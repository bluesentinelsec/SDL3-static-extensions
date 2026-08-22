/**
 * @file backend.hpp
 * @brief HTTP transport backend selection.
 */
#pragma once

#include <optional>
#include <string>
#include <string_view>

namespace mog
{

/**
 * @brief Available HTTP transport backends.
 *
 * @c Auto resolves using an environment override (if any), then the platform
 * default. Android uses the embedded stack, browser WebAssembly uses Fetch,
 * and desktop/iOS platforms prefer their native transport with embedded fallback.
 */
enum class Backend
{
    Auto = 0,
    Embedded, ///< Built-in HTTP/1.1 + mbedTLS (Android default and native fallback).
    Curl,     ///< Runtime libcurl via dlopen on supported desktop platforms.
    WinHttp,  ///< Windows WinHTTP.
    Native,   ///< Apple NSURLSession (macOS and iOS).
    Web,      ///< Browser Fetch API (Emscripten only).
};

/**
 * @brief Parse a backend name (case-insensitive).
 * @param text One of: auto, embedded, curl, winhttp, native, web.
 * @return Backend or nullopt if unknown.
 */
[[nodiscard]] std::optional<Backend> ParseBackend(std::string_view text);

/**
 * @return Canonical lowercase name for @p backend.
 */
[[nodiscard]] std::string_view ToString(Backend backend) noexcept;

/**
 * @brief Resolve which backend will handle a request.
 *
 * Precedence (highest first):
 * 1. @p explicit_override when set (library Options or CLI --backend)
 * 2. Environment variable @c MOG_BACKEND
 * 3. @c Backend::Auto → platform-native transport, browser Fetch, or embedded.
 *
 * @param explicit_override Optional caller override.
 * @return Concrete backend (never @c Auto).
 */
[[nodiscard]] Backend ResolveBackend(std::optional<Backend> explicit_override = std::nullopt);

/**
 * @brief Read @c MOG_BACKEND from the environment if set and valid.
 */
[[nodiscard]] std::optional<Backend> BackendFromEnvironment();

} // namespace mog
