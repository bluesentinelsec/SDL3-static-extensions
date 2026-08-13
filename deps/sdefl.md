# sdefl / sinfl (vendored under `extras/src/sdefl/`)

| | |
|--|--|
| Upstream | https://github.com/vurtun/lib (Micha Mettke) |
| Commit | `5a3f3aba052e63ffae8eb0214c6bb8ffffedea3c` |
| Files | `sdefl.h` (DEFLATE compressor), `sinfl.h` (decompressor) |
| License | dual MIT / public domain (text embedded in the headers) |
| Imported | 2026-08-13, direct source copy |

The same single-header DEFLATE implementation raylib vendors, backing
`SDLStatic_CompressData` / `SDLStatic_DecompressData` (see
`extras/include/SDLStatic/compress.h`). We use the `zsdeflate`/`zsinflate`
zlib-format entry points for their adler32 integrity check.

## Local modifications (found by our sanitizer suite, kept local)

1. **`sinfl.h` `zsinflate`** — the stored adler32 was assembled with
   `eob[0] << 24` on promoted `int`; a first byte ≥ 0x80 makes the shift
   overflow signed int (UB, caught by UBSan). Cast each byte to `unsigned`.
2. **`sinfl.h` `sinfl_refill`** — upstream reads 8 bytes unconditionally
   through its 64-bit bit-reader, running past the end of the input buffer
   near the stream tail (heap over-read, caught by ASan on a plain valid
   round-trip; raylib inherits this exposure). Added an input bound
   (`bitend`) to the decoder state and a zero-filled bounded tail path in
   the refill, so the reader can never advance past the buffer regardless
   of input corruption.
