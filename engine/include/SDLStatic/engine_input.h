/**
 * @file engine_input.h
 * @brief Polled input: keyboard, mouse, four gamepads, touch and motion.
 *
 * Original SDLStatic code (zlib).
 *
 * The engine pumps SDL's events once a frame and folds them into state the
 * game **asks** for, rather than handing the game a callback per event:
 *
 *     if (SDLStatic_KeyPressed(engine, SDL_SCANCODE_SPACE)) Jump();
 *     if (SDLStatic_GamepadButtonDown(engine, 0, SDL_GAMEPAD_BUTTON_SOUTH)) Hold();
 *
 * Polling because a game asks "is the player holding right" at a point in
 * its own logic where the answer matters, and an event callback arrives at
 * a point where it does not — so every callback-based game ends up building
 * exactly this state table by hand, usually with one bug in it.
 *
 * ### Edges last the whole frame
 *
 * `Pressed` and `Released` mean "this frame", and stay true for **all** of
 * it — including every `fixed_update` step, of which there may be several.
 * That matters more than it sounds: a jump polled from a fixed step, with
 * edges cleared per step, is silently dropped whenever a frame happens to
 * run two steps. Here, all steps in a frame see the same edge, so a press
 * is never eaten and never doubled.
 *
 * ### Disconnection is normal
 *
 * A gamepad that goes away reads as neutral — no buttons down, sticks at
 * zero — rather than freezing at whatever it was doing when the battery
 * died. A player whose controller dies mid-run should stop, not keep
 * sprinting into a pit. `SDLStatic_GamepadConnected` says whether anybody
 * is there; the player slot is kept, so reconnecting picks up the same
 * slot rather than shuffling everyone along.
 */
#ifndef SDLSTATIC_ENGINE_INPUT_H
#define SDLSTATIC_ENGINE_INPUT_H

#include <SDLStatic/engine.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Gamepads the engine tracks. Four, because that is what a couch holds. */
#define SDLSTATIC_MAX_PLAYERS 4

/* --- keyboard ------------------------------------------------------------ */

/** Held now. Scancodes, not keycodes: a scancode is a *position* on the
 *  keyboard, so WASD stays where the player's fingers are on an AZERTY
 *  layout. Use keycodes only for text. */
extern bool SDLStatic_KeyDown(SDLStatic_Engine *engine, SDL_Scancode key);

/** Went down this frame. True for every fixed step in the frame. */
extern bool SDLStatic_KeyPressed(SDLStatic_Engine *engine, SDL_Scancode key);

/** Came up this frame. */
extern bool SDLStatic_KeyReleased(SDLStatic_Engine *engine, SDL_Scancode key);

/** Any modifier state — shift, control, alt. */
extern SDL_Keymod SDLStatic_KeyModifiers(SDLStatic_Engine *engine);

/** Text typed this frame, as UTF-8, or "" — for a name-entry box. This is
 *  the only correct way to read text: a scancode is a key position and has
 *  no idea what character an IME or a layout would produce. */
extern const char *SDLStatic_TextTyped(SDLStatic_Engine *engine);

/** Start or stop delivering SDLStatic_TextTyped. Off by default, because
 *  while it is on the platform may show an on-screen keyboard. */
extern void SDLStatic_SetTextInput(SDLStatic_Engine *engine, bool enabled);

/* --- mouse --------------------------------------------------------------- */

typedef enum SDLStatic_MouseButton
{
    SDLSTATIC_MOUSE_LEFT = 0,
    SDLSTATIC_MOUSE_MIDDLE, /**< the wheel, pressed */
    SDLSTATIC_MOUSE_RIGHT,
    SDLSTATIC_MOUSE_X1, /**< the thumb buttons, if there are any */
    SDLSTATIC_MOUSE_X2,
    SDLSTATIC_MOUSE_COUNT
} SDLStatic_MouseButton;

/** Where the pointer is, in **design coordinates** — the same space the
 *  game draws in, so a hit test is a rectangle test and not a conversion
 *  exercise. */
extern void SDLStatic_MousePosition(SDLStatic_Engine *engine, float *x, float *y);

/** How far it moved this frame, in design units. */
extern void SDLStatic_MouseDelta(SDLStatic_Engine *engine, float *x, float *y);

extern bool SDLStatic_MouseDown(SDLStatic_Engine *engine, SDLStatic_MouseButton button);
extern bool SDLStatic_MousePressed(SDLStatic_Engine *engine, SDLStatic_MouseButton button);
extern bool SDLStatic_MouseReleased(SDLStatic_Engine *engine, SDLStatic_MouseButton button);

/** Wheel movement this frame. `y` is the usual vertical scroll; `x` is a
 *  tilt wheel or a trackpad's horizontal swipe. Both are already sign-
 *  corrected for natural scrolling. */
extern void SDLStatic_MouseWheel(SDLStatic_Engine *engine, float *x, float *y);

/** Relative mode: the cursor is hidden and locked, and MouseDelta keeps
 *  reporting movement past the window edge. What a game wants while the
 *  player is aiming, and must be turned off for menus. */
extern bool SDLStatic_SetMouseCapture(SDLStatic_Engine *engine, bool captured);
extern bool SDLStatic_MouseCaptured(SDLStatic_Engine *engine);

/* --- gamepads ------------------------------------------------------------ */

/**
 * Buttons, named as they are printed on an Xbox controller.
 *
 * SDL names its face buttons by position (south/east/west/north) so that
 * they survive a Nintendo layout where A and B are swapped. These are the
 * same buttons under the names most people say out loud; the mapping is
 * SDL's, so a DualSense reports cross as A and circle as B, which is what
 * a game means when it says "press A".
 */
typedef enum SDLStatic_GamepadButton
{
    SDLSTATIC_PAD_A = 0,
    SDLSTATIC_PAD_B,
    SDLSTATIC_PAD_X,
    SDLSTATIC_PAD_Y,
    SDLSTATIC_PAD_BACK,  /**< "view" on an Xbox pad */
    SDLSTATIC_PAD_GUIDE, /**< the glowing one in the middle */
    SDLSTATIC_PAD_START, /**< "menu" */
    SDLSTATIC_PAD_LEFT_STICK,
    SDLSTATIC_PAD_RIGHT_STICK,
    SDLSTATIC_PAD_LEFT_SHOULDER,  /**< LB */
    SDLSTATIC_PAD_RIGHT_SHOULDER, /**< RB */
    SDLSTATIC_PAD_DPAD_UP,
    SDLSTATIC_PAD_DPAD_DOWN,
    SDLSTATIC_PAD_DPAD_LEFT,
    SDLSTATIC_PAD_DPAD_RIGHT,
    SDLSTATIC_PAD_SHARE, /**< the share button on a Series X|S pad */
    SDLSTATIC_PAD_PADDLE1, /**< the four paddles on an Elite */
    SDLSTATIC_PAD_PADDLE2,
    SDLSTATIC_PAD_PADDLE3,
    SDLSTATIC_PAD_PADDLE4,
    SDLSTATIC_PAD_TOUCHPAD, /**< pressed, on the pads that have one */
    /** The triggers, as buttons. Past the threshold counts as a press,
     *  which is what a game means by "shoot" and saves every caller writing
     *  the same comparison. */
    SDLSTATIC_PAD_LEFT_TRIGGER,
    SDLSTATIC_PAD_RIGHT_TRIGGER,
    SDLSTATIC_PAD_BUTTON_COUNT
} SDLStatic_GamepadButton;

typedef enum SDLStatic_GamepadAxis
{
    SDLSTATIC_AXIS_LEFT_X = 0,
    SDLSTATIC_AXIS_LEFT_Y,
    SDLSTATIC_AXIS_RIGHT_X,
    SDLSTATIC_AXIS_RIGHT_Y,
    SDLSTATIC_AXIS_LEFT_TRIGGER,  /**< 0..1, not -1..1 */
    SDLSTATIC_AXIS_RIGHT_TRIGGER, /**< 0..1 */
    SDLSTATIC_AXIS_COUNT
} SDLStatic_GamepadAxis;

/** Is a controller in this slot? Slots are stable across disconnection, so
 *  player 2 stays player 2 when their battery dies and comes back. */
extern bool SDLStatic_GamepadConnected(SDLStatic_Engine *engine, int player);

/** How many are connected right now. */
extern int SDLStatic_GamepadCount(SDLStatic_Engine *engine);

/** The controller's name — "Xbox Series X Controller" — for a settings
 *  screen. NULL when the slot is empty. */
extern const char *SDLStatic_GamepadName(SDLStatic_Engine *engine, int player);

extern bool SDLStatic_GamepadButtonDown(SDLStatic_Engine *engine, int player,
                                        SDLStatic_GamepadButton button);
extern bool SDLStatic_GamepadButtonPressed(SDLStatic_Engine *engine, int player,
                                           SDLStatic_GamepadButton button);
extern bool SDLStatic_GamepadButtonReleased(SDLStatic_Engine *engine, int player,
                                            SDLStatic_GamepadButton button);

/** One axis, deadzoned. Sticks are -1..1; triggers are 0..1. */
extern float SDLStatic_GamepadAxisValue(SDLStatic_Engine *engine, int player,
                                        SDLStatic_GamepadAxis axis);

/**
 * A stick as a vector, with a **radial** deadzone.
 *
 * Deadzoning each axis on its own is the classic mistake: it carves a
 * square hole out of a round stick, so a gentle diagonal reads as zero
 * while the same distance straight up does not, and the player feels the
 * corners. This measures the stick's distance from centre, ignores it below
 * the threshold, and rescales the rest to a full 0..1 — so the smallest
 * movement that registers is the same in every direction and there is no
 * jump from nothing to something.
 *
 * `side` is 0 for the left stick, 1 for the right.
 */
extern void SDLStatic_GamepadStick(SDLStatic_Engine *engine, int player, int side, float *x,
                                   float *y);

/** The deadzone, as a fraction of full deflection. 0.2 by default, which
 *  suits a worn controller; a fresh one is happy at 0.1. */
extern void SDLStatic_SetGamepadDeadzone(SDLStatic_Engine *engine, float deadzone);
extern float SDLStatic_GamepadDeadzone(SDLStatic_Engine *engine);

/** How far a trigger must go to count as a button press. 0.5 by default. */
extern void SDLStatic_SetTriggerThreshold(SDLStatic_Engine *engine, float threshold);

/* --- sticks as buttons, for menus ---------------------------------------- */

/** The four directions, from a stick or the d-pad. */
typedef enum SDLStatic_Direction
{
    SDLSTATIC_DIR_UP = 0,
    SDLSTATIC_DIR_DOWN,
    SDLSTATIC_DIR_LEFT,
    SDLSTATIC_DIR_RIGHT,
    SDLSTATIC_DIR_COUNT
} SDLStatic_Direction;

/**
 * A stick held in a direction, reported as a button press — with the
 * key-repeat behaviour a menu needs.
 *
 * Navigating a menu with an analog stick is otherwise miserable: a raw
 * "is it past the threshold" moves the selection sixty times a second, and
 * a bare edge moves it once and then stops even though the player is still
 * holding. This gives one press immediately, a pause, then a steady repeat
 * — exactly what a keyboard's auto-repeat does, because that is the
 * behaviour everyone has already learned.
 *
 * Both sticks and the d-pad feed it, so a menu written against this works
 * with either without knowing which the player used.
 */
extern bool SDLStatic_GamepadDirectionRepeat(SDLStatic_Engine *engine, int player,
                                             SDLStatic_Direction direction);

/** The same edge without the repeat: true only on the frame the stick
 *  crosses into the direction. For a game that wants a single step per
 *  flick. */
extern bool SDLStatic_GamepadDirectionPressed(SDLStatic_Engine *engine, int player,
                                              SDLStatic_Direction direction);

/** Tune the repeat: how long a direction must be held before it starts
 *  repeating, and how fast it repeats after that. Defaults are 0.4s and
 *  0.12s, which match a typical desktop's key repeat. */
extern void SDLStatic_SetDirectionRepeat(SDLStatic_Engine *engine, float delay_seconds,
                                         float interval_seconds);

/* --- rumble -------------------------------------------------------------- */

/**
 * Shake the controller. Both motors are 0..1; `milliseconds` is how long.
 *
 * An Xbox pad's two motors are different weights — the low-frequency one is
 * a heavy thud, the high-frequency one a light buzz — so a hit wants low,
 * a pickup wants high, and an engine wants a little of both.
 *
 * Returns false if the slot is empty or the controller cannot rumble, which
 * a game may ignore: rumble is never load-bearing.
 */
extern bool SDLStatic_GamepadRumble(SDLStatic_Engine *engine, int player, float low, float high,
                                    Uint32 milliseconds);

/** The trigger motors, on controllers that have them (Xbox One and later).
 *  Fails harmlessly on those that do not. */
extern bool SDLStatic_GamepadRumbleTriggers(SDLStatic_Engine *engine, int player, float left,
                                            float right, Uint32 milliseconds);

/** Stop all rumble on a slot, or on every slot when `player` is negative.
 *  Call this when the game is paused or loses focus — a controller left
 *  buzzing while a player is in a menu is a bug people remember. */
extern void SDLStatic_GamepadStopRumble(SDLStatic_Engine *engine, int player);

/** Set the light bar / LED colour, on controllers that have one. */
extern bool SDLStatic_GamepadSetLED(SDLStatic_Engine *engine, int player, Uint8 red, Uint8 green,
                                    Uint8 blue);

/* --- motion -------------------------------------------------------------- */

/** Does this controller have the sensor? Most Xbox pads do not; DualSense
 *  and Switch Pro controllers do. */
extern bool SDLStatic_GamepadHasGyro(SDLStatic_Engine *engine, int player);
extern bool SDLStatic_GamepadHasAccelerometer(SDLStatic_Engine *engine, int player);

/** Turn the sensors on. Off by default: they deliver events at hundreds of
 *  hertz whether or not anybody is reading them. */
extern bool SDLStatic_SetGamepadMotion(SDLStatic_Engine *engine, int player, bool enabled);

/** Angular velocity in radians per second, about each axis: x is pitch, y
 *  is yaw, z is roll. Zero when there is no gyro or it is switched off. */
extern void SDLStatic_GamepadGyro(SDLStatic_Engine *engine, int player, float *x, float *y,
                                  float *z);

/** Acceleration in m/s², including gravity — so a controller at rest reads
 *  about 9.8 on whichever axis is pointing down, which is how you work out
 *  which way up it is being held. */
extern void SDLStatic_GamepadAccelerometer(SDLStatic_Engine *engine, int player, float *x,
                                           float *y, float *z);

/* --- touch --------------------------------------------------------------- */

/** Fingers the engine tracks at once. Ten is every finger a person has. */
#define SDLSTATIC_MAX_FINGERS 10

/** One finger, in **design coordinates** like the mouse. */
typedef struct SDLStatic_Finger
{
    SDL_FingerID id; /**< stable while the finger is down */
    float x, y;
    float dx, dy;  /**< movement this frame */
    float pressure;
    bool pressed;  /**< touched down this frame */
    bool released; /**< lifted this frame */
} SDLStatic_Finger;

/** How many fingers are down. */
extern int SDLStatic_FingerCount(SDLStatic_Engine *engine);

/** One of them, or NULL. Order is by when they went down, so finger 0 is
 *  the one that has been down longest — which is what a virtual thumbstick
 *  wants. */
extern const SDLStatic_Finger *SDLStatic_GetFinger(SDLStatic_Engine *engine, int index);

/** A finger that went down inside `area` this frame, or NULL. The building
 *  block for on-screen buttons: no gesture recogniser, just a hit test
 *  against a rectangle the game already knows about. */
extern const SDLStatic_Finger *SDLStatic_FingerInRect(SDLStatic_Engine *engine, SDL_FRect area);

/** A finger held down inside `area`, whether or not it started there. For a
 *  virtual d-pad, where sliding a thumb from one arrow to the next should
 *  keep working. */
extern const SDLStatic_Finger *SDLStatic_FingerHeldInRect(SDLStatic_Engine *engine,
                                                          SDL_FRect area);

/** Pinch this frame, as a scale factor: greater than 1 is fingers moving
 *  apart. Exactly 1 when fewer than two fingers are down. */
extern float SDLStatic_TouchPinch(SDLStatic_Engine *engine);

/** Rotation between two fingers this frame, in degrees. */
extern float SDLStatic_TouchRotation(SDLStatic_Engine *engine);

/* --- device motion ------------------------------------------------------- */

/** The *device's* own gyro and accelerometer — a phone or tablet being
 *  tilted, as opposed to a controller. Same units as the gamepad versions. */
extern bool SDLStatic_HasDeviceMotion(SDLStatic_Engine *engine);
extern bool SDLStatic_SetDeviceMotion(SDLStatic_Engine *engine, bool enabled);
extern void SDLStatic_DeviceGyro(SDLStatic_Engine *engine, float *x, float *y, float *z);
extern void SDLStatic_DeviceAccelerometer(SDLStatic_Engine *engine, float *x, float *y,
                                          float *z);

/* --- anything at all ----------------------------------------------------- */

/** Did anything happen this frame, on any device? What a title screen's
 *  "press any key" is really asking, and what an attract mode uses to
 *  decide it has been left alone. */
extern bool SDLStatic_AnyInput(SDLStatic_Engine *engine);

/** Seconds since the last input of any kind. */
extern float SDLStatic_IdleSeconds(SDLStatic_Engine *engine);

/** Which kind of device the player last used, so a game can switch its
 *  prompts between "Press A" and "Press Space" without being asked. */
typedef enum SDLStatic_InputDevice
{
    SDLSTATIC_DEVICE_NONE = 0,
    SDLSTATIC_DEVICE_KEYBOARD,
    SDLSTATIC_DEVICE_MOUSE,
    SDLSTATIC_DEVICE_GAMEPAD,
    SDLSTATIC_DEVICE_TOUCH
} SDLStatic_InputDevice;

extern SDLStatic_InputDevice SDLStatic_LastInputDevice(SDLStatic_Engine *engine);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_INPUT_H */
