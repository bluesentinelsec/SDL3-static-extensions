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

### The script signature is not always the C signature

Check
[`SCRIPT_API.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/bindings/generated/SCRIPT_API.md)
— it lists every bound function with the signature the *script* sees.
Three rules make it differ from C:

- A `(const void *data, size_t len)` pair collapses into **one** string
  argument, so everything after it shifts left:
  `SDLStatic_CreateGui(renderer, data, len, font_size)` is
  `SDLStaticC.CreateGui(renderer, data, font_size)`. Passing a spurious
  length lands in `font_size` — the call still succeeds, just with the
  wrong value.
- Pure out-parameters are not arguments; they come back as extra returns.
- In/out parameters are passed *and* returned.

Functions that cannot cross a script boundary (callbacks, varargs,
threading) are skipped **with the reason recorded** in
[`COVERAGE.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/bindings/generated/COVERAGE.md).

## The GPU API from a script

SDL's GPU API is bound in full — device, pipelines, passes, buffers,
shaders. Getting there took more than binding the functions, because most
of them take a *descriptor struct* that a C caller fills in on the stack,
and a script has no stack to put one on. Every one of those calls was
reachable and inert.

So the descriptors get heap builders, in the `SDLStaticC` module, the same
shape used for `SDL_Event` and the Box2D joint definitions: create, set,
pass to SDL, destroy.

```lua
local target = SDLStaticC.GPUColorTargetInfoCreate()
SDLStaticC.GPUColorTargetInfoSetTexture(target, swapchain)
SDLStaticC.GPUColorTargetInfoSetClearColor(target, 0.1, 0.1, 0.15, 1.0)
SDLStaticC.GPUColorTargetInfoSetOps(target, SDL.GPU_LOADOP_CLEAR,
                                    SDL.GPU_STOREOP_STORE)

local pass = SDL.BeginGPURenderPass(cmd, target, 1, nil)
SDL.BindGPUGraphicsPipeline(pass, pipeline)
SDL.DrawGPUPrimitives(pass, 3, 1, 0, 0)
SDL.EndGPURenderPass(pass)

SDLStaticC.GPUColorTargetInfoDestroy(target)
```

Where a descriptor holds an **array** — the vertex buffers, vertex
attributes and colour targets of a pipeline — the builder appends instead
of setting, and owns the storage it grows:

```lua
local pipeline = SDLStaticC.GPUPipelineInfoCreate()
SDLStaticC.GPUPipelineInfoSetShaders(pipeline, vertex_shader, fragment_shader)
SDLStaticC.GPUPipelineInfoAddVertexBuffer(pipeline, 0, 20,
                                          SDL.GPU_VERTEXINPUTRATE_VERTEX)
SDLStaticC.GPUPipelineInfoAddVertexAttribute(pipeline, 0, 0,
                                             SDL.GPU_VERTEXELEMENTFORMAT_FLOAT3, 0)
SDLStaticC.GPUPipelineInfoAddVertexAttribute(pipeline, 1, 0,
                                             SDL.GPU_VERTEXELEMENTFORMAT_FLOAT2, 12)
SDLStaticC.GPUPipelineInfoAddColorTarget(pipeline,
                                         SDL.GetGPUSwapchainTextureFormat(device, window))
local handle = SDL.CreateGPUGraphicsPipeline(device, pipeline)
SDLStaticC.GPUPipelineInfoDestroy(pipeline)   -- the descriptor, not the pipeline
```

### Four calls that needed wrappers

A handful of GPU functions cannot be bound as they stand, because they
pass data through pointers a script cannot make. Each has a wrapper that
does the same work in one call:

| Instead of | Call | Why |
|---|---|---|
| `SDL_AcquireGPUSwapchainTexture` | `SDLStaticC.GPUAcquireSwapchain(cmd, window)` | returns the texture rather than filling an `SDL_GPUTexture **`; size via `GPUSwapchainWidth/Height`. A `nil` texture means *not ready this frame* — skip the frame, do not stop. There is a `GPUWaitAndAcquireSwapchain` too. |
| `SDL_MapGPUTransferBuffer` | `SDLStaticC.GPUUploadToTransferBuffer(device, buffer, offset, bytes, cycle)` | maps, copies and unmaps together. The map returns a raw `void *`, which is the one thing a script cannot hold. `GPUReadTransferBuffer` reads back. |
| `SDL_BindGPU*StorageBuffers` | `SDLStaticC.GPUBindVertexStorageBuffer(pass, slot, buffer)` and friends | SDL takes an array of pointers; these bind one slot, which is what nearly every call site does. |
| `SDL_BeginGPUComputePass` | `SDLStaticC.GPUBeginComputePass(cmd, bindings)` | its two read-write binding arrays come from `GPUComputeBindingsCreate` + `AddBuffer`/`AddTexture`. |
| `SDL_WaitForGPUFences` | `SDLStaticC.GPUWaitForFence(device, fence)` | the array form, for the single fence almost everyone has. |

Vertex data crosses as a string of bytes, which is what `(const void *,
int)` collapses to everywhere else in the bindings — `string.pack("fff",
x, y, z)` in Lua, `[x, y, z].pack("f*")` in Ruby.

Shaders are your problem, as they are in C: SDL takes compiled bytecode,
so ship SPIR-V, DXIL and MSL for the backends you support and pick with
`SDL_GetGPUShaderFormats`.

## Regular expressions

Neither language brings usable regular expressions of its own: mruby ships
no engine at all, so `Regexp` simply does not exist in stock mruby, and
Lua has patterns, which have no alternation, quantified groups or
lookaround. [`SDLStatic::Regex`](regex.html) supplies one engine for both.

In Ruby it arrives as the real class, so literals, `$1` and `$~` work —
mruby's compiler already emits code for them, it was only the class that
was missing:

```ruby
"on 2026-08-14".match(/(?<year>\d{4})/)["year"]   # => "2026"
"a1b2".gsub(/\d/) { |d| d.to_i * 2 }              # => "a2b4"
```

In Lua it is an added `Regex` module; Lua's own patterns are untouched:

```lua
for m in Regex.new("\\d+"):gmatch("a1b22") do print(m[0]) end
```

Both are linked in by `SDLStatic::Bindings`, so nothing extra is needed.
See [Regex](regex.html) for the full surface and its limits.

## The REPL

`tools/repl` builds an interactive shell for both languages with all
bindings loaded:

```bash
./build/debug/bin/repl -l lua
./build/debug/bin/repl -l ruby
```
