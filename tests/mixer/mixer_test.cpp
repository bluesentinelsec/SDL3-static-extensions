/**
 * @file mixer_test.cpp
 * @brief Tests for SDLStatic::Mixer (vendored SDL_mixer, static decoders only).
 *
 * Runs fully headless: MIX_CreateMixer needs no audio device, and
 * MIX_Generate pulls mixed samples on demand, so decode and playback
 * correctness are asserted deterministically (real signal energy, not just
 * non-NULL). Corpus: synthesized sfx + chiptune loop in every enabled
 * format (see assets/README.md; regenerate with scripts/gen_test_audio.py).
 */

#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <gtest/gtest.h>

#include <cmath>
#include <string>
#include <vector>

#ifndef MIXER_TEST_ASSETS_DIR
#error "MIXER_TEST_ASSETS_DIR must be defined by the build"
#endif

namespace
{

std::string AssetPath(const char *name)
{
    return std::string(MIXER_TEST_ASSETS_DIR) + "/" + name;
}

class MixerFoundation : public ::testing::Test
{
  protected:
    static void SetUpTestSuite()
    {
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
        ASSERT_TRUE(MIX_Init()) << SDL_GetError();
    }
    static void TearDownTestSuite()
    {
        MIX_Quit();
        SDL_Quit();
    }

    void SetUp() override
    {
        SDL_AudioSpec spec = {SDL_AUDIO_F32, 2, 44100};
        mixer_ = MIX_CreateMixer(&spec);
        ASSERT_NE(mixer_, nullptr) << SDL_GetError();
    }
    void TearDown() override
    {
        if (mixer_ != nullptr)
        {
            MIX_DestroyMixer(mixer_);
        }
    }

    MIX_Mixer *mixer_ = nullptr;
};

TEST_F(MixerFoundation, VersionAndDecodersAreWired)
{
    EXPECT_GE(MIX_Version(), SDL_VERSIONNUM(3, 2, 4));
    const int n = MIX_GetNumAudioDecoders();
    ASSERT_GT(n, 0);
    std::vector<std::string> names;
    for (int i = 0; i < n; ++i)
    {
        names.emplace_back(MIX_GetAudioDecoder(i));
    }
    auto has = [&names](const char *name) {
        for (const std::string &d : names)
        {
            if (d == name)
            {
                return true;
            }
        }
        return false;
    };
    EXPECT_TRUE(has("WAV"));
    EXPECT_TRUE(has("STBVORBIS"));
    EXPECT_TRUE(has("DRMP3"));
    EXPECT_TRUE(has("DRFLAC"));
    // Removed decoders must be gone entirely.
    EXPECT_FALSE(has("VORBIS"));
    EXPECT_FALSE(has("MPG123"));
    EXPECT_FALSE(has("FLAC"));
    EXPECT_FALSE(has("OPUS"));
    EXPECT_FALSE(has("GME"));
    EXPECT_FALSE(has("XMP"));
    EXPECT_FALSE(has("WAVPACK"));
    EXPECT_FALSE(has("FLUIDSYNTH"));
}

struct FormatCase
{
    const char *file;
    double expected_seconds;  // < 0: only assert duration is positive
};

class DecodeFormats : public MixerFoundation, public ::testing::WithParamInterface<FormatCase>
{
};

TEST_P(DecodeFormats, LoadsAndReportsDuration)
{
    MIX_Audio *audio = MIX_LoadAudio(mixer_, AssetPath(GetParam().file).c_str(), true);
    ASSERT_NE(audio, nullptr) << GetParam().file << ": " << SDL_GetError();

    SDL_AudioSpec spec;
    ASSERT_TRUE(MIX_GetAudioFormat(audio, &spec)) << SDL_GetError();
    EXPECT_GT(spec.freq, 0) << GetParam().file;
    EXPECT_GT(spec.channels, 0) << GetParam().file;

    const Sint64 frames = MIX_GetAudioDuration(audio);
    ASSERT_GT(frames, 0) << GetParam().file;
    if (GetParam().expected_seconds > 0)
    {
        const double seconds = static_cast<double>(frames) / spec.freq;
        EXPECT_NEAR(seconds, GetParam().expected_seconds, 0.15) << GetParam().file;
    }
    MIX_DestroyAudio(audio);
}

INSTANTIATE_TEST_SUITE_P(
    Corpus, DecodeFormats,
    ::testing::Values(FormatCase{"music_loop.wav", 6.4}, FormatCase{"music_loop.ogg", 6.4},
                      FormatCase{"music_loop.mp3", 6.4}, FormatCase{"music_loop.flac", 6.4},
                      FormatCase{"sfx_laser.wav", 0.3}, FormatCase{"sfx_explosion.wav", 0.65},
                      FormatCase{"sfx_coin.wav", 0.22}, FormatCase{"sfx_coin.aiff", 0.22},
                      FormatCase{"sfx_coin.au", 0.22}, FormatCase{"sfx_coin.voc", 0.22}),
    [](const ::testing::TestParamInfo<FormatCase> &param_info) {
        std::string name = param_info.param.file;
        for (char &c : name)
        {
            if (c == '.' || c == '-')
            {
                c = '_';
            }
        }
        return name;
    });

double GeneratedEnergy(MIX_Mixer *mixer, int frames)
{
    std::vector<float> buffer(static_cast<size_t>(frames) * 2);
    const int bytes = static_cast<int>(buffer.size() * sizeof(float));
    const int got = MIX_Generate(mixer, buffer.data(), bytes);
    if (got <= 0)
    {
        return -1.0;
    }
    double energy = 0.0;
    for (size_t i = 0; i < static_cast<size_t>(got) / sizeof(float); ++i)
    {
        energy += std::fabs(static_cast<double>(buffer[i]));
    }
    return energy;
}

TEST_F(MixerFoundation, PlaybackGeneratesRealSignal)
{
    MIX_Audio *audio = MIX_LoadAudio(mixer_, AssetPath("sfx_coin.wav").c_str(), true);
    ASSERT_NE(audio, nullptr) << SDL_GetError();
    MIX_Track *track = MIX_CreateTrack(mixer_);
    ASSERT_NE(track, nullptr) << SDL_GetError();
    ASSERT_TRUE(MIX_SetTrackAudio(track, audio)) << SDL_GetError();

    // Before playback: no data (MIX_Generate <= 0) or pure silence.
    EXPECT_LE(GeneratedEnergy(mixer_, 1024), 0.0);

    ASSERT_TRUE(MIX_PlayTrack(track, 0)) << SDL_GetError();
    EXPECT_TRUE(MIX_TrackPlaying(track));
    const double energy = GeneratedEnergy(mixer_, 4096);
    EXPECT_GT(energy, 10.0) << "playback produced no audible signal";

    ASSERT_TRUE(MIX_StopTrack(track, 0));
    MIX_DestroyTrack(track);
    MIX_DestroyAudio(audio);
}

TEST_F(MixerFoundation, MixesTwoTracksLouderThanOne)
{
    MIX_Audio *audio = MIX_LoadAudio(mixer_, AssetPath("music_loop.wav").c_str(), true);
    ASSERT_NE(audio, nullptr) << SDL_GetError();

    MIX_Track *a = MIX_CreateTrack(mixer_);
    MIX_Track *b = MIX_CreateTrack(mixer_);
    ASSERT_NE(a, nullptr);
    ASSERT_NE(b, nullptr);
    ASSERT_TRUE(MIX_SetTrackAudio(a, audio));
    ASSERT_TRUE(MIX_SetTrackAudio(b, audio));

    ASSERT_TRUE(MIX_PlayTrack(a, 0));
    const double one = GeneratedEnergy(mixer_, 4096);
    ASSERT_GT(one, 0.0);

    ASSERT_TRUE(MIX_SetTrackPlaybackPosition(a, 0));
    ASSERT_TRUE(MIX_PlayTrack(b, 0));
    const double two = GeneratedEnergy(mixer_, 4096);
    EXPECT_GT(two, one * 1.5) << "two simultaneous tracks should sum";

    MIX_DestroyTrack(a);
    MIX_DestroyTrack(b);
    MIX_DestroyAudio(audio);
}

TEST_F(MixerFoundation, TrackGainAttenuates)
{
    MIX_Audio *audio = MIX_LoadAudio(mixer_, AssetPath("music_loop.wav").c_str(), true);
    ASSERT_NE(audio, nullptr) << SDL_GetError();
    MIX_Track *track = MIX_CreateTrack(mixer_);
    ASSERT_NE(track, nullptr);
    ASSERT_TRUE(MIX_SetTrackAudio(track, audio));

    ASSERT_TRUE(MIX_PlayTrack(track, 0));
    const double full = GeneratedEnergy(mixer_, 4096);
    ASSERT_GT(full, 0.0);

    ASSERT_TRUE(MIX_SetTrackPlaybackPosition(track, 0));
    ASSERT_TRUE(MIX_SetTrackGain(track, 0.1F));
    const double quiet = GeneratedEnergy(mixer_, 4096);
    EXPECT_LT(quiet, full * 0.5) << "gain 0.1 should clearly attenuate";

    MIX_DestroyTrack(track);
    MIX_DestroyAudio(audio);
}

TEST_F(MixerFoundation, SineWaveGeneratorWorks)
{
    MIX_Audio *sine = MIX_CreateSineWaveAudio(mixer_, 440, 0.5F, 500);
    ASSERT_NE(sine, nullptr) << SDL_GetError();
    MIX_Track *track = MIX_CreateTrack(mixer_);
    ASSERT_NE(track, nullptr);
    ASSERT_TRUE(MIX_SetTrackAudio(track, sine));
    ASSERT_TRUE(MIX_PlayTrack(track, 0));
    EXPECT_GT(GeneratedEnergy(mixer_, 4096), 10.0);
    MIX_DestroyTrack(track);
    MIX_DestroyAudio(sine);
}

TEST_F(MixerFoundation, MidiLoadsOrFailsCleanly)
{
    // TiMidity links statically but needs GUS patch data at runtime to
    // synthesize; without it, loading must fail cleanly — never crash.
    MIX_Audio *midi = MIX_LoadAudio(mixer_, AssetPath("music_scale.mid").c_str(), false);
    if (midi != nullptr)
    {
        EXPECT_GT(MIX_GetAudioDuration(midi), 0);
        MIX_DestroyAudio(midi);
    }
    else
    {
        SUCCEED() << "MIDI decoder present but no GUS patches installed: "
                  << SDL_GetError();
    }
}

class MalformedAudio : public MixerFoundation, public ::testing::WithParamInterface<const char *>
{
};

TEST_P(MalformedAudio, TruncationsAndBitFlipsDoNotCrash)
{
    size_t size = 0;
    void *data = SDL_LoadFile(AssetPath(GetParam()).c_str(), &size);
    ASSERT_NE(data, nullptr) << SDL_GetError();
    const Uint8 *bytes = static_cast<Uint8 *>(data);
    const std::vector<Uint8> original(bytes, bytes + size);
    SDL_free(data);

    auto try_load = [this](const std::vector<Uint8> &blob) {
        if (blob.empty())
        {
            return;
        }
        SDL_IOStream *io = SDL_IOFromConstMem(blob.data(), blob.size());
        ASSERT_NE(io, nullptr) << SDL_GetError();
        MIX_Audio *audio = MIX_LoadAudio_IO(mixer_, io, true, true);
        if (audio != nullptr)
        {
            MIX_DestroyAudio(audio);  // accepting damaged data is fine; crashing is not
        }
    };

    for (const double fraction : {0.1, 0.25, 0.5, 0.9})
    {
        std::vector<Uint8> truncated(
            original.begin(),
            original.begin() +
                static_cast<std::vector<Uint8>::difference_type>(
                    static_cast<double>(original.size()) * fraction));
        try_load(truncated);
    }

    std::vector<Uint8> corrupted = original;
    Uint32 state = 0x2545F491U;
    const size_t flips = corrupted.size() / 64 + 16;
    for (size_t i = 0; i < flips; ++i)
    {
        state ^= state << 13;
        state ^= state >> 17;
        state ^= state << 5;
        corrupted[state % corrupted.size()] ^= static_cast<Uint8>(1U << (state % 8U));
    }
    try_load(corrupted);
}

INSTANTIATE_TEST_SUITE_P(Corpus, MalformedAudio,
                         ::testing::Values("music_loop.wav", "music_loop.ogg",
                                           "music_loop.mp3", "music_loop.flac",
                                           "sfx_coin.aiff", "sfx_coin.au",
                                           "sfx_coin.voc", "music_scale.mid"),
                         [](const ::testing::TestParamInfo<const char *> &param_info) {
                             std::string name = param_info.param;
                             for (char &c : name)
                             {
                                 if (c == '.' || c == '-')
                                 {
                                     c = '_';
                                 }
                             }
                             return name;
                         });

}  // namespace
