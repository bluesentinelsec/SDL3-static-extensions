// ui.h — RAII over the Nuklear SDL3 backend.
// Original SDLStatic code (zlib). The full immediate-mode nk_* API stays
// available through context(); this wrapper owns setup/teardown and the
// per-frame input/render calls.

#ifndef SDLSTATIC_CPP_UI_H_
#define SDLSTATIC_CPP_UI_H_

#include <SDLStatic/gui.h>

#include <utility>

#include "sdlstatic/status.h"

namespace sdlstatic {

class Gui {
 public:
  static Result<Gui> Create(SDL_Renderer* renderer, float font_size = 0.0f) {
    SDLStatic_Gui* raw = SDLStatic_CreateGui(renderer, nullptr, 0, font_size);
    if (raw == nullptr) return Status::FromSdl();
    return Gui(raw);
  }

  ~Gui() { Destroy(); }
  Gui(Gui&& other) noexcept : gui_(std::exchange(other.gui_, nullptr)) {}
  Gui& operator=(Gui&& other) noexcept {
    if (this != &other) {
      Destroy();
      gui_ = std::exchange(other.gui_, nullptr);
    }
    return *this;
  }
  Gui(const Gui&) = delete;
  Gui& operator=(const Gui&) = delete;

  void InputBegin() { SDLStatic_GuiInputBegin(gui_); }
  bool ProcessEvent(const SDL_Event& event) { return SDLStatic_GuiProcessEvent(gui_, &event); }
  void InputEnd() { SDLStatic_GuiInputEnd(gui_); }
  bool wants_input() const { return SDLStatic_GuiWantsInput(gui_); }

  Status Render() {
    if (!SDLStatic_GuiRender(gui_)) return Status::FromSdl();
    return Status::Ok();
  }

  struct nk_context* context() const { return SDLStatic_GuiContext(gui_); }
  SDLStatic_Gui* get() const { return gui_; }

 private:
  explicit Gui(SDLStatic_Gui* gui) : gui_(gui) {}
  void Destroy() {
    if (gui_ != nullptr) SDLStatic_DestroyGui(gui_);
    gui_ = nullptr;
  }
  SDLStatic_Gui* gui_ = nullptr;
};

}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_UI_H_
