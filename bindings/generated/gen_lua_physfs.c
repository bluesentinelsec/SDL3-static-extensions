/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for PhysFS. */
#include "../src/gen_support_lua.h"

#include <physfs.h>
#include <string.h>

static void GenPush_PHYSFS_Stat(lua_State *L, const PHYSFS_Stat *in)
{
    lua_createtable(L, 0, 6);
    lua_pushinteger(L, (lua_Integer)in->filesize);
    lua_setfield(L, -2, "filesize");
    lua_pushinteger(L, (lua_Integer)in->modtime);
    lua_setfield(L, -2, "modtime");
    lua_pushinteger(L, (lua_Integer)in->createtime);
    lua_setfield(L, -2, "createtime");
    lua_pushinteger(L, (lua_Integer)in->accesstime);
    lua_setfield(L, -2, "accesstime");
    lua_pushinteger(L, (lua_Integer)in->filetype);
    lua_setfield(L, -2, "filetype");
    lua_pushinteger(L, (lua_Integer)in->readonly);
    lua_setfield(L, -2, "readonly");
}

static void GenPush_PHYSFS_Version(lua_State *L, const PHYSFS_Version *in)
{
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, (lua_Integer)in->major);
    lua_setfield(L, -2, "major");
    lua_pushinteger(L, (lua_Integer)in->minor);
    lua_setfield(L, -2, "minor");
    lua_pushinteger(L, (lua_Integer)in->patch);
    lua_setfield(L, -2, "patch");
}

static int GenL_PHYSFS_caseFold(lua_State *L)
{
    (void)L;
    PHYSFS_uint32 a0 = (PHYSFS_uint32)luaL_checkinteger(L, 1);
    PHYSFS_uint32 io1 = (PHYSFS_uint32)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_caseFold(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_close(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    int rv = PHYSFS_close(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_deinit(lua_State *L)
{
    (void)L;
    int rv = PHYSFS_deinit();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_delete(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int rv = PHYSFS_delete(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_deregisterArchiver(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int rv = PHYSFS_deregisterArchiver(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_eof(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    int rv = PHYSFS_eof(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_exists(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int rv = PHYSFS_exists(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_fileLength(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint64 rv = PHYSFS_fileLength(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_flush(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    int rv = PHYSFS_flush(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_getAllocator(lua_State *L)
{
    (void)L;
    const PHYSFS_Allocator * rv = PHYSFS_getAllocator();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "PHYSFS_Allocator");
    return 1;
}

static int GenL_PHYSFS_getBaseDir(lua_State *L)
{
    (void)L;
    const char * rv = PHYSFS_getBaseDir();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_PHYSFS_getDirSeparator(lua_State *L)
{
    (void)L;
    const char * rv = PHYSFS_getDirSeparator();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_PHYSFS_getErrorByCode(lua_State *L)
{
    (void)L;
    PHYSFS_ErrorCode a0 = (PHYSFS_ErrorCode)luaL_checkinteger(L, 1);
    const char * rv = PHYSFS_getErrorByCode(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_PHYSFS_getLastErrorCode(lua_State *L)
{
    (void)L;
    PHYSFS_ErrorCode rv = PHYSFS_getLastErrorCode();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_getLinkedVersion(lua_State *L)
{
    (void)L;
    PHYSFS_Version out0;
    memset(&out0, 0, sizeof(out0));
    PHYSFS_getLinkedVersion(&out0);
    GenPush_PHYSFS_Version(L, &out0);
    return 1;
}

static int GenL_PHYSFS_getMountPoint(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char * rv = PHYSFS_getMountPoint(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_PHYSFS_getPrefDir(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char * rv = PHYSFS_getPrefDir(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_PHYSFS_getRealDir(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char * rv = PHYSFS_getRealDir(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_PHYSFS_getWriteDir(lua_State *L)
{
    (void)L;
    const char * rv = PHYSFS_getWriteDir();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_PHYSFS_init(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int rv = PHYSFS_init(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_isInit(lua_State *L)
{
    (void)L;
    int rv = PHYSFS_isInit();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_mkdir(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int rv = PHYSFS_mkdir(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_mount(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int rv = PHYSFS_mount(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_mountHandle(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int rv = PHYSFS_mountHandle(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_mountIo(lua_State *L)
{
    (void)L;
    PHYSFS_Io *a0 = (PHYSFS_Io *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_Io");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int rv = PHYSFS_mountIo(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_openAppend(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    PHYSFS_File * rv = PHYSFS_openAppend(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "PHYSFS_File");
    return 1;
}

static int GenL_PHYSFS_openRead(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    PHYSFS_File * rv = PHYSFS_openRead(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "PHYSFS_File");
    return 1;
}

static int GenL_PHYSFS_openWrite(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    PHYSFS_File * rv = PHYSFS_openWrite(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "PHYSFS_File");
    return 1;
}

static int GenL_PHYSFS_permitSymbolicLinks(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    PHYSFS_permitSymbolicLinks(a0);
    return 0;
}

static int GenL_PHYSFS_readSBE16(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint16 io1 = (PHYSFS_sint16)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readSBE16(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_readSBE32(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint32 io1 = (PHYSFS_sint32)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readSBE32(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_readSBE64(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint64 io1 = (PHYSFS_sint64)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readSBE64(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_readSLE16(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint16 io1 = (PHYSFS_sint16)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readSLE16(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_readSLE32(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint32 io1 = (PHYSFS_sint32)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readSLE32(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_readSLE64(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint64 io1 = (PHYSFS_sint64)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readSLE64(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_readUBE16(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint16 io1 = (PHYSFS_uint16)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readUBE16(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_readUBE32(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint32 io1 = (PHYSFS_uint32)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readUBE32(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_readUBE64(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint64 io1 = (PHYSFS_uint64)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readUBE64(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_readULE16(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint16 io1 = (PHYSFS_uint16)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readULE16(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_readULE32(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint32 io1 = (PHYSFS_uint32)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readULE32(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_readULE64(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint64 io1 = (PHYSFS_uint64)luaL_optinteger(L, 2, 0);
    int rv = PHYSFS_readULE64(a0, &io1);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_PHYSFS_registerArchiver(lua_State *L)
{
    (void)L;
    const PHYSFS_Archiver *a0 = (const PHYSFS_Archiver *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_Archiver");
    int rv = PHYSFS_registerArchiver(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_seek(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint64 a1 = (PHYSFS_uint64)luaL_checkinteger(L, 2);
    int rv = PHYSFS_seek(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_setAllocator(lua_State *L)
{
    (void)L;
    const PHYSFS_Allocator *a0 = (const PHYSFS_Allocator *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_Allocator");
    int rv = PHYSFS_setAllocator(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_setBuffer(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint64 a1 = (PHYSFS_uint64)luaL_checkinteger(L, 2);
    int rv = PHYSFS_setBuffer(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_setErrorCode(lua_State *L)
{
    (void)L;
    PHYSFS_ErrorCode a0 = (PHYSFS_ErrorCode)luaL_checkinteger(L, 1);
    PHYSFS_setErrorCode(a0);
    return 0;
}

static int GenL_PHYSFS_setRoot(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = PHYSFS_setRoot(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_setSaneConfig(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    int rv = PHYSFS_setSaneConfig(a0, a1, a2, a3, a4);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_setWriteDir(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int rv = PHYSFS_setWriteDir(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_stat(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    PHYSFS_Stat out1;
    memset(&out1, 0, sizeof(out1));
    int rv = PHYSFS_stat(a0, &out1);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_PHYSFS_Stat(L, &out1);
    return 2;
}

static int GenL_PHYSFS_swapSBE16(lua_State *L)
{
    (void)L;
    PHYSFS_sint16 a0 = (PHYSFS_sint16)luaL_checkinteger(L, 1);
    PHYSFS_sint16 rv = PHYSFS_swapSBE16(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_swapSBE32(lua_State *L)
{
    (void)L;
    PHYSFS_sint32 a0 = (PHYSFS_sint32)luaL_checkinteger(L, 1);
    PHYSFS_sint32 rv = PHYSFS_swapSBE32(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_swapSBE64(lua_State *L)
{
    (void)L;
    PHYSFS_sint64 a0 = (PHYSFS_sint64)luaL_checkinteger(L, 1);
    PHYSFS_sint64 rv = PHYSFS_swapSBE64(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_swapSLE16(lua_State *L)
{
    (void)L;
    PHYSFS_sint16 a0 = (PHYSFS_sint16)luaL_checkinteger(L, 1);
    PHYSFS_sint16 rv = PHYSFS_swapSLE16(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_swapSLE32(lua_State *L)
{
    (void)L;
    PHYSFS_sint32 a0 = (PHYSFS_sint32)luaL_checkinteger(L, 1);
    PHYSFS_sint32 rv = PHYSFS_swapSLE32(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_swapSLE64(lua_State *L)
{
    (void)L;
    PHYSFS_sint64 a0 = (PHYSFS_sint64)luaL_checkinteger(L, 1);
    PHYSFS_sint64 rv = PHYSFS_swapSLE64(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_swapUBE16(lua_State *L)
{
    (void)L;
    PHYSFS_uint16 a0 = (PHYSFS_uint16)luaL_checkinteger(L, 1);
    PHYSFS_uint16 rv = PHYSFS_swapUBE16(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_swapUBE32(lua_State *L)
{
    (void)L;
    PHYSFS_uint32 a0 = (PHYSFS_uint32)luaL_checkinteger(L, 1);
    PHYSFS_uint32 rv = PHYSFS_swapUBE32(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_swapUBE64(lua_State *L)
{
    (void)L;
    PHYSFS_uint64 a0 = (PHYSFS_uint64)luaL_checkinteger(L, 1);
    PHYSFS_uint64 rv = PHYSFS_swapUBE64(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_swapULE16(lua_State *L)
{
    (void)L;
    PHYSFS_uint16 a0 = (PHYSFS_uint16)luaL_checkinteger(L, 1);
    PHYSFS_uint16 rv = PHYSFS_swapULE16(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_swapULE32(lua_State *L)
{
    (void)L;
    PHYSFS_uint32 a0 = (PHYSFS_uint32)luaL_checkinteger(L, 1);
    PHYSFS_uint32 rv = PHYSFS_swapULE32(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_swapULE64(lua_State *L)
{
    (void)L;
    PHYSFS_uint64 a0 = (PHYSFS_uint64)luaL_checkinteger(L, 1);
    PHYSFS_uint64 rv = PHYSFS_swapULE64(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_symbolicLinksPermitted(lua_State *L)
{
    (void)L;
    int rv = PHYSFS_symbolicLinksPermitted();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_tell(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint64 rv = PHYSFS_tell(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_unmount(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int rv = PHYSFS_unmount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_utf8ToUcs2(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    PHYSFS_uint16 io1 = (PHYSFS_uint16)luaL_optinteger(L, 2, 0);
    PHYSFS_uint64 a2 = (PHYSFS_uint64)luaL_checkinteger(L, 3);
    PHYSFS_utf8ToUcs2(a0, &io1, a2);
    lua_pushinteger(L, (lua_Integer)io1);
    return 1;
}

static int GenL_PHYSFS_utf8ToUcs4(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    PHYSFS_uint32 io1 = (PHYSFS_uint32)luaL_optinteger(L, 2, 0);
    PHYSFS_uint64 a2 = (PHYSFS_uint64)luaL_checkinteger(L, 3);
    PHYSFS_utf8ToUcs4(a0, &io1, a2);
    lua_pushinteger(L, (lua_Integer)io1);
    return 1;
}

static int GenL_PHYSFS_utf8ToUtf16(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    PHYSFS_uint16 io1 = (PHYSFS_uint16)luaL_optinteger(L, 2, 0);
    PHYSFS_uint64 a2 = (PHYSFS_uint64)luaL_checkinteger(L, 3);
    PHYSFS_utf8ToUtf16(a0, &io1, a2);
    lua_pushinteger(L, (lua_Integer)io1);
    return 1;
}

static int GenL_PHYSFS_utf8stricmp(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = PHYSFS_utf8stricmp(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeBytes(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    size_t len1 = 0;
    const char *a1 = luaL_checklstring(L, 2, &len1);
    PHYSFS_sint64 rv = PHYSFS_writeBytes(a0, (const void *)a1, (PHYSFS_uint64)len1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeSBE16(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint16 a1 = (PHYSFS_sint16)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeSBE16(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeSBE32(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint32 a1 = (PHYSFS_sint32)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeSBE32(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeSBE64(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint64 a1 = (PHYSFS_sint64)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeSBE64(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeSLE16(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint16 a1 = (PHYSFS_sint16)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeSLE16(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeSLE32(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint32 a1 = (PHYSFS_sint32)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeSLE32(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeSLE64(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_sint64 a1 = (PHYSFS_sint64)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeSLE64(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeUBE16(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint16 a1 = (PHYSFS_uint16)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeUBE16(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeUBE32(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint32 a1 = (PHYSFS_uint32)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeUBE32(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeUBE64(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint64 a1 = (PHYSFS_uint64)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeUBE64(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeULE16(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint16 a1 = (PHYSFS_uint16)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeULE16(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeULE32(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint32 a1 = (PHYSFS_uint32)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeULE32(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_PHYSFS_writeULE64(lua_State *L)
{
    (void)L;
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_LuaCheckHandle(L, 1, "PHYSFS_File");
    PHYSFS_uint64 a1 = (PHYSFS_uint64)luaL_checkinteger(L, 2);
    int rv = PHYSFS_writeULE64(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

int SDLStaticGen_OpenLua_physfs(lua_State *L);
int SDLStaticGen_OpenLua_physfs(lua_State *L)
{
    lua_createtable(L, 0, 82);
    lua_pushcfunction(L, GenL_PHYSFS_caseFold);
    lua_setfield(L, -2, "caseFold");
    lua_pushcfunction(L, GenL_PHYSFS_close);
    lua_setfield(L, -2, "close");
    lua_pushcfunction(L, GenL_PHYSFS_deinit);
    lua_setfield(L, -2, "deinit");
    lua_pushcfunction(L, GenL_PHYSFS_delete);
    lua_setfield(L, -2, "delete");
    lua_pushcfunction(L, GenL_PHYSFS_deregisterArchiver);
    lua_setfield(L, -2, "deregisterArchiver");
    lua_pushcfunction(L, GenL_PHYSFS_eof);
    lua_setfield(L, -2, "eof");
    lua_pushcfunction(L, GenL_PHYSFS_exists);
    lua_setfield(L, -2, "exists");
    lua_pushcfunction(L, GenL_PHYSFS_fileLength);
    lua_setfield(L, -2, "fileLength");
    lua_pushcfunction(L, GenL_PHYSFS_flush);
    lua_setfield(L, -2, "flush");
    lua_pushcfunction(L, GenL_PHYSFS_getAllocator);
    lua_setfield(L, -2, "getAllocator");
    lua_pushcfunction(L, GenL_PHYSFS_getBaseDir);
    lua_setfield(L, -2, "getBaseDir");
    lua_pushcfunction(L, GenL_PHYSFS_getDirSeparator);
    lua_setfield(L, -2, "getDirSeparator");
    lua_pushcfunction(L, GenL_PHYSFS_getErrorByCode);
    lua_setfield(L, -2, "getErrorByCode");
    lua_pushcfunction(L, GenL_PHYSFS_getLastErrorCode);
    lua_setfield(L, -2, "getLastErrorCode");
    lua_pushcfunction(L, GenL_PHYSFS_getLinkedVersion);
    lua_setfield(L, -2, "getLinkedVersion");
    lua_pushcfunction(L, GenL_PHYSFS_getMountPoint);
    lua_setfield(L, -2, "getMountPoint");
    lua_pushcfunction(L, GenL_PHYSFS_getPrefDir);
    lua_setfield(L, -2, "getPrefDir");
    lua_pushcfunction(L, GenL_PHYSFS_getRealDir);
    lua_setfield(L, -2, "getRealDir");
    lua_pushcfunction(L, GenL_PHYSFS_getWriteDir);
    lua_setfield(L, -2, "getWriteDir");
    lua_pushcfunction(L, GenL_PHYSFS_init);
    lua_setfield(L, -2, "init");
    lua_pushcfunction(L, GenL_PHYSFS_isInit);
    lua_setfield(L, -2, "isInit");
    lua_pushcfunction(L, GenL_PHYSFS_mkdir);
    lua_setfield(L, -2, "mkdir");
    lua_pushcfunction(L, GenL_PHYSFS_mount);
    lua_setfield(L, -2, "mount");
    lua_pushcfunction(L, GenL_PHYSFS_mountHandle);
    lua_setfield(L, -2, "mountHandle");
    lua_pushcfunction(L, GenL_PHYSFS_mountIo);
    lua_setfield(L, -2, "mountIo");
    lua_pushcfunction(L, GenL_PHYSFS_openAppend);
    lua_setfield(L, -2, "openAppend");
    lua_pushcfunction(L, GenL_PHYSFS_openRead);
    lua_setfield(L, -2, "openRead");
    lua_pushcfunction(L, GenL_PHYSFS_openWrite);
    lua_setfield(L, -2, "openWrite");
    lua_pushcfunction(L, GenL_PHYSFS_permitSymbolicLinks);
    lua_setfield(L, -2, "permitSymbolicLinks");
    lua_pushcfunction(L, GenL_PHYSFS_readSBE16);
    lua_setfield(L, -2, "readSBE16");
    lua_pushcfunction(L, GenL_PHYSFS_readSBE32);
    lua_setfield(L, -2, "readSBE32");
    lua_pushcfunction(L, GenL_PHYSFS_readSBE64);
    lua_setfield(L, -2, "readSBE64");
    lua_pushcfunction(L, GenL_PHYSFS_readSLE16);
    lua_setfield(L, -2, "readSLE16");
    lua_pushcfunction(L, GenL_PHYSFS_readSLE32);
    lua_setfield(L, -2, "readSLE32");
    lua_pushcfunction(L, GenL_PHYSFS_readSLE64);
    lua_setfield(L, -2, "readSLE64");
    lua_pushcfunction(L, GenL_PHYSFS_readUBE16);
    lua_setfield(L, -2, "readUBE16");
    lua_pushcfunction(L, GenL_PHYSFS_readUBE32);
    lua_setfield(L, -2, "readUBE32");
    lua_pushcfunction(L, GenL_PHYSFS_readUBE64);
    lua_setfield(L, -2, "readUBE64");
    lua_pushcfunction(L, GenL_PHYSFS_readULE16);
    lua_setfield(L, -2, "readULE16");
    lua_pushcfunction(L, GenL_PHYSFS_readULE32);
    lua_setfield(L, -2, "readULE32");
    lua_pushcfunction(L, GenL_PHYSFS_readULE64);
    lua_setfield(L, -2, "readULE64");
    lua_pushcfunction(L, GenL_PHYSFS_registerArchiver);
    lua_setfield(L, -2, "registerArchiver");
    lua_pushcfunction(L, GenL_PHYSFS_seek);
    lua_setfield(L, -2, "seek");
    lua_pushcfunction(L, GenL_PHYSFS_setAllocator);
    lua_setfield(L, -2, "setAllocator");
    lua_pushcfunction(L, GenL_PHYSFS_setBuffer);
    lua_setfield(L, -2, "setBuffer");
    lua_pushcfunction(L, GenL_PHYSFS_setErrorCode);
    lua_setfield(L, -2, "setErrorCode");
    lua_pushcfunction(L, GenL_PHYSFS_setRoot);
    lua_setfield(L, -2, "setRoot");
    lua_pushcfunction(L, GenL_PHYSFS_setSaneConfig);
    lua_setfield(L, -2, "setSaneConfig");
    lua_pushcfunction(L, GenL_PHYSFS_setWriteDir);
    lua_setfield(L, -2, "setWriteDir");
    lua_pushcfunction(L, GenL_PHYSFS_stat);
    lua_setfield(L, -2, "stat");
    lua_pushcfunction(L, GenL_PHYSFS_swapSBE16);
    lua_setfield(L, -2, "swapSBE16");
    lua_pushcfunction(L, GenL_PHYSFS_swapSBE32);
    lua_setfield(L, -2, "swapSBE32");
    lua_pushcfunction(L, GenL_PHYSFS_swapSBE64);
    lua_setfield(L, -2, "swapSBE64");
    lua_pushcfunction(L, GenL_PHYSFS_swapSLE16);
    lua_setfield(L, -2, "swapSLE16");
    lua_pushcfunction(L, GenL_PHYSFS_swapSLE32);
    lua_setfield(L, -2, "swapSLE32");
    lua_pushcfunction(L, GenL_PHYSFS_swapSLE64);
    lua_setfield(L, -2, "swapSLE64");
    lua_pushcfunction(L, GenL_PHYSFS_swapUBE16);
    lua_setfield(L, -2, "swapUBE16");
    lua_pushcfunction(L, GenL_PHYSFS_swapUBE32);
    lua_setfield(L, -2, "swapUBE32");
    lua_pushcfunction(L, GenL_PHYSFS_swapUBE64);
    lua_setfield(L, -2, "swapUBE64");
    lua_pushcfunction(L, GenL_PHYSFS_swapULE16);
    lua_setfield(L, -2, "swapULE16");
    lua_pushcfunction(L, GenL_PHYSFS_swapULE32);
    lua_setfield(L, -2, "swapULE32");
    lua_pushcfunction(L, GenL_PHYSFS_swapULE64);
    lua_setfield(L, -2, "swapULE64");
    lua_pushcfunction(L, GenL_PHYSFS_symbolicLinksPermitted);
    lua_setfield(L, -2, "symbolicLinksPermitted");
    lua_pushcfunction(L, GenL_PHYSFS_tell);
    lua_setfield(L, -2, "tell");
    lua_pushcfunction(L, GenL_PHYSFS_unmount);
    lua_setfield(L, -2, "unmount");
    lua_pushcfunction(L, GenL_PHYSFS_utf8ToUcs2);
    lua_setfield(L, -2, "utf8ToUcs2");
    lua_pushcfunction(L, GenL_PHYSFS_utf8ToUcs4);
    lua_setfield(L, -2, "utf8ToUcs4");
    lua_pushcfunction(L, GenL_PHYSFS_utf8ToUtf16);
    lua_setfield(L, -2, "utf8ToUtf16");
    lua_pushcfunction(L, GenL_PHYSFS_utf8stricmp);
    lua_setfield(L, -2, "utf8stricmp");
    lua_pushcfunction(L, GenL_PHYSFS_writeBytes);
    lua_setfield(L, -2, "writeBytes");
    lua_pushcfunction(L, GenL_PHYSFS_writeSBE16);
    lua_setfield(L, -2, "writeSBE16");
    lua_pushcfunction(L, GenL_PHYSFS_writeSBE32);
    lua_setfield(L, -2, "writeSBE32");
    lua_pushcfunction(L, GenL_PHYSFS_writeSBE64);
    lua_setfield(L, -2, "writeSBE64");
    lua_pushcfunction(L, GenL_PHYSFS_writeSLE16);
    lua_setfield(L, -2, "writeSLE16");
    lua_pushcfunction(L, GenL_PHYSFS_writeSLE32);
    lua_setfield(L, -2, "writeSLE32");
    lua_pushcfunction(L, GenL_PHYSFS_writeSLE64);
    lua_setfield(L, -2, "writeSLE64");
    lua_pushcfunction(L, GenL_PHYSFS_writeUBE16);
    lua_setfield(L, -2, "writeUBE16");
    lua_pushcfunction(L, GenL_PHYSFS_writeUBE32);
    lua_setfield(L, -2, "writeUBE32");
    lua_pushcfunction(L, GenL_PHYSFS_writeUBE64);
    lua_setfield(L, -2, "writeUBE64");
    lua_pushcfunction(L, GenL_PHYSFS_writeULE16);
    lua_setfield(L, -2, "writeULE16");
    lua_pushcfunction(L, GenL_PHYSFS_writeULE32);
    lua_setfield(L, -2, "writeULE32");
    lua_pushcfunction(L, GenL_PHYSFS_writeULE64);
    lua_setfield(L, -2, "writeULE64");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ENUM_ERROR);
    lua_setfield(L, -2, "ENUM_ERROR");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ENUM_STOP);
    lua_setfield(L, -2, "ENUM_STOP");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ENUM_OK);
    lua_setfield(L, -2, "ENUM_OK");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_OK);
    lua_setfield(L, -2, "ERR_OK");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_OTHER_ERROR);
    lua_setfield(L, -2, "ERR_OTHER_ERROR");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_OUT_OF_MEMORY);
    lua_setfield(L, -2, "ERR_OUT_OF_MEMORY");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_NOT_INITIALIZED);
    lua_setfield(L, -2, "ERR_NOT_INITIALIZED");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_IS_INITIALIZED);
    lua_setfield(L, -2, "ERR_IS_INITIALIZED");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_ARGV0_IS_NULL);
    lua_setfield(L, -2, "ERR_ARGV0_IS_NULL");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_UNSUPPORTED);
    lua_setfield(L, -2, "ERR_UNSUPPORTED");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_PAST_EOF);
    lua_setfield(L, -2, "ERR_PAST_EOF");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_FILES_STILL_OPEN);
    lua_setfield(L, -2, "ERR_FILES_STILL_OPEN");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_INVALID_ARGUMENT);
    lua_setfield(L, -2, "ERR_INVALID_ARGUMENT");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_NOT_MOUNTED);
    lua_setfield(L, -2, "ERR_NOT_MOUNTED");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_NOT_FOUND);
    lua_setfield(L, -2, "ERR_NOT_FOUND");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_SYMLINK_FORBIDDEN);
    lua_setfield(L, -2, "ERR_SYMLINK_FORBIDDEN");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_NO_WRITE_DIR);
    lua_setfield(L, -2, "ERR_NO_WRITE_DIR");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_OPEN_FOR_READING);
    lua_setfield(L, -2, "ERR_OPEN_FOR_READING");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_OPEN_FOR_WRITING);
    lua_setfield(L, -2, "ERR_OPEN_FOR_WRITING");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_NOT_A_FILE);
    lua_setfield(L, -2, "ERR_NOT_A_FILE");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_READ_ONLY);
    lua_setfield(L, -2, "ERR_READ_ONLY");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_CORRUPT);
    lua_setfield(L, -2, "ERR_CORRUPT");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_SYMLINK_LOOP);
    lua_setfield(L, -2, "ERR_SYMLINK_LOOP");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_IO);
    lua_setfield(L, -2, "ERR_IO");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_PERMISSION);
    lua_setfield(L, -2, "ERR_PERMISSION");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_NO_SPACE);
    lua_setfield(L, -2, "ERR_NO_SPACE");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_BAD_FILENAME);
    lua_setfield(L, -2, "ERR_BAD_FILENAME");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_BUSY);
    lua_setfield(L, -2, "ERR_BUSY");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_DIR_NOT_EMPTY);
    lua_setfield(L, -2, "ERR_DIR_NOT_EMPTY");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_OS_ERROR);
    lua_setfield(L, -2, "ERR_OS_ERROR");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_DUPLICATE);
    lua_setfield(L, -2, "ERR_DUPLICATE");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_BAD_PASSWORD);
    lua_setfield(L, -2, "ERR_BAD_PASSWORD");
    lua_pushinteger(L, (lua_Integer)PHYSFS_ERR_APP_CALLBACK);
    lua_setfield(L, -2, "ERR_APP_CALLBACK");
    lua_pushinteger(L, (lua_Integer)PHYSFS_FILETYPE_REGULAR);
    lua_setfield(L, -2, "FILETYPE_REGULAR");
    lua_pushinteger(L, (lua_Integer)PHYSFS_FILETYPE_DIRECTORY);
    lua_setfield(L, -2, "FILETYPE_DIRECTORY");
    lua_pushinteger(L, (lua_Integer)PHYSFS_FILETYPE_SYMLINK);
    lua_setfield(L, -2, "FILETYPE_SYMLINK");
    lua_pushinteger(L, (lua_Integer)PHYSFS_FILETYPE_OTHER);
    lua_setfield(L, -2, "FILETYPE_OTHER");
    lua_setglobal(L, "PHYSFS");
    return 0;
}
