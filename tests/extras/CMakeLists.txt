add_executable(SDL3_static_extensions_extras_test
  extras_test.cpp
)
target_link_libraries(SDL3_static_extensions_extras_test
  PRIVATE
    SDLStatic::Extras
    GTest::gtest_main
)
cppboot_set_project_warnings(SDL3_static_extensions_extras_test)
gtest_discover_tests(SDL3_static_extensions_extras_test)

# Link audit: static SDLStatic::Extras + static SDL3 must depend only on
# OS-built-in shared libraries — no libcrypto, no libz, ever.
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME extras_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_extras_test>
  )
endif()
