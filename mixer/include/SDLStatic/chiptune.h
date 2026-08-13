/**
 * @file chiptune.h
 * @brief 8-bit era music/sfx synthesis on top of SDLStatic::Mixer.
 *
 * Original SDLStatic code (zlib, like the rest of this repo) — NOT part of
 * upstream SDL_mixer. Everything renders offline to PCM and is returned as a
 * regular MIX_Audio, so playback, looping, gain, etc. all go through the
 * normal MIX_Track APIs. Rendering is fully deterministic: the same inputs
 * always produce bit-identical audio (the noise generator is a seeded LFSR).
 *
 * Three levels of API, lowest to highest:
 *
 *  1. SDLStatic_CreateChipTone()  — one waveform "voice": square (three duty
 *     cycles), 16-step triangle, saw, or NES-style LFSR noise, with optional
 *     pitch sweep, vibrato, and attack/release envelope.
 *  2. SDLStatic_CreateChipSFX()   — canned game sound effects (coin, laser,
 *     jump, explosion, powerup, hurt).
 *  3. SDLStatic_CreateChipTune()  — compile a Music Macro Language (MML)
 *     string, the dialect of 8-bit BASIC `PLAY` statements, into a finished
 *     multi-channel tune.
 *
 * MML dialect (case-insensitive, whitespace ignored):
 *
 *   A-G[#+-][n][.]  play a note; `#`/`+` sharp, `-` flat; `n` = length
 *                   (1=whole, 4=quarter, ... up to 64), dots extend by half
 *   R[n][.]         rest
 *   On              set octave 0-8 (default 4; O4 A = 440 Hz)
 *   < >             octave down / up
 *   Ln              default note length (default 4)
 *   Tn              tempo in BPM, 20-600 (default 120)
 *   Vn              channel volume 0-15 (default 10)
 *   Wn              waveform 0-7, see SDLStatic_ChipWave (default 2 = square)
 *   Sn              envelope shape: 0 = flat sustain (default), 1 = decay
 *                   across the note, 2 = short percussive pluck — use S2 on
 *                   a noise channel for drums
 *   ;               start the next channel (up to 8; mixed like NES voices)
 *
 * Example — the classic NES lineup: pulse lead, pulse counterpoint,
 * triangle bass, noise percussion:
 *
 *   MIX_Audio *tune = SDLStatic_CreateChipTune(mixer,
 *       "T140 W1 O5 L8 C E G >C< G E C4 ;"
 *       "T140 W2 O4 L8 E G B >E< B G E4 ;"
 *       "T140 W3 O2 L4 C G E G ;"
 *       "T140 W5 S2 L8 O3 C O6 C O3 C O6 C O3 C O6 C O3 C O6 C");
 *
 * The result loops seamlessly if the channels line up on the same total
 * length. On parse errors these functions return NULL with SDL_GetError()
 * describing the offending character and position.
 */
#ifndef SDLSTATIC_CHIPTUNE_H
#define SDLSTATIC_CHIPTUNE_H

#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Waveforms of the 8-bit era. Values are stable (MML `Wn` uses them). */
typedef enum SDLStatic_ChipWave
{
    SDLSTATIC_CHIP_SQUARE_125 = 0, /**< square, 12.5% duty (thin/nasal) */
    SDLSTATIC_CHIP_SQUARE_25 = 1,  /**< square, 25% duty (classic lead) */
    SDLSTATIC_CHIP_SQUARE_50 = 2,  /**< square, 50% duty (hollow/full) */
    SDLSTATIC_CHIP_TRIANGLE = 3,   /**< 16-step quantized triangle (NES bass) */
    SDLSTATIC_CHIP_SAW = 4,        /**< sawtooth */
    SDLSTATIC_CHIP_NOISE = 5,      /**< 15-bit LFSR noise (drums/explosions) */
    SDLSTATIC_CHIP_NOISE_METALLIC = 6, /**< short-loop LFSR (metallic buzz) */
    SDLSTATIC_CHIP_SINE = 7            /**< pure sine (not on real hardware,
                                            but a useful soft voice) */
} SDLStatic_ChipWave;

/** One synthesized voice. Zero-init then set what you need. */
typedef struct SDLStatic_ChipToneDesc
{
    SDLStatic_ChipWave wave; /**< waveform */
    float freq_hz;           /**< pitch; for noise, the LFSR clock feel */
    float freq_end_hz;       /**< >0: exponential sweep to this pitch */
    Uint32 duration_ms;      /**< total length, must be > 0 */
    float volume;            /**< 0..1 */
    Uint32 attack_ms;        /**< linear fade-in */
    Uint32 release_ms;       /**< linear fade-out at the end */
    float vibrato_hz;        /**< vibrato rate; 0 = none */
    float vibrato_semitones; /**< vibrato depth in semitones */
} SDLStatic_ChipToneDesc;

/** Canned sound effects. */
typedef enum SDLStatic_ChipSFX
{
    SDLSTATIC_SFX_COIN = 0,
    SDLSTATIC_SFX_LASER,
    SDLSTATIC_SFX_JUMP,
    SDLSTATIC_SFX_EXPLOSION,
    SDLSTATIC_SFX_POWERUP,
    SDLSTATIC_SFX_HURT
} SDLStatic_ChipSFX;

/**
 * Render a single tone/voice to a MIX_Audio.
 * \returns a new MIX_Audio (destroy with MIX_DestroyAudio), or NULL on error.
 */
extern MIX_Audio *SDLStatic_CreateChipTone(MIX_Mixer *mixer, const SDLStatic_ChipToneDesc *desc);

/**
 * Render a canned game sound effect.
 * \returns a new MIX_Audio, or NULL on error.
 */
extern MIX_Audio *SDLStatic_CreateChipSFX(MIX_Mixer *mixer, SDLStatic_ChipSFX which);

/**
 * Compile an MML string (dialect documented above) into a MIX_Audio.
 * \returns a new MIX_Audio, or NULL on parse error (see SDL_GetError()).
 */
extern MIX_Audio *SDLStatic_CreateChipTune(MIX_Mixer *mixer, const char *mml);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_CHIPTUNE_H */
