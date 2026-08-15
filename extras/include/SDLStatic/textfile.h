/**
 * @file textfile.h
 * @brief Reading a whole text file, in a form scripts can use.
 *
 * Original SDLStatic code (zlib). SDL_LoadFile hands back a void* plus a
 * size through an out-parameter — a pair that cannot cross a Lua or Ruby
 * binding boundary, so scripts had no way to read a file at all. This
 * returns a single NUL-terminated string instead: script bindings receive
 * it as an ordinary string (the copy is freed for them), and C callers own
 * the allocation and free it with SDL_free.
 */
#ifndef SDLSTATIC_TEXTFILE_H
#define SDLSTATIC_TEXTFILE_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Read `path` as text. Returns an SDL_malloc'd NUL-terminated string (free
 *  with SDL_free), or NULL with SDL_GetError set. Embedded NUL bytes make
 *  the result look short — this is for text, not binary blobs. */
extern char *SDLStatic_LoadTextFile(const char *path);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_TEXTFILE_H */
