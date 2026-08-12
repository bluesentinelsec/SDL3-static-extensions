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

// --- SDLStatic::Image at browser runtime --------------------------------

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

TEST(WebImage, DecodesEmbeddedPngInBrowser)
{
    ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
    SDL_Surface *surface = IMG_Load("/assets/sample.png");
    ASSERT_NE(surface, nullptr) << SDL_GetError();
    EXPECT_GT(surface->w, 0);
    EXPECT_GT(surface->h, 0);
    SDL_DestroySurface(surface);
    SDL_Quit();
}

TEST(WebImage, DecodesEmbeddedGifAnimationInBrowser)
{
    ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
    IMG_Animation *anim = IMG_LoadAnimation("/assets/rgbrgb.gif");
    ASSERT_NE(anim, nullptr) << SDL_GetError();
    EXPECT_GE(anim->count, 3);
    IMG_FreeAnimation(anim);
    SDL_Quit();
}

TEST(WebImage, VersionIsWired)
{
    EXPECT_GE(IMG_Version(), SDL_VERSIONNUM(3, 4, 4));
}
