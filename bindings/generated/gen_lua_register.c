/* GENERATED FILE - DO NOT EDIT. Aggregate Lua registration. */
#include "../src/gen_support_lua.h"

extern int SDLStaticGen_OpenLua_sdl(lua_State *L);
extern int SDLStaticGen_OpenLua_mix(lua_State *L);
extern int SDLStaticGen_OpenLua_img(lua_State *L);
extern int SDLStaticGen_OpenLua_ttf(lua_State *L);
extern int SDLStaticGen_OpenLua_net(lua_State *L);
extern int SDLStaticGen_OpenLua_physfs(lua_State *L);
extern int SDLStaticGen_OpenLua_b2(lua_State *L);
extern int SDLStaticGen_OpenLua_nk(lua_State *L);
extern int SDLStaticGen_OpenLua_cjson(lua_State *L);
extern int SDLStaticGen_OpenLua_sdlstatic(lua_State *L);

int SDLStatic_OpenGeneratedLuaBindings(lua_State *L);
int SDLStatic_OpenGeneratedLuaBindings(lua_State *L)
{
    SDLStaticGen_OpenLua_sdl(L);
    SDLStaticGen_OpenLua_mix(L);
    SDLStaticGen_OpenLua_img(L);
    SDLStaticGen_OpenLua_ttf(L);
    SDLStaticGen_OpenLua_net(L);
    SDLStaticGen_OpenLua_physfs(L);
    SDLStaticGen_OpenLua_b2(L);
    SDLStaticGen_OpenLua_nk(L);
    SDLStaticGen_OpenLua_cjson(L);
    SDLStaticGen_OpenLua_sdlstatic(L);
    return 0;
}
