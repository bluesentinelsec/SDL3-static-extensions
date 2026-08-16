// Actors: handles, deferral, hierarchy, messages.
//
// The tests lean hard on the cases that make an actor system crash months
// later rather than immediately: a handle kept past the actor's death, an
// actor destroying another during an update it is inside, a parent
// destroyed with children attached, and two things killing the same target
// in one frame.
#include <SDLStatic/engine_actor.h>

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace
{

struct Counter
{
    int fixed_updates = 0;
    int updates = 0;
    int messages = 0;
    int destroyed = 0;
    float last_a = 0.0f;
};

// Actors carry an index into this, not a pointer, so the vector may grow
// without invalidating anything an actor holds.
std::vector<Counter> g_counters;

struct Slot
{
    size_t index = 0;
};

Counter &CounterFor(SDLStatic_Actor *actor)
{
    return g_counters[static_cast<Slot *>(SDLStatic_ActorState(actor))->index];
}

size_t NewCounter()
{
    g_counters.emplace_back();
    return g_counters.size() - 1;
}

void OnFixed(SDLStatic_Actor *actor, float) { CounterFor(actor).fixed_updates++; }
void OnUpdate(SDLStatic_Actor *actor, float) { CounterFor(actor).updates++; }
void OnDestroy(SDLStatic_Actor *actor) { CounterFor(actor).destroyed++; }
void OnMessage(SDLStatic_Actor *actor, const SDLStatic_ActorMessage *m)
{
    Counter &c = CounterFor(actor);
    c.messages++;
    c.last_a = m->a;
}

class ActorHarness : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
        g_counters.clear();
        SDLStatic_EngineConfig config{};
        config.headless = true;
        config.manual_clock = true;
        config.no_auto_mount = true;
        config.design_width = 640;
        config.design_height = 360;
        engine_ = SDLStatic_CreateEngine(&config);
        ASSERT_NE(engine_, nullptr) << SDL_GetError();
    }
    void TearDown() override
    {
        SDLStatic_DestroyEngine(engine_);
        SDL_Quit();
    }

    // Spawn something with a counter attached.
    SDLStatic_ActorId Spawn(const char *type, float x = 0.0f, float y = 0.0f,
                            SDLStatic_ActorId parent = SDLSTATIC_ACTOR_NONE)
    {
        SDLStatic_ActorDef def{};
        def.type = type;
        def.state_size = sizeof(Slot);
        def.x = x;
        def.y = y;
        def.parent = parent;
        def.fixed_update = OnFixed;
        def.update = OnUpdate;
        def.message = OnMessage;
        def.destroy = OnDestroy;

        const size_t index = NewCounter();
        const SDLStatic_ActorId id = SDLStatic_ActorSpawn(engine_, &def);
        if (id != SDLSTATIC_ACTOR_NONE)
        {
            static_cast<Slot *>(SDLStatic_ActorState(SDLStatic_ActorGet(engine_, id)))->index =
                index;
        }
        return id;
    }

    void RunFrames(int frames)
    {
        for (int i = 0; i < frames; ++i)
        {
            SDLStatic_EngineAdvance(engine_, 16666667ull);
            SDLStatic_EngineTick(engine_);
        }
    }

    SDLStatic_Engine *engine_ = nullptr;
};

TEST_F(ActorHarness, SpawnGivesAUsableHandleImmediately)
{
    const SDLStatic_ActorId id = Spawn("goblin", 10.0f, 20.0f);
    ASSERT_NE(id, SDLSTATIC_ACTOR_NONE);

    // Usable before the frame ends, so the caller can set the thing up...
    SDLStatic_Actor *actor = SDLStatic_ActorGet(engine_, id);
    ASSERT_NE(actor, nullptr);
    EXPECT_STREQ(SDLStatic_ActorType(actor), "goblin");
    EXPECT_FLOAT_EQ(SDLStatic_ActorLocal(actor).x, 10.0f);

    // ...but not yet running or visible to queries.
    EXPECT_EQ(SDLStatic_ActorCount(engine_), 0);
    EXPECT_EQ(SDLStatic_ActorFindByType(engine_, "goblin"), SDLSTATIC_ACTOR_NONE);

    RunFrames(1);
    EXPECT_EQ(SDLStatic_ActorCount(engine_), 1);
    EXPECT_EQ(SDLStatic_ActorFindByType(engine_, "goblin"), id);
}

TEST_F(ActorHarness, ADefaultDefProducesAVisibleActor)
{
    SDLStatic_ActorDef def{};
    def.type = "thing";
    const SDLStatic_ActorId id = SDLStatic_ActorSpawn(engine_, &def);
    ASSERT_NE(id, SDLSTATIC_ACTOR_NONE);
    const SDLStatic_ActorTransform t = SDLStatic_ActorLocal(SDLStatic_ActorGet(engine_, id));
    EXPECT_FLOAT_EQ(t.scale_x, 1.0f) << "zero scale would be an invisible actor";
    EXPECT_FLOAT_EQ(t.scale_y, 1.0f);
}

// The reason this is a handle and not a pointer.
TEST_F(ActorHarness, AHandleToADeadActorStopsResolving)
{
    const SDLStatic_ActorId id = Spawn("goblin");
    RunFrames(1);
    ASSERT_TRUE(SDLStatic_ActorAlive(engine_, id));

    SDLStatic_ActorDestroy(engine_, id);
    RunFrames(1);

    EXPECT_FALSE(SDLStatic_ActorAlive(engine_, id));
    EXPECT_EQ(SDLStatic_ActorGet(engine_, id), nullptr);
}

// And the case that makes generations worth the bits: the slot is reused,
// and the *old* handle must not address its replacement.
TEST_F(ActorHarness, AReusedSlotDoesNotResurrectAnOldHandle)
{
    const SDLStatic_ActorId first = Spawn("first");
    RunFrames(1);
    SDLStatic_ActorDestroy(engine_, first);
    RunFrames(1);

    const SDLStatic_ActorId second = Spawn("second");
    RunFrames(1);

    EXPECT_NE(first, second) << "the same slot, a later generation";
    EXPECT_FALSE(SDLStatic_ActorAlive(engine_, first));
    ASSERT_TRUE(SDLStatic_ActorAlive(engine_, second));
    EXPECT_STREQ(SDLStatic_ActorType(SDLStatic_ActorGet(engine_, second)), "second");
}

TEST_F(ActorHarness, DestroyingTwiceIsHarmless)
{
    const SDLStatic_ActorId id = Spawn("goblin");
    RunFrames(1);
    SDLStatic_ActorDestroy(engine_, id);
    SDLStatic_ActorDestroy(engine_, id); // two things killed it this frame
    RunFrames(1);
    EXPECT_FALSE(SDLStatic_ActorAlive(engine_, id));
    EXPECT_EQ(g_counters[0].destroyed, 1) << "destroyed once, not twice";
}

TEST_F(ActorHarness, UpdatesRunOnLiveEnabledActorsOnly)
{
    const SDLStatic_ActorId a = Spawn("a");
    const SDLStatic_ActorId b = Spawn("b");
    RunFrames(1);
    SDLStatic_ActorSetEnabled(SDLStatic_ActorGet(engine_, b), false);

    RunFrames(3);
    EXPECT_GT(g_counters[0].fixed_updates, 0);
    // Three, not four: the actor was admitted at the *end* of the frame it
    // was spawned in, so that first frame never updated it.
    EXPECT_EQ(g_counters[0].updates, 3);
    EXPECT_EQ(g_counters[1].fixed_updates, 0) << "disabled";
    EXPECT_EQ(g_counters[1].updates, 0);
    (void)a;
}

// The crash this system exists to prevent: an actor killing another during
// an update that is iterating them.
TEST_F(ActorHarness, AnActorMayDestroyAnotherFromInsideAnUpdate)
{
    static SDLStatic_ActorId target;
    static SDLStatic_Engine *engine_ptr;
    engine_ptr = engine_;

    target = Spawn("victim");
    SDLStatic_ActorDef def{};
    def.type = "killer";
    def.fixed_update = [](SDLStatic_Actor *, float) {
        SDLStatic_ActorDestroy(engine_ptr, target);
    };
    ASSERT_NE(SDLStatic_ActorSpawn(engine_, &def), SDLSTATIC_ACTOR_NONE);

    RunFrames(3);
    EXPECT_FALSE(SDLStatic_ActorAlive(engine_, target));
    EXPECT_EQ(SDLStatic_ActorCount(engine_), 1) << "the killer survives";
}

// Spawning from inside an update is equally safe, and the new actor must
// not run in the frame it was created in.
TEST_F(ActorHarness, SpawningFromInsideAnUpdateIsSafe)
{
    static SDLStatic_Engine *engine_ptr;
    static int spawned;
    engine_ptr = engine_;
    spawned = 0;

    SDLStatic_ActorDef spawner{};
    spawner.type = "spawner";
    spawner.fixed_update = [](SDLStatic_Actor *, float) {
        if (spawned < 3)
        {
            SDLStatic_ActorDef child{};
            child.type = "spawned";
            SDLStatic_ActorSpawn(engine_ptr, &child);
            spawned++;
        }
    };
    ASSERT_NE(SDLStatic_ActorSpawn(engine_, &spawner), SDLSTATIC_ACTOR_NONE);

    RunFrames(6);
    EXPECT_EQ(spawned, 3);
    EXPECT_EQ(SDLStatic_ActorCount(engine_), 4);
}

TEST_F(ActorHarness, AFailedSpawnLeavesNothingBehind)
{
    SDLStatic_ActorDef def{};
    def.type = "refuses";
    def.state_size = sizeof(Slot);
    def.spawn = [](SDLStatic_Actor *) { return false; };

    EXPECT_EQ(SDLStatic_ActorSpawn(engine_, &def), SDLSTATIC_ACTOR_NONE);
    RunFrames(1);
    EXPECT_EQ(SDLStatic_ActorCount(engine_), 0);
    EXPECT_EQ(SDLStatic_ActorFindByType(engine_, "refuses"), SDLSTATIC_ACTOR_NONE);
}

// --- hierarchy ------------------------------------------------------------

TEST_F(ActorHarness, ChildTransformsComposeThroughTheParent)
{
    const SDLStatic_ActorId parent = Spawn("parent", 100.0f, 50.0f);
    const SDLStatic_ActorId child = Spawn("child", 10.0f, 5.0f, parent);
    RunFrames(1);

    const SDLStatic_ActorTransform w =
        SDLStatic_ActorWorld(SDLStatic_ActorGet(engine_, child));
    EXPECT_FLOAT_EQ(w.x, 110.0f);
    EXPECT_FLOAT_EQ(w.y, 55.0f);

    // Moving the parent moves the child.
    SDLStatic_ActorMove(SDLStatic_ActorGet(engine_, parent), 10.0f, 0.0f);
    EXPECT_FLOAT_EQ(SDLStatic_ActorWorld(SDLStatic_ActorGet(engine_, child)).x, 120.0f);
}

TEST_F(ActorHarness, RotationAndScaleComposeToo)
{
    const SDLStatic_ActorId parent = Spawn("parent", 0.0f, 0.0f);
    SDLStatic_Actor *p = SDLStatic_ActorGet(engine_, parent);
    SDLStatic_ActorTransform t = SDLStatic_ActorLocal(p);
    t.rotation = 90.0f;
    t.scale_x = 2.0f;
    t.scale_y = 2.0f;
    SDLStatic_ActorSetLocal(p, &t);

    const SDLStatic_ActorId child = Spawn("child", 10.0f, 0.0f, parent);
    RunFrames(1);

    // (10,0) scaled by 2 and rotated 90 degrees lands on (0,20).
    const SDLStatic_ActorTransform w =
        SDLStatic_ActorWorld(SDLStatic_ActorGet(engine_, child));
    EXPECT_NEAR(w.x, 0.0f, 0.001f);
    EXPECT_NEAR(w.y, 20.0f, 0.001f);
    EXPECT_FLOAT_EQ(w.scale_x, 2.0f);
    EXPECT_FLOAT_EQ(w.rotation, 90.0f);
}

TEST_F(ActorHarness, DestroyingAParentTakesItsChildren)
{
    const SDLStatic_ActorId parent = Spawn("parent");
    const SDLStatic_ActorId child = Spawn("child", 0.0f, 0.0f, parent);
    const SDLStatic_ActorId grandchild = Spawn("grandchild", 0.0f, 0.0f, child);
    RunFrames(1);
    ASSERT_EQ(SDLStatic_ActorCount(engine_), 3);

    SDLStatic_ActorDestroy(engine_, parent);
    RunFrames(1);

    EXPECT_EQ(SDLStatic_ActorCount(engine_), 0) << "\"part of\" has to mean something";
    EXPECT_FALSE(SDLStatic_ActorAlive(engine_, child));
    EXPECT_FALSE(SDLStatic_ActorAlive(engine_, grandchild));
    for (const Counter &c : g_counters)
    {
        EXPECT_EQ(c.destroyed, 1) << "every one gets its hook";
    }
}

// Reparenting keeps the world position: "pick this up" must not teleport it.
TEST_F(ActorHarness, ReparentingKeepsTheWorldPosition)
{
    const SDLStatic_ActorId holder = Spawn("holder", 300.0f, 200.0f);
    const SDLStatic_ActorId item = Spawn("item", 50.0f, 60.0f);
    RunFrames(1);

    SDLStatic_Actor *actor = SDLStatic_ActorGet(engine_, item);
    ASSERT_TRUE(SDLStatic_ActorSetParent(actor, holder));

    const SDLStatic_ActorTransform w = SDLStatic_ActorWorld(actor);
    EXPECT_NEAR(w.x, 50.0f, 0.001f) << "still where it was";
    EXPECT_NEAR(w.y, 60.0f, 0.001f);
    EXPECT_NEAR(SDLStatic_ActorLocal(actor).x, -250.0f, 0.001f) << "local is now relative";

    // Detaching keeps it too.
    ASSERT_TRUE(SDLStatic_ActorSetParent(actor, SDLSTATIC_ACTOR_NONE));
    EXPECT_NEAR(SDLStatic_ActorWorld(actor).x, 50.0f, 0.001f);
    EXPECT_EQ(SDLStatic_ActorParent(actor), SDLSTATIC_ACTOR_NONE);
}

// A cycle would make every transform walk run forever, so it is refused
// rather than discovered later by a hang.
TEST_F(ActorHarness, ACycleIsRefused)
{
    const SDLStatic_ActorId a = Spawn("a");
    const SDLStatic_ActorId b = Spawn("b", 0.0f, 0.0f, a);
    const SDLStatic_ActorId c = Spawn("c", 0.0f, 0.0f, b);
    RunFrames(1);

    // a cannot be parented to its own grandchild...
    EXPECT_FALSE(SDLStatic_ActorSetParent(SDLStatic_ActorGet(engine_, a), c));
    // ...nor to itself.
    EXPECT_FALSE(SDLStatic_ActorSetParent(SDLStatic_ActorGet(engine_, a), a));
    // The hierarchy is untouched by the refusal.
    EXPECT_EQ(SDLStatic_ActorParent(SDLStatic_ActorGet(engine_, c)), b);
}

TEST_F(ActorHarness, ChildrenAreEnumerable)
{
    const SDLStatic_ActorId parent = Spawn("parent");
    const SDLStatic_ActorId first = Spawn("child", 0.0f, 0.0f, parent);
    const SDLStatic_ActorId second = Spawn("child", 0.0f, 0.0f, parent);
    RunFrames(1);

    SDLStatic_Actor *p = SDLStatic_ActorGet(engine_, parent);
    ASSERT_EQ(SDLStatic_ActorChildCount(p), 2);
    std::vector<SDLStatic_ActorId> seen{SDLStatic_ActorChild(p, 0), SDLStatic_ActorChild(p, 1)};
    EXPECT_NE(std::find(seen.begin(), seen.end(), first), seen.end());
    EXPECT_NE(std::find(seen.begin(), seen.end(), second), seen.end());
    EXPECT_EQ(SDLStatic_ActorChild(p, 2), SDLSTATIC_ACTOR_NONE);

    // Destroying one child leaves the other attached.
    SDLStatic_ActorDestroy(engine_, first);
    RunFrames(1);
    EXPECT_EQ(SDLStatic_ActorChildCount(SDLStatic_ActorGet(engine_, parent)), 1);
}

// --- interpolation --------------------------------------------------------

// The actor half of the loop's interpolation contract: the engine keeps the
// previous transform so no game has to.
TEST_F(ActorHarness, RenderTransformsAreInterpolated)
{
    SDLStatic_ActorDef def{};
    def.type = "mover";
    def.fixed_update = [](SDLStatic_Actor *actor, float) {
        SDLStatic_ActorMove(actor, 10.0f, 0.0f);
    };
    const SDLStatic_ActorId id = SDLStatic_ActorSpawn(engine_, &def);
    RunFrames(2);

    SDLStatic_Actor *actor = SDLStatic_ActorGet(engine_, id);
    const float now = SDLStatic_ActorWorld(actor).x;
    EXPECT_NEAR(SDLStatic_ActorRenderTransform(actor, 1.0f).x, now, 0.001f);
    EXPECT_NEAR(SDLStatic_ActorRenderTransform(actor, 0.0f).x, now - 10.0f, 0.001f)
        << "one step behind";
    EXPECT_NEAR(SDLStatic_ActorRenderTransform(actor, 0.5f).x, now - 5.0f, 0.001f);
}

// A teleport must not be interpolated, or the actor smears across the
// screen from somewhere it never was.
TEST_F(ActorHarness, ATeleportIsNotInterpolated)
{
    const SDLStatic_ActorId id = Spawn("thing", 0.0f, 0.0f);
    RunFrames(2);

    SDLStatic_Actor *actor = SDLStatic_ActorGet(engine_, id);
    SDLStatic_ActorTeleport(actor, 5000.0f, 0.0f);
    EXPECT_FLOAT_EQ(SDLStatic_ActorRenderTransform(actor, 0.0f).x, 5000.0f);
    EXPECT_FLOAT_EQ(SDLStatic_ActorRenderTransform(actor, 1.0f).x, 5000.0f);
}

// --- queries --------------------------------------------------------------

TEST_F(ActorHarness, QueriesFilterByTypeAndTags)
{
    constexpr SDLStatic_ActorTags kEnemy = 1u << 0;
    constexpr SDLStatic_ActorTags kSolid = 1u << 1;

    const SDLStatic_ActorId goblin = Spawn("goblin");
    const SDLStatic_ActorId orc = Spawn("orc");
    Spawn("rock");
    RunFrames(1);

    SDLStatic_ActorSetTags(SDLStatic_ActorGet(engine_, goblin), kEnemy | kSolid);
    SDLStatic_ActorSetTags(SDLStatic_ActorGet(engine_, orc), kEnemy);

    SDLStatic_ActorId found[8];
    EXPECT_EQ(SDLStatic_ActorQuery(engine_, nullptr, kEnemy, found, 8), 2);
    EXPECT_EQ(SDLStatic_ActorQuery(engine_, nullptr, kSolid, found, 8), 1);
    EXPECT_EQ(SDLStatic_ActorQuery(engine_, "goblin", 0, found, 8), 1);
    EXPECT_EQ(SDLStatic_ActorQuery(engine_, "goblin", kEnemy, found, 8), 1) << "both must match";
    EXPECT_EQ(SDLStatic_ActorQuery(engine_, "rock", kEnemy, found, 8), 0);
    EXPECT_EQ(SDLStatic_ActorQuery(engine_, nullptr, 0, found, 8), 3) << "no filter, everything";

    // A caller's array is never overrun.
    EXPECT_EQ(SDLStatic_ActorQuery(engine_, nullptr, 0, found, 2), 2);
}

TEST_F(ActorHarness, ActorsAreFindableByName)
{
    SDLStatic_ActorDef def{};
    def.type = "door";
    def.name = "exit";
    const SDLStatic_ActorId id = SDLStatic_ActorSpawn(engine_, &def);
    RunFrames(1);
    EXPECT_EQ(SDLStatic_ActorFindByName(engine_, "exit"), id);
    EXPECT_EQ(SDLStatic_ActorFindByName(engine_, "nowhere"), SDLSTATIC_ACTOR_NONE);
}

TEST_F(ActorHarness, EachVisitsEveryLiveActorAndCanStop)
{
    Spawn("a");
    Spawn("b");
    Spawn("c");
    RunFrames(1);

    int visited = 0;
    SDLStatic_ActorEach(
        engine_, [](SDLStatic_Actor *, void *user) { (*static_cast<int *>(user))++; return true; },
        &visited);
    EXPECT_EQ(visited, 3);

    int before_stop = 0;
    SDLStatic_ActorEach(
        engine_,
        [](SDLStatic_Actor *, void *user) { return ++(*static_cast<int *>(user)) < 2; },
        &before_stop);
    EXPECT_EQ(before_stop, 2) << "returning false stops the walk";
}

// --- messages -------------------------------------------------------------

TEST_F(ActorHarness, MessagesArriveInTheSameFrame)
{
    const SDLStatic_ActorId id = Spawn("target");
    RunFrames(1);

    SDLStatic_ActorMessage message{};
    message.id = 7;
    message.a = 12.5f;
    EXPECT_TRUE(SDLStatic_ActorSend(engine_, id, &message));
    EXPECT_EQ(g_counters[0].messages, 0) << "queued, not called through";

    RunFrames(1);
    EXPECT_EQ(g_counters[0].messages, 1);
    EXPECT_FLOAT_EQ(g_counters[0].last_a, 12.5f);
}

TEST_F(ActorHarness, SendingToADeadActorFails)
{
    const SDLStatic_ActorId id = Spawn("target");
    RunFrames(1);
    SDLStatic_ActorDestroy(engine_, id);
    RunFrames(1);

    SDLStatic_ActorMessage message{};
    EXPECT_FALSE(SDLStatic_ActorSend(engine_, id, &message));
}

// A target that dies between the send and the delivery simply does not get
// it, which is what "it is gone" should mean.
TEST_F(ActorHarness, AMessageToSomethingThatDiesFirstIsDropped)
{
    const SDLStatic_ActorId id = Spawn("target");
    RunFrames(1);

    SDLStatic_ActorMessage message{};
    ASSERT_TRUE(SDLStatic_ActorSend(engine_, id, &message));
    SDLStatic_ActorDestroy(engine_, id); // same frame, before delivery
    RunFrames(2);
    EXPECT_EQ(g_counters[0].messages, 0);
}

TEST_F(ActorHarness, BroadcastFiltersLikeAQuery)
{
    constexpr SDLStatic_ActorTags kEnemy = 1u << 0;
    const SDLStatic_ActorId goblin = Spawn("goblin");
    const SDLStatic_ActorId orc = Spawn("orc");
    Spawn("rock");
    RunFrames(1);
    SDLStatic_ActorSetTags(SDLStatic_ActorGet(engine_, goblin), kEnemy);
    SDLStatic_ActorSetTags(SDLStatic_ActorGet(engine_, orc), kEnemy);

    SDLStatic_ActorMessage message{};
    message.a = 3.0f;
    EXPECT_EQ(SDLStatic_ActorBroadcast(engine_, nullptr, kEnemy, &message), 2);
    RunFrames(1);
    EXPECT_EQ(g_counters[0].messages, 1);
    EXPECT_EQ(g_counters[1].messages, 1);
    EXPECT_EQ(g_counters[2].messages, 0) << "the rock is not an enemy";
}

// Two actors answering each other must not recurse: the exchange is spread
// over frames, so a runaway is visibly slow rather than a stack overflow.
TEST_F(ActorHarness, AnEndlessExchangeIsSpreadOverFramesRatherThanRecursing)
{
    static SDLStatic_Engine *engine_ptr;
    static SDLStatic_ActorId ping;
    static SDLStatic_ActorId pong;
    static int exchanges;
    engine_ptr = engine_;
    exchanges = 0;

    auto reply = [](SDLStatic_Actor *actor, const SDLStatic_ActorMessage *) {
        exchanges++;
        const SDLStatic_ActorId self = SDLStatic_ActorGetId(actor);
        SDLStatic_ActorMessage back{};
        SDLStatic_ActorSend(engine_ptr, (self == ping) ? pong : ping, &back);
    };

    SDLStatic_ActorDef def{};
    def.type = "ping";
    def.message = reply;
    ping = SDLStatic_ActorSpawn(engine_, &def);
    def.type = "pong";
    pong = SDLStatic_ActorSpawn(engine_, &def);
    RunFrames(1);

    SDLStatic_ActorMessage start{};
    SDLStatic_ActorSend(engine_, ping, &start);
    RunFrames(5);

    // One exchange per frame, not an unbounded chain inside one.
    EXPECT_EQ(exchanges, 5);
}

// --- teardown -------------------------------------------------------------

TEST_F(ActorHarness, ClearDestroysEverythingNow)
{
    Spawn("a");
    const SDLStatic_ActorId parent = Spawn("b");
    Spawn("child", 0.0f, 0.0f, parent);
    RunFrames(1);
    ASSERT_EQ(SDLStatic_ActorCount(engine_), 3);

    SDLStatic_ActorClear(engine_);
    EXPECT_EQ(SDLStatic_ActorCount(engine_), 0) << "immediately, not next frame";
    for (const Counter &c : g_counters)
    {
        EXPECT_EQ(c.destroyed, 1);
    }
}

TEST_F(ActorHarness, TheWorldGrowsPastItsFirstBlock)
{
    // More than the initial capacity, to exercise the growth path and the
    // free list that comes with it.
    std::vector<SDLStatic_ActorId> ids;
    for (int i = 0; i < 300; ++i)
    {
        ids.push_back(Spawn("many"));
    }
    RunFrames(1);
    EXPECT_EQ(SDLStatic_ActorCount(engine_), 300);
    for (const SDLStatic_ActorId id : ids)
    {
        EXPECT_TRUE(SDLStatic_ActorAlive(engine_, id));
    }

    // Destroy half; the freed slots come back for reuse.
    for (size_t i = 0; i < ids.size(); i += 2)
    {
        SDLStatic_ActorDestroy(engine_, ids[i]);
    }
    RunFrames(1);
    EXPECT_EQ(SDLStatic_ActorCount(engine_), 150);
    for (int i = 0; i < 50; ++i)
    {
        EXPECT_NE(Spawn("more"), SDLSTATIC_ACTOR_NONE);
    }
    RunFrames(1);
    EXPECT_EQ(SDLStatic_ActorCount(engine_), 200);
}

TEST_F(ActorHarness, NullsAndNonsenseAreHandled)
{
    EXPECT_EQ(SDLStatic_ActorSpawn(engine_, nullptr), SDLSTATIC_ACTOR_NONE);
    EXPECT_EQ(SDLStatic_ActorSpawn(nullptr, nullptr), SDLSTATIC_ACTOR_NONE);
    EXPECT_EQ(SDLStatic_ActorGet(engine_, SDLSTATIC_ACTOR_NONE), nullptr);
    EXPECT_EQ(SDLStatic_ActorGet(engine_, 0xDEADBEEFull), nullptr) << "a made-up handle";
    EXPECT_FALSE(SDLStatic_ActorAlive(nullptr, 1));
    EXPECT_EQ(SDLStatic_ActorCount(nullptr), 0);
    EXPECT_EQ(SDLStatic_ActorState(nullptr), nullptr);
    EXPECT_EQ(SDLStatic_ActorType(nullptr), nullptr);
    EXPECT_EQ(SDLStatic_ActorChildCount(nullptr), 0);
    EXPECT_FALSE(SDLStatic_ActorSetParent(nullptr, 1));
    EXPECT_EQ(SDLStatic_ActorFindByType(engine_, nullptr), SDLSTATIC_ACTOR_NONE);
    EXPECT_EQ(SDLStatic_ActorQuery(engine_, nullptr, 0, nullptr, 8), 0);
    SDLStatic_ActorDestroy(engine_, 12345);
    SDLStatic_ActorClear(nullptr);

    // An identity transform from nothing, rather than zeros that would
    // scale everything away.
    EXPECT_FLOAT_EQ(SDLStatic_ActorWorld(nullptr).scale_x, 1.0f);
    EXPECT_FLOAT_EQ(SDLStatic_ActorRenderTransform(nullptr, 0.5f).scale_y, 1.0f);
}

} // namespace
