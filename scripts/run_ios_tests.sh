#!/usr/bin/env bash
# Run the packaged iOS tests in a temporary Simulator, polling os_log output.
set -euo pipefail

app="${APP:-}"
app_name="${APP_NAME:-SDL3_static_extensions_ios_test.app}"
build_dir="${BUILD_DIR:-build/ios/consumer/iphonesimulator}"
bundle_id="${BUNDLE_ID:-com.example.sdl3staticextensions.test}"
log_subsystem="${LOG_SUBSYSTEM:-com.example.sdl3staticextensions.test}"
sentinel="${SENTINEL:-SDL3_STATIC_EXTENSIONS_IOS_TEST_RESULT}"
timeout_seconds="${SDL3_STATIC_EXTENSIONS_IOS_TEST_TIMEOUT:-180}"
simulator_name="${SIM_NAME:-SDL3-static-extensions iOS Tests}"

simulator_udid=""
launch_pid=""
stream_pid=""
log_file="$(mktemp)"

cleanup() {
    if [[ -n "${launch_pid}" ]]; then
        kill "${launch_pid}" >/dev/null 2>&1 || true
        wait "${launch_pid}" >/dev/null 2>&1 || true
    fi
    if [[ -n "${stream_pid}" ]]; then
        kill "${stream_pid}" >/dev/null 2>&1 || true
        wait "${stream_pid}" >/dev/null 2>&1 || true
    fi
    if [[ -n "${simulator_udid}" ]]; then
        xcrun simctl shutdown "${simulator_udid}" >/dev/null 2>&1 || true
        xcrun simctl delete "${simulator_udid}" >/dev/null 2>&1 || true
    fi
    rm -f "${log_file}"
}
trap cleanup EXIT

if [[ -z "${app}" ]]; then
    app="$(find "${build_dir}" -type d -name "${app_name}" -print -quit)"
fi
if [[ -z "${app}" || ! -d "${app}" ]]; then
    echo "iOS test app not found under ${build_dir}: ${app_name}" >&2
    exit 2
fi

selection="$(python3 - <<'PY'
import json
import subprocess

def simctl(*args):
    return json.loads(subprocess.check_output(["xcrun", "simctl", "list", *args, "-j"], text=True))

runtimes = [
    runtime for runtime in simctl("runtimes").get("runtimes", [])
    if runtime.get("isAvailable") and runtime.get("identifier", "").startswith(
        "com.apple.CoreSimulator.SimRuntime.iOS-"
    )
]
if not runtimes:
    raise SystemExit("No available iOS Simulator runtime")
runtime = runtimes[-1]["identifier"]

device_types = [
    device for device in simctl("devicetypes").get("devicetypes", [])
    if device.get("name", "").startswith("iPhone")
]
if not device_types:
    raise SystemExit("No available iPhone Simulator device type")

preferred = ("iPhone 17", "iPhone 16", "iPhone 15", "iPhone 14")
device = next(
    (item for name in preferred for item in device_types if item.get("name") == name),
    device_types[-1],
)
print(runtime)
print(device["identifier"])
PY
)"
runtime_id="$(printf '%s\n' "${selection}" | sed -n '1p')"
device_type_id="$(printf '%s\n' "${selection}" | sed -n '2p')"

echo "Using ${runtime_id} with ${device_type_id}"
simulator_udid="$(xcrun simctl create "${simulator_name}" "${device_type_id}" "${runtime_id}")"
xcrun simctl boot "${simulator_udid}"
xcrun simctl bootstatus "${simulator_udid}" -b
xcrun simctl install "${simulator_udid}" "${app}"

xcrun simctl spawn "${simulator_udid}" log stream \
    --style compact \
    --level debug \
    --predicate "subsystem == \"${log_subsystem}\"" >"${log_file}" 2>&1 &
stream_pid=$!

# CI simulators occasionally wedge on the first launch after boot; retry once.
result=""
for attempt in 1 2; do
    xcrun simctl launch --console-pty "${simulator_udid}" "${bundle_id}" >>"${log_file}" 2>&1 &
    launch_pid=$!

    deadline=$((SECONDS + timeout_seconds))
    while [[ -z "${result}" && ${SECONDS} -lt ${deadline} ]]; do
        if grep -q "${sentinel}:" "${log_file}"; then
            result="$(grep "${sentinel}:" "${log_file}" | tail -n 1 | sed -E "s/.*${sentinel}: ([0-9]+).*/\\1/")"
            break
        fi
        sleep 1
    done
    if [[ -n "${result}" || ${attempt} -eq 2 ]]; then
        break
    fi

    echo "No ${sentinel} within ${timeout_seconds}s (attempt ${attempt}); relaunching" >&2
    kill "${launch_pid}" >/dev/null 2>&1 || true
    wait "${launch_pid}" >/dev/null 2>&1 || true
    launch_pid=""
    xcrun simctl terminate "${simulator_udid}" "${bundle_id}" >/dev/null 2>&1 || true
done

echo "----- iOS test log -----"
sed -n "/PASS:/p;/FAIL:/p;/${sentinel}:/p" "${log_file}"
echo "----- end iOS test log -----"

if [[ -z "${result}" ]]; then
    echo "Timed out waiting for ${sentinel}; raw simulator log tail:" >&2
    tail -n 100 "${log_file}" >&2
    exit 1
fi

echo "iOS test failures: ${result}"
exit "${result}"
