/**
 * @file image_test.cpp
 * @brief Foundation tests for SDLStatic::Image (vendored SDL3_image).
 *
 * Proves the static library links, initializes against the FetchContent SDL3,
 * and decodes through the real IMG_Load path — the corpus-driven format tests
 * come with the removal/backend hardening passes.
 */

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <gtest/gtest.h>

#include <array>
#include <cstddef>

namespace
{

// Minimal valid 24-bit BMP: 2x2 pixels (BGR rows padded to 4 bytes... 2*3=6 -> pad 2).
constexpr std::array<unsigned char, 70> kTinyBmp = {
    'B', 'M',              // signature
    70,  0,   0,   0,      // file size
    0,   0,   0,   0,      // reserved
    54,  0,   0,   0,      // pixel data offset
    40,  0,   0,   0,      // BITMAPINFOHEADER size
    2,   0,   0,   0,      // width = 2
    2,   0,   0,   0,      // height = 2
    1,   0,               // planes
    24,  0,               // bpp
    0,   0,   0,   0,      // compression = BI_RGB
    16,  0,   0,   0,      // image size (2 rows * 8 bytes)
    0,   0,   0,   0,      // x ppm
    0,   0,   0,   0,      // y ppm
    0,   0,   0,   0,      // colors used
    0,   0,   0,   0,      // important colors
    // row 1 (bottom): blue, green + 2 pad bytes
    255, 0,   0,   0,   255, 0,   0,   0,
    // row 0 (top): red, white + 2 pad bytes
    0,   0,   255, 255, 255, 255, 0,   0,
};

SDL_Surface *LoadTinyBmp()
{
    SDL_IOStream *io = SDL_IOFromConstMem(kTinyBmp.data(), kTinyBmp.size());
    if (io == nullptr)
    {
        return nullptr;
    }
    return IMG_Load_IO(io, true);
}

}  // namespace

TEST(ImageFoundation, VersionIsWired)
{
    EXPECT_GE(IMG_Version(), SDL_VERSIONNUM(3, 4, 4));
}

TEST(ImageFoundation, LoadsBmpFromMemory)
{
    ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
    SDL_Surface *surface = LoadTinyBmp();
    ASSERT_NE(surface, nullptr) << SDL_GetError();
    EXPECT_EQ(surface->w, 2);
    EXPECT_EQ(surface->h, 2);
    SDL_DestroySurface(surface);
    SDL_Quit();
}
