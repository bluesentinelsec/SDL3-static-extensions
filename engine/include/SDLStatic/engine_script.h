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

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_SCRIPT_H */
