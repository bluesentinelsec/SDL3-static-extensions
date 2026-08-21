cmake_minimum_required(VERSION 3.20)

# ---------------------------------------------------------------------------
# Single source of truth for the package version: the VERSION file at repo root.
# Edit that file only; CMake, --version, tests, and release checks all consume it.
# ---------------------------------------------------------------------------
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" SDL3_STATIC_EXTENSIONS_VERSION_RAW
  LIMIT_COUNT 1
)
string(STRIP "${SDL3_STATIC_EXTENSIONS_VERSION_RAW}" SDL3_STATIC_EXTENSIONS_VERSION)
# Allow optional leading 'v' and ignore anything after '#' on the line.
string(REGEX REPLACE "^[vV]" "" SDL3_STATIC_EXTENSIONS_VERSION "${SDL3_STATIC_EXTENSIONS_VERSION}")
string(REGEX REPLACE "[ \t]*#.*" "" SDL3_STATIC_EXTENSIONS_VERSION "${SDL3_STATIC_EXTENSIONS_VERSION}")
string(STRIP "${SDL3_STATIC_EXTENSIONS_VERSION}" SDL3_STATIC_EXTENSIONS_VERSION)
if(NOT SDL3_STATIC_EXTENSIONS_VERSION MATCHES "^[0-9]+\\.[0-9]+\\.[0-9]+([.-].*)?$")
  message(FATAL_ERROR
    "VERSION file must contain a semantic version like 0.1.0 "
    "(got '${SDL3_STATIC_EXTENSIONS_VERSION}')"
  )
endif()

project(SDL3-static-extensions
  VERSION ${SDL3_STATIC_EXTENSIONS_VERSION}
  DESCRIPTION "C++ project bootstrapped by cppboot"
  LANGUAGES CXX
)

# True when this project is the top-level CMake project (not add_subdirectory /
# FetchContent). Downstream consumers should not inherit app/tests/bench defaults.
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(SDL3_STATIC_EXTENSIONS_IS_TOP_LEVEL ON)
else()
  set(SDL3_STATIC_EXTENSIONS_IS_TOP_LEVEL OFF)
endif()

# Exposed to version templates (configure_file @ONLY).
set(PROJECT_NAMESPACE "SDL3_static_extensions")
set(PROJECT_VERSION_STRING "${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Top-level-only settings so embedding via add_subdirectory/FetchContent stays clean.
if(SDL3_STATIC_EXTENSIONS_IS_TOP_LEVEL)
  # Export a compilation database for clangd and other LSP tools.
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

  # Put binaries under build/<config>/bin (and libs under lib/) so an executable
  # named like a component directory (e.g. project "calc" + src/calc/) never
  # collides with a source/build subdirectory path.
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

  # Default to Debug when the user does not pass CMAKE_BUILD_TYPE (single-config).
  if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
  endif()
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# Absolute paths: generic names like "Dependencies" collide with a consuming
# parent project's identically named modules when this repo is embedded via
# FetchContent/add_subdirectory (CMAKE_MODULE_PATH searches the parent first).
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerWarnings.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Sanitizers.cmake")

# Preferred third-party libraries (FetchContent). On for top-level apps; off when
# embedded (and for the Android Prefab AAR and iOS XCFramework and web/Emscripten package, whose public
# contract is the dependency-free core C++ API).
set(SDL3_STATIC_EXTENSIONS_DEFAULT_WITH_OPTIONAL_DEPS ${SDL3_STATIC_EXTENSIONS_IS_TOP_LEVEL})
if(ANDROID OR IOS OR EMSCRIPTEN)
  set(SDL3_STATIC_EXTENSIONS_DEFAULT_WITH_OPTIONAL_DEPS OFF)
endif()
option(SDL3_STATIC_EXTENSIONS_WITH_CLI11 "CLI argument parsing via CLI11" ${SDL3_STATIC_EXTENSIONS_DEFAULT_WITH_OPTIONAL_DEPS})
option(SDL3_STATIC_EXTENSIONS_WITH_JSON "JSON parsing via nlohmann/json" ${SDL3_STATIC_EXTENSIONS_DEFAULT_WITH_OPTIONAL_DEPS})
option(SDL3_STATIC_EXTENSIONS_WITH_SPDLOG "Console/file logging via spdlog" ${SDL3_STATIC_EXTENSIONS_DEFAULT_WITH_OPTIONAL_DEPS})

# When embedded, skip app/tests/benchmarks unless the consumer opts in. Platform
# package consumers receive the C++ library as a packaged artifact; repository
# tests run in the platform test application instead of CTest (browser tests
# under tests/web keep BUILD_TESTS meaningful for Emscripten).
set(SDL3_STATIC_EXTENSIONS_DEFAULT_BUILD_APP ${SDL3_STATIC_EXTENSIONS_IS_TOP_LEVEL})
set(SDL3_STATIC_EXTENSIONS_DEFAULT_BUILD_TESTS ${SDL3_STATIC_EXTENSIONS_IS_TOP_LEVEL})
set(SDL3_STATIC_EXTENSIONS_DEFAULT_BUILD_BENCHMARKS ${SDL3_STATIC_EXTENSIONS_IS_TOP_LEVEL})
if(ANDROID OR IOS)
  set(SDL3_STATIC_EXTENSIONS_DEFAULT_BUILD_APP OFF)
  set(SDL3_STATIC_EXTENSIONS_DEFAULT_BUILD_TESTS OFF)
  set(SDL3_STATIC_EXTENSIONS_DEFAULT_BUILD_BENCHMARKS OFF)
endif()
if(EMSCRIPTEN)
  set(SDL3_STATIC_EXTENSIONS_DEFAULT_BUILD_APP OFF)
  set(SDL3_STATIC_EXTENSIONS_DEFAULT_BUILD_BENCHMARKS OFF)
endif()
option(SDL3_STATIC_EXTENSIONS_BUILD_APP "Build the demo application executable" ${SDL3_STATIC_EXTENSIONS_DEFAULT_BUILD_APP})
option(SDL3_STATIC_EXTENSIONS_BUILD_TESTS "Build unit tests" ${SDL3_STATIC_EXTENSIONS_DEFAULT_BUILD_TESTS})
option(SDL3_STATIC_EXTENSIONS_BUILD_BENCHMARKS "Build benchmarks" ${SDL3_STATIC_EXTENSIONS_DEFAULT_BUILD_BENCHMARKS})
# HTML5 canvas demo page for top-level Emscripten builds (see src/web/).
option(SDL3_STATIC_EXTENSIONS_BUILD_WEB_DEMO "Build the web canvas demo (Emscripten only)" ${SDL3_STATIC_EXTENSIONS_IS_TOP_LEVEL})

# SDL extension libraries (design: default ON; consumers disable what they
# do not want). Each extension is a static library under SDLStatic::.
option(SDLSTATIC_BUILD_IMAGE "Build the SDLStatic::Image extension" ON)
option(SDLSTATIC_BUILD_TTF "Build the SDLStatic::TTF extension" ON)
option(SDLSTATIC_BUILD_MIXER "Build the SDLStatic::Mixer extension" ON)
# Upstream SDL_net has no real Emscripten support (it ships a stub build);
# per the no-stubs policy, Net simply does not exist on web builds.
if(EMSCRIPTEN)
  set(SDLSTATIC_BUILD_NET OFF)
else()
  option(SDLSTATIC_BUILD_NET "Build the SDLStatic::Net extension" ON)
endif()
option(SDLSTATIC_BUILD_GFX "Build the SDLStatic::Gfx extension" ON)
option(SDLSTATIC_BUILD_EXTRAS "Build the SDLStatic::Extras modules" ON)
option(SDLSTATIC_BUILD_FORMATS "Build the SDLStatic::Formats parsers (JSON/TOML/YAML)" ON)
option(SDLSTATIC_BUILD_VFS "Build the SDLStatic::VFS virtual filesystem (PhysFS)" ON)
option(SDLSTATIC_BUILD_PHYSICS "Build the SDLStatic::Physics engine (Box2D)" ON)
option(SDLSTATIC_BUILD_GUI "Build the SDLStatic::GUI toolkit (Nuklear)" ON)
option(SDLSTATIC_BUILD_LUA "Build the SDLStatic::Lua interpreter" ON)
option(SDLSTATIC_BUILD_RUBY "Build the SDLStatic::Ruby interpreter (mruby)" ON)
option(SDLSTATIC_BUILD_CPP "Build the sdlstatic C++ bindings (RAII, no exceptions)" ON)
option(SDLSTATIC_BUILD_TILED "Build the SDLStatic::Tiled map parser (cute_tiled)" ON)
option(SDLSTATIC_BUILD_REGEX "Build the SDLStatic::Regex engine (Oniguruma)" ON)
option(SDLSTATIC_BUILD_LIGHT "Build the SDLStatic::Light 2D lighting engine" ON)
option(SDLSTATIC_BUILD_ENGINE "Build the SDLStatic::Engine game engine" ON)
# mog's C API and server are not supported in browsers.
if(EMSCRIPTEN)
  set(SDLSTATIC_BUILD_HTTP OFF)
else()
  option(SDLSTATIC_BUILD_HTTP "Build the SDLStatic::Http client/server (mog)" ON)
endif()

if(ANDROID AND (SDL3_STATIC_EXTENSIONS_BUILD_APP OR SDL3_STATIC_EXTENSIONS_BUILD_TESTS OR SDL3_STATIC_EXTENSIONS_BUILD_BENCHMARKS))
  message(FATAL_ERROR
    "Android builds provide the SDL3_static_extensions Prefab library; set SDL3_STATIC_EXTENSIONS_BUILD_APP, "
    "SDL3_STATIC_EXTENSIONS_BUILD_TESTS, and SDL3_STATIC_EXTENSIONS_BUILD_BENCHMARKS to OFF. "
    "Use the android Gradle project to build and run device tests."
  )
endif()

if(ANDROID AND (SDL3_STATIC_EXTENSIONS_WITH_CLI11 OR SDL3_STATIC_EXTENSIONS_WITH_JSON OR SDL3_STATIC_EXTENSIONS_WITH_SPDLOG))
  message(FATAL_ERROR
    "The Android Prefab AAR contains the dependency-free core API; set "
    "SDL3_STATIC_EXTENSIONS_WITH_CLI11, SDL3_STATIC_EXTENSIONS_WITH_JSON, and SDL3_STATIC_EXTENSIONS_WITH_SPDLOG to OFF"
  )
endif()
if(IOS AND (SDL3_STATIC_EXTENSIONS_BUILD_APP OR SDL3_STATIC_EXTENSIONS_BUILD_TESTS OR SDL3_STATIC_EXTENSIONS_BUILD_BENCHMARKS))
  message(FATAL_ERROR
    "iOS builds provide the SDL3_static_extensions XCFramework library; set SDL3_STATIC_EXTENSIONS_BUILD_APP, "
    "SDL3_STATIC_EXTENSIONS_BUILD_TESTS, and SDL3_STATIC_EXTENSIONS_BUILD_BENCHMARKS to OFF. "
    "Use the iOS package test application for Simulator tests."
  )
endif()

if(IOS AND (SDL3_STATIC_EXTENSIONS_WITH_CLI11 OR SDL3_STATIC_EXTENSIONS_WITH_JSON OR SDL3_STATIC_EXTENSIONS_WITH_SPDLOG))
  message(FATAL_ERROR
    "The iOS XCFramework contains the dependency-free core API; set "
    "SDL3_STATIC_EXTENSIONS_WITH_CLI11, SDL3_STATIC_EXTENSIONS_WITH_JSON, and SDL3_STATIC_EXTENSIONS_WITH_SPDLOG to OFF"
  )
endif()
if(EMSCRIPTEN AND (SDL3_STATIC_EXTENSIONS_BUILD_APP OR SDL3_STATIC_EXTENSIONS_BUILD_BENCHMARKS))
  message(FATAL_ERROR
    "Browser builds provide the static SDL3_static_extensions library, the web demo, and "
    "browser tests; set SDL3_STATIC_EXTENSIONS_BUILD_APP and SDL3_STATIC_EXTENSIONS_BUILD_BENCHMARKS to OFF"
  )
endif()
# ASan + UBSan for project targets (intended for Linux GCC/Clang; see make sanitizer).
option(SDL3_STATIC_EXTENSIONS_ENABLE_SANITIZERS "Enable Address+UBSan on project targets" OFF)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Dependencies.cmake")

# Apply sanitizer flags only to targets created after this point (not FetchContent deps).
if(SDL3_STATIC_EXTENSIONS_ENABLE_SANITIZERS)
  cppboot_enable_sanitizers()
endif()

# Generate the version API from cmake/version.{hpp,cpp}.in (values from VERSION).
set(SDL3_STATIC_EXTENSIONS_GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(SDL3_STATIC_EXTENSIONS_GENERATED_INCLUDE_DIR "${SDL3_STATIC_EXTENSIONS_GENERATED_DIR}/include")
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/version.hpp.in"
  "${SDL3_STATIC_EXTENSIONS_GENERATED_INCLUDE_DIR}/SDL3_static_extensions/version.hpp"
  @ONLY
)
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/version.cpp.in"
  "${SDL3_STATIC_EXTENSIONS_GENERATED_DIR}/version.cpp"
  @ONLY
)

# The Android Prefab AAR and iOS XCFramework and web/Emscripten package ships the core as a static
# archive, so force the core static there (even with --shared). Android
# additionally needs PIC: the archive folds into libSDL3_static_extensions.so (src/android/).
set(SDL3_STATIC_EXTENSIONS_CORE_LIB_TYPE STATIC)
if(ANDROID OR IOS OR EMSCRIPTEN)
  set(SDL3_STATIC_EXTENSIONS_CORE_LIB_TYPE STATIC)
endif()
if(ANDROID)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()
add_library(${PROJECT_NAME}_lib ${SDL3_STATIC_EXTENSIONS_CORE_LIB_TYPE})
# Namespaced aliases for consumers (add_subdirectory / FetchContent / find_package).
add_library(${PROJECT_NAME}::lib ALIAS ${PROJECT_NAME}_lib)
add_library(${PROJECT_NAME}::SDL3_static_extensions ALIAS ${PROJECT_NAME}_lib)

set_target_properties(${PROJECT_NAME}_lib PROPERTIES
  OUTPUT_NAME SDL3_static_extensions
  EXPORT_NAME lib
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)

target_include_directories(${PROJECT_NAME}_lib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${SDL3_STATIC_EXTENSIONS_GENERATED_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>
)

cppboot_set_project_warnings(${PROJECT_NAME}_lib)

# Preferred third-party deps are linked on the *app* (and optionally tests), not
# the library. Static libraries propagate private deps into install(EXPORT);
# keeping the library free of FetchContent targets makes find_package clean.
# Add target_link_libraries(... PUBLIC/PRIVATE ...) in component CMakeLists when
# library code needs these deps.

add_subdirectory(src)

if(SDLSTATIC_BUILD_IMAGE)
  add_subdirectory(image)
endif()

if(SDLSTATIC_BUILD_TTF)
  add_subdirectory(ttf)
endif()

if(SDLSTATIC_BUILD_MIXER)
  add_subdirectory(mixer)
endif()

if(SDLSTATIC_BUILD_NET)
  add_subdirectory(net)
endif()

if(SDLSTATIC_BUILD_GFX)
  add_subdirectory(gfx)
endif()

if(SDLSTATIC_BUILD_EXTRAS)
  add_subdirectory(extras)
endif()

if(SDLSTATIC_BUILD_FORMATS)
  add_subdirectory(formats)
endif()

if(SDLSTATIC_BUILD_VFS)
  if(NOT SDLSTATIC_BUILD_EXTRAS)
    message(FATAL_ERROR "SDLSTATIC_BUILD_VFS requires SDLSTATIC_BUILD_EXTRAS (encrypted mounts use SDLStatic crypto)")
  endif()
  add_subdirectory(vfs)
endif()

if(SDLSTATIC_BUILD_PHYSICS)
  if(NOT SDLSTATIC_BUILD_GFX)
    message(FATAL_ERROR "SDLSTATIC_BUILD_PHYSICS requires SDLSTATIC_BUILD_GFX (debug draw uses the GPU primitives)")
  endif()
  add_subdirectory(physics)
endif()

if(SDLSTATIC_BUILD_GUI)
  if(NOT SDLSTATIC_BUILD_EXTRAS)
    message(FATAL_ERROR "SDLSTATIC_BUILD_GUI requires SDLSTATIC_BUILD_EXTRAS (file dialogs)")
  endif()
  add_subdirectory(gui)
endif()

if(SDLSTATIC_BUILD_LUA OR SDLSTATIC_BUILD_RUBY)
  if(NOT SDLSTATIC_BUILD_VFS)
    message(FATAL_ERROR "script interpreters require SDLSTATIC_BUILD_VFS (require() loads modules through the VFS)")
  endif()
  if(NOT SDLSTATIC_BUILD_REGEX)
    message(FATAL_ERROR "script interpreters require SDLSTATIC_BUILD_REGEX (Ruby's Regexp class is built on it)")
  endif()
endif()
if(SDLSTATIC_BUILD_HTTP)
  add_subdirectory(http)
endif()
if(SDLSTATIC_BUILD_TILED)
  if(NOT SDLSTATIC_BUILD_VFS)
    message(FATAL_ERROR "SDLSTATIC_BUILD_TILED requires SDLSTATIC_BUILD_VFS")
  endif()
  if(NOT SDLSTATIC_BUILD_FORMATS)
    message(FATAL_ERROR "SDLSTATIC_BUILD_TILED requires SDLSTATIC_BUILD_FORMATS")
  endif()
  add_subdirectory(tiled)
endif()
if(SDLSTATIC_BUILD_REGEX)
  add_subdirectory(regex)
endif()
if(SDLSTATIC_BUILD_LIGHT)
  add_subdirectory(light)
endif()
if(SDLSTATIC_BUILD_ENGINE)
  if(NOT SDLSTATIC_BUILD_FORMATS)
    message(FATAL_ERROR "SDLSTATIC_BUILD_ENGINE requires SDLSTATIC_BUILD_FORMATS (graphics settings parse media/config.toml)")
  endif()
  if(NOT SDLSTATIC_BUILD_VFS)
    message(FATAL_ERROR "SDLSTATIC_BUILD_ENGINE requires SDLSTATIC_BUILD_VFS (the engine mounts the game's media archive)")
  endif()
  if(NOT SDLSTATIC_BUILD_PHYSICS)
    message(FATAL_ERROR "SDLSTATIC_BUILD_ENGINE requires SDLSTATIC_BUILD_PHYSICS (actors carry Box2D bodies)")
  endif()
  if(NOT SDLSTATIC_BUILD_IMAGE)
    message(FATAL_ERROR "SDLSTATIC_BUILD_ENGINE requires SDLSTATIC_BUILD_IMAGE (the asset loader decodes textures)")
  endif()
  if(NOT SDLSTATIC_BUILD_LIGHT)
    message(FATAL_ERROR "SDLSTATIC_BUILD_ENGINE requires SDLSTATIC_BUILD_LIGHT (scene lighting presets)")
  endif()
  add_subdirectory(engine)
endif()
if(SDLSTATIC_BUILD_LUA)
  add_subdirectory(lua)
endif()
if(SDLSTATIC_BUILD_RUBY)
  add_subdirectory(mruby)
endif()
if(SDLSTATIC_BUILD_CPP)
  foreach(dep IN ITEMS VFS EXTRAS MIXER PHYSICS IMAGE GUI LUA RUBY TILED TTF FORMATS GFX)
    if(NOT SDLSTATIC_BUILD_${dep})
      message(FATAL_ERROR "SDLSTATIC_BUILD_CPP requires SDLSTATIC_BUILD_${dep} (or set SDLSTATIC_BUILD_CPP=OFF)")
    endif()
  endforeach()
  add_subdirectory(cpp)
endif()
if(SDLSTATIC_BUILD_LUA AND SDLSTATIC_BUILD_RUBY)
  foreach(dep IN ITEMS VFS IMAGE TILED MIXER PHYSICS GFX EXTRAS TTF FORMATS GUI)
    if(NOT SDLSTATIC_BUILD_${dep})
      message(FATAL_ERROR "the bindings require SDLSTATIC_BUILD_${dep} (or disable LUA/RUBY)")
    endif()
  endforeach()
  add_subdirectory(bindings)
  if(SDL3_STATIC_EXTENSIONS_IS_TOP_LEVEL)
    add_subdirectory(tools/repl)
  endif()
endif()

if(SDL3_STATIC_EXTENSIONS_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

if(SDL3_STATIC_EXTENSIONS_BUILD_BENCHMARKS)
  add_subdirectory(benchmarks)
endif()

# Keep a source-root compile_commands.json for clangd / VS Code IntelliSense.
# Only when this project is top-level (do not rewrite a parent project's link).
if(SDL3_STATIC_EXTENSIONS_IS_TOP_LEVEL AND CMAKE_EXPORT_COMPILE_COMMANDS)
  if(WIN32)
    add_custom_target(cppboot_compile_commands ALL
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_BINARY_DIR}/compile_commands.json"
        "${CMAKE_SOURCE_DIR}/compile_commands.json"
      COMMENT "Copying compile_commands.json to source root for clangd"
      VERBATIM
    )
  else()
    add_custom_target(cppboot_compile_commands ALL
      COMMAND ${CMAKE_COMMAND} -E rm -f
        "${CMAKE_SOURCE_DIR}/compile_commands.json"
      COMMAND ${CMAKE_COMMAND} -E create_symlink
        "${CMAKE_BINARY_DIR}/compile_commands.json"
        "${CMAKE_SOURCE_DIR}/compile_commands.json"
      COMMENT "Linking compile_commands.json to source root for clangd"
      VERBATIM
    )
  endif()
endif()

include(GNUInstallDirs)
install(DIRECTORY include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h"
)
# Generated version API header (from VERSION + cmake/version.hpp.in).
install(DIRECTORY ${SDL3_STATIC_EXTENSIONS_GENERATED_INCLUDE_DIR}/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h"
)
install(TARGETS ${PROJECT_NAME}_lib
  EXPORT ${PROJECT_NAME}Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# CMake package config so consumers can find_package(SDL3-static-extensions).
install(EXPORT ${PROJECT_NAME}Targets
  FILE ${PROJECT_NAME}Targets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/SDL3-static-extensionsConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/SDL3-static-extensionsConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/SDL3-static-extensionsConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/SDL3-static-extensionsConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/SDL3-static-extensionsConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

