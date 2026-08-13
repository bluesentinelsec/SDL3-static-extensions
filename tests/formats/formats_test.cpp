/**
 * @file formats_test.cpp
 * @brief Tests for SDLStatic::Formats — vendored cJSON, tomlc99, libyaml.
 *
 * Each parser gets a realistic game-shaped document with value-exact
 * assertions, a serialization/round-trip check where the library supports
 * it, and the repo's malformed-input treatment: truncations and
 * deterministic bit flips must produce parse errors, never crashes
 * (verified for real by the ASan+UBSan job).
 */

#include <cJSON.h>
#include <toml.h>
#include <yaml.h>

#include <gtest/gtest.h>

#include <cstring>
#include <string>
#include <vector>

namespace
{

using Uint32 = unsigned int;

/* Truncations + deterministic bit flips; parse must fail or succeed, not crash. */
template <typename ParseFn>
void FuzzLite(const char *doc, ParseFn parse)
{
    const size_t len = std::strlen(doc);
    for (const double fraction : {0.1, 0.25, 0.5, 0.9})
    {
        std::string cut(doc, static_cast<size_t>(static_cast<double>(len) * fraction));
        parse(cut.c_str());
    }
    Uint32 rng = 0xF00DFACEu;
    for (int round = 0; round < 8; ++round)
    {
        std::string mutated(doc);
        for (int i = 0; i < 6; ++i)
        {
            rng ^= rng << 13;
            rng ^= rng >> 17;
            rng ^= rng << 5;
            mutated[rng % mutated.size()] ^= static_cast<char>(1 << (rng % 7));
        }
        parse(mutated.c_str());
    }
}

const char *const kLevelJson = R"({
  "name": "The Sunken Vault",
  "difficulty": 3,
  "gravity": 9.81,
  "secret": null,
  "checkpoint": true,
  "spawn": {"x": 12, "y": -4},
  "enemies": [
    {"type": "slime", "hp": 20},
    {"type": "bat", "hp": 8}
  ],
  "loot": ["coin", "gem", "keyé"]
})";

TEST(Json, ParsesLevelFileWithExactValues)
{
    cJSON *root = cJSON_Parse(kLevelJson);
    ASSERT_NE(root, nullptr) << cJSON_GetErrorPtr();

    EXPECT_STREQ(cJSON_GetObjectItem(root, "name")->valuestring, "The Sunken Vault");
    EXPECT_EQ(cJSON_GetObjectItem(root, "difficulty")->valueint, 3);
    EXPECT_DOUBLE_EQ(cJSON_GetObjectItem(root, "gravity")->valuedouble, 9.81);
    EXPECT_TRUE(cJSON_IsNull(cJSON_GetObjectItem(root, "secret")));
    EXPECT_TRUE(cJSON_IsTrue(cJSON_GetObjectItem(root, "checkpoint")));

    cJSON *spawn = cJSON_GetObjectItem(root, "spawn");
    ASSERT_NE(spawn, nullptr);
    EXPECT_EQ(cJSON_GetObjectItem(spawn, "y")->valueint, -4);

    cJSON *enemies = cJSON_GetObjectItem(root, "enemies");
    ASSERT_TRUE(cJSON_IsArray(enemies));
    ASSERT_EQ(cJSON_GetArraySize(enemies), 2);
    EXPECT_STREQ(cJSON_GetObjectItem(cJSON_GetArrayItem(enemies, 1), "type")->valuestring, "bat");

    cJSON *loot = cJSON_GetObjectItem(root, "loot");
    ASSERT_EQ(cJSON_GetArraySize(loot), 3);
    EXPECT_STREQ(cJSON_GetArrayItem(loot, 2)->valuestring, "key\xc3\xa9") << "UTF-8 escape";

    cJSON_Delete(root);
}

TEST(Json, SerializeParseRoundTrip)
{
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "title", "quick save");
    cJSON_AddNumberToObject(root, "playtime", 1234.5);
    cJSON *inv = cJSON_AddArrayToObject(root, "inventory");
    cJSON_AddItemToArray(inv, cJSON_CreateString("sword"));
    cJSON_AddItemToArray(inv, cJSON_CreateNumber(42));

    char *text = cJSON_PrintUnformatted(root);
    ASSERT_NE(text, nullptr);
    cJSON *back = cJSON_Parse(text);
    ASSERT_NE(back, nullptr);
    EXPECT_STREQ(cJSON_GetObjectItem(back, "title")->valuestring, "quick save");
    EXPECT_EQ(cJSON_GetArrayItem(cJSON_GetObjectItem(back, "inventory"), 1)->valueint, 42);

    cJSON_Delete(back);
    cJSON_free(text);
    cJSON_Delete(root);
}

TEST(Json, MalformedInputFailsCleanly)
{
    EXPECT_EQ(cJSON_Parse("{\"unterminated\": \"str"), nullptr);
    EXPECT_EQ(cJSON_Parse("{\"a\": 1,}"), nullptr) << "trailing comma";
    EXPECT_EQ(cJSON_Parse(""), nullptr);
    FuzzLite(kLevelJson, [](const char *doc) {
        cJSON *parsed = cJSON_Parse(doc);
        if (parsed != nullptr)
        {
            cJSON_Delete(parsed);
        }
    });
}

const char *const kConfigToml = R"(# game.ini successor
title = "Dungeon Crawler"

[video]
width = 1920
height = 1080
vsync = true
render_scale = 0.75

[audio]
music_volume = 0.8
channels = ["master", "music", "sfx"]

[keybinds]
jump = "space"
attack = "mouse1"
)";

TEST(Toml, ParsesGameConfigWithExactValues)
{
    char err[200];
    toml_table_t *conf = toml_parse(const_cast<char *>(std::string(kConfigToml).data()), err,
                                    sizeof(err));
    ASSERT_NE(conf, nullptr) << err;

    toml_datum_t title = toml_string_in(conf, "title");
    ASSERT_TRUE(title.ok);
    EXPECT_STREQ(title.u.s, "Dungeon Crawler");
    free(title.u.s);

    toml_table_t *video = toml_table_in(conf, "video");
    ASSERT_NE(video, nullptr);
    toml_datum_t width = toml_int_in(video, "width");
    ASSERT_TRUE(width.ok);
    EXPECT_EQ(width.u.i, 1920);
    toml_datum_t vsync = toml_bool_in(video, "vsync");
    ASSERT_TRUE(vsync.ok);
    EXPECT_TRUE(vsync.u.b);
    toml_datum_t scale = toml_double_in(video, "render_scale");
    ASSERT_TRUE(scale.ok);
    EXPECT_DOUBLE_EQ(scale.u.d, 0.75);

    toml_table_t *audio = toml_table_in(conf, "audio");
    ASSERT_NE(audio, nullptr);
    toml_array_t *channels = toml_array_in(audio, "channels");
    ASSERT_NE(channels, nullptr);
    ASSERT_EQ(toml_array_nelem(channels), 3);
    toml_datum_t sfx = toml_string_at(channels, 2);
    ASSERT_TRUE(sfx.ok);
    EXPECT_STREQ(sfx.u.s, "sfx");
    free(sfx.u.s);

    toml_free(conf);
}

TEST(Toml, MalformedInputFailsCleanly)
{
    char err[200];
    std::string bad = "[section\nkey = \"unclosed";
    EXPECT_EQ(toml_parse(bad.data(), err, sizeof(err)), nullptr);
    std::string dupes = "a = 1\na = 2\n";
    EXPECT_EQ(toml_parse(dupes.data(), err, sizeof(err)), nullptr) << "duplicate keys";
    FuzzLite(kConfigToml, [](const char *doc) {
        char ferr[200];
        std::string copy(doc);
        toml_table_t *parsed = toml_parse(copy.data(), ferr, sizeof(ferr));
        if (parsed != nullptr)
        {
            toml_free(parsed);
        }
    });
}

const char *const kSceneYaml = R"(scene: overworld
layers:
  - name: terrain
    tiles: [1, 2, 3, 4]
  - name: props
    tiles: [9, 9, 0, 9]
entities:
  player:
    x: 4.5
    y: 8.0
    persistent: true
)";

/* Load the first document into a yaml_document_t; caller must delete. */
bool LoadYaml(const char *text, yaml_document_t *doc)
{
    yaml_parser_t parser;
    if (!yaml_parser_initialize(&parser))
    {
        return false;
    }
    yaml_parser_set_input_string(&parser, reinterpret_cast<const unsigned char *>(text),
                                 std::strlen(text));
    const bool ok = yaml_parser_load(&parser, doc) != 0;
    yaml_parser_delete(&parser);
    return ok;
}

const char *ScalarOf(yaml_document_t * /*doc*/, yaml_node_t *node)
{
    return (node != nullptr && node->type == YAML_SCALAR_NODE)
               ? reinterpret_cast<const char *>(node->data.scalar.value)
               : nullptr;
}

yaml_node_t *MapGet(yaml_document_t *doc, yaml_node_t *map, const char *key)
{
    if (map == nullptr || map->type != YAML_MAPPING_NODE)
    {
        return nullptr;
    }
    for (yaml_node_pair_t *p = map->data.mapping.pairs.start; p < map->data.mapping.pairs.top;
         ++p)
    {
        yaml_node_t *k = yaml_document_get_node(doc, p->key);
        const char *ks = ScalarOf(doc, k);
        if (ks != nullptr && std::strcmp(ks, key) == 0)
        {
            return yaml_document_get_node(doc, p->value);
        }
    }
    return nullptr;
}

TEST(Yaml, ParsesSceneFileWithExactValues)
{
    yaml_document_t doc;
    ASSERT_TRUE(LoadYaml(kSceneYaml, &doc));
    yaml_node_t *root = yaml_document_get_root_node(&doc);
    ASSERT_NE(root, nullptr);

    EXPECT_STREQ(ScalarOf(&doc, MapGet(&doc, root, "scene")), "overworld");

    yaml_node_t *layers = MapGet(&doc, root, "layers");
    ASSERT_NE(layers, nullptr);
    ASSERT_EQ(layers->type, YAML_SEQUENCE_NODE);
    const ptrdiff_t nlayers =
        layers->data.sequence.items.top - layers->data.sequence.items.start;
    ASSERT_EQ(nlayers, 2);
    yaml_node_t *props =
        yaml_document_get_node(&doc, layers->data.sequence.items.start[1]);
    EXPECT_STREQ(ScalarOf(&doc, MapGet(&doc, props, "name")), "props");
    yaml_node_t *tiles = MapGet(&doc, props, "tiles");
    ASSERT_NE(tiles, nullptr);
    yaml_node_t *tile0 = yaml_document_get_node(&doc, tiles->data.sequence.items.start[0]);
    EXPECT_STREQ(ScalarOf(&doc, tile0), "9");

    yaml_node_t *entities = MapGet(&doc, root, "entities");
    yaml_node_t *player = MapGet(&doc, entities, "player");
    ASSERT_NE(player, nullptr);
    EXPECT_STREQ(ScalarOf(&doc, MapGet(&doc, player, "x")), "4.5");
    EXPECT_STREQ(ScalarOf(&doc, MapGet(&doc, player, "persistent")), "true");

    yaml_document_delete(&doc);
}

TEST(Yaml, EmitParseRoundTrip)
{
    /* Emit a small document and parse it back. */
    yaml_emitter_t emitter;
    ASSERT_TRUE(yaml_emitter_initialize(&emitter));
    unsigned char buffer[1024];
    size_t written = 0;
    yaml_emitter_set_output_string(&emitter, buffer, sizeof(buffer), &written);

    yaml_document_t doc;
    ASSERT_TRUE(yaml_document_initialize(&doc, nullptr, nullptr, nullptr, 1, 1));
    const int map = yaml_document_add_mapping(&doc, nullptr, YAML_BLOCK_MAPPING_STYLE);
    const int key = yaml_document_add_scalar(
        &doc, nullptr, reinterpret_cast<const yaml_char_t *>("save_slot"), -1,
        YAML_PLAIN_SCALAR_STYLE);
    const int value = yaml_document_add_scalar(&doc, nullptr,
                                               reinterpret_cast<const yaml_char_t *>("3"), -1,
                                               YAML_PLAIN_SCALAR_STYLE);
    ASSERT_TRUE(yaml_document_append_mapping_pair(&doc, map, key, value));
    ASSERT_TRUE(yaml_emitter_dump(&emitter, &doc)); /* consumes doc */
    ASSERT_TRUE(yaml_emitter_flush(&emitter));
    yaml_emitter_delete(&emitter);

    const std::string text(reinterpret_cast<char *>(buffer), written);
    yaml_document_t back;
    ASSERT_TRUE(LoadYaml(text.c_str(), &back));
    yaml_node_t *root = yaml_document_get_root_node(&back);
    EXPECT_STREQ(ScalarOf(&back, MapGet(&back, root, "save_slot")), "3");
    yaml_document_delete(&back);
}

TEST(Yaml, MalformedInputFailsCleanly)
{
    yaml_document_t doc;
    EXPECT_FALSE(LoadYaml("key: [unclosed", &doc));
    EXPECT_FALSE(LoadYaml("\t\ttabs: are-not-indentation\n  x: 1\n\ty: 2", &doc));
    FuzzLite(kSceneYaml, [](const char *text) {
        yaml_document_t fuzz_doc;
        if (LoadYaml(text, &fuzz_doc))
        {
            yaml_document_delete(&fuzz_doc);
        }
    });
}

} // namespace
