# SDL3_gfx (vendored under `gfx/`)

| | |
|--|--|
| Upstream | https://github.com/sabdul-khabir/SDL3_gfx (community port of ferzkopp's SDL2_gfx to SDL3) |
| Version | v1.0.1 |
| Commit | `ac0128aa5259b4f1f8985db32e48fed33d02a3b5` |
| License | zlib (see `gfx/COPYING`; authors in `gfx/AUTHORS`) |
| Imported | 2026-08-13, direct source copy (no submodule, no fork) |
| Requires | SDL3 (satisfied by our pinned 3.4.14, see `deps/SDL3.md`) |

## What was taken

- `SDL3_gfxPrimitives.c/h` + `SDL3_gfxPrimitives_font.h` — CPU-bound
  primitives (pixels through polygons, 8×8 font text).
- `SDL3_rotozoom.c/h` — surface rotation/zoom.
- `SDL3_framerate.c/h` — framerate manager.
- `COPYING`, `AUTHORS`.

## What was deleted (not imported)

- `SDL3_imageFilter.c/h` — ~7.4k lines of MMX-era byte-array image filters,
  unrelated to drawing; deleted, not stubbed.
- Build files, IDE projects, docs, test program.

SDL3_gfx has zero external dependencies (pure C over the SDL renderer and
surface APIs), so it is inherently static-link friendly — nothing else to
delete-down.

## Original additions (not vendored)

`gfx/src/sdlstatic_gpu_primitives.c` + `<SDLStatic/gpu_primitives.h>`:
GPU-bound equivalents of the CPU primitives (same signatures, `gpu` prefix)
that tessellate to triangles and render via one `SDL_RenderGeometry` call
per primitive. See `gfx/README.md`.

## Local modifications to vendored code

- `SDL3_rotozoom.c` `_transformSurfaceRGBA` + `transformSurfaceY`: the
  `(src->w - dst->w) << 15` fixed-point setup left-shifts a negative value
  whenever the rotated destination is larger than the source — undefined
  behavior, caught by UBSan on the first test run. Replaced the shifts with
  well-defined multiplication by 32768 (both variants).

API conventions note: the primitives return SDL3-style `bool`, but the
framerate module kept the old C convention (`int`, 0 on success).
