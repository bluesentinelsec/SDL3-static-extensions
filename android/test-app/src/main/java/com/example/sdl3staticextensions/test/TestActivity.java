package com.example.sdl3staticextensions.test;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public final class TestActivity extends Activity {
    private static final String TAG = "SDL3-static-extensions-android-test";

    static {
        System.loadLibrary("SDL3_static_extensions_android_test");
    }

    private static native int runNativeTests();

    @Override
    protected void onCreate(Bundle state) {
        super.onCreate(state);
        Thread runner = new Thread(() -> {
            int failures = runNativeTests();
            if (failures == 0) {
                Log.i(TAG, "SDL3_STATIC_EXTENSIONS_ANDROID_TESTS: PASS");
            } else {
                Log.e(TAG, "SDL3_STATIC_EXTENSIONS_ANDROID_TESTS: FAIL (" + failures + " failures)");
            }
            finishAndRemoveTask();
        }, "SDL3-static-extensions-native-tests");
        runner.start();
    }
}
