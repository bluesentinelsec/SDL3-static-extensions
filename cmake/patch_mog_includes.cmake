# Rewrites mog's module-name include()s to absolute paths. When mog is
# embedded via FetchContent, CMAKE_MODULE_PATH lists the PARENT project's
# cmake/ first, so `include(Dependencies)` finds our Dependencies.cmake
# instead of mog's and mog's mbedTLS/miniz never get declared (a latent bug
# in the shared cppboot template; tracked for an upstream fix in both).
file(READ CMakeLists.txt _mog_cml)
string(REPLACE "include(Dependencies)"
               "include(\"\${CMAKE_CURRENT_SOURCE_DIR}/cmake/Dependencies.cmake\")"
               _mog_cml "${_mog_cml}")
string(REPLACE "include(CompilerWarnings)"
               "include(\"\${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerWarnings.cmake\")"
               _mog_cml "${_mog_cml}")
string(REPLACE "include(Sanitizers)"
               "include(\"\${CMAKE_CURRENT_SOURCE_DIR}/cmake/Sanitizers.cmake\")"
               _mog_cml "${_mog_cml}")
file(WRITE CMakeLists.txt "${_mog_cml}")
