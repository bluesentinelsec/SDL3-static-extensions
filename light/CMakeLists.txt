# SDLStatic::Light — dynamic 2D lighting: a day/night ambient cycle,
# coloured lights, and hard shadows cast by the level's geometry.
#
#   <SDLStatic/light.h>  light map compositing, occluders, gameplay queries
#
# Original code (zlib), plain C over SDL3's renderer — no shaders and no
# GPU API, so it runs everywhere the rest of the project does.
enable_language(C)

# The GL path loads every entry point through SDL_GL_GetProcAddress, so
# nothing here links against libGL and the archive stays dependency-free.
add_library(SDLStatic_Light STATIC
  src/sdlstatic_light.c
  src/sdlstatic_light_gl.c
)
add_library(SDLStatic::Light ALIAS SDLStatic_Light)

if("c_std_99" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_Light PRIVATE c_std_99)
endif()

set_target_properties(SDLStatic_Light PROPERTIES
  OUTPUT_NAME SDLStatic_Light
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_Light
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(SDLStatic_Light PUBLIC SDL3::SDL3)
if(UNIX AND NOT APPLE)
  target_link_libraries(SDLStatic_Light PRIVATE m)
endif()
