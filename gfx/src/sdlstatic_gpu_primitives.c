/*
 * sdlstatic_gpu_primitives.c — GPU-bound gfx primitives via SDL_RenderGeometry.
 *
 * Original SDLStatic code (zlib). Every primitive tessellates to triangles
 * and issues exactly one SDL_RenderGeometry call. See SDLStatic/gpu_primitives.h.
 */
#include <SDLStatic/gpu_primitives.h>

/* Hairline strokes render at 1.5px: exact-1px quads lose pixels to integer
 * vertex snapping in SDL's software rasterizer, and 1.5px survives every
 * backend while still reading as a thin line. */
#define HAIRLINE 1.5f

static SDL_FColor MakeColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    const SDL_FColor c = {(float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f,
                          (float)a / 255.0f};
    return c;
}

static bool Submit(SDL_Renderer *renderer, Uint8 alpha, const SDL_Vertex *verts, int num_verts,
                   const int *indices, int num_indices)
{
    if (renderer == NULL)
    {
        return SDL_InvalidParamError("renderer");
    }
    /* Match the CPU primitives: blend only when the color has translucency. */
    if (!SDL_SetRenderDrawBlendMode(renderer,
                                    (alpha == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND))
    {
        return false;
    }
    return SDL_RenderGeometry(renderer, NULL, verts, num_verts, indices, num_indices);
}

/* Quad helper: writes 4 vertices + 6 indices for corners in any order
 * (a,b,c,d go around the quad). */
static void WriteQuad(SDL_Vertex *verts, int *indices, int base, SDL_FPoint a, SDL_FPoint b,
                      SDL_FPoint c, SDL_FPoint d, SDL_FColor color)
{
    const SDL_FPoint zero = {0.0f, 0.0f};
    verts[base + 0].position = a;
    verts[base + 1].position = b;
    verts[base + 2].position = c;
    verts[base + 3].position = d;
    for (int i = 0; i < 4; ++i)
    {
        verts[base + i].color = color;
        verts[base + i].tex_coord = zero;
    }
    int *ix = indices + (base / 4) * 6;
    ix[0] = base + 0;
    ix[1] = base + 1;
    ix[2] = base + 2;
    ix[3] = base + 0;
    ix[4] = base + 2;
    ix[5] = base + 3;
}

/* Oriented thick segment from p1 to p2. */
static void WriteSegment(SDL_Vertex *verts, int *indices, int base, float x1, float y1, float x2,
                         float y2, float width, SDL_FColor color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    const float len = SDL_sqrtf(dx * dx + dy * dy);
    if (len < 0.0001f)
    {
        dx = 1.0f;
        dy = 0.0f;
    }
    else
    {
        dx /= len;
        dy /= len;
    }
    const float px = -dy * width * 0.5f;
    const float py = dx * width * 0.5f;
    const SDL_FPoint a = {x1 + px, y1 + py};
    const SDL_FPoint b = {x2 + px, y2 + py};
    const SDL_FPoint c = {x2 - px, y2 - py};
    const SDL_FPoint d = {x1 - px, y1 - py};
    WriteQuad(verts, indices, base, a, b, c, d, color);
}

/* ------------------------------------------------------ pixels/lines --- */

bool gpuThickLineRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                      Uint8 width, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (width < 1)
    {
        return SDL_InvalidParamError("width");
    }
    SDL_Vertex verts[4];
    int indices[6];
    /* +0.5 centers the quad on pixel centers, matching CPU line coverage. */
    WriteSegment(verts, indices, 0, (float)x1 + 0.5f, (float)y1 + 0.5f, (float)x2 + 0.5f,
                 (float)y2 + 0.5f, SDL_max((float)width, HAIRLINE), MakeColor(r, g, b, a));
    return Submit(renderer, a, verts, 4, indices, 6);
}

bool gpuLineRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                 Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    return gpuThickLineRGBA(renderer, x1, y1, x2, y2, 1, r, g, b, a);
}

bool gpuPixelRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Vertex verts[4];
    int indices[6];
    const SDL_FPoint p0 = {(float)x, (float)y};
    const SDL_FPoint p1 = {(float)x + 1.0f, (float)y};
    const SDL_FPoint p2 = {(float)x + 1.0f, (float)y + 1.0f};
    const SDL_FPoint p3 = {(float)x, (float)y + 1.0f};
    WriteQuad(verts, indices, 0, p0, p1, p2, p3, MakeColor(r, g, b, a));
    return Submit(renderer, a, verts, 4, indices, 6);
}

bool gpuHlineRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 x2, Sint16 y,
                  Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    return gpuLineRGBA(renderer, x1, y, x2, y, r, g, b, a);
}

bool gpuVlineRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y1, Sint16 y2,
                  Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    return gpuLineRGBA(renderer, x, y1, x, y2, r, g, b, a);
}

/* -------------------------------------------------------- rectangles --- */

bool gpuBoxRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (x1 > x2)
    {
        const Sint16 t = x1;
        x1 = x2;
        x2 = t;
    }
    if (y1 > y2)
    {
        const Sint16 t = y1;
        y1 = y2;
        y2 = t;
    }
    SDL_Vertex verts[4];
    int indices[6];
    /* CPU boxRGBA fills coordinates inclusively: cover [x1, x2+1). */
    const SDL_FPoint p0 = {(float)x1, (float)y1};
    const SDL_FPoint p1 = {(float)x2 + 1.0f, (float)y1};
    const SDL_FPoint p2 = {(float)x2 + 1.0f, (float)y2 + 1.0f};
    const SDL_FPoint p3 = {(float)x1, (float)y2 + 1.0f};
    WriteQuad(verts, indices, 0, p0, p1, p2, p3, MakeColor(r, g, b, a));
    return Submit(renderer, a, verts, 4, indices, 6);
}

bool gpuRectangleRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                      Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Vertex verts[16];
    int indices[24];
    const SDL_FColor color = MakeColor(r, g, b, a);
    const float fx1 = (float)SDL_min(x1, x2);
    const float fy1 = (float)SDL_min(y1, y2);
    const float fx2 = (float)SDL_max(x1, x2) + 1.0f;
    const float fy2 = (float)SDL_max(y1, y2) + 1.0f;
    const SDL_FPoint t0 = {fx1, fy1}, t1 = {fx2, fy1}, t2 = {fx2, fy1 + 1}, t3 = {fx1, fy1 + 1};
    const SDL_FPoint b0 = {fx1, fy2 - 1}, b1 = {fx2, fy2 - 1}, b2 = {fx2, fy2}, b3 = {fx1, fy2};
    const SDL_FPoint l0 = {fx1, fy1 + 1}, l1 = {fx1 + 1, fy1 + 1}, l2 = {fx1 + 1, fy2 - 1},
                     l3 = {fx1, fy2 - 1};
    const SDL_FPoint r0 = {fx2 - 1, fy1 + 1}, r1 = {fx2, fy1 + 1}, r2 = {fx2, fy2 - 1},
                     r3 = {fx2 - 1, fy2 - 1};
    WriteQuad(verts, indices, 0, t0, t1, t2, t3, color);
    WriteQuad(verts, indices, 4, b0, b1, b2, b3, color);
    WriteQuad(verts, indices, 8, l0, l1, l2, l3, color);
    WriteQuad(verts, indices, 12, r0, r1, r2, r3, color);
    return Submit(renderer, a, verts, 16, indices, 24);
}

/* Rounded-rect contour points (clockwise), rad clamped to half extents. */
static int RoundedContour(SDL_FPoint *pts, int max_pts, float x1, float y1, float x2, float y2,
                          float rad)
{
    const float w = x2 - x1;
    const float h = y2 - y1;
    rad = SDL_min(rad, SDL_min(w, h) * 0.5f);
    const int corner_segs = SDL_clamp((int)(rad * 0.8f) + 3, 3, 48);
    const struct
    {
        float cx, cy, start;
    } corners[4] = {
        {x2 - rad, y1 + rad, -90.0f}, /* top-right */
        {x2 - rad, y2 - rad, 0.0f},   /* bottom-right */
        {x1 + rad, y2 - rad, 90.0f},  /* bottom-left */
        {x1 + rad, y1 + rad, 180.0f}, /* top-left */
    };
    int n = 0;
    for (int c = 0; c < 4 && n < max_pts; ++c)
    {
        for (int s = 0; s <= corner_segs && n < max_pts; ++s)
        {
            const float deg = corners[c].start + 90.0f * (float)s / (float)corner_segs;
            const float rd = deg * SDL_PI_F / 180.0f;
            pts[n].x = corners[c].cx + SDL_cosf(rd) * rad;
            pts[n].y = corners[c].cy + SDL_sinf(rd) * rad;
            n++;
        }
    }
    return n;
}

/* Fill a convex contour by fanning around its centroid. */
static bool FillConvexContour(SDL_Renderer *renderer, const SDL_FPoint *pts, int n,
                              Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    const SDL_FColor color = MakeColor(r, g, b, a);
    SDL_Vertex *verts = (SDL_Vertex *)SDL_malloc(sizeof(SDL_Vertex) * (size_t)(n + 1));
    int *indices = (int *)SDL_malloc(sizeof(int) * (size_t)n * 3);
    if (verts == NULL || indices == NULL)
    {
        SDL_free(verts);
        SDL_free(indices);
        return false;
    }
    SDL_FPoint center = {0.0f, 0.0f};
    for (int i = 0; i < n; ++i)
    {
        center.x += pts[i].x;
        center.y += pts[i].y;
    }
    center.x /= (float)n;
    center.y /= (float)n;
    const SDL_FPoint zero = {0.0f, 0.0f};
    verts[0].position = center;
    verts[0].color = color;
    verts[0].tex_coord = zero;
    for (int i = 0; i < n; ++i)
    {
        verts[i + 1].position = pts[i];
        verts[i + 1].color = color;
        verts[i + 1].tex_coord = zero;
        indices[i * 3 + 0] = 0;
        indices[i * 3 + 1] = i + 1;
        indices[i * 3 + 2] = (i + 1) % n + 1;
    }
    const bool ok = Submit(renderer, a, verts, n + 1, indices, n * 3);
    SDL_free(verts);
    SDL_free(indices);
    return ok;
}

/* Stroke a closed contour with 1px-wide segments in one draw. */
static bool StrokeContour(SDL_Renderer *renderer, const SDL_FPoint *pts, int n, bool close,
                          float width, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    const int segments = close ? n : (n - 1);
    if (segments < 1)
    {
        return SDL_InvalidParamError("n");
    }
    const SDL_FColor color = MakeColor(r, g, b, a);
    SDL_Vertex *verts = (SDL_Vertex *)SDL_malloc(sizeof(SDL_Vertex) * (size_t)segments * 4);
    int *indices = (int *)SDL_malloc(sizeof(int) * (size_t)segments * 6);
    if (verts == NULL || indices == NULL)
    {
        SDL_free(verts);
        SDL_free(indices);
        return false;
    }
    for (int i = 0; i < segments; ++i)
    {
        const SDL_FPoint p1 = pts[i];
        const SDL_FPoint p2 = pts[(i + 1) % n];
        WriteSegment(verts, indices, i * 4, p1.x, p1.y, p2.x, p2.y, width, color);
    }
    const bool ok = Submit(renderer, a, verts, segments * 4, indices, segments * 6);
    SDL_free(verts);
    SDL_free(indices);
    return ok;
}

#define MAX_CONTOUR 256

bool gpuRoundedBoxRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                       Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (rad < 0)
    {
        return SDL_InvalidParamError("rad");
    }
    SDL_FPoint pts[MAX_CONTOUR];
    const float fx1 = (float)SDL_min(x1, x2);
    const float fy1 = (float)SDL_min(y1, y2);
    const float fx2 = (float)SDL_max(x1, x2) + 1.0f;
    const float fy2 = (float)SDL_max(y1, y2) + 1.0f;
    const int n = RoundedContour(pts, MAX_CONTOUR, fx1, fy1, fx2, fy2, (float)rad);
    return FillConvexContour(renderer, pts, n, r, g, b, a);
}

bool gpuRoundedRectangleRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                             Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (rad < 0)
    {
        return SDL_InvalidParamError("rad");
    }
    SDL_FPoint pts[MAX_CONTOUR];
    const float fx1 = (float)SDL_min(x1, x2) + 0.5f;
    const float fy1 = (float)SDL_min(y1, y2) + 0.5f;
    const float fx2 = (float)SDL_max(x1, x2) + 0.5f;
    const float fy2 = (float)SDL_max(y1, y2) + 0.5f;
    const int n = RoundedContour(pts, MAX_CONTOUR, fx1, fy1, fx2, fy2, (float)rad);
    return StrokeContour(renderer, pts, n, true, HAIRLINE, r, g, b, a);
}

/* --------------------------------------- circles/ellipses/arcs/pies --- */

/* Annulus (ring) segment between angles, outer/inner radii, one draw. */
static bool RingSegment(SDL_Renderer *renderer, float cx, float cy, float rx_out, float ry_out,
                        float rx_in, float ry_in, float start_deg, float end_deg,
                        Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    const float span = end_deg - start_deg;
    const int segs = SDL_clamp((int)(SDL_max(rx_out, ry_out) * 1.2f * SDL_fabsf(span) / 360.0f) + 6,
                               6, 256);
    const SDL_FColor color = MakeColor(r, g, b, a);
    const int nv = (segs + 1) * 2;
    SDL_Vertex *verts = (SDL_Vertex *)SDL_malloc(sizeof(SDL_Vertex) * (size_t)nv);
    int *indices = (int *)SDL_malloc(sizeof(int) * (size_t)segs * 6);
    if (verts == NULL || indices == NULL)
    {
        SDL_free(verts);
        SDL_free(indices);
        return false;
    }
    const SDL_FPoint zero = {0.0f, 0.0f};
    for (int i = 0; i <= segs; ++i)
    {
        const float deg = start_deg + span * (float)i / (float)segs;
        const float rd = deg * SDL_PI_F / 180.0f;
        const float c = SDL_cosf(rd);
        const float s = SDL_sinf(rd);
        verts[i * 2 + 0].position.x = cx + c * rx_out;
        verts[i * 2 + 0].position.y = cy + s * ry_out;
        verts[i * 2 + 1].position.x = cx + c * rx_in;
        verts[i * 2 + 1].position.y = cy + s * ry_in;
        verts[i * 2 + 0].color = color;
        verts[i * 2 + 1].color = color;
        verts[i * 2 + 0].tex_coord = zero;
        verts[i * 2 + 1].tex_coord = zero;
    }
    for (int i = 0; i < segs; ++i)
    {
        int *ix = indices + i * 6;
        ix[0] = i * 2;
        ix[1] = i * 2 + 2;
        ix[2] = i * 2 + 1;
        ix[3] = i * 2 + 1;
        ix[4] = i * 2 + 2;
        ix[5] = i * 2 + 3;
    }
    const bool ok = Submit(renderer, a, verts, nv, indices, segs * 6);
    SDL_free(verts);
    SDL_free(indices);
    return ok;
}

/* Filled fan from center over an angle range (full disc when span=360). */
static bool CenterFan(SDL_Renderer *renderer, float cx, float cy, float rx, float ry,
                      float start_deg, float end_deg, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    const float span = end_deg - start_deg;
    const int segs = SDL_clamp((int)(SDL_max(rx, ry) * 1.2f * SDL_fabsf(span) / 360.0f) + 6,
                               6, 256);
    const SDL_FColor color = MakeColor(r, g, b, a);
    SDL_Vertex *verts = (SDL_Vertex *)SDL_malloc(sizeof(SDL_Vertex) * (size_t)(segs + 2));
    int *indices = (int *)SDL_malloc(sizeof(int) * (size_t)segs * 3);
    if (verts == NULL || indices == NULL)
    {
        SDL_free(verts);
        SDL_free(indices);
        return false;
    }
    const SDL_FPoint zero = {0.0f, 0.0f};
    verts[0].position.x = cx;
    verts[0].position.y = cy;
    verts[0].color = color;
    verts[0].tex_coord = zero;
    for (int i = 0; i <= segs; ++i)
    {
        const float deg = start_deg + span * (float)i / (float)segs;
        const float rd = deg * SDL_PI_F / 180.0f;
        verts[i + 1].position.x = cx + SDL_cosf(rd) * rx;
        verts[i + 1].position.y = cy + SDL_sinf(rd) * ry;
        verts[i + 1].color = color;
        verts[i + 1].tex_coord = zero;
    }
    for (int i = 0; i < segs; ++i)
    {
        indices[i * 3 + 0] = 0;
        indices[i * 3 + 1] = i + 1;
        indices[i * 3 + 2] = i + 2;
    }
    const bool ok = Submit(renderer, a, verts, segs + 2, indices, segs * 3);
    SDL_free(verts);
    SDL_free(indices);
    return ok;
}

bool gpuFilledEllipseRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry,
                          Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (rx < 0 || ry < 0)
    {
        return SDL_InvalidParamError("radius");
    }
    return CenterFan(renderer, (float)x + 0.5f, (float)y + 0.5f, (float)rx + 0.5f,
                     (float)ry + 0.5f, 0.0f, 360.0f, r, g, b, a);
}

bool gpuFilledCircleRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad,
                         Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    return gpuFilledEllipseRGBA(renderer, x, y, rad, rad, r, g, b, a);
}

bool gpuEllipseRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry,
                    Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (rx < 0 || ry < 0)
    {
        return SDL_InvalidParamError("radius");
    }
    return RingSegment(renderer, (float)x + 0.5f, (float)y + 0.5f, (float)rx + 0.5f,
                       (float)ry + 0.5f, SDL_max((float)rx - 0.5f, 0.0f),
                       SDL_max((float)ry - 0.5f, 0.0f), 0.0f, 360.0f, r, g, b, a);
}

bool gpuCircleRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad,
                   Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    return gpuEllipseRGBA(renderer, x, y, rad, rad, r, g, b, a);
}

bool gpuArcRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end,
                Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (rad < 0)
    {
        return SDL_InvalidParamError("rad");
    }
    float span = (float)(end - start);
    while (span < 0.0f)
    {
        span += 360.0f;
    }
    return RingSegment(renderer, (float)x + 0.5f, (float)y + 0.5f, (float)rad + 0.5f,
                       (float)rad + 0.5f, SDL_max((float)rad - 0.5f, 0.0f),
                       SDL_max((float)rad - 0.5f, 0.0f), (float)start, (float)start + span,
                       r, g, b, a);
}

bool gpuFilledPieRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start,
                      Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (rad < 0)
    {
        return SDL_InvalidParamError("rad");
    }
    float span = (float)(end - start);
    while (span < 0.0f)
    {
        span += 360.0f;
    }
    return CenterFan(renderer, (float)x + 0.5f, (float)y + 0.5f, (float)rad + 0.5f,
                     (float)rad + 0.5f, (float)start, (float)start + span, r, g, b, a);
}

bool gpuPieRGBA(SDL_Renderer *renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end,
                Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (rad < 0)
    {
        return SDL_InvalidParamError("rad");
    }
    float span = (float)(end - start);
    while (span < 0.0f)
    {
        span += 360.0f;
    }
    /* Outline: the arc plus the two radius edges, one batched stroke. */
    const float cx = (float)x + 0.5f;
    const float cy = (float)y + 0.5f;
    const float fr = (float)rad + 0.5f;
    const int segs = SDL_clamp((int)(fr * 1.2f * span / 360.0f) + 6, 6, 250);
    SDL_FPoint pts[256];
    int n = 0;
    pts[n].x = cx;
    pts[n].y = cy;
    n++;
    for (int i = 0; i <= segs; ++i)
    {
        const float deg = (float)start + span * (float)i / (float)segs;
        const float rd = deg * SDL_PI_F / 180.0f;
        pts[n].x = cx + SDL_cosf(rd) * fr;
        pts[n].y = cy + SDL_sinf(rd) * fr;
        n++;
    }
    return StrokeContour(renderer, pts, n, true, HAIRLINE, r, g, b, a);
}

/* ----------------------------------------- triangles/polygons/curves --- */

bool gpuFilledTrigonRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                         Sint16 x3, Sint16 y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Vertex verts[3];
    const int indices[3] = {0, 1, 2};
    const SDL_FColor color = MakeColor(r, g, b, a);
    const SDL_FPoint zero = {0.0f, 0.0f};
    const SDL_FPoint pos[3] = {{(float)x1 + 0.5f, (float)y1 + 0.5f},
                               {(float)x2 + 0.5f, (float)y2 + 0.5f},
                               {(float)x3 + 0.5f, (float)y3 + 0.5f}};
    for (int i = 0; i < 3; ++i)
    {
        verts[i].position = pos[i];
        verts[i].color = color;
        verts[i].tex_coord = zero;
    }
    return Submit(renderer, a, verts, 3, indices, 3);
}

bool gpuTrigonRGBA(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2,
                   Sint16 x3, Sint16 y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    const SDL_FPoint pts[3] = {{(float)x1 + 0.5f, (float)y1 + 0.5f},
                               {(float)x2 + 0.5f, (float)y2 + 0.5f},
                               {(float)x3 + 0.5f, (float)y3 + 0.5f}};
    return StrokeContour(renderer, pts, 3, true, HAIRLINE, r, g, b, a);
}

bool gpuPolygonRGBA(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy, int n,
                    Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (vx == NULL || vy == NULL || n < 3)
    {
        return SDL_InvalidParamError("polygon");
    }
    SDL_FPoint *pts = (SDL_FPoint *)SDL_malloc(sizeof(SDL_FPoint) * (size_t)n);
    if (pts == NULL)
    {
        return false;
    }
    for (int i = 0; i < n; ++i)
    {
        pts[i].x = (float)vx[i] + 0.5f;
        pts[i].y = (float)vy[i] + 0.5f;
    }
    const bool ok = StrokeContour(renderer, pts, n, true, HAIRLINE, r, g, b, a);
    SDL_free(pts);
    return ok;
}

/* Ear-clipping triangulation for simple polygons. */
static float Cross(SDL_FPoint o, SDL_FPoint p, SDL_FPoint q)
{
    return (p.x - o.x) * (q.y - o.y) - (p.y - o.y) * (q.x - o.x);
}

static bool PointInTriangle(SDL_FPoint p, SDL_FPoint a, SDL_FPoint b, SDL_FPoint c)
{
    const float d1 = Cross(p, a, b);
    const float d2 = Cross(p, b, c);
    const float d3 = Cross(p, c, a);
    const bool has_neg = (d1 < 0.0f) || (d2 < 0.0f) || (d3 < 0.0f);
    const bool has_pos = (d1 > 0.0f) || (d2 > 0.0f) || (d3 > 0.0f);
    return !(has_neg && has_pos);
}

bool gpuFilledPolygonRGBA(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy, int n,
                          Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (vx == NULL || vy == NULL || n < 3)
    {
        return SDL_InvalidParamError("polygon");
    }
    SDL_FPoint *pts = (SDL_FPoint *)SDL_malloc(sizeof(SDL_FPoint) * (size_t)n);
    int *remaining = (int *)SDL_malloc(sizeof(int) * (size_t)n);
    SDL_Vertex *verts = (SDL_Vertex *)SDL_malloc(sizeof(SDL_Vertex) * (size_t)n);
    int *indices = (int *)SDL_malloc(sizeof(int) * (size_t)(n - 2) * 3);
    if (pts == NULL || remaining == NULL || verts == NULL || indices == NULL)
    {
        goto fail;
    }

    {
        const SDL_FColor color = MakeColor(r, g, b, a);
        const SDL_FPoint zero = {0.0f, 0.0f};
        float area = 0.0f;
        for (int i = 0; i < n; ++i)
        {
            pts[i].x = (float)vx[i] + 0.5f;
            pts[i].y = (float)vy[i] + 0.5f;
            remaining[i] = i;
            verts[i].position = pts[i];
            verts[i].color = color;
            verts[i].tex_coord = zero;
        }
        for (int i = 0; i < n; ++i)
        {
            const int j = (i + 1) % n;
            area += pts[i].x * pts[j].y - pts[j].x * pts[i].y;
        }
        const float orient = (area >= 0.0f) ? 1.0f : -1.0f;

        int left = n;
        int out = 0;
        int guard = 0;
        while (left > 3)
        {
            bool clipped = false;
            for (int i = 0; i < left; ++i)
            {
                const int ia = remaining[(i + left - 1) % left];
                const int ib = remaining[i];
                const int ic = remaining[(i + 1) % left];
                if (Cross(pts[ia], pts[ib], pts[ic]) * orient <= 0.0f)
                {
                    continue; /* reflex vertex, not an ear */
                }
                bool contains = false;
                for (int k = 0; k < left; ++k)
                {
                    const int ik = remaining[k];
                    if (ik == ia || ik == ib || ik == ic)
                    {
                        continue;
                    }
                    if (PointInTriangle(pts[ik], pts[ia], pts[ib], pts[ic]))
                    {
                        contains = true;
                        break;
                    }
                }
                if (contains)
                {
                    continue;
                }
                indices[out++] = ia;
                indices[out++] = ib;
                indices[out++] = ic;
                for (int k = i; k < left - 1; ++k)
                {
                    remaining[k] = remaining[k + 1];
                }
                left--;
                clipped = true;
                break;
            }
            if (!clipped)
            {
                /* Degenerate input (self-intersection/collinear runs):
                 * emit the rest as a fan rather than looping forever. */
                if (++guard > 1)
                {
                    break;
                }
                for (int k = 1; k < left - 1; ++k)
                {
                    indices[out++] = remaining[0];
                    indices[out++] = remaining[k];
                    indices[out++] = remaining[k + 1];
                }
                left = 3;
                break;
            }
        }
        if (left == 3)
        {
            indices[out++] = remaining[0];
            indices[out++] = remaining[1];
            indices[out++] = remaining[2];
        }

        const bool ok = Submit(renderer, a, verts, n, indices, out);
        SDL_free(pts);
        SDL_free(remaining);
        SDL_free(verts);
        SDL_free(indices);
        return ok;
    }

fail:
    SDL_free(pts);
    SDL_free(remaining);
    SDL_free(verts);
    SDL_free(indices);
    return false;
}

bool gpuBezierRGBA(SDL_Renderer *renderer, const Sint16 *vx, const Sint16 *vy, int n, int s,
                   Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (vx == NULL || vy == NULL || n < 3 || s < 2)
    {
        return SDL_InvalidParamError("bezier");
    }
    /* Flatten the whole curve with de Casteljau at (n-1)*s sample points. */
    const int samples = (n - 1) * s + 1;
    SDL_FPoint *pts = (SDL_FPoint *)SDL_malloc(sizeof(SDL_FPoint) * (size_t)samples);
    float *wx = (float *)SDL_malloc(sizeof(float) * (size_t)n);
    float *wy = (float *)SDL_malloc(sizeof(float) * (size_t)n);
    if (pts == NULL || wx == NULL || wy == NULL)
    {
        SDL_free(pts);
        SDL_free(wx);
        SDL_free(wy);
        return false;
    }
    for (int i = 0; i < samples; ++i)
    {
        const float t = (float)i / (float)(samples - 1);
        for (int k = 0; k < n; ++k)
        {
            wx[k] = (float)vx[k] + 0.5f;
            wy[k] = (float)vy[k] + 0.5f;
        }
        for (int level = n - 1; level > 0; --level)
        {
            for (int k = 0; k < level; ++k)
            {
                wx[k] = wx[k] + (wx[k + 1] - wx[k]) * t;
                wy[k] = wy[k] + (wy[k + 1] - wy[k]) * t;
            }
        }
        pts[i].x = wx[0];
        pts[i].y = wy[0];
    }
    const bool ok = StrokeContour(renderer, pts, samples, false, HAIRLINE, r, g, b, a);
    SDL_free(pts);
    SDL_free(wx);
    SDL_free(wy);
    return ok;
}
