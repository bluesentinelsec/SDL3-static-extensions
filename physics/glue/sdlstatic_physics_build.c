/*
 * sdlstatic_physics_build.c — heap builders for Box2D joint definitions.
 * Original SDLStatic code (zlib).
 *
 * Mechanical, and the value is in the shape rather than the code: a
 * create/destroy pair plus scalar setters is what the binding generator
 * already classifies as an owned resource, so every one of these becomes a
 * GC-managed handle in Lua and Ruby with no generator work.
 *
 * Without them b2CreateRevoluteJoint and its siblings were bound and
 * uncallable, because a script cannot produce the def they take — so no
 * joints at all, which is no ragdolls, vehicles, ropes or hinged doors.
 */
#include <SDLStatic/physics_build.h>

#define DEGREES_TO_RADIANS ((float)(SDL_PI_D / 180.0))

/* Each builder starts from Box2D's own default rather than zero: a zeroed
   joint def has no bodies, no frequencies and no limits, and produces a
   joint that either does nothing or explodes. */
#define DEFINE_JOINT_BUILDER(Type, type_name, default_fn)                                        \
    Type *SDLStatic_##type_name##Create(void)                                                    \
    {                                                                                            \
        Type *def = (Type *)SDL_malloc(sizeof(Type));                                            \
        if (def != NULL)                                                                         \
        {                                                                                        \
            *def = default_fn();                                                                 \
        }                                                                                        \
        return def;                                                                              \
    }                                                                                            \
    void SDLStatic_##type_name##Destroy(Type *def)                                               \
    {                                                                                            \
        SDL_free(def);                                                                           \
    }

DEFINE_JOINT_BUILDER(b2DistanceJointDef, DistanceJointDef, b2DefaultDistanceJointDef)
DEFINE_JOINT_BUILDER(b2RevoluteJointDef, RevoluteJointDef, b2DefaultRevoluteJointDef)
DEFINE_JOINT_BUILDER(b2PrismaticJointDef, PrismaticJointDef, b2DefaultPrismaticJointDef)
DEFINE_JOINT_BUILDER(b2WeldJointDef, WeldJointDef, b2DefaultWeldJointDef)
DEFINE_JOINT_BUILDER(b2WheelJointDef, WheelJointDef, b2DefaultWheelJointDef)
DEFINE_JOINT_BUILDER(b2MotorJointDef, MotorJointDef, b2DefaultMotorJointDef)
DEFINE_JOINT_BUILDER(b2MouseJointDef, MouseJointDef, b2DefaultMouseJointDef)
DEFINE_JOINT_BUILDER(b2FilterJointDef, FilterJointDef, b2DefaultFilterJointDef)

/* Bodies and anchors are the same two calls on every joint, so they are
   generated too — writing them out eight times invites the copy-paste bug
   where one of them sets bodyIdA twice. */
#define DEFINE_JOINT_BODIES(Type, type_name)                                                     \
    void SDLStatic_##type_name##SetBodies(Type *def, b2BodyId a, b2BodyId b)                     \
    {                                                                                            \
        if (def != NULL)                                                                         \
        {                                                                                        \
            def->bodyIdA = a;                                                                    \
            def->bodyIdB = b;                                                                    \
        }                                                                                        \
    }

#define DEFINE_JOINT_ANCHORS(Type, type_name)                                                    \
    void SDLStatic_##type_name##SetAnchors(Type *def, float ax, float ay, float bx, float by)    \
    {                                                                                            \
        if (def != NULL)                                                                         \
        {                                                                                        \
            def->localAnchorA = (b2Vec2){ax, ay};                                                \
            def->localAnchorB = (b2Vec2){bx, by};                                                \
        }                                                                                        \
    }

DEFINE_JOINT_BODIES(b2DistanceJointDef, DistanceJointDef)
DEFINE_JOINT_BODIES(b2RevoluteJointDef, RevoluteJointDef)
DEFINE_JOINT_BODIES(b2PrismaticJointDef, PrismaticJointDef)
DEFINE_JOINT_BODIES(b2WeldJointDef, WeldJointDef)
DEFINE_JOINT_BODIES(b2WheelJointDef, WheelJointDef)
DEFINE_JOINT_BODIES(b2MotorJointDef, MotorJointDef)
DEFINE_JOINT_BODIES(b2MouseJointDef, MouseJointDef)
DEFINE_JOINT_BODIES(b2FilterJointDef, FilterJointDef)

DEFINE_JOINT_ANCHORS(b2DistanceJointDef, DistanceJointDef)
DEFINE_JOINT_ANCHORS(b2RevoluteJointDef, RevoluteJointDef)
DEFINE_JOINT_ANCHORS(b2PrismaticJointDef, PrismaticJointDef)
DEFINE_JOINT_ANCHORS(b2WeldJointDef, WeldJointDef)
DEFINE_JOINT_ANCHORS(b2WheelJointDef, WheelJointDef)

/* --- distance -------------------------------------------------------------- */

void SDLStatic_DistanceJointDefSetLength(b2DistanceJointDef *def, float length)
{
    if (def != NULL)
    {
        def->length = length;
    }
}

void SDLStatic_DistanceJointDefSetSpring(b2DistanceJointDef *def, bool enabled, float hertz,
                                         float damping)
{
    if (def != NULL)
    {
        def->enableSpring = enabled;
        def->hertz = hertz;
        def->dampingRatio = damping;
    }
}

void SDLStatic_DistanceJointDefSetLimit(b2DistanceJointDef *def, bool enabled, float min_length,
                                        float max_length)
{
    if (def != NULL)
    {
        def->enableLimit = enabled;
        def->minLength = min_length;
        def->maxLength = max_length;
    }
}

void SDLStatic_DistanceJointDefSetCollideConnected(b2DistanceJointDef *def, bool enabled)
{
    if (def != NULL)
    {
        def->collideConnected = enabled;
    }
}

/* --- revolute -------------------------------------------------------------- */

/* Degrees at this boundary, because a script author setting a hinge limit
   is thinking in degrees; radians are the solver's business. */
void SDLStatic_RevoluteJointDefSetLimit(b2RevoluteJointDef *def, float min_degrees,
                                        float max_degrees)
{
    if (def != NULL)
    {
        def->enableLimit = true;
        def->lowerAngle = min_degrees * DEGREES_TO_RADIANS;
        def->upperAngle = max_degrees * DEGREES_TO_RADIANS;
    }
}

void SDLStatic_RevoluteJointDefSetMotor(b2RevoluteJointDef *def, bool enabled,
                                        float degrees_per_second, float max_torque)
{
    if (def != NULL)
    {
        def->enableMotor = enabled;
        def->motorSpeed = degrees_per_second * DEGREES_TO_RADIANS;
        def->maxMotorTorque = max_torque;
    }
}

void SDLStatic_RevoluteJointDefSetSpring(b2RevoluteJointDef *def, bool enabled, float hertz,
                                         float damping)
{
    if (def != NULL)
    {
        def->enableSpring = enabled;
        def->hertz = hertz;
        def->dampingRatio = damping;
    }
}

void SDLStatic_RevoluteJointDefSetCollideConnected(b2RevoluteJointDef *def, bool enabled)
{
    if (def != NULL)
    {
        def->collideConnected = enabled;
    }
}

/* --- prismatic ------------------------------------------------------------- */

void SDLStatic_PrismaticJointDefSetAxis(b2PrismaticJointDef *def, float x, float y)
{
    if (def != NULL)
    {
        def->localAxisA = (b2Vec2){x, y};
    }
}

void SDLStatic_PrismaticJointDefSetLimit(b2PrismaticJointDef *def, bool enabled, float lower,
                                         float upper)
{
    if (def != NULL)
    {
        def->enableLimit = enabled;
        def->lowerTranslation = lower;
        def->upperTranslation = upper;
    }
}

void SDLStatic_PrismaticJointDefSetMotor(b2PrismaticJointDef *def, bool enabled, float speed,
                                         float max_force)
{
    if (def != NULL)
    {
        def->enableMotor = enabled;
        def->motorSpeed = speed;
        def->maxMotorForce = max_force;
    }
}

/* --- weld ------------------------------------------------------------------ */

void SDLStatic_WeldJointDefSetSpring(b2WeldJointDef *def, float linear_hertz,
                                     float linear_damping, float angular_hertz,
                                     float angular_damping)
{
    if (def != NULL)
    {
        def->linearHertz = linear_hertz;
        def->linearDampingRatio = linear_damping;
        def->angularHertz = angular_hertz;
        def->angularDampingRatio = angular_damping;
    }
}

/* --- wheel ----------------------------------------------------------------- */

void SDLStatic_WheelJointDefSetAxis(b2WheelJointDef *def, float x, float y)
{
    if (def != NULL)
    {
        def->localAxisA = (b2Vec2){x, y};
    }
}

void SDLStatic_WheelJointDefSetSpring(b2WheelJointDef *def, bool enabled, float hertz,
                                      float damping)
{
    if (def != NULL)
    {
        def->enableSpring = enabled;
        def->hertz = hertz;
        def->dampingRatio = damping;
    }
}

void SDLStatic_WheelJointDefSetMotor(b2WheelJointDef *def, bool enabled, float speed,
                                     float max_torque)
{
    if (def != NULL)
    {
        def->enableMotor = enabled;
        def->motorSpeed = speed;
        def->maxMotorTorque = max_torque;
    }
}

/* --- mouse ----------------------------------------------------------------- */

void SDLStatic_MouseJointDefSetSpring(b2MouseJointDef *def, float hertz, float damping)
{
    if (def != NULL)
    {
        def->hertz = hertz;
        def->dampingRatio = damping;
    }
}

void SDLStatic_MouseJointDefSetMaxForce(b2MouseJointDef *def, float force)
{
    if (def != NULL)
    {
        def->maxForce = force;
    }
}
