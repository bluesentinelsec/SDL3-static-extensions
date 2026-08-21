/**
 * @file scene_test.cpp
 * @brief SDLStatic::Engine — the scene stack.
 *
 * The interesting properties are all about ordering: lifecycle callbacks
 * firing in the right order and the right number of times, stack changes
 * that are safe to request from inside a callback, and covered scenes
 * behaving the way a pause menu needs them to.
 */
#include <SDLStatic/engine.h>
#include <SDLStatic/engine_scene.h>

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace
{

constexpr Uint64 kFrameNs = 1000000000ull / 60;

// Scenes record what happened to them into one shared log, so a test can
// assert on the exact order of lifecycle events.
std::vector<std::string> g_log;

struct SceneState
{
    int fixed_updates = 0;
    int renders = 0;
};

void Note(SDLStatic_Scene *scene, const char *what)
{
    const char *name = SDLStatic_SceneName(scene);
    g_log.push_back(std::string(name != nullptr ? name : "?") + ":" + what);
}

bool SceneLoad(SDLStatic_Scene *scene)
{
    Note(scene, "load");
    return true;
}
void SceneEnter(SDLStatic_Scene *scene) { Note(scene, "enter"); }
void SceneExit(SDLStatic_Scene *scene) { Note(scene, "exit"); }
void SceneUnload(SDLStatic_Scene *scene) { Note(scene, "unload"); }
void SceneFixedUpdate(SDLStatic_Scene *scene, float step)
{
    (void)step;
    static_cast<SceneState *>(SDLStatic_SceneState(scene))->fixed_updates++;
}
void SceneRender(SDLStatic_Scene *scene, float alpha)
{
    (void)alpha;
    static_cast<SceneState *>(SDLStatic_SceneState(scene))->renders++;
}

SDLStatic_SceneDef MakeDef(const char *name, SDLStatic_SceneFlags flags = SDLSTATIC_SCENE_DEFAULT)
{
    SDLStatic_SceneDef def{};
    def.name = name;
    def.state_size = sizeof(SceneState);
    def.flags = flags;
    def.load = SceneLoad;
    def.enter = SceneEnter;
    def.exit = SceneExit;
    def.unload = SceneUnload;
    def.fixed_update = SceneFixedUpdate;
    def.render = SceneRender;
    return def;
}

class SceneHarness : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        g_log.clear();
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
        SDLStatic_EngineConfig config{};
        config.headless = true;
        config.manual_clock = true;
        config.design_width = 64;
        config.design_height = 64;
        engine_ = SDLStatic_CreateEngine(&config);
        ASSERT_NE(engine_, nullptr) << SDL_GetError();
    }
    void TearDown() override
    {
        SDLStatic_DestroyEngine(engine_);
        SDL_Quit();
    }

    void Frame(int count = 1)
    {
        for (int i = 0; i < count; i++)
        {
            SDLStatic_EngineAdvance(engine_, kFrameNs);
            SDLStatic_EngineTick(engine_);
        }
    }

    static bool LoggedInOrder(const std::vector<std::string> &wanted)
    {
        size_t at = 0;
        for (const auto &entry : g_log)
        {
            if (at < wanted.size() && entry == wanted[at])
            {
                at++;
            }
        }
        return at == wanted.size();
    }

    SDLStatic_Engine *engine_ = nullptr;
};

// The documented lifecycle order, and each callback exactly once.
TEST_F(SceneHarness, LifecycleRunsInOrder)
{
    const SDLStatic_SceneDef title = MakeDef("title");
    EXPECT_TRUE(SDLStatic_ScenePush(engine_, &title));
    EXPECT_EQ(SDLStatic_SceneDepth(engine_), 0) << "the change is deferred";

    Frame();
    EXPECT_EQ(SDLStatic_SceneDepth(engine_), 1);
    EXPECT_TRUE(LoggedInOrder({"title:load", "title:enter"}));

    SDLStatic_DestroyEngine(engine_);
    engine_ = nullptr;
    EXPECT_TRUE(LoggedInOrder({"title:load", "title:enter", "title:exit", "title:unload"}))
        << "destroying the engine still runs exit and unload";

    // TearDown expects an engine; give it an empty one.
    SDLStatic_EngineConfig config{};
    config.headless = true;
    config.design_width = 8;
    config.design_height = 8;
    engine_ = SDLStatic_CreateEngine(&config);
}

// Push/pop is the pause-menu case: the level keeps its state, and gets its
// enter() back when the menu goes away.
TEST_F(SceneHarness, PushingKeepsTheSceneBelowAlive)
{
    const SDLStatic_SceneDef level = MakeDef("level");
    const SDLStatic_SceneDef menu = MakeDef("menu");

    SDLStatic_ScenePush(engine_, &level);
    Frame(3);
    SceneState *level_state =
        static_cast<SceneState *>(SDLStatic_SceneState(SDLStatic_SceneCurrent(engine_)));
    const int before = level_state->fixed_updates;
    EXPECT_GT(before, 0);

    SDLStatic_ScenePush(engine_, &menu);
    Frame(); // the push lands at the end of this frame, so the level still
             // simulates once more — that is the deferral rule working
    const int covered_at = level_state->fixed_updates;
    Frame(3);
    EXPECT_EQ(SDLStatic_SceneDepth(engine_), 2);
    EXPECT_STREQ(SDLStatic_SceneName(SDLStatic_SceneCurrent(engine_)), "menu");
    EXPECT_EQ(level_state->fixed_updates, covered_at)
        << "a covered scene is paused by default";
    EXPECT_TRUE(LoggedInOrder({"level:enter", "level:exit", "menu:enter"}));

    SDLStatic_ScenePop(engine_);
    Frame(3);
    EXPECT_EQ(SDLStatic_SceneDepth(engine_), 1);
    EXPECT_GT(level_state->fixed_updates, covered_at) << "and resumes when uncovered";
    EXPECT_GT(covered_at, before);
    EXPECT_TRUE(LoggedInOrder({"menu:exit", "menu:unload", "level:enter"}));
}

// A level under a dialogue box should keep running; a level under a pause
// menu should not. The flag is the difference.
TEST_F(SceneHarness, CoveredScenesRunOnlyIfTheyAskTo)
{
    const SDLStatic_SceneDef level = MakeDef("level", SDLSTATIC_SCENE_UPDATE_WHEN_COVERED);
    const SDLStatic_SceneDef dialogue = MakeDef("dialogue", SDLSTATIC_SCENE_TRANSPARENT);

    SDLStatic_ScenePush(engine_, &level);
    Frame();
    SceneState *level_state =
        static_cast<SceneState *>(SDLStatic_SceneState(SDLStatic_SceneCurrent(engine_)));

    SDLStatic_ScenePush(engine_, &dialogue);
    Frame();
    const int updates = level_state->fixed_updates;
    const int renders = level_state->renders;
    Frame(3);

    EXPECT_GT(level_state->fixed_updates, updates) << "still simulating under the dialogue";
    EXPECT_GT(level_state->renders, renders) << "and still drawn, because it is transparent";
}

// An opaque scene on top means the one below is not drawn at all — the
// saving that makes a stack cheap.
TEST_F(SceneHarness, AnOpaqueSceneHidesTheOneBelow)
{
    const SDLStatic_SceneDef level = MakeDef("level", SDLSTATIC_SCENE_UPDATE_WHEN_COVERED);
    const SDLStatic_SceneDef full = MakeDef("full"); // opaque by default

    SDLStatic_ScenePush(engine_, &level);
    Frame();
    SceneState *level_state =
        static_cast<SceneState *>(SDLStatic_SceneState(SDLStatic_SceneCurrent(engine_)));

    SDLStatic_ScenePush(engine_, &full);
    Frame(2); // one frame for the push to land, one to be safely covered
    const int renders = level_state->renders;
    Frame(3);
    EXPECT_EQ(level_state->renders, renders) << "hidden scenes are not rendered";
}

// Replace destroys the old scene; reset empties the stack first.
TEST_F(SceneHarness, ReplaceAndReset)
{
    const SDLStatic_SceneDef one = MakeDef("one");
    const SDLStatic_SceneDef two = MakeDef("two");
    const SDLStatic_SceneDef three = MakeDef("three");

    SDLStatic_ScenePush(engine_, &one);
    Frame();
    SDLStatic_ScenePush(engine_, &two);
    Frame();
    EXPECT_EQ(SDLStatic_SceneDepth(engine_), 2);

    SDLStatic_SceneReplace(engine_, &three);
    Frame();
    EXPECT_EQ(SDLStatic_SceneDepth(engine_), 2) << "replace swaps the top only";
    EXPECT_STREQ(SDLStatic_SceneName(SDLStatic_SceneCurrent(engine_)), "three");
    EXPECT_TRUE(LoggedInOrder({"two:unload", "three:load"}));

    SDLStatic_SceneReset(engine_, &one);
    Frame();
    EXPECT_EQ(SDLStatic_SceneDepth(engine_), 1) << "reset clears the whole stack";
    EXPECT_STREQ(SDLStatic_SceneName(SDLStatic_SceneCurrent(engine_)), "one");
}

// The reason changes are deferred: a scene must be able to replace itself
// from inside its own update without the ground moving underneath.
TEST_F(SceneHarness, ASceneCanReplaceItselfFromItsOwnUpdate)
{
    static SDLStatic_SceneDef next = MakeDef("next");
    static SDLStatic_SceneDef first = MakeDef("first");
    first.update = [](SDLStatic_Scene *scene, float dt) {
        (void)dt;
        SceneState *state = static_cast<SceneState *>(SDLStatic_SceneState(scene));
        // Ask on the second frame, then keep touching our own state: if the
        // stack had changed underneath us this would be a use-after-free,
        // which is what ASan is here to notice.
        if (state->fixed_updates == 2)
        {
            SDLStatic_SceneReplace(SDLStatic_SceneEngine(scene), &next);
        }
        state->renders += 0;
    };

    SDLStatic_ScenePush(engine_, &first);
    Frame(6);
    EXPECT_STREQ(SDLStatic_SceneName(SDLStatic_SceneCurrent(engine_)), "next");
    EXPECT_TRUE(LoggedInOrder({"first:exit", "first:unload", "next:load", "next:enter"}));
}

// Two changes in one frame is a game bug: the second would silently win.
TEST_F(SceneHarness, TwoStackChangesInOneFrameIsAnError)
{
    const SDLStatic_SceneDef one = MakeDef("one");
    const SDLStatic_SceneDef two = MakeDef("two");
    EXPECT_TRUE(SDLStatic_ScenePush(engine_, &one));
    EXPECT_FALSE(SDLStatic_ScenePush(engine_, &two));
    EXPECT_NE(std::string(SDL_GetError()).find("already queued"), std::string::npos);
}

// A scene whose load fails must not end up on the stack, and must not
// disturb whatever was already there.
TEST_F(SceneHarness, AFailedLoadLeavesTheStackAlone)
{
    const SDLStatic_SceneDef good = MakeDef("good");
    SDLStatic_SceneDef bad = MakeDef("bad");
    bad.load = [](SDLStatic_Scene *scene) {
        Note(scene, "load");
        SDL_SetError("no");
        return false;
    };

    SDLStatic_ScenePush(engine_, &good);
    Frame();
    SDLStatic_ScenePush(engine_, &bad);
    Frame();

    EXPECT_EQ(SDLStatic_SceneDepth(engine_), 1);
    EXPECT_STREQ(SDLStatic_SceneName(SDLStatic_SceneCurrent(engine_)), "good");
    EXPECT_TRUE(SDLStatic_SceneIsActive(SDLStatic_SceneCurrent(engine_)))
        << "the surviving scene is active again";
}

// Transitions swap at the midpoint, where the screen is covered.
TEST_F(SceneHarness, FadeTransitionSwapsAtTheMidpoint)
{
    const SDLStatic_SceneDef from = MakeDef("from");
    const SDLStatic_SceneDef to = MakeDef("to");
    SDLStatic_ScenePush(engine_, &from);
    Frame();

    ASSERT_TRUE(SDLStatic_SceneTransitionTo(engine_, &to, SDLSTATIC_TRANSITION_FADE, 0.2f));
    EXPECT_TRUE(SDLStatic_SceneTransitioning(engine_));

    // A tenth of a second in — before the midpoint — the old scene is
    // still the live one.
    Frame(6);
    EXPECT_STREQ(SDLStatic_SceneName(SDLStatic_SceneCurrent(engine_)), "from");

    Frame(6); // past the midpoint
    EXPECT_STREQ(SDLStatic_SceneName(SDLStatic_SceneCurrent(engine_)), "to");

    Frame(12); // past the end
    EXPECT_FALSE(SDLStatic_SceneTransitioning(engine_));
    EXPECT_EQ(SDLStatic_SceneDepth(engine_), 1);

    // A second transition is refused while one is running.
    ASSERT_TRUE(SDLStatic_SceneTransitionTo(engine_, &from, SDLSTATIC_TRANSITION_FADE, 0.2f));
    EXPECT_FALSE(SDLStatic_SceneTransitionTo(engine_, &to, SDLSTATIC_TRANSITION_FADE, 0.2f));
}

// A zero-length or NONE transition is just a replace, rather than an error
// or a one-frame flash.
TEST_F(SceneHarness, AnInstantTransitionIsAPlainReplace)
{
    const SDLStatic_SceneDef from = MakeDef("from");
    const SDLStatic_SceneDef to = MakeDef("to");
    SDLStatic_ScenePush(engine_, &from);
    Frame();
    EXPECT_TRUE(SDLStatic_SceneTransitionTo(engine_, &to, SDLSTATIC_TRANSITION_NONE, 0.0f));
    Frame();
    EXPECT_STREQ(SDLStatic_SceneName(SDLStatic_SceneCurrent(engine_)), "to");
    EXPECT_FALSE(SDLStatic_SceneTransitioning(engine_));
}

// Lookup by name, so a menu can talk to the level underneath it.
TEST_F(SceneHarness, ScenesAreFindableByName)
{
    const SDLStatic_SceneDef level = MakeDef("level");
    const SDLStatic_SceneDef menu = MakeDef("menu");
    SDLStatic_ScenePush(engine_, &level);
    Frame();
    SDLStatic_ScenePush(engine_, &menu);
    Frame();

    SDLStatic_Scene *found = SDLStatic_SceneFind(engine_, "level");
    ASSERT_NE(found, nullptr);
    EXPECT_STREQ(SDLStatic_SceneName(found), "level");
    EXPECT_FALSE(SDLStatic_SceneIsActive(found)) << "found, but covered";
    EXPECT_NE(SDLStatic_SceneState(found), nullptr);
    EXPECT_EQ(SDLStatic_SceneFind(engine_, "nothing"), nullptr);
}

// The stack has a ceiling, and reaching it is an error rather than a
// silent overwrite.
TEST_F(SceneHarness, TheStackHasALimit)
{
    const SDLStatic_SceneDef def = MakeDef("deep");
    for (int i = 0; i < SDLSTATIC_SCENE_STACK_MAX; i++)
    {
        EXPECT_TRUE(SDLStatic_ScenePush(engine_, &def)) << "push " << i;
        Frame();
    }
    EXPECT_EQ(SDLStatic_SceneDepth(engine_), SDLSTATIC_SCENE_STACK_MAX);
    SDLStatic_ScenePush(engine_, &def);
    Frame();
    EXPECT_EQ(SDLStatic_SceneDepth(engine_), SDLSTATIC_SCENE_STACK_MAX) << "no overflow";
}

TEST_F(SceneHarness, NullsAreHandled)
{
    EXPECT_FALSE(SDLStatic_ScenePush(nullptr, nullptr));
    EXPECT_FALSE(SDLStatic_ScenePush(engine_, nullptr));
    EXPECT_FALSE(SDLStatic_ScenePop(nullptr));
    EXPECT_FALSE(SDLStatic_SceneReplace(engine_, nullptr));
    EXPECT_FALSE(SDLStatic_SceneReset(engine_, nullptr));
    EXPECT_EQ(SDLStatic_SceneCurrent(nullptr), nullptr);
    EXPECT_EQ(SDLStatic_SceneDepth(nullptr), 0);
    EXPECT_EQ(SDLStatic_SceneFind(nullptr, "x"), nullptr);
    EXPECT_EQ(SDLStatic_SceneState(nullptr), nullptr);
    EXPECT_EQ(SDLStatic_SceneEngine(nullptr), nullptr);
    EXPECT_EQ(SDLStatic_SceneName(nullptr), nullptr);
    EXPECT_FALSE(SDLStatic_SceneIsActive(nullptr));
    EXPECT_FALSE(SDLStatic_SceneTransitionTo(nullptr, nullptr, SDLSTATIC_TRANSITION_FADE, 1.0f));
    EXPECT_FALSE(SDLStatic_SceneTransitioning(nullptr));
    SDLStatic_SceneSetTransitionColor(nullptr, SDL_FColor{});
}

} // namespace
