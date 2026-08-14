---
title: VFS
description: "PhysFS virtual filesystem with an encrypted-asset pipeline: pack, encrypt, embed, and mount your game files from one sealed archive."
---

# VFS — `SDLStatic::VFS`

PhysFS 3.2.0, built static with only the **ZIP** and real-directory
backends (the other archive formats were deleted, not stubbed), plus
original glue for a complete encrypted-asset pipeline.

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::VFS)
```

## The asset pipeline

```
assets/  ──pack_assets.py──▶  media.zip  ──(--password)──▶  media.bin (SSE1)
                                                              │
                                            ship as a file, or --header
                                            embeds it as a C byte array
```

```bash
python3 scripts/pack_assets.py assets/ media.bin --password "openSesame" \
        --header media.h --symbol game_media
```

The zip is deterministic (sorted entries, fixed timestamps): repacking
unchanged assets yields byte-identical archives. Encrypting the whole
zip also hides file names — something classic zip passwords never did.

## Mounting at runtime

```c
#include <physfs.h>
#include <SDLStatic/vfs.h>
#include "media.h"

PHYSFS_init(argv[0]);

/* decrypt + mount the embedded image from memory, one call: */
SDLStatic_MountEncryptedArchive(game_media, (int)game_media_len,
                                "openSesame", "/assets");

/* plain zips need no glue at all: */
PHYSFS_mount("mods/extra.zip", "/mods", 1);

/* read whole files... */
int size = 0;
unsigned char *level = SDLStatic_LoadVFSFile("/assets/levels/1.json", &size);

/* ...or stream mounted assets straight into the other modules: */
SDL_Surface *hero = IMG_Load_IO(SDLStatic_OpenVFSRead("/assets/hero.png"), true);
MIX_Audio *bgm = MIX_LoadAudio_IO(mixer,
    SDLStatic_OpenVFSRead("/assets/bgm.ogg"), false, true);
```

A wrong password or a tampered blob returns `false` with
`SDL_GetError()` set — the SSE1 container authenticates (encrypt-then-MAC)
*before* mounting, so you never get a half-mounted archive. See
[Extras](extras.html) for the underlying crypto.

Everything else is the native PhysFS API: search-path layering,
`PHYSFS_enumerateFiles`, `PHYSFS_openRead`, write directories, and so on.
The [Tiled](tiled.html) module and both [script runtimes](scripting.html)
(`require`/`load` from mounted archives) are VFS-aware out of the box.

Provenance:
[`deps/physfs.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/physfs.md).
