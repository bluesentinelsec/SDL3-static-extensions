/*
 * sdlstatic_lua.c — Lua state helper + VFS package searcher.
 *
 * Original SDLStatic code (zlib). SDLStatic_CreateLuaState opens the
 * standard libraries and installs a package searcher that resolves
 * require("game.enemies") to "game/enemies.lua" inside the PhysFS VFS
 * (when initialized) — so script modules can live in a mounted, optionally
 * encrypted, zip archive. Falls back to Lua's normal searchers otherwise.
 */
#include <SDLStatic/lua.h>
#include <SDLStatic/vfs.h>
#include <physfs.h>

#include <lauxlib.h>
#include <lualib.h>

static int VfsSearcher(lua_State *L)
{
    const char *name = luaL_checkstring(L, 1);
    if (!PHYSFS_isInit())
    {
        lua_pushfstring(L, "\n\tVFS not initialized");
        return 1;
    }
    char path[512];
    size_t at = 0;
    for (const char *p = name; *p != '\0' && at + 6 < sizeof(path); ++p)
    {
        path[at++] = (*p == '.') ? '/' : *p;
    }
    path[at] = '\0';
    SDL_strlcat(path, ".lua", sizeof(path));

    int size = 0;
    unsigned char *data = SDLStatic_LoadVFSFile(path, &size);
    if (data == NULL)
    {
        lua_pushfstring(L, "\n\tno VFS file '%s'", path);
        return 1;
    }
    const int rc =
        luaL_loadbuffer(L, (const char *)data, (size_t)size, lua_pushfstring(L, "@vfs:%s", path));
    SDL_free(data);
    if (rc != LUA_OK)
    {
        return lua_error(L);
    }
    lua_pushfstring(L, "vfs:%s", path); /* second return: loader data */
    return 2;
}

lua_State *SDLStatic_CreateLuaState(void)
{
    lua_State *L = luaL_newstate();
    if (L == NULL)
    {
        SDL_SetError("luaL_newstate failed");
        return NULL;
    }
    luaL_openlibs(L);

    /* Insert the VFS searcher after the preload searcher (position 2). */
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "searchers");
    const lua_Integer count = luaL_len(L, -1);
    for (lua_Integer i = count; i >= 2; --i)
    {
        lua_geti(L, -1, i);
        lua_seti(L, -2, i + 1);
    }
    lua_pushcfunction(L, VfsSearcher);
    lua_seti(L, -2, 2);
    lua_pop(L, 2);
    return L;
}

bool SDLStatic_LuaRunVFSScript(lua_State *L, const char *vfsPath)
{
    if (L == NULL || vfsPath == NULL)
    {
        return SDL_InvalidParamError("L/vfsPath");
    }
    int size = 0;
    unsigned char *data = SDLStatic_LoadVFSFile(vfsPath, &size);
    if (data == NULL)
    {
        return false;
    }
    char chunkname[512];
    SDL_snprintf(chunkname, sizeof(chunkname), "@vfs:%s", vfsPath);
    const int rc = luaL_loadbuffer(L, (const char *)data, (size_t)size, chunkname);
    SDL_free(data);
    if (rc != LUA_OK || lua_pcall(L, 0, 0, 0) != LUA_OK)
    {
        SDL_SetError("%s", lua_tostring(L, -1));
        lua_pop(L, 1);
        return false;
    }
    return true;
}
