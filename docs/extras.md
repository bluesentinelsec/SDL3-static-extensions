---
title: Extras
description: "Password-based asset encryption, DEFLATE compression, base64, and Godot-style signals — the glue every game ends up needing."
---

# Extras — `SDLStatic::Extras`

Game infrastructure outside the SDL satellite family that most games end
up needing anyway. Plain C over SDL3 with zero external dependencies (no
libcrypto, no zlib) — fully static everywhere, web included. All returned
buffers are `SDL_malloc`'d; free them with `SDL_free`.

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Extras)
```

## Crypto — `<SDLStatic/crypto.h>`

Password-based asset encryption: ChaCha20 (RFC 8439) + PBKDF2-HMAC-SHA256
key derivation + encrypt-then-MAC (HMAC-SHA256), implemented from spec
and pinned to published test vectors (`SDLStatic_CryptoSelfTest()`
re-checks them at runtime). A wrong password or tampered file is
**detected**, not decrypted into garbage.

```c
int n = 0;
unsigned char *enc = SDLStatic_EncryptData(bytes, size, "password", &n);
unsigned char *dec = SDLStatic_DecryptData(enc, n, "password", &size);
```

Also exposes `SDLStatic_SHA256` / `SDLStatic_HMACSHA256`. Scope honesty:
salts/nonces come from timing entropy, not an OS CSPRNG — right for
protecting shipped assets, not for building a messaging app.

## Compression — `<SDLStatic/compress.h>`

DEFLATE with the raylib API shape, backed by vendored sdefl/sinfl:

```c
int compSize = 0, size = 0;
unsigned char *comp = SDLStatic_CompressData(data, dataSize, &compSize);
unsigned char *back = SDLStatic_DecompressData(comp, compSize, &size);
```

The container records the original size and an adler32 checksum, so
decompression allocates exactly and rejects corrupted input.

## Base64 — `<SDLStatic/base64.h>`

```c
char *text = SDLStatic_EncodeDataBase64(data, dataSize, &outSize);
unsigned char *data2 = SDLStatic_DecodeDataBase64(text, &outSize);
```

RFC 4648, strict decoding (whitespace skipped, anything else rejected).

## Signals — `<SDLStatic/signals.h>`

Godot-style events:

```c
SDLStatic_SignalEmitter *door = SDLStatic_CreateSignalEmitter();
Uint64 id = SDLStatic_ConnectSignal(door, "opened", on_opened, hud, 0);
SDLStatic_EmitSignal(door, "opened", &args);
SDLStatic_DisconnectSignal(door, id);
```

Godot-matching semantics: in-order delivery, connections made during an
emission don't fire in it, disconnect-during-emit (including self) is
safe, `SDLSTATIC_SIGNAL_ONESHOT` auto-disconnects, emission is
reentrant. Single-threaded by design, like a game loop.

Crypto primitives are pinned to published vectors (FIPS 180-4, RFC 4231,
RFC 8439) in the test suite, with an independent Python implementation of
the SSE1 container cross-validated against the C one.

Provenance for the vendored DEFLATE:
[`deps/sdefl.md`](https://github.com/bluesentinelsec/SDL3-static-extensions/blob/main/deps/sdefl.md).
