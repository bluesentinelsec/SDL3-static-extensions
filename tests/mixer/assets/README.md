# Audio test corpus

Every file here is **synthesized** by `scripts/gen_test_audio.py` — a
deterministic chiptune music loop (square lead + triangle bass) and three
retro sound effects (laser sweep, noise-burst explosion, coin blip), plus a
hand-assembled Standard MIDI File. No external recordings; no third-party
licenses. Regenerate with:

```bash
python3 scripts/gen_test_audio.py    # WAVs + MIDI directly; ogg/mp3/flac/
                                     # aiff/au/voc encoded via ffmpeg
```

The same files back the local demo and the format decode tests
(`tests/mixer/mixer_test.cpp`).
