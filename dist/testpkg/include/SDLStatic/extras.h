// extras.h — value-typed crypto/compress/base64 + RAII signals.
// Original SDLStatic code (zlib).

#ifndef SDLSTATIC_CPP_EXTRAS_H_
#define SDLSTATIC_CPP_EXTRAS_H_

#include <SDLStatic/base64.h>
#include <SDLStatic/compress.h>
#include <SDLStatic/crypto.h>
#include <SDLStatic/signals.h>

#include <cstdint>
#include <functional>
#include <memory>
#include <span>
#include <string>
#include <utility>
#include <vector>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace internal {

inline Result<std::vector<std::uint8_t>> WrapBytes(unsigned char* out, int size) {
  if (out == nullptr) return Status::FromSdl();
  std::vector<std::uint8_t> result(out, out + size);
  SDL_free(out);
  return result;
}

}  // namespace internal

// --- crypto / compress / base64: pure value transformations --------------

inline Result<std::vector<std::uint8_t>> Compress(std::span<const std::uint8_t> data) {
  int size = 0;
  unsigned char* out =
      SDLStatic_CompressData(data.data(), static_cast<int>(data.size()), &size);
  return internal::WrapBytes(out, size);
}

inline Result<std::vector<std::uint8_t>> Decompress(std::span<const std::uint8_t> data) {
  int size = 0;
  unsigned char* out =
      SDLStatic_DecompressData(data.data(), static_cast<int>(data.size()), &size);
  return internal::WrapBytes(out, size);
}

inline Result<std::vector<std::uint8_t>> Encrypt(std::span<const std::uint8_t> data,
                                                 const std::string& password) {
  int size = 0;
  unsigned char* out = SDLStatic_EncryptData(data.data(), static_cast<int>(data.size()),
                                             password.c_str(), &size);
  return internal::WrapBytes(out, size);
}

// Fails (with the SDL error text) on a wrong password or tampered data.
inline Result<std::vector<std::uint8_t>> Decrypt(std::span<const std::uint8_t> data,
                                                 const std::string& password) {
  int size = 0;
  unsigned char* out = SDLStatic_DecryptData(data.data(), static_cast<int>(data.size()),
                                             password.c_str(), &size);
  return internal::WrapBytes(out, size);
}

inline Result<std::string> Base64Encode(std::span<const std::uint8_t> data) {
  int size = 0;
  char* out = SDLStatic_EncodeDataBase64(data.data(), static_cast<int>(data.size()), &size);
  if (out == nullptr) return Status::FromSdl();
  std::string result(out, static_cast<std::size_t>(size));
  SDL_free(out);
  return result;
}

inline Result<std::vector<std::uint8_t>> Base64Decode(const std::string& text) {
  int size = 0;
  unsigned char* out = SDLStatic_DecodeDataBase64(text.c_str(), &size);
  return internal::WrapBytes(out, size);
}

// Hex-encoded SHA-256 digest.
inline std::string Sha256Hex(std::span<const std::uint8_t> data) {
  Uint8 digest[32];
  SDLStatic_SHA256(data.data(), data.size(), digest);
  static const char kDigits[] = "0123456789abcdef";
  std::string hex(64, '0');
  for (int i = 0; i < 32; ++i) {
    hex[static_cast<std::size_t>(i) * 2] = kDigits[digest[i] >> 4];
    hex[static_cast<std::size_t>(i) * 2 + 1] = kDigits[digest[i] & 15];
  }
  return hex;
}

// --- Godot-style signals with RAII connections ----------------------------

class SignalEmitter;

// Disconnects its signal connection when destroyed (or Release()d).
class ScopedConnection {
 public:
  ScopedConnection() = default;
  ScopedConnection(SDLStatic_SignalEmitter* emitter, Uint64 id) : emitter_(emitter), id_(id) {}
  ~ScopedConnection() { Reset(); }
  ScopedConnection(ScopedConnection&& other) noexcept
      : emitter_(std::exchange(other.emitter_, nullptr)), id_(std::exchange(other.id_, 0)) {}
  ScopedConnection& operator=(ScopedConnection&& other) noexcept {
    if (this != &other) {
      Reset();
      emitter_ = std::exchange(other.emitter_, nullptr);
      id_ = std::exchange(other.id_, 0);
    }
    return *this;
  }
  ScopedConnection(const ScopedConnection&) = delete;
  ScopedConnection& operator=(const ScopedConnection&) = delete;

  bool connected() const { return id_ != 0; }
  void Reset() {
    if (id_ != 0 && emitter_ != nullptr) SDLStatic_DisconnectSignal(emitter_, id_);
    emitter_ = nullptr;
    id_ = 0;
  }

 private:
  SDLStatic_SignalEmitter* emitter_ = nullptr;
  Uint64 id_ = 0;
};

// Owns an emitter; std::function callbacks; connections auto-disconnect.
class SignalEmitter {
 public:
  using Callback = std::function<void(const char* signal, void* args)>;

  static Result<SignalEmitter> Create() {
    SDLStatic_SignalEmitter* raw = SDLStatic_CreateSignalEmitter();
    if (raw == nullptr) return Status::FromSdl();
    return SignalEmitter(raw);
  }

  ~SignalEmitter() { Destroy(); }
  SignalEmitter(SignalEmitter&& other) noexcept
      : emitter_(std::exchange(other.emitter_, nullptr)),
        callbacks_(std::move(other.callbacks_)) {}
  SignalEmitter& operator=(SignalEmitter&& other) noexcept {
    if (this != &other) {
      Destroy();
      emitter_ = std::exchange(other.emitter_, nullptr);
      callbacks_ = std::move(other.callbacks_);
    }
    return *this;
  }
  SignalEmitter(const SignalEmitter&) = delete;
  SignalEmitter& operator=(const SignalEmitter&) = delete;

  Result<ScopedConnection> Connect(const std::string& signal, Callback callback,
                                   Uint32 flags = 0) {
    auto owned = std::make_unique<Callback>(std::move(callback));
    const Uint64 id =
        SDLStatic_ConnectSignal(emitter_, signal.c_str(), &SignalEmitter::Trampoline,
                                owned.get(), flags);
    if (id == 0) return Status::FromSdl();
    callbacks_.push_back(std::move(owned));
    return ScopedConnection(emitter_, id);
  }

  // Number of callbacks invoked, or an error.
  Result<int> Emit(const std::string& signal, void* args = nullptr) {
    const int invoked = SDLStatic_EmitSignal(emitter_, signal.c_str(), args);
    if (invoked < 0) return Status::FromSdl();
    return invoked;
  }

  int ConnectionCount(const char* signal = nullptr) const {
    return SDLStatic_CountSignalConnections(emitter_, signal);
  }

  SDLStatic_SignalEmitter* get() const { return emitter_; }

 private:
  explicit SignalEmitter(SDLStatic_SignalEmitter* emitter) : emitter_(emitter) {}
  static void Trampoline(void* userdata, const char* signal, void* args) {
    (*static_cast<Callback*>(userdata))(signal, args);
  }
  void Destroy() {
    if (emitter_ != nullptr) SDLStatic_DestroySignalEmitter(emitter_);
    emitter_ = nullptr;
  }

  SDLStatic_SignalEmitter* emitter_ = nullptr;
  std::vector<std::unique_ptr<Callback>> callbacks_;
};

}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_EXTRAS_H_
