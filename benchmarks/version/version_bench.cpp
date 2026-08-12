/**
 * @file version_bench.cpp
 * @brief Microbenchmarks for SDL3_static_extensions::Version.
 */

#include "SDL3_static_extensions/version.hpp"

#include <benchmark/benchmark.h>
#include <string_view>

namespace
{

void BM_Version(benchmark::State &state)
{
    for (auto _ : state)
    {
        // Mutable lvalue required: const-ref DoNotOptimize is deprecated under -Werror.
        std::string_view version = SDL3_static_extensions::Version();
        benchmark::DoNotOptimize(version);
    }
}
BENCHMARK(BM_Version);

} // namespace
