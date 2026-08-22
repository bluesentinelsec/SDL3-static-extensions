/**
 * @file engine_script.h
 * @brief The loop contract for scripts: hooks, or drive it yourself.
 *
 * Original SDLStatic code (zlib).
 *
 * A generated binding can call any function that takes numbers and handles.
 * What it cannot do is hand C a function pointer and a `void *user`, which
 * is exactly what the engine's hooks are — so this is the bridge, and it is
 * the only hand-written part of the script surface.
 *
 * ### Two ways to own the frame, and you pick
 *
 * **The opinionated loop** is the default and what most games should use.
 * The script registers handlers and hands the loop over; the engine does
 * the fixed tick, the interpolation, the frame limiter and the asset pump,
 * and calls back into script at the documented points:
 *
 *     -- Lua
 *     SDLStaticC.OnFixedUpdate(engine, function(step) player:move(step) end)
 *     SDLStaticC.OnRender(engine, function(alpha) draw(alpha) end)
 *     SDLStaticC.Run(engine)           -- returns when the game quits
 *
 * **Your own loop** is opt-in, for a script that wants the frame itself —
 * a tool, a test, an unusual integration. Nothing is registered; the script
 * calls the tick:
 *
 *     while SDLStaticC.EngineTick(engine) do
 *       -- everything between frames is yours
 *     end
 *
 * The contract is that simple: **if you registered handlers, call Run; if
 * you did not, call EngineTick yourself.** Both drive the same loop —
 * `Run` is a loop around `EngineTick` — so the fixed timestep, the
 * interpolation alpha and the frame pacing are identical either way. What
 * differs is only who owns the `while`.
 *
 * Mixing them is refused rather than half-working: registering a handler
 * and then driving the loop by hand would call the handlers anyway, from a
 * place the script did not expect. See SDLStatic_ScriptHasHandlers.
 */
#ifndef SDLSTATIC_ENGINE_SCRIPT_H
#define SDLSTATIC_ENGINE_SCRIPT_H

#include <SDLStatic/engine.h>
#include <SDLStatic/engine_scene.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Which hook a registration is for. */
typedef enum SDLStatic_ScriptHook
{
    SDLSTATIC_HOOK_LOAD = 0,
    SDLSTATIC_HOOK_FIXED_UPDATE,
    SDLSTATIC_HOOK_UPDATE,
    SDLSTATIC_HOOK_RENDER,
    SDLSTATIC_HOOK_POST_RENDER,
    SDLSTATIC_HOOK_UNLOAD,
    SDLSTATIC_HOOK_COUNT
} SDLStatic_ScriptHook;

/**
 * How the bridge calls back into a language.
 *
 * One function pointer per language, installed once by that language's
 * binding layer. `handle` is whatever the language used to remember the
 * script function — a Lua registry reference, an mruby object — and is
 * opaque here: this file deliberately knows nothing about either language,
 * so adding a third costs one dispatcher and no changes to the engine.
 *
 * `value` carries the hook's argument: the step for a fixed update, the
 * delta for an update, the alpha for a render, and nothing for the rest.
 * The return value is only read for LOAD, where false aborts start-up.
 */
typedef bool (*SDLStatic_ScriptDispatch)(void *language_state, Sint64 handle,
                                         SDLStatic_ScriptHook hook, float value);

/** Release a handle when the engine is done with it, so the language can
 *  drop its reference and let the script function be collected. */
typedef void (*SDLStatic_ScriptRelease)(void *language_state, Sint64 handle);

/**
 * Install the bridge for a language. Called by that language's binding
 * layer, not by a game.
 *
 * One language at a time per engine: a game embedding both Lua and Ruby
 * gives each its own engine, which is also the only arrangement in which
 * "who owns the loop" has an answer.
 */
extern bool SDLStatic_ScriptBind(SDLStatic_Engine *engine, void *language_state,
                                 SDLStatic_ScriptDispatch dispatch,
                                 SDLStatic_ScriptRelease release);

/** Register a script function for a hook, replacing any previous one. The
 *  previous handle is released. */
extern bool SDLStatic_ScriptSetHook(SDLStatic_Engine *engine, SDLStatic_ScriptHook hook,
                                    Sint64 handle);

/** Has the script registered anything? What SDLStatic_ScriptRun checks, and
 *  what tells a script whether it is in "engine drives" or "I drive" mode. */
extern bool SDLStatic_ScriptHasHandlers(SDLStatic_Engine *engine);

/**
 * Hand the loop to the engine, dispatching to the registered handlers.
 *
 * Returns false — without running — if nothing is registered, because a
 * script that called Run with no handlers has almost certainly forgotten
 * to register them, and a silent black window is a worse answer than an
 * error.
 */
extern bool SDLStatic_ScriptRun(SDLStatic_Engine *engine);

/** Drop every handler and the bridge. Called when a script state goes
 *  away, so the engine stops calling into a dead interpreter. */
extern void SDLStatic_ScriptUnbind(SDLStatic_Engine *engine);

/* --- scenes ---------------------------------------------------------------- */

/**
 * ### Scenes from a script
 *
 * A scene is defined by its callbacks — that is the whole of what makes a
 * title screen different from a level — so unlike the other definitions in
 * this engine, a builder alone would produce a scene that does nothing.
 * It needs the same bridge the game hooks got, one level down.
 *
 * A script defines a scene **by name**, once, and then pushes it by that
 * name:
 *
 *     SDLStaticC.SceneDefine(engine, "level")
 *     SDLStaticC.SceneOn(engine, "level", "load",  function(scene) ... end)
 *     SDLStaticC.SceneOn(engine, "level", "render", function(scene, alpha) ... end)
 *     SDLStaticC.ScriptScenePush(engine, "level")
 *
 * The name is the identity, not a pointer, which is what makes this work
 * from a script at all: the engine copies a definition when it pushes one,
 * so a C game may pass a local and forget it, while a script has nowhere to
 * keep a struct in the first place. A name outlives both.
 *
 * Every callback receives the scene, so one definition can back several
 * live scenes and tell them apart — a script keeps per-scene data in a
 * table keyed by the scene, the way C uses SDLStatic_SceneState.
 */

/** Which scene callback a registration is for; mirrors SDLStatic_SceneDef. */
typedef enum SDLStatic_SceneHook
{
    SDLSTATIC_SCENE_HOOK_LOAD = 0,
    SDLSTATIC_SCENE_HOOK_ENTER,
    SDLSTATIC_SCENE_HOOK_FIXED_UPDATE,
    SDLSTATIC_SCENE_HOOK_UPDATE,
    SDLSTATIC_SCENE_HOOK_RENDER,
    SDLSTATIC_SCENE_HOOK_EVENT,
    SDLSTATIC_SCENE_HOOK_EXIT,
    SDLSTATIC_SCENE_HOOK_UNLOAD,
    SDLSTATIC_SCENE_HOOK_COUNT
} SDLStatic_SceneHook;

/**
 * How the bridge calls a scene callback back into a language.
 *
 * Separate from SDLStatic_ScriptDispatch because a scene callback carries
 * more: which scene it is for, and — for the event hook — the event. Only
 * LOAD's return value is read, where false aborts the push.
 */
typedef bool (*SDLStatic_ScriptSceneDispatch)(void *language_state, Sint64 handle,
                                              SDLStatic_SceneHook hook,
                                              SDLStatic_Scene *scene, float value,
                                              const SDL_Event *event);

/** Install the scene dispatcher. Called by a language's binding layer
 *  alongside SDLStatic_ScriptBind. */
extern bool SDLStatic_ScriptSetSceneDispatch(SDLStatic_Engine *engine,
                                             SDLStatic_ScriptSceneDispatch dispatch);

/** Begin (or reset) a scene definition under this name. Defining a name
 *  that already exists releases its handlers and starts over, so reloading
 *  a script does not accumulate stale closures. */
extern bool SDLStatic_ScriptSceneDefine(SDLStatic_Engine *engine, const char *name);

/** Register a script function for one of the scene's callbacks. */
extern bool SDLStatic_ScriptSceneSetHook(SDLStatic_Engine *engine, const char *name,
                                         SDLStatic_SceneHook hook, Sint64 handle);

/** Set the scene's flags — transparent, or updating while covered. */
extern bool SDLStatic_ScriptSceneSetFlags(SDLStatic_Engine *engine, const char *name,
                                          SDLStatic_SceneFlags flags);

/** How many bytes of engine-owned state the scene wants. Scripts usually
 *  leave this at zero and keep state on their own side, keyed by the scene;
 *  it is here so a script can hand the same scene to C code that expects
 *  SDLStatic_SceneState to work. */
extern bool SDLStatic_ScriptSceneSetStateSize(SDLStatic_Engine *engine, const char *name,
                                              int state_size);

/**
 * A stable key for one live scene, for a script to index its own state by.
 *
 * The obvious thing — using the scene itself as a table key — does not
 * work, and fails quietly: a handle crossing into a script is boxed fresh
 * each time it is passed, so the same scene arrives as a different key
 * every frame and a table of per-scene state grows without bound. This
 * returns the identity underneath the box.
 *
 *     local state = {}
 *     SDLStaticC.SceneOn(engine, "room", "update", function(scene, dt)
 *       local key = SDLStaticC.SceneKey(scene)
 *       state[key] = (state[key] or 0) + dt
 *     end)
 *
 * Valid until the scene is destroyed, and not reused while it lives. It is
 * the scene's address, so do not persist it — across a save, or a run, it
 * means nothing.
 */
extern Sint64 SDLStatic_SceneKey(SDLStatic_Scene *scene);

/** Is a definition registered under this name? */
extern bool SDLStatic_ScriptSceneDefined(SDLStatic_Engine *engine, const char *name);

/* The stack operations, by name. Each mirrors the SDLStatic_Scene* call of
   the same shape and defers in exactly the same way. */
extern bool SDLStatic_ScriptScenePush(SDLStatic_Engine *engine, const char *name);
extern bool SDLStatic_ScriptSceneReplace(SDLStatic_Engine *engine, const char *name);
extern bool SDLStatic_ScriptSceneReset(SDLStatic_Engine *engine, const char *name);
extern bool SDLStatic_ScriptSceneTransitionTo(SDLStatic_Engine *engine, const char *name,
                                              SDLStatic_SceneTransition transition,
                                              float seconds);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_SCRIPT_H */
