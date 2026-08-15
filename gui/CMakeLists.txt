# SDLStatic::GUI — vendored Nuklear (single header, v4.13.3, dual
# MIT/public-domain; provenance in deps/nuklear.md) plus the original SDL3
# backend and the weighted grid layout helper.
#
# Nuklear is vendored as-is (no delete-down: it is one dependency-free
# header; its embedded single-file pieces — stb_truetype/stb_rect_pack —
# are part of that header). All platform specificity lives in our backend,
# so the GUI runs wherever SDL3 runs: desktop, web, and mobile.

enable_language(C)

add_library(SDLStatic_GUI STATIC
  # Original SDLStatic code; sdlstatic_gui.c is the single TU that compiles
  # the Nuklear implementation.
  src/sdlstatic_gui.c
  src/sdlstatic_gui_grid.c
)
add_library(SDLStatic::GUI ALIAS SDLStatic_GUI)

if("c_std_99" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_GUI PRIVATE c_std_99)
endif()

set_target_properties(SDLStatic_GUI PROPERTIES
  OUTPUT_NAME SDLStatic_GUI
  POSITION_INDEPENDENT_CODE ON
)

# SYSTEM: the vendored header's declarations trip strict consumer warnings.
target_include_directories(SDLStatic_GUI SYSTEM
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# SDLStatic_GuiOpenFileButton drives the file dialogs in SDLStatic::Extras.
target_link_libraries(SDLStatic_GUI PUBLIC SDL3::SDL3 SDLStatic::Extras)
if(UNIX AND NOT APPLE)
  target_link_libraries(SDLStatic_GUI PRIVATE m)
endif()
