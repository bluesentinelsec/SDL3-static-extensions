add_executable(SDL3_static_extensions_image_test
  image_test.cpp
)
target_link_libraries(SDL3_static_extensions_image_test
  PRIVATE
    SDLStatic::Image
    GTest::gtest_main
)
target_compile_definitions(SDL3_static_extensions_image_test PRIVATE
  IMAGE_TEST_ASSETS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/assets"
)
cppboot_set_project_warnings(SDL3_static_extensions_image_test)
gtest_discover_tests(SDL3_static_extensions_image_test)

# Link audit: the test binary (static SDLStatic::Image + static SDL3) must
# depend only on OS-built-in shared libraries — the project's core promise.
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME image_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_image_test>
  )
endif()
