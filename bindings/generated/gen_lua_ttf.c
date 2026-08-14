/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for SDL_ttf. */
#include "../src/gen_support_lua.h"

#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_ttf/SDL_textengine.h>
#include <string.h>

static void GenRead_SDL_Color(lua_State *L, int idx, SDL_Color *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->r = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "r");
    out->g = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "g");
    out->b = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "b");
    out->a = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "a");
}

static void GenRead_SDL_Rect(lua_State *L, int idx, SDL_Rect *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (int)SDLStaticGen_LuaFieldInt(L, idx, "x");
    out->y = (int)SDLStaticGen_LuaFieldInt(L, idx, "y");
    out->w = (int)SDLStaticGen_LuaFieldInt(L, idx, "w");
    out->h = (int)SDLStaticGen_LuaFieldInt(L, idx, "h");
}

static void GenPush_SDL_Rect(lua_State *L, const SDL_Rect *in)
{
    lua_createtable(L, 0, 4);
    lua_pushinteger(L, (lua_Integer)in->x);
    lua_setfield(L, -2, "x");
    lua_pushinteger(L, (lua_Integer)in->y);
    lua_setfield(L, -2, "y");
    lua_pushinteger(L, (lua_Integer)in->w);
    lua_setfield(L, -2, "w");
    lua_pushinteger(L, (lua_Integer)in->h);
    lua_setfield(L, -2, "h");
}

static void GenRead_TTF_SubString(lua_State *L, int idx, TTF_SubString *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->flags = (TTF_SubStringFlags)SDLStaticGen_LuaFieldInt(L, idx, "flags");
    out->offset = (int)SDLStaticGen_LuaFieldInt(L, idx, "offset");
    out->length = (int)SDLStaticGen_LuaFieldInt(L, idx, "length");
    out->line_index = (int)SDLStaticGen_LuaFieldInt(L, idx, "line_index");
    out->cluster_index = (int)SDLStaticGen_LuaFieldInt(L, idx, "cluster_index");
    lua_getfield(L, idx, "rect");
    GenRead_SDL_Rect(L, lua_gettop(L), &out->rect);
    lua_pop(L, 1);
}

static void GenPush_TTF_SubString(lua_State *L, const TTF_SubString *in)
{
    lua_createtable(L, 0, 6);
    lua_pushinteger(L, (lua_Integer)in->flags);
    lua_setfield(L, -2, "flags");
    lua_pushinteger(L, (lua_Integer)in->offset);
    lua_setfield(L, -2, "offset");
    lua_pushinteger(L, (lua_Integer)in->length);
    lua_setfield(L, -2, "length");
    lua_pushinteger(L, (lua_Integer)in->line_index);
    lua_setfield(L, -2, "line_index");
    lua_pushinteger(L, (lua_Integer)in->cluster_index);
    lua_setfield(L, -2, "cluster_index");
    GenPush_SDL_Rect(L, &in->rect);
    lua_setfield(L, -2, "rect");
}

static void GenDtor_TTF_CloseFont(void *p)
{
    TTF_Font *typed = (TTF_Font *)p;
    TTF_CloseFont(typed);
}

static void GenDtor_TTF_DestroyRendererTextEngine(void *p)
{
    TTF_TextEngine *typed = (TTF_TextEngine *)p;
    TTF_DestroyRendererTextEngine(typed);
}

static void GenDtor_TTF_DestroyText(void *p)
{
    TTF_Text *typed = (TTF_Text *)p;
    TTF_DestroyText(typed);
}

static void GenDtor_SDL_DestroySurface(void *p)
{
    SDL_Surface *typed = (SDL_Surface *)p;
    SDL_DestroySurface(typed);
}

static int GenL_TTF_AddFallbackFont(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_Font *a1 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 2, "TTF_Font");
    bool rv = TTF_AddFallbackFont(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_AppendTextString(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    bool rv = TTF_AppendTextString(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_ClearFallbackFonts(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_ClearFallbackFonts(a0);
    return 0;
}

static int GenL_TTF_CloseFont(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaTakeHandle(L, 1, "TTF_Font");
    TTF_CloseFont(a0);
    return 0;
}

static int GenL_TTF_CopyFont(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_Font * rv = TTF_CopyFont(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "TTF_Font", GenDtor_TTF_CloseFont);
    return 1;
}

static int GenL_TTF_CreateGPUTextEngine(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    TTF_TextEngine * rv = TTF_CreateGPUTextEngine(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "TTF_TextEngine");
    return 1;
}

static int GenL_TTF_CreateGPUTextEngineWithProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    TTF_TextEngine * rv = TTF_CreateGPUTextEngineWithProperties(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "TTF_TextEngine");
    return 1;
}

static int GenL_TTF_CreateRendererTextEngine(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    TTF_TextEngine * rv = TTF_CreateRendererTextEngine(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "TTF_TextEngine", GenDtor_TTF_DestroyRendererTextEngine);
    return 1;
}

static int GenL_TTF_CreateRendererTextEngineWithProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    TTF_TextEngine * rv = TTF_CreateRendererTextEngineWithProperties(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "TTF_TextEngine");
    return 1;
}

static int GenL_TTF_CreateSurfaceTextEngine(lua_State *L)
{
    (void)L;
    TTF_TextEngine * rv = TTF_CreateSurfaceTextEngine();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "TTF_TextEngine");
    return 1;
}

static int GenL_TTF_CreateText(lua_State *L)
{
    (void)L;
    TTF_TextEngine *a0 = (TTF_TextEngine *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_TextEngine");
    TTF_Font *a1 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 2, "TTF_Font");
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    size_t a3 = (size_t)luaL_checkinteger(L, 4);
    TTF_Text * rv = TTF_CreateText(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "TTF_Text", GenDtor_TTF_DestroyText);
    return 1;
}

static int GenL_TTF_DeleteTextString(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = TTF_DeleteTextString(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_DestroyGPUTextEngine(lua_State *L)
{
    (void)L;
    TTF_TextEngine *a0 = (TTF_TextEngine *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_TextEngine");
    TTF_DestroyGPUTextEngine(a0);
    return 0;
}

static int GenL_TTF_DestroyRendererTextEngine(lua_State *L)
{
    (void)L;
    TTF_TextEngine *a0 = (TTF_TextEngine *)SDLStaticGen_LuaTakeHandle(L, 1, "TTF_TextEngine");
    TTF_DestroyRendererTextEngine(a0);
    return 0;
}

static int GenL_TTF_DestroySurfaceTextEngine(lua_State *L)
{
    (void)L;
    TTF_TextEngine *a0 = (TTF_TextEngine *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_TextEngine");
    TTF_DestroySurfaceTextEngine(a0);
    return 0;
}

static int GenL_TTF_DestroyText(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaTakeHandle(L, 1, "TTF_Text");
    TTF_DestroyText(a0);
    return 0;
}

static int GenL_TTF_DrawRendererText(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    bool rv = TTF_DrawRendererText(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_DrawSurfaceText(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDL_Surface *a3 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 4, "SDL_Surface");
    bool rv = TTF_DrawSurfaceText(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_FontHasGlyph(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    bool rv = TTF_FontHasGlyph(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_FontIsFixedWidth(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    bool rv = TTF_FontIsFixedWidth(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_FontIsScalable(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    bool rv = TTF_FontIsScalable(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_GetFontAscent(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    int rv = TTF_GetFontAscent(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontDPI(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    bool rv = TTF_GetFontDPI(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_TTF_GetFontDescent(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    int rv = TTF_GetFontDescent(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontDirection(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_Direction rv = TTF_GetFontDirection(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontFamilyName(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char * rv = TTF_GetFontFamilyName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_TTF_GetFontGeneration(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 rv = TTF_GetFontGeneration(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontHeight(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    int rv = TTF_GetFontHeight(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontHinting(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_HintingFlags rv = TTF_GetFontHinting(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontKerning(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    bool rv = TTF_GetFontKerning(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_GetFontLineSkip(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    int rv = TTF_GetFontLineSkip(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontOutline(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    int rv = TTF_GetFontOutline(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontProperties(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    SDL_PropertiesID rv = TTF_GetFontProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontSDF(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    bool rv = TTF_GetFontSDF(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_GetFontScript(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 rv = TTF_GetFontScript(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontSize(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    float rv = TTF_GetFontSize(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_TTF_GetFontStyle(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_FontStyleFlags rv = TTF_GetFontStyle(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontStyleName(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char * rv = TTF_GetFontStyleName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_TTF_GetFontWeight(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    int rv = TTF_GetFontWeight(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFontWrapAlignment(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_HorizontalAlignment rv = TTF_GetFontWrapAlignment(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetFreeTypeVersion(lua_State *L)
{
    (void)L;
    int io0 = (int)luaL_optinteger(L, 1, 0);
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    TTF_GetFreeTypeVersion(&io0, &io1, &io2);
    lua_pushinteger(L, (lua_Integer)io0);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_TTF_GetGPUTextDrawData(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    TTF_GPUAtlasDrawSequence * rv = TTF_GetGPUTextDrawData(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "TTF_GPUAtlasDrawSequence");
    return 1;
}

static int GenL_TTF_GetGPUTextEngineWinding(lua_State *L)
{
    (void)L;
    const TTF_TextEngine *a0 = (const TTF_TextEngine *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_TextEngine");
    TTF_GPUTextEngineWinding rv = TTF_GetGPUTextEngineWinding(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetGlyphImage(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    TTF_ImageType io2 = (TTF_ImageType)luaL_optinteger(L, 3, 0);
    SDL_Surface * rv = TTF_GetGlyphImage(a0, a1, &io2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_TTF_GetGlyphImageForIndex(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    TTF_ImageType io2 = (TTF_ImageType)luaL_optinteger(L, 3, 0);
    SDL_Surface * rv = TTF_GetGlyphImageForIndex(a0, a1, &io2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_TTF_GetGlyphKerning(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    bool rv = TTF_GetGlyphKerning(a0, a1, a2, &io3);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io3);
    return 2;
}

static int GenL_TTF_GetGlyphMetrics(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    int io4 = (int)luaL_optinteger(L, 5, 0);
    int io5 = (int)luaL_optinteger(L, 6, 0);
    int io6 = (int)luaL_optinteger(L, 7, 0);
    bool rv = TTF_GetGlyphMetrics(a0, a1, &io2, &io3, &io4, &io5, &io6);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    lua_pushinteger(L, (lua_Integer)io5);
    lua_pushinteger(L, (lua_Integer)io6);
    return 6;
}

static int GenL_TTF_GetGlyphScript(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    Uint32 rv = TTF_GetGlyphScript(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetHarfBuzzVersion(lua_State *L)
{
    (void)L;
    int io0 = (int)luaL_optinteger(L, 1, 0);
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    TTF_GetHarfBuzzVersion(&io0, &io1, &io2);
    lua_pushinteger(L, (lua_Integer)io0);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_TTF_GetNextTextSubString(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    TTF_SubString tmp1;
    const TTF_SubString *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_TTF_SubString(L, 2, &tmp1);
        a1 = &tmp1;
    }
    TTF_SubString out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = TTF_GetNextTextSubString(a0, a1, &out2);
    lua_pushboolean(L, (int)rv);
    GenPush_TTF_SubString(L, &out2);
    return 2;
}

static int GenL_TTF_GetNumFontFaces(lua_State *L)
{
    (void)L;
    const TTF_Font *a0 = (const TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    int rv = TTF_GetNumFontFaces(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetPreviousTextSubString(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    TTF_SubString tmp1;
    const TTF_SubString *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_TTF_SubString(L, 2, &tmp1);
        a1 = &tmp1;
    }
    TTF_SubString out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = TTF_GetPreviousTextSubString(a0, a1, &out2);
    lua_pushboolean(L, (int)rv);
    GenPush_TTF_SubString(L, &out2);
    return 2;
}

static int GenL_TTF_GetStringSize(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    int io4 = (int)luaL_optinteger(L, 5, 0);
    bool rv = TTF_GetStringSize(a0, a1, a2, &io3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    return 3;
}

static int GenL_TTF_GetStringSizeWrapped(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int io4 = (int)luaL_optinteger(L, 5, 0);
    int io5 = (int)luaL_optinteger(L, 6, 0);
    bool rv = TTF_GetStringSizeWrapped(a0, a1, a2, a3, &io4, &io5);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io4);
    lua_pushinteger(L, (lua_Integer)io5);
    return 3;
}

static int GenL_TTF_GetTextColor(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    Uint8 io1 = (Uint8)luaL_optinteger(L, 2, 0);
    Uint8 io2 = (Uint8)luaL_optinteger(L, 3, 0);
    Uint8 io3 = (Uint8)luaL_optinteger(L, 4, 0);
    Uint8 io4 = (Uint8)luaL_optinteger(L, 5, 0);
    bool rv = TTF_GetTextColor(a0, &io1, &io2, &io3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    return 5;
}

static int GenL_TTF_GetTextColorFloat(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    bool rv = TTF_GetTextColorFloat(a0, &io1, &io2, &io3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    return 5;
}

static int GenL_TTF_GetTextDirection(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    TTF_Direction rv = TTF_GetTextDirection(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetTextEngine(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    TTF_TextEngine * rv = TTF_GetTextEngine(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "TTF_TextEngine");
    return 1;
}

static int GenL_TTF_GetTextFont(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    TTF_Font * rv = TTF_GetTextFont(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "TTF_Font");
    return 1;
}

static int GenL_TTF_GetTextPosition(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    bool rv = TTF_GetTextPosition(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_TTF_GetTextProperties(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    SDL_PropertiesID rv = TTF_GetTextProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetTextScript(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    Uint32 rv = TTF_GetTextScript(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_GetTextSize(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    bool rv = TTF_GetTextSize(a0, &io1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_TTF_GetTextSubString(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    int a1 = (int)luaL_checkinteger(L, 2);
    TTF_SubString out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = TTF_GetTextSubString(a0, a1, &out2);
    lua_pushboolean(L, (int)rv);
    GenPush_TTF_SubString(L, &out2);
    return 2;
}

static int GenL_TTF_GetTextSubStringForLine(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    int a1 = (int)luaL_checkinteger(L, 2);
    TTF_SubString out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = TTF_GetTextSubStringForLine(a0, a1, &out2);
    lua_pushboolean(L, (int)rv);
    GenPush_TTF_SubString(L, &out2);
    return 2;
}

static int GenL_TTF_GetTextSubStringForPoint(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    TTF_SubString out3;
    memset(&out3, 0, sizeof(out3));
    bool rv = TTF_GetTextSubStringForPoint(a0, a1, a2, &out3);
    lua_pushboolean(L, (int)rv);
    GenPush_TTF_SubString(L, &out3);
    return 2;
}

static int GenL_TTF_GetTextWrapWidth(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    bool rv = TTF_GetTextWrapWidth(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_TTF_Init(lua_State *L)
{
    (void)L;
    bool rv = TTF_Init();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_InsertTextString(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    size_t a3 = (size_t)luaL_checkinteger(L, 4);
    bool rv = TTF_InsertTextString(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_MeasureString(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int io4 = (int)luaL_optinteger(L, 5, 0);
    size_t io5 = (size_t)luaL_optinteger(L, 6, 0);
    bool rv = TTF_MeasureString(a0, a1, a2, a3, &io4, &io5);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io4);
    lua_pushinteger(L, (lua_Integer)io5);
    return 3;
}

static int GenL_TTF_OpenFont(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    TTF_Font * rv = TTF_OpenFont(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "TTF_Font", GenDtor_TTF_CloseFont);
    return 1;
}

static int GenL_TTF_OpenFontIO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    TTF_Font * rv = TTF_OpenFontIO(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "TTF_Font", GenDtor_TTF_CloseFont);
    return 1;
}

static int GenL_TTF_OpenFontWithProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    TTF_Font * rv = TTF_OpenFontWithProperties(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "TTF_Font", GenDtor_TTF_CloseFont);
    return 1;
}

static int GenL_TTF_Quit(lua_State *L)
{
    (void)L;
    TTF_Quit();
    return 0;
}

static int GenL_TTF_RemoveFallbackFont(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_Font *a1 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 2, "TTF_Font");
    TTF_RemoveFallbackFont(a0, a1);
    return 0;
}

static int GenL_TTF_RenderGlyph_Blended(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    SDL_Color a2;
    GenRead_SDL_Color(L, 3, &a2);
    SDL_Surface * rv = TTF_RenderGlyph_Blended(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_RenderGlyph_LCD(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    SDL_Color a2;
    GenRead_SDL_Color(L, 3, &a2);
    SDL_Color a3;
    GenRead_SDL_Color(L, 4, &a3);
    SDL_Surface * rv = TTF_RenderGlyph_LCD(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_RenderGlyph_Shaded(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    SDL_Color a2;
    GenRead_SDL_Color(L, 3, &a2);
    SDL_Color a3;
    GenRead_SDL_Color(L, 4, &a3);
    SDL_Surface * rv = TTF_RenderGlyph_Shaded(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_RenderGlyph_Solid(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    SDL_Color a2;
    GenRead_SDL_Color(L, 3, &a2);
    SDL_Surface * rv = TTF_RenderGlyph_Solid(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_RenderText_Blended(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    SDL_Color a3;
    GenRead_SDL_Color(L, 4, &a3);
    SDL_Surface * rv = TTF_RenderText_Blended(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_RenderText_Blended_Wrapped(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    SDL_Color a3;
    GenRead_SDL_Color(L, 4, &a3);
    int a4 = (int)luaL_checkinteger(L, 5);
    SDL_Surface * rv = TTF_RenderText_Blended_Wrapped(a0, a1, a2, a3, a4);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_RenderText_LCD(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    SDL_Color a3;
    GenRead_SDL_Color(L, 4, &a3);
    SDL_Color a4;
    GenRead_SDL_Color(L, 5, &a4);
    SDL_Surface * rv = TTF_RenderText_LCD(a0, a1, a2, a3, a4);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_RenderText_LCD_Wrapped(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    SDL_Color a3;
    GenRead_SDL_Color(L, 4, &a3);
    SDL_Color a4;
    GenRead_SDL_Color(L, 5, &a4);
    int a5 = (int)luaL_checkinteger(L, 6);
    SDL_Surface * rv = TTF_RenderText_LCD_Wrapped(a0, a1, a2, a3, a4, a5);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_RenderText_Shaded(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    SDL_Color a3;
    GenRead_SDL_Color(L, 4, &a3);
    SDL_Color a4;
    GenRead_SDL_Color(L, 5, &a4);
    SDL_Surface * rv = TTF_RenderText_Shaded(a0, a1, a2, a3, a4);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_RenderText_Shaded_Wrapped(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    SDL_Color a3;
    GenRead_SDL_Color(L, 4, &a3);
    SDL_Color a4;
    GenRead_SDL_Color(L, 5, &a4);
    int a5 = (int)luaL_checkinteger(L, 6);
    SDL_Surface * rv = TTF_RenderText_Shaded_Wrapped(a0, a1, a2, a3, a4, a5);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_RenderText_Solid(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    SDL_Color a3;
    GenRead_SDL_Color(L, 4, &a3);
    SDL_Surface * rv = TTF_RenderText_Solid(a0, a1, a2, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_RenderText_Solid_Wrapped(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    SDL_Color a3;
    GenRead_SDL_Color(L, 4, &a3);
    int a4 = (int)luaL_checkinteger(L, 5);
    SDL_Surface * rv = TTF_RenderText_Solid_Wrapped(a0, a1, a2, a3, a4);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_TTF_SetFontDirection(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_Direction a1 = (TTF_Direction)luaL_checkinteger(L, 2);
    bool rv = TTF_SetFontDirection(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetFontHinting(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_HintingFlags a1 = (TTF_HintingFlags)luaL_checkinteger(L, 2);
    TTF_SetFontHinting(a0, a1);
    return 0;
}

static int GenL_TTF_SetFontKerning(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    bool a1 = (bool)lua_toboolean(L, 2);
    TTF_SetFontKerning(a0, a1);
    return 0;
}

static int GenL_TTF_SetFontLanguage(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = TTF_SetFontLanguage(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetFontLineSkip(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    int a1 = (int)luaL_checkinteger(L, 2);
    TTF_SetFontLineSkip(a0, a1);
    return 0;
}

static int GenL_TTF_SetFontOutline(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = TTF_SetFontOutline(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetFontSDF(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = TTF_SetFontSDF(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetFontScript(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    bool rv = TTF_SetFontScript(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetFontSize(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    float a1 = (float)luaL_checknumber(L, 2);
    bool rv = TTF_SetFontSize(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetFontSizeDPI(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    float a1 = (float)luaL_checknumber(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    bool rv = TTF_SetFontSizeDPI(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetFontStyle(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_FontStyleFlags a1 = (TTF_FontStyleFlags)luaL_checkinteger(L, 2);
    TTF_SetFontStyle(a0, a1);
    return 0;
}

static int GenL_TTF_SetFontWrapAlignment(lua_State *L)
{
    (void)L;
    TTF_Font *a0 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Font");
    TTF_HorizontalAlignment a1 = (TTF_HorizontalAlignment)luaL_checkinteger(L, 2);
    TTF_SetFontWrapAlignment(a0, a1);
    return 0;
}

static int GenL_TTF_SetGPUTextEngineWinding(lua_State *L)
{
    (void)L;
    TTF_TextEngine *a0 = (TTF_TextEngine *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_TextEngine");
    TTF_GPUTextEngineWinding a1 = (TTF_GPUTextEngineWinding)luaL_checkinteger(L, 2);
    TTF_SetGPUTextEngineWinding(a0, a1);
    return 0;
}

static int GenL_TTF_SetTextColor(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    Uint8 a1 = (Uint8)luaL_checkinteger(L, 2);
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    bool rv = TTF_SetTextColor(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetTextColorFloat(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    bool rv = TTF_SetTextColorFloat(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetTextDirection(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    TTF_Direction a1 = (TTF_Direction)luaL_checkinteger(L, 2);
    bool rv = TTF_SetTextDirection(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetTextEngine(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    TTF_TextEngine *a1 = (TTF_TextEngine *)SDLStaticGen_LuaCheckHandle(L, 2, "TTF_TextEngine");
    bool rv = TTF_SetTextEngine(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetTextFont(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    TTF_Font *a1 = (TTF_Font *)SDLStaticGen_LuaCheckHandle(L, 2, "TTF_Font");
    bool rv = TTF_SetTextFont(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetTextPosition(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = TTF_SetTextPosition(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetTextScript(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    bool rv = TTF_SetTextScript(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetTextString(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    bool rv = TTF_SetTextString(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetTextWrapWhitespaceVisible(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = TTF_SetTextWrapWhitespaceVisible(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_SetTextWrapWidth(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = TTF_SetTextWrapWidth(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_StringToTag(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    Uint32 rv = TTF_StringToTag(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_TagToString(lua_State *L)
{
    (void)L;
    Uint32 a0 = (Uint32)luaL_checkinteger(L, 1);
    const char *src1 = lua_isnoneornil(L, 2) ? "" : luaL_checkstring(L, 2);
    char *a1 = SDL_strdup(src1);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    TTF_TagToString(a0, a1, a2);
    SDL_free(a1);
    return 0;
}

static int GenL_TTF_TextWrapWhitespaceVisible(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    bool rv = TTF_TextWrapWhitespaceVisible(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_UpdateText(lua_State *L)
{
    (void)L;
    TTF_Text *a0 = (TTF_Text *)SDLStaticGen_LuaCheckHandle(L, 1, "TTF_Text");
    bool rv = TTF_UpdateText(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_TTF_Version(lua_State *L)
{
    (void)L;
    int rv = TTF_Version();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_TTF_WasInit(lua_State *L)
{
    (void)L;
    int rv = TTF_WasInit();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

int SDLStaticGen_OpenLua_ttf(lua_State *L);
int SDLStaticGen_OpenLua_ttf(lua_State *L)
{
    lua_createtable(L, 0, 116);
    lua_pushcfunction(L, GenL_TTF_AddFallbackFont);
    lua_setfield(L, -2, "AddFallbackFont");
    lua_pushcfunction(L, GenL_TTF_AppendTextString);
    lua_setfield(L, -2, "AppendTextString");
    lua_pushcfunction(L, GenL_TTF_ClearFallbackFonts);
    lua_setfield(L, -2, "ClearFallbackFonts");
    lua_pushcfunction(L, GenL_TTF_CloseFont);
    lua_setfield(L, -2, "CloseFont");
    lua_pushcfunction(L, GenL_TTF_CopyFont);
    lua_setfield(L, -2, "CopyFont");
    lua_pushcfunction(L, GenL_TTF_CreateGPUTextEngine);
    lua_setfield(L, -2, "CreateGPUTextEngine");
    lua_pushcfunction(L, GenL_TTF_CreateGPUTextEngineWithProperties);
    lua_setfield(L, -2, "CreateGPUTextEngineWithProperties");
    lua_pushcfunction(L, GenL_TTF_CreateRendererTextEngine);
    lua_setfield(L, -2, "CreateRendererTextEngine");
    lua_pushcfunction(L, GenL_TTF_CreateRendererTextEngineWithProperties);
    lua_setfield(L, -2, "CreateRendererTextEngineWithProperties");
    lua_pushcfunction(L, GenL_TTF_CreateSurfaceTextEngine);
    lua_setfield(L, -2, "CreateSurfaceTextEngine");
    lua_pushcfunction(L, GenL_TTF_CreateText);
    lua_setfield(L, -2, "CreateText");
    lua_pushcfunction(L, GenL_TTF_DeleteTextString);
    lua_setfield(L, -2, "DeleteTextString");
    lua_pushcfunction(L, GenL_TTF_DestroyGPUTextEngine);
    lua_setfield(L, -2, "DestroyGPUTextEngine");
    lua_pushcfunction(L, GenL_TTF_DestroyRendererTextEngine);
    lua_setfield(L, -2, "DestroyRendererTextEngine");
    lua_pushcfunction(L, GenL_TTF_DestroySurfaceTextEngine);
    lua_setfield(L, -2, "DestroySurfaceTextEngine");
    lua_pushcfunction(L, GenL_TTF_DestroyText);
    lua_setfield(L, -2, "DestroyText");
    lua_pushcfunction(L, GenL_TTF_DrawRendererText);
    lua_setfield(L, -2, "DrawRendererText");
    lua_pushcfunction(L, GenL_TTF_DrawSurfaceText);
    lua_setfield(L, -2, "DrawSurfaceText");
    lua_pushcfunction(L, GenL_TTF_FontHasGlyph);
    lua_setfield(L, -2, "FontHasGlyph");
    lua_pushcfunction(L, GenL_TTF_FontIsFixedWidth);
    lua_setfield(L, -2, "FontIsFixedWidth");
    lua_pushcfunction(L, GenL_TTF_FontIsScalable);
    lua_setfield(L, -2, "FontIsScalable");
    lua_pushcfunction(L, GenL_TTF_GetFontAscent);
    lua_setfield(L, -2, "GetFontAscent");
    lua_pushcfunction(L, GenL_TTF_GetFontDPI);
    lua_setfield(L, -2, "GetFontDPI");
    lua_pushcfunction(L, GenL_TTF_GetFontDescent);
    lua_setfield(L, -2, "GetFontDescent");
    lua_pushcfunction(L, GenL_TTF_GetFontDirection);
    lua_setfield(L, -2, "GetFontDirection");
    lua_pushcfunction(L, GenL_TTF_GetFontFamilyName);
    lua_setfield(L, -2, "GetFontFamilyName");
    lua_pushcfunction(L, GenL_TTF_GetFontGeneration);
    lua_setfield(L, -2, "GetFontGeneration");
    lua_pushcfunction(L, GenL_TTF_GetFontHeight);
    lua_setfield(L, -2, "GetFontHeight");
    lua_pushcfunction(L, GenL_TTF_GetFontHinting);
    lua_setfield(L, -2, "GetFontHinting");
    lua_pushcfunction(L, GenL_TTF_GetFontKerning);
    lua_setfield(L, -2, "GetFontKerning");
    lua_pushcfunction(L, GenL_TTF_GetFontLineSkip);
    lua_setfield(L, -2, "GetFontLineSkip");
    lua_pushcfunction(L, GenL_TTF_GetFontOutline);
    lua_setfield(L, -2, "GetFontOutline");
    lua_pushcfunction(L, GenL_TTF_GetFontProperties);
    lua_setfield(L, -2, "GetFontProperties");
    lua_pushcfunction(L, GenL_TTF_GetFontSDF);
    lua_setfield(L, -2, "GetFontSDF");
    lua_pushcfunction(L, GenL_TTF_GetFontScript);
    lua_setfield(L, -2, "GetFontScript");
    lua_pushcfunction(L, GenL_TTF_GetFontSize);
    lua_setfield(L, -2, "GetFontSize");
    lua_pushcfunction(L, GenL_TTF_GetFontStyle);
    lua_setfield(L, -2, "GetFontStyle");
    lua_pushcfunction(L, GenL_TTF_GetFontStyleName);
    lua_setfield(L, -2, "GetFontStyleName");
    lua_pushcfunction(L, GenL_TTF_GetFontWeight);
    lua_setfield(L, -2, "GetFontWeight");
    lua_pushcfunction(L, GenL_TTF_GetFontWrapAlignment);
    lua_setfield(L, -2, "GetFontWrapAlignment");
    lua_pushcfunction(L, GenL_TTF_GetFreeTypeVersion);
    lua_setfield(L, -2, "GetFreeTypeVersion");
    lua_pushcfunction(L, GenL_TTF_GetGPUTextDrawData);
    lua_setfield(L, -2, "GetGPUTextDrawData");
    lua_pushcfunction(L, GenL_TTF_GetGPUTextEngineWinding);
    lua_setfield(L, -2, "GetGPUTextEngineWinding");
    lua_pushcfunction(L, GenL_TTF_GetGlyphImage);
    lua_setfield(L, -2, "GetGlyphImage");
    lua_pushcfunction(L, GenL_TTF_GetGlyphImageForIndex);
    lua_setfield(L, -2, "GetGlyphImageForIndex");
    lua_pushcfunction(L, GenL_TTF_GetGlyphKerning);
    lua_setfield(L, -2, "GetGlyphKerning");
    lua_pushcfunction(L, GenL_TTF_GetGlyphMetrics);
    lua_setfield(L, -2, "GetGlyphMetrics");
    lua_pushcfunction(L, GenL_TTF_GetGlyphScript);
    lua_setfield(L, -2, "GetGlyphScript");
    lua_pushcfunction(L, GenL_TTF_GetHarfBuzzVersion);
    lua_setfield(L, -2, "GetHarfBuzzVersion");
    lua_pushcfunction(L, GenL_TTF_GetNextTextSubString);
    lua_setfield(L, -2, "GetNextTextSubString");
    lua_pushcfunction(L, GenL_TTF_GetNumFontFaces);
    lua_setfield(L, -2, "GetNumFontFaces");
    lua_pushcfunction(L, GenL_TTF_GetPreviousTextSubString);
    lua_setfield(L, -2, "GetPreviousTextSubString");
    lua_pushcfunction(L, GenL_TTF_GetStringSize);
    lua_setfield(L, -2, "GetStringSize");
    lua_pushcfunction(L, GenL_TTF_GetStringSizeWrapped);
    lua_setfield(L, -2, "GetStringSizeWrapped");
    lua_pushcfunction(L, GenL_TTF_GetTextColor);
    lua_setfield(L, -2, "GetTextColor");
    lua_pushcfunction(L, GenL_TTF_GetTextColorFloat);
    lua_setfield(L, -2, "GetTextColorFloat");
    lua_pushcfunction(L, GenL_TTF_GetTextDirection);
    lua_setfield(L, -2, "GetTextDirection");
    lua_pushcfunction(L, GenL_TTF_GetTextEngine);
    lua_setfield(L, -2, "GetTextEngine");
    lua_pushcfunction(L, GenL_TTF_GetTextFont);
    lua_setfield(L, -2, "GetTextFont");
    lua_pushcfunction(L, GenL_TTF_GetTextPosition);
    lua_setfield(L, -2, "GetTextPosition");
    lua_pushcfunction(L, GenL_TTF_GetTextProperties);
    lua_setfield(L, -2, "GetTextProperties");
    lua_pushcfunction(L, GenL_TTF_GetTextScript);
    lua_setfield(L, -2, "GetTextScript");
    lua_pushcfunction(L, GenL_TTF_GetTextSize);
    lua_setfield(L, -2, "GetTextSize");
    lua_pushcfunction(L, GenL_TTF_GetTextSubString);
    lua_setfield(L, -2, "GetTextSubString");
    lua_pushcfunction(L, GenL_TTF_GetTextSubStringForLine);
    lua_setfield(L, -2, "GetTextSubStringForLine");
    lua_pushcfunction(L, GenL_TTF_GetTextSubStringForPoint);
    lua_setfield(L, -2, "GetTextSubStringForPoint");
    lua_pushcfunction(L, GenL_TTF_GetTextWrapWidth);
    lua_setfield(L, -2, "GetTextWrapWidth");
    lua_pushcfunction(L, GenL_TTF_Init);
    lua_setfield(L, -2, "Init");
    lua_pushcfunction(L, GenL_TTF_InsertTextString);
    lua_setfield(L, -2, "InsertTextString");
    lua_pushcfunction(L, GenL_TTF_MeasureString);
    lua_setfield(L, -2, "MeasureString");
    lua_pushcfunction(L, GenL_TTF_OpenFont);
    lua_setfield(L, -2, "OpenFont");
    lua_pushcfunction(L, GenL_TTF_OpenFontIO);
    lua_setfield(L, -2, "OpenFontIO");
    lua_pushcfunction(L, GenL_TTF_OpenFontWithProperties);
    lua_setfield(L, -2, "OpenFontWithProperties");
    lua_pushcfunction(L, GenL_TTF_Quit);
    lua_setfield(L, -2, "Quit");
    lua_pushcfunction(L, GenL_TTF_RemoveFallbackFont);
    lua_setfield(L, -2, "RemoveFallbackFont");
    lua_pushcfunction(L, GenL_TTF_RenderGlyph_Blended);
    lua_setfield(L, -2, "RenderGlyph_Blended");
    lua_pushcfunction(L, GenL_TTF_RenderGlyph_LCD);
    lua_setfield(L, -2, "RenderGlyph_LCD");
    lua_pushcfunction(L, GenL_TTF_RenderGlyph_Shaded);
    lua_setfield(L, -2, "RenderGlyph_Shaded");
    lua_pushcfunction(L, GenL_TTF_RenderGlyph_Solid);
    lua_setfield(L, -2, "RenderGlyph_Solid");
    lua_pushcfunction(L, GenL_TTF_RenderText_Blended);
    lua_setfield(L, -2, "RenderText_Blended");
    lua_pushcfunction(L, GenL_TTF_RenderText_Blended_Wrapped);
    lua_setfield(L, -2, "RenderText_Blended_Wrapped");
    lua_pushcfunction(L, GenL_TTF_RenderText_LCD);
    lua_setfield(L, -2, "RenderText_LCD");
    lua_pushcfunction(L, GenL_TTF_RenderText_LCD_Wrapped);
    lua_setfield(L, -2, "RenderText_LCD_Wrapped");
    lua_pushcfunction(L, GenL_TTF_RenderText_Shaded);
    lua_setfield(L, -2, "RenderText_Shaded");
    lua_pushcfunction(L, GenL_TTF_RenderText_Shaded_Wrapped);
    lua_setfield(L, -2, "RenderText_Shaded_Wrapped");
    lua_pushcfunction(L, GenL_TTF_RenderText_Solid);
    lua_setfield(L, -2, "RenderText_Solid");
    lua_pushcfunction(L, GenL_TTF_RenderText_Solid_Wrapped);
    lua_setfield(L, -2, "RenderText_Solid_Wrapped");
    lua_pushcfunction(L, GenL_TTF_SetFontDirection);
    lua_setfield(L, -2, "SetFontDirection");
    lua_pushcfunction(L, GenL_TTF_SetFontHinting);
    lua_setfield(L, -2, "SetFontHinting");
    lua_pushcfunction(L, GenL_TTF_SetFontKerning);
    lua_setfield(L, -2, "SetFontKerning");
    lua_pushcfunction(L, GenL_TTF_SetFontLanguage);
    lua_setfield(L, -2, "SetFontLanguage");
    lua_pushcfunction(L, GenL_TTF_SetFontLineSkip);
    lua_setfield(L, -2, "SetFontLineSkip");
    lua_pushcfunction(L, GenL_TTF_SetFontOutline);
    lua_setfield(L, -2, "SetFontOutline");
    lua_pushcfunction(L, GenL_TTF_SetFontSDF);
    lua_setfield(L, -2, "SetFontSDF");
    lua_pushcfunction(L, GenL_TTF_SetFontScript);
    lua_setfield(L, -2, "SetFontScript");
    lua_pushcfunction(L, GenL_TTF_SetFontSize);
    lua_setfield(L, -2, "SetFontSize");
    lua_pushcfunction(L, GenL_TTF_SetFontSizeDPI);
    lua_setfield(L, -2, "SetFontSizeDPI");
    lua_pushcfunction(L, GenL_TTF_SetFontStyle);
    lua_setfield(L, -2, "SetFontStyle");
    lua_pushcfunction(L, GenL_TTF_SetFontWrapAlignment);
    lua_setfield(L, -2, "SetFontWrapAlignment");
    lua_pushcfunction(L, GenL_TTF_SetGPUTextEngineWinding);
    lua_setfield(L, -2, "SetGPUTextEngineWinding");
    lua_pushcfunction(L, GenL_TTF_SetTextColor);
    lua_setfield(L, -2, "SetTextColor");
    lua_pushcfunction(L, GenL_TTF_SetTextColorFloat);
    lua_setfield(L, -2, "SetTextColorFloat");
    lua_pushcfunction(L, GenL_TTF_SetTextDirection);
    lua_setfield(L, -2, "SetTextDirection");
    lua_pushcfunction(L, GenL_TTF_SetTextEngine);
    lua_setfield(L, -2, "SetTextEngine");
    lua_pushcfunction(L, GenL_TTF_SetTextFont);
    lua_setfield(L, -2, "SetTextFont");
    lua_pushcfunction(L, GenL_TTF_SetTextPosition);
    lua_setfield(L, -2, "SetTextPosition");
    lua_pushcfunction(L, GenL_TTF_SetTextScript);
    lua_setfield(L, -2, "SetTextScript");
    lua_pushcfunction(L, GenL_TTF_SetTextString);
    lua_setfield(L, -2, "SetTextString");
    lua_pushcfunction(L, GenL_TTF_SetTextWrapWhitespaceVisible);
    lua_setfield(L, -2, "SetTextWrapWhitespaceVisible");
    lua_pushcfunction(L, GenL_TTF_SetTextWrapWidth);
    lua_setfield(L, -2, "SetTextWrapWidth");
    lua_pushcfunction(L, GenL_TTF_StringToTag);
    lua_setfield(L, -2, "StringToTag");
    lua_pushcfunction(L, GenL_TTF_TagToString);
    lua_setfield(L, -2, "TagToString");
    lua_pushcfunction(L, GenL_TTF_TextWrapWhitespaceVisible);
    lua_setfield(L, -2, "TextWrapWhitespaceVisible");
    lua_pushcfunction(L, GenL_TTF_UpdateText);
    lua_setfield(L, -2, "UpdateText");
    lua_pushcfunction(L, GenL_TTF_Version);
    lua_setfield(L, -2, "Version");
    lua_pushcfunction(L, GenL_TTF_WasInit);
    lua_setfield(L, -2, "WasInit");
    lua_pushinteger(L, (lua_Integer)TTF_DIRECTION_INVALID);
    lua_setfield(L, -2, "DIRECTION_INVALID");
    lua_pushinteger(L, (lua_Integer)TTF_DIRECTION_LTR);
    lua_setfield(L, -2, "DIRECTION_LTR");
    lua_pushinteger(L, (lua_Integer)TTF_DIRECTION_RTL);
    lua_setfield(L, -2, "DIRECTION_RTL");
    lua_pushinteger(L, (lua_Integer)TTF_DIRECTION_TTB);
    lua_setfield(L, -2, "DIRECTION_TTB");
    lua_pushinteger(L, (lua_Integer)TTF_DIRECTION_BTT);
    lua_setfield(L, -2, "DIRECTION_BTT");
    lua_pushinteger(L, (lua_Integer)TTF_DRAW_COMMAND_NOOP);
    lua_setfield(L, -2, "DRAW_COMMAND_NOOP");
    lua_pushinteger(L, (lua_Integer)TTF_DRAW_COMMAND_FILL);
    lua_setfield(L, -2, "DRAW_COMMAND_FILL");
    lua_pushinteger(L, (lua_Integer)TTF_DRAW_COMMAND_COPY);
    lua_setfield(L, -2, "DRAW_COMMAND_COPY");
    lua_pushinteger(L, (lua_Integer)TTF_GPU_TEXTENGINE_WINDING_INVALID);
    lua_setfield(L, -2, "GPU_TEXTENGINE_WINDING_INVALID");
    lua_pushinteger(L, (lua_Integer)TTF_GPU_TEXTENGINE_WINDING_CLOCKWISE);
    lua_setfield(L, -2, "GPU_TEXTENGINE_WINDING_CLOCKWISE");
    lua_pushinteger(L, (lua_Integer)TTF_GPU_TEXTENGINE_WINDING_COUNTER_CLOCKWISE);
    lua_setfield(L, -2, "GPU_TEXTENGINE_WINDING_COUNTER_CLOCKWISE");
    lua_pushinteger(L, (lua_Integer)TTF_HINTING_INVALID);
    lua_setfield(L, -2, "HINTING_INVALID");
    lua_pushinteger(L, (lua_Integer)TTF_HINTING_NORMAL);
    lua_setfield(L, -2, "HINTING_NORMAL");
    lua_pushinteger(L, (lua_Integer)TTF_HINTING_LIGHT);
    lua_setfield(L, -2, "HINTING_LIGHT");
    lua_pushinteger(L, (lua_Integer)TTF_HINTING_MONO);
    lua_setfield(L, -2, "HINTING_MONO");
    lua_pushinteger(L, (lua_Integer)TTF_HINTING_NONE);
    lua_setfield(L, -2, "HINTING_NONE");
    lua_pushinteger(L, (lua_Integer)TTF_HINTING_LIGHT_SUBPIXEL);
    lua_setfield(L, -2, "HINTING_LIGHT_SUBPIXEL");
    lua_pushinteger(L, (lua_Integer)TTF_HORIZONTAL_ALIGN_INVALID);
    lua_setfield(L, -2, "HORIZONTAL_ALIGN_INVALID");
    lua_pushinteger(L, (lua_Integer)TTF_HORIZONTAL_ALIGN_LEFT);
    lua_setfield(L, -2, "HORIZONTAL_ALIGN_LEFT");
    lua_pushinteger(L, (lua_Integer)TTF_HORIZONTAL_ALIGN_CENTER);
    lua_setfield(L, -2, "HORIZONTAL_ALIGN_CENTER");
    lua_pushinteger(L, (lua_Integer)TTF_HORIZONTAL_ALIGN_RIGHT);
    lua_setfield(L, -2, "HORIZONTAL_ALIGN_RIGHT");
    lua_pushinteger(L, (lua_Integer)TTF_IMAGE_INVALID);
    lua_setfield(L, -2, "IMAGE_INVALID");
    lua_pushinteger(L, (lua_Integer)TTF_IMAGE_ALPHA);
    lua_setfield(L, -2, "IMAGE_ALPHA");
    lua_pushinteger(L, (lua_Integer)TTF_IMAGE_COLOR);
    lua_setfield(L, -2, "IMAGE_COLOR");
    lua_pushinteger(L, (lua_Integer)TTF_IMAGE_SDF);
    lua_setfield(L, -2, "IMAGE_SDF");
    lua_setglobal(L, "TTF");
    return 0;
}
