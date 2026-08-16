/**
 * @file engine_render.h
 * @brief Engine-owned drawing: a sprite per actor, z-ordered and culled.
 *
 * Original SDLStatic code (zlib).
 *
 * Give an actor a sprite and the engine draws it — in the right order,
 * only if it is on screen, at the interpolated position, through whichever
 * camera you hand it:
 *
 *     SDLStatic_Sprite sprite = SDLStatic_SpriteDefault();
 *     sprite.texture = goblin_texture;
 *     sprite.width = 64.0f;
 *     sprite.height = 64.0f;
 *     sprite.layer = LAYER_ACTORS;
 *     SDLStatic_ActorSetSprite(actor, &sprite);
 *
 *     // in the render hook
 *     SDLStatic_RenderWorld(engine, &camera, alpha);
 *
 * That is the whole loop for a 2D game. What the engine is doing on your
 * behalf, and why each piece is worth having in the engine rather than in
 * every game:
 *
 *   **Ordering.** Draw order is the difference between a character standing
 *   in front of a tree and inside it. Sorting per frame by an explicit
 *   layer, and optionally by world Y within it, is the thing every 2D game
 *   needs and no two hand-rolled versions agree on.
 *
 *   **Culling.** A level is bigger than the screen — that is what a camera
 *   is for — so most of it must not be drawn. Culling against the camera's
 *   visible rectangle turns "draw the level" from O(level) into O(screen).
 *
 *   **Interpolation.** Sprites are drawn at
 *   SDLStatic_ActorRenderTransform, so motion is smooth without any game
 *   writing its own `previous_x`.
 *
 * The engine does **not** load textures. A sprite holds an `SDL_Texture *`
 * the game made however it liked; asset streaming is its own subsystem.
 * Drawing what you are given and fetching what you asked for are different
 * jobs with different failure modes, and merging them makes both worse.
 */
#ifndef SDLSTATIC_ENGINE_RENDER_H
#define SDLSTATIC_ENGINE_RENDER_H

#include <SDLStatic/engine_actor.h>
#include <SDLStatic/engine_camera.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * What to draw for an actor.
 *
 * Copied into the actor when set, so it may be a local. Get it back with
 * SDLStatic_ActorSprite and change it in place — a sprite that animates is
 * changing `source` every few frames, and going through a setter for that
 * would be silly.
 */
typedef struct SDLStatic_Sprite
{
    /** The texture. NULL draws a solid rectangle in `color` instead, which
     *  is genuinely useful: it is how a game gets something on screen
     *  before it has any art, and how a debug view marks a hitbox. */
    SDL_Texture *texture;

    /** The part of the texture to draw. A zero width or height means the
     *  whole thing — so an unset source does the obvious. Animation is
     *  moving this rectangle. */
    SDL_FRect source;

    /** On-screen size in **world units**, before the actor's scale. Zero
     *  means the source rectangle's size, so a sprite drawn at its natural
     *  size needs no numbers at all. */
    float width, height;

    /** Where the actor's position sits within the sprite, as a fraction of
     *  its size. (0.5, 0.5) is the middle and the default; (0.5, 1.0) is
     *  the bottom edge, which is what you want for anything standing on
     *  ground, because then its position *is* where its feet are. */
    float origin_x, origin_y;

    /** Multiplied into the texture. White is untouched; the alpha is what
     *  fades a sprite out. */
    SDL_FColor color;

    SDL_FlipMode flip;

    /** Coarse draw order: background, ground, actors, foreground, UI. Lower
     *  is drawn first, so higher layers are in front. Use spaced-out
     *  constants (0, 100, 200) and leave room to insert. */
    int layer;

    /** Fine order within a layer. Lower first. Ignored when `sort_by_y` is
     *  set. */
    float order;

    /** Sort by world Y within the layer instead of by `order`, so something
     *  further down the screen is drawn in front. This is how a top-down or
     *  isometric game gets depth out of a 2D scene, and doing it in the
     *  engine means it happens after the actor has moved rather than from a
     *  value the game had to remember to update. */
    bool sort_by_y;

    /** Drawn in **design** coordinates, ignoring the camera: a HUD, a
     *  health bar in a fixed corner. Screen-space sprites are drawn by
     *  SDLStatic_RenderOverlay rather than SDLStatic_RenderWorld, so a
     *  split-screen game draws its HUD once instead of once per player. */
    bool screen_space;

    /** False hides the sprite without touching the actor. */
    bool visible;
} SDLStatic_Sprite;

/** A sprite with the defaults filled in: visible, white, centred origin.
 *  Start here — a zero-initialised sprite would be invisible and
 *  transparent, which is never what anybody meant. */
extern SDLStatic_Sprite SDLStatic_SpriteDefault(void);

/** Give this actor a sprite, replacing any it had. The struct is copied. */
extern bool SDLStatic_ActorSetSprite(SDLStatic_Actor *actor, const SDLStatic_Sprite *sprite);

/** The actor's sprite, to read or change in place. NULL if it has none. */
extern SDLStatic_Sprite *SDLStatic_ActorSprite(SDLStatic_Actor *actor);

/** Remove the sprite. The actor carries on existing, unseen. */
extern void SDLStatic_ActorClearSprite(SDLStatic_Actor *actor);

/* --- drawing ------------------------------------------------------------- */

/**
 * Draw every world sprite through `camera`, sorted and culled.
 *
 * Call from the render hook, with the `alpha` it was given. The camera is
 * set up and put back for you, so this composes with anything else drawn
 * around it. `camera` may be NULL to draw in design coordinates without one
 * — useful for a menu screen that still wants the sorting.
 *
 * In split screen, call it once per camera; each pass culls to its own
 * viewport, which is most of what makes four views affordable.
 *
 * Returns the number of sprites drawn.
 */
extern int SDLStatic_RenderWorld(SDLStatic_Engine *engine, const SDLStatic_Camera *camera,
                                 float alpha);

/**
 * Draw every screen-space sprite, in design coordinates.
 *
 * Separate from SDLStatic_RenderWorld because a HUD belongs to the player,
 * not to a viewport: a split-screen game calls RenderWorld once per camera
 * and this once, at the end.
 */
extern int SDLStatic_RenderOverlay(SDLStatic_Engine *engine, float alpha);

/** What the last RenderWorld or RenderOverlay did. Worth putting on a debug
 *  overlay: "considered 4000, drew 60" is how you find out that culling is
 *  working, and "drew 4000" is how you find out it is not. */
typedef struct SDLStatic_RenderStats
{
    int considered; /**< actors with a visible sprite */
    int culled;     /**< skipped: off screen */
    int drawn;
} SDLStatic_RenderStats;

extern SDLStatic_RenderStats SDLStatic_RenderLastStats(SDLStatic_Engine *engine);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_RENDER_H */
