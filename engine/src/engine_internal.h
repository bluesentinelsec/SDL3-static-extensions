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
#include <SDLStatic/engine_media.h>
#include <SDLStatic/engine_input.h>
#include <SDLStatic/engine_light.h>
#include <SDLStatic/engine_render.h>
#include <SDLStatic/engine_scene.h>

#define NS_PER_SECOND 1000000000ull

struct SDLStatic_PostFX;
struct SDLStatic_ActorWorld;
struct SDLStatic_DrawItem;
struct SDLStatic_Input;
struct SDLStatic_Physics;
struct SDLStatic_Assets;
struct SDLStatic_EngineLight;
struct SDLStatic_Saves;
struct SDLStatic_Text;
struct SDLStatic_ScriptBridge;

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

    SDLStatic_MediaSource media_source;
    char media_path[512];

    /* Allocated on first spawn, so a game that never uses actors pays
       nothing for them. */
    struct SDLStatic_ActorWorld *actors;

    /* The draw list: grown once and reused, because this runs every frame
       and possibly once per camera. */
    struct SDLStatic_DrawItem *draw_list;
    int draw_capacity;
    SDLStatic_RenderStats render_stats;

    struct SDLStatic_Input *input;
    struct SDLStatic_Physics *physics;
    struct SDLStatic_Assets *assets;
    struct SDLStatic_EngineLight *light;
    struct SDLStatic_Saves *saves;
    struct SDLStatic_Text *text;
    struct SDLStatic_ScriptBridge *script;
};

extern void SDLStatic_EngineSavesDestroy(SDLStatic_Engine *engine);
extern void SDLStatic_EngineTextDestroy(SDLStatic_Engine *engine);

/* --- lighting ------------------------------------------------------------ */

/** Advance the day/night clock. Per-frame, because a cycle is scenery. */
extern void SDLStatic_EngineLightUpdate(SDLStatic_Engine *engine, float dt);
extern void SDLStatic_EngineLightDestroy(SDLStatic_Engine *engine);

/** The actor's attached light, as with the sprite. */
extern SDLStatic_LightDef *SDLStatic_ActorLightSlot(SDLStatic_Actor *actor, bool create);
extern void SDLStatic_ActorLightRemove(SDLStatic_Actor *actor);


/* --- assets -------------------------------------------------------------- */

/** Turn decoded surfaces into textures, within this frame's time budget.
 *  Main thread only: SDL's renderer belongs to the thread that made it. */
extern void SDLStatic_EngineAssetsPump(SDLStatic_Engine *engine);
extern void SDLStatic_EngineAssetsDestroy(SDLStatic_Engine *engine);

/* --- physics ------------------------------------------------------------- */

/** Advance the world one fixed step and write the results onto actors. */
extern void SDLStatic_EnginePhysicsStep(SDLStatic_Engine *engine, float step);
extern void SDLStatic_EnginePhysicsDestroy(SDLStatic_Engine *engine);

/** A Box2D body handle, stored on the actor as its three fields so that the
 *  actor system needs no Box2D header. */
extern void SDLStatic_ActorSetBody(SDLStatic_Actor *actor, int index, Uint16 world,
                                   Uint16 generation, float offset_x, float offset_y);
extern bool SDLStatic_ActorGetBody(SDLStatic_Actor *actor, int *index, Uint16 *world,
                                   Uint16 *generation, float *offset_x, float *offset_y);
extern void SDLStatic_ActorClearBody(SDLStatic_Actor *actor);

/* --- input --------------------------------------------------------------- */

extern bool SDLStatic_EngineInputInit(SDLStatic_Engine *engine);
extern void SDLStatic_EngineInputDestroy(SDLStatic_Engine *engine);

/** Adopt controllers that were already plugged in at startup: they do not
 *  all produce an ADDED event. */
extern void SDLStatic_EngineInputOpenGamepads(SDLStatic_Engine *engine);

/** Snapshot last frame's state; edges are the difference. */
extern void SDLStatic_EngineInputBeginFrame(SDLStatic_Engine *engine);

/** Fold one SDL event into the state table. */
extern void SDLStatic_EngineInputEvent(SDLStatic_Engine *engine, const SDL_Event *event);

/** Sample the things that are polled rather than evented — stick axes —
 *  and advance the menu-repeat clocks. */
extern void SDLStatic_EngineInputEndFrame(SDLStatic_Engine *engine, float dt);

/* Small hooks the binding layer uses. */
extern bool SDLStatic_InputKeyDownRaw(SDLStatic_Engine *engine, int scancode);
extern int SDLStatic_InputFirstPressedKey(SDLStatic_Engine *engine);

/* --- rendering ----------------------------------------------------------- */

/** The actor's sprite storage. `create` gives it one if it has none. */
extern SDLStatic_Sprite *SDLStatic_ActorSpriteSlot(SDLStatic_Actor *actor, bool create);

/** Forget the actor's sprite. */
extern void SDLStatic_ActorSpriteRemove(SDLStatic_Actor *actor);

/** Free the draw list with the engine. */
extern void SDLStatic_RenderDestroy(SDLStatic_Engine *engine);

/* --- actors, driven by the loop ------------------------------------------ */

/** Snapshot transforms for interpolation, then run one simulation step. */
extern void SDLStatic_ActorDispatchFixedUpdate(SDLStatic_Engine *engine, float step);

/** Per-frame cosmetic update. */
extern void SDLStatic_ActorDispatchUpdate(SDLStatic_Engine *engine, float dt);

/** Drain the message queue, once, after the updates. */
extern void SDLStatic_ActorDeliverMessages(SDLStatic_Engine *engine);

/** Admit spawned actors and free destroyed ones, at the end of the frame. */
extern void SDLStatic_ActorApplyPending(SDLStatic_Engine *engine);

/** Free the world with the engine. */
extern void SDLStatic_ActorWorldDestroy(SDLStatic_Engine *engine);

/* --- media --------------------------------------------------------------- */

/** Run the mount search and record what it found on the engine. */
extern void SDLStatic_EngineMountMedia(SDLStatic_Engine *engine, const char *explicit_path,
                                       int argc, char *const *argv);

/** Point the settings resolver at the mounted archive, so a game's shipped
 *  config.toml is found wherever it lives. */
extern void SDLStatic_EngineInstallConfigReader(void);

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
