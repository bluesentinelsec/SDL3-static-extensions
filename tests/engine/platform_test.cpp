// Saves and localisation.
//
// The save tests care about one thing above all: that a write which fails
// partway does not take the previous save with it. The text tests care
// about the fallback chain, because a half-finished translation is the
// normal state of a translation, not an exceptional one.
#include <SDLStatic/engine_save.h>
#include <SDLStatic/engine_text.h>

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace
{

class PlatformHarness : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
        SDLStatic_EngineConfig config{};
        config.headless = true;
        config.manual_clock = true;
        config.no_auto_mount = true;
        engine_ = SDLStatic_CreateEngine(&config);
        ASSERT_NE(engine_, nullptr) << SDL_GetError();
        // A directory per test. ctest runs these as separate processes in
        // parallel, so a shared save directory means several tests writing
        // slot 0 at once — which fails in exactly the way real save
        // corruption does, and for the same reason.
        app_ = std::string("SaveTest_") +
               ::testing::UnitTest::GetInstance()->current_test_info()->name();
        SDLStatic_SaveSetIdentity(engine_, "SDLStaticTest", app_.c_str());
        for (int slot = 0; slot < 4; ++slot)
        {
            SDLStatic_SaveDelete(engine_, slot);
        }
    }
    void TearDown() override
    {
        for (int slot = 0; slot < 4; ++slot)
        {
            SDLStatic_SaveDelete(engine_, slot);
        }
        SDLStatic_DestroyEngine(engine_);
        SDL_Quit();
    }

    SDLStatic_Engine *engine_ = nullptr;
    std::string app_;
};

// --- saves ----------------------------------------------------------------

struct GameState
{
    int level;
    float health;
    char name[16];
};

TEST_F(PlatformHarness, SavesRoundTrip)
{
    GameState written{};
    written.level = 7;
    written.health = 42.5f;
    SDL_strlcpy(written.name, "hero", sizeof(written.name));

    ASSERT_TRUE(SDLStatic_SaveWrite(engine_, 0, &written, sizeof(written), "Cave of Ordeals"))
        << SDL_GetError();

    size_t size = 0;
    void *data = SDLStatic_SaveRead(engine_, 0, &size);
    ASSERT_NE(data, nullptr);
    ASSERT_EQ(size, sizeof(written));

    GameState read{};
    SDL_memcpy(&read, data, size);
    SDL_free(data);

    EXPECT_EQ(read.level, 7);
    EXPECT_FLOAT_EQ(read.health, 42.5f);
    EXPECT_STREQ(read.name, "hero");
}

// What a load menu needs to draw a row, without parsing a save it may not
// even be able to interpret.
TEST_F(PlatformHarness, InfoDescribesASlotWithoutReadingIt)
{
    const int payload = 1234;
    ASSERT_TRUE(SDLStatic_SaveWrite(engine_, 1, &payload, sizeof(payload), "Chapter 3"));

    const SDLStatic_SaveInfo info = SDLStatic_SaveInfoOf(engine_, 1);
    EXPECT_TRUE(info.exists);
    EXPECT_EQ(info.size, sizeof(payload));
    EXPECT_STREQ(info.label, "Chapter 3");
    EXPECT_GT(info.modified, 0) << "a timestamp, for ordering by most recent";

    const SDLStatic_SaveInfo empty = SDLStatic_SaveInfoOf(engine_, 3);
    EXPECT_FALSE(empty.exists);
    EXPECT_EQ(empty.size, 0u);
}

TEST_F(PlatformHarness, SlotsAreIndependent)
{
    const int first = 111;
    const int second = 222;
    ASSERT_TRUE(SDLStatic_SaveWrite(engine_, 0, &first, sizeof(first), "one"));
    ASSERT_TRUE(SDLStatic_SaveWrite(engine_, 1, &second, sizeof(second), "two"));

    size_t size = 0;
    int *read = static_cast<int *>(SDLStatic_SaveRead(engine_, 0, &size));
    ASSERT_NE(read, nullptr);
    EXPECT_EQ(*read, 111);
    SDL_free(read);

    read = static_cast<int *>(SDLStatic_SaveRead(engine_, 1, &size));
    ASSERT_NE(read, nullptr);
    EXPECT_EQ(*read, 222);
    SDL_free(read);
}

TEST_F(PlatformHarness, OverwritingReplacesRatherThanAppending)
{
    const int first = 1;
    const double second = 2.0;
    ASSERT_TRUE(SDLStatic_SaveWrite(engine_, 0, &first, sizeof(first), "a"));
    ASSERT_TRUE(SDLStatic_SaveWrite(engine_, 0, &second, sizeof(second), "b"));

    const SDLStatic_SaveInfo info = SDLStatic_SaveInfoOf(engine_, 0);
    EXPECT_EQ(info.size, sizeof(second)) << "the new size, not the sum";
    EXPECT_STREQ(info.label, "b");
}

// The reason these primitives are in the engine at all: a write that fails
// must not take the previous save with it.
TEST_F(PlatformHarness, AFailedWriteLeavesThePreviousSaveIntact)
{
    const int good = 99;
    ASSERT_TRUE(SDLStatic_SaveWrite(engine_, 0, &good, sizeof(good), "good save"));

    // A write that cannot succeed: a null payload with a nonzero size is
    // rejected before anything is touched.
    EXPECT_FALSE(SDLStatic_SaveWrite(engine_, 0, nullptr, 16, "doomed"));

    size_t size = 0;
    int *read = static_cast<int *>(SDLStatic_SaveRead(engine_, 0, &size));
    ASSERT_NE(read, nullptr) << "the old save is still there";
    EXPECT_EQ(*read, 99);
    SDL_free(read);
    EXPECT_STREQ(SDLStatic_SaveInfoOf(engine_, 0).label, "good save");
}

// The temporary file must not be left behind to accumulate.
TEST_F(PlatformHarness, WritingLeavesNoTemporaryBehind)
{
    const int payload = 5;
    ASSERT_TRUE(SDLStatic_SaveWrite(engine_, 2, &payload, sizeof(payload), "x"));

    char *path = SDLStatic_SavePath(engine_, 2);
    ASSERT_NE(path, nullptr);
    std::string temporary(path);
    temporary.replace(temporary.find(".sav"), 4, ".tmp");
    SDL_free(path);

    SDL_PathInfo info;
    EXPECT_FALSE(SDL_GetPathInfo(temporary.c_str(), &info)) << "renamed, not copied";
}

TEST_F(PlatformHarness, DeletingIsIdempotent)
{
    const int payload = 1;
    ASSERT_TRUE(SDLStatic_SaveWrite(engine_, 0, &payload, sizeof(payload), "x"));
    EXPECT_TRUE(SDLStatic_SaveExists(engine_, 0));

    EXPECT_TRUE(SDLStatic_SaveDelete(engine_, 0));
    EXPECT_FALSE(SDLStatic_SaveExists(engine_, 0));
    // A load menu offering delete on every row must not error on the empty
    // ones.
    EXPECT_TRUE(SDLStatic_SaveDelete(engine_, 0));
}

TEST_F(PlatformHarness, AnEmptyPayloadIsAValidSave)
{
    // "I have started a game" with nothing else to record yet.
    ASSERT_TRUE(SDLStatic_SaveWrite(engine_, 0, nullptr, 0, "new game"));
    EXPECT_TRUE(SDLStatic_SaveExists(engine_, 0));
    EXPECT_EQ(SDLStatic_SaveInfoOf(engine_, 0).size, 0u);
}

TEST_F(PlatformHarness, OutOfRangeSlotsAreRefused)
{
    const int payload = 1;
    EXPECT_FALSE(SDLStatic_SaveWrite(engine_, -1, &payload, sizeof(payload), "x"));
    EXPECT_FALSE(SDLStatic_SaveWrite(engine_, SDLSTATIC_SAVE_SLOTS, &payload, sizeof(payload),
                                     "x"));
    EXPECT_EQ(SDLStatic_SaveRead(engine_, 999, nullptr), nullptr);
    EXPECT_FALSE(SDLStatic_SaveInfoOf(engine_, -5).exists);
    EXPECT_EQ(SDLStatic_SavePath(engine_, 99), nullptr);
}

// --- localisation ---------------------------------------------------------

TEST_F(PlatformHarness, StringsComeBackInTheChosenLanguage)
{
    ASSERT_TRUE(SDLStatic_TextLoad(engine_, "en",
                                   "[strings]\n\"menu.start\" = \"Start\"\n"));
    ASSERT_TRUE(SDLStatic_TextLoad(engine_, "fr",
                                   "[strings]\n\"menu.start\" = \"Commencer\"\n"));

    EXPECT_STREQ(SDLStatic_Text(engine_, "menu.start"), "Start") << "English by default";

    SDLStatic_TextSetLanguage(engine_, "fr");
    EXPECT_STREQ(SDLStatic_TextLanguage(engine_), "fr");
    EXPECT_STREQ(SDLStatic_Text(engine_, "menu.start"), "Commencer");
}

// A translation in progress has gaps by definition, and an English button
// beats a blank one — a blank is indistinguishable from a bug.
TEST_F(PlatformHarness, AMissingTranslationFallsBackToEnglish)
{
    ASSERT_TRUE(SDLStatic_TextLoad(
        engine_, "en", "[strings]\n\"menu.start\" = \"Start\"\n\"menu.quit\" = \"Quit\"\n"));
    ASSERT_TRUE(SDLStatic_TextLoad(engine_, "fr",
                                   "[strings]\n\"menu.start\" = \"Commencer\"\n"));

    SDLStatic_TextSetLanguage(engine_, "fr");
    EXPECT_STREQ(SDLStatic_Text(engine_, "menu.start"), "Commencer");
    EXPECT_STREQ(SDLStatic_Text(engine_, "menu.quit"), "Quit") << "the gap shows English";
    EXPECT_FALSE(SDLStatic_TextHas(engine_, "menu.quit")) << "and a tool can tell";
    EXPECT_TRUE(SDLStatic_TextHas(engine_, "menu.start"));
}

// A key with no entry anywhere renders as itself: ugly on purpose, obvious
// in a screenshot, and it names the thing that needs fixing.
TEST_F(PlatformHarness, AnUnknownKeyRendersAsTheKey)
{
    SDLStatic_TextLoad(engine_, "en", "[strings]\n\"a\" = \"A\"\n");
    EXPECT_STREQ(SDLStatic_Text(engine_, "menu.nonexistent"), "menu.nonexistent");
}

TEST_F(PlatformHarness, AnUnknownLanguageStillRuns)
{
    ASSERT_TRUE(SDLStatic_TextLoad(engine_, "en", "[strings]\n\"go\" = \"Go\"\n"));
    SDLStatic_TextSetLanguage(engine_, "kli"); // no such table
    EXPECT_STREQ(SDLStatic_Text(engine_, "go"), "Go")
        << "falling back beats refusing to start over a settings string";
}

// The looked-up string is the format, so a translator controls where the
// numbers go — word order is not the same in every language.
TEST_F(PlatformHarness, FormattingUsesTheTranslatedFormatString)
{
    ASSERT_TRUE(SDLStatic_TextLoad(engine_, "en", "[strings]\n\"hud.score\" = \"Score: %d\"\n"));
    ASSERT_TRUE(SDLStatic_TextLoad(engine_, "fr", "[strings]\n\"hud.score\" = \"%d points\"\n"));

    EXPECT_STREQ(SDLStatic_TextFormat(engine_, "hud.score", 40), "Score: 40");
    SDLStatic_TextSetLanguage(engine_, "fr");
    EXPECT_STREQ(SDLStatic_TextFormat(engine_, "hud.score", 40), "40 points");
}

// Several formatted strings in one expression must not overwrite each
// other, which is the usual trap with a single static buffer.
TEST_F(PlatformHarness, SeveralFormattedStringsCoexist)
{
    ASSERT_TRUE(SDLStatic_TextLoad(engine_, "en",
                                   "[strings]\n\"a\" = \"a%d\"\n\"b\" = \"b%d\"\n"));
    const char *first = SDLStatic_TextFormat(engine_, "a", 1);
    const char *second = SDLStatic_TextFormat(engine_, "b", 2);
    EXPECT_STREQ(first, "a1") << "still intact after the second call";
    EXPECT_STREQ(second, "b2");
}

TEST_F(PlatformHarness, LoadingTwiceMergesWithLaterKeysWinning)
{
    ASSERT_TRUE(SDLStatic_TextLoad(engine_, "en",
                                   "[strings]\n\"a\" = \"first\"\n\"b\" = \"keep\"\n"));
    ASSERT_TRUE(SDLStatic_TextLoad(engine_, "en", "[strings]\n\"a\" = \"second\"\n"));

    EXPECT_STREQ(SDLStatic_Text(engine_, "a"), "second") << "patched";
    EXPECT_STREQ(SDLStatic_Text(engine_, "b"), "keep") << "and the rest survives";
    EXPECT_EQ(SDLStatic_TextCount(engine_, "en"), 2);
}

TEST_F(PlatformHarness, AFlatTableIsAcceptedToo)
{
    // A perfectly reasonable thing for a translator to hand back.
    ASSERT_TRUE(SDLStatic_TextLoad(engine_, "en", "\"greeting\" = \"Hello\"\n"));
    EXPECT_STREQ(SDLStatic_Text(engine_, "greeting"), "Hello");
}

TEST_F(PlatformHarness, AMalformedTableIsNotFatal)
{
    ASSERT_TRUE(SDLStatic_TextLoad(engine_, "en", "[strings]\n\"a\" = \"A\"\n"));
    EXPECT_FALSE(SDLStatic_TextLoad(engine_, "en", "[strings\n\"b\" = "));
    EXPECT_STREQ(SDLStatic_Text(engine_, "a"), "A") << "what loaded before survives";
}

TEST_F(PlatformHarness, SystemLanguagesAreReadable)
{
    char *languages[4] = {nullptr, nullptr, nullptr, nullptr};
    const int count = SDLStatic_TextSystemLanguages(languages, 4);
    EXPECT_GE(count, 0);
    for (int i = 0; i < count; ++i)
    {
        EXPECT_NE(languages[i], nullptr);
        EXPECT_GT(SDL_strlen(languages[i]), 0u);
        SDL_free(languages[i]);
    }
}

TEST_F(PlatformHarness, NullsAreHandled)
{
    EXPECT_FALSE(SDLStatic_SaveWrite(nullptr, 0, "x", 1, nullptr));
    EXPECT_EQ(SDLStatic_SaveRead(nullptr, 0, nullptr), nullptr);
    EXPECT_FALSE(SDLStatic_SaveExists(nullptr, 0));
    SDLStatic_SaveSetIdentity(nullptr, "a", "b");

    EXPECT_FALSE(SDLStatic_TextLoad(nullptr, "en", "x = 1"));
    EXPECT_FALSE(SDLStatic_TextLoad(engine_, nullptr, nullptr));
    EXPECT_STREQ(SDLStatic_Text(nullptr, "key"), "key");
    EXPECT_STREQ(SDLStatic_Text(engine_, nullptr), "");
    EXPECT_FALSE(SDLStatic_TextHas(nullptr, "key"));
    EXPECT_EQ(SDLStatic_TextSystemLanguages(nullptr, 0), 0);
    SDLStatic_TextSetLanguage(nullptr, "fr");
}

} // namespace
