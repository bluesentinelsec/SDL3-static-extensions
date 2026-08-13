/*
 * sdlstatic_base64.c — Base64 (RFC 4648) for SDLStatic Extras.
 *
 * Original SDLStatic code (zlib). Strict decoder: ASCII whitespace is
 * skipped, anything else outside the alphabet (or misplaced padding)
 * rejects the input.
 */
#include <SDLStatic/base64.h>

static const char kAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char *SDLStatic_EncodeDataBase64(const unsigned char *data, int dataSize, int *outputSize)
{
    if (outputSize != NULL)
    {
        *outputSize = 0;
    }
    if ((data == NULL && dataSize > 0) || dataSize < 0 || outputSize == NULL)
    {
        SDL_InvalidParamError("data/outputSize");
        return NULL;
    }
    const size_t groups = ((size_t)dataSize + 2) / 3;
    char *out = (char *)SDL_malloc(groups * 4 + 1);
    if (out == NULL)
    {
        return NULL;
    }
    char *w = out;
    int i = 0;
    for (; i + 2 < dataSize; i += 3)
    {
        const Uint32 v = ((Uint32)data[i] << 16) | ((Uint32)data[i + 1] << 8) | data[i + 2];
        *w++ = kAlphabet[(v >> 18) & 63];
        *w++ = kAlphabet[(v >> 12) & 63];
        *w++ = kAlphabet[(v >> 6) & 63];
        *w++ = kAlphabet[v & 63];
    }
    const int rest = dataSize - i;
    if (rest == 1)
    {
        const Uint32 v = (Uint32)data[i] << 16;
        *w++ = kAlphabet[(v >> 18) & 63];
        *w++ = kAlphabet[(v >> 12) & 63];
        *w++ = '=';
        *w++ = '=';
    }
    else if (rest == 2)
    {
        const Uint32 v = ((Uint32)data[i] << 16) | ((Uint32)data[i + 1] << 8);
        *w++ = kAlphabet[(v >> 18) & 63];
        *w++ = kAlphabet[(v >> 12) & 63];
        *w++ = kAlphabet[(v >> 6) & 63];
        *w++ = '=';
    }
    *w = '\0';
    *outputSize = (int)(w - out);
    return out;
}

unsigned char *SDLStatic_DecodeDataBase64(const char *text, int *outputSize)
{
    if (outputSize != NULL)
    {
        *outputSize = 0;
    }
    if (text == NULL || outputSize == NULL)
    {
        SDL_InvalidParamError("text/outputSize");
        return NULL;
    }

    /* Upper bound: every 4 significant chars decode to at most 3 bytes. */
    const size_t textLen = SDL_strlen(text);
    unsigned char *out = (unsigned char *)SDL_malloc(textLen / 4 * 3 + 3);
    if (out == NULL)
    {
        return NULL;
    }

    Uint32 acc = 0;
    int bits = 0;
    int written = 0;
    int padding = 0;
    for (const char *p = text; *p != '\0'; ++p)
    {
        const char c = *p;
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
        {
            continue;
        }
        if (c == '=')
        {
            padding++;
            continue;
        }
        int value = -1;
        if (c >= 'A' && c <= 'Z')
        {
            value = c - 'A';
        }
        else if (c >= 'a' && c <= 'z')
        {
            value = c - 'a' + 26;
        }
        else if (c >= '0' && c <= '9')
        {
            value = c - '0' + 52;
        }
        else if (c == '+')
        {
            value = 62;
        }
        else if (c == '/')
        {
            value = 63;
        }
        if (value < 0 || padding > 0) /* data after '=' is invalid too */
        {
            SDL_free(out);
            SDL_SetError("invalid base64 character '%c'", c);
            return NULL;
        }
        acc = (acc << 6) | (Uint32)value;
        bits += 6;
        if (bits >= 8)
        {
            bits -= 8;
            out[written++] = (unsigned char)((acc >> bits) & 0xff);
        }
    }
    if (padding > 2 || (bits >= 6))
    {
        SDL_free(out);
        SDL_SetError("truncated base64 input");
        return NULL;
    }
    *outputSize = written;
    return out;
}
