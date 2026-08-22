# SDK.cmake — the single static library we ship, and the rules that install it.
#
# The component targets (SDLStatic::Engine, ::Bindings, ::TTF, …) are how the
# source tree is organised; they are not how anyone wants to consume it. A
# game that had to name twenty archives in dependency order, plus SDL3 and
# every vendored dependency, would be paying for our directory layout.
#
# So one archive holds the lot: every component, SDL3 itself, and the
# third-party static libraries the components need. `-lSDL3_static_extensions_sdk`
# and an include path is the whole link line, which is the promise a project
# called *static extensions* ought to be making.
#
# It is assembled from object files rather than by merging archives, because
# $<TARGET_OBJECTS:...> is the one approach that works the same on ar, libtool
# and lib.exe. Merging archives means three platform-specific code paths and a
# fourth for the cross builds.

# Fold a target's objects into the SDK, if that target exists in this build.
# Optional components and platform-specific dependencies mean half of these
# are absent in any given configuration.
function(sdlstatic_sdk_collect out_var)
  set(collected "")
  foreach(candidate IN LISTS ARGN)
    if(TARGET ${candidate})
      get_target_property(type ${candidate} TYPE)
      # INTERFACE and imported targets have no objects of their own; a
      # dependency that arrives prebuilt has to be linked, not absorbed.
      get_target_property(imported ${candidate} IMPORTED)
      if(type STREQUAL "STATIC_LIBRARY" AND NOT imported)
        list(APPEND collected "$<TARGET_OBJECTS:${candidate}>")
      endif()
    endif()
  endforeach()
  set(${out_var} "${collected}" PARENT_SCOPE)
endfunction()

# Our own components, discovered rather than listed.
#
# A hand-written list is the same bug this file exists to fix, one level up:
# someone adds a module, forgets the list, and the SDK ships without it —
# silently, because everything still builds and every in-tree test passes.
# Walking the build system means a component is in the SDK because it exists.
function(sdlstatic_sdk_find_components dir out_var)
  set(found "")
  get_property(targets DIRECTORY "${dir}" PROPERTY BUILDSYSTEM_TARGETS)
  foreach(target IN LISTS targets)
    if(target MATCHES "^SDLStatic_")
      get_target_property(type ${target} TYPE)
      if(type STREQUAL "STATIC_LIBRARY")
        list(APPEND found ${target})
      endif()
    endif()
  endforeach()
  get_property(subdirs DIRECTORY "${dir}" PROPERTY SUBDIRECTORIES)
  foreach(subdir IN LISTS subdirs)
    sdlstatic_sdk_find_components("${subdir}" _sub)
    list(APPEND found ${_sub})
  endforeach()
  set(${out_var} "${found}" PARENT_SCOPE)
endfunction()

sdlstatic_sdk_find_components("${CMAKE_CURRENT_SOURCE_DIR}" SDLSTATIC_SDK_COMPONENTS)
# The scaffold library carries the version API, which is public surface.
list(APPEND SDLSTATIC_SDK_COMPONENTS ${PROJECT_NAME}_lib)
# The SDK itself must not try to absorb itself if this file is re-included.
list(REMOVE_ITEM SDLSTATIC_SDK_COMPONENTS SDLStatic_SDK)
list(REMOVE_DUPLICATES SDLSTATIC_SDK_COMPONENTS)
message(STATUS "SDK: ${CMAKE_PROJECT_NAME} components folded in: ${SDLSTATIC_SDK_COMPONENTS}")

# Third-party code the components need. SDL3 is included deliberately: an
# extensions library that made you find and match your own SDL3 build would
# reintroduce exactly the version-mismatch problem static linking avoids.
set(SDLSTATIC_SDK_VENDORED
  SDL3-static
  freetype
  mbedtls mbedx509 mbedcrypto everest p256m
  miniz
  mog
)

sdlstatic_sdk_collect(_sdk_component_objects ${SDLSTATIC_SDK_COMPONENTS})
sdlstatic_sdk_collect(_sdk_vendored_objects ${SDLSTATIC_SDK_VENDORED})

add_library(SDLStatic_SDK STATIC ${_sdk_component_objects} ${_sdk_vendored_objects})
add_library(SDLStatic::SDK ALIAS SDLStatic_SDK)
add_library(${PROJECT_NAME}::SDK ALIAS SDLStatic_SDK)

set_target_properties(SDLStatic_SDK PROPERTIES
  OUTPUT_NAME SDL3_static_extensions_sdk
  EXPORT_NAME SDK
  POSITION_INDEPENDENT_CODE ON
  LINKER_LANGUAGE CXX
)

# The headers a consumer includes. Under BUILD_INTERFACE these are the source
# directories; from an install they are one flattened include tree, which is
# why the install rules below copy each component's include/ into the same
# place.
# A bare path here would be exported verbatim and point at this machine's
# build tree, so anything not already a generator expression is wrapped:
# these directories exist while building, and after an install the headers
# are somewhere else entirely.
function(sdlstatic_sdk_add_includes)
  foreach(dir IN LISTS ARGN)
    if(dir MATCHES "^\\$<")
      target_include_directories(SDLStatic_SDK INTERFACE "${dir}")
    else()
      target_include_directories(SDLStatic_SDK INTERFACE "$<BUILD_INTERFACE:${dir}>")
    endif()
  endforeach()
endfunction()

foreach(component IN LISTS SDLSTATIC_SDK_COMPONENTS)
  if(TARGET ${component})
    get_target_property(dirs ${component} INTERFACE_INCLUDE_DIRECTORIES)
    if(dirs)
      sdlstatic_sdk_add_includes(${dirs})
    endif()
  endif()
endforeach()
target_include_directories(SDLStatic_SDK INTERFACE
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# SDL3's headers are part of our public surface — <SDLStatic/engine.h> opens
# with #include <SDL3/SDL.h> — so a consumer needs them whether or not they
# call SDL3 directly.
# SDL3 keeps its headers on a separate interface target (SDL3::Headers)
# rather than on the library, so asking the library for them finds nothing.
set(_sdl3_includes "")
if(TARGET SDL3::Headers)
  get_target_property(_sdl3_includes SDL3::Headers INTERFACE_INCLUDE_DIRECTORIES)
endif()
if(NOT _sdl3_includes AND DEFINED sdl3_SOURCE_DIR)
  set(_sdl3_includes "${sdl3_SOURCE_DIR}/include")
endif()
if(_sdl3_includes)
  sdlstatic_sdk_add_includes(${_sdl3_includes})
endif()

# ---------------------------------------------------------------------------
# What the archive cannot contain: the operating system's own libraries.
#
# SDL3 knows which frameworks and system libraries it needs on each platform,
# and that list changes between SDL versions. Rather than copy it here and
# watch it rot, read it off the SDL3 target and keep the entries that are not
# CMake targets — those are the system libraries, and they are exactly what an
# installed consumer still has to link.
# ---------------------------------------------------------------------------
# SDL3 states these as generator expressions —
#
#   $<LINK_ONLY:m>
#   $<LINK_ONLY:$<LINK_LIBRARY:FRAMEWORK,Cocoa>>
#   $<LINK_ONLY:$<LINK_LIBRARY:WEAK_FRAMEWORK,CoreHaptics>>
#
# — so they have to be unwrapped rather than passed along. The frameworks
# become plain `-framework X` flags: the LINK_LIBRARY form needs CMake 3.24,
# and an installed SDK should not impose a newer CMake on its consumers than
# the project itself requires.
set(SDLSTATIC_SDK_SYSTEM_LIBS "")
set(_sdl_link_interface "")
foreach(sdl_target IN ITEMS SDL3-static SDL3::SDL3)
  if(TARGET ${sdl_target} AND NOT _sdl_link_interface)
    get_target_property(_sdl_link_interface ${sdl_target} INTERFACE_LINK_LIBRARIES)
  endif()
endforeach()

foreach(dep IN LISTS _sdl_link_interface)
  # $<LINK_ONLY:...> only says "link, do not propagate usage requirements",
  # which is already true of everything here.
  if(dep MATCHES "^\\$<LINK_ONLY:(.+)>$")
    set(dep "${CMAKE_MATCH_1}")
  endif()

  if(dep MATCHES "^\\$<LINK_LIBRARY:WEAK_FRAMEWORK,(.+)>$")
    list(APPEND SDLSTATIC_SDK_SYSTEM_LIBS "-weak_framework ${CMAKE_MATCH_1}")
  elseif(dep MATCHES "^\\$<LINK_LIBRARY:FRAMEWORK,(.+)>$")
    list(APPEND SDLSTATIC_SDK_SYSTEM_LIBS "-framework ${CMAKE_MATCH_1}")
  elseif(dep MATCHES "^\\$<TARGET_NAME:(.+)>$" OR dep MATCHES "^\\$<")
    # A target we have already absorbed, or an expression that names one.
    continue()
  elseif(TARGET ${dep})
    continue()
  elseif(dep)
    list(APPEND SDLSTATIC_SDK_SYSTEM_LIBS "${dep}")
  endif()
endforeach()

# The C++ runtime. The archive holds C++ objects — the C++ wrapper, Box2D's
# debug draw, parts of the GUI — so a consumer whose own project is C only
# links with the C driver and fails on a wall of missing std:: symbols, with
# nothing in the error naming the cause. Saying so here costs one entry and
# saves that afternoon.
if(NOT MSVC)
  if(APPLE OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    list(APPEND SDLSTATIC_SDK_SYSTEM_LIBS "c++")
  else()
    list(APPEND SDLSTATIC_SDK_SYSTEM_LIBS "stdc++")
  endif()
endif()

if(SDLSTATIC_SDK_SYSTEM_LIBS)
  list(REMOVE_DUPLICATES SDLSTATIC_SDK_SYSTEM_LIBS)
endif()
message(STATUS "SDK: system libraries a consumer still links: ${SDLSTATIC_SDK_SYSTEM_LIBS}")
target_link_libraries(SDLStatic_SDK INTERFACE ${SDLSTATIC_SDK_SYSTEM_LIBS})

# ---------------------------------------------------------------------------
# Installing
#
# Everything lands in one include tree and one lib directory, so an unpacked
# SDK looks the same as an installed prefix and both look like every other
# CMake package a consumer has used.
# ---------------------------------------------------------------------------
include(GNUInstallDirs)

# Each component's public headers. Read from the targets rather than listed
# by hand: a component that adds a header directory should not have to
# remember to update the install rules, because it will not.
set(_installed_include_dirs "")
foreach(component IN LISTS SDLSTATIC_SDK_COMPONENTS)
  if(NOT TARGET ${component})
    continue()
  endif()
  get_target_property(dirs ${component} INTERFACE_INCLUDE_DIRECTORIES)
  if(NOT dirs)
    continue()
  endif()
  foreach(dir IN LISTS dirs)
    # Only the build-tree side of the interface names a real directory;
    # $<INSTALL_INTERFACE:...> is where these headers are going, not where
    # they are.
    if(dir MATCHES "\\$<BUILD_INTERFACE:(.+)>")
      set(dir "${CMAKE_MATCH_1}")
    elseif(dir MATCHES "\\$<")
      continue()
    endif()
    if(IS_DIRECTORY "${dir}")
      list(APPEND _installed_include_dirs "${dir}")
    endif()
  endforeach()
endforeach()
if(_installed_include_dirs)
  list(REMOVE_DUPLICATES _installed_include_dirs)
endif()
foreach(dir IN LISTS _installed_include_dirs)
  install(DIRECTORY "${dir}/"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp" PATTERN "*.inl"
  )
endforeach()

# SDL3's headers, for the same reason its objects are in the archive: our
# public headers include them, so they are part of what we ship whether we
# like it or not.
if(_sdl3_includes)
  foreach(dir IN LISTS _sdl3_includes)
    if(dir MATCHES "\\$<BUILD_INTERFACE:(.+)>")
      set(dir "${CMAKE_MATCH_1}")
    elseif(dir MATCHES "\\$<")
      continue()
    endif()
    if(IS_DIRECTORY "${dir}")
      install(DIRECTORY "${dir}/"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING PATTERN "*.h"
      )
    endif()
  endforeach()
endif()

install(TARGETS SDLStatic_SDK
  EXPORT ${PROJECT_NAME}Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
