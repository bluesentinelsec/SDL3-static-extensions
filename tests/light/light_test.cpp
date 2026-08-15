/**
 * @file light_test.cpp
 * @brief SDLStatic::Light — compositing, shadows, falloff, day/night.
 *
 * Lighting is easy to get subtly wrong in ways that still look plausible,
 * so these read pixels: a wall must leave the far side darker than the near
 * side, ambient must scale what was already drawn, and a point behind an
 * occluder must sample as unlit.
 */
#include <SDLStatic/light.h>

#include <gtest/gtest.h>

#include <utility>

namespace
{

constexpr int kScreen = 256;

class LightHarness : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
        surface_ = SDL_CreateSurface(kScreen, kScreen, SDL_PIXELFORMAT_ARGB8888);
        ASSERT_NE(surface_, nullptr);
        renderer_ = SDL_CreateSoftwareRenderer(surface_);
        ASSERT_NE(renderer_, nullptr) << SDL_GetError();
        scene_ = SDLStatic_CreateLightScene(renderer_);
        ASSERT_NE(scene_, nullptr) << SDL_GetError();
    }
    void TearDown() override
    {
        SDLStatic_DestroyLightScene(scene_);
        SDL_DestroyRenderer(renderer_);
        SDL_DestroySurface(surface_);
        SDL_Quit();
    }

    // Paint the whole frame mid-grey: lighting multiplies, so grey shows
    // both darkening and brightening.
    void DrawWorld(Uint8 value = 200)
    {
        SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_NONE);
        SDL_SetRenderDrawColor(renderer_, value, value, value, 255);
        SDL_RenderClear(renderer_);
    }

    int Brightness(int x, int y)
    {
        SDL_FlushRenderer(renderer_);
        const Uint32 pixel = static_cast<const Uint32 *>(surface_->pixels)[y * kScreen + x];
        const int r = (pixel >> 16) & 0xFF;
        const int g = (pixel >> 8) & 0xFF;
        const int b = pixel & 0xFF;
        return (r + g + b) / 3;
    }

    SDL_Surface *surface_ = nullptr;
    SDL_Renderer *renderer_ = nullptr;
    SDLStatic_LightScene *scene_ = nullptr;
};

// Ambient is a multiplier over what is already drawn: black ambient is a
// dark room, white ambient is no lighting at all.
TEST_F(LightHarness, AmbientScalesTheFrame)
{
    DrawWorld(200);
    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f});
    ASSERT_TRUE(SDLStatic_RenderLighting(scene_)) << SDL_GetError();
    EXPECT_NEAR(Brightness(128, 128), 200, 4) << "white ambient must not change the frame";

    DrawWorld(200);
    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.25f, 0.25f, 0.25f, 1.0f});
    ASSERT_TRUE(SDLStatic_RenderLighting(scene_));
    EXPECT_NEAR(Brightness(128, 128), 50, 6) << "quarter ambient is a quarter as bright";

    DrawWorld(200);
    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.0f, 0.0f, 0.0f, 1.0f});
    ASSERT_TRUE(SDLStatic_RenderLighting(scene_));
    EXPECT_LT(Brightness(128, 128), 6) << "a pitch-dark dungeon";
}

// A light brightens what is near it and leaves the far corner dark.
TEST_F(LightHarness, LightFallsOffWithDistance)
{
    DrawWorld(200);
    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.05f, 0.05f, 0.05f, 1.0f});

    SDLStatic_Light torch{};
    torch.x = 128.0f;
    torch.y = 128.0f;
    torch.radius = 90.0f;
    torch.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
    ASSERT_TRUE(SDLStatic_AddLight(scene_, &torch));
    ASSERT_TRUE(SDLStatic_RenderLighting(scene_));

    const int centre = Brightness(128, 128);
    const int middle = Brightness(128 + 45, 128);
    const int edge = Brightness(128 + 85, 128);
    const int outside = Brightness(10, 10);
    EXPECT_GT(centre, 150) << "the light's centre is bright";
    EXPECT_LT(middle, centre);
    EXPECT_LT(edge, middle) << "brightness falls off with distance";
    EXPECT_LT(outside, 20) << "beyond the radius stays dark";
}

// The point of shadows: a wall between the light and a spot leaves that
// spot dark, while the same distance in the clear is lit.
TEST_F(LightHarness, OccludersCastShadows)
{
    DrawWorld(200);
    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.05f, 0.05f, 0.05f, 1.0f});

    // A wall to the right of the light, with a gap above and below.
    const SDL_FRect wall = {150.0f, 100.0f, 12.0f, 56.0f};
    ASSERT_TRUE(SDLStatic_AddOccluderRect(scene_, wall));

    SDLStatic_Light torch{};
    torch.x = 100.0f;
    torch.y = 128.0f;
    torch.radius = 140.0f;
    torch.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
    ASSERT_TRUE(SDLStatic_AddLight(scene_, &torch));
    ASSERT_TRUE(SDLStatic_RenderLighting(scene_));

    // Compare at the *same distance* from the light, or the comparison
    // measures falloff rather than shadowing: (200,128) is 100 units away
    // through the wall, (170,58) is 99 units away with a clear line.
    const int behind_wall = Brightness(200, 128);
    const int beside_wall = Brightness(170, 58);
    EXPECT_LT(behind_wall, 25) << "the wall's shadow must be dark";
    EXPECT_GT(beside_wall, behind_wall + 30) << "and only its shadow";

    // The lit side of the wall is still lit — a shadow starts at the
    // occluder, it does not swallow it.
    EXPECT_GT(Brightness(140, 128), 60) << "the near face is lit";
}

// A light with no_shadows ignores geometry: cheaper, and right for a glow
// that should not be blocked (a HUD light, a magic aura).
TEST_F(LightHarness, ShadowsCanBeDisabledPerLight)
{
    auto brightness_behind = [&](bool no_shadows) {
        DrawWorld(200);
        SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
        SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.05f, 0.05f, 0.05f, 1.0f});
        SDLStatic_AddOccluderRect(scene_, SDL_FRect{150.0f, 100.0f, 12.0f, 56.0f});
        SDLStatic_Light light{};
        light.x = 100.0f;
        light.y = 128.0f;
        light.radius = 140.0f;
        light.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
        light.no_shadows = no_shadows;
        SDLStatic_AddLight(scene_, &light);
        SDLStatic_RenderLighting(scene_);
        return Brightness(200, 128);
    };
    EXPECT_GT(brightness_behind(true), brightness_behind(false) + 40);
}

// A cone lights what it points at and nothing behind it — a lantern, a
// searchlight, a guard's field of view.
TEST_F(LightHarness, ConesLightOnlyTheirDirection)
{
    DrawWorld(200);
    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.05f, 0.05f, 0.05f, 1.0f});

    SDLStatic_Light lantern{};
    lantern.x = 128.0f;
    lantern.y = 128.0f;
    lantern.radius = 110.0f;
    lantern.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
    lantern.angle = 0.0f;                  // pointing +x
    lantern.spread = 60.0f * SDL_PI_F / 180.0f;
    ASSERT_TRUE(SDLStatic_AddLight(scene_, &lantern));
    ASSERT_TRUE(SDLStatic_RenderLighting(scene_));

    EXPECT_GT(Brightness(128 + 60, 128), 90) << "in front of the cone";
    EXPECT_LT(Brightness(128 - 60, 128), 20) << "behind it stays dark";
}

// The camera offset means lights are placed in world coordinates and the
// view can move without touching them.
TEST_F(LightHarness, CameraOffsetsTheLightMap)
{
    DrawWorld(200);
    SDLStatic_LightBeginFrame(scene_, 100.0f, 0.0f); // camera scrolled right
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.05f, 0.05f, 0.05f, 1.0f});
    SDLStatic_Light light{};
    light.x = 228.0f; // world x; screen x = 228 - 100 = 128
    light.y = 128.0f;
    light.radius = 60.0f;
    light.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
    ASSERT_TRUE(SDLStatic_AddLight(scene_, &light));
    ASSERT_TRUE(SDLStatic_RenderLighting(scene_));

    EXPECT_GT(Brightness(128, 128), 120) << "drawn where the camera puts it";
    EXPECT_LT(Brightness(228, 128), 30) << "not at its world position";
}

// The gameplay query: this is what decides whether a guard sees the player.
TEST_F(LightHarness, SampleLightAnswersForGameplay)
{
    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.0f, 0.0f, 0.0f, 1.0f});
    SDLStatic_AddOccluderRect(scene_, SDL_FRect{150.0f, 100.0f, 12.0f, 56.0f});

    SDLStatic_Light torch{};
    torch.x = 100.0f;
    torch.y = 128.0f;
    torch.radius = 140.0f;
    torch.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
    ASSERT_TRUE(SDLStatic_AddLight(scene_, &torch));

    EXPECT_GT(SDLStatic_SampleLight(scene_, 110.0f, 128.0f), 0.7f) << "next to the torch";
    EXPECT_LT(SDLStatic_SampleLight(scene_, 200.0f, 128.0f), 0.05f) << "in the wall's shadow";
    EXPECT_GT(SDLStatic_SampleLight(scene_, 200.0f, 60.0f), 0.1f) << "clear line, further away";
    EXPECT_LT(SDLStatic_SampleLight(scene_, 240.0f, 240.0f), 0.05f) << "out of range";

    // Line of sight is the same test, exposed on its own.
    EXPECT_TRUE(SDLStatic_LightLineOfSight(scene_, 100.0f, 128.0f, 140.0f, 128.0f));
    EXPECT_FALSE(SDLStatic_LightLineOfSight(scene_, 100.0f, 128.0f, 200.0f, 128.0f));
    EXPECT_TRUE(SDLStatic_LightLineOfSight(scene_, 100.0f, 128.0f, 200.0f, 60.0f));

    // Ambient alone still counts as light: a moonlit field is not a cave.
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.5f, 0.5f, 0.5f, 1.0f});
    EXPECT_GT(SDLStatic_SampleLight(scene_, 240.0f, 240.0f), 0.4f);
}

// The day/night ramp has to be continuous — a jump would show as the sky
// snapping between two colours — and dark at midnight.
TEST_F(LightHarness, DayNightCycleIsContinuousAndOrdered)
{
    const SDL_FColor midnight = SDLStatic_DayNightAmbient(0.0f);
    const SDL_FColor dawn = SDLStatic_DayNightAmbient(7.5f);
    const SDL_FColor noon = SDLStatic_DayNightAmbient(13.0f);
    const SDL_FColor dusk = SDLStatic_DayNightAmbient(19.0f);

    auto luminance = [](SDL_FColor c) { return 0.2126f * c.r + 0.7152f * c.g + 0.0722f * c.b; };
    EXPECT_LT(luminance(midnight), 0.2f) << "night is dark";
    EXPECT_GT(luminance(noon), 0.9f) << "midday is bright";
    EXPECT_GT(luminance(dawn), luminance(midnight));
    EXPECT_LT(luminance(dusk), luminance(noon));
    EXPECT_GT(dawn.r, dawn.b) << "dawn is warm";
    EXPECT_GT(dusk.r, dusk.b) << "so is dusk";
    EXPECT_LT(midnight.r, midnight.b) << "night is cool";

    // No discontinuities anywhere around the clock, including the wrap.
    SDL_FColor previous = SDLStatic_DayNightAmbient(0.0f);
    for (float hour = 0.05f; hour <= 24.0f; hour += 0.05f)
    {
        const SDL_FColor current = SDLStatic_DayNightAmbient(hour);
        EXPECT_LT(SDL_fabsf(current.r - previous.r), 0.05f) << "at hour " << hour;
        EXPECT_LT(SDL_fabsf(current.g - previous.g), 0.05f) << "at hour " << hour;
        EXPECT_LT(SDL_fabsf(current.b - previous.b), 0.05f) << "at hour " << hour;
        previous = current;
    }

    // Hours wrap, so a clock can just keep counting.
    const SDL_FColor wrapped = SDLStatic_DayNightAmbient(25.0f);
    const SDL_FColor same = SDLStatic_DayNightAmbient(1.0f);
    EXPECT_FLOAT_EQ(wrapped.r, same.r);
    EXPECT_FLOAT_EQ(SDLStatic_DayNightSunlight(25.0f), SDLStatic_DayNightSunlight(1.0f));

    EXPECT_FLOAT_EQ(SDLStatic_DayNightSunlight(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(SDLStatic_DayNightSunlight(13.0f), 1.0f);
    EXPECT_GT(SDLStatic_DayNightSunlight(10.0f), SDLStatic_DayNightSunlight(7.0f));
}

// Limits are reported rather than silently dropping lights, and every
// entry point survives a null scene.
TEST_F(LightHarness, LimitsAndNullsAreHandled)
{
    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_Light light{};
    light.radius = 10.0f;
    light.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
    for (int i = 0; i < SDLSTATIC_LIGHT_MAX; i++)
    {
        EXPECT_TRUE(SDLStatic_AddLight(scene_, &light)) << "light " << i;
    }
    EXPECT_FALSE(SDLStatic_AddLight(scene_, &light)) << "one past the limit";

    // A zero-radius light is nothing to draw, not an error.
    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_Light empty{};
    EXPECT_TRUE(SDLStatic_AddLight(scene_, &empty));

    for (int i = 0; i < SDLSTATIC_LIGHT_OCCLUDER_MAX / 4; i++)
    {
        EXPECT_TRUE(SDLStatic_AddOccluderRect(scene_, SDL_FRect{0, 0, 1, 1})) << "rect " << i;
    }
    EXPECT_FALSE(SDLStatic_AddOccluderRect(scene_, SDL_FRect{0, 0, 1, 1}));

    EXPECT_EQ(SDLStatic_CreateLightScene(nullptr), nullptr);
    SDLStatic_DestroyLightScene(nullptr);
    SDLStatic_LightBeginFrame(nullptr, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(nullptr, SDL_FColor{});
    EXPECT_FALSE(SDLStatic_AddLight(nullptr, &light));
    EXPECT_FALSE(SDLStatic_AddLight(scene_, nullptr));
    EXPECT_FALSE(SDLStatic_AddOccluderRect(nullptr, SDL_FRect{}));
    EXPECT_FALSE(SDLStatic_AddOccluderSegment(nullptr, 0, 0, 1, 1));
    EXPECT_FALSE(SDLStatic_RenderLighting(nullptr));
    EXPECT_FLOAT_EQ(SDLStatic_SampleLight(nullptr, 0.0f, 0.0f), 0.0f);
    EXPECT_FALSE(SDLStatic_LightLineOfSight(nullptr, 0, 0, 1, 1));
    SDLStatic_SetLightRayCount(nullptr, 32);
    SDLStatic_SetLightRings(nullptr, 2);
    SDLStatic_SetLightDebugDraw(nullptr, true);
}

// Quality settings change the geometry, not the result: a shadow is in the
// same place at 16 rays as at 256.
TEST_F(LightHarness, QualitySettingsKeepShadowsInPlace)
{
    auto shadowed = [&](int rays, int rings) {
        SDLStatic_SetLightRayCount(scene_, rays);
        SDLStatic_SetLightRings(scene_, rings);
        DrawWorld(200);
        SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
        SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.05f, 0.05f, 0.05f, 1.0f});
        SDLStatic_AddOccluderRect(scene_, SDL_FRect{150.0f, 100.0f, 12.0f, 56.0f});
        SDLStatic_Light torch{};
        torch.x = 100.0f;
        torch.y = 128.0f;
        torch.radius = 140.0f;
        torch.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
        SDLStatic_AddLight(scene_, &torch);
        SDLStatic_RenderLighting(scene_);
        return Brightness(200, 128);
    };
    EXPECT_LT(shadowed(16, 1), 25);
    EXPECT_LT(shadowed(256, 6), 25);
}


// The shader path, on a real GL context. Skipped rather than failed where
// one cannot be created (a headless CI box with no GL, a machine whose
// SDL build has no OpenGL renderer) — but when it does run it checks the
// same properties as the geometry path, because the two must agree.
class LightGlHarness : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
        {
            GTEST_SKIP() << "no video subsystem: " << SDL_GetError();
        }
        // Ask for OpenGL specifically; the default is Metal on macOS.
        SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
        window_ = SDL_CreateWindow("light-gl", 256, 256, SDL_WINDOW_HIDDEN | SDL_WINDOW_OPENGL);
        if (window_ == nullptr)
        {
            GTEST_SKIP() << "no window: " << SDL_GetError();
        }
        renderer_ = SDL_CreateRenderer(window_, "opengl");
        if (renderer_ == nullptr)
        {
            GTEST_SKIP() << "no OpenGL renderer: " << SDL_GetError();
        }
        scene_ = SDLStatic_CreateLightScene(renderer_);
        ASSERT_NE(scene_, nullptr) << SDL_GetError();
        if (!SDLStatic_LightUsesShaders(scene_))
        {
            GTEST_SKIP() << "the light shader did not come up on this driver";
        }
    }
    void TearDown() override
    {
        SDLStatic_DestroyLightScene(scene_);
        if (renderer_ != nullptr)
        {
            SDL_DestroyRenderer(renderer_);
        }
        if (window_ != nullptr)
        {
            SDL_DestroyWindow(window_);
        }
        SDL_Quit();
    }

    // Read one pixel back from the window's framebuffer.
    int Brightness(int x, int y)
    {
        SDL_Rect rect = {x, y, 1, 1};
        SDL_Surface *pixel = SDL_RenderReadPixels(renderer_, &rect);
        if (pixel == nullptr)
        {
            return -1;
        }
        Uint8 r = 0, g = 0, b = 0;
        SDL_ReadSurfacePixel(pixel, 0, 0, &r, &g, &b, nullptr);
        SDL_DestroySurface(pixel);
        return (r + g + b) / 3;
    }

    SDL_Window *window_ = nullptr;
    SDL_Renderer *renderer_ = nullptr;
    SDLStatic_LightScene *scene_ = nullptr;
};

TEST_F(LightGlHarness, ShaderPathLightsAndShadows)
{
    SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_NONE);
    SDL_SetRenderDrawColor(renderer_, 200, 200, 200, 255);
    SDL_RenderClear(renderer_);

    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.05f, 0.05f, 0.05f, 1.0f});
    SDLStatic_AddOccluderRect(scene_, SDL_FRect{150.0f, 100.0f, 12.0f, 56.0f});

    SDLStatic_Light torch{};
    torch.x = 100.0f;
    torch.y = 128.0f;
    torch.radius = 140.0f;
    torch.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
    ASSERT_TRUE(SDLStatic_AddLight(scene_, &torch));
    ASSERT_TRUE(SDLStatic_RenderLighting(scene_)) << SDL_GetError();

    const int near_light = Brightness(110, 128);
    const int behind_wall = Brightness(200, 128);
    const int clear_line = Brightness(170, 58);
    ASSERT_GE(near_light, 0) << "could not read the framebuffer";
    EXPECT_GT(near_light, 120) << "the shader lit the area around the torch";
    EXPECT_LT(behind_wall, 40) << "and the wall still casts a shadow";
    EXPECT_GT(clear_line, behind_wall + 20) << "which is a shadow, not distance";
}

// The two paths must agree, or a game would look different on Metal and
// OpenGL. Same scene, same measurements, one with the shader forced off.
TEST_F(LightGlHarness, ShaderAndGeometryPathsAgree)
{
    auto measure = [&](bool shaders) {
        SDLStatic_SetLightUseShaders(scene_, shaders);
        SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_NONE);
        SDL_SetRenderDrawColor(renderer_, 200, 200, 200, 255);
        SDL_RenderClear(renderer_);
        SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
        SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.05f, 0.05f, 0.05f, 1.0f});
        SDLStatic_AddOccluderRect(scene_, SDL_FRect{150.0f, 100.0f, 12.0f, 56.0f});
        SDLStatic_Light torch{};
        torch.x = 100.0f;
        torch.y = 128.0f;
        torch.radius = 140.0f;
        torch.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
        SDLStatic_AddLight(scene_, &torch);
        SDLStatic_RenderLighting(scene_);
        return std::pair<int, int>{Brightness(110, 128), Brightness(200, 128)};
    };
    const auto shader = measure(true);
    const auto geometry = measure(false);

    EXPECT_NEAR(shader.first, geometry.first, 45) << "similar brightness near the light";
    EXPECT_LT(shader.second, 40) << "shader: shadowed";
    EXPECT_LT(geometry.second, 40) << "geometry: shadowed";
}

// Vertical orientation. A scene symmetric about the middle of the screen
// cannot catch a flipped light map — every earlier test here was, and a
// flip sailed through them — so this one puts the light near the top and
// checks the light lands there and not at the mirrored height.
TEST_F(LightGlHarness, LightMapIsNotVerticallyFlipped)
{
    SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_NONE);
    SDL_SetRenderDrawColor(renderer_, 200, 200, 200, 255);
    SDL_RenderClear(renderer_);

    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.05f, 0.05f, 0.05f, 1.0f});
    SDLStatic_Light lamp{};
    lamp.x = 128.0f;
    lamp.y = 40.0f; // near the top
    lamp.radius = 60.0f;
    lamp.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
    ASSERT_TRUE(SDLStatic_AddLight(scene_, &lamp));
    ASSERT_TRUE(SDLStatic_RenderLighting(scene_)) << SDL_GetError();

    EXPECT_GT(Brightness(128, 40), 120) << "lit where the light is";
    EXPECT_LT(Brightness(128, 216), 40) << "and not at the mirrored height";
}

// The same for shadows: an occluder above the light must throw its shadow
// upward, not downward.
TEST_F(LightGlHarness, ShadowsFallOnTheCorrectSide)
{
    SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_NONE);
    SDL_SetRenderDrawColor(renderer_, 200, 200, 200, 255);
    SDL_RenderClear(renderer_);

    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.05f, 0.05f, 0.05f, 1.0f});
    SDLStatic_AddOccluderRect(scene_, SDL_FRect{100.0f, 90.0f, 56.0f, 12.0f});
    SDLStatic_Light lamp{};
    lamp.x = 128.0f;
    lamp.y = 140.0f; // below the bar
    lamp.radius = 150.0f;
    lamp.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
    ASSERT_TRUE(SDLStatic_AddLight(scene_, &lamp));
    ASSERT_TRUE(SDLStatic_RenderLighting(scene_)) << SDL_GetError();

    EXPECT_LT(Brightness(128, 60), 40) << "shadow above the bar";
    EXPECT_GT(Brightness(128, 120), 100) << "lit below it";
}

// Half-resolution light maps are the first performance dial; the lighting
// must still be there afterwards.
TEST_F(LightGlHarness, MapScaleKeepsTheLighting)
{
    SDLStatic_SetLightMapScale(scene_, 0.5f);
    SDL_SetRenderDrawColor(renderer_, 200, 200, 200, 255);
    SDL_RenderClear(renderer_);
    SDLStatic_LightBeginFrame(scene_, 0.0f, 0.0f);
    SDLStatic_SetLightAmbient(scene_, SDL_FColor{0.05f, 0.05f, 0.05f, 1.0f});
    SDLStatic_Light torch{};
    torch.x = 128.0f;
    torch.y = 128.0f;
    torch.radius = 100.0f;
    torch.color = SDL_FColor{1.0f, 1.0f, 1.0f, 1.0f};
    SDLStatic_AddLight(scene_, &torch);
    ASSERT_TRUE(SDLStatic_RenderLighting(scene_)) << SDL_GetError();
    EXPECT_GT(Brightness(128, 128), 120) << "still lit at half resolution";
    EXPECT_LT(Brightness(10, 10), 40) << "and still dark in the corner";
}

} // namespace
