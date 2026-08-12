# SDLStatic::TTF — static-only build of the vendored SDL_ttf sources
# (upstream release-3.2.2; provenance in deps/SDL3_ttf.md).
#
# Phase A: FreeType backend via pinned, minimal, static FetchContent
# (deps/FreeType.md — internal zlib, no harfbuzz/png/brotli/bzip2, so the
# link-time dependency set stays empty). HarfBuzz shaping and plutosvg color
# emoji are disabled (TTF_USE_HARFBUZZ / TTF_USE_PLUTOSVG default to 0).
# The stb_truetype-vs-static-FreeType Phase-B decision is documented in
# deps/SDL3_ttf.md.

# The root project is CXX-only; the vendored SDL_ttf sources are C.
enable_language(C)

add_library(SDLStatic_TTF STATIC
  src/SDL_ttf.c
  src/SDL_hashtable.c
  src/SDL_hashtable_ttf.c
  src/SDL_gpu_textengine.c
  src/SDL_renderer_textengine.c
  src/SDL_surface_textengine.c
)
add_library(SDLStatic::TTF ALIAS SDLStatic_TTF)

if("c_std_99" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_TTF PRIVATE c_std_99)
endif()

set_target_properties(SDLStatic_TTF PROPERTIES
  OUTPUT_NAME SDLStatic_TTF
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_TTF
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(SDLStatic_TTF
  PUBLIC SDL3::SDL3
  PRIVATE freetype
)

# Vendored upstream C: build quietly rather than under the project's
# warnings-as-errors regime; our own code around it stays strict.
