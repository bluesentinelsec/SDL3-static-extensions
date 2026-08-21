/**
 * @file engine_save.h
 * @brief Save slots: writing without losing what was already there.
 *
 * Original SDLStatic code (zlib).
 *
 * The engine provides the **primitives**, not the data model. It knows how
 * to put bytes somewhere safe, enumerate what is there, and hand it back;
 * it never learns what a save contains. That division is deliberate — a
 * save format is the most game-specific thing a game has, and an engine
 * that imposed one would be wrong for every game in a different way.
 *
 *     SDLStatic_SaveWrite(engine, 1, state, sizeof(state), "Cave of Ordeals");
 *
 *     size_t size = 0;
 *     void *data = SDLStatic_SaveRead(engine, 1, &size);
 *     if (data != NULL && size == sizeof(state)) {
 *         SDL_memcpy(&state, data, size);
 *     }
 *     SDL_free(data);
 *
 * ### Writes are atomic
 *
 * A save is written to a temporary file, flushed, and then renamed over the
 * target. Rename is atomic on every platform this runs on, so the old save
 * survives intact until the new one is complete on disk.
 *
 * This is the whole reason to have save primitives in an engine at all. The
 * obvious implementation — open the save file, write into it — destroys the
 * player's progress if the game crashes, the battery dies, or the disk
 * fills up halfway through. It fails rarely, and when it does it takes
 * something irreplaceable, which is the worst possible combination.
 */
#ifndef SDLSTATIC_ENGINE_SAVE_H
#define SDLSTATIC_ENGINE_SAVE_H

#include <SDLStatic/engine.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Slots a game may use, 0..15. Sixteen because a UI that shows more than
 *  that is a file browser, and a game that needs one should write its own
 *  files rather than pretending they are slots. */
#define SDLSTATIC_SAVE_SLOTS 16

/** Which organisation and game the save directory belongs to. Call once,
 *  before anything else here; the engine remembers it. Without it, saves
 *  go under "SDLStatic/Game", which works and is not what you want to
 *  ship. */
extern void SDLStatic_SaveSetIdentity(SDLStatic_Engine *engine, const char *org,
                                      const char *app);

/**
 * Write a slot, atomically.
 *
 * `label` is optional and is stored beside the data for
 * SDLStatic_SaveInfo — a chapter name, a location, whatever a load menu
 * should show without having to parse the save itself.
 *
 * Returns false and sets SDL_GetError() on failure, having left any
 * existing save untouched.
 */
extern bool SDLStatic_SaveWrite(SDLStatic_Engine *engine, int slot, const void *data,
                                size_t size, const char *label);

/** Read a slot. Returns a SDL_malloc'd buffer — free it with SDL_free — or
 *  NULL if the slot is empty or unreadable. */
extern void *SDLStatic_SaveRead(SDLStatic_Engine *engine, int slot, size_t *size);

/** Is there anything in this slot? */
extern bool SDLStatic_SaveExists(SDLStatic_Engine *engine, int slot);

/** Delete a slot. Deleting an empty slot is not an error. */
extern bool SDLStatic_SaveDelete(SDLStatic_Engine *engine, int slot);

/** What a load menu needs to draw a row without reading the save. */
typedef struct SDLStatic_SaveInfo
{
    bool exists;
    size_t size;
    Sint64 modified;   /**< unix time, for "most recent" ordering */
    char label[128];
} SDLStatic_SaveInfo;

extern SDLStatic_SaveInfo SDLStatic_SaveInfoOf(SDLStatic_Engine *engine, int slot);

/** The path a slot writes to, for logging and for a player who wants to
 *  back one up. SDL_malloc'd, or NULL. */
extern char *SDLStatic_SavePath(SDLStatic_Engine *engine, int slot);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_SAVE_H */
