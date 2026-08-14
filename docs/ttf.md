---
title: TTF
description: "TrueType/OpenType text rendering via a minimal static FreeType, plus zero-setup debug text with an embedded font."
---

# TTF — `SDLStatic::TTF`

A static-link-first port of SDL_ttf (upstream base 3.2.2) over a minimal
static FreeType 2.14.3 — internal zlib, no HarfBuzz/libpng/Brotli/bzip2.
Zero shared-library dependencies, enforced in CI by a link audit.

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::TTF)
```

```c
#include <SDL3_ttf/SDL_ttf.h>

TTF_Init();
TTF_Font *font = TTF_OpenFont("kenney-pixel.ttf", 24.0f);
SDL_Surface *label = TTF_RenderText_Blended(font, "READY?", 0,
                                            (SDL_Color){255, 255, 255, 255});
```

## Supported

- TTF / OTF (CFF), TrueType collections, memory fonts, font fallbacks
- DPI-aware sizing (`TTF_SetFontSizeDPI`) — hinted rendering at any density
- Render modes: Solid, Shaded, Blended, LCD; metrics, measurement, wrapping
- Styles: bold, italic, underline, strikethrough, outline (FT_Stroker),
  hinting control, SDF rendering
- Kerning; the `TTF_Text` engines (surface / renderer / GPU), non-shaped
  layout path

## Deliberately removed

| Removed | Why |
|---------|-----|
| Complex-script shaping &amp; BiDi (9 APIs) | require HarfBuzz; v1 targets LTR game text |
| Color emoji / SVG glyphs | require plutosvg + FreeType PNG support |
| WOFF2 fonts | requires Brotli |

Removed APIs are deleted from the header — misuse fails at compile time.

## Debug text (original extension)

`<SDLStatic/debug_text.h>` renders HUD/debug text on any `SDL_Renderer`
with **no font files at runtime** — an embedded ProggyClean font (~40 KB)
is compiled in, rasterized DPI-aware, colored by the current draw color:

```c
SDL_SetRenderDrawColor(renderer, 80, 250, 123, 255);
SDLStatic_RenderDebugTextFormat(renderer, 8, 8, "FPS: %d", fps);
```

Provenance:
[`deps/SDL3_ttf.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/SDL3_ttf.md)
·
[`deps/FreeType.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/FreeType.md).
