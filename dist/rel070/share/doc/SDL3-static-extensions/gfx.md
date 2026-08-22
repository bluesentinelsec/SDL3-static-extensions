---
title: Gfx
description: "2D drawing primitives: the classic SDL3_gfx CPU set plus original GPU-batched equivalents with the same API shape."
---

# Gfx — `SDLStatic::Gfx`

SDL3_gfx v1.0.1 (the community SDL3 port of the classic SDL2_gfx),
statically built, **plus an original GPU-primitives layer** with the same
API shape.

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Gfx)
```

## What's inside

| Piece | Status | Notes |
|-------|--------|-------|
| CPU primitives (`SDL3_gfx/SDL3_gfxPrimitives.h`) | ✅ vendored | pixels, lines, rects, circles, ellipses, arcs, pies, polygons, béziers, 8×8-font text |
| Rotozoom (`SDL3_gfx/SDL3_rotozoom.h`) | ✅ vendored | surface rotation/zoom |
| Framerate manager (`SDL3_gfx/SDL3_framerate.h`) | ✅ vendored | |
| Image filters | ❌ deleted | MMX-era byte-array filters, out of scope |
| **GPU primitives** (`SDLStatic/gpu_primitives.h`) | ✅ original | see below |

## GPU-bound primitives

The vendored primitives are CPU-bound: they compute every covered pixel
on the CPU. The GPU layer provides equivalents — same names with a `gpu`
prefix, same parameter order, same `bool` return — that tessellate each
shape into triangles and issue **one `SDL_RenderGeometry` call**, so fill
cost moves to the GPU and a shape is a single batched draw regardless of
pixel area:

```c
filledCircleRGBA(renderer, x, y, rad, r, g, b, a);     /* CPU per-pixel   */
gpuFilledCircleRGBA(renderer, x, y, rad, r, g, b, a);  /* 1 GPU draw call */
```

Covered: pixel, h/v/thick lines, rectangle/box, rounded rectangle/box,
circle, ellipse, arc, pie (outline + filled), trigon, polygon (outline +
filled — ear-clipping triangulation handles concave shapes), bézier.
Hairline outlines render at 1.5 px so coverage survives every rasterizer.

Not mirrored: antialiased `aa*` variants (use MSAA or a filtered target),
text (use [TTF](ttf.html)), textured polygons (call `SDL_RenderGeometry`
directly).

Tests render headless with pixel readback and prove the CPU and GPU
layers draw the same shapes (intersection-over-union comparison).

Provenance and local fixes:
[`deps/SDL3_gfx.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/SDL3_gfx.md).
