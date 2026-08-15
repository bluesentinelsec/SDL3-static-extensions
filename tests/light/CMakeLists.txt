add_executable(SDL3_static_extensions_light_test
  light_test.cpp
)
target_link_libraries(SDL3_static_extensions_light_test
  PRIVATE
    SDLStatic::Light
    GTest::gtest_main
)
cppboot_set_project_warnings(SDL3_static_extensions_light_test)
gtest_discover_tests(SDL3_static_extensions_light_test DISCOVERY_TIMEOUT 60)

find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME light_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_light_test>
  )
endif()

# The embedded shaders are generated from light/shaders/*; this is the same
# guard bindgen_freshness gives the generated bindings.
if(Python3_Interpreter_FOUND)
  add_test(NAME light_shaders_freshness
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/embed_shaders.py --check
  )
endif()
