# SDLStatic::Engine — an opinionated game engine: the frame loop, scenes,
# actors, rendering, input and assets.
#
#   <SDLStatic/engine.h>           the loop, time, and the drawing surface
#   <SDLStatic/engine_scene.h>     the scene stack
#   <SDLStatic/engine_graphics.h>  graphics settings, config.toml and the CLI
#
# Original code (zlib), plain C over SDL3. The loop is a fixed simulation
# tick with interpolated rendering — the arrangement that makes motion look
# smooth when the tick rate and the display's refresh rate disagree.
enable_language(C)

add_library(SDLStatic_Engine STATIC
  src/sdlstatic_engine.c
  src/sdlstatic_engine_scene.c
  src/sdlstatic_engine_graphics.c
  src/sdlstatic_engine_gfxconfig.c
  src/sdlstatic_engine_target.c
  src/sdlstatic_engine_postfx.c
)
add_library(SDLStatic::Engine ALIAS SDLStatic_Engine)

if("c_std_99" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_Engine PRIVATE c_std_99)
endif()

set_target_properties(SDLStatic_Engine PROPERTIES
  OUTPUT_NAME SDLStatic_Engine
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_Engine
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Formats for tomlc99: config.toml is part of the settings contract, not an
# optional extra, so the dependency is unconditional rather than a #ifdef.
target_link_libraries(SDLStatic_Engine PUBLIC SDL3::SDL3 PRIVATE SDLStatic::Formats)
if(UNIX AND NOT APPLE)
  target_link_libraries(SDLStatic_Engine PRIVATE m)
endif()
