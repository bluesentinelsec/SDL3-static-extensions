---
title: GUI
description: "Nuklear immediate-mode GUI with an SDL3 backend and a weighted grid layout — tool and in-game UI with no hard-coded coordinates."
---

# GUI — `SDLStatic::GUI`

Nuklear v4.13.3 — the single-header immediate-mode GUI — with an original
SDL3 backend and a weighted grid layout helper. For graphical tools,
in-game UI, and general SDL applications; static everywhere SDL3 runs.

```cmake
target_link_libraries(your_app PRIVATE SDLStatic::GUI)
```

## Frame loop

```c
#include <SDLStatic/gui.h>
#include <SDLStatic/gui_grid.h>

SDLStatic_Gui *gui = SDLStatic_CreateGui(renderer, NULL, 0, 0);  /* default font */

/* each frame: */
SDLStatic_GuiInputBegin(gui);
while (SDL_PollEvent(&ev)) { SDLStatic_GuiProcessEvent(gui, &ev); }
SDLStatic_GuiInputEnd(gui);

struct nk_context *ctx = SDLStatic_GuiContext(gui);
if (nk_begin(ctx, "Inspector", nk_rect(20, 20, 280, 340),
             NK_WINDOW_BORDER | NK_WINDOW_TITLE | NK_WINDOW_MOVABLE)) {
    nk_layout_row_dynamic(ctx, 0, 1);
    if (nk_button_label(ctx, "Respawn")) { respawn(); }
    nk_checkbox_label(ctx, "God mode", &god_mode);
    nk_slider_float(ctx, 0, &volume, 1.0f, 0.01f);
}
nk_end(ctx);

SDL_RenderClear(renderer);
/* ...draw the game... */
SDLStatic_GuiRender(gui);          /* UI composites over the frame */
SDL_RenderPresent(renderer);
```

`SDLStatic_GuiWantsInput(gui)` tells the game when the UI owns the
pointer. If you don't need the raw events yourself, the whole input
block collapses to one call:

```c
while (SDLStatic_GuiPumpEvents(gui)) {   /* false when the user quits */
    /* ...build the UI, draw, present... */
}
```

## From Lua and Ruby

The GUI is fully drivable from both script languages through the
generated bindings — `SDLStaticC.CreateGui`, `SDLStaticC.GuiContext`,
`SDLStaticC.GuiPumpEvents`, and the whole `NK.*` widget surface:

```lua
local gui = SDLStaticC.CreateGui(renderer, nil, 0, 0)
local ctx = SDLStaticC.GuiContext(gui)
while SDLStaticC.GuiPumpEvents(gui) do
  if NK.begin(ctx, "Tools", NK.rect(10, 10, 200, 300),
              NK.NK_WINDOW_BORDER + NK.NK_WINDOW_TITLE) then
    NK.layout_row_dynamic(ctx, 0, 1)
    if NK.button_label(ctx, "Bake") then bake() end
    local changed, value = NK.slider_float(ctx, 0, value, 1, 0.01)
  end
  NK.end_(ctx)
  SDLStaticC.GuiRender(gui)
  SDL.RenderPresent(renderer)
end
```

### High-DPI

Create the window with `SDL_WINDOW_HIGH_PIXEL_DENSITY` and the GUI adapts
automatically: the font is baked at the window's pixel density (so text
is crisp on Retina rather than half-size) and mouse input is scaled to
match, so hit-testing lines up. The GUI then lays out in **pixels**;
`SDLStatic_GuiScale(gui)` returns that density, so multiply your own
point-based sizes by it to stay density-independent:

```c
const float s = SDLStatic_GuiScale(gui);          /* 2.0 on Retina */
nk_layout_row_dynamic(ctx, 46.0f * s, 2);         /* 46pt row */
```

Windowless (software) renderers stay at 1.0, so headless tests and
non-Retina displays are unaffected.

### Grid layout from scripts

The full grid helper in `<SDLStatic/gui_grid.h>` takes a caller-owned
struct and a `const float *` of column weights, neither of which can cross
a script boundary. A gui-owned mirror does the same job for every language:

```lua
SDLStaticC.GuiGridWeight(gui, 0, 1.0)   -- label column
SDLStaticC.GuiGridWeight(gui, 1, 2.0)   -- field column, twice as wide
SDLStaticC.GuiGridBeginOwned(gui, 2, 46 * scale)
SDLStaticC.GuiGridCellOwned(gui); NK.label(ctx, "Name:", NK.NK_TEXT_LEFT)
SDLStaticC.GuiGridCellOwned(gui); NK.button_label(ctx, "Browse")
SDLStaticC.GuiGridEndOwned(gui)
```

Weights default to 1 (equal columns) and reset after each grid.

### Images

`SDLStatic_GuiImage(gui, texture, mode)` shows an `SDL_Texture` in the next
widget slot. Nuklear's own `nk_image` takes a struct whose handle is a
union — unreachable from a script — and only ever stretches; this takes the
texture directly and applies a sizing mode:

| Mode | Behaviour |
|---|---|
| `SDLSTATIC_GUI_IMAGE_STRETCH` | fills the slot, ignoring aspect ratio |
| `SDLSTATIC_GUI_IMAGE_ZOOM` | largest fit inside, aspect preserved |
| `SDLSTATIC_GUI_IMAGE_FILL` | covers the slot, aspect preserved, cropped |
| `SDLSTATIC_GUI_IMAGE_CENTER` | native size, centred |

```c
nk_layout_row_dynamic(ctx, 380.0f * scale, 1);
SDLStatic_GuiImage(gui, texture, SDLSTATIC_GUI_IMAGE_ZOOM);
```

Load textures with [SDLStatic::Image](image.html) (`IMG_LoadTexture`), or
from a mounted [VFS](vfs.html) archive. Modes that can overflow the slot are
scissored to it, so an image never spills onto neighbouring widgets.

### Tooltips

`SDLStatic_GuiTooltip(gui, text)` shows hover text for the **next** widget
with desktop timing: it appears only after the pointer has rested on that
widget, and hides again the moment the pointer moves. Nuklear's own
`nk_tooltip` draws immediately and stays up for as long as the pointer is
inside the widget, which is not how tooltips behave.

```c
SDLStatic_GuiTooltip(gui, "Create a new document");
nk_button_label(ctx, "New");
```

The dwell defaults to 1000 ms; `SDLStatic_GuiSetTooltipDelay(gui, ms)`
changes it (0 shows immediately) and `SDLStatic_GuiTooltipDelay` reads it
back. The call returns true on frames where the tooltip is displayed.

### Keyboard and theming from scripts

`SDLStatic_GuiKeyPressed(gui, SDL_SCANCODE_ESCAPE)` reports keys seen
during the last pump — SDL's keyboard-state API returns a raw array that
cannot cross a binding boundary, so this is how scripts implement
"Escape quits". `SDLStatic_GuiPushStyleColor` / `PopStyleColor` theme the
window background, text, buttons and header for the same reason:
Nuklear's own style stack takes union-typed style items.

```lua
SDLStaticC.GuiPushStyleColor(gui, SDLStaticC.SDLSTATIC_GUI_COLOR_WINDOW_BACKGROUND,
                             {r = 28, g = 30, b = 38, a = 255})
-- ...build the window...
SDLStaticC.GuiPopStyleColor(gui, 1)
```

`GuiPumpEvents` exists because `SDL_Event` is a union and cannot cross a
script boundary — it is the supported way to feed input to the GUI from
Lua and Ruby. Three idioms to know: `nk_bool` crosses as a real boolean
(use truthiness, not `~= 0` — `0` is truthy in both languages),
out-parameters come back as extra return values, and enum constants are
registered by name (`NK.NK_WINDOW_TITLE`). The weighted grid helper
below stays C/C++-only: it takes a `const float *` weights array and a
caller-owned struct, so scripts use Nuklear's native
`layout_row_begin`/`push`/`end` instead. The full Nuklear widget set is available through the context:
buttons, check/radio, sliders, progress, spinboxes, single/multi-line
edit with clipboard, combos, lists, trees, menus, popups, tooltips,
charts, color picker. Always include `<SDLStatic/nuklear.h>` (never the
raw header) so every translation unit sees the pinned configuration.

## Grid layout — no hard-coded coordinates

Column weights declared once; widgets placed cell by cell with auto-wrap
and spans. Widths are weight-proportional to the window, so the same
code lays out correctly at any display size:

```c
static const float weights[] = {1, 2};        /* label : field = 1 : 2 */
SDLStatic_GuiGrid grid;
SDLStatic_GuiGridBegin(ctx, &grid, 2, weights, 0);  /* 0 = font-based rows */

SDLStatic_GuiGridCell(&grid);  nk_label(ctx, "Name:", NK_TEXT_LEFT);
SDLStatic_GuiGridCell(&grid);  nk_edit_string_zero_terminated(ctx, NK_EDIT_FIELD,
                                                              name, sizeof(name),
                                                              nk_filter_default);
SDLStatic_GuiGridCellSpan(&grid, 2);  nk_button_label(ctx, "Apply");
SDLStatic_GuiGridEnd(&grid);
```

Tests run fully headless: pixel readback proves rendering, fabricated
SDL events drive clicks, toggles, a real slider drag, and UTF-8 text
entry.

Provenance and configuration:
[`deps/nuklear.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/nuklear.md).
