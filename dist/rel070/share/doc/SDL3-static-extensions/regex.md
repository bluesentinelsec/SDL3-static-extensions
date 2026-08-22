---
title: Regex
description: "Real regular expressions in C, C++, Lua and Ruby — Ruby syntax, statically linked, via vendored Oniguruma."
---

# Regex — `SDLStatic::Regex`

Regular expressions with Ruby syntax and Ruby semantics, over vendored
[Oniguruma](https://github.com/kkos/oniguruma) (BSD-2, pure C, no external
dependencies — provenance in `deps/oniguruma.md`). It links statically
everywhere the rest of the project does, web included.

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Regex)
```

This module exists because the scripting languages could not do the job
alone. mruby ships **no regex engine at all** — `Regexp` does not exist in
any stock mruby — and Lua has *patterns*, which have no alternation, no
quantified groups and no lookaround. One C engine fixes both, and C and C++
get it too.

Patterns are compiled with `ONIG_SYNTAX_RUBY` against UTF-8 subjects, so
named captures, lookaround, non-greedy quantifiers and `\p{...}` classes all
behave the way a Ruby programmer expects.

## C — `<SDLStatic/regex.h>`

```c
SDLStatic_Regex *re = SDLStatic_CompileRegex("(\\w+)@(\\w+)", "i");
if (re == NULL) {
    SDL_Log("bad pattern: %s", SDL_GetError());
}
if (SDLStatic_RegexSearch(re, "mail bob@example now", 0)) {
    SDL_Log("%s at %d", SDLStatic_RegexGroup(re, 1),
            SDLStatic_RegexGroupBegin(re, 1));   /* bob at 5 */
}
SDLStatic_DestroyRegex(re);
```

A compiled pattern is also a **cursor**: it holds the most recent match, and
the group accessors always describe that match. The strings it returns stay
valid until the next search on the same object, which makes scanning cheap
but means one `SDLStatic_Regex` must not be shared between threads
mid-search. Compile once at load time and reuse — compiling is the expensive
part.

| Function | What it does |
|---|---|
| `SDLStatic_CompileRegex(pattern, flags)` | compile; `flags` is any of `i`, `m`, `x` |
| `SDLStatic_RegexSearch(re, text, start)` | first match at or after `start` |
| `SDLStatic_RegexMatchAt(re, text, start)` | anchored: does it match *here* |
| `SDLStatic_RegexGroupCount(re)` | groups in the last match, including group 0 |
| `SDLStatic_RegexGroup(re, n)` | group text, or NULL if it did not participate |
| `SDLStatic_RegexGroupBegin/End(re, n)` | byte offsets, or -1 |
| `SDLStatic_RegexNamedGroup(re, name)` | index of `(?<name>…)`, or -1 |
| `SDLStatic_RegexNamedGroupCount/Name(re, i)` | enumerate names, in declaration order |
| `SDLStatic_RegexReplace(re, text, repl, all)` | substitute, `\1`..`\9` for groups |
| `SDLStatic_RegexEscape(text)` | quote metacharacters; free with `SDL_free` |

Two things to keep in mind. `m` is *Ruby's* `/m` — dot matches newline — not
Perl's; Ruby's `^` and `$` are always per-line, so there is no flag for
that. And offsets are **byte** offsets, because UTF-8 characters are not all
one byte wide; feed them straight back into `SDLStatic_RegexSearch` and they
line up.

A failed search returns false without setting an error — no match is an
ordinary answer. A genuine failure (a bad offset, an allocation failure)
also returns false but sets `SDL_GetError()`.

## Ruby — the real `Regexp`

Scripts get the class Ruby programmers already know, so literals work:

```ruby
m = "on 2026-08-14".match(/(?<year>\d{4})-(?<mon>\d{2})/)
m[0]              # => "2026-08"
m["year"]         # => "2026"
$1                # => "2026"
$~.pre_match      # => "on "

"version: 42"[/(\d+)/, 1]          # => "42"
"a1b2".gsub(/\d/) { |d| d.to_i * 2 }  # => "a2b4"
"a1b22c".split(/\d+/)              # => ["a", "b", "c"]
"HELLO" =~ /hello/i                # => 0
case tag when /^ui_/ then ... end
```

This works because mruby's compiler already understands regex syntax even
though mruby has no engine: every `/pattern/flags` literal compiles into a
call to `Regexp.compile`, and `$1`/`$~` compile into ordinary global reads.
Supplying the class is all that was missing — **mruby itself is unpatched**.

Available: `Regexp.new` / `.compile` / `.escape` / `.quote` / `.union` /
`.last_match`, and `#match`, `#match?`, `#=~`, `#===`, `#source`,
`#options`, `#names`. `MatchData` supports `[]` (index or name), `begin`,
`end`, `captures`, `named_captures`, `names`, `pre_match`, `post_match`,
`to_a` and `size`. On `String`: `match`, `match?`, `=~`, `[]`/`slice`,
`index`, `scan`, `split`, `sub`, `gsub`, `sub!`, `gsub!`.

The `String` methods still take plain strings, exactly as before — they
delegate to mruby's own implementations when the argument is not a
`Regexp`, so nothing that worked before changes behaviour.

Not supported: `$&`, `` $` ``, `$'` and `$~` inside a `gsub` block (use the
matched text the block is given), encodings other than UTF-8, and
`Regexp#timeout`. A malformed pattern raises `RegexpError`.

## Lua — the `Regex` module

Lua keeps its own patterns untouched; this is an addition, not a
replacement, so `string.gsub("a1", "%d", "#")` behaves as always.

```lua
local re = Regex.new("(\\w+)@(\\w+)")      -- nil, err on a bad pattern
local m = re:match("mail bob@example now")
print(m[0], m[1], m.start, m.stop)          -- bob@example  bob  5  16

for m in Regex.new("\\d+"):gmatch("a1b22c333") do print(m[0]) end
Regex.new("\\s*,\\s*"):split("a , b,c")     -- {"a", "b", "c"}
re:gsub("bob@a", "\\2/\\1")                 -- "a/bob"
Regex.new("\\d+"):gsub("a1", function(m) return "<" .. m[0] .. ">" end)
Regex.new("(?<y>\\d{4})"):match("in 2026").named.y   -- "2026"
```

`Regex.new` returns `nil` plus the engine's message rather than raising, in
keeping with the rest of the Lua surface. Positions passed *in* are 1-based
like Lua's own string functions; the `start`/`stop` fields *inside* a match
are the engine's 0-based byte offsets, and can be handed back to `:match`
directly. Handles are garbage-collected.

Methods: `:match`, `:match_at`, `:gmatch`, `:gsub`, `:split`, `:test`,
`:source`, `:flags`; module functions `Regex.new`, `Regex.escape`,
`Regex.find`.

## C++

The generated RAII owner is `sdlstatic::gen::RegexHandle`:

```cpp
auto re = sdlstatic::gen::RegexHandle::CompileRegex("(\\w+)@(\\w+)", nullptr);
if (re) {
    if (re->RegexSearch("bob@example", 0)) { /* ... */ }
}
```

## Cost

The Release archive is about 0.7 MB. In a full web build of the REPL —
both interpreters, every module — the engine adds roughly 8% to the wasm
(5.65 → 6.12 MB, or 1.92 → 2.06 MB gzipped). `-DSDLSTATIC_BUILD_REGEX=OFF`
drops it from C-only builds; `SDLSTATIC_BUILD_LUA`/`_RUBY` require it,
because Ruby's `Regexp` is built on it.
