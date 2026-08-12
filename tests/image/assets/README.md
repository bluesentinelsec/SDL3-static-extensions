# Image test corpus

Sources:

- `sample.*`, `palette.gif`, `rgbrgb.*`, `svg.svg` — copied from upstream
  SDL_image's `test/` directory at the pinned vendoring commit
  `bec9134a26c7d0f31b36d6083c25296e04cabff5` (tag `release-3.4.4`, zlib
  license; see `deps/SDL3_image.md`).
- `generated.lbm`, `generated.xv` — produced by `scripts/gen_test_images.py`
  (deterministic; regenerate with `python3 scripts/gen_test_images.py`).

The `sample.avif`, `sample.jxl`, `sample.tif`, and `rgbrgb.webp` files are the
**negative** corpus: these formats were deliberately removed from
SDLStatic::Image, and tests assert they no longer load.
