# SDL3_mixer (vendored under `mixer/`)

| | |
|--|--|
| Upstream | https://github.com/libsdl-org/SDL_mixer |
| Version | 3.2.4 (tag `release-3.2.4`) |
| Commit | `72a81869b45e249e8e67102db4e98dd2441f05a1` |
| License | zlib (see `mixer/LICENSE.txt`) |
| Imported | 2026-08-12, direct source copy (no submodule, no fork) |
| Requires | SDL3 ≥ 3.4.0 (satisfied by our pinned 3.4.14, see `deps/SDL3.md`) |
| API generation | The redesigned **`MIX_*`** API (what 3.2.4 ships) |

## What was taken

- `src/` core: `SDL_mixer.c`, metadata tags, spatialization, internal headers.
- Static-friendly decoders (each vendored single-file or pure C, in-tree):
  `decoder_wav.c`, `decoder_aiff.c`, `decoder_au.c`, `decoder_voc.c`,
  `decoder_raw.c`, `decoder_sinewave.c`, `decoder_stb_vorbis.c` (+
  `src/stb_vorbis/`), `decoder_drmp3.c` / `decoder_drflac.c` (+
  `src/dr_libs/`), `decoder_timidity.c` (+ `src/timidity/` incl. its
  COPYING).
- `include/SDL3_mixer/`, `LICENSE.txt`.

## What was deleted (not imported)

- Decoders requiring external shared/heavy libraries (no-stubs — the decoder
  table is `#ifdef`-gated upstream, so removal needed no dispatch surgery):
  `decoder_flac.c` (libFLAC), `decoder_vorbis.c` (libvorbisfile),
  `decoder_mpg123.c` (mpg123), `decoder_opus.c` (opus/opusfile),
  `decoder_wavpack.c` (WavPack), `decoder_gme.c` (game-music-emu),
  `decoder_xmp.c` (libxmp — trackers are out of scope by decision),
  `decoder_fluidsynth.c` (FluidSynth — MIDI is covered statically by
  TiMidity).
- `external/` submodule stubs, `.github/`, `cmake/`, `CMakeLists.txt`,
  `build-scripts/`, `test/`, `examples/`, `docs/`, IDE trees, shared-library
  export machinery (`genexports.py`, `.exports`, `.sym`, `version.rc`).

## Format coverage (the games-90%)

Enabled: **WAV, OGG Vorbis, MP3, FLAC** (the big four), plus AIFF, AU, VOC,
RAW, generated sine waves, and **MIDI** via statically linked TiMidity
(requires GUS patch data at runtime to produce sound; loads fail cleanly
without it — the dlopen-style "niche optional" of the design, with zero
link-time cost).

## Local modifications

None yet (decoder selection is entirely build-level).

Test corpus: fully **synthesized** by `scripts/gen_test_audio.py`
(deterministic chiptune loop + sfx, encoded to every enabled format with
ffmpeg) — no external recordings, no licensing questions. See
`tests/mixer/assets/README.md`.
