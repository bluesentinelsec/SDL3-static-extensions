/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for SDL_mixer. */
#include "../src/gen_support_ruby.h"

#include <SDL3_mixer/SDL_mixer.h>
#include <string.h>

static void GenRead_MIX_Point3D(mrb_state *mrb, mrb_value h, MIX_Point3D *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->x = (float)SDLStaticGen_RubyFieldNum(mrb, h, "x");
    out->y = (float)SDLStaticGen_RubyFieldNum(mrb, h, "y");
    out->z = (float)SDLStaticGen_RubyFieldNum(mrb, h, "z");
}

static mrb_value GenPush_MIX_Point3D(mrb_state *mrb, const MIX_Point3D *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "x", mrb_float_value(mrb, (mrb_float)in->x));
    SDLStaticGen_RubyHashSet(mrb, h, "y", mrb_float_value(mrb, (mrb_float)in->y));
    SDLStaticGen_RubyHashSet(mrb, h, "z", mrb_float_value(mrb, (mrb_float)in->z));
    return h;
}

static void GenRead_MIX_StereoGains(mrb_state *mrb, mrb_value h, MIX_StereoGains *out)
{
    memset(out, 0, sizeof(*out));
    if (!mrb_hash_p(h)) { return; }
    out->left = (float)SDLStaticGen_RubyFieldNum(mrb, h, "left");
    out->right = (float)SDLStaticGen_RubyFieldNum(mrb, h, "right");
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

static void GenDtor_MIX_DestroyMixer(void *p)
{
    MIX_Mixer *typed = (MIX_Mixer *)p;
    MIX_DestroyMixer(typed);
}

static void GenDtor_MIX_DestroyAudio(void *p)
{
    MIX_Audio *typed = (MIX_Audio *)p;
    MIX_DestroyAudio(typed);
}

static void GenDtor_MIX_DestroyTrack(void *p)
{
    MIX_Track *typed = (MIX_Track *)p;
    MIX_DestroyTrack(typed);
}

static void GenDtor_MIX_DestroyAudioDecoder(void *p)
{
    MIX_AudioDecoder *typed = (MIX_AudioDecoder *)p;
    MIX_DestroyAudioDecoder(typed);
}

static mrb_value GenR_MIX_AudioFramesToMS(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Audio");
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint64 rv = MIX_AudioFramesToMS(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_AudioMSToFrames(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Audio");
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint64 rv = MIX_AudioMSToFrames(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_CreateAudioDecoder(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    SDL_PropertiesID a1 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    MIX_AudioDecoder * rv = MIX_CreateAudioDecoder(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "MIX_AudioDecoder", GenDtor_MIX_DestroyAudioDecoder);
    }
}

static mrb_value GenR_MIX_CreateAudioDecoder_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_IOStream *a0 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "SDL_IOStream");
    bool a1 = (bool)SDLStaticGen_RubyToBool((argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PropertiesID a2 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    MIX_AudioDecoder * rv = MIX_CreateAudioDecoder_IO(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "MIX_AudioDecoder", GenDtor_MIX_DestroyAudioDecoder);
    }
}

static mrb_value GenR_MIX_CreateGroup(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    MIX_Group * rv = MIX_CreateGroup(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Group");
    }
}

static mrb_value GenR_MIX_CreateMixer(mrb_state *mrb, mrb_value self)
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
    MIX_Mixer * rv = MIX_CreateMixer(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "MIX_Mixer", GenDtor_MIX_DestroyMixer);
    }
}

static mrb_value GenR_MIX_CreateMixerDevice(mrb_state *mrb, mrb_value self)
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
    MIX_Mixer * rv = MIX_CreateMixerDevice(a0, a1);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "MIX_Mixer", GenDtor_MIX_DestroyMixer);
    }
}

static mrb_value GenR_MIX_CreateSineWaveAudio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    Sint64 a3 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    MIX_Audio * rv = MIX_CreateSineWaveAudio(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    }
}

static mrb_value GenR_MIX_CreateTrack(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    MIX_Track * rv = MIX_CreateTrack(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "MIX_Track", GenDtor_MIX_DestroyTrack);
    }
}

static mrb_value GenR_MIX_DestroyAudio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Audio");
    MIX_DestroyAudio(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_MIX_DestroyAudioDecoder(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_AudioDecoder *a0 = (MIX_AudioDecoder *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_AudioDecoder");
    MIX_DestroyAudioDecoder(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_MIX_DestroyGroup(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Group *a0 = (MIX_Group *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Group");
    MIX_DestroyGroup(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_MIX_DestroyMixer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    MIX_DestroyMixer(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_MIX_DestroyTrack(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    MIX_DestroyTrack(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_MIX_FramesToMS(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint64 rv = MIX_FramesToMS(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_GetAudioDecoder(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = MIX_GetAudioDecoder(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_MIX_GetAudioDecoderFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_AudioDecoder *a0 = (MIX_AudioDecoder *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_AudioDecoder");
    SDL_AudioSpec out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = MIX_GetAudioDecoderFormat(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_AudioSpec(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_MIX_GetAudioDecoderProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_AudioDecoder *a0 = (MIX_AudioDecoder *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_AudioDecoder");
    SDL_PropertiesID rv = MIX_GetAudioDecoderProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_GetAudioDuration(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Audio");
    Sint64 rv = MIX_GetAudioDuration(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_GetAudioFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Audio");
    SDL_AudioSpec out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = MIX_GetAudioFormat(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_AudioSpec(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_MIX_GetAudioProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Audio *a0 = (MIX_Audio *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Audio");
    SDL_PropertiesID rv = MIX_GetAudioProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_GetGroupMixer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Group *a0 = (MIX_Group *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Group");
    MIX_Mixer * rv = MIX_GetGroupMixer(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Mixer");
    }
}

static mrb_value GenR_MIX_GetGroupProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Group *a0 = (MIX_Group *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Group");
    SDL_PropertiesID rv = MIX_GetGroupProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_GetMixerFormat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    SDL_AudioSpec out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = MIX_GetMixerFormat(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_SDL_AudioSpec(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_MIX_GetMixerFrequencyRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    float rv = MIX_GetMixerFrequencyRatio(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_MIX_GetMixerGain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    float rv = MIX_GetMixerGain(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_MIX_GetMixerProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    SDL_PropertiesID rv = MIX_GetMixerProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_GetNumAudioDecoders(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = MIX_GetNumAudioDecoders();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_GetTrack3DPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    MIX_Point3D out1;
    memset(&out1, 0, sizeof(out1));
    bool rv = MIX_GetTrack3DPosition(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_bool_value((mrb_bool)(rv != 0));
    rets[1] = GenPush_MIX_Point3D(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_MIX_GetTrackAudio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    MIX_Audio * rv = MIX_GetTrackAudio(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Audio");
    }
}

static mrb_value GenR_MIX_GetTrackAudioStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    SDL_AudioStream * rv = MIX_GetTrackAudioStream(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "SDL_AudioStream");
    }
}

static mrb_value GenR_MIX_GetTrackFadeFrames(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    Sint64 rv = MIX_GetTrackFadeFrames(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_GetTrackFrequencyRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    float rv = MIX_GetTrackFrequencyRatio(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_MIX_GetTrackGain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    float rv = MIX_GetTrackGain(a0);
    return mrb_float_value(mrb, (mrb_float)rv);
    }
}

static mrb_value GenR_MIX_GetTrackLoops(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    int rv = MIX_GetTrackLoops(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_GetTrackMixer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    MIX_Mixer * rv = MIX_GetTrackMixer(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Mixer");
    }
}

static mrb_value GenR_MIX_GetTrackPlaybackPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    Sint64 rv = MIX_GetTrackPlaybackPosition(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_GetTrackProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    SDL_PropertiesID rv = MIX_GetTrackProperties(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_GetTrackRemaining(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    Sint64 rv = MIX_GetTrackRemaining(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_Init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = MIX_Init();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_LoadAudio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    MIX_Audio * rv = MIX_LoadAudio(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    }
}

static mrb_value GenR_MIX_LoadAudioNoCopy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    MIX_Audio * rv = MIX_LoadAudioNoCopy(a0, (const void *)a1, (size_t)len1, a3);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Audio");
    }
}

static mrb_value GenR_MIX_LoadAudioWithProperties(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    SDL_PropertiesID a0 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    MIX_Audio * rv = MIX_LoadAudioWithProperties(a0);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    }
}

static mrb_value GenR_MIX_LoadAudio_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    MIX_Audio * rv = MIX_LoadAudio_IO(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    }
}

static mrb_value GenR_MIX_LoadRawAudio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    SDL_AudioSpec tmp3;
    const SDL_AudioSpec *a3 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_AudioSpec(mrb, argv[2], &tmp3);
        a3 = &tmp3;
    }
    MIX_Audio * rv = MIX_LoadRawAudio(a0, (const void *)a1, (size_t)len1, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    }
}

static mrb_value GenR_MIX_LoadRawAudioNoCopy(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    SDL_AudioSpec tmp3;
    const SDL_AudioSpec *a3 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_AudioSpec(mrb, argv[2], &tmp3);
        a3 = &tmp3;
    }
    bool a4 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    MIX_Audio * rv = MIX_LoadRawAudioNoCopy(a0, (const void *)a1, (size_t)len1, a3, a4);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "MIX_Audio");
    }
}

static mrb_value GenR_MIX_LoadRawAudio_IO(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    SDL_AudioSpec tmp2;
    const SDL_AudioSpec *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_AudioSpec(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    MIX_Audio * rv = MIX_LoadRawAudio_IO(a0, a1, a2, a3);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "MIX_Audio", GenDtor_MIX_DestroyAudio);
    }
}

static mrb_value GenR_MIX_LockMixer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    MIX_LockMixer(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_MIX_MSToFrames(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint64 rv = MIX_MSToFrames(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_PauseAllTracks(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    bool rv = MIX_PauseAllTracks(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_PauseTag(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_PauseTag(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_PauseTrack(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    bool rv = MIX_PauseTrack(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_PlayAudio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    MIX_Audio *a1 = (MIX_Audio *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "MIX_Audio");
    bool rv = MIX_PlayAudio(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_PlayTag(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PropertiesID a2 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = MIX_PlayTag(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_PlayTrack(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    SDL_PropertiesID a1 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_PlayTrack(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_Quit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Quit();
    return mrb_nil_value();
    }
}

static mrb_value GenR_MIX_ResumeAllTracks(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    bool rv = MIX_ResumeAllTracks(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_ResumeTag(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_ResumeTag(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_ResumeTrack(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    bool rv = MIX_ResumeTrack(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetMixerFrequencyRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_SetMixerFrequencyRatio(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetMixerGain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_SetMixerGain(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTagGain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    float a2 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = MIX_SetTagGain(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTrack3DPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    MIX_Point3D tmp1;
    const MIX_Point3D *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_MIX_Point3D(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = MIX_SetTrack3DPosition(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTrackAudio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    MIX_Audio *a1 = (MIX_Audio *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "MIX_Audio");
    bool rv = MIX_SetTrackAudio(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTrackAudioStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    SDL_AudioStream *a1 = (SDL_AudioStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_AudioStream");
    bool rv = MIX_SetTrackAudioStream(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTrackFrequencyRatio(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_SetTrackFrequencyRatio(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTrackGain(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    float a1 = (float)SDLStaticGen_RubyToNum(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_SetTrackGain(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTrackGroup(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    MIX_Group *a1 = (MIX_Group *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "MIX_Group");
    bool rv = MIX_SetTrackGroup(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTrackIOStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    bool a2 = (bool)SDLStaticGen_RubyToBool((argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = MIX_SetTrackIOStream(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTrackLoops(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_SetTrackLoops(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTrackPlaybackPosition(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_SetTrackPlaybackPosition(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTrackRawIOStream(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    SDL_IOStream *a1 = (SDL_IOStream *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "SDL_IOStream");
    SDL_AudioSpec tmp2;
    const SDL_AudioSpec *a2 = NULL;
    if (argc > 2 && mrb_hash_p(argv[2])) {
        GenRead_SDL_AudioSpec(mrb, argv[2], &tmp2);
        a2 = &tmp2;
    }
    bool a3 = (bool)SDLStaticGen_RubyToBool((argc > 3 ? argv[3] : mrb_nil_value()));
    bool rv = MIX_SetTrackRawIOStream(a0, a1, a2, a3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_SetTrackStereo(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    MIX_StereoGains tmp1;
    const MIX_StereoGains *a1 = NULL;
    if (argc > 1 && mrb_hash_p(argv[1])) {
        GenRead_MIX_StereoGains(mrb, argv[1], &tmp1);
        a1 = &tmp1;
    }
    bool rv = MIX_SetTrackStereo(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_StopAllTracks(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_StopAllTracks(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_StopTag(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint64 a2 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    bool rv = MIX_StopTag(a0, a1, a2);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_StopTrack(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_StopTrack(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_TagTrack(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    bool rv = MIX_TagTrack(a0, a1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_TrackFramesToMS(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint64 rv = MIX_TrackFramesToMS(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_TrackMSToFrames(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    Sint64 a1 = (Sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    Sint64 rv = MIX_TrackMSToFrames(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_MIX_TrackPaused(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    bool rv = MIX_TrackPaused(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_TrackPlaying(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    bool rv = MIX_TrackPlaying(a0);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_MIX_UnlockMixer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Mixer *a0 = (MIX_Mixer *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Mixer");
    MIX_UnlockMixer(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_MIX_UntagTrack(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    MIX_Track *a0 = (MIX_Track *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "MIX_Track");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    MIX_UntagTrack(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_MIX_Version(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = MIX_Version();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

void SDLStaticGen_OpenRuby_mix(mrb_state *mrb);
void SDLStaticGen_OpenRuby_mix(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "MIX");
    mrb_define_module_function(mrb, mod, "AudioFramesToMS", GenR_MIX_AudioFramesToMS, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "AudioMSToFrames", GenR_MIX_AudioMSToFrames, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAudioDecoder", GenR_MIX_CreateAudioDecoder, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateAudioDecoder_IO", GenR_MIX_CreateAudioDecoder_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateGroup", GenR_MIX_CreateGroup, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateMixer", GenR_MIX_CreateMixer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateMixerDevice", GenR_MIX_CreateMixerDevice, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateSineWaveAudio", GenR_MIX_CreateSineWaveAudio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateTrack", GenR_MIX_CreateTrack, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyAudio", GenR_MIX_DestroyAudio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyAudioDecoder", GenR_MIX_DestroyAudioDecoder, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyGroup", GenR_MIX_DestroyGroup, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyMixer", GenR_MIX_DestroyMixer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyTrack", GenR_MIX_DestroyTrack, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "FramesToMS", GenR_MIX_FramesToMS, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioDecoder", GenR_MIX_GetAudioDecoder, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioDecoderFormat", GenR_MIX_GetAudioDecoderFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioDecoderProperties", GenR_MIX_GetAudioDecoderProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioDuration", GenR_MIX_GetAudioDuration, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioFormat", GenR_MIX_GetAudioFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAudioProperties", GenR_MIX_GetAudioProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGroupMixer", GenR_MIX_GetGroupMixer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetGroupProperties", GenR_MIX_GetGroupProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMixerFormat", GenR_MIX_GetMixerFormat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMixerFrequencyRatio", GenR_MIX_GetMixerFrequencyRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMixerGain", GenR_MIX_GetMixerGain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetMixerProperties", GenR_MIX_GetMixerProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetNumAudioDecoders", GenR_MIX_GetNumAudioDecoders, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrack3DPosition", GenR_MIX_GetTrack3DPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrackAudio", GenR_MIX_GetTrackAudio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrackAudioStream", GenR_MIX_GetTrackAudioStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrackFadeFrames", GenR_MIX_GetTrackFadeFrames, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrackFrequencyRatio", GenR_MIX_GetTrackFrequencyRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrackGain", GenR_MIX_GetTrackGain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrackLoops", GenR_MIX_GetTrackLoops, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrackMixer", GenR_MIX_GetTrackMixer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrackPlaybackPosition", GenR_MIX_GetTrackPlaybackPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrackProperties", GenR_MIX_GetTrackProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetTrackRemaining", GenR_MIX_GetTrackRemaining, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Init", GenR_MIX_Init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadAudio", GenR_MIX_LoadAudio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadAudioNoCopy", GenR_MIX_LoadAudioNoCopy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadAudioWithProperties", GenR_MIX_LoadAudioWithProperties, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadAudio_IO", GenR_MIX_LoadAudio_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadRawAudio", GenR_MIX_LoadRawAudio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadRawAudioNoCopy", GenR_MIX_LoadRawAudioNoCopy, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LoadRawAudio_IO", GenR_MIX_LoadRawAudio_IO, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "LockMixer", GenR_MIX_LockMixer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "MSToFrames", GenR_MIX_MSToFrames, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PauseAllTracks", GenR_MIX_PauseAllTracks, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PauseTag", GenR_MIX_PauseTag, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PauseTrack", GenR_MIX_PauseTrack, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PlayAudio", GenR_MIX_PlayAudio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PlayTag", GenR_MIX_PlayTag, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "PlayTrack", GenR_MIX_PlayTrack, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Quit", GenR_MIX_Quit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResumeAllTracks", GenR_MIX_ResumeAllTracks, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResumeTag", GenR_MIX_ResumeTag, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResumeTrack", GenR_MIX_ResumeTrack, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetMixerFrequencyRatio", GenR_MIX_SetMixerFrequencyRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetMixerGain", GenR_MIX_SetMixerGain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTagGain", GenR_MIX_SetTagGain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrack3DPosition", GenR_MIX_SetTrack3DPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrackAudio", GenR_MIX_SetTrackAudio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrackAudioStream", GenR_MIX_SetTrackAudioStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrackFrequencyRatio", GenR_MIX_SetTrackFrequencyRatio, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrackGain", GenR_MIX_SetTrackGain, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrackGroup", GenR_MIX_SetTrackGroup, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrackIOStream", GenR_MIX_SetTrackIOStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrackLoops", GenR_MIX_SetTrackLoops, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrackPlaybackPosition", GenR_MIX_SetTrackPlaybackPosition, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrackRawIOStream", GenR_MIX_SetTrackRawIOStream, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SetTrackStereo", GenR_MIX_SetTrackStereo, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StopAllTracks", GenR_MIX_StopAllTracks, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StopTag", GenR_MIX_StopTag, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "StopTrack", GenR_MIX_StopTrack, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TagTrack", GenR_MIX_TagTrack, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TrackFramesToMS", GenR_MIX_TrackFramesToMS, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TrackMSToFrames", GenR_MIX_TrackMSToFrames, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TrackPaused", GenR_MIX_TrackPaused, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "TrackPlaying", GenR_MIX_TrackPlaying, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UnlockMixer", GenR_MIX_UnlockMixer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UntagTrack", GenR_MIX_UntagTrack, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Version", GenR_MIX_Version, MRB_ARGS_ANY());
}
