/**
 * @file http.hpp
 * @brief Module-level request helpers (requests-style free functions).
 */
#pragma once

#include "mog/options.hpp"
#include "mog/response.hpp"

#include <string_view>

namespace mog
{

/**
 * @brief Perform an HTTP request with the resolved backend.
 *
 * Free functions are thread-safe: they share no mutable global request state.
 * Backend / TLS library process init is synchronized internally.
 */
[[nodiscard]] Result<Response> request(Method method, std::string_view url,
                                       const Options &options = {});

[[nodiscard]] Result<Response> get(std::string_view url, const Options &options = {});
[[nodiscard]] Result<Response> post(std::string_view url, const Options &options = {});
[[nodiscard]] Result<Response> put(std::string_view url, const Options &options = {});
[[nodiscard]] Result<Response> patch(std::string_view url, const Options &options = {});
[[nodiscard]] Result<Response> del(std::string_view url, const Options &options = {});
[[nodiscard]] Result<Response> head(std::string_view url, const Options &options = {});
[[nodiscard]] Result<Response> options(std::string_view url, const Options &options = {});

} // namespace mog
