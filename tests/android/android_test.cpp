/**
 * @file android_test.cpp
 * @brief End-to-end Android tests consuming the SDL3-static-extensions Prefab package.
 */

#include <SDL3_static_extensions/version.hpp>

#include <SDLStatic/engine.h>
#include <SDLStatic/engine_actor.h>
#include <SDLStatic/engine_config.h>
#include <SDLStatic/lua.h>

#include <SDL3/SDL.h>

#include <android/log.h>
#include <jni.h>
#include <string>
#include <string_view>

namespace
{

constexpr const char *kLogTag = "SDL3-static-extensions-android-test";

class TestRun
{
  public:
    void Check(bool condition, std::string_view message)
    {
        if (condition)
        {
            __android_log_print(ANDROID_LOG_INFO, kLogTag, "PASS: %.*s",
                                static_cast<int>(message.size()), message.data());
            return;
        }
        ++failures_;
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "FAIL: %.*s",
                            static_cast<int>(message.size()), message.data());
    }

    [[nodiscard]] int failures() const noexcept
    {
        return failures_;
    }

  private:
    int failures_ = 0;
};

int RunTests()
{
    TestRun run;
    const std::string_view version = SDL3_static_extensions::Version();
    run.Check(!version.empty(), "Prefab package exports the generated version API");
    const std::string major_prefix = std::to_string(SDL3_static_extensions::kVersionMajor) + ".";
    run.Check(version.substr(0, major_prefix.size()) == major_prefix,
              "Version() matches the compiled major version");
    run.Check(SDL3_static_extensions::kVersionMajor >= 0, "major version is non-negative");

    // The engine, not just the version string. Checking only the latter is
    // how this test passed for months against an AAR that contained nothing
    // else: the package was verified for ABIs, slices and version, and every
    // one of those checks was true of an empty library.
    SDLStatic_EngineConfig *config = SDLStatic_ConfigCreate();
    run.Check(config != nullptr, "the engine's builders are in the package");
    if (config != nullptr)
    {
        // Headless with a manual clock: an instrumentation test has no window
        // and must not wait on a real one.
        SDLStatic_ConfigSetHeadless(config, true);
        SDLStatic_ConfigSetManualClock(config, true);
        SDLStatic_ConfigSetAutoMount(config, false);

        SDLStatic_Engine *engine = SDLStatic_CreateEngine(config);
        SDLStatic_ConfigDestroy(config);
        run.Check(engine != nullptr, "an engine can be created on Android");
        if (engine != nullptr)
        {
            SDLStatic_ActorDef *def = SDLStatic_ActorDefCreate();
            SDLStatic_ActorDefSetType(def, "android");
            const SDLStatic_ActorId actor = SDLStatic_ActorSpawn(engine, def);
            SDLStatic_ActorDefDestroy(def);
            run.Check(actor != SDLSTATIC_ACTOR_NONE, "an actor can be spawned");

            for (int i = 0; i < 5; ++i)
            {
                SDLStatic_EngineAdvance(engine, 16666667);
                SDLStatic_EngineTick(engine);
            }
            run.Check(SDLStatic_EngineFrameCount(engine) >= 5, "the loop runs frames");
            run.Check(SDLStatic_ActorCount(engine) == 1, "the actor survived the frames");
            SDLStatic_DestroyEngine(engine);
        }
    }

    // The script surface: Lua and its bindings are a large part of what the
    // package is for, and the largest part of what a link error would drop.
    lua_State *lua = SDLStatic_CreateLuaState();
    run.Check(lua != nullptr, "a Lua state can be created");
    if (lua != nullptr)
    {
        run.Check(SDLStatic_OpenLuaBindings(lua), "the generated bindings load");
        lua_close(lua);
    }

    run.Check(SDL_GetPlatform() != nullptr, "SDL3 itself is in the package");
    return run.failures();
}

} // namespace

extern "C" JNIEXPORT jint JNICALL
Java_com_example_sdl3staticextensions_test_TestActivity_runNativeTests(JNIEnv *, jclass)
{
    return RunTests();
}
