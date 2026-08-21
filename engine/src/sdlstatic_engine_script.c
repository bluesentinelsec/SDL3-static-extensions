/*
 * sdlstatic_engine_script.c — the loop contract for scripts.
 * Original SDLStatic code (zlib).
 *
 * The generator can bind anything taking numbers and handles. It cannot
 * hand C a function pointer and a void* — which is what a hook is — so this
 * is the bridge, and it is the only hand-written part of the script
 * surface.
 *
 * It deliberately knows nothing about Lua or mruby. A language installs one
 * dispatch function and one release function; everything else here is an
 * opaque Sint64 the language chose to mean "this script function". Adding a
 * third language costs a dispatcher and no changes to this file or to the
 * engine.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_script.h>

struct SDLStatic_ScriptBridge
{
    void *language_state;
    SDLStatic_ScriptDispatch dispatch;
    SDLStatic_ScriptRelease release;

    Sint64 handles[SDLSTATIC_HOOK_COUNT];
    bool registered[SDLSTATIC_HOOK_COUNT];

    SDLStatic_GameHooks hooks;
};

static struct SDLStatic_ScriptBridge *Bridge(SDLStatic_Engine *engine, bool create)
{
    if (engine == NULL)
    {
        return NULL;
    }
    if (engine->script == NULL && create)
    {
        engine->script = (struct SDLStatic_ScriptBridge *)SDL_calloc(
            1, sizeof(struct SDLStatic_ScriptBridge));
    }
    return engine->script;
}

/* One trampoline per hook. Each is the C function pointer the engine wants,
   and each does the same thing: look up the script handle for its hook and
   ask the language to call it. */
static bool Call(SDLStatic_Engine *engine, SDLStatic_ScriptHook hook, float value)
{
    struct SDLStatic_ScriptBridge *bridge = Bridge(engine, false);
    if (bridge == NULL || bridge->dispatch == NULL || !bridge->registered[hook])
    {
        return true;
    }
    return bridge->dispatch(bridge->language_state, bridge->handles[hook], hook, value);
}

static bool OnLoad(void *user)
{
    return Call((SDLStatic_Engine *)user, SDLSTATIC_HOOK_LOAD, 0.0f);
}
static void OnFixedUpdate(void *user, float step)
{
    Call((SDLStatic_Engine *)user, SDLSTATIC_HOOK_FIXED_UPDATE, step);
}
static void OnUpdate(void *user, float dt)
{
    Call((SDLStatic_Engine *)user, SDLSTATIC_HOOK_UPDATE, dt);
}
static void OnRender(void *user, float alpha)
{
    Call((SDLStatic_Engine *)user, SDLSTATIC_HOOK_RENDER, alpha);
}
static void OnPostRender(void *user)
{
    Call((SDLStatic_Engine *)user, SDLSTATIC_HOOK_POST_RENDER, 0.0f);
}
static void OnUnload(void *user)
{
    Call((SDLStatic_Engine *)user, SDLSTATIC_HOOK_UNLOAD, 0.0f);
}

/* Publish only the hooks the script actually registered. A null C pointer
   means "no hook", so an unregistered one costs nothing per frame rather
   than a dispatch that finds nothing to call. */
static void Publish(SDLStatic_Engine *engine, struct SDLStatic_ScriptBridge *bridge)
{
    SDL_zero(bridge->hooks);
    if (bridge->registered[SDLSTATIC_HOOK_LOAD])
    {
        bridge->hooks.load = OnLoad;
    }
    if (bridge->registered[SDLSTATIC_HOOK_FIXED_UPDATE])
    {
        bridge->hooks.fixed_update = OnFixedUpdate;
    }
    if (bridge->registered[SDLSTATIC_HOOK_UPDATE])
    {
        bridge->hooks.update = OnUpdate;
    }
    if (bridge->registered[SDLSTATIC_HOOK_RENDER])
    {
        bridge->hooks.render = OnRender;
    }
    if (bridge->registered[SDLSTATIC_HOOK_POST_RENDER])
    {
        bridge->hooks.post_render = OnPostRender;
    }
    if (bridge->registered[SDLSTATIC_HOOK_UNLOAD])
    {
        bridge->hooks.unload = OnUnload;
    }
    /* The engine is its own user pointer: the trampolines need to find the
       bridge, and the engine is the one thing they are guaranteed to be
       given. */
    SDLStatic_EngineSetHooks(engine, &bridge->hooks, engine);
}

bool SDLStatic_ScriptBind(SDLStatic_Engine *engine, void *language_state,
                          SDLStatic_ScriptDispatch dispatch, SDLStatic_ScriptRelease release)
{
    struct SDLStatic_ScriptBridge *bridge = Bridge(engine, true);
    if (bridge == NULL || dispatch == NULL)
    {
        SDL_InvalidParamError("engine/dispatch");
        return false;
    }
    /* Binding the same state again is a no-op, not a reset. A language's
       registration helper calls this on every OnUpdate/OnRender, and
       unbinding each time would release the handler registered a moment
       ago — leaving only whichever hook was registered last, which is a
       bug that looks exactly like "hooks do not fire". */
    if (bridge->dispatch == dispatch && bridge->language_state == language_state)
    {
        return true;
    }

    /* A genuinely different language state does reset, so the outgoing one
       does not leak the references it was holding. */
    SDLStatic_ScriptUnbind(engine);
    bridge = Bridge(engine, true);
    if (bridge == NULL)
    {
        return false;
    }
    bridge->language_state = language_state;
    bridge->dispatch = dispatch;
    bridge->release = release;
    return true;
}

bool SDLStatic_ScriptSetHook(SDLStatic_Engine *engine, SDLStatic_ScriptHook hook, Sint64 handle)
{
    struct SDLStatic_ScriptBridge *bridge = Bridge(engine, false);
    if (bridge == NULL || bridge->dispatch == NULL || hook >= SDLSTATIC_HOOK_COUNT)
    {
        SDL_SetError("no script bound to this engine");
        return false;
    }
    if (bridge->registered[hook] && bridge->release != NULL)
    {
        /* Replacing a handler releases the old handle, so re-registering in
           a loop does not pin every previous closure alive. */
        bridge->release(bridge->language_state, bridge->handles[hook]);
    }
    bridge->handles[hook] = handle;
    bridge->registered[hook] = true;
    Publish(engine, bridge);
    return true;
}

bool SDLStatic_ScriptHasHandlers(SDLStatic_Engine *engine)
{
    struct SDLStatic_ScriptBridge *bridge = Bridge(engine, false);
    if (bridge == NULL)
    {
        return false;
    }
    for (int i = 0; i < SDLSTATIC_HOOK_COUNT; ++i)
    {
        if (bridge->registered[i])
        {
            return true;
        }
    }
    return false;
}

bool SDLStatic_ScriptRun(SDLStatic_Engine *engine)
{
    struct SDLStatic_ScriptBridge *bridge = Bridge(engine, false);
    if (bridge == NULL || !SDLStatic_ScriptHasHandlers(engine))
    {
        /* A script that calls Run with nothing registered has almost
           certainly forgotten to register, and a silent black window is a
           worse answer than an error. */
        SDL_SetError("no handlers registered: register one, or drive the loop "
                     "yourself with EngineTick");
        return false;
    }
    Publish(engine, bridge);
    return SDLStatic_RunGame(engine, &bridge->hooks, engine);
}

void SDLStatic_ScriptUnbind(SDLStatic_Engine *engine)
{
    struct SDLStatic_ScriptBridge *bridge = Bridge(engine, false);
    if (bridge == NULL)
    {
        return;
    }
    if (bridge->release != NULL)
    {
        for (int i = 0; i < SDLSTATIC_HOOK_COUNT; ++i)
        {
            if (bridge->registered[i])
            {
                bridge->release(bridge->language_state, bridge->handles[i]);
            }
        }
    }
    /* Detach from the engine before freeing: a hook still pointing at freed
       memory is exactly the crash this whole file exists to avoid. */
    SDLStatic_EngineSetHooks(engine, NULL, NULL);
    SDL_free(bridge);
    engine->script = NULL;
}
