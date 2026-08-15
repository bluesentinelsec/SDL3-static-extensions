/*
 * sdlstatic_gui.c — SDL3 backend for Nuklear (SDLStatic GUI).
 *
 * Original SDLStatic code (zlib). This is the single translation unit that
 * compiles the vendored Nuklear implementation; everything else includes
 * the SDLStatic/nuklear.h wrapper for declarations only.
 */
/* Definition for the NK_DTOA hook declared in SDLStatic/nuklear.h. It must
 * exist before nuklear's implementation is expanded below. */
#include <SDL3/SDL.h>

char *SDLStatic_NuklearDtoa(char *buffer, double value)
{
    /* Nuklear's %f formatter scans the result for '.', so plain decimal
     * notation is required (never exponent form). NK_MAX_NUMBER_BUFFER is
     * 64; %.6f of a double needs at most ~320 chars in the pathological
     * case, so clamp the magnitude the way nuklear's own printf does. */
    if (value != value || value > 1.0e18 || value < -1.0e18)
    {
        SDL_strlcpy(buffer, "0.0", 4);
        return buffer;
    }
    SDL_snprintf(buffer, 64, "%.6f", value);
    return buffer;
}

#define NK_IMPLEMENTATION
#include <SDLStatic/nuklear.h>

#include <SDLStatic/gui.h>
#include <SDLStatic/gui_grid.h>

typedef struct GuiVertex
{
    float pos[2];
    float uv[2];
    float col[4]; /* SDL_FColor-compatible */
} GuiVertex;

struct SDLStatic_Gui
{
    SDL_Renderer *renderer;
    struct nk_context ctx;
    struct nk_font_atlas atlas;
    struct nk_draw_null_texture tex_null;
    struct nk_buffer cmds;
    SDL_Texture *font_texture;
    void *font_copy;
    float scale;   /* window pixel density: UI/input work in pixels */
    Uint8 style_kind[32]; /* 0 = style item, 1 = plain colour (pop order) */
    int style_depth;
    struct nk_font *fonts[3]; /* small / normal / large, baked together */
    int font_depth;           /* nk_style_push_font nesting */
    /* Tooltip dwell tracking: which widget the pointer is resting on, when
     * it arrived, and where the pointer was, so movement re-arms the timer. */
    struct nk_rect tip_rect;
    Uint64 tip_since_ms;
    float tip_mouse_x, tip_mouse_y;
    int tip_delay_ms;
    bool tip_tracking;
    SDLStatic_GuiGrid grid;   /* the script-reachable grid */
    float grid_weights[SDLSTATIC_GUI_GRID_MAX_COLS];
    bool grid_active;
    Uint8 pressed[(SDL_SCANCODE_COUNT + 7) / 8]; /* keys down this frame */
};

/* ------------------------------------------------------- clipboard ----- */

static void ClipboardCopy(nk_handle usr, const char *text, int len)
{
    (void)usr;
    char *owned = (char *)SDL_malloc((size_t)len + 1);
    if (owned != NULL)
    {
        SDL_memcpy(owned, text, (size_t)len);
        owned[len] = '\0';
        SDL_SetClipboardText(owned);
        SDL_free(owned);
    }
}

static void ClipboardPaste(nk_handle usr, struct nk_text_edit *edit)
{
    (void)usr;
    char *text = SDL_GetClipboardText();
    if (text != NULL)
    {
        if (*text != '\0')
        {
            nk_textedit_paste(edit, text, nk_strlen(text));
        }
        SDL_free(text);
    }
}

/* --------------------------------------------------------- lifetime ---- */

SDLStatic_Gui *SDLStatic_CreateGui(SDL_Renderer *renderer, const void *font_data, size_t font_len,
                                   float font_size)
{
    if (renderer == NULL)
    {
        SDL_InvalidParamError("renderer");
        return NULL;
    }
    if (font_size <= 0.0f)
    {
        font_size = 13.0f;
    }
    /* High-DPI: an SDL_WINDOW_HIGH_PIXEL_DENSITY window renders into a
     * backbuffer measured in pixels while events arrive in points. Bake the
     * font at the pixel size and scale input to match, so the UI is crisp
     * and hit-testing lines up. Windowless (software) renderers stay 1.0. */
    float scale = 1.0f;
    {
        SDL_Window *window = SDL_GetRenderWindow(renderer);
        if (window != NULL)
        {
            const float density = SDL_GetWindowPixelDensity(window);
            if (density > 0.0f)
            {
                scale = density;
            }
        }
    }
    font_size *= scale;

    SDLStatic_Gui *gui = (SDLStatic_Gui *)SDL_calloc(1, sizeof(SDLStatic_Gui));
    if (gui == NULL)
    {
        return NULL;
    }
    gui->renderer = renderer;
    gui->scale = scale;
    gui->tip_delay_ms = 1000; /* desktop-style hover dwell */

    if (!nk_init_default(&gui->ctx, NULL))
    {
        SDL_free(gui);
        SDL_SetError("nk_init_default failed");
        return NULL;
    }
    nk_buffer_init_default(&gui->cmds);

    nk_font_atlas_init_default(&gui->atlas);
    nk_font_atlas_begin(&gui->atlas);
    /* Bake a small ladder of sizes in one atlas: Nuklear cannot add glyphs
     * after baking, so a program that changes text size at runtime needs
     * every size up front. See SDLStatic_GuiSetFont. */
    static const float kSizeFactors[3] = {0.75f, 1.0f, 1.5f};
    if (font_data != NULL && font_len > 0)
    {
        /* Nuklear reads the TTF during baking; keep an owned copy alive. */
        gui->font_copy = SDL_malloc(font_len);
        if (gui->font_copy != NULL)
        {
            SDL_memcpy(gui->font_copy, font_data, font_len);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        const float size = font_size * kSizeFactors[i];
        if (gui->font_copy != NULL)
        {
            gui->fonts[i] = nk_font_atlas_add_from_memory(
                &gui->atlas, gui->font_copy, (nk_size)font_len, size, NULL);
        }
        if (gui->fonts[i] == NULL)
        {
            gui->fonts[i] = nk_font_atlas_add_default(&gui->atlas, size, NULL);
        }
    }
    struct nk_font *font = gui->fonts[SDLSTATIC_GUI_FONT_NORMAL];

    int atlas_w = 0;
    int atlas_h = 0;
    const void *image = nk_font_atlas_bake(&gui->atlas, &atlas_w, &atlas_h, NK_FONT_ATLAS_RGBA32);
    if (image == NULL || font == NULL)
    {
        SDLStatic_DestroyGui(gui);
        SDL_SetError("font atlas baking failed");
        return NULL;
    }
    gui->font_texture =
        SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, atlas_w,
                          atlas_h);
    if (gui->font_texture == NULL ||
        !SDL_UpdateTexture(gui->font_texture, NULL, image, atlas_w * 4))
    {
        SDLStatic_DestroyGui(gui);
        return NULL;
    }
    SDL_SetTextureBlendMode(gui->font_texture, SDL_BLENDMODE_BLEND);
    nk_font_atlas_end(&gui->atlas, nk_handle_ptr(gui->font_texture), &gui->tex_null);
    nk_style_set_font(&gui->ctx, &font->handle);

    gui->ctx.clip.copy = ClipboardCopy;
    gui->ctx.clip.paste = ClipboardPaste;
    gui->ctx.clip.userdata = nk_handle_ptr(gui);
    return gui;
}

void SDLStatic_DestroyGui(SDLStatic_Gui *gui)
{
    if (gui == NULL)
    {
        return;
    }
    nk_font_atlas_clear(&gui->atlas);
    nk_buffer_free(&gui->cmds);
    nk_free(&gui->ctx);
    if (gui->font_texture != NULL)
    {
        SDL_DestroyTexture(gui->font_texture);
    }
    SDL_free(gui->font_copy);
    SDL_free(gui);
}

struct nk_context *SDLStatic_GuiContext(SDLStatic_Gui *gui)
{
    return (gui != NULL) ? &gui->ctx : NULL;
}

/* ----------------------------------------------------------- input ----- */

void SDLStatic_GuiInputBegin(SDLStatic_Gui *gui)
{
    if (gui != NULL)
    {
        SDL_memset(gui->pressed, 0, sizeof(gui->pressed));
        nk_input_begin(&gui->ctx);
    }
}

void SDLStatic_GuiInputEnd(SDLStatic_Gui *gui)
{
    if (gui != NULL)
    {
        nk_input_end(&gui->ctx);
    }
}

bool SDLStatic_GuiWantsInput(SDLStatic_Gui *gui)
{
    return (gui != NULL) && nk_item_is_any_active(&gui->ctx);
}

void SDLStatic_GuiSetTooltipDelay(SDLStatic_Gui *gui, int delay_ms)
{
    if (gui != NULL)
    {
        gui->tip_delay_ms = (delay_ms < 0) ? 0 : delay_ms;
    }
}

int SDLStatic_GuiTooltipDelay(SDLStatic_Gui *gui)
{
    return (gui != NULL) ? gui->tip_delay_ms : 0;
}

bool SDLStatic_GuiTooltip(SDLStatic_Gui *gui, const char *text)
{
    if (gui == NULL || text == NULL)
    {
        return false;
    }
    struct nk_context *ctx = &gui->ctx;
    const struct nk_rect bounds = nk_widget_bounds(ctx);
    if (!nk_input_is_mouse_hovering_rect(&ctx->input, bounds))
    {
        return false;
    }

    const float mx = ctx->input.mouse.pos.x;
    const float my = ctx->input.mouse.pos.y;
    const Uint64 now = SDL_GetTicks();

    /* A different widget, or a pointer that actually moved, restarts the
     * dwell. The threshold ignores sub-pixel jitter but not real motion. */
    const float move_threshold = 2.0f * gui->scale;
    const bool same_widget = gui->tip_tracking && bounds.x == gui->tip_rect.x &&
                             bounds.y == gui->tip_rect.y && bounds.w == gui->tip_rect.w &&
                             bounds.h == gui->tip_rect.h;
    const bool moved = !gui->tip_tracking ||
                       SDL_fabsf(mx - gui->tip_mouse_x) > move_threshold ||
                       SDL_fabsf(my - gui->tip_mouse_y) > move_threshold;

    if (!same_widget || moved)
    {
        gui->tip_tracking = true;
        gui->tip_rect = bounds;
        gui->tip_mouse_x = mx;
        gui->tip_mouse_y = my;
        gui->tip_since_ms = now;
        return false; /* re-armed: hidden until the pointer rests again */
    }

    if ((now - gui->tip_since_ms) < (Uint64)gui->tip_delay_ms)
    {
        return false; /* still counting down */
    }
    nk_tooltip(ctx, text);
    return true;
}

bool SDLStatic_GuiGridWeight(SDLStatic_Gui *gui, int column, float weight)
{
    if (gui == NULL || column < 0 || column >= SDLSTATIC_GUI_GRID_MAX_COLS ||
        weight <= 0.0f)
    {
        SDL_InvalidParamError("column/weight");
        return false;
    }
    gui->grid_weights[column] = weight;
    return true;
}

bool SDLStatic_GuiGridBeginOwned(SDLStatic_Gui *gui, int columns, float row_height)
{
    if (gui == NULL)
    {
        SDL_InvalidParamError("gui");
        return false;
    }
    for (int i = 0; i < SDLSTATIC_GUI_GRID_MAX_COLS; i++)
    {
        if (gui->grid_weights[i] <= 0.0f)
        {
            gui->grid_weights[i] = 1.0f; /* default: equal columns */
        }
    }
    gui->grid_active =
        SDLStatic_GuiGridBegin(&gui->ctx, &gui->grid, columns, gui->grid_weights, row_height);
    /* Weights are per-grid: reset so the next grid starts equal again. */
    SDL_memset(gui->grid_weights, 0, sizeof(gui->grid_weights));
    return gui->grid_active;
}

void SDLStatic_GuiGridCellOwned(SDLStatic_Gui *gui)
{
    if (gui != NULL && gui->grid_active)
    {
        SDLStatic_GuiGridCell(&gui->grid);
    }
}

void SDLStatic_GuiGridCellSpanOwned(SDLStatic_Gui *gui, int span)
{
    if (gui != NULL && gui->grid_active)
    {
        SDLStatic_GuiGridCellSpan(&gui->grid, span);
    }
}

void SDLStatic_GuiGridNextRowOwned(SDLStatic_Gui *gui)
{
    if (gui != NULL && gui->grid_active)
    {
        SDLStatic_GuiGridNextRow(&gui->grid);
    }
}

void SDLStatic_GuiGridEndOwned(SDLStatic_Gui *gui)
{
    if (gui != NULL && gui->grid_active)
    {
        SDLStatic_GuiGridEnd(&gui->grid);
        gui->grid_active = false;
    }
}

bool SDLStatic_GuiImage(SDLStatic_Gui *gui, SDL_Texture *texture,
                        SDLStatic_GuiImageMode mode)
{
    if (gui == NULL || texture == NULL)
    {
        SDL_InvalidParamError("gui/texture");
        return false;
    }
    struct nk_context *ctx = &gui->ctx;
    struct nk_rect slot;
    if (nk_widget(&slot, ctx) == NK_WIDGET_INVALID)
    {
        return false; /* scrolled out of view */
    }

    float tex_w = 0.0f;
    float tex_h = 0.0f;
    if (!SDL_GetTextureSize(texture, &tex_w, &tex_h) || tex_w <= 0.0f || tex_h <= 0.0f)
    {
        return false;
    }

    struct nk_rect dst = slot;
    if (mode != SDLSTATIC_GUI_IMAGE_STRETCH)
    {
        float w = tex_w;
        float h = tex_h;
        if (mode == SDLSTATIC_GUI_IMAGE_ZOOM || mode == SDLSTATIC_GUI_IMAGE_FILL)
        {
            const float sx = slot.w / tex_w;
            const float sy = slot.h / tex_h;
            /* Zoom fits inside (min), Fill covers (max). */
            const float scale = (mode == SDLSTATIC_GUI_IMAGE_ZOOM) ? SDL_min(sx, sy)
                                                                   : SDL_max(sx, sy);
            w = tex_w * scale;
            h = tex_h * scale;
        }
        dst.x = slot.x + (slot.w - w) * 0.5f;
        dst.y = slot.y + (slot.h - h) * 0.5f;
        dst.w = w;
        dst.h = h;
    }

    struct nk_command_buffer *canvas = nk_window_get_canvas(ctx);
    if (canvas == NULL)
    {
        return false;
    }
    /* Fill and Center can exceed the slot; clip so the image never spills
     * over neighbouring widgets. */
    const bool needs_clip = (mode == SDLSTATIC_GUI_IMAGE_FILL ||
                             mode == SDLSTATIC_GUI_IMAGE_CENTER);
    if (needs_clip)
    {
        nk_push_scissor(canvas, slot);
    }
    struct nk_image img = nk_image_ptr(texture);
    nk_draw_image(canvas, dst, &img, nk_rgb(255, 255, 255));
    if (needs_clip)
    {
        nk_push_scissor(canvas, nk_null_rect);
    }
    return true;
}

static struct nk_font *FontFor(SDLStatic_Gui *gui, SDLStatic_GuiFontSize which)
{
    if (gui == NULL || which < SDLSTATIC_GUI_FONT_SMALL || which > SDLSTATIC_GUI_FONT_LARGE)
    {
        return NULL;
    }
    return gui->fonts[which];
}

bool SDLStatic_GuiSetFont(SDLStatic_Gui *gui, SDLStatic_GuiFontSize which)
{
    struct nk_font *font = FontFor(gui, which);
    if (font == NULL)
    {
        SDL_InvalidParamError("which");
        return false;
    }
    nk_style_set_font(&gui->ctx, &font->handle);
    return true;
}

bool SDLStatic_GuiPushFont(SDLStatic_Gui *gui, SDLStatic_GuiFontSize which)
{
    struct nk_font *font = FontFor(gui, which);
    if (font == NULL)
    {
        SDL_InvalidParamError("which");
        return false;
    }
    if (!nk_style_push_font(&gui->ctx, &font->handle))
    {
        return false;
    }
    gui->font_depth++;
    return true;
}

void SDLStatic_GuiPopFont(SDLStatic_Gui *gui, int count)
{
    if (gui == NULL)
    {
        return;
    }
    while (count-- > 0 && gui->font_depth > 0)
    {
        nk_style_pop_font(&gui->ctx);
        gui->font_depth--;
    }
}

float SDLStatic_GuiFontHeight(SDLStatic_Gui *gui)
{
    if (gui == NULL || gui->ctx.style.font == NULL)
    {
        return 0.0f;
    }
    return gui->ctx.style.font->height;
}

bool SDLStatic_GuiPushStyleColor(SDLStatic_Gui *gui, SDLStatic_GuiStyleColor which,
                                 SDL_Color color)
{
    if (gui == NULL || gui->style_depth >= (int)SDL_arraysize(gui->style_kind))
    {
        return false;
    }
    struct nk_context *ctx = &gui->ctx;
    const struct nk_color nkc = nk_rgba(color.r, color.g, color.b, color.a);
    struct nk_style_item *item = NULL;
    struct nk_color *plain = NULL;

    switch (which)
    {
    case SDLSTATIC_GUI_COLOR_WINDOW_BACKGROUND:
        item = &ctx->style.window.fixed_background;
        break;
    case SDLSTATIC_GUI_COLOR_BUTTON:
        item = &ctx->style.button.normal;
        break;
    case SDLSTATIC_GUI_COLOR_BUTTON_HOVER:
        item = &ctx->style.button.hover;
        break;
    case SDLSTATIC_GUI_COLOR_HEADER:
        item = &ctx->style.window.header.normal;
        break;
    case SDLSTATIC_GUI_COLOR_TEXT:
        plain = &ctx->style.text.color;
        break;
    case SDLSTATIC_GUI_COLOR_BUTTON_TEXT:
        plain = &ctx->style.button.text_normal;
        break;
    default:
        SDL_InvalidParamError("which");
        return false;
    }

    if (item != NULL)
    {
        nk_style_push_style_item(ctx, item, nk_style_item_color(nkc));
        gui->style_kind[gui->style_depth++] = 0;
    }
    else
    {
        nk_style_push_color(ctx, plain, nkc);
        gui->style_kind[gui->style_depth++] = 1;
    }
    return true;
}

void SDLStatic_GuiPopStyleColor(SDLStatic_Gui *gui, int count)
{
    if (gui == NULL)
    {
        return;
    }
    while (count-- > 0 && gui->style_depth > 0)
    {
        gui->style_depth--;
        if (gui->style_kind[gui->style_depth] == 0)
        {
            nk_style_pop_style_item(&gui->ctx);
        }
        else
        {
            nk_style_pop_color(&gui->ctx);
        }
    }
}

bool SDLStatic_GuiKeyPressed(SDLStatic_Gui *gui, int scancode)
{
    if (gui == NULL || scancode < 0 || scancode >= SDL_SCANCODE_COUNT)
    {
        return false;
    }
    return (gui->pressed[scancode / 8] & (Uint8)(1u << (scancode % 8))) != 0;
}

float SDLStatic_GuiScale(SDLStatic_Gui *gui)
{
    return (gui != NULL) ? gui->scale : 1.0f;
}

bool SDLStatic_GuiPumpEvents(SDLStatic_Gui *gui)
{
    bool keep_running = true;
    SDL_Event event;

    if (gui == NULL)
    {
        SDL_InvalidParamError("gui");
        return false;
    }
    SDLStatic_GuiInputBegin(gui);
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT ||
            event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
        {
            keep_running = false;
        }
        SDLStatic_GuiProcessEvent(gui, &event);
    }
    SDLStatic_GuiInputEnd(gui);
    return keep_running;
}

static void HandleKey(struct nk_context *ctx, const SDL_KeyboardEvent *key, bool down)
{
    const bool ctrl = (key->mod & SDL_KMOD_CTRL) != 0;
    switch (key->key)
    {
    case SDLK_LSHIFT:
    case SDLK_RSHIFT:
        nk_input_key(ctx, NK_KEY_SHIFT, down);
        break;
    case SDLK_LCTRL:
    case SDLK_RCTRL:
        nk_input_key(ctx, NK_KEY_CTRL, down);
        break;
    case SDLK_DELETE:
        nk_input_key(ctx, NK_KEY_DEL, down);
        break;
    case SDLK_RETURN:
    case SDLK_KP_ENTER:
        nk_input_key(ctx, NK_KEY_ENTER, down);
        break;
    case SDLK_TAB:
        nk_input_key(ctx, NK_KEY_TAB, down);
        break;
    case SDLK_BACKSPACE:
        nk_input_key(ctx, NK_KEY_BACKSPACE, down);
        break;
    case SDLK_HOME:
        nk_input_key(ctx, NK_KEY_TEXT_START, down);
        nk_input_key(ctx, NK_KEY_SCROLL_START, down);
        break;
    case SDLK_END:
        nk_input_key(ctx, NK_KEY_TEXT_END, down);
        nk_input_key(ctx, NK_KEY_SCROLL_END, down);
        break;
    case SDLK_PAGEUP:
        nk_input_key(ctx, NK_KEY_SCROLL_UP, down);
        break;
    case SDLK_PAGEDOWN:
        nk_input_key(ctx, NK_KEY_SCROLL_DOWN, down);
        break;
    case SDLK_UP:
        nk_input_key(ctx, NK_KEY_UP, down);
        break;
    case SDLK_DOWN:
        nk_input_key(ctx, NK_KEY_DOWN, down);
        break;
    case SDLK_LEFT:
        nk_input_key(ctx, ctrl ? NK_KEY_TEXT_WORD_LEFT : NK_KEY_LEFT, down);
        break;
    case SDLK_RIGHT:
        nk_input_key(ctx, ctrl ? NK_KEY_TEXT_WORD_RIGHT : NK_KEY_RIGHT, down);
        break;
    case SDLK_C:
        if (ctrl)
        {
            nk_input_key(ctx, NK_KEY_COPY, down);
        }
        break;
    case SDLK_V:
        if (ctrl)
        {
            nk_input_key(ctx, NK_KEY_PASTE, down);
        }
        break;
    case SDLK_X:
        if (ctrl)
        {
            nk_input_key(ctx, NK_KEY_CUT, down);
        }
        break;
    case SDLK_Z:
        if (ctrl)
        {
            nk_input_key(ctx, NK_KEY_TEXT_UNDO, down);
        }
        break;
    case SDLK_Y:
        if (ctrl)
        {
            nk_input_key(ctx, NK_KEY_TEXT_REDO, down);
        }
        break;
    case SDLK_A:
        if (ctrl)
        {
            nk_input_key(ctx, NK_KEY_TEXT_SELECT_ALL, down);
        }
        break;
    default:
        break;
    }
}

bool SDLStatic_GuiProcessEvent(SDLStatic_Gui *gui, const SDL_Event *event)
{
    if (gui == NULL || event == NULL)
    {
        return false;
    }
    struct nk_context *ctx = &gui->ctx;
    switch (event->type)
    {
    case SDL_EVENT_MOUSE_MOTION:
        nk_input_motion(ctx, (int)(event->motion.x * gui->scale),
                        (int)(event->motion.y * gui->scale));
        return true;
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
    case SDL_EVENT_MOUSE_BUTTON_UP: {
        const bool down = (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN);
        const int x = (int)(event->button.x * gui->scale);
        const int y = (int)(event->button.y * gui->scale);
        enum nk_buttons button = NK_BUTTON_LEFT;
        if (event->button.button == SDL_BUTTON_MIDDLE)
        {
            button = NK_BUTTON_MIDDLE;
        }
        else if (event->button.button == SDL_BUTTON_RIGHT)
        {
            button = NK_BUTTON_RIGHT;
        }
        if (button == NK_BUTTON_LEFT && down && event->button.clicks >= 2)
        {
            nk_input_button(ctx, NK_BUTTON_DOUBLE, x, y, nk_true);
        }
        nk_input_button(ctx, button, x, y, down ? nk_true : nk_false);
        return true;
    }
    case SDL_EVENT_MOUSE_WHEEL:
        nk_input_scroll(ctx, nk_vec2(event->wheel.x, event->wheel.y));
        return true;
    case SDL_EVENT_TEXT_INPUT: {
        const char *text = event->text.text;
        const int len = nk_strlen(text);
        int at = 0;
        while (at < len)
        {
            nk_rune rune = 0;
            const int consumed = nk_utf_decode(text + at, &rune, len - at);
            if (consumed <= 0)
            {
                break;
            }
            nk_input_unicode(ctx, rune);
            at += consumed;
        }
        return true;
    }
    case SDL_EVENT_KEY_DOWN:
        if (event->key.scancode >= 0 && event->key.scancode < SDL_SCANCODE_COUNT)
        {
            gui->pressed[event->key.scancode / 8] |=
                (Uint8)(1u << (event->key.scancode % 8));
        }
        /* fall through to Nuklear key translation */
        SDL_FALLTHROUGH;
    case SDL_EVENT_KEY_UP:
        HandleKey(ctx, &event->key, event->type == SDL_EVENT_KEY_DOWN);
        return true;
    default:
        return false;
    }
}

/* ---------------------------------------------------------- render ----- */

bool SDLStatic_GuiRender(SDLStatic_Gui *gui)
{
    if (gui == NULL)
    {
        return SDL_InvalidParamError("gui");
    }
    static const struct nk_draw_vertex_layout_element vertex_layout[] = {
        {NK_VERTEX_POSITION, NK_FORMAT_FLOAT, NK_OFFSETOF(GuiVertex, pos)},
        {NK_VERTEX_TEXCOORD, NK_FORMAT_FLOAT, NK_OFFSETOF(GuiVertex, uv)},
        {NK_VERTEX_COLOR, NK_FORMAT_R32G32B32A32_FLOAT, NK_OFFSETOF(GuiVertex, col)},
        {NK_VERTEX_LAYOUT_END}};

    struct nk_convert_config config;
    NK_MEMSET(&config, 0, sizeof(config));
    config.vertex_layout = vertex_layout;
    config.vertex_size = sizeof(GuiVertex);
    config.vertex_alignment = NK_ALIGNOF(GuiVertex);
    config.tex_null = gui->tex_null;
    config.circle_segment_count = 22;
    config.curve_segment_count = 22;
    config.arc_segment_count = 22;
    config.global_alpha = 1.0f;
    config.shape_AA = NK_ANTI_ALIASING_ON;
    config.line_AA = NK_ANTI_ALIASING_ON;

    struct nk_buffer verts;
    struct nk_buffer idx;
    nk_buffer_init_default(&verts);
    nk_buffer_init_default(&idx);
    const nk_flags rc = nk_convert(&gui->ctx, &gui->cmds, &verts, &idx, &config);
    bool ok = (rc == NK_CONVERT_SUCCESS);
    if (ok)
    {
        const GuiVertex *vertices = (const GuiVertex *)nk_buffer_memory_const(&verts);
        const nk_draw_index *indices = (const nk_draw_index *)nk_buffer_memory_const(&idx);
        const int vertex_count = (int)(verts.needed / sizeof(GuiVertex));

        const struct nk_draw_command *cmd = NULL;
        nk_size index_offset = 0;
        nk_draw_foreach(cmd, &gui->ctx, &gui->cmds)
        {
            if (cmd->elem_count == 0)
            {
                continue;
            }
            const SDL_Rect clip = {(int)cmd->clip_rect.x, (int)cmd->clip_rect.y,
                                   (int)cmd->clip_rect.w, (int)cmd->clip_rect.h};
            SDL_SetRenderClipRect(gui->renderer, &clip);
            if (!SDL_RenderGeometryRaw(gui->renderer, (SDL_Texture *)cmd->texture.ptr,
                                       &vertices->pos[0], (int)sizeof(GuiVertex),
                                       (const SDL_FColor *)(const void *)&vertices->col[0],
                                       (int)sizeof(GuiVertex), &vertices->uv[0],
                                       (int)sizeof(GuiVertex), vertex_count,
                                       indices + index_offset, (int)cmd->elem_count,
                                       (int)sizeof(nk_draw_index)))
            {
                ok = false;
                break;
            }
            index_offset += cmd->elem_count;
        }
        SDL_SetRenderClipRect(gui->renderer, NULL);
    }
    else
    {
        SDL_SetError("nk_convert failed (0x%x)", (unsigned)rc);
    }

    nk_buffer_free(&verts);
    nk_buffer_free(&idx);
    nk_buffer_clear(&gui->cmds);
    nk_clear(&gui->ctx);
    return ok;
}
