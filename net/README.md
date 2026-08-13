# SDLStatic::Net

A static-link-first build of [SDL3_net](https://github.com/libsdl-org/SDL_net)
3.2.0 (the `NET_*` API). SDL_net is the simplest port in this repo: one
portable C file over OS sockets, zero third-party dependencies — the full
API surface ships unchanged.

Provenance: [`deps/SDL3_net.md`](../deps/SDL3_net.md).

## Capability notes

| Area | Status |
|------|--------|
| Address resolution (async, refcounted) | ✅ full |
| TCP stream sockets (client/server) | ✅ full |
| UDP datagram sockets | ✅ full |
| Multi-socket wait (`NET_WaitUntilInputAvailable`) | ✅ full |
| Windows | ✅ links OS-built-in `iphlpapi`/`ws2_32` only |
| Web / Emscripten | ❌ not built — upstream only offers a stub there, and this project does not ship stubs; `SDLSTATIC_BUILD_NET` is forced OFF for web builds |

## Usage

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

Tests (`tests/net/`) are fully self-contained over 127.0.0.1: TCP echo in
both directions, UDP datagram round-trip, multi-socket readiness, clean
failure on unresolvable names (RFC 2606 `.invalid`) and closed ports, plus
the standard link audit.
