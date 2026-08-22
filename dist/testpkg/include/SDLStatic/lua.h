/**
 * @file lua.h
 * @brief Lua state helper + VFS-aware require (SDLStatic Lua).
 *
 * Original SDLStatic code (zlib) around vendored Lua 5.4.8. Use the full
 * native Lua C API (<lua.h>, <lauxlib.h>, <lualib.h>) for everything else.
 */
#ifndef SDLSTATIC_LUA_H
#define SDLSTATIC_LUA_H

#include <SDL3/SDL.h>

/* Lua's own headers lack extern "C" guards; provide them for C++ users. */
#ifdef __cplusplus
extern "C" {
#endif
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

/**
 * New Lua state with the standard libraries plus a package searcher that
 * resolves require("a.b") to "a/b.lua" inside the PhysFS VFS when it is
 * initialized (mounted zip archives, encrypted or not), before falling
 * back to the normal filesystem searchers. Close with lua_close().
 */
extern lua_State *SDLStatic_CreateLuaState(void);

/** Load and run a script from the mounted VFS. False + SDL_GetError on
 *  load or runtime error. */
extern bool SDLStatic_LuaRunVFSScript(lua_State *L, const char *vfsPath);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_LUA_H */
