/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for SDL3 core. */
#include "../src/gen_support_lua.h"

#include <SDL3/SDL.h>
#include <string.h>

static void GenPush_SDL_AtomicInt(lua_State *L, const SDL_AtomicInt *in)
{
    lua_createtable(L, 0, 1);
    lua_pushinteger(L, (lua_Integer)in->value);
    lua_setfield(L, -2, "value");
}

static void GenPush_SDL_AtomicU32(lua_State *L, const SDL_AtomicU32 *in)
{
    lua_createtable(L, 0, 1);
    lua_pushinteger(L, (lua_Integer)in->value);
    lua_setfield(L, -2, "value");
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

static void GenRead_SDL_CameraSpec(lua_State *L, int idx, SDL_CameraSpec *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->format = (SDL_PixelFormat)SDLStaticGen_LuaFieldInt(L, idx, "format");
    out->colorspace = (SDL_Colorspace)SDLStaticGen_LuaFieldInt(L, idx, "colorspace");
    out->width = (int)SDLStaticGen_LuaFieldInt(L, idx, "width");
    out->height = (int)SDLStaticGen_LuaFieldInt(L, idx, "height");
    out->framerate_numerator = (int)SDLStaticGen_LuaFieldInt(L, idx, "framerate_numerator");
    out->framerate_denominator = (int)SDLStaticGen_LuaFieldInt(L, idx, "framerate_denominator");
}

static void GenPush_SDL_CameraSpec(lua_State *L, const SDL_CameraSpec *in)
{
    lua_createtable(L, 0, 6);
    lua_pushinteger(L, (lua_Integer)in->format);
    lua_setfield(L, -2, "format");
    lua_pushinteger(L, (lua_Integer)in->colorspace);
    lua_setfield(L, -2, "colorspace");
    lua_pushinteger(L, (lua_Integer)in->width);
    lua_setfield(L, -2, "width");
    lua_pushinteger(L, (lua_Integer)in->height);
    lua_setfield(L, -2, "height");
    lua_pushinteger(L, (lua_Integer)in->framerate_numerator);
    lua_setfield(L, -2, "framerate_numerator");
    lua_pushinteger(L, (lua_Integer)in->framerate_denominator);
    lua_setfield(L, -2, "framerate_denominator");
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

static void GenRead_SDL_DateTime(lua_State *L, int idx, SDL_DateTime *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->year = (int)SDLStaticGen_LuaFieldInt(L, idx, "year");
    out->month = (int)SDLStaticGen_LuaFieldInt(L, idx, "month");
    out->day = (int)SDLStaticGen_LuaFieldInt(L, idx, "day");
    out->hour = (int)SDLStaticGen_LuaFieldInt(L, idx, "hour");
    out->minute = (int)SDLStaticGen_LuaFieldInt(L, idx, "minute");
    out->second = (int)SDLStaticGen_LuaFieldInt(L, idx, "second");
    out->nanosecond = (int)SDLStaticGen_LuaFieldInt(L, idx, "nanosecond");
    out->day_of_week = (int)SDLStaticGen_LuaFieldInt(L, idx, "day_of_week");
    out->utc_offset = (int)SDLStaticGen_LuaFieldInt(L, idx, "utc_offset");
}

static void GenPush_SDL_DateTime(lua_State *L, const SDL_DateTime *in)
{
    lua_createtable(L, 0, 9);
    lua_pushinteger(L, (lua_Integer)in->year);
    lua_setfield(L, -2, "year");
    lua_pushinteger(L, (lua_Integer)in->month);
    lua_setfield(L, -2, "month");
    lua_pushinteger(L, (lua_Integer)in->day);
    lua_setfield(L, -2, "day");
    lua_pushinteger(L, (lua_Integer)in->hour);
    lua_setfield(L, -2, "hour");
    lua_pushinteger(L, (lua_Integer)in->minute);
    lua_setfield(L, -2, "minute");
    lua_pushinteger(L, (lua_Integer)in->second);
    lua_setfield(L, -2, "second");
    lua_pushinteger(L, (lua_Integer)in->nanosecond);
    lua_setfield(L, -2, "nanosecond");
    lua_pushinteger(L, (lua_Integer)in->day_of_week);
    lua_setfield(L, -2, "day_of_week");
    lua_pushinteger(L, (lua_Integer)in->utc_offset);
    lua_setfield(L, -2, "utc_offset");
}

static void GenRead_SDL_FColor(lua_State *L, int idx, SDL_FColor *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->r = (float)SDLStaticGen_LuaFieldNum(L, idx, "r");
    out->g = (float)SDLStaticGen_LuaFieldNum(L, idx, "g");
    out->b = (float)SDLStaticGen_LuaFieldNum(L, idx, "b");
    out->a = (float)SDLStaticGen_LuaFieldNum(L, idx, "a");
}

static void GenRead_SDL_FPoint(lua_State *L, int idx, SDL_FPoint *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (float)SDLStaticGen_LuaFieldNum(L, idx, "x");
    out->y = (float)SDLStaticGen_LuaFieldNum(L, idx, "y");
}

static void GenRead_SDL_FRect(lua_State *L, int idx, SDL_FRect *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (float)SDLStaticGen_LuaFieldNum(L, idx, "x");
    out->y = (float)SDLStaticGen_LuaFieldNum(L, idx, "y");
    out->w = (float)SDLStaticGen_LuaFieldNum(L, idx, "w");
    out->h = (float)SDLStaticGen_LuaFieldNum(L, idx, "h");
}

static void GenPush_SDL_FRect(lua_State *L, const SDL_FRect *in)
{
    lua_createtable(L, 0, 4);
    lua_pushnumber(L, (lua_Number)in->x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, (lua_Number)in->y);
    lua_setfield(L, -2, "y");
    lua_pushnumber(L, (lua_Number)in->w);
    lua_setfield(L, -2, "w");
    lua_pushnumber(L, (lua_Number)in->h);
    lua_setfield(L, -2, "h");
}

static void GenRead_SDL_GPUBufferCreateInfo(lua_State *L, int idx, SDL_GPUBufferCreateInfo *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->usage = (SDL_GPUBufferUsageFlags)SDLStaticGen_LuaFieldInt(L, idx, "usage");
    out->size = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "size");
    out->props = (SDL_PropertiesID)SDLStaticGen_LuaFieldInt(L, idx, "props");
}

static void GenRead_SDL_GPUSamplerCreateInfo(lua_State *L, int idx, SDL_GPUSamplerCreateInfo *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->min_filter = (SDL_GPUFilter)SDLStaticGen_LuaFieldInt(L, idx, "min_filter");
    out->mag_filter = (SDL_GPUFilter)SDLStaticGen_LuaFieldInt(L, idx, "mag_filter");
    out->mipmap_mode = (SDL_GPUSamplerMipmapMode)SDLStaticGen_LuaFieldInt(L, idx, "mipmap_mode");
    out->address_mode_u = (SDL_GPUSamplerAddressMode)SDLStaticGen_LuaFieldInt(L, idx, "address_mode_u");
    out->address_mode_v = (SDL_GPUSamplerAddressMode)SDLStaticGen_LuaFieldInt(L, idx, "address_mode_v");
    out->address_mode_w = (SDL_GPUSamplerAddressMode)SDLStaticGen_LuaFieldInt(L, idx, "address_mode_w");
    out->mip_lod_bias = (float)SDLStaticGen_LuaFieldNum(L, idx, "mip_lod_bias");
    out->max_anisotropy = (float)SDLStaticGen_LuaFieldNum(L, idx, "max_anisotropy");
    out->compare_op = (SDL_GPUCompareOp)SDLStaticGen_LuaFieldInt(L, idx, "compare_op");
    out->min_lod = (float)SDLStaticGen_LuaFieldNum(L, idx, "min_lod");
    out->max_lod = (float)SDLStaticGen_LuaFieldNum(L, idx, "max_lod");
    out->enable_anisotropy = (bool)SDLStaticGen_LuaFieldBool(L, idx, "enable_anisotropy");
    out->enable_compare = (bool)SDLStaticGen_LuaFieldBool(L, idx, "enable_compare");
    out->padding1 = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "padding1");
    out->padding2 = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "padding2");
    out->props = (SDL_PropertiesID)SDLStaticGen_LuaFieldInt(L, idx, "props");
}

static void GenRead_SDL_GPUTextureCreateInfo(lua_State *L, int idx, SDL_GPUTextureCreateInfo *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->type = (SDL_GPUTextureType)SDLStaticGen_LuaFieldInt(L, idx, "type");
    out->format = (SDL_GPUTextureFormat)SDLStaticGen_LuaFieldInt(L, idx, "format");
    out->usage = (SDL_GPUTextureUsageFlags)SDLStaticGen_LuaFieldInt(L, idx, "usage");
    out->width = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "width");
    out->height = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "height");
    out->layer_count_or_depth = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "layer_count_or_depth");
    out->num_levels = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "num_levels");
    out->sample_count = (SDL_GPUSampleCount)SDLStaticGen_LuaFieldInt(L, idx, "sample_count");
    out->props = (SDL_PropertiesID)SDLStaticGen_LuaFieldInt(L, idx, "props");
}

static void GenRead_SDL_GPUTransferBufferCreateInfo(lua_State *L, int idx, SDL_GPUTransferBufferCreateInfo *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->usage = (SDL_GPUTransferBufferUsage)SDLStaticGen_LuaFieldInt(L, idx, "usage");
    out->size = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "size");
    out->props = (SDL_PropertiesID)SDLStaticGen_LuaFieldInt(L, idx, "props");
}

static void GenRead_SDL_GPUViewport(lua_State *L, int idx, SDL_GPUViewport *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (float)SDLStaticGen_LuaFieldNum(L, idx, "x");
    out->y = (float)SDLStaticGen_LuaFieldNum(L, idx, "y");
    out->w = (float)SDLStaticGen_LuaFieldNum(L, idx, "w");
    out->h = (float)SDLStaticGen_LuaFieldNum(L, idx, "h");
    out->min_depth = (float)SDLStaticGen_LuaFieldNum(L, idx, "min_depth");
    out->max_depth = (float)SDLStaticGen_LuaFieldNum(L, idx, "max_depth");
}

static void GenRead_SDL_GUID(lua_State *L, int idx, SDL_GUID *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "data");
    if (lua_istable(L, -1)) {
        for (int gi = 0; gi < (int)(16); ++gi) {
            lua_rawgeti(L, -1, gi + 1);
            out->data[gi] = (Uint8)lua_tointeger(L, -1);
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);
}

static void GenPush_SDL_GUID(lua_State *L, const SDL_GUID *in)
{
    lua_createtable(L, 0, 1);
    lua_createtable(L, (int)(16), 0);
    for (int gi = 0; gi < (int)(16); ++gi) {
        lua_pushinteger(L, (lua_Integer)in->data[gi]);
        lua_rawseti(L, -2, gi + 1);
    }
    lua_setfield(L, -2, "data");
}

static void GenPush_SDL_PathInfo(lua_State *L, const SDL_PathInfo *in)
{
    lua_createtable(L, 0, 5);
    lua_pushinteger(L, (lua_Integer)in->type);
    lua_setfield(L, -2, "type");
    lua_pushinteger(L, (lua_Integer)in->size);
    lua_setfield(L, -2, "size");
    lua_pushinteger(L, (lua_Integer)in->create_time);
    lua_setfield(L, -2, "create_time");
    lua_pushinteger(L, (lua_Integer)in->modify_time);
    lua_setfield(L, -2, "modify_time");
    lua_pushinteger(L, (lua_Integer)in->access_time);
    lua_setfield(L, -2, "access_time");
}

static void GenRead_SDL_PixelFormatDetails(lua_State *L, int idx, SDL_PixelFormatDetails *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->format = (SDL_PixelFormat)SDLStaticGen_LuaFieldInt(L, idx, "format");
    out->bits_per_pixel = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "bits_per_pixel");
    out->bytes_per_pixel = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "bytes_per_pixel");
    lua_getfield(L, idx, "padding");
    if (lua_istable(L, -1)) {
        for (int gi = 0; gi < (int)(2); ++gi) {
            lua_rawgeti(L, -1, gi + 1);
            out->padding[gi] = (Uint8)lua_tointeger(L, -1);
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);
    out->Rmask = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "Rmask");
    out->Gmask = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "Gmask");
    out->Bmask = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "Bmask");
    out->Amask = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "Amask");
    out->Rbits = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "Rbits");
    out->Gbits = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "Gbits");
    out->Bbits = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "Bbits");
    out->Abits = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "Abits");
    out->Rshift = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "Rshift");
    out->Gshift = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "Gshift");
    out->Bshift = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "Bshift");
    out->Ashift = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "Ashift");
}

static void GenRead_SDL_Point(lua_State *L, int idx, SDL_Point *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (int)SDLStaticGen_LuaFieldInt(L, idx, "x");
    out->y = (int)SDLStaticGen_LuaFieldInt(L, idx, "y");
}

static void GenRead_SDL_Rect(lua_State *L, int idx, SDL_Rect *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (int)SDLStaticGen_LuaFieldInt(L, idx, "x");
    out->y = (int)SDLStaticGen_LuaFieldInt(L, idx, "y");
    out->w = (int)SDLStaticGen_LuaFieldInt(L, idx, "w");
    out->h = (int)SDLStaticGen_LuaFieldInt(L, idx, "h");
}

static void GenPush_SDL_Rect(lua_State *L, const SDL_Rect *in)
{
    lua_createtable(L, 0, 4);
    lua_pushinteger(L, (lua_Integer)in->x);
    lua_setfield(L, -2, "x");
    lua_pushinteger(L, (lua_Integer)in->y);
    lua_setfield(L, -2, "y");
    lua_pushinteger(L, (lua_Integer)in->w);
    lua_setfield(L, -2, "w");
    lua_pushinteger(L, (lua_Integer)in->h);
    lua_setfield(L, -2, "h");
}

static void GenDtor_SDL_DestroyWindow(void *p)
{
    SDL_Window *typed = (SDL_Window *)p;
    SDL_DestroyWindow(typed);
}

static void GenDtor_SDL_DestroyRenderer(void *p)
{
    SDL_Renderer *typed = (SDL_Renderer *)p;
    SDL_DestroyRenderer(typed);
}

static void GenDtor_SDL_DestroyTexture(void *p)
{
    SDL_Texture *typed = (SDL_Texture *)p;
    SDL_DestroyTexture(typed);
}

static void GenDtor_SDL_DestroySurface(void *p)
{
    SDL_Surface *typed = (SDL_Surface *)p;
    SDL_DestroySurface(typed);
}

static void GenDtor_SDL_DestroyAudioStream(void *p)
{
    SDL_AudioStream *typed = (SDL_AudioStream *)p;
    SDL_DestroyAudioStream(typed);
}

static void GenDtor_SDL_CloseCamera(void *p)
{
    SDL_Camera *typed = (SDL_Camera *)p;
    SDL_CloseCamera(typed);
}

static void GenDtor_SDL_CloseGamepad(void *p)
{
    SDL_Gamepad *typed = (SDL_Gamepad *)p;
    SDL_CloseGamepad(typed);
}

static void GenDtor_SDL_CloseJoystick(void *p)
{
    SDL_Joystick *typed = (SDL_Joystick *)p;
    SDL_CloseJoystick(typed);
}

static void GenDtor_SDL_CloseHaptic(void *p)
{
    SDL_Haptic *typed = (SDL_Haptic *)p;
    SDL_CloseHaptic(typed);
}

static void GenDtor_SDL_CloseSensor(void *p)
{
    SDL_Sensor *typed = (SDL_Sensor *)p;
    SDL_CloseSensor(typed);
}

static void GenDtor_SDL_DestroyCursor(void *p)
{
    SDL_Cursor *typed = (SDL_Cursor *)p;
    SDL_DestroyCursor(typed);
}

static void GenDtor_SDL_DestroyPalette(void *p)
{
    SDL_Palette *typed = (SDL_Palette *)p;
    SDL_DestroyPalette(typed);
}

static void GenDtor_SDL_CloseIO(void *p)
{
    SDL_IOStream *typed = (SDL_IOStream *)p;
    SDL_CloseIO(typed);
}

static void GenDtor_SDL_DestroyAsyncIOQueue(void *p)
{
    SDL_AsyncIOQueue *typed = (SDL_AsyncIOQueue *)p;
    SDL_DestroyAsyncIOQueue(typed);
}

static void GenDtor_SDL_CloseStorage(void *p)
{
    SDL_Storage *typed = (SDL_Storage *)p;
    SDL_CloseStorage(typed);
}

static void GenDtor_SDL_DestroyProcess(void *p)
{
    SDL_Process *typed = (SDL_Process *)p;
    SDL_DestroyProcess(typed);
}

static void GenDtor_SDL_DestroyTray(void *p)
{
    SDL_Tray *typed = (SDL_Tray *)p;
    SDL_DestroyTray(typed);
}

static void GenDtor_SDL_UnloadObject(void *p)
{
    SDL_SharedObject *typed = (SDL_SharedObject *)p;
    SDL_UnloadObject(typed);
}

static void GenDtor_SDL_DestroyEnvironment(void *p)
{
    SDL_Environment *typed = (SDL_Environment *)p;
    SDL_DestroyEnvironment(typed);
}

static void GenDtor_SDL_DestroyGPUDevice(void *p)
{
    SDL_GPUDevice *typed = (SDL_GPUDevice *)p;
    SDL_DestroyGPUDevice(typed);
}

static int GenL_SDL_AcquireCameraFrame(lua_State *L)
{
    (void)L;
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Camera");
    Uint64 io1 = (Uint64)luaL_optinteger(L, 2, 0);
    SDL_Surface * rv = SDL_AcquireCameraFrame(a0, &io1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_AcquireGPUCommandBuffer(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUCommandBuffer * rv = SDL_AcquireGPUCommandBuffer(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUCommandBuffer");
    return 1;
}

static int GenL_SDL_AddGamepadMapping(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int rv = SDL_AddGamepadMapping(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_AddGamepadMappingsFromFile(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int rv = SDL_AddGamepadMappingsFromFile(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_AddGamepadMappingsFromIO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    int rv = SDL_AddGamepadMappingsFromIO(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_AddSurfaceAlternateImage(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Surface");
    bool rv = SDL_AddSurfaceAlternateImage(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_AddVulkanRenderSemaphores(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    Sint64 a2 = (Sint64)luaL_checkinteger(L, 3);
    Sint64 a3 = (Sint64)luaL_checkinteger(L, 4);
    bool rv = SDL_AddVulkanRenderSemaphores(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_AsyncIOFromFile(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_AsyncIO * rv = SDL_AsyncIOFromFile(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_AsyncIO");
    return 1;
}

static int GenL_SDL_AttachVirtualJoystick(lua_State *L)
{
    (void)L;
    const SDL_VirtualJoystickDesc *a0 = (const SDL_VirtualJoystickDesc *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_VirtualJoystickDesc");
    SDL_JoystickID rv = SDL_AttachVirtualJoystick(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_AudioDevicePaused(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    bool rv = SDL_AudioDevicePaused(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_AudioStreamDevicePaused(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    bool rv = SDL_AudioStreamDevicePaused(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_BeginGPUComputePass(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    const SDL_GPUStorageTextureReadWriteBinding *a1 = (const SDL_GPUStorageTextureReadWriteBinding *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUStorageTextureReadWriteBinding");
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    const SDL_GPUStorageBufferReadWriteBinding *a3 = (const SDL_GPUStorageBufferReadWriteBinding *)SDLStaticGen_LuaCheckHandle(L, 4, "SDL_GPUStorageBufferReadWriteBinding");
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    SDL_GPUComputePass * rv = SDL_BeginGPUComputePass(a0, a1, a2, a3, a4);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUComputePass");
    return 1;
}

static int GenL_SDL_BeginGPUCopyPass(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    SDL_GPUCopyPass * rv = SDL_BeginGPUCopyPass(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUCopyPass");
    return 1;
}

static int GenL_SDL_BeginGPURenderPass(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    const SDL_GPUColorTargetInfo *a1 = (const SDL_GPUColorTargetInfo *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUColorTargetInfo");
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    const SDL_GPUDepthStencilTargetInfo *a3 = (const SDL_GPUDepthStencilTargetInfo *)SDLStaticGen_LuaCheckHandle(L, 4, "SDL_GPUDepthStencilTargetInfo");
    SDL_GPURenderPass * rv = SDL_BeginGPURenderPass(a0, a1, a2, a3);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPURenderPass");
    return 1;
}

static int GenL_SDL_BindAudioStream(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    SDL_AudioStream *a1 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_AudioStream");
    bool rv = SDL_BindAudioStream(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_BindGPUComputePipeline(lua_State *L)
{
    (void)L;
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUComputePass");
    SDL_GPUComputePipeline *a1 = (SDL_GPUComputePipeline *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUComputePipeline");
    SDL_BindGPUComputePipeline(a0, a1);
    return 0;
}

static int GenL_SDL_BindGPUComputeSamplers(lua_State *L)
{
    (void)L;
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUComputePass");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    const SDL_GPUTextureSamplerBinding *a2 = (const SDL_GPUTextureSamplerBinding *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_GPUTextureSamplerBinding");
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    SDL_BindGPUComputeSamplers(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDL_BindGPUFragmentSamplers(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    const SDL_GPUTextureSamplerBinding *a2 = (const SDL_GPUTextureSamplerBinding *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_GPUTextureSamplerBinding");
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    SDL_BindGPUFragmentSamplers(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDL_BindGPUGraphicsPipeline(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    SDL_GPUGraphicsPipeline *a1 = (SDL_GPUGraphicsPipeline *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUGraphicsPipeline");
    SDL_BindGPUGraphicsPipeline(a0, a1);
    return 0;
}

static int GenL_SDL_BindGPUIndexBuffer(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    const SDL_GPUBufferBinding *a1 = (const SDL_GPUBufferBinding *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUBufferBinding");
    SDL_GPUIndexElementSize a2 = (SDL_GPUIndexElementSize)luaL_checkinteger(L, 3);
    SDL_BindGPUIndexBuffer(a0, a1, a2);
    return 0;
}

static int GenL_SDL_BindGPUVertexBuffers(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    const SDL_GPUBufferBinding *a2 = (const SDL_GPUBufferBinding *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_GPUBufferBinding");
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    SDL_BindGPUVertexBuffers(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDL_BindGPUVertexSamplers(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    const SDL_GPUTextureSamplerBinding *a2 = (const SDL_GPUTextureSamplerBinding *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_GPUTextureSamplerBinding");
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    SDL_BindGPUVertexSamplers(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDL_BlitGPUTexture(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    const SDL_GPUBlitInfo *a1 = (const SDL_GPUBlitInfo *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUBlitInfo");
    SDL_BlitGPUTexture(a0, a1);
    return 0;
}

static int GenL_SDL_BlitSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (!lua_isnoneornil(L, 4)) {
        GenRead_SDL_Rect(L, 4, &tmp3);
        a3 = &tmp3;
    }
    bool rv = SDL_BlitSurface(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_BlitSurface9Grid(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    int a5 = (int)luaL_checkinteger(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    SDL_ScaleMode a7 = (SDL_ScaleMode)luaL_checkinteger(L, 8);
    SDL_Surface *a8 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 9, "SDL_Surface");
    SDL_Rect tmp9;
    const SDL_Rect *a9 = NULL;
    if (!lua_isnoneornil(L, 10)) {
        GenRead_SDL_Rect(L, 10, &tmp9);
        a9 = &tmp9;
    }
    bool rv = SDL_BlitSurface9Grid(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_BlitSurfaceScaled(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (!lua_isnoneornil(L, 4)) {
        GenRead_SDL_Rect(L, 4, &tmp3);
        a3 = &tmp3;
    }
    SDL_ScaleMode a4 = (SDL_ScaleMode)luaL_checkinteger(L, 5);
    bool rv = SDL_BlitSurfaceScaled(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_BlitSurfaceTiled(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (!lua_isnoneornil(L, 4)) {
        GenRead_SDL_Rect(L, 4, &tmp3);
        a3 = &tmp3;
    }
    bool rv = SDL_BlitSurfaceTiled(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_BlitSurfaceTiledWithScale(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    float a2 = (float)luaL_checknumber(L, 3);
    SDL_ScaleMode a3 = (SDL_ScaleMode)luaL_checkinteger(L, 4);
    SDL_Surface *a4 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 5, "SDL_Surface");
    SDL_Rect tmp5;
    const SDL_Rect *a5 = NULL;
    if (!lua_isnoneornil(L, 6)) {
        GenRead_SDL_Rect(L, 6, &tmp5);
        a5 = &tmp5;
    }
    bool rv = SDL_BlitSurfaceTiledWithScale(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_BlitSurfaceUnchecked(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (!lua_isnoneornil(L, 4)) {
        GenRead_SDL_Rect(L, 4, &tmp3);
        a3 = &tmp3;
    }
    bool rv = SDL_BlitSurfaceUnchecked(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_BlitSurfaceUncheckedScaled(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (!lua_isnoneornil(L, 4)) {
        GenRead_SDL_Rect(L, 4, &tmp3);
        a3 = &tmp3;
    }
    SDL_ScaleMode a4 = (SDL_ScaleMode)luaL_checkinteger(L, 5);
    bool rv = SDL_BlitSurfaceUncheckedScaled(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_CalculateGPUTextureFormatSize(lua_State *L)
{
    (void)L;
    SDL_GPUTextureFormat a0 = (SDL_GPUTextureFormat)luaL_checkinteger(L, 1);
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    Uint32 rv = SDL_CalculateGPUTextureFormatSize(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_CancelGPUCommandBuffer(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    bool rv = SDL_CancelGPUCommandBuffer(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_CaptureMouse(lua_State *L)
{
    (void)L;
    bool a0 = (bool)lua_toboolean(L, 1);
    bool rv = SDL_CaptureMouse(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ClaimWindowForGPUDevice(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Window");
    bool rv = SDL_ClaimWindowForGPUDevice(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ClearAudioStream(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    bool rv = SDL_ClearAudioStream(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ClearClipboardData(lua_State *L)
{
    (void)L;
    bool rv = SDL_ClearClipboardData();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ClearComposition(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_ClearComposition(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ClearError(lua_State *L)
{
    (void)L;
    bool rv = SDL_ClearError();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ClearProperty(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_ClearProperty(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ClearSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    bool rv = SDL_ClearSurface(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ClickTrayEntry(lua_State *L)
{
    (void)L;
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayEntry");
    SDL_ClickTrayEntry(a0);
    return 0;
}

static int GenL_SDL_CloseAudioDevice(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    SDL_CloseAudioDevice(a0);
    return 0;
}

static int GenL_SDL_CloseCamera(lua_State *L)
{
    (void)L;
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Camera");
    SDL_CloseCamera(a0);
    return 0;
}

static int GenL_SDL_CloseGamepad(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Gamepad");
    SDL_CloseGamepad(a0);
    return 0;
}

static int GenL_SDL_CloseHaptic(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Haptic");
    SDL_CloseHaptic(a0);
    return 0;
}

static int GenL_SDL_CloseIO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_IOStream");
    bool rv = SDL_CloseIO(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_CloseJoystick(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Joystick");
    SDL_CloseJoystick(a0);
    return 0;
}

static int GenL_SDL_CloseSensor(lua_State *L)
{
    (void)L;
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Sensor");
    SDL_CloseSensor(a0);
    return 0;
}

static int GenL_SDL_CloseStorage(lua_State *L)
{
    (void)L;
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Storage");
    bool rv = SDL_CloseStorage(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_CompareAndSwapAtomicInt(lua_State *L)
{
    (void)L;
    SDL_AtomicInt out0;
    memset(&out0, 0, sizeof(out0));
    int a1 = (int)luaL_checkinteger(L, 1);
    int a2 = (int)luaL_checkinteger(L, 2);
    bool rv = SDL_CompareAndSwapAtomicInt(&out0, a1, a2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_AtomicInt(L, &out0);
    return 2;
}

static int GenL_SDL_CompareAndSwapAtomicU32(lua_State *L)
{
    (void)L;
    SDL_AtomicU32 out0;
    memset(&out0, 0, sizeof(out0));
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 1);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 2);
    bool rv = SDL_CompareAndSwapAtomicU32(&out0, a1, a2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_AtomicU32(L, &out0);
    return 2;
}

static int GenL_SDL_ComposeCustomBlendMode(lua_State *L)
{
    (void)L;
    SDL_BlendFactor a0 = (SDL_BlendFactor)luaL_checkinteger(L, 1);
    SDL_BlendFactor a1 = (SDL_BlendFactor)luaL_checkinteger(L, 2);
    SDL_BlendOperation a2 = (SDL_BlendOperation)luaL_checkinteger(L, 3);
    SDL_BlendFactor a3 = (SDL_BlendFactor)luaL_checkinteger(L, 4);
    SDL_BlendFactor a4 = (SDL_BlendFactor)luaL_checkinteger(L, 5);
    SDL_BlendOperation a5 = (SDL_BlendOperation)luaL_checkinteger(L, 6);
    SDL_BlendMode rv = SDL_ComposeCustomBlendMode(a0, a1, a2, a3, a4, a5);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_ConvertEventToRenderCoordinates(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Event *a1 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Event");
    bool rv = SDL_ConvertEventToRenderCoordinates(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ConvertSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_PixelFormat a1 = (SDL_PixelFormat)luaL_checkinteger(L, 2);
    SDL_Surface * rv = SDL_ConvertSurface(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_SDL_ConvertSurfaceAndColorspace(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_PixelFormat a1 = (SDL_PixelFormat)luaL_checkinteger(L, 2);
    SDL_Palette *a2 = (SDL_Palette *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_Palette");
    SDL_Colorspace a3 = (SDL_Colorspace)luaL_checkinteger(L, 4);
    SDL_PropertiesID a4 = (SDL_PropertiesID)luaL_checkinteger(L, 5);
    SDL_Surface * rv = SDL_ConvertSurfaceAndColorspace(a0, a1, a2, a3, a4);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_SDL_CopyFile(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_CopyFile(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_CopyGPUBufferToBuffer(lua_State *L)
{
    (void)L;
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCopyPass");
    const SDL_GPUBufferLocation *a1 = (const SDL_GPUBufferLocation *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUBufferLocation");
    const SDL_GPUBufferLocation *a2 = (const SDL_GPUBufferLocation *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_GPUBufferLocation");
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    bool a4 = (bool)lua_toboolean(L, 5);
    SDL_CopyGPUBufferToBuffer(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_SDL_CopyGPUTextureToTexture(lua_State *L)
{
    (void)L;
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCopyPass");
    const SDL_GPUTextureLocation *a1 = (const SDL_GPUTextureLocation *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUTextureLocation");
    const SDL_GPUTextureLocation *a2 = (const SDL_GPUTextureLocation *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_GPUTextureLocation");
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    Uint32 a5 = (Uint32)luaL_checkinteger(L, 6);
    bool a6 = (bool)lua_toboolean(L, 7);
    SDL_CopyGPUTextureToTexture(a0, a1, a2, a3, a4, a5, a6);
    return 0;
}

static int GenL_SDL_CopyProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    SDL_PropertiesID a1 = (SDL_PropertiesID)luaL_checkinteger(L, 2);
    bool rv = SDL_CopyProperties(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_CopyStorageFile(lua_State *L)
{
    (void)L;
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Storage");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDL_CopyStorageFile(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_CreateAnimatedCursor(lua_State *L)
{
    (void)L;
    SDL_CursorFrameInfo *a0 = (SDL_CursorFrameInfo *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_CursorFrameInfo");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    SDL_Cursor * rv = SDL_CreateAnimatedCursor(a0, a1, a2, a3);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Cursor");
    return 1;
}

static int GenL_SDL_CreateAsyncIOQueue(lua_State *L)
{
    (void)L;
    SDL_AsyncIOQueue * rv = SDL_CreateAsyncIOQueue();
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_AsyncIOQueue", GenDtor_SDL_DestroyAsyncIOQueue);
    return 1;
}

static int GenL_SDL_CreateAudioStream(lua_State *L)
{
    (void)L;
    SDL_AudioSpec tmp0;
    const SDL_AudioSpec *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_AudioSpec(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_AudioSpec tmp1;
    const SDL_AudioSpec *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_AudioSpec(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_AudioStream * rv = SDL_CreateAudioStream(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_AudioStream", GenDtor_SDL_DestroyAudioStream);
    return 1;
}

static int GenL_SDL_CreateColorCursor(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDL_Cursor * rv = SDL_CreateColorCursor(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Cursor", GenDtor_SDL_DestroyCursor);
    return 1;
}

static int GenL_SDL_CreateDirectory(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDL_CreateDirectory(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_CreateEnvironment(lua_State *L)
{
    (void)L;
    bool a0 = (bool)lua_toboolean(L, 1);
    SDL_Environment * rv = SDL_CreateEnvironment(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Environment", GenDtor_SDL_DestroyEnvironment);
    return 1;
}

static int GenL_SDL_CreateGPUBuffer(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUBufferCreateInfo tmp1;
    const SDL_GPUBufferCreateInfo *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_GPUBufferCreateInfo(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_GPUBuffer * rv = SDL_CreateGPUBuffer(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUBuffer");
    return 1;
}

static int GenL_SDL_CreateGPUComputePipeline(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    const SDL_GPUComputePipelineCreateInfo *a1 = (const SDL_GPUComputePipelineCreateInfo *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUComputePipelineCreateInfo");
    SDL_GPUComputePipeline * rv = SDL_CreateGPUComputePipeline(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUComputePipeline");
    return 1;
}

static int GenL_SDL_CreateGPUDevice(lua_State *L)
{
    (void)L;
    SDL_GPUShaderFormat a0 = (SDL_GPUShaderFormat)luaL_checkinteger(L, 1);
    bool a1 = (bool)lua_toboolean(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    SDL_GPUDevice * rv = SDL_CreateGPUDevice(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_GPUDevice", GenDtor_SDL_DestroyGPUDevice);
    return 1;
}

static int GenL_SDL_CreateGPUDeviceWithProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    SDL_GPUDevice * rv = SDL_CreateGPUDeviceWithProperties(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_GPUDevice", GenDtor_SDL_DestroyGPUDevice);
    return 1;
}

static int GenL_SDL_CreateGPUGraphicsPipeline(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    const SDL_GPUGraphicsPipelineCreateInfo *a1 = (const SDL_GPUGraphicsPipelineCreateInfo *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUGraphicsPipelineCreateInfo");
    SDL_GPUGraphicsPipeline * rv = SDL_CreateGPUGraphicsPipeline(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUGraphicsPipeline");
    return 1;
}

static int GenL_SDL_CreateGPURenderState(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    const SDL_GPURenderStateCreateInfo *a1 = (const SDL_GPURenderStateCreateInfo *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPURenderStateCreateInfo");
    SDL_GPURenderState * rv = SDL_CreateGPURenderState(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPURenderState");
    return 1;
}

static int GenL_SDL_CreateGPURenderer(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Window");
    SDL_Renderer * rv = SDL_CreateGPURenderer(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Renderer");
    return 1;
}

static int GenL_SDL_CreateGPUSampler(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUSamplerCreateInfo tmp1;
    const SDL_GPUSamplerCreateInfo *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_GPUSamplerCreateInfo(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_GPUSampler * rv = SDL_CreateGPUSampler(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUSampler");
    return 1;
}

static int GenL_SDL_CreateGPUShader(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    const SDL_GPUShaderCreateInfo *a1 = (const SDL_GPUShaderCreateInfo *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUShaderCreateInfo");
    SDL_GPUShader * rv = SDL_CreateGPUShader(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUShader");
    return 1;
}

static int GenL_SDL_CreateGPUTexture(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUTextureCreateInfo tmp1;
    const SDL_GPUTextureCreateInfo *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_GPUTextureCreateInfo(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_GPUTexture * rv = SDL_CreateGPUTexture(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUTexture");
    return 1;
}

static int GenL_SDL_CreateGPUTransferBuffer(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUTransferBufferCreateInfo tmp1;
    const SDL_GPUTransferBufferCreateInfo *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_GPUTransferBufferCreateInfo(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_GPUTransferBuffer * rv = SDL_CreateGPUTransferBuffer(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUTransferBuffer");
    return 1;
}

static int GenL_SDL_CreateHapticEffect(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    const SDL_HapticEffect *a1 = (const SDL_HapticEffect *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_HapticEffect");
    SDL_HapticEffectID rv = SDL_CreateHapticEffect(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_CreatePalette(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    SDL_Palette * rv = SDL_CreatePalette(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Palette", GenDtor_SDL_DestroyPalette);
    return 1;
}

static int GenL_SDL_CreatePopupWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    SDL_WindowFlags a5 = (SDL_WindowFlags)luaL_checkinteger(L, 6);
    SDL_Window * rv = SDL_CreatePopupWindow(a0, a1, a2, a3, a4, a5);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Window", GenDtor_SDL_DestroyWindow);
    return 1;
}

static int GenL_SDL_CreateProcessWithProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    SDL_Process * rv = SDL_CreateProcessWithProperties(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Process", GenDtor_SDL_DestroyProcess);
    return 1;
}

static int GenL_SDL_CreateProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID rv = SDL_CreateProperties();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_CreateRenderer(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_Renderer * rv = SDL_CreateRenderer(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Renderer", GenDtor_SDL_DestroyRenderer);
    return 1;
}

static int GenL_SDL_CreateRendererWithProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    SDL_Renderer * rv = SDL_CreateRendererWithProperties(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Renderer", GenDtor_SDL_DestroyRenderer);
    return 1;
}

static int GenL_SDL_CreateSoftwareRenderer(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Renderer * rv = SDL_CreateSoftwareRenderer(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Renderer", GenDtor_SDL_DestroyRenderer);
    return 1;
}

static int GenL_SDL_CreateStorageDirectory(lua_State *L)
{
    (void)L;
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Storage");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_CreateStorageDirectory(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_CreateSurface(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    SDL_PixelFormat a2 = (SDL_PixelFormat)luaL_checkinteger(L, 3);
    SDL_Surface * rv = SDL_CreateSurface(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_SDL_CreateSurfacePalette(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Palette * rv = SDL_CreateSurfacePalette(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Palette");
    return 1;
}

static int GenL_SDL_CreateSystemCursor(lua_State *L)
{
    (void)L;
    SDL_SystemCursor a0 = (SDL_SystemCursor)luaL_checkinteger(L, 1);
    SDL_Cursor * rv = SDL_CreateSystemCursor(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Cursor", GenDtor_SDL_DestroyCursor);
    return 1;
}

static int GenL_SDL_CreateTexture(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_PixelFormat a1 = (SDL_PixelFormat)luaL_checkinteger(L, 2);
    SDL_TextureAccess a2 = (SDL_TextureAccess)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    SDL_Texture * rv = SDL_CreateTexture(a0, a1, a2, a3, a4);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Texture", GenDtor_SDL_DestroyTexture);
    return 1;
}

static int GenL_SDL_CreateTextureFromSurface(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Surface");
    SDL_Texture * rv = SDL_CreateTextureFromSurface(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Texture", GenDtor_SDL_DestroyTexture);
    return 1;
}

static int GenL_SDL_CreateTextureWithProperties(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_PropertiesID a1 = (SDL_PropertiesID)luaL_checkinteger(L, 2);
    SDL_Texture * rv = SDL_CreateTextureWithProperties(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Texture", GenDtor_SDL_DestroyTexture);
    return 1;
}

static int GenL_SDL_CreateTray(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_Tray * rv = SDL_CreateTray(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Tray", GenDtor_SDL_DestroyTray);
    return 1;
}

static int GenL_SDL_CreateTrayMenu(lua_State *L)
{
    (void)L;
    SDL_Tray *a0 = (SDL_Tray *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Tray");
    SDL_TrayMenu * rv = SDL_CreateTrayMenu(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_TrayMenu");
    return 1;
}

static int GenL_SDL_CreateTraySubmenu(lua_State *L)
{
    (void)L;
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayEntry");
    SDL_TrayMenu * rv = SDL_CreateTraySubmenu(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_TrayMenu");
    return 1;
}

static int GenL_SDL_CreateWindow(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDL_WindowFlags a3 = (SDL_WindowFlags)luaL_checkinteger(L, 4);
    SDL_Window * rv = SDL_CreateWindow(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Window", GenDtor_SDL_DestroyWindow);
    return 1;
}

static int GenL_SDL_CreateWindowWithProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    SDL_Window * rv = SDL_CreateWindowWithProperties(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Window", GenDtor_SDL_DestroyWindow);
    return 1;
}

static int GenL_SDL_CursorVisible(lua_State *L)
{
    (void)L;
    bool rv = SDL_CursorVisible();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_DateTimeToTime(lua_State *L)
{
    (void)L;
    SDL_DateTime tmp0;
    const SDL_DateTime *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_DateTime(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_Time io1 = (SDL_Time)luaL_optinteger(L, 2, 0);
    bool rv = SDL_DateTimeToTime(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_Delay(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    SDL_Delay(a0);
    return 0;
}

static int GenL_SDL_DelayNS(lua_State *L)
{
    (void)L;
    Uint64 a0 = (Uint64)luaL_checkinteger(L, 1);
    SDL_DelayNS(a0);
    return 0;
}

static int GenL_SDL_DelayPrecise(lua_State *L)
{
    (void)L;
    Uint64 a0 = (Uint64)luaL_checkinteger(L, 1);
    SDL_DelayPrecise(a0);
    return 0;
}

static int GenL_SDL_DestroyAsyncIOQueue(lua_State *L)
{
    (void)L;
    SDL_AsyncIOQueue *a0 = (SDL_AsyncIOQueue *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_AsyncIOQueue");
    SDL_DestroyAsyncIOQueue(a0);
    return 0;
}

static int GenL_SDL_DestroyAudioStream(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_AudioStream");
    SDL_DestroyAudioStream(a0);
    return 0;
}

static int GenL_SDL_DestroyCursor(lua_State *L)
{
    (void)L;
    SDL_Cursor *a0 = (SDL_Cursor *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Cursor");
    SDL_DestroyCursor(a0);
    return 0;
}

static int GenL_SDL_DestroyEnvironment(lua_State *L)
{
    (void)L;
    SDL_Environment *a0 = (SDL_Environment *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Environment");
    SDL_DestroyEnvironment(a0);
    return 0;
}

static int GenL_SDL_DestroyGPUDevice(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_GPUDevice");
    SDL_DestroyGPUDevice(a0);
    return 0;
}

static int GenL_SDL_DestroyGPURenderState(lua_State *L)
{
    (void)L;
    SDL_GPURenderState *a0 = (SDL_GPURenderState *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderState");
    SDL_DestroyGPURenderState(a0);
    return 0;
}

static int GenL_SDL_DestroyHapticEffect(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    SDL_HapticEffectID a1 = (SDL_HapticEffectID)luaL_checkinteger(L, 2);
    SDL_DestroyHapticEffect(a0, a1);
    return 0;
}

static int GenL_SDL_DestroyPalette(lua_State *L)
{
    (void)L;
    SDL_Palette *a0 = (SDL_Palette *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Palette");
    SDL_DestroyPalette(a0);
    return 0;
}

static int GenL_SDL_DestroyProcess(lua_State *L)
{
    (void)L;
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Process");
    SDL_DestroyProcess(a0);
    return 0;
}

static int GenL_SDL_DestroyProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    SDL_DestroyProperties(a0);
    return 0;
}

static int GenL_SDL_DestroyRenderer(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Renderer");
    SDL_DestroyRenderer(a0);
    return 0;
}

static int GenL_SDL_DestroySurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Surface");
    SDL_DestroySurface(a0);
    return 0;
}

static int GenL_SDL_DestroyTexture(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Texture");
    SDL_DestroyTexture(a0);
    return 0;
}

static int GenL_SDL_DestroyTray(lua_State *L)
{
    (void)L;
    SDL_Tray *a0 = (SDL_Tray *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Tray");
    SDL_DestroyTray(a0);
    return 0;
}

static int GenL_SDL_DestroyWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_Window");
    SDL_DestroyWindow(a0);
    return 0;
}

static int GenL_SDL_DestroyWindowSurface(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_DestroyWindowSurface(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_DetachVirtualJoystick(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    bool rv = SDL_DetachVirtualJoystick(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_DisableScreenSaver(lua_State *L)
{
    (void)L;
    bool rv = SDL_DisableScreenSaver();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_DispatchGPUCompute(lua_State *L)
{
    (void)L;
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUComputePass");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    SDL_DispatchGPUCompute(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDL_DispatchGPUComputeIndirect(lua_State *L)
{
    (void)L;
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUComputePass");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUBuffer");
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    SDL_DispatchGPUComputeIndirect(a0, a1, a2);
    return 0;
}

static int GenL_SDL_DownloadFromGPUBuffer(lua_State *L)
{
    (void)L;
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCopyPass");
    const SDL_GPUBufferRegion *a1 = (const SDL_GPUBufferRegion *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUBufferRegion");
    const SDL_GPUTransferBufferLocation *a2 = (const SDL_GPUTransferBufferLocation *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_GPUTransferBufferLocation");
    SDL_DownloadFromGPUBuffer(a0, a1, a2);
    return 0;
}

static int GenL_SDL_DownloadFromGPUTexture(lua_State *L)
{
    (void)L;
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCopyPass");
    const SDL_GPUTextureRegion *a1 = (const SDL_GPUTextureRegion *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUTextureRegion");
    const SDL_GPUTextureTransferInfo *a2 = (const SDL_GPUTextureTransferInfo *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_GPUTextureTransferInfo");
    SDL_DownloadFromGPUTexture(a0, a1, a2);
    return 0;
}

static int GenL_SDL_DrawGPUIndexedPrimitives(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    Sint32 a4 = (Sint32)luaL_checkinteger(L, 5);
    Uint32 a5 = (Uint32)luaL_checkinteger(L, 6);
    SDL_DrawGPUIndexedPrimitives(a0, a1, a2, a3, a4, a5);
    return 0;
}

static int GenL_SDL_DrawGPUIndexedPrimitivesIndirect(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUBuffer");
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    SDL_DrawGPUIndexedPrimitivesIndirect(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDL_DrawGPUPrimitives(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    SDL_DrawGPUPrimitives(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_SDL_DrawGPUPrimitivesIndirect(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUBuffer");
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    SDL_DrawGPUPrimitivesIndirect(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDL_DuplicateSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Surface * rv = SDL_DuplicateSurface(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_SDL_EnableScreenSaver(lua_State *L)
{
    (void)L;
    bool rv = SDL_EnableScreenSaver();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_EndGPUComputePass(lua_State *L)
{
    (void)L;
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUComputePass");
    SDL_EndGPUComputePass(a0);
    return 0;
}

static int GenL_SDL_EndGPUCopyPass(lua_State *L)
{
    (void)L;
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCopyPass");
    SDL_EndGPUCopyPass(a0);
    return 0;
}

static int GenL_SDL_EndGPURenderPass(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    SDL_EndGPURenderPass(a0);
    return 0;
}

static int GenL_SDL_EventEnabled(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    bool rv = SDL_EventEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_FillSurfaceRect(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    bool rv = SDL_FillSurfaceRect(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_FillSurfaceRects(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    bool rv = SDL_FillSurfaceRects(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_FlashWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_FlashOperation a1 = (SDL_FlashOperation)luaL_checkinteger(L, 2);
    bool rv = SDL_FlashWindow(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_FlipSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_FlipMode a1 = (SDL_FlipMode)luaL_checkinteger(L, 2);
    bool rv = SDL_FlipSurface(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_FlushAudioStream(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    bool rv = SDL_FlushAudioStream(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_FlushEvent(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    SDL_FlushEvent(a0);
    return 0;
}

static int GenL_SDL_FlushEvents(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    SDL_FlushEvents(a0, a1);
    return 0;
}

static int GenL_SDL_FlushIO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = SDL_FlushIO(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_FlushRenderer(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    bool rv = SDL_FlushRenderer(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GL_ExtensionSupported(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDL_GL_ExtensionSupported(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GL_GetAttribute(lua_State *L)
{
    (void)L;
    SDL_GLAttr a0 = (SDL_GLAttr)luaL_checkinteger(L, 1);
    int io1 = (int)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GL_GetAttribute(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GL_GetCurrentWindow(lua_State *L)
{
    (void)L;
    SDL_Window * rv = SDL_GL_GetCurrentWindow();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Window");
    return 1;
}

static int GenL_SDL_GL_GetSwapInterval(lua_State *L)
{
    (void)L;
    int io0 = (int)luaL_optinteger(L, 1, 0);
    bool rv = SDL_GL_GetSwapInterval(&io0);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io0);
    return 2;
}

static int GenL_SDL_GL_LoadLibrary(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDL_GL_LoadLibrary(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GL_ResetAttributes(lua_State *L)
{
    (void)L;
    SDL_GL_ResetAttributes();
    return 0;
}

static int GenL_SDL_GL_SetAttribute(lua_State *L)
{
    (void)L;
    SDL_GLAttr a0 = (SDL_GLAttr)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDL_GL_SetAttribute(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GL_SetSwapInterval(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    bool rv = SDL_GL_SetSwapInterval(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GL_SwapWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_GL_SwapWindow(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GL_UnloadLibrary(lua_State *L)
{
    (void)L;
    SDL_GL_UnloadLibrary();
    return 0;
}

static int GenL_SDL_GPUSupportsProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    bool rv = SDL_GPUSupportsProperties(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GPUSupportsShaderFormats(lua_State *L)
{
    (void)L;
    SDL_GPUShaderFormat a0 = (SDL_GPUShaderFormat)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_GPUSupportsShaderFormats(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GPUTextureFormatTexelBlockSize(lua_State *L)
{
    (void)L;
    SDL_GPUTextureFormat a0 = (SDL_GPUTextureFormat)luaL_checkinteger(L, 1);
    Uint32 rv = SDL_GPUTextureFormatTexelBlockSize(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GPUTextureSupportsFormat(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUTextureFormat a1 = (SDL_GPUTextureFormat)luaL_checkinteger(L, 2);
    SDL_GPUTextureType a2 = (SDL_GPUTextureType)luaL_checkinteger(L, 3);
    SDL_GPUTextureUsageFlags a3 = (SDL_GPUTextureUsageFlags)luaL_checkinteger(L, 4);
    bool rv = SDL_GPUTextureSupportsFormat(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GPUTextureSupportsSampleCount(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUTextureFormat a1 = (SDL_GPUTextureFormat)luaL_checkinteger(L, 2);
    SDL_GPUSampleCount a2 = (SDL_GPUSampleCount)luaL_checkinteger(L, 3);
    bool rv = SDL_GPUTextureSupportsSampleCount(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GamepadConnected(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    bool rv = SDL_GamepadConnected(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GamepadEventsEnabled(lua_State *L)
{
    (void)L;
    bool rv = SDL_GamepadEventsEnabled();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GamepadHasAxis(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_GamepadAxis a1 = (SDL_GamepadAxis)luaL_checkinteger(L, 2);
    bool rv = SDL_GamepadHasAxis(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GamepadHasButton(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_GamepadButton a1 = (SDL_GamepadButton)luaL_checkinteger(L, 2);
    bool rv = SDL_GamepadHasButton(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GamepadHasSensor(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_SensorType a1 = (SDL_SensorType)luaL_checkinteger(L, 2);
    bool rv = SDL_GamepadHasSensor(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GamepadSensorEnabled(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_SensorType a1 = (SDL_SensorType)luaL_checkinteger(L, 2);
    bool rv = SDL_GamepadSensorEnabled(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GenerateMipmapsForGPUTexture(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUTexture");
    SDL_GenerateMipmapsForGPUTexture(a0, a1);
    return 0;
}

static int GenL_SDL_GetAppMetadataProperty(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char * rv = SDL_GetAppMetadataProperty(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetAssertionReport(lua_State *L)
{
    (void)L;
    const SDL_AssertData * rv = SDL_GetAssertionReport();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_AssertData");
    return 1;
}

static int GenL_SDL_GetAsyncIOResult(lua_State *L)
{
    (void)L;
    SDL_AsyncIOQueue *a0 = (SDL_AsyncIOQueue *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AsyncIOQueue");
    SDL_AsyncIOOutcome *a1 = (SDL_AsyncIOOutcome *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_AsyncIOOutcome");
    bool rv = SDL_GetAsyncIOResult(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetAsyncIOSize(lua_State *L)
{
    (void)L;
    SDL_AsyncIO *a0 = (SDL_AsyncIO *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AsyncIO");
    Sint64 rv = SDL_GetAsyncIOSize(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetAudioDeviceFormat(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    SDL_AudioSpec out1;
    memset(&out1, 0, sizeof(out1));
    int io2 = (int)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetAudioDeviceFormat(a0, &out1, &io2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_AudioSpec(L, &out1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_SDL_GetAudioDeviceGain(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    float rv = SDL_GetAudioDeviceGain(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDL_GetAudioDeviceName(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetAudioDeviceName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetAudioDriver(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetAudioDriver(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetAudioFormatName(lua_State *L)
{
    (void)L;
    SDL_AudioFormat a0 = (SDL_AudioFormat)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetAudioFormatName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetAudioStreamAvailable(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    int rv = SDL_GetAudioStreamAvailable(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetAudioStreamDevice(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    SDL_AudioDeviceID rv = SDL_GetAudioStreamDevice(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetAudioStreamFormat(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    SDL_AudioSpec out1;
    memset(&out1, 0, sizeof(out1));
    SDL_AudioSpec out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetAudioStreamFormat(a0, &out1, &out2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_AudioSpec(L, &out1);
    GenPush_SDL_AudioSpec(L, &out2);
    return 3;
}

static int GenL_SDL_GetAudioStreamFrequencyRatio(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    float rv = SDL_GetAudioStreamFrequencyRatio(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDL_GetAudioStreamGain(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    float rv = SDL_GetAudioStreamGain(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDL_GetAudioStreamProperties(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    SDL_PropertiesID rv = SDL_GetAudioStreamProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetAudioStreamQueued(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    int rv = SDL_GetAudioStreamQueued(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetBasePath(lua_State *L)
{
    (void)L;
    const char * rv = SDL_GetBasePath();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetBooleanProperty(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = SDL_GetBooleanProperty(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetCPUCacheLineSize(lua_State *L)
{
    (void)L;
    int rv = SDL_GetCPUCacheLineSize();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetCameraDriver(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetCameraDriver(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetCameraFormat(lua_State *L)
{
    (void)L;
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Camera");
    SDL_CameraSpec out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetCameraFormat(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_CameraSpec(L, &out1);
    return 2;
}

static int GenL_SDL_GetCameraID(lua_State *L)
{
    (void)L;
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Camera");
    SDL_CameraID rv = SDL_GetCameraID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetCameraName(lua_State *L)
{
    (void)L;
    SDL_CameraID a0 = (SDL_CameraID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetCameraName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetCameraPermissionState(lua_State *L)
{
    (void)L;
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Camera");
    SDL_CameraPermissionState rv = SDL_GetCameraPermissionState(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetCameraPosition(lua_State *L)
{
    (void)L;
    SDL_CameraID a0 = (SDL_CameraID)luaL_checkinteger(L, 1);
    SDL_CameraPosition rv = SDL_GetCameraPosition(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetCameraProperties(lua_State *L)
{
    (void)L;
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Camera");
    SDL_PropertiesID rv = SDL_GetCameraProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetClipboardText(lua_State *L)
{
    (void)L;
    char * rv = SDL_GetClipboardText();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDL_GetClosestFullscreenDisplayMode(lua_State *L)
{
    (void)L;
    SDL_DisplayID a0 = (SDL_DisplayID)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    bool a4 = (bool)lua_toboolean(L, 5);
    SDL_DisplayMode *a5 = (SDL_DisplayMode *)SDLStaticGen_LuaCheckHandle(L, 6, "SDL_DisplayMode");
    bool rv = SDL_GetClosestFullscreenDisplayMode(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetCurrentAudioDriver(lua_State *L)
{
    (void)L;
    const char * rv = SDL_GetCurrentAudioDriver();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetCurrentCameraDriver(lua_State *L)
{
    (void)L;
    const char * rv = SDL_GetCurrentCameraDriver();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetCurrentDirectory(lua_State *L)
{
    (void)L;
    char * rv = SDL_GetCurrentDirectory();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDL_GetCurrentDisplayMode(lua_State *L)
{
    (void)L;
    SDL_DisplayID a0 = (SDL_DisplayID)luaL_checkinteger(L, 1);
    const SDL_DisplayMode * rv = SDL_GetCurrentDisplayMode(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_DisplayMode");
    return 1;
}

static int GenL_SDL_GetCurrentDisplayOrientation(lua_State *L)
{
    (void)L;
    SDL_DisplayID a0 = (SDL_DisplayID)luaL_checkinteger(L, 1);
    SDL_DisplayOrientation rv = SDL_GetCurrentDisplayOrientation(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetCurrentRenderOutputSize(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    bool rv = SDL_GetCurrentRenderOutputSize(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_SDL_GetCurrentTime(lua_State *L)
{
    (void)L;
    SDL_Time io0 = (SDL_Time)luaL_optinteger(L, 1, 0);
    bool rv = SDL_GetCurrentTime(&io0);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io0);
    return 2;
}

static int GenL_SDL_GetCurrentVideoDriver(lua_State *L)
{
    (void)L;
    const char * rv = SDL_GetCurrentVideoDriver();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetCursor(lua_State *L)
{
    (void)L;
    SDL_Cursor * rv = SDL_GetCursor();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Cursor");
    return 1;
}

static int GenL_SDL_GetDateTimeLocalePreferences(lua_State *L)
{
    (void)L;
    SDL_DateFormat io0 = (SDL_DateFormat)luaL_optinteger(L, 1, 0);
    SDL_TimeFormat io1 = (SDL_TimeFormat)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetDateTimeLocalePreferences(&io0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io0);
    lua_pushinteger(L, (lua_Integer)io1);
    return 3;
}

static int GenL_SDL_GetDayOfWeek(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int rv = SDL_GetDayOfWeek(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetDayOfYear(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int rv = SDL_GetDayOfYear(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetDaysInMonth(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int rv = SDL_GetDaysInMonth(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetDefaultCursor(lua_State *L)
{
    (void)L;
    SDL_Cursor * rv = SDL_GetDefaultCursor();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Cursor");
    return 1;
}

static int GenL_SDL_GetDefaultTextureScaleMode(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_ScaleMode io1 = (SDL_ScaleMode)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetDefaultTextureScaleMode(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetDesktopDisplayMode(lua_State *L)
{
    (void)L;
    SDL_DisplayID a0 = (SDL_DisplayID)luaL_checkinteger(L, 1);
    const SDL_DisplayMode * rv = SDL_GetDesktopDisplayMode(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_DisplayMode");
    return 1;
}

static int GenL_SDL_GetDisplayBounds(lua_State *L)
{
    (void)L;
    SDL_DisplayID a0 = (SDL_DisplayID)luaL_checkinteger(L, 1);
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetDisplayBounds(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_Rect(L, &out1);
    return 2;
}

static int GenL_SDL_GetDisplayContentScale(lua_State *L)
{
    (void)L;
    SDL_DisplayID a0 = (SDL_DisplayID)luaL_checkinteger(L, 1);
    float rv = SDL_GetDisplayContentScale(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDL_GetDisplayForPoint(lua_State *L)
{
    (void)L;
    SDL_Point tmp0;
    const SDL_Point *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_Point(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_DisplayID rv = SDL_GetDisplayForPoint(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetDisplayForRect(lua_State *L)
{
    (void)L;
    SDL_Rect tmp0;
    const SDL_Rect *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_Rect(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_DisplayID rv = SDL_GetDisplayForRect(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetDisplayForWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_DisplayID rv = SDL_GetDisplayForWindow(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetDisplayName(lua_State *L)
{
    (void)L;
    SDL_DisplayID a0 = (SDL_DisplayID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetDisplayName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetDisplayProperties(lua_State *L)
{
    (void)L;
    SDL_DisplayID a0 = (SDL_DisplayID)luaL_checkinteger(L, 1);
    SDL_PropertiesID rv = SDL_GetDisplayProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetDisplayUsableBounds(lua_State *L)
{
    (void)L;
    SDL_DisplayID a0 = (SDL_DisplayID)luaL_checkinteger(L, 1);
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetDisplayUsableBounds(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_Rect(L, &out1);
    return 2;
}

static int GenL_SDL_GetEnvironment(lua_State *L)
{
    (void)L;
    SDL_Environment * rv = SDL_GetEnvironment();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Environment");
    return 1;
}

static int GenL_SDL_GetEnvironmentVariable(lua_State *L)
{
    (void)L;
    SDL_Environment *a0 = (SDL_Environment *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Environment");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char * rv = SDL_GetEnvironmentVariable(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetError(lua_State *L)
{
    (void)L;
    const char * rv = SDL_GetError();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetFloatProperty(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float rv = SDL_GetFloatProperty(a0, a1, a2);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDL_GetGPUDeviceDriver(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    const char * rv = SDL_GetGPUDeviceDriver(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGPUDeviceProperties(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_PropertiesID rv = SDL_GetGPUDeviceProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGPUDriver(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetGPUDriver(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGPURendererDevice(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_GPUDevice * rv = SDL_GetGPURendererDevice(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUDevice");
    return 1;
}

static int GenL_SDL_GetGPUShaderFormats(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUShaderFormat rv = SDL_GetGPUShaderFormats(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGPUSwapchainTextureFormat(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Window");
    SDL_GPUTextureFormat rv = SDL_GetGPUSwapchainTextureFormat(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGPUTextureFormatFromPixelFormat(lua_State *L)
{
    (void)L;
    SDL_PixelFormat a0 = (SDL_PixelFormat)luaL_checkinteger(L, 1);
    SDL_GPUTextureFormat rv = SDL_GetGPUTextureFormatFromPixelFormat(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadAppleSFSymbolsNameForAxis(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_GamepadAxis a1 = (SDL_GamepadAxis)luaL_checkinteger(L, 2);
    const char * rv = SDL_GetGamepadAppleSFSymbolsNameForAxis(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGamepadAppleSFSymbolsNameForButton(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_GamepadButton a1 = (SDL_GamepadButton)luaL_checkinteger(L, 2);
    const char * rv = SDL_GetGamepadAppleSFSymbolsNameForButton(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGamepadAxis(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_GamepadAxis a1 = (SDL_GamepadAxis)luaL_checkinteger(L, 2);
    Sint16 rv = SDL_GetGamepadAxis(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadAxisFromString(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_GamepadAxis rv = SDL_GetGamepadAxisFromString(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadButton(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_GamepadButton a1 = (SDL_GamepadButton)luaL_checkinteger(L, 2);
    bool rv = SDL_GetGamepadButton(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetGamepadButtonFromString(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_GamepadButton rv = SDL_GetGamepadButtonFromString(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadButtonLabel(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_GamepadButton a1 = (SDL_GamepadButton)luaL_checkinteger(L, 2);
    SDL_GamepadButtonLabel rv = SDL_GetGamepadButtonLabel(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadButtonLabelForType(lua_State *L)
{
    (void)L;
    SDL_GamepadType a0 = (SDL_GamepadType)luaL_checkinteger(L, 1);
    SDL_GamepadButton a1 = (SDL_GamepadButton)luaL_checkinteger(L, 2);
    SDL_GamepadButtonLabel rv = SDL_GetGamepadButtonLabelForType(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadConnectionState(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_JoystickConnectionState rv = SDL_GetGamepadConnectionState(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadFirmwareVersion(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    Uint16 rv = SDL_GetGamepadFirmwareVersion(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadFromID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    SDL_Gamepad * rv = SDL_GetGamepadFromID(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Gamepad");
    return 1;
}

static int GenL_SDL_GetGamepadFromPlayerIndex(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    SDL_Gamepad * rv = SDL_GetGamepadFromPlayerIndex(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Gamepad");
    return 1;
}

static int GenL_SDL_GetGamepadGUIDForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    SDL_GUID rv = SDL_GetGamepadGUIDForID(a0);
    GenPush_SDL_GUID(L, &rv);
    return 1;
}

static int GenL_SDL_GetGamepadID(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_JoystickID rv = SDL_GetGamepadID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadJoystick(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_Joystick * rv = SDL_GetGamepadJoystick(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Joystick");
    return 1;
}

static int GenL_SDL_GetGamepadMapping(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    char * rv = SDL_GetGamepadMapping(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDL_GetGamepadMappingForGUID(lua_State *L)
{
    (void)L;
    SDL_GUID a0;
    GenRead_SDL_GUID(L, 1, &a0);
    char * rv = SDL_GetGamepadMappingForGUID(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDL_GetGamepadMappingForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    char * rv = SDL_GetGamepadMappingForID(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDL_GetGamepadName(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    const char * rv = SDL_GetGamepadName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGamepadNameForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetGamepadNameForID(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGamepadPath(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    const char * rv = SDL_GetGamepadPath(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGamepadPathForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetGamepadPathForID(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGamepadPlayerIndex(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    int rv = SDL_GetGamepadPlayerIndex(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadPlayerIndexForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    int rv = SDL_GetGamepadPlayerIndexForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadPowerInfo(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    SDL_PowerState rv = SDL_GetGamepadPowerInfo(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetGamepadProduct(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    Uint16 rv = SDL_GetGamepadProduct(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadProductForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    Uint16 rv = SDL_GetGamepadProductForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadProductVersion(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    Uint16 rv = SDL_GetGamepadProductVersion(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadProductVersionForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    Uint16 rv = SDL_GetGamepadProductVersionForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadProperties(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_PropertiesID rv = SDL_GetGamepadProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadSensorData(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_SensorType a1 = (SDL_SensorType)luaL_checkinteger(L, 2);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    int a3 = (int)luaL_checkinteger(L, 4);
    bool rv = SDL_GetGamepadSensorData(a0, a1, &io2, a3);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io2);
    return 2;
}

static int GenL_SDL_GetGamepadSensorDataRate(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_SensorType a1 = (SDL_SensorType)luaL_checkinteger(L, 2);
    float rv = SDL_GetGamepadSensorDataRate(a0, a1);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDL_GetGamepadSerial(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    const char * rv = SDL_GetGamepadSerial(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGamepadSteamHandle(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    Uint64 rv = SDL_GetGamepadSteamHandle(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadStringForAxis(lua_State *L)
{
    (void)L;
    SDL_GamepadAxis a0 = (SDL_GamepadAxis)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetGamepadStringForAxis(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGamepadStringForButton(lua_State *L)
{
    (void)L;
    SDL_GamepadButton a0 = (SDL_GamepadButton)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetGamepadStringForButton(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGamepadStringForType(lua_State *L)
{
    (void)L;
    SDL_GamepadType a0 = (SDL_GamepadType)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetGamepadStringForType(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetGamepadTouchpadFinger(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool io3 = (bool)lua_toboolean(L, 4);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    float io5 = (float)luaL_optnumber(L, 6, 0);
    float io6 = (float)luaL_optnumber(L, 7, 0);
    bool rv = SDL_GetGamepadTouchpadFinger(a0, a1, a2, &io3, &io4, &io5, &io6);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io3);
    lua_pushnumber(L, (lua_Number)io4);
    lua_pushnumber(L, (lua_Number)io5);
    lua_pushnumber(L, (lua_Number)io6);
    return 5;
}

static int GenL_SDL_GetGamepadType(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_GamepadType rv = SDL_GetGamepadType(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadTypeForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    SDL_GamepadType rv = SDL_GetGamepadTypeForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadTypeFromString(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_GamepadType rv = SDL_GetGamepadTypeFromString(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadVendor(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    Uint16 rv = SDL_GetGamepadVendor(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGamepadVendorForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    Uint16 rv = SDL_GetGamepadVendorForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGlobalMouseState(lua_State *L)
{
    (void)L;
    float io0 = (float)luaL_optnumber(L, 1, 0);
    float io1 = (float)luaL_optnumber(L, 2, 0);
    SDL_MouseButtonFlags rv = SDL_GetGlobalMouseState(&io0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushnumber(L, (lua_Number)io0);
    lua_pushnumber(L, (lua_Number)io1);
    return 3;
}

static int GenL_SDL_GetGlobalProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID rv = SDL_GetGlobalProperties();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetGrabbedWindow(lua_State *L)
{
    (void)L;
    SDL_Window * rv = SDL_GetGrabbedWindow();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Window");
    return 1;
}

static int GenL_SDL_GetHapticEffectStatus(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    SDL_HapticEffectID a1 = (SDL_HapticEffectID)luaL_checkinteger(L, 2);
    bool rv = SDL_GetHapticEffectStatus(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetHapticFeatures(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    Uint32 rv = SDL_GetHapticFeatures(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetHapticFromID(lua_State *L)
{
    (void)L;
    SDL_HapticID a0 = (SDL_HapticID)luaL_checkinteger(L, 1);
    SDL_Haptic * rv = SDL_GetHapticFromID(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Haptic");
    return 1;
}

static int GenL_SDL_GetHapticID(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    SDL_HapticID rv = SDL_GetHapticID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetHapticName(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    const char * rv = SDL_GetHapticName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetHapticNameForID(lua_State *L)
{
    (void)L;
    SDL_HapticID a0 = (SDL_HapticID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetHapticNameForID(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetHint(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char * rv = SDL_GetHint(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetHintBoolean(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_GetHintBoolean(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetIOProperties(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_PropertiesID rv = SDL_GetIOProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetIOSize(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint64 rv = SDL_GetIOSize(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetIOStatus(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_IOStatus rv = SDL_GetIOStatus(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickAxis(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int a1 = (int)luaL_checkinteger(L, 2);
    Sint16 rv = SDL_GetJoystickAxis(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickAxisInitialState(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int a1 = (int)luaL_checkinteger(L, 2);
    Sint16 io2 = (Sint16)luaL_optinteger(L, 3, 0);
    bool rv = SDL_GetJoystickAxisInitialState(a0, a1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_SDL_GetJoystickBall(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int a1 = (int)luaL_checkinteger(L, 2);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    bool rv = SDL_GetJoystickBall(a0, a1, &io2, &io3);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    return 3;
}

static int GenL_SDL_GetJoystickButton(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDL_GetJoystickButton(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetJoystickConnectionState(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    SDL_JoystickConnectionState rv = SDL_GetJoystickConnectionState(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickFirmwareVersion(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    Uint16 rv = SDL_GetJoystickFirmwareVersion(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickFromID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    SDL_Joystick * rv = SDL_GetJoystickFromID(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Joystick");
    return 1;
}

static int GenL_SDL_GetJoystickFromPlayerIndex(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    SDL_Joystick * rv = SDL_GetJoystickFromPlayerIndex(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Joystick");
    return 1;
}

static int GenL_SDL_GetJoystickGUID(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    SDL_GUID rv = SDL_GetJoystickGUID(a0);
    GenPush_SDL_GUID(L, &rv);
    return 1;
}

static int GenL_SDL_GetJoystickGUIDForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    SDL_GUID rv = SDL_GetJoystickGUIDForID(a0);
    GenPush_SDL_GUID(L, &rv);
    return 1;
}

static int GenL_SDL_GetJoystickGUIDInfo(lua_State *L)
{
    (void)L;
    SDL_GUID a0;
    GenRead_SDL_GUID(L, 1, &a0);
    Uint16 io1 = (Uint16)luaL_optinteger(L, 2, 0);
    Uint16 io2 = (Uint16)luaL_optinteger(L, 3, 0);
    Uint16 io3 = (Uint16)luaL_optinteger(L, 4, 0);
    Uint16 io4 = (Uint16)luaL_optinteger(L, 5, 0);
    SDL_GetJoystickGUIDInfo(a0, &io1, &io2, &io3, &io4);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    return 4;
}

static int GenL_SDL_GetJoystickHat(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int a1 = (int)luaL_checkinteger(L, 2);
    Uint8 rv = SDL_GetJoystickHat(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickID(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    SDL_JoystickID rv = SDL_GetJoystickID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickName(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    const char * rv = SDL_GetJoystickName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetJoystickNameForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetJoystickNameForID(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetJoystickPath(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    const char * rv = SDL_GetJoystickPath(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetJoystickPathForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetJoystickPathForID(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetJoystickPlayerIndex(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int rv = SDL_GetJoystickPlayerIndex(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickPlayerIndexForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    int rv = SDL_GetJoystickPlayerIndexForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickPowerInfo(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    SDL_PowerState rv = SDL_GetJoystickPowerInfo(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetJoystickProduct(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    Uint16 rv = SDL_GetJoystickProduct(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickProductForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    Uint16 rv = SDL_GetJoystickProductForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickProductVersion(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    Uint16 rv = SDL_GetJoystickProductVersion(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickProductVersionForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    Uint16 rv = SDL_GetJoystickProductVersionForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickProperties(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    SDL_PropertiesID rv = SDL_GetJoystickProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickSerial(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    const char * rv = SDL_GetJoystickSerial(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetJoystickType(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    SDL_JoystickType rv = SDL_GetJoystickType(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickTypeForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    SDL_JoystickType rv = SDL_GetJoystickTypeForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickVendor(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    Uint16 rv = SDL_GetJoystickVendor(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetJoystickVendorForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    Uint16 rv = SDL_GetJoystickVendorForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetKeyFromName(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_Keycode rv = SDL_GetKeyFromName(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetKeyFromScancode(lua_State *L)
{
    (void)L;
    SDL_Scancode a0 = (SDL_Scancode)luaL_checkinteger(L, 1);
    SDL_Keymod a1 = (SDL_Keymod)luaL_checkinteger(L, 2);
    bool a2 = (bool)lua_toboolean(L, 3);
    SDL_Keycode rv = SDL_GetKeyFromScancode(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetKeyName(lua_State *L)
{
    (void)L;
    SDL_Keycode a0 = (SDL_Keycode)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetKeyName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetKeyboardFocus(lua_State *L)
{
    (void)L;
    SDL_Window * rv = SDL_GetKeyboardFocus();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Window");
    return 1;
}

static int GenL_SDL_GetKeyboardNameForID(lua_State *L)
{
    (void)L;
    SDL_KeyboardID a0 = (SDL_KeyboardID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetKeyboardNameForID(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetLogPriority(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    SDL_LogPriority rv = SDL_GetLogPriority(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetMasksForPixelFormat(lua_State *L)
{
    (void)L;
    SDL_PixelFormat a0 = (SDL_PixelFormat)luaL_checkinteger(L, 1);
    int io1 = (int)luaL_optinteger(L, 2, 0);
    Uint32 io2 = (Uint32)luaL_optinteger(L, 3, 0);
    Uint32 io3 = (Uint32)luaL_optinteger(L, 4, 0);
    Uint32 io4 = (Uint32)luaL_optinteger(L, 5, 0);
    Uint32 io5 = (Uint32)luaL_optinteger(L, 6, 0);
    bool rv = SDL_GetMasksForPixelFormat(a0, &io1, &io2, &io3, &io4, &io5);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    lua_pushinteger(L, (lua_Integer)io5);
    return 6;
}

static int GenL_SDL_GetMaxHapticEffects(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    int rv = SDL_GetMaxHapticEffects(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetMaxHapticEffectsPlaying(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    int rv = SDL_GetMaxHapticEffectsPlaying(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetModState(lua_State *L)
{
    (void)L;
    SDL_Keymod rv = SDL_GetModState();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetMouseFocus(lua_State *L)
{
    (void)L;
    SDL_Window * rv = SDL_GetMouseFocus();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Window");
    return 1;
}

static int GenL_SDL_GetMouseNameForID(lua_State *L)
{
    (void)L;
    SDL_MouseID a0 = (SDL_MouseID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetMouseNameForID(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetMouseState(lua_State *L)
{
    (void)L;
    float io0 = (float)luaL_optnumber(L, 1, 0);
    float io1 = (float)luaL_optnumber(L, 2, 0);
    SDL_MouseButtonFlags rv = SDL_GetMouseState(&io0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushnumber(L, (lua_Number)io0);
    lua_pushnumber(L, (lua_Number)io1);
    return 3;
}

static int GenL_SDL_GetNaturalDisplayOrientation(lua_State *L)
{
    (void)L;
    SDL_DisplayID a0 = (SDL_DisplayID)luaL_checkinteger(L, 1);
    SDL_DisplayOrientation rv = SDL_GetNaturalDisplayOrientation(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumAllocations(lua_State *L)
{
    (void)L;
    int rv = SDL_GetNumAllocations();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumAudioDrivers(lua_State *L)
{
    (void)L;
    int rv = SDL_GetNumAudioDrivers();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumCameraDrivers(lua_State *L)
{
    (void)L;
    int rv = SDL_GetNumCameraDrivers();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumGPUDrivers(lua_State *L)
{
    (void)L;
    int rv = SDL_GetNumGPUDrivers();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumGamepadTouchpadFingers(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    int a1 = (int)luaL_checkinteger(L, 2);
    int rv = SDL_GetNumGamepadTouchpadFingers(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumGamepadTouchpads(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    int rv = SDL_GetNumGamepadTouchpads(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumHapticAxes(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    int rv = SDL_GetNumHapticAxes(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumJoystickAxes(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int rv = SDL_GetNumJoystickAxes(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumJoystickBalls(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int rv = SDL_GetNumJoystickBalls(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumJoystickButtons(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int rv = SDL_GetNumJoystickButtons(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumJoystickHats(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int rv = SDL_GetNumJoystickHats(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumLogicalCPUCores(lua_State *L)
{
    (void)L;
    int rv = SDL_GetNumLogicalCPUCores();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumRenderDrivers(lua_State *L)
{
    (void)L;
    int rv = SDL_GetNumRenderDrivers();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumVideoDrivers(lua_State *L)
{
    (void)L;
    int rv = SDL_GetNumVideoDrivers();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetNumberProperty(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    Sint64 a2 = (Sint64)luaL_checkinteger(L, 3);
    Sint64 rv = SDL_GetNumberProperty(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetPathInfo(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_PathInfo out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetPathInfo(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_PathInfo(L, &out1);
    return 2;
}

static int GenL_SDL_GetPenDeviceType(lua_State *L)
{
    (void)L;
    SDL_PenID a0 = (SDL_PenID)luaL_checkinteger(L, 1);
    SDL_PenDeviceType rv = SDL_GetPenDeviceType(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetPerformanceCounter(lua_State *L)
{
    (void)L;
    Uint64 rv = SDL_GetPerformanceCounter();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetPerformanceFrequency(lua_State *L)
{
    (void)L;
    Uint64 rv = SDL_GetPerformanceFrequency();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetPixelFormatForMasks(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    SDL_PixelFormat rv = SDL_GetPixelFormatForMasks(a0, a1, a2, a3, a4);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetPixelFormatFromGPUTextureFormat(lua_State *L)
{
    (void)L;
    SDL_GPUTextureFormat a0 = (SDL_GPUTextureFormat)luaL_checkinteger(L, 1);
    SDL_PixelFormat rv = SDL_GetPixelFormatFromGPUTextureFormat(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetPixelFormatName(lua_State *L)
{
    (void)L;
    SDL_PixelFormat a0 = (SDL_PixelFormat)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetPixelFormatName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetPlatform(lua_State *L)
{
    (void)L;
    const char * rv = SDL_GetPlatform();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetPowerInfo(lua_State *L)
{
    (void)L;
    int io0 = (int)luaL_optinteger(L, 1, 0);
    int io1 = (int)luaL_optinteger(L, 2, 0);
    SDL_PowerState rv = SDL_GetPowerInfo(&io0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io0);
    lua_pushinteger(L, (lua_Integer)io1);
    return 3;
}

static int GenL_SDL_GetPrefPath(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    char * rv = SDL_GetPrefPath(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDL_GetPrimaryDisplay(lua_State *L)
{
    (void)L;
    SDL_DisplayID rv = SDL_GetPrimaryDisplay();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetPrimarySelectionText(lua_State *L)
{
    (void)L;
    char * rv = SDL_GetPrimarySelectionText();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDL_GetProcessInput(lua_State *L)
{
    (void)L;
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Process");
    SDL_IOStream * rv = SDL_GetProcessInput(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_IOStream");
    return 1;
}

static int GenL_SDL_GetProcessOutput(lua_State *L)
{
    (void)L;
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Process");
    SDL_IOStream * rv = SDL_GetProcessOutput(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_IOStream");
    return 1;
}

static int GenL_SDL_GetProcessProperties(lua_State *L)
{
    (void)L;
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Process");
    SDL_PropertiesID rv = SDL_GetProcessProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetPropertyType(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_PropertyType rv = SDL_GetPropertyType(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetRGB(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    SDL_PixelFormatDetails tmp1;
    const SDL_PixelFormatDetails *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_PixelFormatDetails(L, 2, &tmp1);
        a1 = &tmp1;
    }
    const SDL_Palette *a2 = (const SDL_Palette *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_Palette");
    Uint8 io3 = (Uint8)luaL_optinteger(L, 4, 0);
    Uint8 io4 = (Uint8)luaL_optinteger(L, 5, 0);
    Uint8 io5 = (Uint8)luaL_optinteger(L, 6, 0);
    SDL_GetRGB(a0, a1, a2, &io3, &io4, &io5);
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    lua_pushinteger(L, (lua_Integer)io5);
    return 3;
}

static int GenL_SDL_GetRGBA(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    SDL_PixelFormatDetails tmp1;
    const SDL_PixelFormatDetails *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_PixelFormatDetails(L, 2, &tmp1);
        a1 = &tmp1;
    }
    const SDL_Palette *a2 = (const SDL_Palette *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_Palette");
    Uint8 io3 = (Uint8)luaL_optinteger(L, 4, 0);
    Uint8 io4 = (Uint8)luaL_optinteger(L, 5, 0);
    Uint8 io5 = (Uint8)luaL_optinteger(L, 6, 0);
    Uint8 io6 = (Uint8)luaL_optinteger(L, 7, 0);
    SDL_GetRGBA(a0, a1, a2, &io3, &io4, &io5, &io6);
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    lua_pushinteger(L, (lua_Integer)io5);
    lua_pushinteger(L, (lua_Integer)io6);
    return 4;
}

static int GenL_SDL_GetRealGamepadType(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_GamepadType rv = SDL_GetRealGamepadType(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetRealGamepadTypeForID(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    SDL_GamepadType rv = SDL_GetRealGamepadTypeForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetRectAndLineIntersection(lua_State *L)
{
    (void)L;
    SDL_Rect tmp0;
    const SDL_Rect *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_Rect(L, 1, &tmp0);
        a0 = &tmp0;
    }
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    int io4 = (int)luaL_optinteger(L, 5, 0);
    bool rv = SDL_GetRectAndLineIntersection(a0, &io1, &io2, &io3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    return 5;
}

static int GenL_SDL_GetRectAndLineIntersectionFloat(lua_State *L)
{
    (void)L;
    SDL_FRect tmp0;
    const SDL_FRect *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_FRect(L, 1, &tmp0);
        a0 = &tmp0;
    }
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    bool rv = SDL_GetRectAndLineIntersectionFloat(a0, &io1, &io2, &io3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    return 5;
}

static int GenL_SDL_GetRectEnclosingPoints(lua_State *L)
{
    (void)L;
    SDL_Point tmp0;
    const SDL_Point *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_Point(L, 1, &tmp0);
        a0 = &tmp0;
    }
    int a1 = (int)luaL_checkinteger(L, 2);
    SDL_Rect tmp2;
    const SDL_Rect *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_Rect(L, 3, &tmp2);
        a2 = &tmp2;
    }
    SDL_Rect out3;
    memset(&out3, 0, sizeof(out3));
    bool rv = SDL_GetRectEnclosingPoints(a0, a1, a2, &out3);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_Rect(L, &out3);
    return 2;
}

static int GenL_SDL_GetRectEnclosingPointsFloat(lua_State *L)
{
    (void)L;
    SDL_FPoint tmp0;
    const SDL_FPoint *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_FPoint(L, 1, &tmp0);
        a0 = &tmp0;
    }
    int a1 = (int)luaL_checkinteger(L, 2);
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_FRect(L, 3, &tmp2);
        a2 = &tmp2;
    }
    SDL_FRect out3;
    memset(&out3, 0, sizeof(out3));
    bool rv = SDL_GetRectEnclosingPointsFloat(a0, a1, a2, &out3);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_FRect(L, &out3);
    return 2;
}

static int GenL_SDL_GetRectIntersection(lua_State *L)
{
    (void)L;
    SDL_Rect tmp0;
    const SDL_Rect *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_Rect(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_Rect out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetRectIntersection(a0, a1, &out2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_Rect(L, &out2);
    return 2;
}

static int GenL_SDL_GetRectIntersectionFloat(lua_State *L)
{
    (void)L;
    SDL_FRect tmp0;
    const SDL_FRect *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_FRect(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_FRect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_FRect out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetRectIntersectionFloat(a0, a1, &out2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_FRect(L, &out2);
    return 2;
}

static int GenL_SDL_GetRectUnion(lua_State *L)
{
    (void)L;
    SDL_Rect tmp0;
    const SDL_Rect *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_Rect(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_Rect out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetRectUnion(a0, a1, &out2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_Rect(L, &out2);
    return 2;
}

static int GenL_SDL_GetRectUnionFloat(lua_State *L)
{
    (void)L;
    SDL_FRect tmp0;
    const SDL_FRect *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_FRect(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_FRect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_FRect out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetRectUnionFloat(a0, a1, &out2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_FRect(L, &out2);
    return 2;
}

static int GenL_SDL_GetRelativeMouseState(lua_State *L)
{
    (void)L;
    float io0 = (float)luaL_optnumber(L, 1, 0);
    float io1 = (float)luaL_optnumber(L, 2, 0);
    SDL_MouseButtonFlags rv = SDL_GetRelativeMouseState(&io0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushnumber(L, (lua_Number)io0);
    lua_pushnumber(L, (lua_Number)io1);
    return 3;
}

static int GenL_SDL_GetRenderClipRect(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetRenderClipRect(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_Rect(L, &out1);
    return 2;
}

static int GenL_SDL_GetRenderColorScale(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    bool rv = SDL_GetRenderColorScale(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io1);
    return 2;
}

static int GenL_SDL_GetRenderDrawBlendMode(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_BlendMode io1 = (SDL_BlendMode)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetRenderDrawBlendMode(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetRenderDrawColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Uint8 io1 = (Uint8)luaL_optinteger(L, 2, 0);
    Uint8 io2 = (Uint8)luaL_optinteger(L, 3, 0);
    Uint8 io3 = (Uint8)luaL_optinteger(L, 4, 0);
    Uint8 io4 = (Uint8)luaL_optinteger(L, 5, 0);
    bool rv = SDL_GetRenderDrawColor(a0, &io1, &io2, &io3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    return 5;
}

static int GenL_SDL_GetRenderDrawColorFloat(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    bool rv = SDL_GetRenderDrawColorFloat(a0, &io1, &io2, &io3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    return 5;
}

static int GenL_SDL_GetRenderDriver(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetRenderDriver(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetRenderLogicalPresentation(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    SDL_RendererLogicalPresentation io3 = (SDL_RendererLogicalPresentation)luaL_optinteger(L, 4, 0);
    bool rv = SDL_GetRenderLogicalPresentation(a0, &io1, &io2, &io3);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    return 4;
}

static int GenL_SDL_GetRenderLogicalPresentationRect(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_FRect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetRenderLogicalPresentationRect(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_FRect(L, &out1);
    return 2;
}

static int GenL_SDL_GetRenderOutputSize(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    bool rv = SDL_GetRenderOutputSize(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_SDL_GetRenderSafeArea(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetRenderSafeArea(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_Rect(L, &out1);
    return 2;
}

static int GenL_SDL_GetRenderScale(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    bool rv = SDL_GetRenderScale(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    return 3;
}

static int GenL_SDL_GetRenderTarget(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Texture * rv = SDL_GetRenderTarget(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Texture");
    return 1;
}

static int GenL_SDL_GetRenderTextureAddressMode(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_TextureAddressMode io1 = (SDL_TextureAddressMode)luaL_optinteger(L, 2, 0);
    SDL_TextureAddressMode io2 = (SDL_TextureAddressMode)luaL_optinteger(L, 3, 0);
    bool rv = SDL_GetRenderTextureAddressMode(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_SDL_GetRenderVSync(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetRenderVSync(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetRenderViewport(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetRenderViewport(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_Rect(L, &out1);
    return 2;
}

static int GenL_SDL_GetRenderWindow(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Window * rv = SDL_GetRenderWindow(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Window");
    return 1;
}

static int GenL_SDL_GetRenderer(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_Renderer * rv = SDL_GetRenderer(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Renderer");
    return 1;
}

static int GenL_SDL_GetRendererFromTexture(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    SDL_Renderer * rv = SDL_GetRendererFromTexture(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Renderer");
    return 1;
}

static int GenL_SDL_GetRendererName(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    const char * rv = SDL_GetRendererName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetRendererProperties(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_PropertiesID rv = SDL_GetRendererProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetRevision(lua_State *L)
{
    (void)L;
    const char * rv = SDL_GetRevision();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetSIMDAlignment(lua_State *L)
{
    (void)L;
    size_t rv = SDL_GetSIMDAlignment();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetSandbox(lua_State *L)
{
    (void)L;
    SDL_Sandbox rv = SDL_GetSandbox();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetScancodeFromKey(lua_State *L)
{
    (void)L;
    SDL_Keycode a0 = (SDL_Keycode)luaL_checkinteger(L, 1);
    SDL_Keymod io1 = (SDL_Keymod)luaL_optinteger(L, 2, 0);
    SDL_Scancode rv = SDL_GetScancodeFromKey(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetScancodeFromName(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_Scancode rv = SDL_GetScancodeFromName(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetScancodeName(lua_State *L)
{
    (void)L;
    SDL_Scancode a0 = (SDL_Scancode)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetScancodeName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetSensorData(lua_State *L)
{
    (void)L;
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Sensor");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_GetSensorData(a0, &io1, a2);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io1);
    return 2;
}

static int GenL_SDL_GetSensorFromID(lua_State *L)
{
    (void)L;
    SDL_SensorID a0 = (SDL_SensorID)luaL_checkinteger(L, 1);
    SDL_Sensor * rv = SDL_GetSensorFromID(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Sensor");
    return 1;
}

static int GenL_SDL_GetSensorID(lua_State *L)
{
    (void)L;
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Sensor");
    SDL_SensorID rv = SDL_GetSensorID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetSensorName(lua_State *L)
{
    (void)L;
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Sensor");
    const char * rv = SDL_GetSensorName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetSensorNameForID(lua_State *L)
{
    (void)L;
    SDL_SensorID a0 = (SDL_SensorID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetSensorNameForID(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetSensorNonPortableType(lua_State *L)
{
    (void)L;
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Sensor");
    int rv = SDL_GetSensorNonPortableType(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetSensorNonPortableTypeForID(lua_State *L)
{
    (void)L;
    SDL_SensorID a0 = (SDL_SensorID)luaL_checkinteger(L, 1);
    int rv = SDL_GetSensorNonPortableTypeForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetSensorProperties(lua_State *L)
{
    (void)L;
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Sensor");
    SDL_PropertiesID rv = SDL_GetSensorProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetSensorType(lua_State *L)
{
    (void)L;
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Sensor");
    SDL_SensorType rv = SDL_GetSensorType(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetSensorTypeForID(lua_State *L)
{
    (void)L;
    SDL_SensorID a0 = (SDL_SensorID)luaL_checkinteger(L, 1);
    SDL_SensorType rv = SDL_GetSensorTypeForID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetSilenceValueForFormat(lua_State *L)
{
    (void)L;
    SDL_AudioFormat a0 = (SDL_AudioFormat)luaL_checkinteger(L, 1);
    int rv = SDL_GetSilenceValueForFormat(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetStorageFileSize(lua_State *L)
{
    (void)L;
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Storage");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    Uint64 io2 = (Uint64)luaL_optinteger(L, 3, 0);
    bool rv = SDL_GetStorageFileSize(a0, a1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_SDL_GetStoragePathInfo(lua_State *L)
{
    (void)L;
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Storage");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_PathInfo out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetStoragePathInfo(a0, a1, &out2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_PathInfo(L, &out2);
    return 2;
}

static int GenL_SDL_GetStorageSpaceRemaining(lua_State *L)
{
    (void)L;
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Storage");
    Uint64 rv = SDL_GetStorageSpaceRemaining(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetStringProperty(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    const char * rv = SDL_GetStringProperty(a0, a1, a2);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetSurfaceAlphaMod(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    Uint8 io1 = (Uint8)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetSurfaceAlphaMod(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetSurfaceBlendMode(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_BlendMode io1 = (SDL_BlendMode)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetSurfaceBlendMode(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetSurfaceClipRect(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetSurfaceClipRect(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_Rect(L, &out1);
    return 2;
}

static int GenL_SDL_GetSurfaceColorKey(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    Uint32 io1 = (Uint32)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetSurfaceColorKey(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetSurfaceColorMod(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    Uint8 io1 = (Uint8)luaL_optinteger(L, 2, 0);
    Uint8 io2 = (Uint8)luaL_optinteger(L, 3, 0);
    Uint8 io3 = (Uint8)luaL_optinteger(L, 4, 0);
    bool rv = SDL_GetSurfaceColorMod(a0, &io1, &io2, &io3);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    return 4;
}

static int GenL_SDL_GetSurfaceColorspace(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Colorspace rv = SDL_GetSurfaceColorspace(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetSurfacePalette(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Palette * rv = SDL_GetSurfacePalette(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Palette");
    return 1;
}

static int GenL_SDL_GetSurfaceProperties(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_PropertiesID rv = SDL_GetSurfaceProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetSystemPageSize(lua_State *L)
{
    (void)L;
    int rv = SDL_GetSystemPageSize();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetSystemRAM(lua_State *L)
{
    (void)L;
    int rv = SDL_GetSystemRAM();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetSystemTheme(lua_State *L)
{
    (void)L;
    SDL_SystemTheme rv = SDL_GetSystemTheme();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetTextInputArea(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    int io2 = (int)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetTextInputArea(a0, &out1, &io2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_Rect(L, &out1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_SDL_GetTextureAlphaMod(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    Uint8 io1 = (Uint8)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetTextureAlphaMod(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetTextureAlphaModFloat(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    bool rv = SDL_GetTextureAlphaModFloat(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io1);
    return 2;
}

static int GenL_SDL_GetTextureBlendMode(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    SDL_BlendMode io1 = (SDL_BlendMode)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetTextureBlendMode(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetTextureColorMod(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    Uint8 io1 = (Uint8)luaL_optinteger(L, 2, 0);
    Uint8 io2 = (Uint8)luaL_optinteger(L, 3, 0);
    Uint8 io3 = (Uint8)luaL_optinteger(L, 4, 0);
    bool rv = SDL_GetTextureColorMod(a0, &io1, &io2, &io3);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    return 4;
}

static int GenL_SDL_GetTextureColorModFloat(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    bool rv = SDL_GetTextureColorModFloat(a0, &io1, &io2, &io3);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    return 4;
}

static int GenL_SDL_GetTexturePalette(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    SDL_Palette * rv = SDL_GetTexturePalette(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Palette");
    return 1;
}

static int GenL_SDL_GetTextureProperties(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    SDL_PropertiesID rv = SDL_GetTextureProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetTextureScaleMode(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    SDL_ScaleMode io1 = (SDL_ScaleMode)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetTextureScaleMode(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetTextureSize(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    bool rv = SDL_GetTextureSize(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    return 3;
}

static int GenL_SDL_GetTicks(lua_State *L)
{
    (void)L;
    Uint64 rv = SDL_GetTicks();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetTicksNS(lua_State *L)
{
    (void)L;
    Uint64 rv = SDL_GetTicksNS();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetTouchDeviceName(lua_State *L)
{
    (void)L;
    SDL_TouchID a0 = (SDL_TouchID)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetTouchDeviceName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetTouchDeviceType(lua_State *L)
{
    (void)L;
    SDL_TouchID a0 = (SDL_TouchID)luaL_checkinteger(L, 1);
    SDL_TouchDeviceType rv = SDL_GetTouchDeviceType(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetTrayEntryChecked(lua_State *L)
{
    (void)L;
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayEntry");
    bool rv = SDL_GetTrayEntryChecked(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetTrayEntryEnabled(lua_State *L)
{
    (void)L;
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayEntry");
    bool rv = SDL_GetTrayEntryEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetTrayEntryLabel(lua_State *L)
{
    (void)L;
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayEntry");
    const char * rv = SDL_GetTrayEntryLabel(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetTrayEntryParent(lua_State *L)
{
    (void)L;
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayEntry");
    SDL_TrayMenu * rv = SDL_GetTrayEntryParent(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_TrayMenu");
    return 1;
}

static int GenL_SDL_GetTrayMenu(lua_State *L)
{
    (void)L;
    SDL_Tray *a0 = (SDL_Tray *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Tray");
    SDL_TrayMenu * rv = SDL_GetTrayMenu(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_TrayMenu");
    return 1;
}

static int GenL_SDL_GetTrayMenuParentEntry(lua_State *L)
{
    (void)L;
    SDL_TrayMenu *a0 = (SDL_TrayMenu *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayMenu");
    SDL_TrayEntry * rv = SDL_GetTrayMenuParentEntry(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_TrayEntry");
    return 1;
}

static int GenL_SDL_GetTrayMenuParentTray(lua_State *L)
{
    (void)L;
    SDL_TrayMenu *a0 = (SDL_TrayMenu *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayMenu");
    SDL_Tray * rv = SDL_GetTrayMenuParentTray(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Tray");
    return 1;
}

static int GenL_SDL_GetTraySubmenu(lua_State *L)
{
    (void)L;
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayEntry");
    SDL_TrayMenu * rv = SDL_GetTraySubmenu(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_TrayMenu");
    return 1;
}

static int GenL_SDL_GetUserFolder(lua_State *L)
{
    (void)L;
    SDL_Folder a0 = (SDL_Folder)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetUserFolder(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetVersion(lua_State *L)
{
    (void)L;
    int rv = SDL_GetVersion();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetVideoDriver(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    const char * rv = SDL_GetVideoDriver(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_GetWindowAspectRatio(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    bool rv = SDL_GetWindowAspectRatio(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    return 3;
}

static int GenL_SDL_GetWindowBordersSize(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    int io4 = (int)luaL_optinteger(L, 5, 0);
    bool rv = SDL_GetWindowBordersSize(a0, &io1, &io2, &io3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    return 5;
}

static int GenL_SDL_GetWindowDisplayScale(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    float rv = SDL_GetWindowDisplayScale(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDL_GetWindowFlags(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_WindowFlags rv = SDL_GetWindowFlags(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetWindowFromEvent(lua_State *L)
{
    (void)L;
    const SDL_Event *a0 = (const SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    SDL_Window * rv = SDL_GetWindowFromEvent(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Window");
    return 1;
}

static int GenL_SDL_GetWindowFromID(lua_State *L)
{
    (void)L;
    SDL_WindowID a0 = (SDL_WindowID)luaL_checkinteger(L, 1);
    SDL_Window * rv = SDL_GetWindowFromID(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Window");
    return 1;
}

static int GenL_SDL_GetWindowFullscreenMode(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    const SDL_DisplayMode * rv = SDL_GetWindowFullscreenMode(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_DisplayMode");
    return 1;
}

static int GenL_SDL_GetWindowID(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_WindowID rv = SDL_GetWindowID(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetWindowKeyboardGrab(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_GetWindowKeyboardGrab(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetWindowMaximumSize(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    bool rv = SDL_GetWindowMaximumSize(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_SDL_GetWindowMinimumSize(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    bool rv = SDL_GetWindowMinimumSize(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_SDL_GetWindowMouseGrab(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_GetWindowMouseGrab(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetWindowOpacity(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    float rv = SDL_GetWindowOpacity(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDL_GetWindowParent(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_Window * rv = SDL_GetWindowParent(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Window");
    return 1;
}

static int GenL_SDL_GetWindowPixelDensity(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    float rv = SDL_GetWindowPixelDensity(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDL_GetWindowPixelFormat(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_PixelFormat rv = SDL_GetWindowPixelFormat(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetWindowPosition(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    bool rv = SDL_GetWindowPosition(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_SDL_GetWindowProgressState(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_ProgressState rv = SDL_GetWindowProgressState(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetWindowProgressValue(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    float rv = SDL_GetWindowProgressValue(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDL_GetWindowProperties(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_PropertiesID rv = SDL_GetWindowProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_GetWindowRelativeMouseMode(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_GetWindowRelativeMouseMode(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_GetWindowSafeArea(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetWindowSafeArea(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_Rect(L, &out1);
    return 2;
}

static int GenL_SDL_GetWindowSize(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    bool rv = SDL_GetWindowSize(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_SDL_GetWindowSizeInPixels(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    bool rv = SDL_GetWindowSizeInPixels(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_SDL_GetWindowSurface(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_Surface * rv = SDL_GetWindowSurface(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_SDL_GetWindowSurfaceVSync(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    bool rv = SDL_GetWindowSurfaceVSync(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_GetWindowTitle(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    const char * rv = SDL_GetWindowTitle(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_HapticEffectSupported(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    const SDL_HapticEffect *a1 = (const SDL_HapticEffect *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_HapticEffect");
    bool rv = SDL_HapticEffectSupported(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HapticRumbleSupported(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    bool rv = SDL_HapticRumbleSupported(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasARMSIMD(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasARMSIMD();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasAVX(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasAVX();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasAVX2(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasAVX2();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasAVX512F(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasAVX512F();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasAltiVec(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasAltiVec();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasClipboardData(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDL_HasClipboardData(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasClipboardText(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasClipboardText();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasEvent(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    bool rv = SDL_HasEvent(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasEvents(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    bool rv = SDL_HasEvents(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasGamepad(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasGamepad();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasJoystick(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasJoystick();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasKeyboard(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasKeyboard();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasLASX(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasLASX();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasLSX(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasLSX();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasMMX(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasMMX();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasMouse(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasMouse();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasNEON(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasNEON();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasPrimarySelectionText(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasPrimarySelectionText();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasProperty(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_HasProperty(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasRectIntersection(lua_State *L)
{
    (void)L;
    SDL_Rect tmp0;
    const SDL_Rect *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_Rect(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_HasRectIntersection(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasRectIntersectionFloat(lua_State *L)
{
    (void)L;
    SDL_FRect tmp0;
    const SDL_FRect *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_FRect(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_FRect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_HasRectIntersectionFloat(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasSSE(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasSSE();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasSSE2(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasSSE2();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasSSE3(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasSSE3();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasSSE41(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasSSE41();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasSSE42(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasSSE42();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HasScreenKeyboardSupport(lua_State *L)
{
    (void)L;
    bool rv = SDL_HasScreenKeyboardSupport();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HideCursor(lua_State *L)
{
    (void)L;
    bool rv = SDL_HideCursor();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_HideWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_HideWindow(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_IOFromConstMem(lua_State *L)
{
    (void)L;
    size_t len0 = 0;
    const char *a0 = luaL_checklstring(L, 1, &len0);
    SDL_IOStream * rv = SDL_IOFromConstMem((const void *)a0, (size_t)len0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_IOStream", GenDtor_SDL_CloseIO);
    return 1;
}

static int GenL_SDL_IOFromDynamicMem(lua_State *L)
{
    (void)L;
    SDL_IOStream * rv = SDL_IOFromDynamicMem();
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_IOStream", GenDtor_SDL_CloseIO);
    return 1;
}

static int GenL_SDL_IOFromFile(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_IOStream * rv = SDL_IOFromFile(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_IOStream", GenDtor_SDL_CloseIO);
    return 1;
}

static int GenL_SDL_Init(lua_State *L)
{
    (void)L;
    SDL_InitFlags a0 = (SDL_InitFlags)luaL_checkinteger(L, 1);
    bool rv = SDL_Init(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_InitHapticRumble(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    bool rv = SDL_InitHapticRumble(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_InitSubSystem(lua_State *L)
{
    (void)L;
    SDL_InitFlags a0 = (SDL_InitFlags)luaL_checkinteger(L, 1);
    bool rv = SDL_InitSubSystem(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_InsertGPUDebugLabel(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_InsertGPUDebugLabel(a0, a1);
    return 0;
}

static int GenL_SDL_InsertTrayEntryAt(lua_State *L)
{
    (void)L;
    SDL_TrayMenu *a0 = (SDL_TrayMenu *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayMenu");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    SDL_TrayEntryFlags a3 = (SDL_TrayEntryFlags)luaL_checkinteger(L, 4);
    SDL_TrayEntry * rv = SDL_InsertTrayEntryAt(a0, a1, a2, a3);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_TrayEntry");
    return 1;
}

static int GenL_SDL_IsAudioDevicePhysical(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    bool rv = SDL_IsAudioDevicePhysical(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_IsAudioDevicePlayback(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    bool rv = SDL_IsAudioDevicePlayback(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_IsGamepad(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    bool rv = SDL_IsGamepad(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_IsJoystickHaptic(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    bool rv = SDL_IsJoystickHaptic(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_IsJoystickVirtual(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    bool rv = SDL_IsJoystickVirtual(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_IsMainThread(lua_State *L)
{
    (void)L;
    bool rv = SDL_IsMainThread();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_IsMouseHaptic(lua_State *L)
{
    (void)L;
    bool rv = SDL_IsMouseHaptic();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_IsTV(lua_State *L)
{
    (void)L;
    bool rv = SDL_IsTV();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_IsTablet(lua_State *L)
{
    (void)L;
    bool rv = SDL_IsTablet();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_JoystickConnected(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    bool rv = SDL_JoystickConnected(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_JoystickEventsEnabled(lua_State *L)
{
    (void)L;
    bool rv = SDL_JoystickEventsEnabled();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_KillProcess(lua_State *L)
{
    (void)L;
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Process");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_KillProcess(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_LoadBMP(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_Surface * rv = SDL_LoadBMP(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_SDL_LoadBMP_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDL_Surface * rv = SDL_LoadBMP_IO(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_SDL_LoadObject(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_SharedObject * rv = SDL_LoadObject(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_SharedObject", GenDtor_SDL_UnloadObject);
    return 1;
}

static int GenL_SDL_LoadPNG(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_Surface * rv = SDL_LoadPNG(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_SDL_LoadPNG_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDL_Surface * rv = SDL_LoadPNG_IO(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_SDL_LoadSurface(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_Surface * rv = SDL_LoadSurface(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_SDL_LoadSurface_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDL_Surface * rv = SDL_LoadSurface_IO(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_SDL_LockAudioStream(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    bool rv = SDL_LockAudioStream(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_LockProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    bool rv = SDL_LockProperties(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_LockSpinlock(lua_State *L)
{
    (void)L;
    SDL_SpinLock io0 = (SDL_SpinLock)luaL_optinteger(L, 1, 0);
    SDL_LockSpinlock(&io0);
    lua_pushinteger(L, (lua_Integer)io0);
    return 1;
}

static int GenL_SDL_LockSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    bool rv = SDL_LockSurface(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_MapRGB(lua_State *L)
{
    (void)L;
    SDL_PixelFormatDetails tmp0;
    const SDL_PixelFormatDetails *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_PixelFormatDetails(L, 1, &tmp0);
        a0 = &tmp0;
    }
    const SDL_Palette *a1 = (const SDL_Palette *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Palette");
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint32 rv = SDL_MapRGB(a0, a1, a2, a3, a4);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_MapRGBA(lua_State *L)
{
    (void)L;
    SDL_PixelFormatDetails tmp0;
    const SDL_PixelFormatDetails *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDL_PixelFormatDetails(L, 1, &tmp0);
        a0 = &tmp0;
    }
    const SDL_Palette *a1 = (const SDL_Palette *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Palette");
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint32 rv = SDL_MapRGBA(a0, a1, a2, a3, a4, a5);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_MapSurfaceRGB(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    Uint32 rv = SDL_MapSurfaceRGB(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_MapSurfaceRGBA(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint32 rv = SDL_MapSurfaceRGBA(a0, a1, a2, a3, a4);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_MaximizeWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_MaximizeWindow(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_MinimizeWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_MinimizeWindow(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_OnApplicationDidEnterBackground(lua_State *L)
{
    (void)L;
    SDL_OnApplicationDidEnterBackground();
    return 0;
}

static int GenL_SDL_OnApplicationDidEnterForeground(lua_State *L)
{
    (void)L;
    SDL_OnApplicationDidEnterForeground();
    return 0;
}

static int GenL_SDL_OnApplicationDidReceiveMemoryWarning(lua_State *L)
{
    (void)L;
    SDL_OnApplicationDidReceiveMemoryWarning();
    return 0;
}

static int GenL_SDL_OnApplicationWillEnterBackground(lua_State *L)
{
    (void)L;
    SDL_OnApplicationWillEnterBackground();
    return 0;
}

static int GenL_SDL_OnApplicationWillEnterForeground(lua_State *L)
{
    (void)L;
    SDL_OnApplicationWillEnterForeground();
    return 0;
}

static int GenL_SDL_OnApplicationWillTerminate(lua_State *L)
{
    (void)L;
    SDL_OnApplicationWillTerminate();
    return 0;
}

static int GenL_SDL_OpenAudioDevice(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    SDL_AudioSpec tmp1;
    const SDL_AudioSpec *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_AudioSpec(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_AudioDeviceID rv = SDL_OpenAudioDevice(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_OpenCamera(lua_State *L)
{
    (void)L;
    SDL_CameraID a0 = (SDL_CameraID)luaL_checkinteger(L, 1);
    SDL_CameraSpec tmp1;
    const SDL_CameraSpec *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_CameraSpec(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_Camera * rv = SDL_OpenCamera(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Camera", GenDtor_SDL_CloseCamera);
    return 1;
}

static int GenL_SDL_OpenFileStorage(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_Storage * rv = SDL_OpenFileStorage(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Storage", GenDtor_SDL_CloseStorage);
    return 1;
}

static int GenL_SDL_OpenGamepad(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    SDL_Gamepad * rv = SDL_OpenGamepad(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Gamepad", GenDtor_SDL_CloseGamepad);
    return 1;
}

static int GenL_SDL_OpenHaptic(lua_State *L)
{
    (void)L;
    SDL_HapticID a0 = (SDL_HapticID)luaL_checkinteger(L, 1);
    SDL_Haptic * rv = SDL_OpenHaptic(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Haptic", GenDtor_SDL_CloseHaptic);
    return 1;
}

static int GenL_SDL_OpenHapticFromJoystick(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    SDL_Haptic * rv = SDL_OpenHapticFromJoystick(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Haptic", GenDtor_SDL_CloseHaptic);
    return 1;
}

static int GenL_SDL_OpenHapticFromMouse(lua_State *L)
{
    (void)L;
    SDL_Haptic * rv = SDL_OpenHapticFromMouse();
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Haptic", GenDtor_SDL_CloseHaptic);
    return 1;
}

static int GenL_SDL_OpenJoystick(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    SDL_Joystick * rv = SDL_OpenJoystick(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Joystick", GenDtor_SDL_CloseJoystick);
    return 1;
}

static int GenL_SDL_OpenSensor(lua_State *L)
{
    (void)L;
    SDL_SensorID a0 = (SDL_SensorID)luaL_checkinteger(L, 1);
    SDL_Sensor * rv = SDL_OpenSensor(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Sensor", GenDtor_SDL_CloseSensor);
    return 1;
}

static int GenL_SDL_OpenTitleStorage(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_PropertiesID a1 = (SDL_PropertiesID)luaL_checkinteger(L, 2);
    SDL_Storage * rv = SDL_OpenTitleStorage(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Storage", GenDtor_SDL_CloseStorage);
    return 1;
}

static int GenL_SDL_OpenURL(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDL_OpenURL(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_OpenUserStorage(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_PropertiesID a2 = (SDL_PropertiesID)luaL_checkinteger(L, 3);
    SDL_Storage * rv = SDL_OpenUserStorage(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Storage", GenDtor_SDL_CloseStorage);
    return 1;
}

static int GenL_SDL_OutOfMemory(lua_State *L)
{
    (void)L;
    bool rv = SDL_OutOfMemory();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_PauseAudioDevice(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    bool rv = SDL_PauseAudioDevice(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_PauseAudioStreamDevice(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    bool rv = SDL_PauseAudioStreamDevice(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_PauseHaptic(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    bool rv = SDL_PauseHaptic(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_PeepEvents(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDL_EventAction a2 = (SDL_EventAction)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    int rv = SDL_PeepEvents(a0, a1, a2, a3, a4);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_PlayHapticRumble(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    float a1 = (float)luaL_checknumber(L, 2);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    bool rv = SDL_PlayHapticRumble(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_PollEvent(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    bool rv = SDL_PollEvent(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_PopGPUDebugGroup(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    SDL_PopGPUDebugGroup(a0);
    return 0;
}

static int GenL_SDL_PremultiplySurfaceAlpha(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_PremultiplySurfaceAlpha(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_PumpEvents(lua_State *L)
{
    (void)L;
    SDL_PumpEvents();
    return 0;
}

static int GenL_SDL_PushEvent(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    bool rv = SDL_PushEvent(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_PushGPUComputeUniformData(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    size_t len2 = 0;
    const char *a2 = luaL_checklstring(L, 3, &len2);
    SDL_PushGPUComputeUniformData(a0, a1, (const void *)a2, (Uint32)len2);
    return 0;
}

static int GenL_SDL_PushGPUDebugGroup(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_PushGPUDebugGroup(a0, a1);
    return 0;
}

static int GenL_SDL_PushGPUFragmentUniformData(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    size_t len2 = 0;
    const char *a2 = luaL_checklstring(L, 3, &len2);
    SDL_PushGPUFragmentUniformData(a0, a1, (const void *)a2, (Uint32)len2);
    return 0;
}

static int GenL_SDL_PushGPUVertexUniformData(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    size_t len2 = 0;
    const char *a2 = luaL_checklstring(L, 3, &len2);
    SDL_PushGPUVertexUniformData(a0, a1, (const void *)a2, (Uint32)len2);
    return 0;
}

static int GenL_SDL_PutAudioStreamData(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    bool rv = SDL_PutAudioStreamData(a0, (const void *)a1, (int)len1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_QueryGPUFence(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUFence *a1 = (SDL_GPUFence *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUFence");
    bool rv = SDL_QueryGPUFence(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_Quit(lua_State *L)
{
    (void)L;
    SDL_Quit();
    return 0;
}

static int GenL_SDL_QuitSubSystem(lua_State *L)
{
    (void)L;
    SDL_InitFlags a0 = (SDL_InitFlags)luaL_checkinteger(L, 1);
    SDL_QuitSubSystem(a0);
    return 0;
}

static int GenL_SDL_RaiseWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_RaiseWindow(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ReadS16BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint16 io1 = (Sint16)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadS16BE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadS16LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint16 io1 = (Sint16)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadS16LE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadS32BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint32 io1 = (Sint32)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadS32BE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadS32LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint32 io1 = (Sint32)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadS32LE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadS64BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint64 io1 = (Sint64)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadS64BE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadS64LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint64 io1 = (Sint64)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadS64LE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadS8(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint8 io1 = (Sint8)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadS8(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadSurfacePixel(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    Uint8 io3 = (Uint8)luaL_optinteger(L, 4, 0);
    Uint8 io4 = (Uint8)luaL_optinteger(L, 5, 0);
    Uint8 io5 = (Uint8)luaL_optinteger(L, 6, 0);
    Uint8 io6 = (Uint8)luaL_optinteger(L, 7, 0);
    bool rv = SDL_ReadSurfacePixel(a0, a1, a2, &io3, &io4, &io5, &io6);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    lua_pushinteger(L, (lua_Integer)io5);
    lua_pushinteger(L, (lua_Integer)io6);
    return 5;
}

static int GenL_SDL_ReadSurfacePixelFloat(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    float io5 = (float)luaL_optnumber(L, 6, 0);
    float io6 = (float)luaL_optnumber(L, 7, 0);
    bool rv = SDL_ReadSurfacePixelFloat(a0, a1, a2, &io3, &io4, &io5, &io6);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    lua_pushnumber(L, (lua_Number)io5);
    lua_pushnumber(L, (lua_Number)io6);
    return 5;
}

static int GenL_SDL_ReadU16BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint16 io1 = (Uint16)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadU16BE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadU16LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint16 io1 = (Uint16)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadU16LE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadU32BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint32 io1 = (Uint32)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadU32BE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadU32LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint32 io1 = (Uint32)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadU32LE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadU64BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint64 io1 = (Uint64)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadU64BE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadU64LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint64 io1 = (Uint64)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadU64LE(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ReadU8(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint8 io1 = (Uint8)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ReadU8(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_RegisterEvents(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    Uint32 rv = SDL_RegisterEvents(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_ReleaseCameraFrame(lua_State *L)
{
    (void)L;
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Camera");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Surface");
    SDL_ReleaseCameraFrame(a0, a1);
    return 0;
}

static int GenL_SDL_ReleaseGPUBuffer(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUBuffer");
    SDL_ReleaseGPUBuffer(a0, a1);
    return 0;
}

static int GenL_SDL_ReleaseGPUComputePipeline(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUComputePipeline *a1 = (SDL_GPUComputePipeline *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUComputePipeline");
    SDL_ReleaseGPUComputePipeline(a0, a1);
    return 0;
}

static int GenL_SDL_ReleaseGPUFence(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUFence *a1 = (SDL_GPUFence *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUFence");
    SDL_ReleaseGPUFence(a0, a1);
    return 0;
}

static int GenL_SDL_ReleaseGPUGraphicsPipeline(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUGraphicsPipeline *a1 = (SDL_GPUGraphicsPipeline *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUGraphicsPipeline");
    SDL_ReleaseGPUGraphicsPipeline(a0, a1);
    return 0;
}

static int GenL_SDL_ReleaseGPUSampler(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUSampler *a1 = (SDL_GPUSampler *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUSampler");
    SDL_ReleaseGPUSampler(a0, a1);
    return 0;
}

static int GenL_SDL_ReleaseGPUShader(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUShader *a1 = (SDL_GPUShader *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUShader");
    SDL_ReleaseGPUShader(a0, a1);
    return 0;
}

static int GenL_SDL_ReleaseGPUTexture(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUTexture");
    SDL_ReleaseGPUTexture(a0, a1);
    return 0;
}

static int GenL_SDL_ReleaseGPUTransferBuffer(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUTransferBuffer *a1 = (SDL_GPUTransferBuffer *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUTransferBuffer");
    SDL_ReleaseGPUTransferBuffer(a0, a1);
    return 0;
}

static int GenL_SDL_ReleaseWindowFromGPUDevice(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Window");
    SDL_ReleaseWindowFromGPUDevice(a0, a1);
    return 0;
}

static int GenL_SDL_ReloadGamepadMappings(lua_State *L)
{
    (void)L;
    bool rv = SDL_ReloadGamepadMappings();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RemovePath(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDL_RemovePath(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RemoveStoragePath(lua_State *L)
{
    (void)L;
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Storage");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_RemoveStoragePath(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RemoveSurfaceAlternateImages(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_RemoveSurfaceAlternateImages(a0);
    return 0;
}

static int GenL_SDL_RemoveTimer(lua_State *L)
{
    (void)L;
    SDL_TimerID a0 = (SDL_TimerID)luaL_checkinteger(L, 1);
    bool rv = SDL_RemoveTimer(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RemoveTrayEntry(lua_State *L)
{
    (void)L;
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayEntry");
    SDL_RemoveTrayEntry(a0);
    return 0;
}

static int GenL_SDL_RenamePath(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_RenamePath(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenameStoragePath(lua_State *L)
{
    (void)L;
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Storage");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDL_RenameStoragePath(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderClear(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    bool rv = SDL_RenderClear(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderClipEnabled(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    bool rv = SDL_RenderClipEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderCoordinatesFromWindow(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    bool rv = SDL_RenderCoordinatesFromWindow(a0, a1, a2, &io3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    return 3;
}

static int GenL_SDL_RenderCoordinatesToWindow(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    bool rv = SDL_RenderCoordinatesToWindow(a0, a1, a2, &io3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    return 3;
}

static int GenL_SDL_RenderDebugText(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = SDL_RenderDebugText(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderFillRect(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_FRect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_RenderFillRect(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderFillRects(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_FRect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_RenderFillRects(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderLine(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    bool rv = SDL_RenderLine(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderLines(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_FPoint tmp1;
    const SDL_FPoint *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_FPoint(L, 2, &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_RenderLines(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderPoint(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    bool rv = SDL_RenderPoint(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderPoints(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_FPoint tmp1;
    const SDL_FPoint *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_FPoint(L, 2, &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_RenderPoints(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderPresent(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    bool rv = SDL_RenderPresent(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderReadPixels(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface * rv = SDL_RenderReadPixels(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_SDL_RenderRect(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_FRect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_RenderRect(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderRects(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_FRect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_RenderRects(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderTexture(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_FRect(L, 3, &tmp2);
        a2 = &tmp2;
    }
    SDL_FRect tmp3;
    const SDL_FRect *a3 = NULL;
    if (!lua_isnoneornil(L, 4)) {
        GenRead_SDL_FRect(L, 4, &tmp3);
        a3 = &tmp3;
    }
    bool rv = SDL_RenderTexture(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderTexture9Grid(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_FRect(L, 3, &tmp2);
        a2 = &tmp2;
    }
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    float a7 = (float)luaL_checknumber(L, 8);
    SDL_FRect tmp8;
    const SDL_FRect *a8 = NULL;
    if (!lua_isnoneornil(L, 9)) {
        GenRead_SDL_FRect(L, 9, &tmp8);
        a8 = &tmp8;
    }
    bool rv = SDL_RenderTexture9Grid(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderTexture9GridTiled(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_FRect(L, 3, &tmp2);
        a2 = &tmp2;
    }
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    float a7 = (float)luaL_checknumber(L, 8);
    SDL_FRect tmp8;
    const SDL_FRect *a8 = NULL;
    if (!lua_isnoneornil(L, 9)) {
        GenRead_SDL_FRect(L, 9, &tmp8);
        a8 = &tmp8;
    }
    float a9 = (float)luaL_checknumber(L, 10);
    bool rv = SDL_RenderTexture9GridTiled(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderTextureAffine(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_FRect(L, 3, &tmp2);
        a2 = &tmp2;
    }
    SDL_FPoint tmp3;
    const SDL_FPoint *a3 = NULL;
    if (!lua_isnoneornil(L, 4)) {
        GenRead_SDL_FPoint(L, 4, &tmp3);
        a3 = &tmp3;
    }
    SDL_FPoint tmp4;
    const SDL_FPoint *a4 = NULL;
    if (!lua_isnoneornil(L, 5)) {
        GenRead_SDL_FPoint(L, 5, &tmp4);
        a4 = &tmp4;
    }
    SDL_FPoint tmp5;
    const SDL_FPoint *a5 = NULL;
    if (!lua_isnoneornil(L, 6)) {
        GenRead_SDL_FPoint(L, 6, &tmp5);
        a5 = &tmp5;
    }
    bool rv = SDL_RenderTextureAffine(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderTextureRotated(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_FRect(L, 3, &tmp2);
        a2 = &tmp2;
    }
    SDL_FRect tmp3;
    const SDL_FRect *a3 = NULL;
    if (!lua_isnoneornil(L, 4)) {
        GenRead_SDL_FRect(L, 4, &tmp3);
        a3 = &tmp3;
    }
    double a4 = (double)luaL_checknumber(L, 5);
    SDL_FPoint tmp5;
    const SDL_FPoint *a5 = NULL;
    if (!lua_isnoneornil(L, 6)) {
        GenRead_SDL_FPoint(L, 6, &tmp5);
        a5 = &tmp5;
    }
    SDL_FlipMode a6 = (SDL_FlipMode)luaL_checkinteger(L, 7);
    bool rv = SDL_RenderTextureRotated(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderTextureTiled(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_FRect(L, 3, &tmp2);
        a2 = &tmp2;
    }
    float a3 = (float)luaL_checknumber(L, 4);
    SDL_FRect tmp4;
    const SDL_FRect *a4 = NULL;
    if (!lua_isnoneornil(L, 5)) {
        GenRead_SDL_FRect(L, 5, &tmp4);
        a4 = &tmp4;
    }
    bool rv = SDL_RenderTextureTiled(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RenderViewportSet(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    bool rv = SDL_RenderViewportSet(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ResetAssertionReport(lua_State *L)
{
    (void)L;
    SDL_ResetAssertionReport();
    return 0;
}

static int GenL_SDL_ResetHint(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDL_ResetHint(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ResetHints(lua_State *L)
{
    (void)L;
    SDL_ResetHints();
    return 0;
}

static int GenL_SDL_ResetKeyboard(lua_State *L)
{
    (void)L;
    SDL_ResetKeyboard();
    return 0;
}

static int GenL_SDL_ResetLogPriorities(lua_State *L)
{
    (void)L;
    SDL_ResetLogPriorities();
    return 0;
}

static int GenL_SDL_RestoreWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_RestoreWindow(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ResumeAudioDevice(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    bool rv = SDL_ResumeAudioDevice(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ResumeAudioStreamDevice(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    bool rv = SDL_ResumeAudioStreamDevice(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ResumeHaptic(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    bool rv = SDL_ResumeHaptic(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RotateSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    float a1 = (float)luaL_checknumber(L, 2);
    SDL_Surface * rv = SDL_RotateSurface(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_SDL_RumbleGamepad(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    Uint16 a1 = (Uint16)luaL_checkinteger(L, 2);
    Uint16 a2 = (Uint16)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    bool rv = SDL_RumbleGamepad(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RumbleGamepadTriggers(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    Uint16 a1 = (Uint16)luaL_checkinteger(L, 2);
    Uint16 a2 = (Uint16)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    bool rv = SDL_RumbleGamepadTriggers(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RumbleJoystick(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    Uint16 a1 = (Uint16)luaL_checkinteger(L, 2);
    Uint16 a2 = (Uint16)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    bool rv = SDL_RumbleJoystick(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RumbleJoystickTriggers(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    Uint16 a1 = (Uint16)luaL_checkinteger(L, 2);
    Uint16 a2 = (Uint16)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    bool rv = SDL_RumbleJoystickTriggers(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_RunHapticEffect(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    SDL_HapticEffectID a1 = (SDL_HapticEffectID)luaL_checkinteger(L, 2);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    bool rv = SDL_RunHapticEffect(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SaveBMP(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_SaveBMP(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SaveBMP_IO(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = SDL_SaveBMP_IO(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SaveFile(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    bool rv = SDL_SaveFile(a0, (const void *)a1, (size_t)len1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SaveFile_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    bool a3 = (bool)lua_toboolean(L, 3);
    bool rv = SDL_SaveFile_IO(a0, (const void *)a1, (size_t)len1, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SavePNG(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_SavePNG(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SavePNG_IO(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = SDL_SavePNG_IO(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ScaleSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDL_ScaleMode a3 = (SDL_ScaleMode)luaL_checkinteger(L, 4);
    SDL_Surface * rv = SDL_ScaleSurface(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_SDL_ScreenKeyboardShown(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_ScreenKeyboardShown(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ScreenSaverEnabled(lua_State *L)
{
    (void)L;
    bool rv = SDL_ScreenSaverEnabled();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SeekIO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    SDL_IOWhence a2 = (SDL_IOWhence)luaL_checkinteger(L, 3);
    Sint64 rv = SDL_SeekIO(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_SendGamepadEffect(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    bool rv = SDL_SendGamepadEffect(a0, (const void *)a1, (int)len1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SendJoystickEffect(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    bool rv = SDL_SendJoystickEffect(a0, (const void *)a1, (int)len1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetAppMetadata(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDL_SetAppMetadata(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetAppMetadataProperty(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_SetAppMetadataProperty(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetAudioDeviceGain(lua_State *L)
{
    (void)L;
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)luaL_checkinteger(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = SDL_SetAudioDeviceGain(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetAudioStreamFormat(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    SDL_AudioSpec tmp1;
    const SDL_AudioSpec *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_AudioSpec(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_AudioSpec tmp2;
    const SDL_AudioSpec *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDL_AudioSpec(L, 3, &tmp2);
        a2 = &tmp2;
    }
    bool rv = SDL_SetAudioStreamFormat(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetAudioStreamFrequencyRatio(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = SDL_SetAudioStreamFrequencyRatio(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetAudioStreamGain(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = SDL_SetAudioStreamGain(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetBooleanProperty(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = SDL_SetBooleanProperty(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetClipboardText(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDL_SetClipboardText(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetCursor(lua_State *L)
{
    (void)L;
    SDL_Cursor *a0 = (SDL_Cursor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Cursor");
    bool rv = SDL_SetCursor(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetDefaultTextureScaleMode(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_ScaleMode a1 = (SDL_ScaleMode)luaL_checkinteger(L, 2);
    bool rv = SDL_SetDefaultTextureScaleMode(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetEnvironmentVariable(lua_State *L)
{
    (void)L;
    SDL_Environment *a0 = (SDL_Environment *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Environment");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool a3 = (bool)lua_toboolean(L, 4);
    bool rv = SDL_SetEnvironmentVariable(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetEventEnabled(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    bool a1 = (bool)lua_toboolean(L, 2);
    SDL_SetEventEnabled(a0, a1);
    return 0;
}

static int GenL_SDL_SetFloatProperty(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    bool rv = SDL_SetFloatProperty(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetGPUAllowedFramesInFlight(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    bool rv = SDL_SetGPUAllowedFramesInFlight(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetGPUBlendConstants(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    SDL_FColor a1;
    GenRead_SDL_FColor(L, 2, &a1);
    SDL_SetGPUBlendConstants(a0, a1);
    return 0;
}

static int GenL_SDL_SetGPUBufferName(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUBuffer");
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    SDL_SetGPUBufferName(a0, a1, a2);
    return 0;
}

static int GenL_SDL_SetGPURenderState(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_GPURenderState *a1 = (SDL_GPURenderState *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPURenderState");
    bool rv = SDL_SetGPURenderState(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetGPURenderStateFragmentUniforms(lua_State *L)
{
    (void)L;
    SDL_GPURenderState *a0 = (SDL_GPURenderState *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderState");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    size_t len2 = 0;
    const char *a2 = luaL_checklstring(L, 3, &len2);
    bool rv = SDL_SetGPURenderStateFragmentUniforms(a0, a1, (const void *)a2, (Uint32)len2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetGPUScissor(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_SetGPUScissor(a0, a1);
    return 0;
}

static int GenL_SDL_SetGPUStencilReference(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    SDL_SetGPUStencilReference(a0, a1);
    return 0;
}

static int GenL_SDL_SetGPUSwapchainParameters(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Window");
    SDL_GPUSwapchainComposition a2 = (SDL_GPUSwapchainComposition)luaL_checkinteger(L, 3);
    SDL_GPUPresentMode a3 = (SDL_GPUPresentMode)luaL_checkinteger(L, 4);
    bool rv = SDL_SetGPUSwapchainParameters(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetGPUTextureName(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUTexture");
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    SDL_SetGPUTextureName(a0, a1, a2);
    return 0;
}

static int GenL_SDL_SetGPUViewport(lua_State *L)
{
    (void)L;
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPURenderPass");
    SDL_GPUViewport tmp1;
    const SDL_GPUViewport *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_GPUViewport(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_SetGPUViewport(a0, a1);
    return 0;
}

static int GenL_SDL_SetGamepadEventsEnabled(lua_State *L)
{
    (void)L;
    bool a0 = (bool)lua_toboolean(L, 1);
    SDL_SetGamepadEventsEnabled(a0);
    return 0;
}

static int GenL_SDL_SetGamepadLED(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    bool rv = SDL_SetGamepadLED(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetGamepadMapping(lua_State *L)
{
    (void)L;
    SDL_JoystickID a0 = (SDL_JoystickID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_SetGamepadMapping(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetGamepadPlayerIndex(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDL_SetGamepadPlayerIndex(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetGamepadSensorEnabled(lua_State *L)
{
    (void)L;
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Gamepad");
    SDL_SensorType a1 = (SDL_SensorType)luaL_checkinteger(L, 2);
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = SDL_SetGamepadSensorEnabled(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetHapticAutocenter(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDL_SetHapticAutocenter(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetHapticGain(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDL_SetHapticGain(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetHint(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_SetHint(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetHintWithPriority(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_HintPriority a2 = (SDL_HintPriority)luaL_checkinteger(L, 3);
    bool rv = SDL_SetHintWithPriority(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetInitialized(lua_State *L)
{
    (void)L;
    SDL_InitState *a0 = (SDL_InitState *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_InitState");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDL_SetInitialized(a0, a1);
    return 0;
}

static int GenL_SDL_SetJoystickEventsEnabled(lua_State *L)
{
    (void)L;
    bool a0 = (bool)lua_toboolean(L, 1);
    SDL_SetJoystickEventsEnabled(a0);
    return 0;
}

static int GenL_SDL_SetJoystickLED(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    bool rv = SDL_SetJoystickLED(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetJoystickPlayerIndex(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDL_SetJoystickPlayerIndex(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetJoystickVirtualAxis(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int a1 = (int)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    bool rv = SDL_SetJoystickVirtualAxis(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetJoystickVirtualBall(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int a1 = (int)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    bool rv = SDL_SetJoystickVirtualBall(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetJoystickVirtualButton(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = SDL_SetJoystickVirtualButton(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetJoystickVirtualHat(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int a1 = (int)luaL_checkinteger(L, 2);
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    bool rv = SDL_SetJoystickVirtualHat(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetJoystickVirtualTouchpad(lua_State *L)
{
    (void)L;
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Joystick");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool a3 = (bool)lua_toboolean(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    bool rv = SDL_SetJoystickVirtualTouchpad(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetLogPriorities(lua_State *L)
{
    (void)L;
    SDL_LogPriority a0 = (SDL_LogPriority)luaL_checkinteger(L, 1);
    SDL_SetLogPriorities(a0);
    return 0;
}

static int GenL_SDL_SetLogPriority(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    SDL_LogPriority a1 = (SDL_LogPriority)luaL_checkinteger(L, 2);
    SDL_SetLogPriority(a0, a1);
    return 0;
}

static int GenL_SDL_SetLogPriorityPrefix(lua_State *L)
{
    (void)L;
    SDL_LogPriority a0 = (SDL_LogPriority)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_SetLogPriorityPrefix(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetModState(lua_State *L)
{
    (void)L;
    SDL_Keymod a0 = (SDL_Keymod)luaL_checkinteger(L, 1);
    SDL_SetModState(a0);
    return 0;
}

static int GenL_SDL_SetNumberProperty(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    Sint64 a2 = (Sint64)luaL_checkinteger(L, 3);
    bool rv = SDL_SetNumberProperty(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetPaletteColors(lua_State *L)
{
    (void)L;
    SDL_Palette *a0 = (SDL_Palette *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Palette");
    SDL_Color tmp1;
    const SDL_Color *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Color(L, 2, &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    bool rv = SDL_SetPaletteColors(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetPrimarySelectionText(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDL_SetPrimarySelectionText(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetRenderClipRect(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_SetRenderClipRect(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetRenderColorScale(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = SDL_SetRenderColorScale(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetRenderDrawBlendMode(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_BlendMode a1 = (SDL_BlendMode)luaL_checkinteger(L, 2);
    bool rv = SDL_SetRenderDrawBlendMode(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetRenderDrawColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    bool rv = SDL_SetRenderDrawColor(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetRenderDrawColorFloat(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    bool rv = SDL_SetRenderDrawColorFloat(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetRenderLogicalPresentation(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDL_RendererLogicalPresentation a3 = (SDL_RendererLogicalPresentation)luaL_checkinteger(L, 4);
    bool rv = SDL_SetRenderLogicalPresentation(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetRenderScale(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    bool rv = SDL_SetRenderScale(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetRenderTarget(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Texture");
    bool rv = SDL_SetRenderTarget(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetRenderTextureAddressMode(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_TextureAddressMode a1 = (SDL_TextureAddressMode)luaL_checkinteger(L, 2);
    SDL_TextureAddressMode a2 = (SDL_TextureAddressMode)luaL_checkinteger(L, 3);
    bool rv = SDL_SetRenderTextureAddressMode(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetRenderVSync(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDL_SetRenderVSync(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetRenderViewport(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_SetRenderViewport(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetScancodeName(lua_State *L)
{
    (void)L;
    SDL_Scancode a0 = (SDL_Scancode)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_SetScancodeName(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetStringProperty(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDL_SetStringProperty(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetSurfaceAlphaMod(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    bool rv = SDL_SetSurfaceAlphaMod(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetSurfaceBlendMode(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_BlendMode a1 = (SDL_BlendMode)luaL_checkinteger(L, 2);
    bool rv = SDL_SetSurfaceBlendMode(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetSurfaceClipRect(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_SetSurfaceClipRect(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetSurfaceColorKey(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    bool a1 = (bool)lua_toboolean(L, 2);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    bool rv = SDL_SetSurfaceColorKey(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetSurfaceColorMod(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    bool rv = SDL_SetSurfaceColorMod(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetSurfaceColorspace(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Colorspace a1 = (SDL_Colorspace)luaL_checkinteger(L, 2);
    bool rv = SDL_SetSurfaceColorspace(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetSurfacePalette(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Palette *a1 = (SDL_Palette *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Palette");
    bool rv = SDL_SetSurfacePalette(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetSurfaceRLE(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_SetSurfaceRLE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetTextInputArea(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_SetTextInputArea(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetTextureAlphaMod(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    bool rv = SDL_SetTextureAlphaMod(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetTextureAlphaModFloat(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = SDL_SetTextureAlphaModFloat(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetTextureBlendMode(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    SDL_BlendMode a1 = (SDL_BlendMode)luaL_checkinteger(L, 2);
    bool rv = SDL_SetTextureBlendMode(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetTextureColorMod(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    bool rv = SDL_SetTextureColorMod(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetTextureColorModFloat(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    bool rv = SDL_SetTextureColorModFloat(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetTexturePalette(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    SDL_Palette *a1 = (SDL_Palette *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Palette");
    bool rv = SDL_SetTexturePalette(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetTextureScaleMode(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    SDL_ScaleMode a1 = (SDL_ScaleMode)luaL_checkinteger(L, 2);
    bool rv = SDL_SetTextureScaleMode(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetTrayEntryChecked(lua_State *L)
{
    (void)L;
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayEntry");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDL_SetTrayEntryChecked(a0, a1);
    return 0;
}

static int GenL_SDL_SetTrayEntryEnabled(lua_State *L)
{
    (void)L;
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayEntry");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDL_SetTrayEntryEnabled(a0, a1);
    return 0;
}

static int GenL_SDL_SetTrayEntryLabel(lua_State *L)
{
    (void)L;
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_TrayEntry");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_SetTrayEntryLabel(a0, a1);
    return 0;
}

static int GenL_SDL_SetTrayIcon(lua_State *L)
{
    (void)L;
    SDL_Tray *a0 = (SDL_Tray *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Tray");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Surface");
    SDL_SetTrayIcon(a0, a1);
    return 0;
}

static int GenL_SDL_SetTrayTooltip(lua_State *L)
{
    (void)L;
    SDL_Tray *a0 = (SDL_Tray *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Tray");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_SetTrayTooltip(a0, a1);
    return 0;
}

static int GenL_SDL_SetWindowAlwaysOnTop(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_SetWindowAlwaysOnTop(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowAspectRatio(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    bool rv = SDL_SetWindowAspectRatio(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowBordered(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_SetWindowBordered(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowFillDocument(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_SetWindowFillDocument(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowFocusable(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_SetWindowFocusable(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowFullscreen(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_SetWindowFullscreen(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowFullscreenMode(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    const SDL_DisplayMode *a1 = (const SDL_DisplayMode *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_DisplayMode");
    bool rv = SDL_SetWindowFullscreenMode(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowIcon(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Surface");
    bool rv = SDL_SetWindowIcon(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowKeyboardGrab(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_SetWindowKeyboardGrab(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowMaximumSize(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_SetWindowMaximumSize(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowMinimumSize(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_SetWindowMinimumSize(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowModal(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_SetWindowModal(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowMouseGrab(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_SetWindowMouseGrab(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowMouseRect(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_SetWindowMouseRect(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowOpacity(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = SDL_SetWindowOpacity(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowParent(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Window");
    bool rv = SDL_SetWindowParent(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowPosition(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_SetWindowPosition(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowProgressState(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_ProgressState a1 = (SDL_ProgressState)luaL_checkinteger(L, 2);
    bool rv = SDL_SetWindowProgressState(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowProgressValue(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = SDL_SetWindowProgressValue(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowRelativeMouseMode(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_SetWindowRelativeMouseMode(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowResizable(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_SetWindowResizable(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowShape(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Surface");
    bool rv = SDL_SetWindowShape(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowSize(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_SetWindowSize(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowSurfaceVSync(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDL_SetWindowSurfaceVSync(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SetWindowTitle(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_SetWindowTitle(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ShouldInit(lua_State *L)
{
    (void)L;
    SDL_InitState *a0 = (SDL_InitState *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_InitState");
    bool rv = SDL_ShouldInit(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ShouldQuit(lua_State *L)
{
    (void)L;
    SDL_InitState *a0 = (SDL_InitState *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_InitState");
    bool rv = SDL_ShouldQuit(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ShowCursor(lua_State *L)
{
    (void)L;
    bool rv = SDL_ShowCursor();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ShowMessageBox(lua_State *L)
{
    (void)L;
    const SDL_MessageBoxData *a0 = (const SDL_MessageBoxData *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_MessageBoxData");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    bool rv = SDL_ShowMessageBox(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDL_ShowSimpleMessageBox(lua_State *L)
{
    (void)L;
    SDL_MessageBoxFlags a0 = (SDL_MessageBoxFlags)luaL_checkinteger(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    SDL_Window *a3 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 4, "SDL_Window");
    bool rv = SDL_ShowSimpleMessageBox(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ShowWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_ShowWindow(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_ShowWindowSystemMenu(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_ShowWindowSystemMenu(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SignalAsyncIOQueue(lua_State *L)
{
    (void)L;
    SDL_AsyncIOQueue *a0 = (SDL_AsyncIOQueue *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AsyncIOQueue");
    SDL_SignalAsyncIOQueue(a0);
    return 0;
}

static int GenL_SDL_StartTextInput(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_StartTextInput(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_StartTextInputWithProperties(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_PropertiesID a1 = (SDL_PropertiesID)luaL_checkinteger(L, 2);
    bool rv = SDL_StartTextInputWithProperties(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_StopHapticEffect(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    SDL_HapticEffectID a1 = (SDL_HapticEffectID)luaL_checkinteger(L, 2);
    bool rv = SDL_StopHapticEffect(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_StopHapticEffects(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    bool rv = SDL_StopHapticEffects(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_StopHapticRumble(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    bool rv = SDL_StopHapticRumble(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_StopTextInput(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_StopTextInput(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_StorageReady(lua_State *L)
{
    (void)L;
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Storage");
    bool rv = SDL_StorageReady(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_StretchSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (!lua_isnoneornil(L, 4)) {
        GenRead_SDL_Rect(L, 4, &tmp3);
        a3 = &tmp3;
    }
    SDL_ScaleMode a4 = (SDL_ScaleMode)luaL_checkinteger(L, 5);
    bool rv = SDL_StretchSurface(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_StringToGUID(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_GUID rv = SDL_StringToGUID(a0);
    GenPush_SDL_GUID(L, &rv);
    return 1;
}

static int GenL_SDL_SubmitGPUCommandBuffer(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    bool rv = SDL_SubmitGPUCommandBuffer(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SubmitGPUCommandBufferAndAcquireFence(lua_State *L)
{
    (void)L;
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCommandBuffer");
    SDL_GPUFence * rv = SDL_SubmitGPUCommandBufferAndAcquireFence(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUFence");
    return 1;
}

static int GenL_SDL_SurfaceHasAlternateImages(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    bool rv = SDL_SurfaceHasAlternateImages(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SurfaceHasColorKey(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    bool rv = SDL_SurfaceHasColorKey(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SurfaceHasRLE(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    bool rv = SDL_SurfaceHasRLE(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_SyncWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_SyncWindow(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_TellIO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint64 rv = SDL_TellIO(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_TextInputActive(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_TextInputActive(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_TimeFromWindows(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    SDL_Time rv = SDL_TimeFromWindows(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_TimeToDateTime(lua_State *L)
{
    (void)L;
    SDL_Time a0 = (SDL_Time)luaL_checkinteger(L, 1);
    SDL_DateTime out1;
    memset(&out1, 0, sizeof(out1));
    bool a2 = (bool)lua_toboolean(L, 2);
    bool rv = SDL_TimeToDateTime(a0, &out1, a2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_DateTime(L, &out1);
    return 2;
}

static int GenL_SDL_TimeToWindows(lua_State *L)
{
    (void)L;
    SDL_Time a0 = (SDL_Time)luaL_checkinteger(L, 1);
    Uint32 io1 = (Uint32)luaL_optinteger(L, 2, 0);
    Uint32 io2 = (Uint32)luaL_optinteger(L, 3, 0);
    SDL_TimeToWindows(a0, &io1, &io2);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_SDL_TryLockSpinlock(lua_State *L)
{
    (void)L;
    SDL_SpinLock io0 = (SDL_SpinLock)luaL_optinteger(L, 1, 0);
    bool rv = SDL_TryLockSpinlock(&io0);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io0);
    return 2;
}

static int GenL_SDL_UnbindAudioStream(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    SDL_UnbindAudioStream(a0);
    return 0;
}

static int GenL_SDL_UnloadObject(lua_State *L)
{
    (void)L;
    SDL_SharedObject *a0 = (SDL_SharedObject *)SDLStaticGen_LuaTakeHandle(L, 1, "SDL_SharedObject");
    SDL_UnloadObject(a0);
    return 0;
}

static int GenL_SDL_UnlockAudioStream(lua_State *L)
{
    (void)L;
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AudioStream");
    bool rv = SDL_UnlockAudioStream(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_UnlockProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    SDL_UnlockProperties(a0);
    return 0;
}

static int GenL_SDL_UnlockSpinlock(lua_State *L)
{
    (void)L;
    SDL_SpinLock io0 = (SDL_SpinLock)luaL_optinteger(L, 1, 0);
    SDL_UnlockSpinlock(&io0);
    lua_pushinteger(L, (lua_Integer)io0);
    return 1;
}

static int GenL_SDL_UnlockSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_UnlockSurface(a0);
    return 0;
}

static int GenL_SDL_UnlockTexture(lua_State *L)
{
    (void)L;
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Texture");
    SDL_UnlockTexture(a0);
    return 0;
}

static int GenL_SDL_UnmapGPUTransferBuffer(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUTransferBuffer *a1 = (SDL_GPUTransferBuffer *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUTransferBuffer");
    SDL_UnmapGPUTransferBuffer(a0, a1);
    return 0;
}

static int GenL_SDL_UnsetEnvironmentVariable(lua_State *L)
{
    (void)L;
    SDL_Environment *a0 = (SDL_Environment *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Environment");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDL_UnsetEnvironmentVariable(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_UpdateGamepads(lua_State *L)
{
    (void)L;
    SDL_UpdateGamepads();
    return 0;
}

static int GenL_SDL_UpdateHapticEffect(lua_State *L)
{
    (void)L;
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Haptic");
    SDL_HapticEffectID a1 = (SDL_HapticEffectID)luaL_checkinteger(L, 2);
    const SDL_HapticEffect *a2 = (const SDL_HapticEffect *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_HapticEffect");
    bool rv = SDL_UpdateHapticEffect(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_UpdateJoysticks(lua_State *L)
{
    (void)L;
    SDL_UpdateJoysticks();
    return 0;
}

static int GenL_SDL_UpdateSensors(lua_State *L)
{
    (void)L;
    SDL_UpdateSensors();
    return 0;
}

static int GenL_SDL_UpdateTrays(lua_State *L)
{
    (void)L;
    SDL_UpdateTrays();
    return 0;
}

static int GenL_SDL_UpdateWindowSurface(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_UpdateWindowSurface(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_UpdateWindowSurfaceRects(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDL_Rect(L, 2, &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDL_UpdateWindowSurfaceRects(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_UploadToGPUBuffer(lua_State *L)
{
    (void)L;
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCopyPass");
    const SDL_GPUTransferBufferLocation *a1 = (const SDL_GPUTransferBufferLocation *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUTransferBufferLocation");
    const SDL_GPUBufferRegion *a2 = (const SDL_GPUBufferRegion *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_GPUBufferRegion");
    bool a3 = (bool)lua_toboolean(L, 4);
    SDL_UploadToGPUBuffer(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDL_UploadToGPUTexture(lua_State *L)
{
    (void)L;
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUCopyPass");
    const SDL_GPUTextureTransferInfo *a1 = (const SDL_GPUTextureTransferInfo *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUTextureTransferInfo");
    const SDL_GPUTextureRegion *a2 = (const SDL_GPUTextureRegion *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_GPUTextureRegion");
    bool a3 = (bool)lua_toboolean(L, 4);
    SDL_UploadToGPUTexture(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDL_WaitAsyncIOResult(lua_State *L)
{
    (void)L;
    SDL_AsyncIOQueue *a0 = (SDL_AsyncIOQueue *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_AsyncIOQueue");
    SDL_AsyncIOOutcome *a1 = (SDL_AsyncIOOutcome *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_AsyncIOOutcome");
    Sint32 a2 = (Sint32)luaL_checkinteger(L, 3);
    bool rv = SDL_WaitAsyncIOResult(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WaitEvent(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    bool rv = SDL_WaitEvent(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WaitEventTimeout(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    Sint32 a1 = (Sint32)luaL_checkinteger(L, 2);
    bool rv = SDL_WaitEventTimeout(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WaitForGPUIdle(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    bool rv = SDL_WaitForGPUIdle(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WaitForGPUSwapchain(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Window");
    bool rv = SDL_WaitForGPUSwapchain(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WaitProcess(lua_State *L)
{
    (void)L;
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Process");
    bool a1 = (bool)lua_toboolean(L, 2);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    bool rv = SDL_WaitProcess(a0, a1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_SDL_WarpMouseGlobal(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = SDL_WarpMouseGlobal(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WarpMouseInWindow(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDL_WarpMouseInWindow(a0, a1, a2);
    return 0;
}

static int GenL_SDL_WasInit(lua_State *L)
{
    (void)L;
    SDL_InitFlags a0 = (SDL_InitFlags)luaL_checkinteger(L, 1);
    SDL_InitFlags rv = SDL_WasInit(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_WindowHasSurface(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    bool rv = SDL_WindowHasSurface(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WindowSupportsGPUPresentMode(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Window");
    SDL_GPUPresentMode a2 = (SDL_GPUPresentMode)luaL_checkinteger(L, 3);
    bool rv = SDL_WindowSupportsGPUPresentMode(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WindowSupportsGPUSwapchainComposition(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Window");
    SDL_GPUSwapchainComposition a2 = (SDL_GPUSwapchainComposition)luaL_checkinteger(L, 3);
    bool rv = SDL_WindowSupportsGPUSwapchainComposition(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteIO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    size_t rv = SDL_WriteIO(a0, (const void *)a1, (size_t)len1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_WriteS16BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteS16BE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteS16LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteS16LE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteS32BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint32 a1 = (Sint32)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteS32BE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteS32LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint32 a1 = (Sint32)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteS32LE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteS64BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteS64BE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteS64LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint64 a1 = (Sint64)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteS64LE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteS8(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Sint8 a1 = (Sint8)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteS8(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteStorageFile(lua_State *L)
{
    (void)L;
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Storage");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t len2 = 0;
    const char *a2 = luaL_checklstring(L, 3, &len2);
    bool rv = SDL_WriteStorageFile(a0, a1, (const void *)a2, (Uint64)len2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteSurfacePixel(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    bool rv = SDL_WriteSurfacePixel(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteSurfacePixelFloat(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    bool rv = SDL_WriteSurfacePixelFloat(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteU16BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint16 a1 = (Uint16)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteU16BE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteU16LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint16 a1 = (Uint16)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteU16LE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteU32BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteU32BE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteU32LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteU32LE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteU64BE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint64 a1 = (Uint64)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteU64BE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteU64LE(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint64 a1 = (Uint64)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteU64LE(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_WriteU8(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    bool rv = SDL_WriteU8(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDL_getenv(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char * rv = SDL_getenv(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_getenv_unsafe(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char * rv = SDL_getenv_unsafe(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDL_hid_ble_scan(lua_State *L)
{
    (void)L;
    bool a0 = (bool)lua_toboolean(L, 1);
    SDL_hid_ble_scan(a0);
    return 0;
}

static int GenL_SDL_hid_close(lua_State *L)
{
    (void)L;
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_hid_device");
    int rv = SDL_hid_close(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_hid_device_change_count(lua_State *L)
{
    (void)L;
    Uint32 rv = SDL_hid_device_change_count();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_hid_enumerate(lua_State *L)
{
    (void)L;
    unsigned short a0 = (unsigned short)luaL_checkinteger(L, 1);
    unsigned short a1 = (unsigned short)luaL_checkinteger(L, 2);
    SDL_hid_device_info * rv = SDL_hid_enumerate(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_hid_device_info");
    return 1;
}

static int GenL_SDL_hid_exit(lua_State *L)
{
    (void)L;
    int rv = SDL_hid_exit();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_hid_free_enumeration(lua_State *L)
{
    (void)L;
    SDL_hid_device_info *a0 = (SDL_hid_device_info *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_hid_device_info");
    SDL_hid_free_enumeration(a0);
    return 0;
}

static int GenL_SDL_hid_get_device_info(lua_State *L)
{
    (void)L;
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_hid_device");
    SDL_hid_device_info * rv = SDL_hid_get_device_info(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_hid_device_info");
    return 1;
}

static int GenL_SDL_hid_get_properties(lua_State *L)
{
    (void)L;
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_hid_device");
    SDL_PropertiesID rv = SDL_hid_get_properties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_hid_init(lua_State *L)
{
    (void)L;
    int rv = SDL_hid_init();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_hid_open_path(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_hid_device * rv = SDL_hid_open_path(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_hid_device");
    return 1;
}

static int GenL_SDL_hid_send_feature_report(lua_State *L)
{
    (void)L;
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_hid_device");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    int rv = SDL_hid_send_feature_report(a0, (const void *)a1, (size_t)len1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_hid_set_nonblocking(lua_State *L)
{
    (void)L;
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_hid_device");
    int a1 = (int)luaL_checkinteger(L, 2);
    int rv = SDL_hid_set_nonblocking(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_hid_write(lua_State *L)
{
    (void)L;
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_hid_device");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    int rv = SDL_hid_write(a0, (const void *)a1, (size_t)len1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_iconv_string(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    size_t a3 = (size_t)luaL_checkinteger(L, 4);
    char * rv = SDL_iconv_string(a0, a1, a2, a3);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDL_setenv_unsafe(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int rv = SDL_setenv_unsafe(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_unsetenv_unsafe(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int rv = SDL_unsetenv_unsafe(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_utf8strlen(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    size_t rv = SDL_utf8strlen(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDL_utf8strnlen(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    size_t a1 = (size_t)luaL_checkinteger(L, 2);
    size_t rv = SDL_utf8strnlen(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

int SDLStaticGen_OpenLua_sdl(lua_State *L);
int SDLStaticGen_OpenLua_sdl(lua_State *L)
{
    lua_createtable(L, 0, 871);
    lua_pushcfunction(L, GenL_SDL_AcquireCameraFrame);
    lua_setfield(L, -2, "AcquireCameraFrame");
    lua_pushcfunction(L, GenL_SDL_AcquireGPUCommandBuffer);
    lua_setfield(L, -2, "AcquireGPUCommandBuffer");
    lua_pushcfunction(L, GenL_SDL_AddGamepadMapping);
    lua_setfield(L, -2, "AddGamepadMapping");
    lua_pushcfunction(L, GenL_SDL_AddGamepadMappingsFromFile);
    lua_setfield(L, -2, "AddGamepadMappingsFromFile");
    lua_pushcfunction(L, GenL_SDL_AddGamepadMappingsFromIO);
    lua_setfield(L, -2, "AddGamepadMappingsFromIO");
    lua_pushcfunction(L, GenL_SDL_AddSurfaceAlternateImage);
    lua_setfield(L, -2, "AddSurfaceAlternateImage");
    lua_pushcfunction(L, GenL_SDL_AddVulkanRenderSemaphores);
    lua_setfield(L, -2, "AddVulkanRenderSemaphores");
    lua_pushcfunction(L, GenL_SDL_AsyncIOFromFile);
    lua_setfield(L, -2, "AsyncIOFromFile");
    lua_pushcfunction(L, GenL_SDL_AttachVirtualJoystick);
    lua_setfield(L, -2, "AttachVirtualJoystick");
    lua_pushcfunction(L, GenL_SDL_AudioDevicePaused);
    lua_setfield(L, -2, "AudioDevicePaused");
    lua_pushcfunction(L, GenL_SDL_AudioStreamDevicePaused);
    lua_setfield(L, -2, "AudioStreamDevicePaused");
    lua_pushcfunction(L, GenL_SDL_BeginGPUComputePass);
    lua_setfield(L, -2, "BeginGPUComputePass");
    lua_pushcfunction(L, GenL_SDL_BeginGPUCopyPass);
    lua_setfield(L, -2, "BeginGPUCopyPass");
    lua_pushcfunction(L, GenL_SDL_BeginGPURenderPass);
    lua_setfield(L, -2, "BeginGPURenderPass");
    lua_pushcfunction(L, GenL_SDL_BindAudioStream);
    lua_setfield(L, -2, "BindAudioStream");
    lua_pushcfunction(L, GenL_SDL_BindGPUComputePipeline);
    lua_setfield(L, -2, "BindGPUComputePipeline");
    lua_pushcfunction(L, GenL_SDL_BindGPUComputeSamplers);
    lua_setfield(L, -2, "BindGPUComputeSamplers");
    lua_pushcfunction(L, GenL_SDL_BindGPUFragmentSamplers);
    lua_setfield(L, -2, "BindGPUFragmentSamplers");
    lua_pushcfunction(L, GenL_SDL_BindGPUGraphicsPipeline);
    lua_setfield(L, -2, "BindGPUGraphicsPipeline");
    lua_pushcfunction(L, GenL_SDL_BindGPUIndexBuffer);
    lua_setfield(L, -2, "BindGPUIndexBuffer");
    lua_pushcfunction(L, GenL_SDL_BindGPUVertexBuffers);
    lua_setfield(L, -2, "BindGPUVertexBuffers");
    lua_pushcfunction(L, GenL_SDL_BindGPUVertexSamplers);
    lua_setfield(L, -2, "BindGPUVertexSamplers");
    lua_pushcfunction(L, GenL_SDL_BlitGPUTexture);
    lua_setfield(L, -2, "BlitGPUTexture");
    lua_pushcfunction(L, GenL_SDL_BlitSurface);
    lua_setfield(L, -2, "BlitSurface");
    lua_pushcfunction(L, GenL_SDL_BlitSurface9Grid);
    lua_setfield(L, -2, "BlitSurface9Grid");
    lua_pushcfunction(L, GenL_SDL_BlitSurfaceScaled);
    lua_setfield(L, -2, "BlitSurfaceScaled");
    lua_pushcfunction(L, GenL_SDL_BlitSurfaceTiled);
    lua_setfield(L, -2, "BlitSurfaceTiled");
    lua_pushcfunction(L, GenL_SDL_BlitSurfaceTiledWithScale);
    lua_setfield(L, -2, "BlitSurfaceTiledWithScale");
    lua_pushcfunction(L, GenL_SDL_BlitSurfaceUnchecked);
    lua_setfield(L, -2, "BlitSurfaceUnchecked");
    lua_pushcfunction(L, GenL_SDL_BlitSurfaceUncheckedScaled);
    lua_setfield(L, -2, "BlitSurfaceUncheckedScaled");
    lua_pushcfunction(L, GenL_SDL_CalculateGPUTextureFormatSize);
    lua_setfield(L, -2, "CalculateGPUTextureFormatSize");
    lua_pushcfunction(L, GenL_SDL_CancelGPUCommandBuffer);
    lua_setfield(L, -2, "CancelGPUCommandBuffer");
    lua_pushcfunction(L, GenL_SDL_CaptureMouse);
    lua_setfield(L, -2, "CaptureMouse");
    lua_pushcfunction(L, GenL_SDL_ClaimWindowForGPUDevice);
    lua_setfield(L, -2, "ClaimWindowForGPUDevice");
    lua_pushcfunction(L, GenL_SDL_ClearAudioStream);
    lua_setfield(L, -2, "ClearAudioStream");
    lua_pushcfunction(L, GenL_SDL_ClearClipboardData);
    lua_setfield(L, -2, "ClearClipboardData");
    lua_pushcfunction(L, GenL_SDL_ClearComposition);
    lua_setfield(L, -2, "ClearComposition");
    lua_pushcfunction(L, GenL_SDL_ClearError);
    lua_setfield(L, -2, "ClearError");
    lua_pushcfunction(L, GenL_SDL_ClearProperty);
    lua_setfield(L, -2, "ClearProperty");
    lua_pushcfunction(L, GenL_SDL_ClearSurface);
    lua_setfield(L, -2, "ClearSurface");
    lua_pushcfunction(L, GenL_SDL_ClickTrayEntry);
    lua_setfield(L, -2, "ClickTrayEntry");
    lua_pushcfunction(L, GenL_SDL_CloseAudioDevice);
    lua_setfield(L, -2, "CloseAudioDevice");
    lua_pushcfunction(L, GenL_SDL_CloseCamera);
    lua_setfield(L, -2, "CloseCamera");
    lua_pushcfunction(L, GenL_SDL_CloseGamepad);
    lua_setfield(L, -2, "CloseGamepad");
    lua_pushcfunction(L, GenL_SDL_CloseHaptic);
    lua_setfield(L, -2, "CloseHaptic");
    lua_pushcfunction(L, GenL_SDL_CloseIO);
    lua_setfield(L, -2, "CloseIO");
    lua_pushcfunction(L, GenL_SDL_CloseJoystick);
    lua_setfield(L, -2, "CloseJoystick");
    lua_pushcfunction(L, GenL_SDL_CloseSensor);
    lua_setfield(L, -2, "CloseSensor");
    lua_pushcfunction(L, GenL_SDL_CloseStorage);
    lua_setfield(L, -2, "CloseStorage");
    lua_pushcfunction(L, GenL_SDL_CompareAndSwapAtomicInt);
    lua_setfield(L, -2, "CompareAndSwapAtomicInt");
    lua_pushcfunction(L, GenL_SDL_CompareAndSwapAtomicU32);
    lua_setfield(L, -2, "CompareAndSwapAtomicU32");
    lua_pushcfunction(L, GenL_SDL_ComposeCustomBlendMode);
    lua_setfield(L, -2, "ComposeCustomBlendMode");
    lua_pushcfunction(L, GenL_SDL_ConvertEventToRenderCoordinates);
    lua_setfield(L, -2, "ConvertEventToRenderCoordinates");
    lua_pushcfunction(L, GenL_SDL_ConvertSurface);
    lua_setfield(L, -2, "ConvertSurface");
    lua_pushcfunction(L, GenL_SDL_ConvertSurfaceAndColorspace);
    lua_setfield(L, -2, "ConvertSurfaceAndColorspace");
    lua_pushcfunction(L, GenL_SDL_CopyFile);
    lua_setfield(L, -2, "CopyFile");
    lua_pushcfunction(L, GenL_SDL_CopyGPUBufferToBuffer);
    lua_setfield(L, -2, "CopyGPUBufferToBuffer");
    lua_pushcfunction(L, GenL_SDL_CopyGPUTextureToTexture);
    lua_setfield(L, -2, "CopyGPUTextureToTexture");
    lua_pushcfunction(L, GenL_SDL_CopyProperties);
    lua_setfield(L, -2, "CopyProperties");
    lua_pushcfunction(L, GenL_SDL_CopyStorageFile);
    lua_setfield(L, -2, "CopyStorageFile");
    lua_pushcfunction(L, GenL_SDL_CreateAnimatedCursor);
    lua_setfield(L, -2, "CreateAnimatedCursor");
    lua_pushcfunction(L, GenL_SDL_CreateAsyncIOQueue);
    lua_setfield(L, -2, "CreateAsyncIOQueue");
    lua_pushcfunction(L, GenL_SDL_CreateAudioStream);
    lua_setfield(L, -2, "CreateAudioStream");
    lua_pushcfunction(L, GenL_SDL_CreateColorCursor);
    lua_setfield(L, -2, "CreateColorCursor");
    lua_pushcfunction(L, GenL_SDL_CreateDirectory);
    lua_setfield(L, -2, "CreateDirectory");
    lua_pushcfunction(L, GenL_SDL_CreateEnvironment);
    lua_setfield(L, -2, "CreateEnvironment");
    lua_pushcfunction(L, GenL_SDL_CreateGPUBuffer);
    lua_setfield(L, -2, "CreateGPUBuffer");
    lua_pushcfunction(L, GenL_SDL_CreateGPUComputePipeline);
    lua_setfield(L, -2, "CreateGPUComputePipeline");
    lua_pushcfunction(L, GenL_SDL_CreateGPUDevice);
    lua_setfield(L, -2, "CreateGPUDevice");
    lua_pushcfunction(L, GenL_SDL_CreateGPUDeviceWithProperties);
    lua_setfield(L, -2, "CreateGPUDeviceWithProperties");
    lua_pushcfunction(L, GenL_SDL_CreateGPUGraphicsPipeline);
    lua_setfield(L, -2, "CreateGPUGraphicsPipeline");
    lua_pushcfunction(L, GenL_SDL_CreateGPURenderState);
    lua_setfield(L, -2, "CreateGPURenderState");
    lua_pushcfunction(L, GenL_SDL_CreateGPURenderer);
    lua_setfield(L, -2, "CreateGPURenderer");
    lua_pushcfunction(L, GenL_SDL_CreateGPUSampler);
    lua_setfield(L, -2, "CreateGPUSampler");
    lua_pushcfunction(L, GenL_SDL_CreateGPUShader);
    lua_setfield(L, -2, "CreateGPUShader");
    lua_pushcfunction(L, GenL_SDL_CreateGPUTexture);
    lua_setfield(L, -2, "CreateGPUTexture");
    lua_pushcfunction(L, GenL_SDL_CreateGPUTransferBuffer);
    lua_setfield(L, -2, "CreateGPUTransferBuffer");
    lua_pushcfunction(L, GenL_SDL_CreateHapticEffect);
    lua_setfield(L, -2, "CreateHapticEffect");
    lua_pushcfunction(L, GenL_SDL_CreatePalette);
    lua_setfield(L, -2, "CreatePalette");
    lua_pushcfunction(L, GenL_SDL_CreatePopupWindow);
    lua_setfield(L, -2, "CreatePopupWindow");
    lua_pushcfunction(L, GenL_SDL_CreateProcessWithProperties);
    lua_setfield(L, -2, "CreateProcessWithProperties");
    lua_pushcfunction(L, GenL_SDL_CreateProperties);
    lua_setfield(L, -2, "CreateProperties");
    lua_pushcfunction(L, GenL_SDL_CreateRenderer);
    lua_setfield(L, -2, "CreateRenderer");
    lua_pushcfunction(L, GenL_SDL_CreateRendererWithProperties);
    lua_setfield(L, -2, "CreateRendererWithProperties");
    lua_pushcfunction(L, GenL_SDL_CreateSoftwareRenderer);
    lua_setfield(L, -2, "CreateSoftwareRenderer");
    lua_pushcfunction(L, GenL_SDL_CreateStorageDirectory);
    lua_setfield(L, -2, "CreateStorageDirectory");
    lua_pushcfunction(L, GenL_SDL_CreateSurface);
    lua_setfield(L, -2, "CreateSurface");
    lua_pushcfunction(L, GenL_SDL_CreateSurfacePalette);
    lua_setfield(L, -2, "CreateSurfacePalette");
    lua_pushcfunction(L, GenL_SDL_CreateSystemCursor);
    lua_setfield(L, -2, "CreateSystemCursor");
    lua_pushcfunction(L, GenL_SDL_CreateTexture);
    lua_setfield(L, -2, "CreateTexture");
    lua_pushcfunction(L, GenL_SDL_CreateTextureFromSurface);
    lua_setfield(L, -2, "CreateTextureFromSurface");
    lua_pushcfunction(L, GenL_SDL_CreateTextureWithProperties);
    lua_setfield(L, -2, "CreateTextureWithProperties");
    lua_pushcfunction(L, GenL_SDL_CreateTray);
    lua_setfield(L, -2, "CreateTray");
    lua_pushcfunction(L, GenL_SDL_CreateTrayMenu);
    lua_setfield(L, -2, "CreateTrayMenu");
    lua_pushcfunction(L, GenL_SDL_CreateTraySubmenu);
    lua_setfield(L, -2, "CreateTraySubmenu");
    lua_pushcfunction(L, GenL_SDL_CreateWindow);
    lua_setfield(L, -2, "CreateWindow");
    lua_pushcfunction(L, GenL_SDL_CreateWindowWithProperties);
    lua_setfield(L, -2, "CreateWindowWithProperties");
    lua_pushcfunction(L, GenL_SDL_CursorVisible);
    lua_setfield(L, -2, "CursorVisible");
    lua_pushcfunction(L, GenL_SDL_DateTimeToTime);
    lua_setfield(L, -2, "DateTimeToTime");
    lua_pushcfunction(L, GenL_SDL_Delay);
    lua_setfield(L, -2, "Delay");
    lua_pushcfunction(L, GenL_SDL_DelayNS);
    lua_setfield(L, -2, "DelayNS");
    lua_pushcfunction(L, GenL_SDL_DelayPrecise);
    lua_setfield(L, -2, "DelayPrecise");
    lua_pushcfunction(L, GenL_SDL_DestroyAsyncIOQueue);
    lua_setfield(L, -2, "DestroyAsyncIOQueue");
    lua_pushcfunction(L, GenL_SDL_DestroyAudioStream);
    lua_setfield(L, -2, "DestroyAudioStream");
    lua_pushcfunction(L, GenL_SDL_DestroyCursor);
    lua_setfield(L, -2, "DestroyCursor");
    lua_pushcfunction(L, GenL_SDL_DestroyEnvironment);
    lua_setfield(L, -2, "DestroyEnvironment");
    lua_pushcfunction(L, GenL_SDL_DestroyGPUDevice);
    lua_setfield(L, -2, "DestroyGPUDevice");
    lua_pushcfunction(L, GenL_SDL_DestroyGPURenderState);
    lua_setfield(L, -2, "DestroyGPURenderState");
    lua_pushcfunction(L, GenL_SDL_DestroyHapticEffect);
    lua_setfield(L, -2, "DestroyHapticEffect");
    lua_pushcfunction(L, GenL_SDL_DestroyPalette);
    lua_setfield(L, -2, "DestroyPalette");
    lua_pushcfunction(L, GenL_SDL_DestroyProcess);
    lua_setfield(L, -2, "DestroyProcess");
    lua_pushcfunction(L, GenL_SDL_DestroyProperties);
    lua_setfield(L, -2, "DestroyProperties");
    lua_pushcfunction(L, GenL_SDL_DestroyRenderer);
    lua_setfield(L, -2, "DestroyRenderer");
    lua_pushcfunction(L, GenL_SDL_DestroySurface);
    lua_setfield(L, -2, "DestroySurface");
    lua_pushcfunction(L, GenL_SDL_DestroyTexture);
    lua_setfield(L, -2, "DestroyTexture");
    lua_pushcfunction(L, GenL_SDL_DestroyTray);
    lua_setfield(L, -2, "DestroyTray");
    lua_pushcfunction(L, GenL_SDL_DestroyWindow);
    lua_setfield(L, -2, "DestroyWindow");
    lua_pushcfunction(L, GenL_SDL_DestroyWindowSurface);
    lua_setfield(L, -2, "DestroyWindowSurface");
    lua_pushcfunction(L, GenL_SDL_DetachVirtualJoystick);
    lua_setfield(L, -2, "DetachVirtualJoystick");
    lua_pushcfunction(L, GenL_SDL_DisableScreenSaver);
    lua_setfield(L, -2, "DisableScreenSaver");
    lua_pushcfunction(L, GenL_SDL_DispatchGPUCompute);
    lua_setfield(L, -2, "DispatchGPUCompute");
    lua_pushcfunction(L, GenL_SDL_DispatchGPUComputeIndirect);
    lua_setfield(L, -2, "DispatchGPUComputeIndirect");
    lua_pushcfunction(L, GenL_SDL_DownloadFromGPUBuffer);
    lua_setfield(L, -2, "DownloadFromGPUBuffer");
    lua_pushcfunction(L, GenL_SDL_DownloadFromGPUTexture);
    lua_setfield(L, -2, "DownloadFromGPUTexture");
    lua_pushcfunction(L, GenL_SDL_DrawGPUIndexedPrimitives);
    lua_setfield(L, -2, "DrawGPUIndexedPrimitives");
    lua_pushcfunction(L, GenL_SDL_DrawGPUIndexedPrimitivesIndirect);
    lua_setfield(L, -2, "DrawGPUIndexedPrimitivesIndirect");
    lua_pushcfunction(L, GenL_SDL_DrawGPUPrimitives);
    lua_setfield(L, -2, "DrawGPUPrimitives");
    lua_pushcfunction(L, GenL_SDL_DrawGPUPrimitivesIndirect);
    lua_setfield(L, -2, "DrawGPUPrimitivesIndirect");
    lua_pushcfunction(L, GenL_SDL_DuplicateSurface);
    lua_setfield(L, -2, "DuplicateSurface");
    lua_pushcfunction(L, GenL_SDL_EnableScreenSaver);
    lua_setfield(L, -2, "EnableScreenSaver");
    lua_pushcfunction(L, GenL_SDL_EndGPUComputePass);
    lua_setfield(L, -2, "EndGPUComputePass");
    lua_pushcfunction(L, GenL_SDL_EndGPUCopyPass);
    lua_setfield(L, -2, "EndGPUCopyPass");
    lua_pushcfunction(L, GenL_SDL_EndGPURenderPass);
    lua_setfield(L, -2, "EndGPURenderPass");
    lua_pushcfunction(L, GenL_SDL_EventEnabled);
    lua_setfield(L, -2, "EventEnabled");
    lua_pushcfunction(L, GenL_SDL_FillSurfaceRect);
    lua_setfield(L, -2, "FillSurfaceRect");
    lua_pushcfunction(L, GenL_SDL_FillSurfaceRects);
    lua_setfield(L, -2, "FillSurfaceRects");
    lua_pushcfunction(L, GenL_SDL_FlashWindow);
    lua_setfield(L, -2, "FlashWindow");
    lua_pushcfunction(L, GenL_SDL_FlipSurface);
    lua_setfield(L, -2, "FlipSurface");
    lua_pushcfunction(L, GenL_SDL_FlushAudioStream);
    lua_setfield(L, -2, "FlushAudioStream");
    lua_pushcfunction(L, GenL_SDL_FlushEvent);
    lua_setfield(L, -2, "FlushEvent");
    lua_pushcfunction(L, GenL_SDL_FlushEvents);
    lua_setfield(L, -2, "FlushEvents");
    lua_pushcfunction(L, GenL_SDL_FlushIO);
    lua_setfield(L, -2, "FlushIO");
    lua_pushcfunction(L, GenL_SDL_FlushRenderer);
    lua_setfield(L, -2, "FlushRenderer");
    lua_pushcfunction(L, GenL_SDL_GL_ExtensionSupported);
    lua_setfield(L, -2, "GL_ExtensionSupported");
    lua_pushcfunction(L, GenL_SDL_GL_GetAttribute);
    lua_setfield(L, -2, "GL_GetAttribute");
    lua_pushcfunction(L, GenL_SDL_GL_GetCurrentWindow);
    lua_setfield(L, -2, "GL_GetCurrentWindow");
    lua_pushcfunction(L, GenL_SDL_GL_GetSwapInterval);
    lua_setfield(L, -2, "GL_GetSwapInterval");
    lua_pushcfunction(L, GenL_SDL_GL_LoadLibrary);
    lua_setfield(L, -2, "GL_LoadLibrary");
    lua_pushcfunction(L, GenL_SDL_GL_ResetAttributes);
    lua_setfield(L, -2, "GL_ResetAttributes");
    lua_pushcfunction(L, GenL_SDL_GL_SetAttribute);
    lua_setfield(L, -2, "GL_SetAttribute");
    lua_pushcfunction(L, GenL_SDL_GL_SetSwapInterval);
    lua_setfield(L, -2, "GL_SetSwapInterval");
    lua_pushcfunction(L, GenL_SDL_GL_SwapWindow);
    lua_setfield(L, -2, "GL_SwapWindow");
    lua_pushcfunction(L, GenL_SDL_GL_UnloadLibrary);
    lua_setfield(L, -2, "GL_UnloadLibrary");
    lua_pushcfunction(L, GenL_SDL_GPUSupportsProperties);
    lua_setfield(L, -2, "GPUSupportsProperties");
    lua_pushcfunction(L, GenL_SDL_GPUSupportsShaderFormats);
    lua_setfield(L, -2, "GPUSupportsShaderFormats");
    lua_pushcfunction(L, GenL_SDL_GPUTextureFormatTexelBlockSize);
    lua_setfield(L, -2, "GPUTextureFormatTexelBlockSize");
    lua_pushcfunction(L, GenL_SDL_GPUTextureSupportsFormat);
    lua_setfield(L, -2, "GPUTextureSupportsFormat");
    lua_pushcfunction(L, GenL_SDL_GPUTextureSupportsSampleCount);
    lua_setfield(L, -2, "GPUTextureSupportsSampleCount");
    lua_pushcfunction(L, GenL_SDL_GamepadConnected);
    lua_setfield(L, -2, "GamepadConnected");
    lua_pushcfunction(L, GenL_SDL_GamepadEventsEnabled);
    lua_setfield(L, -2, "GamepadEventsEnabled");
    lua_pushcfunction(L, GenL_SDL_GamepadHasAxis);
    lua_setfield(L, -2, "GamepadHasAxis");
    lua_pushcfunction(L, GenL_SDL_GamepadHasButton);
    lua_setfield(L, -2, "GamepadHasButton");
    lua_pushcfunction(L, GenL_SDL_GamepadHasSensor);
    lua_setfield(L, -2, "GamepadHasSensor");
    lua_pushcfunction(L, GenL_SDL_GamepadSensorEnabled);
    lua_setfield(L, -2, "GamepadSensorEnabled");
    lua_pushcfunction(L, GenL_SDL_GenerateMipmapsForGPUTexture);
    lua_setfield(L, -2, "GenerateMipmapsForGPUTexture");
    lua_pushcfunction(L, GenL_SDL_GetAppMetadataProperty);
    lua_setfield(L, -2, "GetAppMetadataProperty");
    lua_pushcfunction(L, GenL_SDL_GetAssertionReport);
    lua_setfield(L, -2, "GetAssertionReport");
    lua_pushcfunction(L, GenL_SDL_GetAsyncIOResult);
    lua_setfield(L, -2, "GetAsyncIOResult");
    lua_pushcfunction(L, GenL_SDL_GetAsyncIOSize);
    lua_setfield(L, -2, "GetAsyncIOSize");
    lua_pushcfunction(L, GenL_SDL_GetAudioDeviceFormat);
    lua_setfield(L, -2, "GetAudioDeviceFormat");
    lua_pushcfunction(L, GenL_SDL_GetAudioDeviceGain);
    lua_setfield(L, -2, "GetAudioDeviceGain");
    lua_pushcfunction(L, GenL_SDL_GetAudioDeviceName);
    lua_setfield(L, -2, "GetAudioDeviceName");
    lua_pushcfunction(L, GenL_SDL_GetAudioDriver);
    lua_setfield(L, -2, "GetAudioDriver");
    lua_pushcfunction(L, GenL_SDL_GetAudioFormatName);
    lua_setfield(L, -2, "GetAudioFormatName");
    lua_pushcfunction(L, GenL_SDL_GetAudioStreamAvailable);
    lua_setfield(L, -2, "GetAudioStreamAvailable");
    lua_pushcfunction(L, GenL_SDL_GetAudioStreamDevice);
    lua_setfield(L, -2, "GetAudioStreamDevice");
    lua_pushcfunction(L, GenL_SDL_GetAudioStreamFormat);
    lua_setfield(L, -2, "GetAudioStreamFormat");
    lua_pushcfunction(L, GenL_SDL_GetAudioStreamFrequencyRatio);
    lua_setfield(L, -2, "GetAudioStreamFrequencyRatio");
    lua_pushcfunction(L, GenL_SDL_GetAudioStreamGain);
    lua_setfield(L, -2, "GetAudioStreamGain");
    lua_pushcfunction(L, GenL_SDL_GetAudioStreamProperties);
    lua_setfield(L, -2, "GetAudioStreamProperties");
    lua_pushcfunction(L, GenL_SDL_GetAudioStreamQueued);
    lua_setfield(L, -2, "GetAudioStreamQueued");
    lua_pushcfunction(L, GenL_SDL_GetBasePath);
    lua_setfield(L, -2, "GetBasePath");
    lua_pushcfunction(L, GenL_SDL_GetBooleanProperty);
    lua_setfield(L, -2, "GetBooleanProperty");
    lua_pushcfunction(L, GenL_SDL_GetCPUCacheLineSize);
    lua_setfield(L, -2, "GetCPUCacheLineSize");
    lua_pushcfunction(L, GenL_SDL_GetCameraDriver);
    lua_setfield(L, -2, "GetCameraDriver");
    lua_pushcfunction(L, GenL_SDL_GetCameraFormat);
    lua_setfield(L, -2, "GetCameraFormat");
    lua_pushcfunction(L, GenL_SDL_GetCameraID);
    lua_setfield(L, -2, "GetCameraID");
    lua_pushcfunction(L, GenL_SDL_GetCameraName);
    lua_setfield(L, -2, "GetCameraName");
    lua_pushcfunction(L, GenL_SDL_GetCameraPermissionState);
    lua_setfield(L, -2, "GetCameraPermissionState");
    lua_pushcfunction(L, GenL_SDL_GetCameraPosition);
    lua_setfield(L, -2, "GetCameraPosition");
    lua_pushcfunction(L, GenL_SDL_GetCameraProperties);
    lua_setfield(L, -2, "GetCameraProperties");
    lua_pushcfunction(L, GenL_SDL_GetClipboardText);
    lua_setfield(L, -2, "GetClipboardText");
    lua_pushcfunction(L, GenL_SDL_GetClosestFullscreenDisplayMode);
    lua_setfield(L, -2, "GetClosestFullscreenDisplayMode");
    lua_pushcfunction(L, GenL_SDL_GetCurrentAudioDriver);
    lua_setfield(L, -2, "GetCurrentAudioDriver");
    lua_pushcfunction(L, GenL_SDL_GetCurrentCameraDriver);
    lua_setfield(L, -2, "GetCurrentCameraDriver");
    lua_pushcfunction(L, GenL_SDL_GetCurrentDirectory);
    lua_setfield(L, -2, "GetCurrentDirectory");
    lua_pushcfunction(L, GenL_SDL_GetCurrentDisplayMode);
    lua_setfield(L, -2, "GetCurrentDisplayMode");
    lua_pushcfunction(L, GenL_SDL_GetCurrentDisplayOrientation);
    lua_setfield(L, -2, "GetCurrentDisplayOrientation");
    lua_pushcfunction(L, GenL_SDL_GetCurrentRenderOutputSize);
    lua_setfield(L, -2, "GetCurrentRenderOutputSize");
    lua_pushcfunction(L, GenL_SDL_GetCurrentTime);
    lua_setfield(L, -2, "GetCurrentTime");
    lua_pushcfunction(L, GenL_SDL_GetCurrentVideoDriver);
    lua_setfield(L, -2, "GetCurrentVideoDriver");
    lua_pushcfunction(L, GenL_SDL_GetCursor);
    lua_setfield(L, -2, "GetCursor");
    lua_pushcfunction(L, GenL_SDL_GetDateTimeLocalePreferences);
    lua_setfield(L, -2, "GetDateTimeLocalePreferences");
    lua_pushcfunction(L, GenL_SDL_GetDayOfWeek);
    lua_setfield(L, -2, "GetDayOfWeek");
    lua_pushcfunction(L, GenL_SDL_GetDayOfYear);
    lua_setfield(L, -2, "GetDayOfYear");
    lua_pushcfunction(L, GenL_SDL_GetDaysInMonth);
    lua_setfield(L, -2, "GetDaysInMonth");
    lua_pushcfunction(L, GenL_SDL_GetDefaultCursor);
    lua_setfield(L, -2, "GetDefaultCursor");
    lua_pushcfunction(L, GenL_SDL_GetDefaultTextureScaleMode);
    lua_setfield(L, -2, "GetDefaultTextureScaleMode");
    lua_pushcfunction(L, GenL_SDL_GetDesktopDisplayMode);
    lua_setfield(L, -2, "GetDesktopDisplayMode");
    lua_pushcfunction(L, GenL_SDL_GetDisplayBounds);
    lua_setfield(L, -2, "GetDisplayBounds");
    lua_pushcfunction(L, GenL_SDL_GetDisplayContentScale);
    lua_setfield(L, -2, "GetDisplayContentScale");
    lua_pushcfunction(L, GenL_SDL_GetDisplayForPoint);
    lua_setfield(L, -2, "GetDisplayForPoint");
    lua_pushcfunction(L, GenL_SDL_GetDisplayForRect);
    lua_setfield(L, -2, "GetDisplayForRect");
    lua_pushcfunction(L, GenL_SDL_GetDisplayForWindow);
    lua_setfield(L, -2, "GetDisplayForWindow");
    lua_pushcfunction(L, GenL_SDL_GetDisplayName);
    lua_setfield(L, -2, "GetDisplayName");
    lua_pushcfunction(L, GenL_SDL_GetDisplayProperties);
    lua_setfield(L, -2, "GetDisplayProperties");
    lua_pushcfunction(L, GenL_SDL_GetDisplayUsableBounds);
    lua_setfield(L, -2, "GetDisplayUsableBounds");
    lua_pushcfunction(L, GenL_SDL_GetEnvironment);
    lua_setfield(L, -2, "GetEnvironment");
    lua_pushcfunction(L, GenL_SDL_GetEnvironmentVariable);
    lua_setfield(L, -2, "GetEnvironmentVariable");
    lua_pushcfunction(L, GenL_SDL_GetError);
    lua_setfield(L, -2, "GetError");
    lua_pushcfunction(L, GenL_SDL_GetFloatProperty);
    lua_setfield(L, -2, "GetFloatProperty");
    lua_pushcfunction(L, GenL_SDL_GetGPUDeviceDriver);
    lua_setfield(L, -2, "GetGPUDeviceDriver");
    lua_pushcfunction(L, GenL_SDL_GetGPUDeviceProperties);
    lua_setfield(L, -2, "GetGPUDeviceProperties");
    lua_pushcfunction(L, GenL_SDL_GetGPUDriver);
    lua_setfield(L, -2, "GetGPUDriver");
    lua_pushcfunction(L, GenL_SDL_GetGPURendererDevice);
    lua_setfield(L, -2, "GetGPURendererDevice");
    lua_pushcfunction(L, GenL_SDL_GetGPUShaderFormats);
    lua_setfield(L, -2, "GetGPUShaderFormats");
    lua_pushcfunction(L, GenL_SDL_GetGPUSwapchainTextureFormat);
    lua_setfield(L, -2, "GetGPUSwapchainTextureFormat");
    lua_pushcfunction(L, GenL_SDL_GetGPUTextureFormatFromPixelFormat);
    lua_setfield(L, -2, "GetGPUTextureFormatFromPixelFormat");
    lua_pushcfunction(L, GenL_SDL_GetGamepadAppleSFSymbolsNameForAxis);
    lua_setfield(L, -2, "GetGamepadAppleSFSymbolsNameForAxis");
    lua_pushcfunction(L, GenL_SDL_GetGamepadAppleSFSymbolsNameForButton);
    lua_setfield(L, -2, "GetGamepadAppleSFSymbolsNameForButton");
    lua_pushcfunction(L, GenL_SDL_GetGamepadAxis);
    lua_setfield(L, -2, "GetGamepadAxis");
    lua_pushcfunction(L, GenL_SDL_GetGamepadAxisFromString);
    lua_setfield(L, -2, "GetGamepadAxisFromString");
    lua_pushcfunction(L, GenL_SDL_GetGamepadButton);
    lua_setfield(L, -2, "GetGamepadButton");
    lua_pushcfunction(L, GenL_SDL_GetGamepadButtonFromString);
    lua_setfield(L, -2, "GetGamepadButtonFromString");
    lua_pushcfunction(L, GenL_SDL_GetGamepadButtonLabel);
    lua_setfield(L, -2, "GetGamepadButtonLabel");
    lua_pushcfunction(L, GenL_SDL_GetGamepadButtonLabelForType);
    lua_setfield(L, -2, "GetGamepadButtonLabelForType");
    lua_pushcfunction(L, GenL_SDL_GetGamepadConnectionState);
    lua_setfield(L, -2, "GetGamepadConnectionState");
    lua_pushcfunction(L, GenL_SDL_GetGamepadFirmwareVersion);
    lua_setfield(L, -2, "GetGamepadFirmwareVersion");
    lua_pushcfunction(L, GenL_SDL_GetGamepadFromID);
    lua_setfield(L, -2, "GetGamepadFromID");
    lua_pushcfunction(L, GenL_SDL_GetGamepadFromPlayerIndex);
    lua_setfield(L, -2, "GetGamepadFromPlayerIndex");
    lua_pushcfunction(L, GenL_SDL_GetGamepadGUIDForID);
    lua_setfield(L, -2, "GetGamepadGUIDForID");
    lua_pushcfunction(L, GenL_SDL_GetGamepadID);
    lua_setfield(L, -2, "GetGamepadID");
    lua_pushcfunction(L, GenL_SDL_GetGamepadJoystick);
    lua_setfield(L, -2, "GetGamepadJoystick");
    lua_pushcfunction(L, GenL_SDL_GetGamepadMapping);
    lua_setfield(L, -2, "GetGamepadMapping");
    lua_pushcfunction(L, GenL_SDL_GetGamepadMappingForGUID);
    lua_setfield(L, -2, "GetGamepadMappingForGUID");
    lua_pushcfunction(L, GenL_SDL_GetGamepadMappingForID);
    lua_setfield(L, -2, "GetGamepadMappingForID");
    lua_pushcfunction(L, GenL_SDL_GetGamepadName);
    lua_setfield(L, -2, "GetGamepadName");
    lua_pushcfunction(L, GenL_SDL_GetGamepadNameForID);
    lua_setfield(L, -2, "GetGamepadNameForID");
    lua_pushcfunction(L, GenL_SDL_GetGamepadPath);
    lua_setfield(L, -2, "GetGamepadPath");
    lua_pushcfunction(L, GenL_SDL_GetGamepadPathForID);
    lua_setfield(L, -2, "GetGamepadPathForID");
    lua_pushcfunction(L, GenL_SDL_GetGamepadPlayerIndex);
    lua_setfield(L, -2, "GetGamepadPlayerIndex");
    lua_pushcfunction(L, GenL_SDL_GetGamepadPlayerIndexForID);
    lua_setfield(L, -2, "GetGamepadPlayerIndexForID");
    lua_pushcfunction(L, GenL_SDL_GetGamepadPowerInfo);
    lua_setfield(L, -2, "GetGamepadPowerInfo");
    lua_pushcfunction(L, GenL_SDL_GetGamepadProduct);
    lua_setfield(L, -2, "GetGamepadProduct");
    lua_pushcfunction(L, GenL_SDL_GetGamepadProductForID);
    lua_setfield(L, -2, "GetGamepadProductForID");
    lua_pushcfunction(L, GenL_SDL_GetGamepadProductVersion);
    lua_setfield(L, -2, "GetGamepadProductVersion");
    lua_pushcfunction(L, GenL_SDL_GetGamepadProductVersionForID);
    lua_setfield(L, -2, "GetGamepadProductVersionForID");
    lua_pushcfunction(L, GenL_SDL_GetGamepadProperties);
    lua_setfield(L, -2, "GetGamepadProperties");
    lua_pushcfunction(L, GenL_SDL_GetGamepadSensorData);
    lua_setfield(L, -2, "GetGamepadSensorData");
    lua_pushcfunction(L, GenL_SDL_GetGamepadSensorDataRate);
    lua_setfield(L, -2, "GetGamepadSensorDataRate");
    lua_pushcfunction(L, GenL_SDL_GetGamepadSerial);
    lua_setfield(L, -2, "GetGamepadSerial");
    lua_pushcfunction(L, GenL_SDL_GetGamepadSteamHandle);
    lua_setfield(L, -2, "GetGamepadSteamHandle");
    lua_pushcfunction(L, GenL_SDL_GetGamepadStringForAxis);
    lua_setfield(L, -2, "GetGamepadStringForAxis");
    lua_pushcfunction(L, GenL_SDL_GetGamepadStringForButton);
    lua_setfield(L, -2, "GetGamepadStringForButton");
    lua_pushcfunction(L, GenL_SDL_GetGamepadStringForType);
    lua_setfield(L, -2, "GetGamepadStringForType");
    lua_pushcfunction(L, GenL_SDL_GetGamepadTouchpadFinger);
    lua_setfield(L, -2, "GetGamepadTouchpadFinger");
    lua_pushcfunction(L, GenL_SDL_GetGamepadType);
    lua_setfield(L, -2, "GetGamepadType");
    lua_pushcfunction(L, GenL_SDL_GetGamepadTypeForID);
    lua_setfield(L, -2, "GetGamepadTypeForID");
    lua_pushcfunction(L, GenL_SDL_GetGamepadTypeFromString);
    lua_setfield(L, -2, "GetGamepadTypeFromString");
    lua_pushcfunction(L, GenL_SDL_GetGamepadVendor);
    lua_setfield(L, -2, "GetGamepadVendor");
    lua_pushcfunction(L, GenL_SDL_GetGamepadVendorForID);
    lua_setfield(L, -2, "GetGamepadVendorForID");
    lua_pushcfunction(L, GenL_SDL_GetGlobalMouseState);
    lua_setfield(L, -2, "GetGlobalMouseState");
    lua_pushcfunction(L, GenL_SDL_GetGlobalProperties);
    lua_setfield(L, -2, "GetGlobalProperties");
    lua_pushcfunction(L, GenL_SDL_GetGrabbedWindow);
    lua_setfield(L, -2, "GetGrabbedWindow");
    lua_pushcfunction(L, GenL_SDL_GetHapticEffectStatus);
    lua_setfield(L, -2, "GetHapticEffectStatus");
    lua_pushcfunction(L, GenL_SDL_GetHapticFeatures);
    lua_setfield(L, -2, "GetHapticFeatures");
    lua_pushcfunction(L, GenL_SDL_GetHapticFromID);
    lua_setfield(L, -2, "GetHapticFromID");
    lua_pushcfunction(L, GenL_SDL_GetHapticID);
    lua_setfield(L, -2, "GetHapticID");
    lua_pushcfunction(L, GenL_SDL_GetHapticName);
    lua_setfield(L, -2, "GetHapticName");
    lua_pushcfunction(L, GenL_SDL_GetHapticNameForID);
    lua_setfield(L, -2, "GetHapticNameForID");
    lua_pushcfunction(L, GenL_SDL_GetHint);
    lua_setfield(L, -2, "GetHint");
    lua_pushcfunction(L, GenL_SDL_GetHintBoolean);
    lua_setfield(L, -2, "GetHintBoolean");
    lua_pushcfunction(L, GenL_SDL_GetIOProperties);
    lua_setfield(L, -2, "GetIOProperties");
    lua_pushcfunction(L, GenL_SDL_GetIOSize);
    lua_setfield(L, -2, "GetIOSize");
    lua_pushcfunction(L, GenL_SDL_GetIOStatus);
    lua_setfield(L, -2, "GetIOStatus");
    lua_pushcfunction(L, GenL_SDL_GetJoystickAxis);
    lua_setfield(L, -2, "GetJoystickAxis");
    lua_pushcfunction(L, GenL_SDL_GetJoystickAxisInitialState);
    lua_setfield(L, -2, "GetJoystickAxisInitialState");
    lua_pushcfunction(L, GenL_SDL_GetJoystickBall);
    lua_setfield(L, -2, "GetJoystickBall");
    lua_pushcfunction(L, GenL_SDL_GetJoystickButton);
    lua_setfield(L, -2, "GetJoystickButton");
    lua_pushcfunction(L, GenL_SDL_GetJoystickConnectionState);
    lua_setfield(L, -2, "GetJoystickConnectionState");
    lua_pushcfunction(L, GenL_SDL_GetJoystickFirmwareVersion);
    lua_setfield(L, -2, "GetJoystickFirmwareVersion");
    lua_pushcfunction(L, GenL_SDL_GetJoystickFromID);
    lua_setfield(L, -2, "GetJoystickFromID");
    lua_pushcfunction(L, GenL_SDL_GetJoystickFromPlayerIndex);
    lua_setfield(L, -2, "GetJoystickFromPlayerIndex");
    lua_pushcfunction(L, GenL_SDL_GetJoystickGUID);
    lua_setfield(L, -2, "GetJoystickGUID");
    lua_pushcfunction(L, GenL_SDL_GetJoystickGUIDForID);
    lua_setfield(L, -2, "GetJoystickGUIDForID");
    lua_pushcfunction(L, GenL_SDL_GetJoystickGUIDInfo);
    lua_setfield(L, -2, "GetJoystickGUIDInfo");
    lua_pushcfunction(L, GenL_SDL_GetJoystickHat);
    lua_setfield(L, -2, "GetJoystickHat");
    lua_pushcfunction(L, GenL_SDL_GetJoystickID);
    lua_setfield(L, -2, "GetJoystickID");
    lua_pushcfunction(L, GenL_SDL_GetJoystickName);
    lua_setfield(L, -2, "GetJoystickName");
    lua_pushcfunction(L, GenL_SDL_GetJoystickNameForID);
    lua_setfield(L, -2, "GetJoystickNameForID");
    lua_pushcfunction(L, GenL_SDL_GetJoystickPath);
    lua_setfield(L, -2, "GetJoystickPath");
    lua_pushcfunction(L, GenL_SDL_GetJoystickPathForID);
    lua_setfield(L, -2, "GetJoystickPathForID");
    lua_pushcfunction(L, GenL_SDL_GetJoystickPlayerIndex);
    lua_setfield(L, -2, "GetJoystickPlayerIndex");
    lua_pushcfunction(L, GenL_SDL_GetJoystickPlayerIndexForID);
    lua_setfield(L, -2, "GetJoystickPlayerIndexForID");
    lua_pushcfunction(L, GenL_SDL_GetJoystickPowerInfo);
    lua_setfield(L, -2, "GetJoystickPowerInfo");
    lua_pushcfunction(L, GenL_SDL_GetJoystickProduct);
    lua_setfield(L, -2, "GetJoystickProduct");
    lua_pushcfunction(L, GenL_SDL_GetJoystickProductForID);
    lua_setfield(L, -2, "GetJoystickProductForID");
    lua_pushcfunction(L, GenL_SDL_GetJoystickProductVersion);
    lua_setfield(L, -2, "GetJoystickProductVersion");
    lua_pushcfunction(L, GenL_SDL_GetJoystickProductVersionForID);
    lua_setfield(L, -2, "GetJoystickProductVersionForID");
    lua_pushcfunction(L, GenL_SDL_GetJoystickProperties);
    lua_setfield(L, -2, "GetJoystickProperties");
    lua_pushcfunction(L, GenL_SDL_GetJoystickSerial);
    lua_setfield(L, -2, "GetJoystickSerial");
    lua_pushcfunction(L, GenL_SDL_GetJoystickType);
    lua_setfield(L, -2, "GetJoystickType");
    lua_pushcfunction(L, GenL_SDL_GetJoystickTypeForID);
    lua_setfield(L, -2, "GetJoystickTypeForID");
    lua_pushcfunction(L, GenL_SDL_GetJoystickVendor);
    lua_setfield(L, -2, "GetJoystickVendor");
    lua_pushcfunction(L, GenL_SDL_GetJoystickVendorForID);
    lua_setfield(L, -2, "GetJoystickVendorForID");
    lua_pushcfunction(L, GenL_SDL_GetKeyFromName);
    lua_setfield(L, -2, "GetKeyFromName");
    lua_pushcfunction(L, GenL_SDL_GetKeyFromScancode);
    lua_setfield(L, -2, "GetKeyFromScancode");
    lua_pushcfunction(L, GenL_SDL_GetKeyName);
    lua_setfield(L, -2, "GetKeyName");
    lua_pushcfunction(L, GenL_SDL_GetKeyboardFocus);
    lua_setfield(L, -2, "GetKeyboardFocus");
    lua_pushcfunction(L, GenL_SDL_GetKeyboardNameForID);
    lua_setfield(L, -2, "GetKeyboardNameForID");
    lua_pushcfunction(L, GenL_SDL_GetLogPriority);
    lua_setfield(L, -2, "GetLogPriority");
    lua_pushcfunction(L, GenL_SDL_GetMasksForPixelFormat);
    lua_setfield(L, -2, "GetMasksForPixelFormat");
    lua_pushcfunction(L, GenL_SDL_GetMaxHapticEffects);
    lua_setfield(L, -2, "GetMaxHapticEffects");
    lua_pushcfunction(L, GenL_SDL_GetMaxHapticEffectsPlaying);
    lua_setfield(L, -2, "GetMaxHapticEffectsPlaying");
    lua_pushcfunction(L, GenL_SDL_GetModState);
    lua_setfield(L, -2, "GetModState");
    lua_pushcfunction(L, GenL_SDL_GetMouseFocus);
    lua_setfield(L, -2, "GetMouseFocus");
    lua_pushcfunction(L, GenL_SDL_GetMouseNameForID);
    lua_setfield(L, -2, "GetMouseNameForID");
    lua_pushcfunction(L, GenL_SDL_GetMouseState);
    lua_setfield(L, -2, "GetMouseState");
    lua_pushcfunction(L, GenL_SDL_GetNaturalDisplayOrientation);
    lua_setfield(L, -2, "GetNaturalDisplayOrientation");
    lua_pushcfunction(L, GenL_SDL_GetNumAllocations);
    lua_setfield(L, -2, "GetNumAllocations");
    lua_pushcfunction(L, GenL_SDL_GetNumAudioDrivers);
    lua_setfield(L, -2, "GetNumAudioDrivers");
    lua_pushcfunction(L, GenL_SDL_GetNumCameraDrivers);
    lua_setfield(L, -2, "GetNumCameraDrivers");
    lua_pushcfunction(L, GenL_SDL_GetNumGPUDrivers);
    lua_setfield(L, -2, "GetNumGPUDrivers");
    lua_pushcfunction(L, GenL_SDL_GetNumGamepadTouchpadFingers);
    lua_setfield(L, -2, "GetNumGamepadTouchpadFingers");
    lua_pushcfunction(L, GenL_SDL_GetNumGamepadTouchpads);
    lua_setfield(L, -2, "GetNumGamepadTouchpads");
    lua_pushcfunction(L, GenL_SDL_GetNumHapticAxes);
    lua_setfield(L, -2, "GetNumHapticAxes");
    lua_pushcfunction(L, GenL_SDL_GetNumJoystickAxes);
    lua_setfield(L, -2, "GetNumJoystickAxes");
    lua_pushcfunction(L, GenL_SDL_GetNumJoystickBalls);
    lua_setfield(L, -2, "GetNumJoystickBalls");
    lua_pushcfunction(L, GenL_SDL_GetNumJoystickButtons);
    lua_setfield(L, -2, "GetNumJoystickButtons");
    lua_pushcfunction(L, GenL_SDL_GetNumJoystickHats);
    lua_setfield(L, -2, "GetNumJoystickHats");
    lua_pushcfunction(L, GenL_SDL_GetNumLogicalCPUCores);
    lua_setfield(L, -2, "GetNumLogicalCPUCores");
    lua_pushcfunction(L, GenL_SDL_GetNumRenderDrivers);
    lua_setfield(L, -2, "GetNumRenderDrivers");
    lua_pushcfunction(L, GenL_SDL_GetNumVideoDrivers);
    lua_setfield(L, -2, "GetNumVideoDrivers");
    lua_pushcfunction(L, GenL_SDL_GetNumberProperty);
    lua_setfield(L, -2, "GetNumberProperty");
    lua_pushcfunction(L, GenL_SDL_GetPathInfo);
    lua_setfield(L, -2, "GetPathInfo");
    lua_pushcfunction(L, GenL_SDL_GetPenDeviceType);
    lua_setfield(L, -2, "GetPenDeviceType");
    lua_pushcfunction(L, GenL_SDL_GetPerformanceCounter);
    lua_setfield(L, -2, "GetPerformanceCounter");
    lua_pushcfunction(L, GenL_SDL_GetPerformanceFrequency);
    lua_setfield(L, -2, "GetPerformanceFrequency");
    lua_pushcfunction(L, GenL_SDL_GetPixelFormatForMasks);
    lua_setfield(L, -2, "GetPixelFormatForMasks");
    lua_pushcfunction(L, GenL_SDL_GetPixelFormatFromGPUTextureFormat);
    lua_setfield(L, -2, "GetPixelFormatFromGPUTextureFormat");
    lua_pushcfunction(L, GenL_SDL_GetPixelFormatName);
    lua_setfield(L, -2, "GetPixelFormatName");
    lua_pushcfunction(L, GenL_SDL_GetPlatform);
    lua_setfield(L, -2, "GetPlatform");
    lua_pushcfunction(L, GenL_SDL_GetPowerInfo);
    lua_setfield(L, -2, "GetPowerInfo");
    lua_pushcfunction(L, GenL_SDL_GetPrefPath);
    lua_setfield(L, -2, "GetPrefPath");
    lua_pushcfunction(L, GenL_SDL_GetPrimaryDisplay);
    lua_setfield(L, -2, "GetPrimaryDisplay");
    lua_pushcfunction(L, GenL_SDL_GetPrimarySelectionText);
    lua_setfield(L, -2, "GetPrimarySelectionText");
    lua_pushcfunction(L, GenL_SDL_GetProcessInput);
    lua_setfield(L, -2, "GetProcessInput");
    lua_pushcfunction(L, GenL_SDL_GetProcessOutput);
    lua_setfield(L, -2, "GetProcessOutput");
    lua_pushcfunction(L, GenL_SDL_GetProcessProperties);
    lua_setfield(L, -2, "GetProcessProperties");
    lua_pushcfunction(L, GenL_SDL_GetPropertyType);
    lua_setfield(L, -2, "GetPropertyType");
    lua_pushcfunction(L, GenL_SDL_GetRGB);
    lua_setfield(L, -2, "GetRGB");
    lua_pushcfunction(L, GenL_SDL_GetRGBA);
    lua_setfield(L, -2, "GetRGBA");
    lua_pushcfunction(L, GenL_SDL_GetRealGamepadType);
    lua_setfield(L, -2, "GetRealGamepadType");
    lua_pushcfunction(L, GenL_SDL_GetRealGamepadTypeForID);
    lua_setfield(L, -2, "GetRealGamepadTypeForID");
    lua_pushcfunction(L, GenL_SDL_GetRectAndLineIntersection);
    lua_setfield(L, -2, "GetRectAndLineIntersection");
    lua_pushcfunction(L, GenL_SDL_GetRectAndLineIntersectionFloat);
    lua_setfield(L, -2, "GetRectAndLineIntersectionFloat");
    lua_pushcfunction(L, GenL_SDL_GetRectEnclosingPoints);
    lua_setfield(L, -2, "GetRectEnclosingPoints");
    lua_pushcfunction(L, GenL_SDL_GetRectEnclosingPointsFloat);
    lua_setfield(L, -2, "GetRectEnclosingPointsFloat");
    lua_pushcfunction(L, GenL_SDL_GetRectIntersection);
    lua_setfield(L, -2, "GetRectIntersection");
    lua_pushcfunction(L, GenL_SDL_GetRectIntersectionFloat);
    lua_setfield(L, -2, "GetRectIntersectionFloat");
    lua_pushcfunction(L, GenL_SDL_GetRectUnion);
    lua_setfield(L, -2, "GetRectUnion");
    lua_pushcfunction(L, GenL_SDL_GetRectUnionFloat);
    lua_setfield(L, -2, "GetRectUnionFloat");
    lua_pushcfunction(L, GenL_SDL_GetRelativeMouseState);
    lua_setfield(L, -2, "GetRelativeMouseState");
    lua_pushcfunction(L, GenL_SDL_GetRenderClipRect);
    lua_setfield(L, -2, "GetRenderClipRect");
    lua_pushcfunction(L, GenL_SDL_GetRenderColorScale);
    lua_setfield(L, -2, "GetRenderColorScale");
    lua_pushcfunction(L, GenL_SDL_GetRenderDrawBlendMode);
    lua_setfield(L, -2, "GetRenderDrawBlendMode");
    lua_pushcfunction(L, GenL_SDL_GetRenderDrawColor);
    lua_setfield(L, -2, "GetRenderDrawColor");
    lua_pushcfunction(L, GenL_SDL_GetRenderDrawColorFloat);
    lua_setfield(L, -2, "GetRenderDrawColorFloat");
    lua_pushcfunction(L, GenL_SDL_GetRenderDriver);
    lua_setfield(L, -2, "GetRenderDriver");
    lua_pushcfunction(L, GenL_SDL_GetRenderLogicalPresentation);
    lua_setfield(L, -2, "GetRenderLogicalPresentation");
    lua_pushcfunction(L, GenL_SDL_GetRenderLogicalPresentationRect);
    lua_setfield(L, -2, "GetRenderLogicalPresentationRect");
    lua_pushcfunction(L, GenL_SDL_GetRenderOutputSize);
    lua_setfield(L, -2, "GetRenderOutputSize");
    lua_pushcfunction(L, GenL_SDL_GetRenderSafeArea);
    lua_setfield(L, -2, "GetRenderSafeArea");
    lua_pushcfunction(L, GenL_SDL_GetRenderScale);
    lua_setfield(L, -2, "GetRenderScale");
    lua_pushcfunction(L, GenL_SDL_GetRenderTarget);
    lua_setfield(L, -2, "GetRenderTarget");
    lua_pushcfunction(L, GenL_SDL_GetRenderTextureAddressMode);
    lua_setfield(L, -2, "GetRenderTextureAddressMode");
    lua_pushcfunction(L, GenL_SDL_GetRenderVSync);
    lua_setfield(L, -2, "GetRenderVSync");
    lua_pushcfunction(L, GenL_SDL_GetRenderViewport);
    lua_setfield(L, -2, "GetRenderViewport");
    lua_pushcfunction(L, GenL_SDL_GetRenderWindow);
    lua_setfield(L, -2, "GetRenderWindow");
    lua_pushcfunction(L, GenL_SDL_GetRenderer);
    lua_setfield(L, -2, "GetRenderer");
    lua_pushcfunction(L, GenL_SDL_GetRendererFromTexture);
    lua_setfield(L, -2, "GetRendererFromTexture");
    lua_pushcfunction(L, GenL_SDL_GetRendererName);
    lua_setfield(L, -2, "GetRendererName");
    lua_pushcfunction(L, GenL_SDL_GetRendererProperties);
    lua_setfield(L, -2, "GetRendererProperties");
    lua_pushcfunction(L, GenL_SDL_GetRevision);
    lua_setfield(L, -2, "GetRevision");
    lua_pushcfunction(L, GenL_SDL_GetSIMDAlignment);
    lua_setfield(L, -2, "GetSIMDAlignment");
    lua_pushcfunction(L, GenL_SDL_GetSandbox);
    lua_setfield(L, -2, "GetSandbox");
    lua_pushcfunction(L, GenL_SDL_GetScancodeFromKey);
    lua_setfield(L, -2, "GetScancodeFromKey");
    lua_pushcfunction(L, GenL_SDL_GetScancodeFromName);
    lua_setfield(L, -2, "GetScancodeFromName");
    lua_pushcfunction(L, GenL_SDL_GetScancodeName);
    lua_setfield(L, -2, "GetScancodeName");
    lua_pushcfunction(L, GenL_SDL_GetSensorData);
    lua_setfield(L, -2, "GetSensorData");
    lua_pushcfunction(L, GenL_SDL_GetSensorFromID);
    lua_setfield(L, -2, "GetSensorFromID");
    lua_pushcfunction(L, GenL_SDL_GetSensorID);
    lua_setfield(L, -2, "GetSensorID");
    lua_pushcfunction(L, GenL_SDL_GetSensorName);
    lua_setfield(L, -2, "GetSensorName");
    lua_pushcfunction(L, GenL_SDL_GetSensorNameForID);
    lua_setfield(L, -2, "GetSensorNameForID");
    lua_pushcfunction(L, GenL_SDL_GetSensorNonPortableType);
    lua_setfield(L, -2, "GetSensorNonPortableType");
    lua_pushcfunction(L, GenL_SDL_GetSensorNonPortableTypeForID);
    lua_setfield(L, -2, "GetSensorNonPortableTypeForID");
    lua_pushcfunction(L, GenL_SDL_GetSensorProperties);
    lua_setfield(L, -2, "GetSensorProperties");
    lua_pushcfunction(L, GenL_SDL_GetSensorType);
    lua_setfield(L, -2, "GetSensorType");
    lua_pushcfunction(L, GenL_SDL_GetSensorTypeForID);
    lua_setfield(L, -2, "GetSensorTypeForID");
    lua_pushcfunction(L, GenL_SDL_GetSilenceValueForFormat);
    lua_setfield(L, -2, "GetSilenceValueForFormat");
    lua_pushcfunction(L, GenL_SDL_GetStorageFileSize);
    lua_setfield(L, -2, "GetStorageFileSize");
    lua_pushcfunction(L, GenL_SDL_GetStoragePathInfo);
    lua_setfield(L, -2, "GetStoragePathInfo");
    lua_pushcfunction(L, GenL_SDL_GetStorageSpaceRemaining);
    lua_setfield(L, -2, "GetStorageSpaceRemaining");
    lua_pushcfunction(L, GenL_SDL_GetStringProperty);
    lua_setfield(L, -2, "GetStringProperty");
    lua_pushcfunction(L, GenL_SDL_GetSurfaceAlphaMod);
    lua_setfield(L, -2, "GetSurfaceAlphaMod");
    lua_pushcfunction(L, GenL_SDL_GetSurfaceBlendMode);
    lua_setfield(L, -2, "GetSurfaceBlendMode");
    lua_pushcfunction(L, GenL_SDL_GetSurfaceClipRect);
    lua_setfield(L, -2, "GetSurfaceClipRect");
    lua_pushcfunction(L, GenL_SDL_GetSurfaceColorKey);
    lua_setfield(L, -2, "GetSurfaceColorKey");
    lua_pushcfunction(L, GenL_SDL_GetSurfaceColorMod);
    lua_setfield(L, -2, "GetSurfaceColorMod");
    lua_pushcfunction(L, GenL_SDL_GetSurfaceColorspace);
    lua_setfield(L, -2, "GetSurfaceColorspace");
    lua_pushcfunction(L, GenL_SDL_GetSurfacePalette);
    lua_setfield(L, -2, "GetSurfacePalette");
    lua_pushcfunction(L, GenL_SDL_GetSurfaceProperties);
    lua_setfield(L, -2, "GetSurfaceProperties");
    lua_pushcfunction(L, GenL_SDL_GetSystemPageSize);
    lua_setfield(L, -2, "GetSystemPageSize");
    lua_pushcfunction(L, GenL_SDL_GetSystemRAM);
    lua_setfield(L, -2, "GetSystemRAM");
    lua_pushcfunction(L, GenL_SDL_GetSystemTheme);
    lua_setfield(L, -2, "GetSystemTheme");
    lua_pushcfunction(L, GenL_SDL_GetTextInputArea);
    lua_setfield(L, -2, "GetTextInputArea");
    lua_pushcfunction(L, GenL_SDL_GetTextureAlphaMod);
    lua_setfield(L, -2, "GetTextureAlphaMod");
    lua_pushcfunction(L, GenL_SDL_GetTextureAlphaModFloat);
    lua_setfield(L, -2, "GetTextureAlphaModFloat");
    lua_pushcfunction(L, GenL_SDL_GetTextureBlendMode);
    lua_setfield(L, -2, "GetTextureBlendMode");
    lua_pushcfunction(L, GenL_SDL_GetTextureColorMod);
    lua_setfield(L, -2, "GetTextureColorMod");
    lua_pushcfunction(L, GenL_SDL_GetTextureColorModFloat);
    lua_setfield(L, -2, "GetTextureColorModFloat");
    lua_pushcfunction(L, GenL_SDL_GetTexturePalette);
    lua_setfield(L, -2, "GetTexturePalette");
    lua_pushcfunction(L, GenL_SDL_GetTextureProperties);
    lua_setfield(L, -2, "GetTextureProperties");
    lua_pushcfunction(L, GenL_SDL_GetTextureScaleMode);
    lua_setfield(L, -2, "GetTextureScaleMode");
    lua_pushcfunction(L, GenL_SDL_GetTextureSize);
    lua_setfield(L, -2, "GetTextureSize");
    lua_pushcfunction(L, GenL_SDL_GetTicks);
    lua_setfield(L, -2, "GetTicks");
    lua_pushcfunction(L, GenL_SDL_GetTicksNS);
    lua_setfield(L, -2, "GetTicksNS");
    lua_pushcfunction(L, GenL_SDL_GetTouchDeviceName);
    lua_setfield(L, -2, "GetTouchDeviceName");
    lua_pushcfunction(L, GenL_SDL_GetTouchDeviceType);
    lua_setfield(L, -2, "GetTouchDeviceType");
    lua_pushcfunction(L, GenL_SDL_GetTrayEntryChecked);
    lua_setfield(L, -2, "GetTrayEntryChecked");
    lua_pushcfunction(L, GenL_SDL_GetTrayEntryEnabled);
    lua_setfield(L, -2, "GetTrayEntryEnabled");
    lua_pushcfunction(L, GenL_SDL_GetTrayEntryLabel);
    lua_setfield(L, -2, "GetTrayEntryLabel");
    lua_pushcfunction(L, GenL_SDL_GetTrayEntryParent);
    lua_setfield(L, -2, "GetTrayEntryParent");
    lua_pushcfunction(L, GenL_SDL_GetTrayMenu);
    lua_setfield(L, -2, "GetTrayMenu");
    lua_pushcfunction(L, GenL_SDL_GetTrayMenuParentEntry);
    lua_setfield(L, -2, "GetTrayMenuParentEntry");
    lua_pushcfunction(L, GenL_SDL_GetTrayMenuParentTray);
    lua_setfield(L, -2, "GetTrayMenuParentTray");
    lua_pushcfunction(L, GenL_SDL_GetTraySubmenu);
    lua_setfield(L, -2, "GetTraySubmenu");
    lua_pushcfunction(L, GenL_SDL_GetUserFolder);
    lua_setfield(L, -2, "GetUserFolder");
    lua_pushcfunction(L, GenL_SDL_GetVersion);
    lua_setfield(L, -2, "GetVersion");
    lua_pushcfunction(L, GenL_SDL_GetVideoDriver);
    lua_setfield(L, -2, "GetVideoDriver");
    lua_pushcfunction(L, GenL_SDL_GetWindowAspectRatio);
    lua_setfield(L, -2, "GetWindowAspectRatio");
    lua_pushcfunction(L, GenL_SDL_GetWindowBordersSize);
    lua_setfield(L, -2, "GetWindowBordersSize");
    lua_pushcfunction(L, GenL_SDL_GetWindowDisplayScale);
    lua_setfield(L, -2, "GetWindowDisplayScale");
    lua_pushcfunction(L, GenL_SDL_GetWindowFlags);
    lua_setfield(L, -2, "GetWindowFlags");
    lua_pushcfunction(L, GenL_SDL_GetWindowFromEvent);
    lua_setfield(L, -2, "GetWindowFromEvent");
    lua_pushcfunction(L, GenL_SDL_GetWindowFromID);
    lua_setfield(L, -2, "GetWindowFromID");
    lua_pushcfunction(L, GenL_SDL_GetWindowFullscreenMode);
    lua_setfield(L, -2, "GetWindowFullscreenMode");
    lua_pushcfunction(L, GenL_SDL_GetWindowID);
    lua_setfield(L, -2, "GetWindowID");
    lua_pushcfunction(L, GenL_SDL_GetWindowKeyboardGrab);
    lua_setfield(L, -2, "GetWindowKeyboardGrab");
    lua_pushcfunction(L, GenL_SDL_GetWindowMaximumSize);
    lua_setfield(L, -2, "GetWindowMaximumSize");
    lua_pushcfunction(L, GenL_SDL_GetWindowMinimumSize);
    lua_setfield(L, -2, "GetWindowMinimumSize");
    lua_pushcfunction(L, GenL_SDL_GetWindowMouseGrab);
    lua_setfield(L, -2, "GetWindowMouseGrab");
    lua_pushcfunction(L, GenL_SDL_GetWindowOpacity);
    lua_setfield(L, -2, "GetWindowOpacity");
    lua_pushcfunction(L, GenL_SDL_GetWindowParent);
    lua_setfield(L, -2, "GetWindowParent");
    lua_pushcfunction(L, GenL_SDL_GetWindowPixelDensity);
    lua_setfield(L, -2, "GetWindowPixelDensity");
    lua_pushcfunction(L, GenL_SDL_GetWindowPixelFormat);
    lua_setfield(L, -2, "GetWindowPixelFormat");
    lua_pushcfunction(L, GenL_SDL_GetWindowPosition);
    lua_setfield(L, -2, "GetWindowPosition");
    lua_pushcfunction(L, GenL_SDL_GetWindowProgressState);
    lua_setfield(L, -2, "GetWindowProgressState");
    lua_pushcfunction(L, GenL_SDL_GetWindowProgressValue);
    lua_setfield(L, -2, "GetWindowProgressValue");
    lua_pushcfunction(L, GenL_SDL_GetWindowProperties);
    lua_setfield(L, -2, "GetWindowProperties");
    lua_pushcfunction(L, GenL_SDL_GetWindowRelativeMouseMode);
    lua_setfield(L, -2, "GetWindowRelativeMouseMode");
    lua_pushcfunction(L, GenL_SDL_GetWindowSafeArea);
    lua_setfield(L, -2, "GetWindowSafeArea");
    lua_pushcfunction(L, GenL_SDL_GetWindowSize);
    lua_setfield(L, -2, "GetWindowSize");
    lua_pushcfunction(L, GenL_SDL_GetWindowSizeInPixels);
    lua_setfield(L, -2, "GetWindowSizeInPixels");
    lua_pushcfunction(L, GenL_SDL_GetWindowSurface);
    lua_setfield(L, -2, "GetWindowSurface");
    lua_pushcfunction(L, GenL_SDL_GetWindowSurfaceVSync);
    lua_setfield(L, -2, "GetWindowSurfaceVSync");
    lua_pushcfunction(L, GenL_SDL_GetWindowTitle);
    lua_setfield(L, -2, "GetWindowTitle");
    lua_pushcfunction(L, GenL_SDL_HapticEffectSupported);
    lua_setfield(L, -2, "HapticEffectSupported");
    lua_pushcfunction(L, GenL_SDL_HapticRumbleSupported);
    lua_setfield(L, -2, "HapticRumbleSupported");
    lua_pushcfunction(L, GenL_SDL_HasARMSIMD);
    lua_setfield(L, -2, "HasARMSIMD");
    lua_pushcfunction(L, GenL_SDL_HasAVX);
    lua_setfield(L, -2, "HasAVX");
    lua_pushcfunction(L, GenL_SDL_HasAVX2);
    lua_setfield(L, -2, "HasAVX2");
    lua_pushcfunction(L, GenL_SDL_HasAVX512F);
    lua_setfield(L, -2, "HasAVX512F");
    lua_pushcfunction(L, GenL_SDL_HasAltiVec);
    lua_setfield(L, -2, "HasAltiVec");
    lua_pushcfunction(L, GenL_SDL_HasClipboardData);
    lua_setfield(L, -2, "HasClipboardData");
    lua_pushcfunction(L, GenL_SDL_HasClipboardText);
    lua_setfield(L, -2, "HasClipboardText");
    lua_pushcfunction(L, GenL_SDL_HasEvent);
    lua_setfield(L, -2, "HasEvent");
    lua_pushcfunction(L, GenL_SDL_HasEvents);
    lua_setfield(L, -2, "HasEvents");
    lua_pushcfunction(L, GenL_SDL_HasGamepad);
    lua_setfield(L, -2, "HasGamepad");
    lua_pushcfunction(L, GenL_SDL_HasJoystick);
    lua_setfield(L, -2, "HasJoystick");
    lua_pushcfunction(L, GenL_SDL_HasKeyboard);
    lua_setfield(L, -2, "HasKeyboard");
    lua_pushcfunction(L, GenL_SDL_HasLASX);
    lua_setfield(L, -2, "HasLASX");
    lua_pushcfunction(L, GenL_SDL_HasLSX);
    lua_setfield(L, -2, "HasLSX");
    lua_pushcfunction(L, GenL_SDL_HasMMX);
    lua_setfield(L, -2, "HasMMX");
    lua_pushcfunction(L, GenL_SDL_HasMouse);
    lua_setfield(L, -2, "HasMouse");
    lua_pushcfunction(L, GenL_SDL_HasNEON);
    lua_setfield(L, -2, "HasNEON");
    lua_pushcfunction(L, GenL_SDL_HasPrimarySelectionText);
    lua_setfield(L, -2, "HasPrimarySelectionText");
    lua_pushcfunction(L, GenL_SDL_HasProperty);
    lua_setfield(L, -2, "HasProperty");
    lua_pushcfunction(L, GenL_SDL_HasRectIntersection);
    lua_setfield(L, -2, "HasRectIntersection");
    lua_pushcfunction(L, GenL_SDL_HasRectIntersectionFloat);
    lua_setfield(L, -2, "HasRectIntersectionFloat");
    lua_pushcfunction(L, GenL_SDL_HasSSE);
    lua_setfield(L, -2, "HasSSE");
    lua_pushcfunction(L, GenL_SDL_HasSSE2);
    lua_setfield(L, -2, "HasSSE2");
    lua_pushcfunction(L, GenL_SDL_HasSSE3);
    lua_setfield(L, -2, "HasSSE3");
    lua_pushcfunction(L, GenL_SDL_HasSSE41);
    lua_setfield(L, -2, "HasSSE41");
    lua_pushcfunction(L, GenL_SDL_HasSSE42);
    lua_setfield(L, -2, "HasSSE42");
    lua_pushcfunction(L, GenL_SDL_HasScreenKeyboardSupport);
    lua_setfield(L, -2, "HasScreenKeyboardSupport");
    lua_pushcfunction(L, GenL_SDL_HideCursor);
    lua_setfield(L, -2, "HideCursor");
    lua_pushcfunction(L, GenL_SDL_HideWindow);
    lua_setfield(L, -2, "HideWindow");
    lua_pushcfunction(L, GenL_SDL_IOFromConstMem);
    lua_setfield(L, -2, "IOFromConstMem");
    lua_pushcfunction(L, GenL_SDL_IOFromDynamicMem);
    lua_setfield(L, -2, "IOFromDynamicMem");
    lua_pushcfunction(L, GenL_SDL_IOFromFile);
    lua_setfield(L, -2, "IOFromFile");
    lua_pushcfunction(L, GenL_SDL_Init);
    lua_setfield(L, -2, "Init");
    lua_pushcfunction(L, GenL_SDL_InitHapticRumble);
    lua_setfield(L, -2, "InitHapticRumble");
    lua_pushcfunction(L, GenL_SDL_InitSubSystem);
    lua_setfield(L, -2, "InitSubSystem");
    lua_pushcfunction(L, GenL_SDL_InsertGPUDebugLabel);
    lua_setfield(L, -2, "InsertGPUDebugLabel");
    lua_pushcfunction(L, GenL_SDL_InsertTrayEntryAt);
    lua_setfield(L, -2, "InsertTrayEntryAt");
    lua_pushcfunction(L, GenL_SDL_IsAudioDevicePhysical);
    lua_setfield(L, -2, "IsAudioDevicePhysical");
    lua_pushcfunction(L, GenL_SDL_IsAudioDevicePlayback);
    lua_setfield(L, -2, "IsAudioDevicePlayback");
    lua_pushcfunction(L, GenL_SDL_IsGamepad);
    lua_setfield(L, -2, "IsGamepad");
    lua_pushcfunction(L, GenL_SDL_IsJoystickHaptic);
    lua_setfield(L, -2, "IsJoystickHaptic");
    lua_pushcfunction(L, GenL_SDL_IsJoystickVirtual);
    lua_setfield(L, -2, "IsJoystickVirtual");
    lua_pushcfunction(L, GenL_SDL_IsMainThread);
    lua_setfield(L, -2, "IsMainThread");
    lua_pushcfunction(L, GenL_SDL_IsMouseHaptic);
    lua_setfield(L, -2, "IsMouseHaptic");
    lua_pushcfunction(L, GenL_SDL_IsTV);
    lua_setfield(L, -2, "IsTV");
    lua_pushcfunction(L, GenL_SDL_IsTablet);
    lua_setfield(L, -2, "IsTablet");
    lua_pushcfunction(L, GenL_SDL_JoystickConnected);
    lua_setfield(L, -2, "JoystickConnected");
    lua_pushcfunction(L, GenL_SDL_JoystickEventsEnabled);
    lua_setfield(L, -2, "JoystickEventsEnabled");
    lua_pushcfunction(L, GenL_SDL_KillProcess);
    lua_setfield(L, -2, "KillProcess");
    lua_pushcfunction(L, GenL_SDL_LoadBMP);
    lua_setfield(L, -2, "LoadBMP");
    lua_pushcfunction(L, GenL_SDL_LoadBMP_IO);
    lua_setfield(L, -2, "LoadBMP_IO");
    lua_pushcfunction(L, GenL_SDL_LoadObject);
    lua_setfield(L, -2, "LoadObject");
    lua_pushcfunction(L, GenL_SDL_LoadPNG);
    lua_setfield(L, -2, "LoadPNG");
    lua_pushcfunction(L, GenL_SDL_LoadPNG_IO);
    lua_setfield(L, -2, "LoadPNG_IO");
    lua_pushcfunction(L, GenL_SDL_LoadSurface);
    lua_setfield(L, -2, "LoadSurface");
    lua_pushcfunction(L, GenL_SDL_LoadSurface_IO);
    lua_setfield(L, -2, "LoadSurface_IO");
    lua_pushcfunction(L, GenL_SDL_LockAudioStream);
    lua_setfield(L, -2, "LockAudioStream");
    lua_pushcfunction(L, GenL_SDL_LockProperties);
    lua_setfield(L, -2, "LockProperties");
    lua_pushcfunction(L, GenL_SDL_LockSpinlock);
    lua_setfield(L, -2, "LockSpinlock");
    lua_pushcfunction(L, GenL_SDL_LockSurface);
    lua_setfield(L, -2, "LockSurface");
    lua_pushcfunction(L, GenL_SDL_MapRGB);
    lua_setfield(L, -2, "MapRGB");
    lua_pushcfunction(L, GenL_SDL_MapRGBA);
    lua_setfield(L, -2, "MapRGBA");
    lua_pushcfunction(L, GenL_SDL_MapSurfaceRGB);
    lua_setfield(L, -2, "MapSurfaceRGB");
    lua_pushcfunction(L, GenL_SDL_MapSurfaceRGBA);
    lua_setfield(L, -2, "MapSurfaceRGBA");
    lua_pushcfunction(L, GenL_SDL_MaximizeWindow);
    lua_setfield(L, -2, "MaximizeWindow");
    lua_pushcfunction(L, GenL_SDL_MinimizeWindow);
    lua_setfield(L, -2, "MinimizeWindow");
    lua_pushcfunction(L, GenL_SDL_OnApplicationDidEnterBackground);
    lua_setfield(L, -2, "OnApplicationDidEnterBackground");
    lua_pushcfunction(L, GenL_SDL_OnApplicationDidEnterForeground);
    lua_setfield(L, -2, "OnApplicationDidEnterForeground");
    lua_pushcfunction(L, GenL_SDL_OnApplicationDidReceiveMemoryWarning);
    lua_setfield(L, -2, "OnApplicationDidReceiveMemoryWarning");
    lua_pushcfunction(L, GenL_SDL_OnApplicationWillEnterBackground);
    lua_setfield(L, -2, "OnApplicationWillEnterBackground");
    lua_pushcfunction(L, GenL_SDL_OnApplicationWillEnterForeground);
    lua_setfield(L, -2, "OnApplicationWillEnterForeground");
    lua_pushcfunction(L, GenL_SDL_OnApplicationWillTerminate);
    lua_setfield(L, -2, "OnApplicationWillTerminate");
    lua_pushcfunction(L, GenL_SDL_OpenAudioDevice);
    lua_setfield(L, -2, "OpenAudioDevice");
    lua_pushcfunction(L, GenL_SDL_OpenCamera);
    lua_setfield(L, -2, "OpenCamera");
    lua_pushcfunction(L, GenL_SDL_OpenFileStorage);
    lua_setfield(L, -2, "OpenFileStorage");
    lua_pushcfunction(L, GenL_SDL_OpenGamepad);
    lua_setfield(L, -2, "OpenGamepad");
    lua_pushcfunction(L, GenL_SDL_OpenHaptic);
    lua_setfield(L, -2, "OpenHaptic");
    lua_pushcfunction(L, GenL_SDL_OpenHapticFromJoystick);
    lua_setfield(L, -2, "OpenHapticFromJoystick");
    lua_pushcfunction(L, GenL_SDL_OpenHapticFromMouse);
    lua_setfield(L, -2, "OpenHapticFromMouse");
    lua_pushcfunction(L, GenL_SDL_OpenJoystick);
    lua_setfield(L, -2, "OpenJoystick");
    lua_pushcfunction(L, GenL_SDL_OpenSensor);
    lua_setfield(L, -2, "OpenSensor");
    lua_pushcfunction(L, GenL_SDL_OpenTitleStorage);
    lua_setfield(L, -2, "OpenTitleStorage");
    lua_pushcfunction(L, GenL_SDL_OpenURL);
    lua_setfield(L, -2, "OpenURL");
    lua_pushcfunction(L, GenL_SDL_OpenUserStorage);
    lua_setfield(L, -2, "OpenUserStorage");
    lua_pushcfunction(L, GenL_SDL_OutOfMemory);
    lua_setfield(L, -2, "OutOfMemory");
    lua_pushcfunction(L, GenL_SDL_PauseAudioDevice);
    lua_setfield(L, -2, "PauseAudioDevice");
    lua_pushcfunction(L, GenL_SDL_PauseAudioStreamDevice);
    lua_setfield(L, -2, "PauseAudioStreamDevice");
    lua_pushcfunction(L, GenL_SDL_PauseHaptic);
    lua_setfield(L, -2, "PauseHaptic");
    lua_pushcfunction(L, GenL_SDL_PeepEvents);
    lua_setfield(L, -2, "PeepEvents");
    lua_pushcfunction(L, GenL_SDL_PlayHapticRumble);
    lua_setfield(L, -2, "PlayHapticRumble");
    lua_pushcfunction(L, GenL_SDL_PollEvent);
    lua_setfield(L, -2, "PollEvent");
    lua_pushcfunction(L, GenL_SDL_PopGPUDebugGroup);
    lua_setfield(L, -2, "PopGPUDebugGroup");
    lua_pushcfunction(L, GenL_SDL_PremultiplySurfaceAlpha);
    lua_setfield(L, -2, "PremultiplySurfaceAlpha");
    lua_pushcfunction(L, GenL_SDL_PumpEvents);
    lua_setfield(L, -2, "PumpEvents");
    lua_pushcfunction(L, GenL_SDL_PushEvent);
    lua_setfield(L, -2, "PushEvent");
    lua_pushcfunction(L, GenL_SDL_PushGPUComputeUniformData);
    lua_setfield(L, -2, "PushGPUComputeUniformData");
    lua_pushcfunction(L, GenL_SDL_PushGPUDebugGroup);
    lua_setfield(L, -2, "PushGPUDebugGroup");
    lua_pushcfunction(L, GenL_SDL_PushGPUFragmentUniformData);
    lua_setfield(L, -2, "PushGPUFragmentUniformData");
    lua_pushcfunction(L, GenL_SDL_PushGPUVertexUniformData);
    lua_setfield(L, -2, "PushGPUVertexUniformData");
    lua_pushcfunction(L, GenL_SDL_PutAudioStreamData);
    lua_setfield(L, -2, "PutAudioStreamData");
    lua_pushcfunction(L, GenL_SDL_QueryGPUFence);
    lua_setfield(L, -2, "QueryGPUFence");
    lua_pushcfunction(L, GenL_SDL_Quit);
    lua_setfield(L, -2, "Quit");
    lua_pushcfunction(L, GenL_SDL_QuitSubSystem);
    lua_setfield(L, -2, "QuitSubSystem");
    lua_pushcfunction(L, GenL_SDL_RaiseWindow);
    lua_setfield(L, -2, "RaiseWindow");
    lua_pushcfunction(L, GenL_SDL_ReadS16BE);
    lua_setfield(L, -2, "ReadS16BE");
    lua_pushcfunction(L, GenL_SDL_ReadS16LE);
    lua_setfield(L, -2, "ReadS16LE");
    lua_pushcfunction(L, GenL_SDL_ReadS32BE);
    lua_setfield(L, -2, "ReadS32BE");
    lua_pushcfunction(L, GenL_SDL_ReadS32LE);
    lua_setfield(L, -2, "ReadS32LE");
    lua_pushcfunction(L, GenL_SDL_ReadS64BE);
    lua_setfield(L, -2, "ReadS64BE");
    lua_pushcfunction(L, GenL_SDL_ReadS64LE);
    lua_setfield(L, -2, "ReadS64LE");
    lua_pushcfunction(L, GenL_SDL_ReadS8);
    lua_setfield(L, -2, "ReadS8");
    lua_pushcfunction(L, GenL_SDL_ReadSurfacePixel);
    lua_setfield(L, -2, "ReadSurfacePixel");
    lua_pushcfunction(L, GenL_SDL_ReadSurfacePixelFloat);
    lua_setfield(L, -2, "ReadSurfacePixelFloat");
    lua_pushcfunction(L, GenL_SDL_ReadU16BE);
    lua_setfield(L, -2, "ReadU16BE");
    lua_pushcfunction(L, GenL_SDL_ReadU16LE);
    lua_setfield(L, -2, "ReadU16LE");
    lua_pushcfunction(L, GenL_SDL_ReadU32BE);
    lua_setfield(L, -2, "ReadU32BE");
    lua_pushcfunction(L, GenL_SDL_ReadU32LE);
    lua_setfield(L, -2, "ReadU32LE");
    lua_pushcfunction(L, GenL_SDL_ReadU64BE);
    lua_setfield(L, -2, "ReadU64BE");
    lua_pushcfunction(L, GenL_SDL_ReadU64LE);
    lua_setfield(L, -2, "ReadU64LE");
    lua_pushcfunction(L, GenL_SDL_ReadU8);
    lua_setfield(L, -2, "ReadU8");
    lua_pushcfunction(L, GenL_SDL_RegisterEvents);
    lua_setfield(L, -2, "RegisterEvents");
    lua_pushcfunction(L, GenL_SDL_ReleaseCameraFrame);
    lua_setfield(L, -2, "ReleaseCameraFrame");
    lua_pushcfunction(L, GenL_SDL_ReleaseGPUBuffer);
    lua_setfield(L, -2, "ReleaseGPUBuffer");
    lua_pushcfunction(L, GenL_SDL_ReleaseGPUComputePipeline);
    lua_setfield(L, -2, "ReleaseGPUComputePipeline");
    lua_pushcfunction(L, GenL_SDL_ReleaseGPUFence);
    lua_setfield(L, -2, "ReleaseGPUFence");
    lua_pushcfunction(L, GenL_SDL_ReleaseGPUGraphicsPipeline);
    lua_setfield(L, -2, "ReleaseGPUGraphicsPipeline");
    lua_pushcfunction(L, GenL_SDL_ReleaseGPUSampler);
    lua_setfield(L, -2, "ReleaseGPUSampler");
    lua_pushcfunction(L, GenL_SDL_ReleaseGPUShader);
    lua_setfield(L, -2, "ReleaseGPUShader");
    lua_pushcfunction(L, GenL_SDL_ReleaseGPUTexture);
    lua_setfield(L, -2, "ReleaseGPUTexture");
    lua_pushcfunction(L, GenL_SDL_ReleaseGPUTransferBuffer);
    lua_setfield(L, -2, "ReleaseGPUTransferBuffer");
    lua_pushcfunction(L, GenL_SDL_ReleaseWindowFromGPUDevice);
    lua_setfield(L, -2, "ReleaseWindowFromGPUDevice");
    lua_pushcfunction(L, GenL_SDL_ReloadGamepadMappings);
    lua_setfield(L, -2, "ReloadGamepadMappings");
    lua_pushcfunction(L, GenL_SDL_RemovePath);
    lua_setfield(L, -2, "RemovePath");
    lua_pushcfunction(L, GenL_SDL_RemoveStoragePath);
    lua_setfield(L, -2, "RemoveStoragePath");
    lua_pushcfunction(L, GenL_SDL_RemoveSurfaceAlternateImages);
    lua_setfield(L, -2, "RemoveSurfaceAlternateImages");
    lua_pushcfunction(L, GenL_SDL_RemoveTimer);
    lua_setfield(L, -2, "RemoveTimer");
    lua_pushcfunction(L, GenL_SDL_RemoveTrayEntry);
    lua_setfield(L, -2, "RemoveTrayEntry");
    lua_pushcfunction(L, GenL_SDL_RenamePath);
    lua_setfield(L, -2, "RenamePath");
    lua_pushcfunction(L, GenL_SDL_RenameStoragePath);
    lua_setfield(L, -2, "RenameStoragePath");
    lua_pushcfunction(L, GenL_SDL_RenderClear);
    lua_setfield(L, -2, "RenderClear");
    lua_pushcfunction(L, GenL_SDL_RenderClipEnabled);
    lua_setfield(L, -2, "RenderClipEnabled");
    lua_pushcfunction(L, GenL_SDL_RenderCoordinatesFromWindow);
    lua_setfield(L, -2, "RenderCoordinatesFromWindow");
    lua_pushcfunction(L, GenL_SDL_RenderCoordinatesToWindow);
    lua_setfield(L, -2, "RenderCoordinatesToWindow");
    lua_pushcfunction(L, GenL_SDL_RenderDebugText);
    lua_setfield(L, -2, "RenderDebugText");
    lua_pushcfunction(L, GenL_SDL_RenderFillRect);
    lua_setfield(L, -2, "RenderFillRect");
    lua_pushcfunction(L, GenL_SDL_RenderFillRects);
    lua_setfield(L, -2, "RenderFillRects");
    lua_pushcfunction(L, GenL_SDL_RenderLine);
    lua_setfield(L, -2, "RenderLine");
    lua_pushcfunction(L, GenL_SDL_RenderLines);
    lua_setfield(L, -2, "RenderLines");
    lua_pushcfunction(L, GenL_SDL_RenderPoint);
    lua_setfield(L, -2, "RenderPoint");
    lua_pushcfunction(L, GenL_SDL_RenderPoints);
    lua_setfield(L, -2, "RenderPoints");
    lua_pushcfunction(L, GenL_SDL_RenderPresent);
    lua_setfield(L, -2, "RenderPresent");
    lua_pushcfunction(L, GenL_SDL_RenderReadPixels);
    lua_setfield(L, -2, "RenderReadPixels");
    lua_pushcfunction(L, GenL_SDL_RenderRect);
    lua_setfield(L, -2, "RenderRect");
    lua_pushcfunction(L, GenL_SDL_RenderRects);
    lua_setfield(L, -2, "RenderRects");
    lua_pushcfunction(L, GenL_SDL_RenderTexture);
    lua_setfield(L, -2, "RenderTexture");
    lua_pushcfunction(L, GenL_SDL_RenderTexture9Grid);
    lua_setfield(L, -2, "RenderTexture9Grid");
    lua_pushcfunction(L, GenL_SDL_RenderTexture9GridTiled);
    lua_setfield(L, -2, "RenderTexture9GridTiled");
    lua_pushcfunction(L, GenL_SDL_RenderTextureAffine);
    lua_setfield(L, -2, "RenderTextureAffine");
    lua_pushcfunction(L, GenL_SDL_RenderTextureRotated);
    lua_setfield(L, -2, "RenderTextureRotated");
    lua_pushcfunction(L, GenL_SDL_RenderTextureTiled);
    lua_setfield(L, -2, "RenderTextureTiled");
    lua_pushcfunction(L, GenL_SDL_RenderViewportSet);
    lua_setfield(L, -2, "RenderViewportSet");
    lua_pushcfunction(L, GenL_SDL_ResetAssertionReport);
    lua_setfield(L, -2, "ResetAssertionReport");
    lua_pushcfunction(L, GenL_SDL_ResetHint);
    lua_setfield(L, -2, "ResetHint");
    lua_pushcfunction(L, GenL_SDL_ResetHints);
    lua_setfield(L, -2, "ResetHints");
    lua_pushcfunction(L, GenL_SDL_ResetKeyboard);
    lua_setfield(L, -2, "ResetKeyboard");
    lua_pushcfunction(L, GenL_SDL_ResetLogPriorities);
    lua_setfield(L, -2, "ResetLogPriorities");
    lua_pushcfunction(L, GenL_SDL_RestoreWindow);
    lua_setfield(L, -2, "RestoreWindow");
    lua_pushcfunction(L, GenL_SDL_ResumeAudioDevice);
    lua_setfield(L, -2, "ResumeAudioDevice");
    lua_pushcfunction(L, GenL_SDL_ResumeAudioStreamDevice);
    lua_setfield(L, -2, "ResumeAudioStreamDevice");
    lua_pushcfunction(L, GenL_SDL_ResumeHaptic);
    lua_setfield(L, -2, "ResumeHaptic");
    lua_pushcfunction(L, GenL_SDL_RotateSurface);
    lua_setfield(L, -2, "RotateSurface");
    lua_pushcfunction(L, GenL_SDL_RumbleGamepad);
    lua_setfield(L, -2, "RumbleGamepad");
    lua_pushcfunction(L, GenL_SDL_RumbleGamepadTriggers);
    lua_setfield(L, -2, "RumbleGamepadTriggers");
    lua_pushcfunction(L, GenL_SDL_RumbleJoystick);
    lua_setfield(L, -2, "RumbleJoystick");
    lua_pushcfunction(L, GenL_SDL_RumbleJoystickTriggers);
    lua_setfield(L, -2, "RumbleJoystickTriggers");
    lua_pushcfunction(L, GenL_SDL_RunHapticEffect);
    lua_setfield(L, -2, "RunHapticEffect");
    lua_pushcfunction(L, GenL_SDL_SaveBMP);
    lua_setfield(L, -2, "SaveBMP");
    lua_pushcfunction(L, GenL_SDL_SaveBMP_IO);
    lua_setfield(L, -2, "SaveBMP_IO");
    lua_pushcfunction(L, GenL_SDL_SaveFile);
    lua_setfield(L, -2, "SaveFile");
    lua_pushcfunction(L, GenL_SDL_SaveFile_IO);
    lua_setfield(L, -2, "SaveFile_IO");
    lua_pushcfunction(L, GenL_SDL_SavePNG);
    lua_setfield(L, -2, "SavePNG");
    lua_pushcfunction(L, GenL_SDL_SavePNG_IO);
    lua_setfield(L, -2, "SavePNG_IO");
    lua_pushcfunction(L, GenL_SDL_ScaleSurface);
    lua_setfield(L, -2, "ScaleSurface");
    lua_pushcfunction(L, GenL_SDL_ScreenKeyboardShown);
    lua_setfield(L, -2, "ScreenKeyboardShown");
    lua_pushcfunction(L, GenL_SDL_ScreenSaverEnabled);
    lua_setfield(L, -2, "ScreenSaverEnabled");
    lua_pushcfunction(L, GenL_SDL_SeekIO);
    lua_setfield(L, -2, "SeekIO");
    lua_pushcfunction(L, GenL_SDL_SendGamepadEffect);
    lua_setfield(L, -2, "SendGamepadEffect");
    lua_pushcfunction(L, GenL_SDL_SendJoystickEffect);
    lua_setfield(L, -2, "SendJoystickEffect");
    lua_pushcfunction(L, GenL_SDL_SetAppMetadata);
    lua_setfield(L, -2, "SetAppMetadata");
    lua_pushcfunction(L, GenL_SDL_SetAppMetadataProperty);
    lua_setfield(L, -2, "SetAppMetadataProperty");
    lua_pushcfunction(L, GenL_SDL_SetAudioDeviceGain);
    lua_setfield(L, -2, "SetAudioDeviceGain");
    lua_pushcfunction(L, GenL_SDL_SetAudioStreamFormat);
    lua_setfield(L, -2, "SetAudioStreamFormat");
    lua_pushcfunction(L, GenL_SDL_SetAudioStreamFrequencyRatio);
    lua_setfield(L, -2, "SetAudioStreamFrequencyRatio");
    lua_pushcfunction(L, GenL_SDL_SetAudioStreamGain);
    lua_setfield(L, -2, "SetAudioStreamGain");
    lua_pushcfunction(L, GenL_SDL_SetBooleanProperty);
    lua_setfield(L, -2, "SetBooleanProperty");
    lua_pushcfunction(L, GenL_SDL_SetClipboardText);
    lua_setfield(L, -2, "SetClipboardText");
    lua_pushcfunction(L, GenL_SDL_SetCursor);
    lua_setfield(L, -2, "SetCursor");
    lua_pushcfunction(L, GenL_SDL_SetDefaultTextureScaleMode);
    lua_setfield(L, -2, "SetDefaultTextureScaleMode");
    lua_pushcfunction(L, GenL_SDL_SetEnvironmentVariable);
    lua_setfield(L, -2, "SetEnvironmentVariable");
    lua_pushcfunction(L, GenL_SDL_SetEventEnabled);
    lua_setfield(L, -2, "SetEventEnabled");
    lua_pushcfunction(L, GenL_SDL_SetFloatProperty);
    lua_setfield(L, -2, "SetFloatProperty");
    lua_pushcfunction(L, GenL_SDL_SetGPUAllowedFramesInFlight);
    lua_setfield(L, -2, "SetGPUAllowedFramesInFlight");
    lua_pushcfunction(L, GenL_SDL_SetGPUBlendConstants);
    lua_setfield(L, -2, "SetGPUBlendConstants");
    lua_pushcfunction(L, GenL_SDL_SetGPUBufferName);
    lua_setfield(L, -2, "SetGPUBufferName");
    lua_pushcfunction(L, GenL_SDL_SetGPURenderState);
    lua_setfield(L, -2, "SetGPURenderState");
    lua_pushcfunction(L, GenL_SDL_SetGPURenderStateFragmentUniforms);
    lua_setfield(L, -2, "SetGPURenderStateFragmentUniforms");
    lua_pushcfunction(L, GenL_SDL_SetGPUScissor);
    lua_setfield(L, -2, "SetGPUScissor");
    lua_pushcfunction(L, GenL_SDL_SetGPUStencilReference);
    lua_setfield(L, -2, "SetGPUStencilReference");
    lua_pushcfunction(L, GenL_SDL_SetGPUSwapchainParameters);
    lua_setfield(L, -2, "SetGPUSwapchainParameters");
    lua_pushcfunction(L, GenL_SDL_SetGPUTextureName);
    lua_setfield(L, -2, "SetGPUTextureName");
    lua_pushcfunction(L, GenL_SDL_SetGPUViewport);
    lua_setfield(L, -2, "SetGPUViewport");
    lua_pushcfunction(L, GenL_SDL_SetGamepadEventsEnabled);
    lua_setfield(L, -2, "SetGamepadEventsEnabled");
    lua_pushcfunction(L, GenL_SDL_SetGamepadLED);
    lua_setfield(L, -2, "SetGamepadLED");
    lua_pushcfunction(L, GenL_SDL_SetGamepadMapping);
    lua_setfield(L, -2, "SetGamepadMapping");
    lua_pushcfunction(L, GenL_SDL_SetGamepadPlayerIndex);
    lua_setfield(L, -2, "SetGamepadPlayerIndex");
    lua_pushcfunction(L, GenL_SDL_SetGamepadSensorEnabled);
    lua_setfield(L, -2, "SetGamepadSensorEnabled");
    lua_pushcfunction(L, GenL_SDL_SetHapticAutocenter);
    lua_setfield(L, -2, "SetHapticAutocenter");
    lua_pushcfunction(L, GenL_SDL_SetHapticGain);
    lua_setfield(L, -2, "SetHapticGain");
    lua_pushcfunction(L, GenL_SDL_SetHint);
    lua_setfield(L, -2, "SetHint");
    lua_pushcfunction(L, GenL_SDL_SetHintWithPriority);
    lua_setfield(L, -2, "SetHintWithPriority");
    lua_pushcfunction(L, GenL_SDL_SetInitialized);
    lua_setfield(L, -2, "SetInitialized");
    lua_pushcfunction(L, GenL_SDL_SetJoystickEventsEnabled);
    lua_setfield(L, -2, "SetJoystickEventsEnabled");
    lua_pushcfunction(L, GenL_SDL_SetJoystickLED);
    lua_setfield(L, -2, "SetJoystickLED");
    lua_pushcfunction(L, GenL_SDL_SetJoystickPlayerIndex);
    lua_setfield(L, -2, "SetJoystickPlayerIndex");
    lua_pushcfunction(L, GenL_SDL_SetJoystickVirtualAxis);
    lua_setfield(L, -2, "SetJoystickVirtualAxis");
    lua_pushcfunction(L, GenL_SDL_SetJoystickVirtualBall);
    lua_setfield(L, -2, "SetJoystickVirtualBall");
    lua_pushcfunction(L, GenL_SDL_SetJoystickVirtualButton);
    lua_setfield(L, -2, "SetJoystickVirtualButton");
    lua_pushcfunction(L, GenL_SDL_SetJoystickVirtualHat);
    lua_setfield(L, -2, "SetJoystickVirtualHat");
    lua_pushcfunction(L, GenL_SDL_SetJoystickVirtualTouchpad);
    lua_setfield(L, -2, "SetJoystickVirtualTouchpad");
    lua_pushcfunction(L, GenL_SDL_SetLogPriorities);
    lua_setfield(L, -2, "SetLogPriorities");
    lua_pushcfunction(L, GenL_SDL_SetLogPriority);
    lua_setfield(L, -2, "SetLogPriority");
    lua_pushcfunction(L, GenL_SDL_SetLogPriorityPrefix);
    lua_setfield(L, -2, "SetLogPriorityPrefix");
    lua_pushcfunction(L, GenL_SDL_SetModState);
    lua_setfield(L, -2, "SetModState");
    lua_pushcfunction(L, GenL_SDL_SetNumberProperty);
    lua_setfield(L, -2, "SetNumberProperty");
    lua_pushcfunction(L, GenL_SDL_SetPaletteColors);
    lua_setfield(L, -2, "SetPaletteColors");
    lua_pushcfunction(L, GenL_SDL_SetPrimarySelectionText);
    lua_setfield(L, -2, "SetPrimarySelectionText");
    lua_pushcfunction(L, GenL_SDL_SetRenderClipRect);
    lua_setfield(L, -2, "SetRenderClipRect");
    lua_pushcfunction(L, GenL_SDL_SetRenderColorScale);
    lua_setfield(L, -2, "SetRenderColorScale");
    lua_pushcfunction(L, GenL_SDL_SetRenderDrawBlendMode);
    lua_setfield(L, -2, "SetRenderDrawBlendMode");
    lua_pushcfunction(L, GenL_SDL_SetRenderDrawColor);
    lua_setfield(L, -2, "SetRenderDrawColor");
    lua_pushcfunction(L, GenL_SDL_SetRenderDrawColorFloat);
    lua_setfield(L, -2, "SetRenderDrawColorFloat");
    lua_pushcfunction(L, GenL_SDL_SetRenderLogicalPresentation);
    lua_setfield(L, -2, "SetRenderLogicalPresentation");
    lua_pushcfunction(L, GenL_SDL_SetRenderScale);
    lua_setfield(L, -2, "SetRenderScale");
    lua_pushcfunction(L, GenL_SDL_SetRenderTarget);
    lua_setfield(L, -2, "SetRenderTarget");
    lua_pushcfunction(L, GenL_SDL_SetRenderTextureAddressMode);
    lua_setfield(L, -2, "SetRenderTextureAddressMode");
    lua_pushcfunction(L, GenL_SDL_SetRenderVSync);
    lua_setfield(L, -2, "SetRenderVSync");
    lua_pushcfunction(L, GenL_SDL_SetRenderViewport);
    lua_setfield(L, -2, "SetRenderViewport");
    lua_pushcfunction(L, GenL_SDL_SetScancodeName);
    lua_setfield(L, -2, "SetScancodeName");
    lua_pushcfunction(L, GenL_SDL_SetStringProperty);
    lua_setfield(L, -2, "SetStringProperty");
    lua_pushcfunction(L, GenL_SDL_SetSurfaceAlphaMod);
    lua_setfield(L, -2, "SetSurfaceAlphaMod");
    lua_pushcfunction(L, GenL_SDL_SetSurfaceBlendMode);
    lua_setfield(L, -2, "SetSurfaceBlendMode");
    lua_pushcfunction(L, GenL_SDL_SetSurfaceClipRect);
    lua_setfield(L, -2, "SetSurfaceClipRect");
    lua_pushcfunction(L, GenL_SDL_SetSurfaceColorKey);
    lua_setfield(L, -2, "SetSurfaceColorKey");
    lua_pushcfunction(L, GenL_SDL_SetSurfaceColorMod);
    lua_setfield(L, -2, "SetSurfaceColorMod");
    lua_pushcfunction(L, GenL_SDL_SetSurfaceColorspace);
    lua_setfield(L, -2, "SetSurfaceColorspace");
    lua_pushcfunction(L, GenL_SDL_SetSurfacePalette);
    lua_setfield(L, -2, "SetSurfacePalette");
    lua_pushcfunction(L, GenL_SDL_SetSurfaceRLE);
    lua_setfield(L, -2, "SetSurfaceRLE");
    lua_pushcfunction(L, GenL_SDL_SetTextInputArea);
    lua_setfield(L, -2, "SetTextInputArea");
    lua_pushcfunction(L, GenL_SDL_SetTextureAlphaMod);
    lua_setfield(L, -2, "SetTextureAlphaMod");
    lua_pushcfunction(L, GenL_SDL_SetTextureAlphaModFloat);
    lua_setfield(L, -2, "SetTextureAlphaModFloat");
    lua_pushcfunction(L, GenL_SDL_SetTextureBlendMode);
    lua_setfield(L, -2, "SetTextureBlendMode");
    lua_pushcfunction(L, GenL_SDL_SetTextureColorMod);
    lua_setfield(L, -2, "SetTextureColorMod");
    lua_pushcfunction(L, GenL_SDL_SetTextureColorModFloat);
    lua_setfield(L, -2, "SetTextureColorModFloat");
    lua_pushcfunction(L, GenL_SDL_SetTexturePalette);
    lua_setfield(L, -2, "SetTexturePalette");
    lua_pushcfunction(L, GenL_SDL_SetTextureScaleMode);
    lua_setfield(L, -2, "SetTextureScaleMode");
    lua_pushcfunction(L, GenL_SDL_SetTrayEntryChecked);
    lua_setfield(L, -2, "SetTrayEntryChecked");
    lua_pushcfunction(L, GenL_SDL_SetTrayEntryEnabled);
    lua_setfield(L, -2, "SetTrayEntryEnabled");
    lua_pushcfunction(L, GenL_SDL_SetTrayEntryLabel);
    lua_setfield(L, -2, "SetTrayEntryLabel");
    lua_pushcfunction(L, GenL_SDL_SetTrayIcon);
    lua_setfield(L, -2, "SetTrayIcon");
    lua_pushcfunction(L, GenL_SDL_SetTrayTooltip);
    lua_setfield(L, -2, "SetTrayTooltip");
    lua_pushcfunction(L, GenL_SDL_SetWindowAlwaysOnTop);
    lua_setfield(L, -2, "SetWindowAlwaysOnTop");
    lua_pushcfunction(L, GenL_SDL_SetWindowAspectRatio);
    lua_setfield(L, -2, "SetWindowAspectRatio");
    lua_pushcfunction(L, GenL_SDL_SetWindowBordered);
    lua_setfield(L, -2, "SetWindowBordered");
    lua_pushcfunction(L, GenL_SDL_SetWindowFillDocument);
    lua_setfield(L, -2, "SetWindowFillDocument");
    lua_pushcfunction(L, GenL_SDL_SetWindowFocusable);
    lua_setfield(L, -2, "SetWindowFocusable");
    lua_pushcfunction(L, GenL_SDL_SetWindowFullscreen);
    lua_setfield(L, -2, "SetWindowFullscreen");
    lua_pushcfunction(L, GenL_SDL_SetWindowFullscreenMode);
    lua_setfield(L, -2, "SetWindowFullscreenMode");
    lua_pushcfunction(L, GenL_SDL_SetWindowIcon);
    lua_setfield(L, -2, "SetWindowIcon");
    lua_pushcfunction(L, GenL_SDL_SetWindowKeyboardGrab);
    lua_setfield(L, -2, "SetWindowKeyboardGrab");
    lua_pushcfunction(L, GenL_SDL_SetWindowMaximumSize);
    lua_setfield(L, -2, "SetWindowMaximumSize");
    lua_pushcfunction(L, GenL_SDL_SetWindowMinimumSize);
    lua_setfield(L, -2, "SetWindowMinimumSize");
    lua_pushcfunction(L, GenL_SDL_SetWindowModal);
    lua_setfield(L, -2, "SetWindowModal");
    lua_pushcfunction(L, GenL_SDL_SetWindowMouseGrab);
    lua_setfield(L, -2, "SetWindowMouseGrab");
    lua_pushcfunction(L, GenL_SDL_SetWindowMouseRect);
    lua_setfield(L, -2, "SetWindowMouseRect");
    lua_pushcfunction(L, GenL_SDL_SetWindowOpacity);
    lua_setfield(L, -2, "SetWindowOpacity");
    lua_pushcfunction(L, GenL_SDL_SetWindowParent);
    lua_setfield(L, -2, "SetWindowParent");
    lua_pushcfunction(L, GenL_SDL_SetWindowPosition);
    lua_setfield(L, -2, "SetWindowPosition");
    lua_pushcfunction(L, GenL_SDL_SetWindowProgressState);
    lua_setfield(L, -2, "SetWindowProgressState");
    lua_pushcfunction(L, GenL_SDL_SetWindowProgressValue);
    lua_setfield(L, -2, "SetWindowProgressValue");
    lua_pushcfunction(L, GenL_SDL_SetWindowRelativeMouseMode);
    lua_setfield(L, -2, "SetWindowRelativeMouseMode");
    lua_pushcfunction(L, GenL_SDL_SetWindowResizable);
    lua_setfield(L, -2, "SetWindowResizable");
    lua_pushcfunction(L, GenL_SDL_SetWindowShape);
    lua_setfield(L, -2, "SetWindowShape");
    lua_pushcfunction(L, GenL_SDL_SetWindowSize);
    lua_setfield(L, -2, "SetWindowSize");
    lua_pushcfunction(L, GenL_SDL_SetWindowSurfaceVSync);
    lua_setfield(L, -2, "SetWindowSurfaceVSync");
    lua_pushcfunction(L, GenL_SDL_SetWindowTitle);
    lua_setfield(L, -2, "SetWindowTitle");
    lua_pushcfunction(L, GenL_SDL_ShouldInit);
    lua_setfield(L, -2, "ShouldInit");
    lua_pushcfunction(L, GenL_SDL_ShouldQuit);
    lua_setfield(L, -2, "ShouldQuit");
    lua_pushcfunction(L, GenL_SDL_ShowCursor);
    lua_setfield(L, -2, "ShowCursor");
    lua_pushcfunction(L, GenL_SDL_ShowMessageBox);
    lua_setfield(L, -2, "ShowMessageBox");
    lua_pushcfunction(L, GenL_SDL_ShowSimpleMessageBox);
    lua_setfield(L, -2, "ShowSimpleMessageBox");
    lua_pushcfunction(L, GenL_SDL_ShowWindow);
    lua_setfield(L, -2, "ShowWindow");
    lua_pushcfunction(L, GenL_SDL_ShowWindowSystemMenu);
    lua_setfield(L, -2, "ShowWindowSystemMenu");
    lua_pushcfunction(L, GenL_SDL_SignalAsyncIOQueue);
    lua_setfield(L, -2, "SignalAsyncIOQueue");
    lua_pushcfunction(L, GenL_SDL_StartTextInput);
    lua_setfield(L, -2, "StartTextInput");
    lua_pushcfunction(L, GenL_SDL_StartTextInputWithProperties);
    lua_setfield(L, -2, "StartTextInputWithProperties");
    lua_pushcfunction(L, GenL_SDL_StopHapticEffect);
    lua_setfield(L, -2, "StopHapticEffect");
    lua_pushcfunction(L, GenL_SDL_StopHapticEffects);
    lua_setfield(L, -2, "StopHapticEffects");
    lua_pushcfunction(L, GenL_SDL_StopHapticRumble);
    lua_setfield(L, -2, "StopHapticRumble");
    lua_pushcfunction(L, GenL_SDL_StopTextInput);
    lua_setfield(L, -2, "StopTextInput");
    lua_pushcfunction(L, GenL_SDL_StorageReady);
    lua_setfield(L, -2, "StorageReady");
    lua_pushcfunction(L, GenL_SDL_StretchSurface);
    lua_setfield(L, -2, "StretchSurface");
    lua_pushcfunction(L, GenL_SDL_StringToGUID);
    lua_setfield(L, -2, "StringToGUID");
    lua_pushcfunction(L, GenL_SDL_SubmitGPUCommandBuffer);
    lua_setfield(L, -2, "SubmitGPUCommandBuffer");
    lua_pushcfunction(L, GenL_SDL_SubmitGPUCommandBufferAndAcquireFence);
    lua_setfield(L, -2, "SubmitGPUCommandBufferAndAcquireFence");
    lua_pushcfunction(L, GenL_SDL_SurfaceHasAlternateImages);
    lua_setfield(L, -2, "SurfaceHasAlternateImages");
    lua_pushcfunction(L, GenL_SDL_SurfaceHasColorKey);
    lua_setfield(L, -2, "SurfaceHasColorKey");
    lua_pushcfunction(L, GenL_SDL_SurfaceHasRLE);
    lua_setfield(L, -2, "SurfaceHasRLE");
    lua_pushcfunction(L, GenL_SDL_SyncWindow);
    lua_setfield(L, -2, "SyncWindow");
    lua_pushcfunction(L, GenL_SDL_TellIO);
    lua_setfield(L, -2, "TellIO");
    lua_pushcfunction(L, GenL_SDL_TextInputActive);
    lua_setfield(L, -2, "TextInputActive");
    lua_pushcfunction(L, GenL_SDL_TimeFromWindows);
    lua_setfield(L, -2, "TimeFromWindows");
    lua_pushcfunction(L, GenL_SDL_TimeToDateTime);
    lua_setfield(L, -2, "TimeToDateTime");
    lua_pushcfunction(L, GenL_SDL_TimeToWindows);
    lua_setfield(L, -2, "TimeToWindows");
    lua_pushcfunction(L, GenL_SDL_TryLockSpinlock);
    lua_setfield(L, -2, "TryLockSpinlock");
    lua_pushcfunction(L, GenL_SDL_UnbindAudioStream);
    lua_setfield(L, -2, "UnbindAudioStream");
    lua_pushcfunction(L, GenL_SDL_UnloadObject);
    lua_setfield(L, -2, "UnloadObject");
    lua_pushcfunction(L, GenL_SDL_UnlockAudioStream);
    lua_setfield(L, -2, "UnlockAudioStream");
    lua_pushcfunction(L, GenL_SDL_UnlockProperties);
    lua_setfield(L, -2, "UnlockProperties");
    lua_pushcfunction(L, GenL_SDL_UnlockSpinlock);
    lua_setfield(L, -2, "UnlockSpinlock");
    lua_pushcfunction(L, GenL_SDL_UnlockSurface);
    lua_setfield(L, -2, "UnlockSurface");
    lua_pushcfunction(L, GenL_SDL_UnlockTexture);
    lua_setfield(L, -2, "UnlockTexture");
    lua_pushcfunction(L, GenL_SDL_UnmapGPUTransferBuffer);
    lua_setfield(L, -2, "UnmapGPUTransferBuffer");
    lua_pushcfunction(L, GenL_SDL_UnsetEnvironmentVariable);
    lua_setfield(L, -2, "UnsetEnvironmentVariable");
    lua_pushcfunction(L, GenL_SDL_UpdateGamepads);
    lua_setfield(L, -2, "UpdateGamepads");
    lua_pushcfunction(L, GenL_SDL_UpdateHapticEffect);
    lua_setfield(L, -2, "UpdateHapticEffect");
    lua_pushcfunction(L, GenL_SDL_UpdateJoysticks);
    lua_setfield(L, -2, "UpdateJoysticks");
    lua_pushcfunction(L, GenL_SDL_UpdateSensors);
    lua_setfield(L, -2, "UpdateSensors");
    lua_pushcfunction(L, GenL_SDL_UpdateTrays);
    lua_setfield(L, -2, "UpdateTrays");
    lua_pushcfunction(L, GenL_SDL_UpdateWindowSurface);
    lua_setfield(L, -2, "UpdateWindowSurface");
    lua_pushcfunction(L, GenL_SDL_UpdateWindowSurfaceRects);
    lua_setfield(L, -2, "UpdateWindowSurfaceRects");
    lua_pushcfunction(L, GenL_SDL_UploadToGPUBuffer);
    lua_setfield(L, -2, "UploadToGPUBuffer");
    lua_pushcfunction(L, GenL_SDL_UploadToGPUTexture);
    lua_setfield(L, -2, "UploadToGPUTexture");
    lua_pushcfunction(L, GenL_SDL_WaitAsyncIOResult);
    lua_setfield(L, -2, "WaitAsyncIOResult");
    lua_pushcfunction(L, GenL_SDL_WaitEvent);
    lua_setfield(L, -2, "WaitEvent");
    lua_pushcfunction(L, GenL_SDL_WaitEventTimeout);
    lua_setfield(L, -2, "WaitEventTimeout");
    lua_pushcfunction(L, GenL_SDL_WaitForGPUIdle);
    lua_setfield(L, -2, "WaitForGPUIdle");
    lua_pushcfunction(L, GenL_SDL_WaitForGPUSwapchain);
    lua_setfield(L, -2, "WaitForGPUSwapchain");
    lua_pushcfunction(L, GenL_SDL_WaitProcess);
    lua_setfield(L, -2, "WaitProcess");
    lua_pushcfunction(L, GenL_SDL_WarpMouseGlobal);
    lua_setfield(L, -2, "WarpMouseGlobal");
    lua_pushcfunction(L, GenL_SDL_WarpMouseInWindow);
    lua_setfield(L, -2, "WarpMouseInWindow");
    lua_pushcfunction(L, GenL_SDL_WasInit);
    lua_setfield(L, -2, "WasInit");
    lua_pushcfunction(L, GenL_SDL_WindowHasSurface);
    lua_setfield(L, -2, "WindowHasSurface");
    lua_pushcfunction(L, GenL_SDL_WindowSupportsGPUPresentMode);
    lua_setfield(L, -2, "WindowSupportsGPUPresentMode");
    lua_pushcfunction(L, GenL_SDL_WindowSupportsGPUSwapchainComposition);
    lua_setfield(L, -2, "WindowSupportsGPUSwapchainComposition");
    lua_pushcfunction(L, GenL_SDL_WriteIO);
    lua_setfield(L, -2, "WriteIO");
    lua_pushcfunction(L, GenL_SDL_WriteS16BE);
    lua_setfield(L, -2, "WriteS16BE");
    lua_pushcfunction(L, GenL_SDL_WriteS16LE);
    lua_setfield(L, -2, "WriteS16LE");
    lua_pushcfunction(L, GenL_SDL_WriteS32BE);
    lua_setfield(L, -2, "WriteS32BE");
    lua_pushcfunction(L, GenL_SDL_WriteS32LE);
    lua_setfield(L, -2, "WriteS32LE");
    lua_pushcfunction(L, GenL_SDL_WriteS64BE);
    lua_setfield(L, -2, "WriteS64BE");
    lua_pushcfunction(L, GenL_SDL_WriteS64LE);
    lua_setfield(L, -2, "WriteS64LE");
    lua_pushcfunction(L, GenL_SDL_WriteS8);
    lua_setfield(L, -2, "WriteS8");
    lua_pushcfunction(L, GenL_SDL_WriteStorageFile);
    lua_setfield(L, -2, "WriteStorageFile");
    lua_pushcfunction(L, GenL_SDL_WriteSurfacePixel);
    lua_setfield(L, -2, "WriteSurfacePixel");
    lua_pushcfunction(L, GenL_SDL_WriteSurfacePixelFloat);
    lua_setfield(L, -2, "WriteSurfacePixelFloat");
    lua_pushcfunction(L, GenL_SDL_WriteU16BE);
    lua_setfield(L, -2, "WriteU16BE");
    lua_pushcfunction(L, GenL_SDL_WriteU16LE);
    lua_setfield(L, -2, "WriteU16LE");
    lua_pushcfunction(L, GenL_SDL_WriteU32BE);
    lua_setfield(L, -2, "WriteU32BE");
    lua_pushcfunction(L, GenL_SDL_WriteU32LE);
    lua_setfield(L, -2, "WriteU32LE");
    lua_pushcfunction(L, GenL_SDL_WriteU64BE);
    lua_setfield(L, -2, "WriteU64BE");
    lua_pushcfunction(L, GenL_SDL_WriteU64LE);
    lua_setfield(L, -2, "WriteU64LE");
    lua_pushcfunction(L, GenL_SDL_WriteU8);
    lua_setfield(L, -2, "WriteU8");
    lua_pushcfunction(L, GenL_SDL_getenv);
    lua_setfield(L, -2, "getenv");
    lua_pushcfunction(L, GenL_SDL_getenv_unsafe);
    lua_setfield(L, -2, "getenv_unsafe");
    lua_pushcfunction(L, GenL_SDL_hid_ble_scan);
    lua_setfield(L, -2, "hid_ble_scan");
    lua_pushcfunction(L, GenL_SDL_hid_close);
    lua_setfield(L, -2, "hid_close");
    lua_pushcfunction(L, GenL_SDL_hid_device_change_count);
    lua_setfield(L, -2, "hid_device_change_count");
    lua_pushcfunction(L, GenL_SDL_hid_enumerate);
    lua_setfield(L, -2, "hid_enumerate");
    lua_pushcfunction(L, GenL_SDL_hid_exit);
    lua_setfield(L, -2, "hid_exit");
    lua_pushcfunction(L, GenL_SDL_hid_free_enumeration);
    lua_setfield(L, -2, "hid_free_enumeration");
    lua_pushcfunction(L, GenL_SDL_hid_get_device_info);
    lua_setfield(L, -2, "hid_get_device_info");
    lua_pushcfunction(L, GenL_SDL_hid_get_properties);
    lua_setfield(L, -2, "hid_get_properties");
    lua_pushcfunction(L, GenL_SDL_hid_init);
    lua_setfield(L, -2, "hid_init");
    lua_pushcfunction(L, GenL_SDL_hid_open_path);
    lua_setfield(L, -2, "hid_open_path");
    lua_pushcfunction(L, GenL_SDL_hid_send_feature_report);
    lua_setfield(L, -2, "hid_send_feature_report");
    lua_pushcfunction(L, GenL_SDL_hid_set_nonblocking);
    lua_setfield(L, -2, "hid_set_nonblocking");
    lua_pushcfunction(L, GenL_SDL_hid_write);
    lua_setfield(L, -2, "hid_write");
    lua_pushcfunction(L, GenL_SDL_iconv_string);
    lua_setfield(L, -2, "iconv_string");
    lua_pushcfunction(L, GenL_SDL_setenv_unsafe);
    lua_setfield(L, -2, "setenv_unsafe");
    lua_pushcfunction(L, GenL_SDL_unsetenv_unsafe);
    lua_setfield(L, -2, "unsetenv_unsafe");
    lua_pushcfunction(L, GenL_SDL_utf8strlen);
    lua_setfield(L, -2, "utf8strlen");
    lua_pushcfunction(L, GenL_SDL_utf8strnlen);
    lua_setfield(L, -2, "utf8strnlen");
    lua_pushinteger(L, (lua_Integer)SDL_APP_CONTINUE);
    lua_setfield(L, -2, "APP_CONTINUE");
    lua_pushinteger(L, (lua_Integer)SDL_APP_SUCCESS);
    lua_setfield(L, -2, "APP_SUCCESS");
    lua_pushinteger(L, (lua_Integer)SDL_APP_FAILURE);
    lua_setfield(L, -2, "APP_FAILURE");
    lua_pushinteger(L, (lua_Integer)SDL_ARRAYORDER_NONE);
    lua_setfield(L, -2, "ARRAYORDER_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_ARRAYORDER_RGB);
    lua_setfield(L, -2, "ARRAYORDER_RGB");
    lua_pushinteger(L, (lua_Integer)SDL_ARRAYORDER_RGBA);
    lua_setfield(L, -2, "ARRAYORDER_RGBA");
    lua_pushinteger(L, (lua_Integer)SDL_ARRAYORDER_ARGB);
    lua_setfield(L, -2, "ARRAYORDER_ARGB");
    lua_pushinteger(L, (lua_Integer)SDL_ARRAYORDER_BGR);
    lua_setfield(L, -2, "ARRAYORDER_BGR");
    lua_pushinteger(L, (lua_Integer)SDL_ARRAYORDER_BGRA);
    lua_setfield(L, -2, "ARRAYORDER_BGRA");
    lua_pushinteger(L, (lua_Integer)SDL_ARRAYORDER_ABGR);
    lua_setfield(L, -2, "ARRAYORDER_ABGR");
    lua_pushinteger(L, (lua_Integer)SDL_ASSERTION_RETRY);
    lua_setfield(L, -2, "ASSERTION_RETRY");
    lua_pushinteger(L, (lua_Integer)SDL_ASSERTION_BREAK);
    lua_setfield(L, -2, "ASSERTION_BREAK");
    lua_pushinteger(L, (lua_Integer)SDL_ASSERTION_ABORT);
    lua_setfield(L, -2, "ASSERTION_ABORT");
    lua_pushinteger(L, (lua_Integer)SDL_ASSERTION_IGNORE);
    lua_setfield(L, -2, "ASSERTION_IGNORE");
    lua_pushinteger(L, (lua_Integer)SDL_ASSERTION_ALWAYS_IGNORE);
    lua_setfield(L, -2, "ASSERTION_ALWAYS_IGNORE");
    lua_pushinteger(L, (lua_Integer)SDL_ASYNCIO_COMPLETE);
    lua_setfield(L, -2, "ASYNCIO_COMPLETE");
    lua_pushinteger(L, (lua_Integer)SDL_ASYNCIO_FAILURE);
    lua_setfield(L, -2, "ASYNCIO_FAILURE");
    lua_pushinteger(L, (lua_Integer)SDL_ASYNCIO_CANCELED);
    lua_setfield(L, -2, "ASYNCIO_CANCELED");
    lua_pushinteger(L, (lua_Integer)SDL_ASYNCIO_TASK_READ);
    lua_setfield(L, -2, "ASYNCIO_TASK_READ");
    lua_pushinteger(L, (lua_Integer)SDL_ASYNCIO_TASK_WRITE);
    lua_setfield(L, -2, "ASYNCIO_TASK_WRITE");
    lua_pushinteger(L, (lua_Integer)SDL_ASYNCIO_TASK_CLOSE);
    lua_setfield(L, -2, "ASYNCIO_TASK_CLOSE");
    lua_pushinteger(L, (lua_Integer)SDL_AUDIO_UNKNOWN);
    lua_setfield(L, -2, "AUDIO_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_AUDIO_U8);
    lua_setfield(L, -2, "AUDIO_U8");
    lua_pushinteger(L, (lua_Integer)SDL_AUDIO_S8);
    lua_setfield(L, -2, "AUDIO_S8");
    lua_pushinteger(L, (lua_Integer)SDL_AUDIO_S16LE);
    lua_setfield(L, -2, "AUDIO_S16LE");
    lua_pushinteger(L, (lua_Integer)SDL_AUDIO_S16BE);
    lua_setfield(L, -2, "AUDIO_S16BE");
    lua_pushinteger(L, (lua_Integer)SDL_AUDIO_S32LE);
    lua_setfield(L, -2, "AUDIO_S32LE");
    lua_pushinteger(L, (lua_Integer)SDL_AUDIO_S32BE);
    lua_setfield(L, -2, "AUDIO_S32BE");
    lua_pushinteger(L, (lua_Integer)SDL_AUDIO_F32LE);
    lua_setfield(L, -2, "AUDIO_F32LE");
    lua_pushinteger(L, (lua_Integer)SDL_AUDIO_F32BE);
    lua_setfield(L, -2, "AUDIO_F32BE");
    lua_pushinteger(L, (lua_Integer)SDL_BYTEORDER);
    lua_setfield(L, -2, "BYTEORDER");
    lua_pushinteger(L, (lua_Integer)SDL_AUDIO_S32);
    lua_setfield(L, -2, "AUDIO_S32");
    lua_pushinteger(L, (lua_Integer)SDL_AUDIO_F32);
    lua_setfield(L, -2, "AUDIO_F32");
    lua_pushinteger(L, (lua_Integer)SDL_BITMAPORDER_NONE);
    lua_setfield(L, -2, "BITMAPORDER_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_BITMAPORDER_4321);
    lua_setfield(L, -2, "BITMAPORDER_4321");
    lua_pushinteger(L, (lua_Integer)SDL_BITMAPORDER_1234);
    lua_setfield(L, -2, "BITMAPORDER_1234");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDFACTOR_ZERO);
    lua_setfield(L, -2, "BLENDFACTOR_ZERO");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDFACTOR_ONE);
    lua_setfield(L, -2, "BLENDFACTOR_ONE");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDFACTOR_SRC_COLOR);
    lua_setfield(L, -2, "BLENDFACTOR_SRC_COLOR");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR);
    lua_setfield(L, -2, "BLENDFACTOR_ONE_MINUS_SRC_COLOR");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDFACTOR_SRC_ALPHA);
    lua_setfield(L, -2, "BLENDFACTOR_SRC_ALPHA");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA);
    lua_setfield(L, -2, "BLENDFACTOR_ONE_MINUS_SRC_ALPHA");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDFACTOR_DST_COLOR);
    lua_setfield(L, -2, "BLENDFACTOR_DST_COLOR");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDFACTOR_ONE_MINUS_DST_COLOR);
    lua_setfield(L, -2, "BLENDFACTOR_ONE_MINUS_DST_COLOR");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDFACTOR_DST_ALPHA);
    lua_setfield(L, -2, "BLENDFACTOR_DST_ALPHA");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA);
    lua_setfield(L, -2, "BLENDFACTOR_ONE_MINUS_DST_ALPHA");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDOPERATION_ADD);
    lua_setfield(L, -2, "BLENDOPERATION_ADD");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDOPERATION_SUBTRACT);
    lua_setfield(L, -2, "BLENDOPERATION_SUBTRACT");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDOPERATION_REV_SUBTRACT);
    lua_setfield(L, -2, "BLENDOPERATION_REV_SUBTRACT");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDOPERATION_MINIMUM);
    lua_setfield(L, -2, "BLENDOPERATION_MINIMUM");
    lua_pushinteger(L, (lua_Integer)SDL_BLENDOPERATION_MAXIMUM);
    lua_setfield(L, -2, "BLENDOPERATION_MAXIMUM");
    lua_pushinteger(L, (lua_Integer)SDL_CAMERA_PERMISSION_STATE_DENIED);
    lua_setfield(L, -2, "CAMERA_PERMISSION_STATE_DENIED");
    lua_pushinteger(L, (lua_Integer)SDL_CAMERA_PERMISSION_STATE_PENDING);
    lua_setfield(L, -2, "CAMERA_PERMISSION_STATE_PENDING");
    lua_pushinteger(L, (lua_Integer)SDL_CAMERA_PERMISSION_STATE_APPROVED);
    lua_setfield(L, -2, "CAMERA_PERMISSION_STATE_APPROVED");
    lua_pushinteger(L, (lua_Integer)SDL_CAMERA_POSITION_UNKNOWN);
    lua_setfield(L, -2, "CAMERA_POSITION_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_CAMERA_POSITION_FRONT_FACING);
    lua_setfield(L, -2, "CAMERA_POSITION_FRONT_FACING");
    lua_pushinteger(L, (lua_Integer)SDL_CAMERA_POSITION_BACK_FACING);
    lua_setfield(L, -2, "CAMERA_POSITION_BACK_FACING");
    lua_pushinteger(L, (lua_Integer)SDL_CAPITALIZE_NONE);
    lua_setfield(L, -2, "CAPITALIZE_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_CAPITALIZE_SENTENCES);
    lua_setfield(L, -2, "CAPITALIZE_SENTENCES");
    lua_pushinteger(L, (lua_Integer)SDL_CAPITALIZE_WORDS);
    lua_setfield(L, -2, "CAPITALIZE_WORDS");
    lua_pushinteger(L, (lua_Integer)SDL_CAPITALIZE_LETTERS);
    lua_setfield(L, -2, "CAPITALIZE_LETTERS");
    lua_pushinteger(L, (lua_Integer)SDL_CHROMA_LOCATION_NONE);
    lua_setfield(L, -2, "CHROMA_LOCATION_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_CHROMA_LOCATION_LEFT);
    lua_setfield(L, -2, "CHROMA_LOCATION_LEFT");
    lua_pushinteger(L, (lua_Integer)SDL_CHROMA_LOCATION_CENTER);
    lua_setfield(L, -2, "CHROMA_LOCATION_CENTER");
    lua_pushinteger(L, (lua_Integer)SDL_CHROMA_LOCATION_TOPLEFT);
    lua_setfield(L, -2, "CHROMA_LOCATION_TOPLEFT");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_UNKNOWN);
    lua_setfield(L, -2, "COLOR_PRIMARIES_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_BT709);
    lua_setfield(L, -2, "COLOR_PRIMARIES_BT709");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_UNSPECIFIED);
    lua_setfield(L, -2, "COLOR_PRIMARIES_UNSPECIFIED");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_BT470M);
    lua_setfield(L, -2, "COLOR_PRIMARIES_BT470M");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_BT470BG);
    lua_setfield(L, -2, "COLOR_PRIMARIES_BT470BG");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_BT601);
    lua_setfield(L, -2, "COLOR_PRIMARIES_BT601");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_SMPTE240);
    lua_setfield(L, -2, "COLOR_PRIMARIES_SMPTE240");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_GENERIC_FILM);
    lua_setfield(L, -2, "COLOR_PRIMARIES_GENERIC_FILM");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_BT2020);
    lua_setfield(L, -2, "COLOR_PRIMARIES_BT2020");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_XYZ);
    lua_setfield(L, -2, "COLOR_PRIMARIES_XYZ");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_SMPTE431);
    lua_setfield(L, -2, "COLOR_PRIMARIES_SMPTE431");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_SMPTE432);
    lua_setfield(L, -2, "COLOR_PRIMARIES_SMPTE432");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_EBU3213);
    lua_setfield(L, -2, "COLOR_PRIMARIES_EBU3213");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_PRIMARIES_CUSTOM);
    lua_setfield(L, -2, "COLOR_PRIMARIES_CUSTOM");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_RANGE_UNKNOWN);
    lua_setfield(L, -2, "COLOR_RANGE_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_RANGE_LIMITED);
    lua_setfield(L, -2, "COLOR_RANGE_LIMITED");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_RANGE_FULL);
    lua_setfield(L, -2, "COLOR_RANGE_FULL");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_TYPE_UNKNOWN);
    lua_setfield(L, -2, "COLOR_TYPE_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_TYPE_RGB);
    lua_setfield(L, -2, "COLOR_TYPE_RGB");
    lua_pushinteger(L, (lua_Integer)SDL_COLOR_TYPE_YCBCR);
    lua_setfield(L, -2, "COLOR_TYPE_YCBCR");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_UNKNOWN);
    lua_setfield(L, -2, "COLORSPACE_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_SRGB);
    lua_setfield(L, -2, "COLORSPACE_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_SRGB_LINEAR);
    lua_setfield(L, -2, "COLORSPACE_SRGB_LINEAR");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_HDR10);
    lua_setfield(L, -2, "COLORSPACE_HDR10");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_JPEG);
    lua_setfield(L, -2, "COLORSPACE_JPEG");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_BT601_LIMITED);
    lua_setfield(L, -2, "COLORSPACE_BT601_LIMITED");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_BT601_FULL);
    lua_setfield(L, -2, "COLORSPACE_BT601_FULL");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_BT709_LIMITED);
    lua_setfield(L, -2, "COLORSPACE_BT709_LIMITED");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_BT709_FULL);
    lua_setfield(L, -2, "COLORSPACE_BT709_FULL");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_BT2020_LIMITED);
    lua_setfield(L, -2, "COLORSPACE_BT2020_LIMITED");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_BT2020_FULL);
    lua_setfield(L, -2, "COLORSPACE_BT2020_FULL");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_RGB_DEFAULT);
    lua_setfield(L, -2, "COLORSPACE_RGB_DEFAULT");
    lua_pushinteger(L, (lua_Integer)SDL_COLORSPACE_YUV_DEFAULT);
    lua_setfield(L, -2, "COLORSPACE_YUV_DEFAULT");
    lua_pushinteger(L, (lua_Integer)SDL_DATE_FORMAT_YYYYMMDD);
    lua_setfield(L, -2, "DATE_FORMAT_YYYYMMDD");
    lua_pushinteger(L, (lua_Integer)SDL_DATE_FORMAT_DDMMYYYY);
    lua_setfield(L, -2, "DATE_FORMAT_DDMMYYYY");
    lua_pushinteger(L, (lua_Integer)SDL_DATE_FORMAT_MMDDYYYY);
    lua_setfield(L, -2, "DATE_FORMAT_MMDDYYYY");
    lua_pushinteger(L, (lua_Integer)SDL_ORIENTATION_UNKNOWN);
    lua_setfield(L, -2, "ORIENTATION_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_ORIENTATION_LANDSCAPE);
    lua_setfield(L, -2, "ORIENTATION_LANDSCAPE");
    lua_pushinteger(L, (lua_Integer)SDL_ORIENTATION_LANDSCAPE_FLIPPED);
    lua_setfield(L, -2, "ORIENTATION_LANDSCAPE_FLIPPED");
    lua_pushinteger(L, (lua_Integer)SDL_ORIENTATION_PORTRAIT);
    lua_setfield(L, -2, "ORIENTATION_PORTRAIT");
    lua_pushinteger(L, (lua_Integer)SDL_ORIENTATION_PORTRAIT_FLIPPED);
    lua_setfield(L, -2, "ORIENTATION_PORTRAIT_FLIPPED");
    lua_pushinteger(L, (lua_Integer)SDL_ENUM_CONTINUE);
    lua_setfield(L, -2, "ENUM_CONTINUE");
    lua_pushinteger(L, (lua_Integer)SDL_ENUM_SUCCESS);
    lua_setfield(L, -2, "ENUM_SUCCESS");
    lua_pushinteger(L, (lua_Integer)SDL_ENUM_FAILURE);
    lua_setfield(L, -2, "ENUM_FAILURE");
    lua_pushinteger(L, (lua_Integer)SDL_ADDEVENT);
    lua_setfield(L, -2, "ADDEVENT");
    lua_pushinteger(L, (lua_Integer)SDL_PEEKEVENT);
    lua_setfield(L, -2, "PEEKEVENT");
    lua_pushinteger(L, (lua_Integer)SDL_GETEVENT);
    lua_setfield(L, -2, "GETEVENT");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_FIRST);
    lua_setfield(L, -2, "EVENT_FIRST");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_QUIT);
    lua_setfield(L, -2, "EVENT_QUIT");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_TERMINATING);
    lua_setfield(L, -2, "EVENT_TERMINATING");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_LOW_MEMORY);
    lua_setfield(L, -2, "EVENT_LOW_MEMORY");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WILL_ENTER_BACKGROUND);
    lua_setfield(L, -2, "EVENT_WILL_ENTER_BACKGROUND");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DID_ENTER_BACKGROUND);
    lua_setfield(L, -2, "EVENT_DID_ENTER_BACKGROUND");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WILL_ENTER_FOREGROUND);
    lua_setfield(L, -2, "EVENT_WILL_ENTER_FOREGROUND");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DID_ENTER_FOREGROUND);
    lua_setfield(L, -2, "EVENT_DID_ENTER_FOREGROUND");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_LOCALE_CHANGED);
    lua_setfield(L, -2, "EVENT_LOCALE_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_SYSTEM_THEME_CHANGED);
    lua_setfield(L, -2, "EVENT_SYSTEM_THEME_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DISPLAY_ORIENTATION);
    lua_setfield(L, -2, "EVENT_DISPLAY_ORIENTATION");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DISPLAY_ADDED);
    lua_setfield(L, -2, "EVENT_DISPLAY_ADDED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DISPLAY_REMOVED);
    lua_setfield(L, -2, "EVENT_DISPLAY_REMOVED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DISPLAY_MOVED);
    lua_setfield(L, -2, "EVENT_DISPLAY_MOVED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DISPLAY_DESKTOP_MODE_CHANGED);
    lua_setfield(L, -2, "EVENT_DISPLAY_DESKTOP_MODE_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DISPLAY_CURRENT_MODE_CHANGED);
    lua_setfield(L, -2, "EVENT_DISPLAY_CURRENT_MODE_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED);
    lua_setfield(L, -2, "EVENT_DISPLAY_CONTENT_SCALE_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DISPLAY_USABLE_BOUNDS_CHANGED);
    lua_setfield(L, -2, "EVENT_DISPLAY_USABLE_BOUNDS_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DISPLAY_FIRST);
    lua_setfield(L, -2, "EVENT_DISPLAY_FIRST");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DISPLAY_LAST);
    lua_setfield(L, -2, "EVENT_DISPLAY_LAST");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_SHOWN);
    lua_setfield(L, -2, "EVENT_WINDOW_SHOWN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_HIDDEN);
    lua_setfield(L, -2, "EVENT_WINDOW_HIDDEN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_EXPOSED);
    lua_setfield(L, -2, "EVENT_WINDOW_EXPOSED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_MOVED);
    lua_setfield(L, -2, "EVENT_WINDOW_MOVED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_RESIZED);
    lua_setfield(L, -2, "EVENT_WINDOW_RESIZED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED);
    lua_setfield(L, -2, "EVENT_WINDOW_PIXEL_SIZE_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_METAL_VIEW_RESIZED);
    lua_setfield(L, -2, "EVENT_WINDOW_METAL_VIEW_RESIZED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_MINIMIZED);
    lua_setfield(L, -2, "EVENT_WINDOW_MINIMIZED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_MAXIMIZED);
    lua_setfield(L, -2, "EVENT_WINDOW_MAXIMIZED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_RESTORED);
    lua_setfield(L, -2, "EVENT_WINDOW_RESTORED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_MOUSE_ENTER);
    lua_setfield(L, -2, "EVENT_WINDOW_MOUSE_ENTER");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_MOUSE_LEAVE);
    lua_setfield(L, -2, "EVENT_WINDOW_MOUSE_LEAVE");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_FOCUS_GAINED);
    lua_setfield(L, -2, "EVENT_WINDOW_FOCUS_GAINED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_FOCUS_LOST);
    lua_setfield(L, -2, "EVENT_WINDOW_FOCUS_LOST");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_CLOSE_REQUESTED);
    lua_setfield(L, -2, "EVENT_WINDOW_CLOSE_REQUESTED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_HIT_TEST);
    lua_setfield(L, -2, "EVENT_WINDOW_HIT_TEST");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_ICCPROF_CHANGED);
    lua_setfield(L, -2, "EVENT_WINDOW_ICCPROF_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_DISPLAY_CHANGED);
    lua_setfield(L, -2, "EVENT_WINDOW_DISPLAY_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_DISPLAY_SCALE_CHANGED);
    lua_setfield(L, -2, "EVENT_WINDOW_DISPLAY_SCALE_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_SAFE_AREA_CHANGED);
    lua_setfield(L, -2, "EVENT_WINDOW_SAFE_AREA_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_OCCLUDED);
    lua_setfield(L, -2, "EVENT_WINDOW_OCCLUDED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_ENTER_FULLSCREEN);
    lua_setfield(L, -2, "EVENT_WINDOW_ENTER_FULLSCREEN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_LEAVE_FULLSCREEN);
    lua_setfield(L, -2, "EVENT_WINDOW_LEAVE_FULLSCREEN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_DESTROYED);
    lua_setfield(L, -2, "EVENT_WINDOW_DESTROYED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_HDR_STATE_CHANGED);
    lua_setfield(L, -2, "EVENT_WINDOW_HDR_STATE_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_FIRST);
    lua_setfield(L, -2, "EVENT_WINDOW_FIRST");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_WINDOW_LAST);
    lua_setfield(L, -2, "EVENT_WINDOW_LAST");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_KEY_DOWN);
    lua_setfield(L, -2, "EVENT_KEY_DOWN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_KEY_UP);
    lua_setfield(L, -2, "EVENT_KEY_UP");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_TEXT_EDITING);
    lua_setfield(L, -2, "EVENT_TEXT_EDITING");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_TEXT_INPUT);
    lua_setfield(L, -2, "EVENT_TEXT_INPUT");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_KEYMAP_CHANGED);
    lua_setfield(L, -2, "EVENT_KEYMAP_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_KEYBOARD_ADDED);
    lua_setfield(L, -2, "EVENT_KEYBOARD_ADDED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_KEYBOARD_REMOVED);
    lua_setfield(L, -2, "EVENT_KEYBOARD_REMOVED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_TEXT_EDITING_CANDIDATES);
    lua_setfield(L, -2, "EVENT_TEXT_EDITING_CANDIDATES");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_SCREEN_KEYBOARD_SHOWN);
    lua_setfield(L, -2, "EVENT_SCREEN_KEYBOARD_SHOWN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_SCREEN_KEYBOARD_HIDDEN);
    lua_setfield(L, -2, "EVENT_SCREEN_KEYBOARD_HIDDEN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_MOUSE_MOTION);
    lua_setfield(L, -2, "EVENT_MOUSE_MOTION");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_MOUSE_BUTTON_DOWN);
    lua_setfield(L, -2, "EVENT_MOUSE_BUTTON_DOWN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_MOUSE_BUTTON_UP);
    lua_setfield(L, -2, "EVENT_MOUSE_BUTTON_UP");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_MOUSE_WHEEL);
    lua_setfield(L, -2, "EVENT_MOUSE_WHEEL");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_MOUSE_ADDED);
    lua_setfield(L, -2, "EVENT_MOUSE_ADDED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_MOUSE_REMOVED);
    lua_setfield(L, -2, "EVENT_MOUSE_REMOVED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_JOYSTICK_AXIS_MOTION);
    lua_setfield(L, -2, "EVENT_JOYSTICK_AXIS_MOTION");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_JOYSTICK_BALL_MOTION);
    lua_setfield(L, -2, "EVENT_JOYSTICK_BALL_MOTION");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_JOYSTICK_HAT_MOTION);
    lua_setfield(L, -2, "EVENT_JOYSTICK_HAT_MOTION");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_JOYSTICK_BUTTON_DOWN);
    lua_setfield(L, -2, "EVENT_JOYSTICK_BUTTON_DOWN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_JOYSTICK_BUTTON_UP);
    lua_setfield(L, -2, "EVENT_JOYSTICK_BUTTON_UP");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_JOYSTICK_ADDED);
    lua_setfield(L, -2, "EVENT_JOYSTICK_ADDED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_JOYSTICK_REMOVED);
    lua_setfield(L, -2, "EVENT_JOYSTICK_REMOVED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_JOYSTICK_BATTERY_UPDATED);
    lua_setfield(L, -2, "EVENT_JOYSTICK_BATTERY_UPDATED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_JOYSTICK_UPDATE_COMPLETE);
    lua_setfield(L, -2, "EVENT_JOYSTICK_UPDATE_COMPLETE");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_AXIS_MOTION);
    lua_setfield(L, -2, "EVENT_GAMEPAD_AXIS_MOTION");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_BUTTON_DOWN);
    lua_setfield(L, -2, "EVENT_GAMEPAD_BUTTON_DOWN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_BUTTON_UP);
    lua_setfield(L, -2, "EVENT_GAMEPAD_BUTTON_UP");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_ADDED);
    lua_setfield(L, -2, "EVENT_GAMEPAD_ADDED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_REMOVED);
    lua_setfield(L, -2, "EVENT_GAMEPAD_REMOVED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_REMAPPED);
    lua_setfield(L, -2, "EVENT_GAMEPAD_REMAPPED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN);
    lua_setfield(L, -2, "EVENT_GAMEPAD_TOUCHPAD_DOWN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION);
    lua_setfield(L, -2, "EVENT_GAMEPAD_TOUCHPAD_MOTION");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_TOUCHPAD_UP);
    lua_setfield(L, -2, "EVENT_GAMEPAD_TOUCHPAD_UP");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_SENSOR_UPDATE);
    lua_setfield(L, -2, "EVENT_GAMEPAD_SENSOR_UPDATE");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_UPDATE_COMPLETE);
    lua_setfield(L, -2, "EVENT_GAMEPAD_UPDATE_COMPLETE");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_GAMEPAD_STEAM_HANDLE_UPDATED);
    lua_setfield(L, -2, "EVENT_GAMEPAD_STEAM_HANDLE_UPDATED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_FINGER_DOWN);
    lua_setfield(L, -2, "EVENT_FINGER_DOWN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_FINGER_UP);
    lua_setfield(L, -2, "EVENT_FINGER_UP");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_FINGER_MOTION);
    lua_setfield(L, -2, "EVENT_FINGER_MOTION");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_FINGER_CANCELED);
    lua_setfield(L, -2, "EVENT_FINGER_CANCELED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PINCH_BEGIN);
    lua_setfield(L, -2, "EVENT_PINCH_BEGIN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PINCH_UPDATE);
    lua_setfield(L, -2, "EVENT_PINCH_UPDATE");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PINCH_END);
    lua_setfield(L, -2, "EVENT_PINCH_END");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_CLIPBOARD_UPDATE);
    lua_setfield(L, -2, "EVENT_CLIPBOARD_UPDATE");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DROP_FILE);
    lua_setfield(L, -2, "EVENT_DROP_FILE");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DROP_TEXT);
    lua_setfield(L, -2, "EVENT_DROP_TEXT");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DROP_BEGIN);
    lua_setfield(L, -2, "EVENT_DROP_BEGIN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DROP_COMPLETE);
    lua_setfield(L, -2, "EVENT_DROP_COMPLETE");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_DROP_POSITION);
    lua_setfield(L, -2, "EVENT_DROP_POSITION");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_AUDIO_DEVICE_ADDED);
    lua_setfield(L, -2, "EVENT_AUDIO_DEVICE_ADDED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_AUDIO_DEVICE_REMOVED);
    lua_setfield(L, -2, "EVENT_AUDIO_DEVICE_REMOVED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_AUDIO_DEVICE_FORMAT_CHANGED);
    lua_setfield(L, -2, "EVENT_AUDIO_DEVICE_FORMAT_CHANGED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_SENSOR_UPDATE);
    lua_setfield(L, -2, "EVENT_SENSOR_UPDATE");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PEN_PROXIMITY_IN);
    lua_setfield(L, -2, "EVENT_PEN_PROXIMITY_IN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PEN_PROXIMITY_OUT);
    lua_setfield(L, -2, "EVENT_PEN_PROXIMITY_OUT");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PEN_DOWN);
    lua_setfield(L, -2, "EVENT_PEN_DOWN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PEN_UP);
    lua_setfield(L, -2, "EVENT_PEN_UP");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PEN_BUTTON_DOWN);
    lua_setfield(L, -2, "EVENT_PEN_BUTTON_DOWN");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PEN_BUTTON_UP);
    lua_setfield(L, -2, "EVENT_PEN_BUTTON_UP");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PEN_MOTION);
    lua_setfield(L, -2, "EVENT_PEN_MOTION");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PEN_AXIS);
    lua_setfield(L, -2, "EVENT_PEN_AXIS");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_CAMERA_DEVICE_ADDED);
    lua_setfield(L, -2, "EVENT_CAMERA_DEVICE_ADDED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_CAMERA_DEVICE_REMOVED);
    lua_setfield(L, -2, "EVENT_CAMERA_DEVICE_REMOVED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_CAMERA_DEVICE_APPROVED);
    lua_setfield(L, -2, "EVENT_CAMERA_DEVICE_APPROVED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_CAMERA_DEVICE_DENIED);
    lua_setfield(L, -2, "EVENT_CAMERA_DEVICE_DENIED");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_RENDER_TARGETS_RESET);
    lua_setfield(L, -2, "EVENT_RENDER_TARGETS_RESET");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_RENDER_DEVICE_RESET);
    lua_setfield(L, -2, "EVENT_RENDER_DEVICE_RESET");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_RENDER_DEVICE_LOST);
    lua_setfield(L, -2, "EVENT_RENDER_DEVICE_LOST");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PRIVATE0);
    lua_setfield(L, -2, "EVENT_PRIVATE0");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PRIVATE1);
    lua_setfield(L, -2, "EVENT_PRIVATE1");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PRIVATE2);
    lua_setfield(L, -2, "EVENT_PRIVATE2");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_PRIVATE3);
    lua_setfield(L, -2, "EVENT_PRIVATE3");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_POLL_SENTINEL);
    lua_setfield(L, -2, "EVENT_POLL_SENTINEL");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_USER);
    lua_setfield(L, -2, "EVENT_USER");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_LAST);
    lua_setfield(L, -2, "EVENT_LAST");
    lua_pushinteger(L, (lua_Integer)SDL_EVENT_ENUM_PADDING);
    lua_setfield(L, -2, "EVENT_ENUM_PADDING");
    lua_pushinteger(L, (lua_Integer)SDL_FILEDIALOG_OPENFILE);
    lua_setfield(L, -2, "FILEDIALOG_OPENFILE");
    lua_pushinteger(L, (lua_Integer)SDL_FILEDIALOG_SAVEFILE);
    lua_setfield(L, -2, "FILEDIALOG_SAVEFILE");
    lua_pushinteger(L, (lua_Integer)SDL_FILEDIALOG_OPENFOLDER);
    lua_setfield(L, -2, "FILEDIALOG_OPENFOLDER");
    lua_pushinteger(L, (lua_Integer)SDL_FLASH_CANCEL);
    lua_setfield(L, -2, "FLASH_CANCEL");
    lua_pushinteger(L, (lua_Integer)SDL_FLASH_BRIEFLY);
    lua_setfield(L, -2, "FLASH_BRIEFLY");
    lua_pushinteger(L, (lua_Integer)SDL_FLASH_UNTIL_FOCUSED);
    lua_setfield(L, -2, "FLASH_UNTIL_FOCUSED");
    lua_pushinteger(L, (lua_Integer)SDL_FLIP_NONE);
    lua_setfield(L, -2, "FLIP_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_FLIP_HORIZONTAL);
    lua_setfield(L, -2, "FLIP_HORIZONTAL");
    lua_pushinteger(L, (lua_Integer)SDL_FLIP_VERTICAL);
    lua_setfield(L, -2, "FLIP_VERTICAL");
    lua_pushinteger(L, (lua_Integer)SDL_FLIP_HORIZONTAL_AND_VERTICAL);
    lua_setfield(L, -2, "FLIP_HORIZONTAL_AND_VERTICAL");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_HOME);
    lua_setfield(L, -2, "FOLDER_HOME");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_DESKTOP);
    lua_setfield(L, -2, "FOLDER_DESKTOP");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_DOCUMENTS);
    lua_setfield(L, -2, "FOLDER_DOCUMENTS");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_DOWNLOADS);
    lua_setfield(L, -2, "FOLDER_DOWNLOADS");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_MUSIC);
    lua_setfield(L, -2, "FOLDER_MUSIC");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_PICTURES);
    lua_setfield(L, -2, "FOLDER_PICTURES");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_PUBLICSHARE);
    lua_setfield(L, -2, "FOLDER_PUBLICSHARE");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_SAVEDGAMES);
    lua_setfield(L, -2, "FOLDER_SAVEDGAMES");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_SCREENSHOTS);
    lua_setfield(L, -2, "FOLDER_SCREENSHOTS");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_TEMPLATES);
    lua_setfield(L, -2, "FOLDER_TEMPLATES");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_VIDEOS);
    lua_setfield(L, -2, "FOLDER_VIDEOS");
    lua_pushinteger(L, (lua_Integer)SDL_FOLDER_COUNT);
    lua_setfield(L, -2, "FOLDER_COUNT");
    lua_pushinteger(L, (lua_Integer)SDL_GL_RED_SIZE);
    lua_setfield(L, -2, "GL_RED_SIZE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_GREEN_SIZE);
    lua_setfield(L, -2, "GL_GREEN_SIZE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_BLUE_SIZE);
    lua_setfield(L, -2, "GL_BLUE_SIZE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_ALPHA_SIZE);
    lua_setfield(L, -2, "GL_ALPHA_SIZE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_BUFFER_SIZE);
    lua_setfield(L, -2, "GL_BUFFER_SIZE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_DOUBLEBUFFER);
    lua_setfield(L, -2, "GL_DOUBLEBUFFER");
    lua_pushinteger(L, (lua_Integer)SDL_GL_DEPTH_SIZE);
    lua_setfield(L, -2, "GL_DEPTH_SIZE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_STENCIL_SIZE);
    lua_setfield(L, -2, "GL_STENCIL_SIZE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_ACCUM_RED_SIZE);
    lua_setfield(L, -2, "GL_ACCUM_RED_SIZE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_ACCUM_GREEN_SIZE);
    lua_setfield(L, -2, "GL_ACCUM_GREEN_SIZE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_ACCUM_BLUE_SIZE);
    lua_setfield(L, -2, "GL_ACCUM_BLUE_SIZE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_ACCUM_ALPHA_SIZE);
    lua_setfield(L, -2, "GL_ACCUM_ALPHA_SIZE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_STEREO);
    lua_setfield(L, -2, "GL_STEREO");
    lua_pushinteger(L, (lua_Integer)SDL_GL_MULTISAMPLEBUFFERS);
    lua_setfield(L, -2, "GL_MULTISAMPLEBUFFERS");
    lua_pushinteger(L, (lua_Integer)SDL_GL_MULTISAMPLESAMPLES);
    lua_setfield(L, -2, "GL_MULTISAMPLESAMPLES");
    lua_pushinteger(L, (lua_Integer)SDL_GL_ACCELERATED_VISUAL);
    lua_setfield(L, -2, "GL_ACCELERATED_VISUAL");
    lua_pushinteger(L, (lua_Integer)SDL_GL_RETAINED_BACKING);
    lua_setfield(L, -2, "GL_RETAINED_BACKING");
    lua_pushinteger(L, (lua_Integer)SDL_GL_CONTEXT_MAJOR_VERSION);
    lua_setfield(L, -2, "GL_CONTEXT_MAJOR_VERSION");
    lua_pushinteger(L, (lua_Integer)SDL_GL_CONTEXT_MINOR_VERSION);
    lua_setfield(L, -2, "GL_CONTEXT_MINOR_VERSION");
    lua_pushinteger(L, (lua_Integer)SDL_GL_CONTEXT_FLAGS);
    lua_setfield(L, -2, "GL_CONTEXT_FLAGS");
    lua_pushinteger(L, (lua_Integer)SDL_GL_CONTEXT_PROFILE_MASK);
    lua_setfield(L, -2, "GL_CONTEXT_PROFILE_MASK");
    lua_pushinteger(L, (lua_Integer)SDL_GL_SHARE_WITH_CURRENT_CONTEXT);
    lua_setfield(L, -2, "GL_SHARE_WITH_CURRENT_CONTEXT");
    lua_pushinteger(L, (lua_Integer)SDL_GL_FRAMEBUFFER_SRGB_CAPABLE);
    lua_setfield(L, -2, "GL_FRAMEBUFFER_SRGB_CAPABLE");
    lua_pushinteger(L, (lua_Integer)SDL_GL_CONTEXT_RELEASE_BEHAVIOR);
    lua_setfield(L, -2, "GL_CONTEXT_RELEASE_BEHAVIOR");
    lua_pushinteger(L, (lua_Integer)SDL_GL_CONTEXT_RESET_NOTIFICATION);
    lua_setfield(L, -2, "GL_CONTEXT_RESET_NOTIFICATION");
    lua_pushinteger(L, (lua_Integer)SDL_GL_CONTEXT_NO_ERROR);
    lua_setfield(L, -2, "GL_CONTEXT_NO_ERROR");
    lua_pushinteger(L, (lua_Integer)SDL_GL_FLOATBUFFERS);
    lua_setfield(L, -2, "GL_FLOATBUFFERS");
    lua_pushinteger(L, (lua_Integer)SDL_GL_EGL_PLATFORM);
    lua_setfield(L, -2, "GL_EGL_PLATFORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_INVALID);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_ZERO);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_ZERO");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_ONE);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_ONE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_SRC_COLOR);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_SRC_COLOR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_COLOR);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_ONE_MINUS_SRC_COLOR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_DST_COLOR);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_DST_COLOR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_ONE_MINUS_DST_COLOR);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_ONE_MINUS_DST_COLOR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_SRC_ALPHA);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_SRC_ALPHA");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_DST_ALPHA);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_DST_ALPHA");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_ONE_MINUS_DST_ALPHA);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_ONE_MINUS_DST_ALPHA");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_CONSTANT_COLOR);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_CONSTANT_COLOR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_ONE_MINUS_CONSTANT_COLOR);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_ONE_MINUS_CONSTANT_COLOR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDFACTOR_SRC_ALPHA_SATURATE);
    lua_setfield(L, -2, "GPU_BLENDFACTOR_SRC_ALPHA_SATURATE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDOP_INVALID);
    lua_setfield(L, -2, "GPU_BLENDOP_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDOP_ADD);
    lua_setfield(L, -2, "GPU_BLENDOP_ADD");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDOP_SUBTRACT);
    lua_setfield(L, -2, "GPU_BLENDOP_SUBTRACT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDOP_REVERSE_SUBTRACT);
    lua_setfield(L, -2, "GPU_BLENDOP_REVERSE_SUBTRACT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDOP_MIN);
    lua_setfield(L, -2, "GPU_BLENDOP_MIN");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_BLENDOP_MAX);
    lua_setfield(L, -2, "GPU_BLENDOP_MAX");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_COMPAREOP_INVALID);
    lua_setfield(L, -2, "GPU_COMPAREOP_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_COMPAREOP_NEVER);
    lua_setfield(L, -2, "GPU_COMPAREOP_NEVER");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_COMPAREOP_LESS);
    lua_setfield(L, -2, "GPU_COMPAREOP_LESS");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_COMPAREOP_EQUAL);
    lua_setfield(L, -2, "GPU_COMPAREOP_EQUAL");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_COMPAREOP_LESS_OR_EQUAL);
    lua_setfield(L, -2, "GPU_COMPAREOP_LESS_OR_EQUAL");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_COMPAREOP_GREATER);
    lua_setfield(L, -2, "GPU_COMPAREOP_GREATER");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_COMPAREOP_NOT_EQUAL);
    lua_setfield(L, -2, "GPU_COMPAREOP_NOT_EQUAL");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_COMPAREOP_GREATER_OR_EQUAL);
    lua_setfield(L, -2, "GPU_COMPAREOP_GREATER_OR_EQUAL");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_COMPAREOP_ALWAYS);
    lua_setfield(L, -2, "GPU_COMPAREOP_ALWAYS");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_CUBEMAPFACE_POSITIVEX);
    lua_setfield(L, -2, "GPU_CUBEMAPFACE_POSITIVEX");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_CUBEMAPFACE_NEGATIVEX);
    lua_setfield(L, -2, "GPU_CUBEMAPFACE_NEGATIVEX");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_CUBEMAPFACE_POSITIVEY);
    lua_setfield(L, -2, "GPU_CUBEMAPFACE_POSITIVEY");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_CUBEMAPFACE_NEGATIVEY);
    lua_setfield(L, -2, "GPU_CUBEMAPFACE_NEGATIVEY");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_CUBEMAPFACE_POSITIVEZ);
    lua_setfield(L, -2, "GPU_CUBEMAPFACE_POSITIVEZ");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_CUBEMAPFACE_NEGATIVEZ);
    lua_setfield(L, -2, "GPU_CUBEMAPFACE_NEGATIVEZ");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_CULLMODE_NONE);
    lua_setfield(L, -2, "GPU_CULLMODE_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_CULLMODE_FRONT);
    lua_setfield(L, -2, "GPU_CULLMODE_FRONT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_CULLMODE_BACK);
    lua_setfield(L, -2, "GPU_CULLMODE_BACK");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_FILLMODE_FILL);
    lua_setfield(L, -2, "GPU_FILLMODE_FILL");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_FILLMODE_LINE);
    lua_setfield(L, -2, "GPU_FILLMODE_LINE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_FILTER_NEAREST);
    lua_setfield(L, -2, "GPU_FILTER_NEAREST");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_FILTER_LINEAR);
    lua_setfield(L, -2, "GPU_FILTER_LINEAR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_FRONTFACE_COUNTER_CLOCKWISE);
    lua_setfield(L, -2, "GPU_FRONTFACE_COUNTER_CLOCKWISE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_FRONTFACE_CLOCKWISE);
    lua_setfield(L, -2, "GPU_FRONTFACE_CLOCKWISE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_INDEXELEMENTSIZE_16BIT);
    lua_setfield(L, -2, "GPU_INDEXELEMENTSIZE_16BIT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_INDEXELEMENTSIZE_32BIT);
    lua_setfield(L, -2, "GPU_INDEXELEMENTSIZE_32BIT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_LOADOP_LOAD);
    lua_setfield(L, -2, "GPU_LOADOP_LOAD");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_LOADOP_CLEAR);
    lua_setfield(L, -2, "GPU_LOADOP_CLEAR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_LOADOP_DONT_CARE);
    lua_setfield(L, -2, "GPU_LOADOP_DONT_CARE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_PRESENTMODE_VSYNC);
    lua_setfield(L, -2, "GPU_PRESENTMODE_VSYNC");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_PRESENTMODE_IMMEDIATE);
    lua_setfield(L, -2, "GPU_PRESENTMODE_IMMEDIATE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_PRESENTMODE_MAILBOX);
    lua_setfield(L, -2, "GPU_PRESENTMODE_MAILBOX");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_PRIMITIVETYPE_TRIANGLELIST);
    lua_setfield(L, -2, "GPU_PRIMITIVETYPE_TRIANGLELIST");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_PRIMITIVETYPE_TRIANGLESTRIP);
    lua_setfield(L, -2, "GPU_PRIMITIVETYPE_TRIANGLESTRIP");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_PRIMITIVETYPE_LINELIST);
    lua_setfield(L, -2, "GPU_PRIMITIVETYPE_LINELIST");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_PRIMITIVETYPE_LINESTRIP);
    lua_setfield(L, -2, "GPU_PRIMITIVETYPE_LINESTRIP");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_PRIMITIVETYPE_POINTLIST);
    lua_setfield(L, -2, "GPU_PRIMITIVETYPE_POINTLIST");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SAMPLECOUNT_1);
    lua_setfield(L, -2, "GPU_SAMPLECOUNT_1");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SAMPLECOUNT_2);
    lua_setfield(L, -2, "GPU_SAMPLECOUNT_2");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SAMPLECOUNT_4);
    lua_setfield(L, -2, "GPU_SAMPLECOUNT_4");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SAMPLECOUNT_8);
    lua_setfield(L, -2, "GPU_SAMPLECOUNT_8");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SAMPLERADDRESSMODE_REPEAT);
    lua_setfield(L, -2, "GPU_SAMPLERADDRESSMODE_REPEAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SAMPLERADDRESSMODE_MIRRORED_REPEAT);
    lua_setfield(L, -2, "GPU_SAMPLERADDRESSMODE_MIRRORED_REPEAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE);
    lua_setfield(L, -2, "GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SAMPLERMIPMAPMODE_NEAREST);
    lua_setfield(L, -2, "GPU_SAMPLERMIPMAPMODE_NEAREST");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SAMPLERMIPMAPMODE_LINEAR);
    lua_setfield(L, -2, "GPU_SAMPLERMIPMAPMODE_LINEAR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SHADERSTAGE_VERTEX);
    lua_setfield(L, -2, "GPU_SHADERSTAGE_VERTEX");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SHADERSTAGE_FRAGMENT);
    lua_setfield(L, -2, "GPU_SHADERSTAGE_FRAGMENT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STENCILOP_INVALID);
    lua_setfield(L, -2, "GPU_STENCILOP_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STENCILOP_KEEP);
    lua_setfield(L, -2, "GPU_STENCILOP_KEEP");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STENCILOP_ZERO);
    lua_setfield(L, -2, "GPU_STENCILOP_ZERO");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STENCILOP_REPLACE);
    lua_setfield(L, -2, "GPU_STENCILOP_REPLACE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STENCILOP_INCREMENT_AND_CLAMP);
    lua_setfield(L, -2, "GPU_STENCILOP_INCREMENT_AND_CLAMP");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STENCILOP_DECREMENT_AND_CLAMP);
    lua_setfield(L, -2, "GPU_STENCILOP_DECREMENT_AND_CLAMP");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STENCILOP_INVERT);
    lua_setfield(L, -2, "GPU_STENCILOP_INVERT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STENCILOP_INCREMENT_AND_WRAP);
    lua_setfield(L, -2, "GPU_STENCILOP_INCREMENT_AND_WRAP");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STENCILOP_DECREMENT_AND_WRAP);
    lua_setfield(L, -2, "GPU_STENCILOP_DECREMENT_AND_WRAP");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STOREOP_STORE);
    lua_setfield(L, -2, "GPU_STOREOP_STORE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STOREOP_DONT_CARE);
    lua_setfield(L, -2, "GPU_STOREOP_DONT_CARE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STOREOP_RESOLVE);
    lua_setfield(L, -2, "GPU_STOREOP_RESOLVE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_STOREOP_RESOLVE_AND_STORE);
    lua_setfield(L, -2, "GPU_STOREOP_RESOLVE_AND_STORE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SWAPCHAINCOMPOSITION_SDR);
    lua_setfield(L, -2, "GPU_SWAPCHAINCOMPOSITION_SDR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SWAPCHAINCOMPOSITION_SDR_LINEAR);
    lua_setfield(L, -2, "GPU_SWAPCHAINCOMPOSITION_SDR_LINEAR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SWAPCHAINCOMPOSITION_HDR_EXTENDED_LINEAR);
    lua_setfield(L, -2, "GPU_SWAPCHAINCOMPOSITION_HDR_EXTENDED_LINEAR");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_SWAPCHAINCOMPOSITION_HDR10_ST2084);
    lua_setfield(L, -2, "GPU_SWAPCHAINCOMPOSITION_HDR10_ST2084");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_INVALID);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_A8_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_A8_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8G8_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8G8_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8G8B8A8_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16G16_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16G16_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16G16B16A16_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16G16B16A16_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R10G10B10A2_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R10G10B10A2_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_B5G6R5_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_B5G6R5_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_B5G5R5A1_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_B5G5R5A1_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_B4G4R4A4_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_B4G4R4A4_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_B8G8R8A8_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_B8G8R8A8_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC1_RGBA_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC1_RGBA_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC2_RGBA_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC2_RGBA_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC3_RGBA_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC3_RGBA_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC4_R_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC4_R_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC5_RG_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC5_RG_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC7_RGBA_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC7_RGBA_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC6H_RGB_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC6H_RGB_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC6H_RGB_UFLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC6H_RGB_UFLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8_SNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8_SNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8G8_SNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8G8_SNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8G8B8A8_SNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8G8B8A8_SNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16_SNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16_SNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16G16_SNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16G16_SNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16G16B16A16_SNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16G16B16A16_SNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16G16_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16G16_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16G16B16A16_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16G16B16A16_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R32_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R32_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R32G32_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R32G32_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R32G32B32A32_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R32G32B32A32_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R11G11B10_UFLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R11G11B10_UFLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8_UINT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8G8_UINT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8G8_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UINT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8G8B8A8_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16_UINT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16G16_UINT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16G16_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16G16B16A16_UINT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16G16B16A16_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R32_UINT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R32_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R32G32_UINT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R32G32_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R32G32B32A32_UINT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R32G32B32A32_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8_INT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8_INT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8G8_INT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8G8_INT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8G8B8A8_INT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8G8B8A8_INT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16_INT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16_INT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16G16_INT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16G16_INT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R16G16B16A16_INT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R16G16B16A16_INT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R32_INT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R32_INT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R32G32_INT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R32G32_INT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R32G32B32A32_INT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R32G32B32A32_INT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_R8G8B8A8_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_B8G8R8A8_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_B8G8R8A8_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC1_RGBA_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC1_RGBA_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC2_RGBA_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC2_RGBA_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC3_RGBA_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC3_RGBA_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_BC7_RGBA_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_BC7_RGBA_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_D16_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_D16_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_D24_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_D24_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_D32_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_D32_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_D24_UNORM_S8_UINT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_D24_UNORM_S8_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_D32_FLOAT_S8_UINT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_D32_FLOAT_S8_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_4x4_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_4x4_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_5x4_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_5x4_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_5x5_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_5x5_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_6x5_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_6x5_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_6x6_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_6x6_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_8x5_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_8x5_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_8x6_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_8x6_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_8x8_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_8x8_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x5_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x5_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x6_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x6_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x8_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x8_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x10_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x10_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_12x10_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_12x10_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_12x12_UNORM);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_12x12_UNORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_4x4_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_4x4_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_5x4_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_5x4_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_5x5_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_5x5_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_6x5_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_6x5_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_6x6_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_6x6_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_8x5_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_8x5_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_8x6_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_8x6_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_8x8_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_8x8_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x5_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x5_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x6_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x6_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x8_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x8_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x10_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x10_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_12x10_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_12x10_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_12x12_UNORM_SRGB);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_12x12_UNORM_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_4x4_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_4x4_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_5x4_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_5x4_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_5x5_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_5x5_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_6x5_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_6x5_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_6x6_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_6x6_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_8x5_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_8x5_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_8x6_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_8x6_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_8x8_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_8x8_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x5_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x5_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x6_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x6_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x8_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x8_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_10x10_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_10x10_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_12x10_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_12x10_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTUREFORMAT_ASTC_12x12_FLOAT);
    lua_setfield(L, -2, "GPU_TEXTUREFORMAT_ASTC_12x12_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTURETYPE_2D);
    lua_setfield(L, -2, "GPU_TEXTURETYPE_2D");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTURETYPE_2D_ARRAY);
    lua_setfield(L, -2, "GPU_TEXTURETYPE_2D_ARRAY");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTURETYPE_3D);
    lua_setfield(L, -2, "GPU_TEXTURETYPE_3D");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTURETYPE_CUBE);
    lua_setfield(L, -2, "GPU_TEXTURETYPE_CUBE");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TEXTURETYPE_CUBE_ARRAY);
    lua_setfield(L, -2, "GPU_TEXTURETYPE_CUBE_ARRAY");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD);
    lua_setfield(L, -2, "GPU_TRANSFERBUFFERUSAGE_UPLOAD");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_TRANSFERBUFFERUSAGE_DOWNLOAD);
    lua_setfield(L, -2, "GPU_TRANSFERBUFFERUSAGE_DOWNLOAD");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_INVALID);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_INT);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_INT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_INT2);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_INT2");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_INT3);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_INT3");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_INT4);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_INT4");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_UINT);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_UINT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_UINT2);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_UINT2");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_UINT3);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_UINT3");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_UINT4);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_UINT4");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_FLOAT);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_FLOAT2);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_FLOAT2");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_FLOAT3);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_FLOAT3");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_FLOAT4);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_FLOAT4");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_BYTE2);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_BYTE2");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_BYTE4);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_BYTE4");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_UBYTE2);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_UBYTE2");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_UBYTE4);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_UBYTE4");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_BYTE2_NORM);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_BYTE2_NORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_BYTE4_NORM);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_BYTE4_NORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_UBYTE2_NORM);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_UBYTE2_NORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_UBYTE4_NORM);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_UBYTE4_NORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_SHORT2);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_SHORT2");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_SHORT4);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_SHORT4");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_USHORT2);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_USHORT2");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_USHORT4);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_USHORT4");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_SHORT2_NORM);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_SHORT2_NORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_SHORT4_NORM);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_SHORT4_NORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_USHORT2_NORM);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_USHORT2_NORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_USHORT4_NORM);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_USHORT4_NORM");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_HALF2);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_HALF2");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXELEMENTFORMAT_HALF4);
    lua_setfield(L, -2, "GPU_VERTEXELEMENTFORMAT_HALF4");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXINPUTRATE_VERTEX);
    lua_setfield(L, -2, "GPU_VERTEXINPUTRATE_VERTEX");
    lua_pushinteger(L, (lua_Integer)SDL_GPU_VERTEXINPUTRATE_INSTANCE);
    lua_setfield(L, -2, "GPU_VERTEXINPUTRATE_INSTANCE");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_AXIS_INVALID);
    lua_setfield(L, -2, "GAMEPAD_AXIS_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_AXIS_LEFTX);
    lua_setfield(L, -2, "GAMEPAD_AXIS_LEFTX");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_AXIS_LEFTY);
    lua_setfield(L, -2, "GAMEPAD_AXIS_LEFTY");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_AXIS_RIGHTX);
    lua_setfield(L, -2, "GAMEPAD_AXIS_RIGHTX");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_AXIS_RIGHTY);
    lua_setfield(L, -2, "GAMEPAD_AXIS_RIGHTY");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_AXIS_LEFT_TRIGGER);
    lua_setfield(L, -2, "GAMEPAD_AXIS_LEFT_TRIGGER");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_AXIS_RIGHT_TRIGGER);
    lua_setfield(L, -2, "GAMEPAD_AXIS_RIGHT_TRIGGER");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_AXIS_COUNT);
    lua_setfield(L, -2, "GAMEPAD_AXIS_COUNT");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BINDTYPE_NONE);
    lua_setfield(L, -2, "GAMEPAD_BINDTYPE_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BINDTYPE_BUTTON);
    lua_setfield(L, -2, "GAMEPAD_BINDTYPE_BUTTON");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BINDTYPE_AXIS);
    lua_setfield(L, -2, "GAMEPAD_BINDTYPE_AXIS");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BINDTYPE_HAT);
    lua_setfield(L, -2, "GAMEPAD_BINDTYPE_HAT");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_INVALID);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_SOUTH);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_SOUTH");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_EAST);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_EAST");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_WEST);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_WEST");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_NORTH);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_NORTH");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_BACK);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_BACK");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_GUIDE);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_GUIDE");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_START);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_START");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LEFT_STICK);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LEFT_STICK");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_RIGHT_STICK);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_RIGHT_STICK");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LEFT_SHOULDER);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LEFT_SHOULDER");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_RIGHT_SHOULDER");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_DPAD_UP);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_DPAD_UP");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_DPAD_DOWN);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_DPAD_DOWN");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_DPAD_LEFT);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_DPAD_LEFT");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_DPAD_RIGHT);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_DPAD_RIGHT");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_MISC1);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_MISC1");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_RIGHT_PADDLE1);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_RIGHT_PADDLE1");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LEFT_PADDLE1);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LEFT_PADDLE1");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_RIGHT_PADDLE2);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_RIGHT_PADDLE2");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LEFT_PADDLE2);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LEFT_PADDLE2");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_TOUCHPAD);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_TOUCHPAD");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_MISC2);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_MISC2");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_MISC3);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_MISC3");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_MISC4);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_MISC4");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_MISC5);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_MISC5");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_MISC6);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_MISC6");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_COUNT);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_COUNT");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LABEL_UNKNOWN);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LABEL_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LABEL_A);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LABEL_A");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LABEL_B);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LABEL_B");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LABEL_X);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LABEL_X");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LABEL_Y);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LABEL_Y");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LABEL_CROSS);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LABEL_CROSS");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LABEL_CIRCLE);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LABEL_CIRCLE");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LABEL_SQUARE);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LABEL_SQUARE");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_BUTTON_LABEL_TRIANGLE);
    lua_setfield(L, -2, "GAMEPAD_BUTTON_LABEL_TRIANGLE");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_UNKNOWN);
    lua_setfield(L, -2, "GAMEPAD_TYPE_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_STANDARD);
    lua_setfield(L, -2, "GAMEPAD_TYPE_STANDARD");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_XBOX360);
    lua_setfield(L, -2, "GAMEPAD_TYPE_XBOX360");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_XBOXONE);
    lua_setfield(L, -2, "GAMEPAD_TYPE_XBOXONE");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_PS3);
    lua_setfield(L, -2, "GAMEPAD_TYPE_PS3");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_PS4);
    lua_setfield(L, -2, "GAMEPAD_TYPE_PS4");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_PS5);
    lua_setfield(L, -2, "GAMEPAD_TYPE_PS5");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_PRO);
    lua_setfield(L, -2, "GAMEPAD_TYPE_NINTENDO_SWITCH_PRO");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_LEFT);
    lua_setfield(L, -2, "GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_LEFT");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_RIGHT);
    lua_setfield(L, -2, "GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_RIGHT");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_PAIR);
    lua_setfield(L, -2, "GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_PAIR");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_GAMECUBE);
    lua_setfield(L, -2, "GAMEPAD_TYPE_GAMECUBE");
    lua_pushinteger(L, (lua_Integer)SDL_GAMEPAD_TYPE_COUNT);
    lua_setfield(L, -2, "GAMEPAD_TYPE_COUNT");
    lua_pushinteger(L, (lua_Integer)SDL_HINT_DEFAULT);
    lua_setfield(L, -2, "HINT_DEFAULT");
    lua_pushinteger(L, (lua_Integer)SDL_HINT_NORMAL);
    lua_setfield(L, -2, "HINT_NORMAL");
    lua_pushinteger(L, (lua_Integer)SDL_HINT_OVERRIDE);
    lua_setfield(L, -2, "HINT_OVERRIDE");
    lua_pushinteger(L, (lua_Integer)SDL_HITTEST_NORMAL);
    lua_setfield(L, -2, "HITTEST_NORMAL");
    lua_pushinteger(L, (lua_Integer)SDL_HITTEST_DRAGGABLE);
    lua_setfield(L, -2, "HITTEST_DRAGGABLE");
    lua_pushinteger(L, (lua_Integer)SDL_HITTEST_RESIZE_TOPLEFT);
    lua_setfield(L, -2, "HITTEST_RESIZE_TOPLEFT");
    lua_pushinteger(L, (lua_Integer)SDL_HITTEST_RESIZE_TOP);
    lua_setfield(L, -2, "HITTEST_RESIZE_TOP");
    lua_pushinteger(L, (lua_Integer)SDL_HITTEST_RESIZE_TOPRIGHT);
    lua_setfield(L, -2, "HITTEST_RESIZE_TOPRIGHT");
    lua_pushinteger(L, (lua_Integer)SDL_HITTEST_RESIZE_RIGHT);
    lua_setfield(L, -2, "HITTEST_RESIZE_RIGHT");
    lua_pushinteger(L, (lua_Integer)SDL_HITTEST_RESIZE_BOTTOMRIGHT);
    lua_setfield(L, -2, "HITTEST_RESIZE_BOTTOMRIGHT");
    lua_pushinteger(L, (lua_Integer)SDL_HITTEST_RESIZE_BOTTOM);
    lua_setfield(L, -2, "HITTEST_RESIZE_BOTTOM");
    lua_pushinteger(L, (lua_Integer)SDL_HITTEST_RESIZE_BOTTOMLEFT);
    lua_setfield(L, -2, "HITTEST_RESIZE_BOTTOMLEFT");
    lua_pushinteger(L, (lua_Integer)SDL_HITTEST_RESIZE_LEFT);
    lua_setfield(L, -2, "HITTEST_RESIZE_LEFT");
    lua_pushinteger(L, (lua_Integer)SDL_IO_STATUS_READY);
    lua_setfield(L, -2, "IO_STATUS_READY");
    lua_pushinteger(L, (lua_Integer)SDL_IO_STATUS_ERROR);
    lua_setfield(L, -2, "IO_STATUS_ERROR");
    lua_pushinteger(L, (lua_Integer)SDL_IO_STATUS_EOF);
    lua_setfield(L, -2, "IO_STATUS_EOF");
    lua_pushinteger(L, (lua_Integer)SDL_IO_STATUS_NOT_READY);
    lua_setfield(L, -2, "IO_STATUS_NOT_READY");
    lua_pushinteger(L, (lua_Integer)SDL_IO_STATUS_READONLY);
    lua_setfield(L, -2, "IO_STATUS_READONLY");
    lua_pushinteger(L, (lua_Integer)SDL_IO_STATUS_WRITEONLY);
    lua_setfield(L, -2, "IO_STATUS_WRITEONLY");
    lua_pushinteger(L, (lua_Integer)SDL_IO_SEEK_SET);
    lua_setfield(L, -2, "IO_SEEK_SET");
    lua_pushinteger(L, (lua_Integer)SDL_IO_SEEK_CUR);
    lua_setfield(L, -2, "IO_SEEK_CUR");
    lua_pushinteger(L, (lua_Integer)SDL_IO_SEEK_END);
    lua_setfield(L, -2, "IO_SEEK_END");
    lua_pushinteger(L, (lua_Integer)SDL_INIT_STATUS_UNINITIALIZED);
    lua_setfield(L, -2, "INIT_STATUS_UNINITIALIZED");
    lua_pushinteger(L, (lua_Integer)SDL_INIT_STATUS_INITIALIZING);
    lua_setfield(L, -2, "INIT_STATUS_INITIALIZING");
    lua_pushinteger(L, (lua_Integer)SDL_INIT_STATUS_INITIALIZED);
    lua_setfield(L, -2, "INIT_STATUS_INITIALIZED");
    lua_pushinteger(L, (lua_Integer)SDL_INIT_STATUS_UNINITIALIZING);
    lua_setfield(L, -2, "INIT_STATUS_UNINITIALIZING");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_CONNECTION_INVALID);
    lua_setfield(L, -2, "JOYSTICK_CONNECTION_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_CONNECTION_UNKNOWN);
    lua_setfield(L, -2, "JOYSTICK_CONNECTION_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_CONNECTION_WIRED);
    lua_setfield(L, -2, "JOYSTICK_CONNECTION_WIRED");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_CONNECTION_WIRELESS);
    lua_setfield(L, -2, "JOYSTICK_CONNECTION_WIRELESS");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_TYPE_UNKNOWN);
    lua_setfield(L, -2, "JOYSTICK_TYPE_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_TYPE_GAMEPAD);
    lua_setfield(L, -2, "JOYSTICK_TYPE_GAMEPAD");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_TYPE_WHEEL);
    lua_setfield(L, -2, "JOYSTICK_TYPE_WHEEL");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_TYPE_ARCADE_STICK);
    lua_setfield(L, -2, "JOYSTICK_TYPE_ARCADE_STICK");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_TYPE_FLIGHT_STICK);
    lua_setfield(L, -2, "JOYSTICK_TYPE_FLIGHT_STICK");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_TYPE_DANCE_PAD);
    lua_setfield(L, -2, "JOYSTICK_TYPE_DANCE_PAD");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_TYPE_GUITAR);
    lua_setfield(L, -2, "JOYSTICK_TYPE_GUITAR");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_TYPE_DRUM_KIT);
    lua_setfield(L, -2, "JOYSTICK_TYPE_DRUM_KIT");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_TYPE_ARCADE_PAD);
    lua_setfield(L, -2, "JOYSTICK_TYPE_ARCADE_PAD");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_TYPE_THROTTLE);
    lua_setfield(L, -2, "JOYSTICK_TYPE_THROTTLE");
    lua_pushinteger(L, (lua_Integer)SDL_JOYSTICK_TYPE_COUNT);
    lua_setfield(L, -2, "JOYSTICK_TYPE_COUNT");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_APPLICATION);
    lua_setfield(L, -2, "LOG_CATEGORY_APPLICATION");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_ERROR);
    lua_setfield(L, -2, "LOG_CATEGORY_ERROR");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_ASSERT);
    lua_setfield(L, -2, "LOG_CATEGORY_ASSERT");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_SYSTEM);
    lua_setfield(L, -2, "LOG_CATEGORY_SYSTEM");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_AUDIO);
    lua_setfield(L, -2, "LOG_CATEGORY_AUDIO");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_VIDEO);
    lua_setfield(L, -2, "LOG_CATEGORY_VIDEO");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_RENDER);
    lua_setfield(L, -2, "LOG_CATEGORY_RENDER");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_INPUT);
    lua_setfield(L, -2, "LOG_CATEGORY_INPUT");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_TEST);
    lua_setfield(L, -2, "LOG_CATEGORY_TEST");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_GPU);
    lua_setfield(L, -2, "LOG_CATEGORY_GPU");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_RESERVED2);
    lua_setfield(L, -2, "LOG_CATEGORY_RESERVED2");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_RESERVED3);
    lua_setfield(L, -2, "LOG_CATEGORY_RESERVED3");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_RESERVED4);
    lua_setfield(L, -2, "LOG_CATEGORY_RESERVED4");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_RESERVED5);
    lua_setfield(L, -2, "LOG_CATEGORY_RESERVED5");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_RESERVED6);
    lua_setfield(L, -2, "LOG_CATEGORY_RESERVED6");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_RESERVED7);
    lua_setfield(L, -2, "LOG_CATEGORY_RESERVED7");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_RESERVED8);
    lua_setfield(L, -2, "LOG_CATEGORY_RESERVED8");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_RESERVED9);
    lua_setfield(L, -2, "LOG_CATEGORY_RESERVED9");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_RESERVED10);
    lua_setfield(L, -2, "LOG_CATEGORY_RESERVED10");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_CATEGORY_CUSTOM);
    lua_setfield(L, -2, "LOG_CATEGORY_CUSTOM");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_PRIORITY_INVALID);
    lua_setfield(L, -2, "LOG_PRIORITY_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_PRIORITY_TRACE);
    lua_setfield(L, -2, "LOG_PRIORITY_TRACE");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_PRIORITY_VERBOSE);
    lua_setfield(L, -2, "LOG_PRIORITY_VERBOSE");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_PRIORITY_DEBUG);
    lua_setfield(L, -2, "LOG_PRIORITY_DEBUG");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_PRIORITY_INFO);
    lua_setfield(L, -2, "LOG_PRIORITY_INFO");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_PRIORITY_WARN);
    lua_setfield(L, -2, "LOG_PRIORITY_WARN");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_PRIORITY_ERROR);
    lua_setfield(L, -2, "LOG_PRIORITY_ERROR");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_PRIORITY_CRITICAL);
    lua_setfield(L, -2, "LOG_PRIORITY_CRITICAL");
    lua_pushinteger(L, (lua_Integer)SDL_LOG_PRIORITY_COUNT);
    lua_setfield(L, -2, "LOG_PRIORITY_COUNT");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_IDENTITY);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_IDENTITY");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_BT709);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_BT709");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_UNSPECIFIED);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_UNSPECIFIED");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_FCC);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_FCC");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_BT470BG);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_BT470BG");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_BT601);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_BT601");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_SMPTE240);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_SMPTE240");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_YCGCO);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_YCGCO");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_BT2020_NCL);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_BT2020_NCL");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_BT2020_CL);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_BT2020_CL");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_SMPTE2085);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_SMPTE2085");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_CHROMA_DERIVED_NCL);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_CHROMA_DERIVED_NCL");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_CHROMA_DERIVED_CL);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_CHROMA_DERIVED_CL");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_ICTCP);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_ICTCP");
    lua_pushinteger(L, (lua_Integer)SDL_MATRIX_COEFFICIENTS_CUSTOM);
    lua_setfield(L, -2, "MATRIX_COEFFICIENTS_CUSTOM");
    lua_pushinteger(L, (lua_Integer)SDL_MESSAGEBOX_COLOR_BACKGROUND);
    lua_setfield(L, -2, "MESSAGEBOX_COLOR_BACKGROUND");
    lua_pushinteger(L, (lua_Integer)SDL_MESSAGEBOX_COLOR_TEXT);
    lua_setfield(L, -2, "MESSAGEBOX_COLOR_TEXT");
    lua_pushinteger(L, (lua_Integer)SDL_MESSAGEBOX_COLOR_BUTTON_BORDER);
    lua_setfield(L, -2, "MESSAGEBOX_COLOR_BUTTON_BORDER");
    lua_pushinteger(L, (lua_Integer)SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND);
    lua_setfield(L, -2, "MESSAGEBOX_COLOR_BUTTON_BACKGROUND");
    lua_pushinteger(L, (lua_Integer)SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED);
    lua_setfield(L, -2, "MESSAGEBOX_COLOR_BUTTON_SELECTED");
    lua_pushinteger(L, (lua_Integer)SDL_MESSAGEBOX_COLOR_COUNT);
    lua_setfield(L, -2, "MESSAGEBOX_COLOR_COUNT");
    lua_pushinteger(L, (lua_Integer)SDL_MOUSEWHEEL_NORMAL);
    lua_setfield(L, -2, "MOUSEWHEEL_NORMAL");
    lua_pushinteger(L, (lua_Integer)SDL_MOUSEWHEEL_FLIPPED);
    lua_setfield(L, -2, "MOUSEWHEEL_FLIPPED");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDLAYOUT_NONE);
    lua_setfield(L, -2, "PACKEDLAYOUT_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDLAYOUT_332);
    lua_setfield(L, -2, "PACKEDLAYOUT_332");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDLAYOUT_4444);
    lua_setfield(L, -2, "PACKEDLAYOUT_4444");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDLAYOUT_1555);
    lua_setfield(L, -2, "PACKEDLAYOUT_1555");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDLAYOUT_5551);
    lua_setfield(L, -2, "PACKEDLAYOUT_5551");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDLAYOUT_565);
    lua_setfield(L, -2, "PACKEDLAYOUT_565");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDLAYOUT_8888);
    lua_setfield(L, -2, "PACKEDLAYOUT_8888");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDLAYOUT_2101010);
    lua_setfield(L, -2, "PACKEDLAYOUT_2101010");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDLAYOUT_1010102);
    lua_setfield(L, -2, "PACKEDLAYOUT_1010102");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDORDER_NONE);
    lua_setfield(L, -2, "PACKEDORDER_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDORDER_XRGB);
    lua_setfield(L, -2, "PACKEDORDER_XRGB");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDORDER_RGBX);
    lua_setfield(L, -2, "PACKEDORDER_RGBX");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDORDER_ARGB);
    lua_setfield(L, -2, "PACKEDORDER_ARGB");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDORDER_RGBA);
    lua_setfield(L, -2, "PACKEDORDER_RGBA");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDORDER_XBGR);
    lua_setfield(L, -2, "PACKEDORDER_XBGR");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDORDER_BGRX);
    lua_setfield(L, -2, "PACKEDORDER_BGRX");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDORDER_ABGR);
    lua_setfield(L, -2, "PACKEDORDER_ABGR");
    lua_pushinteger(L, (lua_Integer)SDL_PACKEDORDER_BGRA);
    lua_setfield(L, -2, "PACKEDORDER_BGRA");
    lua_pushinteger(L, (lua_Integer)SDL_PATHTYPE_NONE);
    lua_setfield(L, -2, "PATHTYPE_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_PATHTYPE_FILE);
    lua_setfield(L, -2, "PATHTYPE_FILE");
    lua_pushinteger(L, (lua_Integer)SDL_PATHTYPE_DIRECTORY);
    lua_setfield(L, -2, "PATHTYPE_DIRECTORY");
    lua_pushinteger(L, (lua_Integer)SDL_PATHTYPE_OTHER);
    lua_setfield(L, -2, "PATHTYPE_OTHER");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_AXIS_PRESSURE);
    lua_setfield(L, -2, "PEN_AXIS_PRESSURE");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_AXIS_XTILT);
    lua_setfield(L, -2, "PEN_AXIS_XTILT");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_AXIS_YTILT);
    lua_setfield(L, -2, "PEN_AXIS_YTILT");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_AXIS_DISTANCE);
    lua_setfield(L, -2, "PEN_AXIS_DISTANCE");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_AXIS_ROTATION);
    lua_setfield(L, -2, "PEN_AXIS_ROTATION");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_AXIS_SLIDER);
    lua_setfield(L, -2, "PEN_AXIS_SLIDER");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_AXIS_TANGENTIAL_PRESSURE);
    lua_setfield(L, -2, "PEN_AXIS_TANGENTIAL_PRESSURE");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_AXIS_COUNT);
    lua_setfield(L, -2, "PEN_AXIS_COUNT");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_DEVICE_TYPE_INVALID);
    lua_setfield(L, -2, "PEN_DEVICE_TYPE_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_DEVICE_TYPE_UNKNOWN);
    lua_setfield(L, -2, "PEN_DEVICE_TYPE_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_DEVICE_TYPE_DIRECT);
    lua_setfield(L, -2, "PEN_DEVICE_TYPE_DIRECT");
    lua_pushinteger(L, (lua_Integer)SDL_PEN_DEVICE_TYPE_INDIRECT);
    lua_setfield(L, -2, "PEN_DEVICE_TYPE_INDIRECT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_UNKNOWN);
    lua_setfield(L, -2, "PIXELFORMAT_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_INDEX1LSB);
    lua_setfield(L, -2, "PIXELFORMAT_INDEX1LSB");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_INDEX1MSB);
    lua_setfield(L, -2, "PIXELFORMAT_INDEX1MSB");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_INDEX2LSB);
    lua_setfield(L, -2, "PIXELFORMAT_INDEX2LSB");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_INDEX2MSB);
    lua_setfield(L, -2, "PIXELFORMAT_INDEX2MSB");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_INDEX4LSB);
    lua_setfield(L, -2, "PIXELFORMAT_INDEX4LSB");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_INDEX4MSB);
    lua_setfield(L, -2, "PIXELFORMAT_INDEX4MSB");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_INDEX8);
    lua_setfield(L, -2, "PIXELFORMAT_INDEX8");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGB332);
    lua_setfield(L, -2, "PIXELFORMAT_RGB332");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_XRGB4444);
    lua_setfield(L, -2, "PIXELFORMAT_XRGB4444");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_XBGR4444);
    lua_setfield(L, -2, "PIXELFORMAT_XBGR4444");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_XRGB1555);
    lua_setfield(L, -2, "PIXELFORMAT_XRGB1555");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_XBGR1555);
    lua_setfield(L, -2, "PIXELFORMAT_XBGR1555");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ARGB4444);
    lua_setfield(L, -2, "PIXELFORMAT_ARGB4444");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGBA4444);
    lua_setfield(L, -2, "PIXELFORMAT_RGBA4444");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ABGR4444);
    lua_setfield(L, -2, "PIXELFORMAT_ABGR4444");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGRA4444);
    lua_setfield(L, -2, "PIXELFORMAT_BGRA4444");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ARGB1555);
    lua_setfield(L, -2, "PIXELFORMAT_ARGB1555");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGBA5551);
    lua_setfield(L, -2, "PIXELFORMAT_RGBA5551");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ABGR1555);
    lua_setfield(L, -2, "PIXELFORMAT_ABGR1555");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGRA5551);
    lua_setfield(L, -2, "PIXELFORMAT_BGRA5551");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGB565);
    lua_setfield(L, -2, "PIXELFORMAT_RGB565");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGR565);
    lua_setfield(L, -2, "PIXELFORMAT_BGR565");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGB24);
    lua_setfield(L, -2, "PIXELFORMAT_RGB24");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGR24);
    lua_setfield(L, -2, "PIXELFORMAT_BGR24");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_XRGB8888);
    lua_setfield(L, -2, "PIXELFORMAT_XRGB8888");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGBX8888);
    lua_setfield(L, -2, "PIXELFORMAT_RGBX8888");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_XBGR8888);
    lua_setfield(L, -2, "PIXELFORMAT_XBGR8888");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGRX8888);
    lua_setfield(L, -2, "PIXELFORMAT_BGRX8888");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ARGB8888);
    lua_setfield(L, -2, "PIXELFORMAT_ARGB8888");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGBA8888);
    lua_setfield(L, -2, "PIXELFORMAT_RGBA8888");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ABGR8888);
    lua_setfield(L, -2, "PIXELFORMAT_ABGR8888");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGRA8888);
    lua_setfield(L, -2, "PIXELFORMAT_BGRA8888");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_XRGB2101010);
    lua_setfield(L, -2, "PIXELFORMAT_XRGB2101010");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_XBGR2101010);
    lua_setfield(L, -2, "PIXELFORMAT_XBGR2101010");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ARGB2101010);
    lua_setfield(L, -2, "PIXELFORMAT_ARGB2101010");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ABGR2101010);
    lua_setfield(L, -2, "PIXELFORMAT_ABGR2101010");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGB48);
    lua_setfield(L, -2, "PIXELFORMAT_RGB48");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGR48);
    lua_setfield(L, -2, "PIXELFORMAT_BGR48");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGBA64);
    lua_setfield(L, -2, "PIXELFORMAT_RGBA64");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ARGB64);
    lua_setfield(L, -2, "PIXELFORMAT_ARGB64");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGRA64);
    lua_setfield(L, -2, "PIXELFORMAT_BGRA64");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ABGR64);
    lua_setfield(L, -2, "PIXELFORMAT_ABGR64");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGB48_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_RGB48_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGR48_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_BGR48_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGBA64_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_RGBA64_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ARGB64_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_ARGB64_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGRA64_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_BGRA64_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ABGR64_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_ABGR64_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGB96_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_RGB96_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGR96_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_BGR96_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGBA128_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_RGBA128_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ARGB128_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_ARGB128_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGRA128_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_BGRA128_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ABGR128_FLOAT);
    lua_setfield(L, -2, "PIXELFORMAT_ABGR128_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_YV12);
    lua_setfield(L, -2, "PIXELFORMAT_YV12");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_IYUV);
    lua_setfield(L, -2, "PIXELFORMAT_IYUV");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_YUY2);
    lua_setfield(L, -2, "PIXELFORMAT_YUY2");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_UYVY);
    lua_setfield(L, -2, "PIXELFORMAT_UYVY");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_YVYU);
    lua_setfield(L, -2, "PIXELFORMAT_YVYU");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_NV12);
    lua_setfield(L, -2, "PIXELFORMAT_NV12");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_NV21);
    lua_setfield(L, -2, "PIXELFORMAT_NV21");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_P010);
    lua_setfield(L, -2, "PIXELFORMAT_P010");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_EXTERNAL_OES);
    lua_setfield(L, -2, "PIXELFORMAT_EXTERNAL_OES");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_MJPG);
    lua_setfield(L, -2, "PIXELFORMAT_MJPG");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ARGB32);
    lua_setfield(L, -2, "PIXELFORMAT_ARGB32");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGRA32);
    lua_setfield(L, -2, "PIXELFORMAT_BGRA32");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_ABGR32);
    lua_setfield(L, -2, "PIXELFORMAT_ABGR32");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_RGBX32);
    lua_setfield(L, -2, "PIXELFORMAT_RGBX32");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_XRGB32);
    lua_setfield(L, -2, "PIXELFORMAT_XRGB32");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_BGRX32);
    lua_setfield(L, -2, "PIXELFORMAT_BGRX32");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELFORMAT_XBGR32);
    lua_setfield(L, -2, "PIXELFORMAT_XBGR32");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_UNKNOWN);
    lua_setfield(L, -2, "PIXELTYPE_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_INDEX1);
    lua_setfield(L, -2, "PIXELTYPE_INDEX1");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_INDEX4);
    lua_setfield(L, -2, "PIXELTYPE_INDEX4");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_INDEX8);
    lua_setfield(L, -2, "PIXELTYPE_INDEX8");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_PACKED8);
    lua_setfield(L, -2, "PIXELTYPE_PACKED8");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_PACKED16);
    lua_setfield(L, -2, "PIXELTYPE_PACKED16");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_PACKED32);
    lua_setfield(L, -2, "PIXELTYPE_PACKED32");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_ARRAYU8);
    lua_setfield(L, -2, "PIXELTYPE_ARRAYU8");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_ARRAYU16);
    lua_setfield(L, -2, "PIXELTYPE_ARRAYU16");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_ARRAYU32);
    lua_setfield(L, -2, "PIXELTYPE_ARRAYU32");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_ARRAYF16);
    lua_setfield(L, -2, "PIXELTYPE_ARRAYF16");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_ARRAYF32);
    lua_setfield(L, -2, "PIXELTYPE_ARRAYF32");
    lua_pushinteger(L, (lua_Integer)SDL_PIXELTYPE_INDEX2);
    lua_setfield(L, -2, "PIXELTYPE_INDEX2");
    lua_pushinteger(L, (lua_Integer)SDL_POWERSTATE_ERROR);
    lua_setfield(L, -2, "POWERSTATE_ERROR");
    lua_pushinteger(L, (lua_Integer)SDL_POWERSTATE_UNKNOWN);
    lua_setfield(L, -2, "POWERSTATE_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_POWERSTATE_ON_BATTERY);
    lua_setfield(L, -2, "POWERSTATE_ON_BATTERY");
    lua_pushinteger(L, (lua_Integer)SDL_POWERSTATE_NO_BATTERY);
    lua_setfield(L, -2, "POWERSTATE_NO_BATTERY");
    lua_pushinteger(L, (lua_Integer)SDL_POWERSTATE_CHARGING);
    lua_setfield(L, -2, "POWERSTATE_CHARGING");
    lua_pushinteger(L, (lua_Integer)SDL_POWERSTATE_CHARGED);
    lua_setfield(L, -2, "POWERSTATE_CHARGED");
    lua_pushinteger(L, (lua_Integer)SDL_PROCESS_STDIO_INHERITED);
    lua_setfield(L, -2, "PROCESS_STDIO_INHERITED");
    lua_pushinteger(L, (lua_Integer)SDL_PROCESS_STDIO_NULL);
    lua_setfield(L, -2, "PROCESS_STDIO_NULL");
    lua_pushinteger(L, (lua_Integer)SDL_PROCESS_STDIO_APP);
    lua_setfield(L, -2, "PROCESS_STDIO_APP");
    lua_pushinteger(L, (lua_Integer)SDL_PROCESS_STDIO_REDIRECT);
    lua_setfield(L, -2, "PROCESS_STDIO_REDIRECT");
    lua_pushinteger(L, (lua_Integer)SDL_PROGRESS_STATE_INVALID);
    lua_setfield(L, -2, "PROGRESS_STATE_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_PROGRESS_STATE_NONE);
    lua_setfield(L, -2, "PROGRESS_STATE_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_PROGRESS_STATE_INDETERMINATE);
    lua_setfield(L, -2, "PROGRESS_STATE_INDETERMINATE");
    lua_pushinteger(L, (lua_Integer)SDL_PROGRESS_STATE_NORMAL);
    lua_setfield(L, -2, "PROGRESS_STATE_NORMAL");
    lua_pushinteger(L, (lua_Integer)SDL_PROGRESS_STATE_PAUSED);
    lua_setfield(L, -2, "PROGRESS_STATE_PAUSED");
    lua_pushinteger(L, (lua_Integer)SDL_PROGRESS_STATE_ERROR);
    lua_setfield(L, -2, "PROGRESS_STATE_ERROR");
    lua_pushinteger(L, (lua_Integer)SDL_PROPERTY_TYPE_INVALID);
    lua_setfield(L, -2, "PROPERTY_TYPE_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_PROPERTY_TYPE_POINTER);
    lua_setfield(L, -2, "PROPERTY_TYPE_POINTER");
    lua_pushinteger(L, (lua_Integer)SDL_PROPERTY_TYPE_STRING);
    lua_setfield(L, -2, "PROPERTY_TYPE_STRING");
    lua_pushinteger(L, (lua_Integer)SDL_PROPERTY_TYPE_NUMBER);
    lua_setfield(L, -2, "PROPERTY_TYPE_NUMBER");
    lua_pushinteger(L, (lua_Integer)SDL_PROPERTY_TYPE_FLOAT);
    lua_setfield(L, -2, "PROPERTY_TYPE_FLOAT");
    lua_pushinteger(L, (lua_Integer)SDL_PROPERTY_TYPE_BOOLEAN);
    lua_setfield(L, -2, "PROPERTY_TYPE_BOOLEAN");
    lua_pushinteger(L, (lua_Integer)SDL_LOGICAL_PRESENTATION_DISABLED);
    lua_setfield(L, -2, "LOGICAL_PRESENTATION_DISABLED");
    lua_pushinteger(L, (lua_Integer)SDL_LOGICAL_PRESENTATION_STRETCH);
    lua_setfield(L, -2, "LOGICAL_PRESENTATION_STRETCH");
    lua_pushinteger(L, (lua_Integer)SDL_LOGICAL_PRESENTATION_LETTERBOX);
    lua_setfield(L, -2, "LOGICAL_PRESENTATION_LETTERBOX");
    lua_pushinteger(L, (lua_Integer)SDL_LOGICAL_PRESENTATION_OVERSCAN);
    lua_setfield(L, -2, "LOGICAL_PRESENTATION_OVERSCAN");
    lua_pushinteger(L, (lua_Integer)SDL_LOGICAL_PRESENTATION_INTEGER_SCALE);
    lua_setfield(L, -2, "LOGICAL_PRESENTATION_INTEGER_SCALE");
    lua_pushinteger(L, (lua_Integer)SDL_SANDBOX_NONE);
    lua_setfield(L, -2, "SANDBOX_NONE");
    lua_pushinteger(L, (lua_Integer)SDL_SANDBOX_UNKNOWN_CONTAINER);
    lua_setfield(L, -2, "SANDBOX_UNKNOWN_CONTAINER");
    lua_pushinteger(L, (lua_Integer)SDL_SANDBOX_FLATPAK);
    lua_setfield(L, -2, "SANDBOX_FLATPAK");
    lua_pushinteger(L, (lua_Integer)SDL_SANDBOX_SNAP);
    lua_setfield(L, -2, "SANDBOX_SNAP");
    lua_pushinteger(L, (lua_Integer)SDL_SANDBOX_MACOS);
    lua_setfield(L, -2, "SANDBOX_MACOS");
    lua_pushinteger(L, (lua_Integer)SDL_SCALEMODE_INVALID);
    lua_setfield(L, -2, "SCALEMODE_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_SCALEMODE_NEAREST);
    lua_setfield(L, -2, "SCALEMODE_NEAREST");
    lua_pushinteger(L, (lua_Integer)SDL_SCALEMODE_LINEAR);
    lua_setfield(L, -2, "SCALEMODE_LINEAR");
    lua_pushinteger(L, (lua_Integer)SDL_SCALEMODE_PIXELART);
    lua_setfield(L, -2, "SCALEMODE_PIXELART");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_UNKNOWN);
    lua_setfield(L, -2, "SCANCODE_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_A);
    lua_setfield(L, -2, "SCANCODE_A");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_B);
    lua_setfield(L, -2, "SCANCODE_B");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_C);
    lua_setfield(L, -2, "SCANCODE_C");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_D);
    lua_setfield(L, -2, "SCANCODE_D");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_E);
    lua_setfield(L, -2, "SCANCODE_E");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F);
    lua_setfield(L, -2, "SCANCODE_F");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_G);
    lua_setfield(L, -2, "SCANCODE_G");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_H);
    lua_setfield(L, -2, "SCANCODE_H");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_I);
    lua_setfield(L, -2, "SCANCODE_I");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_J);
    lua_setfield(L, -2, "SCANCODE_J");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_K);
    lua_setfield(L, -2, "SCANCODE_K");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_L);
    lua_setfield(L, -2, "SCANCODE_L");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_M);
    lua_setfield(L, -2, "SCANCODE_M");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_N);
    lua_setfield(L, -2, "SCANCODE_N");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_O);
    lua_setfield(L, -2, "SCANCODE_O");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_P);
    lua_setfield(L, -2, "SCANCODE_P");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_Q);
    lua_setfield(L, -2, "SCANCODE_Q");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_R);
    lua_setfield(L, -2, "SCANCODE_R");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_S);
    lua_setfield(L, -2, "SCANCODE_S");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_T);
    lua_setfield(L, -2, "SCANCODE_T");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_U);
    lua_setfield(L, -2, "SCANCODE_U");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_V);
    lua_setfield(L, -2, "SCANCODE_V");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_W);
    lua_setfield(L, -2, "SCANCODE_W");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_X);
    lua_setfield(L, -2, "SCANCODE_X");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_Y);
    lua_setfield(L, -2, "SCANCODE_Y");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_Z);
    lua_setfield(L, -2, "SCANCODE_Z");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_1);
    lua_setfield(L, -2, "SCANCODE_1");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_2);
    lua_setfield(L, -2, "SCANCODE_2");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_3);
    lua_setfield(L, -2, "SCANCODE_3");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_4);
    lua_setfield(L, -2, "SCANCODE_4");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_5);
    lua_setfield(L, -2, "SCANCODE_5");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_6);
    lua_setfield(L, -2, "SCANCODE_6");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_7);
    lua_setfield(L, -2, "SCANCODE_7");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_8);
    lua_setfield(L, -2, "SCANCODE_8");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_9);
    lua_setfield(L, -2, "SCANCODE_9");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_0);
    lua_setfield(L, -2, "SCANCODE_0");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_RETURN);
    lua_setfield(L, -2, "SCANCODE_RETURN");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_ESCAPE);
    lua_setfield(L, -2, "SCANCODE_ESCAPE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_BACKSPACE);
    lua_setfield(L, -2, "SCANCODE_BACKSPACE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_TAB);
    lua_setfield(L, -2, "SCANCODE_TAB");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_SPACE);
    lua_setfield(L, -2, "SCANCODE_SPACE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MINUS);
    lua_setfield(L, -2, "SCANCODE_MINUS");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_EQUALS);
    lua_setfield(L, -2, "SCANCODE_EQUALS");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LEFTBRACKET);
    lua_setfield(L, -2, "SCANCODE_LEFTBRACKET");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_RIGHTBRACKET);
    lua_setfield(L, -2, "SCANCODE_RIGHTBRACKET");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_BACKSLASH);
    lua_setfield(L, -2, "SCANCODE_BACKSLASH");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_NONUSHASH);
    lua_setfield(L, -2, "SCANCODE_NONUSHASH");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_SEMICOLON);
    lua_setfield(L, -2, "SCANCODE_SEMICOLON");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_APOSTROPHE);
    lua_setfield(L, -2, "SCANCODE_APOSTROPHE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_GRAVE);
    lua_setfield(L, -2, "SCANCODE_GRAVE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_COMMA);
    lua_setfield(L, -2, "SCANCODE_COMMA");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_PERIOD);
    lua_setfield(L, -2, "SCANCODE_PERIOD");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_SLASH);
    lua_setfield(L, -2, "SCANCODE_SLASH");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_CAPSLOCK);
    lua_setfield(L, -2, "SCANCODE_CAPSLOCK");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F1);
    lua_setfield(L, -2, "SCANCODE_F1");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F2);
    lua_setfield(L, -2, "SCANCODE_F2");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F3);
    lua_setfield(L, -2, "SCANCODE_F3");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F4);
    lua_setfield(L, -2, "SCANCODE_F4");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F5);
    lua_setfield(L, -2, "SCANCODE_F5");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F6);
    lua_setfield(L, -2, "SCANCODE_F6");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F7);
    lua_setfield(L, -2, "SCANCODE_F7");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F8);
    lua_setfield(L, -2, "SCANCODE_F8");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F9);
    lua_setfield(L, -2, "SCANCODE_F9");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F10);
    lua_setfield(L, -2, "SCANCODE_F10");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F11);
    lua_setfield(L, -2, "SCANCODE_F11");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F12);
    lua_setfield(L, -2, "SCANCODE_F12");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_PRINTSCREEN);
    lua_setfield(L, -2, "SCANCODE_PRINTSCREEN");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_SCROLLLOCK);
    lua_setfield(L, -2, "SCANCODE_SCROLLLOCK");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_PAUSE);
    lua_setfield(L, -2, "SCANCODE_PAUSE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_INSERT);
    lua_setfield(L, -2, "SCANCODE_INSERT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_HOME);
    lua_setfield(L, -2, "SCANCODE_HOME");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_PAGEUP);
    lua_setfield(L, -2, "SCANCODE_PAGEUP");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_DELETE);
    lua_setfield(L, -2, "SCANCODE_DELETE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_END);
    lua_setfield(L, -2, "SCANCODE_END");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_PAGEDOWN);
    lua_setfield(L, -2, "SCANCODE_PAGEDOWN");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_RIGHT);
    lua_setfield(L, -2, "SCANCODE_RIGHT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LEFT);
    lua_setfield(L, -2, "SCANCODE_LEFT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_DOWN);
    lua_setfield(L, -2, "SCANCODE_DOWN");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_UP);
    lua_setfield(L, -2, "SCANCODE_UP");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_NUMLOCKCLEAR);
    lua_setfield(L, -2, "SCANCODE_NUMLOCKCLEAR");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_DIVIDE);
    lua_setfield(L, -2, "SCANCODE_KP_DIVIDE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_MULTIPLY);
    lua_setfield(L, -2, "SCANCODE_KP_MULTIPLY");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_MINUS);
    lua_setfield(L, -2, "SCANCODE_KP_MINUS");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_PLUS);
    lua_setfield(L, -2, "SCANCODE_KP_PLUS");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_ENTER);
    lua_setfield(L, -2, "SCANCODE_KP_ENTER");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_1);
    lua_setfield(L, -2, "SCANCODE_KP_1");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_2);
    lua_setfield(L, -2, "SCANCODE_KP_2");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_3);
    lua_setfield(L, -2, "SCANCODE_KP_3");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_4);
    lua_setfield(L, -2, "SCANCODE_KP_4");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_5);
    lua_setfield(L, -2, "SCANCODE_KP_5");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_6);
    lua_setfield(L, -2, "SCANCODE_KP_6");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_7);
    lua_setfield(L, -2, "SCANCODE_KP_7");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_8);
    lua_setfield(L, -2, "SCANCODE_KP_8");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_9);
    lua_setfield(L, -2, "SCANCODE_KP_9");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_0);
    lua_setfield(L, -2, "SCANCODE_KP_0");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_PERIOD);
    lua_setfield(L, -2, "SCANCODE_KP_PERIOD");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_NONUSBACKSLASH);
    lua_setfield(L, -2, "SCANCODE_NONUSBACKSLASH");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_APPLICATION);
    lua_setfield(L, -2, "SCANCODE_APPLICATION");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_POWER);
    lua_setfield(L, -2, "SCANCODE_POWER");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_EQUALS);
    lua_setfield(L, -2, "SCANCODE_KP_EQUALS");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F13);
    lua_setfield(L, -2, "SCANCODE_F13");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F14);
    lua_setfield(L, -2, "SCANCODE_F14");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F15);
    lua_setfield(L, -2, "SCANCODE_F15");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F16);
    lua_setfield(L, -2, "SCANCODE_F16");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F17);
    lua_setfield(L, -2, "SCANCODE_F17");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F18);
    lua_setfield(L, -2, "SCANCODE_F18");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F19);
    lua_setfield(L, -2, "SCANCODE_F19");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F20);
    lua_setfield(L, -2, "SCANCODE_F20");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F21);
    lua_setfield(L, -2, "SCANCODE_F21");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F22);
    lua_setfield(L, -2, "SCANCODE_F22");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F23);
    lua_setfield(L, -2, "SCANCODE_F23");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_F24);
    lua_setfield(L, -2, "SCANCODE_F24");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_EXECUTE);
    lua_setfield(L, -2, "SCANCODE_EXECUTE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_HELP);
    lua_setfield(L, -2, "SCANCODE_HELP");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MENU);
    lua_setfield(L, -2, "SCANCODE_MENU");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_SELECT);
    lua_setfield(L, -2, "SCANCODE_SELECT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_STOP);
    lua_setfield(L, -2, "SCANCODE_STOP");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AGAIN);
    lua_setfield(L, -2, "SCANCODE_AGAIN");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_UNDO);
    lua_setfield(L, -2, "SCANCODE_UNDO");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_CUT);
    lua_setfield(L, -2, "SCANCODE_CUT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_COPY);
    lua_setfield(L, -2, "SCANCODE_COPY");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_PASTE);
    lua_setfield(L, -2, "SCANCODE_PASTE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_FIND);
    lua_setfield(L, -2, "SCANCODE_FIND");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MUTE);
    lua_setfield(L, -2, "SCANCODE_MUTE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_VOLUMEUP);
    lua_setfield(L, -2, "SCANCODE_VOLUMEUP");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_VOLUMEDOWN);
    lua_setfield(L, -2, "SCANCODE_VOLUMEDOWN");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_COMMA);
    lua_setfield(L, -2, "SCANCODE_KP_COMMA");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_EQUALSAS400);
    lua_setfield(L, -2, "SCANCODE_KP_EQUALSAS400");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_INTERNATIONAL1);
    lua_setfield(L, -2, "SCANCODE_INTERNATIONAL1");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_INTERNATIONAL2);
    lua_setfield(L, -2, "SCANCODE_INTERNATIONAL2");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_INTERNATIONAL3);
    lua_setfield(L, -2, "SCANCODE_INTERNATIONAL3");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_INTERNATIONAL4);
    lua_setfield(L, -2, "SCANCODE_INTERNATIONAL4");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_INTERNATIONAL5);
    lua_setfield(L, -2, "SCANCODE_INTERNATIONAL5");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_INTERNATIONAL6);
    lua_setfield(L, -2, "SCANCODE_INTERNATIONAL6");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_INTERNATIONAL7);
    lua_setfield(L, -2, "SCANCODE_INTERNATIONAL7");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_INTERNATIONAL8);
    lua_setfield(L, -2, "SCANCODE_INTERNATIONAL8");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_INTERNATIONAL9);
    lua_setfield(L, -2, "SCANCODE_INTERNATIONAL9");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LANG1);
    lua_setfield(L, -2, "SCANCODE_LANG1");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LANG2);
    lua_setfield(L, -2, "SCANCODE_LANG2");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LANG3);
    lua_setfield(L, -2, "SCANCODE_LANG3");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LANG4);
    lua_setfield(L, -2, "SCANCODE_LANG4");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LANG5);
    lua_setfield(L, -2, "SCANCODE_LANG5");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LANG6);
    lua_setfield(L, -2, "SCANCODE_LANG6");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LANG7);
    lua_setfield(L, -2, "SCANCODE_LANG7");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LANG8);
    lua_setfield(L, -2, "SCANCODE_LANG8");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LANG9);
    lua_setfield(L, -2, "SCANCODE_LANG9");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_ALTERASE);
    lua_setfield(L, -2, "SCANCODE_ALTERASE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_SYSREQ);
    lua_setfield(L, -2, "SCANCODE_SYSREQ");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_CANCEL);
    lua_setfield(L, -2, "SCANCODE_CANCEL");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_CLEAR);
    lua_setfield(L, -2, "SCANCODE_CLEAR");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_PRIOR);
    lua_setfield(L, -2, "SCANCODE_PRIOR");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_RETURN2);
    lua_setfield(L, -2, "SCANCODE_RETURN2");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_SEPARATOR);
    lua_setfield(L, -2, "SCANCODE_SEPARATOR");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_OUT);
    lua_setfield(L, -2, "SCANCODE_OUT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_OPER);
    lua_setfield(L, -2, "SCANCODE_OPER");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_CLEARAGAIN);
    lua_setfield(L, -2, "SCANCODE_CLEARAGAIN");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_CRSEL);
    lua_setfield(L, -2, "SCANCODE_CRSEL");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_EXSEL);
    lua_setfield(L, -2, "SCANCODE_EXSEL");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_00);
    lua_setfield(L, -2, "SCANCODE_KP_00");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_000);
    lua_setfield(L, -2, "SCANCODE_KP_000");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_THOUSANDSSEPARATOR);
    lua_setfield(L, -2, "SCANCODE_THOUSANDSSEPARATOR");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_DECIMALSEPARATOR);
    lua_setfield(L, -2, "SCANCODE_DECIMALSEPARATOR");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_CURRENCYUNIT);
    lua_setfield(L, -2, "SCANCODE_CURRENCYUNIT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_CURRENCYSUBUNIT);
    lua_setfield(L, -2, "SCANCODE_CURRENCYSUBUNIT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_LEFTPAREN);
    lua_setfield(L, -2, "SCANCODE_KP_LEFTPAREN");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_RIGHTPAREN);
    lua_setfield(L, -2, "SCANCODE_KP_RIGHTPAREN");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_LEFTBRACE);
    lua_setfield(L, -2, "SCANCODE_KP_LEFTBRACE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_RIGHTBRACE);
    lua_setfield(L, -2, "SCANCODE_KP_RIGHTBRACE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_TAB);
    lua_setfield(L, -2, "SCANCODE_KP_TAB");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_BACKSPACE);
    lua_setfield(L, -2, "SCANCODE_KP_BACKSPACE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_A);
    lua_setfield(L, -2, "SCANCODE_KP_A");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_B);
    lua_setfield(L, -2, "SCANCODE_KP_B");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_C);
    lua_setfield(L, -2, "SCANCODE_KP_C");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_D);
    lua_setfield(L, -2, "SCANCODE_KP_D");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_E);
    lua_setfield(L, -2, "SCANCODE_KP_E");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_F);
    lua_setfield(L, -2, "SCANCODE_KP_F");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_XOR);
    lua_setfield(L, -2, "SCANCODE_KP_XOR");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_POWER);
    lua_setfield(L, -2, "SCANCODE_KP_POWER");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_PERCENT);
    lua_setfield(L, -2, "SCANCODE_KP_PERCENT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_LESS);
    lua_setfield(L, -2, "SCANCODE_KP_LESS");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_GREATER);
    lua_setfield(L, -2, "SCANCODE_KP_GREATER");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_AMPERSAND);
    lua_setfield(L, -2, "SCANCODE_KP_AMPERSAND");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_DBLAMPERSAND);
    lua_setfield(L, -2, "SCANCODE_KP_DBLAMPERSAND");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_VERTICALBAR);
    lua_setfield(L, -2, "SCANCODE_KP_VERTICALBAR");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_DBLVERTICALBAR);
    lua_setfield(L, -2, "SCANCODE_KP_DBLVERTICALBAR");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_COLON);
    lua_setfield(L, -2, "SCANCODE_KP_COLON");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_HASH);
    lua_setfield(L, -2, "SCANCODE_KP_HASH");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_SPACE);
    lua_setfield(L, -2, "SCANCODE_KP_SPACE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_AT);
    lua_setfield(L, -2, "SCANCODE_KP_AT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_EXCLAM);
    lua_setfield(L, -2, "SCANCODE_KP_EXCLAM");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_MEMSTORE);
    lua_setfield(L, -2, "SCANCODE_KP_MEMSTORE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_MEMRECALL);
    lua_setfield(L, -2, "SCANCODE_KP_MEMRECALL");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_MEMCLEAR);
    lua_setfield(L, -2, "SCANCODE_KP_MEMCLEAR");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_MEMADD);
    lua_setfield(L, -2, "SCANCODE_KP_MEMADD");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_MEMSUBTRACT);
    lua_setfield(L, -2, "SCANCODE_KP_MEMSUBTRACT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_MEMMULTIPLY);
    lua_setfield(L, -2, "SCANCODE_KP_MEMMULTIPLY");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_MEMDIVIDE);
    lua_setfield(L, -2, "SCANCODE_KP_MEMDIVIDE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_PLUSMINUS);
    lua_setfield(L, -2, "SCANCODE_KP_PLUSMINUS");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_CLEAR);
    lua_setfield(L, -2, "SCANCODE_KP_CLEAR");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_CLEARENTRY);
    lua_setfield(L, -2, "SCANCODE_KP_CLEARENTRY");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_BINARY);
    lua_setfield(L, -2, "SCANCODE_KP_BINARY");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_OCTAL);
    lua_setfield(L, -2, "SCANCODE_KP_OCTAL");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_DECIMAL);
    lua_setfield(L, -2, "SCANCODE_KP_DECIMAL");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_KP_HEXADECIMAL);
    lua_setfield(L, -2, "SCANCODE_KP_HEXADECIMAL");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LCTRL);
    lua_setfield(L, -2, "SCANCODE_LCTRL");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LSHIFT);
    lua_setfield(L, -2, "SCANCODE_LSHIFT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LALT);
    lua_setfield(L, -2, "SCANCODE_LALT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_LGUI);
    lua_setfield(L, -2, "SCANCODE_LGUI");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_RCTRL);
    lua_setfield(L, -2, "SCANCODE_RCTRL");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_RSHIFT);
    lua_setfield(L, -2, "SCANCODE_RSHIFT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_RALT);
    lua_setfield(L, -2, "SCANCODE_RALT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_RGUI);
    lua_setfield(L, -2, "SCANCODE_RGUI");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MODE);
    lua_setfield(L, -2, "SCANCODE_MODE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_SLEEP);
    lua_setfield(L, -2, "SCANCODE_SLEEP");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_WAKE);
    lua_setfield(L, -2, "SCANCODE_WAKE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_CHANNEL_INCREMENT);
    lua_setfield(L, -2, "SCANCODE_CHANNEL_INCREMENT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_CHANNEL_DECREMENT);
    lua_setfield(L, -2, "SCANCODE_CHANNEL_DECREMENT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MEDIA_PLAY);
    lua_setfield(L, -2, "SCANCODE_MEDIA_PLAY");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MEDIA_PAUSE);
    lua_setfield(L, -2, "SCANCODE_MEDIA_PAUSE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MEDIA_RECORD);
    lua_setfield(L, -2, "SCANCODE_MEDIA_RECORD");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MEDIA_FAST_FORWARD);
    lua_setfield(L, -2, "SCANCODE_MEDIA_FAST_FORWARD");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MEDIA_REWIND);
    lua_setfield(L, -2, "SCANCODE_MEDIA_REWIND");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MEDIA_NEXT_TRACK);
    lua_setfield(L, -2, "SCANCODE_MEDIA_NEXT_TRACK");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MEDIA_PREVIOUS_TRACK);
    lua_setfield(L, -2, "SCANCODE_MEDIA_PREVIOUS_TRACK");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MEDIA_STOP);
    lua_setfield(L, -2, "SCANCODE_MEDIA_STOP");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MEDIA_EJECT);
    lua_setfield(L, -2, "SCANCODE_MEDIA_EJECT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MEDIA_PLAY_PAUSE);
    lua_setfield(L, -2, "SCANCODE_MEDIA_PLAY_PAUSE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_MEDIA_SELECT);
    lua_setfield(L, -2, "SCANCODE_MEDIA_SELECT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_NEW);
    lua_setfield(L, -2, "SCANCODE_AC_NEW");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_OPEN);
    lua_setfield(L, -2, "SCANCODE_AC_OPEN");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_CLOSE);
    lua_setfield(L, -2, "SCANCODE_AC_CLOSE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_EXIT);
    lua_setfield(L, -2, "SCANCODE_AC_EXIT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_SAVE);
    lua_setfield(L, -2, "SCANCODE_AC_SAVE");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_PRINT);
    lua_setfield(L, -2, "SCANCODE_AC_PRINT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_PROPERTIES);
    lua_setfield(L, -2, "SCANCODE_AC_PROPERTIES");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_SEARCH);
    lua_setfield(L, -2, "SCANCODE_AC_SEARCH");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_HOME);
    lua_setfield(L, -2, "SCANCODE_AC_HOME");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_BACK);
    lua_setfield(L, -2, "SCANCODE_AC_BACK");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_FORWARD);
    lua_setfield(L, -2, "SCANCODE_AC_FORWARD");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_STOP);
    lua_setfield(L, -2, "SCANCODE_AC_STOP");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_REFRESH);
    lua_setfield(L, -2, "SCANCODE_AC_REFRESH");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_AC_BOOKMARKS);
    lua_setfield(L, -2, "SCANCODE_AC_BOOKMARKS");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_SOFTLEFT);
    lua_setfield(L, -2, "SCANCODE_SOFTLEFT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_SOFTRIGHT);
    lua_setfield(L, -2, "SCANCODE_SOFTRIGHT");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_CALL);
    lua_setfield(L, -2, "SCANCODE_CALL");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_ENDCALL);
    lua_setfield(L, -2, "SCANCODE_ENDCALL");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_RESERVED);
    lua_setfield(L, -2, "SCANCODE_RESERVED");
    lua_pushinteger(L, (lua_Integer)SDL_SCANCODE_COUNT);
    lua_setfield(L, -2, "SCANCODE_COUNT");
    lua_pushinteger(L, (lua_Integer)SDL_SENSOR_INVALID);
    lua_setfield(L, -2, "SENSOR_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_SENSOR_UNKNOWN);
    lua_setfield(L, -2, "SENSOR_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_SENSOR_ACCEL);
    lua_setfield(L, -2, "SENSOR_ACCEL");
    lua_pushinteger(L, (lua_Integer)SDL_SENSOR_GYRO);
    lua_setfield(L, -2, "SENSOR_GYRO");
    lua_pushinteger(L, (lua_Integer)SDL_SENSOR_ACCEL_L);
    lua_setfield(L, -2, "SENSOR_ACCEL_L");
    lua_pushinteger(L, (lua_Integer)SDL_SENSOR_GYRO_L);
    lua_setfield(L, -2, "SENSOR_GYRO_L");
    lua_pushinteger(L, (lua_Integer)SDL_SENSOR_ACCEL_R);
    lua_setfield(L, -2, "SENSOR_ACCEL_R");
    lua_pushinteger(L, (lua_Integer)SDL_SENSOR_GYRO_R);
    lua_setfield(L, -2, "SENSOR_GYRO_R");
    lua_pushinteger(L, (lua_Integer)SDL_SENSOR_COUNT);
    lua_setfield(L, -2, "SENSOR_COUNT");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_DEFAULT);
    lua_setfield(L, -2, "SYSTEM_CURSOR_DEFAULT");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_TEXT);
    lua_setfield(L, -2, "SYSTEM_CURSOR_TEXT");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_WAIT);
    lua_setfield(L, -2, "SYSTEM_CURSOR_WAIT");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_CROSSHAIR);
    lua_setfield(L, -2, "SYSTEM_CURSOR_CROSSHAIR");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_PROGRESS);
    lua_setfield(L, -2, "SYSTEM_CURSOR_PROGRESS");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_NWSE_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_NWSE_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_NESW_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_NESW_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_EW_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_EW_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_NS_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_NS_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_MOVE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_MOVE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_NOT_ALLOWED);
    lua_setfield(L, -2, "SYSTEM_CURSOR_NOT_ALLOWED");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_POINTER);
    lua_setfield(L, -2, "SYSTEM_CURSOR_POINTER");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_NW_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_NW_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_N_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_N_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_NE_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_NE_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_E_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_E_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_SE_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_SE_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_S_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_S_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_SW_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_SW_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_W_RESIZE);
    lua_setfield(L, -2, "SYSTEM_CURSOR_W_RESIZE");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_CURSOR_COUNT);
    lua_setfield(L, -2, "SYSTEM_CURSOR_COUNT");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_THEME_UNKNOWN);
    lua_setfield(L, -2, "SYSTEM_THEME_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_THEME_LIGHT);
    lua_setfield(L, -2, "SYSTEM_THEME_LIGHT");
    lua_pushinteger(L, (lua_Integer)SDL_SYSTEM_THEME_DARK);
    lua_setfield(L, -2, "SYSTEM_THEME_DARK");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTINPUT_TYPE_TEXT);
    lua_setfield(L, -2, "TEXTINPUT_TYPE_TEXT");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTINPUT_TYPE_TEXT_NAME);
    lua_setfield(L, -2, "TEXTINPUT_TYPE_TEXT_NAME");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTINPUT_TYPE_TEXT_EMAIL);
    lua_setfield(L, -2, "TEXTINPUT_TYPE_TEXT_EMAIL");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTINPUT_TYPE_TEXT_USERNAME);
    lua_setfield(L, -2, "TEXTINPUT_TYPE_TEXT_USERNAME");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTINPUT_TYPE_TEXT_PASSWORD_HIDDEN);
    lua_setfield(L, -2, "TEXTINPUT_TYPE_TEXT_PASSWORD_HIDDEN");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTINPUT_TYPE_TEXT_PASSWORD_VISIBLE);
    lua_setfield(L, -2, "TEXTINPUT_TYPE_TEXT_PASSWORD_VISIBLE");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTINPUT_TYPE_NUMBER);
    lua_setfield(L, -2, "TEXTINPUT_TYPE_NUMBER");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTINPUT_TYPE_NUMBER_PASSWORD_HIDDEN);
    lua_setfield(L, -2, "TEXTINPUT_TYPE_NUMBER_PASSWORD_HIDDEN");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTINPUT_TYPE_NUMBER_PASSWORD_VISIBLE);
    lua_setfield(L, -2, "TEXTINPUT_TYPE_NUMBER_PASSWORD_VISIBLE");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTUREACCESS_STATIC);
    lua_setfield(L, -2, "TEXTUREACCESS_STATIC");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTUREACCESS_STREAMING);
    lua_setfield(L, -2, "TEXTUREACCESS_STREAMING");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTUREACCESS_TARGET);
    lua_setfield(L, -2, "TEXTUREACCESS_TARGET");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTURE_ADDRESS_INVALID);
    lua_setfield(L, -2, "TEXTURE_ADDRESS_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTURE_ADDRESS_AUTO);
    lua_setfield(L, -2, "TEXTURE_ADDRESS_AUTO");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTURE_ADDRESS_CLAMP);
    lua_setfield(L, -2, "TEXTURE_ADDRESS_CLAMP");
    lua_pushinteger(L, (lua_Integer)SDL_TEXTURE_ADDRESS_WRAP);
    lua_setfield(L, -2, "TEXTURE_ADDRESS_WRAP");
    lua_pushinteger(L, (lua_Integer)SDL_THREAD_PRIORITY_LOW);
    lua_setfield(L, -2, "THREAD_PRIORITY_LOW");
    lua_pushinteger(L, (lua_Integer)SDL_THREAD_PRIORITY_NORMAL);
    lua_setfield(L, -2, "THREAD_PRIORITY_NORMAL");
    lua_pushinteger(L, (lua_Integer)SDL_THREAD_PRIORITY_HIGH);
    lua_setfield(L, -2, "THREAD_PRIORITY_HIGH");
    lua_pushinteger(L, (lua_Integer)SDL_THREAD_PRIORITY_TIME_CRITICAL);
    lua_setfield(L, -2, "THREAD_PRIORITY_TIME_CRITICAL");
    lua_pushinteger(L, (lua_Integer)SDL_THREAD_UNKNOWN);
    lua_setfield(L, -2, "THREAD_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_THREAD_ALIVE);
    lua_setfield(L, -2, "THREAD_ALIVE");
    lua_pushinteger(L, (lua_Integer)SDL_THREAD_DETACHED);
    lua_setfield(L, -2, "THREAD_DETACHED");
    lua_pushinteger(L, (lua_Integer)SDL_THREAD_COMPLETE);
    lua_setfield(L, -2, "THREAD_COMPLETE");
    lua_pushinteger(L, (lua_Integer)SDL_TIME_FORMAT_24HR);
    lua_setfield(L, -2, "TIME_FORMAT_24HR");
    lua_pushinteger(L, (lua_Integer)SDL_TIME_FORMAT_12HR);
    lua_setfield(L, -2, "TIME_FORMAT_12HR");
    lua_pushinteger(L, (lua_Integer)SDL_TOUCH_DEVICE_INVALID);
    lua_setfield(L, -2, "TOUCH_DEVICE_INVALID");
    lua_pushinteger(L, (lua_Integer)SDL_TOUCH_DEVICE_DIRECT);
    lua_setfield(L, -2, "TOUCH_DEVICE_DIRECT");
    lua_pushinteger(L, (lua_Integer)SDL_TOUCH_DEVICE_INDIRECT_ABSOLUTE);
    lua_setfield(L, -2, "TOUCH_DEVICE_INDIRECT_ABSOLUTE");
    lua_pushinteger(L, (lua_Integer)SDL_TOUCH_DEVICE_INDIRECT_RELATIVE);
    lua_setfield(L, -2, "TOUCH_DEVICE_INDIRECT_RELATIVE");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_UNKNOWN);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_BT709);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_BT709");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_UNSPECIFIED);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_UNSPECIFIED");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_GAMMA22);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_GAMMA22");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_GAMMA28);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_GAMMA28");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_BT601);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_BT601");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_SMPTE240);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_SMPTE240");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_LINEAR);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_LINEAR");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_LOG100);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_LOG100");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_LOG100_SQRT10);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_LOG100_SQRT10");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_IEC61966);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_IEC61966");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_BT1361);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_BT1361");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_SRGB);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_SRGB");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_BT2020_10BIT);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_BT2020_10BIT");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_BT2020_12BIT);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_BT2020_12BIT");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_PQ);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_PQ");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_SMPTE428);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_SMPTE428");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_HLG);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_HLG");
    lua_pushinteger(L, (lua_Integer)SDL_TRANSFER_CHARACTERISTICS_CUSTOM);
    lua_setfield(L, -2, "TRANSFER_CHARACTERISTICS_CUSTOM");
    lua_pushinteger(L, (lua_Integer)SDL_HID_API_BUS_UNKNOWN);
    lua_setfield(L, -2, "HID_API_BUS_UNKNOWN");
    lua_pushinteger(L, (lua_Integer)SDL_HID_API_BUS_USB);
    lua_setfield(L, -2, "HID_API_BUS_USB");
    lua_pushinteger(L, (lua_Integer)SDL_HID_API_BUS_BLUETOOTH);
    lua_setfield(L, -2, "HID_API_BUS_BLUETOOTH");
    lua_pushinteger(L, (lua_Integer)SDL_HID_API_BUS_I2C);
    lua_setfield(L, -2, "HID_API_BUS_I2C");
    lua_pushinteger(L, (lua_Integer)SDL_HID_API_BUS_SPI);
    lua_setfield(L, -2, "HID_API_BUS_SPI");
    lua_setglobal(L, "SDL");
    return 0;
}
