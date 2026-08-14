# SDLStatic::Bindings — Lua + Ruby bindings for the game surface (original
# code, zlib). A language-independent core (bindings_core.c) performs every
# operation; the per-language files marshal arguments and register opaque
# handles with GC finalizers.
enable_language(C)

add_library(SDLStatic_Bindings STATIC
  src/bindings_core.c
  src/sdlstatic_bindings_lua.c
  src/sdlstatic_bindings_ruby.c
)
add_library(SDLStatic::Bindings ALIAS SDLStatic_Bindings)

set_target_properties(SDLStatic_Bindings PROPERTIES
  OUTPUT_NAME SDLStatic_Bindings
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_Bindings
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(SDLStatic_Bindings PUBLIC
  SDLStatic::Lua SDLStatic::Ruby SDLStatic::VFS SDLStatic::Image SDLStatic::Tiled
  SDLStatic::Mixer SDLStatic::Physics SDLStatic::Gfx SDLStatic::Extras
  SDL3::SDL3
)
