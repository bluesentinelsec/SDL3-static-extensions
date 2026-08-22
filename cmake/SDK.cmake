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
# Named as the targets actually are, which is not always the obvious thing:
# mog's C++ core is `mog_lib`, while `mog` is its own Android shared library
# and has no objects to give. Getting that wrong is silent — the collector
# skips what it cannot use — so the check below fails the build instead.
set(SDLSTATIC_SDK_VENDORED
  SDL3-static
  freetype
  mbedtls mbedx509 mbedcrypto everest p256m
  miniz
  mog_lib
)

sdlstatic_sdk_collect(_sdk_component_objects ${SDLSTATIC_SDK_COMPONENTS})
sdlstatic_sdk_collect(_sdk_vendored_objects ${SDLSTATIC_SDK_VENDORED})

# A vendored dependency that is built but not folded in produces an archive
# that links for anyone who does not happen to call it — which is how the
# HTTP core went missing without a single test noticing. If a component is
# enabled, the library underneath it has to be in the archive.
set(_folded "")
foreach(candidate IN LISTS SDLSTATIC_SDK_VENDORED)
  list(FIND _sdk_vendored_objects "$<TARGET_OBJECTS:${candidate}>" _at)
  if(NOT _at EQUAL -1)
    list(APPEND _folded ${candidate})
  endif()
endforeach()
message(STATUS "SDK: vendored libraries folded in: ${_folded}")

foreach(required IN ITEMS SDL3-static mog_lib freetype)
  if(TARGET ${required})
    list(FIND _sdk_vendored_objects "$<TARGET_OBJECTS:${required}>" _found)
    if(_found EQUAL -1)
      message(FATAL_ERROR
        "${required} exists in this build but contributes no objects to the "
        "SDK — it is probably not a static library under this configuration, "
        "and anything depending on it will fail to link for a consumer.")
    endif()
  endif()
endforeach()

# The anchor is C, and the components enable C in their own directories —
# this file runs in the root scope, where the project declared only C++.
enable_language(C)

# The anchor source is not optional: see cmake/sdk_anchor.c. A static library
# built purely from other targets' objects produces no archive under the
# Xcode generator, and reports success while doing it.
add_library(SDLStatic_SDK STATIC
  ${CMAKE_CURRENT_LIST_DIR}/sdk_anchor.c
  ${_sdk_component_objects}
  ${_sdk_vendored_objects}
)
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

# ---------------------------------------------------------------------------
# Xcode: assemble by merging archives instead of collecting objects
#
# When two source files in one target share a basename — mog has two
# prepare.cpp — Xcode disambiguates the object files by hashing the path.
# Those hashed objects are then missing from a $<TARGET_OBJECTS:...>
# aggregation, and the resulting archive links for anyone who does not call
# the code that went missing. Ours had 803 members and no prepare.o, so the
# HTTP backend was half there.
#
# libtool merges archives by content and does not care what the members are
# called, which is why the platform's own tool is the right answer here. The
# object list is left in place: it is what every other generator uses, and
# the merge only adds what Xcode dropped.
# ---------------------------------------------------------------------------
if(CMAKE_GENERATOR STREQUAL "Xcode")
  set(_sdk_archives "")
  foreach(target IN LISTS SDLSTATIC_SDK_COMPONENTS SDLSTATIC_SDK_VENDORED)
    if(NOT TARGET ${target})
      continue()
    endif()
    get_target_property(type ${target} TYPE)
    get_target_property(imported ${target} IMPORTED)
    if(type STREQUAL "STATIC_LIBRARY" AND NOT imported)
      list(APPEND _sdk_archives "$<TARGET_FILE:${target}>")
      add_dependencies(SDLStatic_SDK ${target})
    endif()
  endforeach()

  if(_sdk_archives)
    add_custom_command(TARGET SDLStatic_SDK POST_BUILD
      COMMAND libtool -static -no_warning_for_no_symbols
              -o "$<TARGET_FILE:SDLStatic_SDK>.merged"
              "$<TARGET_FILE:SDLStatic_SDK>" ${_sdk_archives}
      COMMAND ${CMAKE_COMMAND} -E rename
              "$<TARGET_FILE:SDLStatic_SDK>.merged" "$<TARGET_FILE:SDLStatic_SDK>"
      COMMENT "Merging component archives into the SDK (Xcode)"
      VERBATIM
    )
  endif()
endif()

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
# Every folded-in target's system libraries, not just SDL3's.
#
# The archive holds the objects; it cannot hold ws2_32, winhttp or Cocoa. A
# consumer still links those, and which ones depends on what is inside —
# SDL_net wants the socket libraries, mog's WinHTTP backend wants winhttp,
# SDL3 wants a dozen frameworks on Apple. Reading SDL3's list alone was
# enough only until the consumer test called something other than the engine.
#
# Both link properties are read: for a static library the private
# dependencies do not disappear, they defer to whoever links it.
#
# The entries arrive as generator expressions —
#
#   $<LINK_ONLY:m>
#   $<LINK_ONLY:$<LINK_LIBRARY:FRAMEWORK,Cocoa>>
#
# — so they are unwrapped here. Frameworks become plain `-framework X`
# flags: the LINK_LIBRARY form needs CMake 3.24, and an installed SDK should
# not impose a newer CMake on its consumers than the project itself requires.
function(sdlstatic_sdk_system_libs out_var)
  set(collected "")
  foreach(target IN LISTS ARGN)
    if(NOT TARGET ${target})
      continue()
    endif()
    set(deps "")
    foreach(property INTERFACE_LINK_LIBRARIES LINK_LIBRARIES)
      get_target_property(value ${target} ${property})
      if(value)
        list(APPEND deps ${value})
      endif()
    endforeach()

    foreach(dep IN LISTS deps)
      # $<LINK_ONLY:...> only says "link, do not propagate usage
      # requirements", which is already true of everything here.
      if(dep MATCHES "^\\$<LINK_ONLY:(.+)>$")
        set(dep "${CMAKE_MATCH_1}")
      endif()

      if(dep MATCHES "^\\$<LINK_LIBRARY:WEAK_FRAMEWORK,(.+)>$")
        list(APPEND collected "-weak_framework ${CMAKE_MATCH_1}")
      elseif(dep MATCHES "^\\$<LINK_LIBRARY:FRAMEWORK,(.+)>$")
        list(APPEND collected "-framework ${CMAKE_MATCH_1}")
      elseif(dep MATCHES "^\\$<TARGET_NAME:(.+)>$" OR dep MATCHES "^\\$<")
        # A target we have already absorbed, or an expression naming one.
        continue()
      elseif(TARGET ${dep})
        continue()
      elseif(dep STREQUAL "Threads::Threads")
        # A real requirement wearing a target's name. if(TARGET) misses it
        # because an imported target is only visible in the scope that
        # created it, so translate it to the flag it stands for — on most
        # Linux distributions that is now empty, since libpthread was folded
        # into libc, and on the ones where it is not, this is what breaks.
        if(CMAKE_THREAD_LIBS_INIT)
          list(APPEND collected "${CMAKE_THREAD_LIBS_INIT}")
        endif()
      elseif(dep MATCHES "::")
        # CMake's own directory-scope markers (`::@(0x...)`) and any other
        # namespaced target. Nothing with a `::` in it is a system library.
        continue()
      elseif(dep MATCHES "^-")
        # A raw linker flag someone set deliberately.
        list(APPEND collected "${dep}")
      elseif(dep)
        list(APPEND collected "${dep}")
      endif()
    endforeach()
  endforeach()
  set(${out_var} "${collected}" PARENT_SCOPE)
endfunction()

sdlstatic_sdk_system_libs(SDLSTATIC_SDK_SYSTEM_LIBS
  ${SDLSTATIC_SDK_COMPONENTS} ${SDLSTATIC_SDK_VENDORED} SDL3::SDL3)

# The C++ runtime. The archive holds C++ objects — the C++ wrapper, Box2D's
# debug draw, parts of the GUI — so a consumer whose own project is C only
# links with the C driver and fails on a wall of missing std:: symbols with
# nothing in the error naming the cause.
#
# Which runtime that is cannot be guessed from the compiler: Clang means
# libc++ on macOS and libstdc++ on a stock Ubuntu, and guessing wrong fails
# with `cannot find -lc++`, which is a worse error than the one it set out
# to prevent. Ask the toolchain what it links C++ programs against instead.
foreach(implicit IN LISTS CMAKE_CXX_IMPLICIT_LINK_LIBRARIES)
  if(implicit MATCHES "^(std)?c\\+\\+$")
    list(APPEND SDLSTATIC_SDK_SYSTEM_LIBS "${implicit}")
  endif()
endforeach()

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
# Turn an interface include list into real directories: strip the
# $<BUILD_INTERFACE:...> wrapper, drop anything else expressed as a
# generator expression (it describes where headers are *going*, not where
# they are), and keep what exists on disk.
function(sdlstatic_sdk_real_dirs out_var)
  set(dirs "")
  foreach(dir IN LISTS ARGN)
    if(dir MATCHES "\\$<BUILD_INTERFACE:(.+)>")
      set(dir "${CMAKE_MATCH_1}")
    elseif(dir MATCHES "\\$<")
      continue()
    endif()
    if(IS_DIRECTORY "${dir}")
      list(APPEND dirs "${dir}")
    endif()
  endforeach()
  if(dirs)
    list(REMOVE_DUPLICATES dirs)
  endif()
  set(${out_var} "${dirs}" PARENT_SCOPE)
endfunction()

include(GNUInstallDirs)

# Each component's public headers. Read from the targets rather than listed
# by hand: a component that adds a header directory should not have to
# remember to update the install rules, because it will not.
set(_interface_dirs "")
foreach(component IN LISTS SDLSTATIC_SDK_COMPONENTS)
  if(TARGET ${component})
    get_target_property(dirs ${component} INTERFACE_INCLUDE_DIRECTORIES)
    if(dirs)
      list(APPEND _interface_dirs ${dirs})
    endif()
  endif()
endforeach()
sdlstatic_sdk_real_dirs(_installed_include_dirs ${_interface_dirs})
sdlstatic_sdk_real_dirs(_sdl3_header_dirs ${_sdl3_includes})
foreach(dir IN LISTS _installed_include_dirs)
  install(DIRECTORY "${dir}/"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp" PATTERN "*.inl"
  )
endforeach()

# SDL3's headers, for the same reason its objects are in the archive: our
# public headers include them, so they are part of what we ship whether we
# like it or not.
foreach(dir IN LISTS _sdl3_header_dirs)
  install(DIRECTORY "${dir}/"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
  )
endforeach()

install(TARGETS SDLStatic_SDK
  EXPORT ${PROJECT_NAME}Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# ---------------------------------------------------------------------------
# Android: SDL3's Java glue
#
# Loading a shared object that contains SDL3 runs its JNI_OnLoad, which looks
# up org.libsdl.app.SDLActivity and aborts the process if it is missing:
#
#   ClassNotFoundException: org.libsdl.app.SDLActivity
#     at java.lang.Runtime.nativeLoad
#
# So the AAR has to carry SDL's Java classes as well as its objects. It never
# did, and nothing noticed, because the library it shipped had no SDL3 in it
# to ask for them.
#
# The copy happens at configure time rather than build time: Gradle compiles
# Java on its own schedule, and a source directory that fills in later is a
# source directory that was empty when it mattered.
# ---------------------------------------------------------------------------
if(ANDROID AND SDLSTATIC_ANDROID_JAVA_DIR AND DEFINED sdl3_SOURCE_DIR)
  set(_sdl_java "${sdl3_SOURCE_DIR}/android-project/app/src/main/java")
  if(IS_DIRECTORY "${_sdl_java}")
    file(COPY "${_sdl_java}/" DESTINATION "${SDLSTATIC_ANDROID_JAVA_DIR}"
         FILES_MATCHING PATTERN "*.java")
    message(STATUS "SDK: staged SDL3's Java classes into ${SDLSTATIC_ANDROID_JAVA_DIR}")
  else()
    message(FATAL_ERROR
      "SDL3's Android Java sources are missing from ${_sdl_java}. An AAR "
      "without them aborts on load with ClassNotFoundException.")
  endif()
endif()

# ---------------------------------------------------------------------------
# Android: staging headers into the Prefab package
#
# Gradle snapshots a header directory into the AAR, and its own task runs at
# preBuild — before CMake has configured, and so before SDL3 has even been
# downloaded. That is why the AAR shipped version.hpp and nothing else: at
# the moment Gradle looked, nothing else existed.
#
# Staging them from here instead means it happens after the native build,
# from the same directory list the desktop SDK installs, so the two cannot
# drift apart.
# ---------------------------------------------------------------------------
if(ANDROID AND SDLSTATIC_ANDROID_PREFAB_HEADERS AND TARGET SDL3_static_extensions)
  set(_stage_commands "")
  foreach(dir IN LISTS _installed_include_dirs _sdl3_header_dirs)
    list(APPEND _stage_commands
      COMMAND ${CMAKE_COMMAND} -E copy_directory
              "${dir}" "${SDLSTATIC_ANDROID_PREFAB_HEADERS}")
  endforeach()
  if(_stage_commands)
    # A custom target rather than POST_BUILD: add_custom_command(TARGET ...)
    # only works in the directory that created the target, and the Android
    # library is created in src/android while the header list is only known
    # here, after every component has been added.
    add_custom_target(sdlstatic_stage_prefab_headers
      ${_stage_commands}
      COMMENT "Staging public headers into the Prefab package"
      VERBATIM
    )
    add_dependencies(SDL3_static_extensions sdlstatic_stage_prefab_headers)
  endif()
endif()
