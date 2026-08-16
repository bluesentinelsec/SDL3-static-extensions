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

This page covers the first subsystem: the loop, time, and the drawing
surface. Scenes, actors, rendering, input, assets, physics and lighting
follow.

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

A **camera** maps world → design; the engine maps design → pixels. The
engine currently has no camera, so a game that draws directly in design
coordinates is effectively saying "the world is exactly one screen" — fine
for menus, not for a level. The camera arrives with the rendering
subsystem; when it does, nothing on this page changes.

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
