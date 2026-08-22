/**
 * @file physics_build.h
 * @brief Heap builders for Box2D's joint definitions.
 *
 * Original SDLStatic code (zlib), over the vendored Box2D.
 *
 * Box2D's joint definitions are plain structs a C caller fills in on the
 * stack, initialised from `b2DefaultRevoluteJointDef()` and friends. That
 * is the right shape for C and impossible from a script, which has no stack
 * to put one on — so `b2CreateRevoluteJoint` was bound into Lua and Ruby
 * and uncallable, and with it every joint in the library.
 *
 * No joints means no ragdolls, no vehicles, no ropes, no hinged doors: a
 * real gameplay capability missing rather than an obscure corner.
 *
 *     -- a hinge, from Lua
 *     local d = B2Build.RevoluteJointDefCreate()
 *     B2Build.RevoluteJointDefSetBodies(d, doorBody, wallBody)
 *     B2Build.RevoluteJointDefSetAnchors(d, 0, 0, 1.5, 0)
 *     B2Build.RevoluteJointDefSetLimit(d, -90, 0)
 *     local joint = B2.CreateRevoluteJoint(world, d)
 *     B2Build.RevoluteJointDefDestroy(d)
 *
 * Each builder starts from Box2D's own default for that joint, so a script
 * only sets what it cares about and everything else is the value Box2D
 * intends. Angles are **degrees** here, because a script author reaching
 * for a hinge limit is thinking in degrees and Box2D's radians are an
 * implementation detail of the solver.
 *
 * C code has no reason to use any of this.
 */
#ifndef SDLSTATIC_PHYSICS_BUILD_H
#define SDLSTATIC_PHYSICS_BUILD_H

#include <SDL3/SDL.h>
#include <box2d/box2d.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --- shared -------------------------------------------------------------- */

/* Every joint connects two bodies at two local anchors, so those setters
   repeat per type rather than being one generic call — the alternative is
   casting between def types, which is exactly the sort of thing a script
   should never be asked to do. */

/* --- distance: a rigid or springy rod ------------------------------------- */

extern b2DistanceJointDef *SDLStatic_DistanceJointDefCreate(void);
extern void SDLStatic_DistanceJointDefDestroy(b2DistanceJointDef *def);
extern void SDLStatic_DistanceJointDefSetBodies(b2DistanceJointDef *def, b2BodyId a, b2BodyId b);
extern void SDLStatic_DistanceJointDefSetAnchors(b2DistanceJointDef *def, float ax, float ay,
                                                 float bx, float by);
extern void SDLStatic_DistanceJointDefSetLength(b2DistanceJointDef *def, float length);
extern void SDLStatic_DistanceJointDefSetSpring(b2DistanceJointDef *def, bool enabled,
                                                float hertz, float damping);
extern void SDLStatic_DistanceJointDefSetLimit(b2DistanceJointDef *def, bool enabled,
                                               float min_length, float max_length);
extern void SDLStatic_DistanceJointDefSetCollideConnected(b2DistanceJointDef *def, bool enabled);

/* --- revolute: a hinge ---------------------------------------------------- */

extern b2RevoluteJointDef *SDLStatic_RevoluteJointDefCreate(void);
extern void SDLStatic_RevoluteJointDefDestroy(b2RevoluteJointDef *def);
extern void SDLStatic_RevoluteJointDefSetBodies(b2RevoluteJointDef *def, b2BodyId a, b2BodyId b);
extern void SDLStatic_RevoluteJointDefSetAnchors(b2RevoluteJointDef *def, float ax, float ay,
                                                 float bx, float by);
/** Limits in **degrees**. */
extern void SDLStatic_RevoluteJointDefSetLimit(b2RevoluteJointDef *def, float min_degrees,
                                               float max_degrees);
extern void SDLStatic_RevoluteJointDefSetMotor(b2RevoluteJointDef *def, bool enabled,
                                               float degrees_per_second, float max_torque);
extern void SDLStatic_RevoluteJointDefSetSpring(b2RevoluteJointDef *def, bool enabled,
                                                float hertz, float damping);
extern void SDLStatic_RevoluteJointDefSetCollideConnected(b2RevoluteJointDef *def, bool enabled);

/* --- prismatic: a slider -------------------------------------------------- */

extern b2PrismaticJointDef *SDLStatic_PrismaticJointDefCreate(void);
extern void SDLStatic_PrismaticJointDefDestroy(b2PrismaticJointDef *def);
extern void SDLStatic_PrismaticJointDefSetBodies(b2PrismaticJointDef *def, b2BodyId a,
                                                 b2BodyId b);
extern void SDLStatic_PrismaticJointDefSetAnchors(b2PrismaticJointDef *def, float ax, float ay,
                                                  float bx, float by);
/** The axis the slider runs along, in body A's frame. */
extern void SDLStatic_PrismaticJointDefSetAxis(b2PrismaticJointDef *def, float x, float y);
extern void SDLStatic_PrismaticJointDefSetLimit(b2PrismaticJointDef *def, bool enabled,
                                                float lower, float upper);
extern void SDLStatic_PrismaticJointDefSetMotor(b2PrismaticJointDef *def, bool enabled,
                                                float speed, float max_force);

/* --- weld: two bodies as one ---------------------------------------------- */

extern b2WeldJointDef *SDLStatic_WeldJointDefCreate(void);
extern void SDLStatic_WeldJointDefDestroy(b2WeldJointDef *def);
extern void SDLStatic_WeldJointDefSetBodies(b2WeldJointDef *def, b2BodyId a, b2BodyId b);
extern void SDLStatic_WeldJointDefSetAnchors(b2WeldJointDef *def, float ax, float ay, float bx,
                                             float by);
extern void SDLStatic_WeldJointDefSetSpring(b2WeldJointDef *def, float linear_hertz,
                                            float linear_damping, float angular_hertz,
                                            float angular_damping);

/* --- wheel: a suspension -------------------------------------------------- */

extern b2WheelJointDef *SDLStatic_WheelJointDefCreate(void);
extern void SDLStatic_WheelJointDefDestroy(b2WheelJointDef *def);
extern void SDLStatic_WheelJointDefSetBodies(b2WheelJointDef *def, b2BodyId a, b2BodyId b);
extern void SDLStatic_WheelJointDefSetAnchors(b2WheelJointDef *def, float ax, float ay, float bx,
                                              float by);
extern void SDLStatic_WheelJointDefSetAxis(b2WheelJointDef *def, float x, float y);
extern void SDLStatic_WheelJointDefSetSpring(b2WheelJointDef *def, bool enabled, float hertz,
                                             float damping);
extern void SDLStatic_WheelJointDefSetMotor(b2WheelJointDef *def, bool enabled, float speed,
                                            float max_torque);

/* --- motor: drive one body toward another --------------------------------- */

extern b2MotorJointDef *SDLStatic_MotorJointDefCreate(void);
extern void SDLStatic_MotorJointDefDestroy(b2MotorJointDef *def);
extern void SDLStatic_MotorJointDefSetBodies(b2MotorJointDef *def, b2BodyId a, b2BodyId b);

/* --- mouse: drag a body toward a point ------------------------------------ */

extern b2MouseJointDef *SDLStatic_MouseJointDefCreate(void);
extern void SDLStatic_MouseJointDefDestroy(b2MouseJointDef *def);
extern void SDLStatic_MouseJointDefSetBodies(b2MouseJointDef *def, b2BodyId a, b2BodyId b);
extern void SDLStatic_MouseJointDefSetSpring(b2MouseJointDef *def, float hertz, float damping);
extern void SDLStatic_MouseJointDefSetMaxForce(b2MouseJointDef *def, float force);

/* --- filter: stop two bodies colliding, nothing else ---------------------- */

extern b2FilterJointDef *SDLStatic_FilterJointDefCreate(void);
extern void SDLStatic_FilterJointDefDestroy(b2FilterJointDef *def);
extern void SDLStatic_FilterJointDefSetBodies(b2FilterJointDef *def, b2BodyId a, b2BodyId b);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_PHYSICS_BUILD_H */
