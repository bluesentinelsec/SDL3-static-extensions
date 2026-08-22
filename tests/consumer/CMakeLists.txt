# A consumer of the *installed* SDK, deliberately knowing nothing about the
# build tree it came from.
#
# This is the test that would have caught the hollow artifacts. Every other
# consumer check we have builds inside our own tree, where the real component
# targets exist and the placeholder library's emptiness never shows. Here
# there is only a prefix: find_package it, link it, call into it.
cmake_minimum_required(VERSION 3.20)
# C only, deliberately. The SDK contains C++ objects, and a project that
# enabled CXX would link through the C++ driver and pick up its runtime by
# accident — hiding the exact failure this is meant to catch.
project(sdlstatic_sdk_consumer LANGUAGES C)

find_package(SDL3-static-extensions REQUIRED)

add_executable(sdk_consumer main.c)
target_link_libraries(sdk_consumer PRIVATE SDL3-static-extensions::SDK)
