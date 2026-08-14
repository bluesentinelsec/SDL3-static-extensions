/**
 * @file physics_draw.h
 * @brief Debug-draw a Box2D world through the SDLStatic::Gfx GPU primitives.
 *
 * Original SDLStatic code (zlib) — NOT part of vendored Box2D. One call
 * renders the collision shapes of a world as an overlay, batching through
 * SDL_RenderGeometry via the gpu* primitives:
 *
 *   SDLStatic_PhysicsDrawConfig cfg = {
 *       .pixels_per_meter = 32.0f,
 *       .offset_x = 400.0f,   // world origin on screen
 *       .offset_y = 500.0f,   // +y in world is up; screen y flips
 *   };
 *   SDLStatic_DrawPhysicsWorld(worldId, renderer, &cfg);
 *
 * Use the native Box2D API (<box2d/box2d.h>) for everything else.
 */
#ifndef SDLSTATIC_PHYSICS_DRAW_H
#define SDLSTATIC_PHYSICS_DRAW_H

#include <SDL3/SDL.h>
#include <box2d/box2d.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SDLStatic_PhysicsDrawConfig
{
    float pixels_per_meter; /**< world-to-screen scale (default 32 if <= 0) */
    float offset_x;         /**< screen x of the world origin */
    float offset_y;         /**< screen y of the world origin */
    bool draw_joints;       /**< also draw joints */
} SDLStatic_PhysicsDrawConfig;

/**
 * Render every collision shape in `world` to `renderer` as a debug overlay
 * (solid shapes filled, with outlines; y axis flipped so +y is up).
 * \returns true on success.
 */
extern bool SDLStatic_DrawPhysicsWorld(b2WorldId world, SDL_Renderer *renderer,
                                       const SDLStatic_PhysicsDrawConfig *config);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_PHYSICS_DRAW_H */
