/*
 * sdlstatic_engine_save.c — save slots, written atomically.
 * Original SDLStatic code (zlib).
 *
 * The engine knows how to put bytes somewhere safe and hand them back. It
 * never learns what a save contains, because a save format is the most
 * game-specific thing a game has and any format imposed here would be wrong
 * for every game in a different way.
 *
 * What it does own is the part every game gets wrong once: writing without
 * destroying what was already there.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_save.h>

struct SDLStatic_Saves
{
    char *org;
    char *app;
};

static struct SDLStatic_Saves *Saves(SDLStatic_Engine *engine, bool create)
{
    if (engine == NULL)
    {
        return NULL;
    }
    if (engine->saves == NULL && create)
    {
        engine->saves = (struct SDLStatic_Saves *)SDL_calloc(1, sizeof(struct SDLStatic_Saves));
    }
    return engine->saves;
}

void SDLStatic_SaveSetIdentity(SDLStatic_Engine *engine, const char *org, const char *app)
{
    struct SDLStatic_Saves *saves = Saves(engine, true);
    if (saves == NULL)
    {
        return;
    }
    SDL_free(saves->org);
    SDL_free(saves->app);
    saves->org = (org != NULL) ? SDL_strdup(org) : NULL;
    saves->app = (app != NULL) ? SDL_strdup(app) : NULL;
}

/* The directory saves live in, created if needed. Falls back to a generic
   name rather than failing: a game that forgot to set an identity should
   still be able to save, loudly in the wrong place, rather than silently
   losing the player's progress. */
static char *SaveDirectory(SDLStatic_Engine *engine)
{
    struct SDLStatic_Saves *saves = Saves(engine, false);
    const char *org = (saves != NULL && saves->org != NULL) ? saves->org : "SDLStatic";
    const char *app = (saves != NULL && saves->app != NULL) ? saves->app : "Game";

    char *base = SDL_GetPrefPath(org, app);
    if (base == NULL)
    {
        return NULL;
    }
    const size_t need = SDL_strlen(base) + SDL_strlen("saves") + 1;
    char *directory = (char *)SDL_malloc(need);
    if (directory == NULL)
    {
        SDL_free(base);
        return NULL;
    }
    SDL_snprintf(directory, need, "%ssaves", base);
    SDL_free(base);
    SDL_CreateDirectory(directory);
    return directory;
}

static char *SlotPath(SDLStatic_Engine *engine, int slot, const char *suffix)
{
    /* The identity fallback below is for a real engine whose game forgot to
       call SetIdentity. A null engine is a programming error, and writing
       the player's progress into a generic directory on the strength of one
       would be worse than refusing. */
    if (engine == NULL)
    {
        SDL_InvalidParamError("engine");
        return NULL;
    }
    if (slot < 0 || slot >= SDLSTATIC_SAVE_SLOTS)
    {
        SDL_SetError("save slot %d is out of range (0..%d)", slot, SDLSTATIC_SAVE_SLOTS - 1);
        return NULL;
    }
    char *directory = SaveDirectory(engine);
    if (directory == NULL)
    {
        return NULL;
    }
    const size_t need = SDL_strlen(directory) + 32 + SDL_strlen(suffix);
    char *path = (char *)SDL_malloc(need);
    if (path != NULL)
    {
        SDL_snprintf(path, need, "%s/slot%02d%s", directory, slot, suffix);
    }
    SDL_free(directory);
    return path;
}

char *SDLStatic_SavePath(SDLStatic_Engine *engine, int slot)
{
    return SlotPath(engine, slot, ".sav");
}

/*
 * A save file is a small header and then the game's bytes. The header
 * exists so a load menu can show a row — label, size, time — without
 * reading and parsing a save it may not even be able to interpret (an old
 * version's, say).
 */
#define SAVE_MAGIC 0x53565353u /* "SSVS" */
#define SAVE_VERSION 1u

typedef struct SaveHeader
{
    Uint32 magic;
    Uint32 version;
    Uint64 size;
    Sint64 modified;
    char label[128];
} SaveHeader;

bool SDLStatic_SaveWrite(SDLStatic_Engine *engine, int slot, const void *data, size_t size,
                         const char *label)
{
    if (data == NULL && size > 0)
    {
        SDL_InvalidParamError("data");
        return false;
    }
    char *path = SlotPath(engine, slot, ".sav");
    char *temporary = SlotPath(engine, slot, ".tmp");
    if (path == NULL || temporary == NULL)
    {
        SDL_free(path);
        SDL_free(temporary);
        return false;
    }

    SaveHeader header;
    SDL_zero(header);
    header.magic = SAVE_MAGIC;
    header.version = SAVE_VERSION;
    header.size = (Uint64)size;
    SDL_Time now = 0;
    SDL_GetCurrentTime(&now);
    /* SDL_Time is nanoseconds since the epoch; a load menu wants seconds. */
    header.modified = (Sint64)(now / 1000000000);
    if (label != NULL)
    {
        SDL_strlcpy(header.label, label, sizeof(header.label));
    }

    bool ok = false;
    SDL_IOStream *stream = SDL_IOFromFile(temporary, "wb");
    if (stream != NULL)
    {
        ok = SDL_WriteIO(stream, &header, sizeof(header)) == sizeof(header);
        if (ok && size > 0)
        {
            ok = SDL_WriteIO(stream, data, size) == size;
        }
        /* Close before renaming: the bytes have to be out of our hands
           before the rename makes the file the real save. */
        ok = SDL_CloseIO(stream) && ok;
    }

    if (ok)
    {
        /* The whole point. Rename is atomic, so the previous save survives
           intact until this one is complete on disk — a crash, a dead
           battery or a full disk costs the new save rather than the old
           one. Writing in place fails rarely and takes something
           irreplaceable when it does, which is the worst combination. */
        ok = SDL_RenamePath(temporary, path);
    }
    if (!ok)
    {
        SDL_RemovePath(temporary);
    }

    SDL_free(path);
    SDL_free(temporary);
    return ok;
}

/* Read the header, and optionally the payload after it. */
static bool ReadSlot(SDLStatic_Engine *engine, int slot, SaveHeader *header, void **data,
                     size_t *size)
{
    char *path = SlotPath(engine, slot, ".sav");
    if (path == NULL)
    {
        return false;
    }
    SDL_IOStream *stream = SDL_IOFromFile(path, "rb");
    SDL_free(path);
    if (stream == NULL)
    {
        return false;
    }

    bool ok = SDL_ReadIO(stream, header, sizeof(*header)) == sizeof(*header);
    if (ok && (header->magic != SAVE_MAGIC || header->version > SAVE_VERSION))
    {
        /* Not ours, or from a newer build. Refusing beats handing a game
           bytes it will misinterpret. */
        SDL_SetError("slot %d is not a save this build understands", slot);
        ok = false;
    }
    if (ok && data != NULL)
    {
        const size_t payload = (size_t)header->size;
        void *buffer = (payload > 0) ? SDL_malloc(payload) : NULL;
        if (payload > 0 && buffer == NULL)
        {
            ok = false;
        }
        else if (payload > 0)
        {
            ok = SDL_ReadIO(stream, buffer, payload) == payload;
            if (!ok)
            {
                SDL_free(buffer);
                buffer = NULL;
            }
        }
        if (ok)
        {
            *data = buffer;
            if (size != NULL)
            {
                *size = payload;
            }
        }
    }
    SDL_CloseIO(stream);
    return ok;
}

void *SDLStatic_SaveRead(SDLStatic_Engine *engine, int slot, size_t *size)
{
    SaveHeader header;
    void *data = NULL;
    size_t read_size = 0;
    if (!ReadSlot(engine, slot, &header, &data, &read_size))
    {
        return NULL;
    }
    if (size != NULL)
    {
        *size = read_size;
    }
    return data;
}

bool SDLStatic_SaveExists(SDLStatic_Engine *engine, int slot)
{
    SaveHeader header;
    return ReadSlot(engine, slot, &header, NULL, NULL);
}

bool SDLStatic_SaveDelete(SDLStatic_Engine *engine, int slot)
{
    char *path = SlotPath(engine, slot, ".sav");
    if (path == NULL)
    {
        return false;
    }
    SDL_PathInfo info;
    const bool present = SDL_GetPathInfo(path, &info);
    /* Deleting nothing is success: a load menu offering delete on every row
       should not error on the empty ones. */
    const bool ok = present ? SDL_RemovePath(path) : true;
    SDL_free(path);
    return ok;
}

SDLStatic_SaveInfo SDLStatic_SaveInfoOf(SDLStatic_Engine *engine, int slot)
{
    SDLStatic_SaveInfo info;
    SDL_zero(info);

    SaveHeader header;
    if (!ReadSlot(engine, slot, &header, NULL, NULL))
    {
        return info;
    }
    info.exists = true;
    info.size = (size_t)header.size;
    info.modified = header.modified;
    SDL_strlcpy(info.label, header.label, sizeof(info.label));
    return info;
}

void SDLStatic_EngineSavesDestroy(SDLStatic_Engine *engine)
{
    struct SDLStatic_Saves *saves = Saves(engine, false);
    if (saves == NULL)
    {
        return;
    }
    SDL_free(saves->org);
    SDL_free(saves->app);
    SDL_free(saves);
    engine->saves = NULL;
}
