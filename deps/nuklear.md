# Nuklear (vendored under `gui/`)

| | |
|--|--|
| Upstream | https://github.com/Immediate-Mode-UI/Nuklear (community-maintained) |
| Version | v4.13.3 (commit `a53ad2c`) |
| License | dual MIT / public domain (see `gui/src/LICENSE`) |
| Imported | 2026-08-14, direct copy of `nuklear.h` (exposed as `<nuklear.h>`) |
| Dependencies | none — single ANSI C header; its embedded single-file pieces (stb_truetype, stb_rect_pack) are part of the header |

## What was taken

`nuklear.h` and `LICENSE` — **vendored as-is, no delete-down** (decided
explicitly: the library is one dependency-free header; there is nothing to
slim). Demos, docs, and build files were never imported.

## Configuration

All translation units must include `<SDLStatic/nuklear.h>` — the wrapper
that pins this project's `NK_INCLUDE_*` set (fixed types, default
allocator, vertex-buffer output, font baking, default font) so the
declarations always match the single implementation TU
(`gui/src/sdlstatic_gui.c`). `NK_BUTTON_TRIGGER_ON_RELEASE` is defined:
buttons fire on release (standard desktop behavior), which also keeps
clicks working if an event loop delivers press+release in one frame.

## Original additions (not vendored)

- `gui/src/sdlstatic_gui.c` + `<SDLStatic/gui.h>` — the SDL3 backend:
  font-atlas upload to an `SDL_Texture`, draw-list conversion to vertex
  buffers rendered via batched `SDL_RenderGeometryRaw` with scissor
  clipping, SDL event → Nuklear input translation (mouse, wheel, UTF-8
  text, keyboard incl. clipboard shortcuts), SDL clipboard wiring.
- `gui/src/sdlstatic_gui_grid.c` + `<SDLStatic/gui_grid.h>` — weighted
  grid layout helper: declare column weights once, place widgets cell by
  cell with auto-wrap and spans; all widths are weight-proportional to the
  window, so layouts scale with any display size (no hard-coded x/y).

## Local modifications to vendored code

**`%.0f` printed only the first digit (found 2026-08-14).** With
`NK_INCLUDE_STANDARD_IO` off — our configuration — Nuklear formats text
with its own `nk_vsnprintf`. Its `%f` branch tested
`frac_len >= cur_precision` before any fraction digit had been consumed,
which is immediately true when the precision is `0`, so it broke out of
the copy loop after one character: `nk_labelf("%.0f", 40.0)` rendered
`4`. Any HUD printing an FPS, coordinate or percentage was silently
wrong. Fixed locally by copying the whole integer part and then at most
`cur_precision` fraction digits, and by rounding to the requested
precision before conversion so `%.0f` of `2.7` is `3` like printf rather
than `2`. Regression test: `GuiHarness.LabelfFormatsFloatsCorrectly`
renders the formatted text and the literal it must equal and compares
the painted pixels.

**`NK_DTOA` routed through SDL.** Upstream documents its built-in
double-to-string conversion as "imprecise and possibly unsafe (does not
handle nan or infinity!)". `SDLStatic/nuklear.h` points `NK_DTOA` at
`SDLStatic_NuklearDtoa`, which uses `SDL_snprintf` and clamps
non-finite/huge magnitudes, so conversion is accurate and never emits
exponent form (which the `%f` branch cannot parse).


None. Clean under ASan+UBSan.

## Platform note

Nuklear itself makes no OS calls; all platform specificity lives in the
SDL3 backend, so the GUI runs wherever SDL3 runs — desktop, web, Android,
iOS. On mobile, touches arrive as mouse events and text entry rides
SDL_StartTextInput (desktop-flavored UX, fine for tools and game UI).
