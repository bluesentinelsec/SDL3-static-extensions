#!/usr/bin/env bash
set -euo pipefail

apk="${1:-android/test-app/build/outputs/apk/release/test-app-release.apk}"
package="com.example.sdl3staticextensions.test"
activity="${package}/.TestActivity"
# The APK carries the whole SDK — a 70 MB shared object per ABI, where it
# used to be a stub — so installing it and loading it the first time is far
# slower than the old default allowed for.
timeout_seconds="${SDL3_STATIC_EXTENSIONS_ANDROID_TEST_TIMEOUT:-300}"

if [[ ! -f "${apk}" ]]; then
  echo "Android test APK not found: ${apk}" >&2
  exit 1
fi

# Wait for the emulator to finish booting. Installing into a device that is
# still coming up fails with "device offline", and the failure then looks
# like a test timeout two minutes later rather than what it is.
adb wait-for-device
boot_deadline=$((SECONDS + 180))
while (( SECONDS < boot_deadline )); do
  if [[ "$(adb shell getprop sys.boot_completed 2>/dev/null | tr -d '\r')" == "1" ]]; then
    break
  fi
  sleep 2
done
if [[ "$(adb shell getprop sys.boot_completed 2>/dev/null | tr -d '\r')" != "1" ]]; then
  echo "Emulator did not finish booting" >&2
  exit 1
fi

adb install -r "${apk}" >/dev/null
adb logcat -c
adb shell am force-stop "${package}"
adb shell am start -W -n "${activity}" >/dev/null

deadline=$((SECONDS + timeout_seconds))
while (( SECONDS < deadline )); do
  logs="$(adb logcat -d -s SDL3-static-extensions-android-test:I '*:S')"
  if grep -q "SDL3_STATIC_EXTENSIONS_ANDROID_TESTS: PASS" <<<"${logs}"; then
    printf '%s\n' "${logs}"
    exit 0
  fi
  if grep -q "SDL3_STATIC_EXTENSIONS_ANDROID_TESTS: FAIL" <<<"${logs}"; then
    printf '%s\n' "${logs}" >&2
    exit 1
  fi
  sleep 1
done

# Our own tag first, then everything the app and the runtime said. A native
# crash produces no marker at all, so the narrow log shows nothing and the
# only evidence of what happened is in the wider one.
echo "----- test log -----" >&2
adb logcat -d -s SDL3-static-extensions-android-test:I '*:S' >&2
echo "----- crashes and runtime -----" >&2
adb logcat -d -s DEBUG:V AndroidRuntime:E SDL:V libc:V ActivityManager:W '*:S' \
  | tail -80 >&2
echo "Timed out after ${timeout_seconds}s waiting for Android tests" >&2
exit 1
