#!/usr/bin/env python3
"""Generate the audio test corpus: synthesized sfx + a chiptune music loop.

All audio is synthesized here (deterministic, fixed seed) — no external
recordings, no licensing questions. WAV files are written directly; the
compressed/legacy variants (ogg/mp3/flac/aiff/au/voc) are encoded from them
with ffmpeg when available. A minimal Standard MIDI File is hand-assembled.

Usage: python3 scripts/gen_test_audio.py [output-dir]
"""

from __future__ import annotations

import math
import shutil
import struct
import subprocess
import sys
import wave
from pathlib import Path

RATE = 44100


def write_wav(path: Path, samples: list[float]) -> None:
    with wave.open(str(path), "wb") as w:
        w.setnchannels(1)
        w.setsampwidth(2)
        w.setframerate(RATE)
        frames = b"".join(
            struct.pack("<h", max(-32767, min(32767, int(s * 32767)))) for s in samples
        )
        w.writeframes(frames)
    print(f"wrote {path} ({len(samples) / RATE:.2f}s)")


def env(i: int, n: int, attack: float = 0.01, release: float = 0.25) -> float:
    t = i / n
    a = min(1.0, (i / RATE) / attack) if attack > 0 else 1.0
    r = min(1.0, (1.0 - t) / release) if release > 0 else 1.0
    return a * r


def square(phase: float) -> float:
    return 1.0 if (phase % 1.0) < 0.5 else -1.0


def triangle(phase: float) -> float:
    p = phase % 1.0
    return 4.0 * p - 1.0 if p < 0.5 else 3.0 - 4.0 * p


def sfx_laser() -> list[float]:
    n = int(0.30 * RATE)
    out, phase = [], 0.0
    for i in range(n):
        f = 1800.0 - 1400.0 * (i / n)  # descending sweep
        phase += f / RATE
        out.append(0.5 * square(phase) * env(i, n, 0.005, 0.35))
    return out


def sfx_explosion() -> list[float]:
    n = int(0.65 * RATE)
    out, state, lp = [], 0x2545F491, 0.0
    for i in range(n):
        state ^= (state << 13) & 0xFFFFFFFF
        state ^= state >> 17
        state ^= (state << 5) & 0xFFFFFFFF
        noise = (state / 0x7FFFFFFF) - 1.0
        lp += 0.12 * (noise - lp)  # low-pass rumble
        out.append(0.9 * lp * env(i, n, 0.002, 0.85))
    return out


def sfx_coin() -> list[float]:
    n = int(0.22 * RATE)
    out, phase = [], 0.0
    for i in range(n):
        f = 988.0 if i < n * 0.4 else 1319.0  # B5 -> E6
        phase += f / RATE
        out.append(0.4 * square(phase) * env(i, n, 0.002, 0.3))
    return out


NOTES = {"C4": 261.63, "D4": 293.66, "E4": 329.63, "F4": 349.23, "G4": 392.0,
         "A4": 440.0, "B4": 493.88, "C5": 523.25, "E5": 659.25, "G5": 783.99,
         "R": 0.0}


def music_loop() -> list[float]:
    # Two-voice chiptune: square lead + triangle bass, 120 BPM, ~6.4s loop.
    lead = ["E4", "G4", "A4", "C5", "B4", "G4", "E4", "R",
            "C4", "E4", "G4", "C5", "E5", "C5", "G4", "E4",
            "F4", "A4", "C5", "A4", "G4", "E4", "D4", "E4",
            "C4", "E4", "G4", "E4", "C5", "G4", "E4", "C4"]
    bass = ["C4", "R", "G4", "R", "A4", "R", "E4", "R"] * 4
    step = int(0.2 * RATE)  # eighth notes at 150bpm-ish
    n = step * len(lead)
    out = [0.0] * n
    for voice, seq, gain, wave_fn, octave in (
            (0, lead, 0.28, square, 1.0), (1, bass, 0.22, triangle, 0.5)):
        phase = 0.0
        for k, note in enumerate(seq):
            f = NOTES[note] * octave
            for j in range(step):
                i = k * step + j
                if f > 0:
                    phase += f / RATE
                    out[i] += gain * wave_fn(phase) * env(j, step, 0.005, 0.15)
    return out


def midi_scale() -> bytes:
    """Minimal type-0 SMF: C major scale, quarter notes, piano."""
    def vlq(v: int) -> bytes:
        chunks = [v & 0x7F]
        v >>= 7
        while v:
            chunks.append(0x80 | (v & 0x7F))
            v >>= 7
        return bytes(reversed(chunks))

    events = bytearray()
    events += vlq(0) + bytes([0xC0, 0x00])  # program change: piano
    for note in (60, 62, 64, 65, 67, 69, 71, 72):
        events += vlq(0) + bytes([0x90, note, 100])    # note on
        events += vlq(480) + bytes([0x80, note, 0])    # note off after 1 beat
    events += vlq(0) + bytes([0xFF, 0x2F, 0x00])       # end of track
    track = b"MTrk" + struct.pack(">I", len(events)) + bytes(events)
    header = b"MThd" + struct.pack(">IHHH", 6, 0, 1, 480)
    return header + track


def encode(src: Path, dest: Path, *args: str) -> None:
    ffmpeg = shutil.which("ffmpeg")
    if not ffmpeg:
        print(f"SKIP {dest} (no ffmpeg)")
        return
    subprocess.run([ffmpeg, "-y", "-loglevel", "error", "-i", str(src), *args,
                    str(dest)], check=True)
    print(f"wrote {dest}")


def main() -> int:
    out = Path(sys.argv[1]) if len(sys.argv) > 1 else \
        Path(__file__).resolve().parent.parent / "tests" / "mixer" / "assets"
    out.mkdir(parents=True, exist_ok=True)

    write_wav(out / "sfx_laser.wav", sfx_laser())
    write_wav(out / "sfx_explosion.wav", sfx_explosion())
    write_wav(out / "sfx_coin.wav", sfx_coin())
    write_wav(out / "music_loop.wav", music_loop())
    (out / "music_scale.mid").write_bytes(midi_scale())
    print(f"wrote {out / 'music_scale.mid'}")

    music = out / "music_loop.wav"
    encode(music, out / "music_loop.ogg", "-c:a", "libvorbis", "-q:a", "4")
    encode(music, out / "music_loop.mp3", "-c:a", "libmp3lame", "-b:a", "160k")
    encode(music, out / "music_loop.flac", "-c:a", "flac")
    coin = out / "sfx_coin.wav"
    encode(coin, out / "sfx_coin.aiff")
    encode(coin, out / "sfx_coin.au")
    encode(coin, out / "sfx_coin.voc")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
