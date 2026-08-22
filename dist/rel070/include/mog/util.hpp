/**
 * @file util.hpp
 * @brief Small public helpers (encoding, file body load).
 */
#pragma once

#include "mog/error.hpp"

#include <map>
#include <string>
#include <string_view>

namespace mog
{

/**
 * @brief Percent-encode a string for application/x-www-form-urlencoded or query.
 */
[[nodiscard]] std::string UrlEncode(std::string_view text);

/**
 * @brief Encode a map as application/x-www-form-urlencoded (key=value&...).
 */
[[nodiscard]] std::string EncodeForm(const std::map<std::string, std::string> &fields);

/**
 * @brief Encode name/value cookies as a Cookie request header value.
 */
[[nodiscard]] std::string EncodeCookieHeader(const std::map<std::string, std::string> &cookies);

/**
 * @brief Parse a single Set-Cookie header value into name/value (ignores attributes).
 * @return false if the header is not a valid name=value pair.
 */
[[nodiscard]] bool ParseSetCookie(std::string_view set_cookie, std::string &name,
                                  std::string &value);

/**
 * @brief Base64-encode binary data (RFC 4648).
 */
[[nodiscard]] std::string Base64Encode(std::string_view data);

/**
 * @brief Read an entire file into a string (binary-safe).
 */
[[nodiscard]] Result<std::string> ReadFile(std::string_view path);

} // namespace mog
