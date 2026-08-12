/**
 * @file test_main.mm
 * @brief End-to-end iOS tests consuming the packaged SDL3-static-extensions XCFramework.
 */

#import <UIKit/UIKit.h>
#import <os/log.h>

#include <SDL3_static_extensions/version.hpp>

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
