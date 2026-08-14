---
title: Mixer
description: "Audio for games: SDL3_mixer with vendored codecs, statically linked MIDI, and an original chiptune synthesis layer."
---

# Mixer — `SDLStatic::Mixer`

A static-link-first port of SDL3_mixer 3.2.4 (the redesigned `MIX_*`
API). Every enabled decoder is vendored source compiled into the static
library — no shared codec libraries, ever.

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Mixer)
```

## Format support

| Format | Status | Backend |
|--------|--------|---------|
| WAV / AIFF / AU / VOC / RAW | ✅ | built-in |
| OGG Vorbis | ✅ | stb_vorbis (vendored) |
| MP3 | ✅ | dr_mp3 (vendored) |
| FLAC | ✅ | dr_flac (vendored) |
| MIDI | ✅ | TiMidity (vendored) + generated GM patch set |
| Sine generator | ✅ | built-in |
| Opus / WavPack / tracker / GME | ❌ removed | required shared libraries — deleted, not stubbed |

Removed formats are gone from the decoder table at compile time:
unsupported files fail at `MIX_LoadAudio` with a clean error.

## Playing audio

```c
#include <SDL3_mixer/SDL_mixer.h>

MIX_Init();
MIX_Mixer *mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
MIX_Audio *music = MIX_LoadAudio(mixer, "music_loop.ogg", false);
MIX_Track *track = MIX_CreateTrack(mixer);
MIX_SetTrackAudio(track, music);
MIX_PlayTrack(track, 0);
```

Assets mounted in the [VFS](vfs.html) stream directly:
`MIX_LoadAudio_IO(mixer, SDLStatic_OpenVFSRead("/assets/bgm.ogg"), false, true)`.

## MIDI

TiMidity is compiled in; point `TIMIDITY_CFG` at the generated
General-MIDI patch set shipped in `mixer/gm-patches/` and `.mid` files
load like any other format. Without patches configured, loads fail
cleanly rather than playing silence.

## Chiptune synthesis (original extension)

`<SDLStatic/chiptune.h>` renders 8-bit-era audio offline into ordinary
`MIX_Audio` objects — deterministic, loopable, zero extra runtime cost:

- **`SDLStatic_CreateChipTone`** — one voice: square (12.5/25/50% duty),
  NES-style 16-step triangle, saw, LFSR noise (normal + metallic), or
  sine, with pitch sweep, vibrato, and attack/release envelope.
- **`SDLStatic_CreateChipSFX`** — canned effects: coin, laser, jump,
  explosion, powerup, hurt.
- **`SDLStatic_CreateChipTune`** — compiles an MML string (the 8-bit
  BASIC `PLAY` dialect) into a finished multi-channel tune:

```c
MIX_Audio *tune = SDLStatic_CreateChipTune(mixer,
    "T140 W1 O5 L8 C E G >C< G E C4 ;"                        /* pulse lead    */
    "T140 W2 O4 L8 E G B >E< B G E4 ;"                        /* counterpoint  */
    "T140 W3 O2 L4 C G E G ;"                                 /* triangle bass */
    "T140 W5 S2 L8 O3 C O6 C O3 C O6 C O3 C O6 C O3 C O6 C"); /* noise drums   */
```

Up to 8 `;`-separated channels; notes `A–G#`, octaves `O`/`<`/`>`,
lengths `L` and dots, tempo `T`, volume `V`, waveform `W`, envelope `S` —
the classic NES four-voice lineup (two pulse, triangle, noise) is the
example above.

Provenance and the full delete list:
[`deps/SDL3_mixer.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/SDL3_mixer.md).
