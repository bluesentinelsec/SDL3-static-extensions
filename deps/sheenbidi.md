# SheenBidi (vendored under `ttf/sheenbidi/`)

| | |
|--|--|
| Upstream | https://github.com/Tehreer/SheenBidi |
| Version | v3.0.0 (release tag tarball) |
| SHA-256 | `86c56014034739ba39a24c23eb00323b0bf6f737354f665786015fca842af786` (v3.0.0.tar.gz) |
| License | Apache-2.0 (see `ttf/sheenbidi/LICENSE`) — commercial/closed-source safe; attribution required and provided by shipping the license text |
| Imported | 2026-08-14 |
| Dependencies | none — pure C |

## What was taken

`Headers/` and `Source/` plus `LICENSE`. Tests, tools, and build system
were not imported.

## Build configuration

Unity build: the single `Source/SheenBidi.c` TU with
`SB_CONFIG_UNITY=1`, compiled inside `SDLStatic_TTF` with
`Headers/` and `Source/` on the private include path.

## Why

Implements the Unicode Bidirectional Algorithm (UAX #9). HarfBuzz
shapes one directional run at a time; SheenBidi splits mixed
right-to-left / left-to-right paragraphs into those runs. Exposed
through the original `<SDLStatic/bidi.h>` helper
(`SDLStatic_BidiItemize`, `SDLStatic_BidiBaseIsRTL`), which returns
visual-order runs ready to feed `TTF_SetTextDirection`.

Chosen over FriBidi specifically for licensing: FriBidi is LGPL, which
is burdensome for statically linked closed-source games; SheenBidi is
Apache-2.0 and purpose-built for embedding.
