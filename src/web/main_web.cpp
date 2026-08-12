/**
 * @file main_web.cpp
 * @brief HTML5 canvas demo: a minimal Emscripten game loop.
 *
 * Structure to keep as the game grows: per-frame state updates driven by a
 * real delta time, rendering separated from simulation, and the browser in
 * control of frame pacing via emscripten_set_main_loop (requestAnimationFrame).
 * Replace the EM_JS canvas-2D renderer with WebGL2/SDL2 calls as needed.
 */

#include <SDL3_static_extensions/version.hpp>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <string>

// Renders one frame through the canvas 2D context. EM_JS defines the function
// once in JavaScript; calls from C++ are ordinary function calls.
// clang-format off
// The EM_JS body is JavaScript: clang-format must not touch it (it splits
// JS operators like !== into invalid `!= =`).
EM_JS(void, SDL3_static_extensions_draw_frame, (double x, double y, double size, const char *hud), {
    const canvas = document.getElementById('canvas');
    const dpr = window.devicePixelRatio || 1;
    const width = canvas.clientWidth * dpr;
    const height = canvas.clientHeight * dpr;
    if (canvas.width !== width || canvas.height !== height) {
        canvas.width = width;
        canvas.height = height;
    }
    const g = canvas.getContext('2d');
    g.fillStyle = '#101418';
    g.fillRect(0, 0, canvas.width, canvas.height);
    g.fillStyle = '#4fc3f7';
    g.fillRect(x * canvas.width, y * canvas.height, size * dpr, size * dpr);
    g.fillStyle = '#e0e0e0';
    // Note: no JS template literals here — clang tokenizes the EM_JS body and
    // rejects '$' under -Werror (-Wdollar-in-identifier-extension).
    g.font = (14 * dpr) + 'px monospace';
    g.fillText(UTF8ToString(hud), 12 * dpr, 24 * dpr);
});
// clang-format on

namespace
{

struct GameState
{
    double x = 0.1;
    double y = 0.1;
    double vx = 0.25; // canvas-widths per second
    double vy = 0.2;  // canvas-heights per second
    double last_ms = 0.0;
    double frames = 0.0;
    std::string hud;
};

GameState g_state;

void Update(GameState &state, double dt)
{
    state.x += state.vx * dt;
    state.y += state.vy * dt;
    if (state.x < 0.0 || state.x > 0.95)
    {
        state.vx = -state.vx;
    }
    if (state.y < 0.0 || state.y > 0.95)
    {
        state.vy = -state.vy;
    }
    state.frames += 1.0;
}

void Frame()
{
    const double now_ms = emscripten_get_now();
    double dt = (now_ms - g_state.last_ms) / 1000.0;
    if (g_state.last_ms == 0.0 || dt > 0.1)
    {
        dt = 1.0 / 60.0; // first frame / tab was backgrounded
    }
    g_state.last_ms = now_ms;

    Update(g_state, dt);

    g_state.hud = std::string("SDL3-static-extensions ") +
                  std::string(SDL3_static_extensions::Version()) + " — wasm game loop, frame " +
                  std::to_string(static_cast<long>(g_state.frames));
    SDL3_static_extensions_draw_frame(g_state.x, g_state.y, 48.0, g_state.hud.c_str());
}

} // namespace

int main()
{
    // 0 fps == drive the loop with requestAnimationFrame (the right default
    // for games); the final `true` hands control to the browser.
    emscripten_set_main_loop(Frame, 0, true);
    return 0;
}
