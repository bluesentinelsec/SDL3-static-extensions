// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: tomlc99
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_TOML_H_
#define SDLSTATIC_CPP_GEN_TOML_H_

#include <toml.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace toml {

// RAII owner for toml_table_t (destroyed with toml_free).
class TomlTable {
 public:
  static Result<TomlTable> parse(char *conf, char *errbuf, int errbufsz) {
    toml_table_t* created_ = ::toml_parse(conf, errbuf, errbufsz);
    if (created_ == nullptr) {
      return Status::Error("toml_parse failed");
    }
    return TomlTable(created_);
  }

  TomlTable() = default;
  ~TomlTable() { reset(); }
  TomlTable(TomlTable&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  TomlTable& operator=(TomlTable&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  TomlTable(const TomlTable&) = delete;
  TomlTable& operator=(const TomlTable&) = delete;

  toml_table_t* get() const { return value_; }
  toml_table_t* release() {
    toml_table_t* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::toml_free(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  const char* key_in(int keyidx) {
    return ::toml_key_in(value_, keyidx);
  }
  int key_exists(const char *key) {
    return ::toml_key_exists(value_, key);
  }
  toml_datum_t string_in(const char *key) {
    return ::toml_string_in(value_, key);
  }
  toml_datum_t bool_in(const char *key) {
    return ::toml_bool_in(value_, key);
  }
  toml_datum_t int_in(const char *key) {
    return ::toml_int_in(value_, key);
  }
  toml_datum_t double_in(const char *key) {
    return ::toml_double_in(value_, key);
  }
  toml_datum_t timestamp_in(const char *key) {
    return ::toml_timestamp_in(value_, key);
  }
  toml_array_t* array_in(const char *key) {
    return ::toml_array_in(value_, key);
  }
  toml_table_t* table_in(const char *key) {
    return ::toml_table_in(value_, key);
  }
  int table_nkval() {
    return ::toml_table_nkval(value_);
  }
  int table_narr() {
    return ::toml_table_narr(value_);
  }
  int table_ntab() {
    return ::toml_table_ntab(value_);
  }
  const char* table_key() {
    return ::toml_table_key(value_);
  }
  toml_raw_t raw_in(const char *key) {
    return ::toml_raw_in(value_, key);
  }
 private:
  explicit TomlTable(toml_table_t* value) : value_(value), engaged_(true) {}
  toml_table_t* value_{};
  bool engaged_ = false;
};

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& array_at = ::toml_array_at;
inline constexpr auto& array_key = ::toml_array_key;
inline constexpr auto& array_kind = ::toml_array_kind;
inline constexpr auto& array_nelem = ::toml_array_nelem;
inline constexpr auto& array_type = ::toml_array_type;
inline constexpr auto& bool_at = ::toml_bool_at;
inline constexpr auto& double_at = ::toml_double_at;
inline constexpr auto& int_at = ::toml_int_at;
inline constexpr auto& parse_file = ::toml_parse_file;
inline constexpr auto& raw_at = ::toml_raw_at;
inline constexpr auto& rtob = ::toml_rtob;
inline constexpr auto& rtod = ::toml_rtod;
inline constexpr auto& rtod_ex = ::toml_rtod_ex;
inline constexpr auto& rtoi = ::toml_rtoi;
inline constexpr auto& rtos = ::toml_rtos;
inline constexpr auto& rtots = ::toml_rtots;
inline constexpr auto& set_memutil = ::toml_set_memutil;
inline constexpr auto& string_at = ::toml_string_at;
inline constexpr auto& table_at = ::toml_table_at;
inline constexpr auto& timestamp_at = ::toml_timestamp_at;
inline constexpr auto& ucs_to_utf8 = ::toml_ucs_to_utf8;
inline constexpr auto& utf8_to_ucs = ::toml_utf8_to_ucs;

}  // namespace toml
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_TOML_H_
// clang-format on
