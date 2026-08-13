# cJSON / tomlc99 / libyaml (vendored under `formats/`)

All three are plain C, MIT-licensed, and have zero external dependencies —
they don't even use SDL — so `SDLStatic::Formats` is inherently
static-link friendly on every platform including web. Native upstream APIs
are exposed directly (`<cJSON.h>`, `<toml.h>`, `<yaml.h>`).

## cJSON — JSON

| | |
|--|--|
| Upstream | https://github.com/DaveGamble/cJSON |
| Version | v1.7.19 (tag commit `c859b25`) |
| Files | `cJSON.c` (+ LICENSE), header exposed as `<cJSON.h>` |
| Build note | `CJSON_HIDE_SYMBOLS` (static; no dllexport decoration) |

## tomlc99 — TOML v1.0

| | |
|--|--|
| Upstream | https://github.com/cktan/tomlc99 |
| Commit | `29076dfd095bbbbd50a3c1b2760d29f4b83e74ac` (2026-01-30; no tagged releases) |
| Files | `toml.c` (+ LICENSE), header exposed as `<toml.h>` |

## libyaml — YAML 1.1

| | |
|--|--|
| Upstream | https://github.com/yaml/libyaml |
| Version | 0.2.5 (tag commit `2c891fc`) — last stable; 0.2.6 is still RC |
| Files | `src/*.c` + `yaml_private.h` (+ LICENSE), header exposed as `<yaml.h>` |
| Build note | version macros supplied by our CMake; `YAML_DECLARE_STATIC` |

## What was deleted (not imported)

Build systems, test suites, fuzz corpora, docs, packaging metadata from all
three — sources, public headers, and licenses only.

## Local modifications

None. All three passed the malformed-input fuzzing (truncations + bit
flips) under ASan+UBSan without findings.
