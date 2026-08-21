/* Bloom, pass 2 of 3: a separable Gaussian, run twice.
 *
 * Separable means the 2D blur is done as a horizontal pass followed by a
 * vertical one — 2N taps instead of N*N, which is what makes a wide radius
 * affordable at all. `u_direction` picks the axis, so one program does both.
 *
 * The nine taps use the linear-sampling trick: each of the four offset
 * taps sits between two texels so the hardware's bilinear filter returns
 * their weighted average for free, giving a 17-tap blur for the price of 9.
 *
 * GLSL 1.x on purpose (see post.vert).
 */
#ifdef GL_ES
#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif
#endif

varying vec2 v_uv;

uniform sampler2D u_scene;
uniform vec2 u_texel;     /* one source pixel, in UV */
uniform vec2 u_direction; /* (1,0) horizontal, (0,1) vertical */
uniform float u_radius;   /* in source pixels */

void main()
{
    vec2 step = u_texel * u_direction * u_radius;

    /* Weights and offsets for a 17-tap Gaussian collapsed to 9 samples. */
    vec3 color = texture2D(u_scene, v_uv).rgb * 0.1964825501511404;
    color += (texture2D(u_scene, v_uv + step * 1.411764705882353).rgb +
              texture2D(u_scene, v_uv - step * 1.411764705882353).rgb) *
             0.2969069646728344;
    color += (texture2D(u_scene, v_uv + step * 3.2941176470588234).rgb +
              texture2D(u_scene, v_uv - step * 3.2941176470588234).rgb) *
             0.09447039785044732;
    color += (texture2D(u_scene, v_uv + step * 5.176470588235294).rgb +
              texture2D(u_scene, v_uv - step * 5.176470588235294).rgb) *
             0.010381362401148057;

    gl_FragColor = vec4(color, 1.0);
}
