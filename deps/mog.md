# mog (FetchContent under `http/`)
| | |
|--|--|
| Upstream | https://github.com/bluesentinelsec/mog (first-party) |
| Version | v0.6.1 (release tarball, SHA256-pinned) |
| Consumed | CMake FetchContent per decision — NOT vendored |

HTTP/S client + embedded server; C API (`<mog/mog_c.h>`) over a C++20
core. Transports are platform-native (WinHTTP, NSURLSession, libcurl via
dlopen on Linux); TLS via FetchContent'd mbedTLS, gzip via miniz — all
static, so the link audit holds. mog's C API normally builds shared for
FFI; SDLStatic::Http compiles those sources into a static lib against
mog_lib instead. Off on Emscripten (C API/server unsupported there).

## History

Onboarding at v0.6.0 surfaced two first-party bugs, both fixed upstream in
v0.6.1 (and the include bug also in cppboot v0.3.3's template): the
embed-shadowed `include(Dependencies)` (worked around here briefly via a
FetchContent PATCH_COMMAND, since removed) and a use-after-free in the
curl backend (`CURLINFO_EFFECTIVE_URL` read after `curl_easy_cleanup`,
caught by this repo's ASan leg).
