# SDLStatic::Gfx

A static-link-first build of [SDL3_gfx](https://github.com/sabdul-khabir/SDL3_gfx)
v1.0.1 (the community SDL3 port of the classic SDL2_gfx) **plus an original
GPU-primitives layer**. SDL3_gfx is pure C over the SDL renderer/surface
APIs with zero external dependencies.

Provenance and local fixes: [`deps/SDL3_gfx.md`](../deps/SDL3_gfx.md).

## What's inside

| Module | Status | Notes |
|--------|--------|-------|
| CPU primitives (`SDL3_gfx/SDL3_gfxPrimitives.h`) | ✅ vendored | pixels, lines, rects, circles, ellipses, arcs, pies, polygons, béziers, 8×8-font text — per-pixel spans via `SDL_RenderPoints` |
| Rotozoom (`SDL3_gfx/SDL3_rotozoom.h`) | ✅ vendored | surface rotation/zoom (one UB fix, see ledger) |
| Framerate manager (`SDL3_gfx/SDL3_framerate.h`) | ✅ vendored | returns `int` 0 on success (old convention) |
| Image filters | ❌ deleted | MMX-era byte-array filters, out of scope |
| **GPU primitives** (`SDLStatic/gpu_primitives.h`) | ✅ **original** | see below |

## GPU-bound primitives (SDLStatic extension)

The vendored primitives are CPU-bound: they compute every covered pixel on
the CPU and submit point batches. `<SDLStatic/gpu_primitives.h>` provides
equivalents with the **same API shape** — same names with a `gpu` prefix,
same parameter order, same `bool` return — that tessellate each shape into
triangles and issue **one `SDL_RenderGeometry` call**, so rasterization and
fill cost move to the GPU and a shape is a single batched draw regardless
of pixel area:

```c
filledCircleRGBA(renderer, x, y, rad, r, g, b, a);     /* CPU per-pixel  */
gpuFilledCircleRGBA(renderer, x, y, rad, r, g, b, a);  /* 1 GPU draw call */
```

Covered: pixel, h/v/thick lines, rectangle/box, rounded rectangle/box,
circle, ellipse, arc, pie (outline + filled), trigon, polygon (outline +
filled — ear-clipping triangulation handles concave shapes), bézier.
Hairline outlines render at 1.5 px so coverage survives every rasterizer.
Not mirrored: `aa*` variants (use MSAA / a filtered target), text (use the
TTF extension), textured polygons (call `SDL_RenderGeometry` directly).

Tests (`tests/gfx/`) run headless on software renderers with pixel
readback: absolute geometry checks plus CPU-vs-GPU coverage comparison
(intersection-over-union) proving both layers draw the same shapes, a
concave-polygon triangulation check, and the standard link audit.
