# SDLStatic::TTF

A static-link-first port of [SDL_ttf](https://github.com/libsdl-org/SDL_ttf)
(upstream base: **3.2.2**; provenance and change ledger in
[`deps/SDL3_ttf.md`](../deps/SDL3_ttf.md)). Glyph backend: **minimal static
FreeType 2.14.3** via hash-pinned FetchContent
([`deps/FreeType.md`](../deps/FreeType.md)) — internal zlib, no
harfbuzz/png/brotli/bzip2, zero shared-library dependencies (CI-enforced by
the `ttf_link_audit` test). Removed APIs are deleted from the header, so
unsupported usage fails at **compile time**.

## Supported

- TTF / OTF (CFF) fonts, TrueType collections, memory fonts, font fallbacks
- Sizing incl. **DPI-aware** scaling (`TTF_SetFontSizeDPI`) — hinted
  FreeType rendering at any density
- Render modes: Solid, Shaded, Blended, LCD; glyph and string metrics,
  measurement, wrapping
- Styles: bold, italic, underline, strikethrough, **outline** (FT_Stroker),
  hinting control, SDF rendering
- Kerning; the TTF_Text engines (surface / renderer / GPU) with the
  non-shaped layout path

## NOT supported (deliberately removed)

| Removed | Why |
|---------|-----|
| Complex-script shaping & BiDi (`TTF_SetFontScript`, `TTF_GetGlyphScript`, `TTF_SetTextScript`, direction setters/getters — 9 APIs) | Require HarfBuzz; out of scope per the design (v1 targets LTR game text) |
| Color emoji / SVG glyphs | Require plutosvg/plutovg + FreeType PNG support |
| WOFF2 fonts | Requires Brotli |

Text direction is LTR. `TTF_Direction` remains as an inert type.

## SDLStatic additions

`SDLStatic/debug_text.h` — zero-setup debug/HUD text for any `SDL_Renderer`:

```c
SDL_SetRenderDrawColor(renderer, 80, 250, 123, 255);   /* text color */
SDLStatic_RenderDebugTextFormat(renderer, 8, 8, "FPS: %d", fps);
```

Backed by an **embedded ProggyClean** font (MIT, ~40KB, license reproduced in
`src/sdlstatic_debug_font.h`) — no font files needed at runtime. DPI-aware
(rasterized at the window's pixel density, drawn 1:1), color follows the
renderer draw color, rendered strings are cached. `SDLStatic_SetDebugTextSize`
adjusts size; call `SDLStatic_QuitDebugText` at shutdown.

## Attribution requirement

FreeType is licensed under the FTL: products shipping this library must
credit The FreeType Project in their documentation — see
[`deps/FreeType.md`](../deps/FreeType.md) for the exact notice.

## Guarantees (CI-enforced)

- No non-OS shared-library dependencies (`ttf_link_audit`)
- Malformed-font robustness: truncation/bit-flip inputs exercised under
  ASan+UBSan in CI
- Rendering produces real glyph coverage (pixel-count assertions), DPI
  scaling verified geometrically
