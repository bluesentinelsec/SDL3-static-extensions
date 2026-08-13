# SDL3_ttf (vendored under `ttf/`)

| | |
|--|--|
| Upstream | https://github.com/libsdl-org/SDL_ttf |
| Version | 3.2.2 (tag `release-3.2.2`) |
| Commit | `a1ce3670aec736ecbf0936c43f2f0cc53aa61e5b` |
| License | zlib (see `ttf/LICENSE.txt`) |
| Imported | 2026-08-12, direct source copy (no submodule, no fork) |
| Requires | SDL3 ≥ 3.2.6 (satisfied by our pinned 3.4.14, see `deps/SDL3.md`) |

## What was taken

- `src/` — all C translation units and private headers: the FreeType-based
  core (`SDL_ttf.c`), the three text engines (surface / renderer / GPU),
  hashtable helpers, and the already-vendored single-file `stb_rect_pack.h`.
- `include/SDL3_ttf/` — public headers (`SDL_ttf.h`, `SDL_textengine.h`).
- `LICENSE.txt`.

## What was deleted (not imported)

- `external/` — submodule stubs for **freetype**, **harfbuzz**, **plutosvg**,
  **plutovg**
- `.github/`, `build-scripts/`, `cmake/`, `CMakeLists.txt` — upstream
  CI/build system (replaced by `ttf/CMakeLists.txt` when the build lands)
- `Xcode/`, `VisualC/`, `mingw/`, `Android.mk` — IDE / platform projects
- `docs/`, `examples/`, `test` assets, `CHANGES.txt`, `INSTALL.md`,
  `README.md`
- `src/SDL_ttf.sym`, `src/version.rc` — shared-library export machinery

## Backend status (differs from the Image port!)

Upstream SDL_ttf 3.x hard-requires **FreeType** (`SDLTTF_FREETYPE ON`, not
configurable) — there is no stb backend upstream. HarfBuzz (shaping) and
plutosvg (color emoji) are optional and will **not** be used here.

**Backend decision (resolved 2026-08-12): minimal static FreeType,
permanently.** Built via pinned FetchContent (see `deps/FreeType.md`), with
every optional dependency disabled — zero shared-library deps, CI-enforced by
the `ttf_link_audit` test. The stb_truetype rewrite is **dropped from scope**
(design fallback explicitly permits FreeType when static-link-friendly, which
this configuration is).

## Local modifications

Removal pass (no-stubs policy — removed APIs fail at build time):

- Deleted the nine HarfBuzz-dependent public functions that were runtime
  stubs or functionally inert without shaping:
  `TTF_SetFontDirection`, `TTF_GetFontDirection`, `TTF_SetFontScript`,
  `TTF_GetFontScript`, `TTF_GetGlyphScript`, `TTF_SetTextDirection`,
  `TTF_GetTextDirection`, `TTF_SetTextScript`, `TTF_GetTextScript`
  (declarations and implementations; internal layout code uses private
  equivalents). Text direction is LTR; complex-script shaping is out of
  scope per the design.
- `TTF_Direction` remains in the public header as a type (used internally;
  inert as API surface).
- Hardening fixes to vendored code (found by the coverage/robustness suite
  under ASan+UBSan; kept local, no upstream PRs):
  - `BUILD_RENDER_LINE` macro: skip glyphs with a NULL bitmap buffer
    (e.g. spaces) — `NULL + alignment` pointer arithmetic is UB and fired
    on every render containing a space.
  - `BG_Blended_LCD`: rewritten to walk byte pointers — LCD glyph rows are
    not 4-aligned, and the typed `Uint32*` walkers made clang emit
    aligned loads despite upstream's memcpy workaround (misaligned-load UB
    on every LCD render).
- SDLStatic additions (ours, zlib): `SDLStatic/debug_text.h` +
  `src/sdlstatic_debug_text.c` — zero-setup debug/HUD text overlay backed by
  an embedded ProggyClean font (`src/sdlstatic_debug_font.h`, MIT, license
  reproduced in the header; regenerate with `scripts/embed_font.py`).
- HarfBuzz shaping and plutosvg color-emoji are disabled at build level
  (`TTF_USE_HARFBUZZ` / `TTF_USE_PLUTOSVG` = 0); no submodules imported.
