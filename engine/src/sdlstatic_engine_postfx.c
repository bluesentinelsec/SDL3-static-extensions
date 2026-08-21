/*
 * sdlstatic_engine_postfx.c — bloom, CRT, chromatic aberration, FXAA.
 * Original SDLStatic code (zlib).
 *
 * The finished frame is copied out of the framebuffer into a texture this
 * file owns, and then drawn back through a shader chain — which is what
 * turns the settings in engine_graphics.h into something visible.
 *
 * Copying rather than rendering the frame into an SDL texture and reading
 * its GL name: SDL does not publish the name (the documented
 * SDL_PROP_TEXTURE_OPENGL_TEXTURE_NUMBER is absent on the OpenGL renderer
 * in practice), so there is no supported way to sample an SDL render
 * target from a raw GL shader. glCopyTexSubImage2D costs one full-screen
 * copy and works on every GL and GLES version this targets.
 *
 * Same three choices as the lighting shaders, for the same reasons:
 *
 *   No link-time GL dependency. Every entry point comes through
 *   SDL_GL_GetProcAddress, so the project keeps its "no external
 *   libraries" property.
 *
 *   GLSL 1.x. SDL's OpenGL renderer creates a 2.1-era context on macOS and
 *   an ES2/WebGL context turns up on mobile and the web.
 *
 *   Degrade, never fail. On a Metal or Direct3D renderer there is no GL to
 *   talk to, so the chain reports itself unavailable and the frame is
 *   blitted plainly. A game must not fail to start because a player asked
 *   for scanlines. The engine asks SDL for OpenGL by default, so this only
 *   happens on SDLSTATIC_BACKEND_NATIVE or a machine with no working GL.
 *
 * Bloom is three passes rather than one: threshold-and-downsample, then a
 * separable blur across and down. A single wide-tap pass is cheaper to
 * write and looks like ghosting; this looks like light.
 */
#include "engine_internal.h"

#include "post_shaders.h"

/* --- the slice of GL this needs, loaded at runtime ----------------------- */

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
#define GL_DEPTH_TEST 0x0B71
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_VIEWPORT 0x0BA2
#define GL_RGBA 0x1908
#define GL_UNSIGNED_BYTE 0x1401
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_LINEAR 0x2601
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_FRAMEBUFFER 0x8D40
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645

/* Bloom runs at a quarter of the frame in each axis: a glow is
   low-frequency, so the resolution buys nothing and costs 16x the fill. */
#define BLOOM_DIVISOR 4
#define BLOOM_MIN 16

typedef GLuint (*PFN_glCreateShader)(GLenum);
typedef void (*PFN_glShaderSource)(GLuint, GLsizei, const GLchar *const *, const GLint *);
typedef void (*PFN_glCompileShader)(GLuint);
typedef void (*PFN_glGetShaderiv)(GLuint, GLenum, GLint *);
typedef void (*PFN_glGetShaderInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (*PFN_glDeleteShader)(GLuint);
typedef GLuint (*PFN_glCreateProgram)(void);
typedef void (*PFN_glAttachShader)(GLuint, GLuint);
typedef void (*PFN_glBindAttribLocation)(GLuint, GLuint, const GLchar *);
typedef void (*PFN_glLinkProgram)(GLuint);
typedef void (*PFN_glGetProgramiv)(GLuint, GLenum, GLint *);
typedef void (*PFN_glGetProgramInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (*PFN_glDeleteProgram)(GLuint);
typedef void (*PFN_glUseProgram)(GLuint);
typedef GLint (*PFN_glGetUniformLocation)(GLuint, const GLchar *);
typedef void (*PFN_glUniform1i)(GLint, GLint);
typedef void (*PFN_glUniform1f)(GLint, GLfloat);
typedef void (*PFN_glUniform2f)(GLint, GLfloat, GLfloat);
typedef void (*PFN_glUniform3f)(GLint, GLfloat, GLfloat, GLfloat);
typedef void (*PFN_glUniform4f)(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (*PFN_glGenBuffers)(GLsizei, GLuint *);
typedef void (*PFN_glBindBuffer)(GLenum, GLuint);
typedef void (*PFN_glBufferData)(GLenum, long, const void *, GLenum);
typedef void (*PFN_glDeleteBuffers)(GLsizei, const GLuint *);
typedef void (*PFN_glEnableVertexAttribArray)(GLuint);
typedef void (*PFN_glDisableVertexAttribArray)(GLuint);
typedef void (*PFN_glVertexAttribPointer)(GLuint, GLint, GLenum, GLboolean, GLsizei,
                                          const void *);
typedef void (*PFN_glDrawArrays)(GLenum, GLint, GLsizei);
typedef void (*PFN_glActiveTexture)(GLenum);
typedef void (*PFN_glBindTexture)(GLenum, GLuint);
typedef void (*PFN_glDisable)(GLenum);
typedef void (*PFN_glEnable)(GLenum);
typedef GLboolean (*PFN_glIsEnabled)(GLenum);
typedef void (*PFN_glGetIntegerv)(GLenum, GLint *);
typedef void (*PFN_glViewport)(GLint, GLint, GLsizei, GLsizei);
typedef void (*PFN_glGenTextures)(GLsizei, GLuint *);
typedef void (*PFN_glDeleteTextures)(GLsizei, const GLuint *);
typedef void (*PFN_glTexImage2D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum,
                                 const void *);
typedef void (*PFN_glTexParameteri)(GLenum, GLenum, GLint);
typedef void (*PFN_glCopyTexSubImage2D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei,
                                        GLsizei);
typedef void (*PFN_glGenFramebuffers)(GLsizei, GLuint *);
typedef void (*PFN_glDeleteFramebuffers)(GLsizei, const GLuint *);
typedef void (*PFN_glBindFramebuffer)(GLenum, GLuint);
typedef void (*PFN_glFramebufferTexture2D)(GLenum, GLenum, GLenum, GLuint, GLint);
typedef GLenum (*PFN_glCheckFramebufferStatus)(GLenum);
typedef void (*PFN_glGetVertexAttribiv)(GLuint, GLenum, GLint *);
typedef void (*PFN_glGetVertexAttribPointerv)(GLuint, GLenum, void **);

struct SDLStatic_PostFX
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
    PFN_glUniform4f Uniform4f;
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
    PFN_glGenTextures GenTextures;
    PFN_glDeleteTextures DeleteTextures;
    PFN_glTexImage2D TexImage2D;
    PFN_glTexParameteri TexParameteri;
    PFN_glCopyTexSubImage2D CopyTexSubImage2D;
    PFN_glGenFramebuffers GenFramebuffers;
    PFN_glDeleteFramebuffers DeleteFramebuffers;
    PFN_glBindFramebuffer BindFramebuffer;
    PFN_glFramebufferTexture2D FramebufferTexture2D;
    PFN_glCheckFramebufferStatus CheckFramebufferStatus;
    PFN_glGetVertexAttribiv GetVertexAttribiv;
    PFN_glGetVertexAttribPointerv GetVertexAttribPointerv;

    /* The frame, copied out of the framebuffer each time the chain runs. */
    GLuint scene_texture;
    int scene_w, scene_h;

    GLuint program_composite;
    GLuint program_bright;
    GLuint program_blur;
    GLuint vbo;

    /* Ping-pong pair for the separable blur, at BLOOM_DIVISOR of the frame. */
    GLuint bloom_texture[2];
    GLuint bloom_fbo[2];
    int bloom_w, bloom_h;

    float swizzle; /* 1.0 when the frame's channels arrive as BGR */
    bool ready;
};

/* --- shader plumbing ----------------------------------------------------- */

static GLuint CompileShader(struct SDLStatic_PostFX *fx, GLenum type, const char *source,
                            bool es)
{
    /* The sources carry no #version, because the same text has to serve
       desktop GL and GLES. Prepending it here is the whole trick. */
    const char *version = es ? "#version 100\n" : "#version 120\n";
    const char *parts[2] = {version, source};
    const GLuint shader = fx->CreateShader(type);
    if (shader == 0)
    {
        return 0;
    }
    fx->ShaderSource(shader, 2, parts, NULL);
    fx->CompileShader(shader);

    GLint ok = 0;
    fx->GetShaderiv(shader, GL_COMPILE_STATUS, &ok);
    if (!ok)
    {
        char log[512] = {0};
        GLsizei length = 0;
        fx->GetShaderInfoLog(shader, (GLsizei)sizeof(log) - 1, &length, log);
        SDL_SetError("post-processing shader failed to compile: %s", log);
        fx->DeleteShader(shader);
        return 0;
    }
    return shader;
}

static GLuint LinkProgram(struct SDLStatic_PostFX *fx, const char *fragment, bool es)
{
    const GLuint vs = CompileShader(fx, GL_VERTEX_SHADER, kPostVert, es);
    if (vs == 0)
    {
        return 0;
    }
    const GLuint ps = CompileShader(fx, GL_FRAGMENT_SHADER, fragment, es);
    if (ps == 0)
    {
        fx->DeleteShader(vs);
        return 0;
    }
    const GLuint program = fx->CreateProgram();
    fx->AttachShader(program, vs);
    fx->AttachShader(program, ps);
    fx->BindAttribLocation(program, 0, "a_position");
    fx->LinkProgram(program);
    fx->DeleteShader(vs);
    fx->DeleteShader(ps);

    GLint ok = 0;
    fx->GetProgramiv(program, GL_LINK_STATUS, &ok);
    if (!ok)
    {
        char log[512] = {0};
        GLsizei length = 0;
        fx->GetProgramInfoLog(program, (GLsizei)sizeof(log) - 1, &length, log);
        SDL_SetError("post-processing program failed to link: %s", log);
        fx->DeleteProgram(program);
        return 0;
    }
    return program;
}

/* --- setup --------------------------------------------------------------- */

static bool RendererIsOpenGL(SDL_Renderer *renderer, bool *is_es)
{
    const char *name = SDL_GetRendererName(renderer);
    if (name == NULL)
    {
        return false;
    }
    if (SDL_strcmp(name, "opengl") == 0)
    {
        *is_es = false;
        return true;
    }
    if (SDL_strcmp(name, "opengles2") == 0 || SDL_strcmp(name, "opengles") == 0)
    {
        *is_es = true;
        return true;
    }
    return false;
}

#define LOAD(field, name)                                                                        \
    do                                                                                           \
    {                                                                                            \
        fx->field = (PFN_gl##field)SDL_GL_GetProcAddress(name);                                  \
        if (fx->field == NULL)                                                                   \
        {                                                                                        \
            SDL_SetError("post-processing needs %s", name);                                      \
            return false;                                                                        \
        }                                                                                        \
    } while (0)

static bool LoadEntryPoints(struct SDLStatic_PostFX *fx)
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
    LOAD(Uniform4f, "glUniform4f");
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
    LOAD(GenTextures, "glGenTextures");
    LOAD(DeleteTextures, "glDeleteTextures");
    LOAD(TexImage2D, "glTexImage2D");
    LOAD(TexParameteri, "glTexParameteri");
    LOAD(CopyTexSubImage2D, "glCopyTexSubImage2D");
    LOAD(GenFramebuffers, "glGenFramebuffers");
    LOAD(DeleteFramebuffers, "glDeleteFramebuffers");
    LOAD(BindFramebuffer, "glBindFramebuffer");
    LOAD(FramebufferTexture2D, "glFramebufferTexture2D");
    LOAD(CheckFramebufferStatus, "glCheckFramebufferStatus");
    LOAD(GetVertexAttribiv, "glGetVertexAttribiv");
    LOAD(GetVertexAttribPointerv, "glGetVertexAttribPointerv");
    return true;
}

#undef LOAD

static bool EnsureBloomTargets(struct SDLStatic_PostFX *fx, int width, int height)
{
    int w = width / BLOOM_DIVISOR;
    int h = height / BLOOM_DIVISOR;
    if (w < BLOOM_MIN)
    {
        w = BLOOM_MIN;
    }
    if (h < BLOOM_MIN)
    {
        h = BLOOM_MIN;
    }
    if (fx->bloom_w == w && fx->bloom_h == h && fx->bloom_fbo[0] != 0)
    {
        return true;
    }

    if (fx->bloom_fbo[0] != 0)
    {
        fx->DeleteFramebuffers(2, fx->bloom_fbo);
        fx->DeleteTextures(2, fx->bloom_texture);
        SDL_zeroa(fx->bloom_fbo);
        SDL_zeroa(fx->bloom_texture);
    }

    fx->GenTextures(2, fx->bloom_texture);
    fx->GenFramebuffers(2, fx->bloom_fbo);
    for (int i = 0; i < 2; ++i)
    {
        fx->BindTexture(GL_TEXTURE_2D, fx->bloom_texture[i]);
        fx->TexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
        /* Linear and clamped: the blur relies on bilinear taps, and wrapping
           would smear the top of the screen into the bottom. */
        fx->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        fx->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        fx->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        fx->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        fx->BindFramebuffer(GL_FRAMEBUFFER, fx->bloom_fbo[i]);
        fx->FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                                 fx->bloom_texture[i], 0);
        if (fx->CheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        {
            SDL_SetError("bloom framebuffer incomplete");
            return false;
        }
    }
    fx->bloom_w = w;
    fx->bloom_h = h;
    return true;
}

static bool Initialise(SDLStatic_Engine *engine)
{
    bool is_es = false;
    if (!RendererIsOpenGL(engine->renderer, &is_es))
    {
        SDL_SetError("post-processing needs an OpenGL renderer (this one is %s); "
                     "leave config.backend at SDLSTATIC_BACKEND_OPENGL",
                     SDL_GetRendererName(engine->renderer));
        return false;
    }

    struct SDLStatic_PostFX *fx =
        (struct SDLStatic_PostFX *)SDL_calloc(1, sizeof(struct SDLStatic_PostFX));
    if (fx == NULL)
    {
        return false;
    }
    engine->postfx = fx;

    if (!LoadEntryPoints(fx))
    {
        return false;
    }

    fx->program_composite = LinkProgram(fx, kPostCompositeFrag, is_es);
    fx->program_bright = LinkProgram(fx, kPostBrightFrag, is_es);
    fx->program_blur = LinkProgram(fx, kPostBlurFrag, is_es);
    if (fx->program_composite == 0 || fx->program_bright == 0 || fx->program_blur == 0)
    {
        return false;
    }

    /* One oversized triangle rather than two triangles: it covers the
       screen with three vertices instead of six and has no seam down the
       diagonal where the two would meet. */
    static const GLfloat kVertices[6] = {-1.0f, -1.0f, 3.0f, -1.0f, -1.0f, 3.0f};
    GLint previous_buffer = 0;
    fx->GetIntegerv(GL_ARRAY_BUFFER_BINDING, &previous_buffer);
    fx->GenBuffers(1, &fx->vbo);
    fx->BindBuffer(GL_ARRAY_BUFFER, fx->vbo);
    fx->BufferData(GL_ARRAY_BUFFER, (long)sizeof(kVertices), kVertices, GL_STATIC_DRAW);
    /* Put the binding back. Setup runs inside the first frame, before any
       state has been saved, and leaving our buffer bound makes SDL's
       client-side vertex arrays be read as offsets into it — so SDL draws
       nothing, for every frame after this one, and the symptom looks like
       the effects having eaten the game rather than like a stray binding. */
    fx->BindBuffer(GL_ARRAY_BUFFER, (GLuint)previous_buffer);

    fx->ready = true;
    return true;
}

/* --- state save and restore ---------------------------------------------- */

/* SDL's renderer caches what it believes GL's state to be. Drawing behind
   its back and leaving anything changed makes the *next* frame wrong in
   ways that look like a bug anywhere but here — so everything touched is
   put back, including the vertex attribute array, which SDL will otherwise
   find disabled and quietly draw nothing with. */
struct GlState
{
    GLint program;
    GLint array_buffer;
    GLint active_texture;
    GLint texture_2d;
    GLint framebuffer;
    GLint viewport[4];
    GLboolean blend;
    GLboolean scissor;
    GLboolean depth;
    GLint attrib_enabled;
    GLint attrib_size;
    GLint attrib_stride;
    GLint attrib_type;
    GLint attrib_normalized;
    GLint attrib_buffer;
    void *attrib_pointer;
};

static void SaveState(struct SDLStatic_PostFX *fx, struct GlState *state)
{
    fx->GetIntegerv(GL_CURRENT_PROGRAM, &state->program);
    fx->GetIntegerv(GL_ARRAY_BUFFER_BINDING, &state->array_buffer);
    fx->GetIntegerv(GL_ACTIVE_TEXTURE, &state->active_texture);
    fx->GetIntegerv(GL_TEXTURE_BINDING_2D, &state->texture_2d);
    fx->GetIntegerv(GL_FRAMEBUFFER_BINDING, &state->framebuffer);
    fx->GetIntegerv(GL_VIEWPORT, state->viewport);
    state->blend = fx->IsEnabled(GL_BLEND);
    state->scissor = fx->IsEnabled(GL_SCISSOR_TEST);
    state->depth = fx->IsEnabled(GL_DEPTH_TEST);

    fx->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &state->attrib_enabled);
    fx->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_SIZE, &state->attrib_size);
    fx->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_STRIDE, &state->attrib_stride);
    fx->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_TYPE, &state->attrib_type);
    fx->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, &state->attrib_normalized);
    fx->GetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING, &state->attrib_buffer);
    fx->GetVertexAttribPointerv(0, GL_VERTEX_ATTRIB_ARRAY_POINTER, &state->attrib_pointer);
}

static void RestoreState(struct SDLStatic_PostFX *fx, const struct GlState *state)
{
    fx->BindBuffer(GL_ARRAY_BUFFER, (GLuint)state->attrib_buffer);
    fx->VertexAttribPointer(0, state->attrib_size, (GLenum)state->attrib_type,
                            (GLboolean)state->attrib_normalized, state->attrib_stride,
                            state->attrib_pointer);
    if (state->attrib_enabled)
    {
        fx->EnableVertexAttribArray(0);
    }
    else
    {
        fx->DisableVertexAttribArray(0);
    }

    fx->BindBuffer(GL_ARRAY_BUFFER, (GLuint)state->array_buffer);
    fx->BindFramebuffer(GL_FRAMEBUFFER, (GLuint)state->framebuffer);
    fx->Viewport(state->viewport[0], state->viewport[1], state->viewport[2], state->viewport[3]);

    /* Texture units, and the order matters. The chain binds the bloom map
       to unit 1, so unit 1 is active when this runs — binding the saved
       texture *before* switching units would put it on unit 1 and leave our
       scene texture sitting on unit 0, where SDL expects its own. SDL then
       draws every subsequent frame with the wrong texture, which looks like
       the effects having eaten the game. Unit 1 is cleared for the same
       reason: we borrowed it, so we give it back empty. */
    fx->ActiveTexture(GL_TEXTURE0 + 1);
    fx->BindTexture(GL_TEXTURE_2D, 0);
    fx->ActiveTexture((GLenum)state->active_texture);
    fx->BindTexture(GL_TEXTURE_2D, (GLuint)state->texture_2d);

    fx->UseProgram((GLuint)state->program);

    if (state->blend)
    {
        fx->Enable(GL_BLEND);
    }
    else
    {
        fx->Disable(GL_BLEND);
    }
    if (state->scissor)
    {
        fx->Enable(GL_SCISSOR_TEST);
    }
    else
    {
        fx->Disable(GL_SCISSOR_TEST);
    }
    if (state->depth)
    {
        fx->Enable(GL_DEPTH_TEST);
    }
    else
    {
        fx->Disable(GL_DEPTH_TEST);
    }
}

/* --- drawing ------------------------------------------------------------- */

static void DrawFullscreen(struct SDLStatic_PostFX *fx)
{
    fx->BindBuffer(GL_ARRAY_BUFFER, fx->vbo);
    fx->EnableVertexAttribArray(0);
    fx->VertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    fx->DrawArrays(GL_TRIANGLES, 0, 3);
}

static void Bind(struct SDLStatic_PostFX *fx, GLuint program, const char *name, GLuint texture,
                 int unit)
{
    fx->ActiveTexture((GLenum)(GL_TEXTURE0 + unit));
    fx->BindTexture(GL_TEXTURE_2D, texture);
    fx->Uniform1i(fx->GetUniformLocation(program, name), unit);
}

static void Set1f(struct SDLStatic_PostFX *fx, GLuint program, const char *name, float value)
{
    fx->Uniform1f(fx->GetUniformLocation(program, name), value);
}

static void Set2f(struct SDLStatic_PostFX *fx, GLuint program, const char *name, float x, float y)
{
    fx->Uniform2f(fx->GetUniformLocation(program, name), x, y);
}

/* Which channel the correction moves colour *out* of, and how strongly. */
static void ColorBlindWeights(SDLStatic_ColorBlindMode mode, float *r, float *g, float *b,
                              float *amount)
{
    *r = *g = *b = 0.0f;
    *amount = 0.0f;
    switch (mode)
    {
    case SDLSTATIC_COLORBLIND_PROTANOPIA:
        *r = 1.0f;
        *amount = 1.0f;
        break;
    case SDLSTATIC_COLORBLIND_DEUTERANOPIA:
        *g = 1.0f;
        *amount = 1.0f;
        break;
    case SDLSTATIC_COLORBLIND_TRITANOPIA:
        *b = 1.0f;
        *amount = 1.0f;
        break;
    case SDLSTATIC_COLORBLIND_NONE:
    default:
        break;
    }
}

/* --- the chain ----------------------------------------------------------- */

static bool AnyEffectEnabled(const SDLStatic_GraphicsSettings *g)
{
    return g->bloom > 0.0f || g->crt > 0.0f || g->crt_curvature > 0.0f || g->pixelation > 1 ||
           g->chromatic_aberration > 0.0f || g->antialias != SDLSTATIC_AA_OFF ||
           g->brightness != 1.0f || g->contrast != 1.0f || g->saturation != 1.0f ||
           g->color_blind != SDLSTATIC_COLORBLIND_NONE;
}

bool SDLStatic_EnginePostFXAvailable(SDLStatic_Engine *engine)
{
    if (engine == NULL || engine->renderer == NULL || engine->postfx_failed)
    {
        return false;
    }
    if (!AnyEffectEnabled(&engine->graphics))
    {
        return false;
    }
    if (engine->postfx != NULL)
    {
        return engine->postfx->ready;
    }
    bool is_es = false;
    return RendererIsOpenGL(engine->renderer, &is_es);
}

void SDLStatic_EnginePostFXInvalidate(SDLStatic_Engine *engine)
{
    if (engine == NULL)
    {
        return;
    }
    /* Only the "we already tried and it did not work" latch is cleared: the
       programs and buffers are settings-independent, so a slider moving is
       not a reason to recompile anything. */
    engine->postfx_failed = false;
}

/* The frame, lifted out of the framebuffer into a texture we own. */
static bool CaptureScene(struct SDLStatic_PostFX *fx, int width, int height)
{
    if (fx->scene_texture == 0 || fx->scene_w != width || fx->scene_h != height)
    {
        if (fx->scene_texture != 0)
        {
            fx->DeleteTextures(1, &fx->scene_texture);
        }
        fx->GenTextures(1, &fx->scene_texture);
        fx->BindTexture(GL_TEXTURE_2D, fx->scene_texture);
        fx->TexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                       NULL);
        /* Clamped, or the blur and the chromatic offsets would wrap the
           right edge of the screen onto the left. */
        fx->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        fx->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        fx->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        fx->TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        fx->scene_w = width;
        fx->scene_h = height;
    }
    else
    {
        fx->BindTexture(GL_TEXTURE_2D, fx->scene_texture);
    }
    fx->CopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, width, height);
    return true;
}

bool SDLStatic_EnginePostFXPresent(SDLStatic_Engine *engine)
{
    if (engine == NULL || engine->renderer == NULL || engine->postfx_failed ||
        !AnyEffectEnabled(&engine->graphics))
    {
        return false;
    }

    if (engine->postfx == NULL && !Initialise(engine))
    {
        /* Remember the failure: retrying a shader compile every frame would
           turn a cosmetic problem into a performance one. Say so once — a
           silently missing effect is a genuinely hard thing to diagnose. */
        engine->postfx_failed = true;
        SDL_LogWarn(SDL_LOG_CATEGORY_RENDER, "post-processing disabled: %s", SDL_GetError());
        return false;
    }
    struct SDLStatic_PostFX *fx = engine->postfx;
    if (fx == NULL || !fx->ready)
    {
        engine->postfx_failed = true;
        SDL_LogWarn(SDL_LOG_CATEGORY_RENDER, "post-processing disabled: %s", SDL_GetError());
        return false;
    }

    /* SDL batches its draw calls, so the frame is not in the framebuffer
       until the renderer is flushed. Skipping this captures last frame. */
    SDL_FlushRenderer(engine->renderer);

    int output_w = 0;
    int output_h = 0;
    SDL_GetRenderOutputSize(engine->renderer, &output_w, &output_h);
    if (output_w <= 0 || output_h <= 0)
    {
        return false;
    }

    struct GlState state;
    SaveState(fx, &state);

    fx->Disable(GL_BLEND);
    fx->Disable(GL_SCISSOR_TEST);
    fx->Disable(GL_DEPTH_TEST);

    if (!CaptureScene(fx, output_w, output_h))
    {
        RestoreState(fx, &state);
        engine->postfx_failed = true;
        return false;
    }
    const GLuint scene = fx->scene_texture;
    const float scene_w = (float)output_w;
    const float scene_h = (float)output_h;

    const SDLStatic_GraphicsSettings *g = &engine->graphics;

    GLuint bloom_texture = 0;
    if (g->bloom > 0.0f && EnsureBloomTargets(fx, output_w, output_h))
    {
        fx->Viewport(0, 0, fx->bloom_w, fx->bloom_h);

        /* 1: bright pass, downsampling into the first target. */
        fx->BindFramebuffer(GL_FRAMEBUFFER, fx->bloom_fbo[0]);
        fx->UseProgram(fx->program_bright);
        Bind(fx, fx->program_bright, "u_scene", scene, 0);
        Set2f(fx, fx->program_bright, "u_texel", 1.0f / scene_w, 1.0f / scene_h);
        Set1f(fx, fx->program_bright, "u_threshold", g->bloom_threshold);
        fx->Uniform4f(fx->GetUniformLocation(fx->program_bright, "u_swizzle"), fx->swizzle, 0.0f,
                      0.0f, 0.0f);
        DrawFullscreen(fx);

        /* 2 and 3: blur across, then down. */
        const float texel_x = 1.0f / (float)fx->bloom_w;
        const float texel_y = 1.0f / (float)fx->bloom_h;
        fx->UseProgram(fx->program_blur);
        Set1f(fx, fx->program_blur, "u_radius", 1.0f + g->bloom * 2.0f);

        fx->BindFramebuffer(GL_FRAMEBUFFER, fx->bloom_fbo[1]);
        Bind(fx, fx->program_blur, "u_scene", fx->bloom_texture[0], 0);
        Set2f(fx, fx->program_blur, "u_texel", texel_x, texel_y);
        Set2f(fx, fx->program_blur, "u_direction", 1.0f, 0.0f);
        DrawFullscreen(fx);

        fx->BindFramebuffer(GL_FRAMEBUFFER, fx->bloom_fbo[0]);
        Bind(fx, fx->program_blur, "u_scene", fx->bloom_texture[1], 0);
        Set2f(fx, fx->program_blur, "u_texel", texel_x, texel_y);
        Set2f(fx, fx->program_blur, "u_direction", 0.0f, 1.0f);
        DrawFullscreen(fx);

        bloom_texture = fx->bloom_texture[0];
    }

    /* Back to whatever SDL was rendering into — not framebuffer 0, which is
       wrong whenever SDL is itself drawing into an FBO. */
    fx->BindFramebuffer(GL_FRAMEBUFFER, (GLuint)state.framebuffer);
    fx->Viewport(0, 0, output_w, output_h);

    const GLuint composite = fx->program_composite;
    fx->UseProgram(composite);
    Bind(fx, composite, "u_scene", scene, 0);
    Bind(fx, composite, "u_bloom", (bloom_texture != 0) ? bloom_texture : scene, 1);
    Set2f(fx, composite, "u_resolution", (float)output_w, (float)output_h);
    Set2f(fx, composite, "u_texel", 1.0f / scene_w, 1.0f / scene_h);
    Set1f(fx, composite, "u_bloom_amount", (bloom_texture != 0) ? g->bloom : 0.0f);
    Set1f(fx, composite, "u_crt", g->crt);
    Set1f(fx, composite, "u_curvature", g->crt_curvature);
    Set1f(fx, composite, "u_pixelation", (float)g->pixelation);
    Set1f(fx, composite, "u_chromatic", g->chromatic_aberration);
    Set1f(fx, composite, "u_fxaa", (g->antialias == SDLSTATIC_AA_FXAA) ? 1.0f : 0.0f);
    Set1f(fx, composite, "u_brightness", g->brightness);
    Set1f(fx, composite, "u_contrast", g->contrast);
    Set1f(fx, composite, "u_saturation", g->saturation);

    float cb_r = 0.0f;
    float cb_g = 0.0f;
    float cb_b = 0.0f;
    float cb_amount = 0.0f;
    ColorBlindWeights(g->color_blind, &cb_r, &cb_g, &cb_b, &cb_amount);
    fx->Uniform3f(fx->GetUniformLocation(composite, "u_cb_weights"), cb_r, cb_g, cb_b);
    Set1f(fx, composite, "u_cb_amount", cb_amount);
    fx->Uniform4f(fx->GetUniformLocation(composite, "u_swizzle"), fx->swizzle, 0.0f, 0.0f, 0.0f);

    DrawFullscreen(fx);

    RestoreState(fx, &state);

    /* Restoring what we saved is not quite enough. SDL_FlushRenderer's
       contract is that it invalidates SDL's cached idea of GL state so that
       it prepares everything again from scratch — and its own documentation
       warns that "lots of arbitrary pieces of OpenGL state can confuse
       things". Asking for that invalidation again on the way out is what
       makes the *next* frame draw. Without it SDL renders nothing from the
       second frame onward, which looks like the effects eating the game. */
    SDL_FlushRenderer(engine->renderer);
    return true;
}

void SDLStatic_EnginePostFXDestroy(SDLStatic_Engine *engine)
{
    if (engine == NULL || engine->postfx == NULL)
    {
        return;
    }
    struct SDLStatic_PostFX *fx = engine->postfx;
    if (fx->ready)
    {
        if (fx->bloom_fbo[0] != 0)
        {
            fx->DeleteFramebuffers(2, fx->bloom_fbo);
            fx->DeleteTextures(2, fx->bloom_texture);
        }
        if (fx->scene_texture != 0)
        {
            fx->DeleteTextures(1, &fx->scene_texture);
        }
        if (fx->vbo != 0)
        {
            fx->DeleteBuffers(1, &fx->vbo);
        }
        if (fx->program_composite != 0)
        {
            fx->DeleteProgram(fx->program_composite);
        }
        if (fx->program_bright != 0)
        {
            fx->DeleteProgram(fx->program_bright);
        }
        if (fx->program_blur != 0)
        {
            fx->DeleteProgram(fx->program_blur);
        }
    }
    SDL_free(fx);
    engine->postfx = NULL;
}
