/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for mog HTTP/S. */
#include "../src/gen_support_ruby.h"

#include <mog/mog_c.h>
#include <string.h>

static void GenDtor_mog_request_free(void *p)
{
    mog_request *typed = (mog_request *)p;
    mog_request_free(typed);
}

static void GenDtor_mog_response_free(void *p)
{
    mog_response *typed = (mog_response *)p;
    mog_response_free(typed);
}

static void GenDtor_mog_server_free(void *p)
{
    mog_server *typed = (mog_server *)p;
    mog_server_free(typed);
}

static mrb_value GenR_mog_error_code_name(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_error_code a0 = (mog_error_code)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = mog_error_code_name(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_get(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    mog_response * rv = mog_get(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "mog_response", GenDtor_mog_response_free);
    }
}

static mrb_value GenR_mog_perform(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    mog_response * rv = mog_perform(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "mog_response", GenDtor_mog_response_free);
    }
}

static mrb_value GenR_mog_post(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    mog_response * rv = mog_post(a0, (const void *)a1, (size_t)len1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "mog_response", GenDtor_mog_response_free);
    }
}

static mrb_value GenR_mog_request_free(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    mog_request_free(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_new(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request * rv = mog_request_new(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "mog_request", GenDtor_mog_request_free);
    }
}

static mrb_value GenR_mog_request_set_allow_redirects(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_allow_redirects(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_backend(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_backend(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_basic_auth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    mog_request_set_basic_auth(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_bearer_token(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_bearer_token(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_body(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    mog_request_set_body(a0, (const void *)a1, (size_t)len1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_ca_bundle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_ca_bundle(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_client_cert(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    mog_request_set_client_cert(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_connect_timeout_ms(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    long a1 = (long)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_connect_timeout_ms(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_cookie(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    mog_request_set_cookie(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_decompress(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_decompress(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_digest_auth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    mog_request_set_digest_auth(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_header(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    mog_request_set_header(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_json(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_json(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_max_redirects(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_max_redirects(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_max_response_bytes(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    size_t a1 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_max_response_bytes(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_proxy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_proxy(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_query_param(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    mog_request_set_query_param(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_timeout_ms(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    long a1 = (long)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_timeout_ms(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_user_agent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_user_agent(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_request_set_verify_tls(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_request *a0 = (mog_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_request");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_request_set_verify_tls(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_response_backend(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    const char * rv = mog_response_backend(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_response_body(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    size_t io1 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = mog_response_body(a0, &io1);
    mrb_value rets[2];
    rets[0] = (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_mog_response_body_size(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    size_t rv = mog_response_body_size(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_response_downloaded_bytes(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    size_t rv = mog_response_downloaded_bytes(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_response_elapsed_ms(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    long rv = mog_response_elapsed_ms(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_response_error_code(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    mog_error_code rv = mog_response_error_code(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_response_error_message(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    const char * rv = mog_response_error_message(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_response_free(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_response *a0 = (mog_response *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    mog_response_free(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_response_header(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = mog_response_header(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_response_header_count(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    size_t rv = mog_response_header_count(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_response_header_name(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    size_t a1 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = mog_response_header_name(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_response_header_value(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    size_t a1 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = mog_response_header_value(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_response_ok(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    int rv = mog_response_ok(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_response_reason(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    const char * rv = mog_response_reason(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_response_status(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    int rv = mog_response_status(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_response_url(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_response *a0 = (const mog_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_response");
    const char * rv = mog_response_url(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_server_free(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server *a0 = (mog_server *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    mog_server_free(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_server_is_running(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_server *a0 = (const mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    int rv = mog_server_is_running(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_server_last_error(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_server *a0 = (const mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    const char * rv = mog_server_last_error(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_server_new(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server * rv = mog_server_new();
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "mog_server", GenDtor_mog_server_free);
    }
}

static mrb_value GenR_mog_server_port(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_server *a0 = (const mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    unsigned short rv = mog_server_port(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_server_request_body(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server_request");
    size_t io1 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = mog_server_request_body(a0, &io1);
    mrb_value rets[2];
    rets[0] = (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_mog_server_request_client_address(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server_request");
    const char * rv = mog_server_request_client_address(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_server_request_header(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = mog_server_request_header(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_server_request_method(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server_request");
    const char * rv = mog_server_request_method(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_server_request_path(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server_request");
    const char * rv = mog_server_request_path(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_server_request_query(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server_request");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = mog_server_request_query(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_server_request_target(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server_request");
    const char * rv = mog_server_request_target(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_mog_server_response_set_body(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server_response *a0 = (mog_server_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server_response");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    mog_server_response_set_body(a0, (const void *)a1, (size_t)len1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_server_response_set_header(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server_response *a0 = (mog_server_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server_response");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    mog_server_response_set_header(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_server_response_set_status(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server_response *a0 = (mog_server_response *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server_response");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_server_response_set_status(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_server_serve_files(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server *a0 = (mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    mog_server_serve_files(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_server_set_bind_address(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server *a0 = (mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_server_set_bind_address(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_server_set_port(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server *a0 = (mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    unsigned short a1 = (unsigned short)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_server_set_port(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_server_set_threads(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server *a0 = (mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    unsigned int a1 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    mog_server_set_threads(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_server_start(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server *a0 = (mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    int rv = mog_server_start(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_server_stop(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server *a0 = (mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    mog_server_stop(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_server_use_self_signed_tls(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server *a0 = (mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    int rv = mog_server_use_self_signed_tls(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_server_use_tls_files(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server *a0 = (mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = mog_server_use_tls_files(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_mog_server_wait(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    mog_server *a0 = (mog_server *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "mog_server");
    mog_server_wait(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_mog_version(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = mog_version();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

void SDLStaticGen_OpenRuby_mog(mrb_state *mrb);
void SDLStaticGen_OpenRuby_mog(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "MOG");
    mrb_define_module_function(mrb, mod, "error_code_name", GenR_mog_error_code_name, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "get", GenR_mog_get, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "perform", GenR_mog_perform, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "post", GenR_mog_post, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_free", GenR_mog_request_free, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_new", GenR_mog_request_new, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_allow_redirects", GenR_mog_request_set_allow_redirects, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_backend", GenR_mog_request_set_backend, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_basic_auth", GenR_mog_request_set_basic_auth, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_bearer_token", GenR_mog_request_set_bearer_token, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_body", GenR_mog_request_set_body, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_ca_bundle", GenR_mog_request_set_ca_bundle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_client_cert", GenR_mog_request_set_client_cert, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_connect_timeout_ms", GenR_mog_request_set_connect_timeout_ms, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_cookie", GenR_mog_request_set_cookie, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_decompress", GenR_mog_request_set_decompress, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_digest_auth", GenR_mog_request_set_digest_auth, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_header", GenR_mog_request_set_header, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_json", GenR_mog_request_set_json, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_max_redirects", GenR_mog_request_set_max_redirects, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_max_response_bytes", GenR_mog_request_set_max_response_bytes, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_proxy", GenR_mog_request_set_proxy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_query_param", GenR_mog_request_set_query_param, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_timeout_ms", GenR_mog_request_set_timeout_ms, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_user_agent", GenR_mog_request_set_user_agent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "request_set_verify_tls", GenR_mog_request_set_verify_tls, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_backend", GenR_mog_response_backend, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_body", GenR_mog_response_body, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_body_size", GenR_mog_response_body_size, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_downloaded_bytes", GenR_mog_response_downloaded_bytes, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_elapsed_ms", GenR_mog_response_elapsed_ms, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_error_code", GenR_mog_response_error_code, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_error_message", GenR_mog_response_error_message, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_free", GenR_mog_response_free, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_header", GenR_mog_response_header, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_header_count", GenR_mog_response_header_count, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_header_name", GenR_mog_response_header_name, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_header_value", GenR_mog_response_header_value, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_ok", GenR_mog_response_ok, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_reason", GenR_mog_response_reason, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_status", GenR_mog_response_status, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "response_url", GenR_mog_response_url, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_free", GenR_mog_server_free, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_is_running", GenR_mog_server_is_running, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_last_error", GenR_mog_server_last_error, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_new", GenR_mog_server_new, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_port", GenR_mog_server_port, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_request_body", GenR_mog_server_request_body, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_request_client_address", GenR_mog_server_request_client_address, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_request_header", GenR_mog_server_request_header, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_request_method", GenR_mog_server_request_method, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_request_path", GenR_mog_server_request_path, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_request_query", GenR_mog_server_request_query, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_request_target", GenR_mog_server_request_target, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_response_set_body", GenR_mog_server_response_set_body, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_response_set_header", GenR_mog_server_response_set_header, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_response_set_status", GenR_mog_server_response_set_status, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_serve_files", GenR_mog_server_serve_files, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_set_bind_address", GenR_mog_server_set_bind_address, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_set_port", GenR_mog_server_set_port, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_set_threads", GenR_mog_server_set_threads, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_start", GenR_mog_server_start, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_stop", GenR_mog_server_stop, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_use_self_signed_tls", GenR_mog_server_use_self_signed_tls, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_use_tls_files", GenR_mog_server_use_tls_files, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "server_wait", GenR_mog_server_wait, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "version", GenR_mog_version, MRB_ARGS_ANY());
    mrb_define_const(mrb, mod, "MOG_OK", mrb_int_value(mrb, (mrb_int)MOG_OK));
    mrb_define_const(mrb, mod, "MOG_ERR_INVALID_URL", mrb_int_value(mrb, (mrb_int)MOG_ERR_INVALID_URL));
    mrb_define_const(mrb, mod, "MOG_ERR_INVALID_ARGUMENT", mrb_int_value(mrb, (mrb_int)MOG_ERR_INVALID_ARGUMENT));
    mrb_define_const(mrb, mod, "MOG_ERR_UNSUPPORTED_SCHEME", mrb_int_value(mrb, (mrb_int)MOG_ERR_UNSUPPORTED_SCHEME));
    mrb_define_const(mrb, mod, "MOG_ERR_UNSUPPORTED_BACKEND", mrb_int_value(mrb, (mrb_int)MOG_ERR_UNSUPPORTED_BACKEND));
    mrb_define_const(mrb, mod, "MOG_ERR_DNS_FAILED", mrb_int_value(mrb, (mrb_int)MOG_ERR_DNS_FAILED));
    mrb_define_const(mrb, mod, "MOG_ERR_CONNECT_FAILED", mrb_int_value(mrb, (mrb_int)MOG_ERR_CONNECT_FAILED));
    mrb_define_const(mrb, mod, "MOG_ERR_TLS_FAILED", mrb_int_value(mrb, (mrb_int)MOG_ERR_TLS_FAILED));
    mrb_define_const(mrb, mod, "MOG_ERR_TIMEOUT", mrb_int_value(mrb, (mrb_int)MOG_ERR_TIMEOUT));
    mrb_define_const(mrb, mod, "MOG_ERR_IO", mrb_int_value(mrb, (mrb_int)MOG_ERR_IO));
    mrb_define_const(mrb, mod, "MOG_ERR_PROTOCOL", mrb_int_value(mrb, (mrb_int)MOG_ERR_PROTOCOL));
    mrb_define_const(mrb, mod, "MOG_ERR_TOO_MANY_REDIRECTS", mrb_int_value(mrb, (mrb_int)MOG_ERR_TOO_MANY_REDIRECTS));
    mrb_define_const(mrb, mod, "MOG_ERR_HTTP_STATUS", mrb_int_value(mrb, (mrb_int)MOG_ERR_HTTP_STATUS));
    mrb_define_const(mrb, mod, "MOG_ERR_RESPONSE_TOO_LARGE", mrb_int_value(mrb, (mrb_int)MOG_ERR_RESPONSE_TOO_LARGE));
    mrb_define_const(mrb, mod, "MOG_ERR_PROXY", mrb_int_value(mrb, (mrb_int)MOG_ERR_PROXY));
    mrb_define_const(mrb, mod, "MOG_ERR_FILE", mrb_int_value(mrb, (mrb_int)MOG_ERR_FILE));
    mrb_define_const(mrb, mod, "MOG_ERR_JSON", mrb_int_value(mrb, (mrb_int)MOG_ERR_JSON));
    mrb_define_const(mrb, mod, "MOG_ERR_COMPRESSION", mrb_int_value(mrb, (mrb_int)MOG_ERR_COMPRESSION));
    mrb_define_const(mrb, mod, "MOG_ERR_DYNAMIC_LIBRARY", mrb_int_value(mrb, (mrb_int)MOG_ERR_DYNAMIC_LIBRARY));
    mrb_define_const(mrb, mod, "MOG_ERR_INTERNAL", mrb_int_value(mrb, (mrb_int)MOG_ERR_INTERNAL));
}
