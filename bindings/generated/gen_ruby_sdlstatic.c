/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for SDLStatic modules. */
#include "../src/gen_support_ruby.h"

#include <SDLStatic/base64.h>
#include <SDLStatic/chiptune.h>
#include <SDLStatic/compress.h>
#include <SDLStatic/crypto.h>
#include <SDLStatic/gpu_primitives.h>
#include <SDLStatic/gui_grid.h>
#include <SDLStatic/signals.h>
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

static void GenDtor_SDLStatic_FreeTiledMap(void *p)
{
    SDLStatic_TiledMap *typed = (SDLStatic_TiledMap *)p;
    SDLStatic_FreeTiledMap(typed);
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
    mrb_define_module_function(mrb, mod, "CountSignalConnections", GenR_SDLStatic_CountSignalConnections, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateChipSFX", GenR_SDLStatic_CreateChipSFX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateChipTone", GenR_SDLStatic_CreateChipTone, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateChipTune", GenR_SDLStatic_CreateChipTune, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateSignalEmitter", GenR_SDLStatic_CreateSignalEmitter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CryptoSelfTest", GenR_SDLStatic_CryptoSelfTest, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroySignalEmitter", GenR_SDLStatic_DestroySignalEmitter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DisconnectSignal", GenR_SDLStatic_DisconnectSignal, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FreeTiledMap", GenR_SDLStatic_FreeTiledMap, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridCell", GenR_SDLStatic_GuiGridCell, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridCellSpan", GenR_SDLStatic_GuiGridCellSpan, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridEnd", GenR_SDLStatic_GuiGridEnd, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridNextRow", GenR_SDLStatic_GuiGridNextRow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HMACSHA256", GenR_SDLStatic_HMACSHA256, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTiledMap", GenR_SDLStatic_LoadTiledMap, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MountEncryptedArchiveFile", GenR_SDLStatic_MountEncryptedArchiveFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenVFSRead", GenR_SDLStatic_OpenVFSRead, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SHA256", GenR_SDLStatic_SHA256, MRB_ARGS_ANY());
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
}
