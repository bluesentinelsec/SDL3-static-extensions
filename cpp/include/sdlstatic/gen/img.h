// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: SDL_image
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_IMG_H_
#define SDLSTATIC_CPP_GEN_IMG_H_

#include <SDL3_image/SDL_image.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace img {

// RAII owner for IMG_Animation (destroyed with IMG_FreeAnimation).
class Animation {
 public:
  static Result<Animation> LoadAnimation(const char *file) {
    IMG_Animation* created_ = ::IMG_LoadAnimation(file);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Animation(created_);
  }
  static Result<Animation> LoadAnimation_IO(SDL_IOStream *src, bool closeio) {
    IMG_Animation* created_ = ::IMG_LoadAnimation_IO(src, closeio);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Animation(created_);
  }
  static Result<Animation> LoadAnimationTyped_IO(SDL_IOStream *src, bool closeio, const char *type) {
    IMG_Animation* created_ = ::IMG_LoadAnimationTyped_IO(src, closeio, type);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Animation(created_);
  }

  Animation() = default;
  ~Animation() { reset(); }
  Animation(Animation&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Animation& operator=(Animation&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Animation(const Animation&) = delete;
  Animation& operator=(const Animation&) = delete;

  IMG_Animation* get() const { return value_; }
  IMG_Animation* release() {
    IMG_Animation* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::IMG_FreeAnimation(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status SaveAnimation(const char *file) {
    return ::IMG_SaveAnimation(value_, file) ? Status() : Status::FromSdl();
  }
  Status SaveAnimationTyped_IO(SDL_IOStream *dst, bool closeio, const char *type) {
    return ::IMG_SaveAnimationTyped_IO(value_, dst, closeio, type) ? Status() : Status::FromSdl();
  }
  Status SaveANIAnimation_IO(SDL_IOStream *dst, bool closeio) {
    return ::IMG_SaveANIAnimation_IO(value_, dst, closeio) ? Status() : Status::FromSdl();
  }
  Status SaveGIFAnimation_IO(SDL_IOStream *dst, bool closeio) {
    return ::IMG_SaveGIFAnimation_IO(value_, dst, closeio) ? Status() : Status::FromSdl();
  }
  SDL_Cursor* CreateAnimatedCursor(int hot_x, int hot_y) {
    return ::IMG_CreateAnimatedCursor(value_, hot_x, hot_y);
  }
 private:
  explicit Animation(IMG_Animation* value) : value_(value), engaged_(true) {}
  IMG_Animation* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Surface (destroyed with SDL_DestroySurface).
class Surface {
 public:
  static Result<Surface> Load(const char *file) {
    SDL_Surface* created_ = ::IMG_Load(file);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> Load_IO(SDL_IOStream *src, bool closeio) {
    SDL_Surface* created_ = ::IMG_Load_IO(src, closeio);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> LoadTyped_IO(SDL_IOStream *src, bool closeio, const char *type) {
    SDL_Surface* created_ = ::IMG_LoadTyped_IO(src, closeio, type);
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

  Status Save(const char *file) {
    return ::IMG_Save(value_, file) ? Status() : Status::FromSdl();
  }
  Status SaveTyped_IO(SDL_IOStream *dst, bool closeio, const char *type) {
    return ::IMG_SaveTyped_IO(value_, dst, closeio, type) ? Status() : Status::FromSdl();
  }
  Status SaveBMP(const char *file) {
    return ::IMG_SaveBMP(value_, file) ? Status() : Status::FromSdl();
  }
  Status SaveBMP_IO(SDL_IOStream *dst, bool closeio) {
    return ::IMG_SaveBMP_IO(value_, dst, closeio) ? Status() : Status::FromSdl();
  }
  Status SaveCUR(const char *file) {
    return ::IMG_SaveCUR(value_, file) ? Status() : Status::FromSdl();
  }
  Status SaveCUR_IO(SDL_IOStream *dst, bool closeio) {
    return ::IMG_SaveCUR_IO(value_, dst, closeio) ? Status() : Status::FromSdl();
  }
  Status SaveGIF(const char *file) {
    return ::IMG_SaveGIF(value_, file) ? Status() : Status::FromSdl();
  }
  Status SaveGIF_IO(SDL_IOStream *dst, bool closeio) {
    return ::IMG_SaveGIF_IO(value_, dst, closeio) ? Status() : Status::FromSdl();
  }
  Status SaveICO(const char *file) {
    return ::IMG_SaveICO(value_, file) ? Status() : Status::FromSdl();
  }
  Status SaveICO_IO(SDL_IOStream *dst, bool closeio) {
    return ::IMG_SaveICO_IO(value_, dst, closeio) ? Status() : Status::FromSdl();
  }
  Status SaveJPG(const char *file, int quality) {
    return ::IMG_SaveJPG(value_, file, quality) ? Status() : Status::FromSdl();
  }
  Status SaveJPG_IO(SDL_IOStream *dst, bool closeio, int quality) {
    return ::IMG_SaveJPG_IO(value_, dst, closeio, quality) ? Status() : Status::FromSdl();
  }
  Status SavePNG(const char *file) {
    return ::IMG_SavePNG(value_, file) ? Status() : Status::FromSdl();
  }
  Status SavePNG_IO(SDL_IOStream *dst, bool closeio) {
    return ::IMG_SavePNG_IO(value_, dst, closeio) ? Status() : Status::FromSdl();
  }
  Status SaveTGA(const char *file) {
    return ::IMG_SaveTGA(value_, file) ? Status() : Status::FromSdl();
  }
  Status SaveTGA_IO(SDL_IOStream *dst, bool closeio) {
    return ::IMG_SaveTGA_IO(value_, dst, closeio) ? Status() : Status::FromSdl();
  }
 private:
  explicit Surface(SDL_Surface* value) : value_(value), engaged_(true) {}
  SDL_Surface* value_{};
  bool engaged_ = false;
};

// bool-returning C functions surfaced as Status.
inline Status AddAnimationEncoderFrame(IMG_AnimationEncoder *encoder, SDL_Surface *surface, Uint64 duration) {
  return ::IMG_AddAnimationEncoderFrame(encoder, surface, duration) ? Status() : Status::FromSdl();
}
inline Status CloseAnimationDecoder(IMG_AnimationDecoder *decoder) {
  return ::IMG_CloseAnimationDecoder(decoder) ? Status() : Status::FromSdl();
}
inline Status CloseAnimationEncoder(IMG_AnimationEncoder *encoder) {
  return ::IMG_CloseAnimationEncoder(encoder) ? Status() : Status::FromSdl();
}
inline Status GetAnimationDecoderFrame(IMG_AnimationDecoder *decoder, SDL_Surface **frame, Uint64 *duration) {
  return ::IMG_GetAnimationDecoderFrame(decoder, frame, duration) ? Status() : Status::FromSdl();
}
inline Status ResetAnimationDecoder(IMG_AnimationDecoder *decoder) {
  return ::IMG_ResetAnimationDecoder(decoder) ? Status() : Status::FromSdl();
}
inline Status isANI(SDL_IOStream *src) {
  return ::IMG_isANI(src) ? Status() : Status::FromSdl();
}
inline Status isBMP(SDL_IOStream *src) {
  return ::IMG_isBMP(src) ? Status() : Status::FromSdl();
}
inline Status isCUR(SDL_IOStream *src) {
  return ::IMG_isCUR(src) ? Status() : Status::FromSdl();
}
inline Status isGIF(SDL_IOStream *src) {
  return ::IMG_isGIF(src) ? Status() : Status::FromSdl();
}
inline Status isICO(SDL_IOStream *src) {
  return ::IMG_isICO(src) ? Status() : Status::FromSdl();
}
inline Status isJPG(SDL_IOStream *src) {
  return ::IMG_isJPG(src) ? Status() : Status::FromSdl();
}
inline Status isLBM(SDL_IOStream *src) {
  return ::IMG_isLBM(src) ? Status() : Status::FromSdl();
}
inline Status isPCX(SDL_IOStream *src) {
  return ::IMG_isPCX(src) ? Status() : Status::FromSdl();
}
inline Status isPNG(SDL_IOStream *src) {
  return ::IMG_isPNG(src) ? Status() : Status::FromSdl();
}
inline Status isPNM(SDL_IOStream *src) {
  return ::IMG_isPNM(src) ? Status() : Status::FromSdl();
}
inline Status isQOI(SDL_IOStream *src) {
  return ::IMG_isQOI(src) ? Status() : Status::FromSdl();
}
inline Status isSVG(SDL_IOStream *src) {
  return ::IMG_isSVG(src) ? Status() : Status::FromSdl();
}
inline Status isXCF(SDL_IOStream *src) {
  return ::IMG_isXCF(src) ? Status() : Status::FromSdl();
}
inline Status isXPM(SDL_IOStream *src) {
  return ::IMG_isXPM(src) ? Status() : Status::FromSdl();
}
inline Status isXV(SDL_IOStream *src) {
  return ::IMG_isXV(src) ? Status() : Status::FromSdl();
}

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& CreateAnimationDecoder = ::IMG_CreateAnimationDecoder;
inline constexpr auto& CreateAnimationDecoderWithProperties = ::IMG_CreateAnimationDecoderWithProperties;
inline constexpr auto& CreateAnimationDecoder_IO = ::IMG_CreateAnimationDecoder_IO;
inline constexpr auto& CreateAnimationEncoder = ::IMG_CreateAnimationEncoder;
inline constexpr auto& CreateAnimationEncoderWithProperties = ::IMG_CreateAnimationEncoderWithProperties;
inline constexpr auto& CreateAnimationEncoder_IO = ::IMG_CreateAnimationEncoder_IO;
inline constexpr auto& GetAnimationDecoderProperties = ::IMG_GetAnimationDecoderProperties;
inline constexpr auto& GetAnimationDecoderStatus = ::IMG_GetAnimationDecoderStatus;
inline constexpr auto& GetClipboardImage = ::IMG_GetClipboardImage;
inline constexpr auto& LoadANIAnimation_IO = ::IMG_LoadANIAnimation_IO;
inline constexpr auto& LoadBMP_IO = ::IMG_LoadBMP_IO;
inline constexpr auto& LoadCUR_IO = ::IMG_LoadCUR_IO;
inline constexpr auto& LoadGIFAnimation_IO = ::IMG_LoadGIFAnimation_IO;
inline constexpr auto& LoadGIF_IO = ::IMG_LoadGIF_IO;
inline constexpr auto& LoadGPUTexture = ::IMG_LoadGPUTexture;
inline constexpr auto& LoadGPUTextureTyped_IO = ::IMG_LoadGPUTextureTyped_IO;
inline constexpr auto& LoadGPUTexture_IO = ::IMG_LoadGPUTexture_IO;
inline constexpr auto& LoadICO_IO = ::IMG_LoadICO_IO;
inline constexpr auto& LoadJPG_IO = ::IMG_LoadJPG_IO;
inline constexpr auto& LoadLBM_IO = ::IMG_LoadLBM_IO;
inline constexpr auto& LoadPCX_IO = ::IMG_LoadPCX_IO;
inline constexpr auto& LoadPNG_IO = ::IMG_LoadPNG_IO;
inline constexpr auto& LoadPNM_IO = ::IMG_LoadPNM_IO;
inline constexpr auto& LoadQOI_IO = ::IMG_LoadQOI_IO;
inline constexpr auto& LoadSVG_IO = ::IMG_LoadSVG_IO;
inline constexpr auto& LoadSizedSVG_IO = ::IMG_LoadSizedSVG_IO;
inline constexpr auto& LoadTGA_IO = ::IMG_LoadTGA_IO;
inline constexpr auto& LoadTexture = ::IMG_LoadTexture;
inline constexpr auto& LoadTextureTyped_IO = ::IMG_LoadTextureTyped_IO;
inline constexpr auto& LoadTexture_IO = ::IMG_LoadTexture_IO;
inline constexpr auto& LoadXCF_IO = ::IMG_LoadXCF_IO;
inline constexpr auto& LoadXPM_IO = ::IMG_LoadXPM_IO;
inline constexpr auto& LoadXV_IO = ::IMG_LoadXV_IO;
inline constexpr auto& ReadXPMFromArray = ::IMG_ReadXPMFromArray;
inline constexpr auto& ReadXPMFromArrayToRGB888 = ::IMG_ReadXPMFromArrayToRGB888;
inline constexpr auto& Version = ::IMG_Version;

}  // namespace img
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_IMG_H_
// clang-format on
