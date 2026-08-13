# SDL3_net (vendored under `net/`)

| | |
|--|--|
| Upstream | https://github.com/libsdl-org/SDL_net |
| Version | 3.2.0 (tag `release-3.2.0`) |
| Commit | `1a84a2a6b9663572f77e2eb5348d42845bac0053` |
| License | zlib (see `net/LICENSE.txt`) |
| Imported | 2026-08-13, direct source copy (no submodule, no fork) |
| Requires | SDL3 ≥ 3.0.0 (satisfied by our pinned 3.4.14, see `deps/SDL3.md`) |
| API generation | The SDL3-era **`NET_*`** API |

## What was taken

- `src/SDL_net.c` — the entire library is one portable C file over OS
  sockets (BSD sockets / winsock).
- `include/SDL3_net/SDL_net.h`, `LICENSE.txt`.

## What was deleted (not imported)

- `src/SDL_net_stub_only.c` — upstream's every-function-fails stub for
  platforms without sockets (Emscripten, DOS, consoles). This project does
  not ship stubs: on web builds `SDLSTATIC_BUILD_NET` is forced OFF and the
  library simply does not exist (compile-time absence, not runtime failure).
- `src/SDL_net_haiku.cpp` (Haiku is not a target), shared-library export
  machinery (`genexports.py`, `.exports`, `.sym`, `version.rc`), `.github/`,
  `cmake/`, `CMakeLists.txt`, `build-scripts/`, `examples/`, `docs/`, IDE
  trees.

## Dependencies

None beyond the OS. SDL_net has zero third-party dependencies: Unix needs
only libc; Windows links the OS-built-in `iphlpapi` + `ws2_32`. Nothing to
delete-down at the API level — the full NET_* surface ships.

## Local modifications

None.
