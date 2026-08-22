/**
 * @file session.hpp
 * @brief Thread-safe Session with shared defaults and cookie jar.
 */
#pragma once

#include "mog/http.hpp"
#include "mog/options.hpp"
#include "mog/response.hpp"

#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <string_view>

namespace mog
{

namespace detail
{
class CookieJar; // domain/path-aware storage (defined in src/http/detail)
}

/**
 * @brief Reusable client with default headers/options, cookie jar, and keep-alive.
 *
 * All public methods are safe to call concurrently from multiple threads.
 * Each request snapshots session state under a mutex; the embedded transport
 * may reuse an idle connection from this session's pool (thread-safe).
 *
 * Defaults: @c allow_redirects=true, @c keep_alive=true (Connection: keep-alive
 * and origin pooling). Disable redirects with @c Options::allow_redirects=false
 * or CLI @c --no-location; disable pooling with @c Options::keep_alive=false.
 *
 * The cookie jar stores Set-Cookie responses and replays them on later requests,
 * scoped by domain, path, and the Secure flag (simplified RFC 6265; see
 * README "Session cookie jar" for the intentional non-goals).
 */
class Session
{
  public:
    Session();
    explicit Session(Options defaults);
    ~Session(); // out-of-line: cookie_jar_ is an incomplete type here

    Session(const Session &) = delete;
    Session &operator=(const Session &) = delete;
    Session(Session &&) = delete;
    Session &operator=(Session &&) = delete;

    /**
     * @brief Replace default options (headers, timeout, backend, auth, …).
     * Does not clear the cookie jar.
     */
    void set_defaults(Options defaults);

    /**
     * @return Copy of current default options.
     */
    [[nodiscard]] Options defaults() const;

    /**
     * @brief Set or replace a default header.
     */
    void set_header(std::string name, std::string value);

    /**
     * @brief Set Basic auth on session defaults.
     */
    void set_basic_auth(std::string username, std::string password);

    /**
     * @brief Set Bearer token on session defaults.
     */
    void set_bearer_token(std::string token);

    /**
     * @brief Optional base URL prepended to relative request paths.
     */
    void set_base_url(std::string base_url);

    [[nodiscard]] std::string base_url() const;

    /**
     * @brief Replace the entire cookie jar.
     */
    void set_cookies(std::map<std::string, std::string> cookies);

    /**
     * @brief Set one cookie in the jar.
     */
    void set_cookie(std::string name, std::string value);

    /**
     * @return Copy of the cookie jar.
     */
    [[nodiscard]] std::map<std::string, std::string> cookies() const;

    /**
     * @brief Clear all cookies.
     */
    void clear_cookies();

    [[nodiscard]] Result<Response> request(Method method, std::string_view url,
                                           const Options &options = {});

    [[nodiscard]] Result<Response> get(std::string_view url, const Options &options = {});
    [[nodiscard]] Result<Response> post(std::string_view url, const Options &options = {});
    [[nodiscard]] Result<Response> put(std::string_view url, const Options &options = {});
    [[nodiscard]] Result<Response> patch(std::string_view url, const Options &options = {});
    [[nodiscard]] Result<Response> del(std::string_view url, const Options &options = {});
    [[nodiscard]] Result<Response> head(std::string_view url, const Options &options = {});
    [[nodiscard]] Result<Response> options(std::string_view url, const Options &options = {});

  private:
    [[nodiscard]] Options merge_options(const Options &per_request) const;
    [[nodiscard]] std::string resolve_url(std::string_view url) const;

    mutable std::mutex mutex_;
    Options defaults_;
    std::string base_url_;
    std::unique_ptr<detail::CookieJar> cookie_jar_;
    /// Shared with Options::connection_pool on each request when keep_alive is on.
    std::shared_ptr<void> connection_pool_;
};

} // namespace mog
