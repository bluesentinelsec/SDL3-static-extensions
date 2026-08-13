/*
 * sdlstatic_compress.c — DEFLATE wrapper for SDLStatic Extras.
 *
 * Original SDLStatic code (zlib) over vendored sdefl/sinfl (dual
 * MIT/public-domain; provenance in deps/sdefl.md). Container: "SSZ1" +
 * u32le original size + zlib-format DEFLATE stream (adler32-checked).
 */
#include <SDLStatic/compress.h>

#define SDEFL_IMPLEMENTATION
#define SINFL_IMPLEMENTATION
#include "sdefl/sdefl.h"
#include "sdefl/sinfl.h"

#define SSZ_MAGIC "SSZ1"
#define SSZ_HEADER_LEN 8
#define SSZ_LEVEL 8 /* sdefl levels 0..8; favor ratio for asset baking */

unsigned char *SDLStatic_CompressData(const unsigned char *data, int dataSize, int *compDataSize)
{
    if (compDataSize != NULL)
    {
        *compDataSize = 0;
    }
    if ((data == NULL && dataSize > 0) || dataSize < 0 || compDataSize == NULL)
    {
        SDL_InvalidParamError("data/compDataSize");
        return NULL;
    }
    const int bound = sdefl_bound(dataSize);
    unsigned char *out = (unsigned char *)SDL_malloc((size_t)SSZ_HEADER_LEN + (size_t)bound);
    struct sdefl *ctx = (struct sdefl *)SDL_calloc(1, sizeof(struct sdefl));
    if (out == NULL || ctx == NULL)
    {
        SDL_free(out);
        SDL_free(ctx);
        return NULL;
    }
    const int written = zsdeflate(ctx, out + SSZ_HEADER_LEN, data, dataSize, SSZ_LEVEL);
    SDL_free(ctx);
    if (written <= 0)
    {
        SDL_free(out);
        SDL_SetError("deflate failed");
        return NULL;
    }
    SDL_memcpy(out, SSZ_MAGIC, 4);
    out[4] = (Uint8)(dataSize & 0xff);
    out[5] = (Uint8)((dataSize >> 8) & 0xff);
    out[6] = (Uint8)((dataSize >> 16) & 0xff);
    out[7] = (Uint8)((dataSize >> 24) & 0xff);
    *compDataSize = SSZ_HEADER_LEN + written;
    return out;
}

unsigned char *SDLStatic_DecompressData(const unsigned char *compData, int compDataSize,
                                        int *dataSize)
{
    if (dataSize != NULL)
    {
        *dataSize = 0;
    }
    if (compData == NULL || dataSize == NULL)
    {
        SDL_InvalidParamError("compData/dataSize");
        return NULL;
    }
    if (compDataSize < SSZ_HEADER_LEN || SDL_memcmp(compData, SSZ_MAGIC, 4) != 0)
    {
        SDL_SetError("not SDLStatic compressed data");
        return NULL;
    }
    const Uint32 original = (Uint32)compData[4] | ((Uint32)compData[5] << 8) |
                            ((Uint32)compData[6] << 16) | ((Uint32)compData[7] << 24);
    if (original > (Uint32)SDL_MAX_SINT32)
    {
        SDL_SetError("corrupted size header");
        return NULL;
    }
    unsigned char *out = (unsigned char *)SDL_malloc(original > 0 ? original : 1);
    if (out == NULL)
    {
        return NULL;
    }
    const int got = zsinflate(out, (int)original, compData + SSZ_HEADER_LEN,
                              compDataSize - SSZ_HEADER_LEN);
    if (got < 0 || (Uint32)got != original)
    {
        SDL_free(out);
        SDL_SetError("corrupted or truncated compressed data");
        return NULL;
    }
    *dataSize = (int)original;
    return out;
}
