/*
 * gen_support_lua.c — marshaling runtime for the generated Lua bindings.
 * Original SDLStatic code (zlib). See gen_support_lua.h for the model.
 */
#include "gen_support_lua.h"

#include <string.h>

#define GEN_MT "SDLStaticGen.Handle"

static int GenHandleGc(lua_State *L)
{
    SDLStaticGen_Handle *h = (SDLStaticGen_Handle *)luaL_checkudata(L, 1, GEN_MT);
    if (h->ptr != NULL && h->dtor != NULL)
    {
        h->dtor(h->ptr);
    }
    h->ptr = NULL;
    h->dtor = NULL;
    return 0;
}

static int GenHandleTostring(lua_State *L)
{
    SDLStaticGen_Handle *h = (SDLStaticGen_Handle *)luaL_checkudata(L, 1, GEN_MT);
    lua_pushfstring(L, "%s: %p%s", h->ctype, h->ptr,
                    h->dtor != NULL ? " (owned)" : "");
    return 1;
}

static void GenEnsureMetatable(lua_State *L)
{
    if (luaL_newmetatable(L, GEN_MT))
    {
        lua_pushcfunction(L, GenHandleGc);
        lua_setfield(L, -2, "__gc");
        lua_pushcfunction(L, GenHandleTostring);
        lua_setfield(L, -2, "__tostring");
    }
    lua_pop(L, 1);
}

static void GenPush(lua_State *L, void *ptr, const char *ctype, SDLStaticGen_Dtor dtor)
{
    SDLStaticGen_Handle *h;
    if (ptr == NULL)
    {
        lua_pushnil(L);
        return;
    }
    GenEnsureMetatable(L);
    h = (SDLStaticGen_Handle *)lua_newuserdatauv(L, sizeof(SDLStaticGen_Handle), 0);
    h->ptr = ptr;
    h->ctype = ctype;
    h->dtor = dtor;
    luaL_setmetatable(L, GEN_MT);
}

void SDLStaticGen_LuaPushHandle(lua_State *L, void *ptr, const char *ctype)
{
    GenPush(L, ptr, ctype, NULL);
}

void SDLStaticGen_LuaPushOwned(lua_State *L, void *ptr, const char *ctype,
                               SDLStaticGen_Dtor dtor)
{
    GenPush(L, ptr, ctype, dtor);
}

static SDLStaticGen_Handle *GenCheck(lua_State *L, int idx, const char *ctype)
{
    SDLStaticGen_Handle *h = (SDLStaticGen_Handle *)luaL_checkudata(L, idx, GEN_MT);
    if (strcmp(h->ctype, ctype) != 0)
    {
        luaL_error(L, "expected %s, got %s", ctype, h->ctype);
        return NULL; /* unreachable */
    }
    return h;
}

void *SDLStaticGen_LuaCheckHandle(lua_State *L, int idx, const char *ctype)
{
    if (lua_isnoneornil(L, idx))
    {
        return NULL;
    }
    return GenCheck(L, idx, ctype)->ptr;
}

void *SDLStaticGen_LuaTakeHandle(lua_State *L, int idx, const char *ctype)
{
    SDLStaticGen_Handle *h;
    if (lua_isnoneornil(L, idx))
    {
        return NULL;
    }
    h = GenCheck(L, idx, ctype);
    {
        void *ptr = h->ptr;
        h->ptr = NULL;
        h->dtor = NULL;
        return ptr;
    }
}

lua_Integer SDLStaticGen_LuaFieldInt(lua_State *L, int idx, const char *field)
{
    lua_Integer out;
    lua_getfield(L, idx, field);
    out = (lua_Integer)lua_tointeger(L, -1);
    lua_pop(L, 1);
    return out;
}

lua_Number SDLStaticGen_LuaFieldNum(lua_State *L, int idx, const char *field)
{
    lua_Number out;
    lua_getfield(L, idx, field);
    out = lua_tonumber(L, -1);
    lua_pop(L, 1);
    return out;
}

int SDLStaticGen_LuaFieldBool(lua_State *L, int idx, const char *field)
{
    int out;
    lua_getfield(L, idx, field);
    out = lua_toboolean(L, -1);
    lua_pop(L, 1);
    return out;
}
