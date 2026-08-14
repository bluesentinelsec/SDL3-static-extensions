add_executable(SDL3_static_extensions_script_test
  script_test.cpp
)
target_link_libraries(SDL3_static_extensions_script_test
  PRIVATE
    SDLStatic::Bindings
    GTest::gtest_main
)
target_compile_definitions(SDL3_static_extensions_script_test PRIVATE
  SCRIPT_TEST_ASSETS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/assets"
)
cppboot_set_project_warnings(SDL3_static_extensions_script_test)
gtest_discover_tests(SDL3_static_extensions_script_test)

# The repl binary itself, driven end to end.
if(TARGET repl)
  add_test(NAME repl_lua_eval COMMAND repl -l lua -e "print(1 + 2)")
  set_tests_properties(repl_lua_eval PROPERTIES PASS_REGULAR_EXPRESSION "^3")
  add_test(NAME repl_ruby_eval COMMAND repl -l ruby -e "puts 6 * 7")
  set_tests_properties(repl_ruby_eval PROPERTIES PASS_REGULAR_EXPRESSION "^42")
  add_test(NAME repl_bad_language COMMAND repl -l cobol)
  set_tests_properties(repl_bad_language PROPERTIES WILL_FAIL TRUE)
endif()

find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME script_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_script_test>
  )
endif()
