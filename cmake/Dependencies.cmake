# Third-party dependencies via FetchContent (pinned stable tags).
include(FetchContent)

set(GOOGLETEST_TAG v1.17.0)
set(BENCHMARK_TAG v1.9.5)
set(CLI11_TAG v2.6.2)
set(NLOHMANN_JSON_TAG v3.12.0)
set(SPDLOG_TAG v1.17.0)

# ---------------------------------------------------------------------------
# Preferred application libraries (optional — defaults follow top-level vs embed)
# ---------------------------------------------------------------------------

if(SDL3_STATIC_EXTENSIONS_WITH_CLI11)
  # CLI11 — header-only CLI parser (static-link friendly).
  set(CLI11_PRECOMPILED OFF CACHE BOOL "" FORCE)
  set(CLI11_BUILD_TESTS OFF CACHE BOOL "" FORCE)
  set(CLI11_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  FetchContent_Declare(
    cli11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG        ${CLI11_TAG}
    GIT_SHALLOW    TRUE
  )
  FetchContent_MakeAvailable(cli11)
  cppboot_mark_system_includes(CLI11)
endif()

if(SDL3_STATIC_EXTENSIONS_WITH_JSON)
  # nlohmann/json — header-only JSON (static-link friendly).
  set(JSON_BuildTests OFF CACHE BOOL "" FORCE)
  set(JSON_Install OFF CACHE BOOL "" FORCE)
  FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        ${NLOHMANN_JSON_TAG}
    GIT_SHALLOW    TRUE
  )
  FetchContent_MakeAvailable(nlohmann_json)
  cppboot_mark_system_includes(nlohmann_json)
endif()

if(SDL3_STATIC_EXTENSIONS_WITH_SPDLOG)
  # spdlog — fast logging; built as a static library by default.
  set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "" FORCE)
  set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "" FORCE)
  set(SPDLOG_BUILD_BENCH OFF CACHE BOOL "" FORCE)
  set(SPDLOG_INSTALL OFF CACHE BOOL "" FORCE)
  set(SPDLOG_BUILD_SHARED OFF CACHE BOOL "" FORCE)
  FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        ${SPDLOG_TAG}
    GIT_SHALLOW    TRUE
  )
  FetchContent_MakeAvailable(spdlog)
  cppboot_mark_system_includes(spdlog)
endif()

# ---------------------------------------------------------------------------
# Test / benchmark frameworks (only when those options are enabled)
# ---------------------------------------------------------------------------

if(SDL3_STATIC_EXTENSIONS_BUILD_TESTS)
  # GoogleTest / GoogleMock
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        ${GOOGLETEST_TAG}
    GIT_SHALLOW    TRUE
  )
  FetchContent_MakeAvailable(googletest)

  foreach(_cppboot_third_party IN ITEMS gtest gtest_main gmock gmock_main)
    cppboot_mark_system_includes(${_cppboot_third_party})
  endforeach()
endif()

if(SDL3_STATIC_EXTENSIONS_BUILD_BENCHMARKS)
  # Google Benchmark
  set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
  set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)
  set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)

  FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG        ${BENCHMARK_TAG}
    GIT_SHALLOW    TRUE
  )
  FetchContent_MakeAvailable(benchmark)

  foreach(_cppboot_third_party IN ITEMS benchmark benchmark_main)
    cppboot_mark_system_includes(${_cppboot_third_party})
  endforeach()
endif()

include(GoogleTest)

# ---------------------------------------------------------------------------
# SDL3 — the only supported way to obtain SDL3 (see deps/SDL3.md).
# Pinned release tarball, SHA-256 verified, built static. Never vendored,
# never a submodule; extensions never embed a second SDL3.
# ---------------------------------------------------------------------------
if(SDLSTATIC_BUILD_IMAGE OR SDLSTATIC_BUILD_TTF OR SDLSTATIC_BUILD_MIXER OR SDLSTATIC_BUILD_NET OR SDLSTATIC_BUILD_GFX OR SDLSTATIC_BUILD_EXTRAS OR SDLSTATIC_BUILD_VFS OR SDLSTATIC_BUILD_PHYSICS)
  set(SDL_SHARED OFF CACHE BOOL "" FORCE)
  set(SDL_STATIC ON CACHE BOOL "" FORCE)
  set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
  set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
  FetchContent_Declare(
    SDL3
    URL
      https://github.com/libsdl-org/SDL/releases/download/release-3.4.14/SDL3-3.4.14.tar.gz
      https://www.libsdl.org/release/SDL3-3.4.14.tar.gz
    URL_HASH SHA256=30d4aa2b3037718142b32dffd4e72f917ebb6cc5227150e7bb9c45efb2153aeb
  )
  FetchContent_MakeAvailable(SDL3)
endif()

# ---------------------------------------------------------------------------
# FreeType — Phase-A backend for SDLStatic::TTF (see deps/FreeType.md).
# Official release tarball, SHA-256 pinned, built static and minimal: every
# optional dependency disabled (internal zlib; no bzip2/png/harfbuzz/brotli),
# so it adds zero shared-library dependencies. License: FTL (attribution
# required in shipped products — see deps/FreeType.md).
# ---------------------------------------------------------------------------
if(SDLSTATIC_BUILD_TTF)
  set(FT_DISABLE_ZLIB ON CACHE BOOL "" FORCE)
  set(FT_DISABLE_BZIP2 ON CACHE BOOL "" FORCE)
  set(FT_DISABLE_PNG ON CACHE BOOL "" FORCE)
  set(FT_DISABLE_HARFBUZZ ON CACHE BOOL "" FORCE)
  set(FT_DISABLE_BROTLI ON CACHE BOOL "" FORCE)
  set(SKIP_INSTALL_ALL ON)
  FetchContent_Declare(
    freetype
    URL
      https://download.savannah.gnu.org/releases/freetype/freetype-2.14.3.tar.xz
      https://downloads.sourceforge.net/freetype/freetype-2.14.3.tar.xz
    URL_HASH SHA256=36bc4f1cc413335368ee656c42afca65c5a3987e8768cc28cf11ba775e785a5f
  )
  FetchContent_MakeAvailable(freetype)
endif()
