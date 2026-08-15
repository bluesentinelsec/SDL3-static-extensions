# SDLStatic::Regex — regular expressions over vendored Oniguruma (BSD-2,
# provenance in deps/oniguruma.md). Oniguruma is pure C with no external
# dependencies, so it links statically everywhere we ship, web included.
#
#   <SDLStatic/regex.h>  compile / search / groups / replace, Ruby syntax
#
# Oniguruma normally configures itself with autotools; we generate the same
# config.h from CMake's own probes so the build stays plain CMake.
enable_language(C)

include(CheckIncludeFile)
include(CheckSymbolExists)
include(CheckTypeSize)

set(ONIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/oniguruma)

check_include_file(alloca.h HAVE_ALLOCA_H)
check_include_file(stdint.h HAVE_STDINT_H)
check_include_file(inttypes.h HAVE_INTTYPES_H)
check_include_file(sys/types.h HAVE_SYS_TYPES_H)
check_include_file(sys/time.h HAVE_SYS_TIME_H)
check_include_file(sys/times.h HAVE_SYS_TIMES_H)
check_include_file(unistd.h HAVE_UNISTD_H)
check_symbol_exists(alloca "stdlib.h;alloca.h" HAVE_ALLOCA)
check_type_size(int SIZEOF_INT)
check_type_size(long SIZEOF_LONG)
check_type_size("long long" SIZEOF_LONG_LONG)
check_type_size("void*" SIZEOF_VOIDP)

set(PACKAGE "oniguruma")
set(PACKAGE_VERSION "6.9.10")
set(VERSION "6.9.10")
configure_file(${ONIG_DIR}/src/config.h.cmake.in
               ${CMAKE_CURRENT_BINARY_DIR}/onig-config/config.h)

# Upstream's own translation-unit list (src/Makefile.am). A glob would be
# wrong twice over: the unicode_*_data.c tables are #included by unicode.c
# rather than compiled, and the POSIX shim (regposix.c) defines regcomp and
# regexec, which would collide with libc's in a static link. Everything is
# still vendored; this only decides what is compiled.
set(SDLSTATIC_ONIG_NAMES
  regparse.c regcomp.c regexec.c
  regenc.c regerror.c regext.c regsyntax.c regtrav.c regversion.c st.c
  reggnu.c
  unicode.c unicode_unfold_key.c
  unicode_fold1_key.c unicode_fold2_key.c unicode_fold3_key.c
  ascii.c utf8.c
  utf16_be.c utf16_le.c utf32_be.c utf32_le.c
  euc_jp.c euc_jp_prop.c sjis.c sjis_prop.c
  iso8859_1.c iso8859_2.c iso8859_3.c iso8859_4.c iso8859_5.c
  iso8859_6.c iso8859_7.c iso8859_8.c iso8859_9.c iso8859_10.c
  iso8859_11.c iso8859_13.c iso8859_14.c iso8859_15.c iso8859_16.c
  euc_tw.c euc_kr.c big5.c gb18030.c koi8_r.c cp1251.c
  onig_init.c
)
set(SDLSTATIC_ONIG_SOURCES "")
foreach(name IN LISTS SDLSTATIC_ONIG_NAMES)
  list(APPEND SDLSTATIC_ONIG_SOURCES ${ONIG_DIR}/src/${name})
endforeach()

add_library(SDLStatic_Regex STATIC
  src/sdlstatic_regex.c
  ${SDLSTATIC_ONIG_SOURCES}
)
add_library(SDLStatic::Regex ALIAS SDLStatic_Regex)

set_target_properties(SDLStatic_Regex PROPERTIES
  OUTPUT_NAME SDLStatic_Regex
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_Regex
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
# SYSTEM so Oniguruma's own warnings never reach a consumer's -Werror.
target_include_directories(SDLStatic_Regex SYSTEM PRIVATE
  ${ONIG_DIR}/src
  ${CMAKE_CURRENT_BINARY_DIR}/onig-config
)

# ONIG_EXTERN must not expand to a dllimport/visibility attribute: the
# engine is compiled into this archive, never a shared object.
target_compile_definitions(SDLStatic_Regex PRIVATE HAVE_CONFIG_H ONIG_EXTERN=extern)

# Oniguruma is third-party: build it as it is rather than patching warnings.
if(NOT MSVC)
  set_source_files_properties(${SDLSTATIC_ONIG_SOURCES} PROPERTIES COMPILE_OPTIONS "-w")
endif()

target_link_libraries(SDLStatic_Regex PUBLIC SDL3::SDL3)
