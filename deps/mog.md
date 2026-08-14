# mog (FetchContent under `http/`)
| | |
|--|--|
| Upstream | https://github.com/bluesentinelsec/mog (first-party) |
| Version | v0.6.0 (release tarball, SHA256-pinned) |
| Consumed | CMake FetchContent per decision — NOT vendored |

HTTP/S client + embedded server; C API (`<mog/mog_c.h>`) over a C++20
core. Transports are platform-native (WinHTTP, NSURLSession, libcurl via
dlopen on Linux); TLS via FetchContent'd mbedTLS, gzip via miniz — all
static, so the link audit holds. mog's C API normally builds shared for
FFI; SDLStatic::Http compiles those sources into a static lib against
mog_lib instead. Off on Emscripten (C API/server unsupported there).

## Patch (cmake/patch_mog_includes.cmake)

mog v0.6.0 inherits the cppboot template's `include(Dependencies)` — a
module-name include that CMAKE_MODULE_PATH resolves to the PARENT
project's cmake/ when embedded, so mog's mbedTLS/miniz never get declared.
The FetchContent PATCH_COMMAND rewrites those includes to absolute paths.
Upstream fixes to make: same rewrite in mog itself and in the cppboot
template (long-tracked backlog item — this is the bug finally observed in
the wild).
