/**
 * @file json.hpp
 * @brief nlohmann/json interop for mog (cppboot preferred JSON library).
 *
 * Available when the library is built with @c MOG_WITH_JSON=ON (default for
 * top-level cppboot apps). Defines @c MOG_HAS_JSON=1 on the mog target.
 *
 * String-based JSON helpers in options.hpp always work; this header adds
 * overloads and parse helpers that accept / return @c nlohmann::json.
 */
#pragma once

#ifndef MOG_HAS_JSON
#error "mog/json.hpp requires MOG_WITH_JSON (nlohmann/json). Enable MOG_WITH_JSON in CMake."
#endif

#include "mog/error.hpp"
#include "mog/http.hpp"
#include "mog/options.hpp"
#include "mog/response.hpp"
#include "mog/session.hpp"

#include <nlohmann/json.hpp>
#include <string>
#include <string_view>
#include <utility>

namespace mog
{

/**
 * @brief Set the request body from a nlohmann::json value (compact dump).
 *
 * Sets Content-Type to application/json unless the caller already set it.
 * (Content-Type is applied at request prepare time from Options::json.)
 */
inline Options &WithJson(Options &opt, const nlohmann::json &value)
{
    opt.json = value.dump();
    return opt;
}

/**
 * @brief Set the request body from a nlohmann::json value with dump indent.
 * @param indent Indent width passed to @c nlohmann::json::dump (-1 = compact).
 */
inline Options &WithJson(Options &opt, const nlohmann::json &value, int indent)
{
    opt.json = value.dump(indent);
    return opt;
}

/**
 * @brief Build Options with a JSON body from nlohmann::json.
 */
[[nodiscard]] inline Options JsonOptions(const nlohmann::json &value)
{
    Options opt;
    opt.json = value.dump();
    return opt;
}

/**
 * @brief Parse a response body as JSON.
 * @return Parsed document, or @c ErrorCode::JsonError on parse failure.
 */
[[nodiscard]] inline Result<nlohmann::json> ParseJson(const Response &response)
{
    try
    {
        return Result<nlohmann::json>::Ok(nlohmann::json::parse(response.body));
    }
    catch (const nlohmann::json::exception &ex)
    {
        return Result<nlohmann::json>::Err(
            Error{ErrorCode::JsonError, std::string("JSON parse failed: ") + ex.what()});
    }
}

/**
 * @brief Parse @p text as JSON.
 */
[[nodiscard]] inline Result<nlohmann::json> ParseJson(std::string_view text)
{
    try
    {
        return Result<nlohmann::json>::Ok(nlohmann::json::parse(text.begin(), text.end()));
    }
    catch (const nlohmann::json::exception &ex)
    {
        return Result<nlohmann::json>::Err(
            Error{ErrorCode::JsonError, std::string("JSON parse failed: ") + ex.what()});
    }
}

/**
 * @brief Convenience: POST @p value as JSON.
 */
[[nodiscard]] inline Result<Response> post_json(std::string_view url, const nlohmann::json &value,
                                                Options options = {})
{
    WithJson(options, value);
    return post(url, options);
}

/**
 * @brief Convenience: PUT @p value as JSON.
 */
[[nodiscard]] inline Result<Response> put_json(std::string_view url, const nlohmann::json &value,
                                               Options options = {})
{
    WithJson(options, value);
    return put(url, options);
}

/**
 * @brief Convenience: PATCH @p value as JSON.
 */
[[nodiscard]] inline Result<Response> patch_json(std::string_view url, const nlohmann::json &value,
                                                 Options options = {})
{
    WithJson(options, value);
    return patch(url, options);
}

/**
 * @brief Session helpers for JSON bodies.
 */
inline Result<Response> post_json(Session &session, std::string_view url,
                                  const nlohmann::json &value, Options options = {})
{
    WithJson(options, value);
    return session.post(url, options);
}

inline Result<Response> put_json(Session &session, std::string_view url,
                                 const nlohmann::json &value, Options options = {})
{
    WithJson(options, value);
    return session.put(url, options);
}

inline Result<Response> patch_json(Session &session, std::string_view url,
                                   const nlohmann::json &value, Options options = {})
{
    WithJson(options, value);
    return session.patch(url, options);
}

} // namespace mog
