/**
 * @file engine_actor.h
 * @brief Actors: identity, hierarchy, transforms and messages.
 *
 * Original SDLStatic code (zlib).
 *
 * An actor is a thing in the world with a position and a lifetime. The
 * engine owns the *structure* — identity, parenting, transforms, when
 * things are created and destroyed — and the game owns the *meaning*. The
 * engine never learns what a goblin is; it knows that something exists, is
 * at a position, is inside something else, and will stop existing.
 *
 *     static bool GoblinSpawn(SDLStatic_Actor *actor) {
 *         Goblin *g = SDLStatic_ActorState(actor);
 *         g->health = 20;
 *         return true;
 *     }
 *
 *     SDLStatic_ActorDef def = {0};
 *     def.type = "goblin";
 *     def.state_size = sizeof(Goblin);
 *     def.spawn = GoblinSpawn;
 *     def.fixed_update = GoblinThink;
 *     def.x = 400.0f;
 *     def.y = 120.0f;
 *
 *     SDLStatic_ActorId id = SDLStatic_ActorSpawn(engine, &def);
 *
 * ### Handles, not pointers
 *
 * `SDLStatic_ActorId` is a 48-bit handle: a 24-bit slot index and a 24-bit
 * generation counter. Actors move in memory as the world compacts, and a
 * raw pointer to a dead actor is a crash that happens three frames later
 * somewhere unrelated. A handle cannot do that. When an actor is destroyed
 * its slot's generation advances, so every handle to it stops resolving —
 * including one stored by something that had no idea it had died.
 *
 * That is the whole reason this is not a pointer. A game keeps
 * `SDLStatic_ActorId target` on an enemy, the player dies, and the enemy's
 * next `SDLStatic_ActorGet(engine, target)` returns NULL instead of
 * dereferencing whatever was allocated in the player's place.
 *
 * ### Deferred creation and destruction
 *
 * Spawn and destroy both take effect at the **end of the frame**, so the
 * set of actors cannot change underneath code that is iterating it. A
 * spawned actor's id is valid immediately — you may store it, parent to it,
 * and set it up — but it does not receive updates or appear in queries
 * until the frame it was created in has finished.
 *
 * Destroying a parent destroys its children, which is what "part of" is
 * supposed to mean.
 */
#ifndef SDLSTATIC_ENGINE_ACTOR_H
#define SDLSTATIC_ENGINE_ACTOR_H

#include <SDLStatic/engine.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SDLStatic_Actor SDLStatic_Actor;

/**
 * A handle to an actor. Copy it, store it, compare it; it stays valid for
 * exactly as long as the actor does.
 *
 * Zero is "no actor" and never resolves, so a zeroed struct means what you
 * would want it to mean.
 */
typedef Uint64 SDLStatic_ActorId;

/* Spelled per language: a C-style cast in a header is a hard error for any
   C++ consumer building with -Wold-style-cast, and this project's own tests
   are exactly such a consumer. */
#ifdef __cplusplus
#define SDLSTATIC_ACTOR_NONE (static_cast<SDLStatic_ActorId>(0))
#else
#define SDLSTATIC_ACTOR_NONE ((SDLStatic_ActorId)0)
#endif

/** Most actors alive at once: a 24-bit index. Sixteen million is far past
 *  any 2D game, and the limit exists so that the index and the generation
 *  both fit in a handle with room to spare. */
#define SDLSTATIC_ACTOR_MAX 0xFFFFFF

/** Tags are a 32-bit mask, so "every enemy" or "everything solid" is one
 *  bit test rather than a string comparison per actor per frame. The game
 *  decides what the bits mean. */
typedef Uint32 SDLStatic_ActorTags;

/**
 * A message, delivered to an actor's `message` hook.
 *
 * Deliberately small and copied: a message that carried a pointer would
 * outlive whatever it pointed at about as often as not. `id` is the game's
 * own enum; the two numbers and the actor id cover "damage 7 from that
 * one", which is most of what a 2D game sends.
 */
typedef struct SDLStatic_ActorMessage
{
    Uint32 id;
    SDLStatic_ActorId sender;
    float a, b;
    Sint64 value;
} SDLStatic_ActorMessage;

/**
 * What an actor *is*, independent of any instance.
 *
 * The engine copies this on spawn — including the type and name strings —
 * so it may be a local, a temporary, or a table a script built a moment
 * ago. Every callback is optional.
 */
typedef struct SDLStatic_ActorDef
{
    /** What kind of thing this is: "goblin", "bullet", "door". Used by
     *  SDLStatic_ActorFindByType and for debugging. Copied. */
    const char *type;
    /** An optional instance name — "boss", "exit_door" — for the one actor
     *  a level needs to be able to find by name. Copied. */
    const char *name;

    /** Bytes of game state, allocated with the actor and zeroed.
     *  SDLStatic_ActorState hands them back; they are freed when the actor
     *  is, so nothing has to remember. */
    size_t state_size;

    SDLStatic_ActorTags tags;

    /** Local transform: relative to the parent, or to the world when there
     *  is none. Scale defaults to 1 when left at zero, because a
     *  zero-initialised def should produce a visible actor rather than an
     *  invisible one. */
    float x, y;
    float rotation; /**< degrees */
    float scale_x, scale_y;

    /** Spawn into another actor's frame of reference. The parent must
     *  already exist — including one spawned earlier in the same frame. */
    SDLStatic_ActorId parent;

    /** Called once, after the actor exists and its state is zeroed.
     *  Returning false aborts the spawn and the handle never resolves. */
    bool (*spawn)(SDLStatic_Actor *actor);
    /** Simulation, on the fixed tick. Movement and AI go here. */
    void (*fixed_update)(SDLStatic_Actor *actor, float step);
    /** Cosmetics, once a frame with the real delta. */
    void (*update)(SDLStatic_Actor *actor, float dt);
    /** A message arrived. */
    void (*message)(SDLStatic_Actor *actor, const SDLStatic_ActorMessage *message);
    /** Called just before the actor is destroyed, while its state and its
     *  children are still intact. */
    void (*destroy)(SDLStatic_Actor *actor);
} SDLStatic_ActorDef;

/* --- lifetime ------------------------------------------------------------ */

/** Create an actor. The handle is valid immediately; the actor starts
 *  receiving updates at the end of the current frame.
 *
 *  Returns SDLSTATIC_ACTOR_NONE if the world is full or `spawn` returned
 *  false. */
extern SDLStatic_ActorId SDLStatic_ActorSpawn(SDLStatic_Engine *engine,
                                              const SDLStatic_ActorDef *def);

/** Destroy an actor and everything parented to it, at the end of the
 *  frame. Destroying an already-destroyed actor is not an error — that
 *  case comes up constantly with two things killing the same target in one
 *  frame, and making it an error would only mean every caller writes the
 *  same guard. */
extern void SDLStatic_ActorDestroy(SDLStatic_Engine *engine, SDLStatic_ActorId id);

/** Resolve a handle. NULL if the actor is gone, or was never there, or has
 *  not finished spawning. */
extern SDLStatic_Actor *SDLStatic_ActorGet(SDLStatic_Engine *engine, SDLStatic_ActorId id);

/** Is the handle live? Cheaper than Get when the answer is all you want. */
extern bool SDLStatic_ActorAlive(SDLStatic_Engine *engine, SDLStatic_ActorId id);

/** How many actors are alive. */
extern int SDLStatic_ActorCount(SDLStatic_Engine *engine);

/** Destroy every actor, immediately rather than at the end of the frame.
 *  For a scene teardown, where waiting for a frame that will not come is
 *  the wrong behaviour. */
extern void SDLStatic_ActorClear(SDLStatic_Engine *engine);

/* --- an actor ------------------------------------------------------------ */

extern SDLStatic_ActorId SDLStatic_ActorGetId(SDLStatic_Actor *actor);
extern void *SDLStatic_ActorState(SDLStatic_Actor *actor);
extern SDLStatic_Engine *SDLStatic_ActorEngine(SDLStatic_Actor *actor);
extern const char *SDLStatic_ActorType(SDLStatic_Actor *actor);
extern const char *SDLStatic_ActorName(SDLStatic_Actor *actor);

extern SDLStatic_ActorTags SDLStatic_ActorGetTags(SDLStatic_Actor *actor);
extern void SDLStatic_ActorSetTags(SDLStatic_Actor *actor, SDLStatic_ActorTags tags);
extern bool SDLStatic_ActorHasTags(SDLStatic_Actor *actor, SDLStatic_ActorTags any);

/** A disabled actor keeps its state and its place in the hierarchy but
 *  receives no updates — a spawner that is off, an enemy waiting to be
 *  triggered. Disabling a parent disables everything under it. */
extern void SDLStatic_ActorSetEnabled(SDLStatic_Actor *actor, bool enabled);
extern bool SDLStatic_ActorEnabled(SDLStatic_Actor *actor);

/* --- transforms ---------------------------------------------------------- */

/** A position, rotation and scale. Local to the parent, or to the world for
 *  an actor with none. */
typedef struct SDLStatic_ActorTransform
{
    float x, y;
    float rotation;
    float scale_x, scale_y;
} SDLStatic_ActorTransform;

extern SDLStatic_ActorTransform SDLStatic_ActorLocal(SDLStatic_Actor *actor);
extern void SDLStatic_ActorSetLocal(SDLStatic_Actor *actor,
                                    const SDLStatic_ActorTransform *transform);

/** Move without interpolating: a teleport, or the initial placement.
 *  Without this the actor smears across the screen from where it was to
 *  where it now is, over one frame. */
extern void SDLStatic_ActorTeleport(SDLStatic_Actor *actor, float x, float y);

extern void SDLStatic_ActorSetPosition(SDLStatic_Actor *actor, float x, float y);
extern void SDLStatic_ActorMove(SDLStatic_Actor *actor, float dx, float dy);

/** The transform composed through every parent: where this actor actually
 *  is in the world. */
extern SDLStatic_ActorTransform SDLStatic_ActorWorld(SDLStatic_Actor *actor);

/**
 * The world transform to *draw* at, interpolated between the previous
 * simulation step and the current one.
 *
 * This is the actor-system half of the loop's interpolation contract: the
 * engine remembers each actor's transform at the last two fixed steps, so a
 * game gets smooth motion without every actor having to keep its own
 * `previous_x`. Pass the `alpha` from the render hook.
 */
extern SDLStatic_ActorTransform SDLStatic_ActorRenderTransform(SDLStatic_Actor *actor,
                                                               float alpha);

/* --- hierarchy ----------------------------------------------------------- */

/** Reparent, keeping the actor's *world* position — which is almost always
 *  what is meant by "pick this up". Pass SDLSTATIC_ACTOR_NONE to detach.
 *
 *  Returns false if the new parent is dead, or if the change would make a
 *  cycle: an actor cannot be its own ancestor, and letting it become one
 *  turns every transform walk into an infinite loop. */
extern bool SDLStatic_ActorSetParent(SDLStatic_Actor *actor, SDLStatic_ActorId parent);

extern SDLStatic_ActorId SDLStatic_ActorParent(SDLStatic_Actor *actor);

/** How many children this actor has. */
extern int SDLStatic_ActorChildCount(SDLStatic_Actor *actor);

/** The `index`th child, or SDLSTATIC_ACTOR_NONE. Order is unspecified and
 *  may change as children come and go, so it is a way to visit them all,
 *  not a way to identify one. */
extern SDLStatic_ActorId SDLStatic_ActorChild(SDLStatic_Actor *actor, int index);

/* --- queries ------------------------------------------------------------- */

/** The first actor of this type, or SDLSTATIC_ACTOR_NONE. */
extern SDLStatic_ActorId SDLStatic_ActorFindByType(SDLStatic_Engine *engine, const char *type);

/** The actor with this instance name. */
extern SDLStatic_ActorId SDLStatic_ActorFindByName(SDLStatic_Engine *engine, const char *name);

/**
 * Collect actors into a caller-supplied array. Returns how many were
 * written, which is at most `capacity`.
 *
 * A caller's array rather than an allocation, because these run every frame
 * — "every enemy within range" is a query, not an event, and a query that
 * allocates is a query you end up caching by hand.
 *
 * `type` may be NULL to mean any type; `tags` may be 0 to mean any tags.
 * With both set, an actor must match both.
 */
extern int SDLStatic_ActorQuery(SDLStatic_Engine *engine, const char *type,
                                SDLStatic_ActorTags tags, SDLStatic_ActorId *out,
                                int capacity);

/** Visit every live actor. The callback must not spawn or destroy —
 *  actually, it may: both are deferred, which is the point of deferring
 *  them. Return false to stop early. */
extern void SDLStatic_ActorEach(SDLStatic_Engine *engine,
                                bool (*visit)(SDLStatic_Actor *actor, void *user), void *user);

/* --- messages ------------------------------------------------------------ */

/**
 * Send a message, delivered after this frame's updates and before it is
 * drawn.
 *
 * Queued rather than called straight through, so that "damage this, which
 * kills it, which spawns three of those, one of which damages me" cannot
 * recurse arbitrarily deep inside one update. The queue is drained in
 * order, and messages sent while draining are delivered on the next frame —
 * which bounds the work in a frame and makes an infinite exchange visibly
 * slow rather than a stack overflow.
 *
 * Returns false if the target is not alive, so a caller can tell.
 */
extern bool SDLStatic_ActorSend(SDLStatic_Engine *engine, SDLStatic_ActorId target,
                                const SDLStatic_ActorMessage *message);

/** Send to every actor of a type, or with any of `tags`. Returns how many
 *  were queued. NULL/0 mean "any", as with SDLStatic_ActorQuery. */
extern int SDLStatic_ActorBroadcast(SDLStatic_Engine *engine, const char *type,
                                    SDLStatic_ActorTags tags,
                                    const SDLStatic_ActorMessage *message);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_ACTOR_H */
