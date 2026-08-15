/*
 * sdlstatic_textfile.c — whole-file text reads.
 * Original SDLStatic code (zlib). See SDLStatic/textfile.h.
 */
#include <SDLStatic/textfile.h>

char *SDLStatic_LoadTextFile(const char *path)
{
    if (path == NULL)
    {
        SDL_InvalidParamError("path");
        return NULL;
    }
    size_t size = 0;
    void *data = SDL_LoadFile(path, &size);
    if (data == NULL)
    {
        return NULL; /* SDL has set the error */
    }
    /* SDL_LoadFile already NUL-terminates, but do not rely on it: copy into
     * a buffer this function owns and terminate explicitly. */
    char *text = (char *)SDL_malloc(size + 1);
    if (text == NULL)
    {
        SDL_free(data);
        return NULL;
    }
    SDL_memcpy(text, data, size);
    text[size] = '\0';
    SDL_free(data);
    return text;
}
