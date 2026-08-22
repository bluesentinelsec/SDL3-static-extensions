/**
 * @file android_test.cpp
 * @brief End-to-end Android tests consuming the SDL3-static-extensions Prefab package.
 */

#include <SDL3_static_extensions/version.hpp>

#include <SDLStatic/engine.h>
#include <SDLStatic/engine_actor.h>
#include <SDLStatic/engine_config.h>
#include <SDLStatic/bindings.h>
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

    // The engine's surface, called rather than merely linked. Checking the
    // version string alone is how this test passed for months against an
    // AAR that contained nothing else.
    //
    // What it deliberately does not do is create an engine. SDL's Android
    // backend expects to be driven by org.libsdl.app.SDLActivity — it owns
    // the surface, the looper and the main thread — and this harness is a
    // plain Activity calling in over JNI, where SDLStatic_CreateEngine
    // blocks waiting for plumbing that is not there. A game shipping this
    // AAR would subclass SDLActivity and be fine; proving that needs an
    // SDLActivity-based harness, which is its own piece of work.
    SDLStatic_EngineConfig *config = SDLStatic_ConfigCreate();
    run.Check(config != nullptr, "the engine's builders are in the package");
    if (config != nullptr)
    {
        SDLStatic_ConfigSetHeadless(config, true);
        SDLStatic_ConfigSetDesignSize(config, 640, 360);
        SDLStatic_ConfigSetTitle(config, "android");
        SDLStatic_ConfigDestroy(config);
    }

    SDLStatic_ActorDef *def = SDLStatic_ActorDefCreate();
    run.Check(def != nullptr, "actor definitions can be built");
    if (def != nullptr)
    {
        SDLStatic_ActorDefSetType(def, "android");
        SDLStatic_ActorDefDestroy(def);
    }

    // The script surface: Lua and its bindings are a large part of what the
    // package is for, and the largest part of what a link error would drop.
    // None of it needs a window.
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
