# Browser-runtime tests: GoogleTest compiled to WebAssembly, run via emrun.
add_executable(SDL3_static_extensions_web_test web_test.cpp)
target_link_libraries(SDL3_static_extensions_web_test
  PRIVATE
    ${PROJECT_NAME}_lib
    SDLStatic::Image
    GTest::gtest_main
)
set_target_properties(SDL3_static_extensions_web_test PROPERTIES SUFFIX ".html")
target_link_options(SDL3_static_extensions_web_test
  PRIVATE
    "--emrun"
    "SHELL:-sEXIT_RUNTIME=1"
    "SHELL:-sALLOW_MEMORY_GROWTH=1"
    # Corpus samples embedded into the wasm virtual filesystem: proves image
    # decoding works at browser runtime, not merely that it cross-compiles.
    "SHELL:--embed-file ${CMAKE_SOURCE_DIR}/tests/image/assets/sample.png@/assets/sample.png"
    "SHELL:--embed-file ${CMAKE_SOURCE_DIR}/tests/image/assets/rgbrgb.gif@/assets/rgbrgb.gif"
)
cppboot_set_project_warnings(SDL3_static_extensions_web_test)
