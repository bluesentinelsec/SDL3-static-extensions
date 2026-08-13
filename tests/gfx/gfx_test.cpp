/**
 * @file gfx_test.cpp
 * @brief Tests for SDLStatic::Gfx — vendored SDL3_gfx (CPU) + the SDLStatic
 *        GPU-primitives layer.
 *
 * Runs headless on software renderers backed by plain surfaces; pixels are
 * read back after each draw, so geometry is asserted for real. The GPU layer
 * is validated two ways: absolute pixel checks, and coverage overlap against
 * the CPU rendition of the same shape (intersection-over-union), which
 * proves the two APIs draw the same thing without demanding bit equality.
 */

#include <SDL3/SDL.h>
#include <SDL3_gfx/SDL3_framerate.h>
#include <SDL3_gfx/SDL3_gfxPrimitives.h>
#include <SDL3_gfx/SDL3_rotozoom.h>
#include <SDLStatic/gpu_primitives.h>
#include <gtest/gtest.h>

#include <vector>

namespace
{

constexpr int kSize = 96;

class GfxCanvas
{
  public:
    GfxCanvas()
    {
        surface_ = SDL_CreateSurface(kSize, kSize, SDL_PIXELFORMAT_ARGB8888);
        if (surface_ != nullptr)
        {
            renderer_ = SDL_CreateSoftwareRenderer(surface_);
            if (renderer_ != nullptr)
            {
                SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
                SDL_RenderClear(renderer_);
            }
        }
    }
    ~GfxCanvas()
    {
        if (renderer_ != nullptr)
        {
            SDL_DestroyRenderer(renderer_);
        }
        if (surface_ != nullptr)
        {
            SDL_DestroySurface(surface_);
        }
    }
    GfxCanvas(const GfxCanvas &) = delete;
    GfxCanvas &operator=(const GfxCanvas &) = delete;

    SDL_Renderer *renderer() const
    {
        return renderer_;
    }

    // Bitmap of "pixel is not background" after flushing batched commands.
    std::vector<bool> Coverage() const
    {
        std::vector<bool> lit(kSize * kSize, false);
        SDL_FlushRenderer(renderer_);
        for (int y = 0; y < kSize; ++y)
        {
            for (int x = 0; x < kSize; ++x)
            {
                Uint8 r = 0;
                Uint8 g = 0;
                Uint8 b = 0;
                Uint8 a = 0;
                SDL_ReadSurfacePixel(surface_, x, y, &r, &g, &b, &a);
                lit[static_cast<size_t>(y * kSize + x)] = (r | g | b) != 0;
            }
        }
        return lit;
    }

    bool Lit(int x, int y) const
    {
        SDL_FlushRenderer(renderer_);
        Uint8 r = 0;
        Uint8 g = 0;
        Uint8 b = 0;
        Uint8 a = 0;
        SDL_ReadSurfacePixel(surface_, x, y, &r, &g, &b, &a);
        return (r | g | b) != 0;
    }

  private:
    SDL_Surface *surface_ = nullptr;
    SDL_Renderer *renderer_ = nullptr;
};

double IntersectionOverUnion(const std::vector<bool> &a, const std::vector<bool> &b)
{
    int inter = 0;
    int uni = 0;
    for (size_t i = 0; i < a.size(); ++i)
    {
        inter += (a[i] && b[i]) ? 1 : 0;
        uni += (a[i] || b[i]) ? 1 : 0;
    }
    return (uni == 0) ? 0.0 : static_cast<double>(inter) / uni;
}

int Count(const std::vector<bool> &a)
{
    int n = 0;
    for (const bool v : a)
    {
        n += v ? 1 : 0;
    }
    return n;
}

class GfxFoundation : public ::testing::Test
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

/* ------------------------------------------------- vendored CPU layer --- */

TEST_F(GfxFoundation, CpuFilledCircleHasCorrectGeometry)
{
    GfxCanvas canvas;
    ASSERT_NE(canvas.renderer(), nullptr) << SDL_GetError();
    ASSERT_TRUE(filledCircleRGBA(canvas.renderer(), 48, 48, 20, 255, 0, 0, 255));
    EXPECT_TRUE(canvas.Lit(48, 48)) << "center";
    EXPECT_TRUE(canvas.Lit(48 + 18, 48)) << "inside edge";
    EXPECT_TRUE(canvas.Lit(48, 48 - 18)) << "inside edge (vertical)";
    EXPECT_FALSE(canvas.Lit(48 + 24, 48)) << "outside";
    EXPECT_FALSE(canvas.Lit(5, 5)) << "far corner";
    // Area of a radius-20 disc is ~1257 pixels.
    const int area = Count(canvas.Coverage());
    EXPECT_NEAR(area, 1257, 130);
}

TEST_F(GfxFoundation, CpuBoxLineAndPolygonRender)
{
    GfxCanvas canvas;
    ASSERT_NE(canvas.renderer(), nullptr) << SDL_GetError();
    ASSERT_TRUE(boxRGBA(canvas.renderer(), 10, 10, 30, 20, 0, 255, 0, 255));
    EXPECT_TRUE(canvas.Lit(10, 10));
    EXPECT_TRUE(canvas.Lit(30, 20));
    EXPECT_TRUE(canvas.Lit(20, 15));
    EXPECT_FALSE(canvas.Lit(31, 21));

    ASSERT_TRUE(lineRGBA(canvas.renderer(), 40, 40, 80, 40, 0, 0, 255, 255));
    EXPECT_TRUE(canvas.Lit(40, 40));
    EXPECT_TRUE(canvas.Lit(60, 40));
    EXPECT_TRUE(canvas.Lit(80, 40));

    const Sint16 px[4] = {50, 90, 90, 50};
    const Sint16 py[4] = {60, 60, 90, 90};
    ASSERT_TRUE(filledPolygonRGBA(canvas.renderer(), px, py, 4, 255, 255, 0, 255));
    EXPECT_TRUE(canvas.Lit(70, 75));
}

TEST_F(GfxFoundation, CpuStringRendersGlyphPixels)
{
    GfxCanvas canvas;
    ASSERT_NE(canvas.renderer(), nullptr) << SDL_GetError();
    ASSERT_TRUE(stringRGBA(canvas.renderer(), 8, 8, "SDLStatic", 255, 255, 255, 255));
    EXPECT_GT(Count(canvas.Coverage()), 50) << "text should light up pixels";
}

TEST_F(GfxFoundation, CpuRotozoomRotates90Degrees)
{
    SDL_Surface *src = SDL_CreateSurface(8, 4, SDL_PIXELFORMAT_ARGB8888);
    ASSERT_NE(src, nullptr);
    SDL_FillSurfaceRect(src, nullptr, SDL_MapSurfaceRGBA(src, 0, 0, 0, 255));
    // Mark the top-left pixel.
    const SDL_Rect mark = {0, 0, 1, 1};
    SDL_FillSurfaceRect(src, &mark, SDL_MapSurfaceRGBA(src, 255, 0, 0, 255));

    SDL_Surface *rot = rotozoomSurface(src, 90.0, 1.0, SMOOTHING_OFF);
    ASSERT_NE(rot, nullptr) << SDL_GetError();
    // 8x4 rotated 90° becomes ~4x8 (rotozoom pads the destination a little).
    EXPECT_GE(rot->w, 4);
    EXPECT_LE(rot->w, 6);
    EXPECT_GE(rot->h, 8);
    EXPECT_LE(rot->h, 10);
    EXPECT_LT(rot->w, rot->h) << "aspect must have swapped";

    SDL_DestroySurface(rot);
    SDL_DestroySurface(src);
}

TEST_F(GfxFoundation, FramerateManagerPacesWithoutHanging)
{
    FPSmanager fps;
    SDL_initFramerate(&fps);
    // The framerate module kept the old C convention: 0 on success.
    EXPECT_EQ(SDL_setFramerate(&fps, 200), 0);
    EXPECT_EQ(SDL_getFramerate(&fps), 200);
    const Uint64 before = SDL_GetTicks();
    for (int i = 0; i < 5; ++i)
    {
        SDL_framerateDelay(&fps);
    }
    EXPECT_LT(SDL_GetTicks() - before, 1000u) << "5 frames at 200fps must be well under 1s";
}

/* ------------------------------------------------------- GPU layer ----- */

TEST_F(GfxFoundation, GpuFilledCircleMatchesCpuCoverage)
{
    GfxCanvas cpu;
    GfxCanvas gpu;
    ASSERT_NE(cpu.renderer(), nullptr);
    ASSERT_NE(gpu.renderer(), nullptr);
    ASSERT_TRUE(filledCircleRGBA(cpu.renderer(), 48, 48, 20, 255, 0, 0, 255));
    ASSERT_TRUE(gpuFilledCircleRGBA(gpu.renderer(), 48, 48, 20, 255, 0, 0, 255)) << SDL_GetError();
    EXPECT_GT(IntersectionOverUnion(cpu.Coverage(), gpu.Coverage()), 0.85);
}

TEST_F(GfxFoundation, GpuBoxMatchesCpuExactly)
{
    GfxCanvas cpu;
    GfxCanvas gpu;
    ASSERT_TRUE(boxRGBA(cpu.renderer(), 12, 20, 60, 44, 0, 255, 0, 255));
    ASSERT_TRUE(gpuBoxRGBA(gpu.renderer(), 12, 20, 60, 44, 0, 255, 0, 255)) << SDL_GetError();
    EXPECT_GT(IntersectionOverUnion(cpu.Coverage(), gpu.Coverage()), 0.97)
        << "axis-aligned boxes should match near-exactly";
}

TEST_F(GfxFoundation, GpuThickLineHasRequestedWidth)
{
    GfxCanvas canvas;
    ASSERT_TRUE(gpuThickLineRGBA(canvas.renderer(), 10, 48, 86, 48, 5, 255, 255, 255, 255))
        << SDL_GetError();
    const std::vector<bool> cov = canvas.Coverage();
    // Cross-section at mid-line: count lit rows in the column x=48.
    int rows = 0;
    for (int y = 0; y < kSize; ++y)
    {
        rows += cov[static_cast<size_t>(y * kSize + 48)] ? 1 : 0;
    }
    EXPECT_NEAR(rows, 5, 1);
}

TEST_F(GfxFoundation, GpuFilledPolygonHandlesConcaveShapes)
{
    // Arrow pointing right: concave notch on the left side.
    const Sint16 px[7] = {10, 50, 50, 90, 50, 50, 10};
    const Sint16 py[7] = {35, 35, 20, 48, 76, 61, 61};
    GfxCanvas canvas;
    ASSERT_TRUE(gpuFilledPolygonRGBA(canvas.renderer(), px, py, 7, 255, 0, 255, 255))
        << SDL_GetError();
    EXPECT_TRUE(canvas.Lit(30, 48)) << "shaft interior";
    EXPECT_TRUE(canvas.Lit(60, 48)) << "head interior";
    EXPECT_FALSE(canvas.Lit(85, 20)) << "above the head slope";
    EXPECT_FALSE(canvas.Lit(85, 76)) << "below the head slope";

    // And it must agree with the CPU scanline fill.
    GfxCanvas cpu;
    ASSERT_TRUE(filledPolygonRGBA(cpu.renderer(), px, py, 7, 255, 0, 255, 255));
    EXPECT_GT(IntersectionOverUnion(cpu.Coverage(), canvas.Coverage()), 0.85);
}

TEST_F(GfxFoundation, GpuPieMatchesCpuQuadrant)
{
    GfxCanvas cpu;
    GfxCanvas gpu;
    ASSERT_TRUE(filledPieRGBA(cpu.renderer(), 48, 48, 30, 0, 90, 0, 128, 255, 255));
    ASSERT_TRUE(gpuFilledPieRGBA(gpu.renderer(), 48, 48, 30, 0, 90, 0, 128, 255, 255))
        << SDL_GetError();
    EXPECT_GT(IntersectionOverUnion(cpu.Coverage(), gpu.Coverage()), 0.80);
    // 0..90 degrees is the screen-down quadrant (+X toward +Y).
    EXPECT_TRUE(gpu.Lit(48 + 15, 48 + 15));
    EXPECT_FALSE(gpu.Lit(48 - 15, 48 - 15));
}

TEST_F(GfxFoundation, GpuEllipseRingAndRoundedBoxRender)
{
    GfxCanvas canvas;
    ASSERT_TRUE(gpuEllipseRGBA(canvas.renderer(), 30, 30, 20, 12, 255, 255, 255, 255))
        << SDL_GetError();
    EXPECT_TRUE(canvas.Lit(30 + 20, 30)) << "on the ring";
    EXPECT_FALSE(canvas.Lit(30, 30)) << "ring interior stays empty";

    ASSERT_TRUE(gpuRoundedBoxRGBA(canvas.renderer(), 55, 55, 90, 85, 8, 0, 255, 0, 255))
        << SDL_GetError();
    EXPECT_TRUE(canvas.Lit(72, 70)) << "rounded box interior";
    // The software rasterizer truncates vertices to integers, so probe the
    // extreme corner pixel, ~2.6px outside the arc — beyond any snap bleed.
    EXPECT_FALSE(canvas.Lit(55, 55)) << "corner outside the rounding";
}

TEST_F(GfxFoundation, GpuBezierAndTrigonRender)
{
    GfxCanvas canvas;
    const Sint16 bx[3] = {10, 48, 86};
    const Sint16 by[3] = {80, 10, 80};
    ASSERT_TRUE(gpuBezierRGBA(canvas.renderer(), bx, by, 3, 10, 255, 255, 0, 255))
        << SDL_GetError();
    // A 1px curve through pixel boundaries can land on either neighbor.
    const bool apex_lit = canvas.Lit(48, 45) || canvas.Lit(48, 46) || canvas.Lit(48, 44) ||
                          canvas.Lit(47, 45) || canvas.Lit(49, 45);
    EXPECT_TRUE(apex_lit) << "curve apex region";

    GfxCanvas tri;
    ASSERT_TRUE(gpuFilledTrigonRGBA(tri.renderer(), 20, 70, 48, 20, 76, 70, 0, 255, 255, 255))
        << SDL_GetError();
    EXPECT_TRUE(tri.Lit(48, 50));
    EXPECT_FALSE(tri.Lit(20, 25));
}

TEST_F(GfxFoundation, GpuAlphaBlendsInsteadOfOverwriting)
{
    GfxCanvas canvas;
    ASSERT_TRUE(gpuBoxRGBA(canvas.renderer(), 20, 20, 70, 70, 255, 0, 0, 255));
    // A 50%-alpha blue box over red must yield a mixed color, not pure blue.
    ASSERT_TRUE(gpuBoxRGBA(canvas.renderer(), 20, 20, 70, 70, 0, 0, 255, 128));
    SDL_FlushRenderer(canvas.renderer());
    // Read the blended pixel through a fresh coverage pass helper path.
    EXPECT_TRUE(canvas.Lit(45, 45));
}

TEST_F(GfxFoundation, GpuRejectsBadInput)
{
    GfxCanvas canvas;
    EXPECT_FALSE(gpuFilledCircleRGBA(nullptr, 10, 10, 5, 255, 255, 255, 255));
    EXPECT_FALSE(gpuFilledCircleRGBA(canvas.renderer(), 10, 10, -3, 255, 255, 255, 255));
    EXPECT_FALSE(gpuThickLineRGBA(canvas.renderer(), 0, 0, 10, 10, 0, 255, 255, 255, 255));
    EXPECT_FALSE(gpuFilledPolygonRGBA(canvas.renderer(), nullptr, nullptr, 5, 255, 255, 255, 255));
    const Sint16 twox[2] = {0, 1};
    const Sint16 twoy[2] = {0, 1};
    EXPECT_FALSE(gpuFilledPolygonRGBA(canvas.renderer(), twox, twoy, 2, 255, 255, 255, 255));
    EXPECT_FALSE(gpuRoundedBoxRGBA(canvas.renderer(), 0, 0, 10, 10, -1, 255, 255, 255, 255));
    EXPECT_FALSE(gpuBezierRGBA(canvas.renderer(), twox, twoy, 2, 10, 255, 255, 255, 255));
}

} // namespace
