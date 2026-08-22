#!/usr/bin/env bash
# Verify a packaged SDL3-static-extensions.xcframework: slices, headers, version constants.
set -euo pipefail

xcframework="${1:-}"
expected_version="${2:-}"

if [[ -z "${xcframework}" || -z "${expected_version}" ]]; then
    echo "usage: $0 <SDL3-static-extensions.xcframework> <expected-version>" >&2
    exit 2
fi

# Expected simulator architectures mirror the build script's override knob
# (fat by default; CI iteration builds arm64-only, which also changes the
# slice directory name inside the XCFramework).
expected_sim_archs="${SDL3_STATIC_EXTENSIONS_IOS_SIMULATOR_ARCHS:-arm64;x86_64}"

device_library="${xcframework}/ios-arm64/libSDL3_static_extensions-iphoneos.a"
simulator_library="$(find "${xcframework}" -type f -path "*-simulator/*" \
    -name "libSDL3_static_extensions-iphonesimulator.a" -print -quit)"

test -f "${xcframework}/Info.plist"
test -f "${device_library}"
test -f "${simulator_library}"

device_arches="$(lipo -archs "${device_library}")"
simulator_arches="$(lipo -archs "${simulator_library}")"
[[ " ${device_arches} " == *" arm64 "* ]]
[[ " ${simulator_arches} " == *" arm64 "* ]]
if [[ ";${expected_sim_archs};" == *";x86_64;"* ]]; then
    [[ " ${simulator_arches} " == *" x86_64 "* ]]
fi

simulator_identifier="$(basename "$(dirname "${simulator_library}")")"
for identifier in ios-arm64 "${simulator_identifier}"; do
    header_root="${xcframework}/${identifier}/Headers"
    test -f "${header_root}/SDL3_static_extensions/version.hpp"
    # A consumer that cannot include the engine has nothing to link against,
    # so the headers are checked as carefully as the slices.
    test -f "${header_root}/SDLStatic/engine.h"
    test -f "${header_root}/SDLStatic/bindings.h"
    test -f "${header_root}/SDL3/SDL.h"
done

version_major="${expected_version%%.*}"
version_remainder="${expected_version#*.}"
version_minor="${version_remainder%%.*}"
version_patch="${version_remainder#*.}"
version_patch="${version_patch%%[-.]*}"
version_header="${xcframework}/ios-arm64/Headers/SDL3_static_extensions/version.hpp"
grep -q "kVersionMajor = ${version_major}" "${version_header}"
grep -q "kVersionMinor = ${version_minor}" "${version_header}"
grep -q "kVersionPatch = ${version_patch}" "${version_header}"

symbols_file="$(mktemp)"
trap 'rm -f "${symbols_file}"' EXIT
nm -g "${device_library}" >"${symbols_file}"
grep -qE '[ST] _?_ZN22SDL3_static_extensions7Version' "${symbols_file}"

# The engine itself. Checking the version symbol alone is what let this
# framework ship holding a version string and nothing else, through a
# verification that passed every time.
for symbol in _SDLStatic_CreateEngine _SDLStatic_ActorSpawn _SDLStatic_OpenLuaBindings \
              _SDLStatic_CreateGui _SDL_CreateWindow; do
    if ! grep -qE "[ST] ${symbol}\$" "${symbols_file}"; then
        echo "Missing ${symbol} in ${device_library} — the framework is not carrying the engine" >&2
        exit 1
    fi
done

# Size is the coarse version of the same question, and catches a regression
# that keeps the symbols but drops most of the code.
library_size="$(wc -c <"${device_library}")"
if (( library_size < 5000000 )); then
    echo "${device_library} is ${library_size} bytes — that is a placeholder, not the SDK" >&2
    exit 1
fi

echo "Verified iOS XCFramework ${expected_version}"
echo "  device: ${device_arches}"
echo "  simulator: ${simulator_arches}"
