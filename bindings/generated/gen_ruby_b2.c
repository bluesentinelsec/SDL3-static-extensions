/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for Box2D. */
#include "../src/gen_support_ruby.h"

#include <box2d/box2d.h>
#include <string.h>

static void GenRead_b2Vec2(mrb_state *mrb, mrb_value h, b2Vec2 *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "x");
    out->y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "y");
}

static mrb_value GenPush_b2Vec2(mrb_state *mrb, const b2Vec2 *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "x", mrb_float_value(mrb, (mrb_float)in->x));
    SDLStaticGen_RubyHashSet(mrb, h, "y", mrb_float_value(mrb, (mrb_float)in->y));
    return h;
}

static void GenRead_b2AABB(mrb_state *mrb, mrb_value h, b2AABB *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "lowerBound"), &out->lowerBound);
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "upperBound"), &out->upperBound);
}

static mrb_value GenPush_b2AABB(mrb_state *mrb, const b2AABB *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "lowerBound", GenPush_b2Vec2(mrb, &in->lowerBound));
    SDLStaticGen_RubyHashSet(mrb, h, "upperBound", GenPush_b2Vec2(mrb, &in->upperBound));
    return h;
}

static void GenRead_b2Rot(mrb_state *mrb, mrb_value h, b2Rot *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->c = (float)SDLStaticGen_RubyFieldNum(mrb, h, "c");
    out->s = (float)SDLStaticGen_RubyFieldNum(mrb, h, "s");
}

static mrb_value GenPush_b2Rot(mrb_state *mrb, const b2Rot *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "c", mrb_float_value(mrb, (mrb_float)in->c));
    SDLStaticGen_RubyHashSet(mrb, h, "s", mrb_float_value(mrb, (mrb_float)in->s));
    return h;
}

static void GenRead_b2BodyDef(mrb_state *mrb, mrb_value h, b2BodyDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->type = (b2BodyType)SDLStaticGen_RubyFieldInt(mrb, h, "type");
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "position"), &out->position);
    GenRead_b2Rot(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "rotation"), &out->rotation);
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "linearVelocity"), &out->linearVelocity);
    out->angularVelocity = (float)SDLStaticGen_RubyFieldNum(mrb, h, "angularVelocity");
    out->linearDamping = (float)SDLStaticGen_RubyFieldNum(mrb, h, "linearDamping");
    out->angularDamping = (float)SDLStaticGen_RubyFieldNum(mrb, h, "angularDamping");
    out->gravityScale = (float)SDLStaticGen_RubyFieldNum(mrb, h, "gravityScale");
    out->sleepThreshold = (float)SDLStaticGen_RubyFieldNum(mrb, h, "sleepThreshold");
    out->enableSleep = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "enableSleep");
    out->isAwake = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "isAwake");
    out->fixedRotation = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "fixedRotation");
    out->isBullet = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "isBullet");
    out->isEnabled = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "isEnabled");
    out->allowFastRotation = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "allowFastRotation");
    out->internalValue = (int)SDLStaticGen_RubyFieldInt(mrb, h, "internalValue");
}

static mrb_value GenPush_b2BodyDef(mrb_state *mrb, const b2BodyDef *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "type", mrb_int_value(mrb, (mrb_int)in->type));
    SDLStaticGen_RubyHashSet(mrb, h, "position", GenPush_b2Vec2(mrb, &in->position));
    SDLStaticGen_RubyHashSet(mrb, h, "rotation", GenPush_b2Rot(mrb, &in->rotation));
    SDLStaticGen_RubyHashSet(mrb, h, "linearVelocity", GenPush_b2Vec2(mrb, &in->linearVelocity));
    SDLStaticGen_RubyHashSet(mrb, h, "angularVelocity", mrb_float_value(mrb, (mrb_float)in->angularVelocity));
    SDLStaticGen_RubyHashSet(mrb, h, "linearDamping", mrb_float_value(mrb, (mrb_float)in->linearDamping));
    SDLStaticGen_RubyHashSet(mrb, h, "angularDamping", mrb_float_value(mrb, (mrb_float)in->angularDamping));
    SDLStaticGen_RubyHashSet(mrb, h, "gravityScale", mrb_float_value(mrb, (mrb_float)in->gravityScale));
    SDLStaticGen_RubyHashSet(mrb, h, "sleepThreshold", mrb_float_value(mrb, (mrb_float)in->sleepThreshold));
    SDLStaticGen_RubyHashSet(mrb, h, "enableSleep", mrb_bool_value((mrb_bool)(in->enableSleep != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "isAwake", mrb_bool_value((mrb_bool)(in->isAwake != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "fixedRotation", mrb_bool_value((mrb_bool)(in->fixedRotation != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "isBullet", mrb_bool_value((mrb_bool)(in->isBullet != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "isEnabled", mrb_bool_value((mrb_bool)(in->isEnabled != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "allowFastRotation", mrb_bool_value((mrb_bool)(in->allowFastRotation != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "internalValue", mrb_int_value(mrb, (mrb_int)in->internalValue));
    return h;
}

static void GenRead_b2BodyId(mrb_state *mrb, mrb_value h, b2BodyId *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->index1 = (int32_t)SDLStaticGen_RubyFieldInt(mrb, h, "index1");
    out->world0 = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "world0");
    out->generation = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "generation");
}

static mrb_value GenPush_b2BodyId(mrb_state *mrb, const b2BodyId *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "index1", mrb_int_value(mrb, (mrb_int)in->index1));
    SDLStaticGen_RubyHashSet(mrb, h, "world0", mrb_int_value(mrb, (mrb_int)in->world0));
    SDLStaticGen_RubyHashSet(mrb, h, "generation", mrb_int_value(mrb, (mrb_int)in->generation));
    return h;
}

static void GenRead_b2Capsule(mrb_state *mrb, mrb_value h, b2Capsule *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "center1"), &out->center1);
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "center2"), &out->center2);
    out->radius = (float)SDLStaticGen_RubyFieldNum(mrb, h, "radius");
}

static mrb_value GenPush_b2Capsule(mrb_state *mrb, const b2Capsule *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "center1", GenPush_b2Vec2(mrb, &in->center1));
    SDLStaticGen_RubyHashSet(mrb, h, "center2", GenPush_b2Vec2(mrb, &in->center2));
    SDLStaticGen_RubyHashSet(mrb, h, "radius", mrb_float_value(mrb, (mrb_float)in->radius));
    return h;
}

static mrb_value GenPush_b2CastOutput(mrb_state *mrb, const b2CastOutput *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "normal", GenPush_b2Vec2(mrb, &in->normal));
    SDLStaticGen_RubyHashSet(mrb, h, "point", GenPush_b2Vec2(mrb, &in->point));
    SDLStaticGen_RubyHashSet(mrb, h, "fraction", mrb_float_value(mrb, (mrb_float)in->fraction));
    SDLStaticGen_RubyHashSet(mrb, h, "iterations", mrb_int_value(mrb, (mrb_int)in->iterations));
    SDLStaticGen_RubyHashSet(mrb, h, "hit", mrb_bool_value((mrb_bool)(in->hit != 0)));
    return h;
}

static void GenRead_b2SurfaceMaterial(mrb_state *mrb, mrb_value h, b2SurfaceMaterial *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->friction = (float)SDLStaticGen_RubyFieldNum(mrb, h, "friction");
    out->restitution = (float)SDLStaticGen_RubyFieldNum(mrb, h, "restitution");
    out->rollingResistance = (float)SDLStaticGen_RubyFieldNum(mrb, h, "rollingResistance");
    out->tangentSpeed = (float)SDLStaticGen_RubyFieldNum(mrb, h, "tangentSpeed");
    out->userMaterialId = (int)SDLStaticGen_RubyFieldInt(mrb, h, "userMaterialId");
    out->customColor = (uint32_t)SDLStaticGen_RubyFieldInt(mrb, h, "customColor");
}

static mrb_value GenPush_b2SurfaceMaterial(mrb_state *mrb, const b2SurfaceMaterial *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "friction", mrb_float_value(mrb, (mrb_float)in->friction));
    SDLStaticGen_RubyHashSet(mrb, h, "restitution", mrb_float_value(mrb, (mrb_float)in->restitution));
    SDLStaticGen_RubyHashSet(mrb, h, "rollingResistance", mrb_float_value(mrb, (mrb_float)in->rollingResistance));
    SDLStaticGen_RubyHashSet(mrb, h, "tangentSpeed", mrb_float_value(mrb, (mrb_float)in->tangentSpeed));
    SDLStaticGen_RubyHashSet(mrb, h, "userMaterialId", mrb_int_value(mrb, (mrb_int)in->userMaterialId));
    SDLStaticGen_RubyHashSet(mrb, h, "customColor", mrb_int_value(mrb, (mrb_int)in->customColor));
    return h;
}

static void GenRead_b2Filter(mrb_state *mrb, mrb_value h, b2Filter *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->categoryBits = (uint64_t)SDLStaticGen_RubyFieldInt(mrb, h, "categoryBits");
    out->maskBits = (uint64_t)SDLStaticGen_RubyFieldInt(mrb, h, "maskBits");
    out->groupIndex = (int)SDLStaticGen_RubyFieldInt(mrb, h, "groupIndex");
}

static mrb_value GenPush_b2Filter(mrb_state *mrb, const b2Filter *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "categoryBits", mrb_int_value(mrb, (mrb_int)in->categoryBits));
    SDLStaticGen_RubyHashSet(mrb, h, "maskBits", mrb_int_value(mrb, (mrb_int)in->maskBits));
    SDLStaticGen_RubyHashSet(mrb, h, "groupIndex", mrb_int_value(mrb, (mrb_int)in->groupIndex));
    return h;
}

static void GenRead_b2ChainDef(mrb_state *mrb, mrb_value h, b2ChainDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->count = (int)SDLStaticGen_RubyFieldInt(mrb, h, "count");
    out->materialCount = (int)SDLStaticGen_RubyFieldInt(mrb, h, "materialCount");
    GenRead_b2Filter(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "filter"), &out->filter);
    out->isLoop = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "isLoop");
    out->enableSensorEvents = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "enableSensorEvents");
    out->internalValue = (int)SDLStaticGen_RubyFieldInt(mrb, h, "internalValue");
}

static mrb_value GenPush_b2ChainDef(mrb_state *mrb, const b2ChainDef *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "count", mrb_int_value(mrb, (mrb_int)in->count));
    SDLStaticGen_RubyHashSet(mrb, h, "materialCount", mrb_int_value(mrb, (mrb_int)in->materialCount));
    SDLStaticGen_RubyHashSet(mrb, h, "filter", GenPush_b2Filter(mrb, &in->filter));
    SDLStaticGen_RubyHashSet(mrb, h, "isLoop", mrb_bool_value((mrb_bool)(in->isLoop != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "enableSensorEvents", mrb_bool_value((mrb_bool)(in->enableSensorEvents != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "internalValue", mrb_int_value(mrb, (mrb_int)in->internalValue));
    return h;
}

static void GenRead_b2ChainId(mrb_state *mrb, mrb_value h, b2ChainId *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->index1 = (int32_t)SDLStaticGen_RubyFieldInt(mrb, h, "index1");
    out->world0 = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "world0");
    out->generation = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "generation");
}

static mrb_value GenPush_b2ChainId(mrb_state *mrb, const b2ChainId *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "index1", mrb_int_value(mrb, (mrb_int)in->index1));
    SDLStaticGen_RubyHashSet(mrb, h, "world0", mrb_int_value(mrb, (mrb_int)in->world0));
    SDLStaticGen_RubyHashSet(mrb, h, "generation", mrb_int_value(mrb, (mrb_int)in->generation));
    return h;
}

static void GenRead_b2Segment(mrb_state *mrb, mrb_value h, b2Segment *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "point1"), &out->point1);
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "point2"), &out->point2);
}

static mrb_value GenPush_b2Segment(mrb_state *mrb, const b2Segment *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "point1", GenPush_b2Vec2(mrb, &in->point1));
    SDLStaticGen_RubyHashSet(mrb, h, "point2", GenPush_b2Vec2(mrb, &in->point2));
    return h;
}

static void GenRead_b2ChainSegment(mrb_state *mrb, mrb_value h, b2ChainSegment *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "ghost1"), &out->ghost1);
    GenRead_b2Segment(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "segment"), &out->segment);
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "ghost2"), &out->ghost2);
    out->chainId = (int)SDLStaticGen_RubyFieldInt(mrb, h, "chainId");
}

static mrb_value GenPush_b2ChainSegment(mrb_state *mrb, const b2ChainSegment *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "ghost1", GenPush_b2Vec2(mrb, &in->ghost1));
    SDLStaticGen_RubyHashSet(mrb, h, "segment", GenPush_b2Segment(mrb, &in->segment));
    SDLStaticGen_RubyHashSet(mrb, h, "ghost2", GenPush_b2Vec2(mrb, &in->ghost2));
    SDLStaticGen_RubyHashSet(mrb, h, "chainId", mrb_int_value(mrb, (mrb_int)in->chainId));
    return h;
}

static void GenRead_b2Circle(mrb_state *mrb, mrb_value h, b2Circle *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "center"), &out->center);
    out->radius = (float)SDLStaticGen_RubyFieldNum(mrb, h, "radius");
}

static mrb_value GenPush_b2Circle(mrb_state *mrb, const b2Circle *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "center", GenPush_b2Vec2(mrb, &in->center));
    SDLStaticGen_RubyHashSet(mrb, h, "radius", mrb_float_value(mrb, (mrb_float)in->radius));
    return h;
}

static void GenRead_b2Plane(mrb_state *mrb, mrb_value h, b2Plane *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "normal"), &out->normal);
    out->offset = (float)SDLStaticGen_RubyFieldNum(mrb, h, "offset");
}

static mrb_value GenPush_b2Plane(mrb_state *mrb, const b2Plane *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "normal", GenPush_b2Vec2(mrb, &in->normal));
    SDLStaticGen_RubyHashSet(mrb, h, "offset", mrb_float_value(mrb, (mrb_float)in->offset));
    return h;
}

static void GenRead_b2CollisionPlane(mrb_state *mrb, mrb_value h, b2CollisionPlane *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2Plane(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "plane"), &out->plane);
    out->pushLimit = (float)SDLStaticGen_RubyFieldNum(mrb, h, "pushLimit");
    out->push = (float)SDLStaticGen_RubyFieldNum(mrb, h, "push");
    out->clipVelocity = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "clipVelocity");
}

static mrb_value GenPush_b2CollisionPlane(mrb_state *mrb, const b2CollisionPlane *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "plane", GenPush_b2Plane(mrb, &in->plane));
    SDLStaticGen_RubyHashSet(mrb, h, "pushLimit", mrb_float_value(mrb, (mrb_float)in->pushLimit));
    SDLStaticGen_RubyHashSet(mrb, h, "push", mrb_float_value(mrb, (mrb_float)in->push));
    SDLStaticGen_RubyHashSet(mrb, h, "clipVelocity", mrb_bool_value((mrb_bool)(in->clipVelocity != 0)));
    return h;
}

static void GenRead_b2ShapeId(mrb_state *mrb, mrb_value h, b2ShapeId *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->index1 = (int32_t)SDLStaticGen_RubyFieldInt(mrb, h, "index1");
    out->world0 = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "world0");
    out->generation = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "generation");
}

static mrb_value GenPush_b2ShapeId(mrb_state *mrb, const b2ShapeId *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "index1", mrb_int_value(mrb, (mrb_int)in->index1));
    SDLStaticGen_RubyHashSet(mrb, h, "world0", mrb_int_value(mrb, (mrb_int)in->world0));
    SDLStaticGen_RubyHashSet(mrb, h, "generation", mrb_int_value(mrb, (mrb_int)in->generation));
    return h;
}

static mrb_value GenPush_b2ManifoldPoint(mrb_state *mrb, const b2ManifoldPoint *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "point", GenPush_b2Vec2(mrb, &in->point));
    SDLStaticGen_RubyHashSet(mrb, h, "anchorA", GenPush_b2Vec2(mrb, &in->anchorA));
    SDLStaticGen_RubyHashSet(mrb, h, "anchorB", GenPush_b2Vec2(mrb, &in->anchorB));
    SDLStaticGen_RubyHashSet(mrb, h, "separation", mrb_float_value(mrb, (mrb_float)in->separation));
    SDLStaticGen_RubyHashSet(mrb, h, "normalImpulse", mrb_float_value(mrb, (mrb_float)in->normalImpulse));
    SDLStaticGen_RubyHashSet(mrb, h, "tangentImpulse", mrb_float_value(mrb, (mrb_float)in->tangentImpulse));
    SDLStaticGen_RubyHashSet(mrb, h, "totalNormalImpulse", mrb_float_value(mrb, (mrb_float)in->totalNormalImpulse));
    SDLStaticGen_RubyHashSet(mrb, h, "normalVelocity", mrb_float_value(mrb, (mrb_float)in->normalVelocity));
    SDLStaticGen_RubyHashSet(mrb, h, "id", mrb_int_value(mrb, (mrb_int)in->id));
    SDLStaticGen_RubyHashSet(mrb, h, "persisted", mrb_bool_value((mrb_bool)(in->persisted != 0)));
    return h;
}

static mrb_value GenPush_b2Manifold(mrb_state *mrb, const b2Manifold *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "normal", GenPush_b2Vec2(mrb, &in->normal));
    SDLStaticGen_RubyHashSet(mrb, h, "rollingImpulse", mrb_float_value(mrb, (mrb_float)in->rollingImpulse));
    {
        mrb_value arr = mrb_ary_new_capa(mrb, (mrb_int)(2));
        for (mrb_int gi = 0; gi < (mrb_int)(2); ++gi) {
            mrb_ary_push(mrb, arr, GenPush_b2ManifoldPoint(mrb, &in->points[gi]));
        }
        SDLStaticGen_RubyHashSet(mrb, h, "points", arr);
    }
    SDLStaticGen_RubyHashSet(mrb, h, "pointCount", mrb_int_value(mrb, (mrb_int)in->pointCount));
    return h;
}

static mrb_value GenPush_b2ContactData(mrb_state *mrb, const b2ContactData *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "shapeIdA", GenPush_b2ShapeId(mrb, &in->shapeIdA));
    SDLStaticGen_RubyHashSet(mrb, h, "shapeIdB", GenPush_b2ShapeId(mrb, &in->shapeIdB));
    SDLStaticGen_RubyHashSet(mrb, h, "manifold", GenPush_b2Manifold(mrb, &in->manifold));
    return h;
}

static mrb_value GenPush_b2CosSin(mrb_state *mrb, const b2CosSin *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "cosine", mrb_float_value(mrb, (mrb_float)in->cosine));
    SDLStaticGen_RubyHashSet(mrb, h, "sine", mrb_float_value(mrb, (mrb_float)in->sine));
    return h;
}

static mrb_value GenPush_b2Counters(mrb_state *mrb, const b2Counters *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "bodyCount", mrb_int_value(mrb, (mrb_int)in->bodyCount));
    SDLStaticGen_RubyHashSet(mrb, h, "shapeCount", mrb_int_value(mrb, (mrb_int)in->shapeCount));
    SDLStaticGen_RubyHashSet(mrb, h, "contactCount", mrb_int_value(mrb, (mrb_int)in->contactCount));
    SDLStaticGen_RubyHashSet(mrb, h, "jointCount", mrb_int_value(mrb, (mrb_int)in->jointCount));
    SDLStaticGen_RubyHashSet(mrb, h, "islandCount", mrb_int_value(mrb, (mrb_int)in->islandCount));
    SDLStaticGen_RubyHashSet(mrb, h, "stackUsed", mrb_int_value(mrb, (mrb_int)in->stackUsed));
    SDLStaticGen_RubyHashSet(mrb, h, "staticTreeHeight", mrb_int_value(mrb, (mrb_int)in->staticTreeHeight));
    SDLStaticGen_RubyHashSet(mrb, h, "treeHeight", mrb_int_value(mrb, (mrb_int)in->treeHeight));
    SDLStaticGen_RubyHashSet(mrb, h, "byteCount", mrb_int_value(mrb, (mrb_int)in->byteCount));
    SDLStaticGen_RubyHashSet(mrb, h, "taskCount", mrb_int_value(mrb, (mrb_int)in->taskCount));
    {
        mrb_value arr = mrb_ary_new_capa(mrb, (mrb_int)(12));
        for (mrb_int gi = 0; gi < (mrb_int)(12); ++gi) {
            mrb_ary_push(mrb, arr, mrb_int_value(mrb, (mrb_int)in->colorCounts[gi]));
        }
        SDLStaticGen_RubyHashSet(mrb, h, "colorCounts", arr);
    }
    return h;
}

static void GenRead_b2ShapeProxy(mrb_state *mrb, mrb_value h, b2ShapeProxy *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    {
        mrb_value arr = SDLStaticGen_RubyFieldGet(mrb, h, "points");
        if (mrb_array_p(arr)) {
            for (mrb_int gi = 0; gi < (mrb_int)(B2_MAX_POLYGON_VERTICES) && gi < RARRAY_LEN(arr); ++gi) {
                mrb_value el = mrb_ary_ref(mrb, arr, gi);
                GenRead_b2Vec2(mrb, el, &out->points[gi]);
            }
        }
    }
    out->count = (int)SDLStaticGen_RubyFieldInt(mrb, h, "count");
    out->radius = (float)SDLStaticGen_RubyFieldNum(mrb, h, "radius");
}

static mrb_value GenPush_b2ShapeProxy(mrb_state *mrb, const b2ShapeProxy *in)
{
    mrb_value h = mrb_hash_new(mrb);
    {
        mrb_value arr = mrb_ary_new_capa(mrb, (mrb_int)(B2_MAX_POLYGON_VERTICES));
        for (mrb_int gi = 0; gi < (mrb_int)(B2_MAX_POLYGON_VERTICES); ++gi) {
            mrb_ary_push(mrb, arr, GenPush_b2Vec2(mrb, &in->points[gi]));
        }
        SDLStaticGen_RubyHashSet(mrb, h, "points", arr);
    }
    SDLStaticGen_RubyHashSet(mrb, h, "count", mrb_int_value(mrb, (mrb_int)in->count));
    SDLStaticGen_RubyHashSet(mrb, h, "radius", mrb_float_value(mrb, (mrb_float)in->radius));
    return h;
}

static void GenRead_b2Transform(mrb_state *mrb, mrb_value h, b2Transform *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "p"), &out->p);
    GenRead_b2Rot(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "q"), &out->q);
}

static mrb_value GenPush_b2Transform(mrb_state *mrb, const b2Transform *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "p", GenPush_b2Vec2(mrb, &in->p));
    SDLStaticGen_RubyHashSet(mrb, h, "q", GenPush_b2Rot(mrb, &in->q));
    return h;
}

static void GenRead_b2DistanceInput(mrb_state *mrb, mrb_value h, b2DistanceInput *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2ShapeProxy(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "proxyA"), &out->proxyA);
    GenRead_b2ShapeProxy(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "proxyB"), &out->proxyB);
    GenRead_b2Transform(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "transformA"), &out->transformA);
    GenRead_b2Transform(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "transformB"), &out->transformB);
    out->useRadii = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "useRadii");
}

static mrb_value GenPush_b2DistanceOutput(mrb_state *mrb, const b2DistanceOutput *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "pointA", GenPush_b2Vec2(mrb, &in->pointA));
    SDLStaticGen_RubyHashSet(mrb, h, "pointB", GenPush_b2Vec2(mrb, &in->pointB));
    SDLStaticGen_RubyHashSet(mrb, h, "normal", GenPush_b2Vec2(mrb, &in->normal));
    SDLStaticGen_RubyHashSet(mrb, h, "distance", mrb_float_value(mrb, (mrb_float)in->distance));
    SDLStaticGen_RubyHashSet(mrb, h, "iterations", mrb_int_value(mrb, (mrb_int)in->iterations));
    SDLStaticGen_RubyHashSet(mrb, h, "simplexCount", mrb_int_value(mrb, (mrb_int)in->simplexCount));
    return h;
}

static void GenRead_b2ExplosionDef(mrb_state *mrb, mrb_value h, b2ExplosionDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->maskBits = (uint64_t)SDLStaticGen_RubyFieldInt(mrb, h, "maskBits");
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "position"), &out->position);
    out->radius = (float)SDLStaticGen_RubyFieldNum(mrb, h, "radius");
    out->falloff = (float)SDLStaticGen_RubyFieldNum(mrb, h, "falloff");
    out->impulsePerLength = (float)SDLStaticGen_RubyFieldNum(mrb, h, "impulsePerLength");
}

static mrb_value GenPush_b2ExplosionDef(mrb_state *mrb, const b2ExplosionDef *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "maskBits", mrb_int_value(mrb, (mrb_int)in->maskBits));
    SDLStaticGen_RubyHashSet(mrb, h, "position", GenPush_b2Vec2(mrb, &in->position));
    SDLStaticGen_RubyHashSet(mrb, h, "radius", mrb_float_value(mrb, (mrb_float)in->radius));
    SDLStaticGen_RubyHashSet(mrb, h, "falloff", mrb_float_value(mrb, (mrb_float)in->falloff));
    SDLStaticGen_RubyHashSet(mrb, h, "impulsePerLength", mrb_float_value(mrb, (mrb_float)in->impulsePerLength));
    return h;
}

static mrb_value GenPush_b2Hull(mrb_state *mrb, const b2Hull *in)
{
    mrb_value h = mrb_hash_new(mrb);
    {
        mrb_value arr = mrb_ary_new_capa(mrb, (mrb_int)(B2_MAX_POLYGON_VERTICES));
        for (mrb_int gi = 0; gi < (mrb_int)(B2_MAX_POLYGON_VERTICES); ++gi) {
            mrb_ary_push(mrb, arr, GenPush_b2Vec2(mrb, &in->points[gi]));
        }
        SDLStaticGen_RubyHashSet(mrb, h, "points", arr);
    }
    SDLStaticGen_RubyHashSet(mrb, h, "count", mrb_int_value(mrb, (mrb_int)in->count));
    return h;
}

static void GenRead_b2JointId(mrb_state *mrb, mrb_value h, b2JointId *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->index1 = (int32_t)SDLStaticGen_RubyFieldInt(mrb, h, "index1");
    out->world0 = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "world0");
    out->generation = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "generation");
}

static mrb_value GenPush_b2JointId(mrb_state *mrb, const b2JointId *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "index1", mrb_int_value(mrb, (mrb_int)in->index1));
    SDLStaticGen_RubyHashSet(mrb, h, "world0", mrb_int_value(mrb, (mrb_int)in->world0));
    SDLStaticGen_RubyHashSet(mrb, h, "generation", mrb_int_value(mrb, (mrb_int)in->generation));
    return h;
}

static void GenRead_b2MassData(mrb_state *mrb, mrb_value h, b2MassData *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->mass = (float)SDLStaticGen_RubyFieldNum(mrb, h, "mass");
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "center"), &out->center);
    out->rotationalInertia = (float)SDLStaticGen_RubyFieldNum(mrb, h, "rotationalInertia");
}

static mrb_value GenPush_b2MassData(mrb_state *mrb, const b2MassData *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "mass", mrb_float_value(mrb, (mrb_float)in->mass));
    SDLStaticGen_RubyHashSet(mrb, h, "center", GenPush_b2Vec2(mrb, &in->center));
    SDLStaticGen_RubyHashSet(mrb, h, "rotationalInertia", mrb_float_value(mrb, (mrb_float)in->rotationalInertia));
    return h;
}

static mrb_value GenPush_b2PlaneSolverResult(mrb_state *mrb, const b2PlaneSolverResult *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "translation", GenPush_b2Vec2(mrb, &in->translation));
    SDLStaticGen_RubyHashSet(mrb, h, "iterationCount", mrb_int_value(mrb, (mrb_int)in->iterationCount));
    return h;
}

static void GenRead_b2Polygon(mrb_state *mrb, mrb_value h, b2Polygon *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    {
        mrb_value arr = SDLStaticGen_RubyFieldGet(mrb, h, "vertices");
        if (mrb_array_p(arr)) {
            for (mrb_int gi = 0; gi < (mrb_int)(B2_MAX_POLYGON_VERTICES) && gi < RARRAY_LEN(arr); ++gi) {
                mrb_value el = mrb_ary_ref(mrb, arr, gi);
                GenRead_b2Vec2(mrb, el, &out->vertices[gi]);
            }
        }
    }
    {
        mrb_value arr = SDLStaticGen_RubyFieldGet(mrb, h, "normals");
        if (mrb_array_p(arr)) {
            for (mrb_int gi = 0; gi < (mrb_int)(B2_MAX_POLYGON_VERTICES) && gi < RARRAY_LEN(arr); ++gi) {
                mrb_value el = mrb_ary_ref(mrb, arr, gi);
                GenRead_b2Vec2(mrb, el, &out->normals[gi]);
            }
        }
    }
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "centroid"), &out->centroid);
    out->radius = (float)SDLStaticGen_RubyFieldNum(mrb, h, "radius");
    out->count = (int)SDLStaticGen_RubyFieldInt(mrb, h, "count");
}

static mrb_value GenPush_b2Polygon(mrb_state *mrb, const b2Polygon *in)
{
    mrb_value h = mrb_hash_new(mrb);
    {
        mrb_value arr = mrb_ary_new_capa(mrb, (mrb_int)(B2_MAX_POLYGON_VERTICES));
        for (mrb_int gi = 0; gi < (mrb_int)(B2_MAX_POLYGON_VERTICES); ++gi) {
            mrb_ary_push(mrb, arr, GenPush_b2Vec2(mrb, &in->vertices[gi]));
        }
        SDLStaticGen_RubyHashSet(mrb, h, "vertices", arr);
    }
    {
        mrb_value arr = mrb_ary_new_capa(mrb, (mrb_int)(B2_MAX_POLYGON_VERTICES));
        for (mrb_int gi = 0; gi < (mrb_int)(B2_MAX_POLYGON_VERTICES); ++gi) {
            mrb_ary_push(mrb, arr, GenPush_b2Vec2(mrb, &in->normals[gi]));
        }
        SDLStaticGen_RubyHashSet(mrb, h, "normals", arr);
    }
    SDLStaticGen_RubyHashSet(mrb, h, "centroid", GenPush_b2Vec2(mrb, &in->centroid));
    SDLStaticGen_RubyHashSet(mrb, h, "radius", mrb_float_value(mrb, (mrb_float)in->radius));
    SDLStaticGen_RubyHashSet(mrb, h, "count", mrb_int_value(mrb, (mrb_int)in->count));
    return h;
}

static mrb_value GenPush_b2Profile(mrb_state *mrb, const b2Profile *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "step", mrb_float_value(mrb, (mrb_float)in->step));
    SDLStaticGen_RubyHashSet(mrb, h, "pairs", mrb_float_value(mrb, (mrb_float)in->pairs));
    SDLStaticGen_RubyHashSet(mrb, h, "collide", mrb_float_value(mrb, (mrb_float)in->collide));
    SDLStaticGen_RubyHashSet(mrb, h, "solve", mrb_float_value(mrb, (mrb_float)in->solve));
    SDLStaticGen_RubyHashSet(mrb, h, "mergeIslands", mrb_float_value(mrb, (mrb_float)in->mergeIslands));
    SDLStaticGen_RubyHashSet(mrb, h, "prepareStages", mrb_float_value(mrb, (mrb_float)in->prepareStages));
    SDLStaticGen_RubyHashSet(mrb, h, "solveConstraints", mrb_float_value(mrb, (mrb_float)in->solveConstraints));
    SDLStaticGen_RubyHashSet(mrb, h, "prepareConstraints", mrb_float_value(mrb, (mrb_float)in->prepareConstraints));
    SDLStaticGen_RubyHashSet(mrb, h, "integrateVelocities", mrb_float_value(mrb, (mrb_float)in->integrateVelocities));
    SDLStaticGen_RubyHashSet(mrb, h, "warmStart", mrb_float_value(mrb, (mrb_float)in->warmStart));
    SDLStaticGen_RubyHashSet(mrb, h, "solveImpulses", mrb_float_value(mrb, (mrb_float)in->solveImpulses));
    SDLStaticGen_RubyHashSet(mrb, h, "integratePositions", mrb_float_value(mrb, (mrb_float)in->integratePositions));
    SDLStaticGen_RubyHashSet(mrb, h, "relaxImpulses", mrb_float_value(mrb, (mrb_float)in->relaxImpulses));
    SDLStaticGen_RubyHashSet(mrb, h, "applyRestitution", mrb_float_value(mrb, (mrb_float)in->applyRestitution));
    SDLStaticGen_RubyHashSet(mrb, h, "storeImpulses", mrb_float_value(mrb, (mrb_float)in->storeImpulses));
    SDLStaticGen_RubyHashSet(mrb, h, "splitIslands", mrb_float_value(mrb, (mrb_float)in->splitIslands));
    SDLStaticGen_RubyHashSet(mrb, h, "transforms", mrb_float_value(mrb, (mrb_float)in->transforms));
    SDLStaticGen_RubyHashSet(mrb, h, "hitEvents", mrb_float_value(mrb, (mrb_float)in->hitEvents));
    SDLStaticGen_RubyHashSet(mrb, h, "refit", mrb_float_value(mrb, (mrb_float)in->refit));
    SDLStaticGen_RubyHashSet(mrb, h, "bullets", mrb_float_value(mrb, (mrb_float)in->bullets));
    SDLStaticGen_RubyHashSet(mrb, h, "sleepIslands", mrb_float_value(mrb, (mrb_float)in->sleepIslands));
    SDLStaticGen_RubyHashSet(mrb, h, "sensors", mrb_float_value(mrb, (mrb_float)in->sensors));
    return h;
}

static void GenRead_b2QueryFilter(mrb_state *mrb, mrb_value h, b2QueryFilter *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->categoryBits = (uint64_t)SDLStaticGen_RubyFieldInt(mrb, h, "categoryBits");
    out->maskBits = (uint64_t)SDLStaticGen_RubyFieldInt(mrb, h, "maskBits");
}

static mrb_value GenPush_b2QueryFilter(mrb_state *mrb, const b2QueryFilter *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "categoryBits", mrb_int_value(mrb, (mrb_int)in->categoryBits));
    SDLStaticGen_RubyHashSet(mrb, h, "maskBits", mrb_int_value(mrb, (mrb_int)in->maskBits));
    return h;
}

static void GenRead_b2RayCastInput(mrb_state *mrb, mrb_value h, b2RayCastInput *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "origin"), &out->origin);
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "translation"), &out->translation);
    out->maxFraction = (float)SDLStaticGen_RubyFieldNum(mrb, h, "maxFraction");
}

static mrb_value GenPush_b2RayResult(mrb_state *mrb, const b2RayResult *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "shapeId", GenPush_b2ShapeId(mrb, &in->shapeId));
    SDLStaticGen_RubyHashSet(mrb, h, "point", GenPush_b2Vec2(mrb, &in->point));
    SDLStaticGen_RubyHashSet(mrb, h, "normal", GenPush_b2Vec2(mrb, &in->normal));
    SDLStaticGen_RubyHashSet(mrb, h, "fraction", mrb_float_value(mrb, (mrb_float)in->fraction));
    SDLStaticGen_RubyHashSet(mrb, h, "nodeVisits", mrb_int_value(mrb, (mrb_int)in->nodeVisits));
    SDLStaticGen_RubyHashSet(mrb, h, "leafVisits", mrb_int_value(mrb, (mrb_int)in->leafVisits));
    SDLStaticGen_RubyHashSet(mrb, h, "hit", mrb_bool_value((mrb_bool)(in->hit != 0)));
    return h;
}

static mrb_value GenPush_b2SegmentDistanceResult(mrb_state *mrb, const b2SegmentDistanceResult *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "closest1", GenPush_b2Vec2(mrb, &in->closest1));
    SDLStaticGen_RubyHashSet(mrb, h, "closest2", GenPush_b2Vec2(mrb, &in->closest2));
    SDLStaticGen_RubyHashSet(mrb, h, "fraction1", mrb_float_value(mrb, (mrb_float)in->fraction1));
    SDLStaticGen_RubyHashSet(mrb, h, "fraction2", mrb_float_value(mrb, (mrb_float)in->fraction2));
    SDLStaticGen_RubyHashSet(mrb, h, "distanceSquared", mrb_float_value(mrb, (mrb_float)in->distanceSquared));
    return h;
}

static void GenRead_b2ShapeCastInput(mrb_state *mrb, mrb_value h, b2ShapeCastInput *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2ShapeProxy(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "proxy"), &out->proxy);
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "translation"), &out->translation);
    out->maxFraction = (float)SDLStaticGen_RubyFieldNum(mrb, h, "maxFraction");
    out->canEncroach = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "canEncroach");
}

static void GenRead_b2ShapeCastPairInput(mrb_state *mrb, mrb_value h, b2ShapeCastPairInput *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2ShapeProxy(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "proxyA"), &out->proxyA);
    GenRead_b2ShapeProxy(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "proxyB"), &out->proxyB);
    GenRead_b2Transform(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "transformA"), &out->transformA);
    GenRead_b2Transform(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "transformB"), &out->transformB);
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "translationB"), &out->translationB);
    out->maxFraction = (float)SDLStaticGen_RubyFieldNum(mrb, h, "maxFraction");
    out->canEncroach = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "canEncroach");
}

static void GenRead_b2ShapeDef(mrb_state *mrb, mrb_value h, b2ShapeDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2SurfaceMaterial(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "material"), &out->material);
    out->density = (float)SDLStaticGen_RubyFieldNum(mrb, h, "density");
    GenRead_b2Filter(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "filter"), &out->filter);
    out->isSensor = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "isSensor");
    out->enableSensorEvents = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "enableSensorEvents");
    out->enableContactEvents = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "enableContactEvents");
    out->enableHitEvents = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "enableHitEvents");
    out->enablePreSolveEvents = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "enablePreSolveEvents");
    out->invokeContactCreation = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "invokeContactCreation");
    out->updateBodyMass = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "updateBodyMass");
    out->internalValue = (int)SDLStaticGen_RubyFieldInt(mrb, h, "internalValue");
}

static mrb_value GenPush_b2ShapeDef(mrb_state *mrb, const b2ShapeDef *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "material", GenPush_b2SurfaceMaterial(mrb, &in->material));
    SDLStaticGen_RubyHashSet(mrb, h, "density", mrb_float_value(mrb, (mrb_float)in->density));
    SDLStaticGen_RubyHashSet(mrb, h, "filter", GenPush_b2Filter(mrb, &in->filter));
    SDLStaticGen_RubyHashSet(mrb, h, "isSensor", mrb_bool_value((mrb_bool)(in->isSensor != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "enableSensorEvents", mrb_bool_value((mrb_bool)(in->enableSensorEvents != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "enableContactEvents", mrb_bool_value((mrb_bool)(in->enableContactEvents != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "enableHitEvents", mrb_bool_value((mrb_bool)(in->enableHitEvents != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "enablePreSolveEvents", mrb_bool_value((mrb_bool)(in->enablePreSolveEvents != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "invokeContactCreation", mrb_bool_value((mrb_bool)(in->invokeContactCreation != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "updateBodyMass", mrb_bool_value((mrb_bool)(in->updateBodyMass != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "internalValue", mrb_int_value(mrb, (mrb_int)in->internalValue));
    return h;
}

static mrb_value GenPush_b2SimplexVertex(mrb_state *mrb, const b2SimplexVertex *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "wA", GenPush_b2Vec2(mrb, &in->wA));
    SDLStaticGen_RubyHashSet(mrb, h, "wB", GenPush_b2Vec2(mrb, &in->wB));
    SDLStaticGen_RubyHashSet(mrb, h, "w", GenPush_b2Vec2(mrb, &in->w));
    SDLStaticGen_RubyHashSet(mrb, h, "a", mrb_float_value(mrb, (mrb_float)in->a));
    SDLStaticGen_RubyHashSet(mrb, h, "indexA", mrb_int_value(mrb, (mrb_int)in->indexA));
    SDLStaticGen_RubyHashSet(mrb, h, "indexB", mrb_int_value(mrb, (mrb_int)in->indexB));
    return h;
}

static mrb_value GenPush_b2Simplex(mrb_state *mrb, const b2Simplex *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "v1", GenPush_b2SimplexVertex(mrb, &in->v1));
    SDLStaticGen_RubyHashSet(mrb, h, "v2", GenPush_b2SimplexVertex(mrb, &in->v2));
    SDLStaticGen_RubyHashSet(mrb, h, "v3", GenPush_b2SimplexVertex(mrb, &in->v3));
    SDLStaticGen_RubyHashSet(mrb, h, "count", mrb_int_value(mrb, (mrb_int)in->count));
    return h;
}

static void GenRead_b2Sweep(mrb_state *mrb, mrb_value h, b2Sweep *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "localCenter"), &out->localCenter);
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "c1"), &out->c1);
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "c2"), &out->c2);
    GenRead_b2Rot(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "q1"), &out->q1);
    GenRead_b2Rot(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "q2"), &out->q2);
}

static void GenRead_b2TOIInput(mrb_state *mrb, mrb_value h, b2TOIInput *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2ShapeProxy(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "proxyA"), &out->proxyA);
    GenRead_b2ShapeProxy(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "proxyB"), &out->proxyB);
    GenRead_b2Sweep(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "sweepA"), &out->sweepA);
    GenRead_b2Sweep(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "sweepB"), &out->sweepB);
    out->maxFraction = (float)SDLStaticGen_RubyFieldNum(mrb, h, "maxFraction");
}

static mrb_value GenPush_b2TOIOutput(mrb_state *mrb, const b2TOIOutput *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "state", mrb_int_value(mrb, (mrb_int)in->state));
    SDLStaticGen_RubyHashSet(mrb, h, "fraction", mrb_float_value(mrb, (mrb_float)in->fraction));
    return h;
}

static mrb_value GenPush_b2Version(mrb_state *mrb, const b2Version *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "major", mrb_int_value(mrb, (mrb_int)in->major));
    SDLStaticGen_RubyHashSet(mrb, h, "minor", mrb_int_value(mrb, (mrb_int)in->minor));
    SDLStaticGen_RubyHashSet(mrb, h, "revision", mrb_int_value(mrb, (mrb_int)in->revision));
    return h;
}

static void GenRead_b2WorldDef(mrb_state *mrb, mrb_value h, b2WorldDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    GenRead_b2Vec2(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "gravity"), &out->gravity);
    out->restitutionThreshold = (float)SDLStaticGen_RubyFieldNum(mrb, h, "restitutionThreshold");
    out->hitEventThreshold = (float)SDLStaticGen_RubyFieldNum(mrb, h, "hitEventThreshold");
    out->contactHertz = (float)SDLStaticGen_RubyFieldNum(mrb, h, "contactHertz");
    out->contactDampingRatio = (float)SDLStaticGen_RubyFieldNum(mrb, h, "contactDampingRatio");
    out->maxContactPushSpeed = (float)SDLStaticGen_RubyFieldNum(mrb, h, "maxContactPushSpeed");
    out->maximumLinearSpeed = (float)SDLStaticGen_RubyFieldNum(mrb, h, "maximumLinearSpeed");
    out->enableSleep = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "enableSleep");
    out->enableContinuous = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "enableContinuous");
    out->workerCount = (int)SDLStaticGen_RubyFieldInt(mrb, h, "workerCount");
    out->internalValue = (int)SDLStaticGen_RubyFieldInt(mrb, h, "internalValue");
}

static mrb_value GenPush_b2WorldDef(mrb_state *mrb, const b2WorldDef *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "gravity", GenPush_b2Vec2(mrb, &in->gravity));
    SDLStaticGen_RubyHashSet(mrb, h, "restitutionThreshold", mrb_float_value(mrb, (mrb_float)in->restitutionThreshold));
    SDLStaticGen_RubyHashSet(mrb, h, "hitEventThreshold", mrb_float_value(mrb, (mrb_float)in->hitEventThreshold));
    SDLStaticGen_RubyHashSet(mrb, h, "contactHertz", mrb_float_value(mrb, (mrb_float)in->contactHertz));
    SDLStaticGen_RubyHashSet(mrb, h, "contactDampingRatio", mrb_float_value(mrb, (mrb_float)in->contactDampingRatio));
    SDLStaticGen_RubyHashSet(mrb, h, "maxContactPushSpeed", mrb_float_value(mrb, (mrb_float)in->maxContactPushSpeed));
    SDLStaticGen_RubyHashSet(mrb, h, "maximumLinearSpeed", mrb_float_value(mrb, (mrb_float)in->maximumLinearSpeed));
    SDLStaticGen_RubyHashSet(mrb, h, "enableSleep", mrb_bool_value((mrb_bool)(in->enableSleep != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "enableContinuous", mrb_bool_value((mrb_bool)(in->enableContinuous != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "workerCount", mrb_int_value(mrb, (mrb_int)in->workerCount));
    SDLStaticGen_RubyHashSet(mrb, h, "internalValue", mrb_int_value(mrb, (mrb_int)in->internalValue));
    return h;
}

static void GenRead_b2WorldId(mrb_state *mrb, mrb_value h, b2WorldId *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->index1 = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "index1");
    out->generation = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "generation");
}

static mrb_value GenPush_b2WorldId(mrb_state *mrb, const b2WorldId *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "index1", mrb_int_value(mrb, (mrb_int)in->index1));
    SDLStaticGen_RubyHashSet(mrb, h, "generation", mrb_int_value(mrb, (mrb_int)in->generation));
    return h;
}

static mrb_value GenR_b2Atan2(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float rv = b2Atan2(a0, a1);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Body_ApplyAngularImpulse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    b2Body_ApplyAngularImpulse(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_ApplyForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Vec2 a2;
    GenRead_b2Vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    b2Body_ApplyForce(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_ApplyForceToCenter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    b2Body_ApplyForceToCenter(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_ApplyLinearImpulse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Vec2 a2;
    GenRead_b2Vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    b2Body_ApplyLinearImpulse(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_ApplyLinearImpulseToCenter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    b2Body_ApplyLinearImpulseToCenter(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_ApplyMassFromShapes(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Body_ApplyMassFromShapes(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_ApplyTorque(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    b2Body_ApplyTorque(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_ComputeAABB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2AABB rv = b2Body_ComputeAABB(a0);
    return GenPush_b2AABB(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_Disable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Body_Disable(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_Enable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Body_Enable(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_EnableContactEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_EnableContactEvents(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_EnableHitEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_EnableHitEvents(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_EnableSleep(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_EnableSleep(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_GetAngularDamping(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Body_GetAngularDamping(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Body_GetAngularVelocity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Body_GetAngularVelocity(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Body_GetContactCapacity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    int rv = b2Body_GetContactCapacity(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2Body_GetContactData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ContactData out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = b2Body_GetContactData(a0, &out1, a2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_b2ContactData(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_b2Body_GetGravityScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Body_GetGravityScale(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Body_GetJointCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    int rv = b2Body_GetJointCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2Body_GetJoints(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2JointId out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = b2Body_GetJoints(a0, &out1, a2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_b2JointId(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_b2Body_GetLinearDamping(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Body_GetLinearDamping(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Body_GetLinearVelocity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 rv = b2Body_GetLinearVelocity(a0);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetLocalCenterOfMass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 rv = b2Body_GetLocalCenterOfMass(a0);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetLocalPoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Vec2 rv = b2Body_GetLocalPoint(a0, a1);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetLocalPointVelocity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Vec2 rv = b2Body_GetLocalPointVelocity(a0, a1);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetLocalVector(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Vec2 rv = b2Body_GetLocalVector(a0, a1);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetMass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Body_GetMass(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Body_GetMassData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2MassData rv = b2Body_GetMassData(a0);
    return GenPush_b2MassData(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const char * rv = b2Body_GetName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_b2Body_GetPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 rv = b2Body_GetPosition(a0);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetRotation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Rot rv = b2Body_GetRotation(a0);
    return GenPush_b2Rot(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetRotationalInertia(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Body_GetRotationalInertia(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Body_GetShapeCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    int rv = b2Body_GetShapeCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2Body_GetShapes(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ShapeId out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = b2Body_GetShapes(a0, &out1, a2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_b2ShapeId(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_b2Body_GetSleepThreshold(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Body_GetSleepThreshold(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Body_GetTransform(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Transform rv = b2Body_GetTransform(a0);
    return GenPush_b2Transform(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2BodyType rv = b2Body_GetType(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2Body_GetWorld(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2WorldId rv = b2Body_GetWorld(a0);
    return GenPush_b2WorldId(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetWorldCenterOfMass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 rv = b2Body_GetWorldCenterOfMass(a0);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetWorldPoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Vec2 rv = b2Body_GetWorldPoint(a0, a1);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetWorldPointVelocity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Vec2 rv = b2Body_GetWorldPointVelocity(a0, a1);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_GetWorldVector(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Vec2 rv = b2Body_GetWorldVector(a0, a1);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Body_IsAwake(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Body_IsAwake(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Body_IsBullet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Body_IsBullet(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Body_IsEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Body_IsEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Body_IsFixedRotation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Body_IsFixedRotation(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Body_IsSleepEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Body_IsSleepEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Body_IsValid(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Body_IsValid(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Body_SetAngularDamping(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_SetAngularDamping(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetAngularVelocity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_SetAngularVelocity(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetAwake(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_SetAwake(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetBullet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_SetBullet(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetFixedRotation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_SetFixedRotation(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetGravityScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_SetGravityScale(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetLinearDamping(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_SetLinearDamping(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetLinearVelocity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Body_SetLinearVelocity(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetMassData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2MassData a1;
    GenRead_b2MassData(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Body_SetMassData(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_SetName(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetSleepThreshold(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_SetSleepThreshold(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetTargetTransform(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2Body_SetTargetTransform(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetTransform(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Rot a2;
    GenRead_b2Rot(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    b2Body_SetTransform(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Body_SetType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2BodyType a1 = (b2BodyType)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Body_SetType(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Chain_GetFriction(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainId a0;
    GenRead_b2ChainId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Chain_GetFriction(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Chain_GetMaterial(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainId a0;
    GenRead_b2ChainId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    int rv = b2Chain_GetMaterial(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2Chain_GetRestitution(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainId a0;
    GenRead_b2ChainId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Chain_GetRestitution(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Chain_GetSegmentCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainId a0;
    GenRead_b2ChainId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    int rv = b2Chain_GetSegmentCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2Chain_GetSegments(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainId a0;
    GenRead_b2ChainId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ShapeId out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = b2Chain_GetSegments(a0, &out1, a2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_b2ShapeId(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_b2Chain_GetWorld(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainId a0;
    GenRead_b2ChainId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2WorldId rv = b2Chain_GetWorld(a0);
    return GenPush_b2WorldId(mrb, &rv);
    }
}

static mrb_value GenR_b2Chain_IsValid(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainId a0;
    GenRead_b2ChainId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Chain_IsValid(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Chain_SetFriction(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainId a0;
    GenRead_b2ChainId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Chain_SetFriction(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Chain_SetMaterial(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainId a0;
    GenRead_b2ChainId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Chain_SetMaterial(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Chain_SetRestitution(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainId a0;
    GenRead_b2ChainId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Chain_SetRestitution(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2ClipVector(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Vec2 a0;
    GenRead_b2Vec2(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2CollisionPlane tmp1;
    const b2CollisionPlane *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2CollisionPlane(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2Vec2 rv = b2ClipVector(a0, a1, a2);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2CollideCapsuleAndCircle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Capsule tmp0;
    const b2Capsule *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Capsule(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Circle(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Manifold rv = b2CollideCapsuleAndCircle(a0, a1, a2, a3);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2CollideCapsules(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Capsule tmp0;
    const b2Capsule *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Capsule(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Capsule tmp2;
    const b2Capsule *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Capsule(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Manifold rv = b2CollideCapsules(a0, a1, a2, a3);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2CollideChainSegmentAndCapsule(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainSegment tmp0;
    const b2ChainSegment *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2ChainSegment(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Capsule tmp2;
    const b2Capsule *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Capsule(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2SimplexCache *a4 = (b2SimplexCache *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), "b2SimplexCache");
    b2Manifold rv = b2CollideChainSegmentAndCapsule(a0, a1, a2, a3, a4);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2CollideChainSegmentAndCircle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainSegment tmp0;
    const b2ChainSegment *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2ChainSegment(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Circle(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Manifold rv = b2CollideChainSegmentAndCircle(a0, a1, a2, a3);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2CollideChainSegmentAndPolygon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainSegment tmp0;
    const b2ChainSegment *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2ChainSegment(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Polygon tmp2;
    const b2Polygon *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Polygon(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2SimplexCache *a4 = (b2SimplexCache *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), "b2SimplexCache");
    b2Manifold rv = b2CollideChainSegmentAndPolygon(a0, a1, a2, a3, a4);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2CollideCircles(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Circle tmp0;
    const b2Circle *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Circle(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Circle(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Manifold rv = b2CollideCircles(a0, a1, a2, a3);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2CollidePolygonAndCapsule(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Polygon tmp0;
    const b2Polygon *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Polygon(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Capsule tmp2;
    const b2Capsule *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Capsule(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Manifold rv = b2CollidePolygonAndCapsule(a0, a1, a2, a3);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2CollidePolygonAndCircle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Polygon tmp0;
    const b2Polygon *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Polygon(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Circle(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Manifold rv = b2CollidePolygonAndCircle(a0, a1, a2, a3);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2CollidePolygons(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Polygon tmp0;
    const b2Polygon *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Polygon(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Polygon tmp2;
    const b2Polygon *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Polygon(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Manifold rv = b2CollidePolygons(a0, a1, a2, a3);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2CollideSegmentAndCapsule(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Segment tmp0;
    const b2Segment *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Segment(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Capsule tmp2;
    const b2Capsule *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Capsule(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Manifold rv = b2CollideSegmentAndCapsule(a0, a1, a2, a3);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2CollideSegmentAndCircle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Segment tmp0;
    const b2Segment *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Segment(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Circle(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Manifold rv = b2CollideSegmentAndCircle(a0, a1, a2, a3);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2CollideSegmentAndPolygon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Segment tmp0;
    const b2Segment *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Segment(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Polygon tmp2;
    const b2Polygon *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Polygon(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2Transform a3;
    GenRead_b2Transform(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Manifold rv = b2CollideSegmentAndPolygon(a0, a1, a2, a3);
    return GenPush_b2Manifold(mrb, &rv);
    }
}

static mrb_value GenR_b2ComputeCapsuleAABB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Capsule tmp0;
    const b2Capsule *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Capsule(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2AABB rv = b2ComputeCapsuleAABB(a0, a1);
    return GenPush_b2AABB(mrb, &rv);
    }
}

static mrb_value GenR_b2ComputeCapsuleMass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Capsule tmp0;
    const b2Capsule *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Capsule(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2MassData rv = b2ComputeCapsuleMass(a0, a1);
    return GenPush_b2MassData(mrb, &rv);
    }
}

static mrb_value GenR_b2ComputeCircleAABB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Circle tmp0;
    const b2Circle *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Circle(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2AABB rv = b2ComputeCircleAABB(a0, a1);
    return GenPush_b2AABB(mrb, &rv);
    }
}

static mrb_value GenR_b2ComputeCircleMass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Circle tmp0;
    const b2Circle *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Circle(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2MassData rv = b2ComputeCircleMass(a0, a1);
    return GenPush_b2MassData(mrb, &rv);
    }
}

static mrb_value GenR_b2ComputeCosSin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    b2CosSin rv = b2ComputeCosSin(a0);
    return GenPush_b2CosSin(mrb, &rv);
    }
}

static mrb_value GenR_b2ComputeHull(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Vec2 tmp0;
    const b2Vec2 *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Vec2(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Hull rv = b2ComputeHull(a0, a1);
    return GenPush_b2Hull(mrb, &rv);
    }
}

static mrb_value GenR_b2ComputePolygonAABB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Polygon tmp0;
    const b2Polygon *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Polygon(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2AABB rv = b2ComputePolygonAABB(a0, a1);
    return GenPush_b2AABB(mrb, &rv);
    }
}

static mrb_value GenR_b2ComputePolygonMass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Polygon tmp0;
    const b2Polygon *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Polygon(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2MassData rv = b2ComputePolygonMass(a0, a1);
    return GenPush_b2MassData(mrb, &rv);
    }
}

static mrb_value GenR_b2ComputeRotationBetweenUnitVectors(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Vec2 a0;
    GenRead_b2Vec2(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Rot rv = b2ComputeRotationBetweenUnitVectors(a0, a1);
    return GenPush_b2Rot(mrb, &rv);
    }
}

static mrb_value GenR_b2ComputeSegmentAABB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Segment tmp0;
    const b2Segment *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Segment(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Transform a1;
    GenRead_b2Transform(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2AABB rv = b2ComputeSegmentAABB(a0, a1);
    return GenPush_b2AABB(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateBody(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2BodyDef tmp1;
    const b2BodyDef *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2BodyDef(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2BodyId rv = b2CreateBody(a0, a1);
    return GenPush_b2BodyId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateCapsuleShape(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ShapeDef tmp1;
    const b2ShapeDef *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2ShapeDef(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2Capsule tmp2;
    const b2Capsule *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Capsule(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2ShapeId rv = b2CreateCapsuleShape(a0, a1, a2);
    return GenPush_b2ShapeId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateChain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ChainDef tmp1;
    const b2ChainDef *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2ChainDef(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2ChainId rv = b2CreateChain(a0, a1);
    return GenPush_b2ChainId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateCircleShape(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ShapeDef tmp1;
    const b2ShapeDef *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2ShapeDef(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2Circle tmp2;
    const b2Circle *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Circle(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2ShapeId rv = b2CreateCircleShape(a0, a1, a2);
    return GenPush_b2ShapeId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateDistanceJoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const b2DistanceJointDef *a1 = (const b2DistanceJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "b2DistanceJointDef");
    b2JointId rv = b2CreateDistanceJoint(a0, a1);
    return GenPush_b2JointId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateFilterJoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const b2FilterJointDef *a1 = (const b2FilterJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "b2FilterJointDef");
    b2JointId rv = b2CreateFilterJoint(a0, a1);
    return GenPush_b2JointId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateMotorJoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const b2MotorJointDef *a1 = (const b2MotorJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "b2MotorJointDef");
    b2JointId rv = b2CreateMotorJoint(a0, a1);
    return GenPush_b2JointId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateMouseJoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const b2MouseJointDef *a1 = (const b2MouseJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "b2MouseJointDef");
    b2JointId rv = b2CreateMouseJoint(a0, a1);
    return GenPush_b2JointId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreatePolygonShape(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ShapeDef tmp1;
    const b2ShapeDef *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2ShapeDef(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2Polygon tmp2;
    const b2Polygon *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Polygon(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2ShapeId rv = b2CreatePolygonShape(a0, a1, a2);
    return GenPush_b2ShapeId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreatePrismaticJoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const b2PrismaticJointDef *a1 = (const b2PrismaticJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "b2PrismaticJointDef");
    b2JointId rv = b2CreatePrismaticJoint(a0, a1);
    return GenPush_b2JointId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateRevoluteJoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const b2RevoluteJointDef *a1 = (const b2RevoluteJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "b2RevoluteJointDef");
    b2JointId rv = b2CreateRevoluteJoint(a0, a1);
    return GenPush_b2JointId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateSegmentShape(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ShapeDef tmp1;
    const b2ShapeDef *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2ShapeDef(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2Segment tmp2;
    const b2Segment *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_b2Segment(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    b2ShapeId rv = b2CreateSegmentShape(a0, a1, a2);
    return GenPush_b2ShapeId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateWeldJoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const b2WeldJointDef *a1 = (const b2WeldJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "b2WeldJointDef");
    b2JointId rv = b2CreateWeldJoint(a0, a1);
    return GenPush_b2JointId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateWheelJoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const b2WheelJointDef *a1 = (const b2WheelJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "b2WheelJointDef");
    b2JointId rv = b2CreateWheelJoint(a0, a1);
    return GenPush_b2JointId(mrb, &rv);
    }
}

static mrb_value GenR_b2CreateWorld(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldDef tmp0;
    const b2WorldDef *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2WorldDef(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2WorldId rv = b2CreateWorld(a0);
    return GenPush_b2WorldId(mrb, &rv);
    }
}

static mrb_value GenR_b2DefaultBodyDef(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyDef rv = b2DefaultBodyDef();
    return GenPush_b2BodyDef(mrb, &rv);
    }
}

static mrb_value GenR_b2DefaultChainDef(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainDef rv = b2DefaultChainDef();
    return GenPush_b2ChainDef(mrb, &rv);
    }
}

static mrb_value GenR_b2DefaultExplosionDef(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ExplosionDef rv = b2DefaultExplosionDef();
    return GenPush_b2ExplosionDef(mrb, &rv);
    }
}

static mrb_value GenR_b2DefaultFilter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Filter rv = b2DefaultFilter();
    return GenPush_b2Filter(mrb, &rv);
    }
}

static mrb_value GenR_b2DefaultQueryFilter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2QueryFilter rv = b2DefaultQueryFilter();
    return GenPush_b2QueryFilter(mrb, &rv);
    }
}

static mrb_value GenR_b2DefaultShapeDef(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeDef rv = b2DefaultShapeDef();
    return GenPush_b2ShapeDef(mrb, &rv);
    }
}

static mrb_value GenR_b2DefaultSurfaceMaterial(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2SurfaceMaterial rv = b2DefaultSurfaceMaterial();
    return GenPush_b2SurfaceMaterial(mrb, &rv);
    }
}

static mrb_value GenR_b2DefaultWorldDef(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldDef rv = b2DefaultWorldDef();
    return GenPush_b2WorldDef(mrb, &rv);
    }
}

static mrb_value GenR_b2DestroyBody(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2BodyId a0;
    GenRead_b2BodyId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2DestroyBody(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DestroyChain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ChainId a0;
    GenRead_b2ChainId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2DestroyChain(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DestroyJoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2DestroyJoint(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DestroyShape(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2DestroyShape(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DestroyWorld(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2DestroyWorld(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DistanceJoint_EnableLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2DistanceJoint_EnableLimit(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DistanceJoint_EnableMotor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2DistanceJoint_EnableMotor(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DistanceJoint_EnableSpring(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2DistanceJoint_EnableSpring(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DistanceJoint_GetCurrentLength(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2DistanceJoint_GetCurrentLength(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2DistanceJoint_GetLength(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2DistanceJoint_GetLength(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2DistanceJoint_GetMaxLength(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2DistanceJoint_GetMaxLength(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2DistanceJoint_GetMaxMotorForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2DistanceJoint_GetMaxMotorForce(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2DistanceJoint_GetMinLength(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2DistanceJoint_GetMinLength(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2DistanceJoint_GetMotorForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2DistanceJoint_GetMotorForce(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2DistanceJoint_GetMotorSpeed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2DistanceJoint_GetMotorSpeed(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2DistanceJoint_GetSpringDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2DistanceJoint_GetSpringDampingRatio(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2DistanceJoint_GetSpringHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2DistanceJoint_GetSpringHertz(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2DistanceJoint_IsLimitEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2DistanceJoint_IsLimitEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2DistanceJoint_IsMotorEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2DistanceJoint_IsMotorEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2DistanceJoint_IsSpringEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2DistanceJoint_IsSpringEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2DistanceJoint_SetLength(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2DistanceJoint_SetLength(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DistanceJoint_SetLengthRange(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2DistanceJoint_SetLengthRange(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DistanceJoint_SetMaxMotorForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2DistanceJoint_SetMaxMotorForce(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DistanceJoint_SetMotorSpeed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2DistanceJoint_SetMotorSpeed(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DistanceJoint_SetSpringDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2DistanceJoint_SetSpringDampingRatio(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DistanceJoint_SetSpringHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2DistanceJoint_SetSpringHertz(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DynamicTree_CreateProxy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    b2AABB a1;
    GenRead_b2AABB(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    uint64_t a2 = (uint64_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    uint64_t a3 = (uint64_t)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int rv = b2DynamicTree_CreateProxy(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2DynamicTree_Destroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    b2DynamicTree_Destroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DynamicTree_DestroyProxy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2DynamicTree_DestroyProxy(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DynamicTree_EnlargeProxy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2AABB a2;
    GenRead_b2AABB(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    b2DynamicTree_EnlargeProxy(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DynamicTree_GetAABB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2AABB rv = b2DynamicTree_GetAABB(a0, a1);
    return GenPush_b2AABB(mrb, &rv);
    }
}

static mrb_value GenR_b2DynamicTree_GetAreaRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    float rv = b2DynamicTree_GetAreaRatio(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2DynamicTree_GetByteCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    int rv = b2DynamicTree_GetByteCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2DynamicTree_GetCategoryBits(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    uint64_t rv = b2DynamicTree_GetCategoryBits(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2DynamicTree_GetHeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    int rv = b2DynamicTree_GetHeight(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2DynamicTree_GetProxyCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    int rv = b2DynamicTree_GetProxyCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2DynamicTree_GetRootBounds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    b2AABB rv = b2DynamicTree_GetRootBounds(a0);
    return GenPush_b2AABB(mrb, &rv);
    }
}

static mrb_value GenR_b2DynamicTree_GetUserData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    uint64_t rv = b2DynamicTree_GetUserData(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2DynamicTree_MoveProxy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2AABB a2;
    GenRead_b2AABB(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    b2DynamicTree_MoveProxy(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DynamicTree_Rebuild(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = b2DynamicTree_Rebuild(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2DynamicTree_SetCategoryBits(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DynamicTree *a0 = (b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    uint64_t a2 = (uint64_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2DynamicTree_SetCategoryBits(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DynamicTree_Validate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    b2DynamicTree_Validate(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2DynamicTree_ValidateNoEnlarged(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2DynamicTree *a0 = (const b2DynamicTree *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DynamicTree");
    b2DynamicTree_ValidateNoEnlarged(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2GetByteCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = b2GetByteCount();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2GetLengthUnitsPerMeter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float rv = b2GetLengthUnitsPerMeter();
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2GetMilliseconds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    uint64_t a0 = (uint64_t)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float rv = b2GetMilliseconds(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2GetMillisecondsAndReset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    uint64_t io0 = (uint64_t)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float rv = b2GetMillisecondsAndReset(&io0);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_b2GetSweepTransform(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Sweep tmp0;
    const b2Sweep *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Sweep(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Transform rv = b2GetSweepTransform(a0, a1);
    return GenPush_b2Transform(mrb, &rv);
    }
}

static mrb_value GenR_b2GetTicks(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    uint64_t rv = b2GetTicks();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2GetVersion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Version rv = b2GetVersion();
    return GenPush_b2Version(mrb, &rv);
    }
}

static mrb_value GenR_b2InternalAssertFcn(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = b2InternalAssertFcn(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2IsValidAABB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2AABB a0;
    GenRead_b2AABB(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2IsValidAABB(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2IsValidFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = b2IsValidFloat(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2IsValidPlane(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Plane a0;
    GenRead_b2Plane(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2IsValidPlane(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2IsValidRay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RayCastInput tmp0;
    const b2RayCastInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2RayCastInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    bool rv = b2IsValidRay(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2IsValidRotation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Rot a0;
    GenRead_b2Rot(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2IsValidRotation(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2IsValidVec2(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Vec2 a0;
    GenRead_b2Vec2(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2IsValidVec2(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Joint_GetAngularSeparation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Joint_GetAngularSeparation(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Joint_GetBodyA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2BodyId rv = b2Joint_GetBodyA(a0);
    return GenPush_b2BodyId(mrb, &rv);
    }
}

static mrb_value GenR_b2Joint_GetBodyB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2BodyId rv = b2Joint_GetBodyB(a0);
    return GenPush_b2BodyId(mrb, &rv);
    }
}

static mrb_value GenR_b2Joint_GetCollideConnected(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Joint_GetCollideConnected(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Joint_GetConstraintForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 rv = b2Joint_GetConstraintForce(a0);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Joint_GetConstraintTorque(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Joint_GetConstraintTorque(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Joint_GetConstraintTuning(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2Joint_GetConstraintTuning(a0, &io1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)io1);
    rets[1] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_b2Joint_GetLinearSeparation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Joint_GetLinearSeparation(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Joint_GetLocalAnchorA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 rv = b2Joint_GetLocalAnchorA(a0);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Joint_GetLocalAnchorB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 rv = b2Joint_GetLocalAnchorB(a0);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Joint_GetLocalAxisA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 rv = b2Joint_GetLocalAxisA(a0);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Joint_GetReferenceAngle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Joint_GetReferenceAngle(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Joint_GetType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2JointType rv = b2Joint_GetType(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2Joint_GetWorld(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2WorldId rv = b2Joint_GetWorld(a0);
    return GenPush_b2WorldId(mrb, &rv);
    }
}

static mrb_value GenR_b2Joint_IsValid(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Joint_IsValid(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Joint_SetCollideConnected(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2Joint_SetCollideConnected(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Joint_SetConstraintTuning(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2Joint_SetConstraintTuning(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Joint_SetLocalAnchorA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Joint_SetLocalAnchorA(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Joint_SetLocalAnchorB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Joint_SetLocalAnchorB(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Joint_SetLocalAxisA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Joint_SetLocalAxisA(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Joint_SetReferenceAngle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Joint_SetReferenceAngle(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Joint_WakeBodies(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Joint_WakeBodies(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2MakeBox(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Polygon rv = b2MakeBox(a0, a1);
    return GenPush_b2Polygon(mrb, &rv);
    }
}

static mrb_value GenR_b2MakeOffsetBox(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Vec2 a2;
    GenRead_b2Vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    b2Rot a3;
    GenRead_b2Rot(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Polygon rv = b2MakeOffsetBox(a0, a1, a2, a3);
    return GenPush_b2Polygon(mrb, &rv);
    }
}

static mrb_value GenR_b2MakeOffsetPolygon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2Hull *a0 = (const b2Hull *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2Hull");
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Rot a2;
    GenRead_b2Rot(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    b2Polygon rv = b2MakeOffsetPolygon(a0, a1, a2);
    return GenPush_b2Polygon(mrb, &rv);
    }
}

static mrb_value GenR_b2MakeOffsetProxy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Vec2 tmp0;
    const b2Vec2 *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Vec2(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2Vec2 a3;
    GenRead_b2Vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2Rot a4;
    GenRead_b2Rot(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), &a4);
    b2ShapeProxy rv = b2MakeOffsetProxy(a0, a1, a2, a3, a4);
    return GenPush_b2ShapeProxy(mrb, &rv);
    }
}

static mrb_value GenR_b2MakeOffsetRoundedBox(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Vec2 a2;
    GenRead_b2Vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    b2Rot a3;
    GenRead_b2Rot(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    b2Polygon rv = b2MakeOffsetRoundedBox(a0, a1, a2, a3, a4);
    return GenPush_b2Polygon(mrb, &rv);
    }
}

static mrb_value GenR_b2MakeOffsetRoundedPolygon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2Hull *a0 = (const b2Hull *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2Hull");
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Rot a2;
    GenRead_b2Rot(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    b2Polygon rv = b2MakeOffsetRoundedPolygon(a0, a1, a2, a3);
    return GenPush_b2Polygon(mrb, &rv);
    }
}

static mrb_value GenR_b2MakePolygon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2Hull *a0 = (const b2Hull *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2Hull");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Polygon rv = b2MakePolygon(a0, a1);
    return GenPush_b2Polygon(mrb, &rv);
    }
}

static mrb_value GenR_b2MakeProxy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Vec2 tmp0;
    const b2Vec2 *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2Vec2(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2ShapeProxy rv = b2MakeProxy(a0, a1, a2);
    return GenPush_b2ShapeProxy(mrb, &rv);
    }
}

static mrb_value GenR_b2MakeRoundedBox(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2Polygon rv = b2MakeRoundedBox(a0, a1, a2);
    return GenPush_b2Polygon(mrb, &rv);
    }
}

static mrb_value GenR_b2MakeSquare(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    b2Polygon rv = b2MakeSquare(a0);
    return GenPush_b2Polygon(mrb, &rv);
    }
}

static mrb_value GenR_b2MotorJoint_GetAngularOffset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2MotorJoint_GetAngularOffset(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2MotorJoint_GetCorrectionFactor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2MotorJoint_GetCorrectionFactor(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2MotorJoint_GetLinearOffset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 rv = b2MotorJoint_GetLinearOffset(a0);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2MotorJoint_GetMaxForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2MotorJoint_GetMaxForce(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2MotorJoint_GetMaxTorque(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2MotorJoint_GetMaxTorque(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2MotorJoint_SetAngularOffset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2MotorJoint_SetAngularOffset(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2MotorJoint_SetCorrectionFactor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2MotorJoint_SetCorrectionFactor(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2MotorJoint_SetLinearOffset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2MotorJoint_SetLinearOffset(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2MotorJoint_SetMaxForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2MotorJoint_SetMaxForce(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2MotorJoint_SetMaxTorque(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2MotorJoint_SetMaxTorque(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2MouseJoint_GetMaxForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2MouseJoint_GetMaxForce(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2MouseJoint_GetSpringDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2MouseJoint_GetSpringDampingRatio(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2MouseJoint_GetSpringHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2MouseJoint_GetSpringHertz(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2MouseJoint_GetTarget(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 rv = b2MouseJoint_GetTarget(a0);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2MouseJoint_SetMaxForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2MouseJoint_SetMaxForce(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2MouseJoint_SetSpringDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2MouseJoint_SetSpringDampingRatio(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2MouseJoint_SetSpringHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2MouseJoint_SetSpringHertz(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2MouseJoint_SetTarget(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2MouseJoint_SetTarget(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2PointInCapsule(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Vec2 a0;
    GenRead_b2Vec2(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Capsule tmp1;
    const b2Capsule *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Capsule(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = b2PointInCapsule(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2PointInCircle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Vec2 a0;
    GenRead_b2Vec2(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Circle tmp1;
    const b2Circle *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Circle(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = b2PointInCircle(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2PointInPolygon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Vec2 a0;
    GenRead_b2Vec2(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Polygon tmp1;
    const b2Polygon *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Polygon(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = b2PointInPolygon(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2PrismaticJoint_EnableLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2PrismaticJoint_EnableLimit(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2PrismaticJoint_EnableMotor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2PrismaticJoint_EnableMotor(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2PrismaticJoint_EnableSpring(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2PrismaticJoint_EnableSpring(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2PrismaticJoint_GetLowerLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2PrismaticJoint_GetLowerLimit(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2PrismaticJoint_GetMaxMotorForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2PrismaticJoint_GetMaxMotorForce(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2PrismaticJoint_GetMotorForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2PrismaticJoint_GetMotorForce(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2PrismaticJoint_GetMotorSpeed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2PrismaticJoint_GetMotorSpeed(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2PrismaticJoint_GetSpeed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2PrismaticJoint_GetSpeed(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2PrismaticJoint_GetSpringDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2PrismaticJoint_GetSpringDampingRatio(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2PrismaticJoint_GetSpringHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2PrismaticJoint_GetSpringHertz(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2PrismaticJoint_GetTargetTranslation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2PrismaticJoint_GetTargetTranslation(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2PrismaticJoint_GetTranslation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2PrismaticJoint_GetTranslation(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2PrismaticJoint_GetUpperLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2PrismaticJoint_GetUpperLimit(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2PrismaticJoint_IsLimitEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2PrismaticJoint_IsLimitEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2PrismaticJoint_IsMotorEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2PrismaticJoint_IsMotorEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2PrismaticJoint_IsSpringEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2PrismaticJoint_IsSpringEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2PrismaticJoint_SetLimits(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2PrismaticJoint_SetLimits(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2PrismaticJoint_SetMaxMotorForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2PrismaticJoint_SetMaxMotorForce(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2PrismaticJoint_SetMotorSpeed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2PrismaticJoint_SetMotorSpeed(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2PrismaticJoint_SetSpringDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2PrismaticJoint_SetSpringDampingRatio(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2PrismaticJoint_SetSpringHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2PrismaticJoint_SetSpringHertz(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2PrismaticJoint_SetTargetTranslation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2PrismaticJoint_SetTargetTranslation(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2RayCastCapsule(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RayCastInput tmp0;
    const b2RayCastInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2RayCastInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Capsule tmp1;
    const b2Capsule *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Capsule(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2RayCastCapsule(a0, a1);
    return GenPush_b2CastOutput(mrb, &rv);
    }
}

static mrb_value GenR_b2RayCastCircle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RayCastInput tmp0;
    const b2RayCastInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2RayCastInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Circle tmp1;
    const b2Circle *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Circle(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2RayCastCircle(a0, a1);
    return GenPush_b2CastOutput(mrb, &rv);
    }
}

static mrb_value GenR_b2RayCastPolygon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RayCastInput tmp0;
    const b2RayCastInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2RayCastInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Polygon tmp1;
    const b2Polygon *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Polygon(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2RayCastPolygon(a0, a1);
    return GenPush_b2CastOutput(mrb, &rv);
    }
}

static mrb_value GenR_b2RayCastSegment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RayCastInput tmp0;
    const b2RayCastInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2RayCastInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Segment tmp1;
    const b2Segment *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Segment(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    b2CastOutput rv = b2RayCastSegment(a0, a1, a2);
    return GenPush_b2CastOutput(mrb, &rv);
    }
}

static mrb_value GenR_b2RevoluteJoint_EnableLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2RevoluteJoint_EnableLimit(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2RevoluteJoint_EnableMotor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2RevoluteJoint_EnableMotor(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2RevoluteJoint_EnableSpring(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2RevoluteJoint_EnableSpring(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2RevoluteJoint_GetAngle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2RevoluteJoint_GetAngle(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2RevoluteJoint_GetLowerLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2RevoluteJoint_GetLowerLimit(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2RevoluteJoint_GetMaxMotorTorque(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2RevoluteJoint_GetMaxMotorTorque(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2RevoluteJoint_GetMotorSpeed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2RevoluteJoint_GetMotorSpeed(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2RevoluteJoint_GetMotorTorque(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2RevoluteJoint_GetMotorTorque(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2RevoluteJoint_GetSpringDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2RevoluteJoint_GetSpringDampingRatio(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2RevoluteJoint_GetSpringHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2RevoluteJoint_GetSpringHertz(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2RevoluteJoint_GetTargetAngle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2RevoluteJoint_GetTargetAngle(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2RevoluteJoint_GetUpperLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2RevoluteJoint_GetUpperLimit(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2RevoluteJoint_IsLimitEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2RevoluteJoint_IsLimitEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2RevoluteJoint_IsMotorEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2RevoluteJoint_IsMotorEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2RevoluteJoint_IsSpringEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2RevoluteJoint_IsSpringEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2RevoluteJoint_SetLimits(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2RevoluteJoint_SetLimits(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2RevoluteJoint_SetMaxMotorTorque(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2RevoluteJoint_SetMaxMotorTorque(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2RevoluteJoint_SetMotorSpeed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2RevoluteJoint_SetMotorSpeed(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2RevoluteJoint_SetSpringDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2RevoluteJoint_SetSpringDampingRatio(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2RevoluteJoint_SetSpringHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2RevoluteJoint_SetSpringHertz(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2RevoluteJoint_SetTargetAngle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2RevoluteJoint_SetTargetAngle(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2SegmentDistance(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Vec2 a0;
    GenRead_b2Vec2(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Vec2 a2;
    GenRead_b2Vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    b2Vec2 a3;
    GenRead_b2Vec2(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2SegmentDistanceResult rv = b2SegmentDistance(a0, a1, a2, a3);
    return GenPush_b2SegmentDistanceResult(mrb, &rv);
    }
}

static mrb_value GenR_b2SetLengthUnitsPerMeter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    b2SetLengthUnitsPerMeter(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2ShapeCast(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeCastPairInput tmp0;
    const b2ShapeCastPairInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2ShapeCastPairInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2CastOutput rv = b2ShapeCast(a0);
    return GenPush_b2CastOutput(mrb, &rv);
    }
}

static mrb_value GenR_b2ShapeCastCapsule(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeCastInput tmp0;
    const b2ShapeCastInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2ShapeCastInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Capsule tmp1;
    const b2Capsule *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Capsule(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2ShapeCastCapsule(a0, a1);
    return GenPush_b2CastOutput(mrb, &rv);
    }
}

static mrb_value GenR_b2ShapeCastCircle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeCastInput tmp0;
    const b2ShapeCastInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2ShapeCastInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Circle tmp1;
    const b2Circle *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Circle(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2ShapeCastCircle(a0, a1);
    return GenPush_b2CastOutput(mrb, &rv);
    }
}

static mrb_value GenR_b2ShapeCastPolygon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeCastInput tmp0;
    const b2ShapeCastInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2ShapeCastInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Polygon tmp1;
    const b2Polygon *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Polygon(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2ShapeCastPolygon(a0, a1);
    return GenPush_b2CastOutput(mrb, &rv);
    }
}

static mrb_value GenR_b2ShapeCastSegment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeCastInput tmp0;
    const b2ShapeCastInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2ShapeCastInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2Segment tmp1;
    const b2Segment *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Segment(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2ShapeCastSegment(a0, a1);
    return GenPush_b2CastOutput(mrb, &rv);
    }
}

static mrb_value GenR_b2ShapeDistance(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DistanceInput tmp0;
    const b2DistanceInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2DistanceInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2SimplexCache *a1 = (b2SimplexCache *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "b2SimplexCache");
    b2Simplex out2;
    memset(&out2, 0, sizeof(out2));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2DistanceOutput rv = b2ShapeDistance(a0, a1, &out2, a3);
    mrb_value rets[2];
    rets[0] = GenPush_b2DistanceOutput(mrb, &rv);
    rets[1] = GenPush_b2Simplex(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_b2Shape_AreContactEventsEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Shape_AreContactEventsEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Shape_AreHitEventsEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Shape_AreHitEventsEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Shape_ArePreSolveEventsEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Shape_ArePreSolveEventsEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Shape_AreSensorEventsEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Shape_AreSensorEventsEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Shape_EnableContactEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2Shape_EnableContactEvents(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_EnableHitEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2Shape_EnableHitEvents(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_EnablePreSolveEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2Shape_EnablePreSolveEvents(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_EnableSensorEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2Shape_EnableSensorEvents(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_GetAABB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2AABB rv = b2Shape_GetAABB(a0);
    return GenPush_b2AABB(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetBody(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2BodyId rv = b2Shape_GetBody(a0);
    return GenPush_b2BodyId(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetCapsule(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Capsule rv = b2Shape_GetCapsule(a0);
    return GenPush_b2Capsule(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetChainSegment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ChainSegment rv = b2Shape_GetChainSegment(a0);
    return GenPush_b2ChainSegment(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetCircle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Circle rv = b2Shape_GetCircle(a0);
    return GenPush_b2Circle(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetClosestPoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Vec2 rv = b2Shape_GetClosestPoint(a0, a1);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetContactCapacity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    int rv = b2Shape_GetContactCapacity(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2Shape_GetContactData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ContactData out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = b2Shape_GetContactData(a0, &out1, a2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_b2ContactData(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_b2Shape_GetDensity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Shape_GetDensity(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Shape_GetFilter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Filter rv = b2Shape_GetFilter(a0);
    return GenPush_b2Filter(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetFriction(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Shape_GetFriction(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Shape_GetMassData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2MassData rv = b2Shape_GetMassData(a0);
    return GenPush_b2MassData(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetMaterial(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    int rv = b2Shape_GetMaterial(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2Shape_GetParentChain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ChainId rv = b2Shape_GetParentChain(a0);
    return GenPush_b2ChainId(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetPolygon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Polygon rv = b2Shape_GetPolygon(a0);
    return GenPush_b2Polygon(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetRestitution(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2Shape_GetRestitution(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2Shape_GetSegment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Segment rv = b2Shape_GetSegment(a0);
    return GenPush_b2Segment(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetSensorCapacity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    int rv = b2Shape_GetSensorCapacity(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2Shape_GetSensorOverlaps(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ShapeId out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = b2Shape_GetSensorOverlaps(a0, &out1, a2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_b2ShapeId(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_b2Shape_GetSurfaceMaterial(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2SurfaceMaterial rv = b2Shape_GetSurfaceMaterial(a0);
    return GenPush_b2SurfaceMaterial(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_GetType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ShapeType rv = b2Shape_GetType(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2Shape_GetWorld(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2WorldId rv = b2Shape_GetWorld(a0);
    return GenPush_b2WorldId(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_IsSensor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Shape_IsSensor(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Shape_IsValid(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2Shape_IsValid(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2Shape_RayCast(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2RayCastInput tmp1;
    const b2RayCastInput *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2RayCastInput(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2CastOutput rv = b2Shape_RayCast(a0, a1);
    return GenPush_b2CastOutput(mrb, &rv);
    }
}

static mrb_value GenR_b2Shape_SetCapsule(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Capsule tmp1;
    const b2Capsule *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Capsule(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2Shape_SetCapsule(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_SetCircle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Circle tmp1;
    const b2Circle *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Circle(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2Shape_SetCircle(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_SetDensity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    b2Shape_SetDensity(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_SetFilter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Filter a1;
    GenRead_b2Filter(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Shape_SetFilter(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_SetFriction(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Shape_SetFriction(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_SetMaterial(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Shape_SetMaterial(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_SetPolygon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Polygon tmp1;
    const b2Polygon *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Polygon(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2Shape_SetPolygon(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_SetRestitution(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2Shape_SetRestitution(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_SetSegment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Segment tmp1;
    const b2Segment *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Segment(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2Shape_SetSegment(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_SetSurfaceMaterial(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2SurfaceMaterial a1;
    GenRead_b2SurfaceMaterial(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Shape_SetSurfaceMaterial(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Shape_TestPoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2ShapeId a0;
    GenRead_b2ShapeId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    bool rv = b2Shape_TestPoint(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2SolvePlanes(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Vec2 a0;
    GenRead_b2Vec2(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2CollisionPlane out1;
    memset(&out1, 0, sizeof(out1));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2PlaneSolverResult rv = b2SolvePlanes(a0, &out1, a2);
    mrb_value rets[2];
    rets[0] = GenPush_b2PlaneSolverResult(mrb, &rv);
    rets[1] = GenPush_b2CollisionPlane(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_b2TimeOfImpact(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2TOIInput tmp0;
    const b2TOIInput *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_b2TOIInput(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    b2TOIOutput rv = b2TimeOfImpact(a0);
    return GenPush_b2TOIOutput(mrb, &rv);
    }
}

static mrb_value GenR_b2TransformPolygon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Transform a0;
    GenRead_b2Transform(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Polygon tmp1;
    const b2Polygon *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Polygon(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2Polygon rv = b2TransformPolygon(a0, a1);
    return GenPush_b2Polygon(mrb, &rv);
    }
}

static mrb_value GenR_b2ValidateHull(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const b2Hull *a0 = (const b2Hull *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2Hull");
    bool rv = b2ValidateHull(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2WeldJoint_GetAngularDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2WeldJoint_GetAngularDampingRatio(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2WeldJoint_GetAngularHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2WeldJoint_GetAngularHertz(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2WeldJoint_GetLinearDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2WeldJoint_GetLinearDampingRatio(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2WeldJoint_GetLinearHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2WeldJoint_GetLinearHertz(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2WeldJoint_SetAngularDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2WeldJoint_SetAngularDampingRatio(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2WeldJoint_SetAngularHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2WeldJoint_SetAngularHertz(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2WeldJoint_SetLinearDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2WeldJoint_SetLinearDampingRatio(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2WeldJoint_SetLinearHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2WeldJoint_SetLinearHertz(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2WheelJoint_EnableLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2WheelJoint_EnableLimit(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2WheelJoint_EnableMotor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2WheelJoint_EnableMotor(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2WheelJoint_EnableSpring(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2WheelJoint_EnableSpring(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2WheelJoint_GetLowerLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2WheelJoint_GetLowerLimit(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2WheelJoint_GetMaxMotorTorque(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2WheelJoint_GetMaxMotorTorque(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2WheelJoint_GetMotorSpeed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2WheelJoint_GetMotorSpeed(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2WheelJoint_GetMotorTorque(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2WheelJoint_GetMotorTorque(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2WheelJoint_GetSpringDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2WheelJoint_GetSpringDampingRatio(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2WheelJoint_GetSpringHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2WheelJoint_GetSpringHertz(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2WheelJoint_GetUpperLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2WheelJoint_GetUpperLimit(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2WheelJoint_IsLimitEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2WheelJoint_IsLimitEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2WheelJoint_IsMotorEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2WheelJoint_IsMotorEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2WheelJoint_IsSpringEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2WheelJoint_IsSpringEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2WheelJoint_SetLimits(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2WheelJoint_SetLimits(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2WheelJoint_SetMaxMotorTorque(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2WheelJoint_SetMaxMotorTorque(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2WheelJoint_SetMotorSpeed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2WheelJoint_SetMotorSpeed(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2WheelJoint_SetSpringDampingRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2WheelJoint_SetSpringDampingRatio(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2WheelJoint_SetSpringHertz(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2JointId a0;
    GenRead_b2JointId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2WheelJoint_SetSpringHertz(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_CastMover(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Capsule tmp1;
    const b2Capsule *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2Capsule(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2Vec2 a2;
    GenRead_b2Vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    b2QueryFilter a3;
    GenRead_b2QueryFilter(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    float rv = b2World_CastMover(a0, a1, a2, a3);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2World_CastRayClosest(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2Vec2 a2;
    GenRead_b2Vec2(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    b2QueryFilter a3;
    GenRead_b2QueryFilter(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &a3);
    b2RayResult rv = b2World_CastRayClosest(a0, a1, a2, a3);
    return GenPush_b2RayResult(mrb, &rv);
    }
}

static mrb_value GenR_b2World_Draw(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2DebugDraw *a1 = (b2DebugDraw *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "b2DebugDraw");
    b2World_Draw(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_DumpMemoryStats(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2World_DumpMemoryStats(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_EnableContinuous(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2World_EnableContinuous(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_EnableSleeping(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2World_EnableSleeping(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_EnableSpeculative(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2World_EnableSpeculative(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_EnableWarmStarting(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    b2World_EnableWarmStarting(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_Explode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2ExplosionDef tmp1;
    const b2ExplosionDef *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_b2ExplosionDef(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    b2World_Explode(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_GetAwakeBodyCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    int rv = b2World_GetAwakeBodyCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_b2World_GetCounters(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Counters rv = b2World_GetCounters(a0);
    return GenPush_b2Counters(mrb, &rv);
    }
}

static mrb_value GenR_b2World_GetGravity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 rv = b2World_GetGravity(a0);
    return GenPush_b2Vec2(mrb, &rv);
    }
}

static mrb_value GenR_b2World_GetHitEventThreshold(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2World_GetHitEventThreshold(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2World_GetMaximumLinearSpeed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2World_GetMaximumLinearSpeed(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2World_GetProfile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Profile rv = b2World_GetProfile(a0);
    return GenPush_b2Profile(mrb, &rv);
    }
}

static mrb_value GenR_b2World_GetRestitutionThreshold(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float rv = b2World_GetRestitutionThreshold(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_b2World_IsContinuousEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2World_IsContinuousEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2World_IsSleepingEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2World_IsSleepingEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2World_IsValid(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2World_IsValid(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2World_IsWarmStartingEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    bool rv = b2World_IsWarmStartingEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_b2World_RebuildStaticTree(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2World_RebuildStaticTree(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_SetContactTuning(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    b2World_SetContactTuning(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_SetGravity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    b2Vec2 a1;
    GenRead_b2Vec2(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2World_SetGravity(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_SetHitEventThreshold(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2World_SetHitEventThreshold(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_SetMaximumLinearSpeed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2World_SetMaximumLinearSpeed(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_SetRestitutionThreshold(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    b2World_SetRestitutionThreshold(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2World_Step(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    b2World_Step(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_b2Yield(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2Yield();
    return mrb_nil_value();
    }
}

void SDLStaticGen_OpenRuby_b2(mrb_state *mrb);
void SDLStaticGen_OpenRuby_b2(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "B2");
    mrb_define_module_function(mrb, mod, "Atan2", GenR_b2Atan2, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_ApplyAngularImpulse", GenR_b2Body_ApplyAngularImpulse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_ApplyForce", GenR_b2Body_ApplyForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_ApplyForceToCenter", GenR_b2Body_ApplyForceToCenter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_ApplyLinearImpulse", GenR_b2Body_ApplyLinearImpulse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_ApplyLinearImpulseToCenter", GenR_b2Body_ApplyLinearImpulseToCenter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_ApplyMassFromShapes", GenR_b2Body_ApplyMassFromShapes, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_ApplyTorque", GenR_b2Body_ApplyTorque, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_ComputeAABB", GenR_b2Body_ComputeAABB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_Disable", GenR_b2Body_Disable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_Enable", GenR_b2Body_Enable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_EnableContactEvents", GenR_b2Body_EnableContactEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_EnableHitEvents", GenR_b2Body_EnableHitEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_EnableSleep", GenR_b2Body_EnableSleep, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetAngularDamping", GenR_b2Body_GetAngularDamping, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetAngularVelocity", GenR_b2Body_GetAngularVelocity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetContactCapacity", GenR_b2Body_GetContactCapacity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetContactData", GenR_b2Body_GetContactData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetGravityScale", GenR_b2Body_GetGravityScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetJointCount", GenR_b2Body_GetJointCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetJoints", GenR_b2Body_GetJoints, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetLinearDamping", GenR_b2Body_GetLinearDamping, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetLinearVelocity", GenR_b2Body_GetLinearVelocity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetLocalCenterOfMass", GenR_b2Body_GetLocalCenterOfMass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetLocalPoint", GenR_b2Body_GetLocalPoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetLocalPointVelocity", GenR_b2Body_GetLocalPointVelocity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetLocalVector", GenR_b2Body_GetLocalVector, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetMass", GenR_b2Body_GetMass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetMassData", GenR_b2Body_GetMassData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetName", GenR_b2Body_GetName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetPosition", GenR_b2Body_GetPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetRotation", GenR_b2Body_GetRotation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetRotationalInertia", GenR_b2Body_GetRotationalInertia, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetShapeCount", GenR_b2Body_GetShapeCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetShapes", GenR_b2Body_GetShapes, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetSleepThreshold", GenR_b2Body_GetSleepThreshold, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetTransform", GenR_b2Body_GetTransform, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetType", GenR_b2Body_GetType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetWorld", GenR_b2Body_GetWorld, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetWorldCenterOfMass", GenR_b2Body_GetWorldCenterOfMass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetWorldPoint", GenR_b2Body_GetWorldPoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetWorldPointVelocity", GenR_b2Body_GetWorldPointVelocity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_GetWorldVector", GenR_b2Body_GetWorldVector, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_IsAwake", GenR_b2Body_IsAwake, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_IsBullet", GenR_b2Body_IsBullet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_IsEnabled", GenR_b2Body_IsEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_IsFixedRotation", GenR_b2Body_IsFixedRotation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_IsSleepEnabled", GenR_b2Body_IsSleepEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_IsValid", GenR_b2Body_IsValid, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetAngularDamping", GenR_b2Body_SetAngularDamping, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetAngularVelocity", GenR_b2Body_SetAngularVelocity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetAwake", GenR_b2Body_SetAwake, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetBullet", GenR_b2Body_SetBullet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetFixedRotation", GenR_b2Body_SetFixedRotation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetGravityScale", GenR_b2Body_SetGravityScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetLinearDamping", GenR_b2Body_SetLinearDamping, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetLinearVelocity", GenR_b2Body_SetLinearVelocity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetMassData", GenR_b2Body_SetMassData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetName", GenR_b2Body_SetName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetSleepThreshold", GenR_b2Body_SetSleepThreshold, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetTargetTransform", GenR_b2Body_SetTargetTransform, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetTransform", GenR_b2Body_SetTransform, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Body_SetType", GenR_b2Body_SetType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Chain_GetFriction", GenR_b2Chain_GetFriction, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Chain_GetMaterial", GenR_b2Chain_GetMaterial, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Chain_GetRestitution", GenR_b2Chain_GetRestitution, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Chain_GetSegmentCount", GenR_b2Chain_GetSegmentCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Chain_GetSegments", GenR_b2Chain_GetSegments, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Chain_GetWorld", GenR_b2Chain_GetWorld, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Chain_IsValid", GenR_b2Chain_IsValid, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Chain_SetFriction", GenR_b2Chain_SetFriction, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Chain_SetMaterial", GenR_b2Chain_SetMaterial, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Chain_SetRestitution", GenR_b2Chain_SetRestitution, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ClipVector", GenR_b2ClipVector, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollideCapsuleAndCircle", GenR_b2CollideCapsuleAndCircle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollideCapsules", GenR_b2CollideCapsules, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollideChainSegmentAndCapsule", GenR_b2CollideChainSegmentAndCapsule, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollideChainSegmentAndCircle", GenR_b2CollideChainSegmentAndCircle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollideChainSegmentAndPolygon", GenR_b2CollideChainSegmentAndPolygon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollideCircles", GenR_b2CollideCircles, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollidePolygonAndCapsule", GenR_b2CollidePolygonAndCapsule, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollidePolygonAndCircle", GenR_b2CollidePolygonAndCircle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollidePolygons", GenR_b2CollidePolygons, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollideSegmentAndCapsule", GenR_b2CollideSegmentAndCapsule, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollideSegmentAndCircle", GenR_b2CollideSegmentAndCircle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CollideSegmentAndPolygon", GenR_b2CollideSegmentAndPolygon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ComputeCapsuleAABB", GenR_b2ComputeCapsuleAABB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ComputeCapsuleMass", GenR_b2ComputeCapsuleMass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ComputeCircleAABB", GenR_b2ComputeCircleAABB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ComputeCircleMass", GenR_b2ComputeCircleMass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ComputeCosSin", GenR_b2ComputeCosSin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ComputeHull", GenR_b2ComputeHull, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ComputePolygonAABB", GenR_b2ComputePolygonAABB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ComputePolygonMass", GenR_b2ComputePolygonMass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ComputeRotationBetweenUnitVectors", GenR_b2ComputeRotationBetweenUnitVectors, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ComputeSegmentAABB", GenR_b2ComputeSegmentAABB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateBody", GenR_b2CreateBody, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateCapsuleShape", GenR_b2CreateCapsuleShape, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateChain", GenR_b2CreateChain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateCircleShape", GenR_b2CreateCircleShape, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateDistanceJoint", GenR_b2CreateDistanceJoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateFilterJoint", GenR_b2CreateFilterJoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateMotorJoint", GenR_b2CreateMotorJoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateMouseJoint", GenR_b2CreateMouseJoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreatePolygonShape", GenR_b2CreatePolygonShape, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreatePrismaticJoint", GenR_b2CreatePrismaticJoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateRevoluteJoint", GenR_b2CreateRevoluteJoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateSegmentShape", GenR_b2CreateSegmentShape, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateWeldJoint", GenR_b2CreateWeldJoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateWheelJoint", GenR_b2CreateWheelJoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateWorld", GenR_b2CreateWorld, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DefaultBodyDef", GenR_b2DefaultBodyDef, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DefaultChainDef", GenR_b2DefaultChainDef, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DefaultExplosionDef", GenR_b2DefaultExplosionDef, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DefaultFilter", GenR_b2DefaultFilter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DefaultQueryFilter", GenR_b2DefaultQueryFilter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DefaultShapeDef", GenR_b2DefaultShapeDef, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DefaultSurfaceMaterial", GenR_b2DefaultSurfaceMaterial, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DefaultWorldDef", GenR_b2DefaultWorldDef, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyBody", GenR_b2DestroyBody, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyChain", GenR_b2DestroyChain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyJoint", GenR_b2DestroyJoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyShape", GenR_b2DestroyShape, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyWorld", GenR_b2DestroyWorld, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_EnableLimit", GenR_b2DistanceJoint_EnableLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_EnableMotor", GenR_b2DistanceJoint_EnableMotor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_EnableSpring", GenR_b2DistanceJoint_EnableSpring, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_GetCurrentLength", GenR_b2DistanceJoint_GetCurrentLength, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_GetLength", GenR_b2DistanceJoint_GetLength, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_GetMaxLength", GenR_b2DistanceJoint_GetMaxLength, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_GetMaxMotorForce", GenR_b2DistanceJoint_GetMaxMotorForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_GetMinLength", GenR_b2DistanceJoint_GetMinLength, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_GetMotorForce", GenR_b2DistanceJoint_GetMotorForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_GetMotorSpeed", GenR_b2DistanceJoint_GetMotorSpeed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_GetSpringDampingRatio", GenR_b2DistanceJoint_GetSpringDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_GetSpringHertz", GenR_b2DistanceJoint_GetSpringHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_IsLimitEnabled", GenR_b2DistanceJoint_IsLimitEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_IsMotorEnabled", GenR_b2DistanceJoint_IsMotorEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_IsSpringEnabled", GenR_b2DistanceJoint_IsSpringEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_SetLength", GenR_b2DistanceJoint_SetLength, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_SetLengthRange", GenR_b2DistanceJoint_SetLengthRange, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_SetMaxMotorForce", GenR_b2DistanceJoint_SetMaxMotorForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_SetMotorSpeed", GenR_b2DistanceJoint_SetMotorSpeed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_SetSpringDampingRatio", GenR_b2DistanceJoint_SetSpringDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJoint_SetSpringHertz", GenR_b2DistanceJoint_SetSpringHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_CreateProxy", GenR_b2DynamicTree_CreateProxy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_Destroy", GenR_b2DynamicTree_Destroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_DestroyProxy", GenR_b2DynamicTree_DestroyProxy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_EnlargeProxy", GenR_b2DynamicTree_EnlargeProxy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_GetAABB", GenR_b2DynamicTree_GetAABB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_GetAreaRatio", GenR_b2DynamicTree_GetAreaRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_GetByteCount", GenR_b2DynamicTree_GetByteCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_GetCategoryBits", GenR_b2DynamicTree_GetCategoryBits, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_GetHeight", GenR_b2DynamicTree_GetHeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_GetProxyCount", GenR_b2DynamicTree_GetProxyCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_GetRootBounds", GenR_b2DynamicTree_GetRootBounds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_GetUserData", GenR_b2DynamicTree_GetUserData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_MoveProxy", GenR_b2DynamicTree_MoveProxy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_Rebuild", GenR_b2DynamicTree_Rebuild, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_SetCategoryBits", GenR_b2DynamicTree_SetCategoryBits, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_Validate", GenR_b2DynamicTree_Validate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DynamicTree_ValidateNoEnlarged", GenR_b2DynamicTree_ValidateNoEnlarged, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetByteCount", GenR_b2GetByteCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetLengthUnitsPerMeter", GenR_b2GetLengthUnitsPerMeter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMilliseconds", GenR_b2GetMilliseconds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMillisecondsAndReset", GenR_b2GetMillisecondsAndReset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSweepTransform", GenR_b2GetSweepTransform, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTicks", GenR_b2GetTicks, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetVersion", GenR_b2GetVersion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "InternalAssertFcn", GenR_b2InternalAssertFcn, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsValidAABB", GenR_b2IsValidAABB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsValidFloat", GenR_b2IsValidFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsValidPlane", GenR_b2IsValidPlane, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsValidRay", GenR_b2IsValidRay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsValidRotation", GenR_b2IsValidRotation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsValidVec2", GenR_b2IsValidVec2, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetAngularSeparation", GenR_b2Joint_GetAngularSeparation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetBodyA", GenR_b2Joint_GetBodyA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetBodyB", GenR_b2Joint_GetBodyB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetCollideConnected", GenR_b2Joint_GetCollideConnected, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetConstraintForce", GenR_b2Joint_GetConstraintForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetConstraintTorque", GenR_b2Joint_GetConstraintTorque, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetConstraintTuning", GenR_b2Joint_GetConstraintTuning, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetLinearSeparation", GenR_b2Joint_GetLinearSeparation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetLocalAnchorA", GenR_b2Joint_GetLocalAnchorA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetLocalAnchorB", GenR_b2Joint_GetLocalAnchorB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetLocalAxisA", GenR_b2Joint_GetLocalAxisA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetReferenceAngle", GenR_b2Joint_GetReferenceAngle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetType", GenR_b2Joint_GetType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_GetWorld", GenR_b2Joint_GetWorld, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_IsValid", GenR_b2Joint_IsValid, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_SetCollideConnected", GenR_b2Joint_SetCollideConnected, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_SetConstraintTuning", GenR_b2Joint_SetConstraintTuning, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_SetLocalAnchorA", GenR_b2Joint_SetLocalAnchorA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_SetLocalAnchorB", GenR_b2Joint_SetLocalAnchorB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_SetLocalAxisA", GenR_b2Joint_SetLocalAxisA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_SetReferenceAngle", GenR_b2Joint_SetReferenceAngle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Joint_WakeBodies", GenR_b2Joint_WakeBodies, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MakeBox", GenR_b2MakeBox, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MakeOffsetBox", GenR_b2MakeOffsetBox, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MakeOffsetPolygon", GenR_b2MakeOffsetPolygon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MakeOffsetProxy", GenR_b2MakeOffsetProxy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MakeOffsetRoundedBox", GenR_b2MakeOffsetRoundedBox, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MakeOffsetRoundedPolygon", GenR_b2MakeOffsetRoundedPolygon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MakePolygon", GenR_b2MakePolygon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MakeProxy", GenR_b2MakeProxy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MakeRoundedBox", GenR_b2MakeRoundedBox, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MakeSquare", GenR_b2MakeSquare, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJoint_GetAngularOffset", GenR_b2MotorJoint_GetAngularOffset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJoint_GetCorrectionFactor", GenR_b2MotorJoint_GetCorrectionFactor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJoint_GetLinearOffset", GenR_b2MotorJoint_GetLinearOffset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJoint_GetMaxForce", GenR_b2MotorJoint_GetMaxForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJoint_GetMaxTorque", GenR_b2MotorJoint_GetMaxTorque, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJoint_SetAngularOffset", GenR_b2MotorJoint_SetAngularOffset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJoint_SetCorrectionFactor", GenR_b2MotorJoint_SetCorrectionFactor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJoint_SetLinearOffset", GenR_b2MotorJoint_SetLinearOffset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJoint_SetMaxForce", GenR_b2MotorJoint_SetMaxForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJoint_SetMaxTorque", GenR_b2MotorJoint_SetMaxTorque, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJoint_GetMaxForce", GenR_b2MouseJoint_GetMaxForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJoint_GetSpringDampingRatio", GenR_b2MouseJoint_GetSpringDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJoint_GetSpringHertz", GenR_b2MouseJoint_GetSpringHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJoint_GetTarget", GenR_b2MouseJoint_GetTarget, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJoint_SetMaxForce", GenR_b2MouseJoint_SetMaxForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJoint_SetSpringDampingRatio", GenR_b2MouseJoint_SetSpringDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJoint_SetSpringHertz", GenR_b2MouseJoint_SetSpringHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJoint_SetTarget", GenR_b2MouseJoint_SetTarget, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PointInCapsule", GenR_b2PointInCapsule, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PointInCircle", GenR_b2PointInCircle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PointInPolygon", GenR_b2PointInPolygon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_EnableLimit", GenR_b2PrismaticJoint_EnableLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_EnableMotor", GenR_b2PrismaticJoint_EnableMotor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_EnableSpring", GenR_b2PrismaticJoint_EnableSpring, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_GetLowerLimit", GenR_b2PrismaticJoint_GetLowerLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_GetMaxMotorForce", GenR_b2PrismaticJoint_GetMaxMotorForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_GetMotorForce", GenR_b2PrismaticJoint_GetMotorForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_GetMotorSpeed", GenR_b2PrismaticJoint_GetMotorSpeed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_GetSpeed", GenR_b2PrismaticJoint_GetSpeed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_GetSpringDampingRatio", GenR_b2PrismaticJoint_GetSpringDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_GetSpringHertz", GenR_b2PrismaticJoint_GetSpringHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_GetTargetTranslation", GenR_b2PrismaticJoint_GetTargetTranslation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_GetTranslation", GenR_b2PrismaticJoint_GetTranslation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_GetUpperLimit", GenR_b2PrismaticJoint_GetUpperLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_IsLimitEnabled", GenR_b2PrismaticJoint_IsLimitEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_IsMotorEnabled", GenR_b2PrismaticJoint_IsMotorEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_IsSpringEnabled", GenR_b2PrismaticJoint_IsSpringEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_SetLimits", GenR_b2PrismaticJoint_SetLimits, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_SetMaxMotorForce", GenR_b2PrismaticJoint_SetMaxMotorForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_SetMotorSpeed", GenR_b2PrismaticJoint_SetMotorSpeed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_SetSpringDampingRatio", GenR_b2PrismaticJoint_SetSpringDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_SetSpringHertz", GenR_b2PrismaticJoint_SetSpringHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJoint_SetTargetTranslation", GenR_b2PrismaticJoint_SetTargetTranslation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RayCastCapsule", GenR_b2RayCastCapsule, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RayCastCircle", GenR_b2RayCastCircle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RayCastPolygon", GenR_b2RayCastPolygon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RayCastSegment", GenR_b2RayCastSegment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_EnableLimit", GenR_b2RevoluteJoint_EnableLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_EnableMotor", GenR_b2RevoluteJoint_EnableMotor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_EnableSpring", GenR_b2RevoluteJoint_EnableSpring, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_GetAngle", GenR_b2RevoluteJoint_GetAngle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_GetLowerLimit", GenR_b2RevoluteJoint_GetLowerLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_GetMaxMotorTorque", GenR_b2RevoluteJoint_GetMaxMotorTorque, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_GetMotorSpeed", GenR_b2RevoluteJoint_GetMotorSpeed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_GetMotorTorque", GenR_b2RevoluteJoint_GetMotorTorque, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_GetSpringDampingRatio", GenR_b2RevoluteJoint_GetSpringDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_GetSpringHertz", GenR_b2RevoluteJoint_GetSpringHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_GetTargetAngle", GenR_b2RevoluteJoint_GetTargetAngle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_GetUpperLimit", GenR_b2RevoluteJoint_GetUpperLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_IsLimitEnabled", GenR_b2RevoluteJoint_IsLimitEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_IsMotorEnabled", GenR_b2RevoluteJoint_IsMotorEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_IsSpringEnabled", GenR_b2RevoluteJoint_IsSpringEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_SetLimits", GenR_b2RevoluteJoint_SetLimits, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_SetMaxMotorTorque", GenR_b2RevoluteJoint_SetMaxMotorTorque, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_SetMotorSpeed", GenR_b2RevoluteJoint_SetMotorSpeed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_SetSpringDampingRatio", GenR_b2RevoluteJoint_SetSpringDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_SetSpringHertz", GenR_b2RevoluteJoint_SetSpringHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJoint_SetTargetAngle", GenR_b2RevoluteJoint_SetTargetAngle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SegmentDistance", GenR_b2SegmentDistance, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetLengthUnitsPerMeter", GenR_b2SetLengthUnitsPerMeter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShapeCast", GenR_b2ShapeCast, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShapeCastCapsule", GenR_b2ShapeCastCapsule, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShapeCastCircle", GenR_b2ShapeCastCircle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShapeCastPolygon", GenR_b2ShapeCastPolygon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShapeCastSegment", GenR_b2ShapeCastSegment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShapeDistance", GenR_b2ShapeDistance, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_AreContactEventsEnabled", GenR_b2Shape_AreContactEventsEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_AreHitEventsEnabled", GenR_b2Shape_AreHitEventsEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_ArePreSolveEventsEnabled", GenR_b2Shape_ArePreSolveEventsEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_AreSensorEventsEnabled", GenR_b2Shape_AreSensorEventsEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_EnableContactEvents", GenR_b2Shape_EnableContactEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_EnableHitEvents", GenR_b2Shape_EnableHitEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_EnablePreSolveEvents", GenR_b2Shape_EnablePreSolveEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_EnableSensorEvents", GenR_b2Shape_EnableSensorEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetAABB", GenR_b2Shape_GetAABB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetBody", GenR_b2Shape_GetBody, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetCapsule", GenR_b2Shape_GetCapsule, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetChainSegment", GenR_b2Shape_GetChainSegment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetCircle", GenR_b2Shape_GetCircle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetClosestPoint", GenR_b2Shape_GetClosestPoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetContactCapacity", GenR_b2Shape_GetContactCapacity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetContactData", GenR_b2Shape_GetContactData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetDensity", GenR_b2Shape_GetDensity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetFilter", GenR_b2Shape_GetFilter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetFriction", GenR_b2Shape_GetFriction, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetMassData", GenR_b2Shape_GetMassData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetMaterial", GenR_b2Shape_GetMaterial, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetParentChain", GenR_b2Shape_GetParentChain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetPolygon", GenR_b2Shape_GetPolygon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetRestitution", GenR_b2Shape_GetRestitution, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetSegment", GenR_b2Shape_GetSegment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetSensorCapacity", GenR_b2Shape_GetSensorCapacity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetSensorOverlaps", GenR_b2Shape_GetSensorOverlaps, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetSurfaceMaterial", GenR_b2Shape_GetSurfaceMaterial, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetType", GenR_b2Shape_GetType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_GetWorld", GenR_b2Shape_GetWorld, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_IsSensor", GenR_b2Shape_IsSensor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_IsValid", GenR_b2Shape_IsValid, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_RayCast", GenR_b2Shape_RayCast, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_SetCapsule", GenR_b2Shape_SetCapsule, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_SetCircle", GenR_b2Shape_SetCircle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_SetDensity", GenR_b2Shape_SetDensity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_SetFilter", GenR_b2Shape_SetFilter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_SetFriction", GenR_b2Shape_SetFriction, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_SetMaterial", GenR_b2Shape_SetMaterial, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_SetPolygon", GenR_b2Shape_SetPolygon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_SetRestitution", GenR_b2Shape_SetRestitution, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_SetSegment", GenR_b2Shape_SetSegment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_SetSurfaceMaterial", GenR_b2Shape_SetSurfaceMaterial, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Shape_TestPoint", GenR_b2Shape_TestPoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SolvePlanes", GenR_b2SolvePlanes, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TimeOfImpact", GenR_b2TimeOfImpact, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TransformPolygon", GenR_b2TransformPolygon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ValidateHull", GenR_b2ValidateHull, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJoint_GetAngularDampingRatio", GenR_b2WeldJoint_GetAngularDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJoint_GetAngularHertz", GenR_b2WeldJoint_GetAngularHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJoint_GetLinearDampingRatio", GenR_b2WeldJoint_GetLinearDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJoint_GetLinearHertz", GenR_b2WeldJoint_GetLinearHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJoint_SetAngularDampingRatio", GenR_b2WeldJoint_SetAngularDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJoint_SetAngularHertz", GenR_b2WeldJoint_SetAngularHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJoint_SetLinearDampingRatio", GenR_b2WeldJoint_SetLinearDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJoint_SetLinearHertz", GenR_b2WeldJoint_SetLinearHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_EnableLimit", GenR_b2WheelJoint_EnableLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_EnableMotor", GenR_b2WheelJoint_EnableMotor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_EnableSpring", GenR_b2WheelJoint_EnableSpring, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_GetLowerLimit", GenR_b2WheelJoint_GetLowerLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_GetMaxMotorTorque", GenR_b2WheelJoint_GetMaxMotorTorque, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_GetMotorSpeed", GenR_b2WheelJoint_GetMotorSpeed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_GetMotorTorque", GenR_b2WheelJoint_GetMotorTorque, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_GetSpringDampingRatio", GenR_b2WheelJoint_GetSpringDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_GetSpringHertz", GenR_b2WheelJoint_GetSpringHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_GetUpperLimit", GenR_b2WheelJoint_GetUpperLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_IsLimitEnabled", GenR_b2WheelJoint_IsLimitEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_IsMotorEnabled", GenR_b2WheelJoint_IsMotorEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_IsSpringEnabled", GenR_b2WheelJoint_IsSpringEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_SetLimits", GenR_b2WheelJoint_SetLimits, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_SetMaxMotorTorque", GenR_b2WheelJoint_SetMaxMotorTorque, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_SetMotorSpeed", GenR_b2WheelJoint_SetMotorSpeed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_SetSpringDampingRatio", GenR_b2WheelJoint_SetSpringDampingRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJoint_SetSpringHertz", GenR_b2WheelJoint_SetSpringHertz, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_CastMover", GenR_b2World_CastMover, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_CastRayClosest", GenR_b2World_CastRayClosest, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_Draw", GenR_b2World_Draw, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_DumpMemoryStats", GenR_b2World_DumpMemoryStats, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_EnableContinuous", GenR_b2World_EnableContinuous, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_EnableSleeping", GenR_b2World_EnableSleeping, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_EnableSpeculative", GenR_b2World_EnableSpeculative, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_EnableWarmStarting", GenR_b2World_EnableWarmStarting, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_Explode", GenR_b2World_Explode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_GetAwakeBodyCount", GenR_b2World_GetAwakeBodyCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_GetCounters", GenR_b2World_GetCounters, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_GetGravity", GenR_b2World_GetGravity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_GetHitEventThreshold", GenR_b2World_GetHitEventThreshold, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_GetMaximumLinearSpeed", GenR_b2World_GetMaximumLinearSpeed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_GetProfile", GenR_b2World_GetProfile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_GetRestitutionThreshold", GenR_b2World_GetRestitutionThreshold, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_IsContinuousEnabled", GenR_b2World_IsContinuousEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_IsSleepingEnabled", GenR_b2World_IsSleepingEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_IsValid", GenR_b2World_IsValid, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_IsWarmStartingEnabled", GenR_b2World_IsWarmStartingEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_RebuildStaticTree", GenR_b2World_RebuildStaticTree, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_SetContactTuning", GenR_b2World_SetContactTuning, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_SetGravity", GenR_b2World_SetGravity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_SetHitEventThreshold", GenR_b2World_SetHitEventThreshold, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_SetMaximumLinearSpeed", GenR_b2World_SetMaximumLinearSpeed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_SetRestitutionThreshold", GenR_b2World_SetRestitutionThreshold, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "World_Step", GenR_b2World_Step, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Yield", GenR_b2Yield, MRB_ARGS_ANY());
}
