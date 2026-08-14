/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for tomlc99. */
#include "../src/gen_support_ruby.h"

#include <toml.h>
#include <string.h>

static void GenDtor_toml_free(void *p)
{
    toml_table_t *typed = (toml_table_t *)p;
    toml_free(typed);
}

static mrb_value GenR_toml_array_at(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_array_t");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    toml_array_t * rv = toml_array_at(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "toml_array_t");
    }
}

static mrb_value GenR_toml_array_in(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_table_t");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    toml_array_t * rv = toml_array_in(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "toml_array_t");
    }
}

static mrb_value GenR_toml_array_key(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_array_t");
    const char * rv = toml_array_key(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_toml_array_kind(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_array_t");
    char rv = toml_array_kind(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_toml_array_nelem(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_array_t");
    int rv = toml_array_nelem(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_toml_array_type(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_array_t");
    char rv = toml_array_type(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_toml_free(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    toml_table_t *a0 = (toml_table_t *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_table_t");
    toml_free(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_toml_key_exists(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_table_t");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = toml_key_exists(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_toml_key_in(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_table_t");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = toml_key_in(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_toml_parse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *src0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    char *a0 = SDL_strdup(src0 != NULL ? src0 : "");
    const char *src1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char *a1 = SDL_strdup(src1 != NULL ? src1 : "");
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    toml_table_t * rv = toml_parse(a0, a1, a2);
    SDL_free(a1);
    SDL_free(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "toml_table_t", GenDtor_toml_free);
    }
}

static mrb_value GenR_toml_table_at(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_array_t");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    toml_table_t * rv = toml_table_at(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "toml_table_t");
    }
}

static mrb_value GenR_toml_table_in(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_table_t");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    toml_table_t * rv = toml_table_in(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "toml_table_t");
    }
}

static mrb_value GenR_toml_table_key(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_table_t");
    const char * rv = toml_table_key(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_toml_table_narr(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_table_t");
    int rv = toml_table_narr(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_toml_table_nkval(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_table_t");
    int rv = toml_table_nkval(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_toml_table_ntab(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "toml_table_t");
    int rv = toml_table_ntab(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_toml_ucs_to_utf8(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int64_t a0 = (int64_t)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *src1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char *a1 = SDL_strdup(src1 != NULL ? src1 : "");
    int rv = toml_ucs_to_utf8(a0, a1);
    SDL_free(a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_toml_utf8_to_ucs(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int64_t io2 = (int64_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = toml_utf8_to_ucs(a0, a1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

void SDLStaticGen_OpenRuby_toml(mrb_state *mrb);
void SDLStaticGen_OpenRuby_toml(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "TOML");
    mrb_define_module_function(mrb, mod, "array_at", GenR_toml_array_at, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "array_in", GenR_toml_array_in, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "array_key", GenR_toml_array_key, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "array_kind", GenR_toml_array_kind, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "array_nelem", GenR_toml_array_nelem, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "array_type", GenR_toml_array_type, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "free", GenR_toml_free, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "key_exists", GenR_toml_key_exists, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "key_in", GenR_toml_key_in, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "parse", GenR_toml_parse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "table_at", GenR_toml_table_at, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "table_in", GenR_toml_table_in, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "table_key", GenR_toml_table_key, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "table_narr", GenR_toml_table_narr, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "table_nkval", GenR_toml_table_nkval, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "table_ntab", GenR_toml_table_ntab, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ucs_to_utf8", GenR_toml_ucs_to_utf8, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "utf8_to_ucs", GenR_toml_utf8_to_ucs, MRB_ARGS_ANY());
}
