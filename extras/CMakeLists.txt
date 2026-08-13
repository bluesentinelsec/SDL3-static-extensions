# SDLStatic::Extras — original game-infrastructure modules (zlib), plus the
# vendored sdefl/sinfl DEFLATE single-headers (dual MIT/public-domain;
# provenance in deps/sdefl.md). Everything is plain C over SDL3 with zero
# external dependencies — fully static on every platform, web included.
#
#   <SDLStatic/crypto.h>    password-based asset encryption (ChaCha20 +
#                           PBKDF2-HMAC-SHA256, encrypt-then-MAC)
#   <SDLStatic/compress.h>  DEFLATE compress/decompress (raylib API shape)
#   <SDLStatic/base64.h>    Base64 encode/decode (raylib API shape)
#   <SDLStatic/signals.h>   Godot-style signal/observer system

enable_language(C)

add_library(SDLStatic_Extras STATIC
  src/sdlstatic_crypto.c
  src/sdlstatic_compress.c
  src/sdlstatic_base64.c
  src/sdlstatic_signals.c
)
add_library(SDLStatic::Extras ALIAS SDLStatic_Extras)

if("c_std_99" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_Extras PRIVATE c_std_99)
endif()

set_target_properties(SDLStatic_Extras PROPERTIES
  OUTPUT_NAME SDLStatic_Extras
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_Extras
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(SDLStatic_Extras PUBLIC SDL3::SDL3)
