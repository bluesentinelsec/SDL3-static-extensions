/*
 * sdlstatic_engine_actor.c — the actor world.
 * Original SDLStatic code (zlib).
 *
 * A slot array with a generation counter per slot, a free list, and two
 * pending queues. That is the whole design, and each piece is there for a
 * specific failure it prevents:
 *
 *   Generations   make a stale handle resolve to NULL instead of to
 *                 whatever was allocated in the dead actor's place.
 *   A free list   keeps spawn O(1) without leaving holes that iteration has
 *                 to skip forever.
 *   Deferral      means the set of actors cannot change while something is
 *                 walking it, which is otherwise the most common crash in a
 *                 system like this — an actor killing another during an
 *                 update it is inside.
 *
 * The world is allocated on first spawn, so a game that never uses actors
 * pays nothing for them.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_actor.h>

/* A handle is 24 bits of index and 24 bits of generation. Keeping both in
   the low 48 bits leaves the top word free, which is what lets a script
   binding carry one through a double without losing precision. */
#define INDEX_BITS 24u
#define INDEX_MASK ((Uint64)0xFFFFFFu)
#define GENERATION_MASK ((Uint64)0xFFFFFFu)

static SDLStatic_ActorId MakeId(Uint32 index, Uint32 generation)
{
    /* +1 on the index so that slot 0 generation 0 is not the same bit
       pattern as SDLSTATIC_ACTOR_NONE. */
    return (SDLStatic_ActorId)((Uint64)(index + 1u) & INDEX_MASK) |
           (((Uint64)generation & GENERATION_MASK) << INDEX_BITS);
}

static Uint32 IdIndex(SDLStatic_ActorId id)
{
    return (Uint32)((id & INDEX_MASK) - 1u);
}

static Uint32 IdGeneration(SDLStatic_ActorId id)
{
    return (Uint32)((id >> INDEX_BITS) & GENERATION_MASK);
}

struct SDLStatic_Actor
{
    SDLStatic_ActorId id;
    SDLStatic_Engine *engine;

    char *type;
    char *name;
    void *state;
    SDLStatic_ActorTags tags;

    SDLStatic_ActorTransform local;
    /* The transform at the last two fixed steps, so rendering can draw
       between them. Kept by the engine rather than by every actor, because
       otherwise every actor in every game reimplements it. */
    SDLStatic_ActorTransform previous;

    SDLStatic_ActorId parent;
    SDLStatic_ActorId *children;
    int child_count, child_capacity;

    bool (*spawn)(SDLStatic_Actor *actor);
    void (*fixed_update)(SDLStatic_Actor *actor, float step);
    void (*update)(SDLStatic_Actor *actor, float dt);
    void (*message)(SDLStatic_Actor *actor, const SDLStatic_ActorMessage *message);
    void (*destroy)(SDLStatic_Actor *actor);

    /* By value rather than allocated: a sprite is smaller than the actor
       already is, and this way it cannot be leaked or dangle. */
    SDLStatic_Sprite sprite;
    bool has_sprite;

    bool enabled;
    bool alive;    /* the slot holds an actor */
    bool pending;  /* spawned this frame; not yet updated or queried */
    bool doomed;   /* destroy requested; goes away at the end of the frame */
};

typedef struct QueuedMessage
{
    SDLStatic_ActorId target;
    SDLStatic_ActorMessage message;
} QueuedMessage;

struct SDLStatic_ActorWorld
{
    SDLStatic_Actor *slots;
    Uint32 *generations;
    int capacity;
    int count; /* live and not doomed */

    Uint32 *free_slots;
    int free_count;

    SDLStatic_ActorId *pending_spawn;
    int pending_spawn_count, pending_spawn_capacity;

    SDLStatic_ActorId *pending_destroy;
    int pending_destroy_count, pending_destroy_capacity;

    QueuedMessage *messages;
    int message_count, message_capacity;
    bool draining; /* messages sent now go to the next frame */
};

/* --- growth -------------------------------------------------------------- */

static bool GrowIds(SDLStatic_ActorId **array, int *capacity, int needed)
{
    if (*capacity >= needed)
    {
        return true;
    }
    int next = (*capacity > 0) ? *capacity * 2 : 16;
    while (next < needed)
    {
        next *= 2;
    }
    SDLStatic_ActorId *grown =
        (SDLStatic_ActorId *)SDL_realloc(*array, (size_t)next * sizeof(**array));
    if (grown == NULL)
    {
        return false;
    }
    *array = grown;
    *capacity = next;
    return true;
}

static bool GrowWorld(struct SDLStatic_ActorWorld *world)
{
    const int next = (world->capacity > 0) ? world->capacity * 2 : 64;
    if (next > SDLSTATIC_ACTOR_MAX)
    {
        SDL_SetError("actor world is full (%d)", SDLSTATIC_ACTOR_MAX);
        return false;
    }

    SDLStatic_Actor *slots =
        (SDLStatic_Actor *)SDL_realloc(world->slots, (size_t)next * sizeof(*slots));
    if (slots == NULL)
    {
        return false;
    }
    world->slots = slots;

    Uint32 *generations =
        (Uint32 *)SDL_realloc(world->generations, (size_t)next * sizeof(*generations));
    if (generations == NULL)
    {
        return false;
    }
    world->generations = generations;

    Uint32 *free_slots =
        (Uint32 *)SDL_realloc(world->free_slots, (size_t)next * sizeof(*free_slots));
    if (free_slots == NULL)
    {
        return false;
    }
    world->free_slots = free_slots;

    /* New slots start empty and free, highest index first so that the free
       list pops the lowest — which keeps the live actors bunched at the
       front of the array and iteration cache-friendly. */
    for (int i = next - 1; i >= world->capacity; --i)
    {
        SDL_zero(world->slots[i]);
        world->generations[i] = 0;
        world->free_slots[world->free_count++] = (Uint32)i;
    }
    world->capacity = next;
    return true;
}

static struct SDLStatic_ActorWorld *World(SDLStatic_Engine *engine, bool create)
{
    if (engine == NULL)
    {
        return NULL;
    }
    if (engine->actors == NULL && create)
    {
        engine->actors = (struct SDLStatic_ActorWorld *)SDL_calloc(
            1, sizeof(struct SDLStatic_ActorWorld));
    }
    return engine->actors;
}

/* --- resolving ----------------------------------------------------------- */

static SDLStatic_Actor *Resolve(struct SDLStatic_ActorWorld *world, SDLStatic_ActorId id,
                                bool allow_pending)
{
    if (world == NULL || id == SDLSTATIC_ACTOR_NONE)
    {
        return NULL;
    }
    const Uint32 index = IdIndex(id);
    if ((int)index >= world->capacity)
    {
        return NULL;
    }
    /* The generation check is the whole point of a handle: a slot that has
       been reused has a different generation, so an old handle to it stops
       resolving rather than quietly addressing its replacement. */
    if (world->generations[index] != IdGeneration(id))
    {
        return NULL;
    }
    SDLStatic_Actor *actor = &world->slots[index];
    if (!actor->alive || actor->doomed)
    {
        return NULL;
    }
    if (actor->pending && !allow_pending)
    {
        return NULL;
    }
    return actor;
}

SDLStatic_Actor *SDLStatic_ActorGet(SDLStatic_Engine *engine, SDLStatic_ActorId id)
{
    /* Pending actors resolve: a spawn returns a usable handle so the caller
       can set the thing up before it starts running. */
    return Resolve(World(engine, false), id, true);
}

bool SDLStatic_ActorAlive(SDLStatic_Engine *engine, SDLStatic_ActorId id)
{
    return Resolve(World(engine, false), id, true) != NULL;
}

int SDLStatic_ActorCount(SDLStatic_Engine *engine)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    return (world != NULL) ? world->count : 0;
}

/* --- children ------------------------------------------------------------ */

static bool AddChild(SDLStatic_Actor *parent, SDLStatic_ActorId child)
{
    if (!GrowIds(&parent->children, &parent->child_capacity, parent->child_count + 1))
    {
        return false;
    }
    parent->children[parent->child_count++] = child;
    return true;
}

static void RemoveChild(SDLStatic_Actor *parent, SDLStatic_ActorId child)
{
    for (int i = 0; i < parent->child_count; ++i)
    {
        if (parent->children[i] == child)
        {
            /* Swap with the last: order is documented as unspecified, so
               this is free rather than a memmove. */
            parent->children[i] = parent->children[parent->child_count - 1];
            parent->child_count--;
            return;
        }
    }
}

/* --- spawn --------------------------------------------------------------- */

static char *CopyString(const char *text)
{
    return (text != NULL) ? SDL_strdup(text) : NULL;
}

SDLStatic_ActorId SDLStatic_ActorSpawn(SDLStatic_Engine *engine, const SDLStatic_ActorDef *def)
{
    struct SDLStatic_ActorWorld *world = World(engine, true);
    if (world == NULL || def == NULL)
    {
        SDL_InvalidParamError("engine/def");
        return SDLSTATIC_ACTOR_NONE;
    }
    if (world->free_count == 0 && !GrowWorld(world))
    {
        return SDLSTATIC_ACTOR_NONE;
    }

    const Uint32 index = world->free_slots[--world->free_count];
    SDLStatic_Actor *actor = &world->slots[index];
    SDL_zerop(actor);

    actor->id = MakeId(index, world->generations[index]);
    actor->engine = engine;
    actor->type = CopyString(def->type);
    actor->name = CopyString(def->name);
    actor->tags = def->tags;
    actor->enabled = true;
    actor->alive = true;
    actor->pending = true;

    if (def->state_size > 0)
    {
        actor->state = SDL_calloc(1, def->state_size);
        if (actor->state == NULL)
        {
            SDL_free(actor->type);
            SDL_free(actor->name);
            SDL_zerop(actor);
            world->free_slots[world->free_count++] = index;
            return SDLSTATIC_ACTOR_NONE;
        }
    }

    actor->local.x = def->x;
    actor->local.y = def->y;
    actor->local.rotation = def->rotation;
    /* A zero-initialised def should produce a visible actor, not one scaled
       to nothing. */
    actor->local.scale_x = (def->scale_x != 0.0f) ? def->scale_x : 1.0f;
    actor->local.scale_y = (def->scale_y != 0.0f) ? def->scale_y : 1.0f;
    actor->previous = actor->local;

    actor->spawn = def->spawn;
    actor->fixed_update = def->fixed_update;
    actor->update = def->update;
    actor->message = def->message;
    actor->destroy = def->destroy;

    if (def->parent != SDLSTATIC_ACTOR_NONE)
    {
        SDLStatic_Actor *parent = Resolve(world, def->parent, true);
        if (parent != NULL && AddChild(parent, actor->id))
        {
            actor->parent = def->parent;
        }
    }

    if (actor->spawn != NULL && !actor->spawn(actor))
    {
        /* The spawn hook refused. Unwind completely, including the parent
           link, so a failed spawn leaves nothing behind. */
        if (actor->parent != SDLSTATIC_ACTOR_NONE)
        {
            SDLStatic_Actor *parent = Resolve(world, actor->parent, true);
            if (parent != NULL)
            {
                RemoveChild(parent, actor->id);
            }
        }
        SDL_free(actor->type);
        SDL_free(actor->name);
        SDL_free(actor->state);
        SDL_zerop(actor);
        world->generations[index] = (world->generations[index] + 1) & (Uint32)GENERATION_MASK;
        world->free_slots[world->free_count++] = index;
        return SDLSTATIC_ACTOR_NONE;
    }

    if (!GrowIds(&world->pending_spawn, &world->pending_spawn_capacity,
                 world->pending_spawn_count + 1))
    {
        return SDLSTATIC_ACTOR_NONE;
    }
    world->pending_spawn[world->pending_spawn_count++] = actor->id;
    return actor->id;
}

/* --- destroy ------------------------------------------------------------- */

/* Mark this actor and everything under it. Recursive over the hierarchy,
   which is bounded by how deeply a game nests things — a few levels, not a
   few thousand. */
static void MarkDoomed(struct SDLStatic_ActorWorld *world, SDLStatic_ActorId id)
{
    SDLStatic_Actor *actor = Resolve(world, id, true);
    if (actor == NULL)
    {
        return;
    }
    actor->doomed = true;
    world->count--;
    for (int i = 0; i < actor->child_count; ++i)
    {
        MarkDoomed(world, actor->children[i]);
    }
}

void SDLStatic_ActorDestroy(SDLStatic_Engine *engine, SDLStatic_ActorId id)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    SDLStatic_Actor *actor = Resolve(world, id, true);
    if (actor == NULL)
    {
        return; /* already gone: not an error, see the header */
    }
    if (!GrowIds(&world->pending_destroy, &world->pending_destroy_capacity,
                 world->pending_destroy_count + 1))
    {
        return;
    }
    world->pending_destroy[world->pending_destroy_count++] = id;
    MarkDoomed(world, id);
}

/* Free one slot, having already run its destroy hook. */
static void ReleaseSlot(struct SDLStatic_ActorWorld *world, Uint32 index)
{
    SDLStatic_Actor *actor = &world->slots[index];
    SDL_free(actor->type);
    SDL_free(actor->name);
    SDL_free(actor->state);
    SDL_free(actor->children);
    SDL_zerop(actor);

    /* Advance the generation *now*, so every handle to this actor stops
       resolving the instant the slot is free. */
    world->generations[index] = (world->generations[index] + 1) & (Uint32)GENERATION_MASK;
    world->free_slots[world->free_count++] = index;
}

/* Run destroy hooks top-down, then free bottom-up. Top-down so a parent's
   hook still sees its children; the free order does not matter once every
   hook has run. */
static void DestroyTree(struct SDLStatic_ActorWorld *world, SDLStatic_ActorId id, bool run_hooks)
{
    const Uint32 index = IdIndex(id);
    if ((int)index >= world->capacity || world->generations[index] != IdGeneration(id))
    {
        return;
    }
    SDLStatic_Actor *actor = &world->slots[index];
    if (!actor->alive)
    {
        return;
    }

    if (run_hooks && actor->destroy != NULL)
    {
        actor->destroy(actor);
    }

    /* Copy the children out: freeing them will edit the array. */
    const int child_count = actor->child_count;
    SDLStatic_ActorId *children = NULL;
    if (child_count > 0)
    {
        children = (SDLStatic_ActorId *)SDL_malloc((size_t)child_count * sizeof(*children));
        if (children != NULL)
        {
            SDL_memcpy(children, actor->children,
                       (size_t)child_count * sizeof(*children));
        }
    }

    if (actor->parent != SDLSTATIC_ACTOR_NONE)
    {
        SDLStatic_Actor *parent = Resolve(world, actor->parent, true);
        if (parent == NULL)
        {
            /* The parent is being destroyed too; reach past Resolve, which
               refuses doomed actors, so the link is still cleaned up. */
            const Uint32 parent_index = IdIndex(actor->parent);
            if ((int)parent_index < world->capacity &&
                world->generations[parent_index] == IdGeneration(actor->parent) &&
                world->slots[parent_index].alive)
            {
                RemoveChild(&world->slots[parent_index], id);
            }
        }
        else
        {
            RemoveChild(parent, id);
        }
    }

    ReleaseSlot(world, index);

    for (int i = 0; i < child_count && children != NULL; ++i)
    {
        DestroyTree(world, children[i], run_hooks);
    }
    SDL_free(children);
}

void SDLStatic_ActorClear(SDLStatic_Engine *engine)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL)
    {
        return;
    }
    /* Roots only: DestroyTree takes the children with it. */
    for (int i = 0; i < world->capacity; ++i)
    {
        if (world->slots[i].alive && world->slots[i].parent == SDLSTATIC_ACTOR_NONE)
        {
            DestroyTree(world, world->slots[i].id, true);
        }
    }
    /* Anything left was parented to something already gone. */
    for (int i = 0; i < world->capacity; ++i)
    {
        if (world->slots[i].alive)
        {
            DestroyTree(world, world->slots[i].id, true);
        }
    }
    world->count = 0;
    world->pending_spawn_count = 0;
    world->pending_destroy_count = 0;
    world->message_count = 0;
}

void SDLStatic_ActorWorldDestroy(SDLStatic_Engine *engine)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL)
    {
        return;
    }
    SDLStatic_ActorClear(engine);
    SDL_free(world->slots);
    SDL_free(world->generations);
    SDL_free(world->free_slots);
    SDL_free(world->pending_spawn);
    SDL_free(world->pending_destroy);
    SDL_free(world->messages);
    SDL_free(world);
    engine->actors = NULL;
}

/* --- sprites ------------------------------------------------------------- */

SDLStatic_Sprite *SDLStatic_ActorSpriteSlot(SDLStatic_Actor *actor, bool create)
{
    if (actor == NULL)
    {
        return NULL;
    }
    if (!actor->has_sprite)
    {
        if (!create)
        {
            return NULL;
        }
        actor->sprite = SDLStatic_SpriteDefault();
        actor->has_sprite = true;
    }
    return &actor->sprite;
}

void SDLStatic_ActorSpriteRemove(SDLStatic_Actor *actor)
{
    if (actor != NULL)
    {
        actor->has_sprite = false;
    }
}

/* --- accessors ----------------------------------------------------------- */

SDLStatic_ActorId SDLStatic_ActorGetId(SDLStatic_Actor *actor)
{
    return (actor != NULL) ? actor->id : SDLSTATIC_ACTOR_NONE;
}

void *SDLStatic_ActorState(SDLStatic_Actor *actor)
{
    return (actor != NULL) ? actor->state : NULL;
}

SDLStatic_Engine *SDLStatic_ActorEngine(SDLStatic_Actor *actor)
{
    return (actor != NULL) ? actor->engine : NULL;
}

const char *SDLStatic_ActorType(SDLStatic_Actor *actor)
{
    return (actor != NULL) ? actor->type : NULL;
}

const char *SDLStatic_ActorName(SDLStatic_Actor *actor)
{
    return (actor != NULL) ? actor->name : NULL;
}

SDLStatic_ActorTags SDLStatic_ActorGetTags(SDLStatic_Actor *actor)
{
    return (actor != NULL) ? actor->tags : 0;
}

void SDLStatic_ActorSetTags(SDLStatic_Actor *actor, SDLStatic_ActorTags tags)
{
    if (actor != NULL)
    {
        actor->tags = tags;
    }
}

bool SDLStatic_ActorHasTags(SDLStatic_Actor *actor, SDLStatic_ActorTags any)
{
    return (actor != NULL) && (actor->tags & any) != 0;
}

void SDLStatic_ActorSetEnabled(SDLStatic_Actor *actor, bool enabled)
{
    if (actor != NULL)
    {
        actor->enabled = enabled;
    }
}

bool SDLStatic_ActorEnabled(SDLStatic_Actor *actor)
{
    return (actor != NULL) && actor->enabled;
}

/* --- transforms ---------------------------------------------------------- */

SDLStatic_ActorTransform SDLStatic_ActorLocal(SDLStatic_Actor *actor)
{
    SDLStatic_ActorTransform identity = {0.0f, 0.0f, 0.0f, 1.0f, 1.0f};
    return (actor != NULL) ? actor->local : identity;
}

void SDLStatic_ActorSetLocal(SDLStatic_Actor *actor, const SDLStatic_ActorTransform *transform)
{
    if (actor != NULL && transform != NULL)
    {
        actor->local = *transform;
    }
}

void SDLStatic_ActorSetPosition(SDLStatic_Actor *actor, float x, float y)
{
    if (actor != NULL)
    {
        actor->local.x = x;
        actor->local.y = y;
    }
}

void SDLStatic_ActorMove(SDLStatic_Actor *actor, float dx, float dy)
{
    if (actor != NULL)
    {
        actor->local.x += dx;
        actor->local.y += dy;
    }
}

void SDLStatic_ActorTeleport(SDLStatic_Actor *actor, float x, float y)
{
    if (actor == NULL)
    {
        return;
    }
    actor->local.x = x;
    actor->local.y = y;
    /* Drag the previous transform along, or the actor is drawn smeared
       across everywhere it did not go. */
    actor->previous = actor->local;
}

/* Compose child onto parent: rotate and scale the child's offset by the
   parent's transform, then translate. */
static SDLStatic_ActorTransform Compose(const SDLStatic_ActorTransform *parent,
                                        const SDLStatic_ActorTransform *child)
{
    const float radians = parent->rotation * (float)(SDL_PI_D / 180.0);
    const float c = SDL_cosf(radians);
    const float s = SDL_sinf(radians);
    const float x = child->x * parent->scale_x;
    const float y = child->y * parent->scale_y;

    SDLStatic_ActorTransform out;
    out.x = parent->x + (x * c - y * s);
    out.y = parent->y + (x * s + y * c);
    out.rotation = parent->rotation + child->rotation;
    out.scale_x = parent->scale_x * child->scale_x;
    out.scale_y = parent->scale_y * child->scale_y;
    return out;
}

/* Walk to the root composing transforms. Depth is bounded by SetParent's
   cycle check, so this terminates. */
static SDLStatic_ActorTransform WorldOf(struct SDLStatic_ActorWorld *world,
                                        SDLStatic_Actor *actor, bool interpolated, float alpha)
{
    SDLStatic_ActorTransform local = actor->local;
    if (interpolated)
    {
        local.x = actor->previous.x + (actor->local.x - actor->previous.x) * alpha;
        local.y = actor->previous.y + (actor->local.y - actor->previous.y) * alpha;
        local.rotation = actor->previous.rotation +
                         (actor->local.rotation - actor->previous.rotation) * alpha;
        local.scale_x = actor->previous.scale_x +
                        (actor->local.scale_x - actor->previous.scale_x) * alpha;
        local.scale_y = actor->previous.scale_y +
                        (actor->local.scale_y - actor->previous.scale_y) * alpha;
    }

    if (actor->parent == SDLSTATIC_ACTOR_NONE)
    {
        return local;
    }
    SDLStatic_Actor *parent = Resolve(world, actor->parent, true);
    if (parent == NULL)
    {
        return local;
    }
    const SDLStatic_ActorTransform parent_world =
        WorldOf(world, parent, interpolated, alpha);
    return Compose(&parent_world, &local);
}

SDLStatic_ActorTransform SDLStatic_ActorWorld(SDLStatic_Actor *actor)
{
    SDLStatic_ActorTransform identity = {0.0f, 0.0f, 0.0f, 1.0f, 1.0f};
    if (actor == NULL)
    {
        return identity;
    }
    return WorldOf(World(actor->engine, false), actor, false, 0.0f);
}

SDLStatic_ActorTransform SDLStatic_ActorRenderTransform(SDLStatic_Actor *actor, float alpha)
{
    SDLStatic_ActorTransform identity = {0.0f, 0.0f, 0.0f, 1.0f, 1.0f};
    if (actor == NULL)
    {
        return identity;
    }
    return WorldOf(World(actor->engine, false), actor, true, alpha);
}

/* --- hierarchy ----------------------------------------------------------- */

SDLStatic_ActorId SDLStatic_ActorParent(SDLStatic_Actor *actor)
{
    return (actor != NULL) ? actor->parent : SDLSTATIC_ACTOR_NONE;
}

int SDLStatic_ActorChildCount(SDLStatic_Actor *actor)
{
    return (actor != NULL) ? actor->child_count : 0;
}

SDLStatic_ActorId SDLStatic_ActorChild(SDLStatic_Actor *actor, int index)
{
    if (actor == NULL || index < 0 || index >= actor->child_count)
    {
        return SDLSTATIC_ACTOR_NONE;
    }
    return actor->children[index];
}

/* Would making `candidate` the parent of `actor` create a cycle? */
static bool WouldCycle(struct SDLStatic_ActorWorld *world, SDLStatic_Actor *actor,
                       SDLStatic_ActorId candidate)
{
    SDLStatic_ActorId walk = candidate;
    /* Bounded by the number of slots: even a corrupt chain terminates. */
    for (int guard = 0; guard <= world->capacity && walk != SDLSTATIC_ACTOR_NONE; ++guard)
    {
        if (walk == actor->id)
        {
            return true;
        }
        SDLStatic_Actor *step = Resolve(world, walk, true);
        if (step == NULL)
        {
            return false;
        }
        walk = step->parent;
    }
    return false;
}

/* Solve for the local transform that leaves the world transform unchanged
   under a new parent. */
static SDLStatic_ActorTransform Decompose(const SDLStatic_ActorTransform *parent_world,
                                          const SDLStatic_ActorTransform *world)
{
    const float radians = -parent_world->rotation * (float)(SDL_PI_D / 180.0);
    const float c = SDL_cosf(radians);
    const float s = SDL_sinf(radians);
    const float dx = world->x - parent_world->x;
    const float dy = world->y - parent_world->y;
    const float sx = (parent_world->scale_x != 0.0f) ? parent_world->scale_x : 1.0f;
    const float sy = (parent_world->scale_y != 0.0f) ? parent_world->scale_y : 1.0f;

    SDLStatic_ActorTransform out;
    out.x = (dx * c - dy * s) / sx;
    out.y = (dx * s + dy * c) / sy;
    out.rotation = world->rotation - parent_world->rotation;
    out.scale_x = world->scale_x / sx;
    out.scale_y = world->scale_y / sy;
    return out;
}

bool SDLStatic_ActorSetParent(SDLStatic_Actor *actor, SDLStatic_ActorId parent)
{
    if (actor == NULL)
    {
        SDL_InvalidParamError("actor");
        return false;
    }
    struct SDLStatic_ActorWorld *world = World(actor->engine, false);
    if (world == NULL || parent == actor->id)
    {
        SDL_SetError("an actor cannot be its own parent");
        return false;
    }

    SDLStatic_Actor *next = NULL;
    if (parent != SDLSTATIC_ACTOR_NONE)
    {
        next = Resolve(world, parent, true);
        if (next == NULL)
        {
            SDL_SetError("no such parent");
            return false;
        }
        /* A cycle would make every transform walk run forever, so it is
           refused rather than detected later. */
        if (WouldCycle(world, actor, parent))
        {
            SDL_SetError("reparenting there would make a cycle");
            return false;
        }
    }

    /* Keep the world position: "pick this up" should not teleport it. */
    const SDLStatic_ActorTransform world_transform = SDLStatic_ActorWorld(actor);

    if (actor->parent != SDLSTATIC_ACTOR_NONE)
    {
        SDLStatic_Actor *old = Resolve(world, actor->parent, true);
        if (old != NULL)
        {
            RemoveChild(old, actor->id);
        }
    }

    actor->parent = SDLSTATIC_ACTOR_NONE;
    if (next != NULL)
    {
        if (!AddChild(next, actor->id))
        {
            return false;
        }
        actor->parent = parent;
        const SDLStatic_ActorTransform parent_world = SDLStatic_ActorWorld(next);
        actor->local = Decompose(&parent_world, &world_transform);
    }
    else
    {
        actor->local = world_transform;
    }
    actor->previous = actor->local;
    return true;
}

/* --- queries ------------------------------------------------------------- */

/* Does this actor match a (type, tags) filter? NULL/0 mean "any". */
static bool Matches(const SDLStatic_Actor *actor, const char *type, SDLStatic_ActorTags tags)
{
    if (type != NULL && (actor->type == NULL || SDL_strcmp(actor->type, type) != 0))
    {
        return false;
    }
    if (tags != 0 && (actor->tags & tags) == 0)
    {
        return false;
    }
    return true;
}

SDLStatic_ActorId SDLStatic_ActorFindByType(SDLStatic_Engine *engine, const char *type)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL || type == NULL)
    {
        return SDLSTATIC_ACTOR_NONE;
    }
    for (int i = 0; i < world->capacity; ++i)
    {
        SDLStatic_Actor *actor = &world->slots[i];
        if (actor->alive && !actor->doomed && !actor->pending && Matches(actor, type, 0))
        {
            return actor->id;
        }
    }
    return SDLSTATIC_ACTOR_NONE;
}

SDLStatic_ActorId SDLStatic_ActorFindByName(SDLStatic_Engine *engine, const char *name)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL || name == NULL)
    {
        return SDLSTATIC_ACTOR_NONE;
    }
    for (int i = 0; i < world->capacity; ++i)
    {
        SDLStatic_Actor *actor = &world->slots[i];
        if (actor->alive && !actor->doomed && !actor->pending && actor->name != NULL &&
            SDL_strcmp(actor->name, name) == 0)
        {
            return actor->id;
        }
    }
    return SDLSTATIC_ACTOR_NONE;
}

int SDLStatic_ActorQuery(SDLStatic_Engine *engine, const char *type, SDLStatic_ActorTags tags,
                         SDLStatic_ActorId *out, int capacity)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL || out == NULL || capacity <= 0)
    {
        return 0;
    }
    int found = 0;
    for (int i = 0; i < world->capacity && found < capacity; ++i)
    {
        SDLStatic_Actor *actor = &world->slots[i];
        if (actor->alive && !actor->doomed && !actor->pending && Matches(actor, type, tags))
        {
            out[found++] = actor->id;
        }
    }
    return found;
}

void SDLStatic_ActorEach(SDLStatic_Engine *engine,
                         bool (*visit)(SDLStatic_Actor *actor, void *user), void *user)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL || visit == NULL)
    {
        return;
    }
    for (int i = 0; i < world->capacity; ++i)
    {
        SDLStatic_Actor *actor = &world->slots[i];
        if (actor->alive && !actor->doomed && !actor->pending && !visit(actor, user))
        {
            return;
        }
    }
}

/* --- messages ------------------------------------------------------------ */

static bool Queue(struct SDLStatic_ActorWorld *world, SDLStatic_ActorId target,
                  const SDLStatic_ActorMessage *message)
{
    if (world->message_count >= world->message_capacity)
    {
        const int next = (world->message_capacity > 0) ? world->message_capacity * 2 : 32;
        QueuedMessage *grown =
            (QueuedMessage *)SDL_realloc(world->messages, (size_t)next * sizeof(*grown));
        if (grown == NULL)
        {
            return false;
        }
        world->messages = grown;
        world->message_capacity = next;
    }
    world->messages[world->message_count].target = target;
    world->messages[world->message_count].message = *message;
    world->message_count++;
    return true;
}

bool SDLStatic_ActorSend(SDLStatic_Engine *engine, SDLStatic_ActorId target,
                         const SDLStatic_ActorMessage *message)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL || message == NULL || Resolve(world, target, true) == NULL)
    {
        return false;
    }
    return Queue(world, target, message);
}

int SDLStatic_ActorBroadcast(SDLStatic_Engine *engine, const char *type,
                             SDLStatic_ActorTags tags, const SDLStatic_ActorMessage *message)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL || message == NULL)
    {
        return 0;
    }
    int sent = 0;
    for (int i = 0; i < world->capacity; ++i)
    {
        SDLStatic_Actor *actor = &world->slots[i];
        if (actor->alive && !actor->doomed && !actor->pending && Matches(actor, type, tags) &&
            Queue(world, actor->id, message))
        {
            sent++;
        }
    }
    return sent;
}

/* --- the frame ----------------------------------------------------------- */

void SDLStatic_ActorDispatchFixedUpdate(SDLStatic_Engine *engine, float step)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL)
    {
        return;
    }
    /* Snapshot every transform before anything moves. Doing it here, once,
       is what lets rendering interpolate without every actor keeping its
       own copy — and it has to happen before the first update of the step, or
       an actor that moves early would be interpolated from where it already
       is. */
    for (int i = 0; i < world->capacity; ++i)
    {
        SDLStatic_Actor *actor = &world->slots[i];
        if (actor->alive && !actor->doomed && !actor->pending)
        {
            actor->previous = actor->local;
        }
    }
    for (int i = 0; i < world->capacity; ++i)
    {
        SDLStatic_Actor *actor = &world->slots[i];
        if (actor->alive && !actor->doomed && !actor->pending && actor->enabled &&
            actor->fixed_update != NULL)
        {
            actor->fixed_update(actor, step);
        }
    }
}

void SDLStatic_ActorDispatchUpdate(SDLStatic_Engine *engine, float dt)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL)
    {
        return;
    }
    for (int i = 0; i < world->capacity; ++i)
    {
        SDLStatic_Actor *actor = &world->slots[i];
        if (actor->alive && !actor->doomed && !actor->pending && actor->enabled &&
            actor->update != NULL)
        {
            actor->update(actor, dt);
        }
    }
}

void SDLStatic_ActorDeliverMessages(SDLStatic_Engine *engine)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL || world->message_count == 0 || world->draining)
    {
        return;
    }

    /* Take the queue and drain the copy. Messages sent while draining land
       in the fresh queue and are delivered next frame, which bounds the
       work in a frame — an actor pair that answers each other forever
       becomes visibly slow rather than a stack overflow. */
    const int count = world->message_count;
    QueuedMessage *batch = (QueuedMessage *)SDL_malloc((size_t)count * sizeof(*batch));
    if (batch == NULL)
    {
        return;
    }
    SDL_memcpy(batch, world->messages, (size_t)count * sizeof(*batch));
    world->message_count = 0;

    world->draining = true;
    for (int i = 0; i < count; ++i)
    {
        SDLStatic_Actor *actor = Resolve(world, batch[i].target, false);
        /* A target that died earlier in this same drain simply does not
           receive it, which is what "it is gone" should mean. */
        if (actor != NULL && actor->message != NULL)
        {
            actor->message(actor, &batch[i].message);
        }
    }
    world->draining = false;
    SDL_free(batch);
}

void SDLStatic_ActorApplyPending(SDLStatic_Engine *engine)
{
    struct SDLStatic_ActorWorld *world = World(engine, false);
    if (world == NULL)
    {
        return;
    }

    /* Destroy first, then admit the new. A spawn made *by* a destroy hook
       must not be swept away by the same pass, and doing it in this order
       means it is not. */
    for (int i = 0; i < world->pending_destroy_count; ++i)
    {
        DestroyTree(world, world->pending_destroy[i], true);
    }
    world->pending_destroy_count = 0;

    for (int i = 0; i < world->pending_spawn_count; ++i)
    {
        SDLStatic_Actor *actor = Resolve(world, world->pending_spawn[i], true);
        if (actor != NULL && actor->pending)
        {
            actor->pending = false;
            world->count++;
        }
    }
    world->pending_spawn_count = 0;
}
