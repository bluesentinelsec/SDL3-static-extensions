---
title: Getting Started
description: "Consume SDL3 Static Extensions from CMake with FetchContent, build the repo and its tests, and open your first window."
---

# Getting Started

## Requirements

- CMake 3.20+ and a C17/C++17 toolchain (clang, gcc, or MSVC)
- No other dependencies: every library, codec, and language runtime is
  vendored source

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

## Try the REPL

An interactive REPL for both embedded languages builds with the tree:

```bash
./build/debug/bin/repl -l lua
> SDL.GetPlatform()
./build/debug/bin/repl -l ruby
> SDL.GetPlatform
```

## Where to go next

- [Modules](modules.html) — what each `SDLStatic::*` target gives you
- [C++ bindings](cpp.html) — RAII, `Status`/`Result`, no exceptions
- [Lua &amp; Ruby](scripting.html) — embedded scripting, require-from-zip
- [Platforms](platforms.html) — Android, iOS, and WebAssembly specifics
