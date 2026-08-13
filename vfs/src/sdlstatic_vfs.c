/*
 * sdlstatic_vfs.c — encrypted-asset glue over PhysFS for SDLStatic VFS.
 *
 * Original SDLStatic code (zlib). See SDLStatic/vfs.h for the pipeline.
 */
#include <SDLStatic/crypto.h>
#include <SDLStatic/vfs.h>
#include <physfs.h>

/* Every memory mount needs a unique virtual filename. */
static SDL_AtomicInt mount_counter;

static void FreeMountedImage(void *buf)
{
    SDL_free(buf);
}

static bool SetPhysfsError(const char *what)
{
    const PHYSFS_ErrorCode code = PHYSFS_getLastErrorCode();
    return SDL_SetError("%s: %s", what, PHYSFS_getErrorByCode(code));
}

bool SDLStatic_MountEncryptedArchive(const void *data, int dataSize, const char *password,
                                     const char *mountPoint)
{
    if (data == NULL || password == NULL)
    {
        return SDL_InvalidParamError("data/password");
    }
    if (!PHYSFS_isInit())
    {
        return SDL_SetError("PhysFS is not initialized (call PHYSFS_init first)");
    }

    int plainSize = 0;
    unsigned char *plain =
        SDLStatic_DecryptData((const unsigned char *)data, dataSize, password, &plainSize);
    if (plain == NULL)
    {
        return false; /* SDL error already set: wrong password / tampered */
    }

    char name[64];
    SDL_snprintf(name, sizeof(name), "sse-mount-%d.zip", SDL_AddAtomicInt(&mount_counter, 1));
    if (!PHYSFS_mountMemory(plain, (PHYSFS_uint64)plainSize, FreeMountedImage, name,
                            mountPoint, 1))
    {
        const bool result = SetPhysfsError("cannot mount decrypted archive");
        SDL_free(plain); /* PhysFS only takes ownership on success */
        return result;
    }
    return true;
}

bool SDLStatic_MountEncryptedArchiveFile(const char *path, const char *password,
                                         const char *mountPoint)
{
    if (path == NULL)
    {
        return SDL_InvalidParamError("path");
    }
    size_t size = 0;
    void *blob = SDL_LoadFile(path, &size);
    if (blob == NULL)
    {
        return false;
    }
    if (size > (size_t)SDL_MAX_SINT32)
    {
        SDL_free(blob);
        return SDL_SetError("file too large");
    }
    const bool ok = SDLStatic_MountEncryptedArchive(blob, (int)size, password, mountPoint);
    SDL_free(blob);
    return ok;
}

/* ------------------------------------------------- SDL_IOStream bridge --- */

static Sint64 VfsStreamSize(void *userdata)
{
    const PHYSFS_sint64 len = PHYSFS_fileLength((PHYSFS_File *)userdata);
    return (len < 0) ? -1 : (Sint64)len;
}

static Sint64 VfsStreamSeek(void *userdata, Sint64 offset, SDL_IOWhence whence)
{
    PHYSFS_File *file = (PHYSFS_File *)userdata;
    Sint64 target = 0;
    switch (whence)
    {
    case SDL_IO_SEEK_SET:
        target = offset;
        break;
    case SDL_IO_SEEK_CUR:
        target = (Sint64)PHYSFS_tell(file) + offset;
        break;
    case SDL_IO_SEEK_END:
        target = (Sint64)PHYSFS_fileLength(file) + offset;
        break;
    default:
        SDL_InvalidParamError("whence");
        return -1;
    }
    if (target < 0 || !PHYSFS_seek(file, (PHYSFS_uint64)target))
    {
        SetPhysfsError("seek failed");
        return -1;
    }
    return target;
}

static size_t VfsStreamRead(void *userdata, void *ptr, size_t size, SDL_IOStatus *status)
{
    PHYSFS_File *file = (PHYSFS_File *)userdata;
    const PHYSFS_sint64 got = PHYSFS_readBytes(file, ptr, (PHYSFS_uint64)size);
    if (got < 0)
    {
        *status = SDL_IO_STATUS_ERROR;
        SetPhysfsError("read failed");
        return 0;
    }
    if ((size_t)got < size)
    {
        *status = PHYSFS_eof(file) ? SDL_IO_STATUS_EOF : SDL_IO_STATUS_ERROR;
    }
    return (size_t)got;
}

static size_t VfsStreamWrite(void *userdata, const void *ptr, size_t size, SDL_IOStatus *status)
{
    (void)userdata;
    (void)ptr;
    (void)size;
    *status = SDL_IO_STATUS_READONLY;
    SDL_SetError("VFS streams are read-only");
    return 0;
}

static bool VfsStreamClose(void *userdata)
{
    if (!PHYSFS_close((PHYSFS_File *)userdata))
    {
        return SetPhysfsError("close failed");
    }
    return true;
}

SDL_IOStream *SDLStatic_OpenVFSRead(const char *vfsPath)
{
    if (vfsPath == NULL)
    {
        SDL_InvalidParamError("vfsPath");
        return NULL;
    }
    PHYSFS_File *file = PHYSFS_openRead(vfsPath);
    if (file == NULL)
    {
        SetPhysfsError(vfsPath);
        return NULL;
    }
    SDL_IOStreamInterface iface;
    SDL_INIT_INTERFACE(&iface);
    iface.size = VfsStreamSize;
    iface.seek = VfsStreamSeek;
    iface.read = VfsStreamRead;
    iface.write = VfsStreamWrite;
    iface.close = VfsStreamClose;
    SDL_IOStream *stream = SDL_OpenIO(&iface, file);
    if (stream == NULL)
    {
        PHYSFS_close(file);
        return NULL;
    }
    return stream;
}

unsigned char *SDLStatic_LoadVFSFile(const char *vfsPath, int *size)
{
    if (size != NULL)
    {
        *size = 0;
    }
    if (vfsPath == NULL || size == NULL)
    {
        SDL_InvalidParamError("vfsPath/size");
        return NULL;
    }
    PHYSFS_File *file = PHYSFS_openRead(vfsPath);
    if (file == NULL)
    {
        SetPhysfsError(vfsPath);
        return NULL;
    }
    const PHYSFS_sint64 len = PHYSFS_fileLength(file);
    if (len < 0 || len > SDL_MAX_SINT32)
    {
        PHYSFS_close(file);
        SDL_SetError("file has unknown or oversized length");
        return NULL;
    }
    unsigned char *buf = (unsigned char *)SDL_malloc((len > 0) ? (size_t)len : 1);
    if (buf == NULL)
    {
        PHYSFS_close(file);
        return NULL;
    }
    const PHYSFS_sint64 got = PHYSFS_readBytes(file, buf, (PHYSFS_uint64)len);
    PHYSFS_close(file);
    if (got != len)
    {
        SDL_free(buf);
        SetPhysfsError("short read");
        return NULL;
    }
    *size = (int)len;
    return buf;
}
