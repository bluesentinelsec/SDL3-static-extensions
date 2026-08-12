/**
 * @file main.cpp
 * @brief Program entrypoint (always src/main.cpp in cppboot projects).
 *
 * Keep this file thin: parse args / wire dependencies, then call library code.
 */

#include "SDL3_static_extensions/version.hpp"

#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

/**
 * @brief Program entry.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return Exit status.
 */
int main(int argc, char **argv)
{
    CLI::App app{"SDL3-static-extensions — cppboot project"};
    app.set_version_flag("-V,--version", std::string{SDL3_static_extensions::Version()});
    CLI11_PARSE(app, argc, argv);

    std::cout << "SDL3-static-extensions " << SDL3_static_extensions::Version()
              << " — add components under src/ (see README.md / AGENTS.md)\n";
    return 0;
}
