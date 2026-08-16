add_executable(SDL3_static_extensions_engine_test
  engine_test.cpp
  scene_test.cpp
)
target_link_libraries(SDL3_static_extensions_engine_test
  PRIVATE
    SDLStatic::Engine
    GTest::gtest_main
)
cppboot_set_project_warnings(SDL3_static_extensions_engine_test)
gtest_discover_tests(SDL3_static_extensions_engine_test DISCOVERY_TIMEOUT 60)

find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME engine_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_engine_test>
  )
endif()
