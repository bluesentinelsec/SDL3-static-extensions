/**
 * @file gui_grid.h
 * @brief Weighted grid layout helper for Nuklear (SDLStatic GUI).
 *
 * Original SDLStatic code (zlib). Nuklear's native layout is row-at-a-time;
 * this helper adds a Tkinter-grid flavor on top so nothing hard-codes x/y
 * coordinates: declare column weights once, then place widgets cell by
 * cell. Cells advance left-to-right and wrap to a new row automatically;
 * spans merge adjacent columns. All widths are weight-proportional to the
 * window, so the layout scales with any display or window size.
 *
 *   static const float weights[] = {1.0f, 2.0f, 1.0f};   // like Tk column weight
 *   SDLStatic_GuiGrid grid;
 *   SDLStatic_GuiGridBegin(ctx, &grid, 3, weights, 0);   // 0 = auto row height
 *
 *   SDLStatic_GuiGridCell(&grid);          nk_label(ctx, "Name:", NK_TEXT_LEFT);
 *   SDLStatic_GuiGridCellSpan(&grid, 2);   nk_edit_string_zero_terminated(...);
 *
 *   SDLStatic_GuiGridCell(&grid);          nk_label(ctx, "HP:", NK_TEXT_LEFT);
 *   SDLStatic_GuiGridCellSpan(&grid, 2);   nk_slider_int(ctx, 0, &hp, 100, 1);
 *
 *   SDLStatic_GuiGridEnd(&grid);
 */
#ifndef SDLSTATIC_GUI_GRID_H
#define SDLSTATIC_GUI_GRID_H

#include <SDLStatic/nuklear.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SDLSTATIC_GUI_GRID_MAX_COLS 16

typedef struct SDLStatic_GuiGrid
{
    struct nk_context *ctx;
    float weights[SDLSTATIC_GUI_GRID_MAX_COLS];
    float total_weight;
    float row_height;
    int columns;
    int cursor;   /* next column index in the current row */
    bool row_open;
} SDLStatic_GuiGrid;

/**
 * Start a grid inside the current Nuklear window.
 * \param columns     1..SDLSTATIC_GUI_GRID_MAX_COLS
 * \param weights     per-column weights (like Tkinter's column weight);
 *                    NULL means equal columns.
 * \param row_height  pixel height per row; <= 0 derives one widget row from
 *                    the current font (so even heights need no hard-coding).
 * \returns false on bad parameters.
 */
/** A grid on the heap, for callers that cannot declare one on the stack.
 *
 *  C code should keep using a local — it is cheaper and scoped. This exists
 *  for scripts, which have no stack to put a struct on, and without it every
 *  grid function was bound and uncallable. */
extern SDLStatic_GuiGrid *SDLStatic_GuiGridCreate(void);
extern void SDLStatic_GuiGridDestroy(SDLStatic_GuiGrid *grid);

extern bool SDLStatic_GuiGridBegin(struct nk_context *ctx, SDLStatic_GuiGrid *grid, int columns,
                                   const float *weights, float row_height);

/** Claim the next cell (auto-wraps to a new row when the row is full). Call
 *  exactly one widget after each claimed cell. */
extern void SDLStatic_GuiGridCell(SDLStatic_GuiGrid *grid);

/** Like Cell, but spanning `span` columns (clamped to the row remainder). */
extern void SDLStatic_GuiGridCellSpan(SDLStatic_GuiGrid *grid, int span);

/** Force the next cell onto a fresh row even if this one isn't full. */
extern void SDLStatic_GuiGridNextRow(SDLStatic_GuiGrid *grid);

/** Finish the grid (closes the last row). */
extern void SDLStatic_GuiGridEnd(SDLStatic_GuiGrid *grid);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_GUI_GRID_H */
