// game.h — RAII and type-safety over SDLStatic::Engine.
// Original SDLStatic code (zlib).
//
// Named game.h rather than engine.h on purpose. This header includes the C
// <SDLStatic/engine.h>, and macOS and Windows have case-insensitive
// filesystems: a C++ header at sdlstatic/engine.h shadows the C one and
// ends up including itself. Every other header here avoids the collision by
// accident (there is no C SDLStatic/physics.h); this is the first that
// would have hit it.
//
// The C API is already the real API; this is not a reimplementation of it.
// What C++ adds is the three things a C game has to remember by hand:
//
//   Lifetime.   The engine, the action map and every actor handle are
//               owned. Destruction happens in the right order because
//               that is what scope does.
//   Hooks.      Free functions with a void* become member functions or
//               lambdas, without every game writing the same trampoline
//               and the same static_cast.
//   Handles.    An actor id is a value type that knows which engine it
//               came from, so `actor.velocity()` is a method rather than
//               a three-argument call with an out-parameter.
//
// Everything here is a thin inline wrapper: no virtual dispatch, no
// allocation the C API would not have done, and the C handle is always
// reachable with `.get()` for anything not wrapped yet.
//
//     sdlstatic::Engine engine = sdlstatic::Engine::Create(config).value();
//
//     engine.on_fixed_update([&](float step) { player.Move(step); });
//     engine.on_render([&](float alpha) {
//         engine.render_world(camera, alpha);
//     });
//     engine.Run();

#ifndef SDLSTATIC_CPP_GAME_H_
#define SDLSTATIC_CPP_GAME_H_

#include <SDLStatic/engine.h>
#include <SDLStatic/engine_actor.h>
#include <SDLStatic/engine_assets.h>
#include <SDLStatic/engine_binding.h>
#include <SDLStatic/engine_camera.h>
#include <SDLStatic/engine_graphics.h>
#include <SDLStatic/engine_input.h>
#include <SDLStatic/engine_light.h>
#include <SDLStatic/engine_physics.h>
#include <SDLStatic/engine_render.h>
#include <SDLStatic/engine_save.h>
#include <SDLStatic/engine_scene.h>
#include <SDLStatic/engine_text.h>

#include <functional>
#include <string>
#include <utility>
#include <vector>

#include "sdlstatic/status.h"

namespace sdlstatic {

class Engine;

// A live actor, as a value. Copyable and cheap: it is an engine pointer and
// a 48-bit handle, and it stops resolving when the actor dies — so holding
// one past its lifetime is safe in exactly the way holding a pointer is
// not.
class Actor {
 public:
  Actor() = default;
  Actor(SDLStatic_Engine* engine, SDLStatic_ActorId id) : engine_(engine), id_(id) {}

  SDLStatic_ActorId id() const { return id_; }
  bool alive() const { return SDLStatic_ActorAlive(engine_, id_); }
  explicit operator bool() const { return alive(); }

  // The raw actor, or nullptr. Everything below goes through this, so an
  // operation on a dead actor is a no-op rather than a crash.
  SDLStatic_Actor* get() const { return SDLStatic_ActorGet(engine_, id_); }

  const char* type() const { return SDLStatic_ActorType(get()); }
  const char* name() const { return SDLStatic_ActorName(get()); }

  template <typename T>
  T* state() const {
    return static_cast<T*>(SDLStatic_ActorState(get()));
  }

  void destroy() const { SDLStatic_ActorDestroy(engine_, id_); }

  // --- transform ---
  SDLStatic_ActorTransform local() const { return SDLStatic_ActorLocal(get()); }
  SDLStatic_ActorTransform world() const { return SDLStatic_ActorWorld(get()); }
  SDLStatic_ActorTransform render_transform(float alpha) const {
    return SDLStatic_ActorRenderTransform(get(), alpha);
  }
  void set_position(float x, float y) const { SDLStatic_ActorSetPosition(get(), x, y); }
  void move(float dx, float dy) const { SDLStatic_ActorMove(get(), dx, dy); }
  void teleport(float x, float y) const { SDLStatic_ActorTeleport(get(), x, y); }

  // --- hierarchy ---
  bool set_parent(Actor parent) const {
    return SDLStatic_ActorSetParent(get(), parent.id());
  }
  Actor parent() const { return Actor(engine_, SDLStatic_ActorParent(get())); }
  int child_count() const { return SDLStatic_ActorChildCount(get()); }
  Actor child(int index) const { return Actor(engine_, SDLStatic_ActorChild(get(), index)); }

  // --- tags and state ---
  SDLStatic_ActorTags tags() const { return SDLStatic_ActorGetTags(get()); }
  void set_tags(SDLStatic_ActorTags value) const { SDLStatic_ActorSetTags(get(), value); }
  bool has_tags(SDLStatic_ActorTags any) const { return SDLStatic_ActorHasTags(get(), any); }
  bool enabled() const { return SDLStatic_ActorEnabled(get()); }
  void set_enabled(bool value) const { SDLStatic_ActorSetEnabled(get(), value); }

  // --- sprite ---
  bool set_sprite(const SDLStatic_Sprite& sprite) const {
    return SDLStatic_ActorSetSprite(get(), &sprite);
  }
  SDLStatic_Sprite* sprite() const { return SDLStatic_ActorSprite(get()); }
  void clear_sprite() const { SDLStatic_ActorClearSprite(get()); }

  // --- light ---
  bool set_light(const SDLStatic_LightDef& light) const {
    return SDLStatic_ActorAddLight(get(), &light);
  }
  SDLStatic_LightDef* light() const { return SDLStatic_ActorLight(get()); }
  void clear_light() const { SDLStatic_ActorRemoveLight(get()); }

  // --- physics ---
  bool set_body(const SDLStatic_BodyDef& body) const {
    return SDLStatic_ActorAddBody(get(), &body);
  }
  bool has_body() const { return SDLStatic_ActorHasBody(get()); }
  void remove_body() const { SDLStatic_ActorRemoveBody(get()); }
  void set_velocity(float x, float y) const { SDLStatic_ActorSetVelocity(get(), x, y); }
  std::pair<float, float> velocity() const {
    float x = 0.0f;
    float y = 0.0f;
    SDLStatic_ActorVelocity(get(), &x, &y);
    return {x, y};
  }
  void apply_impulse(float x, float y) const { SDLStatic_ActorApplyImpulse(get(), x, y); }
  void apply_force(float x, float y) const { SDLStatic_ActorApplyForce(get(), x, y); }

  // --- messages ---
  bool send(const SDLStatic_ActorMessage& message) const {
    return SDLStatic_ActorSend(engine_, id_, &message);
  }

  friend bool operator==(const Actor& a, const Actor& b) { return a.id_ == b.id_; }
  friend bool operator!=(const Actor& a, const Actor& b) { return !(a == b); }

 private:
  SDLStatic_Engine* engine_ = nullptr;
  SDLStatic_ActorId id_ = SDLSTATIC_ACTOR_NONE;
};

// An action map, owned. Bindings read the same as in C, but the map cannot
// be leaked or double-freed.
class ActionMap {
 public:
  static Result<ActionMap> Create() {
    SDLStatic_ActionMap* map = SDLStatic_ActionMapCreate();
    if (map == nullptr) return Status::Error("SDLStatic_ActionMapCreate failed");
    return ActionMap(map);
  }

  ActionMap() = default;
  ~ActionMap() { reset(); }
  ActionMap(ActionMap&& other) noexcept : map_(std::exchange(other.map_, nullptr)) {}
  ActionMap& operator=(ActionMap&& other) noexcept {
    if (this != &other) {
      reset();
      map_ = std::exchange(other.map_, nullptr);
    }
    return *this;
  }
  ActionMap(const ActionMap&) = delete;
  ActionMap& operator=(const ActionMap&) = delete;

  SDLStatic_ActionMap* get() const { return map_; }

  bool bind_key(const std::string& action, SDL_Scancode key, int sign = 1) const {
    return SDLStatic_ActionBindKeySigned(map_, action.c_str(), key, sign);
  }
  bool bind_pad(const std::string& action, SDLStatic_GamepadButton button) const {
    return SDLStatic_ActionBindPad(map_, action.c_str(), button);
  }
  bool bind_axis(const std::string& action, SDLStatic_GamepadAxis axis, int half = 0) const {
    return SDLStatic_ActionBindAxis(map_, action.c_str(), axis, half);
  }
  bool bind_mouse(const std::string& action, SDLStatic_MouseButton button) const {
    return SDLStatic_ActionBindMouse(map_, action.c_str(), button);
  }
  void clear(const std::string& action) const { SDLStatic_ActionClear(map_, action.c_str()); }

  void set_keyboard_player(int player) const {
    SDLStatic_ActionMapSetKeyboardPlayer(map_, player);
  }

  bool save(const std::string& org, const std::string& app) const {
    return SDLStatic_ActionMapSave(map_, org.c_str(), app.c_str());
  }
  bool load(const std::string& org, const std::string& app) const {
    return SDLStatic_ActionMapLoad(map_, org.c_str(), app.c_str());
  }

 private:
  explicit ActionMap(SDLStatic_ActionMap* map) : map_(map) {}
  void reset() {
    if (map_ != nullptr) SDLStatic_ActionMapDestroy(std::exchange(map_, nullptr));
  }
  SDLStatic_ActionMap* map_ = nullptr;
};

// The engine, owned.
//
// Hooks are std::function, so a lambda capturing the game's state works
// without the game writing a trampoline and a static_cast for each one.
// The C hooks struct lives inside this object and points back at it, which
// is why Engine is non-movable: a moved engine would leave the C side
// pointing at the old address, and it would keep working right up until it
// did not.
class Engine {
 public:
  static Result<Engine> Create(const SDLStatic_EngineConfig& config) {
    SDLStatic_Engine* engine = SDLStatic_CreateEngine(&config);
    if (engine == nullptr) return Status::FromSdl();
    return Result<Engine>(Engine(engine));
  }

  static Result<Engine> Create() {
    SDLStatic_EngineConfig config{};
    return Create(config);
  }

  ~Engine() { reset(); }
  Engine(Engine&& other) noexcept
      : engine_(std::exchange(other.engine_, nullptr)),
        load_(std::move(other.load_)),
        fixed_update_(std::move(other.fixed_update_)),
        update_(std::move(other.update_)),
        render_(std::move(other.render_)),
        post_render_(std::move(other.post_render_)),
        event_(std::move(other.event_)),
        unload_(std::move(other.unload_)) {
    // The C side holds a pointer to the hooks struct and a user pointer;
    // both have just moved, so they are re-published against this object.
    Publish();
  }
  Engine& operator=(Engine&& other) noexcept {
    if (this != &other) {
      reset();
      engine_ = std::exchange(other.engine_, nullptr);
      fixed_update_ = std::move(other.fixed_update_);
      update_ = std::move(other.update_);
      render_ = std::move(other.render_);
      post_render_ = std::move(other.post_render_);
      event_ = std::move(other.event_);
      load_ = std::move(other.load_);
      unload_ = std::move(other.unload_);
      Publish();
    }
    return *this;
  }
  Engine(const Engine&) = delete;
  Engine& operator=(const Engine&) = delete;

  SDLStatic_Engine* get() const { return engine_; }
  explicit operator bool() const { return engine_ != nullptr; }

  // --- hooks ---
  void on_load(std::function<bool()> fn) { load_ = std::move(fn); Publish(); }
  void on_fixed_update(std::function<void(float)> fn) { fixed_update_ = std::move(fn); Publish(); }
  void on_update(std::function<void(float)> fn) { update_ = std::move(fn); Publish(); }
  void on_render(std::function<void(float)> fn) { render_ = std::move(fn); Publish(); }
  void on_post_render(std::function<void()> fn) { post_render_ = std::move(fn); Publish(); }
  void on_event(std::function<void(const SDL_Event&)> fn) { event_ = std::move(fn); Publish(); }
  void on_unload(std::function<void()> fn) { unload_ = std::move(fn); Publish(); }

  bool Run() {
    Publish();
    return SDLStatic_RunGame(engine_, &hooks_, this);
  }
  bool Tick() {
    Publish();
    return SDLStatic_EngineTick(engine_);
  }
  void Quit() const { SDLStatic_EngineQuit(engine_); }
  void Advance(Uint64 nanoseconds) const { SDLStatic_EngineAdvance(engine_, nanoseconds); }

  SDL_Renderer* renderer() const { return SDLStatic_EngineRenderer(engine_); }
  SDL_Window* window() const { return SDLStatic_EngineWindow(engine_); }
  float fps() const { return SDLStatic_EngineFps(engine_); }
  Uint64 frame_count() const { return SDLStatic_EngineFrameCount(engine_); }

  // --- actors ---
  Actor spawn(const SDLStatic_ActorDef& def) const {
    return Actor(engine_, SDLStatic_ActorSpawn(engine_, &def));
  }
  Actor find_by_type(const std::string& type) const {
    return Actor(engine_, SDLStatic_ActorFindByType(engine_, type.c_str()));
  }
  Actor find_by_name(const std::string& name) const {
    return Actor(engine_, SDLStatic_ActorFindByName(engine_, name.c_str()));
  }
  int actor_count() const { return SDLStatic_ActorCount(engine_); }

  // A vector rather than a caller's array: at the C++ layer the allocation
  // is the lesser evil, and a game that needs the zero-allocation version
  // still has SDLStatic_ActorQuery.
  std::vector<Actor> query(const char* type = nullptr, SDLStatic_ActorTags tags = 0,
                           int limit = 256) const {
    std::vector<SDLStatic_ActorId> ids(static_cast<size_t>(limit));
    const int found = SDLStatic_ActorQuery(engine_, type, tags, ids.data(), limit);
    std::vector<Actor> actors;
    actors.reserve(static_cast<size_t>(found));
    for (int i = 0; i < found; ++i) actors.emplace_back(engine_, ids[static_cast<size_t>(i)]);
    return actors;
  }

  // --- rendering ---
  int render_world(const SDLStatic_Camera& camera, float alpha) const {
    return SDLStatic_RenderWorld(engine_, &camera, alpha);
  }
  int render_overlay(float alpha) const { return SDLStatic_RenderOverlay(engine_, alpha); }

  // --- input ---
  bool key_down(SDL_Scancode key) const { return SDLStatic_KeyDown(engine_, key); }
  bool key_pressed(SDL_Scancode key) const { return SDLStatic_KeyPressed(engine_, key); }
  bool action_down(const ActionMap& map, int player, const std::string& action) const {
    return SDLStatic_ActionDown(engine_, map.get(), player, action.c_str());
  }
  bool action_pressed(const ActionMap& map, int player, const std::string& action) const {
    return SDLStatic_ActionPressed(engine_, map.get(), player, action.c_str());
  }
  float action_value(const ActionMap& map, int player, const std::string& action) const {
    return SDLStatic_ActionValue(engine_, map.get(), player, action.c_str());
  }

  // --- assets ---
  SDLStatic_TextureId load_texture(const std::string& path) const {
    return SDLStatic_LoadTexture(engine_, path.c_str());
  }
  SDLStatic_TextureId load_texture_async(const std::string& path) const {
    return SDLStatic_LoadTextureAsync(engine_, path.c_str());
  }
  SDL_Texture* texture(SDLStatic_TextureId id) const {
    return SDLStatic_Texture(engine_, id);
  }
  float assets_progress() const { return SDLStatic_AssetsProgress(engine_); }
  bool assets_ready() const { return SDLStatic_AssetsReady(engine_); }

  // --- lighting ---
  void set_light_preset(SDLStatic_LightPreset preset) const {
    SDLStatic_LightSetPreset(engine_, preset);
  }
  bool render_lighting(const SDLStatic_Camera& camera, float alpha) const {
    return SDLStatic_LightRender(engine_, &camera, alpha);
  }

  // --- saves ---
  void set_save_identity(const std::string& org, const std::string& app) const {
    SDLStatic_SaveSetIdentity(engine_, org.c_str(), app.c_str());
  }
  bool save(int slot, const void* data, size_t size, const std::string& label = "") const {
    return SDLStatic_SaveWrite(engine_, slot, data, size, label.c_str());
  }
  // The buffer is returned owned, so a caller cannot forget to free it.
  std::vector<unsigned char> load(int slot) const {
    size_t size = 0;
    void* data = SDLStatic_SaveRead(engine_, slot, &size);
    if (data == nullptr) return {};
    std::vector<unsigned char> bytes(static_cast<const unsigned char*>(data),
                                     static_cast<const unsigned char*>(data) + size);
    SDL_free(data);
    return bytes;
  }

  // --- text ---
  const char* text(const std::string& key) const {
    return SDLStatic_Text(engine_, key.c_str());
  }
  void set_language(const std::string& language) const {
    SDLStatic_TextSetLanguage(engine_, language.c_str());
  }

 private:
  explicit Engine(SDLStatic_Engine* engine) : engine_(engine) {}

  void reset() {
    if (engine_ != nullptr) SDLStatic_DestroyEngine(std::exchange(engine_, nullptr));
  }

  // Publish the hooks the game has actually set. A null C function pointer
  // means "no hook", so an unset std::function costs nothing per frame
  // rather than an empty call through a trampoline.
  void Publish() {
    hooks_ = SDLStatic_GameHooks{};
    if (load_) hooks_.load = &OnLoad;
    if (fixed_update_) hooks_.fixed_update = &OnFixedUpdate;
    if (update_) hooks_.update = &OnUpdate;
    if (render_) hooks_.render = &OnRender;
    if (post_render_) hooks_.post_render = &OnPostRender;
    if (event_) hooks_.event = &OnEvent;
    if (unload_) hooks_.unload = &OnUnload;
    if (engine_ != nullptr) SDLStatic_EngineSetHooks(engine_, &hooks_, this);
  }

  static Engine* Self(void* user) { return static_cast<Engine*>(user); }
  static bool OnLoad(void* user) { return Self(user)->load_(); }
  static void OnFixedUpdate(void* user, float step) { Self(user)->fixed_update_(step); }
  static void OnUpdate(void* user, float dt) { Self(user)->update_(dt); }
  static void OnRender(void* user, float alpha) { Self(user)->render_(alpha); }
  static void OnPostRender(void* user) { Self(user)->post_render_(); }
  static void OnEvent(void* user, const SDL_Event* event) { Self(user)->event_(*event); }
  static void OnUnload(void* user) { Self(user)->unload_(); }

  SDLStatic_Engine* engine_ = nullptr;
  SDLStatic_GameHooks hooks_{};
  std::function<bool()> load_;
  std::function<void(float)> fixed_update_;
  std::function<void(float)> update_;
  std::function<void(float)> render_;
  std::function<void()> post_render_;
  std::function<void(const SDL_Event&)> event_;
  std::function<void()> unload_;
};

}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GAME_H_
