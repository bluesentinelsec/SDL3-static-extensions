/*
 * sdlstatic_dialog.c — poll-style native file dialogs.
 * Original SDLStatic code (zlib). See SDLStatic/dialog.h.
 *
 * SDL invokes the dialog callback when the user is done, possibly from a
 * different thread than the one that opened it, so the state is an atomic
 * and the path is published through an atomic pointer: the callback
 * allocates and stores, the polling side reads and frees.
 */
#include <SDLStatic/dialog.h>

static SDL_AtomicInt g_state; /* SDLStatic_DialogState */
static void *g_path;          /* char*, published atomically */

static void SetPath(char *path)
{
    char *previous = (char *)SDL_SetAtomicPointer(&g_path, path);
    if (previous != NULL)
    {
        SDL_free(previous);
    }
}

static void SDLCALL DialogCallback(void *userdata, const char *const *filelist, int filter)
{
    (void)userdata;
    (void)filter;

    if (filelist == NULL)
    {
        /* SDL has already set the error (unsupported platform, backend
         * failure, ...). Leave it in place for the caller to read. */
        SDL_SetAtomicInt(&g_state, SDLSTATIC_DIALOG_ERROR);
        return;
    }
    if (filelist[0] == NULL)
    {
        SDL_SetAtomicInt(&g_state, SDLSTATIC_DIALOG_CANCELLED);
        return;
    }
    {
        char *copy = SDL_strdup(filelist[0]);
        if (copy == NULL)
        {
            SDL_SetAtomicInt(&g_state, SDLSTATIC_DIALOG_ERROR);
            return;
        }
        SetPath(copy);
        SDL_SetAtomicInt(&g_state, SDLSTATIC_DIALOG_ACCEPTED);
    }
}

static bool BeginDialog(bool save, SDL_Window *window, const char *filter_name,
                        const char *filter_pattern, const char *default_location)
{
    if (SDL_GetAtomicInt(&g_state) == SDLSTATIC_DIALOG_PENDING)
    {
        SDL_SetError("a file dialog is already open");
        return false;
    }
    SetPath(NULL);
    SDL_SetAtomicInt(&g_state, SDLSTATIC_DIALOG_PENDING);

    SDL_DialogFileFilter filter;
    const SDL_DialogFileFilter *filters = NULL;
    int filter_count = 0;
    if (filter_name != NULL && filter_pattern != NULL)
    {
        filter.name = filter_name;
        filter.pattern = filter_pattern;
        filters = &filter;
        filter_count = 1;
    }

    if (save)
    {
        SDL_ShowSaveFileDialog(DialogCallback, NULL, window, filters, filter_count,
                               default_location);
    }
    else
    {
        SDL_ShowOpenFileDialog(DialogCallback, NULL, window, filters, filter_count,
                               default_location, false);
    }
    return true;
}

bool SDLStatic_ShowOpenFileDialog(SDL_Window *window, const char *filter_name,
                                  const char *filter_pattern, const char *default_location)
{
    return BeginDialog(false, window, filter_name, filter_pattern, default_location);
}

bool SDLStatic_ShowSaveFileDialog(SDL_Window *window, const char *filter_name,
                                  const char *filter_pattern, const char *default_location)
{
    return BeginDialog(true, window, filter_name, filter_pattern, default_location);
}

SDLStatic_DialogState SDLStatic_DialogStatus(void)
{
    return (SDLStatic_DialogState)SDL_GetAtomicInt(&g_state);
}

const char *SDLStatic_DialogPath(void)
{
    if (SDL_GetAtomicInt(&g_state) != SDLSTATIC_DIALOG_ACCEPTED)
    {
        return NULL;
    }
    return (const char *)SDL_GetAtomicPointer(&g_path);
}

void SDLStatic_DialogReset(void)
{
    SetPath(NULL);
    SDL_SetAtomicInt(&g_state, SDLSTATIC_DIALOG_IDLE);
}
