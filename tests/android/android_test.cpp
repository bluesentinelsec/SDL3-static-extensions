/**
 * @file android_test.cpp
 * @brief End-to-end Android tests consuming the SDL3-static-extensions Prefab package.
 */

#include <SDL3_static_extensions/version.hpp>
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
    return run.failures();
}

} // namespace

extern "C" JNIEXPORT jint JNICALL
Java_com_example_sdl3staticextensions_test_TestActivity_runNativeTests(JNIEnv *, jclass)
{
    return RunTests();
}
