#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SDL3-static-extensions::SDK" for configuration "Debug"
set_property(TARGET SDL3-static-extensions::SDK APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SDL3-static-extensions::SDK PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C;CXX;OBJC;OBJCXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions_sdk.a"
  )

list(APPEND _cmake_import_check_targets SDL3-static-extensions::SDK )
list(APPEND _cmake_import_check_files_for_SDL3-static-extensions::SDK "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions_sdk.a" )

# Import target "SDL3-static-extensions::SDKCxx" for configuration "Debug"
set_property(TARGET SDL3-static-extensions::SDKCxx APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SDL3-static-extensions::SDKCxx PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C;CXX;OBJC;OBJCXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions_sdk_cxx.a"
  )

list(APPEND _cmake_import_check_targets SDL3-static-extensions::SDKCxx )
list(APPEND _cmake_import_check_files_for_SDL3-static-extensions::SDKCxx "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions_sdk_cxx.a" )

# Import target "SDL3-static-extensions::SDKShared" for configuration "Debug"
set_property(TARGET SDL3-static-extensions::SDKShared APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SDL3-static-extensions::SDKShared PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions.0.6.0.dylib"
  IMPORTED_SONAME_DEBUG "@rpath/libSDL3_static_extensions.0.dylib"
  )

list(APPEND _cmake_import_check_targets SDL3-static-extensions::SDKShared )
list(APPEND _cmake_import_check_files_for_SDL3-static-extensions::SDKShared "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions.0.6.0.dylib" )

# Import target "SDL3-static-extensions::SDKCxxShared" for configuration "Debug"
set_property(TARGET SDL3-static-extensions::SDKCxxShared APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SDL3-static-extensions::SDKCxxShared PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions_cxx.0.6.0.dylib"
  IMPORTED_SONAME_DEBUG "@rpath/libSDL3_static_extensions_cxx.0.dylib"
  )

list(APPEND _cmake_import_check_targets SDL3-static-extensions::SDKCxxShared )
list(APPEND _cmake_import_check_files_for_SDL3-static-extensions::SDKCxxShared "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions_cxx.0.6.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
