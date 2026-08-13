# SDLStatic::Physics

A static-link-first build of [Box2D](https://github.com/erincatto/box2d)
v3.1.1 — Erin Catto's canonical 2D physics engine, rewritten in pure C11
for v3. Zero external dependencies, SIMD with scalar fallback, works on
every platform including web. The full native `b2*` API ships unchanged.

Provenance: [`deps/box2d.md`](../deps/box2d.md).

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Physics)
```

```c
#include <box2d/box2d.h>

b2WorldDef world_def = b2DefaultWorldDef();
world_def.gravity = (b2Vec2){0.0f, -10.0f};
b2WorldId world = b2CreateWorld(&world_def);

b2BodyDef body_def = b2DefaultBodyDef();
body_def.type = b2_dynamicBody;
body_def.position = (b2Vec2){0.0f, 4.0f};
b2BodyId player = b2CreateBody(world, &body_def);
b2Polygon box = b2MakeBox(0.5f, 0.5f);
b2ShapeDef shape_def = b2DefaultShapeDef();
b2CreatePolygonShape(player, &shape_def, &box);

b2World_Step(world, 1.0f / 60.0f, 4);   /* each frame */
```

## Debug-draw overlay (SDLStatic extension)

Original glue in `<SDLStatic/physics_draw.h>` renders a world's collision
shapes through the SDLStatic::Gfx GPU primitives — one call, batched
`SDL_RenderGeometry` draws, meters-to-pixels mapping with y flipped:

```c
SDLStatic_PhysicsDrawConfig cfg = {
    .pixels_per_meter = 32.0f,
    .offset_x = 640.0f, .offset_y = 600.0f,
};
SDLStatic_DrawPhysicsWorld(world, renderer, &cfg);
```

Tests (`tests/physics/`) assert simulation against analytical
expectations: a dropped box rests exactly at its half-extent and falls
asleep, stacks stay standing, raycasts hit at computed points and
fractions, distance joints hold length under gravity, sensor/contact
events fire, two identical worlds evolve **bit-identically** (Box2D v3's
determinism), and the debug overlay is verified by pixel readback. Plus
the standard link audit.
