# Unit tests — one subdirectory per component under test.
# Browser builds run the wasm test page instead of the native CTest suites.
if(EMSCRIPTEN)
  add_subdirectory(web)
  return()
endif()

add_subdirectory(version)
if(SDLSTATIC_BUILD_IMAGE)
  add_subdirectory(image)
endif()
if(SDLSTATIC_BUILD_TTF)
  add_subdirectory(ttf)
endif()
