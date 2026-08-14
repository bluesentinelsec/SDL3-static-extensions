# cute_tiled (vendored under `tiled/`)

| | |
|--|--|
| Upstream | https://github.com/RandyGaul/cute_headers (`cute_tiled.h`) |
| Version | commit `389aa9554f478c49d5db2715548f52b8d5286db7` |
| SHA-256 | `1567d137ddcd257fd74e6bd146cfe8f12feb45a1d3d4c0231c72dcf48e671180` (as imported, before local fixes) |
| License | dual zlib / public domain (license text embedded at the end of the header) |
| Imported | 2026-08-10, direct copy of `cute_tiled.h` (exposed as `<cute_tiled.h>`) |
| Dependencies | none — single C header (embeds strpool) |

## Why cute_tiled

Parses Tiled's JSON export (`.tmj` / `.json`) in a single dependency-free
C header — a perfect fit for the static-link-first rule. The main
alternative, libtmx, requires libxml2 (and parses the XML `.tmx` format),
which fails that rule.

## What was taken

`cute_tiled.h` only — **vendored as-is, no delete-down** (single
dependency-free header; nothing to slim). The implementation is compiled
in exactly one TU: `tiled/src/sdlstatic_tiled.c`
(`CUTE_TILED_IMPLEMENTATION`).

## Original additions (not vendored)

- `tiled/src/sdlstatic_tiled.c` + `<SDLStatic/tiled.h>` — VFS-first map
  loading (mounted/encrypted zip archives via PhysFS, filesystem
  fallback) and a flat accessor API (dimensions, layers, tile GIDs,
  objects) that the Lua/Ruby/C++ bindings wrap. The full
  `cute_tiled_map_t` parse tree stays reachable via `SDLStatic_TiledRaw`.
- `scripts/gen_tiled_maps.py` — generates the Tiled-1.10-conformant test
  corpus (`tests/tiled/assets/level.tmj` + `maps.zip`). Note: Tiled's
  JSON export puts no space after `:`; cute_tiled depends on this for
  quoted numeric fields like `"version": "1.10"` (it only skips a quote
  that immediately follows the value start), so the generator emits
  compact separators.

## Local modifications to vendored code

1. **Missing `cute_tiled_chunk_t` typedef** — every other struct has a
   forward `typedef struct X X;`, but the chunk struct (a newer
   infinite-map addition) was missed, so the header compiles as C++ but
   fails as C. Added the typedef next to the others.
2. **Linked lists never un-reversed** — `cute_tiled_load_map_from_memory`
   captures `layer`/`tileset` cursors *before* parsing (both still NULL),
   so the post-parse loops meant to restore document order for object,
   chunk, and tile-descriptor lists never ran (layers and tilesets were
   fixed up correctly, in place). Re-read the list heads after the
   layer/tileset reversal so objects come back in document order.
3. **Crash on truncated input (mitigated in the wrapper, header
   untouched)** — `cute_tiled_next` deliberately null-writes
   (`CUTE_TILED_CRASH`) when the cursor runs off the end of the buffer,
   which truncated or non-JSON input triggers. `SDLStatic_LoadTiledMap`
   validates the buffer with cJSON (`SDLStatic::Formats`) before handing
   it to cute_tiled, so malformed input fails with `SDL_GetError` instead
   of a segfault.

Per project policy these fixes are documented here and kept local; they
are not upstreamed.
