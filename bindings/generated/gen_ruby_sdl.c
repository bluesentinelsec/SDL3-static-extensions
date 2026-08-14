/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for SDL3 core. */
#include "../src/gen_support_ruby.h"

#include <SDL3/SDL.h>
#include <string.h>

static mrb_value GenPush_SDL_AtomicInt(mrb_state *mrb, const SDL_AtomicInt *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "value", mrb_int_value(mrb, (mrb_int)in->value));
    return h;
}

static mrb_value GenPush_SDL_AtomicU32(mrb_state *mrb, const SDL_AtomicU32 *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "value", mrb_int_value(mrb, (mrb_int)in->value));
    return h;
}

static void GenRead_SDL_AudioSpec(mrb_state *mrb, mrb_value h, SDL_AudioSpec *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->format = (SDL_AudioFormat)SDLStaticGen_RubyFieldInt(mrb, h, "format");
    out->channels = (int)SDLStaticGen_RubyFieldInt(mrb, h, "channels");
    out->freq = (int)SDLStaticGen_RubyFieldInt(mrb, h, "freq");
}

static mrb_value GenPush_SDL_AudioSpec(mrb_state *mrb, const SDL_AudioSpec *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "format", mrb_int_value(mrb, (mrb_int)in->format));
    SDLStaticGen_RubyHashSet(mrb, h, "channels", mrb_int_value(mrb, (mrb_int)in->channels));
    SDLStaticGen_RubyHashSet(mrb, h, "freq", mrb_int_value(mrb, (mrb_int)in->freq));
    return h;
}

static void GenRead_SDL_CameraSpec(mrb_state *mrb, mrb_value h, SDL_CameraSpec *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->format = (SDL_PixelFormat)SDLStaticGen_RubyFieldInt(mrb, h, "format");
    out->colorspace = (SDL_Colorspace)SDLStaticGen_RubyFieldInt(mrb, h, "colorspace");
    out->width = (int)SDLStaticGen_RubyFieldInt(mrb, h, "width");
    out->height = (int)SDLStaticGen_RubyFieldInt(mrb, h, "height");
    out->framerate_numerator = (int)SDLStaticGen_RubyFieldInt(mrb, h, "framerate_numerator");
    out->framerate_denominator = (int)SDLStaticGen_RubyFieldInt(mrb, h, "framerate_denominator");
}

static mrb_value GenPush_SDL_CameraSpec(mrb_state *mrb, const SDL_CameraSpec *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "format", mrb_int_value(mrb, (mrb_int)in->format));
    SDLStaticGen_RubyHashSet(mrb, h, "colorspace", mrb_int_value(mrb, (mrb_int)in->colorspace));
    SDLStaticGen_RubyHashSet(mrb, h, "width", mrb_int_value(mrb, (mrb_int)in->width));
    SDLStaticGen_RubyHashSet(mrb, h, "height", mrb_int_value(mrb, (mrb_int)in->height));
    SDLStaticGen_RubyHashSet(mrb, h, "framerate_numerator", mrb_int_value(mrb, (mrb_int)in->framerate_numerator));
    SDLStaticGen_RubyHashSet(mrb, h, "framerate_denominator", mrb_int_value(mrb, (mrb_int)in->framerate_denominator));
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

static void GenRead_SDL_DateTime(mrb_state *mrb, mrb_value h, SDL_DateTime *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->year = (int)SDLStaticGen_RubyFieldInt(mrb, h, "year");
    out->month = (int)SDLStaticGen_RubyFieldInt(mrb, h, "month");
    out->day = (int)SDLStaticGen_RubyFieldInt(mrb, h, "day");
    out->hour = (int)SDLStaticGen_RubyFieldInt(mrb, h, "hour");
    out->minute = (int)SDLStaticGen_RubyFieldInt(mrb, h, "minute");
    out->second = (int)SDLStaticGen_RubyFieldInt(mrb, h, "second");
    out->nanosecond = (int)SDLStaticGen_RubyFieldInt(mrb, h, "nanosecond");
    out->day_of_week = (int)SDLStaticGen_RubyFieldInt(mrb, h, "day_of_week");
    out->utc_offset = (int)SDLStaticGen_RubyFieldInt(mrb, h, "utc_offset");
}

static mrb_value GenPush_SDL_DateTime(mrb_state *mrb, const SDL_DateTime *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "year", mrb_int_value(mrb, (mrb_int)in->year));
    SDLStaticGen_RubyHashSet(mrb, h, "month", mrb_int_value(mrb, (mrb_int)in->month));
    SDLStaticGen_RubyHashSet(mrb, h, "day", mrb_int_value(mrb, (mrb_int)in->day));
    SDLStaticGen_RubyHashSet(mrb, h, "hour", mrb_int_value(mrb, (mrb_int)in->hour));
    SDLStaticGen_RubyHashSet(mrb, h, "minute", mrb_int_value(mrb, (mrb_int)in->minute));
    SDLStaticGen_RubyHashSet(mrb, h, "second", mrb_int_value(mrb, (mrb_int)in->second));
    SDLStaticGen_RubyHashSet(mrb, h, "nanosecond", mrb_int_value(mrb, (mrb_int)in->nanosecond));
    SDLStaticGen_RubyHashSet(mrb, h, "day_of_week", mrb_int_value(mrb, (mrb_int)in->day_of_week));
    SDLStaticGen_RubyHashSet(mrb, h, "utc_offset", mrb_int_value(mrb, (mrb_int)in->utc_offset));
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

static void GenRead_SDL_FPoint(mrb_state *mrb, mrb_value h, SDL_FPoint *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "x");
    out->y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "y");
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

static void GenRead_SDL_GPUBufferCreateInfo(mrb_state *mrb, mrb_value h, SDL_GPUBufferCreateInfo *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->usage = (SDL_GPUBufferUsageFlags)SDLStaticGen_RubyFieldInt(mrb, h, "usage");
    out->size = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "size");
    out->props = (SDL_PropertiesID)SDLStaticGen_RubyFieldInt(mrb, h, "props");
}

static void GenRead_SDL_GPUSamplerCreateInfo(mrb_state *mrb, mrb_value h, SDL_GPUSamplerCreateInfo *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->min_filter = (SDL_GPUFilter)SDLStaticGen_RubyFieldInt(mrb, h, "min_filter");
    out->mag_filter = (SDL_GPUFilter)SDLStaticGen_RubyFieldInt(mrb, h, "mag_filter");
    out->mipmap_mode = (SDL_GPUSamplerMipmapMode)SDLStaticGen_RubyFieldInt(mrb, h, "mipmap_mode");
    out->address_mode_u = (SDL_GPUSamplerAddressMode)SDLStaticGen_RubyFieldInt(mrb, h, "address_mode_u");
    out->address_mode_v = (SDL_GPUSamplerAddressMode)SDLStaticGen_RubyFieldInt(mrb, h, "address_mode_v");
    out->address_mode_w = (SDL_GPUSamplerAddressMode)SDLStaticGen_RubyFieldInt(mrb, h, "address_mode_w");
    out->mip_lod_bias = (float)SDLStaticGen_RubyFieldNum(mrb, h, "mip_lod_bias");
    out->max_anisotropy = (float)SDLStaticGen_RubyFieldNum(mrb, h, "max_anisotropy");
    out->compare_op = (SDL_GPUCompareOp)SDLStaticGen_RubyFieldInt(mrb, h, "compare_op");
    out->min_lod = (float)SDLStaticGen_RubyFieldNum(mrb, h, "min_lod");
    out->max_lod = (float)SDLStaticGen_RubyFieldNum(mrb, h, "max_lod");
    out->enable_anisotropy = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "enable_anisotropy");
    out->enable_compare = (bool)SDLStaticGen_RubyFieldBool(mrb, h, "enable_compare");
    out->padding1 = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "padding1");
    out->padding2 = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "padding2");
    out->props = (SDL_PropertiesID)SDLStaticGen_RubyFieldInt(mrb, h, "props");
}

static void GenRead_SDL_GPUTextureCreateInfo(mrb_state *mrb, mrb_value h, SDL_GPUTextureCreateInfo *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->type = (SDL_GPUTextureType)SDLStaticGen_RubyFieldInt(mrb, h, "type");
    out->format = (SDL_GPUTextureFormat)SDLStaticGen_RubyFieldInt(mrb, h, "format");
    out->usage = (SDL_GPUTextureUsageFlags)SDLStaticGen_RubyFieldInt(mrb, h, "usage");
    out->width = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "width");
    out->height = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "height");
    out->layer_count_or_depth = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "layer_count_or_depth");
    out->num_levels = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "num_levels");
    out->sample_count = (SDL_GPUSampleCount)SDLStaticGen_RubyFieldInt(mrb, h, "sample_count");
    out->props = (SDL_PropertiesID)SDLStaticGen_RubyFieldInt(mrb, h, "props");
}

static void GenRead_SDL_GPUTransferBufferCreateInfo(mrb_state *mrb, mrb_value h, SDL_GPUTransferBufferCreateInfo *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->usage = (SDL_GPUTransferBufferUsage)SDLStaticGen_RubyFieldInt(mrb, h, "usage");
    out->size = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "size");
    out->props = (SDL_PropertiesID)SDLStaticGen_RubyFieldInt(mrb, h, "props");
}

static void GenRead_SDL_GPUViewport(mrb_state *mrb, mrb_value h, SDL_GPUViewport *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "x");
    out->y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "y");
    out->w = (float)SDLStaticGen_RubyFieldNum(mrb, h, "w");
    out->h = (float)SDLStaticGen_RubyFieldNum(mrb, h, "h");
    out->min_depth = (float)SDLStaticGen_RubyFieldNum(mrb, h, "min_depth");
    out->max_depth = (float)SDLStaticGen_RubyFieldNum(mrb, h, "max_depth");
}

static void GenRead_SDL_GUID(mrb_state *mrb, mrb_value h, SDL_GUID *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    {
        mrb_value arr = SDLStaticGen_RubyFieldGet(mrb, h, "data");
        if (mrb_array_p(arr)) {
            for (mrb_int gi = 0; gi < (mrb_int)(16) && gi < RARRAY_LEN(arr); ++gi) {
                mrb_value el = mrb_ary_ref(mrb, arr, gi);
                out->data[gi] = (Uint8)SDLStaticGen_RubyToInt(mrb, el);
            }
        }
    }
}

static mrb_value GenPush_SDL_GUID(mrb_state *mrb, const SDL_GUID *in)
{
    mrb_value h = mrb_hash_new(mrb);
    {
        mrb_value arr = mrb_ary_new_capa(mrb, (mrb_int)(16));
        for (mrb_int gi = 0; gi < (mrb_int)(16); ++gi) {
            mrb_ary_push(mrb, arr, mrb_int_value(mrb, (mrb_int)in->data[gi]));
        }
        SDLStaticGen_RubyHashSet(mrb, h, "data", arr);
    }
    return h;
}

static mrb_value GenPush_SDL_PathInfo(mrb_state *mrb, const SDL_PathInfo *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "type", mrb_int_value(mrb, (mrb_int)in->type));
    SDLStaticGen_RubyHashSet(mrb, h, "size", mrb_int_value(mrb, (mrb_int)in->size));
    SDLStaticGen_RubyHashSet(mrb, h, "create_time", mrb_int_value(mrb, (mrb_int)in->create_time));
    SDLStaticGen_RubyHashSet(mrb, h, "modify_time", mrb_int_value(mrb, (mrb_int)in->modify_time));
    SDLStaticGen_RubyHashSet(mrb, h, "access_time", mrb_int_value(mrb, (mrb_int)in->access_time));
    return h;
}

static void GenRead_SDL_PixelFormatDetails(mrb_state *mrb, mrb_value h, SDL_PixelFormatDetails *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->format = (SDL_PixelFormat)SDLStaticGen_RubyFieldInt(mrb, h, "format");
    out->bits_per_pixel = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "bits_per_pixel");
    out->bytes_per_pixel = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "bytes_per_pixel");
    {
        mrb_value arr = SDLStaticGen_RubyFieldGet(mrb, h, "padding");
        if (mrb_array_p(arr)) {
            for (mrb_int gi = 0; gi < (mrb_int)(2) && gi < RARRAY_LEN(arr); ++gi) {
                mrb_value el = mrb_ary_ref(mrb, arr, gi);
                out->padding[gi] = (Uint8)SDLStaticGen_RubyToInt(mrb, el);
            }
        }
    }
    out->Rmask = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "Rmask");
    out->Gmask = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "Gmask");
    out->Bmask = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "Bmask");
    out->Amask = (Uint32)SDLStaticGen_RubyFieldInt(mrb, h, "Amask");
    out->Rbits = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "Rbits");
    out->Gbits = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "Gbits");
    out->Bbits = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "Bbits");
    out->Abits = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "Abits");
    out->Rshift = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "Rshift");
    out->Gshift = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "Gshift");
    out->Bshift = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "Bshift");
    out->Ashift = (Uint8)SDLStaticGen_RubyFieldInt(mrb, h, "Ashift");
}

static void GenRead_SDL_Point(mrb_state *mrb, mrb_value h, SDL_Point *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (int)SDLStaticGen_RubyFieldInt(mrb, h, "x");
    out->y = (int)SDLStaticGen_RubyFieldInt(mrb, h, "y");
}

static void GenRead_SDL_Rect(mrb_state *mrb, mrb_value h, SDL_Rect *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (int)SDLStaticGen_RubyFieldInt(mrb, h, "x");
    out->y = (int)SDLStaticGen_RubyFieldInt(mrb, h, "y");
    out->w = (int)SDLStaticGen_RubyFieldInt(mrb, h, "w");
    out->h = (int)SDLStaticGen_RubyFieldInt(mrb, h, "h");
}

static mrb_value GenPush_SDL_Rect(mrb_state *mrb, const SDL_Rect *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "x", mrb_int_value(mrb, (mrb_int)in->x));
    SDLStaticGen_RubyHashSet(mrb, h, "y", mrb_int_value(mrb, (mrb_int)in->y));
    SDLStaticGen_RubyHashSet(mrb, h, "w", mrb_int_value(mrb, (mrb_int)in->w));
    SDLStaticGen_RubyHashSet(mrb, h, "h", mrb_int_value(mrb, (mrb_int)in->h));
    return h;
}

static void GenDtor_SDL_DestroyWindow(void *p)
{
    SDL_Window *typed = (SDL_Window *)p;
    SDL_DestroyWindow(typed);
}

static void GenDtor_SDL_DestroyRenderer(void *p)
{
    SDL_Renderer *typed = (SDL_Renderer *)p;
    SDL_DestroyRenderer(typed);
}

static void GenDtor_SDL_DestroyTexture(void *p)
{
    SDL_Texture *typed = (SDL_Texture *)p;
    SDL_DestroyTexture(typed);
}

static void GenDtor_SDL_DestroySurface(void *p)
{
    SDL_Surface *typed = (SDL_Surface *)p;
    SDL_DestroySurface(typed);
}

static void GenDtor_SDL_DestroyAudioStream(void *p)
{
    SDL_AudioStream *typed = (SDL_AudioStream *)p;
    SDL_DestroyAudioStream(typed);
}

static void GenDtor_SDL_CloseCamera(void *p)
{
    SDL_Camera *typed = (SDL_Camera *)p;
    SDL_CloseCamera(typed);
}

static void GenDtor_SDL_CloseGamepad(void *p)
{
    SDL_Gamepad *typed = (SDL_Gamepad *)p;
    SDL_CloseGamepad(typed);
}

static void GenDtor_SDL_CloseJoystick(void *p)
{
    SDL_Joystick *typed = (SDL_Joystick *)p;
    SDL_CloseJoystick(typed);
}

static void GenDtor_SDL_CloseHaptic(void *p)
{
    SDL_Haptic *typed = (SDL_Haptic *)p;
    SDL_CloseHaptic(typed);
}

static void GenDtor_SDL_CloseSensor(void *p)
{
    SDL_Sensor *typed = (SDL_Sensor *)p;
    SDL_CloseSensor(typed);
}

static void GenDtor_SDL_DestroyCursor(void *p)
{
    SDL_Cursor *typed = (SDL_Cursor *)p;
    SDL_DestroyCursor(typed);
}

static void GenDtor_SDL_DestroyPalette(void *p)
{
    SDL_Palette *typed = (SDL_Palette *)p;
    SDL_DestroyPalette(typed);
}

static void GenDtor_SDL_CloseIO(void *p)
{
    SDL_IOStream *typed = (SDL_IOStream *)p;
    SDL_CloseIO(typed);
}

static void GenDtor_SDL_DestroyAsyncIOQueue(void *p)
{
    SDL_AsyncIOQueue *typed = (SDL_AsyncIOQueue *)p;
    SDL_DestroyAsyncIOQueue(typed);
}

static void GenDtor_SDL_CloseStorage(void *p)
{
    SDL_Storage *typed = (SDL_Storage *)p;
    SDL_CloseStorage(typed);
}

static void GenDtor_SDL_DestroyProcess(void *p)
{
    SDL_Process *typed = (SDL_Process *)p;
    SDL_DestroyProcess(typed);
}

static void GenDtor_SDL_DestroyTray(void *p)
{
    SDL_Tray *typed = (SDL_Tray *)p;
    SDL_DestroyTray(typed);
}

static void GenDtor_SDL_UnloadObject(void *p)
{
    SDL_SharedObject *typed = (SDL_SharedObject *)p;
    SDL_UnloadObject(typed);
}

static void GenDtor_SDL_DestroyEnvironment(void *p)
{
    SDL_Environment *typed = (SDL_Environment *)p;
    SDL_DestroyEnvironment(typed);
}

static void GenDtor_SDL_DestroyGPUDevice(void *p)
{
    SDL_GPUDevice *typed = (SDL_GPUDevice *)p;
    SDL_DestroyGPUDevice(typed);
}

static mrb_value GenR_SDL_AcquireCameraFrame(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Camera");
    Uint64 io1 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Surface * rv = SDL_AcquireCameraFrame(a0, &io1);
    mrb_value rets[2];
    rets[0] = SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_AcquireGPUCommandBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUCommandBuffer * rv = SDL_AcquireGPUCommandBuffer(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUCommandBuffer");
    }
}

static mrb_value GenR_SDL_AddGamepadMapping(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = SDL_AddGamepadMapping(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_AddGamepadMappingsFromFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = SDL_AddGamepadMappingsFromFile(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_AddGamepadMappingsFromIO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDL_AddGamepadMappingsFromIO(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_AddSurfaceAlternateImage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Surface");
    bool rv = SDL_AddSurfaceAlternateImage(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_AddVulkanRenderSemaphores(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint64 a2 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint64 a3 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_AddVulkanRenderSemaphores(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_AsyncIOFromFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_AsyncIO * rv = SDL_AsyncIOFromFile(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_AsyncIO");
    }
}

static mrb_value GenR_SDL_AttachVirtualJoystick(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDL_VirtualJoystickDesc *a0 = (const SDL_VirtualJoystickDesc *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_VirtualJoystickDesc");
    SDL_JoystickID rv = SDL_AttachVirtualJoystick(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_AudioDevicePaused(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_AudioDevicePaused(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_AudioStreamDevicePaused(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    bool rv = SDL_AudioStreamDevicePaused(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_BeginGPUComputePass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    const SDL_GPUStorageTextureReadWriteBinding *a1 = (const SDL_GPUStorageTextureReadWriteBinding *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUStorageTextureReadWriteBinding");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const SDL_GPUStorageBufferReadWriteBinding *a3 = (const SDL_GPUStorageBufferReadWriteBinding *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), "SDL_GPUStorageBufferReadWriteBinding");
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_GPUComputePass * rv = SDL_BeginGPUComputePass(a0, a1, a2, a3, a4);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUComputePass");
    }
}

static mrb_value GenR_SDL_BeginGPUCopyPass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    SDL_GPUCopyPass * rv = SDL_BeginGPUCopyPass(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUCopyPass");
    }
}

static mrb_value GenR_SDL_BeginGPURenderPass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    const SDL_GPUColorTargetInfo *a1 = (const SDL_GPUColorTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUColorTargetInfo");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const SDL_GPUDepthStencilTargetInfo *a3 = (const SDL_GPUDepthStencilTargetInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), "SDL_GPUDepthStencilTargetInfo");
    SDL_GPURenderPass * rv = SDL_BeginGPURenderPass(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPURenderPass");
    }
}

static mrb_value GenR_SDL_BindAudioStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_AudioStream *a1 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_AudioStream");
    bool rv = SDL_BindAudioStream(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_BindGPUComputePipeline(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePass");
    SDL_GPUComputePipeline *a1 = (SDL_GPUComputePipeline *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUComputePipeline");
    SDL_BindGPUComputePipeline(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_BindGPUComputeSamplers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const SDL_GPUTextureSamplerBinding *a2 = (const SDL_GPUTextureSamplerBinding *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUTextureSamplerBinding");
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_BindGPUComputeSamplers(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_BindGPUFragmentSamplers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const SDL_GPUTextureSamplerBinding *a2 = (const SDL_GPUTextureSamplerBinding *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUTextureSamplerBinding");
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_BindGPUFragmentSamplers(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_BindGPUGraphicsPipeline(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    SDL_GPUGraphicsPipeline *a1 = (SDL_GPUGraphicsPipeline *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUGraphicsPipeline");
    SDL_BindGPUGraphicsPipeline(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_BindGPUIndexBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    const SDL_GPUBufferBinding *a1 = (const SDL_GPUBufferBinding *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBufferBinding");
    SDL_GPUIndexElementSize a2 = (SDL_GPUIndexElementSize)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_BindGPUIndexBuffer(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_BindGPUVertexBuffers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const SDL_GPUBufferBinding *a2 = (const SDL_GPUBufferBinding *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUBufferBinding");
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_BindGPUVertexBuffers(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_BindGPUVertexSamplers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const SDL_GPUTextureSamplerBinding *a2 = (const SDL_GPUTextureSamplerBinding *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUTextureSamplerBinding");
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_BindGPUVertexSamplers(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_BlitGPUTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    const SDL_GPUBlitInfo *a1 = (const SDL_GPUBlitInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBlitInfo");
    SDL_BlitGPUTexture(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_BlitSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (argc > 3 && mrb_hash_p(argv[3])) {
        GenRead_SDL_Rect(mrb, argv[3], &tmp3);
        a3 = &tmp3;
    }
    bool rv = SDL_BlitSurface(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_BlitSurface9Grid(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int a5 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    SDL_ScaleMode a7 = (SDL_ScaleMode)SDLStaticGen_RubyToInt(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    SDL_Surface *a8 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 8 ? argv[8] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp9;
    const SDL_Rect *a9 = NULL;
    if (argc > 9 && mrb_hash_p(argv[9])) {
        GenRead_SDL_Rect(mrb, argv[9], &tmp9);
        a9 = &tmp9;
    }
    bool rv = SDL_BlitSurface9Grid(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_BlitSurfaceScaled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (argc > 3 && mrb_hash_p(argv[3])) {
        GenRead_SDL_Rect(mrb, argv[3], &tmp3);
        a3 = &tmp3;
    }
    SDL_ScaleMode a4 = (SDL_ScaleMode)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_BlitSurfaceScaled(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_BlitSurfaceTiled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (argc > 3 && mrb_hash_p(argv[3])) {
        GenRead_SDL_Rect(mrb, argv[3], &tmp3);
        a3 = &tmp3;
    }
    bool rv = SDL_BlitSurfaceTiled(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_BlitSurfaceTiledWithScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_ScaleMode a3 = (SDL_ScaleMode)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_Surface *a4 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 4 ? argv[4] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp5;
    const SDL_Rect *a5 = NULL;
    if (argc > 5 && mrb_hash_p(argv[5])) {
        GenRead_SDL_Rect(mrb, argv[5], &tmp5);
        a5 = &tmp5;
    }
    bool rv = SDL_BlitSurfaceTiledWithScale(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_BlitSurfaceUnchecked(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (argc > 3 && mrb_hash_p(argv[3])) {
        GenRead_SDL_Rect(mrb, argv[3], &tmp3);
        a3 = &tmp3;
    }
    bool rv = SDL_BlitSurfaceUnchecked(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_BlitSurfaceUncheckedScaled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (argc > 3 && mrb_hash_p(argv[3])) {
        GenRead_SDL_Rect(mrb, argv[3], &tmp3);
        a3 = &tmp3;
    }
    SDL_ScaleMode a4 = (SDL_ScaleMode)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_BlitSurfaceUncheckedScaled(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_CalculateGPUTextureFormatSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureFormat a0 = (SDL_GPUTextureFormat)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 rv = SDL_CalculateGPUTextureFormatSize(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_CancelGPUCommandBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    bool rv = SDL_CancelGPUCommandBuffer(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_CaptureMouse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool a0 = (bool)SDLStaticGen_RubyToBool((argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_CaptureMouse(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ClaimWindowForGPUDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_ClaimWindowForGPUDevice(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ClearAudioStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    bool rv = SDL_ClearAudioStream(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ClearClipboardData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_ClearClipboardData();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ClearComposition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_ClearComposition(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ClearError(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_ClearError();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ClearProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ClearProperty(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ClearSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_ClearSurface(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ClickTrayEntry(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayEntry");
    SDL_ClickTrayEntry(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_CloseAudioDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_CloseAudioDevice(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_CloseCamera(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Camera");
    SDL_CloseCamera(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_CloseGamepad(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_CloseGamepad(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_CloseHaptic(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    SDL_CloseHaptic(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_CloseIO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = SDL_CloseIO(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_CloseJoystick(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    SDL_CloseJoystick(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_CloseSensor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Sensor");
    SDL_CloseSensor(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_CloseStorage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Storage");
    bool rv = SDL_CloseStorage(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_CompareAndSwapAtomicInt(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AtomicInt out0;
    memset(&out0, 0, sizeof(out0));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_CompareAndSwapAtomicInt(&out0, a1, a2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_AtomicInt(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_CompareAndSwapAtomicU32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AtomicU32 out0;
    memset(&out0, 0, sizeof(out0));
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_CompareAndSwapAtomicU32(&out0, a1, a2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_AtomicU32(mrb, &out0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ComposeCustomBlendMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_BlendFactor a0 = (SDL_BlendFactor)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_BlendFactor a1 = (SDL_BlendFactor)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_BlendOperation a2 = (SDL_BlendOperation)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_BlendFactor a3 = (SDL_BlendFactor)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_BlendFactor a4 = (SDL_BlendFactor)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_BlendOperation a5 = (SDL_BlendOperation)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    SDL_BlendMode rv = SDL_ComposeCustomBlendMode(a0, a1, a2, a3, a4, a5);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_ConvertEventToRenderCoordinates(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Event *a1 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Event");
    bool rv = SDL_ConvertEventToRenderCoordinates(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ConvertSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_PixelFormat a1 = (SDL_PixelFormat)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Surface * rv = SDL_ConvertSurface(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_SDL_ConvertSurfaceAndColorspace(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_PixelFormat a1 = (SDL_PixelFormat)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Palette *a2 = (SDL_Palette *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_Palette");
    SDL_Colorspace a3 = (SDL_Colorspace)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_PropertiesID a4 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_Surface * rv = SDL_ConvertSurfaceAndColorspace(a0, a1, a2, a3, a4);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_SDL_CopyFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_CopyFile(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_CopyGPUBufferToBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCopyPass");
    const SDL_GPUBufferLocation *a1 = (const SDL_GPUBufferLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBufferLocation");
    const SDL_GPUBufferLocation *a2 = (const SDL_GPUBufferLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUBufferLocation");
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool a4 = (bool)SDLStaticGen_RubyToBool((argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_CopyGPUBufferToBuffer(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_CopyGPUTextureToTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCopyPass");
    const SDL_GPUTextureLocation *a1 = (const SDL_GPUTextureLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTextureLocation");
    const SDL_GPUTextureLocation *a2 = (const SDL_GPUTextureLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUTextureLocation");
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    bool a6 = (bool)SDLStaticGen_RubyToBool((argc > 6 ? argv[6] : mrb_nil_value()));
    SDL_CopyGPUTextureToTexture(a0, a1, a2, a3, a4, a5, a6);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_CopyProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_PropertiesID a1 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_CopyProperties(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_CopyStorageFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Storage");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_CopyStorageFile(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_CreateAnimatedCursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_CursorFrameInfo *a0 = (SDL_CursorFrameInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_CursorFrameInfo");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_Cursor * rv = SDL_CreateAnimatedCursor(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Cursor");
    }
}

static mrb_value GenR_SDL_CreateAsyncIOQueue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AsyncIOQueue * rv = SDL_CreateAsyncIOQueue();
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_AsyncIOQueue", GenDtor_SDL_DestroyAsyncIOQueue);
    }
}

static mrb_value GenR_SDL_CreateAudioStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioSpec tmp0;
    const SDL_AudioSpec *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_AudioSpec(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_AudioSpec tmp1;
    const SDL_AudioSpec *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_AudioSpec(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_AudioStream * rv = SDL_CreateAudioStream(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_AudioStream", GenDtor_SDL_DestroyAudioStream);
    }
}

static mrb_value GenR_SDL_CreateColorCursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Cursor * rv = SDL_CreateColorCursor(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Cursor", GenDtor_SDL_DestroyCursor);
    }
}

static mrb_value GenR_SDL_CreateDirectory(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_CreateDirectory(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_CreateEnvironment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool a0 = (bool)SDLStaticGen_RubyToBool((argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Environment * rv = SDL_CreateEnvironment(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Environment", GenDtor_SDL_DestroyEnvironment);
    }
}

static mrb_value GenR_SDL_CreateGPUBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUBufferCreateInfo tmp1;
    const SDL_GPUBufferCreateInfo *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_GPUBufferCreateInfo(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_GPUBuffer * rv = SDL_CreateGPUBuffer(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUBuffer");
    }
}

static mrb_value GenR_SDL_CreateGPUComputePipeline(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    const SDL_GPUComputePipelineCreateInfo *a1 = (const SDL_GPUComputePipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUComputePipelineCreateInfo");
    SDL_GPUComputePipeline * rv = SDL_CreateGPUComputePipeline(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUComputePipeline");
    }
}

static mrb_value GenR_SDL_CreateGPUDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUShaderFormat a0 = (SDL_GPUShaderFormat)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_GPUDevice * rv = SDL_CreateGPUDevice(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_GPUDevice", GenDtor_SDL_DestroyGPUDevice);
    }
}

static mrb_value GenR_SDL_CreateGPUDeviceWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_GPUDevice * rv = SDL_CreateGPUDeviceWithProperties(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_GPUDevice", GenDtor_SDL_DestroyGPUDevice);
    }
}

static mrb_value GenR_SDL_CreateGPUGraphicsPipeline(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    const SDL_GPUGraphicsPipelineCreateInfo *a1 = (const SDL_GPUGraphicsPipelineCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUGraphicsPipelineCreateInfo");
    SDL_GPUGraphicsPipeline * rv = SDL_CreateGPUGraphicsPipeline(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUGraphicsPipeline");
    }
}

static mrb_value GenR_SDL_CreateGPURenderState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    const SDL_GPURenderStateCreateInfo *a1 = (const SDL_GPURenderStateCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPURenderStateCreateInfo");
    SDL_GPURenderState * rv = SDL_CreateGPURenderState(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPURenderState");
    }
}

static mrb_value GenR_SDL_CreateGPURenderer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Window");
    SDL_Renderer * rv = SDL_CreateGPURenderer(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Renderer");
    }
}

static mrb_value GenR_SDL_CreateGPUSampler(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUSamplerCreateInfo tmp1;
    const SDL_GPUSamplerCreateInfo *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_GPUSamplerCreateInfo(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_GPUSampler * rv = SDL_CreateGPUSampler(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUSampler");
    }
}

static mrb_value GenR_SDL_CreateGPUShader(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    const SDL_GPUShaderCreateInfo *a1 = (const SDL_GPUShaderCreateInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUShaderCreateInfo");
    SDL_GPUShader * rv = SDL_CreateGPUShader(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUShader");
    }
}

static mrb_value GenR_SDL_CreateGPUTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUTextureCreateInfo tmp1;
    const SDL_GPUTextureCreateInfo *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_GPUTextureCreateInfo(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_GPUTexture * rv = SDL_CreateGPUTexture(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTexture");
    }
}

static mrb_value GenR_SDL_CreateGPUTransferBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUTransferBufferCreateInfo tmp1;
    const SDL_GPUTransferBufferCreateInfo *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_GPUTransferBufferCreateInfo(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_GPUTransferBuffer * rv = SDL_CreateGPUTransferBuffer(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUTransferBuffer");
    }
}

static mrb_value GenR_SDL_CreateHapticEffect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    const SDL_HapticEffect *a1 = (const SDL_HapticEffect *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_HapticEffect");
    SDL_HapticEffectID rv = SDL_CreateHapticEffect(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_CreatePalette(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Palette * rv = SDL_CreatePalette(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Palette", GenDtor_SDL_DestroyPalette);
    }
}

static mrb_value GenR_SDL_CreatePopupWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_WindowFlags a5 = (SDL_WindowFlags)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    SDL_Window * rv = SDL_CreatePopupWindow(a0, a1, a2, a3, a4, a5);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Window", GenDtor_SDL_DestroyWindow);
    }
}

static mrb_value GenR_SDL_CreateProcessWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Process * rv = SDL_CreateProcessWithProperties(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Process", GenDtor_SDL_DestroyProcess);
    }
}

static mrb_value GenR_SDL_CreateProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID rv = SDL_CreateProperties();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_CreateRenderer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Renderer * rv = SDL_CreateRenderer(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Renderer", GenDtor_SDL_DestroyRenderer);
    }
}

static mrb_value GenR_SDL_CreateRendererWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Renderer * rv = SDL_CreateRendererWithProperties(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Renderer", GenDtor_SDL_DestroyRenderer);
    }
}

static mrb_value GenR_SDL_CreateSoftwareRenderer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Renderer * rv = SDL_CreateSoftwareRenderer(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Renderer", GenDtor_SDL_DestroyRenderer);
    }
}

static mrb_value GenR_SDL_CreateStorageDirectory(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Storage");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_CreateStorageDirectory(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_CreateSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PixelFormat a2 = (SDL_PixelFormat)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Surface * rv = SDL_CreateSurface(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_SDL_CreateSurfacePalette(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Palette * rv = SDL_CreateSurfacePalette(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Palette");
    }
}

static mrb_value GenR_SDL_CreateSystemCursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_SystemCursor a0 = (SDL_SystemCursor)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Cursor * rv = SDL_CreateSystemCursor(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Cursor", GenDtor_SDL_DestroyCursor);
    }
}

static mrb_value GenR_SDL_CreateTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_PixelFormat a1 = (SDL_PixelFormat)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_TextureAccess a2 = (SDL_TextureAccess)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_Texture * rv = SDL_CreateTexture(a0, a1, a2, a3, a4);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Texture", GenDtor_SDL_DestroyTexture);
    }
}

static mrb_value GenR_SDL_CreateTextureFromSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Surface");
    SDL_Texture * rv = SDL_CreateTextureFromSurface(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Texture", GenDtor_SDL_DestroyTexture);
    }
}

static mrb_value GenR_SDL_CreateTextureWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_PropertiesID a1 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Texture * rv = SDL_CreateTextureWithProperties(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Texture", GenDtor_SDL_DestroyTexture);
    }
}

static mrb_value GenR_SDL_CreateTray(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Tray * rv = SDL_CreateTray(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Tray", GenDtor_SDL_DestroyTray);
    }
}

static mrb_value GenR_SDL_CreateTrayMenu(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Tray *a0 = (SDL_Tray *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Tray");
    SDL_TrayMenu * rv = SDL_CreateTrayMenu(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_TrayMenu");
    }
}

static mrb_value GenR_SDL_CreateTraySubmenu(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayEntry");
    SDL_TrayMenu * rv = SDL_CreateTraySubmenu(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_TrayMenu");
    }
}

static mrb_value GenR_SDL_CreateWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_WindowFlags a3 = (SDL_WindowFlags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_Window * rv = SDL_CreateWindow(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Window", GenDtor_SDL_DestroyWindow);
    }
}

static mrb_value GenR_SDL_CreateWindowWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Window * rv = SDL_CreateWindowWithProperties(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Window", GenDtor_SDL_DestroyWindow);
    }
}

static mrb_value GenR_SDL_CursorVisible(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_CursorVisible();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_DateTimeToTime(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DateTime tmp0;
    const SDL_DateTime *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_DateTime(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_Time io1 = (SDL_Time)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_DateTimeToTime(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_Delay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Delay(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DelayNS(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint64 a0 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_DelayNS(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DelayPrecise(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint64 a0 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_DelayPrecise(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyAsyncIOQueue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AsyncIOQueue *a0 = (SDL_AsyncIOQueue *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AsyncIOQueue");
    SDL_DestroyAsyncIOQueue(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyAudioStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    SDL_DestroyAudioStream(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyCursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Cursor *a0 = (SDL_Cursor *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Cursor");
    SDL_DestroyCursor(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyEnvironment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Environment *a0 = (SDL_Environment *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Environment");
    SDL_DestroyEnvironment(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyGPUDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_DestroyGPUDevice(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyGPURenderState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderState *a0 = (SDL_GPURenderState *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderState");
    SDL_DestroyGPURenderState(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyHapticEffect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    SDL_HapticEffectID a1 = (SDL_HapticEffectID)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_DestroyHapticEffect(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyPalette(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Palette *a0 = (SDL_Palette *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Palette");
    SDL_DestroyPalette(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyProcess(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Process");
    SDL_DestroyProcess(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_DestroyProperties(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyRenderer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_DestroyRenderer(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroySurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_DestroySurface(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    SDL_DestroyTexture(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyTray(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Tray *a0 = (SDL_Tray *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Tray");
    SDL_DestroyTray(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_DestroyWindow(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DestroyWindowSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_DestroyWindowSurface(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_DetachVirtualJoystick(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_DetachVirtualJoystick(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_DisableScreenSaver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_DisableScreenSaver();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_DispatchGPUCompute(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_DispatchGPUCompute(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DispatchGPUComputeIndirect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePass");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBuffer");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_DispatchGPUComputeIndirect(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DownloadFromGPUBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCopyPass");
    const SDL_GPUBufferRegion *a1 = (const SDL_GPUBufferRegion *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBufferRegion");
    const SDL_GPUTransferBufferLocation *a2 = (const SDL_GPUTransferBufferLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUTransferBufferLocation");
    SDL_DownloadFromGPUBuffer(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DownloadFromGPUTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCopyPass");
    const SDL_GPUTextureRegion *a1 = (const SDL_GPUTextureRegion *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTextureRegion");
    const SDL_GPUTextureTransferInfo *a2 = (const SDL_GPUTextureTransferInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUTextureTransferInfo");
    SDL_DownloadFromGPUTexture(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DrawGPUIndexedPrimitives(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Sint32 a4 = (Sint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 a5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    SDL_DrawGPUIndexedPrimitives(a0, a1, a2, a3, a4, a5);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DrawGPUIndexedPrimitivesIndirect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBuffer");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_DrawGPUIndexedPrimitivesIndirect(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DrawGPUPrimitives(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_DrawGPUPrimitives(a0, a1, a2, a3, a4);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DrawGPUPrimitivesIndirect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBuffer");
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_DrawGPUPrimitivesIndirect(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_DuplicateSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Surface * rv = SDL_DuplicateSurface(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_SDL_EnableScreenSaver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_EnableScreenSaver();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_EndGPUComputePass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUComputePass *a0 = (SDL_GPUComputePass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUComputePass");
    SDL_EndGPUComputePass(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_EndGPUCopyPass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCopyPass");
    SDL_EndGPUCopyPass(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_EndGPURenderPass(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    SDL_EndGPURenderPass(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_EventEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_EventEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_FillSurfaceRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_FillSurfaceRect(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_FillSurfaceRects(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_FillSurfaceRects(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_FlashWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_FlashOperation a1 = (SDL_FlashOperation)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_FlashWindow(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_FlipSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_FlipMode a1 = (SDL_FlipMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_FlipSurface(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_FlushAudioStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    bool rv = SDL_FlushAudioStream(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_FlushEvent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_FlushEvent(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_FlushEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_FlushEvents(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_FlushIO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool rv = SDL_FlushIO(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_FlushRenderer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    bool rv = SDL_FlushRenderer(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GL_ExtensionSupported(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_GL_ExtensionSupported(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GL_GetAttribute(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GLAttr a0 = (SDL_GLAttr)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GL_GetAttribute(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GL_GetCurrentWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window * rv = SDL_GL_GetCurrentWindow();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Window");
    }
}

static mrb_value GenR_SDL_GL_GetSwapInterval(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int io0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_GL_GetSwapInterval(&io0);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GL_LoadLibrary(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_GL_LoadLibrary(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GL_ResetAttributes(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GL_ResetAttributes();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_GL_SetAttribute(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GLAttr a0 = (SDL_GLAttr)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GL_SetAttribute(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GL_SetSwapInterval(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_GL_SetSwapInterval(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GL_SwapWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_GL_SwapWindow(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GL_UnloadLibrary(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GL_UnloadLibrary();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_GPUSupportsProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_GPUSupportsProperties(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GPUSupportsShaderFormats(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUShaderFormat a0 = (SDL_GPUShaderFormat)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GPUSupportsShaderFormats(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GPUTextureFormatTexelBlockSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureFormat a0 = (SDL_GPUTextureFormat)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint32 rv = SDL_GPUTextureFormatTexelBlockSize(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GPUTextureSupportsFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUTextureFormat a1 = (SDL_GPUTextureFormat)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUTextureType a2 = (SDL_GPUTextureType)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_GPUTextureUsageFlags a3 = (SDL_GPUTextureUsageFlags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_GPUTextureSupportsFormat(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GPUTextureSupportsSampleCount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUTextureFormat a1 = (SDL_GPUTextureFormat)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GPUSampleCount a2 = (SDL_GPUSampleCount)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GPUTextureSupportsSampleCount(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GUIDToString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GUID a0;
    GenRead_SDL_GUID(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    const char *src1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char *a1 = SDL_strdup(src1 != NULL ? src1 : "");
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_GUIDToString(a0, a1, a2);
    SDL_free(a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_GamepadConnected(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    bool rv = SDL_GamepadConnected(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GamepadEventsEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_GamepadEventsEnabled();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GamepadHasAxis(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_GamepadAxis a1 = (SDL_GamepadAxis)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GamepadHasAxis(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GamepadHasButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_GamepadButton a1 = (SDL_GamepadButton)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GamepadHasButton(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GamepadHasSensor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_SensorType a1 = (SDL_SensorType)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GamepadHasSensor(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GamepadSensorEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_SensorType a1 = (SDL_SensorType)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GamepadSensorEnabled(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GenerateMipmapsForGPUTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    SDL_GenerateMipmapsForGPUTexture(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_GetAppMetadataProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetAppMetadataProperty(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetAssertionReport(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDL_AssertData * rv = SDL_GetAssertionReport();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_AssertData");
    }
}

static mrb_value GenR_SDL_GetAsyncIOResult(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AsyncIOQueue *a0 = (SDL_AsyncIOQueue *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AsyncIOQueue");
    SDL_AsyncIOOutcome *a1 = (SDL_AsyncIOOutcome *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_AsyncIOOutcome");
    bool rv = SDL_GetAsyncIOResult(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetAsyncIOSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AsyncIO *a0 = (SDL_AsyncIO *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AsyncIO");
    Sint64 rv = SDL_GetAsyncIOSize(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetAudioDeviceFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_AudioSpec out1;
    memset(&out1, 0, sizeof(out1));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetAudioDeviceFormat(a0, &out1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_AudioSpec(mrb, &out1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetAudioDeviceGain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float rv = SDL_GetAudioDeviceGain(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDL_GetAudioDeviceName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetAudioDeviceName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetAudioDriver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetAudioDriver(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetAudioFormatName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioFormat a0 = (SDL_AudioFormat)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetAudioFormatName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetAudioStreamAvailable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    int rv = SDL_GetAudioStreamAvailable(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetAudioStreamDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    SDL_AudioDeviceID rv = SDL_GetAudioStreamDevice(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetAudioStreamFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    SDL_AudioSpec out1;
    memset(&out1, 0, sizeof(out1));
    SDL_AudioSpec out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetAudioStreamFormat(a0, &out1, &out2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_AudioSpec(mrb, &out1);
    rets[2] = GenPush_SDL_AudioSpec(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetAudioStreamFrequencyRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    float rv = SDL_GetAudioStreamFrequencyRatio(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDL_GetAudioStreamGain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    float rv = SDL_GetAudioStreamGain(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDL_GetAudioStreamProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    SDL_PropertiesID rv = SDL_GetAudioStreamProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetAudioStreamQueued(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    int rv = SDL_GetAudioStreamQueued(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetBasePath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = SDL_GetBasePath();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetBooleanProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetBooleanProperty(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetCPUCacheLineSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_GetCPUCacheLineSize();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetCameraDriver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetCameraDriver(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetCameraFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Camera");
    SDL_CameraSpec out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetCameraFormat(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_CameraSpec(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetCameraID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Camera");
    SDL_CameraID rv = SDL_GetCameraID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetCameraName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_CameraID a0 = (SDL_CameraID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetCameraName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetCameraPermissionState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Camera");
    SDL_CameraPermissionState rv = SDL_GetCameraPermissionState(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetCameraPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_CameraID a0 = (SDL_CameraID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_CameraPosition rv = SDL_GetCameraPosition(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetCameraProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Camera");
    SDL_PropertiesID rv = SDL_GetCameraProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetClipboardText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    char * rv = SDL_GetClipboardText();
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDL_GetClosestFullscreenDisplayMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DisplayID a0 = (SDL_DisplayID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool a4 = (bool)SDLStaticGen_RubyToBool((argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_DisplayMode *a5 = (SDL_DisplayMode *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 5 ? argv[5] : mrb_nil_value()), "SDL_DisplayMode");
    bool rv = SDL_GetClosestFullscreenDisplayMode(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetCurrentAudioDriver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = SDL_GetCurrentAudioDriver();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetCurrentCameraDriver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = SDL_GetCurrentCameraDriver();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetCurrentDirectory(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    char * rv = SDL_GetCurrentDirectory();
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDL_GetCurrentDisplayMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DisplayID a0 = (SDL_DisplayID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const SDL_DisplayMode * rv = SDL_GetCurrentDisplayMode(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_DisplayMode");
    }
}

static mrb_value GenR_SDL_GetCurrentDisplayOrientation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DisplayID a0 = (SDL_DisplayID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_DisplayOrientation rv = SDL_GetCurrentDisplayOrientation(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetCurrentRenderOutputSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetCurrentRenderOutputSize(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetCurrentTime(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Time io0 = (SDL_Time)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_GetCurrentTime(&io0);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetCurrentVideoDriver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = SDL_GetCurrentVideoDriver();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetCursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Cursor * rv = SDL_GetCursor();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Cursor");
    }
}

static mrb_value GenR_SDL_GetDateTimeLocalePreferences(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DateFormat io0 = (SDL_DateFormat)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_TimeFormat io1 = (SDL_TimeFormat)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetDateTimeLocalePreferences(&io0, &io1);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io0);
    rets[2] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetDayOfWeek(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = SDL_GetDayOfWeek(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetDayOfYear(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = SDL_GetDayOfYear(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetDaysInMonth(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDL_GetDaysInMonth(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetDefaultCursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Cursor * rv = SDL_GetDefaultCursor();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Cursor");
    }
}

static mrb_value GenR_SDL_GetDefaultTextureScaleMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_ScaleMode io1 = (SDL_ScaleMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetDefaultTextureScaleMode(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetDesktopDisplayMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DisplayID a0 = (SDL_DisplayID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const SDL_DisplayMode * rv = SDL_GetDesktopDisplayMode(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_DisplayMode");
    }
}

static mrb_value GenR_SDL_GetDisplayBounds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DisplayID a0 = (SDL_DisplayID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetDisplayBounds(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_Rect(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetDisplayContentScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DisplayID a0 = (SDL_DisplayID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float rv = SDL_GetDisplayContentScale(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDL_GetDisplayForPoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Point tmp0;
    const SDL_Point *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_Point(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_DisplayID rv = SDL_GetDisplayForPoint(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetDisplayForRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Rect tmp0;
    const SDL_Rect *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_Rect(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_DisplayID rv = SDL_GetDisplayForRect(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetDisplayForWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_DisplayID rv = SDL_GetDisplayForWindow(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetDisplayName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DisplayID a0 = (SDL_DisplayID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetDisplayName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetDisplayProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DisplayID a0 = (SDL_DisplayID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_PropertiesID rv = SDL_GetDisplayProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetDisplayUsableBounds(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DisplayID a0 = (SDL_DisplayID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetDisplayUsableBounds(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_Rect(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetEnvironment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Environment * rv = SDL_GetEnvironment();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Environment");
    }
}

static mrb_value GenR_SDL_GetEnvironmentVariable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Environment *a0 = (SDL_Environment *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Environment");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDL_GetEnvironmentVariable(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetError(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = SDL_GetError();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetEventDescription(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDL_Event *a0 = (const SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    const char *src1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char *a1 = SDL_strdup(src1 != NULL ? src1 : "");
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = SDL_GetEventDescription(a0, a1, a2);
    SDL_free(a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetFloatProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float rv = SDL_GetFloatProperty(a0, a1, a2);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDL_GetGPUDeviceDriver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    const char * rv = SDL_GetGPUDeviceDriver(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGPUDeviceProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_PropertiesID rv = SDL_GetGPUDeviceProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGPUDriver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetGPUDriver(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGPURendererDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_GPUDevice * rv = SDL_GetGPURendererDevice(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUDevice");
    }
}

static mrb_value GenR_SDL_GetGPUShaderFormats(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUShaderFormat rv = SDL_GetGPUShaderFormats(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGPUSwapchainTextureFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Window");
    SDL_GPUTextureFormat rv = SDL_GetGPUSwapchainTextureFormat(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGPUTextureFormatFromPixelFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PixelFormat a0 = (SDL_PixelFormat)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_GPUTextureFormat rv = SDL_GetGPUTextureFormatFromPixelFormat(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadAppleSFSymbolsNameForAxis(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_GamepadAxis a1 = (SDL_GamepadAxis)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDL_GetGamepadAppleSFSymbolsNameForAxis(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGamepadAppleSFSymbolsNameForButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_GamepadButton a1 = (SDL_GamepadButton)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = SDL_GetGamepadAppleSFSymbolsNameForButton(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGamepadAxis(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_GamepadAxis a1 = (SDL_GamepadAxis)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 rv = SDL_GetGamepadAxis(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadAxisFromString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_GamepadAxis rv = SDL_GetGamepadAxisFromString(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_GamepadButton a1 = (SDL_GamepadButton)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetGamepadButton(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetGamepadButtonFromString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_GamepadButton rv = SDL_GetGamepadButtonFromString(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadButtonLabel(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_GamepadButton a1 = (SDL_GamepadButton)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GamepadButtonLabel rv = SDL_GetGamepadButtonLabel(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadButtonLabelForType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GamepadType a0 = (SDL_GamepadType)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_GamepadButton a1 = (SDL_GamepadButton)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_GamepadButtonLabel rv = SDL_GetGamepadButtonLabelForType(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadConnectionState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_JoystickConnectionState rv = SDL_GetGamepadConnectionState(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadFirmwareVersion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    Uint16 rv = SDL_GetGamepadFirmwareVersion(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadFromID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Gamepad * rv = SDL_GetGamepadFromID(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Gamepad");
    }
}

static mrb_value GenR_SDL_GetGamepadFromPlayerIndex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Gamepad * rv = SDL_GetGamepadFromPlayerIndex(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Gamepad");
    }
}

static mrb_value GenR_SDL_GetGamepadGUIDForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_GUID rv = SDL_GetGamepadGUIDForID(a0);
    return GenPush_SDL_GUID(mrb, &rv);
    }
}

static mrb_value GenR_SDL_GetGamepadID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_JoystickID rv = SDL_GetGamepadID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadJoystick(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_Joystick * rv = SDL_GetGamepadJoystick(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Joystick");
    }
}

static mrb_value GenR_SDL_GetGamepadMapping(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    char * rv = SDL_GetGamepadMapping(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDL_GetGamepadMappingForGUID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GUID a0;
    GenRead_SDL_GUID(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    char * rv = SDL_GetGamepadMappingForGUID(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDL_GetGamepadMappingForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    char * rv = SDL_GetGamepadMappingForID(a0);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDL_GetGamepadName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    const char * rv = SDL_GetGamepadName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGamepadNameForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetGamepadNameForID(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGamepadPath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    const char * rv = SDL_GetGamepadPath(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGamepadPathForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetGamepadPathForID(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGamepadPlayerIndex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    int rv = SDL_GetGamepadPlayerIndex(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadPlayerIndexForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = SDL_GetGamepadPlayerIndexForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadPowerInfo(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PowerState rv = SDL_GetGamepadPowerInfo(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetGamepadProduct(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    Uint16 rv = SDL_GetGamepadProduct(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadProductForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint16 rv = SDL_GetGamepadProductForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadProductVersion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    Uint16 rv = SDL_GetGamepadProductVersion(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadProductVersionForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint16 rv = SDL_GetGamepadProductVersionForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_PropertiesID rv = SDL_GetGamepadProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadSensorData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_SensorType a1 = (SDL_SensorType)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_GetGamepadSensorData(a0, a1, &io2, a3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetGamepadSensorDataRate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_SensorType a1 = (SDL_SensorType)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float rv = SDL_GetGamepadSensorDataRate(a0, a1);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadSerial(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    const char * rv = SDL_GetGamepadSerial(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGamepadSteamHandle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    Uint64 rv = SDL_GetGamepadSteamHandle(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadStringForAxis(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GamepadAxis a0 = (SDL_GamepadAxis)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetGamepadStringForAxis(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGamepadStringForButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GamepadButton a0 = (SDL_GamepadButton)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetGamepadStringForButton(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGamepadStringForType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GamepadType a0 = (SDL_GamepadType)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetGamepadStringForType(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetGamepadTouchpadFinger(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool io3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float io5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float io6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = SDL_GetGamepadTouchpadFinger(a0, a1, a2, &io3, &io4, &io5, &io6);
    mrb_value rets[5];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_bool_value((mrb_bool)(io3 != 0));
    rets[2] = mrb_float_value(mrb, (mrb_float)io4);
    rets[3] = mrb_float_value(mrb, (mrb_float)io5);
    rets[4] = mrb_float_value(mrb, (mrb_float)io6);
    return mrb_ary_new_from_values(mrb, 5, rets);
    }
}

static mrb_value GenR_SDL_GetGamepadType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_GamepadType rv = SDL_GetGamepadType(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadTypeForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_GamepadType rv = SDL_GetGamepadTypeForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadTypeFromString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_GamepadType rv = SDL_GetGamepadTypeFromString(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadVendor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    Uint16 rv = SDL_GetGamepadVendor(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGamepadVendorForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint16 rv = SDL_GetGamepadVendorForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGlobalMouseState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float io0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_MouseButtonFlags rv = SDL_GetGlobalMouseState(&io0, &io1);
    mrb_value rets[3];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_float_value(mrb, (mrb_float)io0);
    rets[2] = mrb_float_value(mrb, (mrb_float)io1);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetGlobalProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID rv = SDL_GetGlobalProperties();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetGrabbedWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window * rv = SDL_GetGrabbedWindow();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Window");
    }
}

static mrb_value GenR_SDL_GetHapticEffectStatus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    SDL_HapticEffectID a1 = (SDL_HapticEffectID)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetHapticEffectStatus(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetHapticFeatures(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    Uint32 rv = SDL_GetHapticFeatures(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetHapticFromID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_HapticID a0 = (SDL_HapticID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Haptic * rv = SDL_GetHapticFromID(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Haptic");
    }
}

static mrb_value GenR_SDL_GetHapticID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    SDL_HapticID rv = SDL_GetHapticID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetHapticName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    const char * rv = SDL_GetHapticName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetHapticNameForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_HapticID a0 = (SDL_HapticID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetHapticNameForID(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetHint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetHint(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetHintBoolean(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetHintBoolean(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetIOProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_PropertiesID rv = SDL_GetIOProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetIOSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint64 rv = SDL_GetIOSize(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetIOStatus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    SDL_IOStatus rv = SDL_GetIOStatus(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickAxis(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 rv = SDL_GetJoystickAxis(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickAxisInitialState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 io2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetJoystickAxisInitialState(a0, a1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetJoystickBall(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_GetJoystickBall(a0, a1, &io2, &io3);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    rets[2] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetJoystickButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetJoystickButton(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetJoystickConnectionState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    SDL_JoystickConnectionState rv = SDL_GetJoystickConnectionState(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickFirmwareVersion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    Uint16 rv = SDL_GetJoystickFirmwareVersion(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickFromID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Joystick * rv = SDL_GetJoystickFromID(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Joystick");
    }
}

static mrb_value GenR_SDL_GetJoystickFromPlayerIndex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Joystick * rv = SDL_GetJoystickFromPlayerIndex(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Joystick");
    }
}

static mrb_value GenR_SDL_GetJoystickGUID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    SDL_GUID rv = SDL_GetJoystickGUID(a0);
    return GenPush_SDL_GUID(mrb, &rv);
    }
}

static mrb_value GenR_SDL_GetJoystickGUIDForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_GUID rv = SDL_GetJoystickGUIDForID(a0);
    return GenPush_SDL_GUID(mrb, &rv);
    }
}

static mrb_value GenR_SDL_GetJoystickGUIDInfo(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GUID a0;
    GenRead_SDL_GUID(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &a0);
    Uint16 io1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint16 io2 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint16 io3 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint16 io4 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_GetJoystickGUIDInfo(a0, &io1, &io2, &io3, &io4);
    mrb_value rets[4];
    rets[0] = mrb_int_value(mrb, (mrb_int)io1);
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    rets[2] = mrb_int_value(mrb, (mrb_int)io3);
    rets[3] = mrb_int_value(mrb, (mrb_int)io4);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_SDL_GetJoystickHat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 rv = SDL_GetJoystickHat(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    SDL_JoystickID rv = SDL_GetJoystickID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    const char * rv = SDL_GetJoystickName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetJoystickNameForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetJoystickNameForID(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetJoystickPath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    const char * rv = SDL_GetJoystickPath(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetJoystickPathForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetJoystickPathForID(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetJoystickPlayerIndex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int rv = SDL_GetJoystickPlayerIndex(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickPlayerIndexForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = SDL_GetJoystickPlayerIndexForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickPowerInfo(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PowerState rv = SDL_GetJoystickPowerInfo(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetJoystickProduct(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    Uint16 rv = SDL_GetJoystickProduct(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickProductForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint16 rv = SDL_GetJoystickProductForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickProductVersion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    Uint16 rv = SDL_GetJoystickProductVersion(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickProductVersionForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint16 rv = SDL_GetJoystickProductVersionForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    SDL_PropertiesID rv = SDL_GetJoystickProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickSerial(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    const char * rv = SDL_GetJoystickSerial(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetJoystickType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    SDL_JoystickType rv = SDL_GetJoystickType(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickTypeForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_JoystickType rv = SDL_GetJoystickTypeForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickVendor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    Uint16 rv = SDL_GetJoystickVendor(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetJoystickVendorForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint16 rv = SDL_GetJoystickVendorForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetKeyFromName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Keycode rv = SDL_GetKeyFromName(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetKeyFromScancode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Scancode a0 = (SDL_Scancode)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Keymod a1 = (SDL_Keymod)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Keycode rv = SDL_GetKeyFromScancode(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetKeyName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Keycode a0 = (SDL_Keycode)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetKeyName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetKeyboardFocus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window * rv = SDL_GetKeyboardFocus();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Window");
    }
}

static mrb_value GenR_SDL_GetKeyboardNameForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_KeyboardID a0 = (SDL_KeyboardID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetKeyboardNameForID(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetLogPriority(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_LogPriority rv = SDL_GetLogPriority(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetMasksForPixelFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PixelFormat a0 = (SDL_PixelFormat)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 io2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 io3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 io4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 io5 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    bool rv = SDL_GetMasksForPixelFormat(a0, &io1, &io2, &io3, &io4, &io5);
    mrb_value rets[6];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    rets[3] = mrb_int_value(mrb, (mrb_int)io3);
    rets[4] = mrb_int_value(mrb, (mrb_int)io4);
    rets[5] = mrb_int_value(mrb, (mrb_int)io5);
    return mrb_ary_new_from_values(mrb, 6, rets);
    }
}

static mrb_value GenR_SDL_GetMaxHapticEffects(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    int rv = SDL_GetMaxHapticEffects(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetMaxHapticEffectsPlaying(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    int rv = SDL_GetMaxHapticEffectsPlaying(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetModState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Keymod rv = SDL_GetModState();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetMouseFocus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window * rv = SDL_GetMouseFocus();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Window");
    }
}

static mrb_value GenR_SDL_GetMouseNameForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_MouseID a0 = (SDL_MouseID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetMouseNameForID(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetMouseState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float io0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_MouseButtonFlags rv = SDL_GetMouseState(&io0, &io1);
    mrb_value rets[3];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_float_value(mrb, (mrb_float)io0);
    rets[2] = mrb_float_value(mrb, (mrb_float)io1);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetNaturalDisplayOrientation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DisplayID a0 = (SDL_DisplayID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_DisplayOrientation rv = SDL_GetNaturalDisplayOrientation(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumAllocations(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_GetNumAllocations();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumAudioDrivers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_GetNumAudioDrivers();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumCameraDrivers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_GetNumCameraDrivers();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumGPUDrivers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_GetNumGPUDrivers();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumGamepadTouchpadFingers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDL_GetNumGamepadTouchpadFingers(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumGamepadTouchpads(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    int rv = SDL_GetNumGamepadTouchpads(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumHapticAxes(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    int rv = SDL_GetNumHapticAxes(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumJoystickAxes(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int rv = SDL_GetNumJoystickAxes(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumJoystickBalls(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int rv = SDL_GetNumJoystickBalls(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumJoystickButtons(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int rv = SDL_GetNumJoystickButtons(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumJoystickHats(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int rv = SDL_GetNumJoystickHats(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumLogicalCPUCores(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_GetNumLogicalCPUCores();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumRenderDrivers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_GetNumRenderDrivers();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumVideoDrivers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_GetNumVideoDrivers();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetNumberProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint64 a2 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint64 rv = SDL_GetNumberProperty(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetPathInfo(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_PathInfo out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetPathInfo(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_PathInfo(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetPenDeviceType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PenID a0 = (SDL_PenID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_PenDeviceType rv = SDL_GetPenDeviceType(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetPerformanceCounter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint64 rv = SDL_GetPerformanceCounter();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetPerformanceFrequency(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint64 rv = SDL_GetPerformanceFrequency();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetPixelFormatForMasks(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_PixelFormat rv = SDL_GetPixelFormatForMasks(a0, a1, a2, a3, a4);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetPixelFormatFromGPUTextureFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUTextureFormat a0 = (SDL_GPUTextureFormat)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_PixelFormat rv = SDL_GetPixelFormatFromGPUTextureFormat(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetPixelFormatName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PixelFormat a0 = (SDL_PixelFormat)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetPixelFormatName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetPlatform(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = SDL_GetPlatform();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetPowerInfo(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int io0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PowerState rv = SDL_GetPowerInfo(&io0, &io1);
    mrb_value rets[3];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io0);
    rets[2] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetPrefPath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char * rv = SDL_GetPrefPath(a0, a1);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDL_GetPrimaryDisplay(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_DisplayID rv = SDL_GetPrimaryDisplay();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetPrimarySelectionText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    char * rv = SDL_GetPrimarySelectionText();
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDL_GetProcessInput(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Process");
    SDL_IOStream * rv = SDL_GetProcessInput(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_IOStream");
    }
}

static mrb_value GenR_SDL_GetProcessOutput(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Process");
    SDL_IOStream * rv = SDL_GetProcessOutput(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_IOStream");
    }
}

static mrb_value GenR_SDL_GetProcessProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Process");
    SDL_PropertiesID rv = SDL_GetProcessProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetPropertyType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PropertyType rv = SDL_GetPropertyType(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetRGB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_PixelFormatDetails tmp1;
    const SDL_PixelFormatDetails *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_PixelFormatDetails(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    const SDL_Palette *a2 = (const SDL_Palette *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_Palette");
    Uint8 io3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 io4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 io5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    SDL_GetRGB(a0, a1, a2, &io3, &io4, &io5);
    mrb_value rets[3];
    rets[0] = mrb_int_value(mrb, (mrb_int)io3);
    rets[1] = mrb_int_value(mrb, (mrb_int)io4);
    rets[2] = mrb_int_value(mrb, (mrb_int)io5);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_PixelFormatDetails tmp1;
    const SDL_PixelFormatDetails *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_PixelFormatDetails(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    const SDL_Palette *a2 = (const SDL_Palette *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_Palette");
    Uint8 io3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 io4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 io5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 io6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    SDL_GetRGBA(a0, a1, a2, &io3, &io4, &io5, &io6);
    mrb_value rets[4];
    rets[0] = mrb_int_value(mrb, (mrb_int)io3);
    rets[1] = mrb_int_value(mrb, (mrb_int)io4);
    rets[2] = mrb_int_value(mrb, (mrb_int)io5);
    rets[3] = mrb_int_value(mrb, (mrb_int)io6);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_SDL_GetRealGamepadType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_GamepadType rv = SDL_GetRealGamepadType(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetRealGamepadTypeForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_GamepadType rv = SDL_GetRealGamepadTypeForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetRectAndLineIntersection(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Rect tmp0;
    const SDL_Rect *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_Rect(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int io4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_GetRectAndLineIntersection(a0, &io1, &io2, &io3, &io4);
    mrb_value rets[5];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    rets[3] = mrb_int_value(mrb, (mrb_int)io3);
    rets[4] = mrb_int_value(mrb, (mrb_int)io4);
    return mrb_ary_new_from_values(mrb, 5, rets);
    }
}

static mrb_value GenR_SDL_GetRectAndLineIntersectionFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_FRect tmp0;
    const SDL_FRect *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_FRect(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_GetRectAndLineIntersectionFloat(a0, &io1, &io2, &io3, &io4);
    mrb_value rets[5];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    rets[3] = mrb_float_value(mrb, (mrb_float)io3);
    rets[4] = mrb_float_value(mrb, (mrb_float)io4);
    return mrb_ary_new_from_values(mrb, 5, rets);
    }
}

static mrb_value GenR_SDL_GetRectEnclosingPoints(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Point tmp0;
    const SDL_Point *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_Point(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Rect tmp2;
    const SDL_Rect *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_Rect(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    SDL_Rect out3;
    memset(&out3, 0, sizeof(out3));
    bool rv = SDL_GetRectEnclosingPoints(a0, a1, a2, &out3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_Rect(mrb, &out3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRectEnclosingPointsFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_FPoint tmp0;
    const SDL_FPoint *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_FPoint(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_FRect(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    SDL_FRect out3;
    memset(&out3, 0, sizeof(out3));
    bool rv = SDL_GetRectEnclosingPointsFloat(a0, a1, a2, &out3);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_FRect(mrb, &out3);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRectIntersection(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Rect tmp0;
    const SDL_Rect *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_Rect(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_Rect out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetRectIntersection(a0, a1, &out2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_Rect(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRectIntersectionFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_FRect tmp0;
    const SDL_FRect *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_FRect(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_FRect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_FRect out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetRectIntersectionFloat(a0, a1, &out2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_FRect(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRectUnion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Rect tmp0;
    const SDL_Rect *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_Rect(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_Rect out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetRectUnion(a0, a1, &out2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_Rect(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRectUnionFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_FRect tmp0;
    const SDL_FRect *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_FRect(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_FRect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_FRect out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetRectUnionFloat(a0, a1, &out2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_FRect(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRelativeMouseState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float io0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_MouseButtonFlags rv = SDL_GetRelativeMouseState(&io0, &io1);
    mrb_value rets[3];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_float_value(mrb, (mrb_float)io0);
    rets[2] = mrb_float_value(mrb, (mrb_float)io1);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetRenderClipRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetRenderClipRect(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_Rect(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRenderColorScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetRenderColorScale(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRenderDrawBlendMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_BlendMode io1 = (SDL_BlendMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetRenderDrawBlendMode(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRenderDrawColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Uint8 io1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 io2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 io3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 io4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_GetRenderDrawColor(a0, &io1, &io2, &io3, &io4);
    mrb_value rets[5];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    rets[3] = mrb_int_value(mrb, (mrb_int)io3);
    rets[4] = mrb_int_value(mrb, (mrb_int)io4);
    return mrb_ary_new_from_values(mrb, 5, rets);
    }
}

static mrb_value GenR_SDL_GetRenderDrawColorFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_GetRenderDrawColorFloat(a0, &io1, &io2, &io3, &io4);
    mrb_value rets[5];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    rets[3] = mrb_float_value(mrb, (mrb_float)io3);
    rets[4] = mrb_float_value(mrb, (mrb_float)io4);
    return mrb_ary_new_from_values(mrb, 5, rets);
    }
}

static mrb_value GenR_SDL_GetRenderDriver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetRenderDriver(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetRenderLogicalPresentation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_RendererLogicalPresentation io3 = (SDL_RendererLogicalPresentation)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_GetRenderLogicalPresentation(a0, &io1, &io2, &io3);
    mrb_value rets[4];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    rets[3] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_SDL_GetRenderLogicalPresentationRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_FRect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetRenderLogicalPresentationRect(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_FRect(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRenderOutputSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetRenderOutputSize(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetRenderSafeArea(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetRenderSafeArea(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_Rect(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRenderScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetRenderScale(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetRenderTarget(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Texture * rv = SDL_GetRenderTarget(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Texture");
    }
}

static mrb_value GenR_SDL_GetRenderTextureAddressMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_TextureAddressMode io1 = (SDL_TextureAddressMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_TextureAddressMode io2 = (SDL_TextureAddressMode)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetRenderTextureAddressMode(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetRenderVSync(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetRenderVSync(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRenderViewport(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetRenderViewport(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_Rect(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetRenderWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Window * rv = SDL_GetRenderWindow(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Window");
    }
}

static mrb_value GenR_SDL_GetRenderer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_Renderer * rv = SDL_GetRenderer(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Renderer");
    }
}

static mrb_value GenR_SDL_GetRendererFromTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    SDL_Renderer * rv = SDL_GetRendererFromTexture(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Renderer");
    }
}

static mrb_value GenR_SDL_GetRendererName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    const char * rv = SDL_GetRendererName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetRendererProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_PropertiesID rv = SDL_GetRendererProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetRevision(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = SDL_GetRevision();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetSIMDAlignment(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t rv = SDL_GetSIMDAlignment();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetSandbox(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Sandbox rv = SDL_GetSandbox();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetScancodeFromKey(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Keycode a0 = (SDL_Keycode)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Keymod io1 = (SDL_Keymod)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Scancode rv = SDL_GetScancodeFromKey(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetScancodeFromName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Scancode rv = SDL_GetScancodeFromName(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetScancodeName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Scancode a0 = (SDL_Scancode)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetScancodeName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetSensorData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Sensor");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetSensorData(a0, &io1, a2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetSensorFromID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_SensorID a0 = (SDL_SensorID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Sensor * rv = SDL_GetSensorFromID(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Sensor");
    }
}

static mrb_value GenR_SDL_GetSensorID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Sensor");
    SDL_SensorID rv = SDL_GetSensorID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetSensorName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Sensor");
    const char * rv = SDL_GetSensorName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetSensorNameForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_SensorID a0 = (SDL_SensorID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetSensorNameForID(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetSensorNonPortableType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Sensor");
    int rv = SDL_GetSensorNonPortableType(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetSensorNonPortableTypeForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_SensorID a0 = (SDL_SensorID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = SDL_GetSensorNonPortableTypeForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetSensorProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Sensor");
    SDL_PropertiesID rv = SDL_GetSensorProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetSensorType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Sensor *a0 = (SDL_Sensor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Sensor");
    SDL_SensorType rv = SDL_GetSensorType(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetSensorTypeForID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_SensorID a0 = (SDL_SensorID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_SensorType rv = SDL_GetSensorTypeForID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetSilenceValueForFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioFormat a0 = (SDL_AudioFormat)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = SDL_GetSilenceValueForFormat(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetStorageFileSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Storage");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint64 io2 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetStorageFileSize(a0, a1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetStoragePathInfo(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Storage");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PathInfo out2;
    memset(&out2, 0, sizeof(out2));
    bool rv = SDL_GetStoragePathInfo(a0, a1, &out2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_PathInfo(mrb, &out2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetStorageSpaceRemaining(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Storage");
    Uint64 rv = SDL_GetStorageSpaceRemaining(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetStringProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    const char * rv = SDL_GetStringProperty(a0, a1, a2);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetSurfaceAlphaMod(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    Uint8 io1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetSurfaceAlphaMod(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetSurfaceBlendMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_BlendMode io1 = (SDL_BlendMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetSurfaceBlendMode(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetSurfaceClipRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetSurfaceClipRect(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_Rect(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetSurfaceColorKey(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    Uint32 io1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetSurfaceColorKey(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetSurfaceColorMod(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    Uint8 io1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 io2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 io3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_GetSurfaceColorMod(a0, &io1, &io2, &io3);
    mrb_value rets[4];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    rets[3] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_SDL_GetSurfaceColorspace(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Colorspace rv = SDL_GetSurfaceColorspace(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetSurfacePalette(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Palette * rv = SDL_GetSurfacePalette(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Palette");
    }
}

static mrb_value GenR_SDL_GetSurfaceProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_PropertiesID rv = SDL_GetSurfaceProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetSystemPageSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_GetSystemPageSize();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetSystemRAM(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_GetSystemRAM();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetSystemTheme(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_SystemTheme rv = SDL_GetSystemTheme();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetTextInputArea(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetTextInputArea(a0, &out1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_Rect(mrb, &out1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetTextureAlphaMod(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    Uint8 io1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetTextureAlphaMod(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetTextureAlphaModFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetTextureAlphaModFloat(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetTextureBlendMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    SDL_BlendMode io1 = (SDL_BlendMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetTextureBlendMode(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetTextureColorMod(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    Uint8 io1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 io2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 io3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_GetTextureColorMod(a0, &io1, &io2, &io3);
    mrb_value rets[4];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    rets[3] = mrb_int_value(mrb, (mrb_int)io3);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_SDL_GetTextureColorModFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_GetTextureColorModFloat(a0, &io1, &io2, &io3);
    mrb_value rets[4];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    rets[3] = mrb_float_value(mrb, (mrb_float)io3);
    return mrb_ary_new_from_values(mrb, 4, rets);
    }
}

static mrb_value GenR_SDL_GetTexturePalette(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    SDL_Palette * rv = SDL_GetTexturePalette(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Palette");
    }
}

static mrb_value GenR_SDL_GetTextureProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    SDL_PropertiesID rv = SDL_GetTextureProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetTextureScaleMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    SDL_ScaleMode io1 = (SDL_ScaleMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetTextureScaleMode(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetTextureSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetTextureSize(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetTicks(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint64 rv = SDL_GetTicks();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetTicksNS(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint64 rv = SDL_GetTicksNS();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetTouchDeviceName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TouchID a0 = (SDL_TouchID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetTouchDeviceName(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetTouchDeviceType(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TouchID a0 = (SDL_TouchID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_TouchDeviceType rv = SDL_GetTouchDeviceType(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetTrayEntryChecked(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayEntry");
    bool rv = SDL_GetTrayEntryChecked(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetTrayEntryEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayEntry");
    bool rv = SDL_GetTrayEntryEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetTrayEntryLabel(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayEntry");
    const char * rv = SDL_GetTrayEntryLabel(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetTrayEntryParent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayEntry");
    SDL_TrayMenu * rv = SDL_GetTrayEntryParent(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_TrayMenu");
    }
}

static mrb_value GenR_SDL_GetTrayMenu(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Tray *a0 = (SDL_Tray *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Tray");
    SDL_TrayMenu * rv = SDL_GetTrayMenu(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_TrayMenu");
    }
}

static mrb_value GenR_SDL_GetTrayMenuParentEntry(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayMenu *a0 = (SDL_TrayMenu *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayMenu");
    SDL_TrayEntry * rv = SDL_GetTrayMenuParentEntry(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_TrayEntry");
    }
}

static mrb_value GenR_SDL_GetTrayMenuParentTray(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayMenu *a0 = (SDL_TrayMenu *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayMenu");
    SDL_Tray * rv = SDL_GetTrayMenuParentTray(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Tray");
    }
}

static mrb_value GenR_SDL_GetTraySubmenu(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayEntry");
    SDL_TrayMenu * rv = SDL_GetTraySubmenu(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_TrayMenu");
    }
}

static mrb_value GenR_SDL_GetUserFolder(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Folder a0 = (SDL_Folder)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetUserFolder(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetVersion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_GetVersion();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetVideoDriver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_GetVideoDriver(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_GetWindowAspectRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    float io1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float io2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetWindowAspectRatio(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io1);
    rets[2] = mrb_float_value(mrb, (mrb_float)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetWindowBordersSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int io3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int io4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_GetWindowBordersSize(a0, &io1, &io2, &io3, &io4);
    mrb_value rets[5];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    rets[3] = mrb_int_value(mrb, (mrb_int)io3);
    rets[4] = mrb_int_value(mrb, (mrb_int)io4);
    return mrb_ary_new_from_values(mrb, 5, rets);
    }
}

static mrb_value GenR_SDL_GetWindowDisplayScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    float rv = SDL_GetWindowDisplayScale(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDL_GetWindowFlags(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_WindowFlags rv = SDL_GetWindowFlags(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetWindowFromEvent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDL_Event *a0 = (const SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    SDL_Window * rv = SDL_GetWindowFromEvent(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Window");
    }
}

static mrb_value GenR_SDL_GetWindowFromID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_WindowID a0 = (SDL_WindowID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Window * rv = SDL_GetWindowFromID(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Window");
    }
}

static mrb_value GenR_SDL_GetWindowFullscreenMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    const SDL_DisplayMode * rv = SDL_GetWindowFullscreenMode(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_DisplayMode");
    }
}

static mrb_value GenR_SDL_GetWindowID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_WindowID rv = SDL_GetWindowID(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetWindowKeyboardGrab(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_GetWindowKeyboardGrab(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetWindowMaximumSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetWindowMaximumSize(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetWindowMinimumSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetWindowMinimumSize(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetWindowMouseGrab(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_GetWindowMouseGrab(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetWindowOpacity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    float rv = SDL_GetWindowOpacity(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDL_GetWindowParent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_Window * rv = SDL_GetWindowParent(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Window");
    }
}

static mrb_value GenR_SDL_GetWindowPixelDensity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    float rv = SDL_GetWindowPixelDensity(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDL_GetWindowPixelFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_PixelFormat rv = SDL_GetWindowPixelFormat(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetWindowPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetWindowPosition(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetWindowProgressState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_ProgressState rv = SDL_GetWindowProgressState(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetWindowProgressValue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    float rv = SDL_GetWindowProgressValue(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_SDL_GetWindowProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_PropertiesID rv = SDL_GetWindowProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_GetWindowRelativeMouseMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_GetWindowRelativeMouseMode(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_GetWindowSafeArea(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_Rect out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = SDL_GetWindowSafeArea(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_Rect(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetWindowSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetWindowSize(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetWindowSizeInPixels(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_GetWindowSizeInPixels(a0, &io1, &io2);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    rets[2] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_GetWindowSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_Surface * rv = SDL_GetWindowSurface(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_SDL_GetWindowSurfaceVSync(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_GetWindowSurfaceVSync(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_GetWindowTitle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    const char * rv = SDL_GetWindowTitle(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_HapticEffectSupported(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    const SDL_HapticEffect *a1 = (const SDL_HapticEffect *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_HapticEffect");
    bool rv = SDL_HapticEffectSupported(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HapticRumbleSupported(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    bool rv = SDL_HapticRumbleSupported(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasARMSIMD(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasARMSIMD();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasAVX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasAVX();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasAVX2(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasAVX2();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasAVX512F(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasAVX512F();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasAltiVec(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasAltiVec();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasClipboardData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_HasClipboardData(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasClipboardText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasClipboardText();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasEvent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_HasEvent(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_HasEvents(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasGamepad(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasGamepad();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasJoystick(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasJoystick();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasKeyboard(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasKeyboard();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasLASX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasLASX();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasLSX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasLSX();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasMMX(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasMMX();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasMouse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasMouse();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasNEON(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasNEON();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasPrimarySelectionText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasPrimarySelectionText();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_HasProperty(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasRectIntersection(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Rect tmp0;
    const SDL_Rect *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_Rect(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_HasRectIntersection(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasRectIntersectionFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_FRect tmp0;
    const SDL_FRect *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_FRect(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_FRect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_HasRectIntersectionFloat(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasSSE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasSSE();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasSSE2(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasSSE2();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasSSE3(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasSSE3();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasSSE41(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasSSE41();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasSSE42(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasSSE42();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HasScreenKeyboardSupport(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HasScreenKeyboardSupport();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HideCursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_HideCursor();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_HideWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_HideWindow(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_IOFromConstMem(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    size_t len0 = 0;
    const char *a0 = SDLStaticGen_RubyToBlob(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), &len0);
    SDL_IOStream * rv = SDL_IOFromConstMem((const void *)a0, (size_t)len0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_IOStream", GenDtor_SDL_CloseIO);
    }
}

static mrb_value GenR_SDL_IOFromDynamicMem(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream * rv = SDL_IOFromDynamicMem();
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_IOStream", GenDtor_SDL_CloseIO);
    }
}

static mrb_value GenR_SDL_IOFromFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_IOStream * rv = SDL_IOFromFile(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_IOStream", GenDtor_SDL_CloseIO);
    }
}

static mrb_value GenR_SDL_Init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_InitFlags a0 = (SDL_InitFlags)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_Init(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_InitHapticRumble(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    bool rv = SDL_InitHapticRumble(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_InitSubSystem(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_InitFlags a0 = (SDL_InitFlags)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_InitSubSystem(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_InsertGPUDebugLabel(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_InsertGPUDebugLabel(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_InsertTrayEntryAt(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayMenu *a0 = (SDL_TrayMenu *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayMenu");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_TrayEntryFlags a3 = (SDL_TrayEntryFlags)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_TrayEntry * rv = SDL_InsertTrayEntryAt(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_TrayEntry");
    }
}

static mrb_value GenR_SDL_IsAudioDevicePhysical(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_IsAudioDevicePhysical(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_IsAudioDevicePlayback(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_IsAudioDevicePlayback(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_IsGamepad(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_IsGamepad(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_IsJoystickHaptic(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    bool rv = SDL_IsJoystickHaptic(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_IsJoystickVirtual(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_IsJoystickVirtual(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_IsMainThread(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_IsMainThread();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_IsMouseHaptic(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_IsMouseHaptic();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_IsTV(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_IsTV();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_IsTablet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_IsTablet();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_JoystickConnected(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    bool rv = SDL_JoystickConnected(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_JoystickEventsEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_JoystickEventsEnabled();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_KillProcess(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Process");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_KillProcess(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_LoadBMP(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Surface * rv = SDL_LoadBMP(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_SDL_LoadBMP_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Surface * rv = SDL_LoadBMP_IO(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_SDL_LoadObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_SharedObject * rv = SDL_LoadObject(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_SharedObject", GenDtor_SDL_UnloadObject);
    }
}

static mrb_value GenR_SDL_LoadPNG(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Surface * rv = SDL_LoadPNG(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_SDL_LoadPNG_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Surface * rv = SDL_LoadPNG_IO(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_SDL_LoadSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Surface * rv = SDL_LoadSurface(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_SDL_LoadSurface_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Surface * rv = SDL_LoadSurface_IO(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_SDL_LockAudioStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    bool rv = SDL_LockAudioStream(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_LockProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_LockProperties(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_LockSpinlock(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_SpinLock io0 = (SDL_SpinLock)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_LockSpinlock(&io0);
    return mrb_int_value(mrb, (mrb_int)io0);
    }
}

static mrb_value GenR_SDL_LockSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    bool rv = SDL_LockSurface(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_MapRGB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PixelFormatDetails tmp0;
    const SDL_PixelFormatDetails *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_PixelFormatDetails(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    const SDL_Palette *a1 = (const SDL_Palette *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Palette");
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 rv = SDL_MapRGB(a0, a1, a2, a3, a4);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_MapRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PixelFormatDetails tmp0;
    const SDL_PixelFormatDetails *a0 = NULL;
    if (argc > 0 && mrb_hash_p(argv[0])) {
        GenRead_SDL_PixelFormatDetails(mrb, argv[0], &tmp0);
        a0 = &tmp0;
    }
    const SDL_Palette *a1 = (const SDL_Palette *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Palette");
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint32 rv = SDL_MapRGBA(a0, a1, a2, a3, a4, a5);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_MapSurfaceRGB(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 rv = SDL_MapSurfaceRGB(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_MapSurfaceRGBA(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint32 rv = SDL_MapSurfaceRGBA(a0, a1, a2, a3, a4);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_MaximizeWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_MaximizeWindow(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_MinimizeWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_MinimizeWindow(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_OnApplicationDidEnterBackground(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_OnApplicationDidEnterBackground();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_OnApplicationDidEnterForeground(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_OnApplicationDidEnterForeground();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_OnApplicationDidReceiveMemoryWarning(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_OnApplicationDidReceiveMemoryWarning();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_OnApplicationWillEnterBackground(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_OnApplicationWillEnterBackground();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_OnApplicationWillEnterForeground(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_OnApplicationWillEnterForeground();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_OnApplicationWillTerminate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_OnApplicationWillTerminate();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_OpenAudioDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_AudioSpec tmp1;
    const SDL_AudioSpec *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_AudioSpec(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_AudioDeviceID rv = SDL_OpenAudioDevice(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_OpenCamera(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_CameraID a0 = (SDL_CameraID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_CameraSpec tmp1;
    const SDL_CameraSpec *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_CameraSpec(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_Camera * rv = SDL_OpenCamera(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Camera", GenDtor_SDL_CloseCamera);
    }
}

static mrb_value GenR_SDL_OpenFileStorage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Storage * rv = SDL_OpenFileStorage(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Storage", GenDtor_SDL_CloseStorage);
    }
}

static mrb_value GenR_SDL_OpenGamepad(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Gamepad * rv = SDL_OpenGamepad(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Gamepad", GenDtor_SDL_CloseGamepad);
    }
}

static mrb_value GenR_SDL_OpenHaptic(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_HapticID a0 = (SDL_HapticID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Haptic * rv = SDL_OpenHaptic(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Haptic", GenDtor_SDL_CloseHaptic);
    }
}

static mrb_value GenR_SDL_OpenHapticFromJoystick(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    SDL_Haptic * rv = SDL_OpenHapticFromJoystick(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Haptic", GenDtor_SDL_CloseHaptic);
    }
}

static mrb_value GenR_SDL_OpenHapticFromMouse(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic * rv = SDL_OpenHapticFromMouse();
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Haptic", GenDtor_SDL_CloseHaptic);
    }
}

static mrb_value GenR_SDL_OpenJoystick(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Joystick * rv = SDL_OpenJoystick(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Joystick", GenDtor_SDL_CloseJoystick);
    }
}

static mrb_value GenR_SDL_OpenSensor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_SensorID a0 = (SDL_SensorID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_Sensor * rv = SDL_OpenSensor(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Sensor", GenDtor_SDL_CloseSensor);
    }
}

static mrb_value GenR_SDL_OpenTitleStorage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_PropertiesID a1 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Storage * rv = SDL_OpenTitleStorage(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Storage", GenDtor_SDL_CloseStorage);
    }
}

static mrb_value GenR_SDL_OpenURL(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_OpenURL(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_OpenUserStorage(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PropertiesID a2 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Storage * rv = SDL_OpenUserStorage(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Storage", GenDtor_SDL_CloseStorage);
    }
}

static mrb_value GenR_SDL_OutOfMemory(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_OutOfMemory();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_PauseAudioDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_PauseAudioDevice(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_PauseAudioStreamDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    bool rv = SDL_PauseAudioStreamDevice(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_PauseHaptic(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    bool rv = SDL_PauseHaptic(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_PeepEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_EventAction a2 = (SDL_EventAction)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint32 a4 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int rv = SDL_PeepEvents(a0, a1, a2, a3, a4);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_PlayHapticRumble(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_PlayHapticRumble(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_PollEvent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    bool rv = SDL_PollEvent(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_PopGPUDebugGroup(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    SDL_PopGPUDebugGroup(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_PremultiplySurfaceAlpha(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_PremultiplySurfaceAlpha(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_PumpEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PumpEvents();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_PushEvent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    bool rv = SDL_PushEvent(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_PushGPUComputeUniformData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t len2 = 0;
    const char *a2 = SDLStaticGen_RubyToBlob(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &len2);
    SDL_PushGPUComputeUniformData(a0, a1, (const void *)a2, (Uint32)len2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_PushGPUDebugGroup(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PushGPUDebugGroup(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_PushGPUFragmentUniformData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t len2 = 0;
    const char *a2 = SDLStaticGen_RubyToBlob(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &len2);
    SDL_PushGPUFragmentUniformData(a0, a1, (const void *)a2, (Uint32)len2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_PushGPUVertexUniformData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t len2 = 0;
    const char *a2 = SDLStaticGen_RubyToBlob(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &len2);
    SDL_PushGPUVertexUniformData(a0, a1, (const void *)a2, (Uint32)len2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_PutAudioStreamData(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    bool rv = SDL_PutAudioStreamData(a0, (const void *)a1, (int)len1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_QueryGPUFence(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUFence *a1 = (SDL_GPUFence *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUFence");
    bool rv = SDL_QueryGPUFence(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_Quit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Quit();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_QuitSubSystem(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_InitFlags a0 = (SDL_InitFlags)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_QuitSubSystem(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_RaiseWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_RaiseWindow(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ReadS16BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint16 io1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadS16BE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadS16LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint16 io1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadS16LE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadS32BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint32 io1 = (Sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadS32BE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadS32LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint32 io1 = (Sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadS32LE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadS64BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint64 io1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadS64BE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadS64LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint64 io1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadS64LE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadS8(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint8 io1 = (Sint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadS8(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadSurfacePixel(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 io3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 io4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 io5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 io6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = SDL_ReadSurfacePixel(a0, a1, a2, &io3, &io4, &io5, &io6);
    mrb_value rets[5];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io3);
    rets[2] = mrb_int_value(mrb, (mrb_int)io4);
    rets[3] = mrb_int_value(mrb, (mrb_int)io5);
    rets[4] = mrb_int_value(mrb, (mrb_int)io6);
    return mrb_ary_new_from_values(mrb, 5, rets);
    }
}

static mrb_value GenR_SDL_ReadSurfacePixelFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float io5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float io6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = SDL_ReadSurfacePixelFloat(a0, a1, a2, &io3, &io4, &io5, &io6);
    mrb_value rets[5];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io3);
    rets[2] = mrb_float_value(mrb, (mrb_float)io4);
    rets[3] = mrb_float_value(mrb, (mrb_float)io5);
    rets[4] = mrb_float_value(mrb, (mrb_float)io6);
    return mrb_ary_new_from_values(mrb, 5, rets);
    }
}

static mrb_value GenR_SDL_ReadU16BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint16 io1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadU16BE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadU16LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint16 io1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadU16LE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadU32BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint32 io1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadU32BE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadU32LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint32 io1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadU32LE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadU64BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint64 io1 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadU64BE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadU64LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint64 io1 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadU64LE(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ReadU8(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint8 io1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ReadU8(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_RegisterEvents(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint32 rv = SDL_RegisterEvents(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_ReleaseCameraFrame(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Camera *a0 = (SDL_Camera *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Camera");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Surface");
    SDL_ReleaseCameraFrame(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ReleaseGPUBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBuffer");
    SDL_ReleaseGPUBuffer(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ReleaseGPUComputePipeline(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUComputePipeline *a1 = (SDL_GPUComputePipeline *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUComputePipeline");
    SDL_ReleaseGPUComputePipeline(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ReleaseGPUFence(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUFence *a1 = (SDL_GPUFence *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUFence");
    SDL_ReleaseGPUFence(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ReleaseGPUGraphicsPipeline(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUGraphicsPipeline *a1 = (SDL_GPUGraphicsPipeline *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUGraphicsPipeline");
    SDL_ReleaseGPUGraphicsPipeline(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ReleaseGPUSampler(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUSampler *a1 = (SDL_GPUSampler *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUSampler");
    SDL_ReleaseGPUSampler(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ReleaseGPUShader(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUShader *a1 = (SDL_GPUShader *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUShader");
    SDL_ReleaseGPUShader(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ReleaseGPUTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    SDL_ReleaseGPUTexture(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ReleaseGPUTransferBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUTransferBuffer *a1 = (SDL_GPUTransferBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTransferBuffer");
    SDL_ReleaseGPUTransferBuffer(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ReleaseWindowFromGPUDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Window");
    SDL_ReleaseWindowFromGPUDevice(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ReloadGamepadMappings(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_ReloadGamepadMappings();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RemovePath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_RemovePath(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RemoveStoragePath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Storage");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_RemoveStoragePath(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RemoveSurfaceAlternateImages(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_RemoveSurfaceAlternateImages(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_RemoveTimer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TimerID a0 = (SDL_TimerID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_RemoveTimer(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RemoveTrayEntry(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayEntry");
    SDL_RemoveTrayEntry(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_RenamePath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_RenamePath(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenameStoragePath(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Storage");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_RenameStoragePath(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderClear(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    bool rv = SDL_RenderClear(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderClipEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    bool rv = SDL_RenderClipEnabled(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderCoordinatesFromWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_RenderCoordinatesFromWindow(a0, a1, a2, &io3, &io4);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io3);
    rets[2] = mrb_float_value(mrb, (mrb_float)io4);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_RenderCoordinatesToWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float io3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float io4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_RenderCoordinatesToWindow(a0, a1, a2, &io3, &io4);
    mrb_value rets[3];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_float_value(mrb, (mrb_float)io3);
    rets[2] = mrb_float_value(mrb, (mrb_float)io4);
    return mrb_ary_new_from_values(mrb, 3, rets);
    }
}

static mrb_value GenR_SDL_RenderDebugText(mrb_state *mrb, mrb_value self)
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
    bool rv = SDL_RenderDebugText(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderFillRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_FRect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_RenderFillRect(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderFillRects(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_FRect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_RenderFillRects(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderLine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_RenderLine(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderLines(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_FPoint tmp1;
    const SDL_FPoint *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_FPoint(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_RenderLines(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderPoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_RenderPoint(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderPoints(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_FPoint tmp1;
    const SDL_FPoint *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_FPoint(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_RenderPoints(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderPresent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    bool rv = SDL_RenderPresent(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderReadPixels(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface * rv = SDL_RenderReadPixels(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_SDL_RenderRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_FRect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_RenderRect(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderRects(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_FRect tmp1;
    const SDL_FRect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_FRect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_RenderRects(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_FRect(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    SDL_FRect tmp3;
    const SDL_FRect *a3 = NULL;
    if (argc > 3 && mrb_hash_p(argv[3])) {
        GenRead_SDL_FRect(mrb, argv[3], &tmp3);
        a3 = &tmp3;
    }
    bool rv = SDL_RenderTexture(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderTexture9Grid(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_FRect(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    float a7 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    SDL_FRect tmp8;
    const SDL_FRect *a8 = NULL;
    if (argc > 8 && mrb_hash_p(argv[8])) {
        GenRead_SDL_FRect(mrb, argv[8], &tmp8);
        a8 = &tmp8;
    }
    bool rv = SDL_RenderTexture9Grid(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderTexture9GridTiled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_FRect(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    float a7 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 7 ? argv[7] : mrb_nil_value()));
    SDL_FRect tmp8;
    const SDL_FRect *a8 = NULL;
    if (argc > 8 && mrb_hash_p(argv[8])) {
        GenRead_SDL_FRect(mrb, argv[8], &tmp8);
        a8 = &tmp8;
    }
    float a9 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 9 ? argv[9] : mrb_nil_value()));
    bool rv = SDL_RenderTexture9GridTiled(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderTextureAffine(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_FRect(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    SDL_FPoint tmp3;
    const SDL_FPoint *a3 = NULL;
    if (argc > 3 && mrb_hash_p(argv[3])) {
        GenRead_SDL_FPoint(mrb, argv[3], &tmp3);
        a3 = &tmp3;
    }
    SDL_FPoint tmp4;
    const SDL_FPoint *a4 = NULL;
    if (argc > 4 && mrb_hash_p(argv[4])) {
        GenRead_SDL_FPoint(mrb, argv[4], &tmp4);
        a4 = &tmp4;
    }
    SDL_FPoint tmp5;
    const SDL_FPoint *a5 = NULL;
    if (argc > 5 && mrb_hash_p(argv[5])) {
        GenRead_SDL_FPoint(mrb, argv[5], &tmp5);
        a5 = &tmp5;
    }
    bool rv = SDL_RenderTextureAffine(a0, a1, a2, a3, a4, a5);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderTextureRotated(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_FRect(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    SDL_FRect tmp3;
    const SDL_FRect *a3 = NULL;
    if (argc > 3 && mrb_hash_p(argv[3])) {
        GenRead_SDL_FRect(mrb, argv[3], &tmp3);
        a3 = &tmp3;
    }
    double a4 = (double)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    SDL_FPoint tmp5;
    const SDL_FPoint *a5 = NULL;
    if (argc > 5 && mrb_hash_p(argv[5])) {
        GenRead_SDL_FPoint(mrb, argv[5], &tmp5);
        a5 = &tmp5;
    }
    SDL_FlipMode a6 = (SDL_FlipMode)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = SDL_RenderTextureRotated(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderTextureTiled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    SDL_FRect tmp2;
    const SDL_FRect *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_FRect(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_FRect tmp4;
    const SDL_FRect *a4 = NULL;
    if (argc > 4 && mrb_hash_p(argv[4])) {
        GenRead_SDL_FRect(mrb, argv[4], &tmp4);
        a4 = &tmp4;
    }
    bool rv = SDL_RenderTextureTiled(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RenderViewportSet(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    bool rv = SDL_RenderViewportSet(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ResetAssertionReport(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_ResetAssertionReport();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ResetHint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_ResetHint(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ResetHints(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_ResetHints();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ResetKeyboard(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_ResetKeyboard();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_ResetLogPriorities(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_ResetLogPriorities();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_RestoreWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_RestoreWindow(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ResumeAudioDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_ResumeAudioDevice(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ResumeAudioStreamDevice(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    bool rv = SDL_ResumeAudioStreamDevice(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ResumeHaptic(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    bool rv = SDL_ResumeHaptic(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RotateSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Surface * rv = SDL_RotateSurface(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_Surface");
    }
}

static mrb_value GenR_SDL_RumbleGamepad(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    Uint16 a1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint16 a2 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_RumbleGamepad(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RumbleGamepadTriggers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    Uint16 a1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint16 a2 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_RumbleGamepadTriggers(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RumbleJoystick(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    Uint16 a1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint16 a2 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_RumbleJoystick(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RumbleJoystickTriggers(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    Uint16 a1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint16 a2 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint32 a3 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_RumbleJoystickTriggers(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_RunHapticEffect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    SDL_HapticEffectID a1 = (SDL_HapticEffectID)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_RunHapticEffect(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SaveBMP(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SaveBMP(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SaveBMP_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SaveBMP_IO(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SaveFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    bool rv = SDL_SaveFile(a0, (const void *)a1, (size_t)len1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SaveFile_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SaveFile_IO(a0, (const void *)a1, (size_t)len1, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SavePNG(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SavePNG(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SavePNG_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SavePNG_IO(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ScaleSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_ScaleMode a3 = (SDL_ScaleMode)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_Surface * rv = SDL_ScaleSurface(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "SDL_Surface", GenDtor_SDL_DestroySurface);
    }
}

static mrb_value GenR_SDL_ScreenKeyboardShown(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_ScreenKeyboardShown(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ScreenSaverEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_ScreenSaverEnabled();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SeekIO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_IOWhence a2 = (SDL_IOWhence)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint64 rv = SDL_SeekIO(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_SendGamepadEffect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    bool rv = SDL_SendGamepadEffect(a0, (const void *)a1, (int)len1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SendJoystickEffect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    bool rv = SDL_SendJoystickEffect(a0, (const void *)a1, (int)len1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetAppMetadata(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetAppMetadata(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetAppMetadataProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetAppMetadataProperty(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetAudioDeviceGain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioDeviceID a0 = (SDL_AudioDeviceID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetAudioDeviceGain(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetAudioStreamFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    SDL_AudioSpec tmp1;
    const SDL_AudioSpec *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_AudioSpec(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_AudioSpec tmp2;
    const SDL_AudioSpec *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_AudioSpec(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    bool rv = SDL_SetAudioStreamFormat(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetAudioStreamFrequencyRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetAudioStreamFrequencyRatio(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetAudioStreamGain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetAudioStreamGain(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetBooleanProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetBooleanProperty(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetClipboardText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_SetClipboardText(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetCursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Cursor *a0 = (SDL_Cursor *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Cursor");
    bool rv = SDL_SetCursor(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetDefaultTextureScaleMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_ScaleMode a1 = (SDL_ScaleMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetDefaultTextureScaleMode(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetEnvironmentVariable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Environment *a0 = (SDL_Environment *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Environment");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_SetEnvironmentVariable(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetEventEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_SetEventEnabled(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetFloatProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetFloatProperty(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetGPUAllowedFramesInFlight(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetGPUAllowedFramesInFlight(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetGPUBlendConstants(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    SDL_FColor a1;
    GenRead_SDL_FColor(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &a1);
    SDL_SetGPUBlendConstants(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetGPUBufferName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUBuffer *a1 = (SDL_GPUBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUBuffer");
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_SetGPUBufferName(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetGPURenderState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_GPURenderState *a1 = (SDL_GPURenderState *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPURenderState");
    bool rv = SDL_SetGPURenderState(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetGPURenderStateFragmentUniforms(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderState *a0 = (SDL_GPURenderState *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderState");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t len2 = 0;
    const char *a2 = SDLStaticGen_RubyToBlob(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &len2);
    bool rv = SDL_SetGPURenderStateFragmentUniforms(a0, a1, (const void *)a2, (Uint32)len2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetGPUScissor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_SetGPUScissor(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetGPUStencilReference(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_SetGPUStencilReference(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetGPUSwapchainParameters(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Window");
    SDL_GPUSwapchainComposition a2 = (SDL_GPUSwapchainComposition)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_GPUPresentMode a3 = (SDL_GPUPresentMode)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_SetGPUSwapchainParameters(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetGPUTextureName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUTexture *a1 = (SDL_GPUTexture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTexture");
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_SetGPUTextureName(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetGPUViewport(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPURenderPass *a0 = (SDL_GPURenderPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPURenderPass");
    SDL_GPUViewport tmp1;
    const SDL_GPUViewport *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_GPUViewport(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_SetGPUViewport(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetGamepadEventsEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool a0 = (bool)SDLStaticGen_RubyToBool((argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_SetGamepadEventsEnabled(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetGamepadLED(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_SetGamepadLED(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetGamepadMapping(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_JoystickID a0 = (SDL_JoystickID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetGamepadMapping(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetGamepadPlayerIndex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetGamepadPlayerIndex(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetGamepadSensorEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Gamepad *a0 = (SDL_Gamepad *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Gamepad");
    SDL_SensorType a1 = (SDL_SensorType)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetGamepadSensorEnabled(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetHapticAutocenter(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetHapticAutocenter(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetHapticGain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetHapticGain(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetHint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetHint(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetHintWithPriority(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_HintPriority a2 = (SDL_HintPriority)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetHintWithPriority(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetInitialized(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_InitState *a0 = (SDL_InitState *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_InitState");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_SetInitialized(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetJoystickEventsEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool a0 = (bool)SDLStaticGen_RubyToBool((argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_SetJoystickEventsEnabled(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetJoystickLED(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_SetJoystickLED(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetJoystickPlayerIndex(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetJoystickPlayerIndex(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetJoystickVirtualAxis(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetJoystickVirtualAxis(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetJoystickVirtualBall(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint16 a2 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint16 a3 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_SetJoystickVirtualBall(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetJoystickVirtualButton(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetJoystickVirtualButton(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetJoystickVirtualHat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetJoystickVirtualHat(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetJoystickVirtualTouchpad(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Joystick *a0 = (SDL_Joystick *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Joystick");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = SDL_SetJoystickVirtualTouchpad(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetLogPriorities(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_LogPriority a0 = (SDL_LogPriority)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_SetLogPriorities(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetLogPriority(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_LogPriority a1 = (SDL_LogPriority)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_SetLogPriority(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetLogPriorityPrefix(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_LogPriority a0 = (SDL_LogPriority)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetLogPriorityPrefix(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetModState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Keymod a0 = (SDL_Keymod)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_SetModState(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetNumberProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint64 a2 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetNumberProperty(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetPaletteColors(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Palette *a0 = (SDL_Palette *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Palette");
    SDL_Color tmp1;
    const SDL_Color *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Color(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_SetPaletteColors(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetPrimarySelectionText(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_SetPrimarySelectionText(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetRenderClipRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_SetRenderClipRect(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetRenderColorScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetRenderColorScale(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetRenderDrawBlendMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_BlendMode a1 = (SDL_BlendMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetRenderDrawBlendMode(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetRenderDrawColor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_SetRenderDrawColor(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetRenderDrawColorFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_SetRenderDrawColorFloat(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetRenderLogicalPresentation(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_RendererLogicalPresentation a3 = (SDL_RendererLogicalPresentation)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_SetRenderLogicalPresentation(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetRenderScale(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetRenderScale(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetRenderTarget(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Texture *a1 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Texture");
    bool rv = SDL_SetRenderTarget(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetRenderTextureAddressMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_TextureAddressMode a1 = (SDL_TextureAddressMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_TextureAddressMode a2 = (SDL_TextureAddressMode)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetRenderTextureAddressMode(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetRenderVSync(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetRenderVSync(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetRenderViewport(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Renderer *a0 = (SDL_Renderer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Renderer");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_SetRenderViewport(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetScancodeName(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Scancode a0 = (SDL_Scancode)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetScancodeName(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetStringProperty(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetStringProperty(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetSurfaceAlphaMod(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetSurfaceAlphaMod(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetSurfaceBlendMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_BlendMode a1 = (SDL_BlendMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetSurfaceBlendMode(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetSurfaceClipRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_SetSurfaceClipRect(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetSurfaceColorKey(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 a2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetSurfaceColorKey(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetSurfaceColorMod(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_SetSurfaceColorMod(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetSurfaceColorspace(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Colorspace a1 = (SDL_Colorspace)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetSurfaceColorspace(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetSurfacePalette(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Palette *a1 = (SDL_Palette *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Palette");
    bool rv = SDL_SetSurfacePalette(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetSurfaceRLE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetSurfaceRLE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetTextInputArea(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetTextInputArea(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetTextureAlphaMod(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetTextureAlphaMod(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetTextureAlphaModFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetTextureAlphaModFloat(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetTextureBlendMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    SDL_BlendMode a1 = (SDL_BlendMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetTextureBlendMode(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetTextureColorMod(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint8 a2 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_SetTextureColorMod(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetTextureColorModFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = SDL_SetTextureColorModFloat(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetTexturePalette(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    SDL_Palette *a1 = (SDL_Palette *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Palette");
    bool rv = SDL_SetTexturePalette(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetTextureScaleMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    SDL_ScaleMode a1 = (SDL_ScaleMode)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetTextureScaleMode(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetTrayEntryChecked(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayEntry");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_SetTrayEntryChecked(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetTrayEntryEnabled(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayEntry");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_SetTrayEntryEnabled(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetTrayEntryLabel(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_TrayEntry *a0 = (SDL_TrayEntry *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_TrayEntry");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_SetTrayEntryLabel(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetTrayIcon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Tray *a0 = (SDL_Tray *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Tray");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Surface");
    SDL_SetTrayIcon(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetTrayTooltip(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Tray *a0 = (SDL_Tray *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Tray");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_SetTrayTooltip(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_SetWindowAlwaysOnTop(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowAlwaysOnTop(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowAspectRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetWindowAspectRatio(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowBordered(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowBordered(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowFillDocument(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowFillDocument(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowFocusable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowFocusable(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowFullscreen(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowFullscreen(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowFullscreenMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    const SDL_DisplayMode *a1 = (const SDL_DisplayMode *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_DisplayMode");
    bool rv = SDL_SetWindowFullscreenMode(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowIcon(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Surface");
    bool rv = SDL_SetWindowIcon(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowKeyboardGrab(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowKeyboardGrab(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowMaximumSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetWindowMaximumSize(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowMinimumSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetWindowMinimumSize(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowModal(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowModal(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowMouseGrab(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowMouseGrab(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowMouseRect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = SDL_SetWindowMouseRect(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowOpacity(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowOpacity(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowParent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_SetWindowParent(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetWindowPosition(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowProgressState(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_ProgressState a1 = (SDL_ProgressState)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowProgressState(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowProgressValue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowProgressValue(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowRelativeMouseMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowRelativeMouseMode(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowResizable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowResizable(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowShape(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_Surface *a1 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Surface");
    bool rv = SDL_SetWindowShape(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowSize(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_SetWindowSize(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowSurfaceVSync(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowSurfaceVSync(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SetWindowTitle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_SetWindowTitle(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ShouldInit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_InitState *a0 = (SDL_InitState *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_InitState");
    bool rv = SDL_ShouldInit(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ShouldQuit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_InitState *a0 = (SDL_InitState *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_InitState");
    bool rv = SDL_ShouldQuit(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ShowCursor(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = SDL_ShowCursor();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ShowMessageBox(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const SDL_MessageBoxData *a0 = (const SDL_MessageBoxData *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_MessageBoxData");
    int io1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_ShowMessageBox(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_ShowSimpleMessageBox(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_MessageBoxFlags a0 = (SDL_MessageBoxFlags)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_Window *a3 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_ShowSimpleMessageBox(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ShowWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_ShowWindow(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_ShowWindowSystemMenu(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_ShowWindowSystemMenu(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SignalAsyncIOQueue(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AsyncIOQueue *a0 = (SDL_AsyncIOQueue *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AsyncIOQueue");
    SDL_SignalAsyncIOQueue(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_StartTextInput(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_StartTextInput(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_StartTextInputWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_PropertiesID a1 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_StartTextInputWithProperties(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_StopHapticEffect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    SDL_HapticEffectID a1 = (SDL_HapticEffectID)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_StopHapticEffect(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_StopHapticEffects(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    bool rv = SDL_StopHapticEffects(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_StopHapticRumble(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    bool rv = SDL_StopHapticRumble(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_StopTextInput(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_StopTextInput(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_StorageReady(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Storage");
    bool rv = SDL_StorageReady(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_StretchSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    SDL_Surface *a2 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_Surface");
    SDL_Rect tmp3;
    const SDL_Rect *a3 = NULL;
    if (argc > 3 && mrb_hash_p(argv[3])) {
        GenRead_SDL_Rect(mrb, argv[3], &tmp3);
        a3 = &tmp3;
    }
    SDL_ScaleMode a4 = (SDL_ScaleMode)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    bool rv = SDL_StretchSurface(a0, a1, a2, a3, a4);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_StringToGUID(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_GUID rv = SDL_StringToGUID(a0);
    return GenPush_SDL_GUID(mrb, &rv);
    }
}

static mrb_value GenR_SDL_SubmitGPUCommandBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    bool rv = SDL_SubmitGPUCommandBuffer(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SubmitGPUCommandBufferAndAcquireFence(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCommandBuffer *a0 = (SDL_GPUCommandBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCommandBuffer");
    SDL_GPUFence * rv = SDL_SubmitGPUCommandBufferAndAcquireFence(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_GPUFence");
    }
}

static mrb_value GenR_SDL_SurfaceHasAlternateImages(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    bool rv = SDL_SurfaceHasAlternateImages(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SurfaceHasColorKey(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    bool rv = SDL_SurfaceHasColorKey(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SurfaceHasRLE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    bool rv = SDL_SurfaceHasRLE(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_SyncWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_SyncWindow(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_TellIO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint64 rv = SDL_TellIO(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_TextInputActive(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_TextInputActive(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_TimeFromWindows(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_Time rv = SDL_TimeFromWindows(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_TimeToDateTime(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Time a0 = (SDL_Time)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_DateTime out1;
    memset(&out1, 0, sizeof(out1));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_TimeToDateTime(a0, &out1, a2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_DateTime(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_TimeToWindows(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Time a0 = (SDL_Time)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Uint32 io1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Uint32 io2 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_TimeToWindows(a0, &io1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)io1);
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_TryLockSpinlock(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_SpinLock io0 = (SDL_SpinLock)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    bool rv = SDL_TryLockSpinlock(&io0);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io0);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_UCS4ToUTF8(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 a0 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *src1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char *a1 = SDL_strdup(src1 != NULL ? src1 : "");
    char * rv = SDL_UCS4ToUTF8(a0, a1);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    SDL_free(a1);
    return rstr;
    }
}

static mrb_value GenR_SDL_UnbindAudioStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    SDL_UnbindAudioStream(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_UnloadObject(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_SharedObject *a0 = (SDL_SharedObject *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_SharedObject");
    SDL_UnloadObject(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_UnlockAudioStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AudioStream *a0 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AudioStream");
    bool rv = SDL_UnlockAudioStream(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_UnlockProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_UnlockProperties(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_UnlockSpinlock(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_SpinLock io0 = (SDL_SpinLock)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_UnlockSpinlock(&io0);
    return mrb_int_value(mrb, (mrb_int)io0);
    }
}

static mrb_value GenR_SDL_UnlockSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    SDL_UnlockSurface(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_UnlockTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Texture *a0 = (SDL_Texture *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Texture");
    SDL_UnlockTexture(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_UnmapGPUTransferBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_GPUTransferBuffer *a1 = (SDL_GPUTransferBuffer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTransferBuffer");
    SDL_UnmapGPUTransferBuffer(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_UnsetEnvironmentVariable(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Environment *a0 = (SDL_Environment *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Environment");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_UnsetEnvironmentVariable(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_UpdateGamepads(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_UpdateGamepads();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_UpdateHapticEffect(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Haptic *a0 = (SDL_Haptic *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Haptic");
    SDL_HapticEffectID a1 = (SDL_HapticEffectID)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const SDL_HapticEffect *a2 = (const SDL_HapticEffect *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_HapticEffect");
    bool rv = SDL_UpdateHapticEffect(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_UpdateJoysticks(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_UpdateJoysticks();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_UpdateSensors(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_UpdateSensors();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_UpdateTrays(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_UpdateTrays();
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_UpdateWindowSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_UpdateWindowSurface(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_UpdateWindowSurfaceRects(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    SDL_Rect tmp1;
    const SDL_Rect *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_SDL_Rect(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_UpdateWindowSurfaceRects(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_UploadToGPUBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCopyPass");
    const SDL_GPUTransferBufferLocation *a1 = (const SDL_GPUTransferBufferLocation *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTransferBufferLocation");
    const SDL_GPUBufferRegion *a2 = (const SDL_GPUBufferRegion *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUBufferRegion");
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_UploadToGPUBuffer(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_UploadToGPUTexture(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUCopyPass *a0 = (SDL_GPUCopyPass *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUCopyPass");
    const SDL_GPUTextureTransferInfo *a1 = (const SDL_GPUTextureTransferInfo *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_GPUTextureTransferInfo");
    const SDL_GPUTextureRegion *a2 = (const SDL_GPUTextureRegion *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), "SDL_GPUTextureRegion");
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    SDL_UploadToGPUTexture(a0, a1, a2, a3);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_WaitAsyncIOResult(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_AsyncIOQueue *a0 = (SDL_AsyncIOQueue *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_AsyncIOQueue");
    SDL_AsyncIOOutcome *a1 = (SDL_AsyncIOOutcome *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_AsyncIOOutcome");
    Sint32 a2 = (Sint32)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_WaitAsyncIOResult(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WaitEvent(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    bool rv = SDL_WaitEvent(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WaitEventTimeout(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Event *a0 = (SDL_Event *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Event");
    Sint32 a1 = (Sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WaitEventTimeout(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WaitForGPUIdle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    bool rv = SDL_WaitForGPUIdle(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WaitForGPUSwapchain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_WaitForGPUSwapchain(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WaitProcess(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Process *a0 = (SDL_Process *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Process");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    int io2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_WaitProcess(a0, a1, &io2);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = mrb_int_value(mrb, (mrb_int)io2);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_SDL_WarpMouseGlobal(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    float a0 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WarpMouseGlobal(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WarpMouseInWindow(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    SDL_WarpMouseInWindow(a0, a1, a2);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_WasInit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_InitFlags a0 = (SDL_InitFlags)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_InitFlags rv = SDL_WasInit(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_WindowHasSurface(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Window *a0 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Window");
    bool rv = SDL_WindowHasSurface(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WindowSupportsGPUPresentMode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Window");
    SDL_GPUPresentMode a2 = (SDL_GPUPresentMode)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_WindowSupportsGPUPresentMode(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WindowSupportsGPUSwapchainComposition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_GPUDevice *a0 = (SDL_GPUDevice *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_GPUDevice");
    SDL_Window *a1 = (SDL_Window *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_Window");
    SDL_GPUSwapchainComposition a2 = (SDL_GPUSwapchainComposition)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = SDL_WindowSupportsGPUSwapchainComposition(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteIO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    size_t rv = SDL_WriteIO(a0, (const void *)a1, (size_t)len1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_WriteS16BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteS16BE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteS16LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint16 a1 = (Sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteS16LE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteS32BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint32 a1 = (Sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteS32BE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteS32LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint32 a1 = (Sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteS32LE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteS64BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteS64BE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteS64LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteS64LE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteS8(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Sint8 a1 = (Sint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteS8(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteStorageFile(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Storage *a0 = (SDL_Storage *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Storage");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t len2 = 0;
    const char *a2 = SDLStaticGen_RubyToBlob(mrb, (argc > 2 ? argv[2] : mrb_nil_value()), &len2);
    bool rv = SDL_WriteStorageFile(a0, a1, (const void *)a2, (Uint64)len2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteSurfacePixel(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Uint8 a3 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    Uint8 a4 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    Uint8 a5 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    Uint8 a6 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = SDL_WriteSurfacePixel(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteSurfacePixelFloat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_Surface *a0 = (SDL_Surface *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_Surface");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    float a3 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    float a4 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    float a5 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 5 ? argv[5] : mrb_nil_value()));
    float a6 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 6 ? argv[6] : mrb_nil_value()));
    bool rv = SDL_WriteSurfacePixelFloat(a0, a1, a2, a3, a4, a5, a6);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteU16BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint16 a1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteU16BE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteU16LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint16 a1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteU16LE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteU32BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteU32BE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteU32LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint32 a1 = (Uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteU32LE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteU64BE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint64 a1 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteU64BE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteU64LE(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint64 a1 = (Uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteU64LE(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_WriteU8(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    Uint8 a1 = (Uint8)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = SDL_WriteU8(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_SDL_getenv(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_getenv(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_getenv_unsafe(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = SDL_getenv_unsafe(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_SDL_hid_ble_scan(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool a0 = (bool)SDLStaticGen_RubyToBool((argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_hid_ble_scan(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_hid_close(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_hid_device");
    int rv = SDL_hid_close(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_hid_device_change_count(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    Uint32 rv = SDL_hid_device_change_count();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_hid_enumerate(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    unsigned short a0 = (unsigned short)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    unsigned short a1 = (unsigned short)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_hid_device_info * rv = SDL_hid_enumerate(a0, a1);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_hid_device_info");
    }
}

static mrb_value GenR_SDL_hid_exit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_hid_exit();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_hid_free_enumeration(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_hid_device_info *a0 = (SDL_hid_device_info *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_hid_device_info");
    SDL_hid_free_enumeration(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_SDL_hid_get_device_info(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_hid_device");
    SDL_hid_device_info * rv = SDL_hid_get_device_info(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_hid_device_info");
    }
}

static mrb_value GenR_SDL_hid_get_properties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_hid_device");
    SDL_PropertiesID rv = SDL_hid_get_properties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_hid_init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = SDL_hid_init();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_hid_open_path(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_hid_device * rv = SDL_hid_open_path(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_hid_device");
    }
}

static mrb_value GenR_SDL_hid_send_feature_report(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_hid_device");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    int rv = SDL_hid_send_feature_report(a0, (const void *)a1, (size_t)len1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_hid_set_nonblocking(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_hid_device");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = SDL_hid_set_nonblocking(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_hid_write(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_hid_device *a0 = (SDL_hid_device *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_hid_device");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    int rv = SDL_hid_write(a0, (const void *)a1, (size_t)len1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_iconv_string(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    size_t a3 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    char * rv = SDL_iconv_string(a0, a1, a2, a3);
    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);
    if (rv != NULL) { SDL_free(rv); }
    return rstr;
    }
}

static mrb_value GenR_SDL_setenv_unsafe(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = SDL_setenv_unsafe(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_unsetenv_unsafe(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = SDL_unsetenv_unsafe(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_utf8strlen(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    size_t rv = SDL_utf8strlen(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_SDL_utf8strnlen(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    size_t a1 = (size_t)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    size_t rv = SDL_utf8strnlen(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

void SDLStaticGen_OpenRuby_sdl(mrb_state *mrb);
void SDLStaticGen_OpenRuby_sdl(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "SDL");
    mrb_define_module_function(mrb, mod, "AcquireCameraFrame", GenR_SDL_AcquireCameraFrame, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AcquireGPUCommandBuffer", GenR_SDL_AcquireGPUCommandBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddGamepadMapping", GenR_SDL_AddGamepadMapping, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddGamepadMappingsFromFile", GenR_SDL_AddGamepadMappingsFromFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddGamepadMappingsFromIO", GenR_SDL_AddGamepadMappingsFromIO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddSurfaceAlternateImage", GenR_SDL_AddSurfaceAlternateImage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AddVulkanRenderSemaphores", GenR_SDL_AddVulkanRenderSemaphores, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AsyncIOFromFile", GenR_SDL_AsyncIOFromFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AttachVirtualJoystick", GenR_SDL_AttachVirtualJoystick, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AudioDevicePaused", GenR_SDL_AudioDevicePaused, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AudioStreamDevicePaused", GenR_SDL_AudioStreamDevicePaused, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BeginGPUComputePass", GenR_SDL_BeginGPUComputePass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BeginGPUCopyPass", GenR_SDL_BeginGPUCopyPass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BeginGPURenderPass", GenR_SDL_BeginGPURenderPass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BindAudioStream", GenR_SDL_BindAudioStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BindGPUComputePipeline", GenR_SDL_BindGPUComputePipeline, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BindGPUComputeSamplers", GenR_SDL_BindGPUComputeSamplers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BindGPUFragmentSamplers", GenR_SDL_BindGPUFragmentSamplers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BindGPUGraphicsPipeline", GenR_SDL_BindGPUGraphicsPipeline, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BindGPUIndexBuffer", GenR_SDL_BindGPUIndexBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BindGPUVertexBuffers", GenR_SDL_BindGPUVertexBuffers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BindGPUVertexSamplers", GenR_SDL_BindGPUVertexSamplers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BlitGPUTexture", GenR_SDL_BlitGPUTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BlitSurface", GenR_SDL_BlitSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BlitSurface9Grid", GenR_SDL_BlitSurface9Grid, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BlitSurfaceScaled", GenR_SDL_BlitSurfaceScaled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BlitSurfaceTiled", GenR_SDL_BlitSurfaceTiled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BlitSurfaceTiledWithScale", GenR_SDL_BlitSurfaceTiledWithScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BlitSurfaceUnchecked", GenR_SDL_BlitSurfaceUnchecked, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "BlitSurfaceUncheckedScaled", GenR_SDL_BlitSurfaceUncheckedScaled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CalculateGPUTextureFormatSize", GenR_SDL_CalculateGPUTextureFormatSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CancelGPUCommandBuffer", GenR_SDL_CancelGPUCommandBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CaptureMouse", GenR_SDL_CaptureMouse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ClaimWindowForGPUDevice", GenR_SDL_ClaimWindowForGPUDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ClearAudioStream", GenR_SDL_ClearAudioStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ClearClipboardData", GenR_SDL_ClearClipboardData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ClearComposition", GenR_SDL_ClearComposition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ClearError", GenR_SDL_ClearError, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ClearProperty", GenR_SDL_ClearProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ClearSurface", GenR_SDL_ClearSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ClickTrayEntry", GenR_SDL_ClickTrayEntry, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CloseAudioDevice", GenR_SDL_CloseAudioDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CloseCamera", GenR_SDL_CloseCamera, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CloseGamepad", GenR_SDL_CloseGamepad, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CloseHaptic", GenR_SDL_CloseHaptic, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CloseIO", GenR_SDL_CloseIO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CloseJoystick", GenR_SDL_CloseJoystick, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CloseSensor", GenR_SDL_CloseSensor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CloseStorage", GenR_SDL_CloseStorage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CompareAndSwapAtomicInt", GenR_SDL_CompareAndSwapAtomicInt, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CompareAndSwapAtomicU32", GenR_SDL_CompareAndSwapAtomicU32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ComposeCustomBlendMode", GenR_SDL_ComposeCustomBlendMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConvertEventToRenderCoordinates", GenR_SDL_ConvertEventToRenderCoordinates, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConvertSurface", GenR_SDL_ConvertSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ConvertSurfaceAndColorspace", GenR_SDL_ConvertSurfaceAndColorspace, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CopyFile", GenR_SDL_CopyFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CopyGPUBufferToBuffer", GenR_SDL_CopyGPUBufferToBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CopyGPUTextureToTexture", GenR_SDL_CopyGPUTextureToTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CopyProperties", GenR_SDL_CopyProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CopyStorageFile", GenR_SDL_CopyStorageFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAnimatedCursor", GenR_SDL_CreateAnimatedCursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAsyncIOQueue", GenR_SDL_CreateAsyncIOQueue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAudioStream", GenR_SDL_CreateAudioStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateColorCursor", GenR_SDL_CreateColorCursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateDirectory", GenR_SDL_CreateDirectory, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateEnvironment", GenR_SDL_CreateEnvironment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPUBuffer", GenR_SDL_CreateGPUBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPUComputePipeline", GenR_SDL_CreateGPUComputePipeline, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPUDevice", GenR_SDL_CreateGPUDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPUDeviceWithProperties", GenR_SDL_CreateGPUDeviceWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPUGraphicsPipeline", GenR_SDL_CreateGPUGraphicsPipeline, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPURenderState", GenR_SDL_CreateGPURenderState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPURenderer", GenR_SDL_CreateGPURenderer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPUSampler", GenR_SDL_CreateGPUSampler, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPUShader", GenR_SDL_CreateGPUShader, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPUTexture", GenR_SDL_CreateGPUTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGPUTransferBuffer", GenR_SDL_CreateGPUTransferBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateHapticEffect", GenR_SDL_CreateHapticEffect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreatePalette", GenR_SDL_CreatePalette, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreatePopupWindow", GenR_SDL_CreatePopupWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateProcessWithProperties", GenR_SDL_CreateProcessWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateProperties", GenR_SDL_CreateProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateRenderer", GenR_SDL_CreateRenderer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateRendererWithProperties", GenR_SDL_CreateRendererWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateSoftwareRenderer", GenR_SDL_CreateSoftwareRenderer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateStorageDirectory", GenR_SDL_CreateStorageDirectory, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateSurface", GenR_SDL_CreateSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateSurfacePalette", GenR_SDL_CreateSurfacePalette, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateSystemCursor", GenR_SDL_CreateSystemCursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateTexture", GenR_SDL_CreateTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateTextureFromSurface", GenR_SDL_CreateTextureFromSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateTextureWithProperties", GenR_SDL_CreateTextureWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateTray", GenR_SDL_CreateTray, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateTrayMenu", GenR_SDL_CreateTrayMenu, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateTraySubmenu", GenR_SDL_CreateTraySubmenu, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateWindow", GenR_SDL_CreateWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateWindowWithProperties", GenR_SDL_CreateWindowWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CursorVisible", GenR_SDL_CursorVisible, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DateTimeToTime", GenR_SDL_DateTimeToTime, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Delay", GenR_SDL_Delay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DelayNS", GenR_SDL_DelayNS, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DelayPrecise", GenR_SDL_DelayPrecise, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyAsyncIOQueue", GenR_SDL_DestroyAsyncIOQueue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyAudioStream", GenR_SDL_DestroyAudioStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyCursor", GenR_SDL_DestroyCursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyEnvironment", GenR_SDL_DestroyEnvironment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyGPUDevice", GenR_SDL_DestroyGPUDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyGPURenderState", GenR_SDL_DestroyGPURenderState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyHapticEffect", GenR_SDL_DestroyHapticEffect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyPalette", GenR_SDL_DestroyPalette, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyProcess", GenR_SDL_DestroyProcess, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyProperties", GenR_SDL_DestroyProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyRenderer", GenR_SDL_DestroyRenderer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroySurface", GenR_SDL_DestroySurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyTexture", GenR_SDL_DestroyTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyTray", GenR_SDL_DestroyTray, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyWindow", GenR_SDL_DestroyWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyWindowSurface", GenR_SDL_DestroyWindowSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DetachVirtualJoystick", GenR_SDL_DetachVirtualJoystick, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DisableScreenSaver", GenR_SDL_DisableScreenSaver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DispatchGPUCompute", GenR_SDL_DispatchGPUCompute, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DispatchGPUComputeIndirect", GenR_SDL_DispatchGPUComputeIndirect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DownloadFromGPUBuffer", GenR_SDL_DownloadFromGPUBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DownloadFromGPUTexture", GenR_SDL_DownloadFromGPUTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DrawGPUIndexedPrimitives", GenR_SDL_DrawGPUIndexedPrimitives, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DrawGPUIndexedPrimitivesIndirect", GenR_SDL_DrawGPUIndexedPrimitivesIndirect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DrawGPUPrimitives", GenR_SDL_DrawGPUPrimitives, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DrawGPUPrimitivesIndirect", GenR_SDL_DrawGPUPrimitivesIndirect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DuplicateSurface", GenR_SDL_DuplicateSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EnableScreenSaver", GenR_SDL_EnableScreenSaver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EndGPUComputePass", GenR_SDL_EndGPUComputePass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EndGPUCopyPass", GenR_SDL_EndGPUCopyPass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EndGPURenderPass", GenR_SDL_EndGPURenderPass, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "EventEnabled", GenR_SDL_EventEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FillSurfaceRect", GenR_SDL_FillSurfaceRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FillSurfaceRects", GenR_SDL_FillSurfaceRects, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FlashWindow", GenR_SDL_FlashWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FlipSurface", GenR_SDL_FlipSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FlushAudioStream", GenR_SDL_FlushAudioStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FlushEvent", GenR_SDL_FlushEvent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FlushEvents", GenR_SDL_FlushEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FlushIO", GenR_SDL_FlushIO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FlushRenderer", GenR_SDL_FlushRenderer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GL_ExtensionSupported", GenR_SDL_GL_ExtensionSupported, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GL_GetAttribute", GenR_SDL_GL_GetAttribute, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GL_GetCurrentWindow", GenR_SDL_GL_GetCurrentWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GL_GetSwapInterval", GenR_SDL_GL_GetSwapInterval, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GL_LoadLibrary", GenR_SDL_GL_LoadLibrary, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GL_ResetAttributes", GenR_SDL_GL_ResetAttributes, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GL_SetAttribute", GenR_SDL_GL_SetAttribute, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GL_SetSwapInterval", GenR_SDL_GL_SetSwapInterval, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GL_SwapWindow", GenR_SDL_GL_SwapWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GL_UnloadLibrary", GenR_SDL_GL_UnloadLibrary, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUSupportsProperties", GenR_SDL_GPUSupportsProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUSupportsShaderFormats", GenR_SDL_GPUSupportsShaderFormats, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureFormatTexelBlockSize", GenR_SDL_GPUTextureFormatTexelBlockSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureSupportsFormat", GenR_SDL_GPUTextureSupportsFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GPUTextureSupportsSampleCount", GenR_SDL_GPUTextureSupportsSampleCount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GUIDToString", GenR_SDL_GUIDToString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadConnected", GenR_SDL_GamepadConnected, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadEventsEnabled", GenR_SDL_GamepadEventsEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadHasAxis", GenR_SDL_GamepadHasAxis, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadHasButton", GenR_SDL_GamepadHasButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadHasSensor", GenR_SDL_GamepadHasSensor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GamepadSensorEnabled", GenR_SDL_GamepadSensorEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GenerateMipmapsForGPUTexture", GenR_SDL_GenerateMipmapsForGPUTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAppMetadataProperty", GenR_SDL_GetAppMetadataProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAssertionReport", GenR_SDL_GetAssertionReport, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAsyncIOResult", GenR_SDL_GetAsyncIOResult, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAsyncIOSize", GenR_SDL_GetAsyncIOSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioDeviceFormat", GenR_SDL_GetAudioDeviceFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioDeviceGain", GenR_SDL_GetAudioDeviceGain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioDeviceName", GenR_SDL_GetAudioDeviceName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioDriver", GenR_SDL_GetAudioDriver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioFormatName", GenR_SDL_GetAudioFormatName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioStreamAvailable", GenR_SDL_GetAudioStreamAvailable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioStreamDevice", GenR_SDL_GetAudioStreamDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioStreamFormat", GenR_SDL_GetAudioStreamFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioStreamFrequencyRatio", GenR_SDL_GetAudioStreamFrequencyRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioStreamGain", GenR_SDL_GetAudioStreamGain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioStreamProperties", GenR_SDL_GetAudioStreamProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioStreamQueued", GenR_SDL_GetAudioStreamQueued, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetBasePath", GenR_SDL_GetBasePath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetBooleanProperty", GenR_SDL_GetBooleanProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCPUCacheLineSize", GenR_SDL_GetCPUCacheLineSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCameraDriver", GenR_SDL_GetCameraDriver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCameraFormat", GenR_SDL_GetCameraFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCameraID", GenR_SDL_GetCameraID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCameraName", GenR_SDL_GetCameraName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCameraPermissionState", GenR_SDL_GetCameraPermissionState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCameraPosition", GenR_SDL_GetCameraPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCameraProperties", GenR_SDL_GetCameraProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetClipboardText", GenR_SDL_GetClipboardText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetClosestFullscreenDisplayMode", GenR_SDL_GetClosestFullscreenDisplayMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCurrentAudioDriver", GenR_SDL_GetCurrentAudioDriver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCurrentCameraDriver", GenR_SDL_GetCurrentCameraDriver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCurrentDirectory", GenR_SDL_GetCurrentDirectory, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCurrentDisplayMode", GenR_SDL_GetCurrentDisplayMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCurrentDisplayOrientation", GenR_SDL_GetCurrentDisplayOrientation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCurrentRenderOutputSize", GenR_SDL_GetCurrentRenderOutputSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCurrentTime", GenR_SDL_GetCurrentTime, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCurrentVideoDriver", GenR_SDL_GetCurrentVideoDriver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetCursor", GenR_SDL_GetCursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDateTimeLocalePreferences", GenR_SDL_GetDateTimeLocalePreferences, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDayOfWeek", GenR_SDL_GetDayOfWeek, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDayOfYear", GenR_SDL_GetDayOfYear, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDaysInMonth", GenR_SDL_GetDaysInMonth, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDefaultCursor", GenR_SDL_GetDefaultCursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDefaultTextureScaleMode", GenR_SDL_GetDefaultTextureScaleMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDesktopDisplayMode", GenR_SDL_GetDesktopDisplayMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDisplayBounds", GenR_SDL_GetDisplayBounds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDisplayContentScale", GenR_SDL_GetDisplayContentScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDisplayForPoint", GenR_SDL_GetDisplayForPoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDisplayForRect", GenR_SDL_GetDisplayForRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDisplayForWindow", GenR_SDL_GetDisplayForWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDisplayName", GenR_SDL_GetDisplayName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDisplayProperties", GenR_SDL_GetDisplayProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetDisplayUsableBounds", GenR_SDL_GetDisplayUsableBounds, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetEnvironment", GenR_SDL_GetEnvironment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetEnvironmentVariable", GenR_SDL_GetEnvironmentVariable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetError", GenR_SDL_GetError, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetEventDescription", GenR_SDL_GetEventDescription, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetFloatProperty", GenR_SDL_GetFloatProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGPUDeviceDriver", GenR_SDL_GetGPUDeviceDriver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGPUDeviceProperties", GenR_SDL_GetGPUDeviceProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGPUDriver", GenR_SDL_GetGPUDriver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGPURendererDevice", GenR_SDL_GetGPURendererDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGPUShaderFormats", GenR_SDL_GetGPUShaderFormats, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGPUSwapchainTextureFormat", GenR_SDL_GetGPUSwapchainTextureFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGPUTextureFormatFromPixelFormat", GenR_SDL_GetGPUTextureFormatFromPixelFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadAppleSFSymbolsNameForAxis", GenR_SDL_GetGamepadAppleSFSymbolsNameForAxis, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadAppleSFSymbolsNameForButton", GenR_SDL_GetGamepadAppleSFSymbolsNameForButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadAxis", GenR_SDL_GetGamepadAxis, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadAxisFromString", GenR_SDL_GetGamepadAxisFromString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadButton", GenR_SDL_GetGamepadButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadButtonFromString", GenR_SDL_GetGamepadButtonFromString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadButtonLabel", GenR_SDL_GetGamepadButtonLabel, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadButtonLabelForType", GenR_SDL_GetGamepadButtonLabelForType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadConnectionState", GenR_SDL_GetGamepadConnectionState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadFirmwareVersion", GenR_SDL_GetGamepadFirmwareVersion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadFromID", GenR_SDL_GetGamepadFromID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadFromPlayerIndex", GenR_SDL_GetGamepadFromPlayerIndex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadGUIDForID", GenR_SDL_GetGamepadGUIDForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadID", GenR_SDL_GetGamepadID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadJoystick", GenR_SDL_GetGamepadJoystick, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadMapping", GenR_SDL_GetGamepadMapping, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadMappingForGUID", GenR_SDL_GetGamepadMappingForGUID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadMappingForID", GenR_SDL_GetGamepadMappingForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadName", GenR_SDL_GetGamepadName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadNameForID", GenR_SDL_GetGamepadNameForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadPath", GenR_SDL_GetGamepadPath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadPathForID", GenR_SDL_GetGamepadPathForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadPlayerIndex", GenR_SDL_GetGamepadPlayerIndex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadPlayerIndexForID", GenR_SDL_GetGamepadPlayerIndexForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadPowerInfo", GenR_SDL_GetGamepadPowerInfo, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadProduct", GenR_SDL_GetGamepadProduct, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadProductForID", GenR_SDL_GetGamepadProductForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadProductVersion", GenR_SDL_GetGamepadProductVersion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadProductVersionForID", GenR_SDL_GetGamepadProductVersionForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadProperties", GenR_SDL_GetGamepadProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadSensorData", GenR_SDL_GetGamepadSensorData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadSensorDataRate", GenR_SDL_GetGamepadSensorDataRate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadSerial", GenR_SDL_GetGamepadSerial, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadSteamHandle", GenR_SDL_GetGamepadSteamHandle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadStringForAxis", GenR_SDL_GetGamepadStringForAxis, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadStringForButton", GenR_SDL_GetGamepadStringForButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadStringForType", GenR_SDL_GetGamepadStringForType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadTouchpadFinger", GenR_SDL_GetGamepadTouchpadFinger, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadType", GenR_SDL_GetGamepadType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadTypeForID", GenR_SDL_GetGamepadTypeForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadTypeFromString", GenR_SDL_GetGamepadTypeFromString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadVendor", GenR_SDL_GetGamepadVendor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGamepadVendorForID", GenR_SDL_GetGamepadVendorForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGlobalMouseState", GenR_SDL_GetGlobalMouseState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGlobalProperties", GenR_SDL_GetGlobalProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGrabbedWindow", GenR_SDL_GetGrabbedWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetHapticEffectStatus", GenR_SDL_GetHapticEffectStatus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetHapticFeatures", GenR_SDL_GetHapticFeatures, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetHapticFromID", GenR_SDL_GetHapticFromID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetHapticID", GenR_SDL_GetHapticID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetHapticName", GenR_SDL_GetHapticName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetHapticNameForID", GenR_SDL_GetHapticNameForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetHint", GenR_SDL_GetHint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetHintBoolean", GenR_SDL_GetHintBoolean, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetIOProperties", GenR_SDL_GetIOProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetIOSize", GenR_SDL_GetIOSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetIOStatus", GenR_SDL_GetIOStatus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickAxis", GenR_SDL_GetJoystickAxis, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickAxisInitialState", GenR_SDL_GetJoystickAxisInitialState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickBall", GenR_SDL_GetJoystickBall, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickButton", GenR_SDL_GetJoystickButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickConnectionState", GenR_SDL_GetJoystickConnectionState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickFirmwareVersion", GenR_SDL_GetJoystickFirmwareVersion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickFromID", GenR_SDL_GetJoystickFromID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickFromPlayerIndex", GenR_SDL_GetJoystickFromPlayerIndex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickGUID", GenR_SDL_GetJoystickGUID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickGUIDForID", GenR_SDL_GetJoystickGUIDForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickGUIDInfo", GenR_SDL_GetJoystickGUIDInfo, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickHat", GenR_SDL_GetJoystickHat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickID", GenR_SDL_GetJoystickID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickName", GenR_SDL_GetJoystickName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickNameForID", GenR_SDL_GetJoystickNameForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickPath", GenR_SDL_GetJoystickPath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickPathForID", GenR_SDL_GetJoystickPathForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickPlayerIndex", GenR_SDL_GetJoystickPlayerIndex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickPlayerIndexForID", GenR_SDL_GetJoystickPlayerIndexForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickPowerInfo", GenR_SDL_GetJoystickPowerInfo, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickProduct", GenR_SDL_GetJoystickProduct, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickProductForID", GenR_SDL_GetJoystickProductForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickProductVersion", GenR_SDL_GetJoystickProductVersion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickProductVersionForID", GenR_SDL_GetJoystickProductVersionForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickProperties", GenR_SDL_GetJoystickProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickSerial", GenR_SDL_GetJoystickSerial, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickType", GenR_SDL_GetJoystickType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickTypeForID", GenR_SDL_GetJoystickTypeForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickVendor", GenR_SDL_GetJoystickVendor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetJoystickVendorForID", GenR_SDL_GetJoystickVendorForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetKeyFromName", GenR_SDL_GetKeyFromName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetKeyFromScancode", GenR_SDL_GetKeyFromScancode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetKeyName", GenR_SDL_GetKeyName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetKeyboardFocus", GenR_SDL_GetKeyboardFocus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetKeyboardNameForID", GenR_SDL_GetKeyboardNameForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetLogPriority", GenR_SDL_GetLogPriority, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMasksForPixelFormat", GenR_SDL_GetMasksForPixelFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMaxHapticEffects", GenR_SDL_GetMaxHapticEffects, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMaxHapticEffectsPlaying", GenR_SDL_GetMaxHapticEffectsPlaying, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetModState", GenR_SDL_GetModState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMouseFocus", GenR_SDL_GetMouseFocus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMouseNameForID", GenR_SDL_GetMouseNameForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMouseState", GenR_SDL_GetMouseState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNaturalDisplayOrientation", GenR_SDL_GetNaturalDisplayOrientation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumAllocations", GenR_SDL_GetNumAllocations, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumAudioDrivers", GenR_SDL_GetNumAudioDrivers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumCameraDrivers", GenR_SDL_GetNumCameraDrivers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumGPUDrivers", GenR_SDL_GetNumGPUDrivers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumGamepadTouchpadFingers", GenR_SDL_GetNumGamepadTouchpadFingers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumGamepadTouchpads", GenR_SDL_GetNumGamepadTouchpads, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumHapticAxes", GenR_SDL_GetNumHapticAxes, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumJoystickAxes", GenR_SDL_GetNumJoystickAxes, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumJoystickBalls", GenR_SDL_GetNumJoystickBalls, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumJoystickButtons", GenR_SDL_GetNumJoystickButtons, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumJoystickHats", GenR_SDL_GetNumJoystickHats, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumLogicalCPUCores", GenR_SDL_GetNumLogicalCPUCores, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumRenderDrivers", GenR_SDL_GetNumRenderDrivers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumVideoDrivers", GenR_SDL_GetNumVideoDrivers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumberProperty", GenR_SDL_GetNumberProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPathInfo", GenR_SDL_GetPathInfo, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPenDeviceType", GenR_SDL_GetPenDeviceType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPerformanceCounter", GenR_SDL_GetPerformanceCounter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPerformanceFrequency", GenR_SDL_GetPerformanceFrequency, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPixelFormatForMasks", GenR_SDL_GetPixelFormatForMasks, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPixelFormatFromGPUTextureFormat", GenR_SDL_GetPixelFormatFromGPUTextureFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPixelFormatName", GenR_SDL_GetPixelFormatName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPlatform", GenR_SDL_GetPlatform, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPowerInfo", GenR_SDL_GetPowerInfo, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPrefPath", GenR_SDL_GetPrefPath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPrimaryDisplay", GenR_SDL_GetPrimaryDisplay, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPrimarySelectionText", GenR_SDL_GetPrimarySelectionText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetProcessInput", GenR_SDL_GetProcessInput, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetProcessOutput", GenR_SDL_GetProcessOutput, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetProcessProperties", GenR_SDL_GetProcessProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetPropertyType", GenR_SDL_GetPropertyType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRGB", GenR_SDL_GetRGB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRGBA", GenR_SDL_GetRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRealGamepadType", GenR_SDL_GetRealGamepadType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRealGamepadTypeForID", GenR_SDL_GetRealGamepadTypeForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRectAndLineIntersection", GenR_SDL_GetRectAndLineIntersection, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRectAndLineIntersectionFloat", GenR_SDL_GetRectAndLineIntersectionFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRectEnclosingPoints", GenR_SDL_GetRectEnclosingPoints, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRectEnclosingPointsFloat", GenR_SDL_GetRectEnclosingPointsFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRectIntersection", GenR_SDL_GetRectIntersection, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRectIntersectionFloat", GenR_SDL_GetRectIntersectionFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRectUnion", GenR_SDL_GetRectUnion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRectUnionFloat", GenR_SDL_GetRectUnionFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRelativeMouseState", GenR_SDL_GetRelativeMouseState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderClipRect", GenR_SDL_GetRenderClipRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderColorScale", GenR_SDL_GetRenderColorScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderDrawBlendMode", GenR_SDL_GetRenderDrawBlendMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderDrawColor", GenR_SDL_GetRenderDrawColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderDrawColorFloat", GenR_SDL_GetRenderDrawColorFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderDriver", GenR_SDL_GetRenderDriver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderLogicalPresentation", GenR_SDL_GetRenderLogicalPresentation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderLogicalPresentationRect", GenR_SDL_GetRenderLogicalPresentationRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderOutputSize", GenR_SDL_GetRenderOutputSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderSafeArea", GenR_SDL_GetRenderSafeArea, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderScale", GenR_SDL_GetRenderScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderTarget", GenR_SDL_GetRenderTarget, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderTextureAddressMode", GenR_SDL_GetRenderTextureAddressMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderVSync", GenR_SDL_GetRenderVSync, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderViewport", GenR_SDL_GetRenderViewport, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderWindow", GenR_SDL_GetRenderWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRenderer", GenR_SDL_GetRenderer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRendererFromTexture", GenR_SDL_GetRendererFromTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRendererName", GenR_SDL_GetRendererName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRendererProperties", GenR_SDL_GetRendererProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetRevision", GenR_SDL_GetRevision, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSIMDAlignment", GenR_SDL_GetSIMDAlignment, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSandbox", GenR_SDL_GetSandbox, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetScancodeFromKey", GenR_SDL_GetScancodeFromKey, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetScancodeFromName", GenR_SDL_GetScancodeFromName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetScancodeName", GenR_SDL_GetScancodeName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSensorData", GenR_SDL_GetSensorData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSensorFromID", GenR_SDL_GetSensorFromID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSensorID", GenR_SDL_GetSensorID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSensorName", GenR_SDL_GetSensorName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSensorNameForID", GenR_SDL_GetSensorNameForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSensorNonPortableType", GenR_SDL_GetSensorNonPortableType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSensorNonPortableTypeForID", GenR_SDL_GetSensorNonPortableTypeForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSensorProperties", GenR_SDL_GetSensorProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSensorType", GenR_SDL_GetSensorType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSensorTypeForID", GenR_SDL_GetSensorTypeForID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSilenceValueForFormat", GenR_SDL_GetSilenceValueForFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetStorageFileSize", GenR_SDL_GetStorageFileSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetStoragePathInfo", GenR_SDL_GetStoragePathInfo, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetStorageSpaceRemaining", GenR_SDL_GetStorageSpaceRemaining, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetStringProperty", GenR_SDL_GetStringProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSurfaceAlphaMod", GenR_SDL_GetSurfaceAlphaMod, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSurfaceBlendMode", GenR_SDL_GetSurfaceBlendMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSurfaceClipRect", GenR_SDL_GetSurfaceClipRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSurfaceColorKey", GenR_SDL_GetSurfaceColorKey, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSurfaceColorMod", GenR_SDL_GetSurfaceColorMod, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSurfaceColorspace", GenR_SDL_GetSurfaceColorspace, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSurfacePalette", GenR_SDL_GetSurfacePalette, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSurfaceProperties", GenR_SDL_GetSurfaceProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSystemPageSize", GenR_SDL_GetSystemPageSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSystemRAM", GenR_SDL_GetSystemRAM, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetSystemTheme", GenR_SDL_GetSystemTheme, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextInputArea", GenR_SDL_GetTextInputArea, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextureAlphaMod", GenR_SDL_GetTextureAlphaMod, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextureAlphaModFloat", GenR_SDL_GetTextureAlphaModFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextureBlendMode", GenR_SDL_GetTextureBlendMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextureColorMod", GenR_SDL_GetTextureColorMod, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextureColorModFloat", GenR_SDL_GetTextureColorModFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTexturePalette", GenR_SDL_GetTexturePalette, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextureProperties", GenR_SDL_GetTextureProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextureScaleMode", GenR_SDL_GetTextureScaleMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTextureSize", GenR_SDL_GetTextureSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTicks", GenR_SDL_GetTicks, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTicksNS", GenR_SDL_GetTicksNS, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTouchDeviceName", GenR_SDL_GetTouchDeviceName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTouchDeviceType", GenR_SDL_GetTouchDeviceType, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrayEntryChecked", GenR_SDL_GetTrayEntryChecked, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrayEntryEnabled", GenR_SDL_GetTrayEntryEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrayEntryLabel", GenR_SDL_GetTrayEntryLabel, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrayEntryParent", GenR_SDL_GetTrayEntryParent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrayMenu", GenR_SDL_GetTrayMenu, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrayMenuParentEntry", GenR_SDL_GetTrayMenuParentEntry, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrayMenuParentTray", GenR_SDL_GetTrayMenuParentTray, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTraySubmenu", GenR_SDL_GetTraySubmenu, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetUserFolder", GenR_SDL_GetUserFolder, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetVersion", GenR_SDL_GetVersion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetVideoDriver", GenR_SDL_GetVideoDriver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowAspectRatio", GenR_SDL_GetWindowAspectRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowBordersSize", GenR_SDL_GetWindowBordersSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowDisplayScale", GenR_SDL_GetWindowDisplayScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowFlags", GenR_SDL_GetWindowFlags, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowFromEvent", GenR_SDL_GetWindowFromEvent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowFromID", GenR_SDL_GetWindowFromID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowFullscreenMode", GenR_SDL_GetWindowFullscreenMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowID", GenR_SDL_GetWindowID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowKeyboardGrab", GenR_SDL_GetWindowKeyboardGrab, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowMaximumSize", GenR_SDL_GetWindowMaximumSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowMinimumSize", GenR_SDL_GetWindowMinimumSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowMouseGrab", GenR_SDL_GetWindowMouseGrab, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowOpacity", GenR_SDL_GetWindowOpacity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowParent", GenR_SDL_GetWindowParent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowPixelDensity", GenR_SDL_GetWindowPixelDensity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowPixelFormat", GenR_SDL_GetWindowPixelFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowPosition", GenR_SDL_GetWindowPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowProgressState", GenR_SDL_GetWindowProgressState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowProgressValue", GenR_SDL_GetWindowProgressValue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowProperties", GenR_SDL_GetWindowProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowRelativeMouseMode", GenR_SDL_GetWindowRelativeMouseMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowSafeArea", GenR_SDL_GetWindowSafeArea, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowSize", GenR_SDL_GetWindowSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowSizeInPixels", GenR_SDL_GetWindowSizeInPixels, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowSurface", GenR_SDL_GetWindowSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowSurfaceVSync", GenR_SDL_GetWindowSurfaceVSync, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetWindowTitle", GenR_SDL_GetWindowTitle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HapticEffectSupported", GenR_SDL_HapticEffectSupported, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HapticRumbleSupported", GenR_SDL_HapticRumbleSupported, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasARMSIMD", GenR_SDL_HasARMSIMD, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasAVX", GenR_SDL_HasAVX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasAVX2", GenR_SDL_HasAVX2, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasAVX512F", GenR_SDL_HasAVX512F, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasAltiVec", GenR_SDL_HasAltiVec, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasClipboardData", GenR_SDL_HasClipboardData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasClipboardText", GenR_SDL_HasClipboardText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasEvent", GenR_SDL_HasEvent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasEvents", GenR_SDL_HasEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasGamepad", GenR_SDL_HasGamepad, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasJoystick", GenR_SDL_HasJoystick, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasKeyboard", GenR_SDL_HasKeyboard, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasLASX", GenR_SDL_HasLASX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasLSX", GenR_SDL_HasLSX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasMMX", GenR_SDL_HasMMX, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasMouse", GenR_SDL_HasMouse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasNEON", GenR_SDL_HasNEON, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasPrimarySelectionText", GenR_SDL_HasPrimarySelectionText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasProperty", GenR_SDL_HasProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasRectIntersection", GenR_SDL_HasRectIntersection, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasRectIntersectionFloat", GenR_SDL_HasRectIntersectionFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasSSE", GenR_SDL_HasSSE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasSSE2", GenR_SDL_HasSSE2, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasSSE3", GenR_SDL_HasSSE3, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasSSE41", GenR_SDL_HasSSE41, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasSSE42", GenR_SDL_HasSSE42, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HasScreenKeyboardSupport", GenR_SDL_HasScreenKeyboardSupport, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HideCursor", GenR_SDL_HideCursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "HideWindow", GenR_SDL_HideWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IOFromConstMem", GenR_SDL_IOFromConstMem, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IOFromDynamicMem", GenR_SDL_IOFromDynamicMem, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IOFromFile", GenR_SDL_IOFromFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Init", GenR_SDL_Init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "InitHapticRumble", GenR_SDL_InitHapticRumble, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "InitSubSystem", GenR_SDL_InitSubSystem, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "InsertGPUDebugLabel", GenR_SDL_InsertGPUDebugLabel, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "InsertTrayEntryAt", GenR_SDL_InsertTrayEntryAt, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsAudioDevicePhysical", GenR_SDL_IsAudioDevicePhysical, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsAudioDevicePlayback", GenR_SDL_IsAudioDevicePlayback, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsGamepad", GenR_SDL_IsGamepad, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsJoystickHaptic", GenR_SDL_IsJoystickHaptic, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsJoystickVirtual", GenR_SDL_IsJoystickVirtual, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsMainThread", GenR_SDL_IsMainThread, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsMouseHaptic", GenR_SDL_IsMouseHaptic, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsTV", GenR_SDL_IsTV, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "IsTablet", GenR_SDL_IsTablet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "JoystickConnected", GenR_SDL_JoystickConnected, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "JoystickEventsEnabled", GenR_SDL_JoystickEventsEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "KillProcess", GenR_SDL_KillProcess, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadBMP", GenR_SDL_LoadBMP, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadBMP_IO", GenR_SDL_LoadBMP_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadObject", GenR_SDL_LoadObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadPNG", GenR_SDL_LoadPNG, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadPNG_IO", GenR_SDL_LoadPNG_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadSurface", GenR_SDL_LoadSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadSurface_IO", GenR_SDL_LoadSurface_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LockAudioStream", GenR_SDL_LockAudioStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LockProperties", GenR_SDL_LockProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LockSpinlock", GenR_SDL_LockSpinlock, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LockSurface", GenR_SDL_LockSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MapRGB", GenR_SDL_MapRGB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MapRGBA", GenR_SDL_MapRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MapSurfaceRGB", GenR_SDL_MapSurfaceRGB, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MapSurfaceRGBA", GenR_SDL_MapSurfaceRGBA, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MaximizeWindow", GenR_SDL_MaximizeWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MinimizeWindow", GenR_SDL_MinimizeWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OnApplicationDidEnterBackground", GenR_SDL_OnApplicationDidEnterBackground, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OnApplicationDidEnterForeground", GenR_SDL_OnApplicationDidEnterForeground, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OnApplicationDidReceiveMemoryWarning", GenR_SDL_OnApplicationDidReceiveMemoryWarning, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OnApplicationWillEnterBackground", GenR_SDL_OnApplicationWillEnterBackground, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OnApplicationWillEnterForeground", GenR_SDL_OnApplicationWillEnterForeground, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OnApplicationWillTerminate", GenR_SDL_OnApplicationWillTerminate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenAudioDevice", GenR_SDL_OpenAudioDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenCamera", GenR_SDL_OpenCamera, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenFileStorage", GenR_SDL_OpenFileStorage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenGamepad", GenR_SDL_OpenGamepad, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenHaptic", GenR_SDL_OpenHaptic, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenHapticFromJoystick", GenR_SDL_OpenHapticFromJoystick, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenHapticFromMouse", GenR_SDL_OpenHapticFromMouse, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenJoystick", GenR_SDL_OpenJoystick, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenSensor", GenR_SDL_OpenSensor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenTitleStorage", GenR_SDL_OpenTitleStorage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenURL", GenR_SDL_OpenURL, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OpenUserStorage", GenR_SDL_OpenUserStorage, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "OutOfMemory", GenR_SDL_OutOfMemory, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PauseAudioDevice", GenR_SDL_PauseAudioDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PauseAudioStreamDevice", GenR_SDL_PauseAudioStreamDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PauseHaptic", GenR_SDL_PauseHaptic, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PeepEvents", GenR_SDL_PeepEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PlayHapticRumble", GenR_SDL_PlayHapticRumble, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PollEvent", GenR_SDL_PollEvent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PopGPUDebugGroup", GenR_SDL_PopGPUDebugGroup, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PremultiplySurfaceAlpha", GenR_SDL_PremultiplySurfaceAlpha, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PumpEvents", GenR_SDL_PumpEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PushEvent", GenR_SDL_PushEvent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PushGPUComputeUniformData", GenR_SDL_PushGPUComputeUniformData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PushGPUDebugGroup", GenR_SDL_PushGPUDebugGroup, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PushGPUFragmentUniformData", GenR_SDL_PushGPUFragmentUniformData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PushGPUVertexUniformData", GenR_SDL_PushGPUVertexUniformData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PutAudioStreamData", GenR_SDL_PutAudioStreamData, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "QueryGPUFence", GenR_SDL_QueryGPUFence, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Quit", GenR_SDL_Quit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "QuitSubSystem", GenR_SDL_QuitSubSystem, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RaiseWindow", GenR_SDL_RaiseWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadS16BE", GenR_SDL_ReadS16BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadS16LE", GenR_SDL_ReadS16LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadS32BE", GenR_SDL_ReadS32BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadS32LE", GenR_SDL_ReadS32LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadS64BE", GenR_SDL_ReadS64BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadS64LE", GenR_SDL_ReadS64LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadS8", GenR_SDL_ReadS8, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadSurfacePixel", GenR_SDL_ReadSurfacePixel, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadSurfacePixelFloat", GenR_SDL_ReadSurfacePixelFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadU16BE", GenR_SDL_ReadU16BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadU16LE", GenR_SDL_ReadU16LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadU32BE", GenR_SDL_ReadU32BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadU32LE", GenR_SDL_ReadU32LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadU64BE", GenR_SDL_ReadU64BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadU64LE", GenR_SDL_ReadU64LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReadU8", GenR_SDL_ReadU8, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RegisterEvents", GenR_SDL_RegisterEvents, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReleaseCameraFrame", GenR_SDL_ReleaseCameraFrame, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReleaseGPUBuffer", GenR_SDL_ReleaseGPUBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReleaseGPUComputePipeline", GenR_SDL_ReleaseGPUComputePipeline, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReleaseGPUFence", GenR_SDL_ReleaseGPUFence, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReleaseGPUGraphicsPipeline", GenR_SDL_ReleaseGPUGraphicsPipeline, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReleaseGPUSampler", GenR_SDL_ReleaseGPUSampler, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReleaseGPUShader", GenR_SDL_ReleaseGPUShader, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReleaseGPUTexture", GenR_SDL_ReleaseGPUTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReleaseGPUTransferBuffer", GenR_SDL_ReleaseGPUTransferBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReleaseWindowFromGPUDevice", GenR_SDL_ReleaseWindowFromGPUDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ReloadGamepadMappings", GenR_SDL_ReloadGamepadMappings, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RemovePath", GenR_SDL_RemovePath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RemoveStoragePath", GenR_SDL_RemoveStoragePath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RemoveSurfaceAlternateImages", GenR_SDL_RemoveSurfaceAlternateImages, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RemoveTimer", GenR_SDL_RemoveTimer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RemoveTrayEntry", GenR_SDL_RemoveTrayEntry, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenamePath", GenR_SDL_RenamePath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenameStoragePath", GenR_SDL_RenameStoragePath, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderClear", GenR_SDL_RenderClear, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderClipEnabled", GenR_SDL_RenderClipEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderCoordinatesFromWindow", GenR_SDL_RenderCoordinatesFromWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderCoordinatesToWindow", GenR_SDL_RenderCoordinatesToWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderDebugText", GenR_SDL_RenderDebugText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderFillRect", GenR_SDL_RenderFillRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderFillRects", GenR_SDL_RenderFillRects, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderLine", GenR_SDL_RenderLine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderLines", GenR_SDL_RenderLines, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderPoint", GenR_SDL_RenderPoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderPoints", GenR_SDL_RenderPoints, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderPresent", GenR_SDL_RenderPresent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderReadPixels", GenR_SDL_RenderReadPixels, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderRect", GenR_SDL_RenderRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderRects", GenR_SDL_RenderRects, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderTexture", GenR_SDL_RenderTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderTexture9Grid", GenR_SDL_RenderTexture9Grid, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderTexture9GridTiled", GenR_SDL_RenderTexture9GridTiled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderTextureAffine", GenR_SDL_RenderTextureAffine, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderTextureRotated", GenR_SDL_RenderTextureRotated, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderTextureTiled", GenR_SDL_RenderTextureTiled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RenderViewportSet", GenR_SDL_RenderViewportSet, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResetAssertionReport", GenR_SDL_ResetAssertionReport, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResetHint", GenR_SDL_ResetHint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResetHints", GenR_SDL_ResetHints, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResetKeyboard", GenR_SDL_ResetKeyboard, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResetLogPriorities", GenR_SDL_ResetLogPriorities, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RestoreWindow", GenR_SDL_RestoreWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResumeAudioDevice", GenR_SDL_ResumeAudioDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResumeAudioStreamDevice", GenR_SDL_ResumeAudioStreamDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResumeHaptic", GenR_SDL_ResumeHaptic, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RotateSurface", GenR_SDL_RotateSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RumbleGamepad", GenR_SDL_RumbleGamepad, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RumbleGamepadTriggers", GenR_SDL_RumbleGamepadTriggers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RumbleJoystick", GenR_SDL_RumbleJoystick, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RumbleJoystickTriggers", GenR_SDL_RumbleJoystickTriggers, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RunHapticEffect", GenR_SDL_RunHapticEffect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveBMP", GenR_SDL_SaveBMP, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveBMP_IO", GenR_SDL_SaveBMP_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveFile", GenR_SDL_SaveFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SaveFile_IO", GenR_SDL_SaveFile_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SavePNG", GenR_SDL_SavePNG, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SavePNG_IO", GenR_SDL_SavePNG_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ScaleSurface", GenR_SDL_ScaleSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ScreenKeyboardShown", GenR_SDL_ScreenKeyboardShown, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ScreenSaverEnabled", GenR_SDL_ScreenSaverEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SeekIO", GenR_SDL_SeekIO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SendGamepadEffect", GenR_SDL_SendGamepadEffect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SendJoystickEffect", GenR_SDL_SendJoystickEffect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetAppMetadata", GenR_SDL_SetAppMetadata, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetAppMetadataProperty", GenR_SDL_SetAppMetadataProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetAudioDeviceGain", GenR_SDL_SetAudioDeviceGain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetAudioStreamFormat", GenR_SDL_SetAudioStreamFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetAudioStreamFrequencyRatio", GenR_SDL_SetAudioStreamFrequencyRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetAudioStreamGain", GenR_SDL_SetAudioStreamGain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetBooleanProperty", GenR_SDL_SetBooleanProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetClipboardText", GenR_SDL_SetClipboardText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetCursor", GenR_SDL_SetCursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetDefaultTextureScaleMode", GenR_SDL_SetDefaultTextureScaleMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetEnvironmentVariable", GenR_SDL_SetEnvironmentVariable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetEventEnabled", GenR_SDL_SetEventEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetFloatProperty", GenR_SDL_SetFloatProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGPUAllowedFramesInFlight", GenR_SDL_SetGPUAllowedFramesInFlight, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGPUBlendConstants", GenR_SDL_SetGPUBlendConstants, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGPUBufferName", GenR_SDL_SetGPUBufferName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGPURenderState", GenR_SDL_SetGPURenderState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGPURenderStateFragmentUniforms", GenR_SDL_SetGPURenderStateFragmentUniforms, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGPUScissor", GenR_SDL_SetGPUScissor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGPUStencilReference", GenR_SDL_SetGPUStencilReference, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGPUSwapchainParameters", GenR_SDL_SetGPUSwapchainParameters, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGPUTextureName", GenR_SDL_SetGPUTextureName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGPUViewport", GenR_SDL_SetGPUViewport, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGamepadEventsEnabled", GenR_SDL_SetGamepadEventsEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGamepadLED", GenR_SDL_SetGamepadLED, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGamepadMapping", GenR_SDL_SetGamepadMapping, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGamepadPlayerIndex", GenR_SDL_SetGamepadPlayerIndex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetGamepadSensorEnabled", GenR_SDL_SetGamepadSensorEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetHapticAutocenter", GenR_SDL_SetHapticAutocenter, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetHapticGain", GenR_SDL_SetHapticGain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetHint", GenR_SDL_SetHint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetHintWithPriority", GenR_SDL_SetHintWithPriority, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetInitialized", GenR_SDL_SetInitialized, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetJoystickEventsEnabled", GenR_SDL_SetJoystickEventsEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetJoystickLED", GenR_SDL_SetJoystickLED, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetJoystickPlayerIndex", GenR_SDL_SetJoystickPlayerIndex, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetJoystickVirtualAxis", GenR_SDL_SetJoystickVirtualAxis, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetJoystickVirtualBall", GenR_SDL_SetJoystickVirtualBall, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetJoystickVirtualButton", GenR_SDL_SetJoystickVirtualButton, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetJoystickVirtualHat", GenR_SDL_SetJoystickVirtualHat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetJoystickVirtualTouchpad", GenR_SDL_SetJoystickVirtualTouchpad, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetLogPriorities", GenR_SDL_SetLogPriorities, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetLogPriority", GenR_SDL_SetLogPriority, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetLogPriorityPrefix", GenR_SDL_SetLogPriorityPrefix, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetModState", GenR_SDL_SetModState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetNumberProperty", GenR_SDL_SetNumberProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetPaletteColors", GenR_SDL_SetPaletteColors, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetPrimarySelectionText", GenR_SDL_SetPrimarySelectionText, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetRenderClipRect", GenR_SDL_SetRenderClipRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetRenderColorScale", GenR_SDL_SetRenderColorScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetRenderDrawBlendMode", GenR_SDL_SetRenderDrawBlendMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetRenderDrawColor", GenR_SDL_SetRenderDrawColor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetRenderDrawColorFloat", GenR_SDL_SetRenderDrawColorFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetRenderLogicalPresentation", GenR_SDL_SetRenderLogicalPresentation, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetRenderScale", GenR_SDL_SetRenderScale, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetRenderTarget", GenR_SDL_SetRenderTarget, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetRenderTextureAddressMode", GenR_SDL_SetRenderTextureAddressMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetRenderVSync", GenR_SDL_SetRenderVSync, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetRenderViewport", GenR_SDL_SetRenderViewport, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetScancodeName", GenR_SDL_SetScancodeName, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetStringProperty", GenR_SDL_SetStringProperty, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetSurfaceAlphaMod", GenR_SDL_SetSurfaceAlphaMod, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetSurfaceBlendMode", GenR_SDL_SetSurfaceBlendMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetSurfaceClipRect", GenR_SDL_SetSurfaceClipRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetSurfaceColorKey", GenR_SDL_SetSurfaceColorKey, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetSurfaceColorMod", GenR_SDL_SetSurfaceColorMod, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetSurfaceColorspace", GenR_SDL_SetSurfaceColorspace, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetSurfacePalette", GenR_SDL_SetSurfacePalette, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetSurfaceRLE", GenR_SDL_SetSurfaceRLE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextInputArea", GenR_SDL_SetTextInputArea, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextureAlphaMod", GenR_SDL_SetTextureAlphaMod, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextureAlphaModFloat", GenR_SDL_SetTextureAlphaModFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextureBlendMode", GenR_SDL_SetTextureBlendMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextureColorMod", GenR_SDL_SetTextureColorMod, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextureColorModFloat", GenR_SDL_SetTextureColorModFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTexturePalette", GenR_SDL_SetTexturePalette, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTextureScaleMode", GenR_SDL_SetTextureScaleMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrayEntryChecked", GenR_SDL_SetTrayEntryChecked, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrayEntryEnabled", GenR_SDL_SetTrayEntryEnabled, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrayEntryLabel", GenR_SDL_SetTrayEntryLabel, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrayIcon", GenR_SDL_SetTrayIcon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrayTooltip", GenR_SDL_SetTrayTooltip, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowAlwaysOnTop", GenR_SDL_SetWindowAlwaysOnTop, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowAspectRatio", GenR_SDL_SetWindowAspectRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowBordered", GenR_SDL_SetWindowBordered, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowFillDocument", GenR_SDL_SetWindowFillDocument, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowFocusable", GenR_SDL_SetWindowFocusable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowFullscreen", GenR_SDL_SetWindowFullscreen, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowFullscreenMode", GenR_SDL_SetWindowFullscreenMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowIcon", GenR_SDL_SetWindowIcon, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowKeyboardGrab", GenR_SDL_SetWindowKeyboardGrab, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowMaximumSize", GenR_SDL_SetWindowMaximumSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowMinimumSize", GenR_SDL_SetWindowMinimumSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowModal", GenR_SDL_SetWindowModal, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowMouseGrab", GenR_SDL_SetWindowMouseGrab, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowMouseRect", GenR_SDL_SetWindowMouseRect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowOpacity", GenR_SDL_SetWindowOpacity, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowParent", GenR_SDL_SetWindowParent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowPosition", GenR_SDL_SetWindowPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowProgressState", GenR_SDL_SetWindowProgressState, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowProgressValue", GenR_SDL_SetWindowProgressValue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowRelativeMouseMode", GenR_SDL_SetWindowRelativeMouseMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowResizable", GenR_SDL_SetWindowResizable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowShape", GenR_SDL_SetWindowShape, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowSize", GenR_SDL_SetWindowSize, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowSurfaceVSync", GenR_SDL_SetWindowSurfaceVSync, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetWindowTitle", GenR_SDL_SetWindowTitle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShouldInit", GenR_SDL_ShouldInit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShouldQuit", GenR_SDL_ShouldQuit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShowCursor", GenR_SDL_ShowCursor, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShowMessageBox", GenR_SDL_ShowMessageBox, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShowSimpleMessageBox", GenR_SDL_ShowSimpleMessageBox, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShowWindow", GenR_SDL_ShowWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ShowWindowSystemMenu", GenR_SDL_ShowWindowSystemMenu, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SignalAsyncIOQueue", GenR_SDL_SignalAsyncIOQueue, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StartTextInput", GenR_SDL_StartTextInput, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StartTextInputWithProperties", GenR_SDL_StartTextInputWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StopHapticEffect", GenR_SDL_StopHapticEffect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StopHapticEffects", GenR_SDL_StopHapticEffects, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StopHapticRumble", GenR_SDL_StopHapticRumble, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StopTextInput", GenR_SDL_StopTextInput, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StorageReady", GenR_SDL_StorageReady, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StretchSurface", GenR_SDL_StretchSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StringToGUID", GenR_SDL_StringToGUID, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SubmitGPUCommandBuffer", GenR_SDL_SubmitGPUCommandBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SubmitGPUCommandBufferAndAcquireFence", GenR_SDL_SubmitGPUCommandBufferAndAcquireFence, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SurfaceHasAlternateImages", GenR_SDL_SurfaceHasAlternateImages, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SurfaceHasColorKey", GenR_SDL_SurfaceHasColorKey, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SurfaceHasRLE", GenR_SDL_SurfaceHasRLE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SyncWindow", GenR_SDL_SyncWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TellIO", GenR_SDL_TellIO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TextInputActive", GenR_SDL_TextInputActive, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TimeFromWindows", GenR_SDL_TimeFromWindows, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TimeToDateTime", GenR_SDL_TimeToDateTime, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TimeToWindows", GenR_SDL_TimeToWindows, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TryLockSpinlock", GenR_SDL_TryLockSpinlock, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UCS4ToUTF8", GenR_SDL_UCS4ToUTF8, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UnbindAudioStream", GenR_SDL_UnbindAudioStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UnloadObject", GenR_SDL_UnloadObject, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UnlockAudioStream", GenR_SDL_UnlockAudioStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UnlockProperties", GenR_SDL_UnlockProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UnlockSpinlock", GenR_SDL_UnlockSpinlock, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UnlockSurface", GenR_SDL_UnlockSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UnlockTexture", GenR_SDL_UnlockTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UnmapGPUTransferBuffer", GenR_SDL_UnmapGPUTransferBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UnsetEnvironmentVariable", GenR_SDL_UnsetEnvironmentVariable, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UpdateGamepads", GenR_SDL_UpdateGamepads, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UpdateHapticEffect", GenR_SDL_UpdateHapticEffect, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UpdateJoysticks", GenR_SDL_UpdateJoysticks, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UpdateSensors", GenR_SDL_UpdateSensors, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UpdateTrays", GenR_SDL_UpdateTrays, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UpdateWindowSurface", GenR_SDL_UpdateWindowSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UpdateWindowSurfaceRects", GenR_SDL_UpdateWindowSurfaceRects, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UploadToGPUBuffer", GenR_SDL_UploadToGPUBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UploadToGPUTexture", GenR_SDL_UploadToGPUTexture, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WaitAsyncIOResult", GenR_SDL_WaitAsyncIOResult, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WaitEvent", GenR_SDL_WaitEvent, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WaitEventTimeout", GenR_SDL_WaitEventTimeout, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WaitForGPUIdle", GenR_SDL_WaitForGPUIdle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WaitForGPUSwapchain", GenR_SDL_WaitForGPUSwapchain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WaitProcess", GenR_SDL_WaitProcess, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WarpMouseGlobal", GenR_SDL_WarpMouseGlobal, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WarpMouseInWindow", GenR_SDL_WarpMouseInWindow, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WasInit", GenR_SDL_WasInit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WindowHasSurface", GenR_SDL_WindowHasSurface, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WindowSupportsGPUPresentMode", GenR_SDL_WindowSupportsGPUPresentMode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WindowSupportsGPUSwapchainComposition", GenR_SDL_WindowSupportsGPUSwapchainComposition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteIO", GenR_SDL_WriteIO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteS16BE", GenR_SDL_WriteS16BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteS16LE", GenR_SDL_WriteS16LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteS32BE", GenR_SDL_WriteS32BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteS32LE", GenR_SDL_WriteS32LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteS64BE", GenR_SDL_WriteS64BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteS64LE", GenR_SDL_WriteS64LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteS8", GenR_SDL_WriteS8, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteStorageFile", GenR_SDL_WriteStorageFile, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteSurfacePixel", GenR_SDL_WriteSurfacePixel, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteSurfacePixelFloat", GenR_SDL_WriteSurfacePixelFloat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteU16BE", GenR_SDL_WriteU16BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteU16LE", GenR_SDL_WriteU16LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteU32BE", GenR_SDL_WriteU32BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteU32LE", GenR_SDL_WriteU32LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteU64BE", GenR_SDL_WriteU64BE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteU64LE", GenR_SDL_WriteU64LE, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteU8", GenR_SDL_WriteU8, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getenv", GenR_SDL_getenv, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getenv_unsafe", GenR_SDL_getenv_unsafe, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_ble_scan", GenR_SDL_hid_ble_scan, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_close", GenR_SDL_hid_close, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_device_change_count", GenR_SDL_hid_device_change_count, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_enumerate", GenR_SDL_hid_enumerate, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_exit", GenR_SDL_hid_exit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_free_enumeration", GenR_SDL_hid_free_enumeration, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_get_device_info", GenR_SDL_hid_get_device_info, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_get_properties", GenR_SDL_hid_get_properties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_init", GenR_SDL_hid_init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_open_path", GenR_SDL_hid_open_path, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_send_feature_report", GenR_SDL_hid_send_feature_report, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_set_nonblocking", GenR_SDL_hid_set_nonblocking, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "hid_write", GenR_SDL_hid_write, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "iconv_string", GenR_SDL_iconv_string, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "setenv_unsafe", GenR_SDL_setenv_unsafe, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "unsetenv_unsafe", GenR_SDL_unsetenv_unsafe, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "utf8strlen", GenR_SDL_utf8strlen, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "utf8strnlen", GenR_SDL_utf8strnlen, MRB_ARGS_ANY());
    mrb_define_const(mrb, mod, "APP_CONTINUE", mrb_int_value(mrb, (mrb_int)SDL_APP_CONTINUE));
    mrb_define_const(mrb, mod, "APP_SUCCESS", mrb_int_value(mrb, (mrb_int)SDL_APP_SUCCESS));
    mrb_define_const(mrb, mod, "APP_FAILURE", mrb_int_value(mrb, (mrb_int)SDL_APP_FAILURE));
    mrb_define_const(mrb, mod, "ARRAYORDER_NONE", mrb_int_value(mrb, (mrb_int)SDL_ARRAYORDER_NONE));
    mrb_define_const(mrb, mod, "ARRAYORDER_RGB", mrb_int_value(mrb, (mrb_int)SDL_ARRAYORDER_RGB));
    mrb_define_const(mrb, mod, "ARRAYORDER_RGBA", mrb_int_value(mrb, (mrb_int)SDL_ARRAYORDER_RGBA));
    mrb_define_const(mrb, mod, "ARRAYORDER_ARGB", mrb_int_value(mrb, (mrb_int)SDL_ARRAYORDER_ARGB));
    mrb_define_const(mrb, mod, "ARRAYORDER_BGR", mrb_int_value(mrb, (mrb_int)SDL_ARRAYORDER_BGR));
    mrb_define_const(mrb, mod, "ARRAYORDER_BGRA", mrb_int_value(mrb, (mrb_int)SDL_ARRAYORDER_BGRA));
    mrb_define_const(mrb, mod, "ARRAYORDER_ABGR", mrb_int_value(mrb, (mrb_int)SDL_ARRAYORDER_ABGR));
    mrb_define_const(mrb, mod, "ASSERTION_RETRY", mrb_int_value(mrb, (mrb_int)SDL_ASSERTION_RETRY));
    mrb_define_const(mrb, mod, "ASSERTION_BREAK", mrb_int_value(mrb, (mrb_int)SDL_ASSERTION_BREAK));
    mrb_define_const(mrb, mod, "ASSERTION_ABORT", mrb_int_value(mrb, (mrb_int)SDL_ASSERTION_ABORT));
    mrb_define_const(mrb, mod, "ASSERTION_IGNORE", mrb_int_value(mrb, (mrb_int)SDL_ASSERTION_IGNORE));
    mrb_define_const(mrb, mod, "ASSERTION_ALWAYS_IGNORE", mrb_int_value(mrb, (mrb_int)SDL_ASSERTION_ALWAYS_IGNORE));
    mrb_define_const(mrb, mod, "ASYNCIO_COMPLETE", mrb_int_value(mrb, (mrb_int)SDL_ASYNCIO_COMPLETE));
    mrb_define_const(mrb, mod, "ASYNCIO_FAILURE", mrb_int_value(mrb, (mrb_int)SDL_ASYNCIO_FAILURE));
    mrb_define_const(mrb, mod, "ASYNCIO_CANCELED", mrb_int_value(mrb, (mrb_int)SDL_ASYNCIO_CANCELED));
    mrb_define_const(mrb, mod, "ASYNCIO_TASK_READ", mrb_int_value(mrb, (mrb_int)SDL_ASYNCIO_TASK_READ));
    mrb_define_const(mrb, mod, "ASYNCIO_TASK_WRITE", mrb_int_value(mrb, (mrb_int)SDL_ASYNCIO_TASK_WRITE));
    mrb_define_const(mrb, mod, "ASYNCIO_TASK_CLOSE", mrb_int_value(mrb, (mrb_int)SDL_ASYNCIO_TASK_CLOSE));
    mrb_define_const(mrb, mod, "AUDIO_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_AUDIO_UNKNOWN));
    mrb_define_const(mrb, mod, "AUDIO_U8", mrb_int_value(mrb, (mrb_int)SDL_AUDIO_U8));
    mrb_define_const(mrb, mod, "AUDIO_S8", mrb_int_value(mrb, (mrb_int)SDL_AUDIO_S8));
    mrb_define_const(mrb, mod, "AUDIO_S16LE", mrb_int_value(mrb, (mrb_int)SDL_AUDIO_S16LE));
    mrb_define_const(mrb, mod, "AUDIO_S16BE", mrb_int_value(mrb, (mrb_int)SDL_AUDIO_S16BE));
    mrb_define_const(mrb, mod, "AUDIO_S32LE", mrb_int_value(mrb, (mrb_int)SDL_AUDIO_S32LE));
    mrb_define_const(mrb, mod, "AUDIO_S32BE", mrb_int_value(mrb, (mrb_int)SDL_AUDIO_S32BE));
    mrb_define_const(mrb, mod, "AUDIO_F32LE", mrb_int_value(mrb, (mrb_int)SDL_AUDIO_F32LE));
    mrb_define_const(mrb, mod, "AUDIO_F32BE", mrb_int_value(mrb, (mrb_int)SDL_AUDIO_F32BE));
    mrb_define_const(mrb, mod, "BYTEORDER", mrb_int_value(mrb, (mrb_int)SDL_BYTEORDER));
    mrb_define_const(mrb, mod, "AUDIO_S32", mrb_int_value(mrb, (mrb_int)SDL_AUDIO_S32));
    mrb_define_const(mrb, mod, "AUDIO_F32", mrb_int_value(mrb, (mrb_int)SDL_AUDIO_F32));
    mrb_define_const(mrb, mod, "BITMAPORDER_NONE", mrb_int_value(mrb, (mrb_int)SDL_BITMAPORDER_NONE));
    mrb_define_const(mrb, mod, "BITMAPORDER_4321", mrb_int_value(mrb, (mrb_int)SDL_BITMAPORDER_4321));
    mrb_define_const(mrb, mod, "BITMAPORDER_1234", mrb_int_value(mrb, (mrb_int)SDL_BITMAPORDER_1234));
    mrb_define_const(mrb, mod, "BLENDFACTOR_ZERO", mrb_int_value(mrb, (mrb_int)SDL_BLENDFACTOR_ZERO));
    mrb_define_const(mrb, mod, "BLENDFACTOR_ONE", mrb_int_value(mrb, (mrb_int)SDL_BLENDFACTOR_ONE));
    mrb_define_const(mrb, mod, "BLENDFACTOR_SRC_COLOR", mrb_int_value(mrb, (mrb_int)SDL_BLENDFACTOR_SRC_COLOR));
    mrb_define_const(mrb, mod, "BLENDFACTOR_ONE_MINUS_SRC_COLOR", mrb_int_value(mrb, (mrb_int)SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR));
    mrb_define_const(mrb, mod, "BLENDFACTOR_SRC_ALPHA", mrb_int_value(mrb, (mrb_int)SDL_BLENDFACTOR_SRC_ALPHA));
    mrb_define_const(mrb, mod, "BLENDFACTOR_ONE_MINUS_SRC_ALPHA", mrb_int_value(mrb, (mrb_int)SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA));
    mrb_define_const(mrb, mod, "BLENDFACTOR_DST_COLOR", mrb_int_value(mrb, (mrb_int)SDL_BLENDFACTOR_DST_COLOR));
    mrb_define_const(mrb, mod, "BLENDFACTOR_ONE_MINUS_DST_COLOR", mrb_int_value(mrb, (mrb_int)SDL_BLENDFACTOR_ONE_MINUS_DST_COLOR));
    mrb_define_const(mrb, mod, "BLENDFACTOR_DST_ALPHA", mrb_int_value(mrb, (mrb_int)SDL_BLENDFACTOR_DST_ALPHA));
    mrb_define_const(mrb, mod, "BLENDFACTOR_ONE_MINUS_DST_ALPHA", mrb_int_value(mrb, (mrb_int)SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA));
    mrb_define_const(mrb, mod, "BLENDOPERATION_ADD", mrb_int_value(mrb, (mrb_int)SDL_BLENDOPERATION_ADD));
    mrb_define_const(mrb, mod, "BLENDOPERATION_SUBTRACT", mrb_int_value(mrb, (mrb_int)SDL_BLENDOPERATION_SUBTRACT));
    mrb_define_const(mrb, mod, "BLENDOPERATION_REV_SUBTRACT", mrb_int_value(mrb, (mrb_int)SDL_BLENDOPERATION_REV_SUBTRACT));
    mrb_define_const(mrb, mod, "BLENDOPERATION_MINIMUM", mrb_int_value(mrb, (mrb_int)SDL_BLENDOPERATION_MINIMUM));
    mrb_define_const(mrb, mod, "BLENDOPERATION_MAXIMUM", mrb_int_value(mrb, (mrb_int)SDL_BLENDOPERATION_MAXIMUM));
    mrb_define_const(mrb, mod, "CAMERA_PERMISSION_STATE_DENIED", mrb_int_value(mrb, (mrb_int)SDL_CAMERA_PERMISSION_STATE_DENIED));
    mrb_define_const(mrb, mod, "CAMERA_PERMISSION_STATE_PENDING", mrb_int_value(mrb, (mrb_int)SDL_CAMERA_PERMISSION_STATE_PENDING));
    mrb_define_const(mrb, mod, "CAMERA_PERMISSION_STATE_APPROVED", mrb_int_value(mrb, (mrb_int)SDL_CAMERA_PERMISSION_STATE_APPROVED));
    mrb_define_const(mrb, mod, "CAMERA_POSITION_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_CAMERA_POSITION_UNKNOWN));
    mrb_define_const(mrb, mod, "CAMERA_POSITION_FRONT_FACING", mrb_int_value(mrb, (mrb_int)SDL_CAMERA_POSITION_FRONT_FACING));
    mrb_define_const(mrb, mod, "CAMERA_POSITION_BACK_FACING", mrb_int_value(mrb, (mrb_int)SDL_CAMERA_POSITION_BACK_FACING));
    mrb_define_const(mrb, mod, "CAPITALIZE_NONE", mrb_int_value(mrb, (mrb_int)SDL_CAPITALIZE_NONE));
    mrb_define_const(mrb, mod, "CAPITALIZE_SENTENCES", mrb_int_value(mrb, (mrb_int)SDL_CAPITALIZE_SENTENCES));
    mrb_define_const(mrb, mod, "CAPITALIZE_WORDS", mrb_int_value(mrb, (mrb_int)SDL_CAPITALIZE_WORDS));
    mrb_define_const(mrb, mod, "CAPITALIZE_LETTERS", mrb_int_value(mrb, (mrb_int)SDL_CAPITALIZE_LETTERS));
    mrb_define_const(mrb, mod, "CHROMA_LOCATION_NONE", mrb_int_value(mrb, (mrb_int)SDL_CHROMA_LOCATION_NONE));
    mrb_define_const(mrb, mod, "CHROMA_LOCATION_LEFT", mrb_int_value(mrb, (mrb_int)SDL_CHROMA_LOCATION_LEFT));
    mrb_define_const(mrb, mod, "CHROMA_LOCATION_CENTER", mrb_int_value(mrb, (mrb_int)SDL_CHROMA_LOCATION_CENTER));
    mrb_define_const(mrb, mod, "CHROMA_LOCATION_TOPLEFT", mrb_int_value(mrb, (mrb_int)SDL_CHROMA_LOCATION_TOPLEFT));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_UNKNOWN));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_BT709", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_BT709));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_UNSPECIFIED", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_UNSPECIFIED));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_BT470M", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_BT470M));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_BT470BG", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_BT470BG));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_BT601", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_BT601));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_SMPTE240", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_SMPTE240));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_GENERIC_FILM", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_GENERIC_FILM));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_BT2020", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_BT2020));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_XYZ", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_XYZ));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_SMPTE431", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_SMPTE431));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_SMPTE432", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_SMPTE432));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_EBU3213", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_EBU3213));
    mrb_define_const(mrb, mod, "COLOR_PRIMARIES_CUSTOM", mrb_int_value(mrb, (mrb_int)SDL_COLOR_PRIMARIES_CUSTOM));
    mrb_define_const(mrb, mod, "COLOR_RANGE_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_COLOR_RANGE_UNKNOWN));
    mrb_define_const(mrb, mod, "COLOR_RANGE_LIMITED", mrb_int_value(mrb, (mrb_int)SDL_COLOR_RANGE_LIMITED));
    mrb_define_const(mrb, mod, "COLOR_RANGE_FULL", mrb_int_value(mrb, (mrb_int)SDL_COLOR_RANGE_FULL));
    mrb_define_const(mrb, mod, "COLOR_TYPE_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_COLOR_TYPE_UNKNOWN));
    mrb_define_const(mrb, mod, "COLOR_TYPE_RGB", mrb_int_value(mrb, (mrb_int)SDL_COLOR_TYPE_RGB));
    mrb_define_const(mrb, mod, "COLOR_TYPE_YCBCR", mrb_int_value(mrb, (mrb_int)SDL_COLOR_TYPE_YCBCR));
    mrb_define_const(mrb, mod, "COLORSPACE_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_UNKNOWN));
    mrb_define_const(mrb, mod, "COLORSPACE_SRGB", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_SRGB));
    mrb_define_const(mrb, mod, "COLORSPACE_SRGB_LINEAR", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_SRGB_LINEAR));
    mrb_define_const(mrb, mod, "COLORSPACE_HDR10", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_HDR10));
    mrb_define_const(mrb, mod, "COLORSPACE_JPEG", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_JPEG));
    mrb_define_const(mrb, mod, "COLORSPACE_BT601_LIMITED", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_BT601_LIMITED));
    mrb_define_const(mrb, mod, "COLORSPACE_BT601_FULL", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_BT601_FULL));
    mrb_define_const(mrb, mod, "COLORSPACE_BT709_LIMITED", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_BT709_LIMITED));
    mrb_define_const(mrb, mod, "COLORSPACE_BT709_FULL", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_BT709_FULL));
    mrb_define_const(mrb, mod, "COLORSPACE_BT2020_LIMITED", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_BT2020_LIMITED));
    mrb_define_const(mrb, mod, "COLORSPACE_BT2020_FULL", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_BT2020_FULL));
    mrb_define_const(mrb, mod, "COLORSPACE_RGB_DEFAULT", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_RGB_DEFAULT));
    mrb_define_const(mrb, mod, "COLORSPACE_YUV_DEFAULT", mrb_int_value(mrb, (mrb_int)SDL_COLORSPACE_YUV_DEFAULT));
    mrb_define_const(mrb, mod, "DATE_FORMAT_YYYYMMDD", mrb_int_value(mrb, (mrb_int)SDL_DATE_FORMAT_YYYYMMDD));
    mrb_define_const(mrb, mod, "DATE_FORMAT_DDMMYYYY", mrb_int_value(mrb, (mrb_int)SDL_DATE_FORMAT_DDMMYYYY));
    mrb_define_const(mrb, mod, "DATE_FORMAT_MMDDYYYY", mrb_int_value(mrb, (mrb_int)SDL_DATE_FORMAT_MMDDYYYY));
    mrb_define_const(mrb, mod, "ORIENTATION_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_ORIENTATION_UNKNOWN));
    mrb_define_const(mrb, mod, "ORIENTATION_LANDSCAPE", mrb_int_value(mrb, (mrb_int)SDL_ORIENTATION_LANDSCAPE));
    mrb_define_const(mrb, mod, "ORIENTATION_LANDSCAPE_FLIPPED", mrb_int_value(mrb, (mrb_int)SDL_ORIENTATION_LANDSCAPE_FLIPPED));
    mrb_define_const(mrb, mod, "ORIENTATION_PORTRAIT", mrb_int_value(mrb, (mrb_int)SDL_ORIENTATION_PORTRAIT));
    mrb_define_const(mrb, mod, "ORIENTATION_PORTRAIT_FLIPPED", mrb_int_value(mrb, (mrb_int)SDL_ORIENTATION_PORTRAIT_FLIPPED));
    mrb_define_const(mrb, mod, "ENUM_CONTINUE", mrb_int_value(mrb, (mrb_int)SDL_ENUM_CONTINUE));
    mrb_define_const(mrb, mod, "ENUM_SUCCESS", mrb_int_value(mrb, (mrb_int)SDL_ENUM_SUCCESS));
    mrb_define_const(mrb, mod, "ENUM_FAILURE", mrb_int_value(mrb, (mrb_int)SDL_ENUM_FAILURE));
    mrb_define_const(mrb, mod, "ADDEVENT", mrb_int_value(mrb, (mrb_int)SDL_ADDEVENT));
    mrb_define_const(mrb, mod, "PEEKEVENT", mrb_int_value(mrb, (mrb_int)SDL_PEEKEVENT));
    mrb_define_const(mrb, mod, "GETEVENT", mrb_int_value(mrb, (mrb_int)SDL_GETEVENT));
    mrb_define_const(mrb, mod, "EVENT_FIRST", mrb_int_value(mrb, (mrb_int)SDL_EVENT_FIRST));
    mrb_define_const(mrb, mod, "EVENT_QUIT", mrb_int_value(mrb, (mrb_int)SDL_EVENT_QUIT));
    mrb_define_const(mrb, mod, "EVENT_TERMINATING", mrb_int_value(mrb, (mrb_int)SDL_EVENT_TERMINATING));
    mrb_define_const(mrb, mod, "EVENT_LOW_MEMORY", mrb_int_value(mrb, (mrb_int)SDL_EVENT_LOW_MEMORY));
    mrb_define_const(mrb, mod, "EVENT_WILL_ENTER_BACKGROUND", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WILL_ENTER_BACKGROUND));
    mrb_define_const(mrb, mod, "EVENT_DID_ENTER_BACKGROUND", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DID_ENTER_BACKGROUND));
    mrb_define_const(mrb, mod, "EVENT_WILL_ENTER_FOREGROUND", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WILL_ENTER_FOREGROUND));
    mrb_define_const(mrb, mod, "EVENT_DID_ENTER_FOREGROUND", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DID_ENTER_FOREGROUND));
    mrb_define_const(mrb, mod, "EVENT_LOCALE_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_LOCALE_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_SYSTEM_THEME_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_SYSTEM_THEME_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_DISPLAY_ORIENTATION", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DISPLAY_ORIENTATION));
    mrb_define_const(mrb, mod, "EVENT_DISPLAY_ADDED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DISPLAY_ADDED));
    mrb_define_const(mrb, mod, "EVENT_DISPLAY_REMOVED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DISPLAY_REMOVED));
    mrb_define_const(mrb, mod, "EVENT_DISPLAY_MOVED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DISPLAY_MOVED));
    mrb_define_const(mrb, mod, "EVENT_DISPLAY_DESKTOP_MODE_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DISPLAY_DESKTOP_MODE_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_DISPLAY_CURRENT_MODE_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DISPLAY_CURRENT_MODE_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_DISPLAY_CONTENT_SCALE_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_DISPLAY_USABLE_BOUNDS_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DISPLAY_USABLE_BOUNDS_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_DISPLAY_FIRST", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DISPLAY_FIRST));
    mrb_define_const(mrb, mod, "EVENT_DISPLAY_LAST", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DISPLAY_LAST));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_SHOWN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_SHOWN));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_HIDDEN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_HIDDEN));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_EXPOSED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_EXPOSED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_MOVED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_MOVED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_RESIZED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_RESIZED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_PIXEL_SIZE_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_METAL_VIEW_RESIZED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_METAL_VIEW_RESIZED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_MINIMIZED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_MINIMIZED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_MAXIMIZED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_MAXIMIZED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_RESTORED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_RESTORED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_MOUSE_ENTER", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_MOUSE_ENTER));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_MOUSE_LEAVE", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_MOUSE_LEAVE));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_FOCUS_GAINED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_FOCUS_GAINED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_FOCUS_LOST", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_FOCUS_LOST));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_CLOSE_REQUESTED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_CLOSE_REQUESTED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_HIT_TEST", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_HIT_TEST));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_ICCPROF_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_ICCPROF_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_DISPLAY_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_DISPLAY_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_DISPLAY_SCALE_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_DISPLAY_SCALE_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_SAFE_AREA_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_SAFE_AREA_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_OCCLUDED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_OCCLUDED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_ENTER_FULLSCREEN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_ENTER_FULLSCREEN));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_LEAVE_FULLSCREEN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_LEAVE_FULLSCREEN));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_DESTROYED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_DESTROYED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_HDR_STATE_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_HDR_STATE_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_FIRST", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_FIRST));
    mrb_define_const(mrb, mod, "EVENT_WINDOW_LAST", mrb_int_value(mrb, (mrb_int)SDL_EVENT_WINDOW_LAST));
    mrb_define_const(mrb, mod, "EVENT_KEY_DOWN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_KEY_DOWN));
    mrb_define_const(mrb, mod, "EVENT_KEY_UP", mrb_int_value(mrb, (mrb_int)SDL_EVENT_KEY_UP));
    mrb_define_const(mrb, mod, "EVENT_TEXT_EDITING", mrb_int_value(mrb, (mrb_int)SDL_EVENT_TEXT_EDITING));
    mrb_define_const(mrb, mod, "EVENT_TEXT_INPUT", mrb_int_value(mrb, (mrb_int)SDL_EVENT_TEXT_INPUT));
    mrb_define_const(mrb, mod, "EVENT_KEYMAP_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_KEYMAP_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_KEYBOARD_ADDED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_KEYBOARD_ADDED));
    mrb_define_const(mrb, mod, "EVENT_KEYBOARD_REMOVED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_KEYBOARD_REMOVED));
    mrb_define_const(mrb, mod, "EVENT_TEXT_EDITING_CANDIDATES", mrb_int_value(mrb, (mrb_int)SDL_EVENT_TEXT_EDITING_CANDIDATES));
    mrb_define_const(mrb, mod, "EVENT_SCREEN_KEYBOARD_SHOWN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_SCREEN_KEYBOARD_SHOWN));
    mrb_define_const(mrb, mod, "EVENT_SCREEN_KEYBOARD_HIDDEN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_SCREEN_KEYBOARD_HIDDEN));
    mrb_define_const(mrb, mod, "EVENT_MOUSE_MOTION", mrb_int_value(mrb, (mrb_int)SDL_EVENT_MOUSE_MOTION));
    mrb_define_const(mrb, mod, "EVENT_MOUSE_BUTTON_DOWN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_MOUSE_BUTTON_DOWN));
    mrb_define_const(mrb, mod, "EVENT_MOUSE_BUTTON_UP", mrb_int_value(mrb, (mrb_int)SDL_EVENT_MOUSE_BUTTON_UP));
    mrb_define_const(mrb, mod, "EVENT_MOUSE_WHEEL", mrb_int_value(mrb, (mrb_int)SDL_EVENT_MOUSE_WHEEL));
    mrb_define_const(mrb, mod, "EVENT_MOUSE_ADDED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_MOUSE_ADDED));
    mrb_define_const(mrb, mod, "EVENT_MOUSE_REMOVED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_MOUSE_REMOVED));
    mrb_define_const(mrb, mod, "EVENT_JOYSTICK_AXIS_MOTION", mrb_int_value(mrb, (mrb_int)SDL_EVENT_JOYSTICK_AXIS_MOTION));
    mrb_define_const(mrb, mod, "EVENT_JOYSTICK_BALL_MOTION", mrb_int_value(mrb, (mrb_int)SDL_EVENT_JOYSTICK_BALL_MOTION));
    mrb_define_const(mrb, mod, "EVENT_JOYSTICK_HAT_MOTION", mrb_int_value(mrb, (mrb_int)SDL_EVENT_JOYSTICK_HAT_MOTION));
    mrb_define_const(mrb, mod, "EVENT_JOYSTICK_BUTTON_DOWN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_JOYSTICK_BUTTON_DOWN));
    mrb_define_const(mrb, mod, "EVENT_JOYSTICK_BUTTON_UP", mrb_int_value(mrb, (mrb_int)SDL_EVENT_JOYSTICK_BUTTON_UP));
    mrb_define_const(mrb, mod, "EVENT_JOYSTICK_ADDED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_JOYSTICK_ADDED));
    mrb_define_const(mrb, mod, "EVENT_JOYSTICK_REMOVED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_JOYSTICK_REMOVED));
    mrb_define_const(mrb, mod, "EVENT_JOYSTICK_BATTERY_UPDATED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_JOYSTICK_BATTERY_UPDATED));
    mrb_define_const(mrb, mod, "EVENT_JOYSTICK_UPDATE_COMPLETE", mrb_int_value(mrb, (mrb_int)SDL_EVENT_JOYSTICK_UPDATE_COMPLETE));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_AXIS_MOTION", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_AXIS_MOTION));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_BUTTON_DOWN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_BUTTON_DOWN));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_BUTTON_UP", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_BUTTON_UP));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_ADDED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_ADDED));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_REMOVED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_REMOVED));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_REMAPPED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_REMAPPED));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_TOUCHPAD_DOWN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_TOUCHPAD_MOTION", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_TOUCHPAD_UP", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_TOUCHPAD_UP));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_SENSOR_UPDATE", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_SENSOR_UPDATE));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_UPDATE_COMPLETE", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_UPDATE_COMPLETE));
    mrb_define_const(mrb, mod, "EVENT_GAMEPAD_STEAM_HANDLE_UPDATED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_GAMEPAD_STEAM_HANDLE_UPDATED));
    mrb_define_const(mrb, mod, "EVENT_FINGER_DOWN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_FINGER_DOWN));
    mrb_define_const(mrb, mod, "EVENT_FINGER_UP", mrb_int_value(mrb, (mrb_int)SDL_EVENT_FINGER_UP));
    mrb_define_const(mrb, mod, "EVENT_FINGER_MOTION", mrb_int_value(mrb, (mrb_int)SDL_EVENT_FINGER_MOTION));
    mrb_define_const(mrb, mod, "EVENT_FINGER_CANCELED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_FINGER_CANCELED));
    mrb_define_const(mrb, mod, "EVENT_PINCH_BEGIN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PINCH_BEGIN));
    mrb_define_const(mrb, mod, "EVENT_PINCH_UPDATE", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PINCH_UPDATE));
    mrb_define_const(mrb, mod, "EVENT_PINCH_END", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PINCH_END));
    mrb_define_const(mrb, mod, "EVENT_CLIPBOARD_UPDATE", mrb_int_value(mrb, (mrb_int)SDL_EVENT_CLIPBOARD_UPDATE));
    mrb_define_const(mrb, mod, "EVENT_DROP_FILE", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DROP_FILE));
    mrb_define_const(mrb, mod, "EVENT_DROP_TEXT", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DROP_TEXT));
    mrb_define_const(mrb, mod, "EVENT_DROP_BEGIN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DROP_BEGIN));
    mrb_define_const(mrb, mod, "EVENT_DROP_COMPLETE", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DROP_COMPLETE));
    mrb_define_const(mrb, mod, "EVENT_DROP_POSITION", mrb_int_value(mrb, (mrb_int)SDL_EVENT_DROP_POSITION));
    mrb_define_const(mrb, mod, "EVENT_AUDIO_DEVICE_ADDED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_AUDIO_DEVICE_ADDED));
    mrb_define_const(mrb, mod, "EVENT_AUDIO_DEVICE_REMOVED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_AUDIO_DEVICE_REMOVED));
    mrb_define_const(mrb, mod, "EVENT_AUDIO_DEVICE_FORMAT_CHANGED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_AUDIO_DEVICE_FORMAT_CHANGED));
    mrb_define_const(mrb, mod, "EVENT_SENSOR_UPDATE", mrb_int_value(mrb, (mrb_int)SDL_EVENT_SENSOR_UPDATE));
    mrb_define_const(mrb, mod, "EVENT_PEN_PROXIMITY_IN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PEN_PROXIMITY_IN));
    mrb_define_const(mrb, mod, "EVENT_PEN_PROXIMITY_OUT", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PEN_PROXIMITY_OUT));
    mrb_define_const(mrb, mod, "EVENT_PEN_DOWN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PEN_DOWN));
    mrb_define_const(mrb, mod, "EVENT_PEN_UP", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PEN_UP));
    mrb_define_const(mrb, mod, "EVENT_PEN_BUTTON_DOWN", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PEN_BUTTON_DOWN));
    mrb_define_const(mrb, mod, "EVENT_PEN_BUTTON_UP", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PEN_BUTTON_UP));
    mrb_define_const(mrb, mod, "EVENT_PEN_MOTION", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PEN_MOTION));
    mrb_define_const(mrb, mod, "EVENT_PEN_AXIS", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PEN_AXIS));
    mrb_define_const(mrb, mod, "EVENT_CAMERA_DEVICE_ADDED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_CAMERA_DEVICE_ADDED));
    mrb_define_const(mrb, mod, "EVENT_CAMERA_DEVICE_REMOVED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_CAMERA_DEVICE_REMOVED));
    mrb_define_const(mrb, mod, "EVENT_CAMERA_DEVICE_APPROVED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_CAMERA_DEVICE_APPROVED));
    mrb_define_const(mrb, mod, "EVENT_CAMERA_DEVICE_DENIED", mrb_int_value(mrb, (mrb_int)SDL_EVENT_CAMERA_DEVICE_DENIED));
    mrb_define_const(mrb, mod, "EVENT_RENDER_TARGETS_RESET", mrb_int_value(mrb, (mrb_int)SDL_EVENT_RENDER_TARGETS_RESET));
    mrb_define_const(mrb, mod, "EVENT_RENDER_DEVICE_RESET", mrb_int_value(mrb, (mrb_int)SDL_EVENT_RENDER_DEVICE_RESET));
    mrb_define_const(mrb, mod, "EVENT_RENDER_DEVICE_LOST", mrb_int_value(mrb, (mrb_int)SDL_EVENT_RENDER_DEVICE_LOST));
    mrb_define_const(mrb, mod, "EVENT_PRIVATE0", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PRIVATE0));
    mrb_define_const(mrb, mod, "EVENT_PRIVATE1", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PRIVATE1));
    mrb_define_const(mrb, mod, "EVENT_PRIVATE2", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PRIVATE2));
    mrb_define_const(mrb, mod, "EVENT_PRIVATE3", mrb_int_value(mrb, (mrb_int)SDL_EVENT_PRIVATE3));
    mrb_define_const(mrb, mod, "EVENT_POLL_SENTINEL", mrb_int_value(mrb, (mrb_int)SDL_EVENT_POLL_SENTINEL));
    mrb_define_const(mrb, mod, "EVENT_USER", mrb_int_value(mrb, (mrb_int)SDL_EVENT_USER));
    mrb_define_const(mrb, mod, "EVENT_LAST", mrb_int_value(mrb, (mrb_int)SDL_EVENT_LAST));
    mrb_define_const(mrb, mod, "EVENT_ENUM_PADDING", mrb_int_value(mrb, (mrb_int)SDL_EVENT_ENUM_PADDING));
    mrb_define_const(mrb, mod, "FILEDIALOG_OPENFILE", mrb_int_value(mrb, (mrb_int)SDL_FILEDIALOG_OPENFILE));
    mrb_define_const(mrb, mod, "FILEDIALOG_SAVEFILE", mrb_int_value(mrb, (mrb_int)SDL_FILEDIALOG_SAVEFILE));
    mrb_define_const(mrb, mod, "FILEDIALOG_OPENFOLDER", mrb_int_value(mrb, (mrb_int)SDL_FILEDIALOG_OPENFOLDER));
    mrb_define_const(mrb, mod, "FLASH_CANCEL", mrb_int_value(mrb, (mrb_int)SDL_FLASH_CANCEL));
    mrb_define_const(mrb, mod, "FLASH_BRIEFLY", mrb_int_value(mrb, (mrb_int)SDL_FLASH_BRIEFLY));
    mrb_define_const(mrb, mod, "FLASH_UNTIL_FOCUSED", mrb_int_value(mrb, (mrb_int)SDL_FLASH_UNTIL_FOCUSED));
    mrb_define_const(mrb, mod, "FLIP_NONE", mrb_int_value(mrb, (mrb_int)SDL_FLIP_NONE));
    mrb_define_const(mrb, mod, "FLIP_HORIZONTAL", mrb_int_value(mrb, (mrb_int)SDL_FLIP_HORIZONTAL));
    mrb_define_const(mrb, mod, "FLIP_VERTICAL", mrb_int_value(mrb, (mrb_int)SDL_FLIP_VERTICAL));
    mrb_define_const(mrb, mod, "FLIP_HORIZONTAL_AND_VERTICAL", mrb_int_value(mrb, (mrb_int)SDL_FLIP_HORIZONTAL_AND_VERTICAL));
    mrb_define_const(mrb, mod, "FOLDER_HOME", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_HOME));
    mrb_define_const(mrb, mod, "FOLDER_DESKTOP", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_DESKTOP));
    mrb_define_const(mrb, mod, "FOLDER_DOCUMENTS", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_DOCUMENTS));
    mrb_define_const(mrb, mod, "FOLDER_DOWNLOADS", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_DOWNLOADS));
    mrb_define_const(mrb, mod, "FOLDER_MUSIC", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_MUSIC));
    mrb_define_const(mrb, mod, "FOLDER_PICTURES", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_PICTURES));
    mrb_define_const(mrb, mod, "FOLDER_PUBLICSHARE", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_PUBLICSHARE));
    mrb_define_const(mrb, mod, "FOLDER_SAVEDGAMES", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_SAVEDGAMES));
    mrb_define_const(mrb, mod, "FOLDER_SCREENSHOTS", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_SCREENSHOTS));
    mrb_define_const(mrb, mod, "FOLDER_TEMPLATES", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_TEMPLATES));
    mrb_define_const(mrb, mod, "FOLDER_VIDEOS", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_VIDEOS));
    mrb_define_const(mrb, mod, "FOLDER_COUNT", mrb_int_value(mrb, (mrb_int)SDL_FOLDER_COUNT));
    mrb_define_const(mrb, mod, "GL_RED_SIZE", mrb_int_value(mrb, (mrb_int)SDL_GL_RED_SIZE));
    mrb_define_const(mrb, mod, "GL_GREEN_SIZE", mrb_int_value(mrb, (mrb_int)SDL_GL_GREEN_SIZE));
    mrb_define_const(mrb, mod, "GL_BLUE_SIZE", mrb_int_value(mrb, (mrb_int)SDL_GL_BLUE_SIZE));
    mrb_define_const(mrb, mod, "GL_ALPHA_SIZE", mrb_int_value(mrb, (mrb_int)SDL_GL_ALPHA_SIZE));
    mrb_define_const(mrb, mod, "GL_BUFFER_SIZE", mrb_int_value(mrb, (mrb_int)SDL_GL_BUFFER_SIZE));
    mrb_define_const(mrb, mod, "GL_DOUBLEBUFFER", mrb_int_value(mrb, (mrb_int)SDL_GL_DOUBLEBUFFER));
    mrb_define_const(mrb, mod, "GL_DEPTH_SIZE", mrb_int_value(mrb, (mrb_int)SDL_GL_DEPTH_SIZE));
    mrb_define_const(mrb, mod, "GL_STENCIL_SIZE", mrb_int_value(mrb, (mrb_int)SDL_GL_STENCIL_SIZE));
    mrb_define_const(mrb, mod, "GL_ACCUM_RED_SIZE", mrb_int_value(mrb, (mrb_int)SDL_GL_ACCUM_RED_SIZE));
    mrb_define_const(mrb, mod, "GL_ACCUM_GREEN_SIZE", mrb_int_value(mrb, (mrb_int)SDL_GL_ACCUM_GREEN_SIZE));
    mrb_define_const(mrb, mod, "GL_ACCUM_BLUE_SIZE", mrb_int_value(mrb, (mrb_int)SDL_GL_ACCUM_BLUE_SIZE));
    mrb_define_const(mrb, mod, "GL_ACCUM_ALPHA_SIZE", mrb_int_value(mrb, (mrb_int)SDL_GL_ACCUM_ALPHA_SIZE));
    mrb_define_const(mrb, mod, "GL_STEREO", mrb_int_value(mrb, (mrb_int)SDL_GL_STEREO));
    mrb_define_const(mrb, mod, "GL_MULTISAMPLEBUFFERS", mrb_int_value(mrb, (mrb_int)SDL_GL_MULTISAMPLEBUFFERS));
    mrb_define_const(mrb, mod, "GL_MULTISAMPLESAMPLES", mrb_int_value(mrb, (mrb_int)SDL_GL_MULTISAMPLESAMPLES));
    mrb_define_const(mrb, mod, "GL_ACCELERATED_VISUAL", mrb_int_value(mrb, (mrb_int)SDL_GL_ACCELERATED_VISUAL));
    mrb_define_const(mrb, mod, "GL_RETAINED_BACKING", mrb_int_value(mrb, (mrb_int)SDL_GL_RETAINED_BACKING));
    mrb_define_const(mrb, mod, "GL_CONTEXT_MAJOR_VERSION", mrb_int_value(mrb, (mrb_int)SDL_GL_CONTEXT_MAJOR_VERSION));
    mrb_define_const(mrb, mod, "GL_CONTEXT_MINOR_VERSION", mrb_int_value(mrb, (mrb_int)SDL_GL_CONTEXT_MINOR_VERSION));
    mrb_define_const(mrb, mod, "GL_CONTEXT_FLAGS", mrb_int_value(mrb, (mrb_int)SDL_GL_CONTEXT_FLAGS));
    mrb_define_const(mrb, mod, "GL_CONTEXT_PROFILE_MASK", mrb_int_value(mrb, (mrb_int)SDL_GL_CONTEXT_PROFILE_MASK));
    mrb_define_const(mrb, mod, "GL_SHARE_WITH_CURRENT_CONTEXT", mrb_int_value(mrb, (mrb_int)SDL_GL_SHARE_WITH_CURRENT_CONTEXT));
    mrb_define_const(mrb, mod, "GL_FRAMEBUFFER_SRGB_CAPABLE", mrb_int_value(mrb, (mrb_int)SDL_GL_FRAMEBUFFER_SRGB_CAPABLE));
    mrb_define_const(mrb, mod, "GL_CONTEXT_RELEASE_BEHAVIOR", mrb_int_value(mrb, (mrb_int)SDL_GL_CONTEXT_RELEASE_BEHAVIOR));
    mrb_define_const(mrb, mod, "GL_CONTEXT_RESET_NOTIFICATION", mrb_int_value(mrb, (mrb_int)SDL_GL_CONTEXT_RESET_NOTIFICATION));
    mrb_define_const(mrb, mod, "GL_CONTEXT_NO_ERROR", mrb_int_value(mrb, (mrb_int)SDL_GL_CONTEXT_NO_ERROR));
    mrb_define_const(mrb, mod, "GL_FLOATBUFFERS", mrb_int_value(mrb, (mrb_int)SDL_GL_FLOATBUFFERS));
    mrb_define_const(mrb, mod, "GL_EGL_PLATFORM", mrb_int_value(mrb, (mrb_int)SDL_GL_EGL_PLATFORM));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_INVALID", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_INVALID));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_ZERO", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_ZERO));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_ONE", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_ONE));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_SRC_COLOR", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_SRC_COLOR));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_ONE_MINUS_SRC_COLOR", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_COLOR));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_DST_COLOR", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_DST_COLOR));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_ONE_MINUS_DST_COLOR", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_ONE_MINUS_DST_COLOR));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_SRC_ALPHA", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_SRC_ALPHA));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_DST_ALPHA", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_DST_ALPHA));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_ONE_MINUS_DST_ALPHA", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_ONE_MINUS_DST_ALPHA));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_CONSTANT_COLOR", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_CONSTANT_COLOR));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_ONE_MINUS_CONSTANT_COLOR", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_ONE_MINUS_CONSTANT_COLOR));
    mrb_define_const(mrb, mod, "GPU_BLENDFACTOR_SRC_ALPHA_SATURATE", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDFACTOR_SRC_ALPHA_SATURATE));
    mrb_define_const(mrb, mod, "GPU_BLENDOP_INVALID", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDOP_INVALID));
    mrb_define_const(mrb, mod, "GPU_BLENDOP_ADD", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDOP_ADD));
    mrb_define_const(mrb, mod, "GPU_BLENDOP_SUBTRACT", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDOP_SUBTRACT));
    mrb_define_const(mrb, mod, "GPU_BLENDOP_REVERSE_SUBTRACT", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDOP_REVERSE_SUBTRACT));
    mrb_define_const(mrb, mod, "GPU_BLENDOP_MIN", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDOP_MIN));
    mrb_define_const(mrb, mod, "GPU_BLENDOP_MAX", mrb_int_value(mrb, (mrb_int)SDL_GPU_BLENDOP_MAX));
    mrb_define_const(mrb, mod, "GPU_COMPAREOP_INVALID", mrb_int_value(mrb, (mrb_int)SDL_GPU_COMPAREOP_INVALID));
    mrb_define_const(mrb, mod, "GPU_COMPAREOP_NEVER", mrb_int_value(mrb, (mrb_int)SDL_GPU_COMPAREOP_NEVER));
    mrb_define_const(mrb, mod, "GPU_COMPAREOP_LESS", mrb_int_value(mrb, (mrb_int)SDL_GPU_COMPAREOP_LESS));
    mrb_define_const(mrb, mod, "GPU_COMPAREOP_EQUAL", mrb_int_value(mrb, (mrb_int)SDL_GPU_COMPAREOP_EQUAL));
    mrb_define_const(mrb, mod, "GPU_COMPAREOP_LESS_OR_EQUAL", mrb_int_value(mrb, (mrb_int)SDL_GPU_COMPAREOP_LESS_OR_EQUAL));
    mrb_define_const(mrb, mod, "GPU_COMPAREOP_GREATER", mrb_int_value(mrb, (mrb_int)SDL_GPU_COMPAREOP_GREATER));
    mrb_define_const(mrb, mod, "GPU_COMPAREOP_NOT_EQUAL", mrb_int_value(mrb, (mrb_int)SDL_GPU_COMPAREOP_NOT_EQUAL));
    mrb_define_const(mrb, mod, "GPU_COMPAREOP_GREATER_OR_EQUAL", mrb_int_value(mrb, (mrb_int)SDL_GPU_COMPAREOP_GREATER_OR_EQUAL));
    mrb_define_const(mrb, mod, "GPU_COMPAREOP_ALWAYS", mrb_int_value(mrb, (mrb_int)SDL_GPU_COMPAREOP_ALWAYS));
    mrb_define_const(mrb, mod, "GPU_CUBEMAPFACE_POSITIVEX", mrb_int_value(mrb, (mrb_int)SDL_GPU_CUBEMAPFACE_POSITIVEX));
    mrb_define_const(mrb, mod, "GPU_CUBEMAPFACE_NEGATIVEX", mrb_int_value(mrb, (mrb_int)SDL_GPU_CUBEMAPFACE_NEGATIVEX));
    mrb_define_const(mrb, mod, "GPU_CUBEMAPFACE_POSITIVEY", mrb_int_value(mrb, (mrb_int)SDL_GPU_CUBEMAPFACE_POSITIVEY));
    mrb_define_const(mrb, mod, "GPU_CUBEMAPFACE_NEGATIVEY", mrb_int_value(mrb, (mrb_int)SDL_GPU_CUBEMAPFACE_NEGATIVEY));
    mrb_define_const(mrb, mod, "GPU_CUBEMAPFACE_POSITIVEZ", mrb_int_value(mrb, (mrb_int)SDL_GPU_CUBEMAPFACE_POSITIVEZ));
    mrb_define_const(mrb, mod, "GPU_CUBEMAPFACE_NEGATIVEZ", mrb_int_value(mrb, (mrb_int)SDL_GPU_CUBEMAPFACE_NEGATIVEZ));
    mrb_define_const(mrb, mod, "GPU_CULLMODE_NONE", mrb_int_value(mrb, (mrb_int)SDL_GPU_CULLMODE_NONE));
    mrb_define_const(mrb, mod, "GPU_CULLMODE_FRONT", mrb_int_value(mrb, (mrb_int)SDL_GPU_CULLMODE_FRONT));
    mrb_define_const(mrb, mod, "GPU_CULLMODE_BACK", mrb_int_value(mrb, (mrb_int)SDL_GPU_CULLMODE_BACK));
    mrb_define_const(mrb, mod, "GPU_FILLMODE_FILL", mrb_int_value(mrb, (mrb_int)SDL_GPU_FILLMODE_FILL));
    mrb_define_const(mrb, mod, "GPU_FILLMODE_LINE", mrb_int_value(mrb, (mrb_int)SDL_GPU_FILLMODE_LINE));
    mrb_define_const(mrb, mod, "GPU_FILTER_NEAREST", mrb_int_value(mrb, (mrb_int)SDL_GPU_FILTER_NEAREST));
    mrb_define_const(mrb, mod, "GPU_FILTER_LINEAR", mrb_int_value(mrb, (mrb_int)SDL_GPU_FILTER_LINEAR));
    mrb_define_const(mrb, mod, "GPU_FRONTFACE_COUNTER_CLOCKWISE", mrb_int_value(mrb, (mrb_int)SDL_GPU_FRONTFACE_COUNTER_CLOCKWISE));
    mrb_define_const(mrb, mod, "GPU_FRONTFACE_CLOCKWISE", mrb_int_value(mrb, (mrb_int)SDL_GPU_FRONTFACE_CLOCKWISE));
    mrb_define_const(mrb, mod, "GPU_INDEXELEMENTSIZE_16BIT", mrb_int_value(mrb, (mrb_int)SDL_GPU_INDEXELEMENTSIZE_16BIT));
    mrb_define_const(mrb, mod, "GPU_INDEXELEMENTSIZE_32BIT", mrb_int_value(mrb, (mrb_int)SDL_GPU_INDEXELEMENTSIZE_32BIT));
    mrb_define_const(mrb, mod, "GPU_LOADOP_LOAD", mrb_int_value(mrb, (mrb_int)SDL_GPU_LOADOP_LOAD));
    mrb_define_const(mrb, mod, "GPU_LOADOP_CLEAR", mrb_int_value(mrb, (mrb_int)SDL_GPU_LOADOP_CLEAR));
    mrb_define_const(mrb, mod, "GPU_LOADOP_DONT_CARE", mrb_int_value(mrb, (mrb_int)SDL_GPU_LOADOP_DONT_CARE));
    mrb_define_const(mrb, mod, "GPU_PRESENTMODE_VSYNC", mrb_int_value(mrb, (mrb_int)SDL_GPU_PRESENTMODE_VSYNC));
    mrb_define_const(mrb, mod, "GPU_PRESENTMODE_IMMEDIATE", mrb_int_value(mrb, (mrb_int)SDL_GPU_PRESENTMODE_IMMEDIATE));
    mrb_define_const(mrb, mod, "GPU_PRESENTMODE_MAILBOX", mrb_int_value(mrb, (mrb_int)SDL_GPU_PRESENTMODE_MAILBOX));
    mrb_define_const(mrb, mod, "GPU_PRIMITIVETYPE_TRIANGLELIST", mrb_int_value(mrb, (mrb_int)SDL_GPU_PRIMITIVETYPE_TRIANGLELIST));
    mrb_define_const(mrb, mod, "GPU_PRIMITIVETYPE_TRIANGLESTRIP", mrb_int_value(mrb, (mrb_int)SDL_GPU_PRIMITIVETYPE_TRIANGLESTRIP));
    mrb_define_const(mrb, mod, "GPU_PRIMITIVETYPE_LINELIST", mrb_int_value(mrb, (mrb_int)SDL_GPU_PRIMITIVETYPE_LINELIST));
    mrb_define_const(mrb, mod, "GPU_PRIMITIVETYPE_LINESTRIP", mrb_int_value(mrb, (mrb_int)SDL_GPU_PRIMITIVETYPE_LINESTRIP));
    mrb_define_const(mrb, mod, "GPU_PRIMITIVETYPE_POINTLIST", mrb_int_value(mrb, (mrb_int)SDL_GPU_PRIMITIVETYPE_POINTLIST));
    mrb_define_const(mrb, mod, "GPU_SAMPLECOUNT_1", mrb_int_value(mrb, (mrb_int)SDL_GPU_SAMPLECOUNT_1));
    mrb_define_const(mrb, mod, "GPU_SAMPLECOUNT_2", mrb_int_value(mrb, (mrb_int)SDL_GPU_SAMPLECOUNT_2));
    mrb_define_const(mrb, mod, "GPU_SAMPLECOUNT_4", mrb_int_value(mrb, (mrb_int)SDL_GPU_SAMPLECOUNT_4));
    mrb_define_const(mrb, mod, "GPU_SAMPLECOUNT_8", mrb_int_value(mrb, (mrb_int)SDL_GPU_SAMPLECOUNT_8));
    mrb_define_const(mrb, mod, "GPU_SAMPLERADDRESSMODE_REPEAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_SAMPLERADDRESSMODE_REPEAT));
    mrb_define_const(mrb, mod, "GPU_SAMPLERADDRESSMODE_MIRRORED_REPEAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_SAMPLERADDRESSMODE_MIRRORED_REPEAT));
    mrb_define_const(mrb, mod, "GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE", mrb_int_value(mrb, (mrb_int)SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE));
    mrb_define_const(mrb, mod, "GPU_SAMPLERMIPMAPMODE_NEAREST", mrb_int_value(mrb, (mrb_int)SDL_GPU_SAMPLERMIPMAPMODE_NEAREST));
    mrb_define_const(mrb, mod, "GPU_SAMPLERMIPMAPMODE_LINEAR", mrb_int_value(mrb, (mrb_int)SDL_GPU_SAMPLERMIPMAPMODE_LINEAR));
    mrb_define_const(mrb, mod, "GPU_SHADERSTAGE_VERTEX", mrb_int_value(mrb, (mrb_int)SDL_GPU_SHADERSTAGE_VERTEX));
    mrb_define_const(mrb, mod, "GPU_SHADERSTAGE_FRAGMENT", mrb_int_value(mrb, (mrb_int)SDL_GPU_SHADERSTAGE_FRAGMENT));
    mrb_define_const(mrb, mod, "GPU_STENCILOP_INVALID", mrb_int_value(mrb, (mrb_int)SDL_GPU_STENCILOP_INVALID));
    mrb_define_const(mrb, mod, "GPU_STENCILOP_KEEP", mrb_int_value(mrb, (mrb_int)SDL_GPU_STENCILOP_KEEP));
    mrb_define_const(mrb, mod, "GPU_STENCILOP_ZERO", mrb_int_value(mrb, (mrb_int)SDL_GPU_STENCILOP_ZERO));
    mrb_define_const(mrb, mod, "GPU_STENCILOP_REPLACE", mrb_int_value(mrb, (mrb_int)SDL_GPU_STENCILOP_REPLACE));
    mrb_define_const(mrb, mod, "GPU_STENCILOP_INCREMENT_AND_CLAMP", mrb_int_value(mrb, (mrb_int)SDL_GPU_STENCILOP_INCREMENT_AND_CLAMP));
    mrb_define_const(mrb, mod, "GPU_STENCILOP_DECREMENT_AND_CLAMP", mrb_int_value(mrb, (mrb_int)SDL_GPU_STENCILOP_DECREMENT_AND_CLAMP));
    mrb_define_const(mrb, mod, "GPU_STENCILOP_INVERT", mrb_int_value(mrb, (mrb_int)SDL_GPU_STENCILOP_INVERT));
    mrb_define_const(mrb, mod, "GPU_STENCILOP_INCREMENT_AND_WRAP", mrb_int_value(mrb, (mrb_int)SDL_GPU_STENCILOP_INCREMENT_AND_WRAP));
    mrb_define_const(mrb, mod, "GPU_STENCILOP_DECREMENT_AND_WRAP", mrb_int_value(mrb, (mrb_int)SDL_GPU_STENCILOP_DECREMENT_AND_WRAP));
    mrb_define_const(mrb, mod, "GPU_STOREOP_STORE", mrb_int_value(mrb, (mrb_int)SDL_GPU_STOREOP_STORE));
    mrb_define_const(mrb, mod, "GPU_STOREOP_DONT_CARE", mrb_int_value(mrb, (mrb_int)SDL_GPU_STOREOP_DONT_CARE));
    mrb_define_const(mrb, mod, "GPU_STOREOP_RESOLVE", mrb_int_value(mrb, (mrb_int)SDL_GPU_STOREOP_RESOLVE));
    mrb_define_const(mrb, mod, "GPU_STOREOP_RESOLVE_AND_STORE", mrb_int_value(mrb, (mrb_int)SDL_GPU_STOREOP_RESOLVE_AND_STORE));
    mrb_define_const(mrb, mod, "GPU_SWAPCHAINCOMPOSITION_SDR", mrb_int_value(mrb, (mrb_int)SDL_GPU_SWAPCHAINCOMPOSITION_SDR));
    mrb_define_const(mrb, mod, "GPU_SWAPCHAINCOMPOSITION_SDR_LINEAR", mrb_int_value(mrb, (mrb_int)SDL_GPU_SWAPCHAINCOMPOSITION_SDR_LINEAR));
    mrb_define_const(mrb, mod, "GPU_SWAPCHAINCOMPOSITION_HDR_EXTENDED_LINEAR", mrb_int_value(mrb, (mrb_int)SDL_GPU_SWAPCHAINCOMPOSITION_HDR_EXTENDED_LINEAR));
    mrb_define_const(mrb, mod, "GPU_SWAPCHAINCOMPOSITION_HDR10_ST2084", mrb_int_value(mrb, (mrb_int)SDL_GPU_SWAPCHAINCOMPOSITION_HDR10_ST2084));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_INVALID", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_INVALID));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_A8_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_A8_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8G8_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8G8_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8G8B8A8_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16G16_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16G16_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16G16B16A16_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16G16B16A16_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R10G10B10A2_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R10G10B10A2_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_B5G6R5_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_B5G6R5_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_B5G5R5A1_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_B5G5R5A1_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_B4G4R4A4_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_B4G4R4A4_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_B8G8R8A8_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_B8G8R8A8_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC1_RGBA_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC1_RGBA_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC2_RGBA_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC2_RGBA_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC3_RGBA_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC3_RGBA_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC4_R_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC4_R_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC5_RG_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC5_RG_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC7_RGBA_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC7_RGBA_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC6H_RGB_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC6H_RGB_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC6H_RGB_UFLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC6H_RGB_UFLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8_SNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8_SNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8G8_SNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8G8_SNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8G8B8A8_SNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8G8B8A8_SNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16_SNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16_SNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16G16_SNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16G16_SNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16G16B16A16_SNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16G16B16A16_SNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16G16_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16G16_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16G16B16A16_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16G16B16A16_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R32_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R32_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R32G32_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R32G32_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R32G32B32A32_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R32G32B32A32_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R11G11B10_UFLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R11G11B10_UFLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8_UINT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8G8_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8G8_UINT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8G8B8A8_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UINT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16_UINT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16G16_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16G16_UINT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16G16B16A16_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16G16B16A16_UINT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R32_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R32_UINT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R32G32_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R32G32_UINT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R32G32B32A32_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R32G32B32A32_UINT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8_INT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8_INT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8G8_INT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8G8_INT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8G8B8A8_INT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8G8B8A8_INT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16_INT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16_INT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16G16_INT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16G16_INT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R16G16B16A16_INT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R16G16B16A16_INT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R32_INT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R32_INT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R32G32_INT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R32G32_INT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R32G32B32A32_INT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R32G32B32A32_INT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_R8G8B8A8_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_B8G8R8A8_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_B8G8R8A8_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC1_RGBA_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC1_RGBA_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC2_RGBA_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC2_RGBA_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC3_RGBA_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC3_RGBA_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_BC7_RGBA_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_BC7_RGBA_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_D16_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_D16_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_D24_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_D24_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_D32_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_D32_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_D24_UNORM_S8_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_D24_UNORM_S8_UINT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_D32_FLOAT_S8_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_D32_FLOAT_S8_UINT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_4x4_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_4x4_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_5x4_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_5x4_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_5x5_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_5x5_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_6x5_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_6x5_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_6x6_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_6x6_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_8x5_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_8x5_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_8x6_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_8x6_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_8x8_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_8x8_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x5_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x5_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x6_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x6_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x8_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x8_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x10_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x10_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_12x10_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_12x10_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_12x12_UNORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_12x12_UNORM));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_4x4_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_4x4_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_5x4_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_5x4_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_5x5_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_5x5_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_6x5_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_6x5_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_6x6_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_6x6_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_8x5_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_8x5_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_8x6_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_8x6_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_8x8_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_8x8_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x5_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x5_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x6_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x6_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x8_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x8_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x10_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x10_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_12x10_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_12x10_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_12x12_UNORM_SRGB", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_12x12_UNORM_SRGB));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_4x4_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_4x4_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_5x4_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_5x4_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_5x5_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_5x5_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_6x5_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_6x5_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_6x6_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_6x6_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_8x5_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_8x5_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_8x6_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_8x6_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_8x8_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_8x8_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x5_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x5_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x6_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x6_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x8_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x8_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_10x10_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_10x10_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_12x10_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_12x10_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTUREFORMAT_ASTC_12x12_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTUREFORMAT_ASTC_12x12_FLOAT));
    mrb_define_const(mrb, mod, "GPU_TEXTURETYPE_2D", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTURETYPE_2D));
    mrb_define_const(mrb, mod, "GPU_TEXTURETYPE_2D_ARRAY", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTURETYPE_2D_ARRAY));
    mrb_define_const(mrb, mod, "GPU_TEXTURETYPE_3D", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTURETYPE_3D));
    mrb_define_const(mrb, mod, "GPU_TEXTURETYPE_CUBE", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTURETYPE_CUBE));
    mrb_define_const(mrb, mod, "GPU_TEXTURETYPE_CUBE_ARRAY", mrb_int_value(mrb, (mrb_int)SDL_GPU_TEXTURETYPE_CUBE_ARRAY));
    mrb_define_const(mrb, mod, "GPU_TRANSFERBUFFERUSAGE_UPLOAD", mrb_int_value(mrb, (mrb_int)SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD));
    mrb_define_const(mrb, mod, "GPU_TRANSFERBUFFERUSAGE_DOWNLOAD", mrb_int_value(mrb, (mrb_int)SDL_GPU_TRANSFERBUFFERUSAGE_DOWNLOAD));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_INVALID", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_INVALID));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_INT", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_INT));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_INT2", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_INT2));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_INT3", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_INT3));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_INT4", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_INT4));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_UINT", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_UINT));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_UINT2", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_UINT2));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_UINT3", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_UINT3));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_UINT4", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_UINT4));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_FLOAT));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_FLOAT2", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_FLOAT2));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_FLOAT3", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_FLOAT3));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_FLOAT4", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_FLOAT4));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_BYTE2", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_BYTE2));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_BYTE4", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_BYTE4));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_UBYTE2", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_UBYTE2));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_UBYTE4", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_UBYTE4));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_BYTE2_NORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_BYTE2_NORM));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_BYTE4_NORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_BYTE4_NORM));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_UBYTE2_NORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_UBYTE2_NORM));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_UBYTE4_NORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_UBYTE4_NORM));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_SHORT2", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_SHORT2));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_SHORT4", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_SHORT4));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_USHORT2", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_USHORT2));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_USHORT4", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_USHORT4));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_SHORT2_NORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_SHORT2_NORM));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_SHORT4_NORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_SHORT4_NORM));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_USHORT2_NORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_USHORT2_NORM));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_USHORT4_NORM", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_USHORT4_NORM));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_HALF2", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_HALF2));
    mrb_define_const(mrb, mod, "GPU_VERTEXELEMENTFORMAT_HALF4", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXELEMENTFORMAT_HALF4));
    mrb_define_const(mrb, mod, "GPU_VERTEXINPUTRATE_VERTEX", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXINPUTRATE_VERTEX));
    mrb_define_const(mrb, mod, "GPU_VERTEXINPUTRATE_INSTANCE", mrb_int_value(mrb, (mrb_int)SDL_GPU_VERTEXINPUTRATE_INSTANCE));
    mrb_define_const(mrb, mod, "GAMEPAD_AXIS_INVALID", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_AXIS_INVALID));
    mrb_define_const(mrb, mod, "GAMEPAD_AXIS_LEFTX", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_AXIS_LEFTX));
    mrb_define_const(mrb, mod, "GAMEPAD_AXIS_LEFTY", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_AXIS_LEFTY));
    mrb_define_const(mrb, mod, "GAMEPAD_AXIS_RIGHTX", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_AXIS_RIGHTX));
    mrb_define_const(mrb, mod, "GAMEPAD_AXIS_RIGHTY", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_AXIS_RIGHTY));
    mrb_define_const(mrb, mod, "GAMEPAD_AXIS_LEFT_TRIGGER", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_AXIS_LEFT_TRIGGER));
    mrb_define_const(mrb, mod, "GAMEPAD_AXIS_RIGHT_TRIGGER", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_AXIS_RIGHT_TRIGGER));
    mrb_define_const(mrb, mod, "GAMEPAD_AXIS_COUNT", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_AXIS_COUNT));
    mrb_define_const(mrb, mod, "GAMEPAD_BINDTYPE_NONE", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BINDTYPE_NONE));
    mrb_define_const(mrb, mod, "GAMEPAD_BINDTYPE_BUTTON", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BINDTYPE_BUTTON));
    mrb_define_const(mrb, mod, "GAMEPAD_BINDTYPE_AXIS", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BINDTYPE_AXIS));
    mrb_define_const(mrb, mod, "GAMEPAD_BINDTYPE_HAT", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BINDTYPE_HAT));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_INVALID", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_INVALID));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_SOUTH", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_SOUTH));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_EAST", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_EAST));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_WEST", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_WEST));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_NORTH", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_NORTH));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_BACK", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_BACK));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_GUIDE", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_GUIDE));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_START", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_START));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LEFT_STICK", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LEFT_STICK));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_RIGHT_STICK", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_RIGHT_STICK));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LEFT_SHOULDER", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LEFT_SHOULDER));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_RIGHT_SHOULDER", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_DPAD_UP", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_DPAD_UP));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_DPAD_DOWN", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_DPAD_DOWN));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_DPAD_LEFT", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_DPAD_LEFT));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_DPAD_RIGHT", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_DPAD_RIGHT));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_MISC1", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_MISC1));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_RIGHT_PADDLE1", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_RIGHT_PADDLE1));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LEFT_PADDLE1", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LEFT_PADDLE1));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_RIGHT_PADDLE2", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_RIGHT_PADDLE2));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LEFT_PADDLE2", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LEFT_PADDLE2));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_TOUCHPAD", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_TOUCHPAD));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_MISC2", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_MISC2));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_MISC3", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_MISC3));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_MISC4", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_MISC4));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_MISC5", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_MISC5));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_MISC6", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_MISC6));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_COUNT", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_COUNT));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LABEL_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LABEL_UNKNOWN));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LABEL_A", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LABEL_A));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LABEL_B", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LABEL_B));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LABEL_X", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LABEL_X));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LABEL_Y", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LABEL_Y));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LABEL_CROSS", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LABEL_CROSS));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LABEL_CIRCLE", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LABEL_CIRCLE));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LABEL_SQUARE", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LABEL_SQUARE));
    mrb_define_const(mrb, mod, "GAMEPAD_BUTTON_LABEL_TRIANGLE", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_BUTTON_LABEL_TRIANGLE));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_UNKNOWN));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_STANDARD", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_STANDARD));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_XBOX360", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_XBOX360));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_XBOXONE", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_XBOXONE));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_PS3", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_PS3));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_PS4", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_PS4));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_PS5", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_PS5));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_NINTENDO_SWITCH_PRO", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_PRO));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_LEFT", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_LEFT));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_RIGHT", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_RIGHT));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_PAIR", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_NINTENDO_SWITCH_JOYCON_PAIR));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_GAMECUBE", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_GAMECUBE));
    mrb_define_const(mrb, mod, "GAMEPAD_TYPE_COUNT", mrb_int_value(mrb, (mrb_int)SDL_GAMEPAD_TYPE_COUNT));
    mrb_define_const(mrb, mod, "HINT_DEFAULT", mrb_int_value(mrb, (mrb_int)SDL_HINT_DEFAULT));
    mrb_define_const(mrb, mod, "HINT_NORMAL", mrb_int_value(mrb, (mrb_int)SDL_HINT_NORMAL));
    mrb_define_const(mrb, mod, "HINT_OVERRIDE", mrb_int_value(mrb, (mrb_int)SDL_HINT_OVERRIDE));
    mrb_define_const(mrb, mod, "HITTEST_NORMAL", mrb_int_value(mrb, (mrb_int)SDL_HITTEST_NORMAL));
    mrb_define_const(mrb, mod, "HITTEST_DRAGGABLE", mrb_int_value(mrb, (mrb_int)SDL_HITTEST_DRAGGABLE));
    mrb_define_const(mrb, mod, "HITTEST_RESIZE_TOPLEFT", mrb_int_value(mrb, (mrb_int)SDL_HITTEST_RESIZE_TOPLEFT));
    mrb_define_const(mrb, mod, "HITTEST_RESIZE_TOP", mrb_int_value(mrb, (mrb_int)SDL_HITTEST_RESIZE_TOP));
    mrb_define_const(mrb, mod, "HITTEST_RESIZE_TOPRIGHT", mrb_int_value(mrb, (mrb_int)SDL_HITTEST_RESIZE_TOPRIGHT));
    mrb_define_const(mrb, mod, "HITTEST_RESIZE_RIGHT", mrb_int_value(mrb, (mrb_int)SDL_HITTEST_RESIZE_RIGHT));
    mrb_define_const(mrb, mod, "HITTEST_RESIZE_BOTTOMRIGHT", mrb_int_value(mrb, (mrb_int)SDL_HITTEST_RESIZE_BOTTOMRIGHT));
    mrb_define_const(mrb, mod, "HITTEST_RESIZE_BOTTOM", mrb_int_value(mrb, (mrb_int)SDL_HITTEST_RESIZE_BOTTOM));
    mrb_define_const(mrb, mod, "HITTEST_RESIZE_BOTTOMLEFT", mrb_int_value(mrb, (mrb_int)SDL_HITTEST_RESIZE_BOTTOMLEFT));
    mrb_define_const(mrb, mod, "HITTEST_RESIZE_LEFT", mrb_int_value(mrb, (mrb_int)SDL_HITTEST_RESIZE_LEFT));
    mrb_define_const(mrb, mod, "IO_STATUS_READY", mrb_int_value(mrb, (mrb_int)SDL_IO_STATUS_READY));
    mrb_define_const(mrb, mod, "IO_STATUS_ERROR", mrb_int_value(mrb, (mrb_int)SDL_IO_STATUS_ERROR));
    mrb_define_const(mrb, mod, "IO_STATUS_EOF", mrb_int_value(mrb, (mrb_int)SDL_IO_STATUS_EOF));
    mrb_define_const(mrb, mod, "IO_STATUS_NOT_READY", mrb_int_value(mrb, (mrb_int)SDL_IO_STATUS_NOT_READY));
    mrb_define_const(mrb, mod, "IO_STATUS_READONLY", mrb_int_value(mrb, (mrb_int)SDL_IO_STATUS_READONLY));
    mrb_define_const(mrb, mod, "IO_STATUS_WRITEONLY", mrb_int_value(mrb, (mrb_int)SDL_IO_STATUS_WRITEONLY));
    mrb_define_const(mrb, mod, "IO_SEEK_SET", mrb_int_value(mrb, (mrb_int)SDL_IO_SEEK_SET));
    mrb_define_const(mrb, mod, "IO_SEEK_CUR", mrb_int_value(mrb, (mrb_int)SDL_IO_SEEK_CUR));
    mrb_define_const(mrb, mod, "IO_SEEK_END", mrb_int_value(mrb, (mrb_int)SDL_IO_SEEK_END));
    mrb_define_const(mrb, mod, "INIT_STATUS_UNINITIALIZED", mrb_int_value(mrb, (mrb_int)SDL_INIT_STATUS_UNINITIALIZED));
    mrb_define_const(mrb, mod, "INIT_STATUS_INITIALIZING", mrb_int_value(mrb, (mrb_int)SDL_INIT_STATUS_INITIALIZING));
    mrb_define_const(mrb, mod, "INIT_STATUS_INITIALIZED", mrb_int_value(mrb, (mrb_int)SDL_INIT_STATUS_INITIALIZED));
    mrb_define_const(mrb, mod, "INIT_STATUS_UNINITIALIZING", mrb_int_value(mrb, (mrb_int)SDL_INIT_STATUS_UNINITIALIZING));
    mrb_define_const(mrb, mod, "JOYSTICK_CONNECTION_INVALID", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_CONNECTION_INVALID));
    mrb_define_const(mrb, mod, "JOYSTICK_CONNECTION_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_CONNECTION_UNKNOWN));
    mrb_define_const(mrb, mod, "JOYSTICK_CONNECTION_WIRED", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_CONNECTION_WIRED));
    mrb_define_const(mrb, mod, "JOYSTICK_CONNECTION_WIRELESS", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_CONNECTION_WIRELESS));
    mrb_define_const(mrb, mod, "JOYSTICK_TYPE_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_TYPE_UNKNOWN));
    mrb_define_const(mrb, mod, "JOYSTICK_TYPE_GAMEPAD", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_TYPE_GAMEPAD));
    mrb_define_const(mrb, mod, "JOYSTICK_TYPE_WHEEL", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_TYPE_WHEEL));
    mrb_define_const(mrb, mod, "JOYSTICK_TYPE_ARCADE_STICK", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_TYPE_ARCADE_STICK));
    mrb_define_const(mrb, mod, "JOYSTICK_TYPE_FLIGHT_STICK", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_TYPE_FLIGHT_STICK));
    mrb_define_const(mrb, mod, "JOYSTICK_TYPE_DANCE_PAD", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_TYPE_DANCE_PAD));
    mrb_define_const(mrb, mod, "JOYSTICK_TYPE_GUITAR", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_TYPE_GUITAR));
    mrb_define_const(mrb, mod, "JOYSTICK_TYPE_DRUM_KIT", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_TYPE_DRUM_KIT));
    mrb_define_const(mrb, mod, "JOYSTICK_TYPE_ARCADE_PAD", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_TYPE_ARCADE_PAD));
    mrb_define_const(mrb, mod, "JOYSTICK_TYPE_THROTTLE", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_TYPE_THROTTLE));
    mrb_define_const(mrb, mod, "JOYSTICK_TYPE_COUNT", mrb_int_value(mrb, (mrb_int)SDL_JOYSTICK_TYPE_COUNT));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_APPLICATION", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_APPLICATION));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_ERROR", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_ERROR));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_ASSERT", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_ASSERT));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_SYSTEM", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_SYSTEM));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_AUDIO", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_AUDIO));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_VIDEO", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_VIDEO));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_RENDER", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_RENDER));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_INPUT", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_INPUT));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_TEST", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_TEST));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_GPU", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_GPU));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_RESERVED2", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_RESERVED2));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_RESERVED3", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_RESERVED3));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_RESERVED4", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_RESERVED4));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_RESERVED5", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_RESERVED5));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_RESERVED6", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_RESERVED6));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_RESERVED7", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_RESERVED7));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_RESERVED8", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_RESERVED8));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_RESERVED9", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_RESERVED9));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_RESERVED10", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_RESERVED10));
    mrb_define_const(mrb, mod, "LOG_CATEGORY_CUSTOM", mrb_int_value(mrb, (mrb_int)SDL_LOG_CATEGORY_CUSTOM));
    mrb_define_const(mrb, mod, "LOG_PRIORITY_INVALID", mrb_int_value(mrb, (mrb_int)SDL_LOG_PRIORITY_INVALID));
    mrb_define_const(mrb, mod, "LOG_PRIORITY_TRACE", mrb_int_value(mrb, (mrb_int)SDL_LOG_PRIORITY_TRACE));
    mrb_define_const(mrb, mod, "LOG_PRIORITY_VERBOSE", mrb_int_value(mrb, (mrb_int)SDL_LOG_PRIORITY_VERBOSE));
    mrb_define_const(mrb, mod, "LOG_PRIORITY_DEBUG", mrb_int_value(mrb, (mrb_int)SDL_LOG_PRIORITY_DEBUG));
    mrb_define_const(mrb, mod, "LOG_PRIORITY_INFO", mrb_int_value(mrb, (mrb_int)SDL_LOG_PRIORITY_INFO));
    mrb_define_const(mrb, mod, "LOG_PRIORITY_WARN", mrb_int_value(mrb, (mrb_int)SDL_LOG_PRIORITY_WARN));
    mrb_define_const(mrb, mod, "LOG_PRIORITY_ERROR", mrb_int_value(mrb, (mrb_int)SDL_LOG_PRIORITY_ERROR));
    mrb_define_const(mrb, mod, "LOG_PRIORITY_CRITICAL", mrb_int_value(mrb, (mrb_int)SDL_LOG_PRIORITY_CRITICAL));
    mrb_define_const(mrb, mod, "LOG_PRIORITY_COUNT", mrb_int_value(mrb, (mrb_int)SDL_LOG_PRIORITY_COUNT));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_IDENTITY", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_IDENTITY));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_BT709", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_BT709));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_UNSPECIFIED", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_UNSPECIFIED));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_FCC", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_FCC));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_BT470BG", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_BT470BG));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_BT601", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_BT601));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_SMPTE240", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_SMPTE240));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_YCGCO", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_YCGCO));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_BT2020_NCL", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_BT2020_NCL));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_BT2020_CL", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_BT2020_CL));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_SMPTE2085", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_SMPTE2085));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_CHROMA_DERIVED_NCL", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_CHROMA_DERIVED_NCL));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_CHROMA_DERIVED_CL", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_CHROMA_DERIVED_CL));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_ICTCP", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_ICTCP));
    mrb_define_const(mrb, mod, "MATRIX_COEFFICIENTS_CUSTOM", mrb_int_value(mrb, (mrb_int)SDL_MATRIX_COEFFICIENTS_CUSTOM));
    mrb_define_const(mrb, mod, "MESSAGEBOX_COLOR_BACKGROUND", mrb_int_value(mrb, (mrb_int)SDL_MESSAGEBOX_COLOR_BACKGROUND));
    mrb_define_const(mrb, mod, "MESSAGEBOX_COLOR_TEXT", mrb_int_value(mrb, (mrb_int)SDL_MESSAGEBOX_COLOR_TEXT));
    mrb_define_const(mrb, mod, "MESSAGEBOX_COLOR_BUTTON_BORDER", mrb_int_value(mrb, (mrb_int)SDL_MESSAGEBOX_COLOR_BUTTON_BORDER));
    mrb_define_const(mrb, mod, "MESSAGEBOX_COLOR_BUTTON_BACKGROUND", mrb_int_value(mrb, (mrb_int)SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND));
    mrb_define_const(mrb, mod, "MESSAGEBOX_COLOR_BUTTON_SELECTED", mrb_int_value(mrb, (mrb_int)SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED));
    mrb_define_const(mrb, mod, "MESSAGEBOX_COLOR_COUNT", mrb_int_value(mrb, (mrb_int)SDL_MESSAGEBOX_COLOR_COUNT));
    mrb_define_const(mrb, mod, "MOUSEWHEEL_NORMAL", mrb_int_value(mrb, (mrb_int)SDL_MOUSEWHEEL_NORMAL));
    mrb_define_const(mrb, mod, "MOUSEWHEEL_FLIPPED", mrb_int_value(mrb, (mrb_int)SDL_MOUSEWHEEL_FLIPPED));
    mrb_define_const(mrb, mod, "PACKEDLAYOUT_NONE", mrb_int_value(mrb, (mrb_int)SDL_PACKEDLAYOUT_NONE));
    mrb_define_const(mrb, mod, "PACKEDLAYOUT_332", mrb_int_value(mrb, (mrb_int)SDL_PACKEDLAYOUT_332));
    mrb_define_const(mrb, mod, "PACKEDLAYOUT_4444", mrb_int_value(mrb, (mrb_int)SDL_PACKEDLAYOUT_4444));
    mrb_define_const(mrb, mod, "PACKEDLAYOUT_1555", mrb_int_value(mrb, (mrb_int)SDL_PACKEDLAYOUT_1555));
    mrb_define_const(mrb, mod, "PACKEDLAYOUT_5551", mrb_int_value(mrb, (mrb_int)SDL_PACKEDLAYOUT_5551));
    mrb_define_const(mrb, mod, "PACKEDLAYOUT_565", mrb_int_value(mrb, (mrb_int)SDL_PACKEDLAYOUT_565));
    mrb_define_const(mrb, mod, "PACKEDLAYOUT_8888", mrb_int_value(mrb, (mrb_int)SDL_PACKEDLAYOUT_8888));
    mrb_define_const(mrb, mod, "PACKEDLAYOUT_2101010", mrb_int_value(mrb, (mrb_int)SDL_PACKEDLAYOUT_2101010));
    mrb_define_const(mrb, mod, "PACKEDLAYOUT_1010102", mrb_int_value(mrb, (mrb_int)SDL_PACKEDLAYOUT_1010102));
    mrb_define_const(mrb, mod, "PACKEDORDER_NONE", mrb_int_value(mrb, (mrb_int)SDL_PACKEDORDER_NONE));
    mrb_define_const(mrb, mod, "PACKEDORDER_XRGB", mrb_int_value(mrb, (mrb_int)SDL_PACKEDORDER_XRGB));
    mrb_define_const(mrb, mod, "PACKEDORDER_RGBX", mrb_int_value(mrb, (mrb_int)SDL_PACKEDORDER_RGBX));
    mrb_define_const(mrb, mod, "PACKEDORDER_ARGB", mrb_int_value(mrb, (mrb_int)SDL_PACKEDORDER_ARGB));
    mrb_define_const(mrb, mod, "PACKEDORDER_RGBA", mrb_int_value(mrb, (mrb_int)SDL_PACKEDORDER_RGBA));
    mrb_define_const(mrb, mod, "PACKEDORDER_XBGR", mrb_int_value(mrb, (mrb_int)SDL_PACKEDORDER_XBGR));
    mrb_define_const(mrb, mod, "PACKEDORDER_BGRX", mrb_int_value(mrb, (mrb_int)SDL_PACKEDORDER_BGRX));
    mrb_define_const(mrb, mod, "PACKEDORDER_ABGR", mrb_int_value(mrb, (mrb_int)SDL_PACKEDORDER_ABGR));
    mrb_define_const(mrb, mod, "PACKEDORDER_BGRA", mrb_int_value(mrb, (mrb_int)SDL_PACKEDORDER_BGRA));
    mrb_define_const(mrb, mod, "PATHTYPE_NONE", mrb_int_value(mrb, (mrb_int)SDL_PATHTYPE_NONE));
    mrb_define_const(mrb, mod, "PATHTYPE_FILE", mrb_int_value(mrb, (mrb_int)SDL_PATHTYPE_FILE));
    mrb_define_const(mrb, mod, "PATHTYPE_DIRECTORY", mrb_int_value(mrb, (mrb_int)SDL_PATHTYPE_DIRECTORY));
    mrb_define_const(mrb, mod, "PATHTYPE_OTHER", mrb_int_value(mrb, (mrb_int)SDL_PATHTYPE_OTHER));
    mrb_define_const(mrb, mod, "PEN_AXIS_PRESSURE", mrb_int_value(mrb, (mrb_int)SDL_PEN_AXIS_PRESSURE));
    mrb_define_const(mrb, mod, "PEN_AXIS_XTILT", mrb_int_value(mrb, (mrb_int)SDL_PEN_AXIS_XTILT));
    mrb_define_const(mrb, mod, "PEN_AXIS_YTILT", mrb_int_value(mrb, (mrb_int)SDL_PEN_AXIS_YTILT));
    mrb_define_const(mrb, mod, "PEN_AXIS_DISTANCE", mrb_int_value(mrb, (mrb_int)SDL_PEN_AXIS_DISTANCE));
    mrb_define_const(mrb, mod, "PEN_AXIS_ROTATION", mrb_int_value(mrb, (mrb_int)SDL_PEN_AXIS_ROTATION));
    mrb_define_const(mrb, mod, "PEN_AXIS_SLIDER", mrb_int_value(mrb, (mrb_int)SDL_PEN_AXIS_SLIDER));
    mrb_define_const(mrb, mod, "PEN_AXIS_TANGENTIAL_PRESSURE", mrb_int_value(mrb, (mrb_int)SDL_PEN_AXIS_TANGENTIAL_PRESSURE));
    mrb_define_const(mrb, mod, "PEN_AXIS_COUNT", mrb_int_value(mrb, (mrb_int)SDL_PEN_AXIS_COUNT));
    mrb_define_const(mrb, mod, "PEN_DEVICE_TYPE_INVALID", mrb_int_value(mrb, (mrb_int)SDL_PEN_DEVICE_TYPE_INVALID));
    mrb_define_const(mrb, mod, "PEN_DEVICE_TYPE_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_PEN_DEVICE_TYPE_UNKNOWN));
    mrb_define_const(mrb, mod, "PEN_DEVICE_TYPE_DIRECT", mrb_int_value(mrb, (mrb_int)SDL_PEN_DEVICE_TYPE_DIRECT));
    mrb_define_const(mrb, mod, "PEN_DEVICE_TYPE_INDIRECT", mrb_int_value(mrb, (mrb_int)SDL_PEN_DEVICE_TYPE_INDIRECT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_UNKNOWN));
    mrb_define_const(mrb, mod, "PIXELFORMAT_INDEX1LSB", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_INDEX1LSB));
    mrb_define_const(mrb, mod, "PIXELFORMAT_INDEX1MSB", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_INDEX1MSB));
    mrb_define_const(mrb, mod, "PIXELFORMAT_INDEX2LSB", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_INDEX2LSB));
    mrb_define_const(mrb, mod, "PIXELFORMAT_INDEX2MSB", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_INDEX2MSB));
    mrb_define_const(mrb, mod, "PIXELFORMAT_INDEX4LSB", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_INDEX4LSB));
    mrb_define_const(mrb, mod, "PIXELFORMAT_INDEX4MSB", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_INDEX4MSB));
    mrb_define_const(mrb, mod, "PIXELFORMAT_INDEX8", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_INDEX8));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGB332", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGB332));
    mrb_define_const(mrb, mod, "PIXELFORMAT_XRGB4444", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_XRGB4444));
    mrb_define_const(mrb, mod, "PIXELFORMAT_XBGR4444", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_XBGR4444));
    mrb_define_const(mrb, mod, "PIXELFORMAT_XRGB1555", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_XRGB1555));
    mrb_define_const(mrb, mod, "PIXELFORMAT_XBGR1555", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_XBGR1555));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ARGB4444", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ARGB4444));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGBA4444", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGBA4444));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ABGR4444", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ABGR4444));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGRA4444", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGRA4444));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ARGB1555", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ARGB1555));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGBA5551", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGBA5551));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ABGR1555", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ABGR1555));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGRA5551", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGRA5551));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGB565", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGB565));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGR565", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGR565));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGB24", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGB24));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGR24", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGR24));
    mrb_define_const(mrb, mod, "PIXELFORMAT_XRGB8888", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_XRGB8888));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGBX8888", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGBX8888));
    mrb_define_const(mrb, mod, "PIXELFORMAT_XBGR8888", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_XBGR8888));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGRX8888", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGRX8888));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ARGB8888", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ARGB8888));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGBA8888", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGBA8888));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ABGR8888", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ABGR8888));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGRA8888", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGRA8888));
    mrb_define_const(mrb, mod, "PIXELFORMAT_XRGB2101010", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_XRGB2101010));
    mrb_define_const(mrb, mod, "PIXELFORMAT_XBGR2101010", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_XBGR2101010));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ARGB2101010", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ARGB2101010));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ABGR2101010", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ABGR2101010));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGB48", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGB48));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGR48", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGR48));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGBA64", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGBA64));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ARGB64", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ARGB64));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGRA64", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGRA64));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ABGR64", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ABGR64));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGB48_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGB48_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGR48_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGR48_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGBA64_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGBA64_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ARGB64_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ARGB64_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGRA64_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGRA64_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ABGR64_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ABGR64_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGB96_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGB96_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGR96_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGR96_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGBA128_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGBA128_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ARGB128_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ARGB128_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGRA128_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGRA128_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ABGR128_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ABGR128_FLOAT));
    mrb_define_const(mrb, mod, "PIXELFORMAT_YV12", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_YV12));
    mrb_define_const(mrb, mod, "PIXELFORMAT_IYUV", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_IYUV));
    mrb_define_const(mrb, mod, "PIXELFORMAT_YUY2", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_YUY2));
    mrb_define_const(mrb, mod, "PIXELFORMAT_UYVY", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_UYVY));
    mrb_define_const(mrb, mod, "PIXELFORMAT_YVYU", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_YVYU));
    mrb_define_const(mrb, mod, "PIXELFORMAT_NV12", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_NV12));
    mrb_define_const(mrb, mod, "PIXELFORMAT_NV21", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_NV21));
    mrb_define_const(mrb, mod, "PIXELFORMAT_P010", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_P010));
    mrb_define_const(mrb, mod, "PIXELFORMAT_EXTERNAL_OES", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_EXTERNAL_OES));
    mrb_define_const(mrb, mod, "PIXELFORMAT_MJPG", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_MJPG));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ARGB32", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ARGB32));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGRA32", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGRA32));
    mrb_define_const(mrb, mod, "PIXELFORMAT_ABGR32", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_ABGR32));
    mrb_define_const(mrb, mod, "PIXELFORMAT_RGBX32", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_RGBX32));
    mrb_define_const(mrb, mod, "PIXELFORMAT_XRGB32", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_XRGB32));
    mrb_define_const(mrb, mod, "PIXELFORMAT_BGRX32", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_BGRX32));
    mrb_define_const(mrb, mod, "PIXELFORMAT_XBGR32", mrb_int_value(mrb, (mrb_int)SDL_PIXELFORMAT_XBGR32));
    mrb_define_const(mrb, mod, "PIXELTYPE_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_UNKNOWN));
    mrb_define_const(mrb, mod, "PIXELTYPE_INDEX1", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_INDEX1));
    mrb_define_const(mrb, mod, "PIXELTYPE_INDEX4", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_INDEX4));
    mrb_define_const(mrb, mod, "PIXELTYPE_INDEX8", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_INDEX8));
    mrb_define_const(mrb, mod, "PIXELTYPE_PACKED8", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_PACKED8));
    mrb_define_const(mrb, mod, "PIXELTYPE_PACKED16", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_PACKED16));
    mrb_define_const(mrb, mod, "PIXELTYPE_PACKED32", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_PACKED32));
    mrb_define_const(mrb, mod, "PIXELTYPE_ARRAYU8", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_ARRAYU8));
    mrb_define_const(mrb, mod, "PIXELTYPE_ARRAYU16", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_ARRAYU16));
    mrb_define_const(mrb, mod, "PIXELTYPE_ARRAYU32", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_ARRAYU32));
    mrb_define_const(mrb, mod, "PIXELTYPE_ARRAYF16", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_ARRAYF16));
    mrb_define_const(mrb, mod, "PIXELTYPE_ARRAYF32", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_ARRAYF32));
    mrb_define_const(mrb, mod, "PIXELTYPE_INDEX2", mrb_int_value(mrb, (mrb_int)SDL_PIXELTYPE_INDEX2));
    mrb_define_const(mrb, mod, "POWERSTATE_ERROR", mrb_int_value(mrb, (mrb_int)SDL_POWERSTATE_ERROR));
    mrb_define_const(mrb, mod, "POWERSTATE_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_POWERSTATE_UNKNOWN));
    mrb_define_const(mrb, mod, "POWERSTATE_ON_BATTERY", mrb_int_value(mrb, (mrb_int)SDL_POWERSTATE_ON_BATTERY));
    mrb_define_const(mrb, mod, "POWERSTATE_NO_BATTERY", mrb_int_value(mrb, (mrb_int)SDL_POWERSTATE_NO_BATTERY));
    mrb_define_const(mrb, mod, "POWERSTATE_CHARGING", mrb_int_value(mrb, (mrb_int)SDL_POWERSTATE_CHARGING));
    mrb_define_const(mrb, mod, "POWERSTATE_CHARGED", mrb_int_value(mrb, (mrb_int)SDL_POWERSTATE_CHARGED));
    mrb_define_const(mrb, mod, "PROCESS_STDIO_INHERITED", mrb_int_value(mrb, (mrb_int)SDL_PROCESS_STDIO_INHERITED));
    mrb_define_const(mrb, mod, "PROCESS_STDIO_NULL", mrb_int_value(mrb, (mrb_int)SDL_PROCESS_STDIO_NULL));
    mrb_define_const(mrb, mod, "PROCESS_STDIO_APP", mrb_int_value(mrb, (mrb_int)SDL_PROCESS_STDIO_APP));
    mrb_define_const(mrb, mod, "PROCESS_STDIO_REDIRECT", mrb_int_value(mrb, (mrb_int)SDL_PROCESS_STDIO_REDIRECT));
    mrb_define_const(mrb, mod, "PROGRESS_STATE_INVALID", mrb_int_value(mrb, (mrb_int)SDL_PROGRESS_STATE_INVALID));
    mrb_define_const(mrb, mod, "PROGRESS_STATE_NONE", mrb_int_value(mrb, (mrb_int)SDL_PROGRESS_STATE_NONE));
    mrb_define_const(mrb, mod, "PROGRESS_STATE_INDETERMINATE", mrb_int_value(mrb, (mrb_int)SDL_PROGRESS_STATE_INDETERMINATE));
    mrb_define_const(mrb, mod, "PROGRESS_STATE_NORMAL", mrb_int_value(mrb, (mrb_int)SDL_PROGRESS_STATE_NORMAL));
    mrb_define_const(mrb, mod, "PROGRESS_STATE_PAUSED", mrb_int_value(mrb, (mrb_int)SDL_PROGRESS_STATE_PAUSED));
    mrb_define_const(mrb, mod, "PROGRESS_STATE_ERROR", mrb_int_value(mrb, (mrb_int)SDL_PROGRESS_STATE_ERROR));
    mrb_define_const(mrb, mod, "PROPERTY_TYPE_INVALID", mrb_int_value(mrb, (mrb_int)SDL_PROPERTY_TYPE_INVALID));
    mrb_define_const(mrb, mod, "PROPERTY_TYPE_POINTER", mrb_int_value(mrb, (mrb_int)SDL_PROPERTY_TYPE_POINTER));
    mrb_define_const(mrb, mod, "PROPERTY_TYPE_STRING", mrb_int_value(mrb, (mrb_int)SDL_PROPERTY_TYPE_STRING));
    mrb_define_const(mrb, mod, "PROPERTY_TYPE_NUMBER", mrb_int_value(mrb, (mrb_int)SDL_PROPERTY_TYPE_NUMBER));
    mrb_define_const(mrb, mod, "PROPERTY_TYPE_FLOAT", mrb_int_value(mrb, (mrb_int)SDL_PROPERTY_TYPE_FLOAT));
    mrb_define_const(mrb, mod, "PROPERTY_TYPE_BOOLEAN", mrb_int_value(mrb, (mrb_int)SDL_PROPERTY_TYPE_BOOLEAN));
    mrb_define_const(mrb, mod, "LOGICAL_PRESENTATION_DISABLED", mrb_int_value(mrb, (mrb_int)SDL_LOGICAL_PRESENTATION_DISABLED));
    mrb_define_const(mrb, mod, "LOGICAL_PRESENTATION_STRETCH", mrb_int_value(mrb, (mrb_int)SDL_LOGICAL_PRESENTATION_STRETCH));
    mrb_define_const(mrb, mod, "LOGICAL_PRESENTATION_LETTERBOX", mrb_int_value(mrb, (mrb_int)SDL_LOGICAL_PRESENTATION_LETTERBOX));
    mrb_define_const(mrb, mod, "LOGICAL_PRESENTATION_OVERSCAN", mrb_int_value(mrb, (mrb_int)SDL_LOGICAL_PRESENTATION_OVERSCAN));
    mrb_define_const(mrb, mod, "LOGICAL_PRESENTATION_INTEGER_SCALE", mrb_int_value(mrb, (mrb_int)SDL_LOGICAL_PRESENTATION_INTEGER_SCALE));
    mrb_define_const(mrb, mod, "SANDBOX_NONE", mrb_int_value(mrb, (mrb_int)SDL_SANDBOX_NONE));
    mrb_define_const(mrb, mod, "SANDBOX_UNKNOWN_CONTAINER", mrb_int_value(mrb, (mrb_int)SDL_SANDBOX_UNKNOWN_CONTAINER));
    mrb_define_const(mrb, mod, "SANDBOX_FLATPAK", mrb_int_value(mrb, (mrb_int)SDL_SANDBOX_FLATPAK));
    mrb_define_const(mrb, mod, "SANDBOX_SNAP", mrb_int_value(mrb, (mrb_int)SDL_SANDBOX_SNAP));
    mrb_define_const(mrb, mod, "SANDBOX_MACOS", mrb_int_value(mrb, (mrb_int)SDL_SANDBOX_MACOS));
    mrb_define_const(mrb, mod, "SCALEMODE_INVALID", mrb_int_value(mrb, (mrb_int)SDL_SCALEMODE_INVALID));
    mrb_define_const(mrb, mod, "SCALEMODE_NEAREST", mrb_int_value(mrb, (mrb_int)SDL_SCALEMODE_NEAREST));
    mrb_define_const(mrb, mod, "SCALEMODE_LINEAR", mrb_int_value(mrb, (mrb_int)SDL_SCALEMODE_LINEAR));
    mrb_define_const(mrb, mod, "SCALEMODE_PIXELART", mrb_int_value(mrb, (mrb_int)SDL_SCALEMODE_PIXELART));
    mrb_define_const(mrb, mod, "SCANCODE_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_UNKNOWN));
    mrb_define_const(mrb, mod, "SCANCODE_A", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_A));
    mrb_define_const(mrb, mod, "SCANCODE_B", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_B));
    mrb_define_const(mrb, mod, "SCANCODE_C", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_C));
    mrb_define_const(mrb, mod, "SCANCODE_D", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_D));
    mrb_define_const(mrb, mod, "SCANCODE_E", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_E));
    mrb_define_const(mrb, mod, "SCANCODE_F", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F));
    mrb_define_const(mrb, mod, "SCANCODE_G", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_G));
    mrb_define_const(mrb, mod, "SCANCODE_H", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_H));
    mrb_define_const(mrb, mod, "SCANCODE_I", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_I));
    mrb_define_const(mrb, mod, "SCANCODE_J", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_J));
    mrb_define_const(mrb, mod, "SCANCODE_K", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_K));
    mrb_define_const(mrb, mod, "SCANCODE_L", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_L));
    mrb_define_const(mrb, mod, "SCANCODE_M", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_M));
    mrb_define_const(mrb, mod, "SCANCODE_N", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_N));
    mrb_define_const(mrb, mod, "SCANCODE_O", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_O));
    mrb_define_const(mrb, mod, "SCANCODE_P", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_P));
    mrb_define_const(mrb, mod, "SCANCODE_Q", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_Q));
    mrb_define_const(mrb, mod, "SCANCODE_R", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_R));
    mrb_define_const(mrb, mod, "SCANCODE_S", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_S));
    mrb_define_const(mrb, mod, "SCANCODE_T", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_T));
    mrb_define_const(mrb, mod, "SCANCODE_U", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_U));
    mrb_define_const(mrb, mod, "SCANCODE_V", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_V));
    mrb_define_const(mrb, mod, "SCANCODE_W", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_W));
    mrb_define_const(mrb, mod, "SCANCODE_X", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_X));
    mrb_define_const(mrb, mod, "SCANCODE_Y", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_Y));
    mrb_define_const(mrb, mod, "SCANCODE_Z", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_Z));
    mrb_define_const(mrb, mod, "SCANCODE_1", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_1));
    mrb_define_const(mrb, mod, "SCANCODE_2", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_2));
    mrb_define_const(mrb, mod, "SCANCODE_3", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_3));
    mrb_define_const(mrb, mod, "SCANCODE_4", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_4));
    mrb_define_const(mrb, mod, "SCANCODE_5", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_5));
    mrb_define_const(mrb, mod, "SCANCODE_6", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_6));
    mrb_define_const(mrb, mod, "SCANCODE_7", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_7));
    mrb_define_const(mrb, mod, "SCANCODE_8", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_8));
    mrb_define_const(mrb, mod, "SCANCODE_9", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_9));
    mrb_define_const(mrb, mod, "SCANCODE_0", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_0));
    mrb_define_const(mrb, mod, "SCANCODE_RETURN", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_RETURN));
    mrb_define_const(mrb, mod, "SCANCODE_ESCAPE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_ESCAPE));
    mrb_define_const(mrb, mod, "SCANCODE_BACKSPACE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_BACKSPACE));
    mrb_define_const(mrb, mod, "SCANCODE_TAB", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_TAB));
    mrb_define_const(mrb, mod, "SCANCODE_SPACE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_SPACE));
    mrb_define_const(mrb, mod, "SCANCODE_MINUS", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MINUS));
    mrb_define_const(mrb, mod, "SCANCODE_EQUALS", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_EQUALS));
    mrb_define_const(mrb, mod, "SCANCODE_LEFTBRACKET", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LEFTBRACKET));
    mrb_define_const(mrb, mod, "SCANCODE_RIGHTBRACKET", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_RIGHTBRACKET));
    mrb_define_const(mrb, mod, "SCANCODE_BACKSLASH", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_BACKSLASH));
    mrb_define_const(mrb, mod, "SCANCODE_NONUSHASH", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_NONUSHASH));
    mrb_define_const(mrb, mod, "SCANCODE_SEMICOLON", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_SEMICOLON));
    mrb_define_const(mrb, mod, "SCANCODE_APOSTROPHE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_APOSTROPHE));
    mrb_define_const(mrb, mod, "SCANCODE_GRAVE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_GRAVE));
    mrb_define_const(mrb, mod, "SCANCODE_COMMA", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_COMMA));
    mrb_define_const(mrb, mod, "SCANCODE_PERIOD", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_PERIOD));
    mrb_define_const(mrb, mod, "SCANCODE_SLASH", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_SLASH));
    mrb_define_const(mrb, mod, "SCANCODE_CAPSLOCK", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_CAPSLOCK));
    mrb_define_const(mrb, mod, "SCANCODE_F1", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F1));
    mrb_define_const(mrb, mod, "SCANCODE_F2", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F2));
    mrb_define_const(mrb, mod, "SCANCODE_F3", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F3));
    mrb_define_const(mrb, mod, "SCANCODE_F4", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F4));
    mrb_define_const(mrb, mod, "SCANCODE_F5", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F5));
    mrb_define_const(mrb, mod, "SCANCODE_F6", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F6));
    mrb_define_const(mrb, mod, "SCANCODE_F7", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F7));
    mrb_define_const(mrb, mod, "SCANCODE_F8", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F8));
    mrb_define_const(mrb, mod, "SCANCODE_F9", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F9));
    mrb_define_const(mrb, mod, "SCANCODE_F10", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F10));
    mrb_define_const(mrb, mod, "SCANCODE_F11", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F11));
    mrb_define_const(mrb, mod, "SCANCODE_F12", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F12));
    mrb_define_const(mrb, mod, "SCANCODE_PRINTSCREEN", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_PRINTSCREEN));
    mrb_define_const(mrb, mod, "SCANCODE_SCROLLLOCK", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_SCROLLLOCK));
    mrb_define_const(mrb, mod, "SCANCODE_PAUSE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_PAUSE));
    mrb_define_const(mrb, mod, "SCANCODE_INSERT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_INSERT));
    mrb_define_const(mrb, mod, "SCANCODE_HOME", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_HOME));
    mrb_define_const(mrb, mod, "SCANCODE_PAGEUP", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_PAGEUP));
    mrb_define_const(mrb, mod, "SCANCODE_DELETE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_DELETE));
    mrb_define_const(mrb, mod, "SCANCODE_END", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_END));
    mrb_define_const(mrb, mod, "SCANCODE_PAGEDOWN", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_PAGEDOWN));
    mrb_define_const(mrb, mod, "SCANCODE_RIGHT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_RIGHT));
    mrb_define_const(mrb, mod, "SCANCODE_LEFT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LEFT));
    mrb_define_const(mrb, mod, "SCANCODE_DOWN", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_DOWN));
    mrb_define_const(mrb, mod, "SCANCODE_UP", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_UP));
    mrb_define_const(mrb, mod, "SCANCODE_NUMLOCKCLEAR", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_NUMLOCKCLEAR));
    mrb_define_const(mrb, mod, "SCANCODE_KP_DIVIDE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_DIVIDE));
    mrb_define_const(mrb, mod, "SCANCODE_KP_MULTIPLY", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_MULTIPLY));
    mrb_define_const(mrb, mod, "SCANCODE_KP_MINUS", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_MINUS));
    mrb_define_const(mrb, mod, "SCANCODE_KP_PLUS", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_PLUS));
    mrb_define_const(mrb, mod, "SCANCODE_KP_ENTER", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_ENTER));
    mrb_define_const(mrb, mod, "SCANCODE_KP_1", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_1));
    mrb_define_const(mrb, mod, "SCANCODE_KP_2", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_2));
    mrb_define_const(mrb, mod, "SCANCODE_KP_3", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_3));
    mrb_define_const(mrb, mod, "SCANCODE_KP_4", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_4));
    mrb_define_const(mrb, mod, "SCANCODE_KP_5", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_5));
    mrb_define_const(mrb, mod, "SCANCODE_KP_6", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_6));
    mrb_define_const(mrb, mod, "SCANCODE_KP_7", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_7));
    mrb_define_const(mrb, mod, "SCANCODE_KP_8", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_8));
    mrb_define_const(mrb, mod, "SCANCODE_KP_9", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_9));
    mrb_define_const(mrb, mod, "SCANCODE_KP_0", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_0));
    mrb_define_const(mrb, mod, "SCANCODE_KP_PERIOD", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_PERIOD));
    mrb_define_const(mrb, mod, "SCANCODE_NONUSBACKSLASH", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_NONUSBACKSLASH));
    mrb_define_const(mrb, mod, "SCANCODE_APPLICATION", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_APPLICATION));
    mrb_define_const(mrb, mod, "SCANCODE_POWER", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_POWER));
    mrb_define_const(mrb, mod, "SCANCODE_KP_EQUALS", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_EQUALS));
    mrb_define_const(mrb, mod, "SCANCODE_F13", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F13));
    mrb_define_const(mrb, mod, "SCANCODE_F14", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F14));
    mrb_define_const(mrb, mod, "SCANCODE_F15", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F15));
    mrb_define_const(mrb, mod, "SCANCODE_F16", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F16));
    mrb_define_const(mrb, mod, "SCANCODE_F17", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F17));
    mrb_define_const(mrb, mod, "SCANCODE_F18", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F18));
    mrb_define_const(mrb, mod, "SCANCODE_F19", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F19));
    mrb_define_const(mrb, mod, "SCANCODE_F20", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F20));
    mrb_define_const(mrb, mod, "SCANCODE_F21", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F21));
    mrb_define_const(mrb, mod, "SCANCODE_F22", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F22));
    mrb_define_const(mrb, mod, "SCANCODE_F23", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F23));
    mrb_define_const(mrb, mod, "SCANCODE_F24", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_F24));
    mrb_define_const(mrb, mod, "SCANCODE_EXECUTE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_EXECUTE));
    mrb_define_const(mrb, mod, "SCANCODE_HELP", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_HELP));
    mrb_define_const(mrb, mod, "SCANCODE_MENU", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MENU));
    mrb_define_const(mrb, mod, "SCANCODE_SELECT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_SELECT));
    mrb_define_const(mrb, mod, "SCANCODE_STOP", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_STOP));
    mrb_define_const(mrb, mod, "SCANCODE_AGAIN", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AGAIN));
    mrb_define_const(mrb, mod, "SCANCODE_UNDO", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_UNDO));
    mrb_define_const(mrb, mod, "SCANCODE_CUT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_CUT));
    mrb_define_const(mrb, mod, "SCANCODE_COPY", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_COPY));
    mrb_define_const(mrb, mod, "SCANCODE_PASTE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_PASTE));
    mrb_define_const(mrb, mod, "SCANCODE_FIND", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_FIND));
    mrb_define_const(mrb, mod, "SCANCODE_MUTE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MUTE));
    mrb_define_const(mrb, mod, "SCANCODE_VOLUMEUP", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_VOLUMEUP));
    mrb_define_const(mrb, mod, "SCANCODE_VOLUMEDOWN", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_VOLUMEDOWN));
    mrb_define_const(mrb, mod, "SCANCODE_KP_COMMA", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_COMMA));
    mrb_define_const(mrb, mod, "SCANCODE_KP_EQUALSAS400", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_EQUALSAS400));
    mrb_define_const(mrb, mod, "SCANCODE_INTERNATIONAL1", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_INTERNATIONAL1));
    mrb_define_const(mrb, mod, "SCANCODE_INTERNATIONAL2", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_INTERNATIONAL2));
    mrb_define_const(mrb, mod, "SCANCODE_INTERNATIONAL3", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_INTERNATIONAL3));
    mrb_define_const(mrb, mod, "SCANCODE_INTERNATIONAL4", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_INTERNATIONAL4));
    mrb_define_const(mrb, mod, "SCANCODE_INTERNATIONAL5", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_INTERNATIONAL5));
    mrb_define_const(mrb, mod, "SCANCODE_INTERNATIONAL6", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_INTERNATIONAL6));
    mrb_define_const(mrb, mod, "SCANCODE_INTERNATIONAL7", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_INTERNATIONAL7));
    mrb_define_const(mrb, mod, "SCANCODE_INTERNATIONAL8", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_INTERNATIONAL8));
    mrb_define_const(mrb, mod, "SCANCODE_INTERNATIONAL9", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_INTERNATIONAL9));
    mrb_define_const(mrb, mod, "SCANCODE_LANG1", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LANG1));
    mrb_define_const(mrb, mod, "SCANCODE_LANG2", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LANG2));
    mrb_define_const(mrb, mod, "SCANCODE_LANG3", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LANG3));
    mrb_define_const(mrb, mod, "SCANCODE_LANG4", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LANG4));
    mrb_define_const(mrb, mod, "SCANCODE_LANG5", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LANG5));
    mrb_define_const(mrb, mod, "SCANCODE_LANG6", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LANG6));
    mrb_define_const(mrb, mod, "SCANCODE_LANG7", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LANG7));
    mrb_define_const(mrb, mod, "SCANCODE_LANG8", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LANG8));
    mrb_define_const(mrb, mod, "SCANCODE_LANG9", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LANG9));
    mrb_define_const(mrb, mod, "SCANCODE_ALTERASE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_ALTERASE));
    mrb_define_const(mrb, mod, "SCANCODE_SYSREQ", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_SYSREQ));
    mrb_define_const(mrb, mod, "SCANCODE_CANCEL", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_CANCEL));
    mrb_define_const(mrb, mod, "SCANCODE_CLEAR", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_CLEAR));
    mrb_define_const(mrb, mod, "SCANCODE_PRIOR", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_PRIOR));
    mrb_define_const(mrb, mod, "SCANCODE_RETURN2", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_RETURN2));
    mrb_define_const(mrb, mod, "SCANCODE_SEPARATOR", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_SEPARATOR));
    mrb_define_const(mrb, mod, "SCANCODE_OUT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_OUT));
    mrb_define_const(mrb, mod, "SCANCODE_OPER", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_OPER));
    mrb_define_const(mrb, mod, "SCANCODE_CLEARAGAIN", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_CLEARAGAIN));
    mrb_define_const(mrb, mod, "SCANCODE_CRSEL", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_CRSEL));
    mrb_define_const(mrb, mod, "SCANCODE_EXSEL", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_EXSEL));
    mrb_define_const(mrb, mod, "SCANCODE_KP_00", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_00));
    mrb_define_const(mrb, mod, "SCANCODE_KP_000", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_000));
    mrb_define_const(mrb, mod, "SCANCODE_THOUSANDSSEPARATOR", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_THOUSANDSSEPARATOR));
    mrb_define_const(mrb, mod, "SCANCODE_DECIMALSEPARATOR", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_DECIMALSEPARATOR));
    mrb_define_const(mrb, mod, "SCANCODE_CURRENCYUNIT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_CURRENCYUNIT));
    mrb_define_const(mrb, mod, "SCANCODE_CURRENCYSUBUNIT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_CURRENCYSUBUNIT));
    mrb_define_const(mrb, mod, "SCANCODE_KP_LEFTPAREN", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_LEFTPAREN));
    mrb_define_const(mrb, mod, "SCANCODE_KP_RIGHTPAREN", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_RIGHTPAREN));
    mrb_define_const(mrb, mod, "SCANCODE_KP_LEFTBRACE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_LEFTBRACE));
    mrb_define_const(mrb, mod, "SCANCODE_KP_RIGHTBRACE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_RIGHTBRACE));
    mrb_define_const(mrb, mod, "SCANCODE_KP_TAB", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_TAB));
    mrb_define_const(mrb, mod, "SCANCODE_KP_BACKSPACE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_BACKSPACE));
    mrb_define_const(mrb, mod, "SCANCODE_KP_A", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_A));
    mrb_define_const(mrb, mod, "SCANCODE_KP_B", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_B));
    mrb_define_const(mrb, mod, "SCANCODE_KP_C", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_C));
    mrb_define_const(mrb, mod, "SCANCODE_KP_D", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_D));
    mrb_define_const(mrb, mod, "SCANCODE_KP_E", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_E));
    mrb_define_const(mrb, mod, "SCANCODE_KP_F", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_F));
    mrb_define_const(mrb, mod, "SCANCODE_KP_XOR", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_XOR));
    mrb_define_const(mrb, mod, "SCANCODE_KP_POWER", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_POWER));
    mrb_define_const(mrb, mod, "SCANCODE_KP_PERCENT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_PERCENT));
    mrb_define_const(mrb, mod, "SCANCODE_KP_LESS", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_LESS));
    mrb_define_const(mrb, mod, "SCANCODE_KP_GREATER", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_GREATER));
    mrb_define_const(mrb, mod, "SCANCODE_KP_AMPERSAND", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_AMPERSAND));
    mrb_define_const(mrb, mod, "SCANCODE_KP_DBLAMPERSAND", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_DBLAMPERSAND));
    mrb_define_const(mrb, mod, "SCANCODE_KP_VERTICALBAR", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_VERTICALBAR));
    mrb_define_const(mrb, mod, "SCANCODE_KP_DBLVERTICALBAR", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_DBLVERTICALBAR));
    mrb_define_const(mrb, mod, "SCANCODE_KP_COLON", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_COLON));
    mrb_define_const(mrb, mod, "SCANCODE_KP_HASH", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_HASH));
    mrb_define_const(mrb, mod, "SCANCODE_KP_SPACE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_SPACE));
    mrb_define_const(mrb, mod, "SCANCODE_KP_AT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_AT));
    mrb_define_const(mrb, mod, "SCANCODE_KP_EXCLAM", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_EXCLAM));
    mrb_define_const(mrb, mod, "SCANCODE_KP_MEMSTORE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_MEMSTORE));
    mrb_define_const(mrb, mod, "SCANCODE_KP_MEMRECALL", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_MEMRECALL));
    mrb_define_const(mrb, mod, "SCANCODE_KP_MEMCLEAR", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_MEMCLEAR));
    mrb_define_const(mrb, mod, "SCANCODE_KP_MEMADD", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_MEMADD));
    mrb_define_const(mrb, mod, "SCANCODE_KP_MEMSUBTRACT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_MEMSUBTRACT));
    mrb_define_const(mrb, mod, "SCANCODE_KP_MEMMULTIPLY", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_MEMMULTIPLY));
    mrb_define_const(mrb, mod, "SCANCODE_KP_MEMDIVIDE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_MEMDIVIDE));
    mrb_define_const(mrb, mod, "SCANCODE_KP_PLUSMINUS", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_PLUSMINUS));
    mrb_define_const(mrb, mod, "SCANCODE_KP_CLEAR", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_CLEAR));
    mrb_define_const(mrb, mod, "SCANCODE_KP_CLEARENTRY", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_CLEARENTRY));
    mrb_define_const(mrb, mod, "SCANCODE_KP_BINARY", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_BINARY));
    mrb_define_const(mrb, mod, "SCANCODE_KP_OCTAL", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_OCTAL));
    mrb_define_const(mrb, mod, "SCANCODE_KP_DECIMAL", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_DECIMAL));
    mrb_define_const(mrb, mod, "SCANCODE_KP_HEXADECIMAL", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_KP_HEXADECIMAL));
    mrb_define_const(mrb, mod, "SCANCODE_LCTRL", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LCTRL));
    mrb_define_const(mrb, mod, "SCANCODE_LSHIFT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LSHIFT));
    mrb_define_const(mrb, mod, "SCANCODE_LALT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LALT));
    mrb_define_const(mrb, mod, "SCANCODE_LGUI", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_LGUI));
    mrb_define_const(mrb, mod, "SCANCODE_RCTRL", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_RCTRL));
    mrb_define_const(mrb, mod, "SCANCODE_RSHIFT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_RSHIFT));
    mrb_define_const(mrb, mod, "SCANCODE_RALT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_RALT));
    mrb_define_const(mrb, mod, "SCANCODE_RGUI", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_RGUI));
    mrb_define_const(mrb, mod, "SCANCODE_MODE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MODE));
    mrb_define_const(mrb, mod, "SCANCODE_SLEEP", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_SLEEP));
    mrb_define_const(mrb, mod, "SCANCODE_WAKE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_WAKE));
    mrb_define_const(mrb, mod, "SCANCODE_CHANNEL_INCREMENT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_CHANNEL_INCREMENT));
    mrb_define_const(mrb, mod, "SCANCODE_CHANNEL_DECREMENT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_CHANNEL_DECREMENT));
    mrb_define_const(mrb, mod, "SCANCODE_MEDIA_PLAY", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MEDIA_PLAY));
    mrb_define_const(mrb, mod, "SCANCODE_MEDIA_PAUSE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MEDIA_PAUSE));
    mrb_define_const(mrb, mod, "SCANCODE_MEDIA_RECORD", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MEDIA_RECORD));
    mrb_define_const(mrb, mod, "SCANCODE_MEDIA_FAST_FORWARD", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MEDIA_FAST_FORWARD));
    mrb_define_const(mrb, mod, "SCANCODE_MEDIA_REWIND", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MEDIA_REWIND));
    mrb_define_const(mrb, mod, "SCANCODE_MEDIA_NEXT_TRACK", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MEDIA_NEXT_TRACK));
    mrb_define_const(mrb, mod, "SCANCODE_MEDIA_PREVIOUS_TRACK", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MEDIA_PREVIOUS_TRACK));
    mrb_define_const(mrb, mod, "SCANCODE_MEDIA_STOP", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MEDIA_STOP));
    mrb_define_const(mrb, mod, "SCANCODE_MEDIA_EJECT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MEDIA_EJECT));
    mrb_define_const(mrb, mod, "SCANCODE_MEDIA_PLAY_PAUSE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MEDIA_PLAY_PAUSE));
    mrb_define_const(mrb, mod, "SCANCODE_MEDIA_SELECT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_MEDIA_SELECT));
    mrb_define_const(mrb, mod, "SCANCODE_AC_NEW", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_NEW));
    mrb_define_const(mrb, mod, "SCANCODE_AC_OPEN", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_OPEN));
    mrb_define_const(mrb, mod, "SCANCODE_AC_CLOSE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_CLOSE));
    mrb_define_const(mrb, mod, "SCANCODE_AC_EXIT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_EXIT));
    mrb_define_const(mrb, mod, "SCANCODE_AC_SAVE", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_SAVE));
    mrb_define_const(mrb, mod, "SCANCODE_AC_PRINT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_PRINT));
    mrb_define_const(mrb, mod, "SCANCODE_AC_PROPERTIES", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_PROPERTIES));
    mrb_define_const(mrb, mod, "SCANCODE_AC_SEARCH", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_SEARCH));
    mrb_define_const(mrb, mod, "SCANCODE_AC_HOME", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_HOME));
    mrb_define_const(mrb, mod, "SCANCODE_AC_BACK", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_BACK));
    mrb_define_const(mrb, mod, "SCANCODE_AC_FORWARD", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_FORWARD));
    mrb_define_const(mrb, mod, "SCANCODE_AC_STOP", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_STOP));
    mrb_define_const(mrb, mod, "SCANCODE_AC_REFRESH", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_REFRESH));
    mrb_define_const(mrb, mod, "SCANCODE_AC_BOOKMARKS", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_AC_BOOKMARKS));
    mrb_define_const(mrb, mod, "SCANCODE_SOFTLEFT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_SOFTLEFT));
    mrb_define_const(mrb, mod, "SCANCODE_SOFTRIGHT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_SOFTRIGHT));
    mrb_define_const(mrb, mod, "SCANCODE_CALL", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_CALL));
    mrb_define_const(mrb, mod, "SCANCODE_ENDCALL", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_ENDCALL));
    mrb_define_const(mrb, mod, "SCANCODE_RESERVED", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_RESERVED));
    mrb_define_const(mrb, mod, "SCANCODE_COUNT", mrb_int_value(mrb, (mrb_int)SDL_SCANCODE_COUNT));
    mrb_define_const(mrb, mod, "SENSOR_INVALID", mrb_int_value(mrb, (mrb_int)SDL_SENSOR_INVALID));
    mrb_define_const(mrb, mod, "SENSOR_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_SENSOR_UNKNOWN));
    mrb_define_const(mrb, mod, "SENSOR_ACCEL", mrb_int_value(mrb, (mrb_int)SDL_SENSOR_ACCEL));
    mrb_define_const(mrb, mod, "SENSOR_GYRO", mrb_int_value(mrb, (mrb_int)SDL_SENSOR_GYRO));
    mrb_define_const(mrb, mod, "SENSOR_ACCEL_L", mrb_int_value(mrb, (mrb_int)SDL_SENSOR_ACCEL_L));
    mrb_define_const(mrb, mod, "SENSOR_GYRO_L", mrb_int_value(mrb, (mrb_int)SDL_SENSOR_GYRO_L));
    mrb_define_const(mrb, mod, "SENSOR_ACCEL_R", mrb_int_value(mrb, (mrb_int)SDL_SENSOR_ACCEL_R));
    mrb_define_const(mrb, mod, "SENSOR_GYRO_R", mrb_int_value(mrb, (mrb_int)SDL_SENSOR_GYRO_R));
    mrb_define_const(mrb, mod, "SENSOR_COUNT", mrb_int_value(mrb, (mrb_int)SDL_SENSOR_COUNT));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_DEFAULT", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_DEFAULT));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_TEXT", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_TEXT));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_WAIT", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_WAIT));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_CROSSHAIR", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_CROSSHAIR));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_PROGRESS", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_PROGRESS));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_NWSE_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_NWSE_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_NESW_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_NESW_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_EW_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_EW_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_NS_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_NS_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_MOVE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_MOVE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_NOT_ALLOWED", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_NOT_ALLOWED));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_POINTER", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_POINTER));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_NW_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_NW_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_N_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_N_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_NE_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_NE_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_E_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_E_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_SE_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_SE_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_S_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_S_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_SW_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_SW_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_W_RESIZE", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_W_RESIZE));
    mrb_define_const(mrb, mod, "SYSTEM_CURSOR_COUNT", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_CURSOR_COUNT));
    mrb_define_const(mrb, mod, "SYSTEM_THEME_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_THEME_UNKNOWN));
    mrb_define_const(mrb, mod, "SYSTEM_THEME_LIGHT", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_THEME_LIGHT));
    mrb_define_const(mrb, mod, "SYSTEM_THEME_DARK", mrb_int_value(mrb, (mrb_int)SDL_SYSTEM_THEME_DARK));
    mrb_define_const(mrb, mod, "TEXTINPUT_TYPE_TEXT", mrb_int_value(mrb, (mrb_int)SDL_TEXTINPUT_TYPE_TEXT));
    mrb_define_const(mrb, mod, "TEXTINPUT_TYPE_TEXT_NAME", mrb_int_value(mrb, (mrb_int)SDL_TEXTINPUT_TYPE_TEXT_NAME));
    mrb_define_const(mrb, mod, "TEXTINPUT_TYPE_TEXT_EMAIL", mrb_int_value(mrb, (mrb_int)SDL_TEXTINPUT_TYPE_TEXT_EMAIL));
    mrb_define_const(mrb, mod, "TEXTINPUT_TYPE_TEXT_USERNAME", mrb_int_value(mrb, (mrb_int)SDL_TEXTINPUT_TYPE_TEXT_USERNAME));
    mrb_define_const(mrb, mod, "TEXTINPUT_TYPE_TEXT_PASSWORD_HIDDEN", mrb_int_value(mrb, (mrb_int)SDL_TEXTINPUT_TYPE_TEXT_PASSWORD_HIDDEN));
    mrb_define_const(mrb, mod, "TEXTINPUT_TYPE_TEXT_PASSWORD_VISIBLE", mrb_int_value(mrb, (mrb_int)SDL_TEXTINPUT_TYPE_TEXT_PASSWORD_VISIBLE));
    mrb_define_const(mrb, mod, "TEXTINPUT_TYPE_NUMBER", mrb_int_value(mrb, (mrb_int)SDL_TEXTINPUT_TYPE_NUMBER));
    mrb_define_const(mrb, mod, "TEXTINPUT_TYPE_NUMBER_PASSWORD_HIDDEN", mrb_int_value(mrb, (mrb_int)SDL_TEXTINPUT_TYPE_NUMBER_PASSWORD_HIDDEN));
    mrb_define_const(mrb, mod, "TEXTINPUT_TYPE_NUMBER_PASSWORD_VISIBLE", mrb_int_value(mrb, (mrb_int)SDL_TEXTINPUT_TYPE_NUMBER_PASSWORD_VISIBLE));
    mrb_define_const(mrb, mod, "TEXTUREACCESS_STATIC", mrb_int_value(mrb, (mrb_int)SDL_TEXTUREACCESS_STATIC));
    mrb_define_const(mrb, mod, "TEXTUREACCESS_STREAMING", mrb_int_value(mrb, (mrb_int)SDL_TEXTUREACCESS_STREAMING));
    mrb_define_const(mrb, mod, "TEXTUREACCESS_TARGET", mrb_int_value(mrb, (mrb_int)SDL_TEXTUREACCESS_TARGET));
    mrb_define_const(mrb, mod, "TEXTURE_ADDRESS_INVALID", mrb_int_value(mrb, (mrb_int)SDL_TEXTURE_ADDRESS_INVALID));
    mrb_define_const(mrb, mod, "TEXTURE_ADDRESS_AUTO", mrb_int_value(mrb, (mrb_int)SDL_TEXTURE_ADDRESS_AUTO));
    mrb_define_const(mrb, mod, "TEXTURE_ADDRESS_CLAMP", mrb_int_value(mrb, (mrb_int)SDL_TEXTURE_ADDRESS_CLAMP));
    mrb_define_const(mrb, mod, "TEXTURE_ADDRESS_WRAP", mrb_int_value(mrb, (mrb_int)SDL_TEXTURE_ADDRESS_WRAP));
    mrb_define_const(mrb, mod, "THREAD_PRIORITY_LOW", mrb_int_value(mrb, (mrb_int)SDL_THREAD_PRIORITY_LOW));
    mrb_define_const(mrb, mod, "THREAD_PRIORITY_NORMAL", mrb_int_value(mrb, (mrb_int)SDL_THREAD_PRIORITY_NORMAL));
    mrb_define_const(mrb, mod, "THREAD_PRIORITY_HIGH", mrb_int_value(mrb, (mrb_int)SDL_THREAD_PRIORITY_HIGH));
    mrb_define_const(mrb, mod, "THREAD_PRIORITY_TIME_CRITICAL", mrb_int_value(mrb, (mrb_int)SDL_THREAD_PRIORITY_TIME_CRITICAL));
    mrb_define_const(mrb, mod, "THREAD_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_THREAD_UNKNOWN));
    mrb_define_const(mrb, mod, "THREAD_ALIVE", mrb_int_value(mrb, (mrb_int)SDL_THREAD_ALIVE));
    mrb_define_const(mrb, mod, "THREAD_DETACHED", mrb_int_value(mrb, (mrb_int)SDL_THREAD_DETACHED));
    mrb_define_const(mrb, mod, "THREAD_COMPLETE", mrb_int_value(mrb, (mrb_int)SDL_THREAD_COMPLETE));
    mrb_define_const(mrb, mod, "TIME_FORMAT_24HR", mrb_int_value(mrb, (mrb_int)SDL_TIME_FORMAT_24HR));
    mrb_define_const(mrb, mod, "TIME_FORMAT_12HR", mrb_int_value(mrb, (mrb_int)SDL_TIME_FORMAT_12HR));
    mrb_define_const(mrb, mod, "TOUCH_DEVICE_INVALID", mrb_int_value(mrb, (mrb_int)SDL_TOUCH_DEVICE_INVALID));
    mrb_define_const(mrb, mod, "TOUCH_DEVICE_DIRECT", mrb_int_value(mrb, (mrb_int)SDL_TOUCH_DEVICE_DIRECT));
    mrb_define_const(mrb, mod, "TOUCH_DEVICE_INDIRECT_ABSOLUTE", mrb_int_value(mrb, (mrb_int)SDL_TOUCH_DEVICE_INDIRECT_ABSOLUTE));
    mrb_define_const(mrb, mod, "TOUCH_DEVICE_INDIRECT_RELATIVE", mrb_int_value(mrb, (mrb_int)SDL_TOUCH_DEVICE_INDIRECT_RELATIVE));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_UNKNOWN));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_BT709", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_BT709));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_UNSPECIFIED", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_UNSPECIFIED));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_GAMMA22", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_GAMMA22));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_GAMMA28", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_GAMMA28));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_BT601", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_BT601));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_SMPTE240", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_SMPTE240));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_LINEAR", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_LINEAR));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_LOG100", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_LOG100));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_LOG100_SQRT10", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_LOG100_SQRT10));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_IEC61966", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_IEC61966));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_BT1361", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_BT1361));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_SRGB", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_SRGB));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_BT2020_10BIT", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_BT2020_10BIT));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_BT2020_12BIT", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_BT2020_12BIT));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_PQ", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_PQ));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_SMPTE428", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_SMPTE428));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_HLG", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_HLG));
    mrb_define_const(mrb, mod, "TRANSFER_CHARACTERISTICS_CUSTOM", mrb_int_value(mrb, (mrb_int)SDL_TRANSFER_CHARACTERISTICS_CUSTOM));
    mrb_define_const(mrb, mod, "HID_API_BUS_UNKNOWN", mrb_int_value(mrb, (mrb_int)SDL_HID_API_BUS_UNKNOWN));
    mrb_define_const(mrb, mod, "HID_API_BUS_USB", mrb_int_value(mrb, (mrb_int)SDL_HID_API_BUS_USB));
    mrb_define_const(mrb, mod, "HID_API_BUS_BLUETOOTH", mrb_int_value(mrb, (mrb_int)SDL_HID_API_BUS_BLUETOOTH));
    mrb_define_const(mrb, mod, "HID_API_BUS_I2C", mrb_int_value(mrb, (mrb_int)SDL_HID_API_BUS_I2C));
    mrb_define_const(mrb, mod, "HID_API_BUS_SPI", mrb_int_value(mrb, (mrb_int)SDL_HID_API_BUS_SPI));
}
