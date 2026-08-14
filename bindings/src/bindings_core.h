/*
 * bindings_core.h — language-independent core for the script bindings.
 *
 * Original SDLStatic code (zlib). The Lua and Ruby binding files marshal
 * arguments and manage GC; every actual operation lives here so the two
 * languages expose identical behavior. All handles are opaque structs the
 * script side owns via GC-finalized wrappers.
 */
#ifndef SDLSTATIC_BINDINGS_CORE_H
#define SDLSTATIC_BINDINGS_CORE_H

#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <box2d/box2d.h>

typedef struct BindApp
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} BindApp;

typedef struct BindTexture
{
    SDL_Texture *texture;
    float w;
    float h;
} BindTexture;

typedef struct BindAudio
{
    MIX_Mixer *mixer;
} BindAudio;

typedef struct BindSound
{
    MIX_Audio *audio;
} BindSound;

typedef struct BindTrack
{
    MIX_Track *track;
} BindTrack;

typedef struct BindWorld
{
    b2WorldId world;
} BindWorld;

typedef struct BindBody
{
    b2BodyId body;
} BindBody;

typedef struct BindEvent
{
    const char *type; /* "quit" | "key" | "mouse" | "motion" | NULL */
    char key[32];
    bool down;
    float x;
    float y;
    int button;
} BindEvent;

BindApp *BindApp_Create(const char *title, int w, int h);
void BindApp_Destroy(BindApp *app);
bool BindApp_Clear(BindApp *app, Uint8 r, Uint8 g, Uint8 b);
bool BindApp_Present(BindApp *app);
bool BindApp_PollEvent(BindEvent *out);
bool BindApp_Rect(BindApp *app, float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b,
                  Uint8 a);
bool BindApp_Circle(BindApp *app, float x, float y, float rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
bool BindApp_Line(BindApp *app, float x1, float y1, float x2, float y2, Uint8 r, Uint8 g, Uint8 b,
                  Uint8 a);
bool BindApp_Text(BindApp *app, float x, float y, const char *text, Uint8 r, Uint8 g, Uint8 b);
bool BindApp_KeyDown(const char *name);

BindTexture *BindApp_LoadTexture(BindApp *app, const char *path);
void BindTexture_Destroy(BindTexture *tex);
bool BindApp_Draw(BindApp *app, BindTexture *tex, float x, float y, float w, float h,
                  double angle);

BindAudio *BindAudio_Open(void);
void BindAudio_Destroy(BindAudio *audio);
BindSound *BindAudio_Load(BindAudio *audio, const char *path);
void BindSound_Destroy(BindSound *sound);
BindTrack *BindAudio_Play(BindAudio *audio, BindSound *sound, int loops);
void BindTrack_Destroy(BindTrack *track);
bool BindTrack_Stop(BindTrack *track);
bool BindTrack_SetGain(BindTrack *track, float gain);

BindWorld *BindWorld_Create(float gx, float gy);
void BindWorld_Destroy(BindWorld *world);
bool BindWorld_Step(BindWorld *world, float dt);
BindBody *BindWorld_AddBox(BindWorld *world, float x, float y, float hw, float hh, bool dynamic);
BindBody *BindWorld_AddCircle(BindWorld *world, float x, float y, float radius, bool dynamic);
void BindBody_DestroyWrapper(BindBody *body);
bool BindBody_Position(BindBody *body, float *x, float *y);
float BindBody_Angle(BindBody *body);
bool BindBody_SetVelocity(BindBody *body, float vx, float vy);
bool BindBody_ApplyImpulse(BindBody *body, float ix, float iy);

#endif /* SDLSTATIC_BINDINGS_CORE_H */
