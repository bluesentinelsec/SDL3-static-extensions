/*
 * SDLStatic debug text — implementation. See SDLStatic/debug_text.h.
 *
 * Owned by SDL3-static-extensions (zlib); the embedded font is ProggyClean
 * by Tristan Grimmer (MIT, license reproduced in sdlstatic_debug_font.h).
 */

#include "SDLStatic/debug_text.h"

#include <SDL3_ttf/SDL_ttf.h>

#include "sdlstatic_debug_font.h"

#define SDLSTATIC_DEBUG_TEXT_CACHE_SIZE 64
#define SDLSTATIC_DEBUG_TEXT_MAX_LEN 1024

typedef struct CacheEntry
{
    char *text;
    SDL_Texture *texture;
    float w, h;              /* logical (renderer-coordinate) size */
    Uint64 last_used;
} CacheEntry;

typedef struct DebugTextState
{
    bool ttf_owned;          /* we called TTF_Init and must TTF_Quit */
    TTF_Font *font;
    float ptsize;
    float density;           /* pixel density the font is currently sized for */
    SDL_Renderer *renderer;  /* cache is per-renderer; reset if it changes */
    CacheEntry cache[SDLSTATIC_DEBUG_TEXT_CACHE_SIZE];
    Uint64 use_counter;
} DebugTextState;

static DebugTextState g_state = { false, NULL, 13.0f, 0.0f, NULL, {{0}}, 0 };

static void ClearCache(void)
{
    int i;
    for (i = 0; i < SDLSTATIC_DEBUG_TEXT_CACHE_SIZE; ++i) {
        SDL_free(g_state.cache[i].text);
        g_state.cache[i].text = NULL;
        if (g_state.cache[i].texture) {
            SDL_DestroyTexture(g_state.cache[i].texture);
            g_state.cache[i].texture = NULL;
        }
    }
}

static float RendererDensity(SDL_Renderer *renderer)
{
    SDL_Window *window = SDL_GetRenderWindow(renderer);
    if (window) {
        float density = SDL_GetWindowPixelDensity(window);
        if (density > 0.0f) {
            return density;
        }
    }
    return 1.0f; /* software / offscreen renderers */
}

static bool EnsureReady(SDL_Renderer *renderer)
{
    float density;

    if (!renderer) {
        return SDL_InvalidParamError("renderer");
    }

    if (!TTF_WasInit()) {
        if (!TTF_Init()) {
            return false;
        }
        g_state.ttf_owned = true;
    }

    density = RendererDensity(renderer);

    if (!g_state.font) {
        SDL_IOStream *io = SDL_IOFromConstMem(sdlstatic_debug_font,
                                              sdlstatic_debug_font_len);
        if (!io) {
            return false;
        }
        g_state.font = TTF_OpenFontIO(io, true, g_state.ptsize);
        if (!g_state.font) {
            return false;
        }
        g_state.density = 0.0f; /* force size pass below */
        /* ProggyClean is a bitmap-style face: crisp at integer sizes with
           mono hinting; light AA elsewhere still reads well. */
        TTF_SetFontHinting(g_state.font, TTF_HINTING_MONO);
    }

    if (density != g_state.density) {
        if (!TTF_SetFontSizeDPI(g_state.font, g_state.ptsize,
                                (int)(72.0f * density), (int)(72.0f * density))) {
            return false;
        }
        g_state.density = density;
        ClearCache();
    }

    if (renderer != g_state.renderer) {
        ClearCache();
        g_state.renderer = renderer;
    }
    return true;
}

static CacheEntry *LookupOrRender(SDL_Renderer *renderer, const char *text)
{
    int i;
    int victim = 0;
    Uint64 oldest = (Uint64)-1;
    SDL_Surface *surface;
    SDL_Texture *texture;
    CacheEntry *entry;

    for (i = 0; i < SDLSTATIC_DEBUG_TEXT_CACHE_SIZE; ++i) {
        if (g_state.cache[i].text && SDL_strcmp(g_state.cache[i].text, text) == 0) {
            g_state.cache[i].last_used = ++g_state.use_counter;
            return &g_state.cache[i];
        }
        if (g_state.cache[i].last_used < oldest) {
            oldest = g_state.cache[i].last_used;
            victim = i;
        }
    }

    /* Render white; per-draw color is applied via texture color mod. */
    {
        const SDL_Color white = { 255, 255, 255, 255 };
        surface = TTF_RenderText_Blended(g_state.font, text, 0, white);
    }
    if (!surface) {
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_DestroySurface(surface);
        return NULL;
    }
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);

    entry = &g_state.cache[victim];
    SDL_free(entry->text);
    if (entry->texture) {
        SDL_DestroyTexture(entry->texture);
    }
    entry->text = SDL_strdup(text);
    entry->texture = texture;
    entry->w = (float)surface->w / g_state.density;
    entry->h = (float)surface->h / g_state.density;
    entry->last_used = ++g_state.use_counter;
    SDL_DestroySurface(surface);

    return entry->text ? entry : NULL;
}

bool SDLStatic_RenderDebugText(SDL_Renderer *renderer, float x, float y,
                               const char *text)
{
    CacheEntry *entry;
    Uint8 r, g, b, a;
    SDL_FRect dst;

    if (!text || !*text) {
        return true; /* nothing to draw */
    }
    if (!EnsureReady(renderer)) {
        return false;
    }

    entry = LookupOrRender(renderer, text);
    if (!entry) {
        return false;
    }

    /* Text color follows the renderer's current draw color. */
    if (!SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a)) {
        return false;
    }
    SDL_SetTextureColorMod(entry->texture, r, g, b);
    SDL_SetTextureAlphaMod(entry->texture, a);

    dst.x = x;
    dst.y = y;
    dst.w = entry->w;
    dst.h = entry->h;
    return SDL_RenderTexture(renderer, entry->texture, NULL, &dst);
}

bool SDLStatic_RenderDebugTextFormat(SDL_Renderer *renderer, float x, float y,
                                     const char *fmt, ...)
{
    char buffer[SDLSTATIC_DEBUG_TEXT_MAX_LEN];
    va_list ap;

    va_start(ap, fmt);
    (void)SDL_vsnprintf(buffer, sizeof(buffer), fmt, ap);
    va_end(ap);
    return SDLStatic_RenderDebugText(renderer, x, y, buffer);
}

void SDLStatic_SetDebugTextSize(float ptsize)
{
    if (ptsize <= 0.0f) {
        return;
    }
    g_state.ptsize = ptsize;
    g_state.density = 0.0f; /* force re-size on next draw */
    ClearCache();
}

void SDLStatic_QuitDebugText(void)
{
    ClearCache();
    if (g_state.font) {
        TTF_CloseFont(g_state.font);
        g_state.font = NULL;
    }
    if (g_state.ttf_owned && TTF_WasInit()) {
        TTF_Quit();
        g_state.ttf_owned = false;
    }
    g_state.renderer = NULL;
    g_state.density = 0.0f;
}
