/**
 * @file engine_test.cpp
 * @brief SDLStatic::Engine — the frame loop.
 *
 * "Smooth" is otherwise a matter of opinion, so the loop is built over an
 * injectable clock and these tests assert on the arithmetic that produces
 * smoothness: exact step counts, snapped deltas, bounded catch-up, and an
 * interpolation factor that stays in range.
 */
#include <SDLStatic/engine.h>

#include <gtest/gtest.h>

#include <vector>

namespace
{

constexpr Uint64 kNsPerSecond = 1000000000ull;

// Counts what the loop asked the game to do.
struct Recorder
{
    int fixed_updates = 0;
    int updates = 0;
    int renders = 0;
    int loads = 0;
    int unloads = 0;
    float last_step = 0.0f;
    std::vector<float> alphas;
    std::vector<float> deltas;
};

bool OnLoad(void *user)
{
    static_cast<Recorder *>(user)->loads++;
    return true;
}
void OnFixedUpdate(void *user, float step)
{
    Recorder *r = static_cast<Recorder *>(user);
    r->fixed_updates++;
    r->last_step = step;
}
void OnUpdate(void *user, float dt)
{
    Recorder *r = static_cast<Recorder *>(user);
    r->updates++;
    r->deltas.push_back(dt);
}
void OnRender(void *user, float alpha)
{
    Recorder *r = static_cast<Recorder *>(user);
    r->renders++;
    r->alphas.push_back(alpha);
}
void OnUnload(void *user)
{
    static_cast<Recorder *>(user)->unloads++;
}

SDLStatic_GameHooks MakeHooks()
{
    SDLStatic_GameHooks hooks{};
    hooks.load = OnLoad;
    hooks.fixed_update = OnFixedUpdate;
    hooks.update = OnUpdate;
    hooks.render = OnRender;
    hooks.unload = OnUnload;
    return hooks;
}

class EngineHarness : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
        SDLStatic_EngineConfig config{};
        config.headless = true;
        config.manual_clock = true;
        config.design_width = 640; // a small surface keeps the tests quick
        config.design_height = 360;
        engine_ = SDLStatic_CreateEngine(&config);
        ASSERT_NE(engine_, nullptr) << SDL_GetError();
        hooks_ = MakeHooks();
    }
    void TearDown() override
    {
        SDLStatic_DestroyEngine(engine_);
        SDL_Quit();
    }

    // Run `frames` frames, each advancing the clock by `delta_ns`.
    void RunFrames(int frames, Uint64 delta_ns)
    {
        for (int i = 0; i < frames; i++)
        {
            SDLStatic_EngineAdvance(engine_, delta_ns);
            SDLStatic_EngineTick(engine_);
        }
    }

    SDLStatic_Engine *engine_ = nullptr;
    SDLStatic_GameHooks hooks_{};
};

// A second of frames delivered exactly on time must produce exactly a
// second of simulation — no more, no fewer.
TEST_F(EngineHarness, SteadyFramesProduceExactlyOneSecondOfSimulation)
{
    const Uint64 frame = kNsPerSecond / 60;
    SDLStatic_EngineSetRefreshRate(engine_, 60.0f);
    SDLStatic_EngineAdvance(engine_, 0);

    // 60 frames at 1/60s.
    for (int i = 0; i < 60; i++)
    {
        SDLStatic_EngineAdvance(engine_, frame);
        SDLStatic_EngineTick(engine_);
    }
    EXPECT_EQ(SDLStatic_EngineFrameCount(engine_), 60u);
    EXPECT_FLOAT_EQ(SDLStatic_EngineStep(engine_), 1.0f / 60.0f);
    EXPECT_EQ(SDLStatic_EngineOverloadFrames(engine_), 0);
}

// The point of delta smoothing: noisy frame times must still produce a
// steady simulation rate. Without it, the ±1 ms jitter below leaks into
// every step and shows up as shimmer on anything moving.
TEST_F(EngineHarness, NoisyFrameTimesStillProduceASteadyStepRate)
{
    SDLStatic_EngineSetRefreshRate(engine_, 60.0f);
    const Uint64 nominal = kNsPerSecond / 60;

    int total_steps = 0;
    // Jitter of about ±1 ms, the sort a real machine produces.
    const long long jitter[] = {-900000, 400000, -300000, 1100000, -600000, 200000};
    for (int i = 0; i < 60; i++)
    {
        const Uint64 delta = static_cast<Uint64>(static_cast<long long>(nominal) +
                                                 jitter[i % 6]);
        SDLStatic_EngineAdvance(engine_, delta);
        SDLStatic_EngineTick(engine_);
        total_steps += SDLStatic_EngineStepsLastFrame(engine_);
    }
    EXPECT_EQ(total_steps, 60) << "smoothing should absorb the jitter entirely";
}

// Without a known refresh rate there is nothing to snap to, and the loop
// must still be correct — just not as smooth.
TEST_F(EngineHarness, WithoutARefreshRateTheLoopStillKeepsTime)
{
    SDLStatic_EngineSetRefreshRate(engine_, 0.0f);
    const Uint64 nominal = kNsPerSecond / 60;
    int total_steps = 0;
    for (int i = 0; i < 600; i++)
    {
        SDLStatic_EngineAdvance(engine_, nominal);
        SDLStatic_EngineTick(engine_);
        total_steps += SDLStatic_EngineStepsLastFrame(engine_);
    }
    // 10 seconds of frames, 10 seconds of simulation, within rounding.
    EXPECT_NEAR(total_steps, 600, 2);
}

// A stall is not a slow frame: the time is dropped rather than caught up,
// and the game keeps running.
TEST_F(EngineHarness, AStallDropsTimeInsteadOfSpiralling)
{
    SDLStatic_EngineSetRefreshRate(engine_, 60.0f);
    RunFrames(10, kNsPerSecond / 60);
    const int before = SDLStatic_EngineOverloadFrames(engine_);

    SDLStatic_EngineAdvance(engine_, 2 * kNsPerSecond); // a two-second stall
    SDLStatic_EngineTick(engine_);

    EXPECT_LE(SDLStatic_EngineStepsLastFrame(engine_), 5) << "catch-up must be bounded";
    EXPECT_EQ(SDLStatic_EngineOverloadFrames(engine_), before + 1);

    // And the frame after a stall is normal again — no lingering debt.
    SDLStatic_EngineAdvance(engine_, kNsPerSecond / 60);
    SDLStatic_EngineTick(engine_);
    EXPECT_LE(SDLStatic_EngineStepsLastFrame(engine_), 1);
}

// A 60 Hz simulation on a 144 Hz display: the whole reason interpolation
// exists. Renders happen at the display rate, steps at the tick rate, and
// alpha stays in range so nothing is ever drawn outside the two states it
// is interpolating between.
TEST_F(EngineHarness, HighRefreshDisplayRendersMoreOftenThanItSimulates)
{
    SDLStatic_EngineSetRefreshRate(engine_, 144.0f);
    const Uint64 frame = kNsPerSecond / 144;

    int steps = 0;
    for (int i = 0; i < 144; i++)
    {
        SDLStatic_EngineAdvance(engine_, frame);
        SDLStatic_EngineTick(engine_);
        steps += SDLStatic_EngineStepsLastFrame(engine_);
        const float alpha = SDLStatic_EngineAlpha(engine_);
        EXPECT_GE(alpha, 0.0f);
        EXPECT_LT(alpha, 1.0f) << "frame " << i;
    }
    EXPECT_EQ(SDLStatic_EngineFrameCount(engine_), 144u) << "one render per display frame";
    EXPECT_NEAR(steps, 60, 1) << "but only 60 simulation steps in that second";
}

// Time scale affects simulation only: a paused game still renders, so
// menus animate over a frozen world.
TEST_F(EngineHarness, TimeScaleAffectsSimulationButNotRendering)
{
    SDLStatic_EngineSetRefreshRate(engine_, 60.0f);
    SDLStatic_EngineSetTimeScale(engine_, 0.0f);
    RunFrames(30, kNsPerSecond / 60);
    EXPECT_EQ(SDLStatic_EngineFrameCount(engine_), 30u) << "still rendering";
    EXPECT_EQ(SDLStatic_EngineStepsLastFrame(engine_), 0) << "but not simulating";

    SDLStatic_EngineSetTimeScale(engine_, 2.0f);
    SDLStatic_EngineAdvance(engine_, kNsPerSecond / 60);
    SDLStatic_EngineTick(engine_);
    EXPECT_EQ(SDLStatic_EngineStepsLastFrame(engine_), 2) << "double speed, double steps";
}

// The tick rate is changeable at runtime because an options menu will do
// it, and it must not lose or duplicate accumulated time.
TEST_F(EngineHarness, TickRateChangesAtRuntime)
{
    EXPECT_EQ(SDLStatic_EngineTickRate(engine_), 60);
    SDLStatic_EngineSetRefreshRate(engine_, 120.0f);
    ASSERT_TRUE(SDLStatic_EngineSetTickRate(engine_, 120));
    EXPECT_EQ(SDLStatic_EngineTickRate(engine_), 120);
    EXPECT_FLOAT_EQ(SDLStatic_EngineStep(engine_), 1.0f / 120.0f);

    int steps = 0;
    for (int i = 0; i < 120; i++)
    {
        SDLStatic_EngineAdvance(engine_, kNsPerSecond / 120);
        SDLStatic_EngineTick(engine_);
        steps += SDLStatic_EngineStepsLastFrame(engine_);
    }
    EXPECT_EQ(steps, 120);

    // Out-of-range values clamp rather than break the loop.
    EXPECT_TRUE(SDLStatic_EngineSetTickRate(engine_, 1));
    EXPECT_EQ(SDLStatic_EngineTickRate(engine_), 10);
    EXPECT_TRUE(SDLStatic_EngineSetTickRate(engine_, 100000));
    EXPECT_EQ(SDLStatic_EngineTickRate(engine_), 480);
}

// Interpolation modes: lerp trails the simulation, extrapolate leads it,
// none snaps. Games that cannot afford the render latency need the choice.
TEST_F(EngineHarness, InterpolationModesReportDifferentAlphas)
{
    SDL_Quit(); // rebuild the engine per mode
    auto alpha_after_half_step = [](SDLStatic_EngineInterpolation mode) {
        SDL_Init(0);
        SDLStatic_EngineConfig config{};
        config.headless = true;
        config.manual_clock = true;
        config.design_width = 64;
        config.design_height = 64;
        config.interpolation = mode;
        SDLStatic_Engine *engine = SDLStatic_CreateEngine(&config);
        // Half a step of time: no simulation step, but half-way between.
        SDLStatic_EngineAdvance(engine, kNsPerSecond / 120);
        SDLStatic_EngineTick(engine);
        const float alpha = SDLStatic_EngineAlpha(engine);
        SDLStatic_DestroyEngine(engine);
        SDL_Quit();
        return alpha;
    };

    EXPECT_NEAR(alpha_after_half_step(SDLSTATIC_INTERPOLATE_LERP), 0.5f, 0.01f);
    EXPECT_NEAR(alpha_after_half_step(SDLSTATIC_INTERPOLATE_EXTRAPOLATE), 1.5f, 0.01f);
    EXPECT_FLOAT_EQ(alpha_after_half_step(SDLSTATIC_INTERPOLATE_NONE), 1.0f);
    SDL_Init(0); // TearDown expects an initialised SDL
}

// The hooks fire in the documented order and the right number of times.
TEST_F(EngineHarness, HooksRunInOrder)
{
    Recorder recorder;
    SDLStatic_EngineConfig config{};
    config.headless = true;
    config.manual_clock = true;
    config.design_width = 64;
    config.design_height = 64;
    SDLStatic_Engine *engine = SDLStatic_CreateEngine(&config);
    ASSERT_NE(engine, nullptr);
    SDLStatic_EngineSetRefreshRate(engine, 60.0f);

    // RunGame with a game that quits immediately still runs load, one
    // frame, and unload.
    struct Quitter
    {
        SDLStatic_Engine *engine;
        Recorder *recorder;
    } quitter{engine, &recorder};

    SDLStatic_GameHooks quit_hooks{};
    quit_hooks.update = [](void *user, float dt) {
        (void)dt;
        Quitter *q = static_cast<Quitter *>(user);
        q->recorder->updates++;
        SDLStatic_EngineQuit(q->engine);
    };
    quit_hooks.load = [](void *user) {
        static_cast<Quitter *>(user)->recorder->loads++;
        return true;
    };
    quit_hooks.render = [](void *user, float alpha) {
        (void)alpha;
        static_cast<Quitter *>(user)->recorder->renders++;
    };
    quit_hooks.fixed_update = [](void *user, float step) {
        (void)step;
        static_cast<Quitter *>(user)->recorder->fixed_updates++;
    };
    quit_hooks.unload = [](void *user) {
        static_cast<Quitter *>(user)->recorder->unloads++;
    };

    SDLStatic_EngineAdvance(engine, kNsPerSecond / 60);
    EXPECT_TRUE(SDLStatic_RunGame(engine, &quit_hooks, &quitter));
    EXPECT_EQ(recorder.loads, 1);
    EXPECT_EQ(recorder.unloads, 1);
    EXPECT_EQ(recorder.renders, 1) << "quitting in update still finishes the frame";
    EXPECT_GE(recorder.updates, 1);
    SDLStatic_DestroyEngine(engine);
}

// A failing load aborts before the loop starts.
TEST_F(EngineHarness, AFailedLoadStopsBeforeTheLoop)
{
    SDLStatic_GameHooks hooks{};
    hooks.load = [](void *user) {
        static_cast<Recorder *>(user)->loads++;
        return false;
    };
    hooks.render = OnRender;
    Recorder recorder;
    EXPECT_FALSE(SDLStatic_RunGame(engine_, &hooks, &recorder));
    EXPECT_EQ(recorder.loads, 1);
    EXPECT_EQ(recorder.renders, 0);
}

// Design coordinates are the contract: the game draws in them whatever the
// window is, and window positions convert back into them.
TEST_F(EngineHarness, DesignSpaceIsIndependentOfTheSurface)
{
    int width = 0;
    int height = 0;
    SDLStatic_EngineDesignSize(engine_, &width, &height);
    EXPECT_EQ(width, 640);
    EXPECT_EQ(height, 360);

    float x = 0.0f;
    float y = 0.0f;
    SDLStatic_EngineWindowToDesign(engine_, 320.0f, 180.0f, &x, &y);
    EXPECT_NEAR(x, 320.0f, 1.0f) << "headless: the surface is the design space";
    EXPECT_NEAR(y, 180.0f, 1.0f);
}

// Presentation. A game is written once at a reference resolution and has to
// look right on a 16:9 laptop, a 16:10 monitor and an ultrawide — these
// check what each mode does about the difference.
class PresentationHarness : public ::testing::Test
{
  protected:
    void SetUp() override { ASSERT_TRUE(SDL_Init(0)) << SDL_GetError(); }
    void TearDown() override { SDL_Quit(); }

    // A headless engine whose "display" is `w`x`h` pixels.
    SDLStatic_Engine *Make(int w, int h, SDLStatic_EnginePresentation mode)
    {
        SDLStatic_EngineConfig config{};
        config.headless = true;
        config.manual_clock = true;
        config.design_width = 1920;
        config.design_height = 1080;
        config.window_width = w;
        config.window_height = h;
        config.presentation = mode;
        return SDLStatic_CreateEngine(&config);
    }
};

// An ultrawide window in EXPAND sees *more world*, not black bars.
TEST_F(PresentationHarness, ExpandWidensTheViewOnAWiderDisplay)
{
    SDLStatic_Engine *engine = Make(2560, 1080, SDLSTATIC_PRESENT_EXPAND); // 21:9
    ASSERT_NE(engine, nullptr) << SDL_GetError();

    const SDL_FRect view = SDLStatic_EngineViewRect(engine);
    EXPECT_NEAR(view.h, 1080.0f, 1.0f) << "the design height is kept";
    EXPECT_NEAR(view.w, 2560.0f, 2.0f) << "and the width follows the window";
    EXPECT_GT(view.w, 1920.0f) << "so an ultrawide sees more, not bars";

    // The safe rect stays the design rectangle, centred — where the game
    // was actually composed.
    const SDL_FRect safe = SDLStatic_EngineSafeRect(engine);
    EXPECT_NEAR(safe.w, 1920.0f, 1.0f);
    EXPECT_NEAR(safe.h, 1080.0f, 1.0f);
    EXPECT_NEAR(safe.x, (view.w - 1920.0f) * 0.5f, 1.0f) << "centred in the view";
    EXPECT_GE(safe.x, 0.0f);
    SDLStatic_DestroyEngine(engine);
}

// A taller window in EXPAND gains height instead.
TEST_F(PresentationHarness, ExpandHeightensTheViewOnATallerDisplay)
{
    SDLStatic_Engine *engine = Make(1600, 1200, SDLSTATIC_PRESENT_EXPAND); // 4:3
    ASSERT_NE(engine, nullptr);
    const SDL_FRect view = SDLStatic_EngineViewRect(engine);
    EXPECT_NEAR(view.w, 1920.0f, 1.0f) << "the design width is kept";
    EXPECT_GT(view.h, 1080.0f) << "and the height grows";
    SDLStatic_DestroyEngine(engine);
}

// Letterbox is the opposite promise: the view never changes, and the bars
// are the price.
TEST_F(PresentationHarness, LetterboxKeepsTheViewFixed)
{
    SDLStatic_Engine *engine = Make(2560, 1080, SDLSTATIC_PRESENT_LETTERBOX);
    ASSERT_NE(engine, nullptr);
    const SDL_FRect view = SDLStatic_EngineViewRect(engine);
    EXPECT_NEAR(view.w, 1920.0f, 1.0f);
    EXPECT_NEAR(view.h, 1080.0f, 1.0f);

    // With nothing to reconcile, the safe rect is the whole view.
    const SDL_FRect safe = SDLStatic_EngineSafeRect(engine);
    EXPECT_NEAR(safe.x, 0.0f, 1.0f);
    EXPECT_NEAR(safe.w, view.w, 1.0f);
    SDLStatic_DestroyEngine(engine);
}

// Scale factors: what a game needs to pick art and keep hairlines crisp.
TEST_F(PresentationHarness, ScaleReportsPixelsPerDesignUnit)
{
    struct Case
    {
        int w, h;
        float scale;
        int asset;
    };
    // 1080p is 1:1 with the design; 4K is 2x; a small window is below 1.
    const Case cases[] = {{1920, 1080, 1.0f, 1}, {3840, 2160, 2.0f, 2}, {960, 540, 0.5f, 1}};
    for (const Case &c : cases)
    {
        SDLStatic_Engine *engine = Make(c.w, c.h, SDLSTATIC_PRESENT_LETTERBOX);
        ASSERT_NE(engine, nullptr);
        EXPECT_NEAR(SDLStatic_EngineRenderScale(engine), c.scale, 0.01f)
            << c.w << "x" << c.h;
        EXPECT_EQ(SDLStatic_EngineAssetScale(engine), c.asset) << c.w << "x" << c.h;

        int pixel_w = 0;
        int pixel_h = 0;
        SDLStatic_EnginePixelSize(engine, &pixel_w, &pixel_h);
        EXPECT_EQ(pixel_w, c.w);
        EXPECT_EQ(pixel_h, c.h);
        SDLStatic_DestroyEngine(engine);
    }
}

// In EXPAND the scale is uniform on both axes — the view was chosen to make
// it so, which is why nothing is ever distorted.
TEST_F(PresentationHarness, ExpandKeepsPixelsSquare)
{
    SDLStatic_Engine *engine = Make(2560, 1080, SDLSTATIC_PRESENT_EXPAND);
    ASSERT_NE(engine, nullptr);
    const SDL_FRect view = SDLStatic_EngineViewRect(engine);
    const float sx = 2560.0f / view.w;
    const float sy = 1080.0f / view.h;
    EXPECT_NEAR(sx, sy, 0.01f) << "square pixels, or circles come out as ovals";
    SDLStatic_DestroyEngine(engine);
}

// Native means "coordinates are pixels", which some tools want.
TEST_F(PresentationHarness, NativeMakesDesignUnitsPixels)
{
    SDLStatic_Engine *engine = Make(1024, 768, SDLSTATIC_PRESENT_NATIVE);
    ASSERT_NE(engine, nullptr);
    const SDL_FRect view = SDLStatic_EngineViewRect(engine);
    EXPECT_NEAR(view.w, 1024.0f, 1.0f);
    EXPECT_NEAR(view.h, 768.0f, 1.0f);
    EXPECT_NEAR(SDLStatic_EngineRenderScale(engine), 1.0f, 0.01f);
    SDLStatic_DestroyEngine(engine);
}

// The frame limiter. Vsync is supposed to pace the loop, but an occluded
// window or an indifferent driver will present immediately and let it spin
// at thousands of frames a second. This runs on the real clock — hence the
// generous bound, which is about "did it sleep at all", not "how precisely".
TEST(EngineLimiter, LimitsFramesWhenNothingElsePacesThem)
{
    ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
    SDLStatic_EngineConfig config{};
    config.headless = true; // a software renderer never blocks on present
    config.design_width = 64;
    config.design_height = 64;
    config.max_fps = 100;
    SDLStatic_Engine *engine = SDLStatic_CreateEngine(&config);
    ASSERT_NE(engine, nullptr) << SDL_GetError();
    EXPECT_EQ(SDLStatic_EngineMaxFps(engine), 100);

    const Uint64 start = SDL_GetTicksNS();
    for (int i = 0; i < 10; i++)
    {
        SDLStatic_EngineTick(engine);
    }
    const Uint64 elapsed = SDL_GetTicksNS() - start;
    // Ten frames at 100 fps is 100 ms; assert only that it slept for a
    // decent fraction of that, so a loaded CI machine cannot fail it.
    EXPECT_GT(elapsed, 50000000ull) << "the limiter did not sleep";

    // Negative disables it: the same ten frames should now be quick.
    SDLStatic_EngineSetMaxFps(engine, -1);
    const Uint64 unlimited_start = SDL_GetTicksNS();
    for (int i = 0; i < 10; i++)
    {
        SDLStatic_EngineTick(engine);
    }
    EXPECT_LT(SDL_GetTicksNS() - unlimited_start, elapsed);

    SDLStatic_DestroyEngine(engine);
    SDL_Quit();
}

// Every entry point survives a null engine, as everywhere else in the
// project.
TEST_F(EngineHarness, NullsAreHandled)
{
    SDLStatic_DestroyEngine(nullptr);
    EXPECT_FALSE(SDLStatic_EngineTick(nullptr));
    EXPECT_FALSE(SDLStatic_RunGame(nullptr, nullptr, nullptr));
    SDLStatic_EngineQuit(nullptr);
    EXPECT_FLOAT_EQ(SDLStatic_EngineDelta(nullptr), 0.0f);
    EXPECT_FLOAT_EQ(SDLStatic_EngineAlpha(nullptr), 0.0f);
    EXPECT_FLOAT_EQ(SDLStatic_EngineStep(nullptr), 0.0f);
    EXPECT_EQ(SDLStatic_EngineStepsLastFrame(nullptr), 0);
    EXPECT_EQ(SDLStatic_EngineOverloadFrames(nullptr), 0);
    EXPECT_EQ(SDLStatic_EngineFrameCount(nullptr), 0u);
    EXPECT_FLOAT_EQ(SDLStatic_EngineFps(nullptr), 0.0f);
    SDLStatic_EngineSetMaxFps(nullptr, 60);
    EXPECT_EQ(SDLStatic_EngineMaxFps(nullptr), 0);
    EXPECT_FLOAT_EQ(SDLStatic_EngineViewRect(nullptr).w, 0.0f);
    EXPECT_FLOAT_EQ(SDLStatic_EngineSafeRect(nullptr).w, 0.0f);
    SDLStatic_EnginePixelSize(nullptr, nullptr, nullptr);
    EXPECT_FLOAT_EQ(SDLStatic_EngineRenderScale(nullptr), 1.0f);
    EXPECT_EQ(SDLStatic_EngineAssetScale(nullptr), 1);
    EXPECT_FLOAT_EQ(SDLStatic_EngineTimeScale(nullptr), 0.0f);
    EXPECT_FALSE(SDLStatic_EngineSetTickRate(nullptr, 60));
    EXPECT_EQ(SDLStatic_EngineTickRate(nullptr), 0);
    EXPECT_EQ(SDLStatic_EngineRenderer(nullptr), nullptr);
    EXPECT_EQ(SDLStatic_EngineWindow(nullptr), nullptr);
    SDLStatic_EngineDesignSize(nullptr, nullptr, nullptr);
    SDLStatic_EngineSetClearColor(nullptr, SDL_FColor{});
    SDLStatic_EngineWindowToDesign(nullptr, 0.0f, 0.0f, nullptr, nullptr);
    SDLStatic_EngineAdvance(nullptr, 1);
    SDLStatic_EngineSetRefreshRate(nullptr, 60.0f);
    SDLStatic_EngineSetTimeScale(nullptr, 1.0f);
}

} // namespace
