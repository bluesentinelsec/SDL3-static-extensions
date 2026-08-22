// app.h — RAII over SDL window/renderer/surface/texture, with VFS-aware
// image loading and the SDL debug-text helper.
// Original SDLStatic code (zlib).

#ifndef SDLSTATIC_CPP_APP_H_
#define SDLSTATIC_CPP_APP_H_

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDLStatic/vfs.h>
#include <physfs.h>

#include <string>
#include <utility>

#include "sdlstatic/status.h"

namespace sdlstatic {

// Owns SDL initialization: SDL_Quit runs when this is destroyed. Declare
// it BEFORE every other owner (windows, renderers, mixers...) so C++
// destruction order tears the owners down first and SDL last. Calling
// SDL_Quit manually in the same scope as owners is a real crash we shipped
// once: the mixer's destructor ran after the audio subsystem was gone.
class SdlInit {
 public:
  static Result<SdlInit> Create(SDL_InitFlags flags) {
    if (!SDL_Init(flags)) return Status::FromSdl();
    return SdlInit(true);
  }

  ~SdlInit() {
    if (owned_) SDL_Quit();
  }
  SdlInit(SdlInit&& other) noexcept : owned_(std::exchange(other.owned_, false)) {}
  SdlInit& operator=(SdlInit&& other) noexcept {
    std::swap(owned_, other.owned_);
    return *this;
  }
  SdlInit(const SdlInit&) = delete;
  SdlInit& operator=(const SdlInit&) = delete;

 private:
  explicit SdlInit(bool owned) : owned_(owned) {}
  bool owned_ = false;
};

// Owns an SDL_Surface.
class Surface {
 public:
  static Result<Surface> Create(int w, int h,
                                SDL_PixelFormat format = SDL_PIXELFORMAT_ARGB8888) {
    SDL_Surface* raw = SDL_CreateSurface(w, h, format);
    if (raw == nullptr) return Status::FromSdl();
    return Surface(raw);
  }

  ~Surface() { Destroy(); }
  Surface(Surface&& other) noexcept : surface_(std::exchange(other.surface_, nullptr)) {}
  Surface& operator=(Surface&& other) noexcept {
    if (this != &other) {
      Destroy();
      surface_ = std::exchange(other.surface_, nullptr);
    }
    return *this;
  }
  Surface(const Surface&) = delete;
  Surface& operator=(const Surface&) = delete;

  SDL_Surface* get() const { return surface_; }

 private:
  explicit Surface(SDL_Surface* surface) : surface_(surface) {}
  void Destroy() {
    if (surface_ != nullptr) SDL_DestroySurface(surface_);
    surface_ = nullptr;
  }
  SDL_Surface* surface_ = nullptr;
};

// Owns an SDL_Texture. Must not outlive the Renderer that created it.
class Texture {
 public:
  ~Texture() { Destroy(); }
  Texture(Texture&& other) noexcept
      : texture_(std::exchange(other.texture_, nullptr)), w_(other.w_), h_(other.h_) {}
  Texture& operator=(Texture&& other) noexcept {
    if (this != &other) {
      Destroy();
      texture_ = std::exchange(other.texture_, nullptr);
      w_ = other.w_;
      h_ = other.h_;
    }
    return *this;
  }
  Texture(const Texture&) = delete;
  Texture& operator=(const Texture&) = delete;

  float width() const { return w_; }
  float height() const { return h_; }
  SDL_Texture* get() const { return texture_; }

 private:
  friend class Renderer;
  Texture(SDL_Texture* texture, float w, float h) : texture_(texture), w_(w), h_(h) {}
  void Destroy() {
    if (texture_ != nullptr) SDL_DestroyTexture(texture_);
    texture_ = nullptr;
  }
  SDL_Texture* texture_ = nullptr;
  float w_ = 0;
  float h_ = 0;
};

// Owns an SDL_Renderer (software-on-surface for headless use).
class Renderer {
 public:
  // Headless renderer drawing into `target` (which must outlive it).
  static Result<Renderer> CreateSoftware(Surface& target) {
    SDL_Renderer* raw = SDL_CreateSoftwareRenderer(target.get());
    if (raw == nullptr) return Status::FromSdl();
    return Renderer(raw);
  }

  ~Renderer() { Destroy(); }
  Renderer(Renderer&& other) noexcept : renderer_(std::exchange(other.renderer_, nullptr)) {}
  Renderer& operator=(Renderer&& other) noexcept {
    if (this != &other) {
      Destroy();
      renderer_ = std::exchange(other.renderer_, nullptr);
    }
    return *this;
  }
  Renderer(const Renderer&) = delete;
  Renderer& operator=(const Renderer&) = delete;

  Status Clear(Uint8 r, Uint8 g, Uint8 b) {
    if (!SDL_SetRenderDrawColor(renderer_, r, g, b, 255) || !SDL_RenderClear(renderer_)) {
      return Status::FromSdl();
    }
    return Status::Ok();
  }
  Status Present() {
    if (!SDL_RenderPresent(renderer_)) return Status::FromSdl();
    return Status::Ok();
  }
  Status Flush() {
    if (!SDL_FlushRenderer(renderer_)) return Status::FromSdl();
    return Status::Ok();
  }

  // Loads an image through the VFS when the path exists there, else from
  // the real filesystem.
  Result<Texture> LoadTexture(const std::string& path) {
    SDL_Surface* surface = nullptr;
    if (PHYSFS_isInit() && PHYSFS_exists(path.c_str())) {
      SDL_IOStream* io = SDLStatic_OpenVFSRead(path.c_str());
      if (io != nullptr) surface = IMG_Load_IO(io, true);
    } else {
      surface = IMG_Load(path.c_str());
    }
    if (surface == nullptr) return Status::FromSdl();
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer_, surface);
    const float w = static_cast<float>(surface->w);
    const float h = static_cast<float>(surface->h);
    SDL_DestroySurface(surface);
    if (texture == nullptr) return Status::FromSdl();
    return Texture(texture, w, h);
  }

  Status Draw(const Texture& texture, float x, float y) {
    const SDL_FRect dst = {x, y, texture.width(), texture.height()};
    if (!SDL_RenderTexture(renderer_, texture.get(), nullptr, &dst)) return Status::FromSdl();
    return Status::Ok();
  }

  Status DebugText(float x, float y, const std::string& text) {
    if (!SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255) ||
        !SDL_RenderDebugText(renderer_, x, y, text.c_str())) {
      return Status::FromSdl();
    }
    return Status::Ok();
  }

  SDL_Renderer* get() const { return renderer_; }

 private:
  explicit Renderer(SDL_Renderer* renderer) : renderer_(renderer) {}
  void Destroy() {
    if (renderer_ != nullptr) SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
  }
  SDL_Renderer* renderer_ = nullptr;
};

// Owns a window + its renderer (created together, destroyed together).
class Window {
 public:
  static Result<Window> Create(const std::string& title, int w, int h,
                               SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE) {
    if (!SDL_WasInit(SDL_INIT_VIDEO) && !SDL_InitSubSystem(SDL_INIT_VIDEO)) {
      return Status::FromSdl();
    }
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    if (!SDL_CreateWindowAndRenderer(title.c_str(), w, h, flags, &window, &renderer)) {
      return Status::FromSdl();
    }
    return Window(window, renderer);
  }

  ~Window() { Destroy(); }
  Window(Window&& other) noexcept
      : window_(std::exchange(other.window_, nullptr)),
        renderer_(std::exchange(other.renderer_, nullptr)) {}
  Window& operator=(Window&& other) noexcept {
    if (this != &other) {
      Destroy();
      window_ = std::exchange(other.window_, nullptr);
      renderer_ = std::exchange(other.renderer_, nullptr);
    }
    return *this;
  }
  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  SDL_Window* window() const { return window_; }
  SDL_Renderer* renderer() const { return renderer_; }

 private:
  Window(SDL_Window* window, SDL_Renderer* renderer) : window_(window), renderer_(renderer) {}
  void Destroy() {
    if (renderer_ != nullptr) SDL_DestroyRenderer(renderer_);
    if (window_ != nullptr) SDL_DestroyWindow(window_);
    renderer_ = nullptr;
    window_ = nullptr;
  }
  SDL_Window* window_ = nullptr;
  SDL_Renderer* renderer_ = nullptr;
};

}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_APP_H_
