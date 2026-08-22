// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: mog HTTP/S
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_MOG_H_
#define SDLSTATIC_CPP_GEN_MOG_H_

#include <mog/mog_c.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace mog {

// RAII owner for mog_request (destroyed with mog_request_free).
class Request {
 public:
  static Result<Request> request_new(const char *method, const char *url) {
    mog_request* created_ = ::mog_request_new(method, url);
    if (created_ == nullptr) {
      return Status::Error("mog_request_new failed");
    }
    return Request(created_);
  }

  Request() = default;
  ~Request() { reset(); }
  Request(Request&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Request& operator=(Request&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Request(const Request&) = delete;
  Request& operator=(const Request&) = delete;

  mog_request* get() const { return value_; }
  mog_request* release() {
    mog_request* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::mog_request_free(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  void request_set_header(const char *name, const char *value) { ::mog_request_set_header(value_, name, value); }
  void request_set_body(const void *data, size_t len) { ::mog_request_set_body(value_, data, len); }
  void request_set_json(const char *json) { ::mog_request_set_json(value_, json); }
  void request_set_query_param(const char *name, const char *value) { ::mog_request_set_query_param(value_, name, value); }
  void request_set_cookie(const char *name, const char *value) { ::mog_request_set_cookie(value_, name, value); }
  void request_set_timeout_ms(long milliseconds) { ::mog_request_set_timeout_ms(value_, milliseconds); }
  void request_set_connect_timeout_ms(long milliseconds) { ::mog_request_set_connect_timeout_ms(value_, milliseconds); }
  void request_set_verify_tls(int enable) { ::mog_request_set_verify_tls(value_, enable); }
  void request_set_ca_bundle(const char *path) { ::mog_request_set_ca_bundle(value_, path); }
  void request_set_client_cert(const char *cert_path, const char *key_path, const char *key_password) { ::mog_request_set_client_cert(value_, cert_path, key_path, key_password); }
  void request_set_basic_auth(const char *user, const char *password) { ::mog_request_set_basic_auth(value_, user, password); }
  void request_set_bearer_token(const char *token) { ::mog_request_set_bearer_token(value_, token); }
  void request_set_digest_auth(const char *user, const char *password) { ::mog_request_set_digest_auth(value_, user, password); }
  void request_set_proxy(const char *proxy_url) { ::mog_request_set_proxy(value_, proxy_url); }
  void request_set_backend(const char *backend) { ::mog_request_set_backend(value_, backend); }
  void request_set_allow_redirects(int enable) { ::mog_request_set_allow_redirects(value_, enable); }
  void request_set_max_redirects(int max_redirects) { ::mog_request_set_max_redirects(value_, max_redirects); }
  void request_set_max_response_bytes(size_t max_bytes) { ::mog_request_set_max_response_bytes(value_, max_bytes); }
  void request_set_decompress(int enable) { ::mog_request_set_decompress(value_, enable); }
  void request_set_user_agent(const char *user_agent) { ::mog_request_set_user_agent(value_, user_agent); }
 private:
  explicit Request(mog_request* value) : value_(value), engaged_(true) {}
  mog_request* value_{};
  bool engaged_ = false;
};

// RAII owner for mog_response (destroyed with mog_response_free).
class Response {
 public:
  static Result<Response> perform(mog_request *req) {
    mog_response* created_ = ::mog_perform(req);
    if (created_ == nullptr) {
      return Status::Error("mog_perform failed");
    }
    return Response(created_);
  }
  static Result<Response> get(const char *url) {
    mog_response* created_ = ::mog_get(url);
    if (created_ == nullptr) {
      return Status::Error("mog_get failed");
    }
    return Response(created_);
  }
  static Result<Response> post(const char *url, const void *body, size_t len) {
    mog_response* created_ = ::mog_post(url, body, len);
    if (created_ == nullptr) {
      return Status::Error("mog_post failed");
    }
    return Response(created_);
  }

  Response() = default;
  ~Response() { reset(); }
  Response(Response&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Response& operator=(Response&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Response(const Response&) = delete;
  Response& operator=(const Response&) = delete;

  mog_response* get() const { return value_; }
  mog_response* release() {
    mog_response* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::mog_response_free(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  int response_ok() {
    return ::mog_response_ok(value_);
  }
  mog_error_code response_error_code() {
    return ::mog_response_error_code(value_);
  }
  const char* response_error_message() {
    return ::mog_response_error_message(value_);
  }
  int response_status() {
    return ::mog_response_status(value_);
  }
  const char* response_reason() {
    return ::mog_response_reason(value_);
  }
  const char* response_url() {
    return ::mog_response_url(value_);
  }
  const char* response_body(size_t *len_out) {
    return ::mog_response_body(value_, len_out);
  }
  size_t response_body_size() {
    return ::mog_response_body_size(value_);
  }
  size_t response_header_count() {
    return ::mog_response_header_count(value_);
  }
  const char* response_header_name(size_t index) {
    return ::mog_response_header_name(value_, index);
  }
  const char* response_header_value(size_t index) {
    return ::mog_response_header_value(value_, index);
  }
  const char* response_header(const char *name) {
    return ::mog_response_header(value_, name);
  }
  long response_elapsed_ms() {
    return ::mog_response_elapsed_ms(value_);
  }
  size_t response_downloaded_bytes() {
    return ::mog_response_downloaded_bytes(value_);
  }
  const char* response_backend() {
    return ::mog_response_backend(value_);
  }
 private:
  explicit Response(mog_response* value) : value_(value), engaged_(true) {}
  mog_response* value_{};
  bool engaged_ = false;
};

// RAII owner for mog_server (destroyed with mog_server_free).
class Server {
 public:
  static Result<Server> server_new() {
    mog_server* created_ = ::mog_server_new();
    if (created_ == nullptr) {
      return Status::Error("mog_server_new failed");
    }
    return Server(created_);
  }

  Server() = default;
  ~Server() { reset(); }
  Server(Server&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Server& operator=(Server&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Server(const Server&) = delete;
  Server& operator=(const Server&) = delete;

  mog_server* get() const { return value_; }
  mog_server* release() {
    mog_server* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::mog_server_free(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  void server_set_bind_address(const char *address) { ::mog_server_set_bind_address(value_, address); }
  void server_set_port(unsigned short port) { ::mog_server_set_port(value_, port); }
  void server_set_threads(unsigned threads) { ::mog_server_set_threads(value_, threads); }
  int server_use_self_signed_tls() {
    return ::mog_server_use_self_signed_tls(value_);
  }
  int server_use_tls_files(const char *cert_path, const char *key_path) {
    return ::mog_server_use_tls_files(value_, cert_path, key_path);
  }
  void server_serve_files(const char *mount_prefix, const char *directory, int directory_listing) { ::mog_server_serve_files(value_, mount_prefix, directory, directory_listing); }
  int server_route(const char *method, const char *path, mog_handler_fn handler, void *userdata) {
    return ::mog_server_route(value_, method, path, handler, userdata);
  }
  void server_set_default_handler(mog_handler_fn handler, void *userdata) { ::mog_server_set_default_handler(value_, handler, userdata); }
  int server_start() {
    return ::mog_server_start(value_);
  }
  unsigned short server_port() {
    return ::mog_server_port(value_);
  }
  int server_is_running() {
    return ::mog_server_is_running(value_);
  }
  void server_stop() { ::mog_server_stop(value_); }
  void server_wait() { ::mog_server_wait(value_); }
  const char* server_last_error() {
    return ::mog_server_last_error(value_);
  }
 private:
  explicit Server(mog_server* value) : value_(value), engaged_(true) {}
  mog_server* value_{};
  bool engaged_ = false;
};

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& error_code_name = ::mog_error_code_name;
inline constexpr auto& server_request_body = ::mog_server_request_body;
inline constexpr auto& server_request_client_address = ::mog_server_request_client_address;
inline constexpr auto& server_request_header = ::mog_server_request_header;
inline constexpr auto& server_request_method = ::mog_server_request_method;
inline constexpr auto& server_request_path = ::mog_server_request_path;
inline constexpr auto& server_request_query = ::mog_server_request_query;
inline constexpr auto& server_request_target = ::mog_server_request_target;
inline constexpr auto& server_response_set_body = ::mog_server_response_set_body;
inline constexpr auto& server_response_set_header = ::mog_server_response_set_header;
inline constexpr auto& server_response_set_status = ::mog_server_response_set_status;
inline constexpr auto& version = ::mog_version;

}  // namespace mog
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_MOG_H_
// clang-format on
