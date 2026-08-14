// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: Box2D
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_B2_H_
#define SDLSTATIC_CPP_GEN_B2_H_

#include <box2d/box2d.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace b2 {

// RAII owner for b2WorldId (destroyed with b2DestroyWorld).
class PhysicsWorld {
 public:
  static Result<PhysicsWorld> CreateWorld(const b2WorldDef* def) {
    b2WorldId created_ = ::b2CreateWorld(def);
    if (!b2World_IsValid(created_)) {
      return Status::Error("b2CreateWorld failed");
    }
    return PhysicsWorld(created_);
  }

  PhysicsWorld() = default;
  ~PhysicsWorld() { reset(); }
  PhysicsWorld(PhysicsWorld&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = {};
    other.engaged_ = false;
  }
  PhysicsWorld& operator=(PhysicsWorld&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = {};
      other.engaged_ = false;
    }
    return *this;
  }
  PhysicsWorld(const PhysicsWorld&) = delete;
  PhysicsWorld& operator=(const PhysicsWorld&) = delete;

  b2WorldId get() const { return value_; }
  b2WorldId release() {
    b2WorldId out = value_;
    value_ = {};
    engaged_ = false;
    return out;
  }
  void reset() {
    if (engaged_) ::b2DestroyWorld(value_);
    value_ = {};
    engaged_ = false;
  }

  bool World_IsValid() {
    return ::b2World_IsValid(value_);
  }
  void World_Step(float timeStep, int subStepCount) { ::b2World_Step(value_, timeStep, subStepCount); }
  void World_Draw(b2DebugDraw* draw) { ::b2World_Draw(value_, draw); }
  b2BodyEvents World_GetBodyEvents() {
    return ::b2World_GetBodyEvents(value_);
  }
  b2SensorEvents World_GetSensorEvents() {
    return ::b2World_GetSensorEvents(value_);
  }
  b2ContactEvents World_GetContactEvents() {
    return ::b2World_GetContactEvents(value_);
  }
  b2TreeStats World_OverlapAABB(b2AABB aabb, b2QueryFilter filter, b2OverlapResultFcn* fcn, void* context) {
    return ::b2World_OverlapAABB(value_, aabb, filter, fcn, context);
  }
  b2TreeStats World_OverlapShape(const b2ShapeProxy* proxy, b2QueryFilter filter, b2OverlapResultFcn* fcn, void* context) {
    return ::b2World_OverlapShape(value_, proxy, filter, fcn, context);
  }
  b2TreeStats World_CastRay(b2Vec2 origin, b2Vec2 translation, b2QueryFilter filter, b2CastResultFcn* fcn, void* context) {
    return ::b2World_CastRay(value_, origin, translation, filter, fcn, context);
  }
  b2RayResult World_CastRayClosest(b2Vec2 origin, b2Vec2 translation, b2QueryFilter filter) {
    return ::b2World_CastRayClosest(value_, origin, translation, filter);
  }
  b2TreeStats World_CastShape(const b2ShapeProxy* proxy, b2Vec2 translation, b2QueryFilter filter, b2CastResultFcn* fcn, void* context) {
    return ::b2World_CastShape(value_, proxy, translation, filter, fcn, context);
  }
  float World_CastMover(const b2Capsule* mover, b2Vec2 translation, b2QueryFilter filter) {
    return ::b2World_CastMover(value_, mover, translation, filter);
  }
  void World_CollideMover(const b2Capsule* mover, b2QueryFilter filter, b2PlaneResultFcn* fcn, void* context) { ::b2World_CollideMover(value_, mover, filter, fcn, context); }
  void World_EnableSleeping(bool flag) { ::b2World_EnableSleeping(value_, flag); }
  bool World_IsSleepingEnabled() {
    return ::b2World_IsSleepingEnabled(value_);
  }
  void World_EnableContinuous(bool flag) { ::b2World_EnableContinuous(value_, flag); }
  bool World_IsContinuousEnabled() {
    return ::b2World_IsContinuousEnabled(value_);
  }
  void World_SetRestitutionThreshold(float value) { ::b2World_SetRestitutionThreshold(value_, value); }
  float World_GetRestitutionThreshold() {
    return ::b2World_GetRestitutionThreshold(value_);
  }
  void World_SetHitEventThreshold(float value) { ::b2World_SetHitEventThreshold(value_, value); }
  float World_GetHitEventThreshold() {
    return ::b2World_GetHitEventThreshold(value_);
  }
  void World_SetCustomFilterCallback(b2CustomFilterFcn* fcn, void* context) { ::b2World_SetCustomFilterCallback(value_, fcn, context); }
  void World_SetPreSolveCallback(b2PreSolveFcn* fcn, void* context) { ::b2World_SetPreSolveCallback(value_, fcn, context); }
  void World_SetGravity(b2Vec2 gravity) { ::b2World_SetGravity(value_, gravity); }
  b2Vec2 World_GetGravity() {
    return ::b2World_GetGravity(value_);
  }
  void World_Explode(const b2ExplosionDef* explosionDef) { ::b2World_Explode(value_, explosionDef); }
  void World_SetContactTuning(float hertz, float dampingRatio, float pushSpeed) { ::b2World_SetContactTuning(value_, hertz, dampingRatio, pushSpeed); }
  void World_SetMaximumLinearSpeed(float maximumLinearSpeed) { ::b2World_SetMaximumLinearSpeed(value_, maximumLinearSpeed); }
  float World_GetMaximumLinearSpeed() {
    return ::b2World_GetMaximumLinearSpeed(value_);
  }
  void World_EnableWarmStarting(bool flag) { ::b2World_EnableWarmStarting(value_, flag); }
  bool World_IsWarmStartingEnabled() {
    return ::b2World_IsWarmStartingEnabled(value_);
  }
  int World_GetAwakeBodyCount() {
    return ::b2World_GetAwakeBodyCount(value_);
  }
  b2Profile World_GetProfile() {
    return ::b2World_GetProfile(value_);
  }
  b2Counters World_GetCounters() {
    return ::b2World_GetCounters(value_);
  }
  void World_SetUserData(void* userData) { ::b2World_SetUserData(value_, userData); }
  void* World_GetUserData() {
    return ::b2World_GetUserData(value_);
  }
  void World_SetFrictionCallback(b2FrictionCallback* callback) { ::b2World_SetFrictionCallback(value_, callback); }
  void World_SetRestitutionCallback(b2RestitutionCallback* callback) { ::b2World_SetRestitutionCallback(value_, callback); }
  void World_DumpMemoryStats() { ::b2World_DumpMemoryStats(value_); }
  void World_RebuildStaticTree() { ::b2World_RebuildStaticTree(value_); }
  void World_EnableSpeculative(bool flag) { ::b2World_EnableSpeculative(value_, flag); }
  b2JointId CreateDistanceJoint(const b2DistanceJointDef* def) {
    return ::b2CreateDistanceJoint(value_, def);
  }
  b2JointId CreateMotorJoint(const b2MotorJointDef* def) {
    return ::b2CreateMotorJoint(value_, def);
  }
  b2JointId CreateMouseJoint(const b2MouseJointDef* def) {
    return ::b2CreateMouseJoint(value_, def);
  }
  b2JointId CreateFilterJoint(const b2FilterJointDef* def) {
    return ::b2CreateFilterJoint(value_, def);
  }
  b2JointId CreatePrismaticJoint(const b2PrismaticJointDef* def) {
    return ::b2CreatePrismaticJoint(value_, def);
  }
  b2JointId CreateRevoluteJoint(const b2RevoluteJointDef* def) {
    return ::b2CreateRevoluteJoint(value_, def);
  }
  b2JointId CreateWeldJoint(const b2WeldJointDef* def) {
    return ::b2CreateWeldJoint(value_, def);
  }
  b2JointId CreateWheelJoint(const b2WheelJointDef* def) {
    return ::b2CreateWheelJoint(value_, def);
  }
 private:
  explicit PhysicsWorld(b2WorldId value) : value_(value), engaged_(true) {}
  b2WorldId value_{};
  bool engaged_ = false;
};

// RAII owner for b2BodyId (destroyed with b2DestroyBody).
class PhysicsBody {
 public:
  static Result<PhysicsBody> CreateBody(b2WorldId worldId, const b2BodyDef* def) {
    b2BodyId created_ = ::b2CreateBody(worldId, def);
    if (!b2Body_IsValid(created_)) {
      return Status::Error("b2CreateBody failed");
    }
    return PhysicsBody(created_);
  }

  PhysicsBody() = default;
  ~PhysicsBody() { reset(); }
  PhysicsBody(PhysicsBody&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = {};
    other.engaged_ = false;
  }
  PhysicsBody& operator=(PhysicsBody&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = {};
      other.engaged_ = false;
    }
    return *this;
  }
  PhysicsBody(const PhysicsBody&) = delete;
  PhysicsBody& operator=(const PhysicsBody&) = delete;

  b2BodyId get() const { return value_; }
  b2BodyId release() {
    b2BodyId out = value_;
    value_ = {};
    engaged_ = false;
    return out;
  }
  void reset() {
    if (engaged_) ::b2DestroyBody(value_);
    value_ = {};
    engaged_ = false;
  }

  bool Body_IsValid() {
    return ::b2Body_IsValid(value_);
  }
  b2BodyType Body_GetType() {
    return ::b2Body_GetType(value_);
  }
  void Body_SetType(b2BodyType type) { ::b2Body_SetType(value_, type); }
  void Body_SetName(const char* name) { ::b2Body_SetName(value_, name); }
  const char* Body_GetName() {
    return ::b2Body_GetName(value_);
  }
  void Body_SetUserData(void* userData) { ::b2Body_SetUserData(value_, userData); }
  void* Body_GetUserData() {
    return ::b2Body_GetUserData(value_);
  }
  b2Vec2 Body_GetPosition() {
    return ::b2Body_GetPosition(value_);
  }
  b2Rot Body_GetRotation() {
    return ::b2Body_GetRotation(value_);
  }
  b2Transform Body_GetTransform() {
    return ::b2Body_GetTransform(value_);
  }
  void Body_SetTransform(b2Vec2 position, b2Rot rotation) { ::b2Body_SetTransform(value_, position, rotation); }
  b2Vec2 Body_GetLocalPoint(b2Vec2 worldPoint) {
    return ::b2Body_GetLocalPoint(value_, worldPoint);
  }
  b2Vec2 Body_GetWorldPoint(b2Vec2 localPoint) {
    return ::b2Body_GetWorldPoint(value_, localPoint);
  }
  b2Vec2 Body_GetLocalVector(b2Vec2 worldVector) {
    return ::b2Body_GetLocalVector(value_, worldVector);
  }
  b2Vec2 Body_GetWorldVector(b2Vec2 localVector) {
    return ::b2Body_GetWorldVector(value_, localVector);
  }
  b2Vec2 Body_GetLinearVelocity() {
    return ::b2Body_GetLinearVelocity(value_);
  }
  float Body_GetAngularVelocity() {
    return ::b2Body_GetAngularVelocity(value_);
  }
  void Body_SetLinearVelocity(b2Vec2 linearVelocity) { ::b2Body_SetLinearVelocity(value_, linearVelocity); }
  void Body_SetAngularVelocity(float angularVelocity) { ::b2Body_SetAngularVelocity(value_, angularVelocity); }
  void Body_SetTargetTransform(b2Transform target, float timeStep) { ::b2Body_SetTargetTransform(value_, target, timeStep); }
  b2Vec2 Body_GetLocalPointVelocity(b2Vec2 localPoint) {
    return ::b2Body_GetLocalPointVelocity(value_, localPoint);
  }
  b2Vec2 Body_GetWorldPointVelocity(b2Vec2 worldPoint) {
    return ::b2Body_GetWorldPointVelocity(value_, worldPoint);
  }
  void Body_ApplyForce(b2Vec2 force, b2Vec2 point, bool wake) { ::b2Body_ApplyForce(value_, force, point, wake); }
  void Body_ApplyForceToCenter(b2Vec2 force, bool wake) { ::b2Body_ApplyForceToCenter(value_, force, wake); }
  void Body_ApplyTorque(float torque, bool wake) { ::b2Body_ApplyTorque(value_, torque, wake); }
  void Body_ApplyLinearImpulse(b2Vec2 impulse, b2Vec2 point, bool wake) { ::b2Body_ApplyLinearImpulse(value_, impulse, point, wake); }
  void Body_ApplyLinearImpulseToCenter(b2Vec2 impulse, bool wake) { ::b2Body_ApplyLinearImpulseToCenter(value_, impulse, wake); }
  void Body_ApplyAngularImpulse(float impulse, bool wake) { ::b2Body_ApplyAngularImpulse(value_, impulse, wake); }
  float Body_GetMass() {
    return ::b2Body_GetMass(value_);
  }
  float Body_GetRotationalInertia() {
    return ::b2Body_GetRotationalInertia(value_);
  }
  b2Vec2 Body_GetLocalCenterOfMass() {
    return ::b2Body_GetLocalCenterOfMass(value_);
  }
  b2Vec2 Body_GetWorldCenterOfMass() {
    return ::b2Body_GetWorldCenterOfMass(value_);
  }
  void Body_SetMassData(b2MassData massData) { ::b2Body_SetMassData(value_, massData); }
  b2MassData Body_GetMassData() {
    return ::b2Body_GetMassData(value_);
  }
  void Body_ApplyMassFromShapes() { ::b2Body_ApplyMassFromShapes(value_); }
  void Body_SetLinearDamping(float linearDamping) { ::b2Body_SetLinearDamping(value_, linearDamping); }
  float Body_GetLinearDamping() {
    return ::b2Body_GetLinearDamping(value_);
  }
  void Body_SetAngularDamping(float angularDamping) { ::b2Body_SetAngularDamping(value_, angularDamping); }
  float Body_GetAngularDamping() {
    return ::b2Body_GetAngularDamping(value_);
  }
  void Body_SetGravityScale(float gravityScale) { ::b2Body_SetGravityScale(value_, gravityScale); }
  float Body_GetGravityScale() {
    return ::b2Body_GetGravityScale(value_);
  }
  bool Body_IsAwake() {
    return ::b2Body_IsAwake(value_);
  }
  void Body_SetAwake(bool awake) { ::b2Body_SetAwake(value_, awake); }
  void Body_EnableSleep(bool enableSleep) { ::b2Body_EnableSleep(value_, enableSleep); }
  bool Body_IsSleepEnabled() {
    return ::b2Body_IsSleepEnabled(value_);
  }
  void Body_SetSleepThreshold(float sleepThreshold) { ::b2Body_SetSleepThreshold(value_, sleepThreshold); }
  float Body_GetSleepThreshold() {
    return ::b2Body_GetSleepThreshold(value_);
  }
  bool Body_IsEnabled() {
    return ::b2Body_IsEnabled(value_);
  }
  void Body_Disable() { ::b2Body_Disable(value_); }
  void Body_Enable() { ::b2Body_Enable(value_); }
  void Body_SetFixedRotation(bool flag) { ::b2Body_SetFixedRotation(value_, flag); }
  bool Body_IsFixedRotation() {
    return ::b2Body_IsFixedRotation(value_);
  }
  void Body_SetBullet(bool flag) { ::b2Body_SetBullet(value_, flag); }
  bool Body_IsBullet() {
    return ::b2Body_IsBullet(value_);
  }
  void Body_EnableContactEvents(bool flag) { ::b2Body_EnableContactEvents(value_, flag); }
  void Body_EnableHitEvents(bool flag) { ::b2Body_EnableHitEvents(value_, flag); }
  b2WorldId Body_GetWorld() {
    return ::b2Body_GetWorld(value_);
  }
  int Body_GetShapeCount() {
    return ::b2Body_GetShapeCount(value_);
  }
  int Body_GetShapes(b2ShapeId* shapeArray, int capacity) {
    return ::b2Body_GetShapes(value_, shapeArray, capacity);
  }
  int Body_GetJointCount() {
    return ::b2Body_GetJointCount(value_);
  }
  int Body_GetJoints(b2JointId* jointArray, int capacity) {
    return ::b2Body_GetJoints(value_, jointArray, capacity);
  }
  int Body_GetContactCapacity() {
    return ::b2Body_GetContactCapacity(value_);
  }
  int Body_GetContactData(b2ContactData* contactData, int capacity) {
    return ::b2Body_GetContactData(value_, contactData, capacity);
  }
  b2AABB Body_ComputeAABB() {
    return ::b2Body_ComputeAABB(value_);
  }
  b2ShapeId CreateCircleShape(const b2ShapeDef* def, const b2Circle* circle) {
    return ::b2CreateCircleShape(value_, def, circle);
  }
  b2ShapeId CreateSegmentShape(const b2ShapeDef* def, const b2Segment* segment) {
    return ::b2CreateSegmentShape(value_, def, segment);
  }
  b2ShapeId CreateCapsuleShape(const b2ShapeDef* def, const b2Capsule* capsule) {
    return ::b2CreateCapsuleShape(value_, def, capsule);
  }
  b2ShapeId CreatePolygonShape(const b2ShapeDef* def, const b2Polygon* polygon) {
    return ::b2CreatePolygonShape(value_, def, polygon);
  }
  b2ChainId CreateChain(const b2ChainDef* def) {
    return ::b2CreateChain(value_, def);
  }
 private:
  explicit PhysicsBody(b2BodyId value) : value_(value), engaged_(true) {}
  b2BodyId value_{};
  bool engaged_ = false;
};

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& Atan2 = ::b2Atan2;
inline constexpr auto& Chain_GetFriction = ::b2Chain_GetFriction;
inline constexpr auto& Chain_GetMaterial = ::b2Chain_GetMaterial;
inline constexpr auto& Chain_GetRestitution = ::b2Chain_GetRestitution;
inline constexpr auto& Chain_GetSegmentCount = ::b2Chain_GetSegmentCount;
inline constexpr auto& Chain_GetSegments = ::b2Chain_GetSegments;
inline constexpr auto& Chain_GetWorld = ::b2Chain_GetWorld;
inline constexpr auto& Chain_IsValid = ::b2Chain_IsValid;
inline constexpr auto& Chain_SetFriction = ::b2Chain_SetFriction;
inline constexpr auto& Chain_SetMaterial = ::b2Chain_SetMaterial;
inline constexpr auto& Chain_SetRestitution = ::b2Chain_SetRestitution;
inline constexpr auto& ClipVector = ::b2ClipVector;
inline constexpr auto& CollideCapsuleAndCircle = ::b2CollideCapsuleAndCircle;
inline constexpr auto& CollideCapsules = ::b2CollideCapsules;
inline constexpr auto& CollideChainSegmentAndCapsule = ::b2CollideChainSegmentAndCapsule;
inline constexpr auto& CollideChainSegmentAndCircle = ::b2CollideChainSegmentAndCircle;
inline constexpr auto& CollideChainSegmentAndPolygon = ::b2CollideChainSegmentAndPolygon;
inline constexpr auto& CollideCircles = ::b2CollideCircles;
inline constexpr auto& CollidePolygonAndCapsule = ::b2CollidePolygonAndCapsule;
inline constexpr auto& CollidePolygonAndCircle = ::b2CollidePolygonAndCircle;
inline constexpr auto& CollidePolygons = ::b2CollidePolygons;
inline constexpr auto& CollideSegmentAndCapsule = ::b2CollideSegmentAndCapsule;
inline constexpr auto& CollideSegmentAndCircle = ::b2CollideSegmentAndCircle;
inline constexpr auto& CollideSegmentAndPolygon = ::b2CollideSegmentAndPolygon;
inline constexpr auto& ComputeCapsuleAABB = ::b2ComputeCapsuleAABB;
inline constexpr auto& ComputeCapsuleMass = ::b2ComputeCapsuleMass;
inline constexpr auto& ComputeCircleAABB = ::b2ComputeCircleAABB;
inline constexpr auto& ComputeCircleMass = ::b2ComputeCircleMass;
inline constexpr auto& ComputeCosSin = ::b2ComputeCosSin;
inline constexpr auto& ComputeHull = ::b2ComputeHull;
inline constexpr auto& ComputePolygonAABB = ::b2ComputePolygonAABB;
inline constexpr auto& ComputePolygonMass = ::b2ComputePolygonMass;
inline constexpr auto& ComputeRotationBetweenUnitVectors = ::b2ComputeRotationBetweenUnitVectors;
inline constexpr auto& ComputeSegmentAABB = ::b2ComputeSegmentAABB;
inline constexpr auto& DefaultBodyDef = ::b2DefaultBodyDef;
inline constexpr auto& DefaultChainDef = ::b2DefaultChainDef;
inline constexpr auto& DefaultDebugDraw = ::b2DefaultDebugDraw;
inline constexpr auto& DefaultDistanceJointDef = ::b2DefaultDistanceJointDef;
inline constexpr auto& DefaultExplosionDef = ::b2DefaultExplosionDef;
inline constexpr auto& DefaultFilter = ::b2DefaultFilter;
inline constexpr auto& DefaultFilterJointDef = ::b2DefaultFilterJointDef;
inline constexpr auto& DefaultMotorJointDef = ::b2DefaultMotorJointDef;
inline constexpr auto& DefaultMouseJointDef = ::b2DefaultMouseJointDef;
inline constexpr auto& DefaultPrismaticJointDef = ::b2DefaultPrismaticJointDef;
inline constexpr auto& DefaultQueryFilter = ::b2DefaultQueryFilter;
inline constexpr auto& DefaultRevoluteJointDef = ::b2DefaultRevoluteJointDef;
inline constexpr auto& DefaultShapeDef = ::b2DefaultShapeDef;
inline constexpr auto& DefaultSurfaceMaterial = ::b2DefaultSurfaceMaterial;
inline constexpr auto& DefaultWeldJointDef = ::b2DefaultWeldJointDef;
inline constexpr auto& DefaultWheelJointDef = ::b2DefaultWheelJointDef;
inline constexpr auto& DefaultWorldDef = ::b2DefaultWorldDef;
inline constexpr auto& DestroyChain = ::b2DestroyChain;
inline constexpr auto& DestroyJoint = ::b2DestroyJoint;
inline constexpr auto& DestroyShape = ::b2DestroyShape;
inline constexpr auto& DistanceJoint_EnableLimit = ::b2DistanceJoint_EnableLimit;
inline constexpr auto& DistanceJoint_EnableMotor = ::b2DistanceJoint_EnableMotor;
inline constexpr auto& DistanceJoint_EnableSpring = ::b2DistanceJoint_EnableSpring;
inline constexpr auto& DistanceJoint_GetCurrentLength = ::b2DistanceJoint_GetCurrentLength;
inline constexpr auto& DistanceJoint_GetLength = ::b2DistanceJoint_GetLength;
inline constexpr auto& DistanceJoint_GetMaxLength = ::b2DistanceJoint_GetMaxLength;
inline constexpr auto& DistanceJoint_GetMaxMotorForce = ::b2DistanceJoint_GetMaxMotorForce;
inline constexpr auto& DistanceJoint_GetMinLength = ::b2DistanceJoint_GetMinLength;
inline constexpr auto& DistanceJoint_GetMotorForce = ::b2DistanceJoint_GetMotorForce;
inline constexpr auto& DistanceJoint_GetMotorSpeed = ::b2DistanceJoint_GetMotorSpeed;
inline constexpr auto& DistanceJoint_GetSpringDampingRatio = ::b2DistanceJoint_GetSpringDampingRatio;
inline constexpr auto& DistanceJoint_GetSpringHertz = ::b2DistanceJoint_GetSpringHertz;
inline constexpr auto& DistanceJoint_IsLimitEnabled = ::b2DistanceJoint_IsLimitEnabled;
inline constexpr auto& DistanceJoint_IsMotorEnabled = ::b2DistanceJoint_IsMotorEnabled;
inline constexpr auto& DistanceJoint_IsSpringEnabled = ::b2DistanceJoint_IsSpringEnabled;
inline constexpr auto& DistanceJoint_SetLength = ::b2DistanceJoint_SetLength;
inline constexpr auto& DistanceJoint_SetLengthRange = ::b2DistanceJoint_SetLengthRange;
inline constexpr auto& DistanceJoint_SetMaxMotorForce = ::b2DistanceJoint_SetMaxMotorForce;
inline constexpr auto& DistanceJoint_SetMotorSpeed = ::b2DistanceJoint_SetMotorSpeed;
inline constexpr auto& DistanceJoint_SetSpringDampingRatio = ::b2DistanceJoint_SetSpringDampingRatio;
inline constexpr auto& DistanceJoint_SetSpringHertz = ::b2DistanceJoint_SetSpringHertz;
inline constexpr auto& DynamicTree_Create = ::b2DynamicTree_Create;
inline constexpr auto& DynamicTree_CreateProxy = ::b2DynamicTree_CreateProxy;
inline constexpr auto& DynamicTree_Destroy = ::b2DynamicTree_Destroy;
inline constexpr auto& DynamicTree_DestroyProxy = ::b2DynamicTree_DestroyProxy;
inline constexpr auto& DynamicTree_EnlargeProxy = ::b2DynamicTree_EnlargeProxy;
inline constexpr auto& DynamicTree_GetAABB = ::b2DynamicTree_GetAABB;
inline constexpr auto& DynamicTree_GetAreaRatio = ::b2DynamicTree_GetAreaRatio;
inline constexpr auto& DynamicTree_GetByteCount = ::b2DynamicTree_GetByteCount;
inline constexpr auto& DynamicTree_GetCategoryBits = ::b2DynamicTree_GetCategoryBits;
inline constexpr auto& DynamicTree_GetHeight = ::b2DynamicTree_GetHeight;
inline constexpr auto& DynamicTree_GetProxyCount = ::b2DynamicTree_GetProxyCount;
inline constexpr auto& DynamicTree_GetRootBounds = ::b2DynamicTree_GetRootBounds;
inline constexpr auto& DynamicTree_GetUserData = ::b2DynamicTree_GetUserData;
inline constexpr auto& DynamicTree_MoveProxy = ::b2DynamicTree_MoveProxy;
inline constexpr auto& DynamicTree_Query = ::b2DynamicTree_Query;
inline constexpr auto& DynamicTree_RayCast = ::b2DynamicTree_RayCast;
inline constexpr auto& DynamicTree_Rebuild = ::b2DynamicTree_Rebuild;
inline constexpr auto& DynamicTree_SetCategoryBits = ::b2DynamicTree_SetCategoryBits;
inline constexpr auto& DynamicTree_ShapeCast = ::b2DynamicTree_ShapeCast;
inline constexpr auto& DynamicTree_Validate = ::b2DynamicTree_Validate;
inline constexpr auto& DynamicTree_ValidateNoEnlarged = ::b2DynamicTree_ValidateNoEnlarged;
inline constexpr auto& GetByteCount = ::b2GetByteCount;
inline constexpr auto& GetLengthUnitsPerMeter = ::b2GetLengthUnitsPerMeter;
inline constexpr auto& GetMilliseconds = ::b2GetMilliseconds;
inline constexpr auto& GetMillisecondsAndReset = ::b2GetMillisecondsAndReset;
inline constexpr auto& GetSweepTransform = ::b2GetSweepTransform;
inline constexpr auto& GetTicks = ::b2GetTicks;
inline constexpr auto& GetVersion = ::b2GetVersion;
inline constexpr auto& Hash = ::b2Hash;
inline constexpr auto& InternalAssertFcn = ::b2InternalAssertFcn;
inline constexpr auto& IsValidAABB = ::b2IsValidAABB;
inline constexpr auto& IsValidFloat = ::b2IsValidFloat;
inline constexpr auto& IsValidPlane = ::b2IsValidPlane;
inline constexpr auto& IsValidRay = ::b2IsValidRay;
inline constexpr auto& IsValidRotation = ::b2IsValidRotation;
inline constexpr auto& IsValidVec2 = ::b2IsValidVec2;
inline constexpr auto& Joint_GetAngularSeparation = ::b2Joint_GetAngularSeparation;
inline constexpr auto& Joint_GetBodyA = ::b2Joint_GetBodyA;
inline constexpr auto& Joint_GetBodyB = ::b2Joint_GetBodyB;
inline constexpr auto& Joint_GetCollideConnected = ::b2Joint_GetCollideConnected;
inline constexpr auto& Joint_GetConstraintForce = ::b2Joint_GetConstraintForce;
inline constexpr auto& Joint_GetConstraintTorque = ::b2Joint_GetConstraintTorque;
inline constexpr auto& Joint_GetConstraintTuning = ::b2Joint_GetConstraintTuning;
inline constexpr auto& Joint_GetLinearSeparation = ::b2Joint_GetLinearSeparation;
inline constexpr auto& Joint_GetLocalAnchorA = ::b2Joint_GetLocalAnchorA;
inline constexpr auto& Joint_GetLocalAnchorB = ::b2Joint_GetLocalAnchorB;
inline constexpr auto& Joint_GetLocalAxisA = ::b2Joint_GetLocalAxisA;
inline constexpr auto& Joint_GetReferenceAngle = ::b2Joint_GetReferenceAngle;
inline constexpr auto& Joint_GetType = ::b2Joint_GetType;
inline constexpr auto& Joint_GetUserData = ::b2Joint_GetUserData;
inline constexpr auto& Joint_GetWorld = ::b2Joint_GetWorld;
inline constexpr auto& Joint_IsValid = ::b2Joint_IsValid;
inline constexpr auto& Joint_SetCollideConnected = ::b2Joint_SetCollideConnected;
inline constexpr auto& Joint_SetConstraintTuning = ::b2Joint_SetConstraintTuning;
inline constexpr auto& Joint_SetLocalAnchorA = ::b2Joint_SetLocalAnchorA;
inline constexpr auto& Joint_SetLocalAnchorB = ::b2Joint_SetLocalAnchorB;
inline constexpr auto& Joint_SetLocalAxisA = ::b2Joint_SetLocalAxisA;
inline constexpr auto& Joint_SetReferenceAngle = ::b2Joint_SetReferenceAngle;
inline constexpr auto& Joint_SetUserData = ::b2Joint_SetUserData;
inline constexpr auto& Joint_WakeBodies = ::b2Joint_WakeBodies;
inline constexpr auto& MakeBox = ::b2MakeBox;
inline constexpr auto& MakeOffsetBox = ::b2MakeOffsetBox;
inline constexpr auto& MakeOffsetPolygon = ::b2MakeOffsetPolygon;
inline constexpr auto& MakeOffsetProxy = ::b2MakeOffsetProxy;
inline constexpr auto& MakeOffsetRoundedBox = ::b2MakeOffsetRoundedBox;
inline constexpr auto& MakeOffsetRoundedPolygon = ::b2MakeOffsetRoundedPolygon;
inline constexpr auto& MakePolygon = ::b2MakePolygon;
inline constexpr auto& MakeProxy = ::b2MakeProxy;
inline constexpr auto& MakeRoundedBox = ::b2MakeRoundedBox;
inline constexpr auto& MakeSquare = ::b2MakeSquare;
inline constexpr auto& MotorJoint_GetAngularOffset = ::b2MotorJoint_GetAngularOffset;
inline constexpr auto& MotorJoint_GetCorrectionFactor = ::b2MotorJoint_GetCorrectionFactor;
inline constexpr auto& MotorJoint_GetLinearOffset = ::b2MotorJoint_GetLinearOffset;
inline constexpr auto& MotorJoint_GetMaxForce = ::b2MotorJoint_GetMaxForce;
inline constexpr auto& MotorJoint_GetMaxTorque = ::b2MotorJoint_GetMaxTorque;
inline constexpr auto& MotorJoint_SetAngularOffset = ::b2MotorJoint_SetAngularOffset;
inline constexpr auto& MotorJoint_SetCorrectionFactor = ::b2MotorJoint_SetCorrectionFactor;
inline constexpr auto& MotorJoint_SetLinearOffset = ::b2MotorJoint_SetLinearOffset;
inline constexpr auto& MotorJoint_SetMaxForce = ::b2MotorJoint_SetMaxForce;
inline constexpr auto& MotorJoint_SetMaxTorque = ::b2MotorJoint_SetMaxTorque;
inline constexpr auto& MouseJoint_GetMaxForce = ::b2MouseJoint_GetMaxForce;
inline constexpr auto& MouseJoint_GetSpringDampingRatio = ::b2MouseJoint_GetSpringDampingRatio;
inline constexpr auto& MouseJoint_GetSpringHertz = ::b2MouseJoint_GetSpringHertz;
inline constexpr auto& MouseJoint_GetTarget = ::b2MouseJoint_GetTarget;
inline constexpr auto& MouseJoint_SetMaxForce = ::b2MouseJoint_SetMaxForce;
inline constexpr auto& MouseJoint_SetSpringDampingRatio = ::b2MouseJoint_SetSpringDampingRatio;
inline constexpr auto& MouseJoint_SetSpringHertz = ::b2MouseJoint_SetSpringHertz;
inline constexpr auto& MouseJoint_SetTarget = ::b2MouseJoint_SetTarget;
inline constexpr auto& PointInCapsule = ::b2PointInCapsule;
inline constexpr auto& PointInCircle = ::b2PointInCircle;
inline constexpr auto& PointInPolygon = ::b2PointInPolygon;
inline constexpr auto& PrismaticJoint_EnableLimit = ::b2PrismaticJoint_EnableLimit;
inline constexpr auto& PrismaticJoint_EnableMotor = ::b2PrismaticJoint_EnableMotor;
inline constexpr auto& PrismaticJoint_EnableSpring = ::b2PrismaticJoint_EnableSpring;
inline constexpr auto& PrismaticJoint_GetLowerLimit = ::b2PrismaticJoint_GetLowerLimit;
inline constexpr auto& PrismaticJoint_GetMaxMotorForce = ::b2PrismaticJoint_GetMaxMotorForce;
inline constexpr auto& PrismaticJoint_GetMotorForce = ::b2PrismaticJoint_GetMotorForce;
inline constexpr auto& PrismaticJoint_GetMotorSpeed = ::b2PrismaticJoint_GetMotorSpeed;
inline constexpr auto& PrismaticJoint_GetSpeed = ::b2PrismaticJoint_GetSpeed;
inline constexpr auto& PrismaticJoint_GetSpringDampingRatio = ::b2PrismaticJoint_GetSpringDampingRatio;
inline constexpr auto& PrismaticJoint_GetSpringHertz = ::b2PrismaticJoint_GetSpringHertz;
inline constexpr auto& PrismaticJoint_GetTargetTranslation = ::b2PrismaticJoint_GetTargetTranslation;
inline constexpr auto& PrismaticJoint_GetTranslation = ::b2PrismaticJoint_GetTranslation;
inline constexpr auto& PrismaticJoint_GetUpperLimit = ::b2PrismaticJoint_GetUpperLimit;
inline constexpr auto& PrismaticJoint_IsLimitEnabled = ::b2PrismaticJoint_IsLimitEnabled;
inline constexpr auto& PrismaticJoint_IsMotorEnabled = ::b2PrismaticJoint_IsMotorEnabled;
inline constexpr auto& PrismaticJoint_IsSpringEnabled = ::b2PrismaticJoint_IsSpringEnabled;
inline constexpr auto& PrismaticJoint_SetLimits = ::b2PrismaticJoint_SetLimits;
inline constexpr auto& PrismaticJoint_SetMaxMotorForce = ::b2PrismaticJoint_SetMaxMotorForce;
inline constexpr auto& PrismaticJoint_SetMotorSpeed = ::b2PrismaticJoint_SetMotorSpeed;
inline constexpr auto& PrismaticJoint_SetSpringDampingRatio = ::b2PrismaticJoint_SetSpringDampingRatio;
inline constexpr auto& PrismaticJoint_SetSpringHertz = ::b2PrismaticJoint_SetSpringHertz;
inline constexpr auto& PrismaticJoint_SetTargetTranslation = ::b2PrismaticJoint_SetTargetTranslation;
inline constexpr auto& RayCastCapsule = ::b2RayCastCapsule;
inline constexpr auto& RayCastCircle = ::b2RayCastCircle;
inline constexpr auto& RayCastPolygon = ::b2RayCastPolygon;
inline constexpr auto& RayCastSegment = ::b2RayCastSegment;
inline constexpr auto& RevoluteJoint_EnableLimit = ::b2RevoluteJoint_EnableLimit;
inline constexpr auto& RevoluteJoint_EnableMotor = ::b2RevoluteJoint_EnableMotor;
inline constexpr auto& RevoluteJoint_EnableSpring = ::b2RevoluteJoint_EnableSpring;
inline constexpr auto& RevoluteJoint_GetAngle = ::b2RevoluteJoint_GetAngle;
inline constexpr auto& RevoluteJoint_GetLowerLimit = ::b2RevoluteJoint_GetLowerLimit;
inline constexpr auto& RevoluteJoint_GetMaxMotorTorque = ::b2RevoluteJoint_GetMaxMotorTorque;
inline constexpr auto& RevoluteJoint_GetMotorSpeed = ::b2RevoluteJoint_GetMotorSpeed;
inline constexpr auto& RevoluteJoint_GetMotorTorque = ::b2RevoluteJoint_GetMotorTorque;
inline constexpr auto& RevoluteJoint_GetSpringDampingRatio = ::b2RevoluteJoint_GetSpringDampingRatio;
inline constexpr auto& RevoluteJoint_GetSpringHertz = ::b2RevoluteJoint_GetSpringHertz;
inline constexpr auto& RevoluteJoint_GetTargetAngle = ::b2RevoluteJoint_GetTargetAngle;
inline constexpr auto& RevoluteJoint_GetUpperLimit = ::b2RevoluteJoint_GetUpperLimit;
inline constexpr auto& RevoluteJoint_IsLimitEnabled = ::b2RevoluteJoint_IsLimitEnabled;
inline constexpr auto& RevoluteJoint_IsMotorEnabled = ::b2RevoluteJoint_IsMotorEnabled;
inline constexpr auto& RevoluteJoint_IsSpringEnabled = ::b2RevoluteJoint_IsSpringEnabled;
inline constexpr auto& RevoluteJoint_SetLimits = ::b2RevoluteJoint_SetLimits;
inline constexpr auto& RevoluteJoint_SetMaxMotorTorque = ::b2RevoluteJoint_SetMaxMotorTorque;
inline constexpr auto& RevoluteJoint_SetMotorSpeed = ::b2RevoluteJoint_SetMotorSpeed;
inline constexpr auto& RevoluteJoint_SetSpringDampingRatio = ::b2RevoluteJoint_SetSpringDampingRatio;
inline constexpr auto& RevoluteJoint_SetSpringHertz = ::b2RevoluteJoint_SetSpringHertz;
inline constexpr auto& RevoluteJoint_SetTargetAngle = ::b2RevoluteJoint_SetTargetAngle;
inline constexpr auto& SegmentDistance = ::b2SegmentDistance;
inline constexpr auto& SetAllocator = ::b2SetAllocator;
inline constexpr auto& SetAssertFcn = ::b2SetAssertFcn;
inline constexpr auto& SetLengthUnitsPerMeter = ::b2SetLengthUnitsPerMeter;
inline constexpr auto& ShapeCast = ::b2ShapeCast;
inline constexpr auto& ShapeCastCapsule = ::b2ShapeCastCapsule;
inline constexpr auto& ShapeCastCircle = ::b2ShapeCastCircle;
inline constexpr auto& ShapeCastPolygon = ::b2ShapeCastPolygon;
inline constexpr auto& ShapeCastSegment = ::b2ShapeCastSegment;
inline constexpr auto& ShapeDistance = ::b2ShapeDistance;
inline constexpr auto& Shape_AreContactEventsEnabled = ::b2Shape_AreContactEventsEnabled;
inline constexpr auto& Shape_AreHitEventsEnabled = ::b2Shape_AreHitEventsEnabled;
inline constexpr auto& Shape_ArePreSolveEventsEnabled = ::b2Shape_ArePreSolveEventsEnabled;
inline constexpr auto& Shape_AreSensorEventsEnabled = ::b2Shape_AreSensorEventsEnabled;
inline constexpr auto& Shape_EnableContactEvents = ::b2Shape_EnableContactEvents;
inline constexpr auto& Shape_EnableHitEvents = ::b2Shape_EnableHitEvents;
inline constexpr auto& Shape_EnablePreSolveEvents = ::b2Shape_EnablePreSolveEvents;
inline constexpr auto& Shape_EnableSensorEvents = ::b2Shape_EnableSensorEvents;
inline constexpr auto& Shape_GetAABB = ::b2Shape_GetAABB;
inline constexpr auto& Shape_GetBody = ::b2Shape_GetBody;
inline constexpr auto& Shape_GetCapsule = ::b2Shape_GetCapsule;
inline constexpr auto& Shape_GetChainSegment = ::b2Shape_GetChainSegment;
inline constexpr auto& Shape_GetCircle = ::b2Shape_GetCircle;
inline constexpr auto& Shape_GetClosestPoint = ::b2Shape_GetClosestPoint;
inline constexpr auto& Shape_GetContactCapacity = ::b2Shape_GetContactCapacity;
inline constexpr auto& Shape_GetContactData = ::b2Shape_GetContactData;
inline constexpr auto& Shape_GetDensity = ::b2Shape_GetDensity;
inline constexpr auto& Shape_GetFilter = ::b2Shape_GetFilter;
inline constexpr auto& Shape_GetFriction = ::b2Shape_GetFriction;
inline constexpr auto& Shape_GetMassData = ::b2Shape_GetMassData;
inline constexpr auto& Shape_GetMaterial = ::b2Shape_GetMaterial;
inline constexpr auto& Shape_GetParentChain = ::b2Shape_GetParentChain;
inline constexpr auto& Shape_GetPolygon = ::b2Shape_GetPolygon;
inline constexpr auto& Shape_GetRestitution = ::b2Shape_GetRestitution;
inline constexpr auto& Shape_GetSegment = ::b2Shape_GetSegment;
inline constexpr auto& Shape_GetSensorCapacity = ::b2Shape_GetSensorCapacity;
inline constexpr auto& Shape_GetSensorOverlaps = ::b2Shape_GetSensorOverlaps;
inline constexpr auto& Shape_GetSurfaceMaterial = ::b2Shape_GetSurfaceMaterial;
inline constexpr auto& Shape_GetType = ::b2Shape_GetType;
inline constexpr auto& Shape_GetUserData = ::b2Shape_GetUserData;
inline constexpr auto& Shape_GetWorld = ::b2Shape_GetWorld;
inline constexpr auto& Shape_IsSensor = ::b2Shape_IsSensor;
inline constexpr auto& Shape_IsValid = ::b2Shape_IsValid;
inline constexpr auto& Shape_RayCast = ::b2Shape_RayCast;
inline constexpr auto& Shape_SetCapsule = ::b2Shape_SetCapsule;
inline constexpr auto& Shape_SetCircle = ::b2Shape_SetCircle;
inline constexpr auto& Shape_SetDensity = ::b2Shape_SetDensity;
inline constexpr auto& Shape_SetFilter = ::b2Shape_SetFilter;
inline constexpr auto& Shape_SetFriction = ::b2Shape_SetFriction;
inline constexpr auto& Shape_SetMaterial = ::b2Shape_SetMaterial;
inline constexpr auto& Shape_SetPolygon = ::b2Shape_SetPolygon;
inline constexpr auto& Shape_SetRestitution = ::b2Shape_SetRestitution;
inline constexpr auto& Shape_SetSegment = ::b2Shape_SetSegment;
inline constexpr auto& Shape_SetSurfaceMaterial = ::b2Shape_SetSurfaceMaterial;
inline constexpr auto& Shape_SetUserData = ::b2Shape_SetUserData;
inline constexpr auto& Shape_TestPoint = ::b2Shape_TestPoint;
inline constexpr auto& SolvePlanes = ::b2SolvePlanes;
inline constexpr auto& TimeOfImpact = ::b2TimeOfImpact;
inline constexpr auto& TransformPolygon = ::b2TransformPolygon;
inline constexpr auto& ValidateHull = ::b2ValidateHull;
inline constexpr auto& WeldJoint_GetAngularDampingRatio = ::b2WeldJoint_GetAngularDampingRatio;
inline constexpr auto& WeldJoint_GetAngularHertz = ::b2WeldJoint_GetAngularHertz;
inline constexpr auto& WeldJoint_GetLinearDampingRatio = ::b2WeldJoint_GetLinearDampingRatio;
inline constexpr auto& WeldJoint_GetLinearHertz = ::b2WeldJoint_GetLinearHertz;
inline constexpr auto& WeldJoint_SetAngularDampingRatio = ::b2WeldJoint_SetAngularDampingRatio;
inline constexpr auto& WeldJoint_SetAngularHertz = ::b2WeldJoint_SetAngularHertz;
inline constexpr auto& WeldJoint_SetLinearDampingRatio = ::b2WeldJoint_SetLinearDampingRatio;
inline constexpr auto& WeldJoint_SetLinearHertz = ::b2WeldJoint_SetLinearHertz;
inline constexpr auto& WheelJoint_EnableLimit = ::b2WheelJoint_EnableLimit;
inline constexpr auto& WheelJoint_EnableMotor = ::b2WheelJoint_EnableMotor;
inline constexpr auto& WheelJoint_EnableSpring = ::b2WheelJoint_EnableSpring;
inline constexpr auto& WheelJoint_GetLowerLimit = ::b2WheelJoint_GetLowerLimit;
inline constexpr auto& WheelJoint_GetMaxMotorTorque = ::b2WheelJoint_GetMaxMotorTorque;
inline constexpr auto& WheelJoint_GetMotorSpeed = ::b2WheelJoint_GetMotorSpeed;
inline constexpr auto& WheelJoint_GetMotorTorque = ::b2WheelJoint_GetMotorTorque;
inline constexpr auto& WheelJoint_GetSpringDampingRatio = ::b2WheelJoint_GetSpringDampingRatio;
inline constexpr auto& WheelJoint_GetSpringHertz = ::b2WheelJoint_GetSpringHertz;
inline constexpr auto& WheelJoint_GetUpperLimit = ::b2WheelJoint_GetUpperLimit;
inline constexpr auto& WheelJoint_IsLimitEnabled = ::b2WheelJoint_IsLimitEnabled;
inline constexpr auto& WheelJoint_IsMotorEnabled = ::b2WheelJoint_IsMotorEnabled;
inline constexpr auto& WheelJoint_IsSpringEnabled = ::b2WheelJoint_IsSpringEnabled;
inline constexpr auto& WheelJoint_SetLimits = ::b2WheelJoint_SetLimits;
inline constexpr auto& WheelJoint_SetMaxMotorTorque = ::b2WheelJoint_SetMaxMotorTorque;
inline constexpr auto& WheelJoint_SetMotorSpeed = ::b2WheelJoint_SetMotorSpeed;
inline constexpr auto& WheelJoint_SetSpringDampingRatio = ::b2WheelJoint_SetSpringDampingRatio;
inline constexpr auto& WheelJoint_SetSpringHertz = ::b2WheelJoint_SetSpringHertz;
inline constexpr auto& Yield = ::b2Yield;

}  // namespace b2
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_B2_H_
// clang-format on
