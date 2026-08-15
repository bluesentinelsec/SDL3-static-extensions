/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for cJSON. */
#include "../src/gen_support_ruby.h"

#include <cJSON.h>
#include <string.h>

static void GenDtor_cJSON_Delete(void *p)
{
    cJSON *typed = (cJSON *)p;
    cJSON_Delete(typed);
}

static mrb_value GenR_cJSON_AddArrayToObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_AddArrayToObject(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_AddBoolToObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON_bool a2 = (cJSON_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    cJSON * rv = cJSON_AddBoolToObject(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_AddFalseToObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_AddFalseToObject(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_AddItemReferenceToArray(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON *a1 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_AddItemReferenceToArray(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_AddItemReferenceToObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON *a2 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_AddItemReferenceToObject(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_AddItemToArray(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON *a1 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_AddItemToArray(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_AddItemToObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON *a2 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_AddItemToObject(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_AddItemToObjectCS(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON *a2 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_AddItemToObjectCS(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_AddNullToObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_AddNullToObject(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_AddNumberToObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    double a2 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    cJSON * rv = cJSON_AddNumberToObject(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_AddObjectToObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_AddObjectToObject(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_AddRawToObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    cJSON * rv = cJSON_AddRawToObject(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_AddStringToObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    cJSON * rv = cJSON_AddStringToObject(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_AddTrueToObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_AddTrueToObject(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_Compare(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const cJSON *a1 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "cJSON");
    cJSON_bool a2 = (cJSON_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    cJSON_bool rv = cJSON_Compare(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_CreateArray(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON * rv = cJSON_CreateArray();
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "cJSON", GenDtor_cJSON_Delete);
    }
}

static mrb_value GenR_cJSON_CreateArrayReference(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON * rv = cJSON_CreateArrayReference(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_CreateBool(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON_bool a0 = (cJSON_bool)SDLStaticGen_RubyToBool((argc > 0 ? argv[0] : mrb_nil_value()));
    cJSON * rv = cJSON_CreateBool(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_CreateFalse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON * rv = cJSON_CreateFalse();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_CreateNull(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON * rv = cJSON_CreateNull();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_CreateNumber(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    double a0 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    cJSON * rv = cJSON_CreateNumber(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_CreateObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON * rv = cJSON_CreateObject();
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "cJSON", GenDtor_cJSON_Delete);
    }
}

static mrb_value GenR_cJSON_CreateObjectReference(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON * rv = cJSON_CreateObjectReference(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_CreateRaw(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    cJSON * rv = cJSON_CreateRaw(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_CreateString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    cJSON * rv = cJSON_CreateString(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_CreateStringReference(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    cJSON * rv = cJSON_CreateStringReference(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_CreateTrue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON * rv = cJSON_CreateTrue();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_Delete(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_Delete(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_cJSON_DeleteItemFromArray(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON_DeleteItemFromArray(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_cJSON_DeleteItemFromObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON_DeleteItemFromObject(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_cJSON_DeleteItemFromObjectCaseSensitive(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON_DeleteItemFromObjectCaseSensitive(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_cJSON_DetachItemFromArray(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_DetachItemFromArray(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_DetachItemFromObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_DetachItemFromObject(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_DetachItemFromObjectCaseSensitive(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_DetachItemFromObjectCaseSensitive(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_DetachItemViaPointer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON *a1 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "cJSON");
    cJSON * rv = cJSON_DetachItemViaPointer(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_Duplicate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_bool a1 = (cJSON_bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_Duplicate(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_GetArrayItem(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_GetArrayItem(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_GetArraySize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    int rv = cJSON_GetArraySize(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_cJSON_GetErrorPtr(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = cJSON_GetErrorPtr();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_cJSON_GetNumberValue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    double rv = cJSON_GetNumberValue(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_cJSON_GetObjectItem(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_GetObjectItem(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_GetObjectItemCaseSensitive(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_GetObjectItemCaseSensitive(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cJSON");
    }
}

static mrb_value GenR_cJSON_GetStringValue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    char * rv = cJSON_GetStringValue(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { cJSON_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_cJSON_HasObjectItem(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON_bool rv = cJSON_HasObjectItem(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_InitHooks(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON_Hooks *a0 = (cJSON_Hooks *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON_Hooks");
    cJSON_InitHooks(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_cJSON_InsertItemInArray(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON *a2 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_InsertItemInArray(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_IsArray(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_IsArray(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_IsBool(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_IsBool(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_IsFalse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_IsFalse(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_IsInvalid(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_IsInvalid(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_IsNull(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_IsNull(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_IsNumber(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_IsNumber(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_IsObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_IsObject(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_IsRaw(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_IsRaw(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_IsString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_IsString(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_IsTrue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_IsTrue(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_Minify(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *src0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    char *a0 = SDL_strdup(src0 != NULL ? src0 : "");
    cJSON_Minify(a0);
    SDL_free(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_cJSON_Parse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    cJSON * rv = cJSON_Parse(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "cJSON", GenDtor_cJSON_Delete);
    }
}

static mrb_value GenR_cJSON_ParseWithLength(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    size_t a1 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON * rv = cJSON_ParseWithLength(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "cJSON", GenDtor_cJSON_Delete);
    }
}

static mrb_value GenR_cJSON_Print(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    char * rv = cJSON_Print(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { cJSON_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_cJSON_PrintBuffered(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON_bool a2 = (cJSON_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    char * rv = cJSON_PrintBuffered(a0, a1, a2);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { cJSON_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_cJSON_PrintPreallocated(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *src1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char *a1 = SDL_strdup(src1 != NULL ? src1 : "");
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    cJSON_bool a3 = (cJSON_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    cJSON_bool rv = cJSON_PrintPreallocated(a0, a1, a2, a3);
    SDL_free(a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_PrintUnformatted(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const cJSON *a0 = (const cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    char * rv = cJSON_PrintUnformatted(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { cJSON_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_cJSON_ReplaceItemInArray(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON *a2 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_ReplaceItemInArray(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_ReplaceItemInObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON *a2 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_ReplaceItemInObject(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_ReplaceItemInObjectCaseSensitive(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    cJSON *a2 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_ReplaceItemInObjectCaseSensitive(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_ReplaceItemViaPointer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    cJSON *a1 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "cJSON");
    cJSON *a2 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "cJSON");
    cJSON_bool rv = cJSON_ReplaceItemViaPointer(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_cJSON_SetNumberHelper(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    double a1 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    double rv = cJSON_SetNumberHelper(a0, a1);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_cJSON_SetValuestring(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    cJSON *a0 = (cJSON *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "cJSON");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char * rv = cJSON_SetValuestring(a0, a1);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { cJSON_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_cJSON_Version(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = cJSON_Version();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

void SDLStaticGen_OpenRuby_cjson(mrb_state *mrb);
void SDLStaticGen_OpenRuby_cjson(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "JSON");
    mrb_define_module_function(mrb, mod, "AddArrayToObject", GenR_cJSON_AddArrayToObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddBoolToObject", GenR_cJSON_AddBoolToObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddFalseToObject", GenR_cJSON_AddFalseToObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddItemReferenceToArray", GenR_cJSON_AddItemReferenceToArray, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddItemReferenceToObject", GenR_cJSON_AddItemReferenceToObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddItemToArray", GenR_cJSON_AddItemToArray, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddItemToObject", GenR_cJSON_AddItemToObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddItemToObjectCS", GenR_cJSON_AddItemToObjectCS, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddNullToObject", GenR_cJSON_AddNullToObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddNumberToObject", GenR_cJSON_AddNumberToObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddObjectToObject", GenR_cJSON_AddObjectToObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddRawToObject", GenR_cJSON_AddRawToObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddStringToObject", GenR_cJSON_AddStringToObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddTrueToObject", GenR_cJSON_AddTrueToObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Compare", GenR_cJSON_Compare, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateArray", GenR_cJSON_CreateArray, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateArrayReference", GenR_cJSON_CreateArrayReference, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateBool", GenR_cJSON_CreateBool, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateFalse", GenR_cJSON_CreateFalse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateNull", GenR_cJSON_CreateNull, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateNumber", GenR_cJSON_CreateNumber, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateObject", GenR_cJSON_CreateObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateObjectReference", GenR_cJSON_CreateObjectReference, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateRaw", GenR_cJSON_CreateRaw, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateString", GenR_cJSON_CreateString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateStringReference", GenR_cJSON_CreateStringReference, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateTrue", GenR_cJSON_CreateTrue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Delete", GenR_cJSON_Delete, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DeleteItemFromArray", GenR_cJSON_DeleteItemFromArray, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DeleteItemFromObject", GenR_cJSON_DeleteItemFromObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DeleteItemFromObjectCaseSensitive", GenR_cJSON_DeleteItemFromObjectCaseSensitive, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DetachItemFromArray", GenR_cJSON_DetachItemFromArray, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DetachItemFromObject", GenR_cJSON_DetachItemFromObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DetachItemFromObjectCaseSensitive", GenR_cJSON_DetachItemFromObjectCaseSensitive, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DetachItemViaPointer", GenR_cJSON_DetachItemViaPointer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Duplicate", GenR_cJSON_Duplicate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetArrayItem", GenR_cJSON_GetArrayItem, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetArraySize", GenR_cJSON_GetArraySize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetErrorPtr", GenR_cJSON_GetErrorPtr, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumberValue", GenR_cJSON_GetNumberValue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetObjectItem", GenR_cJSON_GetObjectItem, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetObjectItemCaseSensitive", GenR_cJSON_GetObjectItemCaseSensitive, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetStringValue", GenR_cJSON_GetStringValue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasObjectItem", GenR_cJSON_HasObjectItem, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "InitHooks", GenR_cJSON_InitHooks, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "InsertItemInArray", GenR_cJSON_InsertItemInArray, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsArray", GenR_cJSON_IsArray, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsBool", GenR_cJSON_IsBool, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsFalse", GenR_cJSON_IsFalse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsInvalid", GenR_cJSON_IsInvalid, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsNull", GenR_cJSON_IsNull, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsNumber", GenR_cJSON_IsNumber, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsObject", GenR_cJSON_IsObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsRaw", GenR_cJSON_IsRaw, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsString", GenR_cJSON_IsString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsTrue", GenR_cJSON_IsTrue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Minify", GenR_cJSON_Minify, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Parse", GenR_cJSON_Parse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ParseWithLength", GenR_cJSON_ParseWithLength, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Print", GenR_cJSON_Print, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrintBuffered", GenR_cJSON_PrintBuffered, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrintPreallocated", GenR_cJSON_PrintPreallocated, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrintUnformatted", GenR_cJSON_PrintUnformatted, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReplaceItemInArray", GenR_cJSON_ReplaceItemInArray, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReplaceItemInObject", GenR_cJSON_ReplaceItemInObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReplaceItemInObjectCaseSensitive", GenR_cJSON_ReplaceItemInObjectCaseSensitive, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReplaceItemViaPointer", GenR_cJSON_ReplaceItemViaPointer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetNumberHelper", GenR_cJSON_SetNumberHelper, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetValuestring", GenR_cJSON_SetValuestring, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Version", GenR_cJSON_Version, MRB_ARGS_ANY());
#ifdef cJSON_Invalid
    mrb_define_const(mrb, mod, "Invalid", mrb_int_value(mrb, (mrb_int)(cJSON_Invalid)));
#endif
#ifdef cJSON_False
    mrb_define_const(mrb, mod, "False", mrb_int_value(mrb, (mrb_int)(cJSON_False)));
#endif
#ifdef cJSON_True
    mrb_define_const(mrb, mod, "True", mrb_int_value(mrb, (mrb_int)(cJSON_True)));
#endif
#ifdef cJSON_NULL
    mrb_define_const(mrb, mod, "NULL", mrb_int_value(mrb, (mrb_int)(cJSON_NULL)));
#endif
#ifdef cJSON_Number
    mrb_define_const(mrb, mod, "Number", mrb_int_value(mrb, (mrb_int)(cJSON_Number)));
#endif
#ifdef cJSON_String
    mrb_define_const(mrb, mod, "String", mrb_int_value(mrb, (mrb_int)(cJSON_String)));
#endif
#ifdef cJSON_Array
    mrb_define_const(mrb, mod, "Array", mrb_int_value(mrb, (mrb_int)(cJSON_Array)));
#endif
#ifdef cJSON_Object
    mrb_define_const(mrb, mod, "Object", mrb_int_value(mrb, (mrb_int)(cJSON_Object)));
#endif
#ifdef cJSON_Raw
    mrb_define_const(mrb, mod, "Raw", mrb_int_value(mrb, (mrb_int)(cJSON_Raw)));
#endif
#ifdef cJSON_IsReference
    mrb_define_const(mrb, mod, "IsReference", mrb_int_value(mrb, (mrb_int)(cJSON_IsReference)));
#endif
#ifdef cJSON_StringIsConst
    mrb_define_const(mrb, mod, "StringIsConst", mrb_int_value(mrb, (mrb_int)(cJSON_StringIsConst)));
#endif
}
