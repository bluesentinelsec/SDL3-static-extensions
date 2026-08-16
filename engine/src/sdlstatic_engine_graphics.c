/*
 * sdlstatic_engine_graphics.c — the graphics settings themselves.
 * Original SDLStatic code (zlib).
 *
 * Defaults, validation, the quality-to-numbers helpers, and applying a
 * settings struct to a running engine. Loading and saving live next door in
 * sdlstatic_engine_gfxconfig.c; the post-processing shaders in
 * sdlstatic_engine_postfx.c. Split that way because this file is the part
 * with no dependencies — it is pure data handling, and it is what the tests
 * spend most of their time on.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_graphics.h>

/* --- defaults ------------------------------------------------------------ */

SDLStatic_GraphicsSettings SDLStatic_GraphicsDefaults(void)
{
    SDLStatic_GraphicsSettings s;
    SDL_zero(s);

    s.vsync = true;
    s.max_fps = 0; /* follow the display */
    s.window_mode = SDLSTATIC_WINDOW_WINDOWED;
    s.presentation = SDLSTATIC_PRESENT_LETTERBOX;
    s.render_scale = 1.0f;
    s.filter = SDLSTATIC_FILTER_AUTO;

    /* Budgets start high. A game should look like itself until something
       says otherwise; the tiers exist for players who need them. */
    s.particles = SDLSTATIC_QUALITY_HIGH;
    s.dynamic_lights = SDLSTATIC_QUALITY_HIGH;
    s.shadows = SDLSTATIC_QUALITY_HIGH;

    /* Everything stylistic starts off. Bloom and CRT are decisions about
       how a game looks, and the engine does not get to make them. */
    s.bloom = 0.0f;
    s.bloom_threshold = 0.7f;
    s.crt = 0.0f;
    s.crt_curvature = 0.0f;
    s.pixelation = 1;
    s.chromatic_aberration = 0.0f;
    s.antialias = SDLSTATIC_AA_OFF;

    s.brightness = 1.0f;
    s.contrast = 1.0f;
    s.saturation = 1.0f;
    s.color_blind = SDLSTATIC_COLORBLIND_NONE;
    s.reduced_flashing = false;
    s.screen_shake = 1.0f;
    s.ui_scale = 1.0f;

    return s;
}

static float ClampF(float v, float lo, float hi)
{
    if (!(v == v)) /* NaN: a hand-written config can contain one */
    {
        return lo;
    }
    return (v < lo) ? lo : ((v > hi) ? hi : v);
}

static int ClampI(int v, int lo, int hi)
{
    return (v < lo) ? lo : ((v > hi) ? hi : v);
}

static SDLStatic_GraphicsQuality ClampQuality(SDLStatic_GraphicsQuality q)
{
    if ((int)q < (int)SDLSTATIC_QUALITY_OFF)
    {
        return SDLSTATIC_QUALITY_OFF;
    }
    if ((int)q > (int)SDLSTATIC_QUALITY_HIGH)
    {
        return SDLSTATIC_QUALITY_HIGH;
    }
    return q;
}

void SDLStatic_GraphicsClamp(SDLStatic_GraphicsSettings *s)
{
    if (s == NULL)
    {
        return;
    }

    if ((int)s->window_mode < 0 || (int)s->window_mode > (int)SDLSTATIC_WINDOW_EXCLUSIVE)
    {
        s->window_mode = SDLSTATIC_WINDOW_WINDOWED;
    }
    if ((int)s->presentation < 0 || (int)s->presentation > (int)SDLSTATIC_PRESENT_NATIVE)
    {
        s->presentation = SDLSTATIC_PRESENT_LETTERBOX;
    }
    if ((int)s->filter < 0 || (int)s->filter > (int)SDLSTATIC_FILTER_NEAREST)
    {
        s->filter = SDLSTATIC_FILTER_AUTO;
    }
    if ((int)s->antialias < 0 || (int)s->antialias > (int)SDLSTATIC_AA_FXAA)
    {
        s->antialias = SDLSTATIC_AA_OFF;
    }
    if ((int)s->color_blind < 0 || (int)s->color_blind > (int)SDLSTATIC_COLORBLIND_TRITANOPIA)
    {
        s->color_blind = SDLSTATIC_COLORBLIND_NONE;
    }

    /* A frame cap below 10 is a mistake, not a preference — it would make a
       game unplayable and look like a hang. Negative stays negative: that is
       the documented "no limiter". */
    if (s->max_fps > 0)
    {
        s->max_fps = ClampI(s->max_fps, 10, 1000);
    }

    s->render_scale = ClampF(s->render_scale, 0.25f, 2.0f);
    s->particles = ClampQuality(s->particles);
    s->dynamic_lights = ClampQuality(s->dynamic_lights);
    s->shadows = ClampQuality(s->shadows);

    s->bloom = ClampF(s->bloom, 0.0f, 1.0f);
    s->bloom_threshold = ClampF(s->bloom_threshold, 0.0f, 1.0f);
    s->crt = ClampF(s->crt, 0.0f, 1.0f);
    s->crt_curvature = ClampF(s->crt_curvature, 0.0f, 1.0f);
    s->pixelation = ClampI(s->pixelation, 1, 64);
    s->chromatic_aberration = ClampF(s->chromatic_aberration, 0.0f, 1.0f);

    s->brightness = ClampF(s->brightness, 0.5f, 2.0f);
    s->contrast = ClampF(s->contrast, 0.5f, 2.0f);
    s->saturation = ClampF(s->saturation, 0.0f, 2.0f);
    s->screen_shake = ClampF(s->screen_shake, 0.0f, 1.0f);
    s->ui_scale = ClampF(s->ui_scale, 0.5f, 3.0f);

    /* Photosensitivity is a safety setting, so it overrides the aesthetic
       ones rather than sitting beside them: bloom is what turns a bright
       frame into a flash. */
    if (s->reduced_flashing)
    {
        s->bloom = ClampF(s->bloom, 0.0f, 0.25f);
    }
}

bool SDLStatic_GraphicsEqual(const SDLStatic_GraphicsSettings *a,
                             const SDLStatic_GraphicsSettings *b)
{
    if (a == NULL || b == NULL)
    {
        return a == b;
    }
    /* Field by field rather than memcmp: the struct has padding, and two
       structs that differ only in padding are the same settings. */
    return a->vsync == b->vsync && a->max_fps == b->max_fps &&
           a->window_mode == b->window_mode && a->presentation == b->presentation &&
           a->render_scale == b->render_scale && a->filter == b->filter &&
           a->particles == b->particles && a->dynamic_lights == b->dynamic_lights &&
           a->shadows == b->shadows && a->bloom == b->bloom &&
           a->bloom_threshold == b->bloom_threshold && a->crt == b->crt &&
           a->crt_curvature == b->crt_curvature && a->pixelation == b->pixelation &&
           a->chromatic_aberration == b->chromatic_aberration && a->antialias == b->antialias &&
           a->brightness == b->brightness && a->contrast == b->contrast &&
           a->saturation == b->saturation && a->color_blind == b->color_blind &&
           a->reduced_flashing == b->reduced_flashing && a->screen_shake == b->screen_shake &&
           a->ui_scale == b->ui_scale;
}

/* --- budgets, turned into numbers ---------------------------------------- */

float SDLStatic_GraphicsParticleDensity(SDLStatic_GraphicsQuality quality)
{
    switch (ClampQuality(quality))
    {
    case SDLSTATIC_QUALITY_OFF:
        return 0.0f;
    case SDLSTATIC_QUALITY_LOW:
        return 0.25f;
    case SDLSTATIC_QUALITY_MEDIUM:
        return 0.6f;
    case SDLSTATIC_QUALITY_HIGH:
    default:
        return 1.0f;
    }
}

float SDLStatic_GraphicsLightMapScale(SDLStatic_GraphicsQuality quality)
{
    switch (ClampQuality(quality))
    {
    /* Even "off" returns a usable scale: turning dynamic lights off means
       drawing no lights, not rendering the light map at zero pixels. */
    case SDLSTATIC_QUALITY_OFF:
    case SDLSTATIC_QUALITY_LOW:
        return 0.5f;
    case SDLSTATIC_QUALITY_MEDIUM:
        return 0.75f;
    case SDLSTATIC_QUALITY_HIGH:
    default:
        return 1.0f;
    }
}

int SDLStatic_GraphicsMaxDynamicLights(SDLStatic_GraphicsQuality quality)
{
    switch (ClampQuality(quality))
    {
    case SDLSTATIC_QUALITY_OFF:
        return 0;
    case SDLSTATIC_QUALITY_LOW:
        return 8;
    case SDLSTATIC_QUALITY_MEDIUM:
        return 24;
    case SDLSTATIC_QUALITY_HIGH:
    default:
        return 64;
    }
}

int SDLStatic_GraphicsShadowRays(SDLStatic_GraphicsQuality quality)
{
    switch (ClampQuality(quality))
    {
    case SDLSTATIC_QUALITY_OFF:
        return 0;
    case SDLSTATIC_QUALITY_LOW:
        return 32;
    case SDLSTATIC_QUALITY_MEDIUM:
        return 96;
    case SDLSTATIC_QUALITY_HIGH:
    default:
        return 256;
    }
}

float SDLStatic_GraphicsShadowSoftness(SDLStatic_GraphicsQuality quality)
{
    /* Soft edges need rays to be smooth. Below HIGH there are not enough,
       and a soft shadow built from 32 rays reads as banding — so the lower
       tiers get hard shadows, which look deliberate instead of broken. */
    return (ClampQuality(quality) >= SDLSTATIC_QUALITY_HIGH) ? 0.35f : 0.0f;
}

const char *SDLStatic_GraphicsQualityName(SDLStatic_GraphicsQuality quality)
{
    switch (ClampQuality(quality))
    {
    case SDLSTATIC_QUALITY_OFF:
        return "off";
    case SDLSTATIC_QUALITY_LOW:
        return "low";
    case SDLSTATIC_QUALITY_MEDIUM:
        return "medium";
    case SDLSTATIC_QUALITY_HIGH:
    default:
        return "high";
    }
}

bool SDLStatic_GraphicsQualityFromName(const char *name, SDLStatic_GraphicsQuality *out)
{
    if (name == NULL || out == NULL)
    {
        return false;
    }
    if (SDL_strcasecmp(name, "off") == 0 || SDL_strcasecmp(name, "none") == 0)
    {
        *out = SDLSTATIC_QUALITY_OFF;
        return true;
    }
    if (SDL_strcasecmp(name, "low") == 0)
    {
        *out = SDLSTATIC_QUALITY_LOW;
        return true;
    }
    if (SDL_strcasecmp(name, "medium") == 0 || SDL_strcasecmp(name, "med") == 0)
    {
        *out = SDLSTATIC_QUALITY_MEDIUM;
        return true;
    }
    if (SDL_strcasecmp(name, "high") == 0)
    {
        *out = SDLSTATIC_QUALITY_HIGH;
        return true;
    }
    return false;
}

/* --- applying to a running engine ---------------------------------------- */

const SDLStatic_GraphicsSettings *SDLStatic_EngineGraphics(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? &engine->graphics : NULL;
}

bool SDLStatic_EngineEffectsAvailable(SDLStatic_Engine *engine)
{
    return (engine != NULL) && SDLStatic_EnginePostFXAvailable(engine);
}

bool SDLStatic_EngineSetGraphics(SDLStatic_Engine *engine, const SDLStatic_GraphicsSettings *in)
{
    if (engine == NULL || in == NULL)
    {
        SDL_InvalidParamError("engine/settings");
        return false;
    }

    SDLStatic_GraphicsSettings next = *in;
    SDLStatic_GraphicsClamp(&next);

    const SDLStatic_GraphicsSettings previous = engine->graphics;
    engine->graphics = next;

    if (engine->renderer == NULL)
    {
        return true; /* settings-only engine: nothing to apply them to yet */
    }

    if (next.vsync != previous.vsync || engine->frame_count == 0)
    {
        SDL_SetRenderVSync(engine->renderer, next.vsync ? 1 : SDL_RENDERER_VSYNC_DISABLED);
    }

    engine->max_fps = next.max_fps;

    if (next.presentation != previous.presentation || engine->frame_count == 0)
    {
        SDLStatic_EngineSetPresentation(engine, next.presentation);
    }

    if (engine->window != NULL &&
        (next.window_mode != previous.window_mode || engine->frame_count == 0))
    {
        switch (next.window_mode)
        {
        case SDLSTATIC_WINDOW_BORDERLESS:
            /* A NULL display mode is what makes SDL's fullscreen the
               borderless-desktop kind rather than a mode switch. */
            SDL_SetWindowFullscreenMode(engine->window, NULL);
            SDL_SetWindowFullscreen(engine->window, true);
            break;
        case SDLSTATIC_WINDOW_EXCLUSIVE: {
            const SDL_DisplayID display = SDL_GetDisplayForWindow(engine->window);
            const SDL_DisplayMode *mode = SDL_GetDesktopDisplayMode(display);
            SDL_SetWindowFullscreenMode(engine->window, mode);
            SDL_SetWindowFullscreen(engine->window, true);
            break;
        }
        case SDLSTATIC_WINDOW_WINDOWED:
        default:
            SDL_SetWindowFullscreen(engine->window, false);
            break;
        }
    }

    SDLStatic_EngineApplyFilter(engine);
    SDLStatic_EnginePostFXInvalidate(engine);
    return true;
}

void SDLStatic_EngineApplyFilter(SDLStatic_Engine *engine)
{
    if (engine == NULL || engine->renderer == NULL)
    {
        return;
    }
    SDL_ScaleMode mode;
    switch (engine->graphics.filter)
    {
    case SDLSTATIC_FILTER_NEAREST:
        mode = SDL_SCALEMODE_NEAREST;
        break;
    case SDLSTATIC_FILTER_LINEAR:
        mode = SDL_SCALEMODE_LINEAR;
        break;
    case SDLSTATIC_FILTER_AUTO:
    default:
        /* Integer scaling exists for pixel art, and pixel art wants point
           sampling — so AUTO follows the presentation mode. */
        mode = (engine->presentation == SDLSTATIC_PRESENT_INTEGER) ? SDL_SCALEMODE_NEAREST
                                                                   : SDL_SCALEMODE_LINEAR;
        break;
    }
    SDL_SetDefaultTextureScaleMode(engine->renderer, mode);
}
