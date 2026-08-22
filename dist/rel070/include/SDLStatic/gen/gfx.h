// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: SDL3_gfx
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_GFX_H_
#define SDLSTATIC_CPP_GEN_GFX_H_

#include <SDL3_gfx/SDL3_gfxPrimitives.h>
#include <SDL3_gfx/SDL3_rotozoom.h>
#include <SDL3_gfx/SDL3_framerate.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace gfx {

// RAII owner for SDL_Surface (destroyed with SDL_DestroySurface).
class Surface {
 public:
  static Result<Surface> rotozoomSurface(SDL_Surface * src, double angle, double zoom, int smooth) {
    SDL_Surface* created_ = ::rotozoomSurface(src, angle, zoom, smooth);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> rotozoomSurfaceXY(SDL_Surface * src, double angle, double zoomx, double zoomy, int smooth) {
    SDL_Surface* created_ = ::rotozoomSurfaceXY(src, angle, zoomx, zoomy, smooth);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> zoomSurface(SDL_Surface * src, double zoomx, double zoomy, int smooth) {
    SDL_Surface* created_ = ::zoomSurface(src, zoomx, zoomy, smooth);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> shrinkSurface(SDL_Surface * src, int factorx, int factory) {
    SDL_Surface* created_ = ::shrinkSurface(src, factorx, factory);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> rotateSurface90Degrees(SDL_Surface* src, int numClockwiseTurns) {
    SDL_Surface* created_ = ::rotateSurface90Degrees(src, numClockwiseTurns);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }

  Surface() = default;
  ~Surface() { reset(); }
  Surface(Surface&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Surface& operator=(Surface&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Surface(const Surface&) = delete;
  Surface& operator=(const Surface&) = delete;

  SDL_Surface* get() const { return value_; }
  SDL_Surface* release() {
    SDL_Surface* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroySurface(value_);
    value_ = nullptr;
    engaged_ = false;
  }

 private:
  explicit Surface(SDL_Surface* value) : value_(value), engaged_(true) {}
  SDL_Surface* value_{};
  bool engaged_ = false;
};

// bool-returning C functions surfaced as Status.
inline Status aacircleColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Uint32 color) {
  return ::aacircleColor(renderer, x, y, rad, color) ? Status() : Status::FromSdl();
}
inline Status aacircleRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::aacircleRGBA(renderer, x, y, rad, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status aaellipseColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color) {
  return ::aaellipseColor(renderer, x, y, rx, ry, color) ? Status() : Status::FromSdl();
}
inline Status aaellipseRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::aaellipseRGBA(renderer, x, y, rx, ry, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status aalineColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color) {
  return ::aalineColor(renderer, x1, y1, x2, y2, color) ? Status() : Status::FromSdl();
}
inline Status aalineRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::aalineRGBA(renderer, x1, y1, x2, y2, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status aapolygonColor(SDL_Renderer * renderer, const Sint16 * vx, const Sint16 * vy, int n, Uint32 color) {
  return ::aapolygonColor(renderer, vx, vy, n, color) ? Status() : Status::FromSdl();
}
inline Status aapolygonRGBA(SDL_Renderer * renderer, const Sint16 * vx, const Sint16 * vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::aapolygonRGBA(renderer, vx, vy, n, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status aatrigonColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint32 color) {
  return ::aatrigonColor(renderer, x1, y1, x2, y2, x3, y3, color) ? Status() : Status::FromSdl();
}
inline Status aatrigonRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::aatrigonRGBA(renderer, x1, y1, x2, y2, x3, y3, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status arcColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint32 color) {
  return ::arcColor(renderer, x, y, rad, start, end, color) ? Status() : Status::FromSdl();
}
inline Status arcRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::arcRGBA(renderer, x, y, rad, start, end, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status bezierColor(SDL_Renderer * renderer, const Sint16 * vx, const Sint16 * vy, int n, int s, Uint32 color) {
  return ::bezierColor(renderer, vx, vy, n, s, color) ? Status() : Status::FromSdl();
}
inline Status bezierRGBA(SDL_Renderer * renderer, const Sint16 * vx, const Sint16 * vy, int n, int s, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::bezierRGBA(renderer, vx, vy, n, s, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status boxColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color) {
  return ::boxColor(renderer, x1, y1, x2, y2, color) ? Status() : Status::FromSdl();
}
inline Status boxRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::boxRGBA(renderer, x1, y1, x2, y2, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status characterColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, char c, Uint32 color) {
  return ::characterColor(renderer, x, y, c, color) ? Status() : Status::FromSdl();
}
inline Status characterRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, char c, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::characterRGBA(renderer, x, y, c, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status circleColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Uint32 color) {
  return ::circleColor(renderer, x, y, rad, color) ? Status() : Status::FromSdl();
}
inline Status circleRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::circleRGBA(renderer, x, y, rad, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status ellipseColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color) {
  return ::ellipseColor(renderer, x, y, rx, ry, color) ? Status() : Status::FromSdl();
}
inline Status ellipseRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::ellipseRGBA(renderer, x, y, rx, ry, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status filledCircleColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 r, Uint32 color) {
  return ::filledCircleColor(renderer, x, y, r, color) ? Status() : Status::FromSdl();
}
inline Status filledCircleRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::filledCircleRGBA(renderer, x, y, rad, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status filledEllipseColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color) {
  return ::filledEllipseColor(renderer, x, y, rx, ry, color) ? Status() : Status::FromSdl();
}
inline Status filledEllipseRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::filledEllipseRGBA(renderer, x, y, rx, ry, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status filledPieColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint32 color) {
  return ::filledPieColor(renderer, x, y, rad, start, end, color) ? Status() : Status::FromSdl();
}
inline Status filledPieRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::filledPieRGBA(renderer, x, y, rad, start, end, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status filledPolygonColor(SDL_Renderer * renderer, const Sint16 * vx, const Sint16 * vy, int n, Uint32 color) {
  return ::filledPolygonColor(renderer, vx, vy, n, color) ? Status() : Status::FromSdl();
}
inline Status filledPolygonRGBA(SDL_Renderer * renderer, const Sint16 * vx, const Sint16 * vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::filledPolygonRGBA(renderer, vx, vy, n, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status filledTrigonColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint32 color) {
  return ::filledTrigonColor(renderer, x1, y1, x2, y2, x3, y3, color) ? Status() : Status::FromSdl();
}
inline Status filledTrigonRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::filledTrigonRGBA(renderer, x1, y1, x2, y2, x3, y3, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status hlineColor(SDL_Renderer * renderer, Sint16 x1, Sint16 x2, Sint16 y, Uint32 color) {
  return ::hlineColor(renderer, x1, x2, y, color) ? Status() : Status::FromSdl();
}
inline Status hlineRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 x2, Sint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::hlineRGBA(renderer, x1, x2, y, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status lineColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color) {
  return ::lineColor(renderer, x1, y1, x2, y2, color) ? Status() : Status::FromSdl();
}
inline Status lineRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::lineRGBA(renderer, x1, y1, x2, y2, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status pieColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint32 color) {
  return ::pieColor(renderer, x, y, rad, start, end, color) ? Status() : Status::FromSdl();
}
inline Status pieRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::pieRGBA(renderer, x, y, rad, start, end, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status pixelColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Uint32 color) {
  return ::pixelColor(renderer, x, y, color) ? Status() : Status::FromSdl();
}
inline Status pixelRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::pixelRGBA(renderer, x, y, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status polygonColor(SDL_Renderer * renderer, const Sint16 * vx, const Sint16 * vy, int n, Uint32 color) {
  return ::polygonColor(renderer, vx, vy, n, color) ? Status() : Status::FromSdl();
}
inline Status polygonRGBA(SDL_Renderer * renderer, const Sint16 * vx, const Sint16 * vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::polygonRGBA(renderer, vx, vy, n, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status rectangleColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color) {
  return ::rectangleColor(renderer, x1, y1, x2, y2, color) ? Status() : Status::FromSdl();
}
inline Status rectangleRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::rectangleRGBA(renderer, x1, y1, x2, y2, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status roundedBoxColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 rad, Uint32 color) {
  return ::roundedBoxColor(renderer, x1, y1, x2, y2, rad, color) ? Status() : Status::FromSdl();
}
inline Status roundedBoxRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::roundedBoxRGBA(renderer, x1, y1, x2, y2, rad, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status roundedRectangleColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 rad, Uint32 color) {
  return ::roundedRectangleColor(renderer, x1, y1, x2, y2, rad, color) ? Status() : Status::FromSdl();
}
inline Status roundedRectangleRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::roundedRectangleRGBA(renderer, x1, y1, x2, y2, rad, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status stringColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, const char *s, Uint32 color) {
  return ::stringColor(renderer, x, y, s, color) ? Status() : Status::FromSdl();
}
inline Status stringRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, const char *s, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::stringRGBA(renderer, x, y, s, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status texturedPolygon(SDL_Renderer * renderer, const Sint16 * vx, const Sint16 * vy, int n, SDL_Surface * texture, int texture_dx, int texture_dy) {
  return ::texturedPolygon(renderer, vx, vy, n, texture, texture_dx, texture_dy) ? Status() : Status::FromSdl();
}
inline Status thickLineColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 width, Uint32 color) {
  return ::thickLineColor(renderer, x1, y1, x2, y2, width, color) ? Status() : Status::FromSdl();
}
inline Status thickLineRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 width, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::thickLineRGBA(renderer, x1, y1, x2, y2, width, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status trigonColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint32 color) {
  return ::trigonColor(renderer, x1, y1, x2, y2, x3, y3, color) ? Status() : Status::FromSdl();
}
inline Status trigonRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::trigonRGBA(renderer, x1, y1, x2, y2, x3, y3, r, g, b, a) ? Status() : Status::FromSdl();
}
inline Status vlineColor(SDL_Renderer * renderer, Sint16 x, Sint16 y1, Sint16 y2, Uint32 color) {
  return ::vlineColor(renderer, x, y1, y2, color) ? Status() : Status::FromSdl();
}
inline Status vlineRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y1, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  return ::vlineRGBA(renderer, x, y1, y2, r, g, b, a) ? Status() : Status::FromSdl();
}

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& SDL_framerateDelay = ::SDL_framerateDelay;
inline constexpr auto& SDL_getFramecount = ::SDL_getFramecount;
inline constexpr auto& SDL_getFramerate = ::SDL_getFramerate;
inline constexpr auto& SDL_initFramerate = ::SDL_initFramerate;
inline constexpr auto& SDL_setFramerate = ::SDL_setFramerate;
inline constexpr auto& gfxPrimitivesSetFont = ::gfxPrimitivesSetFont;
inline constexpr auto& gfxPrimitivesSetFontRotation = ::gfxPrimitivesSetFontRotation;
inline constexpr auto& rotozoomSurfaceSize = ::rotozoomSurfaceSize;
inline constexpr auto& rotozoomSurfaceSizeXY = ::rotozoomSurfaceSizeXY;
inline constexpr auto& zoomSurfaceSize = ::zoomSurfaceSize;

}  // namespace gfx
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_GFX_H_
// clang-format on
