/**
 * @file gui.h
 * @brief SDL3 backend for Nuklear (SDLStatic GUI).
 *
 * Original SDLStatic code (zlib) around the vendored Nuklear. The backend
 * owns the nk_context, the baked font atlas (uploaded once as an
 * SDL_Texture), clipboard wiring, and the render path: each frame the
 * Nuklear draw list is converted to vertex buffers and issued through
 * batched SDL_RenderGeometry calls with scissor clipping.
 *
 * Frame shape (works standalone or inside a game loop):
 *
 *   SDLStatic_GuiInputBegin(gui);
 *   while (SDL_PollEvent(&ev)) { SDLStatic_GuiProcessEvent(gui, &ev); }
 *   SDLStatic_GuiInputEnd(gui);
 *
 *   struct nk_context *ctx = SDLStatic_GuiContext(gui);
 *   if (nk_begin(ctx, "Tools", nk_rect(20, 20, 260, 300),
 *                NK_WINDOW_BORDER | NK_WINDOW_TITLE)) {
 *       nk_layout_row_dynamic(ctx, 0, 1);
 *       if (nk_button_label(ctx, "Save")) { save(); }
 *   }
 *   nk_end(ctx);
 *
 *   SDL_RenderClear(renderer);
 *   ...draw your game...
 *   SDLStatic_GuiRender(gui);        // composites the UI over the frame
 *   SDL_RenderPresent(renderer);
 *
 * For layout without hard-coded coordinates, see SDLStatic/gui_grid.h.
 */
#ifndef SDLSTATIC_GUI_H
#define SDLSTATIC_GUI_H

#include <SDL3/SDL.h>
#include <SDLStatic/nuklear.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SDLStatic_Gui SDLStatic_Gui;

/**
 * Create a GUI backend bound to `renderer`.
 * \param font_data  optional TTF bytes for the UI font (copied); NULL uses
 *                   Nuklear's embedded default font.
 * \param font_size  glyph height in pixels; <= 0 selects 13.
 * \returns a new backend (destroy with SDLStatic_DestroyGui), or NULL.
 */
extern SDLStatic_Gui *SDLStatic_CreateGui(SDL_Renderer *renderer, const void *font_data,
                                          size_t font_len, float font_size);

extern void SDLStatic_DestroyGui(SDLStatic_Gui *gui);

/** The Nuklear context — use the full nk_* API with it. */
extern struct nk_context *SDLStatic_GuiContext(SDLStatic_Gui *gui);

/** Begin collecting input for this frame. */
extern void SDLStatic_GuiInputBegin(SDLStatic_Gui *gui);

/**
 * Feed one SDL event (mouse, wheel, keyboard, text input). Call between
 * InputBegin and InputEnd. \returns true if the event type is one the GUI
 * consumes.
 */
extern bool SDLStatic_GuiProcessEvent(SDLStatic_Gui *gui, const SDL_Event *event);

/** Finish input collection. */
extern void SDLStatic_GuiInputEnd(SDLStatic_Gui *gui);

/**
 * True while the pointer is over / interacting with any Nuklear window —
 * lets a game skip its own input handling when the UI has focus.
 */
extern bool SDLStatic_GuiWantsInput(SDLStatic_Gui *gui);

/**
 * Convert this frame's draw list and render it through the bound renderer,
 * then clear Nuklear state for the next frame.
 */
extern bool SDLStatic_GuiRender(SDLStatic_Gui *gui);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_GUI_H */
