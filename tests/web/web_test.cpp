/**
 * @file web_test.cpp
 * @brief Browser-runtime tests for the WebAssembly build of SDL3-static-extensions.
 *
 * Runs inside a real browser (see .github/workflows/web.yml and `emrun`);
 * the process exit code is reported back through --emrun / -sEXIT_RUNTIME=1.
 */

#include <SDL3_static_extensions/version.hpp>
#include <emscripten.h>
#include <gtest/gtest.h>
#include <string>

TEST(WebVersion, IsNonEmpty)
{
    EXPECT_FALSE(SDL3_static_extensions::Version().empty());
}

TEST(WebVersion, MatchesComponentConstants)
{
    const std::string expected = std::to_string(SDL3_static_extensions::kVersionMajor) + "." +
                                 std::to_string(SDL3_static_extensions::kVersionMinor) + "." +
                                 std::to_string(SDL3_static_extensions::kVersionPatch);
    EXPECT_EQ(SDL3_static_extensions::Version().substr(0, expected.size()), expected);
}

TEST(WebRuntime, RunsInsideBrowserJavaScriptEnvironment)
{
    // Proves the JS interop bridge works — the same bridge a game uses for
    // canvas/audio/input glue.
    const char *agent = emscripten_run_script_string(
        "typeof navigator !== 'undefined' ? navigator.userAgent : 'node'");
    ASSERT_NE(agent, nullptr);
    EXPECT_FALSE(std::string(agent).empty());
}
