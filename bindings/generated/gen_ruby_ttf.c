/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for SDL_ttf. */
#include "../src/gen_support_ruby.h"

#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_ttf/SDL_textengine.h>
#include <string.h>

static void GenRead_SDL_Color(mrb_state *mrb, mrb_value h, SDL_Color *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->r = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "r");
    out->g = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "g");
    out->b = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "b");
    out->a = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "a");
}

static void GenRead_SDL_Rect(mrb_state *mrb, mrb_value h, SDL_Rect *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (int)SDLStaticGen_RubyFieldInt(mrb, h, "x");
    out->y = (int)SDLStaticGen_RubyFieldInt(mrb, h, "y");
    out->w = (int)SDLStaticGen_RubyFieldInt(mrb, h, "w");
    out->h = (int)SDLStaticGen_RubyFieldInt(mrb, h, "h");
}

static mrb_value GenPush_SDL_Rect(mrb_state *mrb, const SDL_Rect *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "x", mrb_int_value(mrb, (mrb_int)in->x));
    SDLStaticGen_RubyHashSet(mrb, h, "y", mrb_int_value(mrb, (mrb_int)in->y));
    SDLStaticGen_RubyHashSet(mrb, h, "w", mrb_int_value(mrb, (mrb_int)in->w));
    SDLStaticGen_RubyHashSet(mrb, h, "h", mrb_int_value(mrb, (mrb_int)in->h));
    return h;
}

static void GenRead_TTF_SubString(mrb_state *mrb, mrb_value h, TTF_SubString *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->flags = (TTF_SubStringFlags)SDLStaticGen_RubyFieldInt(mrb, h, "flags");
    out->offset = (int)SDLStaticGen_RubyFieldInt(mrb, h, "offset");
    out->length = (int)SDLStaticGen_RubyFieldInt(mrb, h, "length");
    out->line_index = (int)SDLStaticGen_RubyFieldInt(mrb, h, "line_index");
    out->cluster_index = (int)SDLStaticGen_RubyFieldInt(mrb, h, "cluster_index");
    GenRead_SDL_Rect(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "rect"), &out->rect);
}

static mrb_value GenPush_TTF_SubString(mrb_state *mrb, const TTF_SubString *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "flags", mrb_int_value(mrb, (mrb_int)in->flags));
    SDLStaticGen_RubyHashSet(mrb, h, "offset", mrb_int_value(mrb, (mrb_int)in->offset));
    SDLStaticGen_RubyHashSet(mrb, h, "length", mrb_int_value(mrb, (mrb_int)in->length));
    SDLStaticGen_RubyHashSet(mrb, h, "line_index", mrb_int_value(mrb, (mrb_int)in->line_index));
    SDLStaticGen_RubyHashSet(mrb, h, "cluster_index", mrb_int_value(mrb, (mrb_int)in->cluster_index));
    SDLStaticGen_RubyHashSet(mrb, h, "rect", GenPush_SDL_Rect(mrb, &in->rect));
    return h;
}

static void GenDtor_TTF_CloseFont(void *p)
{
    TTF_Font *typed = (TTF_Font *)p;
    TTF_CloseFont(typed);
}

static void GenDtor_TTF_DestroyRendererTextEngine(void *p)
{
    TTF_TextEngine *typed = (TTF_TextEngine *)p;
    TTF_DestroyRendererTextEngine(typed);
}

static void GenDtor_TTF_DestroyText(void *p)
{
    TTF_Text *typed = (TTF_Text *)p;
    TTF_DestroyText(typed);
}

static void GenDtor_SDL_DestroySurface(void *p)
{
    SDL_Surface *typed = (SDL_Surface *)p;
    SDL_DestroySurface(typed);
}

static mrb_value GenR_TTF_AddFallbackFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    TTF_Font *a1 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "TTF_Font");
    bool rv = TTF_AddFallbackFont(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_AppendTextString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = TTF_AppendTextString(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_ClearFallbackFonts(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    TTF_ClearFallbackFonts(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_CloseFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    TTF_CloseFont(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_CopyFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    TTF_Font * rv = TTF_CopyFont(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "TTF_Font", GenDtor_TTF_CloseFont);
    }
}

static mrb_value GenR_TTF_CreateGPUTextEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    TTF_TextEngine * rv = TTF_CreateGPUTextEngine(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "TTF_TextEngine");
    }
}

static mrb_value GenR_TTF_CreateGPUTextEngineWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    TTF_TextEngine * rv = TTF_CreateGPUTextEngineWithProperties(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "TTF_TextEngine");
    }
}

static mrb_value GenR_TTF_CreateRendererTextEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    TTF_TextEngine * rv = TTF_CreateRendererTextEngine(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "TTF_TextEngine", GenDtor_TTF_DestroyRendererTextEngine);
    }
}

static mrb_value GenR_TTF_CreateRendererTextEngineWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    TTF_TextEngine * rv = TTF_CreateRendererTextEngineWithProperties(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "TTF_TextEngine");
    }
}

static mrb_value GenR_TTF_CreateSurfaceTextEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_TextEngine * rv = TTF_CreateSurfaceTextEngine();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "TTF_TextEngine");
    }
}

static mrb_value GenR_TTF_CreateText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_TextEngine *a0 = (TTF_TextEngine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_TextEngine");
    TTF_Font *a1 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "TTF_Font");
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    size_t a3 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    TTF_Text * rv = TTF_CreateText(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "TTF_Text", GenDtor_TTF_DestroyText);
    }
}

static mrb_value GenR_TTF_DeleteTextString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = TTF_DeleteTextString(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_DestroyGPUTextEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_TextEngine *a0 = (TTF_TextEngine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_TextEngine");
    TTF_DestroyGPUTextEngine(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_DestroyRendererTextEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_TextEngine *a0 = (TTF_TextEngine *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_TextEngine");
    TTF_DestroyRendererTextEngine(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_DestroySurfaceTextEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_TextEngine *a0 = (TTF_TextEngine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_TextEngine");
    TTF_DestroySurfaceTextEngine(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_DestroyText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    TTF_DestroyText(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_DrawRendererText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = TTF_DrawRendererText(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_DrawSurfaceText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Surface *a3 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), "SDL_Surface");
    bool rv = TTF_DrawSurfaceText(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_FontHasGlyph(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = TTF_FontHasGlyph(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_FontIsFixedWidth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    bool rv = TTF_FontIsFixedWidth(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_FontIsScalable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    bool rv = TTF_FontIsScalable(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_GetFontAscent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    int rv = TTF_GetFontAscent(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetFontDPI(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = TTF_GetFontDPI(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_TTF_GetFontDescent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    int rv = TTF_GetFontDescent(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetFontFamilyName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char * rv = TTF_GetFontFamilyName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_TTF_GetFontGeneration(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    Uint32 rv = TTF_GetFontGeneration(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetFontHeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    int rv = TTF_GetFontHeight(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetFontHinting(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    TTF_HintingFlags rv = TTF_GetFontHinting(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetFontKerning(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    bool rv = TTF_GetFontKerning(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_GetFontLineSkip(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    int rv = TTF_GetFontLineSkip(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetFontOutline(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    int rv = TTF_GetFontOutline(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetFontProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    SDL_PropertiesID rv = TTF_GetFontProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetFontSDF(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    bool rv = TTF_GetFontSDF(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_GetFontSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    float rv = TTF_GetFontSize(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_TTF_GetFontStyle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    TTF_FontStyleFlags rv = TTF_GetFontStyle(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetFontStyleName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char * rv = TTF_GetFontStyleName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_TTF_GetFontWeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    int rv = TTF_GetFontWeight(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetFontWrapAlignment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    TTF_HorizontalAlignment rv = TTF_GetFontWrapAlignment(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetFreeTypeVersion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int io0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    TTF_GetFreeTypeVersion(&io0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_int_value(mrb, (mrb_int)io0);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_TTF_GetGPUTextDrawData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    TTF_GPUAtlasDrawSequence * rv = TTF_GetGPUTextDrawData(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "TTF_GPUAtlasDrawSequence");
    }
}

static mrb_value GenR_TTF_GetGPUTextEngineWinding(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_TextEngine *a0 = (const TTF_TextEngine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_TextEngine");
    TTF_GPUTextEngineWinding rv = TTF_GetGPUTextEngineWinding(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetGlyphImage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    TTF_ImageType io2 = (TTF_ImageType)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Surface * rv = TTF_GetGlyphImage(a0, a1, &io2);
    mrb_value rets[2];
    rets[0] = SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_TTF_GetGlyphImageForIndex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    TTF_ImageType io2 = (TTF_ImageType)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Surface * rv = TTF_GetGlyphImageForIndex(a0, a1, &io2);
    mrb_value rets[2];
    rets[0] = SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_TTF_GetGlyphKerning(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = TTF_GetGlyphKerning(a0, a1, a2, &io3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_TTF_GetGlyphMetrics(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int io4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int io5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    int io6 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = TTF_GetGlyphMetrics(a0, a1, &io2, &io3, &io4, &io5, &io6);
    mrb_value rets[6];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    rets[2] = mrb_int_value(mrb, (mrb_int)io3);
    rets[3] = mrb_int_value(mrb, (mrb_int)io4);
    rets[4] = mrb_int_value(mrb, (mrb_int)io5);
    rets[5] = mrb_int_value(mrb, (mrb_int)io6);
    return mrb_ary_new_from_values(mrb, 6, rets);
    }
}

static mrb_value GenR_TTF_GetHarfBuzzVersion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int io0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    TTF_GetHarfBuzzVersion(&io0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_int_value(mrb, (mrb_int)io0);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_TTF_GetNextTextSubString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    TTF_SubString tmp1;
    const TTF_SubString *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_TTF_SubString(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    TTF_SubString out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = TTF_GetNextTextSubString(a0, a1, &out2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_TTF_SubString(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_TTF_GetNumFontFaces(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    int rv = TTF_GetNumFontFaces(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetPreviousTextSubString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    TTF_SubString tmp1;
    const TTF_SubString *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_TTF_SubString(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    TTF_SubString out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = TTF_GetPreviousTextSubString(a0, a1, &out2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_TTF_SubString(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_TTF_GetStringSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int io4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = TTF_GetStringSize(a0, a1, a2, &io3, &io4);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    rets[2] = mrb_int_value(mrb, (mrb_int)io4);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_TTF_GetStringSizeWrapped(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int io4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int io5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    bool rv = TTF_GetStringSizeWrapped(a0, a1, a2, a3, &io4, &io5);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io4);
    rets[2] = mrb_int_value(mrb, (mrb_int)io5);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_TTF_GetTextColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    Uint8 io1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 io2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 io3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 io4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = TTF_GetTextColor(a0, &io1, &io2, &io3, &io4);
    mrb_value rets[5];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    rets[3] = mrb_int_value(mrb, (mrb_int)io3);
    rets[4] = mrb_int_value(mrb, (mrb_int)io4);
    return mrb_ary_new_from_values(mrb, 5, rets);
    }
}

static mrb_value GenR_TTF_GetTextColorFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = TTF_GetTextColorFloat(a0, &io1, &io2, &io3, &io4);
    mrb_value rets[5];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    rets[3] = mrb_float_value(mrb, (mrb_float)io3);
    rets[4] = mrb_float_value(mrb, (mrb_float)io4);
    return mrb_ary_new_from_values(mrb, 5, rets);
    }
}

static mrb_value GenR_TTF_GetTextEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    TTF_TextEngine * rv = TTF_GetTextEngine(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "TTF_TextEngine");
    }
}

static mrb_value GenR_TTF_GetTextFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    TTF_Font * rv = TTF_GetTextFont(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "TTF_Font");
    }
}

static mrb_value GenR_TTF_GetTextPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = TTF_GetTextPosition(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_TTF_GetTextProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    SDL_PropertiesID rv = TTF_GetTextProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_GetTextSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = TTF_GetTextSize(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_TTF_GetTextSubString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    TTF_SubString out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = TTF_GetTextSubString(a0, a1, &out2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_TTF_SubString(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_TTF_GetTextSubStringForLine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    TTF_SubString out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = TTF_GetTextSubStringForLine(a0, a1, &out2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_TTF_SubString(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_TTF_GetTextSubStringForPoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    TTF_SubString out3;
    memset(&out3, 0, sizeof(out3));
    bool rv = TTF_GetTextSubStringForPoint(a0, a1, a2, &out3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_TTF_SubString(mrb, &out3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_TTF_GetTextWrapWidth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = TTF_GetTextWrapWidth(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_TTF_Init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = TTF_Init();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_InsertTextString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    size_t a3 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = TTF_InsertTextString(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_MeasureString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int io4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    size_t io5 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    bool rv = TTF_MeasureString(a0, a1, a2, a3, &io4, &io5);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io4);
    rets[2] = mrb_int_value(mrb, (mrb_int)io5);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_TTF_OpenFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    TTF_Font * rv = TTF_OpenFont(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "TTF_Font", GenDtor_TTF_CloseFont);
    }
}

static mrb_value GenR_TTF_OpenFontIO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    TTF_Font * rv = TTF_OpenFontIO(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "TTF_Font", GenDtor_TTF_CloseFont);
    }
}

static mrb_value GenR_TTF_OpenFontWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    TTF_Font * rv = TTF_OpenFontWithProperties(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "TTF_Font", GenDtor_TTF_CloseFont);
    }
}

static mrb_value GenR_TTF_Quit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Quit();
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_RemoveFallbackFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    TTF_Font *a1 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "TTF_Font");
    TTF_RemoveFallbackFont(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_RenderGlyph_Blended(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Color a2;
    GenRead_SDL_Color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDL_Surface * rv = TTF_RenderGlyph_Blended(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_RenderGlyph_LCD(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Color a2;
    GenRead_SDL_Color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDL_Color a3;
    GenRead_SDL_Color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    SDL_Surface * rv = TTF_RenderGlyph_LCD(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_RenderGlyph_Shaded(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Color a2;
    GenRead_SDL_Color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDL_Color a3;
    GenRead_SDL_Color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    SDL_Surface * rv = TTF_RenderGlyph_Shaded(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_RenderGlyph_Solid(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Color a2;
    GenRead_SDL_Color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDL_Surface * rv = TTF_RenderGlyph_Solid(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_RenderText_Blended(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Color a3;
    GenRead_SDL_Color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    SDL_Surface * rv = TTF_RenderText_Blended(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_RenderText_Blended_Wrapped(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Color a3;
    GenRead_SDL_Color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_Surface * rv = TTF_RenderText_Blended_Wrapped(a0, a1, a2, a3, a4);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_RenderText_LCD(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Color a3;
    GenRead_SDL_Color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    SDL_Color a4;
    GenRead_SDL_Color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    SDL_Surface * rv = TTF_RenderText_LCD(a0, a1, a2, a3, a4);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_RenderText_LCD_Wrapped(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Color a3;
    GenRead_SDL_Color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    SDL_Color a4;
    GenRead_SDL_Color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    int a5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    SDL_Surface * rv = TTF_RenderText_LCD_Wrapped(a0, a1, a2, a3, a4, a5);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_RenderText_Shaded(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Color a3;
    GenRead_SDL_Color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    SDL_Color a4;
    GenRead_SDL_Color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    SDL_Surface * rv = TTF_RenderText_Shaded(a0, a1, a2, a3, a4);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_RenderText_Shaded_Wrapped(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Color a3;
    GenRead_SDL_Color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    SDL_Color a4;
    GenRead_SDL_Color(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    int a5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    SDL_Surface * rv = TTF_RenderText_Shaded_Wrapped(a0, a1, a2, a3, a4, a5);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_RenderText_Solid(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Color a3;
    GenRead_SDL_Color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    SDL_Surface * rv = TTF_RenderText_Solid(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_RenderText_Solid_Wrapped(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Color a3;
    GenRead_SDL_Color(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_Surface * rv = TTF_RenderText_Solid_Wrapped(a0, a1, a2, a3, a4);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_TTF_SetFontHinting(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    TTF_HintingFlags a1 = (TTF_HintingFlags)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    TTF_SetFontHinting(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_SetFontKerning(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    TTF_SetFontKerning(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_SetFontLanguage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = TTF_SetFontLanguage(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetFontLineSkip(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    TTF_SetFontLineSkip(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_SetFontOutline(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = TTF_SetFontOutline(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetFontSDF(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = TTF_SetFontSDF(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetFontSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = TTF_SetFontSize(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetFontSizeDPI(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = TTF_SetFontSizeDPI(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetFontStyle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    TTF_FontStyleFlags a1 = (TTF_FontStyleFlags)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    TTF_SetFontStyle(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_SetFontWrapAlignment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Font");
    TTF_HorizontalAlignment a1 = (TTF_HorizontalAlignment)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    TTF_SetFontWrapAlignment(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_SetGPUTextEngineWinding(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_TextEngine *a0 = (TTF_TextEngine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_TextEngine");
    TTF_GPUTextEngineWinding a1 = (TTF_GPUTextEngineWinding)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    TTF_SetGPUTextEngineWinding(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_TTF_SetTextColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = TTF_SetTextColor(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetTextColorFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = TTF_SetTextColorFloat(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetTextEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    TTF_TextEngine *a1 = (TTF_TextEngine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "TTF_TextEngine");
    bool rv = TTF_SetTextEngine(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetTextFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    TTF_Font *a1 = (TTF_Font *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "TTF_Font");
    bool rv = TTF_SetTextFont(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetTextPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = TTF_SetTextPosition(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetTextString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = TTF_SetTextString(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetTextWrapWhitespaceVisible(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = TTF_SetTextWrapWhitespaceVisible(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_SetTextWrapWidth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = TTF_SetTextWrapWidth(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_StringToTag(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint32 rv = TTF_StringToTag(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_TextWrapWhitespaceVisible(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    bool rv = TTF_TextWrapWhitespaceVisible(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_UpdateText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "TTF_Text");
    bool rv = TTF_UpdateText(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_TTF_Version(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = TTF_Version();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_TTF_WasInit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = TTF_WasInit();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

void SDLStaticGen_OpenRuby_ttf(mrb_state *mrb);
void SDLStaticGen_OpenRuby_ttf(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "TTF");
    mrb_define_module_function(mrb, mod, "AddFallbackFont", GenR_TTF_AddFallbackFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AppendTextString", GenR_TTF_AppendTextString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ClearFallbackFonts", GenR_TTF_ClearFallbackFonts, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CloseFont", GenR_TTF_CloseFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CopyFont", GenR_TTF_CopyFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPUTextEngine", GenR_TTF_CreateGPUTextEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPUTextEngineWithProperties", GenR_TTF_CreateGPUTextEngineWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateRendererTextEngine", GenR_TTF_CreateRendererTextEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateRendererTextEngineWithProperties", GenR_TTF_CreateRendererTextEngineWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateSurfaceTextEngine", GenR_TTF_CreateSurfaceTextEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateText", GenR_TTF_CreateText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DeleteTextString", GenR_TTF_DeleteTextString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyGPUTextEngine", GenR_TTF_DestroyGPUTextEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyRendererTextEngine", GenR_TTF_DestroyRendererTextEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroySurfaceTextEngine", GenR_TTF_DestroySurfaceTextEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyText", GenR_TTF_DestroyText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DrawRendererText", GenR_TTF_DrawRendererText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DrawSurfaceText", GenR_TTF_DrawSurfaceText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FontHasGlyph", GenR_TTF_FontHasGlyph, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FontIsFixedWidth", GenR_TTF_FontIsFixedWidth, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FontIsScalable", GenR_TTF_FontIsScalable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontAscent", GenR_TTF_GetFontAscent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontDPI", GenR_TTF_GetFontDPI, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontDescent", GenR_TTF_GetFontDescent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontFamilyName", GenR_TTF_GetFontFamilyName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontGeneration", GenR_TTF_GetFontGeneration, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontHeight", GenR_TTF_GetFontHeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontHinting", GenR_TTF_GetFontHinting, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontKerning", GenR_TTF_GetFontKerning, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontLineSkip", GenR_TTF_GetFontLineSkip, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontOutline", GenR_TTF_GetFontOutline, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontProperties", GenR_TTF_GetFontProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontSDF", GenR_TTF_GetFontSDF, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontSize", GenR_TTF_GetFontSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontStyle", GenR_TTF_GetFontStyle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontStyleName", GenR_TTF_GetFontStyleName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontWeight", GenR_TTF_GetFontWeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFontWrapAlignment", GenR_TTF_GetFontWrapAlignment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFreeTypeVersion", GenR_TTF_GetFreeTypeVersion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGPUTextDrawData", GenR_TTF_GetGPUTextDrawData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGPUTextEngineWinding", GenR_TTF_GetGPUTextEngineWinding, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGlyphImage", GenR_TTF_GetGlyphImage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGlyphImageForIndex", GenR_TTF_GetGlyphImageForIndex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGlyphKerning", GenR_TTF_GetGlyphKerning, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGlyphMetrics", GenR_TTF_GetGlyphMetrics, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetHarfBuzzVersion", GenR_TTF_GetHarfBuzzVersion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNextTextSubString", GenR_TTF_GetNextTextSubString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumFontFaces", GenR_TTF_GetNumFontFaces, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPreviousTextSubString", GenR_TTF_GetPreviousTextSubString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetStringSize", GenR_TTF_GetStringSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetStringSizeWrapped", GenR_TTF_GetStringSizeWrapped, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextColor", GenR_TTF_GetTextColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextColorFloat", GenR_TTF_GetTextColorFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextEngine", GenR_TTF_GetTextEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextFont", GenR_TTF_GetTextFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextPosition", GenR_TTF_GetTextPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextProperties", GenR_TTF_GetTextProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextSize", GenR_TTF_GetTextSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextSubString", GenR_TTF_GetTextSubString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextSubStringForLine", GenR_TTF_GetTextSubStringForLine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextSubStringForPoint", GenR_TTF_GetTextSubStringForPoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextWrapWidth", GenR_TTF_GetTextWrapWidth, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Init", GenR_TTF_Init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "InsertTextString", GenR_TTF_InsertTextString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MeasureString", GenR_TTF_MeasureString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenFont", GenR_TTF_OpenFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenFontIO", GenR_TTF_OpenFontIO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenFontWithProperties", GenR_TTF_OpenFontWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Quit", GenR_TTF_Quit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RemoveFallbackFont", GenR_TTF_RemoveFallbackFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderGlyph_Blended", GenR_TTF_RenderGlyph_Blended, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderGlyph_LCD", GenR_TTF_RenderGlyph_LCD, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderGlyph_Shaded", GenR_TTF_RenderGlyph_Shaded, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderGlyph_Solid", GenR_TTF_RenderGlyph_Solid, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderText_Blended", GenR_TTF_RenderText_Blended, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderText_Blended_Wrapped", GenR_TTF_RenderText_Blended_Wrapped, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderText_LCD", GenR_TTF_RenderText_LCD, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderText_LCD_Wrapped", GenR_TTF_RenderText_LCD_Wrapped, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderText_Shaded", GenR_TTF_RenderText_Shaded, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderText_Shaded_Wrapped", GenR_TTF_RenderText_Shaded_Wrapped, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderText_Solid", GenR_TTF_RenderText_Solid, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderText_Solid_Wrapped", GenR_TTF_RenderText_Solid_Wrapped, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetFontHinting", GenR_TTF_SetFontHinting, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetFontKerning", GenR_TTF_SetFontKerning, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetFontLanguage", GenR_TTF_SetFontLanguage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetFontLineSkip", GenR_TTF_SetFontLineSkip, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetFontOutline", GenR_TTF_SetFontOutline, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetFontSDF", GenR_TTF_SetFontSDF, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetFontSize", GenR_TTF_SetFontSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetFontSizeDPI", GenR_TTF_SetFontSizeDPI, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetFontStyle", GenR_TTF_SetFontStyle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetFontWrapAlignment", GenR_TTF_SetFontWrapAlignment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGPUTextEngineWinding", GenR_TTF_SetGPUTextEngineWinding, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextColor", GenR_TTF_SetTextColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextColorFloat", GenR_TTF_SetTextColorFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextEngine", GenR_TTF_SetTextEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextFont", GenR_TTF_SetTextFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextPosition", GenR_TTF_SetTextPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextString", GenR_TTF_SetTextString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextWrapWhitespaceVisible", GenR_TTF_SetTextWrapWhitespaceVisible, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextWrapWidth", GenR_TTF_SetTextWrapWidth, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StringToTag", GenR_TTF_StringToTag, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TextWrapWhitespaceVisible", GenR_TTF_TextWrapWhitespaceVisible, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UpdateText", GenR_TTF_UpdateText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Version", GenR_TTF_Version, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WasInit", GenR_TTF_WasInit, MRB_ARGS_ANY());
    mrb_define_const(mrb, mod, "DIRECTION_INVALID", mrb_int_value(mrb, (mrb_int)TTF_DIRECTION_INVALID));
    mrb_define_const(mrb, mod, "DIRECTION_LTR", mrb_int_value(mrb, (mrb_int)TTF_DIRECTION_LTR));
    mrb_define_const(mrb, mod, "DIRECTION_RTL", mrb_int_value(mrb, (mrb_int)TTF_DIRECTION_RTL));
    mrb_define_const(mrb, mod, "DIRECTION_TTB", mrb_int_value(mrb, (mrb_int)TTF_DIRECTION_TTB));
    mrb_define_const(mrb, mod, "DIRECTION_BTT", mrb_int_value(mrb, (mrb_int)TTF_DIRECTION_BTT));
    mrb_define_const(mrb, mod, "DRAW_COMMAND_NOOP", mrb_int_value(mrb, (mrb_int)TTF_DRAW_COMMAND_NOOP));
    mrb_define_const(mrb, mod, "DRAW_COMMAND_FILL", mrb_int_value(mrb, (mrb_int)TTF_DRAW_COMMAND_FILL));
    mrb_define_const(mrb, mod, "DRAW_COMMAND_COPY", mrb_int_value(mrb, (mrb_int)TTF_DRAW_COMMAND_COPY));
    mrb_define_const(mrb, mod, "GPU_TEXTENGINE_WINDING_INVALID", mrb_int_value(mrb, (mrb_int)TTF_GPU_TEXTENGINE_WINDING_INVALID));
    mrb_define_const(mrb, mod, "GPU_TEXTENGINE_WINDING_CLOCKWISE", mrb_int_value(mrb, (mrb_int)TTF_GPU_TEXTENGINE_WINDING_CLOCKWISE));
    mrb_define_const(mrb, mod, "GPU_TEXTENGINE_WINDING_COUNTER_CLOCKWISE", mrb_int_value(mrb, (mrb_int)TTF_GPU_TEXTENGINE_WINDING_COUNTER_CLOCKWISE));
    mrb_define_const(mrb, mod, "HINTING_INVALID", mrb_int_value(mrb, (mrb_int)TTF_HINTING_INVALID));
    mrb_define_const(mrb, mod, "HINTING_NORMAL", mrb_int_value(mrb, (mrb_int)TTF_HINTING_NORMAL));
    mrb_define_const(mrb, mod, "HINTING_LIGHT", mrb_int_value(mrb, (mrb_int)TTF_HINTING_LIGHT));
    mrb_define_const(mrb, mod, "HINTING_MONO", mrb_int_value(mrb, (mrb_int)TTF_HINTING_MONO));
    mrb_define_const(mrb, mod, "HINTING_NONE", mrb_int_value(mrb, (mrb_int)TTF_HINTING_NONE));
    mrb_define_const(mrb, mod, "HINTING_LIGHT_SUBPIXEL", mrb_int_value(mrb, (mrb_int)TTF_HINTING_LIGHT_SUBPIXEL));
    mrb_define_const(mrb, mod, "HORIZONTAL_ALIGN_INVALID", mrb_int_value(mrb, (mrb_int)TTF_HORIZONTAL_ALIGN_INVALID));
    mrb_define_const(mrb, mod, "HORIZONTAL_ALIGN_LEFT", mrb_int_value(mrb, (mrb_int)TTF_HORIZONTAL_ALIGN_LEFT));
    mrb_define_const(mrb, mod, "HORIZONTAL_ALIGN_CENTER", mrb_int_value(mrb, (mrb_int)TTF_HORIZONTAL_ALIGN_CENTER));
    mrb_define_const(mrb, mod, "HORIZONTAL_ALIGN_RIGHT", mrb_int_value(mrb, (mrb_int)TTF_HORIZONTAL_ALIGN_RIGHT));
    mrb_define_const(mrb, mod, "IMAGE_INVALID", mrb_int_value(mrb, (mrb_int)TTF_IMAGE_INVALID));
    mrb_define_const(mrb, mod, "IMAGE_ALPHA", mrb_int_value(mrb, (mrb_int)TTF_IMAGE_ALPHA));
    mrb_define_const(mrb, mod, "IMAGE_COLOR", mrb_int_value(mrb, (mrb_int)TTF_IMAGE_COLOR));
    mrb_define_const(mrb, mod, "IMAGE_SDF", mrb_int_value(mrb, (mrb_int)TTF_IMAGE_SDF));
}
