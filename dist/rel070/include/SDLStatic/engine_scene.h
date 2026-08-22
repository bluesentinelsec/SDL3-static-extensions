/**
 * @file engine_scene.h
 * @brief Scenes: title screens, levels, pause menus, loading screens.
 *
 * Original SDLStatic code (zlib). A scene is a screen with a lifecycle and
 * its own state, and the engine keeps them in a **stack** rather than a
 * single "current scene" pointer.
 *
 * The stack is what makes a pause menu possible: pushing one leaves the
 * level underneath intact, so popping it back returns to exactly where the
 * player was, with no rebuilding and no saved state to restore. A design
 * with one current scene cannot express that at all.
 *
 *     static SDLStatic_SceneDef kLevel = {
 *         .name = "level",
 *         .state_size = sizeof(LevelState),
 *         .load = LevelLoad,
 *         .fixed_update = LevelFixedUpdate,
 *         .render = LevelRender,
 *     };
 *
 *     SDLStatic_ScenePush(engine, &kLevel);
 *
 * Scenes are dispatched by the engine's loop, so a game that uses them
 * usually leaves SDLStatic_GameHooks empty except for a debug overlay.
 * Both work at once: the hooks run around the stack, never instead of it.
 */
#ifndef SDLSTATIC_ENGINE_SCENE_H
#define SDLSTATIC_ENGINE_SCENE_H

#include <SDLStatic/engine.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SDLStatic_Scene SDLStatic_Scene;

/** How a covered scene behaves — the two questions a stack has to answer. */
typedef enum SDLStatic_SceneFlags
{
    SDLSTATIC_SCENE_DEFAULT = 0,
    /** Keep simulating while something is on top. Off by default, which is
     *  what "paused" means; on for a level that should keep running behind
     *  a transparent HUD or a dialogue box. */
    SDLSTATIC_SCENE_UPDATE_WHEN_COVERED = 1u << 0,
    /** This scene does not fill the screen, so the scene below it must be
     *  drawn first. What makes a pause menu look like a pause menu. */
    SDLSTATIC_SCENE_TRANSPARENT = 1u << 1
} SDLStatic_SceneFlags;

/**
 * A scene definition: what a screen *is*, independent of any instance.
 *
 * The engine **copies** this (and the name) when a scene is created, so a
 * definition may be a local, a temporary, or a table a script built a
 * moment ago. Nothing here has to outlive the push.
 *
 * Every callback is optional. `state_size` bytes are allocated with the
 * scene and zeroed; `SDLStatic_SceneState` hands them back. That keeps a
 * scene's data next to its lifetime, so leaving the scene frees it and no
 * game code has to remember.
 *
 * Lifecycle, in order:
 *
 *   load    once, when the scene is created — build the world, ask for
 *           assets. Returning false aborts the push.
 *   enter   whenever it becomes the top scene (so: after load, and again
 *           after whatever was above it pops)
 *   ...     fixed_update / update / render / event while it is on the stack
 *   exit    whenever it stops being the top scene
 *   unload  once, just before it is destroyed
 */
typedef struct SDLStatic_SceneDef
{
    const char *name;
    size_t state_size;
    SDLStatic_SceneFlags flags;

    bool (*load)(SDLStatic_Scene *scene);
    void (*enter)(SDLStatic_Scene *scene);
    void (*fixed_update)(SDLStatic_Scene *scene, float step);
    void (*update)(SDLStatic_Scene *scene, float dt);
    void (*render)(SDLStatic_Scene *scene, float alpha);
    void (*event)(SDLStatic_Scene *scene, const SDL_Event *event);
    void (*exit)(SDLStatic_Scene *scene);
    void (*unload)(SDLStatic_Scene *scene);
} SDLStatic_SceneDef;

/** Most scenes on the stack at once. A stack deeper than this is a bug. */
#define SDLSTATIC_SCENE_STACK_MAX 8

/* --- the stack ---------------------------------------------------------- */

/** Push a scene on top of the current one, which keeps its state.
 *
 *  The change takes effect at the end of the current frame, so a scene may
 *  push from inside its own update without the stack shifting under the
 *  code that is still running. */
extern bool SDLStatic_ScenePush(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def);

/** Pop the top scene, destroying it and resuming the one below. */
extern bool SDLStatic_ScenePop(SDLStatic_Engine *engine);

/** Replace the top scene: pop then push, in one deferred operation. */
extern bool SDLStatic_SceneReplace(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def);

/** Pop everything and start again with `def` — going back to the title
 *  screen from three menus deep. */
extern bool SDLStatic_SceneReset(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def);

/** The scene currently on top, or NULL when the stack is empty. */
extern SDLStatic_Scene *SDLStatic_SceneCurrent(SDLStatic_Engine *engine);

/** How many scenes are stacked. */
extern int SDLStatic_SceneDepth(SDLStatic_Engine *engine);

/** Find a scene by definition name anywhere in the stack — a pause menu
 *  asking the level below it a question. NULL when not present. */
extern SDLStatic_Scene *SDLStatic_SceneFind(SDLStatic_Engine *engine, const char *name);

/* --- a scene ------------------------------------------------------------ */

/** The scene's own state: `state_size` zeroed bytes, or NULL if it asked
 *  for none. */
extern void *SDLStatic_SceneState(SDLStatic_Scene *scene);

/** The engine the scene belongs to, so a callback that only received a
 *  scene can still reach the renderer. */
extern SDLStatic_Engine *SDLStatic_SceneEngine(SDLStatic_Scene *scene);

extern const char *SDLStatic_SceneName(SDLStatic_Scene *scene);

/** Is this scene the top of the stack (rather than covered by another)? */
extern bool SDLStatic_SceneIsActive(SDLStatic_Scene *scene);

/* --- transitions -------------------------------------------------------- */

typedef enum SDLStatic_SceneTransition
{
    SDLSTATIC_TRANSITION_NONE = 0, /**< immediate */
    SDLSTATIC_TRANSITION_FADE      /**< out to a colour, swap, back in */
} SDLStatic_SceneTransition;

/**
 * Replace the top scene with a transition.
 *
 * A fade runs in two halves: the outgoing scene fades to the transition
 * colour, the swap happens at the midpoint where nothing is visible, and
 * the incoming scene fades up. Doing it that way means only one scene is
 * ever live, so a transition cannot double the game's memory or run two
 * simulations at once — and the swap is hidden anyway.
 *
 * `seconds` is the whole transition, both halves. While one is running the
 * scenes still update, so a level does not freeze as it fades out.
 */
extern bool SDLStatic_SceneTransitionTo(SDLStatic_Engine *engine,
                                        const SDLStatic_SceneDef *def,
                                        SDLStatic_SceneTransition transition, float seconds);

/** Colour a fade passes through. Black by default; white for a flash, and
 *  a deep blue reads as "time passing" rather than "cut". */
extern void SDLStatic_SceneSetTransitionColor(SDLStatic_Engine *engine, SDL_FColor color);

/** True while a transition is running, for a scene that wants to ignore
 *  input during one. */
extern bool SDLStatic_SceneTransitioning(SDLStatic_Engine *engine);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_SCENE_H */
