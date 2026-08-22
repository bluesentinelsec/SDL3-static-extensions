---
title: "Component support by platform"
description: "Which components build on which platforms, what each platform ships, and where the gaps are."
---

# Component support by platform

Every component builds on every platform we ship, with one exception noted
below. That was not true until recently — and more to the point, it was not
*known*, because the mobile builds compiled a single placeholder library and
never touched the components at all.

## Builds

| Component | Linux | macOS | Windows | Android | iOS | Web |
|---|---|---|---|---|---|---|
| Image | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| TTF | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Mixer | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Net | ✅ | ✅ | ✅ | ✅ | ✅ | ⚠️ |
| Gfx | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Extras | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Formats | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| VFS | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Physics | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| GUI | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Http | ✅ | ✅ | ✅ | ✅ | ✅ | ⚠️ |
| Tiled | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Regex | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Light | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Engine | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Lua | ✅ | ✅ | ✅ | ✅ | ✅¹ | ✅ |
| Ruby | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Bindings | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| C++ wrapper | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |

¹ `os.execute` reports "no shell" on iOS. The platform marks `system()`
unavailable, and Lua's own `LUA_USE_IOS` turns it into a stub — the rest of
the language is unaffected.

⚠️ **Builds, but the platform limits it.** Browsers cannot open raw TCP or
UDP sockets, so `Net` compiles and its calls fail at runtime; `Http` has no
Emscripten transport, so it needs the browser's own fetch. Neither is a
build failure, which is exactly why they are called out here.

## What each platform ships

| Platform | Artifact | Runner |
|---|---|---|
| Linux, macOS, Windows | static SDK — one archive, headers, CMake package | yes |
| Android | Prefab AAR, one `.so` per ABI | no¹ |
| iOS | XCFramework, device + simulator slices | no¹ |
| Web | wasm archive, headers, CMake package | not yet² |

¹ There is no command line to run it from, and CMake treats every executable
on those platforms as an app bundle.
² Tracked with the rest of the web work.

## What "builds" does and does not mean

This table is about compilation and linking. It is **not** a statement that
every component behaves correctly at runtime on every platform, and the
distinction matters more than it looks:

- Desktop is exercised properly — the full suite, plus a consumer that links
  the installed SDK and runs the engine.
- Android and iOS run a consumer app that creates a headless engine, spawns
  an actor, runs frames and loads the Lua bindings. That is a real check, and
  it is much less than the desktop suite.
- Web runs version, browser-environment and image-decoding tests in headless
  Chrome. The engine's browser main loop is implemented but not yet covered.

## Keeping this honest

A hand-written table drifts, and a drifted table is worse than none: it is
believed. The rows above come from building each component for each platform,
and the mobile and web columns are re-checked by CI on every pull request —
if a component stops building for iOS, the iOS job fails rather than this
page quietly becoming wrong.

The runtime column is the part still maintained by hand, and the honest thing
to do with it is shrink it by adding coverage.
