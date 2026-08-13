# SDLStatic::Mixer — static-only build of the vendored SDL_mixer sources
# (upstream release-3.2.4, the redesigned MIX_* API; provenance in
# deps/SDL3_mixer.md).
#
# Only static-link-friendly decoders are enabled; every one is vendored
# single-file or pure C, so the link-time dependency set is empty:
#   WAV, AIFF, AU, VOC, RAW, SINEWAVE           (pure C)
#   OGG Vorbis  via vendored stb_vorbis
#   MP3         via vendored dr_mp3
#   FLAC        via vendored dr_flac
#   MIDI        via vendored TiMidity (software synth; needs GUS patch data
#               at runtime to produce sound, links with zero dependencies)
#
# Deleted outright (no-stubs; heavy external libs): libFLAC, libvorbisfile,
# mpg123, opus/opusfile, wavpack, game-music-emu, libxmp (trackers are out of
# scope), fluidsynth. Their table entries were already #ifdef-gated upstream,
# so no dispatch surgery was required.

# The root project is CXX-only; the vendored SDL_mixer sources are C.
enable_language(C)

add_library(SDLStatic_Mixer STATIC
  src/SDL_mixer.c
  src/SDL_mixer_metadata_tags.c
  src/SDL_mixer_spatialization.c
  src/decoder_aiff.c
  src/decoder_au.c
  src/decoder_drflac.c
  src/decoder_drmp3.c
  src/decoder_raw.c
  src/decoder_sinewave.c
  src/decoder_stb_vorbis.c
  src/decoder_timidity.c
  src/decoder_voc.c
  src/decoder_wav.c
  src/timidity/common.c
  src/timidity/instrum.c
  src/timidity/mix.c
  src/timidity/output.c
  src/timidity/playmidi.c
  src/timidity/readmidi.c
  src/timidity/resample.c
  src/timidity/tables.c
  src/timidity/timidity.c
  # Original SDLStatic code (not vendored): 8-bit synthesis layer.
  src/sdlstatic_chiptune.c
)
add_library(SDLStatic::Mixer ALIAS SDLStatic_Mixer)

if("c_std_99" IN_LIST CMAKE_C_COMPILE_FEATURES)
  target_compile_features(SDLStatic_Mixer PRIVATE c_std_99)
endif()

set_target_properties(SDLStatic_Mixer PROPERTIES
  OUTPUT_NAME SDLStatic_Mixer
  POSITION_INDEPENDENT_CODE ON
)

target_compile_definitions(SDLStatic_Mixer PRIVATE
  DECODER_WAV
  DECODER_AIFF
  DECODER_AU
  DECODER_VOC
  DECODER_OGGVORBIS_STB
  DECODER_FLAC_DRFLAC
  DECODER_MP3_DRMP3
  DECODER_MIDI_TIMIDITY
)

target_include_directories(SDLStatic_Mixer
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(SDLStatic_Mixer PUBLIC SDL3::SDL3)

# Vendored upstream C: build quietly rather than under the project's
# warnings-as-errors regime; our own code around it stays strict.
