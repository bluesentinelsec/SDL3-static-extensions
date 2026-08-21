/**
 * @file engine_light.h
 * @brief Scene lighting: presets, a clock, and lights that ride on actors.
 *
 * Original SDLStatic code (zlib), over SDLStatic::Light.
 *
 * The lighting module already knows how to light a scene. What it does not
 * know is where the camera is, which actors moved this frame, or what the
 * player set the quality slider to — and wiring those up by hand, every
 * frame, in every game, is exactly the sort of bookkeeping an engine is
 * for. So:
 *
 *     SDLStatic_LightSetPreset(engine, SDLSTATIC_LIGHT_NIGHT);
 *
 *     SDLStatic_LightDef torch = SDLStatic_LightDefault();
 *     torch.radius = 380.0f;
 *     torch.color = (SDL_FColor){1.0f, 0.72f, 0.36f, 1.0f};
 *     torch.flicker = 0.15f;
 *     SDLStatic_ActorAddLight(actor, &torch);
 *
 *     // in the render hook, after drawing the world
 *     SDLStatic_LightRender(engine, &camera, alpha);
 *
 * and the light follows the actor for the rest of its life, including
 * through a parent's transform, and disappears when the actor does.
 *
 * ### Lights are drawn interpolated, like everything else
 *
 * An actor's light is submitted at `SDLStatic_ActorRenderTransform`, the
 * same place its sprite is drawn. If it were submitted at the simulation
 * position instead, a torch would lag its own flame by up to one tick — a
 * shimmer that is maddening to look at and very hard to attribute.
 *
 * ### The quality budget is honoured for you
 *
 * `dynamic_lights` and `shadows` from engine_graphics.h decide the light
 * map resolution, the ray count, the softness, and how many lights are
 * submitted at all. A player who turns lighting off gets ambient only, at
 * no cost, without the game writing a single conditional.
 */
#ifndef SDLSTATIC_ENGINE_LIGHT_H
#define SDLSTATIC_ENGINE_LIGHT_H

#include <SDLStatic/engine_actor.h>
#include <SDLStatic/engine_camera.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * A scene's lighting mood.
 *
 * These are the five you asked for plus an off switch, and they are
 * deliberately coarse: a preset is a starting point a designer picks in
 * five seconds, not a colour grading system. Anything more specific is a
 * custom ambient, which is one call away.
 */
typedef enum SDLStatic_LightPreset
{
    /** No lighting at all: the world draws at full brightness. The right
     *  choice for a menu, and for a game that does not want lighting —
     *  costs nothing, because nothing is rendered. */
    SDLSTATIC_LIGHT_NONE = 0,
    SDLSTATIC_LIGHT_SUNRISE,   /**< low warm sun, long shadows */
    SDLSTATIC_LIGHT_AFTERNOON, /**< bright and neutral; the safe default */
    SDLSTATIC_LIGHT_SUNSET,    /**< orange, dimming */
    SDLSTATIC_LIGHT_NIGHT,     /**< deep blue; torches carry the scene */
    /** Near-black. A cave or a dungeon interior, where the only light is
     *  the one the player brought with them. */
    SDLSTATIC_LIGHT_DARK
} SDLStatic_LightPreset;

/** Apply a preset. Sets the ambient colour and the time of day to match,
 *  so a game that later starts the clock carries on from the right hour. */
extern void SDLStatic_LightSetPreset(SDLStatic_Engine *engine, SDLStatic_LightPreset preset);
extern SDLStatic_LightPreset SDLStatic_LightPreset_(SDLStatic_Engine *engine);

/** Override the ambient directly, for a game with its own art direction.
 *  Doing so puts the preset into a custom state, and stops the clock from
 *  overwriting it. */
extern void SDLStatic_LightSetAmbient(SDLStatic_Engine *engine, SDL_FColor ambient);
extern SDL_FColor SDLStatic_LightAmbient(SDLStatic_Engine *engine);

/* --- the clock ----------------------------------------------------------- */

/**
 * Run a day/night cycle.
 *
 * `hours_per_second` is how fast the clock runs: 0 stops it, and 0.05 gives
 * a twenty-minute day, which is about right for a game where the cycle is
 * scenery rather than a mechanic. The ambient colour follows the hour
 * automatically.
 *
 * Setting a custom ambient stops the clock driving it, because a game that
 * has said what colour it wants should not have it quietly overwritten a
 * frame later.
 */
extern void SDLStatic_LightSetClock(SDLStatic_Engine *engine, float hours,
                                    float hours_per_second);

/** The current hour, 0..24. */
extern float SDLStatic_LightHour(SDLStatic_Engine *engine);

/** How bright the sun is now, 0 at night to 1 at midday — for the things
 *  that follow the sun without being the ambient: whether the streetlights
 *  are on, whether the torches should be lit. */
extern float SDLStatic_LightSunlight(SDLStatic_Engine *engine);

/* --- lights on actors ---------------------------------------------------- */

/**
 * A light attached to an actor. Copied on attach.
 *
 * Position comes from the actor, so there is nothing to keep in sync —
 * which is the entire reason this lives on an actor rather than being
 * submitted by hand.
 */
typedef struct SDLStatic_LightDef
{
    float radius; /**< in design units; 200 if left at zero */
    SDL_FColor color;
    /** Offset from the actor's position, so a torch can be at the end of an
     *  arm rather than in the middle of a chest. */
    float offset_x, offset_y;

    float falloff; /**< 0 or 1 linear, 2 quadratic — higher is tighter */
    /** Cone direction in degrees and width in degrees. A width of 0 or 360
     *  is omnidirectional. The cone rotates with the actor, so a torch held
     *  by a turning character sweeps the room. */
    float cone_direction, cone_width;
    float flicker; /**< 0 steady, 1 wild; a torch wants about 0.15 */
    bool no_shadows;
    bool enabled;
} SDLStatic_LightDef;

/** A light with usable defaults: warm white, 200 units, steady, casting
 *  shadows. A zeroed struct would be a black light with no radius. */
extern SDLStatic_LightDef SDLStatic_LightDefault(void);

/** Attach a light to an actor, replacing any it had. */
extern bool SDLStatic_ActorAddLight(SDLStatic_Actor *actor, const SDLStatic_LightDef *light);

/** The actor's light, to read or change in place — for a torch that dims
 *  as it burns down. NULL if it has none. */
extern SDLStatic_LightDef *SDLStatic_ActorLight(SDLStatic_Actor *actor);

extern void SDLStatic_ActorRemoveLight(SDLStatic_Actor *actor);

/* --- occluders ----------------------------------------------------------- */

/**
 * Walls, for this frame.
 *
 * Occluders are submitted per frame rather than kept, because the set that
 * matters is the set near the camera, and a level's geometry is the game's
 * to iterate. Call these any time during the frame, before
 * SDLStatic_LightRender — they are buffered until then, so there is no
 * window in which one of these silently does nothing.
 *
 * Actors with a **static physics body** are submitted for you when
 * `SDLStatic_LightSetAutoOccluders` is on, which covers the common case of
 * "the level's collision is also what blocks light".
 */
extern void SDLStatic_LightAddOccluder(SDLStatic_Engine *engine, SDL_FRect wall);
extern void SDLStatic_LightAddOccluderLine(SDLStatic_Engine *engine, float x1, float y1,
                                           float x2, float y2);

/** Submit every static physics body as an occluder. On by default: the
 *  level's collision is usually exactly what should block light, and a
 *  game that disagrees can turn it off and submit its own. */
extern void SDLStatic_LightSetAutoOccluders(SDLStatic_Engine *engine, bool enabled);

/** A rectangle that is darker than the ambient — the inside of a building
 *  seen from outside, a cave mouth. Submitted per frame like occluders. */
extern void SDLStatic_LightAddDarkZone(SDLStatic_Engine *engine, SDL_FRect area,
                                       SDL_FColor ambient);

/* --- drawing ------------------------------------------------------------- */

/**
 * Composite the lighting over the frame.
 *
 * Call **after** drawing the world and **before** the HUD: lighting
 * multiplies over what is already there, so anything drawn afterwards is
 * unlit — which is what a HUD wants and what the world does not.
 *
 * Does nothing when the preset is NONE or the player has turned dynamic
 * lights off, so a game may call it unconditionally.
 *
 * Returns false if lighting could not be rendered, which a game may ignore.
 */
extern bool SDLStatic_LightRender(SDLStatic_Engine *engine, const SDLStatic_Camera *camera,
                                  float alpha);

/** How much light reaches a world point, 0..1 — for gameplay that depends
 *  on it: whether a guard can see the player, whether a plant grows. Reads
 *  the map rendered last frame, so it is cheap. */
extern float SDLStatic_LightAt(SDLStatic_Engine *engine, float x, float y);

/** How many lights were submitted last frame, after the quality budget was
 *  applied. For a debug overlay, and for noticing that a budget is
 *  silently dropping half the scene. */
extern int SDLStatic_LightCount(SDLStatic_Engine *engine);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_LIGHT_H */
