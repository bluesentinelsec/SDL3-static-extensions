// physics.h — RAII over Box2D v3 worlds/bodies.
// Original SDLStatic code (zlib). Bodies are lightweight ids owned by their
// world; Body is a validity-checked view whose calls fail with a Status
// (never crash) once the world is gone — matching Box2D's own id model.

#ifndef SDLSTATIC_CPP_PHYSICS_H_
#define SDLSTATIC_CPP_PHYSICS_H_

#include <box2d/box2d.h>

#include <utility>

#include "sdlstatic/status.h"

namespace sdlstatic {

struct Vec2 {
  float x = 0;
  float y = 0;
};

class Body {
 public:
  bool valid() const { return b2Body_IsValid(id_); }

  Result<Vec2> Position() const {
    if (!valid()) return Status::Error("body's world was destroyed");
    const b2Vec2 p = b2Body_GetPosition(id_);
    return Vec2{p.x, p.y};
  }
  Result<float> Angle() const {
    if (!valid()) return Status::Error("body's world was destroyed");
    return b2Rot_GetAngle(b2Body_GetRotation(id_));
  }
  Status SetVelocity(Vec2 v) {
    if (!valid()) return Status::Error("body's world was destroyed");
    b2Body_SetLinearVelocity(id_, b2Vec2{v.x, v.y});
    return Status::Ok();
  }
  Status ApplyImpulse(Vec2 impulse) {
    if (!valid()) return Status::Error("body's world was destroyed");
    b2Body_ApplyLinearImpulseToCenter(id_, b2Vec2{impulse.x, impulse.y}, true);
    return Status::Ok();
  }
  b2BodyId id() const { return id_; }

 private:
  friend class World;
  explicit Body(b2BodyId id) : id_(id) {}
  b2BodyId id_;
};

// Owns a b2World; destroys it (and every body in it) on destruction.
class World {
 public:
  static Result<World> Create(Vec2 gravity = {0.0f, -10.0f}) {
    b2WorldDef def = b2DefaultWorldDef();
    def.gravity = b2Vec2{gravity.x, gravity.y};
    const b2WorldId id = b2CreateWorld(&def);
    if (!b2World_IsValid(id)) return Status::Error("b2CreateWorld failed");
    return World(id);
  }

  ~World() { Destroy(); }
  World(World&& other) noexcept : id_(std::exchange(other.id_, b2_nullWorldId)) {}
  World& operator=(World&& other) noexcept {
    if (this != &other) {
      Destroy();
      id_ = std::exchange(other.id_, b2_nullWorldId);
    }
    return *this;
  }
  World(const World&) = delete;
  World& operator=(const World&) = delete;

  Status Step(float dt = 1.0f / 60.0f, int substeps = 4) {
    if (!b2World_IsValid(id_)) return Status::Error("world destroyed");
    b2World_Step(id_, dt, substeps);
    return Status::Ok();
  }

  Result<Body> AddBox(Vec2 center, float half_w, float half_h, bool dynamic) {
    Result<Body> body = AddBody(center, dynamic);
    if (!body.ok()) return body;
    const b2Polygon poly = b2MakeBox(half_w, half_h);
    b2ShapeDef shape = b2DefaultShapeDef();
    b2CreatePolygonShape(body->id(), &shape, &poly);
    return body;
  }
  Result<Body> AddCircle(Vec2 center, float radius, bool dynamic) {
    Result<Body> body = AddBody(center, dynamic);
    if (!body.ok()) return body;
    const b2Circle circle = {{0.0f, 0.0f}, radius};
    b2ShapeDef shape = b2DefaultShapeDef();
    b2CreateCircleShape(body->id(), &shape, &circle);
    return body;
  }

  b2WorldId id() const { return id_; }

 private:
  explicit World(b2WorldId id) : id_(id) {}
  Result<Body> AddBody(Vec2 center, bool dynamic) {
    if (!b2World_IsValid(id_)) return Status::Error("world destroyed");
    b2BodyDef def = b2DefaultBodyDef();
    def.type = dynamic ? b2_dynamicBody : b2_staticBody;
    def.position = b2Vec2{center.x, center.y};
    return Body(b2CreateBody(id_, &def));
  }
  void Destroy() {
    if (b2World_IsValid(id_)) b2DestroyWorld(id_);
    id_ = b2_nullWorldId;
  }
  b2WorldId id_ = b2_nullWorldId;
};

}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_PHYSICS_H_
