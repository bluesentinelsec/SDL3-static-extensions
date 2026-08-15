# Oniguruma (vendored under `regex/oniguruma/`)

| | |
|--|--|
| Upstream | https://github.com/kkos/oniguruma |
| Version | v6.9.10 (release tarball `onig-6.9.10.tar.gz`) |
| SHA-256 | `2a5cfc5ae259e4e97f86b68dfffc152cdaffe94e2060b770cb827238d769fc05` |
| License | BSD-2-Clause (see `regex/oniguruma/COPYING`) — commercial/closed-source safe; attribution required and provided by shipping the license text |
| Imported | 2026-08-14 |
| Dependencies | none — pure C, no libc extensions beyond the standard headers |

## What was taken

`src/*.c` and `src/*.h` plus `COPYING` and `AUTHORS`. The autotools and
CMake build systems, the test suite, the sample programs, the documentation
and the pre-baked Windows configs were not imported. `src/mktable.c` is a
table generator for maintainers, not part of the library, so it was left
behind as well.

Nothing was trimmed from the engine itself: every encoding, syntax and
Unicode table ships. A game that wants Shift-JIS or a POSIX-syntax pattern
has it available, and we avoid a per-release decision about which parts
someone might need.

## Build configuration

`regex/CMakeLists.txt` compiles the engine into `SDLStatic_Regex` and
generates `config.h` from upstream's own `config.h.cmake.in` using CMake's
`check_include_file` / `check_type_size` probes, which is what the autotools
`configure` would otherwise determine. Two deliberate choices:

- **`ONIG_EXTERN=extern`.** Upstream's default expands to a
  dllimport/visibility attribute for shared builds. The engine is compiled
  *into* our static archive, never a DLL, so the plain keyword is correct
  and keeps Windows builds from asking for an import library.
- **The compiled source list is upstream's `src/Makefile.am`, not a glob.**
  A glob would be wrong twice: the `unicode_*_data.c` tables are `#include`d
  by `unicode.c` rather than compiled on their own, and `regposix.c` defines
  `regcomp`/`regexec`, which would collide with libc's in a static link. The
  POSIX shim is therefore vendored but not built; `<onigposix.h>` is not part
  of our surface.

Oniguruma's own warnings are silenced with `-w` for its translation units
only. The wrapper is compiled with the project's normal warning settings.

## Why

mruby ships no regex engine — there is no `Regexp` in any stock mruby, and
none of its ~30 core gems provides one — while Lua has patterns rather than
regular expressions. Oniguruma is the engine CRuby itself uses, so
`SDLStatic::Regex` gives Ruby scripts the semantics they expect (named
captures, lookaround, `\p{...}`) instead of an approximation, and gives Lua
something it has never had. See [../docs/regex.md](../docs/regex.md).

Chosen over the alternatives on the static-first rule and on semantics:
PCRE2 would have meant either an external dependency or a second syntax to
explain; the small embedded engines (Henry Spencer's, TRE) are a fraction of
the size but lack named captures and lookaround, which would have made
`Regexp` Ruby-shaped without being Ruby-compatible. The `mruby-onig-regexp`
gem wraps the same engine, but adopting it would have forced a re-harvest of
mruby through its rake build; binding the C library directly avoids that
entirely and serves Lua and C++ at the same time.

## Cost

The Release archive is about 0.7 MB. A full web build of the REPL — both
interpreters and every module — grows from 5.65 MB to 6.12 MB of wasm,
1.92 MB to 2.06 MB gzipped: roughly 8% uncompressed, 7% over the wire.
`-DSDLSTATIC_BUILD_REGEX=OFF` removes it from C-only builds; the script
interpreters require it, because Ruby's `Regexp` is built on it.

## Local changes

None. The sources are upstream's, unmodified.
