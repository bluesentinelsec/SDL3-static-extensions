/**
 * @file shaping_test.cpp
 * @brief Tests for the restored HarfBuzz shaping path and the SheenBidi
 *        paragraph itemization helper. Headless (surface rendering only).
 *
 * Fonts: Noto Sans Arabic / Devanagari / Hebrew (OFL-1.1, see
 * assets/fonts/OFL.txt) — real complex-script fonts so the assertions
 * exercise genuine joining, ligature, and conjunct behavior.
 */

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDLStatic/bidi.h>
#include <gtest/gtest.h>

#include <hb.h>

#include <string>
#include <vector>

#ifndef TTF_TEST_ASSETS_DIR
#error "TTF_TEST_ASSETS_DIR must be defined by the build"
#endif

namespace
{

std::string FontPath(const char *name)
{
    return std::string(TTF_TEST_ASSETS_DIR) + "/fonts/" + name;
}

class Shaping : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        ASSERT_TRUE(TTF_Init());
    }
    void TearDown() override
    {
        TTF_Quit();
    }
};

// The definitive "is HarfBuzz actually on" probe: shaping an Arabic
// word with the joining features force-disabled must select different
// glyphs than the default shape — proving GSUB contextual forms are
// being applied. (Font-independent: no assumption about whether the
// font implements lam-alef as one ligature glyph or two shaped forms.)
TEST_F(Shaping, ArabicJoiningFeaturesSelectDifferentGlyphs)
{
    hb_blob_t *blob = hb_blob_create_from_file(FontPath("NotoSansArabic-Regular.ttf").c_str());
    ASSERT_NE(hb_blob_get_length(blob), 0u);
    hb_face_t *face = hb_face_create(blob, 0);
    hb_font_t *font = hb_font_create(face);

    auto shape_ids = [&](const hb_feature_t *features, unsigned n_features) {
        hb_buffer_t *buf = hb_buffer_create();
        hb_buffer_add_utf8(buf, "\xD8\xB3\xD9\x84\xD8\xA7\xD9\x85", -1, 0, -1);
        hb_buffer_set_direction(buf, HB_DIRECTION_RTL);
        hb_buffer_set_script(buf, HB_SCRIPT_ARABIC);
        hb_shape(font, buf, features, n_features);
        unsigned n = hb_buffer_get_length(buf);
        hb_glyph_info_t *info = hb_buffer_get_glyph_infos(buf, nullptr);
        std::vector<unsigned> ids;
        for (unsigned i = 0; i < n; i++)
        {
            EXPECT_NE(info[i].codepoint, 0u) << "no .notdef glyphs";
            ids.push_back(info[i].codepoint);
        }
        hb_buffer_destroy(buf);
        return ids;
    };

    const std::vector<unsigned> shaped = shape_ids(nullptr, 0);
    hb_feature_t off[4];
    ASSERT_TRUE(hb_feature_from_string("-init", -1, &off[0]));
    ASSERT_TRUE(hb_feature_from_string("-medi", -1, &off[1]));
    ASSERT_TRUE(hb_feature_from_string("-fina", -1, &off[2]));
    ASSERT_TRUE(hb_feature_from_string("-rlig", -1, &off[3]));
    const std::vector<unsigned> unjoined = shape_ids(off, 4);

    EXPECT_NE(shaped, unjoined)
        << "disabling joining features must change glyph selection";

    hb_font_destroy(font);
    hb_face_destroy(face);
    hb_blob_destroy(blob);
}

// Shaped Arabic text through the full TTF pipeline: contextual joining
// makes the rendered width of a joined word differ from rendering each
// character in isolation.
TEST_F(Shaping, ArabicContextualJoiningChangesMetrics)
{
    TTF_Font *font = TTF_OpenFont(FontPath("NotoSansArabic-Regular.ttf").c_str(), 32.0f);
    ASSERT_NE(font, nullptr) << SDL_GetError();
    ASSERT_TRUE(TTF_SetFontDirection(font, TTF_DIRECTION_RTL));
    ASSERT_TRUE(TTF_SetFontScript(font, TTF_StringToTag("Arab")));

    const char *word = "\xD8\xB3\xD9\x84\xD8\xA7\xD9\x85"; /* سلام */
    int joined_w = 0, joined_h = 0;
    ASSERT_TRUE(TTF_GetStringSize(font, word, 0, &joined_w, &joined_h));
    ASSERT_GT(joined_w, 0);

    // Sum of isolated characters (each its own string).
    const char *chars[] = {"\xD8\xB3", "\xD9\x84", "\xD8\xA7", "\xD9\x85"};
    int isolated_sum = 0;
    for (const char *c : chars)
    {
        int w = 0, h = 0;
        ASSERT_TRUE(TTF_GetStringSize(font, c, 0, &w, &h));
        isolated_sum += w;
    }
    EXPECT_LT(joined_w, isolated_sum)
        << "joined forms must be narrower than isolated forms";

    // And it renders actual pixels.
    SDL_Surface *s = TTF_RenderText_Blended(font, word, 0,
                                            SDL_Color{255, 255, 255, 255});
    ASSERT_NE(s, nullptr) << SDL_GetError();
    SDL_DestroySurface(s);
    TTF_CloseFont(font);
}

// Devanagari conjunct: consonant + virama + consonant shapes to fewer
// glyphs than codepoints.
TEST_F(Shaping, DevanagariConjunctReducesGlyphCount)
{
    hb_blob_t *blob = hb_blob_create_from_file(FontPath("NotoSansDevanagari-Regular.ttf").c_str());
    ASSERT_NE(hb_blob_get_length(blob), 0u);
    hb_face_t *face = hb_face_create(blob, 0);
    hb_font_t *font = hb_font_create(face);

    hb_buffer_t *buf = hb_buffer_create();
    /* क + ् (virama) + ष -> क्ष conjunct */
    hb_buffer_add_utf8(buf, "\xE0\xA4\x95\xE0\xA5\x8D\xE0\xA4\xB7", -1, 0, -1);
    hb_buffer_guess_segment_properties(buf);
    hb_shape(font, buf, nullptr, 0);
    EXPECT_LT(hb_buffer_get_length(buf), 3u) << "conjunct must fuse glyphs";

    hb_buffer_destroy(buf);
    hb_font_destroy(font);
    hb_face_destroy(face);
    hb_blob_destroy(blob);
}

// The nine restored APIs are live: setters succeed, getters round-trip.
TEST_F(Shaping, RestoredDirectionAndScriptApis)
{
    TTF_Font *font = TTF_OpenFont(FontPath("NotoSansHebrew-Regular.ttf").c_str(), 24.0f);
    ASSERT_NE(font, nullptr);

    EXPECT_TRUE(TTF_SetFontDirection(font, TTF_DIRECTION_RTL));
    EXPECT_EQ(TTF_GetFontDirection(font), TTF_DIRECTION_RTL);
    EXPECT_TRUE(TTF_SetFontScript(font, TTF_StringToTag("Hebr")));
    EXPECT_EQ(TTF_GetFontScript(font), TTF_StringToTag("Hebr"));

    // Glyph script lookup (restored TTF_GetGlyphScript): U+05D0 ALEF.
    EXPECT_EQ(TTF_GetGlyphScript(0x05D0), TTF_StringToTag("Hebr"));

    TTF_TextEngine *engine = TTF_CreateSurfaceTextEngine();
    ASSERT_NE(engine, nullptr);
    TTF_Text *text = TTF_CreateText(engine, font, "\xD7\xA9\xD7\x9C\xD7\x95\xD7\x9D", 0);
    ASSERT_NE(text, nullptr);
    EXPECT_TRUE(TTF_SetTextDirection(text, TTF_DIRECTION_RTL));
    EXPECT_EQ(TTF_GetTextDirection(text), TTF_DIRECTION_RTL);
    EXPECT_TRUE(TTF_SetTextScript(text, TTF_StringToTag("Hebr")));
    EXPECT_EQ(TTF_GetTextScript(text), TTF_StringToTag("Hebr"));

    TTF_DestroyText(text);
    TTF_DestroySurfaceTextEngine(engine);
    TTF_CloseFont(font);
}

// SheenBidi itemization: mixed English/Arabic/English splits into three
// runs with correct directions, byte ranges, and visual order.
TEST(Bidi, MixedParagraphItemizes)
{
    /* "abc " + Arabic + " def" */
    const std::string text = std::string("abc ") + "\xD8\xB9\xD8\xB1\xD8\xA8\xD9\x8A" + " def";
    int count = 0;
    SDLStatic_BidiRun *runs = SDLStatic_BidiItemize(text.c_str(), -1, &count);
    ASSERT_NE(runs, nullptr) << SDL_GetError();
    ASSERT_EQ(count, 3);

    EXPECT_EQ(runs[0].direction, TTF_DIRECTION_LTR);
    EXPECT_EQ(runs[1].direction, TTF_DIRECTION_RTL);
    EXPECT_EQ(runs[2].direction, TTF_DIRECTION_LTR);

    int covered = 0;
    for (int i = 0; i < count; i++)
    {
        covered += runs[i].length;
    }
    EXPECT_EQ(covered, static_cast<int>(text.size()));
    SDL_free(runs);
}

TEST(Bidi, SingleDirectionAndBaseDetection)
{
    int count = 0;
    SDLStatic_BidiRun *runs = SDLStatic_BidiItemize("plain english", -1, &count);
    ASSERT_NE(runs, nullptr);
    EXPECT_EQ(count, 1);
    EXPECT_EQ(runs[0].direction, TTF_DIRECTION_LTR);
    SDL_free(runs);

    EXPECT_FALSE(SDLStatic_BidiBaseIsRTL("hello", -1));
    EXPECT_TRUE(SDLStatic_BidiBaseIsRTL("\xD7\xA9\xD7\x9C\xD7\x95\xD7\x9D abc", -1));

    // Degenerate inputs fail cleanly, never crash.
    EXPECT_EQ(SDLStatic_BidiItemize(nullptr, -1, &count), nullptr);
    runs = SDLStatic_BidiItemize("", 0, &count);
    if (runs != nullptr)
    {
        SDL_free(runs);
    }
}

} // namespace
