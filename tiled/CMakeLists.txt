# SDLStatic::Tiled — Tiled (.tmj JSON) map parsing via vendored cute_tiled
# (single dependency-free C header, dual zlib/public-domain; provenance in
# deps/cute_tiled.md) with VFS-aware loading and a flat accessor API the
# Lua/Ruby/C++ bindings wrap. Chosen over libtmx, whose libxml2 dependency
# fails the static-first rule.
enable_language(C)

add_library(SDLStatic_Tiled STATIC
  src/sdlstatic_tiled.c
)
add_library(SDLStatic::Tiled ALIAS SDLStatic_Tiled)

set_target_properties(SDLStatic_Tiled PROPERTIES
  OUTPUT_NAME SDLStatic_Tiled
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_Tiled SYSTEM
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(SDLStatic_Tiled PUBLIC SDL3::SDL3 SDLStatic::VFS PRIVATE SDLStatic::Formats)
