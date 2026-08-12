# SDLStatic::Image — static-link-first build of the vendored SDL3_image
# sources (upstream release-3.4.4; provenance in deps/SDL3_image.md).
#
# Heavy-codec translation units (AVIF, JXL, WEBP, TIFF, libpng, WIC, ImageIO)
# have been deleted outright along with their dispatch entries and public API
# declarations — unsupported formats fail at build time, not runtime (design
# no-stubs policy).
#
# Enabled loaders: BMP, GIF (incl. animation), JPG + PNG (stb_image backend),
# LBM, PCX, PNM, QOI, SVG (nanosvg), TGA, XCF, XPM, XV.
# Save support: PNG and JPG (SAVE_PNG / SAVE_JPG default on in the sources,
# backed by the vendored stb write / tiny_jpeg single-file encoders).

# The root project is CXX-only; the vendored SDL3_image sources are C.
enable_language(C)

add_library(SDLStatic_Image STATIC
  src/IMG.c
  src/IMG_ani.c
  src/IMG_anim_encoder.c
  src/IMG_anim_decoder.c
  src/IMG_bmp.c
  src/IMG_gif.c
  src/IMG_gpu.c
  src/IMG_jpg.c
  src/IMG_lbm.c
  src/IMG_pcx.c
  src/IMG_png.c
  src/IMG_pnm.c
  src/IMG_qoi.c
  src/IMG_stb.c
  src/IMG_svg.c
  src/IMG_tga.c
  src/IMG_xcf.c
  src/IMG_xpm.c
  src/IMG_xv.c
)
add_library(SDLStatic::Image ALIAS SDLStatic_Image)

if("c_std_99" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_Image PRIVATE c_std_99)
endif()

set_target_properties(SDLStatic_Image PROPERTIES
  OUTPUT_NAME SDLStatic_Image
  POSITION_INDEPENDENT_CODE ON
)

target_compile_definitions(SDLStatic_Image PRIVATE
  USE_STBIMAGE
  LOAD_BMP
  LOAD_GIF
  LOAD_JPG
  LOAD_PNG
  LOAD_LBM
  LOAD_PCX
  LOAD_PNM
  LOAD_QOI
  LOAD_SVG
  LOAD_TGA
  LOAD_XCF
  LOAD_XPM
  LOAD_XV
)

if(APPLE)
  # No ImageIO backend here (stb everywhere): upstream wraps the common C
  # decoders in `!defined(__APPLE__) || defined(SDL_IMAGE_USE_COMMON_BACKEND)`,
  # so this define is required on macOS/iOS or the format TUs compile empty.
  target_compile_definitions(SDLStatic_Image PRIVATE SDL_IMAGE_USE_COMMON_BACKEND)
endif()

target_include_directories(SDLStatic_Image
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(SDLStatic_Image PUBLIC SDL3::SDL3)

# Vendored upstream C: build quietly rather than under the project's
# warnings-as-errors regime; our own code around it stays strict.
