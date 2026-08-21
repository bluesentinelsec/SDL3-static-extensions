/**
 * @file engine_text.h
 * @brief Localisation: string tables, with English as the fallback.
 *
 * Original SDLStatic code (zlib).
 *
 * Game code asks for a key and gets a string in whatever language is
 * current:
 *
 *     DrawText(SDLStatic_Text(engine, "menu.start"));
 *     DrawText(SDLStatic_TextFormat(engine, "hud.score", score));
 *
 * with the tables shipped as TOML in the media archive:
 *
 *     # media/lang/fr.toml
 *     [strings]
 *     "menu.start" = "Commencer"
 *     "hud.score" = "Score : %d"
 *
 * ### A missing translation falls back rather than disappearing
 *
 * If a key is absent from the current language, the engine returns the
 * **English** string; if it is absent from that too, it returns the **key
 * itself**. Both are deliberate.
 *
 * A game shipping a half-finished translation should show English for the
 * gaps, not blanks — a blank button is indistinguishable from a bug, and
 * translators work from partial files by definition. And a key with no
 * entry anywhere renders as `menu.start`, which is ugly on purpose: it is
 * immediately obvious in a screenshot, and it names the thing that needs
 * fixing.
 *
 * ### Keys, not English text, are the identifiers
 *
 * The alternative — keying off the English string — means every typo fix in
 * English silently breaks every translation. Keys cost a little readability
 * at the call site and buy the ability to edit English freely.
 */
#ifndef SDLSTATIC_ENGINE_TEXT_H
#define SDLSTATIC_ENGINE_TEXT_H

#include <SDLStatic/engine.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Load a language's strings from TOML.
 *
 * `language` is a code the game chooses — "en", "fr", "pt-BR"; the engine
 * does not interpret it beyond matching what it was given. Loading the same
 * language twice merges, with later keys winning, so a game can ship a base
 * table and patch it.
 *
 * Returns false on a parse error, leaving whatever was already loaded.
 */
extern bool SDLStatic_TextLoad(SDLStatic_Engine *engine, const char *language,
                               const char *toml);

/** Load `lang/<language>.toml` from the mounted media archive. Returns
 *  false if it is not there, which is not an error for an optional
 *  language. */
extern bool SDLStatic_TextLoadFile(SDLStatic_Engine *engine, const char *language);

/** Choose the language. Unknown languages are accepted — every lookup then
 *  falls back to English, which is better than refusing to start. */
extern void SDLStatic_TextSetLanguage(SDLStatic_Engine *engine, const char *language);
extern const char *SDLStatic_TextLanguage(SDLStatic_Engine *engine);

/** The player's preferred languages, from the operating system, best
 *  first. A game normally offers this as the default and lets the player
 *  override it. Returns how many were written. */
extern int SDLStatic_TextSystemLanguages(char **out, int capacity);

/** Look up a key. Never NULL: falls back to English, then to the key. */
extern const char *SDLStatic_Text(SDLStatic_Engine *engine, const char *key);

/** Is there a real translation for this key in the current language? For a
 *  tool that reports coverage, not for gameplay. */
extern bool SDLStatic_TextHas(SDLStatic_Engine *engine, const char *key);

/**
 * Look up a key and format it.
 *
 * The looked-up string is the format, so a translator controls where the
 * numbers go — which matters, because word order is not the same in every
 * language and a translation that cannot move its own placeholders is not
 * really a translation.
 *
 * The result lives in a small rotating set of buffers owned by the engine,
 * so several calls may be used in one expression; copy it if you need it
 * past the next few calls.
 */
extern const char *SDLStatic_TextFormat(SDLStatic_Engine *engine, const char *key, ...);

/** How many keys the current language has, and their names — for a
 *  coverage report. */
extern int SDLStatic_TextCount(SDLStatic_Engine *engine, const char *language);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_ENGINE_TEXT_H */
