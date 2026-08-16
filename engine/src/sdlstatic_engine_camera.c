/*
 * sdlstatic_engine_camera.c — the 2D camera.
 * Original SDLStatic code (zlib).
 *
 * World to design coordinates: a translation and a uniform scale, clipped
 * to a viewport. That is all a 2D camera is, and keeping it to exactly that
 * is what makes split screen fall out for free — four cameras are four
 * viewports over the same world.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_camera.h>

#define ZOOM_MIN 0.05f
#define ZOOM_MAX 50.0f

static float ClampF(float v, float lo, float hi)
{
    if (!(v == v))
    {
        return lo;
    }
    return (v < lo) ? lo : ((v > hi) ? hi : v);
}

void SDLStatic_CameraInit(SDLStatic_Camera *camera, SDLStatic_Engine *engine)
{
    if (camera == NULL)
    {
        return;
    }
    SDL_zerop(camera);
    camera->zoom = 1.0f;
    camera->viewport = SDLStatic_EngineViewRect(engine);
}

void SDLStatic_CameraFollow(SDLStatic_Camera *camera, float world_x, float world_y)
{
    if (camera == NULL)
    {
        return;
    }
    camera->target_x = world_x;
    camera->target_y = world_y;
}

void SDLStatic_CameraSnap(SDLStatic_Camera *camera, float world_x, float world_y)
{
    if (camera == NULL)
    {
        return;
    }
    camera->target_x = world_x;
    camera->target_y = world_y;
    camera->x = world_x;
    camera->y = world_y;
}

void SDLStatic_CameraShake(SDLStatic_Camera *camera, float amount, float seconds)
{
    if (camera == NULL || amount <= 0.0f || seconds <= 0.0f)
    {
        return;
    }
    /* A new shake replaces a weaker one rather than adding to it: two
       explosions in the same second should not shake twice as hard as one
       enormous explosion. */
    if (amount >= camera->shake_amount)
    {
        camera->shake_amount = amount;
        camera->shake_seconds = seconds;
        camera->shake_remaining = seconds;
    }
}

/* How far the camera should move to bring the target back inside the
   deadzone. Zero while the target is inside it — which is the point. */
static float DeadzoneDelta(float camera_pos, float target_pos, float zone_size, float zoom)
{
    if (zone_size <= 0.0f)
    {
        return target_pos - camera_pos;
    }
    /* The deadzone is given in design units, so it has to be converted to
       world units before it can be compared with world positions —
       otherwise zooming in would silently make it larger. */
    const float half = (zone_size * 0.5f) / ((zoom > 0.0f) ? zoom : 1.0f);
    const float delta = target_pos - camera_pos;
    if (delta > half)
    {
        return delta - half;
    }
    if (delta < -half)
    {
        return delta + half;
    }
    return 0.0f;
}

void SDLStatic_CameraUpdate(SDLStatic_Camera *camera, SDLStatic_Engine *engine, float dt)
{
    if (camera == NULL)
    {
        return;
    }
    camera->zoom = ClampF(camera->zoom, ZOOM_MIN, ZOOM_MAX);
    if (camera->viewport.w <= 0.0f || camera->viewport.h <= 0.0f)
    {
        camera->viewport = SDLStatic_EngineViewRect(engine);
    }
    if (dt < 0.0f)
    {
        dt = 0.0f;
    }

    const float want_x = camera->x + DeadzoneDelta(camera->x, camera->target_x,
                                                   camera->deadzone_w, camera->zoom);
    const float want_y = camera->y + DeadzoneDelta(camera->y, camera->target_y,
                                                   camera->deadzone_h, camera->zoom);

    if (camera->smoothing > 0.0f && dt > 0.0f)
    {
        /* Exponential decay against dt, not a fixed fraction per frame. A
           fraction-per-frame camera is faster at 144 Hz than at 60, so the
           game feels different on different machines — the classic reason a
           camera "feels wrong" on someone else's computer. */
        const float t = 1.0f - SDL_expf(-dt / camera->smoothing);
        camera->x += (want_x - camera->x) * t;
        camera->y += (want_y - camera->y) * t;
    }
    else
    {
        camera->x = want_x;
        camera->y = want_y;
    }

    /* The world rectangle the viewport covers, before clamping. */
    const float view_w = camera->viewport.w / camera->zoom;
    const float view_h = camera->viewport.h / camera->zoom;

    if (camera->bounds.w > 0.0f && camera->bounds.h > 0.0f)
    {
        if (view_w >= camera->bounds.w)
        {
            /* The level is narrower than the view: centre on it. Clamping
               instead would push a short level against one edge. */
            camera->x = camera->bounds.x + camera->bounds.w * 0.5f;
        }
        else
        {
            camera->x = ClampF(camera->x, camera->bounds.x + view_w * 0.5f,
                               camera->bounds.x + camera->bounds.w - view_w * 0.5f);
        }
        if (view_h >= camera->bounds.h)
        {
            camera->y = camera->bounds.y + camera->bounds.h * 0.5f;
        }
        else
        {
            camera->y = ClampF(camera->y, camera->bounds.y + view_h * 0.5f,
                               camera->bounds.y + camera->bounds.h - view_h * 0.5f);
        }
    }

    if (camera->shake_remaining > 0.0f)
    {
        camera->shake_remaining -= dt;
        if (camera->shake_remaining <= 0.0f)
        {
            camera->shake_remaining = 0.0f;
            camera->shake_amount = 0.0f;
        }
    }

    camera->visible.w = view_w;
    camera->visible.h = view_h;
    camera->visible.x = camera->x - view_w * 0.5f;
    camera->visible.y = camera->y - view_h * 0.5f;
}

/* The shake offset for this frame. Random per call, decaying with the time
   left, so a shake tapers instead of stopping dead. */
static void ShakeOffset(const SDLStatic_Camera *camera, float *dx, float *dy)
{
    *dx = 0.0f;
    *dy = 0.0f;
    if (camera->shake_remaining <= 0.0f || camera->shake_amount <= 0.0f ||
        camera->shake_seconds <= 0.0f)
    {
        return;
    }
    const float falloff = camera->shake_remaining / camera->shake_seconds;
    const float scale = camera->shake_amount * falloff;
    *dx = ((float)SDL_randf() * 2.0f - 1.0f) * scale;
    *dy = ((float)SDL_randf() * 2.0f - 1.0f) * scale;
}

/* Top-left of the visible world, which is what world coordinates are
   measured from when drawing. */
static void Origin(const SDLStatic_Camera *camera, float *x, float *y)
{
    const float zoom = (camera->zoom > 0.0f) ? camera->zoom : 1.0f;
    *x = camera->x - (camera->viewport.w / zoom) * 0.5f;
    *y = camera->y - (camera->viewport.h / zoom) * 0.5f;
}

bool SDLStatic_CameraBegin(SDLStatic_Engine *engine, const SDLStatic_Camera *camera)
{
    SDL_Renderer *renderer = SDLStatic_EngineRenderer(engine);
    if (renderer == NULL || camera == NULL)
    {
        SDL_InvalidParamError("engine/camera");
        return false;
    }

    /* The viewport is in design coordinates, which is the space the game
       composed in — SDL applies the logical presentation on top. */
    const SDL_Rect viewport = {(int)(camera->viewport.x + 0.5f), (int)(camera->viewport.y + 0.5f),
                               (int)(camera->viewport.w + 0.5f),
                               (int)(camera->viewport.h + 0.5f)};
    if (!SDL_SetRenderViewport(renderer, &viewport))
    {
        return false;
    }
    /* Clip as well as set the viewport: a viewport alone offsets drawing
       but does not stop a sprite from spilling into the other player's
       half of a split screen. */
    const SDL_Rect clip = {0, 0, viewport.w, viewport.h};
    SDL_SetRenderClipRect(renderer, &clip);

    const float zoom = (camera->zoom > 0.0f) ? camera->zoom : 1.0f;
    SDL_SetRenderScale(renderer, zoom, zoom);
    return true;
}

void SDLStatic_CameraEnd(SDLStatic_Engine *engine)
{
    SDL_Renderer *renderer = SDLStatic_EngineRenderer(engine);
    if (renderer == NULL)
    {
        return;
    }
    SDL_SetRenderScale(renderer, 1.0f, 1.0f);
    SDL_SetRenderClipRect(renderer, NULL);
    SDL_SetRenderViewport(renderer, NULL);
}

void SDLStatic_CameraPoint(const SDLStatic_Camera *camera, float world_x, float world_y,
                           float *out_x, float *out_y)
{
    if (camera == NULL)
    {
        return;
    }
    float ox = 0.0f;
    float oy = 0.0f;
    Origin(camera, &ox, &oy);
    float sx = 0.0f;
    float sy = 0.0f;
    ShakeOffset(camera, &sx, &sy);
    /* Only the translation: the renderer is already scaled by the zoom, so
       scaling here as well would apply it twice. */
    if (out_x != NULL)
    {
        *out_x = world_x - ox - sx;
    }
    if (out_y != NULL)
    {
        *out_y = world_y - oy - sy;
    }
}

SDL_FRect SDLStatic_CameraRect(const SDLStatic_Camera *camera, SDL_FRect world)
{
    SDL_FRect out = world;
    SDLStatic_CameraPoint(camera, world.x, world.y, &out.x, &out.y);
    return out;
}

bool SDLStatic_CameraVisible(const SDLStatic_Camera *camera, SDL_FRect world)
{
    if (camera == NULL)
    {
        return false;
    }
    return SDL_HasRectIntersectionFloat(&world, &camera->visible);
}

bool SDLStatic_CameraScreenToWorld(const SDLStatic_Camera *camera, float screen_x, float screen_y,
                                   float *world_x, float *world_y)
{
    if (camera == NULL)
    {
        return false;
    }
    const SDL_FPoint point = {screen_x, screen_y};
    if (!SDL_PointInRectFloat(&point, &camera->viewport))
    {
        return false; /* another player's half */
    }
    float ox = 0.0f;
    float oy = 0.0f;
    Origin(camera, &ox, &oy);
    const float zoom = (camera->zoom > 0.0f) ? camera->zoom : 1.0f;
    if (world_x != NULL)
    {
        *world_x = (screen_x - camera->viewport.x) / zoom + ox;
    }
    if (world_y != NULL)
    {
        *world_y = (screen_y - camera->viewport.y) / zoom + oy;
    }
    return true;
}

/* --- split screen -------------------------------------------------------- */

int SDLStatic_CameraSplit(SDLStatic_Engine *engine, SDLStatic_SplitMode mode, int count,
                          float gap, SDLStatic_Camera *cameras)
{
    if (cameras == NULL)
    {
        SDL_InvalidParamError("cameras");
        return 0;
    }
    count = SDL_clamp(count, 1, SDLSTATIC_SPLIT_MAX);
    if (gap < 0.0f)
    {
        gap = 0.0f;
    }
    const SDL_FRect view = SDLStatic_EngineViewRect(engine);

    if (count == 1)
    {
        /* One player gets everything, so a game can run the same code path
           for one player and for four. */
        cameras[0].viewport = view;
        return 1;
    }

    if (mode == SDLSTATIC_SPLIT_GRID && count == 2)
    {
        mode = SDLSTATIC_SPLIT_HORIZONTAL; /* a 2-up grid is just a split */
    }

    if (mode == SDLSTATIC_SPLIT_GRID)
    {
        const float half_w = (view.w - gap) * 0.5f;
        const float half_h = (view.h - gap) * 0.5f;
        const float right = view.x + half_w + gap;
        const float bottom = view.y + half_h + gap;

        cameras[0].viewport = (SDL_FRect){view.x, view.y, half_w, half_h};
        cameras[1].viewport = (SDL_FRect){right, view.y, half_w, half_h};
        if (count == 3)
        {
            /* Three players: the third takes the whole bottom half rather
               than leaving an empty quadrant staring at everyone. */
            cameras[2].viewport = (SDL_FRect){view.x, bottom, view.w, half_h};
        }
        else
        {
            cameras[2].viewport = (SDL_FRect){view.x, bottom, half_w, half_h};
            cameras[3].viewport = (SDL_FRect){right, bottom, half_w, half_h};
        }
        return count;
    }

    const bool stacked = (mode == SDLSTATIC_SPLIT_HORIZONTAL);
    const float total = stacked ? view.h : view.w;
    const float each = (total - gap * (float)(count - 1)) / (float)count;
    for (int i = 0; i < count; ++i)
    {
        const float offset = (each + gap) * (float)i;
        if (stacked)
        {
            cameras[i].viewport = (SDL_FRect){view.x, view.y + offset, view.w, each};
        }
        else
        {
            cameras[i].viewport = (SDL_FRect){view.x + offset, view.y, each, view.h};
        }
    }
    return count;
}
