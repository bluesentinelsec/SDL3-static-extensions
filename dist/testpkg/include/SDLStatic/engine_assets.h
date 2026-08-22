/**
 * @file engine_assets.h
 * @brief Loading assets: blocking when you want it, streamed when you don't.
 *
 * Original SDLStatic code (zlib).
 *
 * Assets come out of the mounted media archive (see engine_media.h), so a
 * path means the same thing whether the game is running against a
 * directory, a zip, or bytes compiled into the binary:
 *
 *     SDLStatic_TextureId hero = SDLStatic_LoadTexture(engine, "sprites/hero.png");
 *     sprite.texture = SDLStatic_Texture(engine, hero);
 *
 * ### Two ways in, because games need both
 *
 * `SDLStatic_LoadTexture` **blocks** until the asset is there. That is what
 * you want at start-up, in a `load` hook, or anywhere the next line of code
 * genuinely cannot proceed without the thing.
 *
 * `SDLStatic_LoadTextureAsync` returns a handle immediately and loads on a
 * worker thread. That is what you want for a level that should keep running
 * — a loading screen with a progress bar, or an open world streaming in
 * what the player is walking towards.
 *
 * Both return the same kind of handle and share one cache, so a path
 * already loaded synchronously is instant when asked for asynchronously,
 * and the other way round.
 *
 * ### The cache is by path, and counted
 *
 * Asking twice for the same path gives the same handle and loads once —
 * which matters more than it sounds, because forty actors of the same type
 * asking for the same sprite is the normal case, not an edge case.
 * Handles are reference counted; the last release frees the asset.
 *
 * ### Why the main thread still does some work
 *
 * Decoding a PNG is pure computation and happens on a worker. Creating an
 * `SDL_Texture` from the result is not: it touches the renderer, and SDL's
 * renderer belongs to the thread that made it. So the pipeline is
 *
 *     worker:  read from the VFS, decode  ->  SDL_Surface
 *     main:    SDL_CreateTextureFromSurface  ->  SDL_Texture
 *
 * and the main-thread half is **time-sliced**: the engine spends at most a
 * budget per frame turning decoded surfaces into textures, then stops until
 * next frame. Without that, a batch of forty textures finishing together
 * uploads forty textures in one frame and the game visibly hitches at
 * exactly the moment a loading bar is supposed to be reassuring somebody.
 * Godot and Unity both time-slice the same step for the same reason.
 */
#ifndef SDLSTATIC_ENGINE_ASSETS_H
#define SDLSTATIC_ENGINE_ASSETS_H

#include <SDLStatic/engine.h>

#ifdef __cplusplus
extern "C" {
#endif

/** A handle to a loaded asset. Zero is "nothing", and never resolves. */
typedef Uint32 SDLStatic_TextureId;

#ifdef __cplusplus
#define SDLSTATIC_ASSET_NONE (static_cast<SDLStatic_TextureId>(0))
#else
#define SDLSTATIC_ASSET_NONE ((SDLStatic_TextureId)0)
#endif

/** Where an asset is in its life. */
typedef enum SDLStatic_AssetStatus
{
    SDLSTATIC_ASSET_MISSING = 0, /**< no such handle */
    SDLSTATIC_ASSET_QUEUED,      /**< asked for, not started */
    SDLSTATIC_ASSET_LOADING,     /**< a worker is decoding it */
    SDLSTATIC_ASSET_DECODED,     /**< decoded, waiting for the main thread */
    SDLSTATIC_ASSET_READY,
    /** Could not be loaded: absent from the archive, or not an image. Not
     *  fatal — the handle stays valid and resolves to the placeholder, so a
     *  missing file costs a wrong-looking sprite rather than a crash. */
    SDLSTATIC_ASSET_FAILED
} SDLStatic_AssetStatus;

/* --- loading ------------------------------------------------------------- */

/** Load a texture, **blocking** until it is there. Returns
 *  SDLSTATIC_ASSET_NONE only if the engine has no renderer; a missing file
 *  gives a valid handle whose status is FAILED. */
extern SDLStatic_TextureId SDLStatic_LoadTexture(SDLStatic_Engine *engine, const char *path);

/** Ask for a texture without waiting. The handle is usable immediately;
 *  SDLStatic_Texture returns the placeholder until it is ready. */
extern SDLStatic_TextureId SDLStatic_LoadTextureAsync(SDLStatic_Engine *engine,
                                                      const char *path);

/**
 * The texture behind a handle.
 *
 * Never NULL for a valid handle: an asset that is still loading, or that
 * failed, resolves to the **placeholder** — a magenta and black check,
 * chosen because it is impossible to mistake for art and impossible to
 * miss in a screenshot. A game may draw it without checking, and a missing
 * file looks obviously wrong rather than invisibly absent.
 */
extern SDL_Texture *SDLStatic_Texture(SDLStatic_Engine *engine, SDLStatic_TextureId id);

extern SDLStatic_AssetStatus SDLStatic_AssetStatusOf(SDLStatic_Engine *engine,
                                                     SDLStatic_TextureId id);

/** The path a handle was loaded from, for logging. NULL if unknown. */
extern const char *SDLStatic_AssetPath(SDLStatic_Engine *engine, SDLStatic_TextureId id);

/** Keep a handle alive past the release below — for a second owner. */
extern void SDLStatic_AssetRetain(SDLStatic_Engine *engine, SDLStatic_TextureId id);

/** Drop a reference. The asset is freed when the last one goes, so a level
 *  that releases what it loaded gets its memory back without the engine
 *  guessing when. */
extern void SDLStatic_AssetRelease(SDLStatic_Engine *engine, SDLStatic_TextureId id);

/* --- watching a load ----------------------------------------------------- */

/** Is everything asked for so far finished — successfully or not? What a
 *  loading screen waits on. */
extern bool SDLStatic_AssetsReady(SDLStatic_Engine *engine);

/** How far through, 0..1. Counts assets rather than bytes, which is what a
 *  progress bar can actually be driven by without knowing sizes up front.
 *  Returns 1.0 when there is nothing outstanding. */
extern float SDLStatic_AssetsProgress(SDLStatic_Engine *engine);

/** How many are still in flight. */
extern int SDLStatic_AssetsPending(SDLStatic_Engine *engine);

/** How many are loaded and resident. */
extern int SDLStatic_AssetsLoaded(SDLStatic_Engine *engine);

/** Block until everything outstanding has landed. For the end of a loading
 *  screen, or a test. */
extern void SDLStatic_AssetsWait(SDLStatic_Engine *engine);

/* --- tuning -------------------------------------------------------------- */

/**
 * Milliseconds per frame the engine may spend turning decoded pixels into
 * textures. 2 ms by default — about an eighth of a 60 Hz frame.
 *
 * Raise it on a loading screen, where there is nothing else to spend the
 * frame on and finishing sooner is the whole point; leave it low during
 * gameplay, where a hitch is worse than a late texture. Zero finalises
 * exactly one asset per frame; a negative value finalises everything
 * immediately and will hitch.
 */
extern void SDLStatic_AssetsSetFrameBudget(SDLStatic_Engine *engine, float milliseconds);
extern float SDLStatic_AssetsFrameBudget(SDLStatic_Engine *engine);

/** How many worker threads decode. Defaults to two, which is enough to
 *  keep ahead of the main thread's upload budget without competing with
 *  the game for cores. Clamped to [1, 8]; set before the first load. */
extern void SDLStatic_AssetsSetWorkers(SDLStatic_Engine *engine, int workers);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_ASSETS_H */
