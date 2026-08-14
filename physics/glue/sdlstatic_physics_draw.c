/*
 * sdlstatic_physics_draw.c — b2DebugDraw over SDLStatic::Gfx GPU primitives.
 *
 * Original SDLStatic code (zlib). World coordinates are meters with +y up;
 * screen coordinates flip y and scale by pixels_per_meter around the
 * configured origin.
 */
#include <SDLStatic/gpu_primitives.h>
#include <SDLStatic/physics_draw.h>

typedef struct DrawCtx
{
    SDL_Renderer *renderer;
    float scale;
    float ox;
    float oy;
} DrawCtx;

static Sint16 ScreenX(const DrawCtx *ctx, float wx)
{
    return (Sint16)SDL_lroundf(ctx->ox + wx * ctx->scale);
}

static Sint16 ScreenY(const DrawCtx *ctx, float wy)
{
    return (Sint16)SDL_lroundf(ctx->oy - wy * ctx->scale);
}

static void SplitColor(b2HexColor color, Uint8 *r, Uint8 *g, Uint8 *b)
{
    *r = (Uint8)((color >> 16) & 0xff);
    *g = (Uint8)((color >> 8) & 0xff);
    *b = (Uint8)(color & 0xff);
}

#define MAX_POLY_VERTS 16 /* Box2D polygons max out at B2_MAX_POLYGON_VERTICES (8) */

static void DrawPolygonCb(const b2Vec2 *vertices, int vertexCount, b2HexColor color,
                          void *context)
{
    const DrawCtx *ctx = (const DrawCtx *)context;
    Sint16 vx[MAX_POLY_VERTS];
    Sint16 vy[MAX_POLY_VERTS];
    const int n = SDL_min(vertexCount, MAX_POLY_VERTS);
    for (int i = 0; i < n; ++i)
    {
        vx[i] = ScreenX(ctx, vertices[i].x);
        vy[i] = ScreenY(ctx, vertices[i].y);
    }
    Uint8 r, g, b;
    SplitColor(color, &r, &g, &b);
    gpuPolygonRGBA(ctx->renderer, vx, vy, n, r, g, b, 255);
}

static void DrawSolidPolygonCb(b2Transform transform, const b2Vec2 *vertices, int vertexCount,
                               float radius, b2HexColor color, void *context)
{
    (void)radius; /* rounded polygons draw with sharp corners in the overlay */
    const DrawCtx *ctx = (const DrawCtx *)context;
    Sint16 vx[MAX_POLY_VERTS];
    Sint16 vy[MAX_POLY_VERTS];
    const int n = SDL_min(vertexCount, MAX_POLY_VERTS);
    for (int i = 0; i < n; ++i)
    {
        const b2Vec2 world = b2TransformPoint(transform, vertices[i]);
        vx[i] = ScreenX(ctx, world.x);
        vy[i] = ScreenY(ctx, world.y);
    }
    Uint8 r, g, b;
    SplitColor(color, &r, &g, &b);
    gpuFilledPolygonRGBA(ctx->renderer, vx, vy, n, r, g, b, 160);
    gpuPolygonRGBA(ctx->renderer, vx, vy, n, r, g, b, 255);
}

static void DrawCircleCb(b2Vec2 center, float radius, b2HexColor color, void *context)
{
    const DrawCtx *ctx = (const DrawCtx *)context;
    Uint8 r, g, b;
    SplitColor(color, &r, &g, &b);
    gpuCircleRGBA(ctx->renderer, ScreenX(ctx, center.x), ScreenY(ctx, center.y),
                  (Sint16)SDL_lroundf(radius * ctx->scale), r, g, b, 255);
}

static void DrawSolidCircleCb(b2Transform transform, float radius, b2HexColor color,
                              void *context)
{
    const DrawCtx *ctx = (const DrawCtx *)context;
    Uint8 r, g, b;
    SplitColor(color, &r, &g, &b);
    const Sint16 cx = ScreenX(ctx, transform.p.x);
    const Sint16 cy = ScreenY(ctx, transform.p.y);
    const Sint16 sr = (Sint16)SDL_lroundf(radius * ctx->scale);
    gpuFilledCircleRGBA(ctx->renderer, cx, cy, sr, r, g, b, 160);
    gpuCircleRGBA(ctx->renderer, cx, cy, sr, r, g, b, 255);
    /* Radius line shows rotation. */
    const b2Vec2 edge = b2TransformPoint(transform, (b2Vec2){radius, 0.0f});
    gpuLineRGBA(ctx->renderer, cx, cy, ScreenX(ctx, edge.x), ScreenY(ctx, edge.y), r, g, b, 255);
}

static void DrawSolidCapsuleCb(b2Vec2 p1, b2Vec2 p2, float radius, b2HexColor color,
                               void *context)
{
    const DrawCtx *ctx = (const DrawCtx *)context;
    Uint8 r, g, b;
    SplitColor(color, &r, &g, &b);
    const Sint16 sr = (Sint16)SDL_lroundf(radius * ctx->scale);
    gpuFilledCircleRGBA(ctx->renderer, ScreenX(ctx, p1.x), ScreenY(ctx, p1.y), sr, r, g, b, 160);
    gpuFilledCircleRGBA(ctx->renderer, ScreenX(ctx, p2.x), ScreenY(ctx, p2.y), sr, r, g, b, 160);
    const Uint8 width = (Uint8)SDL_clamp(2 * sr, 1, 255);
    gpuThickLineRGBA(ctx->renderer, ScreenX(ctx, p1.x), ScreenY(ctx, p1.y), ScreenX(ctx, p2.x),
                     ScreenY(ctx, p2.y), width, r, g, b, 160);
}

static void DrawSegmentCb(b2Vec2 p1, b2Vec2 p2, b2HexColor color, void *context)
{
    const DrawCtx *ctx = (const DrawCtx *)context;
    Uint8 r, g, b;
    SplitColor(color, &r, &g, &b);
    gpuLineRGBA(ctx->renderer, ScreenX(ctx, p1.x), ScreenY(ctx, p1.y), ScreenX(ctx, p2.x),
                ScreenY(ctx, p2.y), r, g, b, 255);
}

static void DrawTransformCb(b2Transform transform, void *context)
{
    const DrawCtx *ctx = (const DrawCtx *)context;
    const float axis = 0.5f;
    const b2Vec2 px = b2TransformPoint(transform, (b2Vec2){axis, 0.0f});
    const b2Vec2 py = b2TransformPoint(transform, (b2Vec2){0.0f, axis});
    const Sint16 cx = ScreenX(ctx, transform.p.x);
    const Sint16 cy = ScreenY(ctx, transform.p.y);
    gpuLineRGBA(ctx->renderer, cx, cy, ScreenX(ctx, px.x), ScreenY(ctx, px.y), 255, 0, 0, 255);
    gpuLineRGBA(ctx->renderer, cx, cy, ScreenX(ctx, py.x), ScreenY(ctx, py.y), 0, 255, 0, 255);
}

static void DrawPointCb(b2Vec2 p, float size, b2HexColor color, void *context)
{
    const DrawCtx *ctx = (const DrawCtx *)context;
    Uint8 r, g, b;
    SplitColor(color, &r, &g, &b);
    gpuFilledCircleRGBA(ctx->renderer, ScreenX(ctx, p.x), ScreenY(ctx, p.y),
                        (Sint16)SDL_max(1, SDL_lroundf(size * 0.5f)), r, g, b, 255);
}

static void DrawStringCb(b2Vec2 p, const char *s, b2HexColor color, void *context)
{
    /* Text overlays belong to the TTF extension; ignore in the shape overlay. */
    (void)p;
    (void)s;
    (void)color;
    (void)context;
}

bool SDLStatic_DrawPhysicsWorld(b2WorldId world, SDL_Renderer *renderer,
                                const SDLStatic_PhysicsDrawConfig *config)
{
    if (renderer == NULL || config == NULL)
    {
        return SDL_InvalidParamError("renderer/config");
    }
    if (!b2World_IsValid(world))
    {
        return SDL_SetError("invalid Box2D world");
    }
    DrawCtx ctx;
    ctx.renderer = renderer;
    ctx.scale = (config->pixels_per_meter > 0.0f) ? config->pixels_per_meter : 32.0f;
    ctx.ox = config->offset_x;
    ctx.oy = config->offset_y;

    b2DebugDraw draw = b2DefaultDebugDraw();
    draw.DrawPolygonFcn = DrawPolygonCb;
    draw.DrawSolidPolygonFcn = DrawSolidPolygonCb;
    draw.DrawCircleFcn = DrawCircleCb;
    draw.DrawSolidCircleFcn = DrawSolidCircleCb;
    draw.DrawSolidCapsuleFcn = DrawSolidCapsuleCb;
    draw.DrawSegmentFcn = DrawSegmentCb;
    draw.DrawTransformFcn = DrawTransformCb;
    draw.DrawPointFcn = DrawPointCb;
    draw.DrawStringFcn = DrawStringCb;
    draw.drawShapes = true;
    draw.drawJoints = config->draw_joints;
    draw.context = &ctx;

    b2World_Draw(world, &draw);
    return true;
}
