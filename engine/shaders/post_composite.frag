/* The composite: every remaining effect, in one pass.
 *
 * One program rather than one per effect, branching on uniforms. Branches
 * on uniforms are uniform across the draw, so hardware handles them well,
 * and the alternative — a program per combination of eight settings — is
 * 256 programs and a compile stall whenever a slider moves.
 *
 * The order is not arbitrary. Effects that change *where* a pixel is read
 * from must happen before the read; effects that change what the frame
 * *looks like* happen after it:
 *
 *   1. curvature      bends the screen, so it moves the sample position
 *   2. pixelation     quantises the sample position
 *   3. chromatic      reads the three channels from three positions
 *   4. FXAA           reads neighbours to find and soften edges
 *   5. bloom          adds the blurred bright pass on top
 *   6. scanlines      darkens rows, which only makes sense on a final image
 *   7. grading        brightness, contrast, saturation, colour-blindness
 *   8. vignette       the edge of a curved tube
 *
 * Getting 6 before 5 would make the bloom bleed *through* the scanlines,
 * and 7 before 5 would grade the scene but not the glow.
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
uniform sampler2D u_bloom;
uniform vec2 u_resolution; /* output size in pixels */
uniform vec2 u_texel;      /* one scene pixel, in UV */

uniform float u_bloom_amount;
uniform float u_crt;
uniform float u_curvature;
uniform float u_pixelation; /* block size in pixels; 1 is off */
uniform float u_chromatic;
uniform float u_fxaa;
uniform float u_brightness;
uniform float u_contrast;
uniform float u_saturation;
uniform vec3 u_cb_weights; /* colour-blind correction, zero when off */
uniform float u_cb_amount;

/* SDL's renderer may hand back a target whose channel order is not the one
   the shader expects. Rather than guess, the loader measures it once and
   sets this to 1.0 when red and blue need swapping. */
uniform vec4 u_swizzle;

vec3 Scene(vec2 uv)
{
    vec4 c = texture2D(u_scene, uv);
    return mix(c.rgb, c.bgr, u_swizzle.x);
}

/* Barrel distortion. Positive `amount` pushes the corners out, which is
   what a CRT's glass did. */
vec2 Curve(vec2 uv, float amount)
{
    if (amount <= 0.0)
    {
        return uv;
    }
    vec2 centred = uv * 2.0 - 1.0;
    float r2 = dot(centred, centred);
    centred *= 1.0 + r2 * amount * 0.25;
    return centred * 0.5 + 0.5;
}

/* A cheap FXAA: find the local luma gradient and take one extra sample
   along it. Not the full Lottes algorithm — this is a 2D game, where the
   edges are sprite silhouettes and vector shapes rather than the long
   near-horizontal polygon edges FXAA was designed for. */
vec3 Fxaa(vec2 uv, vec3 centre)
{
    vec3 nw = Scene(uv + u_texel * vec2(-1.0, -1.0));
    vec3 ne = Scene(uv + u_texel * vec2(1.0, -1.0));
    vec3 sw = Scene(uv + u_texel * vec2(-1.0, 1.0));
    vec3 se = Scene(uv + u_texel * vec2(1.0, 1.0));

    vec3 luma = vec3(0.299, 0.587, 0.114);
    float lnw = dot(nw, luma);
    float lne = dot(ne, luma);
    float lsw = dot(sw, luma);
    float lse = dot(se, luma);
    float lm = dot(centre, luma);

    float lmin = min(lm, min(min(lnw, lne), min(lsw, lse)));
    float lmax = max(lm, max(max(lnw, lne), max(lsw, lse)));
    /* Flat here: nothing to anti-alias, and blurring it would only cost
       sharpness. */
    if (lmax - lmin < max(0.05, lmax * 0.125))
    {
        return centre;
    }

    vec2 dir = vec2(-((lnw + lne) - (lsw + lse)), ((lnw + lsw) - (lne + lse)));
    float scale = 1.0 / (min(abs(dir.x), abs(dir.y)) + 0.0625);
    dir = clamp(dir * scale, -4.0, 4.0) * u_texel;

    vec3 a = 0.5 * (Scene(uv + dir * (1.0 / 3.0 - 0.5)) + Scene(uv + dir * (2.0 / 3.0 - 0.5)));
    vec3 b = a * 0.5 + 0.25 * (Scene(uv - dir * 0.5) + Scene(uv + dir * 0.5));
    float lb = dot(b, luma);
    return (lb < lmin || lb > lmax) ? a : b;
}

void main()
{
    vec2 uv = Curve(v_uv, u_curvature);

    /* Off the curved glass there is no picture. Done before anything else
       so the effects are not evaluated for pixels that end up black. */
    if (u_curvature > 0.0 && (uv.x < 0.0 || uv.x > 1.0 || uv.y < 0.0 || uv.y > 1.0))
    {
        gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
        return;
    }

    if (u_pixelation > 1.0)
    {
        vec2 blocks = u_resolution / u_pixelation;
        uv = (floor(uv * blocks) + 0.5) / blocks;
    }

    vec3 color;
    if (u_chromatic > 0.0)
    {
        /* Separation grows towards the edges, which is where a real lens
           puts it. Uniform separation just looks like a printing error. */
        vec2 offset = (uv - 0.5) * u_chromatic * 0.02;
        color = vec3(Scene(uv + offset).r, Scene(uv).g, Scene(uv - offset).b);
    }
    else
    {
        color = Scene(uv);
        if (u_fxaa > 0.5)
        {
            color = Fxaa(uv, color);
        }
    }

    if (u_bloom_amount > 0.0)
    {
        color += texture2D(u_bloom, uv).rgb * u_bloom_amount;
    }

    if (u_crt > 0.0)
    {
        /* Scanlines on the output grid, not the scene's — they are a
           property of the display being imitated. */
        float line = sin(uv.y * u_resolution.y * 3.14159265);
        float scan = 1.0 - u_crt * 0.35 * line * line;

        /* An aperture-grille mask: each output pixel column favours one
           phosphor. Subtle at 1x, unmistakable magnified. */
        float column = mod(floor(uv.x * u_resolution.x), 3.0);
        vec3 mask = vec3(column == 0.0 ? 1.0 : 0.85, column == 1.0 ? 1.0 : 0.85,
                         column == 2.0 ? 1.0 : 0.85);
        color *= scan * mix(vec3(1.0), mask, u_crt);
    }

    /* Grading. Contrast pivots around mid-grey rather than black, or
       raising it would just brighten everything. */
    color = pow(max(color, 0.0), vec3(1.0 / max(u_brightness, 0.001)));
    color = (color - 0.5) * u_contrast + 0.5;
    float grey = dot(color, vec3(0.2126, 0.7152, 0.0722));
    color = mix(vec3(grey), color, u_saturation);

    if (u_cb_amount > 0.0)
    {
        /* Daltonisation, shortened: take the error the deficient channel
           cannot carry and push it into the channels that can. u_cb_weights
           says which channel is weak. */
        float lost = dot(color, u_cb_weights);
        vec3 shifted = color + u_cb_weights.gbr * lost * 0.7 - u_cb_weights * lost * 0.7;
        color = mix(color, shifted, u_cb_amount);
    }

    if (u_curvature > 0.0)
    {
        vec2 edge = uv * (1.0 - uv.yx);
        float vignette = clamp(pow(edge.x * edge.y * 40.0, 0.25), 0.0, 1.0);
        color *= mix(1.0, vignette, u_curvature);
    }

    gl_FragColor = vec4(clamp(color, 0.0, 1.0), 1.0);
}
