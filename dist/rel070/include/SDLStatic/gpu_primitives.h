/**
 * @file gpu_primitives.h
 * @brief GPU-bound counterparts to the SDL3_gfx CPU primitives.
 *
 * Original SDLStatic code (zlib) — NOT part of the vendored SDL3_gfx. The
 * classic gfx primitives compute pixel spans on the CPU and submit them as
 * points; these equivalents tessellate each shape into triangles and issue
 * ONE SDL_RenderGeometry() call, so rasterization happens on the GPU and a
 * primitive costs a single batched draw regardless of its pixel area.
 *
 * The API mirrors the CPU functions one-for-one: same names with a `gpu`
 * prefix, same parameter order, same Sint16 coordinates, same bool return
 * (false + SDL_GetError() on bad input). Angles are degrees, 0° along +X,
 * increasing toward +Y (screen-down), matching the CPU pie/arc convention.
 *
 * Not mirrored, by design:
 *  - aa* variants — with a multisampled or linearly-filtered target the GPU
 *    path is already smooth; a separate AA tessellation would be redundant.
 *  - character/string — text belongs to the TTF extension.
 *  - texturedPolygon — pass your own texture to SDL_RenderGeometry directly.
 */
#ifndef SDLSTATIC_GPU_PRIMITIVES_H
#define SDLSTATIC_GPU_PRIMITIVES_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --- pixels and lines ------------------------------------------------- */
extern bool gpuPixelRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y,
                         Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuHlineRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 x2, Sint16 y,
                         Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuVlineRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y1, Sint16 y2,
                         Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuLineRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                        Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuThickLineRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                             Uint8 width, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

/* --- rectangles ------------------------------------------------------- */
extern bool gpuRectangleRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                             Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuBoxRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                       Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuRoundedRectangleRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1,
                                    Sint16 x2, Sint16 y2, Sint16 rad,
                                    Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuRoundedBoxRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1,
                              Sint16 x2, Sint16 y2, Sint16 rad,
                              Uint8 r, Uint8 g, Uint8 b, Uint8 a);

/* --- circles, ellipses, arcs, pies ------------------------------------ */
extern bool gpuCircleRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad,
                          Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuFilledCircleRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad,
                                Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuEllipseRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry,
                           Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuFilledEllipseRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry,
                                 Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuArcRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad,
                       Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuPieRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad,
                       Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuFilledPieRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad,
                             Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

/* --- triangles, polygons, curves -------------------------------------- */
extern bool gpuTrigonRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                          Sint16 x3, Sint16 y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuFilledTrigonRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                                Sint16 x3, Sint16 y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuPolygonRGBA(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy, int n,
                           Uint8 r, Uint8 g, Uint8 b, Uint8 a);
/** Fills any simple polygon (convex or concave, no self-intersections or
 *  holes) via ear-clipping triangulation. */
extern bool gpuFilledPolygonRGBA(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy, int n,
                                 Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern bool gpuBezierRGBA(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy, int n,
                          int s, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_GPU_PRIMITIVES_H */
