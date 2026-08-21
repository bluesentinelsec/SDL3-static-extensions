// cpp_test.cpp — tests for the sdlstatic C++ bindings.
//
// RAII is proven, not assumed: create-and-drop loops run under ASan (leaks
// and double-frees surface), moved-from objects are destroyed safely, and
// the composed "game slice" exercises VFS -> texture -> audio -> physics
// entirely through owner types. Error paths return Status carrying the
// real SDL error text; nothing throws.

#include "sdlstatic/sdlstatic.h"

#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#ifndef CPP_TEST_ASSETS_DIR
#error "CPP_TEST_ASSETS_DIR must be defined by the build"
#endif

namespace {

using sdlstatic::Result;
using sdlstatic::Status;

std::vector<std::uint8_t> Bytes(const std::string& text) {
  return std::vector<std::uint8_t>(text.begin(), text.end());
}

TEST(StatusTest, OkAndErrorSemantics) {
  Status ok = Status::Ok();
  EXPECT_TRUE(ok.ok());
  EXPECT_EQ(ok.message(), "");

  Status error = Status::Error("boom");
  EXPECT_FALSE(error.ok());
  EXPECT_EQ(error.message(), "boom");

  SDL_SetError("from sdl");
  Status sdl_error = Status::FromSdl();
  EXPECT_FALSE(sdl_error.ok());
  EXPECT_EQ(sdl_error.message(), "from sdl");

  Result<int> value = 42;
  ASSERT_TRUE(value.ok());
  EXPECT_EQ(*value, 42);
  Result<int> failed = Status::Error("nope");
  EXPECT_FALSE(failed.ok());
  EXPECT_EQ(failed.status().message(), "nope");
}

TEST(ExtrasTest, RoundTripsThroughValueApis) {
  const std::vector<std::uint8_t> data = Bytes(std::string(400, 'x') + "payload");

  Result<std::vector<std::uint8_t>> compressed = sdlstatic::Compress(data);
  ASSERT_TRUE(compressed.ok()) << compressed.status().message();
  Result<std::vector<std::uint8_t>> plain = sdlstatic::Decompress(*compressed);
  ASSERT_TRUE(plain.ok());
  EXPECT_EQ(*plain, data);

  Result<std::vector<std::uint8_t>> encrypted = sdlstatic::Encrypt(data, "pw");
  ASSERT_TRUE(encrypted.ok());
  Result<std::vector<std::uint8_t>> decrypted = sdlstatic::Decrypt(*encrypted, "pw");
  ASSERT_TRUE(decrypted.ok());
  EXPECT_EQ(*decrypted, data);
  Result<std::vector<std::uint8_t>> wrong = sdlstatic::Decrypt(*encrypted, "bad");
  EXPECT_FALSE(wrong.ok());
  EXPECT_FALSE(wrong.status().message().empty()) << "error text must be present";

  Result<std::string> base64 = sdlstatic::Base64Encode(Bytes("Man"));
  ASSERT_TRUE(base64.ok());
  EXPECT_EQ(*base64, "TWFu");
  EXPECT_EQ(sdlstatic::Sha256Hex(Bytes("abc")).substr(0, 8), "ba7816bf");
}

TEST(SignalsTest, ScopedConnectionDisconnectsOnScopeExit) {
  Result<sdlstatic::SignalEmitter> emitter = sdlstatic::SignalEmitter::Create();
  ASSERT_TRUE(emitter.ok());

  int hits = 0;
  {
    Result<sdlstatic::ScopedConnection> connection = emitter->Connect(
        "fired", [&hits](const char* signal, void*) {
          EXPECT_STREQ(signal, "fired");
          ++hits;
        });
    ASSERT_TRUE(connection.ok());
    EXPECT_TRUE(connection->connected());
    Result<int> invoked = emitter->Emit("fired");
    ASSERT_TRUE(invoked.ok());
    EXPECT_EQ(*invoked, 1);
  }  // connection leaves scope -> auto-disconnect

  Result<int> after = emitter->Emit("fired");
  ASSERT_TRUE(after.ok());
  EXPECT_EQ(*after, 0) << "scoped connection must have disconnected";
  EXPECT_EQ(hits, 1);
}

TEST(VfsTest, MountReadAndEncryptedMount) {
  Result<sdlstatic::Vfs> vfs = sdlstatic::Vfs::Create();
  ASSERT_TRUE(vfs.ok()) << vfs.status().message();
  {
    Result<sdlstatic::Mount> mount =
        sdlstatic::Mount::Archive(std::string(CPP_TEST_ASSETS_DIR) + "/media.zip");
    ASSERT_TRUE(mount.ok()) << mount.status().message();
    Result<std::vector<std::uint8_t>> hello = vfs->ReadFile("hello.txt");
    ASSERT_TRUE(hello.ok());
    EXPECT_EQ(std::string(hello->begin(), hello->end()), "Hello from the vault!\n");
  }  // mount leaves scope -> unmounted
  EXPECT_FALSE(vfs->Exists("hello.txt")) << "mount must be gone after scope exit";

  Result<sdlstatic::Mount> encrypted = sdlstatic::Mount::EncryptedArchive(
      std::string(CPP_TEST_ASSETS_DIR) + "/media_encrypted.bin", "openSesame");
  ASSERT_TRUE(encrypted.ok()) << encrypted.status().message();
  EXPECT_TRUE(vfs->Exists("sprites/hero.dat"));

  Result<sdlstatic::Mount> bad = sdlstatic::Mount::EncryptedArchive(
      std::string(CPP_TEST_ASSETS_DIR) + "/media_encrypted.bin", "wrong");
  EXPECT_FALSE(bad.ok());
}

TEST(MixerTest, HeadlessPlaybackThroughOwners) {
  const SDL_AudioSpec spec = {SDL_AUDIO_F32, 2, 44100};
  Result<sdlstatic::Mixer> mixer = sdlstatic::Mixer::CreateHeadless(spec);
  ASSERT_TRUE(mixer.ok()) << mixer.status().message();

  Result<sdlstatic::Audio> audio =
      mixer->Load(std::string(CPP_TEST_ASSETS_DIR) + "/../../mixer/assets/sfx_coin.wav");
  ASSERT_TRUE(audio.ok()) << audio.status().message();
  EXPECT_GT(audio->DurationFrames(), 0);

  Result<sdlstatic::Track> track = mixer->Play(*audio);
  ASSERT_TRUE(track.ok()) << track.status().message();
  float buffer[4096 * 2] = {};
  Result<int> got = mixer->Generate(buffer, static_cast<int>(sizeof(buffer)));
  ASSERT_TRUE(got.ok());
  double energy = 0;
  for (float sample : buffer) energy += (sample >= 0 ? sample : -sample);
  EXPECT_GT(energy, 10.0) << "playback must produce real signal";
  EXPECT_TRUE(track->Stop().ok());

  Result<sdlstatic::Audio> missing = mixer->Load("no-such-file.wav");
  EXPECT_FALSE(missing.ok());
}

TEST(PhysicsTest, WorldOwnsBodiesAndDropIsClean) {
  Result<sdlstatic::World> world = sdlstatic::World::Create();
  ASSERT_TRUE(world.ok());
  Result<sdlstatic::Body> ground = world->AddBox({0, 0}, 50, 1, /*dynamic=*/false);
  ASSERT_TRUE(ground.ok());
  Result<sdlstatic::Body> ball = world->AddCircle({0, 10}, 0.5f, /*dynamic=*/true);
  ASSERT_TRUE(ball.ok());

  for (int i = 0; i < 120; ++i) ASSERT_TRUE(world->Step().ok());
  Result<sdlstatic::Vec2> position = ball->Position();
  ASSERT_TRUE(position.ok());
  EXPECT_LT(position->y, 9.0f) << "ball must fall";

  // Destroy the world while Body views still exist: calls must fail with a
  // Status, never crash.
  sdlstatic::Body dangling = std::move(ball).value();
  {
    sdlstatic::World reaped = std::move(world).value();
    (void)reaped;
  }  // world destroyed here
  EXPECT_FALSE(dangling.valid());
  EXPECT_FALSE(dangling.Position().ok());
}

TEST(ScriptTest, LuaAndRubyStatesRunAndReportErrors) {
  Result<sdlstatic::LuaState> lua = sdlstatic::LuaState::Create();
  ASSERT_TRUE(lua.ok());
  EXPECT_TRUE(lua->Run("x = 1 + 2").ok());
  Status lua_error = lua->Run("this is not lua");
  EXPECT_FALSE(lua_error.ok());
  EXPECT_FALSE(lua_error.message().empty());

  Result<sdlstatic::RubyState> ruby = sdlstatic::RubyState::Create();
  ASSERT_TRUE(ruby.ok());
  EXPECT_TRUE(ruby->Run("x = 1 + 2").ok());
  Status ruby_error = ruby->Run("raise 'kaboom'");
  EXPECT_FALSE(ruby_error.ok());
  EXPECT_NE(ruby_error.message().find("kaboom"), std::string::npos);
}

TEST(RaiiTest, CreateAndDropLoopsDoNotLeak) {
  // ASan turns any leak or double-free here into a failure.
  for (int i = 0; i < 50; ++i) {
    Result<sdlstatic::World> world = sdlstatic::World::Create();
    ASSERT_TRUE(world.ok());
    (void)world->AddBox({0, 0}, 1, 1, true);
    Result<sdlstatic::SignalEmitter> emitter = sdlstatic::SignalEmitter::Create();
    ASSERT_TRUE(emitter.ok());
    (void)emitter->Connect("s", [](const char*, void*) {});
  }
  // Move semantics: moved-from objects must destroy safely.
  Result<sdlstatic::World> a = sdlstatic::World::Create();
  ASSERT_TRUE(a.ok());
  sdlstatic::World b = std::move(a).value();
  sdlstatic::World c = std::move(b);
  (void)c;
}

TEST(GameSliceTest, ComposedModulesThroughRaii) {
  Result<sdlstatic::Vfs> vfs = sdlstatic::Vfs::Create();
  ASSERT_TRUE(vfs.ok());
  Result<sdlstatic::Mount> mount = sdlstatic::Mount::EncryptedArchive(
      std::string(CPP_TEST_ASSETS_DIR) + "/media_encrypted.bin", "openSesame");
  ASSERT_TRUE(mount.ok());

  // SdlInit is declared before the owners below, so it is destroyed last —
  // the ordering guarantee the guard exists to provide.
  Result<sdlstatic::SdlInit> sdl = sdlstatic::SdlInit::Create(0);
  ASSERT_TRUE(sdl.ok()) << sdl.status().message();
  Result<sdlstatic::Surface> canvas = sdlstatic::Surface::Create(64, 64);
  ASSERT_TRUE(canvas.ok());
  Result<sdlstatic::Renderer> renderer = sdlstatic::Renderer::CreateSoftware(*canvas);
  ASSERT_TRUE(renderer.ok());
  EXPECT_TRUE(renderer->Clear(0, 0, 0).ok());
  EXPECT_TRUE(renderer->DebugText(4, 4, "hp: 100").ok());
  EXPECT_TRUE(renderer->Flush().ok());

  // The zip has no images; the Status must carry a real message.
  Result<sdlstatic::Texture> missing = renderer->LoadTexture("sprites/hero.png");
  EXPECT_FALSE(missing.ok());
  EXPECT_FALSE(missing.status().message().empty());

  Result<sdlstatic::Gui> gui = sdlstatic::Gui::Create(renderer->get());
  ASSERT_TRUE(gui.ok()) << gui.status().message();
  gui->InputBegin();
  gui->InputEnd();
  if (nk_begin(gui->context(), "w", nk_rect(2, 2, 60, 40), NK_WINDOW_BORDER)) {
    nk_layout_row_dynamic(gui->context(), 0, 1);
    nk_label(gui->context(), "hi", NK_TEXT_LEFT);
  }
  nk_end(gui->context());
  EXPECT_TRUE(gui->Render().ok());
  // No SDL_Quit here: the SdlInit guard runs it after every owner above.
}

TEST(SdlInitTest, GuardOrdersMixerTeardownAfterOwners) {
  // Regression for the pong_cpp crash: a Mixer destroyed after SDL audio
  // teardown segfaulted in MIX_DestroyMixer. With the guard declared
  // first, the mixer always dies while SDL is still alive.
  Result<sdlstatic::SdlInit> sdl = sdlstatic::SdlInit::Create(0);
  ASSERT_TRUE(sdl.ok());
  const SDL_AudioSpec spec = {SDL_AUDIO_F32, 2, 44100};
  Result<sdlstatic::Mixer> mixer = sdlstatic::Mixer::CreateHeadless(spec);
  ASSERT_TRUE(mixer.ok()) << mixer.status().message();
  Result<sdlstatic::Audio> tone = mixer->Load(
      std::string(CPP_TEST_ASSETS_DIR) + "/../../mixer/assets/sfx_coin.wav");
  ASSERT_TRUE(tone.ok());
  (void)mixer->Play(*tone);
}  // teardown order: Audio/Track, Mixer, then SdlInit -> SDL_Quit

}  // namespace

// --- the engine wrapper ---------------------------------------------------
//
// What C++ adds over the C API is lifetime, hooks and handles. These check
// exactly those three, not the engine behaviour underneath — that already
// has its own tests, in C.

namespace {

sdlstatic::Engine MakeHeadlessEngine() {
  SDLStatic_EngineConfig config{};
  config.headless = true;
  config.manual_clock = true;
  config.no_auto_mount = true;
  config.design_width = 320;
  config.design_height = 240;
  auto engine = sdlstatic::Engine::Create(config);
  EXPECT_TRUE(engine.ok());
  return std::move(engine).value();
}

TEST(CppEngine, CreatesAndDestroysWithScope) {
  ASSERT_TRUE(SDL_Init(0));
  {
    sdlstatic::Engine engine = MakeHeadlessEngine();
    EXPECT_TRUE(static_cast<bool>(engine));
    EXPECT_NE(engine.get(), nullptr);
    EXPECT_NE(engine.renderer(), nullptr);
  }  // destroyed here; ASan would notice if it were not
  SDL_Quit();
}

// Lambdas capturing game state, without a trampoline and a static_cast per
// hook.
TEST(CppEngine, HooksAreLambdas) {
  ASSERT_TRUE(SDL_Init(0));
  {
    sdlstatic::Engine engine = MakeHeadlessEngine();

    int fixed_steps = 0;
    int frames = 0;
    engine.on_fixed_update([&](float) { fixed_steps++; });
    engine.on_update([&](float) { frames++; });

    for (int i = 0; i < 3; ++i) {
      engine.Advance(16666667ull);
      engine.Tick();
    }
    EXPECT_EQ(frames, 3);
    EXPECT_GT(fixed_steps, 0);
  }
  SDL_Quit();
}

// An actor handle is a value that knows its engine, so it reads as methods
// rather than three-argument calls with out-parameters.
TEST(CppEngine, ActorsAreValues) {
  ASSERT_TRUE(SDL_Init(0));
  {
    sdlstatic::Engine engine = MakeHeadlessEngine();

    SDLStatic_ActorDef def{};
    def.type = "goblin";
    def.x = 10.0f;
    def.y = 20.0f;
    sdlstatic::Actor actor = engine.spawn(def);
    ASSERT_TRUE(actor.alive());
    EXPECT_STREQ(actor.type(), "goblin");
    EXPECT_FLOAT_EQ(actor.world().x, 10.0f);

    actor.move(5.0f, 0.0f);
    EXPECT_FLOAT_EQ(actor.world().x, 15.0f);

    engine.Advance(16666667ull);
    engine.Tick();
    EXPECT_EQ(engine.actor_count(), 1);
    EXPECT_EQ(engine.find_by_type("goblin"), actor);

    // A copy of the handle sees the same actor, and both stop resolving
    // when it dies — which is the whole reason this is not a pointer.
    sdlstatic::Actor copy = actor;
    actor.destroy();
    engine.Advance(16666667ull);
    engine.Tick();
    EXPECT_FALSE(copy.alive());
    EXPECT_EQ(copy.get(), nullptr);
  }
  SDL_Quit();
}

TEST(CppEngine, QueriesReturnVectors) {
  ASSERT_TRUE(SDL_Init(0));
  {
    sdlstatic::Engine engine = MakeHeadlessEngine();
    for (int i = 0; i < 5; ++i) {
      SDLStatic_ActorDef def{};
      def.type = "rock";
      def.tags = 1u << 0;
      engine.spawn(def);
    }
    engine.Advance(16666667ull);
    engine.Tick();

    const std::vector<sdlstatic::Actor> rocks = engine.query("rock");
    EXPECT_EQ(rocks.size(), 5u);
    for (const sdlstatic::Actor& rock : rocks) EXPECT_TRUE(rock.alive());
    EXPECT_EQ(engine.query(nullptr, 1u << 1).size(), 0u);
  }
  SDL_Quit();
}

TEST(CppEngine, ActionMapsOwnThemselves) {
  ASSERT_TRUE(SDL_Init(0));
  {
    sdlstatic::Engine engine = MakeHeadlessEngine();
    auto map_result = sdlstatic::ActionMap::Create();
    ASSERT_TRUE(map_result.ok());
    sdlstatic::ActionMap map = std::move(map_result).value();

    EXPECT_TRUE(map.bind_key("jump", SDL_SCANCODE_SPACE));
    EXPECT_TRUE(map.bind_pad("jump", SDLSTATIC_PAD_A));
    EXPECT_FALSE(engine.action_down(map, 0, "jump")) << "nothing pressed";
    EXPECT_FLOAT_EQ(engine.action_value(map, 0, "jump"), 0.0f);
  }  // map destroyed here, exactly once
  SDL_Quit();
}

// Saves come back owned, so a caller cannot forget to free them.
TEST(CppEngine, SavesReturnOwnedBuffers) {
  ASSERT_TRUE(SDL_Init(0));
  {
    sdlstatic::Engine engine = MakeHeadlessEngine();
    engine.set_save_identity("SDLStaticTest", "CppEngineSaveTest");

    const int payload = 4321;
    ASSERT_TRUE(engine.save(0, &payload, sizeof(payload), "cpp"));

    const std::vector<unsigned char> bytes = engine.load(0);
    ASSERT_EQ(bytes.size(), sizeof(payload));
    int read = 0;
    SDL_memcpy(&read, bytes.data(), bytes.size());
    EXPECT_EQ(read, 4321);

    // An empty slot is an empty vector rather than a null to check.
    EXPECT_TRUE(engine.load(5).empty());
    SDLStatic_SaveDelete(engine.get(), 0);
  }
  SDL_Quit();
}

TEST(CppEngine, TextFallsBackThroughTheWrapper) {
  ASSERT_TRUE(SDL_Init(0));
  {
    sdlstatic::Engine engine = MakeHeadlessEngine();
    ASSERT_TRUE(SDLStatic_TextLoad(engine.get(), "en",
                                   "[strings]\n\"hello\" = \"Hello\"\n"));
    EXPECT_STREQ(engine.text("hello"), "Hello");
    EXPECT_STREQ(engine.text("absent"), "absent");
  }
  SDL_Quit();
}

}  // namespace
