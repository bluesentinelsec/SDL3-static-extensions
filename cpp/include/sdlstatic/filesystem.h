// filesystem.h — RAII over PhysFS + the SDLStatic encrypted-asset pipeline.
// Original SDLStatic code (zlib).

#ifndef SDLSTATIC_CPP_FILESYSTEM_H_
#define SDLSTATIC_CPP_FILESYSTEM_H_

#include <SDLStatic/vfs.h>
#include <physfs.h>

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

#include "sdlstatic/status.h"

namespace sdlstatic {

// Owns PhysFS initialization; deinitializes on destruction. Create exactly
// one, before any Mount.
class Vfs {
 public:
  static Result<Vfs> Create() {
    if (!PHYSFS_isInit() && !PHYSFS_init(nullptr)) {
      return Status::Error(PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
    }
    return Vfs(true);
  }

  ~Vfs() {
    if (owned_ && PHYSFS_isInit()) PHYSFS_deinit();
  }
  Vfs(Vfs&& other) noexcept : owned_(std::exchange(other.owned_, false)) {}
  Vfs& operator=(Vfs&& other) noexcept {
    std::swap(owned_, other.owned_);
    return *this;
  }
  Vfs(const Vfs&) = delete;
  Vfs& operator=(const Vfs&) = delete;

  // Reads an entire file from the mounted VFS.
  Result<std::vector<std::uint8_t>> ReadFile(const std::string& vfs_path) const {
    int size = 0;
    unsigned char* data = SDLStatic_LoadVFSFile(vfs_path.c_str(), &size);
    if (data == nullptr) return Status::FromSdl();
    std::vector<std::uint8_t> out(data, data + size);
    SDL_free(data);
    return out;
  }

  bool Exists(const std::string& vfs_path) const {
    return PHYSFS_exists(vfs_path.c_str()) != 0;
  }

 private:
  explicit Vfs(bool owned) : owned_(owned) {}
  bool owned_ = false;
};

// One mounted archive or directory; unmounts on destruction.
class Mount {
 public:
  static Result<Mount> Archive(const std::string& path, const std::string& mount_point = "/") {
    if (!PHYSFS_mount(path.c_str(), mount_point.c_str(), 1)) {
      return Status::Error(PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()));
    }
    return Mount(path);
  }

  // Decrypts an SSE1 container from disk and mounts the zip image within.
  // The decrypted image stays in memory until this Mount is destroyed.
  static Result<Mount> EncryptedArchive(const std::string& path, const std::string& password,
                                        const std::string& mount_point = "/") {
    if (!SDLStatic_MountEncryptedArchiveFile(path.c_str(), password.c_str(),
                                             mount_point.c_str())) {
      return Status::FromSdl();
    }
    // Encrypted mounts register under a generated name; PhysFS unmounts them
    // at deinit. Track no name: lifetime rides on the Vfs.
    return Mount(std::string());
  }

  ~Mount() {
    if (!name_.empty() && PHYSFS_isInit()) PHYSFS_unmount(name_.c_str());
  }
  Mount(Mount&& other) noexcept : name_(std::exchange(other.name_, std::string())) {}
  Mount& operator=(Mount&& other) noexcept {
    std::swap(name_, other.name_);
    return *this;
  }
  Mount(const Mount&) = delete;
  Mount& operator=(const Mount&) = delete;

 private:
  explicit Mount(std::string name) : name_(std::move(name)) {}
  std::string name_;
};

}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_FILESYSTEM_H_
