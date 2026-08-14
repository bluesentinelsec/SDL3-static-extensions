/**
 * @file bindings.h
 * @brief Game-surface script bindings for Lua and Ruby (SDLStatic).
 *
 * Original SDLStatic code (zlib). Installs a `SDLStatic` module exposing
 * the same API in both languages — windows/rendering, textures (VFS-aware
 * loading), audio playback, Box2D physics, VFS mounts (incl. encrypted),
 * and the crypto/compress/base64 utilities. Every native object is an
 * opaque handle finalized by the language's garbage collector; child
 * handles pin their parents so collection order is always safe.
 *
 *   local app  = SDLStatic.window("Game", 640, 360)     -- Lua
 *   app  = SDLStatic.window("Game", 640, 360)           #  Ruby
 *
 * See bindings/README.md for the full surface.
 */
#ifndef SDLSTATIC_BINDINGS_H
#define SDLSTATIC_BINDINGS_H

#include <SDL3/SDL.h>
#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif
#include <lua.h>

/** Install the `SDLStatic` global table into a Lua state. */
extern bool SDLStatic_OpenLuaBindings(lua_State *L);

/** Install the `SDLStatic` module into an mruby state. */
extern bool SDLStatic_OpenRubyBindings(mrb_state *mrb);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_BINDINGS_H */
