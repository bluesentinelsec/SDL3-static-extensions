/*
 * sdlstatic_signals.c — Godot-style signals for SDLStatic Extras.
 *
 * Original SDLStatic code (zlib). Semantics documented in
 * SDLStatic/signals.h: connections added during an emission don't fire in
 * it, disconnect-during-emit is safe, one-shots auto-disconnect, emission
 * is reentrant. Dead connections are compacted once no emission is active.
 */
#include <SDLStatic/signals.h>

typedef struct Connection
{
    Uint64 id;
    char *signal;
    SDLStatic_SignalCallback callback;
    void *userdata;
    Uint32 flags;
    bool alive;
} Connection;

struct SDLStatic_SignalEmitter
{
    Connection *connections;
    int count;
    int capacity;
    int emit_depth;
    Uint64 next_id;
};

SDLStatic_SignalEmitter *SDLStatic_CreateSignalEmitter(void)
{
    SDLStatic_SignalEmitter *e =
        (SDLStatic_SignalEmitter *)SDL_calloc(1, sizeof(SDLStatic_SignalEmitter));
    if (e != NULL)
    {
        e->next_id = 1;
    }
    return e;
}

void SDLStatic_DestroySignalEmitter(SDLStatic_SignalEmitter *emitter)
{
    if (emitter == NULL)
    {
        return;
    }
    for (int i = 0; i < emitter->count; ++i)
    {
        SDL_free(emitter->connections[i].signal);
    }
    SDL_free(emitter->connections);
    SDL_free(emitter);
}

Uint64 SDLStatic_ConnectSignal(SDLStatic_SignalEmitter *emitter, const char *signal,
                               SDLStatic_SignalCallback callback, void *userdata, Uint32 flags)
{
    if (emitter == NULL || signal == NULL || *signal == '\0' || callback == NULL)
    {
        SDL_InvalidParamError("emitter/signal/callback");
        return 0;
    }
    if (emitter->count == emitter->capacity)
    {
        const int cap = (emitter->capacity > 0) ? emitter->capacity * 2 : 8;
        Connection *grown =
            (Connection *)SDL_realloc(emitter->connections, sizeof(Connection) * (size_t)cap);
        if (grown == NULL)
        {
            return 0;
        }
        emitter->connections = grown;
        emitter->capacity = cap;
    }
    char *name = SDL_strdup(signal);
    if (name == NULL)
    {
        return 0;
    }
    Connection *c = &emitter->connections[emitter->count++];
    c->id = emitter->next_id++;
    c->signal = name;
    c->callback = callback;
    c->userdata = userdata;
    c->flags = flags;
    c->alive = true;
    return c->id;
}

static void Compact(SDLStatic_SignalEmitter *emitter)
{
    if (emitter->emit_depth > 0)
    {
        return; /* an emission is iterating; defer */
    }
    int keep = 0;
    for (int i = 0; i < emitter->count; ++i)
    {
        if (emitter->connections[i].alive)
        {
            emitter->connections[keep++] = emitter->connections[i];
        }
        else
        {
            SDL_free(emitter->connections[i].signal);
        }
    }
    emitter->count = keep;
}

bool SDLStatic_DisconnectSignal(SDLStatic_SignalEmitter *emitter, Uint64 connection)
{
    if (emitter == NULL || connection == 0)
    {
        return false;
    }
    for (int i = 0; i < emitter->count; ++i)
    {
        Connection *c = &emitter->connections[i];
        if (c->id == connection && c->alive)
        {
            c->alive = false;
            Compact(emitter);
            return true;
        }
    }
    return false;
}

int SDLStatic_EmitSignal(SDLStatic_SignalEmitter *emitter, const char *signal, void *args)
{
    if (emitter == NULL || signal == NULL)
    {
        SDL_InvalidParamError("emitter/signal");
        return -1;
    }
    /* Snapshot the count: connections appended by handlers must not fire
     * in this emission. Indices stay stable because compaction is deferred
     * while emit_depth > 0. */
    const int snapshot = emitter->count;
    emitter->emit_depth++;
    int invoked = 0;
    for (int i = 0; i < snapshot; ++i)
    {
        Connection *c = &emitter->connections[i];
        if (!c->alive || SDL_strcmp(c->signal, signal) != 0)
        {
            continue;
        }
        if (c->flags & SDLSTATIC_SIGNAL_ONESHOT)
        {
            c->alive = false; /* before the call: re-entrant emits skip it */
        }
        c->callback(c->userdata, signal, args);
        invoked++;
    }
    emitter->emit_depth--;
    Compact(emitter);
    return invoked;
}

int SDLStatic_CountSignalConnections(SDLStatic_SignalEmitter *emitter, const char *signal)
{
    if (emitter == NULL)
    {
        return 0;
    }
    int n = 0;
    for (int i = 0; i < emitter->count; ++i)
    {
        const Connection *c = &emitter->connections[i];
        if (c->alive && (signal == NULL || SDL_strcmp(c->signal, signal) == 0))
        {
            n++;
        }
    }
    return n;
}
