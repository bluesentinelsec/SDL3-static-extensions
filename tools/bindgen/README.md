# bindgen — the binding generator

Generates the complete language surface for every C library in this
repo, three ways:

| Surface | Output | What you get |
|---|---|---|
| C++ | `cpp/include/sdlstatic/gen/*.h` | RAII owners for every resource with a create/destroy pair, `Status`/`Result` wrappers for fallible functions, namespace aliases for everything else — 100% of the parsed API accounted for, `namespace sdlstatic::{sdl,mix,img,ttf,net,vfs,b2,nk,json,ext}` |
| Lua | `bindings/generated/gen_lua_*.c` | Flat global tables mirroring C names minus prefixes (`SDL.CreateSurface`, `B2.World_Step`, `JSON.Parse`) plus enum constants; owned handles are GC-managed userdata |
| Ruby | `bindings/generated/gen_ruby_*.c` | Same surface as Lua on mruby modules; owned handles are GC-managed Data objects |

Coverage, including every skipped function and why, is written to
`bindings/generated/COVERAGE.md`.

## Running

```sh
# regenerate everything in place (needs a configured build tree for the
# FetchContent SDL3/satellite headers)
python3 -m tools.bindgen --repo . --deps build/_deps

# verify committed output matches the tool (runs in CI via ctest as
# `bindgen_freshness`)
python3 -m tools.bindgen --check

# just parser statistics
python3 -m tools.bindgen --stats-only
```

Generated output is committed (same policy as the mruby codegen): builds
never depend on Python, and diffs are reviewable.

## How it works

- `parse.py` — regex scanner for the rigid per-library declaration
  macros (`SDL_DECLSPEC`/`SDLCALL`, `PHYSFS_DECL`, `B2_API`, `NK_API`,
  `CJSON_PUBLIC`, plain `extern` for SDLStatic modules). Tracks
  `#if` nesting so platform-gated declarations and Nuklear config
  sections outside our pinned `NK_INCLUDE_*` set are dropped
  (`check_nk_config` fails generation if the tool's model of that set
  drifts from `gui/include/SDLStatic/nuklear.h`).
- `classify.py` — resolves typedefs, categorizes every type
  (scalar/enum/string/handle/POD/callback), and produces one plan per
  function per surface. Lua and Ruby share the same plans, so their
  bound sets are identical by construction.
- `spec.py` — the curated knowledge: library inventory, ownership table
  (which create functions transfer ownership to which destroy function —
  this drives C++ RAII classes *and* script GC), by-value resources
  (`SDL_PropertiesID`, Box2D ids) with validity expressions, structs
  whose userData/callback fields are skipped during marshaling.
- `emit_cpp.py` / `emit_lua.py` / `emit_ruby.py` / `emit_report.py`.

## Ownership rules (scripts)

- A pointer returned by a create function in the ownership table is an
  **owned** handle: GC destroys it exactly once.
- Bound destroy functions (`SDL.DestroySurface`, `JSON.Delete`, ...)
  empty the handle box first, so explicit destruction plus a later GC
  never double-frees.
- Every other pointer is **borrowed** — valid as long as its owner.
- Box2D's by-value ids marshal as plain tables/hashes; destroy them
  explicitly (`B2.DestroyWorld`), exactly as in C. The C++ wrappers and
  the curated `SDLStatic` layer provide RAII/GC alternatives.

## Skipped functions

Scripts skip (with the reason recorded in COVERAGE.md): callbacks,
varargs, raw-memory/threading families (deliberate policy — scripts get
crashes, not data races), and types that cannot round-trip a script
boundary (unions like `SDL_Event`, pointer-to-pointer, sized output
buffers). The curated hand-written `SDLStatic` module covers the
game-loop essentials among those (event polling, input); the full C API
remains available to C and C++.
