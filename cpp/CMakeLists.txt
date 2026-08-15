# SDLStatic::Cpp — Google-style C++ bindings over the C surfaces: RAII
# owners for every handle, Status/Result<T> error flow, no exceptions
# (build-enforced via -fno-exceptions on this target), no dependencies
# beyond standard C++20. Disable with -DSDLSTATIC_BUILD_CPP=OFF.
#
# Formatting: cpp/.clang-format (Google preset) applies to this directory
# only. Http has no wrapper by decision: mog is already C++.

add_library(SDLStatic_Cpp STATIC
  src/no_exceptions.cc
)
add_library(SDLStatic::Cpp ALIAS SDLStatic_Cpp)

target_compile_features(SDLStatic_Cpp PUBLIC cxx_std_20)
set_target_properties(SDLStatic_Cpp PROPERTIES
  OUTPUT_NAME SDLStatic_Cpp
  POSITION_INDEPENDENT_CODE ON
)
if(NOT MSVC)
  target_compile_options(SDLStatic_Cpp PRIVATE -fno-exceptions)
endif()

target_include_directories(SDLStatic_Cpp
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(SDLStatic_Cpp PUBLIC
  SDLStatic::VFS SDLStatic::Extras SDLStatic::Mixer SDLStatic::Physics
  SDLStatic::Image SDLStatic::GUI SDLStatic::Lua SDLStatic::Ruby SDLStatic::Tiled
    SDLStatic::TTF SDLStatic::Formats SDLStatic::Gfx
  SDL3::SDL3
)

if(SDLSTATIC_BUILD_REGEX)
  target_link_libraries(SDLStatic_Cpp PUBLIC SDLStatic::Regex)
endif()
if(SDLSTATIC_BUILD_LIGHT)
  target_link_libraries(SDLStatic_Cpp PUBLIC SDLStatic::Light)
endif()
if(SDLSTATIC_BUILD_NET)
  target_link_libraries(SDLStatic_Cpp INTERFACE SDLStatic::Net)
endif()
if(SDLSTATIC_BUILD_HTTP)
  target_link_libraries(SDLStatic_Cpp INTERFACE SDLStatic::Http)
endif()
