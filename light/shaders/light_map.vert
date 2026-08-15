/* Fullscreen pass for the light map.
 *
 * Deliberately GLSL 1.x (desktop 120 / ES 100): SDL's OpenGL renderer
 * creates a 2.1-era context on macOS and an ES2/WebGL1 context can turn up
 * on mobile and the web, so anything requiring 330 or 300 es would fail to
 * compile exactly where portability matters most. The version line is
 * prepended by the loader.
 */
#ifdef GL_ES
precision highp float; /* pixel coordinates: mediump would quantise them */
#endif

attribute vec2 a_position; /* clip space, one triangle covering the screen */

varying vec2 v_pixel; /* pixel coordinates in the light map */

/* Deliberately not named u_resolution like the fragment stage's copy: a
   uniform shared between stages must match in precision as well as type,
   and the fragment stage may be forced down to mediump on hardware without
   high precision there. Two uniforms, set to the same value, sidestep it. */
uniform vec2 u_vert_resolution;

void main()
{
    gl_Position = vec4(a_position, 0.0, 1.0);
    /* Clip space to light-map pixels. No Y flip: SDL renders into a
       texture through an FBO whose origin already matches the coordinates
       the rest of the library works in, and flipping here silently puts
       every light at the wrong height — visible only in a scene that is
       not symmetric about the middle of the screen. */
    vec2 uv = a_position * 0.5 + 0.5;
    v_pixel = uv * u_vert_resolution;
}
