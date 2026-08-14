// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: SDL_mixer
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_MIX_H_
#define SDLSTATIC_CPP_GEN_MIX_H_

#include <SDL3_mixer/SDL_mixer.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace mix {

// RAII owner for MIX_Mixer (destroyed with MIX_DestroyMixer).
class Mixer {
 public:
  static Result<Mixer> CreateMixerDevice(SDL_AudioDeviceID devid, const SDL_AudioSpec *spec) {
    MIX_Mixer* created_ = ::MIX_CreateMixerDevice(devid, spec);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Mixer(created_);
  }
  static Result<Mixer> CreateMixer(const SDL_AudioSpec *spec) {
    MIX_Mixer* created_ = ::MIX_CreateMixer(spec);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Mixer(created_);
  }

  Mixer() = default;
  ~Mixer() { reset(); }
  Mixer(Mixer&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Mixer& operator=(Mixer&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Mixer(const Mixer&) = delete;
  Mixer& operator=(const Mixer&) = delete;

  MIX_Mixer* get() const { return value_; }
  MIX_Mixer* release() {
    MIX_Mixer* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::MIX_DestroyMixer(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_PropertiesID GetMixerProperties() {
    return ::MIX_GetMixerProperties(value_);
  }
  Status GetMixerFormat(SDL_AudioSpec *spec) {
    return ::MIX_GetMixerFormat(value_, spec) ? Status() : Status::FromSdl();
  }
  void LockMixer() { ::MIX_LockMixer(value_); }
  void UnlockMixer() { ::MIX_UnlockMixer(value_); }
  MIX_Audio* LoadAudioNoCopy(const void *data, size_t datalen, bool free_when_done) {
    return ::MIX_LoadAudioNoCopy(value_, data, datalen, free_when_done);
  }
  MIX_Audio* LoadRawAudioNoCopy(const void *data, size_t datalen, const SDL_AudioSpec *spec, bool free_when_done) {
    return ::MIX_LoadRawAudioNoCopy(value_, data, datalen, spec, free_when_done);
  }
  MIX_Track** GetTaggedTracks(const char *tag, int *count) {
    return ::MIX_GetTaggedTracks(value_, tag, count);
  }
  Status PlayTag(const char *tag, SDL_PropertiesID options) {
    return ::MIX_PlayTag(value_, tag, options) ? Status() : Status::FromSdl();
  }
  Status PlayAudio(MIX_Audio *audio) {
    return ::MIX_PlayAudio(value_, audio) ? Status() : Status::FromSdl();
  }
  Status StopAllTracks(Sint64 fade_out_ms) {
    return ::MIX_StopAllTracks(value_, fade_out_ms) ? Status() : Status::FromSdl();
  }
  Status StopTag(const char *tag, Sint64 fade_out_ms) {
    return ::MIX_StopTag(value_, tag, fade_out_ms) ? Status() : Status::FromSdl();
  }
  Status PauseAllTracks() {
    return ::MIX_PauseAllTracks(value_) ? Status() : Status::FromSdl();
  }
  Status PauseTag(const char *tag) {
    return ::MIX_PauseTag(value_, tag) ? Status() : Status::FromSdl();
  }
  Status ResumeAllTracks() {
    return ::MIX_ResumeAllTracks(value_) ? Status() : Status::FromSdl();
  }
  Status ResumeTag(const char *tag) {
    return ::MIX_ResumeTag(value_, tag) ? Status() : Status::FromSdl();
  }
  Status SetMixerGain(float gain) {
    return ::MIX_SetMixerGain(value_, gain) ? Status() : Status::FromSdl();
  }
  float GetMixerGain() {
    return ::MIX_GetMixerGain(value_);
  }
  Status SetTagGain(const char *tag, float gain) {
    return ::MIX_SetTagGain(value_, tag, gain) ? Status() : Status::FromSdl();
  }
  Status SetMixerFrequencyRatio(float ratio) {
    return ::MIX_SetMixerFrequencyRatio(value_, ratio) ? Status() : Status::FromSdl();
  }
  float GetMixerFrequencyRatio() {
    return ::MIX_GetMixerFrequencyRatio(value_);
  }
  MIX_Group* CreateGroup() {
    return ::MIX_CreateGroup(value_);
  }
  Status SetPostMixCallback(MIX_PostMixCallback cb, void *userdata) {
    return ::MIX_SetPostMixCallback(value_, cb, userdata) ? Status() : Status::FromSdl();
  }
  int Generate(void *buffer, int buflen) {
    return ::MIX_Generate(value_, buffer, buflen);
  }
 private:
  explicit Mixer(MIX_Mixer* value) : value_(value), engaged_(true) {}
  MIX_Mixer* value_{};
  bool engaged_ = false;
};

// RAII owner for MIX_Audio (destroyed with MIX_DestroyAudio).
class Audio {
 public:
  static Result<Audio> LoadAudio_IO(MIX_Mixer *mixer, SDL_IOStream *io, bool predecode, bool closeio) {
    MIX_Audio* created_ = ::MIX_LoadAudio_IO(mixer, io, predecode, closeio);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Audio(created_);
  }
  static Result<Audio> LoadAudio(MIX_Mixer *mixer, const char *path, bool predecode) {
    MIX_Audio* created_ = ::MIX_LoadAudio(mixer, path, predecode);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Audio(created_);
  }
  static Result<Audio> LoadAudioWithProperties(SDL_PropertiesID props) {
    MIX_Audio* created_ = ::MIX_LoadAudioWithProperties(props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Audio(created_);
  }
  static Result<Audio> LoadRawAudio_IO(MIX_Mixer *mixer, SDL_IOStream *io, const SDL_AudioSpec *spec, bool closeio) {
    MIX_Audio* created_ = ::MIX_LoadRawAudio_IO(mixer, io, spec, closeio);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Audio(created_);
  }
  static Result<Audio> LoadRawAudio(MIX_Mixer *mixer, const void *data, size_t datalen, const SDL_AudioSpec *spec) {
    MIX_Audio* created_ = ::MIX_LoadRawAudio(mixer, data, datalen, spec);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Audio(created_);
  }
  static Result<Audio> CreateSineWaveAudio(MIX_Mixer *mixer, int hz, float amplitude, Sint64 ms) {
    MIX_Audio* created_ = ::MIX_CreateSineWaveAudio(mixer, hz, amplitude, ms);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Audio(created_);
  }

  Audio() = default;
  ~Audio() { reset(); }
  Audio(Audio&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Audio& operator=(Audio&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Audio(const Audio&) = delete;
  Audio& operator=(const Audio&) = delete;

  MIX_Audio* get() const { return value_; }
  MIX_Audio* release() {
    MIX_Audio* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::MIX_DestroyAudio(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_PropertiesID GetAudioProperties() {
    return ::MIX_GetAudioProperties(value_);
  }
  Sint64 GetAudioDuration() {
    return ::MIX_GetAudioDuration(value_);
  }
  Status GetAudioFormat(SDL_AudioSpec *spec) {
    return ::MIX_GetAudioFormat(value_, spec) ? Status() : Status::FromSdl();
  }
  Sint64 AudioMSToFrames(Sint64 ms) {
    return ::MIX_AudioMSToFrames(value_, ms);
  }
  Sint64 AudioFramesToMS(Sint64 frames) {
    return ::MIX_AudioFramesToMS(value_, frames);
  }
 private:
  explicit Audio(MIX_Audio* value) : value_(value), engaged_(true) {}
  MIX_Audio* value_{};
  bool engaged_ = false;
};

// RAII owner for MIX_Track (destroyed with MIX_DestroyTrack).
class Track {
 public:
  static Result<Track> CreateTrack(MIX_Mixer *mixer) {
    MIX_Track* created_ = ::MIX_CreateTrack(mixer);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Track(created_);
  }

  Track() = default;
  ~Track() { reset(); }
  Track(Track&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Track& operator=(Track&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Track(const Track&) = delete;
  Track& operator=(const Track&) = delete;

  MIX_Track* get() const { return value_; }
  MIX_Track* release() {
    MIX_Track* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::MIX_DestroyTrack(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_PropertiesID GetTrackProperties() {
    return ::MIX_GetTrackProperties(value_);
  }
  MIX_Mixer* GetTrackMixer() {
    return ::MIX_GetTrackMixer(value_);
  }
  Status SetTrackAudio(MIX_Audio *audio) {
    return ::MIX_SetTrackAudio(value_, audio) ? Status() : Status::FromSdl();
  }
  Status SetTrackAudioStream(SDL_AudioStream *stream) {
    return ::MIX_SetTrackAudioStream(value_, stream) ? Status() : Status::FromSdl();
  }
  Status SetTrackIOStream(SDL_IOStream *io, bool closeio) {
    return ::MIX_SetTrackIOStream(value_, io, closeio) ? Status() : Status::FromSdl();
  }
  Status SetTrackRawIOStream(SDL_IOStream *io, const SDL_AudioSpec *spec, bool closeio) {
    return ::MIX_SetTrackRawIOStream(value_, io, spec, closeio) ? Status() : Status::FromSdl();
  }
  Status TagTrack(const char *tag) {
    return ::MIX_TagTrack(value_, tag) ? Status() : Status::FromSdl();
  }
  void UntagTrack(const char *tag) { ::MIX_UntagTrack(value_, tag); }
  char** GetTrackTags(int *count) {
    return ::MIX_GetTrackTags(value_, count);
  }
  Status SetTrackPlaybackPosition(Sint64 frames) {
    return ::MIX_SetTrackPlaybackPosition(value_, frames) ? Status() : Status::FromSdl();
  }
  Sint64 GetTrackPlaybackPosition() {
    return ::MIX_GetTrackPlaybackPosition(value_);
  }
  Sint64 GetTrackFadeFrames() {
    return ::MIX_GetTrackFadeFrames(value_);
  }
  int GetTrackLoops() {
    return ::MIX_GetTrackLoops(value_);
  }
  Status SetTrackLoops(int num_loops) {
    return ::MIX_SetTrackLoops(value_, num_loops) ? Status() : Status::FromSdl();
  }
  MIX_Audio* GetTrackAudio() {
    return ::MIX_GetTrackAudio(value_);
  }
  SDL_AudioStream* GetTrackAudioStream() {
    return ::MIX_GetTrackAudioStream(value_);
  }
  Sint64 GetTrackRemaining() {
    return ::MIX_GetTrackRemaining(value_);
  }
  Sint64 TrackMSToFrames(Sint64 ms) {
    return ::MIX_TrackMSToFrames(value_, ms);
  }
  Sint64 TrackFramesToMS(Sint64 frames) {
    return ::MIX_TrackFramesToMS(value_, frames);
  }
  Status PlayTrack(SDL_PropertiesID options) {
    return ::MIX_PlayTrack(value_, options) ? Status() : Status::FromSdl();
  }
  Status StopTrack(Sint64 fade_out_frames) {
    return ::MIX_StopTrack(value_, fade_out_frames) ? Status() : Status::FromSdl();
  }
  Status PauseTrack() {
    return ::MIX_PauseTrack(value_) ? Status() : Status::FromSdl();
  }
  Status ResumeTrack() {
    return ::MIX_ResumeTrack(value_) ? Status() : Status::FromSdl();
  }
  Status TrackPlaying() {
    return ::MIX_TrackPlaying(value_) ? Status() : Status::FromSdl();
  }
  Status TrackPaused() {
    return ::MIX_TrackPaused(value_) ? Status() : Status::FromSdl();
  }
  Status SetTrackGain(float gain) {
    return ::MIX_SetTrackGain(value_, gain) ? Status() : Status::FromSdl();
  }
  float GetTrackGain() {
    return ::MIX_GetTrackGain(value_);
  }
  Status SetTrackFrequencyRatio(float ratio) {
    return ::MIX_SetTrackFrequencyRatio(value_, ratio) ? Status() : Status::FromSdl();
  }
  float GetTrackFrequencyRatio() {
    return ::MIX_GetTrackFrequencyRatio(value_);
  }
  Status SetTrackOutputChannelMap(const int *chmap, int count) {
    return ::MIX_SetTrackOutputChannelMap(value_, chmap, count) ? Status() : Status::FromSdl();
  }
  Status SetTrackStereo(const MIX_StereoGains *gains) {
    return ::MIX_SetTrackStereo(value_, gains) ? Status() : Status::FromSdl();
  }
  Status SetTrack3DPosition(const MIX_Point3D *position) {
    return ::MIX_SetTrack3DPosition(value_, position) ? Status() : Status::FromSdl();
  }
  Status GetTrack3DPosition(MIX_Point3D *position) {
    return ::MIX_GetTrack3DPosition(value_, position) ? Status() : Status::FromSdl();
  }
  Status SetTrackGroup(MIX_Group *group) {
    return ::MIX_SetTrackGroup(value_, group) ? Status() : Status::FromSdl();
  }
  Status SetTrackStoppedCallback(MIX_TrackStoppedCallback cb, void *userdata) {
    return ::MIX_SetTrackStoppedCallback(value_, cb, userdata) ? Status() : Status::FromSdl();
  }
  Status SetTrackRawCallback(MIX_TrackMixCallback cb, void *userdata) {
    return ::MIX_SetTrackRawCallback(value_, cb, userdata) ? Status() : Status::FromSdl();
  }
  Status SetTrackCookedCallback(MIX_TrackMixCallback cb, void *userdata) {
    return ::MIX_SetTrackCookedCallback(value_, cb, userdata) ? Status() : Status::FromSdl();
  }
 private:
  explicit Track(MIX_Track* value) : value_(value), engaged_(true) {}
  MIX_Track* value_{};
  bool engaged_ = false;
};

// RAII owner for MIX_AudioDecoder (destroyed with MIX_DestroyAudioDecoder).
class AudioDecoder {
 public:
  static Result<AudioDecoder> CreateAudioDecoder(const char *path, SDL_PropertiesID props) {
    MIX_AudioDecoder* created_ = ::MIX_CreateAudioDecoder(path, props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return AudioDecoder(created_);
  }
  static Result<AudioDecoder> CreateAudioDecoder_IO(SDL_IOStream *io, bool closeio, SDL_PropertiesID props) {
    MIX_AudioDecoder* created_ = ::MIX_CreateAudioDecoder_IO(io, closeio, props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return AudioDecoder(created_);
  }

  AudioDecoder() = default;
  ~AudioDecoder() { reset(); }
  AudioDecoder(AudioDecoder&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  AudioDecoder& operator=(AudioDecoder&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  AudioDecoder(const AudioDecoder&) = delete;
  AudioDecoder& operator=(const AudioDecoder&) = delete;

  MIX_AudioDecoder* get() const { return value_; }
  MIX_AudioDecoder* release() {
    MIX_AudioDecoder* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::MIX_DestroyAudioDecoder(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_PropertiesID GetAudioDecoderProperties() {
    return ::MIX_GetAudioDecoderProperties(value_);
  }
  Status GetAudioDecoderFormat(SDL_AudioSpec *spec) {
    return ::MIX_GetAudioDecoderFormat(value_, spec) ? Status() : Status::FromSdl();
  }
  int DecodeAudio(void *buffer, int buflen, const SDL_AudioSpec *spec) {
    return ::MIX_DecodeAudio(value_, buffer, buflen, spec);
  }
 private:
  explicit AudioDecoder(MIX_AudioDecoder* value) : value_(value), engaged_(true) {}
  MIX_AudioDecoder* value_{};
  bool engaged_ = false;
};

// bool-returning C functions surfaced as Status.
inline Status Init() {
  return ::MIX_Init() ? Status() : Status::FromSdl();
}
inline Status SetGroupPostMixCallback(MIX_Group *group, MIX_GroupMixCallback cb, void *userdata) {
  return ::MIX_SetGroupPostMixCallback(group, cb, userdata) ? Status() : Status::FromSdl();
}

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& DestroyGroup = ::MIX_DestroyGroup;
inline constexpr auto& FramesToMS = ::MIX_FramesToMS;
inline constexpr auto& GetAudioDecoder = ::MIX_GetAudioDecoder;
inline constexpr auto& GetGroupMixer = ::MIX_GetGroupMixer;
inline constexpr auto& GetGroupProperties = ::MIX_GetGroupProperties;
inline constexpr auto& GetNumAudioDecoders = ::MIX_GetNumAudioDecoders;
inline constexpr auto& MSToFrames = ::MIX_MSToFrames;
inline constexpr auto& Quit = ::MIX_Quit;
inline constexpr auto& Version = ::MIX_Version;

}  // namespace mix
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_MIX_H_
// clang-format on
