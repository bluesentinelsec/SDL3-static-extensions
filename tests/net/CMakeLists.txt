add_executable(SDL3_static_extensions_net_test
  net_test.cpp
)
target_link_libraries(SDL3_static_extensions_net_test
  PRIVATE
    SDLStatic::Net
    GTest::gtest_main
)
cppboot_set_project_warnings(SDL3_static_extensions_net_test)
gtest_discover_tests(SDL3_static_extensions_net_test DISCOVERY_TIMEOUT 60 PROPERTIES TIMEOUT 120)

# Link audit: static SDLStatic::Net + static SDL3 must depend only on
# OS-built-in shared libraries.
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME net_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_net_test>
  )
endif()
