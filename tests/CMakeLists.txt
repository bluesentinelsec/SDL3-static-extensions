# Unit tests — one subdirectory per component under test.
# Browser builds run the wasm test page instead of the native CTest suites.
if(EMSCRIPTEN)
  add_subdirectory(web)
  return()
endif()

add_subdirectory(version)
