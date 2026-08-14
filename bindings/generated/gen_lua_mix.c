/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for SDL_mixer. */
#include "../src/gen_support_lua.h"

#include <SDL3_mixer/SDL_mixer.h>
#include <string.h>

static void GenRead_MIX_Point3D(lua_State *L, int idx, MIX_Point3D *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (float)SDLStaticGen_LuaFieldNum(L, idx, "x");
    out->y = (float)SDLStaticGen_LuaFieldNum(L, idx, "y");
    out->z = (float)SDLStaticGen_LuaFieldNum(L, idx, "z");
}

static void GenPush_MIX_Point3D(lua_State *L, const MIX_Point3D *in)
{
    lua_createtable(L, 0, 3);
    lua_pushnumber(L, (lua_Number)in->x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, (lua_Number)in->y);
    lua_setfield(L, -2, "y");
    lua_pushnumber(L, (lua_Number)in->z);
    lua_setfield(L, -2, "z");
}

static void GenRead_MIX_StereoGains(lua_State *L, int idx, MIX_StereoGains *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->left = (float)SDLStaticGen_LuaFieldNum(L, idx, "left");
    out->right = (float)SDLStaticGen_LuaFieldNum(L, idx, "right");
}

static void GenRead_SDL_AudioSpec(lua_State *L, int idx, SDL_AudioSpec *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->format = (SDL_AudioFormat)SDLStaticGen_LuaFieldInt(L, idx, "format");
    out->channels = (int)SDLStaticGen_LuaFieldInt(L, idx, "channels");
    out->freq = (int)SDLStaticGen_LuaFieldInt(L, idx, "freq");
}

static void GenPush_SDL_AudioSpec(lua_State *L, const SDL_AudioSpec *in)
{
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, (lua_Integer)in->format);
    lua_setfield(L, -2, "format");
    lua_pushinteger(L, (lua_Integer)in->channels);
    lua_setfield(L, -2, "channels");
    lua_pushinteger(L, (lua_Integer)in->freq);
    lua_setfield(L, -2, "freq");
}

static void GenDtor_MIX_DestroyMixer(void *p)
{
    MIX_Mixer *typed = (MIX_Mixer *)p;
    MIX_DestroyMixer(typed);
}

static void GenDtor_MIX_DestroyAudio(void *p)
{
    MIX_Audio *typed = (MIX_Audio *)p;
    MIX_DestroyAudio(typed);
}

static void GenDtor_MIX_DestroyTrack(void *p)
{
    MIX_Track *typed = (MIX_Track *)p;
    MIX_DestroyTrack(typed);
}

static void GenDtor_MIX_DestroyAudioDecoder(void *p)
{
    MIX_AudioDecoder *typed = (MIX_AudioDecoder *)p;
    MIX_DestroyAudioDecoder(typed);
}

static int GenL_MIX_AudioFramesToMS(lua_State *L)
{
    (void)L;
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Audio");
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    Sint64 rv = MIX_AudioFramesToMS(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_AudioMSToFrames(lua_State *L)
{
    (void)L;
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Audio");
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    Sint64 rv = MIX_AudioMSToFrames(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_CreateAudioDecoder(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_PropertiesID a1 = (SDL_PropertiesID)luaL_checkinteger(L, 2);
    MIX_AudioDecoder * rv = MIX_CreateAudioDecoder(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "MIX_AudioDecoder", GenDtor_MIX_DestroyAudioDecoder);
    return 1;
}

static int GenL_MIX_CreateAudioDecoder_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDL_PropertiesID a2 = (SDL_PropertiesID)luaL_checkinteger(L, 3);
    MIX_AudioDecoder * rv = MIX_CreateAudioDecoder_IO(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "MIX_AudioDecoder", GenDtor_MIX_DestroyAudioDecoder);
    return 1;
}

static int GenL_MIX_CreateGroup(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    MIX_Group * rv = MIX_CreateGroup(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Group");
    return 1;
}

static int GenL_MIX_CreateMixer(lua_State *L)
{
    (void)L;
    SDL_AudioSpec tmp0;
    const SDL_AudioSpec *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_AudioSpec(L, 1, &tmp0);
        a0 = &tmp0;
    }
    MIX_Mixer * rv = MIX_CreateMixer(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "MIX_Mixer", GenDtor_MIX_DestroyMixer);
    return 1;
}

static int GenL_MIX_CreateMixerDevice(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    SDL_AudioSpec tmp1;
    const SDL_AudioSpec *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_AudioSpec(L, 2, &tmp1);
        a1 = &tmp1;
    }
    MIX_Mixer * rv = MIX_CreateMixerDevice(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "MIX_Mixer", GenDtor_MIX_DestroyMixer);
    return 1;
}

static int GenL_MIX_CreateSineWaveAudio(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    int a1 = (int)luaL_checkinteger(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    Sint64 a3 = (Sint64)luaL_checkinteger(L, 4);
    MIX_Audio * rv = MIX_CreateSineWaveAudio(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    return 1;
}

static int GenL_MIX_CreateTrack(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    MIX_Track * rv = MIX_CreateTrack(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "MIX_Track", GenDtor_MIX_DestroyTrack);
    return 1;
}

static int GenL_MIX_DestroyAudio(lua_State *L)
{
    (void)L;
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_LuaTakeHandle(L, 1, "MIX_Audio");
    MIX_DestroyAudio(a0);
    return 0;
}

static int GenL_MIX_DestroyAudioDecoder(lua_State *L)
{
    (void)L;
    MIX_AudioDecoder *a0 = (MIX_AudioDecoder *)SDLStaticGen_LuaTakeHandle(L, 1, "MIX_AudioDecoder");
    MIX_DestroyAudioDecoder(a0);
    return 0;
}

static int GenL_MIX_DestroyGroup(lua_State *L)
{
    (void)L;
    MIX_Group *a0 = (MIX_Group *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Group");
    MIX_DestroyGroup(a0);
    return 0;
}

static int GenL_MIX_DestroyMixer(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaTakeHandle(L, 1, "MIX_Mixer");
    MIX_DestroyMixer(a0);
    return 0;
}

static int GenL_MIX_DestroyTrack(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaTakeHandle(L, 1, "MIX_Track");
    MIX_DestroyTrack(a0);
    return 0;
}

static int GenL_MIX_FramesToMS(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    Sint64 rv = MIX_FramesToMS(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_GetAudioDecoder(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    const char * rv = MIX_GetAudioDecoder(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_MIX_GetAudioDecoderFormat(lua_State *L)
{
    (void)L;
    MIX_AudioDecoder *a0 = (MIX_AudioDecoder *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_AudioDecoder");
    SDL_AudioSpec out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = MIX_GetAudioDecoderFormat(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_AudioSpec(L, &out1);
    return 2;
}

static int GenL_MIX_GetAudioDecoderProperties(lua_State *L)
{
    (void)L;
    MIX_AudioDecoder *a0 = (MIX_AudioDecoder *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_AudioDecoder");
    SDL_PropertiesID rv = MIX_GetAudioDecoderProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_GetAudioDuration(lua_State *L)
{
    (void)L;
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Audio");
    Sint64 rv = MIX_GetAudioDuration(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_GetAudioFormat(lua_State *L)
{
    (void)L;
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Audio");
    SDL_AudioSpec out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = MIX_GetAudioFormat(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_AudioSpec(L, &out1);
    return 2;
}

static int GenL_MIX_GetAudioProperties(lua_State *L)
{
    (void)L;
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Audio");
    SDL_PropertiesID rv = MIX_GetAudioProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_GetGroupMixer(lua_State *L)
{
    (void)L;
    MIX_Group *a0 = (MIX_Group *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Group");
    MIX_Mixer * rv = MIX_GetGroupMixer(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Mixer");
    return 1;
}

static int GenL_MIX_GetGroupProperties(lua_State *L)
{
    (void)L;
    MIX_Group *a0 = (MIX_Group *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Group");
    SDL_PropertiesID rv = MIX_GetGroupProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_GetMixerFormat(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    SDL_AudioSpec out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = MIX_GetMixerFormat(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_AudioSpec(L, &out1);
    return 2;
}

static int GenL_MIX_GetMixerFrequencyRatio(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    float rv = MIX_GetMixerFrequencyRatio(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_MIX_GetMixerGain(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    float rv = MIX_GetMixerGain(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_MIX_GetMixerProperties(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    SDL_PropertiesID rv = MIX_GetMixerProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_GetNumAudioDecoders(lua_State *L)
{
    (void)L;
    int rv = MIX_GetNumAudioDecoders();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_GetTrack3DPosition(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    MIX_Point3D out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = MIX_GetTrack3DPosition(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_MIX_Point3D(L, &out1);
    return 2;
}

static int GenL_MIX_GetTrackAudio(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    MIX_Audio * rv = MIX_GetTrackAudio(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Audio");
    return 1;
}

static int GenL_MIX_GetTrackAudioStream(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    SDL_AudioStream * rv = MIX_GetTrackAudioStream(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_AudioStream");
    return 1;
}

static int GenL_MIX_GetTrackFadeFrames(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    Sint64 rv = MIX_GetTrackFadeFrames(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_GetTrackFrequencyRatio(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    float rv = MIX_GetTrackFrequencyRatio(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_MIX_GetTrackGain(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    float rv = MIX_GetTrackGain(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_MIX_GetTrackLoops(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    int rv = MIX_GetTrackLoops(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_GetTrackMixer(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    MIX_Mixer * rv = MIX_GetTrackMixer(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Mixer");
    return 1;
}

static int GenL_MIX_GetTrackPlaybackPosition(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    Sint64 rv = MIX_GetTrackPlaybackPosition(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_GetTrackProperties(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    SDL_PropertiesID rv = MIX_GetTrackProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_GetTrackRemaining(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    Sint64 rv = MIX_GetTrackRemaining(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_Init(lua_State *L)
{
    (void)L;
    bool rv = MIX_Init();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_LoadAudio(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool a2 = (bool)lua_toboolean(L, 3);
    MIX_Audio * rv = MIX_LoadAudio(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    return 1;
}

static int GenL_MIX_LoadAudioNoCopy(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    bool a3 = (bool)lua_toboolean(L, 3);
    MIX_Audio * rv = MIX_LoadAudioNoCopy(a0, (const void *)a1, (size_t)len1, a3);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Audio");
    return 1;
}

static int GenL_MIX_LoadAudioWithProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    MIX_Audio * rv = MIX_LoadAudioWithProperties(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    return 1;
}

static int GenL_MIX_LoadAudio_IO(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool a3 = (bool)lua_toboolean(L, 4);
    MIX_Audio * rv = MIX_LoadAudio_IO(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    return 1;
}

static int GenL_MIX_LoadRawAudio(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    SDL_AudioSpec tmp3;
    const SDL_AudioSpec *a3 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_AudioSpec(L, 3, &tmp3);
        a3 = &tmp3;
    }
    MIX_Audio * rv = MIX_LoadRawAudio(a0, (const void *)a1, (size_t)len1, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    return 1;
}

static int GenL_MIX_LoadRawAudioNoCopy(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    SDL_AudioSpec tmp3;
    const SDL_AudioSpec *a3 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_AudioSpec(L, 3, &tmp3);
        a3 = &tmp3;
    }
    bool a4 = (bool)lua_toboolean(L, 4);
    MIX_Audio * rv = MIX_LoadRawAudioNoCopy(a0, (const void *)a1, (size_t)len1, a3, a4);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Audio");
    return 1;
}

static int GenL_MIX_LoadRawAudio_IO(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    SDL_AudioSpec tmp2;
    const SDL_AudioSpec *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_AudioSpec(L, 3, &tmp2);
        a2 = &tmp2;
    }
    bool a3 = (bool)lua_toboolean(L, 4);
    MIX_Audio * rv = MIX_LoadRawAudio_IO(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    return 1;
}

static int GenL_MIX_LockMixer(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    MIX_LockMixer(a0);
    return 0;
}

static int GenL_MIX_MSToFrames(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    Sint64 rv = MIX_MSToFrames(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_PauseAllTracks(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    bool rv = MIX_PauseAllTracks(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_PauseTag(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = MIX_PauseTag(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_PauseTrack(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    bool rv = MIX_PauseTrack(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_PlayAudio(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    MIX_Audio *a1 = (MIX_Audio *)SDLStaticGen_LuaCheckHandle(L, 2, "MIX_Audio");
    bool rv = MIX_PlayAudio(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_PlayTag(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_PropertiesID a2 = (SDL_PropertiesID)luaL_checkinteger(L, 3);
    bool rv = MIX_PlayTag(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_PlayTrack(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    SDL_PropertiesID a1 = (SDL_PropertiesID)luaL_checkinteger(L, 2);
    bool rv = MIX_PlayTrack(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_Quit(lua_State *L)
{
    (void)L;
    MIX_Quit();
    return 0;
}

static int GenL_MIX_ResumeAllTracks(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    bool rv = MIX_ResumeAllTracks(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_ResumeTag(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = MIX_ResumeTag(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_ResumeTrack(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    bool rv = MIX_ResumeTrack(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetMixerFrequencyRatio(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = MIX_SetMixerFrequencyRatio(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetMixerGain(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = MIX_SetMixerGain(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTagGain(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    bool rv = MIX_SetTagGain(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTrack3DPosition(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    MIX_Point3D tmp1;
    const MIX_Point3D *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_MIX_Point3D(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = MIX_SetTrack3DPosition(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTrackAudio(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    MIX_Audio *a1 = (MIX_Audio *)SDLStaticGen_LuaCheckHandle(L, 2, "MIX_Audio");
    bool rv = MIX_SetTrackAudio(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTrackAudioStream(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    SDL_AudioStream *a1 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_AudioStream");
    bool rv = MIX_SetTrackAudioStream(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTrackFrequencyRatio(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = MIX_SetTrackFrequencyRatio(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTrackGain(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = MIX_SetTrackGain(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTrackGroup(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    MIX_Group *a1 = (MIX_Group *)SDLStaticGen_LuaCheckHandle(L, 2, "MIX_Group");
    bool rv = MIX_SetTrackGroup(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTrackIOStream(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = MIX_SetTrackIOStream(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTrackLoops(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = MIX_SetTrackLoops(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTrackPlaybackPosition(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    bool rv = MIX_SetTrackPlaybackPosition(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTrackRawIOStream(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    SDL_AudioSpec tmp2;
    const SDL_AudioSpec *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_AudioSpec(L, 3, &tmp2);
        a2 = &tmp2;
    }
    bool a3 = (bool)lua_toboolean(L, 4);
    bool rv = MIX_SetTrackRawIOStream(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_SetTrackStereo(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    MIX_StereoGains tmp1;
    const MIX_StereoGains *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_MIX_StereoGains(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = MIX_SetTrackStereo(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_StopAllTracks(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    bool rv = MIX_StopAllTracks(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_StopTag(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    Sint64 a2 = (Sint64)luaL_checkinteger(L, 3);
    bool rv = MIX_StopTag(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_StopTrack(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    bool rv = MIX_StopTrack(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_TagTrack(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = MIX_TagTrack(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_TrackFramesToMS(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    Sint64 rv = MIX_TrackFramesToMS(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_TrackMSToFrames(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    Sint64 rv = MIX_TrackMSToFrames(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_MIX_TrackPaused(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    bool rv = MIX_TrackPaused(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_TrackPlaying(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    bool rv = MIX_TrackPlaying(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_MIX_UnlockMixer(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    MIX_UnlockMixer(a0);
    return 0;
}

static int GenL_MIX_UntagTrack(lua_State *L)
{
    (void)L;
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Track");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    MIX_UntagTrack(a0, a1);
    return 0;
}

static int GenL_MIX_Version(lua_State *L)
{
    (void)L;
    int rv = MIX_Version();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

int SDLStaticGen_OpenLua_mix(lua_State *L);
int SDLStaticGen_OpenLua_mix(lua_State *L)
{
    lua_createtable(L, 0, 84);
    lua_pushcfunction(L, GenL_MIX_AudioFramesToMS);
    lua_setfield(L, -2, "AudioFramesToMS");
    lua_pushcfunction(L, GenL_MIX_AudioMSToFrames);
    lua_setfield(L, -2, "AudioMSToFrames");
    lua_pushcfunction(L, GenL_MIX_CreateAudioDecoder);
    lua_setfield(L, -2, "CreateAudioDecoder");
    lua_pushcfunction(L, GenL_MIX_CreateAudioDecoder_IO);
    lua_setfield(L, -2, "CreateAudioDecoder_IO");
    lua_pushcfunction(L, GenL_MIX_CreateGroup);
    lua_setfield(L, -2, "CreateGroup");
    lua_pushcfunction(L, GenL_MIX_CreateMixer);
    lua_setfield(L, -2, "CreateMixer");
    lua_pushcfunction(L, GenL_MIX_CreateMixerDevice);
    lua_setfield(L, -2, "CreateMixerDevice");
    lua_pushcfunction(L, GenL_MIX_CreateSineWaveAudio);
    lua_setfield(L, -2, "CreateSineWaveAudio");
    lua_pushcfunction(L, GenL_MIX_CreateTrack);
    lua_setfield(L, -2, "CreateTrack");
    lua_pushcfunction(L, GenL_MIX_DestroyAudio);
    lua_setfield(L, -2, "DestroyAudio");
    lua_pushcfunction(L, GenL_MIX_DestroyAudioDecoder);
    lua_setfield(L, -2, "DestroyAudioDecoder");
    lua_pushcfunction(L, GenL_MIX_DestroyGroup);
    lua_setfield(L, -2, "DestroyGroup");
    lua_pushcfunction(L, GenL_MIX_DestroyMixer);
    lua_setfield(L, -2, "DestroyMixer");
    lua_pushcfunction(L, GenL_MIX_DestroyTrack);
    lua_setfield(L, -2, "DestroyTrack");
    lua_pushcfunction(L, GenL_MIX_FramesToMS);
    lua_setfield(L, -2, "FramesToMS");
    lua_pushcfunction(L, GenL_MIX_GetAudioDecoder);
    lua_setfield(L, -2, "GetAudioDecoder");
    lua_pushcfunction(L, GenL_MIX_GetAudioDecoderFormat);
    lua_setfield(L, -2, "GetAudioDecoderFormat");
    lua_pushcfunction(L, GenL_MIX_GetAudioDecoderProperties);
    lua_setfield(L, -2, "GetAudioDecoderProperties");
    lua_pushcfunction(L, GenL_MIX_GetAudioDuration);
    lua_setfield(L, -2, "GetAudioDuration");
    lua_pushcfunction(L, GenL_MIX_GetAudioFormat);
    lua_setfield(L, -2, "GetAudioFormat");
    lua_pushcfunction(L, GenL_MIX_GetAudioProperties);
    lua_setfield(L, -2, "GetAudioProperties");
    lua_pushcfunction(L, GenL_MIX_GetGroupMixer);
    lua_setfield(L, -2, "GetGroupMixer");
    lua_pushcfunction(L, GenL_MIX_GetGroupProperties);
    lua_setfield(L, -2, "GetGroupProperties");
    lua_pushcfunction(L, GenL_MIX_GetMixerFormat);
    lua_setfield(L, -2, "GetMixerFormat");
    lua_pushcfunction(L, GenL_MIX_GetMixerFrequencyRatio);
    lua_setfield(L, -2, "GetMixerFrequencyRatio");
    lua_pushcfunction(L, GenL_MIX_GetMixerGain);
    lua_setfield(L, -2, "GetMixerGain");
    lua_pushcfunction(L, GenL_MIX_GetMixerProperties);
    lua_setfield(L, -2, "GetMixerProperties");
    lua_pushcfunction(L, GenL_MIX_GetNumAudioDecoders);
    lua_setfield(L, -2, "GetNumAudioDecoders");
    lua_pushcfunction(L, GenL_MIX_GetTrack3DPosition);
    lua_setfield(L, -2, "GetTrack3DPosition");
    lua_pushcfunction(L, GenL_MIX_GetTrackAudio);
    lua_setfield(L, -2, "GetTrackAudio");
    lua_pushcfunction(L, GenL_MIX_GetTrackAudioStream);
    lua_setfield(L, -2, "GetTrackAudioStream");
    lua_pushcfunction(L, GenL_MIX_GetTrackFadeFrames);
    lua_setfield(L, -2, "GetTrackFadeFrames");
    lua_pushcfunction(L, GenL_MIX_GetTrackFrequencyRatio);
    lua_setfield(L, -2, "GetTrackFrequencyRatio");
    lua_pushcfunction(L, GenL_MIX_GetTrackGain);
    lua_setfield(L, -2, "GetTrackGain");
    lua_pushcfunction(L, GenL_MIX_GetTrackLoops);
    lua_setfield(L, -2, "GetTrackLoops");
    lua_pushcfunction(L, GenL_MIX_GetTrackMixer);
    lua_setfield(L, -2, "GetTrackMixer");
    lua_pushcfunction(L, GenL_MIX_GetTrackPlaybackPosition);
    lua_setfield(L, -2, "GetTrackPlaybackPosition");
    lua_pushcfunction(L, GenL_MIX_GetTrackProperties);
    lua_setfield(L, -2, "GetTrackProperties");
    lua_pushcfunction(L, GenL_MIX_GetTrackRemaining);
    lua_setfield(L, -2, "GetTrackRemaining");
    lua_pushcfunction(L, GenL_MIX_Init);
    lua_setfield(L, -2, "Init");
    lua_pushcfunction(L, GenL_MIX_LoadAudio);
    lua_setfield(L, -2, "LoadAudio");
    lua_pushcfunction(L, GenL_MIX_LoadAudioNoCopy);
    lua_setfield(L, -2, "LoadAudioNoCopy");
    lua_pushcfunction(L, GenL_MIX_LoadAudioWithProperties);
    lua_setfield(L, -2, "LoadAudioWithProperties");
    lua_pushcfunction(L, GenL_MIX_LoadAudio_IO);
    lua_setfield(L, -2, "LoadAudio_IO");
    lua_pushcfunction(L, GenL_MIX_LoadRawAudio);
    lua_setfield(L, -2, "LoadRawAudio");
    lua_pushcfunction(L, GenL_MIX_LoadRawAudioNoCopy);
    lua_setfield(L, -2, "LoadRawAudioNoCopy");
    lua_pushcfunction(L, GenL_MIX_LoadRawAudio_IO);
    lua_setfield(L, -2, "LoadRawAudio_IO");
    lua_pushcfunction(L, GenL_MIX_LockMixer);
    lua_setfield(L, -2, "LockMixer");
    lua_pushcfunction(L, GenL_MIX_MSToFrames);
    lua_setfield(L, -2, "MSToFrames");
    lua_pushcfunction(L, GenL_MIX_PauseAllTracks);
    lua_setfield(L, -2, "PauseAllTracks");
    lua_pushcfunction(L, GenL_MIX_PauseTag);
    lua_setfield(L, -2, "PauseTag");
    lua_pushcfunction(L, GenL_MIX_PauseTrack);
    lua_setfield(L, -2, "PauseTrack");
    lua_pushcfunction(L, GenL_MIX_PlayAudio);
    lua_setfield(L, -2, "PlayAudio");
    lua_pushcfunction(L, GenL_MIX_PlayTag);
    lua_setfield(L, -2, "PlayTag");
    lua_pushcfunction(L, GenL_MIX_PlayTrack);
    lua_setfield(L, -2, "PlayTrack");
    lua_pushcfunction(L, GenL_MIX_Quit);
    lua_setfield(L, -2, "Quit");
    lua_pushcfunction(L, GenL_MIX_ResumeAllTracks);
    lua_setfield(L, -2, "ResumeAllTracks");
    lua_pushcfunction(L, GenL_MIX_ResumeTag);
    lua_setfield(L, -2, "ResumeTag");
    lua_pushcfunction(L, GenL_MIX_ResumeTrack);
    lua_setfield(L, -2, "ResumeTrack");
    lua_pushcfunction(L, GenL_MIX_SetMixerFrequencyRatio);
    lua_setfield(L, -2, "SetMixerFrequencyRatio");
    lua_pushcfunction(L, GenL_MIX_SetMixerGain);
    lua_setfield(L, -2, "SetMixerGain");
    lua_pushcfunction(L, GenL_MIX_SetTagGain);
    lua_setfield(L, -2, "SetTagGain");
    lua_pushcfunction(L, GenL_MIX_SetTrack3DPosition);
    lua_setfield(L, -2, "SetTrack3DPosition");
    lua_pushcfunction(L, GenL_MIX_SetTrackAudio);
    lua_setfield(L, -2, "SetTrackAudio");
    lua_pushcfunction(L, GenL_MIX_SetTrackAudioStream);
    lua_setfield(L, -2, "SetTrackAudioStream");
    lua_pushcfunction(L, GenL_MIX_SetTrackFrequencyRatio);
    lua_setfield(L, -2, "SetTrackFrequencyRatio");
    lua_pushcfunction(L, GenL_MIX_SetTrackGain);
    lua_setfield(L, -2, "SetTrackGain");
    lua_pushcfunction(L, GenL_MIX_SetTrackGroup);
    lua_setfield(L, -2, "SetTrackGroup");
    lua_pushcfunction(L, GenL_MIX_SetTrackIOStream);
    lua_setfield(L, -2, "SetTrackIOStream");
    lua_pushcfunction(L, GenL_MIX_SetTrackLoops);
    lua_setfield(L, -2, "SetTrackLoops");
    lua_pushcfunction(L, GenL_MIX_SetTrackPlaybackPosition);
    lua_setfield(L, -2, "SetTrackPlaybackPosition");
    lua_pushcfunction(L, GenL_MIX_SetTrackRawIOStream);
    lua_setfield(L, -2, "SetTrackRawIOStream");
    lua_pushcfunction(L, GenL_MIX_SetTrackStereo);
    lua_setfield(L, -2, "SetTrackStereo");
    lua_pushcfunction(L, GenL_MIX_StopAllTracks);
    lua_setfield(L, -2, "StopAllTracks");
    lua_pushcfunction(L, GenL_MIX_StopTag);
    lua_setfield(L, -2, "StopTag");
    lua_pushcfunction(L, GenL_MIX_StopTrack);
    lua_setfield(L, -2, "StopTrack");
    lua_pushcfunction(L, GenL_MIX_TagTrack);
    lua_setfield(L, -2, "TagTrack");
    lua_pushcfunction(L, GenL_MIX_TrackFramesToMS);
    lua_setfield(L, -2, "TrackFramesToMS");
    lua_pushcfunction(L, GenL_MIX_TrackMSToFrames);
    lua_setfield(L, -2, "TrackMSToFrames");
    lua_pushcfunction(L, GenL_MIX_TrackPaused);
    lua_setfield(L, -2, "TrackPaused");
    lua_pushcfunction(L, GenL_MIX_TrackPlaying);
    lua_setfield(L, -2, "TrackPlaying");
    lua_pushcfunction(L, GenL_MIX_UnlockMixer);
    lua_setfield(L, -2, "UnlockMixer");
    lua_pushcfunction(L, GenL_MIX_UntagTrack);
    lua_setfield(L, -2, "UntagTrack");
    lua_pushcfunction(L, GenL_MIX_Version);
    lua_setfield(L, -2, "Version");
    lua_setglobal(L, "MIX");
    return 0;
}
