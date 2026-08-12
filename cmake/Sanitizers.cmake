# AddressSanitizer + UndefinedBehaviorSanitizer (GCC/Clang).
# Enable with -D<PROJECT>_ENABLE_SANITIZERS=ON (see `make sanitizer`).
# Intended primary platform: Linux. macOS is best-effort; MSVC is not supported here.
function(cppboot_enable_sanitizers)
  if(MSVC)
    message(FATAL_ERROR
      "Sanitizers via cppboot_enable_sanitizers() require GCC or Clang "
      "(not MSVC). Use Linux CI or a Clang toolset.")
  endif()
  if(NOT CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    message(FATAL_ERROR
      "Sanitizers require GNU or Clang (got ${CMAKE_CXX_COMPILER_ID}).")
  endif()

  message(STATUS "Enabling AddressSanitizer + UndefinedBehaviorSanitizer on project targets")
  add_compile_options(
    -fsanitize=address,undefined
    -fno-omit-frame-pointer
    -fno-sanitize-recover=all
    -g
  )
  add_link_options(
    -fsanitize=address,undefined
  )
endfunction()
