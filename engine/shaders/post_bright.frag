/* Bloom, pass 1 of 3: keep only what is bright enough to glow.
 *
 * Runs at a quarter of the frame's resolution, which is not a compromise —
 * a glow is low-frequency by definition, so blurring it at full resolution
 * would be spending four times the fill rate to produce the same image.
 * The four taps are a box downsample, so the reduction itself does not
 * alias bright single pixels into flickering.
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
uniform vec2 u_texel;      /* one source pixel, in UV */
uniform float u_threshold; /* brightness below which nothing blooms */
uniform vec4 u_swizzle;    /* see the composite pass */

vec3 Fetch(vec2 uv)
{
    vec4 c = texture2D(u_scene, uv);
    return mix(c.rgb, c.bgr, u_swizzle.x);
}

void main()
{
    vec3 sum = Fetch(v_uv + u_texel * vec2(-0.5, -0.5)) +
               Fetch(v_uv + u_texel * vec2(0.5, -0.5)) +
               Fetch(v_uv + u_texel * vec2(-0.5, 0.5)) + Fetch(v_uv + u_texel * vec2(0.5, 0.5));
    vec3 color = sum * 0.25;

    /* Soft knee rather than a hard cut: a hard threshold makes a moving
       highlight pop in and out as it crosses the line, which reads as
       flicker. The knee fades it in over a short range instead. */
    float luma = dot(color, vec3(0.2126, 0.7152, 0.0722));
    float knee = max(u_threshold * 0.5, 0.0001);
    float weight = clamp((luma - u_threshold + knee) / (2.0 * knee), 0.0, 1.0);

    gl_FragColor = vec4(color * weight, 1.0);
}
