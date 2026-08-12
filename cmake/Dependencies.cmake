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
