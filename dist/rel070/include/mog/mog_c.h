/**
 * @file mog_c.h
 * @brief C API for mog: a plain C, FFI-friendly binding over the C++ client.
 *
 * This header is valid C and C++. It exposes mog through opaque handles and
 * borrowed strings so it is easy to drive from C and from foreign function
 * interfaces such as Python ctypes, LuaJIT FFI, or Ruby Fiddle.
 *
 * Memory model (there are exactly two things to free):
 *   - A request handle from mog_request_new(), released with mog_request_free().
 *   - A response handle from mog_perform() / mog_get() / mog_post(), released
 *     with mog_response_free().
 * Every `const char *` and byte buffer returned by an accessor is borrowed from
 * its handle and stays valid until that handle is freed. Do not free them
 * yourself. Copy anything you need to outlive the handle.
 *
 * Strings are UTF-8 and NUL-terminated. Response bodies may contain embedded
 * NUL bytes, so read them with mog_response_body() and its length out-param.
 *
 * Errors never cross the boundary as C++ exceptions. A failed transfer still
 * returns a non-NULL response handle whose mog_response_ok() is 0; inspect
 * mog_response_error_code() and mog_response_error_message().
 *
 * Thread-safety matches the C++ library: a single handle must not be used from
 * two threads at once, but independent handles are independent.
 */
#ifndef MOG_C_H
#define MOG_C_H

#include <stddef.h>

/**
 * @def MOG_C_API
 * @brief Export/import decoration for the C API symbols.
 *
 * The shared library is built with MOG_C_BUILD_SHARED defined. Consumers that
 * link the import library on Windows should define MOG_C_USE_SHARED; ctypes and
 * other runtime loaders need neither.
 */
#if defined(_WIN32)
#if defined(MOG_C_BUILD_SHARED)
#define MOG_C_API __declspec(dllexport)
#elif defined(MOG_C_USE_SHARED)
#define MOG_C_API __declspec(dllimport)
#else
#define MOG_C_API
#endif
#else
#if defined(MOG_C_BUILD_SHARED)
#define MOG_C_API __attribute__((visibility("default")))
#else
#define MOG_C_API
#endif
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Stable error categories. These mirror mog::ErrorCode by name and value.
     */
    typedef enum mog_error_code
    {
        MOG_OK = 0,
        MOG_ERR_INVALID_URL,
        MOG_ERR_INVALID_ARGUMENT,
        MOG_ERR_UNSUPPORTED_SCHEME,
        MOG_ERR_UNSUPPORTED_BACKEND,
        MOG_ERR_DNS_FAILED,
        MOG_ERR_CONNECT_FAILED,
        MOG_ERR_TLS_FAILED,
        MOG_ERR_TIMEOUT,
        MOG_ERR_IO,
        MOG_ERR_PROTOCOL,
        MOG_ERR_TOO_MANY_REDIRECTS,
        MOG_ERR_HTTP_STATUS,
        MOG_ERR_RESPONSE_TOO_LARGE,
        MOG_ERR_PROXY,
        MOG_ERR_FILE,
        MOG_ERR_JSON,
        MOG_ERR_COMPRESSION,
        MOG_ERR_DYNAMIC_LIBRARY,
        MOG_ERR_INTERNAL
    } mog_error_code;

    /** @brief Opaque request builder. Create with mog_request_new(). */
    typedef struct mog_request mog_request;

    /** @brief Opaque response. Returned by mog_perform() and the conveniences. */
    typedef struct mog_response mog_response;

    /* ------------------------------------------------------------------ */
    /* Library information                                                 */
    /* ------------------------------------------------------------------ */

    /** @return Version string such as "0.1.0". Never NULL; static storage. */
    MOG_C_API const char *mog_version(void);

    /** @return Short name for an error code, e.g. "timeout". Never NULL. */
    MOG_C_API const char *mog_error_code_name(mog_error_code code);

    /* ------------------------------------------------------------------ */
    /* Request builder                                                    */
    /* ------------------------------------------------------------------ */

    /**
     * @brief Create a request for @p method against @p url.
     * @param method HTTP method, case-insensitive ("GET", "POST", "PUT", ...).
     * @param url    Absolute URL. Required.
     * @return New request handle, or NULL if arguments are missing/invalid or on
     *         allocation failure. Free with mog_request_free().
     */
    MOG_C_API mog_request *mog_request_new(const char *method, const char *url);

    /** @brief Release a request handle. Safe to call with NULL. */
    MOG_C_API void mog_request_free(mog_request *req);

    /* Setters are no-ops when @p req is NULL. All string arguments are copied. */

    /** @brief Set (replacing any prior value of) a request header. */
    MOG_C_API void mog_request_set_header(mog_request *req, const char *name, const char *value);
    /** @brief Set the raw request body (binary-safe). */
    MOG_C_API void mog_request_set_body(mog_request *req, const void *data, size_t len);
    /** @brief Set a JSON body and default Content-Type: application/json. */
    MOG_C_API void mog_request_set_json(mog_request *req, const char *json);
    /** @brief Add a query-string parameter. */
    MOG_C_API void mog_request_set_query_param(mog_request *req, const char *name,
                                               const char *value);
    /** @brief Add a cookie (name/value) sent on this request. */
    MOG_C_API void mog_request_set_cookie(mog_request *req, const char *name, const char *value);
    /** @brief Overall per-operation I/O timeout in milliseconds. */
    MOG_C_API void mog_request_set_timeout_ms(mog_request *req, long milliseconds);
    /** @brief Connect-phase timeout in milliseconds (defaults to the I/O timeout). */
    MOG_C_API void mog_request_set_connect_timeout_ms(mog_request *req, long milliseconds);
    /** @brief Enable TLS certificate verification (nonzero = on, the default). */
    MOG_C_API void mog_request_set_verify_tls(mog_request *req, int enable);
    /** @brief Use a PEM CA bundle file for TLS trust (highest precedence). */
    MOG_C_API void mog_request_set_ca_bundle(mog_request *req, const char *path);
    /**
     * @brief Present a client certificate for mutual TLS.
     * @param key_path     Private key PEM; NULL or "" reuses @p cert_path.
     * @param key_password Passphrase for an encrypted key; NULL or "" if none.
     */
    MOG_C_API void mog_request_set_client_cert(mog_request *req, const char *cert_path,
                                               const char *key_path, const char *key_password);
    /** @brief HTTP Basic auth. */
    MOG_C_API void mog_request_set_basic_auth(mog_request *req, const char *user,
                                              const char *password);
    /** @brief Bearer token (without the "Bearer " prefix). */
    MOG_C_API void mog_request_set_bearer_token(mog_request *req, const char *token);
    /** @brief HTTP Digest auth (sent in response to a 401 challenge). */
    MOG_C_API void mog_request_set_digest_auth(mog_request *req, const char *user,
                                               const char *password);
    /** @brief HTTP proxy URL, e.g. "http://127.0.0.1:8080". */
    MOG_C_API void mog_request_set_proxy(mog_request *req, const char *proxy_url);
    /**
     * @brief Force a backend by name: "auto", "embedded", "curl", "winhttp", "native", "web".
     *        An unknown name leaves the current selection unchanged.
     */
    MOG_C_API void mog_request_set_backend(mog_request *req, const char *backend);
    /** @brief Follow 3xx redirects (nonzero = on, the default). */
    MOG_C_API void mog_request_set_allow_redirects(mog_request *req, int enable);
    /** @brief Maximum redirects to follow when redirects are enabled. */
    MOG_C_API void mog_request_set_max_redirects(mog_request *req, int max_redirects);
    /** @brief Cap the response body size in bytes (0 = unlimited). */
    MOG_C_API void mog_request_set_max_response_bytes(mog_request *req, size_t max_bytes);
    /** @brief Advertise and decode gzip/deflate (nonzero = on, the default). */
    MOG_C_API void mog_request_set_decompress(mog_request *req, int enable);
    /** @brief Override the User-Agent header. */
    MOG_C_API void mog_request_set_user_agent(mog_request *req, const char *user_agent);

    /**
     * @brief Perform @p req and return a response handle.
     * @return Non-NULL on success or transport error (check mog_response_ok());
     *         NULL only when @p req is NULL or on allocation failure. Free with
     *         mog_response_free(). The request handle may be reused or freed after.
     */
    MOG_C_API mog_response *mog_perform(mog_request *req);

    /* ------------------------------------------------------------------ */
    /* One-shot conveniences                                              */
    /* ------------------------------------------------------------------ */

    /** @brief GET @p url with default options. Free the result with mog_response_free(). */
    MOG_C_API mog_response *mog_get(const char *url);
    /** @brief POST @p url with a raw body. Free the result with mog_response_free(). */
    MOG_C_API mog_response *mog_post(const char *url, const void *body, size_t len);

    /* ------------------------------------------------------------------ */
    /* Response accessors (all borrow from the response until it is freed) */
    /* ------------------------------------------------------------------ */

    /** @return 1 if the exchange completed at the transport level (an HTTP 4xx/5xx
     *          still returns 1); 0 on a transport error or NULL handle. */
    MOG_C_API int mog_response_ok(const mog_response *resp);
    /** @return Error category (MOG_OK when the exchange completed). */
    MOG_C_API mog_error_code mog_response_error_code(const mog_response *resp);
    /** @return Error message, or "" when there is no error. Never NULL. */
    MOG_C_API const char *mog_response_error_message(const mog_response *resp);
    /** @return HTTP status code, or 0 if unavailable. */
    MOG_C_API int mog_response_status(const mog_response *resp);
    /** @return Reason phrase, or "". Never NULL. */
    MOG_C_API const char *mog_response_reason(const mog_response *resp);
    /** @return Final URL after redirects, or "". Never NULL. */
    MOG_C_API const char *mog_response_url(const mog_response *resp);
    /**
     * @brief Response body bytes (binary-safe).
     * @param len_out If non-NULL, receives the body length in bytes.
     * @return Pointer to the body (NUL-terminated for text convenience). Never NULL;
     *         may point at an empty buffer.
     */
    MOG_C_API const char *mog_response_body(const mog_response *resp, size_t *len_out);
    /** @return Body length in bytes. */
    MOG_C_API size_t mog_response_body_size(const mog_response *resp);
    /** @return Number of response headers (duplicates preserved, in order). */
    MOG_C_API size_t mog_response_header_count(const mog_response *resp);
    /** @return Header name at @p index, or "" if out of range. Never NULL. */
    MOG_C_API const char *mog_response_header_name(const mog_response *resp, size_t index);
    /** @return Header value at @p index, or "" if out of range. Never NULL. */
    MOG_C_API const char *mog_response_header_value(const mog_response *resp, size_t index);
    /** @return First value for @p name (case-insensitive), or "". Never NULL. */
    MOG_C_API const char *mog_response_header(const mog_response *resp, const char *name);
    /** @return Wall time spent on the exchange, in milliseconds. */
    MOG_C_API long mog_response_elapsed_ms(const mog_response *resp);
    /** @return Number of body bytes received. */
    MOG_C_API size_t mog_response_downloaded_bytes(const mog_response *resp);
    /** @return Name of the backend that served the request, or "". Never NULL. */
    MOG_C_API const char *mog_response_backend(const mog_response *resp);
    /** @brief Release a response handle (and its borrowed strings). Safe with NULL. */
    MOG_C_API void mog_response_free(mog_response *resp);

    /* ================================================================== */
    /* Embedded HTTP/S server                                             */
    /* ================================================================== */
    /*
     * Build a server with mog_server_new(), configure it, register routes and/or a
     * static directory, then mog_server_start() (non-blocking). Free it with
     * mog_server_free() (which stops it first).
     *
     * A route handler is a C callback invoked on a worker thread for each matching
     * request. It receives a borrowed request view and a response builder, both
     * valid ONLY for the duration of the call; do not retain them. Because handlers
     * run on worker threads, any shared state a handler touches must be synchronized
     * by the handler. From Python ctypes, wrap the handler in CFUNCTYPE (ctypes
     * acquires the GIL for the callback); keep a reference to the CFUNCTYPE object
     * alive for the lifetime of the server.
     */

    /** @brief Opaque server. Create with mog_server_new(). */
    typedef struct mog_server mog_server;
    /** @brief Borrowed inbound request, valid only during a handler call. */
    typedef struct mog_server_request mog_server_request;
    /** @brief Response builder, valid only during a handler call. */
    typedef struct mog_server_response mog_server_response;

    /**
     * @brief Route/default handler callback.
     * @param req      Borrowed request (read-only) for this call.
     * @param resp     Response builder to populate for this call.
     * @param userdata The pointer passed at registration.
     */
    typedef void (*mog_handler_fn)(const mog_server_request *req, mog_server_response *resp,
                                   void *userdata);

    /** @brief Create a server with default options. Free with mog_server_free(). */
    MOG_C_API mog_server *mog_server_new(void);
    /** @brief Stop (if running) and free a server. Safe to call with NULL. */
    MOG_C_API void mog_server_free(mog_server *server);

    /* Configuration. Effective only before mog_server_start(); no-ops afterward. */

    /** @brief Interface to bind (e.g. "127.0.0.1", "0.0.0.0"). */
    MOG_C_API void mog_server_set_bind_address(mog_server *server, const char *address);
    /** @brief Port to listen on. 0 selects an ephemeral port (read mog_server_port()). */
    MOG_C_API void mog_server_set_port(mog_server *server, unsigned short port);
    /** @brief Worker thread count (0 = hardware concurrency). */
    MOG_C_API void mog_server_set_threads(mog_server *server, unsigned threads);

    /**
     * @brief Serve HTTPS with an ephemeral self-signed certificate (dev/testing).
     * @return 0 on success, nonzero on failure (see mog_server_last_error()).
     */
    MOG_C_API int mog_server_use_self_signed_tls(mog_server *server);
    /**
     * @brief Serve HTTPS with a certificate chain and private key (PEM files).
     * @return 0 on success, nonzero on failure (see mog_server_last_error()).
     */
    MOG_C_API int mog_server_use_tls_files(mog_server *server, const char *cert_path,
                                           const char *key_path);

    /** @brief Serve files under @p directory at URL prefix @p mount_prefix. */
    MOG_C_API void mog_server_serve_files(mog_server *server, const char *mount_prefix,
                                          const char *directory, int directory_listing);
    /**
     * @brief Register an exact method+path handler.
     * @return 0 on success, nonzero if @p method is not a valid HTTP method.
     */
    MOG_C_API int mog_server_route(mog_server *server, const char *method, const char *path,
                                   mog_handler_fn handler, void *userdata);
    /** @brief Set the fallback handler used when nothing else matches (default: 404). */
    MOG_C_API void mog_server_set_default_handler(mog_server *server, mog_handler_fn handler,
                                                  void *userdata);

    /**
     * @brief Bind and start the accept loop and worker pool. Non-blocking.
     * @return 0 on success, nonzero on failure (see mog_server_last_error()).
     */
    MOG_C_API int mog_server_start(mog_server *server);
    /** @brief The bound port (useful when the configured port was 0). 0 if not started. */
    MOG_C_API unsigned short mog_server_port(const mog_server *server);
    /** @return 1 if the server is running, else 0. */
    MOG_C_API int mog_server_is_running(const mog_server *server);
    /** @brief Stop accepting, drain in-flight connections, and join threads. */
    MOG_C_API void mog_server_stop(mog_server *server);
    /** @brief Block until the server stops (via another thread's mog_server_stop()). */
    MOG_C_API void mog_server_wait(mog_server *server);
    /** @return Message for the most recent failure, or "". Never NULL. */
    MOG_C_API const char *mog_server_last_error(const mog_server *server);

    /* Request accessors (borrow from @p req; valid only during the handler call). */

    /** @return Request method, e.g. "GET". Never NULL. */
    MOG_C_API const char *mog_server_request_method(const mog_server_request *req);
    /** @return Decoded request path (no query string). Never NULL. */
    MOG_C_API const char *mog_server_request_path(const mog_server_request *req);
    /** @return Raw request target (path plus any "?query"). Never NULL. */
    MOG_C_API const char *mog_server_request_target(const mog_server_request *req);
    /** @return Remote peer address. Never NULL. */
    MOG_C_API const char *mog_server_request_client_address(const mog_server_request *req);
    /** @return First value for a query parameter @p name, or "". Never NULL. */
    MOG_C_API const char *mog_server_request_query(const mog_server_request *req, const char *name);
    /** @return First value for header @p name (case-insensitive), or "". Never NULL. */
    MOG_C_API const char *mog_server_request_header(const mog_server_request *req,
                                                    const char *name);
    /** @return Request body bytes (binary-safe); writes the length to @p len_out if non-NULL. */
    MOG_C_API const char *mog_server_request_body(const mog_server_request *req, size_t *len_out);

    /* Response builders (populate @p resp during the handler call). */

    /** @brief Set the HTTP status code (default 200). */
    MOG_C_API void mog_server_response_set_status(mog_server_response *resp, int status);
    /** @brief Set or replace a response header. */
    MOG_C_API void mog_server_response_set_header(mog_server_response *resp, const char *name,
                                                  const char *value);
    /** @brief Set the response body (binary-safe). */
    MOG_C_API void mog_server_response_set_body(mog_server_response *resp, const void *data,
                                                size_t len);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MOG_C_H */
