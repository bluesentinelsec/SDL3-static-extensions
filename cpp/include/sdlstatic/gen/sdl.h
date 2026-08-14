// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: SDL3 core
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_SDL_H_
#define SDLSTATIC_CPP_GEN_SDL_H_

#include <SDL3/SDL.h>
#include <SDL3/SDL.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace sdl {

// RAII owner for SDL_Window (destroyed with SDL_DestroyWindow).
class Window {
 public:
  static Result<Window> CreateWindow(const char *title, int w, int h, SDL_WindowFlags flags) {
    SDL_Window* created_ = ::SDL_CreateWindow(title, w, h, flags);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Window(created_);
  }
  static Result<Window> CreatePopupWindow(SDL_Window *parent, int offset_x, int offset_y, int w, int h, SDL_WindowFlags flags) {
    SDL_Window* created_ = ::SDL_CreatePopupWindow(parent, offset_x, offset_y, w, h, flags);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Window(created_);
  }
  static Result<Window> CreateWindowWithProperties(SDL_PropertiesID props) {
    SDL_Window* created_ = ::SDL_CreateWindowWithProperties(props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Window(created_);
  }

  Window() = default;
  ~Window() { reset(); }
  Window(Window&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Window& operator=(Window&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  SDL_Window* get() const { return value_; }
  SDL_Window* release() {
    SDL_Window* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyWindow(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status StartTextInput() {
    return ::SDL_StartTextInput(value_) ? Status() : Status::FromSdl();
  }
  Status StartTextInputWithProperties(SDL_PropertiesID props) {
    return ::SDL_StartTextInputWithProperties(value_, props) ? Status() : Status::FromSdl();
  }
  Status TextInputActive() {
    return ::SDL_TextInputActive(value_) ? Status() : Status::FromSdl();
  }
  Status StopTextInput() {
    return ::SDL_StopTextInput(value_) ? Status() : Status::FromSdl();
  }
  Status ClearComposition() {
    return ::SDL_ClearComposition(value_) ? Status() : Status::FromSdl();
  }
  Status SetTextInputArea(const SDL_Rect *rect, int cursor) {
    return ::SDL_SetTextInputArea(value_, rect, cursor) ? Status() : Status::FromSdl();
  }
  Status GetTextInputArea(SDL_Rect *rect, int *cursor) {
    return ::SDL_GetTextInputArea(value_, rect, cursor) ? Status() : Status::FromSdl();
  }
  Status ScreenKeyboardShown() {
    return ::SDL_ScreenKeyboardShown(value_) ? Status() : Status::FromSdl();
  }
  SDL_MetalView Metal_CreateView() {
    return ::SDL_Metal_CreateView(value_);
  }
  void WarpMouseInWindow(float x, float y) { ::SDL_WarpMouseInWindow(value_, x, y); }
  Status SetWindowRelativeMouseMode(bool enabled) {
    return ::SDL_SetWindowRelativeMouseMode(value_, enabled) ? Status() : Status::FromSdl();
  }
  Status GetWindowRelativeMouseMode() {
    return ::SDL_GetWindowRelativeMouseMode(value_) ? Status() : Status::FromSdl();
  }
  SDL_Renderer* GetRenderer() {
    return ::SDL_GetRenderer(value_);
  }
  SDL_DisplayID GetDisplayForWindow() {
    return ::SDL_GetDisplayForWindow(value_);
  }
  float GetWindowPixelDensity() {
    return ::SDL_GetWindowPixelDensity(value_);
  }
  float GetWindowDisplayScale() {
    return ::SDL_GetWindowDisplayScale(value_);
  }
  Status SetWindowFullscreenMode(const SDL_DisplayMode *mode) {
    return ::SDL_SetWindowFullscreenMode(value_, mode) ? Status() : Status::FromSdl();
  }
  const SDL_DisplayMode* GetWindowFullscreenMode() {
    return ::SDL_GetWindowFullscreenMode(value_);
  }
  void* GetWindowICCProfile(size_t *size) {
    return ::SDL_GetWindowICCProfile(value_, size);
  }
  SDL_PixelFormat GetWindowPixelFormat() {
    return ::SDL_GetWindowPixelFormat(value_);
  }
  SDL_WindowID GetWindowID() {
    return ::SDL_GetWindowID(value_);
  }
  SDL_Window* GetWindowParent() {
    return ::SDL_GetWindowParent(value_);
  }
  SDL_PropertiesID GetWindowProperties() {
    return ::SDL_GetWindowProperties(value_);
  }
  SDL_WindowFlags GetWindowFlags() {
    return ::SDL_GetWindowFlags(value_);
  }
  Status SetWindowTitle(const char *title) {
    return ::SDL_SetWindowTitle(value_, title) ? Status() : Status::FromSdl();
  }
  const char* GetWindowTitle() {
    return ::SDL_GetWindowTitle(value_);
  }
  Status SetWindowIcon(SDL_Surface *icon) {
    return ::SDL_SetWindowIcon(value_, icon) ? Status() : Status::FromSdl();
  }
  Status SetWindowPosition(int x, int y) {
    return ::SDL_SetWindowPosition(value_, x, y) ? Status() : Status::FromSdl();
  }
  Status GetWindowPosition(int *x, int *y) {
    return ::SDL_GetWindowPosition(value_, x, y) ? Status() : Status::FromSdl();
  }
  Status SetWindowSize(int w, int h) {
    return ::SDL_SetWindowSize(value_, w, h) ? Status() : Status::FromSdl();
  }
  Status GetWindowSize(int *w, int *h) {
    return ::SDL_GetWindowSize(value_, w, h) ? Status() : Status::FromSdl();
  }
  Status GetWindowSafeArea(SDL_Rect *rect) {
    return ::SDL_GetWindowSafeArea(value_, rect) ? Status() : Status::FromSdl();
  }
  Status SetWindowAspectRatio(float min_aspect, float max_aspect) {
    return ::SDL_SetWindowAspectRatio(value_, min_aspect, max_aspect) ? Status() : Status::FromSdl();
  }
  Status GetWindowAspectRatio(float *min_aspect, float *max_aspect) {
    return ::SDL_GetWindowAspectRatio(value_, min_aspect, max_aspect) ? Status() : Status::FromSdl();
  }
  Status GetWindowBordersSize(int *top, int *left, int *bottom, int *right) {
    return ::SDL_GetWindowBordersSize(value_, top, left, bottom, right) ? Status() : Status::FromSdl();
  }
  Status GetWindowSizeInPixels(int *w, int *h) {
    return ::SDL_GetWindowSizeInPixels(value_, w, h) ? Status() : Status::FromSdl();
  }
  Status SetWindowMinimumSize(int min_w, int min_h) {
    return ::SDL_SetWindowMinimumSize(value_, min_w, min_h) ? Status() : Status::FromSdl();
  }
  Status GetWindowMinimumSize(int *w, int *h) {
    return ::SDL_GetWindowMinimumSize(value_, w, h) ? Status() : Status::FromSdl();
  }
  Status SetWindowMaximumSize(int max_w, int max_h) {
    return ::SDL_SetWindowMaximumSize(value_, max_w, max_h) ? Status() : Status::FromSdl();
  }
  Status GetWindowMaximumSize(int *w, int *h) {
    return ::SDL_GetWindowMaximumSize(value_, w, h) ? Status() : Status::FromSdl();
  }
  Status SetWindowBordered(bool bordered) {
    return ::SDL_SetWindowBordered(value_, bordered) ? Status() : Status::FromSdl();
  }
  Status SetWindowResizable(bool resizable) {
    return ::SDL_SetWindowResizable(value_, resizable) ? Status() : Status::FromSdl();
  }
  Status SetWindowAlwaysOnTop(bool on_top) {
    return ::SDL_SetWindowAlwaysOnTop(value_, on_top) ? Status() : Status::FromSdl();
  }
  Status SetWindowFillDocument(bool fill) {
    return ::SDL_SetWindowFillDocument(value_, fill) ? Status() : Status::FromSdl();
  }
  Status ShowWindow() {
    return ::SDL_ShowWindow(value_) ? Status() : Status::FromSdl();
  }
  Status HideWindow() {
    return ::SDL_HideWindow(value_) ? Status() : Status::FromSdl();
  }
  Status RaiseWindow() {
    return ::SDL_RaiseWindow(value_) ? Status() : Status::FromSdl();
  }
  Status MaximizeWindow() {
    return ::SDL_MaximizeWindow(value_) ? Status() : Status::FromSdl();
  }
  Status MinimizeWindow() {
    return ::SDL_MinimizeWindow(value_) ? Status() : Status::FromSdl();
  }
  Status RestoreWindow() {
    return ::SDL_RestoreWindow(value_) ? Status() : Status::FromSdl();
  }
  Status SetWindowFullscreen(bool fullscreen) {
    return ::SDL_SetWindowFullscreen(value_, fullscreen) ? Status() : Status::FromSdl();
  }
  Status SyncWindow() {
    return ::SDL_SyncWindow(value_) ? Status() : Status::FromSdl();
  }
  Status WindowHasSurface() {
    return ::SDL_WindowHasSurface(value_) ? Status() : Status::FromSdl();
  }
  SDL_Surface* GetWindowSurface() {
    return ::SDL_GetWindowSurface(value_);
  }
  Status SetWindowSurfaceVSync(int vsync) {
    return ::SDL_SetWindowSurfaceVSync(value_, vsync) ? Status() : Status::FromSdl();
  }
  Status GetWindowSurfaceVSync(int *vsync) {
    return ::SDL_GetWindowSurfaceVSync(value_, vsync) ? Status() : Status::FromSdl();
  }
  Status UpdateWindowSurface() {
    return ::SDL_UpdateWindowSurface(value_) ? Status() : Status::FromSdl();
  }
  Status UpdateWindowSurfaceRects(const SDL_Rect *rects, int numrects) {
    return ::SDL_UpdateWindowSurfaceRects(value_, rects, numrects) ? Status() : Status::FromSdl();
  }
  Status DestroyWindowSurface() {
    return ::SDL_DestroyWindowSurface(value_) ? Status() : Status::FromSdl();
  }
  Status SetWindowKeyboardGrab(bool grabbed) {
    return ::SDL_SetWindowKeyboardGrab(value_, grabbed) ? Status() : Status::FromSdl();
  }
  Status SetWindowMouseGrab(bool grabbed) {
    return ::SDL_SetWindowMouseGrab(value_, grabbed) ? Status() : Status::FromSdl();
  }
  Status GetWindowKeyboardGrab() {
    return ::SDL_GetWindowKeyboardGrab(value_) ? Status() : Status::FromSdl();
  }
  Status GetWindowMouseGrab() {
    return ::SDL_GetWindowMouseGrab(value_) ? Status() : Status::FromSdl();
  }
  Status SetWindowMouseRect(const SDL_Rect *rect) {
    return ::SDL_SetWindowMouseRect(value_, rect) ? Status() : Status::FromSdl();
  }
  const SDL_Rect* GetWindowMouseRect() {
    return ::SDL_GetWindowMouseRect(value_);
  }
  Status SetWindowOpacity(float opacity) {
    return ::SDL_SetWindowOpacity(value_, opacity) ? Status() : Status::FromSdl();
  }
  float GetWindowOpacity() {
    return ::SDL_GetWindowOpacity(value_);
  }
  Status SetWindowParent(SDL_Window *parent) {
    return ::SDL_SetWindowParent(value_, parent) ? Status() : Status::FromSdl();
  }
  Status SetWindowModal(bool modal) {
    return ::SDL_SetWindowModal(value_, modal) ? Status() : Status::FromSdl();
  }
  Status SetWindowFocusable(bool focusable) {
    return ::SDL_SetWindowFocusable(value_, focusable) ? Status() : Status::FromSdl();
  }
  Status ShowWindowSystemMenu(int x, int y) {
    return ::SDL_ShowWindowSystemMenu(value_, x, y) ? Status() : Status::FromSdl();
  }
  Status SetWindowHitTest(SDL_HitTest callback, void *callback_data) {
    return ::SDL_SetWindowHitTest(value_, callback, callback_data) ? Status() : Status::FromSdl();
  }
  Status SetWindowShape(SDL_Surface *shape) {
    return ::SDL_SetWindowShape(value_, shape) ? Status() : Status::FromSdl();
  }
  Status FlashWindow(SDL_FlashOperation operation) {
    return ::SDL_FlashWindow(value_, operation) ? Status() : Status::FromSdl();
  }
  Status SetWindowProgressState(SDL_ProgressState state) {
    return ::SDL_SetWindowProgressState(value_, state) ? Status() : Status::FromSdl();
  }
  SDL_ProgressState GetWindowProgressState() {
    return ::SDL_GetWindowProgressState(value_);
  }
  Status SetWindowProgressValue(float value) {
    return ::SDL_SetWindowProgressValue(value_, value) ? Status() : Status::FromSdl();
  }
  float GetWindowProgressValue() {
    return ::SDL_GetWindowProgressValue(value_);
  }
  SDL_GLContext GL_CreateContext() {
    return ::SDL_GL_CreateContext(value_);
  }
  Status GL_MakeCurrent(SDL_GLContext context) {
    return ::SDL_GL_MakeCurrent(value_, context) ? Status() : Status::FromSdl();
  }
  SDL_EGLSurface EGL_GetWindowSurface() {
    return ::SDL_EGL_GetWindowSurface(value_);
  }
  Status GL_SwapWindow() {
    return ::SDL_GL_SwapWindow(value_) ? Status() : Status::FromSdl();
  }
 private:
  explicit Window(SDL_Window* value) : value_(value), engaged_(true) {}
  SDL_Window* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Renderer (destroyed with SDL_DestroyRenderer).
class Renderer {
 public:
  static Result<Renderer> CreateRenderer(SDL_Window *window, const char *name) {
    SDL_Renderer* created_ = ::SDL_CreateRenderer(window, name);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Renderer(created_);
  }
  static Result<Renderer> CreateRendererWithProperties(SDL_PropertiesID props) {
    SDL_Renderer* created_ = ::SDL_CreateRendererWithProperties(props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Renderer(created_);
  }
  static Result<Renderer> CreateSoftwareRenderer(SDL_Surface *surface) {
    SDL_Renderer* created_ = ::SDL_CreateSoftwareRenderer(surface);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Renderer(created_);
  }

  Renderer() = default;
  ~Renderer() { reset(); }
  Renderer(Renderer&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Renderer& operator=(Renderer&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Renderer(const Renderer&) = delete;
  Renderer& operator=(const Renderer&) = delete;

  SDL_Renderer* get() const { return value_; }
  SDL_Renderer* release() {
    SDL_Renderer* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyRenderer(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_GPUDevice* GetGPURendererDevice() {
    return ::SDL_GetGPURendererDevice(value_);
  }
  SDL_Window* GetRenderWindow() {
    return ::SDL_GetRenderWindow(value_);
  }
  const char* GetRendererName() {
    return ::SDL_GetRendererName(value_);
  }
  SDL_PropertiesID GetRendererProperties() {
    return ::SDL_GetRendererProperties(value_);
  }
  Status GetRenderOutputSize(int *w, int *h) {
    return ::SDL_GetRenderOutputSize(value_, w, h) ? Status() : Status::FromSdl();
  }
  Status GetCurrentRenderOutputSize(int *w, int *h) {
    return ::SDL_GetCurrentRenderOutputSize(value_, w, h) ? Status() : Status::FromSdl();
  }
  Status SetRenderTarget(SDL_Texture *texture) {
    return ::SDL_SetRenderTarget(value_, texture) ? Status() : Status::FromSdl();
  }
  SDL_Texture* GetRenderTarget() {
    return ::SDL_GetRenderTarget(value_);
  }
  Status SetRenderLogicalPresentation(int w, int h, SDL_RendererLogicalPresentation mode) {
    return ::SDL_SetRenderLogicalPresentation(value_, w, h, mode) ? Status() : Status::FromSdl();
  }
  Status GetRenderLogicalPresentation(int *w, int *h, SDL_RendererLogicalPresentation *mode) {
    return ::SDL_GetRenderLogicalPresentation(value_, w, h, mode) ? Status() : Status::FromSdl();
  }
  Status GetRenderLogicalPresentationRect(SDL_FRect *rect) {
    return ::SDL_GetRenderLogicalPresentationRect(value_, rect) ? Status() : Status::FromSdl();
  }
  Status RenderCoordinatesFromWindow(float window_x, float window_y, float *x, float *y) {
    return ::SDL_RenderCoordinatesFromWindow(value_, window_x, window_y, x, y) ? Status() : Status::FromSdl();
  }
  Status RenderCoordinatesToWindow(float x, float y, float *window_x, float *window_y) {
    return ::SDL_RenderCoordinatesToWindow(value_, x, y, window_x, window_y) ? Status() : Status::FromSdl();
  }
  Status ConvertEventToRenderCoordinates(SDL_Event *event) {
    return ::SDL_ConvertEventToRenderCoordinates(value_, event) ? Status() : Status::FromSdl();
  }
  Status SetRenderViewport(const SDL_Rect *rect) {
    return ::SDL_SetRenderViewport(value_, rect) ? Status() : Status::FromSdl();
  }
  Status GetRenderViewport(SDL_Rect *rect) {
    return ::SDL_GetRenderViewport(value_, rect) ? Status() : Status::FromSdl();
  }
  Status RenderViewportSet() {
    return ::SDL_RenderViewportSet(value_) ? Status() : Status::FromSdl();
  }
  Status GetRenderSafeArea(SDL_Rect *rect) {
    return ::SDL_GetRenderSafeArea(value_, rect) ? Status() : Status::FromSdl();
  }
  Status SetRenderClipRect(const SDL_Rect *rect) {
    return ::SDL_SetRenderClipRect(value_, rect) ? Status() : Status::FromSdl();
  }
  Status GetRenderClipRect(SDL_Rect *rect) {
    return ::SDL_GetRenderClipRect(value_, rect) ? Status() : Status::FromSdl();
  }
  Status RenderClipEnabled() {
    return ::SDL_RenderClipEnabled(value_) ? Status() : Status::FromSdl();
  }
  Status SetRenderScale(float scaleX, float scaleY) {
    return ::SDL_SetRenderScale(value_, scaleX, scaleY) ? Status() : Status::FromSdl();
  }
  Status GetRenderScale(float *scaleX, float *scaleY) {
    return ::SDL_GetRenderScale(value_, scaleX, scaleY) ? Status() : Status::FromSdl();
  }
  Status SetRenderDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    return ::SDL_SetRenderDrawColor(value_, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status SetRenderDrawColorFloat(float r, float g, float b, float a) {
    return ::SDL_SetRenderDrawColorFloat(value_, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status GetRenderDrawColor(Uint8 *r, Uint8 *g, Uint8 *b, Uint8 *a) {
    return ::SDL_GetRenderDrawColor(value_, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status GetRenderDrawColorFloat(float *r, float *g, float *b, float *a) {
    return ::SDL_GetRenderDrawColorFloat(value_, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status SetRenderColorScale(float scale) {
    return ::SDL_SetRenderColorScale(value_, scale) ? Status() : Status::FromSdl();
  }
  Status GetRenderColorScale(float *scale) {
    return ::SDL_GetRenderColorScale(value_, scale) ? Status() : Status::FromSdl();
  }
  Status SetRenderDrawBlendMode(SDL_BlendMode blendMode) {
    return ::SDL_SetRenderDrawBlendMode(value_, blendMode) ? Status() : Status::FromSdl();
  }
  Status GetRenderDrawBlendMode(SDL_BlendMode *blendMode) {
    return ::SDL_GetRenderDrawBlendMode(value_, blendMode) ? Status() : Status::FromSdl();
  }
  Status RenderClear() {
    return ::SDL_RenderClear(value_) ? Status() : Status::FromSdl();
  }
  Status RenderPoint(float x, float y) {
    return ::SDL_RenderPoint(value_, x, y) ? Status() : Status::FromSdl();
  }
  Status RenderPoints(const SDL_FPoint *points, int count) {
    return ::SDL_RenderPoints(value_, points, count) ? Status() : Status::FromSdl();
  }
  Status RenderLine(float x1, float y1, float x2, float y2) {
    return ::SDL_RenderLine(value_, x1, y1, x2, y2) ? Status() : Status::FromSdl();
  }
  Status RenderLines(const SDL_FPoint *points, int count) {
    return ::SDL_RenderLines(value_, points, count) ? Status() : Status::FromSdl();
  }
  Status RenderRect(const SDL_FRect *rect) {
    return ::SDL_RenderRect(value_, rect) ? Status() : Status::FromSdl();
  }
  Status RenderRects(const SDL_FRect *rects, int count) {
    return ::SDL_RenderRects(value_, rects, count) ? Status() : Status::FromSdl();
  }
  Status RenderFillRect(const SDL_FRect *rect) {
    return ::SDL_RenderFillRect(value_, rect) ? Status() : Status::FromSdl();
  }
  Status RenderFillRects(const SDL_FRect *rects, int count) {
    return ::SDL_RenderFillRects(value_, rects, count) ? Status() : Status::FromSdl();
  }
  Status RenderTexture(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect) {
    return ::SDL_RenderTexture(value_, texture, srcrect, dstrect) ? Status() : Status::FromSdl();
  }
  Status RenderTextureRotated(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FRect *dstrect, double angle, const SDL_FPoint *center, SDL_FlipMode flip) {
    return ::SDL_RenderTextureRotated(value_, texture, srcrect, dstrect, angle, center, flip) ? Status() : Status::FromSdl();
  }
  Status RenderTextureAffine(SDL_Texture *texture, const SDL_FRect *srcrect, const SDL_FPoint *origin, const SDL_FPoint *right, const SDL_FPoint *down) {
    return ::SDL_RenderTextureAffine(value_, texture, srcrect, origin, right, down) ? Status() : Status::FromSdl();
  }
  Status RenderTextureTiled(SDL_Texture *texture, const SDL_FRect *srcrect, float scale, const SDL_FRect *dstrect) {
    return ::SDL_RenderTextureTiled(value_, texture, srcrect, scale, dstrect) ? Status() : Status::FromSdl();
  }
  Status RenderTexture9Grid(SDL_Texture *texture, const SDL_FRect *srcrect, float left_width, float right_width, float top_height, float bottom_height, float scale, const SDL_FRect *dstrect) {
    return ::SDL_RenderTexture9Grid(value_, texture, srcrect, left_width, right_width, top_height, bottom_height, scale, dstrect) ? Status() : Status::FromSdl();
  }
  Status RenderTexture9GridTiled(SDL_Texture *texture, const SDL_FRect *srcrect, float left_width, float right_width, float top_height, float bottom_height, float scale, const SDL_FRect *dstrect, float tileScale) {
    return ::SDL_RenderTexture9GridTiled(value_, texture, srcrect, left_width, right_width, top_height, bottom_height, scale, dstrect, tileScale) ? Status() : Status::FromSdl();
  }
  Status RenderGeometry(SDL_Texture *texture, const SDL_Vertex *vertices, int num_vertices, const int *indices, int num_indices) {
    return ::SDL_RenderGeometry(value_, texture, vertices, num_vertices, indices, num_indices) ? Status() : Status::FromSdl();
  }
  Status RenderGeometryRaw(SDL_Texture *texture, const float *xy, int xy_stride, const SDL_FColor *color, int color_stride, const float *uv, int uv_stride, int num_vertices, const void *indices, int num_indices, int size_indices) {
    return ::SDL_RenderGeometryRaw(value_, texture, xy, xy_stride, color, color_stride, uv, uv_stride, num_vertices, indices, num_indices, size_indices) ? Status() : Status::FromSdl();
  }
  Status SetRenderTextureAddressMode(SDL_TextureAddressMode u_mode, SDL_TextureAddressMode v_mode) {
    return ::SDL_SetRenderTextureAddressMode(value_, u_mode, v_mode) ? Status() : Status::FromSdl();
  }
  Status GetRenderTextureAddressMode(SDL_TextureAddressMode *u_mode, SDL_TextureAddressMode *v_mode) {
    return ::SDL_GetRenderTextureAddressMode(value_, u_mode, v_mode) ? Status() : Status::FromSdl();
  }
  SDL_Surface* RenderReadPixels(const SDL_Rect *rect) {
    return ::SDL_RenderReadPixels(value_, rect);
  }
  Status RenderPresent() {
    return ::SDL_RenderPresent(value_) ? Status() : Status::FromSdl();
  }
  Status FlushRenderer() {
    return ::SDL_FlushRenderer(value_) ? Status() : Status::FromSdl();
  }
  void* GetRenderMetalLayer() {
    return ::SDL_GetRenderMetalLayer(value_);
  }
  void* GetRenderMetalCommandEncoder() {
    return ::SDL_GetRenderMetalCommandEncoder(value_);
  }
  Status AddVulkanRenderSemaphores(Uint32 wait_stage_mask, Sint64 wait_semaphore, Sint64 signal_semaphore) {
    return ::SDL_AddVulkanRenderSemaphores(value_, wait_stage_mask, wait_semaphore, signal_semaphore) ? Status() : Status::FromSdl();
  }
  Status SetRenderVSync(int vsync) {
    return ::SDL_SetRenderVSync(value_, vsync) ? Status() : Status::FromSdl();
  }
  Status GetRenderVSync(int *vsync) {
    return ::SDL_GetRenderVSync(value_, vsync) ? Status() : Status::FromSdl();
  }
  Status RenderDebugText(float x, float y, const char *str) {
    return ::SDL_RenderDebugText(value_, x, y, str) ? Status() : Status::FromSdl();
  }
  Status SetDefaultTextureScaleMode(SDL_ScaleMode scale_mode) {
    return ::SDL_SetDefaultTextureScaleMode(value_, scale_mode) ? Status() : Status::FromSdl();
  }
  Status GetDefaultTextureScaleMode(SDL_ScaleMode *scale_mode) {
    return ::SDL_GetDefaultTextureScaleMode(value_, scale_mode) ? Status() : Status::FromSdl();
  }
  SDL_GPURenderState* CreateGPURenderState(const SDL_GPURenderStateCreateInfo *createinfo) {
    return ::SDL_CreateGPURenderState(value_, createinfo);
  }
  Status SetGPURenderState(SDL_GPURenderState *state) {
    return ::SDL_SetGPURenderState(value_, state) ? Status() : Status::FromSdl();
  }
 private:
  explicit Renderer(SDL_Renderer* value) : value_(value), engaged_(true) {}
  SDL_Renderer* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Texture (destroyed with SDL_DestroyTexture).
class Texture {
 public:
  static Result<Texture> CreateTexture(SDL_Renderer *renderer, SDL_PixelFormat format, SDL_TextureAccess access, int w, int h) {
    SDL_Texture* created_ = ::SDL_CreateTexture(renderer, format, access, w, h);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Texture(created_);
  }
  static Result<Texture> CreateTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface) {
    SDL_Texture* created_ = ::SDL_CreateTextureFromSurface(renderer, surface);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Texture(created_);
  }
  static Result<Texture> CreateTextureWithProperties(SDL_Renderer *renderer, SDL_PropertiesID props) {
    SDL_Texture* created_ = ::SDL_CreateTextureWithProperties(renderer, props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Texture(created_);
  }

  Texture() = default;
  ~Texture() { reset(); }
  Texture(Texture&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Texture& operator=(Texture&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Texture(const Texture&) = delete;
  Texture& operator=(const Texture&) = delete;

  SDL_Texture* get() const { return value_; }
  SDL_Texture* release() {
    SDL_Texture* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyTexture(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_PropertiesID GetTextureProperties() {
    return ::SDL_GetTextureProperties(value_);
  }
  SDL_Renderer* GetRendererFromTexture() {
    return ::SDL_GetRendererFromTexture(value_);
  }
  Status GetTextureSize(float *w, float *h) {
    return ::SDL_GetTextureSize(value_, w, h) ? Status() : Status::FromSdl();
  }
  Status SetTexturePalette(SDL_Palette *palette) {
    return ::SDL_SetTexturePalette(value_, palette) ? Status() : Status::FromSdl();
  }
  SDL_Palette* GetTexturePalette() {
    return ::SDL_GetTexturePalette(value_);
  }
  Status SetTextureColorMod(Uint8 r, Uint8 g, Uint8 b) {
    return ::SDL_SetTextureColorMod(value_, r, g, b) ? Status() : Status::FromSdl();
  }
  Status SetTextureColorModFloat(float r, float g, float b) {
    return ::SDL_SetTextureColorModFloat(value_, r, g, b) ? Status() : Status::FromSdl();
  }
  Status GetTextureColorMod(Uint8 *r, Uint8 *g, Uint8 *b) {
    return ::SDL_GetTextureColorMod(value_, r, g, b) ? Status() : Status::FromSdl();
  }
  Status GetTextureColorModFloat(float *r, float *g, float *b) {
    return ::SDL_GetTextureColorModFloat(value_, r, g, b) ? Status() : Status::FromSdl();
  }
  Status SetTextureAlphaMod(Uint8 alpha) {
    return ::SDL_SetTextureAlphaMod(value_, alpha) ? Status() : Status::FromSdl();
  }
  Status SetTextureAlphaModFloat(float alpha) {
    return ::SDL_SetTextureAlphaModFloat(value_, alpha) ? Status() : Status::FromSdl();
  }
  Status GetTextureAlphaMod(Uint8 *alpha) {
    return ::SDL_GetTextureAlphaMod(value_, alpha) ? Status() : Status::FromSdl();
  }
  Status GetTextureAlphaModFloat(float *alpha) {
    return ::SDL_GetTextureAlphaModFloat(value_, alpha) ? Status() : Status::FromSdl();
  }
  Status SetTextureBlendMode(SDL_BlendMode blendMode) {
    return ::SDL_SetTextureBlendMode(value_, blendMode) ? Status() : Status::FromSdl();
  }
  Status GetTextureBlendMode(SDL_BlendMode *blendMode) {
    return ::SDL_GetTextureBlendMode(value_, blendMode) ? Status() : Status::FromSdl();
  }
  Status SetTextureScaleMode(SDL_ScaleMode scaleMode) {
    return ::SDL_SetTextureScaleMode(value_, scaleMode) ? Status() : Status::FromSdl();
  }
  Status GetTextureScaleMode(SDL_ScaleMode *scaleMode) {
    return ::SDL_GetTextureScaleMode(value_, scaleMode) ? Status() : Status::FromSdl();
  }
  Status UpdateTexture(const SDL_Rect *rect, const void *pixels, int pitch) {
    return ::SDL_UpdateTexture(value_, rect, pixels, pitch) ? Status() : Status::FromSdl();
  }
  Status UpdateYUVTexture(const SDL_Rect *rect, const Uint8 *Yplane, int Ypitch, const Uint8 *Uplane, int Upitch, const Uint8 *Vplane, int Vpitch) {
    return ::SDL_UpdateYUVTexture(value_, rect, Yplane, Ypitch, Uplane, Upitch, Vplane, Vpitch) ? Status() : Status::FromSdl();
  }
  Status UpdateNVTexture(const SDL_Rect *rect, const Uint8 *Yplane, int Ypitch, const Uint8 *UVplane, int UVpitch) {
    return ::SDL_UpdateNVTexture(value_, rect, Yplane, Ypitch, UVplane, UVpitch) ? Status() : Status::FromSdl();
  }
  Status LockTexture(const SDL_Rect *rect, void **pixels, int *pitch) {
    return ::SDL_LockTexture(value_, rect, pixels, pitch) ? Status() : Status::FromSdl();
  }
  Status LockTextureToSurface(const SDL_Rect *rect, SDL_Surface **surface) {
    return ::SDL_LockTextureToSurface(value_, rect, surface) ? Status() : Status::FromSdl();
  }
  void UnlockTexture() { ::SDL_UnlockTexture(value_); }
 private:
  explicit Texture(SDL_Texture* value) : value_(value), engaged_(true) {}
  SDL_Texture* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Surface (destroyed with SDL_DestroySurface).
class Surface {
 public:
  static Result<Surface> CreateSurface(int width, int height, SDL_PixelFormat format) {
    SDL_Surface* created_ = ::SDL_CreateSurface(width, height, format);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> CreateSurfaceFrom(int width, int height, SDL_PixelFormat format, void *pixels, int pitch) {
    SDL_Surface* created_ = ::SDL_CreateSurfaceFrom(width, height, format, pixels, pitch);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> LoadBMP_IO(SDL_IOStream *src, bool closeio) {
    SDL_Surface* created_ = ::SDL_LoadBMP_IO(src, closeio);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> LoadBMP(const char *file) {
    SDL_Surface* created_ = ::SDL_LoadBMP(file);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> DuplicateSurface(SDL_Surface *surface) {
    SDL_Surface* created_ = ::SDL_DuplicateSurface(surface);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> ScaleSurface(SDL_Surface *surface, int width, int height, SDL_ScaleMode scaleMode) {
    SDL_Surface* created_ = ::SDL_ScaleSurface(surface, width, height, scaleMode);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> ConvertSurface(SDL_Surface *surface, SDL_PixelFormat format) {
    SDL_Surface* created_ = ::SDL_ConvertSurface(surface, format);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> ConvertSurfaceAndColorspace(SDL_Surface *surface, SDL_PixelFormat format, SDL_Palette *palette, SDL_Colorspace colorspace, SDL_PropertiesID props) {
    SDL_Surface* created_ = ::SDL_ConvertSurfaceAndColorspace(surface, format, palette, colorspace, props);
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

  SDL_PropertiesID GetSurfaceProperties() {
    return ::SDL_GetSurfaceProperties(value_);
  }
  Status SetSurfaceColorspace(SDL_Colorspace colorspace) {
    return ::SDL_SetSurfaceColorspace(value_, colorspace) ? Status() : Status::FromSdl();
  }
  SDL_Colorspace GetSurfaceColorspace() {
    return ::SDL_GetSurfaceColorspace(value_);
  }
  SDL_Palette* CreateSurfacePalette() {
    return ::SDL_CreateSurfacePalette(value_);
  }
  Status SetSurfacePalette(SDL_Palette *palette) {
    return ::SDL_SetSurfacePalette(value_, palette) ? Status() : Status::FromSdl();
  }
  SDL_Palette* GetSurfacePalette() {
    return ::SDL_GetSurfacePalette(value_);
  }
  Status AddSurfaceAlternateImage(SDL_Surface *image) {
    return ::SDL_AddSurfaceAlternateImage(value_, image) ? Status() : Status::FromSdl();
  }
  Status SurfaceHasAlternateImages() {
    return ::SDL_SurfaceHasAlternateImages(value_) ? Status() : Status::FromSdl();
  }
  SDL_Surface** GetSurfaceImages(int *count) {
    return ::SDL_GetSurfaceImages(value_, count);
  }
  void RemoveSurfaceAlternateImages() { ::SDL_RemoveSurfaceAlternateImages(value_); }
  Status LockSurface() {
    return ::SDL_LockSurface(value_) ? Status() : Status::FromSdl();
  }
  void UnlockSurface() { ::SDL_UnlockSurface(value_); }
  Status SaveBMP_IO(SDL_IOStream *dst, bool closeio) {
    return ::SDL_SaveBMP_IO(value_, dst, closeio) ? Status() : Status::FromSdl();
  }
  Status SaveBMP(const char *file) {
    return ::SDL_SaveBMP(value_, file) ? Status() : Status::FromSdl();
  }
  Status SavePNG_IO(SDL_IOStream *dst, bool closeio) {
    return ::SDL_SavePNG_IO(value_, dst, closeio) ? Status() : Status::FromSdl();
  }
  Status SavePNG(const char *file) {
    return ::SDL_SavePNG(value_, file) ? Status() : Status::FromSdl();
  }
  Status SetSurfaceRLE(bool enabled) {
    return ::SDL_SetSurfaceRLE(value_, enabled) ? Status() : Status::FromSdl();
  }
  Status SurfaceHasRLE() {
    return ::SDL_SurfaceHasRLE(value_) ? Status() : Status::FromSdl();
  }
  Status SetSurfaceColorKey(bool enabled, Uint32 key) {
    return ::SDL_SetSurfaceColorKey(value_, enabled, key) ? Status() : Status::FromSdl();
  }
  Status SurfaceHasColorKey() {
    return ::SDL_SurfaceHasColorKey(value_) ? Status() : Status::FromSdl();
  }
  Status GetSurfaceColorKey(Uint32 *key) {
    return ::SDL_GetSurfaceColorKey(value_, key) ? Status() : Status::FromSdl();
  }
  Status SetSurfaceColorMod(Uint8 r, Uint8 g, Uint8 b) {
    return ::SDL_SetSurfaceColorMod(value_, r, g, b) ? Status() : Status::FromSdl();
  }
  Status GetSurfaceColorMod(Uint8 *r, Uint8 *g, Uint8 *b) {
    return ::SDL_GetSurfaceColorMod(value_, r, g, b) ? Status() : Status::FromSdl();
  }
  Status SetSurfaceAlphaMod(Uint8 alpha) {
    return ::SDL_SetSurfaceAlphaMod(value_, alpha) ? Status() : Status::FromSdl();
  }
  Status GetSurfaceAlphaMod(Uint8 *alpha) {
    return ::SDL_GetSurfaceAlphaMod(value_, alpha) ? Status() : Status::FromSdl();
  }
  Status SetSurfaceBlendMode(SDL_BlendMode blendMode) {
    return ::SDL_SetSurfaceBlendMode(value_, blendMode) ? Status() : Status::FromSdl();
  }
  Status GetSurfaceBlendMode(SDL_BlendMode *blendMode) {
    return ::SDL_GetSurfaceBlendMode(value_, blendMode) ? Status() : Status::FromSdl();
  }
  Status SetSurfaceClipRect(const SDL_Rect *rect) {
    return ::SDL_SetSurfaceClipRect(value_, rect) ? Status() : Status::FromSdl();
  }
  Status GetSurfaceClipRect(SDL_Rect *rect) {
    return ::SDL_GetSurfaceClipRect(value_, rect) ? Status() : Status::FromSdl();
  }
  Status FlipSurface(SDL_FlipMode flip) {
    return ::SDL_FlipSurface(value_, flip) ? Status() : Status::FromSdl();
  }
  SDL_Surface* RotateSurface(float angle) {
    return ::SDL_RotateSurface(value_, angle);
  }
  Status PremultiplySurfaceAlpha(bool linear) {
    return ::SDL_PremultiplySurfaceAlpha(value_, linear) ? Status() : Status::FromSdl();
  }
  Status ClearSurface(float r, float g, float b, float a) {
    return ::SDL_ClearSurface(value_, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status FillSurfaceRect(const SDL_Rect *rect, Uint32 color) {
    return ::SDL_FillSurfaceRect(value_, rect, color) ? Status() : Status::FromSdl();
  }
  Status FillSurfaceRects(const SDL_Rect *rects, int count, Uint32 color) {
    return ::SDL_FillSurfaceRects(value_, rects, count, color) ? Status() : Status::FromSdl();
  }
  Status BlitSurface(const SDL_Rect *srcrect, SDL_Surface *dst, const SDL_Rect *dstrect) {
    return ::SDL_BlitSurface(value_, srcrect, dst, dstrect) ? Status() : Status::FromSdl();
  }
  Status BlitSurfaceUnchecked(const SDL_Rect *srcrect, SDL_Surface *dst, const SDL_Rect *dstrect) {
    return ::SDL_BlitSurfaceUnchecked(value_, srcrect, dst, dstrect) ? Status() : Status::FromSdl();
  }
  Status BlitSurfaceScaled(const SDL_Rect *srcrect, SDL_Surface *dst, const SDL_Rect *dstrect, SDL_ScaleMode scaleMode) {
    return ::SDL_BlitSurfaceScaled(value_, srcrect, dst, dstrect, scaleMode) ? Status() : Status::FromSdl();
  }
  Status BlitSurfaceUncheckedScaled(const SDL_Rect *srcrect, SDL_Surface *dst, const SDL_Rect *dstrect, SDL_ScaleMode scaleMode) {
    return ::SDL_BlitSurfaceUncheckedScaled(value_, srcrect, dst, dstrect, scaleMode) ? Status() : Status::FromSdl();
  }
  Status StretchSurface(const SDL_Rect *srcrect, SDL_Surface *dst, const SDL_Rect *dstrect, SDL_ScaleMode scaleMode) {
    return ::SDL_StretchSurface(value_, srcrect, dst, dstrect, scaleMode) ? Status() : Status::FromSdl();
  }
  Status BlitSurfaceTiled(const SDL_Rect *srcrect, SDL_Surface *dst, const SDL_Rect *dstrect) {
    return ::SDL_BlitSurfaceTiled(value_, srcrect, dst, dstrect) ? Status() : Status::FromSdl();
  }
  Status BlitSurfaceTiledWithScale(const SDL_Rect *srcrect, float scale, SDL_ScaleMode scaleMode, SDL_Surface *dst, const SDL_Rect *dstrect) {
    return ::SDL_BlitSurfaceTiledWithScale(value_, srcrect, scale, scaleMode, dst, dstrect) ? Status() : Status::FromSdl();
  }
  Status BlitSurface9Grid(const SDL_Rect *srcrect, int left_width, int right_width, int top_height, int bottom_height, float scale, SDL_ScaleMode scaleMode, SDL_Surface *dst, const SDL_Rect *dstrect) {
    return ::SDL_BlitSurface9Grid(value_, srcrect, left_width, right_width, top_height, bottom_height, scale, scaleMode, dst, dstrect) ? Status() : Status::FromSdl();
  }
  Uint32 MapSurfaceRGB(Uint8 r, Uint8 g, Uint8 b) {
    return ::SDL_MapSurfaceRGB(value_, r, g, b);
  }
  Uint32 MapSurfaceRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    return ::SDL_MapSurfaceRGBA(value_, r, g, b, a);
  }
  Status ReadSurfacePixel(int x, int y, Uint8 *r, Uint8 *g, Uint8 *b, Uint8 *a) {
    return ::SDL_ReadSurfacePixel(value_, x, y, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status ReadSurfacePixelFloat(int x, int y, float *r, float *g, float *b, float *a) {
    return ::SDL_ReadSurfacePixelFloat(value_, x, y, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status WriteSurfacePixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    return ::SDL_WriteSurfacePixel(value_, x, y, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status WriteSurfacePixelFloat(int x, int y, float r, float g, float b, float a) {
    return ::SDL_WriteSurfacePixelFloat(value_, x, y, r, g, b, a) ? Status() : Status::FromSdl();
  }
 private:
  explicit Surface(SDL_Surface* value) : value_(value), engaged_(true) {}
  SDL_Surface* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_AudioStream (destroyed with SDL_DestroyAudioStream).
class AudioStream {
 public:
  static Result<AudioStream> CreateAudioStream(const SDL_AudioSpec *src_spec, const SDL_AudioSpec *dst_spec) {
    SDL_AudioStream* created_ = ::SDL_CreateAudioStream(src_spec, dst_spec);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return AudioStream(created_);
  }
  static Result<AudioStream> OpenAudioDeviceStream(SDL_AudioDeviceID devid, const SDL_AudioSpec *spec, SDL_AudioStreamCallback callback, void *userdata) {
    SDL_AudioStream* created_ = ::SDL_OpenAudioDeviceStream(devid, spec, callback, userdata);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return AudioStream(created_);
  }

  AudioStream() = default;
  ~AudioStream() { reset(); }
  AudioStream(AudioStream&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  AudioStream& operator=(AudioStream&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  AudioStream(const AudioStream&) = delete;
  AudioStream& operator=(const AudioStream&) = delete;

  SDL_AudioStream* get() const { return value_; }
  SDL_AudioStream* release() {
    SDL_AudioStream* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyAudioStream(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  void UnbindAudioStream() { ::SDL_UnbindAudioStream(value_); }
  SDL_AudioDeviceID GetAudioStreamDevice() {
    return ::SDL_GetAudioStreamDevice(value_);
  }
  SDL_PropertiesID GetAudioStreamProperties() {
    return ::SDL_GetAudioStreamProperties(value_);
  }
  Status GetAudioStreamFormat(SDL_AudioSpec *src_spec, SDL_AudioSpec *dst_spec) {
    return ::SDL_GetAudioStreamFormat(value_, src_spec, dst_spec) ? Status() : Status::FromSdl();
  }
  Status SetAudioStreamFormat(const SDL_AudioSpec *src_spec, const SDL_AudioSpec *dst_spec) {
    return ::SDL_SetAudioStreamFormat(value_, src_spec, dst_spec) ? Status() : Status::FromSdl();
  }
  float GetAudioStreamFrequencyRatio() {
    return ::SDL_GetAudioStreamFrequencyRatio(value_);
  }
  Status SetAudioStreamFrequencyRatio(float ratio) {
    return ::SDL_SetAudioStreamFrequencyRatio(value_, ratio) ? Status() : Status::FromSdl();
  }
  float GetAudioStreamGain() {
    return ::SDL_GetAudioStreamGain(value_);
  }
  Status SetAudioStreamGain(float gain) {
    return ::SDL_SetAudioStreamGain(value_, gain) ? Status() : Status::FromSdl();
  }
  int* GetAudioStreamInputChannelMap(int *count) {
    return ::SDL_GetAudioStreamInputChannelMap(value_, count);
  }
  int* GetAudioStreamOutputChannelMap(int *count) {
    return ::SDL_GetAudioStreamOutputChannelMap(value_, count);
  }
  Status SetAudioStreamInputChannelMap(const int *chmap, int count) {
    return ::SDL_SetAudioStreamInputChannelMap(value_, chmap, count) ? Status() : Status::FromSdl();
  }
  Status SetAudioStreamOutputChannelMap(const int *chmap, int count) {
    return ::SDL_SetAudioStreamOutputChannelMap(value_, chmap, count) ? Status() : Status::FromSdl();
  }
  Status PutAudioStreamData(const void *buf, int len) {
    return ::SDL_PutAudioStreamData(value_, buf, len) ? Status() : Status::FromSdl();
  }
  Status PutAudioStreamDataNoCopy(const void *buf, int len, SDL_AudioStreamDataCompleteCallback callback, void *userdata) {
    return ::SDL_PutAudioStreamDataNoCopy(value_, buf, len, callback, userdata) ? Status() : Status::FromSdl();
  }
  Status PutAudioStreamPlanarData(const void * const *channel_buffers, int num_channels, int num_samples) {
    return ::SDL_PutAudioStreamPlanarData(value_, channel_buffers, num_channels, num_samples) ? Status() : Status::FromSdl();
  }
  int GetAudioStreamData(void *buf, int len) {
    return ::SDL_GetAudioStreamData(value_, buf, len);
  }
  int GetAudioStreamAvailable() {
    return ::SDL_GetAudioStreamAvailable(value_);
  }
  int GetAudioStreamQueued() {
    return ::SDL_GetAudioStreamQueued(value_);
  }
  Status FlushAudioStream() {
    return ::SDL_FlushAudioStream(value_) ? Status() : Status::FromSdl();
  }
  Status ClearAudioStream() {
    return ::SDL_ClearAudioStream(value_) ? Status() : Status::FromSdl();
  }
  Status PauseAudioStreamDevice() {
    return ::SDL_PauseAudioStreamDevice(value_) ? Status() : Status::FromSdl();
  }
  Status ResumeAudioStreamDevice() {
    return ::SDL_ResumeAudioStreamDevice(value_) ? Status() : Status::FromSdl();
  }
  Status AudioStreamDevicePaused() {
    return ::SDL_AudioStreamDevicePaused(value_) ? Status() : Status::FromSdl();
  }
  Status LockAudioStream() {
    return ::SDL_LockAudioStream(value_) ? Status() : Status::FromSdl();
  }
  Status UnlockAudioStream() {
    return ::SDL_UnlockAudioStream(value_) ? Status() : Status::FromSdl();
  }
  Status SetAudioStreamGetCallback(SDL_AudioStreamCallback callback, void *userdata) {
    return ::SDL_SetAudioStreamGetCallback(value_, callback, userdata) ? Status() : Status::FromSdl();
  }
  Status SetAudioStreamPutCallback(SDL_AudioStreamCallback callback, void *userdata) {
    return ::SDL_SetAudioStreamPutCallback(value_, callback, userdata) ? Status() : Status::FromSdl();
  }
 private:
  explicit AudioStream(SDL_AudioStream* value) : value_(value), engaged_(true) {}
  SDL_AudioStream* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Camera (destroyed with SDL_CloseCamera).
class Camera {
 public:
  static Result<Camera> OpenCamera(SDL_CameraID instance_id, const SDL_CameraSpec *spec) {
    SDL_Camera* created_ = ::SDL_OpenCamera(instance_id, spec);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Camera(created_);
  }

  Camera() = default;
  ~Camera() { reset(); }
  Camera(Camera&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Camera& operator=(Camera&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Camera(const Camera&) = delete;
  Camera& operator=(const Camera&) = delete;

  SDL_Camera* get() const { return value_; }
  SDL_Camera* release() {
    SDL_Camera* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_CloseCamera(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_CameraPermissionState GetCameraPermissionState() {
    return ::SDL_GetCameraPermissionState(value_);
  }
  SDL_CameraID GetCameraID() {
    return ::SDL_GetCameraID(value_);
  }
  SDL_PropertiesID GetCameraProperties() {
    return ::SDL_GetCameraProperties(value_);
  }
  Status GetCameraFormat(SDL_CameraSpec *spec) {
    return ::SDL_GetCameraFormat(value_, spec) ? Status() : Status::FromSdl();
  }
  SDL_Surface* AcquireCameraFrame(Uint64 *timestampNS) {
    return ::SDL_AcquireCameraFrame(value_, timestampNS);
  }
  void ReleaseCameraFrame(SDL_Surface *frame) { ::SDL_ReleaseCameraFrame(value_, frame); }
 private:
  explicit Camera(SDL_Camera* value) : value_(value), engaged_(true) {}
  SDL_Camera* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Gamepad (destroyed with SDL_CloseGamepad).
class Gamepad {
 public:
  static Result<Gamepad> OpenGamepad(SDL_JoystickID instance_id) {
    SDL_Gamepad* created_ = ::SDL_OpenGamepad(instance_id);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Gamepad(created_);
  }

  Gamepad() = default;
  ~Gamepad() { reset(); }
  Gamepad(Gamepad&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Gamepad& operator=(Gamepad&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Gamepad(const Gamepad&) = delete;
  Gamepad& operator=(const Gamepad&) = delete;

  SDL_Gamepad* get() const { return value_; }
  SDL_Gamepad* release() {
    SDL_Gamepad* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_CloseGamepad(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  char* GetGamepadMapping() {
    return ::SDL_GetGamepadMapping(value_);
  }
  SDL_PropertiesID GetGamepadProperties() {
    return ::SDL_GetGamepadProperties(value_);
  }
  SDL_JoystickID GetGamepadID() {
    return ::SDL_GetGamepadID(value_);
  }
  const char* GetGamepadName() {
    return ::SDL_GetGamepadName(value_);
  }
  const char* GetGamepadPath() {
    return ::SDL_GetGamepadPath(value_);
  }
  SDL_GamepadType GetGamepadType() {
    return ::SDL_GetGamepadType(value_);
  }
  SDL_GamepadType GetRealGamepadType() {
    return ::SDL_GetRealGamepadType(value_);
  }
  int GetGamepadPlayerIndex() {
    return ::SDL_GetGamepadPlayerIndex(value_);
  }
  Status SetGamepadPlayerIndex(int player_index) {
    return ::SDL_SetGamepadPlayerIndex(value_, player_index) ? Status() : Status::FromSdl();
  }
  Uint16 GetGamepadVendor() {
    return ::SDL_GetGamepadVendor(value_);
  }
  Uint16 GetGamepadProduct() {
    return ::SDL_GetGamepadProduct(value_);
  }
  Uint16 GetGamepadProductVersion() {
    return ::SDL_GetGamepadProductVersion(value_);
  }
  Uint16 GetGamepadFirmwareVersion() {
    return ::SDL_GetGamepadFirmwareVersion(value_);
  }
  const char* GetGamepadSerial() {
    return ::SDL_GetGamepadSerial(value_);
  }
  Uint64 GetGamepadSteamHandle() {
    return ::SDL_GetGamepadSteamHandle(value_);
  }
  SDL_JoystickConnectionState GetGamepadConnectionState() {
    return ::SDL_GetGamepadConnectionState(value_);
  }
  SDL_PowerState GetGamepadPowerInfo(int *percent) {
    return ::SDL_GetGamepadPowerInfo(value_, percent);
  }
  Status GamepadConnected() {
    return ::SDL_GamepadConnected(value_) ? Status() : Status::FromSdl();
  }
  SDL_Joystick* GetGamepadJoystick() {
    return ::SDL_GetGamepadJoystick(value_);
  }
  SDL_GamepadBinding** GetGamepadBindings(int *count) {
    return ::SDL_GetGamepadBindings(value_, count);
  }
  Status GamepadHasAxis(SDL_GamepadAxis axis) {
    return ::SDL_GamepadHasAxis(value_, axis) ? Status() : Status::FromSdl();
  }
  Sint16 GetGamepadAxis(SDL_GamepadAxis axis) {
    return ::SDL_GetGamepadAxis(value_, axis);
  }
  Status GamepadHasButton(SDL_GamepadButton button) {
    return ::SDL_GamepadHasButton(value_, button) ? Status() : Status::FromSdl();
  }
  Status GetGamepadButton(SDL_GamepadButton button) {
    return ::SDL_GetGamepadButton(value_, button) ? Status() : Status::FromSdl();
  }
  SDL_GamepadButtonLabel GetGamepadButtonLabel(SDL_GamepadButton button) {
    return ::SDL_GetGamepadButtonLabel(value_, button);
  }
  int GetNumGamepadTouchpads() {
    return ::SDL_GetNumGamepadTouchpads(value_);
  }
  int GetNumGamepadTouchpadFingers(int touchpad) {
    return ::SDL_GetNumGamepadTouchpadFingers(value_, touchpad);
  }
  Status GetGamepadTouchpadFinger(int touchpad, int finger, bool *down, float *x, float *y, float *pressure) {
    return ::SDL_GetGamepadTouchpadFinger(value_, touchpad, finger, down, x, y, pressure) ? Status() : Status::FromSdl();
  }
  Status GamepadHasSensor(SDL_SensorType type) {
    return ::SDL_GamepadHasSensor(value_, type) ? Status() : Status::FromSdl();
  }
  Status SetGamepadSensorEnabled(SDL_SensorType type, bool enabled) {
    return ::SDL_SetGamepadSensorEnabled(value_, type, enabled) ? Status() : Status::FromSdl();
  }
  Status GamepadSensorEnabled(SDL_SensorType type) {
    return ::SDL_GamepadSensorEnabled(value_, type) ? Status() : Status::FromSdl();
  }
  float GetGamepadSensorDataRate(SDL_SensorType type) {
    return ::SDL_GetGamepadSensorDataRate(value_, type);
  }
  Status GetGamepadSensorData(SDL_SensorType type, float *data, int num_values) {
    return ::SDL_GetGamepadSensorData(value_, type, data, num_values) ? Status() : Status::FromSdl();
  }
  Status RumbleGamepad(Uint16 low_frequency_rumble, Uint16 high_frequency_rumble, Uint32 duration_ms) {
    return ::SDL_RumbleGamepad(value_, low_frequency_rumble, high_frequency_rumble, duration_ms) ? Status() : Status::FromSdl();
  }
  Status RumbleGamepadTriggers(Uint16 left_rumble, Uint16 right_rumble, Uint32 duration_ms) {
    return ::SDL_RumbleGamepadTriggers(value_, left_rumble, right_rumble, duration_ms) ? Status() : Status::FromSdl();
  }
  Status SetGamepadLED(Uint8 red, Uint8 green, Uint8 blue) {
    return ::SDL_SetGamepadLED(value_, red, green, blue) ? Status() : Status::FromSdl();
  }
  Status SendGamepadEffect(const void *data, int size) {
    return ::SDL_SendGamepadEffect(value_, data, size) ? Status() : Status::FromSdl();
  }
  const char* GetGamepadAppleSFSymbolsNameForButton(SDL_GamepadButton button) {
    return ::SDL_GetGamepadAppleSFSymbolsNameForButton(value_, button);
  }
  const char* GetGamepadAppleSFSymbolsNameForAxis(SDL_GamepadAxis axis) {
    return ::SDL_GetGamepadAppleSFSymbolsNameForAxis(value_, axis);
  }
 private:
  explicit Gamepad(SDL_Gamepad* value) : value_(value), engaged_(true) {}
  SDL_Gamepad* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Joystick (destroyed with SDL_CloseJoystick).
class Joystick {
 public:
  static Result<Joystick> OpenJoystick(SDL_JoystickID instance_id) {
    SDL_Joystick* created_ = ::SDL_OpenJoystick(instance_id);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Joystick(created_);
  }

  Joystick() = default;
  ~Joystick() { reset(); }
  Joystick(Joystick&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Joystick& operator=(Joystick&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Joystick(const Joystick&) = delete;
  Joystick& operator=(const Joystick&) = delete;

  SDL_Joystick* get() const { return value_; }
  SDL_Joystick* release() {
    SDL_Joystick* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_CloseJoystick(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status IsJoystickHaptic() {
    return ::SDL_IsJoystickHaptic(value_) ? Status() : Status::FromSdl();
  }
  Status SetJoystickVirtualAxis(int axis, Sint16 value) {
    return ::SDL_SetJoystickVirtualAxis(value_, axis, value) ? Status() : Status::FromSdl();
  }
  Status SetJoystickVirtualBall(int ball, Sint16 xrel, Sint16 yrel) {
    return ::SDL_SetJoystickVirtualBall(value_, ball, xrel, yrel) ? Status() : Status::FromSdl();
  }
  Status SetJoystickVirtualButton(int button, bool down) {
    return ::SDL_SetJoystickVirtualButton(value_, button, down) ? Status() : Status::FromSdl();
  }
  Status SetJoystickVirtualHat(int hat, Uint8 value) {
    return ::SDL_SetJoystickVirtualHat(value_, hat, value) ? Status() : Status::FromSdl();
  }
  Status SetJoystickVirtualTouchpad(int touchpad, int finger, bool down, float x, float y, float pressure) {
    return ::SDL_SetJoystickVirtualTouchpad(value_, touchpad, finger, down, x, y, pressure) ? Status() : Status::FromSdl();
  }
  Status SendJoystickVirtualSensorData(SDL_SensorType type, Uint64 sensor_timestamp, const float *data, int num_values) {
    return ::SDL_SendJoystickVirtualSensorData(value_, type, sensor_timestamp, data, num_values) ? Status() : Status::FromSdl();
  }
  SDL_PropertiesID GetJoystickProperties() {
    return ::SDL_GetJoystickProperties(value_);
  }
  const char* GetJoystickName() {
    return ::SDL_GetJoystickName(value_);
  }
  const char* GetJoystickPath() {
    return ::SDL_GetJoystickPath(value_);
  }
  int GetJoystickPlayerIndex() {
    return ::SDL_GetJoystickPlayerIndex(value_);
  }
  Status SetJoystickPlayerIndex(int player_index) {
    return ::SDL_SetJoystickPlayerIndex(value_, player_index) ? Status() : Status::FromSdl();
  }
  SDL_GUID GetJoystickGUID() {
    return ::SDL_GetJoystickGUID(value_);
  }
  Uint16 GetJoystickVendor() {
    return ::SDL_GetJoystickVendor(value_);
  }
  Uint16 GetJoystickProduct() {
    return ::SDL_GetJoystickProduct(value_);
  }
  Uint16 GetJoystickProductVersion() {
    return ::SDL_GetJoystickProductVersion(value_);
  }
  Uint16 GetJoystickFirmwareVersion() {
    return ::SDL_GetJoystickFirmwareVersion(value_);
  }
  const char* GetJoystickSerial() {
    return ::SDL_GetJoystickSerial(value_);
  }
  SDL_JoystickType GetJoystickType() {
    return ::SDL_GetJoystickType(value_);
  }
  Status JoystickConnected() {
    return ::SDL_JoystickConnected(value_) ? Status() : Status::FromSdl();
  }
  SDL_JoystickID GetJoystickID() {
    return ::SDL_GetJoystickID(value_);
  }
  int GetNumJoystickAxes() {
    return ::SDL_GetNumJoystickAxes(value_);
  }
  int GetNumJoystickBalls() {
    return ::SDL_GetNumJoystickBalls(value_);
  }
  int GetNumJoystickHats() {
    return ::SDL_GetNumJoystickHats(value_);
  }
  int GetNumJoystickButtons() {
    return ::SDL_GetNumJoystickButtons(value_);
  }
  Sint16 GetJoystickAxis(int axis) {
    return ::SDL_GetJoystickAxis(value_, axis);
  }
  Status GetJoystickAxisInitialState(int axis, Sint16 *state) {
    return ::SDL_GetJoystickAxisInitialState(value_, axis, state) ? Status() : Status::FromSdl();
  }
  Status GetJoystickBall(int ball, int *dx, int *dy) {
    return ::SDL_GetJoystickBall(value_, ball, dx, dy) ? Status() : Status::FromSdl();
  }
  Uint8 GetJoystickHat(int hat) {
    return ::SDL_GetJoystickHat(value_, hat);
  }
  Status GetJoystickButton(int button) {
    return ::SDL_GetJoystickButton(value_, button) ? Status() : Status::FromSdl();
  }
  Status RumbleJoystick(Uint16 low_frequency_rumble, Uint16 high_frequency_rumble, Uint32 duration_ms) {
    return ::SDL_RumbleJoystick(value_, low_frequency_rumble, high_frequency_rumble, duration_ms) ? Status() : Status::FromSdl();
  }
  Status RumbleJoystickTriggers(Uint16 left_rumble, Uint16 right_rumble, Uint32 duration_ms) {
    return ::SDL_RumbleJoystickTriggers(value_, left_rumble, right_rumble, duration_ms) ? Status() : Status::FromSdl();
  }
  Status SetJoystickLED(Uint8 red, Uint8 green, Uint8 blue) {
    return ::SDL_SetJoystickLED(value_, red, green, blue) ? Status() : Status::FromSdl();
  }
  Status SendJoystickEffect(const void *data, int size) {
    return ::SDL_SendJoystickEffect(value_, data, size) ? Status() : Status::FromSdl();
  }
  SDL_JoystickConnectionState GetJoystickConnectionState() {
    return ::SDL_GetJoystickConnectionState(value_);
  }
  SDL_PowerState GetJoystickPowerInfo(int *percent) {
    return ::SDL_GetJoystickPowerInfo(value_, percent);
  }
 private:
  explicit Joystick(SDL_Joystick* value) : value_(value), engaged_(true) {}
  SDL_Joystick* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Haptic (destroyed with SDL_CloseHaptic).
class Haptic {
 public:
  static Result<Haptic> OpenHaptic(SDL_HapticID instance_id) {
    SDL_Haptic* created_ = ::SDL_OpenHaptic(instance_id);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Haptic(created_);
  }
  static Result<Haptic> OpenHapticFromMouse() {
    SDL_Haptic* created_ = ::SDL_OpenHapticFromMouse();
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Haptic(created_);
  }
  static Result<Haptic> OpenHapticFromJoystick(SDL_Joystick *joystick) {
    SDL_Haptic* created_ = ::SDL_OpenHapticFromJoystick(joystick);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Haptic(created_);
  }

  Haptic() = default;
  ~Haptic() { reset(); }
  Haptic(Haptic&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Haptic& operator=(Haptic&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Haptic(const Haptic&) = delete;
  Haptic& operator=(const Haptic&) = delete;

  SDL_Haptic* get() const { return value_; }
  SDL_Haptic* release() {
    SDL_Haptic* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_CloseHaptic(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_HapticID GetHapticID() {
    return ::SDL_GetHapticID(value_);
  }
  const char* GetHapticName() {
    return ::SDL_GetHapticName(value_);
  }
  int GetMaxHapticEffects() {
    return ::SDL_GetMaxHapticEffects(value_);
  }
  int GetMaxHapticEffectsPlaying() {
    return ::SDL_GetMaxHapticEffectsPlaying(value_);
  }
  Uint32 GetHapticFeatures() {
    return ::SDL_GetHapticFeatures(value_);
  }
  int GetNumHapticAxes() {
    return ::SDL_GetNumHapticAxes(value_);
  }
  Status HapticEffectSupported(const SDL_HapticEffect *effect) {
    return ::SDL_HapticEffectSupported(value_, effect) ? Status() : Status::FromSdl();
  }
  SDL_HapticEffectID CreateHapticEffect(const SDL_HapticEffect *effect) {
    return ::SDL_CreateHapticEffect(value_, effect);
  }
  Status UpdateHapticEffect(SDL_HapticEffectID effect, const SDL_HapticEffect *data) {
    return ::SDL_UpdateHapticEffect(value_, effect, data) ? Status() : Status::FromSdl();
  }
  Status RunHapticEffect(SDL_HapticEffectID effect, Uint32 iterations) {
    return ::SDL_RunHapticEffect(value_, effect, iterations) ? Status() : Status::FromSdl();
  }
  Status StopHapticEffect(SDL_HapticEffectID effect) {
    return ::SDL_StopHapticEffect(value_, effect) ? Status() : Status::FromSdl();
  }
  void DestroyHapticEffect(SDL_HapticEffectID effect) { ::SDL_DestroyHapticEffect(value_, effect); }
  Status GetHapticEffectStatus(SDL_HapticEffectID effect) {
    return ::SDL_GetHapticEffectStatus(value_, effect) ? Status() : Status::FromSdl();
  }
  Status SetHapticGain(int gain) {
    return ::SDL_SetHapticGain(value_, gain) ? Status() : Status::FromSdl();
  }
  Status SetHapticAutocenter(int autocenter) {
    return ::SDL_SetHapticAutocenter(value_, autocenter) ? Status() : Status::FromSdl();
  }
  Status PauseHaptic() {
    return ::SDL_PauseHaptic(value_) ? Status() : Status::FromSdl();
  }
  Status ResumeHaptic() {
    return ::SDL_ResumeHaptic(value_) ? Status() : Status::FromSdl();
  }
  Status StopHapticEffects() {
    return ::SDL_StopHapticEffects(value_) ? Status() : Status::FromSdl();
  }
  Status HapticRumbleSupported() {
    return ::SDL_HapticRumbleSupported(value_) ? Status() : Status::FromSdl();
  }
  Status InitHapticRumble() {
    return ::SDL_InitHapticRumble(value_) ? Status() : Status::FromSdl();
  }
  Status PlayHapticRumble(float strength, Uint32 length) {
    return ::SDL_PlayHapticRumble(value_, strength, length) ? Status() : Status::FromSdl();
  }
  Status StopHapticRumble() {
    return ::SDL_StopHapticRumble(value_) ? Status() : Status::FromSdl();
  }
 private:
  explicit Haptic(SDL_Haptic* value) : value_(value), engaged_(true) {}
  SDL_Haptic* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Sensor (destroyed with SDL_CloseSensor).
class Sensor {
 public:
  static Result<Sensor> OpenSensor(SDL_SensorID instance_id) {
    SDL_Sensor* created_ = ::SDL_OpenSensor(instance_id);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Sensor(created_);
  }

  Sensor() = default;
  ~Sensor() { reset(); }
  Sensor(Sensor&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Sensor& operator=(Sensor&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Sensor(const Sensor&) = delete;
  Sensor& operator=(const Sensor&) = delete;

  SDL_Sensor* get() const { return value_; }
  SDL_Sensor* release() {
    SDL_Sensor* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_CloseSensor(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_PropertiesID GetSensorProperties() {
    return ::SDL_GetSensorProperties(value_);
  }
  const char* GetSensorName() {
    return ::SDL_GetSensorName(value_);
  }
  SDL_SensorType GetSensorType() {
    return ::SDL_GetSensorType(value_);
  }
  int GetSensorNonPortableType() {
    return ::SDL_GetSensorNonPortableType(value_);
  }
  SDL_SensorID GetSensorID() {
    return ::SDL_GetSensorID(value_);
  }
  Status GetSensorData(float *data, int num_values) {
    return ::SDL_GetSensorData(value_, data, num_values) ? Status() : Status::FromSdl();
  }
 private:
  explicit Sensor(SDL_Sensor* value) : value_(value), engaged_(true) {}
  SDL_Sensor* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Cursor (destroyed with SDL_DestroyCursor).
class Cursor {
 public:
  static Result<Cursor> CreateCursor(const Uint8 *data, const Uint8 *mask, int w, int h, int hot_x, int hot_y) {
    SDL_Cursor* created_ = ::SDL_CreateCursor(data, mask, w, h, hot_x, hot_y);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Cursor(created_);
  }
  static Result<Cursor> CreateColorCursor(SDL_Surface *surface, int hot_x, int hot_y) {
    SDL_Cursor* created_ = ::SDL_CreateColorCursor(surface, hot_x, hot_y);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Cursor(created_);
  }
  static Result<Cursor> CreateSystemCursor(SDL_SystemCursor id) {
    SDL_Cursor* created_ = ::SDL_CreateSystemCursor(id);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Cursor(created_);
  }

  Cursor() = default;
  ~Cursor() { reset(); }
  Cursor(Cursor&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Cursor& operator=(Cursor&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Cursor(const Cursor&) = delete;
  Cursor& operator=(const Cursor&) = delete;

  SDL_Cursor* get() const { return value_; }
  SDL_Cursor* release() {
    SDL_Cursor* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyCursor(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status SetCursor() {
    return ::SDL_SetCursor(value_) ? Status() : Status::FromSdl();
  }
 private:
  explicit Cursor(SDL_Cursor* value) : value_(value), engaged_(true) {}
  SDL_Cursor* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Palette (destroyed with SDL_DestroyPalette).
class Palette {
 public:
  static Result<Palette> CreatePalette(int ncolors) {
    SDL_Palette* created_ = ::SDL_CreatePalette(ncolors);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Palette(created_);
  }

  Palette() = default;
  ~Palette() { reset(); }
  Palette(Palette&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Palette& operator=(Palette&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Palette(const Palette&) = delete;
  Palette& operator=(const Palette&) = delete;

  SDL_Palette* get() const { return value_; }
  SDL_Palette* release() {
    SDL_Palette* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyPalette(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status SetPaletteColors(const SDL_Color *colors, int firstcolor, int ncolors) {
    return ::SDL_SetPaletteColors(value_, colors, firstcolor, ncolors) ? Status() : Status::FromSdl();
  }
 private:
  explicit Palette(SDL_Palette* value) : value_(value), engaged_(true) {}
  SDL_Palette* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_PropertiesID (destroyed with SDL_DestroyProperties).
class Properties {
 public:
  static Result<Properties> CreateProperties() {
    SDL_PropertiesID created_ = ::SDL_CreateProperties();
    if (created_ == 0) {
      return Status::FromSdl();
    }
    return Properties(created_);
  }

  Properties() = default;
  ~Properties() { reset(); }
  Properties(Properties&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = {};
    other.engaged_ = false;
  }
  Properties& operator=(Properties&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = {};
      other.engaged_ = false;
    }
    return *this;
  }
  Properties(const Properties&) = delete;
  Properties& operator=(const Properties&) = delete;

  SDL_PropertiesID get() const { return value_; }
  SDL_PropertiesID release() {
    SDL_PropertiesID out = value_;
    value_ = {};
    engaged_ = false;
    return out;
  }
  void reset() {
    if (engaged_) ::SDL_DestroyProperties(value_);
    value_ = {};
    engaged_ = false;
  }

  Status GPUSupportsProperties() {
    return ::SDL_GPUSupportsProperties(value_) ? Status() : Status::FromSdl();
  }
  Status CopyProperties(SDL_PropertiesID dst) {
    return ::SDL_CopyProperties(value_, dst) ? Status() : Status::FromSdl();
  }
  Status LockProperties() {
    return ::SDL_LockProperties(value_) ? Status() : Status::FromSdl();
  }
  void UnlockProperties() { ::SDL_UnlockProperties(value_); }
  Status SetPointerPropertyWithCleanup(const char *name, void *value, SDL_CleanupPropertyCallback cleanup, void *userdata) {
    return ::SDL_SetPointerPropertyWithCleanup(value_, name, value, cleanup, userdata) ? Status() : Status::FromSdl();
  }
  Status SetPointerProperty(const char *name, void *value) {
    return ::SDL_SetPointerProperty(value_, name, value) ? Status() : Status::FromSdl();
  }
  Status SetStringProperty(const char *name, const char *value) {
    return ::SDL_SetStringProperty(value_, name, value) ? Status() : Status::FromSdl();
  }
  Status SetNumberProperty(const char *name, Sint64 value) {
    return ::SDL_SetNumberProperty(value_, name, value) ? Status() : Status::FromSdl();
  }
  Status SetFloatProperty(const char *name, float value) {
    return ::SDL_SetFloatProperty(value_, name, value) ? Status() : Status::FromSdl();
  }
  Status SetBooleanProperty(const char *name, bool value) {
    return ::SDL_SetBooleanProperty(value_, name, value) ? Status() : Status::FromSdl();
  }
  Status HasProperty(const char *name) {
    return ::SDL_HasProperty(value_, name) ? Status() : Status::FromSdl();
  }
  SDL_PropertyType GetPropertyType(const char *name) {
    return ::SDL_GetPropertyType(value_, name);
  }
  void* GetPointerProperty(const char *name, void *default_value) {
    return ::SDL_GetPointerProperty(value_, name, default_value);
  }
  const char* GetStringProperty(const char *name, const char *default_value) {
    return ::SDL_GetStringProperty(value_, name, default_value);
  }
  Sint64 GetNumberProperty(const char *name, Sint64 default_value) {
    return ::SDL_GetNumberProperty(value_, name, default_value);
  }
  float GetFloatProperty(const char *name, float default_value) {
    return ::SDL_GetFloatProperty(value_, name, default_value);
  }
  Status GetBooleanProperty(const char *name, bool default_value) {
    return ::SDL_GetBooleanProperty(value_, name, default_value) ? Status() : Status::FromSdl();
  }
  Status ClearProperty(const char *name) {
    return ::SDL_ClearProperty(value_, name) ? Status() : Status::FromSdl();
  }
  Status EnumerateProperties(SDL_EnumeratePropertiesCallback callback, void *userdata) {
    return ::SDL_EnumerateProperties(value_, callback, userdata) ? Status() : Status::FromSdl();
  }
  SDL_Thread* CreateThreadWithPropertiesRuntime(SDL_FunctionPointer pfnBeginThread, SDL_FunctionPointer pfnEndThread) {
    return ::SDL_CreateThreadWithPropertiesRuntime(value_, pfnBeginThread, pfnEndThread);
  }
 private:
  explicit Properties(SDL_PropertiesID value) : value_(value), engaged_(true) {}
  SDL_PropertiesID value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_IOStream (destroyed with SDL_CloseIO).
class IoStream {
 public:
  static Result<IoStream> IOFromFile(const char *file, const char *mode) {
    SDL_IOStream* created_ = ::SDL_IOFromFile(file, mode);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return IoStream(created_);
  }
  static Result<IoStream> IOFromMem(void *mem, size_t size) {
    SDL_IOStream* created_ = ::SDL_IOFromMem(mem, size);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return IoStream(created_);
  }
  static Result<IoStream> IOFromConstMem(const void *mem, size_t size) {
    SDL_IOStream* created_ = ::SDL_IOFromConstMem(mem, size);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return IoStream(created_);
  }
  static Result<IoStream> IOFromDynamicMem() {
    SDL_IOStream* created_ = ::SDL_IOFromDynamicMem();
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return IoStream(created_);
  }

  IoStream() = default;
  ~IoStream() { reset(); }
  IoStream(IoStream&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  IoStream& operator=(IoStream&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  IoStream(const IoStream&) = delete;
  IoStream& operator=(const IoStream&) = delete;

  SDL_IOStream* get() const { return value_; }
  SDL_IOStream* release() {
    SDL_IOStream* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_CloseIO(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status LoadWAV_IO(bool closeio, SDL_AudioSpec *spec, Uint8 **audio_buf, Uint32 *audio_len) {
    return ::SDL_LoadWAV_IO(value_, closeio, spec, audio_buf, audio_len) ? Status() : Status::FromSdl();
  }
  int AddGamepadMappingsFromIO(bool closeio) {
    return ::SDL_AddGamepadMappingsFromIO(value_, closeio);
  }
  SDL_PropertiesID GetIOProperties() {
    return ::SDL_GetIOProperties(value_);
  }
  SDL_IOStatus GetIOStatus() {
    return ::SDL_GetIOStatus(value_);
  }
  Sint64 GetIOSize() {
    return ::SDL_GetIOSize(value_);
  }
  Sint64 SeekIO(Sint64 offset, SDL_IOWhence whence) {
    return ::SDL_SeekIO(value_, offset, whence);
  }
  Sint64 TellIO() {
    return ::SDL_TellIO(value_);
  }
  size_t ReadIO(void *ptr, size_t size) {
    return ::SDL_ReadIO(value_, ptr, size);
  }
  size_t WriteIO(const void *ptr, size_t size) {
    return ::SDL_WriteIO(value_, ptr, size);
  }
  Status FlushIO() {
    return ::SDL_FlushIO(value_) ? Status() : Status::FromSdl();
  }
  void* LoadFile_IO(size_t *datasize, bool closeio) {
    return ::SDL_LoadFile_IO(value_, datasize, closeio);
  }
  Status SaveFile_IO(const void *data, size_t datasize, bool closeio) {
    return ::SDL_SaveFile_IO(value_, data, datasize, closeio) ? Status() : Status::FromSdl();
  }
  Status ReadU8(Uint8 *value) {
    return ::SDL_ReadU8(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadS8(Sint8 *value) {
    return ::SDL_ReadS8(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadU16LE(Uint16 *value) {
    return ::SDL_ReadU16LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadS16LE(Sint16 *value) {
    return ::SDL_ReadS16LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadU16BE(Uint16 *value) {
    return ::SDL_ReadU16BE(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadS16BE(Sint16 *value) {
    return ::SDL_ReadS16BE(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadU32LE(Uint32 *value) {
    return ::SDL_ReadU32LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadS32LE(Sint32 *value) {
    return ::SDL_ReadS32LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadU32BE(Uint32 *value) {
    return ::SDL_ReadU32BE(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadS32BE(Sint32 *value) {
    return ::SDL_ReadS32BE(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadU64LE(Uint64 *value) {
    return ::SDL_ReadU64LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadS64LE(Sint64 *value) {
    return ::SDL_ReadS64LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadU64BE(Uint64 *value) {
    return ::SDL_ReadU64BE(value_, value) ? Status() : Status::FromSdl();
  }
  Status ReadS64BE(Sint64 *value) {
    return ::SDL_ReadS64BE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteU8(Uint8 value) {
    return ::SDL_WriteU8(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteS8(Sint8 value) {
    return ::SDL_WriteS8(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteU16LE(Uint16 value) {
    return ::SDL_WriteU16LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteS16LE(Sint16 value) {
    return ::SDL_WriteS16LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteU16BE(Uint16 value) {
    return ::SDL_WriteU16BE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteS16BE(Sint16 value) {
    return ::SDL_WriteS16BE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteU32LE(Uint32 value) {
    return ::SDL_WriteU32LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteS32LE(Sint32 value) {
    return ::SDL_WriteS32LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteU32BE(Uint32 value) {
    return ::SDL_WriteU32BE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteS32BE(Sint32 value) {
    return ::SDL_WriteS32BE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteU64LE(Uint64 value) {
    return ::SDL_WriteU64LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteS64LE(Sint64 value) {
    return ::SDL_WriteS64LE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteU64BE(Uint64 value) {
    return ::SDL_WriteU64BE(value_, value) ? Status() : Status::FromSdl();
  }
  Status WriteS64BE(Sint64 value) {
    return ::SDL_WriteS64BE(value_, value) ? Status() : Status::FromSdl();
  }
  SDL_Surface* LoadSurface_IO(bool closeio) {
    return ::SDL_LoadSurface_IO(value_, closeio);
  }
  SDL_Surface* LoadPNG_IO(bool closeio) {
    return ::SDL_LoadPNG_IO(value_, closeio);
  }
 private:
  explicit IoStream(SDL_IOStream* value) : value_(value), engaged_(true) {}
  SDL_IOStream* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_AsyncIOQueue (destroyed with SDL_DestroyAsyncIOQueue).
class AsyncIoQueue {
 public:
  static Result<AsyncIoQueue> CreateAsyncIOQueue() {
    SDL_AsyncIOQueue* created_ = ::SDL_CreateAsyncIOQueue();
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return AsyncIoQueue(created_);
  }

  AsyncIoQueue() = default;
  ~AsyncIoQueue() { reset(); }
  AsyncIoQueue(AsyncIoQueue&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  AsyncIoQueue& operator=(AsyncIoQueue&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  AsyncIoQueue(const AsyncIoQueue&) = delete;
  AsyncIoQueue& operator=(const AsyncIoQueue&) = delete;

  SDL_AsyncIOQueue* get() const { return value_; }
  SDL_AsyncIOQueue* release() {
    SDL_AsyncIOQueue* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyAsyncIOQueue(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status GetAsyncIOResult(SDL_AsyncIOOutcome *outcome) {
    return ::SDL_GetAsyncIOResult(value_, outcome) ? Status() : Status::FromSdl();
  }
  Status WaitAsyncIOResult(SDL_AsyncIOOutcome *outcome, Sint32 timeoutMS) {
    return ::SDL_WaitAsyncIOResult(value_, outcome, timeoutMS) ? Status() : Status::FromSdl();
  }
  void SignalAsyncIOQueue() { ::SDL_SignalAsyncIOQueue(value_); }
 private:
  explicit AsyncIoQueue(SDL_AsyncIOQueue* value) : value_(value), engaged_(true) {}
  SDL_AsyncIOQueue* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Storage (destroyed with SDL_CloseStorage).
class Storage {
 public:
  static Result<Storage> OpenTitleStorage(const char *override, SDL_PropertiesID props) {
    SDL_Storage* created_ = ::SDL_OpenTitleStorage(override, props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Storage(created_);
  }
  static Result<Storage> OpenUserStorage(const char *org, const char *app, SDL_PropertiesID props) {
    SDL_Storage* created_ = ::SDL_OpenUserStorage(org, app, props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Storage(created_);
  }
  static Result<Storage> OpenFileStorage(const char *path) {
    SDL_Storage* created_ = ::SDL_OpenFileStorage(path);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Storage(created_);
  }
  static Result<Storage> OpenStorage(const SDL_StorageInterface *iface, void *userdata) {
    SDL_Storage* created_ = ::SDL_OpenStorage(iface, userdata);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Storage(created_);
  }

  Storage() = default;
  ~Storage() { reset(); }
  Storage(Storage&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Storage& operator=(Storage&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Storage(const Storage&) = delete;
  Storage& operator=(const Storage&) = delete;

  SDL_Storage* get() const { return value_; }
  SDL_Storage* release() {
    SDL_Storage* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_CloseStorage(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status StorageReady() {
    return ::SDL_StorageReady(value_) ? Status() : Status::FromSdl();
  }
  Status GetStorageFileSize(const char *path, Uint64 *length) {
    return ::SDL_GetStorageFileSize(value_, path, length) ? Status() : Status::FromSdl();
  }
  Status ReadStorageFile(const char *path, void *destination, Uint64 length) {
    return ::SDL_ReadStorageFile(value_, path, destination, length) ? Status() : Status::FromSdl();
  }
  Status WriteStorageFile(const char *path, const void *source, Uint64 length) {
    return ::SDL_WriteStorageFile(value_, path, source, length) ? Status() : Status::FromSdl();
  }
  Status CreateStorageDirectory(const char *path) {
    return ::SDL_CreateStorageDirectory(value_, path) ? Status() : Status::FromSdl();
  }
  Status EnumerateStorageDirectory(const char *path, SDL_EnumerateDirectoryCallback callback, void *userdata) {
    return ::SDL_EnumerateStorageDirectory(value_, path, callback, userdata) ? Status() : Status::FromSdl();
  }
  Status RemoveStoragePath(const char *path) {
    return ::SDL_RemoveStoragePath(value_, path) ? Status() : Status::FromSdl();
  }
  Status RenameStoragePath(const char *oldpath, const char *newpath) {
    return ::SDL_RenameStoragePath(value_, oldpath, newpath) ? Status() : Status::FromSdl();
  }
  Status CopyStorageFile(const char *oldpath, const char *newpath) {
    return ::SDL_CopyStorageFile(value_, oldpath, newpath) ? Status() : Status::FromSdl();
  }
  Status GetStoragePathInfo(const char *path, SDL_PathInfo *info) {
    return ::SDL_GetStoragePathInfo(value_, path, info) ? Status() : Status::FromSdl();
  }
  Uint64 GetStorageSpaceRemaining() {
    return ::SDL_GetStorageSpaceRemaining(value_);
  }
  char** GlobStorageDirectory(const char *path, const char *pattern, SDL_GlobFlags flags, int *count) {
    return ::SDL_GlobStorageDirectory(value_, path, pattern, flags, count);
  }
 private:
  explicit Storage(SDL_Storage* value) : value_(value), engaged_(true) {}
  SDL_Storage* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Mutex (destroyed with SDL_DestroyMutex).
class Mutex {
 public:
  static Result<Mutex> CreateMutex() {
    SDL_Mutex* created_ = ::SDL_CreateMutex();
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Mutex(created_);
  }

  Mutex() = default;
  ~Mutex() { reset(); }
  Mutex(Mutex&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Mutex& operator=(Mutex&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Mutex(const Mutex&) = delete;
  Mutex& operator=(const Mutex&) = delete;

  SDL_Mutex* get() const { return value_; }
  SDL_Mutex* release() {
    SDL_Mutex* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyMutex(value_);
    value_ = nullptr;
    engaged_ = false;
  }

 private:
  explicit Mutex(SDL_Mutex* value) : value_(value), engaged_(true) {}
  SDL_Mutex* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_RWLock (destroyed with SDL_DestroyRWLock).
class RwLock {
 public:
  static Result<RwLock> CreateRWLock() {
    SDL_RWLock* created_ = ::SDL_CreateRWLock();
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return RwLock(created_);
  }

  RwLock() = default;
  ~RwLock() { reset(); }
  RwLock(RwLock&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  RwLock& operator=(RwLock&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  RwLock(const RwLock&) = delete;
  RwLock& operator=(const RwLock&) = delete;

  SDL_RWLock* get() const { return value_; }
  SDL_RWLock* release() {
    SDL_RWLock* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyRWLock(value_);
    value_ = nullptr;
    engaged_ = false;
  }

 private:
  explicit RwLock(SDL_RWLock* value) : value_(value), engaged_(true) {}
  SDL_RWLock* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Semaphore (destroyed with SDL_DestroySemaphore).
class Semaphore {
 public:
  static Result<Semaphore> CreateSemaphore(Uint32 initial_value) {
    SDL_Semaphore* created_ = ::SDL_CreateSemaphore(initial_value);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Semaphore(created_);
  }

  Semaphore() = default;
  ~Semaphore() { reset(); }
  Semaphore(Semaphore&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Semaphore& operator=(Semaphore&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Semaphore(const Semaphore&) = delete;
  Semaphore& operator=(const Semaphore&) = delete;

  SDL_Semaphore* get() const { return value_; }
  SDL_Semaphore* release() {
    SDL_Semaphore* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroySemaphore(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  void WaitSemaphore() { ::SDL_WaitSemaphore(value_); }
  Status TryWaitSemaphore() {
    return ::SDL_TryWaitSemaphore(value_) ? Status() : Status::FromSdl();
  }
  Status WaitSemaphoreTimeout(Sint32 timeoutMS) {
    return ::SDL_WaitSemaphoreTimeout(value_, timeoutMS) ? Status() : Status::FromSdl();
  }
  void SignalSemaphore() { ::SDL_SignalSemaphore(value_); }
  Uint32 GetSemaphoreValue() {
    return ::SDL_GetSemaphoreValue(value_);
  }
 private:
  explicit Semaphore(SDL_Semaphore* value) : value_(value), engaged_(true) {}
  SDL_Semaphore* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Condition (destroyed with SDL_DestroyCondition).
class Condition {
 public:
  static Result<Condition> CreateCondition() {
    SDL_Condition* created_ = ::SDL_CreateCondition();
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Condition(created_);
  }

  Condition() = default;
  ~Condition() { reset(); }
  Condition(Condition&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Condition& operator=(Condition&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Condition(const Condition&) = delete;
  Condition& operator=(const Condition&) = delete;

  SDL_Condition* get() const { return value_; }
  SDL_Condition* release() {
    SDL_Condition* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyCondition(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  void SignalCondition() { ::SDL_SignalCondition(value_); }
  void BroadcastCondition() { ::SDL_BroadcastCondition(value_); }
  void WaitCondition(SDL_Mutex *mutex) { ::SDL_WaitCondition(value_, mutex); }
  Status WaitConditionTimeout(SDL_Mutex *mutex, Sint32 timeoutMS) {
    return ::SDL_WaitConditionTimeout(value_, mutex, timeoutMS) ? Status() : Status::FromSdl();
  }
 private:
  explicit Condition(SDL_Condition* value) : value_(value), engaged_(true) {}
  SDL_Condition* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Process (destroyed with SDL_DestroyProcess).
class Process {
 public:
  static Result<Process> CreateProcess(const char * const *args, bool pipe_stdio) {
    SDL_Process* created_ = ::SDL_CreateProcess(args, pipe_stdio);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Process(created_);
  }
  static Result<Process> CreateProcessWithProperties(SDL_PropertiesID props) {
    SDL_Process* created_ = ::SDL_CreateProcessWithProperties(props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Process(created_);
  }

  Process() = default;
  ~Process() { reset(); }
  Process(Process&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Process& operator=(Process&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Process(const Process&) = delete;
  Process& operator=(const Process&) = delete;

  SDL_Process* get() const { return value_; }
  SDL_Process* release() {
    SDL_Process* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyProcess(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_PropertiesID GetProcessProperties() {
    return ::SDL_GetProcessProperties(value_);
  }
  void* ReadProcess(size_t *datasize, int *exitcode) {
    return ::SDL_ReadProcess(value_, datasize, exitcode);
  }
  SDL_IOStream* GetProcessInput() {
    return ::SDL_GetProcessInput(value_);
  }
  SDL_IOStream* GetProcessOutput() {
    return ::SDL_GetProcessOutput(value_);
  }
  Status KillProcess(bool force) {
    return ::SDL_KillProcess(value_, force) ? Status() : Status::FromSdl();
  }
  Status WaitProcess(bool block, int *exitcode) {
    return ::SDL_WaitProcess(value_, block, exitcode) ? Status() : Status::FromSdl();
  }
 private:
  explicit Process(SDL_Process* value) : value_(value), engaged_(true) {}
  SDL_Process* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Tray (destroyed with SDL_DestroyTray).
class Tray {
 public:
  static Result<Tray> CreateTray(SDL_Surface *icon, const char *tooltip) {
    SDL_Tray* created_ = ::SDL_CreateTray(icon, tooltip);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Tray(created_);
  }

  Tray() = default;
  ~Tray() { reset(); }
  Tray(Tray&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Tray& operator=(Tray&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Tray(const Tray&) = delete;
  Tray& operator=(const Tray&) = delete;

  SDL_Tray* get() const { return value_; }
  SDL_Tray* release() {
    SDL_Tray* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyTray(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  void SetTrayIcon(SDL_Surface *icon) { ::SDL_SetTrayIcon(value_, icon); }
  void SetTrayTooltip(const char *tooltip) { ::SDL_SetTrayTooltip(value_, tooltip); }
  SDL_TrayMenu* CreateTrayMenu() {
    return ::SDL_CreateTrayMenu(value_);
  }
  SDL_TrayMenu* GetTrayMenu() {
    return ::SDL_GetTrayMenu(value_);
  }
 private:
  explicit Tray(SDL_Tray* value) : value_(value), engaged_(true) {}
  SDL_Tray* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_SharedObject (destroyed with SDL_UnloadObject).
class SharedObject {
 public:
  static Result<SharedObject> LoadObject(const char *sofile) {
    SDL_SharedObject* created_ = ::SDL_LoadObject(sofile);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return SharedObject(created_);
  }

  SharedObject() = default;
  ~SharedObject() { reset(); }
  SharedObject(SharedObject&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  SharedObject& operator=(SharedObject&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  SharedObject(const SharedObject&) = delete;
  SharedObject& operator=(const SharedObject&) = delete;

  SDL_SharedObject* get() const { return value_; }
  SDL_SharedObject* release() {
    SDL_SharedObject* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_UnloadObject(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_FunctionPointer LoadFunction(const char *name) {
    return ::SDL_LoadFunction(value_, name);
  }
 private:
  explicit SharedObject(SDL_SharedObject* value) : value_(value), engaged_(true) {}
  SDL_SharedObject* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Environment (destroyed with SDL_DestroyEnvironment).
class Environment {
 public:
  static Result<Environment> CreateEnvironment(bool populated) {
    SDL_Environment* created_ = ::SDL_CreateEnvironment(populated);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Environment(created_);
  }

  Environment() = default;
  ~Environment() { reset(); }
  Environment(Environment&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Environment& operator=(Environment&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Environment(const Environment&) = delete;
  Environment& operator=(const Environment&) = delete;

  SDL_Environment* get() const { return value_; }
  SDL_Environment* release() {
    SDL_Environment* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyEnvironment(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  const char* GetEnvironmentVariable(const char *name) {
    return ::SDL_GetEnvironmentVariable(value_, name);
  }
  char** GetEnvironmentVariables() {
    return ::SDL_GetEnvironmentVariables(value_);
  }
  Status SetEnvironmentVariable(const char *name, const char *value, bool overwrite) {
    return ::SDL_SetEnvironmentVariable(value_, name, value, overwrite) ? Status() : Status::FromSdl();
  }
  Status UnsetEnvironmentVariable(const char *name) {
    return ::SDL_UnsetEnvironmentVariable(value_, name) ? Status() : Status::FromSdl();
  }
 private:
  explicit Environment(SDL_Environment* value) : value_(value), engaged_(true) {}
  SDL_Environment* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_GPUDevice (destroyed with SDL_DestroyGPUDevice).
class GpuDevice {
 public:
  static Result<GpuDevice> CreateGPUDevice(SDL_GPUShaderFormat format_flags, bool debug_mode, const char *name) {
    SDL_GPUDevice* created_ = ::SDL_CreateGPUDevice(format_flags, debug_mode, name);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return GpuDevice(created_);
  }
  static Result<GpuDevice> CreateGPUDeviceWithProperties(SDL_PropertiesID props) {
    SDL_GPUDevice* created_ = ::SDL_CreateGPUDeviceWithProperties(props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return GpuDevice(created_);
  }

  GpuDevice() = default;
  ~GpuDevice() { reset(); }
  GpuDevice(GpuDevice&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  GpuDevice& operator=(GpuDevice&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  GpuDevice(const GpuDevice&) = delete;
  GpuDevice& operator=(const GpuDevice&) = delete;

  SDL_GPUDevice* get() const { return value_; }
  SDL_GPUDevice* release() {
    SDL_GPUDevice* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroyGPUDevice(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  const char* GetGPUDeviceDriver() {
    return ::SDL_GetGPUDeviceDriver(value_);
  }
  SDL_GPUShaderFormat GetGPUShaderFormats() {
    return ::SDL_GetGPUShaderFormats(value_);
  }
  SDL_PropertiesID GetGPUDeviceProperties() {
    return ::SDL_GetGPUDeviceProperties(value_);
  }
  SDL_GPUComputePipeline* CreateGPUComputePipeline(const SDL_GPUComputePipelineCreateInfo *createinfo) {
    return ::SDL_CreateGPUComputePipeline(value_, createinfo);
  }
  SDL_GPUGraphicsPipeline* CreateGPUGraphicsPipeline(const SDL_GPUGraphicsPipelineCreateInfo *createinfo) {
    return ::SDL_CreateGPUGraphicsPipeline(value_, createinfo);
  }
  SDL_GPUSampler* CreateGPUSampler(const SDL_GPUSamplerCreateInfo *createinfo) {
    return ::SDL_CreateGPUSampler(value_, createinfo);
  }
  SDL_GPUShader* CreateGPUShader(const SDL_GPUShaderCreateInfo *createinfo) {
    return ::SDL_CreateGPUShader(value_, createinfo);
  }
  SDL_GPUTexture* CreateGPUTexture(const SDL_GPUTextureCreateInfo *createinfo) {
    return ::SDL_CreateGPUTexture(value_, createinfo);
  }
  SDL_GPUBuffer* CreateGPUBuffer(const SDL_GPUBufferCreateInfo *createinfo) {
    return ::SDL_CreateGPUBuffer(value_, createinfo);
  }
  SDL_GPUTransferBuffer* CreateGPUTransferBuffer(const SDL_GPUTransferBufferCreateInfo *createinfo) {
    return ::SDL_CreateGPUTransferBuffer(value_, createinfo);
  }
  void SetGPUBufferName(SDL_GPUBuffer *buffer, const char *text) { ::SDL_SetGPUBufferName(value_, buffer, text); }
  void SetGPUTextureName(SDL_GPUTexture *texture, const char *text) { ::SDL_SetGPUTextureName(value_, texture, text); }
  void ReleaseGPUTexture(SDL_GPUTexture *texture) { ::SDL_ReleaseGPUTexture(value_, texture); }
  void ReleaseGPUSampler(SDL_GPUSampler *sampler) { ::SDL_ReleaseGPUSampler(value_, sampler); }
  void ReleaseGPUBuffer(SDL_GPUBuffer *buffer) { ::SDL_ReleaseGPUBuffer(value_, buffer); }
  void ReleaseGPUTransferBuffer(SDL_GPUTransferBuffer *transfer_buffer) { ::SDL_ReleaseGPUTransferBuffer(value_, transfer_buffer); }
  void ReleaseGPUComputePipeline(SDL_GPUComputePipeline *compute_pipeline) { ::SDL_ReleaseGPUComputePipeline(value_, compute_pipeline); }
  void ReleaseGPUShader(SDL_GPUShader *shader) { ::SDL_ReleaseGPUShader(value_, shader); }
  void ReleaseGPUGraphicsPipeline(SDL_GPUGraphicsPipeline *graphics_pipeline) { ::SDL_ReleaseGPUGraphicsPipeline(value_, graphics_pipeline); }
  SDL_GPUCommandBuffer* AcquireGPUCommandBuffer() {
    return ::SDL_AcquireGPUCommandBuffer(value_);
  }
  void* MapGPUTransferBuffer(SDL_GPUTransferBuffer *transfer_buffer, bool cycle) {
    return ::SDL_MapGPUTransferBuffer(value_, transfer_buffer, cycle);
  }
  void UnmapGPUTransferBuffer(SDL_GPUTransferBuffer *transfer_buffer) { ::SDL_UnmapGPUTransferBuffer(value_, transfer_buffer); }
  Status WindowSupportsGPUSwapchainComposition(SDL_Window *window, SDL_GPUSwapchainComposition swapchain_composition) {
    return ::SDL_WindowSupportsGPUSwapchainComposition(value_, window, swapchain_composition) ? Status() : Status::FromSdl();
  }
  Status WindowSupportsGPUPresentMode(SDL_Window *window, SDL_GPUPresentMode present_mode) {
    return ::SDL_WindowSupportsGPUPresentMode(value_, window, present_mode) ? Status() : Status::FromSdl();
  }
  Status ClaimWindowForGPUDevice(SDL_Window *window) {
    return ::SDL_ClaimWindowForGPUDevice(value_, window) ? Status() : Status::FromSdl();
  }
  void ReleaseWindowFromGPUDevice(SDL_Window *window) { ::SDL_ReleaseWindowFromGPUDevice(value_, window); }
  Status SetGPUSwapchainParameters(SDL_Window *window, SDL_GPUSwapchainComposition swapchain_composition, SDL_GPUPresentMode present_mode) {
    return ::SDL_SetGPUSwapchainParameters(value_, window, swapchain_composition, present_mode) ? Status() : Status::FromSdl();
  }
  Status SetGPUAllowedFramesInFlight(Uint32 allowed_frames_in_flight) {
    return ::SDL_SetGPUAllowedFramesInFlight(value_, allowed_frames_in_flight) ? Status() : Status::FromSdl();
  }
  SDL_GPUTextureFormat GetGPUSwapchainTextureFormat(SDL_Window *window) {
    return ::SDL_GetGPUSwapchainTextureFormat(value_, window);
  }
  Status WaitForGPUSwapchain(SDL_Window *window) {
    return ::SDL_WaitForGPUSwapchain(value_, window) ? Status() : Status::FromSdl();
  }
  Status WaitForGPUIdle() {
    return ::SDL_WaitForGPUIdle(value_) ? Status() : Status::FromSdl();
  }
  Status WaitForGPUFences(bool wait_all, SDL_GPUFence *const *fences, Uint32 num_fences) {
    return ::SDL_WaitForGPUFences(value_, wait_all, fences, num_fences) ? Status() : Status::FromSdl();
  }
  Status QueryGPUFence(SDL_GPUFence *fence) {
    return ::SDL_QueryGPUFence(value_, fence) ? Status() : Status::FromSdl();
  }
  void ReleaseGPUFence(SDL_GPUFence *fence) { ::SDL_ReleaseGPUFence(value_, fence); }
  Status GPUTextureSupportsFormat(SDL_GPUTextureFormat format, SDL_GPUTextureType type, SDL_GPUTextureUsageFlags usage) {
    return ::SDL_GPUTextureSupportsFormat(value_, format, type, usage) ? Status() : Status::FromSdl();
  }
  Status GPUTextureSupportsSampleCount(SDL_GPUTextureFormat format, SDL_GPUSampleCount sample_count) {
    return ::SDL_GPUTextureSupportsSampleCount(value_, format, sample_count) ? Status() : Status::FromSdl();
  }
  SDL_Renderer* CreateGPURenderer(SDL_Window *window) {
    return ::SDL_CreateGPURenderer(value_, window);
  }
 private:
  explicit GpuDevice(SDL_GPUDevice* value) : value_(value), engaged_(true) {}
  SDL_GPUDevice* value_{};
  bool engaged_ = false;
};

// bool-returning C functions surfaced as Status.
inline Status AcquireGPUSwapchainTexture(SDL_GPUCommandBuffer *command_buffer, SDL_Window *window, SDL_GPUTexture **swapchain_texture, Uint32 *swapchain_texture_width, Uint32 *swapchain_texture_height) {
  return ::SDL_AcquireGPUSwapchainTexture(command_buffer, window, swapchain_texture, swapchain_texture_width, swapchain_texture_height) ? Status() : Status::FromSdl();
}
inline Status AddEventWatch(SDL_EventFilter filter, void *userdata) {
  return ::SDL_AddEventWatch(filter, userdata) ? Status() : Status::FromSdl();
}
inline Status AddHintCallback(const char *name, SDL_HintCallback callback, void *userdata) {
  return ::SDL_AddHintCallback(name, callback, userdata) ? Status() : Status::FromSdl();
}
inline Status AudioDevicePaused(SDL_AudioDeviceID devid) {
  return ::SDL_AudioDevicePaused(devid) ? Status() : Status::FromSdl();
}
inline Status BindAudioStream(SDL_AudioDeviceID devid, SDL_AudioStream *stream) {
  return ::SDL_BindAudioStream(devid, stream) ? Status() : Status::FromSdl();
}
inline Status BindAudioStreams(SDL_AudioDeviceID devid, SDL_AudioStream * const *streams, int num_streams) {
  return ::SDL_BindAudioStreams(devid, streams, num_streams) ? Status() : Status::FromSdl();
}
inline Status CancelGPUCommandBuffer(SDL_GPUCommandBuffer *command_buffer) {
  return ::SDL_CancelGPUCommandBuffer(command_buffer) ? Status() : Status::FromSdl();
}
inline Status CaptureMouse(bool enabled) {
  return ::SDL_CaptureMouse(enabled) ? Status() : Status::FromSdl();
}
inline Status ClearClipboardData() {
  return ::SDL_ClearClipboardData() ? Status() : Status::FromSdl();
}
inline Status ClearError() {
  return ::SDL_ClearError() ? Status() : Status::FromSdl();
}
inline Status CloseAsyncIO(SDL_AsyncIO *asyncio, bool flush, SDL_AsyncIOQueue *queue, void *userdata) {
  return ::SDL_CloseAsyncIO(asyncio, flush, queue, userdata) ? Status() : Status::FromSdl();
}
inline Status CompareAndSwapAtomicInt(SDL_AtomicInt *a, int oldval, int newval) {
  return ::SDL_CompareAndSwapAtomicInt(a, oldval, newval) ? Status() : Status::FromSdl();
}
inline Status CompareAndSwapAtomicPointer(void **a, void *oldval, void *newval) {
  return ::SDL_CompareAndSwapAtomicPointer(a, oldval, newval) ? Status() : Status::FromSdl();
}
inline Status CompareAndSwapAtomicU32(SDL_AtomicU32 *a, Uint32 oldval, Uint32 newval) {
  return ::SDL_CompareAndSwapAtomicU32(a, oldval, newval) ? Status() : Status::FromSdl();
}
inline Status ConvertAudioSamples(const SDL_AudioSpec *src_spec, const Uint8 *src_data, int src_len, const SDL_AudioSpec *dst_spec, Uint8 **dst_data, int *dst_len) {
  return ::SDL_ConvertAudioSamples(src_spec, src_data, src_len, dst_spec, dst_data, dst_len) ? Status() : Status::FromSdl();
}
inline Status ConvertPixels(int width, int height, SDL_PixelFormat src_format, const void *src, int src_pitch, SDL_PixelFormat dst_format, void *dst, int dst_pitch) {
  return ::SDL_ConvertPixels(width, height, src_format, src, src_pitch, dst_format, dst, dst_pitch) ? Status() : Status::FromSdl();
}
inline Status ConvertPixelsAndColorspace(int width, int height, SDL_PixelFormat src_format, SDL_Colorspace src_colorspace, SDL_PropertiesID src_properties, const void *src, int src_pitch, SDL_PixelFormat dst_format, SDL_Colorspace dst_colorspace, SDL_PropertiesID dst_properties, void *dst, int dst_pitch) {
  return ::SDL_ConvertPixelsAndColorspace(width, height, src_format, src_colorspace, src_properties, src, src_pitch, dst_format, dst_colorspace, dst_properties, dst, dst_pitch) ? Status() : Status::FromSdl();
}
inline Status CopyFile(const char *oldpath, const char *newpath) {
  return ::SDL_CopyFile(oldpath, newpath) ? Status() : Status::FromSdl();
}
inline Status CreateDirectory(const char *path) {
  return ::SDL_CreateDirectory(path) ? Status() : Status::FromSdl();
}
inline Status CreateWindowAndRenderer(const char *title, int width, int height, SDL_WindowFlags window_flags, SDL_Window **window, SDL_Renderer **renderer) {
  return ::SDL_CreateWindowAndRenderer(title, width, height, window_flags, window, renderer) ? Status() : Status::FromSdl();
}
inline Status CursorVisible() {
  return ::SDL_CursorVisible() ? Status() : Status::FromSdl();
}
inline Status DateTimeToTime(const SDL_DateTime *dt, SDL_Time *ticks) {
  return ::SDL_DateTimeToTime(dt, ticks) ? Status() : Status::FromSdl();
}
inline Status DetachVirtualJoystick(SDL_JoystickID instance_id) {
  return ::SDL_DetachVirtualJoystick(instance_id) ? Status() : Status::FromSdl();
}
inline Status DisableScreenSaver() {
  return ::SDL_DisableScreenSaver() ? Status() : Status::FromSdl();
}
inline Status EnableScreenSaver() {
  return ::SDL_EnableScreenSaver() ? Status() : Status::FromSdl();
}
inline Status EnumerateDirectory(const char *path, SDL_EnumerateDirectoryCallback callback, void *userdata) {
  return ::SDL_EnumerateDirectory(path, callback, userdata) ? Status() : Status::FromSdl();
}
inline Status EventEnabled(Uint32 type) {
  return ::SDL_EventEnabled(type) ? Status() : Status::FromSdl();
}
inline Status GL_DestroyContext(SDL_GLContext context) {
  return ::SDL_GL_DestroyContext(context) ? Status() : Status::FromSdl();
}
inline Status GL_ExtensionSupported(const char *extension) {
  return ::SDL_GL_ExtensionSupported(extension) ? Status() : Status::FromSdl();
}
inline Status GL_GetAttribute(SDL_GLAttr attr, int *value) {
  return ::SDL_GL_GetAttribute(attr, value) ? Status() : Status::FromSdl();
}
inline Status GL_GetSwapInterval(int *interval) {
  return ::SDL_GL_GetSwapInterval(interval) ? Status() : Status::FromSdl();
}
inline Status GL_LoadLibrary(const char *path) {
  return ::SDL_GL_LoadLibrary(path) ? Status() : Status::FromSdl();
}
inline Status GL_SetAttribute(SDL_GLAttr attr, int value) {
  return ::SDL_GL_SetAttribute(attr, value) ? Status() : Status::FromSdl();
}
inline Status GL_SetSwapInterval(int interval) {
  return ::SDL_GL_SetSwapInterval(interval) ? Status() : Status::FromSdl();
}
inline Status GPUSupportsShaderFormats(SDL_GPUShaderFormat format_flags, const char *name) {
  return ::SDL_GPUSupportsShaderFormats(format_flags, name) ? Status() : Status::FromSdl();
}
inline Status GamepadEventsEnabled() {
  return ::SDL_GamepadEventsEnabled() ? Status() : Status::FromSdl();
}
inline Status GetAudioDeviceFormat(SDL_AudioDeviceID devid, SDL_AudioSpec *spec, int *sample_frames) {
  return ::SDL_GetAudioDeviceFormat(devid, spec, sample_frames) ? Status() : Status::FromSdl();
}
inline Status GetClosestFullscreenDisplayMode(SDL_DisplayID displayID, int w, int h, float refresh_rate, bool include_high_density_modes, SDL_DisplayMode *closest) {
  return ::SDL_GetClosestFullscreenDisplayMode(displayID, w, h, refresh_rate, include_high_density_modes, closest) ? Status() : Status::FromSdl();
}
inline Status GetCurrentTime(SDL_Time *ticks) {
  return ::SDL_GetCurrentTime(ticks) ? Status() : Status::FromSdl();
}
inline Status GetDateTimeLocalePreferences(SDL_DateFormat *dateFormat, SDL_TimeFormat *timeFormat) {
  return ::SDL_GetDateTimeLocalePreferences(dateFormat, timeFormat) ? Status() : Status::FromSdl();
}
inline Status GetDisplayBounds(SDL_DisplayID displayID, SDL_Rect *rect) {
  return ::SDL_GetDisplayBounds(displayID, rect) ? Status() : Status::FromSdl();
}
inline Status GetDisplayUsableBounds(SDL_DisplayID displayID, SDL_Rect *rect) {
  return ::SDL_GetDisplayUsableBounds(displayID, rect) ? Status() : Status::FromSdl();
}
inline Status GetEventFilter(SDL_EventFilter *filter, void **userdata) {
  return ::SDL_GetEventFilter(filter, userdata) ? Status() : Status::FromSdl();
}
inline Status GetHintBoolean(const char *name, bool default_value) {
  return ::SDL_GetHintBoolean(name, default_value) ? Status() : Status::FromSdl();
}
inline Status GetMasksForPixelFormat(SDL_PixelFormat format, int *bpp, Uint32 *Rmask, Uint32 *Gmask, Uint32 *Bmask, Uint32 *Amask) {
  return ::SDL_GetMasksForPixelFormat(format, bpp, Rmask, Gmask, Bmask, Amask) ? Status() : Status::FromSdl();
}
inline Status GetPathInfo(const char *path, SDL_PathInfo *info) {
  return ::SDL_GetPathInfo(path, info) ? Status() : Status::FromSdl();
}
inline Status GetRectAndLineIntersection(const SDL_Rect *rect, int *X1, int *Y1, int *X2, int *Y2) {
  return ::SDL_GetRectAndLineIntersection(rect, X1, Y1, X2, Y2) ? Status() : Status::FromSdl();
}
inline Status GetRectAndLineIntersectionFloat(const SDL_FRect *rect, float *X1, float *Y1, float *X2, float *Y2) {
  return ::SDL_GetRectAndLineIntersectionFloat(rect, X1, Y1, X2, Y2) ? Status() : Status::FromSdl();
}
inline Status GetRectEnclosingPoints(const SDL_Point *points, int count, const SDL_Rect *clip, SDL_Rect *result) {
  return ::SDL_GetRectEnclosingPoints(points, count, clip, result) ? Status() : Status::FromSdl();
}
inline Status GetRectEnclosingPointsFloat(const SDL_FPoint *points, int count, const SDL_FRect *clip, SDL_FRect *result) {
  return ::SDL_GetRectEnclosingPointsFloat(points, count, clip, result) ? Status() : Status::FromSdl();
}
inline Status GetRectIntersection(const SDL_Rect *A, const SDL_Rect *B, SDL_Rect *result) {
  return ::SDL_GetRectIntersection(A, B, result) ? Status() : Status::FromSdl();
}
inline Status GetRectIntersectionFloat(const SDL_FRect *A, const SDL_FRect *B, SDL_FRect *result) {
  return ::SDL_GetRectIntersectionFloat(A, B, result) ? Status() : Status::FromSdl();
}
inline Status GetRectUnion(const SDL_Rect *A, const SDL_Rect *B, SDL_Rect *result) {
  return ::SDL_GetRectUnion(A, B, result) ? Status() : Status::FromSdl();
}
inline Status GetRectUnionFloat(const SDL_FRect *A, const SDL_FRect *B, SDL_FRect *result) {
  return ::SDL_GetRectUnionFloat(A, B, result) ? Status() : Status::FromSdl();
}
inline Status GetTrayEntryChecked(SDL_TrayEntry *entry) {
  return ::SDL_GetTrayEntryChecked(entry) ? Status() : Status::FromSdl();
}
inline Status GetTrayEntryEnabled(SDL_TrayEntry *entry) {
  return ::SDL_GetTrayEntryEnabled(entry) ? Status() : Status::FromSdl();
}
inline Status HasARMSIMD() {
  return ::SDL_HasARMSIMD() ? Status() : Status::FromSdl();
}
inline Status HasAVX() {
  return ::SDL_HasAVX() ? Status() : Status::FromSdl();
}
inline Status HasAVX2() {
  return ::SDL_HasAVX2() ? Status() : Status::FromSdl();
}
inline Status HasAVX512F() {
  return ::SDL_HasAVX512F() ? Status() : Status::FromSdl();
}
inline Status HasAltiVec() {
  return ::SDL_HasAltiVec() ? Status() : Status::FromSdl();
}
inline Status HasClipboardData(const char *mime_type) {
  return ::SDL_HasClipboardData(mime_type) ? Status() : Status::FromSdl();
}
inline Status HasClipboardText() {
  return ::SDL_HasClipboardText() ? Status() : Status::FromSdl();
}
inline Status HasEvent(Uint32 type) {
  return ::SDL_HasEvent(type) ? Status() : Status::FromSdl();
}
inline Status HasEvents(Uint32 minType, Uint32 maxType) {
  return ::SDL_HasEvents(minType, maxType) ? Status() : Status::FromSdl();
}
inline Status HasGamepad() {
  return ::SDL_HasGamepad() ? Status() : Status::FromSdl();
}
inline Status HasJoystick() {
  return ::SDL_HasJoystick() ? Status() : Status::FromSdl();
}
inline Status HasKeyboard() {
  return ::SDL_HasKeyboard() ? Status() : Status::FromSdl();
}
inline Status HasLASX() {
  return ::SDL_HasLASX() ? Status() : Status::FromSdl();
}
inline Status HasLSX() {
  return ::SDL_HasLSX() ? Status() : Status::FromSdl();
}
inline Status HasMMX() {
  return ::SDL_HasMMX() ? Status() : Status::FromSdl();
}
inline Status HasMouse() {
  return ::SDL_HasMouse() ? Status() : Status::FromSdl();
}
inline Status HasNEON() {
  return ::SDL_HasNEON() ? Status() : Status::FromSdl();
}
inline Status HasPrimarySelectionText() {
  return ::SDL_HasPrimarySelectionText() ? Status() : Status::FromSdl();
}
inline Status HasRectIntersection(const SDL_Rect *A, const SDL_Rect *B) {
  return ::SDL_HasRectIntersection(A, B) ? Status() : Status::FromSdl();
}
inline Status HasRectIntersectionFloat(const SDL_FRect *A, const SDL_FRect *B) {
  return ::SDL_HasRectIntersectionFloat(A, B) ? Status() : Status::FromSdl();
}
inline Status HasSSE() {
  return ::SDL_HasSSE() ? Status() : Status::FromSdl();
}
inline Status HasSSE2() {
  return ::SDL_HasSSE2() ? Status() : Status::FromSdl();
}
inline Status HasSSE3() {
  return ::SDL_HasSSE3() ? Status() : Status::FromSdl();
}
inline Status HasSSE41() {
  return ::SDL_HasSSE41() ? Status() : Status::FromSdl();
}
inline Status HasSSE42() {
  return ::SDL_HasSSE42() ? Status() : Status::FromSdl();
}
inline Status HasScreenKeyboardSupport() {
  return ::SDL_HasScreenKeyboardSupport() ? Status() : Status::FromSdl();
}
inline Status HideCursor() {
  return ::SDL_HideCursor() ? Status() : Status::FromSdl();
}
inline Status Init(SDL_InitFlags flags) {
  return ::SDL_Init(flags) ? Status() : Status::FromSdl();
}
inline Status InitSubSystem(SDL_InitFlags flags) {
  return ::SDL_InitSubSystem(flags) ? Status() : Status::FromSdl();
}
inline Status IsAudioDevicePhysical(SDL_AudioDeviceID devid) {
  return ::SDL_IsAudioDevicePhysical(devid) ? Status() : Status::FromSdl();
}
inline Status IsAudioDevicePlayback(SDL_AudioDeviceID devid) {
  return ::SDL_IsAudioDevicePlayback(devid) ? Status() : Status::FromSdl();
}
inline Status IsGamepad(SDL_JoystickID instance_id) {
  return ::SDL_IsGamepad(instance_id) ? Status() : Status::FromSdl();
}
inline Status IsJoystickVirtual(SDL_JoystickID instance_id) {
  return ::SDL_IsJoystickVirtual(instance_id) ? Status() : Status::FromSdl();
}
inline Status IsMainThread() {
  return ::SDL_IsMainThread() ? Status() : Status::FromSdl();
}
inline Status IsMouseHaptic() {
  return ::SDL_IsMouseHaptic() ? Status() : Status::FromSdl();
}
inline Status IsTV() {
  return ::SDL_IsTV() ? Status() : Status::FromSdl();
}
inline Status IsTablet() {
  return ::SDL_IsTablet() ? Status() : Status::FromSdl();
}
inline Status JoystickEventsEnabled() {
  return ::SDL_JoystickEventsEnabled() ? Status() : Status::FromSdl();
}
inline Status LoadFileAsync(const char *file, SDL_AsyncIOQueue *queue, void *userdata) {
  return ::SDL_LoadFileAsync(file, queue, userdata) ? Status() : Status::FromSdl();
}
inline Status LoadWAV(const char *path, SDL_AudioSpec *spec, Uint8 **audio_buf, Uint32 *audio_len) {
  return ::SDL_LoadWAV(path, spec, audio_buf, audio_len) ? Status() : Status::FromSdl();
}
inline Status MixAudio(Uint8 *dst, const Uint8 *src, SDL_AudioFormat format, Uint32 len, float volume) {
  return ::SDL_MixAudio(dst, src, format, len, volume) ? Status() : Status::FromSdl();
}
inline Status OpenURL(const char *url) {
  return ::SDL_OpenURL(url) ? Status() : Status::FromSdl();
}
inline Status OutOfMemory() {
  return ::SDL_OutOfMemory() ? Status() : Status::FromSdl();
}
inline Status PauseAudioDevice(SDL_AudioDeviceID devid) {
  return ::SDL_PauseAudioDevice(devid) ? Status() : Status::FromSdl();
}
inline Status PollEvent(SDL_Event *event) {
  return ::SDL_PollEvent(event) ? Status() : Status::FromSdl();
}
inline Status PremultiplyAlpha(int width, int height, SDL_PixelFormat src_format, const void *src, int src_pitch, SDL_PixelFormat dst_format, void *dst, int dst_pitch, bool linear) {
  return ::SDL_PremultiplyAlpha(width, height, src_format, src, src_pitch, dst_format, dst, dst_pitch, linear) ? Status() : Status::FromSdl();
}
inline Status PushEvent(SDL_Event *event) {
  return ::SDL_PushEvent(event) ? Status() : Status::FromSdl();
}
inline Status ReadAsyncIO(SDL_AsyncIO *asyncio, void *ptr, Uint64 offset, Uint64 size, SDL_AsyncIOQueue *queue, void *userdata) {
  return ::SDL_ReadAsyncIO(asyncio, ptr, offset, size, queue, userdata) ? Status() : Status::FromSdl();
}
inline Status ReloadGamepadMappings() {
  return ::SDL_ReloadGamepadMappings() ? Status() : Status::FromSdl();
}
inline Status RemovePath(const char *path) {
  return ::SDL_RemovePath(path) ? Status() : Status::FromSdl();
}
inline Status RemoveTimer(SDL_TimerID id) {
  return ::SDL_RemoveTimer(id) ? Status() : Status::FromSdl();
}
inline Status RenamePath(const char *oldpath, const char *newpath) {
  return ::SDL_RenamePath(oldpath, newpath) ? Status() : Status::FromSdl();
}
inline Status ResetHint(const char *name) {
  return ::SDL_ResetHint(name) ? Status() : Status::FromSdl();
}
inline Status ResumeAudioDevice(SDL_AudioDeviceID devid) {
  return ::SDL_ResumeAudioDevice(devid) ? Status() : Status::FromSdl();
}
inline Status RunOnMainThread(SDL_MainThreadCallback callback, void *userdata, bool wait_complete) {
  return ::SDL_RunOnMainThread(callback, userdata, wait_complete) ? Status() : Status::FromSdl();
}
inline Status SaveFile(const char *file, const void *data, size_t datasize) {
  return ::SDL_SaveFile(file, data, datasize) ? Status() : Status::FromSdl();
}
inline Status ScreenSaverEnabled() {
  return ::SDL_ScreenSaverEnabled() ? Status() : Status::FromSdl();
}
inline Status SetAppMetadata(const char *appname, const char *appversion, const char *appidentifier) {
  return ::SDL_SetAppMetadata(appname, appversion, appidentifier) ? Status() : Status::FromSdl();
}
inline Status SetAppMetadataProperty(const char *name, const char *value) {
  return ::SDL_SetAppMetadataProperty(name, value) ? Status() : Status::FromSdl();
}
inline Status SetAudioDeviceGain(SDL_AudioDeviceID devid, float gain) {
  return ::SDL_SetAudioDeviceGain(devid, gain) ? Status() : Status::FromSdl();
}
inline Status SetAudioPostmixCallback(SDL_AudioDeviceID devid, SDL_AudioPostmixCallback callback, void *userdata) {
  return ::SDL_SetAudioPostmixCallback(devid, callback, userdata) ? Status() : Status::FromSdl();
}
inline Status SetClipboardData(SDL_ClipboardDataCallback callback, SDL_ClipboardCleanupCallback cleanup, void *userdata, const char *const *mime_types, size_t num_mime_types) {
  return ::SDL_SetClipboardData(callback, cleanup, userdata, mime_types, num_mime_types) ? Status() : Status::FromSdl();
}
inline Status SetClipboardText(const char *text) {
  return ::SDL_SetClipboardText(text) ? Status() : Status::FromSdl();
}
inline Status SetCurrentThreadPriority(SDL_ThreadPriority priority) {
  return ::SDL_SetCurrentThreadPriority(priority) ? Status() : Status::FromSdl();
}
inline Status SetGPURenderStateFragmentUniforms(SDL_GPURenderState *state, Uint32 slot_index, const void *data, Uint32 length) {
  return ::SDL_SetGPURenderStateFragmentUniforms(state, slot_index, data, length) ? Status() : Status::FromSdl();
}
inline Status SetGamepadMapping(SDL_JoystickID instance_id, const char *mapping) {
  return ::SDL_SetGamepadMapping(instance_id, mapping) ? Status() : Status::FromSdl();
}
inline Status SetHint(const char *name, const char *value) {
  return ::SDL_SetHint(name, value) ? Status() : Status::FromSdl();
}
inline Status SetHintWithPriority(const char *name, const char *value, SDL_HintPriority priority) {
  return ::SDL_SetHintWithPriority(name, value, priority) ? Status() : Status::FromSdl();
}
inline Status SetLogPriorityPrefix(SDL_LogPriority priority, const char *prefix) {
  return ::SDL_SetLogPriorityPrefix(priority, prefix) ? Status() : Status::FromSdl();
}
inline Status SetMemoryFunctions(SDL_malloc_func malloc_func, SDL_calloc_func calloc_func, SDL_realloc_func realloc_func, SDL_free_func free_func) {
  return ::SDL_SetMemoryFunctions(malloc_func, calloc_func, realloc_func, free_func) ? Status() : Status::FromSdl();
}
inline Status SetPrimarySelectionText(const char *text) {
  return ::SDL_SetPrimarySelectionText(text) ? Status() : Status::FromSdl();
}
inline Status SetRelativeMouseTransform(SDL_MouseMotionTransformCallback callback, void *userdata) {
  return ::SDL_SetRelativeMouseTransform(callback, userdata) ? Status() : Status::FromSdl();
}
inline Status SetScancodeName(SDL_Scancode scancode, const char *name) {
  return ::SDL_SetScancodeName(scancode, name) ? Status() : Status::FromSdl();
}
inline Status SetTLS(SDL_TLSID *id, const void *value, SDL_TLSDestructorCallback destructor) {
  return ::SDL_SetTLS(id, value, destructor) ? Status() : Status::FromSdl();
}
inline Status ShouldInit(SDL_InitState *state) {
  return ::SDL_ShouldInit(state) ? Status() : Status::FromSdl();
}
inline Status ShouldQuit(SDL_InitState *state) {
  return ::SDL_ShouldQuit(state) ? Status() : Status::FromSdl();
}
inline Status ShowCursor() {
  return ::SDL_ShowCursor() ? Status() : Status::FromSdl();
}
inline Status ShowMessageBox(const SDL_MessageBoxData *messageboxdata, int *buttonid) {
  return ::SDL_ShowMessageBox(messageboxdata, buttonid) ? Status() : Status::FromSdl();
}
inline Status ShowSimpleMessageBox(SDL_MessageBoxFlags flags, const char *title, const char *message, SDL_Window *window) {
  return ::SDL_ShowSimpleMessageBox(flags, title, message, window) ? Status() : Status::FromSdl();
}
inline Status SubmitGPUCommandBuffer(SDL_GPUCommandBuffer *command_buffer) {
  return ::SDL_SubmitGPUCommandBuffer(command_buffer) ? Status() : Status::FromSdl();
}
inline Status TimeToDateTime(SDL_Time ticks, SDL_DateTime *dt, bool localTime) {
  return ::SDL_TimeToDateTime(ticks, dt, localTime) ? Status() : Status::FromSdl();
}
inline Status TryLockSpinlock(SDL_SpinLock *lock) {
  return ::SDL_TryLockSpinlock(lock) ? Status() : Status::FromSdl();
}
inline Status WaitAndAcquireGPUSwapchainTexture(SDL_GPUCommandBuffer *command_buffer, SDL_Window *window, SDL_GPUTexture **swapchain_texture, Uint32 *swapchain_texture_width, Uint32 *swapchain_texture_height) {
  return ::SDL_WaitAndAcquireGPUSwapchainTexture(command_buffer, window, swapchain_texture, swapchain_texture_width, swapchain_texture_height) ? Status() : Status::FromSdl();
}
inline Status WaitEvent(SDL_Event *event) {
  return ::SDL_WaitEvent(event) ? Status() : Status::FromSdl();
}
inline Status WaitEventTimeout(SDL_Event *event, Sint32 timeoutMS) {
  return ::SDL_WaitEventTimeout(event, timeoutMS) ? Status() : Status::FromSdl();
}
inline Status WarpMouseGlobal(float x, float y) {
  return ::SDL_WarpMouseGlobal(x, y) ? Status() : Status::FromSdl();
}
inline Status WriteAsyncIO(SDL_AsyncIO *asyncio, void *ptr, Uint64 offset, Uint64 size, SDL_AsyncIOQueue *queue, void *userdata) {
  return ::SDL_WriteAsyncIO(asyncio, ptr, offset, size, queue, userdata) ? Status() : Status::FromSdl();
}

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& AddAtomicInt = ::SDL_AddAtomicInt;
inline constexpr auto& AddAtomicU32 = ::SDL_AddAtomicU32;
inline constexpr auto& AddGamepadMapping = ::SDL_AddGamepadMapping;
inline constexpr auto& AddGamepadMappingsFromFile = ::SDL_AddGamepadMappingsFromFile;
inline constexpr auto& AddTimer = ::SDL_AddTimer;
inline constexpr auto& AddTimerNS = ::SDL_AddTimerNS;
inline constexpr auto& AsyncIOFromFile = ::SDL_AsyncIOFromFile;
inline constexpr auto& AttachVirtualJoystick = ::SDL_AttachVirtualJoystick;
inline constexpr auto& BeginGPUComputePass = ::SDL_BeginGPUComputePass;
inline constexpr auto& BeginGPUCopyPass = ::SDL_BeginGPUCopyPass;
inline constexpr auto& BeginGPURenderPass = ::SDL_BeginGPURenderPass;
inline constexpr auto& BindGPUComputePipeline = ::SDL_BindGPUComputePipeline;
inline constexpr auto& BindGPUComputeSamplers = ::SDL_BindGPUComputeSamplers;
inline constexpr auto& BindGPUComputeStorageBuffers = ::SDL_BindGPUComputeStorageBuffers;
inline constexpr auto& BindGPUComputeStorageTextures = ::SDL_BindGPUComputeStorageTextures;
inline constexpr auto& BindGPUFragmentSamplers = ::SDL_BindGPUFragmentSamplers;
inline constexpr auto& BindGPUFragmentStorageBuffers = ::SDL_BindGPUFragmentStorageBuffers;
inline constexpr auto& BindGPUFragmentStorageTextures = ::SDL_BindGPUFragmentStorageTextures;
inline constexpr auto& BindGPUGraphicsPipeline = ::SDL_BindGPUGraphicsPipeline;
inline constexpr auto& BindGPUIndexBuffer = ::SDL_BindGPUIndexBuffer;
inline constexpr auto& BindGPUVertexBuffers = ::SDL_BindGPUVertexBuffers;
inline constexpr auto& BindGPUVertexSamplers = ::SDL_BindGPUVertexSamplers;
inline constexpr auto& BindGPUVertexStorageBuffers = ::SDL_BindGPUVertexStorageBuffers;
inline constexpr auto& BindGPUVertexStorageTextures = ::SDL_BindGPUVertexStorageTextures;
inline constexpr auto& BlitGPUTexture = ::SDL_BlitGPUTexture;
inline constexpr auto& CalculateGPUTextureFormatSize = ::SDL_CalculateGPUTextureFormatSize;
inline constexpr auto& CleanupTLS = ::SDL_CleanupTLS;
inline constexpr auto& ClickTrayEntry = ::SDL_ClickTrayEntry;
inline constexpr auto& CloseAudioDevice = ::SDL_CloseAudioDevice;
inline constexpr auto& ComposeCustomBlendMode = ::SDL_ComposeCustomBlendMode;
inline constexpr auto& CopyGPUBufferToBuffer = ::SDL_CopyGPUBufferToBuffer;
inline constexpr auto& CopyGPUTextureToTexture = ::SDL_CopyGPUTextureToTexture;
inline constexpr auto& CreateAnimatedCursor = ::SDL_CreateAnimatedCursor;
inline constexpr auto& CreateThreadRuntime = ::SDL_CreateThreadRuntime;
inline constexpr auto& CreateTraySubmenu = ::SDL_CreateTraySubmenu;
inline constexpr auto& Delay = ::SDL_Delay;
inline constexpr auto& DelayNS = ::SDL_DelayNS;
inline constexpr auto& DelayPrecise = ::SDL_DelayPrecise;
inline constexpr auto& DestroyGPURenderState = ::SDL_DestroyGPURenderState;
inline constexpr auto& DetachThread = ::SDL_DetachThread;
inline constexpr auto& DispatchGPUCompute = ::SDL_DispatchGPUCompute;
inline constexpr auto& DispatchGPUComputeIndirect = ::SDL_DispatchGPUComputeIndirect;
inline constexpr auto& DownloadFromGPUBuffer = ::SDL_DownloadFromGPUBuffer;
inline constexpr auto& DownloadFromGPUTexture = ::SDL_DownloadFromGPUTexture;
inline constexpr auto& DrawGPUIndexedPrimitives = ::SDL_DrawGPUIndexedPrimitives;
inline constexpr auto& DrawGPUIndexedPrimitivesIndirect = ::SDL_DrawGPUIndexedPrimitivesIndirect;
inline constexpr auto& DrawGPUPrimitives = ::SDL_DrawGPUPrimitives;
inline constexpr auto& DrawGPUPrimitivesIndirect = ::SDL_DrawGPUPrimitivesIndirect;
inline constexpr auto& EGL_GetCurrentConfig = ::SDL_EGL_GetCurrentConfig;
inline constexpr auto& EGL_GetCurrentDisplay = ::SDL_EGL_GetCurrentDisplay;
inline constexpr auto& EGL_GetProcAddress = ::SDL_EGL_GetProcAddress;
inline constexpr auto& EGL_SetAttributeCallbacks = ::SDL_EGL_SetAttributeCallbacks;
inline constexpr auto& EndGPUComputePass = ::SDL_EndGPUComputePass;
inline constexpr auto& EndGPUCopyPass = ::SDL_EndGPUCopyPass;
inline constexpr auto& EndGPURenderPass = ::SDL_EndGPURenderPass;
inline constexpr auto& FilterEvents = ::SDL_FilterEvents;
inline constexpr auto& FlushEvent = ::SDL_FlushEvent;
inline constexpr auto& FlushEvents = ::SDL_FlushEvents;
inline constexpr auto& GL_GetCurrentContext = ::SDL_GL_GetCurrentContext;
inline constexpr auto& GL_GetCurrentWindow = ::SDL_GL_GetCurrentWindow;
inline constexpr auto& GL_GetProcAddress = ::SDL_GL_GetProcAddress;
inline constexpr auto& GL_ResetAttributes = ::SDL_GL_ResetAttributes;
inline constexpr auto& GL_UnloadLibrary = ::SDL_GL_UnloadLibrary;
inline constexpr auto& GPUTextureFormatTexelBlockSize = ::SDL_GPUTextureFormatTexelBlockSize;
inline constexpr auto& GUIDToString = ::SDL_GUIDToString;
inline constexpr auto& GenerateMipmapsForGPUTexture = ::SDL_GenerateMipmapsForGPUTexture;
inline constexpr auto& GetAppMetadataProperty = ::SDL_GetAppMetadataProperty;
inline constexpr auto& GetAssertionHandler = ::SDL_GetAssertionHandler;
inline constexpr auto& GetAssertionReport = ::SDL_GetAssertionReport;
inline constexpr auto& GetAsyncIOSize = ::SDL_GetAsyncIOSize;
inline constexpr auto& GetAtomicInt = ::SDL_GetAtomicInt;
inline constexpr auto& GetAtomicPointer = ::SDL_GetAtomicPointer;
inline constexpr auto& GetAtomicU32 = ::SDL_GetAtomicU32;
inline constexpr auto& GetAudioDeviceChannelMap = ::SDL_GetAudioDeviceChannelMap;
inline constexpr auto& GetAudioDeviceGain = ::SDL_GetAudioDeviceGain;
inline constexpr auto& GetAudioDeviceName = ::SDL_GetAudioDeviceName;
inline constexpr auto& GetAudioDriver = ::SDL_GetAudioDriver;
inline constexpr auto& GetAudioFormatName = ::SDL_GetAudioFormatName;
inline constexpr auto& GetAudioPlaybackDevices = ::SDL_GetAudioPlaybackDevices;
inline constexpr auto& GetAudioRecordingDevices = ::SDL_GetAudioRecordingDevices;
inline constexpr auto& GetBasePath = ::SDL_GetBasePath;
inline constexpr auto& GetCPUCacheLineSize = ::SDL_GetCPUCacheLineSize;
inline constexpr auto& GetCameraDriver = ::SDL_GetCameraDriver;
inline constexpr auto& GetCameraName = ::SDL_GetCameraName;
inline constexpr auto& GetCameraPosition = ::SDL_GetCameraPosition;
inline constexpr auto& GetCameraSupportedFormats = ::SDL_GetCameraSupportedFormats;
inline constexpr auto& GetCameras = ::SDL_GetCameras;
inline constexpr auto& GetClipboardData = ::SDL_GetClipboardData;
inline constexpr auto& GetClipboardMimeTypes = ::SDL_GetClipboardMimeTypes;
inline constexpr auto& GetClipboardText = ::SDL_GetClipboardText;
inline constexpr auto& GetCurrentAudioDriver = ::SDL_GetCurrentAudioDriver;
inline constexpr auto& GetCurrentCameraDriver = ::SDL_GetCurrentCameraDriver;
inline constexpr auto& GetCurrentDirectory = ::SDL_GetCurrentDirectory;
inline constexpr auto& GetCurrentDisplayMode = ::SDL_GetCurrentDisplayMode;
inline constexpr auto& GetCurrentDisplayOrientation = ::SDL_GetCurrentDisplayOrientation;
inline constexpr auto& GetCurrentThreadID = ::SDL_GetCurrentThreadID;
inline constexpr auto& GetCurrentVideoDriver = ::SDL_GetCurrentVideoDriver;
inline constexpr auto& GetCursor = ::SDL_GetCursor;
inline constexpr auto& GetDayOfWeek = ::SDL_GetDayOfWeek;
inline constexpr auto& GetDayOfYear = ::SDL_GetDayOfYear;
inline constexpr auto& GetDaysInMonth = ::SDL_GetDaysInMonth;
inline constexpr auto& GetDefaultAssertionHandler = ::SDL_GetDefaultAssertionHandler;
inline constexpr auto& GetDefaultCursor = ::SDL_GetDefaultCursor;
inline constexpr auto& GetDefaultLogOutputFunction = ::SDL_GetDefaultLogOutputFunction;
inline constexpr auto& GetDesktopDisplayMode = ::SDL_GetDesktopDisplayMode;
inline constexpr auto& GetDisplayContentScale = ::SDL_GetDisplayContentScale;
inline constexpr auto& GetDisplayForPoint = ::SDL_GetDisplayForPoint;
inline constexpr auto& GetDisplayForRect = ::SDL_GetDisplayForRect;
inline constexpr auto& GetDisplayName = ::SDL_GetDisplayName;
inline constexpr auto& GetDisplayProperties = ::SDL_GetDisplayProperties;
inline constexpr auto& GetDisplays = ::SDL_GetDisplays;
inline constexpr auto& GetEnvironment = ::SDL_GetEnvironment;
inline constexpr auto& GetError = ::SDL_GetError;
inline constexpr auto& GetEventDescription = ::SDL_GetEventDescription;
inline constexpr auto& GetFullscreenDisplayModes = ::SDL_GetFullscreenDisplayModes;
inline constexpr auto& GetGPUDriver = ::SDL_GetGPUDriver;
inline constexpr auto& GetGPUTextureFormatFromPixelFormat = ::SDL_GetGPUTextureFormatFromPixelFormat;
inline constexpr auto& GetGamepadAxisFromString = ::SDL_GetGamepadAxisFromString;
inline constexpr auto& GetGamepadButtonFromString = ::SDL_GetGamepadButtonFromString;
inline constexpr auto& GetGamepadButtonLabelForType = ::SDL_GetGamepadButtonLabelForType;
inline constexpr auto& GetGamepadFromID = ::SDL_GetGamepadFromID;
inline constexpr auto& GetGamepadFromPlayerIndex = ::SDL_GetGamepadFromPlayerIndex;
inline constexpr auto& GetGamepadGUIDForID = ::SDL_GetGamepadGUIDForID;
inline constexpr auto& GetGamepadMappingForGUID = ::SDL_GetGamepadMappingForGUID;
inline constexpr auto& GetGamepadMappingForID = ::SDL_GetGamepadMappingForID;
inline constexpr auto& GetGamepadMappings = ::SDL_GetGamepadMappings;
inline constexpr auto& GetGamepadNameForID = ::SDL_GetGamepadNameForID;
inline constexpr auto& GetGamepadPathForID = ::SDL_GetGamepadPathForID;
inline constexpr auto& GetGamepadPlayerIndexForID = ::SDL_GetGamepadPlayerIndexForID;
inline constexpr auto& GetGamepadProductForID = ::SDL_GetGamepadProductForID;
inline constexpr auto& GetGamepadProductVersionForID = ::SDL_GetGamepadProductVersionForID;
inline constexpr auto& GetGamepadStringForAxis = ::SDL_GetGamepadStringForAxis;
inline constexpr auto& GetGamepadStringForButton = ::SDL_GetGamepadStringForButton;
inline constexpr auto& GetGamepadStringForType = ::SDL_GetGamepadStringForType;
inline constexpr auto& GetGamepadTypeForID = ::SDL_GetGamepadTypeForID;
inline constexpr auto& GetGamepadTypeFromString = ::SDL_GetGamepadTypeFromString;
inline constexpr auto& GetGamepadVendorForID = ::SDL_GetGamepadVendorForID;
inline constexpr auto& GetGamepads = ::SDL_GetGamepads;
inline constexpr auto& GetGlobalMouseState = ::SDL_GetGlobalMouseState;
inline constexpr auto& GetGlobalProperties = ::SDL_GetGlobalProperties;
inline constexpr auto& GetGrabbedWindow = ::SDL_GetGrabbedWindow;
inline constexpr auto& GetHapticFromID = ::SDL_GetHapticFromID;
inline constexpr auto& GetHapticNameForID = ::SDL_GetHapticNameForID;
inline constexpr auto& GetHaptics = ::SDL_GetHaptics;
inline constexpr auto& GetHint = ::SDL_GetHint;
inline constexpr auto& GetJoystickFromID = ::SDL_GetJoystickFromID;
inline constexpr auto& GetJoystickFromPlayerIndex = ::SDL_GetJoystickFromPlayerIndex;
inline constexpr auto& GetJoystickGUIDForID = ::SDL_GetJoystickGUIDForID;
inline constexpr auto& GetJoystickGUIDInfo = ::SDL_GetJoystickGUIDInfo;
inline constexpr auto& GetJoystickNameForID = ::SDL_GetJoystickNameForID;
inline constexpr auto& GetJoystickPathForID = ::SDL_GetJoystickPathForID;
inline constexpr auto& GetJoystickPlayerIndexForID = ::SDL_GetJoystickPlayerIndexForID;
inline constexpr auto& GetJoystickProductForID = ::SDL_GetJoystickProductForID;
inline constexpr auto& GetJoystickProductVersionForID = ::SDL_GetJoystickProductVersionForID;
inline constexpr auto& GetJoystickTypeForID = ::SDL_GetJoystickTypeForID;
inline constexpr auto& GetJoystickVendorForID = ::SDL_GetJoystickVendorForID;
inline constexpr auto& GetJoysticks = ::SDL_GetJoysticks;
inline constexpr auto& GetKeyFromName = ::SDL_GetKeyFromName;
inline constexpr auto& GetKeyFromScancode = ::SDL_GetKeyFromScancode;
inline constexpr auto& GetKeyName = ::SDL_GetKeyName;
inline constexpr auto& GetKeyboardFocus = ::SDL_GetKeyboardFocus;
inline constexpr auto& GetKeyboardNameForID = ::SDL_GetKeyboardNameForID;
inline constexpr auto& GetKeyboardState = ::SDL_GetKeyboardState;
inline constexpr auto& GetKeyboards = ::SDL_GetKeyboards;
inline constexpr auto& GetLogOutputFunction = ::SDL_GetLogOutputFunction;
inline constexpr auto& GetLogPriority = ::SDL_GetLogPriority;
inline constexpr auto& GetMemoryFunctions = ::SDL_GetMemoryFunctions;
inline constexpr auto& GetMice = ::SDL_GetMice;
inline constexpr auto& GetModState = ::SDL_GetModState;
inline constexpr auto& GetMouseFocus = ::SDL_GetMouseFocus;
inline constexpr auto& GetMouseNameForID = ::SDL_GetMouseNameForID;
inline constexpr auto& GetMouseState = ::SDL_GetMouseState;
inline constexpr auto& GetNaturalDisplayOrientation = ::SDL_GetNaturalDisplayOrientation;
inline constexpr auto& GetNumAllocations = ::SDL_GetNumAllocations;
inline constexpr auto& GetNumAudioDrivers = ::SDL_GetNumAudioDrivers;
inline constexpr auto& GetNumCameraDrivers = ::SDL_GetNumCameraDrivers;
inline constexpr auto& GetNumGPUDrivers = ::SDL_GetNumGPUDrivers;
inline constexpr auto& GetNumLogicalCPUCores = ::SDL_GetNumLogicalCPUCores;
inline constexpr auto& GetNumRenderDrivers = ::SDL_GetNumRenderDrivers;
inline constexpr auto& GetNumVideoDrivers = ::SDL_GetNumVideoDrivers;
inline constexpr auto& GetOriginalMemoryFunctions = ::SDL_GetOriginalMemoryFunctions;
inline constexpr auto& GetPenDeviceType = ::SDL_GetPenDeviceType;
inline constexpr auto& GetPerformanceCounter = ::SDL_GetPerformanceCounter;
inline constexpr auto& GetPerformanceFrequency = ::SDL_GetPerformanceFrequency;
inline constexpr auto& GetPixelFormatDetails = ::SDL_GetPixelFormatDetails;
inline constexpr auto& GetPixelFormatForMasks = ::SDL_GetPixelFormatForMasks;
inline constexpr auto& GetPixelFormatFromGPUTextureFormat = ::SDL_GetPixelFormatFromGPUTextureFormat;
inline constexpr auto& GetPixelFormatName = ::SDL_GetPixelFormatName;
inline constexpr auto& GetPlatform = ::SDL_GetPlatform;
inline constexpr auto& GetPowerInfo = ::SDL_GetPowerInfo;
inline constexpr auto& GetPrefPath = ::SDL_GetPrefPath;
inline constexpr auto& GetPreferredLocales = ::SDL_GetPreferredLocales;
inline constexpr auto& GetPrimaryDisplay = ::SDL_GetPrimaryDisplay;
inline constexpr auto& GetPrimarySelectionText = ::SDL_GetPrimarySelectionText;
inline constexpr auto& GetRGB = ::SDL_GetRGB;
inline constexpr auto& GetRGBA = ::SDL_GetRGBA;
inline constexpr auto& GetRealGamepadTypeForID = ::SDL_GetRealGamepadTypeForID;
inline constexpr auto& GetRelativeMouseState = ::SDL_GetRelativeMouseState;
inline constexpr auto& GetRenderDriver = ::SDL_GetRenderDriver;
inline constexpr auto& GetRevision = ::SDL_GetRevision;
inline constexpr auto& GetSIMDAlignment = ::SDL_GetSIMDAlignment;
inline constexpr auto& GetSandbox = ::SDL_GetSandbox;
inline constexpr auto& GetScancodeFromKey = ::SDL_GetScancodeFromKey;
inline constexpr auto& GetScancodeFromName = ::SDL_GetScancodeFromName;
inline constexpr auto& GetScancodeName = ::SDL_GetScancodeName;
inline constexpr auto& GetSensorFromID = ::SDL_GetSensorFromID;
inline constexpr auto& GetSensorNameForID = ::SDL_GetSensorNameForID;
inline constexpr auto& GetSensorNonPortableTypeForID = ::SDL_GetSensorNonPortableTypeForID;
inline constexpr auto& GetSensorTypeForID = ::SDL_GetSensorTypeForID;
inline constexpr auto& GetSensors = ::SDL_GetSensors;
inline constexpr auto& GetSilenceValueForFormat = ::SDL_GetSilenceValueForFormat;
inline constexpr auto& GetSystemPageSize = ::SDL_GetSystemPageSize;
inline constexpr auto& GetSystemRAM = ::SDL_GetSystemRAM;
inline constexpr auto& GetSystemTheme = ::SDL_GetSystemTheme;
inline constexpr auto& GetTLS = ::SDL_GetTLS;
inline constexpr auto& GetThreadID = ::SDL_GetThreadID;
inline constexpr auto& GetThreadName = ::SDL_GetThreadName;
inline constexpr auto& GetThreadState = ::SDL_GetThreadState;
inline constexpr auto& GetTicks = ::SDL_GetTicks;
inline constexpr auto& GetTicksNS = ::SDL_GetTicksNS;
inline constexpr auto& GetTouchDeviceName = ::SDL_GetTouchDeviceName;
inline constexpr auto& GetTouchDeviceType = ::SDL_GetTouchDeviceType;
inline constexpr auto& GetTouchDevices = ::SDL_GetTouchDevices;
inline constexpr auto& GetTouchFingers = ::SDL_GetTouchFingers;
inline constexpr auto& GetTrayEntries = ::SDL_GetTrayEntries;
inline constexpr auto& GetTrayEntryLabel = ::SDL_GetTrayEntryLabel;
inline constexpr auto& GetTrayEntryParent = ::SDL_GetTrayEntryParent;
inline constexpr auto& GetTrayMenuParentEntry = ::SDL_GetTrayMenuParentEntry;
inline constexpr auto& GetTrayMenuParentTray = ::SDL_GetTrayMenuParentTray;
inline constexpr auto& GetTraySubmenu = ::SDL_GetTraySubmenu;
inline constexpr auto& GetUserFolder = ::SDL_GetUserFolder;
inline constexpr auto& GetVersion = ::SDL_GetVersion;
inline constexpr auto& GetVideoDriver = ::SDL_GetVideoDriver;
inline constexpr auto& GetWindowFromEvent = ::SDL_GetWindowFromEvent;
inline constexpr auto& GetWindowFromID = ::SDL_GetWindowFromID;
inline constexpr auto& GetWindows = ::SDL_GetWindows;
inline constexpr auto& GlobDirectory = ::SDL_GlobDirectory;
inline constexpr auto& InsertGPUDebugLabel = ::SDL_InsertGPUDebugLabel;
inline constexpr auto& InsertTrayEntryAt = ::SDL_InsertTrayEntryAt;
inline constexpr auto& LoadFile = ::SDL_LoadFile;
inline constexpr auto& LoadPNG = ::SDL_LoadPNG;
inline constexpr auto& LoadSurface = ::SDL_LoadSurface;
inline constexpr auto& LockJoysticks = ::SDL_LockJoysticks;
inline constexpr auto& LockMutex = ::SDL_LockMutex;
inline constexpr auto& LockRWLockForReading = ::SDL_LockRWLockForReading;
inline constexpr auto& LockRWLockForWriting = ::SDL_LockRWLockForWriting;
inline constexpr auto& LockSpinlock = ::SDL_LockSpinlock;
inline constexpr auto& MapRGB = ::SDL_MapRGB;
inline constexpr auto& MapRGBA = ::SDL_MapRGBA;
inline constexpr auto& MemoryBarrierAcquireFunction = ::SDL_MemoryBarrierAcquireFunction;
inline constexpr auto& MemoryBarrierReleaseFunction = ::SDL_MemoryBarrierReleaseFunction;
inline constexpr auto& Metal_DestroyView = ::SDL_Metal_DestroyView;
inline constexpr auto& Metal_GetLayer = ::SDL_Metal_GetLayer;
inline constexpr auto& OnApplicationDidEnterBackground = ::SDL_OnApplicationDidEnterBackground;
inline constexpr auto& OnApplicationDidEnterForeground = ::SDL_OnApplicationDidEnterForeground;
inline constexpr auto& OnApplicationDidReceiveMemoryWarning = ::SDL_OnApplicationDidReceiveMemoryWarning;
inline constexpr auto& OnApplicationWillEnterBackground = ::SDL_OnApplicationWillEnterBackground;
inline constexpr auto& OnApplicationWillEnterForeground = ::SDL_OnApplicationWillEnterForeground;
inline constexpr auto& OnApplicationWillTerminate = ::SDL_OnApplicationWillTerminate;
inline constexpr auto& OpenAudioDevice = ::SDL_OpenAudioDevice;
inline constexpr auto& OpenIO = ::SDL_OpenIO;
inline constexpr auto& PeepEvents = ::SDL_PeepEvents;
inline constexpr auto& PopGPUDebugGroup = ::SDL_PopGPUDebugGroup;
inline constexpr auto& PumpEvents = ::SDL_PumpEvents;
inline constexpr auto& PushGPUComputeUniformData = ::SDL_PushGPUComputeUniformData;
inline constexpr auto& PushGPUDebugGroup = ::SDL_PushGPUDebugGroup;
inline constexpr auto& PushGPUFragmentUniformData = ::SDL_PushGPUFragmentUniformData;
inline constexpr auto& PushGPUVertexUniformData = ::SDL_PushGPUVertexUniformData;
inline constexpr auto& Quit = ::SDL_Quit;
inline constexpr auto& QuitSubSystem = ::SDL_QuitSubSystem;
inline constexpr auto& RegisterEvents = ::SDL_RegisterEvents;
inline constexpr auto& RemoveEventWatch = ::SDL_RemoveEventWatch;
inline constexpr auto& RemoveHintCallback = ::SDL_RemoveHintCallback;
inline constexpr auto& RemoveTrayEntry = ::SDL_RemoveTrayEntry;
inline constexpr auto& ResetAssertionReport = ::SDL_ResetAssertionReport;
inline constexpr auto& ResetHints = ::SDL_ResetHints;
inline constexpr auto& ResetKeyboard = ::SDL_ResetKeyboard;
inline constexpr auto& ResetLogPriorities = ::SDL_ResetLogPriorities;
inline constexpr auto& SetAssertionHandler = ::SDL_SetAssertionHandler;
inline constexpr auto& SetAtomicInt = ::SDL_SetAtomicInt;
inline constexpr auto& SetAtomicPointer = ::SDL_SetAtomicPointer;
inline constexpr auto& SetAtomicU32 = ::SDL_SetAtomicU32;
inline constexpr auto& SetEventEnabled = ::SDL_SetEventEnabled;
inline constexpr auto& SetEventFilter = ::SDL_SetEventFilter;
inline constexpr auto& SetGPUBlendConstants = ::SDL_SetGPUBlendConstants;
inline constexpr auto& SetGPUScissor = ::SDL_SetGPUScissor;
inline constexpr auto& SetGPUStencilReference = ::SDL_SetGPUStencilReference;
inline constexpr auto& SetGPUViewport = ::SDL_SetGPUViewport;
inline constexpr auto& SetGamepadEventsEnabled = ::SDL_SetGamepadEventsEnabled;
inline constexpr auto& SetInitialized = ::SDL_SetInitialized;
inline constexpr auto& SetJoystickEventsEnabled = ::SDL_SetJoystickEventsEnabled;
inline constexpr auto& SetLogOutputFunction = ::SDL_SetLogOutputFunction;
inline constexpr auto& SetLogPriorities = ::SDL_SetLogPriorities;
inline constexpr auto& SetLogPriority = ::SDL_SetLogPriority;
inline constexpr auto& SetModState = ::SDL_SetModState;
inline constexpr auto& SetTrayEntryCallback = ::SDL_SetTrayEntryCallback;
inline constexpr auto& SetTrayEntryChecked = ::SDL_SetTrayEntryChecked;
inline constexpr auto& SetTrayEntryEnabled = ::SDL_SetTrayEntryEnabled;
inline constexpr auto& SetTrayEntryLabel = ::SDL_SetTrayEntryLabel;
inline constexpr auto& SetX11EventHook = ::SDL_SetX11EventHook;
inline constexpr auto& ShowFileDialogWithProperties = ::SDL_ShowFileDialogWithProperties;
inline constexpr auto& ShowOpenFileDialog = ::SDL_ShowOpenFileDialog;
inline constexpr auto& ShowOpenFolderDialog = ::SDL_ShowOpenFolderDialog;
inline constexpr auto& ShowSaveFileDialog = ::SDL_ShowSaveFileDialog;
inline constexpr auto& StepBackUTF8 = ::SDL_StepBackUTF8;
inline constexpr auto& StepUTF8 = ::SDL_StepUTF8;
inline constexpr auto& StringToGUID = ::SDL_StringToGUID;
inline constexpr auto& SubmitGPUCommandBufferAndAcquireFence = ::SDL_SubmitGPUCommandBufferAndAcquireFence;
inline constexpr auto& TimeFromWindows = ::SDL_TimeFromWindows;
inline constexpr auto& TimeToWindows = ::SDL_TimeToWindows;
inline constexpr auto& TryLockMutex = ::SDL_TryLockMutex;
inline constexpr auto& TryLockRWLockForReading = ::SDL_TryLockRWLockForReading;
inline constexpr auto& TryLockRWLockForWriting = ::SDL_TryLockRWLockForWriting;
inline constexpr auto& UCS4ToUTF8 = ::SDL_UCS4ToUTF8;
inline constexpr auto& UnbindAudioStreams = ::SDL_UnbindAudioStreams;
inline constexpr auto& UnlockJoysticks = ::SDL_UnlockJoysticks;
inline constexpr auto& UnlockMutex = ::SDL_UnlockMutex;
inline constexpr auto& UnlockRWLock = ::SDL_UnlockRWLock;
inline constexpr auto& UnlockSpinlock = ::SDL_UnlockSpinlock;
inline constexpr auto& UpdateGamepads = ::SDL_UpdateGamepads;
inline constexpr auto& UpdateJoysticks = ::SDL_UpdateJoysticks;
inline constexpr auto& UpdateSensors = ::SDL_UpdateSensors;
inline constexpr auto& UpdateTrays = ::SDL_UpdateTrays;
inline constexpr auto& UploadToGPUBuffer = ::SDL_UploadToGPUBuffer;
inline constexpr auto& UploadToGPUTexture = ::SDL_UploadToGPUTexture;
inline constexpr auto& WaitThread = ::SDL_WaitThread;
inline constexpr auto& WasInit = ::SDL_WasInit;
inline constexpr auto& abs = ::SDL_abs;
inline constexpr auto& acos = ::SDL_acos;
inline constexpr auto& acosf = ::SDL_acosf;
inline constexpr auto& aligned_alloc = ::SDL_aligned_alloc;
inline constexpr auto& aligned_free = ::SDL_aligned_free;
inline constexpr auto& asin = ::SDL_asin;
inline constexpr auto& asinf = ::SDL_asinf;
inline constexpr auto& atan = ::SDL_atan;
inline constexpr auto& atan2 = ::SDL_atan2;
inline constexpr auto& atan2f = ::SDL_atan2f;
inline constexpr auto& atanf = ::SDL_atanf;
inline constexpr auto& atof = ::SDL_atof;
inline constexpr auto& atoi = ::SDL_atoi;
inline constexpr auto& bsearch = ::SDL_bsearch;
inline constexpr auto& bsearch_r = ::SDL_bsearch_r;
inline constexpr auto& ceil = ::SDL_ceil;
inline constexpr auto& ceilf = ::SDL_ceilf;
inline constexpr auto& copysign = ::SDL_copysign;
inline constexpr auto& copysignf = ::SDL_copysignf;
inline constexpr auto& cos = ::SDL_cos;
inline constexpr auto& cosf = ::SDL_cosf;
inline constexpr auto& crc16 = ::SDL_crc16;
inline constexpr auto& crc32 = ::SDL_crc32;
inline constexpr auto& exp = ::SDL_exp;
inline constexpr auto& expf = ::SDL_expf;
inline constexpr auto& fabs = ::SDL_fabs;
inline constexpr auto& fabsf = ::SDL_fabsf;
inline constexpr auto& floor = ::SDL_floor;
inline constexpr auto& floorf = ::SDL_floorf;
inline constexpr auto& fmod = ::SDL_fmod;
inline constexpr auto& fmodf = ::SDL_fmodf;
inline constexpr auto& free = ::SDL_free;
inline constexpr auto& getenv = ::SDL_getenv;
inline constexpr auto& getenv_unsafe = ::SDL_getenv_unsafe;
inline constexpr auto& hid_ble_scan = ::SDL_hid_ble_scan;
inline constexpr auto& hid_close = ::SDL_hid_close;
inline constexpr auto& hid_device_change_count = ::SDL_hid_device_change_count;
inline constexpr auto& hid_enumerate = ::SDL_hid_enumerate;
inline constexpr auto& hid_exit = ::SDL_hid_exit;
inline constexpr auto& hid_free_enumeration = ::SDL_hid_free_enumeration;
inline constexpr auto& hid_get_device_info = ::SDL_hid_get_device_info;
inline constexpr auto& hid_get_feature_report = ::SDL_hid_get_feature_report;
inline constexpr auto& hid_get_indexed_string = ::SDL_hid_get_indexed_string;
inline constexpr auto& hid_get_input_report = ::SDL_hid_get_input_report;
inline constexpr auto& hid_get_manufacturer_string = ::SDL_hid_get_manufacturer_string;
inline constexpr auto& hid_get_product_string = ::SDL_hid_get_product_string;
inline constexpr auto& hid_get_properties = ::SDL_hid_get_properties;
inline constexpr auto& hid_get_report_descriptor = ::SDL_hid_get_report_descriptor;
inline constexpr auto& hid_get_serial_number_string = ::SDL_hid_get_serial_number_string;
inline constexpr auto& hid_init = ::SDL_hid_init;
inline constexpr auto& hid_open = ::SDL_hid_open;
inline constexpr auto& hid_open_path = ::SDL_hid_open_path;
inline constexpr auto& hid_read = ::SDL_hid_read;
inline constexpr auto& hid_read_timeout = ::SDL_hid_read_timeout;
inline constexpr auto& hid_send_feature_report = ::SDL_hid_send_feature_report;
inline constexpr auto& hid_set_nonblocking = ::SDL_hid_set_nonblocking;
inline constexpr auto& hid_write = ::SDL_hid_write;
inline constexpr auto& iconv = ::SDL_iconv;
inline constexpr auto& iconv_close = ::SDL_iconv_close;
inline constexpr auto& iconv_open = ::SDL_iconv_open;
inline constexpr auto& iconv_string = ::SDL_iconv_string;
inline constexpr auto& isalnum = ::SDL_isalnum;
inline constexpr auto& isalpha = ::SDL_isalpha;
inline constexpr auto& isblank = ::SDL_isblank;
inline constexpr auto& iscntrl = ::SDL_iscntrl;
inline constexpr auto& isdigit = ::SDL_isdigit;
inline constexpr auto& isgraph = ::SDL_isgraph;
inline constexpr auto& isinf = ::SDL_isinf;
inline constexpr auto& isinff = ::SDL_isinff;
inline constexpr auto& islower = ::SDL_islower;
inline constexpr auto& isnan = ::SDL_isnan;
inline constexpr auto& isnanf = ::SDL_isnanf;
inline constexpr auto& isprint = ::SDL_isprint;
inline constexpr auto& ispunct = ::SDL_ispunct;
inline constexpr auto& isspace = ::SDL_isspace;
inline constexpr auto& isupper = ::SDL_isupper;
inline constexpr auto& isxdigit = ::SDL_isxdigit;
inline constexpr auto& itoa = ::SDL_itoa;
inline constexpr auto& lltoa = ::SDL_lltoa;
inline constexpr auto& log = ::SDL_log;
inline constexpr auto& log10 = ::SDL_log10;
inline constexpr auto& log10f = ::SDL_log10f;
inline constexpr auto& logf = ::SDL_logf;
inline constexpr auto& lround = ::SDL_lround;
inline constexpr auto& lroundf = ::SDL_lroundf;
inline constexpr auto& ltoa = ::SDL_ltoa;
inline constexpr auto& malloc = ::SDL_malloc;
inline constexpr auto& memcmp = ::SDL_memcmp;
inline constexpr auto& memcpy = ::SDL_memcpy;
inline constexpr auto& memmove = ::SDL_memmove;
inline constexpr auto& memset = ::SDL_memset;
inline constexpr auto& memset4 = ::SDL_memset4;
inline constexpr auto& modf = ::SDL_modf;
inline constexpr auto& modff = ::SDL_modff;
inline constexpr auto& murmur3_32 = ::SDL_murmur3_32;
inline constexpr auto& pow = ::SDL_pow;
inline constexpr auto& powf = ::SDL_powf;
inline constexpr auto& qsort = ::SDL_qsort;
inline constexpr auto& qsort_r = ::SDL_qsort_r;
inline constexpr auto& rand = ::SDL_rand;
inline constexpr auto& rand_bits = ::SDL_rand_bits;
inline constexpr auto& rand_bits_r = ::SDL_rand_bits_r;
inline constexpr auto& rand_r = ::SDL_rand_r;
inline constexpr auto& randf = ::SDL_randf;
inline constexpr auto& randf_r = ::SDL_randf_r;
inline constexpr auto& round = ::SDL_round;
inline constexpr auto& roundf = ::SDL_roundf;
inline constexpr auto& scalbn = ::SDL_scalbn;
inline constexpr auto& scalbnf = ::SDL_scalbnf;
inline constexpr auto& setenv_unsafe = ::SDL_setenv_unsafe;
inline constexpr auto& sin = ::SDL_sin;
inline constexpr auto& sinf = ::SDL_sinf;
inline constexpr auto& sqrt = ::SDL_sqrt;
inline constexpr auto& sqrtf = ::SDL_sqrtf;
inline constexpr auto& srand = ::SDL_srand;
inline constexpr auto& strcasecmp = ::SDL_strcasecmp;
inline constexpr auto& strcasestr = ::SDL_strcasestr;
inline constexpr auto& strchr = ::SDL_strchr;
inline constexpr auto& strcmp = ::SDL_strcmp;
inline constexpr auto& strdup = ::SDL_strdup;
inline constexpr auto& strlcat = ::SDL_strlcat;
inline constexpr auto& strlcpy = ::SDL_strlcpy;
inline constexpr auto& strlen = ::SDL_strlen;
inline constexpr auto& strlwr = ::SDL_strlwr;
inline constexpr auto& strncasecmp = ::SDL_strncasecmp;
inline constexpr auto& strncmp = ::SDL_strncmp;
inline constexpr auto& strndup = ::SDL_strndup;
inline constexpr auto& strnlen = ::SDL_strnlen;
inline constexpr auto& strnstr = ::SDL_strnstr;
inline constexpr auto& strpbrk = ::SDL_strpbrk;
inline constexpr auto& strrchr = ::SDL_strrchr;
inline constexpr auto& strrev = ::SDL_strrev;
inline constexpr auto& strstr = ::SDL_strstr;
inline constexpr auto& strtod = ::SDL_strtod;
inline constexpr auto& strtok_r = ::SDL_strtok_r;
inline constexpr auto& strtol = ::SDL_strtol;
inline constexpr auto& strtoll = ::SDL_strtoll;
inline constexpr auto& strtoul = ::SDL_strtoul;
inline constexpr auto& strtoull = ::SDL_strtoull;
inline constexpr auto& strupr = ::SDL_strupr;
inline constexpr auto& tan = ::SDL_tan;
inline constexpr auto& tanf = ::SDL_tanf;
inline constexpr auto& tolower = ::SDL_tolower;
inline constexpr auto& toupper = ::SDL_toupper;
inline constexpr auto& trunc = ::SDL_trunc;
inline constexpr auto& truncf = ::SDL_truncf;
inline constexpr auto& uitoa = ::SDL_uitoa;
inline constexpr auto& ulltoa = ::SDL_ulltoa;
inline constexpr auto& ultoa = ::SDL_ultoa;
inline constexpr auto& unsetenv_unsafe = ::SDL_unsetenv_unsafe;
inline constexpr auto& utf8strlcpy = ::SDL_utf8strlcpy;
inline constexpr auto& utf8strlen = ::SDL_utf8strlen;
inline constexpr auto& utf8strnlen = ::SDL_utf8strnlen;
inline constexpr auto& wcscasecmp = ::SDL_wcscasecmp;
inline constexpr auto& wcscmp = ::SDL_wcscmp;
inline constexpr auto& wcsdup = ::SDL_wcsdup;
inline constexpr auto& wcslcat = ::SDL_wcslcat;
inline constexpr auto& wcslcpy = ::SDL_wcslcpy;
inline constexpr auto& wcslen = ::SDL_wcslen;
inline constexpr auto& wcsncasecmp = ::SDL_wcsncasecmp;
inline constexpr auto& wcsncmp = ::SDL_wcsncmp;
inline constexpr auto& wcsnlen = ::SDL_wcsnlen;
inline constexpr auto& wcsnstr = ::SDL_wcsnstr;
inline constexpr auto& wcsstr = ::SDL_wcsstr;
inline constexpr auto& wcstol = ::SDL_wcstol;

}  // namespace sdl
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_SDL_H_
// clang-format on
