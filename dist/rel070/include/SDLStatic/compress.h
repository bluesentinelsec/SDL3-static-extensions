/**
 * @file compress.h
 * @brief DEFLATE compression for game data (SDLStatic Extras).
 *
 * Original SDLStatic wrapper (zlib) over the vendored sdefl/sinfl
 * single-headers (the same DEFLATE implementation raylib vendors), with
 * raylib's API shape. Output carries a small header ("SSZ1" + original
 * size), so decompression allocates exactly and validates input.
 *
 * Buffers are allocated with SDL_malloc; free results with SDL_free.
 */
#ifndef SDLSTATIC_COMPRESS_H
#define SDLSTATIC_COMPRESS_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Compress a buffer (DEFLATE).
 * \returns a new SDL_malloc'd buffer (*compDataSize bytes), or NULL on error.
 */
extern unsigned char *SDLStatic_CompressData(const unsigned char *data, int dataSize,
                                             int *compDataSize);

/**
 * Decompress a buffer produced by SDLStatic_CompressData.
 * \returns a new SDL_malloc'd buffer (*dataSize bytes), or NULL on
 *          malformed/corrupted input (see SDL_GetError()).
 */
extern unsigned char *SDLStatic_DecompressData(const unsigned char *compData, int compDataSize,
                                               int *dataSize);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_COMPRESS_H */
