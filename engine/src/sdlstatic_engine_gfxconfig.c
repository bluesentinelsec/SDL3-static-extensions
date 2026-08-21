/*
 * sdlstatic_engine_gfxconfig.c — where graphics settings come from.
 * Original SDLStatic code (zlib).
 *
 * Four sources, in increasing order of authority:
 *
 *   compiled-in defaults
 *   the config shipped inside the media archive       (the game's opinion)
 *   media/config.toml beside the executable           (an installer's)
 *   media/config.toml in the pref directory           (the player's)
 *   the command line                                  (right now)
 *
 * The player's saved settings beat what the game shipped with, and the
 * command line beats everything — which is the order you want at 2am when a
 * game will not start because someone saved an unsupported setting.
 *
 * Nothing here is fatal. A malformed config leaves the previous values in
 * place and is reported through SDLStatic_GraphicsConfigError, because a
 * typo in a settings file should not stop a game from running.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_graphics.h>

#include <toml.h>

#include <stdlib.h> /* tomlc99 hands back malloc'd strings */

/* Diagnostics from the last resolve. Static because they are answers to
   "what did you read, and did it work" — questions asked once, at startup,
   and not worth an out-parameter on every call. */
static char g_config_path[1024];
static char g_config_error[512];

static SDLStatic_GraphicsReadFile g_archive_reader = NULL;
static void *g_archive_user = NULL;

const char *SDLStatic_GraphicsConfigPath(void)
{
    return (g_config_path[0] != '\0') ? g_config_path : NULL;
}

const char *SDLStatic_GraphicsConfigError(void)
{
    return (g_config_error[0] != '\0') ? g_config_error : NULL;
}

void SDLStatic_GraphicsSetArchiveReader(SDLStatic_GraphicsReadFile reader, void *user)
{
    g_archive_reader = reader;
    g_archive_user = user;
}

/* --- small parsers shared by TOML and the command line ------------------- */

static bool ParseBool(const char *text, bool *out)
{
    if (text == NULL || out == NULL)
    {
        return false;
    }
    if (SDL_strcasecmp(text, "on") == 0 || SDL_strcasecmp(text, "true") == 0 ||
        SDL_strcasecmp(text, "yes") == 0 || SDL_strcmp(text, "1") == 0)
    {
        *out = true;
        return true;
    }
    if (SDL_strcasecmp(text, "off") == 0 || SDL_strcasecmp(text, "false") == 0 ||
        SDL_strcasecmp(text, "no") == 0 || SDL_strcmp(text, "0") == 0)
    {
        *out = false;
        return true;
    }
    return false;
}

static bool ParseWindowMode(const char *text, SDLStatic_WindowMode *out)
{
    if (text == NULL || out == NULL)
    {
        return false;
    }
    if (SDL_strcasecmp(text, "windowed") == 0 || SDL_strcasecmp(text, "window") == 0)
    {
        *out = SDLSTATIC_WINDOW_WINDOWED;
        return true;
    }
    if (SDL_strcasecmp(text, "borderless") == 0 || SDL_strcasecmp(text, "fullscreen") == 0 ||
        SDL_strcasecmp(text, "desktop") == 0)
    {
        *out = SDLSTATIC_WINDOW_BORDERLESS;
        return true;
    }
    if (SDL_strcasecmp(text, "exclusive") == 0)
    {
        *out = SDLSTATIC_WINDOW_EXCLUSIVE;
        return true;
    }
    return false;
}

static bool ParsePresentation(const char *text, SDLStatic_EnginePresentation *out)
{
    static const struct
    {
        const char *name;
        SDLStatic_EnginePresentation mode;
    } kModes[] = {{"letterbox", SDLSTATIC_PRESENT_LETTERBOX},
                  {"expand", SDLSTATIC_PRESENT_EXPAND},
                  {"overscan", SDLSTATIC_PRESENT_OVERSCAN},
                  {"integer", SDLSTATIC_PRESENT_INTEGER},
                  {"stretch", SDLSTATIC_PRESENT_STRETCH},
                  {"native", SDLSTATIC_PRESENT_NATIVE}};
    if (text == NULL || out == NULL)
    {
        return false;
    }
    for (size_t i = 0; i < SDL_arraysize(kModes); ++i)
    {
        if (SDL_strcasecmp(text, kModes[i].name) == 0)
        {
            *out = kModes[i].mode;
            return true;
        }
    }
    return false;
}

static const char *PresentationName(SDLStatic_EnginePresentation mode)
{
    switch (mode)
    {
    case SDLSTATIC_PRESENT_EXPAND:
        return "expand";
    case SDLSTATIC_PRESENT_OVERSCAN:
        return "overscan";
    case SDLSTATIC_PRESENT_INTEGER:
        return "integer";
    case SDLSTATIC_PRESENT_STRETCH:
        return "stretch";
    case SDLSTATIC_PRESENT_NATIVE:
        return "native";
    case SDLSTATIC_PRESENT_LETTERBOX:
    default:
        return "letterbox";
    }
}

static const char *WindowModeName(SDLStatic_WindowMode mode)
{
    switch (mode)
    {
    case SDLSTATIC_WINDOW_BORDERLESS:
        return "borderless";
    case SDLSTATIC_WINDOW_EXCLUSIVE:
        return "exclusive";
    case SDLSTATIC_WINDOW_WINDOWED:
    default:
        return "windowed";
    }
}

static bool ParseFilter(const char *text, SDLStatic_TextureFilter *out)
{
    if (text == NULL || out == NULL)
    {
        return false;
    }
    if (SDL_strcasecmp(text, "auto") == 0)
    {
        *out = SDLSTATIC_FILTER_AUTO;
        return true;
    }
    if (SDL_strcasecmp(text, "linear") == 0 || SDL_strcasecmp(text, "smooth") == 0)
    {
        *out = SDLSTATIC_FILTER_LINEAR;
        return true;
    }
    if (SDL_strcasecmp(text, "nearest") == 0 || SDL_strcasecmp(text, "point") == 0 ||
        SDL_strcasecmp(text, "pixel") == 0)
    {
        *out = SDLSTATIC_FILTER_NEAREST;
        return true;
    }
    return false;
}

static const char *FilterName(SDLStatic_TextureFilter filter)
{
    switch (filter)
    {
    case SDLSTATIC_FILTER_LINEAR:
        return "linear";
    case SDLSTATIC_FILTER_NEAREST:
        return "nearest";
    case SDLSTATIC_FILTER_AUTO:
    default:
        return "auto";
    }
}

static bool ParseAA(const char *text, SDLStatic_GraphicsAA *out)
{
    if (text == NULL || out == NULL)
    {
        return false;
    }
    if (SDL_strcasecmp(text, "off") == 0 || SDL_strcasecmp(text, "none") == 0)
    {
        *out = SDLSTATIC_AA_OFF;
        return true;
    }
    if (SDL_strcasecmp(text, "fxaa") == 0 || SDL_strcasecmp(text, "on") == 0)
    {
        *out = SDLSTATIC_AA_FXAA;
        return true;
    }
    return false;
}

static bool ParseColorBlind(const char *text, SDLStatic_ColorBlindMode *out)
{
    static const struct
    {
        const char *name;
        SDLStatic_ColorBlindMode mode;
    } kModes[] = {{"none", SDLSTATIC_COLORBLIND_NONE},
                  {"off", SDLSTATIC_COLORBLIND_NONE},
                  {"protanopia", SDLSTATIC_COLORBLIND_PROTANOPIA},
                  {"deuteranopia", SDLSTATIC_COLORBLIND_DEUTERANOPIA},
                  {"tritanopia", SDLSTATIC_COLORBLIND_TRITANOPIA}};
    if (text == NULL || out == NULL)
    {
        return false;
    }
    for (size_t i = 0; i < SDL_arraysize(kModes); ++i)
    {
        if (SDL_strcasecmp(text, kModes[i].name) == 0)
        {
            *out = kModes[i].mode;
            return true;
        }
    }
    return false;
}

static const char *ColorBlindName(SDLStatic_ColorBlindMode mode)
{
    switch (mode)
    {
    case SDLSTATIC_COLORBLIND_PROTANOPIA:
        return "protanopia";
    case SDLSTATIC_COLORBLIND_DEUTERANOPIA:
        return "deuteranopia";
    case SDLSTATIC_COLORBLIND_TRITANOPIA:
        return "tritanopia";
    case SDLSTATIC_COLORBLIND_NONE:
    default:
        return "none";
    }
}

/* --- TOML ---------------------------------------------------------------- */

/* Look a key up in `section`, falling back to the document root. A config
   file is a thing humans edit; accepting `vsync = false` at the top level as
   well as under [display] costs one line here and saves an support email. */
static const toml_table_t *SectionOr(const toml_table_t *root, const char *name)
{
    const toml_table_t *table = toml_table_in(root, name);
    return (table != NULL) ? table : root;
}

static void ReadBool(const toml_table_t *table, const toml_table_t *root, const char *key,
                     bool *out)
{
    toml_datum_t d = toml_bool_in(table, key);
    if (!d.ok && table != root)
    {
        d = toml_bool_in(root, key);
    }
    if (d.ok)
    {
        *out = d.u.b != 0;
        return;
    }
    /* Also accept the string spellings, so "on"/"off" works in a file the
       same way it works on the command line. */
    toml_datum_t s = toml_string_in(table, key);
    if (!s.ok && table != root)
    {
        s = toml_string_in(root, key);
    }
    if (s.ok)
    {
        ParseBool(s.u.s, out);
        free(s.u.s);
    }
}

static void ReadInt(const toml_table_t *table, const toml_table_t *root, const char *key, int *out)
{
    toml_datum_t d = toml_int_in(table, key);
    if (!d.ok && table != root)
    {
        d = toml_int_in(root, key);
    }
    if (d.ok)
    {
        *out = (int)d.u.i;
    }
}

static void ReadFloat(const toml_table_t *table, const toml_table_t *root, const char *key,
                      float *out)
{
    toml_datum_t d = toml_double_in(table, key);
    if (!d.ok && table != root)
    {
        d = toml_double_in(root, key);
    }
    if (d.ok)
    {
        *out = (float)d.u.d;
        return;
    }
    /* `bloom = 1` is an integer in TOML but obviously means 1.0. */
    toml_datum_t i = toml_int_in(table, key);
    if (!i.ok && table != root)
    {
        i = toml_int_in(root, key);
    }
    if (i.ok)
    {
        *out = (float)i.u.i;
    }
}

/* Reads a string key and hands it to a parser. Returns quietly when the key
   is absent — every key in a config file is optional. */
static void ReadEnum(const toml_table_t *table, const toml_table_t *root, const char *key,
                     bool (*parse)(const char *, void *), void *out)
{
    toml_datum_t d = toml_string_in(table, key);
    if (!d.ok && table != root)
    {
        d = toml_string_in(root, key);
    }
    if (d.ok)
    {
        parse(d.u.s, out);
        free(d.u.s);
    }
}

/* Trampolines, because the parsers are typed and ReadEnum is not. */
static bool ParseQualityV(const char *t, void *out)
{
    return SDLStatic_GraphicsQualityFromName(t, (SDLStatic_GraphicsQuality *)out);
}
static bool ParseWindowModeV(const char *t, void *out)
{
    return ParseWindowMode(t, (SDLStatic_WindowMode *)out);
}
static bool ParsePresentationV(const char *t, void *out)
{
    return ParsePresentation(t, (SDLStatic_EnginePresentation *)out);
}
static bool ParseFilterV(const char *t, void *out)
{
    return ParseFilter(t, (SDLStatic_TextureFilter *)out);
}
static bool ParseAAV(const char *t, void *out)
{
    return ParseAA(t, (SDLStatic_GraphicsAA *)out);
}
static bool ParseColorBlindV(const char *t, void *out)
{
    return ParseColorBlind(t, (SDLStatic_ColorBlindMode *)out);
}

bool SDLStatic_GraphicsLoadTomlString(SDLStatic_GraphicsSettings *s, const char *text)
{
    if (s == NULL || text == NULL)
    {
        SDL_InvalidParamError("settings/toml");
        return false;
    }

    /* tomlc99 parses in place, so it needs its own mutable copy. */
    char *copy = SDL_strdup(text);
    if (copy == NULL)
    {
        return false;
    }
    char err[256] = {0};
    toml_table_t *root = toml_parse(copy, err, (int)sizeof(err));
    SDL_free(copy);
    if (root == NULL)
    {
        SDL_strlcpy(g_config_error, err[0] ? err : "could not parse TOML",
                    sizeof(g_config_error));
        SDL_SetError("config.toml: %s", g_config_error);
        return false;
    }

    const toml_table_t *display = SectionOr(root, "display");
    ReadBool(display, root, "vsync", &s->vsync);
    ReadInt(display, root, "max_fps", &s->max_fps);
    ReadEnum(display, root, "window_mode", ParseWindowModeV, &s->window_mode);
    ReadInt(display, root, "window_width", &s->window_width);
    ReadInt(display, root, "window_height", &s->window_height);
    ReadInt(display, root, "display", &s->display);
    ReadEnum(display, root, "presentation", ParsePresentationV, &s->presentation);
    ReadFloat(display, root, "render_scale", &s->render_scale);
    ReadEnum(display, root, "filter", ParseFilterV, &s->filter);

    const toml_table_t *quality = SectionOr(root, "quality");
    ReadEnum(quality, root, "particles", ParseQualityV, &s->particles);
    ReadEnum(quality, root, "dynamic_lights", ParseQualityV, &s->dynamic_lights);
    ReadEnum(quality, root, "shadows", ParseQualityV, &s->shadows);

    const toml_table_t *effects = SectionOr(root, "effects");
    ReadFloat(effects, root, "bloom", &s->bloom);
    ReadFloat(effects, root, "bloom_threshold", &s->bloom_threshold);
    ReadFloat(effects, root, "crt", &s->crt);
    ReadFloat(effects, root, "crt_curvature", &s->crt_curvature);
    ReadInt(effects, root, "pixelation", &s->pixelation);
    ReadFloat(effects, root, "chromatic_aberration", &s->chromatic_aberration);
    ReadEnum(effects, root, "antialias", ParseAAV, &s->antialias);

    const toml_table_t *image = SectionOr(root, "image");
    ReadFloat(image, root, "brightness", &s->brightness);
    ReadFloat(image, root, "contrast", &s->contrast);
    ReadFloat(image, root, "saturation", &s->saturation);
    ReadEnum(image, root, "color_blind", ParseColorBlindV, &s->color_blind);

    const toml_table_t *access = SectionOr(root, "accessibility");
    ReadBool(access, root, "reduced_flashing", &s->reduced_flashing);
    ReadFloat(access, root, "screen_shake", &s->screen_shake);
    ReadFloat(access, root, "ui_scale", &s->ui_scale);

    toml_free(root);
    SDLStatic_GraphicsClamp(s);
    return true;
}

bool SDLStatic_GraphicsLoadTomlFile(SDLStatic_GraphicsSettings *s, const char *path)
{
    if (s == NULL || path == NULL)
    {
        SDL_InvalidParamError("settings/path");
        return false;
    }
    size_t size = 0;
    void *data = SDL_LoadFile(path, &size);
    if (data == NULL)
    {
        return false;
    }
    /* SDL_LoadFile NUL-terminates, which is what toml_parse needs. */
    const bool ok = SDLStatic_GraphicsLoadTomlString(s, (const char *)data);
    SDL_free(data);
    return ok;
}

/* --- the command line ---------------------------------------------------- */

/* Accepts --key=value and --key value, and treats a bare boolean flag as
   "on". Returns the value, or NULL for a bare flag, and advances *i past
   whatever it consumed. */
static const char *ArgValue(const char *arg, const char *key, int argc, char *const *argv, int *i,
                            bool *matched)
{
    const size_t klen = SDL_strlen(key);
    *matched = false;
    if (SDL_strncmp(arg, key, klen) != 0)
    {
        return NULL;
    }
    if (arg[klen] == '=')
    {
        *matched = true;
        return arg + klen + 1;
    }
    if (arg[klen] != '\0')
    {
        return NULL; /* --bloomier is not --bloom */
    }
    *matched = true;
    if (*i + 1 < argc && argv[*i + 1][0] != '-')
    {
        *i += 1;
        return argv[*i];
    }
    return NULL;
}

const char *SDLStatic_GraphicsArgsConfigPath(int argc, char *const *argv)
{
    if (argv == NULL)
    {
        return NULL;
    }
    for (int i = 1; i < argc; ++i)
    {
        bool matched = false;
        const char *value = ArgValue(argv[i], "--config", argc, argv, &i, &matched);
        if (matched && value != NULL)
        {
            return value;
        }
    }
    return NULL;
}

int SDLStatic_GraphicsLoadArgs(SDLStatic_GraphicsSettings *s, int argc, char *const *argv)
{
    if (s == NULL || argv == NULL)
    {
        return 0;
    }
    int changed = 0;

    /* The escape hatches go first and replace the whole struct, so
       `--with-safe-mode --bloom=0.5` means safe mode with bloom rather than
       depending on which order they were typed in. */
    for (int i = 1; i < argc; ++i)
    {
        if (SDL_strcmp(argv[i], "--with-safe-mode") == 0)
        {
            *s = SDLStatic_GraphicsSafeMode();
            changed++;
        }
        else if (SDL_strcmp(argv[i], "--with-default-settings") == 0)
        {
            *s = SDLStatic_GraphicsDefaults();
            changed++;
        }
    }

    for (int i = 1; i < argc; ++i)
    {
        const char *arg = argv[i];
        bool matched = false;
        const char *value = NULL;

/* Each of these consumes at most one following argument. The macro keeps
   the table readable: the alternative is forty near-identical if-blocks. */
#define OPT(key) ((value = ArgValue(arg, key, argc, argv, &i, &matched)), matched)

        if (OPT("--vsync"))
        {
            /* Bare --vsync means on; --vsync=off is the explicit form. */
            bool v = true;
            if (value == NULL || ParseBool(value, &v))
            {
                s->vsync = v;
                changed++;
            }
        }
        else if (OPT("--no-vsync"))
        {
            s->vsync = false;
            changed++;
        }
        else if (OPT("--max-fps") && value != NULL)
        {
            s->max_fps = SDL_atoi(value);
            changed++;
        }
        else if (OPT("--fullscreen"))
        {
            s->window_mode = SDLSTATIC_WINDOW_BORDERLESS;
            if (value != NULL)
            {
                ParseWindowMode(value, &s->window_mode);
            }
            changed++;
        }
        else if (OPT("--windowed"))
        {
            s->window_mode = SDLSTATIC_WINDOW_WINDOWED;
            changed++;
        }
        else if (OPT("--display") && value != NULL)
        {
            s->display = SDL_atoi(value);
            changed++;
        }
        else if (OPT("--window-size") && value != NULL)
        {
            /* WxH, the spelling every game with a launcher already uses. */
            int w = 0;
            int h = 0;
            if (SDL_sscanf(value, "%dx%d", &w, &h) == 2 && w > 0 && h > 0)
            {
                s->window_width = w;
                s->window_height = h;
                s->window_mode = SDLSTATIC_WINDOW_WINDOWED;
                changed++;
            }
        }
        else if (OPT("--window-mode") && value != NULL)
        {
            changed += ParseWindowMode(value, &s->window_mode) ? 1 : 0;
        }
        else if (OPT("--presentation") && value != NULL)
        {
            changed += ParsePresentation(value, &s->presentation) ? 1 : 0;
        }
        else if (OPT("--render-scale") && value != NULL)
        {
            s->render_scale = (float)SDL_atof(value);
            changed++;
        }
        else if (OPT("--filter") && value != NULL)
        {
            changed += ParseFilter(value, &s->filter) ? 1 : 0;
        }
        else if (OPT("--particles") && value != NULL)
        {
            changed += SDLStatic_GraphicsQualityFromName(value, &s->particles) ? 1 : 0;
        }
        else if (OPT("--lights") && value != NULL)
        {
            changed += SDLStatic_GraphicsQualityFromName(value, &s->dynamic_lights) ? 1 : 0;
        }
        else if (OPT("--shadows") && value != NULL)
        {
            changed += SDLStatic_GraphicsQualityFromName(value, &s->shadows) ? 1 : 0;
        }
        else if (OPT("--bloom") && value != NULL)
        {
            s->bloom = (float)SDL_atof(value);
            changed++;
        }
        else if (OPT("--bloom-threshold") && value != NULL)
        {
            s->bloom_threshold = (float)SDL_atof(value);
            changed++;
        }
        else if (OPT("--crt") && value != NULL)
        {
            s->crt = (float)SDL_atof(value);
            changed++;
        }
        else if (OPT("--crt-curvature") && value != NULL)
        {
            s->crt_curvature = (float)SDL_atof(value);
            changed++;
        }
        else if (OPT("--pixelation") && value != NULL)
        {
            s->pixelation = SDL_atoi(value);
            changed++;
        }
        else if (OPT("--chromatic-aberration") && value != NULL)
        {
            s->chromatic_aberration = (float)SDL_atof(value);
            changed++;
        }
        else if (OPT("--antialias") && value != NULL)
        {
            changed += ParseAA(value, &s->antialias) ? 1 : 0;
        }
        else if (OPT("--brightness") && value != NULL)
        {
            s->brightness = (float)SDL_atof(value);
            changed++;
        }
        else if (OPT("--contrast") && value != NULL)
        {
            s->contrast = (float)SDL_atof(value);
            changed++;
        }
        else if (OPT("--saturation") && value != NULL)
        {
            s->saturation = (float)SDL_atof(value);
            changed++;
        }
        else if (OPT("--color-blind") && value != NULL)
        {
            changed += ParseColorBlind(value, &s->color_blind) ? 1 : 0;
        }
        else if (OPT("--reduced-flashing"))
        {
            bool v = true;
            if (value == NULL || ParseBool(value, &v))
            {
                s->reduced_flashing = v;
                changed++;
            }
        }
        else if (OPT("--screen-shake") && value != NULL)
        {
            s->screen_shake = (float)SDL_atof(value);
            changed++;
        }
        else if (OPT("--ui-scale") && value != NULL)
        {
            s->ui_scale = (float)SDL_atof(value);
            changed++;
        }
        /* --config is handled by Resolve, and anything else belongs to the
           game: the engine is a guest on this command line. */
#undef OPT
    }

    if (changed > 0)
    {
        SDLStatic_GraphicsClamp(s);
    }
    return changed;
}

/* --- pref directory ------------------------------------------------------ */

/* SDL_GetPrefPath is the same per-user, per-application directory PhysFS
   calls the pref dir, created if it does not exist — one platform's
   ~/.local/share, another's %APPDATA%. Using SDL's keeps the engine free of
   a PhysFS dependency for what is a one-line lookup. */
static char *PrefConfigPath(const char *org, const char *app, bool create_media_dir)
{
    if (app == NULL || app[0] == '\0')
    {
        return NULL;
    }
    char *base = SDL_GetPrefPath(org, app);
    if (base == NULL)
    {
        return NULL;
    }
    /* <pref>/media/config.toml — the media directory rather than the root,
       so a game's writable state has the same shape as its read-only
       archive. */
    const size_t need = SDL_strlen(base) + SDL_strlen("media/config.toml") + 1;
    char *path = (char *)SDL_malloc(need);
    if (path == NULL)
    {
        SDL_free(base);
        return NULL;
    }
    SDL_snprintf(path, need, "%smedia/config.toml", base);

    if (create_media_dir)
    {
        const size_t dir_need = SDL_strlen(base) + SDL_strlen("media") + 1;
        char *dir = (char *)SDL_malloc(dir_need);
        if (dir != NULL)
        {
            SDL_snprintf(dir, dir_need, "%smedia", base);
            SDL_CreateDirectory(dir);
            SDL_free(dir);
        }
    }
    SDL_free(base);
    return path;
}

char *SDLStatic_GraphicsSavePath(const char *org, const char *app)
{
    return PrefConfigPath(org, app, false);
}

/* --- resolve ------------------------------------------------------------- */

static void NoteSource(const char *path)
{
    SDL_strlcpy(g_config_path, (path != NULL) ? path : "", sizeof(g_config_path));
}

void SDLStatic_GraphicsResolve(SDLStatic_GraphicsSettings *out, int argc, char *const *argv,
                               const char *org, const char *app)
{
    if (out == NULL)
    {
        return;
    }
    *out = SDLStatic_GraphicsDefaults();
    g_config_path[0] = '\0';
    g_config_error[0] = '\0';

    /* The escape hatches skip every config file. That is the whole point:
       they have to work when the saved settings are what is broken, so
       reading those settings first would defeat them. */
    for (int i = 1; i < argc && argv != NULL; ++i)
    {
        if (SDL_strcmp(argv[i], "--with-safe-mode") == 0 ||
            SDL_strcmp(argv[i], "--with-default-settings") == 0)
        {
            SDLStatic_GraphicsLoadArgs(out, argc, argv);
            return;
        }
    }

    /* An explicit --config replaces the search entirely. Someone passing a
       path wants that file, not that file plus three others. */
    const char *explicit_path = SDLStatic_GraphicsArgsConfigPath(argc, argv);
    if (explicit_path != NULL)
    {
        if (SDLStatic_GraphicsLoadTomlFile(out, explicit_path))
        {
            NoteSource(explicit_path);
        }
        else if (g_config_error[0] == '\0')
        {
            SDL_snprintf(g_config_error, sizeof(g_config_error), "could not read %s",
                         explicit_path);
        }
        SDLStatic_GraphicsLoadArgs(out, argc, argv);
        return;
    }

    /* Lowest authority first: what the game shipped inside its media
       archive, read through whatever the game mounted it with. */
    if (g_archive_reader != NULL)
    {
        static const char *kArchivePaths[] = {"media/config.toml", "config.toml"};
        for (size_t i = 0; i < SDL_arraysize(kArchivePaths); ++i)
        {
            char *text = NULL;
            if (g_archive_reader(kArchivePaths[i], &text, g_archive_user) && text != NULL)
            {
                if (SDLStatic_GraphicsLoadTomlString(out, text))
                {
                    NoteSource(kArchivePaths[i]);
                }
                SDL_free(text);
                break;
            }
        }
    }

    /* Then the copy beside the game — an installer's or a server's. */
    if (SDLStatic_GraphicsLoadTomlFile(out, "media/config.toml"))
    {
        NoteSource("media/config.toml");
    }

    /* Then the player's own, which is the one they edited on purpose. */
    char *pref = PrefConfigPath(org, app, false);
    if (pref != NULL)
    {
        if (SDLStatic_GraphicsLoadTomlFile(out, pref))
        {
            NoteSource(pref);
        }
        SDL_free(pref);
    }

    SDLStatic_GraphicsLoadArgs(out, argc, argv);
}

/* --- writing back -------------------------------------------------------- */

char *SDLStatic_GraphicsToToml(const SDLStatic_GraphicsSettings *s)
{
    if (s == NULL)
    {
        SDL_InvalidParamError("settings");
        return NULL;
    }
    /* Comments and section order are deliberate: this file is meant to be
       opened and edited by a person who has never seen the engine. */
    char *text = NULL;
    SDL_asprintf(&text,
                 "# Graphics settings. Written by the game; safe to edit by hand.\n"
                 "# Anything invalid is clamped or ignored, never fatal.\n"
                 "\n"
                 "[display]\n"
                 "vsync = %s\n"
                 "max_fps = %d          # 0 follows the display, negative uncaps\n"
                 "window_mode = \"%s\"   # windowed | borderless | exclusive\n"
                 "window_width = %d     # windowed size; 0 for the default\n"
                 "window_height = %d\n"
                 "display = %d           # 0-based monitor index\n"
                 "presentation = \"%s\"  # letterbox | expand | overscan | integer | "
                 "stretch | native\n"
                 "render_scale = %.3f    # 0.25-2.0; below 1.0 trades sharpness for speed\n"
                 "filter = \"%s\"         # auto | linear | nearest\n"
                 "\n"
                 "[quality]\n"
                 "particles = \"%s\"\n"
                 "dynamic_lights = \"%s\"\n"
                 "shadows = \"%s\"\n"
                 "\n"
                 "[effects]\n"
                 "bloom = %.3f\n"
                 "bloom_threshold = %.3f\n"
                 "crt = %.3f\n"
                 "crt_curvature = %.3f\n"
                 "pixelation = %d        # 1 is off\n"
                 "chromatic_aberration = %.3f\n"
                 "antialias = \"%s\"      # off | fxaa\n"
                 "\n"
                 "[image]\n"
                 "brightness = %.3f\n"
                 "contrast = %.3f\n"
                 "saturation = %.3f\n"
                 "color_blind = \"%s\"    # none | protanopia | deuteranopia | tritanopia\n"
                 "\n"
                 "[accessibility]\n"
                 "reduced_flashing = %s\n"
                 "screen_shake = %.3f\n"
                 "ui_scale = %.3f\n",
                 s->vsync ? "true" : "false", s->max_fps, WindowModeName(s->window_mode),
                 s->window_width, s->window_height, s->display,
                 PresentationName(s->presentation), (double)s->render_scale,
                 FilterName(s->filter), SDLStatic_GraphicsQualityName(s->particles),
                 SDLStatic_GraphicsQualityName(s->dynamic_lights),
                 SDLStatic_GraphicsQualityName(s->shadows), (double)s->bloom,
                 (double)s->bloom_threshold, (double)s->crt, (double)s->crt_curvature,
                 s->pixelation, (double)s->chromatic_aberration,
                 (s->antialias == SDLSTATIC_AA_FXAA) ? "fxaa" : "off", (double)s->brightness,
                 (double)s->contrast, (double)s->saturation, ColorBlindName(s->color_blind),
                 s->reduced_flashing ? "true" : "false", (double)s->screen_shake,
                 (double)s->ui_scale);
    return text;
}

bool SDLStatic_GraphicsSave(const SDLStatic_GraphicsSettings *s, const char *org, const char *app)
{
    if (s == NULL)
    {
        SDL_InvalidParamError("settings");
        return false;
    }
    char *path = PrefConfigPath(org, app, true);
    if (path == NULL)
    {
        SDL_SetError("no pref directory for %s/%s", org ? org : "(null)", app ? app : "(null)");
        return false;
    }
    char *text = SDLStatic_GraphicsToToml(s);
    if (text == NULL)
    {
        SDL_free(path);
        return false;
    }
    const bool ok = SDL_SaveFile(path, text, SDL_strlen(text));
    SDL_free(text);
    SDL_free(path);
    return ok;
}
