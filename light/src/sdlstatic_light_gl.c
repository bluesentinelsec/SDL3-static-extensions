/*
 * sdlstatic_light_gl.c — the shader path for SDLStatic::Light.
 * Original SDLStatic code (zlib).
 *
 * When SDL's renderer is running on OpenGL or OpenGL ES, the light map is
 * produced by a fragment shader instead of by triangle fans: per-pixel
 * falloff, per-pixel cones, and shadows raymarched against an occluder
 * mask. That is what "hardware accelerated lighting" means here — the work
 * is done by the GPU, once per pixel, rather than by the CPU building
 * geometry.
 *
 * Three deliberate choices:
 *
 *   No link-time GL dependency. Every entry point is fetched through
 *   SDL_GL_GetProcAddress, so the project keeps its "no external
 *   libraries" property and the same binary works whether the renderer
 *   ends up on GL, GLES or something else entirely.
 *
 *   GLSL 1.x. SDL's OpenGL renderer creates a 2.1-era context on macOS and
 *   an ES2/WebGL context can turn up on mobile and the web. A shader
 *   requiring #version 330 would fail exactly where portability matters.
 *
 *   Shared surface with the fallback. This produces the same light map the
 *   geometry path does, so compositing, the camera, the day/night cycle
 *   and the gameplay queries are identical either way, and a machine
 *   without GL still lights its scene.
 */
#include "light_internal.h"

#include "light_shaders.h"

/* --- the slice of GL this needs, loaded at runtime ---------------------- */

typedef unsigned int GLenum;
typedef unsigned int GLuint;
typedef int GLint;
typedef int GLsizei;
typedef float GLfloat;
typedef char GLchar;
typedef unsigned char GLboolean;

#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
#define GL_FLOAT 0x1406
#define GL_FALSE 0
#define GL_TRIANGLES 0x0004
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE_2D 0x0DE1
#define GL_BLEND 0x0BE2
#define GL_SCISSOR_TEST 0x0C11
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_VIEWPORT 0x0BA2
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_LUMINANCE 0x1909
#define GL_UNSIGNED_BYTE 0x1401
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_LINEAR 0x2601
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_ONE 1
/* The separate RGB/alpha factors, not the old GL_BLEND_SRC/GL_BLEND_DST:
 * those do not exist in GLES2 or WebGL, where querying them returns
 * nothing and feeding the result back to glBlendFunc is an error that
 * leaves the whole renderer blending wrongly. */
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645

/* The occluder mask is rasterised on the CPU. It follows the light map's
 * resolution — sharper shadows on a bigger window — but is capped, because
 * it is uploaded every frame and it is a blocking test rather than
 * something the player looks at. The cap is what bounds both the upload
 * and the raymarch's sampling cost. */
#define MASK_MAX_W 768
#define MASK_MAX_H 432
#define MASK_MIN_W 192
#define MASK_MIN_H 108

typedef GLuint(GLAPIENTRY_UNUSED *PFN_glCreateShader)(GLenum);
typedef void(GLAPIENTRY_UNUSED *PFN_glShaderSource)(GLuint, GLsizei, const GLchar *const *,
                                                  const GLint *);
typedef void(GLAPIENTRY_UNUSED *PFN_glCompileShader)(GLuint);
typedef void(GLAPIENTRY_UNUSED *PFN_glGetShaderiv)(GLuint, GLenum, GLint *);
typedef void(GLAPIENTRY_UNUSED *PFN_glGetShaderInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
typedef void(GLAPIENTRY_UNUSED *PFN_glDeleteShader)(GLuint);
typedef GLuint(GLAPIENTRY_UNUSED *PFN_glCreateProgram)(void);
typedef void(GLAPIENTRY_UNUSED *PFN_glAttachShader)(GLuint, GLuint);
typedef void(GLAPIENTRY_UNUSED *PFN_glBindAttribLocation)(GLuint, GLuint, const GLchar *);
typedef void(GLAPIENTRY_UNUSED *PFN_glLinkProgram)(GLuint);
typedef void(GLAPIENTRY_UNUSED *PFN_glGetProgramiv)(GLuint, GLenum, GLint *);
typedef void(GLAPIENTRY_UNUSED *PFN_glGetProgramInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
typedef void(GLAPIENTRY_UNUSED *PFN_glDeleteProgram)(GLuint);
typedef void(GLAPIENTRY_UNUSED *PFN_glUseProgram)(GLuint);
typedef GLint(GLAPIENTRY_UNUSED *PFN_glGetUniformLocation)(GLuint, const GLchar *);
typedef void(GLAPIENTRY_UNUSED *PFN_glUniform1i)(GLint, GLint);
typedef void(GLAPIENTRY_UNUSED *PFN_glUniform1f)(GLint, GLfloat);
typedef void(GLAPIENTRY_UNUSED *PFN_glUniform2f)(GLint, GLfloat, GLfloat);
typedef void(GLAPIENTRY_UNUSED *PFN_glUniform3f)(GLint, GLfloat, GLfloat, GLfloat);
typedef void(GLAPIENTRY_UNUSED *PFN_glUniform4fv)(GLint, GLsizei, const GLfloat *);
typedef void(GLAPIENTRY_UNUSED *PFN_glGenBuffers)(GLsizei, GLuint *);
typedef void(GLAPIENTRY_UNUSED *PFN_glBindBuffer)(GLenum, GLuint);
typedef void(GLAPIENTRY_UNUSED *PFN_glBufferData)(GLenum, long, const void *, GLenum);
typedef void(GLAPIENTRY_UNUSED *PFN_glDeleteBuffers)(GLsizei, const GLuint *);
typedef void(GLAPIENTRY_UNUSED *PFN_glEnableVertexAttribArray)(GLuint);
typedef void(GLAPIENTRY_UNUSED *PFN_glDisableVertexAttribArray)(GLuint);
typedef void(GLAPIENTRY_UNUSED *PFN_glVertexAttribPointer)(GLuint, GLint, GLenum, GLboolean,
                                                         GLsizei, const void *);
typedef void(GLAPIENTRY_UNUSED *PFN_glDrawArrays)(GLenum, GLint, GLsizei);
typedef void(GLAPIENTRY_UNUSED *PFN_glActiveTexture)(GLenum);
typedef void(GLAPIENTRY_UNUSED *PFN_glBindTexture)(GLenum, GLuint);
typedef void(GLAPIENTRY_UNUSED *PFN_glDisable)(GLenum);
typedef void(GLAPIENTRY_UNUSED *PFN_glEnable)(GLenum);
typedef GLboolean(GLAPIENTRY_UNUSED *PFN_glIsEnabled)(GLenum);
typedef void(GLAPIENTRY_UNUSED *PFN_glGetIntegerv)(GLenum, GLint *);
typedef void(GLAPIENTRY_UNUSED *PFN_glViewport)(GLint, GLint, GLsizei, GLsizei);
typedef const unsigned char *(GLAPIENTRY_UNUSED *PFN_glGetString)(GLenum);
typedef void(GLAPIENTRY_UNUSED *PFN_glGenTextures)(GLsizei, GLuint *);
typedef void(GLAPIENTRY_UNUSED *PFN_glDeleteTextures)(GLsizei, const GLuint *);
typedef void(GLAPIENTRY_UNUSED *PFN_glTexImage2D)(GLenum, GLint, GLint, GLsizei, GLsizei,
                                                  GLint, GLenum, GLenum, const void *);
typedef void(GLAPIENTRY_UNUSED *PFN_glTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei,
                                                     GLsizei, GLenum, GLenum, const void *);
typedef void(GLAPIENTRY_UNUSED *PFN_glTexParameteri)(GLenum, GLenum, GLint);
typedef void(GLAPIENTRY_UNUSED *PFN_glPixelStorei)(GLenum, GLint);
typedef void(GLAPIENTRY_UNUSED *PFN_glBlendFunc)(GLenum, GLenum);
typedef void(GLAPIENTRY_UNUSED *PFN_glBlendFuncSeparate)(GLenum, GLenum, GLenum, GLenum);
typedef void(GLAPIENTRY_UNUSED *PFN_glGetVertexAttribiv)(GLuint, GLenum, GLint *);
typedef void(GLAPIENTRY_UNUSED *PFN_glGetVertexAttribPointerv)(GLuint, GLenum, void **);

struct LightGl
{
    PFN_glCreateShader CreateShader;
    PFN_glShaderSource ShaderSource;
    PFN_glCompileShader CompileShader;
    PFN_glGetShaderiv GetShaderiv;
    PFN_glGetShaderInfoLog GetShaderInfoLog;
    PFN_glDeleteShader DeleteShader;
    PFN_glCreateProgram CreateProgram;
    PFN_glAttachShader AttachShader;
    PFN_glBindAttribLocation BindAttribLocation;
    PFN_glLinkProgram LinkProgram;
    PFN_glGetProgramiv GetProgramiv;
    PFN_glGetProgramInfoLog GetProgramInfoLog;
    PFN_glDeleteProgram DeleteProgram;
    PFN_glUseProgram UseProgram;
    PFN_glGetUniformLocation GetUniformLocation;
    PFN_glUniform1i Uniform1i;
    PFN_glUniform1f Uniform1f;
    PFN_glUniform2f Uniform2f;
    PFN_glUniform3f Uniform3f;
    PFN_glUniform4fv Uniform4fv;
    PFN_glGenBuffers GenBuffers;
    PFN_glBindBuffer BindBuffer;
    PFN_glBufferData BufferData;
    PFN_glDeleteBuffers DeleteBuffers;
    PFN_glEnableVertexAttribArray EnableVertexAttribArray;
    PFN_glDisableVertexAttribArray DisableVertexAttribArray;
    PFN_glVertexAttribPointer VertexAttribPointer;
    PFN_glDrawArrays DrawArrays;
    PFN_glActiveTexture ActiveTexture;
    PFN_glBindTexture BindTexture;
    PFN_glDisable Disable;
    PFN_glEnable Enable;
    PFN_glIsEnabled IsEnabled;
    PFN_glGetIntegerv GetIntegerv;
    PFN_glViewport Viewport;
    PFN_glGetString GetString;
    PFN_glGenTextures GenTextures;
    PFN_glDeleteTextures DeleteTextures;
    PFN_glTexImage2D TexImage2D;
    PFN_glTexSubImage2D TexSubImage2D;
    PFN_glTexParameteri TexParameteri;
    PFN_glPixelStorei PixelStorei;
    PFN_glBlendFunc BlendFunc;
    PFN_glBlendFuncSeparate BlendFuncSeparate;
    PFN_glGetVertexAttribiv GetVertexAttribiv;
    PFN_glGetVertexAttribPointerv GetVertexAttribPointerv;

    GLuint mask_texture; /* our own: SDL does not hand out its texture ids */
    unsigned char *mask; /* CPU side, rasterised each frame */
    int mask_w, mask_h;  /* follows the light map, within the caps above */

    GLuint program;
    GLuint quad;
    GLint u_light_count;
    GLint u_resolution_vert;
    GLint u_resolution_frag;
    GLint u_light_pos;
    GLint u_light_color;
    GLint u_light_cone;
    GLint u_mask;
    GLint u_mask_size;
    GLint u_swizzle;
    GLint u_shadow_softness;
};

#define LOAD(field, name)                                                                      \
    do                                                                                         \
    {                                                                                          \
        gl->field = (PFN_gl##field)SDL_GL_GetProcAddress(name);                                \
        if (gl->field == NULL)                                                                 \
        {                                                                                      \
            SDL_SetError("OpenGL entry point %s is missing", name);                            \
            return false;                                                                      \
        }                                                                                      \
    } while (0)

static bool LoadEntryPoints(struct LightGl *gl)
{
    LOAD(CreateShader, "glCreateShader");
    LOAD(ShaderSource, "glShaderSource");
    LOAD(CompileShader, "glCompileShader");
    LOAD(GetShaderiv, "glGetShaderiv");
    LOAD(GetShaderInfoLog, "glGetShaderInfoLog");
    LOAD(DeleteShader, "glDeleteShader");
    LOAD(CreateProgram, "glCreateProgram");
    LOAD(AttachShader, "glAttachShader");
    LOAD(BindAttribLocation, "glBindAttribLocation");
    LOAD(LinkProgram, "glLinkProgram");
    LOAD(GetProgramiv, "glGetProgramiv");
    LOAD(GetProgramInfoLog, "glGetProgramInfoLog");
    LOAD(DeleteProgram, "glDeleteProgram");
    LOAD(UseProgram, "glUseProgram");
    LOAD(GetUniformLocation, "glGetUniformLocation");
    LOAD(Uniform1i, "glUniform1i");
    LOAD(Uniform1f, "glUniform1f");
    LOAD(Uniform2f, "glUniform2f");
    LOAD(Uniform3f, "glUniform3f");
    LOAD(Uniform4fv, "glUniform4fv");
    LOAD(GenBuffers, "glGenBuffers");
    LOAD(BindBuffer, "glBindBuffer");
    LOAD(BufferData, "glBufferData");
    LOAD(DeleteBuffers, "glDeleteBuffers");
    LOAD(EnableVertexAttribArray, "glEnableVertexAttribArray");
    LOAD(DisableVertexAttribArray, "glDisableVertexAttribArray");
    LOAD(VertexAttribPointer, "glVertexAttribPointer");
    LOAD(DrawArrays, "glDrawArrays");
    LOAD(ActiveTexture, "glActiveTexture");
    LOAD(BindTexture, "glBindTexture");
    LOAD(Disable, "glDisable");
    LOAD(Enable, "glEnable");
    LOAD(IsEnabled, "glIsEnabled");
    LOAD(GetIntegerv, "glGetIntegerv");
    LOAD(Viewport, "glViewport");
    LOAD(GetString, "glGetString");
    LOAD(GenTextures, "glGenTextures");
    LOAD(DeleteTextures, "glDeleteTextures");
    LOAD(TexImage2D, "glTexImage2D");
    LOAD(TexSubImage2D, "glTexSubImage2D");
    LOAD(TexParameteri, "glTexParameteri");
    LOAD(PixelStorei, "glPixelStorei");
    LOAD(BlendFunc, "glBlendFunc");
    LOAD(BlendFuncSeparate, "glBlendFuncSeparate");
    LOAD(GetVertexAttribiv, "glGetVertexAttribiv");
    LOAD(GetVertexAttribPointerv, "glGetVertexAttribPointerv");
    return true;
}

#undef LOAD

/* --- program ------------------------------------------------------------ */

static GLuint CompileStage(struct LightGl *gl, GLenum stage, const char *version,
                           const char *body)
{
    const GLchar *sources[2] = {version, body};
    const GLuint shader = gl->CreateShader(stage);
    if (shader == 0)
    {
        SDL_SetError("glCreateShader failed");
        return 0;
    }
    gl->ShaderSource(shader, 2, sources, NULL);
    gl->CompileShader(shader);

    GLint ok = 0;
    gl->GetShaderiv(shader, GL_COMPILE_STATUS, &ok);
    if (!ok)
    {
        char log[1024];
        GLsizei length = 0;
        gl->GetShaderInfoLog(shader, (GLsizei)sizeof(log) - 1, &length, log);
        log[(length > 0 && length < (GLsizei)sizeof(log)) ? length : 0] = '\0';
        SDL_SetError("%s shader failed to compile: %s",
                     (stage == GL_VERTEX_SHADER) ? "vertex" : "fragment", log);
        gl->DeleteShader(shader);
        return 0;
    }
    return shader;
}

/* ES contexts need "#version 100" and the desktop ones "#version 120"; the
 * shading-language string is the reliable way to tell them apart. */
static const char *VersionLine(struct LightGl *gl)
{
    const unsigned char *glsl = gl->GetString(GL_SHADING_LANGUAGE_VERSION);
    if (glsl != NULL && SDL_strstr((const char *)glsl, "ES") != NULL)
    {
        /* GL_ES is predefined in an ES context — defining it again is a
           compile error, and the shaders test it with #ifdef anyway. */
        return "#version 100\n";
    }
    return "#version 120\n";
}

static bool BuildProgram(struct LightGl *gl)
{
    const char *version = VersionLine(gl);
    const GLuint vertex = CompileStage(gl, GL_VERTEX_SHADER, version, kLightMapVert);
    if (vertex == 0)
    {
        return false;
    }
    const GLuint fragment = CompileStage(gl, GL_FRAGMENT_SHADER, version, kLightMapFrag);
    if (fragment == 0)
    {
        gl->DeleteShader(vertex);
        return false;
    }

    gl->program = gl->CreateProgram();
    gl->AttachShader(gl->program, vertex);
    gl->AttachShader(gl->program, fragment);
    /* Bound explicitly: GLSL 1.x has no layout qualifiers. */
    gl->BindAttribLocation(gl->program, 0, "a_position");
    gl->LinkProgram(gl->program);
    gl->DeleteShader(vertex);
    gl->DeleteShader(fragment);

    GLint ok = 0;
    gl->GetProgramiv(gl->program, GL_LINK_STATUS, &ok);
    if (!ok)
    {
        char log[1024];
        GLsizei length = 0;
        gl->GetProgramInfoLog(gl->program, (GLsizei)sizeof(log) - 1, &length, log);
        log[(length > 0 && length < (GLsizei)sizeof(log)) ? length : 0] = '\0';
        SDL_SetError("light shader failed to link: %s", log);
        gl->DeleteProgram(gl->program);
        gl->program = 0;
        return false;
    }

    gl->u_light_count = gl->GetUniformLocation(gl->program, "u_light_count");
    gl->u_resolution_frag = gl->GetUniformLocation(gl->program, "u_resolution");
    gl->u_resolution_vert = gl->GetUniformLocation(gl->program, "u_vert_resolution");
    gl->u_light_pos = gl->GetUniformLocation(gl->program, "u_light_pos");
    gl->u_light_color = gl->GetUniformLocation(gl->program, "u_light_color");
    gl->u_light_cone = gl->GetUniformLocation(gl->program, "u_light_cone");
    gl->u_mask = gl->GetUniformLocation(gl->program, "u_mask");
    gl->u_mask_size = gl->GetUniformLocation(gl->program, "u_mask_size");
    gl->u_swizzle = gl->GetUniformLocation(gl->program, "u_swizzle");
    gl->u_shadow_softness = gl->GetUniformLocation(gl->program, "u_shadow_softness");

    /* One triangle covering clip space — cheaper than two, and avoids the
       seam a quad's diagonal can show. */
    static const GLfloat vertices[6] = {-1.0f, -1.0f, 3.0f, -1.0f, -1.0f, 3.0f};
    gl->GenBuffers(1, &gl->quad);
    gl->BindBuffer(GL_ARRAY_BUFFER, gl->quad);
    gl->BufferData(GL_ARRAY_BUFFER, (long)sizeof(vertices), vertices, GL_STATIC_DRAW);
    gl->BindBuffer(GL_ARRAY_BUFFER, 0);

    /* The occluder mask. SDL's OpenGL renderer does not publish the GL id
       behind its textures in practice, so rather than depend on that this
       owns a texture outright and uploads a CPU-rasterised mask each
       frame. Single channel, no mipmaps, clamped: a lookup table. */
    gl->mask = (unsigned char *)SDL_calloc(1, MASK_MAX_W * MASK_MAX_H);
    if (gl->mask == NULL)
    {
        return false;
    }
    gl->GenTextures(1, &gl->mask_texture);
    gl->BindTexture(GL_TEXTURE_2D, gl->mask_texture);
    gl->PixelStorei(GL_UNPACK_ALIGNMENT, 1);
    gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    gl->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    gl->BindTexture(GL_TEXTURE_2D, 0);
    return true;
}

bool SDLStatic_LightGlInit(SDLStatic_LightScene *scene)
{
    /* Only meaningful on the GL renderers; everything else uses the
       geometry path, which produces the same light map on the CPU. */
    const char *name = SDL_GetRendererName(scene->renderer);
    if (name == NULL ||
        (SDL_strncmp(name, "opengl", 6) != 0 && SDL_strncmp(name, "gles", 4) != 0))
    {
        return false;
    }
    /* No check for a current SDL_GLContext here: SDL's renderer owns the
       context, and on Emscripten it does not surface as one at all, which
       would rule out WebGL — the platform this path matters most for. The
       renderer's name is the guard, and loading the entry points below is
       the real test. */

    struct LightGl *gl = (struct LightGl *)SDL_calloc(1, sizeof(*gl));
    if (gl == NULL)
    {
        return false;
    }
    if (!LoadEntryPoints(gl) || !BuildProgram(gl))
    {
        /* Logged rather than swallowed: falling back to the CPU path is a
           large, silent performance difference otherwise. */
        SDL_Log("light: shader path unavailable (%s)", SDL_GetError());
        SDL_free(gl);
        return false;
    }
    scene->gl = gl;
    return true;
}

void SDLStatic_LightGlQuit(SDLStatic_LightScene *scene)
{
    struct LightGl *gl = scene->gl;
    if (gl == NULL)
    {
        return;
    }
    if (gl->quad != 0)
    {
        gl->DeleteBuffers(1, &gl->quad);
    }
    if (gl->program != 0)
    {
        gl->DeleteProgram(gl->program);
    }
    if (gl->mask_texture != 0)
    {
        gl->DeleteTextures(1, &gl->mask_texture);
    }
    SDL_free(gl->mask);
    SDL_free(gl);
    scene->gl = NULL;
}

/* --- the pass ----------------------------------------------------------- */

/* SDL owns this context, so anything touched has to go back as it was or
 * the next SDL_Render* call draws with our state. */
typedef struct GlState
{
    GLint program;
    GLint array_buffer;
    GLint active_texture;
    GLint texture_2d;
    GLint blend_src_rgb;
    GLint blend_dst_rgb;
    GLint blend_src_alpha;
    GLint blend_dst_alpha;
    GLboolean blend;
    GLboolean scissor;
    /* Attribute 0's array state. SDL's renderer keeps its own idea of what
     * is enabled and does not re-issue it, so leaving this attribute
     * disabled makes every later SDL draw fetch no positions — the frame
     * silently comes out empty. */
    GLint attrib_enabled;
    GLint attrib_size;
    GLint attrib_type;
    GLint attrib_normalized;
    GLint attrib_stride;
    GLint attrib_buffer;
    void *attrib_pointer;
} GlState;

static void SaveState(struct LightGl *gl, GlState *state)
{
    gl->GetIntegerv(GL_CURRENT_PROGRAM, &state->program);
    gl->GetIntegerv(GL_ARRAY_BUFFER_BINDING, &state->array_buffer);
    gl->GetIntegerv(GL_ACTIVE_TEXTURE, &state->active_texture);
    gl->GetIntegerv(GL_TEXTURE_BINDING_2D, &state->texture_2d);
    gl->GetIntegerv(GL_BLEND_SRC_RGB, &state->blend_src_rgb);
    gl->GetIntegerv(GL_BLEND_DST_RGB, &state->blend_dst_rgb);
    gl->GetIntegerv(GL_BLEND_SRC_ALPHA, &state->blend_src_alpha);
    gl->GetIntegerv(GL_BLEND_DST_ALPHA, &state->blend_dst_alpha);
    state->blend = gl->IsEnabled(GL_BLEND);
    state->scissor = gl->IsEnabled(GL_SCISSOR_TEST);

    gl->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &state->attrib_enabled);
    gl->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_SIZE, &state->attrib_size);
    gl->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_TYPE, &state->attrib_type);
    gl->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, &state->attrib_normalized);
    gl->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_STRIDE, &state->attrib_stride);
    gl->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING, &state->attrib_buffer);
    gl->GetVertexAttribPointerv(0, GL_VERTEX_ATTRIB_ARRAY_POINTER, &state->attrib_pointer);
}

static void RestoreState(struct LightGl *gl, const GlState *state)
{
    /* Put attribute 0 back exactly as it was, buffer binding included:
       VertexAttribPointer captures whichever buffer is bound when it is
       called. */
    gl->BindBuffer(GL_ARRAY_BUFFER, (GLuint)state->attrib_buffer);
    gl->VertexAttribPointer(0, state->attrib_size, (GLenum)state->attrib_type,
                            (GLboolean)state->attrib_normalized, state->attrib_stride,
                            state->attrib_pointer);
    if (state->attrib_enabled)
    {
        gl->EnableVertexAttribArray(0);
    }
    else
    {
        gl->DisableVertexAttribArray(0);
    }
    gl->BindBuffer(GL_ARRAY_BUFFER, (GLuint)state->array_buffer);
    gl->UseProgram((GLuint)state->program);
    gl->ActiveTexture((GLenum)state->active_texture);
    gl->BindTexture(GL_TEXTURE_2D, (GLuint)state->texture_2d);
    gl->BlendFuncSeparate((GLenum)state->blend_src_rgb, (GLenum)state->blend_dst_rgb,
                          (GLenum)state->blend_src_alpha, (GLenum)state->blend_dst_alpha);
    if (state->blend)
    {
        gl->Enable(GL_BLEND);
    }
    else
    {
        gl->Disable(GL_BLEND);
    }
    if (state->scissor)
    {
        gl->Enable(GL_SCISSOR_TEST);
    }
    else
    {
        gl->Disable(GL_SCISSOR_TEST);
    }
}

/* Rasterise this frame's occluders into the mask: 255 is solid, 0 is
 * empty. Mask space covers the same view as the light map, so the shader
 * can look up with the same normalised coordinates.
 *
 * Filled rectangles are the common case (tiles, platforms, crates) and are
 * a memset per row. Free-standing segments are walked with a DDA — thin,
 * but the raymarch samples with linear filtering, so a one-pixel line
 * still stops a ray. */
static void RasteriseMask(SDLStatic_LightScene *scene, struct LightGl *gl)
{
    if (scene->map_w <= 0 || scene->map_h <= 0)
    {
        return;
    }
    gl->mask_w = SDL_clamp(scene->map_w, MASK_MIN_W, MASK_MAX_W);
    gl->mask_h = SDL_clamp(scene->map_h, MASK_MIN_H, MASK_MAX_H);
    SDL_memset(gl->mask, 0, (size_t)gl->mask_w * (size_t)gl->mask_h);
    /* World -> mask. The light map covers the view; the mask covers the
       same area at its own fixed resolution. */
    const float sx = (float)gl->mask_w / (float)scene->map_w * scene->map_scale;
    const float sy = (float)gl->mask_h / (float)scene->map_h * scene->map_scale;

    for (int i = 0; i < scene->occluder_rect_count; i++)
    {
        const SDL_FRect r = scene->occluder_rects[i];
        int x0 = (int)SDL_floorf((r.x - scene->camera_x) * sx);
        int y0 = (int)SDL_floorf((r.y - scene->camera_y) * sy);
        int x1 = (int)SDL_ceilf((r.x + r.w - scene->camera_x) * sx);
        int y1 = (int)SDL_ceilf((r.y + r.h - scene->camera_y) * sy);
        x0 = SDL_max(x0, 0);
        y0 = SDL_max(y0, 0);
        x1 = SDL_min(x1, gl->mask_w);
        y1 = SDL_min(y1, gl->mask_h);
        for (int y = y0; y < y1; y++)
        {
            if (x1 > x0)
            {
                SDL_memset(gl->mask + (size_t)y * (size_t)gl->mask_w + x0, 0xFF,
                           (size_t)(x1 - x0));
            }
        }
    }

    for (int i = scene->occluder_rect_count * 4; i < scene->occluder_count; i++)
    {
        const Segment *s = &scene->occluders[i];
        const float ax = (s->x1 - scene->camera_x) * sx;
        const float ay = (s->y1 - scene->camera_y) * sy;
        const float bx = (s->x2 - scene->camera_x) * sx;
        const float by = (s->y2 - scene->camera_y) * sy;
        const float dx = bx - ax;
        const float dy = by - ay;
        const int steps = (int)SDL_max(SDL_fabsf(dx), SDL_fabsf(dy)) + 1;
        for (int step = 0; step <= steps; step++)
        {
            const float t = (float)step / (float)steps;
            const int x = (int)(ax + dx * t);
            const int y = (int)(ay + dy * t);
            if (x >= 0 && x < gl->mask_w && y >= 0 && y < gl->mask_h)
            {
                gl->mask[(size_t)y * (size_t)gl->mask_w + x] = 0xFF;
            }
        }
    }
}

bool SDLStatic_LightGlRenderMap(SDLStatic_LightScene *scene, float seconds)
{
    struct LightGl *gl = scene->gl;
    if (gl == NULL)
    {
        return false;
    }
    /* SDL has the light map bound as its render target; flushing makes
       sure its own queued work lands before the shader writes there. */
    if (!SDL_FlushRenderer(scene->renderer))
    {
        return false;
    }

    GlState state;
    SaveState(gl, &state);

    gl->UseProgram(gl->program);
    /* Additive: the ambient and any dark zones are already in the map, and
       lights add to them. */
    gl->Enable(GL_BLEND);
    gl->BlendFunc(GL_ONE, GL_ONE);
    gl->Disable(GL_SCISSOR_TEST);
    gl->Viewport(0, 0, scene->map_w, scene->map_h);

    gl->Uniform2f(gl->u_resolution_frag, (float)scene->map_w, (float)scene->map_h);
    gl->Uniform2f(gl->u_resolution_vert, (float)scene->map_w, (float)scene->map_h);
    gl->Uniform1f(gl->u_shadow_softness, scene->shadow_softness);
    RasteriseMask(scene, gl);
    gl->Uniform2f(gl->u_mask_size, (float)gl->mask_w, (float)gl->mask_h);

    /* Pack the lights: positions in light-map pixels, so the shader never
       has to know about the camera or the map scale. */
    float positions[SDLSTATIC_LIGHT_GL_MAX * 4];
    float colours[SDLSTATIC_LIGHT_GL_MAX * 4];
    float cones[SDLSTATIC_LIGHT_GL_MAX * 4];
    int count = 0;
    for (int i = 0; i < scene->light_count && count < SDLSTATIC_LIGHT_GL_MAX; i++)
    {
        const SDLStatic_Light *light = &scene->lights[i];
        const float flicker = SDLStatic_LightFlickerScale(light, seconds);
        const float alpha = (light->color.a > 0.0f) ? light->color.a : 1.0f;
        positions[count * 4 + 0] = (light->x - scene->camera_x) * scene->map_scale;
        positions[count * 4 + 1] = (light->y - scene->camera_y) * scene->map_scale;
        positions[count * 4 + 2] = light->radius * flicker * scene->map_scale;
        positions[count * 4 + 3] = alpha * flicker;
        colours[count * 4 + 0] = light->color.r;
        colours[count * 4 + 1] = light->color.g;
        colours[count * 4 + 2] = light->color.b;
        colours[count * 4 + 3] = (light->falloff > 0.0f) ? light->falloff : 1.0f;
        const bool omni = (light->spread <= 0.0f || light->spread >= 2.0f * SDL_PI_F);
        cones[count * 4 + 0] = light->angle;
        cones[count * 4 + 1] = omni ? -1.0f : light->spread * 0.5f;
        cones[count * 4 + 2] = light->no_shadows ? 0.0f : 1.0f;
        cones[count * 4 + 3] = 0.0f;
        count++;
    }
    gl->Uniform1i(gl->u_light_count, count);
    gl->Uniform4fv(gl->u_light_pos, count > 0 ? count : 1, positions);
    gl->Uniform4fv(gl->u_light_color, count > 0 ? count : 1, colours);
    gl->Uniform4fv(gl->u_light_cone, count > 0 ? count : 1, cones);

    gl->ActiveTexture(GL_TEXTURE0);
    gl->BindTexture(GL_TEXTURE_2D, gl->mask_texture);
    gl->PixelStorei(GL_UNPACK_ALIGNMENT, 1);
    /* Re-specified rather than sub-uploaded: the size follows the window,
       so it can change when the window is resized. */
    gl->TexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, gl->mask_w, gl->mask_h, 0, GL_LUMINANCE,
                   GL_UNSIGNED_BYTE, gl->mask);
    gl->Uniform1i(gl->u_mask, 0);


    gl->BindBuffer(GL_ARRAY_BUFFER, gl->quad);
    gl->EnableVertexAttribArray(0);
    gl->VertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    gl->Uniform1f(gl->u_swizzle, scene->map_swizzle ? 1.0f : 0.0f);
    gl->DrawArrays(GL_TRIANGLES, 0, 3);

    RestoreState(gl, &state);
    return true;
}
