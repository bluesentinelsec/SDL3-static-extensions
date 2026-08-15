# SDLStatic::Bindings — Lua + Ruby bindings for the game surface (original
# code, zlib). A language-independent core (bindings_core.c) performs every
# operation; the per-language files marshal arguments and register opaque
# handles with GC finalizers.
enable_language(C)

# Generated flat bindings (bindings/generated/, from tools/bindgen). Each
# module's files build only when its CMake option is on; the register
# files skip disabled modules via SDLSTATIC_GEN_DISABLE_<LIB>.
set(SDLSTATIC_GEN_SOURCES
  generated/gen_lua_register.c
  generated/gen_ruby_register.c
  generated/gen_lua_sdl.c
  generated/gen_ruby_sdl.c
  generated/gen_lua_sdlstatic.c
  generated/gen_ruby_sdlstatic.c
)
set(SDLSTATIC_GEN_DEFS "")
foreach(pair IN ITEMS
    "mix:MIXER" "img:IMAGE" "ttf:TTF" "net:NET" "physfs:VFS"
    "b2:PHYSICS" "nk:GUI" "cjson:FORMATS" "gfx:GFX" "toml:FORMATS"
    "yaml:FORMATS" "mog:HTTP")
  string(REPLACE ":" ";" pair "${pair}")
  list(GET pair 0 genkey)
  list(GET pair 1 opt)
  if(SDLSTATIC_BUILD_${opt})
    list(APPEND SDLSTATIC_GEN_SOURCES
      generated/gen_lua_${genkey}.c generated/gen_ruby_${genkey}.c)
  else()
    string(TOUPPER "${genkey}" genkey_upper)
    list(APPEND SDLSTATIC_GEN_DEFS "SDLSTATIC_GEN_DISABLE_${genkey_upper}")
  endif()
endforeach()

add_library(SDLStatic_Bindings STATIC
  src/bindings_core.c
  src/sdlstatic_bindings_lua.c
  src/sdlstatic_bindings_ruby.c
  src/gen_support_lua.c
  src/gen_support_ruby.c
  src/sdlstatic_regexp_ruby.c
  src/sdlstatic_regex_lua.c
  ${SDLSTATIC_GEN_SOURCES}
)

if(SDLSTATIC_GEN_DEFS)
  target_compile_definitions(SDLStatic_Bindings PRIVATE ${SDLSTATIC_GEN_DEFS})
endif()
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
  SDLStatic::TTF SDLStatic::Formats SDLStatic::GUI
  SDL3::SDL3
)
if(SDLSTATIC_BUILD_REGEX)
  target_link_libraries(SDLStatic_Bindings PUBLIC SDLStatic::Regex)
endif()
if(SDLSTATIC_BUILD_NET)
  target_link_libraries(SDLStatic_Bindings PUBLIC SDLStatic::Net)
endif()
if(SDLSTATIC_BUILD_HTTP)
  target_link_libraries(SDLStatic_Bindings PUBLIC SDLStatic::Http)
endif()
