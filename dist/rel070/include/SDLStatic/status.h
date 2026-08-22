// status.h — exception-free error handling for the sdlstatic C++ bindings.
//
// Original SDLStatic code (zlib). Google-style Status/Result<T> without
// Abseil (decided: no dependencies beyond standard C++): every fallible
// factory returns Result<T>, every fallible operation returns Status, both
// [[nodiscard]]. Control flow stays traceable — plain if/early-return, no
// unwinding. The bindings library compiles with -fno-exceptions.

#ifndef SDLSTATIC_CPP_STATUS_H_
#define SDLSTATIC_CPP_STATUS_H_

#include <SDL3/SDL.h>

#include <optional>
#include <string>
#include <utility>

namespace sdlstatic {

class [[nodiscard]] Status {
 public:
  // Success.
  Status() = default;

  static Status Ok() { return Status(); }
  static Status Error(std::string message) { return Status(std::move(message)); }
  // Captures the thread's current SDL error text.
  static Status FromSdl() { return Status(std::string(SDL_GetError())); }

  bool ok() const { return !message_.has_value(); }
  // Empty string when ok().
  const std::string& message() const {
    static const std::string kEmpty;
    return message_.has_value() ? *message_ : kEmpty;
  }

 private:
  explicit Status(std::string message) : message_(std::move(message)) {}
  std::optional<std::string> message_;
};

// Result<T>: either a value or the Status explaining its absence.
// Accessing value()/operator-> on an error is a programming bug; it trips
// SDL_assert in debug builds (never throws).
template <typename T>
class [[nodiscard]] Result {
 public:
  Result(T value) : value_(std::move(value)) {}          // NOLINT(runtime/explicit)
  Result(Status status) : status_(std::move(status)) {}  // NOLINT(runtime/explicit)

  bool ok() const { return value_.has_value(); }
  const Status& status() const { return status_; }

  T& value() & {
    SDL_assert(ok());
    return *value_;
  }
  const T& value() const& {
    SDL_assert(ok());
    return *value_;
  }
  // Move the value out: `T owned = std::move(result).value();`
  T value() && {
    SDL_assert(ok());
    return *std::move(value_);
  }

  T&& operator*() && { return std::move(value()); }

  T* operator->() { return &value(); }
  const T* operator->() const { return &value(); }
  T& operator*() & { return value(); }
  const T& operator*() const& { return value(); }

 private:
  std::optional<T> value_;
  Status status_;
};

}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_STATUS_H_
