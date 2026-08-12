#!/usr/bin/env python3
"""Generate hand-crafted corpus images for formats upstream ships no sample for.

Emits minimal-but-valid files (committed to tests/image/assets/) for:
  - LBM  (IFF ILBM, uncompressed, 4x2, 24-bit via 8 bitplanes per channel? no —
          PBM variant: chunky 8-bit paletted, the variant IMG_lbm.c supports)
  - XV   (xv "thumbnail" P7 332 format)

Deterministic output: running this script twice produces identical bytes.
Usage: python3 scripts/gen_test_images.py [output-dir]
"""

from __future__ import annotations

import struct
import sys
from pathlib import Path


def chunk(tag: bytes, payload: bytes) -> bytes:
    data = tag + struct.pack(">I", len(payload)) + payload
    if len(payload) % 2:
        data += b"\x00"
    return data


def gen_lbm() -> bytes:
    """4x2 IFF PBM (chunky, palette, uncompressed) — the DPaint-style variant."""
    width, height = 4, 2
    bmhd = struct.pack(
        ">HHhhBBBxHBBhh",
        width, height,   # w, h
        0, 0,            # x, y
        8,               # nPlanes: 8-bit chunky
        0,               # masking
        0,               # compression: none
        0,               # transparent color (pad byte consumed by 'x')
        1, 1,            # xAspect, yAspect
        width, height,   # pageWidth, pageHeight
    )
    # 4-entry palette: red, green, blue, white (rest of the 256 unspecified
    # entries default; CMAP may list fewer than 2^depth entries).
    cmap = bytes([255, 0, 0, 0, 255, 0, 0, 0, 255, 255, 255, 255])
    # Chunky rows of palette indices. The reference parser reads PBM rows
    # padded to a 16-pixel multiple (((w+15)/16)*16 bytes per row).
    padded_row = ((width + 15) // 16) * 16
    rows = [bytes([0, 1, 2, 3]), bytes([3, 2, 1, 0])]
    body = b"".join(row + b"\x00" * (padded_row - len(row)) for row in rows)
    payload = b"PBM " + chunk(b"BMHD", bmhd) + chunk(b"CMAP", cmap) + chunk(b"BODY", body)
    return chunk(b"FORM", payload)


def gen_xv() -> bytes:
    """4x2 xv thumbnail (P7 332): textual header, then 1 byte per pixel."""
    header = (
        b"P7 332\n"
        b"#XVVERSION:Version 3.10  Rev: 12/16/94\n"
        b"#IMGINFO:4x2 RGB\n"
        b"#END_OF_COMMENTS\n"
        b"4 2 255\n"
    )
    # 3-3-2 packed RGB: red=0xE0, green=0x1C, blue=0x03, white=0xFF
    pixels = bytes([0xE0, 0x1C, 0x03, 0xFF, 0xFF, 0x03, 0x1C, 0xE0])
    return header + pixels


def main() -> int:
    out = Path(sys.argv[1]) if len(sys.argv) > 1 else Path(__file__).resolve().parent.parent / "tests" / "image" / "assets"
    out.mkdir(parents=True, exist_ok=True)
    (out / "generated.lbm").write_bytes(gen_lbm())
    (out / "generated.xv").write_bytes(gen_xv())
    print(f"wrote {out / 'generated.lbm'} ({len(gen_lbm())} bytes)")
    print(f"wrote {out / 'generated.xv'} ({len(gen_xv())} bytes)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
