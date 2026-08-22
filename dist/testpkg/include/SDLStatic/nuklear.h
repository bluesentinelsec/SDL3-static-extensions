/**
 * @file nuklear.h
 * @brief The vendored Nuklear header with this project's configuration.
 *
 * Include THIS header (not the raw vendored one) so every translation unit
 * sees the same NK_INCLUDE_* configuration that the library was compiled
 * with — mismatched defines across TUs are the classic single-header bug.
 * The implementation lives in exactly one TU inside SDLStatic::GUI.
 *
 * Nuklear is vendored as-is (v4.13.3, dual MIT/public-domain; provenance
 * in deps/nuklear.md). See the upstream docs for the full immediate-mode
 * API: https://immediate-mode-ui.github.io/Nuklear/
 */
#ifndef SDLSTATIC_NUKLEAR_H
#define SDLSTATIC_NUKLEAR_H

/* Buttons fire on release (standard desktop behavior), which also keeps
 * clicks working when an event loop delivers press+release in one frame. */
#define NK_BUTTON_TRIGGER_ON_RELEASE

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_BOOL
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT

/* Nuklear's built-in double->string conversion is documented upstream as
 * "imprecise and possibly unsafe"; it emits exponent form for ordinary
 * values, which its own %f formatter then mis-parses (40.0 renders as
 * "4"). Route conversion through SDL's printf, which is always present
 * here, so nk_labelf/nk_text formatting is correct. */
#define NK_DTOA(buffer, value) SDLStatic_NuklearDtoa((buffer), (value))
#ifdef __cplusplus
extern "C" {
#endif
extern char *SDLStatic_NuklearDtoa(char *buffer, double value);
#ifdef __cplusplus
}
#endif

#include <nuklear.h>

#endif /* SDLSTATIC_NUKLEAR_H */
