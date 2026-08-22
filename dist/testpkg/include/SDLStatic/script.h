// script.h — RAII over the Lua and Ruby interpreter states.
// Original SDLStatic code (zlib).

#ifndef SDLSTATIC_CPP_SCRIPT_H_
#define SDLSTATIC_CPP_SCRIPT_H_

#include <SDLStatic/lua.h>
#include <SDLStatic/ruby.h>

#include <mruby/compile.h>
#include <mruby/string.h>

#include <string>
#include <utility>

#include "sdlstatic/status.h"

namespace sdlstatic {

// Owns a lua_State with the stdlibs + VFS-aware require installed.
class LuaState {
 public:
  static Result<LuaState> Create() {
    lua_State* raw = SDLStatic_CreateLuaState();
    if (raw == nullptr) return Status::FromSdl();
    return LuaState(raw);
  }

  ~LuaState() { Destroy(); }
  LuaState(LuaState&& other) noexcept : state_(std::exchange(other.state_, nullptr)) {}
  LuaState& operator=(LuaState&& other) noexcept {
    if (this != &other) {
      Destroy();
      state_ = std::exchange(other.state_, nullptr);
    }
    return *this;
  }
  LuaState(const LuaState&) = delete;
  LuaState& operator=(const LuaState&) = delete;

  Status Run(const std::string& code) {
    if (luaL_loadstring(state_, code.c_str()) != LUA_OK ||
        lua_pcall(state_, 0, LUA_MULTRET, 0) != LUA_OK) {
      Status status = Status::Error(lua_tostring(state_, -1));
      lua_pop(state_, 1);
      return status;
    }
    return Status::Ok();
  }

  lua_State* get() const { return state_; }

 private:
  explicit LuaState(lua_State* state) : state_(state) {}
  void Destroy() {
    if (state_ != nullptr) lua_close(state_);
    state_ = nullptr;
  }
  lua_State* state_ = nullptr;
};

// Owns an mrb_state with require/puts installed.
class RubyState {
 public:
  static Result<RubyState> Create() {
    mrb_state* raw = SDLStatic_CreateRubyState();
    if (raw == nullptr) return Status::FromSdl();
    return RubyState(raw);
  }

  ~RubyState() { Destroy(); }
  RubyState(RubyState&& other) noexcept : state_(std::exchange(other.state_, nullptr)) {}
  RubyState& operator=(RubyState&& other) noexcept {
    if (this != &other) {
      Destroy();
      state_ = std::exchange(other.state_, nullptr);
    }
    return *this;
  }
  RubyState(const RubyState&) = delete;
  RubyState& operator=(const RubyState&) = delete;

  Status AddLoadPath(const std::string& path) {
    if (!SDLStatic_RubyAddLoadPath(state_, path.c_str())) return Status::FromSdl();
    return Status::Ok();
  }

  Status Run(const std::string& code) {
    mrb_load_string(state_, code.c_str());
    if (state_->exc != nullptr) {
      mrb_value msg = mrb_inspect(state_, mrb_obj_value(state_->exc));
      state_->exc = nullptr;
      return Status::Error(RSTRING_CSTR(state_, msg));
    }
    return Status::Ok();
  }

  mrb_state* get() const { return state_; }

 private:
  explicit RubyState(mrb_state* state) : state_(state) {}
  void Destroy() {
    if (state_ != nullptr) mrb_close(state_);
    state_ = nullptr;
  }
  mrb_state* state_ = nullptr;
};

}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_SCRIPT_H_
