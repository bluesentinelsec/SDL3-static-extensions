/**
 * @file dialog.h
 * @brief Native file open/save dialogs, poll-style.
 *
 * Original SDLStatic code (zlib) over SDL's dialog API. SDL delivers the
 * chosen file through a callback and takes an array of filters — neither
 * of which can cross a Lua/Ruby binding boundary, and callbacks are
 * awkward in an immediate-mode frame loop even in C. This wrapper starts
 * a dialog and lets the caller poll a small state machine each frame:
 *
 *     if (nk_button_label(ctx, "Open")) {
 *         SDLStatic_ShowOpenFileDialog(window, "Text files", "txt", NULL);
 *     }
 *     if (SDLStatic_DialogStatus() == SDLSTATIC_DIALOG_ACCEPTED) {
 *         load(SDLStatic_DialogPath());
 *         SDLStatic_DialogReset();
 *     }
 *
 * One dialog is tracked at a time (that is all a modal file picker can be).
 * Dialogs are a desktop feature: SDL has no Emscripten backend, so on web
 * builds the status becomes SDLSTATIC_DIALOG_ERROR with SDL_GetError()
 * explaining why — check for it rather than assuming success.
 */
#ifndef SDLSTATIC_DIALOG_H
#define SDLSTATIC_DIALOG_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum SDLStatic_DialogState
{
    SDLSTATIC_DIALOG_IDLE = 0,  /**< nothing has been requested */
    SDLSTATIC_DIALOG_PENDING,   /**< the dialog is open, waiting on the user */
    SDLSTATIC_DIALOG_ACCEPTED,  /**< a file was chosen; see SDLStatic_DialogPath */
    SDLSTATIC_DIALOG_CANCELLED, /**< the user dismissed the dialog */
    SDLSTATIC_DIALOG_ERROR      /**< it could not be shown; see SDL_GetError */
} SDLStatic_DialogState;

/** Show a native "open file" dialog. `filter_name`/`filter_pattern` are
 *  optional (NULL for no filter); pattern is SDL's syntax, e.g. "txt" or
 *  "png;jpg". `default_location` may be NULL. Returns false if a dialog is
 *  already pending. */
extern bool SDLStatic_ShowOpenFileDialog(SDL_Window *window, const char *filter_name,
                                         const char *filter_pattern,
                                         const char *default_location);

/** Show a native "save file" dialog — the Save As half of a document app. */
extern bool SDLStatic_ShowSaveFileDialog(SDL_Window *window, const char *filter_name,
                                         const char *filter_pattern,
                                         const char *default_location);

/** Current state. Poll this each frame after starting a dialog. */
extern SDLStatic_DialogState SDLStatic_DialogStatus(void);

/** The chosen path once the status is ACCEPTED, else NULL. Owned by the
 *  library and valid until the next dialog or SDLStatic_DialogReset. */
extern const char *SDLStatic_DialogPath(void);

/** Return to IDLE and release the stored path. Call after handling a
 *  result so the next dialog starts clean. */
extern void SDLStatic_DialogReset(void);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_DIALOG_H */
