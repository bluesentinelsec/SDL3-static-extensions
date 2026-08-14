---
title: Modules
description: "Every SDLStatic module: CMake target, what it provides, and what is vendored underneath."
---

# Modules

Every module is a static library with a `SDLStatic::` CMake alias target.
Link what you need; each page below covers the API surface, examples, and
the exact upstream provenance. Deeper reference material lives with the
code in each module's `README.md` and in the [`deps/`
ledgers](https://github.com/bluesentinelsec/SDL3-static-extensions/tree/main/deps),
which record every vendored version, checksum, deletion, and local fix.

| Target | Page | Provides |
|--------|------|----------|
| `SDLStatic::Mixer` | [Mixer](mixer.html) | audio mixing, music, sound effects, MIDI, chiptune synthesis |
| `SDLStatic::Gfx` | [Gfx](gfx.html) | CPU drawing primitives, rotozoom, framerate manager, GPU-batched primitives |
| `SDLStatic::Image` | [Image](image.html) | loading/saving 13 image formats, animations |
| `SDLStatic::TTF` | [TTF](ttf.html) | TrueType/OpenType rendering, complex-script shaping (HarfBuzz), BiDi (SheenBidi) |
| `SDLStatic::Net` | [Net](net.html) | TCP/UDP sockets (SDL3_net) |
| `mog::mog` | [HTTP/S](http.html) | HTTP/S client (mog), statically linked |
| `SDLStatic::Physics` | [Physics](physics.html) | Box2D v3 rigid-body physics |
| `SDLStatic::GUI` | [GUI](gui.html) | Nuklear immediate-mode GUI, SDL3 backend, grid layout |
| `SDLStatic::Tiled` | [Tiled](tiled.html) | Tiled map (.tmj) parsing, VFS-aware |
| `SDLStatic::VFS` | [VFS](vfs.html) | PhysFS virtual filesystem, encrypted-zip mounting, asset packing |
| `SDLStatic::Extras` | [Extras](extras.html) | password crypto, DEFLATE compression, base64, signals/events |
| `SDLStatic::Formats` | [Formats](formats.html) | JSON (cJSON), TOML (tomlc99), YAML (libyaml) |
| `SDLStatic::Lua` / `SDLStatic::Ruby` | [Lua &amp; Ruby](scripting.html) | embedded Lua 5.4.8 and mruby 4.0.0 |
| `SDLStatic::Bindings` | [Lua &amp; Ruby](scripting.html) | curated game API + generated full-API bindings for both languages |
| `SDLStatic::Cpp` | [C++](cpp.html) | Google-style RAII wrappers, `Status`/`Result`, generated full-API surface |

## Design rules shared by every module

- **Static first.** No module ever links a shared system library for its
  core function. If an upstream cannot be built static on a platform, it
  is not stubbed — it simply does not exist there (compile-time error, not
  a runtime surprise).
- **Pinned and ledgered.** Vendored code is imported at a specific
  release/commit with its SHA-256 recorded. Local changes are documented
  in `deps/<name>.md`, never silently mixed in.
- **Delete, don't stub.** Unsupported upstream features are removed from
  the headers, so misuse fails at compile time.
- **Tested where it runs.** Six CI platforms (Linux, macOS, Windows,
  ASan+UBSan, Android emulator, browser WebAssembly) plus an iOS
  XCFramework batch job.
