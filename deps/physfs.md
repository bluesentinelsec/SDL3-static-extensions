# PhysFS (vendored under `vfs/`)

| | |
|--|--|
| Upstream | https://github.com/icculus/physfs |
| Version | 3.2.0 (tag `release-3.2.0`, commit `eb3383b`) |
| License | zlib (see `vfs/src/physfs/LICENSE.txt`) |
| Imported | 2026-08-14, direct source copy (no submodule, no fork) |
| Dependencies | none (pure C over OS APIs; Apple platform file needs Foundation) |

## What was taken

- Core: `physfs.c`, `physfs_byteorder.c`, `physfs_unicode.c`, internal
  headers (incl. `physfs_miniz.h`, the self-contained zip inflater).
- Archivers: **ZIP** (`physfs_archiver_zip.c`) and real directories
  (`physfs_archiver_dir.c`) only.
- Platform backends: posix, unix, windows, android, apple (`.m`).
- Public header exposed as `<physfs.h>`; built with `PHYSFS_STATIC`.

## What was deleted (not imported)

- Nine archive formats (no stubs; the table is `#if`-gated upstream, so
  `PHYSFS_SUPPORTS_DEFAULT=0` + `PHYSFS_SUPPORTS_ZIP=1` compiles exactly
  what remains, and `PHYSFS_supportedArchiveTypes()` reports the truth):
  7z (`physfs_lzmasdk.h` gone with it), GRP, WAD, HOG, MVL, QPAK, SLB,
  ISO9660, VDF, plus their shared `physfs_archiver_unpacked.c` helper.
- Platform backends we don't target: haiku (`.cpp`), OS/2, QNX, WinRT.
- Build systems, docs, test programs, extras.

## Original additions (not vendored)

`vfs/src/sdlstatic_vfs.c` + `<SDLStatic/vfs.h>`: encrypted-archive mounts
(SSE1 container from SDLStatic Extras → `PHYSFS_mountMemory`) and a
read-only `SDL_IOStream` bridge over PhysFS files. `scripts/pack_assets.py`
builds deterministic zips, optionally encrypts them (independent Python
SSE1 implementation — the C tests mount its output, cross-validating both),
and optionally emits a C header for embedding.

## Local modifications to vendored code

None. PhysFS passed the malformed-archive fuzzing under ASan+UBSan without
findings.
