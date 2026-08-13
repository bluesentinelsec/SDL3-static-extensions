# SDLStatic::Mixer

A static-link-first port of [SDL3_mixer](https://github.com/libsdl-org/SDL_mixer)
3.2.4 (the redesigned `MIX_*` API). No shared codec libraries — every enabled
decoder is vendored source, compiled into `libSDLStatic_Mixer.a`.

Provenance and the full delete list: [`deps/SDL3_mixer.md`](../deps/SDL3_mixer.md).

## Format support

| Format | Status | Backend |
|--------|--------|---------|
| WAV | ✅ | built-in |
| OGG Vorbis | ✅ | stb_vorbis (vendored) |
| MP3 | ✅ | dr_mp3 (vendored) |
| FLAC | ✅ | dr_flac (vendored) |
| AIFF | ✅ | built-in |
| AU | ✅ | built-in |
| VOC | ✅ | built-in |
| RAW PCM | ✅ | built-in |
| Sine wave generator | ✅ | built-in |
| MIDI | ⚠️ | TiMidity (vendored, statically linked) — needs GUS patch data on disk at runtime; without it, loads fail cleanly |
| Opus | ❌ removed | required libopus/libopusfile |
| WavPack | ❌ removed | required libwavpack |
| Tracker (MOD/XM/IT/S3M) | ❌ removed | required libxmp |
| Game-console music (GME) | ❌ removed | required libgme |
| SoundFont MIDI | ❌ removed | required FluidSynth (TiMidity covers MIDI) |

Removed formats are gone from the build entirely (no stubs): the decoder
table is compile-time gated, so unsupported files fail at `MIX_LoadAudio`
with a clean error, and nothing references the deleted code.

## Usage

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Mixer)
```

```c
#include <SDL3_mixer/SDL_mixer.h>

MIX_Init();
MIX_Mixer *mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
MIX_Audio *music = MIX_LoadAudio(mixer, "music_loop.ogg", false);
MIX_Track *track = MIX_CreateTrack(mixer);
MIX_SetTrackAudio(track, music);
MIX_PlayTrack(track, 0);
```

## Chiptune synthesis (SDLStatic extension)

Original code (not vendored SDL_mixer): `<SDLStatic/chiptune.h>` adds 8-bit
era synthesis with high-level entry points, rendered offline into normal
`MIX_Audio` objects — deterministic, loopable, zero runtime cost beyond
ordinary playback.

- `SDLStatic_CreateChipTone` — one voice: square (12.5/25/50% duty), 16-step
  NES-style triangle, saw, or LFSR noise (normal + metallic short-loop), with
  pitch sweep, vibrato, and attack/release envelope.
- `SDLStatic_CreateChipSFX` — canned effects: coin, laser, jump, explosion,
  powerup, hurt.
- `SDLStatic_CreateChipTune` — compiles an MML string (the 8-bit BASIC
  `PLAY` dialect: notes `A-G#`, octaves `O`/`<`/`>`, lengths `L`/dots, tempo
  `T`, volume `V`, waveform `W`, up to 8 `;`-separated channels) into a
  finished multi-channel tune:

```c
MIX_Audio *tune = SDLStatic_CreateChipTune(mixer,
    "T140 W2 O5 L8 C E G >C< G E C4 ;"   /* pulse lead   */
    "T140 W1 O4 L8 E G B >E< B G E4 ;"   /* pulse harmony */
    "T140 W3 O2 L4 C G C G");            /* triangle bass */
```

Tests (`tests/mixer/`) decode a synthesized corpus in every enabled format,
assert real signal energy from headless `MIX_Generate` playback, fuzz
malformed inputs under ASan+UBSan, and run a link audit proving the test
binary depends only on OS-built-in shared libraries.
