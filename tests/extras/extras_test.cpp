/**
 * @file extras_test.cpp
 * @brief Tests for SDLStatic::Extras — crypto, compression, base64, signals.
 *
 * The crypto primitives are pinned to published test vectors (FIPS 180-4,
 * RFC 4231, RFC 8439, the standard PBKDF2-HMAC-SHA256 vectors), so a wrong
 * implementation cannot pass. Container-level tests then prove round-trips,
 * wrong-password rejection, and tamper detection.
 */

#include <SDL3/SDL.h>
#include <SDLStatic/base64.h>
#include <SDLStatic/compress.h>
#include <SDLStatic/crypto.h>
#include <SDLStatic/signals.h>
#include <gtest/gtest.h>

#include <cstring>
#include <string>
#include <vector>

namespace
{

std::string Hex(const Uint8 *data, size_t len)
{
    static const char digits[] = "0123456789abcdef";
    std::string out;
    for (size_t i = 0; i < len; ++i)
    {
        out.push_back(digits[data[i] >> 4]);
        out.push_back(digits[data[i] & 15]);
    }
    return out;
}

/* ------------------------------------------------------------- crypto --- */

TEST(Sha256, MatchesPublishedVectors)
{
    Uint8 digest[32];
    ASSERT_TRUE(SDLStatic_SHA256("abc", 3, digest));
    EXPECT_EQ(Hex(digest, 32), "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");

    ASSERT_TRUE(SDLStatic_SHA256("", 0, digest));
    EXPECT_EQ(Hex(digest, 32), "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");

    // Two-block message (FIPS 180-4 example).
    const char *msg = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
    ASSERT_TRUE(SDLStatic_SHA256(msg, std::strlen(msg), digest));
    EXPECT_EQ(Hex(digest, 32), "248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1");

    // A million 'a's exercises long-message length handling.
    std::vector<Uint8> million(1000000, 'a');
    ASSERT_TRUE(SDLStatic_SHA256(million.data(), million.size(), digest));
    EXPECT_EQ(Hex(digest, 32), "cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0");
}

TEST(Sha256, HmacMatchesRfc4231)
{
    Uint8 digest[32];
    Uint8 key[20];
    SDL_memset(key, 0x0b, sizeof(key));
    ASSERT_TRUE(SDLStatic_HMACSHA256(key, sizeof(key), "Hi There", 8, digest));
    EXPECT_EQ(Hex(digest, 32), "b0344c61d8db38535ca8afceaf0bf12b881dc200c9833da726e9376c2e32cff7");

    // Test case 2: key "Jefe", data "what do ya want for nothing?".
    ASSERT_TRUE(SDLStatic_HMACSHA256("Jefe", 4, "what do ya want for nothing?", 28, digest));
    EXPECT_EQ(Hex(digest, 32), "5bdcc146bf60754e6a042426089575c75a003f089d2739839dec58b964ec3843");

    // Test case 3: 0xaa*20 key, 0xdd*50 data.
    Uint8 key3[20];
    Uint8 data3[50];
    SDL_memset(key3, 0xaa, sizeof(key3));
    SDL_memset(data3, 0xdd, sizeof(data3));
    ASSERT_TRUE(SDLStatic_HMACSHA256(key3, sizeof(key3), data3, sizeof(data3), digest));
    EXPECT_EQ(Hex(digest, 32), "773ea91e36800e46854db8ebd09181a72959098b3ef8c122d9635514ced565fe");
}

TEST(Crypto, SelfTestPinsChaCha20AndPbkdf2ToPublishedVectors)
{
    EXPECT_TRUE(SDLStatic_CryptoSelfTest()) << SDL_GetError();
}

TEST(Crypto, EncryptDecryptRoundTrip)
{
    const char *payload = "level_01.png pretend-bytes \x01\x02\x03 with zero \x00 inside";
    const int payloadSize = 48;
    int encSize = 0;
    unsigned char *enc = SDLStatic_EncryptData(reinterpret_cast<const unsigned char *>(payload),
                                               payloadSize, "hunter2", &encSize);
    ASSERT_NE(enc, nullptr) << SDL_GetError();
    EXPECT_EQ(encSize, 4 + 16 + 12 + payloadSize + 32);
    EXPECT_EQ(SDL_memcmp(enc, "SSE1", 4), 0);
    // Ciphertext must not contain the plaintext.
    bool same = SDL_memcmp(enc + 32, payload, payloadSize) == 0;
    EXPECT_FALSE(same);

    int decSize = 0;
    unsigned char *dec = SDLStatic_DecryptData(enc, encSize, "hunter2", &decSize);
    ASSERT_NE(dec, nullptr) << SDL_GetError();
    ASSERT_EQ(decSize, payloadSize);
    EXPECT_EQ(SDL_memcmp(dec, payload, static_cast<size_t>(payloadSize)), 0);

    SDL_free(dec);
    SDL_free(enc);
}

TEST(Crypto, WrongPasswordAndTamperingAreRejected)
{
    const unsigned char payload[] = "top secret map data";
    int encSize = 0;
    unsigned char *enc = SDLStatic_EncryptData(payload, sizeof(payload), "correct", &encSize);
    ASSERT_NE(enc, nullptr);

    int size = 0;
    EXPECT_EQ(SDLStatic_DecryptData(enc, encSize, "incorrect", &size), nullptr)
        << "wrong password must fail";

    // Flip one ciphertext bit: MAC must catch it.
    enc[4 + 16 + 12 + 3] ^= 0x40;
    EXPECT_EQ(SDLStatic_DecryptData(enc, encSize, "correct", &size), nullptr)
        << "tampered data must fail";
    enc[4 + 16 + 12 + 3] ^= 0x40;

    // Flip a tag bit instead.
    enc[encSize - 1] ^= 0x01;
    EXPECT_EQ(SDLStatic_DecryptData(enc, encSize, "correct", &size), nullptr)
        << "tampered tag must fail";
    enc[encSize - 1] ^= 0x01;

    // Sanity: untouched buffer still decrypts.
    unsigned char *dec = SDLStatic_DecryptData(enc, encSize, "correct", &size);
    EXPECT_NE(dec, nullptr);
    SDL_free(dec);
    SDL_free(enc);

    // Truncated/garbage inputs fail cleanly.
    EXPECT_EQ(SDLStatic_DecryptData(payload, sizeof(payload), "x", &size), nullptr);
    EXPECT_EQ(SDLStatic_EncryptData(payload, -1, "x", &size), nullptr);
}

TEST(Crypto, UniqueSaltsProduceDifferentCiphertexts)
{
    const unsigned char payload[] = "same plaintext";
    int sizeA = 0;
    int sizeB = 0;
    unsigned char *a = SDLStatic_EncryptData(payload, sizeof(payload), "pw", &sizeA);
    unsigned char *b = SDLStatic_EncryptData(payload, sizeof(payload), "pw", &sizeB);
    ASSERT_NE(a, nullptr);
    ASSERT_NE(b, nullptr);
    ASSERT_EQ(sizeA, sizeB);
    EXPECT_NE(SDL_memcmp(a, b, static_cast<size_t>(sizeA)), 0)
        << "fresh salt/nonce must randomize output";
    SDL_free(a);
    SDL_free(b);
}

TEST(Crypto, EmptyPayloadRoundTrips)
{
    int encSize = 0;
    unsigned char *enc = SDLStatic_EncryptData(nullptr, 0, "pw", &encSize);
    ASSERT_NE(enc, nullptr) << SDL_GetError();
    int decSize = -1;
    unsigned char *dec = SDLStatic_DecryptData(enc, encSize, "pw", &decSize);
    ASSERT_NE(dec, nullptr) << SDL_GetError();
    EXPECT_EQ(decSize, 0);
    SDL_free(dec);
    SDL_free(enc);
}

/* -------------------------------------------------------- compression --- */

TEST(Compress, RoundTripsCompressibleData)
{
    std::string text;
    for (int i = 0; i < 500; ++i)
    {
        text += "the quick brown fox jumps over the lazy dog. ";
    }
    int compSize = 0;
    unsigned char *comp = SDLStatic_CompressData(
        reinterpret_cast<const unsigned char *>(text.data()), static_cast<int>(text.size()),
        &compSize);
    ASSERT_NE(comp, nullptr) << SDL_GetError();
    EXPECT_LT(compSize, static_cast<int>(text.size()) / 4) << "repetitive text should shrink a lot";

    int plainSize = 0;
    unsigned char *plain = SDLStatic_DecompressData(comp, compSize, &plainSize);
    ASSERT_NE(plain, nullptr) << SDL_GetError();
    ASSERT_EQ(plainSize, static_cast<int>(text.size()));
    EXPECT_EQ(SDL_memcmp(plain, text.data(), text.size()), 0);

    SDL_free(plain);
    SDL_free(comp);
}

TEST(Compress, RoundTripsIncompressibleAndEmptyData)
{
    // Deterministic pseudo-random bytes barely compress but must round-trip.
    std::vector<unsigned char> noise(100000);
    Uint32 rng = 0x12345678u;
    for (auto &byte : noise)
    {
        rng ^= rng << 13;
        rng ^= rng >> 17;
        rng ^= rng << 5;
        byte = static_cast<unsigned char>(rng);
    }
    int compSize = 0;
    unsigned char *comp =
        SDLStatic_CompressData(noise.data(), static_cast<int>(noise.size()), &compSize);
    ASSERT_NE(comp, nullptr);
    int plainSize = 0;
    unsigned char *plain = SDLStatic_DecompressData(comp, compSize, &plainSize);
    ASSERT_NE(plain, nullptr);
    ASSERT_EQ(plainSize, static_cast<int>(noise.size()));
    EXPECT_EQ(SDL_memcmp(plain, noise.data(), noise.size()), 0);
    SDL_free(plain);
    SDL_free(comp);

    int emptyCompSize = 0;
    unsigned char *emptyComp = SDLStatic_CompressData(nullptr, 0, &emptyCompSize);
    ASSERT_NE(emptyComp, nullptr) << SDL_GetError();
    int emptySize = -1;
    unsigned char *empty = SDLStatic_DecompressData(emptyComp, emptyCompSize, &emptySize);
    ASSERT_NE(empty, nullptr) << SDL_GetError();
    EXPECT_EQ(emptySize, 0);
    SDL_free(empty);
    SDL_free(emptyComp);
}

TEST(Compress, RejectsCorruptedInput)
{
    const unsigned char payload[] = "some data worth compressing some data worth compressing";
    int compSize = 0;
    unsigned char *comp = SDLStatic_CompressData(payload, sizeof(payload), &compSize);
    ASSERT_NE(comp, nullptr);

    int size = 0;
    EXPECT_EQ(SDLStatic_DecompressData(payload, sizeof(payload), &size), nullptr)
        << "not our container";
    EXPECT_EQ(SDLStatic_DecompressData(comp, 6, &size), nullptr) << "truncated header";
    EXPECT_EQ(SDLStatic_DecompressData(comp, compSize / 2, &size), nullptr)
        << "truncated stream";

    // Corrupt the size header so it disagrees with the stream.
    comp[4] ^= 0xff;
    EXPECT_EQ(SDLStatic_DecompressData(comp, compSize, &size), nullptr) << "size mismatch";
    comp[4] ^= 0xff;

    int okSize = 0;
    unsigned char *ok = SDLStatic_DecompressData(comp, compSize, &okSize);
    EXPECT_NE(ok, nullptr);
    SDL_free(ok);
    SDL_free(comp);
}

/* ------------------------------------------------------------- base64 --- */

TEST(Base64, MatchesRfc4648Vectors)
{
    const struct
    {
        const char *plain;
        const char *encoded;
    } cases[] = {
        {"", ""},        {"f", "Zg=="},     {"fo", "Zm8="},     {"foo", "Zm9v"},
        {"foob", "Zm9vYg=="}, {"fooba", "Zm9vYmE="}, {"foobar", "Zm9vYmFy"},
    };
    for (const auto &c : cases)
    {
        int outSize = -1;
        char *encoded = SDLStatic_EncodeDataBase64(
            reinterpret_cast<const unsigned char *>(c.plain),
            static_cast<int>(std::strlen(c.plain)), &outSize);
        ASSERT_NE(encoded, nullptr) << c.plain;
        EXPECT_STREQ(encoded, c.encoded);
        EXPECT_EQ(outSize, static_cast<int>(std::strlen(c.encoded)));

        int decSize = -1;
        unsigned char *decoded = SDLStatic_DecodeDataBase64(c.encoded, &decSize);
        ASSERT_NE(decoded, nullptr) << c.encoded;
        ASSERT_EQ(decSize, static_cast<int>(std::strlen(c.plain)));
        EXPECT_EQ(SDL_memcmp(decoded, c.plain, static_cast<size_t>(decSize)), 0);
        SDL_free(decoded);
        SDL_free(encoded);
    }
}

TEST(Base64, RoundTripsBinaryAndSkipsWhitespace)
{
    std::vector<unsigned char> all(256);
    for (int i = 0; i < 256; ++i)
    {
        all[static_cast<size_t>(i)] = static_cast<unsigned char>(i);
    }
    int encSize = 0;
    char *enc = SDLStatic_EncodeDataBase64(all.data(), 256, &encSize);
    ASSERT_NE(enc, nullptr);
    int decSize = 0;
    unsigned char *dec = SDLStatic_DecodeDataBase64(enc, &decSize);
    ASSERT_NE(dec, nullptr);
    ASSERT_EQ(decSize, 256);
    EXPECT_EQ(SDL_memcmp(dec, all.data(), 256), 0);
    SDL_free(dec);

    int wsSize = 0;
    unsigned char *ws = SDLStatic_DecodeDataBase64("Zm9v\nYmFy\r\n", &wsSize);
    ASSERT_NE(ws, nullptr) << SDL_GetError();
    ASSERT_EQ(wsSize, 6);
    EXPECT_EQ(SDL_memcmp(ws, "foobar", 6), 0);
    SDL_free(ws);
    SDL_free(enc);
}

TEST(Base64, RejectsInvalidInput)
{
    int size = 0;
    EXPECT_EQ(SDLStatic_DecodeDataBase64("Zm9v!", &size), nullptr) << "invalid character";
    EXPECT_EQ(SDLStatic_DecodeDataBase64("Zg==Zg==", &size), nullptr) << "data after padding";
    EXPECT_EQ(SDLStatic_DecodeDataBase64("Z", &size), nullptr) << "truncated";
    EXPECT_EQ(SDLStatic_DecodeDataBase64(nullptr, &size), nullptr);
    EXPECT_EQ(SDLStatic_EncodeDataBase64(nullptr, 5, &size), nullptr);
}

/* ------------------------------------------------------------ signals --- */

struct SignalLog
{
    std::vector<std::string> entries;
    SDLStatic_SignalEmitter *emitter = nullptr;
    Uint64 self_id = 0;
};

void LogA(void *userdata, const char *signal, void *args)
{
    static_cast<SignalLog *>(userdata)->entries.push_back(std::string("A:") + signal +
                                                          (args ? ":arg" : ""));
}

void LogB(void *userdata, const char *signal, void * /*args*/)
{
    static_cast<SignalLog *>(userdata)->entries.push_back(std::string("B:") + signal);
}

TEST(Signals, EmitInvokesConnectionsInOrder)
{
    SDLStatic_SignalEmitter *emitter = SDLStatic_CreateSignalEmitter();
    ASSERT_NE(emitter, nullptr);
    SignalLog log;
    ASSERT_NE(SDLStatic_ConnectSignal(emitter, "hit", LogA, &log, 0), 0u);
    ASSERT_NE(SDLStatic_ConnectSignal(emitter, "hit", LogB, &log, 0), 0u);
    ASSERT_NE(SDLStatic_ConnectSignal(emitter, "died", LogB, &log, 0), 0u);

    int payload = 42;
    EXPECT_EQ(SDLStatic_EmitSignal(emitter, "hit", &payload), 2);
    EXPECT_EQ(SDLStatic_EmitSignal(emitter, "died", nullptr), 1);
    EXPECT_EQ(SDLStatic_EmitSignal(emitter, "unknown", nullptr), 0);

    const std::vector<std::string> expected = {"A:hit:arg", "B:hit", "B:died"};
    EXPECT_EQ(log.entries, expected);
    EXPECT_EQ(SDLStatic_CountSignalConnections(emitter, nullptr), 3);
    EXPECT_EQ(SDLStatic_CountSignalConnections(emitter, "hit"), 2);
    SDLStatic_DestroySignalEmitter(emitter);
}

TEST(Signals, DisconnectAndOneShot)
{
    SDLStatic_SignalEmitter *emitter = SDLStatic_CreateSignalEmitter();
    SignalLog log;
    const Uint64 a = SDLStatic_ConnectSignal(emitter, "tick", LogA, &log, 0);
    SDLStatic_ConnectSignal(emitter, "tick", LogB, &log, SDLSTATIC_SIGNAL_ONESHOT);

    EXPECT_EQ(SDLStatic_EmitSignal(emitter, "tick", nullptr), 2);
    EXPECT_EQ(SDLStatic_EmitSignal(emitter, "tick", nullptr), 1) << "one-shot must be gone";
    EXPECT_EQ(SDLStatic_CountSignalConnections(emitter, "tick"), 1);

    EXPECT_TRUE(SDLStatic_DisconnectSignal(emitter, a));
    EXPECT_FALSE(SDLStatic_DisconnectSignal(emitter, a)) << "double disconnect";
    EXPECT_EQ(SDLStatic_EmitSignal(emitter, "tick", nullptr), 0);
    SDLStatic_DestroySignalEmitter(emitter);
}

void SelfDisconnect(void *userdata, const char * /*signal*/, void * /*args*/)
{
    SignalLog *log = static_cast<SignalLog *>(userdata);
    log->entries.push_back("self");
    SDLStatic_DisconnectSignal(log->emitter, log->self_id);
}

void ConnectAnother(void *userdata, const char * /*signal*/, void * /*args*/)
{
    SignalLog *log = static_cast<SignalLog *>(userdata);
    log->entries.push_back("connector");
    SDLStatic_ConnectSignal(log->emitter, "evt", LogB, log, 0);
}

TEST(Signals, ReentrantMutationDuringEmitIsSafe)
{
    SDLStatic_SignalEmitter *emitter = SDLStatic_CreateSignalEmitter();
    SignalLog log;
    log.emitter = emitter;

    // Handler that disconnects itself mid-emit.
    log.self_id = SDLStatic_ConnectSignal(emitter, "evt", SelfDisconnect, &log, 0);
    // Handler that connects a new handler mid-emit (must not fire this pass).
    SDLStatic_ConnectSignal(emitter, "evt", ConnectAnother, &log, 0);

    EXPECT_EQ(SDLStatic_EmitSignal(emitter, "evt", nullptr), 2);
    const std::vector<std::string> first = {"self", "connector"};
    EXPECT_EQ(log.entries, first);

    // Next emission: self-disconnected handler gone, new handler fires.
    log.entries.clear();
    EXPECT_EQ(SDLStatic_EmitSignal(emitter, "evt", nullptr), 2);
    const std::vector<std::string> second = {"connector", "B:evt"};
    EXPECT_EQ(log.entries, second);

    SDLStatic_DestroySignalEmitter(emitter);
}

void NestedEmit(void *userdata, const char *signal, void * /*args*/)
{
    SignalLog *log = static_cast<SignalLog *>(userdata);
    log->entries.push_back(std::string("nested-from:") + signal);
    if (SDL_strcmp(signal, "outer") == 0)
    {
        SDLStatic_EmitSignal(log->emitter, "inner", nullptr);
    }
}

TEST(Signals, EmissionIsReentrant)
{
    SDLStatic_SignalEmitter *emitter = SDLStatic_CreateSignalEmitter();
    SignalLog log;
    log.emitter = emitter;
    SDLStatic_ConnectSignal(emitter, "outer", NestedEmit, &log, 0);
    SDLStatic_ConnectSignal(emitter, "inner", NestedEmit, &log, 0);

    EXPECT_EQ(SDLStatic_EmitSignal(emitter, "outer", nullptr), 1);
    const std::vector<std::string> expected = {"nested-from:outer", "nested-from:inner"};
    EXPECT_EQ(log.entries, expected);
    SDLStatic_DestroySignalEmitter(emitter);
}

TEST(Signals, RejectsBadInput)
{
    SDLStatic_SignalEmitter *emitter = SDLStatic_CreateSignalEmitter();
    EXPECT_EQ(SDLStatic_ConnectSignal(nullptr, "s", LogA, nullptr, 0), 0u);
    EXPECT_EQ(SDLStatic_ConnectSignal(emitter, nullptr, LogA, nullptr, 0), 0u);
    EXPECT_EQ(SDLStatic_ConnectSignal(emitter, "", LogA, nullptr, 0), 0u);
    EXPECT_EQ(SDLStatic_ConnectSignal(emitter, "s", nullptr, nullptr, 0), 0u);
    EXPECT_EQ(SDLStatic_EmitSignal(nullptr, "s", nullptr), -1);
    EXPECT_FALSE(SDLStatic_DisconnectSignal(emitter, 12345));
    EXPECT_EQ(SDLStatic_CountSignalConnections(nullptr, nullptr), 0);
    SDLStatic_DestroySignalEmitter(emitter);
    SDLStatic_DestroySignalEmitter(nullptr); // must be a safe no-op
}

/* ------------------------------------------- pipeline integration ------ */

TEST(Extras, CompressEncryptBase64Pipeline)
{
    // The full asset-baking pipeline: compress -> encrypt -> base64 -> back.
    std::string asset;
    for (int i = 0; i < 200; ++i)
    {
        asset += "tile" + std::to_string(i % 16) + ",";
    }
    int compSize = 0;
    unsigned char *comp = SDLStatic_CompressData(
        reinterpret_cast<const unsigned char *>(asset.data()), static_cast<int>(asset.size()),
        &compSize);
    ASSERT_NE(comp, nullptr);
    int encSize = 0;
    unsigned char *enc = SDLStatic_EncryptData(comp, compSize, "asset-key", &encSize);
    ASSERT_NE(enc, nullptr);
    int b64Size = 0;
    char *b64 = SDLStatic_EncodeDataBase64(enc, encSize, &b64Size);
    ASSERT_NE(b64, nullptr);

    int decB64Size = 0;
    unsigned char *decB64 = SDLStatic_DecodeDataBase64(b64, &decB64Size);
    ASSERT_NE(decB64, nullptr);
    ASSERT_EQ(decB64Size, encSize);
    int decSize = 0;
    unsigned char *dec = SDLStatic_DecryptData(decB64, decB64Size, "asset-key", &decSize);
    ASSERT_NE(dec, nullptr);
    ASSERT_EQ(decSize, compSize);
    int plainSize = 0;
    unsigned char *plain = SDLStatic_DecompressData(dec, decSize, &plainSize);
    ASSERT_NE(plain, nullptr);
    ASSERT_EQ(plainSize, static_cast<int>(asset.size()));
    EXPECT_EQ(SDL_memcmp(plain, asset.data(), asset.size()), 0);

    SDL_free(plain);
    SDL_free(dec);
    SDL_free(decB64);
    SDL_free(b64);
    SDL_free(enc);
    SDL_free(comp);
}

} // namespace
