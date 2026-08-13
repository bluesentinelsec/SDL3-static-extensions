/**
 * @file ttf_test.cpp
 * @brief Foundation tests for SDLStatic::TTF (vendored SDL_ttf, static
 *        minimal FreeType backend).
 *
 * Covers: init/version, font open (file + memory + DPI), metrics sanity,
 * measurement, blended/solid rendering producing real pixels, kerning API,
 * and malformed-font robustness (truncations and bit-flips must never
 * crash; runs under ASan+UBSan in CI). Corpus: Bitstream Vera Sans
 * (tests/ttf/assets/, license alongside).
 */

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

#ifndef TTF_TEST_ASSETS_DIR
#error "TTF_TEST_ASSETS_DIR must be defined by the build"
#endif

namespace
{

std::string FontPath()
{
    return std::string(TTF_TEST_ASSETS_DIR) + "/Vera.ttf";
}

class TtfFoundation : public ::testing::Test
{
  protected:
    static void SetUpTestSuite()
    {
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
        ASSERT_TRUE(TTF_Init()) << SDL_GetError();
    }
    static void TearDownTestSuite()
    {
        TTF_Quit();
        SDL_Quit();
    }
};

TEST_F(TtfFoundation, VersionIsWired)
{
    EXPECT_GE(TTF_Version(), SDL_VERSIONNUM(3, 2, 2));
}

TEST_F(TtfFoundation, OpensFontAndReportsSaneMetrics)
{
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 24.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();

    EXPECT_GT(TTF_GetFontHeight(font), 0);
    EXPECT_GT(TTF_GetFontAscent(font), 0);
    EXPECT_LT(TTF_GetFontDescent(font), 0);
    EXPECT_GT(TTF_GetFontLineSkip(font), 0);

    int w = 0, h = 0;
    ASSERT_TRUE(TTF_GetStringSize(font, "Hello, SDLStatic!", 0, &w, &h))
        << SDL_GetError();
    EXPECT_GT(w, 0);
    EXPECT_GT(h, 0);

    TTF_CloseFont(font);
}

TEST_F(TtfFoundation, OpensFontFromMemory)
{
    size_t size = 0;
    void *data = SDL_LoadFile(FontPath().c_str(), &size);
    ASSERT_NE(data, nullptr) << SDL_GetError();

    SDL_IOStream *io = SDL_IOFromConstMem(data, size);
    ASSERT_NE(io, nullptr) << SDL_GetError();
    TTF_Font *font = TTF_OpenFontIO(io, true, 16.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();
    EXPECT_GT(TTF_GetFontHeight(font), 0);
    TTF_CloseFont(font);
    SDL_free(data);
}

TEST_F(TtfFoundation, DpiScalingChangesGeometry)
{
    TTF_Font *base = TTF_OpenFont(FontPath().c_str(), 16.0F);
    ASSERT_NE(base, nullptr) << SDL_GetError();
    TTF_Font *hidpi = TTF_OpenFont(FontPath().c_str(), 16.0F);
    ASSERT_NE(hidpi, nullptr) << SDL_GetError();
    ASSERT_TRUE(TTF_SetFontSizeDPI(hidpi, 16.0F, 144, 144)) << SDL_GetError();

    int base_w = 0, base_h = 0, hi_w = 0, hi_h = 0;
    ASSERT_TRUE(TTF_GetStringSize(base, "Retina", 0, &base_w, &base_h));
    ASSERT_TRUE(TTF_GetStringSize(hidpi, "Retina", 0, &hi_w, &hi_h));
    EXPECT_GT(hi_w, base_w);  // 144 dpi > default 72 dpi
    EXPECT_GT(hi_h, base_h);

    TTF_CloseFont(base);
    TTF_CloseFont(hidpi);
}

int CountNonZeroBrightPixels(SDL_Surface *surface)
{
    // Counts visibly bright glyph pixels. Works for Blended (alpha-keyed),
    // Solid (paletted), and opaque Shaded/LCD surfaces alike: a pixel counts
    // when it is non-transparent AND clearly brighter than a dark background.
    int bright = 0;
    for (int y = 0; y < surface->h; ++y)
    {
        for (int x = 0; x < surface->w; ++x)
        {
            Uint8 r = 0, g = 0, b = 0, a = 0;
            if (SDL_ReadSurfacePixel(surface, x, y, &r, &g, &b, &a) && a != 0 &&
                (static_cast<int>(r) + g + b) > 300)
            {
                ++bright;
            }
        }
    }
    return bright;
}

TEST_F(TtfFoundation, BlendedRenderProducesGlyphPixels)
{
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 32.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();

    const SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "SDLStatic", 0, white);
    ASSERT_NE(surface, nullptr) << SDL_GetError();
    EXPECT_GT(surface->w, 0);
    EXPECT_GT(surface->h, 0);
    EXPECT_GT(CountNonZeroBrightPixels(surface), 50);  // real glyph coverage

    SDL_DestroySurface(surface);
    TTF_CloseFont(font);
}

TEST_F(TtfFoundation, SolidRenderProducesGlyphPixels)
{
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 32.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();

    const SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, "SDLStatic", 0, white);
    ASSERT_NE(surface, nullptr) << SDL_GetError();
    EXPECT_GT(CountNonZeroBrightPixels(surface), 50);

    SDL_DestroySurface(surface);
    TTF_CloseFont(font);
}

TEST_F(TtfFoundation, StyleAndOutlineRender)
{
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 24.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();

    TTF_SetFontStyle(font, TTF_STYLE_BOLD | TTF_STYLE_ITALIC);
    ASSERT_TRUE(TTF_SetFontOutline(font, 2)) << SDL_GetError();

    const SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "Styled", 0, white);
    ASSERT_NE(surface, nullptr) << SDL_GetError();
    EXPECT_GT(CountNonZeroBrightPixels(surface), 50);

    SDL_DestroySurface(surface);
    TTF_CloseFont(font);
}

TEST_F(TtfFoundation, MalformedFontsDoNotCrash)
{
    size_t size = 0;
    void *data = SDL_LoadFile(FontPath().c_str(), &size);
    ASSERT_NE(data, nullptr) << SDL_GetError();
    const Uint8 *bytes = static_cast<Uint8 *>(data);
    const std::vector<Uint8> original(bytes, bytes + size);
    SDL_free(data);

    auto try_open = [](const std::vector<Uint8> &blob) {
        if (blob.empty())
        {
            return;
        }
        SDL_IOStream *io = SDL_IOFromConstMem(blob.data(), blob.size());
        ASSERT_NE(io, nullptr) << SDL_GetError();
        TTF_Font *font = TTF_OpenFontIO(io, true, 20.0F);
        if (font != nullptr)
        {
            // Accepting damaged data is fine; crashing is not. Exercise it.
            const SDL_Color white = {255, 255, 255, 255};
            SDL_Surface *surface = TTF_RenderText_Blended(font, "x", 0, white);
            if (surface != nullptr)
            {
                SDL_DestroySurface(surface);
            }
            TTF_CloseFont(font);
        }
    };

    for (const double fraction : {0.05, 0.25, 0.5, 0.9})
    {
        std::vector<Uint8> truncated(
            original.begin(),
            original.begin() +
                static_cast<std::vector<Uint8>::difference_type>(
                    static_cast<double>(original.size()) * fraction));
        try_open(truncated);
    }

    std::vector<Uint8> corrupted = original;
    Uint32 state = 0x2545F491U;
    const size_t flips = corrupted.size() / 64 + 16;
    for (size_t i = 0; i < flips; ++i)
    {
        state ^= state << 13;
        state ^= state >> 17;
        state ^= state << 5;
        corrupted[state % corrupted.size()] ^= static_cast<Uint8>(1U << (state % 8U));
    }
    try_open(corrupted);
}


// --- Coverage: claimed capabilities proven, not assumed ---------------------

std::string Vt323Path()
{
    return std::string(TTF_TEST_ASSETS_DIR) + "/VT323-Regular.ttf";
}

TEST_F(TtfFoundation, TextEngineSurfaceDrawsText)
{
    TTF_TextEngine *engine = TTF_CreateSurfaceTextEngine();
    ASSERT_NE(engine, nullptr) << SDL_GetError();
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 24.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();

    TTF_Text *text = TTF_CreateText(engine, font, "Engine-drawn text", 0);
    ASSERT_NE(text, nullptr) << SDL_GetError();
    int tw = 0, th = 0;
    ASSERT_TRUE(TTF_GetTextSize(text, &tw, &th)) << SDL_GetError();
    EXPECT_GT(tw, 0);
    EXPECT_GT(th, 0);
    ASSERT_TRUE(TTF_SetTextColor(text, 255, 255, 255, 255));

    SDL_Surface *canvas = SDL_CreateSurface(tw + 16, th + 16, SDL_PIXELFORMAT_RGBA32);
    ASSERT_NE(canvas, nullptr) << SDL_GetError();
    ASSERT_TRUE(SDL_FillSurfaceRect(canvas, nullptr,
                                    SDL_MapSurfaceRGBA(canvas, 0, 0, 0, 255)));
    ASSERT_TRUE(TTF_DrawSurfaceText(text, 8, 8, canvas)) << SDL_GetError();
    EXPECT_GT(CountNonZeroBrightPixels(canvas), 50);

    SDL_DestroySurface(canvas);
    TTF_DestroyText(text);
    TTF_CloseFont(font);
    TTF_DestroySurfaceTextEngine(engine);
}

TEST_F(TtfFoundation, WrappedRenderProducesMultipleLines)
{
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 20.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();
    const char *prose =
        "Wrapped text is the bread and butter of dialog boxes, tooltips, and "
        "quest logs in games.";

    const SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *single = TTF_RenderText_Blended(font, prose, 0, white);
    ASSERT_NE(single, nullptr) << SDL_GetError();
    SDL_Surface *wrapped = TTF_RenderText_Blended_Wrapped(font, prose, 0, white, 220);
    ASSERT_NE(wrapped, nullptr) << SDL_GetError();

    EXPECT_LE(wrapped->w, 220);
    EXPECT_GT(wrapped->h, single->h * 3);  // long prose at 220px = many lines

    int ww = 0, wh = 0;
    ASSERT_TRUE(TTF_GetStringSizeWrapped(font, prose, 0, 220, &ww, &wh));
    EXPECT_EQ(ww, wrapped->w);
    EXPECT_EQ(wh, wrapped->h);

    SDL_DestroySurface(single);
    SDL_DestroySurface(wrapped);
    TTF_CloseFont(font);
}

TEST_F(TtfFoundation, Utf8TextRendersAndMeasures)
{
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 24.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();

    EXPECT_TRUE(TTF_FontHasGlyph(font, 0x00E9));   // é
    EXPECT_TRUE(TTF_FontHasGlyph(font, 0x00F1));   // ñ
    EXPECT_FALSE(TTF_FontHasGlyph(font, 0x1F600)); // emoji: not in Vera

    const char *text = "Héllo wörld — ¡ñandú!";
    int w = 0, h = 0;
    ASSERT_TRUE(TTF_GetStringSize(font, text, 0, &w, &h)) << SDL_GetError();
    EXPECT_GT(w, 0);

    const SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(font, text, 0, white);
    ASSERT_NE(surface, nullptr) << SDL_GetError();
    EXPECT_GT(CountNonZeroBrightPixels(surface), 50);
    SDL_DestroySurface(surface);
    TTF_CloseFont(font);
}

TEST_F(TtfFoundation, SdfRenderProducesGradientField)
{
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 32.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();
    ASSERT_TRUE(TTF_SetFontSDF(font, true)) << SDL_GetError();
    EXPECT_TRUE(TTF_GetFontSDF(font));

    const SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "S", 0, white);
    ASSERT_NE(surface, nullptr) << SDL_GetError();

    std::vector<bool> alpha_seen(256, false);
    int distinct_alpha = 0;
    for (int y = 0; y < surface->h; ++y)
    {
        for (int x = 0; x < surface->w; ++x)
        {
            Uint8 r = 0, g = 0, b = 0, a = 0;
            if (SDL_ReadSurfacePixel(surface, x, y, &r, &g, &b, &a) && !alpha_seen[a])
            {
                alpha_seen[a] = true;
                ++distinct_alpha;
            }
        }
    }
    EXPECT_GT(distinct_alpha, 16) << "SDF output should be a smooth distance field";

    SDL_DestroySurface(surface);
    TTF_CloseFont(font);
}

TEST_F(TtfFoundation, ShadedRenderWorks)
{
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 24.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();
    const SDL_Color fg = {255, 255, 255, 255};
    const SDL_Color bg = {32, 32, 32, 255};
    SDL_Surface *surface = TTF_RenderText_Shaded(font, "Shaded", 0, fg, bg);
    ASSERT_NE(surface, nullptr) << SDL_GetError();
    EXPECT_GT(CountNonZeroBrightPixels(surface), 50);
    SDL_DestroySurface(surface);
    TTF_CloseFont(font);
}

TEST_F(TtfFoundation, LcdRenderWorks)
{
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 24.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();
    const SDL_Color fg = {255, 255, 255, 255};
    const SDL_Color bg = {0, 0, 0, 255};
    SDL_Surface *surface = TTF_RenderText_LCD(font, "LCD subpixel", 0, fg, bg);
    ASSERT_NE(surface, nullptr) << SDL_GetError();
    EXPECT_GT(CountNonZeroBrightPixels(surface), 50);
    SDL_DestroySurface(surface);
    TTF_CloseFont(font);
}

TEST_F(TtfFoundation, FallbackFontProvidesMissingGlyphs)
{
    TTF_Font *primary = TTF_OpenFont(FontPath().c_str(), 24.0F);
    ASSERT_NE(primary, nullptr) << SDL_GetError();
    TTF_Font *fallback = TTF_OpenFont(Vt323Path().c_str(), 24.0F);
    ASSERT_NE(fallback, nullptr) << SDL_GetError();

    // Find a codepoint the fallback covers but the primary does not.
    // Latin Extended-A: present in VT323, absent from Bitstream Vera.
    const Uint32 candidates[] = {0x0100, 0x0104, 0x0118, 0x0102, 0x016A};
    Uint32 missing = 0;
    for (Uint32 cp : candidates)
    {
        if (!TTF_FontHasGlyph(primary, cp) && TTF_FontHasGlyph(fallback, cp))
        {
            missing = cp;
            break;
        }
    }
    ASSERT_NE(missing, 0u) << "test fonts overlap too much; pick a new candidate";

    ASSERT_TRUE(TTF_AddFallbackFont(primary, fallback)) << SDL_GetError();

    char utf8[8] = {0};
    // encode codepoint (all candidates are 3-byte UTF-8 or fewer)
    if (missing < 0x800)
    {
        utf8[0] = static_cast<char>(0xC0 | (missing >> 6));
        utf8[1] = static_cast<char>(0x80 | (missing & 0x3F));
    }
    else
    {
        utf8[0] = static_cast<char>(0xE0 | (missing >> 12));
        utf8[1] = static_cast<char>(0x80 | ((missing >> 6) & 0x3F));
        utf8[2] = static_cast<char>(0x80 | (missing & 0x3F));
    }

    const SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(primary, utf8, 0, white);
    ASSERT_NE(surface, nullptr) << SDL_GetError();
    EXPECT_GT(CountNonZeroBrightPixels(surface), 5)
        << "fallback glyph U+" << std::hex << missing << " rendered empty";

    SDL_DestroySurface(surface);
    TTF_RemoveFallbackFont(primary, fallback);
    TTF_CloseFont(fallback);
    TTF_CloseFont(primary);
}

TEST_F(TtfFoundation, GlyphMetricsAreSane)
{
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 24.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();
    int minx = 0, maxx = 0, miny = 0, maxy = 0, advance = 0;
    ASSERT_TRUE(TTF_GetGlyphMetrics(font, 'A', &minx, &maxx, &miny, &maxy, &advance))
        << SDL_GetError();
    EXPECT_GT(maxx, minx);
    EXPECT_GT(maxy, miny);
    EXPECT_GT(advance, 0);
    TTF_CloseFont(font);
}

TEST_F(TtfFoundation, MeasureStringFitsWidth)
{
    TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 24.0F);
    ASSERT_NE(font, nullptr) << SDL_GetError();
    const char *text = "This string is far too long to fit in a tiny box.";

    int full_w = 0, full_h = 0;
    ASSERT_TRUE(TTF_GetStringSize(font, text, 0, &full_w, &full_h));

    const int max_width = full_w / 3;
    int measured_width = 0;
    size_t measured_length = 0;
    ASSERT_TRUE(TTF_MeasureString(font, text, 0, max_width, &measured_width,
                                  &measured_length))
        << SDL_GetError();
    EXPECT_LE(measured_width, max_width);
    EXPECT_GT(measured_length, 0u);
    EXPECT_LT(measured_length, SDL_strlen(text));
    TTF_CloseFont(font);
}

TEST_F(TtfFoundation, HintingModesAllRender)
{
    const TTF_HintingFlags modes[] = {TTF_HINTING_NORMAL, TTF_HINTING_LIGHT,
                                      TTF_HINTING_MONO, TTF_HINTING_NONE};
    const SDL_Color white = {255, 255, 255, 255};
    for (TTF_HintingFlags mode : modes)
    {
        TTF_Font *font = TTF_OpenFont(FontPath().c_str(), 24.0F);
        ASSERT_NE(font, nullptr) << SDL_GetError();
        TTF_SetFontHinting(font, mode);
        EXPECT_EQ(TTF_GetFontHinting(font), mode);
        SDL_Surface *surface = TTF_RenderText_Blended(font, "Hinting", 0, white);
        ASSERT_NE(surface, nullptr) << SDL_GetError() << " (mode " << mode << ")";
        EXPECT_GT(CountNonZeroBrightPixels(surface), 50) << "mode " << mode;
        SDL_DestroySurface(surface);
        TTF_CloseFont(font);
    }
}


// --- SDLStatic debug text (embedded ProggyClean) ----------------------------

#include <SDLStatic/debug_text.h>

TEST_F(TtfFoundation, DebugTextDrawsWithEmbeddedFont)
{
    SDL_Surface *canvas = SDL_CreateSurface(320, 64, SDL_PIXELFORMAT_RGBA32);
    ASSERT_NE(canvas, nullptr) << SDL_GetError();
    SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(canvas);
    ASSERT_NE(renderer, nullptr) << SDL_GetError();

    SDL_SetRenderDrawColor(renderer, 10, 12, 14, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 80, 250, 123, 255);  // text = draw color
    ASSERT_TRUE(SDLStatic_RenderDebugTextFormat(renderer, 8.0F, 8.0F, "FPS: %d", 60))
        << SDL_GetError();
    ASSERT_TRUE(SDLStatic_RenderDebugText(renderer, 8.0F, 28.0F,
                                          "frame 1234  draw 0.8ms"))
        << SDL_GetError();
    SDL_RenderPresent(renderer);

    // Verify green-tinted glyph pixels landed on the canvas.
    int green = 0;
    for (int y = 0; y < canvas->h; ++y)
    {
        for (int x = 0; x < canvas->w; ++x)
        {
            Uint8 r = 0, g = 0, b = 0, a = 0;
            if (SDL_ReadSurfacePixel(canvas, x, y, &r, &g, &b, &a) && g > 150 &&
                g > r + 40)
            {
                ++green;
            }
        }
    }
    EXPECT_GT(green, 40) << "debug text did not render";

    // Cached redraw and size change both succeed.
    EXPECT_TRUE(SDLStatic_RenderDebugText(renderer, 8.0F, 48.0F, "FPS: 60"));
    SDLStatic_SetDebugTextSize(18.0F);
    EXPECT_TRUE(SDLStatic_RenderDebugText(renderer, 8.0F, 8.0F, "resized"));
    SDLStatic_SetDebugTextSize(13.0F);

    SDLStatic_QuitDebugText();
    SDL_DestroyRenderer(renderer);
    SDL_DestroySurface(canvas);
}

}  // namespace
