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

None. Clean under ASan+UBSan.

## Platform note

Nuklear itself makes no OS calls; all platform specificity lives in the
SDL3 backend, so the GUI runs wherever SDL3 runs — desktop, web, Android,
iOS. On mobile, touches arrive as mouse events and text entry rides
SDL_StartTextInput (desktop-flavored UX, fine for tools and game UI).
