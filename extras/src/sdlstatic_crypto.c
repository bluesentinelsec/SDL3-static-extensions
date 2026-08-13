/*
 * sdlstatic_crypto.c — password-based asset encryption for SDLStatic Extras.
 *
 * Original SDLStatic code (zlib). Implements SHA-256 (FIPS 180-4),
 * HMAC-SHA256 (RFC 2104), PBKDF2-HMAC-SHA256 (RFC 8018), and ChaCha20
 * (RFC 8439) from their specifications; the test suite pins each primitive
 * to published test vectors. Container format and design notes in
 * SDLStatic/crypto.h.
 */
#include <SDLStatic/crypto.h>

#define SSE_MAGIC "SSE1"
#define SSE_SALT_LEN 16
#define SSE_NONCE_LEN 12
#define SSE_TAG_LEN 32
#define SSE_HEADER_LEN (4 + SSE_SALT_LEN + SSE_NONCE_LEN)
#define SSE_PBKDF2_ITERATIONS 10000

/* ------------------------------------------------------------ SHA-256 --- */

typedef struct Sha256Ctx
{
    Uint32 state[8];
    Uint64 length;
    Uint8 block[64];
    size_t fill;
} Sha256Ctx;

static const Uint32 kSha256K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4,
    0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe,
    0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f,
    0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
    0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
    0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116,
    0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7,
    0xc67178f2};

static Uint32 Rotr32(Uint32 v, int n)
{
    return (v >> n) | (v << (32 - n));
}

static void Sha256Init(Sha256Ctx *ctx)
{
    static const Uint32 init[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
                                   0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
    SDL_memcpy(ctx->state, init, sizeof(init));
    ctx->length = 0;
    ctx->fill = 0;
}

static void Sha256Block(Sha256Ctx *ctx, const Uint8 *p)
{
    Uint32 w[64];
    for (int i = 0; i < 16; ++i)
    {
        w[i] = ((Uint32)p[i * 4] << 24) | ((Uint32)p[i * 4 + 1] << 16) |
               ((Uint32)p[i * 4 + 2] << 8) | (Uint32)p[i * 4 + 3];
    }
    for (int i = 16; i < 64; ++i)
    {
        const Uint32 s0 = Rotr32(w[i - 15], 7) ^ Rotr32(w[i - 15], 18) ^ (w[i - 15] >> 3);
        const Uint32 s1 = Rotr32(w[i - 2], 17) ^ Rotr32(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
    }
    Uint32 a = ctx->state[0], b = ctx->state[1], c = ctx->state[2], d = ctx->state[3];
    Uint32 e = ctx->state[4], f = ctx->state[5], g = ctx->state[6], h = ctx->state[7];
    for (int i = 0; i < 64; ++i)
    {
        const Uint32 s1 = Rotr32(e, 6) ^ Rotr32(e, 11) ^ Rotr32(e, 25);
        const Uint32 ch = (e & f) ^ (~e & g);
        const Uint32 t1 = h + s1 + ch + kSha256K[i] + w[i];
        const Uint32 s0 = Rotr32(a, 2) ^ Rotr32(a, 13) ^ Rotr32(a, 22);
        const Uint32 maj = (a & b) ^ (a & c) ^ (b & c);
        const Uint32 t2 = s0 + maj;
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}

static void Sha256Update(Sha256Ctx *ctx, const void *data, size_t len)
{
    const Uint8 *p = (const Uint8 *)data;
    ctx->length += (Uint64)len * 8;
    while (len > 0)
    {
        const size_t take = SDL_min(len, 64 - ctx->fill);
        SDL_memcpy(ctx->block + ctx->fill, p, take);
        ctx->fill += take;
        p += take;
        len -= take;
        if (ctx->fill == 64)
        {
            Sha256Block(ctx, ctx->block);
            ctx->fill = 0;
        }
    }
}

static void Sha256Final(Sha256Ctx *ctx, Uint8 digest[32])
{
    const Uint64 bits = ctx->length;
    const Uint8 pad = 0x80;
    Sha256Update(ctx, &pad, 1);
    const Uint8 zero = 0;
    while (ctx->fill != 56)
    {
        Sha256Update(ctx, &zero, 1);
    }
    Uint8 lenb[8];
    for (int i = 0; i < 8; ++i)
    {
        lenb[i] = (Uint8)(bits >> (56 - i * 8));
    }
    /* Length bytes must not re-count toward the message length. */
    ctx->length = bits;
    Sha256Update(ctx, lenb, 8);
    for (int i = 0; i < 8; ++i)
    {
        digest[i * 4 + 0] = (Uint8)(ctx->state[i] >> 24);
        digest[i * 4 + 1] = (Uint8)(ctx->state[i] >> 16);
        digest[i * 4 + 2] = (Uint8)(ctx->state[i] >> 8);
        digest[i * 4 + 3] = (Uint8)(ctx->state[i]);
    }
}

bool SDLStatic_SHA256(const void *data, size_t dataSize, Uint8 digest[32])
{
    if ((data == NULL && dataSize > 0) || digest == NULL)
    {
        return SDL_InvalidParamError("data");
    }
    Sha256Ctx ctx;
    Sha256Init(&ctx);
    Sha256Update(&ctx, data, dataSize);
    Sha256Final(&ctx, digest);
    return true;
}

/* -------------------------------------------------------- HMAC-SHA256 --- */

typedef struct HmacCtx
{
    Sha256Ctx inner;
    Uint8 opad_key[64];
} HmacCtx;

static void HmacInit(HmacCtx *h, const void *key, size_t keySize)
{
    Uint8 kb[64];
    SDL_memset(kb, 0, sizeof(kb));
    if (keySize > 64)
    {
        SDLStatic_SHA256(key, keySize, kb); /* first 32 bytes, rest zero */
    }
    else if (keySize > 0)
    {
        SDL_memcpy(kb, key, keySize);
    }
    Uint8 ipad[64];
    for (int i = 0; i < 64; ++i)
    {
        ipad[i] = kb[i] ^ 0x36;
        h->opad_key[i] = kb[i] ^ 0x5c;
    }
    Sha256Init(&h->inner);
    Sha256Update(&h->inner, ipad, 64);
}

static void HmacUpdate(HmacCtx *h, const void *data, size_t len)
{
    Sha256Update(&h->inner, data, len);
}

static void HmacFinal(HmacCtx *h, Uint8 digest[32])
{
    Uint8 inner_digest[32];
    Sha256Final(&h->inner, inner_digest);
    Sha256Ctx outer;
    Sha256Init(&outer);
    Sha256Update(&outer, h->opad_key, 64);
    Sha256Update(&outer, inner_digest, 32);
    Sha256Final(&outer, digest);
}

bool SDLStatic_HMACSHA256(const void *key, size_t keySize, const void *data, size_t dataSize,
                          Uint8 digest[32])
{
    if ((key == NULL && keySize > 0) || (data == NULL && dataSize > 0) || digest == NULL)
    {
        return SDL_InvalidParamError("key/data");
    }
    HmacCtx h;
    HmacInit(&h, key, keySize);
    HmacUpdate(&h, data, dataSize);
    HmacFinal(&h, digest);
    return true;
}

/* ------------------------------------------------------------- PBKDF2 --- */

static void Pbkdf2HmacSha256(const char *password, const Uint8 *salt, size_t saltLen,
                             Uint32 iterations, Uint8 *out, size_t outLen)
{
    const size_t passLen = SDL_strlen(password);
    Uint32 block_index = 1;
    while (outLen > 0)
    {
        Uint8 be[4] = {(Uint8)(block_index >> 24), (Uint8)(block_index >> 16),
                       (Uint8)(block_index >> 8), (Uint8)block_index};
        Uint8 u[32];
        Uint8 acc[32];
        HmacCtx h;
        HmacInit(&h, password, passLen);
        HmacUpdate(&h, salt, saltLen);
        HmacUpdate(&h, be, 4);
        HmacFinal(&h, u);
        SDL_memcpy(acc, u, 32);
        for (Uint32 i = 1; i < iterations; ++i)
        {
            HmacInit(&h, password, passLen);
            HmacUpdate(&h, u, 32);
            HmacFinal(&h, u);
            for (int k = 0; k < 32; ++k)
            {
                acc[k] ^= u[k];
            }
        }
        const size_t take = SDL_min(outLen, (size_t)32);
        SDL_memcpy(out, acc, take);
        out += take;
        outLen -= take;
        block_index++;
    }
}

/* ----------------------------------------------------------- ChaCha20 --- */

static Uint32 Rotl32(Uint32 v, int n)
{
    return (v << n) | (v >> (32 - n));
}

#define CHACHA_QR(a, b, c, d)                                                                      \
    do                                                                                             \
    {                                                                                              \
        (a) += (b);                                                                                \
        (d) = Rotl32((d) ^ (a), 16);                                                               \
        (c) += (d);                                                                                \
        (b) = Rotl32((b) ^ (c), 12);                                                               \
        (a) += (b);                                                                                \
        (d) = Rotl32((d) ^ (a), 8);                                                                \
        (c) += (d);                                                                                \
        (b) = Rotl32((b) ^ (c), 7);                                                                \
    } while (0)

static Uint32 LoadLE32(const Uint8 *p)
{
    return (Uint32)p[0] | ((Uint32)p[1] << 8) | ((Uint32)p[2] << 16) | ((Uint32)p[3] << 24);
}

static void ChaCha20Block(const Uint8 key[32], const Uint8 nonce[12], Uint32 counter,
                          Uint8 out[64])
{
    Uint32 state[16];
    state[0] = 0x61707865;
    state[1] = 0x3320646e;
    state[2] = 0x79622d32;
    state[3] = 0x6b206574;
    for (int i = 0; i < 8; ++i)
    {
        state[4 + i] = LoadLE32(key + i * 4);
    }
    state[12] = counter;
    state[13] = LoadLE32(nonce);
    state[14] = LoadLE32(nonce + 4);
    state[15] = LoadLE32(nonce + 8);

    Uint32 x[16];
    SDL_memcpy(x, state, sizeof(x));
    for (int round = 0; round < 10; ++round)
    {
        CHACHA_QR(x[0], x[4], x[8], x[12]);
        CHACHA_QR(x[1], x[5], x[9], x[13]);
        CHACHA_QR(x[2], x[6], x[10], x[14]);
        CHACHA_QR(x[3], x[7], x[11], x[15]);
        CHACHA_QR(x[0], x[5], x[10], x[15]);
        CHACHA_QR(x[1], x[6], x[11], x[12]);
        CHACHA_QR(x[2], x[7], x[8], x[13]);
        CHACHA_QR(x[3], x[4], x[9], x[14]);
    }
    for (int i = 0; i < 16; ++i)
    {
        const Uint32 v = x[i] + state[i];
        out[i * 4 + 0] = (Uint8)v;
        out[i * 4 + 1] = (Uint8)(v >> 8);
        out[i * 4 + 2] = (Uint8)(v >> 16);
        out[i * 4 + 3] = (Uint8)(v >> 24);
    }
}

static void ChaCha20Xor(const Uint8 key[32], const Uint8 nonce[12], Uint32 counter, Uint8 *buf,
                        size_t len)
{
    Uint8 stream[64];
    while (len > 0)
    {
        ChaCha20Block(key, nonce, counter++, stream);
        const size_t take = SDL_min(len, (size_t)64);
        for (size_t i = 0; i < take; ++i)
        {
            buf[i] ^= stream[i];
        }
        buf += take;
        len -= take;
    }
}

/* -------------------------------------------------------- entropy/tag --- */

/* Uniqueness-grade randomness for salts/nonces (documented: not a CSPRNG). */
static void FillEntropy(Uint8 *out, size_t len)
{
    static Uint64 counter = 0;
    Uint64 seed[4];
    seed[0] = SDL_GetPerformanceCounter();
    seed[1] = SDL_GetTicksNS();
    seed[2] = ++counter;
    seed[3] = (Uint64)(uintptr_t)out;
    Uint8 digest[32];
    while (len > 0)
    {
        SDLStatic_SHA256(seed, sizeof(seed), digest);
        const size_t take = SDL_min(len, (size_t)32);
        SDL_memcpy(out, digest, take);
        out += take;
        len -= take;
        seed[2] = ++counter;
        seed[0] ^= SDL_GetPerformanceCounter();
    }
}

static bool ConstantTimeEqual(const Uint8 *a, const Uint8 *b, size_t len)
{
    Uint8 diff = 0;
    for (size_t i = 0; i < len; ++i)
    {
        diff |= (Uint8)(a[i] ^ b[i]);
    }
    return diff == 0;
}

/* ------------------------------------------------------- public API ---- */

unsigned char *SDLStatic_EncryptData(const unsigned char *data, int dataSize,
                                     const char *password, int *outputSize)
{
    if (outputSize != NULL)
    {
        *outputSize = 0;
    }
    if ((data == NULL && dataSize > 0) || dataSize < 0 || password == NULL || outputSize == NULL)
    {
        SDL_InvalidParamError("data/password/outputSize");
        return NULL;
    }
    const size_t total = (size_t)SSE_HEADER_LEN + (size_t)dataSize + SSE_TAG_LEN;
    unsigned char *out = (unsigned char *)SDL_malloc(total > 0 ? total : 1);
    if (out == NULL)
    {
        return NULL;
    }

    SDL_memcpy(out, SSE_MAGIC, 4);
    Uint8 *salt = out + 4;
    Uint8 *nonce = out + 4 + SSE_SALT_LEN;
    Uint8 *body = out + SSE_HEADER_LEN;
    FillEntropy(salt, SSE_SALT_LEN + SSE_NONCE_LEN); /* fills salt then nonce */

    Uint8 dk[64];
    Pbkdf2HmacSha256(password, salt, SSE_SALT_LEN, SSE_PBKDF2_ITERATIONS, dk, sizeof(dk));

    if (dataSize > 0)
    {
        SDL_memcpy(body, data, (size_t)dataSize);
        ChaCha20Xor(dk, nonce, 1, body, (size_t)dataSize);
    }

    /* Encrypt-then-MAC over everything before the tag. */
    Uint8 tag[SSE_TAG_LEN];
    SDLStatic_HMACSHA256(dk + 32, 32, out, SSE_HEADER_LEN + (size_t)dataSize, tag);
    SDL_memcpy(body + dataSize, tag, SSE_TAG_LEN);

    SDL_memset(dk, 0, sizeof(dk));
    *outputSize = (int)total;
    return out;
}

unsigned char *SDLStatic_DecryptData(const unsigned char *data, int dataSize,
                                     const char *password, int *outputSize)
{
    if (outputSize != NULL)
    {
        *outputSize = 0;
    }
    if (data == NULL || password == NULL || outputSize == NULL)
    {
        SDL_InvalidParamError("data/password/outputSize");
        return NULL;
    }
    if (dataSize < SSE_HEADER_LEN + SSE_TAG_LEN || SDL_memcmp(data, SSE_MAGIC, 4) != 0)
    {
        SDL_SetError("not SDLStatic encrypted data");
        return NULL;
    }
    const Uint8 *salt = data + 4;
    const Uint8 *nonce = data + 4 + SSE_SALT_LEN;
    const int plainSize = dataSize - SSE_HEADER_LEN - SSE_TAG_LEN;

    Uint8 dk[64];
    Pbkdf2HmacSha256(password, salt, SSE_SALT_LEN, SSE_PBKDF2_ITERATIONS, dk, sizeof(dk));

    Uint8 expected[SSE_TAG_LEN];
    SDLStatic_HMACSHA256(dk + 32, 32, data, (size_t)(SSE_HEADER_LEN + plainSize), expected);
    if (!ConstantTimeEqual(expected, data + SSE_HEADER_LEN + plainSize, SSE_TAG_LEN))
    {
        SDL_memset(dk, 0, sizeof(dk));
        SDL_SetError("wrong password or corrupted data");
        return NULL;
    }

    unsigned char *out = (unsigned char *)SDL_malloc(plainSize > 0 ? (size_t)plainSize : 1);
    if (out == NULL)
    {
        SDL_memset(dk, 0, sizeof(dk));
        return NULL;
    }
    if (plainSize > 0)
    {
        SDL_memcpy(out, data + SSE_HEADER_LEN, (size_t)plainSize);
        ChaCha20Xor(dk, nonce, 1, out, (size_t)plainSize);
    }
    SDL_memset(dk, 0, sizeof(dk));
    *outputSize = plainSize;
    return out;
}

/* --------------------------------------------------------- self-test --- */

bool SDLStatic_CryptoSelfTest(void)
{
    /* ChaCha20, RFC 8439 section 2.4.2. */
    static const Uint8 rfc_plain[] =
        "Ladies and Gentlemen of the class of '99: If I could offer you "
        "only one tip for the future, sunscreen would be it.";
    static const Uint8 rfc_expected[114] = {
        0x6e, 0x2e, 0x35, 0x9a, 0x25, 0x68, 0xf9, 0x80, 0x41, 0xba, 0x07, 0x28, 0xdd, 0x0d,
        0x69, 0x81, 0xe9, 0x7e, 0x7a, 0xec, 0x1d, 0x43, 0x60, 0xc2, 0x0a, 0x27, 0xaf, 0xcc,
        0xfd, 0x9f, 0xae, 0x0b, 0xf9, 0x1b, 0x65, 0xc5, 0x52, 0x47, 0x33, 0xab, 0x8f, 0x59,
        0x3d, 0xab, 0xcd, 0x62, 0xb3, 0x57, 0x16, 0x39, 0xd6, 0x24, 0xe6, 0x51, 0x52, 0xab,
        0x8f, 0x53, 0x0c, 0x35, 0x9f, 0x08, 0x61, 0xd8, 0x07, 0xca, 0x0d, 0xbf, 0x50, 0x0d,
        0x6a, 0x61, 0x56, 0xa3, 0x8e, 0x08, 0x8a, 0x22, 0xb6, 0x5e, 0x52, 0xbc, 0x51, 0x4d,
        0x16, 0xcc, 0xf8, 0x06, 0x81, 0x8c, 0xe9, 0x1a, 0xb7, 0x79, 0x37, 0x36, 0x5a, 0xf9,
        0x0b, 0xbf, 0x74, 0xa3, 0x5b, 0xe6, 0xb4, 0x0b, 0x8e, 0xed, 0xf2, 0x78, 0x5e, 0x42,
        0x87, 0x4d};
    Uint8 key[32];
    for (int i = 0; i < 32; ++i)
    {
        key[i] = (Uint8)i;
    }
    static const Uint8 nonce[12] = {0, 0, 0, 0, 0, 0, 0, 0x4a, 0, 0, 0, 0};
    Uint8 buf[114];
    SDL_memcpy(buf, rfc_plain, sizeof(buf));
    ChaCha20Xor(key, nonce, 1, buf, sizeof(buf));
    if (SDL_memcmp(buf, rfc_expected, sizeof(buf)) != 0)
    {
        return SDL_SetError("ChaCha20 RFC 8439 vector mismatch");
    }

    /* PBKDF2-HMAC-SHA256, standard vectors (password/salt, c=1 and c=2). */
    static const Uint8 pbkdf2_c1[32] = {
        0x12, 0x0f, 0xb6, 0xcf, 0xfc, 0xf8, 0xb3, 0x2c, 0x43, 0xe7, 0x22, 0x52, 0x56, 0xc4,
        0xf8, 0x37, 0xa8, 0x65, 0x48, 0xc9, 0x2c, 0xcc, 0x35, 0x48, 0x08, 0x05, 0x98, 0x7c,
        0xb7, 0x0b, 0xe1, 0x7b};
    static const Uint8 pbkdf2_c2[32] = {
        0xae, 0x4d, 0x0c, 0x95, 0xaf, 0x6b, 0x46, 0xd3, 0x2d, 0x0a, 0xdf, 0xf9, 0x28, 0xf0,
        0x6d, 0xd0, 0x2a, 0x30, 0x3f, 0x8e, 0xf3, 0xc2, 0x51, 0xdf, 0xd6, 0xe2, 0xd8, 0x5a,
        0x95, 0x47, 0x4c, 0x43};
    Uint8 dk[32];
    Pbkdf2HmacSha256("password", (const Uint8 *)"salt", 4, 1, dk, sizeof(dk));
    if (SDL_memcmp(dk, pbkdf2_c1, sizeof(dk)) != 0)
    {
        return SDL_SetError("PBKDF2 c=1 vector mismatch");
    }
    Pbkdf2HmacSha256("password", (const Uint8 *)"salt", 4, 2, dk, sizeof(dk));
    if (SDL_memcmp(dk, pbkdf2_c2, sizeof(dk)) != 0)
    {
        return SDL_SetError("PBKDF2 c=2 vector mismatch");
    }
    return true;
}
