# SDLStatic::Physics — static-only build of vendored Box2D v3.1.1 (MIT;
# provenance in deps/box2d.md) plus original debug-draw glue that renders
# collision shapes through the SDLStatic::Gfx GPU primitives.
#
# Box2D v3 is pure C11 with zero external dependencies; SIMD (SSE2/NEON)
# auto-detects with a scalar fallback, so every platform including web
# builds the same sources. The native b2* API is exposed directly.

enable_language(C)

file(GLOB BOX2D_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_library(SDLStatic_Physics STATIC
  ${BOX2D_SOURCES}
  # Original SDLStatic code (not vendored): b2DebugDraw -> gpu* primitives.
  glue/sdlstatic_physics_draw.c
  glue/sdlstatic_physics_build.c
)
add_library(SDLStatic::Physics ALIAS SDLStatic_Physics)

if("c_std_11" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_Physics PRIVATE c_std_11)
endif()

set_target_properties(SDLStatic_Physics PROPERTIES
  OUTPUT_NAME SDLStatic_Physics
  POSITION_INDEPENDENT_CODE ON
)

# SYSTEM: Box2D's public headers use C-style casts in inline helpers, which
# consumer TUs built with -Wold-style-cast -Werror would reject.
target_include_directories(SDLStatic_Physics SYSTEM
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_include_directories(SDLStatic_Physics
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Box2D's wasm path uses Emscripten's SSE->WASM-SIMD128 compat intrinsics,
# which require these flags (upstream's own CMake does the same). WASM SIMD
# is supported by all modern browsers.
if(EMSCRIPTEN)
  target_compile_options(SDLStatic_Physics PRIVATE -msimd128 -msse2)
endif()

target_link_libraries(SDLStatic_Physics PUBLIC SDLStatic::Gfx)
if(UNIX AND NOT APPLE)
  target_link_libraries(SDLStatic_Physics PRIVATE m)
endif()
