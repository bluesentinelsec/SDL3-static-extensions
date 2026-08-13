# SDLStatic::Net — static-only build of the vendored SDL_net sources
# (upstream release-3.2.0, the NET_* API; provenance in deps/SDL3_net.md).
#
# SDL_net has no third-party dependencies at all: one portable C file over
# OS sockets. On Windows it links the OS-built-in iphlpapi/ws2_32; on Unix
# it needs nothing beyond libc. There is no web/Emscripten build — upstream
# only offers a stub there, and this project does not ship stubs.

enable_language(C)

add_library(SDLStatic_Net STATIC
  src/SDL_net.c
)
add_library(SDLStatic::Net ALIAS SDLStatic_Net)

if("c_std_99" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_Net PRIVATE c_std_99)
endif()

set_target_properties(SDLStatic_Net PROPERTIES
  OUTPUT_NAME SDLStatic_Net
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_Net
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Upstream probes for getifaddrs and defines HAVE_GETIFADDRS; without it the
# interface-enumeration path compiles to a do-nothing fallback and
# NET_GetLocalAddresses() reports zero interfaces (Windows has its own path).
if(NOT WIN32)
  include(CheckCSourceCompiles)
  check_c_source_compiles("
      #include <ifaddrs.h>
      int main(void) {
        struct ifaddrs* ifap;
        getifaddrs(&ifap);
        return 0;
      }
      " HAVE_GETIFADDRS)
  if(HAVE_GETIFADDRS)
    target_compile_definitions(SDLStatic_Net PRIVATE HAVE_GETIFADDRS)
  endif()
endif()

target_link_libraries(SDLStatic_Net PUBLIC SDL3::SDL3)
if(WIN32)
  # OS-built-in system libraries (not third-party): name resolution + winsock.
  target_link_libraries(SDLStatic_Net PRIVATE iphlpapi ws2_32)
endif()
