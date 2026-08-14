/*
 * bindings_core.c — implementation of the language-independent binding core.
 * Original SDLStatic code (zlib). See bindings_core.h.
 */
#include "bindings_core.h"

#include <SDL3_image/SDL_image.h>
#include <SDLStatic/vfs.h>
#include <physfs.h>

BindApp *BindApp_Create(const char *title, int w, int h)
{
    if (!SDL_WasInit(SDL_INIT_VIDEO) && !SDL_InitSubSystem(SDL_INIT_VIDEO))
    {
        return NULL;
    }
    BindApp *app = (BindApp *)SDL_calloc(1, sizeof(BindApp));
    if (app == NULL)
    {
        return NULL;
    }
    if (!SDL_CreateWindowAndRenderer(title, w, h, SDL_WINDOW_RESIZABLE, &app->window,
                                     &app->renderer))
    {
        SDL_free(app);
        return NULL;
    }
    return app;
}

void BindApp_Destroy(BindApp *app)
{
    if (app == NULL)
    {
        return;
    }
    if (app->renderer != NULL)
    {
        SDL_DestroyRenderer(app->renderer);
    }
    if (app->window != NULL)
    {
        SDL_DestroyWindow(app->window);
    }
    SDL_free(app);
}

bool BindApp_Clear(BindApp *app, Uint8 r, Uint8 g, Uint8 b)
{
    return SDL_SetRenderDrawColor(app->renderer, r, g, b, 255) && SDL_RenderClear(app->renderer);
}

bool BindApp_Present(BindApp *app)
{
    return SDL_RenderPresent(app->renderer);
}

bool BindApp_PollEvent(BindEvent *out)
{
    SDL_Event event;
    SDL_memset(out, 0, sizeof(*out));
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            out->type = "quit";
            return true;
        case SDL_EVENT_KEY_DOWN:
        case SDL_EVENT_KEY_UP:
            out->type = "key";
            out->down = (event.type == SDL_EVENT_KEY_DOWN);
            SDL_strlcpy(out->key, SDL_GetKeyName(event.key.key), sizeof(out->key));
            return true;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
        case SDL_EVENT_MOUSE_BUTTON_UP:
            out->type = "mouse";
            out->down = (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN);
            out->x = event.button.x;
            out->y = event.button.y;
            out->button = event.button.button;
            return true;
        case SDL_EVENT_MOUSE_MOTION:
            out->type = "motion";
            out->x = event.motion.x;
            out->y = event.motion.y;
            return true;
        default:
            break; /* skip everything else, keep polling */
        }
    }
    return false;
}

bool BindApp_Rect(BindApp *app, float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b,
                  Uint8 a)
{
    const SDL_FRect rect = {x, y, w, h};
    return SDL_SetRenderDrawBlendMode(app->renderer,
                                      (a == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND) &&
           SDL_SetRenderDrawColor(app->renderer, r, g, b, a) &&
           SDL_RenderFillRect(app->renderer, &rect);
}

bool BindApp_Circle(BindApp *app, float x, float y, float rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    extern bool gpuFilledCircleRGBA(SDL_Renderer *, Sint16, Sint16, Sint16, Uint8, Uint8, Uint8,
                                    Uint8);
    return gpuFilledCircleRGBA(app->renderer, (Sint16)x, (Sint16)y, (Sint16)rad, r, g, b, a);
}

bool BindApp_Line(BindApp *app, float x1, float y1, float x2, float y2, Uint8 r, Uint8 g, Uint8 b,
                  Uint8 a)
{
    return SDL_SetRenderDrawBlendMode(app->renderer,
                                      (a == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND) &&
           SDL_SetRenderDrawColor(app->renderer, r, g, b, a) &&
           SDL_RenderLine(app->renderer, x1, y1, x2, y2);
}

bool BindApp_Text(BindApp *app, float x, float y, const char *text, Uint8 r, Uint8 g, Uint8 b)
{
    return SDL_SetRenderDrawColor(app->renderer, r, g, b, 255) &&
           SDL_RenderDebugText(app->renderer, x, y, text);
}

bool BindApp_KeyDown(const char *name)
{
    const SDL_Scancode scancode = SDL_GetScancodeFromName(name);
    if (scancode == SDL_SCANCODE_UNKNOWN)
    {
        return false;
    }
    int numkeys = 0;
    const bool *state = SDL_GetKeyboardState(&numkeys);
    return state != NULL && scancode < numkeys && state[scancode];
}

BindTexture *BindApp_LoadTexture(BindApp *app, const char *path)
{
    SDL_Surface *surface = NULL;
    if (PHYSFS_isInit() && PHYSFS_exists(path))
    {
        SDL_IOStream *io = SDLStatic_OpenVFSRead(path);
        if (io != NULL)
        {
            surface = IMG_Load_IO(io, true);
        }
    }
    else
    {
        surface = IMG_Load(path);
    }
    if (surface == NULL)
    {
        return NULL;
    }
    BindTexture *tex = (BindTexture *)SDL_calloc(1, sizeof(BindTexture));
    if (tex == NULL)
    {
        SDL_DestroySurface(surface);
        return NULL;
    }
    tex->texture = SDL_CreateTextureFromSurface(app->renderer, surface);
    tex->w = (float)surface->w;
    tex->h = (float)surface->h;
    SDL_DestroySurface(surface);
    if (tex->texture == NULL)
    {
        SDL_free(tex);
        return NULL;
    }
    return tex;
}

void BindTexture_Destroy(BindTexture *tex)
{
    if (tex != NULL)
    {
        if (tex->texture != NULL)
        {
            SDL_DestroyTexture(tex->texture);
        }
        SDL_free(tex);
    }
}

bool BindApp_Draw(BindApp *app, BindTexture *tex, float x, float y, float w, float h, double angle)
{
    const SDL_FRect dst = {x, y, (w > 0) ? w : tex->w, (h > 0) ? h : tex->h};
    if (angle == 0.0)
    {
        return SDL_RenderTexture(app->renderer, tex->texture, NULL, &dst);
    }
    return SDL_RenderTextureRotated(app->renderer, tex->texture, NULL, &dst, angle, NULL,
                                    SDL_FLIP_NONE);
}

/* ------------------------------------------------------------- audio ---- */

BindAudio *BindAudio_Open(void)
{
    if (!SDL_WasInit(SDL_INIT_AUDIO) && !SDL_InitSubSystem(SDL_INIT_AUDIO))
    {
        return NULL;
    }
    if (!MIX_Init())
    {
        return NULL;
    }
    BindAudio *audio = (BindAudio *)SDL_calloc(1, sizeof(BindAudio));
    if (audio == NULL)
    {
        return NULL;
    }
    audio->mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
    if (audio->mixer == NULL)
    {
        SDL_free(audio);
        return NULL;
    }
    return audio;
}

void BindAudio_Destroy(BindAudio *audio)
{
    if (audio != NULL)
    {
        if (audio->mixer != NULL)
        {
            MIX_DestroyMixer(audio->mixer);
        }
        SDL_free(audio);
    }
}

BindSound *BindAudio_Load(BindAudio *audio, const char *path)
{
    MIX_Audio *loaded = NULL;
    if (PHYSFS_isInit() && PHYSFS_exists(path))
    {
        SDL_IOStream *io = SDLStatic_OpenVFSRead(path);
        if (io != NULL)
        {
            loaded = MIX_LoadAudio_IO(audio->mixer, io, true, true);
        }
    }
    else
    {
        loaded = MIX_LoadAudio(audio->mixer, path, true);
    }
    if (loaded == NULL)
    {
        return NULL;
    }
    BindSound *sound = (BindSound *)SDL_calloc(1, sizeof(BindSound));
    if (sound == NULL)
    {
        MIX_DestroyAudio(loaded);
        return NULL;
    }
    sound->audio = loaded;
    return sound;
}

void BindSound_Destroy(BindSound *sound)
{
    if (sound != NULL)
    {
        if (sound->audio != NULL)
        {
            MIX_DestroyAudio(sound->audio);
        }
        SDL_free(sound);
    }
}

BindTrack *BindAudio_Play(BindAudio *audio, BindSound *sound, int loops)
{
    BindTrack *track = (BindTrack *)SDL_calloc(1, sizeof(BindTrack));
    if (track == NULL)
    {
        return NULL;
    }
    track->track = MIX_CreateTrack(audio->mixer);
    if (track->track == NULL || !MIX_SetTrackAudio(track->track, sound->audio))
    {
        BindTrack_Destroy(track);
        return NULL;
    }
    SDL_PropertiesID opts = 0;
    if (loops != 0)
    {
        opts = SDL_CreateProperties();
        SDL_SetNumberProperty(opts, MIX_PROP_PLAY_LOOPS_NUMBER, loops);
    }
    const bool ok = MIX_PlayTrack(track->track, opts);
    if (opts != 0)
    {
        SDL_DestroyProperties(opts);
    }
    if (!ok)
    {
        BindTrack_Destroy(track);
        return NULL;
    }
    return track;
}

void BindTrack_Destroy(BindTrack *track)
{
    if (track != NULL)
    {
        if (track->track != NULL)
        {
            MIX_DestroyTrack(track->track);
        }
        SDL_free(track);
    }
}

bool BindTrack_Stop(BindTrack *track)
{
    return MIX_StopTrack(track->track, 0);
}

bool BindTrack_SetGain(BindTrack *track, float gain)
{
    return MIX_SetTrackGain(track->track, gain);
}

/* ----------------------------------------------------------- physics ---- */

BindWorld *BindWorld_Create(float gx, float gy)
{
    BindWorld *world = (BindWorld *)SDL_calloc(1, sizeof(BindWorld));
    if (world == NULL)
    {
        return NULL;
    }
    b2WorldDef def = b2DefaultWorldDef();
    def.gravity.x = gx;
    def.gravity.y = gy;
    world->world = b2CreateWorld(&def);
    if (!b2World_IsValid(world->world))
    {
        SDL_free(world);
        SDL_SetError("b2CreateWorld failed");
        return NULL;
    }
    return world;
}

void BindWorld_Destroy(BindWorld *world)
{
    if (world != NULL)
    {
        if (b2World_IsValid(world->world))
        {
            b2DestroyWorld(world->world);
        }
        SDL_free(world);
    }
}

bool BindWorld_Step(BindWorld *world, float dt)
{
    if (!b2World_IsValid(world->world))
    {
        return SDL_SetError("world destroyed");
    }
    b2World_Step(world->world, dt, 4);
    return true;
}

static BindBody *AddBody(BindWorld *world, float x, float y, bool dynamic)
{
    if (!b2World_IsValid(world->world))
    {
        SDL_SetError("world destroyed");
        return NULL;
    }
    BindBody *body = (BindBody *)SDL_calloc(1, sizeof(BindBody));
    if (body == NULL)
    {
        return NULL;
    }
    b2BodyDef def = b2DefaultBodyDef();
    def.type = dynamic ? b2_dynamicBody : b2_staticBody;
    def.position.x = x;
    def.position.y = y;
    body->body = b2CreateBody(world->world, &def);
    return body;
}

BindBody *BindWorld_AddBox(BindWorld *world, float x, float y, float hw, float hh, bool dynamic)
{
    BindBody *body = AddBody(world, x, y, dynamic);
    if (body != NULL)
    {
        const b2Polygon poly = b2MakeBox(hw, hh);
        b2ShapeDef shape = b2DefaultShapeDef();
        b2CreatePolygonShape(body->body, &shape, &poly);
    }
    return body;
}

BindBody *BindWorld_AddCircle(BindWorld *world, float x, float y, float radius, bool dynamic)
{
    BindBody *body = AddBody(world, x, y, dynamic);
    if (body != NULL)
    {
        const b2Circle circle = {{0.0f, 0.0f}, radius};
        b2ShapeDef shape = b2DefaultShapeDef();
        b2CreateCircleShape(body->body, &shape, &circle);
    }
    return body;
}

void BindBody_DestroyWrapper(BindBody *body)
{
    SDL_free(body); /* bodies themselves die with their world */
}

bool BindBody_Position(BindBody *body, float *x, float *y)
{
    if (!b2Body_IsValid(body->body))
    {
        return SDL_SetError("body's world was destroyed");
    }
    const b2Vec2 pos = b2Body_GetPosition(body->body);
    *x = pos.x;
    *y = pos.y;
    return true;
}

float BindBody_Angle(BindBody *body)
{
    if (!b2Body_IsValid(body->body))
    {
        return 0.0f;
    }
    return b2Rot_GetAngle(b2Body_GetRotation(body->body));
}

bool BindBody_SetVelocity(BindBody *body, float vx, float vy)
{
    if (!b2Body_IsValid(body->body))
    {
        return SDL_SetError("body's world was destroyed");
    }
    const b2Vec2 v = {vx, vy};
    b2Body_SetLinearVelocity(body->body, v);
    return true;
}

bool BindBody_ApplyImpulse(BindBody *body, float ix, float iy)
{
    if (!b2Body_IsValid(body->body))
    {
        return SDL_SetError("body's world was destroyed");
    }
    const b2Vec2 impulse = {ix, iy};
    b2Body_ApplyLinearImpulseToCenter(body->body, impulse, true);
    return true;
}
