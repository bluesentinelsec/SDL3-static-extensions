---
title: Net
description: "TCP and UDP sockets via SDL3_net, statically built — the simplest port in the stack."
---

# Net — `SDLStatic::Net`

SDL3_net 3.2.0 (the `NET_*` API), statically built. One portable C file
over OS sockets with zero third-party dependencies; the full API surface
ships unchanged. For HTTP/S, see the [mog HTTP client](http.html).

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Net)
```

```c
#include <SDL3_net/SDL_net.h>

NET_Init();
NET_Address *addr = NET_ResolveHostname("example.com");
NET_WaitUntilResolved(addr, 5000);
NET_StreamSocket *sock = NET_CreateClient(addr, 443, 0);
```

## Capability notes

| Area | Status |
|------|--------|
| Address resolution (async, refcounted) | ✅ full |
| TCP stream sockets (client/server) | ✅ full |
| UDP datagram sockets | ✅ full |
| Multi-socket wait (`NET_WaitUntilInputAvailable`) | ✅ full |
| Windows | ✅ links OS-built-in `iphlpapi`/`ws2_32` only |
| Web / Emscripten | ❌ not built — upstream ships only a stub there, and this project does not ship stubs; `SDLSTATIC_BUILD_NET` is forced OFF for web builds |

Tests are fully self-contained over 127.0.0.1: TCP echo both directions,
UDP round-trips, multi-socket readiness, clean failure paths.

Provenance:
[`deps/SDL3_net.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/SDL3_net.md).
