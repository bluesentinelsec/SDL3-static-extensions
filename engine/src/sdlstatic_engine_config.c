/*
 * sdlstatic_engine_config.c — heap builders for the plain-struct arguments.
 * Original SDLStatic code (zlib).
 *
 * Mechanical by design. The value is not in the code but in the shape: a
 * create/destroy pair plus scalar setters is exactly what the binding
 * generator already recognises as an owned resource, so every one of these
 * becomes a GC-managed handle in Lua and Ruby without a line of generator
 * work or hand-written marshalling.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_config.h>

/* --- engine config -------------------------------------------------------- */

/* The title and media path are borrowed pointers in the plain struct, which
   is right for a C caller holding a literal. A script's string may be
   collected the moment the setter returns, so the builder owns copies and
   frees them with itself. */
struct ConfigStrings
{
    char *title;
    char *media_path;
    SDLStatic_GraphicsSettings graphics;
    bool has_graphics;
};

/* The strings live immediately after the config, so one allocation frees
   everything and SDLStatic_ConfigDestroy stays a single SDL_free. */
typedef struct ConfigBlock
{
    SDLStatic_EngineConfig config;
    struct ConfigStrings owned;
} ConfigBlock;

static ConfigBlock *Block(SDLStatic_EngineConfig *config)
{
    return (ConfigBlock *)config;
}

SDLStatic_EngineConfig *SDLStatic_ConfigCreate(void)
{
    ConfigBlock *block = (ConfigBlock *)SDL_calloc(1, sizeof(ConfigBlock));
    return (block != NULL) ? &block->config : NULL;
}

void SDLStatic_ConfigDestroy(SDLStatic_EngineConfig *config)
{
    if (config == NULL)
    {
        return;
    }
    ConfigBlock *block = Block(config);
    SDL_free(block->owned.title);
    SDL_free(block->owned.media_path);
    SDL_free(block);
}

static void ReplaceString(char **slot, const char **field, const char *value)
{
    SDL_free(*slot);
    *slot = (value != NULL) ? SDL_strdup(value) : NULL;
    *field = *slot;
}

void SDLStatic_ConfigSetTitle(SDLStatic_EngineConfig *config, const char *title)
{
    if (config != NULL)
    {
        ReplaceString(&Block(config)->owned.title, &config->title, title);
    }
}

void SDLStatic_ConfigSetMediaPath(SDLStatic_EngineConfig *config, const char *path)
{
    if (config != NULL)
    {
        ReplaceString(&Block(config)->owned.media_path, &config->media_path, path);
    }
}

void SDLStatic_ConfigSetWindowSize(SDLStatic_EngineConfig *config, int width, int height)
{
    if (config != NULL)
    {
        config->window_width = width;
        config->window_height = height;
    }
}

void SDLStatic_ConfigSetDesignSize(SDLStatic_EngineConfig *config, int width, int height)
{
    if (config != NULL)
    {
        config->design_width = width;
        config->design_height = height;
    }
}

void SDLStatic_ConfigSetPresentation(SDLStatic_EngineConfig *config,
                                     SDLStatic_EnginePresentation presentation)
{
    if (config != NULL)
    {
        config->presentation = presentation;
    }
}

void SDLStatic_ConfigSetFullscreen(SDLStatic_EngineConfig *config, bool fullscreen)
{
    if (config != NULL)
    {
        config->fullscreen = fullscreen;
    }
}

/* The plain struct spells these as opt-outs so a zeroed config gives the
   documented defaults. A script says what it wants, so these read the
   positive way round and invert here. */
void SDLStatic_ConfigSetVsync(SDLStatic_EngineConfig *config, bool vsync)
{
    if (config != NULL)
    {
        config->no_vsync = !vsync;
    }
}

void SDLStatic_ConfigSetResizable(SDLStatic_EngineConfig *config, bool resizable)
{
    if (config != NULL)
    {
        config->fixed_size = !resizable;
    }
}

void SDLStatic_ConfigSetHighDpi(SDLStatic_EngineConfig *config, bool high_dpi)
{
    if (config != NULL)
    {
        config->low_dpi = !high_dpi;
    }
}

void SDLStatic_ConfigSetAutoMount(SDLStatic_EngineConfig *config, bool enabled)
{
    if (config != NULL)
    {
        config->no_auto_mount = !enabled;
    }
}

void SDLStatic_ConfigSetMaxFps(SDLStatic_EngineConfig *config, int max_fps)
{
    if (config != NULL)
    {
        config->max_fps = max_fps;
    }
}

void SDLStatic_ConfigSetTickRate(SDLStatic_EngineConfig *config, int ticks_per_second)
{
    if (config != NULL)
    {
        config->tick_rate = ticks_per_second;
    }
}

void SDLStatic_ConfigSetBackend(SDLStatic_EngineConfig *config, SDLStatic_EngineBackend backend)
{
    if (config != NULL)
    {
        config->backend = backend;
    }
}

void SDLStatic_ConfigSetHeadless(SDLStatic_EngineConfig *config, bool headless)
{
    if (config != NULL)
    {
        config->headless = headless;
    }
}

void SDLStatic_ConfigSetManualClock(SDLStatic_EngineConfig *config, bool manual)
{
    if (config != NULL)
    {
        config->manual_clock = manual;
    }
}

void SDLStatic_ConfigSetGraphics(SDLStatic_EngineConfig *config,
                                 const SDLStatic_GraphicsSettings *graphics)
{
    if (config == NULL || graphics == NULL)
    {
        return;
    }
    /* Copied into the block, so the caller's settings may be a temporary —
       which they always are from a script. */
    ConfigBlock *block = Block(config);
    block->owned.graphics = *graphics;
    block->owned.has_graphics = true;
    config->graphics = &block->owned.graphics;
}

/* --- actor definitions ---------------------------------------------------- */

typedef struct ActorDefBlock
{
    SDLStatic_ActorDef def;
    char *type;
    char *name;
} ActorDefBlock;

static ActorDefBlock *ActorBlock(SDLStatic_ActorDef *def)
{
    return (ActorDefBlock *)def;
}

SDLStatic_ActorDef *SDLStatic_ActorDefCreate(void)
{
    ActorDefBlock *block = (ActorDefBlock *)SDL_calloc(1, sizeof(ActorDefBlock));
    return (block != NULL) ? &block->def : NULL;
}

void SDLStatic_ActorDefDestroy(SDLStatic_ActorDef *def)
{
    if (def == NULL)
    {
        return;
    }
    ActorDefBlock *block = ActorBlock(def);
    SDL_free(block->type);
    SDL_free(block->name);
    SDL_free(block);
}

void SDLStatic_ActorDefSetType(SDLStatic_ActorDef *def, const char *type)
{
    if (def != NULL)
    {
        ReplaceString(&ActorBlock(def)->type, &def->type, type);
    }
}

void SDLStatic_ActorDefSetName(SDLStatic_ActorDef *def, const char *name)
{
    if (def != NULL)
    {
        ReplaceString(&ActorBlock(def)->name, &def->name, name);
    }
}

void SDLStatic_ActorDefSetPosition(SDLStatic_ActorDef *def, float x, float y)
{
    if (def != NULL)
    {
        def->x = x;
        def->y = y;
    }
}

void SDLStatic_ActorDefSetRotation(SDLStatic_ActorDef *def, float degrees)
{
    if (def != NULL)
    {
        def->rotation = degrees;
    }
}

void SDLStatic_ActorDefSetScale(SDLStatic_ActorDef *def, float x, float y)
{
    if (def != NULL)
    {
        def->scale_x = x;
        def->scale_y = y;
    }
}

void SDLStatic_ActorDefSetTags(SDLStatic_ActorDef *def, SDLStatic_ActorTags tags)
{
    if (def != NULL)
    {
        def->tags = tags;
    }
}

void SDLStatic_ActorDefSetParent(SDLStatic_ActorDef *def, SDLStatic_ActorId parent)
{
    if (def != NULL)
    {
        def->parent = parent;
    }
}

void SDLStatic_ActorDefSetStateSize(SDLStatic_ActorDef *def, int size)
{
    if (def != NULL && size >= 0)
    {
        def->state_size = (size_t)size;
    }
}

/* --- sprites, bodies, lights ---------------------------------------------- */

/* Each starts from its module's default rather than zero: a zeroed sprite is
   invisible and transparent, a zeroed body has no size and no density. */

SDLStatic_Sprite *SDLStatic_SpriteCreate(void)
{
    SDLStatic_Sprite *sprite = (SDLStatic_Sprite *)SDL_malloc(sizeof(SDLStatic_Sprite));
    if (sprite != NULL)
    {
        *sprite = SDLStatic_SpriteDefault();
    }
    return sprite;
}

void SDLStatic_SpriteDestroy(SDLStatic_Sprite *sprite)
{
    SDL_free(sprite);
}

void SDLStatic_SpriteSetTexture(SDLStatic_Sprite *sprite, SDL_Texture *texture)
{
    if (sprite != NULL)
    {
        sprite->texture = texture;
    }
}

void SDLStatic_SpriteSetSize(SDLStatic_Sprite *sprite, float width, float height)
{
    if (sprite != NULL)
    {
        sprite->width = width;
        sprite->height = height;
    }
}

void SDLStatic_SpriteSetSource(SDLStatic_Sprite *sprite, float x, float y, float w, float h)
{
    if (sprite != NULL)
    {
        sprite->source = (SDL_FRect){x, y, w, h};
    }
}

void SDLStatic_SpriteSetOrigin(SDLStatic_Sprite *sprite, float x, float y)
{
    if (sprite != NULL)
    {
        sprite->origin_x = x;
        sprite->origin_y = y;
    }
}

void SDLStatic_SpriteSetColor(SDLStatic_Sprite *sprite, float r, float g, float b, float a)
{
    if (sprite != NULL)
    {
        sprite->color = (SDL_FColor){r, g, b, a};
    }
}

void SDLStatic_SpriteSetLayer(SDLStatic_Sprite *sprite, int layer, float order)
{
    if (sprite != NULL)
    {
        sprite->layer = layer;
        sprite->order = order;
    }
}

void SDLStatic_SpriteSetSortByY(SDLStatic_Sprite *sprite, bool enabled)
{
    if (sprite != NULL)
    {
        sprite->sort_by_y = enabled;
    }
}

void SDLStatic_SpriteSetScreenSpace(SDLStatic_Sprite *sprite, bool enabled)
{
    if (sprite != NULL)
    {
        sprite->screen_space = enabled;
    }
}

void SDLStatic_SpriteSetVisible(SDLStatic_Sprite *sprite, bool visible)
{
    if (sprite != NULL)
    {
        sprite->visible = visible;
    }
}

SDLStatic_BodyDef *SDLStatic_BodyDefCreate(void)
{
    SDLStatic_BodyDef *def = (SDLStatic_BodyDef *)SDL_malloc(sizeof(SDLStatic_BodyDef));
    if (def != NULL)
    {
        *def = SDLStatic_BodyDefault();
    }
    return def;
}

void SDLStatic_BodyDefDestroy(SDLStatic_BodyDef *def)
{
    SDL_free(def);
}

void SDLStatic_BodyDefSetType(SDLStatic_BodyDef *def, SDLStatic_BodyType type)
{
    if (def != NULL)
    {
        def->type = type;
    }
}

void SDLStatic_BodyDefSetShape(SDLStatic_BodyDef *def, SDLStatic_ShapeType shape)
{
    if (def != NULL)
    {
        def->shape = shape;
    }
}

void SDLStatic_BodyDefSetSize(SDLStatic_BodyDef *def, float width, float height)
{
    if (def != NULL)
    {
        def->width = width;
        def->height = height;
    }
}

void SDLStatic_BodyDefSetOffset(SDLStatic_BodyDef *def, float x, float y)
{
    if (def != NULL)
    {
        def->offset_x = x;
        def->offset_y = y;
    }
}

void SDLStatic_BodyDefSetMaterial(SDLStatic_BodyDef *def, float density, float friction,
                                  float restitution)
{
    if (def != NULL)
    {
        def->density = density;
        def->friction = friction;
        def->restitution = restitution;
    }
}

void SDLStatic_BodyDefSetFixedRotation(SDLStatic_BodyDef *def, bool fixed)
{
    if (def != NULL)
    {
        def->fixed_rotation = fixed;
    }
}

void SDLStatic_BodyDefSetSensor(SDLStatic_BodyDef *def, bool sensor)
{
    if (def != NULL)
    {
        def->sensor = sensor;
    }
}

void SDLStatic_BodyDefSetGravityScale(SDLStatic_BodyDef *def, float scale)
{
    if (def != NULL)
    {
        def->gravity_scale = scale;
    }
}

void SDLStatic_BodyDefSetFilter(SDLStatic_BodyDef *def, Uint32 category, Uint32 collides_with)
{
    if (def != NULL)
    {
        def->category = category;
        def->collides_with = collides_with;
    }
}

void SDLStatic_BodyDefSetBullet(SDLStatic_BodyDef *def, bool bullet)
{
    if (def != NULL)
    {
        def->bullet = bullet;
    }
}

SDLStatic_LightDef *SDLStatic_LightDefCreate(void)
{
    SDLStatic_LightDef *def = (SDLStatic_LightDef *)SDL_malloc(sizeof(SDLStatic_LightDef));
    if (def != NULL)
    {
        *def = SDLStatic_LightDefault();
    }
    return def;
}

void SDLStatic_LightDefDestroy(SDLStatic_LightDef *def)
{
    SDL_free(def);
}

void SDLStatic_LightDefSetRadius(SDLStatic_LightDef *def, float radius)
{
    if (def != NULL)
    {
        def->radius = radius;
    }
}

void SDLStatic_LightDefSetColor(SDLStatic_LightDef *def, float r, float g, float b, float a)
{
    if (def != NULL)
    {
        def->color = (SDL_FColor){r, g, b, a};
    }
}

void SDLStatic_LightDefSetOffset(SDLStatic_LightDef *def, float x, float y)
{
    if (def != NULL)
    {
        def->offset_x = x;
        def->offset_y = y;
    }
}

void SDLStatic_LightDefSetCone(SDLStatic_LightDef *def, float direction, float width)
{
    if (def != NULL)
    {
        def->cone_direction = direction;
        def->cone_width = width;
    }
}

void SDLStatic_LightDefSetFlicker(SDLStatic_LightDef *def, float flicker)
{
    if (def != NULL)
    {
        def->flicker = flicker;
    }
}

void SDLStatic_LightDefSetShadows(SDLStatic_LightDef *def, bool casts_shadows)
{
    if (def != NULL)
    {
        def->no_shadows = !casts_shadows;
    }
}

/* --- cameras --------------------------------------------------------------- */

SDLStatic_Camera *SDLStatic_CameraCreate(SDLStatic_Engine *engine)
{
    SDLStatic_Camera *camera = (SDLStatic_Camera *)SDL_malloc(sizeof(SDLStatic_Camera));
    if (camera != NULL)
    {
        SDLStatic_CameraInit(camera, engine);
    }
    return camera;
}

void SDLStatic_CameraDestroy(SDLStatic_Camera *camera)
{
    SDL_free(camera);
}

void SDLStatic_CameraSetZoom(SDLStatic_Camera *camera, float zoom)
{
    if (camera != NULL)
    {
        camera->zoom = zoom;
    }
}

void SDLStatic_CameraSetSmoothing(SDLStatic_Camera *camera, float seconds)
{
    if (camera != NULL)
    {
        camera->smoothing = seconds;
    }
}

void SDLStatic_CameraSetDeadzone(SDLStatic_Camera *camera, float width, float height)
{
    if (camera != NULL)
    {
        camera->deadzone_w = width;
        camera->deadzone_h = height;
    }
}

void SDLStatic_CameraSetBounds(SDLStatic_Camera *camera, float x, float y, float w, float h)
{
    if (camera != NULL)
    {
        camera->bounds = (SDL_FRect){x, y, w, h};
    }
}

void SDLStatic_CameraSetViewport(SDLStatic_Camera *camera, float x, float y, float w, float h)
{
    if (camera != NULL)
    {
        camera->viewport = (SDL_FRect){x, y, w, h};
    }
}

float SDLStatic_CameraX(SDLStatic_Camera *camera)
{
    return (camera != NULL) ? camera->x : 0.0f;
}

float SDLStatic_CameraY(SDLStatic_Camera *camera)
{
    return (camera != NULL) ? camera->y : 0.0f;
}
