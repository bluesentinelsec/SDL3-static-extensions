---
title: Image
description: "Image loading and saving for 13 formats with fully static codecs — SDL3_image without the shared-library tail."
---

# Image — `SDLStatic::Image`

A static-link-first port of SDL3_image (upstream base 3.4.4). The API is
SDL3_image-compatible for everything supported; removed APIs are deleted
from the header so unsupported usage fails at **compile time**, never at
runtime.

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Image)
```

```c
#include <SDL3_image/SDL_image.h>

SDL_Surface *hero = IMG_Load("hero.png");
SDL_Texture *tex  = IMG_LoadTexture(renderer, "tiles.png");
IMG_SavePNG(screenshot, "shot.png");

/* from a VFS-mounted archive: */
SDL_Surface *s = IMG_Load_IO(SDLStatic_OpenVFSRead("/assets/hero.png"), true);
```

## Format support

| Format | Load | Save | Animation |
|--------|------|------|-----------|
| BMP | ✅ | ✅ | — |
| PNG | ✅ | ✅ | — |
| JPG | ✅ | ✅ | — |
| GIF | ✅ | ✅ | ✅ load + save |
| ANI | — | — | ✅ load + save |
| ICO / CUR | ✅ | ✅ | — |
| TGA | ✅ | ✅ | — |
| QOI | ✅ | ❌ | — |
| SVG | ✅ (incl. `IMG_LoadSizedSVG_IO`) | ❌ | — |
| PNM (PBM/PGM/PPM) | ✅ | ❌ | — |
| PCX | ✅ | ❌ | — |
| XPM / XV | ✅ | ❌ | — |

All codecs are vendored single-file C (stb_image, nanosvg, tiny_jpeg,
original encoders) — no libpng, no libjpeg, no zlib dependency. Formats
that required shared libraries upstream (AVIF, JXL, TIFF, WebP) are
removed, headers included.

TGA has no magic bytes: loading TGA from memory needs
`IMG_LoadTyped_IO(io, true, "TGA")` (file loads by `.tga` extension work
directly).

Provenance and change ledger:
[`deps/SDL3_image.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/SDL3_image.md).
