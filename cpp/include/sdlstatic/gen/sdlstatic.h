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
#include <SDLStatic/engine.h>
#include <SDLStatic/engine_actor.h>
#include <SDLStatic/engine_assets.h>
#include <SDLStatic/engine_binding.h>
#include <SDLStatic/engine_camera.h>
#include <SDLStatic/engine_graphics.h>
#include <SDLStatic/engine_input.h>
#include <SDLStatic/engine_light.h>
#include <SDLStatic/engine_media.h>
#include <SDLStatic/engine_physics.h>
#include <SDLStatic/engine_render.h>
#include <SDLStatic/engine_save.h>
#include <SDLStatic/engine_scene.h>
#include <SDLStatic/engine_text.h>
#include <SDLStatic/gui.h>
#include <SDLStatic/gui_grid.h>
#include <SDLStatic/light.h>
#include <SDLStatic/regex.h>
#include <SDLStatic/signals.h>
#include <SDLStatic/textfile.h>
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
  Status GuiOpenFileButton(const char *label, const char *filter_name, const char *filter_pattern) {
    return ::SDLStatic_GuiOpenFileButton(value_, label, filter_name, filter_pattern) ? Status() : Status::FromSdl();
  }
  Status GuiSaveFileButton(const char *label, const char *filename, const void *data, size_t len) {
    return ::SDLStatic_GuiSaveFileButton(value_, label, filename, data, len) ? Status() : Status::FromSdl();
  }
  const char* GuiSavedPath() {
    return ::SDLStatic_GuiSavedPath(value_);
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
  Status GuiDrawTexture(SDL_Texture *texture, SDL_FRect rect, SDLStatic_GuiImageMode mode) {
    return ::SDLStatic_GuiDrawTexture(value_, texture, rect, mode) ? Status() : Status::FromSdl();
  }
  Status GuiDrawTextureOverlay(SDL_Texture *texture, SDL_FRect rect, SDLStatic_GuiImageMode mode) {
    return ::SDLStatic_GuiDrawTextureOverlay(value_, texture, rect, mode) ? Status() : Status::FromSdl();
  }
  int GuiDrawCommandCount() {
    return ::SDLStatic_GuiDrawCommandCount(value_);
  }
  int GuiMemoryUsed() {
    return ::SDLStatic_GuiMemoryUsed(value_);
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

// RAII owner for SDLStatic_Regex (destroyed with SDLStatic_DestroyRegex).
class RegexHandle {
 public:
  static Result<RegexHandle> CompileRegex(const char *pattern, const char *flags) {
    SDLStatic_Regex* created_ = ::SDLStatic_CompileRegex(pattern, flags);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return RegexHandle(created_);
  }

  RegexHandle() = default;
  ~RegexHandle() { reset(); }
  RegexHandle(RegexHandle&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  RegexHandle& operator=(RegexHandle&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  RegexHandle(const RegexHandle&) = delete;
  RegexHandle& operator=(const RegexHandle&) = delete;

  SDLStatic_Regex* get() const { return value_; }
  SDLStatic_Regex* release() {
    SDLStatic_Regex* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDLStatic_DestroyRegex(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status RegexSearch(const char *text, int start) {
    return ::SDLStatic_RegexSearch(value_, text, start) ? Status() : Status::FromSdl();
  }
  Status RegexMatchAt(const char *text, int start) {
    return ::SDLStatic_RegexMatchAt(value_, text, start) ? Status() : Status::FromSdl();
  }
  int RegexGroupCount() {
    return ::SDLStatic_RegexGroupCount(value_);
  }
  const char* RegexGroup(int group) {
    return ::SDLStatic_RegexGroup(value_, group);
  }
  int RegexGroupBegin(int group) {
    return ::SDLStatic_RegexGroupBegin(value_, group);
  }
  int RegexGroupEnd(int group) {
    return ::SDLStatic_RegexGroupEnd(value_, group);
  }
  int RegexNamedGroup(const char *name) {
    return ::SDLStatic_RegexNamedGroup(value_, name);
  }
  int RegexNamedGroupCount() {
    return ::SDLStatic_RegexNamedGroupCount(value_);
  }
  const char* RegexNamedGroupName(int index) {
    return ::SDLStatic_RegexNamedGroupName(value_, index);
  }
  const char* RegexPattern() {
    return ::SDLStatic_RegexPattern(value_);
  }
  const char* RegexFlags() {
    return ::SDLStatic_RegexFlags(value_);
  }
  const char* RegexReplace(const char *text, const char *replacement, bool all) {
    return ::SDLStatic_RegexReplace(value_, text, replacement, all);
  }
 private:
  explicit RegexHandle(SDLStatic_Regex* value) : value_(value), engaged_(true) {}
  SDLStatic_Regex* value_{};
  bool engaged_ = false;
};

// RAII owner for SDLStatic_LightScene (destroyed with SDLStatic_DestroyLightScene).
class LightSceneHandle {
 public:
  static Result<LightSceneHandle> CreateLightScene(SDL_Renderer *renderer) {
    SDLStatic_LightScene* created_ = ::SDLStatic_CreateLightScene(renderer);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return LightSceneHandle(created_);
  }

  LightSceneHandle() = default;
  ~LightSceneHandle() { reset(); }
  LightSceneHandle(LightSceneHandle&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  LightSceneHandle& operator=(LightSceneHandle&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  LightSceneHandle(const LightSceneHandle&) = delete;
  LightSceneHandle& operator=(const LightSceneHandle&) = delete;

  SDLStatic_LightScene* get() const { return value_; }
  SDLStatic_LightScene* release() {
    SDLStatic_LightScene* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDLStatic_DestroyLightScene(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  void LightBeginFrame(float camera_x, float camera_y) { ::SDLStatic_LightBeginFrame(value_, camera_x, camera_y); }
  void SetLightAmbient(SDL_FColor ambient) { ::SDLStatic_SetLightAmbient(value_, ambient); }
  Status AddLight(const SDLStatic_Light *light) {
    return ::SDLStatic_AddLight(value_, light) ? Status() : Status::FromSdl();
  }
  Status AddDarkZone(SDL_FRect rect, SDL_FColor ambient) {
    return ::SDLStatic_AddDarkZone(value_, rect, ambient) ? Status() : Status::FromSdl();
  }
  Status AddOccluderRect(SDL_FRect rect) {
    return ::SDLStatic_AddOccluderRect(value_, rect) ? Status() : Status::FromSdl();
  }
  Status AddOccluderSegment(float x1, float y1, float x2, float y2) {
    return ::SDLStatic_AddOccluderSegment(value_, x1, y1, x2, y2) ? Status() : Status::FromSdl();
  }
  Status RenderLighting() {
    return ::SDLStatic_RenderLighting(value_) ? Status() : Status::FromSdl();
  }
  float SampleLight(float x, float y) {
    return ::SDLStatic_SampleLight(value_, x, y);
  }
  Status LightLineOfSight(float x1, float y1, float x2, float y2) {
    return ::SDLStatic_LightLineOfSight(value_, x1, y1, x2, y2) ? Status() : Status::FromSdl();
  }
  Status LightUsesShaders() {
    return ::SDLStatic_LightUsesShaders(value_) ? Status() : Status::FromSdl();
  }
  void SetLightUseShaders(bool enabled) { ::SDLStatic_SetLightUseShaders(value_, enabled); }
  void SetLightMapScale(float scale) { ::SDLStatic_SetLightMapScale(value_, scale); }
  void SetLightShadowSoftness(float softness) { ::SDLStatic_SetLightShadowSoftness(value_, softness); }
  void SetLightRayCount(int rays) { ::SDLStatic_SetLightRayCount(value_, rays); }
  void SetLightRings(int rings) { ::SDLStatic_SetLightRings(value_, rings); }
  void SetLightDebugDraw(bool enabled) { ::SDLStatic_SetLightDebugDraw(value_, enabled); }
 private:
  explicit LightSceneHandle(SDLStatic_LightScene* value) : value_(value), engaged_(true) {}
  SDLStatic_LightScene* value_{};
  bool engaged_ = false;
};

// bool-returning C functions surfaced as Status.
inline Status ActionBind(SDLStatic_ActionMap *map, const char *action, SDLStatic_Binding binding) {
  return ::SDLStatic_ActionBind(map, action, binding) ? Status() : Status::FromSdl();
}
inline Status ActionBindAxis(SDLStatic_ActionMap *map, const char *action, SDLStatic_GamepadAxis axis, int half) {
  return ::SDLStatic_ActionBindAxis(map, action, axis, half) ? Status() : Status::FromSdl();
}
inline Status ActionBindDirection(SDLStatic_ActionMap *map, const char *action, SDLStatic_Direction direction) {
  return ::SDLStatic_ActionBindDirection(map, action, direction) ? Status() : Status::FromSdl();
}
inline Status ActionBindKey(SDLStatic_ActionMap *map, const char *action, SDL_Scancode key) {
  return ::SDLStatic_ActionBindKey(map, action, key) ? Status() : Status::FromSdl();
}
inline Status ActionBindKeySigned(SDLStatic_ActionMap *map, const char *action, SDL_Scancode key, int sign) {
  return ::SDLStatic_ActionBindKeySigned(map, action, key, sign) ? Status() : Status::FromSdl();
}
inline Status ActionBindMouse(SDLStatic_ActionMap *map, const char *action, SDLStatic_MouseButton button) {
  return ::SDLStatic_ActionBindMouse(map, action, button) ? Status() : Status::FromSdl();
}
inline Status ActionBindPad(SDLStatic_ActionMap *map, const char *action, SDLStatic_GamepadButton button) {
  return ::SDLStatic_ActionBindPad(map, action, button) ? Status() : Status::FromSdl();
}
inline Status ActionBindingAt(SDLStatic_ActionMap *map, const char *action, int index, SDLStatic_Binding *out) {
  return ::SDLStatic_ActionBindingAt(map, action, index, out) ? Status() : Status::FromSdl();
}
inline Status ActionCapture(SDLStatic_Engine *engine, int player, SDLStatic_Binding *out) {
  return ::SDLStatic_ActionCapture(engine, player, out) ? Status() : Status::FromSdl();
}
inline Status ActionDown(SDLStatic_Engine *engine, SDLStatic_ActionMap *map, int player, const char *action) {
  return ::SDLStatic_ActionDown(engine, map, player, action) ? Status() : Status::FromSdl();
}
inline Status ActionMapLoad(SDLStatic_ActionMap *map, const char *org, const char *app) {
  return ::SDLStatic_ActionMapLoad(map, org, app) ? Status() : Status::FromSdl();
}
inline Status ActionMapLoadToml(SDLStatic_ActionMap *map, const char *toml) {
  return ::SDLStatic_ActionMapLoadToml(map, toml) ? Status() : Status::FromSdl();
}
inline Status ActionMapSave(SDLStatic_ActionMap *map, const char *org, const char *app) {
  return ::SDLStatic_ActionMapSave(map, org, app) ? Status() : Status::FromSdl();
}
inline Status ActionPressed(SDLStatic_Engine *engine, SDLStatic_ActionMap *map, int player, const char *action) {
  return ::SDLStatic_ActionPressed(engine, map, player, action) ? Status() : Status::FromSdl();
}
inline Status ActionReleased(SDLStatic_Engine *engine, SDLStatic_ActionMap *map, int player, const char *action) {
  return ::SDLStatic_ActionReleased(engine, map, player, action) ? Status() : Status::FromSdl();
}
inline Status ActorAddBody(SDLStatic_Actor *actor, const SDLStatic_BodyDef *def) {
  return ::SDLStatic_ActorAddBody(actor, def) ? Status() : Status::FromSdl();
}
inline Status ActorAddLight(SDLStatic_Actor *actor, const SDLStatic_LightDef *light) {
  return ::SDLStatic_ActorAddLight(actor, light) ? Status() : Status::FromSdl();
}
inline Status ActorAlive(SDLStatic_Engine *engine, SDLStatic_ActorId id) {
  return ::SDLStatic_ActorAlive(engine, id) ? Status() : Status::FromSdl();
}
inline Status ActorBodyBounds(SDLStatic_Actor *actor, SDL_FRect *out) {
  return ::SDLStatic_ActorBodyBounds(actor, out) ? Status() : Status::FromSdl();
}
inline Status ActorEnabled(SDLStatic_Actor *actor) {
  return ::SDLStatic_ActorEnabled(actor) ? Status() : Status::FromSdl();
}
inline Status ActorHasBody(SDLStatic_Actor *actor) {
  return ::SDLStatic_ActorHasBody(actor) ? Status() : Status::FromSdl();
}
inline Status ActorHasTags(SDLStatic_Actor *actor, SDLStatic_ActorTags any) {
  return ::SDLStatic_ActorHasTags(actor, any) ? Status() : Status::FromSdl();
}
inline Status ActorSend(SDLStatic_Engine *engine, SDLStatic_ActorId target, const SDLStatic_ActorMessage *message) {
  return ::SDLStatic_ActorSend(engine, target, message) ? Status() : Status::FromSdl();
}
inline Status ActorSetParent(SDLStatic_Actor *actor, SDLStatic_ActorId parent) {
  return ::SDLStatic_ActorSetParent(actor, parent) ? Status() : Status::FromSdl();
}
inline Status ActorSetSprite(SDLStatic_Actor *actor, const SDLStatic_Sprite *sprite) {
  return ::SDLStatic_ActorSetSprite(actor, sprite) ? Status() : Status::FromSdl();
}
inline Status AnyInput(SDLStatic_Engine *engine) {
  return ::SDLStatic_AnyInput(engine) ? Status() : Status::FromSdl();
}
inline Status AssetsReady(SDLStatic_Engine *engine) {
  return ::SDLStatic_AssetsReady(engine) ? Status() : Status::FromSdl();
}
inline Status BidiBaseIsRTL(const char *utf8, int length) {
  return ::SDLStatic_BidiBaseIsRTL(utf8, length) ? Status() : Status::FromSdl();
}
inline Status BindingFromString(const char *text, SDLStatic_Binding *out) {
  return ::SDLStatic_BindingFromString(text, out) ? Status() : Status::FromSdl();
}
inline Status CameraBegin(SDLStatic_Engine *engine, const SDLStatic_Camera *camera) {
  return ::SDLStatic_CameraBegin(engine, camera) ? Status() : Status::FromSdl();
}
inline Status CameraScreenToWorld(const SDLStatic_Camera *camera, float screen_x, float screen_y, float *world_x, float *world_y) {
  return ::SDLStatic_CameraScreenToWorld(camera, screen_x, screen_y, world_x, world_y) ? Status() : Status::FromSdl();
}
inline Status CameraVisible(const SDLStatic_Camera *camera, SDL_FRect world) {
  return ::SDLStatic_CameraVisible(camera, world) ? Status() : Status::FromSdl();
}
inline Status CryptoSelfTest() {
  return ::SDLStatic_CryptoSelfTest() ? Status() : Status::FromSdl();
}
inline Status DialogDeliverSave(const char *path) {
  return ::SDLStatic_DialogDeliverSave(path) ? Status() : Status::FromSdl();
}
inline Status DisconnectSignal(SDLStatic_SignalEmitter *emitter, Uint64 connection) {
  return ::SDLStatic_DisconnectSignal(emitter, connection) ? Status() : Status::FromSdl();
}
inline Status EngineEffectsAvailable(SDLStatic_Engine *engine) {
  return ::SDLStatic_EngineEffectsAvailable(engine) ? Status() : Status::FromSdl();
}
inline Status EngineSetDisplay(SDLStatic_Engine *engine, int index) {
  return ::SDLStatic_EngineSetDisplay(engine, index) ? Status() : Status::FromSdl();
}
inline Status EngineSetGraphics(SDLStatic_Engine *engine, const SDLStatic_GraphicsSettings *settings) {
  return ::SDLStatic_EngineSetGraphics(engine, settings) ? Status() : Status::FromSdl();
}
inline Status EngineSetPresentation(SDLStatic_Engine *engine, SDLStatic_EnginePresentation mode) {
  return ::SDLStatic_EngineSetPresentation(engine, mode) ? Status() : Status::FromSdl();
}
inline Status EngineSetTickRate(SDLStatic_Engine *engine, int ticks_per_second) {
  return ::SDLStatic_EngineSetTickRate(engine, ticks_per_second) ? Status() : Status::FromSdl();
}
inline Status EngineTick(SDLStatic_Engine *engine) {
  return ::SDLStatic_EngineTick(engine) ? Status() : Status::FromSdl();
}
inline Status GamepadButtonDown(SDLStatic_Engine *engine, int player, SDLStatic_GamepadButton button) {
  return ::SDLStatic_GamepadButtonDown(engine, player, button) ? Status() : Status::FromSdl();
}
inline Status GamepadButtonPressed(SDLStatic_Engine *engine, int player, SDLStatic_GamepadButton button) {
  return ::SDLStatic_GamepadButtonPressed(engine, player, button) ? Status() : Status::FromSdl();
}
inline Status GamepadButtonReleased(SDLStatic_Engine *engine, int player, SDLStatic_GamepadButton button) {
  return ::SDLStatic_GamepadButtonReleased(engine, player, button) ? Status() : Status::FromSdl();
}
inline Status GamepadConnected(SDLStatic_Engine *engine, int player) {
  return ::SDLStatic_GamepadConnected(engine, player) ? Status() : Status::FromSdl();
}
inline Status GamepadDirectionPressed(SDLStatic_Engine *engine, int player, SDLStatic_Direction direction) {
  return ::SDLStatic_GamepadDirectionPressed(engine, player, direction) ? Status() : Status::FromSdl();
}
inline Status GamepadDirectionRepeat(SDLStatic_Engine *engine, int player, SDLStatic_Direction direction) {
  return ::SDLStatic_GamepadDirectionRepeat(engine, player, direction) ? Status() : Status::FromSdl();
}
inline Status GamepadHasAccelerometer(SDLStatic_Engine *engine, int player) {
  return ::SDLStatic_GamepadHasAccelerometer(engine, player) ? Status() : Status::FromSdl();
}
inline Status GamepadHasGyro(SDLStatic_Engine *engine, int player) {
  return ::SDLStatic_GamepadHasGyro(engine, player) ? Status() : Status::FromSdl();
}
inline Status GamepadRumble(SDLStatic_Engine *engine, int player, float low, float high, Uint32 milliseconds) {
  return ::SDLStatic_GamepadRumble(engine, player, low, high, milliseconds) ? Status() : Status::FromSdl();
}
inline Status GamepadRumbleTriggers(SDLStatic_Engine *engine, int player, float left, float right, Uint32 milliseconds) {
  return ::SDLStatic_GamepadRumbleTriggers(engine, player, left, right, milliseconds) ? Status() : Status::FromSdl();
}
inline Status GamepadSetLED(SDLStatic_Engine *engine, int player, Uint8 red, Uint8 green, Uint8 blue) {
  return ::SDLStatic_GamepadSetLED(engine, player, red, green, blue) ? Status() : Status::FromSdl();
}
inline Status GraphicsEqual(const SDLStatic_GraphicsSettings *a, const SDLStatic_GraphicsSettings *b) {
  return ::SDLStatic_GraphicsEqual(a, b) ? Status() : Status::FromSdl();
}
inline Status GraphicsLoadTomlFile(SDLStatic_GraphicsSettings *settings, const char *path) {
  return ::SDLStatic_GraphicsLoadTomlFile(settings, path) ? Status() : Status::FromSdl();
}
inline Status GraphicsLoadTomlString(SDLStatic_GraphicsSettings *settings, const char *toml) {
  return ::SDLStatic_GraphicsLoadTomlString(settings, toml) ? Status() : Status::FromSdl();
}
inline Status GraphicsQualityFromName(const char *name, SDLStatic_GraphicsQuality *out) {
  return ::SDLStatic_GraphicsQualityFromName(name, out) ? Status() : Status::FromSdl();
}
inline Status GraphicsSave(const SDLStatic_GraphicsSettings *settings, const char *org, const char *app) {
  return ::SDLStatic_GraphicsSave(settings, org, app) ? Status() : Status::FromSdl();
}
inline Status GuiGridBegin(struct nk_context *ctx, SDLStatic_GuiGrid *grid, int columns, const float *weights, float row_height) {
  return ::SDLStatic_GuiGridBegin(ctx, grid, columns, weights, row_height) ? Status() : Status::FromSdl();
}
inline Status HMACSHA256(const void *key, size_t keySize, const void *data, size_t dataSize, Uint8 digest[32]) {
  return ::SDLStatic_HMACSHA256(key, keySize, data, dataSize, digest) ? Status() : Status::FromSdl();
}
inline Status HasDeviceMotion(SDLStatic_Engine *engine) {
  return ::SDLStatic_HasDeviceMotion(engine) ? Status() : Status::FromSdl();
}
inline Status KeyDown(SDLStatic_Engine *engine, SDL_Scancode key) {
  return ::SDLStatic_KeyDown(engine, key) ? Status() : Status::FromSdl();
}
inline Status KeyPressed(SDLStatic_Engine *engine, SDL_Scancode key) {
  return ::SDLStatic_KeyPressed(engine, key) ? Status() : Status::FromSdl();
}
inline Status KeyReleased(SDLStatic_Engine *engine, SDL_Scancode key) {
  return ::SDLStatic_KeyReleased(engine, key) ? Status() : Status::FromSdl();
}
inline Status LightRender(SDLStatic_Engine *engine, const SDLStatic_Camera *camera, float alpha) {
  return ::SDLStatic_LightRender(engine, camera, alpha) ? Status() : Status::FromSdl();
}
inline Status MountEncryptedArchive(const void *data, int dataSize, const char *password, const char *mountPoint) {
  return ::SDLStatic_MountEncryptedArchive(data, dataSize, password, mountPoint) ? Status() : Status::FromSdl();
}
inline Status MountEncryptedArchiveFile(const char *path, const char *password, const char *mountPoint) {
  return ::SDLStatic_MountEncryptedArchiveFile(path, password, mountPoint) ? Status() : Status::FromSdl();
}
inline Status MouseCaptured(SDLStatic_Engine *engine) {
  return ::SDLStatic_MouseCaptured(engine) ? Status() : Status::FromSdl();
}
inline Status MouseDown(SDLStatic_Engine *engine, SDLStatic_MouseButton button) {
  return ::SDLStatic_MouseDown(engine, button) ? Status() : Status::FromSdl();
}
inline Status MousePressed(SDLStatic_Engine *engine, SDLStatic_MouseButton button) {
  return ::SDLStatic_MousePressed(engine, button) ? Status() : Status::FromSdl();
}
inline Status MouseReleased(SDLStatic_Engine *engine, SDLStatic_MouseButton button) {
  return ::SDLStatic_MouseReleased(engine, button) ? Status() : Status::FromSdl();
}
inline Status PhysicsPaused(SDLStatic_Engine *engine) {
  return ::SDLStatic_PhysicsPaused(engine) ? Status() : Status::FromSdl();
}
inline Status RenderDebugText(SDL_Renderer *renderer, float x, float y, const char *text) {
  return ::SDLStatic_RenderDebugText(renderer, x, y, text) ? Status() : Status::FromSdl();
}
inline Status RunGame(SDLStatic_Engine *engine, const SDLStatic_GameHooks *hooks, void *user) {
  return ::SDLStatic_RunGame(engine, hooks, user) ? Status() : Status::FromSdl();
}
inline Status SHA256(const void *data, size_t dataSize, Uint8 digest[32]) {
  return ::SDLStatic_SHA256(data, dataSize, digest) ? Status() : Status::FromSdl();
}
inline Status SaveDelete(SDLStatic_Engine *engine, int slot) {
  return ::SDLStatic_SaveDelete(engine, slot) ? Status() : Status::FromSdl();
}
inline Status SaveExists(SDLStatic_Engine *engine, int slot) {
  return ::SDLStatic_SaveExists(engine, slot) ? Status() : Status::FromSdl();
}
inline Status SaveWrite(SDLStatic_Engine *engine, int slot, const void *data, size_t size, const char *label) {
  return ::SDLStatic_SaveWrite(engine, slot, data, size, label) ? Status() : Status::FromSdl();
}
inline Status SceneIsActive(SDLStatic_Scene *scene) {
  return ::SDLStatic_SceneIsActive(scene) ? Status() : Status::FromSdl();
}
inline Status ScenePop(SDLStatic_Engine *engine) {
  return ::SDLStatic_ScenePop(engine) ? Status() : Status::FromSdl();
}
inline Status ScenePush(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def) {
  return ::SDLStatic_ScenePush(engine, def) ? Status() : Status::FromSdl();
}
inline Status SceneReplace(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def) {
  return ::SDLStatic_SceneReplace(engine, def) ? Status() : Status::FromSdl();
}
inline Status SceneReset(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def) {
  return ::SDLStatic_SceneReset(engine, def) ? Status() : Status::FromSdl();
}
inline Status SceneTransitionTo(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def, SDLStatic_SceneTransition transition, float seconds) {
  return ::SDLStatic_SceneTransitionTo(engine, def, transition, seconds) ? Status() : Status::FromSdl();
}
inline Status SceneTransitioning(SDLStatic_Engine *engine) {
  return ::SDLStatic_SceneTransitioning(engine) ? Status() : Status::FromSdl();
}
inline Status SetDeviceMotion(SDLStatic_Engine *engine, bool enabled) {
  return ::SDLStatic_SetDeviceMotion(engine, enabled) ? Status() : Status::FromSdl();
}
inline Status SetGamepadMotion(SDLStatic_Engine *engine, int player, bool enabled) {
  return ::SDLStatic_SetGamepadMotion(engine, player, enabled) ? Status() : Status::FromSdl();
}
inline Status SetMouseCapture(SDLStatic_Engine *engine, bool captured) {
  return ::SDLStatic_SetMouseCapture(engine, captured) ? Status() : Status::FromSdl();
}
inline Status ShowOpenFileDialog(SDL_Window *window, const char *filter_name, const char *filter_pattern, const char *default_location) {
  return ::SDLStatic_ShowOpenFileDialog(window, filter_name, filter_pattern, default_location) ? Status() : Status::FromSdl();
}
inline Status ShowSaveFileDialog(SDL_Window *window, const char *filter_name, const char *filter_pattern, const char *default_location) {
  return ::SDLStatic_ShowSaveFileDialog(window, filter_name, filter_pattern, default_location) ? Status() : Status::FromSdl();
}
inline Status TextHas(SDLStatic_Engine *engine, const char *key) {
  return ::SDLStatic_TextHas(engine, key) ? Status() : Status::FromSdl();
}
inline Status TextLoad(SDLStatic_Engine *engine, const char *language, const char *toml) {
  return ::SDLStatic_TextLoad(engine, language, toml) ? Status() : Status::FromSdl();
}
inline Status TextLoadFile(SDLStatic_Engine *engine, const char *language) {
  return ::SDLStatic_TextLoadFile(engine, language) ? Status() : Status::FromSdl();
}

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& ActionBindingCount = ::SDLStatic_ActionBindingCount;
inline constexpr auto& ActionClear = ::SDLStatic_ActionClear;
inline constexpr auto& ActionCount = ::SDLStatic_ActionCount;
inline constexpr auto& ActionMapCreate = ::SDLStatic_ActionMapCreate;
inline constexpr auto& ActionMapDestroy = ::SDLStatic_ActionMapDestroy;
inline constexpr auto& ActionMapKeyboardPlayer = ::SDLStatic_ActionMapKeyboardPlayer;
inline constexpr auto& ActionMapSetKeyboardPlayer = ::SDLStatic_ActionMapSetKeyboardPlayer;
inline constexpr auto& ActionMapToToml = ::SDLStatic_ActionMapToToml;
inline constexpr auto& ActionName = ::SDLStatic_ActionName;
inline constexpr auto& ActionValue = ::SDLStatic_ActionValue;
inline constexpr auto& ActionVector = ::SDLStatic_ActionVector;
inline constexpr auto& ActorAngularVelocity = ::SDLStatic_ActorAngularVelocity;
inline constexpr auto& ActorApplyForce = ::SDLStatic_ActorApplyForce;
inline constexpr auto& ActorApplyImpulse = ::SDLStatic_ActorApplyImpulse;
inline constexpr auto& ActorBroadcast = ::SDLStatic_ActorBroadcast;
inline constexpr auto& ActorChild = ::SDLStatic_ActorChild;
inline constexpr auto& ActorChildCount = ::SDLStatic_ActorChildCount;
inline constexpr auto& ActorClear = ::SDLStatic_ActorClear;
inline constexpr auto& ActorClearSprite = ::SDLStatic_ActorClearSprite;
inline constexpr auto& ActorCount = ::SDLStatic_ActorCount;
inline constexpr auto& ActorDestroy = ::SDLStatic_ActorDestroy;
inline constexpr auto& ActorEach = ::SDLStatic_ActorEach;
inline constexpr auto& ActorEngine = ::SDLStatic_ActorEngine;
inline constexpr auto& ActorFindByName = ::SDLStatic_ActorFindByName;
inline constexpr auto& ActorFindByType = ::SDLStatic_ActorFindByType;
inline constexpr auto& ActorGet = ::SDLStatic_ActorGet;
inline constexpr auto& ActorGetId = ::SDLStatic_ActorGetId;
inline constexpr auto& ActorGetTags = ::SDLStatic_ActorGetTags;
inline constexpr auto& ActorLight = ::SDLStatic_ActorLight;
inline constexpr auto& ActorLocal = ::SDLStatic_ActorLocal;
inline constexpr auto& ActorMove = ::SDLStatic_ActorMove;
inline constexpr auto& ActorName = ::SDLStatic_ActorName;
inline constexpr auto& ActorParent = ::SDLStatic_ActorParent;
inline constexpr auto& ActorQuery = ::SDLStatic_ActorQuery;
inline constexpr auto& ActorRemoveBody = ::SDLStatic_ActorRemoveBody;
inline constexpr auto& ActorRemoveLight = ::SDLStatic_ActorRemoveLight;
inline constexpr auto& ActorRenderTransform = ::SDLStatic_ActorRenderTransform;
inline constexpr auto& ActorSetAngularVelocity = ::SDLStatic_ActorSetAngularVelocity;
inline constexpr auto& ActorSetEnabled = ::SDLStatic_ActorSetEnabled;
inline constexpr auto& ActorSetLocal = ::SDLStatic_ActorSetLocal;
inline constexpr auto& ActorSetPosition = ::SDLStatic_ActorSetPosition;
inline constexpr auto& ActorSetTags = ::SDLStatic_ActorSetTags;
inline constexpr auto& ActorSetVelocity = ::SDLStatic_ActorSetVelocity;
inline constexpr auto& ActorSpawn = ::SDLStatic_ActorSpawn;
inline constexpr auto& ActorSprite = ::SDLStatic_ActorSprite;
inline constexpr auto& ActorState = ::SDLStatic_ActorState;
inline constexpr auto& ActorTeleport = ::SDLStatic_ActorTeleport;
inline constexpr auto& ActorTeleportBody = ::SDLStatic_ActorTeleportBody;
inline constexpr auto& ActorType = ::SDLStatic_ActorType;
inline constexpr auto& ActorVelocity = ::SDLStatic_ActorVelocity;
inline constexpr auto& ActorWakeBody = ::SDLStatic_ActorWakeBody;
inline constexpr auto& ActorWorld = ::SDLStatic_ActorWorld;
inline constexpr auto& AssetPath = ::SDLStatic_AssetPath;
inline constexpr auto& AssetRelease = ::SDLStatic_AssetRelease;
inline constexpr auto& AssetRetain = ::SDLStatic_AssetRetain;
inline constexpr auto& AssetStatusOf = ::SDLStatic_AssetStatusOf;
inline constexpr auto& AssetsFrameBudget = ::SDLStatic_AssetsFrameBudget;
inline constexpr auto& AssetsLoaded = ::SDLStatic_AssetsLoaded;
inline constexpr auto& AssetsPending = ::SDLStatic_AssetsPending;
inline constexpr auto& AssetsProgress = ::SDLStatic_AssetsProgress;
inline constexpr auto& AssetsSetFrameBudget = ::SDLStatic_AssetsSetFrameBudget;
inline constexpr auto& AssetsSetWorkers = ::SDLStatic_AssetsSetWorkers;
inline constexpr auto& AssetsWait = ::SDLStatic_AssetsWait;
inline constexpr auto& BidiItemize = ::SDLStatic_BidiItemize;
inline constexpr auto& BindingToString = ::SDLStatic_BindingToString;
inline constexpr auto& BodyDefault = ::SDLStatic_BodyDefault;
inline constexpr auto& CameraEnd = ::SDLStatic_CameraEnd;
inline constexpr auto& CameraFollow = ::SDLStatic_CameraFollow;
inline constexpr auto& CameraInit = ::SDLStatic_CameraInit;
inline constexpr auto& CameraPoint = ::SDLStatic_CameraPoint;
inline constexpr auto& CameraRect = ::SDLStatic_CameraRect;
inline constexpr auto& CameraShake = ::SDLStatic_CameraShake;
inline constexpr auto& CameraSnap = ::SDLStatic_CameraSnap;
inline constexpr auto& CameraSplit = ::SDLStatic_CameraSplit;
inline constexpr auto& CameraUpdate = ::SDLStatic_CameraUpdate;
inline constexpr auto& CompressData = ::SDLStatic_CompressData;
inline constexpr auto& ConnectSignal = ::SDLStatic_ConnectSignal;
inline constexpr auto& CountSignalConnections = ::SDLStatic_CountSignalConnections;
inline constexpr auto& CreateChipSFX = ::SDLStatic_CreateChipSFX;
inline constexpr auto& CreateChipTone = ::SDLStatic_CreateChipTone;
inline constexpr auto& CreateChipTune = ::SDLStatic_CreateChipTune;
inline constexpr auto& CreateEngine = ::SDLStatic_CreateEngine;
inline constexpr auto& CreateGuiWithGlyphs = ::SDLStatic_CreateGuiWithGlyphs;
inline constexpr auto& CreateSignalEmitter = ::SDLStatic_CreateSignalEmitter;
inline constexpr auto& DayNightAmbient = ::SDLStatic_DayNightAmbient;
inline constexpr auto& DayNightSunlight = ::SDLStatic_DayNightSunlight;
inline constexpr auto& DecodeDataBase64 = ::SDLStatic_DecodeDataBase64;
inline constexpr auto& DecompressData = ::SDLStatic_DecompressData;
inline constexpr auto& DecryptData = ::SDLStatic_DecryptData;
inline constexpr auto& DestroyEngine = ::SDLStatic_DestroyEngine;
inline constexpr auto& DestroySignalEmitter = ::SDLStatic_DestroySignalEmitter;
inline constexpr auto& DeviceAccelerometer = ::SDLStatic_DeviceAccelerometer;
inline constexpr auto& DeviceGyro = ::SDLStatic_DeviceGyro;
inline constexpr auto& DialogPath = ::SDLStatic_DialogPath;
inline constexpr auto& DialogReset = ::SDLStatic_DialogReset;
inline constexpr auto& DialogStatus = ::SDLStatic_DialogStatus;
inline constexpr auto& EmitSignal = ::SDLStatic_EmitSignal;
inline constexpr auto& EncodeDataBase64 = ::SDLStatic_EncodeDataBase64;
inline constexpr auto& EncryptData = ::SDLStatic_EncryptData;
inline constexpr auto& EngineAdvance = ::SDLStatic_EngineAdvance;
inline constexpr auto& EngineAlpha = ::SDLStatic_EngineAlpha;
inline constexpr auto& EngineAssetScale = ::SDLStatic_EngineAssetScale;
inline constexpr auto& EngineDelta = ::SDLStatic_EngineDelta;
inline constexpr auto& EngineDesignSize = ::SDLStatic_EngineDesignSize;
inline constexpr auto& EngineDisplay = ::SDLStatic_EngineDisplay;
inline constexpr auto& EngineDisplayCount = ::SDLStatic_EngineDisplayCount;
inline constexpr auto& EngineDisplayName = ::SDLStatic_EngineDisplayName;
inline constexpr auto& EngineEmbedMedia = ::SDLStatic_EngineEmbedMedia;
inline constexpr auto& EngineFps = ::SDLStatic_EngineFps;
inline constexpr auto& EngineFrameCount = ::SDLStatic_EngineFrameCount;
inline constexpr auto& EngineGraphics = ::SDLStatic_EngineGraphics;
inline constexpr auto& EngineMaxFps = ::SDLStatic_EngineMaxFps;
inline constexpr auto& EngineMediaPath = ::SDLStatic_EngineMediaPath;
inline constexpr auto& EngineMediaSource = ::SDLStatic_EngineMediaSource;
inline constexpr auto& EngineOverloadFrames = ::SDLStatic_EngineOverloadFrames;
inline constexpr auto& EnginePixelSize = ::SDLStatic_EnginePixelSize;
inline constexpr auto& EnginePresentation_ = ::SDLStatic_EnginePresentation_;
inline constexpr auto& EngineQuit = ::SDLStatic_EngineQuit;
inline constexpr auto& EngineRenderScale = ::SDLStatic_EngineRenderScale;
inline constexpr auto& EngineRenderer = ::SDLStatic_EngineRenderer;
inline constexpr auto& EngineSafeRect = ::SDLStatic_EngineSafeRect;
inline constexpr auto& EngineSetClearColor = ::SDLStatic_EngineSetClearColor;
inline constexpr auto& EngineSetHooks = ::SDLStatic_EngineSetHooks;
inline constexpr auto& EngineSetMaxFps = ::SDLStatic_EngineSetMaxFps;
inline constexpr auto& EngineSetMediaPassword = ::SDLStatic_EngineSetMediaPassword;
inline constexpr auto& EngineSetRefreshRate = ::SDLStatic_EngineSetRefreshRate;
inline constexpr auto& EngineSetTimeScale = ::SDLStatic_EngineSetTimeScale;
inline constexpr auto& EngineStep = ::SDLStatic_EngineStep;
inline constexpr auto& EngineStepsLastFrame = ::SDLStatic_EngineStepsLastFrame;
inline constexpr auto& EngineTickRate = ::SDLStatic_EngineTickRate;
inline constexpr auto& EngineTimeScale = ::SDLStatic_EngineTimeScale;
inline constexpr auto& EngineViewRect = ::SDLStatic_EngineViewRect;
inline constexpr auto& EngineWindow = ::SDLStatic_EngineWindow;
inline constexpr auto& EngineWindowToDesign = ::SDLStatic_EngineWindowToDesign;
inline constexpr auto& FingerCount = ::SDLStatic_FingerCount;
inline constexpr auto& FingerHeldInRect = ::SDLStatic_FingerHeldInRect;
inline constexpr auto& FingerInRect = ::SDLStatic_FingerInRect;
inline constexpr auto& GamepadAccelerometer = ::SDLStatic_GamepadAccelerometer;
inline constexpr auto& GamepadAxisValue = ::SDLStatic_GamepadAxisValue;
inline constexpr auto& GamepadCount = ::SDLStatic_GamepadCount;
inline constexpr auto& GamepadDeadzone = ::SDLStatic_GamepadDeadzone;
inline constexpr auto& GamepadGyro = ::SDLStatic_GamepadGyro;
inline constexpr auto& GamepadName = ::SDLStatic_GamepadName;
inline constexpr auto& GamepadStick = ::SDLStatic_GamepadStick;
inline constexpr auto& GamepadStopRumble = ::SDLStatic_GamepadStopRumble;
inline constexpr auto& GetFinger = ::SDLStatic_GetFinger;
inline constexpr auto& GraphicsArgsConfigPath = ::SDLStatic_GraphicsArgsConfigPath;
inline constexpr auto& GraphicsClamp = ::SDLStatic_GraphicsClamp;
inline constexpr auto& GraphicsConfigError = ::SDLStatic_GraphicsConfigError;
inline constexpr auto& GraphicsConfigPath = ::SDLStatic_GraphicsConfigPath;
inline constexpr auto& GraphicsDefaults = ::SDLStatic_GraphicsDefaults;
inline constexpr auto& GraphicsLightMapScale = ::SDLStatic_GraphicsLightMapScale;
inline constexpr auto& GraphicsLoadArgs = ::SDLStatic_GraphicsLoadArgs;
inline constexpr auto& GraphicsMaxDynamicLights = ::SDLStatic_GraphicsMaxDynamicLights;
inline constexpr auto& GraphicsParticleDensity = ::SDLStatic_GraphicsParticleDensity;
inline constexpr auto& GraphicsQualityName = ::SDLStatic_GraphicsQualityName;
inline constexpr auto& GraphicsResolve = ::SDLStatic_GraphicsResolve;
inline constexpr auto& GraphicsSafeMode = ::SDLStatic_GraphicsSafeMode;
inline constexpr auto& GraphicsSavePath = ::SDLStatic_GraphicsSavePath;
inline constexpr auto& GraphicsSetArchiveReader = ::SDLStatic_GraphicsSetArchiveReader;
inline constexpr auto& GraphicsShadowRays = ::SDLStatic_GraphicsShadowRays;
inline constexpr auto& GraphicsShadowSoftness = ::SDLStatic_GraphicsShadowSoftness;
inline constexpr auto& GraphicsToToml = ::SDLStatic_GraphicsToToml;
inline constexpr auto& GuiGridCell = ::SDLStatic_GuiGridCell;
inline constexpr auto& GuiGridCellSpan = ::SDLStatic_GuiGridCellSpan;
inline constexpr auto& GuiGridEnd = ::SDLStatic_GuiGridEnd;
inline constexpr auto& GuiGridNextRow = ::SDLStatic_GuiGridNextRow;
inline constexpr auto& IdleSeconds = ::SDLStatic_IdleSeconds;
inline constexpr auto& KeyModifiers = ::SDLStatic_KeyModifiers;
inline constexpr auto& LastInputDevice = ::SDLStatic_LastInputDevice;
inline constexpr auto& LightAddDarkZone = ::SDLStatic_LightAddDarkZone;
inline constexpr auto& LightAddOccluder = ::SDLStatic_LightAddOccluder;
inline constexpr auto& LightAddOccluderLine = ::SDLStatic_LightAddOccluderLine;
inline constexpr auto& LightAmbient = ::SDLStatic_LightAmbient;
inline constexpr auto& LightAt = ::SDLStatic_LightAt;
inline constexpr auto& LightCount = ::SDLStatic_LightCount;
inline constexpr auto& LightDefault = ::SDLStatic_LightDefault;
inline constexpr auto& LightHour = ::SDLStatic_LightHour;
inline constexpr auto& LightPreset_ = ::SDLStatic_LightPreset_;
inline constexpr auto& LightSetAmbient = ::SDLStatic_LightSetAmbient;
inline constexpr auto& LightSetAutoOccluders = ::SDLStatic_LightSetAutoOccluders;
inline constexpr auto& LightSetClock = ::SDLStatic_LightSetClock;
inline constexpr auto& LightSetPreset = ::SDLStatic_LightSetPreset;
inline constexpr auto& LightSunlight = ::SDLStatic_LightSunlight;
inline constexpr auto& LoadTextFile = ::SDLStatic_LoadTextFile;
inline constexpr auto& LoadTexture = ::SDLStatic_LoadTexture;
inline constexpr auto& LoadTextureAsync = ::SDLStatic_LoadTextureAsync;
inline constexpr auto& LoadVFSFile = ::SDLStatic_LoadVFSFile;
inline constexpr auto& MountMedia = ::SDLStatic_MountMedia;
inline constexpr auto& MouseDelta = ::SDLStatic_MouseDelta;
inline constexpr auto& MousePosition = ::SDLStatic_MousePosition;
inline constexpr auto& MouseWheel = ::SDLStatic_MouseWheel;
inline constexpr auto& OpenVFSRead = ::SDLStatic_OpenVFSRead;
inline constexpr auto& PhysicsBodyCount = ::SDLStatic_PhysicsBodyCount;
inline constexpr auto& PhysicsGravity = ::SDLStatic_PhysicsGravity;
inline constexpr auto& PhysicsOverlap = ::SDLStatic_PhysicsOverlap;
inline constexpr auto& PhysicsPixelsPerMetre = ::SDLStatic_PhysicsPixelsPerMetre;
inline constexpr auto& PhysicsRaycast = ::SDLStatic_PhysicsRaycast;
inline constexpr auto& PhysicsSetCollisionCallback = ::SDLStatic_PhysicsSetCollisionCallback;
inline constexpr auto& PhysicsSetGravity = ::SDLStatic_PhysicsSetGravity;
inline constexpr auto& PhysicsSetPaused = ::SDLStatic_PhysicsSetPaused;
inline constexpr auto& PhysicsSetPixelsPerMetre = ::SDLStatic_PhysicsSetPixelsPerMetre;
inline constexpr auto& PhysicsSetSubSteps = ::SDLStatic_PhysicsSetSubSteps;
inline constexpr auto& QuitDebugText = ::SDLStatic_QuitDebugText;
inline constexpr auto& RegexEscape = ::SDLStatic_RegexEscape;
inline constexpr auto& RenderLastStats = ::SDLStatic_RenderLastStats;
inline constexpr auto& RenderOverlay = ::SDLStatic_RenderOverlay;
inline constexpr auto& RenderWorld = ::SDLStatic_RenderWorld;
inline constexpr auto& SaveInfoOf = ::SDLStatic_SaveInfoOf;
inline constexpr auto& SavePath = ::SDLStatic_SavePath;
inline constexpr auto& SaveRead = ::SDLStatic_SaveRead;
inline constexpr auto& SaveSetIdentity = ::SDLStatic_SaveSetIdentity;
inline constexpr auto& SceneCurrent = ::SDLStatic_SceneCurrent;
inline constexpr auto& SceneDepth = ::SDLStatic_SceneDepth;
inline constexpr auto& SceneEngine = ::SDLStatic_SceneEngine;
inline constexpr auto& SceneFind = ::SDLStatic_SceneFind;
inline constexpr auto& SceneName = ::SDLStatic_SceneName;
inline constexpr auto& SceneSetTransitionColor = ::SDLStatic_SceneSetTransitionColor;
inline constexpr auto& SceneState = ::SDLStatic_SceneState;
inline constexpr auto& SetDebugTextSize = ::SDLStatic_SetDebugTextSize;
inline constexpr auto& SetDirectionRepeat = ::SDLStatic_SetDirectionRepeat;
inline constexpr auto& SetGamepadDeadzone = ::SDLStatic_SetGamepadDeadzone;
inline constexpr auto& SetTextInput = ::SDLStatic_SetTextInput;
inline constexpr auto& SetTriggerThreshold = ::SDLStatic_SetTriggerThreshold;
inline constexpr auto& SpriteDefault = ::SDLStatic_SpriteDefault;
inline constexpr auto& Text = ::SDLStatic_Text;
inline constexpr auto& TextCount = ::SDLStatic_TextCount;
inline constexpr auto& TextFormat = ::SDLStatic_TextFormat;
inline constexpr auto& TextLanguage = ::SDLStatic_TextLanguage;
inline constexpr auto& TextSetLanguage = ::SDLStatic_TextSetLanguage;
inline constexpr auto& TextSystemLanguages = ::SDLStatic_TextSystemLanguages;
inline constexpr auto& TextTyped = ::SDLStatic_TextTyped;
inline constexpr auto& Texture = ::SDLStatic_Texture;
inline constexpr auto& TouchPinch = ::SDLStatic_TouchPinch;
inline constexpr auto& TouchRotation = ::SDLStatic_TouchRotation;

}  // namespace ext
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_SDLSTATIC_H_
// clang-format on
