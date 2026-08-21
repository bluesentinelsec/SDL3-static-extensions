/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for SDLStatic modules. */
#include "../src/gen_support_ruby.h"

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
#include <SDLStatic/gpu_build.h>
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

static void GenRead_SDLStatic_ActorMessage(mrb_state *mrb, mrb_value h, SDLStatic_ActorMessage *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->id = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "id");
    out->sender = (SDLStatic_ActorId)SDLStaticGen_RubyFieldInt(mrb, h, "sender");
    out->a = (float)SDLStaticGen_RubyFieldNum(mrb, h, "a");
    out->b = (float)SDLStaticGen_RubyFieldNum(mrb, h, "b");
    out->value = (Sint64)SDLStaticGen_RubyFieldInt(mrb, h, "value");
}

static void GenRead_SDLStatic_ActorTransform(mrb_state *mrb, mrb_value h, SDLStatic_ActorTransform *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "x");
    out->y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "y");
    out->rotation = (float)SDLStaticGen_RubyFieldNum(mrb, h, "rotation");
    out->scale_x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "scale_x");
    out->scale_y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "scale_y");
}

static mrb_value GenPush_SDLStatic_ActorTransform(mrb_state *mrb, const SDLStatic_ActorTransform *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "x", mrb_float_value(mrb, (mrb_float)in->x));
    SDLStaticGen_RubyHashSet(mrb, h, "y", mrb_float_value(mrb, (mrb_float)in->y));
    SDLStaticGen_RubyHashSet(mrb, h, "rotation", mrb_float_value(mrb, (mrb_float)in->rotation));
    SDLStaticGen_RubyHashSet(mrb, h, "scale_x", mrb_float_value(mrb, (mrb_float)in->scale_x));
    SDLStaticGen_RubyHashSet(mrb, h, "scale_y", mrb_float_value(mrb, (mrb_float)in->scale_y));
    return h;
}

static void GenRead_SDLStatic_Binding(mrb_state *mrb, mrb_value h, SDLStatic_Binding *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->source = (SDLStatic_BindingSource)SDLStaticGen_RubyFieldInt(mrb, h, "source");
    out->code = (int)SDLStaticGen_RubyFieldInt(mrb, h, "code");
    out->sign = (int)SDLStaticGen_RubyFieldInt(mrb, h, "sign");
    out->axis_half = (int)SDLStaticGen_RubyFieldInt(mrb, h, "axis_half");
}

static mrb_value GenPush_SDLStatic_Binding(mrb_state *mrb, const SDLStatic_Binding *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "source", mrb_int_value(mrb, (mrb_int)in->source));
    SDLStaticGen_RubyHashSet(mrb, h, "code", mrb_int_value(mrb, (mrb_int)in->code));
    SDLStaticGen_RubyHashSet(mrb, h, "sign", mrb_int_value(mrb, (mrb_int)in->sign));
    SDLStaticGen_RubyHashSet(mrb, h, "axis_half", mrb_int_value(mrb, (mrb_int)in->axis_half));
    return h;
}

static void GenRead_SDLStatic_BodyDef(mrb_state *mrb, mrb_value h, SDLStatic_BodyDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->type = (SDLStatic_BodyType)SDLStaticGen_RubyFieldInt(mrb, h, "type");
    out->shape = (SDLStatic_ShapeType)SDLStaticGen_RubyFieldInt(mrb, h, "shape");
    out->width = (float)SDLStaticGen_RubyFieldNum(mrb, h, "width");
    out->height = (float)SDLStaticGen_RubyFieldNum(mrb, h, "height");
    out->offset_x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "offset_x");
    out->offset_y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "offset_y");
    out->density = (float)SDLStaticGen_RubyFieldNum(mrb, h, "density");
    out->friction = (float)SDLStaticGen_RubyFieldNum(mrb, h, "friction");
    out->restitution = (float)SDLStaticGen_RubyFieldNum(mrb, h, "restitution");
    out->fixed_rotation = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "fixed_rotation");
    out->sensor = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "sensor");
    out->gravity_scale = (float)SDLStaticGen_RubyFieldNum(mrb, h, "gravity_scale");
    out->damping = (float)SDLStaticGen_RubyFieldNum(mrb, h, "damping");
    out->category = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "category");
    out->collides_with = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "collides_with");
    out->bullet = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "bullet");
}

static mrb_value GenPush_SDLStatic_BodyDef(mrb_state *mrb, const SDLStatic_BodyDef *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "type", mrb_int_value(mrb, (mrb_int)in->type));
    SDLStaticGen_RubyHashSet(mrb, h, "shape", mrb_int_value(mrb, (mrb_int)in->shape));
    SDLStaticGen_RubyHashSet(mrb, h, "width", mrb_float_value(mrb, (mrb_float)in->width));
    SDLStaticGen_RubyHashSet(mrb, h, "height", mrb_float_value(mrb, (mrb_float)in->height));
    SDLStaticGen_RubyHashSet(mrb, h, "offset_x", mrb_float_value(mrb, (mrb_float)in->offset_x));
    SDLStaticGen_RubyHashSet(mrb, h, "offset_y", mrb_float_value(mrb, (mrb_float)in->offset_y));
    SDLStaticGen_RubyHashSet(mrb, h, "density", mrb_float_value(mrb, (mrb_float)in->density));
    SDLStaticGen_RubyHashSet(mrb, h, "friction", mrb_float_value(mrb, (mrb_float)in->friction));
    SDLStaticGen_RubyHashSet(mrb, h, "restitution", mrb_float_value(mrb, (mrb_float)in->restitution));
    SDLStaticGen_RubyHashSet(mrb, h, "fixed_rotation", mrb_bool_value((mrb_bool)(in->fixed_rotation != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "sensor", mrb_bool_value((mrb_bool)(in->sensor != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "gravity_scale", mrb_float_value(mrb, (mrb_float)in->gravity_scale));
    SDLStaticGen_RubyHashSet(mrb, h, "damping", mrb_float_value(mrb, (mrb_float)in->damping));
    SDLStaticGen_RubyHashSet(mrb, h, "category", mrb_int_value(mrb, (mrb_int)in->category));
    SDLStaticGen_RubyHashSet(mrb, h, "collides_with", mrb_int_value(mrb, (mrb_int)in->collides_with));
    SDLStaticGen_RubyHashSet(mrb, h, "bullet", mrb_bool_value((mrb_bool)(in->bullet != 0)));
    return h;
}

static void GenRead_SDL_FRect(mrb_state *mrb, mrb_value h, SDL_FRect *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "x");
    out->y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "y");
    out->w = (float)SDLStaticGen_RubyFieldNum(mrb, h, "w");
    out->h = (float)SDLStaticGen_RubyFieldNum(mrb, h, "h");
}

static mrb_value GenPush_SDL_FRect(mrb_state *mrb, const SDL_FRect *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "x", mrb_float_value(mrb, (mrb_float)in->x));
    SDLStaticGen_RubyHashSet(mrb, h, "y", mrb_float_value(mrb, (mrb_float)in->y));
    SDLStaticGen_RubyHashSet(mrb, h, "w", mrb_float_value(mrb, (mrb_float)in->w));
    SDLStaticGen_RubyHashSet(mrb, h, "h", mrb_float_value(mrb, (mrb_float)in->h));
    return h;
}

static void GenRead_SDLStatic_Camera(mrb_state *mrb, mrb_value h, SDLStatic_Camera *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "x");
    out->y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "y");
    out->zoom = (float)SDLStaticGen_RubyFieldNum(mrb, h, "zoom");
    out->target_x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "target_x");
    out->target_y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "target_y");
    out->smoothing = (float)SDLStaticGen_RubyFieldNum(mrb, h, "smoothing");
    out->deadzone_w = (float)SDLStaticGen_RubyFieldNum(mrb, h, "deadzone_w");
    out->deadzone_h = (float)SDLStaticGen_RubyFieldNum(mrb, h, "deadzone_h");
    GenRead_SDL_FRect(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "bounds"), &out->bounds);
    out->shake_amount = (float)SDLStaticGen_RubyFieldNum(mrb, h, "shake_amount");
    out->shake_seconds = (float)SDLStaticGen_RubyFieldNum(mrb, h, "shake_seconds");
    out->shake_remaining = (float)SDLStaticGen_RubyFieldNum(mrb, h, "shake_remaining");
    GenRead_SDL_FRect(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "viewport"), &out->viewport);
    GenRead_SDL_FRect(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "visible"), &out->visible);
}

static mrb_value GenPush_SDLStatic_Camera(mrb_state *mrb, const SDLStatic_Camera *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "x", mrb_float_value(mrb, (mrb_float)in->x));
    SDLStaticGen_RubyHashSet(mrb, h, "y", mrb_float_value(mrb, (mrb_float)in->y));
    SDLStaticGen_RubyHashSet(mrb, h, "zoom", mrb_float_value(mrb, (mrb_float)in->zoom));
    SDLStaticGen_RubyHashSet(mrb, h, "target_x", mrb_float_value(mrb, (mrb_float)in->target_x));
    SDLStaticGen_RubyHashSet(mrb, h, "target_y", mrb_float_value(mrb, (mrb_float)in->target_y));
    SDLStaticGen_RubyHashSet(mrb, h, "smoothing", mrb_float_value(mrb, (mrb_float)in->smoothing));
    SDLStaticGen_RubyHashSet(mrb, h, "deadzone_w", mrb_float_value(mrb, (mrb_float)in->deadzone_w));
    SDLStaticGen_RubyHashSet(mrb, h, "deadzone_h", mrb_float_value(mrb, (mrb_float)in->deadzone_h));
    SDLStaticGen_RubyHashSet(mrb, h, "bounds", GenPush_SDL_FRect(mrb, &in->bounds));
    SDLStaticGen_RubyHashSet(mrb, h, "shake_amount", mrb_float_value(mrb, (mrb_float)in->shake_amount));
    SDLStaticGen_RubyHashSet(mrb, h, "shake_seconds", mrb_float_value(mrb, (mrb_float)in->shake_seconds));
    SDLStaticGen_RubyHashSet(mrb, h, "shake_remaining", mrb_float_value(mrb, (mrb_float)in->shake_remaining));
    SDLStaticGen_RubyHashSet(mrb, h, "viewport", GenPush_SDL_FRect(mrb, &in->viewport));
    SDLStaticGen_RubyHashSet(mrb, h, "visible", GenPush_SDL_FRect(mrb, &in->visible));
    return h;
}

static void GenRead_SDLStatic_ChipToneDesc(mrb_state *mrb, mrb_value h, SDLStatic_ChipToneDesc *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->wave = (SDLStatic_ChipWave)SDLStaticGen_RubyFieldInt(mrb, h, "wave");
    out->freq_hz = (float)SDLStaticGen_RubyFieldNum(mrb, h, "freq_hz");
    out->freq_end_hz = (float)SDLStaticGen_RubyFieldNum(mrb, h, "freq_end_hz");
    out->duration_ms = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "duration_ms");
    out->volume = (float)SDLStaticGen_RubyFieldNum(mrb, h, "volume");
    out->attack_ms = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "attack_ms");
    out->release_ms = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "release_ms");
    out->vibrato_hz = (float)SDLStaticGen_RubyFieldNum(mrb, h, "vibrato_hz");
    out->vibrato_semitones = (float)SDLStaticGen_RubyFieldNum(mrb, h, "vibrato_semitones");
}

static void GenRead_SDLStatic_GraphicsSettings(mrb_state *mrb, mrb_value h, SDLStatic_GraphicsSettings *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->vsync = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "vsync");
    out->max_fps = (int)SDLStaticGen_RubyFieldInt(mrb, h, "max_fps");
    out->window_mode = (SDLStatic_WindowMode)SDLStaticGen_RubyFieldInt(mrb, h, "window_mode");
    out->window_width = (int)SDLStaticGen_RubyFieldInt(mrb, h, "window_width");
    out->window_height = (int)SDLStaticGen_RubyFieldInt(mrb, h, "window_height");
    out->display = (int)SDLStaticGen_RubyFieldInt(mrb, h, "display");
    out->presentation = (SDLStatic_EnginePresentation)SDLStaticGen_RubyFieldInt(mrb, h, "presentation");
    out->render_scale = (float)SDLStaticGen_RubyFieldNum(mrb, h, "render_scale");
    out->filter = (SDLStatic_TextureFilter)SDLStaticGen_RubyFieldInt(mrb, h, "filter");
    out->particles = (SDLStatic_GraphicsQuality)SDLStaticGen_RubyFieldInt(mrb, h, "particles");
    out->dynamic_lights = (SDLStatic_GraphicsQuality)SDLStaticGen_RubyFieldInt(mrb, h, "dynamic_lights");
    out->shadows = (SDLStatic_GraphicsQuality)SDLStaticGen_RubyFieldInt(mrb, h, "shadows");
    out->bloom = (float)SDLStaticGen_RubyFieldNum(mrb, h, "bloom");
    out->bloom_threshold = (float)SDLStaticGen_RubyFieldNum(mrb, h, "bloom_threshold");
    out->crt = (float)SDLStaticGen_RubyFieldNum(mrb, h, "crt");
    out->crt_curvature = (float)SDLStaticGen_RubyFieldNum(mrb, h, "crt_curvature");
    out->pixelation = (int)SDLStaticGen_RubyFieldInt(mrb, h, "pixelation");
    out->chromatic_aberration = (float)SDLStaticGen_RubyFieldNum(mrb, h, "chromatic_aberration");
    out->antialias = (SDLStatic_GraphicsAA)SDLStaticGen_RubyFieldInt(mrb, h, "antialias");
    out->brightness = (float)SDLStaticGen_RubyFieldNum(mrb, h, "brightness");
    out->contrast = (float)SDLStaticGen_RubyFieldNum(mrb, h, "contrast");
    out->saturation = (float)SDLStaticGen_RubyFieldNum(mrb, h, "saturation");
    out->color_blind = (SDLStatic_ColorBlindMode)SDLStaticGen_RubyFieldInt(mrb, h, "color_blind");
    out->reduced_flashing = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "reduced_flashing");
    out->screen_shake = (float)SDLStaticGen_RubyFieldNum(mrb, h, "screen_shake");
    out->ui_scale = (float)SDLStaticGen_RubyFieldNum(mrb, h, "ui_scale");
}

static mrb_value GenPush_SDLStatic_GraphicsSettings(mrb_state *mrb, const SDLStatic_GraphicsSettings *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "vsync", mrb_bool_value((mrb_bool)(in->vsync != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "max_fps", mrb_int_value(mrb, (mrb_int)in->max_fps));
    SDLStaticGen_RubyHashSet(mrb, h, "window_mode", mrb_int_value(mrb, (mrb_int)in->window_mode));
    SDLStaticGen_RubyHashSet(mrb, h, "window_width", mrb_int_value(mrb, (mrb_int)in->window_width));
    SDLStaticGen_RubyHashSet(mrb, h, "window_height", mrb_int_value(mrb, (mrb_int)in->window_height));
    SDLStaticGen_RubyHashSet(mrb, h, "display", mrb_int_value(mrb, (mrb_int)in->display));
    SDLStaticGen_RubyHashSet(mrb, h, "presentation", mrb_int_value(mrb, (mrb_int)in->presentation));
    SDLStaticGen_RubyHashSet(mrb, h, "render_scale", mrb_float_value(mrb, (mrb_float)in->render_scale));
    SDLStaticGen_RubyHashSet(mrb, h, "filter", mrb_int_value(mrb, (mrb_int)in->filter));
    SDLStaticGen_RubyHashSet(mrb, h, "particles", mrb_int_value(mrb, (mrb_int)in->particles));
    SDLStaticGen_RubyHashSet(mrb, h, "dynamic_lights", mrb_int_value(mrb, (mrb_int)in->dynamic_lights));
    SDLStaticGen_RubyHashSet(mrb, h, "shadows", mrb_int_value(mrb, (mrb_int)in->shadows));
    SDLStaticGen_RubyHashSet(mrb, h, "bloom", mrb_float_value(mrb, (mrb_float)in->bloom));
    SDLStaticGen_RubyHashSet(mrb, h, "bloom_threshold", mrb_float_value(mrb, (mrb_float)in->bloom_threshold));
    SDLStaticGen_RubyHashSet(mrb, h, "crt", mrb_float_value(mrb, (mrb_float)in->crt));
    SDLStaticGen_RubyHashSet(mrb, h, "crt_curvature", mrb_float_value(mrb, (mrb_float)in->crt_curvature));
    SDLStaticGen_RubyHashSet(mrb, h, "pixelation", mrb_int_value(mrb, (mrb_int)in->pixelation));
    SDLStaticGen_RubyHashSet(mrb, h, "chromatic_aberration", mrb_float_value(mrb, (mrb_float)in->chromatic_aberration));
    SDLStaticGen_RubyHashSet(mrb, h, "antialias", mrb_int_value(mrb, (mrb_int)in->antialias));
    SDLStaticGen_RubyHashSet(mrb, h, "brightness", mrb_float_value(mrb, (mrb_float)in->brightness));
    SDLStaticGen_RubyHashSet(mrb, h, "contrast", mrb_float_value(mrb, (mrb_float)in->contrast));
    SDLStaticGen_RubyHashSet(mrb, h, "saturation", mrb_float_value(mrb, (mrb_float)in->saturation));
    SDLStaticGen_RubyHashSet(mrb, h, "color_blind", mrb_int_value(mrb, (mrb_int)in->color_blind));
    SDLStaticGen_RubyHashSet(mrb, h, "reduced_flashing", mrb_bool_value((mrb_bool)(in->reduced_flashing != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "screen_shake", mrb_float_value(mrb, (mrb_float)in->screen_shake));
    SDLStaticGen_RubyHashSet(mrb, h, "ui_scale", mrb_float_value(mrb, (mrb_float)in->ui_scale));
    return h;
}

static void GenRead_SDL_FColor(mrb_state *mrb, mrb_value h, SDL_FColor *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->r = (float)SDLStaticGen_RubyFieldNum(mrb, h, "r");
    out->g = (float)SDLStaticGen_RubyFieldNum(mrb, h, "g");
    out->b = (float)SDLStaticGen_RubyFieldNum(mrb, h, "b");
    out->a = (float)SDLStaticGen_RubyFieldNum(mrb, h, "a");
}

static mrb_value GenPush_SDL_FColor(mrb_state *mrb, const SDL_FColor *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "r", mrb_float_value(mrb, (mrb_float)in->r));
    SDLStaticGen_RubyHashSet(mrb, h, "g", mrb_float_value(mrb, (mrb_float)in->g));
    SDLStaticGen_RubyHashSet(mrb, h, "b", mrb_float_value(mrb, (mrb_float)in->b));
    SDLStaticGen_RubyHashSet(mrb, h, "a", mrb_float_value(mrb, (mrb_float)in->a));
    return h;
}

static void GenRead_SDLStatic_Light(mrb_state *mrb, mrb_value h, SDLStatic_Light *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "x");
    out->y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "y");
    out->radius = (float)SDLStaticGen_RubyFieldNum(mrb, h, "radius");
    GenRead_SDL_FColor(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "color"), &out->color);
    out->falloff = (float)SDLStaticGen_RubyFieldNum(mrb, h, "falloff");
    out->angle = (float)SDLStaticGen_RubyFieldNum(mrb, h, "angle");
    out->spread = (float)SDLStaticGen_RubyFieldNum(mrb, h, "spread");
    out->flicker = (float)SDLStaticGen_RubyFieldNum(mrb, h, "flicker");
    out->seed = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "seed");
    out->no_shadows = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "no_shadows");
}

static void GenRead_SDLStatic_LightDef(mrb_state *mrb, mrb_value h, SDLStatic_LightDef *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->radius = (float)SDLStaticGen_RubyFieldNum(mrb, h, "radius");
    GenRead_SDL_FColor(mrb, SDLStaticGen_RubyFieldGet(mrb, h, "color"), &out->color);
    out->offset_x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "offset_x");
    out->offset_y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "offset_y");
    out->falloff = (float)SDLStaticGen_RubyFieldNum(mrb, h, "falloff");
    out->cone_direction = (float)SDLStaticGen_RubyFieldNum(mrb, h, "cone_direction");
    out->cone_width = (float)SDLStaticGen_RubyFieldNum(mrb, h, "cone_width");
    out->flicker = (float)SDLStaticGen_RubyFieldNum(mrb, h, "flicker");
    out->no_shadows = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "no_shadows");
    out->enabled = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "enabled");
}

static mrb_value GenPush_SDLStatic_LightDef(mrb_state *mrb, const SDLStatic_LightDef *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "radius", mrb_float_value(mrb, (mrb_float)in->radius));
    SDLStaticGen_RubyHashSet(mrb, h, "color", GenPush_SDL_FColor(mrb, &in->color));
    SDLStaticGen_RubyHashSet(mrb, h, "offset_x", mrb_float_value(mrb, (mrb_float)in->offset_x));
    SDLStaticGen_RubyHashSet(mrb, h, "offset_y", mrb_float_value(mrb, (mrb_float)in->offset_y));
    SDLStaticGen_RubyHashSet(mrb, h, "falloff", mrb_float_value(mrb, (mrb_float)in->falloff));
    SDLStaticGen_RubyHashSet(mrb, h, "cone_direction", mrb_float_value(mrb, (mrb_float)in->cone_direction));
    SDLStaticGen_RubyHashSet(mrb, h, "cone_width", mrb_float_value(mrb, (mrb_float)in->cone_width));
    SDLStaticGen_RubyHashSet(mrb, h, "flicker", mrb_float_value(mrb, (mrb_float)in->flicker));
    SDLStaticGen_RubyHashSet(mrb, h, "no_shadows", mrb_bool_value((mrb_bool)(in->no_shadows != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "enabled", mrb_bool_value((mrb_bool)(in->enabled != 0)));
    return h;
}

static void GenRead_SDLStatic_PhysicsDrawConfig(mrb_state *mrb, mrb_value h, SDLStatic_PhysicsDrawConfig *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->pixels_per_meter = (float)SDLStaticGen_RubyFieldNum(mrb, h, "pixels_per_meter");
    out->offset_x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "offset_x");
    out->offset_y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "offset_y");
    out->draw_joints = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "draw_joints");
}

static mrb_value GenPush_SDLStatic_RayHit(mrb_state *mrb, const SDLStatic_RayHit *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "hit", mrb_bool_value((mrb_bool)(in->hit != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "actor", mrb_int_value(mrb, (mrb_int)in->actor));
    SDLStaticGen_RubyHashSet(mrb, h, "x", mrb_float_value(mrb, (mrb_float)in->x));
    SDLStaticGen_RubyHashSet(mrb, h, "y", mrb_float_value(mrb, (mrb_float)in->y));
    SDLStaticGen_RubyHashSet(mrb, h, "normal_x", mrb_float_value(mrb, (mrb_float)in->normal_x));
    SDLStaticGen_RubyHashSet(mrb, h, "normal_y", mrb_float_value(mrb, (mrb_float)in->normal_y));
    SDLStaticGen_RubyHashSet(mrb, h, "fraction", mrb_float_value(mrb, (mrb_float)in->fraction));
    return h;
}

static mrb_value GenPush_SDLStatic_RenderStats(mrb_state *mrb, const SDLStatic_RenderStats *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "considered", mrb_int_value(mrb, (mrb_int)in->considered));
    SDLStaticGen_RubyHashSet(mrb, h, "culled", mrb_int_value(mrb, (mrb_int)in->culled));
    SDLStaticGen_RubyHashSet(mrb, h, "drawn", mrb_int_value(mrb, (mrb_int)in->drawn));
    return h;
}

static mrb_value GenPush_SDLStatic_SaveInfo(mrb_state *mrb, const SDLStatic_SaveInfo *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "exists", mrb_bool_value((mrb_bool)(in->exists != 0)));
    SDLStaticGen_RubyHashSet(mrb, h, "size", mrb_int_value(mrb, (mrb_int)in->size));
    SDLStaticGen_RubyHashSet(mrb, h, "modified", mrb_int_value(mrb, (mrb_int)in->modified));
    {
        mrb_value arr = mrb_ary_new_capa(mrb, (mrb_int)(128));
        for (mrb_int gi = 0; gi < (mrb_int)(128); ++gi) {
            mrb_ary_push(mrb, arr, mrb_int_value(mrb, (mrb_int)in->label[gi]));
        }
        SDLStaticGen_RubyHashSet(mrb, h, "label", arr);
    }
    return h;
}

static void GenRead_SDL_Color(mrb_state *mrb, mrb_value h, SDL_Color *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->r = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "r");
    out->g = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "g");
    out->b = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "b");
    out->a = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "a");
}

static void GenRead_b2BodyId(mrb_state *mrb, mrb_value h, b2BodyId *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->index1 = (int32_t)SDLStaticGen_RubyFieldInt(mrb, h, "index1");
    out->world0 = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "world0");
    out->generation = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "generation");
}

static void GenRead_b2WorldId(mrb_state *mrb, mrb_value h, b2WorldId *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->index1 = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "index1");
    out->generation = (uint16_t)SDLStaticGen_RubyFieldInt(mrb, h, "generation");
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

static mrb_value GenR_SDLStatic_ActionBind(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_Binding a2;
    GenRead_SDLStatic_Binding(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    bool rv = SDLStatic_ActionBind(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionBindAxis(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GamepadAxis a2 = (SDLStatic_GamepadAxis)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_ActionBindAxis(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionBindDirection(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_Direction a2 = (SDLStatic_Direction)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_ActionBindDirection(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionBindKey(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Scancode a2 = (SDL_Scancode)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_ActionBindKey(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionBindKeySigned(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Scancode a2 = (SDL_Scancode)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_ActionBindKeySigned(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionBindMouse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_MouseButton a2 = (SDLStatic_MouseButton)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_ActionBindMouse(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionBindPad(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GamepadButton a2 = (SDLStatic_GamepadButton)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_ActionBindPad(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionBindingAt(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_Binding out3;
    memset(&out3, 0, sizeof(out3));
    bool rv = SDLStatic_ActionBindingAt(a0, a1, a2, &out3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDLStatic_Binding(mrb, &out3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_ActionBindingCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_ActionBindingCount(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActionCapture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_Binding out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDLStatic_ActionCapture(a0, a1, &out2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDLStatic_Binding(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_ActionClear(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActionClear(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActionCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    int rv = SDLStatic_ActionCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActionDown(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ActionMap *a1 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_ActionMap");
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_ActionDown(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionMapCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap * rv = SDLStatic_ActionMapCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_ActionMap");
    }
}

static mrb_value GenR_SDLStatic_ActionMapDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    SDLStatic_ActionMapDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActionMapKeyboardPlayer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    int rv = SDLStatic_ActionMapKeyboardPlayer(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActionMapLoad(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_ActionMapLoad(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionMapLoadToml(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_ActionMapLoadToml(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionMapSave(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_ActionMapSave(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionMapSetKeyboardPlayer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActionMapSetKeyboardPlayer(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActionMapToToml(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    char * rv = SDLStatic_ActionMapToToml(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDLStatic_ActionName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActionMap *a0 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActionMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_ActionName(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_ActionPressed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ActionMap *a1 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_ActionMap");
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_ActionPressed(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionReleased(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ActionMap *a1 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_ActionMap");
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_ActionReleased(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActionValue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ActionMap *a1 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_ActionMap");
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float rv = SDLStatic_ActionValue(a0, a1, a2, a3);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_ActionVector(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ActionMap *a1 = (SDLStatic_ActionMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_ActionMap");
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    const char *a4 = SDLStaticGen_RubyToStr(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float io5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float io6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    SDLStatic_ActionVector(a0, a1, a2, a3, a4, &io5, &io6);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)io5);
    rets[1] = mrb_float_value(mrb, (mrb_float)io6);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_ActorAddBody(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_BodyDef tmp1;
    const SDLStatic_BodyDef *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_BodyDef(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_ActorAddBody(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActorAddLight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_LightDef tmp1;
    const SDLStatic_LightDef *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_LightDef(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_ActorAddLight(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActorAlive(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_ActorAlive(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActorAngularVelocity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    float rv = SDLStatic_ActorAngularVelocity(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_ActorApplyForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorApplyForce(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorApplyImpulse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorApplyImpulse(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorBodyBounds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDL_FRect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDLStatic_ActorBodyBounds(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_FRect(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_ActorBroadcast(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorTags a2 = (SDLStatic_ActorTags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorMessage tmp3;
    const SDLStatic_ActorMessage *a3 = NULL;
    if (argc > 3 && mrb_hash_p(argv[3])) {
        GenRead_SDLStatic_ActorMessage(mrb, argv[3], &tmp3);
        a3 = &tmp3;
    }
    int rv = SDLStatic_ActorBroadcast(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActorChild(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorId rv = SDLStatic_ActorChild(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActorChildCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    int rv = SDLStatic_ActorChildCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActorClear(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ActorClear(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorClearSprite(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorClearSprite(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_ActorCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActorDefCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActorDef * rv = SDLStatic_ActorDefCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_ActorDef");
    }
}

static mrb_value GenR_SDLStatic_ActorDefDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActorDef");
    SDLStatic_ActorDefDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorDefSetName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActorDef");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorDefSetName(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorDefSetParent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActorDef");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorDefSetParent(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorDefSetPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActorDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorDefSetPosition(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorDefSetRotation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActorDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorDefSetRotation(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorDefSetScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActorDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorDefSetScale(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorDefSetStateSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActorDef");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorDefSetStateSize(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorDefSetTags(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActorDef");
    SDLStatic_ActorTags a1 = (SDLStatic_ActorTags)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorDefSetTags(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorDefSetType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_ActorDef *a0 = (SDLStatic_ActorDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_ActorDef");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorDefSetType(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorDestroy(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    bool rv = SDLStatic_ActorEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActorEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_Engine * rv = SDLStatic_ActorEngine(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_Engine");
    }
}

static mrb_value GenR_SDLStatic_ActorFindByName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorId rv = SDLStatic_ActorFindByName(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActorFindByType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorId rv = SDLStatic_ActorFindByType(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActorGet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_Actor * rv = SDLStatic_ActorGet(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_Actor");
    }
}

static mrb_value GenR_SDLStatic_ActorGetId(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorId rv = SDLStatic_ActorGetId(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActorGetTags(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorTags rv = SDLStatic_ActorGetTags(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActorHasBody(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    bool rv = SDLStatic_ActorHasBody(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActorHasTags(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorTags a1 = (SDLStatic_ActorTags)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_ActorHasTags(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActorLocal(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorTransform rv = SDLStatic_ActorLocal(a0);
    return GenPush_SDLStatic_ActorTransform(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_ActorMove(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorMove(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    const char * rv = SDLStatic_ActorName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_ActorParent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorId rv = SDLStatic_ActorParent(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActorQuery(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorTags a2 = (SDLStatic_ActorTags)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorId io3 = (SDLStatic_ActorId)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int rv = SDLStatic_ActorQuery(a0, a1, a2, &io3, a4);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_ActorRemoveBody(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorRemoveBody(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorRemoveLight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorRemoveLight(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorRenderTransform(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorTransform rv = SDLStatic_ActorRenderTransform(a0, a1);
    return GenPush_SDLStatic_ActorTransform(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_ActorSend(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorMessage tmp2;
    const SDLStatic_ActorMessage *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDLStatic_ActorMessage(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    bool rv = SDLStatic_ActorSend(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActorSetAngularVelocity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorSetAngularVelocity(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorSetEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorSetEnabled(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorSetLocal(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorTransform tmp1;
    const SDLStatic_ActorTransform *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_ActorTransform(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDLStatic_ActorSetLocal(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorSetParent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorId a1 = (SDLStatic_ActorId)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_ActorSetParent(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActorSetPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorSetPosition(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorSetSprite(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    const SDLStatic_Sprite *a1 = (const SDLStatic_Sprite *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_Sprite");
    bool rv = SDLStatic_ActorSetSprite(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ActorSetTags(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorTags a1 = (SDLStatic_ActorTags)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ActorSetTags(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorSetVelocity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorSetVelocity(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorSpawn(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const SDLStatic_ActorDef *a1 = (const SDLStatic_ActorDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_ActorDef");
    SDLStatic_ActorId rv = SDLStatic_ActorSpawn(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_ActorSprite(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_Sprite * rv = SDLStatic_ActorSprite(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_Sprite");
    }
}

static mrb_value GenR_SDLStatic_ActorTeleport(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorTeleport(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorTeleportBody(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorTeleportBody(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    const char * rv = SDLStatic_ActorType(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_ActorVelocity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorVelocity(a0, &io1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)io1);
    rets[1] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_ActorWakeBody(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorWakeBody(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ActorWorld(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Actor *a0 = (SDLStatic_Actor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Actor");
    SDLStatic_ActorTransform rv = SDLStatic_ActorWorld(a0);
    return GenPush_SDLStatic_ActorTransform(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_AddDarkZone(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    SDL_FRect a1;
    GenRead_SDL_FRect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    SDL_FColor a2;
    GenRead_SDL_FColor(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    bool rv = SDLStatic_AddDarkZone(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_AddLight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    SDLStatic_Light tmp1;
    const SDLStatic_Light *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_Light(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_AddLight(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_AddOccluderRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    SDL_FRect a1;
    GenRead_SDL_FRect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    bool rv = SDLStatic_AddOccluderRect(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_AddOccluderSegment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDLStatic_AddOccluderSegment(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_AnyInput(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool rv = SDLStatic_AnyInput(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_AssetPath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_TextureId a1 = (SDLStatic_TextureId)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_AssetPath(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_AssetRelease(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_TextureId a1 = (SDLStatic_TextureId)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_AssetRelease(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_AssetRetain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_TextureId a1 = (SDLStatic_TextureId)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_AssetRetain(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_AssetStatusOf(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_TextureId a1 = (SDLStatic_TextureId)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_AssetStatus rv = SDLStatic_AssetStatusOf(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_AssetsFrameBudget(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_AssetsFrameBudget(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_AssetsLoaded(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_AssetsLoaded(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_AssetsPending(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_AssetsPending(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_AssetsProgress(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_AssetsProgress(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_AssetsReady(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool rv = SDLStatic_AssetsReady(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_AssetsSetFrameBudget(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_AssetsSetFrameBudget(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_AssetsSetWorkers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_AssetsSetWorkers(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_AssetsWait(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_AssetsWait(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_BidiBaseIsRTL(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_BidiBaseIsRTL(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_BindingFromString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_Binding out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDLStatic_BindingFromString(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDLStatic_Binding(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_BindingToString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Binding a0;
    GenRead_SDLStatic_Binding(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const char *src1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char *a1 = SDL_strdup(src1 != NULL ? src1 : "");
    size_t a2 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char * rv = SDLStatic_BindingToString(a0, a1, a2);
    SDL_free(a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_BodyDefDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_BodyDefDestroy(&out0);
    return GenPush_SDLStatic_BodyDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_BodyDefSetBullet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_BodyDefSetBullet(&out0, a1);
    return GenPush_SDLStatic_BodyDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_BodyDefSetFilter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_BodyDefSetFilter(&out0, a1, a2);
    return GenPush_SDLStatic_BodyDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_BodyDefSetFixedRotation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_BodyDefSetFixedRotation(&out0, a1);
    return GenPush_SDLStatic_BodyDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_BodyDefSetGravityScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_BodyDefSetGravityScale(&out0, a1);
    return GenPush_SDLStatic_BodyDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_BodyDefSetMaterial(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_BodyDefSetMaterial(&out0, a1, a2, a3);
    return GenPush_SDLStatic_BodyDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_BodyDefSetOffset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_BodyDefSetOffset(&out0, a1, a2);
    return GenPush_SDLStatic_BodyDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_BodyDefSetSensor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_BodyDefSetSensor(&out0, a1);
    return GenPush_SDLStatic_BodyDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_BodyDefSetShape(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_ShapeType a1 = (SDLStatic_ShapeType)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_BodyDefSetShape(&out0, a1);
    return GenPush_SDLStatic_BodyDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_BodyDefSetSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_BodyDefSetSize(&out0, a1, a2);
    return GenPush_SDLStatic_BodyDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_BodyDefSetType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_BodyType a1 = (SDLStatic_BodyType)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_BodyDefSetType(&out0, a1);
    return GenPush_SDLStatic_BodyDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_BodyDefault(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_BodyDef rv = SDLStatic_BodyDefault();
    return GenPush_SDLStatic_BodyDef(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_CameraBegin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_Camera tmp1;
    const SDLStatic_Camera *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_Camera(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_CameraBegin(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_CameraDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_CameraDestroy(&out0);
    return GenPush_SDLStatic_Camera(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_CameraEnd(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_CameraEnd(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_CameraFollow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_CameraFollow(&out0, a1, a2);
    return GenPush_SDLStatic_Camera(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_CameraInit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_Engine *a1 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_CameraInit(&out0, a1);
    return GenPush_SDLStatic_Camera(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_CameraPoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera tmp0;
    const SDLStatic_Camera *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDLStatic_Camera(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_CameraPoint(a0, a1, a2, &io3, &io4);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)io3);
    rets[1] = mrb_float_value(mrb, (mrb_float)io4);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_CameraRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera tmp0;
    const SDLStatic_Camera *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDLStatic_Camera(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_FRect a1;
    GenRead_SDL_FRect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    SDL_FRect rv = SDLStatic_CameraRect(a0, a1);
    return GenPush_SDL_FRect(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_CameraScreenToWorld(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera tmp0;
    const SDLStatic_Camera *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDLStatic_Camera(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDLStatic_CameraScreenToWorld(a0, a1, a2, &io3, &io4);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io3);
    rets[2] = mrb_float_value(mrb, (mrb_float)io4);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDLStatic_CameraSetBounds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_CameraSetBounds(&out0, a1, a2, a3, a4);
    return GenPush_SDLStatic_Camera(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_CameraSetDeadzone(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_CameraSetDeadzone(&out0, a1, a2);
    return GenPush_SDLStatic_Camera(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_CameraSetSmoothing(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_CameraSetSmoothing(&out0, a1);
    return GenPush_SDLStatic_Camera(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_CameraSetViewport(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_CameraSetViewport(&out0, a1, a2, a3, a4);
    return GenPush_SDLStatic_Camera(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_CameraSetZoom(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_CameraSetZoom(&out0, a1);
    return GenPush_SDLStatic_Camera(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_CameraShake(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_CameraShake(&out0, a1, a2);
    return GenPush_SDLStatic_Camera(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_CameraSnap(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_CameraSnap(&out0, a1, a2);
    return GenPush_SDLStatic_Camera(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_CameraSplit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_SplitMode a1 = (SDLStatic_SplitMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_Camera out4;
    memset(&out4, 0, sizeof(out4));
    int rv = SDLStatic_CameraSplit(a0, a1, a2, a3, &out4);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_SDLStatic_Camera(mrb, &out4);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_CameraUpdate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_Engine *a1 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_CameraUpdate(&out0, a1, a2);
    return GenPush_SDLStatic_Camera(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_CameraVisible(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera tmp0;
    const SDLStatic_Camera *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDLStatic_Camera(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_FRect a1;
    GenRead_SDL_FRect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    bool rv = SDLStatic_CameraVisible(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_CameraX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float rv = SDLStatic_CameraX(&out0);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)rv);
    rets[1] = GenPush_SDLStatic_Camera(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_CameraY(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Camera out0;
    memset(&out0, 0, sizeof(out0));
    float rv = SDLStatic_CameraY(&out0);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)rv);
    rets[1] = GenPush_SDLStatic_Camera(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_CompileRegex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_Regex * rv = SDLStatic_CompileRegex(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDLStatic_Regex", GenDtor_SDLStatic_DestroyRegex);
    }
}

static mrb_value GenR_SDLStatic_ConfigCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig * rv = SDLStatic_ConfigCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_EngineConfig");
    }
}

static mrb_value GenR_SDLStatic_ConfigDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    SDLStatic_ConfigDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetAutoMount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetAutoMount(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetBackend(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    SDLStatic_EngineBackend a1 = (SDLStatic_EngineBackend)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetBackend(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetDesignSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ConfigSetDesignSize(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetFullscreen(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetFullscreen(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetGraphics(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    SDLStatic_GraphicsSettings tmp1;
    const SDLStatic_GraphicsSettings *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_GraphicsSettings(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDLStatic_ConfigSetGraphics(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetHeadless(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetHeadless(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetHighDpi(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetHighDpi(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetManualClock(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetManualClock(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetMaxFps(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetMaxFps(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetMediaPath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetMediaPath(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetPresentation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    SDLStatic_EnginePresentation a1 = (SDLStatic_EnginePresentation)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetPresentation(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetResizable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetResizable(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetTickRate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetTickRate(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetTitle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetTitle(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetVsync(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_ConfigSetVsync(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ConfigSetWindowSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_EngineConfig *a0 = (SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ConfigSetWindowSize(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_CountSignalConnections(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_SignalEmitter");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_CountSignalConnections(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_CreateChipSFX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    SDLStatic_ChipSFX a1 = (SDLStatic_ChipSFX)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    MIX_Audio * rv = SDLStatic_CreateChipSFX(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Audio");
    }
}

static mrb_value GenR_SDLStatic_CreateChipTone(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    SDLStatic_ChipToneDesc tmp1;
    const SDLStatic_ChipToneDesc *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_ChipToneDesc(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    MIX_Audio * rv = SDLStatic_CreateChipTone(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Audio");
    }
}

static mrb_value GenR_SDLStatic_CreateChipTune(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    MIX_Audio * rv = SDLStatic_CreateChipTune(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Audio");
    }
}

static mrb_value GenR_SDLStatic_CreateEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_EngineConfig *a0 = (const SDLStatic_EngineConfig *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_EngineConfig");
    SDLStatic_Engine * rv = SDLStatic_CreateEngine(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_Engine");
    }
}

static mrb_value GenR_SDLStatic_CreateGui(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_Gui * rv = SDLStatic_CreateGui(a0, (const void *)a1, (size_t)len1, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDLStatic_Gui", GenDtor_SDLStatic_DestroyGui);
    }
}

static mrb_value GenR_SDLStatic_CreateGuiWithGlyphs(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GuiGlyphRange a4 = (SDLStatic_GuiGlyphRange)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_Gui * rv = SDLStatic_CreateGuiWithGlyphs(a0, (const void *)a1, (size_t)len1, a3, a4);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_Gui");
    }
}

static mrb_value GenR_SDLStatic_CreateLightScene(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDLStatic_LightScene * rv = SDLStatic_CreateLightScene(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDLStatic_LightScene", GenDtor_SDLStatic_DestroyLightScene);
    }
}

static mrb_value GenR_SDLStatic_CreateSignalEmitter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_SignalEmitter * rv = SDLStatic_CreateSignalEmitter();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_SignalEmitter");
    }
}

static mrb_value GenR_SDLStatic_CryptoSelfTest(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDLStatic_CryptoSelfTest();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_DayNightAmbient(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_FColor rv = SDLStatic_DayNightAmbient(a0);
    return GenPush_SDL_FColor(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_DayNightSunlight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float rv = SDLStatic_DayNightSunlight(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_DestroyEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_DestroyEngine(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DestroyGui(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_DestroyGui(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DestroyLightScene(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    SDLStatic_DestroyLightScene(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DestroyRegex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    SDLStatic_DestroyRegex(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DestroySignalEmitter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_SignalEmitter");
    SDLStatic_DestroySignalEmitter(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DeviceAccelerometer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_DeviceAccelerometer(a0, &io1, &io2, &io3);
    mrb_value rets[3];
    rets[0] = mrb_float_value(mrb, (mrb_float)io1);
    rets[1] = mrb_float_value(mrb, (mrb_float)io2);
    rets[2] = mrb_float_value(mrb, (mrb_float)io3);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDLStatic_DeviceGyro(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_DeviceGyro(a0, &io1, &io2, &io3);
    mrb_value rets[3];
    rets[0] = mrb_float_value(mrb, (mrb_float)io1);
    rets[1] = mrb_float_value(mrb, (mrb_float)io2);
    rets[2] = mrb_float_value(mrb, (mrb_float)io3);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDLStatic_DialogDeliverSave(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDLStatic_DialogDeliverSave(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_DialogPath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = SDLStatic_DialogPath();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_DialogReset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_DialogReset();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DialogStatus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_DialogState rv = SDLStatic_DialogStatus();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_DisconnectSignal(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_SignalEmitter *a0 = (SDLStatic_SignalEmitter *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_SignalEmitter");
    Uint64 a1 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_DisconnectSignal(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_DistanceJointDefCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DistanceJointDef * rv = SDLStatic_DistanceJointDefCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "b2DistanceJointDef");
    }
}

static mrb_value GenR_SDLStatic_DistanceJointDefDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DistanceJointDef");
    SDLStatic_DistanceJointDefDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DistanceJointDefSetAnchors(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DistanceJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_DistanceJointDefSetAnchors(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DistanceJointDefSetBodies(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DistanceJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2BodyId a2;
    GenRead_b2BodyId(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_DistanceJointDefSetBodies(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DistanceJointDefSetCollideConnected(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DistanceJointDef");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_DistanceJointDefSetCollideConnected(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DistanceJointDefSetLength(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DistanceJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_DistanceJointDefSetLength(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DistanceJointDefSetLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DistanceJointDef");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_DistanceJointDefSetLimit(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DistanceJointDefSetSpring(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2DistanceJointDef *a0 = (b2DistanceJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2DistanceJointDef");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_DistanceJointDefSetSpring(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_DrawPhysicsWorld(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WorldId a0;
    GenRead_b2WorldId(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    SDL_Renderer *a1 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Renderer");
    SDLStatic_PhysicsDrawConfig tmp2;
    const SDLStatic_PhysicsDrawConfig *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDLStatic_PhysicsDrawConfig(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    bool rv = SDLStatic_DrawPhysicsWorld(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_EncodeDataBase64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t len0 = 0;
    const char *a0 = SDLStaticGen_RubyToBlob(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &len0);
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char * rv = SDLStatic_EncodeDataBase64((const void *)a0, (int)len0, &io2);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    mrb_value rets[2];
    rets[0] = rstr;
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_EngineAdvance(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    Uint64 a1 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_EngineAdvance(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_EngineAlpha(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_EngineAlpha(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineAssetScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_EngineAssetScale(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineDelta(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_EngineDelta(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineDesignSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_EngineDesignSize(a0, &io1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)io1);
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_EngineDisplay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_EngineDisplay(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineDisplayCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDLStatic_EngineDisplayCount();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineDisplayName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDLStatic_EngineDisplayName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_EngineEffectsAvailable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool rv = SDLStatic_EngineEffectsAvailable(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_EngineEmbedMedia(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t len0 = 0;
    const char *a0 = SDLStaticGen_RubyToBlob(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &len0);
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_EngineEmbedMedia((const void *)a0, (int)len0, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_EngineFps(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_EngineFps(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineFrameCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    Uint64 rv = SDLStatic_EngineFrameCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineMaxFps(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_EngineMaxFps(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineMediaPath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char * rv = SDLStatic_EngineMediaPath(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_EngineMediaSource(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_MediaSource rv = SDLStatic_EngineMediaSource(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineOverloadFrames(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_EngineOverloadFrames(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EnginePixelSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_EnginePixelSize(a0, &io1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)io1);
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_EnginePresentation_(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_EnginePresentation rv = SDLStatic_EnginePresentation_(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineQuit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_EngineQuit(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_EngineRenderScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_EngineRenderScale(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineRenderer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_Renderer * rv = SDLStatic_EngineRenderer(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Renderer");
    }
}

static mrb_value GenR_SDLStatic_EngineSafeRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_FRect rv = SDLStatic_EngineSafeRect(a0);
    return GenPush_SDL_FRect(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_EngineSetClearColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_FColor a1;
    GenRead_SDL_FColor(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    SDLStatic_EngineSetClearColor(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_EngineSetDisplay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_EngineSetDisplay(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_EngineSetGraphics(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_GraphicsSettings tmp1;
    const SDLStatic_GraphicsSettings *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_GraphicsSettings(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_EngineSetGraphics(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_EngineSetMaxFps(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_EngineSetMaxFps(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_EngineSetMediaPassword(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_EngineSetMediaPassword(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_EngineSetPresentation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_EnginePresentation a1 = (SDLStatic_EnginePresentation)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_EngineSetPresentation(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_EngineSetRefreshRate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_EngineSetRefreshRate(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_EngineSetTickRate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_EngineSetTickRate(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_EngineSetTimeScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_EngineSetTimeScale(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_EngineStep(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_EngineStep(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineStepsLastFrame(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_EngineStepsLastFrame(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineTick(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool rv = SDLStatic_EngineTick(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_EngineTickRate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_EngineTickRate(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineTimeScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_EngineTimeScale(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EngineViewRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_FRect rv = SDLStatic_EngineViewRect(a0);
    return GenPush_SDL_FRect(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_EngineWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_Window * rv = SDLStatic_EngineWindow(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Window");
    }
}

static mrb_value GenR_SDLStatic_EngineWindowToDesign(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_EngineWindowToDesign(a0, a1, a2, &io3, &io4);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)io3);
    rets[1] = mrb_float_value(mrb, (mrb_float)io4);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_EventCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event * rv = SDLStatic_EventCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Event");
    }
}

static mrb_value GenR_SDLStatic_EventDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    SDLStatic_EventDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_EventGamepadAxis(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    int rv = SDLStatic_EventGamepadAxis(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EventGamepadAxisValue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    float rv = SDLStatic_EventGamepadAxisValue(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EventGamepadButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    int rv = SDLStatic_EventGamepadButton(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EventGamepadWhich(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    Sint32 rv = SDLStatic_EventGamepadWhich(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EventKeyModifiers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    Uint16 rv = SDLStatic_EventKeyModifiers(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EventKeyRepeat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    bool rv = SDLStatic_EventKeyRepeat(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_EventKeyScancode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    int rv = SDLStatic_EventKeyScancode(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EventMouseButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    int rv = SDLStatic_EventMouseButton(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EventMouseDeltaX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    float rv = SDLStatic_EventMouseDeltaX(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EventMouseDeltaY(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    float rv = SDLStatic_EventMouseDeltaY(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EventMouseX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    float rv = SDLStatic_EventMouseX(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EventMouseY(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    float rv = SDLStatic_EventMouseY(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EventSetType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_EventSetType(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_EventText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    const char * rv = SDLStatic_EventText(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_EventTouchX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    float rv = SDLStatic_EventTouchX(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EventTouchY(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    float rv = SDLStatic_EventTouchY(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EventType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    Uint32 rv = SDLStatic_EventType(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_EventWheelX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    float rv = SDLStatic_EventWheelX(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EventWheelY(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    float rv = SDLStatic_EventWheelY(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_EventWindowId(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    Uint32 rv = SDLStatic_EventWindowId(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_FilterJointDefCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2FilterJointDef * rv = SDLStatic_FilterJointDefCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "b2FilterJointDef");
    }
}

static mrb_value GenR_SDLStatic_FilterJointDefDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2FilterJointDef *a0 = (b2FilterJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2FilterJointDef");
    SDLStatic_FilterJointDefDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_FilterJointDefSetBodies(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2FilterJointDef *a0 = (b2FilterJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2FilterJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2BodyId a2;
    GenRead_b2BodyId(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_FilterJointDefSetBodies(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_FingerCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_FingerCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_FreeTiledMap(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_TiledMap *a0 = (SDLStatic_TiledMap *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    SDLStatic_FreeTiledMap(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUAcquireSwapchain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Window");
    SDL_GPUTexture * rv = SDLStatic_GPUAcquireSwapchain(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTexture");
    }
}

static mrb_value GenR_SDLStatic_GPUBeginComputePass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    SDLStatic_GPUComputeBindings *a1 = (SDLStatic_GPUComputeBindings *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_GPUComputeBindings");
    SDL_GPUComputePass * rv = SDLStatic_GPUBeginComputePass(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUComputePass");
    }
}

static mrb_value GenR_SDLStatic_GPUBindComputeStorageBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUBuffer *a2 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUBuffer");
    SDLStatic_GPUBindComputeStorageBuffer(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBindComputeStorageTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUTexture *a2 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUTexture");
    SDLStatic_GPUBindComputeStorageTexture(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBindFragmentStorageBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUBuffer *a2 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUBuffer");
    SDLStatic_GPUBindFragmentStorageBuffer(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBindFragmentStorageTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUTexture *a2 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUTexture");
    SDLStatic_GPUBindFragmentStorageTexture(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBindVertexStorageBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUBuffer *a2 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUBuffer");
    SDLStatic_GPUBindVertexStorageBuffer(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBindVertexStorageTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUTexture *a2 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUTexture");
    SDLStatic_GPUBindVertexStorageTexture(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBlitInfoCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBlitInfo * rv = SDLStatic_GPUBlitInfoCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUBlitInfo");
    }
}

static mrb_value GenR_SDLStatic_GPUBlitInfoDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBlitInfo *a0 = (SDL_GPUBlitInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUBlitInfo");
    SDLStatic_GPUBlitInfoDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBlitInfoSetDestination(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBlitInfo *a0 = (SDL_GPUBlitInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUBlitInfo");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    SDLStatic_GPUBlitInfoSetDestination(a0, a1, a2, a3, a4, a5);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBlitInfoSetFilter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBlitInfo *a0 = (SDL_GPUBlitInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUBlitInfo");
    SDL_GPUFilter a1 = (SDL_GPUFilter)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GPUBlitInfoSetFilter(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBlitInfoSetSource(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBlitInfo *a0 = (SDL_GPUBlitInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUBlitInfo");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    SDLStatic_GPUBlitInfoSetSource(a0, a1, a2, a3, a4, a5);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBufferBindingCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBufferBinding * rv = SDLStatic_GPUBufferBindingCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUBufferBinding");
    }
}

static mrb_value GenR_SDLStatic_GPUBufferBindingDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBufferBinding *a0 = (SDL_GPUBufferBinding *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUBufferBinding");
    SDLStatic_GPUBufferBindingDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBufferBindingSet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBufferBinding *a0 = (SDL_GPUBufferBinding *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUBufferBinding");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBuffer");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GPUBufferBindingSet(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBufferLocationCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBufferLocation * rv = SDLStatic_GPUBufferLocationCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUBufferLocation");
    }
}

static mrb_value GenR_SDLStatic_GPUBufferLocationDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBufferLocation *a0 = (SDL_GPUBufferLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUBufferLocation");
    SDLStatic_GPUBufferLocationDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBufferLocationSet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBufferLocation *a0 = (SDL_GPUBufferLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUBufferLocation");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBuffer");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GPUBufferLocationSet(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBufferRegionCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBufferRegion * rv = SDLStatic_GPUBufferRegionCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUBufferRegion");
    }
}

static mrb_value GenR_SDLStatic_GPUBufferRegionDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBufferRegion *a0 = (SDL_GPUBufferRegion *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUBufferRegion");
    SDLStatic_GPUBufferRegionDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUBufferRegionSet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUBufferRegion *a0 = (SDL_GPUBufferRegion *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUBufferRegion");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBuffer");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_GPUBufferRegionSet(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUColorTargetInfoCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUColorTargetInfo * rv = SDLStatic_GPUColorTargetInfoCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUColorTargetInfo");
    }
}

static mrb_value GenR_SDLStatic_GPUColorTargetInfoDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUColorTargetInfo *a0 = (SDL_GPUColorTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUColorTargetInfo");
    SDLStatic_GPUColorTargetInfoDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUColorTargetInfoSetClearColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUColorTargetInfo *a0 = (SDL_GPUColorTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUColorTargetInfo");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_GPUColorTargetInfoSetClearColor(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUColorTargetInfoSetCycle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUColorTargetInfo *a0 = (SDL_GPUColorTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUColorTargetInfo");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GPUColorTargetInfoSetCycle(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUColorTargetInfoSetMipLayer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUColorTargetInfo *a0 = (SDL_GPUColorTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUColorTargetInfo");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GPUColorTargetInfoSetMipLayer(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUColorTargetInfoSetOps(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUColorTargetInfo *a0 = (SDL_GPUColorTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUColorTargetInfo");
    SDL_GPULoadOp a1 = (SDL_GPULoadOp)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUStoreOp a2 = (SDL_GPUStoreOp)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GPUColorTargetInfoSetOps(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUColorTargetInfoSetTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUColorTargetInfo *a0 = (SDL_GPUColorTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUColorTargetInfo");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    SDLStatic_GPUColorTargetInfoSetTexture(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUComputeBindingsAddBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GPUComputeBindings *a0 = (SDLStatic_GPUComputeBindings *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GPUComputeBindings");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBuffer");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GPUComputeBindingsAddBuffer(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GPUComputeBindingsAddTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GPUComputeBindings *a0 = (SDLStatic_GPUComputeBindings *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GPUComputeBindings");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool a4 = (bool)SDLStaticGen_RubyToBool((argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDLStatic_GPUComputeBindingsAddTexture(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GPUComputeBindingsCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GPUComputeBindings * rv = SDLStatic_GPUComputeBindingsCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_GPUComputeBindings");
    }
}

static mrb_value GenR_SDLStatic_GPUComputeBindingsDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GPUComputeBindings *a0 = (SDLStatic_GPUComputeBindings *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GPUComputeBindings");
    SDLStatic_GPUComputeBindingsDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUComputePipelineInfoCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePipelineCreateInfo * rv = SDLStatic_GPUComputePipelineInfoCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUComputePipelineCreateInfo");
    }
}

static mrb_value GenR_SDLStatic_GPUComputePipelineInfoDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePipelineCreateInfo *a0 = (SDL_GPUComputePipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePipelineCreateInfo");
    SDLStatic_GPUComputePipelineInfoDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUComputePipelineInfoSetCode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePipelineCreateInfo *a0 = (SDL_GPUComputePipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePipelineCreateInfo");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    SDLStatic_GPUComputePipelineInfoSetCode(a0, (const void *)a1, (int)len1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUComputePipelineInfoSetEntrypoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePipelineCreateInfo *a0 = (SDL_GPUComputePipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePipelineCreateInfo");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GPUComputePipelineInfoSetEntrypoint(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUComputePipelineInfoSetFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePipelineCreateInfo *a0 = (SDL_GPUComputePipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePipelineCreateInfo");
    SDL_GPUShaderFormat a1 = (SDL_GPUShaderFormat)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GPUComputePipelineInfoSetFormat(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUComputePipelineInfoSetThreadCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePipelineCreateInfo *a0 = (SDL_GPUComputePipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePipelineCreateInfo");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_GPUComputePipelineInfoSetThreadCount(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUDepthStencilTargetInfoCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDepthStencilTargetInfo * rv = SDLStatic_GPUDepthStencilTargetInfoCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUDepthStencilTargetInfo");
    }
}

static mrb_value GenR_SDLStatic_GPUDepthStencilTargetInfoDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDepthStencilTargetInfo *a0 = (SDL_GPUDepthStencilTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDepthStencilTargetInfo");
    SDLStatic_GPUDepthStencilTargetInfoDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUDepthStencilTargetInfoSetClear(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDepthStencilTargetInfo *a0 = (SDL_GPUDepthStencilTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDepthStencilTargetInfo");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GPUDepthStencilTargetInfoSetClear(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUDepthStencilTargetInfoSetOps(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDepthStencilTargetInfo *a0 = (SDL_GPUDepthStencilTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDepthStencilTargetInfo");
    SDL_GPULoadOp a1 = (SDL_GPULoadOp)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUStoreOp a2 = (SDL_GPUStoreOp)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GPUDepthStencilTargetInfoSetOps(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUDepthStencilTargetInfoSetTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDepthStencilTargetInfo *a0 = (SDL_GPUDepthStencilTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDepthStencilTargetInfo");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    SDLStatic_GPUDepthStencilTargetInfoSetTexture(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUPipelineInfoAddColorTarget(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUGraphicsPipelineCreateInfo *a0 = (SDL_GPUGraphicsPipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUGraphicsPipelineCreateInfo");
    SDL_GPUTextureFormat a1 = (SDL_GPUTextureFormat)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GPUPipelineInfoAddColorTarget(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GPUPipelineInfoAddVertexAttribute(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUGraphicsPipelineCreateInfo *a0 = (SDL_GPUGraphicsPipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUGraphicsPipelineCreateInfo");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_GPUVertexElementFormat a3 = (SDL_GPUVertexElementFormat)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDLStatic_GPUPipelineInfoAddVertexAttribute(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GPUPipelineInfoAddVertexBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUGraphicsPipelineCreateInfo *a0 = (SDL_GPUGraphicsPipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUGraphicsPipelineCreateInfo");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_GPUVertexInputRate a3 = (SDL_GPUVertexInputRate)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_GPUPipelineInfoAddVertexBuffer(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GPUPipelineInfoCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUGraphicsPipelineCreateInfo * rv = SDLStatic_GPUPipelineInfoCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUGraphicsPipelineCreateInfo");
    }
}

static mrb_value GenR_SDLStatic_GPUPipelineInfoDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUGraphicsPipelineCreateInfo *a0 = (SDL_GPUGraphicsPipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUGraphicsPipelineCreateInfo");
    SDLStatic_GPUPipelineInfoDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUPipelineInfoSetDepthStencil(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUGraphicsPipelineCreateInfo *a0 = (SDL_GPUGraphicsPipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUGraphicsPipelineCreateInfo");
    SDL_GPUTextureFormat a1 = (SDL_GPUTextureFormat)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GPUPipelineInfoSetDepthStencil(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUPipelineInfoSetFillMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUGraphicsPipelineCreateInfo *a0 = (SDL_GPUGraphicsPipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUGraphicsPipelineCreateInfo");
    SDL_GPUFillMode a1 = (SDL_GPUFillMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUCullMode a2 = (SDL_GPUCullMode)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GPUPipelineInfoSetFillMode(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUPipelineInfoSetPrimitive(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUGraphicsPipelineCreateInfo *a0 = (SDL_GPUGraphicsPipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUGraphicsPipelineCreateInfo");
    SDL_GPUPrimitiveType a1 = (SDL_GPUPrimitiveType)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GPUPipelineInfoSetPrimitive(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUPipelineInfoSetShaders(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUGraphicsPipelineCreateInfo *a0 = (SDL_GPUGraphicsPipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUGraphicsPipelineCreateInfo");
    SDL_GPUShader *a1 = (SDL_GPUShader *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUShader");
    SDL_GPUShader *a2 = (SDL_GPUShader *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUShader");
    SDLStatic_GPUPipelineInfoSetShaders(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPURenderStateInfoAddSampler(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderStateCreateInfo *a0 = (SDL_GPURenderStateCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderStateCreateInfo");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    SDL_GPUSampler *a2 = (SDL_GPUSampler *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUSampler");
    bool rv = SDLStatic_GPURenderStateInfoAddSampler(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GPURenderStateInfoCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderStateCreateInfo * rv = SDLStatic_GPURenderStateInfoCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPURenderStateCreateInfo");
    }
}

static mrb_value GenR_SDLStatic_GPURenderStateInfoDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderStateCreateInfo *a0 = (SDL_GPURenderStateCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderStateCreateInfo");
    SDLStatic_GPURenderStateInfoDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPURenderStateInfoSetShader(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderStateCreateInfo *a0 = (SDL_GPURenderStateCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderStateCreateInfo");
    SDL_GPUShader *a1 = (SDL_GPUShader *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUShader");
    SDLStatic_GPURenderStateInfoSetShader(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUShaderCreateInfoCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUShaderCreateInfo * rv = SDLStatic_GPUShaderCreateInfoCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUShaderCreateInfo");
    }
}

static mrb_value GenR_SDLStatic_GPUShaderCreateInfoDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUShaderCreateInfo *a0 = (SDL_GPUShaderCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUShaderCreateInfo");
    SDLStatic_GPUShaderCreateInfoDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUShaderCreateInfoSetCode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUShaderCreateInfo *a0 = (SDL_GPUShaderCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUShaderCreateInfo");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    SDLStatic_GPUShaderCreateInfoSetCode(a0, (const void *)a1, (int)len1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUShaderCreateInfoSetCounts(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUShaderCreateInfo *a0 = (SDL_GPUShaderCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUShaderCreateInfo");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_GPUShaderCreateInfoSetCounts(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUShaderCreateInfoSetEntrypoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUShaderCreateInfo *a0 = (SDL_GPUShaderCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUShaderCreateInfo");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GPUShaderCreateInfoSetEntrypoint(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUShaderCreateInfoSetFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUShaderCreateInfo *a0 = (SDL_GPUShaderCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUShaderCreateInfo");
    SDL_GPUShaderFormat a1 = (SDL_GPUShaderFormat)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUShaderStage a2 = (SDL_GPUShaderStage)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GPUShaderCreateInfoSetFormat(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUSwapchainHeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 rv = SDLStatic_GPUSwapchainHeight();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_GPUSwapchainWidth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 rv = SDLStatic_GPUSwapchainWidth();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_GPUTextureLocationCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureLocation * rv = SDLStatic_GPUTextureLocationCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTextureLocation");
    }
}

static mrb_value GenR_SDLStatic_GPUTextureLocationDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureLocation *a0 = (SDL_GPUTextureLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUTextureLocation");
    SDLStatic_GPUTextureLocationDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUTextureLocationSet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureLocation *a0 = (SDL_GPUTextureLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUTextureLocation");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_GPUTextureLocationSet(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUTextureRegionCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureRegion * rv = SDLStatic_GPUTextureRegionCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTextureRegion");
    }
}

static mrb_value GenR_SDLStatic_GPUTextureRegionDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureRegion *a0 = (SDL_GPUTextureRegion *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUTextureRegion");
    SDLStatic_GPUTextureRegionDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUTextureRegionSet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureRegion *a0 = (SDL_GPUTextureRegion *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUTextureRegion");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    SDLStatic_GPUTextureRegionSet(a0, a1, a2, a3, a4, a5);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUTextureSamplerBindingCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureSamplerBinding * rv = SDLStatic_GPUTextureSamplerBindingCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTextureSamplerBinding");
    }
}

static mrb_value GenR_SDLStatic_GPUTextureSamplerBindingDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureSamplerBinding *a0 = (SDL_GPUTextureSamplerBinding *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUTextureSamplerBinding");
    SDLStatic_GPUTextureSamplerBindingDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUTextureSamplerBindingSet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureSamplerBinding *a0 = (SDL_GPUTextureSamplerBinding *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUTextureSamplerBinding");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    SDL_GPUSampler *a2 = (SDL_GPUSampler *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUSampler");
    SDLStatic_GPUTextureSamplerBindingSet(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUTextureTransferInfoCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureTransferInfo * rv = SDLStatic_GPUTextureTransferInfoCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTextureTransferInfo");
    }
}

static mrb_value GenR_SDLStatic_GPUTextureTransferInfoDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureTransferInfo *a0 = (SDL_GPUTextureTransferInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUTextureTransferInfo");
    SDLStatic_GPUTextureTransferInfoDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUTextureTransferInfoSet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureTransferInfo *a0 = (SDL_GPUTextureTransferInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUTextureTransferInfo");
    SDL_GPUTransferBuffer *a1 = (SDL_GPUTransferBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTransferBuffer");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_GPUTextureTransferInfoSet(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUTransferBufferLocationCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTransferBufferLocation * rv = SDLStatic_GPUTransferBufferLocationCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTransferBufferLocation");
    }
}

static mrb_value GenR_SDLStatic_GPUTransferBufferLocationDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTransferBufferLocation *a0 = (SDL_GPUTransferBufferLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUTransferBufferLocation");
    SDLStatic_GPUTransferBufferLocationDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUTransferBufferLocationSet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTransferBufferLocation *a0 = (SDL_GPUTransferBufferLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUTransferBufferLocation");
    SDL_GPUTransferBuffer *a1 = (SDL_GPUTransferBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTransferBuffer");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_GPUTransferBufferLocationSet(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GPUUploadToTransferBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUTransferBuffer *a1 = (SDL_GPUTransferBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTransferBuffer");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    size_t len3 = 0;
    const char *a3 = SDLStaticGen_RubyToBlob(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &len3);
    bool a5 = (bool)SDLStaticGen_RubyToBool((argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDLStatic_GPUUploadToTransferBuffer(a0, a1, a2, (const void *)a3, (int)len3, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GPUWaitAndAcquireSwapchain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Window");
    SDL_GPUTexture * rv = SDLStatic_GPUWaitAndAcquireSwapchain(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTexture");
    }
}

static mrb_value GenR_SDLStatic_GPUWaitForFence(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUFence *a1 = (SDL_GPUFence *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUFence");
    bool rv = SDLStatic_GPUWaitForFence(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadAccelerometer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_GamepadAccelerometer(a0, a1, &io2, &io3, &io4);
    mrb_value rets[3];
    rets[0] = mrb_float_value(mrb, (mrb_float)io2);
    rets[1] = mrb_float_value(mrb, (mrb_float)io3);
    rets[2] = mrb_float_value(mrb, (mrb_float)io4);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDLStatic_GamepadAxisValue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GamepadAxis a2 = (SDLStatic_GamepadAxis)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float rv = SDLStatic_GamepadAxisValue(a0, a1, a2);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_GamepadButtonDown(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GamepadButton a2 = (SDLStatic_GamepadButton)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GamepadButtonDown(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadButtonPressed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GamepadButton a2 = (SDLStatic_GamepadButton)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GamepadButtonPressed(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadButtonReleased(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GamepadButton a2 = (SDLStatic_GamepadButton)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GamepadButtonReleased(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadConnected(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GamepadConnected(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_GamepadCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_GamepadDeadzone(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_GamepadDeadzone(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_GamepadDirectionPressed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_Direction a2 = (SDLStatic_Direction)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GamepadDirectionPressed(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadDirectionRepeat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_Direction a2 = (SDLStatic_Direction)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GamepadDirectionRepeat(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadGyro(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_GamepadGyro(a0, a1, &io2, &io3, &io4);
    mrb_value rets[3];
    rets[0] = mrb_float_value(mrb, (mrb_float)io2);
    rets[1] = mrb_float_value(mrb, (mrb_float)io3);
    rets[2] = mrb_float_value(mrb, (mrb_float)io4);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDLStatic_GamepadHasAccelerometer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GamepadHasAccelerometer(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadHasGyro(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GamepadHasGyro(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_GamepadName(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_GamepadRumble(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDLStatic_GamepadRumble(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadRumbleTriggers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDLStatic_GamepadRumbleTriggers(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadSetLED(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDLStatic_GamepadSetLED(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GamepadStick(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_GamepadStick(a0, a1, a2, &io3, &io4);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)io3);
    rets[1] = mrb_float_value(mrb, (mrb_float)io4);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_GamepadStopRumble(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GamepadStopRumble(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GraphicsClamp(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsSettings out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_GraphicsClamp(&out0);
    return GenPush_SDLStatic_GraphicsSettings(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_GraphicsConfigError(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = SDLStatic_GraphicsConfigError();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_GraphicsConfigPath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = SDLStatic_GraphicsConfigPath();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_GraphicsDefaults(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsSettings rv = SDLStatic_GraphicsDefaults();
    return GenPush_SDLStatic_GraphicsSettings(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_GraphicsEqual(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsSettings tmp0;
    const SDLStatic_GraphicsSettings *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDLStatic_GraphicsSettings(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDLStatic_GraphicsSettings tmp1;
    const SDLStatic_GraphicsSettings *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_GraphicsSettings(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDLStatic_GraphicsEqual(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GraphicsLightMapScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float rv = SDLStatic_GraphicsLightMapScale(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_GraphicsLoadTomlFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsSettings out0;
    memset(&out0, 0, sizeof(out0));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDLStatic_GraphicsLoadTomlFile(&out0, a1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDLStatic_GraphicsSettings(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_GraphicsLoadTomlString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsSettings out0;
    memset(&out0, 0, sizeof(out0));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDLStatic_GraphicsLoadTomlString(&out0, a1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDLStatic_GraphicsSettings(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_GraphicsMaxDynamicLights(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = SDLStatic_GraphicsMaxDynamicLights(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_GraphicsParticleDensity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float rv = SDLStatic_GraphicsParticleDensity(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_GraphicsQualityFromName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_GraphicsQuality io1 = (SDLStatic_GraphicsQuality)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GraphicsQualityFromName(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_GraphicsQualityName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDLStatic_GraphicsQualityName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_GraphicsSafeMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsSettings rv = SDLStatic_GraphicsSafeMode();
    return GenPush_SDLStatic_GraphicsSettings(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_GraphicsSave(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsSettings tmp0;
    const SDLStatic_GraphicsSettings *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDLStatic_GraphicsSettings(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GraphicsSave(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GraphicsSavePath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char * rv = SDLStatic_GraphicsSavePath(a0, a1);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDLStatic_GraphicsShadowRays(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = SDLStatic_GraphicsShadowRays(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_GraphicsShadowSoftness(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsQuality a0 = (SDLStatic_GraphicsQuality)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float rv = SDLStatic_GraphicsShadowSoftness(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_GraphicsToToml(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GraphicsSettings tmp0;
    const SDLStatic_GraphicsSettings *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDLStatic_GraphicsSettings(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    char * rv = SDLStatic_GraphicsToToml(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDLStatic_GuiContext(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    struct nk_context * rv = SDLStatic_GuiContext(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "nk_context");
    }
}

static mrb_value GenR_SDLStatic_GuiDrawCommandCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int rv = SDLStatic_GuiDrawCommandCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_GuiDrawTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDL_FRect a2;
    GenRead_SDL_FRect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_GuiImageMode a3 = (SDLStatic_GuiImageMode)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_GuiDrawTexture(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiDrawTextureOverlay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDL_FRect a2;
    GenRead_SDL_FRect(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_GuiImageMode a3 = (SDLStatic_GuiImageMode)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_GuiDrawTextureOverlay(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiFontHeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    float rv = SDLStatic_GuiFontHeight(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_GuiGridBeginOwned(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GuiGridBeginOwned(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiGridCell(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GuiGrid");
    SDLStatic_GuiGridCell(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridCellOwned(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiGridCellOwned(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridCellSpan(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GuiGrid");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GuiGridCellSpan(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridCellSpanOwned(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GuiGridCellSpanOwned(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GuiGrid * rv = SDLStatic_GuiGridCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_GuiGrid");
    }
}

static mrb_value GenR_SDLStatic_GuiGridDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GuiGrid");
    SDLStatic_GuiGridDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridEnd(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GuiGrid");
    SDLStatic_GuiGridEnd(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridEndOwned(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiGridEndOwned(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridNextRow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_GuiGrid *a0 = (SDLStatic_GuiGrid *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_GuiGrid");
    SDLStatic_GuiGridNextRow(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridNextRowOwned(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiGridNextRowOwned(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiGridWeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GuiGridWeight(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiImage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDLStatic_GuiImageMode a2 = (SDLStatic_GuiImageMode)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_GuiImage(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiInputBegin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiInputBegin(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiInputEnd(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiInputEnd(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiKeyPressed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GuiKeyPressed(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiMemoryUsed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int rv = SDLStatic_GuiMemoryUsed(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_GuiOpenFileButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_GuiOpenFileButton(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiPopFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GuiPopFont(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiPopStyleColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GuiPopStyleColor(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiProcessEvent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    const SDL_Event *a1 = (const SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Event");
    bool rv = SDLStatic_GuiProcessEvent(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiPumpEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    bool rv = SDLStatic_GuiPumpEvents(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiPushFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiFontSize a1 = (SDLStatic_GuiFontSize)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GuiPushFont(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiPushStyleColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiStyleColor a1 = (SDLStatic_GuiStyleColor)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Color a2;
    GenRead_SDL_Color(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    bool rv = SDLStatic_GuiPushStyleColor(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiRender(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    bool rv = SDLStatic_GuiRender(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiSaveFileButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    size_t len3 = 0;
    const char *a3 = SDLStaticGen_RubyToBlob(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &len3);
    bool rv = SDLStatic_GuiSaveFileButton(a0, a1, a2, (const void *)a3, (size_t)len3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiSavedPath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    const char * rv = SDLStatic_GuiSavedPath(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_GuiScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    float rv = SDLStatic_GuiScale(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_GuiSetFont(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    SDLStatic_GuiFontSize a1 = (SDLStatic_GuiFontSize)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GuiSetFont(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiSetTooltipDelay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_GuiSetTooltipDelay(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_GuiTooltip(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_GuiTooltip(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_GuiTooltipDelay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    int rv = SDLStatic_GuiTooltipDelay(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_GuiWantsInput(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Gui *a0 = (SDLStatic_Gui *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Gui");
    bool rv = SDLStatic_GuiWantsInput(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_HMACSHA256(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t len0 = 0;
    const char *a0 = SDLStaticGen_RubyToBlob(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &len0);
    size_t len2 = 0;
    const char *a2 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len2);
    Uint8 io4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_HMACSHA256((const void *)a0, (size_t)len0, (const void *)a2, (size_t)len2, &io4);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io4);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_HasDeviceMotion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool rv = SDLStatic_HasDeviceMotion(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_IdleSeconds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_IdleSeconds(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_KeyDown(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_Scancode a1 = (SDL_Scancode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_KeyDown(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_KeyModifiers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_Keymod rv = SDLStatic_KeyModifiers(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_KeyPressed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_Scancode a1 = (SDL_Scancode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_KeyPressed(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_KeyReleased(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_Scancode a1 = (SDL_Scancode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_KeyReleased(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_LastInputDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_InputDevice rv = SDLStatic_LastInputDevice(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_LightAddDarkZone(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_FRect a1;
    GenRead_SDL_FRect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    SDL_FColor a2;
    GenRead_SDL_FColor(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_LightAddDarkZone(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_LightAddOccluder(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_FRect a1;
    GenRead_SDL_FRect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    SDLStatic_LightAddOccluder(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_LightAddOccluderLine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_LightAddOccluderLine(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_LightAmbient(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_FColor rv = SDLStatic_LightAmbient(a0);
    return GenPush_SDL_FColor(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_LightAt(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float rv = SDLStatic_LightAt(a0, a1, a2);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_LightBeginFrame(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_LightBeginFrame(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_LightCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_LightCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_LightDefDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    SDLStatic_LightDefDestroy(&out0);
    return GenPush_SDLStatic_LightDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_LightDefSetColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_LightDefSetColor(&out0, a1, a2, a3, a4);
    return GenPush_SDLStatic_LightDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_LightDefSetCone(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_LightDefSetCone(&out0, a1, a2);
    return GenPush_SDLStatic_LightDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_LightDefSetFlicker(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_LightDefSetFlicker(&out0, a1);
    return GenPush_SDLStatic_LightDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_LightDefSetOffset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_LightDefSetOffset(&out0, a1, a2);
    return GenPush_SDLStatic_LightDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_LightDefSetRadius(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_LightDefSetRadius(&out0, a1);
    return GenPush_SDLStatic_LightDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_LightDefSetShadows(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightDef out0;
    memset(&out0, 0, sizeof(out0));
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_LightDefSetShadows(&out0, a1);
    return GenPush_SDLStatic_LightDef(mrb, &out0);
    }
}

static mrb_value GenR_SDLStatic_LightDefault(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightDef rv = SDLStatic_LightDefault();
    return GenPush_SDLStatic_LightDef(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_LightHour(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_LightHour(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_LightLineOfSight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDLStatic_LightLineOfSight(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_LightPreset_(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_LightPreset rv = SDLStatic_LightPreset_(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_LightRender(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_Camera tmp1;
    const SDLStatic_Camera *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_Camera(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_LightRender(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_LightSetAmbient(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_FColor a1;
    GenRead_SDL_FColor(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    SDLStatic_LightSetAmbient(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_LightSetAutoOccluders(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_LightSetAutoOccluders(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_LightSetClock(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_LightSetClock(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_LightSetPreset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_LightPreset a1 = (SDLStatic_LightPreset)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_LightSetPreset(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_LightSunlight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_LightSunlight(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_LightUsesShaders(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    bool rv = SDLStatic_LightUsesShaders(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_LoadTextFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    char * rv = SDLStatic_LoadTextFile(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDLStatic_LoadTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_TextureId rv = SDLStatic_LoadTexture(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_LoadTextureAsync(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_TextureId rv = SDLStatic_LoadTextureAsync(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_LoadTiledMap(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_TiledMap * rv = SDLStatic_LoadTiledMap(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDLStatic_TiledMap", GenDtor_SDLStatic_FreeTiledMap);
    }
}

static mrb_value GenR_SDLStatic_MotorJointDefCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2MotorJointDef * rv = SDLStatic_MotorJointDefCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "b2MotorJointDef");
    }
}

static mrb_value GenR_SDLStatic_MotorJointDefDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2MotorJointDef *a0 = (b2MotorJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2MotorJointDef");
    SDLStatic_MotorJointDefDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_MotorJointDefSetBodies(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2MotorJointDef *a0 = (b2MotorJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2MotorJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2BodyId a2;
    GenRead_b2BodyId(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_MotorJointDefSetBodies(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_MountEncryptedArchive(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t len0 = 0;
    const char *a0 = SDLStaticGen_RubyToBlob(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &len0);
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_MountEncryptedArchive((const void *)a0, (int)len0, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_MountEncryptedArchiveFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_MountEncryptedArchiveFile(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_MountMedia(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_MediaSource rv = SDLStatic_MountMedia(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_MouseCaptured(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool rv = SDLStatic_MouseCaptured(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_MouseDelta(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_MouseDelta(a0, &io1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)io1);
    rets[1] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_MouseDown(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_MouseButton a1 = (SDLStatic_MouseButton)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_MouseDown(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_MouseJointDefCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2MouseJointDef * rv = SDLStatic_MouseJointDefCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "b2MouseJointDef");
    }
}

static mrb_value GenR_SDLStatic_MouseJointDefDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2MouseJointDef *a0 = (b2MouseJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2MouseJointDef");
    SDLStatic_MouseJointDefDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_MouseJointDefSetBodies(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2MouseJointDef *a0 = (b2MouseJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2MouseJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2BodyId a2;
    GenRead_b2BodyId(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_MouseJointDefSetBodies(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_MouseJointDefSetMaxForce(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2MouseJointDef *a0 = (b2MouseJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2MouseJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_MouseJointDefSetMaxForce(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_MouseJointDefSetSpring(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2MouseJointDef *a0 = (b2MouseJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2MouseJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_MouseJointDefSetSpring(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_MousePosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_MousePosition(a0, &io1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)io1);
    rets[1] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_MousePressed(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_MouseButton a1 = (SDLStatic_MouseButton)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_MousePressed(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_MouseReleased(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_MouseButton a1 = (SDLStatic_MouseButton)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_MouseReleased(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_MouseWheel(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_MouseWheel(a0, &io1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)io1);
    rets[1] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_OpenVFSRead(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_IOStream * rv = SDLStatic_OpenVFSRead(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_IOStream");
    }
}

static mrb_value GenR_SDLStatic_PhysicsBodyCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_PhysicsBodyCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_PhysicsGravity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_PhysicsGravity(a0, &io1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_float_value(mrb, (mrb_float)io1);
    rets[1] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_PhysicsOverlap(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_FRect a1;
    GenRead_SDL_FRect(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_ActorId io3 = (SDLStatic_ActorId)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int rv = SDLStatic_PhysicsOverlap(a0, a1, a2, &io3, a4);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_PhysicsPaused(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool rv = SDLStatic_PhysicsPaused(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_PhysicsPixelsPerMetre(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_PhysicsPixelsPerMetre(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_PhysicsRaycast(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    SDLStatic_RayHit rv = SDLStatic_PhysicsRaycast(a0, a1, a2, a3, a4, a5);
    return GenPush_SDLStatic_RayHit(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_PhysicsSetGravity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_PhysicsSetGravity(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_PhysicsSetPaused(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_PhysicsSetPaused(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_PhysicsSetPixelsPerMetre(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_PhysicsSetPixelsPerMetre(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_PhysicsSetSubSteps(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_PhysicsSetSubSteps(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_PrismaticJointDefCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2PrismaticJointDef * rv = SDLStatic_PrismaticJointDefCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "b2PrismaticJointDef");
    }
}

static mrb_value GenR_SDLStatic_PrismaticJointDefDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2PrismaticJointDef");
    SDLStatic_PrismaticJointDefDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_PrismaticJointDefSetAnchors(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2PrismaticJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_PrismaticJointDefSetAnchors(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_PrismaticJointDefSetAxis(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2PrismaticJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_PrismaticJointDefSetAxis(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_PrismaticJointDefSetBodies(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2PrismaticJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2BodyId a2;
    GenRead_b2BodyId(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_PrismaticJointDefSetBodies(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_PrismaticJointDefSetLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2PrismaticJointDef");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_PrismaticJointDefSetLimit(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_PrismaticJointDefSetMotor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2PrismaticJointDef *a0 = (b2PrismaticJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2PrismaticJointDef");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_PrismaticJointDefSetMotor(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_QuitDebugText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_QuitDebugText();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_RegexEscape(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    char * rv = SDLStatic_RegexEscape(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDLStatic_RegexFlags(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char * rv = SDLStatic_RegexFlags(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_RegexGroup(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_RegexGroup(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_RegexGroupBegin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_RegexGroupBegin(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RegexGroupCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int rv = SDLStatic_RegexGroupCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RegexGroupEnd(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_RegexGroupEnd(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RegexMatchAt(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_RegexMatchAt(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_RegexNamedGroup(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_RegexNamedGroup(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RegexNamedGroupCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int rv = SDLStatic_RegexNamedGroupCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RegexNamedGroupName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_RegexNamedGroupName(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_RegexPattern(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char * rv = SDLStatic_RegexPattern(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_RegexReplace(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    const char * rv = SDLStatic_RegexReplace(a0, a1, a2, a3);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_RegexSearch(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Regex *a0 = (SDLStatic_Regex *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Regex");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_RegexSearch(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_RenderDebugText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_RenderDebugText(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_RenderLastStats(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_RenderStats rv = SDLStatic_RenderLastStats(a0);
    return GenPush_SDLStatic_RenderStats(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_RenderLighting(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    bool rv = SDLStatic_RenderLighting(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_RenderOverlay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_RenderOverlay(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RenderWorld(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_Camera tmp1;
    const SDLStatic_Camera *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDLStatic_Camera(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = SDLStatic_RenderWorld(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_RevoluteJointDefCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RevoluteJointDef * rv = SDLStatic_RevoluteJointDefCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "b2RevoluteJointDef");
    }
}

static mrb_value GenR_SDLStatic_RevoluteJointDefDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2RevoluteJointDef");
    SDLStatic_RevoluteJointDefDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_RevoluteJointDefSetAnchors(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2RevoluteJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_RevoluteJointDefSetAnchors(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_RevoluteJointDefSetBodies(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2RevoluteJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2BodyId a2;
    GenRead_b2BodyId(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_RevoluteJointDefSetBodies(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_RevoluteJointDefSetCollideConnected(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2RevoluteJointDef");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_RevoluteJointDefSetCollideConnected(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_RevoluteJointDefSetLimit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2RevoluteJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_RevoluteJointDefSetLimit(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_RevoluteJointDefSetMotor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2RevoluteJointDef");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_RevoluteJointDefSetMotor(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_RevoluteJointDefSetSpring(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2RevoluteJointDef *a0 = (b2RevoluteJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2RevoluteJointDef");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_RevoluteJointDefSetSpring(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SHA256(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t len0 = 0;
    const char *a0 = SDLStaticGen_RubyToBlob(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &len0);
    Uint8 io2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_SHA256((const void *)a0, (size_t)len0, &io2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDLStatic_SampleLight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float rv = SDLStatic_SampleLight(a0, a1, a2);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_SaveDelete(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_SaveDelete(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SaveExists(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_SaveExists(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SaveInfoOf(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SaveInfo rv = SDLStatic_SaveInfoOf(a0, a1);
    return GenPush_SDLStatic_SaveInfo(mrb, &rv);
    }
}

static mrb_value GenR_SDLStatic_SavePath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char * rv = SDLStatic_SavePath(a0, a1);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDLStatic_SaveSetIdentity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_SaveSetIdentity(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SaveWrite(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t len2 = 0;
    const char *a2 = SDLStaticGen_RubyToBlob(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &len2);
    const char *a4 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_SaveWrite(a0, a1, (const void *)a2, (size_t)len2, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SceneCurrent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_Scene * rv = SDLStatic_SceneCurrent(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_Scene");
    }
}

static mrb_value GenR_SDLStatic_SceneDepth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int rv = SDLStatic_SceneDepth(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_SceneEngine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Scene *a0 = (SDLStatic_Scene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Scene");
    SDLStatic_Engine * rv = SDLStatic_SceneEngine(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_Engine");
    }
}

static mrb_value GenR_SDLStatic_SceneFind(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_Scene * rv = SDLStatic_SceneFind(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_Scene");
    }
}

static mrb_value GenR_SDLStatic_SceneIsActive(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Scene *a0 = (SDLStatic_Scene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Scene");
    bool rv = SDLStatic_SceneIsActive(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SceneName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Scene *a0 = (SDLStatic_Scene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Scene");
    const char * rv = SDLStatic_SceneName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_ScenePop(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool rv = SDLStatic_ScenePop(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ScenePush(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const SDLStatic_SceneDef *a1 = (const SDLStatic_SceneDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_SceneDef");
    bool rv = SDLStatic_ScenePush(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SceneReplace(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const SDLStatic_SceneDef *a1 = (const SDLStatic_SceneDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_SceneDef");
    bool rv = SDLStatic_SceneReplace(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SceneReset(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const SDLStatic_SceneDef *a1 = (const SDLStatic_SceneDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_SceneDef");
    bool rv = SDLStatic_SceneReset(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SceneSetTransitionColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDL_FColor a1;
    GenRead_SDL_FColor(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    SDLStatic_SceneSetTransitionColor(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SceneTransitionTo(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const SDLStatic_SceneDef *a1 = (const SDLStatic_SceneDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDLStatic_SceneDef");
    SDLStatic_SceneTransition a2 = (SDLStatic_SceneTransition)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_SceneTransitionTo(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SceneTransitioning(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool rv = SDLStatic_SceneTransitioning(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ScriptHasHandlers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool rv = SDLStatic_ScriptHasHandlers(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ScriptRun(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool rv = SDLStatic_ScriptRun(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ScriptSetHook(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ScriptHook a1 = (SDLStatic_ScriptHook)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint64 a2 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_ScriptSetHook(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ScriptUnbind(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_ScriptUnbind(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetDebugTextSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDLStatic_SetDebugTextSize(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetDeviceMotion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_SetDeviceMotion(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SetDirectionRepeat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_SetDirectionRepeat(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetGamepadDeadzone(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SetGamepadDeadzone(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetGamepadMotion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_SetGamepadMotion(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SetLightAmbient(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    SDL_FColor a1;
    GenRead_SDL_FColor(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    SDLStatic_SetLightAmbient(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetLightDebugDraw(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SetLightDebugDraw(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetLightMapScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SetLightMapScale(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetLightRayCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SetLightRayCount(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetLightRings(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SetLightRings(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetLightShadowSoftness(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SetLightShadowSoftness(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetLightUseShaders(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_LightScene *a0 = (SDLStatic_LightScene *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_LightScene");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SetLightUseShaders(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetMouseCapture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_SetMouseCapture(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SetTextInput(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SetTextInput(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SetTriggerThreshold(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SetTriggerThreshold(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_ShowOpenFileDialog(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_ShowOpenFileDialog(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_ShowSaveFileDialog(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char *a3 = SDLStaticGen_RubyToStr(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDLStatic_ShowSaveFileDialog(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_SpriteCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Sprite * rv = SDLStatic_SpriteCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDLStatic_Sprite");
    }
}

static mrb_value GenR_SDLStatic_SpriteDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Sprite");
    SDLStatic_SpriteDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SpriteSetColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Sprite");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_SpriteSetColor(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SpriteSetLayer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Sprite");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_SpriteSetLayer(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SpriteSetOrigin(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Sprite");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_SpriteSetOrigin(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SpriteSetScreenSpace(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Sprite");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SpriteSetScreenSpace(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SpriteSetSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Sprite");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_SpriteSetSize(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SpriteSetSortByY(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Sprite");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SpriteSetSortByY(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SpriteSetSource(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Sprite");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_SpriteSetSource(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SpriteSetTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Sprite");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDLStatic_SpriteSetTexture(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_SpriteSetVisible(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Sprite *a0 = (SDLStatic_Sprite *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Sprite");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_SpriteSetVisible(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_Text(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_Text(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_TextCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_TextCount(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TextHas(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_TextHas(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_TextLanguage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char * rv = SDLStatic_TextLanguage(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_TextLoad(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDLStatic_TextLoad(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_TextLoadFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDLStatic_TextLoadFile(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_TextSetLanguage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDLStatic_TextSetLanguage(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_TextTyped(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    const char * rv = SDLStatic_TextTyped(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_Texture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    SDLStatic_TextureId a1 = (SDLStatic_TextureId)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Texture * rv = SDLStatic_Texture(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Texture");
    }
}

static mrb_value GenR_SDLStatic_TiledLayerCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledLayerCount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledLayerName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_TiledLayerName(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_TiledLayerType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDLStatic_TiledLayerType(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDLStatic_TiledMapHeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledMapHeight(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledMapWidth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledMapWidth(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledObjectAt(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_TiledObject *a3 = (SDLStatic_TiledObject *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), "SDLStatic_TiledObject");
    bool rv = SDLStatic_TiledObjectAt(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDLStatic_TiledObjectCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDLStatic_TiledObjectCount(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledRaw(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_TiledMap *a0 = (SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    cute_tiled_map_t * rv = SDLStatic_TiledRaw(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "cute_tiled_map_t");
    }
}

static mrb_value GenR_SDLStatic_TiledTileAt(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int rv = SDLStatic_TiledTileAt(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledTileHeight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledTileHeight(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TiledTileWidth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDLStatic_TiledMap *a0 = (const SDLStatic_TiledMap *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_TiledMap");
    int rv = SDLStatic_TiledTileWidth(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDLStatic_TouchPinch(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_TouchPinch(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_TouchRotation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDLStatic_Engine *a0 = (SDLStatic_Engine *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDLStatic_Engine");
    float rv = SDLStatic_TouchRotation(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDLStatic_WeldJointDefCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WeldJointDef * rv = SDLStatic_WeldJointDefCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "b2WeldJointDef");
    }
}

static mrb_value GenR_SDLStatic_WeldJointDefDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WeldJointDef *a0 = (b2WeldJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2WeldJointDef");
    SDLStatic_WeldJointDefDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_WeldJointDefSetAnchors(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WeldJointDef *a0 = (b2WeldJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2WeldJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_WeldJointDefSetAnchors(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_WeldJointDefSetBodies(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WeldJointDef *a0 = (b2WeldJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2WeldJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2BodyId a2;
    GenRead_b2BodyId(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_WeldJointDefSetBodies(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_WeldJointDefSetSpring(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WeldJointDef *a0 = (b2WeldJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2WeldJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_WeldJointDefSetSpring(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_WheelJointDefCreate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WheelJointDef * rv = SDLStatic_WheelJointDefCreate();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "b2WheelJointDef");
    }
}

static mrb_value GenR_SDLStatic_WheelJointDefDestroy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2WheelJointDef");
    SDLStatic_WheelJointDefDestroy(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_WheelJointDefSetAnchors(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2WheelJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDLStatic_WheelJointDefSetAnchors(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_WheelJointDefSetAxis(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2WheelJointDef");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDLStatic_WheelJointDefSetAxis(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_WheelJointDefSetBodies(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2WheelJointDef");
    b2BodyId a1;
    GenRead_b2BodyId(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    b2BodyId a2;
    GenRead_b2BodyId(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &a2);
    SDLStatic_WheelJointDefSetBodies(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_WheelJointDefSetMotor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2WheelJointDef");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_WheelJointDefSetMotor(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDLStatic_WheelJointDefSetSpring(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    b2WheelJointDef *a0 = (b2WheelJointDef *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "b2WheelJointDef");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDLStatic_WheelJointDefSetSpring(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

void SDLStaticGen_OpenRuby_sdlstatic(mrb_state *mrb);
void SDLStaticGen_OpenRuby_sdlstatic(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "SDLStaticC");
    mrb_define_module_function(mrb, mod, "ActionBind", GenR_SDLStatic_ActionBind, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionBindAxis", GenR_SDLStatic_ActionBindAxis, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionBindDirection", GenR_SDLStatic_ActionBindDirection, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionBindKey", GenR_SDLStatic_ActionBindKey, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionBindKeySigned", GenR_SDLStatic_ActionBindKeySigned, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionBindMouse", GenR_SDLStatic_ActionBindMouse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionBindPad", GenR_SDLStatic_ActionBindPad, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionBindingAt", GenR_SDLStatic_ActionBindingAt, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionBindingCount", GenR_SDLStatic_ActionBindingCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionCapture", GenR_SDLStatic_ActionCapture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionClear", GenR_SDLStatic_ActionClear, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionCount", GenR_SDLStatic_ActionCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionDown", GenR_SDLStatic_ActionDown, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionMapCreate", GenR_SDLStatic_ActionMapCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionMapDestroy", GenR_SDLStatic_ActionMapDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionMapKeyboardPlayer", GenR_SDLStatic_ActionMapKeyboardPlayer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionMapLoad", GenR_SDLStatic_ActionMapLoad, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionMapLoadToml", GenR_SDLStatic_ActionMapLoadToml, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionMapSave", GenR_SDLStatic_ActionMapSave, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionMapSetKeyboardPlayer", GenR_SDLStatic_ActionMapSetKeyboardPlayer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionMapToToml", GenR_SDLStatic_ActionMapToToml, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionName", GenR_SDLStatic_ActionName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionPressed", GenR_SDLStatic_ActionPressed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionReleased", GenR_SDLStatic_ActionReleased, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionValue", GenR_SDLStatic_ActionValue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActionVector", GenR_SDLStatic_ActionVector, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorAddBody", GenR_SDLStatic_ActorAddBody, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorAddLight", GenR_SDLStatic_ActorAddLight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorAlive", GenR_SDLStatic_ActorAlive, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorAngularVelocity", GenR_SDLStatic_ActorAngularVelocity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorApplyForce", GenR_SDLStatic_ActorApplyForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorApplyImpulse", GenR_SDLStatic_ActorApplyImpulse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorBodyBounds", GenR_SDLStatic_ActorBodyBounds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorBroadcast", GenR_SDLStatic_ActorBroadcast, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorChild", GenR_SDLStatic_ActorChild, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorChildCount", GenR_SDLStatic_ActorChildCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorClear", GenR_SDLStatic_ActorClear, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorClearSprite", GenR_SDLStatic_ActorClearSprite, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorCount", GenR_SDLStatic_ActorCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorDefCreate", GenR_SDLStatic_ActorDefCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorDefDestroy", GenR_SDLStatic_ActorDefDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorDefSetName", GenR_SDLStatic_ActorDefSetName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorDefSetParent", GenR_SDLStatic_ActorDefSetParent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorDefSetPosition", GenR_SDLStatic_ActorDefSetPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorDefSetRotation", GenR_SDLStatic_ActorDefSetRotation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorDefSetScale", GenR_SDLStatic_ActorDefSetScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorDefSetStateSize", GenR_SDLStatic_ActorDefSetStateSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorDefSetTags", GenR_SDLStatic_ActorDefSetTags, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorDefSetType", GenR_SDLStatic_ActorDefSetType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorDestroy", GenR_SDLStatic_ActorDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorEnabled", GenR_SDLStatic_ActorEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorEngine", GenR_SDLStatic_ActorEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorFindByName", GenR_SDLStatic_ActorFindByName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorFindByType", GenR_SDLStatic_ActorFindByType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorGet", GenR_SDLStatic_ActorGet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorGetId", GenR_SDLStatic_ActorGetId, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorGetTags", GenR_SDLStatic_ActorGetTags, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorHasBody", GenR_SDLStatic_ActorHasBody, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorHasTags", GenR_SDLStatic_ActorHasTags, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorLocal", GenR_SDLStatic_ActorLocal, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorMove", GenR_SDLStatic_ActorMove, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorName", GenR_SDLStatic_ActorName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorParent", GenR_SDLStatic_ActorParent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorQuery", GenR_SDLStatic_ActorQuery, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorRemoveBody", GenR_SDLStatic_ActorRemoveBody, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorRemoveLight", GenR_SDLStatic_ActorRemoveLight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorRenderTransform", GenR_SDLStatic_ActorRenderTransform, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorSend", GenR_SDLStatic_ActorSend, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorSetAngularVelocity", GenR_SDLStatic_ActorSetAngularVelocity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorSetEnabled", GenR_SDLStatic_ActorSetEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorSetLocal", GenR_SDLStatic_ActorSetLocal, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorSetParent", GenR_SDLStatic_ActorSetParent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorSetPosition", GenR_SDLStatic_ActorSetPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorSetSprite", GenR_SDLStatic_ActorSetSprite, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorSetTags", GenR_SDLStatic_ActorSetTags, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorSetVelocity", GenR_SDLStatic_ActorSetVelocity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorSpawn", GenR_SDLStatic_ActorSpawn, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorSprite", GenR_SDLStatic_ActorSprite, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorTeleport", GenR_SDLStatic_ActorTeleport, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorTeleportBody", GenR_SDLStatic_ActorTeleportBody, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorType", GenR_SDLStatic_ActorType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorVelocity", GenR_SDLStatic_ActorVelocity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorWakeBody", GenR_SDLStatic_ActorWakeBody, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ActorWorld", GenR_SDLStatic_ActorWorld, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddDarkZone", GenR_SDLStatic_AddDarkZone, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddLight", GenR_SDLStatic_AddLight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddOccluderRect", GenR_SDLStatic_AddOccluderRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddOccluderSegment", GenR_SDLStatic_AddOccluderSegment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AnyInput", GenR_SDLStatic_AnyInput, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetPath", GenR_SDLStatic_AssetPath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetRelease", GenR_SDLStatic_AssetRelease, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetRetain", GenR_SDLStatic_AssetRetain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetStatusOf", GenR_SDLStatic_AssetStatusOf, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetsFrameBudget", GenR_SDLStatic_AssetsFrameBudget, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetsLoaded", GenR_SDLStatic_AssetsLoaded, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetsPending", GenR_SDLStatic_AssetsPending, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetsProgress", GenR_SDLStatic_AssetsProgress, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetsReady", GenR_SDLStatic_AssetsReady, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetsSetFrameBudget", GenR_SDLStatic_AssetsSetFrameBudget, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetsSetWorkers", GenR_SDLStatic_AssetsSetWorkers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AssetsWait", GenR_SDLStatic_AssetsWait, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BidiBaseIsRTL", GenR_SDLStatic_BidiBaseIsRTL, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BindingFromString", GenR_SDLStatic_BindingFromString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BindingToString", GenR_SDLStatic_BindingToString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefDestroy", GenR_SDLStatic_BodyDefDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefSetBullet", GenR_SDLStatic_BodyDefSetBullet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefSetFilter", GenR_SDLStatic_BodyDefSetFilter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefSetFixedRotation", GenR_SDLStatic_BodyDefSetFixedRotation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefSetGravityScale", GenR_SDLStatic_BodyDefSetGravityScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefSetMaterial", GenR_SDLStatic_BodyDefSetMaterial, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefSetOffset", GenR_SDLStatic_BodyDefSetOffset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefSetSensor", GenR_SDLStatic_BodyDefSetSensor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefSetShape", GenR_SDLStatic_BodyDefSetShape, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefSetSize", GenR_SDLStatic_BodyDefSetSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefSetType", GenR_SDLStatic_BodyDefSetType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BodyDefault", GenR_SDLStatic_BodyDefault, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraBegin", GenR_SDLStatic_CameraBegin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraDestroy", GenR_SDLStatic_CameraDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraEnd", GenR_SDLStatic_CameraEnd, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraFollow", GenR_SDLStatic_CameraFollow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraInit", GenR_SDLStatic_CameraInit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraPoint", GenR_SDLStatic_CameraPoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraRect", GenR_SDLStatic_CameraRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraScreenToWorld", GenR_SDLStatic_CameraScreenToWorld, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraSetBounds", GenR_SDLStatic_CameraSetBounds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraSetDeadzone", GenR_SDLStatic_CameraSetDeadzone, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraSetSmoothing", GenR_SDLStatic_CameraSetSmoothing, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraSetViewport", GenR_SDLStatic_CameraSetViewport, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraSetZoom", GenR_SDLStatic_CameraSetZoom, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraShake", GenR_SDLStatic_CameraShake, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraSnap", GenR_SDLStatic_CameraSnap, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraSplit", GenR_SDLStatic_CameraSplit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraUpdate", GenR_SDLStatic_CameraUpdate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraVisible", GenR_SDLStatic_CameraVisible, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraX", GenR_SDLStatic_CameraX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CameraY", GenR_SDLStatic_CameraY, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CompileRegex", GenR_SDLStatic_CompileRegex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigCreate", GenR_SDLStatic_ConfigCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigDestroy", GenR_SDLStatic_ConfigDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetAutoMount", GenR_SDLStatic_ConfigSetAutoMount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetBackend", GenR_SDLStatic_ConfigSetBackend, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetDesignSize", GenR_SDLStatic_ConfigSetDesignSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetFullscreen", GenR_SDLStatic_ConfigSetFullscreen, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetGraphics", GenR_SDLStatic_ConfigSetGraphics, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetHeadless", GenR_SDLStatic_ConfigSetHeadless, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetHighDpi", GenR_SDLStatic_ConfigSetHighDpi, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetManualClock", GenR_SDLStatic_ConfigSetManualClock, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetMaxFps", GenR_SDLStatic_ConfigSetMaxFps, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetMediaPath", GenR_SDLStatic_ConfigSetMediaPath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetPresentation", GenR_SDLStatic_ConfigSetPresentation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetResizable", GenR_SDLStatic_ConfigSetResizable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetTickRate", GenR_SDLStatic_ConfigSetTickRate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetTitle", GenR_SDLStatic_ConfigSetTitle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetVsync", GenR_SDLStatic_ConfigSetVsync, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConfigSetWindowSize", GenR_SDLStatic_ConfigSetWindowSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CountSignalConnections", GenR_SDLStatic_CountSignalConnections, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateChipSFX", GenR_SDLStatic_CreateChipSFX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateChipTone", GenR_SDLStatic_CreateChipTone, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateChipTune", GenR_SDLStatic_CreateChipTune, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateEngine", GenR_SDLStatic_CreateEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGui", GenR_SDLStatic_CreateGui, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGuiWithGlyphs", GenR_SDLStatic_CreateGuiWithGlyphs, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateLightScene", GenR_SDLStatic_CreateLightScene, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateSignalEmitter", GenR_SDLStatic_CreateSignalEmitter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CryptoSelfTest", GenR_SDLStatic_CryptoSelfTest, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DayNightAmbient", GenR_SDLStatic_DayNightAmbient, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DayNightSunlight", GenR_SDLStatic_DayNightSunlight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyEngine", GenR_SDLStatic_DestroyEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyGui", GenR_SDLStatic_DestroyGui, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyLightScene", GenR_SDLStatic_DestroyLightScene, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyRegex", GenR_SDLStatic_DestroyRegex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroySignalEmitter", GenR_SDLStatic_DestroySignalEmitter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DeviceAccelerometer", GenR_SDLStatic_DeviceAccelerometer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DeviceGyro", GenR_SDLStatic_DeviceGyro, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DialogDeliverSave", GenR_SDLStatic_DialogDeliverSave, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DialogPath", GenR_SDLStatic_DialogPath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DialogReset", GenR_SDLStatic_DialogReset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DialogStatus", GenR_SDLStatic_DialogStatus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DisconnectSignal", GenR_SDLStatic_DisconnectSignal, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJointDefCreate", GenR_SDLStatic_DistanceJointDefCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJointDefDestroy", GenR_SDLStatic_DistanceJointDefDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJointDefSetAnchors", GenR_SDLStatic_DistanceJointDefSetAnchors, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJointDefSetBodies", GenR_SDLStatic_DistanceJointDefSetBodies, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJointDefSetCollideConnected", GenR_SDLStatic_DistanceJointDefSetCollideConnected, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJointDefSetLength", GenR_SDLStatic_DistanceJointDefSetLength, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJointDefSetLimit", GenR_SDLStatic_DistanceJointDefSetLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DistanceJointDefSetSpring", GenR_SDLStatic_DistanceJointDefSetSpring, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DrawPhysicsWorld", GenR_SDLStatic_DrawPhysicsWorld, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EncodeDataBase64", GenR_SDLStatic_EncodeDataBase64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineAdvance", GenR_SDLStatic_EngineAdvance, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineAlpha", GenR_SDLStatic_EngineAlpha, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineAssetScale", GenR_SDLStatic_EngineAssetScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineDelta", GenR_SDLStatic_EngineDelta, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineDesignSize", GenR_SDLStatic_EngineDesignSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineDisplay", GenR_SDLStatic_EngineDisplay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineDisplayCount", GenR_SDLStatic_EngineDisplayCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineDisplayName", GenR_SDLStatic_EngineDisplayName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineEffectsAvailable", GenR_SDLStatic_EngineEffectsAvailable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineEmbedMedia", GenR_SDLStatic_EngineEmbedMedia, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineFps", GenR_SDLStatic_EngineFps, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineFrameCount", GenR_SDLStatic_EngineFrameCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineMaxFps", GenR_SDLStatic_EngineMaxFps, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineMediaPath", GenR_SDLStatic_EngineMediaPath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineMediaSource", GenR_SDLStatic_EngineMediaSource, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineOverloadFrames", GenR_SDLStatic_EngineOverloadFrames, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EnginePixelSize", GenR_SDLStatic_EnginePixelSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EnginePresentation_", GenR_SDLStatic_EnginePresentation_, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineQuit", GenR_SDLStatic_EngineQuit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineRenderScale", GenR_SDLStatic_EngineRenderScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineRenderer", GenR_SDLStatic_EngineRenderer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineSafeRect", GenR_SDLStatic_EngineSafeRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineSetClearColor", GenR_SDLStatic_EngineSetClearColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineSetDisplay", GenR_SDLStatic_EngineSetDisplay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineSetGraphics", GenR_SDLStatic_EngineSetGraphics, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineSetMaxFps", GenR_SDLStatic_EngineSetMaxFps, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineSetMediaPassword", GenR_SDLStatic_EngineSetMediaPassword, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineSetPresentation", GenR_SDLStatic_EngineSetPresentation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineSetRefreshRate", GenR_SDLStatic_EngineSetRefreshRate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineSetTickRate", GenR_SDLStatic_EngineSetTickRate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineSetTimeScale", GenR_SDLStatic_EngineSetTimeScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineStep", GenR_SDLStatic_EngineStep, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineStepsLastFrame", GenR_SDLStatic_EngineStepsLastFrame, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineTick", GenR_SDLStatic_EngineTick, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineTickRate", GenR_SDLStatic_EngineTickRate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineTimeScale", GenR_SDLStatic_EngineTimeScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineViewRect", GenR_SDLStatic_EngineViewRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineWindow", GenR_SDLStatic_EngineWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EngineWindowToDesign", GenR_SDLStatic_EngineWindowToDesign, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventCreate", GenR_SDLStatic_EventCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventDestroy", GenR_SDLStatic_EventDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventGamepadAxis", GenR_SDLStatic_EventGamepadAxis, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventGamepadAxisValue", GenR_SDLStatic_EventGamepadAxisValue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventGamepadButton", GenR_SDLStatic_EventGamepadButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventGamepadWhich", GenR_SDLStatic_EventGamepadWhich, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventKeyModifiers", GenR_SDLStatic_EventKeyModifiers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventKeyRepeat", GenR_SDLStatic_EventKeyRepeat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventKeyScancode", GenR_SDLStatic_EventKeyScancode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventMouseButton", GenR_SDLStatic_EventMouseButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventMouseDeltaX", GenR_SDLStatic_EventMouseDeltaX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventMouseDeltaY", GenR_SDLStatic_EventMouseDeltaY, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventMouseX", GenR_SDLStatic_EventMouseX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventMouseY", GenR_SDLStatic_EventMouseY, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventSetType", GenR_SDLStatic_EventSetType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventText", GenR_SDLStatic_EventText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventTouchX", GenR_SDLStatic_EventTouchX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventTouchY", GenR_SDLStatic_EventTouchY, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventType", GenR_SDLStatic_EventType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventWheelX", GenR_SDLStatic_EventWheelX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventWheelY", GenR_SDLStatic_EventWheelY, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventWindowId", GenR_SDLStatic_EventWindowId, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FilterJointDefCreate", GenR_SDLStatic_FilterJointDefCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FilterJointDefDestroy", GenR_SDLStatic_FilterJointDefDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FilterJointDefSetBodies", GenR_SDLStatic_FilterJointDefSetBodies, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FingerCount", GenR_SDLStatic_FingerCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FreeTiledMap", GenR_SDLStatic_FreeTiledMap, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUAcquireSwapchain", GenR_SDLStatic_GPUAcquireSwapchain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBeginComputePass", GenR_SDLStatic_GPUBeginComputePass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBindComputeStorageBuffer", GenR_SDLStatic_GPUBindComputeStorageBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBindComputeStorageTexture", GenR_SDLStatic_GPUBindComputeStorageTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBindFragmentStorageBuffer", GenR_SDLStatic_GPUBindFragmentStorageBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBindFragmentStorageTexture", GenR_SDLStatic_GPUBindFragmentStorageTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBindVertexStorageBuffer", GenR_SDLStatic_GPUBindVertexStorageBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBindVertexStorageTexture", GenR_SDLStatic_GPUBindVertexStorageTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBlitInfoCreate", GenR_SDLStatic_GPUBlitInfoCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBlitInfoDestroy", GenR_SDLStatic_GPUBlitInfoDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBlitInfoSetDestination", GenR_SDLStatic_GPUBlitInfoSetDestination, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBlitInfoSetFilter", GenR_SDLStatic_GPUBlitInfoSetFilter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBlitInfoSetSource", GenR_SDLStatic_GPUBlitInfoSetSource, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBufferBindingCreate", GenR_SDLStatic_GPUBufferBindingCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBufferBindingDestroy", GenR_SDLStatic_GPUBufferBindingDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBufferBindingSet", GenR_SDLStatic_GPUBufferBindingSet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBufferLocationCreate", GenR_SDLStatic_GPUBufferLocationCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBufferLocationDestroy", GenR_SDLStatic_GPUBufferLocationDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBufferLocationSet", GenR_SDLStatic_GPUBufferLocationSet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBufferRegionCreate", GenR_SDLStatic_GPUBufferRegionCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBufferRegionDestroy", GenR_SDLStatic_GPUBufferRegionDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUBufferRegionSet", GenR_SDLStatic_GPUBufferRegionSet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUColorTargetInfoCreate", GenR_SDLStatic_GPUColorTargetInfoCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUColorTargetInfoDestroy", GenR_SDLStatic_GPUColorTargetInfoDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUColorTargetInfoSetClearColor", GenR_SDLStatic_GPUColorTargetInfoSetClearColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUColorTargetInfoSetCycle", GenR_SDLStatic_GPUColorTargetInfoSetCycle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUColorTargetInfoSetMipLayer", GenR_SDLStatic_GPUColorTargetInfoSetMipLayer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUColorTargetInfoSetOps", GenR_SDLStatic_GPUColorTargetInfoSetOps, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUColorTargetInfoSetTexture", GenR_SDLStatic_GPUColorTargetInfoSetTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUComputeBindingsAddBuffer", GenR_SDLStatic_GPUComputeBindingsAddBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUComputeBindingsAddTexture", GenR_SDLStatic_GPUComputeBindingsAddTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUComputeBindingsCreate", GenR_SDLStatic_GPUComputeBindingsCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUComputeBindingsDestroy", GenR_SDLStatic_GPUComputeBindingsDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUComputePipelineInfoCreate", GenR_SDLStatic_GPUComputePipelineInfoCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUComputePipelineInfoDestroy", GenR_SDLStatic_GPUComputePipelineInfoDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUComputePipelineInfoSetCode", GenR_SDLStatic_GPUComputePipelineInfoSetCode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUComputePipelineInfoSetEntrypoint", GenR_SDLStatic_GPUComputePipelineInfoSetEntrypoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUComputePipelineInfoSetFormat", GenR_SDLStatic_GPUComputePipelineInfoSetFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUComputePipelineInfoSetThreadCount", GenR_SDLStatic_GPUComputePipelineInfoSetThreadCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUDepthStencilTargetInfoCreate", GenR_SDLStatic_GPUDepthStencilTargetInfoCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUDepthStencilTargetInfoDestroy", GenR_SDLStatic_GPUDepthStencilTargetInfoDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUDepthStencilTargetInfoSetClear", GenR_SDLStatic_GPUDepthStencilTargetInfoSetClear, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUDepthStencilTargetInfoSetOps", GenR_SDLStatic_GPUDepthStencilTargetInfoSetOps, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUDepthStencilTargetInfoSetTexture", GenR_SDLStatic_GPUDepthStencilTargetInfoSetTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUPipelineInfoAddColorTarget", GenR_SDLStatic_GPUPipelineInfoAddColorTarget, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUPipelineInfoAddVertexAttribute", GenR_SDLStatic_GPUPipelineInfoAddVertexAttribute, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUPipelineInfoAddVertexBuffer", GenR_SDLStatic_GPUPipelineInfoAddVertexBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUPipelineInfoCreate", GenR_SDLStatic_GPUPipelineInfoCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUPipelineInfoDestroy", GenR_SDLStatic_GPUPipelineInfoDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUPipelineInfoSetDepthStencil", GenR_SDLStatic_GPUPipelineInfoSetDepthStencil, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUPipelineInfoSetFillMode", GenR_SDLStatic_GPUPipelineInfoSetFillMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUPipelineInfoSetPrimitive", GenR_SDLStatic_GPUPipelineInfoSetPrimitive, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUPipelineInfoSetShaders", GenR_SDLStatic_GPUPipelineInfoSetShaders, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPURenderStateInfoAddSampler", GenR_SDLStatic_GPURenderStateInfoAddSampler, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPURenderStateInfoCreate", GenR_SDLStatic_GPURenderStateInfoCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPURenderStateInfoDestroy", GenR_SDLStatic_GPURenderStateInfoDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPURenderStateInfoSetShader", GenR_SDLStatic_GPURenderStateInfoSetShader, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUShaderCreateInfoCreate", GenR_SDLStatic_GPUShaderCreateInfoCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUShaderCreateInfoDestroy", GenR_SDLStatic_GPUShaderCreateInfoDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUShaderCreateInfoSetCode", GenR_SDLStatic_GPUShaderCreateInfoSetCode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUShaderCreateInfoSetCounts", GenR_SDLStatic_GPUShaderCreateInfoSetCounts, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUShaderCreateInfoSetEntrypoint", GenR_SDLStatic_GPUShaderCreateInfoSetEntrypoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUShaderCreateInfoSetFormat", GenR_SDLStatic_GPUShaderCreateInfoSetFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUSwapchainHeight", GenR_SDLStatic_GPUSwapchainHeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUSwapchainWidth", GenR_SDLStatic_GPUSwapchainWidth, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureLocationCreate", GenR_SDLStatic_GPUTextureLocationCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureLocationDestroy", GenR_SDLStatic_GPUTextureLocationDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureLocationSet", GenR_SDLStatic_GPUTextureLocationSet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureRegionCreate", GenR_SDLStatic_GPUTextureRegionCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureRegionDestroy", GenR_SDLStatic_GPUTextureRegionDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureRegionSet", GenR_SDLStatic_GPUTextureRegionSet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureSamplerBindingCreate", GenR_SDLStatic_GPUTextureSamplerBindingCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureSamplerBindingDestroy", GenR_SDLStatic_GPUTextureSamplerBindingDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureSamplerBindingSet", GenR_SDLStatic_GPUTextureSamplerBindingSet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureTransferInfoCreate", GenR_SDLStatic_GPUTextureTransferInfoCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureTransferInfoDestroy", GenR_SDLStatic_GPUTextureTransferInfoDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureTransferInfoSet", GenR_SDLStatic_GPUTextureTransferInfoSet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTransferBufferLocationCreate", GenR_SDLStatic_GPUTransferBufferLocationCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTransferBufferLocationDestroy", GenR_SDLStatic_GPUTransferBufferLocationDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTransferBufferLocationSet", GenR_SDLStatic_GPUTransferBufferLocationSet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUUploadToTransferBuffer", GenR_SDLStatic_GPUUploadToTransferBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUWaitAndAcquireSwapchain", GenR_SDLStatic_GPUWaitAndAcquireSwapchain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUWaitForFence", GenR_SDLStatic_GPUWaitForFence, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadAccelerometer", GenR_SDLStatic_GamepadAccelerometer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadAxisValue", GenR_SDLStatic_GamepadAxisValue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadButtonDown", GenR_SDLStatic_GamepadButtonDown, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadButtonPressed", GenR_SDLStatic_GamepadButtonPressed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadButtonReleased", GenR_SDLStatic_GamepadButtonReleased, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadConnected", GenR_SDLStatic_GamepadConnected, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadCount", GenR_SDLStatic_GamepadCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadDeadzone", GenR_SDLStatic_GamepadDeadzone, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadDirectionPressed", GenR_SDLStatic_GamepadDirectionPressed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadDirectionRepeat", GenR_SDLStatic_GamepadDirectionRepeat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadGyro", GenR_SDLStatic_GamepadGyro, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadHasAccelerometer", GenR_SDLStatic_GamepadHasAccelerometer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadHasGyro", GenR_SDLStatic_GamepadHasGyro, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadName", GenR_SDLStatic_GamepadName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadRumble", GenR_SDLStatic_GamepadRumble, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadRumbleTriggers", GenR_SDLStatic_GamepadRumbleTriggers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadSetLED", GenR_SDLStatic_GamepadSetLED, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadStick", GenR_SDLStatic_GamepadStick, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadStopRumble", GenR_SDLStatic_GamepadStopRumble, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsClamp", GenR_SDLStatic_GraphicsClamp, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsConfigError", GenR_SDLStatic_GraphicsConfigError, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsConfigPath", GenR_SDLStatic_GraphicsConfigPath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsDefaults", GenR_SDLStatic_GraphicsDefaults, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsEqual", GenR_SDLStatic_GraphicsEqual, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsLightMapScale", GenR_SDLStatic_GraphicsLightMapScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsLoadTomlFile", GenR_SDLStatic_GraphicsLoadTomlFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsLoadTomlString", GenR_SDLStatic_GraphicsLoadTomlString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsMaxDynamicLights", GenR_SDLStatic_GraphicsMaxDynamicLights, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsParticleDensity", GenR_SDLStatic_GraphicsParticleDensity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsQualityFromName", GenR_SDLStatic_GraphicsQualityFromName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsQualityName", GenR_SDLStatic_GraphicsQualityName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsSafeMode", GenR_SDLStatic_GraphicsSafeMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsSave", GenR_SDLStatic_GraphicsSave, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsSavePath", GenR_SDLStatic_GraphicsSavePath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsShadowRays", GenR_SDLStatic_GraphicsShadowRays, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsShadowSoftness", GenR_SDLStatic_GraphicsShadowSoftness, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GraphicsToToml", GenR_SDLStatic_GraphicsToToml, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiContext", GenR_SDLStatic_GuiContext, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiDrawCommandCount", GenR_SDLStatic_GuiDrawCommandCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiDrawTexture", GenR_SDLStatic_GuiDrawTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiDrawTextureOverlay", GenR_SDLStatic_GuiDrawTextureOverlay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiFontHeight", GenR_SDLStatic_GuiFontHeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridBeginOwned", GenR_SDLStatic_GuiGridBeginOwned, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridCell", GenR_SDLStatic_GuiGridCell, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridCellOwned", GenR_SDLStatic_GuiGridCellOwned, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridCellSpan", GenR_SDLStatic_GuiGridCellSpan, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridCellSpanOwned", GenR_SDLStatic_GuiGridCellSpanOwned, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridCreate", GenR_SDLStatic_GuiGridCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridDestroy", GenR_SDLStatic_GuiGridDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridEnd", GenR_SDLStatic_GuiGridEnd, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridEndOwned", GenR_SDLStatic_GuiGridEndOwned, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridNextRow", GenR_SDLStatic_GuiGridNextRow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridNextRowOwned", GenR_SDLStatic_GuiGridNextRowOwned, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiGridWeight", GenR_SDLStatic_GuiGridWeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiImage", GenR_SDLStatic_GuiImage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiInputBegin", GenR_SDLStatic_GuiInputBegin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiInputEnd", GenR_SDLStatic_GuiInputEnd, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiKeyPressed", GenR_SDLStatic_GuiKeyPressed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiMemoryUsed", GenR_SDLStatic_GuiMemoryUsed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiOpenFileButton", GenR_SDLStatic_GuiOpenFileButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiPopFont", GenR_SDLStatic_GuiPopFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiPopStyleColor", GenR_SDLStatic_GuiPopStyleColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiProcessEvent", GenR_SDLStatic_GuiProcessEvent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiPumpEvents", GenR_SDLStatic_GuiPumpEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiPushFont", GenR_SDLStatic_GuiPushFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiPushStyleColor", GenR_SDLStatic_GuiPushStyleColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiRender", GenR_SDLStatic_GuiRender, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiSaveFileButton", GenR_SDLStatic_GuiSaveFileButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiSavedPath", GenR_SDLStatic_GuiSavedPath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiScale", GenR_SDLStatic_GuiScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiSetFont", GenR_SDLStatic_GuiSetFont, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiSetTooltipDelay", GenR_SDLStatic_GuiSetTooltipDelay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiTooltip", GenR_SDLStatic_GuiTooltip, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiTooltipDelay", GenR_SDLStatic_GuiTooltipDelay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GuiWantsInput", GenR_SDLStatic_GuiWantsInput, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HMACSHA256", GenR_SDLStatic_HMACSHA256, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasDeviceMotion", GenR_SDLStatic_HasDeviceMotion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IdleSeconds", GenR_SDLStatic_IdleSeconds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "KeyDown", GenR_SDLStatic_KeyDown, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "KeyModifiers", GenR_SDLStatic_KeyModifiers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "KeyPressed", GenR_SDLStatic_KeyPressed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "KeyReleased", GenR_SDLStatic_KeyReleased, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LastInputDevice", GenR_SDLStatic_LastInputDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightAddDarkZone", GenR_SDLStatic_LightAddDarkZone, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightAddOccluder", GenR_SDLStatic_LightAddOccluder, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightAddOccluderLine", GenR_SDLStatic_LightAddOccluderLine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightAmbient", GenR_SDLStatic_LightAmbient, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightAt", GenR_SDLStatic_LightAt, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightBeginFrame", GenR_SDLStatic_LightBeginFrame, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightCount", GenR_SDLStatic_LightCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightDefDestroy", GenR_SDLStatic_LightDefDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightDefSetColor", GenR_SDLStatic_LightDefSetColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightDefSetCone", GenR_SDLStatic_LightDefSetCone, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightDefSetFlicker", GenR_SDLStatic_LightDefSetFlicker, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightDefSetOffset", GenR_SDLStatic_LightDefSetOffset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightDefSetRadius", GenR_SDLStatic_LightDefSetRadius, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightDefSetShadows", GenR_SDLStatic_LightDefSetShadows, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightDefault", GenR_SDLStatic_LightDefault, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightHour", GenR_SDLStatic_LightHour, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightLineOfSight", GenR_SDLStatic_LightLineOfSight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightPreset_", GenR_SDLStatic_LightPreset_, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightRender", GenR_SDLStatic_LightRender, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightSetAmbient", GenR_SDLStatic_LightSetAmbient, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightSetAutoOccluders", GenR_SDLStatic_LightSetAutoOccluders, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightSetClock", GenR_SDLStatic_LightSetClock, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightSetPreset", GenR_SDLStatic_LightSetPreset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightSunlight", GenR_SDLStatic_LightSunlight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LightUsesShaders", GenR_SDLStatic_LightUsesShaders, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTextFile", GenR_SDLStatic_LoadTextFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTexture", GenR_SDLStatic_LoadTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTextureAsync", GenR_SDLStatic_LoadTextureAsync, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadTiledMap", GenR_SDLStatic_LoadTiledMap, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJointDefCreate", GenR_SDLStatic_MotorJointDefCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJointDefDestroy", GenR_SDLStatic_MotorJointDefDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MotorJointDefSetBodies", GenR_SDLStatic_MotorJointDefSetBodies, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MountEncryptedArchive", GenR_SDLStatic_MountEncryptedArchive, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MountEncryptedArchiveFile", GenR_SDLStatic_MountEncryptedArchiveFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MountMedia", GenR_SDLStatic_MountMedia, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseCaptured", GenR_SDLStatic_MouseCaptured, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseDelta", GenR_SDLStatic_MouseDelta, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseDown", GenR_SDLStatic_MouseDown, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJointDefCreate", GenR_SDLStatic_MouseJointDefCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJointDefDestroy", GenR_SDLStatic_MouseJointDefDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJointDefSetBodies", GenR_SDLStatic_MouseJointDefSetBodies, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJointDefSetMaxForce", GenR_SDLStatic_MouseJointDefSetMaxForce, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseJointDefSetSpring", GenR_SDLStatic_MouseJointDefSetSpring, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MousePosition", GenR_SDLStatic_MousePosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MousePressed", GenR_SDLStatic_MousePressed, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseReleased", GenR_SDLStatic_MouseReleased, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MouseWheel", GenR_SDLStatic_MouseWheel, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenVFSRead", GenR_SDLStatic_OpenVFSRead, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PhysicsBodyCount", GenR_SDLStatic_PhysicsBodyCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PhysicsGravity", GenR_SDLStatic_PhysicsGravity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PhysicsOverlap", GenR_SDLStatic_PhysicsOverlap, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PhysicsPaused", GenR_SDLStatic_PhysicsPaused, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PhysicsPixelsPerMetre", GenR_SDLStatic_PhysicsPixelsPerMetre, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PhysicsRaycast", GenR_SDLStatic_PhysicsRaycast, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PhysicsSetGravity", GenR_SDLStatic_PhysicsSetGravity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PhysicsSetPaused", GenR_SDLStatic_PhysicsSetPaused, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PhysicsSetPixelsPerMetre", GenR_SDLStatic_PhysicsSetPixelsPerMetre, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PhysicsSetSubSteps", GenR_SDLStatic_PhysicsSetSubSteps, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJointDefCreate", GenR_SDLStatic_PrismaticJointDefCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJointDefDestroy", GenR_SDLStatic_PrismaticJointDefDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJointDefSetAnchors", GenR_SDLStatic_PrismaticJointDefSetAnchors, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJointDefSetAxis", GenR_SDLStatic_PrismaticJointDefSetAxis, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJointDefSetBodies", GenR_SDLStatic_PrismaticJointDefSetBodies, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJointDefSetLimit", GenR_SDLStatic_PrismaticJointDefSetLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PrismaticJointDefSetMotor", GenR_SDLStatic_PrismaticJointDefSetMotor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "QuitDebugText", GenR_SDLStatic_QuitDebugText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexEscape", GenR_SDLStatic_RegexEscape, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexFlags", GenR_SDLStatic_RegexFlags, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexGroup", GenR_SDLStatic_RegexGroup, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexGroupBegin", GenR_SDLStatic_RegexGroupBegin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexGroupCount", GenR_SDLStatic_RegexGroupCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexGroupEnd", GenR_SDLStatic_RegexGroupEnd, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexMatchAt", GenR_SDLStatic_RegexMatchAt, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexNamedGroup", GenR_SDLStatic_RegexNamedGroup, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexNamedGroupCount", GenR_SDLStatic_RegexNamedGroupCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexNamedGroupName", GenR_SDLStatic_RegexNamedGroupName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexPattern", GenR_SDLStatic_RegexPattern, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexReplace", GenR_SDLStatic_RegexReplace, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegexSearch", GenR_SDLStatic_RegexSearch, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderDebugText", GenR_SDLStatic_RenderDebugText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderLastStats", GenR_SDLStatic_RenderLastStats, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderLighting", GenR_SDLStatic_RenderLighting, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderOverlay", GenR_SDLStatic_RenderOverlay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderWorld", GenR_SDLStatic_RenderWorld, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJointDefCreate", GenR_SDLStatic_RevoluteJointDefCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJointDefDestroy", GenR_SDLStatic_RevoluteJointDefDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJointDefSetAnchors", GenR_SDLStatic_RevoluteJointDefSetAnchors, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJointDefSetBodies", GenR_SDLStatic_RevoluteJointDefSetBodies, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJointDefSetCollideConnected", GenR_SDLStatic_RevoluteJointDefSetCollideConnected, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJointDefSetLimit", GenR_SDLStatic_RevoluteJointDefSetLimit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJointDefSetMotor", GenR_SDLStatic_RevoluteJointDefSetMotor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RevoluteJointDefSetSpring", GenR_SDLStatic_RevoluteJointDefSetSpring, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SHA256", GenR_SDLStatic_SHA256, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SampleLight", GenR_SDLStatic_SampleLight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveDelete", GenR_SDLStatic_SaveDelete, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveExists", GenR_SDLStatic_SaveExists, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveInfoOf", GenR_SDLStatic_SaveInfoOf, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SavePath", GenR_SDLStatic_SavePath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveSetIdentity", GenR_SDLStatic_SaveSetIdentity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveWrite", GenR_SDLStatic_SaveWrite, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SceneCurrent", GenR_SDLStatic_SceneCurrent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SceneDepth", GenR_SDLStatic_SceneDepth, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SceneEngine", GenR_SDLStatic_SceneEngine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SceneFind", GenR_SDLStatic_SceneFind, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SceneIsActive", GenR_SDLStatic_SceneIsActive, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SceneName", GenR_SDLStatic_SceneName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ScenePop", GenR_SDLStatic_ScenePop, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ScenePush", GenR_SDLStatic_ScenePush, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SceneReplace", GenR_SDLStatic_SceneReplace, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SceneReset", GenR_SDLStatic_SceneReset, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SceneSetTransitionColor", GenR_SDLStatic_SceneSetTransitionColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SceneTransitionTo", GenR_SDLStatic_SceneTransitionTo, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SceneTransitioning", GenR_SDLStatic_SceneTransitioning, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ScriptHasHandlers", GenR_SDLStatic_ScriptHasHandlers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ScriptRun", GenR_SDLStatic_ScriptRun, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ScriptSetHook", GenR_SDLStatic_ScriptSetHook, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ScriptUnbind", GenR_SDLStatic_ScriptUnbind, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetDebugTextSize", GenR_SDLStatic_SetDebugTextSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetDeviceMotion", GenR_SDLStatic_SetDeviceMotion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetDirectionRepeat", GenR_SDLStatic_SetDirectionRepeat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGamepadDeadzone", GenR_SDLStatic_SetGamepadDeadzone, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGamepadMotion", GenR_SDLStatic_SetGamepadMotion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetLightAmbient", GenR_SDLStatic_SetLightAmbient, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetLightDebugDraw", GenR_SDLStatic_SetLightDebugDraw, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetLightMapScale", GenR_SDLStatic_SetLightMapScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetLightRayCount", GenR_SDLStatic_SetLightRayCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetLightRings", GenR_SDLStatic_SetLightRings, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetLightShadowSoftness", GenR_SDLStatic_SetLightShadowSoftness, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetLightUseShaders", GenR_SDLStatic_SetLightUseShaders, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetMouseCapture", GenR_SDLStatic_SetMouseCapture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextInput", GenR_SDLStatic_SetTextInput, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTriggerThreshold", GenR_SDLStatic_SetTriggerThreshold, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShowOpenFileDialog", GenR_SDLStatic_ShowOpenFileDialog, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShowSaveFileDialog", GenR_SDLStatic_ShowSaveFileDialog, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SpriteCreate", GenR_SDLStatic_SpriteCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SpriteDestroy", GenR_SDLStatic_SpriteDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SpriteSetColor", GenR_SDLStatic_SpriteSetColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SpriteSetLayer", GenR_SDLStatic_SpriteSetLayer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SpriteSetOrigin", GenR_SDLStatic_SpriteSetOrigin, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SpriteSetScreenSpace", GenR_SDLStatic_SpriteSetScreenSpace, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SpriteSetSize", GenR_SDLStatic_SpriteSetSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SpriteSetSortByY", GenR_SDLStatic_SpriteSetSortByY, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SpriteSetSource", GenR_SDLStatic_SpriteSetSource, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SpriteSetTexture", GenR_SDLStatic_SpriteSetTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SpriteSetVisible", GenR_SDLStatic_SpriteSetVisible, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Text", GenR_SDLStatic_Text, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TextCount", GenR_SDLStatic_TextCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TextHas", GenR_SDLStatic_TextHas, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TextLanguage", GenR_SDLStatic_TextLanguage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TextLoad", GenR_SDLStatic_TextLoad, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TextLoadFile", GenR_SDLStatic_TextLoadFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TextSetLanguage", GenR_SDLStatic_TextSetLanguage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TextTyped", GenR_SDLStatic_TextTyped, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Texture", GenR_SDLStatic_Texture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledLayerCount", GenR_SDLStatic_TiledLayerCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledLayerName", GenR_SDLStatic_TiledLayerName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledLayerType", GenR_SDLStatic_TiledLayerType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledMapHeight", GenR_SDLStatic_TiledMapHeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledMapWidth", GenR_SDLStatic_TiledMapWidth, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledObjectAt", GenR_SDLStatic_TiledObjectAt, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledObjectCount", GenR_SDLStatic_TiledObjectCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledRaw", GenR_SDLStatic_TiledRaw, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledTileAt", GenR_SDLStatic_TiledTileAt, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledTileHeight", GenR_SDLStatic_TiledTileHeight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TiledTileWidth", GenR_SDLStatic_TiledTileWidth, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TouchPinch", GenR_SDLStatic_TouchPinch, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TouchRotation", GenR_SDLStatic_TouchRotation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJointDefCreate", GenR_SDLStatic_WeldJointDefCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJointDefDestroy", GenR_SDLStatic_WeldJointDefDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJointDefSetAnchors", GenR_SDLStatic_WeldJointDefSetAnchors, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJointDefSetBodies", GenR_SDLStatic_WeldJointDefSetBodies, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WeldJointDefSetSpring", GenR_SDLStatic_WeldJointDefSetSpring, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJointDefCreate", GenR_SDLStatic_WheelJointDefCreate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJointDefDestroy", GenR_SDLStatic_WheelJointDefDestroy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJointDefSetAnchors", GenR_SDLStatic_WheelJointDefSetAnchors, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJointDefSetAxis", GenR_SDLStatic_WheelJointDefSetAxis, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJointDefSetBodies", GenR_SDLStatic_WheelJointDefSetBodies, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJointDefSetMotor", GenR_SDLStatic_WheelJointDefSetMotor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WheelJointDefSetSpring", GenR_SDLStatic_WheelJointDefSetSpring, MRB_ARGS_ANY());
    mrb_define_const(mrb, mod, "SDLSTATIC_ASSET_MISSING", mrb_int_value(mrb, (mrb_int)SDLSTATIC_ASSET_MISSING));
    mrb_define_const(mrb, mod, "SDLSTATIC_ASSET_QUEUED", mrb_int_value(mrb, (mrb_int)SDLSTATIC_ASSET_QUEUED));
    mrb_define_const(mrb, mod, "SDLSTATIC_ASSET_LOADING", mrb_int_value(mrb, (mrb_int)SDLSTATIC_ASSET_LOADING));
    mrb_define_const(mrb, mod, "SDLSTATIC_ASSET_DECODED", mrb_int_value(mrb, (mrb_int)SDLSTATIC_ASSET_DECODED));
    mrb_define_const(mrb, mod, "SDLSTATIC_ASSET_READY", mrb_int_value(mrb, (mrb_int)SDLSTATIC_ASSET_READY));
    mrb_define_const(mrb, mod, "SDLSTATIC_ASSET_FAILED", mrb_int_value(mrb, (mrb_int)SDLSTATIC_ASSET_FAILED));
    mrb_define_const(mrb, mod, "SDLSTATIC_BIND_NONE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BIND_NONE));
    mrb_define_const(mrb, mod, "SDLSTATIC_BIND_KEY", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BIND_KEY));
    mrb_define_const(mrb, mod, "SDLSTATIC_BIND_MOUSE_BUTTON", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BIND_MOUSE_BUTTON));
    mrb_define_const(mrb, mod, "SDLSTATIC_BIND_MOUSE_WHEEL", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BIND_MOUSE_WHEEL));
    mrb_define_const(mrb, mod, "SDLSTATIC_BIND_PAD_BUTTON", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BIND_PAD_BUTTON));
    mrb_define_const(mrb, mod, "SDLSTATIC_BIND_PAD_AXIS", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BIND_PAD_AXIS));
    mrb_define_const(mrb, mod, "SDLSTATIC_BIND_PAD_DIRECTION", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BIND_PAD_DIRECTION));
    mrb_define_const(mrb, mod, "SDLSTATIC_BODY_STATIC", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BODY_STATIC));
    mrb_define_const(mrb, mod, "SDLSTATIC_BODY_KINEMATIC", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BODY_KINEMATIC));
    mrb_define_const(mrb, mod, "SDLSTATIC_BODY_DYNAMIC", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BODY_DYNAMIC));
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_COIN", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_COIN));
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_LASER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_LASER));
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_JUMP", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_JUMP));
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_EXPLOSION", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_EXPLOSION));
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_POWERUP", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_POWERUP));
    mrb_define_const(mrb, mod, "SDLSTATIC_SFX_HURT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SFX_HURT));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_SQUARE_125", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_SQUARE_125));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_SQUARE_25", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_SQUARE_25));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_SQUARE_50", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_SQUARE_50));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_TRIANGLE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_TRIANGLE));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_SAW", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_SAW));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_NOISE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_NOISE));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_NOISE_METALLIC", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_NOISE_METALLIC));
    mrb_define_const(mrb, mod, "SDLSTATIC_CHIP_SINE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_CHIP_SINE));
    mrb_define_const(mrb, mod, "SDLSTATIC_COLORBLIND_NONE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_COLORBLIND_NONE));
    mrb_define_const(mrb, mod, "SDLSTATIC_COLORBLIND_PROTANOPIA", mrb_int_value(mrb, (mrb_int)SDLSTATIC_COLORBLIND_PROTANOPIA));
    mrb_define_const(mrb, mod, "SDLSTATIC_COLORBLIND_DEUTERANOPIA", mrb_int_value(mrb, (mrb_int)SDLSTATIC_COLORBLIND_DEUTERANOPIA));
    mrb_define_const(mrb, mod, "SDLSTATIC_COLORBLIND_TRITANOPIA", mrb_int_value(mrb, (mrb_int)SDLSTATIC_COLORBLIND_TRITANOPIA));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIALOG_IDLE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIALOG_IDLE));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIALOG_PENDING", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIALOG_PENDING));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIALOG_ACCEPTED", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIALOG_ACCEPTED));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIALOG_CANCELLED", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIALOG_CANCELLED));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIALOG_ERROR", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIALOG_ERROR));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIR_UP", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIR_UP));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIR_DOWN", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIR_DOWN));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIR_LEFT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIR_LEFT));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIR_RIGHT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIR_RIGHT));
    mrb_define_const(mrb, mod, "SDLSTATIC_DIR_COUNT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DIR_COUNT));
    mrb_define_const(mrb, mod, "SDLSTATIC_BACKEND_OPENGL", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BACKEND_OPENGL));
    mrb_define_const(mrb, mod, "SDLSTATIC_BACKEND_NATIVE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BACKEND_NATIVE));
    mrb_define_const(mrb, mod, "SDLSTATIC_BACKEND_SOFTWARE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_BACKEND_SOFTWARE));
    mrb_define_const(mrb, mod, "SDLSTATIC_INTERPOLATE_LERP", mrb_int_value(mrb, (mrb_int)SDLSTATIC_INTERPOLATE_LERP));
    mrb_define_const(mrb, mod, "SDLSTATIC_INTERPOLATE_NONE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_INTERPOLATE_NONE));
    mrb_define_const(mrb, mod, "SDLSTATIC_INTERPOLATE_EXTRAPOLATE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_INTERPOLATE_EXTRAPOLATE));
    mrb_define_const(mrb, mod, "SDLSTATIC_PRESENT_LETTERBOX", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PRESENT_LETTERBOX));
    mrb_define_const(mrb, mod, "SDLSTATIC_PRESENT_EXPAND", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PRESENT_EXPAND));
    mrb_define_const(mrb, mod, "SDLSTATIC_PRESENT_OVERSCAN", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PRESENT_OVERSCAN));
    mrb_define_const(mrb, mod, "SDLSTATIC_PRESENT_INTEGER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PRESENT_INTEGER));
    mrb_define_const(mrb, mod, "SDLSTATIC_PRESENT_STRETCH", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PRESENT_STRETCH));
    mrb_define_const(mrb, mod, "SDLSTATIC_PRESENT_NATIVE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PRESENT_NATIVE));
    mrb_define_const(mrb, mod, "SDLSTATIC_AXIS_LEFT_X", mrb_int_value(mrb, (mrb_int)SDLSTATIC_AXIS_LEFT_X));
    mrb_define_const(mrb, mod, "SDLSTATIC_AXIS_LEFT_Y", mrb_int_value(mrb, (mrb_int)SDLSTATIC_AXIS_LEFT_Y));
    mrb_define_const(mrb, mod, "SDLSTATIC_AXIS_RIGHT_X", mrb_int_value(mrb, (mrb_int)SDLSTATIC_AXIS_RIGHT_X));
    mrb_define_const(mrb, mod, "SDLSTATIC_AXIS_RIGHT_Y", mrb_int_value(mrb, (mrb_int)SDLSTATIC_AXIS_RIGHT_Y));
    mrb_define_const(mrb, mod, "SDLSTATIC_AXIS_LEFT_TRIGGER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_AXIS_LEFT_TRIGGER));
    mrb_define_const(mrb, mod, "SDLSTATIC_AXIS_RIGHT_TRIGGER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_AXIS_RIGHT_TRIGGER));
    mrb_define_const(mrb, mod, "SDLSTATIC_AXIS_COUNT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_AXIS_COUNT));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_A", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_A));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_B", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_B));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_X", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_X));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_Y", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_Y));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_BACK", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_BACK));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_GUIDE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_GUIDE));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_START", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_START));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_LEFT_STICK", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_LEFT_STICK));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_RIGHT_STICK", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_RIGHT_STICK));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_LEFT_SHOULDER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_LEFT_SHOULDER));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_RIGHT_SHOULDER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_RIGHT_SHOULDER));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_DPAD_UP", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_DPAD_UP));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_DPAD_DOWN", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_DPAD_DOWN));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_DPAD_LEFT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_DPAD_LEFT));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_DPAD_RIGHT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_DPAD_RIGHT));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_SHARE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_SHARE));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_PADDLE1", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_PADDLE1));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_PADDLE2", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_PADDLE2));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_PADDLE3", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_PADDLE3));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_PADDLE4", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_PADDLE4));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_TOUCHPAD", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_TOUCHPAD));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_LEFT_TRIGGER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_LEFT_TRIGGER));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_RIGHT_TRIGGER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_RIGHT_TRIGGER));
    mrb_define_const(mrb, mod, "SDLSTATIC_PAD_BUTTON_COUNT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_PAD_BUTTON_COUNT));
    mrb_define_const(mrb, mod, "SDLSTATIC_AA_OFF", mrb_int_value(mrb, (mrb_int)SDLSTATIC_AA_OFF));
    mrb_define_const(mrb, mod, "SDLSTATIC_AA_FXAA", mrb_int_value(mrb, (mrb_int)SDLSTATIC_AA_FXAA));
    mrb_define_const(mrb, mod, "SDLSTATIC_QUALITY_OFF", mrb_int_value(mrb, (mrb_int)SDLSTATIC_QUALITY_OFF));
    mrb_define_const(mrb, mod, "SDLSTATIC_QUALITY_LOW", mrb_int_value(mrb, (mrb_int)SDLSTATIC_QUALITY_LOW));
    mrb_define_const(mrb, mod, "SDLSTATIC_QUALITY_MEDIUM", mrb_int_value(mrb, (mrb_int)SDLSTATIC_QUALITY_MEDIUM));
    mrb_define_const(mrb, mod, "SDLSTATIC_QUALITY_HIGH", mrb_int_value(mrb, (mrb_int)SDLSTATIC_QUALITY_HIGH));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_FONT_SMALL", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_FONT_SMALL));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_FONT_NORMAL", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_FONT_NORMAL));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_FONT_LARGE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_FONT_LARGE));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_GLYPHS_LATIN1", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_GLYPHS_LATIN1));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_GLYPHS_PUNCTUATION", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_GLYPHS_PUNCTUATION));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_GLYPHS_CYRILLIC", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_GLYPHS_CYRILLIC));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_GLYPHS_CHINESE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_GLYPHS_CHINESE));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_GLYPHS_KOREAN", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_GLYPHS_KOREAN));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_IMAGE_STRETCH", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_IMAGE_STRETCH));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_IMAGE_ZOOM", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_IMAGE_ZOOM));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_IMAGE_CENTER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_IMAGE_CENTER));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_IMAGE_FILL", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_IMAGE_FILL));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_WINDOW_BACKGROUND", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_WINDOW_BACKGROUND));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_TEXT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_TEXT));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_BUTTON", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_BUTTON));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_BUTTON_HOVER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_BUTTON_HOVER));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_BUTTON_TEXT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_BUTTON_TEXT));
    mrb_define_const(mrb, mod, "SDLSTATIC_GUI_COLOR_HEADER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_GUI_COLOR_HEADER));
    mrb_define_const(mrb, mod, "SDLSTATIC_DEVICE_NONE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DEVICE_NONE));
    mrb_define_const(mrb, mod, "SDLSTATIC_DEVICE_KEYBOARD", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DEVICE_KEYBOARD));
    mrb_define_const(mrb, mod, "SDLSTATIC_DEVICE_MOUSE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DEVICE_MOUSE));
    mrb_define_const(mrb, mod, "SDLSTATIC_DEVICE_GAMEPAD", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DEVICE_GAMEPAD));
    mrb_define_const(mrb, mod, "SDLSTATIC_DEVICE_TOUCH", mrb_int_value(mrb, (mrb_int)SDLSTATIC_DEVICE_TOUCH));
    mrb_define_const(mrb, mod, "SDLSTATIC_LIGHT_NONE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_LIGHT_NONE));
    mrb_define_const(mrb, mod, "SDLSTATIC_LIGHT_SUNRISE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_LIGHT_SUNRISE));
    mrb_define_const(mrb, mod, "SDLSTATIC_LIGHT_AFTERNOON", mrb_int_value(mrb, (mrb_int)SDLSTATIC_LIGHT_AFTERNOON));
    mrb_define_const(mrb, mod, "SDLSTATIC_LIGHT_SUNSET", mrb_int_value(mrb, (mrb_int)SDLSTATIC_LIGHT_SUNSET));
    mrb_define_const(mrb, mod, "SDLSTATIC_LIGHT_NIGHT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_LIGHT_NIGHT));
    mrb_define_const(mrb, mod, "SDLSTATIC_LIGHT_DARK", mrb_int_value(mrb, (mrb_int)SDLSTATIC_LIGHT_DARK));
    mrb_define_const(mrb, mod, "SDLSTATIC_MEDIA_NONE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_MEDIA_NONE));
    mrb_define_const(mrb, mod, "SDLSTATIC_MEDIA_EXPLICIT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_MEDIA_EXPLICIT));
    mrb_define_const(mrb, mod, "SDLSTATIC_MEDIA_EMBEDDED", mrb_int_value(mrb, (mrb_int)SDLSTATIC_MEDIA_EMBEDDED));
    mrb_define_const(mrb, mod, "SDLSTATIC_MEDIA_ARCHIVE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_MEDIA_ARCHIVE));
    mrb_define_const(mrb, mod, "SDLSTATIC_MEDIA_DIRECTORY", mrb_int_value(mrb, (mrb_int)SDLSTATIC_MEDIA_DIRECTORY));
    mrb_define_const(mrb, mod, "SDLSTATIC_MOUSE_LEFT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_MOUSE_LEFT));
    mrb_define_const(mrb, mod, "SDLSTATIC_MOUSE_MIDDLE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_MOUSE_MIDDLE));
    mrb_define_const(mrb, mod, "SDLSTATIC_MOUSE_RIGHT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_MOUSE_RIGHT));
    mrb_define_const(mrb, mod, "SDLSTATIC_MOUSE_X1", mrb_int_value(mrb, (mrb_int)SDLSTATIC_MOUSE_X1));
    mrb_define_const(mrb, mod, "SDLSTATIC_MOUSE_X2", mrb_int_value(mrb, (mrb_int)SDLSTATIC_MOUSE_X2));
    mrb_define_const(mrb, mod, "SDLSTATIC_MOUSE_COUNT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_MOUSE_COUNT));
    mrb_define_const(mrb, mod, "SDLSTATIC_SCENE_DEFAULT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SCENE_DEFAULT));
    mrb_define_const(mrb, mod, "SDLSTATIC_SCENE_UPDATE_WHEN_COVERED", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SCENE_UPDATE_WHEN_COVERED));
    mrb_define_const(mrb, mod, "SDLSTATIC_SCENE_TRANSPARENT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SCENE_TRANSPARENT));
    mrb_define_const(mrb, mod, "SDLSTATIC_TRANSITION_NONE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_TRANSITION_NONE));
    mrb_define_const(mrb, mod, "SDLSTATIC_TRANSITION_FADE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_TRANSITION_FADE));
    mrb_define_const(mrb, mod, "SDLSTATIC_HOOK_LOAD", mrb_int_value(mrb, (mrb_int)SDLSTATIC_HOOK_LOAD));
    mrb_define_const(mrb, mod, "SDLSTATIC_HOOK_FIXED_UPDATE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_HOOK_FIXED_UPDATE));
    mrb_define_const(mrb, mod, "SDLSTATIC_HOOK_UPDATE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_HOOK_UPDATE));
    mrb_define_const(mrb, mod, "SDLSTATIC_HOOK_RENDER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_HOOK_RENDER));
    mrb_define_const(mrb, mod, "SDLSTATIC_HOOK_POST_RENDER", mrb_int_value(mrb, (mrb_int)SDLSTATIC_HOOK_POST_RENDER));
    mrb_define_const(mrb, mod, "SDLSTATIC_HOOK_UNLOAD", mrb_int_value(mrb, (mrb_int)SDLSTATIC_HOOK_UNLOAD));
    mrb_define_const(mrb, mod, "SDLSTATIC_HOOK_COUNT", mrb_int_value(mrb, (mrb_int)SDLSTATIC_HOOK_COUNT));
    mrb_define_const(mrb, mod, "SDLSTATIC_SHAPE_BOX", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SHAPE_BOX));
    mrb_define_const(mrb, mod, "SDLSTATIC_SHAPE_CIRCLE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SHAPE_CIRCLE));
    mrb_define_const(mrb, mod, "SDLSTATIC_SHAPE_CAPSULE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SHAPE_CAPSULE));
    mrb_define_const(mrb, mod, "SDLSTATIC_SPLIT_HORIZONTAL", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SPLIT_HORIZONTAL));
    mrb_define_const(mrb, mod, "SDLSTATIC_SPLIT_VERTICAL", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SPLIT_VERTICAL));
    mrb_define_const(mrb, mod, "SDLSTATIC_SPLIT_GRID", mrb_int_value(mrb, (mrb_int)SDLSTATIC_SPLIT_GRID));
    mrb_define_const(mrb, mod, "SDLSTATIC_FILTER_AUTO", mrb_int_value(mrb, (mrb_int)SDLSTATIC_FILTER_AUTO));
    mrb_define_const(mrb, mod, "SDLSTATIC_FILTER_LINEAR", mrb_int_value(mrb, (mrb_int)SDLSTATIC_FILTER_LINEAR));
    mrb_define_const(mrb, mod, "SDLSTATIC_FILTER_NEAREST", mrb_int_value(mrb, (mrb_int)SDLSTATIC_FILTER_NEAREST));
    mrb_define_const(mrb, mod, "SDLSTATIC_WINDOW_WINDOWED", mrb_int_value(mrb, (mrb_int)SDLSTATIC_WINDOW_WINDOWED));
    mrb_define_const(mrb, mod, "SDLSTATIC_WINDOW_BORDERLESS", mrb_int_value(mrb, (mrb_int)SDLSTATIC_WINDOW_BORDERLESS));
    mrb_define_const(mrb, mod, "SDLSTATIC_WINDOW_EXCLUSIVE", mrb_int_value(mrb, (mrb_int)SDLSTATIC_WINDOW_EXCLUSIVE));
}
