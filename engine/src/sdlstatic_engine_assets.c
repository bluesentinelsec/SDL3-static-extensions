/*
 * sdlstatic_engine_assets.c — the asset cache and its worker pool.
 * Original SDLStatic code (zlib).
 *
 * The shape is forced by one fact: decoding a PNG is pure computation and
 * can happen anywhere, but creating an SDL_Texture touches the renderer,
 * and SDL's renderer belongs to the thread that made it. So:
 *
 *     worker threads   VFS read -> decode -> SDL_Surface
 *     main thread      SDL_CreateTextureFromSurface -> SDL_Texture
 *
 * and the main-thread half is time-sliced, because forty textures
 * finishing together would otherwise upload forty textures in one frame and
 * hitch at exactly the moment a loading bar is meant to be reassuring
 * somebody.
 *
 * One mutex guards the whole table. That is not laziness: the critical
 * sections are a few pointer swaps, the contention is two workers and a
 * main thread, and a finer-grained scheme would buy nothing measurable
 * while being much easier to get wrong.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_assets.h>
#include <SDLStatic/vfs.h>

#include <physfs.h>

#include <SDL3_image/SDL_image.h>

#define MAX_WORKERS 8
#define DEFAULT_WORKERS 2
#define DEFAULT_BUDGET_MS 2.0f

typedef struct Asset
{
    char *path;
    SDLStatic_AssetStatus status;
    int references;

    SDL_Surface *decoded; /* handed from a worker to the main thread */
    SDL_Texture *texture;
    Uint32 generation;
    bool in_use;
} Asset;

struct SDLStatic_Assets
{
    Asset *entries;
    int count, capacity;

    SDL_Mutex *lock;
    SDL_Semaphore *work; /* posted once per queued asset */
    SDL_Thread *workers[MAX_WORKERS];
    int worker_count;
    int requested_workers;
    bool shutting_down;

    /* The queue is indices into `entries`, so a worker never holds a
       pointer that a realloc could move. */
    int *queue;
    int queue_head, queue_tail, queue_capacity;

    int pending;   /* asked for and not finished */
    int completed; /* finished since the last time nothing was pending */
    int total;     /* asked for since then; the denominator of progress */

    SDL_Texture *placeholder;
    float budget_ms;
};

static struct SDLStatic_Assets *Assets(SDLStatic_Engine *engine, bool create);

/* --- the placeholder ----------------------------------------------------- */

/* Magenta and black checks: impossible to mistake for art, impossible to
   miss in a screenshot. A missing file should look obviously wrong rather
   than invisibly absent. */
static SDL_Texture *MakePlaceholder(SDL_Renderer *renderer)
{
    const int size = 32;
    SDL_Surface *surface = SDL_CreateSurface(size, size, SDL_PIXELFORMAT_RGBA32);
    if (surface == NULL)
    {
        return NULL;
    }
    const SDL_PixelFormatDetails *details = SDL_GetPixelFormatDetails(surface->format);
    const Uint32 magenta = SDL_MapRGBA(details, NULL, 255, 0, 255, 255);
    const Uint32 black = SDL_MapRGBA(details, NULL, 0, 0, 0, 255);
    Uint32 *pixels = (Uint32 *)surface->pixels;
    const int pitch = surface->pitch / 4;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            const bool checker = ((x / 8) + (y / 8)) % 2 == 0;
            pixels[y * pitch + x] = checker ? magenta : black;
        }
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);
    if (texture != NULL)
    {
        SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
    }
    return texture;
}

/* --- handles ------------------------------------------------------------- */

/* Index and generation, as with actors, so a handle to a released asset
   stops resolving rather than addressing whatever took its slot. */
static SDLStatic_TextureId MakeId(int index, Uint32 generation)
{
    return (SDLStatic_TextureId)(((Uint32)(index + 1) & 0xFFFFu) | ((generation & 0xFFFFu) << 16));
}

static int IdIndex(SDLStatic_TextureId id)
{
    return (int)(id & 0xFFFFu) - 1;
}

static Uint32 IdGeneration(SDLStatic_TextureId id)
{
    return (id >> 16) & 0xFFFFu;
}

/* Caller must hold the lock. */
static Asset *Resolve(struct SDLStatic_Assets *assets, SDLStatic_TextureId id)
{
    if (assets == NULL || id == SDLSTATIC_ASSET_NONE)
    {
        return NULL;
    }
    const int index = IdIndex(id);
    if (index < 0 || index >= assets->count)
    {
        return NULL;
    }
    Asset *asset = &assets->entries[index];
    if (!asset->in_use || asset->generation != IdGeneration(id))
    {
        return NULL;
    }
    return asset;
}

/* --- the queue ----------------------------------------------------------- */

static bool Enqueue(struct SDLStatic_Assets *assets, int index)
{
    const int used = assets->queue_tail - assets->queue_head;
    if (used >= assets->queue_capacity)
    {
        const int next = (assets->queue_capacity > 0) ? assets->queue_capacity * 2 : 64;
        int *grown = (int *)SDL_realloc(assets->queue, (size_t)next * sizeof(int));
        if (grown == NULL)
        {
            return false;
        }
        /* Re-linearise: the ring's contents move to the front of the bigger
           buffer, so the head and tail indices stay simple counters. */
        for (int i = 0; i < used; ++i)
        {
            grown[i] = assets->queue[(assets->queue_head + i) % assets->queue_capacity];
        }
        assets->queue = grown;
        assets->queue_capacity = next;
        assets->queue_head = 0;
        assets->queue_tail = used;
    }
    assets->queue[assets->queue_tail % assets->queue_capacity] = index;
    assets->queue_tail++;
    return true;
}

static int Dequeue(struct SDLStatic_Assets *assets)
{
    if (assets->queue_head >= assets->queue_tail)
    {
        return -1;
    }
    const int index = assets->queue[assets->queue_head % assets->queue_capacity];
    assets->queue_head++;
    return index;
}

/* --- decoding ------------------------------------------------------------ */

/* Read and decode one asset. Runs on a worker, so it touches only the VFS
   and the CPU — never the renderer. */
static SDL_Surface *DecodeFromVfs(const char *path)
{
    /* Only ask the VFS when there is one. PhysFS dereferences its internal
       mutex without checking, so calling it before PHYSFS_init is a segfault
       rather than an error return — and a game that has not mounted an
       archive yet, or set no_auto_mount, is an ordinary case rather than a
       misuse. */
    SDL_IOStream *stream = PHYSFS_isInit() ? SDLStatic_OpenVFSRead(path) : NULL;
    if (stream == NULL)
    {
        /* Not in the archive: fall back to the real filesystem, so a game
           run from a build directory before anything is packed still
           works. */
        stream = SDL_IOFromFile(path, "rb");
    }
    if (stream == NULL)
    {
        return NULL;
    }
    return IMG_Load_IO(stream, true);
}

static int SDLCALL WorkerMain(void *data)
{
    struct SDLStatic_Assets *assets = (struct SDLStatic_Assets *)data;
    for (;;)
    {
        SDL_WaitSemaphore(assets->work);

        SDL_LockMutex(assets->lock);
        if (assets->shutting_down)
        {
            SDL_UnlockMutex(assets->lock);
            return 0;
        }
        const int index = Dequeue(assets);
        char *path = NULL;
        /* The slot may have been released between being queued and being
           picked up — a level torn down while it was still loading. Check
           before touching it, or the path is already freed and the status
           gets resurrected on a slot nobody owns. */
        if (index >= 0 && assets->entries[index].in_use && assets->entries[index].path != NULL)
        {
            assets->entries[index].status = SDLSTATIC_ASSET_LOADING;
            /* Copy the path: the table may be reallocated while we decode,
               and the entry may be released under us. */
            path = SDL_strdup(assets->entries[index].path);
        }
        SDL_UnlockMutex(assets->lock);

        if (index < 0 || path == NULL)
        {
            SDL_free(path);
            continue;
        }

        SDL_Surface *surface = DecodeFromVfs(path);
        SDL_free(path);

        SDL_LockMutex(assets->lock);
        Asset *asset = &assets->entries[index];
        if (!asset->in_use)
        {
            /* Released while we were decoding: throw the work away rather
               than resurrecting it. */
            SDL_UnlockMutex(assets->lock);
            SDL_DestroySurface(surface);
            continue;
        }
        if (surface == NULL)
        {
            asset->status = SDLSTATIC_ASSET_FAILED;
            assets->pending--;
            assets->completed++;
        }
        else
        {
            asset->decoded = surface;
            asset->status = SDLSTATIC_ASSET_DECODED;
        }
        SDL_UnlockMutex(assets->lock);
    }
}

static bool StartWorkers(struct SDLStatic_Assets *assets)
{
    if (assets->worker_count > 0)
    {
        return true;
    }
    const int wanted = SDL_clamp(assets->requested_workers, 1, MAX_WORKERS);
    for (int i = 0; i < wanted; ++i)
    {
        char name[32];
        SDL_snprintf(name, sizeof(name), "SDLStaticAssets%d", i);
        assets->workers[i] = SDL_CreateThread(WorkerMain, name, assets);
        if (assets->workers[i] == NULL)
        {
            break;
        }
        assets->worker_count++;
    }
    return assets->worker_count > 0;
}

/* --- the table ----------------------------------------------------------- */

static struct SDLStatic_Assets *Assets(SDLStatic_Engine *engine, bool create)
{
    if (engine == NULL)
    {
        return NULL;
    }
    if (engine->assets == NULL && create)
    {
        struct SDLStatic_Assets *assets =
            (struct SDLStatic_Assets *)SDL_calloc(1, sizeof(struct SDLStatic_Assets));
        if (assets == NULL)
        {
            return NULL;
        }
        assets->lock = SDL_CreateMutex();
        assets->work = SDL_CreateSemaphore(0);
        assets->requested_workers = DEFAULT_WORKERS;
        assets->budget_ms = DEFAULT_BUDGET_MS;
        if (assets->lock == NULL || assets->work == NULL)
        {
            if (assets->lock != NULL)
            {
                SDL_DestroyMutex(assets->lock);
            }
            if (assets->work != NULL)
            {
                SDL_DestroySemaphore(assets->work);
            }
            SDL_free(assets);
            return NULL;
        }
        engine->assets = assets;
    }
    return engine->assets;
}

/* Caller must hold the lock. */
static int FindByPath(struct SDLStatic_Assets *assets, const char *path)
{
    for (int i = 0; i < assets->count; ++i)
    {
        if (assets->entries[i].in_use && SDL_strcmp(assets->entries[i].path, path) == 0)
        {
            return i;
        }
    }
    return -1;
}

/* Caller must hold the lock. */
static int NewEntry(struct SDLStatic_Assets *assets, const char *path)
{
    int index = -1;
    for (int i = 0; i < assets->count; ++i)
    {
        if (!assets->entries[i].in_use)
        {
            index = i;
            break;
        }
    }
    if (index < 0)
    {
        if (assets->count >= assets->capacity)
        {
            const int next = (assets->capacity > 0) ? assets->capacity * 2 : 32;
            Asset *grown = (Asset *)SDL_realloc(assets->entries, (size_t)next * sizeof(Asset));
            if (grown == NULL)
            {
                return -1;
            }
            SDL_memset(grown + assets->capacity, 0,
                       (size_t)(next - assets->capacity) * sizeof(Asset));
            assets->entries = grown;
            assets->capacity = next;
        }
        index = assets->count++;
    }

    Asset *asset = &assets->entries[index];
    const Uint32 generation = asset->generation;
    SDL_zerop(asset);
    asset->generation = generation;
    asset->path = SDL_strdup(path);
    if (asset->path == NULL)
    {
        return -1;
    }
    asset->in_use = true;
    asset->references = 1;
    asset->status = SDLSTATIC_ASSET_QUEUED;
    return index;
}

/* --- loading ------------------------------------------------------------- */

static SDLStatic_TextureId Request(SDLStatic_Engine *engine, const char *path, bool blocking)
{
    struct SDLStatic_Assets *assets = Assets(engine, true);
    if (assets == NULL || path == NULL || engine->renderer == NULL)
    {
        return SDLSTATIC_ASSET_NONE;
    }

    SDL_LockMutex(assets->lock);
    if (assets->placeholder == NULL)
    {
        assets->placeholder = MakePlaceholder(engine->renderer);
    }

    /* One cache for both paths: a texture already loaded synchronously is
       instant when asked for asynchronously, and the other way round. */
    const int existing = FindByPath(assets, path);
    if (existing >= 0)
    {
        assets->entries[existing].references++;
        const SDLStatic_TextureId id =
            MakeId(existing, assets->entries[existing].generation);
        SDL_UnlockMutex(assets->lock);
        if (blocking)
        {
            SDLStatic_AssetsWait(engine);
        }
        return id;
    }

    const int index = NewEntry(assets, path);
    if (index < 0)
    {
        SDL_UnlockMutex(assets->lock);
        return SDLSTATIC_ASSET_NONE;
    }
    const SDLStatic_TextureId id = MakeId(index, assets->entries[index].generation);
    assets->pending++;
    assets->total++;
    const bool queued = Enqueue(assets, index);
    SDL_UnlockMutex(assets->lock);

    if (!queued)
    {
        return id;
    }

    if (!StartWorkers(assets))
    {
        /* No threads available: decode inline rather than never. */
        SDL_LockMutex(assets->lock);
        const int inline_index = Dequeue(assets);
        SDL_UnlockMutex(assets->lock);
        if (inline_index >= 0)
        {
            SDL_Surface *surface = DecodeFromVfs(path);
            SDL_LockMutex(assets->lock);
            Asset *asset = &assets->entries[inline_index];
            if (surface == NULL)
            {
                asset->status = SDLSTATIC_ASSET_FAILED;
                assets->pending--;
                assets->completed++;
            }
            else
            {
                asset->decoded = surface;
                asset->status = SDLSTATIC_ASSET_DECODED;
            }
            SDL_UnlockMutex(assets->lock);
        }
    }
    else
    {
        SDL_SignalSemaphore(assets->work);
    }

    if (blocking)
    {
        SDLStatic_AssetsWait(engine);
    }
    return id;
}

SDLStatic_TextureId SDLStatic_LoadTexture(SDLStatic_Engine *engine, const char *path)
{
    return Request(engine, path, true);
}

SDLStatic_TextureId SDLStatic_LoadTextureAsync(SDLStatic_Engine *engine, const char *path)
{
    return Request(engine, path, false);
}

/* Turn one decoded surface into a texture. Main thread only, and the
   caller must NOT hold the lock while calling into the renderer. */
static bool FinaliseOne(SDLStatic_Engine *engine, struct SDLStatic_Assets *assets)
{
    SDL_LockMutex(assets->lock);
    int found = -1;
    for (int i = 0; i < assets->count; ++i)
    {
        if (assets->entries[i].in_use && assets->entries[i].status == SDLSTATIC_ASSET_DECODED)
        {
            found = i;
            break;
        }
    }
    if (found < 0)
    {
        SDL_UnlockMutex(assets->lock);
        return false;
    }
    SDL_Surface *surface = assets->entries[found].decoded;
    assets->entries[found].decoded = NULL;
    SDL_UnlockMutex(assets->lock);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(engine->renderer, surface);
    SDL_DestroySurface(surface);

    SDL_LockMutex(assets->lock);
    Asset *asset = &assets->entries[found];
    if (!asset->in_use)
    {
        /* Released while it was in the air. */
        SDL_UnlockMutex(assets->lock);
        if (texture != NULL)
        {
            SDL_DestroyTexture(texture);
        }
        return true;
    }
    asset->texture = texture;
    asset->status = (texture != NULL) ? SDLSTATIC_ASSET_READY : SDLSTATIC_ASSET_FAILED;
    assets->pending--;
    assets->completed++;
    SDL_UnlockMutex(assets->lock);
    return true;
}

void SDLStatic_EngineAssetsPump(SDLStatic_Engine *engine)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    if (assets == NULL || engine->renderer == NULL)
    {
        return;
    }

    /* Time-sliced: spend at most the budget per frame, then stop. A batch
       finishing together would otherwise upload all of it in one frame and
       hitch exactly when a loading bar is meant to be reassuring. */
    const Uint64 started = SDL_GetTicksNS();
    const Uint64 budget_ns = (assets->budget_ms > 0.0f)
                                 ? (Uint64)((double)assets->budget_ms * 1000000.0)
                                 : 0;
    for (;;)
    {
        if (!FinaliseOne(engine, assets))
        {
            break;
        }
        if (assets->budget_ms < 0.0f)
        {
            continue; /* documented "finalise everything and hitch" */
        }
        if (budget_ns == 0 || SDL_GetTicksNS() - started >= budget_ns)
        {
            break; /* zero budget: exactly one per frame */
        }
    }

    /* Once nothing is outstanding, reset the progress denominator so the
       next batch starts from zero rather than continuing a running total. */
    SDL_LockMutex(assets->lock);
    if (assets->pending == 0)
    {
        assets->completed = 0;
        assets->total = 0;
    }
    SDL_UnlockMutex(assets->lock);
}

/* --- reading ------------------------------------------------------------- */

SDL_Texture *SDLStatic_Texture(SDLStatic_Engine *engine, SDLStatic_TextureId id)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    if (assets == NULL)
    {
        return NULL;
    }
    SDL_LockMutex(assets->lock);
    const Asset *asset = Resolve(assets, id);
    /* Never NULL for a live handle: still-loading and failed both give the
       placeholder, so a game may draw without checking and a missing file
       looks wrong rather than invisible. */
    SDL_Texture *texture = (asset != NULL && asset->texture != NULL) ? asset->texture
                                                                     : assets->placeholder;
    SDL_UnlockMutex(assets->lock);
    return texture;
}

SDLStatic_AssetStatus SDLStatic_AssetStatusOf(SDLStatic_Engine *engine, SDLStatic_TextureId id)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    if (assets == NULL)
    {
        return SDLSTATIC_ASSET_MISSING;
    }
    SDL_LockMutex(assets->lock);
    const Asset *asset = Resolve(assets, id);
    const SDLStatic_AssetStatus status =
        (asset != NULL) ? asset->status : SDLSTATIC_ASSET_MISSING;
    SDL_UnlockMutex(assets->lock);
    return status;
}

const char *SDLStatic_AssetPath(SDLStatic_Engine *engine, SDLStatic_TextureId id)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    if (assets == NULL)
    {
        return NULL;
    }
    SDL_LockMutex(assets->lock);
    const Asset *asset = Resolve(assets, id);
    const char *path = (asset != NULL) ? asset->path : NULL;
    SDL_UnlockMutex(assets->lock);
    return path;
}

void SDLStatic_AssetRetain(SDLStatic_Engine *engine, SDLStatic_TextureId id)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    if (assets == NULL)
    {
        return;
    }
    SDL_LockMutex(assets->lock);
    Asset *asset = Resolve(assets, id);
    if (asset != NULL)
    {
        asset->references++;
    }
    SDL_UnlockMutex(assets->lock);
}

void SDLStatic_AssetRelease(SDLStatic_Engine *engine, SDLStatic_TextureId id)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    if (assets == NULL)
    {
        return;
    }
    SDL_LockMutex(assets->lock);
    Asset *asset = Resolve(assets, id);
    if (asset == NULL || --asset->references > 0)
    {
        SDL_UnlockMutex(assets->lock);
        return;
    }

    SDL_Texture *texture = asset->texture;
    SDL_Surface *surface = asset->decoded;
    if (asset->status != SDLSTATIC_ASSET_READY && asset->status != SDLSTATIC_ASSET_FAILED)
    {
        /* Released mid-flight: the worker will notice `in_use` is false and
           drop its result rather than writing into a freed slot. */
        assets->pending--;
        assets->completed++;
    }
    SDL_free(asset->path);
    asset->path = NULL;
    asset->texture = NULL;
    asset->decoded = NULL;
    asset->in_use = false;
    asset->generation = (asset->generation + 1) & 0xFFFFu;
    SDL_UnlockMutex(assets->lock);

    if (texture != NULL)
    {
        SDL_DestroyTexture(texture);
    }
    SDL_DestroySurface(surface);
}

/* --- watching ------------------------------------------------------------ */

int SDLStatic_AssetsPending(SDLStatic_Engine *engine)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    if (assets == NULL)
    {
        return 0;
    }
    SDL_LockMutex(assets->lock);
    const int pending = assets->pending;
    SDL_UnlockMutex(assets->lock);
    return pending;
}

int SDLStatic_AssetsLoaded(SDLStatic_Engine *engine)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    if (assets == NULL)
    {
        return 0;
    }
    SDL_LockMutex(assets->lock);
    int loaded = 0;
    for (int i = 0; i < assets->count; ++i)
    {
        if (assets->entries[i].in_use && assets->entries[i].status == SDLSTATIC_ASSET_READY)
        {
            loaded++;
        }
    }
    SDL_UnlockMutex(assets->lock);
    return loaded;
}

bool SDLStatic_AssetsReady(SDLStatic_Engine *engine)
{
    return SDLStatic_AssetsPending(engine) == 0;
}

float SDLStatic_AssetsProgress(SDLStatic_Engine *engine)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    if (assets == NULL)
    {
        return 1.0f;
    }
    SDL_LockMutex(assets->lock);
    const int total = assets->total;
    const int completed = assets->completed;
    SDL_UnlockMutex(assets->lock);
    if (total <= 0)
    {
        return 1.0f;
    }
    const float progress = (float)completed / (float)total;
    return (progress > 1.0f) ? 1.0f : progress;
}

void SDLStatic_AssetsWait(SDLStatic_Engine *engine)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    if (assets == NULL || engine->renderer == NULL)
    {
        return;
    }
    /* The main thread has to keep finalising while it waits, or a blocking
       load would deadlock against the very step that completes it. */
    while (SDLStatic_AssetsPending(engine) > 0)
    {
        if (!FinaliseOne(engine, assets))
        {
            SDL_Delay(1); /* nothing decoded yet: let the workers run */
        }
    }
    SDL_LockMutex(assets->lock);
    assets->completed = 0;
    assets->total = 0;
    SDL_UnlockMutex(assets->lock);
}

/* --- tuning -------------------------------------------------------------- */

void SDLStatic_AssetsSetFrameBudget(SDLStatic_Engine *engine, float milliseconds)
{
    struct SDLStatic_Assets *assets = Assets(engine, true);
    if (assets != NULL)
    {
        assets->budget_ms = milliseconds;
    }
}

float SDLStatic_AssetsFrameBudget(SDLStatic_Engine *engine)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    return (assets != NULL) ? assets->budget_ms : DEFAULT_BUDGET_MS;
}

void SDLStatic_AssetsSetWorkers(SDLStatic_Engine *engine, int workers)
{
    struct SDLStatic_Assets *assets = Assets(engine, true);
    if (assets != NULL && assets->worker_count == 0)
    {
        assets->requested_workers = SDL_clamp(workers, 1, MAX_WORKERS);
    }
}

/* --- teardown ------------------------------------------------------------ */

void SDLStatic_EngineAssetsDestroy(SDLStatic_Engine *engine)
{
    struct SDLStatic_Assets *assets = Assets(engine, false);
    if (assets == NULL)
    {
        return;
    }

    /* Wake every worker once with the flag set, then join: a worker blocked
       on the semaphore would otherwise never notice it should stop. */
    SDL_LockMutex(assets->lock);
    assets->shutting_down = true;
    SDL_UnlockMutex(assets->lock);
    for (int i = 0; i < assets->worker_count; ++i)
    {
        SDL_SignalSemaphore(assets->work);
    }
    for (int i = 0; i < assets->worker_count; ++i)
    {
        SDL_WaitThread(assets->workers[i], NULL);
    }

    for (int i = 0; i < assets->count; ++i)
    {
        Asset *asset = &assets->entries[i];
        if (asset->texture != NULL)
        {
            SDL_DestroyTexture(asset->texture);
        }
        SDL_DestroySurface(asset->decoded);
        SDL_free(asset->path);
    }
    if (assets->placeholder != NULL)
    {
        SDL_DestroyTexture(assets->placeholder);
    }
    SDL_free(assets->entries);
    SDL_free(assets->queue);
    SDL_DestroyMutex(assets->lock);
    SDL_DestroySemaphore(assets->work);
    SDL_free(assets);
    engine->assets = NULL;
}
