/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for SDLStatic modules. */
#include "../src/gen_support_ruby.h"

#include <SDLStatic/base64.h>
#include <SDLStatic/bidi.h>
#include <SDLStatic/chiptune.h>
#include <SDLStatic/compress.h>
#include <SDLStatic/crypto.h>
#include <SDLStatic/debug_text.h>
#include <SDLStatic/dialog.h>
#include <SDLStatic/gpu_primitives.h>
#include <SDLStatic/gui.h>
#include <SDLStatic/gui_grid.h>
#include <SDLStatic/regex.h>
#include <SDLStatic/signals.h>
#include <SDLStatic/textfile.h>
#include <SDLStatic/tiled.h>
#include <SDLStatic/vfs.h>
#include <string.h>

static void GenRead_SDLStatic_ChipToneDesc(mrb_state *mrb, mrb_value h, SDLStatic_ChipToneDesc *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->wave = (SDLStatic_ChipWave)SDLStaticGen_RubyFieldInt(mrb, h, "wave");
    out->freq_hz = (float)SDLStaticGen_RubyFieldNum(mrb, h, "freq_hz");
    out->freq_end_hz = (float)SDLStaticGen_RubyFieldNum(mrb, h, "freq_end_hz");
    out->duration_ms = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "duration_ms");
    out->volume = (float)SDLStaticGen_RubyFieldNum(mrb, h, "volume");
    out->attack_ms = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "attack_ms");
    out->release_ms = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "release_ms");
    out->vibrato_hz = (float)SDLStaticGen_RubyFieldNum(mrb, h, "vibrato_hz");
    out->vibrato_semitones = (float)SDLStaticGen_RubyFieldNum(mrb, h, "vibrato_semitones");
}

static void GenRead_SDL_Color(mrb_state *mrb, mrb_value h, SDL_Color *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->r = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "r");
    out->g = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "g");
    out->b = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "b");
    out->a = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "a");
}

static void GenRead_SDL_FRect(mrb_state *mrb, mrb_value h, SDL_FRect *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "x");
    out->y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "y");
    out->w = (float)SDLStaticGen_RubyFieldNum(mrb, h, "w");
    out->h = (float)SDLStaticGen_RubyFieldNum(mrb, h, "h");
}

static void GenDtor_SDLStatic_FreeTiledMap(void *p)
{
    SDLStatic_TiledMap *typed = (SDLStatic_TiledMap *)p;
    SDLStatic_FreeTiledMap(typed);
}

static void GenDtor_SDLStatic_DestroyGui(void *p)
{
    SDLStatic_Gui *typed = (SDLStatic_Gui *)p;
    SDLStatic_DestroyGui(typed);
}

static void GenDtor_SDLStatic_DestroyRegex(void *p)
{
    SDLStatic_Regex *typed = (SDLStatic_Regex *)p;
    SDLStatic_DestroyRegex(typed);
}

static mrb_value GenR_SDLStatic_BidiBaseIsRTL(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_BidiBaseIsRTL(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_CompileRegex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_Regex * rv = SDLStatic_CompileRegex(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDLStatic_Regex", GenDtor_SDLStatic_DestroyRegex);
    }
}

static mrb_value GenR_SDLStatic_CountSignalConnections(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_SignalEmitter");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_CountSignalConnections(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_CreateChipSFX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    SDLStatic_ChipSFX a1 = (SDLStatic_ChipSFX)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    MIX_Audio * rv = SDLStatic_CreateChipSFX(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Audio");
    }
}

static mrb_value GenR_SDLStatic_CreateChipTone(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    SDLStatic_ChipToneDesc tmp1;
    const SDLStatic_ChipToneDesc *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_ChipToneDesc(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    MIX_Audio * rv = SDLStatic_CreateChipTone(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Audio");
    }
}

static mrb_value GenR_SDLStatic_CreateChipTune(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    MIX_Audio * rv = SDLStatic_CreateChipTune(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Audio");
    }
}

static mrb_value GenR_SDLStatic_CreateGui(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_Gui * rv = SDLStatic_CreateGui(a0, (const void *)a1, (size_t)len1, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDLStatic_Gui", GenDtor_SDLStatic_DestroyGui);
    }
}

static mrb_value GenR_SDLStatic_CreateGuiWithGlyphs(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GuiGlyphRange a4 = (SDLStatic_GuiGlyphRange)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_Gui * rv = SDLStatic_CreateGuiWithGlyphs(a0, (const void *)a1, (size_t)len1, a3, a4);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_Gui");
    }
}

static mrb_value GenR_SDLStatic_CreateSignalEmitter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_SignalEmitter * rv = SDLStatic_CreateSignalEmitter();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_SignalEmitter");
    }
}

static mrb_value GenR_SDLStatic_CryptoSelfTest(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDLStatic_CryptoSelfTest();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_DestroyGui(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_DestroyGui(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DestroyRegex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    SDLStatic_DestroyRegex(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DestroySignalEmitter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_SignalEmitter");
    SDLStatic_DestroySignalEmitter(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DialogDeliverSave(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDLStatic_DialogDeliverSave(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_DialogPath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = SDLStatic_DialogPath();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_DialogReset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_DialogReset();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DialogStatus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_DialogState rv = SDLStatic_DialogStatus();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_DisconnectSignal(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_SignalEmitter");
    Uint64 a1 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_DisconnectSignal(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_EncodeDataBase64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t len0 = 0;
    const char *a0 = SDLStaticGen_RubyToBlob(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &len0);
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char * rv = SDLStatic_EncodeDataBase64((const void *)a0, (int)len0, &io2);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    mrb_value rets[2];
    rets[0] = rstr;
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_FreeTiledMap(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_TiledMap *a0 = (SDLStatic_TiledMap *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    SDLStatic_FreeTiledMap(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiContext(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    struct nk_context * rv = SDLStatic_GuiContext(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_context");
    }
}

static mrb_value GenR_SDLStatic_GuiDrawCommandCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int rv = SDLStatic_GuiDrawCommandCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_GuiDrawTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDL_FRect a2;
    GenRead_SDL_FRect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_GuiImageMode a3 = (SDLStatic_GuiImageMode)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_GuiDrawTexture(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiDrawTextureOverlay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDL_FRect a2;
    GenRead_SDL_FRect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_GuiImageMode a3 = (SDLStatic_GuiImageMode)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_GuiDrawTextureOverlay(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiFontHeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    float rv = SDLStatic_GuiFontHeight(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_GuiGridBeginOwned(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GuiGridBeginOwned(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiGridCell(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GuiGrid");
    SDLStatic_GuiGridCell(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridCellOwned(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiGridCellOwned(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridCellSpan(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GuiGrid");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GuiGridCellSpan(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridCellSpanOwned(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GuiGridCellSpanOwned(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridEnd(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GuiGrid");
    SDLStatic_GuiGridEnd(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridEndOwned(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiGridEndOwned(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridNextRow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GuiGrid");
    SDLStatic_GuiGridNextRow(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridNextRowOwned(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiGridNextRowOwned(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridWeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GuiGridWeight(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiImage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDLStatic_GuiImageMode a2 = (SDLStatic_GuiImageMode)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GuiImage(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiInputBegin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiInputBegin(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiInputEnd(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiInputEnd(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiKeyPressed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GuiKeyPressed(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiMemoryUsed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int rv = SDLStatic_GuiMemoryUsed(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_GuiOpenFileButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_GuiOpenFileButton(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiPopFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GuiPopFont(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiPopStyleColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GuiPopStyleColor(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiProcessEvent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    const SDL_Event *a1 = (const SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Event");
    bool rv = SDLStatic_GuiProcessEvent(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiPumpEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    bool rv = SDLStatic_GuiPumpEvents(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiPushFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiFontSize a1 = (SDLStatic_GuiFontSize)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GuiPushFont(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiPushStyleColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiStyleColor a1 = (SDLStatic_GuiStyleColor)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Color a2;
    GenRead_SDL_Color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    bool rv = SDLStatic_GuiPushStyleColor(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiRender(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    bool rv = SDLStatic_GuiRender(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiSaveFileButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    size_t len3 = 0;
    const char *a3 = SDLStaticGen_RubyToBlob(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &len3);
    bool rv = SDLStatic_GuiSaveFileButton(a0, a1, a2, (const void *)a3, (size_t)len3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiSavedPath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    const char * rv = SDLStatic_GuiSavedPath(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_GuiScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    float rv = SDLStatic_GuiScale(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_GuiSetFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiFontSize a1 = (SDLStatic_GuiFontSize)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GuiSetFont(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiSetTooltipDelay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GuiSetTooltipDelay(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiTooltip(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GuiTooltip(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiTooltipDelay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int rv = SDLStatic_GuiTooltipDelay(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_GuiWantsInput(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    bool rv = SDLStatic_GuiWantsInput(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_HMACSHA256(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t len0 = 0;
    const char *a0 = SDLStaticGen_RubyToBlob(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &len0);
    size_t len2 = 0;
    const char *a2 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len2);
    Uint8 io4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_HMACSHA256((const void *)a0, (size_t)len0, (const void *)a2, (size_t)len2, &io4);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io4);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_LoadTextFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    char * rv = SDLStatic_LoadTextFile(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDLStatic_LoadTiledMap(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_TiledMap * rv = SDLStatic_LoadTiledMap(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDLStatic_TiledMap", GenDtor_SDLStatic_FreeTiledMap);
    }
}

static mrb_value GenR_SDLStatic_MountEncryptedArchive(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t len0 = 0;
    const char *a0 = SDLStaticGen_RubyToBlob(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &len0);
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_MountEncryptedArchive((const void *)a0, (int)len0, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_MountEncryptedArchiveFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_MountEncryptedArchiveFile(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_OpenVFSRead(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_IOStream * rv = SDLStatic_OpenVFSRead(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_IOStream");
    }
}

static mrb_value GenR_SDLStatic_QuitDebugText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_QuitDebugText();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_RegexEscape(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    char * rv = SDLStatic_RegexEscape(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDLStatic_RegexFlags(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char * rv = SDLStatic_RegexFlags(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_RegexGroup(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_RegexGroup(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_RegexGroupBegin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_RegexGroupBegin(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RegexGroupCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int rv = SDLStatic_RegexGroupCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RegexGroupEnd(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_RegexGroupEnd(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RegexMatchAt(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_RegexMatchAt(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_RegexNamedGroup(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_RegexNamedGroup(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RegexNamedGroupCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int rv = SDLStatic_RegexNamedGroupCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RegexNamedGroupName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_RegexNamedGroupName(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_RegexPattern(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char * rv = SDLStatic_RegexPattern(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_RegexReplace(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    const char * rv = SDLStatic_RegexReplace(a0, a1, a2, a3);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_RegexSearch(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_RegexSearch(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_RenderDebugText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_RenderDebugText(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SHA256(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t len0 = 0;
    const char *a0 = SDLStaticGen_RubyToBlob(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &len0);
    Uint8 io2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_SHA256((const void *)a0, (size_t)len0, &io2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_SetDebugTextSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_SetDebugTextSize(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ShowOpenFileDialog(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_ShowOpenFileDialog(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ShowSaveFileDialog(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_ShowSaveFileDialog(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_TiledLayerCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledLayerCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledLayerName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_TiledLayerName(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_TiledLayerType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_TiledLayerType(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_TiledMapHeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledMapHeight(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledMapWidth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledMapWidth(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledObjectAt(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_TiledObject *a3 = (SDLStatic_TiledObject *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), "SDLStatic_TiledObject");
    bool rv = SDLStatic_TiledObjectAt(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_TiledObjectCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_TiledObjectCount(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledRaw(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_TiledMap *a0 = (SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    cute_tiled_map_t * rv = SDLStatic_TiledRaw(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cute_tiled_map_t");
    }
}

static mrb_value GenR_SDLStatic_TiledTileAt(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int rv = SDLStatic_TiledTileAt(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledTileHeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledTileHeight(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledTileWidth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledTileWidth(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

void SDLStaticGen_OpenRuby_sdlstatic(mrb_state *mrb);
void SDLStaticGen_OpenRuby_sdlstatic(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "SDLStaticC");
    mrb_define_module_function(mrb, mod, "BidiBaseIsRTL", GenR_SDLStatic_BidiBaseIsRTL, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CompileRegex", GenR_SDLStatic_CompileRegex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CountSignalConnections", GenR_SDLStatic_CountSignalConnections, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateChipSFX", GenR_SDLStatic_CreateChipSFX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateChipTone", GenR_SDLStatic_CreateChipTone, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateChipTune", GenR_SDLStatic_CreateChipTune, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGui", GenR_SDLStatic_CreateGui, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGuiWithGlyphs", GenR_SDLStatic_CreateGuiWithGlyphs, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateSignalEmitter", GenR_SDLStatic_CreateSignalEmitter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CryptoSelfTest", GenR_SDLStatic_CryptoSelfTest, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyGui", GenR_SDLStatic_DestroyGui, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyRegex", GenR_SDLStatic_DestroyRegex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroySignalEmitter", GenR_SDLStatic_DestroySignalEmitter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DialogDeliverSave", GenR_SDLStatic_DialogDeliverSave, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DialogPath", GenR_SDLStatic_DialogPath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DialogReset", GenR_SDLStatic_DialogReset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DialogStatus", GenR_SDLStatic_DialogStatus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DisconnectSignal", GenR_SDLStatic_DisconnectSignal, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EncodeDataBase64", GenR_SDLStatic_EncodeDataBase64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FreeTiledMap", GenR_SDLStatic_FreeTiledMap, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiContext", GenR_SDLStatic_GuiContext, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiDrawCommandCount", GenR_SDLStatic_GuiDrawCommandCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiDrawTexture", GenR_SDLStatic_GuiDrawTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiDrawTextureOverlay", GenR_SDLStatic_GuiDrawTextureOverlay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiFontHeight", GenR_SDLStatic_GuiFontHeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridBeginOwned", GenR_SDLStatic_GuiGridBeginOwned, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridCell", GenR_SDLStatic_GuiGridCell, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridCellOwned", GenR_SDLStatic_GuiGridCellOwned, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridCellSpan", GenR_SDLStatic_GuiGridCellSpan, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridCellSpanOwned", GenR_SDLStatic_GuiGridCellSpanOwned, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridEnd", GenR_SDLStatic_GuiGridEnd, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridEndOwned", GenR_SDLStatic_GuiGridEndOwned, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridNextRow", GenR_SDLStatic_GuiGridNextRow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridNextRowOwned", GenR_SDLStatic_GuiGridNextRowOwned, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridWeight", GenR_SDLStatic_GuiGridWeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiImage", GenR_SDLStatic_GuiImage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiInputBegin", GenR_SDLStatic_GuiInputBegin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiInputEnd", GenR_SDLStatic_GuiInputEnd, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiKeyPressed", GenR_SDLStatic_GuiKeyPressed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiMemoryUsed", GenR_SDLStatic_GuiMemoryUsed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiOpenFileButton", GenR_SDLStatic_GuiOpenFileButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiPopFont", GenR_SDLStatic_GuiPopFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiPopStyleColor", GenR_SDLStatic_GuiPopStyleColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiProcessEvent", GenR_SDLStatic_GuiProcessEvent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiPumpEvents", GenR_SDLStatic_GuiPumpEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiPushFont", GenR_SDLStatic_GuiPushFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiPushStyleColor", GenR_SDLStatic_GuiPushStyleColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiRender", GenR_SDLStatic_GuiRender, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiSaveFileButton", GenR_SDLStatic_GuiSaveFileButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiSavedPath", GenR_SDLStatic_GuiSavedPath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiScale", GenR_SDLStatic_GuiScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiSetFont", GenR_SDLStatic_GuiSetFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiSetTooltipDelay", GenR_SDLStatic_GuiSetTooltipDelay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiTooltip", GenR_SDLStatic_GuiTooltip, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiTooltipDelay", GenR_SDLStatic_GuiTooltipDelay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiWantsInput", GenR_SDLStatic_GuiWantsInput, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HMACSHA256", GenR_SDLStatic_HMACSHA256, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTextFile", GenR_SDLStatic_LoadTextFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTiledMap", GenR_SDLStatic_LoadTiledMap, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MountEncryptedArchive", GenR_SDLStatic_MountEncryptedArchive, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MountEncryptedArchiveFile", GenR_SDLStatic_MountEncryptedArchiveFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenVFSRead", GenR_SDLStatic_OpenVFSRead, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "QuitDebugText", GenR_SDLStatic_QuitDebugText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexEscape", GenR_SDLStatic_RegexEscape, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexFlags", GenR_SDLStatic_RegexFlags, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexGroup", GenR_SDLStatic_RegexGroup, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexGroupBegin", GenR_SDLStatic_RegexGroupBegin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexGroupCount", GenR_SDLStatic_RegexGroupCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexGroupEnd", GenR_SDLStatic_RegexGroupEnd, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexMatchAt", GenR_SDLStatic_RegexMatchAt, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexNamedGroup", GenR_SDLStatic_RegexNamedGroup, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexNamedGroupCount", GenR_SDLStatic_RegexNamedGroupCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexNamedGroupName", GenR_SDLStatic_RegexNamedGroupName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexPattern", GenR_SDLStatic_RegexPattern, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexReplace", GenR_SDLStatic_RegexReplace, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexSearch", GenR_SDLStatic_RegexSearch, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderDebugText", GenR_SDLStatic_RenderDebugText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SHA256", GenR_SDLStatic_SHA256, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetDebugTextSize", GenR_SDLStatic_SetDebugTextSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShowOpenFileDialog", GenR_SDLStatic_ShowOpenFileDialog, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShowSaveFileDialog", GenR_SDLStatic_ShowSaveFileDialog, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledLayerCount", GenR_SDLStatic_TiledLayerCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledLayerName", GenR_SDLStatic_TiledLayerName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledLayerType", GenR_SDLStatic_TiledLayerType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledMapHeight", GenR_SDLStatic_TiledMapHeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledMapWidth", GenR_SDLStatic_TiledMapWidth, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledObjectAt", GenR_SDLStatic_TiledObjectAt, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledObjectCount", GenR_SDLStatic_TiledObjectCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledRaw", GenR_SDLStatic_TiledRaw, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledTileAt", GenR_SDLStatic_TiledTileAt, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledTileHeight", GenR_SDLStatic_TiledTileHeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledTileWidth", GenR_SDLStatic_TiledTileWidth, MRB_ARGS_ANY());
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_COIN", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_COIN));
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_LASER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_LASER));
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_JUMP", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_JUMP));
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_EXPLOSION", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_EXPLOSION));
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_POWERUP", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_POWERUP));
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_HURT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_HURT));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_SQUARE_125", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_SQUARE_125));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_SQUARE_25", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_SQUARE_25));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_SQUARE_50", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_SQUARE_50));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_TRIANGLE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_TRIANGLE));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_SAW", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_SAW));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_NOISE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_NOISE));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_NOISE_METALLIC", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_NOISE_METALLIC));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_SINE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_SINE));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIALOG_IDLE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIALOG_IDLE));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIALOG_PENDING", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIALOG_PENDING));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIALOG_ACCEPTED", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIALOG_ACCEPTED));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIALOG_CANCELLED", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIALOG_CANCELLED));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIALOG_ERROR", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIALOG_ERROR));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_FONT_SMALL", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_FONT_SMALL));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_FONT_NORMAL", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_FONT_NORMAL));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_FONT_LARGE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_FONT_LARGE));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_GLYPHS_LATIN1", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_GLYPHS_LATIN1));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_GLYPHS_PUNCTUATION", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_GLYPHS_PUNCTUATION));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_GLYPHS_CYRILLIC", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_GLYPHS_CYRILLIC));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_GLYPHS_CHINESE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_GLYPHS_CHINESE));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_GLYPHS_KOREAN", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_GLYPHS_KOREAN));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_IMAGE_STRETCH", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_IMAGE_STRETCH));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_IMAGE_ZOOM", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_IMAGE_ZOOM));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_IMAGE_CENTER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_IMAGE_CENTER));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_IMAGE_FILL", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_IMAGE_FILL));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_WINDOW_BACKGROUND", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_WINDOW_BACKGROUND));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_TEXT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_TEXT));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_BUTTON", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_BUTTON));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_BUTTON_HOVER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_BUTTON_HOVER));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_BUTTON_TEXT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_BUTTON_TEXT));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_HEADER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_HEADER));
}
