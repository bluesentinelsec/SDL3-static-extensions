# Install the SDK to a throwaway prefix, then build and run a consumer that
# knows only about that prefix.
#
#   cmake -DBUILD_DIR=build/debug -DSOURCE_DIR=. -P scripts/verify_sdk_install.cmake
#
# The point is the isolation. Every other consumer check in this repo builds
# inside our tree, where the component targets exist and an empty library
# never shows — which is how we shipped a 686-byte "static library" for
# several releases without noticing. Here there is a prefix and nothing else.
cmake_minimum_required(VERSION 3.20)

if(NOT DEFINED BUILD_DIR OR NOT DEFINED SOURCE_DIR)
  message(FATAL_ERROR "usage: cmake -DBUILD_DIR=... -DSOURCE_DIR=... [-DCONFIG=...] -P scripts/verify_sdk_install.cmake")
endif()

# The consumer must be built in the same configuration as the archive it
# links. On MSVC a Release consumer against a Debug SDK fails on
# __imp__aligned_malloc_dbg — the debug CRT is a different runtime, and the
# error names none of that.
if(NOT DEFINED CONFIG OR CONFIG STREQUAL "")
  set(CONFIG "Release")
endif()

get_filename_component(BUILD_DIR "${BUILD_DIR}" ABSOLUTE)
get_filename_component(SOURCE_DIR "${SOURCE_DIR}" ABSOLUTE)
set(work "${BUILD_DIR}/sdk-verify")
set(prefix "${work}/prefix")
set(consumer "${work}/consumer")

# A stale prefix would let a consumer link headers or archives from a
# previous run, which is the one thing this test exists to rule out.
file(REMOVE_RECURSE "${work}")
file(MAKE_DIRECTORY "${prefix}")

message(STATUS "installing the ${CONFIG} SDK to ${prefix}")
execute_process(
  COMMAND ${CMAKE_COMMAND} --install "${BUILD_DIR}" --prefix "${prefix}"
          --config "${CONFIG}"
  RESULT_VARIABLE rc OUTPUT_QUIET
)
if(NOT rc EQUAL 0)
  message(FATAL_ERROR "install failed (${rc})")
endif()

# The archive has to contain the engine, not just exist. A hollow library
# links fine against a consumer that calls nothing, so check before building.
file(GLOB sdk_archive "${prefix}/lib/*SDL3_static_extensions_sdk*")
if(NOT sdk_archive)
  message(FATAL_ERROR "no SDK archive installed into ${prefix}/lib")
endif()
list(GET sdk_archive 0 sdk_archive)
file(SIZE "${sdk_archive}" sdk_size)
if(sdk_size LESS 1000000)
  message(FATAL_ERROR
    "${sdk_archive} is ${sdk_size} bytes — that is a placeholder, not the SDK")
endif()

# Every component's headers, not just the engine's. A component that was
# built but never installed would otherwise be discovered by whoever tried
# to include it, which is the discovery this test exists to prevent.
foreach(header
    SDLStatic/engine.h SDLStatic/vfs.h SDLStatic/gui.h SDLStatic/lua.h
    SDLStatic/ruby.h SDLStatic/bindings.h SDLStatic/tiled.h SDLStatic/regex.h
    SDL3_image/SDL_image.h SDL3_ttf/SDL_ttf.h SDL3_mixer/SDL_mixer.h
    SDL3_net/SDL_net.h SDL3_gfx/SDL3_gfxPrimitives.h
    box2d/box2d.h physfs.h lua.h mruby.h
    SDL3/SDL.h)
  if(NOT EXISTS "${prefix}/include/${header}")
    message(FATAL_ERROR "missing installed header: ${header}")
  endif()
endforeach()

message(STATUS "configuring a consumer against ${prefix}")
execute_process(
  COMMAND ${CMAKE_COMMAND}
          -S "${SOURCE_DIR}/tests/consumer" -B "${consumer}"
          -DCMAKE_PREFIX_PATH=${prefix}
          -DCMAKE_BUILD_TYPE=${CONFIG}
  RESULT_VARIABLE rc OUTPUT_VARIABLE out ERROR_VARIABLE out
)
if(NOT rc EQUAL 0)
  message(FATAL_ERROR "consumer configure failed:\n${out}")
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} --build "${consumer}" --config "${CONFIG}"
  RESULT_VARIABLE rc OUTPUT_VARIABLE out ERROR_VARIABLE out
)
if(NOT rc EQUAL 0)
  message(FATAL_ERROR "consumer build failed:\n${out}")
endif()

find_program(consumer_exe NAMES sdk_consumer sdk_consumer.exe
  PATHS "${consumer}" "${consumer}/${CONFIG}" NO_DEFAULT_PATH)
if(NOT consumer_exe)
  message(FATAL_ERROR "consumer built but produced no executable")
endif()

execute_process(COMMAND "${consumer_exe}" RESULT_VARIABLE rc OUTPUT_VARIABLE out
                ERROR_VARIABLE out)
if(NOT rc EQUAL 0)
  message(FATAL_ERROR "consumer ran but failed (${rc}):\n${out}")
endif()
message(STATUS "${out}")
message(STATUS "SDK install verified")
