add_executable(SDL3_static_extensions_genbindings_test
  genbindings_test.cpp
)
target_link_libraries(SDL3_static_extensions_genbindings_test
  PRIVATE
    SDLStatic::Bindings
    SDLStatic::Cpp
    SDLStatic::Physics
    SDLStatic::Formats
    GTest::gtest_main
)
cppboot_set_project_warnings(SDL3_static_extensions_genbindings_test)
gtest_discover_tests(SDL3_static_extensions_genbindings_test DISCOVERY_TIMEOUT 60)

find_package(Python3 COMPONENTS Interpreter)
if(Python3_Interpreter_FOUND)
  add_test(NAME genbindings_link_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/link_audit.py
            $<TARGET_FILE:SDL3_static_extensions_genbindings_test>
  )
  # Nuklear stays public-API only: NK_LIB/NK_INTERN must not be bound, and
  # only value types get field access.
  add_test(NAME nuklear_scope_audit
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/tools/audit_nuklear_scope.py
  )

  # Codegen freshness: committed generated output must match the tool.
  add_test(NAME bindgen_freshness
    COMMAND ${Python3_EXECUTABLE} -m tools.bindgen --check
            --repo ${CMAKE_SOURCE_DIR} --deps ${FETCHCONTENT_BASE_DIR}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )
endif()
