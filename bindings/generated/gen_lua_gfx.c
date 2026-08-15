/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for SDL3_gfx. */
#include "../src/gen_support_lua.h"

#include <SDL3_gfx/SDL3_gfxPrimitives.h>
#include <SDL3_gfx/SDL3_rotozoom.h>
#include <SDL3_gfx/SDL3_framerate.h>
#include <string.h>

static void GenPush_FPSmanager(lua_State *L, const FPSmanager *in)
{
    lua_createtable(L, 0, 5);
    lua_pushinteger(L, (lua_Integer)in->framecount);
    lua_setfield(L, -2, "framecount");
    lua_pushnumber(L, (lua_Number)in->rateticks);
    lua_setfield(L, -2, "rateticks");
    lua_pushinteger(L, (lua_Integer)in->baseticks);
    lua_setfield(L, -2, "baseticks");
    lua_pushinteger(L, (lua_Integer)in->lastticks);
    lua_setfield(L, -2, "lastticks");
    lua_pushinteger(L, (lua_Integer)in->rate);
    lua_setfield(L, -2, "rate");
}

static void GenDtor_SDL_DestroySurface(void *p)
{
    SDL_Surface *typed = (SDL_Surface *)p;
    SDL_DestroySurface(typed);
}

static int GenL_SDL_framerateDelay(lua_State *L)
{
    (void)L;
    FPSmanager out0;
    memset(&out0, 0, sizeof(out0));
    Uint64 rv = SDL_framerateDelay(&out0);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_FPSmanager(L, &out0);
    return 2;
}

static int GenL_SDL_getFramecount(lua_State *L)
{
    (void)L;
    FPSmanager out0;
    memset(&out0, 0, sizeof(out0));
    int rv = SDL_getFramecount(&out0);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_FPSmanager(L, &out0);
    return 2;
}

static int GenL_SDL_getFramerate(lua_State *L)
{
    (void)L;
    FPSmanager out0;
    memset(&out0, 0, sizeof(out0));
    int rv = SDL_getFramerate(&out0);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_FPSmanager(L, &out0);
    return 2;
}

static int GenL_SDL_initFramerate(lua_State *L)
{
    (void)L;
    FPSmanager out0;
    memset(&out0, 0, sizeof(out0));
    SDL_initFramerate(&out0);
    GenPush_FPSmanager(L, &out0);
    return 1;
}

static int GenL_SDL_setFramerate(lua_State *L)
{
    (void)L;
    FPSmanager out0;
    memset(&out0, 0, sizeof(out0));
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 1);
    int rv = SDL_setFramerate(&out0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_FPSmanager(L, &out0);
    return 2;
}

static int GenL_aacircleColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    bool rv = aacircleColor(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_aacircleRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    bool rv = aacircleRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_aaellipseColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint32 a5 = (Uint32)luaL_checkinteger(L, 6);
    bool rv = aaellipseColor(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_aaellipseRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    bool rv = aaellipseRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_aalineColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint32 a5 = (Uint32)luaL_checkinteger(L, 6);
    bool rv = aalineColor(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_aalineRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    bool rv = aalineRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_aatrigonColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Sint16 a6 = (Sint16)luaL_checkinteger(L, 7);
    Uint32 a7 = (Uint32)luaL_checkinteger(L, 8);
    bool rv = aatrigonColor(a0, a1, a2, a3, a4, a5, a6, a7);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_aatrigonRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Sint16 a6 = (Sint16)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    Uint8 a9 = (Uint8)luaL_checkinteger(L, 10);
    Uint8 a10 = (Uint8)luaL_checkinteger(L, 11);
    bool rv = aatrigonRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_arcColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Uint32 a6 = (Uint32)luaL_checkinteger(L, 7);
    bool rv = arcColor(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_arcRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    Uint8 a9 = (Uint8)luaL_checkinteger(L, 10);
    bool rv = arcRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_boxColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint32 a5 = (Uint32)luaL_checkinteger(L, 6);
    bool rv = boxColor(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_boxRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    bool rv = boxRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_characterColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    char a3 = (char)luaL_checkinteger(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    bool rv = characterColor(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_characterRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    char a3 = (char)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    bool rv = characterRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_circleColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    bool rv = circleColor(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_circleRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    bool rv = circleRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_ellipseColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint32 a5 = (Uint32)luaL_checkinteger(L, 6);
    bool rv = ellipseColor(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_ellipseRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    bool rv = ellipseRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_filledCircleColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    bool rv = filledCircleColor(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_filledCircleRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    bool rv = filledCircleRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_filledEllipseColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint32 a5 = (Uint32)luaL_checkinteger(L, 6);
    bool rv = filledEllipseColor(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_filledEllipseRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    bool rv = filledEllipseRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_filledPieColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Uint32 a6 = (Uint32)luaL_checkinteger(L, 7);
    bool rv = filledPieColor(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_filledPieRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    Uint8 a9 = (Uint8)luaL_checkinteger(L, 10);
    bool rv = filledPieRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_filledTrigonColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Sint16 a6 = (Sint16)luaL_checkinteger(L, 7);
    Uint32 a7 = (Uint32)luaL_checkinteger(L, 8);
    bool rv = filledTrigonColor(a0, a1, a2, a3, a4, a5, a6, a7);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_filledTrigonRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Sint16 a6 = (Sint16)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    Uint8 a9 = (Uint8)luaL_checkinteger(L, 10);
    Uint8 a10 = (Uint8)luaL_checkinteger(L, 11);
    bool rv = filledTrigonRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_gfxPrimitivesSetFontRotation(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    gfxPrimitivesSetFontRotation(a0);
    return 0;
}

static int GenL_hlineColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    bool rv = hlineColor(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_hlineRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    bool rv = hlineRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_lineColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint32 a5 = (Uint32)luaL_checkinteger(L, 6);
    bool rv = lineColor(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_lineRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    bool rv = lineRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_pieColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Uint32 a6 = (Uint32)luaL_checkinteger(L, 7);
    bool rv = pieColor(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_pieRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    Uint8 a9 = (Uint8)luaL_checkinteger(L, 10);
    bool rv = pieRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_pixelColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Uint32 a3 = (Uint32)luaL_checkinteger(L, 4);
    bool rv = pixelColor(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_pixelRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    bool rv = pixelRGBA(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_rectangleColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint32 a5 = (Uint32)luaL_checkinteger(L, 6);
    bool rv = rectangleColor(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_rectangleRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    bool rv = rectangleRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_rotateSurface90Degrees(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDL_Surface * rv = rotateSurface90Degrees(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_rotozoomSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    double a1 = (double)luaL_checknumber(L, 2);
    double a2 = (double)luaL_checknumber(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    SDL_Surface * rv = rotozoomSurface(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_rotozoomSurfaceSize(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    double a2 = (double)luaL_checknumber(L, 3);
    double a3 = (double)luaL_checknumber(L, 4);
    int io4 = (int)luaL_optinteger(L, 5, 0);
    int io5 = (int)luaL_optinteger(L, 6, 0);
    rotozoomSurfaceSize(a0, a1, a2, a3, &io4, &io5);
    lua_pushinteger(L, (lua_Integer)io4);
    lua_pushinteger(L, (lua_Integer)io5);
    return 2;
}

static int GenL_rotozoomSurfaceSizeXY(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    double a2 = (double)luaL_checknumber(L, 3);
    double a3 = (double)luaL_checknumber(L, 4);
    double a4 = (double)luaL_checknumber(L, 5);
    int io5 = (int)luaL_optinteger(L, 6, 0);
    int io6 = (int)luaL_optinteger(L, 7, 0);
    rotozoomSurfaceSizeXY(a0, a1, a2, a3, a4, &io5, &io6);
    lua_pushinteger(L, (lua_Integer)io5);
    lua_pushinteger(L, (lua_Integer)io6);
    return 2;
}

static int GenL_rotozoomSurfaceXY(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    double a1 = (double)luaL_checknumber(L, 2);
    double a2 = (double)luaL_checknumber(L, 3);
    double a3 = (double)luaL_checknumber(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    SDL_Surface * rv = rotozoomSurfaceXY(a0, a1, a2, a3, a4);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_roundedBoxColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Uint32 a6 = (Uint32)luaL_checkinteger(L, 7);
    bool rv = roundedBoxColor(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_roundedBoxRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    Uint8 a9 = (Uint8)luaL_checkinteger(L, 10);
    bool rv = roundedBoxRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_roundedRectangleColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Uint32 a6 = (Uint32)luaL_checkinteger(L, 7);
    bool rv = roundedRectangleColor(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_roundedRectangleRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    Uint8 a9 = (Uint8)luaL_checkinteger(L, 10);
    bool rv = roundedRectangleRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_shrinkSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDL_Surface * rv = shrinkSurface(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_stringColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    bool rv = stringColor(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_stringRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    bool rv = stringRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_thickLineColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint32 a6 = (Uint32)luaL_checkinteger(L, 7);
    bool rv = thickLineColor(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_thickLineRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    Uint8 a9 = (Uint8)luaL_checkinteger(L, 10);
    bool rv = thickLineRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_trigonColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Sint16 a6 = (Sint16)luaL_checkinteger(L, 7);
    Uint32 a7 = (Uint32)luaL_checkinteger(L, 8);
    bool rv = trigonColor(a0, a1, a2, a3, a4, a5, a6, a7);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_trigonRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Sint16 a4 = (Sint16)luaL_checkinteger(L, 5);
    Sint16 a5 = (Sint16)luaL_checkinteger(L, 6);
    Sint16 a6 = (Sint16)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    Uint8 a8 = (Uint8)luaL_checkinteger(L, 9);
    Uint8 a9 = (Uint8)luaL_checkinteger(L, 10);
    Uint8 a10 = (Uint8)luaL_checkinteger(L, 11);
    bool rv = trigonRGBA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_vlineColor(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    bool rv = vlineColor(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_vlineRGBA(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    Sint16 a1 = (Sint16)luaL_checkinteger(L, 2);
    Sint16 a2 = (Sint16)luaL_checkinteger(L, 3);
    Sint16 a3 = (Sint16)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    Uint8 a5 = (Uint8)luaL_checkinteger(L, 6);
    Uint8 a6 = (Uint8)luaL_checkinteger(L, 7);
    Uint8 a7 = (Uint8)luaL_checkinteger(L, 8);
    bool rv = vlineRGBA(a0, a1, a2, a3, a4, a5, a6, a7);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_zoomSurface(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    double a1 = (double)luaL_checknumber(L, 2);
    double a2 = (double)luaL_checknumber(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    SDL_Surface * rv = zoomSurface(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_zoomSurfaceSize(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    double a2 = (double)luaL_checknumber(L, 3);
    double a3 = (double)luaL_checknumber(L, 4);
    int io4 = (int)luaL_optinteger(L, 5, 0);
    int io5 = (int)luaL_optinteger(L, 6, 0);
    zoomSurfaceSize(a0, a1, a2, a3, &io4, &io5);
    lua_pushinteger(L, (lua_Integer)io4);
    lua_pushinteger(L, (lua_Integer)io5);
    return 2;
}

int SDLStaticGen_OpenLua_gfx(lua_State *L);
int SDLStaticGen_OpenLua_gfx(lua_State *L)
{
    lua_createtable(L, 0, 62);
    lua_pushcfunction(L, GenL_SDL_framerateDelay);
    lua_setfield(L, -2, "SDL_framerateDelay");
    lua_pushcfunction(L, GenL_SDL_getFramecount);
    lua_setfield(L, -2, "SDL_getFramecount");
    lua_pushcfunction(L, GenL_SDL_getFramerate);
    lua_setfield(L, -2, "SDL_getFramerate");
    lua_pushcfunction(L, GenL_SDL_initFramerate);
    lua_setfield(L, -2, "SDL_initFramerate");
    lua_pushcfunction(L, GenL_SDL_setFramerate);
    lua_setfield(L, -2, "SDL_setFramerate");
    lua_pushcfunction(L, GenL_aacircleColor);
    lua_setfield(L, -2, "aacircleColor");
    lua_pushcfunction(L, GenL_aacircleRGBA);
    lua_setfield(L, -2, "aacircleRGBA");
    lua_pushcfunction(L, GenL_aaellipseColor);
    lua_setfield(L, -2, "aaellipseColor");
    lua_pushcfunction(L, GenL_aaellipseRGBA);
    lua_setfield(L, -2, "aaellipseRGBA");
    lua_pushcfunction(L, GenL_aalineColor);
    lua_setfield(L, -2, "aalineColor");
    lua_pushcfunction(L, GenL_aalineRGBA);
    lua_setfield(L, -2, "aalineRGBA");
    lua_pushcfunction(L, GenL_aatrigonColor);
    lua_setfield(L, -2, "aatrigonColor");
    lua_pushcfunction(L, GenL_aatrigonRGBA);
    lua_setfield(L, -2, "aatrigonRGBA");
    lua_pushcfunction(L, GenL_arcColor);
    lua_setfield(L, -2, "arcColor");
    lua_pushcfunction(L, GenL_arcRGBA);
    lua_setfield(L, -2, "arcRGBA");
    lua_pushcfunction(L, GenL_boxColor);
    lua_setfield(L, -2, "boxColor");
    lua_pushcfunction(L, GenL_boxRGBA);
    lua_setfield(L, -2, "boxRGBA");
    lua_pushcfunction(L, GenL_characterColor);
    lua_setfield(L, -2, "characterColor");
    lua_pushcfunction(L, GenL_characterRGBA);
    lua_setfield(L, -2, "characterRGBA");
    lua_pushcfunction(L, GenL_circleColor);
    lua_setfield(L, -2, "circleColor");
    lua_pushcfunction(L, GenL_circleRGBA);
    lua_setfield(L, -2, "circleRGBA");
    lua_pushcfunction(L, GenL_ellipseColor);
    lua_setfield(L, -2, "ellipseColor");
    lua_pushcfunction(L, GenL_ellipseRGBA);
    lua_setfield(L, -2, "ellipseRGBA");
    lua_pushcfunction(L, GenL_filledCircleColor);
    lua_setfield(L, -2, "filledCircleColor");
    lua_pushcfunction(L, GenL_filledCircleRGBA);
    lua_setfield(L, -2, "filledCircleRGBA");
    lua_pushcfunction(L, GenL_filledEllipseColor);
    lua_setfield(L, -2, "filledEllipseColor");
    lua_pushcfunction(L, GenL_filledEllipseRGBA);
    lua_setfield(L, -2, "filledEllipseRGBA");
    lua_pushcfunction(L, GenL_filledPieColor);
    lua_setfield(L, -2, "filledPieColor");
    lua_pushcfunction(L, GenL_filledPieRGBA);
    lua_setfield(L, -2, "filledPieRGBA");
    lua_pushcfunction(L, GenL_filledTrigonColor);
    lua_setfield(L, -2, "filledTrigonColor");
    lua_pushcfunction(L, GenL_filledTrigonRGBA);
    lua_setfield(L, -2, "filledTrigonRGBA");
    lua_pushcfunction(L, GenL_gfxPrimitivesSetFontRotation);
    lua_setfield(L, -2, "gfxPrimitivesSetFontRotation");
    lua_pushcfunction(L, GenL_hlineColor);
    lua_setfield(L, -2, "hlineColor");
    lua_pushcfunction(L, GenL_hlineRGBA);
    lua_setfield(L, -2, "hlineRGBA");
    lua_pushcfunction(L, GenL_lineColor);
    lua_setfield(L, -2, "lineColor");
    lua_pushcfunction(L, GenL_lineRGBA);
    lua_setfield(L, -2, "lineRGBA");
    lua_pushcfunction(L, GenL_pieColor);
    lua_setfield(L, -2, "pieColor");
    lua_pushcfunction(L, GenL_pieRGBA);
    lua_setfield(L, -2, "pieRGBA");
    lua_pushcfunction(L, GenL_pixelColor);
    lua_setfield(L, -2, "pixelColor");
    lua_pushcfunction(L, GenL_pixelRGBA);
    lua_setfield(L, -2, "pixelRGBA");
    lua_pushcfunction(L, GenL_rectangleColor);
    lua_setfield(L, -2, "rectangleColor");
    lua_pushcfunction(L, GenL_rectangleRGBA);
    lua_setfield(L, -2, "rectangleRGBA");
    lua_pushcfunction(L, GenL_rotateSurface90Degrees);
    lua_setfield(L, -2, "rotateSurface90Degrees");
    lua_pushcfunction(L, GenL_rotozoomSurface);
    lua_setfield(L, -2, "rotozoomSurface");
    lua_pushcfunction(L, GenL_rotozoomSurfaceSize);
    lua_setfield(L, -2, "rotozoomSurfaceSize");
    lua_pushcfunction(L, GenL_rotozoomSurfaceSizeXY);
    lua_setfield(L, -2, "rotozoomSurfaceSizeXY");
    lua_pushcfunction(L, GenL_rotozoomSurfaceXY);
    lua_setfield(L, -2, "rotozoomSurfaceXY");
    lua_pushcfunction(L, GenL_roundedBoxColor);
    lua_setfield(L, -2, "roundedBoxColor");
    lua_pushcfunction(L, GenL_roundedBoxRGBA);
    lua_setfield(L, -2, "roundedBoxRGBA");
    lua_pushcfunction(L, GenL_roundedRectangleColor);
    lua_setfield(L, -2, "roundedRectangleColor");
    lua_pushcfunction(L, GenL_roundedRectangleRGBA);
    lua_setfield(L, -2, "roundedRectangleRGBA");
    lua_pushcfunction(L, GenL_shrinkSurface);
    lua_setfield(L, -2, "shrinkSurface");
    lua_pushcfunction(L, GenL_stringColor);
    lua_setfield(L, -2, "stringColor");
    lua_pushcfunction(L, GenL_stringRGBA);
    lua_setfield(L, -2, "stringRGBA");
    lua_pushcfunction(L, GenL_thickLineColor);
    lua_setfield(L, -2, "thickLineColor");
    lua_pushcfunction(L, GenL_thickLineRGBA);
    lua_setfield(L, -2, "thickLineRGBA");
    lua_pushcfunction(L, GenL_trigonColor);
    lua_setfield(L, -2, "trigonColor");
    lua_pushcfunction(L, GenL_trigonRGBA);
    lua_setfield(L, -2, "trigonRGBA");
    lua_pushcfunction(L, GenL_vlineColor);
    lua_setfield(L, -2, "vlineColor");
    lua_pushcfunction(L, GenL_vlineRGBA);
    lua_setfield(L, -2, "vlineRGBA");
    lua_pushcfunction(L, GenL_zoomSurface);
    lua_setfield(L, -2, "zoomSurface");
    lua_pushcfunction(L, GenL_zoomSurfaceSize);
    lua_setfield(L, -2, "zoomSurfaceSize");
#ifdef FPS_UPPER_LIMIT
    lua_pushinteger(L, (lua_Integer)(FPS_UPPER_LIMIT));
    lua_setfield(L, -2, "FPS_UPPER_LIMIT");
#endif
#ifdef FPS_LOWER_LIMIT
    lua_pushinteger(L, (lua_Integer)(FPS_LOWER_LIMIT));
    lua_setfield(L, -2, "FPS_LOWER_LIMIT");
#endif
#ifdef FPS_DEFAULT
    lua_pushinteger(L, (lua_Integer)(FPS_DEFAULT));
    lua_setfield(L, -2, "FPS_DEFAULT");
#endif
#ifdef SDL3_GFXPRIMITIVES_MAJOR
    lua_pushinteger(L, (lua_Integer)(SDL3_GFXPRIMITIVES_MAJOR));
    lua_setfield(L, -2, "SDL3_GFXPRIMITIVES_MAJOR");
#endif
#ifdef SDL3_GFXPRIMITIVES_MINOR
    lua_pushinteger(L, (lua_Integer)(SDL3_GFXPRIMITIVES_MINOR));
    lua_setfield(L, -2, "SDL3_GFXPRIMITIVES_MINOR");
#endif
#ifdef SDL3_GFXPRIMITIVES_MICRO
    lua_pushinteger(L, (lua_Integer)(SDL3_GFXPRIMITIVES_MICRO));
    lua_setfield(L, -2, "SDL3_GFXPRIMITIVES_MICRO");
#endif
#ifdef SMOOTHING_OFF
    lua_pushinteger(L, (lua_Integer)(SMOOTHING_OFF));
    lua_setfield(L, -2, "SMOOTHING_OFF");
#endif
#ifdef SMOOTHING_ON
    lua_pushinteger(L, (lua_Integer)(SMOOTHING_ON));
    lua_setfield(L, -2, "SMOOTHING_ON");
#endif
    lua_setglobal(L, "GFX");
    return 0;
}
