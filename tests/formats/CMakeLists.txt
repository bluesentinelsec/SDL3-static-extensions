add_executable(SDL3_static_extensions_formats_test
  formats_test.cpp
)
target_link_libraries(SDL3_static_extensions_formats_test
  PRIVATE
    SDLStatic::Formats
    GTest::gtest_main
)
cppboot_set_project_warnings(SDL3_static_extensions_formats_test)
gtest_discover_tests(SDL3_static_extensions_formats_test)

# Link audit: parsers must not pull in shared libs (no libyaml.so, ever).
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME formats_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_formats_test>
  )
endif()
