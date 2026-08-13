# Generated General MIDI patch set

TiMidity — the statically linked MIDI soft-synth in `SDLStatic::Mixer` —
needs GF1/GUS instrument patches at runtime to render audio. Third-party
patch collections (freepats, eawpats) carry GPL or unclear licensing, so
this set is **generated from scratch** by `scripts/gen_gus_patches.py`:
band-limited single-cycle waveforms for the melodic timbres (piano, organ,
strings, bass, flute, lead — mapped over all 128 GM programs) and
synthesized one-shots for percussion (kick, snare, hat, tom, cymbal). Fully
deterministic, zlib like the rest of the repo, ~140 KB total.

This is a lightweight chip-flavored rendition of General MIDI, not a
sampled orchestra — ideal for retro games, background tunes, and testing.
Applications wanting realism can point TiMidity at any full GUS patch set
instead.

## Using it

Set the `TIMIDITY_CFG` environment variable before `MIX_Init()`:

```c
SDL_SetEnvironmentVariable(SDL_GetEnvironment(), "TIMIDITY_CFG",
                           "path/to/gm-patches/timidity.cfg", true);
MIX_Init();
MIX_Audio *song = MIX_LoadAudio(mixer, "song.mid", false);
```

Without a config, MIDI loads fail cleanly (`MIX_LoadAudio` returns NULL) —
nothing crashes and no other formats are affected.

Regenerate with `python3 scripts/gen_gus_patches.py`.
