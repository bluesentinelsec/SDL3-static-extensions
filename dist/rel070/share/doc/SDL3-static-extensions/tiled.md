---
title: Tiled
description: "Tiled map (.tmj) parsing via cute_tiled, VFS-aware so levels load from mounted (optionally encrypted) archives."
---

# Tiled — `SDLStatic::Tiled`

Parses [Tiled](https://www.mapeditor.org/) JSON maps (`.tmj`) via the
vendored single-header cute_tiled — no libxml2, no dependencies. Loading
is **VFS-first**: if the [virtual filesystem](vfs.html) is initialized
and the path exists there, maps load from mounted (optionally encrypted)
archives; otherwise from disk.

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Tiled)
```

```c
#include <SDLStatic/tiled.h>

SDLStatic_TiledMap *map = SDLStatic_LoadTiledMap("/assets/level.tmj");

int w  = SDLStatic_TiledMapWidth(map);       /* in tiles */
int th = SDLStatic_TiledTileHeight(map);     /* in pixels */

for (int y = 0; y < SDLStatic_TiledMapHeight(map); y++)
    for (int x = 0; x < w; x++) {
        int gid = SDLStatic_TiledTileAt(map, 0, x, y);  /* 0 = empty */
        /* draw tile gid at (x, y) */
    }

SDLStatic_TiledObject obj;
for (int i = 0; SDLStatic_TiledObjectAt(map, 2, i, &obj); i++)
    spawn_entity(obj.name, obj.type, obj.x, obj.y, obj.w, obj.h);

SDLStatic_FreeTiledMap(map);
```

The flat accessor API covers dimensions, layers (name/type), tile GIDs,
and objects; the full cute_tiled parse tree (tilesets, properties,
animations) stays reachable via `SDLStatic_TiledRaw(map)`.

Malformed input fails cleanly with `SDL_GetError()` — map data is
validated as JSON before parsing, so truncated or corrupt files can
never crash the loader.

C++ gets a RAII `TiledMap` wrapper (`sdlstatic/tilemap.h`); Lua and Ruby
get `SDLStatic.load_map` with GC-managed map objects — see
[C++](cpp.html) and [Scripting](scripting.html).

Provenance and local fixes (four upstream bugs documented):
[`deps/cute_tiled.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/cute_tiled.md).
