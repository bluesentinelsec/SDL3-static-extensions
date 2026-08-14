/**
 * @file physics_test.cpp
 * @brief Tests for SDLStatic::Physics — vendored Box2D v3 + debug-draw glue.
 *
 * Simulation correctness is asserted against analytical expectations: a
 * dropped box must come to rest exactly at its half-extent above the
 * ground, raycasts must hit at computed points, joints must hold their
 * constraints, and two identical worlds must evolve bit-identically
 * (Box2D v3's determinism promise). The debug-draw glue is verified with
 * pixel readback through a software renderer.
 */

#include <SDL3/SDL.h>
#include <SDLStatic/physics_draw.h>
#include <box2d/box2d.h>
#include <gtest/gtest.h>

#include <cstring>
#include <vector>

namespace
{

constexpr float kDt = 1.0f / 60.0f;
constexpr int kSubsteps = 4;

class PhysicsWorld : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        b2WorldDef def = b2DefaultWorldDef();
        def.gravity = {0.0f, -10.0f};
        world_ = b2CreateWorld(&def);
        ASSERT_TRUE(b2World_IsValid(world_));
    }
    void TearDown() override
    {
        if (b2World_IsValid(world_))
        {
            b2DestroyWorld(world_);
        }
    }

    b2BodyId AddGround()
    {
        b2BodyDef def = b2DefaultBodyDef();
        def.position = {0.0f, 0.0f};
        b2BodyId ground = b2CreateBody(world_, &def);
        const b2Segment segment = {{-50.0f, 0.0f}, {50.0f, 0.0f}};
        b2ShapeDef shape = b2DefaultShapeDef();
        b2CreateSegmentShape(ground, &shape, &segment);
        return ground;
    }

    b2BodyId AddBox(float x, float y, float half = 0.5f)
    {
        b2BodyDef def = b2DefaultBodyDef();
        def.type = b2_dynamicBody;
        def.position = {x, y};
        b2BodyId body = b2CreateBody(world_, &def);
        const b2Polygon box = b2MakeBox(half, half);
        b2ShapeDef shape = b2DefaultShapeDef();
        b2CreatePolygonShape(body, &shape, &box);
        return body;
    }

    void Step(int count)
    {
        for (int i = 0; i < count; ++i)
        {
            b2World_Step(world_, kDt, kSubsteps);
        }
    }

    b2WorldId world_ = b2_nullWorldId;
};

TEST_F(PhysicsWorld, DroppedBoxComesToRestAtHalfExtent)
{
    AddGround();
    const b2BodyId box = AddBox(0.0f, 5.0f);

    Step(300);

    const b2Vec2 pos = b2Body_GetPosition(box);
    const b2Vec2 vel = b2Body_GetLinearVelocity(box);
    EXPECT_NEAR(pos.y, 0.5f, 0.02f) << "resting height must equal the half-extent";
    EXPECT_NEAR(pos.x, 0.0f, 0.01f) << "no lateral drift";
    EXPECT_NEAR(vel.x, 0.0f, 0.01f);
    EXPECT_NEAR(vel.y, 0.0f, 0.01f);
    EXPECT_FALSE(b2Body_IsAwake(box)) << "resting bodies must fall asleep";
}

TEST_F(PhysicsWorld, StackOfBoxesStaysStanding)
{
    AddGround();
    std::vector<b2BodyId> stack;
    for (int i = 0; i < 5; ++i)
    {
        stack.push_back(AddBox(0.0f, 0.5f + 1.0f * static_cast<float>(i) + 0.01f));
    }

    Step(400);

    for (int i = 0; i < 5; ++i)
    {
        const b2Vec2 pos = b2Body_GetPosition(stack[static_cast<size_t>(i)]);
        EXPECT_NEAR(pos.y, 0.5f + 1.0f * static_cast<float>(i), 0.05f) << "box " << i;
        EXPECT_NEAR(pos.x, 0.0f, 0.2f) << "box " << i << " toppled";
    }
}

TEST_F(PhysicsWorld, RaycastHitsCircleAtComputedPoint)
{
    b2BodyDef def = b2DefaultBodyDef();
    def.position = {0.0f, 0.0f};
    b2BodyId body = b2CreateBody(world_, &def);
    const b2Circle circle = {{0.0f, 0.0f}, 1.0f};
    b2ShapeDef shape = b2DefaultShapeDef();
    b2CreateCircleShape(body, &shape, &circle);

    const b2RayResult hit =
        b2World_CastRayClosest(world_, {-5.0f, 0.0f}, {10.0f, 0.0f}, b2DefaultQueryFilter());
    ASSERT_TRUE(b2Shape_IsValid(hit.shapeId)) << "ray must hit the circle";
    EXPECT_NEAR(hit.point.x, -1.0f, 1e-3f);
    EXPECT_NEAR(hit.point.y, 0.0f, 1e-3f);
    EXPECT_NEAR(hit.normal.x, -1.0f, 1e-3f);
    EXPECT_NEAR(hit.fraction, 0.4f, 1e-3f) << "4 of 10 units traveled";

    const b2RayResult miss =
        b2World_CastRayClosest(world_, {-5.0f, 5.0f}, {10.0f, 0.0f}, b2DefaultQueryFilter());
    EXPECT_FALSE(b2Shape_IsValid(miss.shapeId));
}

TEST_F(PhysicsWorld, DistanceJointHoldsLengthUnderGravity)
{
    b2BodyDef anchor_def = b2DefaultBodyDef();
    anchor_def.position = {0.0f, 10.0f};
    b2BodyId anchor = b2CreateBody(world_, &anchor_def);

    const b2BodyId bob = AddBox(0.0f, 8.0f, 0.25f);

    b2DistanceJointDef joint = b2DefaultDistanceJointDef();
    joint.bodyIdA = anchor;
    joint.bodyIdB = bob;
    joint.localAnchorA = {0.0f, 0.0f};
    joint.localAnchorB = {0.0f, 0.0f};
    joint.length = 2.0f;
    b2CreateDistanceJoint(world_, &joint);

    Step(240);

    const b2Vec2 pos = b2Body_GetPosition(bob);
    const float dx = pos.x - 0.0f;
    const float dy = pos.y - 10.0f;
    const float length = SDL_sqrtf(dx * dx + dy * dy);
    EXPECT_NEAR(length, 2.0f, 0.05f) << "joint must hold its length";
    EXPECT_NEAR(pos.y, 8.0f, 0.1f) << "bob should hang straight down";
}

TEST_F(PhysicsWorld, SensorAndContactEventsFire)
{
    AddGround();

    // A static sensor region above the ground.
    b2BodyDef sensor_def = b2DefaultBodyDef();
    sensor_def.position = {0.0f, 2.0f};
    b2BodyId sensor_body = b2CreateBody(world_, &sensor_def);
    const b2Polygon region = b2MakeBox(1.0f, 1.0f);
    b2ShapeDef sensor_shape = b2DefaultShapeDef();
    sensor_shape.isSensor = true;
    sensor_shape.enableSensorEvents = true;
    b2ShapeId sensor_id = b2CreatePolygonShape(sensor_body, &sensor_shape, &region);

    // A box falling through the sensor onto the ground.
    b2BodyDef box_def = b2DefaultBodyDef();
    box_def.type = b2_dynamicBody;
    box_def.position = {0.0f, 5.0f};
    b2BodyId box = b2CreateBody(world_, &box_def);
    const b2Polygon box_poly = b2MakeBox(0.5f, 0.5f);
    b2ShapeDef box_shape = b2DefaultShapeDef();
    box_shape.enableSensorEvents = true;
    box_shape.enableContactEvents = true;
    b2CreatePolygonShape(box, &box_shape, &box_poly);

    bool sensor_begin = false;
    bool contact_begin = false;
    for (int i = 0; i < 300; ++i)
    {
        b2World_Step(world_, kDt, kSubsteps);
        const b2SensorEvents sensor_events = b2World_GetSensorEvents(world_);
        for (int e = 0; e < sensor_events.beginCount; ++e)
        {
            if (B2_ID_EQUALS(sensor_events.beginEvents[e].sensorShapeId, sensor_id))
            {
                sensor_begin = true;
            }
        }
        const b2ContactEvents contact_events = b2World_GetContactEvents(world_);
        if (contact_events.beginCount > 0)
        {
            contact_begin = true;
        }
    }
    EXPECT_TRUE(sensor_begin) << "falling box must trigger the sensor";
    EXPECT_TRUE(contact_begin) << "landing must produce a contact event";
}

TEST_F(PhysicsWorld, IdenticalWorldsEvolveBitIdentically)
{
    // Build a second world with the same contents, step both identically,
    // and require bit-identical transforms (Box2D v3 determinism).
    b2WorldDef def = b2DefaultWorldDef();
    def.gravity = {0.0f, -10.0f};
    b2WorldId other = b2CreateWorld(&def);

    b2BodyId bodies_a[8];
    b2BodyId bodies_b[8];
    for (b2WorldId w : {world_, other})
    {
        b2BodyDef ground_def = b2DefaultBodyDef();
        b2BodyId ground = b2CreateBody(w, &ground_def);
        const b2Segment segment = {{-50.0f, 0.0f}, {50.0f, 0.0f}};
        b2ShapeDef gshape = b2DefaultShapeDef();
        b2CreateSegmentShape(ground, &gshape, &segment);
    }
    for (int i = 0; i < 8; ++i)
    {
        const float x = -3.5f + static_cast<float>(i);
        const float y = 3.0f + 0.6f * static_cast<float>(i % 3);
        for (int w = 0; w < 2; ++w)
        {
            b2BodyDef bdef = b2DefaultBodyDef();
            bdef.type = b2_dynamicBody;
            bdef.position = {x, y};
            bdef.rotation = b2MakeRot(0.1f * static_cast<float>(i));
            b2BodyId body = b2CreateBody(w == 0 ? world_ : other, &bdef);
            const b2Polygon poly = b2MakeBox(0.3f, 0.4f);
            b2ShapeDef shape = b2DefaultShapeDef();
            b2CreatePolygonShape(body, &shape, &poly);
            (w == 0 ? bodies_a : bodies_b)[i] = body;
        }
    }

    for (int step = 0; step < 180; ++step)
    {
        b2World_Step(world_, kDt, kSubsteps);
        b2World_Step(other, kDt, kSubsteps);
    }
    for (int i = 0; i < 8; ++i)
    {
        const b2Transform ta = b2Body_GetTransform(bodies_a[i]);
        const b2Transform tb = b2Body_GetTransform(bodies_b[i]);
        EXPECT_EQ(std::memcmp(&ta, &tb, sizeof(b2Transform)), 0) << "body " << i << " diverged";
    }
    b2DestroyWorld(other);
}

TEST_F(PhysicsWorld, InvalidIdsAreRejectedNotCrashing)
{
    EXPECT_FALSE(b2Body_IsValid(b2_nullBodyId));
    EXPECT_FALSE(b2Shape_IsValid(b2_nullShapeId));
    EXPECT_FALSE(b2Joint_IsValid(b2_nullJointId));
    EXPECT_FALSE(b2World_IsValid(b2_nullWorldId));
}

TEST_F(PhysicsWorld, DebugDrawRendersShapesThroughGpuPrimitives)
{
    ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
    SDL_Surface *surface = SDL_CreateSurface(200, 200, SDL_PIXELFORMAT_ARGB8888);
    ASSERT_NE(surface, nullptr);
    SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(surface);
    ASSERT_NE(renderer, nullptr) << SDL_GetError();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    AddGround();
    AddBox(0.0f, 0.5f); // resting on the ground at the origin
    Step(10);

    SDLStatic_PhysicsDrawConfig config = {};
    config.pixels_per_meter = 20.0f;
    config.offset_x = 100.0f; // world origin at screen center
    config.offset_y = 150.0f;
    ASSERT_TRUE(SDLStatic_DrawPhysicsWorld(world_, renderer, &config)) << SDL_GetError();
    SDL_FlushRenderer(renderer);

    // The box occupies world (-0.5..0.5, 0..1) -> screen (90..110, 130..150).
    Uint8 r = 0, g = 0, b = 0, a = 0;
    SDL_ReadSurfacePixel(surface, 100, 140, &r, &g, &b, &a);
    EXPECT_NE(r | g | b, 0) << "box interior must be drawn";
    SDL_ReadSurfacePixel(surface, 100, 40, &r, &g, &b, &a);
    EXPECT_EQ(r | g | b, 0) << "empty sky must stay empty";

    // Bad input paths.
    EXPECT_FALSE(SDLStatic_DrawPhysicsWorld(world_, nullptr, &config));
    EXPECT_FALSE(SDLStatic_DrawPhysicsWorld(b2_nullWorldId, renderer, &config));

    SDL_DestroyRenderer(renderer);
    SDL_DestroySurface(surface);
    SDL_Quit();
}

} // namespace
