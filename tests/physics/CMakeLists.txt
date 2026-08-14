add_executable(SDL3_static_extensions_physics_test
  physics_test.cpp
)
target_link_libraries(SDL3_static_extensions_physics_test
  PRIVATE
    SDLStatic::Physics
    GTest::gtest_main
)
cppboot_set_project_warnings(SDL3_static_extensions_physics_test)
gtest_discover_tests(SDL3_static_extensions_physics_test DISCOVERY_TIMEOUT 60)

# Link audit: static Box2D + glue must depend only on OS-built-in libs.
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME physics_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_physics_test>
  )
endif()
