---
title: Formats
description: "JSON, TOML, and YAML parsing — the three data formats games actually need, statically built with their native APIs unchanged."
---

# Formats — `SDLStatic::Formats`

Static-only builds of the three data-format parsers games actually use —
level files, configs, and everything ini-shaped. All plain C, MIT, zero
external dependencies (not even SDL). The native upstream APIs are
exposed unchanged.

| Format | Library | Version | Header |
|--------|---------|---------|--------|
| JSON | cJSON | v1.7.19 | `<cJSON.h>` |
| TOML | tomlc99 | pinned commit | `<toml.h>` |
| YAML | libyaml | 0.2.5 | `<yaml.h>` |

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Formats)
```

```c
/* JSON: DOM parse + write */
cJSON *level = cJSON_Parse(text);
int hp = cJSON_GetObjectItem(level, "hp")->valueint;
char *out = cJSON_Print(level);

/* TOML: typed config lookups */
toml_table_t *conf = toml_parse(buf, errbuf, sizeof(errbuf));
toml_datum_t title = toml_string_in(conf, "title");

/* YAML: event/document parsing */
yaml_parser_t parser;
yaml_parser_initialize(&parser);
```

The [Tiled](tiled.html) module uses cJSON internally to validate map
files before parsing; C++ gets a RAII `JsonDocument` owner; Lua and Ruby
get the `JSON.*` module — see [C++](cpp.html) and
[Scripting](scripting.html).

Provenance for all three:
[`deps/formats.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/formats.md).
