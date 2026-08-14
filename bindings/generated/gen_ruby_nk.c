/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for Nuklear. */
#include "../src/gen_support_ruby.h"

#include <SDLStatic/nuklear.h>
#include <string.h>

static void GenRead_nk_color(mrb_state *mrb, mrb_value h, struct nk_color *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->r = (nk_byte)SDLStaticGen_RubyFieldInt(mrb, h, "r");
    out->g = (nk_byte)SDLStaticGen_RubyFieldInt(mrb, h, "g");
    out->b = (nk_byte)SDLStaticGen_RubyFieldInt(mrb, h, "b");
    out->a = (nk_byte)SDLStaticGen_RubyFieldInt(mrb, h, "a");
}

static mrb_value GenPush_nk_color(mrb_state *mrb, const struct nk_color *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "r", mrb_int_value(mrb, (mrb_int)in->r));
    SDLStaticGen_RubyHashSet(mrb, h, "g", mrb_int_value(mrb, (mrb_int)in->g));
    SDLStaticGen_RubyHashSet(mrb, h, "b", mrb_int_value(mrb, (mrb_int)in->b));
    SDLStaticGen_RubyHashSet(mrb, h, "a", mrb_int_value(mrb, (mrb_int)in->a));
    return h;
}

static void GenRead_nk_colorf(mrb_state *mrb, mrb_value h, struct nk_colorf *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->r = (float)SDLStaticGen_RubyFieldNum(mrb, h, "r");
    out->g = (float)SDLStaticGen_RubyFieldNum(mrb, h, "g");
    out->b = (float)SDLStaticGen_RubyFieldNum(mrb, h, "b");
    out->a = (float)SDLStaticGen_RubyFieldNum(mrb, h, "a");
}

static mrb_value GenPush_nk_colorf(mrb_state *mrb, const struct nk_colorf *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "r", mrb_float_value(mrb, (mrb_float)in->r));
    SDLStaticGen_RubyHashSet(mrb, h, "g", mrb_float_value(mrb, (mrb_float)in->g));
    SDLStaticGen_RubyHashSet(mrb, h, "b", mrb_float_value(mrb, (mrb_float)in->b));
    SDLStaticGen_RubyHashSet(mrb, h, "a", mrb_float_value(mrb, (mrb_float)in->a));
    return h;
}

static void GenRead_nk_rect(mrb_state *mrb, mrb_value h, struct nk_rect *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "x");
    out->y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "y");
    out->w = (float)SDLStaticGen_RubyFieldNum(mrb, h, "w");
    out->h = (float)SDLStaticGen_RubyFieldNum(mrb, h, "h");
}

static mrb_value GenPush_nk_rect(mrb_state *mrb, const struct nk_rect *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "x", mrb_float_value(mrb, (mrb_float)in->x));
    SDLStaticGen_RubyHashSet(mrb, h, "y", mrb_float_value(mrb, (mrb_float)in->y));
    SDLStaticGen_RubyHashSet(mrb, h, "w", mrb_float_value(mrb, (mrb_float)in->w));
    SDLStaticGen_RubyHashSet(mrb, h, "h", mrb_float_value(mrb, (mrb_float)in->h));
    return h;
}

static mrb_value GenPush_nk_scroll(mrb_state *mrb, const struct nk_scroll *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "x", mrb_int_value(mrb, (mrb_int)in->x));
    SDLStaticGen_RubyHashSet(mrb, h, "y", mrb_int_value(mrb, (mrb_int)in->y));
    return h;
}

static void GenRead_nk_vec2(mrb_state *mrb, mrb_value h, struct nk_vec2 *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "x");
    out->y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "y");
}

static mrb_value GenPush_nk_vec2(mrb_state *mrb, const struct nk_vec2 *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "x", mrb_float_value(mrb, (mrb_float)in->x));
    SDLStaticGen_RubyHashSet(mrb, h, "y", mrb_float_value(mrb, (mrb_float)in->y));
    return h;
}

static mrb_value GenR_nk__begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_command * rv = nk__begin(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_command");
    }
}

static mrb_value GenR_nk__draw_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_buffer");
    const struct nk_draw_command * rv = nk__draw_begin(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_draw_command");
    }
}

static mrb_value GenR_nk__draw_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_buffer");
    const struct nk_draw_command * rv = nk__draw_end(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_draw_command");
    }
}

static mrb_value GenR_nk__draw_list_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_draw_list *a0 = (const struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_buffer");
    const struct nk_draw_command * rv = nk__draw_list_begin(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_draw_command");
    }
}

static mrb_value GenR_nk__draw_list_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_draw_list *a0 = (const struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_buffer");
    const struct nk_draw_command * rv = nk__draw_list_end(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_draw_command");
    }
}

static mrb_value GenR_nk__draw_list_next(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_draw_command *a0 = (const struct nk_draw_command *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_command");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_buffer");
    const struct nk_draw_list *a2 = (const struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "nk_draw_list");
    const struct nk_draw_command * rv = nk__draw_list_next(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_draw_command");
    }
}

static mrb_value GenR_nk__draw_next(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_draw_command *a0 = (const struct nk_draw_command *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_command");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_buffer");
    const struct nk_context *a2 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "nk_context");
    const struct nk_draw_command * rv = nk__draw_next(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_draw_command");
    }
}

static mrb_value GenR_nk__next(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_command *a1 = (const struct nk_command *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_command");
    const struct nk_command * rv = nk__next(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_command");
    }
}

static mrb_value GenR_nk_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_rect a2;
    GenRead_nk_rect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_begin(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_begin_titled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_rect a3;
    GenRead_nk_rect(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_begin_titled(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_buffer_clear(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_buffer");
    nk_buffer_clear(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_buffer_free(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_buffer");
    nk_buffer_free(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_buffer_info(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_memory_status *a0 = (struct nk_memory_status *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_memory_status");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_buffer");
    nk_buffer_info(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_buffer_init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_buffer");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_allocator");
    nk_size a2 = (nk_size)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_buffer_init(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_buffer_init_default(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_buffer");
    nk_buffer_init_default(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_buffer_mark(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_buffer");
    enum nk_buffer_allocation_type a1 = (enum nk_buffer_allocation_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_buffer_mark(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_buffer_push(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_buffer");
    enum nk_buffer_allocation_type a1 = (enum nk_buffer_allocation_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t len2 = 0;
    const char *a2 = SDLStaticGen_RubyToBlob(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &len2);
    nk_size a4 = (nk_size)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_buffer_push(a0, a1, (const void *)a2, (nk_size)len2, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_buffer_reset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_buffer");
    enum nk_buffer_allocation_type a1 = (enum nk_buffer_allocation_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_buffer_reset(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_buffer_total(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_buffer *a0 = (const struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_buffer");
    nk_size rv = nk_buffer_total(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_button_color(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_bool rv = nk_button_color(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_button_label(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_label_styled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_style_button *a1 = (const struct nk_style_button *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_style_button");
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_button_label_styled(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_pop_behavior(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_button_pop_behavior(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_push_behavior(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_button_behavior a1 = (enum nk_button_behavior)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_button_push_behavior(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_set_behavior(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_button_behavior a1 = (enum nk_button_behavior)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_button_set_behavior(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_button_symbol(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_button_symbol(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_symbol_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_button_symbol_label(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_symbol_label_styled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_style_button *a1 = (const struct nk_style_button *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_style_button");
    enum nk_symbol_type a2 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_button_symbol_label_styled(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_symbol_styled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_style_button *a1 = (const struct nk_style_button *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_style_button");
    enum nk_symbol_type a2 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_button_symbol_styled(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_symbol_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_button_symbol_text(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_symbol_text_styled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_style_button *a1 = (const struct nk_style_button *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_style_button");
    enum nk_symbol_type a2 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_flags a5 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    nk_bool rv = nk_button_symbol_text_styled(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_button_text(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_button_text_styled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_style_button *a1 = (const struct nk_style_button *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_style_button");
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_button_text_styled(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_chart_add_slot(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_chart_type a1 = (enum nk_chart_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_chart_add_slot(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_chart_add_slot_colored(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_chart_type a1 = (enum nk_chart_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    nk_chart_add_slot_colored(a0, a1, a2, a3, a4, a5, a6);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_chart_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_chart_type a1 = (enum nk_chart_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_chart_begin(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_chart_begin_colored(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_chart_type a1 = (enum nk_chart_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    nk_bool rv = nk_chart_begin_colored(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_chart_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_chart_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_chart_push(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags rv = nk_chart_push(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_chart_push_slot(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags rv = nk_chart_push_slot(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_check_flags_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    unsigned int a2 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    unsigned int a3 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    unsigned int rv = nk_check_flags_label(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_check_flags_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    unsigned int a3 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    unsigned int a4 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    unsigned int rv = nk_check_flags_text(a0, a1, a2, a3, a4);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_check_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool a2 = (nk_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_check_label(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_check_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool a3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_check_text(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_check_text_align(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool a3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_flags a5 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    nk_bool rv = nk_check_text_align(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_checkbox_flags_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    unsigned int io2 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    unsigned int a3 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_checkbox_flags_label(a0, a1, &io2, a3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_checkbox_flags_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    unsigned int io3 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    unsigned int a4 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_checkbox_flags_text(a0, a1, a2, &io3, a4);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_checkbox_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool io2 = (nk_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_checkbox_label(a0, a1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io2 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_checkbox_label_align(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool io2 = (nk_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_checkbox_label_align(a0, a1, &io2, a3, a4);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io2 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_checkbox_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool io3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_checkbox_text(a0, a1, a2, &io3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io3 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_checkbox_text_align(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool io3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_flags a5 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    nk_bool rv = nk_checkbox_text_align(a0, a1, a2, &io3, a4, a5);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io3 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_clear(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_clear(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_color_cf(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_color a0;
    GenRead_nk_color(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    struct nk_colorf rv = nk_color_cf(a0);
    return GenPush_nk_colorf(mrb, &rv);
    }
}

static mrb_value GenR_nk_color_d(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    double io0 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    double io1 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    double io2 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    double io3 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_color a4;
    GenRead_nk_color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_color_d(&io0, &io1, &io2, &io3, a4);
    mrb_value rets[4];
    rets[0] = mrb_float_value(mrb, (mrb_float)io0);
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    rets[3] = mrb_float_value(mrb, (mrb_float)io3);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_nk_color_dv(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    double io0 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_color_dv(&io0, a1);
    return mrb_float_value(mrb, (mrb_float)io0);
    }
}

static mrb_value GenR_nk_color_f(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float io0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_color a4;
    GenRead_nk_color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_color_f(&io0, &io1, &io2, &io3, a4);
    mrb_value rets[4];
    rets[0] = mrb_float_value(mrb, (mrb_float)io0);
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    rets[3] = mrb_float_value(mrb, (mrb_float)io3);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_nk_color_fv(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float io0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_color_fv(&io0, a1);
    return mrb_float_value(mrb, (mrb_float)io0);
    }
}

static mrb_value GenR_nk_color_hsv_b(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    nk_byte io0 = (nk_byte)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    nk_byte io1 = (nk_byte)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_byte io2 = (nk_byte)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_color_hsv_b(&io0, &io1, &io2, a3);
    mrb_value rets[3];
    rets[0] = mrb_int_value(mrb, (mrb_int)io0);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_nk_color_hsv_bv(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    nk_byte io0 = (nk_byte)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_color_hsv_bv(&io0, a1);
    return mrb_int_value(mrb, (mrb_int)io0);
    }
}

static mrb_value GenR_nk_color_hsv_f(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float io0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_color_hsv_f(&io0, &io1, &io2, a3);
    mrb_value rets[3];
    rets[0] = mrb_float_value(mrb, (mrb_float)io0);
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_nk_color_hsv_fv(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float io0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_color_hsv_fv(&io0, a1);
    return mrb_float_value(mrb, (mrb_float)io0);
    }
}

static mrb_value GenR_nk_color_hsv_i(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int io0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_color_hsv_i(&io0, &io1, &io2, a3);
    mrb_value rets[3];
    rets[0] = mrb_int_value(mrb, (mrb_int)io0);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_nk_color_hsv_iv(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int io0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_color_hsv_iv(&io0, a1);
    return mrb_int_value(mrb, (mrb_int)io0);
    }
}

static mrb_value GenR_nk_color_hsva_b(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    nk_byte io0 = (nk_byte)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    nk_byte io1 = (nk_byte)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_byte io2 = (nk_byte)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_byte io3 = (nk_byte)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_color a4;
    GenRead_nk_color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_color_hsva_b(&io0, &io1, &io2, &io3, a4);
    mrb_value rets[4];
    rets[0] = mrb_int_value(mrb, (mrb_int)io0);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    rets[3] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_nk_color_hsva_bv(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    nk_byte io0 = (nk_byte)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_color_hsva_bv(&io0, a1);
    return mrb_int_value(mrb, (mrb_int)io0);
    }
}

static mrb_value GenR_nk_color_hsva_f(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float io0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_color a4;
    GenRead_nk_color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_color_hsva_f(&io0, &io1, &io2, &io3, a4);
    mrb_value rets[4];
    rets[0] = mrb_float_value(mrb, (mrb_float)io0);
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    rets[3] = mrb_float_value(mrb, (mrb_float)io3);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_nk_color_hsva_fv(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float io0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_color_hsva_fv(&io0, a1);
    return mrb_float_value(mrb, (mrb_float)io0);
    }
}

static mrb_value GenR_nk_color_hsva_i(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int io0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_color a4;
    GenRead_nk_color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_color_hsva_i(&io0, &io1, &io2, &io3, a4);
    mrb_value rets[4];
    rets[0] = mrb_int_value(mrb, (mrb_int)io0);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    rets[3] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_nk_color_hsva_iv(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int io0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_color_hsva_iv(&io0, a1);
    return mrb_int_value(mrb, (mrb_int)io0);
    }
}

static mrb_value GenR_nk_color_pick(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_colorf out1;
    memset(&out1, 0, sizeof(out1));
    enum nk_color_format a2 = (enum nk_color_format)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_color_pick(a0, &out1, a2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_nk_colorf(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_color_picker(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_colorf a1;
    GenRead_nk_colorf(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    enum nk_color_format a2 = (enum nk_color_format)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_colorf rv = nk_color_picker(a0, a1, a2);
    return GenPush_nk_colorf(mrb, &rv);
    }
}

static mrb_value GenR_nk_color_u32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_color a0;
    GenRead_nk_color(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    nk_uint rv = nk_color_u32(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_colorf_hsva_f(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float io0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_colorf a4;
    GenRead_nk_colorf(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_colorf_hsva_f(&io0, &io1, &io2, &io3, a4);
    mrb_value rets[4];
    rets[0] = mrb_float_value(mrb, (mrb_float)io0);
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    rets[3] = mrb_float_value(mrb, (mrb_float)io3);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_nk_colorf_hsva_fv(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float io0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_colorf a1;
    GenRead_nk_colorf(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_colorf_hsva_fv(&io0, a1);
    return mrb_float_value(mrb, (mrb_float)io0);
    }
}

static mrb_value GenR_nk_combo_begin_color(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_bool rv = nk_combo_begin_color(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_combo_begin_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_bool rv = nk_combo_begin_label(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_combo_begin_symbol(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_bool rv = nk_combo_begin_symbol(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_combo_begin_symbol_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    enum nk_symbol_type a2 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_vec2 a3;
    GenRead_nk_vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_bool rv = nk_combo_begin_symbol_label(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_combo_begin_symbol_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    enum nk_symbol_type a3 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_vec2 a4;
    GenRead_nk_vec2(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_bool rv = nk_combo_begin_symbol_text(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_combo_begin_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_vec2 a3;
    GenRead_nk_vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_bool rv = nk_combo_begin_text(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_combo_close(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_combo_close(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_combo_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_combo_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_combo_item_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a2 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_combo_item_label(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_combo_item_symbol_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_combo_item_symbol_label(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_combo_item_symbol_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_combo_item_symbol_text(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_combo_item_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_combo_item_text(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_combo_separator(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int a5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    struct nk_vec2 a6;
    GenRead_nk_vec2(mrb, (argc > 6 ? argv[6] : mrb_nil_value()), &a6);
    int rv = nk_combo_separator(a0, a1, a2, a3, a4, a5, a6);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_combo_string(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    struct nk_vec2 a5;
    GenRead_nk_vec2(mrb, (argc > 5 ? argv[5] : mrb_nil_value()), &a5);
    int rv = nk_combo_string(a0, a1, a2, a3, a4, a5);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_combobox_separator(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int a5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    struct nk_vec2 a6;
    GenRead_nk_vec2(mrb, (argc > 6 ? argv[6] : mrb_nil_value()), &a6);
    nk_bool rv = nk_combobox_separator(a0, a1, a2, &io3, a4, a5, a6);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_combobox_string(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    struct nk_vec2 a5;
    GenRead_nk_vec2(mrb, (argc > 5 ? argv[5] : mrb_nil_value()), &a5);
    nk_bool rv = nk_combobox_string(a0, a1, &io2, a3, a4, a5);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_contextual_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_flags a1 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    struct nk_rect a3;
    GenRead_nk_rect(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_bool rv = nk_contextual_begin(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_contextual_close(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_contextual_close(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_contextual_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_contextual_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_contextual_item_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a2 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_contextual_item_label(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_contextual_item_symbol_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_contextual_item_symbol_label(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_contextual_item_symbol_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_contextual_item_symbol_text(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_contextual_item_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_contextual_item_text(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_convert(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_buffer *a1 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_buffer");
    struct nk_buffer *a2 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "nk_buffer");
    struct nk_buffer *a3 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), "nk_buffer");
    const struct nk_convert_config *a4 = (const struct nk_convert_config *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), "nk_convert_config");
    nk_flags rv = nk_convert(a0, a1, a2, a3, a4);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_draw_image(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    const struct nk_image *a2 = (const struct nk_image *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "nk_image");
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_draw_image(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_add_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    const struct nk_user_font *a1 = (const struct nk_user_font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_user_font");
    struct nk_rect a2;
    GenRead_nk_rect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    struct nk_color a6;
    GenRead_nk_color(mrb, (argc > 6 ? argv[6] : mrb_nil_value()), &a6);
    nk_draw_list_add_text(a0, a1, a2, a3, a4, a5, a6);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_fill_circle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    unsigned int a4 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_draw_list_fill_circle(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_fill_poly_convex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 tmp1;
    const struct nk_vec2 *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_nk_vec2(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    unsigned int a2 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    enum nk_anti_aliasing a4 = (enum nk_anti_aliasing)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_draw_list_fill_poly_convex(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_fill_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_draw_list_fill_rect(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_fill_rect_multi_color(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    struct nk_color a4;
    GenRead_nk_color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    struct nk_color a5;
    GenRead_nk_color(mrb, (argc > 5 ? argv[5] : mrb_nil_value()), &a5);
    nk_draw_list_fill_rect_multi_color(a0, a1, a2, a3, a4, a5);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_fill_triangle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    struct nk_vec2 a3;
    GenRead_nk_vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    struct nk_color a4;
    GenRead_nk_color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_draw_list_fill_triangle(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    nk_draw_list_init(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_path_arc_to(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    unsigned int a5 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    nk_draw_list_path_arc_to(a0, a1, a2, a3, a4, a5);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_path_arc_to_fast(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_draw_list_path_arc_to_fast(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_path_clear(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    nk_draw_list_path_clear(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_path_curve_to(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    struct nk_vec2 a3;
    GenRead_nk_vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    unsigned int a4 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_draw_list_path_curve_to(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_path_fill(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_draw_list_path_fill(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_path_line_to(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_draw_list_path_line_to(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_path_rect_to(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_draw_list_path_rect_to(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_path_stroke(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    enum nk_draw_list_stroke a2 = (enum nk_draw_list_stroke)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_draw_list_path_stroke(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_setup(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    const struct nk_convert_config *a1 = (const struct nk_convert_config *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_convert_config");
    struct nk_buffer *a2 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "nk_buffer");
    struct nk_buffer *a3 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), "nk_buffer");
    struct nk_buffer *a4 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), "nk_buffer");
    enum nk_anti_aliasing a5 = (enum nk_anti_aliasing)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    enum nk_anti_aliasing a6 = (enum nk_anti_aliasing)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    nk_draw_list_setup(a0, a1, a2, a3, a4, a5, a6);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_stroke_circle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    unsigned int a4 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    nk_draw_list_stroke_circle(a0, a1, a2, a3, a4, a5);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_stroke_curve(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    struct nk_vec2 a3;
    GenRead_nk_vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    struct nk_vec2 a4;
    GenRead_nk_vec2(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    struct nk_color a5;
    GenRead_nk_color(mrb, (argc > 5 ? argv[5] : mrb_nil_value()), &a5);
    unsigned int a6 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    float a7 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    nk_draw_list_stroke_curve(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_stroke_line(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_draw_list_stroke_line(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_stroke_poly_line(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 tmp1;
    const struct nk_vec2 *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_nk_vec2(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    unsigned int a2 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    enum nk_draw_list_stroke a4 = (enum nk_draw_list_stroke)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    enum nk_anti_aliasing a6 = (enum nk_anti_aliasing)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    nk_draw_list_stroke_poly_line(a0, a1, a2, a3, a4, a5, a6);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_stroke_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_draw_list_stroke_rect(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_list_stroke_triangle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    struct nk_vec2 a3;
    GenRead_nk_vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    struct nk_color a4;
    GenRead_nk_color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    nk_draw_list_stroke_triangle(a0, a1, a2, a3, a4, a5);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_nine_slice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    const struct nk_nine_slice *a2 = (const struct nk_nine_slice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "nk_nine_slice");
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_draw_nine_slice(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_draw_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    const struct nk_user_font *a4 = (const struct nk_user_font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), "nk_user_font");
    struct nk_color a5;
    GenRead_nk_color(mrb, (argc > 5 ? argv[5] : mrb_nil_value()), &a5);
    struct nk_color a6;
    GenRead_nk_color(mrb, (argc > 6 ? argv[6] : mrb_nil_value()), &a6);
    nk_draw_text(a0, a1, a2, a3, a4, a5, a6);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_edit_focus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_flags a1 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_edit_focus(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_edit_unfocus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_edit_unfocus(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_fill_arc(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    struct nk_color a6;
    GenRead_nk_color(mrb, (argc > 6 ? argv[6] : mrb_nil_value()), &a6);
    nk_fill_arc(a0, a1, a2, a3, a4, a5, a6);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_fill_circle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_fill_circle(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_fill_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_fill_rect(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_fill_rect_multi_color(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    struct nk_color a4;
    GenRead_nk_color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    struct nk_color a5;
    GenRead_nk_color(mrb, (argc > 5 ? argv[5] : mrb_nil_value()), &a5);
    nk_fill_rect_multi_color(a0, a1, a2, a3, a4, a5);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_fill_triangle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    struct nk_color a7;
    GenRead_nk_color(mrb, (argc > 7 ? argv[7] : mrb_nil_value()), &a7);
    nk_fill_triangle(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_filter_ascii(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_rune a1 = (nk_rune)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_filter_ascii(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_filter_binary(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_rune a1 = (nk_rune)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_filter_binary(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_filter_decimal(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_rune a1 = (nk_rune)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_filter_decimal(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_filter_default(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_rune a1 = (nk_rune)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_filter_default(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_filter_float(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_rune a1 = (nk_rune)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_filter_float(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_filter_hex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_rune a1 = (nk_rune)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_filter_hex(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_filter_oct(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_rune a1 = (nk_rune)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_filter_oct(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_font_atlas_add(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_font_atlas");
    const struct nk_font_config *a1 = (const struct nk_font_config *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_font_config");
    struct nk_font * rv = nk_font_atlas_add(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_font");
    }
}

static mrb_value GenR_nk_font_atlas_add_compressed_base85(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_font_atlas");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const struct nk_font_config *a3 = (const struct nk_font_config *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), "nk_font_config");
    struct nk_font * rv = nk_font_atlas_add_compressed_base85(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_font");
    }
}

static mrb_value GenR_nk_font_atlas_add_default(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_font_atlas");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const struct nk_font_config *a2 = (const struct nk_font_config *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "nk_font_config");
    struct nk_font * rv = nk_font_atlas_add_default(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_font");
    }
}

static mrb_value GenR_nk_font_atlas_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_font_atlas");
    nk_font_atlas_begin(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_font_atlas_cleanup(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_font_atlas");
    nk_font_atlas_cleanup(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_font_atlas_clear(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_font_atlas");
    nk_font_atlas_clear(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_font_atlas_init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_font_atlas");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_allocator");
    nk_font_atlas_init(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_font_atlas_init_custom(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_font_atlas");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_allocator");
    const struct nk_allocator *a2 = (const struct nk_allocator *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "nk_allocator");
    nk_font_atlas_init_custom(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_font_atlas_init_default(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_font_atlas");
    nk_font_atlas_init_default(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_free(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_free(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_get_null_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_rect rv = nk_get_null_rect();
    return GenPush_nk_rect(mrb, &rv);
    }
}

static mrb_value GenR_nk_group_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a2 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_group_begin(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_group_begin_titled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_group_begin_titled(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_group_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_group_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_group_get_scroll(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_uint io2 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_uint io3 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_group_get_scroll(a0, a1, &io2, &io3);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)io2);
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_group_scrolled_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_scroll out1;
    memset(&out1, 0, sizeof(out1));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_group_scrolled_begin(a0, &out1, a2, a3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_nk_scroll(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_group_scrolled_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_group_scrolled_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_group_scrolled_offset_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_uint io1 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_uint io2 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_group_scrolled_offset_begin(a0, &io1, &io2, a3, a4);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_nk_group_set_scroll(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_uint a2 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_uint a3 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_group_set_scroll(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_hsv(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color rv = nk_hsv(a0, a1, a2);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_hsv_f(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color rv = nk_hsv_f(a0, a1, a2);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_hsva(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_color rv = nk_hsva(a0, a1, a2, a3);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_hsva_colorf(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_colorf rv = nk_hsva_colorf(a0, a1, a2, a3);
    return GenPush_nk_colorf(mrb, &rv);
    }
}

static mrb_value GenR_nk_hsva_f(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_color rv = nk_hsva_f(a0, a1, a2, a3);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_image_is_subimage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_image *a0 = (const struct nk_image *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_image");
    nk_bool rv = nk_image_is_subimage(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_allocator");
    const struct nk_user_font *a2 = (const struct nk_user_font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "nk_user_font");
    nk_bool rv = nk_init(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_init_custom(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_buffer *a1 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_buffer");
    struct nk_buffer *a2 = (struct nk_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "nk_buffer");
    const struct nk_user_font *a3 = (const struct nk_user_font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), "nk_user_font");
    nk_bool rv = nk_init_custom(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_init_default(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_user_font *a1 = (const struct nk_user_font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_user_font");
    nk_bool rv = nk_init_default(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_any_mouse_click_in_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_bool rv = nk_input_any_mouse_click_in_rect(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_input_begin(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_input_button(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool a4 = (nk_bool)SDLStaticGen_RubyToBool((argc > 4 ? argv[4] : mrb_nil_value()));
    nk_input_button(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_input_char(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    char a1 = (char)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_input_char(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_input_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_input_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_input_has_mouse_click(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_input_has_mouse_click(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_has_mouse_click_down_in_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_rect a2;
    GenRead_nk_rect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_bool a3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_input_has_mouse_click_down_in_rect(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_has_mouse_click_in_button_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_rect a2;
    GenRead_nk_rect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_bool rv = nk_input_has_mouse_click_in_button_rect(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_has_mouse_click_in_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_rect a2;
    GenRead_nk_rect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_bool rv = nk_input_has_mouse_click_in_rect(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_is_key_down(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_keys a1 = (enum nk_keys)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_input_is_key_down(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_is_key_pressed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_keys a1 = (enum nk_keys)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_input_is_key_pressed(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_is_key_released(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_keys a1 = (enum nk_keys)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_input_is_key_released(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_is_mouse_click_down_in_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_rect a2;
    GenRead_nk_rect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_bool a3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_input_is_mouse_click_down_in_rect(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_is_mouse_click_in_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_rect a2;
    GenRead_nk_rect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_bool rv = nk_input_is_mouse_click_in_rect(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_is_mouse_down(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_input_is_mouse_down(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_is_mouse_hovering_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_bool rv = nk_input_is_mouse_hovering_rect(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_is_mouse_moved(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    nk_bool rv = nk_input_is_mouse_moved(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_is_mouse_pressed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_input_is_mouse_pressed(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_is_mouse_prev_hovering_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_bool rv = nk_input_is_mouse_prev_hovering_rect(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_is_mouse_released(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_input_is_mouse_released(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_key(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_keys a1 = (enum nk_keys)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool a2 = (nk_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    nk_input_key(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_input_motion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_input_motion(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_input_mouse_clicked(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_rect a2;
    GenRead_nk_rect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_bool rv = nk_input_mouse_clicked(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_input_scroll(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_input_scroll(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_input_unicode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_rune a1 = (nk_rune)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_input_unicode(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_item_is_any_active(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_item_is_any_active(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_knob_float(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    enum nk_heading a5 = (enum nk_heading)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    nk_bool rv = nk_knob_float(a0, a1, &io2, a3, a4, a5, a6);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_knob_int(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    enum nk_heading a5 = (enum nk_heading)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    nk_bool rv = nk_knob_int(a0, a1, &io2, a3, a4, a5, a6);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a2 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_label(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_label_colored(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a2 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_label_colored(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_label_colored_wrap(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_label_colored_wrap(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_label_wrap(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_label_wrap(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_ratio_from_pixel(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float rv = nk_layout_ratio_from_pixel(a0, a1);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_nk_layout_reset_min_row_height(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_layout_reset_min_row_height(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_row_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_layout_format a1 = (enum nk_layout_format)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_layout_row_begin(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_row_dynamic(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_layout_row_dynamic(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_row_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_layout_row_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_row_push(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_layout_row_push(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_row_static(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_layout_row_static(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_row_template_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_layout_row_template_begin(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_row_template_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_layout_row_template_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_row_template_push_dynamic(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_layout_row_template_push_dynamic(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_row_template_push_static(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_layout_row_template_push_static(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_row_template_push_variable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_layout_row_template_push_variable(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_set_min_row_height(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_layout_set_min_row_height(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_space_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_layout_format a1 = (enum nk_layout_format)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_layout_space_begin(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_space_bounds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_rect rv = nk_layout_space_bounds(a0);
    return GenPush_nk_rect(mrb, &rv);
    }
}

static mrb_value GenR_nk_layout_space_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_layout_space_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_space_push(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_layout_space_push(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_layout_space_rect_to_local(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_rect rv = nk_layout_space_rect_to_local(a0, a1);
    return GenPush_nk_rect(mrb, &rv);
    }
}

static mrb_value GenR_nk_layout_space_rect_to_screen(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_rect rv = nk_layout_space_rect_to_screen(a0, a1);
    return GenPush_nk_rect(mrb, &rv);
    }
}

static mrb_value GenR_nk_layout_space_to_local(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_vec2 rv = nk_layout_space_to_local(a0, a1);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_layout_space_to_screen(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_vec2 rv = nk_layout_space_to_screen(a0, a1);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_layout_widget_bounds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_rect rv = nk_layout_widget_bounds(a0);
    return GenPush_nk_rect(mrb, &rv);
    }
}

static mrb_value GenR_nk_list_view_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_list_view *a1 = (struct nk_list_view *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_list_view");
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int a5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    nk_bool rv = nk_list_view_begin(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_list_view_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_list_view *a0 = (struct nk_list_view *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_list_view");
    nk_list_view_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_menu_begin_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a2 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_vec2 a3;
    GenRead_nk_vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_bool rv = nk_menu_begin_label(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_menu_begin_symbol(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    enum nk_symbol_type a2 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_vec2 a3;
    GenRead_nk_vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_bool rv = nk_menu_begin_symbol(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_menu_begin_symbol_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a2 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    enum nk_symbol_type a3 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_vec2 a4;
    GenRead_nk_vec2(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_bool rv = nk_menu_begin_symbol_label(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_menu_begin_symbol_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    enum nk_symbol_type a4 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    struct nk_vec2 a5;
    GenRead_nk_vec2(mrb, (argc > 5 ? argv[5] : mrb_nil_value()), &a5);
    nk_bool rv = nk_menu_begin_symbol_text(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_menu_begin_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_vec2 a4;
    GenRead_nk_vec2(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_bool rv = nk_menu_begin_text(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_menu_close(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_menu_close(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_menu_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_menu_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_menu_item_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a2 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_menu_item_label(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_menu_item_symbol_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_menu_item_symbol_label(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_menu_item_symbol_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_menu_item_symbol_text(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_menu_item_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_menu_item_text(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_menubar_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_menubar_begin(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_menubar_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_menubar_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_murmur_hash(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t len0 = 0;
    const char *a0 = SDLStaticGen_RubyToBlob(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &len0);
    nk_hash a2 = (nk_hash)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_hash rv = nk_murmur_hash((const void *)a0, (int)len0, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_nine_slice_is_sub9slice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_nine_slice *a0 = (const struct nk_nine_slice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_nine_slice");
    int rv = nk_nine_slice_is_sub9slice(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_option_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool a2 = (nk_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_option_label(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_option_label_align(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool a2 = (nk_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_option_label_align(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_option_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool a3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_option_text(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_option_text_align(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool a3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_flags a5 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    nk_bool rv = nk_option_text_align(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_popup_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_popup_type a1 = (enum nk_popup_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_rect a4;
    GenRead_nk_rect(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_bool rv = nk_popup_begin(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_popup_close(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_popup_close(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_popup_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_popup_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_popup_get_scroll(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_uint io1 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_uint io2 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_popup_get_scroll(a0, &io1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)io1);
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_popup_set_scroll(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_uint a1 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_uint a2 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_popup_set_scroll(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_prog(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_size a1 = (nk_size)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_size a2 = (nk_size)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool a3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_size rv = nk_prog(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_progress(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_size io1 = (nk_size)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_size a2 = (nk_size)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool a3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_progress(a0, &io1, a2, a3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_property_double(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    double a2 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    double io3 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    double a4 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    double a5 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    nk_bool rv = nk_property_double(a0, a1, a2, &io3, a4, a5, a6);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_property_float(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    nk_bool rv = nk_property_float(a0, a1, a2, &io3, a4, a5, a6);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_property_int(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int a5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    nk_bool rv = nk_property_int(a0, a1, a2, &io3, a4, a5, a6);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_propertyd(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    double a2 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    double a3 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    double a4 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    double a5 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    double rv = nk_propertyd(a0, a1, a2, a3, a4, a5, a6);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_nk_propertyf(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    float rv = nk_propertyf(a0, a1, a2, a3, a4, a5, a6);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_nk_propertyi(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int a5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    int rv = nk_propertyi(a0, a1, a2, a3, a4, a5, a6);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_push_scissor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_push_scissor(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_radio_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool io2 = (nk_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_radio_label(a0, a1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io2 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_radio_label_align(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool io2 = (nk_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_radio_label_align(a0, a1, &io2, a3, a4);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io2 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_radio_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool io3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_radio_text(a0, a1, a2, &io3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io3 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_radio_text_align(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool io3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_flags a5 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    nk_bool rv = nk_radio_text_align(a0, a1, a2, &io3, a4, a5);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io3 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_rect rv = nk_rect(a0, a1, a2, a3);
    return GenPush_nk_rect(mrb, &rv);
    }
}

static mrb_value GenR_nk_rect_pos(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_rect a0;
    GenRead_nk_rect(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    struct nk_vec2 rv = nk_rect_pos(a0);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_rect_size(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_rect a0;
    GenRead_nk_rect(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    struct nk_vec2 rv = nk_rect_size(a0);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_recta(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_vec2 a0;
    GenRead_nk_vec2(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    struct nk_vec2 a1;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    struct nk_rect rv = nk_recta(a0, a1);
    return GenPush_nk_rect(mrb, &rv);
    }
}

static mrb_value GenR_nk_recti(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_rect rv = nk_recti(a0, a1, a2, a3);
    return GenPush_nk_rect(mrb, &rv);
    }
}

static mrb_value GenR_nk_rgb(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color rv = nk_rgb(a0, a1, a2);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_rgb_cf(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_colorf a0;
    GenRead_nk_colorf(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    struct nk_color rv = nk_rgb_cf(a0);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_rgb_f(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color rv = nk_rgb_f(a0, a1, a2);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_rgb_factor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_color a0;
    GenRead_nk_color(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_color rv = nk_rgb_factor(a0, a1);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_rgb_hex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_color rv = nk_rgb_hex(a0);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_rgba(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_color rv = nk_rgba(a0, a1, a2, a3);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_rgba_cf(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_colorf a0;
    GenRead_nk_colorf(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    struct nk_color rv = nk_rgba_cf(a0);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_rgba_f(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_color rv = nk_rgba_f(a0, a1, a2, a3);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_rgba_hex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_color rv = nk_rgba_hex(a0);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_rgba_u32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    nk_uint a0 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    struct nk_color rv = nk_rgba_u32(a0);
    return GenPush_nk_color(mrb, &rv);
    }
}

static mrb_value GenR_nk_rule_horizontal(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_color a1;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    nk_bool a2 = (nk_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    nk_rule_horizontal(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_select_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a2 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool a3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_select_label(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_select_symbol_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool a4 = (nk_bool)SDLStaticGen_RubyToBool((argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_select_symbol_label(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_select_symbol_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool a5 = (nk_bool)SDLStaticGen_RubyToBool((argc > 5 ? argv[5] : mrb_nil_value()));
    nk_bool rv = nk_select_symbol_text(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_select_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool a4 = (nk_bool)SDLStaticGen_RubyToBool((argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_select_text(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_selectable_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a2 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool io3 = (nk_bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_selectable_label(a0, a1, a2, &io3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io3 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_selectable_symbol_label(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool io4 = (nk_bool)SDLStaticGen_RubyToBool((argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_selectable_symbol_label(a0, a1, a2, a3, &io4);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io4 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_selectable_symbol_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_flags a4 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool io5 = (nk_bool)SDLStaticGen_RubyToBool((argc > 5 ? argv[5] : mrb_nil_value()));
    nk_bool rv = nk_selectable_symbol_text(a0, a1, a2, a3, a4, &io5);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io5 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_selectable_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool io4 = (nk_bool)SDLStaticGen_RubyToBool((argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_selectable_text(a0, a1, a2, a3, &io4);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io4 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_slide_float(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float rv = nk_slide_float(a0, a1, a2, a3, a4);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_nk_slide_int(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int rv = nk_slide_int(a0, a1, a2, a3, a4);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_slider_float(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_slider_float(a0, a1, &io2, a3, a4);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_slider_int(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    nk_bool rv = nk_slider_int(a0, a1, &io2, a3, a4);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_spacer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_spacer(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_spacing(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_spacing(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_str_append_str_char(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = nk_str_append_str_char(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_append_str_utf8(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = nk_str_append_str_utf8(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_append_text_char(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = nk_str_append_text_char(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_append_text_utf8(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = nk_str_append_text_utf8(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_at_char_const(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = nk_str_at_char_const(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_nk_str_at_const(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_rune io2 = (nk_rune)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    const char * rv = nk_str_at_const(a0, a1, &io2, &io3);
    mrb_value rets[3];
    rets[0] = (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    rets[2] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_nk_str_clear(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    nk_str_clear(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_str_delete_chars(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_str_delete_chars(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_str_delete_runes(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_str_delete_runes(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_str_free(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    nk_str_free(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_str_get_const(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    const char * rv = nk_str_get_const(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_nk_str_init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_allocator");
    nk_size a2 = (nk_size)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_str_init(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_str_init_default(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    nk_str_init_default(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_str_insert_at_char(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int rv = nk_str_insert_at_char(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_insert_at_rune(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int rv = nk_str_insert_at_rune(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_insert_str_char(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = nk_str_insert_str_char(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_insert_str_utf8(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = nk_str_insert_str_utf8(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_insert_text_char(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int rv = nk_str_insert_text_char(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_insert_text_utf8(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int rv = nk_str_insert_text_utf8(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_len(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int rv = nk_str_len(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_len_char(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int rv = nk_str_len_char(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_str_remove_chars(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_str_remove_chars(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_str_remove_runes(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_str_remove_runes(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_str_rune_at(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_str");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_rune rv = nk_str_rune_at(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_strfilter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = nk_strfilter(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_stricmp(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = nk_stricmp(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_stricmpn(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = nk_stricmpn(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_strlen(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = nk_strlen(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_strmatch_fuzzy_string(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = nk_strmatch_fuzzy_string(a0, a1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_strmatch_fuzzy_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int rv = nk_strmatch_fuzzy_text(a0, a1, a2, &io3);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_stroke_arc(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    struct nk_color a7;
    GenRead_nk_color(mrb, (argc > 7 ? argv[7] : mrb_nil_value()), &a7);
    nk_stroke_arc(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_stroke_circle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_stroke_circle(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_stroke_curve(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    float a7 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    float a8 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    float a9 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 9 ? argv[9] : mrb_nil_value()));
    struct nk_color a10;
    GenRead_nk_color(mrb, (argc > 10 ? argv[10] : mrb_nil_value()), &a10);
    nk_stroke_curve(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_stroke_line(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    struct nk_color a6;
    GenRead_nk_color(mrb, (argc > 6 ? argv[6] : mrb_nil_value()), &a6);
    nk_stroke_line(a0, a1, a2, a3, a4, a5, a6);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_stroke_rect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_color a4;
    GenRead_nk_color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_stroke_rect(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_stroke_triangle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_command_buffer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    float a7 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    struct nk_color a8;
    GenRead_nk_color(mrb, (argc > 8 ? argv[8] : mrb_nil_value()), &a8);
    nk_stroke_triangle(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_style_default(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_style_default(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_style_from_table(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_color tmp1;
    const struct nk_color *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_nk_color(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    nk_style_from_table(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_style_get_color_by_name(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    enum nk_style_colors a0 = (enum nk_style_colors)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = nk_style_get_color_by_name(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_nk_style_hide_cursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_style_hide_cursor(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_style_load_all_cursors(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_cursor *a1 = (const struct nk_cursor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_cursor");
    nk_style_load_all_cursors(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_style_load_cursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_style_cursor a1 = (enum nk_style_cursor)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const struct nk_cursor *a2 = (const struct nk_cursor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "nk_cursor");
    nk_style_load_cursor(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_style_pop_color(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_style_pop_color(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_style_pop_flags(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_style_pop_flags(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_style_pop_float(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_style_pop_float(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_style_pop_font(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_style_pop_font(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_style_pop_style_item(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_style_pop_style_item(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_style_pop_vec2(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_style_pop_vec2(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_style_push_color(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_color out1;
    memset(&out1, 0, sizeof(out1));
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a2);
    nk_bool rv = nk_style_push_color(a0, &out1, a2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_nk_color(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_style_push_flags(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_flags io1 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_flags a2 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_style_push_flags(a0, &io1, a2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_style_push_float(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_style_push_float(a0, &io1, a2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_style_push_font(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_user_font *a1 = (const struct nk_user_font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_user_font");
    nk_bool rv = nk_style_push_font(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_style_push_vec2(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 out1;
    memset(&out1, 0, sizeof(out1));
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a2);
    nk_bool rv = nk_style_push_vec2(a0, &out1, a2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_nk_vec2(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_style_set_cursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_style_cursor a1 = (enum nk_style_cursor)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_style_set_cursor(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_style_set_font(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const struct nk_user_font *a1 = (const struct nk_user_font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_user_font");
    nk_style_set_font(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_style_show_cursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_style_show_cursor(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_text(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_text_colored(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_flags a3 = (nk_flags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    struct nk_color a4;
    GenRead_nk_color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    nk_text_colored(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_text_wrap(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_text_wrap(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_text_wrap_colored(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_color a3;
    GenRead_nk_color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_text_wrap_colored(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_textedit_cut(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_bool rv = nk_textedit_cut(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_textedit_delete(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_textedit_delete(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_textedit_delete_selection(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_textedit_delete_selection(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_textedit_free(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_textedit_free(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_textedit_init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "nk_allocator");
    nk_size a2 = (nk_size)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_textedit_init(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_textedit_init_default(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_textedit_init_default(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_textedit_paste(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_textedit_paste(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_textedit_redo(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_textedit_redo(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_textedit_select_all(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_textedit_select_all(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_textedit_text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_textedit_text(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_textedit_undo(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_text_edit");
    nk_textedit_undo(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_tooltip(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_tooltip(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_tooltip_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_tooltip_begin(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_tooltip_begin_offset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    enum nk_tooltip_pos a2 = (enum nk_tooltip_pos)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_vec2 a3;
    GenRead_nk_vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_bool rv = nk_tooltip_begin_offset(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_tooltip_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_tooltip_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_tooltip_offset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    enum nk_tooltip_pos a2 = (enum nk_tooltip_pos)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    struct nk_vec2 a3;
    GenRead_nk_vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    nk_tooltip_offset(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_tree_element_pop(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_tree_element_pop(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_tree_element_push_hashed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_tree_type a1 = (enum nk_tree_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    enum nk_collapse_states a3 = (enum nk_collapse_states)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool io4 = (nk_bool)SDLStaticGen_RubyToBool((argc > 4 ? argv[4] : mrb_nil_value()));
    const char *a5 = SDLStaticGen_RubyToStr(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    int a6 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    int a7 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    nk_bool rv = nk_tree_element_push_hashed(a0, a1, a2, a3, &io4, a5, a6, a7);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io4 != 0));
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_tree_pop(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_tree_pop(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_tree_push_hashed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_tree_type a1 = (enum nk_tree_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    enum nk_collapse_states a3 = (enum nk_collapse_states)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    const char *a4 = SDLStaticGen_RubyToStr(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int a5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    int a6 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    nk_bool rv = nk_tree_push_hashed(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_tree_state_pop(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_tree_state_pop(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_tree_state_push(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_tree_type a1 = (enum nk_tree_type)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    enum nk_collapse_states io3 = (enum nk_collapse_states)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_bool rv = nk_tree_state_push(a0, a1, a2, &io3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_triangle_from_direction(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_vec2 out0;
    memset(&out0, 0, sizeof(out0));
    struct nk_rect a1;
    GenRead_nk_rect(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a1);
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    enum nk_heading a4 = (enum nk_heading)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_triangle_from_direction(&out0, a1, a2, a3, a4);
    return GenPush_nk_vec2(mrb, &out0);
    }
}

static mrb_value GenR_nk_utf_at(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_rune io3 = (nk_rune)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int io4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    const char * rv = nk_utf_at(a0, a1, a2, &io3, &io4);
    mrb_value rets[3];
    rets[0] = (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    rets[2] = mrb_int_value(mrb, (mrb_int)io4);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_nk_utf_decode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    nk_rune io1 = (nk_rune)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = nk_utf_decode(a0, &io1, a2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_utf_len(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = nk_utf_len(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_nk_value_bool(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_value_bool(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_value_color_byte(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_value_color_byte(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_value_color_float(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_value_color_float(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_value_color_hex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_color a2;
    GenRead_nk_color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_value_color_hex(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_value_float(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_value_float(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_value_int(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_value_int(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_value_uint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    unsigned int a2 = (unsigned int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_value_uint(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_vec2(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_vec2 rv = nk_vec2(a0, a1);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_vec2i(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_vec2 rv = nk_vec2i(a0, a1);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_widget(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_rect out0;
    memset(&out0, 0, sizeof(out0));
    const struct nk_context *a1 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_widget_layout_states rv = nk_widget(&out0, a1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_nk_rect(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_widget_bounds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_rect rv = nk_widget_bounds(a0);
    return GenPush_nk_rect(mrb, &rv);
    }
}

static mrb_value GenR_nk_widget_disable_begin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_widget_disable_begin(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_widget_disable_end(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_widget_disable_end(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_widget_fitting(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_rect out0;
    memset(&out0, 0, sizeof(out0));
    const struct nk_context *a1 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a2);
    enum nk_widget_layout_states rv = nk_widget_fitting(&out0, a1, a2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_nk_rect(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_widget_has_mouse_click_down(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool a2 = (nk_bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    nk_bool rv = nk_widget_has_mouse_click_down(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_widget_height(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float rv = nk_widget_height(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_nk_widget_is_hovered(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_widget_is_hovered(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_widget_is_mouse_clicked(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    enum nk_buttons a1 = (enum nk_buttons)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_widget_is_mouse_clicked(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_widget_position(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 rv = nk_widget_position(a0);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_widget_size(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 rv = nk_widget_size(a0);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_widget_width(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float rv = nk_widget_width(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_nk_window_close(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_window_close(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_window_collapse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    enum nk_collapse_states a2 = (enum nk_collapse_states)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_window_collapse(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_window_collapse_if(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    enum nk_collapse_states a2 = (enum nk_collapse_states)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_window_collapse_if(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_window_find(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_window * rv = nk_window_find(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_window");
    }
}

static mrb_value GenR_nk_window_get_bounds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_rect rv = nk_window_get_bounds(a0);
    return GenPush_nk_rect(mrb, &rv);
    }
}

static mrb_value GenR_nk_window_get_canvas(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_command_buffer * rv = nk_window_get_canvas(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_command_buffer");
    }
}

static mrb_value GenR_nk_window_get_content_region(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_rect rv = nk_window_get_content_region(a0);
    return GenPush_nk_rect(mrb, &rv);
    }
}

static mrb_value GenR_nk_window_get_content_region_max(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 rv = nk_window_get_content_region_max(a0);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_window_get_content_region_min(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 rv = nk_window_get_content_region_min(a0);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_window_get_content_region_size(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 rv = nk_window_get_content_region_size(a0);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_window_get_height(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float rv = nk_window_get_height(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_nk_window_get_panel(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_panel * rv = nk_window_get_panel(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_panel");
    }
}

static mrb_value GenR_nk_window_get_position(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 rv = nk_window_get_position(a0);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_window_get_scroll(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_uint io1 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_uint io2 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_window_get_scroll(a0, &io1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)io1);
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_nk_window_get_size(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    struct nk_vec2 rv = nk_window_get_size(a0);
    return GenPush_nk_vec2(mrb, &rv);
    }
}

static mrb_value GenR_nk_window_get_width(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    float rv = nk_window_get_width(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_nk_window_has_focus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_window_has_focus(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_window_is_active(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_window_is_active(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_window_is_any_hovered(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_window_is_any_hovered(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_window_is_closed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_window_is_closed(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_window_is_collapsed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_window_is_collapsed(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_window_is_hidden(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_bool rv = nk_window_is_hidden(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_window_is_hovered(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_bool rv = nk_window_is_hovered(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_nk_window_set_bounds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_rect a2;
    GenRead_nk_rect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_window_set_bounds(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_window_set_focus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_window_set_focus(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_window_set_position(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_window_set_position(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_window_set_scroll(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    nk_uint a1 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    nk_uint a2 = (nk_uint)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_window_set_scroll(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_window_set_size(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    struct nk_vec2 a2;
    GenRead_nk_vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    nk_window_set_size(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_window_show(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    enum nk_show_states a2 = (enum nk_show_states)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    nk_window_show(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_nk_window_show_if(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "nk_context");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    enum nk_show_states a2 = (enum nk_show_states)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    nk_window_show_if(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

void SDLStaticGen_OpenRuby_nk(mrb_state *mrb);
void SDLStaticGen_OpenRuby_nk(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "NK");
    mrb_define_module_function(mrb, mod, "_begin", GenR_nk__begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "_draw_begin", GenR_nk__draw_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "_draw_end", GenR_nk__draw_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "_draw_list_begin", GenR_nk__draw_list_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "_draw_list_end", GenR_nk__draw_list_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "_draw_list_next", GenR_nk__draw_list_next, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "_draw_next", GenR_nk__draw_next, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "_next", GenR_nk__next, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "begin_", GenR_nk_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "begin_titled", GenR_nk_begin_titled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "buffer_clear", GenR_nk_buffer_clear, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "buffer_free", GenR_nk_buffer_free, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "buffer_info", GenR_nk_buffer_info, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "buffer_init", GenR_nk_buffer_init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "buffer_init_default", GenR_nk_buffer_init_default, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "buffer_mark", GenR_nk_buffer_mark, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "buffer_push", GenR_nk_buffer_push, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "buffer_reset", GenR_nk_buffer_reset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "buffer_total", GenR_nk_buffer_total, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_color", GenR_nk_button_color, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_label", GenR_nk_button_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_label_styled", GenR_nk_button_label_styled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_pop_behavior", GenR_nk_button_pop_behavior, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_push_behavior", GenR_nk_button_push_behavior, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_set_behavior", GenR_nk_button_set_behavior, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_symbol", GenR_nk_button_symbol, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_symbol_label", GenR_nk_button_symbol_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_symbol_label_styled", GenR_nk_button_symbol_label_styled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_symbol_styled", GenR_nk_button_symbol_styled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_symbol_text", GenR_nk_button_symbol_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_symbol_text_styled", GenR_nk_button_symbol_text_styled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_text", GenR_nk_button_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "button_text_styled", GenR_nk_button_text_styled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "chart_add_slot", GenR_nk_chart_add_slot, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "chart_add_slot_colored", GenR_nk_chart_add_slot_colored, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "chart_begin", GenR_nk_chart_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "chart_begin_colored", GenR_nk_chart_begin_colored, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "chart_end", GenR_nk_chart_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "chart_push", GenR_nk_chart_push, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "chart_push_slot", GenR_nk_chart_push_slot, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "check_flags_label", GenR_nk_check_flags_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "check_flags_text", GenR_nk_check_flags_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "check_label", GenR_nk_check_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "check_text", GenR_nk_check_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "check_text_align", GenR_nk_check_text_align, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "checkbox_flags_label", GenR_nk_checkbox_flags_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "checkbox_flags_text", GenR_nk_checkbox_flags_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "checkbox_label", GenR_nk_checkbox_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "checkbox_label_align", GenR_nk_checkbox_label_align, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "checkbox_text", GenR_nk_checkbox_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "checkbox_text_align", GenR_nk_checkbox_text_align, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "clear", GenR_nk_clear, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_cf", GenR_nk_color_cf, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_d", GenR_nk_color_d, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_dv", GenR_nk_color_dv, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_f", GenR_nk_color_f, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_fv", GenR_nk_color_fv, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsv_b", GenR_nk_color_hsv_b, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsv_bv", GenR_nk_color_hsv_bv, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsv_f", GenR_nk_color_hsv_f, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsv_fv", GenR_nk_color_hsv_fv, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsv_i", GenR_nk_color_hsv_i, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsv_iv", GenR_nk_color_hsv_iv, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsva_b", GenR_nk_color_hsva_b, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsva_bv", GenR_nk_color_hsva_bv, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsva_f", GenR_nk_color_hsva_f, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsva_fv", GenR_nk_color_hsva_fv, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsva_i", GenR_nk_color_hsva_i, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_hsva_iv", GenR_nk_color_hsva_iv, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_pick", GenR_nk_color_pick, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_picker", GenR_nk_color_picker, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "color_u32", GenR_nk_color_u32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "colorf_hsva_f", GenR_nk_colorf_hsva_f, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "colorf_hsva_fv", GenR_nk_colorf_hsva_fv, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_begin_color", GenR_nk_combo_begin_color, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_begin_label", GenR_nk_combo_begin_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_begin_symbol", GenR_nk_combo_begin_symbol, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_begin_symbol_label", GenR_nk_combo_begin_symbol_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_begin_symbol_text", GenR_nk_combo_begin_symbol_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_begin_text", GenR_nk_combo_begin_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_close", GenR_nk_combo_close, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_end", GenR_nk_combo_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_item_label", GenR_nk_combo_item_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_item_symbol_label", GenR_nk_combo_item_symbol_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_item_symbol_text", GenR_nk_combo_item_symbol_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_item_text", GenR_nk_combo_item_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_separator", GenR_nk_combo_separator, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combo_string", GenR_nk_combo_string, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combobox_separator", GenR_nk_combobox_separator, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "combobox_string", GenR_nk_combobox_string, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "contextual_begin", GenR_nk_contextual_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "contextual_close", GenR_nk_contextual_close, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "contextual_end", GenR_nk_contextual_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "contextual_item_label", GenR_nk_contextual_item_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "contextual_item_symbol_label", GenR_nk_contextual_item_symbol_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "contextual_item_symbol_text", GenR_nk_contextual_item_symbol_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "contextual_item_text", GenR_nk_contextual_item_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "convert", GenR_nk_convert, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_image", GenR_nk_draw_image, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_add_text", GenR_nk_draw_list_add_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_fill_circle", GenR_nk_draw_list_fill_circle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_fill_poly_convex", GenR_nk_draw_list_fill_poly_convex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_fill_rect", GenR_nk_draw_list_fill_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_fill_rect_multi_color", GenR_nk_draw_list_fill_rect_multi_color, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_fill_triangle", GenR_nk_draw_list_fill_triangle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_init", GenR_nk_draw_list_init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_path_arc_to", GenR_nk_draw_list_path_arc_to, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_path_arc_to_fast", GenR_nk_draw_list_path_arc_to_fast, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_path_clear", GenR_nk_draw_list_path_clear, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_path_curve_to", GenR_nk_draw_list_path_curve_to, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_path_fill", GenR_nk_draw_list_path_fill, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_path_line_to", GenR_nk_draw_list_path_line_to, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_path_rect_to", GenR_nk_draw_list_path_rect_to, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_path_stroke", GenR_nk_draw_list_path_stroke, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_setup", GenR_nk_draw_list_setup, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_stroke_circle", GenR_nk_draw_list_stroke_circle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_stroke_curve", GenR_nk_draw_list_stroke_curve, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_stroke_line", GenR_nk_draw_list_stroke_line, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_stroke_poly_line", GenR_nk_draw_list_stroke_poly_line, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_stroke_rect", GenR_nk_draw_list_stroke_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_list_stroke_triangle", GenR_nk_draw_list_stroke_triangle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_nine_slice", GenR_nk_draw_nine_slice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "draw_text", GenR_nk_draw_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "edit_focus", GenR_nk_edit_focus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "edit_unfocus", GenR_nk_edit_unfocus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "end_", GenR_nk_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "fill_arc", GenR_nk_fill_arc, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "fill_circle", GenR_nk_fill_circle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "fill_rect", GenR_nk_fill_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "fill_rect_multi_color", GenR_nk_fill_rect_multi_color, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "fill_triangle", GenR_nk_fill_triangle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filter_ascii", GenR_nk_filter_ascii, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filter_binary", GenR_nk_filter_binary, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filter_decimal", GenR_nk_filter_decimal, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filter_default", GenR_nk_filter_default, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filter_float", GenR_nk_filter_float, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filter_hex", GenR_nk_filter_hex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filter_oct", GenR_nk_filter_oct, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "font_atlas_add", GenR_nk_font_atlas_add, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "font_atlas_add_compressed_base85", GenR_nk_font_atlas_add_compressed_base85, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "font_atlas_add_default", GenR_nk_font_atlas_add_default, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "font_atlas_begin", GenR_nk_font_atlas_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "font_atlas_cleanup", GenR_nk_font_atlas_cleanup, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "font_atlas_clear", GenR_nk_font_atlas_clear, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "font_atlas_init", GenR_nk_font_atlas_init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "font_atlas_init_custom", GenR_nk_font_atlas_init_custom, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "font_atlas_init_default", GenR_nk_font_atlas_init_default, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "free", GenR_nk_free, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "get_null_rect", GenR_nk_get_null_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "group_begin", GenR_nk_group_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "group_begin_titled", GenR_nk_group_begin_titled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "group_end", GenR_nk_group_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "group_get_scroll", GenR_nk_group_get_scroll, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "group_scrolled_begin", GenR_nk_group_scrolled_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "group_scrolled_end", GenR_nk_group_scrolled_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "group_scrolled_offset_begin", GenR_nk_group_scrolled_offset_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "group_set_scroll", GenR_nk_group_set_scroll, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hsv", GenR_nk_hsv, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hsv_f", GenR_nk_hsv_f, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hsva", GenR_nk_hsva, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hsva_colorf", GenR_nk_hsva_colorf, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hsva_f", GenR_nk_hsva_f, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "image_is_subimage", GenR_nk_image_is_subimage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "init", GenR_nk_init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "init_custom", GenR_nk_init_custom, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "init_default", GenR_nk_init_default, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_any_mouse_click_in_rect", GenR_nk_input_any_mouse_click_in_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_begin", GenR_nk_input_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_button", GenR_nk_input_button, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_char", GenR_nk_input_char, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_end", GenR_nk_input_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_has_mouse_click", GenR_nk_input_has_mouse_click, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_has_mouse_click_down_in_rect", GenR_nk_input_has_mouse_click_down_in_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_has_mouse_click_in_button_rect", GenR_nk_input_has_mouse_click_in_button_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_has_mouse_click_in_rect", GenR_nk_input_has_mouse_click_in_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_is_key_down", GenR_nk_input_is_key_down, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_is_key_pressed", GenR_nk_input_is_key_pressed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_is_key_released", GenR_nk_input_is_key_released, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_is_mouse_click_down_in_rect", GenR_nk_input_is_mouse_click_down_in_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_is_mouse_click_in_rect", GenR_nk_input_is_mouse_click_in_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_is_mouse_down", GenR_nk_input_is_mouse_down, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_is_mouse_hovering_rect", GenR_nk_input_is_mouse_hovering_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_is_mouse_moved", GenR_nk_input_is_mouse_moved, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_is_mouse_pressed", GenR_nk_input_is_mouse_pressed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_is_mouse_prev_hovering_rect", GenR_nk_input_is_mouse_prev_hovering_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_is_mouse_released", GenR_nk_input_is_mouse_released, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_key", GenR_nk_input_key, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_motion", GenR_nk_input_motion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_mouse_clicked", GenR_nk_input_mouse_clicked, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_scroll", GenR_nk_input_scroll, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "input_unicode", GenR_nk_input_unicode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "item_is_any_active", GenR_nk_item_is_any_active, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "knob_float", GenR_nk_knob_float, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "knob_int", GenR_nk_knob_int, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "label", GenR_nk_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "label_colored", GenR_nk_label_colored, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "label_colored_wrap", GenR_nk_label_colored_wrap, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "label_wrap", GenR_nk_label_wrap, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_ratio_from_pixel", GenR_nk_layout_ratio_from_pixel, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_reset_min_row_height", GenR_nk_layout_reset_min_row_height, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_row_begin", GenR_nk_layout_row_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_row_dynamic", GenR_nk_layout_row_dynamic, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_row_end", GenR_nk_layout_row_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_row_push", GenR_nk_layout_row_push, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_row_static", GenR_nk_layout_row_static, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_row_template_begin", GenR_nk_layout_row_template_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_row_template_end", GenR_nk_layout_row_template_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_row_template_push_dynamic", GenR_nk_layout_row_template_push_dynamic, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_row_template_push_static", GenR_nk_layout_row_template_push_static, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_row_template_push_variable", GenR_nk_layout_row_template_push_variable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_set_min_row_height", GenR_nk_layout_set_min_row_height, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_space_begin", GenR_nk_layout_space_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_space_bounds", GenR_nk_layout_space_bounds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_space_end", GenR_nk_layout_space_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_space_push", GenR_nk_layout_space_push, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_space_rect_to_local", GenR_nk_layout_space_rect_to_local, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_space_rect_to_screen", GenR_nk_layout_space_rect_to_screen, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_space_to_local", GenR_nk_layout_space_to_local, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_space_to_screen", GenR_nk_layout_space_to_screen, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "layout_widget_bounds", GenR_nk_layout_widget_bounds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "list_view_begin", GenR_nk_list_view_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "list_view_end", GenR_nk_list_view_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menu_begin_label", GenR_nk_menu_begin_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menu_begin_symbol", GenR_nk_menu_begin_symbol, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menu_begin_symbol_label", GenR_nk_menu_begin_symbol_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menu_begin_symbol_text", GenR_nk_menu_begin_symbol_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menu_begin_text", GenR_nk_menu_begin_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menu_close", GenR_nk_menu_close, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menu_end", GenR_nk_menu_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menu_item_label", GenR_nk_menu_item_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menu_item_symbol_label", GenR_nk_menu_item_symbol_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menu_item_symbol_text", GenR_nk_menu_item_symbol_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menu_item_text", GenR_nk_menu_item_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menubar_begin", GenR_nk_menubar_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "menubar_end", GenR_nk_menubar_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "murmur_hash", GenR_nk_murmur_hash, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "nine_slice_is_sub9slice", GenR_nk_nine_slice_is_sub9slice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "option_label", GenR_nk_option_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "option_label_align", GenR_nk_option_label_align, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "option_text", GenR_nk_option_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "option_text_align", GenR_nk_option_text_align, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "popup_begin", GenR_nk_popup_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "popup_close", GenR_nk_popup_close, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "popup_end", GenR_nk_popup_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "popup_get_scroll", GenR_nk_popup_get_scroll, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "popup_set_scroll", GenR_nk_popup_set_scroll, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "prog", GenR_nk_prog, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "progress", GenR_nk_progress, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "property_double", GenR_nk_property_double, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "property_float", GenR_nk_property_float, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "property_int", GenR_nk_property_int, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "propertyd", GenR_nk_propertyd, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "propertyf", GenR_nk_propertyf, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "propertyi", GenR_nk_propertyi, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "push_scissor", GenR_nk_push_scissor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "radio_label", GenR_nk_radio_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "radio_label_align", GenR_nk_radio_label_align, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "radio_text", GenR_nk_radio_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "radio_text_align", GenR_nk_radio_text_align, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rect", GenR_nk_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rect_pos", GenR_nk_rect_pos, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rect_size", GenR_nk_rect_size, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "recta", GenR_nk_recta, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "recti", GenR_nk_recti, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rgb", GenR_nk_rgb, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rgb_cf", GenR_nk_rgb_cf, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rgb_f", GenR_nk_rgb_f, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rgb_factor", GenR_nk_rgb_factor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rgb_hex", GenR_nk_rgb_hex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rgba", GenR_nk_rgba, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rgba_cf", GenR_nk_rgba_cf, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rgba_f", GenR_nk_rgba_f, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rgba_hex", GenR_nk_rgba_hex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rgba_u32", GenR_nk_rgba_u32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rule_horizontal", GenR_nk_rule_horizontal, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "select_label", GenR_nk_select_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "select_symbol_label", GenR_nk_select_symbol_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "select_symbol_text", GenR_nk_select_symbol_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "select_text", GenR_nk_select_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "selectable_label", GenR_nk_selectable_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "selectable_symbol_label", GenR_nk_selectable_symbol_label, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "selectable_symbol_text", GenR_nk_selectable_symbol_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "selectable_text", GenR_nk_selectable_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "slide_float", GenR_nk_slide_float, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "slide_int", GenR_nk_slide_int, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "slider_float", GenR_nk_slider_float, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "slider_int", GenR_nk_slider_int, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "spacer", GenR_nk_spacer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "spacing", GenR_nk_spacing, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_append_str_char", GenR_nk_str_append_str_char, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_append_str_utf8", GenR_nk_str_append_str_utf8, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_append_text_char", GenR_nk_str_append_text_char, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_append_text_utf8", GenR_nk_str_append_text_utf8, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_at_char_const", GenR_nk_str_at_char_const, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_at_const", GenR_nk_str_at_const, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_clear", GenR_nk_str_clear, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_delete_chars", GenR_nk_str_delete_chars, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_delete_runes", GenR_nk_str_delete_runes, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_free", GenR_nk_str_free, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_get_const", GenR_nk_str_get_const, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_init", GenR_nk_str_init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_init_default", GenR_nk_str_init_default, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_insert_at_char", GenR_nk_str_insert_at_char, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_insert_at_rune", GenR_nk_str_insert_at_rune, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_insert_str_char", GenR_nk_str_insert_str_char, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_insert_str_utf8", GenR_nk_str_insert_str_utf8, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_insert_text_char", GenR_nk_str_insert_text_char, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_insert_text_utf8", GenR_nk_str_insert_text_utf8, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_len", GenR_nk_str_len, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_len_char", GenR_nk_str_len_char, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_remove_chars", GenR_nk_str_remove_chars, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_remove_runes", GenR_nk_str_remove_runes, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "str_rune_at", GenR_nk_str_rune_at, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "strfilter", GenR_nk_strfilter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "stricmp", GenR_nk_stricmp, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "stricmpn", GenR_nk_stricmpn, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "strlen", GenR_nk_strlen, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "strmatch_fuzzy_string", GenR_nk_strmatch_fuzzy_string, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "strmatch_fuzzy_text", GenR_nk_strmatch_fuzzy_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "stroke_arc", GenR_nk_stroke_arc, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "stroke_circle", GenR_nk_stroke_circle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "stroke_curve", GenR_nk_stroke_curve, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "stroke_line", GenR_nk_stroke_line, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "stroke_rect", GenR_nk_stroke_rect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "stroke_triangle", GenR_nk_stroke_triangle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_default", GenR_nk_style_default, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_from_table", GenR_nk_style_from_table, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_get_color_by_name", GenR_nk_style_get_color_by_name, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_hide_cursor", GenR_nk_style_hide_cursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_load_all_cursors", GenR_nk_style_load_all_cursors, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_load_cursor", GenR_nk_style_load_cursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_pop_color", GenR_nk_style_pop_color, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_pop_flags", GenR_nk_style_pop_flags, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_pop_float", GenR_nk_style_pop_float, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_pop_font", GenR_nk_style_pop_font, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_pop_style_item", GenR_nk_style_pop_style_item, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_pop_vec2", GenR_nk_style_pop_vec2, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_push_color", GenR_nk_style_push_color, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_push_flags", GenR_nk_style_push_flags, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_push_float", GenR_nk_style_push_float, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_push_font", GenR_nk_style_push_font, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_push_vec2", GenR_nk_style_push_vec2, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_set_cursor", GenR_nk_style_set_cursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_set_font", GenR_nk_style_set_font, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "style_show_cursor", GenR_nk_style_show_cursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "text", GenR_nk_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "text_colored", GenR_nk_text_colored, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "text_wrap", GenR_nk_text_wrap, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "text_wrap_colored", GenR_nk_text_wrap_colored, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "textedit_cut", GenR_nk_textedit_cut, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "textedit_delete", GenR_nk_textedit_delete, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "textedit_delete_selection", GenR_nk_textedit_delete_selection, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "textedit_free", GenR_nk_textedit_free, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "textedit_init", GenR_nk_textedit_init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "textedit_init_default", GenR_nk_textedit_init_default, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "textedit_paste", GenR_nk_textedit_paste, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "textedit_redo", GenR_nk_textedit_redo, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "textedit_select_all", GenR_nk_textedit_select_all, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "textedit_text", GenR_nk_textedit_text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "textedit_undo", GenR_nk_textedit_undo, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tooltip", GenR_nk_tooltip, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tooltip_begin", GenR_nk_tooltip_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tooltip_begin_offset", GenR_nk_tooltip_begin_offset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tooltip_end", GenR_nk_tooltip_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tooltip_offset", GenR_nk_tooltip_offset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tree_element_pop", GenR_nk_tree_element_pop, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tree_element_push_hashed", GenR_nk_tree_element_push_hashed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tree_pop", GenR_nk_tree_pop, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tree_push_hashed", GenR_nk_tree_push_hashed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tree_state_pop", GenR_nk_tree_state_pop, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tree_state_push", GenR_nk_tree_state_push, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "triangle_from_direction", GenR_nk_triangle_from_direction, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "utf_at", GenR_nk_utf_at, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "utf_decode", GenR_nk_utf_decode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "utf_len", GenR_nk_utf_len, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "value_bool", GenR_nk_value_bool, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "value_color_byte", GenR_nk_value_color_byte, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "value_color_float", GenR_nk_value_color_float, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "value_color_hex", GenR_nk_value_color_hex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "value_float", GenR_nk_value_float, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "value_int", GenR_nk_value_int, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "value_uint", GenR_nk_value_uint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "vec2", GenR_nk_vec2, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "vec2i", GenR_nk_vec2i, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget", GenR_nk_widget, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget_bounds", GenR_nk_widget_bounds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget_disable_begin", GenR_nk_widget_disable_begin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget_disable_end", GenR_nk_widget_disable_end, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget_fitting", GenR_nk_widget_fitting, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget_has_mouse_click_down", GenR_nk_widget_has_mouse_click_down, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget_height", GenR_nk_widget_height, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget_is_hovered", GenR_nk_widget_is_hovered, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget_is_mouse_clicked", GenR_nk_widget_is_mouse_clicked, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget_position", GenR_nk_widget_position, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget_size", GenR_nk_widget_size, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "widget_width", GenR_nk_widget_width, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_close", GenR_nk_window_close, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_collapse", GenR_nk_window_collapse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_collapse_if", GenR_nk_window_collapse_if, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_find", GenR_nk_window_find, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_bounds", GenR_nk_window_get_bounds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_canvas", GenR_nk_window_get_canvas, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_content_region", GenR_nk_window_get_content_region, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_content_region_max", GenR_nk_window_get_content_region_max, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_content_region_min", GenR_nk_window_get_content_region_min, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_content_region_size", GenR_nk_window_get_content_region_size, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_height", GenR_nk_window_get_height, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_panel", GenR_nk_window_get_panel, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_position", GenR_nk_window_get_position, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_scroll", GenR_nk_window_get_scroll, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_size", GenR_nk_window_get_size, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_get_width", GenR_nk_window_get_width, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_has_focus", GenR_nk_window_has_focus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_is_active", GenR_nk_window_is_active, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_is_any_hovered", GenR_nk_window_is_any_hovered, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_is_closed", GenR_nk_window_is_closed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_is_collapsed", GenR_nk_window_is_collapsed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_is_hidden", GenR_nk_window_is_hidden, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_is_hovered", GenR_nk_window_is_hovered, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_set_bounds", GenR_nk_window_set_bounds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_set_focus", GenR_nk_window_set_focus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_set_position", GenR_nk_window_set_position, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_set_scroll", GenR_nk_window_set_scroll, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_set_size", GenR_nk_window_set_size, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_show", GenR_nk_window_show, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "window_show_if", GenR_nk_window_show_if, MRB_ARGS_ANY());
    mrb_define_const(mrb, mod, "NK_BUFFER_FIXED", mrb_int_value(mrb, (mrb_int)NK_BUFFER_FIXED));
    mrb_define_const(mrb, mod, "NK_BUFFER_DYNAMIC", mrb_int_value(mrb, (mrb_int)NK_BUFFER_DYNAMIC));
    mrb_define_const(mrb, mod, "NK_ANTI_ALIASING_OFF", mrb_int_value(mrb, (mrb_int)NK_ANTI_ALIASING_OFF));
    mrb_define_const(mrb, mod, "NK_ANTI_ALIASING_ON", mrb_int_value(mrb, (mrb_int)NK_ANTI_ALIASING_ON));
    mrb_define_const(mrb, mod, "NK_BUFFER_FRONT", mrb_int_value(mrb, (mrb_int)NK_BUFFER_FRONT));
    mrb_define_const(mrb, mod, "NK_BUFFER_BACK", mrb_int_value(mrb, (mrb_int)NK_BUFFER_BACK));
    mrb_define_const(mrb, mod, "NK_BUFFER_MAX", mrb_int_value(mrb, (mrb_int)NK_BUFFER_MAX));
    mrb_define_const(mrb, mod, "NK_BUTTON_DEFAULT", mrb_int_value(mrb, (mrb_int)NK_BUTTON_DEFAULT));
    mrb_define_const(mrb, mod, "NK_BUTTON_REPEATER", mrb_int_value(mrb, (mrb_int)NK_BUTTON_REPEATER));
    mrb_define_const(mrb, mod, "NK_BUTTON_LEFT", mrb_int_value(mrb, (mrb_int)NK_BUTTON_LEFT));
    mrb_define_const(mrb, mod, "NK_BUTTON_MIDDLE", mrb_int_value(mrb, (mrb_int)NK_BUTTON_MIDDLE));
    mrb_define_const(mrb, mod, "NK_BUTTON_RIGHT", mrb_int_value(mrb, (mrb_int)NK_BUTTON_RIGHT));
    mrb_define_const(mrb, mod, "NK_BUTTON_DOUBLE", mrb_int_value(mrb, (mrb_int)NK_BUTTON_DOUBLE));
    mrb_define_const(mrb, mod, "NK_BUTTON_X1", mrb_int_value(mrb, (mrb_int)NK_BUTTON_X1));
    mrb_define_const(mrb, mod, "NK_BUTTON_X2", mrb_int_value(mrb, (mrb_int)NK_BUTTON_X2));
    mrb_define_const(mrb, mod, "NK_BUTTON_MAX", mrb_int_value(mrb, (mrb_int)NK_BUTTON_MAX));
    mrb_define_const(mrb, mod, "NK_CHART_HOVERING", mrb_int_value(mrb, (mrb_int)NK_CHART_HOVERING));
    mrb_define_const(mrb, mod, "NK_CHART_CLICKED", mrb_int_value(mrb, (mrb_int)NK_CHART_CLICKED));
    mrb_define_const(mrb, mod, "NK_CHART_LINES", mrb_int_value(mrb, (mrb_int)NK_CHART_LINES));
    mrb_define_const(mrb, mod, "NK_CHART_COLUMN", mrb_int_value(mrb, (mrb_int)NK_CHART_COLUMN));
    mrb_define_const(mrb, mod, "NK_CHART_MAX", mrb_int_value(mrb, (mrb_int)NK_CHART_MAX));
    mrb_define_const(mrb, mod, "NK_MINIMIZED", mrb_int_value(mrb, (mrb_int)NK_MINIMIZED));
    mrb_define_const(mrb, mod, "NK_MAXIMIZED", mrb_int_value(mrb, (mrb_int)NK_MAXIMIZED));
    mrb_define_const(mrb, mod, "NK_RGB", mrb_int_value(mrb, (mrb_int)NK_RGB));
    mrb_define_const(mrb, mod, "NK_RGBA", mrb_int_value(mrb, (mrb_int)NK_RGBA));
    mrb_define_const(mrb, mod, "NK_CLIPPING_OFF", mrb_int_value(mrb, (mrb_int)NK_CLIPPING_OFF));
    mrb_define_const(mrb, mod, "NK_CLIPPING_ON", mrb_int_value(mrb, (mrb_int)NK_CLIPPING_ON));
    mrb_define_const(mrb, mod, "NK_COMMAND_NOP", mrb_int_value(mrb, (mrb_int)NK_COMMAND_NOP));
    mrb_define_const(mrb, mod, "NK_COMMAND_SCISSOR", mrb_int_value(mrb, (mrb_int)NK_COMMAND_SCISSOR));
    mrb_define_const(mrb, mod, "NK_COMMAND_LINE", mrb_int_value(mrb, (mrb_int)NK_COMMAND_LINE));
    mrb_define_const(mrb, mod, "NK_COMMAND_CURVE", mrb_int_value(mrb, (mrb_int)NK_COMMAND_CURVE));
    mrb_define_const(mrb, mod, "NK_COMMAND_RECT", mrb_int_value(mrb, (mrb_int)NK_COMMAND_RECT));
    mrb_define_const(mrb, mod, "NK_COMMAND_RECT_FILLED", mrb_int_value(mrb, (mrb_int)NK_COMMAND_RECT_FILLED));
    mrb_define_const(mrb, mod, "NK_COMMAND_RECT_MULTI_COLOR", mrb_int_value(mrb, (mrb_int)NK_COMMAND_RECT_MULTI_COLOR));
    mrb_define_const(mrb, mod, "NK_COMMAND_CIRCLE", mrb_int_value(mrb, (mrb_int)NK_COMMAND_CIRCLE));
    mrb_define_const(mrb, mod, "NK_COMMAND_CIRCLE_FILLED", mrb_int_value(mrb, (mrb_int)NK_COMMAND_CIRCLE_FILLED));
    mrb_define_const(mrb, mod, "NK_COMMAND_ARC", mrb_int_value(mrb, (mrb_int)NK_COMMAND_ARC));
    mrb_define_const(mrb, mod, "NK_COMMAND_ARC_FILLED", mrb_int_value(mrb, (mrb_int)NK_COMMAND_ARC_FILLED));
    mrb_define_const(mrb, mod, "NK_COMMAND_TRIANGLE", mrb_int_value(mrb, (mrb_int)NK_COMMAND_TRIANGLE));
    mrb_define_const(mrb, mod, "NK_COMMAND_TRIANGLE_FILLED", mrb_int_value(mrb, (mrb_int)NK_COMMAND_TRIANGLE_FILLED));
    mrb_define_const(mrb, mod, "NK_COMMAND_POLYGON", mrb_int_value(mrb, (mrb_int)NK_COMMAND_POLYGON));
    mrb_define_const(mrb, mod, "NK_COMMAND_POLYGON_FILLED", mrb_int_value(mrb, (mrb_int)NK_COMMAND_POLYGON_FILLED));
    mrb_define_const(mrb, mod, "NK_COMMAND_POLYLINE", mrb_int_value(mrb, (mrb_int)NK_COMMAND_POLYLINE));
    mrb_define_const(mrb, mod, "NK_COMMAND_TEXT", mrb_int_value(mrb, (mrb_int)NK_COMMAND_TEXT));
    mrb_define_const(mrb, mod, "NK_COMMAND_IMAGE", mrb_int_value(mrb, (mrb_int)NK_COMMAND_IMAGE));
    mrb_define_const(mrb, mod, "NK_COMMAND_CUSTOM", mrb_int_value(mrb, (mrb_int)NK_COMMAND_CUSTOM));
    mrb_define_const(mrb, mod, "NK_CONVERT_SUCCESS", mrb_int_value(mrb, (mrb_int)NK_CONVERT_SUCCESS));
    mrb_define_const(mrb, mod, "NK_CONVERT_INVALID_PARAM", mrb_int_value(mrb, (mrb_int)NK_CONVERT_INVALID_PARAM));
    mrb_define_const(mrb, mod, "NK_CONVERT_COMMAND_BUFFER_FULL", mrb_int_value(mrb, (mrb_int)NK_CONVERT_COMMAND_BUFFER_FULL));
    mrb_define_const(mrb, mod, "NK_CONVERT_VERTEX_BUFFER_FULL", mrb_int_value(mrb, (mrb_int)NK_CONVERT_VERTEX_BUFFER_FULL));
    mrb_define_const(mrb, mod, "NK_CONVERT_ELEMENT_BUFFER_FULL", mrb_int_value(mrb, (mrb_int)NK_CONVERT_ELEMENT_BUFFER_FULL));
    mrb_define_const(mrb, mod, "NK_STROKE_OPEN", mrb_int_value(mrb, (mrb_int)NK_STROKE_OPEN));
    mrb_define_const(mrb, mod, "NK_STROKE_CLOSED", mrb_int_value(mrb, (mrb_int)NK_STROKE_CLOSED));
    mrb_define_const(mrb, mod, "NK_VERTEX_POSITION", mrb_int_value(mrb, (mrb_int)NK_VERTEX_POSITION));
    mrb_define_const(mrb, mod, "NK_VERTEX_COLOR", mrb_int_value(mrb, (mrb_int)NK_VERTEX_COLOR));
    mrb_define_const(mrb, mod, "NK_VERTEX_TEXCOORD", mrb_int_value(mrb, (mrb_int)NK_VERTEX_TEXCOORD));
    mrb_define_const(mrb, mod, "NK_VERTEX_ATTRIBUTE_COUNT", mrb_int_value(mrb, (mrb_int)NK_VERTEX_ATTRIBUTE_COUNT));
    mrb_define_const(mrb, mod, "NK_FORMAT_SCHAR", mrb_int_value(mrb, (mrb_int)NK_FORMAT_SCHAR));
    mrb_define_const(mrb, mod, "NK_FORMAT_SSHORT", mrb_int_value(mrb, (mrb_int)NK_FORMAT_SSHORT));
    mrb_define_const(mrb, mod, "NK_FORMAT_SINT", mrb_int_value(mrb, (mrb_int)NK_FORMAT_SINT));
    mrb_define_const(mrb, mod, "NK_FORMAT_UCHAR", mrb_int_value(mrb, (mrb_int)NK_FORMAT_UCHAR));
    mrb_define_const(mrb, mod, "NK_FORMAT_USHORT", mrb_int_value(mrb, (mrb_int)NK_FORMAT_USHORT));
    mrb_define_const(mrb, mod, "NK_FORMAT_UINT", mrb_int_value(mrb, (mrb_int)NK_FORMAT_UINT));
    mrb_define_const(mrb, mod, "NK_FORMAT_FLOAT", mrb_int_value(mrb, (mrb_int)NK_FORMAT_FLOAT));
    mrb_define_const(mrb, mod, "NK_FORMAT_DOUBLE", mrb_int_value(mrb, (mrb_int)NK_FORMAT_DOUBLE));
    mrb_define_const(mrb, mod, "NK_FORMAT_COLOR_BEGIN", mrb_int_value(mrb, (mrb_int)NK_FORMAT_COLOR_BEGIN));
    mrb_define_const(mrb, mod, "NK_FORMAT_R8G8B8", mrb_int_value(mrb, (mrb_int)NK_FORMAT_R8G8B8));
    mrb_define_const(mrb, mod, "NK_FORMAT_R16G15B16", mrb_int_value(mrb, (mrb_int)NK_FORMAT_R16G15B16));
    mrb_define_const(mrb, mod, "NK_FORMAT_R32G32B32", mrb_int_value(mrb, (mrb_int)NK_FORMAT_R32G32B32));
    mrb_define_const(mrb, mod, "NK_FORMAT_R8G8B8A8", mrb_int_value(mrb, (mrb_int)NK_FORMAT_R8G8B8A8));
    mrb_define_const(mrb, mod, "NK_FORMAT_B8G8R8A8", mrb_int_value(mrb, (mrb_int)NK_FORMAT_B8G8R8A8));
    mrb_define_const(mrb, mod, "NK_FORMAT_R16G15B16A16", mrb_int_value(mrb, (mrb_int)NK_FORMAT_R16G15B16A16));
    mrb_define_const(mrb, mod, "NK_FORMAT_R32G32B32A32", mrb_int_value(mrb, (mrb_int)NK_FORMAT_R32G32B32A32));
    mrb_define_const(mrb, mod, "NK_FORMAT_R32G32B32A32_FLOAT", mrb_int_value(mrb, (mrb_int)NK_FORMAT_R32G32B32A32_FLOAT));
    mrb_define_const(mrb, mod, "NK_FORMAT_R32G32B32A32_DOUBLE", mrb_int_value(mrb, (mrb_int)NK_FORMAT_R32G32B32A32_DOUBLE));
    mrb_define_const(mrb, mod, "NK_FORMAT_RGB32", mrb_int_value(mrb, (mrb_int)NK_FORMAT_RGB32));
    mrb_define_const(mrb, mod, "NK_FORMAT_RGBA32", mrb_int_value(mrb, (mrb_int)NK_FORMAT_RGBA32));
    mrb_define_const(mrb, mod, "NK_FORMAT_COLOR_END", mrb_int_value(mrb, (mrb_int)NK_FORMAT_COLOR_END));
    mrb_define_const(mrb, mod, "NK_FORMAT_COUNT", mrb_int_value(mrb, (mrb_int)NK_FORMAT_COUNT));
    mrb_define_const(mrb, mod, "NK_EDIT_ACTIVE", mrb_int_value(mrb, (mrb_int)NK_EDIT_ACTIVE));
    mrb_define_const(mrb, mod, "NK_EDIT_INACTIVE", mrb_int_value(mrb, (mrb_int)NK_EDIT_INACTIVE));
    mrb_define_const(mrb, mod, "NK_EDIT_ACTIVATED", mrb_int_value(mrb, (mrb_int)NK_EDIT_ACTIVATED));
    mrb_define_const(mrb, mod, "NK_EDIT_DEACTIVATED", mrb_int_value(mrb, (mrb_int)NK_EDIT_DEACTIVATED));
    mrb_define_const(mrb, mod, "NK_EDIT_COMMITTED", mrb_int_value(mrb, (mrb_int)NK_EDIT_COMMITTED));
    mrb_define_const(mrb, mod, "NK_EDIT_DEFAULT", mrb_int_value(mrb, (mrb_int)NK_EDIT_DEFAULT));
    mrb_define_const(mrb, mod, "NK_EDIT_READ_ONLY", mrb_int_value(mrb, (mrb_int)NK_EDIT_READ_ONLY));
    mrb_define_const(mrb, mod, "NK_EDIT_AUTO_SELECT", mrb_int_value(mrb, (mrb_int)NK_EDIT_AUTO_SELECT));
    mrb_define_const(mrb, mod, "NK_EDIT_SIG_ENTER", mrb_int_value(mrb, (mrb_int)NK_EDIT_SIG_ENTER));
    mrb_define_const(mrb, mod, "NK_EDIT_ALLOW_TAB", mrb_int_value(mrb, (mrb_int)NK_EDIT_ALLOW_TAB));
    mrb_define_const(mrb, mod, "NK_EDIT_NO_CURSOR", mrb_int_value(mrb, (mrb_int)NK_EDIT_NO_CURSOR));
    mrb_define_const(mrb, mod, "NK_EDIT_SELECTABLE", mrb_int_value(mrb, (mrb_int)NK_EDIT_SELECTABLE));
    mrb_define_const(mrb, mod, "NK_EDIT_CLIPBOARD", mrb_int_value(mrb, (mrb_int)NK_EDIT_CLIPBOARD));
    mrb_define_const(mrb, mod, "NK_EDIT_CTRL_ENTER_NEWLINE", mrb_int_value(mrb, (mrb_int)NK_EDIT_CTRL_ENTER_NEWLINE));
    mrb_define_const(mrb, mod, "NK_EDIT_NO_HORIZONTAL_SCROLL", mrb_int_value(mrb, (mrb_int)NK_EDIT_NO_HORIZONTAL_SCROLL));
    mrb_define_const(mrb, mod, "NK_EDIT_ALWAYS_INSERT_MODE", mrb_int_value(mrb, (mrb_int)NK_EDIT_ALWAYS_INSERT_MODE));
    mrb_define_const(mrb, mod, "NK_EDIT_MULTILINE", mrb_int_value(mrb, (mrb_int)NK_EDIT_MULTILINE));
    mrb_define_const(mrb, mod, "NK_EDIT_GOTO_END_ON_ACTIVATE", mrb_int_value(mrb, (mrb_int)NK_EDIT_GOTO_END_ON_ACTIVATE));
    mrb_define_const(mrb, mod, "NK_EDIT_SIMPLE", mrb_int_value(mrb, (mrb_int)NK_EDIT_SIMPLE));
    mrb_define_const(mrb, mod, "NK_EDIT_FIELD", mrb_int_value(mrb, (mrb_int)NK_EDIT_FIELD));
    mrb_define_const(mrb, mod, "NK_EDIT_BOX", mrb_int_value(mrb, (mrb_int)NK_EDIT_BOX));
    mrb_define_const(mrb, mod, "NK_EDIT_EDITOR", mrb_int_value(mrb, (mrb_int)NK_EDIT_EDITOR));
    mrb_define_const(mrb, mod, "NK_FONT_ATLAS_ALPHA8", mrb_int_value(mrb, (mrb_int)NK_FONT_ATLAS_ALPHA8));
    mrb_define_const(mrb, mod, "NK_FONT_ATLAS_RGBA32", mrb_int_value(mrb, (mrb_int)NK_FONT_ATLAS_RGBA32));
    mrb_define_const(mrb, mod, "NK_COORD_UV", mrb_int_value(mrb, (mrb_int)NK_COORD_UV));
    mrb_define_const(mrb, mod, "NK_COORD_PIXEL", mrb_int_value(mrb, (mrb_int)NK_COORD_PIXEL));
    mrb_define_const(mrb, mod, "NK_UP", mrb_int_value(mrb, (mrb_int)NK_UP));
    mrb_define_const(mrb, mod, "NK_RIGHT", mrb_int_value(mrb, (mrb_int)NK_RIGHT));
    mrb_define_const(mrb, mod, "NK_DOWN", mrb_int_value(mrb, (mrb_int)NK_DOWN));
    mrb_define_const(mrb, mod, "NK_LEFT", mrb_int_value(mrb, (mrb_int)NK_LEFT));
    mrb_define_const(mrb, mod, "NK_KEY_NONE", mrb_int_value(mrb, (mrb_int)NK_KEY_NONE));
    mrb_define_const(mrb, mod, "NK_KEY_SHIFT", mrb_int_value(mrb, (mrb_int)NK_KEY_SHIFT));
    mrb_define_const(mrb, mod, "NK_KEY_CTRL", mrb_int_value(mrb, (mrb_int)NK_KEY_CTRL));
    mrb_define_const(mrb, mod, "NK_KEY_DEL", mrb_int_value(mrb, (mrb_int)NK_KEY_DEL));
    mrb_define_const(mrb, mod, "NK_KEY_ENTER", mrb_int_value(mrb, (mrb_int)NK_KEY_ENTER));
    mrb_define_const(mrb, mod, "NK_KEY_TAB", mrb_int_value(mrb, (mrb_int)NK_KEY_TAB));
    mrb_define_const(mrb, mod, "NK_KEY_BACKSPACE", mrb_int_value(mrb, (mrb_int)NK_KEY_BACKSPACE));
    mrb_define_const(mrb, mod, "NK_KEY_COPY", mrb_int_value(mrb, (mrb_int)NK_KEY_COPY));
    mrb_define_const(mrb, mod, "NK_KEY_CUT", mrb_int_value(mrb, (mrb_int)NK_KEY_CUT));
    mrb_define_const(mrb, mod, "NK_KEY_PASTE", mrb_int_value(mrb, (mrb_int)NK_KEY_PASTE));
    mrb_define_const(mrb, mod, "NK_KEY_UP", mrb_int_value(mrb, (mrb_int)NK_KEY_UP));
    mrb_define_const(mrb, mod, "NK_KEY_DOWN", mrb_int_value(mrb, (mrb_int)NK_KEY_DOWN));
    mrb_define_const(mrb, mod, "NK_KEY_LEFT", mrb_int_value(mrb, (mrb_int)NK_KEY_LEFT));
    mrb_define_const(mrb, mod, "NK_KEY_RIGHT", mrb_int_value(mrb, (mrb_int)NK_KEY_RIGHT));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_INSERT_MODE", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_INSERT_MODE));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_REPLACE_MODE", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_REPLACE_MODE));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_RESET_MODE", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_RESET_MODE));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_LINE_START", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_LINE_START));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_LINE_END", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_LINE_END));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_START", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_START));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_END", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_END));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_UNDO", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_UNDO));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_REDO", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_REDO));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_SELECT_ALL", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_SELECT_ALL));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_WORD_LEFT", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_WORD_LEFT));
    mrb_define_const(mrb, mod, "NK_KEY_TEXT_WORD_RIGHT", mrb_int_value(mrb, (mrb_int)NK_KEY_TEXT_WORD_RIGHT));
    mrb_define_const(mrb, mod, "NK_KEY_SCROLL_START", mrb_int_value(mrb, (mrb_int)NK_KEY_SCROLL_START));
    mrb_define_const(mrb, mod, "NK_KEY_SCROLL_END", mrb_int_value(mrb, (mrb_int)NK_KEY_SCROLL_END));
    mrb_define_const(mrb, mod, "NK_KEY_SCROLL_DOWN", mrb_int_value(mrb, (mrb_int)NK_KEY_SCROLL_DOWN));
    mrb_define_const(mrb, mod, "NK_KEY_SCROLL_UP", mrb_int_value(mrb, (mrb_int)NK_KEY_SCROLL_UP));
    mrb_define_const(mrb, mod, "NK_KEY_MAX", mrb_int_value(mrb, (mrb_int)NK_KEY_MAX));
    mrb_define_const(mrb, mod, "NK_DYNAMIC", mrb_int_value(mrb, (mrb_int)NK_DYNAMIC));
    mrb_define_const(mrb, mod, "NK_STATIC", mrb_int_value(mrb, (mrb_int)NK_STATIC));
    mrb_define_const(mrb, mod, "NK_FIXED", mrb_int_value(mrb, (mrb_int)NK_FIXED));
    mrb_define_const(mrb, mod, "NK_MODIFIABLE", mrb_int_value(mrb, (mrb_int)NK_MODIFIABLE));
    mrb_define_const(mrb, mod, "NK_VERTICAL", mrb_int_value(mrb, (mrb_int)NK_VERTICAL));
    mrb_define_const(mrb, mod, "NK_HORIZONTAL", mrb_int_value(mrb, (mrb_int)NK_HORIZONTAL));
    mrb_define_const(mrb, mod, "NK_WINDOW_BORDER", mrb_int_value(mrb, (mrb_int)NK_WINDOW_BORDER));
    mrb_define_const(mrb, mod, "NK_WINDOW_MOVABLE", mrb_int_value(mrb, (mrb_int)NK_WINDOW_MOVABLE));
    mrb_define_const(mrb, mod, "NK_WINDOW_SCALABLE", mrb_int_value(mrb, (mrb_int)NK_WINDOW_SCALABLE));
    mrb_define_const(mrb, mod, "NK_WINDOW_CLOSABLE", mrb_int_value(mrb, (mrb_int)NK_WINDOW_CLOSABLE));
    mrb_define_const(mrb, mod, "NK_WINDOW_MINIMIZABLE", mrb_int_value(mrb, (mrb_int)NK_WINDOW_MINIMIZABLE));
    mrb_define_const(mrb, mod, "NK_WINDOW_NO_SCROLLBAR", mrb_int_value(mrb, (mrb_int)NK_WINDOW_NO_SCROLLBAR));
    mrb_define_const(mrb, mod, "NK_WINDOW_TITLE", mrb_int_value(mrb, (mrb_int)NK_WINDOW_TITLE));
    mrb_define_const(mrb, mod, "NK_WINDOW_SCROLL_AUTO_HIDE", mrb_int_value(mrb, (mrb_int)NK_WINDOW_SCROLL_AUTO_HIDE));
    mrb_define_const(mrb, mod, "NK_WINDOW_BACKGROUND", mrb_int_value(mrb, (mrb_int)NK_WINDOW_BACKGROUND));
    mrb_define_const(mrb, mod, "NK_WINDOW_SCALE_LEFT", mrb_int_value(mrb, (mrb_int)NK_WINDOW_SCALE_LEFT));
    mrb_define_const(mrb, mod, "NK_WINDOW_NO_INPUT", mrb_int_value(mrb, (mrb_int)NK_WINDOW_NO_INPUT));
    mrb_define_const(mrb, mod, "NK_LAYOUT_DYNAMIC_FIXED", mrb_int_value(mrb, (mrb_int)NK_LAYOUT_DYNAMIC_FIXED));
    mrb_define_const(mrb, mod, "NK_LAYOUT_DYNAMIC_ROW", mrb_int_value(mrb, (mrb_int)NK_LAYOUT_DYNAMIC_ROW));
    mrb_define_const(mrb, mod, "NK_LAYOUT_DYNAMIC_FREE", mrb_int_value(mrb, (mrb_int)NK_LAYOUT_DYNAMIC_FREE));
    mrb_define_const(mrb, mod, "NK_LAYOUT_DYNAMIC", mrb_int_value(mrb, (mrb_int)NK_LAYOUT_DYNAMIC));
    mrb_define_const(mrb, mod, "NK_LAYOUT_STATIC_FIXED", mrb_int_value(mrb, (mrb_int)NK_LAYOUT_STATIC_FIXED));
    mrb_define_const(mrb, mod, "NK_LAYOUT_STATIC_ROW", mrb_int_value(mrb, (mrb_int)NK_LAYOUT_STATIC_ROW));
    mrb_define_const(mrb, mod, "NK_LAYOUT_STATIC_FREE", mrb_int_value(mrb, (mrb_int)NK_LAYOUT_STATIC_FREE));
    mrb_define_const(mrb, mod, "NK_LAYOUT_STATIC", mrb_int_value(mrb, (mrb_int)NK_LAYOUT_STATIC));
    mrb_define_const(mrb, mod, "NK_LAYOUT_TEMPLATE", mrb_int_value(mrb, (mrb_int)NK_LAYOUT_TEMPLATE));
    mrb_define_const(mrb, mod, "NK_LAYOUT_COUNT", mrb_int_value(mrb, (mrb_int)NK_LAYOUT_COUNT));
    mrb_define_const(mrb, mod, "NK_PANEL_SET_NONBLOCK", mrb_int_value(mrb, (mrb_int)NK_PANEL_SET_NONBLOCK));
    mrb_define_const(mrb, mod, "NK_PANEL_SET_POPUP", mrb_int_value(mrb, (mrb_int)NK_PANEL_SET_POPUP));
    mrb_define_const(mrb, mod, "NK_PANEL_SET_SUB", mrb_int_value(mrb, (mrb_int)NK_PANEL_SET_SUB));
    mrb_define_const(mrb, mod, "NK_PANEL_NONE", mrb_int_value(mrb, (mrb_int)NK_PANEL_NONE));
    mrb_define_const(mrb, mod, "NK_PANEL_WINDOW", mrb_int_value(mrb, (mrb_int)NK_PANEL_WINDOW));
    mrb_define_const(mrb, mod, "NK_PANEL_GROUP", mrb_int_value(mrb, (mrb_int)NK_PANEL_GROUP));
    mrb_define_const(mrb, mod, "NK_PANEL_POPUP", mrb_int_value(mrb, (mrb_int)NK_PANEL_POPUP));
    mrb_define_const(mrb, mod, "NK_PANEL_CONTEXTUAL", mrb_int_value(mrb, (mrb_int)NK_PANEL_CONTEXTUAL));
    mrb_define_const(mrb, mod, "NK_PANEL_COMBO", mrb_int_value(mrb, (mrb_int)NK_PANEL_COMBO));
    mrb_define_const(mrb, mod, "NK_PANEL_MENU", mrb_int_value(mrb, (mrb_int)NK_PANEL_MENU));
    mrb_define_const(mrb, mod, "NK_PANEL_TOOLTIP", mrb_int_value(mrb, (mrb_int)NK_PANEL_TOOLTIP));
    mrb_define_const(mrb, mod, "NK_POPUP_STATIC", mrb_int_value(mrb, (mrb_int)NK_POPUP_STATIC));
    mrb_define_const(mrb, mod, "NK_POPUP_DYNAMIC", mrb_int_value(mrb, (mrb_int)NK_POPUP_DYNAMIC));
    mrb_define_const(mrb, mod, "NK_HIDDEN", mrb_int_value(mrb, (mrb_int)NK_HIDDEN));
    mrb_define_const(mrb, mod, "NK_SHOWN", mrb_int_value(mrb, (mrb_int)NK_SHOWN));
    mrb_define_const(mrb, mod, "NK_COLOR_TEXT", mrb_int_value(mrb, (mrb_int)NK_COLOR_TEXT));
    mrb_define_const(mrb, mod, "NK_COLOR_WINDOW", mrb_int_value(mrb, (mrb_int)NK_COLOR_WINDOW));
    mrb_define_const(mrb, mod, "NK_COLOR_HEADER", mrb_int_value(mrb, (mrb_int)NK_COLOR_HEADER));
    mrb_define_const(mrb, mod, "NK_COLOR_BORDER", mrb_int_value(mrb, (mrb_int)NK_COLOR_BORDER));
    mrb_define_const(mrb, mod, "NK_COLOR_BUTTON", mrb_int_value(mrb, (mrb_int)NK_COLOR_BUTTON));
    mrb_define_const(mrb, mod, "NK_COLOR_BUTTON_HOVER", mrb_int_value(mrb, (mrb_int)NK_COLOR_BUTTON_HOVER));
    mrb_define_const(mrb, mod, "NK_COLOR_BUTTON_ACTIVE", mrb_int_value(mrb, (mrb_int)NK_COLOR_BUTTON_ACTIVE));
    mrb_define_const(mrb, mod, "NK_COLOR_TOGGLE", mrb_int_value(mrb, (mrb_int)NK_COLOR_TOGGLE));
    mrb_define_const(mrb, mod, "NK_COLOR_TOGGLE_HOVER", mrb_int_value(mrb, (mrb_int)NK_COLOR_TOGGLE_HOVER));
    mrb_define_const(mrb, mod, "NK_COLOR_TOGGLE_CURSOR", mrb_int_value(mrb, (mrb_int)NK_COLOR_TOGGLE_CURSOR));
    mrb_define_const(mrb, mod, "NK_COLOR_SELECT", mrb_int_value(mrb, (mrb_int)NK_COLOR_SELECT));
    mrb_define_const(mrb, mod, "NK_COLOR_SELECT_ACTIVE", mrb_int_value(mrb, (mrb_int)NK_COLOR_SELECT_ACTIVE));
    mrb_define_const(mrb, mod, "NK_COLOR_SLIDER", mrb_int_value(mrb, (mrb_int)NK_COLOR_SLIDER));
    mrb_define_const(mrb, mod, "NK_COLOR_SLIDER_CURSOR", mrb_int_value(mrb, (mrb_int)NK_COLOR_SLIDER_CURSOR));
    mrb_define_const(mrb, mod, "NK_COLOR_SLIDER_CURSOR_HOVER", mrb_int_value(mrb, (mrb_int)NK_COLOR_SLIDER_CURSOR_HOVER));
    mrb_define_const(mrb, mod, "NK_COLOR_SLIDER_CURSOR_ACTIVE", mrb_int_value(mrb, (mrb_int)NK_COLOR_SLIDER_CURSOR_ACTIVE));
    mrb_define_const(mrb, mod, "NK_COLOR_PROPERTY", mrb_int_value(mrb, (mrb_int)NK_COLOR_PROPERTY));
    mrb_define_const(mrb, mod, "NK_COLOR_EDIT", mrb_int_value(mrb, (mrb_int)NK_COLOR_EDIT));
    mrb_define_const(mrb, mod, "NK_COLOR_EDIT_CURSOR", mrb_int_value(mrb, (mrb_int)NK_COLOR_EDIT_CURSOR));
    mrb_define_const(mrb, mod, "NK_COLOR_COMBO", mrb_int_value(mrb, (mrb_int)NK_COLOR_COMBO));
    mrb_define_const(mrb, mod, "NK_COLOR_CHART", mrb_int_value(mrb, (mrb_int)NK_COLOR_CHART));
    mrb_define_const(mrb, mod, "NK_COLOR_CHART_COLOR", mrb_int_value(mrb, (mrb_int)NK_COLOR_CHART_COLOR));
    mrb_define_const(mrb, mod, "NK_COLOR_CHART_COLOR_HIGHLIGHT", mrb_int_value(mrb, (mrb_int)NK_COLOR_CHART_COLOR_HIGHLIGHT));
    mrb_define_const(mrb, mod, "NK_COLOR_SCROLLBAR", mrb_int_value(mrb, (mrb_int)NK_COLOR_SCROLLBAR));
    mrb_define_const(mrb, mod, "NK_COLOR_SCROLLBAR_CURSOR", mrb_int_value(mrb, (mrb_int)NK_COLOR_SCROLLBAR_CURSOR));
    mrb_define_const(mrb, mod, "NK_COLOR_SCROLLBAR_CURSOR_HOVER", mrb_int_value(mrb, (mrb_int)NK_COLOR_SCROLLBAR_CURSOR_HOVER));
    mrb_define_const(mrb, mod, "NK_COLOR_SCROLLBAR_CURSOR_ACTIVE", mrb_int_value(mrb, (mrb_int)NK_COLOR_SCROLLBAR_CURSOR_ACTIVE));
    mrb_define_const(mrb, mod, "NK_COLOR_TAB_HEADER", mrb_int_value(mrb, (mrb_int)NK_COLOR_TAB_HEADER));
    mrb_define_const(mrb, mod, "NK_COLOR_KNOB", mrb_int_value(mrb, (mrb_int)NK_COLOR_KNOB));
    mrb_define_const(mrb, mod, "NK_COLOR_KNOB_CURSOR", mrb_int_value(mrb, (mrb_int)NK_COLOR_KNOB_CURSOR));
    mrb_define_const(mrb, mod, "NK_COLOR_KNOB_CURSOR_HOVER", mrb_int_value(mrb, (mrb_int)NK_COLOR_KNOB_CURSOR_HOVER));
    mrb_define_const(mrb, mod, "NK_COLOR_KNOB_CURSOR_ACTIVE", mrb_int_value(mrb, (mrb_int)NK_COLOR_KNOB_CURSOR_ACTIVE));
    mrb_define_const(mrb, mod, "NK_COLOR_COUNT", mrb_int_value(mrb, (mrb_int)NK_COLOR_COUNT));
    mrb_define_const(mrb, mod, "NK_CURSOR_ARROW", mrb_int_value(mrb, (mrb_int)NK_CURSOR_ARROW));
    mrb_define_const(mrb, mod, "NK_CURSOR_TEXT", mrb_int_value(mrb, (mrb_int)NK_CURSOR_TEXT));
    mrb_define_const(mrb, mod, "NK_CURSOR_MOVE", mrb_int_value(mrb, (mrb_int)NK_CURSOR_MOVE));
    mrb_define_const(mrb, mod, "NK_CURSOR_RESIZE_VERTICAL", mrb_int_value(mrb, (mrb_int)NK_CURSOR_RESIZE_VERTICAL));
    mrb_define_const(mrb, mod, "NK_CURSOR_RESIZE_HORIZONTAL", mrb_int_value(mrb, (mrb_int)NK_CURSOR_RESIZE_HORIZONTAL));
    mrb_define_const(mrb, mod, "NK_CURSOR_RESIZE_TOP_LEFT_DOWN_RIGHT", mrb_int_value(mrb, (mrb_int)NK_CURSOR_RESIZE_TOP_LEFT_DOWN_RIGHT));
    mrb_define_const(mrb, mod, "NK_CURSOR_RESIZE_TOP_RIGHT_DOWN_LEFT", mrb_int_value(mrb, (mrb_int)NK_CURSOR_RESIZE_TOP_RIGHT_DOWN_LEFT));
    mrb_define_const(mrb, mod, "NK_CURSOR_COUNT", mrb_int_value(mrb, (mrb_int)NK_CURSOR_COUNT));
    mrb_define_const(mrb, mod, "NK_HEADER_LEFT", mrb_int_value(mrb, (mrb_int)NK_HEADER_LEFT));
    mrb_define_const(mrb, mod, "NK_HEADER_RIGHT", mrb_int_value(mrb, (mrb_int)NK_HEADER_RIGHT));
    mrb_define_const(mrb, mod, "NK_STYLE_ITEM_COLOR", mrb_int_value(mrb, (mrb_int)NK_STYLE_ITEM_COLOR));
    mrb_define_const(mrb, mod, "NK_STYLE_ITEM_IMAGE", mrb_int_value(mrb, (mrb_int)NK_STYLE_ITEM_IMAGE));
    mrb_define_const(mrb, mod, "NK_STYLE_ITEM_NINE_SLICE", mrb_int_value(mrb, (mrb_int)NK_STYLE_ITEM_NINE_SLICE));
    mrb_define_const(mrb, mod, "NK_SYMBOL_NONE", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_NONE));
    mrb_define_const(mrb, mod, "NK_SYMBOL_X", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_X));
    mrb_define_const(mrb, mod, "NK_SYMBOL_UNDERSCORE", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_UNDERSCORE));
    mrb_define_const(mrb, mod, "NK_SYMBOL_CIRCLE_SOLID", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_CIRCLE_SOLID));
    mrb_define_const(mrb, mod, "NK_SYMBOL_CIRCLE_OUTLINE", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_CIRCLE_OUTLINE));
    mrb_define_const(mrb, mod, "NK_SYMBOL_RECT_SOLID", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_RECT_SOLID));
    mrb_define_const(mrb, mod, "NK_SYMBOL_RECT_OUTLINE", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_RECT_OUTLINE));
    mrb_define_const(mrb, mod, "NK_SYMBOL_TRIANGLE_UP", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_TRIANGLE_UP));
    mrb_define_const(mrb, mod, "NK_SYMBOL_TRIANGLE_DOWN", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_TRIANGLE_DOWN));
    mrb_define_const(mrb, mod, "NK_SYMBOL_TRIANGLE_LEFT", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_TRIANGLE_LEFT));
    mrb_define_const(mrb, mod, "NK_SYMBOL_TRIANGLE_RIGHT", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_TRIANGLE_RIGHT));
    mrb_define_const(mrb, mod, "NK_SYMBOL_PLUS", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_PLUS));
    mrb_define_const(mrb, mod, "NK_SYMBOL_MINUS", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_MINUS));
    mrb_define_const(mrb, mod, "NK_SYMBOL_TRIANGLE_UP_OUTLINE", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_TRIANGLE_UP_OUTLINE));
    mrb_define_const(mrb, mod, "NK_SYMBOL_TRIANGLE_DOWN_OUTLINE", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_TRIANGLE_DOWN_OUTLINE));
    mrb_define_const(mrb, mod, "NK_SYMBOL_TRIANGLE_LEFT_OUTLINE", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_TRIANGLE_LEFT_OUTLINE));
    mrb_define_const(mrb, mod, "NK_SYMBOL_TRIANGLE_RIGHT_OUTLINE", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_TRIANGLE_RIGHT_OUTLINE));
    mrb_define_const(mrb, mod, "NK_SYMBOL_MAX", mrb_int_value(mrb, (mrb_int)NK_SYMBOL_MAX));
    mrb_define_const(mrb, mod, "NK_TEXT_ALIGN_LEFT", mrb_int_value(mrb, (mrb_int)NK_TEXT_ALIGN_LEFT));
    mrb_define_const(mrb, mod, "NK_TEXT_ALIGN_CENTERED", mrb_int_value(mrb, (mrb_int)NK_TEXT_ALIGN_CENTERED));
    mrb_define_const(mrb, mod, "NK_TEXT_ALIGN_RIGHT", mrb_int_value(mrb, (mrb_int)NK_TEXT_ALIGN_RIGHT));
    mrb_define_const(mrb, mod, "NK_TEXT_ALIGN_TOP", mrb_int_value(mrb, (mrb_int)NK_TEXT_ALIGN_TOP));
    mrb_define_const(mrb, mod, "NK_TEXT_ALIGN_MIDDLE", mrb_int_value(mrb, (mrb_int)NK_TEXT_ALIGN_MIDDLE));
    mrb_define_const(mrb, mod, "NK_TEXT_ALIGN_BOTTOM", mrb_int_value(mrb, (mrb_int)NK_TEXT_ALIGN_BOTTOM));
    mrb_define_const(mrb, mod, "NK_TEXT_LEFT", mrb_int_value(mrb, (mrb_int)NK_TEXT_LEFT));
    mrb_define_const(mrb, mod, "NK_TEXT_CENTERED", mrb_int_value(mrb, (mrb_int)NK_TEXT_CENTERED));
    mrb_define_const(mrb, mod, "NK_TEXT_RIGHT", mrb_int_value(mrb, (mrb_int)NK_TEXT_RIGHT));
    mrb_define_const(mrb, mod, "NK_TEXT_EDIT_MODE_VIEW", mrb_int_value(mrb, (mrb_int)NK_TEXT_EDIT_MODE_VIEW));
    mrb_define_const(mrb, mod, "NK_TEXT_EDIT_MODE_INSERT", mrb_int_value(mrb, (mrb_int)NK_TEXT_EDIT_MODE_INSERT));
    mrb_define_const(mrb, mod, "NK_TEXT_EDIT_MODE_REPLACE", mrb_int_value(mrb, (mrb_int)NK_TEXT_EDIT_MODE_REPLACE));
    mrb_define_const(mrb, mod, "NK_TEXT_EDIT_SINGLE_LINE", mrb_int_value(mrb, (mrb_int)NK_TEXT_EDIT_SINGLE_LINE));
    mrb_define_const(mrb, mod, "NK_TEXT_EDIT_MULTI_LINE", mrb_int_value(mrb, (mrb_int)NK_TEXT_EDIT_MULTI_LINE));
    mrb_define_const(mrb, mod, "NK_TOP_LEFT", mrb_int_value(mrb, (mrb_int)NK_TOP_LEFT));
    mrb_define_const(mrb, mod, "NK_TOP_CENTER", mrb_int_value(mrb, (mrb_int)NK_TOP_CENTER));
    mrb_define_const(mrb, mod, "NK_TOP_RIGHT", mrb_int_value(mrb, (mrb_int)NK_TOP_RIGHT));
    mrb_define_const(mrb, mod, "NK_MIDDLE_LEFT", mrb_int_value(mrb, (mrb_int)NK_MIDDLE_LEFT));
    mrb_define_const(mrb, mod, "NK_MIDDLE_CENTER", mrb_int_value(mrb, (mrb_int)NK_MIDDLE_CENTER));
    mrb_define_const(mrb, mod, "NK_MIDDLE_RIGHT", mrb_int_value(mrb, (mrb_int)NK_MIDDLE_RIGHT));
    mrb_define_const(mrb, mod, "NK_BOTTOM_LEFT", mrb_int_value(mrb, (mrb_int)NK_BOTTOM_LEFT));
    mrb_define_const(mrb, mod, "NK_BOTTOM_CENTER", mrb_int_value(mrb, (mrb_int)NK_BOTTOM_CENTER));
    mrb_define_const(mrb, mod, "NK_BOTTOM_RIGHT", mrb_int_value(mrb, (mrb_int)NK_BOTTOM_RIGHT));
    mrb_define_const(mrb, mod, "NK_TREE_NODE", mrb_int_value(mrb, (mrb_int)NK_TREE_NODE));
    mrb_define_const(mrb, mod, "NK_TREE_TAB", mrb_int_value(mrb, (mrb_int)NK_TREE_TAB));
    mrb_define_const(mrb, mod, "NK_WIDGET_ALIGN_LEFT", mrb_int_value(mrb, (mrb_int)NK_WIDGET_ALIGN_LEFT));
    mrb_define_const(mrb, mod, "NK_WIDGET_ALIGN_CENTERED", mrb_int_value(mrb, (mrb_int)NK_WIDGET_ALIGN_CENTERED));
    mrb_define_const(mrb, mod, "NK_WIDGET_ALIGN_RIGHT", mrb_int_value(mrb, (mrb_int)NK_WIDGET_ALIGN_RIGHT));
    mrb_define_const(mrb, mod, "NK_WIDGET_ALIGN_TOP", mrb_int_value(mrb, (mrb_int)NK_WIDGET_ALIGN_TOP));
    mrb_define_const(mrb, mod, "NK_WIDGET_ALIGN_MIDDLE", mrb_int_value(mrb, (mrb_int)NK_WIDGET_ALIGN_MIDDLE));
    mrb_define_const(mrb, mod, "NK_WIDGET_ALIGN_BOTTOM", mrb_int_value(mrb, (mrb_int)NK_WIDGET_ALIGN_BOTTOM));
    mrb_define_const(mrb, mod, "NK_WIDGET_LEFT", mrb_int_value(mrb, (mrb_int)NK_WIDGET_LEFT));
    mrb_define_const(mrb, mod, "NK_WIDGET_CENTERED", mrb_int_value(mrb, (mrb_int)NK_WIDGET_CENTERED));
    mrb_define_const(mrb, mod, "NK_WIDGET_RIGHT", mrb_int_value(mrb, (mrb_int)NK_WIDGET_RIGHT));
    mrb_define_const(mrb, mod, "NK_WIDGET_INVALID", mrb_int_value(mrb, (mrb_int)NK_WIDGET_INVALID));
    mrb_define_const(mrb, mod, "NK_WIDGET_VALID", mrb_int_value(mrb, (mrb_int)NK_WIDGET_VALID));
    mrb_define_const(mrb, mod, "NK_WIDGET_ROM", mrb_int_value(mrb, (mrb_int)NK_WIDGET_ROM));
    mrb_define_const(mrb, mod, "NK_WIDGET_DISABLED", mrb_int_value(mrb, (mrb_int)NK_WIDGET_DISABLED));
    mrb_define_const(mrb, mod, "NK_WIDGET_STATE_MODIFIED", mrb_int_value(mrb, (mrb_int)NK_WIDGET_STATE_MODIFIED));
    mrb_define_const(mrb, mod, "NK_WIDGET_STATE_INACTIVE", mrb_int_value(mrb, (mrb_int)NK_WIDGET_STATE_INACTIVE));
    mrb_define_const(mrb, mod, "NK_WIDGET_STATE_ENTERED", mrb_int_value(mrb, (mrb_int)NK_WIDGET_STATE_ENTERED));
    mrb_define_const(mrb, mod, "NK_WIDGET_STATE_HOVER", mrb_int_value(mrb, (mrb_int)NK_WIDGET_STATE_HOVER));
    mrb_define_const(mrb, mod, "NK_WIDGET_STATE_ACTIVED", mrb_int_value(mrb, (mrb_int)NK_WIDGET_STATE_ACTIVED));
    mrb_define_const(mrb, mod, "NK_WIDGET_STATE_LEFT", mrb_int_value(mrb, (mrb_int)NK_WIDGET_STATE_LEFT));
    mrb_define_const(mrb, mod, "NK_WIDGET_STATE_HOVERED", mrb_int_value(mrb, (mrb_int)NK_WIDGET_STATE_HOVERED));
    mrb_define_const(mrb, mod, "NK_WIDGET_STATE_ACTIVE", mrb_int_value(mrb, (mrb_int)NK_WIDGET_STATE_ACTIVE));
    mrb_define_const(mrb, mod, "NK_WINDOW_PRIVATE", mrb_int_value(mrb, (mrb_int)NK_WINDOW_PRIVATE));
    mrb_define_const(mrb, mod, "NK_WINDOW_DYNAMIC", mrb_int_value(mrb, (mrb_int)NK_WINDOW_DYNAMIC));
    mrb_define_const(mrb, mod, "NK_WINDOW_ROM", mrb_int_value(mrb, (mrb_int)NK_WINDOW_ROM));
    mrb_define_const(mrb, mod, "NK_WINDOW_NOT_INTERACTIVE", mrb_int_value(mrb, (mrb_int)NK_WINDOW_NOT_INTERACTIVE));
    mrb_define_const(mrb, mod, "NK_WINDOW_HIDDEN", mrb_int_value(mrb, (mrb_int)NK_WINDOW_HIDDEN));
    mrb_define_const(mrb, mod, "NK_WINDOW_CLOSED", mrb_int_value(mrb, (mrb_int)NK_WINDOW_CLOSED));
    mrb_define_const(mrb, mod, "NK_WINDOW_MINIMIZED", mrb_int_value(mrb, (mrb_int)NK_WINDOW_MINIMIZED));
    mrb_define_const(mrb, mod, "NK_WINDOW_REMOVE_ROM", mrb_int_value(mrb, (mrb_int)NK_WINDOW_REMOVE_ROM));
}
