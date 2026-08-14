// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: SDL_net
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_NET_H_
#define SDLSTATIC_CPP_GEN_NET_H_

#include <SDL3_net/SDL_net.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace net {

// RAII owner for NET_StreamSocket (destroyed with NET_DestroyStreamSocket).
class StreamSocket {
 public:
  static Result<StreamSocket> CreateClient(NET_Address *address, Uint16 port, SDL_PropertiesID props) {
    NET_StreamSocket* created_ = ::NET_CreateClient(address, port, props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return StreamSocket(created_);
  }

  StreamSocket() = default;
  ~StreamSocket() { reset(); }
  StreamSocket(StreamSocket&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  StreamSocket& operator=(StreamSocket&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  StreamSocket(const StreamSocket&) = delete;
  StreamSocket& operator=(const StreamSocket&) = delete;

  NET_StreamSocket* get() const { return value_; }
  NET_StreamSocket* release() {
    NET_StreamSocket* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::NET_DestroyStreamSocket(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  NET_Status WaitUntilConnected(Sint32 timeout) {
    return ::NET_WaitUntilConnected(value_, timeout);
  }
  NET_Address* GetStreamSocketAddress() {
    return ::NET_GetStreamSocketAddress(value_);
  }
  NET_Status GetConnectionStatus() {
    return ::NET_GetConnectionStatus(value_);
  }
  Status WriteToStreamSocket(const void *buf, int buflen) {
    return ::NET_WriteToStreamSocket(value_, buf, buflen) ? Status() : Status::FromSdl();
  }
  int GetStreamSocketPendingWrites() {
    return ::NET_GetStreamSocketPendingWrites(value_);
  }
  int WaitUntilStreamSocketDrained(Sint32 timeout) {
    return ::NET_WaitUntilStreamSocketDrained(value_, timeout);
  }
  int ReadFromStreamSocket(void *buf, int buflen) {
    return ::NET_ReadFromStreamSocket(value_, buf, buflen);
  }
  void SimulateStreamPacketLoss(int percent_loss) { ::NET_SimulateStreamPacketLoss(value_, percent_loss); }
 private:
  explicit StreamSocket(NET_StreamSocket* value) : value_(value), engaged_(true) {}
  NET_StreamSocket* value_{};
  bool engaged_ = false;
};

// RAII owner for NET_Server (destroyed with NET_DestroyServer).
class Server {
 public:
  static Result<Server> CreateServer(NET_Address *addr, Uint16 port, SDL_PropertiesID props) {
    NET_Server* created_ = ::NET_CreateServer(addr, port, props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Server(created_);
  }

  Server() = default;
  ~Server() { reset(); }
  Server(Server&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Server& operator=(Server&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Server(const Server&) = delete;
  Server& operator=(const Server&) = delete;

  NET_Server* get() const { return value_; }
  NET_Server* release() {
    NET_Server* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::NET_DestroyServer(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status AcceptClient(NET_StreamSocket **client_stream) {
    return ::NET_AcceptClient(value_, client_stream) ? Status() : Status::FromSdl();
  }
 private:
  explicit Server(NET_Server* value) : value_(value), engaged_(true) {}
  NET_Server* value_{};
  bool engaged_ = false;
};

// RAII owner for NET_DatagramSocket (destroyed with NET_DestroyDatagramSocket).
class DatagramSocket {
 public:
  static Result<DatagramSocket> CreateDatagramSocket(NET_Address *addr, Uint16 port, SDL_PropertiesID props) {
    NET_DatagramSocket* created_ = ::NET_CreateDatagramSocket(addr, port, props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return DatagramSocket(created_);
  }

  DatagramSocket() = default;
  ~DatagramSocket() { reset(); }
  DatagramSocket(DatagramSocket&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  DatagramSocket& operator=(DatagramSocket&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  DatagramSocket(const DatagramSocket&) = delete;
  DatagramSocket& operator=(const DatagramSocket&) = delete;

  NET_DatagramSocket* get() const { return value_; }
  NET_DatagramSocket* release() {
    NET_DatagramSocket* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::NET_DestroyDatagramSocket(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status SendDatagram(NET_Address *address, Uint16 port, const void *buf, int buflen) {
    return ::NET_SendDatagram(value_, address, port, buf, buflen) ? Status() : Status::FromSdl();
  }
  Status ReceiveDatagram(NET_Datagram **dgram) {
    return ::NET_ReceiveDatagram(value_, dgram) ? Status() : Status::FromSdl();
  }
  void SimulateDatagramPacketLoss(int percent_loss) { ::NET_SimulateDatagramPacketLoss(value_, percent_loss); }
 private:
  explicit DatagramSocket(NET_DatagramSocket* value) : value_(value), engaged_(true) {}
  NET_DatagramSocket* value_{};
  bool engaged_ = false;
};

// bool-returning C functions surfaced as Status.
inline Status Init() {
  return ::NET_Init() ? Status() : Status::FromSdl();
}

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& CompareAddresses = ::NET_CompareAddresses;
inline constexpr auto& DestroyDatagram = ::NET_DestroyDatagram;
inline constexpr auto& FreeLocalAddresses = ::NET_FreeLocalAddresses;
inline constexpr auto& GetAddressBytes = ::NET_GetAddressBytes;
inline constexpr auto& GetAddressStatus = ::NET_GetAddressStatus;
inline constexpr auto& GetAddressString = ::NET_GetAddressString;
inline constexpr auto& GetLocalAddresses = ::NET_GetLocalAddresses;
inline constexpr auto& Quit = ::NET_Quit;
inline constexpr auto& RefAddress = ::NET_RefAddress;
inline constexpr auto& ResolveHostname = ::NET_ResolveHostname;
inline constexpr auto& SimulateAddressResolutionLoss = ::NET_SimulateAddressResolutionLoss;
inline constexpr auto& UnrefAddress = ::NET_UnrefAddress;
inline constexpr auto& Version = ::NET_Version;
inline constexpr auto& WaitUntilInputAvailable = ::NET_WaitUntilInputAvailable;
inline constexpr auto& WaitUntilResolved = ::NET_WaitUntilResolved;

}  // namespace net
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_NET_H_
// clang-format on
