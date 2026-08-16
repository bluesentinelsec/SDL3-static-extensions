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

## The drawing surface

The game draws in **design coordinates**, not pixels. The engine sets a
logical presentation size — 3840×2160 by default — and SDL scales it to
whatever the display is, letterboxed:

```c
SDLStatic_EngineConfig config = {0};
config.design_width = 3840;   /* write the game once, at one size */
config.design_height = 2160;
config.presentation = SDLSTATIC_PRESENT_LETTERBOX;
```

A sprite at (1920, 1080) is centred on a 4K monitor, a 1080p laptop and a
phone. `SDLSTATIC_PRESENT_INTEGER` is there for pixel art, which wants
whole-number scaling or it shimmers; `SDLSTATIC_PRESENT_NATIVE` turns the
whole thing off and gives you pixels.

Because SDL owns the letterbox, mouse and touch positions arrive in *window*
coordinates and must be converted:

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
