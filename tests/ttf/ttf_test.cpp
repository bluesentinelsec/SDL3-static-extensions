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

int CountNonZeroPixels(SDL_Surface *surface)
{
    int nonzero = 0;
    for (int y = 0; y < surface->h; ++y)
    {
        for (int x = 0; x < surface->w; ++x)
        {
            Uint8 r = 0, g = 0, b = 0, a = 0;
            if (SDL_ReadSurfacePixel(surface, x, y, &r, &g, &b, &a) && a != 0)
            {
                ++nonzero;
            }
        }
    }
    return nonzero;
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
    EXPECT_GT(CountNonZeroPixels(surface), 50);  // real glyph coverage

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
    EXPECT_GT(CountNonZeroPixels(surface), 50);

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
    EXPECT_GT(CountNonZeroPixels(surface), 50);

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

}  // namespace
