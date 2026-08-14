// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: SDL_ttf
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_TTF_H_
#define SDLSTATIC_CPP_GEN_TTF_H_

#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_ttf/SDL_textengine.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace ttf {

// RAII owner for TTF_Font (destroyed with TTF_CloseFont).
class Font {
 public:
  static Result<Font> OpenFont(const char *file, float ptsize) {
    TTF_Font* created_ = ::TTF_OpenFont(file, ptsize);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Font(created_);
  }
  static Result<Font> OpenFontIO(SDL_IOStream *src, bool closeio, float ptsize) {
    TTF_Font* created_ = ::TTF_OpenFontIO(src, closeio, ptsize);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Font(created_);
  }
  static Result<Font> OpenFontWithProperties(SDL_PropertiesID props) {
    TTF_Font* created_ = ::TTF_OpenFontWithProperties(props);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Font(created_);
  }
  static Result<Font> CopyFont(TTF_Font *existing_font) {
    TTF_Font* created_ = ::TTF_CopyFont(existing_font);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Font(created_);
  }

  Font() = default;
  ~Font() { reset(); }
  Font(Font&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Font& operator=(Font&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Font(const Font&) = delete;
  Font& operator=(const Font&) = delete;

  TTF_Font* get() const { return value_; }
  TTF_Font* release() {
    TTF_Font* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::TTF_CloseFont(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  SDL_PropertiesID GetFontProperties() {
    return ::TTF_GetFontProperties(value_);
  }
  Uint32 GetFontGeneration() {
    return ::TTF_GetFontGeneration(value_);
  }
  Status AddFallbackFont(TTF_Font *fallback) {
    return ::TTF_AddFallbackFont(value_, fallback) ? Status() : Status::FromSdl();
  }
  void RemoveFallbackFont(TTF_Font *fallback) { ::TTF_RemoveFallbackFont(value_, fallback); }
  void ClearFallbackFonts() { ::TTF_ClearFallbackFonts(value_); }
  Status SetFontSize(float ptsize) {
    return ::TTF_SetFontSize(value_, ptsize) ? Status() : Status::FromSdl();
  }
  Status SetFontSizeDPI(float ptsize, int hdpi, int vdpi) {
    return ::TTF_SetFontSizeDPI(value_, ptsize, hdpi, vdpi) ? Status() : Status::FromSdl();
  }
  float GetFontSize() {
    return ::TTF_GetFontSize(value_);
  }
  Status GetFontDPI(int *hdpi, int *vdpi) {
    return ::TTF_GetFontDPI(value_, hdpi, vdpi) ? Status() : Status::FromSdl();
  }
  void SetFontStyle(TTF_FontStyleFlags style) { ::TTF_SetFontStyle(value_, style); }
  TTF_FontStyleFlags GetFontStyle() {
    return ::TTF_GetFontStyle(value_);
  }
  Status SetFontOutline(int outline) {
    return ::TTF_SetFontOutline(value_, outline) ? Status() : Status::FromSdl();
  }
  int GetFontOutline() {
    return ::TTF_GetFontOutline(value_);
  }
  void SetFontHinting(TTF_HintingFlags hinting) { ::TTF_SetFontHinting(value_, hinting); }
  int GetNumFontFaces() {
    return ::TTF_GetNumFontFaces(value_);
  }
  TTF_HintingFlags GetFontHinting() {
    return ::TTF_GetFontHinting(value_);
  }
  Status SetFontSDF(bool enabled) {
    return ::TTF_SetFontSDF(value_, enabled) ? Status() : Status::FromSdl();
  }
  Status GetFontSDF() {
    return ::TTF_GetFontSDF(value_) ? Status() : Status::FromSdl();
  }
  int GetFontWeight() {
    return ::TTF_GetFontWeight(value_);
  }
  void SetFontWrapAlignment(TTF_HorizontalAlignment align) { ::TTF_SetFontWrapAlignment(value_, align); }
  TTF_HorizontalAlignment GetFontWrapAlignment() {
    return ::TTF_GetFontWrapAlignment(value_);
  }
  int GetFontHeight() {
    return ::TTF_GetFontHeight(value_);
  }
  int GetFontAscent() {
    return ::TTF_GetFontAscent(value_);
  }
  int GetFontDescent() {
    return ::TTF_GetFontDescent(value_);
  }
  void SetFontLineSkip(int lineskip) { ::TTF_SetFontLineSkip(value_, lineskip); }
  int GetFontLineSkip() {
    return ::TTF_GetFontLineSkip(value_);
  }
  void SetFontKerning(bool enabled) { ::TTF_SetFontKerning(value_, enabled); }
  Status GetFontKerning() {
    return ::TTF_GetFontKerning(value_) ? Status() : Status::FromSdl();
  }
  Status FontIsFixedWidth() {
    return ::TTF_FontIsFixedWidth(value_) ? Status() : Status::FromSdl();
  }
  Status FontIsScalable() {
    return ::TTF_FontIsScalable(value_) ? Status() : Status::FromSdl();
  }
  const char* GetFontFamilyName() {
    return ::TTF_GetFontFamilyName(value_);
  }
  const char* GetFontStyleName() {
    return ::TTF_GetFontStyleName(value_);
  }
  Status SetFontLanguage(const char *language_bcp47) {
    return ::TTF_SetFontLanguage(value_, language_bcp47) ? Status() : Status::FromSdl();
  }
  Status FontHasGlyph(Uint32 ch) {
    return ::TTF_FontHasGlyph(value_, ch) ? Status() : Status::FromSdl();
  }
  SDL_Surface* GetGlyphImage(Uint32 ch, TTF_ImageType *image_type) {
    return ::TTF_GetGlyphImage(value_, ch, image_type);
  }
  SDL_Surface* GetGlyphImageForIndex(Uint32 glyph_index, TTF_ImageType *image_type) {
    return ::TTF_GetGlyphImageForIndex(value_, glyph_index, image_type);
  }
  Status GetGlyphMetrics(Uint32 ch, int *minx, int *maxx, int *miny, int *maxy, int *advance) {
    return ::TTF_GetGlyphMetrics(value_, ch, minx, maxx, miny, maxy, advance) ? Status() : Status::FromSdl();
  }
  Status GetGlyphKerning(Uint32 previous_ch, Uint32 ch, int *kerning) {
    return ::TTF_GetGlyphKerning(value_, previous_ch, ch, kerning) ? Status() : Status::FromSdl();
  }
  Status GetStringSize(const char *text, size_t length, int *w, int *h) {
    return ::TTF_GetStringSize(value_, text, length, w, h) ? Status() : Status::FromSdl();
  }
  Status GetStringSizeWrapped(const char *text, size_t length, int wrap_width, int *w, int *h) {
    return ::TTF_GetStringSizeWrapped(value_, text, length, wrap_width, w, h) ? Status() : Status::FromSdl();
  }
  Status MeasureString(const char *text, size_t length, int max_width, int *measured_width, size_t *measured_length) {
    return ::TTF_MeasureString(value_, text, length, max_width, measured_width, measured_length) ? Status() : Status::FromSdl();
  }
 private:
  explicit Font(TTF_Font* value) : value_(value), engaged_(true) {}
  TTF_Font* value_{};
  bool engaged_ = false;
};

// RAII owner for TTF_TextEngine (destroyed with TTF_DestroyRendererTextEngine).
class TextEngine {
 public:
  static Result<TextEngine> CreateRendererTextEngine(SDL_Renderer *renderer) {
    TTF_TextEngine* created_ = ::TTF_CreateRendererTextEngine(renderer);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return TextEngine(created_);
  }

  TextEngine() = default;
  ~TextEngine() { reset(); }
  TextEngine(TextEngine&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  TextEngine& operator=(TextEngine&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  TextEngine(const TextEngine&) = delete;
  TextEngine& operator=(const TextEngine&) = delete;

  TTF_TextEngine* get() const { return value_; }
  TTF_TextEngine* release() {
    TTF_TextEngine* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::TTF_DestroyRendererTextEngine(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  void DestroySurfaceTextEngine() { ::TTF_DestroySurfaceTextEngine(value_); }
  void DestroyGPUTextEngine() { ::TTF_DestroyGPUTextEngine(value_); }
  void SetGPUTextEngineWinding(TTF_GPUTextEngineWinding winding) { ::TTF_SetGPUTextEngineWinding(value_, winding); }
  TTF_GPUTextEngineWinding GetGPUTextEngineWinding() {
    return ::TTF_GetGPUTextEngineWinding(value_);
  }
 private:
  explicit TextEngine(TTF_TextEngine* value) : value_(value), engaged_(true) {}
  TTF_TextEngine* value_{};
  bool engaged_ = false;
};

// RAII owner for TTF_Text (destroyed with TTF_DestroyText).
class Text {
 public:
  static Result<Text> CreateText(TTF_TextEngine *engine, TTF_Font *font, const char *text, size_t length) {
    TTF_Text* created_ = ::TTF_CreateText(engine, font, text, length);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Text(created_);
  }

  Text() = default;
  ~Text() { reset(); }
  Text(Text&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Text& operator=(Text&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Text(const Text&) = delete;
  Text& operator=(const Text&) = delete;

  TTF_Text* get() const { return value_; }
  TTF_Text* release() {
    TTF_Text* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::TTF_DestroyText(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  Status DrawSurfaceText(int x, int y, SDL_Surface *surface) {
    return ::TTF_DrawSurfaceText(value_, x, y, surface) ? Status() : Status::FromSdl();
  }
  Status DrawRendererText(float x, float y) {
    return ::TTF_DrawRendererText(value_, x, y) ? Status() : Status::FromSdl();
  }
  TTF_GPUAtlasDrawSequence* GetGPUTextDrawData() {
    return ::TTF_GetGPUTextDrawData(value_);
  }
  SDL_PropertiesID GetTextProperties() {
    return ::TTF_GetTextProperties(value_);
  }
  Status SetTextEngine(TTF_TextEngine *engine) {
    return ::TTF_SetTextEngine(value_, engine) ? Status() : Status::FromSdl();
  }
  TTF_TextEngine* GetTextEngine() {
    return ::TTF_GetTextEngine(value_);
  }
  Status SetTextFont(TTF_Font *font) {
    return ::TTF_SetTextFont(value_, font) ? Status() : Status::FromSdl();
  }
  TTF_Font* GetTextFont() {
    return ::TTF_GetTextFont(value_);
  }
  Status SetTextColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    return ::TTF_SetTextColor(value_, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status SetTextColorFloat(float r, float g, float b, float a) {
    return ::TTF_SetTextColorFloat(value_, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status GetTextColor(Uint8 *r, Uint8 *g, Uint8 *b, Uint8 *a) {
    return ::TTF_GetTextColor(value_, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status GetTextColorFloat(float *r, float *g, float *b, float *a) {
    return ::TTF_GetTextColorFloat(value_, r, g, b, a) ? Status() : Status::FromSdl();
  }
  Status SetTextPosition(int x, int y) {
    return ::TTF_SetTextPosition(value_, x, y) ? Status() : Status::FromSdl();
  }
  Status GetTextPosition(int *x, int *y) {
    return ::TTF_GetTextPosition(value_, x, y) ? Status() : Status::FromSdl();
  }
  Status SetTextWrapWidth(int wrap_width) {
    return ::TTF_SetTextWrapWidth(value_, wrap_width) ? Status() : Status::FromSdl();
  }
  Status GetTextWrapWidth(int *wrap_width) {
    return ::TTF_GetTextWrapWidth(value_, wrap_width) ? Status() : Status::FromSdl();
  }
  Status SetTextWrapWhitespaceVisible(bool visible) {
    return ::TTF_SetTextWrapWhitespaceVisible(value_, visible) ? Status() : Status::FromSdl();
  }
  Status TextWrapWhitespaceVisible() {
    return ::TTF_TextWrapWhitespaceVisible(value_) ? Status() : Status::FromSdl();
  }
  Status SetTextString(const char *string, size_t length) {
    return ::TTF_SetTextString(value_, string, length) ? Status() : Status::FromSdl();
  }
  Status InsertTextString(int offset, const char *string, size_t length) {
    return ::TTF_InsertTextString(value_, offset, string, length) ? Status() : Status::FromSdl();
  }
  Status AppendTextString(const char *string, size_t length) {
    return ::TTF_AppendTextString(value_, string, length) ? Status() : Status::FromSdl();
  }
  Status DeleteTextString(int offset, int length) {
    return ::TTF_DeleteTextString(value_, offset, length) ? Status() : Status::FromSdl();
  }
  Status GetTextSize(int *w, int *h) {
    return ::TTF_GetTextSize(value_, w, h) ? Status() : Status::FromSdl();
  }
  Status GetTextSubString(int offset, TTF_SubString *substring) {
    return ::TTF_GetTextSubString(value_, offset, substring) ? Status() : Status::FromSdl();
  }
  Status GetTextSubStringForLine(int line, TTF_SubString *substring) {
    return ::TTF_GetTextSubStringForLine(value_, line, substring) ? Status() : Status::FromSdl();
  }
  TTF_SubString** GetTextSubStringsForRange(int offset, int length, int *count) {
    return ::TTF_GetTextSubStringsForRange(value_, offset, length, count);
  }
  Status GetTextSubStringForPoint(int x, int y, TTF_SubString *substring) {
    return ::TTF_GetTextSubStringForPoint(value_, x, y, substring) ? Status() : Status::FromSdl();
  }
  Status GetPreviousTextSubString(const TTF_SubString *substring, TTF_SubString *previous) {
    return ::TTF_GetPreviousTextSubString(value_, substring, previous) ? Status() : Status::FromSdl();
  }
  Status GetNextTextSubString(const TTF_SubString *substring, TTF_SubString *next) {
    return ::TTF_GetNextTextSubString(value_, substring, next) ? Status() : Status::FromSdl();
  }
  Status UpdateText() {
    return ::TTF_UpdateText(value_) ? Status() : Status::FromSdl();
  }
 private:
  explicit Text(TTF_Text* value) : value_(value), engaged_(true) {}
  TTF_Text* value_{};
  bool engaged_ = false;
};

// RAII owner for SDL_Surface (destroyed with SDL_DestroySurface).
class Surface {
 public:
  static Result<Surface> RenderText_Solid(TTF_Font *font, const char *text, size_t length, SDL_Color fg) {
    SDL_Surface* created_ = ::TTF_RenderText_Solid(font, text, length, fg);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> RenderText_Solid_Wrapped(TTF_Font *font, const char *text, size_t length, SDL_Color fg, int wrapLength) {
    SDL_Surface* created_ = ::TTF_RenderText_Solid_Wrapped(font, text, length, fg, wrapLength);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> RenderGlyph_Solid(TTF_Font *font, Uint32 ch, SDL_Color fg) {
    SDL_Surface* created_ = ::TTF_RenderGlyph_Solid(font, ch, fg);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> RenderText_Shaded(TTF_Font *font, const char *text, size_t length, SDL_Color fg, SDL_Color bg) {
    SDL_Surface* created_ = ::TTF_RenderText_Shaded(font, text, length, fg, bg);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> RenderText_Shaded_Wrapped(TTF_Font *font, const char *text, size_t length, SDL_Color fg, SDL_Color bg, int wrap_width) {
    SDL_Surface* created_ = ::TTF_RenderText_Shaded_Wrapped(font, text, length, fg, bg, wrap_width);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> RenderGlyph_Shaded(TTF_Font *font, Uint32 ch, SDL_Color fg, SDL_Color bg) {
    SDL_Surface* created_ = ::TTF_RenderGlyph_Shaded(font, ch, fg, bg);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> RenderText_Blended(TTF_Font *font, const char *text, size_t length, SDL_Color fg) {
    SDL_Surface* created_ = ::TTF_RenderText_Blended(font, text, length, fg);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> RenderText_Blended_Wrapped(TTF_Font *font, const char *text, size_t length, SDL_Color fg, int wrap_width) {
    SDL_Surface* created_ = ::TTF_RenderText_Blended_Wrapped(font, text, length, fg, wrap_width);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> RenderGlyph_Blended(TTF_Font *font, Uint32 ch, SDL_Color fg) {
    SDL_Surface* created_ = ::TTF_RenderGlyph_Blended(font, ch, fg);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> RenderText_LCD(TTF_Font *font, const char *text, size_t length, SDL_Color fg, SDL_Color bg) {
    SDL_Surface* created_ = ::TTF_RenderText_LCD(font, text, length, fg, bg);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> RenderText_LCD_Wrapped(TTF_Font *font, const char *text, size_t length, SDL_Color fg, SDL_Color bg, int wrap_width) {
    SDL_Surface* created_ = ::TTF_RenderText_LCD_Wrapped(font, text, length, fg, bg, wrap_width);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }
  static Result<Surface> RenderGlyph_LCD(TTF_Font *font, Uint32 ch, SDL_Color fg, SDL_Color bg) {
    SDL_Surface* created_ = ::TTF_RenderGlyph_LCD(font, ch, fg, bg);
    if (created_ == nullptr) {
      return Status::FromSdl();
    }
    return Surface(created_);
  }

  Surface() = default;
  ~Surface() { reset(); }
  Surface(Surface&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  Surface& operator=(Surface&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  Surface(const Surface&) = delete;
  Surface& operator=(const Surface&) = delete;

  SDL_Surface* get() const { return value_; }
  SDL_Surface* release() {
    SDL_Surface* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::SDL_DestroySurface(value_);
    value_ = nullptr;
    engaged_ = false;
  }

 private:
  explicit Surface(SDL_Surface* value) : value_(value), engaged_(true) {}
  SDL_Surface* value_{};
  bool engaged_ = false;
};

// bool-returning C functions surfaced as Status.
inline Status Init() {
  return ::TTF_Init() ? Status() : Status::FromSdl();
}

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& CreateGPUTextEngine = ::TTF_CreateGPUTextEngine;
inline constexpr auto& CreateGPUTextEngineWithProperties = ::TTF_CreateGPUTextEngineWithProperties;
inline constexpr auto& CreateRendererTextEngineWithProperties = ::TTF_CreateRendererTextEngineWithProperties;
inline constexpr auto& CreateSurfaceTextEngine = ::TTF_CreateSurfaceTextEngine;
inline constexpr auto& GetFreeTypeVersion = ::TTF_GetFreeTypeVersion;
inline constexpr auto& GetHarfBuzzVersion = ::TTF_GetHarfBuzzVersion;
inline constexpr auto& Quit = ::TTF_Quit;
inline constexpr auto& StringToTag = ::TTF_StringToTag;
inline constexpr auto& TagToString = ::TTF_TagToString;
inline constexpr auto& Version = ::TTF_Version;
inline constexpr auto& WasInit = ::TTF_WasInit;

}  // namespace ttf
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_TTF_H_
// clang-format on
