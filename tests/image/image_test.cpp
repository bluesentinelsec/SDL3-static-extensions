/**
 * @file image_test.cpp
 * @brief Tests for SDLStatic::Image (vendored SDL3_image, static formats only).
 *
 * Covers: every enabled loader against the committed corpus, animation
 * decoding, PNG/JPG save round-trips, and negative proof that the removed
 * heavy-codec formats (AVIF/JXL/TIFF/WEBP) no longer load. The corpus lives
 * in tests/image/assets/ (see its README for provenance).
 */

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

#ifndef IMAGE_TEST_ASSETS_DIR
#error "IMAGE_TEST_ASSETS_DIR must be defined by the build"
#endif

namespace
{

std::string AssetPath(const char *name)
{
    return std::string(IMAGE_TEST_ASSETS_DIR) + "/" + name;
}

class ImageFormats : public ::testing::Test
{
  protected:
    static void SetUpTestSuite()
    {
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
    }
    static void TearDownTestSuite()
    {
        SDL_Quit();
    }
};

struct FormatCase
{
    const char *file;
    bool same_dims_as_reference;  // upstream sample.* share one geometry
};

class LoadSupported : public ImageFormats, public ::testing::WithParamInterface<FormatCase>
{
};

TEST_P(LoadSupported, Loads)
{
    SDL_Surface *surface = IMG_Load(AssetPath(GetParam().file).c_str());
    ASSERT_NE(surface, nullptr) << GetParam().file << ": " << SDL_GetError();
    EXPECT_GT(surface->w, 0) << GetParam().file;
    EXPECT_GT(surface->h, 0) << GetParam().file;

    if (GetParam().same_dims_as_reference)
    {
        SDL_Surface *reference = IMG_Load(AssetPath("sample.bmp").c_str());
        ASSERT_NE(reference, nullptr) << SDL_GetError();
        EXPECT_EQ(surface->w, reference->w) << GetParam().file;
        EXPECT_EQ(surface->h, reference->h) << GetParam().file;
        SDL_DestroySurface(reference);
    }
    SDL_DestroySurface(surface);
}

INSTANTIATE_TEST_SUITE_P(
    Corpus, LoadSupported,
    ::testing::Values(
        FormatCase{"sample.bmp", true},
        FormatCase{"sample.png", true},
        FormatCase{"sample.jpg", true},
        FormatCase{"sample.qoi", true},
        FormatCase{"sample.pnm", true},
        FormatCase{"sample.tga", true},
        FormatCase{"sample.pcx", true},
        FormatCase{"sample.xcf", true},
        FormatCase{"sample.xpm", true},
        FormatCase{"sample.cur", false},
        FormatCase{"sample.ico", false},
        FormatCase{"palette.gif", false},
        FormatCase{"svg.svg", false},
        FormatCase{"generated.lbm", false},
        FormatCase{"generated.xv", false}),
    [](const ::testing::TestParamInfo<FormatCase> &param_info) {
        std::string name = param_info.param.file;
        for (char &c : name)
        {
            if (c == '.' || c == '-')
            {
                c = '_';
            }
        }
        return name;
    });

class LoadRemoved : public ImageFormats, public ::testing::WithParamInterface<const char *>
{
};

TEST_P(LoadRemoved, DoesNotLoad)
{
    SDL_Surface *surface = IMG_Load(AssetPath(GetParam()).c_str());
    EXPECT_EQ(surface, nullptr) << GetParam()
                                << " loaded, but its format was removed from the build";
    if (surface != nullptr)
    {
        SDL_DestroySurface(surface);
    }
}

INSTANTIATE_TEST_SUITE_P(RemovedFormats, LoadRemoved,
                         ::testing::Values("sample.avif", "sample.jxl", "sample.tif",
                                           "rgbrgb.webp"),
                         [](const ::testing::TestParamInfo<const char *> &param_info) {
                             std::string name = param_info.param;
                             for (char &c : name)
                             {
                                 if (c == '.' || c == '-')
                                 {
                                     c = '_';
                                 }
                             }
                             return name;
                         });

TEST_F(ImageFormats, GifAnimationDecodes)
{
    IMG_Animation *anim = IMG_LoadAnimation(AssetPath("rgbrgb.gif").c_str());
    ASSERT_NE(anim, nullptr) << SDL_GetError();
    EXPECT_GE(anim->count, 3);  // rgbrgb = one frame per channel
    EXPECT_GT(anim->w, 0);
    EXPECT_GT(anim->h, 0);
    IMG_FreeAnimation(anim);
}

TEST_F(ImageFormats, VersionIsWired)
{
    EXPECT_GE(IMG_Version(), SDL_VERSIONNUM(3, 4, 4));
}

SDL_Surface *MakeTestSurface()
{
    SDL_Surface *surface = SDL_CreateSurface(8, 8, SDL_PIXELFORMAT_RGBA32);
    if (surface != nullptr)
    {
        SDL_FillSurfaceRect(surface, nullptr, SDL_MapSurfaceRGBA(surface, 200, 100, 50, 255));
    }
    return surface;
}

TEST_F(ImageFormats, PngSaveRoundTripsLosslessly)
{
    SDL_Surface *original = MakeTestSurface();
    ASSERT_NE(original, nullptr) << SDL_GetError();

    SDL_IOStream *io = SDL_IOFromDynamicMem();
    ASSERT_NE(io, nullptr) << SDL_GetError();
    ASSERT_TRUE(IMG_SavePNG_IO(original, io, false)) << SDL_GetError();

    Sint64 size = SDL_GetIOSize(io);
    ASSERT_GT(size, 0);
    ASSERT_EQ(SDL_SeekIO(io, 0, SDL_IO_SEEK_SET), 0);
    SDL_Surface *reloaded = IMG_Load_IO(io, true);
    ASSERT_NE(reloaded, nullptr) << SDL_GetError();

    EXPECT_EQ(reloaded->w, original->w);
    EXPECT_EQ(reloaded->h, original->h);
    Uint8 r = 0, g = 0, b = 0, a = 0;
    ASSERT_TRUE(SDL_ReadSurfacePixel(reloaded, 4, 4, &r, &g, &b, &a));
    EXPECT_EQ(r, 200);
    EXPECT_EQ(g, 100);
    EXPECT_EQ(b, 50);
    EXPECT_EQ(a, 255);

    SDL_DestroySurface(reloaded);
    SDL_DestroySurface(original);
}

TEST_F(ImageFormats, JpgSaveRoundTrips)
{
    SDL_Surface *original = MakeTestSurface();
    ASSERT_NE(original, nullptr) << SDL_GetError();

    SDL_IOStream *io = SDL_IOFromDynamicMem();
    ASSERT_NE(io, nullptr) << SDL_GetError();
    ASSERT_TRUE(IMG_SaveJPG_IO(original, io, false, 90)) << SDL_GetError();

    ASSERT_EQ(SDL_SeekIO(io, 0, SDL_IO_SEEK_SET), 0);
    SDL_Surface *reloaded = IMG_Load_IO(io, true);
    ASSERT_NE(reloaded, nullptr) << SDL_GetError();
    EXPECT_EQ(reloaded->w, original->w);
    EXPECT_EQ(reloaded->h, original->h);

    SDL_DestroySurface(reloaded);
    SDL_DestroySurface(original);
}


// --- API-surface hardening: every kept save path, sized SVG, ANI, encoder ---

class SaveFormats : public ImageFormats, public ::testing::WithParamInterface<const char *>
{
};

TEST_P(SaveFormats, RoundTripsThroughMemory)
{
    SDL_Surface *original = MakeTestSurface();
    ASSERT_NE(original, nullptr) << SDL_GetError();

    SDL_IOStream *io = SDL_IOFromDynamicMem();
    ASSERT_NE(io, nullptr) << SDL_GetError();
    ASSERT_TRUE(IMG_SaveTyped_IO(original, io, false, GetParam()))
        << GetParam() << ": " << SDL_GetError();

    ASSERT_GT(SDL_GetIOSize(io), 0) << GetParam();
    ASSERT_EQ(SDL_SeekIO(io, 0, SDL_IO_SEEK_SET), 0);
    // Typed reload: TGA is magicless (no content sniffer), and the typed
    // path deserves coverage for every encoder anyway.
    SDL_Surface *reloaded = IMG_LoadTyped_IO(io, true, GetParam());
    ASSERT_NE(reloaded, nullptr) << GetParam() << ": " << SDL_GetError();
    EXPECT_EQ(reloaded->w, original->w) << GetParam();
    EXPECT_EQ(reloaded->h, original->h) << GetParam();

    SDL_DestroySurface(reloaded);
    SDL_DestroySurface(original);
}

INSTANTIATE_TEST_SUITE_P(KeptEncoders, SaveFormats,
                         ::testing::Values("bmp", "gif", "ico", "cur", "tga", "png", "jpg"),
                         [](const ::testing::TestParamInfo<const char *> &param_info) {
                             return std::string(param_info.param);
                         });

TEST_F(ImageFormats, SizedSvgRendersAtRequestedResolution)
{
    SDL_IOStream *io = SDL_IOFromFile(AssetPath("svg.svg").c_str(), "rb");
    ASSERT_NE(io, nullptr) << SDL_GetError();
    SDL_Surface *surface = IMG_LoadSizedSVG_IO(io, 128, 128);
    SDL_CloseIO(io);
    ASSERT_NE(surface, nullptr) << SDL_GetError();
    EXPECT_EQ(surface->w, 128);
    EXPECT_EQ(surface->h, 128);
    SDL_DestroySurface(surface);
}

TEST_F(ImageFormats, AniAnimationDecodes)
{
    IMG_Animation *anim = IMG_LoadAnimation(AssetPath("rgbrgb.ani").c_str());
    ASSERT_NE(anim, nullptr) << SDL_GetError();
    EXPECT_GE(anim->count, 2);
    EXPECT_GT(anim->w, 0);
    EXPECT_GT(anim->h, 0);
    IMG_FreeAnimation(anim);
}

TEST_F(ImageFormats, GifAnimationEncodeDecodeRoundTrips)
{
    IMG_Animation *anim = IMG_LoadAnimation(AssetPath("rgbrgb.gif").c_str());
    ASSERT_NE(anim, nullptr) << SDL_GetError();

    SDL_IOStream *io = SDL_IOFromDynamicMem();
    ASSERT_NE(io, nullptr) << SDL_GetError();
    ASSERT_TRUE(IMG_SaveAnimationTyped_IO(anim, io, false, "gif")) << SDL_GetError();

    ASSERT_EQ(SDL_SeekIO(io, 0, SDL_IO_SEEK_SET), 0);
    IMG_Animation *reloaded = IMG_LoadAnimationTyped_IO(io, true, "gif");
    ASSERT_NE(reloaded, nullptr) << SDL_GetError();
    EXPECT_EQ(reloaded->count, anim->count);
    EXPECT_EQ(reloaded->w, anim->w);
    EXPECT_EQ(reloaded->h, anim->h);

    IMG_FreeAnimation(reloaded);
    IMG_FreeAnimation(anim);
}

// --- Malformed-input robustness: truncated and corrupted corpus variants ----
// Every loader must fail cleanly or succeed — never crash. Runs under
// ASan+UBSan in CI, making this continuous memory-safety coverage for all
// parsers we ship.

class MalformedInputs : public ImageFormats, public ::testing::WithParamInterface<const char *>
{
};

std::vector<Uint8> ReadAsset(const char *name)
{
    size_t size = 0;
    void *data = SDL_LoadFile(AssetPath(name).c_str(), &size);
    std::vector<Uint8> bytes;
    if (data != nullptr)
    {
        const Uint8 *p = static_cast<Uint8 *>(data);
        bytes.assign(p, p + size);
        SDL_free(data);
    }
    return bytes;
}

void TryLoadBytes(const std::vector<Uint8> &bytes)
{
    if (bytes.empty())
    {
        return;
    }
    SDL_IOStream *io = SDL_IOFromConstMem(bytes.data(), bytes.size());
    ASSERT_NE(io, nullptr) << SDL_GetError();
    SDL_Surface *surface = IMG_Load_IO(io, true);
    if (surface != nullptr)
    {
        SDL_DestroySurface(surface);  // accepting damaged data is fine; crashing is not
    }

    // Animation path exercises the decoder-creation code (GIF/ANI contexts).
    io = SDL_IOFromConstMem(bytes.data(), bytes.size());
    ASSERT_NE(io, nullptr) << SDL_GetError();
    IMG_Animation *anim = IMG_LoadAnimation_IO(io, true);
    if (anim != nullptr)
    {
        IMG_FreeAnimation(anim);
    }
}

TEST_P(MalformedInputs, TruncationsAndBitFlipsDoNotCrash)
{
    const std::vector<Uint8> original = ReadAsset(GetParam());
    ASSERT_FALSE(original.empty()) << GetParam();

    for (const double fraction : {0.1, 0.25, 0.5, 0.9})
    {
        std::vector<Uint8> truncated(
            original.begin(),
            original.begin() +
                static_cast<std::vector<Uint8>::difference_type>(
                    static_cast<double>(original.size()) * fraction));
        TryLoadBytes(truncated);
    }

    // Deterministic bit flips sprinkled through the file (xorshift PRNG).
    std::vector<Uint8> corrupted = original;
    Uint32 state = 0x2545F491U;
    const size_t flips = corrupted.size() / 16 + 4;
    for (size_t i = 0; i < flips; ++i)
    {
        state ^= state << 13;
        state ^= state >> 17;
        state ^= state << 5;
        corrupted[state % corrupted.size()] ^= static_cast<Uint8>(1U << (state % 8U));
    }
    TryLoadBytes(corrupted);
}

INSTANTIATE_TEST_SUITE_P(Corpus, MalformedInputs,
                         ::testing::Values("sample.bmp", "sample.png", "sample.jpg",
                                           "sample.qoi", "sample.pnm", "sample.tga",
                                           "sample.pcx", "sample.xcf", "sample.xpm",
                                           "sample.cur", "sample.ico", "palette.gif",
                                           "rgbrgb.gif", "rgbrgb.ani", "svg.svg", "generated.lbm",
                                           "generated.xv"),
                         [](const ::testing::TestParamInfo<const char *> &param_info) {
                             std::string name = param_info.param;
                             for (char &c : name)
                             {
                                 if (c == '.' || c == '-')
                                 {
                                     c = '_';
                                 }
                             }
                             return name;
                         });

}  // namespace
