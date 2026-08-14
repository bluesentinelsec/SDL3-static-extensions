---
title: Physics
description: "Box2D v3 rigid-body physics, pure C11, statically built for every platform including WebAssembly, with a one-call debug-draw overlay."
---

# Physics — `SDLStatic::Physics`

Box2D v3.1.1 — Erin Catto's canonical 2D physics engine, rewritten in
pure C11 for v3. Zero external dependencies, SIMD with scalar fallback,
works on every platform including web. The full native `b2*` API ships
unchanged.

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

## Debug-draw overlay (original extension)

`<SDLStatic/physics_draw.h>` renders a world's collision shapes through
the [Gfx](gfx.html) GPU primitives — batched draws, meters-to-pixels
mapping with y flipped:

```c
SDLStatic_PhysicsDrawConfig cfg = {
    .pixels_per_meter = 32.0f,
    .offset_x = 640.0f, .offset_y = 600.0f,
};
SDLStatic_DrawPhysicsWorld(world, renderer, &cfg);
```

Tests assert simulation against analytical expectations — resting
heights, stable stacks, raycast hit points, joint lengths, contact
events — and verify that two identical worlds evolve **bit-identically**
(Box2D v3's determinism guarantee).

C++ users get RAII `PhysicsWorld`/`PhysicsBody` owners; Lua and Ruby get
the full `B2.*` module — see [C++](cpp.html) and
[Scripting](scripting.html).

Provenance:
[`deps/box2d.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/box2d.md).
