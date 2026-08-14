---
title: HTTP/S
description: "HTTP and HTTPS via mog — a lightweight static-link-friendly client and embedded server, compiled into your binary."
---

# HTTP/S — mog

HTTP and HTTPS come from [mog](https://github.com/bluesentinelsec/mog), a
lightweight static-link-friendly HTTP/S client (and embedded server) for
C++ with a C API on top. It is pulled in via CMake FetchContent at a
pinned release and compiled statically — the resulting game binary stays
fully self-contained, with the Mozilla CA bundle compiled in so HTTPS
verifies even in a `FROM scratch` container.

Two ways to use it:

## C API — `SDLStatic::Http`

mog's C API sources are compiled straight into a static library against
the static mog core:

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Http)
```

```c
#include <mog/mog_c.h>

mog_response *resp = mog_get("https://api.example.com/leaderboard");
if (resp != NULL && mog_response_ok(resp) && mog_response_status(resp) == 200) {
    size_t len = 0;
    const char *body = mog_response_body(resp, &len);
    /* parse with SDLStatic::Formats (cJSON) */
}
mog_response_free(resp);
```

An embedded HTTP/S server (`mog_server_*`) is included too — the test
suite runs loopback round-trips against it on every platform.

## C++ API — `mog::mog`

mog is already C++ underneath (a requests-style API), so C++ games link
the mog target directly — no wrapper needed:

```cmake
target_link_libraries(your_game PRIVATE mog::mog)
```

```cpp
#include <mog/mog.hpp>

auto r = mog::get("https://api.example.com/leaderboard");
if (r) {
    // r->status_code, r->headers, r->text()
}
```

On native platforms mog prefers the OS HTTP stack (libcurl on Linux,
NSURLSession on macOS/iOS, WinHTTP on Windows) and falls back to its
embedded HTTP/1.1 + mbedTLS stack when none is available. Full behavior
docs live at [mog's own site](https://bluesentinelsec.github.io/mog/).

Provenance:
[`deps/mog.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/mog.md).
