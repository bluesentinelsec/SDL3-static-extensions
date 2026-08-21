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
    return true;
}
