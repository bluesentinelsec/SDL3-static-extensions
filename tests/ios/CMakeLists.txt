cmake_minimum_required(VERSION 3.28)

project(SDL3_static_extensions_ios_package_test LANGUAGES CXX OBJCXX)

if(NOT IOS)
  message(FATAL_ERROR "The SDL3-static-extensions iOS package test must be configured with CMAKE_SYSTEM_NAME=iOS")
endif()

set(SDL3_STATIC_EXTENSIONS_XCFRAMEWORK "" CACHE PATH "Path to the packaged SDL3-static-extensions.xcframework")
set(SDL3_STATIC_EXTENSIONS_EXPECTED_VERSION "" CACHE STRING "Version expected from the packaged library")

if(NOT IS_DIRECTORY "${SDL3_STATIC_EXTENSIONS_XCFRAMEWORK}")
  message(FATAL_ERROR "Set SDL3_STATIC_EXTENSIONS_XCFRAMEWORK to the packaged SDL3-static-extensions.xcframework directory")
endif()
if(SDL3_STATIC_EXTENSIONS_EXPECTED_VERSION STREQUAL "")
  message(FATAL_ERROR "Set SDL3_STATIC_EXTENSIONS_EXPECTED_VERSION to the root VERSION value")
endif()

add_executable(SDL3_static_extensions_ios_test MACOSX_BUNDLE test_main.mm)
target_compile_features(SDL3_static_extensions_ios_test PRIVATE cxx_std_20)
target_compile_options(SDL3_static_extensions_ios_test PRIVATE -fobjc-arc)
target_compile_definitions(SDL3_static_extensions_ios_test PRIVATE
  SDL3_STATIC_EXTENSIONS_EXPECTED_VERSION="${SDL3_STATIC_EXTENSIONS_EXPECTED_VERSION}"
)
target_link_libraries(SDL3_static_extensions_ios_test PRIVATE
  "${SDL3_STATIC_EXTENSIONS_XCFRAMEWORK}"
  "-framework Foundation"
  "-framework UIKit"
)

set_target_properties(SDL3_static_extensions_ios_test PROPERTIES
  MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in"
  MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.sdl3staticextensions.test"
  MACOSX_BUNDLE_BUNDLE_NAME "SDL3-static-extensions iOS Tests"
  MACOSX_BUNDLE_BUNDLE_VERSION "1"
  MACOSX_BUNDLE_SHORT_VERSION_STRING "${SDL3_STATIC_EXTENSIONS_EXPECTED_VERSION}"
  XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "com.example.sdl3staticextensions.test"
  XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO"
  XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED "NO"
  XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
)
