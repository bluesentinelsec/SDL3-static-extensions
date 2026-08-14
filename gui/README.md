# SDLStatic::GUI

[Nuklear](https://github.com/Immediate-Mode-UI/Nuklear) v4.13.3 — the
single-header immediate-mode GUI — with an original SDL3 backend and a
weighted grid layout helper. For graphical tools, in-game UI, and general
SDL applications; static everywhere SDL3 runs (desktop, web, mobile).

Provenance and configuration: [`deps/nuklear.md`](../deps/nuklear.md).

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

`SDLStatic_GuiWantsInput(gui)` tells a game when the UI owns the pointer.
The full Nuklear widget set is available through the context: buttons,
check/radio, sliders, progress, property/spinbox, single/multi-line edit
with clipboard, combo, lists, trees, menus, popups, tooltips, charts,
color picker. Include `<SDLStatic/nuklear.h>` (never the raw header) so
every TU sees the pinned configuration.

## Grid layout — no hard-coded coordinates

Column weights declared once; widgets placed cell by cell with auto-wrap
and spans. Widths are weight-proportional to the window, so the same code
lays out correctly at any display size:

```c
static const float weights[] = {1, 2};        /* label : field = 1 : 2 */
SDLStatic_GuiGrid grid;
SDLStatic_GuiGridBegin(ctx, &grid, 2, weights, 0);  /* 0 = font-based rows */

SDLStatic_GuiGridCell(&grid);  nk_label(ctx, "Name:", NK_TEXT_LEFT);
SDLStatic_GuiGridCell(&grid);  nk_edit_string_zero_terminated(ctx, NK_EDIT_FIELD,
                                                              name, sizeof(name),
                                                              nk_filter_default);
SDLStatic_GuiGridCell(&grid);  nk_label(ctx, "HP:", NK_TEXT_LEFT);
SDLStatic_GuiGridCell(&grid);  nk_slider_int(ctx, 0, &hp, 100, 1);

SDLStatic_GuiGridCellSpan(&grid, 2);  nk_button_label(ctx, "Apply");
SDLStatic_GuiGridEnd(&grid);
```

Tests (`tests/gui/`) run fully headless on a software renderer: pixel
readback proves rendering, fabricated SDL events drive button clicks,
checkbox toggles, a real slider drag, and UTF-8 text entry, and the grid
tests assert weight-proportional widths, spans, auto-wrap, and that cell
geometry scales with window size — the no-hard-coded-coordinates
guarantee. Plus the standard link audit.
