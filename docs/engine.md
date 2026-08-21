---
title: Engine
description: "An opinionated game engine: a fixed-tick loop with interpolated rendering, design-resolution scaling, and a frame limiter."
---

# Engine — `SDLStatic::Engine`

An opinionated game engine. Everything else in this project is a library
that does one thing and leaves the shape of your program alone; the engine
is the opposite trade. It owns the loop, and in exchange it can do things a
library cannot — chiefly render *between* two simulation states, which is
most of the difference between a game that looks smooth and one that does
not.

The rule it holds to: **the engine owns structure, the game owns meaning.**
It knows a frame has a duration and a simulation has a rate. It never knows
what a goblin is.

```cmake
target_link_libraries(your_game PRIVATE SDLStatic::Engine)
```

This page covers the loop and time, presentation and scaling, scenes,
graphics settings, the camera, actors, engine-owned rendering, input,
actions, physics, assets and lighting. Saves, localisation and the script
bindings follow.

## The loop

```c
static void FixedUpdate(void *user, float step) { /* simulation: 60 Hz */ }
static void Render(void *user, float alpha)     { /* draw, interpolated */ }

int main(void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDLStatic_Engine *engine = SDLStatic_CreateEngine(NULL);

    SDLStatic_GameHooks hooks = {0};
    hooks.fixed_update = FixedUpdate;
    hooks.render = Render;
    SDLStatic_RunGame(engine, &hooks, &game);

    SDLStatic_DestroyEngine(engine);
}
```

`SDLStatic_RunGame` owns the loop, including on the web, where it hands
control to the browser and returns immediately — so cleanup belongs in the
`unload` hook, not after the call. A game that wants its own loop calls
`SDLStatic_EngineTick` instead.

### Why a fixed tick with interpolation

A loop that measures a delta and multiplies by it is *correct* and still
looks worse than Godot or Unity, for reasons that compound:

- **Delta noise becomes position noise.** Real frame times are 16.4, 17.1,
  15.9 ms — never clean. Multiplying by them makes a steadily moving object
  travel a slightly different distance each refresh, which reads as shimmer.
- **The display is quantised and a free-running simulation is not.** The
  panel shows a new image every 16.667 ms whatever you do; sampling
  continuous motion at irregular intervals and displaying it at regular ones
  is judder even when every frame arrives on time.
- **Measuring after present folds the vsync wait into the next frame**,
  producing an alternating long/short beat.
- **A hitch produces a huge delta**, which either teleports everything or
  triggers a burst of catch-up that makes the next frame late too.

So the engine does four things, and each is worth a line in your mental
model of the frame:

| | |
|---|---|
| **Clamp** | A frame longer than 250 ms is a stall, not a slow frame. The time is dropped. |
| **Smooth** | The measured delta is snapped onto the display's cadence: within 15% of a whole number of refresh periods, it becomes exactly that. 16.4 and 17.1 both become 16.667. |
| **Step** | The simulation advances in exact, equal steps — never a fraction, never a variable amount. |
| **Interpolate** | Rendering happens *between* the last two steps, using `alpha`. |

Delta smoothing is the piece hand-rolled loops usually miss, and it removes
most visible judder on its own. It is not a hack: the display, not the
clock, defines the timeline.

### Using alpha

```c
static void FixedUpdate(void *user, float step) {
    Game *g = user;
    g->previous_x = g->x;          /* remember where we were */
    g->x += g->velocity * step;    /* advance by an exact step */
}

static void Render(void *user, float alpha) {
    Game *g = user;
    const float x = g->previous_x + (g->x - g->previous_x) * alpha;
    DrawPlayerAt(x);
}
```

That is the whole contract. Keep the previous value, draw between the two,
and a 60 Hz simulation looks right on a 144 Hz panel.

Two consequences worth knowing:

- Rendering lags the simulation by up to one step (≤16.7 ms). Invisible for
  most games. For a fighting game or a twitch shooter, set
  `interpolation = SDLSTATIC_INTERPOLATE_EXTRAPOLATE`, which predicts
  forward instead — no lag, at the cost of a small overshoot when something
  changes direction sharply.
- A teleport must not be interpolated, or the object smears across the
  screen. Set `previous` to the new position when you jump.

### `fixed_update` versus `update`

Both exist because games need both:

- `fixed_update(step)` runs 0..5 times per frame, always with the same
  step. **Simulation** goes here — movement, physics, AI — because it must
  not depend on how fast the machine is.
- `update(dt)` runs exactly once per frame with the real delta.
  **Cosmetics** go here — camera smoothing, UI tweens, anything that should
  track the display rather than the simulation.

An engine that offers only one forces games to fake the other.

### When the machine cannot keep up

Catch-up is capped at five steps per frame. Beyond that the engine drops the
outstanding time and increments a counter:

```c
if (SDLStatic_EngineOverloadFrames(engine) > last_seen) {
    LowerQuality();   /* fewer particles, half-resolution lighting */
}
```

Dropping the debt makes a struggling game *slow*, which is survivable, in
place of *spiralling*, which is not.

## Coordinate spaces

Three spaces, and it is worth being exact about which is which:

| Space | What it is | Who decides it |
|---|---|---|
| **World** | where things are in the level — a dungeon 20,000 units across | your game |
| **Design** | the fixed virtual screen you compose into, e.g. 1920×1080 | `config.design_width/height` |
| **Pixel** | the actual framebuffer of the window | the display |

A **camera** maps world → design; the presentation maps design → pixels. A
game that draws directly in design coordinates is saying "the world is
exactly one screen" — fine for a menu, not for a level. See
[The camera](#the-camera) below.

### Design → pixels costs nothing

SDL applies logical presentation as a **coordinate transform**, not an
offscreen render target: a rectangle at (100, 100) in a 1920-wide design
space is rasterised directly at (50, 50) on a 960-wide window. So there is
no supersampling, no resample blur, and no penalty for authoring at a
different resolution from the one you display at.

That is why the reference resolution should be chosen for convenience —
pick 1920×1080 and the numbers stay readable — and **not** for the target
hardware. A 1920×1080 design renders natively at 4K.

*Art* is the separate question. Scaling coordinates is free; scaling
*images* is not, because a 1× sprite stretched to 4K is soft and a 4×
sprite minified to a laptop shimmers. `SDLStatic_EngineAssetScale` returns
1, 2 or 4 so a game that ships more than one art set can pick:

```c
char path[256];
SDL_snprintf(path, sizeof(path), "sprites/player@%dx.png",
             SDLStatic_EngineAssetScale(engine));
```

## Presentation modes

### Fitting a design space to a window that is the wrong shape

A window is rarely the shape you composed for. There are only three things
any engine can do about it — **show bars, crop, or distort** — and the
presentation mode is how you choose. Nothing else about the game changes;
the drawing code is identical in all six.

#### Setting it

At creation:

```c
SDLStatic_EngineConfig config = {0};
config.design_width = 1920;
config.design_height = 1080;
config.presentation = SDLSTATIC_PRESENT_LETTERBOX;   /* already the default */

SDLStatic_Engine *engine = SDLStatic_CreateEngine(&config);
```

`SDLSTATIC_PRESENT_LETTERBOX` is zero, so a zero-initialised config —
including `SDLStatic_CreateEngine(NULL)` — gets it without asking.

And at runtime, which is what an options menu needs:

```c
SDLStatic_EngineSetPresentation(engine, SDLSTATIC_PRESENT_INTEGER);
SDLStatic_EnginePresentation mode = SDLStatic_EnginePresentation_(engine);
```

The change takes effect immediately: the view rect is correct on the very
next call, not the next frame, so a menu can redraw its own preview from it.
Persist the value with the settings and restore it on launch.

#### Choosing one

| Mode | Aspect | Bars | Crops | Suited to |
|---|---|---|---|---|
| **`LETTERBOX`** (default) | kept | yes | no | **almost everything** — see below |
| `EXPAND` | kept | no | no | competitive or exploration games where a wider monitor giving a wider view is a feature, not an unfairness |
| `OVERSCAN` | kept | no | **yes** | full-bleed backdrops and video, where filling the screen matters more than the edges |
| `INTEGER` | kept | yes | no | pixel art, where a fractional scale is what makes it shimmer |
| `STRETCH` | **lost** | no | no | effectively nothing; it distorts |
| `NATIVE` | n/a | n/a | n/a | tools, editors and debug windows that want to think in pixels |

**Recommendation: `LETTERBOX`, unless you have a specific reason not to.**
It is the only mode that guarantees every player sees exactly the frame you
composed — same aspect, nothing cut off, nothing stretched — at every window
size, on every monitor, from a phone to an ultrawide. The view rect never
changes, so UI can sit at fixed coordinates and a screen that was laid out
carefully stays laid out. The price is bars on a mismatched display, and
that is a very small price for "it looks right everywhere". It is also the
easiest mode to *test*, because there is exactly one composition to check.

The others are each a considered trade against that:

- **`EXPAND`** trades a fixed frame for filling the screen. Good when the
  extra visible world is harmless or desirable; bad when seeing further is a
  competitive advantage, and it means every layout must be checked at
  several aspect ratios.
- **`OVERSCAN`** trades content for filling the screen. Whatever falls
  outside the window is gone, so it only suits art with nothing important
  near the edges.
- **`INTEGER`** trades screen coverage for pixel-perfect scaling. Essential
  for pixel art, wasteful for anything else — on a 5120×2106 window a
  1920×1080 design can only take 1×, leaving most of the screen as bars.
- **`STRETCH`** distorts. Circles become ovals. Offer it in an options menu
  if you like, but do not ship it as a default.
- **`NATIVE`** turns the whole design-space idea off.

Whichever you pick, these two calls describe what the player is seeing:

```c
const SDL_FRect view = SDLStatic_EngineViewRect(engine);  /* all that is visible */
const SDL_FRect safe = SDLStatic_EngineSafeRect(engine);  /* where you composed */

DrawBackdrop(view);                       /* fill everything, edge to edge */
DrawHealthBar(safe.x + 40, safe.y + 40);  /* anchor UI to the safe area */
```

The **view rect** is everything on screen. The **safe rect** is the design
rectangle intersected with it: the part guaranteed visible, and where the
game was actually composed. Anchor UI to the safe rect and a button never
drifts off into the periphery on a 21:9 monitor; fill the view rect with
backdrops and there is never a gap at the edge. Consoles call the same idea
title-safe.

In `LETTERBOX` — and in `INTEGER` and `STRETCH` — the two are identical and
never change, which is exactly why it is the recommended mode: writing
against the safe rect and writing against fixed coordinates give the same
result. Using the safe rect anyway costs nothing and means switching modes
later is free.

In `EXPAND` the view is recomputed whenever the window's pixel size
changes, so dragging a window between a laptop screen and an ultrawide is
handled without the game hearing about it.

Both rects, and `SDLStatic_EngineRenderScale`, are read back out of SDL
rather than derived from the mode — because the modes do not agree on what
"the scale" is. `INTEGER` floors it, `OVERSCAN` scales *past* the window and
crops, `STRETCH` uses a different factor per axis. So under `OVERSCAN` the
view rect is the band that survives the crop, not the full design space, and
the safe rect shrinks with it: a HUD anchored to the safe rect stays on
screen in the one mode that would otherwise push it off.

> Capturing a frame: `SDL_RenderReadPixels` takes its rect in **pixels**,
> not render coordinates, and `NULL` means the whole logical area. Under
> `OVERSCAN` that is bigger than the window, and the driver returns rows
> that are not in the framebuffer. Pass `SDLStatic_EnginePixelSize` instead.

### One art set at every size

Nothing above requires shipping art at several resolutions. Scaling is a
coordinate transform, so a single set holds up in both directions provided
the art is authored at the largest size it will be drawn and drawn with
linear filtering. Point sampling is what makes downscaled art sparkle, and
that is a filter setting rather than an asset problem — reserve nearest for
pixel art, ideally alongside `INTEGER`. `SDLStatic_EngineAssetScale` is
there for anyone who later wants a second set; it is not a prerequisite.

### Mouse and touch

SDL reports events in *window* coordinates, so they need converting:

```c
float x, y;
SDLStatic_EngineWindowToDesign(engine, event.motion.x, event.motion.y, &x, &y);
```

## The frame limiter

Vsync is on by default and usually paces the loop for free. Usually — an
occluded window, an off-screen window, or a driver that ignores the request
will present immediately, and the loop then spins at thousands of frames a
second, heating the machine to draw images nobody sees. (This is measurable:
the same 181-frame run took 0.09 s unpaced and 1.55 s paced.)

So the engine sleeps out the remainder of each frame — to the display's
refresh rate by default, or to `config.max_fps`, or not at all if you set a
negative value. When vsync is already pacing things the remainder is zero
and the limiter costs nothing.

`SDLStatic_EngineSetMaxFps` changes it at runtime, because an options menu
will want to.

## Time control

```c
SDLStatic_EngineSetTimeScale(engine, 0.0f);  /* pause the world  */
SDLStatic_EngineSetTimeScale(engine, 0.25f); /* slow motion      */
SDLStatic_EngineSetTickRate(engine, 120);    /* from an options menu */
```

Time scale affects the simulation only: `update` and `render` keep running
at full rate, so a menu animates over a frozen world. Changing the tick rate
carries the accumulated fraction across, so it does not stutter.

## Testing a loop

"Smooth" is otherwise a matter of opinion, so the engine can be built
headless with an injected clock:

```c
SDLStatic_EngineConfig config = {0};
config.headless = true;      /* software renderer, no window */
config.manual_clock = true;  /* time only advances when told */

SDLStatic_EngineAdvance(engine, 16666666);  /* one 60 Hz frame */
SDLStatic_EngineTick(engine);
```

That is what the module's own tests use to assert the properties that make
motion smooth: a second of steady frames produces exactly 60 steps; a second
of *noisy* frames also produces exactly 60; a two-second stall produces at
most five; on a simulated 144 Hz display, 144 renders accompany 60 steps and
`alpha` never leaves [0, 1).

## Scenes

A scene is a screen: a title, a level, a pause menu, a loading screen. The
engine keeps them in a **stack**, not a single "current scene" pointer,
because a stack is what makes a pause menu possible — pushing one leaves
the level underneath intact, so popping it returns to exactly where the
player was, with nothing to rebuild and no state to restore.

```c
static SDLStatic_SceneDef kLevel = {
    .name = "level",
    .state_size = sizeof(LevelState),
    .load = LevelLoad,           /* build the world; false aborts the push */
    .fixed_update = LevelStep,
    .render = LevelRender,
};

SDLStatic_ScenePush(engine, &kLevel);
```

`state_size` bytes are allocated with the scene and zeroed;
`SDLStatic_SceneState` hands them back. That keeps a scene's data next to
its lifetime, so leaving the scene frees it and no game code has to
remember. The definition itself is **copied**, so it may be a local, a
temporary, or a table a script just built.

### Lifecycle

`load` once when created → `enter` whenever it becomes the top scene →
`fixed_update`/`update`/`render`/`event` while it is on the stack → `exit`
whenever it stops being the top → `unload` once before destruction. A scene
covered by a pause menu sees `exit`, and sees `enter` again when the menu
pops.

### Covered scenes

Two flags answer the two questions a stack has to answer:

| Flag | Meaning |
|---|---|
| `SDLSTATIC_SCENE_UPDATE_WHEN_COVERED` | keep simulating underneath. Off by default — which is what "paused" means. On for a level running behind a dialogue box. |
| `SDLSTATIC_SCENE_TRANSPARENT` | this scene does not fill the screen, so draw the one below it first. What makes a pause menu look like one. |

An opaque scene means the scenes below are not drawn at all, which is the
saving that makes a deep stack cheap.

### Changes are deferred

`Push`, `Pop`, `Replace` and `Reset` take effect at the **end of the frame**,
so a scene can replace itself from inside its own update and keep running
to the end of that update without the ground moving underneath it. Two
changes in one frame is an error rather than a silent last-one-wins.

### Transitions

```c
SDLStatic_SceneTransitionTo(engine, &kLevel, SDLSTATIC_TRANSITION_FADE, 0.35f);
```

A fade runs in two halves: the outgoing scene fades to the transition
colour, **the swap happens at the midpoint** where the screen is covered,
and the incoming scene fades up. Only one scene is ever live, so a
transition cannot double the game's memory or run two simulations at once —
and the swap is hidden anyway. Scenes keep updating during a fade, so a
level does not freeze as it leaves.

## Getting your game into the engine

Three ways, depending on the language, all supported deliberately.

**C and C++ link the engine.** The engine is a library first: your program
owns `main`, fills in the hooks and links `SDLStatic::Engine`. No plugin
loading, no dynamic symbols — those fight static linking, and iOS and the
web forbid them outright.

**Lua and Ruby are run by the player binary.** The engine also ships as an
executable that hosts a script — `sdlstatic-engine game.lua` — defaulting to
`main.lua` or `main.rb` in the current directory. This is the Love2D model
and it is the fastest way to start a game.

**Assets come from an archive.** The player mounts `media.zip`, `media.dat`
(both may be encrypted) or a plain `media/` directory, in that order, and
`--media` overrides it. A finished game can have its archive appended to the
executable so it ships as a single file.

The full mechanism lands with the scripting subsystem; the loop is
independent of it.

## Graphics settings

Everything a player can change lives in one struct,
`SDLStatic_GraphicsSettings` — plain data, so it copies, compares and
serialises. `<SDLStatic/engine_graphics.h>`.

```c
SDLStatic_GraphicsSettings gfx;
SDLStatic_GraphicsResolve(&gfx, argc, argv, "acme", "mygame");

SDLStatic_EngineConfig config = {0};
config.graphics = &gfx;
config.argc = argc;                   /* so --media works */
config.argv = argv;
SDLStatic_Engine *engine = SDLStatic_CreateEngine(&config);
```

and an options screen is three lines:

```c
SDLStatic_GraphicsSettings next = *SDLStatic_EngineGraphics(engine);
next.bloom = slider;
SDLStatic_EngineSetGraphics(engine, &next);       /* applies now */
SDLStatic_GraphicsSave(&next, "acme", "mygame");  /* persists */
```

### Where the values come from

`SDLStatic_GraphicsResolve` walks five sources, each beating the one before:

| | Source | |
|---|---|---|
| 1 | `SDLStatic_GraphicsDefaults()` | compiled in |
| 2 | `media/config.toml` **inside the media archive** | what the game shipped with |
| 3 | `media/config.toml` in the working directory | an installer's, or a server's |
| 4 | `media/config.toml` in the pref directory | the player's saved settings |
| 5 | the command line | right now |

The player's saved settings beat what the game shipped with, and the command
line beats everything — which is the order you want at 2am when a game will
not start because of a setting somebody saved. `--config=PATH` replaces the
search entirely: someone passing a path wants *that* file, not that file
plus three others.

Nothing here is fatal. A malformed file leaves the previous values in place
and reports through `SDLStatic_GraphicsConfigError`; every value is clamped
on the way in, so a hand-edited `brightness = 40` cannot black out a game.
`SDLStatic_GraphicsConfigPath` says which file was actually read, which is
worth logging at startup — "why is my config being ignored" is otherwise a
long afternoon.

The archive is reached through a callback rather than a PhysFS dependency,
because by the time settings resolve the archive may be a zip, an encrypted
`.dat`, a plain directory, or bytes compiled into the executable, and
mounting it is the game's decision:

```c
static bool ReadFromVfs(const char *path, char **text, void *user) {
    int size = 0;
    unsigned char *data = SDLStatic_LoadVFSFile(path, &size);
    if (data == NULL) return false;
    *text = (char *)data;
    return true;
}
SDLStatic_GraphicsSetArchiveReader(ReadFromVfs, NULL);   /* before Resolve */
```

### config.toml

Keys are optional, and are accepted at the top level as well as in their
section — someone writing this by hand should not have to know which section
a key lives in.

```toml
[display]
vsync = true
max_fps = 0            # 0 follows the display, negative uncaps
window_mode = "windowed"     # windowed | borderless | exclusive
presentation = "letterbox"   # letterbox | expand | overscan | integer | stretch | native
render_scale = 1.0     # 0.25-2.0
filter = "auto"        # auto | linear | nearest

[quality]
particles = "high"     # off | low | medium | high
dynamic_lights = "high"
shadows = "high"

[effects]
bloom = 0.0
bloom_threshold = 0.7
crt = 0.0
crt_curvature = 0.0
pixelation = 1         # 1 is off
chromatic_aberration = 0.0
antialias = "off"      # off | fxaa

[image]
brightness = 1.0
contrast = 1.0
saturation = 1.0
color_blind = "none"   # none | protanopia | deuteranopia | tritanopia

[accessibility]
reduced_flashing = false
screen_shake = 1.0
ui_scale = 1.0
```

Every key has a command-line twin: `--vsync=off`, `--max-fps 120`,
`--shadows=low`, `--bloom=0.4`, `--render-scale=0.75`, `--fullscreen`,
`--color-blind=deuteranopia`. Both `--key=value` and `--key value` work,
booleans take on/off/true/false/1/0 or may be bare (`--vsync`, `--no-vsync`),
and anything unrecognised is ignored — the game owns the command line and the
engine is only a guest on it.

### Three kinds of setting, which fail differently

**Engine settings** — vsync, frame cap, window mode, presentation, render
scale, filtering — apply the moment they are set.

`render_scale` deserves a mention: it renders at a fraction of the window's
resolution and lets the display scale the result up. It is the single
largest performance lever available, it needs no art changes, and on a
handheld it is the difference between 30 and 60 fps.

**Post-processing** — bloom, CRT scanlines and curvature, pixelation,
chromatic aberration, FXAA, brightness/contrast/saturation, colour-blind
correction — runs as GLSL over the finished frame, and the engine asks SDL
for an OpenGL renderer by default so that it can. Without one they are
skipped rather than fatal: a game must not fail to start because a player
asked for scanlines. Ask `SDLStatic_EngineEffectsAvailable` and grey the
section out rather than offering sliders that do nothing.

The chain runs *before* the `post_render` hook, so a HUD drawn there is not
scanlined along with the world — real CRT games had no UI layer, and
applying the effect to one reads as a bug rather than a style. It is also
the only place a screenshot shows what the player actually saw.

**Budgets** — particles, dynamic lights, shadows, screen shake, UI scale —
are carried by the engine and spent by the game. The engine cannot know what
a particle costs in your game, so it does not pretend to; it converts the
player's choice into concrete numbers and leaves the spending to you:

```c
const SDLStatic_GraphicsSettings *g = SDLStatic_EngineGraphics(engine);

int count = (int)(base * SDLStatic_GraphicsParticleDensity(g->particles));
SDLStatic_SetLightMapScale(scene, SDLStatic_GraphicsLightMapScale(g->dynamic_lights));
SDLStatic_SetLightShadowRays(scene, SDLStatic_GraphicsShadowRays(g->shadows));
SDLStatic_SetLightShadowSoftness(scene, SDLStatic_GraphicsShadowSoftness(g->shadows));
```

Note `SDLStatic_GraphicsShadowSoftness` returns 0 below the top tier: soft
edges need rays to look soft, and a penumbra built from 32 rays reads as
banding rather than softness.

`reduced_flashing` is a safety setting rather than an aesthetic one, so it
overrides the aesthetic ones — enabling it caps bloom, because bloom is what
turns a bright frame into a flash.

## The camera

`<SDLStatic/engine_camera.h>`. The camera maps **world** coordinates onto
the design space; the presentation maps design onto pixels. A game with no
camera is saying "the world is exactly one screen".

```c
SDLStatic_Camera camera;
SDLStatic_CameraInit(&camera, engine);
camera.bounds = (SDL_FRect){0, 0, 8000, 2000};   /* the level */
camera.smoothing = 0.15f;                        /* seconds to catch up */
camera.deadzone_w = 300.0f;                      /* design units */

/* update */
SDLStatic_CameraFollow(&camera, player.x, player.y);
SDLStatic_CameraUpdate(&camera, engine, dt);

/* render */
SDLStatic_CameraBegin(engine, &camera);
for (Entity *e = level; e; e = e->next) {
    if (!SDLStatic_CameraVisible(&camera, e->box)) continue;   /* cull */
    SDL_FRect dst = SDLStatic_CameraRect(&camera, e->box);
    SDL_RenderTexture(renderer, e->texture, NULL, &dst);
}
SDLStatic_CameraEnd(engine);
```

Update from the per-frame `update` hook, not `fixed_update`: camera movement
is cosmetic and should track the display's rate.

Four things worth knowing:

- **Smoothing is frame-rate independent.** It is exponential decay against
  `dt`, not a fixed fraction per frame — the latter is nearly two and a half
  times faster at 144 Hz than at 60, which is the classic reason a camera
  "feels wrong on someone else's machine".
- **The deadzone is in design units**, converted to world units against the
  zoom, so zooming in does not silently widen it. It is what stops a
  platformer's camera twitching every time the player hops.
- **A level smaller than the view is centred**, not clamped to an edge.
- **`SDLStatic_CameraRect` translates but does not scale.** The renderer is
  already scaled by the zoom; scaling here as well applies it twice.

There is no rotation. SDL's renderer has no general transform, so a rotating
camera would have to rotate every draw call individually, and a field that
only worked for some of them would be worse than not having one.

### Split screen

Four cameras are four viewports over the same world, so split screen is the
same code:

```c
SDLStatic_Camera cameras[SDLSTATIC_SPLIT_MAX];
for (int i = 0; i < 4; i++) SDLStatic_CameraInit(&cameras[i], engine);

int n = SDLStatic_CameraSplit(engine, SDLSTATIC_SPLIT_HORIZONTAL, players, 6.0f, cameras);
for (int i = 0; i < n; i++) {
    SDLStatic_CameraBegin(engine, &cameras[i]);
    DrawWorld(&cameras[i]);
    SDLStatic_CameraEnd(engine);
}
```

| Mode | Layout | Suits |
|---|---|---|
| `HORIZONTAL` | full-width bands, stacked | side-scrollers, which need horizontal room |
| `VERTICAL` | full-height columns | vertical games, and racing on an ultrawide |
| `GRID` | quarters | four players; with three, the odd one takes the whole bottom half rather than leaving a dead quadrant |

One player gets the whole view, so a game runs the same path for one player
and for four. Splitting keeps each camera's own settings, so a game can
configure them once and re-split whenever somebody joins. The `gap` argument
leaves a few design units of black between panes — without it two views abut
and the eye cannot find the boundary.

`SDLStatic_CameraBegin` clips as well as setting the viewport, so a sprite
cannot spill into the other player's half, and
`SDLStatic_CameraScreenToWorld` returns false outside its own viewport,
which is how a game works out whose half was clicked.

## The renderer backend

SDL ships several renderer backends and, left alone, picks the platform's
native one: Metal on Apple, Direct3D on Windows, OpenGL elsewhere. **This
engine asks for OpenGL, everywhere, by default.**

```c
config.backend = SDLSTATIC_BACKEND_OPENGL;   /* already the default */
```

The reason is that the post-processing chain and the lighting module are
GLSL. Under a native backend they cannot run at all, so the same game would
look different on macOS from how it looks on Linux for no reason the player
can see — and writing the effects again in MSL, HLSL and SPIR-V is three
more implementations to keep in step. GLSL 1.x covers desktop GL, GLES on
mobile and WebGL in a browser, which is every platform this project targets.

The cost is worth stating plainly. Apple deprecated OpenGL in 2018: it still
works, it is capped at 4.1, and it will not improve. Metal has lower CPU
overhead. Some Windows OEM drivers have weaker GL than their Direct3D. A 2D
game is very unlikely to measure any of it, but a game that does can say:

| | |
|---|---|
| `SDLSTATIC_BACKEND_OPENGL` | the default; the shader effects work |
| `SDLSTATIC_BACKEND_NATIVE` | Metal/Direct3D/Vulkan; no post-processing |
| `SDLSTATIC_BACKEND_SOFTWARE` | for tools, and for a machine whose drivers are broken enough that nothing else starts |

The hint is a preference, not a demand: on a machine with no working GL, SDL
still returns a renderer and only the shader effects go missing. Better than
refusing to start.

## Assets

The engine mounts the game's assets during `SDLStatic_CreateEngine`, before
anything asks for a file. There is no setup call, because an opinionated
engine that made you write mounting code would not be one.

```c
config.argc = argc;   /* so --media and --media-password work */
config.argv = argv;
```

Search order, first match wins:

| | Source | |
|---|---|---|
| 1 | `--media=PATH`, or `config.media_path` | replaces the search entirely |
| 2 | an archive compiled into the executable | `SDLStatic_EngineEmbedMedia` |
| 3 | `media.zip` beside the executable | possibly encrypted |
| 4 | `media.dat` | the same, named so it does not invite a double-click |
| 5 | `media/` | a plain directory: what you develop against |

Everything mounts at `/`, so `assets/player.png` means the same file
whichever source it came from. That is the point of the ordering: you
develop against `media/`, ship `media.zip`, and one day embed the archive in
the binary — and not one line of the game changes. The embedded archive
comes *before* the files on disk, so a single-file build cannot be quietly
overridden by whatever happens to be sitting in the working directory; the
directory comes last, so building a release archive changes what the game
reads without anyone having to remember to delete it.

```c
SDL_IOStream *io = SDLStatic_OpenVFSRead("assets/player.png");
SDL_Texture *tex = IMG_LoadTexture_IO(renderer, io, true);
```

`SDLStatic_EngineMediaSource` and `SDLStatic_EngineMediaPath` report what
was mounted — worth logging, since "which copy of my assets is this running
against" is otherwise guesswork. A game that wants none of it sets
`config.no_auto_mount`.

Encrypted archives take a password from `--media-password` or
`SDLStatic_EngineSetMediaPassword`. Embedding an encrypted archive with its
password in the same binary is obfuscation rather than security: it stops
casual extraction, not a determined person with a debugger.

## Escape hatches

Two command-line arguments **replace the settings entirely and read no
config file at all**. That is the whole point — they have to work when the
saved settings are what is broken, and reading them first would defeat it. A
player should never have to reinstall a game to undo a setting.

```
--with-default-settings    the shipped defaults: borderless fullscreen,
                           maximum fidelity
--with-safe-mode           a resizable 1280x720 window, graphics low,
                           every shader effect off
```

Both are applied before the rest of the line, so `--with-safe-mode
--bloom=0.5` means safe mode with bloom whichever order they were typed in.

Safe mode turns the budgets *down* rather than off — it still has to be
playable enough to reach the options screen and undo whatever went wrong —
but every shader effect is off, because if the post-processing chain is what
broke the machine, safe mode must not run it. It is windowed and resizable
on purpose: a window that will not display correctly can at least be dragged
somewhere that will.

## Multiple monitors

```c
for (int i = 0; i < SDLStatic_EngineDisplayCount(); i++) {
    printf("%d: %s\n", i, SDLStatic_EngineDisplayName(i));   /* "DELL U2720Q" */
}
SDLStatic_EngineSetDisplay(engine, chosen);
```

or persist it: `display = 1` in `config.toml`, `--display=1` on the command
line.

The window and renderer are **kept, not recreated**. Recreating them is the
obvious implementation and it is a trap: SDL textures belong to the renderer
that made them, so tearing the renderer down invalidates every texture the
game has loaded. A monitor change would silently become a full asset reload,
and any game that did not know to reload would draw nothing at all
afterwards. Moving the window achieves the same result and cannot do that —
the fullscreen mode is dropped, the window is repositioned on the target
display, and the mode is restored.

A saved display index is clamped to what exists at launch, so unplugging the
monitor a game was saved on does not leave it running invisibly on a display
that is no longer there.

## Actors

An actor is a thing in the world with a position and a lifetime. The engine
owns the structure — identity, parenting, transforms, when things are
created and destroyed — and the game owns the meaning. The engine never
learns what a goblin is. `<SDLStatic/engine_actor.h>`.

```c
typedef struct { int health; } Goblin;

static bool GoblinSpawn(SDLStatic_Actor *actor) {
    Goblin *g = SDLStatic_ActorState(actor);
    g->health = 20;
    return true;
}

static void GoblinThink(SDLStatic_Actor *actor, float step) {
    SDLStatic_ActorMove(actor, 40.0f * step, 0.0f);
}

SDLStatic_ActorDef def = {0};
def.type = "goblin";
def.state_size = sizeof(Goblin);
def.spawn = GoblinSpawn;
def.fixed_update = GoblinThink;
def.x = 400.0f;

SDLStatic_ActorId id = SDLStatic_ActorSpawn(engine, &def);
```

`state_size` is all it takes: the engine allocates the bytes, zeroes them,
and frees them when the actor goes away, so an actor's data has the actor's
lifetime and nothing has to remember.

### Handles, not pointers

`SDLStatic_ActorId` is a 48-bit handle — a 24-bit slot index and a 24-bit
generation. It is not a pointer, and that is the single most important
decision in this subsystem.

A game stores `SDLStatic_ActorId target` on an enemy. The player dies. With
a pointer, the enemy's next dereference reads whatever was allocated in the
player's place: usually another actor, so the enemy quietly starts chasing a
door. With a handle, the slot's generation has advanced, so
`SDLStatic_ActorGet` returns NULL and the enemy finds out its target is
gone — which is the thing it needed to know.

```c
SDLStatic_Actor *victim = SDLStatic_ActorGet(engine, target);
if (victim == NULL) { GoIdle(self); return; }
```

### Deferred creation and destruction

Spawn and destroy both take effect **at the end of the frame**, so the set
of actors cannot change underneath code that is walking it. That removes the
most common crash in a system like this — an actor killing another during an
update it is inside — as a category rather than case by case.

The handle from `SDLStatic_ActorSpawn` is valid immediately: you may store
it, parent to it and set it up. The actor does not receive updates or appear
in queries until the frame it was created in has finished, so a spawner
cannot accidentally run its own children in the same tick that made them.

Destroying a parent destroys its children, which is what "part of" is
supposed to mean, and destroying something twice is not an error — two
things killing the same target in one frame is normal, and making it an
error would only mean every caller writes the same guard.

### Hierarchy

```c
SDLStatic_ActorSetParent(sword, knight_id);   /* keeps its world position */
```

Transforms compose through parents, so moving, rotating or scaling a parent
carries its children. Reparenting preserves the actor's *world* position —
"pick this up" should not teleport it — and a change that would make a cycle
is refused, because an actor that is its own ancestor turns every transform
walk into an infinite loop.

### Interpolation, once

The engine snapshots every actor's transform before each fixed step, so the
loop's interpolation contract is handled for the whole world rather than by
every actor keeping its own `previous_x`:

```c
static void Render(void *user, float alpha) {
    SDLStatic_ActorTransform t = SDLStatic_ActorRenderTransform(actor, alpha);
    DrawSprite(t.x, t.y, t.rotation);
}
```

Use `SDLStatic_ActorTeleport` for a jump. A teleport that goes through
`SetPosition` is interpolated, and the actor smears across the screen from
somewhere it never was.

### Queries

```c
SDLStatic_ActorId enemies[64];
int n = SDLStatic_ActorQuery(engine, NULL, kTagEnemy, enemies, 64);
```

Filter by type, by tags, or both. Tags are a 32-bit mask the game assigns
meaning to, so "every enemy" is one bit test per actor rather than a string
comparison. Queries write into a caller's array rather than allocating,
because they run every frame — a query that allocates is a query you end up
caching by hand.

`SDLStatic_ActorFindByName` is for the one actor a level needs to address
directly: the boss, the exit door.

### Messages

```c
SDLStatic_ActorMessage hit = {0};
hit.id = MSG_DAMAGE;
hit.sender = SDLStatic_ActorGetId(self);
hit.a = 7.0f;
SDLStatic_ActorSend(engine, target, &hit);
```

Messages are queued and delivered after all updates and before the frame is
drawn, so a message sent this frame is handled this frame and the frame is
drawn from a settled world. They are copied, and carry no pointers — a
message that carried one would outlive what it pointed at about as often as
not.

Delivery is not a call through. "Damage this, which kills it, which spawns
three of those, one of which damages me" would otherwise recurse arbitrarily
deep inside a single update. Messages sent *while* the queue is draining are
delivered next frame instead, which bounds the work in a frame: two actors
answering each other forever become visibly slow rather than a stack
overflow.

A target that dies between the send and the delivery simply does not receive
it, which is what "it is gone" should mean.

## Rendering

Give an actor a sprite and the engine draws it — ordered, culled, and at
the interpolated position. `<SDLStatic/engine_render.h>`.

```c
SDLStatic_Sprite sprite = SDLStatic_SpriteDefault();
sprite.texture = goblin_texture;
sprite.width = 64.0f;
sprite.height = 96.0f;
sprite.origin_y = 1.0f;        /* the position is where its feet are */
sprite.layer = LAYER_ACTORS;
sprite.sort_by_y = true;
SDLStatic_ActorSetSprite(actor, &sprite);

/* in the render hook */
SDLStatic_RenderWorld(engine, &camera, alpha);
SDLStatic_RenderOverlay(engine, alpha);
```

That is the whole draw loop for a 2D game. Start from
`SDLStatic_SpriteDefault()` rather than a zeroed struct — a zeroed sprite
would be invisible, fully transparent and pinned by its top-left corner,
which is never what anybody meant.

A sprite with **no texture** draws a solid rectangle in its colour. That is
deliberate: it is how a game gets something on screen before it has any art,
and how a debug view marks a hitbox. Every screenshot in this section was
made that way.

### What the engine is doing for you

**Ordering.** Draw order is the difference between a character standing in
front of a tree and inside it. Sprites sort by `layer` first, then by
`order` — or by world Y when `sort_by_y` is set, which is how a top-down or
isometric game gets depth out of a flat scene. Doing it in the engine means
it happens *after* the actors have moved, rather than from a value the game
had to remember to update.

Ties break on the actor id. That is not decoration: without a stable
tiebreak, two sprites at the same depth swap places whenever the sort runs
differently, and the flicker only appears when things overlap — exactly when
somebody is looking.

**Culling.** Sprites outside the camera's visible rectangle are skipped. A
level is bigger than the screen, which is the entire reason a camera exists,
so this turns "draw the level" from O(level) into O(screen). The demo draws
66 of 426 sprites in a single view; in two-way split screen each narrower
viewport draws 32 and 37.

```c
SDLStatic_RenderStats s = SDLStatic_RenderLastStats(engine);
printf("considered %d, culled %d, drew %d\n", s.considered, s.culled, s.drawn);
```

Worth putting on a debug overlay: "drew 4000" is how you find out culling
is not working.

A rotated sprite is culled against its circumscribed square rather than its
rectangle, or a sprite near the screen edge would vanish as it turned.

**Interpolation.** Sprites draw at `SDLStatic_ActorRenderTransform`, so
motion is smooth without any game writing its own `previous_x`.

### Origins

`origin_x`/`origin_y` say where the actor's position sits within the sprite,
as a fraction of its size. The default (0.5, 0.5) centres it. **(0.5, 1.0)
is what you want for anything standing on ground**: the actor's position
becomes where its feet are, which makes both Y-sorting and physics agree
with what the player sees. Rotation happens about the same point, so a
sprite pinned at its feet turns about its feet rather than its waist.

### World and screen

`SDLStatic_RenderWorld` draws world sprites through a camera.
`SDLStatic_RenderOverlay` draws sprites with `screen_space` set, in design
coordinates, ignoring the camera.

They are separate calls because a HUD belongs to the player, not to a
viewport. A split-screen game calls RenderWorld once per camera and
RenderOverlay once, at the end:

```c
for (int i = 0; i < players; i++)
    SDLStatic_RenderWorld(engine, &cameras[i], alpha);
SDLStatic_RenderOverlay(engine, alpha);
```

### What the engine does not do

**It does not load textures.** A sprite holds an `SDL_Texture *` the game
made however it liked. Drawing what you are given and fetching what you
asked for are different jobs with different failure modes, and merging them
makes both worse; asset streaming is its own subsystem.

## Input

The engine pumps SDL's events once a frame and folds them into state the
game **asks** for. `<SDLStatic/engine_input.h>`.

```c
if (SDLStatic_KeyPressed(engine, SDL_SCANCODE_SPACE)) Jump();
if (SDLStatic_GamepadButtonDown(engine, 0, SDLSTATIC_PAD_A)) Hold();

float x, y;
SDLStatic_GamepadStick(engine, 0, 0, &x, &y);
```

Polling rather than callbacks, because a game asks "is the player holding
right" at the point in its own logic where the answer matters, and an event
callback arrives at a point where it does not. Every callback-based game
ends up building this state table by hand, usually with one of the two bugs
below in it.

### Edges last the whole frame

`Pressed` and `Released` mean "this frame" and stay true for **all** of it,
including every `fixed_update` step — of which there may be several.

This is the bug worth knowing about. A jump polled from a fixed step, with
edges cleared per step, is silently dropped whenever a frame happens to run
two steps: the first step sees the press, the second does not, and which one
your `if` lives in decides whether the input registered. Here the edges are
computed once at the top of the frame from the difference between this
frame's held set and the last one, so all steps agree. There is a test that
runs a 50 ms frame (three steps at 60 Hz) and asserts all three see the
press.

### Disconnection is normal

A gamepad that goes away reads as **neutral** — no buttons, sticks at zero —
rather than freezing at whatever it was doing. A player whose battery dies
mid-run should stop, not keep sprinting into a pit. Slots are stable, so
reconnecting puts that player back where they were rather than shuffling
everyone along, and a fifth controller simply is not a player rather than
displacing one of the four already playing.

### Devices

| | |
|---|---|
| **Keyboard** | scancodes (key *positions*, so WASD survives AZERTY), modifiers, and `SDLStatic_TextTyped` for text — the only correct way to read what an IME or layout produced |
| **Mouse** | position and delta in **design coordinates**, left/middle/right plus two thumb buttons, and a wheel with vertical *and* horizontal movement, sign-corrected for natural scrolling |
| **Gamepads** | four slots; every button on an Xbox pad including the share button, all four Elite paddles and the touchpad click; both sticks; both triggers as analog values *and* as buttons |
| **Touch** | up to ten fingers in design coordinates, with `FingerInRect` and `FingerHeldInRect` as the building blocks for on-screen controls |
| **Motion** | gyro and accelerometer, from a controller that has them or from the device itself |

Rumble is `SDLStatic_GamepadRumble(engine, player, low, high, ms)` — the two
motors are different weights, so a hit wants low and a pickup wants high —
plus `RumbleTriggers` on pads that have them. `SDLStatic_GamepadStopRumble`
exists because a controller left buzzing while the player is in a menu is a
bug people remember.

### Sticks are round

`SDLStatic_GamepadStick` applies a **radial** deadzone: it measures the
stick's distance from centre, ignores it below the threshold, and rescales
the rest to a full 0..1.

Deadzoning each axis separately is the classic mistake — it carves a square
hole out of a round stick, so a gentle diagonal reads as zero while the same
distance straight up does not, and the player feels the corners.

### Sticks as buttons, for menus

```c
if (SDLStatic_GamepadDirectionRepeat(engine, player, SDLSTATIC_DIR_DOWN)) SelectNext();
```

Navigating a menu with a stick is otherwise miserable: a raw threshold test
moves the selection sixty times a second, and a bare edge moves it once and
stops while the player is still holding. This gives one press immediately, a
pause, then a steady repeat — what a keyboard does, because that is the
behaviour everyone has already learned. Both sticks and the d-pad feed it,
so a menu works with either without knowing which the player used.

## Actions

Game code should say what it means, not which key means it.
`<SDLStatic/engine_binding.h>`.

```c
SDLStatic_ActionMap *map = SDLStatic_ActionMapCreate();
SDLStatic_ActionBindKey(map, "jump", SDL_SCANCODE_SPACE);
SDLStatic_ActionBindPad(map, "jump", SDLSTATIC_PAD_A);
SDLStatic_ActionBindKeySigned(map, "move_x", SDL_SCANCODE_A, -1);
SDLStatic_ActionBindKeySigned(map, "move_x", SDL_SCANCODE_D, +1);
SDLStatic_ActionBindAxis(map, "move_x", SDLSTATIC_AXIS_LEFT_X, 0);

if (SDLStatic_ActionPressed(engine, map, player, "jump")) Jump();
float move = SDLStatic_ActionValue(engine, map, player, "move_x");
```

A game written against scancodes cannot be rebound without editing the game,
cannot support a controller without writing every check twice, and cannot be
played by someone whose hands do not fit the layout the designer happened to
have. An action map is how all three stop being the game's problem.

**Actions are signed and analog**, in [-1, 1], not booleans. A key
contributes its binding's sign, a stick its deflection — so "move_x" bound
to A, D *and* the stick works with all three at once, and the game reads one
number whichever the player used. A boolean action cannot express a stick,
so an engine with boolean actions grows a parallel axis API and every game
ends up using both.

`SDLStatic_ActionVector` normalises past unit length, so holding two keys
does not move a player 41% faster diagonally.

**Who is player 2:** gamepad bindings read the pad in the player's own slot.
Keyboard and mouse bindings belong to whichever player
`SDLStatic_ActionMapSetKeyboardPlayer` says — player 0 by default, or -1 for
a gamepad-only game — because there is one keyboard and four people cannot
share it.

### Rebinding

```c
SDLStatic_Binding pressed;
if (SDLStatic_ActionCapture(engine, -1, &pressed)) {
    SDLStatic_ActionClear(map, "jump");
    SDLStatic_ActionBind(map, "jump", pressed);
    SDLStatic_ActionMapSave(map, "acme", "mygame");
}
```

`ActionCapture` ignores movement, or a stick resting slightly off-centre
would capture itself the instant the prompt opened. Bindings render as text
— `"space"`, `"pad:a"`, `"axis:left_x"`, `"-a"` — for a settings screen and
for `media/bindings.toml` beside `config.toml`:

```toml
[bindings]
jump = ["space", "pad:a"]
move_x = ["-a", "+d", "axis:left_x"]
```

Loading **replaces the bindings of actions the file mentions and leaves the
rest alone**, so a player who rebound one key does not lose every other
binding when the game adds a new action in a later version. A malformed file
leaves the defaults in place, and an unparseable individual binding is
skipped rather than being fatal.

## Physics

Give an actor a body and the engine simulates it, then writes the result
back onto the actor's transform — so the sprite the renderer draws is
already in the right place. `<SDLStatic/engine_physics.h>`.

```c
SDLStatic_BodyDef def = SDLStatic_BodyDefault();
def.shape = SDLSTATIC_SHAPE_CAPSULE;
def.width = 46.0f;
def.height = 88.0f;
def.offset_y = -44.0f;      /* the actor stands at its feet */
def.fixed_rotation = true;
SDLStatic_ActorAddBody(actor, &def);
```

Start from `SDLStatic_BodyDefault()`: a zeroed def has no size and no
density, which is a body that falls through the world.

### It steps with the simulation, not with the frame

The world advances once per `fixed_update`, with the same step every time.
A solver fed a variable timestep produces different results on different
machines, and a game whose physics depend on frame rate cannot be tested,
recorded or played fairly. The fixed tick exists for exactly this reason and
physics is its most demanding customer.

Bodies step **after** the actors' own `fixed_update`, so a game sets a
velocity and the solver acts on it in the same step rather than the next.

### Pixels are not metres

Box2D is tuned for a world measured in metres, where a person is about 2
units tall. Games are written in pixels, where a person is about 100. Feed
it pixels and everything becomes a thousand-tonne skyscraper: contacts
jitter, stacks explode, and the tuning constants stop meaning what they were
tuned to mean.

So the engine converts at the boundary. `PixelsPerMetre` is 64 by default —
a 64-pixel crate is a one-metre crate — and **every number in the physics
API is in design units**, the same coordinates the game already draws in. No
game code ever sees a metre.

### One position, and the solver owns it

After each step, every body's position is written onto its actor's
transform. There are not two positions to keep in agreement; the renderer
reads what the solver decided.

`offset_x`/`offset_y` are what make a feet-anchored sprite and a centred
body agree. An actor drawn with `origin_y = 1` stands at its feet, so its
body wants `offset_y = -height / 2`:

| | |
|---|---|
| sprite `origin_y = 1.0` | the actor's position is where its feet are |
| body `offset_y = -h/2` | the body is centred on the sprite, not half-buried |

Get this wrong and the character sinks into the floor by half its height —
which looks like a physics bug and is really a units bug.

Almost every walking character also wants `fixed_rotation`: a capsule free
to spin lies down the first time it bumps into anything.

### Collisions

```c
static void OnCollision(SDLStatic_Engine *engine, SDLStatic_ActorId a,
                        SDLStatic_ActorId b, bool began, void *user) {
    if (began && IsBullet(a)) SDLStatic_ActorDestroy(engine, a);
}
SDLStatic_PhysicsSetCollisionCallback(engine, OnCollision, NULL);
```

Callbacks name **actors**, not shapes, and are delivered **after** the step
rather than during it — the solver is mid-flight while it runs, and
destroying a body from inside it corrupts the world. Since actor destruction
is deferred to the end of the frame anyway, `SDLStatic_ActorDestroy` from a
handler is safe, which is the first thing every handler wants to do.

Sensors report through the same callback, with the sensor always first. They
come from a different Box2D event stream than contacts, because a sensor
never produces a contact — the solver has nothing to solve. Folding them in
here is the point: a trigger volume nobody can detect is not a trigger
volume.

### Queries

```c
/* the ground check every platformer needs */
SDLStatic_RayHit down = SDLStatic_PhysicsRaycast(engine, x, y, 0.0f, 12.0f, CAT_GROUND);
bool grounded = down.hit;

SDLStatic_ActorId nearby[32];
int n = SDLStatic_PhysicsOverlap(engine, blast_area, CAT_ENEMY, nearby, 32);
```

Both are in design units and return actor ids. Overlap writes one entry per
actor rather than per shape, so a body with several shapes does not fill the
caller's array with itself.

### Filtering

`category` says what a body **is**; `collides_with` says what it **hits**.
Zero means everything, which is what a game wants until it does not — a
one-way platform, a ghost that walks through walls, a bullet that ignores
the player who fired it.

## Assets

Assets come out of the mounted media archive, so a path means the same file
whether the game is running against a directory, a zip, or bytes compiled
into the binary. `<SDLStatic/engine_assets.h>`.

```c
SDLStatic_TextureId hero = SDLStatic_LoadTexture(engine, "sprites/hero.png");
sprite.texture = SDLStatic_Texture(engine, hero);
```

### Two ways in, because games need both

**`SDLStatic_LoadTexture` blocks** until the asset is there. That is what you
want in a `load` hook or anywhere the next line genuinely cannot proceed
without the thing.

**`SDLStatic_LoadTextureAsync` returns immediately** and loads on a worker.
That is what you want for a loading screen with a progress bar, or an open
world streaming in what the player is walking towards.

```c
SDLStatic_TextureId id = SDLStatic_LoadTextureAsync(engine, "level/tiles.png");
/* ... later, in the loading scene ... */
DrawProgressBar(SDLStatic_AssetsProgress(engine));
if (SDLStatic_AssetsReady(engine)) StartLevel();
```

Both return the same kind of handle and **share one cache**, so a path
already loaded synchronously is instant when asked for asynchronously and
the other way round.

### The cache is by path, and counted

Asking twice gives the same handle and loads once. That matters more than it
sounds: forty actors of the same type asking for the same sprite is the
normal case, not an edge case. Handles are reference counted —
`SDLStatic_AssetRetain` for a second owner, `SDLStatic_AssetRelease` when
done — and the last release frees the texture, so a level that releases what
it loaded gets its memory back without the engine guessing when.

### Nothing returns NULL

`SDLStatic_Texture` on a handle that is still loading, or that failed,
returns the **placeholder**: magenta and black checks, chosen because they
are impossible to mistake for art and impossible to miss in a screenshot.

So a game may draw without checking, a missing file costs a wrong-looking
sprite rather than a crash, and the wrongness is loud. `AssetStatusOf`
reports `FAILED` for anyone who wants to know.

### Why the main thread still does some work

Decoding a PNG is pure computation and happens on a worker. Creating an
`SDL_Texture` is not — it touches the renderer, and SDL's renderer belongs
to the thread that made it:

```
worker:  read from the VFS, decode  ->  SDL_Surface
main:    SDL_CreateTextureFromSurface  ->  SDL_Texture
```

The main-thread half is **time-sliced**: at most `AssetsSetFrameBudget`
milliseconds per frame (2 ms by default), then it stops until next frame.
Without that, forty textures finishing together upload forty textures in one
frame and the game hitches at exactly the moment a loading bar is meant to
be reassuring somebody. Godot and Unity time-slice the same step for the
same reason.

Raise the budget on a loading screen, where finishing sooner is the whole
point and there is nothing else to spend the frame on; leave it low during
gameplay, where a hitch is worse than a late texture.

### Two sharp edges this cost

Both were found by writing the tests, and both are the kind that only show
up on somebody else's machine:

**PhysFS crashes rather than failing** when it has not been initialised — it
dereferences its internal mutex without checking. A game that loads a
texture before mounting an archive, or that sets `no_auto_mount`, is an
ordinary case rather than a misuse, so the loader checks `PHYSFS_isInit()`
before asking the VFS and falls back to the real filesystem.

**A slot released while still queued** left the worker duplicating a freed
path. A level torn down while it is still loading is not exotic — it is what
happens when a player quits during a loading screen — so the worker
re-checks the slot is live after dequeuing it.

## Lighting

The lighting module knows how to light a scene. What it cannot know is
where the camera is, which actors are carrying lights, or what the player
set the quality slider to — so the engine supplies those.
`<SDLStatic/engine_light.h>`.

```c
SDLStatic_LightSetPreset(engine, SDLSTATIC_LIGHT_NIGHT);

SDLStatic_LightDef torch = SDLStatic_LightDefault();
torch.radius = 380.0f;
torch.color = (SDL_FColor){1.0f, 0.72f, 0.36f, 1.0f};
torch.flicker = 0.15f;
SDLStatic_ActorAddLight(actor, &torch);

/* in the render hook, after the world and before the HUD */
SDLStatic_RenderWorld(engine, &camera, alpha);
SDLStatic_LightRender(engine, &camera, alpha);
SDLStatic_RenderOverlay(engine, alpha);
```

Order matters: lighting multiplies over what is already drawn, so anything
drawn afterwards is unlit — which is what a HUD wants and what the world
does not.

### Presets and the clock

| | |
|---|---|
| `NONE` | no lighting; the world draws at full brightness, and costs nothing |
| `SUNRISE` / `AFTERNOON` / `SUNSET` / `NIGHT` | points on the day/night curve |
| `DARK` | a cave: near-black at any hour, but *not* absolute black — a player with no torch should be able to tell the game from a crash |

A preset also sets the hour, so a game that later starts the clock carries
on from a time that matches what is on screen.

```c
SDLStatic_LightSetClock(engine, 6.0f, 0.05f);   /* dawn, a 20-minute day */
if (SDLStatic_LightSunlight(engine) < 0.2f) LightTheStreetlamps();
```

Setting a custom ambient stops the clock driving it. A game that has said
what colour it wants should not have it quietly overwritten a frame later.

### Lights ride on actors

A light attached to an actor follows it — through parents, through physics,
for the actor's whole life — and disappears when the actor does. There is
nothing to keep in sync, which is the entire reason it lives there rather
than being submitted by hand.

It is submitted at `SDLStatic_ActorRenderTransform`, the same place the
sprite is drawn. At the simulation position instead, a torch would lag its
own flame by up to a tick: a shimmer that is maddening to look at and very
hard to attribute to its cause.

The offset rides the actor's rotation, so a torch at the end of an arm
sweeps the room as the character turns.

### The quality budget is applied for you

`dynamic_lights` and `shadows` decide the light-map resolution, the ray
count, the softness, and how many lights are submitted at all. A player who
turns lighting off gets ambient only, at no cost, without the game writing a
single conditional.

When the budget runs out the engine **stops** rather than thinning: a light
that flickers in and out as the count drifts across the limit is far more
distracting than one that is consistently absent. `SDLStatic_LightCount`
reports what actually went in, which is how you notice a budget silently
dropping half the scene.

### Walls

```c
SDLStatic_LightAddOccluder(engine, wall_rect);
```

Occluders and dark zones are buffered and consumed by the next
`LightRender`, so they can be submitted anywhere in the frame. An API where
`AddOccluder` only works inside an invisible window is one that fails
silently when somebody calls it in the wrong place.

**Static physics bodies are submitted automatically**, because a level's
collision is usually exactly what should block light — off with
`SDLStatic_LightSetAutoOccluders` for a game that disagrees. Only bodies
near the camera go in: an occluder off screen cannot cast a shadow onto it,
and the mask has a finite resolution to spend.

## Saves

The engine provides the primitives, not the data model. It knows how to put
bytes somewhere safe and hand them back; it never learns what a save
contains. `<SDLStatic/engine_save.h>`.

```c
SDLStatic_SaveSetIdentity(engine, "acme", "mygame");
SDLStatic_SaveWrite(engine, 1, &state, sizeof(state), "Cave of Ordeals");

size_t size = 0;
void *data = SDLStatic_SaveRead(engine, 1, &size);
if (data != NULL && size == sizeof(state)) SDL_memcpy(&state, data, size);
SDL_free(data);
```

A save format is the most game-specific thing a game has, so one imposed
here would be wrong for every game in a different way.

### Writes are atomic, and that is the whole point

A save goes to a temporary file, is closed, and is then **renamed** over the
target. Rename is atomic everywhere this runs, so the previous save survives
intact until the new one is complete on disk.

The obvious implementation — open the save file and write into it — destroys
the player's progress if the game crashes, the battery dies, or the disk
fills up halfway through. It fails rarely and takes something irreplaceable
when it does, which is the worst possible combination, and it is the one
piece of this that is genuinely worth an engine owning.

### Slots carry a label

`SDLStatic_SaveInfoOf` returns existence, size, modification time and a
label without reading the payload — so a load menu can draw its rows without
parsing saves it may not even be able to interpret, such as an older
version's. Saves from a newer build are refused rather than misread.

## Localisation

```c
SDLStatic_TextLoadFile(engine, "fr");          /* lang/fr.toml from the archive */
SDLStatic_TextSetLanguage(engine, "fr");

DrawText(SDLStatic_Text(engine, "menu.start"));
DrawText(SDLStatic_TextFormat(engine, "hud.score", score));
```

```toml
# media/lang/fr.toml
[strings]
"menu.start" = "Commencer"
"hud.score" = "%d points"
```

### The fallback chain

Current language → **English** → **the key itself**. Each step earns its
place:

- A translation in progress has gaps *by definition* — translators work from
  partial files. An English button beats a blank one, because a blank is
  indistinguishable from a bug.
- A key with no entry anywhere renders as `menu.start`. That is ugly on
  purpose: obvious in a screenshot, and it names the thing that needs
  fixing.

`SDLStatic_TextHas` reports whether a real translation exists, for a
coverage tool — not for gameplay, which should just draw the string.

### Keys, not English text, are the identifiers

Keying off the English string means every typo fix in English silently
breaks every translation. Keys cost a little readability at the call site
and buy the freedom to edit English at all.

### Formatting is the translator's

The looked-up string *is* the format, so `"Score: %d"` and `"%d points"` are
both expressible. Word order differs between languages, and a translation
that cannot move its own placeholders is not really a translation.

`SDLStatic_TextFormat` returns one of a small rotating set of buffers, so
several calls can appear in one expression without the second clobbering the
first.
