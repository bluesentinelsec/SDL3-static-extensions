/*
 * gen_support_ruby.h — marshaling runtime for the GENERATED mruby
 * bindings. Hand-written support code (original SDLStatic, zlib); the
 * generated per-library stub files include this. Same handle model as
 * the Lua side: boxed pointer + C type name + optional destructor, with
 * dfree running the destructor exactly once and bound destroy functions
 * emptying the box first.
 */
#ifndef SDLSTATIC_GEN_SUPPORT_RUBY_H
#define SDLSTATIC_GEN_SUPPORT_RUBY_H

#include <SDLStatic/ruby.h>

#include <mruby/array.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/hash.h>
#include <mruby/string.h>
#include <mruby/variable.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*SDLStaticGen_Dtor)(void *ptr);

typedef struct SDLStaticGen_RubyHandle
{
    void *ptr;
    const char *ctype;
    SDLStaticGen_Dtor dtor;
} SDLStaticGen_RubyHandle;

extern const struct mrb_data_type SDLStaticGen_RubyHandleType;

/** Push a borrowed pointer (nil for NULL). */
extern mrb_value SDLStaticGen_RubyPushHandle(mrb_state *mrb, void *ptr,
                                             const char *ctype);
/** Push an owned pointer; GC calls dtor unless taken first. */
extern mrb_value SDLStaticGen_RubyPushOwned(mrb_state *mrb, void *ptr,
                                            const char *ctype,
                                            SDLStaticGen_Dtor dtor);
/** Handle argument -> pointer; nil -> NULL; wrong type raises TypeError. */
extern void *SDLStaticGen_RubyCheckHandle(mrb_state *mrb, mrb_value v,
                                          const char *ctype);
/** Like check, but empties the box (ownership leaves Ruby). */
extern void *SDLStaticGen_RubyTakeHandle(mrb_state *mrb, mrb_value v,
                                         const char *ctype);

/** Hash-field readers for generated POD converters (0/false when absent). */
extern mrb_int SDLStaticGen_RubyFieldInt(mrb_state *mrb, mrb_value hash,
                                         const char *field);
extern mrb_float SDLStaticGen_RubyFieldNum(mrb_state *mrb, mrb_value hash,
                                           const char *field);
extern mrb_bool SDLStaticGen_RubyFieldBool(mrb_state *mrb, mrb_value hash,
                                           const char *field);
extern void SDLStaticGen_RubyHashSet(mrb_state *mrb, mrb_value hash,
                                     const char *field, mrb_value v);
extern mrb_value SDLStaticGen_RubyFieldGet(mrb_state *mrb, mrb_value hash,
                                           const char *field);

/** Lenient argument converters (nil/absent -> 0/NULL/false). */
extern mrb_int SDLStaticGen_RubyToInt(mrb_state *mrb, mrb_value v);
extern mrb_float SDLStaticGen_RubyToNum(mrb_state *mrb, mrb_value v);
extern mrb_bool SDLStaticGen_RubyToBool(mrb_value v);
extern const char *SDLStaticGen_RubyToStr(mrb_state *mrb, mrb_value v);
extern const char *SDLStaticGen_RubyToBlob(mrb_state *mrb, mrb_value v,
                                           size_t *len);

/** Register the shared Handle class; called by each module opener. */
extern void SDLStaticGen_RubyEnsureHandleClass(mrb_state *mrb);

#ifdef __cplusplus
}
#endif

#endif /* SDLSTATIC_GEN_SUPPORT_RUBY_H */
