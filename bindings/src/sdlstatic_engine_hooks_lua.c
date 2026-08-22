/*
 * sdlstatic_engine_hooks_lua.c — registering Lua functions as engine hooks.
 * Original SDLStatic code (zlib).
 *
 * The generator binds anything taking numbers and handles. It cannot turn a
 * Lua function into a C function pointer, so this is the glue, and it is
 * deliberately tiny: the engine's bridge (engine_script.h) does the
 * dispatching and knows nothing about Lua; this file only converts a Lua
 * value into a handle the bridge can hold, and back again.
 *
 * A handle is a luaL_ref into the registry. That is the only way to keep a
 * Lua function alive across a C callback — a value left on the stack is
 * gone by the time the engine calls back, and one held only by a local is
 * collected.
 */
#include <SDLStatic/engine.h>
#include <SDLStatic/engine_script.h>
#include <SDLStatic/engine_scene.h>
#include <SDLStatic/lua.h>

#include <lauxlib.h>
#include <lua.h>

#include "gen_support_lua.h"

/* The bridge hands back whatever we gave it. Going through the registry
   means the reference survives garbage collection for exactly as long as
   the engine holds it. */
static bool DispatchLua(void *language_state, Sint64 handle, SDLStatic_ScriptHook hook,
                        float value)
{
    lua_State *L = (lua_State *)language_state;
    lua_rawgeti(L, LUA_REGISTRYINDEX, (lua_Integer)handle);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return true;
    }

    /* Only the hooks that carry a number take an argument; the rest are
       called with none, so a script writes `function() ... end` for them
       rather than ignoring a meaningless zero. */
    int args = 0;
    if (hook == SDLSTATIC_HOOK_FIXED_UPDATE || hook == SDLSTATIC_HOOK_UPDATE ||
        hook == SDLSTATIC_HOOK_RENDER)
    {
        lua_pushnumber(L, (lua_Number)value);
        args = 1;
    }

    if (lua_pcall(L, args, 1, 0) != LUA_OK)
    {
        /* An error in a hook must not unwind through the engine's C frames.
           Report it and carry on, so one bad frame does not take the game
           down mid-loop. */
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "engine hook: %s",
                     lua_tostring(L, -1) ? lua_tostring(L, -1) : "error");
        lua_pop(L, 1);
        return true;
    }

    /* Only `load` reads a result: returning false there aborts start-up.
       Everywhere else the return is ignored, so a script may end a handler
       with an expression without meaning anything by it. */
    bool ok = true;
    if (hook == SDLSTATIC_HOOK_LOAD && !lua_isnil(L, -1))
    {
        ok = lua_toboolean(L, -1) != 0;
    }
    lua_pop(L, 1);
    return ok;
}

static void ReleaseLua(void *language_state, Sint64 handle)
{
    luaL_unref((lua_State *)language_state, LUA_REGISTRYINDEX, (int)handle);
}

/* SDLStaticC.OnFixedUpdate(engine, function(step) ... end) and friends. */
static int SetHook(lua_State *L, SDLStatic_ScriptHook hook)
{
    /* The generated bindings box a handle in a userdata, so lua_touserdata
       would hand back the box rather than the engine — which binds happily
       and then never calls anything. Go through the same unboxer the
       generated code uses. */
    SDLStatic_Engine *engine =
        (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    luaL_argcheck(L, engine != NULL, 1, "engine expected");
    luaL_checktype(L, 2, LUA_TFUNCTION);

    if (!SDLStatic_ScriptBind(engine, L, DispatchLua, ReleaseLua))
    {
        return luaL_error(L, "could not bind Lua to this engine");
    }
    lua_pushvalue(L, 2);
    const int ref = luaL_ref(L, LUA_REGISTRYINDEX);
    if (!SDLStatic_ScriptSetHook(engine, hook, (Sint64)ref))
    {
        luaL_unref(L, LUA_REGISTRYINDEX, ref);
        return luaL_error(L, "%s", SDL_GetError());
    }
    lua_pushboolean(L, 1);
    return 1;
}

static int LOnLoad(lua_State *L) { return SetHook(L, SDLSTATIC_HOOK_LOAD); }
static int LOnFixedUpdate(lua_State *L) { return SetHook(L, SDLSTATIC_HOOK_FIXED_UPDATE); }
static int LOnUpdate(lua_State *L) { return SetHook(L, SDLSTATIC_HOOK_UPDATE); }
static int LOnRender(lua_State *L) { return SetHook(L, SDLSTATIC_HOOK_RENDER); }
static int LOnPostRender(lua_State *L) { return SetHook(L, SDLSTATIC_HOOK_POST_RENDER); }
static int LOnUnload(lua_State *L) { return SetHook(L, SDLSTATIC_HOOK_UNLOAD); }

/* Hand the loop over. Handlers fire from EngineTick too, so a script that
   would rather own the `while` simply does not call this. */
static int LRun(lua_State *L)
{
    SDLStatic_Engine *engine =
        (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    luaL_argcheck(L, engine != NULL, 1, "engine expected");
    lua_pushboolean(L, SDLStatic_ScriptRun(engine));
    return 1;
}

/* --- scenes ---------------------------------------------------------------- */

/* A scene callback carries more than a game hook does: which scene, and for
   the event hook the event itself. Both cross as borrowed handles — the
   engine owns the scene, and the event belongs to the frame — so a script
   that stashes one and uses it later has a dangling pointer, exactly as it
   would in C. */
static bool DispatchSceneLua(void *language_state, Sint64 handle, SDLStatic_SceneHook hook,
                             SDLStatic_Scene *scene, float value, const SDL_Event *event)
{
    lua_State *L = (lua_State *)language_state;
    lua_rawgeti(L, LUA_REGISTRYINDEX, (lua_Integer)handle);
    if (!lua_isfunction(L, -1))
    {
        lua_pop(L, 1);
        return true;
    }

    /* Every scene callback is given its scene, so one definition can back
       several live scenes and a script can tell them apart — a table keyed
       by the scene is how a script does what SDLStatic_SceneState does for
       C. */
    SDLStaticGen_LuaPushHandle(L, scene, "SDLStatic_Scene");
    int args = 1;
    if (hook == SDLSTATIC_SCENE_HOOK_FIXED_UPDATE || hook == SDLSTATIC_SCENE_HOOK_UPDATE ||
        hook == SDLSTATIC_SCENE_HOOK_RENDER)
    {
        lua_pushnumber(L, (lua_Number)value);
        args = 2;
    }
    else if (hook == SDLSTATIC_SCENE_HOOK_EVENT)
    {
        /* const is dropped here because the bindings have one handle type
           per C type; a script cannot write through it usefully anyway,
           since the setters it would need take a builder's event. */
        SDLStaticGen_LuaPushHandle(L, (void *)(uintptr_t)event, "SDL_Event");
        args = 2;
    }

    if (lua_pcall(L, args, 1, 0) != LUA_OK)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "scene hook: %s",
                     lua_tostring(L, -1) ? lua_tostring(L, -1) : "error");
        lua_pop(L, 1);
        return true;
    }

    /* Only `load` reads a result, where false aborts the push. */
    bool ok = true;
    if (hook == SDLSTATIC_SCENE_HOOK_LOAD && !lua_isnil(L, -1))
    {
        ok = lua_toboolean(L, -1) != 0;
    }
    lua_pop(L, 1);
    return ok;
}

/* Hook names rather than numbers, because a script writing
   SDLStaticC.SceneOn(e, "level", 4, fn) is unreadable and a typo in it is
   silent. A wrong name here is an error naming the ones that exist. */
static const struct
{
    const char *name;
    SDLStatic_SceneHook hook;
} kSceneHooks[] = {
    {"load", SDLSTATIC_SCENE_HOOK_LOAD},
    {"enter", SDLSTATIC_SCENE_HOOK_ENTER},
    {"fixed_update", SDLSTATIC_SCENE_HOOK_FIXED_UPDATE},
    {"update", SDLSTATIC_SCENE_HOOK_UPDATE},
    {"render", SDLSTATIC_SCENE_HOOK_RENDER},
    {"event", SDLSTATIC_SCENE_HOOK_EVENT},
    {"exit", SDLSTATIC_SCENE_HOOK_EXIT},
    {"unload", SDLSTATIC_SCENE_HOOK_UNLOAD},
};

/* SDLStaticC.SceneDefine(engine, "level") */
static int LSceneDefine(lua_State *L)
{
    SDLStatic_Engine *engine =
        (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    luaL_argcheck(L, engine != NULL, 1, "engine expected");
    const char *name = luaL_checkstring(L, 2);

    /* Defining a scene binds the language too, so a script that uses only
       scenes never has to know the game hooks exist. */
    if (!SDLStatic_ScriptBind(engine, L, DispatchLua, ReleaseLua) ||
        !SDLStatic_ScriptSetSceneDispatch(engine, DispatchSceneLua))
    {
        return luaL_error(L, "could not bind Lua to this engine");
    }
    if (!SDLStatic_ScriptSceneDefine(engine, name))
    {
        return luaL_error(L, "%s", SDL_GetError());
    }
    lua_pushboolean(L, 1);
    return 1;
}

/* SDLStaticC.SceneOn(engine, "level", "render", function(scene, alpha) ... end) */
static int LSceneOn(lua_State *L)
{
    SDLStatic_Engine *engine =
        (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    luaL_argcheck(L, engine != NULL, 1, "engine expected");
    const char *name = luaL_checkstring(L, 2);
    const char *hook_name = luaL_checkstring(L, 3);
    luaL_checktype(L, 4, LUA_TFUNCTION);

    SDLStatic_SceneHook hook = SDLSTATIC_SCENE_HOOK_COUNT;
    for (size_t i = 0; i < SDL_arraysize(kSceneHooks); ++i)
    {
        if (SDL_strcmp(kSceneHooks[i].name, hook_name) == 0)
        {
            hook = kSceneHooks[i].hook;
            break;
        }
    }
    if (hook == SDLSTATIC_SCENE_HOOK_COUNT)
    {
        return luaL_error(L, "unknown scene hook '%s': expected load, enter, fixed_update, "
                             "update, render, event, exit or unload",
                          hook_name);
    }

    lua_pushvalue(L, 4);
    const int ref = luaL_ref(L, LUA_REGISTRYINDEX);
    if (!SDLStatic_ScriptSceneSetHook(engine, name, hook, (Sint64)ref))
    {
        luaL_unref(L, LUA_REGISTRYINDEX, ref);
        return luaL_error(L, "%s", SDL_GetError());
    }
    lua_pushboolean(L, 1);
    return 1;
}

/* Installed by the opener below rather than exported: scenes and hooks
   are one surface to a script, so there is one entry point. */
static bool OpenLuaSceneHooks(lua_State *L)
{
    static const luaL_Reg scenes[] = {
        {"SceneDefine", LSceneDefine}, {"SceneOn", LSceneOn}, {NULL, NULL}};
    if (L == NULL)
    {
        return false;
    }
    lua_getglobal(L, "SDLStaticC");
    if (!lua_istable(L, -1))
    {
        lua_pop(L, 1);
        return false;
    }
    luaL_setfuncs(L, scenes, 0);
    lua_pop(L, 1);
    return true;
}

bool SDLStatic_OpenLuaEngineHooks(lua_State *L)
{
    static const luaL_Reg hooks[] = {{"OnLoad", LOnLoad},
                                     {"OnFixedUpdate", LOnFixedUpdate},
                                     {"OnUpdate", LOnUpdate},
                                     {"OnRender", LOnRender},
                                     {"OnPostRender", LOnPostRender},
                                     {"OnUnload", LOnUnload},
                                     {"Run", LRun},
                                     {NULL, NULL}};
    if (L == NULL)
    {
        return false;
    }
    /* Added to the generated module rather than a new one, so a script sees
       one namespace for the engine however each piece was produced. */
    lua_getglobal(L, "SDLStaticC");
    if (!lua_istable(L, -1))
    {
        lua_pop(L, 1);
        return false;
    }
    luaL_setfuncs(L, hooks, 0);
    lua_pop(L, 1);
    return OpenLuaSceneHooks(L);
}
