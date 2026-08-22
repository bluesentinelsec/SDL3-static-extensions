/**
 * @file options.hpp
 * @brief Per-request options (requests-style kwargs) for web client workloads.
 */
#pragma once

#include "mog/backend.hpp"
#include "mog/error.hpp"

#include <chrono>
#include <cstddef>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace mog
{

/**
 * @brief HTTP methods supported by the client.
 */
enum class Method
{
    Get,
    Post,
    Put,
    Patch,
    Delete,
    Head,
    Options,
};

/**
 * @return Wire token for @p method (e.g. "GET").
 */
[[nodiscard]] std::string_view ToString(Method method) noexcept;

/**
 * @brief Parse method name (case-insensitive).
 */
[[nodiscard]] std::optional<Method> ParseMethod(std::string_view text);

/**
 * @brief HTTP authentication to attach to a request.
 *
 * Prefer the helpers @ref WithBasicAuth and @ref WithBearerToken.
 */
struct Auth
{
    enum class Kind
    {
        None,
        Basic,
        Bearer,
        Digest, ///< HTTP Digest (challenge-response; sent after a 401).
    };

    Kind kind = Kind::None;
    std::string username; ///< Basic / Digest auth user.
    std::string password; ///< Basic / Digest auth password.
    std::string token;    ///< Bearer token (without the "Bearer " prefix).
};

/**
 * @brief One part of a multipart/form-data body: a text field or a file part.
 *
 * A part is a file part when @ref filename is set (its @ref value holds the file
 * bytes); otherwise it is a plain text field (@ref value holds the text).
 */
struct FormPart
{
    std::string name;                    ///< Field name (Content-Disposition name=).
    std::string value;                   ///< Text value, or file bytes when @ref filename is set.
    std::optional<std::string> filename; ///< Set => file part (adds filename= and a Content-Type).
    std::string content_type; ///< Optional part Content-Type; a default is applied when empty.
};

/**
 * @brief Streaming response-body sink (see @ref Options::response_writer).
 *
 * Invoked with response body bytes as they arrive, in receive order and after
 * transfer-decoding (de-chunked). Return an @ref Error to abort the transfer
 * (the request fails with that error). The writer is never called for bodyless
 * responses (HEAD / 204 / 304) nor for intermediate redirect responses — only
 * the final response body is streamed.
 */
using BodyWriter = std::function<Result<void>(std::string_view data)>;

/**
 * @brief Per-request configuration (similar to kwargs in Python requests).
 *
 * Only fields you set affect the request; Session defaults fill the rest when
 * using @ref Session.
 */
struct Options
{
    /// Extra headers (merged over session defaults; these win on conflict).
    std::map<std::string, std::string> headers;

    /// Raw request body. Ignored when @ref json or @ref form is set (those win).
    std::string body;

    /// If set, sent as the body with Content-Type: application/json (unless overridden).
    std::optional<std::string> json;

    /// If non-empty, encoded as application/x-www-form-urlencoded body (unless overridden).
    std::map<std::string, std::string> form;

    /**
     * @brief multipart/form-data parts (text fields and/or file uploads).
     *
     * When non-empty this takes precedence over @ref json, @ref form, and
     * @ref body, and sets @c Content-Type: multipart/form-data with a generated
     * boundary (unless the caller set Content-Type). Build parts with
     * @ref AddFormField / @ref AddFormFile / @ref AddFormFileFromPath.
     */
    std::vector<FormPart> multipart;

    /// Query parameters appended to the URL.
    std::map<std::string, std::string> params;

    /// Cookies sent on this request (name → value). Merged with Session jar when using Session.
    std::map<std::string, std::string> cookies;

    /// Overall I/O deadline for connect (if connect_timeout unset) and for each read/write.
    std::chrono::milliseconds timeout{std::chrono::seconds(30)};

    /// Optional connect-only deadline; defaults to @ref timeout when unset.
    std::optional<std::chrono::milliseconds> connect_timeout;

    /// Verify TLS certificates (HTTPS). Set false only for debugging.
    bool verify_tls = true;

    /**
     * @brief Client certificate (PEM file path) for mutual TLS (mTLS). Optional.
     *
     * When set, it is presented to the server during the TLS handshake. The
     * private key comes from @ref client_key (or this same file if that is unset).
     */
    std::optional<std::string> client_cert;

    /// Client private-key PEM file path for mTLS. Defaults to @ref client_cert when unset.
    std::optional<std::string> client_key;

    /// Passphrase for an encrypted @ref client_key (empty = unencrypted).
    std::string client_key_password;

    /**
     * @brief Optional path to a PEM CA bundle (highest precedence for TLS trust).
     *
     * When set (CLI @c --cacert), only this file is used. When unset, discovery is:
     * environment (@c MOG_CA_BUNDLE / @c SSL_CERT_FILE / …) → system trust store →
     * embedded Mozilla roots → clear error. See README “TLS trust”.
     */
    std::optional<std::string> ca_bundle;

    /**
     * @brief Follow 3xx responses with a Location header (default: true).
     *
     * Redirect following is enabled by default for both free functions and
     * @ref Session (typical client behavior). Disable with @c false or CLI
     * @c --no-location when the 3xx response itself is required.
     */
    bool allow_redirects = true;

    /// Maximum redirects when @ref allow_redirects is true.
    int max_redirects = 5;

    /**
     * @brief Prefer HTTP/1.1 keep-alive (`Connection: keep-alive` when unset).
     *
     * Default @c true. Free functions still open one connection per request
     * (no pool). @ref Session attaches an internal pool so successive requests
     * to the same origin can reuse TCP/TLS. Set @c false (or send
     * @c Connection: close) to force a new connection each time.
     */
    bool keep_alive = true;

    /**
     * @brief Opaque keep-alive pool handle (set by @ref Session; not for app code).
     *
     * When null, @ref keep_alive only affects the request Connection header.
     */
    std::shared_ptr<void> connection_pool;

    /// Backend override (CLI / Options). Env @c MOG_BACKEND is consulted if unset.
    std::optional<Backend> backend;

    /// User-Agent header when the caller does not set one.
    std::string user_agent;

    /// HTTP authentication (Basic or Bearer).
    Auth auth{};

    /**
     * @brief HTTP proxy URL, e.g. "http://127.0.0.1:8080".
     *
     * Used for both http and https targets (HTTPS uses CONNECT).
     * Empty / unset means direct connection.
     */
    std::optional<std::string> proxy;

    /// Hard cap on response body size (bytes). 0 = unlimited.
    /// When @ref decompress is true, the limit applies to the **decoded** body size.
    std::size_t max_response_bytes = 64ULL * 1024ULL * 1024ULL;

    /// When true, Session updates its cookie jar from Set-Cookie (library default true on Session).
    bool update_cookies = true;

    /**
     * @brief When true, advertise gzip/deflate and decode Content-Encoding on responses.
     *
     * Adds @c Accept-Encoding: gzip, deflate unless the caller already set that header.
     * Decoded body is exposed in @c Response::body; Content-Encoding / Content-Length
     * are adjusted accordingly. Unknown encodings fail with @c CompressionError.
     *
     * Ignored when @ref response_writer is set (streaming delivers raw bytes).
     */
    bool decompress = true;

    /**
     * @brief Optional streaming sink for the response body (see @ref BodyWriter).
     *
     * When set, the final response body is delivered incrementally to this
     * writer instead of being buffered — @ref Response::body stays empty and
     * @ref Response::downloaded_bytes reports how many bytes were streamed. Use
     * this for large downloads to keep memory flat regardless of body size.
     *
     * Streaming delivers the exact wire bytes: mog does not advertise
     * @c Accept-Encoding and does not decode @c Content-Encoding while a writer
     * is attached, so @ref decompress has no effect. @ref max_response_bytes is
     * still enforced (0 = unlimited). Build a file sink with @ref FileWriter.
     */
    BodyWriter response_writer;
};

/**
 * @brief Build a @ref BodyWriter that streams the response body to a file.
 *
 * The file at @p path is created/truncated when this function is called; a
 * @c FileError is returned if it cannot be opened. The returned writer owns the
 * open file (flushed and closed when the writer is destroyed). Assign it to
 * @ref Options::response_writer and keep the Options alive for the request.
 */
[[nodiscard]] Result<BodyWriter> FileWriter(const std::string &path);

// ---------------------------------------------------------------------------
// Fluent helpers (mutate and return reference for chaining)
// ---------------------------------------------------------------------------

inline Options &WithHeader(Options &opt, std::string name, std::string value)
{
    opt.headers[std::move(name)] = std::move(value);
    return opt;
}

inline Options &WithBasicAuth(Options &opt, std::string username, std::string password)
{
    opt.auth.kind = Auth::Kind::Basic;
    opt.auth.username = std::move(username);
    opt.auth.password = std::move(password);
    opt.auth.token.clear();
    return opt;
}

inline Options &WithBearerToken(Options &opt, std::string token)
{
    opt.auth.kind = Auth::Kind::Bearer;
    opt.auth.token = std::move(token);
    opt.auth.username.clear();
    opt.auth.password.clear();
    return opt;
}

/**
 * @brief Use HTTP Digest auth (credentials sent in response to a 401 challenge).
 */
inline Options &WithDigestAuth(Options &opt, std::string username, std::string password)
{
    opt.auth.kind = Auth::Kind::Digest;
    opt.auth.username = std::move(username);
    opt.auth.password = std::move(password);
    opt.auth.token.clear();
    return opt;
}

/**
 * @brief Present a client certificate for mutual TLS.
 * @param key_path Private-key PEM; defaults to @p cert_path when empty.
 */
inline Options &WithClientCert(Options &opt, std::string cert_path, std::string key_path = {},
                               std::string key_password = {})
{
    opt.client_cert = std::move(cert_path);
    if (!key_path.empty())
    {
        opt.client_key = std::move(key_path);
    }
    opt.client_key_password = std::move(key_password);
    return opt;
}

/**
 * @brief Set raw JSON text as the body (Content-Type applied at send time).
 *
 * When MOG_WITH_JSON is enabled, @c WithJson also accepts @c nlohmann::json
 * (see mog/json.hpp). String / string_view / C-string overloads are provided so
 * string literals are not ambiguous with nlohmann's converting constructors.
 */
inline Options &WithJson(Options &opt, std::string json_body)
{
    opt.json = std::move(json_body);
    return opt;
}

inline Options &WithJson(Options &opt, std::string_view json_body)
{
    opt.json = std::string{json_body};
    return opt;
}

inline Options &WithJson(Options &opt, const char *json_body)
{
    opt.json = json_body != nullptr ? std::string{json_body} : std::string{};
    return opt;
}

inline Options &WithForm(Options &opt, std::map<std::string, std::string> fields)
{
    opt.form = std::move(fields);
    return opt;
}

/**
 * @brief Append a multipart text field (see @ref Options::multipart).
 */
inline Options &AddFormField(Options &opt, std::string name, std::string value)
{
    opt.multipart.push_back(FormPart{std::move(name), std::move(value), std::nullopt, {}});
    return opt;
}

/**
 * @brief Append a multipart file part from in-memory bytes.
 * @param content_type Optional; when empty a type is guessed from @p filename.
 */
inline Options &AddFormFile(Options &opt, std::string name, std::string filename, std::string data,
                            std::string content_type = {})
{
    opt.multipart.push_back(FormPart{std::move(name), std::move(data),
                                     std::optional<std::string>{std::move(filename)},
                                     std::move(content_type)});
    return opt;
}

/**
 * @brief Append a multipart file part read from disk.
 *
 * The file at @p path is read fully into memory; @c filename defaults to the
 * path's basename. Returns @c FileError if the file cannot be read.
 */
[[nodiscard]] Result<void> AddFormFileFromPath(Options &opt, std::string name,
                                               const std::string &path,
                                               std::string content_type = {});

inline Options &WithProxy(Options &opt, std::string proxy_url)
{
    opt.proxy = std::move(proxy_url);
    return opt;
}

inline Options &WithTimeout(Options &opt, std::chrono::milliseconds timeout)
{
    opt.timeout = timeout;
    return opt;
}

/**
 * @brief Build Options for a JSON POST/PUT body in one shot (raw text).
 */
[[nodiscard]] inline Options JsonOptions(std::string json_body)
{
    Options opt;
    opt.json = std::move(json_body);
    return opt;
}

[[nodiscard]] inline Options JsonOptions(std::string_view json_body)
{
    Options opt;
    opt.json = std::string{json_body};
    return opt;
}

[[nodiscard]] inline Options JsonOptions(const char *json_body)
{
    Options opt;
    opt.json = json_body != nullptr ? std::string{json_body} : std::string{};
    return opt;
}

/**
 * @brief Build Options for form-urlencoded body.
 */
[[nodiscard]] inline Options FormOptions(std::map<std::string, std::string> fields)
{
    Options opt;
    opt.form = std::move(fields);
    return opt;
}

} // namespace mog
