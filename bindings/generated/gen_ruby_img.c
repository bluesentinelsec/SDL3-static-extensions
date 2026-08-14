/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for SDL_image. */
#include "../src/gen_support_ruby.h"

#include <SDL3_image/SDL_image.h>
#include <string.h>

static void GenDtor_IMG_FreeAnimation(void *p)
{
    IMG_Animation *typed = (IMG_Animation *)p;
    IMG_FreeAnimation(typed);
}

static void GenDtor_SDL_DestroySurface(void *p)
{
    SDL_Surface *typed = (SDL_Surface *)p;
    SDL_DestroySurface(typed);
}

static mrb_value GenR_IMG_AddAnimationEncoderFrame(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_AnimationEncoder *a0 = (IMG_AnimationEncoder *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_AnimationEncoder");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Surface");
    Uint64 a2 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = IMG_AddAnimationEncoderFrame(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_CloseAnimationDecoder(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_AnimationDecoder *a0 = (IMG_AnimationDecoder *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_AnimationDecoder");
    bool rv = IMG_CloseAnimationDecoder(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_CloseAnimationEncoder(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_AnimationEncoder *a0 = (IMG_AnimationEncoder *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_AnimationEncoder");
    bool rv = IMG_CloseAnimationEncoder(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_CreateAnimatedCursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_Animation");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Cursor * rv = IMG_CreateAnimatedCursor(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Cursor");
    }
}

static mrb_value GenR_IMG_CreateAnimationDecoder(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    IMG_AnimationDecoder * rv = IMG_CreateAnimationDecoder(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "IMG_AnimationDecoder");
    }
}

static mrb_value GenR_IMG_CreateAnimationDecoderWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    IMG_AnimationDecoder * rv = IMG_CreateAnimationDecoderWithProperties(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "IMG_AnimationDecoder");
    }
}

static mrb_value GenR_IMG_CreateAnimationDecoder_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    IMG_AnimationDecoder * rv = IMG_CreateAnimationDecoder_IO(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "IMG_AnimationDecoder");
    }
}

static mrb_value GenR_IMG_CreateAnimationEncoder(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    IMG_AnimationEncoder * rv = IMG_CreateAnimationEncoder(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "IMG_AnimationEncoder");
    }
}

static mrb_value GenR_IMG_CreateAnimationEncoderWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    IMG_AnimationEncoder * rv = IMG_CreateAnimationEncoderWithProperties(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "IMG_AnimationEncoder");
    }
}

static mrb_value GenR_IMG_CreateAnimationEncoder_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    IMG_AnimationEncoder * rv = IMG_CreateAnimationEncoder_IO(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "IMG_AnimationEncoder");
    }
}

static mrb_value GenR_IMG_FreeAnimation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_Animation");
    IMG_FreeAnimation(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_IMG_GetAnimationDecoderProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_AnimationDecoder *a0 = (IMG_AnimationDecoder *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_AnimationDecoder");
    SDL_PropertiesID rv = IMG_GetAnimationDecoderProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_IMG_GetAnimationDecoderStatus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_AnimationDecoder *a0 = (IMG_AnimationDecoder *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_AnimationDecoder");
    IMG_AnimationDecoderStatus rv = IMG_GetAnimationDecoderStatus(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_IMG_GetClipboardImage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface * rv = IMG_GetClipboardImage();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_Load(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Surface * rv = IMG_Load(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_IMG_LoadANIAnimation_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    IMG_Animation * rv = IMG_LoadANIAnimation_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "IMG_Animation");
    }
}

static mrb_value GenR_IMG_LoadAnimation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    IMG_Animation * rv = IMG_LoadAnimation(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "IMG_Animation", GenDtor_IMG_FreeAnimation);
    }
}

static mrb_value GenR_IMG_LoadAnimationTyped_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    IMG_Animation * rv = IMG_LoadAnimationTyped_IO(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "IMG_Animation", GenDtor_IMG_FreeAnimation);
    }
}

static mrb_value GenR_IMG_LoadAnimation_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    IMG_Animation * rv = IMG_LoadAnimation_IO(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "IMG_Animation", GenDtor_IMG_FreeAnimation);
    }
}

static mrb_value GenR_IMG_LoadBMP_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadBMP_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadCUR_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadCUR_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadGIFAnimation_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    IMG_Animation * rv = IMG_LoadGIFAnimation_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "IMG_Animation");
    }
}

static mrb_value GenR_IMG_LoadGIF_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadGIF_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadGPUTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUCopyPass *a1 = (SDL_GPUCopyPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUCopyPass");
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int io4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_GPUTexture * rv = IMG_LoadGPUTexture(a0, a1, a2, &io3, &io4);
    mrb_value rets[3];
    rets[0] = SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTexture");
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    rets[2] = mrb_int_value(mrb, (mrb_int)io4);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_IMG_LoadGPUTextureTyped_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUCopyPass *a1 = (SDL_GPUCopyPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUCopyPass");
    SDL_IOStream *a2 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_IOStream");
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    const char *a4 = SDLStaticGen_RubyToStr(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int io5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    int io6 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    SDL_GPUTexture * rv = IMG_LoadGPUTextureTyped_IO(a0, a1, a2, a3, a4, &io5, &io6);
    mrb_value rets[3];
    rets[0] = SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTexture");
    rets[1] = mrb_int_value(mrb, (mrb_int)io5);
    rets[2] = mrb_int_value(mrb, (mrb_int)io6);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_IMG_LoadGPUTexture_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUCopyPass *a1 = (SDL_GPUCopyPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUCopyPass");
    SDL_IOStream *a2 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_IOStream");
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    int io4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int io5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    SDL_GPUTexture * rv = IMG_LoadGPUTexture_IO(a0, a1, a2, a3, &io4, &io5);
    mrb_value rets[3];
    rets[0] = SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTexture");
    rets[1] = mrb_int_value(mrb, (mrb_int)io4);
    rets[2] = mrb_int_value(mrb, (mrb_int)io5);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_IMG_LoadICO_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadICO_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadJPG_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadJPG_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadLBM_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadLBM_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadPCX_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadPCX_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadPNG_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadPNG_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadPNM_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadPNM_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadQOI_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadQOI_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadSVG_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadSVG_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadSizedSVG_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Surface * rv = IMG_LoadSizedSVG_IO(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadTGA_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadTGA_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Texture * rv = IMG_LoadTexture(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Texture");
    }
}

static mrb_value GenR_IMG_LoadTextureTyped_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_Texture * rv = IMG_LoadTextureTyped_IO(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Texture");
    }
}

static mrb_value GenR_IMG_LoadTexture_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Texture * rv = IMG_LoadTexture_IO(a0, a1, a2);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Texture");
    }
}

static mrb_value GenR_IMG_LoadTyped_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Surface * rv = IMG_LoadTyped_IO(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_IMG_LoadXCF_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadXCF_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadXPM_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadXPM_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_LoadXV_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadXV_IO(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_IMG_Load_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Surface * rv = IMG_Load_IO(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_IMG_ResetAnimationDecoder(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_AnimationDecoder *a0 = (IMG_AnimationDecoder *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_AnimationDecoder");
    bool rv = IMG_ResetAnimationDecoder(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_Save(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = IMG_Save(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveANIAnimation_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_Animation");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = IMG_SaveANIAnimation_IO(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveAnimation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_Animation");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = IMG_SaveAnimation(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveAnimationTyped_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_Animation");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = IMG_SaveAnimationTyped_IO(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveBMP(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = IMG_SaveBMP(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveBMP_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = IMG_SaveBMP_IO(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveCUR(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = IMG_SaveCUR(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveCUR_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = IMG_SaveCUR_IO(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveGIF(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = IMG_SaveGIF(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveGIFAnimation_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "IMG_Animation");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = IMG_SaveGIFAnimation_IO(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveGIF_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = IMG_SaveGIF_IO(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveICO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = IMG_SaveICO(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveICO_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = IMG_SaveICO_IO(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveJPG(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = IMG_SaveJPG(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveJPG_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = IMG_SaveJPG_IO(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SavePNG(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = IMG_SavePNG(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SavePNG_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = IMG_SavePNG_IO(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveTGA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = IMG_SaveTGA(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveTGA_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = IMG_SaveTGA_IO(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_SaveTyped_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = IMG_SaveTyped_IO(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_Version(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = IMG_Version();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_IMG_isANI(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isANI(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isBMP(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isBMP(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isCUR(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isCUR(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isGIF(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isGIF(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isICO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isICO(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isJPG(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isJPG(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isLBM(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isLBM(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isPCX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isPCX(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isPNG(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isPNG(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isPNM(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isPNM(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isQOI(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isQOI(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isSVG(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isSVG(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isXCF(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isXCF(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isXPM(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isXPM(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_IMG_isXV(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = IMG_isXV(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

void SDLStaticGen_OpenRuby_img(mrb_state *mrb);
void SDLStaticGen_OpenRuby_img(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "IMG");
    mrb_define_module_function(mrb, mod, "AddAnimationEncoderFrame", GenR_IMG_AddAnimationEncoderFrame, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CloseAnimationDecoder", GenR_IMG_CloseAnimationDecoder, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CloseAnimationEncoder", GenR_IMG_CloseAnimationEncoder, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAnimatedCursor", GenR_IMG_CreateAnimatedCursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAnimationDecoder", GenR_IMG_CreateAnimationDecoder, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAnimationDecoderWithProperties", GenR_IMG_CreateAnimationDecoderWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAnimationDecoder_IO", GenR_IMG_CreateAnimationDecoder_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAnimationEncoder", GenR_IMG_CreateAnimationEncoder, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAnimationEncoderWithProperties", GenR_IMG_CreateAnimationEncoderWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAnimationEncoder_IO", GenR_IMG_CreateAnimationEncoder_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FreeAnimation", GenR_IMG_FreeAnimation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAnimationDecoderProperties", GenR_IMG_GetAnimationDecoderProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAnimationDecoderStatus", GenR_IMG_GetAnimationDecoderStatus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetClipboardImage", GenR_IMG_GetClipboardImage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Load", GenR_IMG_Load, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadANIAnimation_IO", GenR_IMG_LoadANIAnimation_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadAnimation", GenR_IMG_LoadAnimation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadAnimationTyped_IO", GenR_IMG_LoadAnimationTyped_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadAnimation_IO", GenR_IMG_LoadAnimation_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadBMP_IO", GenR_IMG_LoadBMP_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadCUR_IO", GenR_IMG_LoadCUR_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadGIFAnimation_IO", GenR_IMG_LoadGIFAnimation_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadGIF_IO", GenR_IMG_LoadGIF_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadGPUTexture", GenR_IMG_LoadGPUTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadGPUTextureTyped_IO", GenR_IMG_LoadGPUTextureTyped_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadGPUTexture_IO", GenR_IMG_LoadGPUTexture_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadICO_IO", GenR_IMG_LoadICO_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadJPG_IO", GenR_IMG_LoadJPG_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadLBM_IO", GenR_IMG_LoadLBM_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadPCX_IO", GenR_IMG_LoadPCX_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadPNG_IO", GenR_IMG_LoadPNG_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadPNM_IO", GenR_IMG_LoadPNM_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadQOI_IO", GenR_IMG_LoadQOI_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadSVG_IO", GenR_IMG_LoadSVG_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadSizedSVG_IO", GenR_IMG_LoadSizedSVG_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTGA_IO", GenR_IMG_LoadTGA_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTexture", GenR_IMG_LoadTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTextureTyped_IO", GenR_IMG_LoadTextureTyped_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTexture_IO", GenR_IMG_LoadTexture_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTyped_IO", GenR_IMG_LoadTyped_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadXCF_IO", GenR_IMG_LoadXCF_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadXPM_IO", GenR_IMG_LoadXPM_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadXV_IO", GenR_IMG_LoadXV_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Load_IO", GenR_IMG_Load_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResetAnimationDecoder", GenR_IMG_ResetAnimationDecoder, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Save", GenR_IMG_Save, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveANIAnimation_IO", GenR_IMG_SaveANIAnimation_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveAnimation", GenR_IMG_SaveAnimation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveAnimationTyped_IO", GenR_IMG_SaveAnimationTyped_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveBMP", GenR_IMG_SaveBMP, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveBMP_IO", GenR_IMG_SaveBMP_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveCUR", GenR_IMG_SaveCUR, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveCUR_IO", GenR_IMG_SaveCUR_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveGIF", GenR_IMG_SaveGIF, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveGIFAnimation_IO", GenR_IMG_SaveGIFAnimation_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveGIF_IO", GenR_IMG_SaveGIF_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveICO", GenR_IMG_SaveICO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveICO_IO", GenR_IMG_SaveICO_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveJPG", GenR_IMG_SaveJPG, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveJPG_IO", GenR_IMG_SaveJPG_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SavePNG", GenR_IMG_SavePNG, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SavePNG_IO", GenR_IMG_SavePNG_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveTGA", GenR_IMG_SaveTGA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveTGA_IO", GenR_IMG_SaveTGA_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveTyped_IO", GenR_IMG_SaveTyped_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Version", GenR_IMG_Version, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isANI", GenR_IMG_isANI, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isBMP", GenR_IMG_isBMP, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isCUR", GenR_IMG_isCUR, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isGIF", GenR_IMG_isGIF, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isICO", GenR_IMG_isICO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isJPG", GenR_IMG_isJPG, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isLBM", GenR_IMG_isLBM, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isPCX", GenR_IMG_isPCX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isPNG", GenR_IMG_isPNG, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isPNM", GenR_IMG_isPNM, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isQOI", GenR_IMG_isQOI, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isSVG", GenR_IMG_isSVG, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isXCF", GenR_IMG_isXCF, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isXPM", GenR_IMG_isXPM, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isXV", GenR_IMG_isXV, MRB_ARGS_ANY());
    mrb_define_const(mrb, mod, "DECODER_STATUS_INVALID", mrb_int_value(mrb, (mrb_int)IMG_DECODER_STATUS_INVALID));
    mrb_define_const(mrb, mod, "DECODER_STATUS_OK", mrb_int_value(mrb, (mrb_int)IMG_DECODER_STATUS_OK));
    mrb_define_const(mrb, mod, "DECODER_STATUS_FAILED", mrb_int_value(mrb, (mrb_int)IMG_DECODER_STATUS_FAILED));
    mrb_define_const(mrb, mod, "DECODER_STATUS_COMPLETE", mrb_int_value(mrb, (mrb_int)IMG_DECODER_STATUS_COMPLETE));
}
