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
- iOS runs a consumer app that creates a headless engine, spawns an actor,
  runs frames and loads the Lua bindings. A real check, and much less than
  the desktop suite.
- Android runs the same app minus the engine. SDL's Android backend expects
  to be driven by `org.libsdl.app.SDLActivity`, which owns the surface, the
  looper and the main thread; a plain Activity calling in over JNI blocks in
  `SDLStatic_CreateEngine` waiting for plumbing that is not there. A game
  subclassing `SDLActivity` is unaffected — proving that needs an
  SDLActivity-based harness, which is its own work.
- Web runs version, browser-environment and image-decoding tests in headless
  Chrome. The engine's browser main loop is implemented but not yet covered.

## Two ways a build can lie

Both were live in this repository, and both passed every check:

**An artifact with the right shape and no contents.** The mobile builds
compiled one placeholder library, and the checks verified ABIs, slices,
paths and version — every one of which is true of an archive holding a
version string. Artifact checks now assert size and symbols.

**A build that succeeds and produces nothing.** A static library assembled
from `$<TARGET_OBJECTS:...>` compiles nothing of its own, and the Xcode
generator treats that as a target with no work to do: no archive, no error.
Relatedly, when two source files share a basename, Xcode disambiguates the
object names and then omits them from that same aggregation — 803 members
where there should have been 1606, with half of an HTTP backend missing.
The SDK is merged with `libtool` under Xcode for that reason.

Neither is caught by an exit code, which is why the checks look inside.

## Keeping this honest

A hand-written table drifts, and a drifted table is worse than none: it is
believed. The rows above come from building each component for each platform,
and the mobile and web columns are re-checked by CI on every pull request —
if a component stops building for iOS, the iOS job fails rather than this
page quietly becoming wrong.

The runtime column is the part still maintained by hand, and the honest thing
to do with it is shrink it by adding coverage.
