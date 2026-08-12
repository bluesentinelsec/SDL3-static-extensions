# AGENTS.md — working in `SDL3-static-extensions`

This file orients **human contributors and coding agents** to how this
cppboot-generated C++ project is structured and how code should be written.
For day-to-day build commands, see [README.md](README.md).

## Project model

- **Entrypoint:** the program starts in **`src/main.cpp`** — always. No alternate
  app tree; do not invent a second `main`.
- **Library first:** reusable code belongs in the library target under
  `src/<component>/`, not in `main.cpp`.
- **Main is thin:** `src/main.cpp` only wires startup and calls into the library.
- **Components:** group related code under `src/<component>/`, `tests/<component>/`,
  and `benchmarks/<component>/`.
- **Explicit sources:** every translation unit is listed in that directory's
  `CMakeLists.txt`. Never use `file(GLOB)` for project sources.
- **Onboard a component:** add the directory, list files in its `CMakeLists.txt`,
  then `add_subdirectory(...)` from the parent.

Public headers live under `include/SDL3_static_extensions/` (directory tree matches the C++ namespace).

## Preferred libraries

Use these **default** third-party libraries (FetchContent, ON unless turned off
in CMake) instead of inventing a parallel stack:

| Need | Prefer | Notes |
|------|--------|--------|
| Parse CLI args | **CLI11** (`CLI11::CLI11`) | `#include <CLI/CLI.hpp>` |
| Parse / emit JSON | **nlohmann/json** (`nlohmann_json::nlohmann_json`) | `#include <nlohmann/json.hpp>` |
| Console (and file) logging | **spdlog** (`spdlog::spdlog`) | `#include <spdlog/spdlog.h>` |

They are linked `PUBLIC` on the project library when enabled. Options:

- `SDL3_STATIC_EXTENSIONS_WITH_CLI11` (default ON)
- `SDL3_STATIC_EXTENSIONS_WITH_JSON` (default ON)
- `SDL3_STATIC_EXTENSIONS_WITH_SPDLOG` (default ON)

Do not add competing CLI/JSON/logging libraries unless there is a clear,
documented reason. See `cmake/Dependencies.cmake` for pinned tags.

## Tooling workflow

Prefer the Makefile (Unix) or `build.bat` (Windows) wrappers:

| Goal | Unix | Windows |
|------|------|---------|
| Debug build | `make` / `make debug` | `build.bat` / `build.bat debug` |
| Release build | `make release` | `build.bat release` |
| Unit tests | `make test` | `build.bat test` |
| Benchmarks | `make bench` | `build.bat bench` |
| ASan+UBSan (Linux) | `make sanitizer` | n/a (use Linux/CI) |
| Format | `make fmt` | `build.bat fmt` |
| API docs | `make doc` | `build.bat doc` |
| ctags index | `make tags` (if enabled) | `build.bat tags` |
| Clean | `make clean` | `build.bat clean` |

- Builds are **out-of-source** under `build/`.
- After a Debug configure, `compile_commands.json` at the repo root supports clangd/LSP.
- **Warnings are errors.** Fix warnings; do not silence them without strong reason.
- If present, `.ctags` + `make tags` produce a repo-root `tags` file for editors
  (Universal Ctags recommended).
- If present, `.github/workflows/ci.yml` is the multi-OS CI contract (Debug +
  Release, tests, benchmarks on Linux/macOS/Windows). Keep it green.
- If present, `.github/workflows/sanitizers.yml` runs ASan+UBSan on Linux;
  treat sanitizer failures as bugs. Locally: `make sanitizer`.
- If present, `android/` is the Android Prefab AAR Gradle project (library
  module + on-device test app). `.github/workflows/android.yml` builds it and
  runs `scripts/run_android_tests.sh` on an emulator; keep it green. Android
  device tests live in `tests/android/`, not the GoogleTest tree.
- If present, `scripts/build_ios_xcframework.sh` packages the iOS XCFramework
  and `.github/workflows/ios.yml` builds + tests it in an iOS Simulator
  (`scripts/run_ios_tests.sh`); keep it green. iOS package tests live in
  `tests/ios/`, not the GoogleTest tree.
- If present, `src/web/` is the Emscripten canvas demo (game loop) and
  `tests/web/` the browser test page; `.github/workflows/web.yml` builds both
  and runs the tests in headless Chrome via `emrun`. Keep the game loop
  non-blocking — the browser owns frame pacing.
- **Version:** edit the root **`VERSION`** file only. CMake generates
  `SDL3_static_extensions::Version()` / CLI `--version` from `cmake/version.*.in`.
  Ship releases with annotated tags `vX.Y.Z` matching `VERSION` (or
  workflow_dispatch); the release job fails on mismatch.
- If present, `.devcontainer/` enables **GitHub Codespaces** / Dev Containers
  (browser or local VS Code in a C++ toolchain container).
- Default library API includes **`Version()`** (from `VERSION`) and the app
  exposes **`--version` / `-V`** via CLI11.
- Mechanical formatting is enforced by **clang-format** via the checked-in
  `.clang-format` (**Microsoft** style). Run `make fmt`.
- **Logic, naming, API design, and code organization** follow the
  **Google C++ Style Guide** (see Coding standards below). These are two
  separate concerns: Microsoft for whitespace/braces layout; Google for how
  the C++ is written.

## Coding standards

### Formatting vs. language style (two different layers)

| Layer | Standard | How it is applied |
|-------|----------|-------------------|
| **Formatting** | Microsoft (clang-format) | `.clang-format`, `make fmt` — indentation, braces, wrapping, spacing |
| **Language / design style** | [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) | Naming, headers, ownership, construct choices, readability norms |

Do not treat clang-format as a substitute for the Google guide, or vice versa.

### Style (Google C++ Style Guide)

Follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
for source code logic and structure:

- Clear, consistent naming (`PascalCase` types, Google-style functions/members;
  match existing code in this tree).
- Prefer headers that express a stable API; keep implementation details out of
  public headers when practical.
- Avoid non-portable extensions and clever syntax that hurts readability.
- Keep functions small and focused; prefer early returns over deep nesting.

### Design (SOLID, readability, maintainability)

Write code that a future human can change safely:

- **Single responsibility:** one class/function does one coherent job.
- **Open/closed:** extend behavior via new types or composition, not by growing
  god-objects or switch-on-type forests.
- **Liskov substitution:** derived types honor base contracts; do not surprise
  callers.
- **Interface segregation:** prefer small, purpose-built interfaces over wide ones.
- **Dependency inversion:** depend on abstractions at boundaries; inject
  collaborators rather than hard-wiring concrete types deep in call chains.

Additional habits:

- Optimize for **clarity over cleverness**. The default reader is a teammate,
  not a compiler.
- Prefer **composition** and explicit ownership (`std::unique_ptr`, values,
  spans) over hidden global state.
- Keep APIs **minimal and intentional**. Every public symbol is a long-term
  commitment.
- Fail loudly and locally: validate preconditions at boundaries; use types and
  names that make invalid states hard to represent.
- Tests are part of the product: add or update unit tests (and mocks where they
  clarify collaboration) when behavior changes.

### Documentation and comments

**Public symbols** (public headers / exported module interfaces, public classes,
functions, enums, and type aliases intended for use outside the defining
translation unit):

- Provide **professional Doxygen** documentation: brief description, parameters,
  return values, pre/postconditions, and ownership or lifetime notes when
  relevant.
- Use `/** ... */` with `@brief`, `@param`, `@return`, and related tags so
  `make doc` stays useful.
- Document *what* and *why* at the API boundary, not line-by-line mechanics.

**Internal code** (`.cpp` bodies, private helpers, anonymous namespaces, test
helpers):

- Favor **self-documenting** names and structure over commentary.
- Use comments **sparsely**.
- When you comment, write **long-lived** notes: invariants, non-obvious
  algorithms, protocol constraints, performance tradeoffs, or security
  boundaries that will still matter months later.
- Do **not** write tactical comments: no "increment i", no narrating the next
  line, no TODOs that only make sense during an unfinished edit, no
  change-log commentary that belongs in version control.

### Tests and benchmarks under warnings-as-errors

- Project flags apply to **your** TUs (lib, app, tests, benchmarks), not only
  production code.
- For `[[nodiscard]]` APIs with GoogleTest throws, bind the result:

  ```cpp
  EXPECT_THROW(
      {
        auto value = ApiThatIsNodiscard();
        static_cast<void>(value);
      },
      std::runtime_error);
  ```

- For Google Benchmark, pass a **mutable lvalue** to `DoNotOptimize` (const-ref
  overloads are deprecated and fail `-Werror`):

  ```cpp
  auto value = Compute();
  benchmark::DoNotOptimize(value);
  ```

### What to avoid

- Drive-by refactors unrelated to the task.
- Silent warning suppressions and `#pragma` noise without justification.
- New dependencies without a clear need (third-party code is pinned via
  FetchContent in `cmake/Dependencies.cmake`). Prefer the default CLI11 /
  nlohmann/json / spdlog stack for CLI, JSON, and logging.
- Alternate CLI/JSON/logging libraries when the preferred ones are enabled.
- Globs for source lists; dumping library logic into `src/main.cpp` or a single
  catch-all source file.

## Checklist before finishing a change

1. Sources listed explicitly in the right component `CMakeLists.txt`.
2. `make` (or `make release`) succeeds with warnings-as-errors.
3. `make test` passes; add coverage for new behavior.
4. Public API has Doxygen; internal comments (if any) are durable.
5. `make fmt` leaves formatting clean.
6. Logic/naming match Google C++ guidance; formatting matches `.clang-format`.

## Scope of this file

`AGENTS.md` is about **how to work in this repository**. Product requirements
and design docs for the application itself belong elsewhere.
