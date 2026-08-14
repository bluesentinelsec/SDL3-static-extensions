add_executable(SDL3_static_extensions_gfx_test
  gfx_test.cpp
)
target_link_libraries(SDL3_static_extensions_gfx_test
  PRIVATE
    SDLStatic::Gfx
    GTest::gtest_main
)
cppboot_set_project_warnings(SDL3_static_extensions_gfx_test)
gtest_discover_tests(SDL3_static_extensions_gfx_test DISCOVERY_TIMEOUT 60)

# Link audit: static SDLStatic::Gfx + static SDL3 must depend only on
# OS-built-in shared libraries.
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME gfx_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_gfx_test>
  )
endif()
