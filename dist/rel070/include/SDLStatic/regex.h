/**
 * @file regex.h
 * @brief Regular expressions, Ruby syntax, over vendored Oniguruma.
 *
 * Original SDLStatic code (zlib) wrapping Oniguruma (BSD-2, see
 * `deps/oniguruma.md`). Patterns use ONIG_SYNTAX_RUBY on UTF-8 text, so
 * everything a Ruby programmer expects works: named captures, lookaround,
 * non-greedy quantifiers, `\d`/`\w`/`\p{...}`.
 *
 * The API is deliberately small — compile, search, read the groups — for
 * two reasons. It crosses the Lua/Ruby binding boundary without callbacks
 * or ownership questions, and richer operations (scan, gsub, split) are
 * built on these primitives in each language, where they can return that
 * language's own types. In Ruby they arrive as a real `Regexp` class, so
 * `/(\d+)/` literals, `String#match`, `=~` and `$1` all work.
 *
 *     SDLStatic_Regex *re = SDLStatic_CompileRegex("(\\w+)@(\\w+)", "i");
 *     if (SDLStatic_RegexSearch(re, "mail bob@example now", 0)) {
 *         SDL_Log("%s", SDLStatic_RegexGroup(re, 1));   // bob
 *     }
 *     SDLStatic_DestroyRegex(re);
 *
 * A compiled pattern holds the most recent match, so it is a cursor as
 * well as a program: the group accessors always describe the last
 * successful search, and the strings they return stay valid until the next
 * search on that object or until it is destroyed. That makes iteration
 * cheap, and it makes a single `SDLStatic_Regex` unsafe to share between
 * threads mid-search.
 *
 * Byte offsets, not character indices: Oniguruma reports positions in the
 * subject's bytes, and UTF-8 characters are not all one byte wide. Feed
 * offsets straight back into SDLStatic_RegexSearch and they line up.
 */
#ifndef SDLSTATIC_REGEX_H
#define SDLSTATIC_REGEX_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

/** A compiled pattern together with its most recent match. */
typedef struct SDLStatic_Regex SDLStatic_Regex;

/** Compile a pattern.
 *
 *  \param pattern the expression, in Ruby syntax.
 *  \param flags any of "i" (case-insensitive), "m" (dot matches newline —
 *  Ruby's meaning of /m, not Perl's), "x" (extended: whitespace and #
 *  comments ignored). NULL or "" for none; unknown letters are an error.
 *  \returns a new pattern, or NULL with SDL_GetError() describing where the
 *  expression went wrong. Free it with SDLStatic_DestroyRegex. */
extern SDLStatic_Regex *SDLStatic_CompileRegex(const char *pattern, const char *flags);

/** Release a compiled pattern. Safe on NULL. */
extern void SDLStatic_DestroyRegex(SDLStatic_Regex *regex);

/** Search `text` from byte offset `start` for the first match.
 *
 *  Returns true when one is found, after which the group accessors
 *  describe it. Returns false when there is no match — which is not an
 *  error — and also on a genuine failure, which sets SDL_GetError(). */
extern bool SDLStatic_RegexSearch(SDLStatic_Regex *regex, const char *text, int start);

/** Match at exactly byte offset `start`, without searching forward.
 *
 *  This is what an anchored scan wants: `String#split` and `gsub` advance
 *  through a subject and need to know whether the pattern matches *here*. */
extern bool SDLStatic_RegexMatchAt(SDLStatic_Regex *regex, const char *text, int start);

/** How many capture groups the last match has, including group 0 (the
 *  whole match). Returns 0 when nothing has matched yet. */
extern int SDLStatic_RegexGroupCount(SDLStatic_Regex *regex);

/** The text of a capture group from the last match, or NULL when the group
 *  did not participate (or does not exist). Group 0 is the whole match.
 *  Valid until the next search on this pattern. */
extern const char *SDLStatic_RegexGroup(SDLStatic_Regex *regex, int group);

/** Byte offset where a group starts, or -1 if it did not participate. */
extern int SDLStatic_RegexGroupBegin(SDLStatic_Regex *regex, int group);

/** Byte offset one past the end of a group, or -1 if it did not
 *  participate. An empty match has begin == end, which is what a scanning
 *  loop must check to guarantee progress. */
extern int SDLStatic_RegexGroupEnd(SDLStatic_Regex *regex, int group);

/** The index of a named group — `(?<year>\d+)` — or -1 if there is no such
 *  name. Combine with SDLStatic_RegexGroup to read it. */
extern int SDLStatic_RegexNamedGroup(SDLStatic_Regex *regex, const char *name);

/** How many named groups the pattern declares. */
extern int SDLStatic_RegexNamedGroupCount(SDLStatic_Regex *regex);

/** The name of the nth named group (0-based, in declaration order), or
 *  NULL when out of range. Valid for the lifetime of the pattern. */
extern const char *SDLStatic_RegexNamedGroupName(SDLStatic_Regex *regex, int index);

/** The pattern text this was compiled from — Ruby's `Regexp#source`. */
extern const char *SDLStatic_RegexPattern(SDLStatic_Regex *regex);

/** The flag letters this was compiled with, "" when none. */
extern const char *SDLStatic_RegexFlags(SDLStatic_Regex *regex);

/** Replace matches in `text` with `replacement`, which may reference
 *  groups as `\\1`..`\\9` and the whole match as `\\0`; a literal
 *  backslash is `\\\\`.
 *
 *  \param all true to replace every match (Ruby's `gsub`), false for only
 *  the first (`sub`).
 *  \returns the result, owned by this pattern and valid until the next
 *  call on it, or NULL on failure. When nothing matches, the return value
 *  is a copy of `text` rather than NULL. */
extern const char *SDLStatic_RegexReplace(SDLStatic_Regex *regex, const char *text,
                                          const char *replacement, bool all);

/** Quote regex metacharacters in `text` so it matches literally — Ruby's
 *  `Regexp.escape`. Returns a string owned by SDL; free it with SDL_free. */
extern char *SDLStatic_RegexEscape(const char *text);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_REGEX_H */
