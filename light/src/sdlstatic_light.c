/*
 * sdlstatic_light.c — dynamic 2D lighting over SDL3's renderer.
 * Original SDLStatic code (zlib). See SDLStatic/light.h.
 *
 * Two halves:
 *
 *   Drawing   — a light map texture is cleared to the ambient colour, each
 *               light is added into it as a triangle fan, and the result is
 *               multiplied over the frame. Multiplying is what makes an
 *               unlit floor a dark floor rather than a black hole.
 *
 *   Shadows   — the fan is not a circle but the light's *visibility
 *               polygon*: rays are cast to the corners of nearby occluders
 *               (plus a uniform spread to keep the arc round), each ray is
 *               stopped at the nearest edge, and the polygon is filled.
 *               Hard-edged, which is what a torch in a stone corridor
 *               looks like.
 *
 * Everything is submitted per frame, so there is no handle bookkeeping and
 * no way for the lighting to drift out of step with the game state.
 */
#include "light_internal.h"

#define LIGHT_DEFAULT_RAYS 96
#define LIGHT_DEFAULT_RINGS 3

SDLStatic_LightScene *SDLStatic_CreateLightScene(SDL_Renderer *renderer)
{
    if (renderer == NULL)
    {
        SDL_InvalidParamError("renderer");
        return NULL;
    }
    SDLStatic_LightScene *scene = (SDLStatic_LightScene *)SDL_calloc(1, sizeof(*scene));
    if (scene == NULL)
    {
        return NULL;
    }
    scene->renderer = renderer;
    scene->rays = LIGHT_DEFAULT_RAYS;
    scene->rings = LIGHT_DEFAULT_RINGS;
    scene->ambient = (SDL_FColor){1.0f, 1.0f, 1.0f, 1.0f};
    scene->map_scale = 1.0f;
    scene->shadow_softness = 0.0f;
    scene->prefer_shaders = true;
    /* Shader path when the renderer is OpenGL or GLES, geometry path
       otherwise. Failing to set it up is not an error: it is how a Metal,
       D3D or software renderer is expected to end up. */
    if (!SDLStatic_LightGlInit(scene))
    {
        SDL_ClearError();
    }
    return scene;
}

void SDLStatic_DestroyLightScene(SDLStatic_LightScene *scene)
{
    if (scene == NULL)
    {
        return;
    }
    SDLStatic_LightGlQuit(scene);
    if (scene->map != NULL)
    {
        SDL_DestroyTexture(scene->map);
    }
    if (scene->mask != NULL)
    {
        SDL_DestroyTexture(scene->mask);
    }
    SDL_free(scene->angles);
    SDL_free(scene->verts);
    SDL_free(scene->indices);
    SDL_free(scene);
}

void SDLStatic_LightBeginFrame(SDLStatic_LightScene *scene, float camera_x, float camera_y)
{
    if (scene == NULL)
    {
        return;
    }
    scene->light_count = 0;
    scene->occluder_count = 0;
    scene->occluder_rect_count = 0;
    scene->zone_count = 0;
    scene->camera_x = camera_x;
    scene->camera_y = camera_y;
}

void SDLStatic_SetLightAmbient(SDLStatic_LightScene *scene, SDL_FColor ambient)
{
    if (scene != NULL)
    {
        scene->ambient = ambient;
    }
}

bool SDLStatic_AddLight(SDLStatic_LightScene *scene, const SDLStatic_Light *light)
{
    if (scene == NULL || light == NULL)
    {
        return SDL_InvalidParamError("scene/light");
    }
    if (scene->light_count >= SDLSTATIC_LIGHT_MAX)
    {
        SDL_SetError("at most %d lights per frame", SDLSTATIC_LIGHT_MAX);
        return false;
    }
    if (light->radius <= 0.0f)
    {
        return true; /* a light with no reach is not an error, just nothing */
    }
    scene->lights[scene->light_count++] = *light;
    return true;
}

static bool AddSegment(SDLStatic_LightScene *scene, float x1, float y1, float x2, float y2)
{
    if (scene->occluder_count >= SDLSTATIC_LIGHT_OCCLUDER_MAX)
    {
        SDL_SetError("at most %d occluder edges per frame", SDLSTATIC_LIGHT_OCCLUDER_MAX);
        return false;
    }
    Segment *s = &scene->occluders[scene->occluder_count++];
    s->x1 = x1;
    s->y1 = y1;
    s->x2 = x2;
    s->y2 = y2;
    return true;
}

bool SDLStatic_AddDarkZone(SDLStatic_LightScene *scene, SDL_FRect rect, SDL_FColor ambient)
{
    if (scene == NULL)
    {
        return SDL_InvalidParamError("scene");
    }
    if (scene->zone_count >= SDLSTATIC_LIGHT_ZONE_MAX)
    {
        SDL_SetError("at most %d dark zones per frame", SDLSTATIC_LIGHT_ZONE_MAX);
        return false;
    }
    scene->zones[scene->zone_count].rect = rect;
    scene->zones[scene->zone_count].ambient = ambient;
    scene->zone_count++;
    return true;
}

bool SDLStatic_AddOccluderRect(SDLStatic_LightScene *scene, SDL_FRect rect)
{
    if (scene == NULL)
    {
        return SDL_InvalidParamError("scene");
    }
    const float l = rect.x;
    const float t = rect.y;
    const float r = rect.x + rect.w;
    const float b = rect.y + rect.h;
    if (scene->occluder_rect_count <
        (int)(sizeof(scene->occluder_rects) / sizeof(scene->occluder_rects[0])))
    {
        /* Kept whole for the shader path, which fills them into the mask
           texture; the edges below are what the geometry path rays
           against. */
        scene->occluder_rects[scene->occluder_rect_count++] = rect;
    }
    /* All four edges: a light inside the box should be trapped by it, and
       a light outside should be stopped by the near edge. */
    return AddSegment(scene, l, t, r, t) && AddSegment(scene, r, t, r, b) &&
           AddSegment(scene, r, b, l, b) && AddSegment(scene, l, b, l, t);
}

bool SDLStatic_AddOccluderSegment(SDLStatic_LightScene *scene, float x1, float y1, float x2,
                                  float y2)
{
    if (scene == NULL)
    {
        return SDL_InvalidParamError("scene");
    }
    return AddSegment(scene, x1, y1, x2, y2);
}

void SDLStatic_SetLightRayCount(SDLStatic_LightScene *scene, int rays)
{
    if (scene != NULL)
    {
        scene->rays = SDL_clamp(rays, 16, 512);
    }
}

void SDLStatic_SetLightRings(SDLStatic_LightScene *scene, int rings)
{
    if (scene != NULL)
    {
        scene->rings = SDL_clamp(rings, 1, 8);
    }
}

void SDLStatic_SetLightDebugDraw(SDLStatic_LightScene *scene, bool enabled)
{
    if (scene != NULL)
    {
        scene->debug_draw = enabled;
    }
}

/* --- geometry ----------------------------------------------------------- */

/* Distance along the ray at which it first crosses the segment, or -1.
 * Standard parametric solve; the determinant is zero for parallel lines. */
static float RayHit(float ox, float oy, float dx, float dy, const Segment *s)
{
    const float ex = s->x2 - s->x1;
    const float ey = s->y2 - s->y1;
    const float det = dx * ey - dy * ex;
    if (SDL_fabsf(det) < 1e-6f)
    {
        return -1.0f;
    }
    const float qx = s->x1 - ox;
    const float qy = s->y1 - oy;
    const float t = (qx * ey - qy * ex) / det; /* along the ray */
    const float u = (qx * dy - qy * dx) / det; /* along the segment */
    if (t < 0.0f || u < 0.0f || u > 1.0f)
    {
        return -1.0f;
    }
    return t;
}

/* Cheap reject: does the segment come anywhere near the light's circle? */
static bool SegmentNearCircle(const Segment *s, float cx, float cy, float radius)
{
    const float min_x = SDL_min(s->x1, s->x2) - radius;
    const float max_x = SDL_max(s->x1, s->x2) + radius;
    const float min_y = SDL_min(s->y1, s->y2) - radius;
    const float max_y = SDL_max(s->y1, s->y2) + radius;
    return cx >= min_x && cx <= max_x && cy >= min_y && cy <= max_y;
}

static float CastRay(const SDLStatic_LightScene *scene, float ox, float oy, float angle,
                     float radius)
{
    const float dx = SDL_cosf(angle);
    const float dy = SDL_sinf(angle);
    float nearest = radius;
    for (int i = 0; i < scene->occluder_count; i++)
    {
        const Segment *s = &scene->occluders[i];
        if (!SegmentNearCircle(s, ox, oy, radius))
        {
            continue;
        }
        const float t = RayHit(ox, oy, dx, dy, s);
        if (t >= 0.0f && t < nearest)
        {
            nearest = t;
        }
    }
    return nearest;
}

static bool EnsureCapacity(SDLStatic_LightScene *scene, int angles, int verts, int indices)
{
    if (angles > scene->angle_capacity)
    {
        float *grown = (float *)SDL_realloc(scene->angles, (size_t)angles * sizeof(float));
        if (grown == NULL)
        {
            return false;
        }
        scene->angles = grown;
        scene->angle_capacity = angles;
    }
    if (verts > scene->vert_capacity)
    {
        SDL_Vertex *grown =
            (SDL_Vertex *)SDL_realloc(scene->verts, (size_t)verts * sizeof(SDL_Vertex));
        if (grown == NULL)
        {
            return false;
        }
        scene->verts = grown;
        scene->vert_capacity = verts;
    }
    if (indices > scene->index_capacity)
    {
        int *grown = (int *)SDL_realloc(scene->indices, (size_t)indices * sizeof(int));
        if (grown == NULL)
        {
            return false;
        }
        scene->indices = grown;
        scene->index_capacity = indices;
    }
    return true;
}

static int CompareAngles(const void *a, const void *b)
{
    const float left = *(const float *)a;
    const float right = *(const float *)b;
    return (left > right) - (left < right);
}

/* Torch flicker: two out-of-phase sine waves plus the light's own seed, so
 * neighbouring torches never pulse together. Deterministic in time, which
 * keeps a replay or a screenshot test reproducible. */
float SDLStatic_LightFlickerScale(const SDLStatic_Light *light, float seconds)
{
    if (light->flicker <= 0.0f)
    {
        return 1.0f;
    }
    const float phase = (float)(light->seed % 1000u) * 0.01f;
    const float wobble = SDL_sinf((seconds * 11.0f) + phase) * 0.6f +
                         SDL_sinf((seconds * 23.0f) + phase * 2.3f) * 0.4f;
    const float amount = SDL_clamp(light->flicker, 0.0f, 1.0f);
    return SDL_max(0.05f, 1.0f + wobble * amount * 0.5f);
}

/* Attenuation at `distance` from a light of `radius`, before flicker. */
static float Attenuate(const SDLStatic_Light *light, float distance)
{
    if (distance >= light->radius)
    {
        return 0.0f;
    }
    const float t = 1.0f - (distance / light->radius);
    const float exponent = (light->falloff > 0.0f) ? light->falloff : 1.0f;
    return SDL_powf(t, exponent);
}

/* Is `angle` inside the light's cone? Omni lights accept everything. */
static bool InCone(const SDLStatic_Light *light, float angle)
{
    if (light->spread <= 0.0f || light->spread >= 2.0f * SDL_PI_F)
    {
        return true;
    }
    float delta = angle - light->angle;
    while (delta > SDL_PI_F)
    {
        delta -= 2.0f * SDL_PI_F;
    }
    while (delta < -SDL_PI_F)
    {
        delta += 2.0f * SDL_PI_F;
    }
    return SDL_fabsf(delta) <= light->spread * 0.5f;
}

/* Build and draw one light's visibility polygon into the light map. */
static bool DrawLight(SDLStatic_LightScene *scene, const SDLStatic_Light *light, float seconds)
{
    const float flicker = SDLStatic_LightFlickerScale(light, seconds);
    const float radius = light->radius * flicker;
    if (radius <= 0.0f)
    {
        return true;
    }

    /* Candidate angles: a uniform spread for the arc, plus a pair either
       side of every occluder corner so shadow edges land exactly on the
       corner instead of the nearest ray. */
    const int uniform = scene->rays;
    const int max_angles = uniform + scene->occluder_count * 4 + 8;
    const int rings = scene->rings;
    const int max_verts = 1 + max_angles * rings;
    const int max_indices = max_angles * rings * 6;
    if (!EnsureCapacity(scene, max_angles, max_verts, max_indices))
    {
        return false;
    }

    int count = 0;
    const float step = (2.0f * SDL_PI_F) / (float)uniform;
    for (int i = 0; i < uniform; i++)
    {
        scene->angles[count++] = (float)i * step;
    }
    const float epsilon = 0.0008f;
    for (int i = 0; i < scene->occluder_count && count + 4 <= max_angles; i++)
    {
        const Segment *s = &scene->occluders[i];
        if (!SegmentNearCircle(s, light->x, light->y, radius))
        {
            continue;
        }
        const float a1 = SDL_atan2f(s->y1 - light->y, s->x1 - light->x);
        const float a2 = SDL_atan2f(s->y2 - light->y, s->x2 - light->x);
        scene->angles[count++] = a1 - epsilon;
        scene->angles[count++] = a1 + epsilon;
        scene->angles[count++] = a2 - epsilon;
        scene->angles[count++] = a2 + epsilon;
    }
    /* Normalise into [0, 2pi) and sort, so the fan winds consistently. */
    for (int i = 0; i < count; i++)
    {
        float a = SDL_fmodf(scene->angles[i], 2.0f * SDL_PI_F);
        if (a < 0.0f)
        {
            a += 2.0f * SDL_PI_F;
        }
        scene->angles[i] = a;
    }
    SDL_qsort(scene->angles, (size_t)count, sizeof(float), CompareAngles);

    const float cx = light->x - scene->camera_x;
    const float cy = light->y - scene->camera_y;
    const float alpha = (light->color.a > 0.0f) ? light->color.a : 1.0f;

    /* Centre vertex, then `rings` vertices along every ray. */
    SDL_Vertex *v = scene->verts;
    int vert_count = 0;
    v[vert_count].position.x = cx;
    v[vert_count].position.y = cy;
    v[vert_count].color = (SDL_FColor){light->color.r, light->color.g, light->color.b,
                                       alpha * flicker};
    v[vert_count].tex_coord = (SDL_FPoint){0.0f, 0.0f};
    vert_count++;

    for (int i = 0; i < count; i++)
    {
        const float angle = scene->angles[i];
        float reach = light->no_shadows ? radius
                                        : CastRay(scene, light->x, light->y, angle, radius);
        if (!InCone(light, angle))
        {
            reach = 0.0f; /* outside the cone: collapse onto the centre */
        }
        for (int ring = 1; ring <= rings; ring++)
        {
            const float t = (float)ring / (float)rings;
            const float distance = reach * t;
            const float intensity = Attenuate(light, distance / flicker) * alpha * flicker;
            v[vert_count].position.x = cx + SDL_cosf(angle) * distance;
            v[vert_count].position.y = cy + SDL_sinf(angle) * distance;
            v[vert_count].color = (SDL_FColor){light->color.r, light->color.g, light->color.b,
                                               intensity};
            v[vert_count].tex_coord = (SDL_FPoint){0.0f, 0.0f};
            vert_count++;
        }
    }

    /* Stitch: centre to first ring, then quads between rings. */
    int *idx = scene->indices;
    int index_count = 0;
    for (int i = 0; i < count; i++)
    {
        const int next = (i + 1) % count;
        const int a = 1 + i * rings;
        const int b = 1 + next * rings;
        idx[index_count++] = 0;
        idx[index_count++] = a;
        idx[index_count++] = b;
        for (int ring = 0; ring < rings - 1; ring++)
        {
            idx[index_count++] = a + ring;
            idx[index_count++] = a + ring + 1;
            idx[index_count++] = b + ring;
            idx[index_count++] = b + ring;
            idx[index_count++] = a + ring + 1;
            idx[index_count++] = b + ring + 1;
        }
    }

    return SDL_RenderGeometry(scene->renderer, NULL, scene->verts, vert_count, scene->indices,
                              index_count);
}

/* The light map has to match the output, and the output can change when the
 * window resizes or moves between displays. The mask is the same size: the
 * shader raymarches it in light-map pixels. */
static bool EnsureTargets(SDLStatic_LightScene *scene)
{
    int out_w = 0;
    int out_h = 0;
    if (!SDL_GetCurrentRenderOutputSize(scene->renderer, &out_w, &out_h) || out_w <= 0 ||
        out_h <= 0)
    {
        return false;
    }
    const int w = SDL_max(1, (int)((float)out_w * scene->map_scale));
    const int h = SDL_max(1, (int)((float)out_h * scene->map_scale));
    if (scene->map != NULL && scene->map_w == w && scene->map_h == h)
    {
        return true;
    }
    if (scene->map != NULL)
    {
        SDL_DestroyTexture(scene->map);
        scene->map = NULL;
    }
    if (scene->mask != NULL)
    {
        SDL_DestroyTexture(scene->mask);
        scene->mask = NULL;
    }
    /* Which pixel format the light map gets matters more than it looks.
       The shader path writes into this texture through raw GL, in GL's
       channel order (R,G,B,A in memory), while SDL samples it back with a
       shader picked for the texture's format — so a format whose bytes run
       B,G,R,A comes back with red and blue swapped, and warm torchlight
       turns blue. SDL_PIXELFORMAT_ABGR8888 is the one whose memory layout
       *is* GL_RGBA, so prefer it; if the renderer will not take it, fall
       back and tell the shader to swap on the way out. */
    SDL_PixelFormat format = SDL_PIXELFORMAT_UNKNOWN;
    const SDL_PixelFormat *supported = (const SDL_PixelFormat *)SDL_GetPointerProperty(
        SDL_GetRendererProperties(scene->renderer),
        SDL_PROP_RENDERER_TEXTURE_FORMATS_POINTER, NULL);
    if (supported != NULL)
    {
        for (int i = 0; supported[i] != SDL_PIXELFORMAT_UNKNOWN; i++)
        {
            if (supported[i] == SDL_PIXELFORMAT_ABGR8888 ||
                supported[i] == SDL_PIXELFORMAT_XBGR8888)
            {
                format = supported[i];
                break;
            }
            if (format == SDL_PIXELFORMAT_UNKNOWN)
            {
                format = supported[i]; /* first choice, as a fallback */
            }
        }
    }
    if (format == SDL_PIXELFORMAT_UNKNOWN)
    {
        format = SDL_PIXELFORMAT_ABGR8888;
    }
    scene->map_swizzle = (format == SDL_PIXELFORMAT_ARGB8888 ||
                          format == SDL_PIXELFORMAT_XRGB8888);
    scene->map = SDL_CreateTexture(scene->renderer, format, SDL_TEXTUREACCESS_TARGET, w, h);
    if (scene->map == NULL)
    {
        return false;
    }
    /* Linear, because a half-resolution light map is stretched back up and
       nearest sampling would show the grid. */
    SDL_SetTextureScaleMode(scene->map, SDL_SCALEMODE_LINEAR);

    scene->map_w = w;
    scene->map_h = h;
    return true;
}

bool SDLStatic_RenderLighting(SDLStatic_LightScene *scene)
{
    if (scene == NULL)
    {
        return SDL_InvalidParamError("scene");
    }
    if (!EnsureTargets(scene))
    {
        return false;
    }
    const float seconds = (float)SDL_GetTicks() / 1000.0f;
    const bool use_shader = (scene->gl != NULL) && scene->prefer_shaders;

    SDL_Texture *previous_target = SDL_GetRenderTarget(scene->renderer);
    if (!SDL_SetRenderTarget(scene->renderer, scene->map))
    {
        return false;
    }

    /* Ambient first — the colour every unlit pixel keeps — then any dark
       zones on top of it, then the lights. Painting the base with SDL
       means both paths share it, so a cave is as dark on Metal as it is
       on OpenGL. */
    const SDL_FColor ambient = scene->ambient;
    SDL_SetRenderDrawColorFloat(scene->renderer, ambient.r, ambient.g, ambient.b, 1.0f);
    SDL_SetRenderDrawBlendMode(scene->renderer, SDL_BLENDMODE_NONE);
    SDL_RenderClear(scene->renderer);
    for (int i = 0; i < scene->zone_count; i++)
    {
        const SDL_FRect world = scene->zones[i].rect;
        const SDL_FColor zone = scene->zones[i].ambient;
        const SDL_FRect on_map = {(world.x - scene->camera_x) * scene->map_scale,
                                  (world.y - scene->camera_y) * scene->map_scale,
                                  world.w * scene->map_scale, world.h * scene->map_scale};
        SDL_SetRenderDrawColorFloat(scene->renderer, zone.r, zone.g, zone.b, 1.0f);
        SDL_RenderFillRect(scene->renderer, &on_map);
    }

    bool ok = true;
    bool drawn = false;
    if (use_shader)
    {
        /* The shader writes the whole map in one pass: ambient, falloff,
           cones and shadows, per pixel. */
        drawn = SDLStatic_LightGlRenderMap(scene, seconds);
        if (!drawn)
        {
            /* The shader path can decline at runtime — a driver refusing
               the program, a mask with no GL texture behind it. Fall
               through rather than leaving the frame unlit. */
            SDL_ClearError();
        }
    }
    if (!drawn)
    {
        /* Geometry path: each light as a visibility polygon, added over
           the base the block above painted. */
        SDL_SetRenderDrawBlendMode(scene->renderer, SDL_BLENDMODE_ADD);
        for (int i = 0; i < scene->light_count; i++)
        {
            if (!DrawLight(scene, &scene->lights[i], seconds))
            {
                ok = false;
                break;
            }
        }
    }

    SDL_SetRenderTarget(scene->renderer, previous_target);
    if (!ok)
    {
        return false;
    }

    /* Multiply over the frame: dark areas keep their colour but lose their
       brightness, which is what "unlit" should look like. */
    SDL_SetTextureBlendMode(scene->map, SDL_BLENDMODE_MUL);
    if (!SDL_RenderTexture(scene->renderer, scene->map, NULL, NULL))
    {
        return false;
    }

    if (scene->debug_draw)
    {
        SDL_SetRenderDrawBlendMode(scene->renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(scene->renderer, 255, 80, 80, 200);
        for (int i = 0; i < scene->occluder_count; i++)
        {
            const Segment *s = &scene->occluders[i];
            SDL_RenderLine(scene->renderer, s->x1 - scene->camera_x, s->y1 - scene->camera_y,
                           s->x2 - scene->camera_x, s->y2 - scene->camera_y);
        }
        SDL_SetRenderDrawColor(scene->renderer, 255, 255, 120, 255);
        for (int i = 0; i < scene->light_count; i++)
        {
            const SDLStatic_Light *light = &scene->lights[i];
            SDL_FRect dot = {light->x - scene->camera_x - 2.0f,
                             light->y - scene->camera_y - 2.0f, 4.0f, 4.0f};
            SDL_RenderFillRect(scene->renderer, &dot);
        }
    }
    return true;
}

bool SDLStatic_LightUsesShaders(SDLStatic_LightScene *scene)
{
    return scene != NULL && scene->gl != NULL && scene->prefer_shaders;
}

void SDLStatic_SetLightUseShaders(SDLStatic_LightScene *scene, bool enabled)
{
    if (scene != NULL)
    {
        scene->prefer_shaders = enabled;
    }
}

void SDLStatic_SetLightMapScale(SDLStatic_LightScene *scene, float scale)
{
    if (scene == NULL)
    {
        return;
    }
    const float clamped = SDL_clamp(scale, 0.1f, 1.0f);
    if (clamped != scene->map_scale)
    {
        scene->map_scale = clamped;
        scene->map_w = 0; /* force the targets to be rebuilt */
    }
}

void SDLStatic_SetLightShadowSoftness(SDLStatic_LightScene *scene, float softness)
{
    if (scene != NULL)
    {
        scene->shadow_softness = SDL_clamp(softness, 0.0f, 1.0f);
    }
}

/* --- gameplay queries --------------------------------------------------- */

bool SDLStatic_LightLineOfSight(SDLStatic_LightScene *scene, float x1, float y1, float x2,
                                float y2)
{
    if (scene == NULL)
    {
        SDL_InvalidParamError("scene");
        return false;
    }
    const float dx = x2 - x1;
    const float dy = y2 - y1;
    const float distance = SDL_sqrtf(dx * dx + dy * dy);
    if (distance <= 1e-4f)
    {
        return true;
    }
    const float angle = SDL_atan2f(dy, dx);
    /* Stop just short of the target so a point sitting exactly on an
       occluder's surface — a torch mounted on a wall — is not shadowed by
       the very edge it is attached to. */
    const float reach = CastRay(scene, x1, y1, angle, distance - 0.5f);
    return reach >= distance - 0.5f;
}

float SDLStatic_SampleLight(SDLStatic_LightScene *scene, float x, float y)
{
    if (scene == NULL)
    {
        return 0.0f;
    }
    /* Luminance of the ambient — or of the dark zone the point is in,
       since that is what the light map will show there — and then every
       light that reaches it. */
    SDL_FColor a = scene->ambient;
    for (int i = 0; i < scene->zone_count; i++)
    {
        const SDL_FRect r = scene->zones[i].rect;
        if (x >= r.x && x <= r.x + r.w && y >= r.y && y <= r.y + r.h)
        {
            a = scene->zones[i].ambient;
        }
    }
    float total = 0.2126f * a.r + 0.7152f * a.g + 0.0722f * a.b;
    const float seconds = (float)SDL_GetTicks() / 1000.0f;

    for (int i = 0; i < scene->light_count; i++)
    {
        const SDLStatic_Light *light = &scene->lights[i];
        const float dx = x - light->x;
        const float dy = y - light->y;
        const float distance = SDL_sqrtf(dx * dx + dy * dy);
        const float flicker = SDLStatic_LightFlickerScale(light, seconds);
        if (distance >= light->radius * flicker)
        {
            continue;
        }
        if (!InCone(light, SDL_atan2f(dy, dx)))
        {
            continue;
        }
        if (!light->no_shadows && !SDLStatic_LightLineOfSight(scene, light->x, light->y, x, y))
        {
            continue; /* something is in the way */
        }
        const float alpha = (light->color.a > 0.0f) ? light->color.a : 1.0f;
        const float luminance = 0.2126f * light->color.r + 0.7152f * light->color.g +
                                0.0722f * light->color.b;
        total += Attenuate(light, distance) * alpha * flicker * luminance;
    }
    return SDL_clamp(total, 0.0f, 1.0f);
}

/* --- time of day -------------------------------------------------------- */

/* Keyframes around the clock. Values are ambient multipliers, so night is
 * dim and blue, dawn and dusk are warm and low, noon is bright and neutral.
 * Deliberately readable numbers: this is meant to be tuned by eye. */
typedef struct DayKey
{
    float hour;
    SDL_FColor colour;
    float sunlight;
} DayKey;

static const DayKey kDayCycle[] = {
    {0.0f, {0.10f, 0.12f, 0.22f, 1.0f}, 0.0f},  /* midnight */
    {4.0f, {0.12f, 0.14f, 0.26f, 1.0f}, 0.0f},  /* last dark hour */
    {6.0f, {0.45f, 0.32f, 0.30f, 1.0f}, 0.15f}, /* first light */
    {7.5f, {0.85f, 0.62f, 0.45f, 1.0f}, 0.5f},  /* sunrise */
    {10.0f, {1.00f, 0.96f, 0.90f, 1.0f}, 0.9f}, /* morning */
    {13.0f, {1.05f, 1.03f, 1.00f, 1.0f}, 1.0f}, /* midday */
    {17.0f, {1.00f, 0.92f, 0.82f, 1.0f}, 0.8f}, /* afternoon */
    {19.0f, {0.90f, 0.55f, 0.38f, 1.0f}, 0.35f},/* sunset */
    {20.5f, {0.35f, 0.26f, 0.32f, 1.0f}, 0.05f},/* dusk */
    {22.0f, {0.14f, 0.15f, 0.26f, 1.0f}, 0.0f}, /* night */
    {24.0f, {0.10f, 0.12f, 0.22f, 1.0f}, 0.0f}, /* wraps to midnight */
};

#define DAY_KEY_COUNT ((int)(sizeof(kDayCycle) / sizeof(kDayCycle[0])))

static float WrapHours(float hours)
{
    float h = SDL_fmodf(hours, 24.0f);
    if (h < 0.0f)
    {
        h += 24.0f;
    }
    return h;
}

SDL_FColor SDLStatic_DayNightAmbient(float hours)
{
    const float h = WrapHours(hours);
    for (int i = 1; i < DAY_KEY_COUNT; i++)
    {
        if (h <= kDayCycle[i].hour)
        {
            const DayKey *a = &kDayCycle[i - 1];
            const DayKey *b = &kDayCycle[i];
            const float span = b->hour - a->hour;
            const float t = (span > 0.0f) ? (h - a->hour) / span : 0.0f;
            SDL_FColor out;
            out.r = a->colour.r + (b->colour.r - a->colour.r) * t;
            out.g = a->colour.g + (b->colour.g - a->colour.g) * t;
            out.b = a->colour.b + (b->colour.b - a->colour.b) * t;
            out.a = 1.0f;
            return out;
        }
    }
    return kDayCycle[0].colour;
}

float SDLStatic_DayNightSunlight(float hours)
{
    const float h = WrapHours(hours);
    for (int i = 1; i < DAY_KEY_COUNT; i++)
    {
        if (h <= kDayCycle[i].hour)
        {
            const DayKey *a = &kDayCycle[i - 1];
            const DayKey *b = &kDayCycle[i];
            const float span = b->hour - a->hour;
            const float t = (span > 0.0f) ? (h - a->hour) / span : 0.0f;
            return a->sunlight + (b->sunlight - a->sunlight) * t;
        }
    }
    return 0.0f;
}
