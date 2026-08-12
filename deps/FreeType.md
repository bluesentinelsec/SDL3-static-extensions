# FreeType (consumed via FetchContent — never vendored)

| | |
|--|--|
| Upstream | https://freetype.org (mirror: https://github.com/freetype/freetype) |
| Version | 2.14.3 (tag `VER-2-14-3`) |
| Commit | `0a0221a1347e2f1e07c395263540026e9a0aa7c7` |
| Fetch | Official release tarball, SHA-256 pinned (see `cmake/Dependencies.cmake`) |
| License | **FTL** (BSD-style; FreeType is dual FTL/GPLv2 — we take FTL) |

Backend for `SDLStatic::TTF` (Phase A; see `deps/SDL3_ttf.md` for the open
Phase-B decision). Built static and **minimal** — every optional dependency
disabled so it contributes zero shared-library dependencies:

- `FT_DISABLE_ZLIB` (uses FreeType's internal zlib copy)
- `FT_DISABLE_BZIP2`, `FT_DISABLE_PNG`, `FT_DISABLE_HARFBUZZ`,
  `FT_DISABLE_BROTLI`

The link audit (`scripts/link_audit.py`) verifies this on every desktop CI
run.

**Attribution requirement (FTL):** products shipping this library must
acknowledge FreeType in their documentation/credits, e.g.:

> Portions of this software are copyright © The FreeType Project
> (www.freetype.org). All rights reserved.

Consumers of SDLStatic::TTF inherit this obligation; it is called out in the
extension's README.

Update procedure: bump the URL + `URL_HASH` in `cmake/Dependencies.cmake`,
update this file, and let the full CI matrix validate.
