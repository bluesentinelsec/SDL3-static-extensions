/**
 * @file vfs_test.cpp
 * @brief Tests for SDLStatic::VFS — vendored PhysFS (ZIP-only) + glue.
 *
 * The corpus (tests/vfs/assets) is built by scripts/pack_assets.py: a
 * deterministic zip and the same zip in the SSE1 encrypted container.
 * The encryption was performed by the *Python* implementation, so mounting
 * it here cross-validates the C and Python SSE1 implementations.
 */

#include <SDL3/SDL.h>
#include <SDLStatic/crypto.h>
#include <SDLStatic/vfs.h>
#include <gtest/gtest.h>
#include <physfs.h>

#include <cstring>
#include <string>
#include <vector>

#ifndef VFS_TEST_ASSETS_DIR
#error "VFS_TEST_ASSETS_DIR must be defined by the build"
#endif

namespace
{

std::string AssetPath(const char *name)
{
    return std::string(VFS_TEST_ASSETS_DIR) + "/" + name;
}

std::vector<unsigned char> ReadHostFile(const char *name)
{
    size_t size = 0;
    void *data = SDL_LoadFile(AssetPath(name).c_str(), &size);
    EXPECT_NE(data, nullptr) << name;
    std::vector<unsigned char> out;
    if (data != nullptr)
    {
        out.assign(static_cast<unsigned char *>(data),
                   static_cast<unsigned char *>(data) + size);
        SDL_free(data);
    }
    return out;
}

class VfsFoundation : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        ASSERT_TRUE(PHYSFS_init(nullptr)) << PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode());
    }
    void TearDown() override
    {
        PHYSFS_deinit();
    }
};

TEST_F(VfsFoundation, OnlyZipSupportRemains)
{
    PHYSFS_Version version;
    PHYSFS_getLinkedVersion(&version);
    EXPECT_EQ(version.major, 3);
    EXPECT_EQ(version.minor, 2);

    bool has_zip = false;
    for (const PHYSFS_ArchiveInfo **info = PHYSFS_supportedArchiveTypes(); *info != nullptr;
         ++info)
    {
        const std::string ext = (*info)->extension;
        if (ext == "ZIP" || ext == "zip")
        {
            has_zip = true;
        }
        else
        {
            ADD_FAILURE() << "unexpected archiver still compiled in: " << ext;
        }
    }
    EXPECT_TRUE(has_zip) << "ZIP support must be present";
}

TEST_F(VfsFoundation, MountsZipFromDiskAndReadsExactContents)
{
    ASSERT_TRUE(PHYSFS_mount(AssetPath("media.zip").c_str(), "/", 1))
        << PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode());

    // Text file, exact bytes.
    int size = 0;
    unsigned char *hello = SDLStatic_LoadVFSFile("hello.txt", &size);
    ASSERT_NE(hello, nullptr) << SDL_GetError();
    EXPECT_EQ(std::string(reinterpret_cast<char *>(hello), static_cast<size_t>(size)),
              "Hello from the vault!\n");
    SDL_free(hello);

    // Nested paths and binary integrity.
    unsigned char *hero = SDLStatic_LoadVFSFile("sprites/hero.dat", &size);
    ASSERT_NE(hero, nullptr) << SDL_GetError();
    ASSERT_EQ(size, 256);
    for (int i = 0; i < 256; ++i)
    {
        ASSERT_EQ(hero[i], static_cast<unsigned char>(i)) << "byte " << i;
    }
    SDL_free(hero);

    // Enumeration sees all three files.
    EXPECT_NE(PHYSFS_exists("config/level.json"), 0);
    char **files = PHYSFS_enumerateFiles("/");
    int count = 0;
    for (char **f = files; *f != nullptr; ++f)
    {
        count++;
    }
    PHYSFS_freeList(files);
    EXPECT_EQ(count, 3) << "hello.txt + sprites/ + config/";
}

TEST_F(VfsFoundation, MountsZipImageFromMemory)
{
    const std::vector<unsigned char> zip = ReadHostFile("media.zip");
    ASSERT_FALSE(zip.empty());
    ASSERT_TRUE(PHYSFS_mountMemory(zip.data(), zip.size(), nullptr, "media.zip", "/mem", 1))
        << PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode());

    int size = 0;
    unsigned char *json = SDLStatic_LoadVFSFile("/mem/config/level.json", &size);
    ASSERT_NE(json, nullptr) << SDL_GetError();
    EXPECT_NE(std::strstr(reinterpret_cast<char *>(json), "kraken"), nullptr);
    SDL_free(json);
    ASSERT_TRUE(PHYSFS_unmount("media.zip"));
}

TEST_F(VfsFoundation, MountsPythonEncryptedArchive)
{
    // Encrypted by scripts/pack_assets.py (Python SSE1); decrypted by the C
    // implementation here — cross-validating both.
    const std::vector<unsigned char> blob = ReadHostFile("media_encrypted.bin");
    ASSERT_FALSE(blob.empty());
    ASSERT_TRUE(SDLStatic_MountEncryptedArchive(blob.data(), static_cast<int>(blob.size()),
                                                "openSesame", "/vault"))
        << SDL_GetError();

    int size = 0;
    unsigned char *hello = SDLStatic_LoadVFSFile("/vault/hello.txt", &size);
    ASSERT_NE(hello, nullptr) << SDL_GetError();
    EXPECT_EQ(std::string(reinterpret_cast<char *>(hello), static_cast<size_t>(size)),
              "Hello from the vault!\n");
    SDL_free(hello);
}

TEST_F(VfsFoundation, EncryptedMountRejectsWrongPasswordAndGarbage)
{
    const std::vector<unsigned char> blob = ReadHostFile("media_encrypted.bin");
    ASSERT_FALSE(blob.empty());
    EXPECT_FALSE(SDLStatic_MountEncryptedArchive(blob.data(), static_cast<int>(blob.size()),
                                                 "wrongPassword", "/vault"));

    // Valid password but payload isn't a zip: encrypt junk on the fly.
    int encSize = 0;
    const unsigned char junk[] = "this is not a zip archive at all";
    unsigned char *enc = SDLStatic_EncryptData(junk, sizeof(junk), "pw", &encSize);
    ASSERT_NE(enc, nullptr);
    EXPECT_FALSE(SDLStatic_MountEncryptedArchive(enc, encSize, "pw", "/junk"));
    SDL_free(enc);

    EXPECT_FALSE(SDLStatic_MountEncryptedArchive(nullptr, 0, "pw", "/x"));
    EXPECT_FALSE(SDLStatic_MountEncryptedArchiveFile(AssetPath("missing.bin").c_str(), "pw",
                                                     "/x"));
}

TEST_F(VfsFoundation, EncryptedMountFromFileWorks)
{
    ASSERT_TRUE(SDLStatic_MountEncryptedArchiveFile(AssetPath("media_encrypted.bin").c_str(),
                                                    "openSesame", nullptr))
        << SDL_GetError();
    EXPECT_NE(PHYSFS_exists("sprites/hero.dat"), 0);
}

TEST_F(VfsFoundation, IoStreamBridgeSupportsSizeSeekRead)
{
    ASSERT_TRUE(PHYSFS_mount(AssetPath("media.zip").c_str(), "/", 1));
    SDL_IOStream *stream = SDLStatic_OpenVFSRead("hello.txt");
    ASSERT_NE(stream, nullptr) << SDL_GetError();

    EXPECT_EQ(SDL_GetIOSize(stream), 22);

    // Seek into the middle and read the tail.
    ASSERT_EQ(SDL_SeekIO(stream, 6, SDL_IO_SEEK_SET), 6);
    char tail[32] = {};
    const size_t got = SDL_ReadIO(stream, tail, sizeof(tail));
    EXPECT_EQ(got, 16u);
    EXPECT_STREQ(tail, "from the vault!\n");

    // Relative and end-based seeks.
    ASSERT_EQ(SDL_SeekIO(stream, -7, SDL_IO_SEEK_END), 15);
    char word[7] = {};
    ASSERT_EQ(SDL_ReadIO(stream, word, 6), 6u);
    EXPECT_STREQ(word, "vault!");

    // Whole-file convenience through the SDL loader on top of the bridge.
    ASSERT_EQ(SDL_SeekIO(stream, 0, SDL_IO_SEEK_SET), 0);
    size_t all = 0;
    void *data = SDL_LoadFile_IO(stream, &all, true); // closes the stream
    ASSERT_NE(data, nullptr);
    EXPECT_EQ(all, 22u);
    SDL_free(data);

    // Writes must be refused on a fresh stream.
    SDL_IOStream *ro = SDLStatic_OpenVFSRead("hello.txt");
    ASSERT_NE(ro, nullptr);
    EXPECT_EQ(SDL_WriteIO(ro, "x", 1), 0u);
    SDL_CloseIO(ro);
}

TEST_F(VfsFoundation, MalformedZipImagesFailCleanly)
{
    const std::vector<unsigned char> zip = ReadHostFile("media.zip");
    ASSERT_FALSE(zip.empty());

    for (const double fraction : {0.1, 0.25, 0.5, 0.9})
    {
        std::vector<unsigned char> cut(
            zip.begin(),
            zip.begin() + static_cast<std::ptrdiff_t>(static_cast<double>(zip.size()) * fraction));
        if (PHYSFS_mountMemory(cut.data(), cut.size(), nullptr, "cut.zip", "/fuzz", 1))
        {
            PHYSFS_unmount("cut.zip"); /* partial zips may still mount */
        }
    }
    Uint32 rng = 0xDEFACED1u;
    for (int round = 0; round < 8; ++round)
    {
        std::vector<unsigned char> mutated = zip;
        for (int i = 0; i < 8; ++i)
        {
            rng ^= rng << 13;
            rng ^= rng >> 17;
            rng ^= rng << 5;
            mutated[rng % mutated.size()] ^= static_cast<unsigned char>(1u << (rng % 8));
        }
        if (PHYSFS_mountMemory(mutated.data(), mutated.size(), nullptr, "fuzz.zip", "/fuzz", 1))
        {
            /* if it mounted, reading through it must not crash either */
            int size = 0;
            unsigned char *data = SDLStatic_LoadVFSFile("/fuzz/hello.txt", &size);
            SDL_free(data);
            PHYSFS_unmount("fuzz.zip");
        }
    }
    SUCCEED();
}

} // namespace
