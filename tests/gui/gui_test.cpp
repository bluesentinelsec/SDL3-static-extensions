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

// Key queries: what lets scripts implement "Escape quits" (SDL's keyboard
// state API cannot cross the binding boundary).
TEST_F(GuiHarness, KeyPressedReportsThisFramesKeys)
{
    ASSERT_TRUE(SDL_InitSubSystem(SDL_INIT_EVENTS)) << SDL_GetError();

    SDL_Event key;
    SDL_zero(key);
    key.type = SDL_EVENT_KEY_DOWN;
    key.key.scancode = SDL_SCANCODE_ESCAPE;
    ASSERT_TRUE(SDL_PushEvent(&key));
    EXPECT_TRUE(SDLStatic_GuiPumpEvents(gui_));
    EXPECT_TRUE(SDLStatic_GuiKeyPressed(gui_, SDL_SCANCODE_ESCAPE));
    EXPECT_FALSE(SDLStatic_GuiKeyPressed(gui_, SDL_SCANCODE_A)) << "only keys seen";

    // The set is per-frame: a pump with no keys clears it.
    EXPECT_TRUE(SDLStatic_GuiPumpEvents(gui_));
    EXPECT_FALSE(SDLStatic_GuiKeyPressed(gui_, SDL_SCANCODE_ESCAPE));

    // Out-of-range and null are safe.
    EXPECT_FALSE(SDLStatic_GuiKeyPressed(gui_, -1));
    EXPECT_FALSE(SDLStatic_GuiKeyPressed(gui_, 999999));
    EXPECT_FALSE(SDLStatic_GuiKeyPressed(nullptr, SDL_SCANCODE_ESCAPE));

    SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

// Theming: Nuklear's own style stack takes union-typed items, so this is
// the entry point Lua and Ruby can reach.
TEST_F(GuiHarness, StyleColorPushPopRestoresTheme)
{
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);
    const struct nk_color before = ctx->style.window.fixed_background.data.color;
    const struct nk_color text_before = ctx->style.text.color;

    ASSERT_TRUE(SDLStatic_GuiPushStyleColor(
        gui_, SDLSTATIC_GUI_COLOR_WINDOW_BACKGROUND, SDL_Color{10, 20, 30, 255}));
    ASSERT_TRUE(SDLStatic_GuiPushStyleColor(gui_, SDLSTATIC_GUI_COLOR_TEXT,
                                            SDL_Color{1, 2, 3, 255}));
    EXPECT_EQ(ctx->style.window.fixed_background.data.color.r, 10);
    EXPECT_EQ(ctx->style.text.color.g, 2) << "plain-colour stack too";

    // Pops unwind both stacks in LIFO order, whichever kind each push used.
    SDLStatic_GuiPopStyleColor(gui_, 2);
    EXPECT_EQ(ctx->style.window.fixed_background.data.color.r, before.r);
    EXPECT_EQ(ctx->style.text.color.g, text_before.g);

    // Over-popping and null are safe no-ops.
    SDLStatic_GuiPopStyleColor(gui_, 5);
    SDLStatic_GuiPopStyleColor(nullptr, 1);
    EXPECT_FALSE(SDLStatic_GuiPushStyleColor(nullptr, SDLSTATIC_GUI_COLOR_BUTTON,
                                             SDL_Color{0, 0, 0, 255}));
}

// Runtime font sizing: Nuklear cannot add glyphs after the atlas is baked,
// so the sizes are baked up front and selected here.
TEST_F(GuiHarness, FontSizesAreSelectableAtRuntime)
{
    const float normal = SDLStatic_GuiFontHeight(gui_);
    EXPECT_GT(normal, 0.0f);

    ASSERT_TRUE(SDLStatic_GuiSetFont(gui_, SDLSTATIC_GUI_FONT_LARGE));
    const float large = SDLStatic_GuiFontHeight(gui_);
    EXPECT_GT(large, normal);

    ASSERT_TRUE(SDLStatic_GuiSetFont(gui_, SDLSTATIC_GUI_FONT_SMALL));
    EXPECT_LT(SDLStatic_GuiFontHeight(gui_), normal);

    ASSERT_TRUE(SDLStatic_GuiSetFont(gui_, SDLSTATIC_GUI_FONT_NORMAL));
    EXPECT_FLOAT_EQ(SDLStatic_GuiFontHeight(gui_), normal);

    // Scoped push/pop restores the previous font.
    ASSERT_TRUE(SDLStatic_GuiPushFont(gui_, SDLSTATIC_GUI_FONT_LARGE));
    EXPECT_FLOAT_EQ(SDLStatic_GuiFontHeight(gui_), large);
    SDLStatic_GuiPopFont(gui_, 1);
    EXPECT_FLOAT_EQ(SDLStatic_GuiFontHeight(gui_), normal);

    // Text actually measures wider with a bigger font (glyphs really differ).
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);
    const char *sample = "Button 1 was clicked.";
    const int len = static_cast<int>(SDL_strlen(sample));
    const float w_normal = ctx->style.font->width(ctx->style.font->userdata,
                                                  ctx->style.font->height, sample, len);
    ASSERT_TRUE(SDLStatic_GuiSetFont(gui_, SDLSTATIC_GUI_FONT_LARGE));
    const float w_large = ctx->style.font->width(ctx->style.font->userdata,
                                                 ctx->style.font->height, sample, len);
    EXPECT_GT(w_large, w_normal);
    ASSERT_TRUE(SDLStatic_GuiSetFont(gui_, SDLSTATIC_GUI_FONT_NORMAL));

    // Bad input and over-pop are safe.
    EXPECT_FALSE(SDLStatic_GuiSetFont(gui_, static_cast<SDLStatic_GuiFontSize>(99)));
    EXPECT_FALSE(SDLStatic_GuiSetFont(nullptr, SDLSTATIC_GUI_FONT_NORMAL));
    EXPECT_FALSE(SDLStatic_GuiPushFont(nullptr, SDLSTATIC_GUI_FONT_LARGE));
    SDLStatic_GuiPopFont(gui_, 5);
    SDLStatic_GuiPopFont(nullptr, 1);
    EXPECT_FLOAT_EQ(SDLStatic_GuiFontHeight(gui_), normal);
    EXPECT_FLOAT_EQ(SDLStatic_GuiFontHeight(nullptr), 0.0f);
}

// nk_labelf float formatting. Nuklear's built-in printf (used because
// NK_INCLUDE_STANDARD_IO is off) emitted only the first character for a
// precision of 0: "%.0f" of 40.0 rendered as "4". Compared black-box by
// rendering the formatted text beside the literal it must equal.
TEST_F(GuiHarness, LabelfFormatsFloatsCorrectly)
{
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);

    auto render_text = [&](bool formatted, double value, const char *literal) {
        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
        SDL_RenderClear(renderer_);
        SDLStatic_GuiInputBegin(gui_);
        SDLStatic_GuiInputEnd(gui_);
        if (nk_begin(ctx, "fmt", nk_rect(0, 0, kScreen, kScreen), 0))
        {
            nk_layout_row_dynamic(ctx, 30, 1);
            if (formatted)
            {
                nk_labelf(ctx, NK_TEXT_LEFT, "%.0f", value);
            }
            else
            {
                nk_label(ctx, literal, NK_TEXT_LEFT);
            }
        }
        nk_end(ctx);
        SDLStatic_GuiRender(gui_);
        SDL_FlushRenderer(renderer_);
        int lit = 0;
        for (int y = 0; y < kScreen; y++)
        {
            for (int x = 0; x < kScreen; x++)
            {
                Uint8 r = 0, g = 0, b = 0, a = 0;
                SDL_ReadSurfacePixel(surface_, x, y, &r, &g, &b, &a);
                if (r > 40 || g > 40 || b > 40)
                {
                    lit++;
                }
            }
        }
        return lit;
    };

    // "%.0f" of 40.0 must paint exactly what "40" paints.
    EXPECT_EQ(render_text(true, 40.0, nullptr), render_text(false, 0, "40"));
    // Rounds like printf rather than truncating.
    EXPECT_EQ(render_text(true, 2.7, nullptr), render_text(false, 0, "3"));
    // Precision beyond zero still works.
    EXPECT_GT(render_text(true, 1.5, nullptr), 0);
}

// Image widget: Nuklear's nk_image takes a union-handle struct that cannot
// cross a script boundary, so the library takes an SDL_Texture directly and
// applies the PictureBox-style sizing modes itself.
TEST_F(GuiHarness, ImageWidgetHonoursSizingModes)
{
    // A 40x20 texture (2:1) drawn into a square slot: Stretch fills it,
    // Zoom leaves letterbox bars, Fill covers it.
    SDL_Surface *pixels = SDL_CreateSurface(40, 20, SDL_PIXELFORMAT_RGBA32);
    ASSERT_NE(pixels, nullptr);
    SDL_FillSurfaceRect(pixels, nullptr, SDL_MapSurfaceRGBA(pixels, 255, 0, 0, 255));
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer_, pixels);
    ASSERT_NE(texture, nullptr) << SDL_GetError();
    SDL_DestroySurface(pixels);

    auto painted = [&](SDLStatic_GuiImageMode mode) {
        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
        SDL_RenderClear(renderer_);
        SDLStatic_GuiInputBegin(gui_);
        SDLStatic_GuiInputEnd(gui_);
        struct nk_context *ctx = SDLStatic_GuiContext(gui_);
        if (nk_begin(ctx, "img", nk_rect(0, 0, kScreen, kScreen), 0))
        {
            nk_layout_row_static(ctx, 100, 100, 1);  // square 100x100 slot
            EXPECT_TRUE(SDLStatic_GuiImage(gui_, texture, mode));
        }
        nk_end(ctx);
        SDLStatic_GuiRender(gui_);
        SDL_FlushRenderer(renderer_);
        int red = 0;
        for (int y = 0; y < kScreen; y++)
        {
            for (int x = 0; x < kScreen; x++)
            {
                Uint8 r = 0, g = 0, b = 0, a = 0;
                SDL_ReadSurfacePixel(surface_, x, y, &r, &g, &b, &a);
                if (r > 150 && g < 100)
                {
                    red++;
                }
            }
        }
        return red;
    };

    const int stretch = painted(SDLSTATIC_GUI_IMAGE_STRETCH);
    const int zoom = painted(SDLSTATIC_GUI_IMAGE_ZOOM);
    const int fill = painted(SDLSTATIC_GUI_IMAGE_FILL);
    const int center = painted(SDLSTATIC_GUI_IMAGE_CENTER);

    EXPECT_GT(stretch, 0) << "stretch must paint the whole slot";
    // 2:1 source zoomed into a square slot covers about half of it.
    EXPECT_LT(zoom, stretch);
    EXPECT_NEAR(static_cast<double>(zoom) / stretch, 0.5, 0.15);
    // Fill covers the slot but is clipped to it, so it matches stretch's area.
    EXPECT_NEAR(static_cast<double>(fill) / stretch, 1.0, 0.15);
    // Native 40x20 centred is much smaller than the 100x100 slot.
    EXPECT_LT(center, zoom);

    EXPECT_FALSE(SDLStatic_GuiImage(nullptr, texture, SDLSTATIC_GUI_IMAGE_ZOOM));
    EXPECT_FALSE(SDLStatic_GuiImage(gui_, nullptr, SDLSTATIC_GUI_IMAGE_ZOOM));
    SDL_DestroyTexture(texture);
}

// The gui-owned grid: same layout as the caller-owned helper, but reachable
// from scripts (which cannot hold a struct or pass a float array).
TEST_F(GuiHarness, OwnedGridMatchesCallerOwnedGrid)
{
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);

    auto widths = [&](bool owned) {
        std::vector<float> out;
        SDLStatic_GuiInputBegin(gui_);
        SDLStatic_GuiInputEnd(gui_);
        if (nk_begin(ctx, "grid", nk_rect(0, 0, 300, 200), 0))
        {
            static const float weights[] = {1.0f, 2.0f, 1.0f};
            SDLStatic_GuiGrid caller_grid;
            if (owned)
            {
                SDLStatic_GuiGridWeight(gui_, 0, 1.0f);
                SDLStatic_GuiGridWeight(gui_, 1, 2.0f);
                SDLStatic_GuiGridWeight(gui_, 2, 1.0f);
                SDLStatic_GuiGridBeginOwned(gui_, 3, 24.0f);
            }
            else
            {
                SDLStatic_GuiGridBegin(ctx, &caller_grid, 3, weights, 24.0f);
            }
            for (int i = 0; i < 3; i++)
            {
                if (owned)
                {
                    SDLStatic_GuiGridCellOwned(gui_);
                }
                else
                {
                    SDLStatic_GuiGridCell(&caller_grid);
                }
                struct nk_rect bounds = nk_widget_bounds(ctx);
                out.push_back(bounds.w);
                nk_label(ctx, "x", NK_TEXT_LEFT);
            }
            if (owned)
            {
                SDLStatic_GuiGridEndOwned(gui_);
            }
            else
            {
                SDLStatic_GuiGridEnd(&caller_grid);
            }
        }
        nk_end(ctx);
        SDLStatic_GuiRender(gui_);  // ends the frame (nk_clear)
        return out;
    };

    const std::vector<float> caller = widths(false);
    const std::vector<float> owned = widths(true);
    ASSERT_EQ(caller.size(), 3u);
    ASSERT_EQ(owned.size(), 3u);
    for (size_t i = 0; i < caller.size(); i++)
    {
        EXPECT_NEAR(owned[i], caller[i], 0.5f) << "column " << i;
    }
    // The middle column carries weight 2, so it is about twice as wide.
    EXPECT_NEAR(owned[1] / owned[0], 2.0, 0.15);

    // Weights reset between grids: the next one is equal-width.
    SDLStatic_GuiInputBegin(gui_);
    SDLStatic_GuiInputEnd(gui_);
    std::vector<float> equal;
    if (nk_begin(ctx, "grid2", nk_rect(0, 0, 300, 200), 0))
    {
        SDLStatic_GuiGridBeginOwned(gui_, 3, 24.0f);
        for (int i = 0; i < 3; i++)
        {
            SDLStatic_GuiGridCellOwned(gui_);
            equal.push_back(nk_widget_bounds(ctx).w);
            nk_label(ctx, "x", NK_TEXT_LEFT);
        }
        SDLStatic_GuiGridEndOwned(gui_);
    }
    nk_end(ctx);
    SDLStatic_GuiRender(gui_);
    ASSERT_EQ(equal.size(), 3u);
    EXPECT_NEAR(equal[1] / equal[0], 1.0, 0.05);

    EXPECT_FALSE(SDLStatic_GuiGridWeight(nullptr, 0, 1.0f));
    EXPECT_FALSE(SDLStatic_GuiGridWeight(gui_, -1, 1.0f));
    EXPECT_FALSE(SDLStatic_GuiGridBeginOwned(nullptr, 2, 20.0f));
    SDLStatic_GuiGridEndOwned(nullptr);  // safe no-op
}

// Tooltip timing: Nuklear's nk_tooltip draws immediately and stays up as
// long as the pointer is inside the widget. SDLStatic_GuiTooltip adds the
// desktop behaviour — appear after a dwell, hide as soon as the pointer
// moves.
TEST_F(GuiHarness, TooltipWaitsForHoverDwellAndHidesOnMotion)
{
    ASSERT_TRUE(SDL_InitSubSystem(SDL_INIT_EVENTS)) << SDL_GetError();
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);

    // Drive one frame with the pointer at (x, y); returns whether the
    // tooltip was displayed for the button occupying the top-left row.
    auto frame_at = [&](float x, float y) {
        SDL_Event motion;
        SDL_zero(motion);
        motion.type = SDL_EVENT_MOUSE_MOTION;
        motion.motion.x = x;
        motion.motion.y = y;
        SDL_PushEvent(&motion);
        SDLStatic_GuiPumpEvents(gui_);

        bool shown = false;
        if (nk_begin(ctx, "tips", nk_rect(0, 0, 200, 120), 0))
        {
            nk_layout_row_dynamic(ctx, 40, 1);
            shown = SDLStatic_GuiTooltip(gui_, "hover text");
            nk_button_label(ctx, "Hover me");
        }
        nk_end(ctx);
        SDLStatic_GuiRender(gui_);  // ends the frame
        return shown;
    };

    EXPECT_EQ(SDLStatic_GuiTooltipDelay(gui_), 1000) << "desktop-style default";

    // Pointer away from the widget: never shown.
    EXPECT_FALSE(frame_at(180.0f, 110.0f));

    // Arrive on the widget: the dwell has only just started, so not yet.
    EXPECT_FALSE(frame_at(50.0f, 30.0f));
    EXPECT_FALSE(frame_at(50.0f, 30.0f)) << "still counting down";

    // With no delay it appears as soon as the pointer is resting.
    SDLStatic_GuiSetTooltipDelay(gui_, 0);
    EXPECT_TRUE(frame_at(50.0f, 30.0f));

    // Moving the pointer re-arms it, even within the same widget.
    EXPECT_FALSE(frame_at(70.0f, 34.0f)) << "motion hides the tooltip";
    EXPECT_TRUE(frame_at(70.0f, 34.0f)) << "resting again shows it";

    // A long delay keeps it hidden no matter how many frames pass.
    SDLStatic_GuiSetTooltipDelay(gui_, 60000);
    EXPECT_FALSE(frame_at(90.0f, 34.0f));
    for (int i = 0; i < 5; i++)
    {
        EXPECT_FALSE(frame_at(90.0f, 34.0f));
    }

    SDLStatic_GuiSetTooltipDelay(gui_, -5);
    EXPECT_EQ(SDLStatic_GuiTooltipDelay(gui_), 0) << "negative clamps to 0";
    EXPECT_FALSE(SDLStatic_GuiTooltip(nullptr, "x"));
    EXPECT_FALSE(SDLStatic_GuiTooltip(gui_, nullptr));
    SDLStatic_GuiSetTooltipDelay(nullptr, 100);  // safe no-op

    SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

// A windowless (software) renderer stays at 1.0 so headless tests and
// non-Retina displays are unaffected by the high-DPI path.
TEST_F(GuiHarness, ScaleDefaultsToOneWithoutAWindow)
{
    EXPECT_FLOAT_EQ(SDLStatic_GuiScale(gui_), 1.0f);
    EXPECT_FLOAT_EQ(SDLStatic_GuiScale(nullptr), 1.0f);
}

// The file buttons are ordinary buttons on desktop: nothing happens until
// they are clicked, and a save reports nowhere until one completes. (The
// browser halves are DOM overlays and are exercised in a real engine.)
TEST_F(GuiHarness, FileButtonsAreInertUntilClicked)
{
    struct nk_context *ctx = SDLStatic_GuiContext(gui_);
    BeginFrame();
    if (nk_begin(ctx, "files", nk_rect(10, 10, 300, 200), NK_WINDOW_NO_SCROLLBAR))
    {
        nk_layout_row_dynamic(ctx, 30.0f, 1);
        EXPECT_FALSE(SDLStatic_GuiOpenFileButton(gui_, "Open", "Text files", "txt"));
        EXPECT_FALSE(SDLStatic_GuiSaveFileButton(gui_, "Save", "untitled.txt", "hi", 2));
    }
    nk_end(ctx);
    EXPECT_TRUE(SDLStatic_GuiRender(gui_));
    EXPECT_EQ(SDLStatic_GuiSavedPath(gui_), nullptr) << "nothing has been saved";
    EXPECT_EQ(SDLStatic_GuiSavedPath(nullptr), nullptr);

    EXPECT_FALSE(SDLStatic_GuiOpenFileButton(nullptr, "Open", nullptr, nullptr));
    EXPECT_FALSE(SDLStatic_GuiOpenFileButton(gui_, nullptr, nullptr, nullptr));
    EXPECT_FALSE(SDLStatic_GuiSaveFileButton(gui_, "Save", nullptr, "hi", 2));
    EXPECT_FALSE(SDLStatic_GuiSaveFileButton(gui_, "Save", "f.txt", nullptr, 4))
        << "a null buffer with a non-zero length is a caller bug";
}

} // namespace
