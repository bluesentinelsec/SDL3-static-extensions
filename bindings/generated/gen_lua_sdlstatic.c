/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for SDLStatic modules. */
#include "../src/gen_support_lua.h"

#include <SDLStatic/base64.h>
#include <SDLStatic/bidi.h>
#include <SDLStatic/chiptune.h>
#include <SDLStatic/compress.h>
#include <SDLStatic/crypto.h>
#include <SDLStatic/debug_text.h>
#include <SDLStatic/dialog.h>
#include <SDLStatic/engine.h>
#include <SDLStatic/engine_actor.h>
#include <SDLStatic/engine_assets.h>
#include <SDLStatic/engine_binding.h>
#include <SDLStatic/engine_camera.h>
#include <SDLStatic/engine_config.h>
#include <SDLStatic/engine_graphics.h>
#include <SDLStatic/engine_input.h>
#include <SDLStatic/engine_light.h>
#include <SDLStatic/engine_media.h>
#include <SDLStatic/engine_physics.h>
#include <SDLStatic/engine_render.h>
#include <SDLStatic/engine_save.h>
#include <SDLStatic/engine_scene.h>
#include <SDLStatic/engine_script.h>
#include <SDLStatic/engine_text.h>
#include <SDLStatic/gpu_primitives.h>
#include <SDLStatic/gui.h>
#include <SDLStatic/gui_grid.h>
#include <SDLStatic/light.h>
#include <SDLStatic/physics_build.h>
#include <SDLStatic/physics_draw.h>
#include <SDLStatic/regex.h>
#include <SDLStatic/signals.h>
#include <SDLStatic/textfile.h>
#include <SDLStatic/tiled.h>
#include <SDLStatic/vfs.h>
#include <string.h>

static void GenRead_SDLStatic_ActorMessage(lua_State *L, int idx, SDLStatic_ActorMessage *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->id = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "id");
    out->sender = (SDLStatic_ActorId)SDLStaticGen_LuaFieldInt(L, idx, "sender");
    out->a = (float)SDLStaticGen_LuaFieldNum(L, idx, "a");
    out->b = (float)SDLStaticGen_LuaFieldNum(L, idx, "b");
    out->value = (Sint64)SDLStaticGen_LuaFieldInt(L, idx, "value");
}

static void GenRead_SDLStatic_ActorTransform(lua_State *L, int idx, SDLStatic_ActorTransform *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (float)SDLStaticGen_LuaFieldNum(L, idx, "x");
    out->y = (float)SDLStaticGen_LuaFieldNum(L, idx, "y");
    out->rotation = (float)SDLStaticGen_LuaFieldNum(L, idx, "rotation");
    out->scale_x = (float)SDLStaticGen_LuaFieldNum(L, idx, "scale_x");
    out->scale_y = (float)SDLStaticGen_LuaFieldNum(L, idx, "scale_y");
}

static void GenPush_SDLStatic_ActorTransform(lua_State *L, const SDLStatic_ActorTransform *in)
{
    lua_createtable(L, 0, 5);
    lua_pushnumber(L, (lua_Number)in->x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, (lua_Number)in->y);
    lua_setfield(L, -2, "y");
    lua_pushnumber(L, (lua_Number)in->rotation);
    lua_setfield(L, -2, "rotation");
    lua_pushnumber(L, (lua_Number)in->scale_x);
    lua_setfield(L, -2, "scale_x");
    lua_pushnumber(L, (lua_Number)in->scale_y);
    lua_setfield(L, -2, "scale_y");
}

static void GenRead_SDLStatic_Binding(lua_State *L, int idx, SDLStatic_Binding *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->source = (SDLStatic_BindingSource)SDLStaticGen_LuaFieldInt(L, idx, "source");
    out->code = (int)SDLStaticGen_LuaFieldInt(L, idx, "code");
    out->sign = (int)SDLStaticGen_LuaFieldInt(L, idx, "sign");
    out->axis_half = (int)SDLStaticGen_LuaFieldInt(L, idx, "axis_half");
}

static void GenPush_SDLStatic_Binding(lua_State *L, const SDLStatic_Binding *in)
{
    lua_createtable(L, 0, 4);
    lua_pushinteger(L, (lua_Integer)in->source);
    lua_setfield(L, -2, "source");
    lua_pushinteger(L, (lua_Integer)in->code);
    lua_setfield(L, -2, "code");
    lua_pushinteger(L, (lua_Integer)in->sign);
    lua_setfield(L, -2, "sign");
    lua_pushinteger(L, (lua_Integer)in->axis_half);
    lua_setfield(L, -2, "axis_half");
}

static void GenRead_SDLStatic_BodyDef(lua_State *L, int idx, SDLStatic_BodyDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->type = (SDLStatic_BodyType)SDLStaticGen_LuaFieldInt(L, idx, "type");
    out->shape = (SDLStatic_ShapeType)SDLStaticGen_LuaFieldInt(L, idx, "shape");
    out->width = (float)SDLStaticGen_LuaFieldNum(L, idx, "width");
    out->height = (float)SDLStaticGen_LuaFieldNum(L, idx, "height");
    out->offset_x = (float)SDLStaticGen_LuaFieldNum(L, idx, "offset_x");
    out->offset_y = (float)SDLStaticGen_LuaFieldNum(L, idx, "offset_y");
    out->density = (float)SDLStaticGen_LuaFieldNum(L, idx, "density");
    out->friction = (float)SDLStaticGen_LuaFieldNum(L, idx, "friction");
    out->restitution = (float)SDLStaticGen_LuaFieldNum(L, idx, "restitution");
    out->fixed_rotation = (bool)SDLStaticGen_LuaFieldBool(L, idx, "fixed_rotation");
    out->sensor = (bool)SDLStaticGen_LuaFieldBool(L, idx, "sensor");
    out->gravity_scale = (float)SDLStaticGen_LuaFieldNum(L, idx, "gravity_scale");
    out->damping = (float)SDLStaticGen_LuaFieldNum(L, idx, "damping");
    out->category = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "category");
    out->collides_with = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "collides_with");
    out->bullet = (bool)SDLStaticGen_LuaFieldBool(L, idx, "bullet");
}

static void GenPush_SDLStatic_BodyDef(lua_State *L, const SDLStatic_BodyDef *in)
{
    lua_createtable(L, 0, 16);
    lua_pushinteger(L, (lua_Integer)in->type);
    lua_setfield(L, -2, "type");
    lua_pushinteger(L, (lua_Integer)in->shape);
    lua_setfield(L, -2, "shape");
    lua_pushnumber(L, (lua_Number)in->width);
    lua_setfield(L, -2, "width");
    lua_pushnumber(L, (lua_Number)in->height);
    lua_setfield(L, -2, "height");
    lua_pushnumber(L, (lua_Number)in->offset_x);
    lua_setfield(L, -2, "offset_x");
    lua_pushnumber(L, (lua_Number)in->offset_y);
    lua_setfield(L, -2, "offset_y");
    lua_pushnumber(L, (lua_Number)in->density);
    lua_setfield(L, -2, "density");
    lua_pushnumber(L, (lua_Number)in->friction);
    lua_setfield(L, -2, "friction");
    lua_pushnumber(L, (lua_Number)in->restitution);
    lua_setfield(L, -2, "restitution");
    lua_pushboolean(L, (int)in->fixed_rotation);
    lua_setfield(L, -2, "fixed_rotation");
    lua_pushboolean(L, (int)in->sensor);
    lua_setfield(L, -2, "sensor");
    lua_pushnumber(L, (lua_Number)in->gravity_scale);
    lua_setfield(L, -2, "gravity_scale");
    lua_pushnumber(L, (lua_Number)in->damping);
    lua_setfield(L, -2, "damping");
    lua_pushinteger(L, (lua_Integer)in->category);
    lua_setfield(L, -2, "category");
    lua_pushinteger(L, (lua_Integer)in->collides_with);
    lua_setfield(L, -2, "collides_with");
    lua_pushboolean(L, (int)in->bullet);
    lua_setfield(L, -2, "bullet");
}

static void GenRead_SDL_FRect(lua_State *L, int idx, SDL_FRect *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (float)SDLStaticGen_LuaFieldNum(L, idx, "x");
    out->y = (float)SDLStaticGen_LuaFieldNum(L, idx, "y");
    out->w = (float)SDLStaticGen_LuaFieldNum(L, idx, "w");
    out->h = (float)SDLStaticGen_LuaFieldNum(L, idx, "h");
}

static void GenPush_SDL_FRect(lua_State *L, const SDL_FRect *in)
{
    lua_createtable(L, 0, 4);
    lua_pushnumber(L, (lua_Number)in->x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, (lua_Number)in->y);
    lua_setfield(L, -2, "y");
    lua_pushnumber(L, (lua_Number)in->w);
    lua_setfield(L, -2, "w");
    lua_pushnumber(L, (lua_Number)in->h);
    lua_setfield(L, -2, "h");
}

static void GenRead_SDLStatic_Camera(lua_State *L, int idx, SDLStatic_Camera *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (float)SDLStaticGen_LuaFieldNum(L, idx, "x");
    out->y = (float)SDLStaticGen_LuaFieldNum(L, idx, "y");
    out->zoom = (float)SDLStaticGen_LuaFieldNum(L, idx, "zoom");
    out->target_x = (float)SDLStaticGen_LuaFieldNum(L, idx, "target_x");
    out->target_y = (float)SDLStaticGen_LuaFieldNum(L, idx, "target_y");
    out->smoothing = (float)SDLStaticGen_LuaFieldNum(L, idx, "smoothing");
    out->deadzone_w = (float)SDLStaticGen_LuaFieldNum(L, idx, "deadzone_w");
    out->deadzone_h = (float)SDLStaticGen_LuaFieldNum(L, idx, "deadzone_h");
    lua_getfield(L, idx, "bounds");
    GenRead_SDL_FRect(L, lua_gettop(L), &out->bounds);
    lua_pop(L, 1);
    out->shake_amount = (float)SDLStaticGen_LuaFieldNum(L, idx, "shake_amount");
    out->shake_seconds = (float)SDLStaticGen_LuaFieldNum(L, idx, "shake_seconds");
    out->shake_remaining = (float)SDLStaticGen_LuaFieldNum(L, idx, "shake_remaining");
    lua_getfield(L, idx, "viewport");
    GenRead_SDL_FRect(L, lua_gettop(L), &out->viewport);
    lua_pop(L, 1);
    lua_getfield(L, idx, "visible");
    GenRead_SDL_FRect(L, lua_gettop(L), &out->visible);
    lua_pop(L, 1);
}

static void GenPush_SDLStatic_Camera(lua_State *L, const SDLStatic_Camera *in)
{
    lua_createtable(L, 0, 14);
    lua_pushnumber(L, (lua_Number)in->x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, (lua_Number)in->y);
    lua_setfield(L, -2, "y");
    lua_pushnumber(L, (lua_Number)in->zoom);
    lua_setfield(L, -2, "zoom");
    lua_pushnumber(L, (lua_Number)in->target_x);
    lua_setfield(L, -2, "target_x");
    lua_pushnumber(L, (lua_Number)in->target_y);
    lua_setfield(L, -2, "target_y");
    lua_pushnumber(L, (lua_Number)in->smoothing);
    lua_setfield(L, -2, "smoothing");
    lua_pushnumber(L, (lua_Number)in->deadzone_w);
    lua_setfield(L, -2, "deadzone_w");
    lua_pushnumber(L, (lua_Number)in->deadzone_h);
    lua_setfield(L, -2, "deadzone_h");
    GenPush_SDL_FRect(L, &in->bounds);
    lua_setfield(L, -2, "bounds");
    lua_pushnumber(L, (lua_Number)in->shake_amount);
    lua_setfield(L, -2, "shake_amount");
    lua_pushnumber(L, (lua_Number)in->shake_seconds);
    lua_setfield(L, -2, "shake_seconds");
    lua_pushnumber(L, (lua_Number)in->shake_remaining);
    lua_setfield(L, -2, "shake_remaining");
    GenPush_SDL_FRect(L, &in->viewport);
    lua_setfield(L, -2, "viewport");
    GenPush_SDL_FRect(L, &in->visible);
    lua_setfield(L, -2, "visible");
}

static void GenRead_SDLStatic_ChipToneDesc(lua_State *L, int idx, SDLStatic_ChipToneDesc *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->wave = (SDLStatic_ChipWave)SDLStaticGen_LuaFieldInt(L, idx, "wave");
    out->freq_hz = (float)SDLStaticGen_LuaFieldNum(L, idx, "freq_hz");
    out->freq_end_hz = (float)SDLStaticGen_LuaFieldNum(L, idx, "freq_end_hz");
    out->duration_ms = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "duration_ms");
    out->volume = (float)SDLStaticGen_LuaFieldNum(L, idx, "volume");
    out->attack_ms = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "attack_ms");
    out->release_ms = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "release_ms");
    out->vibrato_hz = (float)SDLStaticGen_LuaFieldNum(L, idx, "vibrato_hz");
    out->vibrato_semitones = (float)SDLStaticGen_LuaFieldNum(L, idx, "vibrato_semitones");
}

static void GenRead_SDLStatic_GraphicsSettings(lua_State *L, int idx, SDLStatic_GraphicsSettings *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->vsync = (bool)SDLStaticGen_LuaFieldBool(L, idx, "vsync");
    out->max_fps = (int)SDLStaticGen_LuaFieldInt(L, idx, "max_fps");
    out->window_mode = (SDLStatic_WindowMode)SDLStaticGen_LuaFieldInt(L, idx, "window_mode");
    out->window_width = (int)SDLStaticGen_LuaFieldInt(L, idx, "window_width");
    out->window_height = (int)SDLStaticGen_LuaFieldInt(L, idx, "window_height");
    out->display = (int)SDLStaticGen_LuaFieldInt(L, idx, "display");
    out->presentation = (SDLStatic_EnginePresentation)SDLStaticGen_LuaFieldInt(L, idx, "presentation");
    out->render_scale = (float)SDLStaticGen_LuaFieldNum(L, idx, "render_scale");
    out->filter = (SDLStatic_TextureFilter)SDLStaticGen_LuaFieldInt(L, idx, "filter");
    out->particles = (SDLStatic_GraphicsQuality)SDLStaticGen_LuaFieldInt(L, idx, "particles");
    out->dynamic_lights = (SDLStatic_GraphicsQuality)SDLStaticGen_LuaFieldInt(L, idx, "dynamic_lights");
    out->shadows = (SDLStatic_GraphicsQuality)SDLStaticGen_LuaFieldInt(L, idx, "shadows");
    out->bloom = (float)SDLStaticGen_LuaFieldNum(L, idx, "bloom");
    out->bloom_threshold = (float)SDLStaticGen_LuaFieldNum(L, idx, "bloom_threshold");
    out->crt = (float)SDLStaticGen_LuaFieldNum(L, idx, "crt");
    out->crt_curvature = (float)SDLStaticGen_LuaFieldNum(L, idx, "crt_curvature");
    out->pixelation = (int)SDLStaticGen_LuaFieldInt(L, idx, "pixelation");
    out->chromatic_aberration = (float)SDLStaticGen_LuaFieldNum(L, idx, "chromatic_aberration");
    out->antialias = (SDLStatic_GraphicsAA)SDLStaticGen_LuaFieldInt(L, idx, "antialias");
    out->brightness = (float)SDLStaticGen_LuaFieldNum(L, idx, "brightness");
    out->contrast = (float)SDLStaticGen_LuaFieldNum(L, idx, "contrast");
    out->saturation = (float)SDLStaticGen_LuaFieldNum(L, idx, "saturation");
    out->color_blind = (SDLStatic_ColorBlindMode)SDLStaticGen_LuaFieldInt(L, idx, "color_blind");
    out->reduced_flashing = (bool)SDLStaticGen_LuaFieldBool(L, idx, "reduced_flashing");
    out->screen_shake = (float)SDLStaticGen_LuaFieldNum(L, idx, "screen_shake");
    out->ui_scale = (float)SDLStaticGen_LuaFieldNum(L, idx, "ui_scale");
}

static void GenPush_SDLStatic_GraphicsSettings(lua_State *L, const SDLStatic_GraphicsSettings *in)
{
    lua_createtable(L, 0, 26);
    lua_pushboolean(L, (int)in->vsync);
    lua_setfield(L, -2, "vsync");
    lua_pushinteger(L, (lua_Integer)in->max_fps);
    lua_setfield(L, -2, "max_fps");
    lua_pushinteger(L, (lua_Integer)in->window_mode);
    lua_setfield(L, -2, "window_mode");
    lua_pushinteger(L, (lua_Integer)in->window_width);
    lua_setfield(L, -2, "window_width");
    lua_pushinteger(L, (lua_Integer)in->window_height);
    lua_setfield(L, -2, "window_height");
    lua_pushinteger(L, (lua_Integer)in->display);
    lua_setfield(L, -2, "display");
    lua_pushinteger(L, (lua_Integer)in->presentation);
    lua_setfield(L, -2, "presentation");
    lua_pushnumber(L, (lua_Number)in->render_scale);
    lua_setfield(L, -2, "render_scale");
    lua_pushinteger(L, (lua_Integer)in->filter);
    lua_setfield(L, -2, "filter");
    lua_pushinteger(L, (lua_Integer)in->particles);
    lua_setfield(L, -2, "particles");
    lua_pushinteger(L, (lua_Integer)in->dynamic_lights);
    lua_setfield(L, -2, "dynamic_lights");
    lua_pushinteger(L, (lua_Integer)in->shadows);
    lua_setfield(L, -2, "shadows");
    lua_pushnumber(L, (lua_Number)in->bloom);
    lua_setfield(L, -2, "bloom");
    lua_pushnumber(L, (lua_Number)in->bloom_threshold);
    lua_setfield(L, -2, "bloom_threshold");
    lua_pushnumber(L, (lua_Number)in->crt);
    lua_setfield(L, -2, "crt");
    lua_pushnumber(L, (lua_Number)in->crt_curvature);
    lua_setfield(L, -2, "crt_curvature");
    lua_pushinteger(L, (lua_Integer)in->pixelation);
    lua_setfield(L, -2, "pixelation");
    lua_pushnumber(L, (lua_Number)in->chromatic_aberration);
    lua_setfield(L, -2, "chromatic_aberration");
    lua_pushinteger(L, (lua_Integer)in->antialias);
    lua_setfield(L, -2, "antialias");
    lua_pushnumber(L, (lua_Number)in->brightness);
    lua_setfield(L, -2, "brightness");
    lua_pushnumber(L, (lua_Number)in->contrast);
    lua_setfield(L, -2, "contrast");
    lua_pushnumber(L, (lua_Number)in->saturation);
    lua_setfield(L, -2, "saturation");
    lua_pushinteger(L, (lua_Integer)in->color_blind);
    lua_setfield(L, -2, "color_blind");
    lua_pushboolean(L, (int)in->reduced_flashing);
    lua_setfield(L, -2, "reduced_flashing");
    lua_pushnumber(L, (lua_Number)in->screen_shake);
    lua_setfield(L, -2, "screen_shake");
    lua_pushnumber(L, (lua_Number)in->ui_scale);
    lua_setfield(L, -2, "ui_scale");
}

static void GenRead_SDL_FColor(lua_State *L, int idx, SDL_FColor *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->r = (float)SDLStaticGen_LuaFieldNum(L, idx, "r");
    out->g = (float)SDLStaticGen_LuaFieldNum(L, idx, "g");
    out->b = (float)SDLStaticGen_LuaFieldNum(L, idx, "b");
    out->a = (float)SDLStaticGen_LuaFieldNum(L, idx, "a");
}

static void GenPush_SDL_FColor(lua_State *L, const SDL_FColor *in)
{
    lua_createtable(L, 0, 4);
    lua_pushnumber(L, (lua_Number)in->r);
    lua_setfield(L, -2, "r");
    lua_pushnumber(L, (lua_Number)in->g);
    lua_setfield(L, -2, "g");
    lua_pushnumber(L, (lua_Number)in->b);
    lua_setfield(L, -2, "b");
    lua_pushnumber(L, (lua_Number)in->a);
    lua_setfield(L, -2, "a");
}

static void GenRead_SDLStatic_Light(lua_State *L, int idx, SDLStatic_Light *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (float)SDLStaticGen_LuaFieldNum(L, idx, "x");
    out->y = (float)SDLStaticGen_LuaFieldNum(L, idx, "y");
    out->radius = (float)SDLStaticGen_LuaFieldNum(L, idx, "radius");
    lua_getfield(L, idx, "color");
    GenRead_SDL_FColor(L, lua_gettop(L), &out->color);
    lua_pop(L, 1);
    out->falloff = (float)SDLStaticGen_LuaFieldNum(L, idx, "falloff");
    out->angle = (float)SDLStaticGen_LuaFieldNum(L, idx, "angle");
    out->spread = (float)SDLStaticGen_LuaFieldNum(L, idx, "spread");
    out->flicker = (float)SDLStaticGen_LuaFieldNum(L, idx, "flicker");
    out->seed = (Uint32)SDLStaticGen_LuaFieldInt(L, idx, "seed");
    out->no_shadows = (bool)SDLStaticGen_LuaFieldBool(L, idx, "no_shadows");
}

static void GenRead_SDLStatic_LightDef(lua_State *L, int idx, SDLStatic_LightDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->radius = (float)SDLStaticGen_LuaFieldNum(L, idx, "radius");
    lua_getfield(L, idx, "color");
    GenRead_SDL_FColor(L, lua_gettop(L), &out->color);
    lua_pop(L, 1);
    out->offset_x = (float)SDLStaticGen_LuaFieldNum(L, idx, "offset_x");
    out->offset_y = (float)SDLStaticGen_LuaFieldNum(L, idx, "offset_y");
    out->falloff = (float)SDLStaticGen_LuaFieldNum(L, idx, "falloff");
    out->cone_direction = (float)SDLStaticGen_LuaFieldNum(L, idx, "cone_direction");
    out->cone_width = (float)SDLStaticGen_LuaFieldNum(L, idx, "cone_width");
    out->flicker = (float)SDLStaticGen_LuaFieldNum(L, idx, "flicker");
    out->no_shadows = (bool)SDLStaticGen_LuaFieldBool(L, idx, "no_shadows");
    out->enabled = (bool)SDLStaticGen_LuaFieldBool(L, idx, "enabled");
}

static void GenPush_SDLStatic_LightDef(lua_State *L, const SDLStatic_LightDef *in)
{
    lua_createtable(L, 0, 10);
    lua_pushnumber(L, (lua_Number)in->radius);
    lua_setfield(L, -2, "radius");
    GenPush_SDL_FColor(L, &in->color);
    lua_setfield(L, -2, "color");
    lua_pushnumber(L, (lua_Number)in->offset_x);
    lua_setfield(L, -2, "offset_x");
    lua_pushnumber(L, (lua_Number)in->offset_y);
    lua_setfield(L, -2, "offset_y");
    lua_pushnumber(L, (lua_Number)in->falloff);
    lua_setfield(L, -2, "falloff");
    lua_pushnumber(L, (lua_Number)in->cone_direction);
    lua_setfield(L, -2, "cone_direction");
    lua_pushnumber(L, (lua_Number)in->cone_width);
    lua_setfield(L, -2, "cone_width");
    lua_pushnumber(L, (lua_Number)in->flicker);
    lua_setfield(L, -2, "flicker");
    lua_pushboolean(L, (int)in->no_shadows);
    lua_setfield(L, -2, "no_shadows");
    lua_pushboolean(L, (int)in->enabled);
    lua_setfield(L, -2, "enabled");
}

static void GenRead_SDLStatic_PhysicsDrawConfig(lua_State *L, int idx, SDLStatic_PhysicsDrawConfig *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->pixels_per_meter = (float)SDLStaticGen_LuaFieldNum(L, idx, "pixels_per_meter");
    out->offset_x = (float)SDLStaticGen_LuaFieldNum(L, idx, "offset_x");
    out->offset_y = (float)SDLStaticGen_LuaFieldNum(L, idx, "offset_y");
    out->draw_joints = (bool)SDLStaticGen_LuaFieldBool(L, idx, "draw_joints");
}

static void GenPush_SDLStatic_RayHit(lua_State *L, const SDLStatic_RayHit *in)
{
    lua_createtable(L, 0, 7);
    lua_pushboolean(L, (int)in->hit);
    lua_setfield(L, -2, "hit");
    lua_pushinteger(L, (lua_Integer)in->actor);
    lua_setfield(L, -2, "actor");
    lua_pushnumber(L, (lua_Number)in->x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, (lua_Number)in->y);
    lua_setfield(L, -2, "y");
    lua_pushnumber(L, (lua_Number)in->normal_x);
    lua_setfield(L, -2, "normal_x");
    lua_pushnumber(L, (lua_Number)in->normal_y);
    lua_setfield(L, -2, "normal_y");
    lua_pushnumber(L, (lua_Number)in->fraction);
    lua_setfield(L, -2, "fraction");
}

static void GenPush_SDLStatic_RenderStats(lua_State *L, const SDLStatic_RenderStats *in)
{
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, (lua_Integer)in->considered);
    lua_setfield(L, -2, "considered");
    lua_pushinteger(L, (lua_Integer)in->culled);
    lua_setfield(L, -2, "culled");
    lua_pushinteger(L, (lua_Integer)in->drawn);
    lua_setfield(L, -2, "drawn");
}

static void GenPush_SDLStatic_SaveInfo(lua_State *L, const SDLStatic_SaveInfo *in)
{
    lua_createtable(L, 0, 4);
    lua_pushboolean(L, (int)in->exists);
    lua_setfield(L, -2, "exists");
    lua_pushinteger(L, (lua_Integer)in->size);
    lua_setfield(L, -2, "size");
    lua_pushinteger(L, (lua_Integer)in->modified);
    lua_setfield(L, -2, "modified");
    lua_createtable(L, (int)(128), 0);
    for (int gi = 0; gi < (int)(128); ++gi) {
        lua_pushinteger(L, (lua_Integer)in->label[gi]);
        lua_rawseti(L, -2, gi + 1);
    }
    lua_setfield(L, -2, "label");
}

static void GenRead_SDL_Color(lua_State *L, int idx, SDL_Color *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->r = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "r");
    out->g = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "g");
    out->b = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "b");
    out->a = (Uint8)SDLStaticGen_LuaFieldInt(L, idx, "a");
}

static void GenRead_b2BodyId(lua_State *L, int idx, b2BodyId *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->index1 = (int32_t)SDLStaticGen_LuaFieldInt(L, idx, "index1");
    out->world0 = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "world0");
    out->generation = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "generation");
}

static void GenRead_b2WorldId(lua_State *L, int idx, b2WorldId *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->index1 = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "index1");
    out->generation = (uint16_t)SDLStaticGen_LuaFieldInt(L, idx, "generation");
}

static void GenDtor_SDLStatic_FreeTiledMap(void *p)
{
    SDLStatic_TiledMap *typed = (SDLStatic_TiledMap *)p;
    SDLStatic_FreeTiledMap(typed);
}

static void GenDtor_SDLStatic_DestroyGui(void *p)
{
    SDLStatic_Gui *typed = (SDLStatic_Gui *)p;
    SDLStatic_DestroyGui(typed);
}

static void GenDtor_SDLStatic_DestroyRegex(void *p)
{
    SDLStatic_Regex *typed = (SDLStatic_Regex *)p;
    SDLStatic_DestroyRegex(typed);
}

static void GenDtor_SDLStatic_DestroyLightScene(void *p)
{
    SDLStatic_LightScene *typed = (SDLStatic_LightScene *)p;
    SDLStatic_DestroyLightScene(typed);
}

static int GenL_SDLStatic_ActionBind(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_Binding a2;
    GenRead_SDLStatic_Binding(L, 3, &a2);
    bool rv = SDLStatic_ActionBind(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionBindAxis(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_GamepadAxis a2 = (SDLStatic_GamepadAxis)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    bool rv = SDLStatic_ActionBindAxis(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionBindDirection(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_Direction a2 = (SDLStatic_Direction)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_ActionBindDirection(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionBindKey(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_Scancode a2 = (SDL_Scancode)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_ActionBindKey(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionBindKeySigned(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDL_Scancode a2 = (SDL_Scancode)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    bool rv = SDLStatic_ActionBindKeySigned(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionBindMouse(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_MouseButton a2 = (SDLStatic_MouseButton)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_ActionBindMouse(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionBindPad(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_GamepadButton a2 = (SDLStatic_GamepadButton)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_ActionBindPad(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionBindingAt(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDLStatic_Binding out3;
    memset(&out3, 0, sizeof(out3));
    bool rv = SDLStatic_ActionBindingAt(a0, a1, a2, &out3);
    lua_pushboolean(L, (int)rv);
    GenPush_SDLStatic_Binding(L, &out3);
    return 2;
}

static int GenL_SDLStatic_ActionBindingCount(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = SDLStatic_ActionBindingCount(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActionCapture(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_Binding out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDLStatic_ActionCapture(a0, a1, &out2);
    lua_pushboolean(L, (int)rv);
    GenPush_SDLStatic_Binding(L, &out2);
    return 2;
}

static int GenL_SDLStatic_ActionClear(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_ActionClear(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActionCount(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    int rv = SDLStatic_ActionCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActionDown(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ActionMap *a1 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 2, "SDLStatic_ActionMap");
    int a2 = (int)luaL_checkinteger(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = SDLStatic_ActionDown(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionMapCreate(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap * rv = SDLStatic_ActionMapCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_ActionMap");
    return 1;
}

static int GenL_SDLStatic_ActionMapDestroy(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    SDLStatic_ActionMapDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_ActionMapKeyboardPlayer(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    int rv = SDLStatic_ActionMapKeyboardPlayer(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActionMapLoad(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDLStatic_ActionMapLoad(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionMapLoadToml(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDLStatic_ActionMapLoadToml(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionMapSave(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDLStatic_ActionMapSave(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionMapSetKeyboardPlayer(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_ActionMapSetKeyboardPlayer(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActionMapToToml(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    char * rv = SDLStatic_ActionMapToToml(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDLStatic_ActionName(lua_State *L)
{
    (void)L;
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActionMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char * rv = SDLStatic_ActionName(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_ActionPressed(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ActionMap *a1 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 2, "SDLStatic_ActionMap");
    int a2 = (int)luaL_checkinteger(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = SDLStatic_ActionPressed(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionReleased(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ActionMap *a1 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 2, "SDLStatic_ActionMap");
    int a2 = (int)luaL_checkinteger(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = SDLStatic_ActionReleased(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActionValue(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ActionMap *a1 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 2, "SDLStatic_ActionMap");
    int a2 = (int)luaL_checkinteger(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    float rv = SDLStatic_ActionValue(a0, a1, a2, a3);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_ActionVector(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ActionMap *a1 = (SDLStatic_ActionMap *)SDLStaticGen_LuaCheckHandle(L, 2, "SDLStatic_ActionMap");
    int a2 = (int)luaL_checkinteger(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    const char *a4 = lua_isnoneornil(L, 5) ? NULL : luaL_checkstring(L, 5);
    float io5 = (float)luaL_optnumber(L, 6, 0);
    float io6 = (float)luaL_optnumber(L, 7, 0);
    SDLStatic_ActionVector(a0, a1, a2, a3, a4, &io5, &io6);
    lua_pushnumber(L, (lua_Number)io5);
    lua_pushnumber(L, (lua_Number)io6);
    return 2;
}

static int GenL_SDLStatic_ActorAddBody(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_BodyDef tmp1;
    const SDLStatic_BodyDef *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_BodyDef(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_ActorAddBody(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActorAddLight(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_LightDef tmp1;
    const SDLStatic_LightDef *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_LightDef(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_ActorAddLight(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActorAlive(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_ActorAlive(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActorAngularVelocity(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    float rv = SDLStatic_ActorAngularVelocity(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_ActorApplyForce(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_ActorApplyForce(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_ActorApplyImpulse(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_ActorApplyImpulse(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_ActorBodyBounds(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDL_FRect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDLStatic_ActorBodyBounds(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDL_FRect(L, &out1);
    return 2;
}

static int GenL_SDLStatic_ActorBroadcast(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_ActorTags a2 = (SDLStatic_ActorTags)luaL_checkinteger(L, 3);
    SDLStatic_ActorMessage tmp3;
    const SDLStatic_ActorMessage *a3 = NULL;
    if (!lua_isnoneornil(L, 4)) {
        GenRead_SDLStatic_ActorMessage(L, 4, &tmp3);
        a3 = &tmp3;
    }
    int rv = SDLStatic_ActorBroadcast(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActorChild(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_ActorId rv = SDLStatic_ActorChild(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActorChildCount(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    int rv = SDLStatic_ActorChildCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActorClear(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ActorClear(a0);
    return 0;
}

static int GenL_SDLStatic_ActorClearSprite(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorClearSprite(a0);
    return 0;
}

static int GenL_SDLStatic_ActorCount(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_ActorCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActorDefCreate(lua_State *L)
{
    (void)L;
    SDLStatic_ActorDef * rv = SDLStatic_ActorDefCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_ActorDef");
    return 1;
}

static int GenL_SDLStatic_ActorDefDestroy(lua_State *L)
{
    (void)L;
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActorDef");
    SDLStatic_ActorDefDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_ActorDefSetName(lua_State *L)
{
    (void)L;
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActorDef");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_ActorDefSetName(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActorDefSetParent(lua_State *L)
{
    (void)L;
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActorDef");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)luaL_checkinteger(L, 2);
    SDLStatic_ActorDefSetParent(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActorDefSetPosition(lua_State *L)
{
    (void)L;
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActorDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_ActorDefSetPosition(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_ActorDefSetRotation(lua_State *L)
{
    (void)L;
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActorDef");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_ActorDefSetRotation(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActorDefSetScale(lua_State *L)
{
    (void)L;
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActorDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_ActorDefSetScale(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_ActorDefSetStateSize(lua_State *L)
{
    (void)L;
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActorDef");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_ActorDefSetStateSize(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActorDefSetTags(lua_State *L)
{
    (void)L;
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActorDef");
    SDLStatic_ActorTags a1 = (SDLStatic_ActorTags)luaL_checkinteger(L, 2);
    SDLStatic_ActorDefSetTags(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActorDefSetType(lua_State *L)
{
    (void)L;
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_ActorDef");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_ActorDefSetType(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActorDestroy(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)luaL_checkinteger(L, 2);
    SDLStatic_ActorDestroy(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActorEnabled(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    bool rv = SDLStatic_ActorEnabled(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActorEngine(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_Engine * rv = SDLStatic_ActorEngine(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_Engine");
    return 1;
}

static int GenL_SDLStatic_ActorFindByName(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_ActorId rv = SDLStatic_ActorFindByName(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActorFindByType(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_ActorId rv = SDLStatic_ActorFindByType(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActorGet(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)luaL_checkinteger(L, 2);
    SDLStatic_Actor * rv = SDLStatic_ActorGet(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_Actor");
    return 1;
}

static int GenL_SDLStatic_ActorGetId(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorId rv = SDLStatic_ActorGetId(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActorGetTags(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorTags rv = SDLStatic_ActorGetTags(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActorHasBody(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    bool rv = SDLStatic_ActorHasBody(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActorHasTags(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorTags a1 = (SDLStatic_ActorTags)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_ActorHasTags(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActorLocal(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorTransform rv = SDLStatic_ActorLocal(a0);
    GenPush_SDLStatic_ActorTransform(L, &rv);
    return 1;
}

static int GenL_SDLStatic_ActorMove(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_ActorMove(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_ActorName(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    const char * rv = SDLStatic_ActorName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_ActorParent(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorId rv = SDLStatic_ActorParent(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActorQuery(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_ActorTags a2 = (SDLStatic_ActorTags)luaL_checkinteger(L, 3);
    SDLStatic_ActorId io3 = (SDLStatic_ActorId)luaL_optinteger(L, 4, 0);
    int a4 = (int)luaL_checkinteger(L, 5);
    int rv = SDLStatic_ActorQuery(a0, a1, a2, &io3, a4);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io3);
    return 2;
}

static int GenL_SDLStatic_ActorRemoveBody(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorRemoveBody(a0);
    return 0;
}

static int GenL_SDLStatic_ActorRemoveLight(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorRemoveLight(a0);
    return 0;
}

static int GenL_SDLStatic_ActorRenderTransform(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_ActorTransform rv = SDLStatic_ActorRenderTransform(a0, a1);
    GenPush_SDLStatic_ActorTransform(L, &rv);
    return 1;
}

static int GenL_SDLStatic_ActorSend(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)luaL_checkinteger(L, 2);
    SDLStatic_ActorMessage tmp2;
    const SDLStatic_ActorMessage *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDLStatic_ActorMessage(L, 3, &tmp2);
        a2 = &tmp2;
    }
    bool rv = SDLStatic_ActorSend(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActorSetAngularVelocity(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_ActorSetAngularVelocity(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActorSetEnabled(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_ActorSetEnabled(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActorSetLocal(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorTransform tmp1;
    const SDLStatic_ActorTransform *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_ActorTransform(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDLStatic_ActorSetLocal(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActorSetParent(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_ActorSetParent(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActorSetPosition(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_ActorSetPosition(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_ActorSetSprite(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    const SDLStatic_Sprite *a1 = (const SDLStatic_Sprite *)SDLStaticGen_LuaCheckHandle(L, 2, "SDLStatic_Sprite");
    bool rv = SDLStatic_ActorSetSprite(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ActorSetTags(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorTags a1 = (SDLStatic_ActorTags)luaL_checkinteger(L, 2);
    SDLStatic_ActorSetTags(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ActorSetVelocity(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_ActorSetVelocity(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_ActorSpawn(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const SDLStatic_ActorDef *a1 = (const SDLStatic_ActorDef *)SDLStaticGen_LuaCheckHandle(L, 2, "SDLStatic_ActorDef");
    SDLStatic_ActorId rv = SDLStatic_ActorSpawn(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_ActorSprite(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_Sprite * rv = SDLStatic_ActorSprite(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_Sprite");
    return 1;
}

static int GenL_SDLStatic_ActorTeleport(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_ActorTeleport(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_ActorTeleportBody(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_ActorTeleportBody(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_ActorType(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    const char * rv = SDLStatic_ActorType(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_ActorVelocity(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    SDLStatic_ActorVelocity(a0, &io1, &io2);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    return 2;
}

static int GenL_SDLStatic_ActorWakeBody(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorWakeBody(a0);
    return 0;
}

static int GenL_SDLStatic_ActorWorld(lua_State *L)
{
    (void)L;
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Actor");
    SDLStatic_ActorTransform rv = SDLStatic_ActorWorld(a0);
    GenPush_SDLStatic_ActorTransform(L, &rv);
    return 1;
}

static int GenL_SDLStatic_AddDarkZone(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    SDL_FRect a1;
    GenRead_SDL_FRect(L, 2, &a1);
    SDL_FColor a2;
    GenRead_SDL_FColor(L, 3, &a2);
    bool rv = SDLStatic_AddDarkZone(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_AddLight(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    SDLStatic_Light tmp1;
    const SDLStatic_Light *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_Light(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_AddLight(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_AddOccluderRect(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    SDL_FRect a1;
    GenRead_SDL_FRect(L, 2, &a1);
    bool rv = SDLStatic_AddOccluderRect(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_AddOccluderSegment(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    bool rv = SDLStatic_AddOccluderSegment(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_AnyInput(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool rv = SDLStatic_AnyInput(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_AssetPath(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_TextureId a1 = (SDLStatic_TextureId)luaL_checkinteger(L, 2);
    const char * rv = SDLStatic_AssetPath(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_AssetRelease(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_TextureId a1 = (SDLStatic_TextureId)luaL_checkinteger(L, 2);
    SDLStatic_AssetRelease(a0, a1);
    return 0;
}

static int GenL_SDLStatic_AssetRetain(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_TextureId a1 = (SDLStatic_TextureId)luaL_checkinteger(L, 2);
    SDLStatic_AssetRetain(a0, a1);
    return 0;
}

static int GenL_SDLStatic_AssetStatusOf(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_TextureId a1 = (SDLStatic_TextureId)luaL_checkinteger(L, 2);
    SDLStatic_AssetStatus rv = SDLStatic_AssetStatusOf(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_AssetsFrameBudget(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_AssetsFrameBudget(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_AssetsLoaded(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_AssetsLoaded(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_AssetsPending(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_AssetsPending(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_AssetsProgress(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_AssetsProgress(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_AssetsReady(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool rv = SDLStatic_AssetsReady(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_AssetsSetFrameBudget(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_AssetsSetFrameBudget(a0, a1);
    return 0;
}

static int GenL_SDLStatic_AssetsSetWorkers(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_AssetsSetWorkers(a0, a1);
    return 0;
}

static int GenL_SDLStatic_AssetsWait(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_AssetsWait(a0);
    return 0;
}

static int GenL_SDLStatic_BidiBaseIsRTL(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_BidiBaseIsRTL(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_BindingFromString(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDLStatic_Binding out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDLStatic_BindingFromString(a0, &out1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDLStatic_Binding(L, &out1);
    return 2;
}

static int GenL_SDLStatic_BindingToString(lua_State *L)
{
    (void)L;
    SDLStatic_Binding a0;
    GenRead_SDLStatic_Binding(L, 1, &a0);
    const char *src1 = lua_isnoneornil(L, 2) ? "" : luaL_checkstring(L, 2);
    char *a1 = SDL_strdup(src1);
    size_t a2 = (size_t)luaL_checkinteger(L, 3);
    const char * rv = SDLStatic_BindingToString(a0, a1, a2);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    SDL_free(a1);
    return 1;
}

static int GenL_SDLStatic_BodyDefDestroy(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_BodyDefDestroy(&out0);
    GenPush_SDLStatic_BodyDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_BodyDefSetBullet(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    bool a1 = (bool)lua_toboolean(L, 1);
    SDLStatic_BodyDefSetBullet(&out0, a1);
    GenPush_SDLStatic_BodyDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_BodyDefSetFilter(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 1);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 2);
    SDLStatic_BodyDefSetFilter(&out0, a1, a2);
    GenPush_SDLStatic_BodyDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_BodyDefSetFixedRotation(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    bool a1 = (bool)lua_toboolean(L, 1);
    SDLStatic_BodyDefSetFixedRotation(&out0, a1);
    GenPush_SDLStatic_BodyDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_BodyDefSetGravityScale(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    SDLStatic_BodyDefSetGravityScale(&out0, a1);
    GenPush_SDLStatic_BodyDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_BodyDefSetMaterial(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    float a3 = (float)luaL_checknumber(L, 3);
    SDLStatic_BodyDefSetMaterial(&out0, a1, a2, a3);
    GenPush_SDLStatic_BodyDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_BodyDefSetOffset(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    SDLStatic_BodyDefSetOffset(&out0, a1, a2);
    GenPush_SDLStatic_BodyDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_BodyDefSetSensor(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    bool a1 = (bool)lua_toboolean(L, 1);
    SDLStatic_BodyDefSetSensor(&out0, a1);
    GenPush_SDLStatic_BodyDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_BodyDefSetShape(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_ShapeType a1 = (SDLStatic_ShapeType)luaL_checkinteger(L, 1);
    SDLStatic_BodyDefSetShape(&out0, a1);
    GenPush_SDLStatic_BodyDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_BodyDefSetSize(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    SDLStatic_BodyDefSetSize(&out0, a1, a2);
    GenPush_SDLStatic_BodyDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_BodyDefSetType(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_BodyType a1 = (SDLStatic_BodyType)luaL_checkinteger(L, 1);
    SDLStatic_BodyDefSetType(&out0, a1);
    GenPush_SDLStatic_BodyDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_BodyDefault(lua_State *L)
{
    (void)L;
    SDLStatic_BodyDef rv = SDLStatic_BodyDefault();
    GenPush_SDLStatic_BodyDef(L, &rv);
    return 1;
}

static int GenL_SDLStatic_CameraBegin(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_Camera tmp1;
    const SDLStatic_Camera *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_Camera(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_CameraBegin(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_CameraDestroy(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_CameraDestroy(&out0);
    GenPush_SDLStatic_Camera(L, &out0);
    return 1;
}

static int GenL_SDLStatic_CameraEnd(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_CameraEnd(a0);
    return 0;
}

static int GenL_SDLStatic_CameraFollow(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    SDLStatic_CameraFollow(&out0, a1, a2);
    GenPush_SDLStatic_Camera(L, &out0);
    return 1;
}

static int GenL_SDLStatic_CameraInit(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_Engine *a1 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_CameraInit(&out0, a1);
    GenPush_SDLStatic_Camera(L, &out0);
    return 1;
}

static int GenL_SDLStatic_CameraPoint(lua_State *L)
{
    (void)L;
    SDLStatic_Camera tmp0;
    const SDLStatic_Camera *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDLStatic_Camera(L, 1, &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    SDLStatic_CameraPoint(a0, a1, a2, &io3, &io4);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    return 2;
}

static int GenL_SDLStatic_CameraRect(lua_State *L)
{
    (void)L;
    SDLStatic_Camera tmp0;
    const SDLStatic_Camera *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDLStatic_Camera(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_FRect a1;
    GenRead_SDL_FRect(L, 2, &a1);
    SDL_FRect rv = SDLStatic_CameraRect(a0, a1);
    GenPush_SDL_FRect(L, &rv);
    return 1;
}

static int GenL_SDLStatic_CameraScreenToWorld(lua_State *L)
{
    (void)L;
    SDLStatic_Camera tmp0;
    const SDLStatic_Camera *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDLStatic_Camera(L, 1, &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    bool rv = SDLStatic_CameraScreenToWorld(a0, a1, a2, &io3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    return 3;
}

static int GenL_SDLStatic_CameraSetBounds(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    float a3 = (float)luaL_checknumber(L, 3);
    float a4 = (float)luaL_checknumber(L, 4);
    SDLStatic_CameraSetBounds(&out0, a1, a2, a3, a4);
    GenPush_SDLStatic_Camera(L, &out0);
    return 1;
}

static int GenL_SDLStatic_CameraSetDeadzone(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    SDLStatic_CameraSetDeadzone(&out0, a1, a2);
    GenPush_SDLStatic_Camera(L, &out0);
    return 1;
}

static int GenL_SDLStatic_CameraSetSmoothing(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    SDLStatic_CameraSetSmoothing(&out0, a1);
    GenPush_SDLStatic_Camera(L, &out0);
    return 1;
}

static int GenL_SDLStatic_CameraSetViewport(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    float a3 = (float)luaL_checknumber(L, 3);
    float a4 = (float)luaL_checknumber(L, 4);
    SDLStatic_CameraSetViewport(&out0, a1, a2, a3, a4);
    GenPush_SDLStatic_Camera(L, &out0);
    return 1;
}

static int GenL_SDLStatic_CameraSetZoom(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    SDLStatic_CameraSetZoom(&out0, a1);
    GenPush_SDLStatic_Camera(L, &out0);
    return 1;
}

static int GenL_SDLStatic_CameraShake(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    SDLStatic_CameraShake(&out0, a1, a2);
    GenPush_SDLStatic_Camera(L, &out0);
    return 1;
}

static int GenL_SDLStatic_CameraSnap(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    SDLStatic_CameraSnap(&out0, a1, a2);
    GenPush_SDLStatic_Camera(L, &out0);
    return 1;
}

static int GenL_SDLStatic_CameraSplit(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_SplitMode a1 = (SDLStatic_SplitMode)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    SDLStatic_Camera out4;
    memset(&out4, 0, sizeof(out4));
    int rv = SDLStatic_CameraSplit(a0, a1, a2, a3, &out4);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_SDLStatic_Camera(L, &out4);
    return 2;
}

static int GenL_SDLStatic_CameraUpdate(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_Engine *a1 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a2 = (float)luaL_checknumber(L, 2);
    SDLStatic_CameraUpdate(&out0, a1, a2);
    GenPush_SDLStatic_Camera(L, &out0);
    return 1;
}

static int GenL_SDLStatic_CameraVisible(lua_State *L)
{
    (void)L;
    SDLStatic_Camera tmp0;
    const SDLStatic_Camera *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDLStatic_Camera(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDL_FRect a1;
    GenRead_SDL_FRect(L, 2, &a1);
    bool rv = SDLStatic_CameraVisible(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_CameraX(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float rv = SDLStatic_CameraX(&out0);
    lua_pushnumber(L, (lua_Number)rv);
    GenPush_SDLStatic_Camera(L, &out0);
    return 2;
}

static int GenL_SDLStatic_CameraY(lua_State *L)
{
    (void)L;
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float rv = SDLStatic_CameraY(&out0);
    lua_pushnumber(L, (lua_Number)rv);
    GenPush_SDLStatic_Camera(L, &out0);
    return 2;
}

static int GenL_SDLStatic_CompileRegex(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_Regex * rv = SDLStatic_CompileRegex(a0, a1);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDLStatic_Regex", GenDtor_SDLStatic_DestroyRegex);
    return 1;
}

static int GenL_SDLStatic_ConfigCreate(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig * rv = SDLStatic_ConfigCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_EngineConfig");
    return 1;
}

static int GenL_SDLStatic_ConfigDestroy(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    SDLStatic_ConfigDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_ConfigSetAutoMount(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_ConfigSetAutoMount(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetBackend(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    SDLStatic_EngineBackend a1 = (SDLStatic_EngineBackend)luaL_checkinteger(L, 2);
    SDLStatic_ConfigSetBackend(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetDesignSize(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDLStatic_ConfigSetDesignSize(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_ConfigSetFullscreen(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_ConfigSetFullscreen(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetGraphics(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    SDLStatic_GraphicsSettings tmp1;
    const SDLStatic_GraphicsSettings *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_GraphicsSettings(L, 2, &tmp1);
        a1 = &tmp1;
    }
    SDLStatic_ConfigSetGraphics(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetHeadless(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_ConfigSetHeadless(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetHighDpi(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_ConfigSetHighDpi(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetManualClock(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_ConfigSetManualClock(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetMaxFps(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_ConfigSetMaxFps(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetMediaPath(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_ConfigSetMediaPath(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetPresentation(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    SDLStatic_EnginePresentation a1 = (SDLStatic_EnginePresentation)luaL_checkinteger(L, 2);
    SDLStatic_ConfigSetPresentation(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetResizable(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_ConfigSetResizable(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetTickRate(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_ConfigSetTickRate(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetTitle(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_ConfigSetTitle(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetVsync(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_ConfigSetVsync(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ConfigSetWindowSize(lua_State *L)
{
    (void)L;
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDLStatic_ConfigSetWindowSize(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_CountSignalConnections(lua_State *L)
{
    (void)L;
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_SignalEmitter");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = SDLStatic_CountSignalConnections(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_CreateChipSFX(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    SDLStatic_ChipSFX a1 = (SDLStatic_ChipSFX)luaL_checkinteger(L, 2);
    MIX_Audio * rv = SDLStatic_CreateChipSFX(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Audio");
    return 1;
}

static int GenL_SDLStatic_CreateChipTone(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    SDLStatic_ChipToneDesc tmp1;
    const SDLStatic_ChipToneDesc *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_ChipToneDesc(L, 2, &tmp1);
        a1 = &tmp1;
    }
    MIX_Audio * rv = SDLStatic_CreateChipTone(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Audio");
    return 1;
}

static int GenL_SDLStatic_CreateChipTune(lua_State *L)
{
    (void)L;
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_LuaCheckHandle(L, 1, "MIX_Mixer");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    MIX_Audio * rv = SDLStatic_CreateChipTune(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "MIX_Audio");
    return 1;
}

static int GenL_SDLStatic_CreateEngine(lua_State *L)
{
    (void)L;
    const SDLStatic_EngineConfig *a0 = (const SDLStatic_EngineConfig *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_EngineConfig");
    SDLStatic_Engine * rv = SDLStatic_CreateEngine(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_Engine");
    return 1;
}

static int GenL_SDLStatic_CreateGui(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    size_t len1 = 0;
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checklstring(L, 2, &len1);
    float a3 = (float)luaL_checknumber(L, 3);
    SDLStatic_Gui * rv = SDLStatic_CreateGui(a0, (const void *)a1, (size_t)len1, a3);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDLStatic_Gui", GenDtor_SDLStatic_DestroyGui);
    return 1;
}

static int GenL_SDLStatic_CreateGuiWithGlyphs(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    size_t len1 = 0;
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checklstring(L, 2, &len1);
    float a3 = (float)luaL_checknumber(L, 3);
    SDLStatic_GuiGlyphRange a4 = (SDLStatic_GuiGlyphRange)luaL_checkinteger(L, 4);
    SDLStatic_Gui * rv = SDLStatic_CreateGuiWithGlyphs(a0, (const void *)a1, (size_t)len1, a3, a4);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_Gui");
    return 1;
}

static int GenL_SDLStatic_CreateLightScene(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    SDLStatic_LightScene * rv = SDLStatic_CreateLightScene(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDLStatic_LightScene", GenDtor_SDLStatic_DestroyLightScene);
    return 1;
}

static int GenL_SDLStatic_CreateSignalEmitter(lua_State *L)
{
    (void)L;
    SDLStatic_SignalEmitter * rv = SDLStatic_CreateSignalEmitter();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_SignalEmitter");
    return 1;
}

static int GenL_SDLStatic_CryptoSelfTest(lua_State *L)
{
    (void)L;
    bool rv = SDLStatic_CryptoSelfTest();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_DayNightAmbient(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    SDL_FColor rv = SDLStatic_DayNightAmbient(a0);
    GenPush_SDL_FColor(L, &rv);
    return 1;
}

static int GenL_SDLStatic_DayNightSunlight(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float rv = SDLStatic_DayNightSunlight(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_DestroyEngine(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_DestroyEngine(a0);
    return 0;
}

static int GenL_SDLStatic_DestroyGui(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaTakeHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_DestroyGui(a0);
    return 0;
}

static int GenL_SDLStatic_DestroyLightScene(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaTakeHandle(L, 1, "SDLStatic_LightScene");
    SDLStatic_DestroyLightScene(a0);
    return 0;
}

static int GenL_SDLStatic_DestroyRegex(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaTakeHandle(L, 1, "SDLStatic_Regex");
    SDLStatic_DestroyRegex(a0);
    return 0;
}

static int GenL_SDLStatic_DestroySignalEmitter(lua_State *L)
{
    (void)L;
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_SignalEmitter");
    SDLStatic_DestroySignalEmitter(a0);
    return 0;
}

static int GenL_SDLStatic_DeviceAccelerometer(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    SDLStatic_DeviceAccelerometer(a0, &io1, &io2, &io3);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    return 3;
}

static int GenL_SDLStatic_DeviceGyro(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    SDLStatic_DeviceGyro(a0, &io1, &io2, &io3);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    return 3;
}

static int GenL_SDLStatic_DialogDeliverSave(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDLStatic_DialogDeliverSave(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_DialogPath(lua_State *L)
{
    (void)L;
    const char * rv = SDLStatic_DialogPath();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_DialogReset(lua_State *L)
{
    (void)L;
    SDLStatic_DialogReset();
    return 0;
}

static int GenL_SDLStatic_DialogStatus(lua_State *L)
{
    (void)L;
    SDLStatic_DialogState rv = SDLStatic_DialogStatus();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_DisconnectSignal(lua_State *L)
{
    (void)L;
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_SignalEmitter");
    Uint64 a1 = (Uint64)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_DisconnectSignal(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_DistanceJointDefCreate(lua_State *L)
{
    (void)L;
    b2DistanceJointDef * rv = SDLStatic_DistanceJointDefCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "b2DistanceJointDef");
    return 1;
}

static int GenL_SDLStatic_DistanceJointDefDestroy(lua_State *L)
{
    (void)L;
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DistanceJointDef");
    SDLStatic_DistanceJointDefDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_DistanceJointDefSetAnchors(lua_State *L)
{
    (void)L;
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DistanceJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    SDLStatic_DistanceJointDefSetAnchors(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_SDLStatic_DistanceJointDefSetBodies(lua_State *L)
{
    (void)L;
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DistanceJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(L, 2, &a1);
    b2BodyId a2;
    GenRead_b2BodyId(L, 3, &a2);
    SDLStatic_DistanceJointDefSetBodies(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_DistanceJointDefSetCollideConnected(lua_State *L)
{
    (void)L;
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DistanceJointDef");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_DistanceJointDefSetCollideConnected(a0, a1);
    return 0;
}

static int GenL_SDLStatic_DistanceJointDefSetLength(lua_State *L)
{
    (void)L;
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DistanceJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_DistanceJointDefSetLength(a0, a1);
    return 0;
}

static int GenL_SDLStatic_DistanceJointDefSetLimit(lua_State *L)
{
    (void)L;
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DistanceJointDef");
    bool a1 = (bool)lua_toboolean(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    SDLStatic_DistanceJointDefSetLimit(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDLStatic_DistanceJointDefSetSpring(lua_State *L)
{
    (void)L;
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2DistanceJointDef");
    bool a1 = (bool)lua_toboolean(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    SDLStatic_DistanceJointDefSetSpring(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDLStatic_DrawPhysicsWorld(lua_State *L)
{
    (void)L;
    b2WorldId a0;
    GenRead_b2WorldId(L, 1, &a0);
    SDL_Renderer *a1 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Renderer");
    SDLStatic_PhysicsDrawConfig tmp2;
    const SDLStatic_PhysicsDrawConfig *a2 = NULL;
    if (!lua_isnoneornil(L, 3)) {
        GenRead_SDLStatic_PhysicsDrawConfig(L, 3, &tmp2);
        a2 = &tmp2;
    }
    bool rv = SDLStatic_DrawPhysicsWorld(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_EncodeDataBase64(lua_State *L)
{
    (void)L;
    size_t len0 = 0;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checklstring(L, 1, &len0);
    int io2 = (int)luaL_optinteger(L, 2, 0);
    char * rv = SDLStatic_EncodeDataBase64((const void *)a0, (int)len0, &io2);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_SDLStatic_EngineAdvance(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    Uint64 a1 = (Uint64)luaL_checkinteger(L, 2);
    SDLStatic_EngineAdvance(a0, a1);
    return 0;
}

static int GenL_SDLStatic_EngineAlpha(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_EngineAlpha(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EngineAssetScale(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_EngineAssetScale(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EngineDelta(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_EngineDelta(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EngineDesignSize(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    SDLStatic_EngineDesignSize(a0, &io1, &io2);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_SDLStatic_EngineDisplay(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_EngineDisplay(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EngineDisplayCount(lua_State *L)
{
    (void)L;
    int rv = SDLStatic_EngineDisplayCount();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EngineDisplayName(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    const char * rv = SDLStatic_EngineDisplayName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_EngineEffectsAvailable(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool rv = SDLStatic_EngineEffectsAvailable(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_EngineEmbedMedia(lua_State *L)
{
    (void)L;
    size_t len0 = 0;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checklstring(L, 1, &len0);
    const char *a2 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_EngineEmbedMedia((const void *)a0, (int)len0, a2);
    return 0;
}

static int GenL_SDLStatic_EngineFps(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_EngineFps(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EngineFrameCount(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    Uint64 rv = SDLStatic_EngineFrameCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EngineMaxFps(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_EngineMaxFps(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EngineMediaPath(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char * rv = SDLStatic_EngineMediaPath(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_EngineMediaSource(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_MediaSource rv = SDLStatic_EngineMediaSource(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EngineOverloadFrames(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_EngineOverloadFrames(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EnginePixelSize(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    SDLStatic_EnginePixelSize(a0, &io1, &io2);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_SDLStatic_EnginePresentation_(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_EnginePresentation rv = SDLStatic_EnginePresentation_(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EngineQuit(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_EngineQuit(a0);
    return 0;
}

static int GenL_SDLStatic_EngineRenderScale(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_EngineRenderScale(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EngineRenderer(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_Renderer * rv = SDLStatic_EngineRenderer(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Renderer");
    return 1;
}

static int GenL_SDLStatic_EngineSafeRect(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_FRect rv = SDLStatic_EngineSafeRect(a0);
    GenPush_SDL_FRect(L, &rv);
    return 1;
}

static int GenL_SDLStatic_EngineSetClearColor(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_FColor a1;
    GenRead_SDL_FColor(L, 2, &a1);
    SDLStatic_EngineSetClearColor(a0, a1);
    return 0;
}

static int GenL_SDLStatic_EngineSetDisplay(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_EngineSetDisplay(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_EngineSetGraphics(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_GraphicsSettings tmp1;
    const SDLStatic_GraphicsSettings *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_GraphicsSettings(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_EngineSetGraphics(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_EngineSetMaxFps(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_EngineSetMaxFps(a0, a1);
    return 0;
}

static int GenL_SDLStatic_EngineSetMediaPassword(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDLStatic_EngineSetMediaPassword(a0);
    return 0;
}

static int GenL_SDLStatic_EngineSetPresentation(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_EnginePresentation a1 = (SDLStatic_EnginePresentation)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_EngineSetPresentation(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_EngineSetRefreshRate(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_EngineSetRefreshRate(a0, a1);
    return 0;
}

static int GenL_SDLStatic_EngineSetTickRate(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_EngineSetTickRate(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_EngineSetTimeScale(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_EngineSetTimeScale(a0, a1);
    return 0;
}

static int GenL_SDLStatic_EngineStep(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_EngineStep(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EngineStepsLastFrame(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_EngineStepsLastFrame(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EngineTick(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool rv = SDLStatic_EngineTick(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_EngineTickRate(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_EngineTickRate(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EngineTimeScale(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_EngineTimeScale(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EngineViewRect(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_FRect rv = SDLStatic_EngineViewRect(a0);
    GenPush_SDL_FRect(L, &rv);
    return 1;
}

static int GenL_SDLStatic_EngineWindow(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_Window * rv = SDLStatic_EngineWindow(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Window");
    return 1;
}

static int GenL_SDLStatic_EngineWindowToDesign(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    SDLStatic_EngineWindowToDesign(a0, a1, a2, &io3, &io4);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    return 2;
}

static int GenL_SDLStatic_EventCreate(lua_State *L)
{
    (void)L;
    SDL_Event * rv = SDLStatic_EventCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Event");
    return 1;
}

static int GenL_SDLStatic_EventDestroy(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    SDLStatic_EventDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_EventGamepadAxis(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    int rv = SDLStatic_EventGamepadAxis(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EventGamepadAxisValue(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    float rv = SDLStatic_EventGamepadAxisValue(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EventGamepadButton(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    int rv = SDLStatic_EventGamepadButton(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EventGamepadWhich(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    Sint32 rv = SDLStatic_EventGamepadWhich(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EventKeyModifiers(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    Uint16 rv = SDLStatic_EventKeyModifiers(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EventKeyRepeat(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    bool rv = SDLStatic_EventKeyRepeat(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_EventKeyScancode(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    int rv = SDLStatic_EventKeyScancode(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EventMouseButton(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    int rv = SDLStatic_EventMouseButton(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EventMouseDeltaX(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    float rv = SDLStatic_EventMouseDeltaX(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EventMouseDeltaY(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    float rv = SDLStatic_EventMouseDeltaY(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EventMouseX(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    float rv = SDLStatic_EventMouseX(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EventMouseY(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    float rv = SDLStatic_EventMouseY(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EventSetType(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    Uint32 a1 = (Uint32)luaL_checkinteger(L, 2);
    SDLStatic_EventSetType(a0, a1);
    return 0;
}

static int GenL_SDLStatic_EventText(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    const char * rv = SDLStatic_EventText(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_EventTouchX(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    float rv = SDLStatic_EventTouchX(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EventTouchY(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    float rv = SDLStatic_EventTouchY(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EventType(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    Uint32 rv = SDLStatic_EventType(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_EventWheelX(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    float rv = SDLStatic_EventWheelX(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EventWheelY(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    float rv = SDLStatic_EventWheelY(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_EventWindowId(lua_State *L)
{
    (void)L;
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Event");
    Uint32 rv = SDLStatic_EventWindowId(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_FilterJointDefCreate(lua_State *L)
{
    (void)L;
    b2FilterJointDef * rv = SDLStatic_FilterJointDefCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "b2FilterJointDef");
    return 1;
}

static int GenL_SDLStatic_FilterJointDefDestroy(lua_State *L)
{
    (void)L;
    b2FilterJointDef *a0 = (b2FilterJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2FilterJointDef");
    SDLStatic_FilterJointDefDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_FilterJointDefSetBodies(lua_State *L)
{
    (void)L;
    b2FilterJointDef *a0 = (b2FilterJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2FilterJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(L, 2, &a1);
    b2BodyId a2;
    GenRead_b2BodyId(L, 3, &a2);
    SDLStatic_FilterJointDefSetBodies(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_FingerCount(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_FingerCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_FreeTiledMap(lua_State *L)
{
    (void)L;
    SDLStatic_TiledMap *a0 = (SDLStatic_TiledMap *)SDLStaticGen_LuaTakeHandle(L, 1, "SDLStatic_TiledMap");
    SDLStatic_FreeTiledMap(a0);
    return 0;
}

static int GenL_SDLStatic_GamepadAccelerometer(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    SDLStatic_GamepadAccelerometer(a0, a1, &io2, &io3, &io4);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    return 3;
}

static int GenL_SDLStatic_GamepadAxisValue(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GamepadAxis a2 = (SDLStatic_GamepadAxis)luaL_checkinteger(L, 3);
    float rv = SDLStatic_GamepadAxisValue(a0, a1, a2);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadButtonDown(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GamepadButton a2 = (SDLStatic_GamepadButton)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_GamepadButtonDown(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadButtonPressed(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GamepadButton a2 = (SDLStatic_GamepadButton)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_GamepadButtonPressed(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadButtonReleased(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GamepadButton a2 = (SDLStatic_GamepadButton)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_GamepadButtonReleased(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadConnected(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_GamepadConnected(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadCount(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_GamepadCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadDeadzone(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_GamepadDeadzone(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadDirectionPressed(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_Direction a2 = (SDLStatic_Direction)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_GamepadDirectionPressed(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadDirectionRepeat(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_Direction a2 = (SDLStatic_Direction)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_GamepadDirectionRepeat(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadGyro(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    SDLStatic_GamepadGyro(a0, a1, &io2, &io3, &io4);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    return 3;
}

static int GenL_SDLStatic_GamepadHasAccelerometer(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_GamepadHasAccelerometer(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadHasGyro(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_GamepadHasGyro(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadName(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char * rv = SDLStatic_GamepadName(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_GamepadRumble(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    bool rv = SDLStatic_GamepadRumble(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadRumbleTriggers(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    Uint32 a4 = (Uint32)luaL_checkinteger(L, 5);
    bool rv = SDLStatic_GamepadRumbleTriggers(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadSetLED(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    Uint8 a2 = (Uint8)luaL_checkinteger(L, 3);
    Uint8 a3 = (Uint8)luaL_checkinteger(L, 4);
    Uint8 a4 = (Uint8)luaL_checkinteger(L, 5);
    bool rv = SDLStatic_GamepadSetLED(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GamepadStick(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float io4 = (float)luaL_optnumber(L, 5, 0);
    SDLStatic_GamepadStick(a0, a1, a2, &io3, &io4);
    lua_pushnumber(L, (lua_Number)io3);
    lua_pushnumber(L, (lua_Number)io4);
    return 2;
}

static int GenL_SDLStatic_GamepadStopRumble(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GamepadStopRumble(a0, a1);
    return 0;
}

static int GenL_SDLStatic_GraphicsClamp(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsSettings out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_GraphicsClamp(&out0);
    GenPush_SDLStatic_GraphicsSettings(L, &out0);
    return 1;
}

static int GenL_SDLStatic_GraphicsConfigError(lua_State *L)
{
    (void)L;
    const char * rv = SDLStatic_GraphicsConfigError();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_GraphicsConfigPath(lua_State *L)
{
    (void)L;
    const char * rv = SDLStatic_GraphicsConfigPath();
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_GraphicsDefaults(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsSettings rv = SDLStatic_GraphicsDefaults();
    GenPush_SDLStatic_GraphicsSettings(L, &rv);
    return 1;
}

static int GenL_SDLStatic_GraphicsEqual(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsSettings tmp0;
    const SDLStatic_GraphicsSettings *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDLStatic_GraphicsSettings(L, 1, &tmp0);
        a0 = &tmp0;
    }
    SDLStatic_GraphicsSettings tmp1;
    const SDLStatic_GraphicsSettings *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_GraphicsSettings(L, 2, &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_GraphicsEqual(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GraphicsLightMapScale(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)luaL_checkinteger(L, 1);
    float rv = SDLStatic_GraphicsLightMapScale(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_GraphicsLoadTomlFile(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsSettings out0;
    memset(&out0, 0, sizeof(out0));
    const char *a1 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDLStatic_GraphicsLoadTomlFile(&out0, a1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDLStatic_GraphicsSettings(L, &out0);
    return 2;
}

static int GenL_SDLStatic_GraphicsLoadTomlString(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsSettings out0;
    memset(&out0, 0, sizeof(out0));
    const char *a1 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    bool rv = SDLStatic_GraphicsLoadTomlString(&out0, a1);
    lua_pushboolean(L, (int)rv);
    GenPush_SDLStatic_GraphicsSettings(L, &out0);
    return 2;
}

static int GenL_SDLStatic_GraphicsMaxDynamicLights(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)luaL_checkinteger(L, 1);
    int rv = SDLStatic_GraphicsMaxDynamicLights(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_GraphicsParticleDensity(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)luaL_checkinteger(L, 1);
    float rv = SDLStatic_GraphicsParticleDensity(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_GraphicsQualityFromName(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDLStatic_GraphicsQuality io1 = (SDLStatic_GraphicsQuality)luaL_optinteger(L, 2, 0);
    bool rv = SDLStatic_GraphicsQualityFromName(a0, &io1);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_SDLStatic_GraphicsQualityName(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)luaL_checkinteger(L, 1);
    const char * rv = SDLStatic_GraphicsQualityName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_GraphicsSafeMode(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsSettings rv = SDLStatic_GraphicsSafeMode();
    GenPush_SDLStatic_GraphicsSettings(L, &rv);
    return 1;
}

static int GenL_SDLStatic_GraphicsSave(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsSettings tmp0;
    const SDLStatic_GraphicsSettings *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDLStatic_GraphicsSettings(L, 1, &tmp0);
        a0 = &tmp0;
    }
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDLStatic_GraphicsSave(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GraphicsSavePath(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    char * rv = SDLStatic_GraphicsSavePath(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDLStatic_GraphicsShadowRays(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)luaL_checkinteger(L, 1);
    int rv = SDLStatic_GraphicsShadowRays(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_GraphicsShadowSoftness(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)luaL_checkinteger(L, 1);
    float rv = SDLStatic_GraphicsShadowSoftness(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_GraphicsToToml(lua_State *L)
{
    (void)L;
    SDLStatic_GraphicsSettings tmp0;
    const SDLStatic_GraphicsSettings *a0 = NULL;
    if (!lua_isnoneornil(L, 1)) {
        GenRead_SDLStatic_GraphicsSettings(L, 1, &tmp0);
        a0 = &tmp0;
    }
    char * rv = SDLStatic_GraphicsToToml(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDLStatic_GuiContext(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    struct nk_context * rv = SDLStatic_GuiContext(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_context");
    return 1;
}

static int GenL_SDLStatic_GuiDrawCommandCount(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int rv = SDLStatic_GuiDrawCommandCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_GuiDrawTexture(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Texture");
    SDL_FRect a2;
    GenRead_SDL_FRect(L, 3, &a2);
    SDLStatic_GuiImageMode a3 = (SDLStatic_GuiImageMode)luaL_checkinteger(L, 4);
    bool rv = SDLStatic_GuiDrawTexture(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiDrawTextureOverlay(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Texture");
    SDL_FRect a2;
    GenRead_SDL_FRect(L, 3, &a2);
    SDLStatic_GuiImageMode a3 = (SDLStatic_GuiImageMode)luaL_checkinteger(L, 4);
    bool rv = SDLStatic_GuiDrawTextureOverlay(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiFontHeight(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    float rv = SDLStatic_GuiFontHeight(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_GuiGridBeginOwned(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int a1 = (int)luaL_checkinteger(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    bool rv = SDLStatic_GuiGridBeginOwned(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiGridCell(lua_State *L)
{
    (void)L;
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_GuiGrid");
    SDLStatic_GuiGridCell(a0);
    return 0;
}

static int GenL_SDLStatic_GuiGridCellOwned(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiGridCellOwned(a0);
    return 0;
}

static int GenL_SDLStatic_GuiGridCellSpan(lua_State *L)
{
    (void)L;
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_GuiGrid");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GuiGridCellSpan(a0, a1);
    return 0;
}

static int GenL_SDLStatic_GuiGridCellSpanOwned(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GuiGridCellSpanOwned(a0, a1);
    return 0;
}

static int GenL_SDLStatic_GuiGridCreate(lua_State *L)
{
    (void)L;
    SDLStatic_GuiGrid * rv = SDLStatic_GuiGridCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_GuiGrid");
    return 1;
}

static int GenL_SDLStatic_GuiGridDestroy(lua_State *L)
{
    (void)L;
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_GuiGrid");
    SDLStatic_GuiGridDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_GuiGridEnd(lua_State *L)
{
    (void)L;
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_GuiGrid");
    SDLStatic_GuiGridEnd(a0);
    return 0;
}

static int GenL_SDLStatic_GuiGridEndOwned(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiGridEndOwned(a0);
    return 0;
}

static int GenL_SDLStatic_GuiGridNextRow(lua_State *L)
{
    (void)L;
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_GuiGrid");
    SDLStatic_GuiGridNextRow(a0);
    return 0;
}

static int GenL_SDLStatic_GuiGridNextRowOwned(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiGridNextRowOwned(a0);
    return 0;
}

static int GenL_SDLStatic_GuiGridWeight(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int a1 = (int)luaL_checkinteger(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    bool rv = SDLStatic_GuiGridWeight(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiImage(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Texture");
    SDLStatic_GuiImageMode a2 = (SDLStatic_GuiImageMode)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_GuiImage(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiInputBegin(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiInputBegin(a0);
    return 0;
}

static int GenL_SDLStatic_GuiInputEnd(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiInputEnd(a0);
    return 0;
}

static int GenL_SDLStatic_GuiKeyPressed(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_GuiKeyPressed(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiMemoryUsed(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int rv = SDLStatic_GuiMemoryUsed(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_GuiOpenFileButton(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = SDLStatic_GuiOpenFileButton(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiPopFont(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GuiPopFont(a0, a1);
    return 0;
}

static int GenL_SDLStatic_GuiPopStyleColor(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GuiPopStyleColor(a0, a1);
    return 0;
}

static int GenL_SDLStatic_GuiProcessEvent(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    const SDL_Event *a1 = (const SDL_Event *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Event");
    bool rv = SDLStatic_GuiProcessEvent(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiPumpEvents(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    bool rv = SDLStatic_GuiPumpEvents(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiPushFont(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiFontSize a1 = (SDLStatic_GuiFontSize)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_GuiPushFont(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiPushStyleColor(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiStyleColor a1 = (SDLStatic_GuiStyleColor)luaL_checkinteger(L, 2);
    SDL_Color a2;
    GenRead_SDL_Color(L, 3, &a2);
    bool rv = SDLStatic_GuiPushStyleColor(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiRender(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    bool rv = SDLStatic_GuiRender(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiSaveFileButton(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    size_t len3 = 0;
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checklstring(L, 4, &len3);
    bool rv = SDLStatic_GuiSaveFileButton(a0, a1, a2, (const void *)a3, (size_t)len3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiSavedPath(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    const char * rv = SDLStatic_GuiSavedPath(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_GuiScale(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    float rv = SDLStatic_GuiScale(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_GuiSetFont(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    SDLStatic_GuiFontSize a1 = (SDLStatic_GuiFontSize)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_GuiSetFont(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiSetTooltipDelay(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_GuiSetTooltipDelay(a0, a1);
    return 0;
}

static int GenL_SDLStatic_GuiTooltip(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDLStatic_GuiTooltip(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_GuiTooltipDelay(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    int rv = SDLStatic_GuiTooltipDelay(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_GuiWantsInput(lua_State *L)
{
    (void)L;
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Gui");
    bool rv = SDLStatic_GuiWantsInput(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_HMACSHA256(lua_State *L)
{
    (void)L;
    size_t len0 = 0;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checklstring(L, 1, &len0);
    size_t len2 = 0;
    const char *a2 = lua_isnoneornil(L, 2) ? NULL : luaL_checklstring(L, 2, &len2);
    Uint8 io4 = (Uint8)luaL_optinteger(L, 3, 0);
    bool rv = SDLStatic_HMACSHA256((const void *)a0, (size_t)len0, (const void *)a2, (size_t)len2, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io4);
    return 2;
}

static int GenL_SDLStatic_HasDeviceMotion(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool rv = SDLStatic_HasDeviceMotion(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_IdleSeconds(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_IdleSeconds(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_KeyDown(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_Scancode a1 = (SDL_Scancode)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_KeyDown(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_KeyModifiers(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_Keymod rv = SDLStatic_KeyModifiers(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_KeyPressed(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_Scancode a1 = (SDL_Scancode)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_KeyPressed(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_KeyReleased(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_Scancode a1 = (SDL_Scancode)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_KeyReleased(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_LastInputDevice(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_InputDevice rv = SDLStatic_LastInputDevice(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_LightAddDarkZone(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_FRect a1;
    GenRead_SDL_FRect(L, 2, &a1);
    SDL_FColor a2;
    GenRead_SDL_FColor(L, 3, &a2);
    SDLStatic_LightAddDarkZone(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_LightAddOccluder(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_FRect a1;
    GenRead_SDL_FRect(L, 2, &a1);
    SDLStatic_LightAddOccluder(a0, a1);
    return 0;
}

static int GenL_SDLStatic_LightAddOccluderLine(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    SDLStatic_LightAddOccluderLine(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_SDLStatic_LightAmbient(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_FColor rv = SDLStatic_LightAmbient(a0);
    GenPush_SDL_FColor(L, &rv);
    return 1;
}

static int GenL_SDLStatic_LightAt(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float rv = SDLStatic_LightAt(a0, a1, a2);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_LightBeginFrame(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_LightBeginFrame(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_LightCount(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_LightCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_LightDefDestroy(lua_State *L)
{
    (void)L;
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_LightDefDestroy(&out0);
    GenPush_SDLStatic_LightDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_LightDefSetColor(lua_State *L)
{
    (void)L;
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    float a3 = (float)luaL_checknumber(L, 3);
    float a4 = (float)luaL_checknumber(L, 4);
    SDLStatic_LightDefSetColor(&out0, a1, a2, a3, a4);
    GenPush_SDLStatic_LightDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_LightDefSetCone(lua_State *L)
{
    (void)L;
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    SDLStatic_LightDefSetCone(&out0, a1, a2);
    GenPush_SDLStatic_LightDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_LightDefSetFlicker(lua_State *L)
{
    (void)L;
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    SDLStatic_LightDefSetFlicker(&out0, a1);
    GenPush_SDLStatic_LightDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_LightDefSetOffset(lua_State *L)
{
    (void)L;
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    float a2 = (float)luaL_checknumber(L, 2);
    SDLStatic_LightDefSetOffset(&out0, a1, a2);
    GenPush_SDLStatic_LightDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_LightDefSetRadius(lua_State *L)
{
    (void)L;
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)luaL_checknumber(L, 1);
    SDLStatic_LightDefSetRadius(&out0, a1);
    GenPush_SDLStatic_LightDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_LightDefSetShadows(lua_State *L)
{
    (void)L;
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    bool a1 = (bool)lua_toboolean(L, 1);
    SDLStatic_LightDefSetShadows(&out0, a1);
    GenPush_SDLStatic_LightDef(L, &out0);
    return 1;
}

static int GenL_SDLStatic_LightDefault(lua_State *L)
{
    (void)L;
    SDLStatic_LightDef rv = SDLStatic_LightDefault();
    GenPush_SDLStatic_LightDef(L, &rv);
    return 1;
}

static int GenL_SDLStatic_LightHour(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_LightHour(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_LightLineOfSight(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    bool rv = SDLStatic_LightLineOfSight(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_LightPreset_(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_LightPreset rv = SDLStatic_LightPreset_(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_LightRender(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_Camera tmp1;
    const SDLStatic_Camera *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_Camera(L, 2, &tmp1);
        a1 = &tmp1;
    }
    float a2 = (float)luaL_checknumber(L, 3);
    bool rv = SDLStatic_LightRender(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_LightSetAmbient(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_FColor a1;
    GenRead_SDL_FColor(L, 2, &a1);
    SDLStatic_LightSetAmbient(a0, a1);
    return 0;
}

static int GenL_SDLStatic_LightSetAutoOccluders(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_LightSetAutoOccluders(a0, a1);
    return 0;
}

static int GenL_SDLStatic_LightSetClock(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_LightSetClock(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_LightSetPreset(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_LightPreset a1 = (SDLStatic_LightPreset)luaL_checkinteger(L, 2);
    SDLStatic_LightSetPreset(a0, a1);
    return 0;
}

static int GenL_SDLStatic_LightSunlight(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_LightSunlight(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_LightUsesShaders(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    bool rv = SDLStatic_LightUsesShaders(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_LoadTextFile(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    char * rv = SDLStatic_LoadTextFile(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDLStatic_LoadTexture(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_TextureId rv = SDLStatic_LoadTexture(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_LoadTextureAsync(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_TextureId rv = SDLStatic_LoadTextureAsync(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_LoadTiledMap(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDLStatic_TiledMap * rv = SDLStatic_LoadTiledMap(a0);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "SDLStatic_TiledMap", GenDtor_SDLStatic_FreeTiledMap);
    return 1;
}

static int GenL_SDLStatic_MotorJointDefCreate(lua_State *L)
{
    (void)L;
    b2MotorJointDef * rv = SDLStatic_MotorJointDefCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "b2MotorJointDef");
    return 1;
}

static int GenL_SDLStatic_MotorJointDefDestroy(lua_State *L)
{
    (void)L;
    b2MotorJointDef *a0 = (b2MotorJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2MotorJointDef");
    SDLStatic_MotorJointDefDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_MotorJointDefSetBodies(lua_State *L)
{
    (void)L;
    b2MotorJointDef *a0 = (b2MotorJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2MotorJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(L, 2, &a1);
    b2BodyId a2;
    GenRead_b2BodyId(L, 3, &a2);
    SDLStatic_MotorJointDefSetBodies(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_MountEncryptedArchive(lua_State *L)
{
    (void)L;
    size_t len0 = 0;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checklstring(L, 1, &len0);
    const char *a2 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a3 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDLStatic_MountEncryptedArchive((const void *)a0, (int)len0, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_MountEncryptedArchiveFile(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDLStatic_MountEncryptedArchiveFile(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_MountMedia(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_MediaSource rv = SDLStatic_MountMedia(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_MouseCaptured(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool rv = SDLStatic_MouseCaptured(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_MouseDelta(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    SDLStatic_MouseDelta(a0, &io1, &io2);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    return 2;
}

static int GenL_SDLStatic_MouseDown(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_MouseButton a1 = (SDLStatic_MouseButton)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_MouseDown(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_MouseJointDefCreate(lua_State *L)
{
    (void)L;
    b2MouseJointDef * rv = SDLStatic_MouseJointDefCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "b2MouseJointDef");
    return 1;
}

static int GenL_SDLStatic_MouseJointDefDestroy(lua_State *L)
{
    (void)L;
    b2MouseJointDef *a0 = (b2MouseJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2MouseJointDef");
    SDLStatic_MouseJointDefDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_MouseJointDefSetBodies(lua_State *L)
{
    (void)L;
    b2MouseJointDef *a0 = (b2MouseJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2MouseJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(L, 2, &a1);
    b2BodyId a2;
    GenRead_b2BodyId(L, 3, &a2);
    SDLStatic_MouseJointDefSetBodies(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_MouseJointDefSetMaxForce(lua_State *L)
{
    (void)L;
    b2MouseJointDef *a0 = (b2MouseJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2MouseJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_MouseJointDefSetMaxForce(a0, a1);
    return 0;
}

static int GenL_SDLStatic_MouseJointDefSetSpring(lua_State *L)
{
    (void)L;
    b2MouseJointDef *a0 = (b2MouseJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2MouseJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_MouseJointDefSetSpring(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_MousePosition(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    SDLStatic_MousePosition(a0, &io1, &io2);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    return 2;
}

static int GenL_SDLStatic_MousePressed(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_MouseButton a1 = (SDLStatic_MouseButton)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_MousePressed(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_MouseReleased(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_MouseButton a1 = (SDLStatic_MouseButton)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_MouseReleased(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_MouseWheel(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    SDLStatic_MouseWheel(a0, &io1, &io2);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    return 2;
}

static int GenL_SDLStatic_OpenVFSRead(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    SDL_IOStream * rv = SDLStatic_OpenVFSRead(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_IOStream");
    return 1;
}

static int GenL_SDLStatic_PhysicsBodyCount(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_PhysicsBodyCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_PhysicsGravity(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    SDLStatic_PhysicsGravity(a0, &io1, &io2);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    return 2;
}

static int GenL_SDLStatic_PhysicsOverlap(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_FRect a1;
    GenRead_SDL_FRect(L, 2, &a1);
    Uint32 a2 = (Uint32)luaL_checkinteger(L, 3);
    SDLStatic_ActorId io3 = (SDLStatic_ActorId)luaL_optinteger(L, 4, 0);
    int a4 = (int)luaL_checkinteger(L, 5);
    int rv = SDLStatic_PhysicsOverlap(a0, a1, a2, &io3, a4);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io3);
    return 2;
}

static int GenL_SDLStatic_PhysicsPaused(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool rv = SDLStatic_PhysicsPaused(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_PhysicsPixelsPerMetre(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_PhysicsPixelsPerMetre(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_PhysicsRaycast(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    Uint32 a5 = (Uint32)luaL_checkinteger(L, 6);
    SDLStatic_RayHit rv = SDLStatic_PhysicsRaycast(a0, a1, a2, a3, a4, a5);
    GenPush_SDLStatic_RayHit(L, &rv);
    return 1;
}

static int GenL_SDLStatic_PhysicsSetGravity(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_PhysicsSetGravity(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_PhysicsSetPaused(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_PhysicsSetPaused(a0, a1);
    return 0;
}

static int GenL_SDLStatic_PhysicsSetPixelsPerMetre(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_PhysicsSetPixelsPerMetre(a0, a1);
    return 0;
}

static int GenL_SDLStatic_PhysicsSetSubSteps(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_PhysicsSetSubSteps(a0, a1);
    return 0;
}

static int GenL_SDLStatic_PrismaticJointDefCreate(lua_State *L)
{
    (void)L;
    b2PrismaticJointDef * rv = SDLStatic_PrismaticJointDefCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "b2PrismaticJointDef");
    return 1;
}

static int GenL_SDLStatic_PrismaticJointDefDestroy(lua_State *L)
{
    (void)L;
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2PrismaticJointDef");
    SDLStatic_PrismaticJointDefDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_PrismaticJointDefSetAnchors(lua_State *L)
{
    (void)L;
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2PrismaticJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    SDLStatic_PrismaticJointDefSetAnchors(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_SDLStatic_PrismaticJointDefSetAxis(lua_State *L)
{
    (void)L;
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2PrismaticJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_PrismaticJointDefSetAxis(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_PrismaticJointDefSetBodies(lua_State *L)
{
    (void)L;
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2PrismaticJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(L, 2, &a1);
    b2BodyId a2;
    GenRead_b2BodyId(L, 3, &a2);
    SDLStatic_PrismaticJointDefSetBodies(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_PrismaticJointDefSetLimit(lua_State *L)
{
    (void)L;
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2PrismaticJointDef");
    bool a1 = (bool)lua_toboolean(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    SDLStatic_PrismaticJointDefSetLimit(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDLStatic_PrismaticJointDefSetMotor(lua_State *L)
{
    (void)L;
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2PrismaticJointDef");
    bool a1 = (bool)lua_toboolean(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    SDLStatic_PrismaticJointDefSetMotor(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDLStatic_QuitDebugText(lua_State *L)
{
    (void)L;
    SDLStatic_QuitDebugText();
    return 0;
}

static int GenL_SDLStatic_RegexEscape(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    char * rv = SDLStatic_RegexEscape(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDLStatic_RegexFlags(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    const char * rv = SDLStatic_RegexFlags(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_RegexGroup(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char * rv = SDLStatic_RegexGroup(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_RegexGroupBegin(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    int a1 = (int)luaL_checkinteger(L, 2);
    int rv = SDLStatic_RegexGroupBegin(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_RegexGroupCount(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    int rv = SDLStatic_RegexGroupCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_RegexGroupEnd(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    int a1 = (int)luaL_checkinteger(L, 2);
    int rv = SDLStatic_RegexGroupEnd(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_RegexMatchAt(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_RegexMatchAt(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_RegexNamedGroup(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = SDLStatic_RegexNamedGroup(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_RegexNamedGroupCount(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    int rv = SDLStatic_RegexNamedGroupCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_RegexNamedGroupName(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char * rv = SDLStatic_RegexNamedGroupName(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_RegexPattern(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    const char * rv = SDLStatic_RegexPattern(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_RegexReplace(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool a3 = (bool)lua_toboolean(L, 4);
    const char * rv = SDLStatic_RegexReplace(a0, a1, a2, a3);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_RegexSearch(lua_State *L)
{
    (void)L;
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Regex");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_RegexSearch(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_RenderDebugText(lua_State *L)
{
    (void)L;
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Renderer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = SDLStatic_RenderDebugText(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_RenderLastStats(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_RenderStats rv = SDLStatic_RenderLastStats(a0);
    GenPush_SDLStatic_RenderStats(L, &rv);
    return 1;
}

static int GenL_SDLStatic_RenderLighting(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    bool rv = SDLStatic_RenderLighting(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_RenderOverlay(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    int rv = SDLStatic_RenderOverlay(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_RenderWorld(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_Camera tmp1;
    const SDLStatic_Camera *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_SDLStatic_Camera(L, 2, &tmp1);
        a1 = &tmp1;
    }
    float a2 = (float)luaL_checknumber(L, 3);
    int rv = SDLStatic_RenderWorld(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_RevoluteJointDefCreate(lua_State *L)
{
    (void)L;
    b2RevoluteJointDef * rv = SDLStatic_RevoluteJointDefCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "b2RevoluteJointDef");
    return 1;
}

static int GenL_SDLStatic_RevoluteJointDefDestroy(lua_State *L)
{
    (void)L;
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2RevoluteJointDef");
    SDLStatic_RevoluteJointDefDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_RevoluteJointDefSetAnchors(lua_State *L)
{
    (void)L;
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2RevoluteJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    SDLStatic_RevoluteJointDefSetAnchors(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_SDLStatic_RevoluteJointDefSetBodies(lua_State *L)
{
    (void)L;
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2RevoluteJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(L, 2, &a1);
    b2BodyId a2;
    GenRead_b2BodyId(L, 3, &a2);
    SDLStatic_RevoluteJointDefSetBodies(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_RevoluteJointDefSetCollideConnected(lua_State *L)
{
    (void)L;
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2RevoluteJointDef");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_RevoluteJointDefSetCollideConnected(a0, a1);
    return 0;
}

static int GenL_SDLStatic_RevoluteJointDefSetLimit(lua_State *L)
{
    (void)L;
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2RevoluteJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_RevoluteJointDefSetLimit(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_RevoluteJointDefSetMotor(lua_State *L)
{
    (void)L;
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2RevoluteJointDef");
    bool a1 = (bool)lua_toboolean(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    SDLStatic_RevoluteJointDefSetMotor(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDLStatic_RevoluteJointDefSetSpring(lua_State *L)
{
    (void)L;
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2RevoluteJointDef");
    bool a1 = (bool)lua_toboolean(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    SDLStatic_RevoluteJointDefSetSpring(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDLStatic_SHA256(lua_State *L)
{
    (void)L;
    size_t len0 = 0;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checklstring(L, 1, &len0);
    Uint8 io2 = (Uint8)luaL_optinteger(L, 2, 0);
    bool rv = SDLStatic_SHA256((const void *)a0, (size_t)len0, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_SDLStatic_SampleLight(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float rv = SDLStatic_SampleLight(a0, a1, a2);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_SaveDelete(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_SaveDelete(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SaveExists(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool rv = SDLStatic_SaveExists(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SaveInfoOf(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_SaveInfo rv = SDLStatic_SaveInfoOf(a0, a1);
    GenPush_SDLStatic_SaveInfo(L, &rv);
    return 1;
}

static int GenL_SDLStatic_SavePath(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    char * rv = SDLStatic_SavePath(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    if (rv != NULL) { SDL_free(rv); }
    return 1;
}

static int GenL_SDLStatic_SaveSetIdentity(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    SDLStatic_SaveSetIdentity(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_SaveWrite(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    size_t len2 = 0;
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checklstring(L, 3, &len2);
    const char *a4 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = SDLStatic_SaveWrite(a0, a1, (const void *)a2, (size_t)len2, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SceneCurrent(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_Scene * rv = SDLStatic_SceneCurrent(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_Scene");
    return 1;
}

static int GenL_SDLStatic_SceneDepth(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int rv = SDLStatic_SceneDepth(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_SceneEngine(lua_State *L)
{
    (void)L;
    SDLStatic_Scene *a0 = (SDLStatic_Scene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Scene");
    SDLStatic_Engine * rv = SDLStatic_SceneEngine(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_Engine");
    return 1;
}

static int GenL_SDLStatic_SceneFind(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_Scene * rv = SDLStatic_SceneFind(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_Scene");
    return 1;
}

static int GenL_SDLStatic_SceneIsActive(lua_State *L)
{
    (void)L;
    SDLStatic_Scene *a0 = (SDLStatic_Scene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Scene");
    bool rv = SDLStatic_SceneIsActive(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SceneName(lua_State *L)
{
    (void)L;
    SDLStatic_Scene *a0 = (SDLStatic_Scene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Scene");
    const char * rv = SDLStatic_SceneName(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_ScenePop(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool rv = SDLStatic_ScenePop(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ScenePush(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const SDLStatic_SceneDef *a1 = (const SDLStatic_SceneDef *)SDLStaticGen_LuaCheckHandle(L, 2, "SDLStatic_SceneDef");
    bool rv = SDLStatic_ScenePush(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SceneReplace(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const SDLStatic_SceneDef *a1 = (const SDLStatic_SceneDef *)SDLStaticGen_LuaCheckHandle(L, 2, "SDLStatic_SceneDef");
    bool rv = SDLStatic_SceneReplace(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SceneReset(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const SDLStatic_SceneDef *a1 = (const SDLStatic_SceneDef *)SDLStaticGen_LuaCheckHandle(L, 2, "SDLStatic_SceneDef");
    bool rv = SDLStatic_SceneReset(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SceneSetTransitionColor(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDL_FColor a1;
    GenRead_SDL_FColor(L, 2, &a1);
    SDLStatic_SceneSetTransitionColor(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SceneTransitionTo(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const SDLStatic_SceneDef *a1 = (const SDLStatic_SceneDef *)SDLStaticGen_LuaCheckHandle(L, 2, "SDLStatic_SceneDef");
    SDLStatic_SceneTransition a2 = (SDLStatic_SceneTransition)luaL_checkinteger(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    bool rv = SDLStatic_SceneTransitionTo(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SceneTransitioning(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool rv = SDLStatic_SceneTransitioning(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ScriptHasHandlers(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool rv = SDLStatic_ScriptHasHandlers(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ScriptRun(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool rv = SDLStatic_ScriptRun(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ScriptSetHook(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ScriptHook a1 = (SDLStatic_ScriptHook)luaL_checkinteger(L, 2);
    Sint64 a2 = (Sint64)luaL_checkinteger(L, 3);
    bool rv = SDLStatic_ScriptSetHook(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ScriptUnbind(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_ScriptUnbind(a0);
    return 0;
}

static int GenL_SDLStatic_SetDebugTextSize(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    SDLStatic_SetDebugTextSize(a0);
    return 0;
}

static int GenL_SDLStatic_SetDeviceMotion(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDLStatic_SetDeviceMotion(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SetDirectionRepeat(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_SetDirectionRepeat(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_SetGamepadDeadzone(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_SetGamepadDeadzone(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SetGamepadMotion(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    int a1 = (int)luaL_checkinteger(L, 2);
    bool a2 = (bool)lua_toboolean(L, 3);
    bool rv = SDLStatic_SetGamepadMotion(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SetLightAmbient(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    SDL_FColor a1;
    GenRead_SDL_FColor(L, 2, &a1);
    SDLStatic_SetLightAmbient(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SetLightDebugDraw(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_SetLightDebugDraw(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SetLightMapScale(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_SetLightMapScale(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SetLightRayCount(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_SetLightRayCount(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SetLightRings(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    int a1 = (int)luaL_checkinteger(L, 2);
    SDLStatic_SetLightRings(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SetLightShadowSoftness(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_SetLightShadowSoftness(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SetLightUseShaders(lua_State *L)
{
    (void)L;
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_LightScene");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_SetLightUseShaders(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SetMouseCapture(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool a1 = (bool)lua_toboolean(L, 2);
    bool rv = SDLStatic_SetMouseCapture(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SetTextInput(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_SetTextInput(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SetTriggerThreshold(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float a1 = (float)luaL_checknumber(L, 2);
    SDLStatic_SetTriggerThreshold(a0, a1);
    return 0;
}

static int GenL_SDLStatic_ShowOpenFileDialog(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = SDLStatic_ShowOpenFileDialog(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_ShowSaveFileDialog(lua_State *L)
{
    (void)L;
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_LuaCheckHandle(L, 1, "SDL_Window");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    bool rv = SDLStatic_ShowSaveFileDialog(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_SpriteCreate(lua_State *L)
{
    (void)L;
    SDLStatic_Sprite * rv = SDLStatic_SpriteCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDLStatic_Sprite");
    return 1;
}

static int GenL_SDLStatic_SpriteDestroy(lua_State *L)
{
    (void)L;
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Sprite");
    SDLStatic_SpriteDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_SpriteSetColor(lua_State *L)
{
    (void)L;
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Sprite");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    SDLStatic_SpriteSetColor(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_SDLStatic_SpriteSetLayer(lua_State *L)
{
    (void)L;
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Sprite");
    int a1 = (int)luaL_checkinteger(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_SpriteSetLayer(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_SpriteSetOrigin(lua_State *L)
{
    (void)L;
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Sprite");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_SpriteSetOrigin(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_SpriteSetScreenSpace(lua_State *L)
{
    (void)L;
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Sprite");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_SpriteSetScreenSpace(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SpriteSetSize(lua_State *L)
{
    (void)L;
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Sprite");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_SpriteSetSize(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_SpriteSetSortByY(lua_State *L)
{
    (void)L;
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Sprite");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_SpriteSetSortByY(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SpriteSetSource(lua_State *L)
{
    (void)L;
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Sprite");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    SDLStatic_SpriteSetSource(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_SDLStatic_SpriteSetTexture(lua_State *L)
{
    (void)L;
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Sprite");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_LuaCheckHandle(L, 2, "SDL_Texture");
    SDLStatic_SpriteSetTexture(a0, a1);
    return 0;
}

static int GenL_SDLStatic_SpriteSetVisible(lua_State *L)
{
    (void)L;
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Sprite");
    bool a1 = (bool)lua_toboolean(L, 2);
    SDLStatic_SpriteSetVisible(a0, a1);
    return 0;
}

static int GenL_SDLStatic_Text(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char * rv = SDLStatic_Text(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_TextCount(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = SDLStatic_TextCount(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TextHas(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDLStatic_TextHas(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_TextLanguage(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char * rv = SDLStatic_TextLanguage(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_TextLoad(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    bool rv = SDLStatic_TextLoad(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_TextLoadFile(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    bool rv = SDLStatic_TextLoadFile(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_TextSetLanguage(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    SDLStatic_TextSetLanguage(a0, a1);
    return 0;
}

static int GenL_SDLStatic_TextTyped(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    const char * rv = SDLStatic_TextTyped(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_Texture(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    SDLStatic_TextureId a1 = (SDLStatic_TextureId)luaL_checkinteger(L, 2);
    SDL_Texture * rv = SDLStatic_Texture(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "SDL_Texture");
    return 1;
}

static int GenL_SDLStatic_TiledLayerCount(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledLayerCount(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledLayerName(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char * rv = SDLStatic_TiledLayerName(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_TiledLayerType(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char * rv = SDLStatic_TiledLayerType(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_SDLStatic_TiledMapHeight(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledMapHeight(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledMapWidth(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledMapWidth(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledObjectAt(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    SDLStatic_TiledObject *a3 = (SDLStatic_TiledObject *)SDLStaticGen_LuaCheckHandle(L, 4, "SDLStatic_TiledObject");
    bool rv = SDLStatic_TiledObjectAt(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_SDLStatic_TiledObjectCount(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    int rv = SDLStatic_TiledObjectCount(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledRaw(lua_State *L)
{
    (void)L;
    SDLStatic_TiledMap *a0 = (SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    cute_tiled_map_t * rv = SDLStatic_TiledRaw(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "cute_tiled_map_t");
    return 1;
}

static int GenL_SDLStatic_TiledTileAt(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int rv = SDLStatic_TiledTileAt(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledTileHeight(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledTileHeight(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TiledTileWidth(lua_State *L)
{
    (void)L;
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledTileWidth(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_SDLStatic_TouchPinch(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_TouchPinch(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_TouchRotation(lua_State *L)
{
    (void)L;
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_LuaCheckHandle(L, 1, "SDLStatic_Engine");
    float rv = SDLStatic_TouchRotation(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_SDLStatic_WeldJointDefCreate(lua_State *L)
{
    (void)L;
    b2WeldJointDef * rv = SDLStatic_WeldJointDefCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "b2WeldJointDef");
    return 1;
}

static int GenL_SDLStatic_WeldJointDefDestroy(lua_State *L)
{
    (void)L;
    b2WeldJointDef *a0 = (b2WeldJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2WeldJointDef");
    SDLStatic_WeldJointDefDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_WeldJointDefSetAnchors(lua_State *L)
{
    (void)L;
    b2WeldJointDef *a0 = (b2WeldJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2WeldJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    SDLStatic_WeldJointDefSetAnchors(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_SDLStatic_WeldJointDefSetBodies(lua_State *L)
{
    (void)L;
    b2WeldJointDef *a0 = (b2WeldJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2WeldJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(L, 2, &a1);
    b2BodyId a2;
    GenRead_b2BodyId(L, 3, &a2);
    SDLStatic_WeldJointDefSetBodies(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_WeldJointDefSetSpring(lua_State *L)
{
    (void)L;
    b2WeldJointDef *a0 = (b2WeldJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2WeldJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    SDLStatic_WeldJointDefSetSpring(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_SDLStatic_WheelJointDefCreate(lua_State *L)
{
    (void)L;
    b2WheelJointDef * rv = SDLStatic_WheelJointDefCreate();
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "b2WheelJointDef");
    return 1;
}

static int GenL_SDLStatic_WheelJointDefDestroy(lua_State *L)
{
    (void)L;
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2WheelJointDef");
    SDLStatic_WheelJointDefDestroy(a0);
    return 0;
}

static int GenL_SDLStatic_WheelJointDefSetAnchors(lua_State *L)
{
    (void)L;
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2WheelJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    SDLStatic_WheelJointDefSetAnchors(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_SDLStatic_WheelJointDefSetAxis(lua_State *L)
{
    (void)L;
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2WheelJointDef");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    SDLStatic_WheelJointDefSetAxis(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_WheelJointDefSetBodies(lua_State *L)
{
    (void)L;
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2WheelJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(L, 2, &a1);
    b2BodyId a2;
    GenRead_b2BodyId(L, 3, &a2);
    SDLStatic_WheelJointDefSetBodies(a0, a1, a2);
    return 0;
}

static int GenL_SDLStatic_WheelJointDefSetMotor(lua_State *L)
{
    (void)L;
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2WheelJointDef");
    bool a1 = (bool)lua_toboolean(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    SDLStatic_WheelJointDefSetMotor(a0, a1, a2, a3);
    return 0;
}

static int GenL_SDLStatic_WheelJointDefSetSpring(lua_State *L)
{
    (void)L;
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_LuaCheckHandle(L, 1, "b2WheelJointDef");
    bool a1 = (bool)lua_toboolean(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    SDLStatic_WheelJointDefSetSpring(a0, a1, a2, a3);
    return 0;
}

int SDLStaticGen_OpenLua_sdlstatic(lua_State *L);
int SDLStaticGen_OpenLua_sdlstatic(lua_State *L)
{
    lua_createtable(L, 0, 517);
    lua_pushcfunction(L, GenL_SDLStatic_ActionBind);
    lua_setfield(L, -2, "ActionBind");
    lua_pushcfunction(L, GenL_SDLStatic_ActionBindAxis);
    lua_setfield(L, -2, "ActionBindAxis");
    lua_pushcfunction(L, GenL_SDLStatic_ActionBindDirection);
    lua_setfield(L, -2, "ActionBindDirection");
    lua_pushcfunction(L, GenL_SDLStatic_ActionBindKey);
    lua_setfield(L, -2, "ActionBindKey");
    lua_pushcfunction(L, GenL_SDLStatic_ActionBindKeySigned);
    lua_setfield(L, -2, "ActionBindKeySigned");
    lua_pushcfunction(L, GenL_SDLStatic_ActionBindMouse);
    lua_setfield(L, -2, "ActionBindMouse");
    lua_pushcfunction(L, GenL_SDLStatic_ActionBindPad);
    lua_setfield(L, -2, "ActionBindPad");
    lua_pushcfunction(L, GenL_SDLStatic_ActionBindingAt);
    lua_setfield(L, -2, "ActionBindingAt");
    lua_pushcfunction(L, GenL_SDLStatic_ActionBindingCount);
    lua_setfield(L, -2, "ActionBindingCount");
    lua_pushcfunction(L, GenL_SDLStatic_ActionCapture);
    lua_setfield(L, -2, "ActionCapture");
    lua_pushcfunction(L, GenL_SDLStatic_ActionClear);
    lua_setfield(L, -2, "ActionClear");
    lua_pushcfunction(L, GenL_SDLStatic_ActionCount);
    lua_setfield(L, -2, "ActionCount");
    lua_pushcfunction(L, GenL_SDLStatic_ActionDown);
    lua_setfield(L, -2, "ActionDown");
    lua_pushcfunction(L, GenL_SDLStatic_ActionMapCreate);
    lua_setfield(L, -2, "ActionMapCreate");
    lua_pushcfunction(L, GenL_SDLStatic_ActionMapDestroy);
    lua_setfield(L, -2, "ActionMapDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_ActionMapKeyboardPlayer);
    lua_setfield(L, -2, "ActionMapKeyboardPlayer");
    lua_pushcfunction(L, GenL_SDLStatic_ActionMapLoad);
    lua_setfield(L, -2, "ActionMapLoad");
    lua_pushcfunction(L, GenL_SDLStatic_ActionMapLoadToml);
    lua_setfield(L, -2, "ActionMapLoadToml");
    lua_pushcfunction(L, GenL_SDLStatic_ActionMapSave);
    lua_setfield(L, -2, "ActionMapSave");
    lua_pushcfunction(L, GenL_SDLStatic_ActionMapSetKeyboardPlayer);
    lua_setfield(L, -2, "ActionMapSetKeyboardPlayer");
    lua_pushcfunction(L, GenL_SDLStatic_ActionMapToToml);
    lua_setfield(L, -2, "ActionMapToToml");
    lua_pushcfunction(L, GenL_SDLStatic_ActionName);
    lua_setfield(L, -2, "ActionName");
    lua_pushcfunction(L, GenL_SDLStatic_ActionPressed);
    lua_setfield(L, -2, "ActionPressed");
    lua_pushcfunction(L, GenL_SDLStatic_ActionReleased);
    lua_setfield(L, -2, "ActionReleased");
    lua_pushcfunction(L, GenL_SDLStatic_ActionValue);
    lua_setfield(L, -2, "ActionValue");
    lua_pushcfunction(L, GenL_SDLStatic_ActionVector);
    lua_setfield(L, -2, "ActionVector");
    lua_pushcfunction(L, GenL_SDLStatic_ActorAddBody);
    lua_setfield(L, -2, "ActorAddBody");
    lua_pushcfunction(L, GenL_SDLStatic_ActorAddLight);
    lua_setfield(L, -2, "ActorAddLight");
    lua_pushcfunction(L, GenL_SDLStatic_ActorAlive);
    lua_setfield(L, -2, "ActorAlive");
    lua_pushcfunction(L, GenL_SDLStatic_ActorAngularVelocity);
    lua_setfield(L, -2, "ActorAngularVelocity");
    lua_pushcfunction(L, GenL_SDLStatic_ActorApplyForce);
    lua_setfield(L, -2, "ActorApplyForce");
    lua_pushcfunction(L, GenL_SDLStatic_ActorApplyImpulse);
    lua_setfield(L, -2, "ActorApplyImpulse");
    lua_pushcfunction(L, GenL_SDLStatic_ActorBodyBounds);
    lua_setfield(L, -2, "ActorBodyBounds");
    lua_pushcfunction(L, GenL_SDLStatic_ActorBroadcast);
    lua_setfield(L, -2, "ActorBroadcast");
    lua_pushcfunction(L, GenL_SDLStatic_ActorChild);
    lua_setfield(L, -2, "ActorChild");
    lua_pushcfunction(L, GenL_SDLStatic_ActorChildCount);
    lua_setfield(L, -2, "ActorChildCount");
    lua_pushcfunction(L, GenL_SDLStatic_ActorClear);
    lua_setfield(L, -2, "ActorClear");
    lua_pushcfunction(L, GenL_SDLStatic_ActorClearSprite);
    lua_setfield(L, -2, "ActorClearSprite");
    lua_pushcfunction(L, GenL_SDLStatic_ActorCount);
    lua_setfield(L, -2, "ActorCount");
    lua_pushcfunction(L, GenL_SDLStatic_ActorDefCreate);
    lua_setfield(L, -2, "ActorDefCreate");
    lua_pushcfunction(L, GenL_SDLStatic_ActorDefDestroy);
    lua_setfield(L, -2, "ActorDefDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_ActorDefSetName);
    lua_setfield(L, -2, "ActorDefSetName");
    lua_pushcfunction(L, GenL_SDLStatic_ActorDefSetParent);
    lua_setfield(L, -2, "ActorDefSetParent");
    lua_pushcfunction(L, GenL_SDLStatic_ActorDefSetPosition);
    lua_setfield(L, -2, "ActorDefSetPosition");
    lua_pushcfunction(L, GenL_SDLStatic_ActorDefSetRotation);
    lua_setfield(L, -2, "ActorDefSetRotation");
    lua_pushcfunction(L, GenL_SDLStatic_ActorDefSetScale);
    lua_setfield(L, -2, "ActorDefSetScale");
    lua_pushcfunction(L, GenL_SDLStatic_ActorDefSetStateSize);
    lua_setfield(L, -2, "ActorDefSetStateSize");
    lua_pushcfunction(L, GenL_SDLStatic_ActorDefSetTags);
    lua_setfield(L, -2, "ActorDefSetTags");
    lua_pushcfunction(L, GenL_SDLStatic_ActorDefSetType);
    lua_setfield(L, -2, "ActorDefSetType");
    lua_pushcfunction(L, GenL_SDLStatic_ActorDestroy);
    lua_setfield(L, -2, "ActorDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_ActorEnabled);
    lua_setfield(L, -2, "ActorEnabled");
    lua_pushcfunction(L, GenL_SDLStatic_ActorEngine);
    lua_setfield(L, -2, "ActorEngine");
    lua_pushcfunction(L, GenL_SDLStatic_ActorFindByName);
    lua_setfield(L, -2, "ActorFindByName");
    lua_pushcfunction(L, GenL_SDLStatic_ActorFindByType);
    lua_setfield(L, -2, "ActorFindByType");
    lua_pushcfunction(L, GenL_SDLStatic_ActorGet);
    lua_setfield(L, -2, "ActorGet");
    lua_pushcfunction(L, GenL_SDLStatic_ActorGetId);
    lua_setfield(L, -2, "ActorGetId");
    lua_pushcfunction(L, GenL_SDLStatic_ActorGetTags);
    lua_setfield(L, -2, "ActorGetTags");
    lua_pushcfunction(L, GenL_SDLStatic_ActorHasBody);
    lua_setfield(L, -2, "ActorHasBody");
    lua_pushcfunction(L, GenL_SDLStatic_ActorHasTags);
    lua_setfield(L, -2, "ActorHasTags");
    lua_pushcfunction(L, GenL_SDLStatic_ActorLocal);
    lua_setfield(L, -2, "ActorLocal");
    lua_pushcfunction(L, GenL_SDLStatic_ActorMove);
    lua_setfield(L, -2, "ActorMove");
    lua_pushcfunction(L, GenL_SDLStatic_ActorName);
    lua_setfield(L, -2, "ActorName");
    lua_pushcfunction(L, GenL_SDLStatic_ActorParent);
    lua_setfield(L, -2, "ActorParent");
    lua_pushcfunction(L, GenL_SDLStatic_ActorQuery);
    lua_setfield(L, -2, "ActorQuery");
    lua_pushcfunction(L, GenL_SDLStatic_ActorRemoveBody);
    lua_setfield(L, -2, "ActorRemoveBody");
    lua_pushcfunction(L, GenL_SDLStatic_ActorRemoveLight);
    lua_setfield(L, -2, "ActorRemoveLight");
    lua_pushcfunction(L, GenL_SDLStatic_ActorRenderTransform);
    lua_setfield(L, -2, "ActorRenderTransform");
    lua_pushcfunction(L, GenL_SDLStatic_ActorSend);
    lua_setfield(L, -2, "ActorSend");
    lua_pushcfunction(L, GenL_SDLStatic_ActorSetAngularVelocity);
    lua_setfield(L, -2, "ActorSetAngularVelocity");
    lua_pushcfunction(L, GenL_SDLStatic_ActorSetEnabled);
    lua_setfield(L, -2, "ActorSetEnabled");
    lua_pushcfunction(L, GenL_SDLStatic_ActorSetLocal);
    lua_setfield(L, -2, "ActorSetLocal");
    lua_pushcfunction(L, GenL_SDLStatic_ActorSetParent);
    lua_setfield(L, -2, "ActorSetParent");
    lua_pushcfunction(L, GenL_SDLStatic_ActorSetPosition);
    lua_setfield(L, -2, "ActorSetPosition");
    lua_pushcfunction(L, GenL_SDLStatic_ActorSetSprite);
    lua_setfield(L, -2, "ActorSetSprite");
    lua_pushcfunction(L, GenL_SDLStatic_ActorSetTags);
    lua_setfield(L, -2, "ActorSetTags");
    lua_pushcfunction(L, GenL_SDLStatic_ActorSetVelocity);
    lua_setfield(L, -2, "ActorSetVelocity");
    lua_pushcfunction(L, GenL_SDLStatic_ActorSpawn);
    lua_setfield(L, -2, "ActorSpawn");
    lua_pushcfunction(L, GenL_SDLStatic_ActorSprite);
    lua_setfield(L, -2, "ActorSprite");
    lua_pushcfunction(L, GenL_SDLStatic_ActorTeleport);
    lua_setfield(L, -2, "ActorTeleport");
    lua_pushcfunction(L, GenL_SDLStatic_ActorTeleportBody);
    lua_setfield(L, -2, "ActorTeleportBody");
    lua_pushcfunction(L, GenL_SDLStatic_ActorType);
    lua_setfield(L, -2, "ActorType");
    lua_pushcfunction(L, GenL_SDLStatic_ActorVelocity);
    lua_setfield(L, -2, "ActorVelocity");
    lua_pushcfunction(L, GenL_SDLStatic_ActorWakeBody);
    lua_setfield(L, -2, "ActorWakeBody");
    lua_pushcfunction(L, GenL_SDLStatic_ActorWorld);
    lua_setfield(L, -2, "ActorWorld");
    lua_pushcfunction(L, GenL_SDLStatic_AddDarkZone);
    lua_setfield(L, -2, "AddDarkZone");
    lua_pushcfunction(L, GenL_SDLStatic_AddLight);
    lua_setfield(L, -2, "AddLight");
    lua_pushcfunction(L, GenL_SDLStatic_AddOccluderRect);
    lua_setfield(L, -2, "AddOccluderRect");
    lua_pushcfunction(L, GenL_SDLStatic_AddOccluderSegment);
    lua_setfield(L, -2, "AddOccluderSegment");
    lua_pushcfunction(L, GenL_SDLStatic_AnyInput);
    lua_setfield(L, -2, "AnyInput");
    lua_pushcfunction(L, GenL_SDLStatic_AssetPath);
    lua_setfield(L, -2, "AssetPath");
    lua_pushcfunction(L, GenL_SDLStatic_AssetRelease);
    lua_setfield(L, -2, "AssetRelease");
    lua_pushcfunction(L, GenL_SDLStatic_AssetRetain);
    lua_setfield(L, -2, "AssetRetain");
    lua_pushcfunction(L, GenL_SDLStatic_AssetStatusOf);
    lua_setfield(L, -2, "AssetStatusOf");
    lua_pushcfunction(L, GenL_SDLStatic_AssetsFrameBudget);
    lua_setfield(L, -2, "AssetsFrameBudget");
    lua_pushcfunction(L, GenL_SDLStatic_AssetsLoaded);
    lua_setfield(L, -2, "AssetsLoaded");
    lua_pushcfunction(L, GenL_SDLStatic_AssetsPending);
    lua_setfield(L, -2, "AssetsPending");
    lua_pushcfunction(L, GenL_SDLStatic_AssetsProgress);
    lua_setfield(L, -2, "AssetsProgress");
    lua_pushcfunction(L, GenL_SDLStatic_AssetsReady);
    lua_setfield(L, -2, "AssetsReady");
    lua_pushcfunction(L, GenL_SDLStatic_AssetsSetFrameBudget);
    lua_setfield(L, -2, "AssetsSetFrameBudget");
    lua_pushcfunction(L, GenL_SDLStatic_AssetsSetWorkers);
    lua_setfield(L, -2, "AssetsSetWorkers");
    lua_pushcfunction(L, GenL_SDLStatic_AssetsWait);
    lua_setfield(L, -2, "AssetsWait");
    lua_pushcfunction(L, GenL_SDLStatic_BidiBaseIsRTL);
    lua_setfield(L, -2, "BidiBaseIsRTL");
    lua_pushcfunction(L, GenL_SDLStatic_BindingFromString);
    lua_setfield(L, -2, "BindingFromString");
    lua_pushcfunction(L, GenL_SDLStatic_BindingToString);
    lua_setfield(L, -2, "BindingToString");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefDestroy);
    lua_setfield(L, -2, "BodyDefDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefSetBullet);
    lua_setfield(L, -2, "BodyDefSetBullet");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefSetFilter);
    lua_setfield(L, -2, "BodyDefSetFilter");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefSetFixedRotation);
    lua_setfield(L, -2, "BodyDefSetFixedRotation");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefSetGravityScale);
    lua_setfield(L, -2, "BodyDefSetGravityScale");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefSetMaterial);
    lua_setfield(L, -2, "BodyDefSetMaterial");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefSetOffset);
    lua_setfield(L, -2, "BodyDefSetOffset");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefSetSensor);
    lua_setfield(L, -2, "BodyDefSetSensor");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefSetShape);
    lua_setfield(L, -2, "BodyDefSetShape");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefSetSize);
    lua_setfield(L, -2, "BodyDefSetSize");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefSetType);
    lua_setfield(L, -2, "BodyDefSetType");
    lua_pushcfunction(L, GenL_SDLStatic_BodyDefault);
    lua_setfield(L, -2, "BodyDefault");
    lua_pushcfunction(L, GenL_SDLStatic_CameraBegin);
    lua_setfield(L, -2, "CameraBegin");
    lua_pushcfunction(L, GenL_SDLStatic_CameraDestroy);
    lua_setfield(L, -2, "CameraDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_CameraEnd);
    lua_setfield(L, -2, "CameraEnd");
    lua_pushcfunction(L, GenL_SDLStatic_CameraFollow);
    lua_setfield(L, -2, "CameraFollow");
    lua_pushcfunction(L, GenL_SDLStatic_CameraInit);
    lua_setfield(L, -2, "CameraInit");
    lua_pushcfunction(L, GenL_SDLStatic_CameraPoint);
    lua_setfield(L, -2, "CameraPoint");
    lua_pushcfunction(L, GenL_SDLStatic_CameraRect);
    lua_setfield(L, -2, "CameraRect");
    lua_pushcfunction(L, GenL_SDLStatic_CameraScreenToWorld);
    lua_setfield(L, -2, "CameraScreenToWorld");
    lua_pushcfunction(L, GenL_SDLStatic_CameraSetBounds);
    lua_setfield(L, -2, "CameraSetBounds");
    lua_pushcfunction(L, GenL_SDLStatic_CameraSetDeadzone);
    lua_setfield(L, -2, "CameraSetDeadzone");
    lua_pushcfunction(L, GenL_SDLStatic_CameraSetSmoothing);
    lua_setfield(L, -2, "CameraSetSmoothing");
    lua_pushcfunction(L, GenL_SDLStatic_CameraSetViewport);
    lua_setfield(L, -2, "CameraSetViewport");
    lua_pushcfunction(L, GenL_SDLStatic_CameraSetZoom);
    lua_setfield(L, -2, "CameraSetZoom");
    lua_pushcfunction(L, GenL_SDLStatic_CameraShake);
    lua_setfield(L, -2, "CameraShake");
    lua_pushcfunction(L, GenL_SDLStatic_CameraSnap);
    lua_setfield(L, -2, "CameraSnap");
    lua_pushcfunction(L, GenL_SDLStatic_CameraSplit);
    lua_setfield(L, -2, "CameraSplit");
    lua_pushcfunction(L, GenL_SDLStatic_CameraUpdate);
    lua_setfield(L, -2, "CameraUpdate");
    lua_pushcfunction(L, GenL_SDLStatic_CameraVisible);
    lua_setfield(L, -2, "CameraVisible");
    lua_pushcfunction(L, GenL_SDLStatic_CameraX);
    lua_setfield(L, -2, "CameraX");
    lua_pushcfunction(L, GenL_SDLStatic_CameraY);
    lua_setfield(L, -2, "CameraY");
    lua_pushcfunction(L, GenL_SDLStatic_CompileRegex);
    lua_setfield(L, -2, "CompileRegex");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigCreate);
    lua_setfield(L, -2, "ConfigCreate");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigDestroy);
    lua_setfield(L, -2, "ConfigDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetAutoMount);
    lua_setfield(L, -2, "ConfigSetAutoMount");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetBackend);
    lua_setfield(L, -2, "ConfigSetBackend");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetDesignSize);
    lua_setfield(L, -2, "ConfigSetDesignSize");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetFullscreen);
    lua_setfield(L, -2, "ConfigSetFullscreen");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetGraphics);
    lua_setfield(L, -2, "ConfigSetGraphics");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetHeadless);
    lua_setfield(L, -2, "ConfigSetHeadless");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetHighDpi);
    lua_setfield(L, -2, "ConfigSetHighDpi");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetManualClock);
    lua_setfield(L, -2, "ConfigSetManualClock");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetMaxFps);
    lua_setfield(L, -2, "ConfigSetMaxFps");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetMediaPath);
    lua_setfield(L, -2, "ConfigSetMediaPath");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetPresentation);
    lua_setfield(L, -2, "ConfigSetPresentation");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetResizable);
    lua_setfield(L, -2, "ConfigSetResizable");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetTickRate);
    lua_setfield(L, -2, "ConfigSetTickRate");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetTitle);
    lua_setfield(L, -2, "ConfigSetTitle");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetVsync);
    lua_setfield(L, -2, "ConfigSetVsync");
    lua_pushcfunction(L, GenL_SDLStatic_ConfigSetWindowSize);
    lua_setfield(L, -2, "ConfigSetWindowSize");
    lua_pushcfunction(L, GenL_SDLStatic_CountSignalConnections);
    lua_setfield(L, -2, "CountSignalConnections");
    lua_pushcfunction(L, GenL_SDLStatic_CreateChipSFX);
    lua_setfield(L, -2, "CreateChipSFX");
    lua_pushcfunction(L, GenL_SDLStatic_CreateChipTone);
    lua_setfield(L, -2, "CreateChipTone");
    lua_pushcfunction(L, GenL_SDLStatic_CreateChipTune);
    lua_setfield(L, -2, "CreateChipTune");
    lua_pushcfunction(L, GenL_SDLStatic_CreateEngine);
    lua_setfield(L, -2, "CreateEngine");
    lua_pushcfunction(L, GenL_SDLStatic_CreateGui);
    lua_setfield(L, -2, "CreateGui");
    lua_pushcfunction(L, GenL_SDLStatic_CreateGuiWithGlyphs);
    lua_setfield(L, -2, "CreateGuiWithGlyphs");
    lua_pushcfunction(L, GenL_SDLStatic_CreateLightScene);
    lua_setfield(L, -2, "CreateLightScene");
    lua_pushcfunction(L, GenL_SDLStatic_CreateSignalEmitter);
    lua_setfield(L, -2, "CreateSignalEmitter");
    lua_pushcfunction(L, GenL_SDLStatic_CryptoSelfTest);
    lua_setfield(L, -2, "CryptoSelfTest");
    lua_pushcfunction(L, GenL_SDLStatic_DayNightAmbient);
    lua_setfield(L, -2, "DayNightAmbient");
    lua_pushcfunction(L, GenL_SDLStatic_DayNightSunlight);
    lua_setfield(L, -2, "DayNightSunlight");
    lua_pushcfunction(L, GenL_SDLStatic_DestroyEngine);
    lua_setfield(L, -2, "DestroyEngine");
    lua_pushcfunction(L, GenL_SDLStatic_DestroyGui);
    lua_setfield(L, -2, "DestroyGui");
    lua_pushcfunction(L, GenL_SDLStatic_DestroyLightScene);
    lua_setfield(L, -2, "DestroyLightScene");
    lua_pushcfunction(L, GenL_SDLStatic_DestroyRegex);
    lua_setfield(L, -2, "DestroyRegex");
    lua_pushcfunction(L, GenL_SDLStatic_DestroySignalEmitter);
    lua_setfield(L, -2, "DestroySignalEmitter");
    lua_pushcfunction(L, GenL_SDLStatic_DeviceAccelerometer);
    lua_setfield(L, -2, "DeviceAccelerometer");
    lua_pushcfunction(L, GenL_SDLStatic_DeviceGyro);
    lua_setfield(L, -2, "DeviceGyro");
    lua_pushcfunction(L, GenL_SDLStatic_DialogDeliverSave);
    lua_setfield(L, -2, "DialogDeliverSave");
    lua_pushcfunction(L, GenL_SDLStatic_DialogPath);
    lua_setfield(L, -2, "DialogPath");
    lua_pushcfunction(L, GenL_SDLStatic_DialogReset);
    lua_setfield(L, -2, "DialogReset");
    lua_pushcfunction(L, GenL_SDLStatic_DialogStatus);
    lua_setfield(L, -2, "DialogStatus");
    lua_pushcfunction(L, GenL_SDLStatic_DisconnectSignal);
    lua_setfield(L, -2, "DisconnectSignal");
    lua_pushcfunction(L, GenL_SDLStatic_DistanceJointDefCreate);
    lua_setfield(L, -2, "DistanceJointDefCreate");
    lua_pushcfunction(L, GenL_SDLStatic_DistanceJointDefDestroy);
    lua_setfield(L, -2, "DistanceJointDefDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_DistanceJointDefSetAnchors);
    lua_setfield(L, -2, "DistanceJointDefSetAnchors");
    lua_pushcfunction(L, GenL_SDLStatic_DistanceJointDefSetBodies);
    lua_setfield(L, -2, "DistanceJointDefSetBodies");
    lua_pushcfunction(L, GenL_SDLStatic_DistanceJointDefSetCollideConnected);
    lua_setfield(L, -2, "DistanceJointDefSetCollideConnected");
    lua_pushcfunction(L, GenL_SDLStatic_DistanceJointDefSetLength);
    lua_setfield(L, -2, "DistanceJointDefSetLength");
    lua_pushcfunction(L, GenL_SDLStatic_DistanceJointDefSetLimit);
    lua_setfield(L, -2, "DistanceJointDefSetLimit");
    lua_pushcfunction(L, GenL_SDLStatic_DistanceJointDefSetSpring);
    lua_setfield(L, -2, "DistanceJointDefSetSpring");
    lua_pushcfunction(L, GenL_SDLStatic_DrawPhysicsWorld);
    lua_setfield(L, -2, "DrawPhysicsWorld");
    lua_pushcfunction(L, GenL_SDLStatic_EncodeDataBase64);
    lua_setfield(L, -2, "EncodeDataBase64");
    lua_pushcfunction(L, GenL_SDLStatic_EngineAdvance);
    lua_setfield(L, -2, "EngineAdvance");
    lua_pushcfunction(L, GenL_SDLStatic_EngineAlpha);
    lua_setfield(L, -2, "EngineAlpha");
    lua_pushcfunction(L, GenL_SDLStatic_EngineAssetScale);
    lua_setfield(L, -2, "EngineAssetScale");
    lua_pushcfunction(L, GenL_SDLStatic_EngineDelta);
    lua_setfield(L, -2, "EngineDelta");
    lua_pushcfunction(L, GenL_SDLStatic_EngineDesignSize);
    lua_setfield(L, -2, "EngineDesignSize");
    lua_pushcfunction(L, GenL_SDLStatic_EngineDisplay);
    lua_setfield(L, -2, "EngineDisplay");
    lua_pushcfunction(L, GenL_SDLStatic_EngineDisplayCount);
    lua_setfield(L, -2, "EngineDisplayCount");
    lua_pushcfunction(L, GenL_SDLStatic_EngineDisplayName);
    lua_setfield(L, -2, "EngineDisplayName");
    lua_pushcfunction(L, GenL_SDLStatic_EngineEffectsAvailable);
    lua_setfield(L, -2, "EngineEffectsAvailable");
    lua_pushcfunction(L, GenL_SDLStatic_EngineEmbedMedia);
    lua_setfield(L, -2, "EngineEmbedMedia");
    lua_pushcfunction(L, GenL_SDLStatic_EngineFps);
    lua_setfield(L, -2, "EngineFps");
    lua_pushcfunction(L, GenL_SDLStatic_EngineFrameCount);
    lua_setfield(L, -2, "EngineFrameCount");
    lua_pushcfunction(L, GenL_SDLStatic_EngineMaxFps);
    lua_setfield(L, -2, "EngineMaxFps");
    lua_pushcfunction(L, GenL_SDLStatic_EngineMediaPath);
    lua_setfield(L, -2, "EngineMediaPath");
    lua_pushcfunction(L, GenL_SDLStatic_EngineMediaSource);
    lua_setfield(L, -2, "EngineMediaSource");
    lua_pushcfunction(L, GenL_SDLStatic_EngineOverloadFrames);
    lua_setfield(L, -2, "EngineOverloadFrames");
    lua_pushcfunction(L, GenL_SDLStatic_EnginePixelSize);
    lua_setfield(L, -2, "EnginePixelSize");
    lua_pushcfunction(L, GenL_SDLStatic_EnginePresentation_);
    lua_setfield(L, -2, "EnginePresentation_");
    lua_pushcfunction(L, GenL_SDLStatic_EngineQuit);
    lua_setfield(L, -2, "EngineQuit");
    lua_pushcfunction(L, GenL_SDLStatic_EngineRenderScale);
    lua_setfield(L, -2, "EngineRenderScale");
    lua_pushcfunction(L, GenL_SDLStatic_EngineRenderer);
    lua_setfield(L, -2, "EngineRenderer");
    lua_pushcfunction(L, GenL_SDLStatic_EngineSafeRect);
    lua_setfield(L, -2, "EngineSafeRect");
    lua_pushcfunction(L, GenL_SDLStatic_EngineSetClearColor);
    lua_setfield(L, -2, "EngineSetClearColor");
    lua_pushcfunction(L, GenL_SDLStatic_EngineSetDisplay);
    lua_setfield(L, -2, "EngineSetDisplay");
    lua_pushcfunction(L, GenL_SDLStatic_EngineSetGraphics);
    lua_setfield(L, -2, "EngineSetGraphics");
    lua_pushcfunction(L, GenL_SDLStatic_EngineSetMaxFps);
    lua_setfield(L, -2, "EngineSetMaxFps");
    lua_pushcfunction(L, GenL_SDLStatic_EngineSetMediaPassword);
    lua_setfield(L, -2, "EngineSetMediaPassword");
    lua_pushcfunction(L, GenL_SDLStatic_EngineSetPresentation);
    lua_setfield(L, -2, "EngineSetPresentation");
    lua_pushcfunction(L, GenL_SDLStatic_EngineSetRefreshRate);
    lua_setfield(L, -2, "EngineSetRefreshRate");
    lua_pushcfunction(L, GenL_SDLStatic_EngineSetTickRate);
    lua_setfield(L, -2, "EngineSetTickRate");
    lua_pushcfunction(L, GenL_SDLStatic_EngineSetTimeScale);
    lua_setfield(L, -2, "EngineSetTimeScale");
    lua_pushcfunction(L, GenL_SDLStatic_EngineStep);
    lua_setfield(L, -2, "EngineStep");
    lua_pushcfunction(L, GenL_SDLStatic_EngineStepsLastFrame);
    lua_setfield(L, -2, "EngineStepsLastFrame");
    lua_pushcfunction(L, GenL_SDLStatic_EngineTick);
    lua_setfield(L, -2, "EngineTick");
    lua_pushcfunction(L, GenL_SDLStatic_EngineTickRate);
    lua_setfield(L, -2, "EngineTickRate");
    lua_pushcfunction(L, GenL_SDLStatic_EngineTimeScale);
    lua_setfield(L, -2, "EngineTimeScale");
    lua_pushcfunction(L, GenL_SDLStatic_EngineViewRect);
    lua_setfield(L, -2, "EngineViewRect");
    lua_pushcfunction(L, GenL_SDLStatic_EngineWindow);
    lua_setfield(L, -2, "EngineWindow");
    lua_pushcfunction(L, GenL_SDLStatic_EngineWindowToDesign);
    lua_setfield(L, -2, "EngineWindowToDesign");
    lua_pushcfunction(L, GenL_SDLStatic_EventCreate);
    lua_setfield(L, -2, "EventCreate");
    lua_pushcfunction(L, GenL_SDLStatic_EventDestroy);
    lua_setfield(L, -2, "EventDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_EventGamepadAxis);
    lua_setfield(L, -2, "EventGamepadAxis");
    lua_pushcfunction(L, GenL_SDLStatic_EventGamepadAxisValue);
    lua_setfield(L, -2, "EventGamepadAxisValue");
    lua_pushcfunction(L, GenL_SDLStatic_EventGamepadButton);
    lua_setfield(L, -2, "EventGamepadButton");
    lua_pushcfunction(L, GenL_SDLStatic_EventGamepadWhich);
    lua_setfield(L, -2, "EventGamepadWhich");
    lua_pushcfunction(L, GenL_SDLStatic_EventKeyModifiers);
    lua_setfield(L, -2, "EventKeyModifiers");
    lua_pushcfunction(L, GenL_SDLStatic_EventKeyRepeat);
    lua_setfield(L, -2, "EventKeyRepeat");
    lua_pushcfunction(L, GenL_SDLStatic_EventKeyScancode);
    lua_setfield(L, -2, "EventKeyScancode");
    lua_pushcfunction(L, GenL_SDLStatic_EventMouseButton);
    lua_setfield(L, -2, "EventMouseButton");
    lua_pushcfunction(L, GenL_SDLStatic_EventMouseDeltaX);
    lua_setfield(L, -2, "EventMouseDeltaX");
    lua_pushcfunction(L, GenL_SDLStatic_EventMouseDeltaY);
    lua_setfield(L, -2, "EventMouseDeltaY");
    lua_pushcfunction(L, GenL_SDLStatic_EventMouseX);
    lua_setfield(L, -2, "EventMouseX");
    lua_pushcfunction(L, GenL_SDLStatic_EventMouseY);
    lua_setfield(L, -2, "EventMouseY");
    lua_pushcfunction(L, GenL_SDLStatic_EventSetType);
    lua_setfield(L, -2, "EventSetType");
    lua_pushcfunction(L, GenL_SDLStatic_EventText);
    lua_setfield(L, -2, "EventText");
    lua_pushcfunction(L, GenL_SDLStatic_EventTouchX);
    lua_setfield(L, -2, "EventTouchX");
    lua_pushcfunction(L, GenL_SDLStatic_EventTouchY);
    lua_setfield(L, -2, "EventTouchY");
    lua_pushcfunction(L, GenL_SDLStatic_EventType);
    lua_setfield(L, -2, "EventType");
    lua_pushcfunction(L, GenL_SDLStatic_EventWheelX);
    lua_setfield(L, -2, "EventWheelX");
    lua_pushcfunction(L, GenL_SDLStatic_EventWheelY);
    lua_setfield(L, -2, "EventWheelY");
    lua_pushcfunction(L, GenL_SDLStatic_EventWindowId);
    lua_setfield(L, -2, "EventWindowId");
    lua_pushcfunction(L, GenL_SDLStatic_FilterJointDefCreate);
    lua_setfield(L, -2, "FilterJointDefCreate");
    lua_pushcfunction(L, GenL_SDLStatic_FilterJointDefDestroy);
    lua_setfield(L, -2, "FilterJointDefDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_FilterJointDefSetBodies);
    lua_setfield(L, -2, "FilterJointDefSetBodies");
    lua_pushcfunction(L, GenL_SDLStatic_FingerCount);
    lua_setfield(L, -2, "FingerCount");
    lua_pushcfunction(L, GenL_SDLStatic_FreeTiledMap);
    lua_setfield(L, -2, "FreeTiledMap");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadAccelerometer);
    lua_setfield(L, -2, "GamepadAccelerometer");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadAxisValue);
    lua_setfield(L, -2, "GamepadAxisValue");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadButtonDown);
    lua_setfield(L, -2, "GamepadButtonDown");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadButtonPressed);
    lua_setfield(L, -2, "GamepadButtonPressed");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadButtonReleased);
    lua_setfield(L, -2, "GamepadButtonReleased");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadConnected);
    lua_setfield(L, -2, "GamepadConnected");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadCount);
    lua_setfield(L, -2, "GamepadCount");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadDeadzone);
    lua_setfield(L, -2, "GamepadDeadzone");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadDirectionPressed);
    lua_setfield(L, -2, "GamepadDirectionPressed");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadDirectionRepeat);
    lua_setfield(L, -2, "GamepadDirectionRepeat");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadGyro);
    lua_setfield(L, -2, "GamepadGyro");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadHasAccelerometer);
    lua_setfield(L, -2, "GamepadHasAccelerometer");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadHasGyro);
    lua_setfield(L, -2, "GamepadHasGyro");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadName);
    lua_setfield(L, -2, "GamepadName");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadRumble);
    lua_setfield(L, -2, "GamepadRumble");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadRumbleTriggers);
    lua_setfield(L, -2, "GamepadRumbleTriggers");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadSetLED);
    lua_setfield(L, -2, "GamepadSetLED");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadStick);
    lua_setfield(L, -2, "GamepadStick");
    lua_pushcfunction(L, GenL_SDLStatic_GamepadStopRumble);
    lua_setfield(L, -2, "GamepadStopRumble");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsClamp);
    lua_setfield(L, -2, "GraphicsClamp");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsConfigError);
    lua_setfield(L, -2, "GraphicsConfigError");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsConfigPath);
    lua_setfield(L, -2, "GraphicsConfigPath");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsDefaults);
    lua_setfield(L, -2, "GraphicsDefaults");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsEqual);
    lua_setfield(L, -2, "GraphicsEqual");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsLightMapScale);
    lua_setfield(L, -2, "GraphicsLightMapScale");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsLoadTomlFile);
    lua_setfield(L, -2, "GraphicsLoadTomlFile");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsLoadTomlString);
    lua_setfield(L, -2, "GraphicsLoadTomlString");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsMaxDynamicLights);
    lua_setfield(L, -2, "GraphicsMaxDynamicLights");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsParticleDensity);
    lua_setfield(L, -2, "GraphicsParticleDensity");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsQualityFromName);
    lua_setfield(L, -2, "GraphicsQualityFromName");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsQualityName);
    lua_setfield(L, -2, "GraphicsQualityName");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsSafeMode);
    lua_setfield(L, -2, "GraphicsSafeMode");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsSave);
    lua_setfield(L, -2, "GraphicsSave");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsSavePath);
    lua_setfield(L, -2, "GraphicsSavePath");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsShadowRays);
    lua_setfield(L, -2, "GraphicsShadowRays");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsShadowSoftness);
    lua_setfield(L, -2, "GraphicsShadowSoftness");
    lua_pushcfunction(L, GenL_SDLStatic_GraphicsToToml);
    lua_setfield(L, -2, "GraphicsToToml");
    lua_pushcfunction(L, GenL_SDLStatic_GuiContext);
    lua_setfield(L, -2, "GuiContext");
    lua_pushcfunction(L, GenL_SDLStatic_GuiDrawCommandCount);
    lua_setfield(L, -2, "GuiDrawCommandCount");
    lua_pushcfunction(L, GenL_SDLStatic_GuiDrawTexture);
    lua_setfield(L, -2, "GuiDrawTexture");
    lua_pushcfunction(L, GenL_SDLStatic_GuiDrawTextureOverlay);
    lua_setfield(L, -2, "GuiDrawTextureOverlay");
    lua_pushcfunction(L, GenL_SDLStatic_GuiFontHeight);
    lua_setfield(L, -2, "GuiFontHeight");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridBeginOwned);
    lua_setfield(L, -2, "GuiGridBeginOwned");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridCell);
    lua_setfield(L, -2, "GuiGridCell");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridCellOwned);
    lua_setfield(L, -2, "GuiGridCellOwned");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridCellSpan);
    lua_setfield(L, -2, "GuiGridCellSpan");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridCellSpanOwned);
    lua_setfield(L, -2, "GuiGridCellSpanOwned");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridCreate);
    lua_setfield(L, -2, "GuiGridCreate");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridDestroy);
    lua_setfield(L, -2, "GuiGridDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridEnd);
    lua_setfield(L, -2, "GuiGridEnd");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridEndOwned);
    lua_setfield(L, -2, "GuiGridEndOwned");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridNextRow);
    lua_setfield(L, -2, "GuiGridNextRow");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridNextRowOwned);
    lua_setfield(L, -2, "GuiGridNextRowOwned");
    lua_pushcfunction(L, GenL_SDLStatic_GuiGridWeight);
    lua_setfield(L, -2, "GuiGridWeight");
    lua_pushcfunction(L, GenL_SDLStatic_GuiImage);
    lua_setfield(L, -2, "GuiImage");
    lua_pushcfunction(L, GenL_SDLStatic_GuiInputBegin);
    lua_setfield(L, -2, "GuiInputBegin");
    lua_pushcfunction(L, GenL_SDLStatic_GuiInputEnd);
    lua_setfield(L, -2, "GuiInputEnd");
    lua_pushcfunction(L, GenL_SDLStatic_GuiKeyPressed);
    lua_setfield(L, -2, "GuiKeyPressed");
    lua_pushcfunction(L, GenL_SDLStatic_GuiMemoryUsed);
    lua_setfield(L, -2, "GuiMemoryUsed");
    lua_pushcfunction(L, GenL_SDLStatic_GuiOpenFileButton);
    lua_setfield(L, -2, "GuiOpenFileButton");
    lua_pushcfunction(L, GenL_SDLStatic_GuiPopFont);
    lua_setfield(L, -2, "GuiPopFont");
    lua_pushcfunction(L, GenL_SDLStatic_GuiPopStyleColor);
    lua_setfield(L, -2, "GuiPopStyleColor");
    lua_pushcfunction(L, GenL_SDLStatic_GuiProcessEvent);
    lua_setfield(L, -2, "GuiProcessEvent");
    lua_pushcfunction(L, GenL_SDLStatic_GuiPumpEvents);
    lua_setfield(L, -2, "GuiPumpEvents");
    lua_pushcfunction(L, GenL_SDLStatic_GuiPushFont);
    lua_setfield(L, -2, "GuiPushFont");
    lua_pushcfunction(L, GenL_SDLStatic_GuiPushStyleColor);
    lua_setfield(L, -2, "GuiPushStyleColor");
    lua_pushcfunction(L, GenL_SDLStatic_GuiRender);
    lua_setfield(L, -2, "GuiRender");
    lua_pushcfunction(L, GenL_SDLStatic_GuiSaveFileButton);
    lua_setfield(L, -2, "GuiSaveFileButton");
    lua_pushcfunction(L, GenL_SDLStatic_GuiSavedPath);
    lua_setfield(L, -2, "GuiSavedPath");
    lua_pushcfunction(L, GenL_SDLStatic_GuiScale);
    lua_setfield(L, -2, "GuiScale");
    lua_pushcfunction(L, GenL_SDLStatic_GuiSetFont);
    lua_setfield(L, -2, "GuiSetFont");
    lua_pushcfunction(L, GenL_SDLStatic_GuiSetTooltipDelay);
    lua_setfield(L, -2, "GuiSetTooltipDelay");
    lua_pushcfunction(L, GenL_SDLStatic_GuiTooltip);
    lua_setfield(L, -2, "GuiTooltip");
    lua_pushcfunction(L, GenL_SDLStatic_GuiTooltipDelay);
    lua_setfield(L, -2, "GuiTooltipDelay");
    lua_pushcfunction(L, GenL_SDLStatic_GuiWantsInput);
    lua_setfield(L, -2, "GuiWantsInput");
    lua_pushcfunction(L, GenL_SDLStatic_HMACSHA256);
    lua_setfield(L, -2, "HMACSHA256");
    lua_pushcfunction(L, GenL_SDLStatic_HasDeviceMotion);
    lua_setfield(L, -2, "HasDeviceMotion");
    lua_pushcfunction(L, GenL_SDLStatic_IdleSeconds);
    lua_setfield(L, -2, "IdleSeconds");
    lua_pushcfunction(L, GenL_SDLStatic_KeyDown);
    lua_setfield(L, -2, "KeyDown");
    lua_pushcfunction(L, GenL_SDLStatic_KeyModifiers);
    lua_setfield(L, -2, "KeyModifiers");
    lua_pushcfunction(L, GenL_SDLStatic_KeyPressed);
    lua_setfield(L, -2, "KeyPressed");
    lua_pushcfunction(L, GenL_SDLStatic_KeyReleased);
    lua_setfield(L, -2, "KeyReleased");
    lua_pushcfunction(L, GenL_SDLStatic_LastInputDevice);
    lua_setfield(L, -2, "LastInputDevice");
    lua_pushcfunction(L, GenL_SDLStatic_LightAddDarkZone);
    lua_setfield(L, -2, "LightAddDarkZone");
    lua_pushcfunction(L, GenL_SDLStatic_LightAddOccluder);
    lua_setfield(L, -2, "LightAddOccluder");
    lua_pushcfunction(L, GenL_SDLStatic_LightAddOccluderLine);
    lua_setfield(L, -2, "LightAddOccluderLine");
    lua_pushcfunction(L, GenL_SDLStatic_LightAmbient);
    lua_setfield(L, -2, "LightAmbient");
    lua_pushcfunction(L, GenL_SDLStatic_LightAt);
    lua_setfield(L, -2, "LightAt");
    lua_pushcfunction(L, GenL_SDLStatic_LightBeginFrame);
    lua_setfield(L, -2, "LightBeginFrame");
    lua_pushcfunction(L, GenL_SDLStatic_LightCount);
    lua_setfield(L, -2, "LightCount");
    lua_pushcfunction(L, GenL_SDLStatic_LightDefDestroy);
    lua_setfield(L, -2, "LightDefDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_LightDefSetColor);
    lua_setfield(L, -2, "LightDefSetColor");
    lua_pushcfunction(L, GenL_SDLStatic_LightDefSetCone);
    lua_setfield(L, -2, "LightDefSetCone");
    lua_pushcfunction(L, GenL_SDLStatic_LightDefSetFlicker);
    lua_setfield(L, -2, "LightDefSetFlicker");
    lua_pushcfunction(L, GenL_SDLStatic_LightDefSetOffset);
    lua_setfield(L, -2, "LightDefSetOffset");
    lua_pushcfunction(L, GenL_SDLStatic_LightDefSetRadius);
    lua_setfield(L, -2, "LightDefSetRadius");
    lua_pushcfunction(L, GenL_SDLStatic_LightDefSetShadows);
    lua_setfield(L, -2, "LightDefSetShadows");
    lua_pushcfunction(L, GenL_SDLStatic_LightDefault);
    lua_setfield(L, -2, "LightDefault");
    lua_pushcfunction(L, GenL_SDLStatic_LightHour);
    lua_setfield(L, -2, "LightHour");
    lua_pushcfunction(L, GenL_SDLStatic_LightLineOfSight);
    lua_setfield(L, -2, "LightLineOfSight");
    lua_pushcfunction(L, GenL_SDLStatic_LightPreset_);
    lua_setfield(L, -2, "LightPreset_");
    lua_pushcfunction(L, GenL_SDLStatic_LightRender);
    lua_setfield(L, -2, "LightRender");
    lua_pushcfunction(L, GenL_SDLStatic_LightSetAmbient);
    lua_setfield(L, -2, "LightSetAmbient");
    lua_pushcfunction(L, GenL_SDLStatic_LightSetAutoOccluders);
    lua_setfield(L, -2, "LightSetAutoOccluders");
    lua_pushcfunction(L, GenL_SDLStatic_LightSetClock);
    lua_setfield(L, -2, "LightSetClock");
    lua_pushcfunction(L, GenL_SDLStatic_LightSetPreset);
    lua_setfield(L, -2, "LightSetPreset");
    lua_pushcfunction(L, GenL_SDLStatic_LightSunlight);
    lua_setfield(L, -2, "LightSunlight");
    lua_pushcfunction(L, GenL_SDLStatic_LightUsesShaders);
    lua_setfield(L, -2, "LightUsesShaders");
    lua_pushcfunction(L, GenL_SDLStatic_LoadTextFile);
    lua_setfield(L, -2, "LoadTextFile");
    lua_pushcfunction(L, GenL_SDLStatic_LoadTexture);
    lua_setfield(L, -2, "LoadTexture");
    lua_pushcfunction(L, GenL_SDLStatic_LoadTextureAsync);
    lua_setfield(L, -2, "LoadTextureAsync");
    lua_pushcfunction(L, GenL_SDLStatic_LoadTiledMap);
    lua_setfield(L, -2, "LoadTiledMap");
    lua_pushcfunction(L, GenL_SDLStatic_MotorJointDefCreate);
    lua_setfield(L, -2, "MotorJointDefCreate");
    lua_pushcfunction(L, GenL_SDLStatic_MotorJointDefDestroy);
    lua_setfield(L, -2, "MotorJointDefDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_MotorJointDefSetBodies);
    lua_setfield(L, -2, "MotorJointDefSetBodies");
    lua_pushcfunction(L, GenL_SDLStatic_MountEncryptedArchive);
    lua_setfield(L, -2, "MountEncryptedArchive");
    lua_pushcfunction(L, GenL_SDLStatic_MountEncryptedArchiveFile);
    lua_setfield(L, -2, "MountEncryptedArchiveFile");
    lua_pushcfunction(L, GenL_SDLStatic_MountMedia);
    lua_setfield(L, -2, "MountMedia");
    lua_pushcfunction(L, GenL_SDLStatic_MouseCaptured);
    lua_setfield(L, -2, "MouseCaptured");
    lua_pushcfunction(L, GenL_SDLStatic_MouseDelta);
    lua_setfield(L, -2, "MouseDelta");
    lua_pushcfunction(L, GenL_SDLStatic_MouseDown);
    lua_setfield(L, -2, "MouseDown");
    lua_pushcfunction(L, GenL_SDLStatic_MouseJointDefCreate);
    lua_setfield(L, -2, "MouseJointDefCreate");
    lua_pushcfunction(L, GenL_SDLStatic_MouseJointDefDestroy);
    lua_setfield(L, -2, "MouseJointDefDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_MouseJointDefSetBodies);
    lua_setfield(L, -2, "MouseJointDefSetBodies");
    lua_pushcfunction(L, GenL_SDLStatic_MouseJointDefSetMaxForce);
    lua_setfield(L, -2, "MouseJointDefSetMaxForce");
    lua_pushcfunction(L, GenL_SDLStatic_MouseJointDefSetSpring);
    lua_setfield(L, -2, "MouseJointDefSetSpring");
    lua_pushcfunction(L, GenL_SDLStatic_MousePosition);
    lua_setfield(L, -2, "MousePosition");
    lua_pushcfunction(L, GenL_SDLStatic_MousePressed);
    lua_setfield(L, -2, "MousePressed");
    lua_pushcfunction(L, GenL_SDLStatic_MouseReleased);
    lua_setfield(L, -2, "MouseReleased");
    lua_pushcfunction(L, GenL_SDLStatic_MouseWheel);
    lua_setfield(L, -2, "MouseWheel");
    lua_pushcfunction(L, GenL_SDLStatic_OpenVFSRead);
    lua_setfield(L, -2, "OpenVFSRead");
    lua_pushcfunction(L, GenL_SDLStatic_PhysicsBodyCount);
    lua_setfield(L, -2, "PhysicsBodyCount");
    lua_pushcfunction(L, GenL_SDLStatic_PhysicsGravity);
    lua_setfield(L, -2, "PhysicsGravity");
    lua_pushcfunction(L, GenL_SDLStatic_PhysicsOverlap);
    lua_setfield(L, -2, "PhysicsOverlap");
    lua_pushcfunction(L, GenL_SDLStatic_PhysicsPaused);
    lua_setfield(L, -2, "PhysicsPaused");
    lua_pushcfunction(L, GenL_SDLStatic_PhysicsPixelsPerMetre);
    lua_setfield(L, -2, "PhysicsPixelsPerMetre");
    lua_pushcfunction(L, GenL_SDLStatic_PhysicsRaycast);
    lua_setfield(L, -2, "PhysicsRaycast");
    lua_pushcfunction(L, GenL_SDLStatic_PhysicsSetGravity);
    lua_setfield(L, -2, "PhysicsSetGravity");
    lua_pushcfunction(L, GenL_SDLStatic_PhysicsSetPaused);
    lua_setfield(L, -2, "PhysicsSetPaused");
    lua_pushcfunction(L, GenL_SDLStatic_PhysicsSetPixelsPerMetre);
    lua_setfield(L, -2, "PhysicsSetPixelsPerMetre");
    lua_pushcfunction(L, GenL_SDLStatic_PhysicsSetSubSteps);
    lua_setfield(L, -2, "PhysicsSetSubSteps");
    lua_pushcfunction(L, GenL_SDLStatic_PrismaticJointDefCreate);
    lua_setfield(L, -2, "PrismaticJointDefCreate");
    lua_pushcfunction(L, GenL_SDLStatic_PrismaticJointDefDestroy);
    lua_setfield(L, -2, "PrismaticJointDefDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_PrismaticJointDefSetAnchors);
    lua_setfield(L, -2, "PrismaticJointDefSetAnchors");
    lua_pushcfunction(L, GenL_SDLStatic_PrismaticJointDefSetAxis);
    lua_setfield(L, -2, "PrismaticJointDefSetAxis");
    lua_pushcfunction(L, GenL_SDLStatic_PrismaticJointDefSetBodies);
    lua_setfield(L, -2, "PrismaticJointDefSetBodies");
    lua_pushcfunction(L, GenL_SDLStatic_PrismaticJointDefSetLimit);
    lua_setfield(L, -2, "PrismaticJointDefSetLimit");
    lua_pushcfunction(L, GenL_SDLStatic_PrismaticJointDefSetMotor);
    lua_setfield(L, -2, "PrismaticJointDefSetMotor");
    lua_pushcfunction(L, GenL_SDLStatic_QuitDebugText);
    lua_setfield(L, -2, "QuitDebugText");
    lua_pushcfunction(L, GenL_SDLStatic_RegexEscape);
    lua_setfield(L, -2, "RegexEscape");
    lua_pushcfunction(L, GenL_SDLStatic_RegexFlags);
    lua_setfield(L, -2, "RegexFlags");
    lua_pushcfunction(L, GenL_SDLStatic_RegexGroup);
    lua_setfield(L, -2, "RegexGroup");
    lua_pushcfunction(L, GenL_SDLStatic_RegexGroupBegin);
    lua_setfield(L, -2, "RegexGroupBegin");
    lua_pushcfunction(L, GenL_SDLStatic_RegexGroupCount);
    lua_setfield(L, -2, "RegexGroupCount");
    lua_pushcfunction(L, GenL_SDLStatic_RegexGroupEnd);
    lua_setfield(L, -2, "RegexGroupEnd");
    lua_pushcfunction(L, GenL_SDLStatic_RegexMatchAt);
    lua_setfield(L, -2, "RegexMatchAt");
    lua_pushcfunction(L, GenL_SDLStatic_RegexNamedGroup);
    lua_setfield(L, -2, "RegexNamedGroup");
    lua_pushcfunction(L, GenL_SDLStatic_RegexNamedGroupCount);
    lua_setfield(L, -2, "RegexNamedGroupCount");
    lua_pushcfunction(L, GenL_SDLStatic_RegexNamedGroupName);
    lua_setfield(L, -2, "RegexNamedGroupName");
    lua_pushcfunction(L, GenL_SDLStatic_RegexPattern);
    lua_setfield(L, -2, "RegexPattern");
    lua_pushcfunction(L, GenL_SDLStatic_RegexReplace);
    lua_setfield(L, -2, "RegexReplace");
    lua_pushcfunction(L, GenL_SDLStatic_RegexSearch);
    lua_setfield(L, -2, "RegexSearch");
    lua_pushcfunction(L, GenL_SDLStatic_RenderDebugText);
    lua_setfield(L, -2, "RenderDebugText");
    lua_pushcfunction(L, GenL_SDLStatic_RenderLastStats);
    lua_setfield(L, -2, "RenderLastStats");
    lua_pushcfunction(L, GenL_SDLStatic_RenderLighting);
    lua_setfield(L, -2, "RenderLighting");
    lua_pushcfunction(L, GenL_SDLStatic_RenderOverlay);
    lua_setfield(L, -2, "RenderOverlay");
    lua_pushcfunction(L, GenL_SDLStatic_RenderWorld);
    lua_setfield(L, -2, "RenderWorld");
    lua_pushcfunction(L, GenL_SDLStatic_RevoluteJointDefCreate);
    lua_setfield(L, -2, "RevoluteJointDefCreate");
    lua_pushcfunction(L, GenL_SDLStatic_RevoluteJointDefDestroy);
    lua_setfield(L, -2, "RevoluteJointDefDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_RevoluteJointDefSetAnchors);
    lua_setfield(L, -2, "RevoluteJointDefSetAnchors");
    lua_pushcfunction(L, GenL_SDLStatic_RevoluteJointDefSetBodies);
    lua_setfield(L, -2, "RevoluteJointDefSetBodies");
    lua_pushcfunction(L, GenL_SDLStatic_RevoluteJointDefSetCollideConnected);
    lua_setfield(L, -2, "RevoluteJointDefSetCollideConnected");
    lua_pushcfunction(L, GenL_SDLStatic_RevoluteJointDefSetLimit);
    lua_setfield(L, -2, "RevoluteJointDefSetLimit");
    lua_pushcfunction(L, GenL_SDLStatic_RevoluteJointDefSetMotor);
    lua_setfield(L, -2, "RevoluteJointDefSetMotor");
    lua_pushcfunction(L, GenL_SDLStatic_RevoluteJointDefSetSpring);
    lua_setfield(L, -2, "RevoluteJointDefSetSpring");
    lua_pushcfunction(L, GenL_SDLStatic_SHA256);
    lua_setfield(L, -2, "SHA256");
    lua_pushcfunction(L, GenL_SDLStatic_SampleLight);
    lua_setfield(L, -2, "SampleLight");
    lua_pushcfunction(L, GenL_SDLStatic_SaveDelete);
    lua_setfield(L, -2, "SaveDelete");
    lua_pushcfunction(L, GenL_SDLStatic_SaveExists);
    lua_setfield(L, -2, "SaveExists");
    lua_pushcfunction(L, GenL_SDLStatic_SaveInfoOf);
    lua_setfield(L, -2, "SaveInfoOf");
    lua_pushcfunction(L, GenL_SDLStatic_SavePath);
    lua_setfield(L, -2, "SavePath");
    lua_pushcfunction(L, GenL_SDLStatic_SaveSetIdentity);
    lua_setfield(L, -2, "SaveSetIdentity");
    lua_pushcfunction(L, GenL_SDLStatic_SaveWrite);
    lua_setfield(L, -2, "SaveWrite");
    lua_pushcfunction(L, GenL_SDLStatic_SceneCurrent);
    lua_setfield(L, -2, "SceneCurrent");
    lua_pushcfunction(L, GenL_SDLStatic_SceneDepth);
    lua_setfield(L, -2, "SceneDepth");
    lua_pushcfunction(L, GenL_SDLStatic_SceneEngine);
    lua_setfield(L, -2, "SceneEngine");
    lua_pushcfunction(L, GenL_SDLStatic_SceneFind);
    lua_setfield(L, -2, "SceneFind");
    lua_pushcfunction(L, GenL_SDLStatic_SceneIsActive);
    lua_setfield(L, -2, "SceneIsActive");
    lua_pushcfunction(L, GenL_SDLStatic_SceneName);
    lua_setfield(L, -2, "SceneName");
    lua_pushcfunction(L, GenL_SDLStatic_ScenePop);
    lua_setfield(L, -2, "ScenePop");
    lua_pushcfunction(L, GenL_SDLStatic_ScenePush);
    lua_setfield(L, -2, "ScenePush");
    lua_pushcfunction(L, GenL_SDLStatic_SceneReplace);
    lua_setfield(L, -2, "SceneReplace");
    lua_pushcfunction(L, GenL_SDLStatic_SceneReset);
    lua_setfield(L, -2, "SceneReset");
    lua_pushcfunction(L, GenL_SDLStatic_SceneSetTransitionColor);
    lua_setfield(L, -2, "SceneSetTransitionColor");
    lua_pushcfunction(L, GenL_SDLStatic_SceneTransitionTo);
    lua_setfield(L, -2, "SceneTransitionTo");
    lua_pushcfunction(L, GenL_SDLStatic_SceneTransitioning);
    lua_setfield(L, -2, "SceneTransitioning");
    lua_pushcfunction(L, GenL_SDLStatic_ScriptHasHandlers);
    lua_setfield(L, -2, "ScriptHasHandlers");
    lua_pushcfunction(L, GenL_SDLStatic_ScriptRun);
    lua_setfield(L, -2, "ScriptRun");
    lua_pushcfunction(L, GenL_SDLStatic_ScriptSetHook);
    lua_setfield(L, -2, "ScriptSetHook");
    lua_pushcfunction(L, GenL_SDLStatic_ScriptUnbind);
    lua_setfield(L, -2, "ScriptUnbind");
    lua_pushcfunction(L, GenL_SDLStatic_SetDebugTextSize);
    lua_setfield(L, -2, "SetDebugTextSize");
    lua_pushcfunction(L, GenL_SDLStatic_SetDeviceMotion);
    lua_setfield(L, -2, "SetDeviceMotion");
    lua_pushcfunction(L, GenL_SDLStatic_SetDirectionRepeat);
    lua_setfield(L, -2, "SetDirectionRepeat");
    lua_pushcfunction(L, GenL_SDLStatic_SetGamepadDeadzone);
    lua_setfield(L, -2, "SetGamepadDeadzone");
    lua_pushcfunction(L, GenL_SDLStatic_SetGamepadMotion);
    lua_setfield(L, -2, "SetGamepadMotion");
    lua_pushcfunction(L, GenL_SDLStatic_SetLightAmbient);
    lua_setfield(L, -2, "SetLightAmbient");
    lua_pushcfunction(L, GenL_SDLStatic_SetLightDebugDraw);
    lua_setfield(L, -2, "SetLightDebugDraw");
    lua_pushcfunction(L, GenL_SDLStatic_SetLightMapScale);
    lua_setfield(L, -2, "SetLightMapScale");
    lua_pushcfunction(L, GenL_SDLStatic_SetLightRayCount);
    lua_setfield(L, -2, "SetLightRayCount");
    lua_pushcfunction(L, GenL_SDLStatic_SetLightRings);
    lua_setfield(L, -2, "SetLightRings");
    lua_pushcfunction(L, GenL_SDLStatic_SetLightShadowSoftness);
    lua_setfield(L, -2, "SetLightShadowSoftness");
    lua_pushcfunction(L, GenL_SDLStatic_SetLightUseShaders);
    lua_setfield(L, -2, "SetLightUseShaders");
    lua_pushcfunction(L, GenL_SDLStatic_SetMouseCapture);
    lua_setfield(L, -2, "SetMouseCapture");
    lua_pushcfunction(L, GenL_SDLStatic_SetTextInput);
    lua_setfield(L, -2, "SetTextInput");
    lua_pushcfunction(L, GenL_SDLStatic_SetTriggerThreshold);
    lua_setfield(L, -2, "SetTriggerThreshold");
    lua_pushcfunction(L, GenL_SDLStatic_ShowOpenFileDialog);
    lua_setfield(L, -2, "ShowOpenFileDialog");
    lua_pushcfunction(L, GenL_SDLStatic_ShowSaveFileDialog);
    lua_setfield(L, -2, "ShowSaveFileDialog");
    lua_pushcfunction(L, GenL_SDLStatic_SpriteCreate);
    lua_setfield(L, -2, "SpriteCreate");
    lua_pushcfunction(L, GenL_SDLStatic_SpriteDestroy);
    lua_setfield(L, -2, "SpriteDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_SpriteSetColor);
    lua_setfield(L, -2, "SpriteSetColor");
    lua_pushcfunction(L, GenL_SDLStatic_SpriteSetLayer);
    lua_setfield(L, -2, "SpriteSetLayer");
    lua_pushcfunction(L, GenL_SDLStatic_SpriteSetOrigin);
    lua_setfield(L, -2, "SpriteSetOrigin");
    lua_pushcfunction(L, GenL_SDLStatic_SpriteSetScreenSpace);
    lua_setfield(L, -2, "SpriteSetScreenSpace");
    lua_pushcfunction(L, GenL_SDLStatic_SpriteSetSize);
    lua_setfield(L, -2, "SpriteSetSize");
    lua_pushcfunction(L, GenL_SDLStatic_SpriteSetSortByY);
    lua_setfield(L, -2, "SpriteSetSortByY");
    lua_pushcfunction(L, GenL_SDLStatic_SpriteSetSource);
    lua_setfield(L, -2, "SpriteSetSource");
    lua_pushcfunction(L, GenL_SDLStatic_SpriteSetTexture);
    lua_setfield(L, -2, "SpriteSetTexture");
    lua_pushcfunction(L, GenL_SDLStatic_SpriteSetVisible);
    lua_setfield(L, -2, "SpriteSetVisible");
    lua_pushcfunction(L, GenL_SDLStatic_Text);
    lua_setfield(L, -2, "Text");
    lua_pushcfunction(L, GenL_SDLStatic_TextCount);
    lua_setfield(L, -2, "TextCount");
    lua_pushcfunction(L, GenL_SDLStatic_TextHas);
    lua_setfield(L, -2, "TextHas");
    lua_pushcfunction(L, GenL_SDLStatic_TextLanguage);
    lua_setfield(L, -2, "TextLanguage");
    lua_pushcfunction(L, GenL_SDLStatic_TextLoad);
    lua_setfield(L, -2, "TextLoad");
    lua_pushcfunction(L, GenL_SDLStatic_TextLoadFile);
    lua_setfield(L, -2, "TextLoadFile");
    lua_pushcfunction(L, GenL_SDLStatic_TextSetLanguage);
    lua_setfield(L, -2, "TextSetLanguage");
    lua_pushcfunction(L, GenL_SDLStatic_TextTyped);
    lua_setfield(L, -2, "TextTyped");
    lua_pushcfunction(L, GenL_SDLStatic_Texture);
    lua_setfield(L, -2, "Texture");
    lua_pushcfunction(L, GenL_SDLStatic_TiledLayerCount);
    lua_setfield(L, -2, "TiledLayerCount");
    lua_pushcfunction(L, GenL_SDLStatic_TiledLayerName);
    lua_setfield(L, -2, "TiledLayerName");
    lua_pushcfunction(L, GenL_SDLStatic_TiledLayerType);
    lua_setfield(L, -2, "TiledLayerType");
    lua_pushcfunction(L, GenL_SDLStatic_TiledMapHeight);
    lua_setfield(L, -2, "TiledMapHeight");
    lua_pushcfunction(L, GenL_SDLStatic_TiledMapWidth);
    lua_setfield(L, -2, "TiledMapWidth");
    lua_pushcfunction(L, GenL_SDLStatic_TiledObjectAt);
    lua_setfield(L, -2, "TiledObjectAt");
    lua_pushcfunction(L, GenL_SDLStatic_TiledObjectCount);
    lua_setfield(L, -2, "TiledObjectCount");
    lua_pushcfunction(L, GenL_SDLStatic_TiledRaw);
    lua_setfield(L, -2, "TiledRaw");
    lua_pushcfunction(L, GenL_SDLStatic_TiledTileAt);
    lua_setfield(L, -2, "TiledTileAt");
    lua_pushcfunction(L, GenL_SDLStatic_TiledTileHeight);
    lua_setfield(L, -2, "TiledTileHeight");
    lua_pushcfunction(L, GenL_SDLStatic_TiledTileWidth);
    lua_setfield(L, -2, "TiledTileWidth");
    lua_pushcfunction(L, GenL_SDLStatic_TouchPinch);
    lua_setfield(L, -2, "TouchPinch");
    lua_pushcfunction(L, GenL_SDLStatic_TouchRotation);
    lua_setfield(L, -2, "TouchRotation");
    lua_pushcfunction(L, GenL_SDLStatic_WeldJointDefCreate);
    lua_setfield(L, -2, "WeldJointDefCreate");
    lua_pushcfunction(L, GenL_SDLStatic_WeldJointDefDestroy);
    lua_setfield(L, -2, "WeldJointDefDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_WeldJointDefSetAnchors);
    lua_setfield(L, -2, "WeldJointDefSetAnchors");
    lua_pushcfunction(L, GenL_SDLStatic_WeldJointDefSetBodies);
    lua_setfield(L, -2, "WeldJointDefSetBodies");
    lua_pushcfunction(L, GenL_SDLStatic_WeldJointDefSetSpring);
    lua_setfield(L, -2, "WeldJointDefSetSpring");
    lua_pushcfunction(L, GenL_SDLStatic_WheelJointDefCreate);
    lua_setfield(L, -2, "WheelJointDefCreate");
    lua_pushcfunction(L, GenL_SDLStatic_WheelJointDefDestroy);
    lua_setfield(L, -2, "WheelJointDefDestroy");
    lua_pushcfunction(L, GenL_SDLStatic_WheelJointDefSetAnchors);
    lua_setfield(L, -2, "WheelJointDefSetAnchors");
    lua_pushcfunction(L, GenL_SDLStatic_WheelJointDefSetAxis);
    lua_setfield(L, -2, "WheelJointDefSetAxis");
    lua_pushcfunction(L, GenL_SDLStatic_WheelJointDefSetBodies);
    lua_setfield(L, -2, "WheelJointDefSetBodies");
    lua_pushcfunction(L, GenL_SDLStatic_WheelJointDefSetMotor);
    lua_setfield(L, -2, "WheelJointDefSetMotor");
    lua_pushcfunction(L, GenL_SDLStatic_WheelJointDefSetSpring);
    lua_setfield(L, -2, "WheelJointDefSetSpring");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_ASSET_MISSING);
    lua_setfield(L, -2, "SDLSTATIC_ASSET_MISSING");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_ASSET_QUEUED);
    lua_setfield(L, -2, "SDLSTATIC_ASSET_QUEUED");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_ASSET_LOADING);
    lua_setfield(L, -2, "SDLSTATIC_ASSET_LOADING");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_ASSET_DECODED);
    lua_setfield(L, -2, "SDLSTATIC_ASSET_DECODED");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_ASSET_READY);
    lua_setfield(L, -2, "SDLSTATIC_ASSET_READY");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_ASSET_FAILED);
    lua_setfield(L, -2, "SDLSTATIC_ASSET_FAILED");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BIND_NONE);
    lua_setfield(L, -2, "SDLSTATIC_BIND_NONE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BIND_KEY);
    lua_setfield(L, -2, "SDLSTATIC_BIND_KEY");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BIND_MOUSE_BUTTON);
    lua_setfield(L, -2, "SDLSTATIC_BIND_MOUSE_BUTTON");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BIND_MOUSE_WHEEL);
    lua_setfield(L, -2, "SDLSTATIC_BIND_MOUSE_WHEEL");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BIND_PAD_BUTTON);
    lua_setfield(L, -2, "SDLSTATIC_BIND_PAD_BUTTON");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BIND_PAD_AXIS);
    lua_setfield(L, -2, "SDLSTATIC_BIND_PAD_AXIS");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BIND_PAD_DIRECTION);
    lua_setfield(L, -2, "SDLSTATIC_BIND_PAD_DIRECTION");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BODY_STATIC);
    lua_setfield(L, -2, "SDLSTATIC_BODY_STATIC");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BODY_KINEMATIC);
    lua_setfield(L, -2, "SDLSTATIC_BODY_KINEMATIC");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BODY_DYNAMIC);
    lua_setfield(L, -2, "SDLSTATIC_BODY_DYNAMIC");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_COIN);
    lua_setfield(L, -2, "SDLSTATIC_SFX_COIN");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_LASER);
    lua_setfield(L, -2, "SDLSTATIC_SFX_LASER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_JUMP);
    lua_setfield(L, -2, "SDLSTATIC_SFX_JUMP");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_EXPLOSION);
    lua_setfield(L, -2, "SDLSTATIC_SFX_EXPLOSION");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_POWERUP);
    lua_setfield(L, -2, "SDLSTATIC_SFX_POWERUP");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SFX_HURT);
    lua_setfield(L, -2, "SDLSTATIC_SFX_HURT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_SQUARE_125);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_SQUARE_125");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_SQUARE_25);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_SQUARE_25");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_SQUARE_50);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_SQUARE_50");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_TRIANGLE);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_TRIANGLE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_SAW);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_SAW");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_NOISE);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_NOISE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_NOISE_METALLIC);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_NOISE_METALLIC");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_CHIP_SINE);
    lua_setfield(L, -2, "SDLSTATIC_CHIP_SINE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_COLORBLIND_NONE);
    lua_setfield(L, -2, "SDLSTATIC_COLORBLIND_NONE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_COLORBLIND_PROTANOPIA);
    lua_setfield(L, -2, "SDLSTATIC_COLORBLIND_PROTANOPIA");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_COLORBLIND_DEUTERANOPIA);
    lua_setfield(L, -2, "SDLSTATIC_COLORBLIND_DEUTERANOPIA");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_COLORBLIND_TRITANOPIA);
    lua_setfield(L, -2, "SDLSTATIC_COLORBLIND_TRITANOPIA");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DIALOG_IDLE);
    lua_setfield(L, -2, "SDLSTATIC_DIALOG_IDLE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DIALOG_PENDING);
    lua_setfield(L, -2, "SDLSTATIC_DIALOG_PENDING");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DIALOG_ACCEPTED);
    lua_setfield(L, -2, "SDLSTATIC_DIALOG_ACCEPTED");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DIALOG_CANCELLED);
    lua_setfield(L, -2, "SDLSTATIC_DIALOG_CANCELLED");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DIALOG_ERROR);
    lua_setfield(L, -2, "SDLSTATIC_DIALOG_ERROR");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DIR_UP);
    lua_setfield(L, -2, "SDLSTATIC_DIR_UP");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DIR_DOWN);
    lua_setfield(L, -2, "SDLSTATIC_DIR_DOWN");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DIR_LEFT);
    lua_setfield(L, -2, "SDLSTATIC_DIR_LEFT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DIR_RIGHT);
    lua_setfield(L, -2, "SDLSTATIC_DIR_RIGHT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DIR_COUNT);
    lua_setfield(L, -2, "SDLSTATIC_DIR_COUNT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BACKEND_OPENGL);
    lua_setfield(L, -2, "SDLSTATIC_BACKEND_OPENGL");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BACKEND_NATIVE);
    lua_setfield(L, -2, "SDLSTATIC_BACKEND_NATIVE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_BACKEND_SOFTWARE);
    lua_setfield(L, -2, "SDLSTATIC_BACKEND_SOFTWARE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_INTERPOLATE_LERP);
    lua_setfield(L, -2, "SDLSTATIC_INTERPOLATE_LERP");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_INTERPOLATE_NONE);
    lua_setfield(L, -2, "SDLSTATIC_INTERPOLATE_NONE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_INTERPOLATE_EXTRAPOLATE);
    lua_setfield(L, -2, "SDLSTATIC_INTERPOLATE_EXTRAPOLATE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PRESENT_LETTERBOX);
    lua_setfield(L, -2, "SDLSTATIC_PRESENT_LETTERBOX");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PRESENT_EXPAND);
    lua_setfield(L, -2, "SDLSTATIC_PRESENT_EXPAND");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PRESENT_OVERSCAN);
    lua_setfield(L, -2, "SDLSTATIC_PRESENT_OVERSCAN");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PRESENT_INTEGER);
    lua_setfield(L, -2, "SDLSTATIC_PRESENT_INTEGER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PRESENT_STRETCH);
    lua_setfield(L, -2, "SDLSTATIC_PRESENT_STRETCH");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PRESENT_NATIVE);
    lua_setfield(L, -2, "SDLSTATIC_PRESENT_NATIVE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_AXIS_LEFT_X);
    lua_setfield(L, -2, "SDLSTATIC_AXIS_LEFT_X");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_AXIS_LEFT_Y);
    lua_setfield(L, -2, "SDLSTATIC_AXIS_LEFT_Y");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_AXIS_RIGHT_X);
    lua_setfield(L, -2, "SDLSTATIC_AXIS_RIGHT_X");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_AXIS_RIGHT_Y);
    lua_setfield(L, -2, "SDLSTATIC_AXIS_RIGHT_Y");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_AXIS_LEFT_TRIGGER);
    lua_setfield(L, -2, "SDLSTATIC_AXIS_LEFT_TRIGGER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_AXIS_RIGHT_TRIGGER);
    lua_setfield(L, -2, "SDLSTATIC_AXIS_RIGHT_TRIGGER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_AXIS_COUNT);
    lua_setfield(L, -2, "SDLSTATIC_AXIS_COUNT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_A);
    lua_setfield(L, -2, "SDLSTATIC_PAD_A");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_B);
    lua_setfield(L, -2, "SDLSTATIC_PAD_B");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_X);
    lua_setfield(L, -2, "SDLSTATIC_PAD_X");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_Y);
    lua_setfield(L, -2, "SDLSTATIC_PAD_Y");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_BACK);
    lua_setfield(L, -2, "SDLSTATIC_PAD_BACK");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_GUIDE);
    lua_setfield(L, -2, "SDLSTATIC_PAD_GUIDE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_START);
    lua_setfield(L, -2, "SDLSTATIC_PAD_START");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_LEFT_STICK);
    lua_setfield(L, -2, "SDLSTATIC_PAD_LEFT_STICK");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_RIGHT_STICK);
    lua_setfield(L, -2, "SDLSTATIC_PAD_RIGHT_STICK");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_LEFT_SHOULDER);
    lua_setfield(L, -2, "SDLSTATIC_PAD_LEFT_SHOULDER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_RIGHT_SHOULDER);
    lua_setfield(L, -2, "SDLSTATIC_PAD_RIGHT_SHOULDER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_DPAD_UP);
    lua_setfield(L, -2, "SDLSTATIC_PAD_DPAD_UP");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_DPAD_DOWN);
    lua_setfield(L, -2, "SDLSTATIC_PAD_DPAD_DOWN");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_DPAD_LEFT);
    lua_setfield(L, -2, "SDLSTATIC_PAD_DPAD_LEFT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_DPAD_RIGHT);
    lua_setfield(L, -2, "SDLSTATIC_PAD_DPAD_RIGHT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_SHARE);
    lua_setfield(L, -2, "SDLSTATIC_PAD_SHARE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_PADDLE1);
    lua_setfield(L, -2, "SDLSTATIC_PAD_PADDLE1");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_PADDLE2);
    lua_setfield(L, -2, "SDLSTATIC_PAD_PADDLE2");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_PADDLE3);
    lua_setfield(L, -2, "SDLSTATIC_PAD_PADDLE3");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_PADDLE4);
    lua_setfield(L, -2, "SDLSTATIC_PAD_PADDLE4");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_TOUCHPAD);
    lua_setfield(L, -2, "SDLSTATIC_PAD_TOUCHPAD");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_LEFT_TRIGGER);
    lua_setfield(L, -2, "SDLSTATIC_PAD_LEFT_TRIGGER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_RIGHT_TRIGGER);
    lua_setfield(L, -2, "SDLSTATIC_PAD_RIGHT_TRIGGER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_PAD_BUTTON_COUNT);
    lua_setfield(L, -2, "SDLSTATIC_PAD_BUTTON_COUNT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_AA_OFF);
    lua_setfield(L, -2, "SDLSTATIC_AA_OFF");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_AA_FXAA);
    lua_setfield(L, -2, "SDLSTATIC_AA_FXAA");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_QUALITY_OFF);
    lua_setfield(L, -2, "SDLSTATIC_QUALITY_OFF");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_QUALITY_LOW);
    lua_setfield(L, -2, "SDLSTATIC_QUALITY_LOW");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_QUALITY_MEDIUM);
    lua_setfield(L, -2, "SDLSTATIC_QUALITY_MEDIUM");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_QUALITY_HIGH);
    lua_setfield(L, -2, "SDLSTATIC_QUALITY_HIGH");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_FONT_SMALL);
    lua_setfield(L, -2, "SDLSTATIC_GUI_FONT_SMALL");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_FONT_NORMAL);
    lua_setfield(L, -2, "SDLSTATIC_GUI_FONT_NORMAL");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_FONT_LARGE);
    lua_setfield(L, -2, "SDLSTATIC_GUI_FONT_LARGE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_GLYPHS_LATIN1);
    lua_setfield(L, -2, "SDLSTATIC_GUI_GLYPHS_LATIN1");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_GLYPHS_PUNCTUATION);
    lua_setfield(L, -2, "SDLSTATIC_GUI_GLYPHS_PUNCTUATION");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_GLYPHS_CYRILLIC);
    lua_setfield(L, -2, "SDLSTATIC_GUI_GLYPHS_CYRILLIC");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_GLYPHS_CHINESE);
    lua_setfield(L, -2, "SDLSTATIC_GUI_GLYPHS_CHINESE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_GLYPHS_KOREAN);
    lua_setfield(L, -2, "SDLSTATIC_GUI_GLYPHS_KOREAN");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_IMAGE_STRETCH);
    lua_setfield(L, -2, "SDLSTATIC_GUI_IMAGE_STRETCH");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_IMAGE_ZOOM);
    lua_setfield(L, -2, "SDLSTATIC_GUI_IMAGE_ZOOM");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_IMAGE_CENTER);
    lua_setfield(L, -2, "SDLSTATIC_GUI_IMAGE_CENTER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_IMAGE_FILL);
    lua_setfield(L, -2, "SDLSTATIC_GUI_IMAGE_FILL");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_WINDOW_BACKGROUND);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_WINDOW_BACKGROUND");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_TEXT);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_TEXT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_BUTTON);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_BUTTON");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_BUTTON_HOVER);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_BUTTON_HOVER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_BUTTON_TEXT);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_BUTTON_TEXT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_GUI_COLOR_HEADER);
    lua_setfield(L, -2, "SDLSTATIC_GUI_COLOR_HEADER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DEVICE_NONE);
    lua_setfield(L, -2, "SDLSTATIC_DEVICE_NONE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DEVICE_KEYBOARD);
    lua_setfield(L, -2, "SDLSTATIC_DEVICE_KEYBOARD");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DEVICE_MOUSE);
    lua_setfield(L, -2, "SDLSTATIC_DEVICE_MOUSE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DEVICE_GAMEPAD);
    lua_setfield(L, -2, "SDLSTATIC_DEVICE_GAMEPAD");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_DEVICE_TOUCH);
    lua_setfield(L, -2, "SDLSTATIC_DEVICE_TOUCH");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_LIGHT_NONE);
    lua_setfield(L, -2, "SDLSTATIC_LIGHT_NONE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_LIGHT_SUNRISE);
    lua_setfield(L, -2, "SDLSTATIC_LIGHT_SUNRISE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_LIGHT_AFTERNOON);
    lua_setfield(L, -2, "SDLSTATIC_LIGHT_AFTERNOON");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_LIGHT_SUNSET);
    lua_setfield(L, -2, "SDLSTATIC_LIGHT_SUNSET");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_LIGHT_NIGHT);
    lua_setfield(L, -2, "SDLSTATIC_LIGHT_NIGHT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_LIGHT_DARK);
    lua_setfield(L, -2, "SDLSTATIC_LIGHT_DARK");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_MEDIA_NONE);
    lua_setfield(L, -2, "SDLSTATIC_MEDIA_NONE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_MEDIA_EXPLICIT);
    lua_setfield(L, -2, "SDLSTATIC_MEDIA_EXPLICIT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_MEDIA_EMBEDDED);
    lua_setfield(L, -2, "SDLSTATIC_MEDIA_EMBEDDED");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_MEDIA_ARCHIVE);
    lua_setfield(L, -2, "SDLSTATIC_MEDIA_ARCHIVE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_MEDIA_DIRECTORY);
    lua_setfield(L, -2, "SDLSTATIC_MEDIA_DIRECTORY");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_MOUSE_LEFT);
    lua_setfield(L, -2, "SDLSTATIC_MOUSE_LEFT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_MOUSE_MIDDLE);
    lua_setfield(L, -2, "SDLSTATIC_MOUSE_MIDDLE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_MOUSE_RIGHT);
    lua_setfield(L, -2, "SDLSTATIC_MOUSE_RIGHT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_MOUSE_X1);
    lua_setfield(L, -2, "SDLSTATIC_MOUSE_X1");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_MOUSE_X2);
    lua_setfield(L, -2, "SDLSTATIC_MOUSE_X2");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_MOUSE_COUNT);
    lua_setfield(L, -2, "SDLSTATIC_MOUSE_COUNT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SCENE_DEFAULT);
    lua_setfield(L, -2, "SDLSTATIC_SCENE_DEFAULT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SCENE_UPDATE_WHEN_COVERED);
    lua_setfield(L, -2, "SDLSTATIC_SCENE_UPDATE_WHEN_COVERED");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SCENE_TRANSPARENT);
    lua_setfield(L, -2, "SDLSTATIC_SCENE_TRANSPARENT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_TRANSITION_NONE);
    lua_setfield(L, -2, "SDLSTATIC_TRANSITION_NONE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_TRANSITION_FADE);
    lua_setfield(L, -2, "SDLSTATIC_TRANSITION_FADE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_HOOK_LOAD);
    lua_setfield(L, -2, "SDLSTATIC_HOOK_LOAD");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_HOOK_FIXED_UPDATE);
    lua_setfield(L, -2, "SDLSTATIC_HOOK_FIXED_UPDATE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_HOOK_UPDATE);
    lua_setfield(L, -2, "SDLSTATIC_HOOK_UPDATE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_HOOK_RENDER);
    lua_setfield(L, -2, "SDLSTATIC_HOOK_RENDER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_HOOK_POST_RENDER);
    lua_setfield(L, -2, "SDLSTATIC_HOOK_POST_RENDER");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_HOOK_UNLOAD);
    lua_setfield(L, -2, "SDLSTATIC_HOOK_UNLOAD");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_HOOK_COUNT);
    lua_setfield(L, -2, "SDLSTATIC_HOOK_COUNT");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SHAPE_BOX);
    lua_setfield(L, -2, "SDLSTATIC_SHAPE_BOX");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SHAPE_CIRCLE);
    lua_setfield(L, -2, "SDLSTATIC_SHAPE_CIRCLE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SHAPE_CAPSULE);
    lua_setfield(L, -2, "SDLSTATIC_SHAPE_CAPSULE");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SPLIT_HORIZONTAL);
    lua_setfield(L, -2, "SDLSTATIC_SPLIT_HORIZONTAL");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SPLIT_VERTICAL);
    lua_setfield(L, -2, "SDLSTATIC_SPLIT_VERTICAL");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_SPLIT_GRID);
    lua_setfield(L, -2, "SDLSTATIC_SPLIT_GRID");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_FILTER_AUTO);
    lua_setfield(L, -2, "SDLSTATIC_FILTER_AUTO");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_FILTER_LINEAR);
    lua_setfield(L, -2, "SDLSTATIC_FILTER_LINEAR");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_FILTER_NEAREST);
    lua_setfield(L, -2, "SDLSTATIC_FILTER_NEAREST");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_WINDOW_WINDOWED);
    lua_setfield(L, -2, "SDLSTATIC_WINDOW_WINDOWED");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_WINDOW_BORDERLESS);
    lua_setfield(L, -2, "SDLSTATIC_WINDOW_BORDERLESS");
    lua_pushinteger(L, (lua_Integer)SDLSTATIC_WINDOW_EXCLUSIVE);
    lua_setfield(L, -2, "SDLSTATIC_WINDOW_EXCLUSIVE");
    lua_setglobal(L, "SDLStaticC");
    return 0;
}
