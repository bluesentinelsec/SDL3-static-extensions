#!/usr/bin/env python3
"""Generate an original General MIDI GUS patch set for the TiMidity backend.

TiMidity (the statically linked MIDI soft-synth in SDLStatic::Mixer) needs
GF1/GUS instrument patches at runtime to render audio. Third-party patch
collections carry licensing baggage, so — in the same spirit as the
synthesized test corpus — this script *generates* a small, deterministic,
zlib-clean set: band-limited single-cycle waveforms for melodic programs and
synthesized one-shots for percussion, plus the timidity.cfg mapping all 128
GM programs and the common drum notes.

Output (default): mixer/gm-patches/
Regenerate with:  python3 scripts/gen_gus_patches.py

GF1 .pat layout matches what src/timidity/instrum.c actually reads:
239-byte header (magic at 0, #instruments at 82, #layers at 151, #samples at
198), then per sample: 7B name, 1B fractions, u32 data/loop bounds IN BYTES,
u16 sample_rate, u32 low/high/root frequencies in MILLIHERTZ, 2B tuning,
1B panning, 6B envelope rates, 6B envelope offsets, 3B tremolo, 3B vibrato,
1B modes, 40B scale/reserved, then 16-bit LE signed PCM.
"""

from __future__ import annotations

import math
import struct
import sys
from pathlib import Path

SAMPLE_RATE = 44100
CYCLE = 128  # single-cycle length for melodic patches (u16 rate cap: 440*128)

MODES_16BIT = 1 << 0
MODES_LOOPING = 1 << 2
MODES_SUSTAIN = 1 << 5
MODES_ENVELOPE = 1 << 6

NOTE0_MHZ = 8176  # MIDI note 0 in millihertz, matching timidity's freq_table


def note_mhz(note: int) -> int:
    return round(440000.0 * 2.0 ** ((note - 69) / 12.0))


def xorshift(state: int) -> int:
    state ^= (state << 13) & 0xFFFFFFFF
    state ^= state >> 17
    state ^= (state << 5) & 0xFFFFFFFF
    return state & 0xFFFFFFFF


def normalize(samples: list[float], peak: int = 30000) -> bytes:
    top = max(abs(s) for s in samples) or 1.0
    return b"".join(struct.pack("<h", round(s / top * peak)) for s in samples)


def cycle_wave(harmonics: dict[int, float]) -> bytes:
    """One band-limited cycle from a harmonic recipe {n: amplitude}."""
    samples = [
        sum(a * math.sin(2.0 * math.pi * n * i / CYCLE) for n, a in harmonics.items())
        for i in range(CYCLE)
    ]
    return normalize(samples)


def pat(name: str, data: bytes, *, root_mhz: int, sample_rate: int,
        looping: bool) -> bytes:
    """Serialize one single-sample GF1 patch."""
    header = bytearray(239)
    header[0:22] = b"GF1PATCH110\x00ID#000002\x00"
    header[82] = 1    # instruments
    header[151] = 1   # layers
    header[198] = 1   # samples

    modes = MODES_16BIT
    if looping:
        # Sustained tone: loop the whole cycle, hold under the GUS envelope.
        modes |= MODES_LOOPING | MODES_SUSTAIN | MODES_ENVELOPE

    # Envelope bytes: top 2 bits of a rate select a range (00 fastest), low 6
    # are the mantissa. Offsets are target levels. Stages 0-2 run at note-on
    # (attack to full, settle to sustain); 3-5 run at note-off (release).
    rates = bytes([0x3F, 0x08, 0x01, 0x18, 0x18, 0x18])
    offsets = bytes([250, 246, 244, 8, 4, 0])

    body = bytearray()
    body += name.encode("ascii")[:7].ljust(7, b"\x00")
    body += bytes([0])                       # fractions
    body += struct.pack("<i", len(data))     # data length (bytes)
    body += struct.pack("<i", 0)             # loop start (bytes)
    body += struct.pack("<i", len(data))     # loop end (bytes)
    body += struct.pack("<H", sample_rate)
    body += struct.pack("<i", NOTE0_MHZ)     # low freq
    body += struct.pack("<i", note_mhz(127)) # high freq
    body += struct.pack("<i", root_mhz)
    body += struct.pack("<H", 0)             # tuning
    body += bytes([7])                       # panning: center
    body += rates
    body += offsets
    body += bytes([0, 0, 0])                 # tremolo sweep/rate/depth
    body += bytes([0, 0, 0])                 # vibrato sweep/rate/depth
    body += bytes([modes])
    body += struct.pack("<H", 0)             # scale frequency
    body += struct.pack("<H", 1024)          # scale factor
    body += bytes(36)                        # reserved
    body += data
    return bytes(header) + bytes(body)


def melodic(name: str, harmonics: dict[int, float]) -> bytes:
    # One cycle played back at root pitch when resampled from CYCLE*440 Hz.
    return pat(name, cycle_wave(harmonics), root_mhz=440000,
               sample_rate=440 * CYCLE, looping=True)


def percussion(name: str, samples: list[float], root_note: int) -> bytes:
    return pat(name, normalize(samples), root_mhz=note_mhz(root_note),
               sample_rate=SAMPLE_RATE, looping=False)


def decay(i: int, total: int, curve: float = 5.0) -> float:
    return math.exp(-curve * i / total)


def drum_kick() -> list[float]:
    n = int(SAMPLE_RATE * 0.25)
    out, phase = [], 0.0
    for i in range(n):
        freq = 55.0 + 65.0 * decay(i, n, 9.0)  # pitch glide 120 -> 55 Hz
        phase += 2.0 * math.pi * freq / SAMPLE_RATE
        out.append(math.sin(phase) * decay(i, n, 6.0))
    return out


def drum_snare() -> list[float]:
    n = int(SAMPLE_RATE * 0.18)
    out, state = [], 0x2F6E2B1
    for i in range(n):
        state = xorshift(state)
        noise = (state / 0x7FFFFFFF) - 1.0
        tone = math.sin(2.0 * math.pi * 185.0 * i / SAMPLE_RATE)
        out.append((0.7 * noise + 0.4 * tone) * decay(i, n, 7.0))
    return out


def drum_hat() -> list[float]:
    n = int(SAMPLE_RATE * 0.08)
    out, state, prev = [], 0xBADC0DE, 0.0
    for i in range(n):
        state = xorshift(state)
        noise = (state / 0x7FFFFFFF) - 1.0
        out.append((noise - prev) * decay(i, n, 8.0))  # crude highpass
        prev = noise
    return out


def drum_tom() -> list[float]:
    n = int(SAMPLE_RATE * 0.3)
    out, phase = [], 0.0
    for i in range(n):
        freq = 120.0 + 60.0 * decay(i, n, 7.0)
        phase += 2.0 * math.pi * freq / SAMPLE_RATE
        out.append(math.sin(phase) * decay(i, n, 5.0))
    return out


def drum_cymbal() -> list[float]:
    n = int(SAMPLE_RATE * 0.7)
    out, state = [], 0x51C4E77
    partials = [317.0, 419.0, 547.0, 683.0, 829.0]  # enharmonic shimmer
    for i in range(n):
        state = xorshift(state)
        noise = (state / 0x7FFFFFFF) - 1.0
        metal = sum(math.copysign(0.15, math.sin(2.0 * math.pi * f * i / SAMPLE_RATE))
                    for f in partials)
        out.append((0.6 * noise + metal) * decay(i, n, 4.0))
    return out


MELODIC = {
    "piano": {1: 1.0, 2: 0.5, 3: 0.22, 4: 0.12, 5: 0.06, 6: 0.035, 8: 0.02},
    "organ": {1: 1.0, 3: 0.33, 5: 0.2, 7: 0.14, 9: 0.11},
    "strings": {n: 1.0 / n for n in range(1, 13)},
    "bass": {1: 1.0, 2: 0.6, 3: 0.25},
    "flute": {1: 1.0, 2: 0.14, 3: 0.05},
    "lead": {n: (1.0 / n if n % 2 else 0.55 / n) for n in range(1, 11)},
}

# GM program ranges -> timbre (inclusive bounds).
PROGRAM_MAP = [
    (0, 7, "piano"), (8, 15, "piano"), (16, 23, "organ"), (24, 31, "piano"),
    (32, 39, "bass"), (40, 55, "strings"), (56, 63, "lead"), (64, 79, "flute"),
    (80, 87, "lead"), (88, 95, "strings"), (96, 103, "flute"),
    (104, 111, "piano"), (112, 119, "organ"), (120, 127, "flute"),
]

DRUMS = {
    "kick": (drum_kick, 36, [35, 36]),
    "snare": (drum_snare, 38, [37, 38, 39, 40]),
    "hat": (drum_hat, 42, [42, 44, 46, 54, 69, 70, 75, 76]),
    "tom": (drum_tom, 45, [41, 43, 45, 47, 48, 50, 60, 61, 62, 63, 64]),
    "cymbal": (drum_cymbal, 49, [49, 51, 52, 53, 55, 57, 59]),
}


def main() -> int:
    out = Path(sys.argv[1]) if len(sys.argv) > 1 else \
        Path(__file__).resolve().parent.parent / "mixer" / "gm-patches"
    out.mkdir(parents=True, exist_ok=True)

    for name, harmonics in MELODIC.items():
        (out / f"{name}.pat").write_bytes(melodic(name, harmonics))
        print(f"wrote {out / f'{name}.pat'}")
    for name, (builder, root, _notes) in DRUMS.items():
        (out / f"{name}.pat").write_bytes(percussion(name, builder(), root))
        print(f"wrote {out / f'{name}.pat'}")

    cfg = ["# Generated by scripts/gen_gus_patches.py — original synthesized",
           "# GM patch set (zlib, no third-party samples). See gm-patches/README.md.",
           "bank 0"]
    for lo, hi, timbre in PROGRAM_MAP:
        for program in range(lo, hi + 1):
            cfg.append(f"{program} {timbre}.pat")
    cfg.append("drumset 0")
    for name, (_builder, _root, notes) in DRUMS.items():
        for note in notes:
            cfg.append(f"{note} {name}.pat note={note}")
    (out / "timidity.cfg").write_text("\n".join(cfg) + "\n")
    print(f"wrote {out / 'timidity.cfg'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
