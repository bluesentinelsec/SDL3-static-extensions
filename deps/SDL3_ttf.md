# SDL3_ttf (vendored under `ttf/`)

| | |
|--|--|
| Upstream | https://github.com/libsdl-org/SDL_ttf |
| Version | 3.2.2 (tag `release-3.2.2`) |
| Commit | `a1ce3670aec736ecbf0936c43f2f0cc53aa61e5b` |
| License | zlib (see `ttf/LICENSE.txt`) |
| Imported | 2026-08-12, direct source copy (no submodule, no fork) |
| Requires | SDL3 ≥ 3.2.6 (satisfied by our pinned 3.4.14, see `deps/SDL3.md`) |

## What was taken

- `src/` — all C translation units and private headers: the FreeType-based
  core (`SDL_ttf.c`), the three text engines (surface / renderer / GPU),
  hashtable helpers, and the already-vendored single-file `stb_rect_pack.h`.
- `include/SDL3_ttf/` — public headers (`SDL_ttf.h`, `SDL_textengine.h`).
- `LICENSE.txt`.

## What was deleted (not imported)

- `external/` — submodule stubs for **freetype**, **harfbuzz**, **plutosvg**,
  **plutovg**
- `.github/`, `build-scripts/`, `cmake/`, `CMakeLists.txt` — upstream
  CI/build system (replaced by `ttf/CMakeLists.txt` when the build lands)
- `Xcode/`, `VisualC/`, `mingw/`, `Android.mk` — IDE / platform projects
- `docs/`, `examples/`, `test` assets, `CHANGES.txt`, `INSTALL.md`,
  `README.md`
- `src/SDL_ttf.sym`, `src/version.rc` — shared-library export machinery

## Backend status (differs from the Image port!)

Upstream SDL_ttf 3.x hard-requires **FreeType** (`SDLTTF_FREETYPE ON`, not
configurable) — there is no stb backend upstream. HarfBuzz (shaping) and
plutosvg (color emoji) are optional and will **not** be used here.

Phase-A plan (per the design: temporary old backend allowed): build against a
**statically vendored FreeType** via pinned FetchContent, configured minimal
(no harfbuzz, no brotli, no bzip2, no libpng — FreeType itself is
static-link-friendly when built this way, adding zero shared deps).

Phase-B decision (open): replace FreeType with **stb_truetype + our own
DPI/quality code** (design default; a substantial glyph-engine rewrite), or
retain minimal static FreeType permanently (design fallback: "FreeType only if
clearly static-link-friendly" — it is, in this configuration). To be decided
before Phase B starts.

## Local modifications

None yet (snapshot only; removal pass and build wiring follow).
