---
title: Getting Started
description: "Consume SDL3 Static Extensions from CMake with FetchContent, build the repo and its tests, and open your first window."
---

# Getting Started

## Requirements

- CMake 3.20+ and a C17/C++17 toolchain (clang, gcc, or MSVC)
- No other dependencies: every library, codec, and language runtime is
  vendored source

## Two ways in, and the one you want depends on how you build

**From source, with FetchContent** — you are already using CMake and want
the library built with your own flags and toolchain. Link the individual
modules; this is the section below.

**From a release, with `find_package`** — you want to download something
and link it. The release SDK is one archive containing every module *and
SDL3 itself*, so the link line is one library:

```cmake
cmake_minimum_required(VERSION 3.20)
project(my_game C)

find_package(SDL3-static-extensions REQUIRED)

add_executable(my_game main.c)
target_link_libraries(my_game PRIVATE SDL3-static-extensions::SDK)
```

```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH=/path/to/unpacked/sdk
```

Nothing else is needed: no separate SDL3, no per-module list, no link
order to get right — the objects are in one archive, where order does not
exist. The system libraries each platform requires (frameworks on macOS,
`user32` and friends on Windows) come with the package.

The archive contains C++ objects, so a C-only project links the C++
runtime through the package. If your build reports a duplicate `-lc++`,
that is why, and it is harmless.

The same layout comes out of `cmake --install`, so an installed prefix and
an unpacked release SDK are interchangeable.

## Consume from your game (FetchContent)

```cmake
cmake_minimum_required(VERSION 3.20)
project(my_game C)

include(FetchContent)
FetchContent_Declare(SDL3_static_extensions
  GIT_REPOSITORY https://github.com/bluesentinelsec/SDL3-static-extensions.git
  GIT_TAG        v0.2.0)
FetchContent_MakeAvailable(SDL3_static_extensions)

add_executable(my_game main.c)
target_link_libraries(my_game PRIVATE
  SDL3::SDL3
  SDLStatic::Mixer
  SDLStatic::Gfx
  SDLStatic::Extras)
```

Link only what you use — each module is its own static library. The full
target list is on the [Modules](modules.html) page. Modules you do not
link cost you nothing at runtime; modules you do link are compiled into
your executable with no shared-library footprint.

To trim configure/compile time you can switch off whole modules:

```cmake
set(SDLSTATIC_BUILD_GUI OFF)      # before MakeAvailable
set(SDLSTATIC_BUILD_RUBY OFF)
```

Everything is `ON` by default. Some options imply others (the C++ and
script bindings need the modules they wrap); CMake will tell you exactly
which switch to flip if a combination cannot work.

## First window

```c
#include <SDL3/SDL.h>

int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_CreateWindowAndRenderer("my_game", 640, 480, 0, &window, &renderer);

    bool running = true;
    while (running)
    {
        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
            if (ev.type == SDL_EVENT_QUIT) { running = false; }
        }
        SDL_SetRenderDrawColor(renderer, 24, 24, 32, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
```

Prefer C++? The same program with RAII lifetimes and no manual destroys is
on the [C++ page](cpp.html). Prefer a scripting language? The
[Lua &amp; Ruby page](scripting.html) shows the same loop in both.

## Build the repository itself

```bash
git clone https://github.com/bluesentinelsec/SDL3-static-extensions.git
cd SDL3-static-extensions
cmake -B build/debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build/debug --parallel
ctest --test-dir build/debug
```

The first configure downloads SDL3 and its satellites (pinned versions)
via FetchContent; everything after that is offline.

## Run a script, or open a REPL

The runner builds with the tree and ships in the release SDK's `bin/`. It
is statically linked like everything else here — it carries both
interpreters and the whole engine, so it needs nothing installed on the
machine.

Point it at a script and it runs it. The language comes from the
extension, so there is nothing to remember:

```bash
./build/debug/bin/repl game.lua
./build/debug/bin/repl game.rb
```

With no script, it is an interactive REPL, and `-l` says which language
when there is no file to infer it from:

```bash
./build/debug/bin/repl -l lua
> SDL.GetPlatform()
./build/debug/bin/repl -l ruby
> SDL.GetPlatform
```

A script has the whole surface loaded — SDL3, the engine, the bindings —
so it can drive the opinionated loop or write its own. See
[Scripting](scripting.html).

## Where to go next

- [Modules](modules.html) — what each `SDLStatic::*` target gives you
- [C++ bindings](cpp.html) — RAII, `Status`/`Result`, no exceptions
- [Lua &amp; Ruby](scripting.html) — embedded scripting, require-from-zip
- [Platforms](platforms.html) — Android, iOS, and WebAssembly specifics
- [Platform matrix](platforms-matrix.html) — which components build where, and what each platform ships
