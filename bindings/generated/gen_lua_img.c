/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for SDL_image. */
#include "../src/gen_support_lua.h"

#include <SDL3_image/SDL_image.h>
#include <string.h>

static void GenDtor_IMG_FreeAnimation(void *p)
{
    IMG_Animation *typed = (IMG_Animation *)p;
    IMG_FreeAnimation(typed);
}

static void GenDtor_SDL_DestroySurface(void *p)
{
    SDL_Surface *typed = (SDL_Surface *)p;
    SDL_DestroySurface(typed);
}

static int GenL_IMG_AddAnimationEncoderFrame(lua_State *L)
{
    (void)L;
    IMG_AnimationEncoder *a0 = (IMG_AnimationEncoder *)SDLStaticGen_LuaCheckHandle(L, 1, "IMG_AnimationEncoder");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Surface");
    Uint64 a2 = (Uint64)luaL_checkinteger(L, 3);
    bool rv = IMG_AddAnimationEncoderFrame(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_CloseAnimationDecoder(lua_State *L)
{
    (void)L;
    IMG_AnimationDecoder *a0 = (IMG_AnimationDecoder *)SDLStaticGen_LuaCheckHandle(L, 1, "IMG_AnimationDecoder");
    bool rv = IMG_CloseAnimationDecoder(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_CloseAnimationEncoder(lua_State *L)
{
    (void)L;
    IMG_AnimationEncoder *a0 = (IMG_AnimationEncoder *)SDLStaticGen_LuaCheckHandle(L, 1, "IMG_AnimationEncoder");
    bool rv = IMG_CloseAnimationEncoder(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_CreateAnimatedCursor(lua_State *L)
{
    (void)L;
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_LuaCheckHandle(L, 1, "IMG_Animation");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDL_Cursor * rv = IMG_CreateAnimatedCursor(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Cursor");
    return 1;
}

static int GenL_IMG_CreateAnimationDecoder(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    IMG_AnimationDecoder * rv = IMG_CreateAnimationDecoder(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "IMG_AnimationDecoder");
    return 1;
}

static int GenL_IMG_CreateAnimationDecoderWithProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    IMG_AnimationDecoder * rv = IMG_CreateAnimationDecoderWithProperties(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "IMG_AnimationDecoder");
    return 1;
}

static int GenL_IMG_CreateAnimationDecoder_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    IMG_AnimationDecoder * rv = IMG_CreateAnimationDecoder_IO(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "IMG_AnimationDecoder");
    return 1;
}

static int GenL_IMG_CreateAnimationEncoder(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    IMG_AnimationEncoder * rv = IMG_CreateAnimationEncoder(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "IMG_AnimationEncoder");
    return 1;
}

static int GenL_IMG_CreateAnimationEncoderWithProperties(lua_State *L)
{
    (void)L;
    SDL_PropertiesID a0 = (SDL_PropertiesID)luaL_checkinteger(L, 1);
    IMG_AnimationEncoder * rv = IMG_CreateAnimationEncoderWithProperties(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "IMG_AnimationEncoder");
    return 1;
}

static int GenL_IMG_CreateAnimationEncoder_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    IMG_AnimationEncoder * rv = IMG_CreateAnimationEncoder_IO(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "IMG_AnimationEncoder");
    return 1;
}

static int GenL_IMG_FreeAnimation(lua_State *L)
{
    (void)L;
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_LuaTakeHandle(L, 1, "IMG_Animation");
    IMG_FreeAnimation(a0);
    return 0;
}

static int GenL_IMG_GetAnimationDecoderProperties(lua_State *L)
{
    (void)L;
    IMG_AnimationDecoder *a0 = (IMG_AnimationDecoder *)SDLStaticGen_LuaCheckHandle(L, 1, "IMG_AnimationDecoder");
    SDL_PropertiesID rv = IMG_GetAnimationDecoderProperties(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_IMG_GetAnimationDecoderStatus(lua_State *L)
{
    (void)L;
    IMG_AnimationDecoder *a0 = (IMG_AnimationDecoder *)SDLStaticGen_LuaCheckHandle(L, 1, "IMG_AnimationDecoder");
    IMG_AnimationDecoderStatus rv = IMG_GetAnimationDecoderStatus(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_IMG_GetClipboardImage(lua_State *L)
{
    (void)L;
    SDL_Surface * rv = IMG_GetClipboardImage();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_Load(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_Surface * rv = IMG_Load(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_IMG_LoadANIAnimation_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    IMG_Animation * rv = IMG_LoadANIAnimation_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "IMG_Animation");
    return 1;
}

static int GenL_IMG_LoadAnimation(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    IMG_Animation * rv = IMG_LoadAnimation(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "IMG_Animation", GenDtor_IMG_FreeAnimation);
    return 1;
}

static int GenL_IMG_LoadAnimationTyped_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    IMG_Animation * rv = IMG_LoadAnimationTyped_IO(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "IMG_Animation", GenDtor_IMG_FreeAnimation);
    return 1;
}

static int GenL_IMG_LoadAnimation_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    IMG_Animation * rv = IMG_LoadAnimation_IO(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "IMG_Animation", GenDtor_IMG_FreeAnimation);
    return 1;
}

static int GenL_IMG_LoadBMP_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadBMP_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadCUR_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadCUR_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadGIFAnimation_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    IMG_Animation * rv = IMG_LoadGIFAnimation_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "IMG_Animation");
    return 1;
}

static int GenL_IMG_LoadGIF_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadGIF_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadGPUTexture(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUCopyPass *a1 = (SDL_GPUCopyPass *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUCopyPass");
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    int io4 = (int)luaL_optinteger(L, 5, 0);
    SDL_GPUTexture * rv = IMG_LoadGPUTexture(a0, a1, a2, &io3, &io4);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUTexture");
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    return 3;
}

static int GenL_IMG_LoadGPUTextureTyped_IO(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUCopyPass *a1 = (SDL_GPUCopyPass *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUCopyPass");
    SDL_IOStream *a2 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_IOStream");
    bool a3 = (bool)lua_toboolean(L, 4);
    const char *a4 = lua_isnoneornil(L, 5) ? NULL : luaL_checkstring(L, 5);
    int io5 = (int)luaL_optinteger(L, 6, 0);
    int io6 = (int)luaL_optinteger(L, 7, 0);
    SDL_GPUTexture * rv = IMG_LoadGPUTextureTyped_IO(a0, a1, a2, a3, a4, &io5, &io6);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUTexture");
    lua_pushinteger(L, (lua_Integer)io5);
    lua_pushinteger(L, (lua_Integer)io6);
    return 3;
}

static int GenL_IMG_LoadGPUTexture_IO(lua_State *L)
{
    (void)L;
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_GPUDevice");
    SDL_GPUCopyPass *a1 = (SDL_GPUCopyPass *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_GPUCopyPass");
    SDL_IOStream *a2 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 3, "SDL_IOStream");
    bool a3 = (bool)lua_toboolean(L, 4);
    int io4 = (int)luaL_optinteger(L, 5, 0);
    int io5 = (int)luaL_optinteger(L, 6, 0);
    SDL_GPUTexture * rv = IMG_LoadGPUTexture_IO(a0, a1, a2, a3, &io4, &io5);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_GPUTexture");
    lua_pushinteger(L, (lua_Integer)io4);
    lua_pushinteger(L, (lua_Integer)io5);
    return 3;
}

static int GenL_IMG_LoadICO_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadICO_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadJPG_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadJPG_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadLBM_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadLBM_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadPCX_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadPCX_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadPNG_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadPNG_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadPNM_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadPNM_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadQOI_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadQOI_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadSVG_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadSVG_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadSizedSVG_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDL_Surface * rv = IMG_LoadSizedSVG_IO(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadTGA_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadTGA_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadTexture(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_Texture * rv = IMG_LoadTexture(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Texture");
    return 1;
}

static int GenL_IMG_LoadTextureTyped_IO(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    SDL_Texture * rv = IMG_LoadTextureTyped_IO(a0, a1, a2, a3);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Texture");
    return 1;
}

static int GenL_IMG_LoadTexture_IO(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    SDL_Texture * rv = IMG_LoadTexture_IO(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Texture");
    return 1;
}

static int GenL_IMG_LoadTyped_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    SDL_Surface * rv = IMG_LoadTyped_IO(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_IMG_LoadXCF_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadXCF_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadXPM_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadXPM_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_LoadXV_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    SDL_Surface * rv = IMG_LoadXV_IO(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Surface");
    return 1;
}

static int GenL_IMG_Load_IO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDL_Surface * rv = IMG_Load_IO(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    return 1;
}

static int GenL_IMG_ResetAnimationDecoder(lua_State *L)
{
    (void)L;
    IMG_AnimationDecoder *a0 = (IMG_AnimationDecoder *)SDLStaticGen_LuaCheckHandle(L, 1, "IMG_AnimationDecoder");
    bool rv = IMG_ResetAnimationDecoder(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_Save(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = IMG_Save(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveANIAnimation_IO(lua_State *L)
{
    (void)L;
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_LuaCheckHandle(L, 1, "IMG_Animation");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = IMG_SaveANIAnimation_IO(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveAnimation(lua_State *L)
{
    (void)L;
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_LuaCheckHandle(L, 1, "IMG_Animation");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = IMG_SaveAnimation(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveAnimationTyped_IO(lua_State *L)
{
    (void)L;
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_LuaCheckHandle(L, 1, "IMG_Animation");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = IMG_SaveAnimationTyped_IO(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveBMP(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = IMG_SaveBMP(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveBMP_IO(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = IMG_SaveBMP_IO(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveCUR(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = IMG_SaveCUR(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveCUR_IO(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = IMG_SaveCUR_IO(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveGIF(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = IMG_SaveGIF(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveGIFAnimation_IO(lua_State *L)
{
    (void)L;
    IMG_Animation *a0 = (IMG_Animation *)SDLStaticGen_LuaCheckHandle(L, 1, "IMG_Animation");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = IMG_SaveGIFAnimation_IO(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveGIF_IO(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = IMG_SaveGIF_IO(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveICO(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = IMG_SaveICO(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveICO_IO(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = IMG_SaveICO_IO(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveJPG(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = IMG_SaveJPG(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveJPG_IO(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    bool rv = IMG_SaveJPG_IO(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SavePNG(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = IMG_SavePNG(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SavePNG_IO(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = IMG_SavePNG_IO(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveTGA(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = IMG_SaveTGA(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveTGA_IO(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = IMG_SaveTGA_IO(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_SaveTyped_IO(lua_State *L)
{
    (void)L;
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_IOStream");
    bool a2 = (bool)lua_toboolean(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = IMG_SaveTyped_IO(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_Version(lua_State *L)
{
    (void)L;
    int rv = IMG_Version();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_IMG_isANI(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isANI(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isBMP(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isBMP(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isCUR(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isCUR(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isGIF(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isGIF(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isICO(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isICO(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isJPG(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isJPG(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isLBM(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isLBM(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isPCX(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isPCX(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isPNG(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isPNG(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isPNM(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isPNM(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isQOI(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isQOI(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isSVG(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isSVG(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isXCF(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isXCF(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isXPM(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isXPM(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_IMG_isXV(lua_State *L)
{
    (void)L;
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_IOStream");
    bool rv = IMG_isXV(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

int SDLStaticGen_OpenLua_img(lua_State *L);
int SDLStaticGen_OpenLua_img(lua_State *L)
{
    lua_createtable(L, 0, 81);
    lua_pushcfunction(L, GenL_IMG_AddAnimationEncoderFrame);
    lua_setfield(L, -2, "AddAnimationEncoderFrame");
    lua_pushcfunction(L, GenL_IMG_CloseAnimationDecoder);
    lua_setfield(L, -2, "CloseAnimationDecoder");
    lua_pushcfunction(L, GenL_IMG_CloseAnimationEncoder);
    lua_setfield(L, -2, "CloseAnimationEncoder");
    lua_pushcfunction(L, GenL_IMG_CreateAnimatedCursor);
    lua_setfield(L, -2, "CreateAnimatedCursor");
    lua_pushcfunction(L, GenL_IMG_CreateAnimationDecoder);
    lua_setfield(L, -2, "CreateAnimationDecoder");
    lua_pushcfunction(L, GenL_IMG_CreateAnimationDecoderWithProperties);
    lua_setfield(L, -2, "CreateAnimationDecoderWithProperties");
    lua_pushcfunction(L, GenL_IMG_CreateAnimationDecoder_IO);
    lua_setfield(L, -2, "CreateAnimationDecoder_IO");
    lua_pushcfunction(L, GenL_IMG_CreateAnimationEncoder);
    lua_setfield(L, -2, "CreateAnimationEncoder");
    lua_pushcfunction(L, GenL_IMG_CreateAnimationEncoderWithProperties);
    lua_setfield(L, -2, "CreateAnimationEncoderWithProperties");
    lua_pushcfunction(L, GenL_IMG_CreateAnimationEncoder_IO);
    lua_setfield(L, -2, "CreateAnimationEncoder_IO");
    lua_pushcfunction(L, GenL_IMG_FreeAnimation);
    lua_setfield(L, -2, "FreeAnimation");
    lua_pushcfunction(L, GenL_IMG_GetAnimationDecoderProperties);
    lua_setfield(L, -2, "GetAnimationDecoderProperties");
    lua_pushcfunction(L, GenL_IMG_GetAnimationDecoderStatus);
    lua_setfield(L, -2, "GetAnimationDecoderStatus");
    lua_pushcfunction(L, GenL_IMG_GetClipboardImage);
    lua_setfield(L, -2, "GetClipboardImage");
    lua_pushcfunction(L, GenL_IMG_Load);
    lua_setfield(L, -2, "Load");
    lua_pushcfunction(L, GenL_IMG_LoadANIAnimation_IO);
    lua_setfield(L, -2, "LoadANIAnimation_IO");
    lua_pushcfunction(L, GenL_IMG_LoadAnimation);
    lua_setfield(L, -2, "LoadAnimation");
    lua_pushcfunction(L, GenL_IMG_LoadAnimationTyped_IO);
    lua_setfield(L, -2, "LoadAnimationTyped_IO");
    lua_pushcfunction(L, GenL_IMG_LoadAnimation_IO);
    lua_setfield(L, -2, "LoadAnimation_IO");
    lua_pushcfunction(L, GenL_IMG_LoadBMP_IO);
    lua_setfield(L, -2, "LoadBMP_IO");
    lua_pushcfunction(L, GenL_IMG_LoadCUR_IO);
    lua_setfield(L, -2, "LoadCUR_IO");
    lua_pushcfunction(L, GenL_IMG_LoadGIFAnimation_IO);
    lua_setfield(L, -2, "LoadGIFAnimation_IO");
    lua_pushcfunction(L, GenL_IMG_LoadGIF_IO);
    lua_setfield(L, -2, "LoadGIF_IO");
    lua_pushcfunction(L, GenL_IMG_LoadGPUTexture);
    lua_setfield(L, -2, "LoadGPUTexture");
    lua_pushcfunction(L, GenL_IMG_LoadGPUTextureTyped_IO);
    lua_setfield(L, -2, "LoadGPUTextureTyped_IO");
    lua_pushcfunction(L, GenL_IMG_LoadGPUTexture_IO);
    lua_setfield(L, -2, "LoadGPUTexture_IO");
    lua_pushcfunction(L, GenL_IMG_LoadICO_IO);
    lua_setfield(L, -2, "LoadICO_IO");
    lua_pushcfunction(L, GenL_IMG_LoadJPG_IO);
    lua_setfield(L, -2, "LoadJPG_IO");
    lua_pushcfunction(L, GenL_IMG_LoadLBM_IO);
    lua_setfield(L, -2, "LoadLBM_IO");
    lua_pushcfunction(L, GenL_IMG_LoadPCX_IO);
    lua_setfield(L, -2, "LoadPCX_IO");
    lua_pushcfunction(L, GenL_IMG_LoadPNG_IO);
    lua_setfield(L, -2, "LoadPNG_IO");
    lua_pushcfunction(L, GenL_IMG_LoadPNM_IO);
    lua_setfield(L, -2, "LoadPNM_IO");
    lua_pushcfunction(L, GenL_IMG_LoadQOI_IO);
    lua_setfield(L, -2, "LoadQOI_IO");
    lua_pushcfunction(L, GenL_IMG_LoadSVG_IO);
    lua_setfield(L, -2, "LoadSVG_IO");
    lua_pushcfunction(L, GenL_IMG_LoadSizedSVG_IO);
    lua_setfield(L, -2, "LoadSizedSVG_IO");
    lua_pushcfunction(L, GenL_IMG_LoadTGA_IO);
    lua_setfield(L, -2, "LoadTGA_IO");
    lua_pushcfunction(L, GenL_IMG_LoadTexture);
    lua_setfield(L, -2, "LoadTexture");
    lua_pushcfunction(L, GenL_IMG_LoadTextureTyped_IO);
    lua_setfield(L, -2, "LoadTextureTyped_IO");
    lua_pushcfunction(L, GenL_IMG_LoadTexture_IO);
    lua_setfield(L, -2, "LoadTexture_IO");
    lua_pushcfunction(L, GenL_IMG_LoadTyped_IO);
    lua_setfield(L, -2, "LoadTyped_IO");
    lua_pushcfunction(L, GenL_IMG_LoadXCF_IO);
    lua_setfield(L, -2, "LoadXCF_IO");
    lua_pushcfunction(L, GenL_IMG_LoadXPM_IO);
    lua_setfield(L, -2, "LoadXPM_IO");
    lua_pushcfunction(L, GenL_IMG_LoadXV_IO);
    lua_setfield(L, -2, "LoadXV_IO");
    lua_pushcfunction(L, GenL_IMG_Load_IO);
    lua_setfield(L, -2, "Load_IO");
    lua_pushcfunction(L, GenL_IMG_ResetAnimationDecoder);
    lua_setfield(L, -2, "ResetAnimationDecoder");
    lua_pushcfunction(L, GenL_IMG_Save);
    lua_setfield(L, -2, "Save");
    lua_pushcfunction(L, GenL_IMG_SaveANIAnimation_IO);
    lua_setfield(L, -2, "SaveANIAnimation_IO");
    lua_pushcfunction(L, GenL_IMG_SaveAnimation);
    lua_setfield(L, -2, "SaveAnimation");
    lua_pushcfunction(L, GenL_IMG_SaveAnimationTyped_IO);
    lua_setfield(L, -2, "SaveAnimationTyped_IO");
    lua_pushcfunction(L, GenL_IMG_SaveBMP);
    lua_setfield(L, -2, "SaveBMP");
    lua_pushcfunction(L, GenL_IMG_SaveBMP_IO);
    lua_setfield(L, -2, "SaveBMP_IO");
    lua_pushcfunction(L, GenL_IMG_SaveCUR);
    lua_setfield(L, -2, "SaveCUR");
    lua_pushcfunction(L, GenL_IMG_SaveCUR_IO);
    lua_setfield(L, -2, "SaveCUR_IO");
    lua_pushcfunction(L, GenL_IMG_SaveGIF);
    lua_setfield(L, -2, "SaveGIF");
    lua_pushcfunction(L, GenL_IMG_SaveGIFAnimation_IO);
    lua_setfield(L, -2, "SaveGIFAnimation_IO");
    lua_pushcfunction(L, GenL_IMG_SaveGIF_IO);
    lua_setfield(L, -2, "SaveGIF_IO");
    lua_pushcfunction(L, GenL_IMG_SaveICO);
    lua_setfield(L, -2, "SaveICO");
    lua_pushcfunction(L, GenL_IMG_SaveICO_IO);
    lua_setfield(L, -2, "SaveICO_IO");
    lua_pushcfunction(L, GenL_IMG_SaveJPG);
    lua_setfield(L, -2, "SaveJPG");
    lua_pushcfunction(L, GenL_IMG_SaveJPG_IO);
    lua_setfield(L, -2, "SaveJPG_IO");
    lua_pushcfunction(L, GenL_IMG_SavePNG);
    lua_setfield(L, -2, "SavePNG");
    lua_pushcfunction(L, GenL_IMG_SavePNG_IO);
    lua_setfield(L, -2, "SavePNG_IO");
    lua_pushcfunction(L, GenL_IMG_SaveTGA);
    lua_setfield(L, -2, "SaveTGA");
    lua_pushcfunction(L, GenL_IMG_SaveTGA_IO);
    lua_setfield(L, -2, "SaveTGA_IO");
    lua_pushcfunction(L, GenL_IMG_SaveTyped_IO);
    lua_setfield(L, -2, "SaveTyped_IO");
    lua_pushcfunction(L, GenL_IMG_Version);
    lua_setfield(L, -2, "Version");
    lua_pushcfunction(L, GenL_IMG_isANI);
    lua_setfield(L, -2, "isANI");
    lua_pushcfunction(L, GenL_IMG_isBMP);
    lua_setfield(L, -2, "isBMP");
    lua_pushcfunction(L, GenL_IMG_isCUR);
    lua_setfield(L, -2, "isCUR");
    lua_pushcfunction(L, GenL_IMG_isGIF);
    lua_setfield(L, -2, "isGIF");
    lua_pushcfunction(L, GenL_IMG_isICO);
    lua_setfield(L, -2, "isICO");
    lua_pushcfunction(L, GenL_IMG_isJPG);
    lua_setfield(L, -2, "isJPG");
    lua_pushcfunction(L, GenL_IMG_isLBM);
    lua_setfield(L, -2, "isLBM");
    lua_pushcfunction(L, GenL_IMG_isPCX);
    lua_setfield(L, -2, "isPCX");
    lua_pushcfunction(L, GenL_IMG_isPNG);
    lua_setfield(L, -2, "isPNG");
    lua_pushcfunction(L, GenL_IMG_isPNM);
    lua_setfield(L, -2, "isPNM");
    lua_pushcfunction(L, GenL_IMG_isQOI);
    lua_setfield(L, -2, "isQOI");
    lua_pushcfunction(L, GenL_IMG_isSVG);
    lua_setfield(L, -2, "isSVG");
    lua_pushcfunction(L, GenL_IMG_isXCF);
    lua_setfield(L, -2, "isXCF");
    lua_pushcfunction(L, GenL_IMG_isXPM);
    lua_setfield(L, -2, "isXPM");
    lua_pushcfunction(L, GenL_IMG_isXV);
    lua_setfield(L, -2, "isXV");
    lua_pushinteger(L, (lua_Integer)IMG_DECODER_STATUS_INVALID);
    lua_setfield(L, -2, "DECODER_STATUS_INVALID");
    lua_pushinteger(L, (lua_Integer)IMG_DECODER_STATUS_OK);
    lua_setfield(L, -2, "DECODER_STATUS_OK");
    lua_pushinteger(L, (lua_Integer)IMG_DECODER_STATUS_FAILED);
    lua_setfield(L, -2, "DECODER_STATUS_FAILED");
    lua_pushinteger(L, (lua_Integer)IMG_DECODER_STATUS_COMPLETE);
    lua_setfield(L, -2, "DECODER_STATUS_COMPLETE");
    lua_setglobal(L, "IMG");
    return 0;
}
