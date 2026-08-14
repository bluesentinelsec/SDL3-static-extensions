/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for mog HTTP/S. */
#include "../src/gen_support_lua.h"

#include <mog/mog_c.h>
#include <string.h>

static void GenDtor_mog_request_free(void *p)
{
    mog_request *typed = (mog_request *)p;
    mog_request_free(typed);
}

static void GenDtor_mog_response_free(void *p)
{
    mog_response *typed = (mog_response *)p;
    mog_response_free(typed);
}

static void GenDtor_mog_server_free(void *p)
{
    mog_server *typed = (mog_server *)p;
    mog_server_free(typed);
}

static int GenL_mog_error_code_name(lua_State *L)
{
    (void)L;
    mog_error_code a0 = (mog_error_code)luaL_checkinteger(L, 1);
    const char * rv = mog_error_code_name(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_get(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    mog_response * rv = mog_get(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "mog_response", GenDtor_mog_response_free);
    return 1;
}

static int GenL_mog_perform(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    mog_response * rv = mog_perform(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "mog_response", GenDtor_mog_response_free);
    return 1;
}

static int GenL_mog_post(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    mog_response * rv = mog_post(a0, (const void *)a1, (size_t)len1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "mog_response", GenDtor_mog_response_free);
    return 1;
}

static int GenL_mog_request_free(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaTakeHandle(L, 1, "mog_request");
    mog_request_free(a0);
    return 0;
}

static int GenL_mog_request_new(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    mog_request * rv = mog_request_new(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "mog_request", GenDtor_mog_request_free);
    return 1;
}

static int GenL_mog_request_set_allow_redirects(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    int a1 = (int)luaL_checkinteger(L, 2);
    mog_request_set_allow_redirects(a0, a1);
    return 0;
}

static int GenL_mog_request_set_backend(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    mog_request_set_backend(a0, a1);
    return 0;
}

static int GenL_mog_request_set_basic_auth(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    mog_request_set_basic_auth(a0, a1, a2);
    return 0;
}

static int GenL_mog_request_set_bearer_token(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    mog_request_set_bearer_token(a0, a1);
    return 0;
}

static int GenL_mog_request_set_body(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    mog_request_set_body(a0, (const void *)a1, (size_t)len1);
    return 0;
}

static int GenL_mog_request_set_ca_bundle(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    mog_request_set_ca_bundle(a0, a1);
    return 0;
}

static int GenL_mog_request_set_client_cert(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    mog_request_set_client_cert(a0, a1, a2, a3);
    return 0;
}

static int GenL_mog_request_set_connect_timeout_ms(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    long a1 = (long)luaL_checkinteger(L, 2);
    mog_request_set_connect_timeout_ms(a0, a1);
    return 0;
}

static int GenL_mog_request_set_cookie(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    mog_request_set_cookie(a0, a1, a2);
    return 0;
}

static int GenL_mog_request_set_decompress(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    int a1 = (int)luaL_checkinteger(L, 2);
    mog_request_set_decompress(a0, a1);
    return 0;
}

static int GenL_mog_request_set_digest_auth(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    mog_request_set_digest_auth(a0, a1, a2);
    return 0;
}

static int GenL_mog_request_set_header(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    mog_request_set_header(a0, a1, a2);
    return 0;
}

static int GenL_mog_request_set_json(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    mog_request_set_json(a0, a1);
    return 0;
}

static int GenL_mog_request_set_max_redirects(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    int a1 = (int)luaL_checkinteger(L, 2);
    mog_request_set_max_redirects(a0, a1);
    return 0;
}

static int GenL_mog_request_set_max_response_bytes(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    size_t a1 = (size_t)luaL_checkinteger(L, 2);
    mog_request_set_max_response_bytes(a0, a1);
    return 0;
}

static int GenL_mog_request_set_proxy(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    mog_request_set_proxy(a0, a1);
    return 0;
}

static int GenL_mog_request_set_query_param(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    mog_request_set_query_param(a0, a1, a2);
    return 0;
}

static int GenL_mog_request_set_timeout_ms(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    long a1 = (long)luaL_checkinteger(L, 2);
    mog_request_set_timeout_ms(a0, a1);
    return 0;
}

static int GenL_mog_request_set_user_agent(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    mog_request_set_user_agent(a0, a1);
    return 0;
}

static int GenL_mog_request_set_verify_tls(lua_State *L)
{
    (void)L;
    mog_request *a0 = (mog_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_request");
    int a1 = (int)luaL_checkinteger(L, 2);
    mog_request_set_verify_tls(a0, a1);
    return 0;
}

static int GenL_mog_response_backend(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    const char * rv = mog_response_backend(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_response_body(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    size_t io1 = (size_t)luaL_optinteger(L, 2, 0);
    const char * rv = mog_response_body(a0, &io1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_mog_response_body_size(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    size_t rv = mog_response_body_size(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_response_downloaded_bytes(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    size_t rv = mog_response_downloaded_bytes(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_response_elapsed_ms(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    long rv = mog_response_elapsed_ms(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_response_error_code(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    mog_error_code rv = mog_response_error_code(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_response_error_message(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    const char * rv = mog_response_error_message(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_response_free(lua_State *L)
{
    (void)L;
    mog_response *a0 = (mog_response *)SDLStaticGen_LuaTakeHandle(L, 1, "mog_response");
    mog_response_free(a0);
    return 0;
}

static int GenL_mog_response_header(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char * rv = mog_response_header(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_response_header_count(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    size_t rv = mog_response_header_count(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_response_header_name(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    size_t a1 = (size_t)luaL_checkinteger(L, 2);
    const char * rv = mog_response_header_name(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_response_header_value(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    size_t a1 = (size_t)luaL_checkinteger(L, 2);
    const char * rv = mog_response_header_value(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_response_ok(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    int rv = mog_response_ok(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_response_reason(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    const char * rv = mog_response_reason(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_response_status(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    int rv = mog_response_status(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_response_url(lua_State *L)
{
    (void)L;
    const mog_response *a0 = (const mog_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_response");
    const char * rv = mog_response_url(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_server_free(lua_State *L)
{
    (void)L;
    mog_server *a0 = (mog_server *)SDLStaticGen_LuaTakeHandle(L, 1, "mog_server");
    mog_server_free(a0);
    return 0;
}

static int GenL_mog_server_is_running(lua_State *L)
{
    (void)L;
    const mog_server *a0 = (const mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    int rv = mog_server_is_running(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_server_last_error(lua_State *L)
{
    (void)L;
    const mog_server *a0 = (const mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    const char * rv = mog_server_last_error(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_server_new(lua_State *L)
{
    (void)L;
    mog_server * rv = mog_server_new();
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "mog_server", GenDtor_mog_server_free);
    return 1;
}

static int GenL_mog_server_port(lua_State *L)
{
    (void)L;
    const mog_server *a0 = (const mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    unsigned short rv = mog_server_port(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_server_request_body(lua_State *L)
{
    (void)L;
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server_request");
    size_t io1 = (size_t)luaL_optinteger(L, 2, 0);
    const char * rv = mog_server_request_body(a0, &io1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_mog_server_request_client_address(lua_State *L)
{
    (void)L;
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server_request");
    const char * rv = mog_server_request_client_address(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_server_request_header(lua_State *L)
{
    (void)L;
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char * rv = mog_server_request_header(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_server_request_method(lua_State *L)
{
    (void)L;
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server_request");
    const char * rv = mog_server_request_method(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_server_request_path(lua_State *L)
{
    (void)L;
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server_request");
    const char * rv = mog_server_request_path(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_server_request_query(lua_State *L)
{
    (void)L;
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server_request");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char * rv = mog_server_request_query(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_server_request_target(lua_State *L)
{
    (void)L;
    const mog_server_request *a0 = (const mog_server_request *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server_request");
    const char * rv = mog_server_request_target(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_mog_server_response_set_body(lua_State *L)
{
    (void)L;
    mog_server_response *a0 = (mog_server_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server_response");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    mog_server_response_set_body(a0, (const void *)a1, (size_t)len1);
    return 0;
}

static int GenL_mog_server_response_set_header(lua_State *L)
{
    (void)L;
    mog_server_response *a0 = (mog_server_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server_response");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    mog_server_response_set_header(a0, a1, a2);
    return 0;
}

static int GenL_mog_server_response_set_status(lua_State *L)
{
    (void)L;
    mog_server_response *a0 = (mog_server_response *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server_response");
    int a1 = (int)luaL_checkinteger(L, 2);
    mog_server_response_set_status(a0, a1);
    return 0;
}

static int GenL_mog_server_serve_files(lua_State *L)
{
    (void)L;
    mog_server *a0 = (mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    mog_server_serve_files(a0, a1, a2, a3);
    return 0;
}

static int GenL_mog_server_set_bind_address(lua_State *L)
{
    (void)L;
    mog_server *a0 = (mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    mog_server_set_bind_address(a0, a1);
    return 0;
}

static int GenL_mog_server_set_port(lua_State *L)
{
    (void)L;
    mog_server *a0 = (mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    unsigned short a1 = (unsigned short)luaL_checkinteger(L, 2);
    mog_server_set_port(a0, a1);
    return 0;
}

static int GenL_mog_server_set_threads(lua_State *L)
{
    (void)L;
    mog_server *a0 = (mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    unsigned int a1 = (unsigned int)luaL_checkinteger(L, 2);
    mog_server_set_threads(a0, a1);
    return 0;
}

static int GenL_mog_server_start(lua_State *L)
{
    (void)L;
    mog_server *a0 = (mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    int rv = mog_server_start(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_server_stop(lua_State *L)
{
    (void)L;
    mog_server *a0 = (mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    mog_server_stop(a0);
    return 0;
}

static int GenL_mog_server_use_self_signed_tls(lua_State *L)
{
    (void)L;
    mog_server *a0 = (mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    int rv = mog_server_use_self_signed_tls(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_server_use_tls_files(lua_State *L)
{
    (void)L;
    mog_server *a0 = (mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int rv = mog_server_use_tls_files(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_mog_server_wait(lua_State *L)
{
    (void)L;
    mog_server *a0 = (mog_server *)SDLStaticGen_LuaCheckHandle(L, 1, "mog_server");
    mog_server_wait(a0);
    return 0;
}

static int GenL_mog_version(lua_State *L)
{
    (void)L;
    const char * rv = mog_version();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

int SDLStaticGen_OpenLua_mog(lua_State *L);
int SDLStaticGen_OpenLua_mog(lua_State *L)
{
    lua_createtable(L, 0, 67);
    lua_pushcfunction(L, GenL_mog_error_code_name);
    lua_setfield(L, -2, "error_code_name");
    lua_pushcfunction(L, GenL_mog_get);
    lua_setfield(L, -2, "get");
    lua_pushcfunction(L, GenL_mog_perform);
    lua_setfield(L, -2, "perform");
    lua_pushcfunction(L, GenL_mog_post);
    lua_setfield(L, -2, "post");
    lua_pushcfunction(L, GenL_mog_request_free);
    lua_setfield(L, -2, "request_free");
    lua_pushcfunction(L, GenL_mog_request_new);
    lua_setfield(L, -2, "request_new");
    lua_pushcfunction(L, GenL_mog_request_set_allow_redirects);
    lua_setfield(L, -2, "request_set_allow_redirects");
    lua_pushcfunction(L, GenL_mog_request_set_backend);
    lua_setfield(L, -2, "request_set_backend");
    lua_pushcfunction(L, GenL_mog_request_set_basic_auth);
    lua_setfield(L, -2, "request_set_basic_auth");
    lua_pushcfunction(L, GenL_mog_request_set_bearer_token);
    lua_setfield(L, -2, "request_set_bearer_token");
    lua_pushcfunction(L, GenL_mog_request_set_body);
    lua_setfield(L, -2, "request_set_body");
    lua_pushcfunction(L, GenL_mog_request_set_ca_bundle);
    lua_setfield(L, -2, "request_set_ca_bundle");
    lua_pushcfunction(L, GenL_mog_request_set_client_cert);
    lua_setfield(L, -2, "request_set_client_cert");
    lua_pushcfunction(L, GenL_mog_request_set_connect_timeout_ms);
    lua_setfield(L, -2, "request_set_connect_timeout_ms");
    lua_pushcfunction(L, GenL_mog_request_set_cookie);
    lua_setfield(L, -2, "request_set_cookie");
    lua_pushcfunction(L, GenL_mog_request_set_decompress);
    lua_setfield(L, -2, "request_set_decompress");
    lua_pushcfunction(L, GenL_mog_request_set_digest_auth);
    lua_setfield(L, -2, "request_set_digest_auth");
    lua_pushcfunction(L, GenL_mog_request_set_header);
    lua_setfield(L, -2, "request_set_header");
    lua_pushcfunction(L, GenL_mog_request_set_json);
    lua_setfield(L, -2, "request_set_json");
    lua_pushcfunction(L, GenL_mog_request_set_max_redirects);
    lua_setfield(L, -2, "request_set_max_redirects");
    lua_pushcfunction(L, GenL_mog_request_set_max_response_bytes);
    lua_setfield(L, -2, "request_set_max_response_bytes");
    lua_pushcfunction(L, GenL_mog_request_set_proxy);
    lua_setfield(L, -2, "request_set_proxy");
    lua_pushcfunction(L, GenL_mog_request_set_query_param);
    lua_setfield(L, -2, "request_set_query_param");
    lua_pushcfunction(L, GenL_mog_request_set_timeout_ms);
    lua_setfield(L, -2, "request_set_timeout_ms");
    lua_pushcfunction(L, GenL_mog_request_set_user_agent);
    lua_setfield(L, -2, "request_set_user_agent");
    lua_pushcfunction(L, GenL_mog_request_set_verify_tls);
    lua_setfield(L, -2, "request_set_verify_tls");
    lua_pushcfunction(L, GenL_mog_response_backend);
    lua_setfield(L, -2, "response_backend");
    lua_pushcfunction(L, GenL_mog_response_body);
    lua_setfield(L, -2, "response_body");
    lua_pushcfunction(L, GenL_mog_response_body_size);
    lua_setfield(L, -2, "response_body_size");
    lua_pushcfunction(L, GenL_mog_response_downloaded_bytes);
    lua_setfield(L, -2, "response_downloaded_bytes");
    lua_pushcfunction(L, GenL_mog_response_elapsed_ms);
    lua_setfield(L, -2, "response_elapsed_ms");
    lua_pushcfunction(L, GenL_mog_response_error_code);
    lua_setfield(L, -2, "response_error_code");
    lua_pushcfunction(L, GenL_mog_response_error_message);
    lua_setfield(L, -2, "response_error_message");
    lua_pushcfunction(L, GenL_mog_response_free);
    lua_setfield(L, -2, "response_free");
    lua_pushcfunction(L, GenL_mog_response_header);
    lua_setfield(L, -2, "response_header");
    lua_pushcfunction(L, GenL_mog_response_header_count);
    lua_setfield(L, -2, "response_header_count");
    lua_pushcfunction(L, GenL_mog_response_header_name);
    lua_setfield(L, -2, "response_header_name");
    lua_pushcfunction(L, GenL_mog_response_header_value);
    lua_setfield(L, -2, "response_header_value");
    lua_pushcfunction(L, GenL_mog_response_ok);
    lua_setfield(L, -2, "response_ok");
    lua_pushcfunction(L, GenL_mog_response_reason);
    lua_setfield(L, -2, "response_reason");
    lua_pushcfunction(L, GenL_mog_response_status);
    lua_setfield(L, -2, "response_status");
    lua_pushcfunction(L, GenL_mog_response_url);
    lua_setfield(L, -2, "response_url");
    lua_pushcfunction(L, GenL_mog_server_free);
    lua_setfield(L, -2, "server_free");
    lua_pushcfunction(L, GenL_mog_server_is_running);
    lua_setfield(L, -2, "server_is_running");
    lua_pushcfunction(L, GenL_mog_server_last_error);
    lua_setfield(L, -2, "server_last_error");
    lua_pushcfunction(L, GenL_mog_server_new);
    lua_setfield(L, -2, "server_new");
    lua_pushcfunction(L, GenL_mog_server_port);
    lua_setfield(L, -2, "server_port");
    lua_pushcfunction(L, GenL_mog_server_request_body);
    lua_setfield(L, -2, "server_request_body");
    lua_pushcfunction(L, GenL_mog_server_request_client_address);
    lua_setfield(L, -2, "server_request_client_address");
    lua_pushcfunction(L, GenL_mog_server_request_header);
    lua_setfield(L, -2, "server_request_header");
    lua_pushcfunction(L, GenL_mog_server_request_method);
    lua_setfield(L, -2, "server_request_method");
    lua_pushcfunction(L, GenL_mog_server_request_path);
    lua_setfield(L, -2, "server_request_path");
    lua_pushcfunction(L, GenL_mog_server_request_query);
    lua_setfield(L, -2, "server_request_query");
    lua_pushcfunction(L, GenL_mog_server_request_target);
    lua_setfield(L, -2, "server_request_target");
    lua_pushcfunction(L, GenL_mog_server_response_set_body);
    lua_setfield(L, -2, "server_response_set_body");
    lua_pushcfunction(L, GenL_mog_server_response_set_header);
    lua_setfield(L, -2, "server_response_set_header");
    lua_pushcfunction(L, GenL_mog_server_response_set_status);
    lua_setfield(L, -2, "server_response_set_status");
    lua_pushcfunction(L, GenL_mog_server_serve_files);
    lua_setfield(L, -2, "server_serve_files");
    lua_pushcfunction(L, GenL_mog_server_set_bind_address);
    lua_setfield(L, -2, "server_set_bind_address");
    lua_pushcfunction(L, GenL_mog_server_set_port);
    lua_setfield(L, -2, "server_set_port");
    lua_pushcfunction(L, GenL_mog_server_set_threads);
    lua_setfield(L, -2, "server_set_threads");
    lua_pushcfunction(L, GenL_mog_server_start);
    lua_setfield(L, -2, "server_start");
    lua_pushcfunction(L, GenL_mog_server_stop);
    lua_setfield(L, -2, "server_stop");
    lua_pushcfunction(L, GenL_mog_server_use_self_signed_tls);
    lua_setfield(L, -2, "server_use_self_signed_tls");
    lua_pushcfunction(L, GenL_mog_server_use_tls_files);
    lua_setfield(L, -2, "server_use_tls_files");
    lua_pushcfunction(L, GenL_mog_server_wait);
    lua_setfield(L, -2, "server_wait");
    lua_pushcfunction(L, GenL_mog_version);
    lua_setfield(L, -2, "version");
    lua_pushinteger(L, (lua_Integer)MOG_OK);
    lua_setfield(L, -2, "MOG_OK");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_INVALID_URL);
    lua_setfield(L, -2, "MOG_ERR_INVALID_URL");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_INVALID_ARGUMENT);
    lua_setfield(L, -2, "MOG_ERR_INVALID_ARGUMENT");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_UNSUPPORTED_SCHEME);
    lua_setfield(L, -2, "MOG_ERR_UNSUPPORTED_SCHEME");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_UNSUPPORTED_BACKEND);
    lua_setfield(L, -2, "MOG_ERR_UNSUPPORTED_BACKEND");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_DNS_FAILED);
    lua_setfield(L, -2, "MOG_ERR_DNS_FAILED");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_CONNECT_FAILED);
    lua_setfield(L, -2, "MOG_ERR_CONNECT_FAILED");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_TLS_FAILED);
    lua_setfield(L, -2, "MOG_ERR_TLS_FAILED");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_TIMEOUT);
    lua_setfield(L, -2, "MOG_ERR_TIMEOUT");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_IO);
    lua_setfield(L, -2, "MOG_ERR_IO");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_PROTOCOL);
    lua_setfield(L, -2, "MOG_ERR_PROTOCOL");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_TOO_MANY_REDIRECTS);
    lua_setfield(L, -2, "MOG_ERR_TOO_MANY_REDIRECTS");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_HTTP_STATUS);
    lua_setfield(L, -2, "MOG_ERR_HTTP_STATUS");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_RESPONSE_TOO_LARGE);
    lua_setfield(L, -2, "MOG_ERR_RESPONSE_TOO_LARGE");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_PROXY);
    lua_setfield(L, -2, "MOG_ERR_PROXY");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_FILE);
    lua_setfield(L, -2, "MOG_ERR_FILE");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_JSON);
    lua_setfield(L, -2, "MOG_ERR_JSON");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_COMPRESSION);
    lua_setfield(L, -2, "MOG_ERR_COMPRESSION");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_DYNAMIC_LIBRARY);
    lua_setfield(L, -2, "MOG_ERR_DYNAMIC_LIBRARY");
    lua_pushinteger(L, (lua_Integer)MOG_ERR_INTERNAL);
    lua_setfield(L, -2, "MOG_ERR_INTERNAL");
    lua_setglobal(L, "MOG");
    return 0;
}
