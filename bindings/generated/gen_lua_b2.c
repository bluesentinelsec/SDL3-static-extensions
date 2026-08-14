/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for Box2D. */
#include "../src/gen_support_lua.h"

#include <box2d/box2d.h>
#include <string.h>

static void GenRead_b2Vec2(lua_State *L, int idx, b2Vec2 *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (float)SDLStaticGen_LuaFieldNum(L, idx, "x");
    out->y = (float)SDLStaticGen_LuaFieldNum(L, idx, "y");
}

static void GenPush_b2Vec2(lua_State *L, const b2Vec2 *in)
{
    lua_createtable(L, 0, 2);
    lua_pushnumber(L, (lua_Number)in->x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, (lua_Number)in->y);
    lua_setfield(L, -2, "y");
}

static void GenRead_b2AABB(lua_State *L, int idx, b2AABB *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "lowerBound");
    GenRead_b2Vec2(L, lua_gettop(L), &out->lowerBound);
    lua_pop(L, 1);
    lua_getfield(L, idx, "upperBound");
    GenRead_b2Vec2(L, lua_gettop(L), &out->upperBound);
    lua_pop(L, 1);
}

static void GenPush_b2AABB(lua_State *L, const b2AABB *in)
{
    lua_createtable(L, 0, 2);
    GenPush_b2Vec2(L, &in->lowerBound);
    lua_setfield(L, -2, "lowerBound");
    GenPush_b2Vec2(L, &in->upperBound);
    lua_setfield(L, -2, "upperBound");
}

static void GenRead_b2Rot(lua_State *L, int idx, b2Rot *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->c = (float)SDLStaticGen_LuaFieldNum(L, idx, "c");
    out->s = (float)SDLStaticGen_LuaFieldNum(L, idx, "s");
}

static void GenPush_b2Rot(lua_State *L, const b2Rot *in)
{
    lua_createtable(L, 0, 2);
    lua_pushnumber(L, (lua_Number)in->c);
    lua_setfield(L, -2, "c");
    lua_pushnumber(L, (lua_Number)in->s);
    lua_setfield(L, -2, "s");
}

static void GenRead_b2BodyDef(lua_State *L, int idx, b2BodyDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->type = (b2BodyType)SDLStaticGen_LuaFieldInt(L, idx, "type");
    lua_getfield(L, idx, "position");
    GenRead_b2Vec2(L, lua_gettop(L), &out->position);
    lua_pop(L, 1);
    lua_getfield(L, idx, "rotation");
    GenRead_b2Rot(L, lua_gettop(L), &out->rotation);
    lua_pop(L, 1);
    lua_getfield(L, idx, "linearVelocity");
    GenRead_b2Vec2(L, lua_gettop(L), &out->linearVelocity);
    lua_pop(L, 1);
    out->angularVelocity = (float)SDLStaticGen_LuaFieldNum(L, idx, "angularVelocity");
    out->linearDamping = (float)SDLStaticGen_LuaFieldNum(L, idx, "linearDamping");
    out->angularDamping = (float)SDLStaticGen_LuaFieldNum(L, idx, "angularDamping");
    out->gravityScale = (float)SDLStaticGen_LuaFieldNum(L, idx, "gravityScale");
    out->sleepThreshold = (float)SDLStaticGen_LuaFieldNum(L, idx, "sleepThreshold");
    out->enableSleep = (bool)SDLStaticGen_LuaFieldBool(L, idx, "enableSleep");
    out->isAwake = (bool)SDLStaticGen_LuaFieldBool(L, idx, "isAwake");
    out->fixedRotation = (bool)SDLStaticGen_LuaFieldBool(L, idx, "fixedRotation");
    out->isBullet = (bool)SDLStaticGen_LuaFieldBool(L, idx, "isBullet");
    out->isEnabled = (bool)SDLStaticGen_LuaFieldBool(L, idx, "isEnabled");
    out->allowFastRotation = (bool)SDLStaticGen_LuaFieldBool(L, idx, "allowFastRotation");
    out->internalValue = (int)SDLStaticGen_LuaFieldInt(L, idx, "internalValue");
}

static void GenPush_b2BodyDef(lua_State *L, const b2BodyDef *in)
{
    lua_createtable(L, 0, 18);
    lua_pushinteger(L, (lua_Integer)in->type);
    lua_setfield(L, -2, "type");
    GenPush_b2Vec2(L, &in->position);
    lua_setfield(L, -2, "position");
    GenPush_b2Rot(L, &in->rotation);
    lua_setfield(L, -2, "rotation");
    GenPush_b2Vec2(L, &in->linearVelocity);
    lua_setfield(L, -2, "linearVelocity");
    lua_pushnumber(L, (lua_Number)in->angularVelocity);
    lua_setfield(L, -2, "angularVelocity");
    lua_pushnumber(L, (lua_Number)in->linearDamping);
    lua_setfield(L, -2, "linearDamping");
    lua_pushnumber(L, (lua_Number)in->angularDamping);
    lua_setfield(L, -2, "angularDamping");
    lua_pushnumber(L, (lua_Number)in->gravityScale);
    lua_setfield(L, -2, "gravityScale");
    lua_pushnumber(L, (lua_Number)in->sleepThreshold);
    lua_setfield(L, -2, "sleepThreshold");
    lua_pushboolean(L, (int)in->enableSleep);
    lua_setfield(L, -2, "enableSleep");
    lua_pushboolean(L, (int)in->isAwake);
    lua_setfield(L, -2, "isAwake");
    lua_pushboolean(L, (int)in->fixedRotation);
    lua_setfield(L, -2, "fixedRotation");
    lua_pushboolean(L, (int)in->isBullet);
    lua_setfield(L, -2, "isBullet");
    lua_pushboolean(L, (int)in->isEnabled);
    lua_setfield(L, -2, "isEnabled");
    lua_pushboolean(L, (int)in->allowFastRotation);
    lua_setfield(L, -2, "allowFastRotation");
    lua_pushinteger(L, (lua_Integer)in->internalValue);
    lua_setfield(L, -2, "internalValue");
}

static void GenRead_b2BodyId(lua_State *L, int idx, b2BodyId *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->index1 = (int32_t)SDLStaticGen_LuaFieldInt(L, idx, "index1");
    out->world0 = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "world0");
    out->generation = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "generation");
}

static void GenPush_b2BodyId(lua_State *L, const b2BodyId *in)
{
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, (lua_Integer)in->index1);
    lua_setfield(L, -2, "index1");
    lua_pushinteger(L, (lua_Integer)in->world0);
    lua_setfield(L, -2, "world0");
    lua_pushinteger(L, (lua_Integer)in->generation);
    lua_setfield(L, -2, "generation");
}

static void GenRead_b2Capsule(lua_State *L, int idx, b2Capsule *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "center1");
    GenRead_b2Vec2(L, lua_gettop(L), &out->center1);
    lua_pop(L, 1);
    lua_getfield(L, idx, "center2");
    GenRead_b2Vec2(L, lua_gettop(L), &out->center2);
    lua_pop(L, 1);
    out->radius = (float)SDLStaticGen_LuaFieldNum(L, idx, "radius");
}

static void GenPush_b2Capsule(lua_State *L, const b2Capsule *in)
{
    lua_createtable(L, 0, 3);
    GenPush_b2Vec2(L, &in->center1);
    lua_setfield(L, -2, "center1");
    GenPush_b2Vec2(L, &in->center2);
    lua_setfield(L, -2, "center2");
    lua_pushnumber(L, (lua_Number)in->radius);
    lua_setfield(L, -2, "radius");
}

static void GenPush_b2CastOutput(lua_State *L, const b2CastOutput *in)
{
    lua_createtable(L, 0, 5);
    GenPush_b2Vec2(L, &in->normal);
    lua_setfield(L, -2, "normal");
    GenPush_b2Vec2(L, &in->point);
    lua_setfield(L, -2, "point");
    lua_pushnumber(L, (lua_Number)in->fraction);
    lua_setfield(L, -2, "fraction");
    lua_pushinteger(L, (lua_Integer)in->iterations);
    lua_setfield(L, -2, "iterations");
    lua_pushboolean(L, (int)in->hit);
    lua_setfield(L, -2, "hit");
}

static void GenRead_b2SurfaceMaterial(lua_State *L, int idx, b2SurfaceMaterial *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->friction = (float)SDLStaticGen_LuaFieldNum(L, idx, "friction");
    out->restitution = (float)SDLStaticGen_LuaFieldNum(L, idx, "restitution");
    out->rollingResistance = (float)SDLStaticGen_LuaFieldNum(L, idx, "rollingResistance");
    out->tangentSpeed = (float)SDLStaticGen_LuaFieldNum(L, idx, "tangentSpeed");
    out->userMaterialId = (int)SDLStaticGen_LuaFieldInt(L, idx, "userMaterialId");
    out->customColor = (uint32_t)SDLStaticGen_LuaFieldInt(L, idx, "customColor");
}

static void GenPush_b2SurfaceMaterial(lua_State *L, const b2SurfaceMaterial *in)
{
    lua_createtable(L, 0, 6);
    lua_pushnumber(L, (lua_Number)in->friction);
    lua_setfield(L, -2, "friction");
    lua_pushnumber(L, (lua_Number)in->restitution);
    lua_setfield(L, -2, "restitution");
    lua_pushnumber(L, (lua_Number)in->rollingResistance);
    lua_setfield(L, -2, "rollingResistance");
    lua_pushnumber(L, (lua_Number)in->tangentSpeed);
    lua_setfield(L, -2, "tangentSpeed");
    lua_pushinteger(L, (lua_Integer)in->userMaterialId);
    lua_setfield(L, -2, "userMaterialId");
    lua_pushinteger(L, (lua_Integer)in->customColor);
    lua_setfield(L, -2, "customColor");
}

static void GenRead_b2Filter(lua_State *L, int idx, b2Filter *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->categoryBits = (uint64_t)SDLStaticGen_LuaFieldInt(L, idx, "categoryBits");
    out->maskBits = (uint64_t)SDLStaticGen_LuaFieldInt(L, idx, "maskBits");
    out->groupIndex = (int)SDLStaticGen_LuaFieldInt(L, idx, "groupIndex");
}

static void GenPush_b2Filter(lua_State *L, const b2Filter *in)
{
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, (lua_Integer)in->categoryBits);
    lua_setfield(L, -2, "categoryBits");
    lua_pushinteger(L, (lua_Integer)in->maskBits);
    lua_setfield(L, -2, "maskBits");
    lua_pushinteger(L, (lua_Integer)in->groupIndex);
    lua_setfield(L, -2, "groupIndex");
}

static void GenRead_b2ChainDef(lua_State *L, int idx, b2ChainDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->count = (int)SDLStaticGen_LuaFieldInt(L, idx, "count");
    out->materialCount = (int)SDLStaticGen_LuaFieldInt(L, idx, "materialCount");
    lua_getfield(L, idx, "filter");
    GenRead_b2Filter(L, lua_gettop(L), &out->filter);
    lua_pop(L, 1);
    out->isLoop = (bool)SDLStaticGen_LuaFieldBool(L, idx, "isLoop");
    out->enableSensorEvents = (bool)SDLStaticGen_LuaFieldBool(L, idx, "enableSensorEvents");
    out->internalValue = (int)SDLStaticGen_LuaFieldInt(L, idx, "internalValue");
}

static void GenPush_b2ChainDef(lua_State *L, const b2ChainDef *in)
{
    lua_createtable(L, 0, 9);
    lua_pushinteger(L, (lua_Integer)in->count);
    lua_setfield(L, -2, "count");
    lua_pushinteger(L, (lua_Integer)in->materialCount);
    lua_setfield(L, -2, "materialCount");
    GenPush_b2Filter(L, &in->filter);
    lua_setfield(L, -2, "filter");
    lua_pushboolean(L, (int)in->isLoop);
    lua_setfield(L, -2, "isLoop");
    lua_pushboolean(L, (int)in->enableSensorEvents);
    lua_setfield(L, -2, "enableSensorEvents");
    lua_pushinteger(L, (lua_Integer)in->internalValue);
    lua_setfield(L, -2, "internalValue");
}

static void GenRead_b2ChainId(lua_State *L, int idx, b2ChainId *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->index1 = (int32_t)SDLStaticGen_LuaFieldInt(L, idx, "index1");
    out->world0 = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "world0");
    out->generation = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "generation");
}

static void GenPush_b2ChainId(lua_State *L, const b2ChainId *in)
{
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, (lua_Integer)in->index1);
    lua_setfield(L, -2, "index1");
    lua_pushinteger(L, (lua_Integer)in->world0);
    lua_setfield(L, -2, "world0");
    lua_pushinteger(L, (lua_Integer)in->generation);
    lua_setfield(L, -2, "generation");
}

static void GenRead_b2Segment(lua_State *L, int idx, b2Segment *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "point1");
    GenRead_b2Vec2(L, lua_gettop(L), &out->point1);
    lua_pop(L, 1);
    lua_getfield(L, idx, "point2");
    GenRead_b2Vec2(L, lua_gettop(L), &out->point2);
    lua_pop(L, 1);
}

static void GenPush_b2Segment(lua_State *L, const b2Segment *in)
{
    lua_createtable(L, 0, 2);
    GenPush_b2Vec2(L, &in->point1);
    lua_setfield(L, -2, "point1");
    GenPush_b2Vec2(L, &in->point2);
    lua_setfield(L, -2, "point2");
}

static void GenRead_b2ChainSegment(lua_State *L, int idx, b2ChainSegment *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "ghost1");
    GenRead_b2Vec2(L, lua_gettop(L), &out->ghost1);
    lua_pop(L, 1);
    lua_getfield(L, idx, "segment");
    GenRead_b2Segment(L, lua_gettop(L), &out->segment);
    lua_pop(L, 1);
    lua_getfield(L, idx, "ghost2");
    GenRead_b2Vec2(L, lua_gettop(L), &out->ghost2);
    lua_pop(L, 1);
    out->chainId = (int)SDLStaticGen_LuaFieldInt(L, idx, "chainId");
}

static void GenPush_b2ChainSegment(lua_State *L, const b2ChainSegment *in)
{
    lua_createtable(L, 0, 4);
    GenPush_b2Vec2(L, &in->ghost1);
    lua_setfield(L, -2, "ghost1");
    GenPush_b2Segment(L, &in->segment);
    lua_setfield(L, -2, "segment");
    GenPush_b2Vec2(L, &in->ghost2);
    lua_setfield(L, -2, "ghost2");
    lua_pushinteger(L, (lua_Integer)in->chainId);
    lua_setfield(L, -2, "chainId");
}

static void GenRead_b2Circle(lua_State *L, int idx, b2Circle *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "center");
    GenRead_b2Vec2(L, lua_gettop(L), &out->center);
    lua_pop(L, 1);
    out->radius = (float)SDLStaticGen_LuaFieldNum(L, idx, "radius");
}

static void GenPush_b2Circle(lua_State *L, const b2Circle *in)
{
    lua_createtable(L, 0, 2);
    GenPush_b2Vec2(L, &in->center);
    lua_setfield(L, -2, "center");
    lua_pushnumber(L, (lua_Number)in->radius);
    lua_setfield(L, -2, "radius");
}

static void GenRead_b2Plane(lua_State *L, int idx, b2Plane *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "normal");
    GenRead_b2Vec2(L, lua_gettop(L), &out->normal);
    lua_pop(L, 1);
    out->offset = (float)SDLStaticGen_LuaFieldNum(L, idx, "offset");
}

static void GenPush_b2Plane(lua_State *L, const b2Plane *in)
{
    lua_createtable(L, 0, 2);
    GenPush_b2Vec2(L, &in->normal);
    lua_setfield(L, -2, "normal");
    lua_pushnumber(L, (lua_Number)in->offset);
    lua_setfield(L, -2, "offset");
}

static void GenRead_b2CollisionPlane(lua_State *L, int idx, b2CollisionPlane *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "plane");
    GenRead_b2Plane(L, lua_gettop(L), &out->plane);
    lua_pop(L, 1);
    out->pushLimit = (float)SDLStaticGen_LuaFieldNum(L, idx, "pushLimit");
    out->push = (float)SDLStaticGen_LuaFieldNum(L, idx, "push");
    out->clipVelocity = (bool)SDLStaticGen_LuaFieldBool(L, idx, "clipVelocity");
}

static void GenPush_b2CollisionPlane(lua_State *L, const b2CollisionPlane *in)
{
    lua_createtable(L, 0, 4);
    GenPush_b2Plane(L, &in->plane);
    lua_setfield(L, -2, "plane");
    lua_pushnumber(L, (lua_Number)in->pushLimit);
    lua_setfield(L, -2, "pushLimit");
    lua_pushnumber(L, (lua_Number)in->push);
    lua_setfield(L, -2, "push");
    lua_pushboolean(L, (int)in->clipVelocity);
    lua_setfield(L, -2, "clipVelocity");
}

static void GenRead_b2ShapeId(lua_State *L, int idx, b2ShapeId *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->index1 = (int32_t)SDLStaticGen_LuaFieldInt(L, idx, "index1");
    out->world0 = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "world0");
    out->generation = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "generation");
}

static void GenPush_b2ShapeId(lua_State *L, const b2ShapeId *in)
{
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, (lua_Integer)in->index1);
    lua_setfield(L, -2, "index1");
    lua_pushinteger(L, (lua_Integer)in->world0);
    lua_setfield(L, -2, "world0");
    lua_pushinteger(L, (lua_Integer)in->generation);
    lua_setfield(L, -2, "generation");
}

static void GenPush_b2ManifoldPoint(lua_State *L, const b2ManifoldPoint *in)
{
    lua_createtable(L, 0, 10);
    GenPush_b2Vec2(L, &in->point);
    lua_setfield(L, -2, "point");
    GenPush_b2Vec2(L, &in->anchorA);
    lua_setfield(L, -2, "anchorA");
    GenPush_b2Vec2(L, &in->anchorB);
    lua_setfield(L, -2, "anchorB");
    lua_pushnumber(L, (lua_Number)in->separation);
    lua_setfield(L, -2, "separation");
    lua_pushnumber(L, (lua_Number)in->normalImpulse);
    lua_setfield(L, -2, "normalImpulse");
    lua_pushnumber(L, (lua_Number)in->tangentImpulse);
    lua_setfield(L, -2, "tangentImpulse");
    lua_pushnumber(L, (lua_Number)in->totalNormalImpulse);
    lua_setfield(L, -2, "totalNormalImpulse");
    lua_pushnumber(L, (lua_Number)in->normalVelocity);
    lua_setfield(L, -2, "normalVelocity");
    lua_pushinteger(L, (lua_Integer)in->id);
    lua_setfield(L, -2, "id");
    lua_pushboolean(L, (int)in->persisted);
    lua_setfield(L, -2, "persisted");
}

static void GenPush_b2Manifold(lua_State *L, const b2Manifold *in)
{
    lua_createtable(L, 0, 4);
    GenPush_b2Vec2(L, &in->normal);
    lua_setfield(L, -2, "normal");
    lua_pushnumber(L, (lua_Number)in->rollingImpulse);
    lua_setfield(L, -2, "rollingImpulse");
    lua_createtable(L, (int)(2), 0);
    for (int gi = 0; gi < (int)(2); ++gi) {
        GenPush_b2ManifoldPoint(L, &in->points[gi]);
        lua_rawseti(L, -2, gi + 1);
    }
    lua_setfield(L, -2, "points");
    lua_pushinteger(L, (lua_Integer)in->pointCount);
    lua_setfield(L, -2, "pointCount");
}

static void GenPush_b2ContactData(lua_State *L, const b2ContactData *in)
{
    lua_createtable(L, 0, 3);
    GenPush_b2ShapeId(L, &in->shapeIdA);
    lua_setfield(L, -2, "shapeIdA");
    GenPush_b2ShapeId(L, &in->shapeIdB);
    lua_setfield(L, -2, "shapeIdB");
    GenPush_b2Manifold(L, &in->manifold);
    lua_setfield(L, -2, "manifold");
}

static void GenPush_b2CosSin(lua_State *L, const b2CosSin *in)
{
    lua_createtable(L, 0, 2);
    lua_pushnumber(L, (lua_Number)in->cosine);
    lua_setfield(L, -2, "cosine");
    lua_pushnumber(L, (lua_Number)in->sine);
    lua_setfield(L, -2, "sine");
}

static void GenPush_b2Counters(lua_State *L, const b2Counters *in)
{
    lua_createtable(L, 0, 11);
    lua_pushinteger(L, (lua_Integer)in->bodyCount);
    lua_setfield(L, -2, "bodyCount");
    lua_pushinteger(L, (lua_Integer)in->shapeCount);
    lua_setfield(L, -2, "shapeCount");
    lua_pushinteger(L, (lua_Integer)in->contactCount);
    lua_setfield(L, -2, "contactCount");
    lua_pushinteger(L, (lua_Integer)in->jointCount);
    lua_setfield(L, -2, "jointCount");
    lua_pushinteger(L, (lua_Integer)in->islandCount);
    lua_setfield(L, -2, "islandCount");
    lua_pushinteger(L, (lua_Integer)in->stackUsed);
    lua_setfield(L, -2, "stackUsed");
    lua_pushinteger(L, (lua_Integer)in->staticTreeHeight);
    lua_setfield(L, -2, "staticTreeHeight");
    lua_pushinteger(L, (lua_Integer)in->treeHeight);
    lua_setfield(L, -2, "treeHeight");
    lua_pushinteger(L, (lua_Integer)in->byteCount);
    lua_setfield(L, -2, "byteCount");
    lua_pushinteger(L, (lua_Integer)in->taskCount);
    lua_setfield(L, -2, "taskCount");
    lua_createtable(L, (int)(12), 0);
    for (int gi = 0; gi < (int)(12); ++gi) {
        lua_pushinteger(L, (lua_Integer)in->colorCounts[gi]);
        lua_rawseti(L, -2, gi + 1);
    }
    lua_setfield(L, -2, "colorCounts");
}

static void GenRead_b2ShapeProxy(lua_State *L, int idx, b2ShapeProxy *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "points");
    if (lua_istable(L, -1)) {
        for (int gi = 0; gi < (int)(B2_MAX_POLYGON_VERTICES); ++gi) {
            lua_rawgeti(L, -1, gi + 1);
            GenRead_b2Vec2(L, lua_gettop(L), &out->points[gi]);
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);
    out->count = (int)SDLStaticGen_LuaFieldInt(L, idx, "count");
    out->radius = (float)SDLStaticGen_LuaFieldNum(L, idx, "radius");
}

static void GenPush_b2ShapeProxy(lua_State *L, const b2ShapeProxy *in)
{
    lua_createtable(L, 0, 3);
    lua_createtable(L, (int)(B2_MAX_POLYGON_VERTICES), 0);
    for (int gi = 0; gi < (int)(B2_MAX_POLYGON_VERTICES); ++gi) {
        GenPush_b2Vec2(L, &in->points[gi]);
        lua_rawseti(L, -2, gi + 1);
    }
    lua_setfield(L, -2, "points");
    lua_pushinteger(L, (lua_Integer)in->count);
    lua_setfield(L, -2, "count");
    lua_pushnumber(L, (lua_Number)in->radius);
    lua_setfield(L, -2, "radius");
}

static void GenRead_b2Transform(lua_State *L, int idx, b2Transform *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "p");
    GenRead_b2Vec2(L, lua_gettop(L), &out->p);
    lua_pop(L, 1);
    lua_getfield(L, idx, "q");
    GenRead_b2Rot(L, lua_gettop(L), &out->q);
    lua_pop(L, 1);
}

static void GenPush_b2Transform(lua_State *L, const b2Transform *in)
{
    lua_createtable(L, 0, 2);
    GenPush_b2Vec2(L, &in->p);
    lua_setfield(L, -2, "p");
    GenPush_b2Rot(L, &in->q);
    lua_setfield(L, -2, "q");
}

static void GenRead_b2DistanceInput(lua_State *L, int idx, b2DistanceInput *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "proxyA");
    GenRead_b2ShapeProxy(L, lua_gettop(L), &out->proxyA);
    lua_pop(L, 1);
    lua_getfield(L, idx, "proxyB");
    GenRead_b2ShapeProxy(L, lua_gettop(L), &out->proxyB);
    lua_pop(L, 1);
    lua_getfield(L, idx, "transformA");
    GenRead_b2Transform(L, lua_gettop(L), &out->transformA);
    lua_pop(L, 1);
    lua_getfield(L, idx, "transformB");
    GenRead_b2Transform(L, lua_gettop(L), &out->transformB);
    lua_pop(L, 1);
    out->useRadii = (bool)SDLStaticGen_LuaFieldBool(L, idx, "useRadii");
}

static void GenPush_b2DistanceOutput(lua_State *L, const b2DistanceOutput *in)
{
    lua_createtable(L, 0, 6);
    GenPush_b2Vec2(L, &in->pointA);
    lua_setfield(L, -2, "pointA");
    GenPush_b2Vec2(L, &in->pointB);
    lua_setfield(L, -2, "pointB");
    GenPush_b2Vec2(L, &in->normal);
    lua_setfield(L, -2, "normal");
    lua_pushnumber(L, (lua_Number)in->distance);
    lua_setfield(L, -2, "distance");
    lua_pushinteger(L, (lua_Integer)in->iterations);
    lua_setfield(L, -2, "iterations");
    lua_pushinteger(L, (lua_Integer)in->simplexCount);
    lua_setfield(L, -2, "simplexCount");
}

static void GenRead_b2ExplosionDef(lua_State *L, int idx, b2ExplosionDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->maskBits = (uint64_t)SDLStaticGen_LuaFieldInt(L, idx, "maskBits");
    lua_getfield(L, idx, "position");
    GenRead_b2Vec2(L, lua_gettop(L), &out->position);
    lua_pop(L, 1);
    out->radius = (float)SDLStaticGen_LuaFieldNum(L, idx, "radius");
    out->falloff = (float)SDLStaticGen_LuaFieldNum(L, idx, "falloff");
    out->impulsePerLength = (float)SDLStaticGen_LuaFieldNum(L, idx, "impulsePerLength");
}

static void GenPush_b2ExplosionDef(lua_State *L, const b2ExplosionDef *in)
{
    lua_createtable(L, 0, 5);
    lua_pushinteger(L, (lua_Integer)in->maskBits);
    lua_setfield(L, -2, "maskBits");
    GenPush_b2Vec2(L, &in->position);
    lua_setfield(L, -2, "position");
    lua_pushnumber(L, (lua_Number)in->radius);
    lua_setfield(L, -2, "radius");
    lua_pushnumber(L, (lua_Number)in->falloff);
    lua_setfield(L, -2, "falloff");
    lua_pushnumber(L, (lua_Number)in->impulsePerLength);
    lua_setfield(L, -2, "impulsePerLength");
}

static void GenPush_b2Hull(lua_State *L, const b2Hull *in)
{
    lua_createtable(L, 0, 2);
    lua_createtable(L, (int)(B2_MAX_POLYGON_VERTICES), 0);
    for (int gi = 0; gi < (int)(B2_MAX_POLYGON_VERTICES); ++gi) {
        GenPush_b2Vec2(L, &in->points[gi]);
        lua_rawseti(L, -2, gi + 1);
    }
    lua_setfield(L, -2, "points");
    lua_pushinteger(L, (lua_Integer)in->count);
    lua_setfield(L, -2, "count");
}

static void GenRead_b2JointId(lua_State *L, int idx, b2JointId *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->index1 = (int32_t)SDLStaticGen_LuaFieldInt(L, idx, "index1");
    out->world0 = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "world0");
    out->generation = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "generation");
}

static void GenPush_b2JointId(lua_State *L, const b2JointId *in)
{
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, (lua_Integer)in->index1);
    lua_setfield(L, -2, "index1");
    lua_pushinteger(L, (lua_Integer)in->world0);
    lua_setfield(L, -2, "world0");
    lua_pushinteger(L, (lua_Integer)in->generation);
    lua_setfield(L, -2, "generation");
}

static void GenRead_b2MassData(lua_State *L, int idx, b2MassData *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->mass = (float)SDLStaticGen_LuaFieldNum(L, idx, "mass");
    lua_getfield(L, idx, "center");
    GenRead_b2Vec2(L, lua_gettop(L), &out->center);
    lua_pop(L, 1);
    out->rotationalInertia = (float)SDLStaticGen_LuaFieldNum(L, idx, "rotationalInertia");
}

static void GenPush_b2MassData(lua_State *L, const b2MassData *in)
{
    lua_createtable(L, 0, 3);
    lua_pushnumber(L, (lua_Number)in->mass);
    lua_setfield(L, -2, "mass");
    GenPush_b2Vec2(L, &in->center);
    lua_setfield(L, -2, "center");
    lua_pushnumber(L, (lua_Number)in->rotationalInertia);
    lua_setfield(L, -2, "rotationalInertia");
}

static void GenPush_b2PlaneSolverResult(lua_State *L, const b2PlaneSolverResult *in)
{
    lua_createtable(L, 0, 2);
    GenPush_b2Vec2(L, &in->translation);
    lua_setfield(L, -2, "translation");
    lua_pushinteger(L, (lua_Integer)in->iterationCount);
    lua_setfield(L, -2, "iterationCount");
}

static void GenRead_b2Polygon(lua_State *L, int idx, b2Polygon *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "vertices");
    if (lua_istable(L, -1)) {
        for (int gi = 0; gi < (int)(B2_MAX_POLYGON_VERTICES); ++gi) {
            lua_rawgeti(L, -1, gi + 1);
            GenRead_b2Vec2(L, lua_gettop(L), &out->vertices[gi]);
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);
    lua_getfield(L, idx, "normals");
    if (lua_istable(L, -1)) {
        for (int gi = 0; gi < (int)(B2_MAX_POLYGON_VERTICES); ++gi) {
            lua_rawgeti(L, -1, gi + 1);
            GenRead_b2Vec2(L, lua_gettop(L), &out->normals[gi]);
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);
    lua_getfield(L, idx, "centroid");
    GenRead_b2Vec2(L, lua_gettop(L), &out->centroid);
    lua_pop(L, 1);
    out->radius = (float)SDLStaticGen_LuaFieldNum(L, idx, "radius");
    out->count = (int)SDLStaticGen_LuaFieldInt(L, idx, "count");
}

static void GenPush_b2Polygon(lua_State *L, const b2Polygon *in)
{
    lua_createtable(L, 0, 5);
    lua_createtable(L, (int)(B2_MAX_POLYGON_VERTICES), 0);
    for (int gi = 0; gi < (int)(B2_MAX_POLYGON_VERTICES); ++gi) {
        GenPush_b2Vec2(L, &in->vertices[gi]);
        lua_rawseti(L, -2, gi + 1);
    }
    lua_setfield(L, -2, "vertices");
    lua_createtable(L, (int)(B2_MAX_POLYGON_VERTICES), 0);
    for (int gi = 0; gi < (int)(B2_MAX_POLYGON_VERTICES); ++gi) {
        GenPush_b2Vec2(L, &in->normals[gi]);
        lua_rawseti(L, -2, gi + 1);
    }
    lua_setfield(L, -2, "normals");
    GenPush_b2Vec2(L, &in->centroid);
    lua_setfield(L, -2, "centroid");
    lua_pushnumber(L, (lua_Number)in->radius);
    lua_setfield(L, -2, "radius");
    lua_pushinteger(L, (lua_Integer)in->count);
    lua_setfield(L, -2, "count");
}

static void GenPush_b2Profile(lua_State *L, const b2Profile *in)
{
    lua_createtable(L, 0, 22);
    lua_pushnumber(L, (lua_Number)in->step);
    lua_setfield(L, -2, "step");
    lua_pushnumber(L, (lua_Number)in->pairs);
    lua_setfield(L, -2, "pairs");
    lua_pushnumber(L, (lua_Number)in->collide);
    lua_setfield(L, -2, "collide");
    lua_pushnumber(L, (lua_Number)in->solve);
    lua_setfield(L, -2, "solve");
    lua_pushnumber(L, (lua_Number)in->mergeIslands);
    lua_setfield(L, -2, "mergeIslands");
    lua_pushnumber(L, (lua_Number)in->prepareStages);
    lua_setfield(L, -2, "prepareStages");
    lua_pushnumber(L, (lua_Number)in->solveConstraints);
    lua_setfield(L, -2, "solveConstraints");
    lua_pushnumber(L, (lua_Number)in->prepareConstraints);
    lua_setfield(L, -2, "prepareConstraints");
    lua_pushnumber(L, (lua_Number)in->integrateVelocities);
    lua_setfield(L, -2, "integrateVelocities");
    lua_pushnumber(L, (lua_Number)in->warmStart);
    lua_setfield(L, -2, "warmStart");
    lua_pushnumber(L, (lua_Number)in->solveImpulses);
    lua_setfield(L, -2, "solveImpulses");
    lua_pushnumber(L, (lua_Number)in->integratePositions);
    lua_setfield(L, -2, "integratePositions");
    lua_pushnumber(L, (lua_Number)in->relaxImpulses);
    lua_setfield(L, -2, "relaxImpulses");
    lua_pushnumber(L, (lua_Number)in->applyRestitution);
    lua_setfield(L, -2, "applyRestitution");
    lua_pushnumber(L, (lua_Number)in->storeImpulses);
    lua_setfield(L, -2, "storeImpulses");
    lua_pushnumber(L, (lua_Number)in->splitIslands);
    lua_setfield(L, -2, "splitIslands");
    lua_pushnumber(L, (lua_Number)in->transforms);
    lua_setfield(L, -2, "transforms");
    lua_pushnumber(L, (lua_Number)in->hitEvents);
    lua_setfield(L, -2, "hitEvents");
    lua_pushnumber(L, (lua_Number)in->refit);
    lua_setfield(L, -2, "refit");
    lua_pushnumber(L, (lua_Number)in->bullets);
    lua_setfield(L, -2, "bullets");
    lua_pushnumber(L, (lua_Number)in->sleepIslands);
    lua_setfield(L, -2, "sleepIslands");
    lua_pushnumber(L, (lua_Number)in->sensors);
    lua_setfield(L, -2, "sensors");
}

static void GenRead_b2QueryFilter(lua_State *L, int idx, b2QueryFilter *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->categoryBits = (uint64_t)SDLStaticGen_LuaFieldInt(L, idx, "categoryBits");
    out->maskBits = (uint64_t)SDLStaticGen_LuaFieldInt(L, idx, "maskBits");
}

static void GenPush_b2QueryFilter(lua_State *L, const b2QueryFilter *in)
{
    lua_createtable(L, 0, 2);
    lua_pushinteger(L, (lua_Integer)in->categoryBits);
    lua_setfield(L, -2, "categoryBits");
    lua_pushinteger(L, (lua_Integer)in->maskBits);
    lua_setfield(L, -2, "maskBits");
}

static void GenRead_b2RayCastInput(lua_State *L, int idx, b2RayCastInput *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "origin");
    GenRead_b2Vec2(L, lua_gettop(L), &out->origin);
    lua_pop(L, 1);
    lua_getfield(L, idx, "translation");
    GenRead_b2Vec2(L, lua_gettop(L), &out->translation);
    lua_pop(L, 1);
    out->maxFraction = (float)SDLStaticGen_LuaFieldNum(L, idx, "maxFraction");
}

static void GenPush_b2RayResult(lua_State *L, const b2RayResult *in)
{
    lua_createtable(L, 0, 7);
    GenPush_b2ShapeId(L, &in->shapeId);
    lua_setfield(L, -2, "shapeId");
    GenPush_b2Vec2(L, &in->point);
    lua_setfield(L, -2, "point");
    GenPush_b2Vec2(L, &in->normal);
    lua_setfield(L, -2, "normal");
    lua_pushnumber(L, (lua_Number)in->fraction);
    lua_setfield(L, -2, "fraction");
    lua_pushinteger(L, (lua_Integer)in->nodeVisits);
    lua_setfield(L, -2, "nodeVisits");
    lua_pushinteger(L, (lua_Integer)in->leafVisits);
    lua_setfield(L, -2, "leafVisits");
    lua_pushboolean(L, (int)in->hit);
    lua_setfield(L, -2, "hit");
}

static void GenPush_b2SegmentDistanceResult(lua_State *L, const b2SegmentDistanceResult *in)
{
    lua_createtable(L, 0, 5);
    GenPush_b2Vec2(L, &in->closest1);
    lua_setfield(L, -2, "closest1");
    GenPush_b2Vec2(L, &in->closest2);
    lua_setfield(L, -2, "closest2");
    lua_pushnumber(L, (lua_Number)in->fraction1);
    lua_setfield(L, -2, "fraction1");
    lua_pushnumber(L, (lua_Number)in->fraction2);
    lua_setfield(L, -2, "fraction2");
    lua_pushnumber(L, (lua_Number)in->distanceSquared);
    lua_setfield(L, -2, "distanceSquared");
}

static void GenRead_b2ShapeCastInput(lua_State *L, int idx, b2ShapeCastInput *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "proxy");
    GenRead_b2ShapeProxy(L, lua_gettop(L), &out->proxy);
    lua_pop(L, 1);
    lua_getfield(L, idx, "translation");
    GenRead_b2Vec2(L, lua_gettop(L), &out->translation);
    lua_pop(L, 1);
    out->maxFraction = (float)SDLStaticGen_LuaFieldNum(L, idx, "maxFraction");
    out->canEncroach = (bool)SDLStaticGen_LuaFieldBool(L, idx, "canEncroach");
}

static void GenRead_b2ShapeCastPairInput(lua_State *L, int idx, b2ShapeCastPairInput *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "proxyA");
    GenRead_b2ShapeProxy(L, lua_gettop(L), &out->proxyA);
    lua_pop(L, 1);
    lua_getfield(L, idx, "proxyB");
    GenRead_b2ShapeProxy(L, lua_gettop(L), &out->proxyB);
    lua_pop(L, 1);
    lua_getfield(L, idx, "transformA");
    GenRead_b2Transform(L, lua_gettop(L), &out->transformA);
    lua_pop(L, 1);
    lua_getfield(L, idx, "transformB");
    GenRead_b2Transform(L, lua_gettop(L), &out->transformB);
    lua_pop(L, 1);
    lua_getfield(L, idx, "translationB");
    GenRead_b2Vec2(L, lua_gettop(L), &out->translationB);
    lua_pop(L, 1);
    out->maxFraction = (float)SDLStaticGen_LuaFieldNum(L, idx, "maxFraction");
    out->canEncroach = (bool)SDLStaticGen_LuaFieldBool(L, idx, "canEncroach");
}

static void GenRead_b2ShapeDef(lua_State *L, int idx, b2ShapeDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "material");
    GenRead_b2SurfaceMaterial(L, lua_gettop(L), &out->material);
    lua_pop(L, 1);
    out->density = (float)SDLStaticGen_LuaFieldNum(L, idx, "density");
    lua_getfield(L, idx, "filter");
    GenRead_b2Filter(L, lua_gettop(L), &out->filter);
    lua_pop(L, 1);
    out->isSensor = (bool)SDLStaticGen_LuaFieldBool(L, idx, "isSensor");
    out->enableSensorEvents = (bool)SDLStaticGen_LuaFieldBool(L, idx, "enableSensorEvents");
    out->enableContactEvents = (bool)SDLStaticGen_LuaFieldBool(L, idx, "enableContactEvents");
    out->enableHitEvents = (bool)SDLStaticGen_LuaFieldBool(L, idx, "enableHitEvents");
    out->enablePreSolveEvents = (bool)SDLStaticGen_LuaFieldBool(L, idx, "enablePreSolveEvents");
    out->invokeContactCreation = (bool)SDLStaticGen_LuaFieldBool(L, idx, "invokeContactCreation");
    out->updateBodyMass = (bool)SDLStaticGen_LuaFieldBool(L, idx, "updateBodyMass");
    out->internalValue = (int)SDLStaticGen_LuaFieldInt(L, idx, "internalValue");
}

static void GenPush_b2ShapeDef(lua_State *L, const b2ShapeDef *in)
{
    lua_createtable(L, 0, 12);
    GenPush_b2SurfaceMaterial(L, &in->material);
    lua_setfield(L, -2, "material");
    lua_pushnumber(L, (lua_Number)in->density);
    lua_setfield(L, -2, "density");
    GenPush_b2Filter(L, &in->filter);
    lua_setfield(L, -2, "filter");
    lua_pushboolean(L, (int)in->isSensor);
    lua_setfield(L, -2, "isSensor");
    lua_pushboolean(L, (int)in->enableSensorEvents);
    lua_setfield(L, -2, "enableSensorEvents");
    lua_pushboolean(L, (int)in->enableContactEvents);
    lua_setfield(L, -2, "enableContactEvents");
    lua_pushboolean(L, (int)in->enableHitEvents);
    lua_setfield(L, -2, "enableHitEvents");
    lua_pushboolean(L, (int)in->enablePreSolveEvents);
    lua_setfield(L, -2, "enablePreSolveEvents");
    lua_pushboolean(L, (int)in->invokeContactCreation);
    lua_setfield(L, -2, "invokeContactCreation");
    lua_pushboolean(L, (int)in->updateBodyMass);
    lua_setfield(L, -2, "updateBodyMass");
    lua_pushinteger(L, (lua_Integer)in->internalValue);
    lua_setfield(L, -2, "internalValue");
}

static void GenPush_b2SimplexVertex(lua_State *L, const b2SimplexVertex *in)
{
    lua_createtable(L, 0, 6);
    GenPush_b2Vec2(L, &in->wA);
    lua_setfield(L, -2, "wA");
    GenPush_b2Vec2(L, &in->wB);
    lua_setfield(L, -2, "wB");
    GenPush_b2Vec2(L, &in->w);
    lua_setfield(L, -2, "w");
    lua_pushnumber(L, (lua_Number)in->a);
    lua_setfield(L, -2, "a");
    lua_pushinteger(L, (lua_Integer)in->indexA);
    lua_setfield(L, -2, "indexA");
    lua_pushinteger(L, (lua_Integer)in->indexB);
    lua_setfield(L, -2, "indexB");
}

static void GenPush_b2Simplex(lua_State *L, const b2Simplex *in)
{
    lua_createtable(L, 0, 4);
    GenPush_b2SimplexVertex(L, &in->v1);
    lua_setfield(L, -2, "v1");
    GenPush_b2SimplexVertex(L, &in->v2);
    lua_setfield(L, -2, "v2");
    GenPush_b2SimplexVertex(L, &in->v3);
    lua_setfield(L, -2, "v3");
    lua_pushinteger(L, (lua_Integer)in->count);
    lua_setfield(L, -2, "count");
}

static void GenRead_b2Sweep(lua_State *L, int idx, b2Sweep *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "localCenter");
    GenRead_b2Vec2(L, lua_gettop(L), &out->localCenter);
    lua_pop(L, 1);
    lua_getfield(L, idx, "c1");
    GenRead_b2Vec2(L, lua_gettop(L), &out->c1);
    lua_pop(L, 1);
    lua_getfield(L, idx, "c2");
    GenRead_b2Vec2(L, lua_gettop(L), &out->c2);
    lua_pop(L, 1);
    lua_getfield(L, idx, "q1");
    GenRead_b2Rot(L, lua_gettop(L), &out->q1);
    lua_pop(L, 1);
    lua_getfield(L, idx, "q2");
    GenRead_b2Rot(L, lua_gettop(L), &out->q2);
    lua_pop(L, 1);
}

static void GenRead_b2TOIInput(lua_State *L, int idx, b2TOIInput *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "proxyA");
    GenRead_b2ShapeProxy(L, lua_gettop(L), &out->proxyA);
    lua_pop(L, 1);
    lua_getfield(L, idx, "proxyB");
    GenRead_b2ShapeProxy(L, lua_gettop(L), &out->proxyB);
    lua_pop(L, 1);
    lua_getfield(L, idx, "sweepA");
    GenRead_b2Sweep(L, lua_gettop(L), &out->sweepA);
    lua_pop(L, 1);
    lua_getfield(L, idx, "sweepB");
    GenRead_b2Sweep(L, lua_gettop(L), &out->sweepB);
    lua_pop(L, 1);
    out->maxFraction = (float)SDLStaticGen_LuaFieldNum(L, idx, "maxFraction");
}

static void GenPush_b2TOIOutput(lua_State *L, const b2TOIOutput *in)
{
    lua_createtable(L, 0, 2);
    lua_pushinteger(L, (lua_Integer)in->state);
    lua_setfield(L, -2, "state");
    lua_pushnumber(L, (lua_Number)in->fraction);
    lua_setfield(L, -2, "fraction");
}

static void GenPush_b2Version(lua_State *L, const b2Version *in)
{
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, (lua_Integer)in->major);
    lua_setfield(L, -2, "major");
    lua_pushinteger(L, (lua_Integer)in->minor);
    lua_setfield(L, -2, "minor");
    lua_pushinteger(L, (lua_Integer)in->revision);
    lua_setfield(L, -2, "revision");
}

static void GenRead_b2WorldDef(lua_State *L, int idx, b2WorldDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    lua_getfield(L, idx, "gravity");
    GenRead_b2Vec2(L, lua_gettop(L), &out->gravity);
    lua_pop(L, 1);
    out->restitutionThreshold = (float)SDLStaticGen_LuaFieldNum(L, idx, "restitutionThreshold");
    out->hitEventThreshold = (float)SDLStaticGen_LuaFieldNum(L, idx, "hitEventThreshold");
    out->contactHertz = (float)SDLStaticGen_LuaFieldNum(L, idx, "contactHertz");
    out->contactDampingRatio = (float)SDLStaticGen_LuaFieldNum(L, idx, "contactDampingRatio");
    out->maxContactPushSpeed = (float)SDLStaticGen_LuaFieldNum(L, idx, "maxContactPushSpeed");
    out->maximumLinearSpeed = (float)SDLStaticGen_LuaFieldNum(L, idx, "maximumLinearSpeed");
    out->enableSleep = (bool)SDLStaticGen_LuaFieldBool(L, idx, "enableSleep");
    out->enableContinuous = (bool)SDLStaticGen_LuaFieldBool(L, idx, "enableContinuous");
    out->workerCount = (int)SDLStaticGen_LuaFieldInt(L, idx, "workerCount");
    out->internalValue = (int)SDLStaticGen_LuaFieldInt(L, idx, "internalValue");
}

static void GenPush_b2WorldDef(lua_State *L, const b2WorldDef *in)
{
    lua_createtable(L, 0, 17);
    GenPush_b2Vec2(L, &in->gravity);
    lua_setfield(L, -2, "gravity");
    lua_pushnumber(L, (lua_Number)in->restitutionThreshold);
    lua_setfield(L, -2, "restitutionThreshold");
    lua_pushnumber(L, (lua_Number)in->hitEventThreshold);
    lua_setfield(L, -2, "hitEventThreshold");
    lua_pushnumber(L, (lua_Number)in->contactHertz);
    lua_setfield(L, -2, "contactHertz");
    lua_pushnumber(L, (lua_Number)in->contactDampingRatio);
    lua_setfield(L, -2, "contactDampingRatio");
    lua_pushnumber(L, (lua_Number)in->maxContactPushSpeed);
    lua_setfield(L, -2, "maxContactPushSpeed");
    lua_pushnumber(L, (lua_Number)in->maximumLinearSpeed);
    lua_setfield(L, -2, "maximumLinearSpeed");
    lua_pushboolean(L, (int)in->enableSleep);
    lua_setfield(L, -2, "enableSleep");
    lua_pushboolean(L, (int)in->enableContinuous);
    lua_setfield(L, -2, "enableContinuous");
    lua_pushinteger(L, (lua_Integer)in->workerCount);
    lua_setfield(L, -2, "workerCount");
    lua_pushinteger(L, (lua_Integer)in->internalValue);
    lua_setfield(L, -2, "internalValue");
}

static void GenRead_b2WorldId(lua_State *L, int idx, b2WorldId *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->index1 = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "index1");
    out->generation = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "generation");
}

static void GenPush_b2WorldId(lua_State *L, const b2WorldId *in)
{
    lua_createtable(L, 0, 2);
    lua_pushinteger(L, (lua_Integer)in->index1);
    lua_setfield(L, -2, "index1");
    lua_pushinteger(L, (lua_Integer)in->generation);
    lua_setfield(L, -2, "generation");
}

static int GenL_b2Atan2(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    float rv = b2Atan2(a0, a1);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Body_ApplyAngularImpulse(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    bool a2 = (bool)lua_toboolean(L, 3);
    b2Body_ApplyAngularImpulse(a0, a1, a2);
    return 0;
}

static int GenL_b2Body_ApplyForce(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Vec2 a2;
    GenRead_b2Vec2(L, 3, &a2);
    bool a3 = (bool)lua_toboolean(L, 4);
    b2Body_ApplyForce(a0, a1, a2, a3);
    return 0;
}

static int GenL_b2Body_ApplyForceToCenter(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    bool a2 = (bool)lua_toboolean(L, 3);
    b2Body_ApplyForceToCenter(a0, a1, a2);
    return 0;
}

static int GenL_b2Body_ApplyLinearImpulse(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Vec2 a2;
    GenRead_b2Vec2(L, 3, &a2);
    bool a3 = (bool)lua_toboolean(L, 4);
    b2Body_ApplyLinearImpulse(a0, a1, a2, a3);
    return 0;
}

static int GenL_b2Body_ApplyLinearImpulseToCenter(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    bool a2 = (bool)lua_toboolean(L, 3);
    b2Body_ApplyLinearImpulseToCenter(a0, a1, a2);
    return 0;
}

static int GenL_b2Body_ApplyMassFromShapes(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Body_ApplyMassFromShapes(a0);
    return 0;
}

static int GenL_b2Body_ApplyTorque(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    bool a2 = (bool)lua_toboolean(L, 3);
    b2Body_ApplyTorque(a0, a1, a2);
    return 0;
}

static int GenL_b2Body_ComputeAABB(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2AABB rv = b2Body_ComputeAABB(a0);
    GenPush_b2AABB(L, &rv);
    return 1;
}

static int GenL_b2Body_Disable(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Body_Disable(a0);
    return 0;
}

static int GenL_b2Body_Enable(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Body_Enable(a0);
    return 0;
}

static int GenL_b2Body_EnableContactEvents(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2Body_EnableContactEvents(a0, a1);
    return 0;
}

static int GenL_b2Body_EnableHitEvents(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2Body_EnableHitEvents(a0, a1);
    return 0;
}

static int GenL_b2Body_EnableSleep(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2Body_EnableSleep(a0, a1);
    return 0;
}

static int GenL_b2Body_GetAngularDamping(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float rv = b2Body_GetAngularDamping(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Body_GetAngularVelocity(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float rv = b2Body_GetAngularVelocity(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Body_GetContactCapacity(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    int rv = b2Body_GetContactCapacity(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2Body_GetContactData(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2ContactData out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)luaL_checkinteger(L, 2);
    int rv = b2Body_GetContactData(a0, &out1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_b2ContactData(L, &out1);
    return 2;
}

static int GenL_b2Body_GetGravityScale(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float rv = b2Body_GetGravityScale(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Body_GetJointCount(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    int rv = b2Body_GetJointCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2Body_GetJoints(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2JointId out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)luaL_checkinteger(L, 2);
    int rv = b2Body_GetJoints(a0, &out1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_b2JointId(L, &out1);
    return 2;
}

static int GenL_b2Body_GetLinearDamping(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float rv = b2Body_GetLinearDamping(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Body_GetLinearVelocity(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 rv = b2Body_GetLinearVelocity(a0);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Body_GetLocalCenterOfMass(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 rv = b2Body_GetLocalCenterOfMass(a0);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Body_GetLocalPoint(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Vec2 rv = b2Body_GetLocalPoint(a0, a1);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Body_GetLocalPointVelocity(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Vec2 rv = b2Body_GetLocalPointVelocity(a0, a1);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Body_GetLocalVector(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Vec2 rv = b2Body_GetLocalVector(a0, a1);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Body_GetMass(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float rv = b2Body_GetMass(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Body_GetMassData(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2MassData rv = b2Body_GetMassData(a0);
    GenPush_b2MassData(L, &rv);
    return 1;
}

static int GenL_b2Body_GetName(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    const char * rv = b2Body_GetName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_b2Body_GetPosition(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 rv = b2Body_GetPosition(a0);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Body_GetRotation(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Rot rv = b2Body_GetRotation(a0);
    GenPush_b2Rot(L, &rv);
    return 1;
}

static int GenL_b2Body_GetRotationalInertia(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float rv = b2Body_GetRotationalInertia(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Body_GetShapeCount(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    int rv = b2Body_GetShapeCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2Body_GetShapes(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2ShapeId out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)luaL_checkinteger(L, 2);
    int rv = b2Body_GetShapes(a0, &out1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_b2ShapeId(L, &out1);
    return 2;
}

static int GenL_b2Body_GetSleepThreshold(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float rv = b2Body_GetSleepThreshold(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Body_GetTransform(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Transform rv = b2Body_GetTransform(a0);
    GenPush_b2Transform(L, &rv);
    return 1;
}

static int GenL_b2Body_GetType(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2BodyType rv = b2Body_GetType(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2Body_GetWorld(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2WorldId rv = b2Body_GetWorld(a0);
    GenPush_b2WorldId(L, &rv);
    return 1;
}

static int GenL_b2Body_GetWorldCenterOfMass(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 rv = b2Body_GetWorldCenterOfMass(a0);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Body_GetWorldPoint(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Vec2 rv = b2Body_GetWorldPoint(a0, a1);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Body_GetWorldPointVelocity(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Vec2 rv = b2Body_GetWorldPointVelocity(a0, a1);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Body_GetWorldVector(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Vec2 rv = b2Body_GetWorldVector(a0, a1);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Body_IsAwake(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool rv = b2Body_IsAwake(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Body_IsBullet(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool rv = b2Body_IsBullet(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Body_IsEnabled(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool rv = b2Body_IsEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Body_IsFixedRotation(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool rv = b2Body_IsFixedRotation(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Body_IsSleepEnabled(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool rv = b2Body_IsSleepEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Body_IsValid(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool rv = b2Body_IsValid(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Body_SetAngularDamping(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Body_SetAngularDamping(a0, a1);
    return 0;
}

static int GenL_b2Body_SetAngularVelocity(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Body_SetAngularVelocity(a0, a1);
    return 0;
}

static int GenL_b2Body_SetAwake(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2Body_SetAwake(a0, a1);
    return 0;
}

static int GenL_b2Body_SetBullet(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2Body_SetBullet(a0, a1);
    return 0;
}

static int GenL_b2Body_SetFixedRotation(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2Body_SetFixedRotation(a0, a1);
    return 0;
}

static int GenL_b2Body_SetGravityScale(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Body_SetGravityScale(a0, a1);
    return 0;
}

static int GenL_b2Body_SetLinearDamping(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Body_SetLinearDamping(a0, a1);
    return 0;
}

static int GenL_b2Body_SetLinearVelocity(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Body_SetLinearVelocity(a0, a1);
    return 0;
}

static int GenL_b2Body_SetMassData(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2MassData a1;
    GenRead_b2MassData(L, 2, &a1);
    b2Body_SetMassData(a0, a1);
    return 0;
}

static int GenL_b2Body_SetName(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    b2Body_SetName(a0, a1);
    return 0;
}

static int GenL_b2Body_SetSleepThreshold(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Body_SetSleepThreshold(a0, a1);
    return 0;
}

static int GenL_b2Body_SetTargetTransform(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    float a2 = (float)luaL_checknumber(L, 3);
    b2Body_SetTargetTransform(a0, a1, a2);
    return 0;
}

static int GenL_b2Body_SetTransform(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Rot a2;
    GenRead_b2Rot(L, 3, &a2);
    b2Body_SetTransform(a0, a1, a2);
    return 0;
}

static int GenL_b2Body_SetType(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2BodyType a1 = (b2BodyType)luaL_checkinteger(L, 2);
    b2Body_SetType(a0, a1);
    return 0;
}

static int GenL_b2Chain_GetFriction(lua_State *L)
{
    (void)L;
    b2ChainId a0;
    GenRead_b2ChainId(L, 1, &a0);
    float rv = b2Chain_GetFriction(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Chain_GetMaterial(lua_State *L)
{
    (void)L;
    b2ChainId a0;
    GenRead_b2ChainId(L, 1, &a0);
    int rv = b2Chain_GetMaterial(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2Chain_GetRestitution(lua_State *L)
{
    (void)L;
    b2ChainId a0;
    GenRead_b2ChainId(L, 1, &a0);
    float rv = b2Chain_GetRestitution(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Chain_GetSegmentCount(lua_State *L)
{
    (void)L;
    b2ChainId a0;
    GenRead_b2ChainId(L, 1, &a0);
    int rv = b2Chain_GetSegmentCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2Chain_GetSegments(lua_State *L)
{
    (void)L;
    b2ChainId a0;
    GenRead_b2ChainId(L, 1, &a0);
    b2ShapeId out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)luaL_checkinteger(L, 2);
    int rv = b2Chain_GetSegments(a0, &out1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_b2ShapeId(L, &out1);
    return 2;
}

static int GenL_b2Chain_GetWorld(lua_State *L)
{
    (void)L;
    b2ChainId a0;
    GenRead_b2ChainId(L, 1, &a0);
    b2WorldId rv = b2Chain_GetWorld(a0);
    GenPush_b2WorldId(L, &rv);
    return 1;
}

static int GenL_b2Chain_IsValid(lua_State *L)
{
    (void)L;
    b2ChainId a0;
    GenRead_b2ChainId(L, 1, &a0);
    bool rv = b2Chain_IsValid(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Chain_SetFriction(lua_State *L)
{
    (void)L;
    b2ChainId a0;
    GenRead_b2ChainId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Chain_SetFriction(a0, a1);
    return 0;
}

static int GenL_b2Chain_SetMaterial(lua_State *L)
{
    (void)L;
    b2ChainId a0;
    GenRead_b2ChainId(L, 1, &a0);
    int a1 = (int)luaL_checkinteger(L, 2);
    b2Chain_SetMaterial(a0, a1);
    return 0;
}

static int GenL_b2Chain_SetRestitution(lua_State *L)
{
    (void)L;
    b2ChainId a0;
    GenRead_b2ChainId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Chain_SetRestitution(a0, a1);
    return 0;
}

static int GenL_b2ClipVector(lua_State *L)
{
    (void)L;
    b2Vec2 a0;
    GenRead_b2Vec2(L, 1, &a0);
    b2CollisionPlane tmp1;
    const b2CollisionPlane *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2CollisionPlane(L, 2, &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)luaL_checkinteger(L, 3);
    b2Vec2 rv = b2ClipVector(a0, a1, a2);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2CollideCapsuleAndCircle(lua_State *L)
{
    (void)L;
    b2Capsule tmp0;
    const b2Capsule *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Capsule(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Circle(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2Manifold rv = b2CollideCapsuleAndCircle(a0, a1, a2, a3);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2CollideCapsules(lua_State *L)
{
    (void)L;
    b2Capsule tmp0;
    const b2Capsule *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Capsule(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Capsule tmp2;
    const b2Capsule *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Capsule(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2Manifold rv = b2CollideCapsules(a0, a1, a2, a3);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2CollideChainSegmentAndCapsule(lua_State *L)
{
    (void)L;
    b2ChainSegment tmp0;
    const b2ChainSegment *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2ChainSegment(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Capsule tmp2;
    const b2Capsule *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Capsule(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2SimplexCache *a4 = (b2SimplexCache *)SDLStaticGen_LuaCheckHandle(L, 5, "b2SimplexCache");
    b2Manifold rv = b2CollideChainSegmentAndCapsule(a0, a1, a2, a3, a4);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2CollideChainSegmentAndCircle(lua_State *L)
{
    (void)L;
    b2ChainSegment tmp0;
    const b2ChainSegment *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2ChainSegment(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Circle(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2Manifold rv = b2CollideChainSegmentAndCircle(a0, a1, a2, a3);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2CollideChainSegmentAndPolygon(lua_State *L)
{
    (void)L;
    b2ChainSegment tmp0;
    const b2ChainSegment *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2ChainSegment(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Polygon tmp2;
    const b2Polygon *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Polygon(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2SimplexCache *a4 = (b2SimplexCache *)SDLStaticGen_LuaCheckHandle(L, 5, "b2SimplexCache");
    b2Manifold rv = b2CollideChainSegmentAndPolygon(a0, a1, a2, a3, a4);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2CollideCircles(lua_State *L)
{
    (void)L;
    b2Circle tmp0;
    const b2Circle *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Circle(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Circle(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2Manifold rv = b2CollideCircles(a0, a1, a2, a3);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2CollidePolygonAndCapsule(lua_State *L)
{
    (void)L;
    b2Polygon tmp0;
    const b2Polygon *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Polygon(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Capsule tmp2;
    const b2Capsule *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Capsule(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2Manifold rv = b2CollidePolygonAndCapsule(a0, a1, a2, a3);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2CollidePolygonAndCircle(lua_State *L)
{
    (void)L;
    b2Polygon tmp0;
    const b2Polygon *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Polygon(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Circle(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2Manifold rv = b2CollidePolygonAndCircle(a0, a1, a2, a3);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2CollidePolygons(lua_State *L)
{
    (void)L;
    b2Polygon tmp0;
    const b2Polygon *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Polygon(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Polygon tmp2;
    const b2Polygon *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Polygon(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2Manifold rv = b2CollidePolygons(a0, a1, a2, a3);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2CollideSegmentAndCapsule(lua_State *L)
{
    (void)L;
    b2Segment tmp0;
    const b2Segment *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Segment(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Capsule tmp2;
    const b2Capsule *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Capsule(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2Manifold rv = b2CollideSegmentAndCapsule(a0, a1, a2, a3);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2CollideSegmentAndCircle(lua_State *L)
{
    (void)L;
    b2Segment tmp0;
    const b2Segment *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Segment(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Circle(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2Manifold rv = b2CollideSegmentAndCircle(a0, a1, a2, a3);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2CollideSegmentAndPolygon(lua_State *L)
{
    (void)L;
    b2Segment tmp0;
    const b2Segment *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Segment(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2Polygon tmp2;
    const b2Polygon *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Polygon(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(L, 4, &a3);
    b2Manifold rv = b2CollideSegmentAndPolygon(a0, a1, a2, a3);
    GenPush_b2Manifold(L, &rv);
    return 1;
}

static int GenL_b2ComputeCapsuleAABB(lua_State *L)
{
    (void)L;
    b2Capsule tmp0;
    const b2Capsule *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Capsule(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2AABB rv = b2ComputeCapsuleAABB(a0, a1);
    GenPush_b2AABB(L, &rv);
    return 1;
}

static int GenL_b2ComputeCapsuleMass(lua_State *L)
{
    (void)L;
    b2Capsule tmp0;
    const b2Capsule *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Capsule(L, 1, &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)luaL_checknumber(L, 2);
    b2MassData rv = b2ComputeCapsuleMass(a0, a1);
    GenPush_b2MassData(L, &rv);
    return 1;
}

static int GenL_b2ComputeCircleAABB(lua_State *L)
{
    (void)L;
    b2Circle tmp0;
    const b2Circle *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Circle(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2AABB rv = b2ComputeCircleAABB(a0, a1);
    GenPush_b2AABB(L, &rv);
    return 1;
}

static int GenL_b2ComputeCircleMass(lua_State *L)
{
    (void)L;
    b2Circle tmp0;
    const b2Circle *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Circle(L, 1, &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)luaL_checknumber(L, 2);
    b2MassData rv = b2ComputeCircleMass(a0, a1);
    GenPush_b2MassData(L, &rv);
    return 1;
}

static int GenL_b2ComputeCosSin(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    b2CosSin rv = b2ComputeCosSin(a0);
    GenPush_b2CosSin(L, &rv);
    return 1;
}

static int GenL_b2ComputeHull(lua_State *L)
{
    (void)L;
    b2Vec2 tmp0;
    const b2Vec2 *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Vec2(L, 1, &tmp0);
        a0 = &tmp0;
    }
    int a1 = (int)luaL_checkinteger(L, 2);
    b2Hull rv = b2ComputeHull(a0, a1);
    GenPush_b2Hull(L, &rv);
    return 1;
}

static int GenL_b2ComputePolygonAABB(lua_State *L)
{
    (void)L;
    b2Polygon tmp0;
    const b2Polygon *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Polygon(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2AABB rv = b2ComputePolygonAABB(a0, a1);
    GenPush_b2AABB(L, &rv);
    return 1;
}

static int GenL_b2ComputePolygonMass(lua_State *L)
{
    (void)L;
    b2Polygon tmp0;
    const b2Polygon *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Polygon(L, 1, &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)luaL_checknumber(L, 2);
    b2MassData rv = b2ComputePolygonMass(a0, a1);
    GenPush_b2MassData(L, &rv);
    return 1;
}

static int GenL_b2ComputeRotationBetweenUnitVectors(lua_State *L)
{
    (void)L;
    b2Vec2 a0;
    GenRead_b2Vec2(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Rot rv = b2ComputeRotationBetweenUnitVectors(a0, a1);
    GenPush_b2Rot(L, &rv);
    return 1;
}

static int GenL_b2ComputeSegmentAABB(lua_State *L)
{
    (void)L;
    b2Segment tmp0;
    const b2Segment *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Segment(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(L, 2, &a1);
    b2AABB rv = b2ComputeSegmentAABB(a0, a1);
    GenPush_b2AABB(L, &rv);
    return 1;
}

static int GenL_b2CreateBody(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2BodyDef tmp1;
    const b2BodyDef *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2BodyDef(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2BodyId rv = b2CreateBody(a0, a1);
    GenPush_b2BodyId(L, &rv);
    return 1;
}

static int GenL_b2CreateCapsuleShape(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2ShapeDef tmp1;
    const b2ShapeDef *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2ShapeDef(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2Capsule tmp2;
    const b2Capsule *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Capsule(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2ShapeId rv = b2CreateCapsuleShape(a0, a1, a2);
    GenPush_b2ShapeId(L, &rv);
    return 1;
}

static int GenL_b2CreateChain(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2ChainDef tmp1;
    const b2ChainDef *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2ChainDef(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2ChainId rv = b2CreateChain(a0, a1);
    GenPush_b2ChainId(L, &rv);
    return 1;
}

static int GenL_b2CreateCircleShape(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2ShapeDef tmp1;
    const b2ShapeDef *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2ShapeDef(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Circle(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2ShapeId rv = b2CreateCircleShape(a0, a1, a2);
    GenPush_b2ShapeId(L, &rv);
    return 1;
}

static int GenL_b2CreateDistanceJoint(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    const b2DistanceJointDef *a1 = (const b2DistanceJointDef *)SDLStaticGen_LuaCheckHandle(L, 2, "b2DistanceJointDef");
    b2JointId rv = b2CreateDistanceJoint(a0, a1);
    GenPush_b2JointId(L, &rv);
    return 1;
}

static int GenL_b2CreateFilterJoint(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    const b2FilterJointDef *a1 = (const b2FilterJointDef *)SDLStaticGen_LuaCheckHandle(L, 2, "b2FilterJointDef");
    b2JointId rv = b2CreateFilterJoint(a0, a1);
    GenPush_b2JointId(L, &rv);
    return 1;
}

static int GenL_b2CreateMotorJoint(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    const b2MotorJointDef *a1 = (const b2MotorJointDef *)SDLStaticGen_LuaCheckHandle(L, 2, "b2MotorJointDef");
    b2JointId rv = b2CreateMotorJoint(a0, a1);
    GenPush_b2JointId(L, &rv);
    return 1;
}

static int GenL_b2CreateMouseJoint(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    const b2MouseJointDef *a1 = (const b2MouseJointDef *)SDLStaticGen_LuaCheckHandle(L, 2, "b2MouseJointDef");
    b2JointId rv = b2CreateMouseJoint(a0, a1);
    GenPush_b2JointId(L, &rv);
    return 1;
}

static int GenL_b2CreatePolygonShape(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2ShapeDef tmp1;
    const b2ShapeDef *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2ShapeDef(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2Polygon tmp2;
    const b2Polygon *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Polygon(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2ShapeId rv = b2CreatePolygonShape(a0, a1, a2);
    GenPush_b2ShapeId(L, &rv);
    return 1;
}

static int GenL_b2CreatePrismaticJoint(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    const b2PrismaticJointDef *a1 = (const b2PrismaticJointDef *)SDLStaticGen_LuaCheckHandle(L, 2, "b2PrismaticJointDef");
    b2JointId rv = b2CreatePrismaticJoint(a0, a1);
    GenPush_b2JointId(L, &rv);
    return 1;
}

static int GenL_b2CreateRevoluteJoint(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    const b2RevoluteJointDef *a1 = (const b2RevoluteJointDef *)SDLStaticGen_LuaCheckHandle(L, 2, "b2RevoluteJointDef");
    b2JointId rv = b2CreateRevoluteJoint(a0, a1);
    GenPush_b2JointId(L, &rv);
    return 1;
}

static int GenL_b2CreateSegmentShape(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2ShapeDef tmp1;
    const b2ShapeDef *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2ShapeDef(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2Segment tmp2;
    const b2Segment *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_b2Segment(L, 3, &tmp2);
        a2 = &tmp2;
    }
    b2ShapeId rv = b2CreateSegmentShape(a0, a1, a2);
    GenPush_b2ShapeId(L, &rv);
    return 1;
}

static int GenL_b2CreateWeldJoint(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    const b2WeldJointDef *a1 = (const b2WeldJointDef *)SDLStaticGen_LuaCheckHandle(L, 2, "b2WeldJointDef");
    b2JointId rv = b2CreateWeldJoint(a0, a1);
    GenPush_b2JointId(L, &rv);
    return 1;
}

static int GenL_b2CreateWheelJoint(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    const b2WheelJointDef *a1 = (const b2WheelJointDef *)SDLStaticGen_LuaCheckHandle(L, 2, "b2WheelJointDef");
    b2JointId rv = b2CreateWheelJoint(a0, a1);
    GenPush_b2JointId(L, &rv);
    return 1;
}

static int GenL_b2CreateWorld(lua_State *L)
{
    (void)L;
    b2WorldDef tmp0;
    const b2WorldDef *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2WorldDef(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2WorldId rv = b2CreateWorld(a0);
    GenPush_b2WorldId(L, &rv);
    return 1;
}

static int GenL_b2DefaultBodyDef(lua_State *L)
{
    (void)L;
    b2BodyDef rv = b2DefaultBodyDef();
    GenPush_b2BodyDef(L, &rv);
    return 1;
}

static int GenL_b2DefaultChainDef(lua_State *L)
{
    (void)L;
    b2ChainDef rv = b2DefaultChainDef();
    GenPush_b2ChainDef(L, &rv);
    return 1;
}

static int GenL_b2DefaultExplosionDef(lua_State *L)
{
    (void)L;
    b2ExplosionDef rv = b2DefaultExplosionDef();
    GenPush_b2ExplosionDef(L, &rv);
    return 1;
}

static int GenL_b2DefaultFilter(lua_State *L)
{
    (void)L;
    b2Filter rv = b2DefaultFilter();
    GenPush_b2Filter(L, &rv);
    return 1;
}

static int GenL_b2DefaultQueryFilter(lua_State *L)
{
    (void)L;
    b2QueryFilter rv = b2DefaultQueryFilter();
    GenPush_b2QueryFilter(L, &rv);
    return 1;
}

static int GenL_b2DefaultShapeDef(lua_State *L)
{
    (void)L;
    b2ShapeDef rv = b2DefaultShapeDef();
    GenPush_b2ShapeDef(L, &rv);
    return 1;
}

static int GenL_b2DefaultSurfaceMaterial(lua_State *L)
{
    (void)L;
    b2SurfaceMaterial rv = b2DefaultSurfaceMaterial();
    GenPush_b2SurfaceMaterial(L, &rv);
    return 1;
}

static int GenL_b2DefaultWorldDef(lua_State *L)
{
    (void)L;
    b2WorldDef rv = b2DefaultWorldDef();
    GenPush_b2WorldDef(L, &rv);
    return 1;
}

static int GenL_b2DestroyBody(lua_State *L)
{
    (void)L;
    b2BodyId a0;
    GenRead_b2BodyId(L, 1, &a0);
    b2DestroyBody(a0);
    return 0;
}

static int GenL_b2DestroyChain(lua_State *L)
{
    (void)L;
    b2ChainId a0;
    GenRead_b2ChainId(L, 1, &a0);
    b2DestroyChain(a0);
    return 0;
}

static int GenL_b2DestroyJoint(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2DestroyJoint(a0);
    return 0;
}

static int GenL_b2DestroyShape(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2DestroyShape(a0, a1);
    return 0;
}

static int GenL_b2DestroyWorld(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2DestroyWorld(a0);
    return 0;
}

static int GenL_b2DistanceJoint_EnableLimit(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2DistanceJoint_EnableLimit(a0, a1);
    return 0;
}

static int GenL_b2DistanceJoint_EnableMotor(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2DistanceJoint_EnableMotor(a0, a1);
    return 0;
}

static int GenL_b2DistanceJoint_EnableSpring(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2DistanceJoint_EnableSpring(a0, a1);
    return 0;
}

static int GenL_b2DistanceJoint_GetCurrentLength(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2DistanceJoint_GetCurrentLength(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2DistanceJoint_GetLength(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2DistanceJoint_GetLength(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2DistanceJoint_GetMaxLength(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2DistanceJoint_GetMaxLength(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2DistanceJoint_GetMaxMotorForce(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2DistanceJoint_GetMaxMotorForce(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2DistanceJoint_GetMinLength(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2DistanceJoint_GetMinLength(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2DistanceJoint_GetMotorForce(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2DistanceJoint_GetMotorForce(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2DistanceJoint_GetMotorSpeed(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2DistanceJoint_GetMotorSpeed(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2DistanceJoint_GetSpringDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2DistanceJoint_GetSpringDampingRatio(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2DistanceJoint_GetSpringHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2DistanceJoint_GetSpringHertz(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2DistanceJoint_IsLimitEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2DistanceJoint_IsLimitEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2DistanceJoint_IsMotorEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2DistanceJoint_IsMotorEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2DistanceJoint_IsSpringEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2DistanceJoint_IsSpringEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2DistanceJoint_SetLength(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2DistanceJoint_SetLength(a0, a1);
    return 0;
}

static int GenL_b2DistanceJoint_SetLengthRange(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    b2DistanceJoint_SetLengthRange(a0, a1, a2);
    return 0;
}

static int GenL_b2DistanceJoint_SetMaxMotorForce(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2DistanceJoint_SetMaxMotorForce(a0, a1);
    return 0;
}

static int GenL_b2DistanceJoint_SetMotorSpeed(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2DistanceJoint_SetMotorSpeed(a0, a1);
    return 0;
}

static int GenL_b2DistanceJoint_SetSpringDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2DistanceJoint_SetSpringDampingRatio(a0, a1);
    return 0;
}

static int GenL_b2DistanceJoint_SetSpringHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2DistanceJoint_SetSpringHertz(a0, a1);
    return 0;
}

static int GenL_b2DynamicTree_CreateProxy(lua_State *L)
{
    (void)L;
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    b2AABB a1;
    GenRead_b2AABB(L, 2, &a1);
    uint64_t a2 = (uint64_t)luaL_checkinteger(L, 3);
    uint64_t a3 = (uint64_t)luaL_checkinteger(L, 4);
    int rv = b2DynamicTree_CreateProxy(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2DynamicTree_Destroy(lua_State *L)
{
    (void)L;
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    b2DynamicTree_Destroy(a0);
    return 0;
}

static int GenL_b2DynamicTree_DestroyProxy(lua_State *L)
{
    (void)L;
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    int a1 = (int)luaL_checkinteger(L, 2);
    b2DynamicTree_DestroyProxy(a0, a1);
    return 0;
}

static int GenL_b2DynamicTree_EnlargeProxy(lua_State *L)
{
    (void)L;
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    int a1 = (int)luaL_checkinteger(L, 2);
    b2AABB a2;
    GenRead_b2AABB(L, 3, &a2);
    b2DynamicTree_EnlargeProxy(a0, a1, a2);
    return 0;
}

static int GenL_b2DynamicTree_GetAABB(lua_State *L)
{
    (void)L;
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    int a1 = (int)luaL_checkinteger(L, 2);
    b2AABB rv = b2DynamicTree_GetAABB(a0, a1);
    GenPush_b2AABB(L, &rv);
    return 1;
}

static int GenL_b2DynamicTree_GetAreaRatio(lua_State *L)
{
    (void)L;
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    float rv = b2DynamicTree_GetAreaRatio(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2DynamicTree_GetByteCount(lua_State *L)
{
    (void)L;
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    int rv = b2DynamicTree_GetByteCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2DynamicTree_GetCategoryBits(lua_State *L)
{
    (void)L;
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    int a1 = (int)luaL_checkinteger(L, 2);
    uint64_t rv = b2DynamicTree_GetCategoryBits(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2DynamicTree_GetHeight(lua_State *L)
{
    (void)L;
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    int rv = b2DynamicTree_GetHeight(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2DynamicTree_GetProxyCount(lua_State *L)
{
    (void)L;
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    int rv = b2DynamicTree_GetProxyCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2DynamicTree_GetRootBounds(lua_State *L)
{
    (void)L;
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    b2AABB rv = b2DynamicTree_GetRootBounds(a0);
    GenPush_b2AABB(L, &rv);
    return 1;
}

static int GenL_b2DynamicTree_GetUserData(lua_State *L)
{
    (void)L;
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    int a1 = (int)luaL_checkinteger(L, 2);
    uint64_t rv = b2DynamicTree_GetUserData(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2DynamicTree_MoveProxy(lua_State *L)
{
    (void)L;
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    int a1 = (int)luaL_checkinteger(L, 2);
    b2AABB a2;
    GenRead_b2AABB(L, 3, &a2);
    b2DynamicTree_MoveProxy(a0, a1, a2);
    return 0;
}

static int GenL_b2DynamicTree_Rebuild(lua_State *L)
{
    (void)L;
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    bool a1 = (bool)lua_toboolean(L, 2);
    int rv = b2DynamicTree_Rebuild(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2DynamicTree_SetCategoryBits(lua_State *L)
{
    (void)L;
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    int a1 = (int)luaL_checkinteger(L, 2);
    uint64_t a2 = (uint64_t)luaL_checkinteger(L, 3);
    b2DynamicTree_SetCategoryBits(a0, a1, a2);
    return 0;
}

static int GenL_b2DynamicTree_Validate(lua_State *L)
{
    (void)L;
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    b2DynamicTree_Validate(a0);
    return 0;
}

static int GenL_b2DynamicTree_ValidateNoEnlarged(lua_State *L)
{
    (void)L;
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DynamicTree");
    b2DynamicTree_ValidateNoEnlarged(a0);
    return 0;
}

static int GenL_b2GetByteCount(lua_State *L)
{
    (void)L;
    int rv = b2GetByteCount();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2GetLengthUnitsPerMeter(lua_State *L)
{
    (void)L;
    float rv = b2GetLengthUnitsPerMeter();
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2GetMilliseconds(lua_State *L)
{
    (void)L;
    uint64_t a0 = (uint64_t)luaL_checkinteger(L, 1);
    float rv = b2GetMilliseconds(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2GetMillisecondsAndReset(lua_State *L)
{
    (void)L;
    uint64_t io0 = (uint64_t)luaL_optinteger(L, 1, 0);
    float rv = b2GetMillisecondsAndReset(&io0);
    lua_pushnumber(L, (lua_Number)rv);
    lua_pushinteger(L, (lua_Integer)io0);
    return 2;
}

static int GenL_b2GetSweepTransform(lua_State *L)
{
    (void)L;
    b2Sweep tmp0;
    const b2Sweep *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Sweep(L, 1, &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)luaL_checknumber(L, 2);
    b2Transform rv = b2GetSweepTransform(a0, a1);
    GenPush_b2Transform(L, &rv);
    return 1;
}

static int GenL_b2GetTicks(lua_State *L)
{
    (void)L;
    uint64_t rv = b2GetTicks();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2GetVersion(lua_State *L)
{
    (void)L;
    b2Version rv = b2GetVersion();
    GenPush_b2Version(L, &rv);
    return 1;
}

static int GenL_b2InternalAssertFcn(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int rv = b2InternalAssertFcn(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2IsValidAABB(lua_State *L)
{
    (void)L;
    b2AABB a0;
    GenRead_b2AABB(L, 1, &a0);
    bool rv = b2IsValidAABB(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2IsValidFloat(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    bool rv = b2IsValidFloat(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2IsValidPlane(lua_State *L)
{
    (void)L;
    b2Plane a0;
    GenRead_b2Plane(L, 1, &a0);
    bool rv = b2IsValidPlane(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2IsValidRay(lua_State *L)
{
    (void)L;
    b2RayCastInput tmp0;
    const b2RayCastInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2RayCastInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    bool rv = b2IsValidRay(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2IsValidRotation(lua_State *L)
{
    (void)L;
    b2Rot a0;
    GenRead_b2Rot(L, 1, &a0);
    bool rv = b2IsValidRotation(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2IsValidVec2(lua_State *L)
{
    (void)L;
    b2Vec2 a0;
    GenRead_b2Vec2(L, 1, &a0);
    bool rv = b2IsValidVec2(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Joint_GetAngularSeparation(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2Joint_GetAngularSeparation(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Joint_GetBodyA(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2BodyId rv = b2Joint_GetBodyA(a0);
    GenPush_b2BodyId(L, &rv);
    return 1;
}

static int GenL_b2Joint_GetBodyB(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2BodyId rv = b2Joint_GetBodyB(a0);
    GenPush_b2BodyId(L, &rv);
    return 1;
}

static int GenL_b2Joint_GetCollideConnected(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2Joint_GetCollideConnected(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Joint_GetConstraintForce(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Vec2 rv = b2Joint_GetConstraintForce(a0);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Joint_GetConstraintTorque(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2Joint_GetConstraintTorque(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Joint_GetConstraintTuning(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    b2Joint_GetConstraintTuning(a0, &io1, &io2);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    return 2;
}

static int GenL_b2Joint_GetLinearSeparation(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2Joint_GetLinearSeparation(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Joint_GetLocalAnchorA(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Vec2 rv = b2Joint_GetLocalAnchorA(a0);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Joint_GetLocalAnchorB(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Vec2 rv = b2Joint_GetLocalAnchorB(a0);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Joint_GetLocalAxisA(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Vec2 rv = b2Joint_GetLocalAxisA(a0);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Joint_GetReferenceAngle(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2Joint_GetReferenceAngle(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Joint_GetType(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2JointType rv = b2Joint_GetType(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2Joint_GetWorld(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2WorldId rv = b2Joint_GetWorld(a0);
    GenPush_b2WorldId(L, &rv);
    return 1;
}

static int GenL_b2Joint_IsValid(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2Joint_IsValid(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Joint_SetCollideConnected(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2Joint_SetCollideConnected(a0, a1);
    return 0;
}

static int GenL_b2Joint_SetConstraintTuning(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    b2Joint_SetConstraintTuning(a0, a1, a2);
    return 0;
}

static int GenL_b2Joint_SetLocalAnchorA(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Joint_SetLocalAnchorA(a0, a1);
    return 0;
}

static int GenL_b2Joint_SetLocalAnchorB(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Joint_SetLocalAnchorB(a0, a1);
    return 0;
}

static int GenL_b2Joint_SetLocalAxisA(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Joint_SetLocalAxisA(a0, a1);
    return 0;
}

static int GenL_b2Joint_SetReferenceAngle(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Joint_SetReferenceAngle(a0, a1);
    return 0;
}

static int GenL_b2Joint_WakeBodies(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Joint_WakeBodies(a0);
    return 0;
}

static int GenL_b2MakeBox(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Polygon rv = b2MakeBox(a0, a1);
    GenPush_b2Polygon(L, &rv);
    return 1;
}

static int GenL_b2MakeOffsetBox(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Vec2 a2;
    GenRead_b2Vec2(L, 3, &a2);
    b2Rot a3;
    GenRead_b2Rot(L, 4, &a3);
    b2Polygon rv = b2MakeOffsetBox(a0, a1, a2, a3);
    GenPush_b2Polygon(L, &rv);
    return 1;
}

static int GenL_b2MakeOffsetPolygon(lua_State *L)
{
    (void)L;
    const b2Hull *a0 = (const b2Hull *)SDLStaticGen_LuaCheckHandle(L, 1, "b2Hull");
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Rot a2;
    GenRead_b2Rot(L, 3, &a2);
    b2Polygon rv = b2MakeOffsetPolygon(a0, a1, a2);
    GenPush_b2Polygon(L, &rv);
    return 1;
}

static int GenL_b2MakeOffsetProxy(lua_State *L)
{
    (void)L;
    b2Vec2 tmp0;
    const b2Vec2 *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Vec2(L, 1, &tmp0);
        a0 = &tmp0;
    }
    int a1 = (int)luaL_checkinteger(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    b2Vec2 a3;
    GenRead_b2Vec2(L, 4, &a3);
    b2Rot a4;
    GenRead_b2Rot(L, 5, &a4);
    b2ShapeProxy rv = b2MakeOffsetProxy(a0, a1, a2, a3, a4);
    GenPush_b2ShapeProxy(L, &rv);
    return 1;
}

static int GenL_b2MakeOffsetRoundedBox(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Vec2 a2;
    GenRead_b2Vec2(L, 3, &a2);
    b2Rot a3;
    GenRead_b2Rot(L, 4, &a3);
    float a4 = (float)luaL_checknumber(L, 5);
    b2Polygon rv = b2MakeOffsetRoundedBox(a0, a1, a2, a3, a4);
    GenPush_b2Polygon(L, &rv);
    return 1;
}

static int GenL_b2MakeOffsetRoundedPolygon(lua_State *L)
{
    (void)L;
    const b2Hull *a0 = (const b2Hull *)SDLStaticGen_LuaCheckHandle(L, 1, "b2Hull");
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Rot a2;
    GenRead_b2Rot(L, 3, &a2);
    float a3 = (float)luaL_checknumber(L, 4);
    b2Polygon rv = b2MakeOffsetRoundedPolygon(a0, a1, a2, a3);
    GenPush_b2Polygon(L, &rv);
    return 1;
}

static int GenL_b2MakePolygon(lua_State *L)
{
    (void)L;
    const b2Hull *a0 = (const b2Hull *)SDLStaticGen_LuaCheckHandle(L, 1, "b2Hull");
    float a1 = (float)luaL_checknumber(L, 2);
    b2Polygon rv = b2MakePolygon(a0, a1);
    GenPush_b2Polygon(L, &rv);
    return 1;
}

static int GenL_b2MakeProxy(lua_State *L)
{
    (void)L;
    b2Vec2 tmp0;
    const b2Vec2 *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2Vec2(L, 1, &tmp0);
        a0 = &tmp0;
    }
    int a1 = (int)luaL_checkinteger(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    b2ShapeProxy rv = b2MakeProxy(a0, a1, a2);
    GenPush_b2ShapeProxy(L, &rv);
    return 1;
}

static int GenL_b2MakeRoundedBox(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    b2Polygon rv = b2MakeRoundedBox(a0, a1, a2);
    GenPush_b2Polygon(L, &rv);
    return 1;
}

static int GenL_b2MakeSquare(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    b2Polygon rv = b2MakeSquare(a0);
    GenPush_b2Polygon(L, &rv);
    return 1;
}

static int GenL_b2MotorJoint_GetAngularOffset(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2MotorJoint_GetAngularOffset(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2MotorJoint_GetCorrectionFactor(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2MotorJoint_GetCorrectionFactor(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2MotorJoint_GetLinearOffset(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Vec2 rv = b2MotorJoint_GetLinearOffset(a0);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2MotorJoint_GetMaxForce(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2MotorJoint_GetMaxForce(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2MotorJoint_GetMaxTorque(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2MotorJoint_GetMaxTorque(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2MotorJoint_SetAngularOffset(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2MotorJoint_SetAngularOffset(a0, a1);
    return 0;
}

static int GenL_b2MotorJoint_SetCorrectionFactor(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2MotorJoint_SetCorrectionFactor(a0, a1);
    return 0;
}

static int GenL_b2MotorJoint_SetLinearOffset(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2MotorJoint_SetLinearOffset(a0, a1);
    return 0;
}

static int GenL_b2MotorJoint_SetMaxForce(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2MotorJoint_SetMaxForce(a0, a1);
    return 0;
}

static int GenL_b2MotorJoint_SetMaxTorque(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2MotorJoint_SetMaxTorque(a0, a1);
    return 0;
}

static int GenL_b2MouseJoint_GetMaxForce(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2MouseJoint_GetMaxForce(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2MouseJoint_GetSpringDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2MouseJoint_GetSpringDampingRatio(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2MouseJoint_GetSpringHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2MouseJoint_GetSpringHertz(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2MouseJoint_GetTarget(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Vec2 rv = b2MouseJoint_GetTarget(a0);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2MouseJoint_SetMaxForce(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2MouseJoint_SetMaxForce(a0, a1);
    return 0;
}

static int GenL_b2MouseJoint_SetSpringDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2MouseJoint_SetSpringDampingRatio(a0, a1);
    return 0;
}

static int GenL_b2MouseJoint_SetSpringHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2MouseJoint_SetSpringHertz(a0, a1);
    return 0;
}

static int GenL_b2MouseJoint_SetTarget(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2MouseJoint_SetTarget(a0, a1);
    return 0;
}

static int GenL_b2PointInCapsule(lua_State *L)
{
    (void)L;
    b2Vec2 a0;
    GenRead_b2Vec2(L, 1, &a0);
    b2Capsule tmp1;
    const b2Capsule *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Capsule(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = b2PointInCapsule(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2PointInCircle(lua_State *L)
{
    (void)L;
    b2Vec2 a0;
    GenRead_b2Vec2(L, 1, &a0);
    b2Circle tmp1;
    const b2Circle *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Circle(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = b2PointInCircle(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2PointInPolygon(lua_State *L)
{
    (void)L;
    b2Vec2 a0;
    GenRead_b2Vec2(L, 1, &a0);
    b2Polygon tmp1;
    const b2Polygon *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Polygon(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = b2PointInPolygon(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_EnableLimit(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2PrismaticJoint_EnableLimit(a0, a1);
    return 0;
}

static int GenL_b2PrismaticJoint_EnableMotor(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2PrismaticJoint_EnableMotor(a0, a1);
    return 0;
}

static int GenL_b2PrismaticJoint_EnableSpring(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2PrismaticJoint_EnableSpring(a0, a1);
    return 0;
}

static int GenL_b2PrismaticJoint_GetLowerLimit(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2PrismaticJoint_GetLowerLimit(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_GetMaxMotorForce(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2PrismaticJoint_GetMaxMotorForce(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_GetMotorForce(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2PrismaticJoint_GetMotorForce(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_GetMotorSpeed(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2PrismaticJoint_GetMotorSpeed(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_GetSpeed(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2PrismaticJoint_GetSpeed(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_GetSpringDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2PrismaticJoint_GetSpringDampingRatio(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_GetSpringHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2PrismaticJoint_GetSpringHertz(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_GetTargetTranslation(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2PrismaticJoint_GetTargetTranslation(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_GetTranslation(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2PrismaticJoint_GetTranslation(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_GetUpperLimit(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2PrismaticJoint_GetUpperLimit(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_IsLimitEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2PrismaticJoint_IsLimitEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_IsMotorEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2PrismaticJoint_IsMotorEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_IsSpringEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2PrismaticJoint_IsSpringEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2PrismaticJoint_SetLimits(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    b2PrismaticJoint_SetLimits(a0, a1, a2);
    return 0;
}

static int GenL_b2PrismaticJoint_SetMaxMotorForce(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2PrismaticJoint_SetMaxMotorForce(a0, a1);
    return 0;
}

static int GenL_b2PrismaticJoint_SetMotorSpeed(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2PrismaticJoint_SetMotorSpeed(a0, a1);
    return 0;
}

static int GenL_b2PrismaticJoint_SetSpringDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2PrismaticJoint_SetSpringDampingRatio(a0, a1);
    return 0;
}

static int GenL_b2PrismaticJoint_SetSpringHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2PrismaticJoint_SetSpringHertz(a0, a1);
    return 0;
}

static int GenL_b2PrismaticJoint_SetTargetTranslation(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2PrismaticJoint_SetTargetTranslation(a0, a1);
    return 0;
}

static int GenL_b2RayCastCapsule(lua_State *L)
{
    (void)L;
    b2RayCastInput tmp0;
    const b2RayCastInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2RayCastInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Capsule tmp1;
    const b2Capsule *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Capsule(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2RayCastCapsule(a0, a1);
    GenPush_b2CastOutput(L, &rv);
    return 1;
}

static int GenL_b2RayCastCircle(lua_State *L)
{
    (void)L;
    b2RayCastInput tmp0;
    const b2RayCastInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2RayCastInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Circle tmp1;
    const b2Circle *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Circle(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2RayCastCircle(a0, a1);
    GenPush_b2CastOutput(L, &rv);
    return 1;
}

static int GenL_b2RayCastPolygon(lua_State *L)
{
    (void)L;
    b2RayCastInput tmp0;
    const b2RayCastInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2RayCastInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Polygon tmp1;
    const b2Polygon *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Polygon(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2RayCastPolygon(a0, a1);
    GenPush_b2CastOutput(L, &rv);
    return 1;
}

static int GenL_b2RayCastSegment(lua_State *L)
{
    (void)L;
    b2RayCastInput tmp0;
    const b2RayCastInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2RayCastInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Segment tmp1;
    const b2Segment *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Segment(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool a2 = (bool)lua_toboolean(L, 3);
    b2CastOutput rv = b2RayCastSegment(a0, a1, a2);
    GenPush_b2CastOutput(L, &rv);
    return 1;
}

static int GenL_b2RevoluteJoint_EnableLimit(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2RevoluteJoint_EnableLimit(a0, a1);
    return 0;
}

static int GenL_b2RevoluteJoint_EnableMotor(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2RevoluteJoint_EnableMotor(a0, a1);
    return 0;
}

static int GenL_b2RevoluteJoint_EnableSpring(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2RevoluteJoint_EnableSpring(a0, a1);
    return 0;
}

static int GenL_b2RevoluteJoint_GetAngle(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2RevoluteJoint_GetAngle(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_GetLowerLimit(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2RevoluteJoint_GetLowerLimit(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_GetMaxMotorTorque(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2RevoluteJoint_GetMaxMotorTorque(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_GetMotorSpeed(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2RevoluteJoint_GetMotorSpeed(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_GetMotorTorque(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2RevoluteJoint_GetMotorTorque(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_GetSpringDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2RevoluteJoint_GetSpringDampingRatio(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_GetSpringHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2RevoluteJoint_GetSpringHertz(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_GetTargetAngle(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2RevoluteJoint_GetTargetAngle(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_GetUpperLimit(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2RevoluteJoint_GetUpperLimit(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_IsLimitEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2RevoluteJoint_IsLimitEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_IsMotorEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2RevoluteJoint_IsMotorEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_IsSpringEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2RevoluteJoint_IsSpringEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2RevoluteJoint_SetLimits(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    b2RevoluteJoint_SetLimits(a0, a1, a2);
    return 0;
}

static int GenL_b2RevoluteJoint_SetMaxMotorTorque(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2RevoluteJoint_SetMaxMotorTorque(a0, a1);
    return 0;
}

static int GenL_b2RevoluteJoint_SetMotorSpeed(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2RevoluteJoint_SetMotorSpeed(a0, a1);
    return 0;
}

static int GenL_b2RevoluteJoint_SetSpringDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2RevoluteJoint_SetSpringDampingRatio(a0, a1);
    return 0;
}

static int GenL_b2RevoluteJoint_SetSpringHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2RevoluteJoint_SetSpringHertz(a0, a1);
    return 0;
}

static int GenL_b2RevoluteJoint_SetTargetAngle(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2RevoluteJoint_SetTargetAngle(a0, a1);
    return 0;
}

static int GenL_b2SegmentDistance(lua_State *L)
{
    (void)L;
    b2Vec2 a0;
    GenRead_b2Vec2(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Vec2 a2;
    GenRead_b2Vec2(L, 3, &a2);
    b2Vec2 a3;
    GenRead_b2Vec2(L, 4, &a3);
    b2SegmentDistanceResult rv = b2SegmentDistance(a0, a1, a2, a3);
    GenPush_b2SegmentDistanceResult(L, &rv);
    return 1;
}

static int GenL_b2SetLengthUnitsPerMeter(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    b2SetLengthUnitsPerMeter(a0);
    return 0;
}

static int GenL_b2ShapeCast(lua_State *L)
{
    (void)L;
    b2ShapeCastPairInput tmp0;
    const b2ShapeCastPairInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2ShapeCastPairInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2CastOutput rv = b2ShapeCast(a0);
    GenPush_b2CastOutput(L, &rv);
    return 1;
}

static int GenL_b2ShapeCastCapsule(lua_State *L)
{
    (void)L;
    b2ShapeCastInput tmp0;
    const b2ShapeCastInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2ShapeCastInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Capsule tmp1;
    const b2Capsule *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Capsule(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2ShapeCastCapsule(a0, a1);
    GenPush_b2CastOutput(L, &rv);
    return 1;
}

static int GenL_b2ShapeCastCircle(lua_State *L)
{
    (void)L;
    b2ShapeCastInput tmp0;
    const b2ShapeCastInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2ShapeCastInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Circle tmp1;
    const b2Circle *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Circle(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2ShapeCastCircle(a0, a1);
    GenPush_b2CastOutput(L, &rv);
    return 1;
}

static int GenL_b2ShapeCastPolygon(lua_State *L)
{
    (void)L;
    b2ShapeCastInput tmp0;
    const b2ShapeCastInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2ShapeCastInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Polygon tmp1;
    const b2Polygon *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Polygon(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2ShapeCastPolygon(a0, a1);
    GenPush_b2CastOutput(L, &rv);
    return 1;
}

static int GenL_b2ShapeCastSegment(lua_State *L)
{
    (void)L;
    b2ShapeCastInput tmp0;
    const b2ShapeCastInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2ShapeCastInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2Segment tmp1;
    const b2Segment *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Segment(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2ShapeCastSegment(a0, a1);
    GenPush_b2CastOutput(L, &rv);
    return 1;
}

static int GenL_b2ShapeDistance(lua_State *L)
{
    (void)L;
    b2DistanceInput tmp0;
    const b2DistanceInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2DistanceInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2SimplexCache *a1 = (b2SimplexCache *)SDLStaticGen_LuaCheckHandle(L, 2, "b2SimplexCache");
    b2Simplex out2;
    memset(&out2, 0, sizeof(out2));
    int a3 = (int)luaL_checkinteger(L, 3);
    b2DistanceOutput rv = b2ShapeDistance(a0, a1, &out2, a3);
    GenPush_b2DistanceOutput(L, &rv);
    GenPush_b2Simplex(L, &out2);
    return 2;
}

static int GenL_b2Shape_AreContactEventsEnabled(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    bool rv = b2Shape_AreContactEventsEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Shape_AreHitEventsEnabled(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    bool rv = b2Shape_AreHitEventsEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Shape_ArePreSolveEventsEnabled(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    bool rv = b2Shape_ArePreSolveEventsEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Shape_AreSensorEventsEnabled(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    bool rv = b2Shape_AreSensorEventsEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Shape_EnableContactEvents(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2Shape_EnableContactEvents(a0, a1);
    return 0;
}

static int GenL_b2Shape_EnableHitEvents(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2Shape_EnableHitEvents(a0, a1);
    return 0;
}

static int GenL_b2Shape_EnablePreSolveEvents(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2Shape_EnablePreSolveEvents(a0, a1);
    return 0;
}

static int GenL_b2Shape_EnableSensorEvents(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2Shape_EnableSensorEvents(a0, a1);
    return 0;
}

static int GenL_b2Shape_GetAABB(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2AABB rv = b2Shape_GetAABB(a0);
    GenPush_b2AABB(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetBody(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2BodyId rv = b2Shape_GetBody(a0);
    GenPush_b2BodyId(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetCapsule(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Capsule rv = b2Shape_GetCapsule(a0);
    GenPush_b2Capsule(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetChainSegment(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2ChainSegment rv = b2Shape_GetChainSegment(a0);
    GenPush_b2ChainSegment(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetCircle(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Circle rv = b2Shape_GetCircle(a0);
    GenPush_b2Circle(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetClosestPoint(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Vec2 rv = b2Shape_GetClosestPoint(a0, a1);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetContactCapacity(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    int rv = b2Shape_GetContactCapacity(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2Shape_GetContactData(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2ContactData out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)luaL_checkinteger(L, 2);
    int rv = b2Shape_GetContactData(a0, &out1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_b2ContactData(L, &out1);
    return 2;
}

static int GenL_b2Shape_GetDensity(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    float rv = b2Shape_GetDensity(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Shape_GetFilter(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Filter rv = b2Shape_GetFilter(a0);
    GenPush_b2Filter(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetFriction(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    float rv = b2Shape_GetFriction(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Shape_GetMassData(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2MassData rv = b2Shape_GetMassData(a0);
    GenPush_b2MassData(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetMaterial(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    int rv = b2Shape_GetMaterial(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2Shape_GetParentChain(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2ChainId rv = b2Shape_GetParentChain(a0);
    GenPush_b2ChainId(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetPolygon(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Polygon rv = b2Shape_GetPolygon(a0);
    GenPush_b2Polygon(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetRestitution(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    float rv = b2Shape_GetRestitution(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2Shape_GetSegment(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Segment rv = b2Shape_GetSegment(a0);
    GenPush_b2Segment(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetSensorCapacity(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    int rv = b2Shape_GetSensorCapacity(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2Shape_GetSensorOverlaps(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2ShapeId out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)luaL_checkinteger(L, 2);
    int rv = b2Shape_GetSensorOverlaps(a0, &out1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_b2ShapeId(L, &out1);
    return 2;
}

static int GenL_b2Shape_GetSurfaceMaterial(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2SurfaceMaterial rv = b2Shape_GetSurfaceMaterial(a0);
    GenPush_b2SurfaceMaterial(L, &rv);
    return 1;
}

static int GenL_b2Shape_GetType(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2ShapeType rv = b2Shape_GetType(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2Shape_GetWorld(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2WorldId rv = b2Shape_GetWorld(a0);
    GenPush_b2WorldId(L, &rv);
    return 1;
}

static int GenL_b2Shape_IsSensor(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    bool rv = b2Shape_IsSensor(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Shape_IsValid(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    bool rv = b2Shape_IsValid(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2Shape_RayCast(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2RayCastInput tmp1;
    const b2RayCastInput *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2RayCastInput(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2Shape_RayCast(a0, a1);
    GenPush_b2CastOutput(L, &rv);
    return 1;
}

static int GenL_b2Shape_SetCapsule(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Capsule tmp1;
    const b2Capsule *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Capsule(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2Shape_SetCapsule(a0, a1);
    return 0;
}

static int GenL_b2Shape_SetCircle(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Circle tmp1;
    const b2Circle *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Circle(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2Shape_SetCircle(a0, a1);
    return 0;
}

static int GenL_b2Shape_SetDensity(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    bool a2 = (bool)lua_toboolean(L, 3);
    b2Shape_SetDensity(a0, a1, a2);
    return 0;
}

static int GenL_b2Shape_SetFilter(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Filter a1;
    GenRead_b2Filter(L, 2, &a1);
    b2Shape_SetFilter(a0, a1);
    return 0;
}

static int GenL_b2Shape_SetFriction(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Shape_SetFriction(a0, a1);
    return 0;
}

static int GenL_b2Shape_SetMaterial(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    int a1 = (int)luaL_checkinteger(L, 2);
    b2Shape_SetMaterial(a0, a1);
    return 0;
}

static int GenL_b2Shape_SetPolygon(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Polygon tmp1;
    const b2Polygon *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Polygon(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2Shape_SetPolygon(a0, a1);
    return 0;
}

static int GenL_b2Shape_SetRestitution(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2Shape_SetRestitution(a0, a1);
    return 0;
}

static int GenL_b2Shape_SetSegment(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Segment tmp1;
    const b2Segment *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Segment(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2Shape_SetSegment(a0, a1);
    return 0;
}

static int GenL_b2Shape_SetSurfaceMaterial(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2SurfaceMaterial a1;
    GenRead_b2SurfaceMaterial(L, 2, &a1);
    b2Shape_SetSurfaceMaterial(a0, a1);
    return 0;
}

static int GenL_b2Shape_TestPoint(lua_State *L)
{
    (void)L;
    b2ShapeId a0;
    GenRead_b2ShapeId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    bool rv = b2Shape_TestPoint(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2SolvePlanes(lua_State *L)
{
    (void)L;
    b2Vec2 a0;
    GenRead_b2Vec2(L, 1, &a0);
    b2CollisionPlane out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)luaL_checkinteger(L, 2);
    b2PlaneSolverResult rv = b2SolvePlanes(a0, &out1, a2);
    GenPush_b2PlaneSolverResult(L, &rv);
    GenPush_b2CollisionPlane(L, &out1);
    return 2;
}

static int GenL_b2TimeOfImpact(lua_State *L)
{
    (void)L;
    b2TOIInput tmp0;
    const b2TOIInput *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_b2TOIInput(L, 1, &tmp0);
        a0 = &tmp0;
    }
    b2TOIOutput rv = b2TimeOfImpact(a0);
    GenPush_b2TOIOutput(L, &rv);
    return 1;
}

static int GenL_b2TransformPolygon(lua_State *L)
{
    (void)L;
    b2Transform a0;
    GenRead_b2Transform(L, 1, &a0);
    b2Polygon tmp1;
    const b2Polygon *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Polygon(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2Polygon rv = b2TransformPolygon(a0, a1);
    GenPush_b2Polygon(L, &rv);
    return 1;
}

static int GenL_b2ValidateHull(lua_State *L)
{
    (void)L;
    const b2Hull *a0 = (const b2Hull *)SDLStaticGen_LuaCheckHandle(L, 1, "b2Hull");
    bool rv = b2ValidateHull(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2WeldJoint_GetAngularDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2WeldJoint_GetAngularDampingRatio(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2WeldJoint_GetAngularHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2WeldJoint_GetAngularHertz(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2WeldJoint_GetLinearDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2WeldJoint_GetLinearDampingRatio(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2WeldJoint_GetLinearHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2WeldJoint_GetLinearHertz(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2WeldJoint_SetAngularDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2WeldJoint_SetAngularDampingRatio(a0, a1);
    return 0;
}

static int GenL_b2WeldJoint_SetAngularHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2WeldJoint_SetAngularHertz(a0, a1);
    return 0;
}

static int GenL_b2WeldJoint_SetLinearDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2WeldJoint_SetLinearDampingRatio(a0, a1);
    return 0;
}

static int GenL_b2WeldJoint_SetLinearHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2WeldJoint_SetLinearHertz(a0, a1);
    return 0;
}

static int GenL_b2WheelJoint_EnableLimit(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2WheelJoint_EnableLimit(a0, a1);
    return 0;
}

static int GenL_b2WheelJoint_EnableMotor(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2WheelJoint_EnableMotor(a0, a1);
    return 0;
}

static int GenL_b2WheelJoint_EnableSpring(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2WheelJoint_EnableSpring(a0, a1);
    return 0;
}

static int GenL_b2WheelJoint_GetLowerLimit(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2WheelJoint_GetLowerLimit(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2WheelJoint_GetMaxMotorTorque(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2WheelJoint_GetMaxMotorTorque(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2WheelJoint_GetMotorSpeed(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2WheelJoint_GetMotorSpeed(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2WheelJoint_GetMotorTorque(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2WheelJoint_GetMotorTorque(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2WheelJoint_GetSpringDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2WheelJoint_GetSpringDampingRatio(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2WheelJoint_GetSpringHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2WheelJoint_GetSpringHertz(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2WheelJoint_GetUpperLimit(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float rv = b2WheelJoint_GetUpperLimit(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2WheelJoint_IsLimitEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2WheelJoint_IsLimitEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2WheelJoint_IsMotorEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2WheelJoint_IsMotorEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2WheelJoint_IsSpringEnabled(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    bool rv = b2WheelJoint_IsSpringEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2WheelJoint_SetLimits(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    b2WheelJoint_SetLimits(a0, a1, a2);
    return 0;
}

static int GenL_b2WheelJoint_SetMaxMotorTorque(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2WheelJoint_SetMaxMotorTorque(a0, a1);
    return 0;
}

static int GenL_b2WheelJoint_SetMotorSpeed(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2WheelJoint_SetMotorSpeed(a0, a1);
    return 0;
}

static int GenL_b2WheelJoint_SetSpringDampingRatio(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2WheelJoint_SetSpringDampingRatio(a0, a1);
    return 0;
}

static int GenL_b2WheelJoint_SetSpringHertz(lua_State *L)
{
    (void)L;
    b2JointId a0;
    GenRead_b2JointId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2WheelJoint_SetSpringHertz(a0, a1);
    return 0;
}

static int GenL_b2World_CastMover(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2Capsule tmp1;
    const b2Capsule *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2Capsule(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2Vec2 a2;
    GenRead_b2Vec2(L, 3, &a2);
    b2QueryFilter a3;
    GenRead_b2QueryFilter(L, 4, &a3);
    float rv = b2World_CastMover(a0, a1, a2, a3);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2World_CastRayClosest(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2Vec2 a2;
    GenRead_b2Vec2(L, 3, &a2);
    b2QueryFilter a3;
    GenRead_b2QueryFilter(L, 4, &a3);
    b2RayResult rv = b2World_CastRayClosest(a0, a1, a2, a3);
    GenPush_b2RayResult(L, &rv);
    return 1;
}

static int GenL_b2World_Draw(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2DebugDraw *a1 = (b2DebugDraw *)SDLStaticGen_LuaCheckHandle(L, 2, "b2DebugDraw");
    b2World_Draw(a0, a1);
    return 0;
}

static int GenL_b2World_DumpMemoryStats(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2World_DumpMemoryStats(a0);
    return 0;
}

static int GenL_b2World_EnableContinuous(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2World_EnableContinuous(a0, a1);
    return 0;
}

static int GenL_b2World_EnableSleeping(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2World_EnableSleeping(a0, a1);
    return 0;
}

static int GenL_b2World_EnableSpeculative(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2World_EnableSpeculative(a0, a1);
    return 0;
}

static int GenL_b2World_EnableWarmStarting(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    bool a1 = (bool)lua_toboolean(L, 2);
    b2World_EnableWarmStarting(a0, a1);
    return 0;
}

static int GenL_b2World_Explode(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2ExplosionDef tmp1;
    const b2ExplosionDef *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_b2ExplosionDef(L, 2, &tmp1);
        a1 = &tmp1;
    }
    b2World_Explode(a0, a1);
    return 0;
}

static int GenL_b2World_GetAwakeBodyCount(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    int rv = b2World_GetAwakeBodyCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_b2World_GetCounters(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2Counters rv = b2World_GetCounters(a0);
    GenPush_b2Counters(L, &rv);
    return 1;
}

static int GenL_b2World_GetGravity(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2Vec2 rv = b2World_GetGravity(a0);
    GenPush_b2Vec2(L, &rv);
    return 1;
}

static int GenL_b2World_GetHitEventThreshold(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    float rv = b2World_GetHitEventThreshold(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2World_GetMaximumLinearSpeed(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    float rv = b2World_GetMaximumLinearSpeed(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2World_GetProfile(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2Profile rv = b2World_GetProfile(a0);
    GenPush_b2Profile(L, &rv);
    return 1;
}

static int GenL_b2World_GetRestitutionThreshold(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    float rv = b2World_GetRestitutionThreshold(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_b2World_IsContinuousEnabled(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    bool rv = b2World_IsContinuousEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2World_IsSleepingEnabled(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    bool rv = b2World_IsSleepingEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2World_IsValid(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    bool rv = b2World_IsValid(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2World_IsWarmStartingEnabled(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    bool rv = b2World_IsWarmStartingEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_b2World_RebuildStaticTree(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2World_RebuildStaticTree(a0);
    return 0;
}

static int GenL_b2World_SetContactTuning(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    b2World_SetContactTuning(a0, a1, a2, a3);
    return 0;
}

static int GenL_b2World_SetGravity(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(L, 2, &a1);
    b2World_SetGravity(a0, a1);
    return 0;
}

static int GenL_b2World_SetHitEventThreshold(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2World_SetHitEventThreshold(a0, a1);
    return 0;
}

static int GenL_b2World_SetMaximumLinearSpeed(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2World_SetMaximumLinearSpeed(a0, a1);
    return 0;
}

static int GenL_b2World_SetRestitutionThreshold(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    b2World_SetRestitutionThreshold(a0, a1);
    return 0;
}

static int GenL_b2World_Step(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    b2World_Step(a0, a1, a2);
    return 0;
}

static int GenL_b2Yield(lua_State *L)
{
    (void)L;
    b2Yield();
    return 0;
}

int SDLStaticGen_OpenLua_b2(lua_State *L);
int SDLStaticGen_OpenLua_b2(lua_State *L)
{
    lua_createtable(L, 0, 386);
    lua_pushcfunction(L, GenL_b2Atan2);
    lua_setfield(L, -2, "Atan2");
    lua_pushcfunction(L, GenL_b2Body_ApplyAngularImpulse);
    lua_setfield(L, -2, "Body_ApplyAngularImpulse");
    lua_pushcfunction(L, GenL_b2Body_ApplyForce);
    lua_setfield(L, -2, "Body_ApplyForce");
    lua_pushcfunction(L, GenL_b2Body_ApplyForceToCenter);
    lua_setfield(L, -2, "Body_ApplyForceToCenter");
    lua_pushcfunction(L, GenL_b2Body_ApplyLinearImpulse);
    lua_setfield(L, -2, "Body_ApplyLinearImpulse");
    lua_pushcfunction(L, GenL_b2Body_ApplyLinearImpulseToCenter);
    lua_setfield(L, -2, "Body_ApplyLinearImpulseToCenter");
    lua_pushcfunction(L, GenL_b2Body_ApplyMassFromShapes);
    lua_setfield(L, -2, "Body_ApplyMassFromShapes");
    lua_pushcfunction(L, GenL_b2Body_ApplyTorque);
    lua_setfield(L, -2, "Body_ApplyTorque");
    lua_pushcfunction(L, GenL_b2Body_ComputeAABB);
    lua_setfield(L, -2, "Body_ComputeAABB");
    lua_pushcfunction(L, GenL_b2Body_Disable);
    lua_setfield(L, -2, "Body_Disable");
    lua_pushcfunction(L, GenL_b2Body_Enable);
    lua_setfield(L, -2, "Body_Enable");
    lua_pushcfunction(L, GenL_b2Body_EnableContactEvents);
    lua_setfield(L, -2, "Body_EnableContactEvents");
    lua_pushcfunction(L, GenL_b2Body_EnableHitEvents);
    lua_setfield(L, -2, "Body_EnableHitEvents");
    lua_pushcfunction(L, GenL_b2Body_EnableSleep);
    lua_setfield(L, -2, "Body_EnableSleep");
    lua_pushcfunction(L, GenL_b2Body_GetAngularDamping);
    lua_setfield(L, -2, "Body_GetAngularDamping");
    lua_pushcfunction(L, GenL_b2Body_GetAngularVelocity);
    lua_setfield(L, -2, "Body_GetAngularVelocity");
    lua_pushcfunction(L, GenL_b2Body_GetContactCapacity);
    lua_setfield(L, -2, "Body_GetContactCapacity");
    lua_pushcfunction(L, GenL_b2Body_GetContactData);
    lua_setfield(L, -2, "Body_GetContactData");
    lua_pushcfunction(L, GenL_b2Body_GetGravityScale);
    lua_setfield(L, -2, "Body_GetGravityScale");
    lua_pushcfunction(L, GenL_b2Body_GetJointCount);
    lua_setfield(L, -2, "Body_GetJointCount");
    lua_pushcfunction(L, GenL_b2Body_GetJoints);
    lua_setfield(L, -2, "Body_GetJoints");
    lua_pushcfunction(L, GenL_b2Body_GetLinearDamping);
    lua_setfield(L, -2, "Body_GetLinearDamping");
    lua_pushcfunction(L, GenL_b2Body_GetLinearVelocity);
    lua_setfield(L, -2, "Body_GetLinearVelocity");
    lua_pushcfunction(L, GenL_b2Body_GetLocalCenterOfMass);
    lua_setfield(L, -2, "Body_GetLocalCenterOfMass");
    lua_pushcfunction(L, GenL_b2Body_GetLocalPoint);
    lua_setfield(L, -2, "Body_GetLocalPoint");
    lua_pushcfunction(L, GenL_b2Body_GetLocalPointVelocity);
    lua_setfield(L, -2, "Body_GetLocalPointVelocity");
    lua_pushcfunction(L, GenL_b2Body_GetLocalVector);
    lua_setfield(L, -2, "Body_GetLocalVector");
    lua_pushcfunction(L, GenL_b2Body_GetMass);
    lua_setfield(L, -2, "Body_GetMass");
    lua_pushcfunction(L, GenL_b2Body_GetMassData);
    lua_setfield(L, -2, "Body_GetMassData");
    lua_pushcfunction(L, GenL_b2Body_GetName);
    lua_setfield(L, -2, "Body_GetName");
    lua_pushcfunction(L, GenL_b2Body_GetPosition);
    lua_setfield(L, -2, "Body_GetPosition");
    lua_pushcfunction(L, GenL_b2Body_GetRotation);
    lua_setfield(L, -2, "Body_GetRotation");
    lua_pushcfunction(L, GenL_b2Body_GetRotationalInertia);
    lua_setfield(L, -2, "Body_GetRotationalInertia");
    lua_pushcfunction(L, GenL_b2Body_GetShapeCount);
    lua_setfield(L, -2, "Body_GetShapeCount");
    lua_pushcfunction(L, GenL_b2Body_GetShapes);
    lua_setfield(L, -2, "Body_GetShapes");
    lua_pushcfunction(L, GenL_b2Body_GetSleepThreshold);
    lua_setfield(L, -2, "Body_GetSleepThreshold");
    lua_pushcfunction(L, GenL_b2Body_GetTransform);
    lua_setfield(L, -2, "Body_GetTransform");
    lua_pushcfunction(L, GenL_b2Body_GetType);
    lua_setfield(L, -2, "Body_GetType");
    lua_pushcfunction(L, GenL_b2Body_GetWorld);
    lua_setfield(L, -2, "Body_GetWorld");
    lua_pushcfunction(L, GenL_b2Body_GetWorldCenterOfMass);
    lua_setfield(L, -2, "Body_GetWorldCenterOfMass");
    lua_pushcfunction(L, GenL_b2Body_GetWorldPoint);
    lua_setfield(L, -2, "Body_GetWorldPoint");
    lua_pushcfunction(L, GenL_b2Body_GetWorldPointVelocity);
    lua_setfield(L, -2, "Body_GetWorldPointVelocity");
    lua_pushcfunction(L, GenL_b2Body_GetWorldVector);
    lua_setfield(L, -2, "Body_GetWorldVector");
    lua_pushcfunction(L, GenL_b2Body_IsAwake);
    lua_setfield(L, -2, "Body_IsAwake");
    lua_pushcfunction(L, GenL_b2Body_IsBullet);
    lua_setfield(L, -2, "Body_IsBullet");
    lua_pushcfunction(L, GenL_b2Body_IsEnabled);
    lua_setfield(L, -2, "Body_IsEnabled");
    lua_pushcfunction(L, GenL_b2Body_IsFixedRotation);
    lua_setfield(L, -2, "Body_IsFixedRotation");
    lua_pushcfunction(L, GenL_b2Body_IsSleepEnabled);
    lua_setfield(L, -2, "Body_IsSleepEnabled");
    lua_pushcfunction(L, GenL_b2Body_IsValid);
    lua_setfield(L, -2, "Body_IsValid");
    lua_pushcfunction(L, GenL_b2Body_SetAngularDamping);
    lua_setfield(L, -2, "Body_SetAngularDamping");
    lua_pushcfunction(L, GenL_b2Body_SetAngularVelocity);
    lua_setfield(L, -2, "Body_SetAngularVelocity");
    lua_pushcfunction(L, GenL_b2Body_SetAwake);
    lua_setfield(L, -2, "Body_SetAwake");
    lua_pushcfunction(L, GenL_b2Body_SetBullet);
    lua_setfield(L, -2, "Body_SetBullet");
    lua_pushcfunction(L, GenL_b2Body_SetFixedRotation);
    lua_setfield(L, -2, "Body_SetFixedRotation");
    lua_pushcfunction(L, GenL_b2Body_SetGravityScale);
    lua_setfield(L, -2, "Body_SetGravityScale");
    lua_pushcfunction(L, GenL_b2Body_SetLinearDamping);
    lua_setfield(L, -2, "Body_SetLinearDamping");
    lua_pushcfunction(L, GenL_b2Body_SetLinearVelocity);
    lua_setfield(L, -2, "Body_SetLinearVelocity");
    lua_pushcfunction(L, GenL_b2Body_SetMassData);
    lua_setfield(L, -2, "Body_SetMassData");
    lua_pushcfunction(L, GenL_b2Body_SetName);
    lua_setfield(L, -2, "Body_SetName");
    lua_pushcfunction(L, GenL_b2Body_SetSleepThreshold);
    lua_setfield(L, -2, "Body_SetSleepThreshold");
    lua_pushcfunction(L, GenL_b2Body_SetTargetTransform);
    lua_setfield(L, -2, "Body_SetTargetTransform");
    lua_pushcfunction(L, GenL_b2Body_SetTransform);
    lua_setfield(L, -2, "Body_SetTransform");
    lua_pushcfunction(L, GenL_b2Body_SetType);
    lua_setfield(L, -2, "Body_SetType");
    lua_pushcfunction(L, GenL_b2Chain_GetFriction);
    lua_setfield(L, -2, "Chain_GetFriction");
    lua_pushcfunction(L, GenL_b2Chain_GetMaterial);
    lua_setfield(L, -2, "Chain_GetMaterial");
    lua_pushcfunction(L, GenL_b2Chain_GetRestitution);
    lua_setfield(L, -2, "Chain_GetRestitution");
    lua_pushcfunction(L, GenL_b2Chain_GetSegmentCount);
    lua_setfield(L, -2, "Chain_GetSegmentCount");
    lua_pushcfunction(L, GenL_b2Chain_GetSegments);
    lua_setfield(L, -2, "Chain_GetSegments");
    lua_pushcfunction(L, GenL_b2Chain_GetWorld);
    lua_setfield(L, -2, "Chain_GetWorld");
    lua_pushcfunction(L, GenL_b2Chain_IsValid);
    lua_setfield(L, -2, "Chain_IsValid");
    lua_pushcfunction(L, GenL_b2Chain_SetFriction);
    lua_setfield(L, -2, "Chain_SetFriction");
    lua_pushcfunction(L, GenL_b2Chain_SetMaterial);
    lua_setfield(L, -2, "Chain_SetMaterial");
    lua_pushcfunction(L, GenL_b2Chain_SetRestitution);
    lua_setfield(L, -2, "Chain_SetRestitution");
    lua_pushcfunction(L, GenL_b2ClipVector);
    lua_setfield(L, -2, "ClipVector");
    lua_pushcfunction(L, GenL_b2CollideCapsuleAndCircle);
    lua_setfield(L, -2, "CollideCapsuleAndCircle");
    lua_pushcfunction(L, GenL_b2CollideCapsules);
    lua_setfield(L, -2, "CollideCapsules");
    lua_pushcfunction(L, GenL_b2CollideChainSegmentAndCapsule);
    lua_setfield(L, -2, "CollideChainSegmentAndCapsule");
    lua_pushcfunction(L, GenL_b2CollideChainSegmentAndCircle);
    lua_setfield(L, -2, "CollideChainSegmentAndCircle");
    lua_pushcfunction(L, GenL_b2CollideChainSegmentAndPolygon);
    lua_setfield(L, -2, "CollideChainSegmentAndPolygon");
    lua_pushcfunction(L, GenL_b2CollideCircles);
    lua_setfield(L, -2, "CollideCircles");
    lua_pushcfunction(L, GenL_b2CollidePolygonAndCapsule);
    lua_setfield(L, -2, "CollidePolygonAndCapsule");
    lua_pushcfunction(L, GenL_b2CollidePolygonAndCircle);
    lua_setfield(L, -2, "CollidePolygonAndCircle");
    lua_pushcfunction(L, GenL_b2CollidePolygons);
    lua_setfield(L, -2, "CollidePolygons");
    lua_pushcfunction(L, GenL_b2CollideSegmentAndCapsule);
    lua_setfield(L, -2, "CollideSegmentAndCapsule");
    lua_pushcfunction(L, GenL_b2CollideSegmentAndCircle);
    lua_setfield(L, -2, "CollideSegmentAndCircle");
    lua_pushcfunction(L, GenL_b2CollideSegmentAndPolygon);
    lua_setfield(L, -2, "CollideSegmentAndPolygon");
    lua_pushcfunction(L, GenL_b2ComputeCapsuleAABB);
    lua_setfield(L, -2, "ComputeCapsuleAABB");
    lua_pushcfunction(L, GenL_b2ComputeCapsuleMass);
    lua_setfield(L, -2, "ComputeCapsuleMass");
    lua_pushcfunction(L, GenL_b2ComputeCircleAABB);
    lua_setfield(L, -2, "ComputeCircleAABB");
    lua_pushcfunction(L, GenL_b2ComputeCircleMass);
    lua_setfield(L, -2, "ComputeCircleMass");
    lua_pushcfunction(L, GenL_b2ComputeCosSin);
    lua_setfield(L, -2, "ComputeCosSin");
    lua_pushcfunction(L, GenL_b2ComputeHull);
    lua_setfield(L, -2, "ComputeHull");
    lua_pushcfunction(L, GenL_b2ComputePolygonAABB);
    lua_setfield(L, -2, "ComputePolygonAABB");
    lua_pushcfunction(L, GenL_b2ComputePolygonMass);
    lua_setfield(L, -2, "ComputePolygonMass");
    lua_pushcfunction(L, GenL_b2ComputeRotationBetweenUnitVectors);
    lua_setfield(L, -2, "ComputeRotationBetweenUnitVectors");
    lua_pushcfunction(L, GenL_b2ComputeSegmentAABB);
    lua_setfield(L, -2, "ComputeSegmentAABB");
    lua_pushcfunction(L, GenL_b2CreateBody);
    lua_setfield(L, -2, "CreateBody");
    lua_pushcfunction(L, GenL_b2CreateCapsuleShape);
    lua_setfield(L, -2, "CreateCapsuleShape");
    lua_pushcfunction(L, GenL_b2CreateChain);
    lua_setfield(L, -2, "CreateChain");
    lua_pushcfunction(L, GenL_b2CreateCircleShape);
    lua_setfield(L, -2, "CreateCircleShape");
    lua_pushcfunction(L, GenL_b2CreateDistanceJoint);
    lua_setfield(L, -2, "CreateDistanceJoint");
    lua_pushcfunction(L, GenL_b2CreateFilterJoint);
    lua_setfield(L, -2, "CreateFilterJoint");
    lua_pushcfunction(L, GenL_b2CreateMotorJoint);
    lua_setfield(L, -2, "CreateMotorJoint");
    lua_pushcfunction(L, GenL_b2CreateMouseJoint);
    lua_setfield(L, -2, "CreateMouseJoint");
    lua_pushcfunction(L, GenL_b2CreatePolygonShape);
    lua_setfield(L, -2, "CreatePolygonShape");
    lua_pushcfunction(L, GenL_b2CreatePrismaticJoint);
    lua_setfield(L, -2, "CreatePrismaticJoint");
    lua_pushcfunction(L, GenL_b2CreateRevoluteJoint);
    lua_setfield(L, -2, "CreateRevoluteJoint");
    lua_pushcfunction(L, GenL_b2CreateSegmentShape);
    lua_setfield(L, -2, "CreateSegmentShape");
    lua_pushcfunction(L, GenL_b2CreateWeldJoint);
    lua_setfield(L, -2, "CreateWeldJoint");
    lua_pushcfunction(L, GenL_b2CreateWheelJoint);
    lua_setfield(L, -2, "CreateWheelJoint");
    lua_pushcfunction(L, GenL_b2CreateWorld);
    lua_setfield(L, -2, "CreateWorld");
    lua_pushcfunction(L, GenL_b2DefaultBodyDef);
    lua_setfield(L, -2, "DefaultBodyDef");
    lua_pushcfunction(L, GenL_b2DefaultChainDef);
    lua_setfield(L, -2, "DefaultChainDef");
    lua_pushcfunction(L, GenL_b2DefaultExplosionDef);
    lua_setfield(L, -2, "DefaultExplosionDef");
    lua_pushcfunction(L, GenL_b2DefaultFilter);
    lua_setfield(L, -2, "DefaultFilter");
    lua_pushcfunction(L, GenL_b2DefaultQueryFilter);
    lua_setfield(L, -2, "DefaultQueryFilter");
    lua_pushcfunction(L, GenL_b2DefaultShapeDef);
    lua_setfield(L, -2, "DefaultShapeDef");
    lua_pushcfunction(L, GenL_b2DefaultSurfaceMaterial);
    lua_setfield(L, -2, "DefaultSurfaceMaterial");
    lua_pushcfunction(L, GenL_b2DefaultWorldDef);
    lua_setfield(L, -2, "DefaultWorldDef");
    lua_pushcfunction(L, GenL_b2DestroyBody);
    lua_setfield(L, -2, "DestroyBody");
    lua_pushcfunction(L, GenL_b2DestroyChain);
    lua_setfield(L, -2, "DestroyChain");
    lua_pushcfunction(L, GenL_b2DestroyJoint);
    lua_setfield(L, -2, "DestroyJoint");
    lua_pushcfunction(L, GenL_b2DestroyShape);
    lua_setfield(L, -2, "DestroyShape");
    lua_pushcfunction(L, GenL_b2DestroyWorld);
    lua_setfield(L, -2, "DestroyWorld");
    lua_pushcfunction(L, GenL_b2DistanceJoint_EnableLimit);
    lua_setfield(L, -2, "DistanceJoint_EnableLimit");
    lua_pushcfunction(L, GenL_b2DistanceJoint_EnableMotor);
    lua_setfield(L, -2, "DistanceJoint_EnableMotor");
    lua_pushcfunction(L, GenL_b2DistanceJoint_EnableSpring);
    lua_setfield(L, -2, "DistanceJoint_EnableSpring");
    lua_pushcfunction(L, GenL_b2DistanceJoint_GetCurrentLength);
    lua_setfield(L, -2, "DistanceJoint_GetCurrentLength");
    lua_pushcfunction(L, GenL_b2DistanceJoint_GetLength);
    lua_setfield(L, -2, "DistanceJoint_GetLength");
    lua_pushcfunction(L, GenL_b2DistanceJoint_GetMaxLength);
    lua_setfield(L, -2, "DistanceJoint_GetMaxLength");
    lua_pushcfunction(L, GenL_b2DistanceJoint_GetMaxMotorForce);
    lua_setfield(L, -2, "DistanceJoint_GetMaxMotorForce");
    lua_pushcfunction(L, GenL_b2DistanceJoint_GetMinLength);
    lua_setfield(L, -2, "DistanceJoint_GetMinLength");
    lua_pushcfunction(L, GenL_b2DistanceJoint_GetMotorForce);
    lua_setfield(L, -2, "DistanceJoint_GetMotorForce");
    lua_pushcfunction(L, GenL_b2DistanceJoint_GetMotorSpeed);
    lua_setfield(L, -2, "DistanceJoint_GetMotorSpeed");
    lua_pushcfunction(L, GenL_b2DistanceJoint_GetSpringDampingRatio);
    lua_setfield(L, -2, "DistanceJoint_GetSpringDampingRatio");
    lua_pushcfunction(L, GenL_b2DistanceJoint_GetSpringHertz);
    lua_setfield(L, -2, "DistanceJoint_GetSpringHertz");
    lua_pushcfunction(L, GenL_b2DistanceJoint_IsLimitEnabled);
    lua_setfield(L, -2, "DistanceJoint_IsLimitEnabled");
    lua_pushcfunction(L, GenL_b2DistanceJoint_IsMotorEnabled);
    lua_setfield(L, -2, "DistanceJoint_IsMotorEnabled");
    lua_pushcfunction(L, GenL_b2DistanceJoint_IsSpringEnabled);
    lua_setfield(L, -2, "DistanceJoint_IsSpringEnabled");
    lua_pushcfunction(L, GenL_b2DistanceJoint_SetLength);
    lua_setfield(L, -2, "DistanceJoint_SetLength");
    lua_pushcfunction(L, GenL_b2DistanceJoint_SetLengthRange);
    lua_setfield(L, -2, "DistanceJoint_SetLengthRange");
    lua_pushcfunction(L, GenL_b2DistanceJoint_SetMaxMotorForce);
    lua_setfield(L, -2, "DistanceJoint_SetMaxMotorForce");
    lua_pushcfunction(L, GenL_b2DistanceJoint_SetMotorSpeed);
    lua_setfield(L, -2, "DistanceJoint_SetMotorSpeed");
    lua_pushcfunction(L, GenL_b2DistanceJoint_SetSpringDampingRatio);
    lua_setfield(L, -2, "DistanceJoint_SetSpringDampingRatio");
    lua_pushcfunction(L, GenL_b2DistanceJoint_SetSpringHertz);
    lua_setfield(L, -2, "DistanceJoint_SetSpringHertz");
    lua_pushcfunction(L, GenL_b2DynamicTree_CreateProxy);
    lua_setfield(L, -2, "DynamicTree_CreateProxy");
    lua_pushcfunction(L, GenL_b2DynamicTree_Destroy);
    lua_setfield(L, -2, "DynamicTree_Destroy");
    lua_pushcfunction(L, GenL_b2DynamicTree_DestroyProxy);
    lua_setfield(L, -2, "DynamicTree_DestroyProxy");
    lua_pushcfunction(L, GenL_b2DynamicTree_EnlargeProxy);
    lua_setfield(L, -2, "DynamicTree_EnlargeProxy");
    lua_pushcfunction(L, GenL_b2DynamicTree_GetAABB);
    lua_setfield(L, -2, "DynamicTree_GetAABB");
    lua_pushcfunction(L, GenL_b2DynamicTree_GetAreaRatio);
    lua_setfield(L, -2, "DynamicTree_GetAreaRatio");
    lua_pushcfunction(L, GenL_b2DynamicTree_GetByteCount);
    lua_setfield(L, -2, "DynamicTree_GetByteCount");
    lua_pushcfunction(L, GenL_b2DynamicTree_GetCategoryBits);
    lua_setfield(L, -2, "DynamicTree_GetCategoryBits");
    lua_pushcfunction(L, GenL_b2DynamicTree_GetHeight);
    lua_setfield(L, -2, "DynamicTree_GetHeight");
    lua_pushcfunction(L, GenL_b2DynamicTree_GetProxyCount);
    lua_setfield(L, -2, "DynamicTree_GetProxyCount");
    lua_pushcfunction(L, GenL_b2DynamicTree_GetRootBounds);
    lua_setfield(L, -2, "DynamicTree_GetRootBounds");
    lua_pushcfunction(L, GenL_b2DynamicTree_GetUserData);
    lua_setfield(L, -2, "DynamicTree_GetUserData");
    lua_pushcfunction(L, GenL_b2DynamicTree_MoveProxy);
    lua_setfield(L, -2, "DynamicTree_MoveProxy");
    lua_pushcfunction(L, GenL_b2DynamicTree_Rebuild);
    lua_setfield(L, -2, "DynamicTree_Rebuild");
    lua_pushcfunction(L, GenL_b2DynamicTree_SetCategoryBits);
    lua_setfield(L, -2, "DynamicTree_SetCategoryBits");
    lua_pushcfunction(L, GenL_b2DynamicTree_Validate);
    lua_setfield(L, -2, "DynamicTree_Validate");
    lua_pushcfunction(L, GenL_b2DynamicTree_ValidateNoEnlarged);
    lua_setfield(L, -2, "DynamicTree_ValidateNoEnlarged");
    lua_pushcfunction(L, GenL_b2GetByteCount);
    lua_setfield(L, -2, "GetByteCount");
    lua_pushcfunction(L, GenL_b2GetLengthUnitsPerMeter);
    lua_setfield(L, -2, "GetLengthUnitsPerMeter");
    lua_pushcfunction(L, GenL_b2GetMilliseconds);
    lua_setfield(L, -2, "GetMilliseconds");
    lua_pushcfunction(L, GenL_b2GetMillisecondsAndReset);
    lua_setfield(L, -2, "GetMillisecondsAndReset");
    lua_pushcfunction(L, GenL_b2GetSweepTransform);
    lua_setfield(L, -2, "GetSweepTransform");
    lua_pushcfunction(L, GenL_b2GetTicks);
    lua_setfield(L, -2, "GetTicks");
    lua_pushcfunction(L, GenL_b2GetVersion);
    lua_setfield(L, -2, "GetVersion");
    lua_pushcfunction(L, GenL_b2InternalAssertFcn);
    lua_setfield(L, -2, "InternalAssertFcn");
    lua_pushcfunction(L, GenL_b2IsValidAABB);
    lua_setfield(L, -2, "IsValidAABB");
    lua_pushcfunction(L, GenL_b2IsValidFloat);
    lua_setfield(L, -2, "IsValidFloat");
    lua_pushcfunction(L, GenL_b2IsValidPlane);
    lua_setfield(L, -2, "IsValidPlane");
    lua_pushcfunction(L, GenL_b2IsValidRay);
    lua_setfield(L, -2, "IsValidRay");
    lua_pushcfunction(L, GenL_b2IsValidRotation);
    lua_setfield(L, -2, "IsValidRotation");
    lua_pushcfunction(L, GenL_b2IsValidVec2);
    lua_setfield(L, -2, "IsValidVec2");
    lua_pushcfunction(L, GenL_b2Joint_GetAngularSeparation);
    lua_setfield(L, -2, "Joint_GetAngularSeparation");
    lua_pushcfunction(L, GenL_b2Joint_GetBodyA);
    lua_setfield(L, -2, "Joint_GetBodyA");
    lua_pushcfunction(L, GenL_b2Joint_GetBodyB);
    lua_setfield(L, -2, "Joint_GetBodyB");
    lua_pushcfunction(L, GenL_b2Joint_GetCollideConnected);
    lua_setfield(L, -2, "Joint_GetCollideConnected");
    lua_pushcfunction(L, GenL_b2Joint_GetConstraintForce);
    lua_setfield(L, -2, "Joint_GetConstraintForce");
    lua_pushcfunction(L, GenL_b2Joint_GetConstraintTorque);
    lua_setfield(L, -2, "Joint_GetConstraintTorque");
    lua_pushcfunction(L, GenL_b2Joint_GetConstraintTuning);
    lua_setfield(L, -2, "Joint_GetConstraintTuning");
    lua_pushcfunction(L, GenL_b2Joint_GetLinearSeparation);
    lua_setfield(L, -2, "Joint_GetLinearSeparation");
    lua_pushcfunction(L, GenL_b2Joint_GetLocalAnchorA);
    lua_setfield(L, -2, "Joint_GetLocalAnchorA");
    lua_pushcfunction(L, GenL_b2Joint_GetLocalAnchorB);
    lua_setfield(L, -2, "Joint_GetLocalAnchorB");
    lua_pushcfunction(L, GenL_b2Joint_GetLocalAxisA);
    lua_setfield(L, -2, "Joint_GetLocalAxisA");
    lua_pushcfunction(L, GenL_b2Joint_GetReferenceAngle);
    lua_setfield(L, -2, "Joint_GetReferenceAngle");
    lua_pushcfunction(L, GenL_b2Joint_GetType);
    lua_setfield(L, -2, "Joint_GetType");
    lua_pushcfunction(L, GenL_b2Joint_GetWorld);
    lua_setfield(L, -2, "Joint_GetWorld");
    lua_pushcfunction(L, GenL_b2Joint_IsValid);
    lua_setfield(L, -2, "Joint_IsValid");
    lua_pushcfunction(L, GenL_b2Joint_SetCollideConnected);
    lua_setfield(L, -2, "Joint_SetCollideConnected");
    lua_pushcfunction(L, GenL_b2Joint_SetConstraintTuning);
    lua_setfield(L, -2, "Joint_SetConstraintTuning");
    lua_pushcfunction(L, GenL_b2Joint_SetLocalAnchorA);
    lua_setfield(L, -2, "Joint_SetLocalAnchorA");
    lua_pushcfunction(L, GenL_b2Joint_SetLocalAnchorB);
    lua_setfield(L, -2, "Joint_SetLocalAnchorB");
    lua_pushcfunction(L, GenL_b2Joint_SetLocalAxisA);
    lua_setfield(L, -2, "Joint_SetLocalAxisA");
    lua_pushcfunction(L, GenL_b2Joint_SetReferenceAngle);
    lua_setfield(L, -2, "Joint_SetReferenceAngle");
    lua_pushcfunction(L, GenL_b2Joint_WakeBodies);
    lua_setfield(L, -2, "Joint_WakeBodies");
    lua_pushcfunction(L, GenL_b2MakeBox);
    lua_setfield(L, -2, "MakeBox");
    lua_pushcfunction(L, GenL_b2MakeOffsetBox);
    lua_setfield(L, -2, "MakeOffsetBox");
    lua_pushcfunction(L, GenL_b2MakeOffsetPolygon);
    lua_setfield(L, -2, "MakeOffsetPolygon");
    lua_pushcfunction(L, GenL_b2MakeOffsetProxy);
    lua_setfield(L, -2, "MakeOffsetProxy");
    lua_pushcfunction(L, GenL_b2MakeOffsetRoundedBox);
    lua_setfield(L, -2, "MakeOffsetRoundedBox");
    lua_pushcfunction(L, GenL_b2MakeOffsetRoundedPolygon);
    lua_setfield(L, -2, "MakeOffsetRoundedPolygon");
    lua_pushcfunction(L, GenL_b2MakePolygon);
    lua_setfield(L, -2, "MakePolygon");
    lua_pushcfunction(L, GenL_b2MakeProxy);
    lua_setfield(L, -2, "MakeProxy");
    lua_pushcfunction(L, GenL_b2MakeRoundedBox);
    lua_setfield(L, -2, "MakeRoundedBox");
    lua_pushcfunction(L, GenL_b2MakeSquare);
    lua_setfield(L, -2, "MakeSquare");
    lua_pushcfunction(L, GenL_b2MotorJoint_GetAngularOffset);
    lua_setfield(L, -2, "MotorJoint_GetAngularOffset");
    lua_pushcfunction(L, GenL_b2MotorJoint_GetCorrectionFactor);
    lua_setfield(L, -2, "MotorJoint_GetCorrectionFactor");
    lua_pushcfunction(L, GenL_b2MotorJoint_GetLinearOffset);
    lua_setfield(L, -2, "MotorJoint_GetLinearOffset");
    lua_pushcfunction(L, GenL_b2MotorJoint_GetMaxForce);
    lua_setfield(L, -2, "MotorJoint_GetMaxForce");
    lua_pushcfunction(L, GenL_b2MotorJoint_GetMaxTorque);
    lua_setfield(L, -2, "MotorJoint_GetMaxTorque");
    lua_pushcfunction(L, GenL_b2MotorJoint_SetAngularOffset);
    lua_setfield(L, -2, "MotorJoint_SetAngularOffset");
    lua_pushcfunction(L, GenL_b2MotorJoint_SetCorrectionFactor);
    lua_setfield(L, -2, "MotorJoint_SetCorrectionFactor");
    lua_pushcfunction(L, GenL_b2MotorJoint_SetLinearOffset);
    lua_setfield(L, -2, "MotorJoint_SetLinearOffset");
    lua_pushcfunction(L, GenL_b2MotorJoint_SetMaxForce);
    lua_setfield(L, -2, "MotorJoint_SetMaxForce");
    lua_pushcfunction(L, GenL_b2MotorJoint_SetMaxTorque);
    lua_setfield(L, -2, "MotorJoint_SetMaxTorque");
    lua_pushcfunction(L, GenL_b2MouseJoint_GetMaxForce);
    lua_setfield(L, -2, "MouseJoint_GetMaxForce");
    lua_pushcfunction(L, GenL_b2MouseJoint_GetSpringDampingRatio);
    lua_setfield(L, -2, "MouseJoint_GetSpringDampingRatio");
    lua_pushcfunction(L, GenL_b2MouseJoint_GetSpringHertz);
    lua_setfield(L, -2, "MouseJoint_GetSpringHertz");
    lua_pushcfunction(L, GenL_b2MouseJoint_GetTarget);
    lua_setfield(L, -2, "MouseJoint_GetTarget");
    lua_pushcfunction(L, GenL_b2MouseJoint_SetMaxForce);
    lua_setfield(L, -2, "MouseJoint_SetMaxForce");
    lua_pushcfunction(L, GenL_b2MouseJoint_SetSpringDampingRatio);
    lua_setfield(L, -2, "MouseJoint_SetSpringDampingRatio");
    lua_pushcfunction(L, GenL_b2MouseJoint_SetSpringHertz);
    lua_setfield(L, -2, "MouseJoint_SetSpringHertz");
    lua_pushcfunction(L, GenL_b2MouseJoint_SetTarget);
    lua_setfield(L, -2, "MouseJoint_SetTarget");
    lua_pushcfunction(L, GenL_b2PointInCapsule);
    lua_setfield(L, -2, "PointInCapsule");
    lua_pushcfunction(L, GenL_b2PointInCircle);
    lua_setfield(L, -2, "PointInCircle");
    lua_pushcfunction(L, GenL_b2PointInPolygon);
    lua_setfield(L, -2, "PointInPolygon");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_EnableLimit);
    lua_setfield(L, -2, "PrismaticJoint_EnableLimit");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_EnableMotor);
    lua_setfield(L, -2, "PrismaticJoint_EnableMotor");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_EnableSpring);
    lua_setfield(L, -2, "PrismaticJoint_EnableSpring");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_GetLowerLimit);
    lua_setfield(L, -2, "PrismaticJoint_GetLowerLimit");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_GetMaxMotorForce);
    lua_setfield(L, -2, "PrismaticJoint_GetMaxMotorForce");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_GetMotorForce);
    lua_setfield(L, -2, "PrismaticJoint_GetMotorForce");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_GetMotorSpeed);
    lua_setfield(L, -2, "PrismaticJoint_GetMotorSpeed");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_GetSpeed);
    lua_setfield(L, -2, "PrismaticJoint_GetSpeed");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_GetSpringDampingRatio);
    lua_setfield(L, -2, "PrismaticJoint_GetSpringDampingRatio");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_GetSpringHertz);
    lua_setfield(L, -2, "PrismaticJoint_GetSpringHertz");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_GetTargetTranslation);
    lua_setfield(L, -2, "PrismaticJoint_GetTargetTranslation");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_GetTranslation);
    lua_setfield(L, -2, "PrismaticJoint_GetTranslation");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_GetUpperLimit);
    lua_setfield(L, -2, "PrismaticJoint_GetUpperLimit");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_IsLimitEnabled);
    lua_setfield(L, -2, "PrismaticJoint_IsLimitEnabled");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_IsMotorEnabled);
    lua_setfield(L, -2, "PrismaticJoint_IsMotorEnabled");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_IsSpringEnabled);
    lua_setfield(L, -2, "PrismaticJoint_IsSpringEnabled");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_SetLimits);
    lua_setfield(L, -2, "PrismaticJoint_SetLimits");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_SetMaxMotorForce);
    lua_setfield(L, -2, "PrismaticJoint_SetMaxMotorForce");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_SetMotorSpeed);
    lua_setfield(L, -2, "PrismaticJoint_SetMotorSpeed");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_SetSpringDampingRatio);
    lua_setfield(L, -2, "PrismaticJoint_SetSpringDampingRatio");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_SetSpringHertz);
    lua_setfield(L, -2, "PrismaticJoint_SetSpringHertz");
    lua_pushcfunction(L, GenL_b2PrismaticJoint_SetTargetTranslation);
    lua_setfield(L, -2, "PrismaticJoint_SetTargetTranslation");
    lua_pushcfunction(L, GenL_b2RayCastCapsule);
    lua_setfield(L, -2, "RayCastCapsule");
    lua_pushcfunction(L, GenL_b2RayCastCircle);
    lua_setfield(L, -2, "RayCastCircle");
    lua_pushcfunction(L, GenL_b2RayCastPolygon);
    lua_setfield(L, -2, "RayCastPolygon");
    lua_pushcfunction(L, GenL_b2RayCastSegment);
    lua_setfield(L, -2, "RayCastSegment");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_EnableLimit);
    lua_setfield(L, -2, "RevoluteJoint_EnableLimit");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_EnableMotor);
    lua_setfield(L, -2, "RevoluteJoint_EnableMotor");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_EnableSpring);
    lua_setfield(L, -2, "RevoluteJoint_EnableSpring");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_GetAngle);
    lua_setfield(L, -2, "RevoluteJoint_GetAngle");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_GetLowerLimit);
    lua_setfield(L, -2, "RevoluteJoint_GetLowerLimit");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_GetMaxMotorTorque);
    lua_setfield(L, -2, "RevoluteJoint_GetMaxMotorTorque");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_GetMotorSpeed);
    lua_setfield(L, -2, "RevoluteJoint_GetMotorSpeed");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_GetMotorTorque);
    lua_setfield(L, -2, "RevoluteJoint_GetMotorTorque");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_GetSpringDampingRatio);
    lua_setfield(L, -2, "RevoluteJoint_GetSpringDampingRatio");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_GetSpringHertz);
    lua_setfield(L, -2, "RevoluteJoint_GetSpringHertz");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_GetTargetAngle);
    lua_setfield(L, -2, "RevoluteJoint_GetTargetAngle");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_GetUpperLimit);
    lua_setfield(L, -2, "RevoluteJoint_GetUpperLimit");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_IsLimitEnabled);
    lua_setfield(L, -2, "RevoluteJoint_IsLimitEnabled");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_IsMotorEnabled);
    lua_setfield(L, -2, "RevoluteJoint_IsMotorEnabled");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_IsSpringEnabled);
    lua_setfield(L, -2, "RevoluteJoint_IsSpringEnabled");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_SetLimits);
    lua_setfield(L, -2, "RevoluteJoint_SetLimits");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_SetMaxMotorTorque);
    lua_setfield(L, -2, "RevoluteJoint_SetMaxMotorTorque");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_SetMotorSpeed);
    lua_setfield(L, -2, "RevoluteJoint_SetMotorSpeed");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_SetSpringDampingRatio);
    lua_setfield(L, -2, "RevoluteJoint_SetSpringDampingRatio");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_SetSpringHertz);
    lua_setfield(L, -2, "RevoluteJoint_SetSpringHertz");
    lua_pushcfunction(L, GenL_b2RevoluteJoint_SetTargetAngle);
    lua_setfield(L, -2, "RevoluteJoint_SetTargetAngle");
    lua_pushcfunction(L, GenL_b2SegmentDistance);
    lua_setfield(L, -2, "SegmentDistance");
    lua_pushcfunction(L, GenL_b2SetLengthUnitsPerMeter);
    lua_setfield(L, -2, "SetLengthUnitsPerMeter");
    lua_pushcfunction(L, GenL_b2ShapeCast);
    lua_setfield(L, -2, "ShapeCast");
    lua_pushcfunction(L, GenL_b2ShapeCastCapsule);
    lua_setfield(L, -2, "ShapeCastCapsule");
    lua_pushcfunction(L, GenL_b2ShapeCastCircle);
    lua_setfield(L, -2, "ShapeCastCircle");
    lua_pushcfunction(L, GenL_b2ShapeCastPolygon);
    lua_setfield(L, -2, "ShapeCastPolygon");
    lua_pushcfunction(L, GenL_b2ShapeCastSegment);
    lua_setfield(L, -2, "ShapeCastSegment");
    lua_pushcfunction(L, GenL_b2ShapeDistance);
    lua_setfield(L, -2, "ShapeDistance");
    lua_pushcfunction(L, GenL_b2Shape_AreContactEventsEnabled);
    lua_setfield(L, -2, "Shape_AreContactEventsEnabled");
    lua_pushcfunction(L, GenL_b2Shape_AreHitEventsEnabled);
    lua_setfield(L, -2, "Shape_AreHitEventsEnabled");
    lua_pushcfunction(L, GenL_b2Shape_ArePreSolveEventsEnabled);
    lua_setfield(L, -2, "Shape_ArePreSolveEventsEnabled");
    lua_pushcfunction(L, GenL_b2Shape_AreSensorEventsEnabled);
    lua_setfield(L, -2, "Shape_AreSensorEventsEnabled");
    lua_pushcfunction(L, GenL_b2Shape_EnableContactEvents);
    lua_setfield(L, -2, "Shape_EnableContactEvents");
    lua_pushcfunction(L, GenL_b2Shape_EnableHitEvents);
    lua_setfield(L, -2, "Shape_EnableHitEvents");
    lua_pushcfunction(L, GenL_b2Shape_EnablePreSolveEvents);
    lua_setfield(L, -2, "Shape_EnablePreSolveEvents");
    lua_pushcfunction(L, GenL_b2Shape_EnableSensorEvents);
    lua_setfield(L, -2, "Shape_EnableSensorEvents");
    lua_pushcfunction(L, GenL_b2Shape_GetAABB);
    lua_setfield(L, -2, "Shape_GetAABB");
    lua_pushcfunction(L, GenL_b2Shape_GetBody);
    lua_setfield(L, -2, "Shape_GetBody");
    lua_pushcfunction(L, GenL_b2Shape_GetCapsule);
    lua_setfield(L, -2, "Shape_GetCapsule");
    lua_pushcfunction(L, GenL_b2Shape_GetChainSegment);
    lua_setfield(L, -2, "Shape_GetChainSegment");
    lua_pushcfunction(L, GenL_b2Shape_GetCircle);
    lua_setfield(L, -2, "Shape_GetCircle");
    lua_pushcfunction(L, GenL_b2Shape_GetClosestPoint);
    lua_setfield(L, -2, "Shape_GetClosestPoint");
    lua_pushcfunction(L, GenL_b2Shape_GetContactCapacity);
    lua_setfield(L, -2, "Shape_GetContactCapacity");
    lua_pushcfunction(L, GenL_b2Shape_GetContactData);
    lua_setfield(L, -2, "Shape_GetContactData");
    lua_pushcfunction(L, GenL_b2Shape_GetDensity);
    lua_setfield(L, -2, "Shape_GetDensity");
    lua_pushcfunction(L, GenL_b2Shape_GetFilter);
    lua_setfield(L, -2, "Shape_GetFilter");
    lua_pushcfunction(L, GenL_b2Shape_GetFriction);
    lua_setfield(L, -2, "Shape_GetFriction");
    lua_pushcfunction(L, GenL_b2Shape_GetMassData);
    lua_setfield(L, -2, "Shape_GetMassData");
    lua_pushcfunction(L, GenL_b2Shape_GetMaterial);
    lua_setfield(L, -2, "Shape_GetMaterial");
    lua_pushcfunction(L, GenL_b2Shape_GetParentChain);
    lua_setfield(L, -2, "Shape_GetParentChain");
    lua_pushcfunction(L, GenL_b2Shape_GetPolygon);
    lua_setfield(L, -2, "Shape_GetPolygon");
    lua_pushcfunction(L, GenL_b2Shape_GetRestitution);
    lua_setfield(L, -2, "Shape_GetRestitution");
    lua_pushcfunction(L, GenL_b2Shape_GetSegment);
    lua_setfield(L, -2, "Shape_GetSegment");
    lua_pushcfunction(L, GenL_b2Shape_GetSensorCapacity);
    lua_setfield(L, -2, "Shape_GetSensorCapacity");
    lua_pushcfunction(L, GenL_b2Shape_GetSensorOverlaps);
    lua_setfield(L, -2, "Shape_GetSensorOverlaps");
    lua_pushcfunction(L, GenL_b2Shape_GetSurfaceMaterial);
    lua_setfield(L, -2, "Shape_GetSurfaceMaterial");
    lua_pushcfunction(L, GenL_b2Shape_GetType);
    lua_setfield(L, -2, "Shape_GetType");
    lua_pushcfunction(L, GenL_b2Shape_GetWorld);
    lua_setfield(L, -2, "Shape_GetWorld");
    lua_pushcfunction(L, GenL_b2Shape_IsSensor);
    lua_setfield(L, -2, "Shape_IsSensor");
    lua_pushcfunction(L, GenL_b2Shape_IsValid);
    lua_setfield(L, -2, "Shape_IsValid");
    lua_pushcfunction(L, GenL_b2Shape_RayCast);
    lua_setfield(L, -2, "Shape_RayCast");
    lua_pushcfunction(L, GenL_b2Shape_SetCapsule);
    lua_setfield(L, -2, "Shape_SetCapsule");
    lua_pushcfunction(L, GenL_b2Shape_SetCircle);
    lua_setfield(L, -2, "Shape_SetCircle");
    lua_pushcfunction(L, GenL_b2Shape_SetDensity);
    lua_setfield(L, -2, "Shape_SetDensity");
    lua_pushcfunction(L, GenL_b2Shape_SetFilter);
    lua_setfield(L, -2, "Shape_SetFilter");
    lua_pushcfunction(L, GenL_b2Shape_SetFriction);
    lua_setfield(L, -2, "Shape_SetFriction");
    lua_pushcfunction(L, GenL_b2Shape_SetMaterial);
    lua_setfield(L, -2, "Shape_SetMaterial");
    lua_pushcfunction(L, GenL_b2Shape_SetPolygon);
    lua_setfield(L, -2, "Shape_SetPolygon");
    lua_pushcfunction(L, GenL_b2Shape_SetRestitution);
    lua_setfield(L, -2, "Shape_SetRestitution");
    lua_pushcfunction(L, GenL_b2Shape_SetSegment);
    lua_setfield(L, -2, "Shape_SetSegment");
    lua_pushcfunction(L, GenL_b2Shape_SetSurfaceMaterial);
    lua_setfield(L, -2, "Shape_SetSurfaceMaterial");
    lua_pushcfunction(L, GenL_b2Shape_TestPoint);
    lua_setfield(L, -2, "Shape_TestPoint");
    lua_pushcfunction(L, GenL_b2SolvePlanes);
    lua_setfield(L, -2, "SolvePlanes");
    lua_pushcfunction(L, GenL_b2TimeOfImpact);
    lua_setfield(L, -2, "TimeOfImpact");
    lua_pushcfunction(L, GenL_b2TransformPolygon);
    lua_setfield(L, -2, "TransformPolygon");
    lua_pushcfunction(L, GenL_b2ValidateHull);
    lua_setfield(L, -2, "ValidateHull");
    lua_pushcfunction(L, GenL_b2WeldJoint_GetAngularDampingRatio);
    lua_setfield(L, -2, "WeldJoint_GetAngularDampingRatio");
    lua_pushcfunction(L, GenL_b2WeldJoint_GetAngularHertz);
    lua_setfield(L, -2, "WeldJoint_GetAngularHertz");
    lua_pushcfunction(L, GenL_b2WeldJoint_GetLinearDampingRatio);
    lua_setfield(L, -2, "WeldJoint_GetLinearDampingRatio");
    lua_pushcfunction(L, GenL_b2WeldJoint_GetLinearHertz);
    lua_setfield(L, -2, "WeldJoint_GetLinearHertz");
    lua_pushcfunction(L, GenL_b2WeldJoint_SetAngularDampingRatio);
    lua_setfield(L, -2, "WeldJoint_SetAngularDampingRatio");
    lua_pushcfunction(L, GenL_b2WeldJoint_SetAngularHertz);
    lua_setfield(L, -2, "WeldJoint_SetAngularHertz");
    lua_pushcfunction(L, GenL_b2WeldJoint_SetLinearDampingRatio);
    lua_setfield(L, -2, "WeldJoint_SetLinearDampingRatio");
    lua_pushcfunction(L, GenL_b2WeldJoint_SetLinearHertz);
    lua_setfield(L, -2, "WeldJoint_SetLinearHertz");
    lua_pushcfunction(L, GenL_b2WheelJoint_EnableLimit);
    lua_setfield(L, -2, "WheelJoint_EnableLimit");
    lua_pushcfunction(L, GenL_b2WheelJoint_EnableMotor);
    lua_setfield(L, -2, "WheelJoint_EnableMotor");
    lua_pushcfunction(L, GenL_b2WheelJoint_EnableSpring);
    lua_setfield(L, -2, "WheelJoint_EnableSpring");
    lua_pushcfunction(L, GenL_b2WheelJoint_GetLowerLimit);
    lua_setfield(L, -2, "WheelJoint_GetLowerLimit");
    lua_pushcfunction(L, GenL_b2WheelJoint_GetMaxMotorTorque);
    lua_setfield(L, -2, "WheelJoint_GetMaxMotorTorque");
    lua_pushcfunction(L, GenL_b2WheelJoint_GetMotorSpeed);
    lua_setfield(L, -2, "WheelJoint_GetMotorSpeed");
    lua_pushcfunction(L, GenL_b2WheelJoint_GetMotorTorque);
    lua_setfield(L, -2, "WheelJoint_GetMotorTorque");
    lua_pushcfunction(L, GenL_b2WheelJoint_GetSpringDampingRatio);
    lua_setfield(L, -2, "WheelJoint_GetSpringDampingRatio");
    lua_pushcfunction(L, GenL_b2WheelJoint_GetSpringHertz);
    lua_setfield(L, -2, "WheelJoint_GetSpringHertz");
    lua_pushcfunction(L, GenL_b2WheelJoint_GetUpperLimit);
    lua_setfield(L, -2, "WheelJoint_GetUpperLimit");
    lua_pushcfunction(L, GenL_b2WheelJoint_IsLimitEnabled);
    lua_setfield(L, -2, "WheelJoint_IsLimitEnabled");
    lua_pushcfunction(L, GenL_b2WheelJoint_IsMotorEnabled);
    lua_setfield(L, -2, "WheelJoint_IsMotorEnabled");
    lua_pushcfunction(L, GenL_b2WheelJoint_IsSpringEnabled);
    lua_setfield(L, -2, "WheelJoint_IsSpringEnabled");
    lua_pushcfunction(L, GenL_b2WheelJoint_SetLimits);
    lua_setfield(L, -2, "WheelJoint_SetLimits");
    lua_pushcfunction(L, GenL_b2WheelJoint_SetMaxMotorTorque);
    lua_setfield(L, -2, "WheelJoint_SetMaxMotorTorque");
    lua_pushcfunction(L, GenL_b2WheelJoint_SetMotorSpeed);
    lua_setfield(L, -2, "WheelJoint_SetMotorSpeed");
    lua_pushcfunction(L, GenL_b2WheelJoint_SetSpringDampingRatio);
    lua_setfield(L, -2, "WheelJoint_SetSpringDampingRatio");
    lua_pushcfunction(L, GenL_b2WheelJoint_SetSpringHertz);
    lua_setfield(L, -2, "WheelJoint_SetSpringHertz");
    lua_pushcfunction(L, GenL_b2World_CastMover);
    lua_setfield(L, -2, "World_CastMover");
    lua_pushcfunction(L, GenL_b2World_CastRayClosest);
    lua_setfield(L, -2, "World_CastRayClosest");
    lua_pushcfunction(L, GenL_b2World_Draw);
    lua_setfield(L, -2, "World_Draw");
    lua_pushcfunction(L, GenL_b2World_DumpMemoryStats);
    lua_setfield(L, -2, "World_DumpMemoryStats");
    lua_pushcfunction(L, GenL_b2World_EnableContinuous);
    lua_setfield(L, -2, "World_EnableContinuous");
    lua_pushcfunction(L, GenL_b2World_EnableSleeping);
    lua_setfield(L, -2, "World_EnableSleeping");
    lua_pushcfunction(L, GenL_b2World_EnableSpeculative);
    lua_setfield(L, -2, "World_EnableSpeculative");
    lua_pushcfunction(L, GenL_b2World_EnableWarmStarting);
    lua_setfield(L, -2, "World_EnableWarmStarting");
    lua_pushcfunction(L, GenL_b2World_Explode);
    lua_setfield(L, -2, "World_Explode");
    lua_pushcfunction(L, GenL_b2World_GetAwakeBodyCount);
    lua_setfield(L, -2, "World_GetAwakeBodyCount");
    lua_pushcfunction(L, GenL_b2World_GetCounters);
    lua_setfield(L, -2, "World_GetCounters");
    lua_pushcfunction(L, GenL_b2World_GetGravity);
    lua_setfield(L, -2, "World_GetGravity");
    lua_pushcfunction(L, GenL_b2World_GetHitEventThreshold);
    lua_setfield(L, -2, "World_GetHitEventThreshold");
    lua_pushcfunction(L, GenL_b2World_GetMaximumLinearSpeed);
    lua_setfield(L, -2, "World_GetMaximumLinearSpeed");
    lua_pushcfunction(L, GenL_b2World_GetProfile);
    lua_setfield(L, -2, "World_GetProfile");
    lua_pushcfunction(L, GenL_b2World_GetRestitutionThreshold);
    lua_setfield(L, -2, "World_GetRestitutionThreshold");
    lua_pushcfunction(L, GenL_b2World_IsContinuousEnabled);
    lua_setfield(L, -2, "World_IsContinuousEnabled");
    lua_pushcfunction(L, GenL_b2World_IsSleepingEnabled);
    lua_setfield(L, -2, "World_IsSleepingEnabled");
    lua_pushcfunction(L, GenL_b2World_IsValid);
    lua_setfield(L, -2, "World_IsValid");
    lua_pushcfunction(L, GenL_b2World_IsWarmStartingEnabled);
    lua_setfield(L, -2, "World_IsWarmStartingEnabled");
    lua_pushcfunction(L, GenL_b2World_RebuildStaticTree);
    lua_setfield(L, -2, "World_RebuildStaticTree");
    lua_pushcfunction(L, GenL_b2World_SetContactTuning);
    lua_setfield(L, -2, "World_SetContactTuning");
    lua_pushcfunction(L, GenL_b2World_SetGravity);
    lua_setfield(L, -2, "World_SetGravity");
    lua_pushcfunction(L, GenL_b2World_SetHitEventThreshold);
    lua_setfield(L, -2, "World_SetHitEventThreshold");
    lua_pushcfunction(L, GenL_b2World_SetMaximumLinearSpeed);
    lua_setfield(L, -2, "World_SetMaximumLinearSpeed");
    lua_pushcfunction(L, GenL_b2World_SetRestitutionThreshold);
    lua_setfield(L, -2, "World_SetRestitutionThreshold");
    lua_pushcfunction(L, GenL_b2World_Step);
    lua_setfield(L, -2, "World_Step");
    lua_pushcfunction(L, GenL_b2Yield);
    lua_setfield(L, -2, "Yield");
    lua_pushinteger(L, (lua_Integer)b2_staticBody);
    lua_setfield(L, -2, "_staticBody");
    lua_pushinteger(L, (lua_Integer)b2_kinematicBody);
    lua_setfield(L, -2, "_kinematicBody");
    lua_pushinteger(L, (lua_Integer)b2_dynamicBody);
    lua_setfield(L, -2, "_dynamicBody");
    lua_pushinteger(L, (lua_Integer)b2_bodyTypeCount);
    lua_setfield(L, -2, "_bodyTypeCount");
    lua_pushinteger(L, (lua_Integer)b2_colorAliceBlue);
    lua_setfield(L, -2, "_colorAliceBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorAntiqueWhite);
    lua_setfield(L, -2, "_colorAntiqueWhite");
    lua_pushinteger(L, (lua_Integer)b2_colorAqua);
    lua_setfield(L, -2, "_colorAqua");
    lua_pushinteger(L, (lua_Integer)b2_colorAquamarine);
    lua_setfield(L, -2, "_colorAquamarine");
    lua_pushinteger(L, (lua_Integer)b2_colorAzure);
    lua_setfield(L, -2, "_colorAzure");
    lua_pushinteger(L, (lua_Integer)b2_colorBeige);
    lua_setfield(L, -2, "_colorBeige");
    lua_pushinteger(L, (lua_Integer)b2_colorBisque);
    lua_setfield(L, -2, "_colorBisque");
    lua_pushinteger(L, (lua_Integer)b2_colorBlack);
    lua_setfield(L, -2, "_colorBlack");
    lua_pushinteger(L, (lua_Integer)b2_colorBlanchedAlmond);
    lua_setfield(L, -2, "_colorBlanchedAlmond");
    lua_pushinteger(L, (lua_Integer)b2_colorBlue);
    lua_setfield(L, -2, "_colorBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorBlueViolet);
    lua_setfield(L, -2, "_colorBlueViolet");
    lua_pushinteger(L, (lua_Integer)b2_colorBrown);
    lua_setfield(L, -2, "_colorBrown");
    lua_pushinteger(L, (lua_Integer)b2_colorBurlywood);
    lua_setfield(L, -2, "_colorBurlywood");
    lua_pushinteger(L, (lua_Integer)b2_colorCadetBlue);
    lua_setfield(L, -2, "_colorCadetBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorChartreuse);
    lua_setfield(L, -2, "_colorChartreuse");
    lua_pushinteger(L, (lua_Integer)b2_colorChocolate);
    lua_setfield(L, -2, "_colorChocolate");
    lua_pushinteger(L, (lua_Integer)b2_colorCoral);
    lua_setfield(L, -2, "_colorCoral");
    lua_pushinteger(L, (lua_Integer)b2_colorCornflowerBlue);
    lua_setfield(L, -2, "_colorCornflowerBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorCornsilk);
    lua_setfield(L, -2, "_colorCornsilk");
    lua_pushinteger(L, (lua_Integer)b2_colorCrimson);
    lua_setfield(L, -2, "_colorCrimson");
    lua_pushinteger(L, (lua_Integer)b2_colorCyan);
    lua_setfield(L, -2, "_colorCyan");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkBlue);
    lua_setfield(L, -2, "_colorDarkBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkCyan);
    lua_setfield(L, -2, "_colorDarkCyan");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkGoldenRod);
    lua_setfield(L, -2, "_colorDarkGoldenRod");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkGray);
    lua_setfield(L, -2, "_colorDarkGray");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkGreen);
    lua_setfield(L, -2, "_colorDarkGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkKhaki);
    lua_setfield(L, -2, "_colorDarkKhaki");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkMagenta);
    lua_setfield(L, -2, "_colorDarkMagenta");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkOliveGreen);
    lua_setfield(L, -2, "_colorDarkOliveGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkOrange);
    lua_setfield(L, -2, "_colorDarkOrange");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkOrchid);
    lua_setfield(L, -2, "_colorDarkOrchid");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkRed);
    lua_setfield(L, -2, "_colorDarkRed");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkSalmon);
    lua_setfield(L, -2, "_colorDarkSalmon");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkSeaGreen);
    lua_setfield(L, -2, "_colorDarkSeaGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkSlateBlue);
    lua_setfield(L, -2, "_colorDarkSlateBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkSlateGray);
    lua_setfield(L, -2, "_colorDarkSlateGray");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkTurquoise);
    lua_setfield(L, -2, "_colorDarkTurquoise");
    lua_pushinteger(L, (lua_Integer)b2_colorDarkViolet);
    lua_setfield(L, -2, "_colorDarkViolet");
    lua_pushinteger(L, (lua_Integer)b2_colorDeepPink);
    lua_setfield(L, -2, "_colorDeepPink");
    lua_pushinteger(L, (lua_Integer)b2_colorDeepSkyBlue);
    lua_setfield(L, -2, "_colorDeepSkyBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorDimGray);
    lua_setfield(L, -2, "_colorDimGray");
    lua_pushinteger(L, (lua_Integer)b2_colorDodgerBlue);
    lua_setfield(L, -2, "_colorDodgerBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorFireBrick);
    lua_setfield(L, -2, "_colorFireBrick");
    lua_pushinteger(L, (lua_Integer)b2_colorFloralWhite);
    lua_setfield(L, -2, "_colorFloralWhite");
    lua_pushinteger(L, (lua_Integer)b2_colorForestGreen);
    lua_setfield(L, -2, "_colorForestGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorFuchsia);
    lua_setfield(L, -2, "_colorFuchsia");
    lua_pushinteger(L, (lua_Integer)b2_colorGainsboro);
    lua_setfield(L, -2, "_colorGainsboro");
    lua_pushinteger(L, (lua_Integer)b2_colorGhostWhite);
    lua_setfield(L, -2, "_colorGhostWhite");
    lua_pushinteger(L, (lua_Integer)b2_colorGold);
    lua_setfield(L, -2, "_colorGold");
    lua_pushinteger(L, (lua_Integer)b2_colorGoldenRod);
    lua_setfield(L, -2, "_colorGoldenRod");
    lua_pushinteger(L, (lua_Integer)b2_colorGray);
    lua_setfield(L, -2, "_colorGray");
    lua_pushinteger(L, (lua_Integer)b2_colorGreen);
    lua_setfield(L, -2, "_colorGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorGreenYellow);
    lua_setfield(L, -2, "_colorGreenYellow");
    lua_pushinteger(L, (lua_Integer)b2_colorHoneyDew);
    lua_setfield(L, -2, "_colorHoneyDew");
    lua_pushinteger(L, (lua_Integer)b2_colorHotPink);
    lua_setfield(L, -2, "_colorHotPink");
    lua_pushinteger(L, (lua_Integer)b2_colorIndianRed);
    lua_setfield(L, -2, "_colorIndianRed");
    lua_pushinteger(L, (lua_Integer)b2_colorIndigo);
    lua_setfield(L, -2, "_colorIndigo");
    lua_pushinteger(L, (lua_Integer)b2_colorIvory);
    lua_setfield(L, -2, "_colorIvory");
    lua_pushinteger(L, (lua_Integer)b2_colorKhaki);
    lua_setfield(L, -2, "_colorKhaki");
    lua_pushinteger(L, (lua_Integer)b2_colorLavender);
    lua_setfield(L, -2, "_colorLavender");
    lua_pushinteger(L, (lua_Integer)b2_colorLavenderBlush);
    lua_setfield(L, -2, "_colorLavenderBlush");
    lua_pushinteger(L, (lua_Integer)b2_colorLawnGreen);
    lua_setfield(L, -2, "_colorLawnGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorLemonChiffon);
    lua_setfield(L, -2, "_colorLemonChiffon");
    lua_pushinteger(L, (lua_Integer)b2_colorLightBlue);
    lua_setfield(L, -2, "_colorLightBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorLightCoral);
    lua_setfield(L, -2, "_colorLightCoral");
    lua_pushinteger(L, (lua_Integer)b2_colorLightCyan);
    lua_setfield(L, -2, "_colorLightCyan");
    lua_pushinteger(L, (lua_Integer)b2_colorLightGoldenRodYellow);
    lua_setfield(L, -2, "_colorLightGoldenRodYellow");
    lua_pushinteger(L, (lua_Integer)b2_colorLightGray);
    lua_setfield(L, -2, "_colorLightGray");
    lua_pushinteger(L, (lua_Integer)b2_colorLightGreen);
    lua_setfield(L, -2, "_colorLightGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorLightPink);
    lua_setfield(L, -2, "_colorLightPink");
    lua_pushinteger(L, (lua_Integer)b2_colorLightSalmon);
    lua_setfield(L, -2, "_colorLightSalmon");
    lua_pushinteger(L, (lua_Integer)b2_colorLightSeaGreen);
    lua_setfield(L, -2, "_colorLightSeaGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorLightSkyBlue);
    lua_setfield(L, -2, "_colorLightSkyBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorLightSlateGray);
    lua_setfield(L, -2, "_colorLightSlateGray");
    lua_pushinteger(L, (lua_Integer)b2_colorLightSteelBlue);
    lua_setfield(L, -2, "_colorLightSteelBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorLightYellow);
    lua_setfield(L, -2, "_colorLightYellow");
    lua_pushinteger(L, (lua_Integer)b2_colorLime);
    lua_setfield(L, -2, "_colorLime");
    lua_pushinteger(L, (lua_Integer)b2_colorLimeGreen);
    lua_setfield(L, -2, "_colorLimeGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorLinen);
    lua_setfield(L, -2, "_colorLinen");
    lua_pushinteger(L, (lua_Integer)b2_colorMagenta);
    lua_setfield(L, -2, "_colorMagenta");
    lua_pushinteger(L, (lua_Integer)b2_colorMaroon);
    lua_setfield(L, -2, "_colorMaroon");
    lua_pushinteger(L, (lua_Integer)b2_colorMediumAquaMarine);
    lua_setfield(L, -2, "_colorMediumAquaMarine");
    lua_pushinteger(L, (lua_Integer)b2_colorMediumBlue);
    lua_setfield(L, -2, "_colorMediumBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorMediumOrchid);
    lua_setfield(L, -2, "_colorMediumOrchid");
    lua_pushinteger(L, (lua_Integer)b2_colorMediumPurple);
    lua_setfield(L, -2, "_colorMediumPurple");
    lua_pushinteger(L, (lua_Integer)b2_colorMediumSeaGreen);
    lua_setfield(L, -2, "_colorMediumSeaGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorMediumSlateBlue);
    lua_setfield(L, -2, "_colorMediumSlateBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorMediumSpringGreen);
    lua_setfield(L, -2, "_colorMediumSpringGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorMediumTurquoise);
    lua_setfield(L, -2, "_colorMediumTurquoise");
    lua_pushinteger(L, (lua_Integer)b2_colorMediumVioletRed);
    lua_setfield(L, -2, "_colorMediumVioletRed");
    lua_pushinteger(L, (lua_Integer)b2_colorMidnightBlue);
    lua_setfield(L, -2, "_colorMidnightBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorMintCream);
    lua_setfield(L, -2, "_colorMintCream");
    lua_pushinteger(L, (lua_Integer)b2_colorMistyRose);
    lua_setfield(L, -2, "_colorMistyRose");
    lua_pushinteger(L, (lua_Integer)b2_colorMoccasin);
    lua_setfield(L, -2, "_colorMoccasin");
    lua_pushinteger(L, (lua_Integer)b2_colorNavajoWhite);
    lua_setfield(L, -2, "_colorNavajoWhite");
    lua_pushinteger(L, (lua_Integer)b2_colorNavy);
    lua_setfield(L, -2, "_colorNavy");
    lua_pushinteger(L, (lua_Integer)b2_colorOldLace);
    lua_setfield(L, -2, "_colorOldLace");
    lua_pushinteger(L, (lua_Integer)b2_colorOlive);
    lua_setfield(L, -2, "_colorOlive");
    lua_pushinteger(L, (lua_Integer)b2_colorOliveDrab);
    lua_setfield(L, -2, "_colorOliveDrab");
    lua_pushinteger(L, (lua_Integer)b2_colorOrange);
    lua_setfield(L, -2, "_colorOrange");
    lua_pushinteger(L, (lua_Integer)b2_colorOrangeRed);
    lua_setfield(L, -2, "_colorOrangeRed");
    lua_pushinteger(L, (lua_Integer)b2_colorOrchid);
    lua_setfield(L, -2, "_colorOrchid");
    lua_pushinteger(L, (lua_Integer)b2_colorPaleGoldenRod);
    lua_setfield(L, -2, "_colorPaleGoldenRod");
    lua_pushinteger(L, (lua_Integer)b2_colorPaleGreen);
    lua_setfield(L, -2, "_colorPaleGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorPaleTurquoise);
    lua_setfield(L, -2, "_colorPaleTurquoise");
    lua_pushinteger(L, (lua_Integer)b2_colorPaleVioletRed);
    lua_setfield(L, -2, "_colorPaleVioletRed");
    lua_pushinteger(L, (lua_Integer)b2_colorPapayaWhip);
    lua_setfield(L, -2, "_colorPapayaWhip");
    lua_pushinteger(L, (lua_Integer)b2_colorPeachPuff);
    lua_setfield(L, -2, "_colorPeachPuff");
    lua_pushinteger(L, (lua_Integer)b2_colorPeru);
    lua_setfield(L, -2, "_colorPeru");
    lua_pushinteger(L, (lua_Integer)b2_colorPink);
    lua_setfield(L, -2, "_colorPink");
    lua_pushinteger(L, (lua_Integer)b2_colorPlum);
    lua_setfield(L, -2, "_colorPlum");
    lua_pushinteger(L, (lua_Integer)b2_colorPowderBlue);
    lua_setfield(L, -2, "_colorPowderBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorPurple);
    lua_setfield(L, -2, "_colorPurple");
    lua_pushinteger(L, (lua_Integer)b2_colorRebeccaPurple);
    lua_setfield(L, -2, "_colorRebeccaPurple");
    lua_pushinteger(L, (lua_Integer)b2_colorRed);
    lua_setfield(L, -2, "_colorRed");
    lua_pushinteger(L, (lua_Integer)b2_colorRosyBrown);
    lua_setfield(L, -2, "_colorRosyBrown");
    lua_pushinteger(L, (lua_Integer)b2_colorRoyalBlue);
    lua_setfield(L, -2, "_colorRoyalBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorSaddleBrown);
    lua_setfield(L, -2, "_colorSaddleBrown");
    lua_pushinteger(L, (lua_Integer)b2_colorSalmon);
    lua_setfield(L, -2, "_colorSalmon");
    lua_pushinteger(L, (lua_Integer)b2_colorSandyBrown);
    lua_setfield(L, -2, "_colorSandyBrown");
    lua_pushinteger(L, (lua_Integer)b2_colorSeaGreen);
    lua_setfield(L, -2, "_colorSeaGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorSeaShell);
    lua_setfield(L, -2, "_colorSeaShell");
    lua_pushinteger(L, (lua_Integer)b2_colorSienna);
    lua_setfield(L, -2, "_colorSienna");
    lua_pushinteger(L, (lua_Integer)b2_colorSilver);
    lua_setfield(L, -2, "_colorSilver");
    lua_pushinteger(L, (lua_Integer)b2_colorSkyBlue);
    lua_setfield(L, -2, "_colorSkyBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorSlateBlue);
    lua_setfield(L, -2, "_colorSlateBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorSlateGray);
    lua_setfield(L, -2, "_colorSlateGray");
    lua_pushinteger(L, (lua_Integer)b2_colorSnow);
    lua_setfield(L, -2, "_colorSnow");
    lua_pushinteger(L, (lua_Integer)b2_colorSpringGreen);
    lua_setfield(L, -2, "_colorSpringGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorSteelBlue);
    lua_setfield(L, -2, "_colorSteelBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorTan);
    lua_setfield(L, -2, "_colorTan");
    lua_pushinteger(L, (lua_Integer)b2_colorTeal);
    lua_setfield(L, -2, "_colorTeal");
    lua_pushinteger(L, (lua_Integer)b2_colorThistle);
    lua_setfield(L, -2, "_colorThistle");
    lua_pushinteger(L, (lua_Integer)b2_colorTomato);
    lua_setfield(L, -2, "_colorTomato");
    lua_pushinteger(L, (lua_Integer)b2_colorTurquoise);
    lua_setfield(L, -2, "_colorTurquoise");
    lua_pushinteger(L, (lua_Integer)b2_colorViolet);
    lua_setfield(L, -2, "_colorViolet");
    lua_pushinteger(L, (lua_Integer)b2_colorWheat);
    lua_setfield(L, -2, "_colorWheat");
    lua_pushinteger(L, (lua_Integer)b2_colorWhite);
    lua_setfield(L, -2, "_colorWhite");
    lua_pushinteger(L, (lua_Integer)b2_colorWhiteSmoke);
    lua_setfield(L, -2, "_colorWhiteSmoke");
    lua_pushinteger(L, (lua_Integer)b2_colorYellow);
    lua_setfield(L, -2, "_colorYellow");
    lua_pushinteger(L, (lua_Integer)b2_colorYellowGreen);
    lua_setfield(L, -2, "_colorYellowGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorBox2DRed);
    lua_setfield(L, -2, "_colorBox2DRed");
    lua_pushinteger(L, (lua_Integer)b2_colorBox2DBlue);
    lua_setfield(L, -2, "_colorBox2DBlue");
    lua_pushinteger(L, (lua_Integer)b2_colorBox2DGreen);
    lua_setfield(L, -2, "_colorBox2DGreen");
    lua_pushinteger(L, (lua_Integer)b2_colorBox2DYellow);
    lua_setfield(L, -2, "_colorBox2DYellow");
    lua_pushinteger(L, (lua_Integer)b2_distanceJoint);
    lua_setfield(L, -2, "_distanceJoint");
    lua_pushinteger(L, (lua_Integer)b2_filterJoint);
    lua_setfield(L, -2, "_filterJoint");
    lua_pushinteger(L, (lua_Integer)b2_motorJoint);
    lua_setfield(L, -2, "_motorJoint");
    lua_pushinteger(L, (lua_Integer)b2_mouseJoint);
    lua_setfield(L, -2, "_mouseJoint");
    lua_pushinteger(L, (lua_Integer)b2_prismaticJoint);
    lua_setfield(L, -2, "_prismaticJoint");
    lua_pushinteger(L, (lua_Integer)b2_revoluteJoint);
    lua_setfield(L, -2, "_revoluteJoint");
    lua_pushinteger(L, (lua_Integer)b2_weldJoint);
    lua_setfield(L, -2, "_weldJoint");
    lua_pushinteger(L, (lua_Integer)b2_wheelJoint);
    lua_setfield(L, -2, "_wheelJoint");
    lua_pushinteger(L, (lua_Integer)b2_circleShape);
    lua_setfield(L, -2, "_circleShape");
    lua_pushinteger(L, (lua_Integer)b2_capsuleShape);
    lua_setfield(L, -2, "_capsuleShape");
    lua_pushinteger(L, (lua_Integer)b2_segmentShape);
    lua_setfield(L, -2, "_segmentShape");
    lua_pushinteger(L, (lua_Integer)b2_polygonShape);
    lua_setfield(L, -2, "_polygonShape");
    lua_pushinteger(L, (lua_Integer)b2_chainSegmentShape);
    lua_setfield(L, -2, "_chainSegmentShape");
    lua_pushinteger(L, (lua_Integer)b2_shapeTypeCount);
    lua_setfield(L, -2, "_shapeTypeCount");
    lua_pushinteger(L, (lua_Integer)b2_toiStateUnknown);
    lua_setfield(L, -2, "_toiStateUnknown");
    lua_pushinteger(L, (lua_Integer)b2_toiStateFailed);
    lua_setfield(L, -2, "_toiStateFailed");
    lua_pushinteger(L, (lua_Integer)b2_toiStateOverlapped);
    lua_setfield(L, -2, "_toiStateOverlapped");
    lua_pushinteger(L, (lua_Integer)b2_toiStateHit);
    lua_setfield(L, -2, "_toiStateHit");
    lua_pushinteger(L, (lua_Integer)b2_toiStateSeparated);
    lua_setfield(L, -2, "_toiStateSeparated");
    lua_setglobal(L, "B2");
    return 0;
}
