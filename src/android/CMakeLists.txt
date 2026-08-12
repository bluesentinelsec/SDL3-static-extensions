# Android Prefab library. Gradle publishes this target as the `SDL3_static_extensions`
# module in the AAR. Whole-archive linking keeps every public C++ API symbol
# while folding the static core library into one shared object.
add_library(SDL3_static_extensions SHARED android_library.cpp)

target_compile_features(SDL3_static_extensions PUBLIC cxx_std_20)
target_include_directories(SDL3_static_extensions
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${SDL3_STATIC_EXTENSIONS_GENERATED_INCLUDE_DIR}>
)

add_dependencies(SDL3_static_extensions ${PROJECT_NAME}_lib)
target_link_options(SDL3_static_extensions
  PRIVATE
    "LINKER:--whole-archive,$<TARGET_FILE:${PROJECT_NAME}_lib>,--no-whole-archive"
)

set_target_properties(SDL3_static_extensions PROPERTIES
  OUTPUT_NAME SDL3_static_extensions
)

cppboot_set_project_warnings(SDL3_static_extensions)
