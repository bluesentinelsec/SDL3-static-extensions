/**
 * @file bidi.h
 * @brief Unicode BiDi paragraph itemization over vendored SheenBidi.
 *
 * Original SDLStatic code (zlib) around SheenBidi (Apache-2.0; provenance
 * in deps/sheenbidi.md). HarfBuzz shapes one directional run at a time —
 * mixed right-to-left / left-to-right text must first be split into runs
 * by the Unicode Bidirectional Algorithm. This helper does exactly that:
 * feed each returned run to TTF_SetTextDirection + TTF_CreateText (or
 * draw them in array order at advancing positions) and mixed Arabic /
 * Hebrew / Latin strings come out in correct visual order.
 *
 * Runs are returned in VISUAL order (left to right on screen). Handles a
 * single paragraph; text with embedded newlines should be split first.
 */
#ifndef SDLSTATIC_BIDI_H
#define SDLSTATIC_BIDI_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SDLStatic_BidiRun
{
    int offset;               /* byte offset of the run in the UTF-8 input */
    int length;               /* byte length of the run */
    TTF_Direction direction;  /* TTF_DIRECTION_LTR or TTF_DIRECTION_RTL */
} SDLStatic_BidiRun;

/** Split a UTF-8 paragraph into directional runs (visual order).
 *  length -1 means SDL_strlen(utf8). Base direction is derived from the
 *  first strong character (LTR when none). Returns an SDL_malloc'd array
 *  (free with SDL_free) and sets *count; NULL + SDL_GetError on failure.
 *  Plain single-direction text yields exactly one run. */
extern SDLStatic_BidiRun *SDLStatic_BidiItemize(const char *utf8, int length,
                                                int *count);

/** True when the paragraph's base direction (first strong character) is
 *  right-to-left — use to pick text alignment. */
extern bool SDLStatic_BidiBaseIsRTL(const char *utf8, int length);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_BIDI_H */
