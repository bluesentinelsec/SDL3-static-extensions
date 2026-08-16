/*
 * sdlstatic_engine_render.c — the draw list.
 * Original SDLStatic code (zlib).
 *
 * Gather, cull, sort, draw. In that order, and the order matters: culling
 * before sorting means the sort only handles what is actually going to be
 * drawn, which on a large level is the difference between sorting sixty
 * sprites and sorting four thousand.
 *
 * The draw list is a scratch buffer on the engine, grown once and reused,
 * because this runs every frame — possibly four times a frame in split
 * screen — and a renderer that allocates per frame is a renderer that
 * stutters when the allocator is having a bad day.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_render.h>

SDLStatic_Sprite SDLStatic_SpriteDefault(void)
{
    SDLStatic_Sprite sprite;
    SDL_zero(sprite);
    /* Everything a zero-initialised sprite would get wrong: it would be
       invisible, fully transparent, and pinned by its top-left corner. */
    sprite.color = (SDL_FColor){1.0f, 1.0f, 1.0f, 1.0f};
    sprite.origin_x = 0.5f;
    sprite.origin_y = 0.5f;
    sprite.visible = true;
    sprite.flip = SDL_FLIP_NONE;
    return sprite;
}

bool SDLStatic_ActorSetSprite(SDLStatic_Actor *actor, const SDLStatic_Sprite *sprite)
{
    if (actor == NULL || sprite == NULL)
    {
        SDL_InvalidParamError("actor/sprite");
        return false;
    }
    SDLStatic_Sprite *slot = SDLStatic_ActorSpriteSlot(actor, true);
    if (slot == NULL)
    {
        return false;
    }
    *slot = *sprite;
    return true;
}

SDLStatic_Sprite *SDLStatic_ActorSprite(SDLStatic_Actor *actor)
{
    return SDLStatic_ActorSpriteSlot(actor, false);
}

void SDLStatic_ActorClearSprite(SDLStatic_Actor *actor)
{
    SDLStatic_ActorSpriteRemove(actor);
}

/* --- the draw list ------------------------------------------------------- */

typedef struct SDLStatic_DrawItem
{
    SDLStatic_Actor *actor;
    const SDLStatic_Sprite *sprite;
    SDLStatic_ActorTransform transform;
    SDL_FRect destination; /* world units, already origin-adjusted */
    int layer;
    float order;
    Uint64 id; /* the tiebreaker: see CompareItems */
} DrawItem;


static bool ReserveList(SDLStatic_Engine *engine, int needed)
{
    if (engine->draw_capacity >= needed)
    {
        return true;
    }
    int next = (engine->draw_capacity > 0) ? engine->draw_capacity * 2 : 64;
    while (next < needed)
    {
        next *= 2;
    }
    DrawItem *grown = (DrawItem *)SDL_realloc(engine->draw_list, (size_t)next * sizeof(DrawItem));
    if (grown == NULL)
    {
        return false;
    }
    engine->draw_list = grown;
    engine->draw_capacity = next;
    return true;
}

/*
 * Layer first, then order (or world Y), then the actor id.
 *
 * The id tiebreak is not decoration. Without it, two sprites on the same
 * layer at the same depth swap places whenever the sort happens to run
 * differently — a flicker that appears only when two things overlap, which
 * is exactly when somebody is looking. Sorting by a stable key makes the
 * order arbitrary but *consistent*, and consistent is what the eye needs.
 */
static int SDLCALL CompareItems(void *unused, const void *lhs, const void *rhs)
{
    (void)unused;
    const DrawItem *a = (const DrawItem *)lhs;
    const DrawItem *b = (const DrawItem *)rhs;

    if (a->layer != b->layer)
    {
        return (a->layer < b->layer) ? -1 : 1;
    }
    if (a->order != b->order)
    {
        return (a->order < b->order) ? -1 : 1;
    }
    if (a->id != b->id)
    {
        return (a->id < b->id) ? -1 : 1;
    }
    return 0;
}

/* The rectangle a sprite occupies in world units, before rotation. */
static SDL_FRect SpriteRect(const SDLStatic_Sprite *sprite,
                            const SDLStatic_ActorTransform *transform)
{
    float w = sprite->width;
    float h = sprite->height;
    if (w <= 0.0f || h <= 0.0f)
    {
        /* Fall back to the source rectangle, then to the texture, so a
           sprite drawn at its natural size needs no numbers at all. */
        float texture_w = 0.0f;
        float texture_h = 0.0f;
        if (sprite->texture != NULL)
        {
            SDL_GetTextureSize(sprite->texture, &texture_w, &texture_h);
        }
        const float source_w = (sprite->source.w > 0.0f) ? sprite->source.w : texture_w;
        const float source_h = (sprite->source.h > 0.0f) ? sprite->source.h : texture_h;
        if (w <= 0.0f)
        {
            w = source_w;
        }
        if (h <= 0.0f)
        {
            h = source_h;
        }
    }

    w *= transform->scale_x;
    h *= transform->scale_y;

    SDL_FRect rect;
    rect.w = w;
    rect.h = h;
    rect.x = transform->x - w * sprite->origin_x;
    rect.y = transform->y - h * sprite->origin_y;
    return rect;
}

/* A rotated sprite sweeps a bigger area than its rectangle, so culling
   against the unrotated one would clip things at the screen edge as they
   turned. The circumscribed square is cheap and never wrong. */
static SDL_FRect CullBounds(const SDL_FRect *rect, float rotation)
{
    if (rotation == 0.0f)
    {
        return *rect;
    }
    const float diagonal = SDL_sqrtf(rect->w * rect->w + rect->h * rect->h);
    SDL_FRect bounds;
    bounds.x = rect->x + rect->w * 0.5f - diagonal * 0.5f;
    bounds.y = rect->y + rect->h * 0.5f - diagonal * 0.5f;
    bounds.w = diagonal;
    bounds.h = diagonal;
    return bounds;
}

struct GatherContext
{
    SDLStatic_Engine *engine;
    const SDLStatic_Camera *camera;
    float alpha;
    bool screen_space;
    int count;
};

static bool GatherOne(SDLStatic_Actor *actor, void *user)
{
    struct GatherContext *ctx = (struct GatherContext *)user;
    const SDLStatic_Sprite *sprite = SDLStatic_ActorSpriteSlot(actor, false);
    if (sprite == NULL || !sprite->visible || sprite->screen_space != ctx->screen_space)
    {
        return true;
    }
    ctx->engine->render_stats.considered++;

    const SDLStatic_ActorTransform transform = SDLStatic_ActorRenderTransform(actor, ctx->alpha);
    const SDL_FRect rect = SpriteRect(sprite, &transform);

    if (ctx->camera != NULL)
    {
        const SDL_FRect bounds = CullBounds(&rect, transform.rotation);
        if (!SDLStatic_CameraVisible(ctx->camera, bounds))
        {
            ctx->engine->render_stats.culled++;
            return true;
        }
    }

    if (!ReserveList(ctx->engine, ctx->count + 1))
    {
        return false;
    }
    DrawItem *item = &ctx->engine->draw_list[ctx->count++];
    item->actor = actor;
    item->sprite = sprite;
    item->transform = transform;
    item->destination = rect;
    item->layer = sprite->layer;
    /* Y-sorting uses the actor's position rather than the rectangle's top,
       so a tall sprite and a short one standing on the same ground sort by
       where they are standing, not by how tall they are. */
    item->order = sprite->sort_by_y ? transform.y : sprite->order;
    item->id = SDLStatic_ActorGetId(actor);
    return true;
}

static void DrawItems(SDLStatic_Engine *engine, const DrawItem *items, int count,
                      const SDLStatic_Camera *camera)
{
    SDL_Renderer *renderer = engine->renderer;
    for (int i = 0; i < count; ++i)
    {
        const DrawItem *item = &items[i];
        const SDLStatic_Sprite *sprite = item->sprite;

        SDL_FRect destination = item->destination;
        if (camera != NULL)
        {
            /* Translate only: the renderer is already scaled by the zoom,
               so scaling here as well would apply it twice. */
            SDLStatic_CameraPoint(camera, destination.x, destination.y, &destination.x,
                                  &destination.y);
        }

        if (sprite->texture == NULL)
        {
            /* No texture: a solid rectangle. How a game gets something on
               screen before it has any art. */
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            SDL_SetRenderDrawColorFloat(renderer, sprite->color.r, sprite->color.g,
                                        sprite->color.b, sprite->color.a);
            SDL_RenderFillRect(renderer, &destination);
            continue;
        }

        SDL_SetTextureColorModFloat(sprite->texture, sprite->color.r, sprite->color.g,
                                    sprite->color.b);
        SDL_SetTextureAlphaModFloat(sprite->texture, sprite->color.a);

        const SDL_FRect *source = NULL;
        if (sprite->source.w > 0.0f && sprite->source.h > 0.0f)
        {
            source = &sprite->source;
        }

        if (item->transform.rotation != 0.0f || sprite->flip != SDL_FLIP_NONE)
        {
            /* Rotate about the origin the sprite declared, not about the
               middle of the rectangle — otherwise a sprite pinned at its
               feet swings around its waist. */
            const SDL_FPoint centre = {destination.w * sprite->origin_x,
                                       destination.h * sprite->origin_y};
            SDL_RenderTextureRotated(renderer, sprite->texture, source, &destination,
                                     (double)item->transform.rotation, &centre, sprite->flip);
        }
        else
        {
            SDL_RenderTexture(renderer, sprite->texture, source, &destination);
        }
    }
}

static int RenderPass(SDLStatic_Engine *engine, const SDLStatic_Camera *camera, float alpha,
                      bool screen_space)
{
    if (engine == NULL || engine->renderer == NULL)
    {
        return 0;
    }
    SDL_zero(engine->render_stats);

    struct GatherContext ctx;
    ctx.engine = engine;
    ctx.camera = camera;
    ctx.alpha = alpha;
    ctx.screen_space = screen_space;
    ctx.count = 0;
    SDLStatic_ActorEach(engine, GatherOne, &ctx);

    if (ctx.count > 1)
    {
        SDL_qsort_r(engine->draw_list, (size_t)ctx.count, sizeof(DrawItem), CompareItems, NULL);
    }

    if (camera != NULL && !SDLStatic_CameraBegin(engine, camera))
    {
        return 0;
    }
    DrawItems(engine, engine->draw_list, ctx.count, camera);
    if (camera != NULL)
    {
        SDLStatic_CameraEnd(engine);
    }

    engine->render_stats.drawn = ctx.count;
    return ctx.count;
}

int SDLStatic_RenderWorld(SDLStatic_Engine *engine, const SDLStatic_Camera *camera, float alpha)
{
    return RenderPass(engine, camera, alpha, false);
}

int SDLStatic_RenderOverlay(SDLStatic_Engine *engine, float alpha)
{
    /* No camera: design coordinates, drawn once however many views there
       are, because a HUD belongs to the player and not to a viewport. */
    return RenderPass(engine, NULL, alpha, true);
}

SDLStatic_RenderStats SDLStatic_RenderLastStats(SDLStatic_Engine *engine)
{
    SDLStatic_RenderStats empty;
    SDL_zero(empty);
    return (engine != NULL) ? engine->render_stats : empty;
}

void SDLStatic_RenderDestroy(SDLStatic_Engine *engine)
{
    if (engine == NULL)
    {
        return;
    }
    SDL_free(engine->draw_list);
    engine->draw_list = NULL;
    engine->draw_capacity = 0;
}
