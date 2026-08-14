/**
 * @file gui_test.cpp
 * @brief Tests for SDLStatic::GUI — vendored Nuklear + SDL3 backend + grid.
 *
 * Runs fully headless on a software renderer: frames are driven manually,
 * input is injected as fabricated SDL events, rendering is verified by
 * pixel readback, and layout geometry is captured via nk_widget_bounds —
 * so widget behavior, the backend, and the no-hard-coded-coordinates
 * property of the grid helper are all proven for real.
 */

#include <SDL3/SDL.h>
#include <SDLStatic/gui.h>
#include <SDLStatic/gui_grid.h>
#include <gtest/gtest.h>

#include <cstring>
#include <string>
#include <vector>

namespace
{

constexpr int kScreen = 400;

class GuiHarness : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
        surface_ = SDL_CreateSurface(kScreen, kScreen, SDL_PIXELFORMAT_ARGB8888);
        ASSERT_NE(surface_, nullptr);
        renderer_ = SDL_CreateSoftwareRenderer(surface_);
        ASSERT_NE(renderer_, nullptr) << SDL_GetError();
        gui_ = SDLStatic_CreateGui(renderer_, nullptr, 0, 0.0f);
        ASSERT_NE(gui_, nullptr) << SDL_GetError();
    }
    void TearDown() override
    {
        SDLStatic_DestroyGui(gui_);
        SDL_DestroyRenderer(renderer_);
        SDL_DestroySurface(surface_);
        SDL_Quit();
    }

    void BeginFrame()
    {
        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
        SDL_RenderClear(renderer_);
    }

    void FeedMouseMove(float x, float y)
    {
        SDL_Event event = {};
        event.type = SDL_EVENT_MOUSE_MOTION;
        event.motion.x = x;
        event.motion.y = y;
        EXPECT_TRUE(SDLStatic_GuiProcessEvent(gui_, &event));
    }

    void FeedButton(float x, float y, bool down)
    {
        SDL_Event event = {};
        event.type = down ? SDL_EVENT_MOUSE_BUTTON_DOWN : SDL_EVENT_MOUSE_BUTTON_UP;
        event.button.button = SDL_BUTTON_LEFT;
        event.button.clicks = 1;
        event.button.x = x;
        event.button.y = y;
        EXPECT_TRUE(SDLStatic_GuiProcessEvent(gui_, &event));
    }

    bool Lit(int x, int y)
    {
        SDL_FlushRenderer(renderer_);
        Uint8 r = 0;
        Uint8 g = 0;
        Uint8 b = 0;
        Uint8 a = 0;
        SDL_ReadSurfacePixel(surface_, x, y, &r, &g, &b, &a);
        return (r | g | b) != 0;
    }

    SDL_Surface *surface_ = nullptr;
    SDL_Renderer *renderer_ = nullptr;
    SDLStatic_Gui *gui_ = nullptr;
};

TEST_F(GuiHarness, CreateRejectsNullRenderer)
{
    EXPECT_EQ(SDLStatic_CreateGui(nullptr, nullptr, 0, 0.0f), nullptr);
    EXPECT_NE(SDLStatic_GuiContext(gui_), nullptr);
    SDLStatic_DestroyGui(nullptr); // safe no-op
}

TEST_F(GuiHarness, WindowRendersPixelsInsideAndNotOutside)
{
    BeginFrame();
    SDLStatic_GuiInputBegin(gui_);
    SDLStatic_GuiInputEnd(gui_);
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);
    if (nk_begin(ctx, "panel", nk_rect(20, 20, 200, 150), NK_WINDOW_BORDER | NK_WINDOW_TITLE))
    {
        nk_layout_row_dynamic(ctx, 0, 1);
        nk_label(ctx, "Hello SDLStatic", NK_TEXT_LEFT);
        nk_button_label(ctx, "A Button");
    }
    nk_end(ctx);
    ASSERT_TRUE(SDLStatic_GuiRender(gui_)) << SDL_GetError();

    EXPECT_TRUE(Lit(120, 90)) << "window interior";
    EXPECT_TRUE(Lit(30, 30)) << "title bar";
    EXPECT_FALSE(Lit(350, 350)) << "outside the window";
}

TEST_F(GuiHarness, ButtonClickReportsPressed)
{
    struct nk_rect button_bounds = nk_rect(0, 0, 0, 0);
    bool clicked = false;

    // Frame 1: no input; capture where the button lands.
    BeginFrame();
    SDLStatic_GuiInputBegin(gui_);
    SDLStatic_GuiInputEnd(gui_);
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);
    if (nk_begin(ctx, "win", nk_rect(10, 10, 220, 160), NK_WINDOW_NO_SCROLLBAR))
    {
        nk_layout_row_dynamic(ctx, 30, 1);
        button_bounds = nk_widget_bounds(ctx);
        nk_button_label(ctx, "Fire");
    }
    nk_end(ctx);
    ASSERT_TRUE(SDLStatic_GuiRender(gui_));
    ASSERT_GT(button_bounds.w, 0.0f);

    // Frame 2: press on the button; frame 3: release -> click fires.
    const float cx = button_bounds.x + button_bounds.w / 2.0f;
    const float cy = button_bounds.y + button_bounds.h / 2.0f;
    for (int phase = 0; phase < 2; ++phase)
    {
        BeginFrame();
        SDLStatic_GuiInputBegin(gui_);
        if (phase == 0)
        {
            FeedMouseMove(cx, cy);
            FeedButton(cx, cy, true);
        }
        else
        {
            FeedButton(cx, cy, false);
        }
        SDLStatic_GuiInputEnd(gui_);
        if (nk_begin(ctx, "win", nk_rect(10, 10, 220, 160), NK_WINDOW_NO_SCROLLBAR))
        {
            nk_layout_row_dynamic(ctx, 30, 1);
            if (nk_button_label(ctx, "Fire"))
            {
                clicked = true;
            }
        }
        nk_end(ctx);
        ASSERT_TRUE(SDLStatic_GuiRender(gui_));
    }
    EXPECT_TRUE(clicked) << "press+release at the button's bounds must register";
    EXPECT_TRUE(SDLStatic_GuiWantsInput(gui_)) << "pointer is over the UI";
}

TEST_F(GuiHarness, CheckboxTogglesAndSliderMoves)
{
    struct nk_rect check_bounds = nk_rect(0, 0, 0, 0);
    struct nk_rect slider_bounds = nk_rect(0, 0, 0, 0);
    nk_bool checked = nk_false;
    float value = 0.0f;
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);

    auto frame = [&](bool capture) {
        BeginFrame();
        if (nk_begin(ctx, "form", nk_rect(10, 10, 300, 200), NK_WINDOW_NO_SCROLLBAR))
        {
            nk_layout_row_dynamic(ctx, 30, 1);
            if (capture)
            {
                check_bounds = nk_widget_bounds(ctx);
            }
            nk_checkbox_label(ctx, "enabled", &checked);
            if (capture)
            {
                slider_bounds = nk_widget_bounds(ctx);
            }
            nk_slider_float(ctx, 0.0f, &value, 1.0f, 0.01f);
        }
        nk_end(ctx);
        ASSERT_TRUE(SDLStatic_GuiRender(gui_));
    };

    SDLStatic_GuiInputBegin(gui_);
    SDLStatic_GuiInputEnd(gui_);
    frame(true);
    ASSERT_GT(check_bounds.w, 0.0f);

    // Press and release on the checkbox across two frames.
    const float kx = check_bounds.x + 8;
    const float ky = check_bounds.y + check_bounds.h / 2;
    SDLStatic_GuiInputBegin(gui_);
    FeedMouseMove(kx, ky);
    FeedButton(kx, ky, true);
    SDLStatic_GuiInputEnd(gui_);
    frame(false);
    SDLStatic_GuiInputBegin(gui_);
    FeedButton(kx, ky, false);
    SDLStatic_GuiInputEnd(gui_);
    frame(false);
    EXPECT_TRUE(checked) << "checkbox must toggle on";

    // Sliders move by dragging the cursor handle: grab it at the left end
    // (value is 0), drag to 75% while held, then release.
    const float sy = slider_bounds.y + slider_bounds.h / 2.0f;
    const float grab_x = slider_bounds.x + 4.0f; /* cursor sits at the left end */
    const float target_x = slider_bounds.x + slider_bounds.w * 0.75f;
    SDLStatic_GuiInputBegin(gui_);
    FeedMouseMove(grab_x, sy);
    FeedButton(grab_x, sy, true);
    SDLStatic_GuiInputEnd(gui_);
    frame(false);
    SDLStatic_GuiInputBegin(gui_);
    FeedMouseMove(target_x, sy);
    SDLStatic_GuiInputEnd(gui_);
    frame(false);
    SDLStatic_GuiInputBegin(gui_);
    FeedButton(target_x, sy, false);
    SDLStatic_GuiInputEnd(gui_);
    frame(false);
    EXPECT_NEAR(value, 0.75f, 0.15f) << "drag should land near the target fraction";
}

TEST_F(GuiHarness, EditFieldReceivesTypedText)
{
    char buffer[64] = {};
    struct nk_rect edit_bounds = nk_rect(0, 0, 0, 0);
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);

    auto frame = [&](bool capture) {
        BeginFrame();
        if (nk_begin(ctx, "editwin", nk_rect(10, 10, 300, 120), NK_WINDOW_NO_SCROLLBAR))
        {
            nk_layout_row_dynamic(ctx, 30, 1);
            if (capture)
            {
                edit_bounds = nk_widget_bounds(ctx);
            }
            nk_edit_string_zero_terminated(ctx, NK_EDIT_FIELD, buffer, sizeof(buffer),
                                           nk_filter_default);
        }
        nk_end(ctx);
        ASSERT_TRUE(SDLStatic_GuiRender(gui_));
    };

    SDLStatic_GuiInputBegin(gui_);
    SDLStatic_GuiInputEnd(gui_);
    frame(true);

    // Press and release inside the field to focus it.
    const float fx = edit_bounds.x + 10;
    const float fy = edit_bounds.y + edit_bounds.h / 2;
    SDLStatic_GuiInputBegin(gui_);
    FeedMouseMove(fx, fy);
    FeedButton(fx, fy, true);
    SDLStatic_GuiInputEnd(gui_);
    frame(false);
    SDLStatic_GuiInputBegin(gui_);
    FeedButton(fx, fy, false);
    SDLStatic_GuiInputEnd(gui_);
    frame(false);

    // Type UTF-8 text ("hé" exercises the decoder).
    SDL_Event text = {};
    text.type = SDL_EVENT_TEXT_INPUT;
    text.text.text = "h\xc3\xa9!";
    SDLStatic_GuiInputBegin(gui_);
    EXPECT_TRUE(SDLStatic_GuiProcessEvent(gui_, &text));
    SDLStatic_GuiInputEnd(gui_);
    frame(false);

    EXPECT_STREQ(buffer, "h\xc3\xa9!") << "typed text must land in the edit buffer";
}

TEST_F(GuiHarness, GridWidthsFollowWeightsAndSpans)
{
    struct nk_rect c1 = nk_rect(0, 0, 0, 0);
    struct nk_rect c2 = nk_rect(0, 0, 0, 0);
    struct nk_rect c3 = nk_rect(0, 0, 0, 0);
    struct nk_rect span_cell = nk_rect(0, 0, 0, 0);
    struct nk_rect next_row = nk_rect(0, 0, 0, 0);
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);
    static const float weights[3] = {1.0f, 2.0f, 1.0f};

    SDLStatic_GuiInputBegin(gui_);
    SDLStatic_GuiInputEnd(gui_);
    BeginFrame();
    if (nk_begin(ctx, "grid", nk_rect(0, 0, 320, 300), NK_WINDOW_NO_SCROLLBAR))
    {
        SDLStatic_GuiGrid grid;
        ASSERT_TRUE(SDLStatic_GuiGridBegin(ctx, &grid, 3, weights, 25.0f));

        SDLStatic_GuiGridCell(&grid);
        c1 = nk_widget_bounds(ctx);
        nk_label(ctx, "a", NK_TEXT_LEFT);
        SDLStatic_GuiGridCell(&grid);
        c2 = nk_widget_bounds(ctx);
        nk_label(ctx, "b", NK_TEXT_LEFT);
        SDLStatic_GuiGridCell(&grid);
        c3 = nk_widget_bounds(ctx);
        nk_label(ctx, "c", NK_TEXT_LEFT);

        // Auto-wrap: this cell must begin row 2. Span 2 columns.
        SDLStatic_GuiGridCellSpan(&grid, 2);
        span_cell = nk_widget_bounds(ctx);
        nk_label(ctx, "wide", NK_TEXT_LEFT);

        SDLStatic_GuiGridNextRow(&grid);
        SDLStatic_GuiGridCell(&grid);
        next_row = nk_widget_bounds(ctx);
        nk_label(ctx, "row3", NK_TEXT_LEFT);

        SDLStatic_GuiGridEnd(&grid);
    }
    nk_end(ctx);
    ASSERT_TRUE(SDLStatic_GuiRender(gui_));
    ASSERT_GT(c1.w, 0.0f) << "grid window must have been built";

    // Weight 1:2:1 must show up as proportional widths (padding tolerance).
    EXPECT_NEAR(c2.w / c1.w, 2.0f, 0.35f) << "middle column has weight 2";
    EXPECT_NEAR(c3.w / c1.w, 1.0f, 0.2f) << "outer columns match";
    // Row 1 cells share a y; row 2 sits below; row 3 below that.
    EXPECT_FLOAT_EQ(c1.y, c2.y);
    EXPECT_FLOAT_EQ(c2.y, c3.y);
    EXPECT_GT(span_cell.y, c1.y);
    EXPECT_GT(next_row.y, span_cell.y);
    // The span covers columns 1+2: wider than c1+c2 alone minus spacing.
    EXPECT_GT(span_cell.w, c1.w + c2.w * 0.8f);
    // Columns line up across rows (same left edge, no hard-coded x).
    EXPECT_NEAR(span_cell.x, c1.x, 2.0f);
    EXPECT_NEAR(next_row.x, c1.x, 2.0f);
}

TEST_F(GuiHarness, GridScalesWithWindowSizeNotPixels)
{
    // The same grid code in two window sizes: widths must scale
    // proportionally — the "no hard-coded coordinates" guarantee.
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);
    static const float weights[2] = {1.0f, 3.0f};
    float first_w = 0.0f;
    float second_w = 0.0f;

    for (int pass = 0; pass < 2; ++pass)
    {
        const float window_w = (pass == 0) ? 200.0f : 380.0f;
        SDLStatic_GuiInputBegin(gui_);
        SDLStatic_GuiInputEnd(gui_);
        BeginFrame();
        char name[16];
        SDL_snprintf(name, sizeof(name), "scale%d", pass);
        if (nk_begin(ctx, name, nk_rect(0, 0, window_w, 100), NK_WINDOW_NO_SCROLLBAR))
        {
            SDLStatic_GuiGrid grid;
            ASSERT_TRUE(SDLStatic_GuiGridBegin(ctx, &grid, 2, weights, 0.0f));
            SDLStatic_GuiGridCell(&grid);
            const struct nk_rect bounds = nk_widget_bounds(ctx);
            nk_label(ctx, "x", NK_TEXT_LEFT);
            SDLStatic_GuiGridCell(&grid);
            nk_label(ctx, "y", NK_TEXT_LEFT);
            SDLStatic_GuiGridEnd(&grid);
            if (pass == 0)
            {
                first_w = bounds.w;
            }
            else
            {
                second_w = bounds.w;
            }
        }
        nk_end(ctx);
        ASSERT_TRUE(SDLStatic_GuiRender(gui_));
    }
    ASSERT_GT(first_w, 0.0f);
    EXPECT_NEAR(second_w / first_w, 380.0f / 200.0f, 0.25f)
        << "cell width must scale with the window";
}

TEST_F(GuiHarness, GridRejectsBadInput)
{
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);
    SDLStatic_GuiGrid grid;
    EXPECT_FALSE(SDLStatic_GuiGridBegin(nullptr, &grid, 2, nullptr, 0.0f));
    EXPECT_FALSE(SDLStatic_GuiGridBegin(ctx, nullptr, 2, nullptr, 0.0f));
    EXPECT_FALSE(SDLStatic_GuiGridBegin(ctx, &grid, 0, nullptr, 0.0f));
    EXPECT_FALSE(SDLStatic_GuiGridBegin(ctx, &grid, SDLSTATIC_GUI_GRID_MAX_COLS + 1, nullptr,
                                        0.0f));
    // Calls on an unopened grid must be safe no-ops.
    SDLStatic_GuiGrid dead = {};
    SDLStatic_GuiGridCell(&dead);
    SDLStatic_GuiGridEnd(&dead);
}

TEST_F(GuiHarness, IgnoresUnrelatedEvents)
{
    SDL_Event event = {};
    event.type = SDL_EVENT_GAMEPAD_BUTTON_DOWN;
    SDLStatic_GuiInputBegin(gui_);
    EXPECT_FALSE(SDLStatic_GuiProcessEvent(gui_, &event));
    EXPECT_FALSE(SDLStatic_GuiProcessEvent(gui_, nullptr));
    SDLStatic_GuiInputEnd(gui_);
}


// SDLStatic_GuiPumpEvents: the one-call input pump. Also the entry point
// that makes the GUI drivable from Lua and Ruby, where SDL_Event (a union)
// cannot cross the script boundary.
TEST_F(GuiHarness, PumpEventsDrainsQueueAndReportsQuit)
{
    // The pump reads the SDL event queue, which needs the events subsystem
    // (the rest of this harness runs with SDL_Init(0)).
    ASSERT_TRUE(SDL_InitSubSystem(SDL_INIT_EVENTS)) << SDL_GetError();

    // A pushed quit request must be reported (and consumed).
    SDL_Event quit;
    SDL_zero(quit);
    quit.type = SDL_EVENT_QUIT;
    ASSERT_TRUE(SDL_PushEvent(&quit));
    EXPECT_FALSE(SDLStatic_GuiPumpEvents(gui_)) << "quit must stop the loop";

    // With an empty queue it keeps running and leaves the GUI usable.
    EXPECT_TRUE(SDLStatic_GuiPumpEvents(gui_));
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);
    ASSERT_NE(ctx, nullptr);
    if (nk_begin(ctx, "pump", nk_rect(0, 0, 100, 60), NK_WINDOW_BORDER))
    {
        nk_layout_row_dynamic(ctx, 0, 1);
        nk_label(ctx, "ok", NK_TEXT_LEFT);
    }
    nk_end(ctx);
    EXPECT_TRUE(SDLStatic_GuiRender(gui_));

    // Mouse motion routed through the pump reaches Nuklear's input state.
    SDL_Event motion;
    SDL_zero(motion);
    motion.type = SDL_EVENT_MOUSE_MOTION;
    motion.motion.x = 42.0f;
    motion.motion.y = 24.0f;
    ASSERT_TRUE(SDL_PushEvent(&motion));
    EXPECT_TRUE(SDLStatic_GuiPumpEvents(gui_));
    EXPECT_EQ(ctx->input.mouse.pos.x, 42.0f);
    EXPECT_EQ(ctx->input.mouse.pos.y, 24.0f);

    EXPECT_FALSE(SDLStatic_GuiPumpEvents(nullptr)) << "null gui fails cleanly";

    SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

} // namespace
