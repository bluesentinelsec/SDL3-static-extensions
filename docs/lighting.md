---
title: Lighting
description: "Dynamic 2D lighting — day/night ambient, coloured lights, hard shadows — on the GPU via embedded GLSL, with a CPU fallback."
---

# Lighting — `SDLStatic::Light`

Dynamic 2D lighting for a game that has to look different at dawn, at noon
and in a cave lit by one guttering torch.

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Light)
```

Lighting runs on the GPU. When SDL's renderer is on OpenGL or OpenGL ES, a
fragment shader evaluates every light per pixel — smooth falloff, cones,
and shadows raymarched against the level's geometry. The GLSL is **compiled
into the binary** (`light/shaders/*`, embedded by `scripts/embed_shaders.py`
into `light/src/light_shaders.h`), so a game ships one executable with no
shader files beside it.

The shaders are deliberately GLSL 1.x — `#version 120` on desktop, `#version
100` on ES — because SDL's OpenGL renderer creates a 2.1-era context on
macOS and a WebGL context on the web. One shader serves desktop, mobile and
browser. Where there is no GL context at all (Metal, Direct3D, a software
renderer in a test) the same light map is built on the CPU instead;
`SDLStatic_LightUsesShaders` says which path is live.

## The model

Build a **light map** — the ambient colour, plus every light added on top —
then multiply it over the frame you already drew:

```c
SDLStatic_LightBeginFrame(scene, camera_x, camera_y);
SDLStatic_SetLightAmbient(scene, SDLStatic_DayNightAmbient(hour));
SDLStatic_AddDarkZone(scene, cave_interior, black);   // rooms the sky misses
SDLStatic_AddOccluderRect(scene, platform);           // walls block light
SDLStatic_AddLight(scene, &torch);

DrawTheWorld();
SDLStatic_RenderLighting(scene);   // composite
DrawTheHud();                      // after lighting: a HUD is never in shadow
```

Lights and occluders are submitted **every frame**, like immediate-mode UI.
There are no handles to keep in sync with your entities, and a light that
stops being submitted stops existing. Everything is in world coordinates;
the camera offset is applied when the map is drawn.

### Two things that will surprise you

**A light map multiplies, so it can only darken.** A surface drawn at 20%
grey cannot be made bright by any light — the most a light can do is
restore it to 20% grey. Paint your world in the colours it should have when
*fully lit*, let the ambient darken it, and give bright sources an
intensity above 1 (`color.a = 1.9f`) so they can lift a dark room back up.

**Light is only visible where it lands on a surface.** There is no
participating medium: an empty black background stays black no matter how
many torches are near it. Interiors need a backdrop — background tiles, a
wall — or the torches will appear to light nothing but the platform edges.

## Lights

```c
SDLStatic_Light torch = {0};
torch.x = 1020.0f;
torch.y = 380.0f;
torch.radius = 320.0f;
torch.color = (SDL_FColor){1.0f, 0.62f, 0.28f, 1.9f}; // a = intensity
torch.falloff = 1.6f;    // 1 linear, 2 lantern-like, 4 candle-like
torch.flicker = 0.18f;   // torches want about 0.15
torch.seed = 977;        // so two torches never pulse together
SDLStatic_AddLight(scene, &torch);
```

Set `angle` and `spread` for a cone — a lantern, a searchlight, a guard's
field of view. Set `no_shadows` for a glow that should not be blocked
(a magic aura, an enemy's eyes): it is also cheaper.

## Shadows

Occluders are the level's solid geometry, submitted per frame:

```c
SDLStatic_AddOccluderRect(scene, (SDL_FRect){900, 700, 1500, 200});
SDLStatic_AddOccluderSegment(scene, x1, y1, x2, y2);  // a slope, a rail
```

On the shader path they are rasterised into a small occluder mask and each
light's rays are marched against it, so the cost does not grow with the
number of walls — which is what makes a dungeon built from hundreds of
tiles affordable. Shadows are hard-edged by default;
`SDLStatic_SetLightShadowSoftness` adds a penumbra that widens with
distance from the occluder.

A surface facing a light is lit rather than shadowed by itself: the march
stops short of its target, or every wall the light shines on would come out
black with a hairline edge.

## Day and night

```c
SDLStatic_SetLightAmbient(scene, SDLStatic_DayNightAmbient(hours));
const float sun = SDLStatic_DayNightSunlight(hours);  // 0 at night, 1 at noon
```

A ready-made cycle: deep blue night, warm low sun at dawn, bright neutral
noon, orange dusk. `hours` wraps, so a clock can just keep counting. It is
a pure function returning a colour — a game with its own art direction can
ignore it entirely.

Ambient is one value for the whole scene, which is right for the sky and
wrong for anywhere the sky cannot reach. `SDLStatic_AddDarkZone` replaces
the ambient inside a rectangle, so a dungeon stays dark at noon while the
field above it does not.

## Lighting as a game mechanic

The point of dynamic lighting in a game is rarely just how it looks:

```c
const float exposure = SDLStatic_SampleLight(scene, player_x, player_y);
const bool seen = SDLStatic_LightLineOfSight(scene, guard_x, guard_y,
                                             player_x, player_y);
if (seen && exposure > 0.22f) { alert(guard); }
```

`SDLStatic_SampleLight` answers how lit a world point is, from 0 to 1,
including shadows and dark zones. It is computed on the CPU from the same
data the renderer uses — not by reading pixels back — so it is cheap enough
to call for every enemy every frame, and it gives the same answer on every
backend. Carrying a torch to see in the dark then costs the player
something, which is the trade that makes the mechanic interesting.

## Performance

| Dial | What it does |
|---|---|
| `SDLStatic_SetLightMapScale(scene, 0.5f)` | Light map at half resolution. Lighting is low frequency, so this is close to free visually and quarters the shader's work — the first thing to reach for on mobile or the web. |
| `no_shadows` per light | Skips the raymarch for that light entirely. |
| `SDLStatic_SetLightRayCount` / `SetLightRings` | Geometry path only — its cost/quality dial. The shader has no ray count. |

Up to `SDLSTATIC_LIGHT_MAX` (64) lights and `SDLSTATIC_LIGHT_OCCLUDER_MAX`
(512) occluder edges per frame; the shader evaluates the first 16 lights per
pass. Limits are reported rather than silently dropping work.

## From Lua, Ruby and C++

The whole surface is generated, so it is available in every language:

```lua
local scene = SDLStaticC.CreateLightScene(renderer)
SDLStaticC.LightBeginFrame(scene, camera_x, camera_y)
SDLStaticC.SetLightAmbient(scene, SDLStaticC.DayNightAmbient(hours))
SDLStaticC.AddLight(scene, {x = 100, y = 200, radius = 300,
                            color = {r = 1, g = 0.6, b = 0.3, a = 1.8}})
SDLStaticC.RenderLighting(scene)
```
