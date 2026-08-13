/**
 * @file chiptune_test.cpp
 * @brief Tests for the SDLStatic chiptune synthesis layer.
 *
 * Rendering is deterministic, so correctness is asserted for real: pitch via
 * zero-crossing rates on rendered PCM, envelopes via windowed energy, noise
 * via bit-identical reproducibility. All headless (MIX_Generate).
 */

#include <SDL3/SDL.h>
#include <SDLStatic/chiptune.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <gtest/gtest.h>

#include <cmath>
#include <vector>

namespace
{

class Chiptune : public ::testing::Test
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

    // Play `audio` from the start and capture `frames` stereo frames.
    std::vector<float> Render(MIX_Audio *audio, int frames)
    {
        std::vector<float> buffer(static_cast<size_t>(frames) * 2, 0.0F);
        MIX_Track *track = MIX_CreateTrack(mixer_);
        EXPECT_NE(track, nullptr);
        EXPECT_TRUE(MIX_SetTrackAudio(track, audio));
        EXPECT_TRUE(MIX_PlayTrack(track, 0));
        const int bytes = static_cast<int>(buffer.size() * sizeof(float));
        const int got = MIX_Generate(mixer_, buffer.data(), bytes);
        EXPECT_GT(got, 0) << SDL_GetError();
        MIX_DestroyTrack(track);
        return buffer;
    }

    // Estimated pitch of the left channel across [first, first+count) frames.
    static double PitchHz(const std::vector<float> &stereo, int first, int count)
    {
        int crossings = 0;
        for (int i = first + 1; i < first + count; ++i)
        {
            const float a = stereo[static_cast<size_t>(i - 1) * 2];
            const float b = stereo[static_cast<size_t>(i) * 2];
            if ((a < 0.0F && b >= 0.0F) || (a >= 0.0F && b < 0.0F))
            {
                crossings++;
            }
        }
        return (crossings / 2.0) / (static_cast<double>(count) / 44100.0);
    }

    // Signal power (sum of squares): unlike mean-|x|, power is additive for
    // uncorrelated voices, so "two channels are louder" is actually testable.
    static double Energy(const std::vector<float> &stereo, int first, int count)
    {
        double sum = 0.0;
        for (int i = first; i < first + count; ++i)
        {
            const double v = static_cast<double>(stereo[static_cast<size_t>(i) * 2]);
            sum += v * v;
        }
        return sum;
    }

    MIX_Mixer *mixer_ = nullptr;
};

TEST_F(Chiptune, SquareToneHasRequestedPitchAndDuration)
{
    SDLStatic_ChipToneDesc desc = {};
    desc.wave = SDLSTATIC_CHIP_SQUARE_50;
    desc.freq_hz = 440.0F;
    desc.duration_ms = 500;
    desc.volume = 1.0F;
    MIX_Audio *tone = SDLStatic_CreateChipTone(mixer_, &desc);
    ASSERT_NE(tone, nullptr) << SDL_GetError();

    EXPECT_NEAR(static_cast<double>(MIX_GetAudioDuration(tone)), 44100.0 * 0.5, 44.0);
    const std::vector<float> pcm = Render(tone, 8192);
    EXPECT_NEAR(PitchHz(pcm, 512, 7000), 440.0, 25.0);
    MIX_DestroyAudio(tone);
}

TEST_F(Chiptune, TriangleIsQuantizedStaircase)
{
    SDLStatic_ChipToneDesc desc = {};
    desc.wave = SDLSTATIC_CHIP_TRIANGLE;
    desc.freq_hz = 220.0F;
    desc.duration_ms = 300;
    desc.volume = 1.0F;
    MIX_Audio *tone = SDLStatic_CreateChipTone(mixer_, &desc);
    ASSERT_NE(tone, nullptr) << SDL_GetError();

    const std::vector<float> pcm = Render(tone, 8192);
    EXPECT_NEAR(PitchHz(pcm, 512, 7000), 220.0, 15.0);
    // Steady-state samples (past the declick ramp) must sit on a small set of
    // discrete levels — a real staircase, not a smooth ramp.
    std::vector<float> levels;
    for (int i = 512; i < 7000; ++i)
    {
        const float v = pcm[static_cast<size_t>(i) * 2];
        bool known = false;
        for (const float known_level : levels)
        {
            if (std::fabs(known_level - v) < 1e-4F)
            {
                known = true;
                break;
            }
        }
        if (!known)
        {
            levels.push_back(v);
        }
    }
    EXPECT_LE(levels.size(), 16U * 2U); // 16 levels; ×2 slack for edge frames
    MIX_DestroyAudio(tone);
}

TEST_F(Chiptune, NoiseIsDeterministicAndModesDiffer)
{
    SDLStatic_ChipToneDesc desc = {};
    desc.wave = SDLSTATIC_CHIP_NOISE;
    desc.freq_hz = 300.0F;
    desc.duration_ms = 200;
    desc.volume = 1.0F;

    MIX_Audio *a = SDLStatic_CreateChipTone(mixer_, &desc);
    MIX_Audio *b = SDLStatic_CreateChipTone(mixer_, &desc);
    desc.wave = SDLSTATIC_CHIP_NOISE_METALLIC;
    MIX_Audio *metallic = SDLStatic_CreateChipTone(mixer_, &desc);
    ASSERT_NE(a, nullptr);
    ASSERT_NE(b, nullptr);
    ASSERT_NE(metallic, nullptr);

    const std::vector<float> pa = Render(a, 4096);
    const std::vector<float> pb = Render(b, 4096);
    const std::vector<float> pm = Render(metallic, 4096);
    EXPECT_EQ(pa, pb) << "identical desc must render bit-identical noise";
    EXPECT_NE(pa, pm) << "LFSR modes must sound different";
    EXPECT_GT(Energy(pa, 0, 4096), 10.0);

    MIX_DestroyAudio(a);
    MIX_DestroyAudio(b);
    MIX_DestroyAudio(metallic);
}

TEST_F(Chiptune, SweepDescendsInPitch)
{
    SDLStatic_ChipToneDesc desc = {};
    desc.wave = SDLSTATIC_CHIP_SQUARE_25;
    desc.freq_hz = 1600.0F;
    desc.freq_end_hz = 200.0F;
    desc.duration_ms = 400;
    desc.volume = 1.0F;
    MIX_Audio *tone = SDLStatic_CreateChipTone(mixer_, &desc);
    ASSERT_NE(tone, nullptr) << SDL_GetError();

    const std::vector<float> pcm = Render(tone, 16384);
    const double early = PitchHz(pcm, 256, 3000);
    const double late = PitchHz(pcm, 12000, 3000);
    EXPECT_GT(early, late * 2.0) << "sweep should clearly descend";
    MIX_DestroyAudio(tone);
}

TEST_F(Chiptune, ToneRejectsBadInput)
{
    EXPECT_EQ(SDLStatic_CreateChipTone(mixer_, nullptr), nullptr);
    SDLStatic_ChipToneDesc desc = {};
    desc.wave = SDLSTATIC_CHIP_SQUARE_50;
    desc.freq_hz = 440.0F;
    desc.duration_ms = 0; // invalid
    desc.volume = 1.0F;
    EXPECT_EQ(SDLStatic_CreateChipTone(mixer_, &desc), nullptr);
    desc.duration_ms = 100;
    desc.freq_hz = -5.0F; // invalid
    EXPECT_EQ(SDLStatic_CreateChipTone(mixer_, &desc), nullptr);
}

TEST_F(Chiptune, AllSfxPresetsRender)
{
    for (int i = SDLSTATIC_SFX_COIN; i <= SDLSTATIC_SFX_HURT; ++i)
    {
        MIX_Audio *sfx = SDLStatic_CreateChipSFX(mixer_, static_cast<SDLStatic_ChipSFX>(i));
        ASSERT_NE(sfx, nullptr) << "sfx " << i << ": " << SDL_GetError();
        EXPECT_GT(MIX_GetAudioDuration(sfx), 0) << "sfx " << i;
        const std::vector<float> pcm = Render(sfx, 2048);
        EXPECT_GT(Energy(pcm, 0, 2048), 1.0) << "sfx " << i << " is silent";
        MIX_DestroyAudio(sfx);
    }
    // One past the last preset: invalid ID, but inside the enum's value range
    // (an out-of-range cast like 99 is unspecified in C++ and gcc rejects it).
    EXPECT_EQ(SDLStatic_CreateChipSFX(mixer_, static_cast<SDLStatic_ChipSFX>(SDLSTATIC_SFX_HURT + 1)),
              nullptr);
}

TEST_F(Chiptune, MmlDurationFollowsTempo)
{
    // Three quarter notes at 120 BPM = 1.5 s.
    MIX_Audio *tune = SDLStatic_CreateChipTune(mixer_, "T120 L4 C E G");
    ASSERT_NE(tune, nullptr) << SDL_GetError();
    EXPECT_NEAR(static_cast<double>(MIX_GetAudioDuration(tune)), 44100.0 * 1.5, 200.0);
    MIX_DestroyAudio(tune);

    // Same notes, twice the tempo: half the length. Dotted quarter = 1.5×.
    tune = SDLStatic_CreateChipTune(mixer_, "T240 L4 C E G");
    ASSERT_NE(tune, nullptr) << SDL_GetError();
    EXPECT_NEAR(static_cast<double>(MIX_GetAudioDuration(tune)), 44100.0 * 0.75, 200.0);
    MIX_DestroyAudio(tune);

    tune = SDLStatic_CreateChipTune(mixer_, "T120 C4.");
    ASSERT_NE(tune, nullptr) << SDL_GetError();
    EXPECT_NEAR(static_cast<double>(MIX_GetAudioDuration(tune)), 44100.0 * 0.75, 200.0);
    MIX_DestroyAudio(tune);
}

TEST_F(Chiptune, MmlNotePitchIsCorrect)
{
    // O4 A is A440 by definition; a whole note gives a long steady window.
    MIX_Audio *tune = SDLStatic_CreateChipTune(mixer_, "T120 O4 L1 A");
    ASSERT_NE(tune, nullptr) << SDL_GetError();
    const std::vector<float> pcm = Render(tune, 32768);
    EXPECT_NEAR(PitchHz(pcm, 512, 30000), 440.0, 25.0);
    MIX_DestroyAudio(tune);

    // '>' shifts up one octave: 880 Hz.
    tune = SDLStatic_CreateChipTune(mixer_, "T120 O4 L1 > A");
    ASSERT_NE(tune, nullptr) << SDL_GetError();
    const std::vector<float> up = Render(tune, 32768);
    EXPECT_NEAR(PitchHz(up, 512, 30000), 880.0, 50.0);
    MIX_DestroyAudio(tune);

    // Sharps move one semitone: A# at O4 = 466.16 Hz.
    tune = SDLStatic_CreateChipTune(mixer_, "T120 O4 L1 A#");
    ASSERT_NE(tune, nullptr) << SDL_GetError();
    const std::vector<float> sharp = Render(tune, 32768);
    EXPECT_NEAR(PitchHz(sharp, 512, 30000), 466.16, 25.0);
    MIX_DestroyAudio(tune);
}

TEST_F(Chiptune, MmlRestIsSilent)
{
    // Quarter note, quarter rest, quarter note at 120 BPM (0.5 s each).
    MIX_Audio *tune = SDLStatic_CreateChipTune(mixer_, "T120 L4 C R C");
    ASSERT_NE(tune, nullptr) << SDL_GetError();
    const std::vector<float> pcm = Render(tune, 44100 * 3 / 2);
    const int quarter = 22050;
    EXPECT_GT(Energy(pcm, 1000, 10000), 10.0) << "first note silent";
    EXPECT_NEAR(Energy(pcm, quarter + 1000, 10000), 0.0, 0.5) << "rest not silent";
    EXPECT_GT(Energy(pcm, 2 * quarter + 1000, 10000), 10.0) << "third note silent";
    MIX_DestroyAudio(tune);
}

TEST_F(Chiptune, MmlMixesMultipleChannels)
{
    MIX_Audio *solo = SDLStatic_CreateChipTune(mixer_, "T120 L2 O4 C");
    MIX_Audio *duo = SDLStatic_CreateChipTune(mixer_, "T120 L2 O4 C ; T120 L2 O4 G");
    ASSERT_NE(solo, nullptr) << SDL_GetError();
    ASSERT_NE(duo, nullptr) << SDL_GetError();
    EXPECT_EQ(MIX_GetAudioDuration(solo), MIX_GetAudioDuration(duo));

    const std::vector<float> one = Render(solo, 16384);
    const std::vector<float> two = Render(duo, 16384);
    EXPECT_GT(Energy(two, 512, 15000), Energy(one, 512, 15000) * 1.5)
        << "two channels should be clearly louder than one";
    MIX_DestroyAudio(solo);
    MIX_DestroyAudio(duo);
}

TEST_F(Chiptune, MmlVolumeAttenuates)
{
    MIX_Audio *loud = SDLStatic_CreateChipTune(mixer_, "T120 V15 L2 C");
    MIX_Audio *quiet = SDLStatic_CreateChipTune(mixer_, "T120 V3 L2 C");
    ASSERT_NE(loud, nullptr);
    ASSERT_NE(quiet, nullptr);
    const std::vector<float> l = Render(loud, 8192);
    const std::vector<float> q = Render(quiet, 8192);
    EXPECT_LT(Energy(q, 512, 7000), Energy(l, 512, 7000) * 0.5);
    MIX_DestroyAudio(loud);
    MIX_DestroyAudio(quiet);
}

TEST_F(Chiptune, MmlWaveformSelectionChangesTimbre)
{
    // Same pitch, different waveforms → different PCM.
    MIX_Audio *square = SDLStatic_CreateChipTune(mixer_, "T120 W2 L2 O4 A");
    MIX_Audio *triangle = SDLStatic_CreateChipTune(mixer_, "T120 W3 L2 O4 A");
    ASSERT_NE(square, nullptr);
    ASSERT_NE(triangle, nullptr);
    const std::vector<float> s = Render(square, 8192);
    const std::vector<float> t = Render(triangle, 8192);
    EXPECT_NE(s, t);
    EXPECT_NEAR(PitchHz(s, 512, 7000), PitchHz(t, 512, 7000), 30.0);
    MIX_DestroyAudio(square);
    MIX_DestroyAudio(triangle);
}

TEST_F(Chiptune, SineWaveIsPitchedAndSmooth)
{
    MIX_Audio *sine = SDLStatic_CreateChipTune(mixer_, "T120 W7 O4 L1 A");
    MIX_Audio *square = SDLStatic_CreateChipTune(mixer_, "T120 W2 O4 L1 A");
    ASSERT_NE(sine, nullptr) << SDL_GetError();
    ASSERT_NE(square, nullptr) << SDL_GetError();

    const std::vector<float> s = Render(sine, 32768);
    const std::vector<float> q = Render(square, 32768);
    EXPECT_NEAR(PitchHz(s, 512, 30000), 440.0, 25.0);

    // Mean-|x| over peak separates the shapes: sine = 2/pi (~0.64), square = 1.
    auto crest = [](const std::vector<float> &pcm) {
        double peak = 0.0;
        double mean = 0.0;
        for (int i = 512; i < 30512; ++i)
        {
            const double v = std::fabs(static_cast<double>(pcm[static_cast<size_t>(i) * 2]));
            peak = std::max(peak, v);
            mean += v;
        }
        return mean / 30000.0 / peak;
    };
    EXPECT_LT(crest(s), 0.75) << "sine should be smooth, not flat-topped";
    EXPECT_GT(crest(q), 0.9) << "square should sit at the rails";

    MIX_DestroyAudio(sine);
    MIX_DestroyAudio(square);
}

TEST_F(Chiptune, MmlEnvelopeShapesDecay)
{
    // T240 L1 = a 1 s whole note. S1 decays across it; S0 stays flat.
    MIX_Audio *flat = SDLStatic_CreateChipTune(mixer_, "T240 S0 L1 C");
    MIX_Audio *decay = SDLStatic_CreateChipTune(mixer_, "T240 S1 L1 C");
    MIX_Audio *pluck = SDLStatic_CreateChipTune(mixer_, "T240 S2 L1 C");
    ASSERT_NE(flat, nullptr) << SDL_GetError();
    ASSERT_NE(decay, nullptr) << SDL_GetError();
    ASSERT_NE(pluck, nullptr) << SDL_GetError();

    const std::vector<float> f = Render(flat, 44100);
    const std::vector<float> d = Render(decay, 44100);
    const std::vector<float> p = Render(pluck, 44100);

    // Flat: similar power early vs late. Decay: late is a fraction of early.
    EXPECT_GT(Energy(f, 36000, 4000), Energy(f, 2000, 4000) * 0.5);
    EXPECT_LT(Energy(d, 36000, 4000), Energy(d, 2000, 4000) * 0.2);
    // Pluck: audible at the start, silent after ~140 ms.
    EXPECT_GT(Energy(p, 0, 4000), 1.0);
    EXPECT_NEAR(Energy(p, 12000, 8000), 0.0, 0.05);

    MIX_DestroyAudio(flat);
    MIX_DestroyAudio(decay);
    MIX_DestroyAudio(pluck);
}

TEST_F(Chiptune, MmlNoisePercussionChannelWorks)
{
    // The classic four-voice NES lineup, percussion via plucked noise.
    MIX_Audio *tune = SDLStatic_CreateChipTune(
        mixer_, "T140 W1 O5 L8 C E G >C< G E C4 ;"
                "T140 W2 O4 L8 E G B >E< B G E4 ;"
                "T140 W3 O2 L4 C G E G ;"
                "T140 W5 S2 L8 O3 C O6 C O3 C O6 C O3 C O6 C O3 C O6 C");
    ASSERT_NE(tune, nullptr) << SDL_GetError();
    // All four channels are 4 beats at 140 BPM.
    EXPECT_NEAR(static_cast<double>(MIX_GetAudioDuration(tune)), 44100.0 * 4.0 * 60.0 / 140.0,
                300.0);
    const std::vector<float> pcm = Render(tune, 32768);
    EXPECT_GT(Energy(pcm, 512, 30000), 50.0);
    MIX_DestroyAudio(tune);
}

TEST_F(Chiptune, MmlRejectsBadPrograms)
{
    EXPECT_EQ(SDLStatic_CreateChipTune(mixer_, nullptr), nullptr);
    EXPECT_EQ(SDLStatic_CreateChipTune(mixer_, ""), nullptr);
    EXPECT_EQ(SDLStatic_CreateChipTune(mixer_, "C D H E"), nullptr); // H invalid
    EXPECT_EQ(SDLStatic_CreateChipTune(mixer_, "T120 W9 C"), nullptr); // bad wave
    EXPECT_EQ(SDLStatic_CreateChipTune(mixer_, "T120 S5 C"), nullptr); // bad shape
    EXPECT_EQ(SDLStatic_CreateChipTune(mixer_, "T120 V5"), nullptr); // no audio
    // Error message should locate the problem.
    SDL_ClearError();
    EXPECT_EQ(SDLStatic_CreateChipTune(mixer_, "C D H"), nullptr);
    EXPECT_NE(std::string(SDL_GetError()).find('H'), std::string::npos);
}

TEST_F(Chiptune, TuneLoopsSeamlesslyThroughTrackApi)
{
    MIX_Audio *tune = SDLStatic_CreateChipTune(mixer_, "T240 L8 C E G >C<");
    ASSERT_NE(tune, nullptr) << SDL_GetError();
    MIX_Track *track = MIX_CreateTrack(mixer_);
    ASSERT_NE(track, nullptr);
    ASSERT_TRUE(MIX_SetTrackAudio(track, tune));

    SDL_PropertiesID opts = SDL_CreateProperties();
    SDL_SetNumberProperty(opts, MIX_PROP_PLAY_LOOPS_NUMBER, -1);
    ASSERT_TRUE(MIX_PlayTrack(track, opts)) << SDL_GetError();
    SDL_DestroyProperties(opts);

    // One iteration is 0.5 s; render 2 s and confirm audio keeps flowing.
    std::vector<float> buffer(static_cast<size_t>(44100) * 2 * 2);
    const int bytes = static_cast<int>(buffer.size() * sizeof(float));
    ASSERT_GT(MIX_Generate(mixer_, buffer.data(), bytes), 0) << SDL_GetError();
    double tail = 0.0;
    for (size_t i = buffer.size() - 20000; i < buffer.size(); i += 2)
    {
        tail += std::fabs(static_cast<double>(buffer[i]));
    }
    EXPECT_GT(tail, 10.0) << "looped tune went silent";
    EXPECT_TRUE(MIX_TrackPlaying(track));

    MIX_DestroyTrack(track);
    MIX_DestroyAudio(tune);
}

} // namespace
