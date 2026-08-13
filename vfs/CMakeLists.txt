# SDLStatic::VFS — static-only build of vendored PhysFS 3.2.0 (zlib;
# provenance in deps/physfs.md) plus original SDLStatic glue for the
# encrypted-asset pipeline (folder -> zip -> SSE1 encrypt -> embed/ship ->
# decrypt -> mount from memory).
#
# Only the ZIP archiver and real-directory backend are compiled — the other
# nine formats (7z, GRP, WAD, HOG, MVL, QPAK, SLB, ISO9660, VDF) were
# deleted, not stubbed; PHYSFS_supportedArchiveTypes() reports the truth.

enable_language(C)
if(APPLE)
  enable_language(OBJC)
endif()

add_library(SDLStatic_VFS STATIC
  src/physfs/physfs.c
  src/physfs/physfs_byteorder.c
  src/physfs/physfs_unicode.c
  src/physfs/physfs_archiver_dir.c
  src/physfs/physfs_archiver_zip.c
  src/physfs/physfs_platform_posix.c
  src/physfs/physfs_platform_unix.c
  src/physfs/physfs_platform_windows.c
  src/physfs/physfs_platform_android.c
  # Original SDLStatic code (not vendored): encrypted mounts + SDL_IOStream.
  src/sdlstatic_vfs.c
)
if(APPLE)
  target_sources(SDLStatic_VFS PRIVATE src/physfs/physfs_platform_apple.m)
endif()
add_library(SDLStatic::VFS ALIAS SDLStatic_VFS)

if("c_std_99" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_VFS PRIVATE c_std_99)
endif()

set_target_properties(SDLStatic_VFS PROPERTIES
  OUTPUT_NAME SDLStatic_VFS
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_VFS
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_definitions(SDLStatic_VFS
  PUBLIC
    PHYSFS_STATIC
  PRIVATE
    PHYSFS_SUPPORTS_DEFAULT=0
    PHYSFS_SUPPORTS_ZIP=1
)

target_link_libraries(SDLStatic_VFS PUBLIC SDL3::SDL3 SDLStatic::Extras)
if(APPLE)
  target_link_libraries(SDLStatic_VFS PUBLIC "-framework Foundation" "-framework IOKit")
endif()
