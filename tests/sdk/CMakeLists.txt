# The SDK as a consumer sees it: installed to a prefix, found with
# find_package, linked, and called into.
#
# Slower than a unit test because it installs and builds a second project,
# and worth it: this is the only check in the suite that would notice the
# library going hollow, which is exactly what happened for several releases
# while every other test passed.
add_test(NAME sdk_install_consumer
  COMMAND ${CMAKE_COMMAND}
          -DBUILD_DIR=${CMAKE_BINARY_DIR}
          -DSOURCE_DIR=${CMAKE_SOURCE_DIR}
          -P ${CMAKE_SOURCE_DIR}/scripts/verify_sdk_install.cmake
)
set_tests_properties(sdk_install_consumer PROPERTIES TIMEOUT 900)

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
