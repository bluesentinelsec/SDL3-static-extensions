/*
 * sdlstatic_engine_physics.c — Box2D, owned by the engine.
 * Original SDLStatic code (zlib).
 *
 * Three jobs, and the middle one is the whole point of putting physics in
 * the engine rather than beside it:
 *
 *   Convert. Box2D wants metres; games are written in pixels. Every number
 *   crossing this boundary is scaled, so no game code ever sees a metre.
 *
 *   Step with the simulation. The world advances once per fixed step, with
 *   the same step every time, because a solver fed a variable timestep
 *   gives different answers on different machines.
 *
 *   Write back. After the step, each body's position becomes its actor's
 *   transform — so the renderer draws where the solver put things, and
 *   there are not two positions to keep in agreement.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_physics.h>

#include <box2d/box2d.h>

#define DEFAULT_PIXELS_PER_METRE 64.0f

struct SDLStatic_Physics
{
    b2WorldId world;
    bool created;

    float pixels_per_metre;
    float gravity_x, gravity_y;
    int sub_steps;
    bool paused;
    int body_count;

    SDLStatic_CollisionCallback callback;
    void *callback_user;
};

/* Design units to metres and back. Everything in the public API is in
   design units; everything inside Box2D is in metres. */
static float ToMetres(const struct SDLStatic_Physics *physics, float pixels)
{
    return pixels / physics->pixels_per_metre;
}

static float ToPixels(const struct SDLStatic_Physics *physics, float metres)
{
    return metres * physics->pixels_per_metre;
}

static struct SDLStatic_Physics *Physics(SDLStatic_Engine *engine, bool create)
{
    if (engine == NULL)
    {
        return NULL;
    }
    if (engine->physics == NULL && create)
    {
        struct SDLStatic_Physics *physics =
            (struct SDLStatic_Physics *)SDL_calloc(1, sizeof(struct SDLStatic_Physics));
        if (physics == NULL)
        {
            return NULL;
        }
        physics->pixels_per_metre = DEFAULT_PIXELS_PER_METRE;
        physics->gravity_x = 0.0f;
        physics->gravity_y = 980.0f; /* about 1g at the default scale */
        physics->sub_steps = 4;
        engine->physics = physics;
    }
    return engine->physics;
}

static bool EnsureWorld(struct SDLStatic_Physics *physics)
{
    if (physics->created)
    {
        return true;
    }
    b2WorldDef def = b2DefaultWorldDef();
    def.gravity = (b2Vec2){ToMetres(physics, physics->gravity_x),
                           ToMetres(physics, physics->gravity_y)};
    physics->world = b2CreateWorld(&def);
    physics->created = b2World_IsValid(physics->world);
    return physics->created;
}

SDLStatic_BodyDef SDLStatic_BodyDefault(void)
{
    SDLStatic_BodyDef def;
    SDL_zero(def);
    /* A zeroed def would be a sizeless, massless body — one that falls
       through the world. These are the values that make it exist. */
    def.type = SDLSTATIC_BODY_DYNAMIC;
    def.shape = SDLSTATIC_SHAPE_BOX;
    def.width = 32.0f;
    def.height = 32.0f;
    def.density = 1.0f;
    def.friction = 0.6f;
    def.restitution = 0.0f;
    def.gravity_scale = 1.0f;
    return def;
}

/* --- the world ----------------------------------------------------------- */

void SDLStatic_PhysicsSetGravity(SDLStatic_Engine *engine, float x, float y)
{
    struct SDLStatic_Physics *physics = Physics(engine, true);
    if (physics == NULL)
    {
        return;
    }
    physics->gravity_x = x;
    physics->gravity_y = y;
    if (physics->created)
    {
        b2World_SetGravity(physics->world,
                           (b2Vec2){ToMetres(physics, x), ToMetres(physics, y)});
    }
}

void SDLStatic_PhysicsGravity(SDLStatic_Engine *engine, float *x, float *y)
{
    struct SDLStatic_Physics *physics = Physics(engine, false);
    if (x != NULL)
    {
        *x = (physics != NULL) ? physics->gravity_x : 0.0f;
    }
    if (y != NULL)
    {
        *y = (physics != NULL) ? physics->gravity_y : 0.0f;
    }
}

void SDLStatic_PhysicsSetPixelsPerMetre(SDLStatic_Engine *engine, float pixels)
{
    struct SDLStatic_Physics *physics = Physics(engine, true);
    if (physics != NULL && pixels > 0.0f)
    {
        physics->pixels_per_metre = pixels;
    }
}

float SDLStatic_PhysicsPixelsPerMetre(SDLStatic_Engine *engine)
{
    struct SDLStatic_Physics *physics = Physics(engine, false);
    return (physics != NULL) ? physics->pixels_per_metre : DEFAULT_PIXELS_PER_METRE;
}

void SDLStatic_PhysicsSetSubSteps(SDLStatic_Engine *engine, int sub_steps)
{
    struct SDLStatic_Physics *physics = Physics(engine, true);
    if (physics != NULL)
    {
        physics->sub_steps = SDL_clamp(sub_steps, 1, 16);
    }
}

void SDLStatic_PhysicsSetPaused(SDLStatic_Engine *engine, bool paused)
{
    struct SDLStatic_Physics *physics = Physics(engine, true);
    if (physics != NULL)
    {
        physics->paused = paused;
    }
}

bool SDLStatic_PhysicsPaused(SDLStatic_Engine *engine)
{
    struct SDLStatic_Physics *physics = Physics(engine, false);
    return physics != NULL && physics->paused;
}

int SDLStatic_PhysicsBodyCount(SDLStatic_Engine *engine)
{
    struct SDLStatic_Physics *physics = Physics(engine, false);
    return (physics != NULL) ? physics->body_count : 0;
}

void SDLStatic_PhysicsSetCollisionCallback(SDLStatic_Engine *engine,
                                           SDLStatic_CollisionCallback callback, void *user)
{
    struct SDLStatic_Physics *physics = Physics(engine, true);
    if (physics != NULL)
    {
        physics->callback = callback;
        physics->callback_user = user;
    }
}

/* --- bodies -------------------------------------------------------------- */

/* The actor's id travels in the body's user data, so a contact event —
   which only knows about shapes — can name the actors involved. Stored as
   an integer in a pointer rather than a pointer to the actor, because
   actors move in memory and ids do not. */
static void *IdToUserData(SDLStatic_ActorId id)
{
    return (void *)(uintptr_t)id;
}

static SDLStatic_ActorId UserDataToId(void *data)
{
    return (SDLStatic_ActorId)(uintptr_t)data;
}

bool SDLStatic_ActorAddBody(SDLStatic_Actor *actor, const SDLStatic_BodyDef *def)
{
    if (actor == NULL || def == NULL)
    {
        SDL_InvalidParamError("actor/def");
        return false;
    }
    SDLStatic_Engine *engine = SDLStatic_ActorEngine(actor);
    struct SDLStatic_Physics *physics = Physics(engine, true);
    if (physics == NULL || !EnsureWorld(physics))
    {
        return false;
    }
    SDLStatic_ActorRemoveBody(actor);

    const SDLStatic_ActorTransform transform = SDLStatic_ActorWorld(actor);

    b2BodyDef body_def = b2DefaultBodyDef();
    switch (def->type)
    {
    case SDLSTATIC_BODY_STATIC:
        body_def.type = b2_staticBody;
        break;
    case SDLSTATIC_BODY_KINEMATIC:
        body_def.type = b2_kinematicBody;
        break;
    case SDLSTATIC_BODY_DYNAMIC:
    default:
        body_def.type = b2_dynamicBody;
        break;
    }
    body_def.position = (b2Vec2){ToMetres(physics, transform.x + def->offset_x),
                                 ToMetres(physics, transform.y + def->offset_y)};
    body_def.rotation = b2MakeRot(transform.rotation * (float)(SDL_PI_D / 180.0));
    body_def.fixedRotation = def->fixed_rotation;
    body_def.gravityScale = def->gravity_scale;
    body_def.linearDamping = def->damping;
    body_def.isBullet = def->bullet;
    body_def.userData = IdToUserData(SDLStatic_ActorGetId(actor));

    const b2BodyId body = b2CreateBody(physics->world, &body_def);
    if (!b2Body_IsValid(body))
    {
        return false;
    }

    b2ShapeDef shape_def = b2DefaultShapeDef();
    shape_def.density = (def->density > 0.0f) ? def->density : 1.0f;
    shape_def.material.friction = def->friction;
    shape_def.material.restitution = def->restitution;
    shape_def.isSensor = def->sensor;
    /* Contact events are off by default in Box2D v3; the engine's whole
       collision callback depends on them, so they go on here. */
    shape_def.enableContactEvents = true;
    shape_def.enableSensorEvents = true;
    if (def->category != 0)
    {
        shape_def.filter.categoryBits = def->category;
    }
    if (def->collides_with != 0)
    {
        shape_def.filter.maskBits = def->collides_with;
    }

    const float half_w = ToMetres(physics, (def->width > 0.0f ? def->width : 32.0f) * 0.5f);
    const float half_h = ToMetres(physics, (def->height > 0.0f ? def->height : 32.0f) * 0.5f);

    switch (def->shape)
    {
    case SDLSTATIC_SHAPE_CIRCLE: {
        const b2Circle circle = {{0.0f, 0.0f}, half_w};
        b2CreateCircleShape(body, &shape_def, &circle);
        break;
    }
    case SDLSTATIC_SHAPE_CAPSULE: {
        /* The centres of the two end caps, so the total height including
           the round ends is what the caller asked for. */
        const float radius = half_w;
        float centre = half_h - radius;
        if (centre < 0.0f)
        {
            centre = 0.0f; /* wider than tall: a circle, effectively */
        }
        const b2Capsule capsule = {{0.0f, -centre}, {0.0f, centre}, radius};
        b2CreateCapsuleShape(body, &shape_def, &capsule);
        break;
    }
    case SDLSTATIC_SHAPE_BOX:
    default: {
        const b2Polygon box = b2MakeBox(half_w, half_h);
        b2CreatePolygonShape(body, &shape_def, &box);
        break;
    }
    }

    SDLStatic_ActorSetBody(actor, body.index1, body.world0, body.generation, def->offset_x,
                           def->offset_y);
    physics->body_count++;
    return true;
}

/* Rebuild a b2BodyId from what the actor stored. */
static b2BodyId BodyOf(SDLStatic_Actor *actor, struct SDLStatic_Physics **out_physics)
{
    b2BodyId none = {0};
    if (actor == NULL)
    {
        return none;
    }
    int index = 0;
    Uint16 world = 0;
    Uint16 generation = 0;
    float offset_x = 0.0f;
    float offset_y = 0.0f;
    if (!SDLStatic_ActorGetBody(actor, &index, &world, &generation, &offset_x, &offset_y))
    {
        return none;
    }
    struct SDLStatic_Physics *physics = Physics(SDLStatic_ActorEngine(actor), false);
    if (physics == NULL || !physics->created)
    {
        return none;
    }
    if (out_physics != NULL)
    {
        *out_physics = physics;
    }
    b2BodyId body;
    body.index1 = index;
    body.world0 = world;
    body.generation = generation;
    return b2Body_IsValid(body) ? body : none;
}

void SDLStatic_ActorRemoveBody(SDLStatic_Actor *actor)
{
    struct SDLStatic_Physics *physics = NULL;
    const b2BodyId body = BodyOf(actor, &physics);
    if (b2Body_IsValid(body))
    {
        b2DestroyBody(body);
        if (physics != NULL && physics->body_count > 0)
        {
            physics->body_count--;
        }
    }
    SDLStatic_ActorClearBody(actor);
}

bool SDLStatic_ActorHasBody(SDLStatic_Actor *actor)
{
    return b2Body_IsValid(BodyOf(actor, NULL));
}

/* --- driving ------------------------------------------------------------- */

void SDLStatic_ActorSetVelocity(SDLStatic_Actor *actor, float x, float y)
{
    struct SDLStatic_Physics *physics = NULL;
    const b2BodyId body = BodyOf(actor, &physics);
    if (b2Body_IsValid(body))
    {
        b2Body_SetLinearVelocity(body,
                                 (b2Vec2){ToMetres(physics, x), ToMetres(physics, y)});
        b2Body_SetAwake(body, true);
    }
}

void SDLStatic_ActorVelocity(SDLStatic_Actor *actor, float *x, float *y)
{
    struct SDLStatic_Physics *physics = NULL;
    const b2BodyId body = BodyOf(actor, &physics);
    float vx = 0.0f;
    float vy = 0.0f;
    if (b2Body_IsValid(body))
    {
        const b2Vec2 velocity = b2Body_GetLinearVelocity(body);
        vx = ToPixels(physics, velocity.x);
        vy = ToPixels(physics, velocity.y);
    }
    if (x != NULL)
    {
        *x = vx;
    }
    if (y != NULL)
    {
        *y = vy;
    }
}

void SDLStatic_ActorApplyImpulse(SDLStatic_Actor *actor, float x, float y)
{
    struct SDLStatic_Physics *physics = NULL;
    const b2BodyId body = BodyOf(actor, &physics);
    if (b2Body_IsValid(body))
    {
        b2Body_ApplyLinearImpulseToCenter(
            body, (b2Vec2){ToMetres(physics, x), ToMetres(physics, y)}, true);
    }
}

void SDLStatic_ActorApplyForce(SDLStatic_Actor *actor, float x, float y)
{
    struct SDLStatic_Physics *physics = NULL;
    const b2BodyId body = BodyOf(actor, &physics);
    if (b2Body_IsValid(body))
    {
        b2Body_ApplyForceToCenter(body,
                                  (b2Vec2){ToMetres(physics, x), ToMetres(physics, y)}, true);
    }
}

void SDLStatic_ActorSetAngularVelocity(SDLStatic_Actor *actor, float degrees_per_second)
{
    const b2BodyId body = BodyOf(actor, NULL);
    if (b2Body_IsValid(body))
    {
        b2Body_SetAngularVelocity(body, degrees_per_second * (float)(SDL_PI_D / 180.0));
        b2Body_SetAwake(body, true);
    }
}

float SDLStatic_ActorAngularVelocity(SDLStatic_Actor *actor)
{
    const b2BodyId body = BodyOf(actor, NULL);
    if (!b2Body_IsValid(body))
    {
        return 0.0f;
    }
    return b2Body_GetAngularVelocity(body) * (float)(180.0 / SDL_PI_D);
}

void SDLStatic_ActorTeleportBody(SDLStatic_Actor *actor, float x, float y)
{
    struct SDLStatic_Physics *physics = NULL;
    const b2BodyId body = BodyOf(actor, &physics);
    float offset_x = 0.0f;
    float offset_y = 0.0f;
    int index = 0;
    Uint16 world = 0;
    Uint16 generation = 0;
    SDLStatic_ActorGetBody(actor, &index, &world, &generation, &offset_x, &offset_y);

    if (b2Body_IsValid(body))
    {
        b2Body_SetTransform(body,
                            (b2Vec2){ToMetres(physics, x + offset_x),
                                     ToMetres(physics, y + offset_y)},
                            b2Body_GetRotation(body));
        b2Body_SetLinearVelocity(body, (b2Vec2){0.0f, 0.0f});
    }
    /* Reset the interpolation too, or the actor is drawn smearing across
       everywhere it did not travel. */
    SDLStatic_ActorTeleport(actor, x, y);
}

void SDLStatic_ActorWakeBody(SDLStatic_Actor *actor)
{
    const b2BodyId body = BodyOf(actor, NULL);
    if (b2Body_IsValid(body))
    {
        b2Body_SetAwake(body, true);
    }
}

/* The body's world-space bounding box, in design units. Used by the
   lighting integration to treat static bodies as walls — the level's
   collision is usually exactly what should block light. */
bool SDLStatic_ActorBodyBounds(SDLStatic_Actor *actor, SDL_FRect *out)
{
    struct SDLStatic_Physics *physics = NULL;
    const b2BodyId body = BodyOf(actor, &physics);
    if (!b2Body_IsValid(body) || out == NULL || physics == NULL)
    {
        return false;
    }
    int shape_count = b2Body_GetShapeCount(body);
    if (shape_count <= 0)
    {
        return false;
    }
    if (shape_count > 8)
    {
        shape_count = 8;
    }
    b2ShapeId shapes[8];
    shape_count = b2Body_GetShapes(body, shapes, shape_count);

    b2AABB total = b2Shape_GetAABB(shapes[0]);
    for (int i = 1; i < shape_count; ++i)
    {
        const b2AABB aabb = b2Shape_GetAABB(shapes[i]);
        total.lowerBound.x = SDL_min(total.lowerBound.x, aabb.lowerBound.x);
        total.lowerBound.y = SDL_min(total.lowerBound.y, aabb.lowerBound.y);
        total.upperBound.x = SDL_max(total.upperBound.x, aabb.upperBound.x);
        total.upperBound.y = SDL_max(total.upperBound.y, aabb.upperBound.y);
    }

    out->x = ToPixels(physics, total.lowerBound.x);
    out->y = ToPixels(physics, total.lowerBound.y);
    out->w = ToPixels(physics, total.upperBound.x - total.lowerBound.x);
    out->h = ToPixels(physics, total.upperBound.y - total.lowerBound.y);
    return true;
}

/* --- the step ------------------------------------------------------------ */

static SDLStatic_ActorId ActorOfShape(b2ShapeId shape)
{
    if (!b2Shape_IsValid(shape))
    {
        return SDLSTATIC_ACTOR_NONE;
    }
    const b2BodyId body = b2Shape_GetBody(shape);
    if (!b2Body_IsValid(body))
    {
        return SDLSTATIC_ACTOR_NONE;
    }
    return UserDataToId(b2Body_GetUserData(body));
}

/* Write each body's position back onto its actor. This is the step that
   makes the renderer and the solver agree: there is one position, and the
   solver owns it. */
static bool WriteBack(SDLStatic_Actor *actor, void *user)
{
    struct SDLStatic_Physics *physics = (struct SDLStatic_Physics *)user;
    int index = 0;
    Uint16 world = 0;
    Uint16 generation = 0;
    float offset_x = 0.0f;
    float offset_y = 0.0f;
    if (!SDLStatic_ActorGetBody(actor, &index, &world, &generation, &offset_x, &offset_y))
    {
        return true;
    }
    b2BodyId body;
    body.index1 = index;
    body.world0 = world;
    body.generation = generation;
    if (!b2Body_IsValid(body))
    {
        return true;
    }

    const b2Vec2 position = b2Body_GetPosition(body);
    const b2Rot rotation = b2Body_GetRotation(body);

    SDLStatic_ActorTransform transform = SDLStatic_ActorLocal(actor);
    transform.x = ToPixels(physics, position.x) - offset_x;
    transform.y = ToPixels(physics, position.y) - offset_y;
    transform.rotation = b2Rot_GetAngle(rotation) * (float)(180.0 / SDL_PI_D);
    SDLStatic_ActorSetLocal(actor, &transform);
    return true;
}

void SDLStatic_EnginePhysicsStep(SDLStatic_Engine *engine, float step)
{
    struct SDLStatic_Physics *physics = Physics(engine, false);
    if (physics == NULL || !physics->created || physics->paused)
    {
        return;
    }

    b2World_Step(physics->world, step, physics->sub_steps);
    SDLStatic_ActorEach(engine, WriteBack, physics);

    /* Contacts after the step, never during it: the solver is mid-flight
       while it runs, and destroying a body from inside it corrupts the
       world. Actor destruction is deferred anyway, so calling
       SDLStatic_ActorDestroy from a handler is safe — which is the first
       thing every handler wants to do. */
    if (physics->callback == NULL)
    {
        return;
    }
    const b2ContactEvents contacts = b2World_GetContactEvents(physics->world);
    for (int i = 0; i < contacts.beginCount; ++i)
    {
        const SDLStatic_ActorId a = ActorOfShape(contacts.beginEvents[i].shapeIdA);
        const SDLStatic_ActorId b = ActorOfShape(contacts.beginEvents[i].shapeIdB);
        if (a != SDLSTATIC_ACTOR_NONE && b != SDLSTATIC_ACTOR_NONE)
        {
            physics->callback(engine, a, b, true, physics->callback_user);
        }
    }
    for (int i = 0; i < contacts.endCount; ++i)
    {
        const SDLStatic_ActorId a = ActorOfShape(contacts.endEvents[i].shapeIdA);
        const SDLStatic_ActorId b = ActorOfShape(contacts.endEvents[i].shapeIdB);
        if (a != SDLSTATIC_ACTOR_NONE && b != SDLSTATIC_ACTOR_NONE)
        {
            physics->callback(engine, a, b, false, physics->callback_user);
        }
    }

    /* Sensors report through a separate stream, because they never produce
       a contact — the solver has nothing to solve. Folding them into the
       same callback is the whole point of having sensors: a trigger volume
       nobody can detect is not a trigger volume. The sensor is always the
       first actor, so a handler can tell which is which. */
    const b2SensorEvents sensors = b2World_GetSensorEvents(physics->world);
    for (int i = 0; i < sensors.beginCount; ++i)
    {
        const SDLStatic_ActorId sensor = ActorOfShape(sensors.beginEvents[i].sensorShapeId);
        const SDLStatic_ActorId visitor = ActorOfShape(sensors.beginEvents[i].visitorShapeId);
        if (sensor != SDLSTATIC_ACTOR_NONE && visitor != SDLSTATIC_ACTOR_NONE)
        {
            physics->callback(engine, sensor, visitor, true, physics->callback_user);
        }
    }
    for (int i = 0; i < sensors.endCount; ++i)
    {
        const SDLStatic_ActorId sensor = ActorOfShape(sensors.endEvents[i].sensorShapeId);
        const SDLStatic_ActorId visitor = ActorOfShape(sensors.endEvents[i].visitorShapeId);
        if (sensor != SDLSTATIC_ACTOR_NONE && visitor != SDLSTATIC_ACTOR_NONE)
        {
            physics->callback(engine, sensor, visitor, false, physics->callback_user);
        }
    }
}

void SDLStatic_EnginePhysicsDestroy(SDLStatic_Engine *engine)
{
    struct SDLStatic_Physics *physics = Physics(engine, false);
    if (physics == NULL)
    {
        return;
    }
    if (physics->created)
    {
        b2DestroyWorld(physics->world);
    }
    SDL_free(physics);
    engine->physics = NULL;
}

/* --- queries ------------------------------------------------------------- */

SDLStatic_RayHit SDLStatic_PhysicsRaycast(SDLStatic_Engine *engine, float x, float y, float dx,
                                          float dy, Uint32 mask)
{
    SDLStatic_RayHit result;
    SDL_zero(result);

    struct SDLStatic_Physics *physics = Physics(engine, false);
    if (physics == NULL || !physics->created)
    {
        return result;
    }
    b2QueryFilter filter = b2DefaultQueryFilter();
    if (mask != 0)
    {
        filter.maskBits = mask;
    }

    const b2Vec2 origin = {ToMetres(physics, x), ToMetres(physics, y)};
    const b2Vec2 translation = {ToMetres(physics, dx), ToMetres(physics, dy)};
    const b2RayResult ray = b2World_CastRayClosest(physics->world, origin, translation, filter);
    if (!ray.hit)
    {
        return result;
    }
    result.hit = true;
    result.actor = ActorOfShape(ray.shapeId);
    result.x = ToPixels(physics, ray.point.x);
    result.y = ToPixels(physics, ray.point.y);
    result.normal_x = ray.normal.x;
    result.normal_y = ray.normal.y;
    result.fraction = ray.fraction;
    return result;
}

struct OverlapContext
{
    SDLStatic_ActorId *out;
    int capacity;
    int count;
};

static bool OverlapVisit(b2ShapeId shape, void *context)
{
    struct OverlapContext *ctx = (struct OverlapContext *)context;
    const SDLStatic_ActorId id = ActorOfShape(shape);
    if (id == SDLSTATIC_ACTOR_NONE)
    {
        return true;
    }
    /* One entry per actor, not per shape: a body with several shapes would
       otherwise fill the caller's array with the same actor. */
    for (int i = 0; i < ctx->count; ++i)
    {
        if (ctx->out[i] == id)
        {
            return true;
        }
    }
    if (ctx->count < ctx->capacity)
    {
        ctx->out[ctx->count++] = id;
    }
    return ctx->count < ctx->capacity;
}

int SDLStatic_PhysicsOverlap(SDLStatic_Engine *engine, SDL_FRect area, Uint32 mask,
                             SDLStatic_ActorId *out, int capacity)
{
    struct SDLStatic_Physics *physics = Physics(engine, false);
    if (physics == NULL || !physics->created || out == NULL || capacity <= 0)
    {
        return 0;
    }
    b2QueryFilter filter = b2DefaultQueryFilter();
    if (mask != 0)
    {
        filter.maskBits = mask;
    }

    b2AABB aabb;
    aabb.lowerBound = (b2Vec2){ToMetres(physics, area.x), ToMetres(physics, area.y)};
    aabb.upperBound = (b2Vec2){ToMetres(physics, area.x + area.w),
                               ToMetres(physics, area.y + area.h)};

    struct OverlapContext ctx;
    ctx.out = out;
    ctx.capacity = capacity;
    ctx.count = 0;
    b2World_OverlapAABB(physics->world, aabb, filter, OverlapVisit, &ctx);
    return ctx.count;
}
