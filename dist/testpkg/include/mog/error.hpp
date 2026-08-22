/**
 * @file error.hpp
 * @brief Error codes and Result<T> for fallible HTTP operations.
 */
#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <utility>

namespace mog
{

/**
 * @brief Stable error categories returned by the library.
 */
enum class ErrorCode
{
    Ok = 0,
    InvalidUrl,
    InvalidArgument,
    UnsupportedScheme,
    UnsupportedBackend,
    DnsFailed,
    ConnectFailed,
    TlsFailed,
    Timeout,
    IoError,
    ProtocolError,
    TooManyRedirects,
    HttpStatus,
    ResponseTooLarge,
    ProxyError,
    FileError,
    JsonError,
    CompressionError,
    /// Failed to load a shared library or resolve a symbol (dlopen/LoadLibrary).
    DynamicLibraryError,
    Internal,
};

/**
 * @brief Human-readable error with a stable code.
 */
class Error
{
  public:
    Error() = default;
    Error(ErrorCode code, std::string message);

    [[nodiscard]] ErrorCode code() const noexcept
    {
        return code_;
    }
    [[nodiscard]] std::string_view message() const noexcept
    {
        return message_;
    }
    [[nodiscard]] std::string to_string() const;

  private:
    ErrorCode code_{ErrorCode::Internal};
    std::string message_;
};

/**
 * @return Short name for @p code (for logging and CLI).
 */
[[nodiscard]] std::string_view ToString(ErrorCode code) noexcept;

/**
 * @brief Either a value of type T or an Error (C++20-friendly expected-like).
 * @tparam T Success value type.
 *
 * Contextual conversion to bool is true on success.
 */
template <typename T> class Result
{
  public:
    static Result Ok(T value)
    {
        Result r;
        r.value_ = std::move(value);
        return r;
    }

    static Result Err(Error error)
    {
        Result r;
        r.error_ = std::move(error);
        return r;
    }

    [[nodiscard]] explicit operator bool() const noexcept
    {
        return value_.has_value();
    }

    [[nodiscard]] bool has_value() const noexcept
    {
        return value_.has_value();
    }

    [[nodiscard]] T &value() &
    {
        return *value_;
    }
    [[nodiscard]] const T &value() const &
    {
        return *value_;
    }
    [[nodiscard]] T &&value() &&
    {
        return std::move(*value_);
    }

    [[nodiscard]] Error &error() &
    {
        return *error_;
    }
    [[nodiscard]] const Error &error() const &
    {
        return *error_;
    }

    [[nodiscard]] T *operator->()
    {
        return &*value_;
    }
    [[nodiscard]] const T *operator->() const
    {
        return &*value_;
    }

    [[nodiscard]] T &operator*() &
    {
        return *value_;
    }
    [[nodiscard]] const T &operator*() const &
    {
        return *value_;
    }

  private:
    std::optional<T> value_;
    std::optional<Error> error_;
};

/**
 * @brief Result specialization for operations with no success payload.
 */
template <> class Result<void>
{
  public:
    static Result Ok()
    {
        Result r;
        r.ok_ = true;
        return r;
    }

    static Result Err(Error error)
    {
        Result r;
        r.ok_ = false;
        r.error_ = std::move(error);
        return r;
    }

    [[nodiscard]] explicit operator bool() const noexcept
    {
        return ok_;
    }

    [[nodiscard]] bool has_value() const noexcept
    {
        return ok_;
    }

    [[nodiscard]] Error &error() &
    {
        return *error_;
    }
    [[nodiscard]] const Error &error() const &
    {
        return *error_;
    }

  private:
    bool ok_{false};
    std::optional<Error> error_;
};

} // namespace mog
