/**
 * @file light.h
 * @brief Dynamic 2D lighting: day/night ambient, coloured lights, hard shadows.
 *
 * Original SDLStatic code (zlib), plain C over SDL3's renderer.
 *
 * Lighting is done on the GPU: when SDL's renderer is on OpenGL or OpenGL
 * ES, a fragment shader evaluates every light per pixel — smooth falloff,
 * cones, and shadows raymarched against the level's geometry. The GLSL is
 * compiled into the binary (see light/shaders/), so a game ships one
 * executable with no shader files beside it, and it is deliberately GLSL
 * 1.x so the same shader serves desktop GL, GLES and WebGL.
 *
 * Where there is no GL context — Metal, Direct3D, a software renderer in a
 * test — the same light map is built on the CPU from triangle fans
 * instead. The scene is lit either way; only the smoothness of the falloff
 * and the cost differ. SDLStatic_LightUsesShaders reports which path is
 * live.
 *
 * The model is the one 2D games have used for years: build a **light map**
 * (ambient colour, plus every light added on top), then multiply it over
 * the frame you already drew. Multiplying is what makes darkness dark —
 * an unlit pixel keeps its colour but loses its brightness, so a grey
 * floor at night reads as a dark grey floor rather than a black hole.
 *
 *     SDLStatic_LightBeginFrame(scene, camera_x, camera_y);
 *     SDLStatic_SetLightAmbient(scene, SDLStatic_DayNightAmbient(hour));
 *     SDLStatic_AddOccluderRect(scene, platform);      // walls block light
 *     SDLStatic_AddLight(scene, &torch);
 *     ... draw the world ...
 *     SDLStatic_RenderLighting(scene);                 // composite on top
 *
 * Lights and occluders are declared **every frame**, like immediate-mode
 * UI: there are no handles to keep in sync with your entities, and a light
 * that stops being submitted simply stops existing. The scene keeps only
 * what it needs to draw.
 *
 * Shadows are hard-edged by default, which is what a torch in a stone
 * corridor looks like; SDLStatic_SetLightShadowSoftness adds a penumbra on
 * the shader path.
 *
 * Everything is in **world coordinates**. The camera offset given to
 * SDLStatic_LightBeginFrame is applied when drawing, so a light attached
 * to an entity uses that entity's world position and nothing else.
 */
#ifndef SDLSTATIC_LIGHT_H
#define SDLSTATIC_LIGHT_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/** A lighting scene: the light map, and this frame's lights and occluders. */
typedef struct SDLStatic_LightScene SDLStatic_LightScene;

/** One light, submitted per frame.
 *
 *  Zero-initialise and fill in what you need: a light with `radius` and a
 *  `color` is already valid, and the rest has sensible zero behaviour
 *  (omnidirectional, no flicker, shadow casting on). */
typedef struct SDLStatic_Light
{
    float x, y;        /**< world position */
    float radius;      /**< how far it reaches, in world units */
    SDL_FColor color;  /**< rgb tint; `a` scales the brightness (1 = full) */
    float falloff;     /**< 0 or 1 linear, 2 quadratic — higher is tighter */
    float angle;       /**< direction in radians, for a cone */
    float spread;      /**< cone width in radians; <= 0 or >= 2*pi is omni */
    float flicker;     /**< 0 steady, 1 wild — torches want about 0.15 */
    Uint32 seed;       /**< makes two torches flicker differently */
    bool no_shadows;   /**< skip shadow casting for this light (cheaper) */
} SDLStatic_Light;

/* --- lifecycle ---------------------------------------------------------- */

/** Create a lighting scene for `renderer`.
 *
 *  The light map is allocated to match the renderer's output and follows
 *  it when the window resizes. Destroy with SDLStatic_DestroyLightScene. */
extern SDLStatic_LightScene *SDLStatic_CreateLightScene(SDL_Renderer *renderer);

extern void SDLStatic_DestroyLightScene(SDLStatic_LightScene *scene);

/* --- per frame ---------------------------------------------------------- */

/** Start a frame: drops last frame's lights and occluders and records the
 *  camera offset. Everything submitted afterwards is in world space; the
 *  camera is subtracted when the light map is drawn. */
extern void SDLStatic_LightBeginFrame(SDLStatic_LightScene *scene, float camera_x,
                                      float camera_y);

/** The colour an unlit pixel keeps. Black is a pitch-dark dungeon; a dim
 *  blue is moonlight; white is "no lighting at all".
 *
 *  This is a multiplier, so component values above 1 are allowed and
 *  brighten the scene — useful for a blazing noon. */
extern void SDLStatic_SetLightAmbient(SDLStatic_LightScene *scene, SDL_FColor ambient);

/** Add a light for this frame. Copies what it needs; the caller's struct
 *  can be a local. Returns false when the scene is full
 *  (SDLSTATIC_LIGHT_MAX per frame). */
extern bool SDLStatic_AddLight(SDLStatic_LightScene *scene, const SDLStatic_Light *light);

/** Darken a region of the world — the inside of a building, a cave, a
 *  cellar — to its own ambient colour, regardless of the time of day.
 *
 *  Ambient is one value for the whole scene, which is right for the sky
 *  and wrong for anywhere the sky cannot reach: at noon a dungeon would
 *  otherwise be as bright as the field above it. A dark zone replaces the
 *  ambient inside its rectangle, so a torch there is the only thing
 *  lighting it, while the world outside stays on the day/night cycle.
 *
 *  Lights are added on top afterwards, so a zone darkens the room without
 *  dimming the lamps in it. Zones are submitted per frame like everything
 *  else, and later zones overwrite earlier ones where they overlap. */
extern bool SDLStatic_AddDarkZone(SDLStatic_LightScene *scene, SDL_FRect rect,
                                  SDL_FColor ambient);

/** Add a solid rectangle that blocks light — a platform, a wall tile, a
 *  crate. Submitted in world coordinates, per frame, like lights. */
extern bool SDLStatic_AddOccluderRect(SDLStatic_LightScene *scene, SDL_FRect rect);

/** Add a single blocking edge, for geometry that is not a box: a sloped
 *  floor, a one-sided wall, the outline of a polygon. */
extern bool SDLStatic_AddOccluderSegment(SDLStatic_LightScene *scene, float x1, float y1,
                                         float x2, float y2);

/** Build the light map and multiply it over the current render target.
 *
 *  Call after drawing the world and before drawing anything that should
 *  stay unlit — a HUD, or a debug overlay. */
extern bool SDLStatic_RenderLighting(SDLStatic_LightScene *scene);

/* --- gameplay ----------------------------------------------------------- */

/** How lit a world point is, from 0 (pitch dark) to 1 (fully lit).
 *
 *  Computed on the CPU from the same lights and occluders — including
 *  shadows — rather than by reading pixels back, so it is cheap enough to
 *  call for every enemy every frame. This is the hook for the mechanics
 *  that make lighting matter: whether a guard can see the player, whether
 *  a torch gives away their position, whether something lurking in the
 *  dark stays hidden.
 *
 *  Only meaningful between SDLStatic_LightBeginFrame and the end of the
 *  frame, since that is when the lights exist. */
extern float SDLStatic_SampleLight(SDLStatic_LightScene *scene, float x, float y);

/** Is there a clear line between two world points — nothing blocking?
 *
 *  The same ray test the shadows use, exposed because line of sight is the
 *  other half of most stealth and enemy-awareness code. */
extern bool SDLStatic_LightLineOfSight(SDLStatic_LightScene *scene, float x1, float y1,
                                       float x2, float y2);

/* --- time of day -------------------------------------------------------- */

/** Ambient colour for a time of day, `hours` in [0, 24).
 *
 *  A ready-made cycle: deep blue night, warm low sun at dawn, bright
 *  neutral noon, orange dusk, back to night. Meant to be good enough to
 *  ship with and easy to abandon — it is a pure function returning a
 *  colour, so a game with its own art direction can ignore it and call
 *  SDLStatic_SetLightAmbient with anything.
 *
 *  Hours outside the range wrap, so a clock can just keep counting. */
extern SDL_FColor SDLStatic_DayNightAmbient(float hours);

/** How bright the sun is at `hours`, from 0 at night to 1 at midday.
 *
 *  Useful for the things that follow the sun without being the ambient
 *  colour: whether torches should be lit, how loud the crickets are. */
extern float SDLStatic_DayNightSunlight(float hours);

/* --- tuning ------------------------------------------------------------- */

/** Most lights and occluders accepted per frame. */
#define SDLSTATIC_LIGHT_MAX 64
#define SDLSTATIC_LIGHT_OCCLUDER_MAX 512
#define SDLSTATIC_LIGHT_ZONE_MAX 32

/** Is the shader path in use?
 *
 *  True when SDL's renderer is on OpenGL or OpenGL ES and the light shader
 *  compiled, in which case the light map is produced per pixel by the GPU.
 *  False on Metal, Direct3D, a software renderer, or if the driver refused
 *  the program — the geometry path then builds the same light map on the
 *  CPU, so the scene is lit either way and only the quality of the falloff
 *  and the cost differ. */
extern bool SDLStatic_LightUsesShaders(SDLStatic_LightScene *scene);

/** Force the geometry path even where shaders are available — for
 *  comparing the two, or for a machine where the GPU path misbehaves. */
extern void SDLStatic_SetLightUseShaders(SDLStatic_LightScene *scene, bool enabled);

/** Resolution of the light map relative to the window, in (0.1, 1].
 *
 *  Lighting is low-frequency, so half resolution (0.5) is close to free
 *  visually and quarters the shader's work — the first dial to reach for
 *  on mobile or the web. Clamped, and the targets are rebuilt on change. */
extern void SDLStatic_SetLightMapScale(SDLStatic_LightScene *scene, float scale);

/** Soften shadow edges, 0 (hard, the default) to 1.
 *
 *  Shader path only: it weights each blocked sample by how far along the
 *  ray it was, which reads as a penumbra that grows with distance from the
 *  occluder. The geometry path's shadows are always hard. */
extern void SDLStatic_SetLightShadowSoftness(SDLStatic_LightScene *scene, float softness);

/** Rays cast per shadow-casting light (default 96).
 *
 *  Geometry path only — the shader evaluates every pixel and has no ray
 *  count. This is that path's cost/quality dial: more rays means smoother
 *  shadow edges
 *  around curved arrangements of occluders and a rounder light circle.
 *  Corners are always sampled exactly regardless, so straight-edged
 *  shadows stay sharp even at low counts. Clamped to [16, 512]. */
extern void SDLStatic_SetLightRayCount(SDLStatic_LightScene *scene, int rays);

/** Concentric rings of geometry per light (default 3, clamped [1, 8]).
 *
 *  Falloff is interpolated between ring vertices, so one ring gives a
 *  linear ramp and more rings follow the falloff curve properly. Raise it
 *  if a large light looks banded; lower it to save vertices. */
extern void SDLStatic_SetLightRings(SDLStatic_LightScene *scene, int rings);

/** Draw the occluder edges and light centres over the frame, for working
 *  out why a shadow is where it is. */
extern void SDLStatic_SetLightDebugDraw(SDLStatic_LightScene *scene, bool enabled);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_LIGHT_H */
