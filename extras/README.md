# SDLStatic::Extras

Game-infrastructure modules that fall outside the SDL satellite family but
that most games end up needing. Everything is plain C over SDL3 with zero
external dependencies (no libcrypto, no libz) — fully static on every
platform, web included. Original SDLStatic code (zlib) except the vendored
sdefl/sinfl DEFLATE headers ([`deps/sdefl.md`](../deps/sdefl.md)).

All returned buffers are `SDL_malloc`'d — free them with `SDL_free`.

## `<SDLStatic/crypto.h>` — password-based asset encryption

ChaCha20 (RFC 8439) + PBKDF2-HMAC-SHA256 key derivation + encrypt-then-MAC
(HMAC-SHA256), all implemented from spec and pinned to published test
vectors in the test suite (`SDLStatic_CryptoSelfTest()` re-checks them at
runtime). A wrong password or a tampered file is *detected*, not decrypted
into garbage. Also exposes `SDLStatic_SHA256` / `SDLStatic_HMACSHA256`.

```c
int n = 0;
unsigned char *enc = SDLStatic_EncryptData(bytes, size, "password", &n);
unsigned char *dec = SDLStatic_DecryptData(enc, n, "password", &size);
```

Scope honesty: salts/nonces come from timing entropy, not an OS CSPRNG —
right for protecting shipped assets, not for building a messaging app.

## `<SDLStatic/compress.h>` — DEFLATE (raylib API shape)

```c
int compSize = 0, size = 0;
unsigned char *comp = SDLStatic_CompressData(data, dataSize, &compSize);
unsigned char *back = SDLStatic_DecompressData(comp, compSize, &size);
```

Container: `"SSZ1"` + original size + zlib-format stream (adler32-checked),
so decompression allocates exactly and rejects corrupted input.

## `<SDLStatic/base64.h>` — Base64 (raylib API shape)

```c
char *text = SDLStatic_EncodeDataBase64(data, dataSize, &outSize);
unsigned char *data2 = SDLStatic_DecodeDataBase64(text, &outSize);
```

RFC 4648, strict decoding (whitespace skipped, anything else rejected).

## `<SDLStatic/signals.h>` — Godot-style signals

```c
SDLStatic_SignalEmitter *door = SDLStatic_CreateSignalEmitter();
Uint64 id = SDLStatic_ConnectSignal(door, "opened", on_opened, hud, 0);
SDLStatic_EmitSignal(door, "opened", &args);   /* -> on_opened(hud, "opened", &args) */
SDLStatic_DisconnectSignal(door, id);
```

Godot-matching semantics: in-order delivery, connections made during an
emission don't fire in it, disconnect-during-emit (including self) is safe,
`SDLSTATIC_SIGNAL_ONESHOT` auto-disconnects, emission is reentrant.
Single-threaded by design, like a game loop.

Tests (`tests/extras/`) pin every crypto primitive to published vectors
(FIPS 180-4, RFC 4231, RFC 8439, PBKDF2), prove round-trips and
tamper/wrong-password rejection, exercise the reentrancy semantics above,
and run the standard link audit.
