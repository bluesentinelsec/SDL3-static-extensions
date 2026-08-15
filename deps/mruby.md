# mruby (vendored under `mruby/`)
| | |
|--|--|
| Upstream | https://github.com/mruby/mruby |
| Version | 4.0.0 | License | MIT (mruby/LICENSE) |
| Imported | 2026-08-15 via scripts/harvest_mruby.py (option "b") |

mruby's build needs host Ruby + rake to GENERATE code (presym tables,
mrblib/gem bytecode, gem inits; the bison parser ships pre-generated in the
release tarball). We ran that once (scripts/mruby_build_config.rb pins the
28-gem set incl. mruby-compiler for runtime .rb loading; no IO/socket/HAL
gems) and committed the generated output — all portable C (RITE bytecode is
byte-oriented), so plain CMake builds it on every platform with no Ruby.

Original glue (`<SDLStatic/ruby.h>`): Kernel#require/#require_relative/#load
(mruby has none) with $LOAD_PATH + $LOADED_FEATURES dedup, circular-require
guard, .rb (runtime compile) + .mrb (bytecode) resolution, VFS-first file
access; Kernel#puts/print/p without the IO gem. No modifications to
vendored/generated code. Gotcha: PhysFS rejects "./"-prefixed paths — a "."
load path resolves to bare names.

No regex engine: mruby has none, and none of its core gems provides one, so
`Regexp` does not exist in a stock build. Rather than adopt a gem — which
would force a re-harvest through rake — the class is supplied by
`bindings/src/sdlstatic_regexp_ruby.c` over `SDLStatic::Regex`
(Oniguruma, see `oniguruma.md`). mruby's compiler already emits
`Regexp.compile` for `/re/` literals and global reads for `$1`/`$~`, so
defining the class is enough; nothing vendored here is patched.

