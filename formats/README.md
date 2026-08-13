# SDLStatic::Formats

Static-only builds of the three data-format parsers games actually need —
level files, configs, and everything ini-shaped:

| Format | Library | Version | Header |
|--------|---------|---------|--------|
| JSON | [cJSON](https://github.com/DaveGamble/cJSON) | v1.7.19 | `<cJSON.h>` |
| TOML | [tomlc99](https://github.com/cktan/tomlc99) | `29076df` | `<toml.h>` |
| YAML | [libyaml](https://github.com/yaml/libyaml) | 0.2.5 | `<yaml.h>` |

All plain C, MIT, zero external dependencies (not even SDL) — fully static
on every platform, web included. The native upstream APIs are exposed
unchanged; provenance in [`deps/formats.md`](../deps/formats.md).

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Formats)
```

```c
/* JSON: DOM parse + write */
cJSON *level = cJSON_Parse(text);
int hp = cJSON_GetObjectItem(level, "hp")->valueint;

/* TOML: typed config lookups */
toml_table_t *conf = toml_parse(buf, err, sizeof(err));
toml_datum_t width = toml_int_in(toml_table_in(conf, "video"), "width");

/* YAML: document API */
yaml_parser_t parser; yaml_document_t doc;
yaml_parser_initialize(&parser);
yaml_parser_set_input_string(&parser, bytes, len);
yaml_parser_load(&parser, &doc);
```

Tests (`tests/formats/`) parse realistic game-shaped documents with
value-exact assertions, round-trip through each library's serializer where
it has one, run the repo's malformed-input fuzzing (truncations + bit
flips under ASan+UBSan), and audit the link line.
