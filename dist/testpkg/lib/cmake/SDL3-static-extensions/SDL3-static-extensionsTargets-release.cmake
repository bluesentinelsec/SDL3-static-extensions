#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SDL3-static-extensions::SDK" for configuration "Release"
set_property(TARGET SDL3-static-extensions::SDK APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SDL3-static-extensions::SDK PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX;OBJC;OBJCXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions_sdk.a"
  )

list(APPEND _cmake_import_check_targets SDL3-static-extensions::SDK )
list(APPEND _cmake_import_check_files_for_SDL3-static-extensions::SDK "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions_sdk.a" )

# Import target "SDL3-static-extensions::SDKCxx" for configuration "Release"
set_property(TARGET SDL3-static-extensions::SDKCxx APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SDL3-static-extensions::SDKCxx PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX;OBJC;OBJCXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions_sdk_cxx.a"
  )

list(APPEND _cmake_import_check_targets SDL3-static-extensions::SDKCxx )
list(APPEND _cmake_import_check_files_for_SDL3-static-extensions::SDKCxx "${_IMPORT_PREFIX}/lib/libSDL3_static_extensions_sdk_cxx.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
