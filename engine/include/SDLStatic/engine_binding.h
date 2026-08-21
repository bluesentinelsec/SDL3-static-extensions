/**
 * @file engine_binding.h
 * @brief Actions: named intents bound to whatever the player presses.
 *
 * Original SDLStatic code (zlib).
 *
 * Game code should say what it means, not which key means it:
 *
 *     if (SDLStatic_ActionPressed(engine, map, player, "jump")) Jump();
 *     float move = SDLStatic_ActionValue(engine, map, player, "move_x");
 *
 * The point is not tidiness. A game written against scancodes cannot be
 * rebound without editing the game, cannot support a controller without
 * writing every check twice, and cannot be played by someone whose hands
 * do not fit the layout the designer happened to have. An action map is
 * how all three stop being the game's problem.
 *
 *     SDLStatic_ActionMap *map = SDLStatic_ActionMapCreate();
 *     SDLStatic_ActionBindKey(map, "jump", SDL_SCANCODE_SPACE);
 *     SDLStatic_ActionBindPad(map, "jump", SDLSTATIC_PAD_A);
 *     SDLStatic_ActionBindKeySigned(map, "move_x", SDL_SCANCODE_A, -1);
 *     SDLStatic_ActionBindKeySigned(map, "move_x", SDL_SCANCODE_D, +1);
 *     SDLStatic_ActionBindAxis(map, "move_x", SDLSTATIC_AXIS_LEFT_X, 0);
 *
 * ### Actions are signed and analog
 *
 * Every action has a value in [-1, 1], not a boolean. A key contributes its
 * binding's sign; a stick contributes its deflection. So "move_x" bound to
 * A, D and the left stick works with all three at once, and a game reads
 * one number whether the player is using a keyboard or leaning on a stick.
 * `Down` is then "is the magnitude past the threshold", which is the thing
 * a boolean action wanted to mean anyway.
 *
 * ### Who is player 2
 *
 * Gamepad bindings read the gamepad in the player's own slot: player 1 uses
 * pad 1. Keyboard and mouse bindings belong to whichever player
 * SDLStatic_ActionMapSetKeyboardPlayer says — player 0 by default — because
 * there is one keyboard and it cannot be shared by four people. Set it to
 * -1 for a strictly-gamepad game.
 */
#ifndef SDLSTATIC_ENGINE_BINDING_H
#define SDLSTATIC_ENGINE_BINDING_H

#include <SDLStatic/engine_input.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SDLStatic_ActionMap SDLStatic_ActionMap;

/** Where a binding gets its value from. */
typedef enum SDLStatic_BindingSource
{
    SDLSTATIC_BIND_NONE = 0,
    SDLSTATIC_BIND_KEY,          /**< code is an SDL_Scancode */
    SDLSTATIC_BIND_MOUSE_BUTTON, /**< code is an SDLStatic_MouseButton */
    SDLSTATIC_BIND_MOUSE_WHEEL,  /**< code 0 is vertical, 1 horizontal */
    SDLSTATIC_BIND_PAD_BUTTON,   /**< code is an SDLStatic_GamepadButton */
    SDLSTATIC_BIND_PAD_AXIS,     /**< code is an SDLStatic_GamepadAxis */
    /** A stick or the d-pad held in a direction, with menu repeat. code is
     *  an SDLStatic_Direction. */
    SDLSTATIC_BIND_PAD_DIRECTION
} SDLStatic_BindingSource;

/**
 * One way to trigger an action. An action may have several, and they are
 * all live at once — that is how a game supports a keyboard and a
 * controller without a mode switch.
 */
typedef struct SDLStatic_Binding
{
    SDLStatic_BindingSource source;
    int code;
    /** Which way this binding pushes the action: +1 or -1. A jump button is
     *  +1; the A key of an A/D pair is -1. */
    int sign;
    /** For an axis: ignore deflection the other way. 0 accepts both
     *  directions (a stick axis bound to a signed action), +1 or -1 accepts
     *  only that side (half a stick bound to a one-way action). */
    int axis_half;
} SDLStatic_Binding;

/* --- the map ------------------------------------------------------------- */

extern SDLStatic_ActionMap *SDLStatic_ActionMapCreate(void);
extern void SDLStatic_ActionMapDestroy(SDLStatic_ActionMap *map);

/** Which player the keyboard and mouse belong to. 0 by default; -1 means
 *  nobody, for a game that is gamepad-only. */
extern void SDLStatic_ActionMapSetKeyboardPlayer(SDLStatic_ActionMap *map, int player);
extern int SDLStatic_ActionMapKeyboardPlayer(SDLStatic_ActionMap *map);

/** Add a binding. The action is created if it does not exist, so there is
 *  no separate "declare the action" step. Returns false only on
 *  allocation failure or a nonsense binding. */
extern bool SDLStatic_ActionBind(SDLStatic_ActionMap *map, const char *action,
                                 SDLStatic_Binding binding);

/* Shorthands for the bindings games actually write. */
extern bool SDLStatic_ActionBindKey(SDLStatic_ActionMap *map, const char *action,
                                    SDL_Scancode key);
extern bool SDLStatic_ActionBindKeySigned(SDLStatic_ActionMap *map, const char *action,
                                          SDL_Scancode key, int sign);
extern bool SDLStatic_ActionBindMouse(SDLStatic_ActionMap *map, const char *action,
                                      SDLStatic_MouseButton button);
extern bool SDLStatic_ActionBindPad(SDLStatic_ActionMap *map, const char *action,
                                    SDLStatic_GamepadButton button);
/** `half` is 0 for the whole axis, or +1/-1 for one side of it. */
extern bool SDLStatic_ActionBindAxis(SDLStatic_ActionMap *map, const char *action,
                                     SDLStatic_GamepadAxis axis, int half);
extern bool SDLStatic_ActionBindDirection(SDLStatic_ActionMap *map, const char *action,
                                          SDLStatic_Direction direction);

/** Forget every binding for an action — step one of rebinding it. */
extern void SDLStatic_ActionClear(SDLStatic_ActionMap *map, const char *action);

/** How many actions the map knows, and their names, for a settings screen
 *  that lists them. */
extern int SDLStatic_ActionCount(SDLStatic_ActionMap *map);
extern const char *SDLStatic_ActionName(SDLStatic_ActionMap *map, int index);

/** The bindings on one action, for the same screen. */
extern int SDLStatic_ActionBindingCount(SDLStatic_ActionMap *map, const char *action);
extern bool SDLStatic_ActionBindingAt(SDLStatic_ActionMap *map, const char *action, int index,
                                      SDLStatic_Binding *out);

/* --- reading ------------------------------------------------------------- */

/** The action's value, in [-1, 1]. Several bindings sum and clamp, so
 *  holding A and D cancels out rather than fighting. */
extern float SDLStatic_ActionValue(SDLStatic_Engine *engine, SDLStatic_ActionMap *map,
                                   int player, const char *action);

/** Past the threshold now. */
extern bool SDLStatic_ActionDown(SDLStatic_Engine *engine, SDLStatic_ActionMap *map, int player,
                                 const char *action);

/** Crossed the threshold this frame — and, like every edge in this engine,
 *  stays true for all of it, including every fixed step. */
extern bool SDLStatic_ActionPressed(SDLStatic_Engine *engine, SDLStatic_ActionMap *map,
                                    int player, const char *action);

extern bool SDLStatic_ActionReleased(SDLStatic_Engine *engine, SDLStatic_ActionMap *map,
                                     int player, const char *action);

/** Two actions as a vector, normalised so that diagonal movement is not
 *  faster than straight movement — the oldest bug in 2D games. */
extern void SDLStatic_ActionVector(SDLStatic_Engine *engine, SDLStatic_ActionMap *map,
                                   int player, const char *x_action, const char *y_action,
                                   float *x, float *y);

/* --- rebinding ----------------------------------------------------------- */

/**
 * Capture whatever the player presses next, for a "press a key to bind"
 * prompt.
 *
 * Returns true on the frame something was pressed, with the binding in
 * `out`. Movement is ignored — a stick resting off-centre or a mouse being
 * moved would otherwise capture itself the instant the prompt opened.
 *
 * `player` limits capture to one player's gamepad, or pass -1 for any.
 */
extern bool SDLStatic_ActionCapture(SDLStatic_Engine *engine, int player,
                                    SDLStatic_Binding *out);

/** A binding as text — "space", "pad:a", "axis:left_x", "mouse:left" — for
 *  a settings screen and for saving. Writes into `buffer` and returns it. */
extern const char *SDLStatic_BindingToString(SDLStatic_Binding binding, char *buffer,
                                             size_t size);

/** Parse what BindingToString wrote. Returns false on anything else. */
extern bool SDLStatic_BindingFromString(const char *text, SDLStatic_Binding *out);

/* --- persistence --------------------------------------------------------- */

/**
 * The map as TOML, for saving alongside the graphics settings:
 *
 *     [bindings]
 *     jump = ["space", "pad:a"]
 *     move_x = ["-a", "+d", "axis:left_x"]
 *
 * Returns a SDL_malloc'd string; free it with SDL_free.
 */
extern char *SDLStatic_ActionMapToToml(SDLStatic_ActionMap *map);

/** Load bindings from TOML. Actions present in the document **replace**
 *  their bindings entirely; actions absent from it keep the defaults the
 *  game set up. That way a player who rebound one key does not lose every
 *  other binding when the game adds a new action in a later version. */
extern bool SDLStatic_ActionMapLoadToml(SDLStatic_ActionMap *map, const char *toml);

/** Save to `bindings.toml` in the pref directory, beside config.toml. */
extern bool SDLStatic_ActionMapSave(SDLStatic_ActionMap *map, const char *org, const char *app);

/** Load it back. Returns false if there is nothing to load, which is not an
 *  error — it is what happens the first time a game runs. */
extern bool SDLStatic_ActionMapLoad(SDLStatic_ActionMap *map, const char *org, const char *app);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_BINDING_H */
