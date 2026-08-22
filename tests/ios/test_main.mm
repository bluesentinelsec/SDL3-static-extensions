/**
 * @file test_main.mm
 * @brief End-to-end iOS tests consuming the packaged SDL3-static-extensions XCFramework.
 */

#import <UIKit/UIKit.h>
#import <os/log.h>

#include <SDL3_static_extensions/version.hpp>

#include <SDLStatic/engine.h>
#include <SDLStatic/engine_actor.h>
#include <SDLStatic/engine_config.h>
#include <SDLStatic/lua.h>

#include <SDL3/SDL.h>

#include <string>
#include <string_view>

namespace
{

os_log_t TestLog()
{
    static os_log_t log = os_log_create("com.example.sdl3staticextensions.test", "tests");
    return log;
}

class TestRun
{
  public:
    void Check(bool condition, std::string_view message)
    {
        const std::string text{message};
        if (condition)
        {
            os_log_info(TestLog(), "PASS: %{public}s", text.c_str());
            return;
        }
        ++failures_;
        os_log_error(TestLog(), "FAIL: %{public}s", text.c_str());
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
    run.Check(version == SDL3_STATIC_EXTENSIONS_EXPECTED_VERSION,
              "XCFramework exports the VERSION-derived API");
    const std::string major_prefix = std::to_string(SDL3_static_extensions::kVersionMajor) + ".";
    run.Check(version.substr(0, major_prefix.size()) == major_prefix,
              "Version() matches the compiled major version");
    run.Check(SDL3_static_extensions::kVersionMajor >= 0, "major version is non-negative");

    // The engine, not just the version string. The XCFramework passed its
    // slice, architecture and version checks for months while containing
    // nothing but version.cpp — all three were true of an empty library.
    SDLStatic_EngineConfig *config = SDLStatic_ConfigCreate();
    run.Check(config != nullptr, "the engine's builders are in the framework");
    if (config != nullptr)
    {
        // Headless with a manual clock: a simulator test has no window to
        // wait on and no real clock worth waiting for.
        SDLStatic_ConfigSetHeadless(config, true);
        SDLStatic_ConfigSetManualClock(config, true);
        SDLStatic_ConfigSetAutoMount(config, false);

        SDLStatic_Engine *engine = SDLStatic_CreateEngine(config);
        SDLStatic_ConfigDestroy(config);
        run.Check(engine != nullptr, "an engine can be created on iOS");
        if (engine != nullptr)
        {
            SDLStatic_ActorDef *def = SDLStatic_ActorDefCreate();
            SDLStatic_ActorDefSetType(def, "ios");
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

    // Lua, which is the component iOS nearly could not have: os.execute calls
    // system(), and iOS marks it unavailable. Upstream's LUA_USE_IOS turns it
    // into a stub, so the rest of the language is here.
    lua_State *lua = SDLStatic_CreateLuaState();
    run.Check(lua != nullptr, "a Lua state can be created");
    if (lua != nullptr)
    {
        run.Check(SDLStatic_OpenLuaBindings(lua), "the generated bindings load");
        lua_close(lua);
    }

    run.Check(SDL_GetPlatform() != nullptr, "SDL3 itself is in the framework");
    return run.failures();
}

} // namespace

@interface TestAppDelegate : UIResponder <UIApplicationDelegate>
@property(nonatomic, strong) UIWindow *window;
@end

@implementation TestAppDelegate

- (BOOL)application:(UIApplication *)application
    didFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions
{
    (void)application;
    (void)launchOptions;
    self.window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    self.window.rootViewController = [[UIViewController alloc] init];
    self.window.rootViewController.view.backgroundColor = UIColor.systemBackgroundColor;
    [self.window makeKeyAndVisible];

    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
      const int failures = RunTests();
      os_log_info(TestLog(), "SDL3_STATIC_EXTENSIONS_IOS_TEST_RESULT: %{public}d", failures);
    });
    return YES;
}

@end

int main(int argc, char *argv[])
{
    @autoreleasepool
    {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass(TestAppDelegate.class));
    }
}
