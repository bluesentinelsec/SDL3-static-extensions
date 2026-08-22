/*
 * SDLStatic/debug_text.h — zero-setup TTF debug text for SDL_Renderer.
 *
 * A convenience layer over SDLStatic::TTF for overlay/diagnostic text (FPS
 * counters, watch values, on-screen logs). Backed by an embedded ProggyClean
 * font (MIT, see src/sdlstatic_debug_font.h) so it needs no font files at
 * runtime, and rendered DPI-aware: glyphs are rasterized at the renderer
 * window's pixel density and drawn 1:1, so debug text is crisp on high-DPI
 * displays.
 *
 * Text color follows the renderer's current draw color (mirrors
 * SDL_RenderDebugText semantics). The font/state initializes lazily on first
 * draw; call SDLStatic_QuitDebugText during shutdown (before TTF_Quit) to
 * release it. Rendered strings are cached, so per-frame HUD text only pays
 * rasterization cost when it changes.
 */

#ifndef SDLSTATIC_DEBUG_TEXT_H_
#define SDLSTATIC_DEBUG_TEXT_H_

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Draw UTF-8 text at (x, y) in renderer coordinates using the embedded debug
 * font and the renderer's current draw color. Lazily initializes on first
 * use. Returns true on success. */
extern bool SDLStatic_RenderDebugText(SDL_Renderer *renderer, float x, float y,
                                      const char *text);

/* printf-style variant of SDLStatic_RenderDebugText. */
extern bool SDLStatic_RenderDebugTextFormat(SDL_Renderer *renderer, float x, float y,
                                            SDL_PRINTF_FORMAT_STRING const char *fmt, ...)
    SDL_PRINTF_VARARG_FUNC(4);

/* Set the debug text size in points (default: 13). Takes effect on the next
 * draw; clears the glyph cache. */
extern void SDLStatic_SetDebugTextSize(float ptsize);

/* Release the embedded font and all cached textures. Safe to call multiple
 * times; the next draw re-initializes. Call before TTF_Quit/SDL_Quit. */
extern void SDLStatic_QuitDebugText(void);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_DEBUG_TEXT_H_ */
