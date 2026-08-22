/**
 * @file log.hpp
 * @brief Process-wide logging for mog (spdlog when MOG_WITH_SPDLOG is ON).
 *
 * Library code and the CLI share one logger. Callers may inject their own
 * spdlog logger, or use @ref MakeDefaultLogger / @ref UseDefaultLogger (the
 * same stderr-colored logger the CLI uses).
 */
#pragma once

#include <memory>
#include <string>
#include <string_view>

#if defined(MOG_HAS_SPDLOG) && MOG_HAS_SPDLOG
#include <spdlog/spdlog.h>
#endif

namespace mog
{

/**
 * @brief Portable log levels (map to spdlog when available).
 */
enum class LogLevel
{
    Trace = 0,
    Debug,
    Info,
    Warn,
    Error,
    Critical,
    Off,
};

/**
 * @brief Parse a level name (case-insensitive): trace, debug, info, warn, error, critical, off.
 */
[[nodiscard]] bool ParseLogLevel(std::string_view text, LogLevel &out);

/**
 * @return Canonical lowercase name for @p level.
 */
[[nodiscard]] std::string_view ToString(LogLevel level) noexcept;

#if defined(MOG_HAS_SPDLOG) && MOG_HAS_SPDLOG

using LoggerPtr = std::shared_ptr<spdlog::logger>;

/**
 * @brief Create the default mog logger (stderr, colored, pattern with timestamp).
 *
 * This is the same logger style used by the mog CLI.
 * @param level Initial level (default Info for situational awareness).
 */
[[nodiscard]] LoggerPtr MakeDefaultLogger(LogLevel level = LogLevel::Info);

/**
 * @brief Install @p logger for all subsequent mog log output.
 *
 * Pass nullptr to clear and recreate the default logger on next @ref GetLogger.
 * Thread-safe.
 */
void SetLogger(LoggerPtr logger);

/**
 * @brief Install @ref MakeDefaultLogger at @p level.
 */
void UseDefaultLogger(LogLevel level = LogLevel::Info);

/**
 * @return The active logger (creates a default at Warn if none was set).
 *
 * Never returns nullptr when spdlog is enabled.
 */
[[nodiscard]] LoggerPtr GetLogger();

/**
 * @brief Set the level on the active logger (and default creation level).
 */
void SetLogLevel(LogLevel level);

/**
 * @return Current level of the active logger.
 */
[[nodiscard]] LogLevel GetLogLevel();

/**
 * @brief Map mog::LogLevel to spdlog.
 */
[[nodiscard]] spdlog::level::level_enum ToSpdlogLevel(LogLevel level) noexcept;

/**
 * @brief Map spdlog level to mog::LogLevel.
 */
[[nodiscard]] LogLevel FromSpdlogLevel(spdlog::level::level_enum level) noexcept;

#else // !MOG_HAS_SPDLOG

// Stubs so headers compile without spdlog; all logging is a no-op.
struct Logger
{
};
using LoggerPtr = std::shared_ptr<Logger>;

[[nodiscard]] inline LoggerPtr MakeDefaultLogger(LogLevel = LogLevel::Info)
{
    return nullptr;
}
inline void SetLogger(LoggerPtr)
{
}
inline void UseDefaultLogger(LogLevel = LogLevel::Info)
{
}
[[nodiscard]] inline LoggerPtr GetLogger()
{
    return nullptr;
}
inline void SetLogLevel(LogLevel)
{
}
[[nodiscard]] inline LogLevel GetLogLevel()
{
    return LogLevel::Off;
}

#endif

} // namespace mog

// ---------------------------------------------------------------------------
// Internal / library log macros (safe no-ops without spdlog)
// ---------------------------------------------------------------------------

#if defined(MOG_HAS_SPDLOG) && MOG_HAS_SPDLOG
#define MOG_LOG_TRACE(...) ::mog::GetLogger()->trace(__VA_ARGS__)
#define MOG_LOG_DEBUG(...) ::mog::GetLogger()->debug(__VA_ARGS__)
#define MOG_LOG_INFO(...) ::mog::GetLogger()->info(__VA_ARGS__)
#define MOG_LOG_WARN(...) ::mog::GetLogger()->warn(__VA_ARGS__)
#define MOG_LOG_ERROR(...) ::mog::GetLogger()->error(__VA_ARGS__)
#define MOG_LOG_CRITICAL(...) ::mog::GetLogger()->critical(__VA_ARGS__)
#else
#define MOG_LOG_TRACE(...) ((void)0)
#define MOG_LOG_DEBUG(...) ((void)0)
#define MOG_LOG_INFO(...) ((void)0)
#define MOG_LOG_WARN(...) ((void)0)
#define MOG_LOG_ERROR(...) ((void)0)
#define MOG_LOG_CRITICAL(...) ((void)0)
#endif
