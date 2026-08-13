# SDLStatic::Formats — static-only build of three vendored data-format
# parsers for level files and game configs (provenance in deps/ *.md):
#
#   cJSON  v1.7.19  (MIT)  — JSON DOM parse/serialize      <cJSON.h>
#   tomlc99 29076df (MIT)  — TOML v1.0 config parsing      <toml.h>
#   libyaml 0.2.5   (MIT)  — YAML 1.1 parse/emit           <yaml.h>
#
# All three are plain C with zero external dependencies (they don't even
# need SDL), so the whole target is inherently static-link friendly on
# every platform, web included. Native upstream APIs are exposed directly.

enable_language(C)

add_library(SDLStatic_Formats STATIC
  src/cjson/cJSON.c
  src/tomlc99/toml.c
  src/libyaml/api.c
  src/libyaml/dumper.c
  src/libyaml/emitter.c
  src/libyaml/loader.c
  src/libyaml/parser.c
  src/libyaml/reader.c
  src/libyaml/scanner.c
  src/libyaml/writer.c
)
add_library(SDLStatic::Formats ALIAS SDLStatic_Formats)

if("c_std_99" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_Formats PRIVATE c_std_99)
endif()

set_target_properties(SDLStatic_Formats PROPERTIES
  OUTPUT_NAME SDLStatic_Formats
  POSITION_INDEPENDENT_CODE ON
)

target_include_directories(SDLStatic_Formats
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# libyaml expects its version macros from the build system, and
# YAML_DECLARE_STATIC selects static linkage on Windows.
target_compile_definitions(SDLStatic_Formats PRIVATE
  YAML_VERSION_MAJOR=0
  YAML_VERSION_MINOR=2
  YAML_VERSION_PATCH=5
  YAML_VERSION_STRING="0.2.5"
)
target_compile_definitions(SDLStatic_Formats PUBLIC
  YAML_DECLARE_STATIC
  CJSON_HIDE_SYMBOLS
)
