/*
 * sdlstatic_engine.c — the frame loop.
 * Original SDLStatic code (zlib). See SDLStatic/engine.h.
 *
 * The whole file is in service of one property: a steady motion should
 * advance by the same distance every time the display refreshes. Four
 * things are needed for that, and each is marked where it happens:
 *
 *   [1] clamp    a stall is not a slow frame; drop the time
 *   [2] smooth   snap the measured delta onto the display's cadence
 *   [3] step     advance the simulation in exact, equal steps
 *   [4] alpha    render *between* steps, so the display rate and the
 *                simulation rate need not agree
 */
#include <SDLStatic/engine.h>

#include "engine_internal.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

/* --- clock -------------------------------------------------------------- */

static Uint64 Now(const SDLStatic_Engine *engine)
{
    return engine->manual_clock ? engine->manual_ns : SDL_GetTicksNS();
}

void SDLStatic_EngineAdvance(SDLStatic_Engine *engine, Uint64 nanoseconds)
{
    if (engine != NULL && engine->manual_clock)
    {
        engine->manual_ns += nanoseconds;
    }
}

void SDLStatic_EngineSetRefreshRate(SDLStatic_Engine *engine, float hz)
{
    if (engine == NULL)
    {
        return;
    }
    engine->refresh_ns = (hz > 1.0f) ? (Uint64)((double)NS_PER_SECOND / (double)hz) : 0;
}

/* [2] Snap a measured frame time onto the display's cadence.
 *
 * This is the piece hand-rolled loops usually miss, and the one that
 * removes most visible judder. Frame times cluster around multiples of the
 * refresh period but never land on them exactly; the noise is measurement
 * and scheduling, not real variation in how much time the game should
 * advance. So if a delta is within a small tolerance of k refreshes, treat
 * it as exactly k refreshes.
 *
 * The tolerance is deliberately generous (15%) and the snap only applies to
 * whole multiples: a genuinely slow frame (say 1.6 refreshes) is left
 * alone, because that one really is late. */
static Uint64 SmoothDelta(const SDLStatic_Engine *engine, Uint64 raw)
{
    if (engine->refresh_ns == 0)
    {
        return raw;
    }
    const double periods = (double)raw / (double)engine->refresh_ns;
    const double nearest = SDL_round(periods);
    if (nearest >= 1.0 && SDL_fabs(periods - nearest) < 0.15)
    {
        return (Uint64)(nearest * (double)engine->refresh_ns);
    }
    return raw;
}

/* --- lifecycle ---------------------------------------------------------- */

static SDL_RendererLogicalPresentation PresentationMode(SDLStatic_EnginePresentation mode)
{
    switch (mode)
    {
    case SDLSTATIC_PRESENT_OVERSCAN:
        return SDL_LOGICAL_PRESENTATION_OVERSCAN;
    case SDLSTATIC_PRESENT_INTEGER:
        return SDL_LOGICAL_PRESENTATION_INTEGER_SCALE;
    case SDLSTATIC_PRESENT_STRETCH:
        return SDL_LOGICAL_PRESENTATION_STRETCH;
    case SDLSTATIC_PRESENT_NATIVE:
        return SDL_LOGICAL_PRESENTATION_DISABLED;
    case SDLSTATIC_PRESENT_EXPAND:
        /* EXPAND is letterbox with a logical size chosen to match the
           window's aspect exactly, so there is never anything to bar. */
        return SDL_LOGICAL_PRESENTATION_LETTERBOX;
    case SDLSTATIC_PRESENT_LETTERBOX:
    default:
        return SDL_LOGICAL_PRESENTATION_LETTERBOX;
    }
}

/* Work out the visible design rectangle and hand it to SDL.
 *
 * Called on creation and whenever the window's pixel size changes, because
 * in EXPAND the visible width follows the window's aspect ratio — that is
 * the whole point of the mode. */
static void ApplyPresentation(SDLStatic_Engine *engine)
{
    int pixel_w = 0;
    int pixel_h = 0;
    /* SDL_GetRenderOutputSize, not SDL_GetCurrentRenderOutputSize: the
       "current" size is the logical destination rectangle — the area we
       already fitted the design space into — so using it here would ask
       the window what shape we just made it, and EXPAND would never
       expand. This one is the framebuffer. */
    if (!SDL_GetRenderOutputSize(engine->renderer, &pixel_w, &pixel_h) || pixel_w <= 0 ||
        pixel_h <= 0)
    {
        return;
    }

    engine->view_width = (float)engine->design_width;
    engine->view_height = (float)engine->design_height;

    if (engine->presentation == SDLSTATIC_PRESENT_EXPAND)
    {
        const float design_aspect = (float)engine->design_width / (float)engine->design_height;
        const float window_aspect = (float)pixel_w / (float)pixel_h;
        if (window_aspect > design_aspect)
        {
            /* Wider than designed: keep the height, show more world either
               side. An ultrawide gains view instead of gaining bars. */
            engine->view_width = (float)engine->design_height * window_aspect;
        }
        else
        {
            engine->view_height = (float)engine->design_width / window_aspect;
        }
    }
    else if (engine->presentation == SDLSTATIC_PRESENT_NATIVE)
    {
        engine->view_width = (float)pixel_w;
        engine->view_height = (float)pixel_h;
    }

    SDL_SetRenderLogicalPresentation(engine->renderer, (int)(engine->view_width + 0.5f),
                                     (int)(engine->view_height + 0.5f),
                                     PresentationMode(engine->presentation));

    /* Pixel art wants nearest, everything else wants linear. Setting it as
       the renderer's default means a game never has to remember. */
    SDL_SetDefaultTextureScaleMode(engine->renderer,
                                   (engine->presentation == SDLSTATIC_PRESENT_INTEGER)
                                       ? SDL_SCALEMODE_NEAREST
                                       : SDL_SCALEMODE_LINEAR);
}

/* The display's refresh rate, so the smoothing above has something to snap
 * to. Unknown is fine — smoothing then does nothing. */
static void DetectRefreshRate(SDLStatic_Engine *engine)
{
    if (engine->window == NULL)
    {
        return;
    }
    const SDL_DisplayID display = SDL_GetDisplayForWindow(engine->window);
    const SDL_DisplayMode *mode = SDL_GetCurrentDisplayMode(display);
    if (mode != NULL && mode->refresh_rate > 1.0f)
    {
        SDLStatic_EngineSetRefreshRate(engine, mode->refresh_rate);
    }
}

SDLStatic_Engine *SDLStatic_CreateEngine(const SDLStatic_EngineConfig *config)
{
    SDLStatic_EngineConfig defaults;
    SDL_zero(defaults);
    if (config == NULL)
    {
        config = &defaults;
    }

    SDLStatic_Engine *engine = (SDLStatic_Engine *)SDL_calloc(1, sizeof(*engine));
    if (engine == NULL)
    {
        return NULL;
    }

    engine->tick_rate = (config->tick_rate > 0) ? SDL_clamp(config->tick_rate, 10, 480) : 60;
    engine->step_ns = NS_PER_SECOND / (Uint64)engine->tick_rate;
    engine->max_steps = (config->max_steps_per_frame > 0) ? config->max_steps_per_frame : 5;
    const float max_frame = (config->max_frame_seconds > 0.0f) ? config->max_frame_seconds
                                                               : 0.25f;
    engine->max_frame_ns = (Uint64)((double)max_frame * (double)NS_PER_SECOND);
    engine->interpolation = config->interpolation;
    engine->max_fps = config->max_fps;
    engine->time_scale = 1.0f;
    engine->manual_clock = config->manual_clock;
    engine->design_width = (config->design_width > 0) ? config->design_width : 1920;
    engine->design_height = (config->design_height > 0) ? config->design_height : 1080;
    engine->presentation = config->presentation;
    engine->clear_color = (SDL_FColor){0.06f, 0.07f, 0.09f, 1.0f};
    engine->running = true;

    if (config->headless)
    {
        /* No window: a software renderer over a surface the size of the
           design space, which is what tests and tools want. */
        /* The surface stands in for the window, so a test can ask for a
           16:10 or ultrawide "display" and check what the design space
           does about it. */
        const int surface_w = (config->window_width > 0) ? config->window_width
                                                         : engine->design_width;
        const int surface_h = (config->window_height > 0) ? config->window_height
                                                          : engine->design_height;
        SDL_Surface *surface = SDL_CreateSurface(surface_w, surface_h,
                                                 SDL_PIXELFORMAT_ARGB8888);
        if (surface == NULL)
        {
            SDL_free(engine);
            return NULL;
        }
        engine->renderer = SDL_CreateSoftwareRenderer(surface);
        if (engine->renderer == NULL)
        {
            SDL_DestroySurface(surface);
            SDL_free(engine);
            return NULL;
        }
        /* A software renderer does *not* take ownership of the surface it
           draws into, so we keep it and free it ourselves. */
        engine->headless_surface = surface;
    }
    else
    {
        SDL_WindowFlags flags = 0;
        if (!config->fixed_size)
        {
            flags |= SDL_WINDOW_RESIZABLE;
        }
        if (!config->low_dpi)
        {
            flags |= SDL_WINDOW_HIGH_PIXEL_DENSITY;
        }
        if (config->fullscreen)
        {
            flags |= SDL_WINDOW_FULLSCREEN;
        }
        const int width = (config->window_width > 0) ? config->window_width : 1280;
        const int height = (config->window_height > 0) ? config->window_height : 720;
        if (!SDL_CreateWindowAndRenderer((config->title != NULL) ? config->title : "SDLStatic",
                                         width, height, flags, &engine->window,
                                         &engine->renderer))
        {
            SDL_free(engine);
            return NULL;
        }
        /* Vsync unless asked otherwise: it costs nothing, it stops the loop
           free-running at four figures, and it quantises the frame delta
           for the smoothing above. */
        SDL_SetRenderVSync(engine->renderer, config->no_vsync ? 0 : 1);
        DetectRefreshRate(engine);
    }

    /* Design coordinates: the game is written once, at one size, and SDL
       scales it to whatever the display is. */
    ApplyPresentation(engine);

    engine->last_ns = Now(engine);
    return engine;
}

void SDLStatic_DestroyEngine(SDLStatic_Engine *engine)
{
    if (engine == NULL)
    {
        return;
    }
    /* Scenes first, so they see exit and unload while the renderer they
       may want to use is still alive. */
    SDLStatic_SceneShutdown(engine);
    if (engine->renderer != NULL)
    {
        SDL_DestroyRenderer(engine->renderer);
    }
    if (engine->window != NULL)
    {
        SDL_DestroyWindow(engine->window);
    }
    if (engine->headless_surface != NULL)
    {
        SDL_DestroySurface(engine->headless_surface); /* after the renderer */
    }
    SDL_free(engine);
}

/* --- the frame ---------------------------------------------------------- */

static void PumpEvents(SDLStatic_Engine *engine)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            engine->running = false;
        }
        else if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && engine->window != NULL &&
                 event.window.windowID == SDL_GetWindowID(engine->window))
        {
            engine->running = false;
        }
        else if (event.type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED)
        {
            /* In EXPAND the visible design rect follows the window, so the
               presentation has to be recomputed before anything draws. */
            ApplyPresentation(engine);
            /* The design space does not change with the window; the
               presentation absorbs it. The hook exists for games that lay
               out UI against the real aspect ratio. */
            if (engine->hooks != NULL && engine->hooks->resize != NULL)
            {
                engine->hooks->resize(engine->user, event.window.data1, event.window.data2);
            }
            DetectRefreshRate(engine); /* a move between displays changes it */
        }
        SDLStatic_SceneDispatchEvent(engine, &event);
        if (engine->hooks != NULL && engine->hooks->event != NULL)
        {
            engine->hooks->event(engine->user, &event);
        }
    }
}

/* Sleep out the rest of the frame.
 *
 * Vsync is supposed to do this, and usually does — but an occluded window,
 * a driver that ignores the request, or a headless run will all present
 * immediately, and then the loop spins as fast as the CPU allows. That
 * wastes power and, on a laptop, is audible. Sleeping to the target frame
 * period costs nothing when vsync is already pacing us (the remainder is
 * zero) and saves the machine when it is not. */
static void LimitFrameRate(SDLStatic_Engine *engine)
{
    if (engine->manual_clock || engine->max_fps < 0)
    {
        return; /* tests drive their own clock; negative disables it */
    }
    Uint64 period_ns = 0;
    if (engine->max_fps > 0)
    {
        period_ns = NS_PER_SECOND / (Uint64)engine->max_fps;
    }
    else if (engine->refresh_ns > 0)
    {
        period_ns = engine->refresh_ns;
    }
    else
    {
        return; /* nothing sensible to limit to */
    }

    const Uint64 elapsed = SDL_GetTicksNS() - engine->frame_start_ns;
    if (elapsed < period_ns)
    {
        SDL_DelayPrecise(period_ns - elapsed);
    }
}

bool SDLStatic_EngineTick(SDLStatic_Engine *engine)
{
    if (engine == NULL)
    {
        SDL_InvalidParamError("engine");
        return false;
    }
    engine->frame_start_ns = SDL_GetTicksNS();

    PumpEvents(engine);

    /* Measured before any waiting, so the vsync block at the end of the
       previous frame is not folded into this frame's step. */
    const Uint64 now = Now(engine);
    Uint64 raw = (now > engine->last_ns) ? (now - engine->last_ns) : 0;
    engine->last_ns = now;

    if (raw > engine->max_frame_ns)
    {
        raw = engine->max_frame_ns; /* [1] a stall: drop the excess */
    }
    const Uint64 delta_ns = SmoothDelta(engine, raw); /* [2] */
    engine->delta_seconds = (float)((double)delta_ns / (double)NS_PER_SECOND);

    /* [3] Exact, equal simulation steps. */
    engine->accumulator_ns += (Uint64)((double)delta_ns * (double)engine->time_scale);
    int steps = 0;
    while (engine->accumulator_ns >= engine->step_ns && steps < engine->max_steps)
    {
        const float step = SDLStatic_EngineStep(engine);
        if (engine->hooks != NULL && engine->hooks->fixed_update != NULL)
        {
            engine->hooks->fixed_update(engine->user, step);
        }
        /* Hooks run around the scene stack, never instead of it: a game can
           use both, which is how a debug overlay coexists with scenes. */
        SDLStatic_SceneDispatchFixedUpdate(engine, step);
        engine->accumulator_ns -= engine->step_ns;
        steps++;
    }
    engine->steps_last_frame = steps;
    if (steps == engine->max_steps && engine->accumulator_ns >= engine->step_ns)
    {
        /* The machine cannot keep up. Dropping the debt keeps the game
           responsive-but-slow instead of spiralling: catching up would make
           the next frame later still. */
        engine->accumulator_ns = 0;
        engine->overload_frames++;
    }

    /* [4] Where this frame sits between the last two simulation states. */
    switch (engine->interpolation)
    {
    case SDLSTATIC_INTERPOLATE_NONE:
        engine->alpha = 1.0f;
        break;
    case SDLSTATIC_INTERPOLATE_EXTRAPOLATE:
        engine->alpha = 1.0f + (float)((double)engine->accumulator_ns /
                                       (double)engine->step_ns);
        break;
    case SDLSTATIC_INTERPOLATE_LERP:
    default:
        engine->alpha = (float)((double)engine->accumulator_ns / (double)engine->step_ns);
        break;
    }

    if (engine->hooks != NULL && engine->hooks->update != NULL)
    {
        engine->hooks->update(engine->user, engine->delta_seconds);
    }
    SDLStatic_SceneDispatchUpdate(engine, engine->delta_seconds);

    SDL_SetRenderDrawColorFloat(engine->renderer, engine->clear_color.r, engine->clear_color.g,
                                engine->clear_color.b, engine->clear_color.a);
    SDL_SetRenderDrawBlendMode(engine->renderer, SDL_BLENDMODE_NONE);
    SDL_RenderClear(engine->renderer);
    SDLStatic_SceneDispatchRender(engine, engine->alpha);
    /* The game's own render hook goes last, so an overlay drawn there sits
       above the scenes and above a transition fade. */
    if (engine->hooks != NULL && engine->hooks->render != NULL)
    {
        engine->hooks->render(engine->user, engine->alpha);
    }
    SDL_RenderPresent(engine->renderer);

    LimitFrameRate(engine);

    engine->frame_count++;
    engine->fps_accumulator += engine->delta_seconds;
    engine->fps_frames++;
    if (engine->fps_accumulator >= 0.25f)
    {
        engine->fps = (float)engine->fps_frames / engine->fps_accumulator;
        engine->fps_accumulator = 0.0f;
        engine->fps_frames = 0;
    }
    return engine->running;
}

#ifdef __EMSCRIPTEN__
static void EmscriptenFrame(void *user)
{
    SDLStatic_Engine *engine = (SDLStatic_Engine *)user;
    if (!SDLStatic_EngineTick(engine))
    {
        if (engine->hooks != NULL && engine->hooks->unload != NULL)
        {
            engine->hooks->unload(engine->user);
        }
        emscripten_cancel_main_loop();
    }
}
#endif

bool SDLStatic_RunGame(SDLStatic_Engine *engine, const SDLStatic_GameHooks *hooks, void *user)
{
    if (engine == NULL || hooks == NULL)
    {
        return SDL_InvalidParamError("engine/hooks");
    }
    engine->hooks = hooks;
    engine->user = user;
    engine->last_ns = Now(engine);

    if (hooks->load != NULL && !hooks->load(user))
    {
        return false; /* the game has already set the error */
    }

#ifdef __EMSCRIPTEN__
    /* The browser owns the loop, so this returns immediately and `unload`
       runs when the game asks to quit. */
    emscripten_set_main_loop_arg(EmscriptenFrame, engine, 0, 0);
    return true;
#else
    while (SDLStatic_EngineTick(engine))
    {
    }
    if (hooks->unload != NULL)
    {
        hooks->unload(user);
    }
    return true;
#endif
}

void SDLStatic_EngineQuit(SDLStatic_Engine *engine)
{
    if (engine != NULL)
    {
        engine->running = false;
    }
}

/* --- accessors ---------------------------------------------------------- */

float SDLStatic_EngineDelta(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->delta_seconds : 0.0f;
}

float SDLStatic_EngineAlpha(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->alpha : 0.0f;
}

float SDLStatic_EngineStep(SDLStatic_Engine *engine)
{
    if (engine == NULL)
    {
        return 0.0f;
    }
    return (float)((double)engine->step_ns / (double)NS_PER_SECOND);
}

int SDLStatic_EngineStepsLastFrame(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->steps_last_frame : 0;
}

int SDLStatic_EngineOverloadFrames(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->overload_frames : 0;
}

Uint64 SDLStatic_EngineFrameCount(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->frame_count : 0;
}

float SDLStatic_EngineFps(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->fps : 0.0f;
}

void SDLStatic_EngineSetMaxFps(SDLStatic_Engine *engine, int max_fps)
{
    if (engine != NULL)
    {
        engine->max_fps = max_fps;
    }
}

int SDLStatic_EngineMaxFps(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->max_fps : 0;
}

void SDLStatic_EngineSetTimeScale(SDLStatic_Engine *engine, float scale)
{
    if (engine != NULL)
    {
        engine->time_scale = SDL_max(0.0f, scale);
    }
}

float SDLStatic_EngineTimeScale(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->time_scale : 0.0f;
}

bool SDLStatic_EngineSetTickRate(SDLStatic_Engine *engine, int ticks_per_second)
{
    if (engine == NULL)
    {
        return SDL_InvalidParamError("engine");
    }
    const int rate = SDL_clamp(ticks_per_second, 10, 480);
    const Uint64 step = NS_PER_SECOND / (Uint64)rate;
    /* Carry the accumulated time across as a fraction of a step, so
       changing the rate from an options menu does not stutter. */
    const double fraction = (engine->step_ns > 0)
                                ? (double)engine->accumulator_ns / (double)engine->step_ns
                                : 0.0;
    engine->tick_rate = rate;
    engine->step_ns = step;
    engine->accumulator_ns = (Uint64)(fraction * (double)step);
    return true;
}

int SDLStatic_EngineTickRate(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->tick_rate : 0;
}

SDL_Renderer *SDLStatic_EngineRenderer(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->renderer : NULL;
}

SDL_Window *SDLStatic_EngineWindow(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->window : NULL;
}

void SDLStatic_EngineDesignSize(SDLStatic_Engine *engine, int *width, int *height)
{
    if (engine == NULL)
    {
        return;
    }
    if (width != NULL)
    {
        *width = engine->design_width;
    }
    if (height != NULL)
    {
        *height = engine->design_height;
    }
}

bool SDLStatic_EngineSetPresentation(SDLStatic_Engine *engine,
                                     SDLStatic_EnginePresentation mode)
{
    if (engine == NULL)
    {
        return SDL_InvalidParamError("engine");
    }
    engine->presentation = mode;
    ApplyPresentation(engine);
    return true;
}

SDLStatic_EnginePresentation SDLStatic_EnginePresentation_(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->presentation : SDLSTATIC_PRESENT_EXPAND;
}

/**
 * Where the logical area actually lands, in logical units.
 *
 * Asked of SDL rather than derived from the mode, because only SDL knows what
 * each mode did: INTEGER floors the scale, OVERSCAN scales past the window and
 * crops, STRETCH uses a different factor per axis. Guessing gets four of the
 * six modes wrong.
 *
 * `SDL_GetRenderLogicalPresentationRect` gives the destination in *pixels*.
 * Inverting it back into logical units gives the region of the logical area a
 * player can actually see, which is what a game wants to reason about.
 */
static bool VisibleLogicalRect(SDLStatic_Engine *engine, SDL_FRect *out, float *scale_x,
                               float *scale_y)
{
    if (engine == NULL || engine->renderer == NULL || engine->view_width <= 0.0f ||
        engine->view_height <= 0.0f)
    {
        return false;
    }
    int pixel_w = 0;
    int pixel_h = 0;
    SDL_GetRenderOutputSize(engine->renderer, &pixel_w, &pixel_h);
    if (pixel_w <= 0 || pixel_h <= 0)
    {
        return false;
    }

    SDL_FRect dst = {0.0f, 0.0f, (float)pixel_w, (float)pixel_h};
    if (!SDL_GetRenderLogicalPresentationRect(engine->renderer, &dst) || dst.w <= 0.0f ||
        dst.h <= 0.0f)
    {
        dst.x = 0.0f;
        dst.y = 0.0f;
        dst.w = (float)pixel_w;
        dst.h = (float)pixel_h;
    }

    const float sx = dst.w / engine->view_width;
    const float sy = dst.h / engine->view_height;

    /* Un-project the window back through the presentation transform, then
       clip to the logical area — SDL will not draw outside it, so the bars a
       letterbox leaves are not part of the view. */
    SDL_FRect visible;
    visible.x = -dst.x / sx;
    visible.y = -dst.y / sy;
    visible.w = (float)pixel_w / sx;
    visible.h = (float)pixel_h / sy;

    const SDL_FRect logical = {0.0f, 0.0f, engine->view_width, engine->view_height};
    if (!SDL_GetRectIntersectionFloat(&visible, &logical, out))
    {
        *out = logical;
    }
    if (scale_x != NULL)
    {
        *scale_x = sx;
    }
    if (scale_y != NULL)
    {
        *scale_y = sy;
    }
    return true;
}

SDL_FRect SDLStatic_EngineViewRect(SDLStatic_Engine *engine)
{
    SDL_FRect rect = {0.0f, 0.0f, 0.0f, 0.0f};
    if (engine == NULL)
    {
        return rect;
    }
    if (!VisibleLogicalRect(engine, &rect, NULL, NULL))
    {
        rect.w = engine->view_width;
        rect.h = engine->view_height;
    }
    return rect;
}

SDL_FRect SDLStatic_EngineSafeRect(SDLStatic_Engine *engine)
{
    SDL_FRect rect = {0.0f, 0.0f, 0.0f, 0.0f};
    if (engine == NULL)
    {
        return rect;
    }
    /* The design rectangle, centred in the logical area... */
    SDL_FRect design;
    design.w = (float)engine->design_width;
    design.h = (float)engine->design_height;
    design.x = (engine->view_width - design.w) * 0.5f;
    design.y = (engine->view_height - design.h) * 0.5f;

    /* ...intersected with what is on screen, so that under OVERSCAN — the one
       mode that crops — the safe rect shrinks instead of promising room that
       the player cannot see. */
    const SDL_FRect view = SDLStatic_EngineViewRect(engine);
    if (!SDL_GetRectIntersectionFloat(&design, &view, &rect))
    {
        rect = view;
    }
    return rect;
}

void SDLStatic_EnginePixelSize(SDLStatic_Engine *engine, int *width, int *height)
{
    int w = 0;
    int h = 0;
    if (engine != NULL)
    {
        SDL_GetRenderOutputSize(engine->renderer, &w, &h);
    }
    if (width != NULL)
    {
        *width = w;
    }
    if (height != NULL)
    {
        *height = h;
    }
}

float SDLStatic_EngineRenderScale(SDLStatic_Engine *engine)
{
    SDL_FRect view;
    float sx = 1.0f;
    float sy = 1.0f;
    if (!VisibleLogicalRect(engine, &view, &sx, &sy))
    {
        return 1.0f;
    }
    /* Every mode but STRETCH is uniform, so sx == sy; for STRETCH the smaller
       factor is the honest one to quote, since it bounds detail. */
    return SDL_min(sx, sy);
}

int SDLStatic_EngineAssetScale(SDLStatic_Engine *engine)
{
    const float scale = SDLStatic_EngineRenderScale(engine);
    if (scale >= 3.0f)
    {
        return 4;
    }
    if (scale >= 1.5f)
    {
        return 2;
    }
    return 1;
}

void SDLStatic_EngineSetClearColor(SDLStatic_Engine *engine, SDL_FColor color)
{
    if (engine != NULL)
    {
        engine->clear_color = color;
    }
}

void SDLStatic_EngineWindowToDesign(SDLStatic_Engine *engine, float window_x, float window_y,
                                    float *design_x, float *design_y)
{
    if (engine == NULL)
    {
        return;
    }
    float x = window_x;
    float y = window_y;
    /* SDL knows the letterbox offset and scale it chose, so ask it rather
       than recomputing and getting it subtly wrong. */
    SDL_RenderCoordinatesFromWindow(engine->renderer, window_x, window_y, &x, &y);
    if (design_x != NULL)
    {
        *design_x = x;
    }
    if (design_y != NULL)
    {
        *design_y = y;
    }
}
