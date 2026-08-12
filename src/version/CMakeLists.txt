# version component — generated from cmake/version.{hpp,cpp}.in + VERSION file.
# Edit the root VERSION file only; do not hand-edit the generated sources.
target_sources(${PROJECT_NAME}_lib
  PRIVATE
    ${SDL3_STATIC_EXTENSIONS_GENERATED_DIR}/version.cpp
)
