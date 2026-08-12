# SDL3_image (vendored under `image/`)

| | |
|--|--|
| Upstream | https://github.com/libsdl-org/SDL_image |
| Version | 3.4.4 (tag `release-3.4.4`) |
| Commit | `bec9134a26c7d0f31b36d6083c25296e04cabff5` |
| License | zlib (see `image/LICENSE.txt`) |
| Imported | 2026-08-11, direct source copy (no submodule, no fork) |

## What was taken

- `src/` — all C translation units and private headers, including the vendored
  single-file backends: `stb_image.h` (PNG/JPG decode), `tiny_jpeg.h`
  (JPG encode), `qoi.h`, `nanosvg.h` / `nanosvgrast.h` (SVG).
- `include/SDL3_image/SDL_image.h` — the public API header.
- `LICENSE.txt`.

## What was deleted (not imported)

- `.github/` — upstream CI (replaced by this repo's workflows)
- `test/` — upstream test programs and image corpus (this repo grows its own)
- `external/` — submodule stubs for shared-lib codecs (libpng, jpeg, libavif,
  dav1d, aom, libjxl, libtiff, libwebp, zlib) — deliberately unused here
- `VisualC/`, `Xcode/`, `Android.mk` — IDE / platform project files
- `CMakeLists.txt`, `cmake/`, `build-scripts/` — upstream build system
  (replaced by `image/CMakeLists.txt`)
- `docs/`, `examples/`, `CHANGES.txt`, `INSTALL.md`, `README.md`
- `src/genexports.py`, `src/SDL_image.exports`, `src/SDL_image.sym`,
  `src/version.rc` — shared-library export machinery (static-only here)

## Local modifications

Removal pass (no-stubs policy — removed formats fail at build time):

- Deleted translation units and headers: `IMG_avif.*`, `IMG_jxl.c`,
  `IMG_webp.*`, `IMG_tif.c`, `IMG_libpng.*`, `IMG_WIC.*`, `IMG_ImageIO.*`,
  `xmlman.*`.
- `src/IMG.c`: removed the AVIF/JXL/TIF/WEBP loader table rows, the
  WEBP/AVIFS/APNG animation table rows, and the corresponding save-dispatch
  branches.
- `src/IMG_anim_encoder.c` / `src/IMG_anim_decoder.c`: removed the
  AVIF/WEBP/APNG dispatch branches and public wrappers (APNG requires libpng;
  the stb backend cannot provide it — GIF remains the animation format).
- `include/SDL3_image/SDL_image.h`: removed all declarations (and AVIF
  encoder/decoder property defines) for the deleted formats.
- Dormant `#ifdef` branches for never-defined backends inside kept TUs
  (e.g. libpng/WIC paths in `IMG_png.c`) are left in place for diff-minimal
  vendoring; they compile to nothing.

Hardening fixes to vendored code (candidates for upstreaming):

- `src/IMG_anim_decoder.c`: the single-frame fallback no longer runs for
  formats with a dedicated animation decoder — on malformed GIF headers the
  fallback recursed (`IMG_LoadGIF_IO` → decoder → fallback → `IMG_LoadTyped_IO`
  → `IMG_LoadGIF_IO` …) until stack overflow.
- `src/IMG_gif.c`: the LZW decompressor's output stack is now bounds-checked
  at every push; corrupted code tables with multi-entry cycles previously
  wrote past the stack (heap-buffer-overflow). Both found by the
  malformed-input test suite under ASan.

Test corpus provenance: see `tests/image/assets/README.md`.
