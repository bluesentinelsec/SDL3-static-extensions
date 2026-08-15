---
title: Lua & Ruby
description: "Embedded Lua 5.4 and mruby with require-from-zip, a curated game API, a generated mirror of the whole C API, and a REPL."
---

# Lua &amp; Ruby scripting

Two embedded languages, compiled into the binary like everything else:
**Lua 5.4.8** (`SDLStatic::Lua`) and **mruby 4.0.0** (`SDLStatic::Ruby`).
`SDLStatic::Bindings` adds the game API to both.

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Bindings)
```

```c
lua_State *L = SDLStatic_CreateLuaState();
SDLStatic_OpenLuaBindings(L);

mrb_state *mrb = SDLStatic_CreateRubyState();
SDLStatic_OpenRubyBindings(mrb);
```

## Modules load from your asset archive

Both runtimes resolve `require` (Lua) and `require` (Ruby) through the
[VFS](vfs.html): scripts ship inside the same mounted — optionally
encrypted — zip as the rest of the game. Ruby's `require` is
CRuby-faithful (`$LOAD_PATH`, `$LOADED_FEATURES`, circular-require
guard) and loads both `.rb` source and precompiled `.mrb` bytecode.

## The curated game API

A hand-written `SDLStatic` module, identical in both languages, covers
the game loop: window/renderer, draw primitives, texture loading, input,
audio, physics world/body, VFS mounting, tile maps, compression, crypto,
base64. This is the layer the Lua and Ruby Pong implementations use:

```lua
SDLStatic.window("pong", 640, 480)
SDLStatic.load_texture("/assets/ball.png")
local map = SDLStatic.load_map("/assets/level.tmj")
local w, h, tw, th = map:size()
```

```ruby
SDLStatic.window("pong", 640, 480)
map = SDLStatic.load_map("/assets/level.tmj")
w, h, tw, th = map.size
```

Objects are garbage-collected safely: opaque handles carry their
destructor, and parent references are pinned so a mixer can never be
collected before its tracks.

## The generated flat API — the whole C surface

Beyond the curated layer, generated bindings mirror the **entire C API**
of every module into flat namespaces with C names minus prefixes — the
same 2,300+ functions in each language, plus enum constants:

```lua
local s = SDL.CreateSurface(64, 48, SDL.PIXELFORMAT_RGBA8888)
local d = JSON.Parse('{"hp": 100}')
local w = B2.CreateWorld(B2.DefaultWorldDef())
B2.World_Step(w, 1/60, 4)
local c = NK.rgb(255, 128, 0)      -- POD structs marshal as tables
```

```ruby
s = SDL.CreateSurface(64, 48, SDL::PIXELFORMAT_RGBA8888)
d = JSON.Parse('{"hp": 100}')
w = B2.CreateWorld(B2.DefaultWorldDef)
B2.World_Step(w, 1.0 / 60.0, 4)
```

Modules: `SDL`, `MIX`, `IMG`, `TTF`, `NET`, `PHYSFS`, `B2`, `NK`,
`GFX`, `TOML`, `YAML`, `MOG` (HTTP), `JSON`, `SDLStaticC`. Ownership is GC-safe by construction: pointers
returned by create functions are destroyed by the GC exactly once, and
calling the explicit destroy function first is also safe (never a
double-free). Out-parameters become extra return values; structs marshal
as tables/hashes.

### Constants, not magic numbers

Enum values *and* integer `#define` constants are registered by name with
the library prefix stripped, so scripts never hardcode numbers:

```lua
SDL.Init(SDL.INIT_VIDEO)
SDL.CreateWindow("game", 1280, 720, SDL.WINDOW_FULLSCREEN | SDL.WINDOW_HIGH_PIXEL_DENSITY)
if SDLStaticC.GuiKeyPressed(gui, SDL.SCANCODE_ESCAPE) then quit() end
```

```ruby
SDL.Init(SDL::INIT_VIDEO)
SDL.CreateWindow('game', 1280, 720, SDL::WINDOW_FULLSCREEN | SDL::WINDOW_HIGH_PIXEL_DENSITY)
```

Nuklear's constants keep their `NK_` spelling (`NK.NK_WINDOW_TITLE`)
because its prefix is lowercase `nk_`. Each constant is emitted behind an
`#ifdef`, so anything a platform doesn't define simply isn't registered.

Functions that cannot cross a script boundary (callbacks, varargs,
threading) are skipped **with the reason recorded** in
[`COVERAGE.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/bindings/generated/COVERAGE.md).

## The REPL

`tools/repl` builds an interactive shell for both languages with all
bindings loaded:

```bash
./build/debug/bin/repl -l lua
./build/debug/bin/repl -l ruby
```
