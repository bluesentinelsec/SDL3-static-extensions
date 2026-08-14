/*
 * gen_support_ruby.c — marshaling runtime for the generated mruby
 * bindings. Original SDLStatic code (zlib).
 */
#include "gen_support_ruby.h"

#include <string.h>

static void GenRubyDfree(mrb_state *mrb, void *p)
{
    SDLStaticGen_RubyHandle *h = (SDLStaticGen_RubyHandle *)p;
    if (h != NULL)
    {
        if (h->ptr != NULL && h->dtor != NULL)
        {
            h->dtor(h->ptr);
        }
        mrb_free(mrb, h);
    }
}

const struct mrb_data_type SDLStaticGen_RubyHandleType = {
    "SDLStaticGen_Handle", GenRubyDfree
};

void SDLStaticGen_RubyEnsureHandleClass(mrb_state *mrb)
{
    struct RClass *mod;
    struct RClass *cls;
    if (mrb_class_defined(mrb, "SDLStaticGen"))
    {
        return;
    }
    mod = mrb_define_module(mrb, "SDLStaticGen");
    cls = mrb_define_class_under(mrb, mod, "Handle", mrb->object_class);
    MRB_SET_INSTANCE_TT(cls, MRB_TT_CDATA);
}

static struct RClass *GenHandleClass(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_module_get(mrb, "SDLStaticGen");
    return mrb_class_get_under(mrb, mod, "Handle");
}

static mrb_value GenPush(mrb_state *mrb, void *ptr, const char *ctype,
                         SDLStaticGen_Dtor dtor)
{
    SDLStaticGen_RubyHandle *h;
    struct RData *data;
    if (ptr == NULL)
    {
        return mrb_nil_value();
    }
    h = (SDLStaticGen_RubyHandle *)mrb_malloc(mrb, sizeof(*h));
    h->ptr = ptr;
    h->ctype = ctype;
    h->dtor = dtor;
    data = mrb_data_object_alloc(mrb, GenHandleClass(mrb), h,
                                 &SDLStaticGen_RubyHandleType);
    return mrb_obj_value(data);
}

mrb_value SDLStaticGen_RubyPushHandle(mrb_state *mrb, void *ptr, const char *ctype)
{
    return GenPush(mrb, ptr, ctype, NULL);
}

mrb_value SDLStaticGen_RubyPushOwned(mrb_state *mrb, void *ptr, const char *ctype,
                                     SDLStaticGen_Dtor dtor)
{
    return GenPush(mrb, ptr, ctype, dtor);
}

static SDLStaticGen_RubyHandle *GenCheck(mrb_state *mrb, mrb_value v,
                                         const char *ctype)
{
    SDLStaticGen_RubyHandle *h = (SDLStaticGen_RubyHandle *)mrb_data_get_ptr(
        mrb, v, &SDLStaticGen_RubyHandleType);
    if (h == NULL || strcmp(h->ctype, ctype) != 0)
    {
        mrb_raisef(mrb, E_TYPE_ERROR, "expected %s handle", ctype);
    }
    return h;
}

void *SDLStaticGen_RubyCheckHandle(mrb_state *mrb, mrb_value v, const char *ctype)
{
    if (mrb_nil_p(v))
    {
        return NULL;
    }
    return GenCheck(mrb, v, ctype)->ptr;
}

void *SDLStaticGen_RubyTakeHandle(mrb_state *mrb, mrb_value v, const char *ctype)
{
    SDLStaticGen_RubyHandle *h;
    void *ptr;
    if (mrb_nil_p(v))
    {
        return NULL;
    }
    h = GenCheck(mrb, v, ctype);
    ptr = h->ptr;
    h->ptr = NULL;
    h->dtor = NULL;
    return ptr;
}

mrb_value SDLStaticGen_RubyFieldGet(mrb_state *mrb, mrb_value hash, const char *field)
{
    if (!mrb_hash_p(hash))
    {
        return mrb_nil_value();
    }
    return mrb_hash_get(mrb, hash, mrb_symbol_value(mrb_intern_cstr(mrb, field)));
}

mrb_int SDLStaticGen_RubyFieldInt(mrb_state *mrb, mrb_value hash, const char *field)
{
    mrb_value v = SDLStaticGen_RubyFieldGet(mrb, hash, field);
    if (mrb_nil_p(v))
    {
        return 0;
    }
    if (mrb_float_p(v))
    {
        return (mrb_int)mrb_float(v);
    }
    return mrb_integer(mrb_ensure_integer_type(mrb, v));
}

mrb_float SDLStaticGen_RubyFieldNum(mrb_state *mrb, mrb_value hash, const char *field)
{
    mrb_value v = SDLStaticGen_RubyFieldGet(mrb, hash, field);
    if (mrb_nil_p(v))
    {
        return 0;
    }
    return mrb_as_float(mrb, v);
}

mrb_bool SDLStaticGen_RubyFieldBool(mrb_state *mrb, mrb_value hash, const char *field)
{
    mrb_value v = SDLStaticGen_RubyFieldGet(mrb, hash, field);
    return mrb_test(v);
}

void SDLStaticGen_RubyHashSet(mrb_state *mrb, mrb_value hash, const char *field,
                              mrb_value v)
{
    mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_cstr(mrb, field)), v);
}

mrb_int SDLStaticGen_RubyToInt(mrb_state *mrb, mrb_value v)
{
    if (mrb_nil_p(v))
    {
        return 0;
    }
    if (mrb_float_p(v))
    {
        return (mrb_int)mrb_float(v);
    }
    return mrb_integer(mrb_ensure_integer_type(mrb, v));
}

mrb_float SDLStaticGen_RubyToNum(mrb_state *mrb, mrb_value v)
{
    if (mrb_nil_p(v))
    {
        return 0;
    }
    return mrb_as_float(mrb, v);
}

mrb_bool SDLStaticGen_RubyToBool(mrb_value v)
{
    return mrb_test(v);
}

const char *SDLStaticGen_RubyToStr(mrb_state *mrb, mrb_value v)
{
    if (mrb_nil_p(v))
    {
        return NULL;
    }
    return mrb_str_to_cstr(mrb, mrb_ensure_string_type(mrb, v));
}

const char *SDLStaticGen_RubyToBlob(mrb_state *mrb, mrb_value v, size_t *len)
{
    mrb_value s;
    if (mrb_nil_p(v))
    {
        *len = 0;
        return NULL;
    }
    s = mrb_ensure_string_type(mrb, v);
    *len = (size_t)RSTRING_LEN(s);
    return RSTRING_PTR(s);
}
