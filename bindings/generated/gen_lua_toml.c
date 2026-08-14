/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for tomlc99. */
#include "../src/gen_support_lua.h"

#include <toml.h>
#include <string.h>

static void GenDtor_toml_free(void *p)
{
    toml_table_t *typed = (toml_table_t *)p;
    toml_free(typed);
}

static int GenL_toml_array_at(lua_State *L)
{
    (void)L;
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_array_t");
    int a1 = (int)luaL_checkinteger(L, 2);
    toml_array_t * rv = toml_array_at(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "toml_array_t");
    return 1;
}

static int GenL_toml_array_in(lua_State *L)
{
    (void)L;
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_table_t");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    toml_array_t * rv = toml_array_in(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "toml_array_t");
    return 1;
}

static int GenL_toml_array_key(lua_State *L)
{
    (void)L;
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_array_t");
    const char * rv = toml_array_key(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_toml_array_kind(lua_State *L)
{
    (void)L;
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_array_t");
    char rv = toml_array_kind(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_toml_array_nelem(lua_State *L)
{
    (void)L;
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_array_t");
    int rv = toml_array_nelem(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_toml_array_type(lua_State *L)
{
    (void)L;
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_array_t");
    char rv = toml_array_type(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_toml_free(lua_State *L)
{
    (void)L;
    toml_table_t *a0 = (toml_table_t *)SDLStaticGen_LuaTakeHandle(L, 1, "toml_table_t");
    toml_free(a0);
    return 0;
}

static int GenL_toml_key_exists(lua_State *L)
{
    (void)L;
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_table_t");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = toml_key_exists(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_toml_key_in(lua_State *L)
{
    (void)L;
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_table_t");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char * rv = toml_key_in(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_toml_parse(lua_State *L)
{
    (void)L;
    const char *src0 = lua_isnoneornil(L, 1) ? "" : luaL_checkstring(L, 1);
    char *a0 = SDL_strdup(src0);
    const char *src1 = lua_isnoneornil(L, 2) ? "" : luaL_checkstring(L, 2);
    char *a1 = SDL_strdup(src1);
    int a2 = (int)luaL_checkinteger(L, 3);
    toml_table_t * rv = toml_parse(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "toml_table_t", GenDtor_toml_free);
    SDL_free(a1);
    SDL_free(a0);
    return 1;
}

static int GenL_toml_table_at(lua_State *L)
{
    (void)L;
    const toml_array_t *a0 = (const toml_array_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_array_t");
    int a1 = (int)luaL_checkinteger(L, 2);
    toml_table_t * rv = toml_table_at(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "toml_table_t");
    return 1;
}

static int GenL_toml_table_in(lua_State *L)
{
    (void)L;
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_table_t");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    toml_table_t * rv = toml_table_in(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "toml_table_t");
    return 1;
}

static int GenL_toml_table_key(lua_State *L)
{
    (void)L;
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_table_t");
    const char * rv = toml_table_key(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_toml_table_narr(lua_State *L)
{
    (void)L;
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_table_t");
    int rv = toml_table_narr(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_toml_table_nkval(lua_State *L)
{
    (void)L;
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_table_t");
    int rv = toml_table_nkval(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_toml_table_ntab(lua_State *L)
{
    (void)L;
    const toml_table_t *a0 = (const toml_table_t *)SDLStaticGen_LuaCheckHandle(L, 1, "toml_table_t");
    int rv = toml_table_ntab(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_toml_ucs_to_utf8(lua_State *L)
{
    (void)L;
    int64_t a0 = (int64_t)luaL_checkinteger(L, 1);
    const char *src1 = lua_isnoneornil(L, 2) ? "" : luaL_checkstring(L, 2);
    char *a1 = SDL_strdup(src1);
    int rv = toml_ucs_to_utf8(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    SDL_free(a1);
    return 1;
}

static int GenL_toml_utf8_to_ucs(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int64_t io2 = (int64_t)luaL_optinteger(L, 3, 0);
    int rv = toml_utf8_to_ucs(a0, a1, &io2);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

int SDLStaticGen_OpenLua_toml(lua_State *L);
int SDLStaticGen_OpenLua_toml(lua_State *L)
{
    lua_createtable(L, 0, 18);
    lua_pushcfunction(L, GenL_toml_array_at);
    lua_setfield(L, -2, "array_at");
    lua_pushcfunction(L, GenL_toml_array_in);
    lua_setfield(L, -2, "array_in");
    lua_pushcfunction(L, GenL_toml_array_key);
    lua_setfield(L, -2, "array_key");
    lua_pushcfunction(L, GenL_toml_array_kind);
    lua_setfield(L, -2, "array_kind");
    lua_pushcfunction(L, GenL_toml_array_nelem);
    lua_setfield(L, -2, "array_nelem");
    lua_pushcfunction(L, GenL_toml_array_type);
    lua_setfield(L, -2, "array_type");
    lua_pushcfunction(L, GenL_toml_free);
    lua_setfield(L, -2, "free");
    lua_pushcfunction(L, GenL_toml_key_exists);
    lua_setfield(L, -2, "key_exists");
    lua_pushcfunction(L, GenL_toml_key_in);
    lua_setfield(L, -2, "key_in");
    lua_pushcfunction(L, GenL_toml_parse);
    lua_setfield(L, -2, "parse");
    lua_pushcfunction(L, GenL_toml_table_at);
    lua_setfield(L, -2, "table_at");
    lua_pushcfunction(L, GenL_toml_table_in);
    lua_setfield(L, -2, "table_in");
    lua_pushcfunction(L, GenL_toml_table_key);
    lua_setfield(L, -2, "table_key");
    lua_pushcfunction(L, GenL_toml_table_narr);
    lua_setfield(L, -2, "table_narr");
    lua_pushcfunction(L, GenL_toml_table_nkval);
    lua_setfield(L, -2, "table_nkval");
    lua_pushcfunction(L, GenL_toml_table_ntab);
    lua_setfield(L, -2, "table_ntab");
    lua_pushcfunction(L, GenL_toml_ucs_to_utf8);
    lua_setfield(L, -2, "ucs_to_utf8");
    lua_pushcfunction(L, GenL_toml_utf8_to_ucs);
    lua_setfield(L, -2, "utf8_to_ucs");
    lua_setglobal(L, "TOML");
    return 0;
}
