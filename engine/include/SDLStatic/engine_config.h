/**
 * @file engine_config.h
 * @brief Heap-allocated builders for the engine's plain-struct arguments.
 *
 * Original SDLStatic code (zlib).
 *
 * `SDLStatic_EngineConfig` and `SDLStatic_ActorDef` are plain structs a C
 * caller fills in on the stack. That is the right shape for C and the wrong
 * shape for a script, which has no stack to put one on and no way to write
 * a `const char *` or a function pointer into a field.
 *
 * These give the same structs a create/destroy pair and scalar setters:
 *
 *     -- Lua
 *     local cfg = SDLStaticC.ConfigCreate()
 *     SDLStaticC.ConfigSetDesignSize(cfg, 1920, 1080)
 *     SDLStaticC.ConfigSetTitle(cfg, "My Game")
 *     local engine = SDLStaticC.CreateEngine(cfg)
 *
 * The binding generator already understands that shape — a function pair
 * named create/destroy makes an owned, GC-managed handle, and setters
 * taking scalars bind themselves. So this costs one small C file and no
 * generator changes, and the resulting handles are freed by the script's
 * garbage collector if the author forgets.
 *
 * C code has no reason to use any of this: a struct on the stack is
 * cheaper and clearer. It exists for the languages that cannot do that.
 *
 * ### Strings are copied
 *
 * A `const char *` in the plain struct is borrowed, which is fine when the
 * caller owns a literal for the length of the call. A script's string may
 * be collected the moment the setter returns, so these copy — and the copy
 * lives and dies with the builder.
 */
#ifndef SDLSTATIC_ENGINE_CONFIG_H
#define SDLSTATIC_ENGINE_CONFIG_H

#include <SDLStatic/engine.h>
#include <SDLStatic/engine_actor.h>
#include <SDLStatic/engine_camera.h>
#include <SDLStatic/engine_graphics.h>
#include <SDLStatic/engine_light.h>
#include <SDLStatic/engine_physics.h>
#include <SDLStatic/engine_render.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --- engine config -------------------------------------------------------- */

/** A config on the heap, zeroed — so every field already has the documented
 *  default and a script only sets what it cares about. */
extern SDLStatic_EngineConfig *SDLStatic_ConfigCreate(void);

/** Free it. The engine copies what it needs during creation, so the config
 *  may be destroyed immediately afterwards. */
extern void SDLStatic_ConfigDestroy(SDLStatic_EngineConfig *config);

extern void SDLStatic_ConfigSetTitle(SDLStatic_EngineConfig *config, const char *title);
extern void SDLStatic_ConfigSetWindowSize(SDLStatic_EngineConfig *config, int width, int height);
extern void SDLStatic_ConfigSetDesignSize(SDLStatic_EngineConfig *config, int width, int height);
extern void SDLStatic_ConfigSetPresentation(SDLStatic_EngineConfig *config,
                                            SDLStatic_EnginePresentation presentation);
extern void SDLStatic_ConfigSetFullscreen(SDLStatic_EngineConfig *config, bool fullscreen);
extern void SDLStatic_ConfigSetVsync(SDLStatic_EngineConfig *config, bool vsync);
extern void SDLStatic_ConfigSetMaxFps(SDLStatic_EngineConfig *config, int max_fps);
extern void SDLStatic_ConfigSetTickRate(SDLStatic_EngineConfig *config, int ticks_per_second);
extern void SDLStatic_ConfigSetBackend(SDLStatic_EngineConfig *config,
                                       SDLStatic_EngineBackend backend);
extern void SDLStatic_ConfigSetResizable(SDLStatic_EngineConfig *config, bool resizable);
extern void SDLStatic_ConfigSetHighDpi(SDLStatic_EngineConfig *config, bool high_dpi);
extern void SDLStatic_ConfigSetHeadless(SDLStatic_EngineConfig *config, bool headless);
extern void SDLStatic_ConfigSetManualClock(SDLStatic_EngineConfig *config, bool manual);
extern void SDLStatic_ConfigSetMediaPath(SDLStatic_EngineConfig *config, const char *path);
extern void SDLStatic_ConfigSetAutoMount(SDLStatic_EngineConfig *config, bool enabled);

/** Apply resolved graphics settings. Copied, so the settings may be a
 *  temporary. */
extern void SDLStatic_ConfigSetGraphics(SDLStatic_EngineConfig *config,
                                        const SDLStatic_GraphicsSettings *graphics);

/* --- actor definitions ---------------------------------------------------- */

/** An actor definition on the heap, with the same defaults a zeroed struct
 *  has — except scale, which the engine already treats as 1 when zero. */
extern SDLStatic_ActorDef *SDLStatic_ActorDefCreate(void);
extern void SDLStatic_ActorDefDestroy(SDLStatic_ActorDef *def);

extern void SDLStatic_ActorDefSetType(SDLStatic_ActorDef *def, const char *type);
extern void SDLStatic_ActorDefSetName(SDLStatic_ActorDef *def, const char *name);
extern void SDLStatic_ActorDefSetPosition(SDLStatic_ActorDef *def, float x, float y);
extern void SDLStatic_ActorDefSetRotation(SDLStatic_ActorDef *def, float degrees);
extern void SDLStatic_ActorDefSetScale(SDLStatic_ActorDef *def, float x, float y);
extern void SDLStatic_ActorDefSetTags(SDLStatic_ActorDef *def, SDLStatic_ActorTags tags);
extern void SDLStatic_ActorDefSetParent(SDLStatic_ActorDef *def, SDLStatic_ActorId parent);

/** Bytes of per-actor state. A script has no use for raw bytes, so this is
 *  really for a C game building a def dynamically; a script keeps its own
 *  table keyed by actor id instead. */
extern void SDLStatic_ActorDefSetStateSize(SDLStatic_ActorDef *def, int size);

/* --- sprites, bodies and lights ------------------------------------------- */

/* Same treatment for the other structs a game fills in by hand. Each starts
   from the module's own default rather than zero, because a zeroed sprite is
   invisible and a zeroed body falls through the world. */

extern SDLStatic_Sprite *SDLStatic_SpriteCreate(void);
extern void SDLStatic_SpriteDestroy(SDLStatic_Sprite *sprite);
extern void SDLStatic_SpriteSetTexture(SDLStatic_Sprite *sprite, SDL_Texture *texture);
extern void SDLStatic_SpriteSetSize(SDLStatic_Sprite *sprite, float width, float height);
extern void SDLStatic_SpriteSetSource(SDLStatic_Sprite *sprite, float x, float y, float w,
                                      float h);
extern void SDLStatic_SpriteSetOrigin(SDLStatic_Sprite *sprite, float x, float y);
extern void SDLStatic_SpriteSetColor(SDLStatic_Sprite *sprite, float r, float g, float b,
                                     float a);
extern void SDLStatic_SpriteSetLayer(SDLStatic_Sprite *sprite, int layer, float order);
extern void SDLStatic_SpriteSetSortByY(SDLStatic_Sprite *sprite, bool enabled);
extern void SDLStatic_SpriteSetScreenSpace(SDLStatic_Sprite *sprite, bool enabled);
extern void SDLStatic_SpriteSetVisible(SDLStatic_Sprite *sprite, bool visible);

extern SDLStatic_BodyDef *SDLStatic_BodyDefCreate(void);
extern void SDLStatic_BodyDefDestroy(SDLStatic_BodyDef *def);
extern void SDLStatic_BodyDefSetType(SDLStatic_BodyDef *def, SDLStatic_BodyType type);
extern void SDLStatic_BodyDefSetShape(SDLStatic_BodyDef *def, SDLStatic_ShapeType shape);
extern void SDLStatic_BodyDefSetSize(SDLStatic_BodyDef *def, float width, float height);
extern void SDLStatic_BodyDefSetOffset(SDLStatic_BodyDef *def, float x, float y);
extern void SDLStatic_BodyDefSetMaterial(SDLStatic_BodyDef *def, float density, float friction,
                                         float restitution);
extern void SDLStatic_BodyDefSetFixedRotation(SDLStatic_BodyDef *def, bool fixed);
extern void SDLStatic_BodyDefSetSensor(SDLStatic_BodyDef *def, bool sensor);
extern void SDLStatic_BodyDefSetGravityScale(SDLStatic_BodyDef *def, float scale);
extern void SDLStatic_BodyDefSetFilter(SDLStatic_BodyDef *def, Uint32 category,
                                       Uint32 collides_with);
extern void SDLStatic_BodyDefSetBullet(SDLStatic_BodyDef *def, bool bullet);

extern SDLStatic_LightDef *SDLStatic_LightDefCreate(void);
extern void SDLStatic_LightDefDestroy(SDLStatic_LightDef *def);
extern void SDLStatic_LightDefSetRadius(SDLStatic_LightDef *def, float radius);
extern void SDLStatic_LightDefSetColor(SDLStatic_LightDef *def, float r, float g, float b,
                                       float a);
extern void SDLStatic_LightDefSetOffset(SDLStatic_LightDef *def, float x, float y);
extern void SDLStatic_LightDefSetCone(SDLStatic_LightDef *def, float direction, float width);
extern void SDLStatic_LightDefSetFlicker(SDLStatic_LightDef *def, float flicker);
extern void SDLStatic_LightDefSetShadows(SDLStatic_LightDef *def, bool casts_shadows);

/* --- cameras --------------------------------------------------------------- */

/** A camera on the heap. C games keep one in their own struct; a script
 *  needs a handle. */
extern SDLStatic_Camera *SDLStatic_CameraCreate(SDLStatic_Engine *engine);
extern void SDLStatic_CameraDestroy(SDLStatic_Camera *camera);
extern void SDLStatic_CameraSetZoom(SDLStatic_Camera *camera, float zoom);
extern void SDLStatic_CameraSetSmoothing(SDLStatic_Camera *camera, float seconds);
extern void SDLStatic_CameraSetDeadzone(SDLStatic_Camera *camera, float width, float height);
extern void SDLStatic_CameraSetBounds(SDLStatic_Camera *camera, float x, float y, float w,
                                      float h);
extern void SDLStatic_CameraSetViewport(SDLStatic_Camera *camera, float x, float y, float w,
                                        float h);
extern float SDLStatic_CameraX(SDLStatic_Camera *camera);
extern float SDLStatic_CameraY(SDLStatic_Camera *camera);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_CONFIG_H */
