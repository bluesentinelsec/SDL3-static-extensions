/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for SDL3_gfx. */
#include "../src/gen_support_ruby.h"

#include <SDL3_gfx/SDL3_gfxPrimitives.h>
#include <SDL3_gfx/SDL3_rotozoom.h>
#include <SDL3_gfx/SDL3_framerate.h>
#include <string.h>

static mrb_value GenPush_FPSmanager(mrb_state *mrb, const FPSmanager *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "framecount", mrb_int_value(mrb, (mrb_int)in->framecount));
    SDLStaticGen_RubyHashSet(mrb, h, "rateticks", mrb_float_value(mrb, (mrb_float)in->rateticks));
    SDLStaticGen_RubyHashSet(mrb, h, "baseticks", mrb_int_value(mrb, (mrb_int)in->baseticks));
    SDLStaticGen_RubyHashSet(mrb, h, "lastticks", mrb_int_value(mrb, (mrb_int)in->lastticks));
    SDLStaticGen_RubyHashSet(mrb, h, "rate", mrb_int_value(mrb, (mrb_int)in->rate));
    return h;
}

static void GenDtor_SDL_DestroySurface(void *p)
{
    SDL_Surface *typed = (SDL_Surface *)p;
    SDL_DestroySurface(typed);
}

static mrb_value GenR_SDL_framerateDelay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    FPSmanager out0;
    memset(&out0, 0, sizeof(out0));
    Uint64 rv = SDL_framerateDelay(&out0);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_FPSmanager(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_getFramecount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    FPSmanager out0;
    memset(&out0, 0, sizeof(out0));
    int rv = SDL_getFramecount(&out0);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_FPSmanager(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_getFramerate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    FPSmanager out0;
    memset(&out0, 0, sizeof(out0));
    int rv = SDL_getFramerate(&out0);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_FPSmanager(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_initFramerate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    FPSmanager out0;
    memset(&out0, 0, sizeof(out0));
    SDL_initFramerate(&out0);
    return GenPush_FPSmanager(mrb, &out0);
    }
}

static mrb_value GenR_SDL_setFramerate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    FPSmanager out0;
    memset(&out0, 0, sizeof(out0));
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = SDL_setFramerate(&out0, a1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_FPSmanager(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_aacircleColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = aacircleColor(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_aacircleRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    bool rv = aacircleRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_aaellipseColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    bool rv = aaellipseColor(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_aaellipseRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    bool rv = aaellipseRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_aalineColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    bool rv = aalineColor(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_aalineRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    bool rv = aalineRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_aatrigonColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Sint16 a6 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint32 a7 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    bool rv = aatrigonColor(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_aatrigonRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Sint16 a6 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    Uint8 a9 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 9 ? argv[9] : mrb_nil_value()));
    Uint8 a10 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 10 ? argv[10] : mrb_nil_value()));
    bool rv = aatrigonRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_arcColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint32 a6 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = arcColor(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_arcRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    Uint8 a9 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 9 ? argv[9] : mrb_nil_value()));
    bool rv = arcRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_boxColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    bool rv = boxColor(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_boxRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    bool rv = boxRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_characterColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    char a3 = (char)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = characterColor(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_characterRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    char a3 = (char)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    bool rv = characterRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_circleColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = circleColor(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_circleRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    bool rv = circleRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_ellipseColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    bool rv = ellipseColor(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_ellipseRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    bool rv = ellipseRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_filledCircleColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = filledCircleColor(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_filledCircleRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    bool rv = filledCircleRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_filledEllipseColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    bool rv = filledEllipseColor(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_filledEllipseRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    bool rv = filledEllipseRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_filledPieColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint32 a6 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = filledPieColor(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_filledPieRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    Uint8 a9 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 9 ? argv[9] : mrb_nil_value()));
    bool rv = filledPieRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_filledTrigonColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Sint16 a6 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint32 a7 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    bool rv = filledTrigonColor(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_filledTrigonRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Sint16 a6 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    Uint8 a9 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 9 ? argv[9] : mrb_nil_value()));
    Uint8 a10 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 10 ? argv[10] : mrb_nil_value()));
    bool rv = filledTrigonRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_gfxPrimitivesSetFontRotation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    gfxPrimitivesSetFontRotation(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_hlineColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = hlineColor(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_hlineRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    bool rv = hlineRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_lineColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    bool rv = lineColor(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_lineRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    bool rv = lineRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_pieColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint32 a6 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = pieColor(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_pieRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    Uint8 a9 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 9 ? argv[9] : mrb_nil_value()));
    bool rv = pieRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_pixelColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = pixelColor(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_pixelRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = pixelRGBA(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_rectangleColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    bool rv = rectangleColor(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_rectangleRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    bool rv = rectangleRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_rotateSurface90Degrees(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Surface * rv = rotateSurface90Degrees(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_rotozoomSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    double a1 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    double a2 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_Surface * rv = rotozoomSurface(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_rotozoomSurfaceSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    double a2 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    double a3 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int io4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int io5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    rotozoomSurfaceSize(a0, a1, a2, a3, &io4, &io5);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)io4);
    rets[1] = mrb_int_value(mrb, (mrb_int)io5);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_rotozoomSurfaceSizeXY(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    double a2 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    double a3 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    double a4 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int io5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    int io6 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    rotozoomSurfaceSizeXY(a0, a1, a2, a3, a4, &io5, &io6);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)io5);
    rets[1] = mrb_int_value(mrb, (mrb_int)io6);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_rotozoomSurfaceXY(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    double a1 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    double a2 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    double a3 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_Surface * rv = rotozoomSurfaceXY(a0, a1, a2, a3, a4);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_roundedBoxColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint32 a6 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = roundedBoxColor(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_roundedBoxRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    Uint8 a9 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 9 ? argv[9] : mrb_nil_value()));
    bool rv = roundedBoxRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_roundedRectangleColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint32 a6 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = roundedRectangleColor(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_roundedRectangleRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    Uint8 a9 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 9 ? argv[9] : mrb_nil_value()));
    bool rv = roundedRectangleRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_shrinkSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Surface * rv = shrinkSurface(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_stringColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = stringColor(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_stringRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    bool rv = stringRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_thickLineColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint32 a6 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = thickLineColor(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_thickLineRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    Uint8 a9 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 9 ? argv[9] : mrb_nil_value()));
    bool rv = thickLineRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_trigonColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Sint16 a6 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint32 a7 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    bool rv = trigonColor(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_trigonRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint16 a4 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Sint16 a5 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Sint16 a6 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    Uint8 a8 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 8 ? argv[8] : mrb_nil_value()));
    Uint8 a9 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 9 ? argv[9] : mrb_nil_value()));
    Uint8 a10 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 10 ? argv[10] : mrb_nil_value()));
    bool rv = trigonRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_vlineColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = vlineColor(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_vlineRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    Uint8 a7 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    bool rv = vlineRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_zoomSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    double a1 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    double a2 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_Surface * rv = zoomSurface(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_zoomSurfaceSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    double a2 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    double a3 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int io4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int io5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    zoomSurfaceSize(a0, a1, a2, a3, &io4, &io5);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)io4);
    rets[1] = mrb_int_value(mrb, (mrb_int)io5);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

void SDLStaticGen_OpenRuby_gfx(mrb_state *mrb);
void SDLStaticGen_OpenRuby_gfx(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "GFX");
    mrb_define_module_function(mrb, mod, "SDL_framerateDelay", GenR_SDL_framerateDelay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SDL_getFramecount", GenR_SDL_getFramecount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SDL_getFramerate", GenR_SDL_getFramerate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SDL_initFramerate", GenR_SDL_initFramerate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SDL_setFramerate", GenR_SDL_setFramerate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "aacircleColor", GenR_aacircleColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "aacircleRGBA", GenR_aacircleRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "aaellipseColor", GenR_aaellipseColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "aaellipseRGBA", GenR_aaellipseRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "aalineColor", GenR_aalineColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "aalineRGBA", GenR_aalineRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "aatrigonColor", GenR_aatrigonColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "aatrigonRGBA", GenR_aatrigonRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "arcColor", GenR_arcColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "arcRGBA", GenR_arcRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "boxColor", GenR_boxColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "boxRGBA", GenR_boxRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "characterColor", GenR_characterColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "characterRGBA", GenR_characterRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "circleColor", GenR_circleColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "circleRGBA", GenR_circleRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ellipseColor", GenR_ellipseColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ellipseRGBA", GenR_ellipseRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filledCircleColor", GenR_filledCircleColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filledCircleRGBA", GenR_filledCircleRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filledEllipseColor", GenR_filledEllipseColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filledEllipseRGBA", GenR_filledEllipseRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filledPieColor", GenR_filledPieColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filledPieRGBA", GenR_filledPieRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filledTrigonColor", GenR_filledTrigonColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "filledTrigonRGBA", GenR_filledTrigonRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "gfxPrimitivesSetFontRotation", GenR_gfxPrimitivesSetFontRotation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hlineColor", GenR_hlineColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hlineRGBA", GenR_hlineRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "lineColor", GenR_lineColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "lineRGBA", GenR_lineRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "pieColor", GenR_pieColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "pieRGBA", GenR_pieRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "pixelColor", GenR_pixelColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "pixelRGBA", GenR_pixelRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rectangleColor", GenR_rectangleColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rectangleRGBA", GenR_rectangleRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rotateSurface90Degrees", GenR_rotateSurface90Degrees, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rotozoomSurface", GenR_rotozoomSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rotozoomSurfaceSize", GenR_rotozoomSurfaceSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rotozoomSurfaceSizeXY", GenR_rotozoomSurfaceSizeXY, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "rotozoomSurfaceXY", GenR_rotozoomSurfaceXY, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "roundedBoxColor", GenR_roundedBoxColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "roundedBoxRGBA", GenR_roundedBoxRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "roundedRectangleColor", GenR_roundedRectangleColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "roundedRectangleRGBA", GenR_roundedRectangleRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "shrinkSurface", GenR_shrinkSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "stringColor", GenR_stringColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "stringRGBA", GenR_stringRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "thickLineColor", GenR_thickLineColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "thickLineRGBA", GenR_thickLineRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "trigonColor", GenR_trigonColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "trigonRGBA", GenR_trigonRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "vlineColor", GenR_vlineColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "vlineRGBA", GenR_vlineRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "zoomSurface", GenR_zoomSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "zoomSurfaceSize", GenR_zoomSurfaceSize, MRB_ARGS_ANY());
}
