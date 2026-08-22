/**
 * @file cli.hpp
 * @brief CLI façade: parse argv, map flags to Options, run a request, write output.
 *
 * Responsibilities are split in the library (SRP):
 * - ParseArgv          — argv → Args (CLI11 front-end)
 * - PrepareRequest     — Args → Prepared (domain mapping)
 * - ResolveLogLevel    — Args → log configuration
 * - Run / RunArgv      — use-case orchestration (open for new backends via registry)
 * - FormatWriteOut / Write* — presentation of results
 *
 * @c main.cpp should only call @ref RunArgv (or ParseArgv + Run) and map exit codes
 * to the process.
 */
#pragma once

#include "mog/error.hpp"
#include "mog/log.hpp"
#include "mog/options.hpp"
#include "mog/response.hpp"
#include "mog/server.hpp"

#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace mog::cli
{

/**
 * @brief Parsed CLI arguments (mirrors CLI11 bindings). Pure data.
 */
struct Args
{
    std::string url;
    std::string method = "GET";
    std::vector<std::string> headers;
    std::string data;
    std::string json;
    std::vector<std::string> form_fields;
    std::string output;
    std::string dump_header;
    std::string backend;
    std::string user;
    std::string bearer;
    std::string user_agent;
    std::string referer;
    std::string cookie;
    std::string proxy;
    std::string ca_bundle;
    std::string client_cert;
    std::string client_key;
    std::string client_key_password;
    double timeout_sec = 30.0;
    double connect_timeout_sec = -1.0;
    int max_redirs = 5;
    bool insecure = false;
    bool verbose = false;
    bool include_headers = false;
    bool fail_on_error = false;
    bool head = false;
    bool no_location = false;
    bool get_with_data = false;
    bool silent = false;
    bool show_error = false;
    bool no_decompress = false;
    bool digest = false;
    std::string write_out;
    std::string log_level;
};

/**
 * @brief Fully resolved CLI request ready for mog::request and output handling.
 */
struct Prepared
{
    Options options;
    Method method = Method::Get;
    std::string url;
    std::string output;
    std::string dump_header;
    std::string write_out;
    bool include_headers = false;
    bool fail_on_error = false;
    bool verbose = false;
    bool silent = false;
    bool show_error = false;
};

/**
 * @brief Optional stream injection for tests (default: cout/cerr).
 */
struct Streams
{
    std::ostream *out = &std::cout;
    std::ostream *err = &std::cerr;
};

// --- Logging configuration (Args → LogLevel) ---

/**
 * @brief Resolve log level from flags.
 *
 * Precedence: @c log_level > @c silent (off) > @c verbose (debug) > info.
 * Invalid @c log_level falls back to info and returns false via @p ok.
 */
[[nodiscard]] LogLevel ResolveLogLevel(const Args &args, bool *ok = nullptr);

/**
 * @brief Install the default logger at the level implied by @p args.
 * @return false if @c log_level was set but invalid (logger still installed at info).
 */
bool ConfigureLogging(const Args &args);

// --- Mapping (Args → Prepared) ---

/**
 * @brief Load @c -d / --json values; supports @file syntax.
 */
[[nodiscard]] Result<std::string> LoadDataArg(std::string_view data);

/**
 * @brief Map CLI args into library Options + Method.
 */
[[nodiscard]] Result<Prepared> PrepareRequest(const Args &args);

// --- Presentation ---

/**
 * @brief Expand curl-style -w format tokens against a response.
 */
[[nodiscard]] std::string FormatWriteOut(std::string_view format, const Response &response);

/**
 * @brief Format a response status line + headers block (HTTP/1.1 wire style).
 */
[[nodiscard]] std::string FormatHeaderBlock(const Response &response);

/**
 * @brief Write response body (and optional headers) to @p out according to @p prepared.
 */
[[nodiscard]] Result<void> WriteResponseOutput(const Prepared &prepared, const Response &response,
                                               std::ostream &out);

/**
 * @brief Write response headers to the dump-header path when configured.
 */
[[nodiscard]] Result<void> WriteHeaderDump(const Prepared &prepared, const Response &response);

[[nodiscard]] int ExitCodeForResponse(const Prepared &prepared, const Response &response);
[[nodiscard]] int ExitCodeForError(const Prepared &prepared);
[[nodiscard]] int ExitCodeForPrepareError(const Error &error);

// --- Use-case orchestration ---

/**
 * @brief Run a fully prepared CLI request: HTTP exchange + output side effects.
 * @return Process exit code (0, 1, 2, or 22).
 */
[[nodiscard]] int Run(const Prepared &prepared, Streams streams = {});

/**
 * @brief Configure logging, prepare, and run from parsed @p args.
 */
[[nodiscard]] int Run(const Args &args, Streams streams = {});

// --- `mog serve`: embedded static file server ---

/**
 * @brief Parsed arguments for the `serve` subcommand. Pure data.
 */
struct ServeArgs
{
    std::string directory = ".";
    std::string bind_address = "127.0.0.1";
    std::uint16_t port = 8000;
    unsigned threads = 0; ///< 0 = hardware concurrency.
    bool self_signed = false;
    std::string tls_cert;
    std::string tls_key;
    bool no_listing = false;
};

/**
 * @brief Map @ref ServeArgs into @ref ServerOptions (resolves TLS config).
 * @return An error if TLS material is invalid or inconsistent.
 */
[[nodiscard]] Result<ServerOptions> BuildServeOptions(const ServeArgs &args);

/// Sentinel returned by @ref ParseServeArgv when `--help` was printed (exit 0).
extern const char *const kServeHelpShown;

#if defined(MOG_HAS_CLI11) && MOG_HAS_CLI11
/**
 * @brief Parse `serve` subcommand argv (argv[1] == "serve") into @ref ServeArgs.
 */
[[nodiscard]] Result<ServeArgs> ParseServeArgv(int argc, char **argv);

/**
 * @brief Run the `serve` subcommand: start the server and block until interrupted.
 * @return Process exit code.
 */
[[nodiscard]] int RunServe(const ServeArgs &args, Streams streams = {});

/**
 * @brief Parse argv with CLI11 into Args (does not run the request).
 */
[[nodiscard]] Result<Args> ParseArgv(int argc, char **argv);
[[nodiscard]] Result<Args> ParseArgv(const std::vector<std::string> &args);

/**
 * @brief Full CLI entry: parse argv, run, return exit code.
 *
 * Handles --version. Writes parse errors to @p streams.err.
 * This is the function @c main should call.
 */
[[nodiscard]] int RunArgv(int argc, char **argv, Streams streams = {});
#endif

} // namespace mog::cli
