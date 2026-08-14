// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: SDLStatic modules
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_SDLSTATIC_H_
#define SDLSTATIC_CPP_GEN_SDLSTATIC_H_

#include <SDLStatic/base64.h>
#include <SDLStatic/chiptune.h>
#include <SDLStatic/compress.h>
#include <SDLStatic/crypto.h>
#include <SDLStatic/gui_grid.h>
#include <SDLStatic/signals.h>
#include <SDLStatic/tiled.h>
#include <SDLStatic/vfs.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace ext {

// RAII owner for SDLStatic_TiledMap (destroyed with SDLStatic_FreeTiledMap).
class TiledMapHandle {
 public:
  static Result<TiledMapHandle> LoadTiledMap(const char *path) {
    SDLStatic_TiledMap* created_ = ::SDLStatic_LoadTiledMap(path);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return TiledMapHandle(created_);
  }

  TiledMapHandle() = default;
  ~TiledMapHandle() { reset(); }
  TiledMapHandle(TiledMapHandle&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  TiledMapHandle& operator=(TiledMapHandle&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  TiledMapHandle(const TiledMapHandle&) = delete;
  TiledMapHandle& operator=(const TiledMapHandle&) = delete;

  SDLStatic_TiledMap* get() const { return value_; }
  SDLStatic_TiledMap* release() {
    SDLStatic_TiledMap* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDLStatic_FreeTiledMap(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  int TiledMapWidth() {
    return ::SDLStatic_TiledMapWidth(value_);
  }
  int TiledMapHeight() {
    return ::SDLStatic_TiledMapHeight(value_);
  }
  int TiledTileWidth() {
    return ::SDLStatic_TiledTileWidth(value_);
  }
  int TiledTileHeight() {
    return ::SDLStatic_TiledTileHeight(value_);
  }
  int TiledLayerCount() {
    return ::SDLStatic_TiledLayerCount(value_);
  }
  const char* TiledLayerName(int idx) {
    return ::SDLStatic_TiledLayerName(value_, idx);
  }
  const char* TiledLayerType(int idx) {
    return ::SDLStatic_TiledLayerType(value_, idx);
  }
  int TiledTileAt(int layer, int x, int y) {
    return ::SDLStatic_TiledTileAt(value_, layer, x, y);
  }
  int TiledObjectCount(int layer) {
    return ::SDLStatic_TiledObjectCount(value_, layer);
  }
  Status TiledObjectAt(int layer, int index, SDLStatic_TiledObject *out) {
    return ::SDLStatic_TiledObjectAt(value_, layer, index, out) ? Status() : Status::FromSdl();
  }
  cute_tiled_map_t* TiledRaw() {
    return ::SDLStatic_TiledRaw(value_);
  }
 private:
  explicit TiledMapHandle(SDLStatic_TiledMap* value) : value_(value), engaged_(true) {}
  SDLStatic_TiledMap* value_{};
  bool engaged_ = false;
};

// bool-returning C functions surfaced as Status.
inline Status CryptoSelfTest() {
  return ::SDLStatic_CryptoSelfTest() ? Status() : Status::FromSdl();
}
inline Status DisconnectSignal(SDLStatic_SignalEmitter *emitter, Uint64 connection) {
  return ::SDLStatic_DisconnectSignal(emitter, connection) ? Status() : Status::FromSdl();
}
inline Status GuiGridBegin(struct nk_context *ctx, SDLStatic_GuiGrid *grid, int columns, const float *weights, float row_height) {
  return ::SDLStatic_GuiGridBegin(ctx, grid, columns, weights, row_height) ? Status() : Status::FromSdl();
}
inline Status HMACSHA256(const void *key, size_t keySize, const void *data, size_t dataSize, Uint8 digest[32]) {
  return ::SDLStatic_HMACSHA256(key, keySize, data, dataSize, digest) ? Status() : Status::FromSdl();
}
inline Status MountEncryptedArchiveFile(const char *path, const char *password, const char *mountPoint) {
  return ::SDLStatic_MountEncryptedArchiveFile(path, password, mountPoint) ? Status() : Status::FromSdl();
}
inline Status SHA256(const void *data, size_t dataSize, Uint8 digest[32]) {
  return ::SDLStatic_SHA256(data, dataSize, digest) ? Status() : Status::FromSdl();
}

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& ConnectSignal = ::SDLStatic_ConnectSignal;
inline constexpr auto& CountSignalConnections = ::SDLStatic_CountSignalConnections;
inline constexpr auto& CreateChipSFX = ::SDLStatic_CreateChipSFX;
inline constexpr auto& CreateChipTone = ::SDLStatic_CreateChipTone;
inline constexpr auto& CreateChipTune = ::SDLStatic_CreateChipTune;
inline constexpr auto& CreateSignalEmitter = ::SDLStatic_CreateSignalEmitter;
inline constexpr auto& DecodeDataBase64 = ::SDLStatic_DecodeDataBase64;
inline constexpr auto& DecompressData = ::SDLStatic_DecompressData;
inline constexpr auto& DecryptData = ::SDLStatic_DecryptData;
inline constexpr auto& DestroySignalEmitter = ::SDLStatic_DestroySignalEmitter;
inline constexpr auto& EmitSignal = ::SDLStatic_EmitSignal;
inline constexpr auto& GuiGridCell = ::SDLStatic_GuiGridCell;
inline constexpr auto& GuiGridCellSpan = ::SDLStatic_GuiGridCellSpan;
inline constexpr auto& GuiGridEnd = ::SDLStatic_GuiGridEnd;
inline constexpr auto& GuiGridNextRow = ::SDLStatic_GuiGridNextRow;
inline constexpr auto& LoadVFSFile = ::SDLStatic_LoadVFSFile;
inline constexpr auto& OpenVFSRead = ::SDLStatic_OpenVFSRead;

}  // namespace ext
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_SDLSTATIC_H_
// clang-format on
