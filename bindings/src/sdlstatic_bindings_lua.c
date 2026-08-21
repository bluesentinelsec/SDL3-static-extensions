/*
 * sdlstatic_bindings_lua.c — Lua bindings for the SDLStatic game surface.
 *
 * Original SDLStatic code (zlib). Every handle is an opaque full userdata
 * with a metatable whose __gc finalizer releases the native object; child
 * handles (textures, sounds, tracks) pin their parent through a uservalue
 * so collection order is always safe.
 */
#include "bindings_core.h"

#include <SDLStatic/base64.h>
#include <SDLStatic/bindings.h>
#include <SDLStatic/compress.h>
#include <SDLStatic/crypto.h>
#include <SDLStatic/tiled.h>
#include <SDLStatic/vfs.h>
#include <physfs.h>

#include <lauxlib.h>
#include <lualib.h>

#define APP_MT "SDLStatic.App"
#define TEX_MT "SDLStatic.Texture"
#define AUDIO_MT "SDLStatic.Audio"
#define SOUND_MT "SDLStatic.Sound"
#define TRACK_MT "SDLStatic.Track"
#define WORLD_MT "SDLStatic.World"
#define MAP_MT "SDLStatic.TiledMap"
#define BODY_MT "SDLStatic.Body"

/* Generic opaque-handle helpers: userdata holds a single pointer. */
static void *CheckHandle(lua_State *L, int idx, const char *mt)
{
    void **slot = (void **)luaL_checkudata(L, idx, mt);
    if (*slot == NULL)
    {
        luaL_error(L, "%s: handle already destroyed", mt);
    }
    return *slot;
}

static void PushHandle(lua_State *L, void *ptr, const char *mt, int parent_idx)
{
    void **slot = (void **)lua_newuserdatauv(L, sizeof(void *), 1);
    *slot = ptr;
    luaL_setmetatable(L, mt);
    if (parent_idx != 0)
    {
        lua_pushvalue(L, parent_idx);
        lua_setiuservalue(L, -2, 1); /* pin the parent for GC ordering */
    }
}

static int Fail(lua_State *L)
{
    return luaL_error(L, "%s", SDL_GetError());
}

/* ------------------------------------------------------------- app ------ */

static int LWindow(lua_State *L)
{
    const char *title = luaL_checkstring(L, 1);
    const int w = (int)luaL_checkinteger(L, 2);
    const int h = (int)luaL_checkinteger(L, 3);
    BindApp *app = BindApp_Create(title, w, h);
    if (app == NULL)
    {
        return Fail(L);
    }
    PushHandle(L, app, APP_MT, 0);
    return 1;
}

static int LAppGc(lua_State *L)
{
    void **slot = (void **)luaL_checkudata(L, 1, APP_MT);
    BindApp_Destroy((BindApp *)*slot);
    *slot = NULL;
    return 0;
}

static int LAppClear(lua_State *L)
{
    BindApp *app = (BindApp *)CheckHandle(L, 1, APP_MT);
    if (!BindApp_Clear(app, (Uint8)luaL_checkinteger(L, 2), (Uint8)luaL_checkinteger(L, 3),
                       (Uint8)luaL_checkinteger(L, 4)))
    {
        return Fail(L);
    }
    return 0;
}

static int LAppPresent(lua_State *L)
{
    BindApp *app = (BindApp *)CheckHandle(L, 1, APP_MT);
    BindApp_Present(app);
    return 0;
}

static int LAppPoll(lua_State *L)
{
    (void)CheckHandle(L, 1, APP_MT);
    BindEvent event;
    if (!BindApp_PollEvent(&event))
    {
        lua_pushnil(L);
        return 1;
    }
    lua_newtable(L);
    lua_pushstring(L, event.type);
    lua_setfield(L, -2, "type");
    if (SDL_strcmp(event.type, "key") == 0)
    {
        lua_pushstring(L, event.key);
        lua_setfield(L, -2, "key");
        lua_pushboolean(L, event.down);
        lua_setfield(L, -2, "down");
    }
    else if (SDL_strcmp(event.type, "quit") != 0)
    {
        lua_pushnumber(L, event.x);
        lua_setfield(L, -2, "x");
        lua_pushnumber(L, event.y);
        lua_setfield(L, -2, "y");
        if (SDL_strcmp(event.type, "mouse") == 0)
        {
            lua_pushinteger(L, event.button);
            lua_setfield(L, -2, "button");
            lua_pushboolean(L, event.down);
            lua_setfield(L, -2, "down");
        }
    }
    return 1;
}

static int LAppRect(lua_State *L)
{
    BindApp *app = (BindApp *)CheckHandle(L, 1, APP_MT);
    if (!BindApp_Rect(app, (float)luaL_checknumber(L, 2), (float)luaL_checknumber(L, 3),
                      (float)luaL_checknumber(L, 4), (float)luaL_checknumber(L, 5),
                      (Uint8)luaL_checkinteger(L, 6), (Uint8)luaL_checkinteger(L, 7),
                      (Uint8)luaL_checkinteger(L, 8), (Uint8)luaL_optinteger(L, 9, 255)))
    {
        return Fail(L);
    }
    return 0;
}

static int LAppCircle(lua_State *L)
{
    BindApp *app = (BindApp *)CheckHandle(L, 1, APP_MT);
    if (!BindApp_Circle(app, (float)luaL_checknumber(L, 2), (float)luaL_checknumber(L, 3),
                        (float)luaL_checknumber(L, 4), (Uint8)luaL_checkinteger(L, 5),
                        (Uint8)luaL_checkinteger(L, 6), (Uint8)luaL_checkinteger(L, 7),
                        (Uint8)luaL_optinteger(L, 8, 255)))
    {
        return Fail(L);
    }
    return 0;
}

static int LAppLine(lua_State *L)
{
    BindApp *app = (BindApp *)CheckHandle(L, 1, APP_MT);
    if (!BindApp_Line(app, (float)luaL_checknumber(L, 2), (float)luaL_checknumber(L, 3),
                      (float)luaL_checknumber(L, 4), (float)luaL_checknumber(L, 5),
                      (Uint8)luaL_checkinteger(L, 6), (Uint8)luaL_checkinteger(L, 7),
                      (Uint8)luaL_checkinteger(L, 8), (Uint8)luaL_optinteger(L, 9, 255)))
    {
        return Fail(L);
    }
    return 0;
}

static int LAppText(lua_State *L)
{
    BindApp *app = (BindApp *)CheckHandle(L, 1, APP_MT);
    BindApp_Text(app, (float)luaL_checknumber(L, 2), (float)luaL_checknumber(L, 3),
                 luaL_checkstring(L, 4), (Uint8)luaL_optinteger(L, 5, 255),
                 (Uint8)luaL_optinteger(L, 6, 255), (Uint8)luaL_optinteger(L, 7, 255));
    return 0;
}

static int LAppKeyDown(lua_State *L)
{
    (void)CheckHandle(L, 1, APP_MT);
    lua_pushboolean(L, BindApp_KeyDown(luaL_checkstring(L, 2)));
    return 1;
}

static int LAppLoadTexture(lua_State *L)
{
    BindApp *app = (BindApp *)CheckHandle(L, 1, APP_MT);
    BindTexture *tex = BindApp_LoadTexture(app, luaL_checkstring(L, 2));
    if (tex == NULL)
    {
        return Fail(L);
    }
    PushHandle(L, tex, TEX_MT, 1);
    return 1;
}

static int LAppDraw(lua_State *L)
{
    BindApp *app = (BindApp *)CheckHandle(L, 1, APP_MT);
    BindTexture *tex = (BindTexture *)CheckHandle(L, 2, TEX_MT);
    BindApp_Draw(app, tex, (float)luaL_checknumber(L, 3), (float)luaL_checknumber(L, 4),
                 (float)luaL_optnumber(L, 5, 0), (float)luaL_optnumber(L, 6, 0),
                 luaL_optnumber(L, 7, 0));
    return 0;
}

static int LTexGc(lua_State *L)
{
    void **slot = (void **)luaL_checkudata(L, 1, TEX_MT);
    BindTexture_Destroy((BindTexture *)*slot);
    *slot = NULL;
    return 0;
}

static int LTexSize(lua_State *L)
{
    BindTexture *tex = (BindTexture *)CheckHandle(L, 1, TEX_MT);
    lua_pushnumber(L, tex->w);
    lua_pushnumber(L, tex->h);
    return 2;
}

/* ------------------------------------------------------------ audio ----- */

static int LOpenAudio(lua_State *L)
{
    BindAudio *audio = BindAudio_Open();
    if (audio == NULL)
    {
        return Fail(L);
    }
    PushHandle(L, audio, AUDIO_MT, 0);
    return 1;
}

static int LAudioGc(lua_State *L)
{
    void **slot = (void **)luaL_checkudata(L, 1, AUDIO_MT);
    BindAudio_Destroy((BindAudio *)*slot);
    *slot = NULL;
    return 0;
}

static int LAudioLoad(lua_State *L)
{
    BindAudio *audio = (BindAudio *)CheckHandle(L, 1, AUDIO_MT);
    BindSound *sound = BindAudio_Load(audio, luaL_checkstring(L, 2));
    if (sound == NULL)
    {
        return Fail(L);
    }
    PushHandle(L, sound, SOUND_MT, 1);
    return 1;
}

static int LSoundGc(lua_State *L)
{
    void **slot = (void **)luaL_checkudata(L, 1, SOUND_MT);
    BindSound_Destroy((BindSound *)*slot);
    *slot = NULL;
    return 0;
}

static int LAudioPlay(lua_State *L)
{
    BindAudio *audio = (BindAudio *)CheckHandle(L, 1, AUDIO_MT);
    BindSound *sound = (BindSound *)CheckHandle(L, 2, SOUND_MT);
    BindTrack *track = BindAudio_Play(audio, sound, (int)luaL_optinteger(L, 3, 0));
    if (track == NULL)
    {
        return Fail(L);
    }
    PushHandle(L, track, TRACK_MT, 1);
    return 1;
}

static int LTrackGc(lua_State *L)
{
    void **slot = (void **)luaL_checkudata(L, 1, TRACK_MT);
    BindTrack_Destroy((BindTrack *)*slot);
    *slot = NULL;
    return 0;
}

static int LTrackStop(lua_State *L)
{
    BindTrack_Stop((BindTrack *)CheckHandle(L, 1, TRACK_MT));
    return 0;
}

static int LTrackGain(lua_State *L)
{
    BindTrack_SetGain((BindTrack *)CheckHandle(L, 1, TRACK_MT), (float)luaL_checknumber(L, 2));
    return 0;
}

/* ---------------------------------------------------------- physics ----- */

static int LWorld(lua_State *L)
{
    BindWorld *world =
        BindWorld_Create((float)luaL_optnumber(L, 1, 0), (float)luaL_optnumber(L, 2, -10));
    if (world == NULL)
    {
        return Fail(L);
    }
    PushHandle(L, world, WORLD_MT, 0);
    return 1;
}

static int LWorldGc(lua_State *L)
{
    void **slot = (void **)luaL_checkudata(L, 1, WORLD_MT);
    BindWorld_Destroy((BindWorld *)*slot);
    *slot = NULL;
    return 0;
}

static int LWorldStep(lua_State *L)
{
    BindWorld *world = (BindWorld *)CheckHandle(L, 1, WORLD_MT);
    if (!BindWorld_Step(world, (float)luaL_optnumber(L, 2, 1.0 / 60.0)))
    {
        return Fail(L);
    }
    return 0;
}

static int LWorldBox(lua_State *L)
{
    BindWorld *world = (BindWorld *)CheckHandle(L, 1, WORLD_MT);
    BindBody *body = BindWorld_AddBox(world, (float)luaL_checknumber(L, 2),
                                      (float)luaL_checknumber(L, 3), (float)luaL_checknumber(L, 4),
                                      (float)luaL_checknumber(L, 5), lua_toboolean(L, 6));
    if (body == NULL)
    {
        return Fail(L);
    }
    PushHandle(L, body, BODY_MT, 1);
    return 1;
}

static int LWorldCircle(lua_State *L)
{
    BindWorld *world = (BindWorld *)CheckHandle(L, 1, WORLD_MT);
    BindBody *body =
        BindWorld_AddCircle(world, (float)luaL_checknumber(L, 2), (float)luaL_checknumber(L, 3),
                            (float)luaL_checknumber(L, 4), lua_toboolean(L, 5));
    if (body == NULL)
    {
        return Fail(L);
    }
    PushHandle(L, body, BODY_MT, 1);
    return 1;
}

static int LBodyGc(lua_State *L)
{
    void **slot = (void **)luaL_checkudata(L, 1, BODY_MT);
    BindBody_DestroyWrapper((BindBody *)*slot);
    *slot = NULL;
    return 0;
}

static int LBodyPosition(lua_State *L)
{
    BindBody *body = (BindBody *)CheckHandle(L, 1, BODY_MT);
    float x = 0;
    float y = 0;
    if (!BindBody_Position(body, &x, &y))
    {
        return Fail(L);
    }
    lua_pushnumber(L, x);
    lua_pushnumber(L, y);
    return 2;
}

static int LBodyAngle(lua_State *L)
{
    lua_pushnumber(L, BindBody_Angle((BindBody *)CheckHandle(L, 1, BODY_MT)));
    return 1;
}

static int LBodyVelocity(lua_State *L)
{
    BindBody *body = (BindBody *)CheckHandle(L, 1, BODY_MT);
    if (!BindBody_SetVelocity(body, (float)luaL_checknumber(L, 2), (float)luaL_checknumber(L, 3)))
    {
        return Fail(L);
    }
    return 0;
}

static int LBodyImpulse(lua_State *L)
{
    BindBody *body = (BindBody *)CheckHandle(L, 1, BODY_MT);
    if (!BindBody_ApplyImpulse(body, (float)luaL_checknumber(L, 2), (float)luaL_checknumber(L, 3)))
    {
        return Fail(L);
    }
    return 0;
}

/* ------------------------------------------------------------- tiled ---- */

static int LLoadMap(lua_State *L)
{
    SDLStatic_TiledMap *map = SDLStatic_LoadTiledMap(luaL_checkstring(L, 1));
    if (map == NULL)
    {
        return Fail(L);
    }
    PushHandle(L, map, MAP_MT, 0);
    return 1;
}

static int LMapGc(lua_State *L)
{
    void **slot = (void **)luaL_checkudata(L, 1, MAP_MT);
    SDLStatic_FreeTiledMap((SDLStatic_TiledMap *)*slot);
    *slot = NULL;
    return 0;
}

static int LMapSize(lua_State *L)
{
    SDLStatic_TiledMap *map = (SDLStatic_TiledMap *)CheckHandle(L, 1, MAP_MT);
    lua_pushinteger(L, SDLStatic_TiledMapWidth(map));
    lua_pushinteger(L, SDLStatic_TiledMapHeight(map));
    lua_pushinteger(L, SDLStatic_TiledTileWidth(map));
    lua_pushinteger(L, SDLStatic_TiledTileHeight(map));
    return 4;
}

static int LMapLayers(lua_State *L)
{
    lua_pushinteger(L, SDLStatic_TiledLayerCount((SDLStatic_TiledMap *)CheckHandle(L, 1, MAP_MT)));
    return 1;
}

static int LMapLayerName(lua_State *L)
{
    const char *name = SDLStatic_TiledLayerName((SDLStatic_TiledMap *)CheckHandle(L, 1, MAP_MT),
                                                (int)luaL_checkinteger(L, 2));
    if (name == NULL)
    {
        lua_pushnil(L);
    }
    else
    {
        lua_pushstring(L, name);
    }
    return 1;
}

static int LMapTile(lua_State *L)
{
    lua_pushinteger(L, SDLStatic_TiledTileAt((SDLStatic_TiledMap *)CheckHandle(L, 1, MAP_MT),
                                             (int)luaL_checkinteger(L, 2),
                                             (int)luaL_checkinteger(L, 3),
                                             (int)luaL_checkinteger(L, 4)));
    return 1;
}

static int LMapObjects(lua_State *L)
{
    SDLStatic_TiledMap *map = (SDLStatic_TiledMap *)CheckHandle(L, 1, MAP_MT);
    const int layer = (int)luaL_checkinteger(L, 2);
    const int count = SDLStatic_TiledObjectCount(map, layer);
    lua_createtable(L, count, 0);
    for (int i = 0; i < count; ++i)
    {
        SDLStatic_TiledObject obj;
        if (!SDLStatic_TiledObjectAt(map, layer, i, &obj))
        {
            continue;
        }
        lua_newtable(L);
        lua_pushstring(L, obj.name != NULL ? obj.name : "");
        lua_setfield(L, -2, "name");
        lua_pushstring(L, obj.type != NULL ? obj.type : "");
        lua_setfield(L, -2, "type");
        lua_pushnumber(L, obj.x);
        lua_setfield(L, -2, "x");
        lua_pushnumber(L, obj.y);
        lua_setfield(L, -2, "y");
        lua_pushnumber(L, obj.w);
        lua_setfield(L, -2, "w");
        lua_pushnumber(L, obj.h);
        lua_setfield(L, -2, "h");
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

/* ----------------------------------------------------- vfs and utils ---- */

static int LMount(lua_State *L)
{
    if (!PHYSFS_isInit())
    {
        PHYSFS_init(NULL);
    }
    if (!PHYSFS_mount(luaL_checkstring(L, 1), luaL_optstring(L, 2, NULL), 1))
    {
        return luaL_error(L, "mount failed");
    }
    return 0;
}

static int LMountEncrypted(lua_State *L)
{
    if (!PHYSFS_isInit())
    {
        PHYSFS_init(NULL);
    }
    if (!SDLStatic_MountEncryptedArchiveFile(luaL_checkstring(L, 1), luaL_checkstring(L, 2),
                                             luaL_optstring(L, 3, NULL)))
    {
        return Fail(L);
    }
    return 0;
}

static int LReadFile(lua_State *L)
{
    int size = 0;
    unsigned char *data = SDLStatic_LoadVFSFile(luaL_checkstring(L, 1), &size);
    if (data == NULL)
    {
        return Fail(L);
    }
    lua_pushlstring(L, (const char *)data, (size_t)size);
    SDL_free(data);
    return 1;
}

static int LTicks(lua_State *L)
{
    lua_pushinteger(L, (lua_Integer)SDL_GetTicks());
    return 1;
}

static int LDelay(lua_State *L)
{
    SDL_Delay((Uint32)luaL_checkinteger(L, 1));
    return 0;
}

static int LSha256(lua_State *L)
{
    size_t len = 0;
    const char *data = luaL_checklstring(L, 1, &len);
    Uint8 digest[32];
    SDLStatic_SHA256(data, len, digest);
    char hex[65];
    for (int i = 0; i < 32; ++i)
    {
        SDL_snprintf(hex + i * 2, 3, "%02x", digest[i]);
    }
    lua_pushlstring(L, hex, 64);
    return 1;
}

typedef unsigned char *(*ByteFn)(const unsigned char *, int, int *);

static int PushByteResult(lua_State *L, unsigned char *out, int outSize)
{
    if (out == NULL)
    {
        return Fail(L);
    }
    lua_pushlstring(L, (const char *)out, (size_t)outSize);
    SDL_free(out);
    return 1;
}

static int LCompress(lua_State *L)
{
    size_t len = 0;
    const char *data = luaL_checklstring(L, 1, &len);
    int outSize = 0;
    unsigned char *out = SDLStatic_CompressData((const unsigned char *)data, (int)len, &outSize);
    return PushByteResult(L, out, outSize);
}

static int LDecompress(lua_State *L)
{
    size_t len = 0;
    const char *data = luaL_checklstring(L, 1, &len);
    int outSize = 0;
    unsigned char *out = SDLStatic_DecompressData((const unsigned char *)data, (int)len, &outSize);
    return PushByteResult(L, out, outSize);
}

static int LEncrypt(lua_State *L)
{
    size_t len = 0;
    const char *data = luaL_checklstring(L, 1, &len);
    int outSize = 0;
    unsigned char *out = SDLStatic_EncryptData((const unsigned char *)data, (int)len,
                                                luaL_checkstring(L, 2), &outSize);
    return PushByteResult(L, out, outSize);
}

static int LDecrypt(lua_State *L)
{
    size_t len = 0;
    const char *data = luaL_checklstring(L, 1, &len);
    int outSize = 0;
    unsigned char *out = SDLStatic_DecryptData((const unsigned char *)data, (int)len,
                                                luaL_checkstring(L, 2), &outSize);
    return PushByteResult(L, out, outSize);
}

static int LB64Encode(lua_State *L)
{
    size_t len = 0;
    const char *data = luaL_checklstring(L, 1, &len);
    int outSize = 0;
    char *out = SDLStatic_EncodeDataBase64((const unsigned char *)data, (int)len, &outSize);
    if (out == NULL)
    {
        return Fail(L);
    }
    lua_pushlstring(L, out, (size_t)outSize);
    SDL_free(out);
    return 1;
}

static int LB64Decode(lua_State *L)
{
    int outSize = 0;
    unsigned char *out = SDLStatic_DecodeDataBase64(luaL_checkstring(L, 1), &outSize);
    return PushByteResult(L, out, outSize);
}

/* ------------------------------------------------------------ open ------ */

static void MakeMeta(lua_State *L, const char *name, const luaL_Reg *methods, lua_CFunction gc)
{
    luaL_newmetatable(L, name);
    lua_pushcfunction(L, gc);
    lua_setfield(L, -2, "__gc");
    lua_newtable(L);
    luaL_setfuncs(L, methods, 0);
    lua_setfield(L, -2, "__index");
    lua_pop(L, 1);
}

extern int SDLStatic_OpenGeneratedLuaBindings(lua_State *L);

bool SDLStatic_OpenLuaBindings(lua_State *L)
{
    static const luaL_Reg app_methods[] = {
        {"clear", LAppClear},   {"present", LAppPresent}, {"poll", LAppPoll},
        {"rect", LAppRect},     {"circle", LAppCircle},   {"line", LAppLine},
        {"text", LAppText},     {"key_down", LAppKeyDown}, {"load_texture", LAppLoadTexture},
        {"draw", LAppDraw},     {NULL, NULL}};
    static const luaL_Reg tex_methods[] = {{"size", LTexSize}, {NULL, NULL}};
    static const luaL_Reg audio_methods[] = {
        {"load", LAudioLoad}, {"play", LAudioPlay}, {NULL, NULL}};
    static const luaL_Reg sound_methods[] = {{NULL, NULL}};
    static const luaL_Reg track_methods[] = {
        {"stop", LTrackStop}, {"gain", LTrackGain}, {NULL, NULL}};
    static const luaL_Reg world_methods[] = {{"step", LWorldStep},
                                             {"box", LWorldBox},
                                             {"circle", LWorldCircle},
                                             {NULL, NULL}};
    static const luaL_Reg map_methods[] = {{"size", LMapSize},
                                           {"layers", LMapLayers},
                                           {"layer_name", LMapLayerName},
                                           {"tile", LMapTile},
                                           {"objects", LMapObjects},
                                           {NULL, NULL}};
    static const luaL_Reg body_methods[] = {{"position", LBodyPosition},
                                            {"angle", LBodyAngle},
                                            {"velocity", LBodyVelocity},
                                            {"impulse", LBodyImpulse},
                                            {NULL, NULL}};
    static const luaL_Reg module_fns[] = {{"window", LWindow},
                                          {"load_map", LLoadMap},
                                          {"open_audio", LOpenAudio},
                                          {"world", LWorld},
                                          {"mount", LMount},
                                          {"mount_encrypted", LMountEncrypted},
                                          {"read_file", LReadFile},
                                          {"ticks", LTicks},
                                          {"delay", LDelay},
                                          {"sha256", LSha256},
                                          {"compress", LCompress},
                                          {"decompress", LDecompress},
                                          {"encrypt", LEncrypt},
                                          {"decrypt", LDecrypt},
                                          {"b64encode", LB64Encode},
                                          {"b64decode", LB64Decode},
                                          {NULL, NULL}};
    if (L == NULL)
    {
        return SDL_InvalidParamError("L");
    }
    MakeMeta(L, APP_MT, app_methods, LAppGc);
    MakeMeta(L, TEX_MT, tex_methods, LTexGc);
    MakeMeta(L, AUDIO_MT, audio_methods, LAudioGc);
    MakeMeta(L, SOUND_MT, sound_methods, LSoundGc);
    MakeMeta(L, TRACK_MT, track_methods, LTrackGc);
    MakeMeta(L, WORLD_MT, world_methods, LWorldGc);
    MakeMeta(L, BODY_MT, body_methods, LBodyGc);
    MakeMeta(L, MAP_MT, map_methods, LMapGc);
    luaL_newlib(L, module_fns);
    lua_setglobal(L, "SDLStatic");
    /* Generated flat mirror of the full C API (SDL, MIX, IMG, TTF, NET,
     * PHYSFS, B2, NK, JSON, SDLStaticC tables); see
     * bindings/generated/COVERAGE.md. */
    SDLStatic_OpenGeneratedLuaBindings(L);
    /* Engine hooks: the one thing a generator cannot produce, because it
     * has to turn a Lua function into something C can hold. */
    SDLStatic_OpenLuaEngineHooks(L);
    /* Real regular expressions, which Lua patterns are not. */
    if (!SDLStatic_OpenLuaRegex(L))
    {
        return false;
    }
    return true;
}
