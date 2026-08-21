---
title: Home
description: "SDL3 Static Extensions: static-link-first game infrastructure for SDL3 — audio, graphics, physics, GUI, scripting, and more in one dependency-free stack."
---

<div class="hero">
  <img class="banner" src="assets/sse-banner.png" alt="SDL3 Static Extensions: a bag of holding erupting with game-development tools over an impossible-geometry block world">
  <h1>SDL3 Static Extensions</h1>
  <p class="tagline">Everything a 2D game needs, statically linked into one self-contained binary. SDL3 and 12 battle-tested extension modules — audio, graphics, physics, GUI, Lua &amp; Ruby scripting — with zero shared-library dependencies.</p>
  <div class="badges">
    <span class="badge rounded-pill">C · C++ · Lua · Ruby</span><span class="badge rounded-pill">Linux · macOS · Windows · Android · iOS · WebAssembly</span><span class="badge rounded-pill">zlib</span><span class="badge rounded-pill">zero shared deps</span>
  </div>
  <div class="d-flex flex-column flex-sm-row gap-2 justify-content-center">
    <a class="btn btn-primary rounded-pill px-4" href="getting-started.html">Get started</a>
    <a class="btn btn-outline-primary rounded-pill px-4" href="modules.html">Browse modules</a>
  </div>
</div>

## Why SDL3 Static Extensions

SDL3 gives you a window, a renderer, input, and audio output — and then the
dependency hunt begins: a mixer, an image loader, fonts, physics, a GUI, a
data format parser, an archive format, a scripting language. Each usually
arrives as another shared library with its own transitive dependencies, its
own platform quirks, and its own packaging story on Android, iOS, and the web.

This project takes the opposite approach. Every extension is **vendored as
pinned source and compiled into a static library**. Your game links a handful
of `SDLStatic::*` CMake targets and produces one self-contained executable —
no DLLs beside the binary, no `LD_LIBRARY_PATH`, no "works on my machine."
The same source tree builds for Linux, macOS, Windows, Android, iOS, and
browser WebAssembly, and all of it is exercised by CI on every platform.

- **One `FetchContent` away.** Consume the whole stack from CMake with a
  single declaration; pick the modules you want with `SDLSTATIC_BUILD_*`
  options (everything is on by default).
- **Four languages, one engine.** The full C API; Google-style C++ RAII
  wrappers with `Status`/`Result` error handling and no exceptions; and Lua
  5.4 plus mruby embedded, with both a curated game API and a generated
  mirror of the entire C surface.
- **Ship your assets sealed.** Pack game files into a zip, optionally
  encrypt it (ChaCha20 + PBKDF2, encrypt-then-MAC), embed it in the binary,
  and mount it as a virtual filesystem — scripts, maps, audio, and textures
  all load from it transparently.
- **Vendored does not mean stale.** Every third-party library is pinned by
  release and checksum with a provenance ledger in `deps/`, including
  documented local fixes (12 upstream bugs found and fixed so far).

## The stack at a glance

| Need | Module | Under the hood |
|------|--------|----------------|
| Audio: mixing, music, sound effects | [Mixer](mixer.html) | SDL3_mixer + vendored codecs, MIDI, chiptune synth |
| 2D drawing primitives | [Gfx](gfx.html) | SDL3_gfx + original GPU-batched equivalents |
| Image loading/saving | [Image](image.html) | SDL3_image, 13 formats, all-static codecs |
| Text and fonts, i18n shaping + BiDi | [TTF](ttf.html) | SDL3_ttf + FreeType, HarfBuzz, SheenBidi |
| Networking | [Net](net.html) | SDL3_net (TCP/UDP) + mog HTTP/S client |
| Physics | [Physics](physics.html) | Box2D v3 |
| GUI | [GUI](gui.html) | Nuklear + SDL3 backend + weighted grid layout |
| Tile maps | [Tiled](tiled.html) | cute_tiled (.tmj) with VFS loading |
| Regular expressions | [Regex](regex.html) | Oniguruma, Ruby syntax, all four languages |
| Dynamic lighting | [Lighting](lighting.html) | day/night, torches, shadows; GPU shader with CPU fallback |
| Game engine | [Engine](engine.html) | fixed-tick loop, interpolation, design resolution, frame limiter |
| Virtual filesystem | [VFS](vfs.html) | PhysFS, encrypted-zip mounting, asset packing |
| Crypto, compression, base64, signals | [Extras](extras.html) | original code + sdefl/sinfl |
| JSON, TOML, YAML | [Formats](formats.html) | cJSON, tomlc99, libyaml |
| Scripting | [Lua &amp; Ruby](scripting.html) | Lua 5.4.8 + mruby 4.0.0, require-from-zip |

## Proof it works

The test suite runs 319 tests across six CI platforms plus an iOS
XCFramework build, with a dedicated AddressSanitizer + UBSan job. The
repository includes four complete Pong implementations — one each in C,
C++, Lua, and Ruby — built purely against the public APIs.
