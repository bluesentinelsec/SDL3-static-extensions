#!/usr/bin/env bash
# Build the Simulator/device test apps against a packaged SDL3-static-extensions.xcframework.
set -euo pipefail

repository_root="$(cd "$(dirname "$0")/.." && pwd)"
xcframework="${1:-}"
configuration="${2:-Release}"
output_root="${3:-${repository_root}/build/ios/consumer}"
deployment_target="${SDL3_STATIC_EXTENSIONS_IOS_DEPLOYMENT_TARGET:-13.0}"
version="$(tr -d '[:space:]' <"${repository_root}/VERSION" | sed 's/^v//;s/^V//;s/#.*//')"

if [[ -z "${xcframework}" ]]; then
    echo "usage: $0 <SDL3-static-extensions.xcframework> [Debug|Release] [output-directory]" >&2
    exit 2
fi
if [[ "${xcframework}" != /* ]]; then
    xcframework="${repository_root}/${xcframework}"
fi
if [[ "${output_root}" != /* ]]; then
    output_root="${repository_root}/${output_root}"
fi
if [[ ! -d "${xcframework}" ]]; then
    echo "XCFramework not found: ${xcframework}" >&2
    exit 2
fi

case "${configuration}" in
    Debug|Release) ;;
    *)
        echo "Configuration must be Debug or Release (got '${configuration}')" >&2
        exit 2
        ;;
esac

configure_and_build() {
    local sdk="$1"
    local architecture="$2"
    local build_dir="$3"

    cmake -S "${repository_root}/tests/ios" -B "${build_dir}" -G Xcode \
        -DCMAKE_SYSTEM_NAME=iOS \
        -DCMAKE_OSX_SYSROOT="${sdk}" \
        -DCMAKE_OSX_ARCHITECTURES="${architecture}" \
        -DCMAKE_OSX_DEPLOYMENT_TARGET="${deployment_target}" \
        -DCMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET="${deployment_target}" \
        -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED=NO \
        -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED=NO \
        -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY= \
        -DSDL3_STATIC_EXTENSIONS_XCFRAMEWORK="${xcframework}" \
        -DSDL3_STATIC_EXTENSIONS_EXPECTED_VERSION="${version}"

    cmake --build "${build_dir}" --config "${configuration}" \
        --target SDL3_static_extensions_ios_test --parallel
}

cmake -E remove_directory "${output_root}"
configure_and_build iphoneos arm64 "${output_root}/iphoneos"
configure_and_build iphonesimulator "$(uname -m)" "${output_root}/iphonesimulator"

echo "Device app build: ${output_root}/iphoneos"
echo "Simulator app build: ${output_root}/iphonesimulator"
