/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for SDLStatic modules. */
#include "../src/gen_support_lua.h"

#include <SDLStatic/base64.h>
#include <SDLStatic/bidi.h>
#include <SDLStatic/chiptune.h>
#include <SDLStatic/compress.h>
#include <SDLStatic/crypto.h>
#include <SDLStatic/debug_text.h>
#include <SDLStatic/gpu_primitives.h>
#include <SDLStatic/gui.h>
#include <SDLStatic/gui_grid.h>
#include <SDLStatic/signals.h>
#include <SDLStatic/tiled.h>
#include <SDLStatic/vfs.h>
#include <string.h>

static void GenRead_SDLStatic_ChipToneDesc(lua_State *L, int idx, SDLStatic_ChipToneDesc *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->wave = (SDLStatic_ChipWave)SDLStaticGen_LuaFieldInt(L, idx, "wave");
    out->freq_hz = (float)SDLStaticGen_LuaFieldNum(L, idx, "freq_hz");
    out->freq_end_hz = (float)SDLStaticGen_LuaFieldNum(L, idx, "freq_end_hz");
    out->duration_ms = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "duration_ms");
    out->volume = (float)SDLStaticGen_LuaFieldNum(L, idx, "volume");
    out->attack_ms = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "attack_ms");
    out->release_ms = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "release_ms");
    out->vibrato_hz = (float)SDLStaticGen_LuaFieldNum(L, idx, "vibrato_hz");
    out->vibrato_semitones = (float)SDLStaticGen_LuaFieldNum(L, idx, "vibrato_semitones");
}

static void GenRead_SDL_Color(lua_State *L, int idx, SDL_Color *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->r = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "r");
    out->g = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "g");
    out->b = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "b");
    out->a = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "a");
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

static int GenL_SDLStatic_BidiBaseIsRTL(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_BidiBaseIsRTL(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_CountSignalConnections(lua_State *L)
{
    (void)L;
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_SignalEmitter");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = SDLStatic_CountSignalConnections(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_CreateChipSFX(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    SDLStatic_ChipSFX a1 = (SDLStatic_ChipSFX)luaL_checkinteger(L, 2);
    MIX_Audio * rv = SDLStatic_CreateChipSFX(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Audio");
    return 1;
}

static int GenL_SDLStatic_CreateChipTone(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    SDLStatic_ChipToneDesc tmp1;
    const SDLStatic_ChipToneDesc *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_ChipToneDesc(L, 2, &tmp1);
        a1 = &tmp1;
    }
    MIX_Audio * rv = SDLStatic_CreateChipTone(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Audio");
    return 1;
}

static int GenL_SDLStatic_CreateChipTune(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    MIX_Audio * rv = SDLStatic_CreateChipTune(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Audio");
    return 1;
}

static int GenL_SDLStatic_CreateGui(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    size_t len1 = 0;
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checklstring(L, 2, &len1);
    float a3 = (float)luaL_checknumber(L, 3);
    SDLStatic_Gui * rv = SDLStatic_CreateGui(a0, (const void *)a1, (size_t)len1, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDLStatic_Gui", GenDtor_SDLStatic_DestroyGui);
    return 1;
}

static int GenL_SDLStatic_CreateSignalEmitter(lua_State *L)
{
    (void)L;
    SDLStatic_SignalEmitter * rv = SDLStatic_CreateSignalEmitter();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_SignalEmitter");
    return 1;
}

static int GenL_SDLStatic_CryptoSelfTest(lua_State *L)
{
    (void)L;
    bool rv = SDLStatic_CryptoSelfTest();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_DestroyGui(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaTakeHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_DestroyGui(a0);
    return 0;
}

static int GenL_SDLStatic_DestroySignalEmitter(lua_State *L)
{
    (void)L;
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_SignalEmitter");
    SDLStatic_DestroySignalEmitter(a0);
    return 0;
}

static int GenL_SDLStatic_DisconnectSignal(lua_State *L)
{
    (void)L;
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_SignalEmitter");
    Uint64 a1 = (Uint64)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_DisconnectSignal(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_EncodeDataBase64(lua_State *L)
{
    (void)L;
    size_t len0 = 0;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checklstring(L, 1, &len0);
    int io2 = (int)luaL_optinteger(L, 2, 0);
    char * rv = SDLStatic_EncodeDataBase64((const void *)a0, (int)len0, &io2);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_SDLStatic_FreeTiledMap(lua_State *L)
{
    (void)L;
    SDLStatic_TiledMap *a0 = (SDLStatic_TiledMap *)SDLStaticGen_LuaTakeHandle(L, 1, "SDLStatic_TiledMap");
    SDLStatic_FreeTiledMap(a0);
    return 0;
}

static int GenL_SDLStatic_GuiContext(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    struct nk_context * rv = SDLStatic_GuiContext(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_context");
    return 1;
}

static int GenL_SDLStatic_GuiFontHeight(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    float rv = SDLStatic_GuiFontHeight(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_GuiGridCell(lua_State *L)
{
    (void)L;
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_GuiGrid");
    SDLStatic_GuiGridCell(a0);
    return 0;
}

static int GenL_SDLStatic_GuiGridCellSpan(lua_State *L)
{
    (void)L;
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_GuiGrid");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GuiGridCellSpan(a0, a1);
    return 0;
}

static int GenL_SDLStatic_GuiGridEnd(lua_State *L)
{
    (void)L;
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_GuiGrid");
    SDLStatic_GuiGridEnd(a0);
    return 0;
}

static int GenL_SDLStatic_GuiGridNextRow(lua_State *L)
{
    (void)L;
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_GuiGrid");
    SDLStatic_GuiGridNextRow(a0);
    return 0;
}

static int GenL_SDLStatic_GuiInputBegin(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiInputBegin(a0);
    return 0;
}

static int GenL_SDLStatic_GuiInputEnd(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiInputEnd(a0);
    return 0;
}

static int GenL_SDLStatic_GuiKeyPressed(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_GuiKeyPressed(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiPopFont(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GuiPopFont(a0, a1);
    return 0;
}

static int GenL_SDLStatic_GuiPopStyleColor(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GuiPopStyleColor(a0, a1);
    return 0;
}

static int GenL_SDLStatic_GuiProcessEvent(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    const SDL_Event *a1 = (const SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Event");
    bool rv = SDLStatic_GuiProcessEvent(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiPumpEvents(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    bool rv = SDLStatic_GuiPumpEvents(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiPushFont(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiFontSize a1 = (SDLStatic_GuiFontSize)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_GuiPushFont(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiPushStyleColor(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiStyleColor a1 = (SDLStatic_GuiStyleColor)luaL_checkinteger(L, 2);
    SDL_Color a2;
    GenRead_SDL_Color(L, 3, &a2);
    bool rv = SDLStatic_GuiPushStyleColor(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiRender(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    bool rv = SDLStatic_GuiRender(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiScale(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    float rv = SDLStatic_GuiScale(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_GuiSetFont(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiFontSize a1 = (SDLStatic_GuiFontSize)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_GuiSetFont(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiWantsInput(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    bool rv = SDLStatic_GuiWantsInput(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_HMACSHA256(lua_State *L)
{
    (void)L;
    size_t len0 = 0;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checklstring(L, 1, &len0);
    size_t len2 = 0;
    const char *a2 = lua_isnoneornil(L, 2) ? NULL : luaL_checklstring(L, 2, &len2);
    Uint8 io4 = (Uint8)luaL_optinteger(L, 3, 0);
    bool rv = SDLStatic_HMACSHA256((const void *)a0, (size_t)len0, (const void *)a2, (size_t)len2, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io4);
    return 2;
}

static int GenL_SDLStatic_LoadTiledMap(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDLStatic_TiledMap * rv = SDLStatic_LoadTiledMap(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDLStatic_TiledMap", GenDtor_SDLStatic_FreeTiledMap);
    return 1;
}

static int GenL_SDLStatic_MountEncryptedArchive(lua_State *L)
{
    (void)L;
    size_t len0 = 0;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checklstring(L, 1, &len0);
    const char *a2 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a3 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDLStatic_MountEncryptedArchive((const void *)a0, (int)len0, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_MountEncryptedArchiveFile(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDLStatic_MountEncryptedArchiveFile(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_OpenVFSRead(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_IOStream * rv = SDLStatic_OpenVFSRead(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_IOStream");
    return 1;
}

static int GenL_SDLStatic_QuitDebugText(lua_State *L)
{
    (void)L;
    SDLStatic_QuitDebugText();
    return 0;
}

static int GenL_SDLStatic_RenderDebugText(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = SDLStatic_RenderDebugText(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SHA256(lua_State *L)
{
    (void)L;
    size_t len0 = 0;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checklstring(L, 1, &len0);
    Uint8 io2 = (Uint8)luaL_optinteger(L, 2, 0);
    bool rv = SDLStatic_SHA256((const void *)a0, (size_t)len0, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_SDLStatic_SetDebugTextSize(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    SDLStatic_SetDebugTextSize(a0);
    return 0;
}

static int GenL_SDLStatic_TiledLayerCount(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledLayerCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledLayerName(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char * rv = SDLStatic_TiledLayerName(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_TiledLayerType(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char * rv = SDLStatic_TiledLayerType(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_TiledMapHeight(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledMapHeight(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledMapWidth(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledMapWidth(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledObjectAt(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDLStatic_TiledObject *a3 = (SDLStatic_TiledObject *)SDLStaticGen_LuaCheckHandle(L, 4, "SDLStatic_TiledObject");
    bool rv = SDLStatic_TiledObjectAt(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_TiledObjectCount(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    int rv = SDLStatic_TiledObjectCount(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledRaw(lua_State *L)
{
    (void)L;
    SDLStatic_TiledMap *a0 = (SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    cute_tiled_map_t * rv = SDLStatic_TiledRaw(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cute_tiled_map_t");
    return 1;
}

static int GenL_SDLStatic_TiledTileAt(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int rv = SDLStatic_TiledTileAt(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledTileHeight(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledTileHeight(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledTileWidth(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledTileWidth(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

int SDLStaticGen_OpenLua_sdlstatic(lua_State *L);
int SDLStaticGen_OpenLua_sdlstatic(lua_State *L)
{
    lua_createtable(L, 0, 52);
    lua_pushcfunction(L, GenL_SDLStatic_BidiBaseIsRTL);
    lua_setfield(L, -2, "BidiBaseIsRTL");
    lua_pushcfunction(L, GenL_SDLStatic_CountSignalConnections);
    lua_setfield(L, -2, "CountSignalConnections");
    lua_pushcfunction(L, GenL_SDLStatic_CreateChipSFX);
    lua_setfield(L, -2, "CreateChipSFX");
    lua_pushcfunction(L, GenL_SDLStatic_CreateChipTone);
    lua_setfield(L, -2, "CreateChipTone");
    lua_pushcfunction(L, GenL_SDLStatic_CreateChipTune);
    lua_setfield(L, -2, "CreateChipTune");
    lua_pushcfunction(L, GenL_SDLStatic_CreateGui);
    lua_setfield(L, -2, "CreateGui");
    lua_pushcfunction(L, GenL_SDLStatic_CreateSignalEmitter);
    lua_setfield(L, -2, "CreateSignalEmitter");
    lua_pushcfunction(L, GenL_SDLStatic_CryptoSelfTest);
    lua_setfield(L, -2, "CryptoSelfTest");
    lua_pushcfunction(L, GenL_SDLStatic_DestroyGui);
    lua_setfield(L, -2, "DestroyGui");
    lua_pushcfunction(L, GenL_SDLStatic_DestroySignalEmitter);
    lua_setfield(L, -2, "DestroySignalEmitter");
    lua_pushcfunction(L, GenL_SDLStatic_DisconnectSignal);
    lua_setfield(L, -2, "DisconnectSignal");
    lua_pushcfunction(L, GenL_SDLStatic_EncodeDataBase64);
    lua_setfield(L, -2, "EncodeDataBase64");
    lua_pushcfunction(L, GenL_SDLStatic_FreeTiledMap);
    lua_setfield(L, -2, "FreeTiledMap");
    lua_pushcfunction(L, GenL_SDLStatic_GuiContext);
    lua_setfield(L, -2, "GuiContext");
    lua_pushcfunction(L, GenL_SDLStatic_GuiFontHeight);
    lua_setfield(L, -2, "GuiFontHeight");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridCell);
    lua_setfield(L, -2, "GuiGridCell");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridCellSpan);
    lua_setfield(L, -2, "GuiGridCellSpan");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridEnd);
    lua_setfield(L, -2, "GuiGridEnd");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridNextRow);
    lua_setfield(L, -2, "GuiGridNextRow");
    lua_pushcfunction(L, GenL_SDLStatic_GuiInputBegin);
    lua_setfield(L, -2, "GuiInputBegin");
    lua_pushcfunction(L, GenL_SDLStatic_GuiInputEnd);
    lua_setfield(L, -2, "GuiInputEnd");
    lua_pushcfunction(L, GenL_SDLStatic_GuiKeyPressed);
    lua_setfield(L, -2, "GuiKeyPressed");
    lua_pushcfunction(L, GenL_SDLStatic_GuiPopFont);
    lua_setfield(L, -2, "GuiPopFont");
    lua_pushcfunction(L, GenL_SDLStatic_GuiPopStyleColor);
    lua_setfield(L, -2, "GuiPopStyleColor");
    lua_pushcfunction(L, GenL_SDLStatic_GuiProcessEvent);
    lua_setfield(L, -2, "GuiProcessEvent");
    lua_pushcfunction(L, GenL_SDLStatic_GuiPumpEvents);
    lua_setfield(L, -2, "GuiPumpEvents");
    lua_pushcfunction(L, GenL_SDLStatic_GuiPushFont);
    lua_setfield(L, -2, "GuiPushFont");
    lua_pushcfunction(L, GenL_SDLStatic_GuiPushStyleColor);
    lua_setfield(L, -2, "GuiPushStyleColor");
    lua_pushcfunction(L, GenL_SDLStatic_GuiRender);
    lua_setfield(L, -2, "GuiRender");
    lua_pushcfunction(L, GenL_SDLStatic_GuiScale);
    lua_setfield(L, -2, "GuiScale");
    lua_pushcfunction(L, GenL_SDLStatic_GuiSetFont);
    lua_setfield(L, -2, "GuiSetFont");
    lua_pushcfunction(L, GenL_SDLStatic_GuiWantsInput);
    lua_setfield(L, -2, "GuiWantsInput");
    lua_pushcfunction(L, GenL_SDLStatic_HMACSHA256);
    lua_setfield(L, -2, "HMACSHA256");
    lua_pushcfunction(L, GenL_SDLStatic_LoadTiledMap);
    lua_setfield(L, -2, "LoadTiledMap");
    lua_pushcfunction(L, GenL_SDLStatic_MountEncryptedArchive);
    lua_setfield(L, -2, "MountEncryptedArchive");
    lua_pushcfunction(L, GenL_SDLStatic_MountEncryptedArchiveFile);
    lua_setfield(L, -2, "MountEncryptedArchiveFile");
    lua_pushcfunction(L, GenL_SDLStatic_OpenVFSRead);
    lua_setfield(L, -2, "OpenVFSRead");
    lua_pushcfunction(L, GenL_SDLStatic_QuitDebugText);
    lua_setfield(L, -2, "QuitDebugText");
    lua_pushcfunction(L, GenL_SDLStatic_RenderDebugText);
    lua_setfield(L, -2, "RenderDebugText");
    lua_pushcfunction(L, GenL_SDLStatic_SHA256);
    lua_setfield(L, -2, "SHA256");
    lua_pushcfunction(L, GenL_SDLStatic_SetDebugTextSize);
    lua_setfield(L, -2, "SetDebugTextSize");
    lua_pushcfunction(L, GenL_SDLStatic_TiledLayerCount);
    lua_setfield(L, -2, "TiledLayerCount");
    lua_pushcfunction(L, GenL_SDLStatic_TiledLayerName);
    lua_setfield(L, -2, "TiledLayerName");
    lua_pushcfunction(L, GenL_SDLStatic_TiledLayerType);
    lua_setfield(L, -2, "TiledLayerType");
    lua_pushcfunction(L, GenL_SDLStatic_TiledMapHeight);
    lua_setfield(L, -2, "TiledMapHeight");
    lua_pushcfunction(L, GenL_SDLStatic_TiledMapWidth);
    lua_setfield(L, -2, "TiledMapWidth");
    lua_pushcfunction(L, GenL_SDLStatic_TiledObjectAt);
    lua_setfield(L, -2, "TiledObjectAt");
    lua_pushcfunction(L, GenL_SDLStatic_TiledObjectCount);
    lua_setfield(L, -2, "TiledObjectCount");
    lua_pushcfunction(L, GenL_SDLStatic_TiledRaw);
    lua_setfield(L, -2, "TiledRaw");
    lua_pushcfunction(L, GenL_SDLStatic_TiledTileAt);
    lua_setfield(L, -2, "TiledTileAt");
    lua_pushcfunction(L, GenL_SDLStatic_TiledTileHeight);
    lua_setfield(L, -2, "TiledTileHeight");
    lua_pushcfunction(L, GenL_SDLStatic_TiledTileWidth);
    lua_setfield(L, -2, "TiledTileWidth");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_COIN);
    lua_setfield(L, -2, "SDLSTATIC_SFX_COIN");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_LASER);
    lua_setfield(L, -2, "SDLSTATIC_SFX_LASER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_JUMP);
    lua_setfield(L, -2, "SDLSTATIC_SFX_JUMP");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_EXPLOSION);
    lua_setfield(L, -2, "SDLSTATIC_SFX_EXPLOSION");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_POWERUP);
    lua_setfield(L, -2, "SDLSTATIC_SFX_POWERUP");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_HURT);
    lua_setfield(L, -2, "SDLSTATIC_SFX_HURT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_SQUARE_125);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_SQUARE_125");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_SQUARE_25);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_SQUARE_25");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_SQUARE_50);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_SQUARE_50");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_TRIANGLE);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_TRIANGLE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_SAW);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_SAW");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_NOISE);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_NOISE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_NOISE_METALLIC);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_NOISE_METALLIC");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_SINE);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_SINE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_FONT_SMALL);
    lua_setfield(L, -2, "SDLSTATIC_GUI_FONT_SMALL");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_FONT_NORMAL);
    lua_setfield(L, -2, "SDLSTATIC_GUI_FONT_NORMAL");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_FONT_LARGE);
    lua_setfield(L, -2, "SDLSTATIC_GUI_FONT_LARGE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_WINDOW_BACKGROUND);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_WINDOW_BACKGROUND");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_TEXT);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_TEXT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_BUTTON);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_BUTTON");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_BUTTON_HOVER);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_BUTTON_HOVER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_BUTTON_TEXT);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_BUTTON_TEXT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_HEADER);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_HEADER");
    lua_setglobal(L, "SDLStaticC");
    return 0;
}
