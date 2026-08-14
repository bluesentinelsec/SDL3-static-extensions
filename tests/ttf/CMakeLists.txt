add_executable(SDL3_static_extensions_ttf_test
  ttf_test.cpp
  shaping_test.cpp
)
target_link_libraries(SDL3_static_extensions_ttf_test
  PRIVATE
    SDLStatic::TTF
    GTest::gtest_main
)
# shaping_test.cpp probes the vendored HarfBuzz directly.
target_include_directories(SDL3_static_extensions_ttf_test SYSTEM PRIVATE
  ${CMAKE_SOURCE_DIR}/ttf/harfbuzz
)
target_compile_definitions(SDL3_static_extensions_ttf_test PRIVATE
  TTF_TEST_ASSETS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/assets"
)
cppboot_set_project_warnings(SDL3_static_extensions_ttf_test)
gtest_discover_tests(SDL3_static_extensions_ttf_test DISCOVERY_TIMEOUT 60)

# Link audit: static SDLStatic::TTF + static minimal FreeType + static SDL3
# must depend only on OS-built-in shared libraries.
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME ttf_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_ttf_test>
  )
endif()
