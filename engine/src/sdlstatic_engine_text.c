/*
 * sdlstatic_engine_text.c — string tables and the fallback chain.
 * Original SDLStatic code (zlib).
 *
 * A lookup tries the current language, then English, then the key itself.
 * Each step exists for a reason a game hits in practice:
 *
 *   Current language   the point of the exercise.
 *   English            a translation in progress has gaps by definition,
 *                      and an English button beats a blank one — a blank is
 *                      indistinguishable from a bug.
 *   The key            renders as "menu.start", which is ugly on purpose:
 *                      obvious in a screenshot, and it names the thing that
 *                      needs fixing.
 */
#include "engine_internal.h"

#include <SDLStatic/engine_text.h>
#include <SDLStatic/vfs.h>

#include <physfs.h>
#include <toml.h>

#include <stdarg.h>
#include <stdlib.h>

#define FALLBACK_LANGUAGE "en"
#define FORMAT_BUFFERS 8
#define FORMAT_LENGTH 512

typedef struct Entry
{
    char *key;
    char *value;
} Entry;

typedef struct Language
{
    char code[16];
    Entry *entries;
    int count, capacity;
} Language;

struct SDLStatic_Text
{
    Language *languages;
    int count, capacity;
    char current[16];

    /* A small rotating set, so several TextFormat calls may appear in one
       expression without the second overwriting the first. */
    char buffers[FORMAT_BUFFERS][FORMAT_LENGTH];
    int next_buffer;
};

static struct SDLStatic_Text *Text(SDLStatic_Engine *engine, bool create)
{
    if (engine == NULL)
    {
        return NULL;
    }
    if (engine->text == NULL && create)
    {
        struct SDLStatic_Text *text =
            (struct SDLStatic_Text *)SDL_calloc(1, sizeof(struct SDLStatic_Text));
        if (text != NULL)
        {
            SDL_strlcpy(text->current, FALLBACK_LANGUAGE, sizeof(text->current));
            engine->text = text;
        }
    }
    return engine->text;
}

static Language *FindLanguage(struct SDLStatic_Text *text, const char *code)
{
    if (text == NULL || code == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < text->count; ++i)
    {
        if (SDL_strcasecmp(text->languages[i].code, code) == 0)
        {
            return &text->languages[i];
        }
    }
    return NULL;
}

static Language *FindOrAddLanguage(struct SDLStatic_Text *text, const char *code)
{
    Language *language = FindLanguage(text, code);
    if (language != NULL)
    {
        return language;
    }
    if (text->count >= text->capacity)
    {
        const int next = (text->capacity > 0) ? text->capacity * 2 : 4;
        Language *grown = (Language *)SDL_realloc(text->languages,
                                                  (size_t)next * sizeof(Language));
        if (grown == NULL)
        {
            return NULL;
        }
        text->languages = grown;
        text->capacity = next;
    }
    language = &text->languages[text->count++];
    SDL_zerop(language);
    SDL_strlcpy(language->code, code, sizeof(language->code));
    return language;
}

/* Set a key, replacing any existing value — so loading a patch table over a
   base one does what it looks like it does. */
static bool SetEntry(Language *language, const char *key, const char *value)
{
    for (int i = 0; i < language->count; ++i)
    {
        if (SDL_strcmp(language->entries[i].key, key) == 0)
        {
            char *copy = SDL_strdup(value);
            if (copy == NULL)
            {
                return false;
            }
            SDL_free(language->entries[i].value);
            language->entries[i].value = copy;
            return true;
        }
    }
    if (language->count >= language->capacity)
    {
        const int next = (language->capacity > 0) ? language->capacity * 2 : 32;
        Entry *grown = (Entry *)SDL_realloc(language->entries, (size_t)next * sizeof(Entry));
        if (grown == NULL)
        {
            return false;
        }
        language->entries = grown;
        language->capacity = next;
    }
    Entry *entry = &language->entries[language->count];
    entry->key = SDL_strdup(key);
    entry->value = SDL_strdup(value);
    if (entry->key == NULL || entry->value == NULL)
    {
        SDL_free(entry->key);
        SDL_free(entry->value);
        return false;
    }
    language->count++;
    return true;
}

static const char *Lookup(const Language *language, const char *key)
{
    if (language == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < language->count; ++i)
    {
        if (SDL_strcmp(language->entries[i].key, key) == 0)
        {
            return language->entries[i].value;
        }
    }
    return NULL;
}

/* --- loading ------------------------------------------------------------- */

bool SDLStatic_TextLoad(SDLStatic_Engine *engine, const char *language_code, const char *toml)
{
    struct SDLStatic_Text *text = Text(engine, true);
    if (text == NULL || language_code == NULL || toml == NULL)
    {
        SDL_InvalidParamError("engine/language/toml");
        return false;
    }

    char *copy = SDL_strdup(toml);
    if (copy == NULL)
    {
        return false;
    }
    char error[256] = {0};
    toml_table_t *root = toml_parse(copy, error, (int)sizeof(error));
    SDL_free(copy);
    if (root == NULL)
    {
        SDL_SetError("%s strings: %s", language_code, error);
        return false;
    }

    /* [strings] if present, the document root if not — a flat file is a
       perfectly reasonable thing for a translator to hand back. */
    const toml_table_t *strings = toml_table_in(root, "strings");
    if (strings == NULL)
    {
        strings = root;
    }

    Language *language = FindOrAddLanguage(text, language_code);
    if (language == NULL)
    {
        toml_free(root);
        return false;
    }

    for (int i = 0;; ++i)
    {
        const char *key = toml_key_in(strings, i);
        if (key == NULL)
        {
            break;
        }
        toml_datum_t value = toml_string_in(strings, key);
        if (!value.ok)
        {
            continue; /* a table or a number: not a string, so not ours */
        }
        SetEntry(language, key, value.u.s);
        free(value.u.s);
    }

    toml_free(root);
    return true;
}

bool SDLStatic_TextLoadFile(SDLStatic_Engine *engine, const char *language_code)
{
    if (engine == NULL || language_code == NULL)
    {
        return false;
    }
    char path[128];
    SDL_snprintf(path, sizeof(path), "lang/%s.toml", language_code);

    /* The archive first, then the real filesystem, so a game run from a
       build directory before anything is packed still finds its strings.
       PhysFS must be checked rather than trusted: it crashes rather than
       failing when it has not been initialised. */
    char *data = NULL;
    if (PHYSFS_isInit())
    {
        int size = 0;
        data = (char *)SDLStatic_LoadVFSFile(path, &size);
    }
    if (data == NULL)
    {
        size_t size = 0;
        data = (char *)SDL_LoadFile(path, &size);
    }
    if (data == NULL)
    {
        return false; /* an absent optional language is not an error */
    }
    const bool ok = SDLStatic_TextLoad(engine, language_code, data);
    SDL_free(data);
    return ok;
}

void SDLStatic_TextSetLanguage(SDLStatic_Engine *engine, const char *language_code)
{
    struct SDLStatic_Text *text = Text(engine, true);
    if (text == NULL || language_code == NULL)
    {
        return;
    }
    /* Unknown languages are accepted: every lookup then falls back to
       English, which beats refusing to start over a settings string. */
    SDL_strlcpy(text->current, language_code, sizeof(text->current));
}

const char *SDLStatic_TextLanguage(SDLStatic_Engine *engine)
{
    struct SDLStatic_Text *text = Text(engine, false);
    return (text != NULL) ? text->current : FALLBACK_LANGUAGE;
}

int SDLStatic_TextSystemLanguages(char **out, int capacity)
{
    if (out == NULL || capacity <= 0)
    {
        return 0;
    }
    int count = 0;
    SDL_Locale **locales = SDL_GetPreferredLocales(&count);
    if (locales == NULL)
    {
        return 0;
    }
    int written = 0;
    for (int i = 0; i < count && written < capacity; ++i)
    {
        if (locales[i] == NULL || locales[i]->language == NULL)
        {
            continue;
        }
        out[written++] = SDL_strdup(locales[i]->language);
    }
    SDL_free(locales);
    return written;
}

/* --- lookup -------------------------------------------------------------- */

const char *SDLStatic_Text(SDLStatic_Engine *engine, const char *key)
{
    if (key == NULL)
    {
        return "";
    }
    struct SDLStatic_Text *text = Text(engine, false);
    if (text == NULL)
    {
        return key;
    }

    const char *value = Lookup(FindLanguage(text, text->current), key);
    if (value == NULL)
    {
        /* A translation in progress has gaps by definition, and an English
           button beats a blank one. */
        value = Lookup(FindLanguage(text, FALLBACK_LANGUAGE), key);
    }
    /* Still nothing: the key, which is ugly on purpose — obvious in a
       screenshot, and it names what needs fixing. */
    return (value != NULL) ? value : key;
}

bool SDLStatic_TextHas(SDLStatic_Engine *engine, const char *key)
{
    struct SDLStatic_Text *text = Text(engine, false);
    if (text == NULL || key == NULL)
    {
        return false;
    }
    return Lookup(FindLanguage(text, text->current), key) != NULL;
}

const char *SDLStatic_TextFormat(SDLStatic_Engine *engine, const char *key, ...)
{
    struct SDLStatic_Text *text = Text(engine, true);
    const char *format = SDLStatic_Text(engine, key);
    if (text == NULL)
    {
        return format;
    }

    char *buffer = text->buffers[text->next_buffer];
    text->next_buffer = (text->next_buffer + 1) % FORMAT_BUFFERS;

    va_list args;
    va_start(args, key);
    SDL_vsnprintf(buffer, FORMAT_LENGTH, format, args);
    va_end(args);
    return buffer;
}

int SDLStatic_TextCount(SDLStatic_Engine *engine, const char *language_code)
{
    struct SDLStatic_Text *text = Text(engine, false);
    if (text == NULL)
    {
        return 0;
    }
    const Language *language =
        FindLanguage(text, (language_code != NULL) ? language_code : text->current);
    return (language != NULL) ? language->count : 0;
}

void SDLStatic_EngineTextDestroy(SDLStatic_Engine *engine)
{
    struct SDLStatic_Text *text = Text(engine, false);
    if (text == NULL)
    {
        return;
    }
    for (int i = 0; i < text->count; ++i)
    {
        Language *language = &text->languages[i];
        for (int e = 0; e < language->count; ++e)
        {
            SDL_free(language->entries[e].key);
            SDL_free(language->entries[e].value);
        }
        SDL_free(language->entries);
    }
    SDL_free(text->languages);
    SDL_free(text);
    engine->text = NULL;
}
