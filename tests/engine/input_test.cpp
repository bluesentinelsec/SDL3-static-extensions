// Input and action bindings.
//
// SDL events are pushed synthetically, so the gamepad, touch and wheel
// paths are exercised without hardware. The cases that matter are the ones
// that only show up in a real game: an edge that has to survive several
// fixed steps in one frame, a controller that disappears mid-press, and a
// stick deadzone that must not be square.
#include <SDLStatic/engine_binding.h>
#include <SDLStatic/engine_input.h>

#include <gtest/gtest.h>

#include <string>

namespace
{

class InputHarness : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        ASSERT_TRUE(SDL_Init(SDL_INIT_EVENTS)) << SDL_GetError();
        SDLStatic_EngineConfig config{};
        config.headless = true;
        config.manual_clock = true;
        config.no_auto_mount = true;
        config.design_width = 640;
        config.design_height = 360;
        config.window_width = 640;
        config.window_height = 360;
        engine_ = SDLStatic_CreateEngine(&config);
        ASSERT_NE(engine_, nullptr) << SDL_GetError();
        map_ = SDLStatic_ActionMapCreate();
        ASSERT_NE(map_, nullptr);
    }
    void TearDown() override
    {
        SDLStatic_ActionMapDestroy(map_);
        SDLStatic_DestroyEngine(engine_);
        SDL_Quit();
    }

    void Push(const SDL_Event &event) { SDL_PushEvent(const_cast<SDL_Event *>(&event)); }

    void Key(SDL_Scancode key, bool down)
    {
        SDL_Event event{};
        event.type = down ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
        event.key.scancode = key;
        event.key.down = down;
        Push(event);
    }

    void MouseButton(Uint8 button, bool down)
    {
        SDL_Event event{};
        event.type = down ? SDL_EVENT_MOUSE_BUTTON_DOWN : SDL_EVENT_MOUSE_BUTTON_UP;
        event.button.button = button;
        event.button.down = down;
        Push(event);
    }

    void Wheel(float x, float y)
    {
        SDL_Event event{};
        event.type = SDL_EVENT_MOUSE_WHEEL;
        event.wheel.x = x;
        event.wheel.y = y;
        event.wheel.direction = SDL_MOUSEWHEEL_NORMAL;
        Push(event);
    }

    void Frame(Uint64 nanoseconds = 16666667ull)
    {
        SDLStatic_EngineAdvance(engine_, nanoseconds);
        SDLStatic_EngineTick(engine_);
    }

    SDLStatic_Engine *engine_ = nullptr;
    SDLStatic_ActionMap *map_ = nullptr;
};

// --- keyboard -------------------------------------------------------------

TEST_F(InputHarness, KeysHaveDownPressedAndReleased)
{
    Key(SDL_SCANCODE_SPACE, true);
    Frame();
    EXPECT_TRUE(SDLStatic_KeyDown(engine_, SDL_SCANCODE_SPACE));
    EXPECT_TRUE(SDLStatic_KeyPressed(engine_, SDL_SCANCODE_SPACE));
    EXPECT_FALSE(SDLStatic_KeyReleased(engine_, SDL_SCANCODE_SPACE));

    Frame();
    EXPECT_TRUE(SDLStatic_KeyDown(engine_, SDL_SCANCODE_SPACE)) << "still held";
    EXPECT_FALSE(SDLStatic_KeyPressed(engine_, SDL_SCANCODE_SPACE)) << "but no longer new";

    Key(SDL_SCANCODE_SPACE, false);
    Frame();
    EXPECT_FALSE(SDLStatic_KeyDown(engine_, SDL_SCANCODE_SPACE));
    EXPECT_TRUE(SDLStatic_KeyReleased(engine_, SDL_SCANCODE_SPACE));
}

// The bug this design exists to prevent: a frame that runs several fixed
// steps must show the same edge to every one of them, or a jump polled
// from fixed_update is silently eaten whenever the machine runs two steps.
TEST_F(InputHarness, EdgesSurviveEveryFixedStepInAFrame)
{
    static int steps_seeing_press;
    static SDLStatic_Engine *engine_ptr;
    steps_seeing_press = 0;
    engine_ptr = engine_;

    SDLStatic_GameHooks hooks{};
    hooks.fixed_update = [](void *, float) {
        if (SDLStatic_KeyPressed(engine_ptr, SDL_SCANCODE_SPACE))
        {
            steps_seeing_press++;
        }
    };
    SDLStatic_EngineSetHooks(engine_, &hooks, nullptr);

    Key(SDL_SCANCODE_SPACE, true);
    // A frame worth three simulation steps at 60 Hz.
    Frame(50000000ull);

    EXPECT_EQ(SDLStatic_EngineStepsLastFrame(engine_), 3);
    EXPECT_EQ(steps_seeing_press, 3) << "every step in the frame sees the same press";
}

TEST_F(InputHarness, TextIsSeparateFromKeys)
{
    // SDL_TextInputEvent.text is a borrowed pointer, so it has to outlive
    // the push — a literal does, and writing through it would not.
    static const char kTyped[] = "hi";
    SDL_Event event{};
    event.type = SDL_EVENT_TEXT_INPUT;
    event.text.text = kTyped;
    Push(event);
    Frame();
    EXPECT_STREQ(SDLStatic_TextTyped(engine_), "hi");

    Frame();
    EXPECT_STREQ(SDLStatic_TextTyped(engine_), "") << "cleared each frame";
}

// --- mouse ----------------------------------------------------------------

TEST_F(InputHarness, AllThreeMouseButtonsAndTheWheel)
{
    MouseButton(SDL_BUTTON_LEFT, true);
    MouseButton(SDL_BUTTON_RIGHT, true);
    MouseButton(SDL_BUTTON_MIDDLE, true);
    Wheel(0.0f, 3.0f);
    Frame();

    EXPECT_TRUE(SDLStatic_MouseDown(engine_, SDLSTATIC_MOUSE_LEFT));
    EXPECT_TRUE(SDLStatic_MouseDown(engine_, SDLSTATIC_MOUSE_RIGHT));
    EXPECT_TRUE(SDLStatic_MouseDown(engine_, SDLSTATIC_MOUSE_MIDDLE))
        << "the wheel is a button as well as a wheel";
    EXPECT_TRUE(SDLStatic_MousePressed(engine_, SDLSTATIC_MOUSE_MIDDLE));

    float x = 0.0f;
    float y = 0.0f;
    SDLStatic_MouseWheel(engine_, &x, &y);
    EXPECT_FLOAT_EQ(y, 3.0f);

    Frame();
    SDLStatic_MouseWheel(engine_, &x, &y);
    EXPECT_FLOAT_EQ(y, 0.0f) << "wheel movement is per-frame, not a running total";
}

TEST_F(InputHarness, FlippedWheelIsCorrected)
{
    SDL_Event event{};
    event.type = SDL_EVENT_MOUSE_WHEEL;
    event.wheel.y = 2.0f;
    event.wheel.direction = SDL_MOUSEWHEEL_FLIPPED;
    Push(event);
    Frame();

    float y = 0.0f;
    SDLStatic_MouseWheel(engine_, nullptr, &y);
    EXPECT_FLOAT_EQ(y, -2.0f) << "natural scrolling handled once, here";
}

// --- gamepads -------------------------------------------------------------

// No controller is plugged in during a test run, so these check the shape
// of the answer: a slot with nothing in it must read neutral rather than
// undefined, which is exactly what a disconnected controller does.
TEST_F(InputHarness, AnEmptySlotReadsNeutral)
{
    EXPECT_FALSE(SDLStatic_GamepadConnected(engine_, 0));
    EXPECT_EQ(SDLStatic_GamepadCount(engine_), 0);
    EXPECT_EQ(SDLStatic_GamepadName(engine_, 0), nullptr);
    EXPECT_FALSE(SDLStatic_GamepadButtonDown(engine_, 0, SDLSTATIC_PAD_A));
    EXPECT_FLOAT_EQ(SDLStatic_GamepadAxisValue(engine_, 0, SDLSTATIC_AXIS_LEFT_X), 0.0f);

    float x = 1.0f;
    float y = 1.0f;
    SDLStatic_GamepadStick(engine_, 0, 0, &x, &y);
    EXPECT_FLOAT_EQ(x, 0.0f) << "a player whose battery dies must stop, not keep running";
    EXPECT_FLOAT_EQ(y, 0.0f);

    // Rumbling a slot with nothing in it is harmless.
    EXPECT_FALSE(SDLStatic_GamepadRumble(engine_, 0, 1.0f, 1.0f, 100));
    EXPECT_FALSE(SDLStatic_GamepadRumbleTriggers(engine_, 0, 1.0f, 1.0f, 100));
    SDLStatic_GamepadStopRumble(engine_, -1);
}

TEST_F(InputHarness, OutOfRangePlayersAreSafe)
{
    EXPECT_FALSE(SDLStatic_GamepadConnected(engine_, -1));
    EXPECT_FALSE(SDLStatic_GamepadConnected(engine_, SDLSTATIC_MAX_PLAYERS));
    EXPECT_FALSE(SDLStatic_GamepadButtonDown(engine_, 99, SDLSTATIC_PAD_A));
    EXPECT_FLOAT_EQ(SDLStatic_GamepadAxisValue(engine_, -3, SDLSTATIC_AXIS_LEFT_Y), 0.0f);
}

TEST_F(InputHarness, DeadzoneAndThresholdAreConfigurable)
{
    SDLStatic_SetGamepadDeadzone(engine_, 0.35f);
    EXPECT_FLOAT_EQ(SDLStatic_GamepadDeadzone(engine_), 0.35f);

    // Clamped: a deadzone of 1 would mean the stick never registers.
    SDLStatic_SetGamepadDeadzone(engine_, 5.0f);
    EXPECT_LE(SDLStatic_GamepadDeadzone(engine_), 0.9f);
    SDLStatic_SetGamepadDeadzone(engine_, -1.0f);
    EXPECT_GE(SDLStatic_GamepadDeadzone(engine_), 0.0f);
}

// --- actions --------------------------------------------------------------

TEST_F(InputHarness, AnActionReadsFromAllItsBindingsAtOnce)
{
    SDLStatic_ActionBindKey(map_, "jump", SDL_SCANCODE_SPACE);
    SDLStatic_ActionBindKey(map_, "jump", SDL_SCANCODE_W);
    SDLStatic_ActionBindPad(map_, "jump", SDLSTATIC_PAD_A);

    Key(SDL_SCANCODE_W, true);
    Frame();
    EXPECT_TRUE(SDLStatic_ActionDown(engine_, map_, 0, "jump"));
    EXPECT_TRUE(SDLStatic_ActionPressed(engine_, map_, 0, "jump"));

    Key(SDL_SCANCODE_W, false);
    Frame();
    EXPECT_FALSE(SDLStatic_ActionDown(engine_, map_, 0, "jump"));
    EXPECT_TRUE(SDLStatic_ActionReleased(engine_, map_, 0, "jump"));
}

TEST_F(InputHarness, SignedBindingsMakeAnAxisOutOfTwoKeys)
{
    SDLStatic_ActionBindKeySigned(map_, "move_x", SDL_SCANCODE_A, -1);
    SDLStatic_ActionBindKeySigned(map_, "move_x", SDL_SCANCODE_D, +1);

    Key(SDL_SCANCODE_D, true);
    Frame();
    EXPECT_FLOAT_EQ(SDLStatic_ActionValue(engine_, map_, 0, "move_x"), 1.0f);

    Key(SDL_SCANCODE_A, true);
    Frame();
    EXPECT_FLOAT_EQ(SDLStatic_ActionValue(engine_, map_, 0, "move_x"), 0.0f)
        << "both directions cancel rather than fight";

    Key(SDL_SCANCODE_D, false);
    Frame();
    EXPECT_FLOAT_EQ(SDLStatic_ActionValue(engine_, map_, 0, "move_x"), -1.0f);
}

// The oldest bug in 2D games: diagonal movement 41% faster than straight.
TEST_F(InputHarness, DiagonalMovementIsNotFaster)
{
    SDLStatic_ActionBindKeySigned(map_, "move_x", SDL_SCANCODE_D, +1);
    SDLStatic_ActionBindKeySigned(map_, "move_y", SDL_SCANCODE_S, +1);

    Key(SDL_SCANCODE_D, true);
    Key(SDL_SCANCODE_S, true);
    Frame();

    float x = 0.0f;
    float y = 0.0f;
    SDLStatic_ActionVector(engine_, map_, 0, "move_x", "move_y", &x, &y);
    EXPECT_NEAR(SDL_sqrtf(x * x + y * y), 1.0f, 0.001f);
    EXPECT_NEAR(x, y, 0.001f);
}

// Actions are per-player, and there is only one keyboard.
TEST_F(InputHarness, TheKeyboardBelongsToOnePlayer)
{
    SDLStatic_ActionBindKey(map_, "fire", SDL_SCANCODE_SPACE);
    Key(SDL_SCANCODE_SPACE, true);
    Frame();

    EXPECT_TRUE(SDLStatic_ActionDown(engine_, map_, 0, "fire"));
    EXPECT_FALSE(SDLStatic_ActionDown(engine_, map_, 1, "fire")) << "player 2 has a gamepad";

    SDLStatic_ActionMapSetKeyboardPlayer(map_, 1);
    EXPECT_FALSE(SDLStatic_ActionDown(engine_, map_, 0, "fire"));
    EXPECT_TRUE(SDLStatic_ActionDown(engine_, map_, 1, "fire"));

    SDLStatic_ActionMapSetKeyboardPlayer(map_, -1);
    EXPECT_FALSE(SDLStatic_ActionDown(engine_, map_, 0, "fire")) << "gamepad-only game";
}

TEST_F(InputHarness, UnknownActionsAreQuiet)
{
    EXPECT_FLOAT_EQ(SDLStatic_ActionValue(engine_, map_, 0, "nonexistent"), 0.0f);
    EXPECT_FALSE(SDLStatic_ActionDown(engine_, map_, 0, "nonexistent"));
    EXPECT_FALSE(SDLStatic_ActionPressed(engine_, map_, 0, nullptr));
}

TEST_F(InputHarness, RebindingReplacesTheOldBinding)
{
    SDLStatic_ActionBindKey(map_, "jump", SDL_SCANCODE_SPACE);
    ASSERT_EQ(SDLStatic_ActionBindingCount(map_, "jump"), 1);

    SDLStatic_ActionClear(map_, "jump");
    SDLStatic_ActionBindKey(map_, "jump", SDL_SCANCODE_J);
    EXPECT_EQ(SDLStatic_ActionBindingCount(map_, "jump"), 1);

    Key(SDL_SCANCODE_SPACE, true);
    Frame();
    EXPECT_FALSE(SDLStatic_ActionDown(engine_, map_, 0, "jump")) << "the old key is dead";

    Key(SDL_SCANCODE_J, true);
    Frame();
    EXPECT_TRUE(SDLStatic_ActionDown(engine_, map_, 0, "jump"));
}

TEST_F(InputHarness, CaptureReadsWhateverThePlayerPresses)
{
    SDLStatic_Binding binding{};
    Frame();
    EXPECT_FALSE(SDLStatic_ActionCapture(engine_, -1, &binding)) << "nothing pressed yet";

    Key(SDL_SCANCODE_K, true);
    Frame();
    ASSERT_TRUE(SDLStatic_ActionCapture(engine_, -1, &binding));
    EXPECT_EQ(binding.source, SDLSTATIC_BIND_KEY);
    EXPECT_EQ(binding.code, SDL_SCANCODE_K);

    // And it can be bound straight back in.
    SDLStatic_ActionClear(map_, "crouch");
    EXPECT_TRUE(SDLStatic_ActionBind(map_, "crouch", binding));
    EXPECT_TRUE(SDLStatic_ActionDown(engine_, map_, 0, "crouch"));
}

// --- binding text and persistence ----------------------------------------

TEST_F(InputHarness, BindingsRoundTripThroughText)
{
    const SDLStatic_Binding cases[] = {
        {SDLSTATIC_BIND_KEY, SDL_SCANCODE_SPACE, 1, 0},
        {SDLSTATIC_BIND_KEY, SDL_SCANCODE_A, -1, 0},
        {SDLSTATIC_BIND_PAD_BUTTON, SDLSTATIC_PAD_A, 1, 0},
        {SDLSTATIC_BIND_PAD_BUTTON, SDLSTATIC_PAD_RIGHT_TRIGGER, 1, 0},
        {SDLSTATIC_BIND_PAD_AXIS, SDLSTATIC_AXIS_LEFT_X, 1, 0},
        {SDLSTATIC_BIND_PAD_AXIS, SDLSTATIC_AXIS_RIGHT_Y, 1, -1},
        {SDLSTATIC_BIND_MOUSE_BUTTON, SDLSTATIC_MOUSE_MIDDLE, 1, 0},
        {SDLSTATIC_BIND_PAD_DIRECTION, SDLSTATIC_DIR_UP, 1, 0},
    };

    for (const SDLStatic_Binding &original : cases)
    {
        char text[64];
        SDLStatic_BindingToString(original, text, sizeof(text));
        SDLStatic_Binding parsed{};
        ASSERT_TRUE(SDLStatic_BindingFromString(text, &parsed)) << text;
        EXPECT_EQ(parsed.source, original.source) << text;
        EXPECT_EQ(parsed.code, original.code) << text;
        EXPECT_EQ(parsed.sign, original.sign) << text;
        EXPECT_EQ(parsed.axis_half, original.axis_half) << text;
    }

    SDLStatic_Binding rubbish{};
    EXPECT_FALSE(SDLStatic_BindingFromString("pad:nonsense", &rubbish));
    EXPECT_FALSE(SDLStatic_BindingFromString("", &rubbish));
}

TEST_F(InputHarness, AMapRoundTripsThroughToml)
{
    SDLStatic_ActionBindKey(map_, "jump", SDL_SCANCODE_SPACE);
    SDLStatic_ActionBindPad(map_, "jump", SDLSTATIC_PAD_A);
    SDLStatic_ActionBindKeySigned(map_, "move_x", SDL_SCANCODE_A, -1);
    SDLStatic_ActionBindKeySigned(map_, "move_x", SDL_SCANCODE_D, +1);
    SDLStatic_ActionBindAxis(map_, "move_x", SDLSTATIC_AXIS_LEFT_X, 0);

    char *toml = SDLStatic_ActionMapToToml(map_);
    ASSERT_NE(toml, nullptr);

    SDLStatic_ActionMap *restored = SDLStatic_ActionMapCreate();
    ASSERT_TRUE(SDLStatic_ActionMapLoadToml(restored, toml)) << toml;
    SDL_free(toml);

    EXPECT_EQ(SDLStatic_ActionBindingCount(restored, "jump"), 2);
    EXPECT_EQ(SDLStatic_ActionBindingCount(restored, "move_x"), 3);

    SDLStatic_Binding binding{};
    ASSERT_TRUE(SDLStatic_ActionBindingAt(restored, "move_x", 0, &binding));
    EXPECT_EQ(binding.sign, -1) << "the sign survives, or A and D swap";
    SDLStatic_ActionMapDestroy(restored);
}

// A player who rebound one key must not lose everything else when the game
// adds a new action in a later version.
TEST_F(InputHarness, LoadingReplacesOnlyTheActionsMentioned)
{
    SDLStatic_ActionBindKey(map_, "jump", SDL_SCANCODE_SPACE);
    SDLStatic_ActionBindKey(map_, "reload", SDL_SCANCODE_R); // added in v2

    ASSERT_TRUE(SDLStatic_ActionMapLoadToml(map_, "[bindings]\njump = [\"j\"]\n"));

    ASSERT_EQ(SDLStatic_ActionBindingCount(map_, "jump"), 1);
    SDLStatic_Binding binding{};
    ASSERT_TRUE(SDLStatic_ActionBindingAt(map_, "jump", 0, &binding));
    EXPECT_EQ(binding.code, SDL_SCANCODE_J) << "rebound";
    EXPECT_EQ(SDLStatic_ActionBindingCount(map_, "reload"), 1)
        << "an action the file never heard of keeps its default";
}

TEST_F(InputHarness, MalformedBindingsFileIsNotFatal)
{
    SDLStatic_ActionBindKey(map_, "jump", SDL_SCANCODE_SPACE);
    EXPECT_FALSE(SDLStatic_ActionMapLoadToml(map_, "[bindings\njump = "));
    EXPECT_EQ(SDLStatic_ActionBindingCount(map_, "jump"), 1) << "defaults survive";

    // Unparseable individual bindings are skipped, not fatal.
    EXPECT_TRUE(SDLStatic_ActionMapLoadToml(
        map_, "[bindings]\njump = [\"space\", \"gibberish:zzz\"]\n"));
    EXPECT_EQ(SDLStatic_ActionBindingCount(map_, "jump"), 1);
}

TEST_F(InputHarness, MapsSaveAndLoadFromThePrefDirectory)
{
    SDLStatic_ActionBindKey(map_, "jump", SDL_SCANCODE_K);
    ASSERT_TRUE(SDLStatic_ActionMapSave(map_, "SDLStaticTest", "BindingsTest"))
        << SDL_GetError();

    SDLStatic_ActionMap *loaded = SDLStatic_ActionMapCreate();
    ASSERT_TRUE(SDLStatic_ActionMapLoad(loaded, "SDLStaticTest", "BindingsTest"));
    ASSERT_EQ(SDLStatic_ActionBindingCount(loaded, "jump"), 1);
    SDLStatic_Binding binding{};
    ASSERT_TRUE(SDLStatic_ActionBindingAt(loaded, "jump", 0, &binding));
    EXPECT_EQ(binding.code, SDL_SCANCODE_K);
    SDLStatic_ActionMapDestroy(loaded);

    // Loading when nothing was ever saved is not an error.
    SDLStatic_ActionMap *empty = SDLStatic_ActionMapCreate();
    EXPECT_FALSE(SDLStatic_ActionMapLoad(empty, "SDLStaticTest", "NeverSavedAnything"));
    SDLStatic_ActionMapDestroy(empty);
}

TEST_F(InputHarness, ABindingLimitIsEnforcedRatherThanOverrunning)
{
    for (int i = 0; i < 32; ++i)
    {
        SDLStatic_ActionBindKey(map_, "spam", SDL_SCANCODE_A);
    }
    EXPECT_LE(SDLStatic_ActionBindingCount(map_, "spam"), 8);
}

// --- idle and device tracking --------------------------------------------

TEST_F(InputHarness, IdleTimeAndLastDeviceTrackWhatThePlayerUsed)
{
    Frame();
    Frame();
    EXPECT_GT(SDLStatic_IdleSeconds(engine_), 0.0f);
    EXPECT_EQ(SDLStatic_LastInputDevice(engine_), SDLSTATIC_DEVICE_NONE);

    Key(SDL_SCANCODE_SPACE, true);
    Frame();
    EXPECT_TRUE(SDLStatic_AnyInput(engine_));
    EXPECT_FLOAT_EQ(SDLStatic_IdleSeconds(engine_), 0.0f);
    EXPECT_EQ(SDLStatic_LastInputDevice(engine_), SDLSTATIC_DEVICE_KEYBOARD);

    MouseButton(SDL_BUTTON_LEFT, true);
    Frame();
    EXPECT_EQ(SDLStatic_LastInputDevice(engine_), SDLSTATIC_DEVICE_MOUSE)
        << "so a game can switch its prompts without being asked";
}

TEST_F(InputHarness, NullsAreHandled)
{
    EXPECT_FALSE(SDLStatic_KeyDown(nullptr, SDL_SCANCODE_A));
    EXPECT_FALSE(SDLStatic_GamepadConnected(nullptr, 0));
    EXPECT_EQ(SDLStatic_FingerCount(nullptr), 0);
    EXPECT_EQ(SDLStatic_GetFinger(nullptr, 0), nullptr);
    EXPECT_FLOAT_EQ(SDLStatic_TouchPinch(nullptr), 1.0f);
    EXPECT_EQ(SDLStatic_LastInputDevice(nullptr), SDLSTATIC_DEVICE_NONE);

    SDLStatic_ActionMapDestroy(nullptr);
    EXPECT_EQ(SDLStatic_ActionCount(nullptr), 0);
    EXPECT_EQ(SDLStatic_ActionName(nullptr, 0), nullptr);
    EXPECT_FALSE(SDLStatic_ActionBindKey(nullptr, "x", SDL_SCANCODE_A));
    EXPECT_EQ(SDLStatic_ActionMapToToml(nullptr), nullptr);
    EXPECT_FALSE(SDLStatic_ActionCapture(nullptr, -1, nullptr));
}

} // namespace
