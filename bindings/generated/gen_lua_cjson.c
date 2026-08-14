/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for cJSON. */
#include "../src/gen_support_lua.h"

#include <cJSON.h>
#include <string.h>

static void GenDtor_cJSON_Delete(void *p)
{
    cJSON *typed = (cJSON *)p;
    cJSON_Delete(typed);
}

static int GenL_cJSON_AddArrayToObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON * rv = cJSON_AddArrayToObject(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_AddBoolToObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON_bool a2 = (cJSON_bool)lua_toboolean(L, 3);
    cJSON * rv = cJSON_AddBoolToObject(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_AddFalseToObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON * rv = cJSON_AddFalseToObject(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_AddItemReferenceToArray(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON *a1 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 2, "cJSON");
    cJSON_bool rv = cJSON_AddItemReferenceToArray(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_AddItemReferenceToObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON *a2 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 3, "cJSON");
    cJSON_bool rv = cJSON_AddItemReferenceToObject(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_AddItemToArray(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON *a1 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 2, "cJSON");
    cJSON_bool rv = cJSON_AddItemToArray(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_AddItemToObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON *a2 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 3, "cJSON");
    cJSON_bool rv = cJSON_AddItemToObject(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_AddItemToObjectCS(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON *a2 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 3, "cJSON");
    cJSON_bool rv = cJSON_AddItemToObjectCS(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_AddNullToObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON * rv = cJSON_AddNullToObject(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_AddNumberToObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    double a2 = (double)luaL_checknumber(L, 3);
    cJSON * rv = cJSON_AddNumberToObject(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_AddObjectToObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON * rv = cJSON_AddObjectToObject(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_AddRawToObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    cJSON * rv = cJSON_AddRawToObject(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_AddStringToObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    cJSON * rv = cJSON_AddStringToObject(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_AddTrueToObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON * rv = cJSON_AddTrueToObject(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_Compare(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const cJSON *a1 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 2, "cJSON");
    cJSON_bool a2 = (cJSON_bool)lua_toboolean(L, 3);
    cJSON_bool rv = cJSON_Compare(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_CreateArray(lua_State *L)
{
    (void)L;
    cJSON * rv = cJSON_CreateArray();
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "cJSON", GenDtor_cJSON_Delete);
    return 1;
}

static int GenL_cJSON_CreateArrayReference(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON * rv = cJSON_CreateArrayReference(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_CreateBool(lua_State *L)
{
    (void)L;
    cJSON_bool a0 = (cJSON_bool)lua_toboolean(L, 1);
    cJSON * rv = cJSON_CreateBool(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_CreateFalse(lua_State *L)
{
    (void)L;
    cJSON * rv = cJSON_CreateFalse();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_CreateNull(lua_State *L)
{
    (void)L;
    cJSON * rv = cJSON_CreateNull();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_CreateNumber(lua_State *L)
{
    (void)L;
    double a0 = (double)luaL_checknumber(L, 1);
    cJSON * rv = cJSON_CreateNumber(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_CreateObject(lua_State *L)
{
    (void)L;
    cJSON * rv = cJSON_CreateObject();
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "cJSON", GenDtor_cJSON_Delete);
    return 1;
}

static int GenL_cJSON_CreateObjectReference(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON * rv = cJSON_CreateObjectReference(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_CreateRaw(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    cJSON * rv = cJSON_CreateRaw(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_CreateString(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    cJSON * rv = cJSON_CreateString(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_CreateStringReference(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    cJSON * rv = cJSON_CreateStringReference(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_CreateTrue(lua_State *L)
{
    (void)L;
    cJSON * rv = cJSON_CreateTrue();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_Delete(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaTakeHandle(L, 1, "cJSON");
    cJSON_Delete(a0);
    return 0;
}

static int GenL_cJSON_DeleteItemFromArray(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    int a1 = (int)luaL_checkinteger(L, 2);
    cJSON_DeleteItemFromArray(a0, a1);
    return 0;
}

static int GenL_cJSON_DeleteItemFromObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON_DeleteItemFromObject(a0, a1);
    return 0;
}

static int GenL_cJSON_DeleteItemFromObjectCaseSensitive(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON_DeleteItemFromObjectCaseSensitive(a0, a1);
    return 0;
}

static int GenL_cJSON_DetachItemFromArray(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    int a1 = (int)luaL_checkinteger(L, 2);
    cJSON * rv = cJSON_DetachItemFromArray(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_DetachItemFromObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON * rv = cJSON_DetachItemFromObject(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_DetachItemFromObjectCaseSensitive(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON * rv = cJSON_DetachItemFromObjectCaseSensitive(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_DetachItemViaPointer(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON *a1 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 2, "cJSON");
    cJSON * rv = cJSON_DetachItemViaPointer(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_Duplicate(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON_bool a1 = (cJSON_bool)lua_toboolean(L, 2);
    cJSON * rv = cJSON_Duplicate(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_GetArrayItem(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    int a1 = (int)luaL_checkinteger(L, 2);
    cJSON * rv = cJSON_GetArrayItem(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_GetArraySize(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    int rv = cJSON_GetArraySize(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_cJSON_GetErrorPtr(lua_State *L)
{
    (void)L;
    const char * rv = cJSON_GetErrorPtr();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_cJSON_GetNumberValue(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    double rv = cJSON_GetNumberValue(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_cJSON_GetObjectItem(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON * rv = cJSON_GetObjectItem(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_GetObjectItemCaseSensitive(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON * rv = cJSON_GetObjectItemCaseSensitive(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cJSON");
    return 1;
}

static int GenL_cJSON_GetStringValue(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    char * rv = cJSON_GetStringValue(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { cJSON_free(rv); }
    return 1;
}

static int GenL_cJSON_HasObjectItem(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON_bool rv = cJSON_HasObjectItem(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_InitHooks(lua_State *L)
{
    (void)L;
    cJSON_Hooks *a0 = (cJSON_Hooks *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON_Hooks");
    cJSON_InitHooks(a0);
    return 0;
}

static int GenL_cJSON_InsertItemInArray(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    int a1 = (int)luaL_checkinteger(L, 2);
    cJSON *a2 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 3, "cJSON");
    cJSON_bool rv = cJSON_InsertItemInArray(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_IsArray(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON_bool rv = cJSON_IsArray(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_IsBool(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON_bool rv = cJSON_IsBool(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_IsFalse(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON_bool rv = cJSON_IsFalse(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_IsInvalid(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON_bool rv = cJSON_IsInvalid(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_IsNull(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON_bool rv = cJSON_IsNull(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_IsNumber(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON_bool rv = cJSON_IsNumber(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_IsObject(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON_bool rv = cJSON_IsObject(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_IsRaw(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON_bool rv = cJSON_IsRaw(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_IsString(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON_bool rv = cJSON_IsString(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_IsTrue(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON_bool rv = cJSON_IsTrue(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_Minify(lua_State *L)
{
    (void)L;
    const char *src0 = lua_isnoneornil(L, 1) ? "" : luaL_checkstring(L, 1);
    char *a0 = SDL_strdup(src0);
    cJSON_Minify(a0);
    SDL_free(a0);
    return 0;
}

static int GenL_cJSON_Parse(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    cJSON * rv = cJSON_Parse(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "cJSON", GenDtor_cJSON_Delete);
    return 1;
}

static int GenL_cJSON_ParseWithLength(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    size_t a1 = (size_t)luaL_checkinteger(L, 2);
    cJSON * rv = cJSON_ParseWithLength(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "cJSON", GenDtor_cJSON_Delete);
    return 1;
}

static int GenL_cJSON_Print(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    char * rv = cJSON_Print(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { cJSON_free(rv); }
    return 1;
}

static int GenL_cJSON_PrintBuffered(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    int a1 = (int)luaL_checkinteger(L, 2);
    cJSON_bool a2 = (cJSON_bool)lua_toboolean(L, 3);
    char * rv = cJSON_PrintBuffered(a0, a1, a2);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { cJSON_free(rv); }
    return 1;
}

static int GenL_cJSON_PrintPreallocated(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *src1 = lua_isnoneornil(L, 2) ? "" : luaL_checkstring(L, 2);
    char *a1 = SDL_strdup(src1);
    int a2 = (int)luaL_checkinteger(L, 3);
    cJSON_bool a3 = (cJSON_bool)lua_toboolean(L, 4);
    cJSON_bool rv = cJSON_PrintPreallocated(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    SDL_free(a1);
    return 1;
}

static int GenL_cJSON_PrintUnformatted(lua_State *L)
{
    (void)L;
    const cJSON *a0 = (const cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    char * rv = cJSON_PrintUnformatted(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { cJSON_free(rv); }
    return 1;
}

static int GenL_cJSON_ReplaceItemInArray(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    int a1 = (int)luaL_checkinteger(L, 2);
    cJSON *a2 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 3, "cJSON");
    cJSON_bool rv = cJSON_ReplaceItemInArray(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_ReplaceItemInObject(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON *a2 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 3, "cJSON");
    cJSON_bool rv = cJSON_ReplaceItemInObject(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_ReplaceItemInObjectCaseSensitive(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    cJSON *a2 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 3, "cJSON");
    cJSON_bool rv = cJSON_ReplaceItemInObjectCaseSensitive(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_ReplaceItemViaPointer(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    cJSON *a1 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 2, "cJSON");
    cJSON *a2 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 3, "cJSON");
    cJSON_bool rv = cJSON_ReplaceItemViaPointer(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_cJSON_SetNumberHelper(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    double a1 = (double)luaL_checknumber(L, 2);
    double rv = cJSON_SetNumberHelper(a0, a1);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_cJSON_SetValuestring(lua_State *L)
{
    (void)L;
    cJSON *a0 = (cJSON *)SDLStaticGen_LuaCheckHandle(L, 1, "cJSON");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    char * rv = cJSON_SetValuestring(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { cJSON_free(rv); }
    return 1;
}

static int GenL_cJSON_Version(lua_State *L)
{
    (void)L;
    const char * rv = cJSON_Version();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

int SDLStaticGen_OpenLua_cjson(lua_State *L);
int SDLStaticGen_OpenLua_cjson(lua_State *L)
{
    lua_createtable(L, 0, 70);
    lua_pushcfunction(L, GenL_cJSON_AddArrayToObject);
    lua_setfield(L, -2, "AddArrayToObject");
    lua_pushcfunction(L, GenL_cJSON_AddBoolToObject);
    lua_setfield(L, -2, "AddBoolToObject");
    lua_pushcfunction(L, GenL_cJSON_AddFalseToObject);
    lua_setfield(L, -2, "AddFalseToObject");
    lua_pushcfunction(L, GenL_cJSON_AddItemReferenceToArray);
    lua_setfield(L, -2, "AddItemReferenceToArray");
    lua_pushcfunction(L, GenL_cJSON_AddItemReferenceToObject);
    lua_setfield(L, -2, "AddItemReferenceToObject");
    lua_pushcfunction(L, GenL_cJSON_AddItemToArray);
    lua_setfield(L, -2, "AddItemToArray");
    lua_pushcfunction(L, GenL_cJSON_AddItemToObject);
    lua_setfield(L, -2, "AddItemToObject");
    lua_pushcfunction(L, GenL_cJSON_AddItemToObjectCS);
    lua_setfield(L, -2, "AddItemToObjectCS");
    lua_pushcfunction(L, GenL_cJSON_AddNullToObject);
    lua_setfield(L, -2, "AddNullToObject");
    lua_pushcfunction(L, GenL_cJSON_AddNumberToObject);
    lua_setfield(L, -2, "AddNumberToObject");
    lua_pushcfunction(L, GenL_cJSON_AddObjectToObject);
    lua_setfield(L, -2, "AddObjectToObject");
    lua_pushcfunction(L, GenL_cJSON_AddRawToObject);
    lua_setfield(L, -2, "AddRawToObject");
    lua_pushcfunction(L, GenL_cJSON_AddStringToObject);
    lua_setfield(L, -2, "AddStringToObject");
    lua_pushcfunction(L, GenL_cJSON_AddTrueToObject);
    lua_setfield(L, -2, "AddTrueToObject");
    lua_pushcfunction(L, GenL_cJSON_Compare);
    lua_setfield(L, -2, "Compare");
    lua_pushcfunction(L, GenL_cJSON_CreateArray);
    lua_setfield(L, -2, "CreateArray");
    lua_pushcfunction(L, GenL_cJSON_CreateArrayReference);
    lua_setfield(L, -2, "CreateArrayReference");
    lua_pushcfunction(L, GenL_cJSON_CreateBool);
    lua_setfield(L, -2, "CreateBool");
    lua_pushcfunction(L, GenL_cJSON_CreateFalse);
    lua_setfield(L, -2, "CreateFalse");
    lua_pushcfunction(L, GenL_cJSON_CreateNull);
    lua_setfield(L, -2, "CreateNull");
    lua_pushcfunction(L, GenL_cJSON_CreateNumber);
    lua_setfield(L, -2, "CreateNumber");
    lua_pushcfunction(L, GenL_cJSON_CreateObject);
    lua_setfield(L, -2, "CreateObject");
    lua_pushcfunction(L, GenL_cJSON_CreateObjectReference);
    lua_setfield(L, -2, "CreateObjectReference");
    lua_pushcfunction(L, GenL_cJSON_CreateRaw);
    lua_setfield(L, -2, "CreateRaw");
    lua_pushcfunction(L, GenL_cJSON_CreateString);
    lua_setfield(L, -2, "CreateString");
    lua_pushcfunction(L, GenL_cJSON_CreateStringReference);
    lua_setfield(L, -2, "CreateStringReference");
    lua_pushcfunction(L, GenL_cJSON_CreateTrue);
    lua_setfield(L, -2, "CreateTrue");
    lua_pushcfunction(L, GenL_cJSON_Delete);
    lua_setfield(L, -2, "Delete");
    lua_pushcfunction(L, GenL_cJSON_DeleteItemFromArray);
    lua_setfield(L, -2, "DeleteItemFromArray");
    lua_pushcfunction(L, GenL_cJSON_DeleteItemFromObject);
    lua_setfield(L, -2, "DeleteItemFromObject");
    lua_pushcfunction(L, GenL_cJSON_DeleteItemFromObjectCaseSensitive);
    lua_setfield(L, -2, "DeleteItemFromObjectCaseSensitive");
    lua_pushcfunction(L, GenL_cJSON_DetachItemFromArray);
    lua_setfield(L, -2, "DetachItemFromArray");
    lua_pushcfunction(L, GenL_cJSON_DetachItemFromObject);
    lua_setfield(L, -2, "DetachItemFromObject");
    lua_pushcfunction(L, GenL_cJSON_DetachItemFromObjectCaseSensitive);
    lua_setfield(L, -2, "DetachItemFromObjectCaseSensitive");
    lua_pushcfunction(L, GenL_cJSON_DetachItemViaPointer);
    lua_setfield(L, -2, "DetachItemViaPointer");
    lua_pushcfunction(L, GenL_cJSON_Duplicate);
    lua_setfield(L, -2, "Duplicate");
    lua_pushcfunction(L, GenL_cJSON_GetArrayItem);
    lua_setfield(L, -2, "GetArrayItem");
    lua_pushcfunction(L, GenL_cJSON_GetArraySize);
    lua_setfield(L, -2, "GetArraySize");
    lua_pushcfunction(L, GenL_cJSON_GetErrorPtr);
    lua_setfield(L, -2, "GetErrorPtr");
    lua_pushcfunction(L, GenL_cJSON_GetNumberValue);
    lua_setfield(L, -2, "GetNumberValue");
    lua_pushcfunction(L, GenL_cJSON_GetObjectItem);
    lua_setfield(L, -2, "GetObjectItem");
    lua_pushcfunction(L, GenL_cJSON_GetObjectItemCaseSensitive);
    lua_setfield(L, -2, "GetObjectItemCaseSensitive");
    lua_pushcfunction(L, GenL_cJSON_GetStringValue);
    lua_setfield(L, -2, "GetStringValue");
    lua_pushcfunction(L, GenL_cJSON_HasObjectItem);
    lua_setfield(L, -2, "HasObjectItem");
    lua_pushcfunction(L, GenL_cJSON_InitHooks);
    lua_setfield(L, -2, "InitHooks");
    lua_pushcfunction(L, GenL_cJSON_InsertItemInArray);
    lua_setfield(L, -2, "InsertItemInArray");
    lua_pushcfunction(L, GenL_cJSON_IsArray);
    lua_setfield(L, -2, "IsArray");
    lua_pushcfunction(L, GenL_cJSON_IsBool);
    lua_setfield(L, -2, "IsBool");
    lua_pushcfunction(L, GenL_cJSON_IsFalse);
    lua_setfield(L, -2, "IsFalse");
    lua_pushcfunction(L, GenL_cJSON_IsInvalid);
    lua_setfield(L, -2, "IsInvalid");
    lua_pushcfunction(L, GenL_cJSON_IsNull);
    lua_setfield(L, -2, "IsNull");
    lua_pushcfunction(L, GenL_cJSON_IsNumber);
    lua_setfield(L, -2, "IsNumber");
    lua_pushcfunction(L, GenL_cJSON_IsObject);
    lua_setfield(L, -2, "IsObject");
    lua_pushcfunction(L, GenL_cJSON_IsRaw);
    lua_setfield(L, -2, "IsRaw");
    lua_pushcfunction(L, GenL_cJSON_IsString);
    lua_setfield(L, -2, "IsString");
    lua_pushcfunction(L, GenL_cJSON_IsTrue);
    lua_setfield(L, -2, "IsTrue");
    lua_pushcfunction(L, GenL_cJSON_Minify);
    lua_setfield(L, -2, "Minify");
    lua_pushcfunction(L, GenL_cJSON_Parse);
    lua_setfield(L, -2, "Parse");
    lua_pushcfunction(L, GenL_cJSON_ParseWithLength);
    lua_setfield(L, -2, "ParseWithLength");
    lua_pushcfunction(L, GenL_cJSON_Print);
    lua_setfield(L, -2, "Print");
    lua_pushcfunction(L, GenL_cJSON_PrintBuffered);
    lua_setfield(L, -2, "PrintBuffered");
    lua_pushcfunction(L, GenL_cJSON_PrintPreallocated);
    lua_setfield(L, -2, "PrintPreallocated");
    lua_pushcfunction(L, GenL_cJSON_PrintUnformatted);
    lua_setfield(L, -2, "PrintUnformatted");
    lua_pushcfunction(L, GenL_cJSON_ReplaceItemInArray);
    lua_setfield(L, -2, "ReplaceItemInArray");
    lua_pushcfunction(L, GenL_cJSON_ReplaceItemInObject);
    lua_setfield(L, -2, "ReplaceItemInObject");
    lua_pushcfunction(L, GenL_cJSON_ReplaceItemInObjectCaseSensitive);
    lua_setfield(L, -2, "ReplaceItemInObjectCaseSensitive");
    lua_pushcfunction(L, GenL_cJSON_ReplaceItemViaPointer);
    lua_setfield(L, -2, "ReplaceItemViaPointer");
    lua_pushcfunction(L, GenL_cJSON_SetNumberHelper);
    lua_setfield(L, -2, "SetNumberHelper");
    lua_pushcfunction(L, GenL_cJSON_SetValuestring);
    lua_setfield(L, -2, "SetValuestring");
    lua_pushcfunction(L, GenL_cJSON_Version);
    lua_setfield(L, -2, "Version");
    lua_setglobal(L, "JSON");
    return 0;
}
