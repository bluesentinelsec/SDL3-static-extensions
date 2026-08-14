add_executable(SDL3_static_extensions_vfs_test
  vfs_test.cpp
)
target_link_libraries(SDL3_static_extensions_vfs_test
  PRIVATE
    SDLStatic::VFS
    GTest::gtest_main
)
target_compile_definitions(SDL3_static_extensions_vfs_test PRIVATE
  VFS_TEST_ASSETS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/assets"
)
cppboot_set_project_warnings(SDL3_static_extensions_vfs_test)
gtest_discover_tests(SDL3_static_extensions_vfs_test DISCOVERY_TIMEOUT 60)

# Link audit: static PhysFS + glue must depend only on OS-built-in libs.
find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME vfs_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_vfs_test>
  )
endif()
