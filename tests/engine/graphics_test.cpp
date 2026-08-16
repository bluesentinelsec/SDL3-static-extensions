// Graphics settings: defaults, validation, and the four places a value can
// come from.
//
// Most of what can go wrong here is a config file lying to the engine — a
// hand-edited brightness of 40, a quality tier nobody has heard of, a frame
// cap of 2. So the tests lean on the clamping and on the precedence order,
// which is the part a player notices when it is wrong ("I changed the
// setting and nothing happened").
#include <SDLStatic/engine_graphics.h>

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace
{

// argv the way main() gets it: a program name, then the arguments.
class Args
{
  public:
    explicit Args(std::vector<std::string> args) : storage_(std::move(args))
    {
        pointers_.reserve(storage_.size());
        for (std::string &s : storage_)
        {
            pointers_.push_back(s.data());
        }
    }
    int argc() const { return static_cast<int>(pointers_.size()); }
    char *const *argv() const { return pointers_.data(); }

  private:
    std::vector<std::string> storage_;
    std::vector<char *> pointers_;
};

// The parts of the defaults that are not about fidelity: pacing, the
// coordinate space, and the neutral image. What "maximum fidelity" means is
// covered by GraphicsShippingDefaults below.
TEST(GraphicsDefaults, ArePacedAndNeutral)
{
    const SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();

    EXPECT_TRUE(s.vsync);
    EXPECT_EQ(s.max_fps, 0) << "follow the display";
    EXPECT_EQ(s.presentation, SDLSTATIC_PRESENT_LETTERBOX);
    EXPECT_FLOAT_EQ(s.render_scale, 1.0f);
    EXPECT_EQ(s.filter, SDLSTATIC_FILTER_AUTO);

    // A neutral image: the grade is what the artist chose.
    EXPECT_FLOAT_EQ(s.brightness, 1.0f);
    EXPECT_FLOAT_EQ(s.contrast, 1.0f);
    EXPECT_FLOAT_EQ(s.saturation, 1.0f);
    EXPECT_FLOAT_EQ(s.screen_shake, 1.0f);
    EXPECT_FLOAT_EQ(s.ui_scale, 1.0f);
}

// A config file is a text file a human edits, so it will eventually contain
// something impossible. None of it may reach the renderer.
TEST(GraphicsClamp, PullsNonsenseBackIntoRange)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    s.brightness = 40.0f;
    s.contrast = -3.0f;
    s.saturation = 99.0f;
    s.render_scale = 0.0f;
    s.bloom = 5.0f;
    s.pixelation = -2;
    s.max_fps = 2;
    s.ui_scale = 100.0f;
    s.screen_shake = -1.0f;
    s.particles = static_cast<SDLStatic_GraphicsQuality>(77);
    s.presentation = static_cast<SDLStatic_EnginePresentation>(-4);

    SDLStatic_GraphicsClamp(&s);

    EXPECT_FLOAT_EQ(s.brightness, 2.0f);
    EXPECT_FLOAT_EQ(s.contrast, 0.5f);
    EXPECT_FLOAT_EQ(s.saturation, 2.0f);
    EXPECT_FLOAT_EQ(s.render_scale, 0.25f) << "zero would render nothing";
    EXPECT_FLOAT_EQ(s.bloom, 1.0f);
    EXPECT_EQ(s.pixelation, 1);
    EXPECT_EQ(s.max_fps, 10) << "a 2 fps cap looks like a hang, not a preference";
    EXPECT_FLOAT_EQ(s.ui_scale, 3.0f);
    EXPECT_FLOAT_EQ(s.screen_shake, 0.0f);
    EXPECT_EQ(s.particles, SDLSTATIC_QUALITY_HIGH);
    EXPECT_EQ(s.presentation, SDLSTATIC_PRESENT_LETTERBOX);
}

// A negative cap is the documented way to say "no limiter", so clamping
// must not treat it as a mistake.
TEST(GraphicsClamp, LeavesTheUncappedSentinelAlone)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    s.max_fps = -1;
    SDLStatic_GraphicsClamp(&s);
    EXPECT_EQ(s.max_fps, -1);
}

// Photosensitivity is a safety setting, so it overrides the aesthetic ones
// rather than sitting politely beside them.
TEST(GraphicsClamp, ReducedFlashingCapsBloom)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    s.bloom = 1.0f;
    s.reduced_flashing = true;
    SDLStatic_GraphicsClamp(&s);
    EXPECT_LE(s.bloom, 0.25f);
}

TEST(GraphicsQuality, MapsToConcreteNumbers)
{
    EXPECT_FLOAT_EQ(SDLStatic_GraphicsParticleDensity(SDLSTATIC_QUALITY_OFF), 0.0f);
    EXPECT_FLOAT_EQ(SDLStatic_GraphicsParticleDensity(SDLSTATIC_QUALITY_HIGH), 1.0f);
    EXPECT_LT(SDLStatic_GraphicsParticleDensity(SDLSTATIC_QUALITY_LOW),
              SDLStatic_GraphicsParticleDensity(SDLSTATIC_QUALITY_MEDIUM));

    EXPECT_EQ(SDLStatic_GraphicsMaxDynamicLights(SDLSTATIC_QUALITY_OFF), 0);
    EXPECT_GT(SDLStatic_GraphicsMaxDynamicLights(SDLSTATIC_QUALITY_HIGH),
              SDLStatic_GraphicsMaxDynamicLights(SDLSTATIC_QUALITY_MEDIUM));

    // The light map still has a resolution when lights are off — "off"
    // means draw no lights, not render the map at zero pixels.
    EXPECT_GT(SDLStatic_GraphicsLightMapScale(SDLSTATIC_QUALITY_OFF), 0.0f);
    EXPECT_FLOAT_EQ(SDLStatic_GraphicsLightMapScale(SDLSTATIC_QUALITY_HIGH), 1.0f);

    // Soft shadows need rays to look soft rather than banded, so only the
    // top tier gets a penumbra.
    EXPECT_FLOAT_EQ(SDLStatic_GraphicsShadowSoftness(SDLSTATIC_QUALITY_LOW), 0.0f);
    EXPECT_GT(SDLStatic_GraphicsShadowSoftness(SDLSTATIC_QUALITY_HIGH), 0.0f);
}

TEST(GraphicsQuality, NamesRoundTrip)
{
    const SDLStatic_GraphicsQuality tiers[] = {SDLSTATIC_QUALITY_OFF, SDLSTATIC_QUALITY_LOW,
                                               SDLSTATIC_QUALITY_MEDIUM,
                                               SDLSTATIC_QUALITY_HIGH};
    for (SDLStatic_GraphicsQuality tier : tiers)
    {
        SDLStatic_GraphicsQuality parsed = SDLSTATIC_QUALITY_OFF;
        ASSERT_TRUE(SDLStatic_GraphicsQualityFromName(SDLStatic_GraphicsQualityName(tier),
                                                      &parsed));
        EXPECT_EQ(parsed, tier);
    }

    SDLStatic_GraphicsQuality untouched = SDLSTATIC_QUALITY_MEDIUM;
    EXPECT_FALSE(SDLStatic_GraphicsQualityFromName("ultra", &untouched));
    EXPECT_EQ(untouched, SDLSTATIC_QUALITY_MEDIUM) << "a bad name changes nothing";
    EXPECT_TRUE(SDLStatic_GraphicsQualityFromName("HIGH", &untouched)) << "case-insensitive";
}

// --- TOML -----------------------------------------------------------------

TEST(GraphicsToml, OverlaysOnlyTheKeysPresent)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    ASSERT_TRUE(SDLStatic_GraphicsLoadTomlString(&s, R"(
[display]
vsync = false
render_scale = 0.75

[effects]
bloom = 0.4
)"));

    EXPECT_FALSE(s.vsync);
    EXPECT_FLOAT_EQ(s.render_scale, 0.75f);
    EXPECT_FLOAT_EQ(s.bloom, 0.4f);
    // Everything the file did not mention is untouched.
    EXPECT_EQ(s.presentation, SDLSTATIC_PRESENT_LETTERBOX);
    EXPECT_EQ(s.shadows, SDLSTATIC_QUALITY_HIGH);
    EXPECT_FLOAT_EQ(s.brightness, 1.0f);
}

TEST(GraphicsToml, ReadsEveryEnum)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    ASSERT_TRUE(SDLStatic_GraphicsLoadTomlString(&s, R"(
[display]
window_mode = "borderless"
presentation = "integer"
filter = "nearest"

[quality]
particles = "low"
dynamic_lights = "medium"
shadows = "off"

[effects]
antialias = "fxaa"

[image]
color_blind = "deuteranopia"
)"));

    EXPECT_EQ(s.window_mode, SDLSTATIC_WINDOW_BORDERLESS);
    EXPECT_EQ(s.presentation, SDLSTATIC_PRESENT_INTEGER);
    EXPECT_EQ(s.filter, SDLSTATIC_FILTER_NEAREST);
    EXPECT_EQ(s.particles, SDLSTATIC_QUALITY_LOW);
    EXPECT_EQ(s.dynamic_lights, SDLSTATIC_QUALITY_MEDIUM);
    EXPECT_EQ(s.shadows, SDLSTATIC_QUALITY_OFF);
    EXPECT_EQ(s.antialias, SDLSTATIC_AA_FXAA);
    EXPECT_EQ(s.color_blind, SDLSTATIC_COLORBLIND_DEUTERANOPIA);
}

// Sections are a convenience, not a requirement — someone writing a config
// by hand should not have to know which section a key lives in.
TEST(GraphicsToml, AcceptsKeysAtTheTopLevelToo)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    ASSERT_TRUE(SDLStatic_GraphicsLoadTomlString(&s, "vsync = false\nbloom = 0.5\n"));
    EXPECT_FALSE(s.vsync);
    EXPECT_FLOAT_EQ(s.bloom, 0.5f);
}

// `bloom = 1` is an integer as far as TOML is concerned, and obviously
// means 1.0 as far as a person is concerned.
TEST(GraphicsToml, AcceptsIntegersWhereFloatsAreExpected)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    ASSERT_TRUE(SDLStatic_GraphicsLoadTomlString(&s, "[effects]\nbloom = 1\n"));
    EXPECT_FLOAT_EQ(s.bloom, 1.0f);
}

TEST(GraphicsToml, ValuesAreClampedOnTheWayIn)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    ASSERT_TRUE(SDLStatic_GraphicsLoadTomlString(&s, "[image]\nbrightness = 40.0\n"));
    EXPECT_FLOAT_EQ(s.brightness, 2.0f) << "a config file cannot black out a game";
}

TEST(GraphicsToml, AMalformedFileChangesNothingAndSaysWhy)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    s.bloom = 0.5f;
    EXPECT_FALSE(SDLStatic_GraphicsLoadTomlString(&s, "[display\nvsync = "));
    EXPECT_FLOAT_EQ(s.bloom, 0.5f) << "the previous values survive";
    EXPECT_NE(SDLStatic_GraphicsConfigError(), nullptr);
}

TEST(GraphicsToml, RoundTripsThroughItsOwnWriter)
{
    SDLStatic_GraphicsSettings original = SDLStatic_GraphicsDefaults();
    original.vsync = false;
    original.max_fps = 120;
    original.presentation = SDLSTATIC_PRESENT_EXPAND;
    original.window_mode = SDLSTATIC_WINDOW_BORDERLESS;
    original.render_scale = 0.75f;
    original.filter = SDLSTATIC_FILTER_NEAREST;
    original.particles = SDLSTATIC_QUALITY_LOW;
    original.dynamic_lights = SDLSTATIC_QUALITY_MEDIUM;
    original.shadows = SDLSTATIC_QUALITY_OFF;
    original.bloom = 0.4f;
    original.crt = 0.6f;
    original.crt_curvature = 0.2f;
    original.pixelation = 3;
    original.chromatic_aberration = 0.15f;
    original.antialias = SDLSTATIC_AA_FXAA;
    original.brightness = 1.2f;
    original.contrast = 0.9f;
    original.saturation = 1.1f;
    original.color_blind = SDLSTATIC_COLORBLIND_TRITANOPIA;
    original.reduced_flashing = false;
    original.screen_shake = 0.5f;
    original.ui_scale = 1.5f;

    char *text = SDLStatic_GraphicsToToml(&original);
    ASSERT_NE(text, nullptr);

    SDLStatic_GraphicsSettings restored = SDLStatic_GraphicsDefaults();
    ASSERT_TRUE(SDLStatic_GraphicsLoadTomlString(&restored, text)) << text;
    SDL_free(text);

    EXPECT_TRUE(SDLStatic_GraphicsEqual(&original, &restored))
        << "every field a player can change has to survive a save and a load";
}

// --- the command line -----------------------------------------------------

TEST(GraphicsArgs, AcceptsBothSpellings)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    const Args args({"game", "--vsync=off", "--max-fps", "120", "--bloom=0.4"});
    EXPECT_EQ(SDLStatic_GraphicsLoadArgs(&s, args.argc(), args.argv()), 3);
    EXPECT_FALSE(s.vsync);
    EXPECT_EQ(s.max_fps, 120);
    EXPECT_FLOAT_EQ(s.bloom, 0.4f);
}

TEST(GraphicsArgs, BareBooleanFlagsMeanOn)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    s.vsync = false;
    const Args args({"game", "--vsync", "--reduced-flashing"});
    SDLStatic_GraphicsLoadArgs(&s, args.argc(), args.argv());
    EXPECT_TRUE(s.vsync);
    EXPECT_TRUE(s.reduced_flashing);
}

TEST(GraphicsArgs, NoVsyncIsItsOwnFlag)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    const Args args({"game", "--no-vsync"});
    SDLStatic_GraphicsLoadArgs(&s, args.argc(), args.argv());
    EXPECT_FALSE(s.vsync);
}

// The game owns the command line; the engine is a guest on it and must not
// choke on arguments meant for somebody else.
TEST(GraphicsArgs, IgnoresArgumentsItDoesNotOwn)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    const Args args({"game", "--level", "forest", "-v", "--bloomier=9", "--crt=0.5"});
    EXPECT_EQ(SDLStatic_GraphicsLoadArgs(&s, args.argc(), args.argv()), 1);
    EXPECT_FLOAT_EQ(s.crt, 0.5f);
    EXPECT_FLOAT_EQ(s.bloom, 0.0f) << "--bloomier is not --bloom";
}

TEST(GraphicsArgs, ReadsEveryQualityAndMode)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    const Args args({"game", "--shadows=low", "--lights=off", "--particles=medium",
                     "--presentation=expand", "--filter=nearest", "--fullscreen",
                     "--color-blind=protanopia", "--antialias=fxaa", "--render-scale=0.5"});
    SDLStatic_GraphicsLoadArgs(&s, args.argc(), args.argv());

    EXPECT_EQ(s.shadows, SDLSTATIC_QUALITY_LOW);
    EXPECT_EQ(s.dynamic_lights, SDLSTATIC_QUALITY_OFF);
    EXPECT_EQ(s.particles, SDLSTATIC_QUALITY_MEDIUM);
    EXPECT_EQ(s.presentation, SDLSTATIC_PRESENT_EXPAND);
    EXPECT_EQ(s.filter, SDLSTATIC_FILTER_NEAREST);
    EXPECT_EQ(s.window_mode, SDLSTATIC_WINDOW_BORDERLESS);
    EXPECT_EQ(s.color_blind, SDLSTATIC_COLORBLIND_PROTANOPIA);
    EXPECT_EQ(s.antialias, SDLSTATIC_AA_FXAA);
    EXPECT_FLOAT_EQ(s.render_scale, 0.5f);
}

TEST(GraphicsArgs, FindsAnExplicitConfigPath)
{
    const Args equals({"game", "--config=/tmp/a.toml"});
    EXPECT_STREQ(SDLStatic_GraphicsArgsConfigPath(equals.argc(), equals.argv()), "/tmp/a.toml");

    const Args spaced({"game", "--config", "/tmp/b.toml"});
    EXPECT_STREQ(SDLStatic_GraphicsArgsConfigPath(spaced.argc(), spaced.argv()), "/tmp/b.toml");

    const Args none({"game", "--bloom=1"});
    EXPECT_EQ(SDLStatic_GraphicsArgsConfigPath(none.argc(), none.argv()), nullptr);
}

// --- precedence -----------------------------------------------------------

// The whole point of the chain: the command line has the last word. This is
// what a player uses when a saved setting has made the game unstartable.
TEST(GraphicsResolve, TheCommandLineBeatsTheFile)
{
    const std::string path = std::string(testing::TempDir()) + "sdlstatic_gfx_resolve.toml";
    const std::string toml = "[display]\nvsync = false\n[effects]\nbloom = 0.9\n";
    ASSERT_TRUE(SDL_SaveFile(path.c_str(), toml.data(), toml.size())) << SDL_GetError();

    const Args args({"game", std::string("--config=") + path, "--bloom=0.1"});
    SDLStatic_GraphicsSettings s{};
    SDLStatic_GraphicsResolve(&s, args.argc(), args.argv(), nullptr, nullptr);

    EXPECT_FALSE(s.vsync) << "from the file, which the command line did not mention";
    EXPECT_FLOAT_EQ(s.bloom, 0.1f) << "from the command line, which beats the file";
    ASSERT_NE(SDLStatic_GraphicsConfigPath(), nullptr);
    EXPECT_EQ(std::string(SDLStatic_GraphicsConfigPath()), path);

    SDL_RemovePath(path.c_str());
}

TEST(GraphicsResolve, WithNothingToReadTheDefaultsSurvive)
{
    const Args args({"game", "--config=/nonexistent/definitely/not/here.toml"});
    SDLStatic_GraphicsSettings s{};
    SDLStatic_GraphicsResolve(&s, args.argc(), args.argv(), nullptr, nullptr);

    const SDLStatic_GraphicsSettings defaults = SDLStatic_GraphicsDefaults();
    EXPECT_TRUE(SDLStatic_GraphicsEqual(&s, &defaults));
    EXPECT_TRUE(s.vsync);
    EXPECT_EQ(s.presentation, SDLSTATIC_PRESENT_LETTERBOX);
    EXPECT_NE(SDLStatic_GraphicsConfigError(), nullptr) << "and it says why";
}

// The game's shipped defaults, read out of whatever it mounted its media
// archive from — a zip, an encrypted .dat, a directory, or bytes compiled
// into the executable. The engine does not care which.
TEST(GraphicsResolve, ReadsTheConfigShippedInTheMediaArchive)
{
    struct Fake
    {
        static bool Read(const char *path, char **text, void *user)
        {
            auto *seen = static_cast<std::vector<std::string> *>(user);
            seen->push_back(path);
            if (std::string(path) != "media/config.toml")
            {
                return false;
            }
            *text = SDL_strdup("[effects]\ncrt = 0.8\n");
            return *text != nullptr;
        }
    };
    std::vector<std::string> seen;
    SDLStatic_GraphicsSetArchiveReader(Fake::Read, &seen);

    SDLStatic_GraphicsSettings s{};
    SDLStatic_GraphicsResolve(&s, 0, nullptr, nullptr, nullptr);
    SDLStatic_GraphicsSetArchiveReader(nullptr, nullptr);

    EXPECT_FLOAT_EQ(s.crt, 0.8f);
    ASSERT_FALSE(seen.empty());
    EXPECT_EQ(seen.front(), "media/config.toml");
}

// An archive reader is the lowest authority in the chain, so a player's
// command line still wins over what the game shipped.
TEST(GraphicsResolve, TheCommandLineBeatsTheArchiveToo)
{
    struct Fake
    {
        static bool Read(const char *path, char **text, void *)
        {
            if (std::string(path) != "media/config.toml")
            {
                return false;
            }
            *text = SDL_strdup("[effects]\ncrt = 0.8\n");
            return *text != nullptr;
        }
    };
    SDLStatic_GraphicsSetArchiveReader(Fake::Read, nullptr);

    const Args args({"game", "--crt=0.0"});
    SDLStatic_GraphicsSettings s{};
    SDLStatic_GraphicsResolve(&s, args.argc(), args.argv(), nullptr, nullptr);
    SDLStatic_GraphicsSetArchiveReader(nullptr, nullptr);

    EXPECT_FLOAT_EQ(s.crt, 0.0f);
}

TEST(GraphicsResolve, NullOutIsSurvivable)
{
    SDLStatic_GraphicsResolve(nullptr, 0, nullptr, nullptr, nullptr);
    EXPECT_EQ(SDLStatic_GraphicsLoadArgs(nullptr, 0, nullptr), 0);
    EXPECT_FALSE(SDLStatic_GraphicsLoadTomlString(nullptr, "x = 1"));
    EXPECT_EQ(SDLStatic_GraphicsToToml(nullptr), nullptr);
}

// --- saving ---------------------------------------------------------------

// What an options screen does when the player presses Apply.
TEST(GraphicsSave, WritesAFileTheLoaderCanReadBack)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    s.bloom = 0.33f;
    s.shadows = SDLSTATIC_QUALITY_LOW;

    ASSERT_TRUE(SDLStatic_GraphicsSave(&s, "SDLStaticTest", "GraphicsSaveTest"))
        << SDL_GetError();

    char *path = SDLStatic_GraphicsSavePath("SDLStaticTest", "GraphicsSaveTest");
    ASSERT_NE(path, nullptr);

    SDLStatic_GraphicsSettings loaded = SDLStatic_GraphicsDefaults();
    EXPECT_TRUE(SDLStatic_GraphicsLoadTomlFile(&loaded, path)) << path;
    EXPECT_FLOAT_EQ(loaded.bloom, 0.33f);
    EXPECT_EQ(loaded.shadows, SDLSTATIC_QUALITY_LOW);

    SDL_RemovePath(path);
    SDL_free(path);
}

TEST(GraphicsSave, NeedsSomewhereToSaveTo)
{
    const SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    EXPECT_FALSE(SDLStatic_GraphicsSave(&s, "org", nullptr));
    EXPECT_EQ(SDLStatic_GraphicsSavePath("org", nullptr), nullptr);
}

// --- applying to an engine ------------------------------------------------

class GraphicsEngine : public ::testing::Test
{
  protected:
    void SetUp() override { ASSERT_TRUE(SDL_Init(0)) << SDL_GetError(); }
    void TearDown() override { SDL_Quit(); }

    SDLStatic_Engine *Make(const SDLStatic_GraphicsSettings *graphics)
    {
        SDLStatic_EngineConfig config{};
        config.headless = true;
        config.manual_clock = true;
        config.window_width = 1920;
        config.window_height = 1080;
        config.graphics = graphics;
        return SDLStatic_CreateEngine(&config);
    }
};

// Settings carry the presentation mode, so they have to win over the plain
// config field — otherwise a player's config.toml would be silently
// overridden by whatever the game hard-coded.
TEST_F(GraphicsEngine, SettingsWinOverThePlainConfigFields)
{
    SDLStatic_GraphicsSettings gfx = SDLStatic_GraphicsDefaults();
    gfx.presentation = SDLSTATIC_PRESENT_EXPAND;
    gfx.max_fps = 120;

    SDLStatic_EngineConfig config{};
    config.headless = true;
    config.manual_clock = true;
    config.window_width = 2560;
    config.window_height = 1080;
    config.presentation = SDLSTATIC_PRESENT_INTEGER; // the game's guess
    config.max_fps = 30;
    config.graphics = &gfx; // the player's choice

    SDLStatic_Engine *engine = SDLStatic_CreateEngine(&config);
    ASSERT_NE(engine, nullptr) << SDL_GetError();
    EXPECT_EQ(SDLStatic_EnginePresentation_(engine), SDLSTATIC_PRESENT_EXPAND);
    EXPECT_GT(SDLStatic_EngineViewRect(engine).w, 1920.0f) << "expanded, not integer-scaled";
    SDLStatic_DestroyEngine(engine);
}

// Without a settings struct the engine still reports coherent settings,
// rather than defaults nobody applied.
TEST_F(GraphicsEngine, MirrorsThePlainFieldsWhenGivenNoSettings)
{
    SDLStatic_EngineConfig config{};
    config.headless = true;
    config.manual_clock = true;
    config.presentation = SDLSTATIC_PRESENT_EXPAND;
    config.no_vsync = true;
    config.max_fps = 45;

    SDLStatic_Engine *engine = SDLStatic_CreateEngine(&config);
    ASSERT_NE(engine, nullptr);
    const SDLStatic_GraphicsSettings *g = SDLStatic_EngineGraphics(engine);
    ASSERT_NE(g, nullptr);
    EXPECT_EQ(g->presentation, SDLSTATIC_PRESENT_EXPAND);
    EXPECT_FALSE(g->vsync);
    EXPECT_EQ(g->max_fps, 45);
    SDLStatic_DestroyEngine(engine);
}

TEST_F(GraphicsEngine, ChangingSettingsAtRuntimeTakesEffect)
{
    SDLStatic_Engine *engine = Make(nullptr);
    ASSERT_NE(engine, nullptr);

    SDLStatic_GraphicsSettings next = *SDLStatic_EngineGraphics(engine);
    next.presentation = SDLSTATIC_PRESENT_NATIVE;
    next.render_scale = 0.5f;
    ASSERT_TRUE(SDLStatic_EngineSetGraphics(engine, &next));

    EXPECT_EQ(SDLStatic_EnginePresentation_(engine), SDLSTATIC_PRESENT_NATIVE);
    EXPECT_FLOAT_EQ(SDLStatic_EngineGraphics(engine)->render_scale, 0.5f);
    SDLStatic_DestroyEngine(engine);
}

TEST_F(GraphicsEngine, RejectedValuesAreClampedNotStored)
{
    SDLStatic_Engine *engine = Make(nullptr);
    ASSERT_NE(engine, nullptr);

    SDLStatic_GraphicsSettings next = *SDLStatic_EngineGraphics(engine);
    next.brightness = 99.0f;
    ASSERT_TRUE(SDLStatic_EngineSetGraphics(engine, &next));
    EXPECT_FLOAT_EQ(SDLStatic_EngineGraphics(engine)->brightness, 2.0f);
    SDLStatic_DestroyEngine(engine);
}

// A software renderer has no OpenGL, so the effects must report themselves
// unavailable rather than pretending — an options screen greys them out on
// the strength of this.
TEST_F(GraphicsEngine, EffectsAreUnavailableWithoutOpenGL)
{
    SDLStatic_GraphicsSettings gfx = SDLStatic_GraphicsDefaults();
    gfx.bloom = 0.5f;
    SDLStatic_Engine *engine = Make(&gfx);
    ASSERT_NE(engine, nullptr);
    EXPECT_FALSE(SDLStatic_EngineEffectsAvailable(engine));
    SDLStatic_DestroyEngine(engine);
}

// ...and asking for them anyway must not stop the game running.
TEST_F(GraphicsEngine, AFrameStillRendersWithEffectsRequestedAndUnavailable)
{
    SDLStatic_GraphicsSettings gfx = SDLStatic_GraphicsDefaults();
    gfx.bloom = 0.8f;
    gfx.crt = 0.5f;
    gfx.render_scale = 0.5f;
    SDLStatic_Engine *engine = Make(&gfx);
    ASSERT_NE(engine, nullptr);

    for (int i = 0; i < 3; ++i)
    {
        SDLStatic_EngineAdvance(engine, 16666667ull);
        SDLStatic_EngineTick(engine);
    }
    EXPECT_GE(SDLStatic_EngineFrameCount(engine), 3u);
    SDLStatic_DestroyEngine(engine);
}

TEST_F(GraphicsEngine, NullsAreHandled)
{
    EXPECT_EQ(SDLStatic_EngineGraphics(nullptr), nullptr);
    EXPECT_FALSE(SDLStatic_EngineEffectsAvailable(nullptr));
    const SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    EXPECT_FALSE(SDLStatic_EngineSetGraphics(nullptr, &s));
}

} // namespace

// --- defaults, safe mode, and the escape hatches --------------------------

namespace
{

// Shipping defaults: as good as the machine can manage, on the whole screen.
TEST(GraphicsShippingDefaults, AreFullscreenAtMaximumFidelity)
{
    const SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    EXPECT_EQ(s.window_mode, SDLSTATIC_WINDOW_BORDERLESS) << "what a finished game does";
    EXPECT_EQ(s.particles, SDLSTATIC_QUALITY_HIGH);
    EXPECT_EQ(s.dynamic_lights, SDLSTATIC_QUALITY_HIGH);
    EXPECT_EQ(s.shadows, SDLSTATIC_QUALITY_HIGH);
    EXPECT_EQ(s.antialias, SDLSTATIC_AA_FXAA) << "fidelity, not style";
    EXPECT_FLOAT_EQ(s.render_scale, 1.0f);
    EXPECT_TRUE(s.vsync);

    // Accessibility alters the image away from what the artist intended, so
    // it is opt-in however useful it is to the people who need it.
    EXPECT_FALSE(s.reduced_flashing);
    EXPECT_EQ(s.color_blind, SDLSTATIC_COLORBLIND_NONE);

    // Style is the game's decision, not the engine's.
    EXPECT_FLOAT_EQ(s.bloom, 0.0f);
    EXPECT_FLOAT_EQ(s.crt, 0.0f);
    EXPECT_FLOAT_EQ(s.chromatic_aberration, 0.0f);
    EXPECT_EQ(s.pixelation, 1);
}

TEST(GraphicsSafeMode, IsAWindowYouCanAlwaysSee)
{
    const SDLStatic_GraphicsSettings s = SDLStatic_GraphicsSafeMode();
    EXPECT_EQ(s.window_mode, SDLSTATIC_WINDOW_WINDOWED);
    EXPECT_EQ(s.window_width, 1280);
    EXPECT_EQ(s.window_height, 720);
    EXPECT_EQ(s.display, 0) << "the primary monitor, which is the one plugged in";

    // Every shader effect off: if the chain is what broke the machine, safe
    // mode must not run it.
    EXPECT_FLOAT_EQ(s.bloom, 0.0f);
    EXPECT_FLOAT_EQ(s.crt, 0.0f);
    EXPECT_EQ(s.antialias, SDLSTATIC_AA_OFF);
    EXPECT_FLOAT_EQ(s.brightness, 1.0f);

    // Down, not off — it still has to be playable enough to reach the
    // options screen and undo whatever went wrong.
    EXPECT_EQ(s.shadows, SDLSTATIC_QUALITY_OFF);
    EXPECT_EQ(s.particles, SDLSTATIC_QUALITY_LOW);
    EXPECT_FLOAT_EQ(s.render_scale, 1.0f);
}

// The whole point of the escape hatches: they have to work when the saved
// settings are what is broken, so they must not read them.
TEST(GraphicsResolve, SafeModeIgnoresEveryConfigFile)
{
    const std::string path = std::string(testing::TempDir()) + "sdlstatic_gfx_broken.toml";
    const std::string toml = "[display]\nwindow_mode = \"exclusive\"\nrender_scale = 0.25\n"
                             "[effects]\ncrt = 1.0\n";
    ASSERT_TRUE(SDL_SaveFile(path.c_str(), toml.data(), toml.size())) << SDL_GetError();

    const Args args({"game", std::string("--config=") + path, "--with-safe-mode"});
    SDLStatic_GraphicsSettings s{};
    SDLStatic_GraphicsResolve(&s, args.argc(), args.argv(), nullptr, nullptr);

    EXPECT_EQ(s.window_mode, SDLSTATIC_WINDOW_WINDOWED) << "not the file's exclusive";
    EXPECT_FLOAT_EQ(s.crt, 0.0f);
    EXPECT_FLOAT_EQ(s.render_scale, 1.0f);
    SDL_RemovePath(path.c_str());
}

TEST(GraphicsResolve, DefaultSettingsIgnoresEveryConfigFileToo)
{
    const std::string path = std::string(testing::TempDir()) + "sdlstatic_gfx_odd.toml";
    const std::string toml = "[quality]\nshadows = \"off\"\n";
    ASSERT_TRUE(SDL_SaveFile(path.c_str(), toml.data(), toml.size()));

    const Args args({"game", std::string("--config=") + path, "--with-default-settings"});
    SDLStatic_GraphicsSettings s{};
    SDLStatic_GraphicsResolve(&s, args.argc(), args.argv(), nullptr, nullptr);

    EXPECT_EQ(s.shadows, SDLSTATIC_QUALITY_HIGH);
    EXPECT_EQ(s.window_mode, SDLSTATIC_WINDOW_BORDERLESS);
    SDL_RemovePath(path.c_str());
}

// An escape hatch replaces the struct, but the rest of the line still
// applies on top — order-independently, so a player can add one fix.
TEST(GraphicsArgs, SafeModeIsReplacedThenOverlaid)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    const Args args({"game", "--bloom=0.5", "--with-safe-mode"});
    SDLStatic_GraphicsLoadArgs(&s, args.argc(), args.argv());
    EXPECT_EQ(s.window_mode, SDLSTATIC_WINDOW_WINDOWED) << "safe mode applied first";
    EXPECT_FLOAT_EQ(s.bloom, 0.5f) << "then the explicit argument, whatever the order";
}

TEST(GraphicsArgs, ReadsWindowSizeAndDisplay)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    const Args args({"game", "--window-size=1600x900", "--display=1"});
    SDLStatic_GraphicsLoadArgs(&s, args.argc(), args.argv());
    EXPECT_EQ(s.window_width, 1600);
    EXPECT_EQ(s.window_height, 900);
    EXPECT_EQ(s.window_mode, SDLSTATIC_WINDOW_WINDOWED) << "asking for a size implies windowed";
    EXPECT_EQ(s.display, 1);

    // Nonsense leaves it alone rather than producing a 0x0 window.
    SDLStatic_GraphicsSettings other = SDLStatic_GraphicsDefaults();
    const Args bad({"game", "--window-size=huge"});
    SDLStatic_GraphicsLoadArgs(&other, bad.argc(), bad.argv());
    EXPECT_EQ(other.window_width, 0);
}

TEST(GraphicsToml, WindowSizeAndDisplayRoundTrip)
{
    SDLStatic_GraphicsSettings original = SDLStatic_GraphicsDefaults();
    original.window_width = 1600;
    original.window_height = 900;
    original.display = 2;

    char *text = SDLStatic_GraphicsToToml(&original);
    ASSERT_NE(text, nullptr);
    SDLStatic_GraphicsSettings restored = SDLStatic_GraphicsDefaults();
    ASSERT_TRUE(SDLStatic_GraphicsLoadTomlString(&restored, text)) << text;
    SDL_free(text);

    EXPECT_EQ(restored.window_width, 1600);
    EXPECT_EQ(restored.window_height, 900);
    EXPECT_EQ(restored.display, 2);
}

// A saved monitor that has since been unplugged must not leave the game
// invisible on a display that is not there.
// Only the boundaries here. Enumerating real displays needs the video
// subsystem, and initialising it in this binary — after the other fixtures
// have cycled SDL_Init/SDL_Quit dozens of times — deadlocks against the
// Cocoa event loop on macOS. The enumeration itself is exercised by the
// engine demos, which have a window and therefore a legitimate reason to
// have video running.
TEST(GraphicsDisplays, HandleIndicesThatDoNotExist)
{
    EXPECT_EQ(SDLStatic_EngineDisplayName(-1), nullptr);
    EXPECT_EQ(SDLStatic_EngineDisplayName(9999), nullptr);
    EXPECT_EQ(SDLStatic_EngineDisplay(nullptr), 0);
    EXPECT_FALSE(SDLStatic_EngineSetDisplay(nullptr, 0));
    EXPECT_GE(SDLStatic_EngineDisplayCount(), 0) << "never negative, video or not";
}

TEST(GraphicsClamp, WindowSizeIsUsableOrTheDefault)
{
    SDLStatic_GraphicsSettings s = SDLStatic_GraphicsDefaults();
    s.window_width = 4;
    s.window_height = 4;
    SDLStatic_GraphicsClamp(&s);
    EXPECT_GE(s.window_width, 320) << "a 4x4 window cannot show a UI";

    // Zero is not a mistake: it means "the engine's default".
    SDLStatic_GraphicsSettings zeroed = SDLStatic_GraphicsDefaults();
    SDLStatic_GraphicsClamp(&zeroed);
    EXPECT_EQ(zeroed.window_width, 0);

    SDLStatic_GraphicsSettings negative = SDLStatic_GraphicsDefaults();
    negative.display = -3;
    SDLStatic_GraphicsClamp(&negative);
    EXPECT_EQ(negative.display, 0);
}

} // namespace
