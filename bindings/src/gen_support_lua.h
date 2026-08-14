/*
 * gen_support_lua.h — marshaling runtime for the GENERATED Lua bindings.
 * Hand-written support code (original SDLStatic, zlib); the generated
 * per-library stub files in bindings/generated/ include this.
 *
 * Handle model: every C object pointer crossing into Lua is boxed in a
 * full userdata carrying the pointer, its C type name, and (for owned
 * handles) a destructor. __gc destroys owned handles exactly once;
 * explicitly bound destroy functions take the pointer out of the box
 * first, so explicit destruction and GC never double-free.
 */
#ifndef SDLSTATIC_GEN_SUPPORT_LUA_H
#define SDLSTATIC_GEN_SUPPORT_LUA_H

#include <SDLStatic/lua.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*SDLStaticGen_Dtor)(void *ptr);

typedef struct SDLStaticGen_Handle
{
    void *ptr;
    const char *ctype;        /* static string, compared by strcmp */
    SDLStaticGen_Dtor dtor;   /* NULL for borrowed handles */
} SDLStaticGen_Handle;

/** Push a borrowed pointer (no GC). NULL pushes nil. */
extern void SDLStaticGen_LuaPushHandle(lua_State *L, void *ptr, const char *ctype);

/** Push an owned pointer; __gc will call dtor unless taken first. */
extern void SDLStaticGen_LuaPushOwned(lua_State *L, void *ptr, const char *ctype,
                                      SDLStaticGen_Dtor dtor);

/** Read a handle argument: our userdata of the right ctype, or nil -> NULL.
 *  Raises a Lua type error otherwise. */
extern void *SDLStaticGen_LuaCheckHandle(lua_State *L, int idx, const char *ctype);

/** Read a handle and clear the box (ownership leaves Lua). Used by bound
 *  destroy functions so a later __gc is a no-op. */
extern void *SDLStaticGen_LuaTakeHandle(lua_State *L, int idx, const char *ctype);

/** Table-field helpers used by generated POD converters. */
extern lua_Integer SDLStaticGen_LuaFieldInt(lua_State *L, int idx, const char *field);
extern lua_Number SDLStaticGen_LuaFieldNum(lua_State *L, int idx, const char *field);
extern int SDLStaticGen_LuaFieldBool(lua_State *L, int idx, const char *field);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_GEN_SUPPORT_LUA_H */
