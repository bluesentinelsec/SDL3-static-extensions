/**
 * @file tiled.h
 * @brief Tiled map (.tmj JSON) loading over vendored cute_tiled.
 *
 * Original SDLStatic code (zlib) around cute_tiled (single dependency-free
 * C header, dual zlib/public-domain; provenance in deps/cute_tiled.md).
 * Loads through the PhysFS VFS when initialized (maps can live in mounted,
 * optionally encrypted, zip archives) with filesystem fallback. This flat
 * accessor API is what the Lua/Ruby/C++ bindings wrap; the full parsed
 * cute_tiled_map_t is reachable via SDLStatic_TiledRaw for C users.
 */
#ifndef SDLSTATIC_TILED_H
#define SDLSTATIC_TILED_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SDLStatic_TiledMap SDLStatic_TiledMap;
typedef struct cute_tiled_map_t cute_tiled_map_t;

typedef struct SDLStatic_TiledObject
{
    const char *name; /* borrowed from the map; valid until free */
    const char *type;
    float x, y, w, h;
} SDLStatic_TiledObject;

/** Load a .tmj map (VFS first, then filesystem). NULL + SDL_GetError on
 *  parse failure. Free with SDLStatic_FreeTiledMap. */
extern SDLStatic_TiledMap *SDLStatic_LoadTiledMap(const char *path);
extern void SDLStatic_FreeTiledMap(SDLStatic_TiledMap *map);

extern int SDLStatic_TiledMapWidth(const SDLStatic_TiledMap *map);   /* in tiles */
extern int SDLStatic_TiledMapHeight(const SDLStatic_TiledMap *map);  /* in tiles */
extern int SDLStatic_TiledTileWidth(const SDLStatic_TiledMap *map);  /* in pixels */
extern int SDLStatic_TiledTileHeight(const SDLStatic_TiledMap *map); /* in pixels */

extern int SDLStatic_TiledLayerCount(const SDLStatic_TiledMap *map);
/** NULL when idx is out of range. */
extern const char *SDLStatic_TiledLayerName(const SDLStatic_TiledMap *map, int idx);
/** "tilelayer", "objectgroup", ... — NULL when out of range. */
extern const char *SDLStatic_TiledLayerType(const SDLStatic_TiledMap *map, int idx);

/** Tile GID at (x, y) of a tilelayer: 0 = empty, -1 = bad layer/coords. */
extern int SDLStatic_TiledTileAt(const SDLStatic_TiledMap *map, int layer, int x, int y);

/** Number of objects in an objectgroup layer (0 for tile layers). */
extern int SDLStatic_TiledObjectCount(const SDLStatic_TiledMap *map, int layer);
/** False when indices are out of range. */
extern bool SDLStatic_TiledObjectAt(const SDLStatic_TiledMap *map, int layer, int index,
                                    SDLStatic_TiledObject *out);

/** The full cute_tiled parse tree (tilesets, properties, animations...). */
extern cute_tiled_map_t *SDLStatic_TiledRaw(SDLStatic_TiledMap *map);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_TILED_H */
