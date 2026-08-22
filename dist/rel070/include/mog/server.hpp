/**
 * @file server.hpp
 * @brief Embedded, thread-safe HTTP server (requests-style handlers).
 *
 * A small, dependency-free HTTP/1.1 server that mirrors the client's design: no
 * exceptions (@ref Result), value-style request/response types, and a bounded
 * thread pool for concurrency. Register route handlers and/or serve a directory
 * of static files, then @ref Server::start (non-blocking) and @ref Server::stop.
 *
 * Thread-safety: the server framework is thread-safe. Routes and static mounts
 * are frozen when @ref Server::start is called, so request dispatch needs no
 * locking. Handlers run on worker threads, so a handler that touches shared
 * state must synchronize that state itself.
 *
 * TLS (HTTPS) is added in a follow-up slice via ServerOptions.
 */
#pragma once

#include "mog/error.hpp"
#include "mog/options.hpp"  // mog::Method
#include "mog/response.hpp" // mog::Header

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace mog
{

/**
 * @brief A parsed inbound HTTP request handed to a handler.
 */
struct ServerRequest
{
    /// Parsed method; @ref Method::Get for an unrecognized verb (see @ref method_text).
    Method method = Method::Get;
    /// Raw method token as received (e.g. "PROPFIND" for verbs outside @ref Method).
    std::string method_text;
    /// Decoded request path, without the query string (e.g. "/a/b").
    std::string path;
    /// Raw request target as received (path plus any "?query").
    std::string target;
    /// Decoded query-string parameters.
    std::map<std::string, std::string> params;
    /// Request headers in received order (duplicates preserved).
    std::vector<Header> headers;
    /// Request body (already de-chunked; empty for bodyless requests).
    std::string body;
    /// Remote peer address (e.g. "127.0.0.1").
    std::string client_address;

    /**
     * @brief Case-insensitive header lookup (first match).
     * @return Header value, or empty string when absent.
     */
    [[nodiscard]] std::string header(std::string_view name) const;
};

/**
 * @brief Streaming body sink passed to a @ref ServerResponse::body_producer.
 *
 * Call it with successive chunks of body bytes. Returns an @ref Error to abort
 * the transfer (for example when the client disconnects mid-stream).
 */
using ResponseSink = std::function<Result<void>(std::string_view)>;

/**
 * @brief An outbound HTTP response produced by a handler.
 *
 * Provide either a buffered @ref body or a @ref body_producer for large or
 * file-backed responses that should stream with constant memory. When a
 * producer is set, @ref body is ignored.
 */
class ServerResponse
{
  public:
    int status_code = 200;
    /// Reason phrase; a standard phrase is used when empty.
    std::string reason;
    std::vector<Header> headers;
    std::string body;

    /**
     * @brief Optional streaming producer. When set, it is invoked with a sink to
     *        emit the body incrementally instead of buffering @ref body.
     *
     * Set @c Content-Length via @ref set_header when the size is known;
     * otherwise the response is sent with chunked transfer-encoding.
     */
    std::function<Result<void>(const ResponseSink &)> body_producer;

    /// Set or replace a header (case-insensitive name match on replace).
    ServerResponse &set_header(std::string name, std::string value);
    /// Case-insensitive header lookup (first match), or empty string.
    [[nodiscard]] std::string header(std::string_view name) const;

    // --- Factories -------------------------------------------------------

    /// Text/plain (or a custom content type) response.
    [[nodiscard]] static ServerResponse Text(
        int status, std::string body, std::string content_type = "text/plain; charset=utf-8");
    /// application/json response from raw JSON text.
    [[nodiscard]] static ServerResponse Json(int status, std::string json);
    /// Bare status response with no body (Content-Length: 0).
    [[nodiscard]] static ServerResponse Status(int status);
    /// 404 response with an optional body.
    [[nodiscard]] static ServerResponse NotFound(std::string body = "Not Found");
    /// Redirect (301/302/303/307/308) to @p location.
    [[nodiscard]] static ServerResponse Redirect(int status, std::string location);
    /**
     * @brief Stream a file from disk with a content type guessed from @p path.
     * @return FileError if the file cannot be opened.
     */
    [[nodiscard]] static Result<ServerResponse> File(const std::string &path);
};

/// Handler signature: map a request to a response. Runs on a worker thread.
using Handler = std::function<ServerResponse(const ServerRequest &)>;

/**
 * @brief Options for serving a directory of static files (see @ref Server::serve_files).
 */
struct StaticOptions
{
    /// Serve directory listings for directories without an index file.
    bool directory_listing = true;
    /// Index file served for a directory request (empty to disable).
    std::string index_file = "index.html";
};

/**
 * @brief TLS (HTTPS) configuration for the server.
 *
 * Empty by default (plain HTTP). Build one with @ref FromFiles for a real
 * certificate, or @ref SelfSigned for an ephemeral development certificate.
 */
struct TlsServerConfig
{
    bool enabled = false;
    std::string cert_pem;     ///< Certificate chain, PEM.
    std::string key_pem;      ///< Private key, PEM.
    std::string key_password; ///< Passphrase for an encrypted key (empty = none).

    /// Load a certificate chain and private key from PEM files.
    [[nodiscard]] static Result<TlsServerConfig> FromFiles(const std::string &cert_path,
                                                           const std::string &key_path,
                                                           const std::string &key_password = {});

    /**
     * @brief Generate an ephemeral self-signed certificate (EC P-256).
     *
     * Suitable for local development and testing. Clients must skip verification
     * (mog's client: @c verify_tls=false) since nothing else trusts it.
     */
    [[nodiscard]] static Result<TlsServerConfig> SelfSigned(
        const std::string &common_name = "localhost");
};

/**
 * @brief Server configuration.
 */
struct ServerOptions
{
    /// Interface to bind. "127.0.0.1" (default) is loopback; "0.0.0.0" is all IPv4.
    std::string bind_address = "127.0.0.1";
    /// TCP port. 0 selects an ephemeral port (read it back with @ref Server::port).
    std::uint16_t port = 8000;
    /// Worker threads. 0 uses the hardware concurrency (at least 1).
    unsigned threads = 0;
    /// listen() backlog.
    int backlog = 128;

    /// Deadline for reading a complete request (headers + body) once it starts.
    std::chrono::milliseconds read_timeout{std::chrono::seconds(30)};
    /// Deadline for writing a response.
    std::chrono::milliseconds write_timeout{std::chrono::seconds(30)};
    /// How long an idle keep-alive connection waits for the next request.
    std::chrono::milliseconds keep_alive_timeout{std::chrono::seconds(5)};

    /// Reject a request whose header block exceeds this many bytes (431).
    std::size_t max_header_bytes = 64ULL * 1024ULL;
    /// Reject a request body larger than this many bytes (413). 0 = unlimited.
    std::size_t max_body_bytes = 16ULL * 1024ULL * 1024ULL;
    /// Maximum requests served on one keep-alive connection before closing.
    int max_keep_alive_requests = 100;

    /// Value sent in the Server response header.
    std::string server_name = "mog";

    /// TLS configuration. When @c enabled, the server speaks HTTPS.
    TlsServerConfig tls{};
};

/**
 * @brief An embedded HTTP/1.1 server.
 *
 * Register handlers and static mounts, then @ref start. Routing precedence:
 * exact method+path routes, then static mounts (longest matching prefix), then
 * the default handler (404 if unset). The destructor stops the server.
 */
class Server
{
  public:
    explicit Server(ServerOptions options = {});
    ~Server();

    Server(const Server &) = delete;
    Server &operator=(const Server &) = delete;
    Server(Server &&) noexcept;
    Server &operator=(Server &&) noexcept;

    /**
     * @brief Register an exact-match handler for @p method and @p path.
     * @note Must be called before @ref start.
     */
    Server &route(Method method, std::string path, Handler handler);

    /**
     * @brief Serve files under @p directory at URL prefix @p mount_prefix.
     * @note Must be called before @ref start. Path traversal outside
     *       @p directory is rejected.
     */
    Server &serve_files(std::string mount_prefix, std::string directory, StaticOptions opt = {});

    /**
     * @brief Set the fallback handler used when nothing else matches.
     * @note Must be called before @ref start. Defaults to a 404.
     */
    Server &set_default_handler(Handler handler);

    /**
     * @brief Bind, then start the accept loop and worker pool. Non-blocking.
     * @note Browser WebAssembly returns @c UnsupportedBackend because browsers
     *       cannot listen for raw TCP connections.
     * @return An error if binding fails or the server is already running.
     */
    [[nodiscard]] Result<void> start();

    /// Stop accepting, drain in-flight connections, and join all threads.
    void stop() noexcept;

    /// Block until the server stops (via @ref stop or another thread).
    void wait();

    [[nodiscard]] bool running() const noexcept;

    /// The bound port (useful when @ref ServerOptions::port was 0). 0 if not started.
    [[nodiscard]] std::uint16_t port() const noexcept;

  private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
};

} // namespace mog
