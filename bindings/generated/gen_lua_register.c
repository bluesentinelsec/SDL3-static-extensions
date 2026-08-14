/* GENERATED FILE - DO NOT EDIT. Aggregate Lua registration.
 * SDLSTATIC_GEN_DISABLE_<LIB> gates modules whose CMake option is
 * off on this platform (e.g. NET on Emscripten). */
#include "../src/gen_support_lua.h"

#ifndef SDLSTATIC_GEN_DISABLE_SDL
extern int SDLStaticGen_OpenLua_sdl(lua_State *L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_MIX
extern int SDLStaticGen_OpenLua_mix(lua_State *L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_IMG
extern int SDLStaticGen_OpenLua_img(lua_State *L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_TTF
extern int SDLStaticGen_OpenLua_ttf(lua_State *L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_NET
extern int SDLStaticGen_OpenLua_net(lua_State *L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_PHYSFS
extern int SDLStaticGen_OpenLua_physfs(lua_State *L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_B2
extern int SDLStaticGen_OpenLua_b2(lua_State *L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_NK
extern int SDLStaticGen_OpenLua_nk(lua_State *L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_CJSON
extern int SDLStaticGen_OpenLua_cjson(lua_State *L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_SDLSTATIC
extern int SDLStaticGen_OpenLua_sdlstatic(lua_State *L);
#endif

int SDLStatic_OpenGeneratedLuaBindings(lua_State *L);
int SDLStatic_OpenGeneratedLuaBindings(lua_State *L)
{
#ifndef SDLSTATIC_GEN_DISABLE_SDL
    SDLStaticGen_OpenLua_sdl(L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_MIX
    SDLStaticGen_OpenLua_mix(L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_IMG
    SDLStaticGen_OpenLua_img(L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_TTF
    SDLStaticGen_OpenLua_ttf(L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_NET
    SDLStaticGen_OpenLua_net(L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_PHYSFS
    SDLStaticGen_OpenLua_physfs(L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_B2
    SDLStaticGen_OpenLua_b2(L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_NK
    SDLStaticGen_OpenLua_nk(L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_CJSON
    SDLStaticGen_OpenLua_cjson(L);
#endif
#ifndef SDLSTATIC_GEN_DISABLE_SDLSTATIC
    SDLStaticGen_OpenLua_sdlstatic(L);
#endif
    return 0;
}
