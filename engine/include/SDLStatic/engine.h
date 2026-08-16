/**
 * @file engine.h
 * @brief SDLStatic::Engine — the frame loop, time, and the drawing surface.
 *
 * Original SDLStatic code (zlib). This is the core of an opinionated game
 * engine: it owns the loop, so it can do the things a library cannot.
 *
 * The loop is a **fixed simulation tick with interpolated rendering**, the
 * arrangement Godot and Unity both use, because a loop that simply
 * multiplies by a measured delta looks worse than it reads:
 *
 *   - Measured frame times are noisy (16.4, 17.1, 15.9 ms), so a steady
 *     motion advances by a different amount each refresh. The eye reads
 *     that as shimmer.
 *   - The display is quantised and a free-running simulation is not, so
 *     even perfectly delivered frames judder.
 *
 * So: the simulation advances in exact steps (60 Hz by default), the
 * measured delta is snapped to the display's cadence before it is used, and
 * rendering happens *between* two simulation states using an interpolation
 * factor. See docs/lighting.md's sibling, docs/engine.md, for the full
 * argument.
 *
 *     SDLStatic_GameHooks hooks = {0};
 *     hooks.fixed_update = FixedUpdate;   // simulation: 60 Hz, exact
 *     hooks.render = Render;              // drawing: display rate, smooth
 *
 *     SDLStatic_Engine *engine = SDLStatic_CreateEngine(NULL);
 *     SDLStatic_RunGame(engine, &hooks, &game);
 *     SDLStatic_DestroyEngine(engine);
 *
 * Coordinates are **design coordinates**, not pixels: the engine sets a
 * logical presentation size (1920x1080 by default) and SDL scales it to
 * whatever the display actually is, letterboxed. A game is written once, at
 * one resolution, and looks right on a 1080p laptop and a 4K monitor —
 * see SDLStatic_EnginePresentation for the other ways to fit it.
 */
#ifndef SDLSTATIC_ENGINE_H
#define SDLSTATIC_ENGINE_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SDLStatic_Engine SDLStatic_Engine;

/**
 * How the design resolution is fitted to the window.
 *
 * All of these scale the *coordinates* — SDL applies a transform, it does
 * not render offscreen and resample — so a game authored at 4K costs a
 * 1080p machine nothing extra. What differs is what happens when the
 * window's aspect ratio is not the design's, and there are only three
 * possible answers: show bars, crop, or distort.
 *
 *     SDLStatic_EngineConfig config = {0};
 *     config.presentation = SDLSTATIC_PRESENT_LETTERBOX;   // already the default
 *     SDLStatic_Engine *engine = SDLStatic_CreateEngine(&config);
 *
 * and to change it later, from an options menu:
 *
 *     SDLStatic_EngineSetPresentation(engine, SDLSTATIC_PRESENT_INTEGER);
 *
 * See docs/engine.md for the full comparison.
 */
typedef enum SDLStatic_EnginePresentation
{
    /** Fit the whole design space, preserving aspect, with bars where the
     *  window is a different shape.
     *
     *  The default, and the right answer for most games: every player sees
     *  exactly the frame the game was composed in, at every window size and
     *  on every monitor, with no distortion and nothing cropped. The view
     *  rect never changes, so UI may be positioned against fixed
     *  coordinates. The cost is bars on a mismatched display. */
    SDLSTATIC_PRESENT_LETTERBOX = 0,
    /** Keep the design's shorter axis and let the other grow or shrink with
     *  the window, so an ultrawide monitor **sees more world** instead of
     *  black bars. No bars, no cropping, no distortion either — the trade is
     *  that the visible area is not fixed, so UI must anchor to
     *  SDLStatic_EngineSafeRect, and a player on a wider monitor sees
     *  further. What Godot calls "expand". */
    SDLSTATIC_PRESENT_EXPAND,
    /** Fill the window by cropping the overflow. Preserves aspect, no bars,
     *  but part of the design space is off-screen — the view and safe rects
     *  shrink to what survives. */
    SDLSTATIC_PRESENT_OVERSCAN,
    /** Whole-number scale, for pixel art. Also switches texture filtering to
     *  nearest, because a fractional scale is what makes pixel art shimmer. */
    SDLSTATIC_PRESENT_INTEGER,
    SDLSTATIC_PRESENT_STRETCH, /**< fill, ignoring aspect ratio: distorts */
    SDLSTATIC_PRESENT_NATIVE   /**< no scaling: coordinates are pixels */
} SDLStatic_EnginePresentation;

/**
 * Which SDL renderer backend to run on.
 *
 * SDL ships several — on a Mac it offers metal, opengl, opengles2, vulkan,
 * gpu and software — and left alone it picks the platform's native one:
 * Metal on Apple, Direct3D on Windows, OpenGL elsewhere.
 *
 * This engine picks **OpenGL, everywhere, by default**, and that is a
 * deliberate trade:
 *
 *   One shader language. The post-processing chain and the lighting module
 *   are GLSL. Under a native backend they cannot run at all, so the same
 *   game looks different on macOS from how it looks on Linux — for no
 *   reason the player can see. Writing them again in MSL, HLSL and SPIR-V
 *   is three more implementations to keep in step.
 *
 *   One code path to test. GLSL 1.x runs on desktop GL, GLES on mobile and
 *   WebGL in a browser, which covers every platform this project targets.
 *
 * The cost is real and worth stating. Apple deprecated OpenGL in 2018: it
 * still works, it is capped at 4.1, and it will not improve. Metal has
 * lower CPU overhead. Some Windows OEM drivers have weaker GL than their
 * Direct3D. A 2D game is very unlikely to notice any of it — but a game
 * that measures a difference, or is shipping on a platform where GL is
 * genuinely worse, should say `SDLSTATIC_BACKEND_NATIVE` and give up the
 * shader effects knowingly rather than by accident.
 */
typedef enum SDLStatic_EngineBackend
{
    /** OpenGL / OpenGL ES: the default, and the only one where the shader
     *  effects work. Falls back to whatever SDL can provide if the machine
     *  genuinely has no GL, rather than refusing to start. */
    SDLSTATIC_BACKEND_OPENGL = 0,
    /** Whatever SDL would have chosen: Metal, Direct3D, Vulkan. Faster on
     *  paper; no post-processing. */
    SDLSTATIC_BACKEND_NATIVE,
    /** The software renderer. For tools, and for a machine whose drivers
     *  are broken enough that nothing else starts. */
    SDLSTATIC_BACKEND_SOFTWARE
} SDLStatic_EngineBackend;

/** How rendering positions things between two simulation steps. */
typedef enum SDLStatic_EngineInterpolation
{
    SDLSTATIC_INTERPOLATE_LERP = 0, /**< between previous and current (default) */
    SDLSTATIC_INTERPOLATE_NONE,     /**< snap to the latest step */
    SDLSTATIC_INTERPOLATE_EXTRAPOLATE /**< predict past current: no render lag,
                                           at the cost of overshoot on sharp
                                           direction changes */
} SDLStatic_EngineInterpolation;

/**
 * Engine configuration. Zero-initialise and set what matters; every field
 * has a sensible default, so `SDLStatic_CreateEngine(NULL)` is a valid way
 * to start.
 */
typedef struct SDLStatic_EngineConfig
{
    const char *title;   /**< window title; "SDLStatic" if NULL */
    int window_width;    /**< window size in pixels; 1280x720 if zero */
    int window_height;
    /** The coordinate space the game is written in — its *reference*
     *  resolution, not the resolution it renders at. 1920x1080 if zero.
     *
     *  Pick the aspect and the convenient number, not the target hardware:
     *  a game written at 1920x1080 renders natively at 4K, because the
     *  scale is applied to coordinates rather than to a rendered image. Art
     *  is a separate question — see SDLStatic_EngineAssetScale. */
    int design_width;
    int design_height;
    SDLStatic_EnginePresentation presentation;
    bool fullscreen;

    /* Opt-outs, not opt-ins: a zero-initialised config must give the
       documented defaults, so the fields that default to *on* are phrased
       as the thing you turn off. */
    bool no_vsync;    /**< vsync is on by default: free pacing, and it
                           quantises the frame delta for smoothing */
    bool fixed_size;  /**< windows are resizable by default */
    bool low_dpi;     /**< high-DPI is on by default */

    /** Upper limit on frames per second; 0 means "follow the display".
     *
     *  Vsync usually paces the loop for free, but not always — an occluded
     *  or off-screen window may not block on present, and some drivers
     *  ignore the request entirely. Left to itself the loop then free-runs
     *  at thousands of frames a second, burning battery to draw images
     *  nobody sees. The engine therefore sleeps out the remainder of each
     *  frame: by default to the display's refresh rate, or to this value
     *  when set. Use a negative value to disable the limiter outright. */
    int max_fps;

    int tick_rate;    /**< simulation steps per second; 60 if zero. 120 is
                           the other sensible value, and is worth it when the
                           engine is running physics. */
    int max_steps_per_frame; /**< catch-up cap; 5 if zero */
    float max_frame_seconds; /**< longer than this is a stall, not a slow
                                  frame, and the time is dropped; 0.25 if 0 */
    SDLStatic_EngineInterpolation interpolation;

    /** Graphics settings to start with — usually the result of
     *  SDLStatic_GraphicsResolve, which is how a config file and the command
     *  line reach the engine. NULL means SDLStatic_GraphicsDefaults().
     *
     *  These win over `presentation`, `no_vsync` and `max_fps` above, which
     *  remain for games that want nothing to do with settings files. */
    const struct SDLStatic_GraphicsSettings *graphics;

    /** Which of SDL's renderer backends to use. Zero means OpenGL, which is
     *  this engine's opinion — see SDLStatic_EngineBackend. */
    SDLStatic_EngineBackend backend;

    /** The program's command line, so the engine can honour the arguments
     *  it documents — `--media`, `--media-password`. Pass them straight
     *  through from main(); anything the engine does not recognise is left
     *  alone, because the game owns this command line.
     *
     *  Graphics settings are read from argv separately, by
     *  SDLStatic_GraphicsResolve, so that a game can inspect or override
     *  them before the engine exists. */
    int argc;
    char *const *argv;

    /** Where the game's assets are. NULL runs the default search — an
     *  embedded archive, then media.zip, media.dat and media/ — which is
     *  what almost every game should do. An explicit path here beats
     *  `--media` on the command line. See engine_media.h. */
    const char *media_path;
    /** Do not mount anything. For a game that manages its own VFS. */
    bool no_auto_mount;

    /** Headless: software renderer, no window. For tests and tools. */
    bool headless;
    /** Drive time with SDLStatic_EngineAdvance instead of the clock, so a
     *  test can simulate an hour of frames in a millisecond. */
    bool manual_clock;
} SDLStatic_EngineConfig;

/**
 * What a game implements. Every hook is optional; a game with only `render`
 * is valid (and is how you write a screensaver).
 *
 * The split between `fixed_update` and `update` is the important one:
 *
 *   fixed_update(step)  runs 0..max_steps times a frame, always with the
 *                       same `step`. Simulation goes here — movement,
 *                       physics, AI — because it must not depend on how
 *                       fast the machine happens to be.
 *   update(dt)          runs exactly once a frame with the real delta.
 *                       Cosmetics go here — camera smoothing, UI tweens.
 *   render(alpha)       runs once a frame. `alpha` is how far the frame
 *                       sits between the previous simulation step and the
 *                       current one, in [0, 1). Draw at
 *                       `lerp(previous, current, alpha)` and motion is
 *                       smooth even when the tick rate and the refresh rate
 *                       disagree.
 */
typedef struct SDLStatic_GameHooks
{
    bool (*load)(void *user);                      /**< once, before the loop */
    void (*fixed_update)(void *user, float step);  /**< simulation */
    void (*update)(void *user, float dt);          /**< per-frame cosmetics */
    void (*render)(void *user, float alpha);       /**< draw */
    /** Draw *after* the post-processing chain, over the finished frame and
     *  before it is presented.
     *
     *  Two things need this. A HUD usually should not be scanlined,
     *  pixelated or chromatically split along with the world — real CRT
     *  games had no UI layer, and applying the effect to one looks like a
     *  bug rather than a style. And a screenshot of what the player
     *  actually saw can only be taken here, because everything before this
     *  point is the frame *without* the effects.
     *
     *  Coordinates are design coordinates, the same as `render`. */
    void (*post_render)(void *user);
    void (*event)(void *user, const SDL_Event *event);
    void (*resize)(void *user, int width, int height);
    void (*unload)(void *user);                    /**< once, after the loop */
} SDLStatic_GameHooks;

/* --- lifecycle ---------------------------------------------------------- */

/** Create an engine (and its window and renderer). `config` may be NULL for
 *  the defaults. Returns NULL and sets SDL_GetError() on failure. */
extern SDLStatic_Engine *SDLStatic_CreateEngine(const SDLStatic_EngineConfig *config);

extern void SDLStatic_DestroyEngine(SDLStatic_Engine *engine);

/** Run until something calls SDLStatic_EngineQuit or the window closes.
 *
 *  On the web this hands the loop to the browser and returns immediately —
 *  which is why cleanup belongs in the `unload` hook rather than after this
 *  call. Returns false if `load` failed. */
extern bool SDLStatic_RunGame(SDLStatic_Engine *engine, const SDLStatic_GameHooks *hooks,
                              void *user);

/** One iteration of the loop, for a game that wants to own its own. Returns
 *  false once the engine has been asked to stop. */
extern bool SDLStatic_EngineTick(SDLStatic_Engine *engine);

/** Install the hooks without handing over the loop.
 *
 *  SDLStatic_RunGame does this for you. A game driving the loop itself with
 *  SDLStatic_EngineTick needs it, because otherwise there is no way to be
 *  called back at all — which made the manual-loop path documented but not
 *  actually usable.
 *
 *  `hooks` is **not** copied: it must outlive the engine, which is what a
 *  static or a member gives you for free. Pass NULL to detach. */
extern void SDLStatic_EngineSetHooks(SDLStatic_Engine *engine,
                                     const SDLStatic_GameHooks *hooks, void *user);

/** Ask the loop to stop after the current frame. */
extern void SDLStatic_EngineQuit(SDLStatic_Engine *engine);

/* --- the frame ---------------------------------------------------------- */

/** Seconds of real time the last frame took, after clamping and smoothing. */
extern float SDLStatic_EngineDelta(SDLStatic_Engine *engine);

/** Interpolation factor for the current frame, in [0, 1). */
extern float SDLStatic_EngineAlpha(SDLStatic_Engine *engine);

/** Fixed step length in seconds — 1/tick_rate. Constant for the run. */
extern float SDLStatic_EngineStep(SDLStatic_Engine *engine);

/** Simulation steps run in the last frame; usually 1. Zero means the frame
 *  arrived early, two or more means it arrived late. */
extern int SDLStatic_EngineStepsLastFrame(SDLStatic_Engine *engine);

/** Frames in which the machine could not keep up and simulation time was
 *  dropped. A steadily rising number is the signal to lower quality. */
extern int SDLStatic_EngineOverloadFrames(SDLStatic_Engine *engine);

/** Frames rendered since the engine started. */
extern Uint64 SDLStatic_EngineFrameCount(SDLStatic_Engine *engine);

/** Smoothed frames per second, for a debug overlay. */
extern float SDLStatic_EngineFps(SDLStatic_Engine *engine);

/** Change the frame-rate limit at runtime — an options menu will want to.
 *  0 follows the display, negative disables the limiter. */
extern void SDLStatic_EngineSetMaxFps(SDLStatic_Engine *engine, int max_fps);
extern int SDLStatic_EngineMaxFps(SDLStatic_Engine *engine);

/** Scale simulation time: 0 pauses, 0.5 is slow motion, 2 is double speed.
 *  Rendering and `update` are unaffected, so menus still animate while the
 *  world is paused. */
extern void SDLStatic_EngineSetTimeScale(SDLStatic_Engine *engine, float scale);
extern float SDLStatic_EngineTimeScale(SDLStatic_Engine *engine);

/** Change the simulation rate at runtime (30, 60, 120...). Clamped to
 *  [10, 480]. Existing accumulated time is rescaled, so this is safe to
 *  call from an options menu. */
extern bool SDLStatic_EngineSetTickRate(SDLStatic_Engine *engine, int ticks_per_second);
extern int SDLStatic_EngineTickRate(SDLStatic_Engine *engine);

/* --- the surface -------------------------------------------------------- */

extern SDL_Renderer *SDLStatic_EngineRenderer(SDLStatic_Engine *engine);
extern SDL_Window *SDLStatic_EngineWindow(SDLStatic_Engine *engine);

/** Change how the design space is fitted to the window, at runtime.
 *
 *  An options menu will want this — "letterbox" versus "expand" is a taste
 *  players have opinions about — and the view rect is recomputed
 *  immediately, so the next frame is already laid out for the new mode. */
extern bool SDLStatic_EngineSetPresentation(SDLStatic_Engine *engine,
                                            SDLStatic_EnginePresentation mode);

extern SDLStatic_EnginePresentation SDLStatic_EnginePresentation_(SDLStatic_Engine *engine);

/** The design (reference) space the game was configured with. */
extern void SDLStatic_EngineDesignSize(SDLStatic_Engine *engine, int *width, int *height);

/** The design-space rectangle actually visible in the window.
 *
 *  Equal to the design size for every mode except EXPAND, where the window's
 *  aspect ratio widens or heightens it — a 21:9 monitor showing a 16:9
 *  design gets a wider view rather than bars. Origin is 0,0 in EXPAND and
 *  LETTERBOX; OVERSCAN crops, so its origin is negative.
 *
 *  This is the rectangle to lay a camera or a full-screen backdrop out
 *  against. */
extern SDL_FRect SDLStatic_EngineViewRect(SDLStatic_Engine *engine);

/** The part of the view guaranteed to be visible on every aspect ratio —
 *  the design rectangle, centred in the view.
 *
 *  Anchor UI to this, not to the view: a button at the right edge of the
 *  *view* sits off in the periphery on an ultrawide, while the safe rect is
 *  where the game was actually composed. Consoles call the same idea a
 *  title-safe area. */
extern SDL_FRect SDLStatic_EngineSafeRect(SDLStatic_Engine *engine);

/** The window's real size in pixels — the framebuffer, not the design
 *  space, and not points on a high-DPI display. */
extern void SDLStatic_EnginePixelSize(SDLStatic_Engine *engine, int *width, int *height);

/** How many pixels one design unit covers right now.
 *
 *  1.0 when the window matches the design space, 2.0 for a 1920-wide design
 *  on a 4K display. Line widths and other things that should stay
 *  pixel-crisp can divide by it. */
extern float SDLStatic_EngineRenderScale(SDLStatic_Engine *engine);

/** Which art set to load: 1 below a 1.5x render scale, 2 below 3x, then 4.
 *
 *  The scaling above is free because it applies to coordinates, but *art* is
 *  not: a 1x sprite stretched onto a 4K display is soft, and a 4K sprite
 *  squeezed onto a laptop wastes memory and shimmers under minification.
 *  Games that ship more than one set of art choose with this. */
extern int SDLStatic_EngineAssetScale(SDLStatic_Engine *engine);

/** Colour the frame is cleared to before `render`. Defaults to near-black. */
extern void SDLStatic_EngineSetClearColor(SDLStatic_Engine *engine, SDL_FColor color);

/** Convert a window position (an SDL mouse or touch coordinate) into design
 *  coordinates. Needed because the game thinks in design space and SDL
 *  reports events in window space. */
extern void SDLStatic_EngineWindowToDesign(SDLStatic_Engine *engine, float window_x,
                                           float window_y, float *design_x,
                                           float *design_y);

/* --- testing ------------------------------------------------------------ */

/** Advance the manual clock by `nanoseconds`.
 *
 *  Only meaningful when the engine was created with `manual_clock`. This is
 *  what makes the loop testable: a test can feed exact, or deliberately
 *  awful, frame times and assert on how many simulation steps came out. */
extern void SDLStatic_EngineAdvance(SDLStatic_Engine *engine, Uint64 nanoseconds);

/** Pretend the display refreshes at this rate, so delta smoothing can be
 *  tested without a real monitor. Zero disables smoothing. */
extern void SDLStatic_EngineSetRefreshRate(SDLStatic_Engine *engine, float hz);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_H */
