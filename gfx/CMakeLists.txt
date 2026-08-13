# SDLStatic::Gfx — static-only build of the vendored SDL3_gfx sources
# (community port of SDL2_gfx to SDL3, v1.0.1; provenance in deps/SDL3_gfx.md)
# plus the original SDLStatic GPU-primitives layer.
#
# SDL3_gfx is pure C over the SDL renderer/surface APIs with zero external
# dependencies, so it is inherently static-link friendly. The vendored code
# is CPU-bound (per-pixel spans via SDL_RenderPoints); sdlstatic_gpu_primitives.c
# adds GPU-bound equivalents that tessellate to triangles and render through
# one SDL_RenderGeometry call per primitive. SDL3_imageFilter (MMX-era byte
# array filters) was deleted, not stubbed.

enable_language(C)

add_library(SDLStatic_Gfx STATIC
  src/SDL3_gfxPrimitives.c
  src/SDL3_rotozoom.c
  src/SDL3_framerate.c
  # Original SDLStatic code (not vendored): GPU-bound primitive equivalents.
  src/sdlstatic_gpu_primitives.c
)
add_library(SDLStatic::Gfx ALIAS SDLStatic_Gfx)

if("c_std_99" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_Gfx PRIVATE c_std_99)
endif()

set_target_properties(SDLStatic_Gfx PROPERTIES
  OUTPUT_NAME SDLStatic_Gfx
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_Gfx
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    # Vendored .c files include their own headers unqualified.
    ${CMAKE_CURRENT_SOURCE_DIR}/include/SDL3_gfx
)

target_link_libraries(SDLStatic_Gfx PUBLIC SDL3::SDL3)
