/*
 * sdlstatic_engine_target.c — the offscreen frame.
 * Original SDLStatic code (zlib).
 *
 * Render scale draws the frame at a fraction of the window's resolution and
 * lets the display scale it up, which needs somewhere to draw it — this
 * file is that somewhere.
 *
 * A game at render_scale 1.0 pays nothing: Begin and End do nothing at all
 * and the loop draws directly to the window exactly as it did before this
 * file existed. Post-processing is separate: it copies the finished frame
 * out of the framebuffer, so it works with or without a target here.
 *
 * The logical presentation is the subtle part. SDL applies it to whatever
 * the current render target is, so pointing the renderer at a texture of a
 * different size would silently change the scale the game draws at. The
 * target is therefore created at the *pixel* size the frame would have had,
 * scaled — and the logical presentation is re-applied against it, so design
 * coordinates keep meaning the same thing whatever the render scale is.
 */
#include "engine_internal.h"

/* Below this, the difference is not worth a texture and a blit. */
#define SCALE_EPSILON 0.001f

/* Only render scale needs the offscreen frame. Post-processing reads the
   framebuffer directly, so it does not. */
static bool WantsTarget(const SDLStatic_Engine *engine)
{
    return SDL_fabsf(engine->graphics.render_scale - 1.0f) > SCALE_EPSILON;
}

static bool EnsureTarget(SDLStatic_Engine *engine, int width, int height)
{
    if (engine->frame_target != NULL && engine->frame_target_w == width &&
        engine->frame_target_h == height)
    {
        return true;
    }
    if (engine->frame_target != NULL)
    {
        SDL_DestroyTexture(engine->frame_target);
        engine->frame_target = NULL;
    }
    /* An 8-bit target is enough for a 2D game and is the one format every
       backend supports as a render target. */
    engine->frame_target = SDL_CreateTexture(engine->renderer, SDL_PIXELFORMAT_RGBA8888,
                                             SDL_TEXTUREACCESS_TARGET, width, height);
    if (engine->frame_target == NULL)
    {
        return false;
    }
    engine->frame_target_w = width;
    engine->frame_target_h = height;
    /* Linear, so a 0.75-scale frame does not come back blocky. The game's
       own filter setting applies to its textures, not to this blit. */
    SDL_SetTextureScaleMode(engine->frame_target, SDL_SCALEMODE_LINEAR);
    return true;
}

void SDLStatic_EngineBeginFrameTarget(SDLStatic_Engine *engine)
{
    engine->frame_target_active = false;
    if (engine->renderer == NULL || !WantsTarget(engine))
    {
        return;
    }

    int pixel_w = 0;
    int pixel_h = 0;
    if (!SDL_GetRenderOutputSize(engine->renderer, &pixel_w, &pixel_h) || pixel_w <= 0 ||
        pixel_h <= 0)
    {
        return;
    }

    const float scale = engine->graphics.render_scale;
    int target_w = (int)((float)pixel_w * scale + 0.5f);
    int target_h = (int)((float)pixel_h * scale + 0.5f);
    if (target_w < 1)
    {
        target_w = 1;
    }
    if (target_h < 1)
    {
        target_h = 1;
    }

    if (!EnsureTarget(engine, target_w, target_h))
    {
        return; /* out of texture memory: draw to the window and carry on */
    }

    if (!SDL_SetRenderTarget(engine->renderer, engine->frame_target))
    {
        return;
    }
    engine->frame_target_active = true;

    /* Re-apply the logical presentation against the target. Without this
       the game would draw into a 1440x810 texture at the scale worked out
       for a 1920x1080 window, and everything would be a quarter too big. */
    SDL_SetRenderLogicalPresentation(engine->renderer, (int)(engine->view_width + 0.5f),
                                     (int)(engine->view_height + 0.5f),
                                     (engine->presentation == SDLSTATIC_PRESENT_NATIVE)
                                         ? SDL_LOGICAL_PRESENTATION_DISABLED
                                         : SDL_LOGICAL_PRESENTATION_LETTERBOX);
}

void SDLStatic_EngineEndFrameTarget(SDLStatic_Engine *engine)
{
    if (engine == NULL || engine->renderer == NULL)
    {
        return;
    }

    if (engine->frame_target_active && engine->frame_target != NULL)
    {
        engine->frame_target_active = false;
        SDL_SetRenderTarget(engine->renderer, NULL);
        /* Blit in window pixels, not design coordinates: this is the one
           draw in the frame that is about the display rather than the
           game. */
        SDL_SetRenderLogicalPresentation(engine->renderer, 0, 0,
                                         SDL_LOGICAL_PRESENTATION_DISABLED);
        SDL_SetRenderDrawBlendMode(engine->renderer, SDL_BLENDMODE_NONE);
        SDL_RenderTexture(engine->renderer, engine->frame_target, NULL, NULL);

        /* Put the presentation back, so anything drawn after this — a debug
           overlay, the next frame — sees the coordinates it expects. */
        SDLStatic_EngineSetPresentation(engine, engine->presentation);
    }

    /* The chain runs over whatever is now in the framebuffer, which is the
       upscaled frame if there was a target and the frame itself if not. */
    SDLStatic_EnginePostFXPresent(engine);
}

void SDLStatic_EngineDestroyFrameTarget(SDLStatic_Engine *engine)
{
    if (engine == NULL)
    {
        return;
    }
    if (engine->frame_target != NULL)
    {
        SDL_DestroyTexture(engine->frame_target);
        engine->frame_target = NULL;
    }
    engine->frame_target_w = 0;
    engine->frame_target_h = 0;
}
