#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mog::lib" for configuration "Debug"
set_property(TARGET mog::lib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(mog::lib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX;OBJCXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libmog.a"
  )

list(APPEND _cmake_import_check_targets mog::lib )
list(APPEND _cmake_import_check_files_for_mog::lib "${_IMPORT_PREFIX}/lib/libmog.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
