# HarfBuzz (vendored under `ttf/harfbuzz/`)

| | |
|--|--|
| Upstream | https://github.com/harfbuzz/harfbuzz |
| Version | 14.3.1 (release tarball) |
| SHA-256 | `9dae9538aae2ffdf70cec31f2c27bf68e2aaeeae3112688467697d5faf6194f7` (harfbuzz-14.3.1.tar.xz) |
| License | "Old MIT" (see `ttf/harfbuzz/COPYING`) — commercial/closed-source safe |
| Imported | 2026-08-14 |
| Dependencies | none required; built against our vendored static FreeType via `hb-ft` |

## What was taken

`src/harfbuzz.cc` (the officially supported single-translation-unit
amalgamation), every `.cc` file it includes, and all `.h`/`.hh` headers
from `src/` — plus `COPYING`. Build system, tests, tools, docs, and CI
were not imported.

## Build configuration

Compiled as one C++ TU (`harfbuzz.cc`) inside `SDLStatic_TTF` with:

- `HAVE_FREETYPE=1` — enables `hb-ft` so SDL_ttf can wrap FreeType faces
- `HB_NO_MMAP=1` — no platform mmap paths; keeps the TU portable

No exceptions or RTTI are required; nothing links dynamically. The
`ttf_link_audit` CI test continues to prove the TTF test binary depends
only on OS-built-in shared libraries.

## Why

Enables the restored SDL_ttf shaping path (`TTF_USE_HARFBUZZ=1`):
Arabic joining and ligatures, Hebrew, Indic conjuncts and reordering,
plus modern GPOS/GSUB kerning for all scripts. See `deps/SDL3_ttf.md`
for the nine restored public APIs and `deps/sheenbidi.md` for the BiDi
companion.
