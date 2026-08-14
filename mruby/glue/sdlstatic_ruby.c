/*
 * sdlstatic_ruby.c — require/load + console output for mruby.
 *
 * Original SDLStatic code (zlib). Design notes in SDLStatic/ruby.h.
 */
#include <SDLStatic/ruby.h>
#include <SDLStatic/vfs.h>
#include <physfs.h>

#include <mruby/array.h>
#include <mruby/compile.h>
#include <mruby/error.h>
#include <mruby/irep.h>
#include <mruby/string.h>
#include <mruby/variable.h>

#include <stdio.h>

/* Read a file through the VFS when initialized, else the real filesystem. */
static unsigned char *ReadScript(const char *path, int *size)
{
    if (PHYSFS_isInit() && PHYSFS_exists(path))
    {
        return SDLStatic_LoadVFSFile(path, size);
    }
    size_t io_size = 0;
    void *data = SDL_LoadFile(path, &io_size);
    if (data == NULL || io_size > (size_t)SDL_MAX_SINT32)
    {
        SDL_free(data);
        return NULL;
    }
    *size = (int)io_size;
    return (unsigned char *)data;
}

static bool ScriptExists(const char *path)
{
    if (PHYSFS_isInit() && PHYSFS_exists(path))
    {
        return true;
    }
    SDL_PathInfo info;
    return SDL_GetPathInfo(path, &info) && info.type == SDL_PATHTYPE_FILE;
}

/* Execute one resolved file. Raises on syntax/runtime errors. */
static void ExecuteFile(mrb_state *mrb, const char *path)
{
    int size = 0;
    unsigned char *data = ReadScript(path, &size);
    if (data == NULL)
    {
        mrb_raisef(mrb, E_RUNTIME_ERROR, "cannot read script '%s'", path);
    }
    const size_t len = SDL_strlen(path);
    if (len > 4 && SDL_strcmp(path + len - 4, ".mrb") == 0)
    {
        mrb_load_irep_buf(mrb, data, (size_t)size);
    }
    else
    {
        mrb_ccontext *ctx = mrb_ccontext_new(mrb);
        mrb_ccontext_filename(mrb, ctx, path);
        mrb_load_nstring_cxt(mrb, (const char *)data, (size_t)size, ctx);
        mrb_ccontext_free(mrb, ctx);
    }
    SDL_free(data);
    if (mrb->exc != NULL)
    {
        mrb_value exc = mrb_obj_value(mrb->exc);
        mrb->exc = NULL;
        mrb_exc_raise(mrb, exc);
    }
}

/* Resolve `name` against $LOAD_PATH; returns a resolved RString or nil. */
static mrb_value ResolveFeature(mrb_state *mrb, const char *name)
{
    static const char *const exts[] = {"", ".rb", ".mrb"};
    const bool absolute = (name[0] == '/');
    mrb_value load_path = mrb_gv_get(mrb, mrb_intern_lit(mrb, "$LOAD_PATH"));
    const mrb_int dirs = mrb_array_p(load_path) ? RARRAY_LEN(load_path) : 0;
    char candidate[1024];

    for (size_t e = 0; e < SDL_arraysize(exts); ++e)
    {
        if (absolute)
        {
            SDL_snprintf(candidate, sizeof(candidate), "%s%s", name, exts[e]);
            if (ScriptExists(candidate))
            {
                return mrb_str_new_cstr(mrb, candidate);
            }
            continue;
        }
        for (mrb_int d = 0; d < dirs; ++d)
        {
            mrb_value dir = mrb_ary_ref(mrb, load_path, d);
            if (!mrb_string_p(dir))
            {
                continue;
            }
            const char *dir_str = RSTRING_CSTR(mrb, dir);
            if (dir_str[0] == '\0' || SDL_strcmp(dir_str, ".") == 0)
            {
                /* PhysFS rejects "./" prefixes; bare names search the mount root. */
                SDL_snprintf(candidate, sizeof(candidate), "%s%s", name, exts[e]);
            }
            else
            {
                SDL_snprintf(candidate, sizeof(candidate), "%s/%s%s", dir_str, name, exts[e]);
            }
            if (ScriptExists(candidate))
            {
                return mrb_str_new_cstr(mrb, candidate);
            }
        }
    }
    return mrb_nil_value();
}

static void ExecuteTracked(mrb_state *mrb, const char *path);

static mrb_value FeaturesArray(mrb_state *mrb)
{
    mrb_value features = mrb_gv_get(mrb, mrb_intern_lit(mrb, "$LOADED_FEATURES"));
    if (!mrb_array_p(features))
    {
        features = mrb_ary_new(mrb);
        mrb_gv_set(mrb, mrb_intern_lit(mrb, "$LOADED_FEATURES"), features);
    }
    return features;
}

static bool FeatureLoaded(mrb_state *mrb, mrb_value features, const char *path)
{
    for (mrb_int i = 0; i < RARRAY_LEN(features); ++i)
    {
        mrb_value entry = mrb_ary_ref(mrb, features, i);
        if (mrb_string_p(entry) && SDL_strcmp(RSTRING_CSTR(mrb, entry), path) == 0)
        {
            return true;
        }
    }
    return false;
}

static mrb_value RequireResolved(mrb_state *mrb, const char *name)
{
    mrb_value resolved = ResolveFeature(mrb, name);
    if (mrb_nil_p(resolved))
    {
        mrb_raisef(mrb, E_RUNTIME_ERROR, "cannot load such file -- %s", name);
    }
    const char *path = RSTRING_CSTR(mrb, resolved);
    mrb_value features = FeaturesArray(mrb);
    if (FeatureLoaded(mrb, features, path))
    {
        return mrb_false_value(); /* already loaded, or currently loading */
    }
    /* Push BEFORE executing: circular requires resolve to false, like CRuby. */
    mrb_ary_push(mrb, features, resolved);
    ExecuteTracked(mrb, path);
    return mrb_true_value();
}

static mrb_value KernelRequire(mrb_state *mrb, mrb_value self)
{
    (void)self;
    const char *name = NULL;
    mrb_get_args(mrb, "z", &name);
    return RequireResolved(mrb, name);
}

static mrb_value KernelRequireRelative(mrb_state *mrb, mrb_value self)
{
    (void)self;
    const char *name = NULL;
    mrb_get_args(mrb, "z", &name);

    /* Resolve against the directory of the file currently executing. */
    mrb_value base = mrb_gv_get(mrb, mrb_intern_lit(mrb, "$__sdlstatic_current_file"));
    char joined[1024];
    if (mrb_string_p(base))
    {
        const char *base_path = RSTRING_CSTR(mrb, base);
        const char *slash = SDL_strrchr(base_path, '/');
        if (slash != NULL)
        {
            const size_t dir_len = (size_t)(slash - base_path);
            SDL_snprintf(joined, sizeof(joined), "%.*s/%s", (int)dir_len, base_path, name);
            name = joined;
        }
    }
    return RequireResolved(mrb, name);
}

static mrb_value KernelLoad(mrb_state *mrb, mrb_value self)
{
    (void)self;
    const char *name = NULL;
    mrb_get_args(mrb, "z", &name);
    mrb_value resolved = ResolveFeature(mrb, name);
    if (mrb_nil_p(resolved))
    {
        mrb_raisef(mrb, E_RUNTIME_ERROR, "cannot load such file -- %s", name);
    }
    ExecuteTracked(mrb, RSTRING_CSTR(mrb, resolved));
    return mrb_true_value();
}

static mrb_value ExecuteFileBody(mrb_state *mrb, mrb_value data)
{
    ExecuteFile(mrb, RSTRING_CSTR(mrb, data));
    return mrb_nil_value();
}

/* Track the current file for require_relative; re-raises script errors. */
static void ExecuteTracked(mrb_state *mrb, const char *path)
{
    mrb_sym gv = mrb_intern_lit(mrb, "$__sdlstatic_current_file");
    mrb_value prev = mrb_gv_get(mrb, gv);
    mrb_gv_set(mrb, gv, mrb_str_new_cstr(mrb, path));
    mrb_bool failed = FALSE;
    mrb_value result = mrb_protect(mrb, ExecuteFileBody, mrb_str_new_cstr(mrb, path), &failed);
    mrb_gv_set(mrb, gv, prev);
    if (failed)
    {
        mrb_exc_raise(mrb, result);
    }
}

/* ------------------------------------------------------ console output --- */

static mrb_value KernelPuts(mrb_state *mrb, mrb_value self)
{
    (void)self;
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    mrb_get_args(mrb, "*", &argv, &argc);
    if (argc == 0)
    {
        fputc('\n', stdout);
    }
    for (mrb_int i = 0; i < argc; ++i)
    {
        mrb_value str = mrb_obj_as_string(mrb, argv[i]);
        fwrite(RSTRING_PTR(str), 1, (size_t)RSTRING_LEN(str), stdout);
        if (RSTRING_LEN(str) == 0 || RSTRING_PTR(str)[RSTRING_LEN(str) - 1] != '\n')
        {
            fputc('\n', stdout);
        }
    }
    fflush(stdout);
    return mrb_nil_value();
}

static mrb_value KernelPrint(mrb_state *mrb, mrb_value self)
{
    (void)self;
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    mrb_get_args(mrb, "*", &argv, &argc);
    for (mrb_int i = 0; i < argc; ++i)
    {
        mrb_value str = mrb_obj_as_string(mrb, argv[i]);
        fwrite(RSTRING_PTR(str), 1, (size_t)RSTRING_LEN(str), stdout);
    }
    fflush(stdout);
    return mrb_nil_value();
}

static mrb_value KernelP(mrb_state *mrb, mrb_value self)
{
    (void)self;
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    mrb_get_args(mrb, "*", &argv, &argc);
    for (mrb_int i = 0; i < argc; ++i)
    {
        mrb_value str = mrb_inspect(mrb, argv[i]);
        fwrite(RSTRING_PTR(str), 1, (size_t)RSTRING_LEN(str), stdout);
        fputc('\n', stdout);
    }
    fflush(stdout);
    return (argc == 1) ? argv[0] : mrb_nil_value();
}

/* -------------------------------------------------------- public API ---- */

mrb_state *SDLStatic_CreateRubyState(void)
{
    mrb_state *mrb = mrb_open();
    if (mrb == NULL)
    {
        SDL_SetError("mrb_open failed");
        return NULL;
    }
    mrb_gv_set(mrb, mrb_intern_lit(mrb, "$LOAD_PATH"), mrb_ary_new(mrb));
    mrb_gv_set(mrb, mrb_intern_lit(mrb, "$LOADED_FEATURES"), mrb_ary_new(mrb));
    struct RClass *kernel = mrb->kernel_module;
    mrb_define_module_function(mrb, kernel, "require", KernelRequire, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, kernel, "require_relative", KernelRequireRelative,
                               MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, kernel, "load", KernelLoad, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, kernel, "puts", KernelPuts, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, kernel, "print", KernelPrint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, kernel, "p", KernelP, MRB_ARGS_ANY());
    return mrb;
}

bool SDLStatic_RubyAddLoadPath(mrb_state *mrb, const char *path)
{
    if (mrb == NULL || path == NULL)
    {
        return SDL_InvalidParamError("mrb/path");
    }
    mrb_value load_path = mrb_gv_get(mrb, mrb_intern_lit(mrb, "$LOAD_PATH"));
    if (!mrb_array_p(load_path))
    {
        load_path = mrb_ary_new(mrb);
        mrb_gv_set(mrb, mrb_intern_lit(mrb, "$LOAD_PATH"), load_path);
    }
    mrb_ary_push(mrb, load_path, mrb_str_new_cstr(mrb, path));
    return true;
}

static mrb_value ExecuteTrackedBody(mrb_state *mrb, mrb_value data)
{
    ExecuteTracked(mrb, RSTRING_CSTR(mrb, data));
    return mrb_nil_value();
}

bool SDLStatic_RubyRunVFSScript(mrb_state *mrb, const char *vfsPath)
{
    if (mrb == NULL || vfsPath == NULL)
    {
        return SDL_InvalidParamError("mrb/vfsPath");
    }
    mrb_bool failed = FALSE;
    mrb_value result =
        mrb_protect(mrb, ExecuteTrackedBody, mrb_str_new_cstr(mrb, vfsPath), &failed);
    if (failed)
    {
        mrb_value msg = mrb_inspect(mrb, result);
        return SDL_SetError("%s", RSTRING_CSTR(mrb, msg));
    }
    return true;
}
