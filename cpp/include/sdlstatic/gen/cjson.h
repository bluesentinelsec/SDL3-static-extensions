// GENERATED FILE - DO NOT EDIT.
// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)
// Library: cJSON
// clang-format off
#ifndef SDLSTATIC_CPP_GEN_CJSON_H_
#define SDLSTATIC_CPP_GEN_CJSON_H_

#include <cJSON.h>

#include "sdlstatic/status.h"

namespace sdlstatic {
namespace json {

// RAII owner for cJSON (destroyed with cJSON_Delete).
class JsonDocument {
 public:
  static Result<JsonDocument> Parse(const char *value) {
    cJSON* created_ = ::cJSON_Parse(value);
    if (created_ == nullptr) {
      return Status::Error("cJSON_Parse failed");
    }
    return JsonDocument(created_);
  }
  static Result<JsonDocument> ParseWithLength(const char *value, size_t buffer_length) {
    cJSON* created_ = ::cJSON_ParseWithLength(value, buffer_length);
    if (created_ == nullptr) {
      return Status::Error("cJSON_ParseWithLength failed");
    }
    return JsonDocument(created_);
  }
  static Result<JsonDocument> CreateArray() {
    cJSON* created_ = ::cJSON_CreateArray();
    if (created_ == nullptr) {
      return Status::Error("cJSON_CreateArray failed");
    }
    return JsonDocument(created_);
  }
  static Result<JsonDocument> CreateObject() {
    cJSON* created_ = ::cJSON_CreateObject();
    if (created_ == nullptr) {
      return Status::Error("cJSON_CreateObject failed");
    }
    return JsonDocument(created_);
  }

  JsonDocument() = default;
  ~JsonDocument() { reset(); }
  JsonDocument(JsonDocument&& other) noexcept
      : value_(other.value_), engaged_(other.engaged_) {
    other.value_ = nullptr;
    other.engaged_ = false;
  }
  JsonDocument& operator=(JsonDocument&& other) noexcept {
    if (this != &other) {
      reset();
      value_ = other.value_;
      engaged_ = other.engaged_;
      other.value_ = nullptr;
      other.engaged_ = false;
    }
    return *this;
  }
  JsonDocument(const JsonDocument&) = delete;
  JsonDocument& operator=(const JsonDocument&) = delete;

  cJSON* get() const { return value_; }
  cJSON* release() {
    cJSON* out = value_;
    value_ = nullptr;
    engaged_ = false;
    return out;
  }
  void reset() {
    if (value_ != nullptr) ::cJSON_Delete(value_);
    value_ = nullptr;
    engaged_ = false;
  }

  char* Print() {
    return ::cJSON_Print(value_);
  }
  char* PrintUnformatted() {
    return ::cJSON_PrintUnformatted(value_);
  }
  char* PrintBuffered(int prebuffer, cJSON_bool fmt) {
    return ::cJSON_PrintBuffered(value_, prebuffer, fmt);
  }
  cJSON_bool PrintPreallocated(char *buffer, const int length, const cJSON_bool format) {
    return ::cJSON_PrintPreallocated(value_, buffer, length, format);
  }
  int GetArraySize() {
    return ::cJSON_GetArraySize(value_);
  }
  cJSON* GetArrayItem(int index) {
    return ::cJSON_GetArrayItem(value_, index);
  }
  cJSON* GetObjectItem(const char * const string) {
    return ::cJSON_GetObjectItem(value_, string);
  }
  cJSON* GetObjectItemCaseSensitive(const char * const string) {
    return ::cJSON_GetObjectItemCaseSensitive(value_, string);
  }
  cJSON_bool HasObjectItem(const char *string) {
    return ::cJSON_HasObjectItem(value_, string);
  }
  char* GetStringValue() {
    return ::cJSON_GetStringValue(value_);
  }
  double GetNumberValue() {
    return ::cJSON_GetNumberValue(value_);
  }
  cJSON_bool IsInvalid() {
    return ::cJSON_IsInvalid(value_);
  }
  cJSON_bool IsFalse() {
    return ::cJSON_IsFalse(value_);
  }
  cJSON_bool IsTrue() {
    return ::cJSON_IsTrue(value_);
  }
  cJSON_bool IsBool() {
    return ::cJSON_IsBool(value_);
  }
  cJSON_bool IsNull() {
    return ::cJSON_IsNull(value_);
  }
  cJSON_bool IsNumber() {
    return ::cJSON_IsNumber(value_);
  }
  cJSON_bool IsString() {
    return ::cJSON_IsString(value_);
  }
  cJSON_bool IsArray() {
    return ::cJSON_IsArray(value_);
  }
  cJSON_bool IsObject() {
    return ::cJSON_IsObject(value_);
  }
  cJSON_bool IsRaw() {
    return ::cJSON_IsRaw(value_);
  }
  cJSON* CreateObjectReference() {
    return ::cJSON_CreateObjectReference(value_);
  }
  cJSON* CreateArrayReference() {
    return ::cJSON_CreateArrayReference(value_);
  }
  cJSON_bool AddItemToArray(cJSON *item) {
    return ::cJSON_AddItemToArray(value_, item);
  }
  cJSON_bool AddItemToObject(const char *string, cJSON *item) {
    return ::cJSON_AddItemToObject(value_, string, item);
  }
  cJSON_bool AddItemToObjectCS(const char *string, cJSON *item) {
    return ::cJSON_AddItemToObjectCS(value_, string, item);
  }
  cJSON_bool AddItemReferenceToArray(cJSON *item) {
    return ::cJSON_AddItemReferenceToArray(value_, item);
  }
  cJSON_bool AddItemReferenceToObject(const char *string, cJSON *item) {
    return ::cJSON_AddItemReferenceToObject(value_, string, item);
  }
  cJSON* DetachItemViaPointer(cJSON * const item) {
    return ::cJSON_DetachItemViaPointer(value_, item);
  }
  cJSON* DetachItemFromArray(int which) {
    return ::cJSON_DetachItemFromArray(value_, which);
  }
  void DeleteItemFromArray(int which) { ::cJSON_DeleteItemFromArray(value_, which); }
  cJSON* DetachItemFromObject(const char *string) {
    return ::cJSON_DetachItemFromObject(value_, string);
  }
  cJSON* DetachItemFromObjectCaseSensitive(const char *string) {
    return ::cJSON_DetachItemFromObjectCaseSensitive(value_, string);
  }
  void DeleteItemFromObject(const char *string) { ::cJSON_DeleteItemFromObject(value_, string); }
  void DeleteItemFromObjectCaseSensitive(const char *string) { ::cJSON_DeleteItemFromObjectCaseSensitive(value_, string); }
  cJSON_bool InsertItemInArray(int which, cJSON *newitem) {
    return ::cJSON_InsertItemInArray(value_, which, newitem);
  }
  cJSON_bool ReplaceItemViaPointer(cJSON * const item, cJSON * replacement) {
    return ::cJSON_ReplaceItemViaPointer(value_, item, replacement);
  }
  cJSON_bool ReplaceItemInArray(int which, cJSON *newitem) {
    return ::cJSON_ReplaceItemInArray(value_, which, newitem);
  }
  cJSON_bool ReplaceItemInObject(const char *string, cJSON *newitem) {
    return ::cJSON_ReplaceItemInObject(value_, string, newitem);
  }
  cJSON_bool ReplaceItemInObjectCaseSensitive(const char *string, cJSON *newitem) {
    return ::cJSON_ReplaceItemInObjectCaseSensitive(value_, string, newitem);
  }
  cJSON* Duplicate(cJSON_bool recurse) {
    return ::cJSON_Duplicate(value_, recurse);
  }
  cJSON_bool Compare(const cJSON * const b, const cJSON_bool case_sensitive) {
    return ::cJSON_Compare(value_, b, case_sensitive);
  }
  cJSON* AddNullToObject(const char * const name) {
    return ::cJSON_AddNullToObject(value_, name);
  }
  cJSON* AddTrueToObject(const char * const name) {
    return ::cJSON_AddTrueToObject(value_, name);
  }
  cJSON* AddFalseToObject(const char * const name) {
    return ::cJSON_AddFalseToObject(value_, name);
  }
  cJSON* AddBoolToObject(const char * const name, const cJSON_bool boolean) {
    return ::cJSON_AddBoolToObject(value_, name, boolean);
  }
  cJSON* AddNumberToObject(const char * const name, const double number) {
    return ::cJSON_AddNumberToObject(value_, name, number);
  }
  cJSON* AddStringToObject(const char * const name, const char * const string) {
    return ::cJSON_AddStringToObject(value_, name, string);
  }
  cJSON* AddRawToObject(const char * const name, const char * const raw) {
    return ::cJSON_AddRawToObject(value_, name, raw);
  }
  cJSON* AddObjectToObject(const char * const name) {
    return ::cJSON_AddObjectToObject(value_, name);
  }
  cJSON* AddArrayToObject(const char * const name) {
    return ::cJSON_AddArrayToObject(value_, name);
  }
  double SetNumberHelper(double number) {
    return ::cJSON_SetNumberHelper(value_, number);
  }
  char* SetValuestring(const char *valuestring) {
    return ::cJSON_SetValuestring(value_, valuestring);
  }
 private:
  explicit JsonDocument(cJSON* value) : value_(value), engaged_(true) {}
  cJSON* value_{};
  bool engaged_ = false;
};

// Everything else, aliased into the namespace unchanged.
inline constexpr auto& CreateBool = ::cJSON_CreateBool;
inline constexpr auto& CreateDoubleArray = ::cJSON_CreateDoubleArray;
inline constexpr auto& CreateFalse = ::cJSON_CreateFalse;
inline constexpr auto& CreateFloatArray = ::cJSON_CreateFloatArray;
inline constexpr auto& CreateIntArray = ::cJSON_CreateIntArray;
inline constexpr auto& CreateNull = ::cJSON_CreateNull;
inline constexpr auto& CreateNumber = ::cJSON_CreateNumber;
inline constexpr auto& CreateRaw = ::cJSON_CreateRaw;
inline constexpr auto& CreateString = ::cJSON_CreateString;
inline constexpr auto& CreateStringArray = ::cJSON_CreateStringArray;
inline constexpr auto& CreateStringReference = ::cJSON_CreateStringReference;
inline constexpr auto& CreateTrue = ::cJSON_CreateTrue;
inline constexpr auto& GetErrorPtr = ::cJSON_GetErrorPtr;
inline constexpr auto& InitHooks = ::cJSON_InitHooks;
inline constexpr auto& Minify = ::cJSON_Minify;
inline constexpr auto& ParseWithLengthOpts = ::cJSON_ParseWithLengthOpts;
inline constexpr auto& ParseWithOpts = ::cJSON_ParseWithOpts;
inline constexpr auto& Version = ::cJSON_Version;
inline constexpr auto& free = ::cJSON_free;
inline constexpr auto& malloc = ::cJSON_malloc;

}  // namespace json
}  // namespace sdlstatic

#endif  // SDLSTATIC_CPP_GEN_CJSON_H_
// clang-format on
