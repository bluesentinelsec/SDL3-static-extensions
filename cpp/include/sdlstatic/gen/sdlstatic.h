// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: SDLStatic modules
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_SDLSTATIC_H_
#define SDLSTATIC_CPP_GEN_SDLSTATIC_H_

#include <SDLStatic/base64.h>
#include <SDLStatic/bidi.h>
#include <SDLStatic/chiptune.h>
#include <SDLStatic/compress.h>
#include <SDLStatic/crypto.h>
#include <SDLStatic/debug_text.h>
#include <SDLStatic/dialog.h>
#include <SDLStatic/gui.h>
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

// RAII owner for SDLStatic_Gui (destroyed with SDLStatic_DestroyGui).
class GuiHandle {
 public:
  static Result<GuiHandle> CreateGui(SDL_Renderer *renderer, const void *font_data, size_t font_len, float font_size) {
    SDLStatic_Gui* created_ = ::SDLStatic_CreateGui(renderer, font_data, font_len, font_size);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return GuiHandle(created_);
  }

  GuiHandle() = default;
  ~GuiHandle() { reset(); }
  GuiHandle(GuiHandle&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  GuiHandle& operator=(GuiHandle&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  GuiHandle(const GuiHandle&) = delete;
  GuiHandle& operator=(const GuiHandle&) = delete;

  SDLStatic_Gui* get() const { return value_; }
  SDLStatic_Gui* release() {
    SDLStatic_Gui* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDLStatic_DestroyGui(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  struct nk_context* GuiContext() {
    return ::SDLStatic_GuiContext(value_);
  }
  void GuiInputBegin() { ::SDLStatic_GuiInputBegin(value_); }
  Status GuiProcessEvent(const SDL_Event *event) {
    return ::SDLStatic_GuiProcessEvent(value_, event) ? Status() : Status::FromSdl();
  }
  void GuiInputEnd() { ::SDLStatic_GuiInputEnd(value_); }
  Status GuiWantsInput() {
    return ::SDLStatic_GuiWantsInput(value_) ? Status() : Status::FromSdl();
  }
  Status GuiPumpEvents() {
    return ::SDLStatic_GuiPumpEvents(value_) ? Status() : Status::FromSdl();
  }
  Status GuiKeyPressed(int scancode) {
    return ::SDLStatic_GuiKeyPressed(value_, scancode) ? Status() : Status::FromSdl();
  }
  Status GuiTooltip(const char *text) {
    return ::SDLStatic_GuiTooltip(value_, text) ? Status() : Status::FromSdl();
  }
  void GuiSetTooltipDelay(int delay_ms) { ::SDLStatic_GuiSetTooltipDelay(value_, delay_ms); }
  int GuiTooltipDelay() {
    return ::SDLStatic_GuiTooltipDelay(value_);
  }
  Status GuiGridWeight(int column, float weight) {
    return ::SDLStatic_GuiGridWeight(value_, column, weight) ? Status() : Status::FromSdl();
  }
  Status GuiGridBeginOwned(int columns, float row_height) {
    return ::SDLStatic_GuiGridBeginOwned(value_, columns, row_height) ? Status() : Status::FromSdl();
  }
  void GuiGridCellOwned() { ::SDLStatic_GuiGridCellOwned(value_); }
  void GuiGridCellSpanOwned(int span) { ::SDLStatic_GuiGridCellSpanOwned(value_, span); }
  void GuiGridNextRowOwned() { ::SDLStatic_GuiGridNextRowOwned(value_); }
  void GuiGridEndOwned() { ::SDLStatic_GuiGridEndOwned(value_); }
  Status GuiImage(SDL_Texture *texture, SDLStatic_GuiImageMode mode) {
    return ::SDLStatic_GuiImage(value_, texture, mode) ? Status() : Status::FromSdl();
  }
  Status GuiSetFont(SDLStatic_GuiFontSize which) {
    return ::SDLStatic_GuiSetFont(value_, which) ? Status() : Status::FromSdl();
  }
  Status GuiPushFont(SDLStatic_GuiFontSize which) {
    return ::SDLStatic_GuiPushFont(value_, which) ? Status() : Status::FromSdl();
  }
  void GuiPopFont(int count) { ::SDLStatic_GuiPopFont(value_, count); }
  float GuiFontHeight() {
    return ::SDLStatic_GuiFontHeight(value_);
  }
  Status GuiPushStyleColor(SDLStatic_GuiStyleColor which, SDL_Color color) {
    return ::SDLStatic_GuiPushStyleColor(value_, which, color) ? Status() : Status::FromSdl();
  }
  void GuiPopStyleColor(int count) { ::SDLStatic_GuiPopStyleColor(value_, count); }
  float GuiScale() {
    return ::SDLStatic_GuiScale(value_);
  }
  Status GuiRender() {
    return ::SDLStatic_GuiRender(value_) ? Status() : Status::FromSdl();
  }
 private:
  explicit GuiHandle(SDLStatic_Gui* value) : value_(value), engaged_(true) {}
  SDLStatic_Gui* value_{};
  bool engaged_ = false;
};

// bool-returning C functions surfaced as Status.
inline Status BidiBaseIsRTL(const char *utf8, int length) {
  return ::SDLStatic_BidiBaseIsRTL(utf8, length) ? Status() : Status::FromSdl();
}
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
inline Status MountEncryptedArchive(const void *data, int dataSize, const char *password, const char *mountPoint) {
  return ::SDLStatic_MountEncryptedArchive(data, dataSize, password, mountPoint) ? Status() : Status::FromSdl();
}
inline Status MountEncryptedArchiveFile(const char *path, const char *password, const char *mountPoint) {
  return ::SDLStatic_MountEncryptedArchiveFile(path, password, mountPoint) ? Status() : Status::FromSdl();
}
inline Status RenderDebugText(SDL_Renderer *renderer, float x, float y, const char *text) {
  return ::SDLStatic_RenderDebugText(renderer, x, y, text) ? Status() : Status::FromSdl();
}
inline Status SHA256(const void *data, size_t dataSize, Uint8 digest[32]) {
  return ::SDLStatic_SHA256(data, dataSize, digest) ? Status() : Status::FromSdl();
}
inline Status ShowOpenFileDialog(SDL_Window *window, const char *filter_name, const char *filter_pattern, const char *default_location) {
  return ::SDLStatic_ShowOpenFileDialog(window, filter_name, filter_pattern, default_location) ? Status() : Status::FromSdl();
}
inline Status ShowSaveFileDialog(SDL_Window *window, const char *filter_name, const char *filter_pattern, const char *default_location) {
  return ::SDLStatic_ShowSaveFileDialog(window, filter_name, filter_pattern, default_location) ? Status() : Status::FromSdl();
}

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& BidiItemize = ::SDLStatic_BidiItemize;
inline constexpr auto& CompressData = ::SDLStatic_CompressData;
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
inline constexpr auto& DialogPath = ::SDLStatic_DialogPath;
inline constexpr auto& DialogReset = ::SDLStatic_DialogReset;
inline constexpr auto& DialogStatus = ::SDLStatic_DialogStatus;
inline constexpr auto& EmitSignal = ::SDLStatic_EmitSignal;
inline constexpr auto& EncodeDataBase64 = ::SDLStatic_EncodeDataBase64;
inline constexpr auto& EncryptData = ::SDLStatic_EncryptData;
inline constexpr auto& GuiGridCell = ::SDLStatic_GuiGridCell;
inline constexpr auto& GuiGridCellSpan = ::SDLStatic_GuiGridCellSpan;
inline constexpr auto& GuiGridEnd = ::SDLStatic_GuiGridEnd;
inline constexpr auto& GuiGridNextRow = ::SDLStatic_GuiGridNextRow;
inline constexpr auto& LoadVFSFile = ::SDLStatic_LoadVFSFile;
inline constexpr auto& OpenVFSRead = ::SDLStatic_OpenVFSRead;
inline constexpr auto& QuitDebugText = ::SDLStatic_QuitDebugText;
inline constexpr auto& SetDebugTextSize = ::SDLStatic_SetDebugTextSize;

}  // namespace ext
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_SDLSTATIC_H_
// clang-format on
