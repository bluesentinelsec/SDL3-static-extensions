/*
 * sdlstatic_engine_hooks_ruby.c — registering Ruby blocks as engine hooks.
 * Original SDLStatic code (zlib).
 *
 * The mirror of the Lua file, and for the same reason: turning a Ruby
 * callable into something C can hold is the one thing the generator cannot
 * do. The engine's bridge does the dispatching and knows about neither
 * language.
 *
 * A handle here is an index into an array the interpreter keeps reachable.
 * mruby has no registry like Lua's, and a bare mrb_value stored in C is not
 * a GC root — the proc would be collected out from under the engine — so
 * the array is registered with mrb_gc_register and the handle is a position
 * in it.
 */
#include <SDLStatic/engine.h>
#include <SDLStatic/engine_script.h>
#include <SDLStatic/engine_scene.h>
#include <SDLStatic/ruby.h>

#include <mruby.h>
#include <mruby/array.h>
#include <mruby/proc.h>
#include <mruby/variable.h>

#include "gen_support_ruby.h"

/* The array of live handlers lives in a global on the interpreter, so it is
   reachable by mruby's collector for exactly as long as the state is. */
#define HANDLER_ARRAY "$__sdlstatic_engine_hooks"

static mrb_value HandlerArray(mrb_state *mrb)
{
    mrb_value array = mrb_gv_get(mrb, mrb_intern_lit(mrb, HANDLER_ARRAY));
    if (!mrb_array_p(array))
    {
        array = mrb_ary_new(mrb);
        mrb_gv_set(mrb, mrb_intern_lit(mrb, HANDLER_ARRAY), array);
    }
    return array;
}

static bool DispatchRuby(void *language_state, Sint64 handle, SDLStatic_ScriptHook hook,
                         float value)
{
    mrb_state *mrb = (mrb_state *)language_state;
    mrb_value array = HandlerArray(mrb);
    if (handle < 0 || handle >= RARRAY_LEN(array))
    {
        return true;
    }
    const mrb_value callable = mrb_ary_ref(mrb, array, (mrb_int)handle);
    if (mrb_nil_p(callable))
    {
        return true;
    }

    /* Only the hooks carrying a number take an argument, so a script writes
       a no-argument block for the rest rather than ignoring a zero. */
    mrb_value result;
    if (hook == SDLSTATIC_HOOK_FIXED_UPDATE || hook == SDLSTATIC_HOOK_UPDATE ||
        hook == SDLSTATIC_HOOK_RENDER)
    {
        const mrb_value arg = mrb_float_value(mrb, (mrb_float)value);
        result = mrb_funcall(mrb, callable, "call", 1, arg);
    }
    else
    {
        result = mrb_funcall(mrb, callable, "call", 0);
    }

    if (mrb->exc != NULL)
    {
        /* An exception must not escape into the engine's C frames: report
           it and carry on, so one bad frame does not end the game. */
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "engine hook raised");
        mrb->exc = NULL;
        return true;
    }
    /* Only `load` reads a result, where false aborts start-up. */
    if (hook == SDLSTATIC_HOOK_LOAD)
    {
        return mrb_test(result);
    }
    return true;
}

static void ReleaseRuby(void *language_state, Sint64 handle)
{
    mrb_state *mrb = (mrb_state *)language_state;
    mrb_value array = HandlerArray(mrb);
    if (handle >= 0 && handle < RARRAY_LEN(array))
    {
        /* Nil the slot rather than removing it: every other handle is an
           index into this array, and compacting would move them. */
        mrb_ary_set(mrb, array, (mrb_int)handle, mrb_nil_value());
    }
}

static mrb_value SetHook(mrb_state *mrb, SDLStatic_ScriptHook hook)
{
    mrb_value engine_value;
    mrb_value callable = mrb_nil_value();
    mrb_get_args(mrb, "o|o&", &engine_value, &callable, &callable);

    SDLStatic_Engine *engine =
        (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, engine_value, "SDLStatic_Engine");
    if (engine == NULL || mrb_nil_p(callable))
    {
        mrb_raise(mrb, E_ARGUMENT_ERROR, "engine and a callable are required");
    }

    if (!SDLStatic_ScriptBind(engine, mrb, DispatchRuby, ReleaseRuby))
    {
        mrb_raise(mrb, E_RUNTIME_ERROR, "could not bind Ruby to this engine");
    }

    mrb_value array = HandlerArray(mrb);
    const mrb_int index = RARRAY_LEN(array);
    mrb_ary_push(mrb, array, callable);
    if (!SDLStatic_ScriptSetHook(engine, hook, (Sint64)index))
    {
        mrb_ary_set(mrb, array, index, mrb_nil_value());
        mrb_raise(mrb, E_RUNTIME_ERROR, SDL_GetError());
    }
    return mrb_true_value();
}

static mrb_value ROnLoad(mrb_state *mrb, mrb_value self)
{
    (void)self;
    return SetHook(mrb, SDLSTATIC_HOOK_LOAD);
}
static mrb_value ROnFixedUpdate(mrb_state *mrb, mrb_value self)
{
    (void)self;
    return SetHook(mrb, SDLSTATIC_HOOK_FIXED_UPDATE);
}
static mrb_value ROnUpdate(mrb_state *mrb, mrb_value self)
{
    (void)self;
    return SetHook(mrb, SDLSTATIC_HOOK_UPDATE);
}
static mrb_value ROnRender(mrb_state *mrb, mrb_value self)
{
    (void)self;
    return SetHook(mrb, SDLSTATIC_HOOK_RENDER);
}
static mrb_value ROnPostRender(mrb_state *mrb, mrb_value self)
{
    (void)self;
    return SetHook(mrb, SDLSTATIC_HOOK_POST_RENDER);
}
static mrb_value ROnUnload(mrb_state *mrb, mrb_value self)
{
    (void)self;
    return SetHook(mrb, SDLSTATIC_HOOK_UNLOAD);
}

static mrb_value RRun(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_value engine_value;
    mrb_get_args(mrb, "o", &engine_value);
    SDLStatic_Engine *engine =
        (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, engine_value, "SDLStatic_Engine");
    if (engine == NULL)
    {
        mrb_raise(mrb, E_ARGUMENT_ERROR, "engine expected");
    }
    return mrb_bool_value(SDLStatic_ScriptRun(engine));
}

/* --- scenes ---------------------------------------------------------------- */

/* A scene callback carries more than a game hook does: which scene, and for
   the event hook the event. Both cross as borrowed handles — the engine
   owns the scene, and the event belongs to the frame — so a script that
   stashes one and uses it later has a dangling pointer, as it would in C. */
static bool DispatchSceneRuby(void *language_state, Sint64 handle, SDLStatic_SceneHook hook,
                              SDLStatic_Scene *scene, float value, const SDL_Event *event)
{
    mrb_state *mrb = (mrb_state *)language_state;
    mrb_value array = HandlerArray(mrb);
    if (handle < 0 || handle >= RARRAY_LEN(array))
    {
        return true;
    }
    const mrb_value callable = mrb_ary_ref(mrb, array, (mrb_int)handle);
    if (mrb_nil_p(callable))
    {
        return true;
    }

    /* Every callback is given its scene, so one definition can back several
       live scenes and a script can tell them apart — a hash keyed by the
       scene does what SDLStatic_SceneState does for C. */
    const mrb_value scene_value = SDLStaticGen_RubyPushHandle(mrb, scene, "SDLStatic_Scene");
    mrb_value result;
    if (hook == SDLSTATIC_SCENE_HOOK_FIXED_UPDATE || hook == SDLSTATIC_SCENE_HOOK_UPDATE ||
        hook == SDLSTATIC_SCENE_HOOK_RENDER)
    {
        result = mrb_funcall(mrb, callable, "call", 2, scene_value,
                             mrb_float_value(mrb, (mrb_float)value));
    }
    else if (hook == SDLSTATIC_SCENE_HOOK_EVENT)
    {
        /* const is dropped because the bindings have one handle type per C
           type; a script cannot usefully write through it in any case. */
        const mrb_value event_value =
            SDLStaticGen_RubyPushHandle(mrb, (void *)(uintptr_t)event, "SDL_Event");
        result = mrb_funcall(mrb, callable, "call", 2, scene_value, event_value);
    }
    else
    {
        result = mrb_funcall(mrb, callable, "call", 1, scene_value);
    }

    if (mrb->exc != NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "scene hook raised");
        mrb->exc = NULL;
        return true;
    }
    if (hook == SDLSTATIC_SCENE_HOOK_LOAD)
    {
        return mrb_test(result);
    }
    return true;
}

/* Hook names rather than numbers: a typo in a number is silent, a typo in
   a name is an error naming the ones that exist. */
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
static mrb_value RSceneDefine(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_value engine_value;
    const char *name = NULL;
    mrb_get_args(mrb, "oz", &engine_value, &name);

    SDLStatic_Engine *engine =
        (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, engine_value, "SDLStatic_Engine");
    if (engine == NULL)
    {
        mrb_raise(mrb, E_ARGUMENT_ERROR, "engine expected");
    }
    /* Defining a scene binds the language too, so a script that uses only
       scenes never has to know the game hooks exist. */
    if (!SDLStatic_ScriptBind(engine, mrb, DispatchRuby, ReleaseRuby) ||
        !SDLStatic_ScriptSetSceneDispatch(engine, DispatchSceneRuby))
    {
        mrb_raise(mrb, E_RUNTIME_ERROR, "could not bind Ruby to this engine");
    }
    if (!SDLStatic_ScriptSceneDefine(engine, name))
    {
        mrb_raise(mrb, E_RUNTIME_ERROR, SDL_GetError());
    }
    return mrb_true_value();
}

/* SDLStaticC.SceneOn(engine, "level", "render") { |scene, alpha| ... } */
static mrb_value RSceneOn(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_value engine_value;
    const char *name = NULL;
    const char *hook_name = NULL;
    mrb_value callable = mrb_nil_value();
    mrb_get_args(mrb, "ozz|o&", &engine_value, &name, &hook_name, &callable, &callable);

    SDLStatic_Engine *engine =
        (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, engine_value, "SDLStatic_Engine");
    if (engine == NULL || mrb_nil_p(callable))
    {
        mrb_raise(mrb, E_ARGUMENT_ERROR, "engine, scene name, hook name and a callable "
                                         "are required");
    }

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
        mrb_raise(mrb, E_ARGUMENT_ERROR,
                  "unknown scene hook: expected load, enter, fixed_update, update, "
                  "render, event, exit or unload");
    }

    mrb_value array = HandlerArray(mrb);
    const mrb_int index = RARRAY_LEN(array);
    mrb_ary_push(mrb, array, callable);
    if (!SDLStatic_ScriptSceneSetHook(engine, name, hook, (Sint64)index))
    {
        mrb_ary_set(mrb, array, index, mrb_nil_value());
        mrb_raise(mrb, E_RUNTIME_ERROR, SDL_GetError());
    }
    return mrb_true_value();
}

bool SDLStatic_OpenRubyEngineHooks(mrb_state *mrb)
{
    if (mrb == NULL)
    {
        return false;
    }
    /* Added to the generated module, so a script sees one namespace for the
       engine however each piece was produced. */
    struct RClass *mod = mrb_module_get(mrb, "SDLStaticC");
    if (mod == NULL)
    {
        return false;
    }
    mrb_define_module_function(mrb, mod, "OnLoad", ROnLoad, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OnFixedUpdate", ROnFixedUpdate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OnUpdate", ROnUpdate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OnRender", ROnRender, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OnPostRender", ROnPostRender, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OnUnload", ROnUnload, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Run", RRun, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, mod, "SceneDefine", RSceneDefine, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, mod, "SceneOn", RSceneOn, MRB_ARGS_ANY());
    return true;
}
