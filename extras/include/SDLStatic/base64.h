/**
 * @file base64.h
 * @brief Base64 encoding/decoding (SDLStatic Extras).
 *
 * Original SDLStatic code (zlib), raylib API shape. Standard RFC 4648
 * alphabet with '=' padding; the decoder skips ASCII whitespace and
 * rejects anything else invalid.
 *
 * Buffers are allocated with SDL_malloc; free results with SDL_free.
 */
#ifndef SDLSTATIC_BASE64_H
#define SDLSTATIC_BASE64_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Encode binary data as Base64.
 * \returns a new NUL-terminated SDL_malloc'd string; *outputSize is the
 *          string length (excluding the NUL). NULL on error.
 */
extern char *SDLStatic_EncodeDataBase64(const unsigned char *data, int dataSize, int *outputSize);

/**
 * Decode a Base64 string (NUL-terminated).
 * \returns a new SDL_malloc'd buffer (*outputSize bytes), or NULL on
 *          invalid input (see SDL_GetError()).
 */
extern unsigned char *SDLStatic_DecodeDataBase64(const char *text, int *outputSize);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_BASE64_H */
