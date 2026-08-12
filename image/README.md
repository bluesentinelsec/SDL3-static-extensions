# SDLStatic::Image

A static-link-first port of [SDL3_image](https://github.com/libsdl-org/SDL_image)
(upstream base: **3.4.4**; full provenance and change ledger in
[`deps/SDL3_image.md`](../deps/SDL3_image.md)). The public API is
SDL3_image-compatible for everything listed as supported below — but **not**
ABI-compatible with the official shared library, and removed APIs are deleted
from the header, so unsupported usage fails at **compile time**, never at
runtime.

## Format support

| Format | Load | Save | Animation | Notes |
|--------|------|------|-----------|-------|
| BMP    | ✅ | ✅ | — | |
| PNG    | ✅ | ✅ | — | stb_image decode / vendored encoder |
| JPG    | ✅ | ✅ | — | stb_image decode / tiny_jpeg encoder |
| GIF    | ✅ | ✅ | ✅ load + save | animation round-trip tested |
| ANI    | — | — | ✅ load + save | Windows animated cursor |
| ICO / CUR | ✅ | ✅ | — | |
| TGA    | ✅ | ✅ | — | magicless: loading from memory requires `IMG_LoadTyped_IO` (or a `.tga` filename) |
| QOI    | ✅ | ❌ | — | |
| SVG    | ✅ (incl. `IMG_LoadSizedSVG_IO`) | ❌ | — | nanosvg; static rasterizer |
| PNM (PBM/PGM/PPM) | ✅ | ❌ | — | |
| PCX    | ✅ | ❌ | — | |
| LBM    | ✅ | ❌ | — | IFF ILBM/PBM |
| XCF    | ✅ | ❌ | — | GIMP, flattened |
| XPM    | ✅ | ❌ | — | |
| XV     | ✅ | ❌ | — | xv thumbnail |

## NOT supported (deliberately removed)

| Format | Why |
|--------|-----|
| **AVIF** | requires libavif + dav1d/aom (heavy link-time shared deps) |
| **JXL**  | requires libjxl |
| **WEBP** | requires libwebp |
| **TIFF** | requires libtiff; not in the games-90% (revisit on demand) |
| **APNG** | animated PNG exists only via libpng; the stb backend cannot provide it — use GIF for animations |

Also removed: the libpng/libjpeg code paths, the Windows WIC backend, and the
Apple ImageIO backend — every platform decodes through the same vendored
single-file C backends (stb_image, tiny_jpeg, qoi, nanosvg), so behavior is
identical everywhere and the link-time dependency set is empty.

These are hard removals per the suite's no-stubs policy: the functions do not
exist in `SDL3_image/SDL_image.h`, so consumer code referencing them fails to
compile rather than failing at runtime.

## Guarantees (CI-enforced)

- **No non-OS shared-library dependencies** — `scripts/link_audit.py` runs as
  a CTest test on every desktop CI push (allowlist: OS-built-ins only; any
  codec/font library fails the build).
- **Parser robustness** — every loader is exercised against truncated and
  bit-flipped inputs under ASan+UBSan in CI. Two memory-safety bugs present
  in upstream 3.4.4's GIF decoder are fixed in this port (see
  `deps/SDL3_image.md`; fixes are local to this repository).
- **Format coverage** — every supported load path and every save encoder is
  round-trip tested against the committed corpus (`tests/image/assets/`),
  including in-browser (wasm) decode tests.
