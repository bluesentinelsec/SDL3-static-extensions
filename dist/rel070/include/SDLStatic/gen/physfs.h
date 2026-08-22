// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: PhysFS
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_PHYSFS_H_
#define SDLSTATIC_CPP_GEN_PHYSFS_H_

#include <physfs.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace vfs {

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& caseFold = ::PHYSFS_caseFold;
inline constexpr auto& close = ::PHYSFS_close;
inline constexpr auto& deinit = ::PHYSFS_deinit;
inline constexpr auto& delete_ = ::PHYSFS_delete;
inline constexpr auto& deregisterArchiver = ::PHYSFS_deregisterArchiver;
inline constexpr auto& enumerate = ::PHYSFS_enumerate;
inline constexpr auto& enumerateFiles = ::PHYSFS_enumerateFiles;
inline constexpr auto& eof = ::PHYSFS_eof;
inline constexpr auto& exists = ::PHYSFS_exists;
inline constexpr auto& fileLength = ::PHYSFS_fileLength;
inline constexpr auto& flush = ::PHYSFS_flush;
inline constexpr auto& freeList = ::PHYSFS_freeList;
inline constexpr auto& getAllocator = ::PHYSFS_getAllocator;
inline constexpr auto& getBaseDir = ::PHYSFS_getBaseDir;
inline constexpr auto& getCdRomDirs = ::PHYSFS_getCdRomDirs;
inline constexpr auto& getCdRomDirsCallback = ::PHYSFS_getCdRomDirsCallback;
inline constexpr auto& getDirSeparator = ::PHYSFS_getDirSeparator;
inline constexpr auto& getErrorByCode = ::PHYSFS_getErrorByCode;
inline constexpr auto& getLastErrorCode = ::PHYSFS_getLastErrorCode;
inline constexpr auto& getLinkedVersion = ::PHYSFS_getLinkedVersion;
inline constexpr auto& getMountPoint = ::PHYSFS_getMountPoint;
inline constexpr auto& getPrefDir = ::PHYSFS_getPrefDir;
inline constexpr auto& getRealDir = ::PHYSFS_getRealDir;
inline constexpr auto& getSearchPath = ::PHYSFS_getSearchPath;
inline constexpr auto& getSearchPathCallback = ::PHYSFS_getSearchPathCallback;
inline constexpr auto& getWriteDir = ::PHYSFS_getWriteDir;
inline constexpr auto& init = ::PHYSFS_init;
inline constexpr auto& isInit = ::PHYSFS_isInit;
inline constexpr auto& mkdir = ::PHYSFS_mkdir;
inline constexpr auto& mount = ::PHYSFS_mount;
inline constexpr auto& mountHandle = ::PHYSFS_mountHandle;
inline constexpr auto& mountIo = ::PHYSFS_mountIo;
inline constexpr auto& mountMemory = ::PHYSFS_mountMemory;
inline constexpr auto& openAppend = ::PHYSFS_openAppend;
inline constexpr auto& openRead = ::PHYSFS_openRead;
inline constexpr auto& openWrite = ::PHYSFS_openWrite;
inline constexpr auto& permitSymbolicLinks = ::PHYSFS_permitSymbolicLinks;
inline constexpr auto& readBytes = ::PHYSFS_readBytes;
inline constexpr auto& readSBE16 = ::PHYSFS_readSBE16;
inline constexpr auto& readSBE32 = ::PHYSFS_readSBE32;
inline constexpr auto& readSBE64 = ::PHYSFS_readSBE64;
inline constexpr auto& readSLE16 = ::PHYSFS_readSLE16;
inline constexpr auto& readSLE32 = ::PHYSFS_readSLE32;
inline constexpr auto& readSLE64 = ::PHYSFS_readSLE64;
inline constexpr auto& readUBE16 = ::PHYSFS_readUBE16;
inline constexpr auto& readUBE32 = ::PHYSFS_readUBE32;
inline constexpr auto& readUBE64 = ::PHYSFS_readUBE64;
inline constexpr auto& readULE16 = ::PHYSFS_readULE16;
inline constexpr auto& readULE32 = ::PHYSFS_readULE32;
inline constexpr auto& readULE64 = ::PHYSFS_readULE64;
inline constexpr auto& registerArchiver = ::PHYSFS_registerArchiver;
inline constexpr auto& seek = ::PHYSFS_seek;
inline constexpr auto& setAllocator = ::PHYSFS_setAllocator;
inline constexpr auto& setBuffer = ::PHYSFS_setBuffer;
inline constexpr auto& setErrorCode = ::PHYSFS_setErrorCode;
inline constexpr auto& setRoot = ::PHYSFS_setRoot;
inline constexpr auto& setSaneConfig = ::PHYSFS_setSaneConfig;
inline constexpr auto& setWriteDir = ::PHYSFS_setWriteDir;
inline constexpr auto& stat = ::PHYSFS_stat;
inline constexpr auto& supportedArchiveTypes = ::PHYSFS_supportedArchiveTypes;
inline constexpr auto& swapSBE16 = ::PHYSFS_swapSBE16;
inline constexpr auto& swapSBE32 = ::PHYSFS_swapSBE32;
inline constexpr auto& swapSBE64 = ::PHYSFS_swapSBE64;
inline constexpr auto& swapSLE16 = ::PHYSFS_swapSLE16;
inline constexpr auto& swapSLE32 = ::PHYSFS_swapSLE32;
inline constexpr auto& swapSLE64 = ::PHYSFS_swapSLE64;
inline constexpr auto& swapUBE16 = ::PHYSFS_swapUBE16;
inline constexpr auto& swapUBE32 = ::PHYSFS_swapUBE32;
inline constexpr auto& swapUBE64 = ::PHYSFS_swapUBE64;
inline constexpr auto& swapULE16 = ::PHYSFS_swapULE16;
inline constexpr auto& swapULE32 = ::PHYSFS_swapULE32;
inline constexpr auto& swapULE64 = ::PHYSFS_swapULE64;
inline constexpr auto& symbolicLinksPermitted = ::PHYSFS_symbolicLinksPermitted;
inline constexpr auto& tell = ::PHYSFS_tell;
inline constexpr auto& ucs4stricmp = ::PHYSFS_ucs4stricmp;
inline constexpr auto& unmount = ::PHYSFS_unmount;
inline constexpr auto& utf16stricmp = ::PHYSFS_utf16stricmp;
inline constexpr auto& utf8FromLatin1 = ::PHYSFS_utf8FromLatin1;
inline constexpr auto& utf8FromUcs2 = ::PHYSFS_utf8FromUcs2;
inline constexpr auto& utf8FromUcs4 = ::PHYSFS_utf8FromUcs4;
inline constexpr auto& utf8FromUtf16 = ::PHYSFS_utf8FromUtf16;
inline constexpr auto& utf8ToUcs2 = ::PHYSFS_utf8ToUcs2;
inline constexpr auto& utf8ToUcs4 = ::PHYSFS_utf8ToUcs4;
inline constexpr auto& utf8ToUtf16 = ::PHYSFS_utf8ToUtf16;
inline constexpr auto& utf8stricmp = ::PHYSFS_utf8stricmp;
inline constexpr auto& writeBytes = ::PHYSFS_writeBytes;
inline constexpr auto& writeSBE16 = ::PHYSFS_writeSBE16;
inline constexpr auto& writeSBE32 = ::PHYSFS_writeSBE32;
inline constexpr auto& writeSBE64 = ::PHYSFS_writeSBE64;
inline constexpr auto& writeSLE16 = ::PHYSFS_writeSLE16;
inline constexpr auto& writeSLE32 = ::PHYSFS_writeSLE32;
inline constexpr auto& writeSLE64 = ::PHYSFS_writeSLE64;
inline constexpr auto& writeUBE16 = ::PHYSFS_writeUBE16;
inline constexpr auto& writeUBE32 = ::PHYSFS_writeUBE32;
inline constexpr auto& writeUBE64 = ::PHYSFS_writeUBE64;
inline constexpr auto& writeULE16 = ::PHYSFS_writeULE16;
inline constexpr auto& writeULE32 = ::PHYSFS_writeULE32;
inline constexpr auto& writeULE64 = ::PHYSFS_writeULE64;

}  // namespace vfs
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_PHYSFS_H_
// clang-format on
