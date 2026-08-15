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

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

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

#ifdef __EMSCRIPTEN__
/* ---------------------------------------------------------------- web ---
 * SDL has no Emscripten dialog backend, so drive the browser directly.
 * Results are parked on a JS-side object and polled from C, which avoids
 * calling back into wasm (that would need extra exported-runtime linker
 * flags in every consuming program).
 */

/* Reads the pending result; returns the SDLStatic_DialogState and copies
   any path into `buf`. */
static int WebPollDialog(char *buf, int buflen)
{
    return EM_ASM_INT(
        {
            var d = Module.__sdlstatic_dialog;
            if (!d) return 0;                    /* IDLE */
            if (d.state === 'pending') return 1; /* PENDING */
            if (d.state === 'accepted')
            {
                stringToUTF8(d.path, $0, $1);
                return 2; /* ACCEPTED */
            }
            if (d.state === 'cancelled') return 3;
            return 4; /* ERROR */
        },
        buf, buflen);
}

static void WebBeginOpen(const char *filter_pattern)
{
    EM_ASM(
        {
            Module.__sdlstatic_dialog = ({state : 'pending'});
            var input = document.createElement('input');
            input.type = 'file';
            input.style.display = 'none';
            if ($0)
            {
                /* SDL filter syntax is "txt" or "png;jpg"; the DOM wants
                   ".txt,.png". */
                var pattern = UTF8ToString($0);
                if (pattern !== '*')
                {
                    input.accept = pattern.split(';')
                                       .map(function(ext) { return '.' + ext.trim(); })
                                       .join(',');
                }
            }
            input.onchange = function(event)
            {
                var file = event.target.files && event.target.files[0];
                if (!file)
                {
                    Module.__sdlstatic_dialog = ({state : 'cancelled'});
                    return;
                }
                var reader = new FileReader();
                reader.onload = function()
                {
                    try
                    {
                        FS.mkdir('/dialog');
                    }
                    catch (e)
                    { /* already exists */
                    }
                    var path = '/dialog/' + file.name;
                    FS.writeFile(path, new Uint8Array(reader.result));
                    Module.__sdlstatic_dialog = ({state : 'accepted', path : path});
                };
                reader.onerror = function()
                {
                    Module.__sdlstatic_dialog = ({state : 'error'});
                };
                reader.readAsArrayBuffer(file);
            };
            /* Browsers only report a chosen file, never a dismissal, so a
               cancelled picker simply leaves the dialog pending. */
            document.body.appendChild(input);
            input.click();
            document.body.removeChild(input);
        },
        filter_pattern);
}

static void WebBeginSave(const char *suggested)
{
    EM_ASM(
        {
            /* A page cannot write to the user's disk, so there is no save
               picker: resolve to a virtual path now and let the app write
               to it. SDLStatic_DialogDeliverSave downloads it afterwards. */
            try
            {
                FS.mkdir('/dialog');
            }
            catch (e)
            { /* already exists */
            }
            var name = $0 ? UTF8ToString($0) : 'untitled.txt';
            Module.__sdlstatic_dialog = ({state : 'accepted', path : '/dialog/' + name});
        },
        suggested);
}
#endif /* __EMSCRIPTEN__ */

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

#ifdef __EMSCRIPTEN__
    (void)window;
    (void)filters;
    (void)filter_count;
    if (save)
    {
        WebBeginSave(default_location);
    }
    else
    {
        WebBeginOpen(filter_pattern);
    }
#else
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
#endif
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
#ifdef __EMSCRIPTEN__
    /* The browser result lands in JS; fold it into the same state machine
     * the native path uses so callers cannot tell the difference. */
    if (SDL_GetAtomicInt(&g_state) == SDLSTATIC_DIALOG_PENDING)
    {
        char path[1024];
        path[0] = '\0';
        const int state = WebPollDialog(path, (int)sizeof(path));
        if (state == SDLSTATIC_DIALOG_ACCEPTED && path[0] != '\0')
        {
            SetPath(SDL_strdup(path));
            SDL_SetAtomicInt(&g_state, SDLSTATIC_DIALOG_ACCEPTED);
        }
        else if (state == SDLSTATIC_DIALOG_CANCELLED)
        {
            SDL_SetAtomicInt(&g_state, SDLSTATIC_DIALOG_CANCELLED);
        }
        else if (state == SDLSTATIC_DIALOG_ERROR)
        {
            SDL_SetError("the browser could not read the chosen file");
            SDL_SetAtomicInt(&g_state, SDLSTATIC_DIALOG_ERROR);
        }
    }
#endif
    return (SDLStatic_DialogState)SDL_GetAtomicInt(&g_state);
}

bool SDLStatic_DialogDeliverSave(const char *path)
{
    if (path == NULL)
    {
        SDL_InvalidParamError("path");
        return false;
    }
#ifdef __EMSCRIPTEN__
    {
        size_t size = 0;
        void *data = SDL_LoadFile(path, &size);
        if (data == NULL)
        {
            return false; /* SDL has set the error */
        }
        EM_ASM(
            {
                var bytes = HEAPU8.slice($0, $0 + $1);
                var name = UTF8ToString($2).split('/').pop();
                var blob = new Blob([bytes], ({type : 'application/octet-stream'}));
                var url = URL.createObjectURL(blob);
                var link = document.createElement('a');
                link.href = url;
                link.download = name;
                document.body.appendChild(link);
                link.click();
                document.body.removeChild(link);
                setTimeout(function() { URL.revokeObjectURL(url); }, 0);
            },
            data, (int)size, path);
        SDL_free(data);
    }
#endif
    return true; /* desktop: the file is already where the user chose */
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
#ifdef __EMSCRIPTEN__
    EM_ASM({ Module.__sdlstatic_dialog = null; });
#endif
}
