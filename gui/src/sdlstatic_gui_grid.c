/*
 * sdlstatic_gui_grid.c — weighted grid layout helper for Nuklear.
 *
 * Original SDLStatic code (zlib). Semantics in SDLStatic/gui_grid.h: cells
 * advance left-to-right, wrap automatically, and every width is a weight
 * ratio of the window — no hard-coded coordinates anywhere.
 */
#include <SDLStatic/gui_grid.h>

#include <SDL3/SDL.h>

bool SDLStatic_GuiGridBegin(struct nk_context *ctx, SDLStatic_GuiGrid *grid, int columns,
                            const float *weights, float row_height)
{
    if (ctx == NULL || grid == NULL || columns < 1 || columns > SDLSTATIC_GUI_GRID_MAX_COLS)
    {
        return SDL_InvalidParamError("ctx/grid/columns");
    }
    grid->ctx = ctx;
    grid->columns = columns;
    grid->row_height = (row_height > 0.0f) ? row_height : 0.0f; /* 0 = font-based auto */
    grid->cursor = 0;
    grid->row_open = false;
    grid->total_weight = 0.0f;
    for (int i = 0; i < columns; ++i)
    {
        const float w = (weights != NULL && weights[i] > 0.0f) ? weights[i] : 1.0f;
        grid->weights[i] = w;
        grid->total_weight += w;
    }
    return true;
}

static void CloseRow(SDLStatic_GuiGrid *grid)
{
    if (grid->row_open)
    {
        nk_layout_row_end(grid->ctx);
        grid->row_open = false;
    }
    grid->cursor = 0;
}

void SDLStatic_GuiGridCellSpan(SDLStatic_GuiGrid *grid, int span)
{
    if (grid == NULL || grid->ctx == NULL)
    {
        return;
    }
    if (grid->cursor >= grid->columns)
    {
        CloseRow(grid);
    }
    if (!grid->row_open)
    {
        nk_layout_row_begin(grid->ctx, NK_DYNAMIC, grid->row_height, grid->columns);
        grid->row_open = true;
        grid->cursor = 0;
    }
    span = SDL_clamp(span, 1, grid->columns - grid->cursor);
    float weight = 0.0f;
    for (int i = 0; i < span; ++i)
    {
        weight += grid->weights[grid->cursor + i];
    }
    nk_layout_row_push(grid->ctx, weight / grid->total_weight);
    grid->cursor += span;
}

void SDLStatic_GuiGridCell(SDLStatic_GuiGrid *grid)
{
    SDLStatic_GuiGridCellSpan(grid, 1);
}

void SDLStatic_GuiGridNextRow(SDLStatic_GuiGrid *grid)
{
    if (grid != NULL && grid->ctx != NULL)
    {
        CloseRow(grid);
    }
}

void SDLStatic_GuiGridEnd(SDLStatic_GuiGrid *grid)
{
    if (grid != NULL && grid->ctx != NULL)
    {
        CloseRow(grid);
        grid->ctx = NULL;
    }
}

/* --- heap allocation, for callers without a stack ------------------------- */

/* C code declares a grid as a local; a script cannot. Without this every
   grid function was bound into Lua and Ruby and none of them was callable,
   because there was no way to produce the first argument. */
SDLStatic_GuiGrid *SDLStatic_GuiGridCreate(void)
{
    return (SDLStatic_GuiGrid *)SDL_calloc(1, sizeof(SDLStatic_GuiGrid));
}

void SDLStatic_GuiGridDestroy(SDLStatic_GuiGrid *grid)
{
    SDL_free(grid);
}
