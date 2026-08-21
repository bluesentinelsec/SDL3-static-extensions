// The 2D camera: following, bounds, culling, and split screen.
//
// The interesting cases are the ones a game only notices late — a camera
// that is faster on a 144 Hz machine than a 60 Hz one, a level shorter than
// the screen pinned to the left edge, a sprite from player one's half
// spilling into player two's.
#include <SDLStatic/engine_camera.h>

#include <gtest/gtest.h>

namespace
{

class CameraHarness : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
        SDLStatic_EngineConfig config{};
        config.headless = true;
        config.manual_clock = true;
        config.design_width = 1920;
        config.design_height = 1080;
        config.window_width = 1920;
        config.window_height = 1080;
        engine_ = SDLStatic_CreateEngine(&config);
        ASSERT_NE(engine_, nullptr) << SDL_GetError();
    }
    void TearDown() override
    {
        SDLStatic_DestroyEngine(engine_);
        SDL_Quit();
    }

    // Run `seconds` of camera updates at `hz`.
    void Advance(SDLStatic_Camera *camera, float seconds, float hz)
    {
        const float dt = 1.0f / hz;
        for (int i = 0; i < static_cast<int>(seconds * hz); ++i)
        {
            SDLStatic_CameraUpdate(camera, engine_, dt);
        }
    }

    SDLStatic_Engine *engine_ = nullptr;
};

TEST_F(CameraHarness, StartsCoveringTheWholeView)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    EXPECT_FLOAT_EQ(camera.zoom, 1.0f);
    EXPECT_FLOAT_EQ(camera.viewport.w, 1920.0f);
    EXPECT_FLOAT_EQ(camera.viewport.h, 1080.0f);
}

TEST_F(CameraHarness, WithoutSmoothingItTracksExactly)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    SDLStatic_CameraFollow(&camera, 500.0f, 300.0f);
    SDLStatic_CameraUpdate(&camera, engine_, 1.0f / 60.0f);
    EXPECT_FLOAT_EQ(camera.x, 500.0f);
    EXPECT_FLOAT_EQ(camera.y, 300.0f);
}

// The one that bites late: a camera built on "move 10% of the way each
// frame" is nearly two and a half times faster at 144 Hz than at 60, so the
// game feels different on someone else's machine.
TEST_F(CameraHarness, SmoothingIsTheSameAtAnyFrameRate)
{
    auto after_half_a_second = [&](float hz) {
        SDLStatic_Camera camera;
        SDLStatic_CameraInit(&camera, engine_);
        camera.smoothing = 0.2f;
        SDLStatic_CameraFollow(&camera, 1000.0f, 0.0f);
        Advance(&camera, 0.5f, hz);
        return camera.x;
    };

    const float at60 = after_half_a_second(60.0f);
    const float at144 = after_half_a_second(144.0f);
    const float at30 = after_half_a_second(30.0f);

    EXPECT_NEAR(at60, at144, 5.0f) << "same distance covered, whatever the rate";
    EXPECT_NEAR(at60, at30, 15.0f);
    EXPECT_GT(at60, 800.0f) << "and it did most of the way in 2.5 time constants";
    EXPECT_LT(at60, 1000.0f) << "but has not arrived";
}

TEST_F(CameraHarness, SnapIgnoresSmoothing)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    camera.smoothing = 1.0f;
    SDLStatic_CameraSnap(&camera, 4000.0f, 250.0f);
    EXPECT_FLOAT_EQ(camera.x, 4000.0f) << "a scene change must not ease across the level";
    EXPECT_FLOAT_EQ(camera.y, 250.0f);
}

// The deadzone is what stops a platformer's camera twitching every time the
// player hops.
TEST_F(CameraHarness, TheDeadzoneAbsorbsSmallMovements)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    camera.deadzone_w = 400.0f;
    camera.deadzone_h = 200.0f;
    SDLStatic_CameraSnap(&camera, 0.0f, 0.0f);

    // Inside the box: nothing moves.
    SDLStatic_CameraFollow(&camera, 150.0f, 80.0f);
    SDLStatic_CameraUpdate(&camera, engine_, 1.0f / 60.0f);
    EXPECT_FLOAT_EQ(camera.x, 0.0f);
    EXPECT_FLOAT_EQ(camera.y, 0.0f);

    // Outside it: the camera follows just far enough to put the target back
    // on the edge, not all the way to it.
    SDLStatic_CameraFollow(&camera, 500.0f, 0.0f);
    SDLStatic_CameraUpdate(&camera, engine_, 1.0f / 60.0f);
    EXPECT_FLOAT_EQ(camera.x, 300.0f) << "500 minus the 200-unit half-width";
}

// Zoom changes how much world a design-space deadzone covers, so the
// comparison has to happen in world units.
TEST_F(CameraHarness, TheDeadzoneShrinksInWorldUnitsAsYouZoomIn)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    camera.deadzone_w = 400.0f;
    camera.zoom = 2.0f; // half as much world across the same box
    SDLStatic_CameraSnap(&camera, 0.0f, 0.0f);

    SDLStatic_CameraFollow(&camera, 150.0f, 0.0f);
    SDLStatic_CameraUpdate(&camera, engine_, 1.0f / 60.0f);
    EXPECT_FLOAT_EQ(camera.x, 50.0f) << "the half-width is now 100 world units, not 200";
}

TEST_F(CameraHarness, BoundsStopTheCameraLeavingTheLevel)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    camera.bounds = SDL_FRect{0.0f, 0.0f, 8000.0f, 2000.0f};

    SDLStatic_CameraSnap(&camera, -5000.0f, -5000.0f);
    SDLStatic_CameraUpdate(&camera, engine_, 0.0f);
    EXPECT_FLOAT_EQ(camera.x, 960.0f) << "half a 1920-wide view in from the left edge";
    EXPECT_FLOAT_EQ(camera.y, 540.0f);

    SDLStatic_CameraSnap(&camera, 99999.0f, 99999.0f);
    SDLStatic_CameraUpdate(&camera, engine_, 0.0f);
    EXPECT_FLOAT_EQ(camera.x, 8000.0f - 960.0f);
    EXPECT_FLOAT_EQ(camera.y, 2000.0f - 540.0f);
}

// A level narrower than the screen must centre, not sit against one edge.
TEST_F(CameraHarness, ALevelSmallerThanTheViewIsCentred)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    camera.bounds = SDL_FRect{0.0f, 0.0f, 800.0f, 400.0f};
    SDLStatic_CameraSnap(&camera, 0.0f, 0.0f);
    SDLStatic_CameraUpdate(&camera, engine_, 0.0f);
    EXPECT_FLOAT_EQ(camera.x, 400.0f);
    EXPECT_FLOAT_EQ(camera.y, 200.0f);
}

TEST_F(CameraHarness, TheVisibleRectIsWhatToCullAgainst)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    SDLStatic_CameraSnap(&camera, 1000.0f, 500.0f);
    SDLStatic_CameraUpdate(&camera, engine_, 0.0f);

    EXPECT_FLOAT_EQ(camera.visible.w, 1920.0f);
    EXPECT_FLOAT_EQ(camera.visible.x, 1000.0f - 960.0f);

    EXPECT_TRUE(SDLStatic_CameraVisible(&camera, SDL_FRect{990.0f, 490.0f, 20.0f, 20.0f}));
    EXPECT_FALSE(SDLStatic_CameraVisible(&camera, SDL_FRect{9000.0f, 500.0f, 20.0f, 20.0f}));

    // Zooming in halves what is visible.
    camera.zoom = 2.0f;
    SDLStatic_CameraUpdate(&camera, engine_, 0.0f);
    EXPECT_FLOAT_EQ(camera.visible.w, 960.0f);
}

TEST_F(CameraHarness, WorldAndScreenAreInverses)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    camera.zoom = 1.5f;
    SDLStatic_CameraSnap(&camera, 3000.0f, 700.0f);
    SDLStatic_CameraUpdate(&camera, engine_, 0.0f);

    float draw_x = 0.0f;
    float draw_y = 0.0f;
    SDLStatic_CameraPoint(&camera, 3000.0f, 700.0f, &draw_x, &draw_y);
    // The camera's own position lands in the middle of its viewport, in the
    // renderer's pre-scale coordinates.
    EXPECT_NEAR(draw_x, camera.viewport.w / camera.zoom * 0.5f, 0.5f);
    EXPECT_NEAR(draw_y, camera.viewport.h / camera.zoom * 0.5f, 0.5f);

    float world_x = 0.0f;
    float world_y = 0.0f;
    ASSERT_TRUE(SDLStatic_CameraScreenToWorld(&camera, 960.0f, 540.0f, &world_x, &world_y));
    EXPECT_NEAR(world_x, 3000.0f, 0.5f) << "the centre of the screen is what it looks at";
    EXPECT_NEAR(world_y, 700.0f, 0.5f);
}

TEST_F(CameraHarness, RectsTranslateButDoNotScale)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    camera.zoom = 3.0f; // the renderer applies this, so the rect must not
    SDLStatic_CameraSnap(&camera, 0.0f, 0.0f);
    SDLStatic_CameraUpdate(&camera, engine_, 0.0f);

    const SDL_FRect out = SDLStatic_CameraRect(&camera, SDL_FRect{100.0f, 50.0f, 64.0f, 32.0f});
    EXPECT_FLOAT_EQ(out.w, 64.0f) << "scaling here as well would apply the zoom twice";
    EXPECT_FLOAT_EQ(out.h, 32.0f);
}

TEST_F(CameraHarness, ShakeDecaysToNothing)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    SDLStatic_CameraSnap(&camera, 0.0f, 0.0f);
    SDLStatic_CameraShake(&camera, 40.0f, 0.5f);
    EXPECT_GT(camera.shake_remaining, 0.0f);

    // While shaking, the drawn position wanders away from the exact one.
    bool moved = false;
    for (int i = 0; i < 20 && !moved; ++i)
    {
        float x = 0.0f;
        SDLStatic_CameraPoint(&camera, 0.0f, 0.0f, &x, nullptr);
        moved = SDL_fabsf(x - (0.0f - camera.visible.x)) > 0.001f;
    }
    EXPECT_TRUE(moved);

    Advance(&camera, 1.0f, 60.0f);
    EXPECT_FLOAT_EQ(camera.shake_remaining, 0.0f);
    float x = 0.0f;
    SDLStatic_CameraPoint(&camera, 123.0f, 0.0f, &x, nullptr);
    EXPECT_FLOAT_EQ(x, 123.0f - camera.visible.x) << "and stops exactly, not nearly";
}

// A second, weaker explosion must not add to a huge one already running.
TEST_F(CameraHarness, AWeakerShakeDoesNotInterruptAStrongerOne)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    SDLStatic_CameraShake(&camera, 80.0f, 1.0f);
    SDLStatic_CameraShake(&camera, 5.0f, 0.1f);
    EXPECT_FLOAT_EQ(camera.shake_amount, 80.0f);
    EXPECT_FLOAT_EQ(camera.shake_remaining, 1.0f);
}

// --- split screen ---------------------------------------------------------

TEST_F(CameraHarness, OnePlayerGetsTheWholeView)
{
    SDLStatic_Camera cameras[SDLSTATIC_SPLIT_MAX];
    for (SDLStatic_Camera &c : cameras)
    {
        SDLStatic_CameraInit(&c, engine_);
    }
    EXPECT_EQ(SDLStatic_CameraSplit(engine_, SDLSTATIC_SPLIT_VERTICAL, 1, 8.0f, cameras), 1);
    EXPECT_FLOAT_EQ(cameras[0].viewport.w, 1920.0f)
        << "so one player and four share a code path";
    EXPECT_FLOAT_EQ(cameras[0].viewport.h, 1080.0f);
}

TEST_F(CameraHarness, HorizontalSplitStacksFullWidthBands)
{
    SDLStatic_Camera cameras[SDLSTATIC_SPLIT_MAX];
    for (SDLStatic_Camera &c : cameras)
    {
        SDLStatic_CameraInit(&c, engine_);
    }
    ASSERT_EQ(SDLStatic_CameraSplit(engine_, SDLSTATIC_SPLIT_HORIZONTAL, 2, 8.0f, cameras), 2);

    EXPECT_FLOAT_EQ(cameras[0].viewport.w, 1920.0f);
    EXPECT_FLOAT_EQ(cameras[1].viewport.w, 1920.0f);
    EXPECT_FLOAT_EQ(cameras[0].viewport.h, (1080.0f - 8.0f) / 2.0f);
    EXPECT_FLOAT_EQ(cameras[1].viewport.y, cameras[0].viewport.h + 8.0f) << "the gap between";
    // The panes and the gap account for exactly the view.
    EXPECT_FLOAT_EQ(cameras[1].viewport.y + cameras[1].viewport.h, 1080.0f);
}

TEST_F(CameraHarness, VerticalSplitMakesFullHeightColumns)
{
    SDLStatic_Camera cameras[SDLSTATIC_SPLIT_MAX];
    for (SDLStatic_Camera &c : cameras)
    {
        SDLStatic_CameraInit(&c, engine_);
    }
    ASSERT_EQ(SDLStatic_CameraSplit(engine_, SDLSTATIC_SPLIT_VERTICAL, 2, 0.0f, cameras), 2);
    EXPECT_FLOAT_EQ(cameras[0].viewport.w, 960.0f);
    EXPECT_FLOAT_EQ(cameras[0].viewport.h, 1080.0f);
    EXPECT_FLOAT_EQ(cameras[1].viewport.x, 960.0f);
}

TEST_F(CameraHarness, FourPlayersGetQuarters)
{
    SDLStatic_Camera cameras[SDLSTATIC_SPLIT_MAX];
    for (SDLStatic_Camera &c : cameras)
    {
        SDLStatic_CameraInit(&c, engine_);
    }
    ASSERT_EQ(SDLStatic_CameraSplit(engine_, SDLSTATIC_SPLIT_GRID, 4, 0.0f, cameras), 4);
    for (const SDLStatic_Camera &c : cameras)
    {
        EXPECT_FLOAT_EQ(c.viewport.w, 960.0f);
        EXPECT_FLOAT_EQ(c.viewport.h, 540.0f);
    }
    EXPECT_FLOAT_EQ(cameras[3].viewport.x, 960.0f);
    EXPECT_FLOAT_EQ(cameras[3].viewport.y, 540.0f);
}

// Three players in a grid: the odd one out takes the whole bottom half
// rather than leaving a dead quadrant.
TEST_F(CameraHarness, ThreePlayersDoNotLeaveAnEmptyQuadrant)
{
    SDLStatic_Camera cameras[SDLSTATIC_SPLIT_MAX];
    for (SDLStatic_Camera &c : cameras)
    {
        SDLStatic_CameraInit(&c, engine_);
    }
    ASSERT_EQ(SDLStatic_CameraSplit(engine_, SDLSTATIC_SPLIT_GRID, 3, 0.0f, cameras), 3);
    EXPECT_FLOAT_EQ(cameras[2].viewport.w, 1920.0f);
    EXPECT_FLOAT_EQ(cameras[2].viewport.y, 540.0f);
}

TEST_F(CameraHarness, SplittingKeepsEachCamerasSettings)
{
    SDLStatic_Camera cameras[SDLSTATIC_SPLIT_MAX];
    for (SDLStatic_Camera &c : cameras)
    {
        SDLStatic_CameraInit(&c, engine_);
    }
    cameras[1].zoom = 2.5f;
    cameras[1].smoothing = 0.3f;
    SDLStatic_CameraSplit(engine_, SDLSTATIC_SPLIT_VERTICAL, 2, 0.0f, cameras);
    EXPECT_FLOAT_EQ(cameras[1].zoom, 2.5f) << "re-splitting when a player joins must not reset";
    EXPECT_FLOAT_EQ(cameras[1].smoothing, 0.3f);
}

// How a split-screen game works out whose half was clicked.
TEST_F(CameraHarness, ScreenToWorldRejectsTheOtherPlayersHalf)
{
    SDLStatic_Camera cameras[SDLSTATIC_SPLIT_MAX];
    for (SDLStatic_Camera &c : cameras)
    {
        SDLStatic_CameraInit(&c, engine_);
    }
    SDLStatic_CameraSplit(engine_, SDLSTATIC_SPLIT_VERTICAL, 2, 0.0f, cameras);
    SDLStatic_CameraUpdate(&cameras[0], engine_, 0.0f);
    SDLStatic_CameraUpdate(&cameras[1], engine_, 0.0f);

    float wx = 0.0f;
    float wy = 0.0f;
    EXPECT_TRUE(SDLStatic_CameraScreenToWorld(&cameras[0], 100.0f, 100.0f, &wx, &wy));
    EXPECT_FALSE(SDLStatic_CameraScreenToWorld(&cameras[0], 1500.0f, 100.0f, &wx, &wy));
    EXPECT_TRUE(SDLStatic_CameraScreenToWorld(&cameras[1], 1500.0f, 100.0f, &wx, &wy));
}

TEST_F(CameraHarness, NullsAreHandled)
{
    SDLStatic_CameraInit(nullptr, engine_);
    SDLStatic_CameraFollow(nullptr, 1.0f, 1.0f);
    SDLStatic_CameraSnap(nullptr, 1.0f, 1.0f);
    SDLStatic_CameraUpdate(nullptr, engine_, 0.1f);
    SDLStatic_CameraShake(nullptr, 1.0f, 1.0f);
    SDLStatic_CameraEnd(nullptr);
    EXPECT_FALSE(SDLStatic_CameraBegin(engine_, nullptr));
    EXPECT_FALSE(SDLStatic_CameraVisible(nullptr, SDL_FRect{0, 0, 1, 1}));
    EXPECT_FALSE(SDLStatic_CameraScreenToWorld(nullptr, 0.0f, 0.0f, nullptr, nullptr));
    EXPECT_EQ(SDLStatic_CameraSplit(engine_, SDLSTATIC_SPLIT_GRID, 4, 0.0f, nullptr), 0);
}

// Zoom of zero would divide the world by nothing; the update clamps it.
TEST_F(CameraHarness, AbsurdZoomIsClamped)
{
    SDLStatic_Camera camera;
    SDLStatic_CameraInit(&camera, engine_);
    camera.zoom = 0.0f;
    SDLStatic_CameraUpdate(&camera, engine_, 0.016f);
    EXPECT_GT(camera.zoom, 0.0f);
    EXPECT_GT(camera.visible.w, 0.0f);
}

} // namespace
