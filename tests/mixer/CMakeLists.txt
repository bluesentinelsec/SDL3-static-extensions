add_executable(SDL3_static_extensions_mixer_test
  mixer_test.cpp
  chiptune_test.cpp
)
target_link_libraries(SDL3_static_extensions_mixer_test
  PRIVATE
    SDLStatic::Mixer
    GTest::gtest_main
)
target_compile_definitions(SDL3_static_extensions_mixer_test PRIVATE
  MIXER_TEST_ASSETS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/assets"
  MIXER_GM_PATCHES_DIR="${CMAKE_SOURCE_DIR}/mixer/gm-patches"
)
cppboot_set_project_warnings(SDL3_static_extensions_mixer_test)
gtest_discover_tests(SDL3_static_extensions_mixer_test)

# Link audit: static SDLStatic::Mixer + static SDL3 must depend only on
# OS-built-in shared libraries — no codec libraries, ever.
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME mixer_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_mixer_test>
  )
endif()
