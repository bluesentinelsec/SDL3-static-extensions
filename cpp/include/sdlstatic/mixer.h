// mixer.h — RAII over the SDL_mixer port (MIX_* API).
// Original SDLStatic code (zlib).

#ifndef SDLSTATIC_CPP_MIXER_H_
#define SDLSTATIC_CPP_MIXER_H_

#include <SDL3_mixer/SDL_mixer.h>

#include <string>
#include <utility>

#include "sdlstatic/status.h"

namespace sdlstatic {

class Audio;
class Track;

// Owns a MIX_Mixer. CreateHeadless drives MIX_Generate (tests, offline
// rendering); CreateDevice plays through the default audio device.
class Mixer {
 public:
  static Result<Mixer> CreateHeadless(const SDL_AudioSpec& spec) {
    if (!EnsureInit()) return Status::FromSdl();
    MIX_Mixer* raw = MIX_CreateMixer(&spec);
    if (raw == nullptr) return Status::FromSdl();
    return Mixer(raw);
  }
  static Result<Mixer> CreateDevice() {
    if (!EnsureInit()) return Status::FromSdl();
    // SDL's default-device macro expands a C-style cast; localize it.
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif
    const SDL_AudioDeviceID device = SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK;
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
    MIX_Mixer* raw = MIX_CreateMixerDevice(device, nullptr);
    if (raw == nullptr) return Status::FromSdl();
    return Mixer(raw);
  }

  ~Mixer() { Destroy(); }
  Mixer(Mixer&& other) noexcept : mixer_(std::exchange(other.mixer_, nullptr)) {}
  Mixer& operator=(Mixer&& other) noexcept {
    if (this != &other) {
      Destroy();
      mixer_ = std::exchange(other.mixer_, nullptr);
    }
    return *this;
  }
  Mixer(const Mixer&) = delete;
  Mixer& operator=(const Mixer&) = delete;

  // Defined below Audio/Track.
  Result<Audio> Load(const std::string& path, bool predecode = true);
  Result<Track> Play(const Audio& audio, int loops = 0);

  // Pulls mixed samples (headless mixers). Returns bytes written, 0 at end
  // of all playback, or an error.
  Result<int> Generate(void* buffer, int bytes) {
    const int got = MIX_Generate(mixer_, buffer, bytes);
    if (got < 0) return Status::FromSdl();
    return got;
  }

  MIX_Mixer* get() const { return mixer_; }

 private:
  explicit Mixer(MIX_Mixer* mixer) : mixer_(mixer) {}
  static bool EnsureInit() { return MIX_Init(); }
  void Destroy() {
    if (mixer_ != nullptr) MIX_DestroyMixer(mixer_);
    mixer_ = nullptr;
  }
  MIX_Mixer* mixer_ = nullptr;
};

// Owns a MIX_Audio (a decoded/streamable sound or song).
class Audio {
 public:
  ~Audio() { Destroy(); }
  Audio(Audio&& other) noexcept : audio_(std::exchange(other.audio_, nullptr)) {}
  Audio& operator=(Audio&& other) noexcept {
    if (this != &other) {
      Destroy();
      audio_ = std::exchange(other.audio_, nullptr);
    }
    return *this;
  }
  Audio(const Audio&) = delete;
  Audio& operator=(const Audio&) = delete;

  Sint64 DurationFrames() const { return MIX_GetAudioDuration(audio_); }
  MIX_Audio* get() const { return audio_; }

 private:
  friend class Mixer;
  explicit Audio(MIX_Audio* audio) : audio_(audio) {}
  void Destroy() {
    if (audio_ != nullptr) MIX_DestroyAudio(audio_);
    audio_ = nullptr;
  }
  MIX_Audio* audio_ = nullptr;
};

// Owns a MIX_Track (one playing instance).
class Track {
 public:
  ~Track() { Destroy(); }
  Track(Track&& other) noexcept : track_(std::exchange(other.track_, nullptr)) {}
  Track& operator=(Track&& other) noexcept {
    if (this != &other) {
      Destroy();
      track_ = std::exchange(other.track_, nullptr);
    }
    return *this;
  }
  Track(const Track&) = delete;
  Track& operator=(const Track&) = delete;

  Status Stop() {
    if (!MIX_StopTrack(track_, 0)) return Status::FromSdl();
    return Status::Ok();
  }
  Status SetGain(float gain) {
    if (!MIX_SetTrackGain(track_, gain)) return Status::FromSdl();
    return Status::Ok();
  }
  bool playing() const { return MIX_TrackPlaying(track_); }
  MIX_Track* get() const { return track_; }

 private:
  friend class Mixer;
  explicit Track(MIX_Track* track) : track_(track) {}
  void Destroy() {
    if (track_ != nullptr) MIX_DestroyTrack(track_);
    track_ = nullptr;
  }
  MIX_Track* track_ = nullptr;
};

inline Result<Audio> Mixer::Load(const std::string& path, bool predecode) {
  MIX_Audio* raw = MIX_LoadAudio(mixer_, path.c_str(), predecode);
  if (raw == nullptr) return Status::FromSdl();
  return Audio(raw);
}

inline Result<Track> Mixer::Play(const Audio& audio, int loops) {
  MIX_Track* raw = MIX_CreateTrack(mixer_);
  if (raw == nullptr) return Status::FromSdl();
  Track track(raw);
  if (!MIX_SetTrackAudio(raw, audio.get())) return Status::FromSdl();
  SDL_PropertiesID opts = 0;
  if (loops != 0) {
    opts = SDL_CreateProperties();
    SDL_SetNumberProperty(opts, MIX_PROP_PLAY_LOOPS_NUMBER, loops);
  }
  const bool ok = MIX_PlayTrack(raw, opts);
  if (opts != 0) SDL_DestroyProperties(opts);
  if (!ok) return Status::FromSdl();
  return track;
}

}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_MIXER_H_
