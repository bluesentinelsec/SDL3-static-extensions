# SDLStatic::Lua — static-only build of vendored Lua 5.4.8 (MIT; provenance
# in deps/lua.md) plus original glue: state creation and a package searcher
# that resolves require() through the PhysFS VFS (scripts can live inside a
# mounted — optionally encrypted — zip archive).

enable_language(C)

file(GLOB LUA_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_library(SDLStatic_Lua STATIC
  ${LUA_SOURCES}
  glue/sdlstatic_lua.c
)
add_library(SDLStatic::Lua ALIAS SDLStatic_Lua)

set_target_properties(SDLStatic_Lua PROPERTIES
  OUTPUT_NAME SDLStatic_Lua
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_Lua SYSTEM
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(SDLStatic_Lua PUBLIC SDL3::SDL3 SDLStatic::VFS)
if(UNIX AND NOT APPLE)
  target_link_libraries(SDLStatic_Lua PRIVATE m)
endif()
