# SDLStatic::VFS

A static-link-first build of [PhysFS](https://github.com/icculus/physfs)
3.2.0 — the virtual filesystem for game assets — plus original glue for the
encrypted-asset pipeline. Only the **ZIP** archiver and real-directory
backends are compiled (the other nine formats were deleted, not stubbed).

Provenance: [`deps/physfs.md`](../deps/physfs.md).

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

At runtime:

```c
#include <physfs.h>
#include <SDLStatic/vfs.h>
#include "media.h"

PHYSFS_init(argv[0]);

/* decrypt + mount the zip image from memory, one call: */
SDLStatic_MountEncryptedArchive(game_media, (int)game_media_len,
                                "openSesame", "/assets");

/* plain zips skip the glue entirely: */
PHYSFS_mount("mods/extra.zip", "/mods", 1);

/* read whole files... */
int size = 0;
unsigned char *level = SDLStatic_LoadVFSFile("/assets/levels/1.json", &size);

/* ...or stream mounted assets straight into the other extensions: */
SDL_Surface *hero = IMG_Load_IO(SDLStatic_OpenVFSRead("/assets/hero.png"), true);
MIX_Audio *bgm = MIX_LoadAudio_IO(mixer, SDLStatic_OpenVFSRead("/assets/bgm.ogg"), false, true);
```

Notes:
- ZIP already deflates its entries, so no separate compression pass is
  needed — and encrypting the *whole* zip also hides file names, which
  classic zip passwords don't.
- Wrong password or tampered blob → `false` + `SDL_GetError()`, never a
  half-mounted archive (the SSE1 container authenticates before mounting).
- Everything else is the native PhysFS API: `PHYSFS_mount`,
  `PHYSFS_enumerateFiles`, `PHYSFS_openRead`, search-path layering, etc.

Tests (`tests/vfs/`) mount from disk and memory, verify exact file bytes
and enumeration, mount a **Python-encrypted** archive through the C
decryptor (cross-validating both SSE1 implementations), reject wrong
passwords and non-zip payloads, exercise the SDL_IOStream bridge
(size/seek/read/EOF/read-only), fuzz truncated + bit-flipped zip images,
and audit the link line.
