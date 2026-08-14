# Box2D (vendored under `physics/`)

| | |
|--|--|
| Upstream | https://github.com/erincatto/box2d |
| Version | v3.1.1 (tag commit `8c66146`) |
| License | MIT (see `physics/LICENSE`) |
| Imported | 2026-08-14, direct source copy (no submodule, no fork) |
| Dependencies | none (pure C11; libm on Linux) |

## What was taken

- All of `src/` (35 C files + internal headers) and `include/box2d/` —
  Box2D v3 has no optional heavy components, so unlike the other ports
  there was nothing to delete at the API level. The full b2* API ships.
- SIMD (SSE2/NEON, no AVX2) auto-detects in `core.h` with a scalar
  fallback, so all six platforms including web build the same sources.

## What was deleted (not imported)

Build system, samples, docs, benchmarks, test suite, `.natvis`.

## Original additions (not vendored)

`physics/glue/sdlstatic_physics_draw.c` + `<SDLStatic/physics_draw.h>`:
`SDLStatic_DrawPhysicsWorld()` wires `b2DebugDraw` to the SDLStatic::Gfx
GPU primitives — collision shapes render as a batched overlay through one
`SDL_Renderer`, with world-meters → screen-pixels mapping (y flipped).

## Local modifications to vendored code

None. Box2D passed the sanitizer suite without findings. Build note: the
public include dir is marked SYSTEM because Box2D's inline helpers use
C-style casts that consumer TUs with `-Wold-style-cast -Werror` would
reject.

## 3D note

If 3D physics is ever needed, Jolt Physics (MIT, C++17, actively
maintained) is the designated candidate — deliberately deferred, as
everything in this repo is currently 2D-shaped.
