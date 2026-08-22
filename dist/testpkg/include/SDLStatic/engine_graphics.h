/**
 * @file engine_graphics.h
 * @brief Graphics settings: what an options screen changes, and where the
 *        values come from.
 *
 * Original SDLStatic code (zlib).
 *
 * One struct holds every graphics setting a player can change. It is plain
 * data — copyable, comparable, serialisable — because the same values have
 * to survive four different journeys:
 *
 *   defaults   SDLStatic_GraphicsDefaults(), compiled in
 *   file       media/config.toml, in the pref directory or beside the game
 *   command    --vsync=off --bloom=0.4, which beats the file
 *   runtime    an options screen, which beats everything until it is saved
 *
 * `SDLStatic_GraphicsResolve` walks that chain in order and hands back the
 * result, so a game's main() is:
 *
 *     SDLStatic_GraphicsSettings gfx;
 *     SDLStatic_GraphicsResolve(&gfx, argc, argv, "acme", "mygame");
 *
 *     SDLStatic_EngineConfig config = {0};
 *     config.graphics = &gfx;
 *     SDLStatic_Engine *engine = SDLStatic_CreateEngine(&config);
 *
 * and an options screen is:
 *
 *     SDLStatic_GraphicsSettings next = *SDLStatic_EngineGraphics(engine);
 *     next.bloom = slider_value;
 *     SDLStatic_EngineSetGraphics(engine, &next);      // applies now
 *     SDLStatic_GraphicsSave(&next, "acme", "mygame"); // persists
 *
 * Settings divide into three kinds, and it is worth knowing which is which
 * because they fail differently:
 *
 *   **Engine settings** (vsync, frame cap, window mode, presentation,
 *   render scale, filtering) take effect the moment they are set.
 *
 *   **Post-processing** (bloom, CRT, chromatic aberration, anti-aliasing,
 *   brightness, colour-blind correction) run as shaders over the finished
 *   frame. They need an OpenGL-backed renderer — see
 *   SDLStatic_EngineEffectsAvailable — and are simply skipped without one,
 *   so a game never fails to start over a cosmetic effect.
 *
 *   **Budgets** (particles, dynamic lights, shadows, screen shake, UI
 *   scale) are numbers the *game* reads. The engine cannot know what a
 *   particle costs in your game, so it does not pretend to: it carries the
 *   player's choice and converts it into concrete numbers through the
 *   SDLStatic_Graphics*() helpers below.
 */
#ifndef SDLSTATIC_ENGINE_GRAPHICS_H
#define SDLSTATIC_ENGINE_GRAPHICS_H

#include <SDLStatic/engine.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * A quality budget. Ordered, so `if (settings.shadows >= SDLSTATIC_QUALITY_MEDIUM)`
 * reads correctly and stays correct if a tier is ever added at the top.
 *
 * `OFF` is a real choice, not a degenerate one: a player on a weak machine
 * turning shadows off entirely is the reason the setting exists.
 */
typedef enum SDLStatic_GraphicsQuality
{
    SDLSTATIC_QUALITY_OFF = 0,
    SDLSTATIC_QUALITY_LOW,
    SDLSTATIC_QUALITY_MEDIUM,
    SDLSTATIC_QUALITY_HIGH
} SDLStatic_GraphicsQuality;

/** Anti-aliasing. FXAA is a post-process pass: it costs one full-screen
 *  shader and smooths the edges of rotated sprites and vector shapes. On by
 *  default, because it is fidelity rather than style — but it softens pixel
 *  art, so a pixel-art game should turn it off along with choosing INTEGER
 *  presentation. */
typedef enum SDLStatic_GraphicsAA
{
    SDLSTATIC_AA_OFF = 0,
    SDLSTATIC_AA_FXAA
} SDLStatic_GraphicsAA;

/** Colour-vision correction. Shifts confusable hues apart rather than
 *  simulating the deficiency — this is the accessibility setting, not the
 *  demonstration. */
typedef enum SDLStatic_ColorBlindMode
{
    SDLSTATIC_COLORBLIND_NONE = 0,
    SDLSTATIC_COLORBLIND_PROTANOPIA,   /**< red-weak */
    SDLSTATIC_COLORBLIND_DEUTERANOPIA, /**< green-weak; the most common */
    SDLSTATIC_COLORBLIND_TRITANOPIA    /**< blue-weak */
} SDLStatic_ColorBlindMode;

typedef enum SDLStatic_WindowMode
{
    SDLSTATIC_WINDOW_WINDOWED = 0,
    SDLSTATIC_WINDOW_BORDERLESS, /**< desktop-sized, no decoration: the
                                      "fullscreen" most players want, because
                                      alt-tab is instant */
    SDLSTATIC_WINDOW_EXCLUSIVE   /**< a real mode switch */
} SDLStatic_WindowMode;

/** Texture filtering. `AUTO` follows the presentation mode — nearest under
 *  INTEGER, linear everywhere else — which is right often enough that most
 *  games never touch it. */
typedef enum SDLStatic_TextureFilter
{
    SDLSTATIC_FILTER_AUTO = 0,
    SDLSTATIC_FILTER_LINEAR,
    SDLSTATIC_FILTER_NEAREST
} SDLStatic_TextureFilter;

/**
 * Every graphics setting, in one copyable struct.
 *
 * Do **not** zero-initialise this: zero is a meaningful value for most of
 * these fields (brightness 0 is black, render scale 0 is nothing) and the
 * enums order quality with OFF first. Start from
 * SDLStatic_GraphicsDefaults() and change what you want.
 */
typedef struct SDLStatic_GraphicsSettings
{
    /* --- presentation and pacing: applied by the engine, immediately --- */

    bool vsync;    /**< default on */
    int max_fps;   /**< 0 follows the display; negative uncaps; default 0 */
    /** Default **borderless fullscreen**. That is what a finished game
     *  should do on launch, and it is what players expect; windowed is the
     *  developer's setting, not the shipping one. */
    SDLStatic_WindowMode window_mode;
    /** Window size in pixels when windowed, ignored when fullscreen. 0
     *  means the engine's own default. Persisted, so a player who resizes
     *  a window gets it back next launch. */
    int window_width, window_height;
    /** Which monitor to open on, as a 0-based index into the displays SDL
     *  reports. Clamped to what actually exists at launch, so unplugging
     *  the monitor a game was saved on does not leave it invisible on a
     *  display that is no longer there.
     *
     *  An index rather than an SDL_DisplayID because the ID is assigned per
     *  run and would mean nothing in a settings file written yesterday. */
    int display;
    SDLStatic_EnginePresentation presentation;
    /** Render at a fraction of the window's resolution and let the display
     *  scale the result up. The single largest performance lever there is:
     *  0.75 costs about half the fill rate, 0.5 about a quarter, and on a
     *  handheld it is the difference between 30 and 60 fps. Clamped to
     *  [0.25, 2.0]; 1.0 is native. Above 1.0 is supersampling. */
    float render_scale;
    SDLStatic_TextureFilter filter;

    /* --- budgets: carried by the engine, spent by the game ------------- */

    SDLStatic_GraphicsQuality particles;      /**< default HIGH */
    SDLStatic_GraphicsQuality dynamic_lights; /**< default HIGH */
    SDLStatic_GraphicsQuality shadows;        /**< default HIGH */

    /* --- post-processing: shaders over the finished frame -------------- */

    /** Bright pixels bleed into their surroundings. 0 is off; 0.3–0.5 reads
     *  as "glowing", above 0.7 as "hazy". Default 0. */
    float bloom;
    /** How bright a pixel must be before it blooms, 0..1. Lower catches
     *  more of the frame. Default 0.7. */
    float bloom_threshold;
    /** Scanlines and a phosphor mask, 0..1. Default 0. */
    float crt;
    /** Barrel distortion, 0..1, kept separate because plenty of people want
     *  scanlines without a curved screen. Default 0. */
    float crt_curvature;
    /** Quantise to NxN blocks. 1 is off. A cheap way to make high-res art
     *  look deliberately chunky. Default 1. */
    int pixelation;
    /** RGB separation increasing towards the edges of the screen, 0..1.
     *  Subtle is the point: 0.1–0.2. Default 0. */
    float chromatic_aberration;
    SDLStatic_GraphicsAA antialias; /**< default FXAA */

    /* --- image and accessibility --------------------------------------- */

    /** Gamma. 1.0 is neutral; clamped to [0.5, 2.0]. The setting players
     *  reach for first when a game's dark scenes are unreadable on their
     *  panel — and a lighting-heavy game needs it. */
    float brightness;
    /** Contrast, 1.0 neutral, clamped to [0.5, 2.0]. Default 1. */
    float contrast;
    /** Saturation, 1.0 neutral, clamped to [0, 2]. 0 is greyscale. */
    float saturation;
    SDLStatic_ColorBlindMode color_blind;
    /** Suppress full-screen flashes and clamp bloom spikes. A
     *  photosensitivity setting; ship it, but off by default — it alters
     *  the image away from what the artist intended, which is right for the
     *  player who needs it and wrong for everyone else. */
    bool reduced_flashing;
    /** Screen-shake multiplier, 0..1. Advisory — the game multiplies its
     *  own shake by this. 0 is the motion-sickness setting. Default 1. */
    float screen_shake;
    /** UI scale multiplier, clamped to [0.5, 3.0]. Advisory. Default 1. */
    float ui_scale;
} SDLStatic_GraphicsSettings;

/* --- defaults and validation -------------------------------------------- */

/**
 * The compiled-in defaults: **borderless fullscreen at maximum fidelity.**
 *
 * Vsync on, every quality budget high, anti-aliasing on, native render
 * scale. A game should look as good as it can on first launch, because most
 * players never open the options screen at all.
 *
 * Two categories stay off, and neither is a fidelity decision:
 *
 *   The **stylistic** effects — bloom, CRT, curvature, pixelation,
 *   chromatic aberration — are decisions about how a game looks, not how
 *   well it looks. The engine does not get to make them; turn on the ones
 *   your game is meant to have.
 *
 *   The **accessibility** settings — reduced flashing, colour-blind
 *   correction — alter the image away from what the artist intended, which
 *   is exactly right for the player who needs them and wrong for everyone
 *   else. They are opt-in.
 */
extern SDLStatic_GraphicsSettings SDLStatic_GraphicsDefaults(void);

/**
 * Safe mode: a resizable 1280x720 window with the graphics turned down.
 *
 * The escape hatch for a player who has made the game unstartable — a
 * resolution the monitor cannot show, a display that is no longer plugged
 * in, an effect the driver crashes on. Reached with `--with-safe-mode`,
 * which needs no working config file and no working settings screen, so it
 * still works when the saved settings are the problem.
 *
 * Windowed and resizable on purpose: a window that will not display
 * correctly can at least be dragged somewhere that will.
 */
extern SDLStatic_GraphicsSettings SDLStatic_GraphicsSafeMode(void);

/** Force every field into its valid range. Called for you by
 *  SDLStatic_EngineSetGraphics and by every loader, so a hand-edited
 *  config.toml with `brightness = 40` cannot black out a game. */
extern void SDLStatic_GraphicsClamp(SDLStatic_GraphicsSettings *settings);

/** Field-by-field comparison, for an options screen that wants to enable
 *  its Apply button only when something actually changed. */
extern bool SDLStatic_GraphicsEqual(const SDLStatic_GraphicsSettings *a,
                                    const SDLStatic_GraphicsSettings *b);

/* --- the engine ---------------------------------------------------------- */

/** Apply settings to a running engine. Everything the engine owns changes
 *  at once — vsync, frame cap, window mode, presentation, render scale,
 *  filtering, and the post-processing chain.
 *
 *  Returns false only if `engine` or `settings` is NULL; a post-effect that
 *  cannot run on this renderer is not an error, it is simply not drawn. */
extern bool SDLStatic_EngineSetGraphics(SDLStatic_Engine *engine,
                                        const SDLStatic_GraphicsSettings *settings);

/** The settings in force. Never NULL for a valid engine — copy it, change
 *  what you want, and set it back. */
extern const SDLStatic_GraphicsSettings *SDLStatic_EngineGraphics(SDLStatic_Engine *engine);

/* --- monitors ------------------------------------------------------------ */

/** How many displays SDL can see. */
extern int SDLStatic_EngineDisplayCount(void);

/** The name of display `index` — "Built-in Retina Display", "DELL U2720Q" —
 *  for an options screen to list. NULL when the index does not exist. */
extern const char *SDLStatic_EngineDisplayName(int index);

/** Which display the window is on now, as a 0-based index. */
extern int SDLStatic_EngineDisplay(SDLStatic_Engine *engine);

/**
 * Move the window to another monitor.
 *
 * The window and renderer are **kept**, not recreated. Recreating them
 * would invalidate every texture the game has loaded — SDL textures belong
 * to the renderer that made them — so a monitor change would silently
 * become a full asset reload, and any game that did not know to reload
 * would draw nothing at all afterwards. Moving the window achieves the same
 * result and cannot do that: the fullscreen mode is dropped, the window is
 * repositioned on the target display, and the mode is restored.
 *
 * Returns false if the index does not name a display.
 */
extern bool SDLStatic_EngineSetDisplay(SDLStatic_Engine *engine, int index);

/** Can this renderer run the post-processing chain?
 *
 *  The effects are OpenGL shaders, and the engine asks SDL for an OpenGL
 *  renderer by default, so normally this is true. It is false when a game
 *  chose SDLSTATIC_BACKEND_NATIVE, or on a machine with no working GL at
 *  all. An options screen should grey that section out when it returns
 *  false rather than offer sliders that do nothing. */
extern bool SDLStatic_EngineEffectsAvailable(SDLStatic_Engine *engine);

/* --- budgets, turned into numbers ---------------------------------------- */

/** Multiplier for particle counts: 0, 0.25, 0.6, 1.0.
 *
 *      int count = (int)(base_count * SDLStatic_GraphicsParticleDensity(gfx.particles));
 */
extern float SDLStatic_GraphicsParticleDensity(SDLStatic_GraphicsQuality quality);

/** Light-map resolution for SDLStatic_SetLightMapScale: 0.5, 0.75, 1.0.
 *  Lighting is low-frequency, so half resolution is close to free. */
extern float SDLStatic_GraphicsLightMapScale(SDLStatic_GraphicsQuality quality);

/** How many dynamic lights to allow at once: 0, 8, 24, 64. */
extern int SDLStatic_GraphicsMaxDynamicLights(SDLStatic_GraphicsQuality quality);

/** Rays per shadow-casting light, for SDLStatic_SetLightShadowRays:
 *  0, 32, 96, 256. */
extern int SDLStatic_GraphicsShadowRays(SDLStatic_GraphicsQuality quality);

/** Penumbra width for SDLStatic_SetLightShadowSoftness: hard shadows below
 *  HIGH, because soft edges on few rays look like banding rather than
 *  softness. */
extern float SDLStatic_GraphicsShadowSoftness(SDLStatic_GraphicsQuality quality);

/** The name of a quality tier — "off", "low", "medium", "high" — for a
 *  settings screen and for the TOML writer. */
extern const char *SDLStatic_GraphicsQualityName(SDLStatic_GraphicsQuality quality);

/** Parse "off"/"low"/"medium"/"high", case-insensitively. Returns false and
 *  leaves `out` alone on anything else. */
extern bool SDLStatic_GraphicsQualityFromName(const char *name, SDLStatic_GraphicsQuality *out);

/* --- where the values come from ------------------------------------------ */

/**
 * Resolve the whole chain: defaults, then the shipped config in the media
 * archive, then `media/config.toml` in the working directory, then the same
 * file in the pref directory, then the command line. Later sources win.
 *
 * That order puts the player's saved settings above whatever the game
 * shipped with, and the command line above everything — which is what you
 * want when a player is trying to start a game that will not start.
 *
 * `org` and `app` name the pref directory (SDL_GetPrefPath). Both may be
 * NULL, in which case the pref directory is skipped. `argc`/`argv` may be
 * 0/NULL to skip the command line. Never fails: a missing or malformed
 * config file leaves the defaults in place and is reported through
 * SDLStatic_GraphicsConfigError.
 */
extern void SDLStatic_GraphicsResolve(SDLStatic_GraphicsSettings *out, int argc,
                                      char *const *argv, const char *org, const char *app);

/**
 * How Resolve reads a file out of the game's media archive.
 *
 * The engine deliberately does not link PhysFS — mounting is the game's
 * decision, and by the time settings are resolved the archive may be a zip
 * on disk, an encrypted .dat, a plain directory, or a byte array compiled
 * into the executable. So the engine asks, and the game answers:
 *
 *     static bool ReadFromVfs(const char *path, char **text, void *user) {
 *         int size = 0;
 *         unsigned char *data = SDLStatic_LoadVFSFile(path, &size);
 *         if (data == NULL) return false;
 *         *text = (char *)data;             // SDLStatic_LoadVFSFile NUL-terminates
 *         return true;
 *     }
 *     SDLStatic_GraphicsSetArchiveReader(ReadFromVfs, NULL);
 *
 * `*text` must be a NUL-terminated string the engine can SDL_free.
 * Return false when the file is not there — that is not an error.
 */
typedef bool (*SDLStatic_GraphicsReadFile)(const char *path, char **text, void *user);

/** Install the archive reader used by SDLStatic_GraphicsResolve. Pass NULL
 *  to remove it. Mount the archive before calling Resolve, or the shipped
 *  defaults will not be found. */
extern void SDLStatic_GraphicsSetArchiveReader(SDLStatic_GraphicsReadFile reader, void *user);

/** Which file SDLStatic_GraphicsResolve actually read, or NULL if none.
 *  Worth logging at startup — "why is my config being ignored" is otherwise
 *  a long afternoon. */
extern const char *SDLStatic_GraphicsConfigPath(void);

/** The last parse error, or NULL. A malformed config is not fatal, so this
 *  is how a game finds out it happened. */
extern const char *SDLStatic_GraphicsConfigError(void);

/** Overlay a TOML document onto `settings`. Only the keys present are
 *  changed, so a config file may set one value and leave the rest.
 *  Returns false on a parse error (see SDLStatic_GraphicsConfigError). */
extern bool SDLStatic_GraphicsLoadTomlString(SDLStatic_GraphicsSettings *settings,
                                             const char *toml);

/** Overlay a TOML file from the real filesystem. */
extern bool SDLStatic_GraphicsLoadTomlFile(SDLStatic_GraphicsSettings *settings,
                                           const char *path);

/**
 * Overlay command-line arguments.
 *
 *     --vsync=off --max-fps=120 --shadows=low --bloom=0.4 --render-scale=0.75
 *     --fullscreen --display=1 --window-size=1600x900 --presentation=letterbox
 *     --config=/path/to/other.toml
 *
 * Both `--key=value` and `--key value` are accepted, and booleans take
 * on/off/true/false/1/0 or may be given bare (`--vsync` means on,
 * `--no-vsync` means off). Unrecognised arguments are ignored, because the
 * game owns the command line and the engine is only a guest on it.
 *
 * Two arguments are **escape hatches** and behave differently from the
 * rest: they replace the whole settings struct rather than overlaying one
 * field, and they are applied before anything else on the line, so
 * `--with-safe-mode --bloom=0.5` means safe mode with bloom.
 *
 *     --with-default-settings   the shipped defaults, ignoring every config
 *                               file: borderless fullscreen, maximum fidelity
 *     --with-safe-mode          a resizable 1280x720 window, graphics low
 *
 * Both work when the saved settings are what is broken, which is the whole
 * point — a player should never have to reinstall a game to undo a setting.
 *
 * Returns the number of settings changed.
 */
extern int SDLStatic_GraphicsLoadArgs(SDLStatic_GraphicsSettings *settings, int argc,
                                      char *const *argv);

/** The value of `--config=PATH` in `argv`, or NULL. Resolve() uses this;
 *  it is exposed because a game may want to know. */
extern const char *SDLStatic_GraphicsArgsConfigPath(int argc, char *const *argv);

/** Serialise to TOML. Returns a SDL_malloc'd, NUL-terminated string —
 *  free it with SDL_free — or NULL on allocation failure. */
extern char *SDLStatic_GraphicsToToml(const SDLStatic_GraphicsSettings *settings);

/** Write `media/config.toml` into the pref directory, creating it as
 *  needed. This is what an options screen calls when the player presses
 *  Apply. Returns false and sets SDL_GetError() on failure. */
extern bool SDLStatic_GraphicsSave(const SDLStatic_GraphicsSettings *settings, const char *org,
                                   const char *app);

/** The path SDLStatic_GraphicsSave would write to, for a settings screen
 *  that wants to show it. Returns a SDL_malloc'd string, or NULL. */
extern char *SDLStatic_GraphicsSavePath(const char *org, const char *app);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_GRAPHICS_H */
