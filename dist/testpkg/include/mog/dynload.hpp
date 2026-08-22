/**
 * @file dynload.hpp
 * @brief Portable runtime shared-library loading (dlopen / LoadLibrary).
 *
 * Platform-specific OS APIs used by mog (e.g. Windows CryptoAPI for the system
 * CA store, future curl/WinHTTP backends) are resolved at runtime through this
 * facade so the static binary does not hard-link optional system libraries.
 */
#pragma once

#include "mog/error.hpp"

#include <string>
#include <string_view>
#include <type_traits>
#include <utility>

namespace mog
{

/**
 * @brief Open flags for @ref SharedLibrary::Open (mapped to platform equivalents).
 */
enum class SharedLibraryMode
{
    /// Resolve symbols lazily where the platform supports it (default).
    Lazy,
    /// Resolve all symbols at open time where supported.
    Now,
};

/**
 * @brief RAII handle for a dynamically loaded shared library.
 *
 * Thread-safety: a single instance is not safe for concurrent Open/Close/Lookup
 * without external synchronization. Distinct instances may be used concurrently.
 */
class SharedLibrary
{
  public:
    SharedLibrary() = default;
    ~SharedLibrary();

    SharedLibrary(const SharedLibrary &) = delete;
    SharedLibrary &operator=(const SharedLibrary &) = delete;

    SharedLibrary(SharedLibrary &&other) noexcept;
    SharedLibrary &operator=(SharedLibrary &&other) noexcept;

    /**
     * @brief Load a shared library from @p path.
     * @param path Absolute or relative path, or a platform search name
     *        (e.g. "libcurl.so.4", "crypt32.dll").
     * @param mode Load-time resolution policy.
     * @return Ok on success; @c ErrorCode::DynamicLibraryError on failure.
     */
    [[nodiscard]] Result<void> Open(std::string_view path,
                                    SharedLibraryMode mode = SharedLibraryMode::Lazy);

    /**
     * @brief Unload the library if open. Safe to call when already closed.
     */
    void Close() noexcept;

    /**
     * @return True when a library is currently loaded.
     */
    [[nodiscard]] bool is_open() const noexcept
    {
        return handle_ != nullptr;
    }

    /**
     * @brief Path last successfully passed to @ref Open (empty if never opened).
     */
    [[nodiscard]] std::string_view path() const noexcept
    {
        return path_;
    }

    /**
     * @brief Resolve an exported symbol by name.
     * @return Function/data address, or DynamicLibraryError if missing/closed.
     */
    [[nodiscard]] Result<void *> Lookup(const char *symbol_name) const;

    /**
     * @brief Resolve @p symbol_name and cast to function/data pointer type @p T.
     * @tparam T Function pointer or object pointer type.
     */
    template <typename T> [[nodiscard]] Result<T> Symbol(const char *symbol_name) const
    {
        static_assert(std::is_pointer_v<T>, "Symbol<T> requires a pointer type");
        auto raw = Lookup(symbol_name);
        if (!raw)
        {
            return Result<T>::Err(raw.error());
        }
        return Result<T>::Ok(reinterpret_cast<T>(*raw));
    }

    /**
     * @brief Convenience: construct and Open in one step.
     */
    [[nodiscard]] static Result<SharedLibrary> Load(
        std::string_view path, SharedLibraryMode mode = SharedLibraryMode::Lazy);

  private:
    void *handle_ = nullptr;
    std::string path_;
};

/**
 * @brief Platform-default library file extension (".so", ".dylib", or ".dll").
 */
[[nodiscard]] std::string_view SharedLibraryExtension() noexcept;

} // namespace mog
