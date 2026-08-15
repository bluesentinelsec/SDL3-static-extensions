---
title: Platforms
description: "Where the stack runs and how it's proven: Linux, macOS, Windows, Android, iOS, and browser WebAssembly, all exercised in CI."
---

# Platforms

The same source tree builds everywhere SDL3 runs, and CI proves it on
every push:

| Platform | CI | Notes |
|----------|----|----|
| Linux | ✅ every push | Debug + Release, full test suite |
| macOS | ✅ every push | Debug + Release, full test suite |
| Windows | ✅ every push | MSVC, full test suite |
| ASan + UBSan | ✅ every push | dedicated clang sanitizer job, full suite |
| Android | ✅ every push | Prefab AAR build + instrumented tests on an emulator |
| Browser WebAssembly | ✅ every push | Emscripten build, tests run in a real browser via emrun |
| iOS | ✅ batch (workflow_dispatch) | static XCFramework build + verification |

## Static everywhere

Every platform build is fully static with respect to this stack: the
only shared libraries a binary touches are the operating system's own.
A link audit runs as a test on every platform and fails CI if any test
executable picks up a non-OS shared dependency.

## Platform-specific notes

- **Web:** `SDLStatic::Net` does not exist in Emscripten builds
  (upstream SDL3_net only offers a stub there, and this project does not
  ship stubs). Use [mog](http.html) for browser-side HTTP via Fetch.
  Box2D builds with SIMD (`-msimd128`).
- **Web canvas sizing:** SDL3's Emscripten backend decides the window size
  by probing the canvas element's CSS box. A canvas with no explicit CSS
  size measures as just its borders, and SDL creates a 2–3 pixel window —
  the app renders correctly but is invisible. Give the canvas a real CSS
  size in your shell HTML, or size it from the app after window creation:

  ```c
  const int w = EM_ASM_INT({ return window.innerWidth; });
  const int h = EM_ASM_INT({ return window.innerHeight; });
  emscripten_set_element_css_size("#canvas", w, h);
  SDL_SetWindowSize(window, w, h);
  ```
- **File dialogs on web:** SDL has no Emscripten dialog backend;
  [`SDLStatic::Extras`](extras.html) supplies one over browser APIs. Opening
  works through a file input; saving downloads the file, since a page cannot
  write to disk.
- **Android:** consumed as a Prefab AAR; the emulator CI job runs the
  test suite on-device.
- **iOS:** ships as a static XCFramework (device arm64 + Simulator
  arm64/x86_64), validated by a dispatched CI batch before merges.
- **MIDI on all platforms** needs the GM patch set (see
  [Mixer](mixer.html)); everything else is fully self-contained.

## Versioning

The project follows [semantic versioning](https://semver.org/). Until
1.0.0, minor versions may include breaking API changes; they will always
be called out in release notes.
