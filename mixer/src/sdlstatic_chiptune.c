/*
 * sdlstatic_chiptune.c — 8-bit era synthesis for SDLStatic::Mixer.
 *
 * Original SDLStatic code (zlib). Renders deterministic mono F32 PCM at
 * 44100 Hz offline and wraps it via MIX_LoadRawAudio. See
 * SDLStatic/chiptune.h for the public API and the MML dialect.
 */
#include <SDLStatic/chiptune.h>

#define CHIP_RATE 44100
#define CHIP_MAX_SECONDS 600 /* refuse absurd allocations (~100 MB) */
#define CHIP_DECLICK_MS 2
#define CHIP_MML_MAX_CHANNELS 8
/* Per-voice headroom so 4+ simultaneous channels don't clip. */
#define CHIP_VOICE_AMP 0.22f

typedef struct ChipVoice
{
    SDLStatic_ChipWave wave;
    double phase;      /* waveform phase, [0,1) */
    Uint32 lfsr;       /* noise shift register state */
    float noise_level; /* current noise output sample */
} ChipVoice;

static void ChipVoice_Init(ChipVoice *v, SDLStatic_ChipWave wave)
{
    v->wave = wave;
    v->phase = 0.0;
    v->lfsr = 0x4a1u; /* fixed seed: determinism is part of the contract */
    v->noise_level = 1.0f;
}

static float ChipVoice_Step(ChipVoice *v, float freq_hz)
{
    float out = 0.0f;
    switch (v->wave)
    {
    case SDLSTATIC_CHIP_SQUARE_125:
        out = (v->phase < 0.125) ? 1.0f : -1.0f;
        break;
    case SDLSTATIC_CHIP_SQUARE_25:
        out = (v->phase < 0.25) ? 1.0f : -1.0f;
        break;
    case SDLSTATIC_CHIP_SQUARE_50:
        out = (v->phase < 0.5) ? 1.0f : -1.0f;
        break;
    case SDLSTATIC_CHIP_TRIANGLE: {
        /* 32-step / 16-level staircase, like the NES triangle channel. */
        const int step = (int)(v->phase * 32.0);
        const int level = (step < 16) ? step : (31 - step);
        out = ((float)level / 7.5f) - 1.0f;
        break;
    }
    case SDLSTATIC_CHIP_SAW:
        out = (float)(v->phase * 2.0 - 1.0);
        break;
    case SDLSTATIC_CHIP_NOISE:
    case SDLSTATIC_CHIP_NOISE_METALLIC:
        out = v->noise_level;
        break;
    }

    /* Noise clocks its LFSR well above the nominal pitch so note choice
     * changes brightness, matching how the NES noise channel feels. */
    const double incr = (v->wave >= SDLSTATIC_CHIP_NOISE)
                            ? ((double)freq_hz * 16.0 / CHIP_RATE)
                            : ((double)freq_hz / CHIP_RATE);
    v->phase += incr;
    while (v->phase >= 1.0)
    {
        v->phase -= 1.0;
        if (v->wave >= SDLSTATIC_CHIP_NOISE)
        {
            const Uint32 tap = (v->wave == SDLSTATIC_CHIP_NOISE_METALLIC) ? 6u : 1u;
            const Uint32 feedback = (v->lfsr ^ (v->lfsr >> tap)) & 1u;
            v->lfsr = (v->lfsr >> 1) | (feedback << 14);
            v->noise_level = (v->lfsr & 1u) ? 1.0f : -1.0f;
        }
    }
    return out;
}

/*
 * Render one tone into `out` (adding, not overwriting, so channels mix by
 * rendering into the same buffer). Frames are clamped by the caller.
 */
static void RenderTone(float *out, int frames, const SDLStatic_ChipToneDesc *d, ChipVoice *voice)
{
    const float volume = SDL_clamp(d->volume, 0.0f, 1.0f) * CHIP_VOICE_AMP;
    const int attack = (int)SDL_min((Uint64)d->attack_ms * CHIP_RATE / 1000, (Uint64)frames);
    const int release = (int)SDL_min((Uint64)d->release_ms * CHIP_RATE / 1000, (Uint64)frames);
    const int declick = CHIP_DECLICK_MS * CHIP_RATE / 1000;
    const bool sweep = (d->freq_end_hz > 0.0f) && (d->freq_hz > 0.0f);
    const float sweep_ratio = sweep ? (d->freq_end_hz / d->freq_hz) : 1.0f;

    for (int i = 0; i < frames; ++i)
    {
        const float t = (float)i / (float)frames;
        float freq = d->freq_hz;
        if (sweep)
        {
            freq = d->freq_hz * SDL_powf(sweep_ratio, t);
        }
        if (d->vibrato_hz > 0.0f && d->vibrato_semitones != 0.0f)
        {
            const float lfo = SDL_sinf(2.0f * SDL_PI_F * d->vibrato_hz * ((float)i / CHIP_RATE));
            freq *= SDL_powf(2.0f, d->vibrato_semitones * lfo / 12.0f);
        }
        freq = SDL_clamp(freq, 1.0f, 20000.0f);

        float env = 1.0f;
        if (attack > 0 && i < attack)
        {
            env = (float)i / (float)attack;
        }
        if (release > 0 && i >= frames - release)
        {
            env = SDL_min(env, (float)(frames - i) / (float)release);
        }
        /* Always-on edge ramps kill clicks even with no envelope set. */
        if (i < declick)
        {
            env = SDL_min(env, (float)i / (float)declick);
        }
        if (frames - i < declick)
        {
            env = SDL_min(env, (float)(frames - i) / (float)declick);
        }

        out[i] += ChipVoice_Step(voice, freq) * volume * env;
    }
}

static MIX_Audio *LoadMono(MIX_Mixer *mixer, const float *samples, int frames)
{
    const SDL_AudioSpec spec = {SDL_AUDIO_F32, 1, CHIP_RATE};
    return MIX_LoadRawAudio(mixer, samples, (size_t)frames * sizeof(float), &spec);
}

MIX_Audio *SDLStatic_CreateChipTone(MIX_Mixer *mixer, const SDLStatic_ChipToneDesc *desc)
{
    if (desc == NULL)
    {
        SDL_SetError("chiptune: desc is NULL");
        return NULL;
    }
    if (desc->duration_ms == 0 || desc->duration_ms > CHIP_MAX_SECONDS * 1000u)
    {
        SDL_SetError("chiptune: duration_ms must be in (0, %d]", CHIP_MAX_SECONDS * 1000);
        return NULL;
    }
    if (desc->freq_hz <= 0.0f)
    {
        SDL_SetError("chiptune: freq_hz must be positive");
        return NULL;
    }
    if ((int)desc->wave < 0 || (int)desc->wave > SDLSTATIC_CHIP_NOISE_METALLIC)
    {
        SDL_SetError("chiptune: bad waveform %d", (int)desc->wave);
        return NULL;
    }

    const int frames = (int)((Uint64)desc->duration_ms * CHIP_RATE / 1000);
    float *samples = (float *)SDL_calloc((size_t)frames, sizeof(float));
    if (samples == NULL)
    {
        return NULL;
    }
    ChipVoice voice;
    ChipVoice_Init(&voice, desc->wave);
    /* Full volume for a lone tone; the MML mixer applies its own scaling. */
    SDLStatic_ChipToneDesc scaled = *desc;
    scaled.volume = SDL_clamp(desc->volume, 0.0f, 1.0f) * (1.0f / CHIP_VOICE_AMP) * 0.6f;
    RenderTone(samples, frames, &scaled, &voice);

    MIX_Audio *audio = LoadMono(mixer, samples, frames);
    SDL_free(samples);
    return audio;
}

/* ---------------------------------------------------------------- sfx --- */

typedef struct SfxStep
{
    SDLStatic_ChipToneDesc desc;
} SfxStep;

static MIX_Audio *RenderSfx(MIX_Mixer *mixer, const SfxStep *steps, int nsteps)
{
    int total = 0;
    for (int i = 0; i < nsteps; ++i)
    {
        total += (int)((Uint64)steps[i].desc.duration_ms * CHIP_RATE / 1000);
    }
    float *samples = (float *)SDL_calloc((size_t)total, sizeof(float));
    if (samples == NULL)
    {
        return NULL;
    }
    int at = 0;
    for (int i = 0; i < nsteps; ++i)
    {
        const int frames = (int)((Uint64)steps[i].desc.duration_ms * CHIP_RATE / 1000);
        ChipVoice voice;
        ChipVoice_Init(&voice, steps[i].desc.wave);
        SDLStatic_ChipToneDesc d = steps[i].desc;
        d.volume = SDL_clamp(d.volume, 0.0f, 1.0f) * (1.0f / CHIP_VOICE_AMP) * 0.6f;
        RenderTone(samples + at, frames, &d, &voice);
        at += frames;
    }
    MIX_Audio *audio = LoadMono(mixer, samples, total);
    SDL_free(samples);
    return audio;
}

MIX_Audio *SDLStatic_CreateChipSFX(MIX_Mixer *mixer, SDLStatic_ChipSFX which)
{
    switch (which)
    {
    case SDLSTATIC_SFX_COIN: {
        const SfxStep steps[] = {
            {{SDLSTATIC_CHIP_SQUARE_50, 987.77f, 0, 60, 0.9f, 0, 0, 0, 0}},
            {{SDLSTATIC_CHIP_SQUARE_50, 1318.51f, 0, 240, 0.9f, 0, 200, 0, 0}},
        };
        return RenderSfx(mixer, steps, 2);
    }
    case SDLSTATIC_SFX_LASER: {
        const SfxStep steps[] = {
            {{SDLSTATIC_CHIP_SQUARE_25, 1760.0f, 110.0f, 280, 0.9f, 0, 120, 0, 0}},
        };
        return RenderSfx(mixer, steps, 1);
    }
    case SDLSTATIC_SFX_JUMP: {
        const SfxStep steps[] = {
            {{SDLSTATIC_CHIP_SQUARE_25, 220.0f, 880.0f, 200, 0.9f, 5, 80, 0, 0}},
        };
        return RenderSfx(mixer, steps, 1);
    }
    case SDLSTATIC_SFX_EXPLOSION: {
        const SfxStep steps[] = {
            {{SDLSTATIC_CHIP_NOISE, 400.0f, 60.0f, 700, 1.0f, 2, 550, 0, 0}},
        };
        return RenderSfx(mixer, steps, 1);
    }
    case SDLSTATIC_SFX_POWERUP: {
        const SfxStep steps[] = {
            {{SDLSTATIC_CHIP_SQUARE_25, 523.25f, 0, 90, 0.9f, 0, 0, 0, 0}},
            {{SDLSTATIC_CHIP_SQUARE_25, 659.26f, 0, 90, 0.9f, 0, 0, 0, 0}},
            {{SDLSTATIC_CHIP_SQUARE_25, 783.99f, 0, 90, 0.9f, 0, 0, 0, 0}},
            {{SDLSTATIC_CHIP_SQUARE_25, 1046.5f, 0, 260, 0.9f, 0, 180, 6.0f, 0.3f}},
        };
        return RenderSfx(mixer, steps, 4);
    }
    case SDLSTATIC_SFX_HURT: {
        const SfxStep steps[] = {
            {{SDLSTATIC_CHIP_SQUARE_125, 440.0f, 110.0f, 150, 0.9f, 0, 40, 0, 0}},
            {{SDLSTATIC_CHIP_NOISE, 200.0f, 80.0f, 150, 0.8f, 0, 120, 0, 0}},
        };
        return RenderSfx(mixer, steps, 2);
    }
    }
    SDL_SetError("chiptune: bad sfx id %d", (int)which);
    return NULL;
}

/* ---------------------------------------------------------------- MML --- */

typedef struct MmlBuf
{
    float *samples;
    int frames;
    int capacity;
} MmlBuf;

static bool MmlBuf_Reserve(MmlBuf *buf, int extra)
{
    if (buf->frames + extra <= buf->capacity)
    {
        return true;
    }
    int cap = (buf->capacity > 0) ? buf->capacity : 4096;
    while (cap < buf->frames + extra)
    {
        cap *= 2;
    }
    float *grown = (float *)SDL_realloc(buf->samples, (size_t)cap * sizeof(float));
    if (grown == NULL)
    {
        return false;
    }
    SDL_memset(grown + buf->capacity, 0, (size_t)(cap - buf->capacity) * sizeof(float));
    buf->samples = grown;
    buf->capacity = cap;
    return true;
}

typedef struct MmlState
{
    int tempo;   /* BPM */
    int octave;  /* 0..8 */
    int deflen;  /* 1..64 */
    int volume;  /* 0..15 */
    SDLStatic_ChipWave wave;
    ChipVoice voice;
} MmlState;

/* Semitone offsets within an octave for A..G. */
static const int kNoteSemitone[7] = {9, 11, 0, 2, 4, 5, 7};

static int MmlParseInt(const char **p, int fallback)
{
    if (!SDL_isdigit((unsigned char)**p))
    {
        return fallback;
    }
    int value = 0;
    while (SDL_isdigit((unsigned char)**p) && value < 100000)
    {
        value = value * 10 + (**p - '0');
        (*p)++;
    }
    return value;
}

/* Note/rest length in seconds: base length, then each dot adds half more. */
static double MmlDuration(const MmlState *st, const char **p)
{
    int len = MmlParseInt(p, st->deflen);
    len = SDL_clamp(len, 1, 64);
    double beats = 4.0 / (double)len;
    double add = beats / 2.0;
    while (**p == '.')
    {
        beats += add;
        add /= 2.0;
        (*p)++;
    }
    return beats * (60.0 / (double)st->tempo);
}

static bool MmlChannel(const char *src, const char *end, int chan, MmlBuf *buf)
{
    MmlState st = {120, 4, 4, 10, SDLSTATIC_CHIP_SQUARE_50, {0}};
    ChipVoice_Init(&st.voice, st.wave);

    const char *p = src;
    while (p < end)
    {
        if (SDL_isspace((unsigned char)*p))
        {
            p++;
            continue;
        }
        const char c = (char)SDL_toupper((unsigned char)*p);
        const int pos = (int)(p - src);
        p++;
        if (c == 'T')
        {
            const int tempo = MmlParseInt(&p, st.tempo);
            st.tempo = SDL_clamp(tempo, 20, 600);
        }
        else if (c == 'O')
        {
            const int octave = MmlParseInt(&p, st.octave);
            st.octave = SDL_clamp(octave, 0, 8);
        }
        else if (c == '<')
        {
            st.octave = SDL_max(st.octave - 1, 0);
        }
        else if (c == '>')
        {
            st.octave = SDL_min(st.octave + 1, 8);
        }
        else if (c == 'L')
        {
            const int deflen = MmlParseInt(&p, st.deflen);
            st.deflen = SDL_clamp(deflen, 1, 64);
        }
        else if (c == 'V')
        {
            const int volume = MmlParseInt(&p, st.volume);
            st.volume = SDL_clamp(volume, 0, 15);
        }
        else if (c == 'W')
        {
            const int w = MmlParseInt(&p, (int)st.wave);
            if (w < 0 || w > (int)SDLSTATIC_CHIP_NOISE_METALLIC)
            {
                SDL_SetError("chiptune MML: bad waveform W%d (channel %d, pos %d)", w, chan, pos);
                return false;
            }
            st.wave = (SDLStatic_ChipWave)w;
            ChipVoice_Init(&st.voice, st.wave);
        }
        else if (c == 'R')
        {
            const double seconds = MmlDuration(&st, &p);
            const int frames = (int)(seconds * CHIP_RATE);
            if (!MmlBuf_Reserve(buf, frames))
            {
                return false;
            }
            buf->frames += frames; /* buffer is zeroed: rest = silence */
        }
        else if (c >= 'A' && c <= 'G')
        {
            int semitone = kNoteSemitone[c - 'A'];
            if (p < end && (*p == '#' || *p == '+'))
            {
                semitone++;
                p++;
            }
            else if (p < end && *p == '-')
            {
                semitone--;
                p++;
            }
            const double seconds = MmlDuration(&st, &p);
            const int frames = (int)(seconds * CHIP_RATE);
            if ((Uint64)buf->frames + (Uint64)frames > (Uint64)CHIP_MAX_SECONDS * CHIP_RATE)
            {
                SDL_SetError("chiptune MML: tune exceeds %d seconds", CHIP_MAX_SECONDS);
                return false;
            }
            if (!MmlBuf_Reserve(buf, frames))
            {
                return false;
            }
            const int midi = (st.octave + 1) * 12 + semitone;
            SDLStatic_ChipToneDesc d = {0};
            d.wave = st.wave;
            d.freq_hz = 440.0f * SDL_powf(2.0f, (float)(midi - 69) / 12.0f);
            d.volume = (float)st.volume / 15.0f;
            /* Gate at 15/16 of the slot for that clipped chip articulation. */
            const int gate = frames - (frames / 16);
            RenderTone(buf->samples + buf->frames, gate, &d, &st.voice);
            buf->frames += frames;
        }
        else
        {
            SDL_SetError("chiptune MML: unexpected character '%c' (channel %d, pos %d)", c, chan,
                         pos);
            return false;
        }
    }
    return true;
}

MIX_Audio *SDLStatic_CreateChipTune(MIX_Mixer *mixer, const char *mml)
{
    if (mml == NULL || *mml == '\0')
    {
        SDL_SetError("chiptune MML: empty program");
        return NULL;
    }

    MmlBuf channels[CHIP_MML_MAX_CHANNELS] = {0};
    int nchan = 0;
    bool ok = true;
    const char *cursor = mml;
    while (ok)
    {
        if (nchan >= CHIP_MML_MAX_CHANNELS)
        {
            SDL_SetError("chiptune MML: more than %d channels", CHIP_MML_MAX_CHANNELS);
            ok = false;
            break;
        }
        const char *sep = SDL_strchr(cursor, ';');
        const char *chan_end = (sep != NULL) ? sep : cursor + SDL_strlen(cursor);
        ok = MmlChannel(cursor, chan_end, nchan, &channels[nchan]);
        nchan++;
        if (!ok || sep == NULL)
        {
            break;
        }
        cursor = sep + 1;
    }

    MIX_Audio *audio = NULL;
    if (ok)
    {
        int total = 0;
        for (int i = 0; i < nchan; ++i)
        {
            total = SDL_max(total, channels[i].frames);
        }
        if (total == 0)
        {
            SDL_SetError("chiptune MML: program produced no audio");
        }
        else
        {
            float *mixdown = (float *)SDL_calloc((size_t)total, sizeof(float));
            if (mixdown != NULL)
            {
                for (int i = 0; i < nchan; ++i)
                {
                    for (int f = 0; f < channels[i].frames; ++f)
                    {
                        mixdown[f] += channels[i].samples[f];
                    }
                }
                for (int f = 0; f < total; ++f)
                {
                    mixdown[f] = SDL_clamp(mixdown[f], -1.0f, 1.0f);
                }
                audio = LoadMono(mixer, mixdown, total);
                SDL_free(mixdown);
            }
        }
    }
    for (int i = 0; i < nchan; ++i)
    {
        SDL_free(channels[i].samples);
    }
    return audio;
}
