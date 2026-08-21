/* Fullscreen pass for the post-processing chain.
 *
 * GLSL 1.x on purpose (desktop 120 / ES 100), for the same reason as the
 * lighting shaders: SDL's OpenGL renderer creates a 2.1-era context on
 * macOS and an ES2/WebGL1 context turns up on mobile and the web. The
 * version line is prepended by the loader.
 */
#ifdef GL_ES
precision highp float;
#endif

attribute vec2 a_position; /* clip space, one triangle covering the screen */

varying vec2 v_uv;

void main()
{
    gl_Position = vec4(a_position, 0.0, 1.0);
    v_uv = a_position * 0.5 + 0.5;
}
