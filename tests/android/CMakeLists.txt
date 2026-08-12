cmake_minimum_required(VERSION 3.22.1)
project(SDL3_static_extensions_android_test LANGUAGES CXX)

find_package(SDL3_static_extensions REQUIRED CONFIG)

add_library(SDL3_static_extensions_android_test SHARED android_test.cpp)
target_compile_features(SDL3_static_extensions_android_test PRIVATE cxx_std_20)
target_compile_options(SDL3_static_extensions_android_test PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -Werror
)
target_link_libraries(SDL3_static_extensions_android_test PRIVATE SDL3_static_extensions::SDL3_static_extensions log)
