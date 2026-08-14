/*
 * sdlstatic_bindings_ruby.c — mruby bindings for the SDLStatic game surface.
 *
 * Original SDLStatic code (zlib). Handles are MRB_TT_CDATA objects whose
 * mrb_data_type dfree runs at GC; children pin parents via instance
 * variables so finalization order is safe. Mirrors the Lua surface.
 */
#include "bindings_core.h"

#include <SDLStatic/base64.h>
#include <SDLStatic/bindings.h>
#include <SDLStatic/compress.h>
#include <SDLStatic/crypto.h>
#include <SDLStatic/vfs.h>
#include <physfs.h>

#include <mruby/array.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/hash.h>
#include <mruby/string.h>
#include <mruby/variable.h>

#define DEF_TYPE(name, freer)                                                                      \
    static void name##_free(mrb_state *mrb, void *p)                                               \
    {                                                                                              \
        (void)mrb;                                                                                 \
        freer(p);                                                                                  \
    }                                                                                              \
    static const struct mrb_data_type name##_type = {#name, name##_free}

static void FreeApp(void *p)
{
    BindApp_Destroy((BindApp *)p);
}
static void FreeTex(void *p)
{
    BindTexture_Destroy((BindTexture *)p);
}
static void FreeAudio(void *p)
{
    BindAudio_Destroy((BindAudio *)p);
}
static void FreeSound(void *p)
{
    BindSound_Destroy((BindSound *)p);
}
static void FreeTrack(void *p)
{
    BindTrack_Destroy((BindTrack *)p);
}
static void FreeWorld(void *p)
{
    BindWorld_Destroy((BindWorld *)p);
}
static void FreeBody(void *p)
{
    BindBody_DestroyWrapper((BindBody *)p);
}

DEF_TYPE(SDLStaticApp, FreeApp);
DEF_TYPE(SDLStaticTexture, FreeTex);
DEF_TYPE(SDLStaticAudio, FreeAudio);
DEF_TYPE(SDLStaticSound, FreeSound);
DEF_TYPE(SDLStaticTrack, FreeTrack);
DEF_TYPE(SDLStaticWorld, FreeWorld);
DEF_TYPE(SDLStaticBody, FreeBody);

static struct RClass *ClassFor(mrb_state *mrb, const char *name)
{
    struct RClass *module = mrb_module_get(mrb, "SDLStatic");
    return mrb_class_get_under(mrb, module, name);
}

static mrb_value WrapChild(mrb_state *mrb, const char *class_name,
                           const struct mrb_data_type *type, void *ptr, mrb_value parent)
{
    struct RClass *cls = ClassFor(mrb, class_name);
    mrb_value obj = mrb_obj_value(mrb_data_object_alloc(mrb, cls, ptr, type));
    if (!mrb_nil_p(parent))
    {
        mrb_iv_set(mrb, obj, mrb_intern_lit(mrb, "@__parent"), parent);
    }
    return obj;
}

static void *Unwrap(mrb_state *mrb, mrb_value obj, const struct mrb_data_type *type)
{
    void *ptr = mrb_data_get_ptr(mrb, obj, type);
    if (ptr == NULL)
    {
        mrb_raise(mrb, E_RUNTIME_ERROR, "handle already destroyed");
    }
    return ptr;
}

static mrb_noreturn void RaiseSdl(mrb_state *mrb)
{
    mrb_raise(mrb, E_RUNTIME_ERROR, SDL_GetError());
}

/* ------------------------------------------------------------- app ------ */

static mrb_value MWindow(mrb_state *mrb, mrb_value self)
{
    (void)self;
    const char *title = NULL;
    mrb_int w = 0;
    mrb_int h = 0;
    mrb_get_args(mrb, "zii", &title, &w, &h);
    BindApp *app = BindApp_Create(title, (int)w, (int)h);
    if (app == NULL)
    {
        RaiseSdl(mrb);
    }
    return WrapChild(mrb, "App", &SDLStaticApp_type, app, mrb_nil_value());
}

static mrb_value MAppClear(mrb_state *mrb, mrb_value self)
{
    mrb_int r, g, b;
    mrb_get_args(mrb, "iii", &r, &g, &b);
    if (!BindApp_Clear((BindApp *)Unwrap(mrb, self, &SDLStaticApp_type), (Uint8)r, (Uint8)g,
                       (Uint8)b))
    {
        RaiseSdl(mrb);
    }
    return mrb_nil_value();
}

static mrb_value MAppPresent(mrb_state *mrb, mrb_value self)
{
    BindApp_Present((BindApp *)Unwrap(mrb, self, &SDLStaticApp_type));
    return mrb_nil_value();
}

static mrb_value MAppPoll(mrb_state *mrb, mrb_value self)
{
    (void)Unwrap(mrb, self, &SDLStaticApp_type);
    BindEvent event;
    if (!BindApp_PollEvent(&event))
    {
        return mrb_nil_value();
    }
    mrb_value hash = mrb_hash_new(mrb);
    mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_lit(mrb, "type")),
                 mrb_str_new_cstr(mrb, event.type));
    if (SDL_strcmp(event.type, "key") == 0)
    {
        mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_lit(mrb, "key")),
                     mrb_str_new_cstr(mrb, event.key));
        mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_lit(mrb, "down")),
                     mrb_bool_value(event.down));
    }
    else if (SDL_strcmp(event.type, "quit") != 0)
    {
        mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_lit(mrb, "x")),
                     mrb_float_value(mrb, event.x));
        mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_lit(mrb, "y")),
                     mrb_float_value(mrb, event.y));
        if (SDL_strcmp(event.type, "mouse") == 0)
        {
            mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_lit(mrb, "button")),
                         mrb_int_value(mrb, event.button));
            mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_lit(mrb, "down")),
                         mrb_bool_value(event.down));
        }
    }
    return hash;
}

static mrb_value MAppRect(mrb_state *mrb, mrb_value self)
{
    mrb_float x, y, w, h;
    mrb_int r, g, b;
    mrb_int a = 255;
    mrb_get_args(mrb, "ffffiii|i", &x, &y, &w, &h, &r, &g, &b, &a);
    if (!BindApp_Rect((BindApp *)Unwrap(mrb, self, &SDLStaticApp_type), (float)x, (float)y,
                      (float)w, (float)h, (Uint8)r, (Uint8)g, (Uint8)b, (Uint8)a))
    {
        RaiseSdl(mrb);
    }
    return mrb_nil_value();
}

static mrb_value MAppCircle(mrb_state *mrb, mrb_value self)
{
    mrb_float x, y, rad;
    mrb_int r, g, b;
    mrb_int a = 255;
    mrb_get_args(mrb, "fffiii|i", &x, &y, &rad, &r, &g, &b, &a);
    if (!BindApp_Circle((BindApp *)Unwrap(mrb, self, &SDLStaticApp_type), (float)x, (float)y,
                        (float)rad, (Uint8)r, (Uint8)g, (Uint8)b, (Uint8)a))
    {
        RaiseSdl(mrb);
    }
    return mrb_nil_value();
}

static mrb_value MAppLine(mrb_state *mrb, mrb_value self)
{
    mrb_float x1, y1, x2, y2;
    mrb_int r, g, b;
    mrb_int a = 255;
    mrb_get_args(mrb, "ffffiii|i", &x1, &y1, &x2, &y2, &r, &g, &b, &a);
    if (!BindApp_Line((BindApp *)Unwrap(mrb, self, &SDLStaticApp_type), (float)x1, (float)y1,
                      (float)x2, (float)y2, (Uint8)r, (Uint8)g, (Uint8)b, (Uint8)a))
    {
        RaiseSdl(mrb);
    }
    return mrb_nil_value();
}

static mrb_value MAppText(mrb_state *mrb, mrb_value self)
{
    mrb_float x, y;
    const char *text = NULL;
    mrb_int r = 255, g = 255, b = 255;
    mrb_get_args(mrb, "ffz|iii", &x, &y, &text, &r, &g, &b);
    BindApp_Text((BindApp *)Unwrap(mrb, self, &SDLStaticApp_type), (float)x, (float)y, text,
                 (Uint8)r, (Uint8)g, (Uint8)b);
    return mrb_nil_value();
}

static mrb_value MAppKeyDown(mrb_state *mrb, mrb_value self)
{
    (void)Unwrap(mrb, self, &SDLStaticApp_type);
    const char *name = NULL;
    mrb_get_args(mrb, "z", &name);
    return mrb_bool_value(BindApp_KeyDown(name));
}

static mrb_value MAppLoadTexture(mrb_state *mrb, mrb_value self)
{
    const char *path = NULL;
    mrb_get_args(mrb, "z", &path);
    BindTexture *tex =
        BindApp_LoadTexture((BindApp *)Unwrap(mrb, self, &SDLStaticApp_type), path);
    if (tex == NULL)
    {
        RaiseSdl(mrb);
    }
    return WrapChild(mrb, "Texture", &SDLStaticTexture_type, tex, self);
}

static mrb_value MAppDraw(mrb_state *mrb, mrb_value self)
{
    mrb_value tex_obj;
    mrb_float x, y;
    mrb_float w = 0, h = 0, angle = 0;
    mrb_get_args(mrb, "off|fff", &tex_obj, &x, &y, &w, &h, &angle);
    BindApp_Draw((BindApp *)Unwrap(mrb, self, &SDLStaticApp_type),
                 (BindTexture *)Unwrap(mrb, tex_obj, &SDLStaticTexture_type), (float)x, (float)y,
                 (float)w, (float)h, (double)angle);
    return mrb_nil_value();
}

static mrb_value MTexSize(mrb_state *mrb, mrb_value self)
{
    BindTexture *tex = (BindTexture *)Unwrap(mrb, self, &SDLStaticTexture_type);
    mrb_value pair = mrb_ary_new_capa(mrb, 2);
    mrb_ary_push(mrb, pair, mrb_float_value(mrb, tex->w));
    mrb_ary_push(mrb, pair, mrb_float_value(mrb, tex->h));
    return pair;
}

/* ------------------------------------------------------------ audio ----- */

static mrb_value MOpenAudio(mrb_state *mrb, mrb_value self)
{
    (void)self;
    BindAudio *audio = BindAudio_Open();
    if (audio == NULL)
    {
        RaiseSdl(mrb);
    }
    return WrapChild(mrb, "Audio", &SDLStaticAudio_type, audio, mrb_nil_value());
}

static mrb_value MAudioLoad(mrb_state *mrb, mrb_value self)
{
    const char *path = NULL;
    mrb_get_args(mrb, "z", &path);
    BindSound *sound = BindAudio_Load((BindAudio *)Unwrap(mrb, self, &SDLStaticAudio_type), path);
    if (sound == NULL)
    {
        RaiseSdl(mrb);
    }
    return WrapChild(mrb, "Sound", &SDLStaticSound_type, sound, self);
}

static mrb_value MAudioPlay(mrb_state *mrb, mrb_value self)
{
    mrb_value sound_obj;
    mrb_int loops = 0;
    mrb_get_args(mrb, "o|i", &sound_obj, &loops);
    BindTrack *track = BindAudio_Play((BindAudio *)Unwrap(mrb, self, &SDLStaticAudio_type),
                                      (BindSound *)Unwrap(mrb, sound_obj, &SDLStaticSound_type),
                                      (int)loops);
    if (track == NULL)
    {
        RaiseSdl(mrb);
    }
    return WrapChild(mrb, "Track", &SDLStaticTrack_type, track, self);
}

static mrb_value MTrackStop(mrb_state *mrb, mrb_value self)
{
    BindTrack_Stop((BindTrack *)Unwrap(mrb, self, &SDLStaticTrack_type));
    return mrb_nil_value();
}

static mrb_value MTrackGain(mrb_state *mrb, mrb_value self)
{
    mrb_float gain;
    mrb_get_args(mrb, "f", &gain);
    BindTrack_SetGain((BindTrack *)Unwrap(mrb, self, &SDLStaticTrack_type), (float)gain);
    return mrb_nil_value();
}

/* ---------------------------------------------------------- physics ----- */

static mrb_value MWorldNew(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_float gx = 0, gy = -10;
    mrb_get_args(mrb, "|ff", &gx, &gy);
    BindWorld *world = BindWorld_Create((float)gx, (float)gy);
    if (world == NULL)
    {
        RaiseSdl(mrb);
    }
    return WrapChild(mrb, "World", &SDLStaticWorld_type, world, mrb_nil_value());
}

static mrb_value MWorldStep(mrb_state *mrb, mrb_value self)
{
    mrb_float dt = 1.0 / 60.0;
    mrb_get_args(mrb, "|f", &dt);
    if (!BindWorld_Step((BindWorld *)Unwrap(mrb, self, &SDLStaticWorld_type), (float)dt))
    {
        RaiseSdl(mrb);
    }
    return mrb_nil_value();
}

static mrb_value MWorldBox(mrb_state *mrb, mrb_value self)
{
    mrb_float x, y, hw, hh;
    mrb_bool dynamic = FALSE;
    mrb_get_args(mrb, "ffff|b", &x, &y, &hw, &hh, &dynamic);
    BindBody *body = BindWorld_AddBox((BindWorld *)Unwrap(mrb, self, &SDLStaticWorld_type),
                                      (float)x, (float)y, (float)hw, (float)hh, dynamic);
    if (body == NULL)
    {
        RaiseSdl(mrb);
    }
    return WrapChild(mrb, "Body", &SDLStaticBody_type, body, self);
}

static mrb_value MWorldCircle(mrb_state *mrb, mrb_value self)
{
    mrb_float x, y, radius;
    mrb_bool dynamic = FALSE;
    mrb_get_args(mrb, "fff|b", &x, &y, &radius, &dynamic);
    BindBody *body = BindWorld_AddCircle((BindWorld *)Unwrap(mrb, self, &SDLStaticWorld_type),
                                         (float)x, (float)y, (float)radius, dynamic);
    if (body == NULL)
    {
        RaiseSdl(mrb);
    }
    return WrapChild(mrb, "Body", &SDLStaticBody_type, body, self);
}

static mrb_value MBodyPosition(mrb_state *mrb, mrb_value self)
{
    float x = 0, y = 0;
    if (!BindBody_Position((BindBody *)Unwrap(mrb, self, &SDLStaticBody_type), &x, &y))
    {
        RaiseSdl(mrb);
    }
    mrb_value pair = mrb_ary_new_capa(mrb, 2);
    mrb_ary_push(mrb, pair, mrb_float_value(mrb, x));
    mrb_ary_push(mrb, pair, mrb_float_value(mrb, y));
    return pair;
}

static mrb_value MBodyAngle(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb,
                           BindBody_Angle((BindBody *)Unwrap(mrb, self, &SDLStaticBody_type)));
}

static mrb_value MBodyVelocity(mrb_state *mrb, mrb_value self)
{
    mrb_float vx, vy;
    mrb_get_args(mrb, "ff", &vx, &vy);
    if (!BindBody_SetVelocity((BindBody *)Unwrap(mrb, self, &SDLStaticBody_type), (float)vx,
                              (float)vy))
    {
        RaiseSdl(mrb);
    }
    return mrb_nil_value();
}

static mrb_value MBodyImpulse(mrb_state *mrb, mrb_value self)
{
    mrb_float ix, iy;
    mrb_get_args(mrb, "ff", &ix, &iy);
    if (!BindBody_ApplyImpulse((BindBody *)Unwrap(mrb, self, &SDLStaticBody_type), (float)ix,
                               (float)iy))
    {
        RaiseSdl(mrb);
    }
    return mrb_nil_value();
}

/* ----------------------------------------------------- vfs and utils ---- */

static mrb_value MMount(mrb_state *mrb, mrb_value self)
{
    (void)self;
    const char *path = NULL;
    const char *mount = NULL;
    mrb_get_args(mrb, "z|z!", &path, &mount);
    if (!PHYSFS_isInit())
    {
        PHYSFS_init(NULL);
    }
    if (!PHYSFS_mount(path, mount, 1))
    {
        mrb_raise(mrb, E_RUNTIME_ERROR, "mount failed");
    }
    return mrb_nil_value();
}

static mrb_value MMountEncrypted(mrb_state *mrb, mrb_value self)
{
    (void)self;
    const char *path = NULL;
    const char *password = NULL;
    const char *mount = NULL;
    mrb_get_args(mrb, "zz|z!", &path, &password, &mount);
    if (!PHYSFS_isInit())
    {
        PHYSFS_init(NULL);
    }
    if (!SDLStatic_MountEncryptedArchiveFile(path, password, mount))
    {
        RaiseSdl(mrb);
    }
    return mrb_nil_value();
}

static mrb_value MReadFile(mrb_state *mrb, mrb_value self)
{
    (void)self;
    const char *path = NULL;
    mrb_get_args(mrb, "z", &path);
    int size = 0;
    unsigned char *data = SDLStatic_LoadVFSFile(path, &size);
    if (data == NULL)
    {
        RaiseSdl(mrb);
    }
    mrb_value str = mrb_str_new(mrb, (const char *)data, (size_t)size);
    SDL_free(data);
    return str;
}

static mrb_value MTicks(mrb_state *mrb, mrb_value self)
{
    (void)self;
    return mrb_int_value(mrb, (mrb_int)SDL_GetTicks());
}

static mrb_value MDelay(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_int ms;
    mrb_get_args(mrb, "i", &ms);
    SDL_Delay((Uint32)ms);
    return mrb_nil_value();
}

static mrb_value MSha256(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_value data;
    mrb_get_args(mrb, "S", &data);
    Uint8 digest[32];
    SDLStatic_SHA256(RSTRING_PTR(data), (size_t)RSTRING_LEN(data), digest);
    char hex[65];
    for (int i = 0; i < 32; ++i)
    {
        SDL_snprintf(hex + i * 2, 3, "%02x", digest[i]);
    }
    return mrb_str_new(mrb, hex, 64);
}

static mrb_value ByteResult(mrb_state *mrb, unsigned char *out, int outSize)
{
    if (out == NULL)
    {
        RaiseSdl(mrb);
    }
    mrb_value str = mrb_str_new(mrb, (const char *)out, (size_t)outSize);
    SDL_free(out);
    return str;
}

static mrb_value MCompress(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_value data;
    mrb_get_args(mrb, "S", &data);
    int outSize = 0;
    unsigned char *out = SDLStatic_CompressData((const unsigned char *)RSTRING_PTR(data),
                                             (int)RSTRING_LEN(data), &outSize);
    return ByteResult(mrb, out, outSize);
}

static mrb_value MDecompress(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_value data;
    mrb_get_args(mrb, "S", &data);
    int outSize = 0;
    unsigned char *out = SDLStatic_DecompressData((const unsigned char *)RSTRING_PTR(data),
                                               (int)RSTRING_LEN(data), &outSize);
    return ByteResult(mrb, out, outSize);
}

static mrb_value MEncrypt(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_value data;
    const char *password = NULL;
    mrb_get_args(mrb, "Sz", &data, &password);
    int outSize = 0;
    unsigned char *out = SDLStatic_EncryptData((const unsigned char *)RSTRING_PTR(data),
                                            (int)RSTRING_LEN(data), password, &outSize);
    return ByteResult(mrb, out, outSize);
}

static mrb_value MDecrypt(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_value data;
    const char *password = NULL;
    mrb_get_args(mrb, "Sz", &data, &password);
    int outSize = 0;
    unsigned char *out = SDLStatic_DecryptData((const unsigned char *)RSTRING_PTR(data),
                                            (int)RSTRING_LEN(data), password, &outSize);
    return ByteResult(mrb, out, outSize);
}

static mrb_value MB64Encode(mrb_state *mrb, mrb_value self)
{
    (void)self;
    mrb_value data;
    mrb_get_args(mrb, "S", &data);
    int outSize = 0;
    char *out = SDLStatic_EncodeDataBase64((const unsigned char *)RSTRING_PTR(data),
                                           (int)RSTRING_LEN(data), &outSize);
    if (out == NULL)
    {
        RaiseSdl(mrb);
    }
    mrb_value str = mrb_str_new(mrb, out, (size_t)outSize);
    SDL_free(out);
    return str;
}

static mrb_value MB64Decode(mrb_state *mrb, mrb_value self)
{
    (void)self;
    const char *text = NULL;
    mrb_get_args(mrb, "z", &text);
    int outSize = 0;
    unsigned char *out = SDLStatic_DecodeDataBase64(text, &outSize);
    return ByteResult(mrb, out, outSize);
}

/* ------------------------------------------------------------ open ------ */

bool SDLStatic_OpenRubyBindings(mrb_state *mrb)
{
    if (mrb == NULL)
    {
        return SDL_InvalidParamError("mrb");
    }
    struct RClass *module = mrb_define_module(mrb, "SDLStatic");

    struct RClass *app = mrb_define_class_under(mrb, module, "App", mrb->object_class);
    MRB_SET_INSTANCE_TT(app, MRB_TT_CDATA);
    mrb_define_method(mrb, app, "clear", MAppClear, MRB_ARGS_REQ(3));
    mrb_define_method(mrb, app, "present", MAppPresent, MRB_ARGS_NONE());
    mrb_define_method(mrb, app, "poll", MAppPoll, MRB_ARGS_NONE());
    mrb_define_method(mrb, app, "rect", MAppRect, MRB_ARGS_ARG(7, 1));
    mrb_define_method(mrb, app, "circle", MAppCircle, MRB_ARGS_ARG(6, 1));
    mrb_define_method(mrb, app, "line", MAppLine, MRB_ARGS_ARG(7, 1));
    mrb_define_method(mrb, app, "text", MAppText, MRB_ARGS_ARG(3, 3));
    mrb_define_method(mrb, app, "key_down?", MAppKeyDown, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, app, "load_texture", MAppLoadTexture, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, app, "draw", MAppDraw, MRB_ARGS_ARG(3, 3));

    struct RClass *tex = mrb_define_class_under(mrb, module, "Texture", mrb->object_class);
    MRB_SET_INSTANCE_TT(tex, MRB_TT_CDATA);
    mrb_define_method(mrb, tex, "size", MTexSize, MRB_ARGS_NONE());

    struct RClass *audio = mrb_define_class_under(mrb, module, "Audio", mrb->object_class);
    MRB_SET_INSTANCE_TT(audio, MRB_TT_CDATA);
    mrb_define_method(mrb, audio, "load", MAudioLoad, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, audio, "play", MAudioPlay, MRB_ARGS_ARG(1, 1));

    struct RClass *sound = mrb_define_class_under(mrb, module, "Sound", mrb->object_class);
    MRB_SET_INSTANCE_TT(sound, MRB_TT_CDATA);
    (void)sound;

    struct RClass *track = mrb_define_class_under(mrb, module, "Track", mrb->object_class);
    MRB_SET_INSTANCE_TT(track, MRB_TT_CDATA);
    mrb_define_method(mrb, track, "stop", MTrackStop, MRB_ARGS_NONE());
    mrb_define_method(mrb, track, "gain", MTrackGain, MRB_ARGS_REQ(1));

    struct RClass *world = mrb_define_class_under(mrb, module, "World", mrb->object_class);
    MRB_SET_INSTANCE_TT(world, MRB_TT_CDATA);
    mrb_define_method(mrb, world, "step", MWorldStep, MRB_ARGS_OPT(1));
    mrb_define_method(mrb, world, "box", MWorldBox, MRB_ARGS_ARG(4, 1));
    mrb_define_method(mrb, world, "circle", MWorldCircle, MRB_ARGS_ARG(3, 1));

    struct RClass *body = mrb_define_class_under(mrb, module, "Body", mrb->object_class);
    MRB_SET_INSTANCE_TT(body, MRB_TT_CDATA);
    mrb_define_method(mrb, body, "position", MBodyPosition, MRB_ARGS_NONE());
    mrb_define_method(mrb, body, "angle", MBodyAngle, MRB_ARGS_NONE());
    mrb_define_method(mrb, body, "velocity", MBodyVelocity, MRB_ARGS_REQ(2));
    mrb_define_method(mrb, body, "impulse", MBodyImpulse, MRB_ARGS_REQ(2));

    mrb_define_module_function(mrb, module, "window", MWindow, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, module, "open_audio", MOpenAudio, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, module, "world", MWorldNew, MRB_ARGS_OPT(2));
    mrb_define_module_function(mrb, module, "mount", MMount, MRB_ARGS_ARG(1, 1));
    mrb_define_module_function(mrb, module, "mount_encrypted", MMountEncrypted,
                               MRB_ARGS_ARG(2, 1));
    mrb_define_module_function(mrb, module, "read_file", MReadFile, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, module, "ticks", MTicks, MRB_ARGS_NONE());
    mrb_define_module_function(mrb, module, "delay", MDelay, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, module, "sha256", MSha256, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, module, "compress", MCompress, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, module, "decompress", MDecompress, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, module, "encrypt", MEncrypt, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, module, "decrypt", MDecrypt, MRB_ARGS_REQ(2));
    mrb_define_module_function(mrb, module, "b64encode", MB64Encode, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, module, "b64decode", MB64Decode, MRB_ARGS_REQ(1));
    return true;
}
