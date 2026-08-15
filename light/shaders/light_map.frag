/* The lights, evaluated per pixel and added to the light map.
 *
 * The ambient colour and any dark zones are painted into the map first, by
 * the caller, with ordinary rectangle fills — so this pass is purely
 * additive and the two rendering paths share exactly the same base. What
 * it writes is "how much light reaches here", not a final colour; the
 * caller multiplies the map over the frame.
 *
 * GLSL 1.x on purpose (see light_map.vert).
 *
 * Shadows are raymarched against an occluder mask — a black-and-white
 * texture the caller fills with the level's solid geometry. Marching a
 * mask rather than testing edge lists keeps the cost independent of how
 * many walls the level has, which is what makes a tile-built dungeon
 * affordable. The trade is that only geometry inside the mask casts
 * shadows, so the mask is rendered with a margin around the view.
 */
#ifdef GL_ES
/* High precision where the hardware has it: these are pixel coordinates in
   the thousands, and mediump quantises them into visible steps. */
#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif
#endif

#define MAX_LIGHTS 16
#define SHADOW_STEPS 48

varying vec2 v_pixel;

uniform int u_light_count;
uniform vec2 u_resolution;

/* xy = position in light-map pixels, z = radius in pixels, w = intensity */
uniform vec4 u_light_pos[MAX_LIGHTS];
/* rgb = colour, a = falloff exponent */
uniform vec4 u_light_color[MAX_LIGHTS];
/* x = cone direction, y = half width (<0 means omni), z = casts shadows */
uniform vec4 u_light_cone[MAX_LIGHTS];

uniform sampler2D u_mask;
uniform vec2 u_mask_size; /* mask resolution, for texel-sized steps */
uniform float u_shadow_softness; /* 0 = hard edges */

/* Some renderers will only give us a light map whose bytes run B,G,R,A,
   and SDL then samples it with a swizzling shader — so what this pass
   writes as red comes back as blue, turning torchlight cold. The library
   picks a GL-ordered format when it can and sets this when it cannot. */
uniform float u_swizzle; /* 1.0 swaps red and blue on the way out */

/* How much of the way from `from` to `to` is clear, 0..1.
 *
 * Steps along the ray in mask texels rather than in fixed fractions of its
 * length: a fixed count spreads its samples further apart the longer the
 * ray, which steps straight over thin geometry and leaves banded streaks
 * radiating from the light.
 *
 * Deliberately not dithered. Jittering the start breaks banding into
 * per-pixel noise, which looks worse here than the banding did: a shadow
 * edge on a wall becomes a fizzing line. Texel-sized steps keep the edge
 * clean, and the mask's own resolution is then the only limit on how
 * sharp a shadow can be. */
float visibility(vec2 from, vec2 to)
{
    vec2 delta = to - from;
    /* Ray length measured in mask texels, so the step size is one texel. */
    float texels = length(delta / u_resolution * u_mask_size);
    float count = min(float(SHADOW_STEPS), max(texels, 1.0));
    float step_size = 1.0 / count;
    float blocked = 0.0;

    /* Stop a couple of texels short of the target. Without this an
       occluder shadows itself: the last samples of a ray landing on a wall
       are inside that wall, so the very surface the light is shining on
       comes out black and only a hairline edge stays lit. Ending early
       lights the face toward the light and still shadows everything
       behind it. */
    float limit = 1.0 - min(0.5, 2.0 / max(texels, 1.0));

    for (int i = 0; i < SHADOW_STEPS; i++)
    {
        if (float(i) >= count)
        {
            break;
        }
        /* Sample at the middle of each step. */
        float t = (float(i) + 0.5) * step_size;
        if (t <= 0.0 || t >= limit)
        {
            continue;
        }
        vec2 uv = (from + delta * t) / u_resolution;
        /* Outside the mask is treated as empty: a light near the edge of
           the view should not be shadowed by the absence of data. */
        if (uv.x < 0.0 || uv.x > 1.0 || uv.y < 0.0 || uv.y > 1.0)
        {
            continue;
        }
        if (texture2D(u_mask, uv).r > 0.5)
        {
            /* Weight by how close to the surface the hit was, which gives
               a cheap penumbra when softness is on. */
            blocked = max(blocked, 1.0 - u_shadow_softness * (1.0 - t));
        }
    }
    return 1.0 - blocked;
}

void main()
{
    vec3 total = vec3(0.0);

    for (int i = 0; i < MAX_LIGHTS; i++)
    {
        if (i >= u_light_count)
        {
            break;
        }
        vec4 pos = u_light_pos[i];
        vec2 delta = v_pixel - pos.xy;
        float distance = length(delta);
        if (distance >= pos.z)
        {
            continue;
        }

        /* Smooth radial falloff. The exponent shapes it: 1 is linear, 2
           reads as a lantern, 4 as a candle. */
        float t = 1.0 - (distance / pos.z);
        float attenuation = pow(t, max(u_light_color[i].a, 0.001));

        /* Cone, if this light has one. */
        vec4 cone = u_light_cone[i];
        if (cone.y > 0.0)
        {
            float angle = atan(delta.y, delta.x);
            float difference = angle - cone.x;
            /* Wrap into [-pi, pi] without a branch per case. */
            difference = mod(difference + 3.14159265, 6.28318530) - 3.14159265;
            float edge = cone.y;
            /* Soften the last few degrees so the cone does not alias. */
            attenuation *= 1.0 - smoothstep(edge * 0.75, edge, abs(difference));
        }

        if (attenuation <= 0.0)
        {
            continue;
        }
        if (cone.z > 0.5)
        {
            attenuation *= visibility(pos.xy, v_pixel);
        }
        total += u_light_color[i].rgb * (attenuation * pos.w);
    }

    gl_FragColor = vec4(mix(total, total.bgr, u_swizzle), 1.0);
}
