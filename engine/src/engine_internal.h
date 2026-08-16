/*
 * engine_internal.h — shared between the engine's translation units.
 *
 * The engine is one library but several subsystems: the loop
 * (sdlstatic_engine.c) and the scene stack (sdlstatic_engine_scene.c) so
 * far. They share the engine object, which lives here rather than in the
 * public header because a game has no business knowing its layout.
 */
#ifndef SDLSTATIC_ENGINE_INTERNAL_H
#define SDLSTATIC_ENGINE_INTERNAL_H

#include <SDLStatic/engine.h>
#include <SDLStatic/engine_graphics.h>
#include <SDLStatic/engine_scene.h>

#define NS_PER_SECOND 1000000000ull

struct SDLStatic_PostFX;

struct SDLStatic_Engine
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *headless_surface; /* owned by us: see DestroyEngine */

    int design_width, design_height;   /* the reference space */
    float view_width, view_height;     /* what is actually visible */
    SDLStatic_EnginePresentation presentation;
    SDL_FColor clear_color;

    /* Timing. All internal time is nanoseconds; the API speaks seconds. */
    Uint64 step_ns;         /* one simulation step */
    Uint64 accumulator_ns;  /* unsimulated time carried between frames */
    Uint64 last_ns;         /* clock reading at the start of the last frame */
    Uint64 refresh_ns;      /* display period, 0 if unknown */
    Uint64 max_frame_ns;    /* longer than this is a stall */
    Uint64 manual_ns;       /* the injected clock, when manual */
    bool manual_clock;

    int tick_rate;
    int max_steps;
    int max_fps;          /* 0 = follow the display, <0 = no limiter */
    Uint64 frame_start_ns; /* for the limiter */
    SDLStatic_EngineInterpolation interpolation;
    float time_scale;

    float delta_seconds;
    float alpha;
    int steps_last_frame;
    int overload_frames;
    Uint64 frame_count;

    /* A short moving average, so a debug overlay does not flicker. */
    float fps;
    float fps_accumulator;
    int fps_frames;

    bool running;
    const SDLStatic_GameHooks *hooks;
    void *user;

    /* Allocated on first use, so a game that never touches scenes pays
       nothing for them. */
    struct SDLStatic_SceneStack *scenes;

    /* Graphics settings, and the offscreen frame the render-scale and
       post-processing paths share. Both want the frame in a texture rather
       than in the backbuffer, so there is only ever one. */
    SDLStatic_GraphicsSettings graphics;
    SDL_Texture *frame_target;
    int frame_target_w, frame_target_h;
    bool frame_target_active; /* set between Begin and End, so End knows */
    struct SDLStatic_PostFX *postfx;
    bool postfx_failed; /* tried once, could not: do not try every frame */
};

/* --- graphics ------------------------------------------------------------ */

/** Push engine->graphics.filter to the renderer's default scale mode. */
extern void SDLStatic_EngineApplyFilter(SDLStatic_Engine *engine);

/** Redirect rendering into the offscreen frame when the settings need one
 *  (render scale below native, or any post-effect enabled). No-op
 *  otherwise, so a game using neither pays nothing. */
extern void SDLStatic_EngineBeginFrameTarget(SDLStatic_Engine *engine);

/** Composite the offscreen frame back to the window, then run the
 *  post-processing chain over the result. Always called, because the chain
 *  applies whether or not a target was used. */
extern void SDLStatic_EngineEndFrameTarget(SDLStatic_Engine *engine);

/** True when the renderer can run the post-processing shaders (OpenGL or
 *  OpenGL ES) and at least one effect is enabled. */
extern bool SDLStatic_EnginePostFXAvailable(SDLStatic_Engine *engine);

/** Drop cached shader state after a settings change. */
extern void SDLStatic_EnginePostFXInvalidate(SDLStatic_Engine *engine);

/** Run the effect chain over the frame currently in the framebuffer.
 *  Returns false when the chain could not run, in which case the frame is
 *  simply left as it was drawn. */
extern bool SDLStatic_EnginePostFXPresent(SDLStatic_Engine *engine);

extern void SDLStatic_EnginePostFXDestroy(SDLStatic_Engine *engine);

extern void SDLStatic_EngineDestroyFrameTarget(SDLStatic_Engine *engine);

/* --- scene stack, driven by the loop ------------------------------------ */

/** Dispatch a simulation step to the scene stack. */
extern void SDLStatic_SceneDispatchFixedUpdate(SDLStatic_Engine *engine, float step);

/** Dispatch a per-frame update, and advance any transition in progress. */
extern void SDLStatic_SceneDispatchUpdate(SDLStatic_Engine *engine, float dt);

/** Draw the stack, bottom-up from the lowest visible scene, then the
 *  transition overlay if one is running. */
extern void SDLStatic_SceneDispatchRender(SDLStatic_Engine *engine, float alpha);

/** Give an event to the top scene. */
extern void SDLStatic_SceneDispatchEvent(SDLStatic_Engine *engine, const SDL_Event *event);

/** Tear the whole stack down, top first. Called when the engine is
 *  destroyed so scenes always see their exit and unload hooks. */
extern void SDLStatic_SceneShutdown(SDLStatic_Engine *engine);

#endif /* SDLSTATIC_ENGINE_INTERNAL_H */
