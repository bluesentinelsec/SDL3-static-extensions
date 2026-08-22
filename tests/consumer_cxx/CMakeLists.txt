# A C++ consumer of the *installed* SDK, linking one archive.
#
# The C++ SDK contains everything the C one does plus the C++ wrapper, so
# this links `SDKCxx` alone — no second library, no link order. If that ever
# stops being true, this fails to link, which is the point.
cmake_minimum_required(VERSION 3.20)
project(sdlstatic_sdk_consumer_cxx LANGUAGES CXX)

find_package(SDL3-static-extensions REQUIRED)

add_executable(sdk_consumer_cxx main.cpp)
target_compile_features(sdk_consumer_cxx PRIVATE cxx_std_20)
target_link_libraries(sdk_consumer_cxx PRIVATE SDL3-static-extensions::SDKCxx)
