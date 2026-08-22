/**
 * @file engine_media.h
 * @brief Where a game's assets come from, and the opinionated default.
 *
 * Original SDLStatic code (zlib).
 *
 * The engine mounts the game's assets for you. It happens during
 * SDLStatic_CreateEngine, before anything asks for a file, and the search
 * order is fixed:
 *
 *   1. `--media=PATH` on the command line, or `config.media_path`
 *   2. an archive compiled into the executable (SDLStatic_EngineEmbedMedia)
 *   3. `media.zip`     beside the executable — possibly encrypted
 *   4. `media.dat`     the same, named so it does not invite a double-click
 *   5. `media/`        a plain directory: what you develop against
 *
 * The first one found wins, and everything lands at `/` in the VFS, so
 * `assets/player.png` means the same thing whether it came out of a zip or
 * off the disk. That is the point of the ordering: a developer works
 * against `media/`, ships `media.zip`, and one day embeds the archive in
 * the binary — and not one line of the game changes.
 *
 * Reading uses PhysFS and SDLStatic::VFS directly:
 *
 *     SDL_IOStream *io = SDLStatic_OpenVFSRead("assets/player.png");
 *     SDL_Texture *tex = IMG_LoadTexture_IO(renderer, io, true);
 *
 * A game that wants none of this sets `config.no_auto_mount` and does its
 * own mounting; the engine will not touch PhysFS beyond initialising it.
 */
#ifndef SDLSTATIC_ENGINE_MEDIA_H
#define SDLSTATIC_ENGINE_MEDIA_H

#include <SDLStatic/engine.h>

#ifdef __cplusplus
extern "C" {
#endif

/** What the engine actually mounted, so a game can log it — "which copy of
 *  my assets is this running against" is a question worth being able to
 *  answer. */
typedef enum SDLStatic_MediaSource
{
    SDLSTATIC_MEDIA_NONE = 0, /**< nothing found; the VFS is empty */
    SDLSTATIC_MEDIA_EXPLICIT, /**< --media, or config.media_path */
    SDLSTATIC_MEDIA_EMBEDDED, /**< compiled into the executable */
    SDLSTATIC_MEDIA_ARCHIVE,  /**< media.zip or media.dat on disk */
    SDLSTATIC_MEDIA_DIRECTORY /**< a plain media/ directory */
} SDLStatic_MediaSource;

/**
 * Hand the engine an archive compiled into the executable.
 *
 * Call **before** SDLStatic_CreateEngine — the mount happens during
 * creation. The bytes are not copied, so they must outlive the engine,
 * which is automatic for the usual `static const unsigned char kMedia[]`
 * produced by `scripts/pack_assets.py --header`.
 *
 * `password` is the one the archive was packed with, or NULL for a plain
 * zip. Embedding an encrypted archive with its password in the same binary
 * is obfuscation rather than security, and worth being clear-eyed about:
 * it stops casual extraction, not a determined person with a debugger.
 */
extern void SDLStatic_EngineEmbedMedia(const void *data, int size, const char *password);

/** Where the archive on disk is encrypted, the password to open it with.
 *  Also settable with `--media-password`. Call before creating the engine. */
extern void SDLStatic_EngineSetMediaPassword(const char *password);

/** Which of the five sources the engine mounted. */
extern SDLStatic_MediaSource SDLStatic_EngineMediaSource(SDLStatic_Engine *engine);

/** The path or description of what was mounted — "media.zip", "media/", the
 *  explicit path, or "(embedded)". NULL when nothing was. */
extern const char *SDLStatic_EngineMediaPath(SDLStatic_Engine *engine);

/**
 * Run the search by hand, against an already-initialised PhysFS.
 *
 * The engine calls this for you; it is exposed for a tool that wants the
 * same behaviour without a window, and for a game that mounts a second
 * archive later (DLC, a mod directory). Returns what it mounted.
 */
extern SDLStatic_MediaSource SDLStatic_MountMedia(const char *explicit_path,
                                                  const char *password);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_MEDIA_H */
