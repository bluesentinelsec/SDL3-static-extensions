# The SDK as a consumer sees it: installed to a prefix, found with
# find_package, linked, and called into.
#
# Slower than a unit test because it installs and builds a second project,
# and worth it: this is the only check in the suite that would notice the
# library going hollow, which is exactly what happened for several releases
# while every other test passed.
# Not under sanitizers. The archive's objects carry ASan instrumentation and
# reference its runtime (___asan_init and friends), so an ordinary consumer
# cannot link them — correctly, because a sanitizer build is not something
# anyone ships. Propagating -fsanitize into the consumer would make the test
# pass without checking anything the other configurations do not already.
# Both spellings: the option, and the flags passed directly — CI uses one,
# a local sanitizer tree often the other, and the test is equally unlinkable
# either way.
set(_sdk_sanitized OFF)
if(SDL3_STATIC_EXTENSIONS_ENABLE_SANITIZERS
   OR CMAKE_C_FLAGS MATCHES "-fsanitize"
   OR CMAKE_CXX_FLAGS MATCHES "-fsanitize")
  set(_sdk_sanitized ON)
  message(STATUS "SDK: skipping the install-consumer test in a sanitizer build")
endif()

if(NOT _sdk_sanitized)
add_test(NAME sdk_install_consumer
  COMMAND ${CMAKE_COMMAND}
          -DBUILD_DIR=${CMAKE_BINARY_DIR}
          -DSOURCE_DIR=${CMAKE_SOURCE_DIR}
          # $<CONFIG> resolves when the test runs, which is the only moment
          # a multi-config generator knows which one it is.
          -DCONFIG=$<CONFIG>
          -P ${CMAKE_SOURCE_DIR}/scripts/verify_sdk_install.cmake
)
set_tests_properties(sdk_install_consumer PROPERTIES TIMEOUT 900)
endif()

# The runner, doing the thing it exists for: running a game script in either
# language, with the language inferred from the file's extension.
if(TARGET repl)
  foreach(lang lua rb)
    add_test(NAME runner_runs_${lang}_script
      COMMAND $<TARGET_FILE:repl> ${CMAKE_CURRENT_SOURCE_DIR}/hello.${lang}
    )
    set_tests_properties(runner_runs_${lang}_script PROPERTIES
      PASS_REGULAR_EXPRESSION "runner ok"
    )
  endforeach()
endif()

# The shared libraries, loaded from outside the C++ toolchain entirely.
#
# A C++ consumer proves very little about a shared library: it links through
# the same compiler that built it and never asks whether the symbols are
# exported. Python asks nothing of the build system — it opens the file and
# looks names up — which is what a plugin host or an FFI binding does.
# Not under sanitizers, for the same reason the install-consumer test is
# skipped there: the library's objects reference the ASan runtime, and a
# plain Python interpreter has not loaded it, so the dlopen fails on a
# missing __asan_* rather than on anything we did wrong.
if(TARGET SDLStatic_SDK_Shared AND NOT _sdk_sanitized)
  find_package(Python3 COMPONENTS Interpreter)
  if(Python3_Interpreter_FOUND)
    add_test(NAME shared_library_ctypes_c
      COMMAND ${Python3_EXECUTABLE}
              ${CMAKE_CURRENT_SOURCE_DIR}/../ctypes/test_shared_library.py
              $<TARGET_FILE:SDLStatic_SDK_Shared>
    )
    add_test(NAME shared_library_ctypes_cxx
      COMMAND ${Python3_EXECUTABLE}
              ${CMAKE_CURRENT_SOURCE_DIR}/../ctypes/test_shared_library.py
              $<TARGET_FILE:SDLStatic_SDK_Cxx_Shared> --cxx
    )
    set_tests_properties(shared_library_ctypes_c shared_library_ctypes_cxx
      PROPERTIES TIMEOUT 300)
  endif()
endif()
