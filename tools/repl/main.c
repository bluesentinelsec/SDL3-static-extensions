/*
 * repl — interactive shell / script runner for the SDLStatic interpreters.
 *
 * Original SDLStatic code (zlib).
 *
 *   repl -l lua                      interactive Lua shell
 *   repl -l ruby                     interactive Ruby shell
 *   repl -l lua  -e 'print(1+2)'     evaluate a one-liner
 *   repl -l ruby script.rb a b      run a script (args in ARGV / arg)
 *
 * Both states come up with the game bindings (SDLStatic module) and
 * VFS-aware require already installed; "." is on the Ruby $LOAD_PATH.
 */
#include <SDLStatic/bindings.h>
#include <SDLStatic/lua.h>
#include <SDLStatic/ruby.h>

#include <lauxlib.h>
#include <lualib.h>
#include <mruby/array.h>
#include <mruby/compile.h>
#include <mruby/string.h>
#include <mruby/variable.h>

#include <stdio.h>
#include <string.h>

static int Usage(void)
{
    fprintf(stderr, "usage: repl -l <lua|ruby> [-e code] [script] [args...]\n");
    return 2;
}

/* ------------------------------------------------------------- Lua ------ */

static int LuaReportError(lua_State *L)
{
    fprintf(stderr, "error: %s\n", lua_tostring(L, -1));
    lua_pop(L, 1);
    return 1;
}

static int RunLua(const char *code, const char *script, int argc, char **argv)
{
    lua_State *L = SDLStatic_CreateLuaState();
    if (L == NULL || !SDLStatic_OpenLuaBindings(L))
    {
        fprintf(stderr, "error: %s\n", SDL_GetError());
        return 1;
    }
    /* arg = {script args}, like the standalone lua interpreter */
    lua_newtable(L);
    for (int i = 0; i < argc; ++i)
    {
        lua_pushstring(L, argv[i]);
        lua_rawseti(L, -2, i + 1);
    }
    lua_setglobal(L, "arg");

    int rc = 0;
    if (code != NULL)
    {
        if (luaL_dostring(L, code) != LUA_OK)
        {
            rc = LuaReportError(L);
        }
    }
    else if (script != NULL)
    {
        if (luaL_dofile(L, script) != LUA_OK)
        {
            rc = LuaReportError(L);
        }
    }
    else
    {
        char line[2048];
        printf("SDLStatic Lua %s — 'exit' to quit\n", LUA_VERSION_RELEASE);
        for (;;)
        {
            printf("lua> ");
            fflush(stdout);
            if (fgets(line, sizeof(line), stdin) == NULL || strncmp(line, "exit", 4) == 0)
            {
                break;
            }
            /* Try as an expression first so `1+2` prints 3. */
            char wrapped[2100];
            snprintf(wrapped, sizeof(wrapped), "print((function() return %s end)())", line);
            if (luaL_dostring(L, wrapped) != LUA_OK)
            {
                lua_pop(L, 1);
                if (luaL_dostring(L, line) != LUA_OK)
                {
                    LuaReportError(L);
                }
            }
        }
    }
    lua_close(L);
    return rc;
}

/* ------------------------------------------------------------ Ruby ------ */

static int RubyReportError(mrb_state *mrb)
{
    if (mrb->exc != NULL)
    {
        mrb_value msg = mrb_inspect(mrb, mrb_obj_value(mrb->exc));
        fprintf(stderr, "error: %s\n", RSTRING_CSTR(mrb, msg));
        mrb->exc = NULL;
        return 1;
    }
    return 0;
}

static int RunRuby(const char *code, const char *script, int argc, char **argv)
{
    mrb_state *mrb = SDLStatic_CreateRubyState();
    if (mrb == NULL || !SDLStatic_OpenRubyBindings(mrb))
    {
        fprintf(stderr, "error: %s\n", SDL_GetError());
        return 1;
    }
    SDLStatic_RubyAddLoadPath(mrb, ".");
    mrb_value args = mrb_ary_new(mrb);
    for (int i = 0; i < argc; ++i)
    {
        mrb_ary_push(mrb, args, mrb_str_new_cstr(mrb, argv[i]));
    }
    mrb_define_global_const(mrb, "ARGV", args);

    int rc = 0;
    if (code != NULL)
    {
        mrb_load_string(mrb, code);
        rc = RubyReportError(mrb);
    }
    else if (script != NULL)
    {
        char req[1024];
        snprintf(req, sizeof(req), "load '%s'", script);
        mrb_load_string(mrb, req);
        rc = RubyReportError(mrb);
    }
    else
    {
        char line[2048];
        printf("SDLStatic mruby %s — 'exit' to quit\n", MRUBY_VERSION);
        for (;;)
        {
            printf("ruby> ");
            fflush(stdout);
            if (fgets(line, sizeof(line), stdin) == NULL || strncmp(line, "exit", 4) == 0)
            {
                break;
            }
            mrb_value result = mrb_load_string(mrb, line);
            if (mrb->exc != NULL)
            {
                RubyReportError(mrb);
            }
            else
            {
                mrb_value inspected = mrb_inspect(mrb, result);
                printf("=> %s\n", RSTRING_CSTR(mrb, inspected));
            }
        }
    }
    mrb_close(mrb);
    return rc;
}

int main(int argc, char **argv)
{
    const char *language = NULL;
    const char *code = NULL;
    const char *script = NULL;
    int script_args_at = argc;

    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "-l") == 0 && i + 1 < argc)
        {
            language = argv[++i];
        }
        else if (strcmp(argv[i], "-e") == 0 && i + 1 < argc)
        {
            code = argv[++i];
        }
        else
        {
            script = argv[i];
            script_args_at = i + 1;
            break;
        }
    }
    if (language == NULL)
    {
        return Usage();
    }
    const int extra = argc - script_args_at;
    char **extra_argv = argv + script_args_at;
    if (strcmp(language, "lua") == 0)
    {
        return RunLua(code, script, extra, extra_argv);
    }
    if (strcmp(language, "ruby") == 0)
    {
        return RunRuby(code, script, extra, extra_argv);
    }
    return Usage();
}
