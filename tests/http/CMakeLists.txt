add_executable(SDL3_static_extensions_http_test
  http_test.cpp
)
target_link_libraries(SDL3_static_extensions_http_test
  PRIVATE
    SDLStatic::Http
    SDL3::SDL3
    GTest::gtest_main
)
cppboot_set_project_warnings(SDL3_static_extensions_http_test)
gtest_discover_tests(SDL3_static_extensions_http_test PROPERTIES TIMEOUT 120)

# Link audit: mog transports are OS-native or dlopen'd; nothing shared links.
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME http_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_http_test>
  )
endif()
