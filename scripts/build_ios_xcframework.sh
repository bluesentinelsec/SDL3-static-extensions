#!/usr/bin/env bash
# Build SDL3-static-extensions.xcframework: static device (arm64) and simulator
# (arm64/x86_64) libraries plus public headers and the generated version.hpp.
set -euo pipefail

repository_root="$(cd "$(dirname "$0")/.." && pwd)"
configuration="${1:-Release}"
configuration_lower="$(printf '%s' "${configuration}" | tr '[:upper:]' '[:lower:]')"
output_root="${2:-${repository_root}/build/ios/${configuration_lower}}"
deployment_target="${SDL3_STATIC_EXTENSIONS_IOS_DEPLOYMENT_TARGET:-13.0}"
# Simulator architectures. Release/packaging builds keep the fat default;
# CI iteration overrides to arm64-only for speed (see .github/workflows/ios.yml).
simulator_archs="${SDL3_STATIC_EXTENSIONS_IOS_SIMULATOR_ARCHS:-arm64;x86_64}"

case "${configuration}" in
    Debug|Release) ;;
    *)
        echo "Configuration must be Debug or Release (got '${configuration}')" >&2
        exit 2
        ;;
esac

if [[ "${output_root}" != /* ]]; then
    output_root="${repository_root}/${output_root}"
fi

version="$(tr -d '[:space:]' <"${repository_root}/VERSION" | sed 's/^v//;s/^V//;s/#.*//')"
device_build="${output_root}/iphoneos"
simulator_build="${output_root}/iphonesimulator"
combined_root="${output_root}/combined"
headers_root="${output_root}/headers"
xcframework="${output_root}/SDL3-static-extensions.xcframework"
archive="${output_root}/SDL3-static-extensions-ios-xcframework-${configuration_lower}-${version}.zip"

for tool in cmake xcodebuild xcrun libtool lipo ditto; do
    command -v "${tool}" >/dev/null 2>&1 || {
        echo "Required Apple build tool is missing: ${tool}" >&2
        exit 2
    }
done

cmake -E remove_directory "${output_root}"
cmake -E make_directory "${combined_root}"

configure_and_build() {
    local sdk="$1"
    local architectures="$2"
    local build_dir="$3"

    cmake -S "${repository_root}" -B "${build_dir}" -G Xcode \
        -DCMAKE_SYSTEM_NAME=iOS \
        -DCMAKE_OSX_SYSROOT="${sdk}" \
        -DCMAKE_OSX_ARCHITECTURES="${architectures}" \
        -DCMAKE_OSX_DEPLOYMENT_TARGET="${deployment_target}" \
        -DCMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET="${deployment_target}" \
        -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED=NO \
        -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED=NO \
        -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY= \
        -DSDL3_STATIC_EXTENSIONS_BUILD_APP=OFF \
        -DSDL3_STATIC_EXTENSIONS_BUILD_TESTS=OFF \
        -DSDL3_STATIC_EXTENSIONS_BUILD_BENCHMARKS=OFF \
        -DSDL3_STATIC_EXTENSIONS_WITH_CLI11=OFF \
        -DSDL3_STATIC_EXTENSIONS_WITH_JSON=OFF \
        -DSDL3_STATIC_EXTENSIONS_WITH_SPDLOG=OFF

    # Both SDKs. The XCFramework packages the C++ one, because it contains
    # the C API as well and Apple's idiom is a single framework rather than a
    # choice of two; the C archive is built because the install step below
    # stages headers from the same tree and installs whatever the project
    # defines. Building only one target is what broke this after the C++ SDK
    # was added — the install then looked for an archive nobody had built.
    cmake --build "${build_dir}" --config "${configuration}" \
        --target "SDLStatic_SDK" "SDLStatic_SDK_Cxx" --parallel
}

combine_archives() {
    local build_dir="$1"
    local destination="$2"
    local candidate

    # The C++ archive: it holds the C API too, so one framework serves both.
    candidate="$(find "${build_dir}" -type f -name "libSDL3_static_extensions_sdk_cxx.a" -path "*/${configuration}*" -print -quit)"
    if [[ -z "${candidate}" ]]; then
        echo "Missing libSDL3_static_extensions_sdk_cxx.a in ${build_dir}" >&2
        exit 1
    fi

    libtool -static -o "${destination}" "${candidate}"
}

configure_and_build iphoneos arm64 "${device_build}"
configure_and_build iphonesimulator "${simulator_archs}" "${simulator_build}"

combine_archives "${device_build}" "${combined_root}/libSDL3_static_extensions-iphoneos.a"
combine_archives "${simulator_build}" "${combined_root}/libSDL3_static_extensions-iphonesimulator.a"

cmake -E make_directory "${headers_root}/SDL3_static_extensions"
cmake -E copy_directory "${repository_root}/include/SDL3_static_extensions" "${headers_root}/SDL3_static_extensions"

# Every component's headers, and SDL3's, since our public headers include
# them. Taken from the install tree so this cannot drift from what the
# desktop SDK ships.
cmake --install "${simulator_build}" --config "${configuration}" \
    --prefix "${headers_root}/staged" >/dev/null
cmake -E copy_directory "${headers_root}/staged/include" "${headers_root}"
cmake -E rm -rf "${headers_root}/staged"
cmake -E rm -f "${headers_root}/SDL3_static_extensions/.gitkeep"
cmake -E copy "${device_build}/generated/include/SDL3_static_extensions/version.hpp" \
    "${headers_root}/SDL3_static_extensions/version.hpp"

xcodebuild -create-xcframework \
    -library "${combined_root}/libSDL3_static_extensions-iphoneos.a" \
    -headers "${headers_root}" \
    -library "${combined_root}/libSDL3_static_extensions-iphonesimulator.a" \
    -headers "${headers_root}" \
    -output "${xcframework}"

ditto -c -k --norsrc --noextattr --keepParent "${xcframework}" "${archive}"

"${repository_root}/scripts/verify_ios_xcframework.sh" "${xcframework}" "${version}"

echo "XCFramework: ${xcframework}"
echo "Package: ${archive}"
