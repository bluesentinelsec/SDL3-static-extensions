/*
 * sdlstatic_regex.c — SDLStatic_Regex over Oniguruma.
 * Original SDLStatic code (zlib). See SDLStatic/regex.h.
 *
 * Oniguruma works in (start, end) byte pointers into the subject and
 * reports groups the same way, so the wrapper keeps a copy of the subject
 * alongside the region: the group accessors can then hand out NUL-
 * terminated strings, which is what every binding needs and what C callers
 * expect from a *_Group function.
 */
#include <SDLStatic/regex.h>

#include <oniguruma.h>

struct SDLStatic_Regex
{
    regex_t *prog;
    OnigRegion *region;
    char *pattern;      /* Regexp#source */
    char *flags;        /* the letters as given, normalised to "" if none */
    char *subject;      /* copy of the last searched text */
    char **groups;      /* lazily built NUL-terminated group texts */
    int group_capacity; /* how many slots `groups` has */
    char **names;       /* named groups, in declaration order */
    int name_count;
    bool matched;
    char *replaced; /* the last SDLStatic_RegexReplace result */
};

/* Oniguruma's one-time init is not thread-safe, so do it under SDL's
 * init-once rather than lazily per compile. */
static SDL_AtomicInt g_onig_ready;

static bool EnsureOnigInit(void)
{
    if (SDL_GetAtomicInt(&g_onig_ready) != 0)
    {
        return true;
    }
    OnigEncoding encodings[] = {ONIG_ENCODING_UTF8};
    if (onig_initialize(encodings, 1) != ONIG_NORMAL)
    {
        SDL_SetError("could not initialise the regex engine");
        return false;
    }
    SDL_SetAtomicInt(&g_onig_ready, 1);
    return true;
}

/* Oniguruma reports failures as codes plus an optional error info block;
 * turn both into an SDL error so callers only ever read SDL_GetError. */
static void SetOnigError(int code, OnigErrorInfo *info)
{
    char message[ONIG_MAX_ERROR_MESSAGE_LEN];
    const int n = (info != NULL) ? onig_error_code_to_str((UChar *)message, code, info)
                                 : onig_error_code_to_str((UChar *)message, code);
    message[(n > 0 && n < (int)sizeof(message)) ? n : 0] = '\0';
    SDL_SetError("regex: %s", message);
}

static bool ParseFlags(const char *flags, OnigOptionType *out)
{
    OnigOptionType options = ONIG_OPTION_NONE;
    for (const char *c = (flags != NULL) ? flags : ""; *c != '\0'; c++)
    {
        switch (*c)
        {
        case 'i':
            options |= ONIG_OPTION_IGNORECASE;
            break;
        case 'm':
            /* Ruby's /m is "dot matches newline", which Oniguruma (like
               Perl) calls MULTILINE; Ruby's ^ and $ are always per-line. */
            options |= ONIG_OPTION_MULTILINE;
            break;
        case 'x':
            options |= ONIG_OPTION_EXTEND;
            break;
        default:
            SDL_SetError("regex: unknown flag '%c' (expected i, m or x)", *c);
            return false;
        }
    }
    *out = options;
    return true;
}

/* Drop everything derived from the previous subject. */
static void ClearMatch(SDLStatic_Regex *regex)
{
    for (int i = 0; i < regex->group_capacity; i++)
    {
        SDL_free(regex->groups[i]);
        regex->groups[i] = NULL;
    }
    SDL_free(regex->subject);
    regex->subject = NULL;
    regex->matched = false;
}

SDLStatic_Regex *SDLStatic_CompileRegex(const char *pattern, const char *flags)
{
    if (pattern == NULL)
    {
        SDL_InvalidParamError("pattern");
        return NULL;
    }
    if (!EnsureOnigInit())
    {
        return NULL;
    }
    OnigOptionType options = ONIG_OPTION_NONE;
    if (!ParseFlags(flags, &options))
    {
        return NULL;
    }

    SDLStatic_Regex *regex = (SDLStatic_Regex *)SDL_calloc(1, sizeof(*regex));
    if (regex == NULL)
    {
        return NULL;
    }

    const UChar *start = (const UChar *)pattern;
    const UChar *end = start + SDL_strlen(pattern);
    OnigErrorInfo info;
    const int status = onig_new(&regex->prog, start, end, options, ONIG_ENCODING_UTF8,
                                ONIG_SYNTAX_RUBY, &info);
    if (status != ONIG_NORMAL)
    {
        SetOnigError(status, &info);
        SDL_free(regex);
        return NULL;
    }

    regex->region = onig_region_new();
    regex->pattern = SDL_strdup(pattern);
    regex->flags = SDL_strdup((flags != NULL) ? flags : "");
    if (regex->region == NULL || regex->pattern == NULL || regex->flags == NULL)
    {
        SDLStatic_DestroyRegex(regex);
        return NULL;
    }
    return regex;
}

void SDLStatic_DestroyRegex(SDLStatic_Regex *regex)
{
    if (regex == NULL)
    {
        return;
    }
    ClearMatch(regex);
    SDL_free(regex->groups);
    for (int i = 0; i < regex->name_count; i++)
    {
        SDL_free(regex->names[i]);
    }
    SDL_free(regex->names);
    if (regex->region != NULL)
    {
        onig_region_free(regex->region, 1);
    }
    if (regex->prog != NULL)
    {
        onig_free(regex->prog);
    }
    SDL_free(regex->pattern);
    SDL_free(regex->flags);
    SDL_free(regex->replaced);
    SDL_free(regex);
}

/* Shared by search and match-at: the two differ only in which Oniguruma
 * entry point they call. */
static bool RunMatch(SDLStatic_Regex *regex, const char *text, int start, bool anchored)
{
    if (regex == NULL || text == NULL)
    {
        SDL_InvalidParamError("regex/text");
        return false;
    }
    const size_t length = SDL_strlen(text);
    if (start < 0 || (size_t)start > length)
    {
        SDL_SetError("regex: start offset %d is outside a %zu-byte subject", start, length);
        return false;
    }

    char *copy = SDL_strdup(text);
    if (copy == NULL)
    {
        return false;
    }
    ClearMatch(regex);

    const UChar *begin = (const UChar *)copy;
    const UChar *end = begin + length;
    const UChar *at = begin + start;
    const int position = anchored
                             ? onig_match(regex->prog, begin, end, at, regex->region,
                                          ONIG_OPTION_NONE)
                             : onig_search(regex->prog, begin, end, at, end, regex->region,
                                           ONIG_OPTION_NONE);
    if (position == ONIG_MISMATCH)
    {
        SDL_free(copy);
        return false; /* no match is an ordinary answer, not an error */
    }
    if (position < 0)
    {
        SetOnigError(position, NULL);
        SDL_free(copy);
        return false;
    }

    /* Grow the group cache to fit this pattern; it is reused thereafter. */
    const int count = regex->region->num_regs;
    if (count > regex->group_capacity)
    {
        char **grown = (char **)SDL_realloc(regex->groups, (size_t)count * sizeof(char *));
        if (grown == NULL)
        {
            SDL_free(copy);
            return false;
        }
        for (int i = regex->group_capacity; i < count; i++)
        {
            grown[i] = NULL;
        }
        regex->groups = grown;
        regex->group_capacity = count;
    }

    regex->subject = copy;
    regex->matched = true;
    return true;
}

bool SDLStatic_RegexSearch(SDLStatic_Regex *regex, const char *text, int start)
{
    return RunMatch(regex, text, start, false);
}

bool SDLStatic_RegexMatchAt(SDLStatic_Regex *regex, const char *text, int start)
{
    return RunMatch(regex, text, start, true);
}

int SDLStatic_RegexGroupCount(SDLStatic_Regex *regex)
{
    if (regex == NULL || !regex->matched)
    {
        return 0;
    }
    return regex->region->num_regs;
}

/* Groups that did not participate carry a begin of -1. */
static bool GroupRange(SDLStatic_Regex *regex, int group, int *begin, int *end)
{
    if (regex == NULL || !regex->matched || group < 0 || group >= regex->region->num_regs)
    {
        return false;
    }
    const int from = regex->region->beg[group];
    const int to = regex->region->end[group];
    if (from < 0 || to < 0)
    {
        return false;
    }
    *begin = from;
    *end = to;
    return true;
}

const char *SDLStatic_RegexGroup(SDLStatic_Regex *regex, int group)
{
    int begin = 0, end = 0;
    if (!GroupRange(regex, group, &begin, &end))
    {
        return NULL;
    }
    if (regex->groups[group] == NULL)
    {
        const size_t size = (size_t)(end - begin);
        char *text = (char *)SDL_malloc(size + 1);
        if (text == NULL)
        {
            return NULL;
        }
        SDL_memcpy(text, regex->subject + begin, size);
        text[size] = '\0';
        regex->groups[group] = text;
    }
    return regex->groups[group];
}

int SDLStatic_RegexGroupBegin(SDLStatic_Regex *regex, int group)
{
    int begin = 0, end = 0;
    return GroupRange(regex, group, &begin, &end) ? begin : -1;
}

int SDLStatic_RegexGroupEnd(SDLStatic_Regex *regex, int group)
{
    int begin = 0, end = 0;
    return GroupRange(regex, group, &begin, &end) ? end : -1;
}

int SDLStatic_RegexNamedGroup(SDLStatic_Regex *regex, const char *name)
{
    if (regex == NULL || name == NULL)
    {
        return -1;
    }
    const UChar *start = (const UChar *)name;
    int *numbers = NULL;
    const int count = onig_name_to_group_numbers(regex->prog, start,
                                                 start + SDL_strlen(name), &numbers);
    if (count < 1 || numbers == NULL)
    {
        return -1;
    }
    /* A name may be reused across alternatives; the last one that matched
       is the useful answer, mirroring Ruby. */
    if (regex->matched)
    {
        for (int i = count - 1; i >= 0; i--)
        {
            if (numbers[i] < regex->region->num_regs && regex->region->beg[numbers[i]] >= 0)
            {
                return numbers[i];
            }
        }
    }
    return numbers[0];
}

/* onig_foreach_name visits the name table in its own hash order, which is
 * neither declaration order nor group order and differs between patterns.
 * Collect (group number, name) pairs and sort by group number so callers
 * see the names in the order they appear in the expression. The strings are
 * copied because the table's storage belongs to the engine. */
typedef struct NameEntry
{
    int group;
    char *name;
} NameEntry;

typedef struct NameWalk
{
    NameEntry *entries;
    int count;
    bool failed;
} NameWalk;

static int OnNameEntry(const UChar *name, const UChar *name_end, int groups, int *numbers,
                       regex_t *prog, void *arg)
{
    (void)prog;
    NameWalk *walk = (NameWalk *)arg;
    if (walk->failed || groups < 1)
    {
        return 0;
    }
    const size_t size = (size_t)(name_end - name);
    char *copy = (char *)SDL_malloc(size + 1);
    if (copy == NULL)
    {
        walk->failed = true;
        return 0;
    }
    SDL_memcpy(copy, name, size);
    copy[size] = '\0';
    walk->entries[walk->count].group = numbers[0];
    walk->entries[walk->count].name = copy;
    walk->count++;
    return 0;
}

static int CompareNameEntries(const void *a, const void *b)
{
    const int left = ((const NameEntry *)a)->group;
    const int right = ((const NameEntry *)b)->group;
    return (left > right) - (left < right);
}

/* Build the sorted name list once per pattern. */
static bool EnsureNames(SDLStatic_Regex *regex)
{
    if (regex->names != NULL)
    {
        return true;
    }
    const int count = onig_number_of_names(regex->prog);
    if (count < 1)
    {
        return false;
    }
    NameWalk walk = {NULL, 0, false};
    walk.entries = (NameEntry *)SDL_calloc((size_t)count, sizeof(NameEntry));
    if (walk.entries == NULL)
    {
        return false;
    }
    onig_foreach_name(regex->prog, OnNameEntry, &walk);
    if (walk.failed)
    {
        for (int i = 0; i < walk.count; i++)
        {
            SDL_free(walk.entries[i].name);
        }
        SDL_free(walk.entries);
        return false;
    }
    SDL_qsort(walk.entries, (size_t)walk.count, sizeof(NameEntry), CompareNameEntries);

    char **names = (char **)SDL_calloc((size_t)walk.count, sizeof(char *));
    if (names == NULL)
    {
        for (int i = 0; i < walk.count; i++)
        {
            SDL_free(walk.entries[i].name);
        }
        SDL_free(walk.entries);
        return false;
    }
    for (int i = 0; i < walk.count; i++)
    {
        names[i] = walk.entries[i].name;
    }
    SDL_free(walk.entries);
    regex->names = names;
    regex->name_count = walk.count;
    return true;
}

int SDLStatic_RegexNamedGroupCount(SDLStatic_Regex *regex)
{
    if (regex == NULL)
    {
        return 0;
    }
    return onig_number_of_names(regex->prog);
}

const char *SDLStatic_RegexNamedGroupName(SDLStatic_Regex *regex, int index)
{
    if (regex == NULL || index < 0 || !EnsureNames(regex) || index >= regex->name_count)
    {
        return NULL;
    }
    return regex->names[index];
}

const char *SDLStatic_RegexPattern(SDLStatic_Regex *regex)
{
    return (regex != NULL) ? regex->pattern : NULL;
}

const char *SDLStatic_RegexFlags(SDLStatic_Regex *regex)
{
    return (regex != NULL) ? regex->flags : NULL;
}

/* A grow-on-demand byte buffer, so replacement handles any output size
 * without a second pass to measure it. */
typedef struct Builder
{
    char *data;
    size_t length;
    size_t capacity;
    bool failed;
} Builder;

static void Append(Builder *out, const char *text, size_t size)
{
    if (out->failed || size == 0)
    {
        return;
    }
    if (out->length + size + 1 > out->capacity)
    {
        size_t capacity = (out->capacity != 0) ? out->capacity : 64;
        while (capacity < out->length + size + 1)
        {
            capacity *= 2;
        }
        char *grown = (char *)SDL_realloc(out->data, capacity);
        if (grown == NULL)
        {
            out->failed = true;
            return;
        }
        out->data = grown;
        out->capacity = capacity;
    }
    SDL_memcpy(out->data + out->length, text, size);
    out->length += size;
    out->data[out->length] = '\0';
}

/* Expand \0..\9 against the current match, passing other escapes through. */
static void AppendReplacement(Builder *out, SDLStatic_Regex *regex, const char *replacement)
{
    for (const char *c = replacement; *c != '\0'; c++)
    {
        if (*c != '\\')
        {
            Append(out, c, 1);
            continue;
        }
        const char next = *(c + 1);
        if (next >= '0' && next <= '9')
        {
            const int group = next - '0';
            int begin = 0, end = 0;
            if (GroupRange(regex, group, &begin, &end))
            {
                Append(out, regex->subject + begin, (size_t)(end - begin));
            }
            c++;
        }
        else if (next == '\\')
        {
            Append(out, "\\", 1);
            c++;
        }
        else if (next == '\0')
        {
            Append(out, "\\", 1);
        }
        else
        {
            Append(out, c, 2);
            c++;
        }
    }
}

const char *SDLStatic_RegexReplace(SDLStatic_Regex *regex, const char *text,
                                   const char *replacement, bool all)
{
    if (regex == NULL || text == NULL || replacement == NULL)
    {
        SDL_InvalidParamError("regex/text/replacement");
        return NULL;
    }
    const int length = (int)SDL_strlen(text);
    Builder out = {NULL, 0, 0, false};
    int position = 0;

    while (position <= length)
    {
        if (!SDLStatic_RegexSearch(regex, text, position))
        {
            break;
        }
        const int begin = regex->region->beg[0];
        const int end = regex->region->end[0];
        Append(&out, text + position, (size_t)(begin - position));
        AppendReplacement(&out, regex, replacement);

        /* An empty match would spin forever: emit one byte and step past
           it, which is what Ruby's gsub does. */
        if (end == begin)
        {
            if (begin < length)
            {
                Append(&out, text + begin, 1);
            }
            position = begin + 1;
        }
        else
        {
            position = end;
        }
        if (!all)
        {
            break;
        }
    }
    if (position <= length)
    {
        Append(&out, text + position, (size_t)(length - position));
    }
    if (out.failed)
    {
        SDL_free(out.data);
        return NULL;
    }
    if (out.data == NULL)
    {
        out.data = SDL_strdup(""); /* an empty subject replaced to nothing */
        if (out.data == NULL)
        {
            return NULL;
        }
    }
    SDL_free(regex->replaced);
    regex->replaced = out.data;
    return regex->replaced;
}

char *SDLStatic_RegexEscape(const char *text)
{
    if (text == NULL)
    {
        SDL_InvalidParamError("text");
        return NULL;
    }
    /* Worst case every byte is a metacharacter needing a backslash. */
    const size_t length = SDL_strlen(text);
    char *out = (char *)SDL_malloc(length * 2 + 1);
    if (out == NULL)
    {
        return NULL;
    }
    size_t written = 0;
    for (size_t i = 0; i < length; i++)
    {
        const char c = text[i];
        if (SDL_strchr("[]{}()|-*.\\?+^$# \t\f\v\n\r", c) != NULL)
        {
            out[written++] = '\\';
        }
        out[written++] = c;
    }
    out[written] = '\0';
    return out;
}
