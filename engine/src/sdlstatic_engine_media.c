/*
 * sdlstatic_engine_media.c — mounting the game's assets.
 * Original SDLStatic code (zlib).
 *
 * An opinionated default, which is the whole point: a game should not have
 * to write mounting code, and the same path should mean the same file
 * whether the assets are a directory on a developer's machine, a zip beside
 * a shipped executable, or bytes compiled into it.
 *
 * PhysFS is initialised here too, once, and left initialised — several
 * modules in this project use it, and deinitialising it under them when one
 * engine goes away would be worse than leaking a handful of bytes at exit.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_media.h>
#include <SDLStatic/vfs.h>

#include <physfs.h>

/* Set before the engine is created, because the mount happens during
   creation and there is nowhere else to put them. */
static const void *g_embedded_data = NULL;
static int g_embedded_size = 0;
static const char *g_embedded_password = NULL;
static char g_password[256];
static bool g_have_password = false;

void SDLStatic_EngineEmbedMedia(const void *data, int size, const char *password)
{
    g_embedded_data = data;
    g_embedded_size = size;
    g_embedded_password = password;
}

void SDLStatic_EngineSetMediaPassword(const char *password)
{
    if (password == NULL)
    {
        g_have_password = false;
        g_password[0] = '\0';
        return;
    }
    SDL_strlcpy(g_password, password, sizeof(g_password));
    g_have_password = true;
}

/* Everything mounts at the root, so a path means the same thing whatever it
   came out of. That is what lets a game move from a directory to a zip to
   an embedded blob without touching a line of code. */
#define MOUNT_POINT "/"

static bool MountArchiveFile(const char *path, const char *password)
{
    if (password != NULL && password[0] != '\0')
    {
        /* Encrypted: decrypt in memory, then mount the plaintext image. */
        if (SDLStatic_MountEncryptedArchiveFile(path, password, MOUNT_POINT))
        {
            return true;
        }
        /* Fall through: an unencrypted archive with a password set is not
           an error, it is a game that has not encrypted this build. */
    }
    return PHYSFS_mount(path, MOUNT_POINT, 1) != 0;
}

static bool Exists(const char *path)
{
    SDL_PathInfo info;
    return SDL_GetPathInfo(path, &info);
}

static bool IsDirectory(const char *path)
{
    SDL_PathInfo info;
    return SDL_GetPathInfo(path, &info) && info.type == SDL_PATHTYPE_DIRECTORY;
}

SDLStatic_MediaSource SDLStatic_MountMedia(const char *explicit_path, const char *password)
{
    if (!PHYSFS_isInit() && !PHYSFS_init(NULL))
    {
        SDL_SetError("PhysFS: %s", PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
        return SDLSTATIC_MEDIA_NONE;
    }

    /* 1. An explicit path replaces the search entirely — someone who says
          --media=/opt/game/assets means that, not that plus three guesses.
          A directory and an archive are both accepted, because the person
          typing it should not have to care which they have. */
    if (explicit_path != NULL && explicit_path[0] != '\0')
    {
        if (IsDirectory(explicit_path))
        {
            if (PHYSFS_mount(explicit_path, MOUNT_POINT, 1) != 0)
            {
                return SDLSTATIC_MEDIA_EXPLICIT;
            }
        }
        else if (MountArchiveFile(explicit_path, password))
        {
            return SDLSTATIC_MEDIA_EXPLICIT;
        }
        SDL_SetError("could not mount %s", explicit_path);
        return SDLSTATIC_MEDIA_NONE;
    }

    /* 2. Compiled into the executable. Ahead of the files on disk because a
          single-file build should not be quietly overridden by whatever
          happens to be sitting in the working directory. */
    if (g_embedded_data != NULL && g_embedded_size > 0)
    {
        const char *embedded_password =
            (g_embedded_password != NULL) ? g_embedded_password : password;
        bool mounted = false;
        if (embedded_password != NULL && embedded_password[0] != '\0')
        {
            mounted = SDLStatic_MountEncryptedArchive(g_embedded_data, g_embedded_size,
                                                      embedded_password, MOUNT_POINT);
        }
        if (!mounted)
        {
            mounted = PHYSFS_mountMemory(g_embedded_data, (PHYSFS_uint64)g_embedded_size, NULL,
                                         "media.zip", MOUNT_POINT, 1) != 0;
        }
        if (mounted)
        {
            return SDLSTATIC_MEDIA_EMBEDDED;
        }
    }

    /* 3 and 4. Archives beside the executable. `.dat` as well as `.zip`
       because a zip next to a game invites a double-click, and a player who
       opens it and drags a file out has broken their install. */
    static const char *kArchives[] = {"media.zip", "media.dat"};
    for (size_t i = 0; i < SDL_arraysize(kArchives); ++i)
    {
        if (Exists(kArchives[i]) && MountArchiveFile(kArchives[i], password))
        {
            return SDLSTATIC_MEDIA_ARCHIVE;
        }
    }

    /* 5. A plain directory: what development runs against. Last, so that
       building a release archive changes what the game reads without
       anybody having to remember to delete the directory. */
    if (IsDirectory("media") && PHYSFS_mount("media", MOUNT_POINT, 1) != 0)
    {
        return SDLSTATIC_MEDIA_DIRECTORY;
    }

    return SDLSTATIC_MEDIA_NONE;
}

/* The description that goes with a source, for logging. */
static const char *SourceLabel(SDLStatic_MediaSource source, const char *explicit_path)
{
    switch (source)
    {
    case SDLSTATIC_MEDIA_EXPLICIT:
        return explicit_path;
    case SDLSTATIC_MEDIA_EMBEDDED:
        return "(embedded)";
    case SDLSTATIC_MEDIA_ARCHIVE:
        return Exists("media.zip") ? "media.zip" : "media.dat";
    case SDLSTATIC_MEDIA_DIRECTORY:
        return "media/";
    case SDLSTATIC_MEDIA_NONE:
    default:
        return NULL;
    }
}

/* Reads a config file out of whatever was mounted, so the settings resolver
   can find the defaults a game shipped with. Installed by the engine. */
static bool ReadFromVfs(const char *path, char **text, void *user)
{
    (void)user;
    if (!PHYSFS_isInit() || path == NULL || text == NULL)
    {
        return false;
    }
    int size = 0;
    unsigned char *data = SDLStatic_LoadVFSFile(path, &size);
    if (data == NULL)
    {
        return false;
    }
    *text = (char *)data;
    return true;
}

/* --media / --media-password, in the same two spellings the graphics
   arguments accept. Parsed here rather than in the settings resolver
   because assets are mounted before settings are read — the config the game
   shipped lives inside the archive. */
static const char *ArgAfter(const char *key, int argc, char *const *argv)
{
    const size_t klen = SDL_strlen(key);
    for (int i = 1; i < argc && argv != NULL; ++i)
    {
        if (SDL_strncmp(argv[i], key, klen) != 0)
        {
            continue;
        }
        if (argv[i][klen] == '=')
        {
            return argv[i] + klen + 1;
        }
        if (argv[i][klen] == '\0' && i + 1 < argc)
        {
            return argv[i + 1];
        }
    }
    return NULL;
}

void SDLStatic_EngineMountMedia(SDLStatic_Engine *engine, const char *explicit_path, int argc,
                                char *const *argv)
{
    /* An explicit path in the config beats the command line: a game that
       hard-codes where its assets are has said so deliberately. */
    if (explicit_path == NULL)
    {
        explicit_path = ArgAfter("--media", argc, argv);
    }
    const char *from_args = ArgAfter("--media-password", argc, argv);
    if (from_args != NULL)
    {
        SDLStatic_EngineSetMediaPassword(from_args);
    }

    const char *password = g_have_password ? g_password : NULL;
    engine->media_source = SDLStatic_MountMedia(explicit_path, password);

    const char *label = SourceLabel(engine->media_source, explicit_path);
    if (label != NULL)
    {
        SDL_strlcpy(engine->media_path, label, sizeof(engine->media_path));
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "media: mounted %s", label);
    }
    else
    {
        engine->media_path[0] = '\0';
        /* Not an error: a game may embed its assets some other way, or have
           none. Worth saying once, because "my textures will not load" is
           usually this. */
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                    "media: nothing to mount (looked for media.zip, media.dat, media/)");
    }
}

void SDLStatic_EngineInstallConfigReader(void)
{
    SDLStatic_GraphicsSetArchiveReader(ReadFromVfs, NULL);
}

SDLStatic_MediaSource SDLStatic_EngineMediaSource(SDLStatic_Engine *engine)
{
    return (engine != NULL) ? engine->media_source : SDLSTATIC_MEDIA_NONE;
}

const char *SDLStatic_EngineMediaPath(SDLStatic_Engine *engine)
{
    if (engine == NULL || engine->media_path[0] == '\0')
    {
        return NULL;
    }
    return engine->media_path;
}
