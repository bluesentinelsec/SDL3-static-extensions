/**
 * @file response.hpp
 * @brief HTTP response value type.
 */
#pragma once

#include "mog/error.hpp"

#include <chrono>
#include <cstddef>
#include <map>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace mog
{

/**
 * @brief Single HTTP header field (name as received from the server).
 */
struct Header
{
    std::string name;
    std::string value;
};

/**
 * @brief Successful HTTP exchange result (status, headers, body).
 */
class Response
{
  public:
    Response() = default;

    int status_code = 0;
    std::string reason;
    /// Final URL after redirects.
    std::string url;
    /// Ordered header list (preserves duplicates such as multiple Set-Cookie).
    std::vector<Header> headers;
    std::string body;
    /// Number of body bytes received: @c body.size() for buffered responses, or
    /// the count streamed to @c Options::response_writer when streaming (in which
    /// case @c body is empty).
    std::size_t downloaded_bytes = 0;
    /// Number of redirects followed to produce this response.
    int history_len = 0;
    /// Redirect chain (each Location target resolved), excluding the original URL.
    std::vector<std::string> history;
    /// Concrete backend that served the request.
    std::string backend;
    /// Wall time spent in the library for this exchange (connect + transfer).
    std::chrono::milliseconds elapsed{0};
    /// Cookies collected from Set-Cookie on this response (name → value).
    std::map<std::string, std::string> cookies;

    [[nodiscard]] bool ok() const noexcept
    {
        return status_code >= 200 && status_code < 400;
    }

    [[nodiscard]] bool is_redirect() const noexcept
    {
        return status_code == 301 || status_code == 302 || status_code == 303 ||
               status_code == 307 || status_code == 308;
    }

    /**
     * @return Response body as text (UTF-8 assumed; no charset conversion).
     */
    [[nodiscard]] const std::string &text() const noexcept
    {
        return body;
    }

    /**
     * @return Response body bytes (alias of @ref body).
     */
    [[nodiscard]] const std::string &content() const noexcept
    {
        return body;
    }

    /**
     * @brief Case-insensitive header lookup (first match).
     * @return Header value or empty string if missing.
     */
    [[nodiscard]] std::string header(std::string_view name) const;

    /**
     * @brief All values for a header name (case-insensitive), e.g. multiple Set-Cookie.
     */
    [[nodiscard]] std::vector<std::string> header_all(std::string_view name) const;

    /**
     * @return Content-Type header value (may include charset parameters).
     */
    [[nodiscard]] std::string content_type() const;

    /**
     * @brief Throw-style check: returns Error when status is 4xx/5xx.
     *
     * Does not throw; returns an error Result for library consistency.
     */
    [[nodiscard]] Result<void> raise_for_status() const;
};

} // namespace mog
