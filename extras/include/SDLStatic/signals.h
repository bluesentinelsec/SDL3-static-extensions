/**
 * @file signals.h
 * @brief Godot-style signals for C (SDLStatic Extras).
 *
 * Original SDLStatic code (zlib). An emitter owns named signals; any code
 * can connect a callback to a signal name and gets invoked (in connection
 * order) whenever that signal is emitted:
 *
 *   SDLStatic_SignalEmitter *door = SDLStatic_CreateSignalEmitter();
 *   Uint64 id = SDLStatic_ConnectSignal(door, "opened", on_door_opened, hud, 0);
 *   ...
 *   SDLStatic_EmitSignal(door, "opened", &args);   // calls on_door_opened(hud, &args)
 *   SDLStatic_DisconnectSignal(door, id);
 *
 * Semantics (matching Godot where it matters):
 *  - Connections made *during* an emission do not fire in that emission.
 *  - Disconnecting during an emission is safe (including self-disconnect).
 *  - SDLSTATIC_SIGNAL_ONESHOT auto-disconnects after the first delivery.
 *  - Emission is reentrant (a handler may emit).
 *  - Not thread-safe by design: use from one thread, like a game loop.
 */
#ifndef SDLSTATIC_SIGNALS_H
#define SDLSTATIC_SIGNALS_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SDLStatic_SignalEmitter SDLStatic_SignalEmitter;

/** Callback invoked on emission. `args` is the pointer passed to Emit. */
typedef void (*SDLStatic_SignalCallback)(void *userdata, const char *signal, void *args);

#define SDLSTATIC_SIGNAL_ONESHOT (1u << 0) /**< auto-disconnect after first delivery */

/** Create an emitter. Destroy with SDLStatic_DestroySignalEmitter. */
extern SDLStatic_SignalEmitter *SDLStatic_CreateSignalEmitter(void);

/** Destroy an emitter and all its connections. Must not be called from a
 *  handler currently being invoked by this emitter. */
extern void SDLStatic_DestroySignalEmitter(SDLStatic_SignalEmitter *emitter);

/**
 * Connect a callback to a signal name.
 * \returns a nonzero connection id, or 0 on error.
 */
extern Uint64 SDLStatic_ConnectSignal(SDLStatic_SignalEmitter *emitter, const char *signal,
                                      SDLStatic_SignalCallback callback, void *userdata,
                                      Uint32 flags);

/** Disconnect by id. \returns true if the connection existed. */
extern bool SDLStatic_DisconnectSignal(SDLStatic_SignalEmitter *emitter, Uint64 connection);

/**
 * Emit a signal: invokes every live connection for `signal` in connection
 * order, passing `args` through untouched.
 * \returns the number of callbacks invoked, or -1 on error.
 */
extern int SDLStatic_EmitSignal(SDLStatic_SignalEmitter *emitter, const char *signal, void *args);

/** Number of live connections for a signal (all signals if NULL). */
extern int SDLStatic_CountSignalConnections(SDLStatic_SignalEmitter *emitter, const char *signal);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_SIGNALS_H */
