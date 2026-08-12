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

None yet. Format selection happens via compile definitions in
`image/CMakeLists.txt` (static-friendly formats only). The planned removal
pass will delete the heavy-codec translation units (`IMG_avif.c`, `IMG_jxl.c`,
`IMG_webp.c`, `IMG_tif.c`, `IMG_libpng.c`, `IMG_WIC.c`, `IMG_ImageIO.m`) and
their dispatch entries in `src/IMG.c` / public header, per the no-stubs API
policy.
