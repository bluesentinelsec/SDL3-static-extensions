add_executable(SDL3_static_extensions_cpp_test
  cpp_test.cpp
)
target_link_libraries(SDL3_static_extensions_cpp_test
  PRIVATE
    SDLStatic::Cpp
    SDLStatic::GUI
    GTest::gtest_main
)
target_compile_definitions(SDL3_static_extensions_cpp_test PRIVATE
  CPP_TEST_ASSETS_DIR="${CMAKE_SOURCE_DIR}/tests/vfs/assets"
)
cppboot_set_project_warnings(SDL3_static_extensions_cpp_test)
gtest_discover_tests(SDL3_static_extensions_cpp_test)

find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME cpp_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_cpp_test>
  )
endif()
