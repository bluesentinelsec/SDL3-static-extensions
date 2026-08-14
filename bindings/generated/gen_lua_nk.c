/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for Nuklear. */
#include "../src/gen_support_lua.h"

#include <SDLStatic/nuklear.h>
#include <string.h>

static void GenRead_nk_color(lua_State *L, int idx, struct nk_color *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->r = (nk_byte)SDLStaticGen_LuaFieldInt(L, idx, "r");
    out->g = (nk_byte)SDLStaticGen_LuaFieldInt(L, idx, "g");
    out->b = (nk_byte)SDLStaticGen_LuaFieldInt(L, idx, "b");
    out->a = (nk_byte)SDLStaticGen_LuaFieldInt(L, idx, "a");
}

static void GenPush_nk_color(lua_State *L, const struct nk_color *in)
{
    lua_createtable(L, 0, 4);
    lua_pushinteger(L, (lua_Integer)in->r);
    lua_setfield(L, -2, "r");
    lua_pushinteger(L, (lua_Integer)in->g);
    lua_setfield(L, -2, "g");
    lua_pushinteger(L, (lua_Integer)in->b);
    lua_setfield(L, -2, "b");
    lua_pushinteger(L, (lua_Integer)in->a);
    lua_setfield(L, -2, "a");
}

static void GenRead_nk_colorf(lua_State *L, int idx, struct nk_colorf *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->r = (float)SDLStaticGen_LuaFieldNum(L, idx, "r");
    out->g = (float)SDLStaticGen_LuaFieldNum(L, idx, "g");
    out->b = (float)SDLStaticGen_LuaFieldNum(L, idx, "b");
    out->a = (float)SDLStaticGen_LuaFieldNum(L, idx, "a");
}

static void GenPush_nk_colorf(lua_State *L, const struct nk_colorf *in)
{
    lua_createtable(L, 0, 4);
    lua_pushnumber(L, (lua_Number)in->r);
    lua_setfield(L, -2, "r");
    lua_pushnumber(L, (lua_Number)in->g);
    lua_setfield(L, -2, "g");
    lua_pushnumber(L, (lua_Number)in->b);
    lua_setfield(L, -2, "b");
    lua_pushnumber(L, (lua_Number)in->a);
    lua_setfield(L, -2, "a");
}

static void GenRead_nk_rect(lua_State *L, int idx, struct nk_rect *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (float)SDLStaticGen_LuaFieldNum(L, idx, "x");
    out->y = (float)SDLStaticGen_LuaFieldNum(L, idx, "y");
    out->w = (float)SDLStaticGen_LuaFieldNum(L, idx, "w");
    out->h = (float)SDLStaticGen_LuaFieldNum(L, idx, "h");
}

static void GenPush_nk_rect(lua_State *L, const struct nk_rect *in)
{
    lua_createtable(L, 0, 4);
    lua_pushnumber(L, (lua_Number)in->x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, (lua_Number)in->y);
    lua_setfield(L, -2, "y");
    lua_pushnumber(L, (lua_Number)in->w);
    lua_setfield(L, -2, "w");
    lua_pushnumber(L, (lua_Number)in->h);
    lua_setfield(L, -2, "h");
}

static void GenPush_nk_scroll(lua_State *L, const struct nk_scroll *in)
{
    lua_createtable(L, 0, 2);
    lua_pushinteger(L, (lua_Integer)in->x);
    lua_setfield(L, -2, "x");
    lua_pushinteger(L, (lua_Integer)in->y);
    lua_setfield(L, -2, "y");
}

static void GenRead_nk_vec2(lua_State *L, int idx, struct nk_vec2 *out)
{
    memset(out, 0, sizeof(*out));
    if (!lua_istable(L, idx)) { return; }
    out->x = (float)SDLStaticGen_LuaFieldNum(L, idx, "x");
    out->y = (float)SDLStaticGen_LuaFieldNum(L, idx, "y");
}

static void GenPush_nk_vec2(lua_State *L, const struct nk_vec2 *in)
{
    lua_createtable(L, 0, 2);
    lua_pushnumber(L, (lua_Number)in->x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, (lua_Number)in->y);
    lua_setfield(L, -2, "y");
}

static int GenL_nk__begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_command * rv = nk__begin(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_command");
    return 1;
}

static int GenL_nk__draw_begin(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_buffer");
    const struct nk_draw_command * rv = nk__draw_begin(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_draw_command");
    return 1;
}

static int GenL_nk__draw_end(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_buffer");
    const struct nk_draw_command * rv = nk__draw_end(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_draw_command");
    return 1;
}

static int GenL_nk__draw_list_begin(lua_State *L)
{
    (void)L;
    const struct nk_draw_list *a0 = (const struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_buffer");
    const struct nk_draw_command * rv = nk__draw_list_begin(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_draw_command");
    return 1;
}

static int GenL_nk__draw_list_end(lua_State *L)
{
    (void)L;
    const struct nk_draw_list *a0 = (const struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_buffer");
    const struct nk_draw_command * rv = nk__draw_list_end(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_draw_command");
    return 1;
}

static int GenL_nk__draw_list_next(lua_State *L)
{
    (void)L;
    const struct nk_draw_command *a0 = (const struct nk_draw_command *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_command");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_buffer");
    const struct nk_draw_list *a2 = (const struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 3, "nk_draw_list");
    const struct nk_draw_command * rv = nk__draw_list_next(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_draw_command");
    return 1;
}

static int GenL_nk__draw_next(lua_State *L)
{
    (void)L;
    const struct nk_draw_command *a0 = (const struct nk_draw_command *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_command");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_buffer");
    const struct nk_context *a2 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 3, "nk_context");
    const struct nk_draw_command * rv = nk__draw_next(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_draw_command");
    return 1;
}

static int GenL_nk__next(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_command *a1 = (const struct nk_command *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_command");
    const struct nk_command * rv = nk__next(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_command");
    return 1;
}

static int GenL_nk_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    struct nk_rect a2;
    GenRead_nk_rect(L, 3, &a2);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool rv = nk_begin(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_begin_titled(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    struct nk_rect a3;
    GenRead_nk_rect(L, 4, &a3);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool rv = nk_begin_titled(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_buffer_clear(lua_State *L)
{
    (void)L;
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_buffer");
    nk_buffer_clear(a0);
    return 0;
}

static int GenL_nk_buffer_free(lua_State *L)
{
    (void)L;
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_buffer");
    nk_buffer_free(a0);
    return 0;
}

static int GenL_nk_buffer_info(lua_State *L)
{
    (void)L;
    struct nk_memory_status *a0 = (struct nk_memory_status *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_memory_status");
    const struct nk_buffer *a1 = (const struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_buffer");
    nk_buffer_info(a0, a1);
    return 0;
}

static int GenL_nk_buffer_init(lua_State *L)
{
    (void)L;
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_buffer");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_allocator");
    nk_size a2 = (nk_size)luaL_checkinteger(L, 3);
    nk_buffer_init(a0, a1, a2);
    return 0;
}

static int GenL_nk_buffer_init_default(lua_State *L)
{
    (void)L;
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_buffer");
    nk_buffer_init_default(a0);
    return 0;
}

static int GenL_nk_buffer_mark(lua_State *L)
{
    (void)L;
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_buffer");
    enum nk_buffer_allocation_type a1 = (enum nk_buffer_allocation_type)luaL_checkinteger(L, 2);
    nk_buffer_mark(a0, a1);
    return 0;
}

static int GenL_nk_buffer_push(lua_State *L)
{
    (void)L;
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_buffer");
    enum nk_buffer_allocation_type a1 = (enum nk_buffer_allocation_type)luaL_checkinteger(L, 2);
    size_t len2 = 0;
    const char *a2 = luaL_checklstring(L, 3, &len2);
    nk_size a4 = (nk_size)luaL_checkinteger(L, 4);
    nk_buffer_push(a0, a1, (const void *)a2, (nk_size)len2, a4);
    return 0;
}

static int GenL_nk_buffer_reset(lua_State *L)
{
    (void)L;
    struct nk_buffer *a0 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_buffer");
    enum nk_buffer_allocation_type a1 = (enum nk_buffer_allocation_type)luaL_checkinteger(L, 2);
    nk_buffer_reset(a0, a1);
    return 0;
}

static int GenL_nk_buffer_total(lua_State *L)
{
    (void)L;
    const struct nk_buffer *a0 = (const struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_buffer");
    nk_size rv = nk_buffer_total(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_button_color(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_bool rv = nk_button_color(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool rv = nk_button_label(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_label_styled(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_style_button *a1 = (const struct nk_style_button *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_style_button");
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    nk_bool rv = nk_button_label_styled(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_pop_behavior(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_button_pop_behavior(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_push_behavior(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_button_behavior a1 = (enum nk_button_behavior)luaL_checkinteger(L, 2);
    nk_bool rv = nk_button_push_behavior(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_set_behavior(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_button_behavior a1 = (enum nk_button_behavior)luaL_checkinteger(L, 2);
    nk_button_set_behavior(a0, a1);
    return 0;
}

static int GenL_nk_button_symbol(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    nk_bool rv = nk_button_symbol(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_symbol_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool rv = nk_button_symbol_label(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_symbol_label_styled(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_style_button *a1 = (const struct nk_style_button *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_style_button");
    enum nk_symbol_type a2 = (enum nk_symbol_type)luaL_checkinteger(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool rv = nk_button_symbol_label_styled(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_symbol_styled(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_style_button *a1 = (const struct nk_style_button *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_style_button");
    enum nk_symbol_type a2 = (enum nk_symbol_type)luaL_checkinteger(L, 3);
    nk_bool rv = nk_button_symbol_styled(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_symbol_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool rv = nk_button_symbol_text(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_symbol_text_styled(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_style_button *a1 = (const struct nk_style_button *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_style_button");
    enum nk_symbol_type a2 = (enum nk_symbol_type)luaL_checkinteger(L, 3);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    nk_flags a5 = (nk_flags)luaL_checkinteger(L, 6);
    nk_bool rv = nk_button_symbol_text_styled(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_bool rv = nk_button_text(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_button_text_styled(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_style_button *a1 = (const struct nk_style_button *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_style_button");
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_bool rv = nk_button_text_styled(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_chart_add_slot(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_chart_type a1 = (enum nk_chart_type)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    nk_chart_add_slot(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_nk_chart_add_slot_colored(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_chart_type a1 = (enum nk_chart_type)luaL_checkinteger(L, 2);
    struct nk_color a2;
    GenRead_nk_color(L, 3, &a2);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    int a4 = (int)luaL_checkinteger(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    nk_chart_add_slot_colored(a0, a1, a2, a3, a4, a5, a6);
    return 0;
}

static int GenL_nk_chart_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_chart_type a1 = (enum nk_chart_type)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    nk_bool rv = nk_chart_begin(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_chart_begin_colored(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_chart_type a1 = (enum nk_chart_type)luaL_checkinteger(L, 2);
    struct nk_color a2;
    GenRead_nk_color(L, 3, &a2);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    int a4 = (int)luaL_checkinteger(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    nk_bool rv = nk_chart_begin_colored(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_chart_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_chart_end(a0);
    return 0;
}

static int GenL_nk_chart_push(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    nk_flags rv = nk_chart_push(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_chart_push_slot(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_flags rv = nk_chart_push_slot(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_check_flags_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    unsigned int a2 = (unsigned int)luaL_checkinteger(L, 3);
    unsigned int a3 = (unsigned int)luaL_checkinteger(L, 4);
    unsigned int rv = nk_check_flags_label(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_check_flags_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    unsigned int a3 = (unsigned int)luaL_checkinteger(L, 4);
    unsigned int a4 = (unsigned int)luaL_checkinteger(L, 5);
    unsigned int rv = nk_check_flags_text(a0, a1, a2, a3, a4);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_check_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool a2 = (nk_bool)lua_toboolean(L, 3);
    nk_bool rv = nk_check_label(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_check_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_bool a3 = (nk_bool)lua_toboolean(L, 4);
    nk_bool rv = nk_check_text(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_check_text_align(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_bool a3 = (nk_bool)lua_toboolean(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_flags a5 = (nk_flags)luaL_checkinteger(L, 6);
    nk_bool rv = nk_check_text_align(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_checkbox_flags_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    unsigned int io2 = (unsigned int)luaL_optinteger(L, 3, 0);
    unsigned int a3 = (unsigned int)luaL_checkinteger(L, 4);
    nk_bool rv = nk_checkbox_flags_label(a0, a1, &io2, a3);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_nk_checkbox_flags_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    unsigned int io3 = (unsigned int)luaL_optinteger(L, 4, 0);
    unsigned int a4 = (unsigned int)luaL_checkinteger(L, 5);
    nk_bool rv = nk_checkbox_flags_text(a0, a1, a2, &io3, a4);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io3);
    return 2;
}

static int GenL_nk_checkbox_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool io2 = (nk_bool)lua_toboolean(L, 3);
    nk_bool rv = nk_checkbox_label(a0, a1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io2);
    return 2;
}

static int GenL_nk_checkbox_label_align(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool io2 = (nk_bool)lua_toboolean(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool rv = nk_checkbox_label_align(a0, a1, &io2, a3, a4);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io2);
    return 2;
}

static int GenL_nk_checkbox_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_bool io3 = (nk_bool)lua_toboolean(L, 4);
    nk_bool rv = nk_checkbox_text(a0, a1, a2, &io3);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io3);
    return 2;
}

static int GenL_nk_checkbox_text_align(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_bool io3 = (nk_bool)lua_toboolean(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_flags a5 = (nk_flags)luaL_checkinteger(L, 6);
    nk_bool rv = nk_checkbox_text_align(a0, a1, a2, &io3, a4, a5);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io3);
    return 2;
}

static int GenL_nk_clear(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_clear(a0);
    return 0;
}

static int GenL_nk_color_cf(lua_State *L)
{
    (void)L;
    struct nk_color a0;
    GenRead_nk_color(L, 1, &a0);
    struct nk_colorf rv = nk_color_cf(a0);
    GenPush_nk_colorf(L, &rv);
    return 1;
}

static int GenL_nk_color_d(lua_State *L)
{
    (void)L;
    double io0 = (double)luaL_optnumber(L, 1, 0);
    double io1 = (double)luaL_optnumber(L, 2, 0);
    double io2 = (double)luaL_optnumber(L, 3, 0);
    double io3 = (double)luaL_optnumber(L, 4, 0);
    struct nk_color a4;
    GenRead_nk_color(L, 5, &a4);
    nk_color_d(&io0, &io1, &io2, &io3, a4);
    lua_pushnumber(L, (lua_Number)io0);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    return 4;
}

static int GenL_nk_color_dv(lua_State *L)
{
    (void)L;
    double io0 = (double)luaL_optnumber(L, 1, 0);
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_color_dv(&io0, a1);
    lua_pushnumber(L, (lua_Number)io0);
    return 1;
}

static int GenL_nk_color_f(lua_State *L)
{
    (void)L;
    float io0 = (float)luaL_optnumber(L, 1, 0);
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    struct nk_color a4;
    GenRead_nk_color(L, 5, &a4);
    nk_color_f(&io0, &io1, &io2, &io3, a4);
    lua_pushnumber(L, (lua_Number)io0);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    return 4;
}

static int GenL_nk_color_fv(lua_State *L)
{
    (void)L;
    float io0 = (float)luaL_optnumber(L, 1, 0);
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_color_fv(&io0, a1);
    lua_pushnumber(L, (lua_Number)io0);
    return 1;
}

static int GenL_nk_color_hex_rgb(lua_State *L)
{
    (void)L;
    const char *src0 = lua_isnoneornil(L, 1) ? "" : luaL_checkstring(L, 1);
    char *a0 = SDL_strdup(src0);
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_color_hex_rgb(a0, a1);
    SDL_free(a0);
    return 0;
}

static int GenL_nk_color_hex_rgba(lua_State *L)
{
    (void)L;
    const char *src0 = lua_isnoneornil(L, 1) ? "" : luaL_checkstring(L, 1);
    char *a0 = SDL_strdup(src0);
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_color_hex_rgba(a0, a1);
    SDL_free(a0);
    return 0;
}

static int GenL_nk_color_hsv_b(lua_State *L)
{
    (void)L;
    nk_byte io0 = (nk_byte)luaL_optinteger(L, 1, 0);
    nk_byte io1 = (nk_byte)luaL_optinteger(L, 2, 0);
    nk_byte io2 = (nk_byte)luaL_optinteger(L, 3, 0);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    nk_color_hsv_b(&io0, &io1, &io2, a3);
    lua_pushinteger(L, (lua_Integer)io0);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_nk_color_hsv_bv(lua_State *L)
{
    (void)L;
    nk_byte io0 = (nk_byte)luaL_optinteger(L, 1, 0);
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_color_hsv_bv(&io0, a1);
    lua_pushinteger(L, (lua_Integer)io0);
    return 1;
}

static int GenL_nk_color_hsv_f(lua_State *L)
{
    (void)L;
    float io0 = (float)luaL_optnumber(L, 1, 0);
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    nk_color_hsv_f(&io0, &io1, &io2, a3);
    lua_pushnumber(L, (lua_Number)io0);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    return 3;
}

static int GenL_nk_color_hsv_fv(lua_State *L)
{
    (void)L;
    float io0 = (float)luaL_optnumber(L, 1, 0);
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_color_hsv_fv(&io0, a1);
    lua_pushnumber(L, (lua_Number)io0);
    return 1;
}

static int GenL_nk_color_hsv_i(lua_State *L)
{
    (void)L;
    int io0 = (int)luaL_optinteger(L, 1, 0);
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    nk_color_hsv_i(&io0, &io1, &io2, a3);
    lua_pushinteger(L, (lua_Integer)io0);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_nk_color_hsv_iv(lua_State *L)
{
    (void)L;
    int io0 = (int)luaL_optinteger(L, 1, 0);
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_color_hsv_iv(&io0, a1);
    lua_pushinteger(L, (lua_Integer)io0);
    return 1;
}

static int GenL_nk_color_hsva_b(lua_State *L)
{
    (void)L;
    nk_byte io0 = (nk_byte)luaL_optinteger(L, 1, 0);
    nk_byte io1 = (nk_byte)luaL_optinteger(L, 2, 0);
    nk_byte io2 = (nk_byte)luaL_optinteger(L, 3, 0);
    nk_byte io3 = (nk_byte)luaL_optinteger(L, 4, 0);
    struct nk_color a4;
    GenRead_nk_color(L, 5, &a4);
    nk_color_hsva_b(&io0, &io1, &io2, &io3, a4);
    lua_pushinteger(L, (lua_Integer)io0);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    return 4;
}

static int GenL_nk_color_hsva_bv(lua_State *L)
{
    (void)L;
    nk_byte io0 = (nk_byte)luaL_optinteger(L, 1, 0);
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_color_hsva_bv(&io0, a1);
    lua_pushinteger(L, (lua_Integer)io0);
    return 1;
}

static int GenL_nk_color_hsva_f(lua_State *L)
{
    (void)L;
    float io0 = (float)luaL_optnumber(L, 1, 0);
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    struct nk_color a4;
    GenRead_nk_color(L, 5, &a4);
    nk_color_hsva_f(&io0, &io1, &io2, &io3, a4);
    lua_pushnumber(L, (lua_Number)io0);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    return 4;
}

static int GenL_nk_color_hsva_fv(lua_State *L)
{
    (void)L;
    float io0 = (float)luaL_optnumber(L, 1, 0);
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_color_hsva_fv(&io0, a1);
    lua_pushnumber(L, (lua_Number)io0);
    return 1;
}

static int GenL_nk_color_hsva_i(lua_State *L)
{
    (void)L;
    int io0 = (int)luaL_optinteger(L, 1, 0);
    int io1 = (int)luaL_optinteger(L, 2, 0);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    struct nk_color a4;
    GenRead_nk_color(L, 5, &a4);
    nk_color_hsva_i(&io0, &io1, &io2, &io3, a4);
    lua_pushinteger(L, (lua_Integer)io0);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    return 4;
}

static int GenL_nk_color_hsva_iv(lua_State *L)
{
    (void)L;
    int io0 = (int)luaL_optinteger(L, 1, 0);
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_color_hsva_iv(&io0, a1);
    lua_pushinteger(L, (lua_Integer)io0);
    return 1;
}

static int GenL_nk_color_pick(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_colorf out1;
    memset(&out1, 0, sizeof(out1));
    enum nk_color_format a2 = (enum nk_color_format)luaL_checkinteger(L, 2);
    nk_bool rv = nk_color_pick(a0, &out1, a2);
    lua_pushboolean(L, (int)rv);
    GenPush_nk_colorf(L, &out1);
    return 2;
}

static int GenL_nk_color_picker(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_colorf a1;
    GenRead_nk_colorf(L, 2, &a1);
    enum nk_color_format a2 = (enum nk_color_format)luaL_checkinteger(L, 3);
    struct nk_colorf rv = nk_color_picker(a0, a1, a2);
    GenPush_nk_colorf(L, &rv);
    return 1;
}

static int GenL_nk_color_u32(lua_State *L)
{
    (void)L;
    struct nk_color a0;
    GenRead_nk_color(L, 1, &a0);
    nk_uint rv = nk_color_u32(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_colorf_hsva_f(lua_State *L)
{
    (void)L;
    float io0 = (float)luaL_optnumber(L, 1, 0);
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    struct nk_colorf a4;
    GenRead_nk_colorf(L, 5, &a4);
    nk_colorf_hsva_f(&io0, &io1, &io2, &io3, a4);
    lua_pushnumber(L, (lua_Number)io0);
    lua_pushnumber(L, (lua_Number)io1);
    lua_pushnumber(L, (lua_Number)io2);
    lua_pushnumber(L, (lua_Number)io3);
    return 4;
}

static int GenL_nk_colorf_hsva_fv(lua_State *L)
{
    (void)L;
    float io0 = (float)luaL_optnumber(L, 1, 0);
    struct nk_colorf a1;
    GenRead_nk_colorf(L, 2, &a1);
    nk_colorf_hsva_fv(&io0, a1);
    lua_pushnumber(L, (lua_Number)io0);
    return 1;
}

static int GenL_nk_combo_begin_color(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    nk_bool rv = nk_combo_begin_color(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_combo_begin_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    nk_bool rv = nk_combo_begin_label(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_combo_begin_symbol(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    nk_bool rv = nk_combo_begin_symbol(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_combo_begin_symbol_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    enum nk_symbol_type a2 = (enum nk_symbol_type)luaL_checkinteger(L, 3);
    struct nk_vec2 a3;
    GenRead_nk_vec2(L, 4, &a3);
    nk_bool rv = nk_combo_begin_symbol_label(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_combo_begin_symbol_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    enum nk_symbol_type a3 = (enum nk_symbol_type)luaL_checkinteger(L, 4);
    struct nk_vec2 a4;
    GenRead_nk_vec2(L, 5, &a4);
    nk_bool rv = nk_combo_begin_symbol_text(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_combo_begin_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    struct nk_vec2 a3;
    GenRead_nk_vec2(L, 4, &a3);
    nk_bool rv = nk_combo_begin_text(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_combo_close(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_combo_close(a0);
    return 0;
}

static int GenL_nk_combo_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_combo_end(a0);
    return 0;
}

static int GenL_nk_combo_item_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_flags a2 = (nk_flags)luaL_checkinteger(L, 3);
    nk_bool rv = nk_combo_item_label(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_combo_item_symbol_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool rv = nk_combo_item_symbol_label(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_combo_item_symbol_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool rv = nk_combo_item_symbol_text(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_combo_item_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool rv = nk_combo_item_text(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_combo_separator(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    int a5 = (int)luaL_checkinteger(L, 6);
    struct nk_vec2 a6;
    GenRead_nk_vec2(L, 7, &a6);
    int rv = nk_combo_separator(a0, a1, a2, a3, a4, a5, a6);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_combo_string(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    struct nk_vec2 a5;
    GenRead_nk_vec2(L, 6, &a5);
    int rv = nk_combo_string(a0, a1, a2, a3, a4, a5);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_combobox_separator(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    int a4 = (int)luaL_checkinteger(L, 5);
    int a5 = (int)luaL_checkinteger(L, 6);
    struct nk_vec2 a6;
    GenRead_nk_vec2(L, 7, &a6);
    nk_bool rv = nk_combobox_separator(a0, a1, a2, &io3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io3);
    return 2;
}

static int GenL_nk_combobox_string(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    struct nk_vec2 a5;
    GenRead_nk_vec2(L, 6, &a5);
    nk_bool rv = nk_combobox_string(a0, a1, &io2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_nk_contextual_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_flags a1 = (nk_flags)luaL_checkinteger(L, 2);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    struct nk_rect a3;
    GenRead_nk_rect(L, 4, &a3);
    nk_bool rv = nk_contextual_begin(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_contextual_close(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_contextual_close(a0);
    return 0;
}

static int GenL_nk_contextual_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_contextual_end(a0);
    return 0;
}

static int GenL_nk_contextual_item_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_flags a2 = (nk_flags)luaL_checkinteger(L, 3);
    nk_bool rv = nk_contextual_item_label(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_contextual_item_symbol_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool rv = nk_contextual_item_symbol_label(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_contextual_item_symbol_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool rv = nk_contextual_item_symbol_text(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_contextual_item_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool rv = nk_contextual_item_text(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_convert(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_buffer *a1 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_buffer");
    struct nk_buffer *a2 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 3, "nk_buffer");
    struct nk_buffer *a3 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 4, "nk_buffer");
    const struct nk_convert_config *a4 = (const struct nk_convert_config *)SDLStaticGen_LuaCheckHandle(L, 5, "nk_convert_config");
    nk_flags rv = nk_convert(a0, a1, a2, a3, a4);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_draw_image(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    const struct nk_image *a2 = (const struct nk_image *)SDLStaticGen_LuaCheckHandle(L, 3, "nk_image");
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    nk_draw_image(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_draw_list_add_text(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    const struct nk_user_font *a1 = (const struct nk_user_font *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_user_font");
    struct nk_rect a2;
    GenRead_nk_rect(L, 3, &a2);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    struct nk_color a6;
    GenRead_nk_color(L, 7, &a6);
    nk_draw_list_add_text(a0, a1, a2, a3, a4, a5, a6);
    return 0;
}

static int GenL_nk_draw_list_fill_circle(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    float a2 = (float)luaL_checknumber(L, 3);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    unsigned int a4 = (unsigned int)luaL_checkinteger(L, 5);
    nk_draw_list_fill_circle(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_nk_draw_list_fill_poly_convex(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 tmp1;
    const struct nk_vec2 *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_nk_vec2(L, 2, &tmp1);
        a1 = &tmp1;
    }
    unsigned int a2 = (unsigned int)luaL_checkinteger(L, 3);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    enum nk_anti_aliasing a4 = (enum nk_anti_aliasing)luaL_checkinteger(L, 5);
    nk_draw_list_fill_poly_convex(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_nk_draw_list_fill_rect(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    struct nk_color a2;
    GenRead_nk_color(L, 3, &a2);
    float a3 = (float)luaL_checknumber(L, 4);
    nk_draw_list_fill_rect(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_draw_list_fill_rect_multi_color(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    struct nk_color a2;
    GenRead_nk_color(L, 3, &a2);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    struct nk_color a4;
    GenRead_nk_color(L, 5, &a4);
    struct nk_color a5;
    GenRead_nk_color(L, 6, &a5);
    nk_draw_list_fill_rect_multi_color(a0, a1, a2, a3, a4, a5);
    return 0;
}

static int GenL_nk_draw_list_fill_triangle(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    struct nk_vec2 a3;
    GenRead_nk_vec2(L, 4, &a3);
    struct nk_color a4;
    GenRead_nk_color(L, 5, &a4);
    nk_draw_list_fill_triangle(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_nk_draw_list_init(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    nk_draw_list_init(a0);
    return 0;
}

static int GenL_nk_draw_list_path_arc_to(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    unsigned int a5 = (unsigned int)luaL_checkinteger(L, 6);
    nk_draw_list_path_arc_to(a0, a1, a2, a3, a4, a5);
    return 0;
}

static int GenL_nk_draw_list_path_arc_to_fast(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    float a2 = (float)luaL_checknumber(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    nk_draw_list_path_arc_to_fast(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_nk_draw_list_path_clear(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    nk_draw_list_path_clear(a0);
    return 0;
}

static int GenL_nk_draw_list_path_curve_to(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    struct nk_vec2 a3;
    GenRead_nk_vec2(L, 4, &a3);
    unsigned int a4 = (unsigned int)luaL_checkinteger(L, 5);
    nk_draw_list_path_curve_to(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_nk_draw_list_path_fill(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_draw_list_path_fill(a0, a1);
    return 0;
}

static int GenL_nk_draw_list_path_line_to(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    nk_draw_list_path_line_to(a0, a1);
    return 0;
}

static int GenL_nk_draw_list_path_rect_to(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    float a3 = (float)luaL_checknumber(L, 4);
    nk_draw_list_path_rect_to(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_draw_list_path_stroke(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    enum nk_draw_list_stroke a2 = (enum nk_draw_list_stroke)luaL_checkinteger(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    nk_draw_list_path_stroke(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_draw_list_setup(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    const struct nk_convert_config *a1 = (const struct nk_convert_config *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_convert_config");
    struct nk_buffer *a2 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 3, "nk_buffer");
    struct nk_buffer *a3 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 4, "nk_buffer");
    struct nk_buffer *a4 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 5, "nk_buffer");
    enum nk_anti_aliasing a5 = (enum nk_anti_aliasing)luaL_checkinteger(L, 6);
    enum nk_anti_aliasing a6 = (enum nk_anti_aliasing)luaL_checkinteger(L, 7);
    nk_draw_list_setup(a0, a1, a2, a3, a4, a5, a6);
    return 0;
}

static int GenL_nk_draw_list_stroke_circle(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    float a2 = (float)luaL_checknumber(L, 3);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    unsigned int a4 = (unsigned int)luaL_checkinteger(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    nk_draw_list_stroke_circle(a0, a1, a2, a3, a4, a5);
    return 0;
}

static int GenL_nk_draw_list_stroke_curve(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    struct nk_vec2 a3;
    GenRead_nk_vec2(L, 4, &a3);
    struct nk_vec2 a4;
    GenRead_nk_vec2(L, 5, &a4);
    struct nk_color a5;
    GenRead_nk_color(L, 6, &a5);
    unsigned int a6 = (unsigned int)luaL_checkinteger(L, 7);
    float a7 = (float)luaL_checknumber(L, 8);
    nk_draw_list_stroke_curve(a0, a1, a2, a3, a4, a5, a6, a7);
    return 0;
}

static int GenL_nk_draw_list_stroke_line(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    float a4 = (float)luaL_checknumber(L, 5);
    nk_draw_list_stroke_line(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_nk_draw_list_stroke_poly_line(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 tmp1;
    const struct nk_vec2 *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_nk_vec2(L, 2, &tmp1);
        a1 = &tmp1;
    }
    unsigned int a2 = (unsigned int)luaL_checkinteger(L, 3);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    enum nk_draw_list_stroke a4 = (enum nk_draw_list_stroke)luaL_checkinteger(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    enum nk_anti_aliasing a6 = (enum nk_anti_aliasing)luaL_checkinteger(L, 7);
    nk_draw_list_stroke_poly_line(a0, a1, a2, a3, a4, a5, a6);
    return 0;
}

static int GenL_nk_draw_list_stroke_rect(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    struct nk_color a2;
    GenRead_nk_color(L, 3, &a2);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    nk_draw_list_stroke_rect(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_nk_draw_list_stroke_triangle(lua_State *L)
{
    (void)L;
    struct nk_draw_list *a0 = (struct nk_draw_list *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_draw_list");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    struct nk_vec2 a3;
    GenRead_nk_vec2(L, 4, &a3);
    struct nk_color a4;
    GenRead_nk_color(L, 5, &a4);
    float a5 = (float)luaL_checknumber(L, 6);
    nk_draw_list_stroke_triangle(a0, a1, a2, a3, a4, a5);
    return 0;
}

static int GenL_nk_draw_nine_slice(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    const struct nk_nine_slice *a2 = (const struct nk_nine_slice *)SDLStaticGen_LuaCheckHandle(L, 3, "nk_nine_slice");
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    nk_draw_nine_slice(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_draw_text(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    const struct nk_user_font *a4 = (const struct nk_user_font *)SDLStaticGen_LuaCheckHandle(L, 5, "nk_user_font");
    struct nk_color a5;
    GenRead_nk_color(L, 6, &a5);
    struct nk_color a6;
    GenRead_nk_color(L, 7, &a6);
    nk_draw_text(a0, a1, a2, a3, a4, a5, a6);
    return 0;
}

static int GenL_nk_edit_focus(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_flags a1 = (nk_flags)luaL_checkinteger(L, 2);
    nk_edit_focus(a0, a1);
    return 0;
}

static int GenL_nk_edit_unfocus(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_edit_unfocus(a0);
    return 0;
}

static int GenL_nk_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_end(a0);
    return 0;
}

static int GenL_nk_fill_arc(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    struct nk_color a6;
    GenRead_nk_color(L, 7, &a6);
    nk_fill_arc(a0, a1, a2, a3, a4, a5, a6);
    return 0;
}

static int GenL_nk_fill_circle(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    struct nk_color a2;
    GenRead_nk_color(L, 3, &a2);
    nk_fill_circle(a0, a1, a2);
    return 0;
}

static int GenL_nk_fill_rect(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    float a2 = (float)luaL_checknumber(L, 3);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    nk_fill_rect(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_fill_rect_multi_color(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    struct nk_color a2;
    GenRead_nk_color(L, 3, &a2);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    struct nk_color a4;
    GenRead_nk_color(L, 5, &a4);
    struct nk_color a5;
    GenRead_nk_color(L, 6, &a5);
    nk_fill_rect_multi_color(a0, a1, a2, a3, a4, a5);
    return 0;
}

static int GenL_nk_fill_triangle(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    struct nk_color a7;
    GenRead_nk_color(L, 8, &a7);
    nk_fill_triangle(a0, a1, a2, a3, a4, a5, a6, a7);
    return 0;
}

static int GenL_nk_filter_ascii(lua_State *L)
{
    (void)L;
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_rune a1 = (nk_rune)luaL_checkinteger(L, 2);
    nk_bool rv = nk_filter_ascii(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_filter_binary(lua_State *L)
{
    (void)L;
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_rune a1 = (nk_rune)luaL_checkinteger(L, 2);
    nk_bool rv = nk_filter_binary(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_filter_decimal(lua_State *L)
{
    (void)L;
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_rune a1 = (nk_rune)luaL_checkinteger(L, 2);
    nk_bool rv = nk_filter_decimal(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_filter_default(lua_State *L)
{
    (void)L;
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_rune a1 = (nk_rune)luaL_checkinteger(L, 2);
    nk_bool rv = nk_filter_default(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_filter_float(lua_State *L)
{
    (void)L;
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_rune a1 = (nk_rune)luaL_checkinteger(L, 2);
    nk_bool rv = nk_filter_float(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_filter_hex(lua_State *L)
{
    (void)L;
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_rune a1 = (nk_rune)luaL_checkinteger(L, 2);
    nk_bool rv = nk_filter_hex(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_filter_oct(lua_State *L)
{
    (void)L;
    const struct nk_text_edit *a0 = (const struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_rune a1 = (nk_rune)luaL_checkinteger(L, 2);
    nk_bool rv = nk_filter_oct(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_font_atlas_add(lua_State *L)
{
    (void)L;
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_font_atlas");
    const struct nk_font_config *a1 = (const struct nk_font_config *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_font_config");
    struct nk_font * rv = nk_font_atlas_add(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_font");
    return 1;
}

static int GenL_nk_font_atlas_add_compressed_base85(lua_State *L)
{
    (void)L;
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_font_atlas");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    const struct nk_font_config *a3 = (const struct nk_font_config *)SDLStaticGen_LuaCheckHandle(L, 4, "nk_font_config");
    struct nk_font * rv = nk_font_atlas_add_compressed_base85(a0, a1, a2, a3);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_font");
    return 1;
}

static int GenL_nk_font_atlas_add_default(lua_State *L)
{
    (void)L;
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_font_atlas");
    float a1 = (float)luaL_checknumber(L, 2);
    const struct nk_font_config *a2 = (const struct nk_font_config *)SDLStaticGen_LuaCheckHandle(L, 3, "nk_font_config");
    struct nk_font * rv = nk_font_atlas_add_default(a0, a1, a2);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_font");
    return 1;
}

static int GenL_nk_font_atlas_begin(lua_State *L)
{
    (void)L;
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_font_atlas");
    nk_font_atlas_begin(a0);
    return 0;
}

static int GenL_nk_font_atlas_cleanup(lua_State *L)
{
    (void)L;
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_font_atlas");
    nk_font_atlas_cleanup(a0);
    return 0;
}

static int GenL_nk_font_atlas_clear(lua_State *L)
{
    (void)L;
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_font_atlas");
    nk_font_atlas_clear(a0);
    return 0;
}

static int GenL_nk_font_atlas_init(lua_State *L)
{
    (void)L;
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_font_atlas");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_allocator");
    nk_font_atlas_init(a0, a1);
    return 0;
}

static int GenL_nk_font_atlas_init_custom(lua_State *L)
{
    (void)L;
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_font_atlas");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_allocator");
    const struct nk_allocator *a2 = (const struct nk_allocator *)SDLStaticGen_LuaCheckHandle(L, 3, "nk_allocator");
    nk_font_atlas_init_custom(a0, a1, a2);
    return 0;
}

static int GenL_nk_font_atlas_init_default(lua_State *L)
{
    (void)L;
    struct nk_font_atlas *a0 = (struct nk_font_atlas *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_font_atlas");
    nk_font_atlas_init_default(a0);
    return 0;
}

static int GenL_nk_free(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_free(a0);
    return 0;
}

static int GenL_nk_get_null_rect(lua_State *L)
{
    (void)L;
    struct nk_rect rv = nk_get_null_rect();
    GenPush_nk_rect(L, &rv);
    return 1;
}

static int GenL_nk_group_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_flags a2 = (nk_flags)luaL_checkinteger(L, 3);
    nk_bool rv = nk_group_begin(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_group_begin_titled(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool rv = nk_group_begin_titled(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_group_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_group_end(a0);
    return 0;
}

static int GenL_nk_group_get_scroll(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_uint io2 = (nk_uint)luaL_optinteger(L, 3, 0);
    nk_uint io3 = (nk_uint)luaL_optinteger(L, 4, 0);
    nk_group_get_scroll(a0, a1, &io2, &io3);
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    return 2;
}

static int GenL_nk_group_scrolled_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_scroll out1;
    memset(&out1, 0, sizeof(out1));
    const char *a2 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 3);
    nk_bool rv = nk_group_scrolled_begin(a0, &out1, a2, a3);
    lua_pushboolean(L, (int)rv);
    GenPush_nk_scroll(L, &out1);
    return 2;
}

static int GenL_nk_group_scrolled_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_group_scrolled_end(a0);
    return 0;
}

static int GenL_nk_group_scrolled_offset_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_uint io1 = (nk_uint)luaL_optinteger(L, 2, 0);
    nk_uint io2 = (nk_uint)luaL_optinteger(L, 3, 0);
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checkstring(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool rv = nk_group_scrolled_offset_begin(a0, &io1, &io2, a3, a4);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 3;
}

static int GenL_nk_group_set_scroll(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_uint a2 = (nk_uint)luaL_checkinteger(L, 3);
    nk_uint a3 = (nk_uint)luaL_checkinteger(L, 4);
    nk_group_set_scroll(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_hsv(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    struct nk_color rv = nk_hsv(a0, a1, a2);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_hsv_f(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    struct nk_color rv = nk_hsv_f(a0, a1, a2);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_hsva(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    struct nk_color rv = nk_hsva(a0, a1, a2, a3);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_hsva_colorf(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    struct nk_colorf rv = nk_hsva_colorf(a0, a1, a2, a3);
    GenPush_nk_colorf(L, &rv);
    return 1;
}

static int GenL_nk_hsva_f(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    struct nk_color rv = nk_hsva_f(a0, a1, a2, a3);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_image_is_subimage(lua_State *L)
{
    (void)L;
    const struct nk_image *a0 = (const struct nk_image *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_image");
    nk_bool rv = nk_image_is_subimage(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_init(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_allocator");
    const struct nk_user_font *a2 = (const struct nk_user_font *)SDLStaticGen_LuaCheckHandle(L, 3, "nk_user_font");
    nk_bool rv = nk_init(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_init_custom(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_buffer *a1 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_buffer");
    struct nk_buffer *a2 = (struct nk_buffer *)SDLStaticGen_LuaCheckHandle(L, 3, "nk_buffer");
    const struct nk_user_font *a3 = (const struct nk_user_font *)SDLStaticGen_LuaCheckHandle(L, 4, "nk_user_font");
    nk_bool rv = nk_init_custom(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_init_default(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_user_font *a1 = (const struct nk_user_font *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_user_font");
    nk_bool rv = nk_init_default(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_any_mouse_click_in_rect(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    nk_bool rv = nk_input_any_mouse_click_in_rect(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_input_begin(a0);
    return 0;
}

static int GenL_nk_input_button(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_bool a4 = (nk_bool)lua_toboolean(L, 5);
    nk_input_button(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_nk_input_char(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    char a1 = (char)luaL_checkinteger(L, 2);
    nk_input_char(a0, a1);
    return 0;
}

static int GenL_nk_input_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_input_end(a0);
    return 0;
}

static int GenL_nk_input_has_mouse_click(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    nk_bool rv = nk_input_has_mouse_click(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_has_mouse_click_down_in_rect(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    struct nk_rect a2;
    GenRead_nk_rect(L, 3, &a2);
    nk_bool a3 = (nk_bool)lua_toboolean(L, 4);
    nk_bool rv = nk_input_has_mouse_click_down_in_rect(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_has_mouse_click_in_button_rect(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    struct nk_rect a2;
    GenRead_nk_rect(L, 3, &a2);
    nk_bool rv = nk_input_has_mouse_click_in_button_rect(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_has_mouse_click_in_rect(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    struct nk_rect a2;
    GenRead_nk_rect(L, 3, &a2);
    nk_bool rv = nk_input_has_mouse_click_in_rect(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_is_key_down(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_keys a1 = (enum nk_keys)luaL_checkinteger(L, 2);
    nk_bool rv = nk_input_is_key_down(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_is_key_pressed(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_keys a1 = (enum nk_keys)luaL_checkinteger(L, 2);
    nk_bool rv = nk_input_is_key_pressed(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_is_key_released(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_keys a1 = (enum nk_keys)luaL_checkinteger(L, 2);
    nk_bool rv = nk_input_is_key_released(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_is_mouse_click_down_in_rect(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    struct nk_rect a2;
    GenRead_nk_rect(L, 3, &a2);
    nk_bool a3 = (nk_bool)lua_toboolean(L, 4);
    nk_bool rv = nk_input_is_mouse_click_down_in_rect(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_is_mouse_click_in_rect(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    struct nk_rect a2;
    GenRead_nk_rect(L, 3, &a2);
    nk_bool rv = nk_input_is_mouse_click_in_rect(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_is_mouse_down(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    nk_bool rv = nk_input_is_mouse_down(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_is_mouse_hovering_rect(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    nk_bool rv = nk_input_is_mouse_hovering_rect(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_is_mouse_moved(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    nk_bool rv = nk_input_is_mouse_moved(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_is_mouse_pressed(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    nk_bool rv = nk_input_is_mouse_pressed(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_is_mouse_prev_hovering_rect(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    nk_bool rv = nk_input_is_mouse_prev_hovering_rect(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_is_mouse_released(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    nk_bool rv = nk_input_is_mouse_released(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_key(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_keys a1 = (enum nk_keys)luaL_checkinteger(L, 2);
    nk_bool a2 = (nk_bool)lua_toboolean(L, 3);
    nk_input_key(a0, a1, a2);
    return 0;
}

static int GenL_nk_input_motion(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_input_motion(a0, a1, a2);
    return 0;
}

static int GenL_nk_input_mouse_clicked(lua_State *L)
{
    (void)L;
    const struct nk_input *a0 = (const struct nk_input *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_input");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    struct nk_rect a2;
    GenRead_nk_rect(L, 3, &a2);
    nk_bool rv = nk_input_mouse_clicked(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_input_scroll(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    nk_input_scroll(a0, a1);
    return 0;
}

static int GenL_nk_input_unicode(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_rune a1 = (nk_rune)luaL_checkinteger(L, 2);
    nk_input_unicode(a0, a1);
    return 0;
}

static int GenL_nk_item_is_any_active(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_item_is_any_active(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_knob_float(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    enum nk_heading a5 = (enum nk_heading)luaL_checkinteger(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    nk_bool rv = nk_knob_float(a0, a1, &io2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io2);
    return 2;
}

static int GenL_nk_knob_int(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    int a1 = (int)luaL_checkinteger(L, 2);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    enum nk_heading a5 = (enum nk_heading)luaL_checkinteger(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    nk_bool rv = nk_knob_int(a0, a1, &io2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_nk_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_flags a2 = (nk_flags)luaL_checkinteger(L, 3);
    nk_label(a0, a1, a2);
    return 0;
}

static int GenL_nk_label_colored(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_flags a2 = (nk_flags)luaL_checkinteger(L, 3);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    nk_label_colored(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_label_colored_wrap(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    struct nk_color a2;
    GenRead_nk_color(L, 3, &a2);
    nk_label_colored_wrap(a0, a1, a2);
    return 0;
}

static int GenL_nk_label_wrap(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_label_wrap(a0, a1);
    return 0;
}

static int GenL_nk_layout_ratio_from_pixel(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    float rv = nk_layout_ratio_from_pixel(a0, a1);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_nk_layout_reset_min_row_height(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_layout_reset_min_row_height(a0);
    return 0;
}

static int GenL_nk_layout_row_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_layout_format a1 = (enum nk_layout_format)luaL_checkinteger(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_layout_row_begin(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_layout_row_dynamic(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_layout_row_dynamic(a0, a1, a2);
    return 0;
}

static int GenL_nk_layout_row_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_layout_row_end(a0);
    return 0;
}

static int GenL_nk_layout_row_push(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    nk_layout_row_push(a0, a1);
    return 0;
}

static int GenL_nk_layout_row_static(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_layout_row_static(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_layout_row_template_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    nk_layout_row_template_begin(a0, a1);
    return 0;
}

static int GenL_nk_layout_row_template_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_layout_row_template_end(a0);
    return 0;
}

static int GenL_nk_layout_row_template_push_dynamic(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_layout_row_template_push_dynamic(a0);
    return 0;
}

static int GenL_nk_layout_row_template_push_static(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    nk_layout_row_template_push_static(a0, a1);
    return 0;
}

static int GenL_nk_layout_row_template_push_variable(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    nk_layout_row_template_push_variable(a0, a1);
    return 0;
}

static int GenL_nk_layout_set_min_row_height(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    nk_layout_set_min_row_height(a0, a1);
    return 0;
}

static int GenL_nk_layout_space_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_layout_format a1 = (enum nk_layout_format)luaL_checkinteger(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_layout_space_begin(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_layout_space_bounds(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_rect rv = nk_layout_space_bounds(a0);
    GenPush_nk_rect(L, &rv);
    return 1;
}

static int GenL_nk_layout_space_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_layout_space_end(a0);
    return 0;
}

static int GenL_nk_layout_space_push(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    nk_layout_space_push(a0, a1);
    return 0;
}

static int GenL_nk_layout_space_rect_to_local(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    struct nk_rect rv = nk_layout_space_rect_to_local(a0, a1);
    GenPush_nk_rect(L, &rv);
    return 1;
}

static int GenL_nk_layout_space_rect_to_screen(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    struct nk_rect rv = nk_layout_space_rect_to_screen(a0, a1);
    GenPush_nk_rect(L, &rv);
    return 1;
}

static int GenL_nk_layout_space_to_local(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    struct nk_vec2 rv = nk_layout_space_to_local(a0, a1);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_layout_space_to_screen(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    struct nk_vec2 rv = nk_layout_space_to_screen(a0, a1);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_layout_widget_bounds(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_rect rv = nk_layout_widget_bounds(a0);
    GenPush_nk_rect(L, &rv);
    return 1;
}

static int GenL_nk_list_view_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_list_view *a1 = (struct nk_list_view *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_list_view");
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    int a5 = (int)luaL_checkinteger(L, 6);
    nk_bool rv = nk_list_view_begin(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_list_view_end(lua_State *L)
{
    (void)L;
    struct nk_list_view *a0 = (struct nk_list_view *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_list_view");
    nk_list_view_end(a0);
    return 0;
}

static int GenL_nk_menu_begin_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_flags a2 = (nk_flags)luaL_checkinteger(L, 3);
    struct nk_vec2 a3;
    GenRead_nk_vec2(L, 4, &a3);
    nk_bool rv = nk_menu_begin_label(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_menu_begin_symbol(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    enum nk_symbol_type a2 = (enum nk_symbol_type)luaL_checkinteger(L, 3);
    struct nk_vec2 a3;
    GenRead_nk_vec2(L, 4, &a3);
    nk_bool rv = nk_menu_begin_symbol(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_menu_begin_symbol_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_flags a2 = (nk_flags)luaL_checkinteger(L, 3);
    enum nk_symbol_type a3 = (enum nk_symbol_type)luaL_checkinteger(L, 4);
    struct nk_vec2 a4;
    GenRead_nk_vec2(L, 5, &a4);
    nk_bool rv = nk_menu_begin_symbol_label(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_menu_begin_symbol_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    enum nk_symbol_type a4 = (enum nk_symbol_type)luaL_checkinteger(L, 5);
    struct nk_vec2 a5;
    GenRead_nk_vec2(L, 6, &a5);
    nk_bool rv = nk_menu_begin_symbol_text(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_menu_begin_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    struct nk_vec2 a4;
    GenRead_nk_vec2(L, 5, &a4);
    nk_bool rv = nk_menu_begin_text(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_menu_close(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_menu_close(a0);
    return 0;
}

static int GenL_nk_menu_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_menu_end(a0);
    return 0;
}

static int GenL_nk_menu_item_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_flags a2 = (nk_flags)luaL_checkinteger(L, 3);
    nk_bool rv = nk_menu_item_label(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_menu_item_symbol_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool rv = nk_menu_item_symbol_label(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_menu_item_symbol_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool rv = nk_menu_item_symbol_text(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_menu_item_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool rv = nk_menu_item_text(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_menubar_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_menubar_begin(a0);
    return 0;
}

static int GenL_nk_menubar_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_menubar_end(a0);
    return 0;
}

static int GenL_nk_murmur_hash(lua_State *L)
{
    (void)L;
    size_t len0 = 0;
    const char *a0 = luaL_checklstring(L, 1, &len0);
    nk_hash a2 = (nk_hash)luaL_checkinteger(L, 2);
    nk_hash rv = nk_murmur_hash((const void *)a0, (int)len0, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_nine_slice_is_sub9slice(lua_State *L)
{
    (void)L;
    const struct nk_nine_slice *a0 = (const struct nk_nine_slice *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_nine_slice");
    int rv = nk_nine_slice_is_sub9slice(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_option_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool a2 = (nk_bool)lua_toboolean(L, 3);
    nk_bool rv = nk_option_label(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_option_label_align(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool a2 = (nk_bool)lua_toboolean(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool rv = nk_option_label_align(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_option_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_bool a3 = (nk_bool)lua_toboolean(L, 4);
    nk_bool rv = nk_option_text(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_option_text_align(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_bool a3 = (nk_bool)lua_toboolean(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_flags a5 = (nk_flags)luaL_checkinteger(L, 6);
    nk_bool rv = nk_option_text_align(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_popup_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_popup_type a1 = (enum nk_popup_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    struct nk_rect a4;
    GenRead_nk_rect(L, 5, &a4);
    nk_bool rv = nk_popup_begin(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_popup_close(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_popup_close(a0);
    return 0;
}

static int GenL_nk_popup_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_popup_end(a0);
    return 0;
}

static int GenL_nk_popup_get_scroll(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_uint io1 = (nk_uint)luaL_optinteger(L, 2, 0);
    nk_uint io2 = (nk_uint)luaL_optinteger(L, 3, 0);
    nk_popup_get_scroll(a0, &io1, &io2);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_nk_popup_set_scroll(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_uint a1 = (nk_uint)luaL_checkinteger(L, 2);
    nk_uint a2 = (nk_uint)luaL_checkinteger(L, 3);
    nk_popup_set_scroll(a0, a1, a2);
    return 0;
}

static int GenL_nk_prog(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_size a1 = (nk_size)luaL_checkinteger(L, 2);
    nk_size a2 = (nk_size)luaL_checkinteger(L, 3);
    nk_bool a3 = (nk_bool)lua_toboolean(L, 4);
    nk_size rv = nk_prog(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_progress(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_size io1 = (nk_size)luaL_optinteger(L, 2, 0);
    nk_size a2 = (nk_size)luaL_checkinteger(L, 3);
    nk_bool a3 = (nk_bool)lua_toboolean(L, 4);
    nk_bool rv = nk_progress(a0, &io1, a2, a3);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_nk_property_double(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    double a2 = (double)luaL_checknumber(L, 3);
    double io3 = (double)luaL_optnumber(L, 4, 0);
    double a4 = (double)luaL_checknumber(L, 5);
    double a5 = (double)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    nk_bool rv = nk_property_double(a0, a1, a2, &io3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io3);
    return 2;
}

static int GenL_nk_property_float(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float io3 = (float)luaL_optnumber(L, 4, 0);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    nk_bool rv = nk_property_float(a0, a1, a2, &io3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io3);
    return 2;
}

static int GenL_nk_property_int(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    int a4 = (int)luaL_checkinteger(L, 5);
    int a5 = (int)luaL_checkinteger(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    nk_bool rv = nk_property_int(a0, a1, a2, &io3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io3);
    return 2;
}

static int GenL_nk_propertyd(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    double a2 = (double)luaL_checknumber(L, 3);
    double a3 = (double)luaL_checknumber(L, 4);
    double a4 = (double)luaL_checknumber(L, 5);
    double a5 = (double)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    double rv = nk_propertyd(a0, a1, a2, a3, a4, a5, a6);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_nk_propertyf(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    float rv = nk_propertyf(a0, a1, a2, a3, a4, a5, a6);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_nk_propertyi(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    int a5 = (int)luaL_checkinteger(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    int rv = nk_propertyi(a0, a1, a2, a3, a4, a5, a6);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_push_scissor(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    nk_push_scissor(a0, a1);
    return 0;
}

static int GenL_nk_radio_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool io2 = (nk_bool)lua_toboolean(L, 3);
    nk_bool rv = nk_radio_label(a0, a1, &io2);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io2);
    return 2;
}

static int GenL_nk_radio_label_align(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool io2 = (nk_bool)lua_toboolean(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool rv = nk_radio_label_align(a0, a1, &io2, a3, a4);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io2);
    return 2;
}

static int GenL_nk_radio_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_bool io3 = (nk_bool)lua_toboolean(L, 4);
    nk_bool rv = nk_radio_text(a0, a1, a2, &io3);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io3);
    return 2;
}

static int GenL_nk_radio_text_align(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_bool io3 = (nk_bool)lua_toboolean(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_flags a5 = (nk_flags)luaL_checkinteger(L, 6);
    nk_bool rv = nk_radio_text_align(a0, a1, a2, &io3, a4, a5);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io3);
    return 2;
}

static int GenL_nk_rect(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    struct nk_rect rv = nk_rect(a0, a1, a2, a3);
    GenPush_nk_rect(L, &rv);
    return 1;
}

static int GenL_nk_rect_pos(lua_State *L)
{
    (void)L;
    struct nk_rect a0;
    GenRead_nk_rect(L, 1, &a0);
    struct nk_vec2 rv = nk_rect_pos(a0);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_rect_size(lua_State *L)
{
    (void)L;
    struct nk_rect a0;
    GenRead_nk_rect(L, 1, &a0);
    struct nk_vec2 rv = nk_rect_size(a0);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_recta(lua_State *L)
{
    (void)L;
    struct nk_vec2 a0;
    GenRead_nk_vec2(L, 1, &a0);
    struct nk_vec2 a1;
    GenRead_nk_vec2(L, 2, &a1);
    struct nk_rect rv = nk_recta(a0, a1);
    GenPush_nk_rect(L, &rv);
    return 1;
}

static int GenL_nk_recti(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    struct nk_rect rv = nk_recti(a0, a1, a2, a3);
    GenPush_nk_rect(L, &rv);
    return 1;
}

static int GenL_nk_rgb(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    struct nk_color rv = nk_rgb(a0, a1, a2);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_rgb_cf(lua_State *L)
{
    (void)L;
    struct nk_colorf a0;
    GenRead_nk_colorf(L, 1, &a0);
    struct nk_color rv = nk_rgb_cf(a0);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_rgb_f(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    struct nk_color rv = nk_rgb_f(a0, a1, a2);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_rgb_factor(lua_State *L)
{
    (void)L;
    struct nk_color a0;
    GenRead_nk_color(L, 1, &a0);
    float a1 = (float)luaL_checknumber(L, 2);
    struct nk_color rv = nk_rgb_factor(a0, a1);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_rgb_hex(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    struct nk_color rv = nk_rgb_hex(a0);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_rgba(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    struct nk_color rv = nk_rgba(a0, a1, a2, a3);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_rgba_cf(lua_State *L)
{
    (void)L;
    struct nk_colorf a0;
    GenRead_nk_colorf(L, 1, &a0);
    struct nk_color rv = nk_rgba_cf(a0);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_rgba_f(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    struct nk_color rv = nk_rgba_f(a0, a1, a2, a3);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_rgba_hex(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    struct nk_color rv = nk_rgba_hex(a0);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_rgba_u32(lua_State *L)
{
    (void)L;
    nk_uint a0 = (nk_uint)luaL_checkinteger(L, 1);
    struct nk_color rv = nk_rgba_u32(a0);
    GenPush_nk_color(L, &rv);
    return 1;
}

static int GenL_nk_rule_horizontal(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_color a1;
    GenRead_nk_color(L, 2, &a1);
    nk_bool a2 = (nk_bool)lua_toboolean(L, 3);
    nk_rule_horizontal(a0, a1, a2);
    return 0;
}

static int GenL_nk_select_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_flags a2 = (nk_flags)luaL_checkinteger(L, 3);
    nk_bool a3 = (nk_bool)lua_toboolean(L, 4);
    nk_bool rv = nk_select_label(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_select_symbol_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool a4 = (nk_bool)lua_toboolean(L, 5);
    nk_bool rv = nk_select_symbol_label(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_select_symbol_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool a5 = (nk_bool)lua_toboolean(L, 6);
    nk_bool rv = nk_select_symbol_text(a0, a1, a2, a3, a4, a5);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_select_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool a4 = (nk_bool)lua_toboolean(L, 5);
    nk_bool rv = nk_select_text(a0, a1, a2, a3, a4);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_selectable_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_flags a2 = (nk_flags)luaL_checkinteger(L, 3);
    nk_bool io3 = (nk_bool)lua_toboolean(L, 4);
    nk_bool rv = nk_selectable_label(a0, a1, a2, &io3);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io3);
    return 2;
}

static int GenL_nk_selectable_symbol_label(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool io4 = (nk_bool)lua_toboolean(L, 5);
    nk_bool rv = nk_selectable_symbol_label(a0, a1, a2, a3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io4);
    return 2;
}

static int GenL_nk_selectable_symbol_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_symbol_type a1 = (enum nk_symbol_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_flags a4 = (nk_flags)luaL_checkinteger(L, 5);
    nk_bool io5 = (nk_bool)lua_toboolean(L, 6);
    nk_bool rv = nk_selectable_symbol_text(a0, a1, a2, a3, a4, &io5);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io5);
    return 2;
}

static int GenL_nk_selectable_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_bool io4 = (nk_bool)lua_toboolean(L, 5);
    nk_bool rv = nk_selectable_text(a0, a1, a2, a3, &io4);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io4);
    return 2;
}

static int GenL_nk_slide_float(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float rv = nk_slide_float(a0, a1, a2, a3, a4);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_nk_slide_int(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    int rv = nk_slide_int(a0, a1, a2, a3, a4);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_slider_float(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    float io2 = (float)luaL_optnumber(L, 3, 0);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    nk_bool rv = nk_slider_float(a0, a1, &io2, a3, a4);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io2);
    return 2;
}

static int GenL_nk_slider_int(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    int a1 = (int)luaL_checkinteger(L, 2);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    int a3 = (int)luaL_checkinteger(L, 4);
    int a4 = (int)luaL_checkinteger(L, 5);
    nk_bool rv = nk_slider_int(a0, a1, &io2, a3, a4);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_nk_spacer(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_spacer(a0);
    return 0;
}

static int GenL_nk_spacing(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    int a1 = (int)luaL_checkinteger(L, 2);
    nk_spacing(a0, a1);
    return 0;
}

static int GenL_nk_str_append_str_char(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = nk_str_append_str_char(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_append_str_utf8(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = nk_str_append_str_utf8(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_append_text_char(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int rv = nk_str_append_text_char(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_append_text_utf8(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int rv = nk_str_append_text_utf8(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_at_char_const(lua_State *L)
{
    (void)L;
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char * rv = nk_str_at_char_const(a0, a1);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_nk_str_at_const(lua_State *L)
{
    (void)L;
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    nk_rune io2 = (nk_rune)luaL_optinteger(L, 3, 0);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    const char * rv = nk_str_at_const(a0, a1, &io2, &io3);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    lua_pushinteger(L, (lua_Integer)io2);
    lua_pushinteger(L, (lua_Integer)io3);
    return 3;
}

static int GenL_nk_str_clear(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    nk_str_clear(a0);
    return 0;
}

static int GenL_nk_str_delete_chars(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_str_delete_chars(a0, a1, a2);
    return 0;
}

static int GenL_nk_str_delete_runes(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_str_delete_runes(a0, a1, a2);
    return 0;
}

static int GenL_nk_str_free(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    nk_str_free(a0);
    return 0;
}

static int GenL_nk_str_get_const(lua_State *L)
{
    (void)L;
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    const char * rv = nk_str_get_const(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_nk_str_init(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_allocator");
    nk_size a2 = (nk_size)luaL_checkinteger(L, 3);
    nk_str_init(a0, a1, a2);
    return 0;
}

static int GenL_nk_str_init_default(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    nk_str_init_default(a0);
    return 0;
}

static int GenL_nk_str_insert_at_char(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int rv = nk_str_insert_at_char(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_insert_at_rune(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int rv = nk_str_insert_at_rune(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_insert_str_char(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int rv = nk_str_insert_str_char(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_insert_str_utf8(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int rv = nk_str_insert_str_utf8(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_insert_text_char(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int rv = nk_str_insert_text_char(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_insert_text_utf8(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    int rv = nk_str_insert_text_utf8(a0, a1, a2, a3);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_len(lua_State *L)
{
    (void)L;
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int rv = nk_str_len(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_len_char(lua_State *L)
{
    (void)L;
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int rv = nk_str_len_char(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_str_remove_chars(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    nk_str_remove_chars(a0, a1);
    return 0;
}

static int GenL_nk_str_remove_runes(lua_State *L)
{
    (void)L;
    struct nk_str *a0 = (struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    nk_str_remove_runes(a0, a1);
    return 0;
}

static int GenL_nk_str_rune_at(lua_State *L)
{
    (void)L;
    const struct nk_str *a0 = (const struct nk_str *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_str");
    int a1 = (int)luaL_checkinteger(L, 2);
    nk_rune rv = nk_str_rune_at(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_strfilter(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = nk_strfilter(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_stricmp(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int rv = nk_stricmp(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_stricmpn(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    int rv = nk_stricmpn(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_strlen(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int rv = nk_strlen(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_strmatch_fuzzy_string(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int io2 = (int)luaL_optinteger(L, 3, 0);
    int rv = nk_strmatch_fuzzy_string(a0, a1, &io2);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_nk_strmatch_fuzzy_text(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    int io3 = (int)luaL_optinteger(L, 4, 0);
    int rv = nk_strmatch_fuzzy_text(a0, a1, a2, &io3);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io3);
    return 2;
}

static int GenL_nk_stroke_arc(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    struct nk_color a7;
    GenRead_nk_color(L, 8, &a7);
    nk_stroke_arc(a0, a1, a2, a3, a4, a5, a6, a7);
    return 0;
}

static int GenL_nk_stroke_circle(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    float a2 = (float)luaL_checknumber(L, 3);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    nk_stroke_circle(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_stroke_curve(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    float a7 = (float)luaL_checknumber(L, 8);
    float a8 = (float)luaL_checknumber(L, 9);
    float a9 = (float)luaL_checknumber(L, 10);
    struct nk_color a10;
    GenRead_nk_color(L, 11, &a10);
    nk_stroke_curve(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    return 0;
}

static int GenL_nk_stroke_line(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    struct nk_color a6;
    GenRead_nk_color(L, 7, &a6);
    nk_stroke_line(a0, a1, a2, a3, a4, a5, a6);
    return 0;
}

static int GenL_nk_stroke_rect(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    struct nk_rect a1;
    GenRead_nk_rect(L, 2, &a1);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    struct nk_color a4;
    GenRead_nk_color(L, 5, &a4);
    nk_stroke_rect(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_nk_stroke_triangle(lua_State *L)
{
    (void)L;
    struct nk_command_buffer *a0 = (struct nk_command_buffer *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_command_buffer");
    float a1 = (float)luaL_checknumber(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    float a3 = (float)luaL_checknumber(L, 4);
    float a4 = (float)luaL_checknumber(L, 5);
    float a5 = (float)luaL_checknumber(L, 6);
    float a6 = (float)luaL_checknumber(L, 7);
    float a7 = (float)luaL_checknumber(L, 8);
    struct nk_color a8;
    GenRead_nk_color(L, 9, &a8);
    nk_stroke_triangle(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    return 0;
}

static int GenL_nk_style_default(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_style_default(a0);
    return 0;
}

static int GenL_nk_style_from_table(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_color tmp1;
    const struct nk_color *a1 = NULL;
    if (!lua_isnoneornil(L, 2)) {
        GenRead_nk_color(L, 2, &tmp1);
        a1 = &tmp1;
    }
    nk_style_from_table(a0, a1);
    return 0;
}

static int GenL_nk_style_get_color_by_name(lua_State *L)
{
    (void)L;
    enum nk_style_colors a0 = (enum nk_style_colors)luaL_checkinteger(L, 1);
    const char * rv = nk_style_get_color_by_name(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_nk_style_hide_cursor(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_style_hide_cursor(a0);
    return 0;
}

static int GenL_nk_style_load_all_cursors(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_cursor *a1 = (const struct nk_cursor *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_cursor");
    nk_style_load_all_cursors(a0, a1);
    return 0;
}

static int GenL_nk_style_load_cursor(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_style_cursor a1 = (enum nk_style_cursor)luaL_checkinteger(L, 2);
    const struct nk_cursor *a2 = (const struct nk_cursor *)SDLStaticGen_LuaCheckHandle(L, 3, "nk_cursor");
    nk_style_load_cursor(a0, a1, a2);
    return 0;
}

static int GenL_nk_style_pop_color(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_style_pop_color(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_style_pop_flags(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_style_pop_flags(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_style_pop_float(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_style_pop_float(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_style_pop_font(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_style_pop_font(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_style_pop_style_item(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_style_pop_style_item(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_style_pop_vec2(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_style_pop_vec2(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_style_push_color(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_color out1;
    memset(&out1, 0, sizeof(out1));
    struct nk_color a2;
    GenRead_nk_color(L, 2, &a2);
    nk_bool rv = nk_style_push_color(a0, &out1, a2);
    lua_pushboolean(L, (int)rv);
    GenPush_nk_color(L, &out1);
    return 2;
}

static int GenL_nk_style_push_flags(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_flags io1 = (nk_flags)luaL_optinteger(L, 2, 0);
    nk_flags a2 = (nk_flags)luaL_checkinteger(L, 3);
    nk_bool rv = nk_style_push_flags(a0, &io1, a2);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_nk_style_push_float(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float io1 = (float)luaL_optnumber(L, 2, 0);
    float a2 = (float)luaL_checknumber(L, 3);
    nk_bool rv = nk_style_push_float(a0, &io1, a2);
    lua_pushboolean(L, (int)rv);
    lua_pushnumber(L, (lua_Number)io1);
    return 2;
}

static int GenL_nk_style_push_font(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_user_font *a1 = (const struct nk_user_font *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_user_font");
    nk_bool rv = nk_style_push_font(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_style_push_vec2(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 out1;
    memset(&out1, 0, sizeof(out1));
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 2, &a2);
    nk_bool rv = nk_style_push_vec2(a0, &out1, a2);
    lua_pushboolean(L, (int)rv);
    GenPush_nk_vec2(L, &out1);
    return 2;
}

static int GenL_nk_style_set_cursor(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_style_cursor a1 = (enum nk_style_cursor)luaL_checkinteger(L, 2);
    nk_bool rv = nk_style_set_cursor(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_style_set_font(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const struct nk_user_font *a1 = (const struct nk_user_font *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_user_font");
    nk_style_set_font(a0, a1);
    return 0;
}

static int GenL_nk_style_show_cursor(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_style_show_cursor(a0);
    return 0;
}

static int GenL_nk_text(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    nk_text(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_text_colored(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_flags a3 = (nk_flags)luaL_checkinteger(L, 4);
    struct nk_color a4;
    GenRead_nk_color(L, 5, &a4);
    nk_text_colored(a0, a1, a2, a3, a4);
    return 0;
}

static int GenL_nk_text_wrap(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_text_wrap(a0, a1, a2);
    return 0;
}

static int GenL_nk_text_wrap_colored(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    struct nk_color a3;
    GenRead_nk_color(L, 4, &a3);
    nk_text_wrap_colored(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_textedit_cut(lua_State *L)
{
    (void)L;
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_bool rv = nk_textedit_cut(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_textedit_delete(lua_State *L)
{
    (void)L;
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_textedit_delete(a0, a1, a2);
    return 0;
}

static int GenL_nk_textedit_delete_selection(lua_State *L)
{
    (void)L;
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_textedit_delete_selection(a0);
    return 0;
}

static int GenL_nk_textedit_free(lua_State *L)
{
    (void)L;
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_textedit_free(a0);
    return 0;
}

static int GenL_nk_textedit_init(lua_State *L)
{
    (void)L;
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    const struct nk_allocator *a1 = (const struct nk_allocator *)SDLStaticGen_LuaCheckHandle(L, 2, "nk_allocator");
    nk_size a2 = (nk_size)luaL_checkinteger(L, 3);
    nk_textedit_init(a0, a1, a2);
    return 0;
}

static int GenL_nk_textedit_init_default(lua_State *L)
{
    (void)L;
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_textedit_init_default(a0);
    return 0;
}

static int GenL_nk_textedit_paste(lua_State *L)
{
    (void)L;
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_bool rv = nk_textedit_paste(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_textedit_redo(lua_State *L)
{
    (void)L;
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_textedit_redo(a0);
    return 0;
}

static int GenL_nk_textedit_select_all(lua_State *L)
{
    (void)L;
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_textedit_select_all(a0);
    return 0;
}

static int GenL_nk_textedit_text(lua_State *L)
{
    (void)L;
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_textedit_text(a0, a1, a2);
    return 0;
}

static int GenL_nk_textedit_undo(lua_State *L)
{
    (void)L;
    struct nk_text_edit *a0 = (struct nk_text_edit *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_text_edit");
    nk_textedit_undo(a0);
    return 0;
}

static int GenL_nk_tooltip(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_tooltip(a0, a1);
    return 0;
}

static int GenL_nk_tooltip_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    nk_bool rv = nk_tooltip_begin(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_tooltip_begin_offset(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float a1 = (float)luaL_checknumber(L, 2);
    enum nk_tooltip_pos a2 = (enum nk_tooltip_pos)luaL_checkinteger(L, 3);
    struct nk_vec2 a3;
    GenRead_nk_vec2(L, 4, &a3);
    nk_bool rv = nk_tooltip_begin_offset(a0, a1, a2, a3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_tooltip_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_tooltip_end(a0);
    return 0;
}

static int GenL_nk_tooltip_offset(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    enum nk_tooltip_pos a2 = (enum nk_tooltip_pos)luaL_checkinteger(L, 3);
    struct nk_vec2 a3;
    GenRead_nk_vec2(L, 4, &a3);
    nk_tooltip_offset(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_tree_element_pop(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_tree_element_pop(a0);
    return 0;
}

static int GenL_nk_tree_element_push_hashed(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_tree_type a1 = (enum nk_tree_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    enum nk_collapse_states a3 = (enum nk_collapse_states)luaL_checkinteger(L, 4);
    nk_bool io4 = (nk_bool)lua_toboolean(L, 5);
    const char *a5 = lua_isnoneornil(L, 6) ? NULL : luaL_checkstring(L, 6);
    int a6 = (int)luaL_checkinteger(L, 7);
    int a7 = (int)luaL_checkinteger(L, 8);
    nk_bool rv = nk_tree_element_push_hashed(a0, a1, a2, a3, &io4, a5, a6, a7);
    lua_pushboolean(L, (int)rv);
    lua_pushboolean(L, (int)io4);
    return 2;
}

static int GenL_nk_tree_pop(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_tree_pop(a0);
    return 0;
}

static int GenL_nk_tree_push_hashed(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_tree_type a1 = (enum nk_tree_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    enum nk_collapse_states a3 = (enum nk_collapse_states)luaL_checkinteger(L, 4);
    const char *a4 = lua_isnoneornil(L, 5) ? NULL : luaL_checkstring(L, 5);
    int a5 = (int)luaL_checkinteger(L, 6);
    int a6 = (int)luaL_checkinteger(L, 7);
    nk_bool rv = nk_tree_push_hashed(a0, a1, a2, a3, a4, a5, a6);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_tree_state_pop(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_tree_state_pop(a0);
    return 0;
}

static int GenL_nk_tree_state_push(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_tree_type a1 = (enum nk_tree_type)luaL_checkinteger(L, 2);
    const char *a2 = lua_isnoneornil(L, 3) ? NULL : luaL_checkstring(L, 3);
    enum nk_collapse_states io3 = (enum nk_collapse_states)luaL_optinteger(L, 4, 0);
    nk_bool rv = nk_tree_state_push(a0, a1, a2, &io3);
    lua_pushboolean(L, (int)rv);
    lua_pushinteger(L, (lua_Integer)io3);
    return 2;
}

static int GenL_nk_triangle_from_direction(lua_State *L)
{
    (void)L;
    struct nk_vec2 out0;
    memset(&out0, 0, sizeof(out0));
    struct nk_rect a1;
    GenRead_nk_rect(L, 1, &a1);
    float a2 = (float)luaL_checknumber(L, 2);
    float a3 = (float)luaL_checknumber(L, 3);
    enum nk_heading a4 = (enum nk_heading)luaL_checkinteger(L, 4);
    nk_triangle_from_direction(&out0, a1, a2, a3, a4);
    GenPush_nk_vec2(L, &out0);
    return 1;
}

static int GenL_nk_utf_at(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_rune io3 = (nk_rune)luaL_optinteger(L, 4, 0);
    int io4 = (int)luaL_optinteger(L, 5, 0);
    const char * rv = nk_utf_at(a0, a1, a2, &io3, &io4);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    lua_pushinteger(L, (lua_Integer)io3);
    lua_pushinteger(L, (lua_Integer)io4);
    return 3;
}

static int GenL_nk_utf_decode(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    nk_rune io1 = (nk_rune)luaL_optinteger(L, 2, 0);
    int a2 = (int)luaL_checkinteger(L, 3);
    int rv = nk_utf_decode(a0, &io1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    lua_pushinteger(L, (lua_Integer)io1);
    return 2;
}

static int GenL_nk_utf_encode(lua_State *L)
{
    (void)L;
    nk_rune a0 = (nk_rune)luaL_checkinteger(L, 1);
    const char *src1 = lua_isnoneornil(L, 2) ? "" : luaL_checkstring(L, 2);
    char *a1 = SDL_strdup(src1);
    int a2 = (int)luaL_checkinteger(L, 3);
    int rv = nk_utf_encode(a0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    SDL_free(a1);
    return 1;
}

static int GenL_nk_utf_len(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    int rv = nk_utf_len(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_nk_value_bool(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_value_bool(a0, a1, a2);
    return 0;
}

static int GenL_nk_value_color_byte(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    struct nk_color a2;
    GenRead_nk_color(L, 3, &a2);
    nk_value_color_byte(a0, a1, a2);
    return 0;
}

static int GenL_nk_value_color_float(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    struct nk_color a2;
    GenRead_nk_color(L, 3, &a2);
    nk_value_color_float(a0, a1, a2);
    return 0;
}

static int GenL_nk_value_color_hex(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    struct nk_color a2;
    GenRead_nk_color(L, 3, &a2);
    nk_value_color_hex(a0, a1, a2);
    return 0;
}

static int GenL_nk_value_float(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    float a2 = (float)luaL_checknumber(L, 3);
    nk_value_float(a0, a1, a2);
    return 0;
}

static int GenL_nk_value_int(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    int a2 = (int)luaL_checkinteger(L, 3);
    nk_value_int(a0, a1, a2);
    return 0;
}

static int GenL_nk_value_uint(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    unsigned int a2 = (unsigned int)luaL_checkinteger(L, 3);
    nk_value_uint(a0, a1, a2);
    return 0;
}

static int GenL_nk_vec2(lua_State *L)
{
    (void)L;
    float a0 = (float)luaL_checknumber(L, 1);
    float a1 = (float)luaL_checknumber(L, 2);
    struct nk_vec2 rv = nk_vec2(a0, a1);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_vec2i(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    int a1 = (int)luaL_checkinteger(L, 2);
    struct nk_vec2 rv = nk_vec2i(a0, a1);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_widget(lua_State *L)
{
    (void)L;
    struct nk_rect out0;
    memset(&out0, 0, sizeof(out0));
    const struct nk_context *a1 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_widget_layout_states rv = nk_widget(&out0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_nk_rect(L, &out0);
    return 2;
}

static int GenL_nk_widget_bounds(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_rect rv = nk_widget_bounds(a0);
    GenPush_nk_rect(L, &rv);
    return 1;
}

static int GenL_nk_widget_disable_begin(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_widget_disable_begin(a0);
    return 0;
}

static int GenL_nk_widget_disable_end(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_widget_disable_end(a0);
    return 0;
}

static int GenL_nk_widget_fitting(lua_State *L)
{
    (void)L;
    struct nk_rect out0;
    memset(&out0, 0, sizeof(out0));
    const struct nk_context *a1 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 2, &a2);
    enum nk_widget_layout_states rv = nk_widget_fitting(&out0, a1, a2);
    lua_pushinteger(L, (lua_Integer)rv);
    GenPush_nk_rect(L, &out0);
    return 2;
}

static int GenL_nk_widget_has_mouse_click_down(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    nk_bool a2 = (nk_bool)lua_toboolean(L, 3);
    nk_bool rv = nk_widget_has_mouse_click_down(a0, a1, a2);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_widget_height(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float rv = nk_widget_height(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_nk_widget_is_hovered(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_widget_is_hovered(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_widget_is_mouse_clicked(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    enum nk_buttons a1 = (enum nk_buttons)luaL_checkinteger(L, 2);
    nk_bool rv = nk_widget_is_mouse_clicked(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_widget_position(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 rv = nk_widget_position(a0);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_widget_size(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 rv = nk_widget_size(a0);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_widget_width(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float rv = nk_widget_width(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_nk_window_close(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_window_close(a0, a1);
    return 0;
}

static int GenL_nk_window_collapse(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    enum nk_collapse_states a2 = (enum nk_collapse_states)luaL_checkinteger(L, 3);
    nk_window_collapse(a0, a1, a2);
    return 0;
}

static int GenL_nk_window_collapse_if(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    enum nk_collapse_states a2 = (enum nk_collapse_states)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_window_collapse_if(a0, a1, a2, a3);
    return 0;
}

static int GenL_nk_window_find(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    struct nk_window * rv = nk_window_find(a0, a1);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_window");
    return 1;
}

static int GenL_nk_window_get_bounds(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_rect rv = nk_window_get_bounds(a0);
    GenPush_nk_rect(L, &rv);
    return 1;
}

static int GenL_nk_window_get_canvas(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_command_buffer * rv = nk_window_get_canvas(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_command_buffer");
    return 1;
}

static int GenL_nk_window_get_content_region(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_rect rv = nk_window_get_content_region(a0);
    GenPush_nk_rect(L, &rv);
    return 1;
}

static int GenL_nk_window_get_content_region_max(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 rv = nk_window_get_content_region_max(a0);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_window_get_content_region_min(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 rv = nk_window_get_content_region_min(a0);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_window_get_content_region_size(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 rv = nk_window_get_content_region_size(a0);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_window_get_height(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float rv = nk_window_get_height(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_nk_window_get_panel(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_panel * rv = nk_window_get_panel(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "nk_panel");
    return 1;
}

static int GenL_nk_window_get_position(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 rv = nk_window_get_position(a0);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_window_get_scroll(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_uint io1 = (nk_uint)luaL_optinteger(L, 2, 0);
    nk_uint io2 = (nk_uint)luaL_optinteger(L, 3, 0);
    nk_window_get_scroll(a0, &io1, &io2);
    lua_pushinteger(L, (lua_Integer)io1);
    lua_pushinteger(L, (lua_Integer)io2);
    return 2;
}

static int GenL_nk_window_get_size(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    struct nk_vec2 rv = nk_window_get_size(a0);
    GenPush_nk_vec2(L, &rv);
    return 1;
}

static int GenL_nk_window_get_width(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    float rv = nk_window_get_width(a0);
    lua_pushnumber(L, (lua_Number)rv);
    return 1;
}

static int GenL_nk_window_has_focus(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_window_has_focus(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_window_is_active(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool rv = nk_window_is_active(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_window_is_any_hovered(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_window_is_any_hovered(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_window_is_closed(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool rv = nk_window_is_closed(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_window_is_collapsed(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool rv = nk_window_is_collapsed(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_window_is_hidden(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_bool rv = nk_window_is_hidden(a0, a1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_window_is_hovered(lua_State *L)
{
    (void)L;
    const struct nk_context *a0 = (const struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_bool rv = nk_window_is_hovered(a0);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_nk_window_set_bounds(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    struct nk_rect a2;
    GenRead_nk_rect(L, 3, &a2);
    nk_window_set_bounds(a0, a1, a2);
    return 0;
}

static int GenL_nk_window_set_focus(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    nk_window_set_focus(a0, a1);
    return 0;
}

static int GenL_nk_window_set_position(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    nk_window_set_position(a0, a1, a2);
    return 0;
}

static int GenL_nk_window_set_scroll(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    nk_uint a1 = (nk_uint)luaL_checkinteger(L, 2);
    nk_uint a2 = (nk_uint)luaL_checkinteger(L, 3);
    nk_window_set_scroll(a0, a1, a2);
    return 0;
}

static int GenL_nk_window_set_size(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    struct nk_vec2 a2;
    GenRead_nk_vec2(L, 3, &a2);
    nk_window_set_size(a0, a1, a2);
    return 0;
}

static int GenL_nk_window_show(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    enum nk_show_states a2 = (enum nk_show_states)luaL_checkinteger(L, 3);
    nk_window_show(a0, a1, a2);
    return 0;
}

static int GenL_nk_window_show_if(lua_State *L)
{
    (void)L;
    struct nk_context *a0 = (struct nk_context *)SDLStaticGen_LuaCheckHandle(L, 1, "nk_context");
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checkstring(L, 2);
    enum nk_show_states a2 = (enum nk_show_states)luaL_checkinteger(L, 3);
    int a3 = (int)luaL_checkinteger(L, 4);
    nk_window_show_if(a0, a1, a2, a3);
    return 0;
}

int SDLStaticGen_OpenLua_nk(lua_State *L);
int SDLStaticGen_OpenLua_nk(lua_State *L)
{
    lua_createtable(L, 0, 429);
    lua_pushcfunction(L, GenL_nk__begin);
    lua_setfield(L, -2, "_begin");
    lua_pushcfunction(L, GenL_nk__draw_begin);
    lua_setfield(L, -2, "_draw_begin");
    lua_pushcfunction(L, GenL_nk__draw_end);
    lua_setfield(L, -2, "_draw_end");
    lua_pushcfunction(L, GenL_nk__draw_list_begin);
    lua_setfield(L, -2, "_draw_list_begin");
    lua_pushcfunction(L, GenL_nk__draw_list_end);
    lua_setfield(L, -2, "_draw_list_end");
    lua_pushcfunction(L, GenL_nk__draw_list_next);
    lua_setfield(L, -2, "_draw_list_next");
    lua_pushcfunction(L, GenL_nk__draw_next);
    lua_setfield(L, -2, "_draw_next");
    lua_pushcfunction(L, GenL_nk__next);
    lua_setfield(L, -2, "_next");
    lua_pushcfunction(L, GenL_nk_begin);
    lua_setfield(L, -2, "begin");
    lua_pushcfunction(L, GenL_nk_begin_titled);
    lua_setfield(L, -2, "begin_titled");
    lua_pushcfunction(L, GenL_nk_buffer_clear);
    lua_setfield(L, -2, "buffer_clear");
    lua_pushcfunction(L, GenL_nk_buffer_free);
    lua_setfield(L, -2, "buffer_free");
    lua_pushcfunction(L, GenL_nk_buffer_info);
    lua_setfield(L, -2, "buffer_info");
    lua_pushcfunction(L, GenL_nk_buffer_init);
    lua_setfield(L, -2, "buffer_init");
    lua_pushcfunction(L, GenL_nk_buffer_init_default);
    lua_setfield(L, -2, "buffer_init_default");
    lua_pushcfunction(L, GenL_nk_buffer_mark);
    lua_setfield(L, -2, "buffer_mark");
    lua_pushcfunction(L, GenL_nk_buffer_push);
    lua_setfield(L, -2, "buffer_push");
    lua_pushcfunction(L, GenL_nk_buffer_reset);
    lua_setfield(L, -2, "buffer_reset");
    lua_pushcfunction(L, GenL_nk_buffer_total);
    lua_setfield(L, -2, "buffer_total");
    lua_pushcfunction(L, GenL_nk_button_color);
    lua_setfield(L, -2, "button_color");
    lua_pushcfunction(L, GenL_nk_button_label);
    lua_setfield(L, -2, "button_label");
    lua_pushcfunction(L, GenL_nk_button_label_styled);
    lua_setfield(L, -2, "button_label_styled");
    lua_pushcfunction(L, GenL_nk_button_pop_behavior);
    lua_setfield(L, -2, "button_pop_behavior");
    lua_pushcfunction(L, GenL_nk_button_push_behavior);
    lua_setfield(L, -2, "button_push_behavior");
    lua_pushcfunction(L, GenL_nk_button_set_behavior);
    lua_setfield(L, -2, "button_set_behavior");
    lua_pushcfunction(L, GenL_nk_button_symbol);
    lua_setfield(L, -2, "button_symbol");
    lua_pushcfunction(L, GenL_nk_button_symbol_label);
    lua_setfield(L, -2, "button_symbol_label");
    lua_pushcfunction(L, GenL_nk_button_symbol_label_styled);
    lua_setfield(L, -2, "button_symbol_label_styled");
    lua_pushcfunction(L, GenL_nk_button_symbol_styled);
    lua_setfield(L, -2, "button_symbol_styled");
    lua_pushcfunction(L, GenL_nk_button_symbol_text);
    lua_setfield(L, -2, "button_symbol_text");
    lua_pushcfunction(L, GenL_nk_button_symbol_text_styled);
    lua_setfield(L, -2, "button_symbol_text_styled");
    lua_pushcfunction(L, GenL_nk_button_text);
    lua_setfield(L, -2, "button_text");
    lua_pushcfunction(L, GenL_nk_button_text_styled);
    lua_setfield(L, -2, "button_text_styled");
    lua_pushcfunction(L, GenL_nk_chart_add_slot);
    lua_setfield(L, -2, "chart_add_slot");
    lua_pushcfunction(L, GenL_nk_chart_add_slot_colored);
    lua_setfield(L, -2, "chart_add_slot_colored");
    lua_pushcfunction(L, GenL_nk_chart_begin);
    lua_setfield(L, -2, "chart_begin");
    lua_pushcfunction(L, GenL_nk_chart_begin_colored);
    lua_setfield(L, -2, "chart_begin_colored");
    lua_pushcfunction(L, GenL_nk_chart_end);
    lua_setfield(L, -2, "chart_end");
    lua_pushcfunction(L, GenL_nk_chart_push);
    lua_setfield(L, -2, "chart_push");
    lua_pushcfunction(L, GenL_nk_chart_push_slot);
    lua_setfield(L, -2, "chart_push_slot");
    lua_pushcfunction(L, GenL_nk_check_flags_label);
    lua_setfield(L, -2, "check_flags_label");
    lua_pushcfunction(L, GenL_nk_check_flags_text);
    lua_setfield(L, -2, "check_flags_text");
    lua_pushcfunction(L, GenL_nk_check_label);
    lua_setfield(L, -2, "check_label");
    lua_pushcfunction(L, GenL_nk_check_text);
    lua_setfield(L, -2, "check_text");
    lua_pushcfunction(L, GenL_nk_check_text_align);
    lua_setfield(L, -2, "check_text_align");
    lua_pushcfunction(L, GenL_nk_checkbox_flags_label);
    lua_setfield(L, -2, "checkbox_flags_label");
    lua_pushcfunction(L, GenL_nk_checkbox_flags_text);
    lua_setfield(L, -2, "checkbox_flags_text");
    lua_pushcfunction(L, GenL_nk_checkbox_label);
    lua_setfield(L, -2, "checkbox_label");
    lua_pushcfunction(L, GenL_nk_checkbox_label_align);
    lua_setfield(L, -2, "checkbox_label_align");
    lua_pushcfunction(L, GenL_nk_checkbox_text);
    lua_setfield(L, -2, "checkbox_text");
    lua_pushcfunction(L, GenL_nk_checkbox_text_align);
    lua_setfield(L, -2, "checkbox_text_align");
    lua_pushcfunction(L, GenL_nk_clear);
    lua_setfield(L, -2, "clear");
    lua_pushcfunction(L, GenL_nk_color_cf);
    lua_setfield(L, -2, "color_cf");
    lua_pushcfunction(L, GenL_nk_color_d);
    lua_setfield(L, -2, "color_d");
    lua_pushcfunction(L, GenL_nk_color_dv);
    lua_setfield(L, -2, "color_dv");
    lua_pushcfunction(L, GenL_nk_color_f);
    lua_setfield(L, -2, "color_f");
    lua_pushcfunction(L, GenL_nk_color_fv);
    lua_setfield(L, -2, "color_fv");
    lua_pushcfunction(L, GenL_nk_color_hex_rgb);
    lua_setfield(L, -2, "color_hex_rgb");
    lua_pushcfunction(L, GenL_nk_color_hex_rgba);
    lua_setfield(L, -2, "color_hex_rgba");
    lua_pushcfunction(L, GenL_nk_color_hsv_b);
    lua_setfield(L, -2, "color_hsv_b");
    lua_pushcfunction(L, GenL_nk_color_hsv_bv);
    lua_setfield(L, -2, "color_hsv_bv");
    lua_pushcfunction(L, GenL_nk_color_hsv_f);
    lua_setfield(L, -2, "color_hsv_f");
    lua_pushcfunction(L, GenL_nk_color_hsv_fv);
    lua_setfield(L, -2, "color_hsv_fv");
    lua_pushcfunction(L, GenL_nk_color_hsv_i);
    lua_setfield(L, -2, "color_hsv_i");
    lua_pushcfunction(L, GenL_nk_color_hsv_iv);
    lua_setfield(L, -2, "color_hsv_iv");
    lua_pushcfunction(L, GenL_nk_color_hsva_b);
    lua_setfield(L, -2, "color_hsva_b");
    lua_pushcfunction(L, GenL_nk_color_hsva_bv);
    lua_setfield(L, -2, "color_hsva_bv");
    lua_pushcfunction(L, GenL_nk_color_hsva_f);
    lua_setfield(L, -2, "color_hsva_f");
    lua_pushcfunction(L, GenL_nk_color_hsva_fv);
    lua_setfield(L, -2, "color_hsva_fv");
    lua_pushcfunction(L, GenL_nk_color_hsva_i);
    lua_setfield(L, -2, "color_hsva_i");
    lua_pushcfunction(L, GenL_nk_color_hsva_iv);
    lua_setfield(L, -2, "color_hsva_iv");
    lua_pushcfunction(L, GenL_nk_color_pick);
    lua_setfield(L, -2, "color_pick");
    lua_pushcfunction(L, GenL_nk_color_picker);
    lua_setfield(L, -2, "color_picker");
    lua_pushcfunction(L, GenL_nk_color_u32);
    lua_setfield(L, -2, "color_u32");
    lua_pushcfunction(L, GenL_nk_colorf_hsva_f);
    lua_setfield(L, -2, "colorf_hsva_f");
    lua_pushcfunction(L, GenL_nk_colorf_hsva_fv);
    lua_setfield(L, -2, "colorf_hsva_fv");
    lua_pushcfunction(L, GenL_nk_combo_begin_color);
    lua_setfield(L, -2, "combo_begin_color");
    lua_pushcfunction(L, GenL_nk_combo_begin_label);
    lua_setfield(L, -2, "combo_begin_label");
    lua_pushcfunction(L, GenL_nk_combo_begin_symbol);
    lua_setfield(L, -2, "combo_begin_symbol");
    lua_pushcfunction(L, GenL_nk_combo_begin_symbol_label);
    lua_setfield(L, -2, "combo_begin_symbol_label");
    lua_pushcfunction(L, GenL_nk_combo_begin_symbol_text);
    lua_setfield(L, -2, "combo_begin_symbol_text");
    lua_pushcfunction(L, GenL_nk_combo_begin_text);
    lua_setfield(L, -2, "combo_begin_text");
    lua_pushcfunction(L, GenL_nk_combo_close);
    lua_setfield(L, -2, "combo_close");
    lua_pushcfunction(L, GenL_nk_combo_end);
    lua_setfield(L, -2, "combo_end");
    lua_pushcfunction(L, GenL_nk_combo_item_label);
    lua_setfield(L, -2, "combo_item_label");
    lua_pushcfunction(L, GenL_nk_combo_item_symbol_label);
    lua_setfield(L, -2, "combo_item_symbol_label");
    lua_pushcfunction(L, GenL_nk_combo_item_symbol_text);
    lua_setfield(L, -2, "combo_item_symbol_text");
    lua_pushcfunction(L, GenL_nk_combo_item_text);
    lua_setfield(L, -2, "combo_item_text");
    lua_pushcfunction(L, GenL_nk_combo_separator);
    lua_setfield(L, -2, "combo_separator");
    lua_pushcfunction(L, GenL_nk_combo_string);
    lua_setfield(L, -2, "combo_string");
    lua_pushcfunction(L, GenL_nk_combobox_separator);
    lua_setfield(L, -2, "combobox_separator");
    lua_pushcfunction(L, GenL_nk_combobox_string);
    lua_setfield(L, -2, "combobox_string");
    lua_pushcfunction(L, GenL_nk_contextual_begin);
    lua_setfield(L, -2, "contextual_begin");
    lua_pushcfunction(L, GenL_nk_contextual_close);
    lua_setfield(L, -2, "contextual_close");
    lua_pushcfunction(L, GenL_nk_contextual_end);
    lua_setfield(L, -2, "contextual_end");
    lua_pushcfunction(L, GenL_nk_contextual_item_label);
    lua_setfield(L, -2, "contextual_item_label");
    lua_pushcfunction(L, GenL_nk_contextual_item_symbol_label);
    lua_setfield(L, -2, "contextual_item_symbol_label");
    lua_pushcfunction(L, GenL_nk_contextual_item_symbol_text);
    lua_setfield(L, -2, "contextual_item_symbol_text");
    lua_pushcfunction(L, GenL_nk_contextual_item_text);
    lua_setfield(L, -2, "contextual_item_text");
    lua_pushcfunction(L, GenL_nk_convert);
    lua_setfield(L, -2, "convert");
    lua_pushcfunction(L, GenL_nk_draw_image);
    lua_setfield(L, -2, "draw_image");
    lua_pushcfunction(L, GenL_nk_draw_list_add_text);
    lua_setfield(L, -2, "draw_list_add_text");
    lua_pushcfunction(L, GenL_nk_draw_list_fill_circle);
    lua_setfield(L, -2, "draw_list_fill_circle");
    lua_pushcfunction(L, GenL_nk_draw_list_fill_poly_convex);
    lua_setfield(L, -2, "draw_list_fill_poly_convex");
    lua_pushcfunction(L, GenL_nk_draw_list_fill_rect);
    lua_setfield(L, -2, "draw_list_fill_rect");
    lua_pushcfunction(L, GenL_nk_draw_list_fill_rect_multi_color);
    lua_setfield(L, -2, "draw_list_fill_rect_multi_color");
    lua_pushcfunction(L, GenL_nk_draw_list_fill_triangle);
    lua_setfield(L, -2, "draw_list_fill_triangle");
    lua_pushcfunction(L, GenL_nk_draw_list_init);
    lua_setfield(L, -2, "draw_list_init");
    lua_pushcfunction(L, GenL_nk_draw_list_path_arc_to);
    lua_setfield(L, -2, "draw_list_path_arc_to");
    lua_pushcfunction(L, GenL_nk_draw_list_path_arc_to_fast);
    lua_setfield(L, -2, "draw_list_path_arc_to_fast");
    lua_pushcfunction(L, GenL_nk_draw_list_path_clear);
    lua_setfield(L, -2, "draw_list_path_clear");
    lua_pushcfunction(L, GenL_nk_draw_list_path_curve_to);
    lua_setfield(L, -2, "draw_list_path_curve_to");
    lua_pushcfunction(L, GenL_nk_draw_list_path_fill);
    lua_setfield(L, -2, "draw_list_path_fill");
    lua_pushcfunction(L, GenL_nk_draw_list_path_line_to);
    lua_setfield(L, -2, "draw_list_path_line_to");
    lua_pushcfunction(L, GenL_nk_draw_list_path_rect_to);
    lua_setfield(L, -2, "draw_list_path_rect_to");
    lua_pushcfunction(L, GenL_nk_draw_list_path_stroke);
    lua_setfield(L, -2, "draw_list_path_stroke");
    lua_pushcfunction(L, GenL_nk_draw_list_setup);
    lua_setfield(L, -2, "draw_list_setup");
    lua_pushcfunction(L, GenL_nk_draw_list_stroke_circle);
    lua_setfield(L, -2, "draw_list_stroke_circle");
    lua_pushcfunction(L, GenL_nk_draw_list_stroke_curve);
    lua_setfield(L, -2, "draw_list_stroke_curve");
    lua_pushcfunction(L, GenL_nk_draw_list_stroke_line);
    lua_setfield(L, -2, "draw_list_stroke_line");
    lua_pushcfunction(L, GenL_nk_draw_list_stroke_poly_line);
    lua_setfield(L, -2, "draw_list_stroke_poly_line");
    lua_pushcfunction(L, GenL_nk_draw_list_stroke_rect);
    lua_setfield(L, -2, "draw_list_stroke_rect");
    lua_pushcfunction(L, GenL_nk_draw_list_stroke_triangle);
    lua_setfield(L, -2, "draw_list_stroke_triangle");
    lua_pushcfunction(L, GenL_nk_draw_nine_slice);
    lua_setfield(L, -2, "draw_nine_slice");
    lua_pushcfunction(L, GenL_nk_draw_text);
    lua_setfield(L, -2, "draw_text");
    lua_pushcfunction(L, GenL_nk_edit_focus);
    lua_setfield(L, -2, "edit_focus");
    lua_pushcfunction(L, GenL_nk_edit_unfocus);
    lua_setfield(L, -2, "edit_unfocus");
    lua_pushcfunction(L, GenL_nk_end);
    lua_setfield(L, -2, "end_");
    lua_pushcfunction(L, GenL_nk_fill_arc);
    lua_setfield(L, -2, "fill_arc");
    lua_pushcfunction(L, GenL_nk_fill_circle);
    lua_setfield(L, -2, "fill_circle");
    lua_pushcfunction(L, GenL_nk_fill_rect);
    lua_setfield(L, -2, "fill_rect");
    lua_pushcfunction(L, GenL_nk_fill_rect_multi_color);
    lua_setfield(L, -2, "fill_rect_multi_color");
    lua_pushcfunction(L, GenL_nk_fill_triangle);
    lua_setfield(L, -2, "fill_triangle");
    lua_pushcfunction(L, GenL_nk_filter_ascii);
    lua_setfield(L, -2, "filter_ascii");
    lua_pushcfunction(L, GenL_nk_filter_binary);
    lua_setfield(L, -2, "filter_binary");
    lua_pushcfunction(L, GenL_nk_filter_decimal);
    lua_setfield(L, -2, "filter_decimal");
    lua_pushcfunction(L, GenL_nk_filter_default);
    lua_setfield(L, -2, "filter_default");
    lua_pushcfunction(L, GenL_nk_filter_float);
    lua_setfield(L, -2, "filter_float");
    lua_pushcfunction(L, GenL_nk_filter_hex);
    lua_setfield(L, -2, "filter_hex");
    lua_pushcfunction(L, GenL_nk_filter_oct);
    lua_setfield(L, -2, "filter_oct");
    lua_pushcfunction(L, GenL_nk_font_atlas_add);
    lua_setfield(L, -2, "font_atlas_add");
    lua_pushcfunction(L, GenL_nk_font_atlas_add_compressed_base85);
    lua_setfield(L, -2, "font_atlas_add_compressed_base85");
    lua_pushcfunction(L, GenL_nk_font_atlas_add_default);
    lua_setfield(L, -2, "font_atlas_add_default");
    lua_pushcfunction(L, GenL_nk_font_atlas_begin);
    lua_setfield(L, -2, "font_atlas_begin");
    lua_pushcfunction(L, GenL_nk_font_atlas_cleanup);
    lua_setfield(L, -2, "font_atlas_cleanup");
    lua_pushcfunction(L, GenL_nk_font_atlas_clear);
    lua_setfield(L, -2, "font_atlas_clear");
    lua_pushcfunction(L, GenL_nk_font_atlas_init);
    lua_setfield(L, -2, "font_atlas_init");
    lua_pushcfunction(L, GenL_nk_font_atlas_init_custom);
    lua_setfield(L, -2, "font_atlas_init_custom");
    lua_pushcfunction(L, GenL_nk_font_atlas_init_default);
    lua_setfield(L, -2, "font_atlas_init_default");
    lua_pushcfunction(L, GenL_nk_free);
    lua_setfield(L, -2, "free");
    lua_pushcfunction(L, GenL_nk_get_null_rect);
    lua_setfield(L, -2, "get_null_rect");
    lua_pushcfunction(L, GenL_nk_group_begin);
    lua_setfield(L, -2, "group_begin");
    lua_pushcfunction(L, GenL_nk_group_begin_titled);
    lua_setfield(L, -2, "group_begin_titled");
    lua_pushcfunction(L, GenL_nk_group_end);
    lua_setfield(L, -2, "group_end");
    lua_pushcfunction(L, GenL_nk_group_get_scroll);
    lua_setfield(L, -2, "group_get_scroll");
    lua_pushcfunction(L, GenL_nk_group_scrolled_begin);
    lua_setfield(L, -2, "group_scrolled_begin");
    lua_pushcfunction(L, GenL_nk_group_scrolled_end);
    lua_setfield(L, -2, "group_scrolled_end");
    lua_pushcfunction(L, GenL_nk_group_scrolled_offset_begin);
    lua_setfield(L, -2, "group_scrolled_offset_begin");
    lua_pushcfunction(L, GenL_nk_group_set_scroll);
    lua_setfield(L, -2, "group_set_scroll");
    lua_pushcfunction(L, GenL_nk_hsv);
    lua_setfield(L, -2, "hsv");
    lua_pushcfunction(L, GenL_nk_hsv_f);
    lua_setfield(L, -2, "hsv_f");
    lua_pushcfunction(L, GenL_nk_hsva);
    lua_setfield(L, -2, "hsva");
    lua_pushcfunction(L, GenL_nk_hsva_colorf);
    lua_setfield(L, -2, "hsva_colorf");
    lua_pushcfunction(L, GenL_nk_hsva_f);
    lua_setfield(L, -2, "hsva_f");
    lua_pushcfunction(L, GenL_nk_image_is_subimage);
    lua_setfield(L, -2, "image_is_subimage");
    lua_pushcfunction(L, GenL_nk_init);
    lua_setfield(L, -2, "init");
    lua_pushcfunction(L, GenL_nk_init_custom);
    lua_setfield(L, -2, "init_custom");
    lua_pushcfunction(L, GenL_nk_init_default);
    lua_setfield(L, -2, "init_default");
    lua_pushcfunction(L, GenL_nk_input_any_mouse_click_in_rect);
    lua_setfield(L, -2, "input_any_mouse_click_in_rect");
    lua_pushcfunction(L, GenL_nk_input_begin);
    lua_setfield(L, -2, "input_begin");
    lua_pushcfunction(L, GenL_nk_input_button);
    lua_setfield(L, -2, "input_button");
    lua_pushcfunction(L, GenL_nk_input_char);
    lua_setfield(L, -2, "input_char");
    lua_pushcfunction(L, GenL_nk_input_end);
    lua_setfield(L, -2, "input_end");
    lua_pushcfunction(L, GenL_nk_input_has_mouse_click);
    lua_setfield(L, -2, "input_has_mouse_click");
    lua_pushcfunction(L, GenL_nk_input_has_mouse_click_down_in_rect);
    lua_setfield(L, -2, "input_has_mouse_click_down_in_rect");
    lua_pushcfunction(L, GenL_nk_input_has_mouse_click_in_button_rect);
    lua_setfield(L, -2, "input_has_mouse_click_in_button_rect");
    lua_pushcfunction(L, GenL_nk_input_has_mouse_click_in_rect);
    lua_setfield(L, -2, "input_has_mouse_click_in_rect");
    lua_pushcfunction(L, GenL_nk_input_is_key_down);
    lua_setfield(L, -2, "input_is_key_down");
    lua_pushcfunction(L, GenL_nk_input_is_key_pressed);
    lua_setfield(L, -2, "input_is_key_pressed");
    lua_pushcfunction(L, GenL_nk_input_is_key_released);
    lua_setfield(L, -2, "input_is_key_released");
    lua_pushcfunction(L, GenL_nk_input_is_mouse_click_down_in_rect);
    lua_setfield(L, -2, "input_is_mouse_click_down_in_rect");
    lua_pushcfunction(L, GenL_nk_input_is_mouse_click_in_rect);
    lua_setfield(L, -2, "input_is_mouse_click_in_rect");
    lua_pushcfunction(L, GenL_nk_input_is_mouse_down);
    lua_setfield(L, -2, "input_is_mouse_down");
    lua_pushcfunction(L, GenL_nk_input_is_mouse_hovering_rect);
    lua_setfield(L, -2, "input_is_mouse_hovering_rect");
    lua_pushcfunction(L, GenL_nk_input_is_mouse_moved);
    lua_setfield(L, -2, "input_is_mouse_moved");
    lua_pushcfunction(L, GenL_nk_input_is_mouse_pressed);
    lua_setfield(L, -2, "input_is_mouse_pressed");
    lua_pushcfunction(L, GenL_nk_input_is_mouse_prev_hovering_rect);
    lua_setfield(L, -2, "input_is_mouse_prev_hovering_rect");
    lua_pushcfunction(L, GenL_nk_input_is_mouse_released);
    lua_setfield(L, -2, "input_is_mouse_released");
    lua_pushcfunction(L, GenL_nk_input_key);
    lua_setfield(L, -2, "input_key");
    lua_pushcfunction(L, GenL_nk_input_motion);
    lua_setfield(L, -2, "input_motion");
    lua_pushcfunction(L, GenL_nk_input_mouse_clicked);
    lua_setfield(L, -2, "input_mouse_clicked");
    lua_pushcfunction(L, GenL_nk_input_scroll);
    lua_setfield(L, -2, "input_scroll");
    lua_pushcfunction(L, GenL_nk_input_unicode);
    lua_setfield(L, -2, "input_unicode");
    lua_pushcfunction(L, GenL_nk_item_is_any_active);
    lua_setfield(L, -2, "item_is_any_active");
    lua_pushcfunction(L, GenL_nk_knob_float);
    lua_setfield(L, -2, "knob_float");
    lua_pushcfunction(L, GenL_nk_knob_int);
    lua_setfield(L, -2, "knob_int");
    lua_pushcfunction(L, GenL_nk_label);
    lua_setfield(L, -2, "label");
    lua_pushcfunction(L, GenL_nk_label_colored);
    lua_setfield(L, -2, "label_colored");
    lua_pushcfunction(L, GenL_nk_label_colored_wrap);
    lua_setfield(L, -2, "label_colored_wrap");
    lua_pushcfunction(L, GenL_nk_label_wrap);
    lua_setfield(L, -2, "label_wrap");
    lua_pushcfunction(L, GenL_nk_layout_ratio_from_pixel);
    lua_setfield(L, -2, "layout_ratio_from_pixel");
    lua_pushcfunction(L, GenL_nk_layout_reset_min_row_height);
    lua_setfield(L, -2, "layout_reset_min_row_height");
    lua_pushcfunction(L, GenL_nk_layout_row_begin);
    lua_setfield(L, -2, "layout_row_begin");
    lua_pushcfunction(L, GenL_nk_layout_row_dynamic);
    lua_setfield(L, -2, "layout_row_dynamic");
    lua_pushcfunction(L, GenL_nk_layout_row_end);
    lua_setfield(L, -2, "layout_row_end");
    lua_pushcfunction(L, GenL_nk_layout_row_push);
    lua_setfield(L, -2, "layout_row_push");
    lua_pushcfunction(L, GenL_nk_layout_row_static);
    lua_setfield(L, -2, "layout_row_static");
    lua_pushcfunction(L, GenL_nk_layout_row_template_begin);
    lua_setfield(L, -2, "layout_row_template_begin");
    lua_pushcfunction(L, GenL_nk_layout_row_template_end);
    lua_setfield(L, -2, "layout_row_template_end");
    lua_pushcfunction(L, GenL_nk_layout_row_template_push_dynamic);
    lua_setfield(L, -2, "layout_row_template_push_dynamic");
    lua_pushcfunction(L, GenL_nk_layout_row_template_push_static);
    lua_setfield(L, -2, "layout_row_template_push_static");
    lua_pushcfunction(L, GenL_nk_layout_row_template_push_variable);
    lua_setfield(L, -2, "layout_row_template_push_variable");
    lua_pushcfunction(L, GenL_nk_layout_set_min_row_height);
    lua_setfield(L, -2, "layout_set_min_row_height");
    lua_pushcfunction(L, GenL_nk_layout_space_begin);
    lua_setfield(L, -2, "layout_space_begin");
    lua_pushcfunction(L, GenL_nk_layout_space_bounds);
    lua_setfield(L, -2, "layout_space_bounds");
    lua_pushcfunction(L, GenL_nk_layout_space_end);
    lua_setfield(L, -2, "layout_space_end");
    lua_pushcfunction(L, GenL_nk_layout_space_push);
    lua_setfield(L, -2, "layout_space_push");
    lua_pushcfunction(L, GenL_nk_layout_space_rect_to_local);
    lua_setfield(L, -2, "layout_space_rect_to_local");
    lua_pushcfunction(L, GenL_nk_layout_space_rect_to_screen);
    lua_setfield(L, -2, "layout_space_rect_to_screen");
    lua_pushcfunction(L, GenL_nk_layout_space_to_local);
    lua_setfield(L, -2, "layout_space_to_local");
    lua_pushcfunction(L, GenL_nk_layout_space_to_screen);
    lua_setfield(L, -2, "layout_space_to_screen");
    lua_pushcfunction(L, GenL_nk_layout_widget_bounds);
    lua_setfield(L, -2, "layout_widget_bounds");
    lua_pushcfunction(L, GenL_nk_list_view_begin);
    lua_setfield(L, -2, "list_view_begin");
    lua_pushcfunction(L, GenL_nk_list_view_end);
    lua_setfield(L, -2, "list_view_end");
    lua_pushcfunction(L, GenL_nk_menu_begin_label);
    lua_setfield(L, -2, "menu_begin_label");
    lua_pushcfunction(L, GenL_nk_menu_begin_symbol);
    lua_setfield(L, -2, "menu_begin_symbol");
    lua_pushcfunction(L, GenL_nk_menu_begin_symbol_label);
    lua_setfield(L, -2, "menu_begin_symbol_label");
    lua_pushcfunction(L, GenL_nk_menu_begin_symbol_text);
    lua_setfield(L, -2, "menu_begin_symbol_text");
    lua_pushcfunction(L, GenL_nk_menu_begin_text);
    lua_setfield(L, -2, "menu_begin_text");
    lua_pushcfunction(L, GenL_nk_menu_close);
    lua_setfield(L, -2, "menu_close");
    lua_pushcfunction(L, GenL_nk_menu_end);
    lua_setfield(L, -2, "menu_end");
    lua_pushcfunction(L, GenL_nk_menu_item_label);
    lua_setfield(L, -2, "menu_item_label");
    lua_pushcfunction(L, GenL_nk_menu_item_symbol_label);
    lua_setfield(L, -2, "menu_item_symbol_label");
    lua_pushcfunction(L, GenL_nk_menu_item_symbol_text);
    lua_setfield(L, -2, "menu_item_symbol_text");
    lua_pushcfunction(L, GenL_nk_menu_item_text);
    lua_setfield(L, -2, "menu_item_text");
    lua_pushcfunction(L, GenL_nk_menubar_begin);
    lua_setfield(L, -2, "menubar_begin");
    lua_pushcfunction(L, GenL_nk_menubar_end);
    lua_setfield(L, -2, "menubar_end");
    lua_pushcfunction(L, GenL_nk_murmur_hash);
    lua_setfield(L, -2, "murmur_hash");
    lua_pushcfunction(L, GenL_nk_nine_slice_is_sub9slice);
    lua_setfield(L, -2, "nine_slice_is_sub9slice");
    lua_pushcfunction(L, GenL_nk_option_label);
    lua_setfield(L, -2, "option_label");
    lua_pushcfunction(L, GenL_nk_option_label_align);
    lua_setfield(L, -2, "option_label_align");
    lua_pushcfunction(L, GenL_nk_option_text);
    lua_setfield(L, -2, "option_text");
    lua_pushcfunction(L, GenL_nk_option_text_align);
    lua_setfield(L, -2, "option_text_align");
    lua_pushcfunction(L, GenL_nk_popup_begin);
    lua_setfield(L, -2, "popup_begin");
    lua_pushcfunction(L, GenL_nk_popup_close);
    lua_setfield(L, -2, "popup_close");
    lua_pushcfunction(L, GenL_nk_popup_end);
    lua_setfield(L, -2, "popup_end");
    lua_pushcfunction(L, GenL_nk_popup_get_scroll);
    lua_setfield(L, -2, "popup_get_scroll");
    lua_pushcfunction(L, GenL_nk_popup_set_scroll);
    lua_setfield(L, -2, "popup_set_scroll");
    lua_pushcfunction(L, GenL_nk_prog);
    lua_setfield(L, -2, "prog");
    lua_pushcfunction(L, GenL_nk_progress);
    lua_setfield(L, -2, "progress");
    lua_pushcfunction(L, GenL_nk_property_double);
    lua_setfield(L, -2, "property_double");
    lua_pushcfunction(L, GenL_nk_property_float);
    lua_setfield(L, -2, "property_float");
    lua_pushcfunction(L, GenL_nk_property_int);
    lua_setfield(L, -2, "property_int");
    lua_pushcfunction(L, GenL_nk_propertyd);
    lua_setfield(L, -2, "propertyd");
    lua_pushcfunction(L, GenL_nk_propertyf);
    lua_setfield(L, -2, "propertyf");
    lua_pushcfunction(L, GenL_nk_propertyi);
    lua_setfield(L, -2, "propertyi");
    lua_pushcfunction(L, GenL_nk_push_scissor);
    lua_setfield(L, -2, "push_scissor");
    lua_pushcfunction(L, GenL_nk_radio_label);
    lua_setfield(L, -2, "radio_label");
    lua_pushcfunction(L, GenL_nk_radio_label_align);
    lua_setfield(L, -2, "radio_label_align");
    lua_pushcfunction(L, GenL_nk_radio_text);
    lua_setfield(L, -2, "radio_text");
    lua_pushcfunction(L, GenL_nk_radio_text_align);
    lua_setfield(L, -2, "radio_text_align");
    lua_pushcfunction(L, GenL_nk_rect);
    lua_setfield(L, -2, "rect");
    lua_pushcfunction(L, GenL_nk_rect_pos);
    lua_setfield(L, -2, "rect_pos");
    lua_pushcfunction(L, GenL_nk_rect_size);
    lua_setfield(L, -2, "rect_size");
    lua_pushcfunction(L, GenL_nk_recta);
    lua_setfield(L, -2, "recta");
    lua_pushcfunction(L, GenL_nk_recti);
    lua_setfield(L, -2, "recti");
    lua_pushcfunction(L, GenL_nk_rgb);
    lua_setfield(L, -2, "rgb");
    lua_pushcfunction(L, GenL_nk_rgb_cf);
    lua_setfield(L, -2, "rgb_cf");
    lua_pushcfunction(L, GenL_nk_rgb_f);
    lua_setfield(L, -2, "rgb_f");
    lua_pushcfunction(L, GenL_nk_rgb_factor);
    lua_setfield(L, -2, "rgb_factor");
    lua_pushcfunction(L, GenL_nk_rgb_hex);
    lua_setfield(L, -2, "rgb_hex");
    lua_pushcfunction(L, GenL_nk_rgba);
    lua_setfield(L, -2, "rgba");
    lua_pushcfunction(L, GenL_nk_rgba_cf);
    lua_setfield(L, -2, "rgba_cf");
    lua_pushcfunction(L, GenL_nk_rgba_f);
    lua_setfield(L, -2, "rgba_f");
    lua_pushcfunction(L, GenL_nk_rgba_hex);
    lua_setfield(L, -2, "rgba_hex");
    lua_pushcfunction(L, GenL_nk_rgba_u32);
    lua_setfield(L, -2, "rgba_u32");
    lua_pushcfunction(L, GenL_nk_rule_horizontal);
    lua_setfield(L, -2, "rule_horizontal");
    lua_pushcfunction(L, GenL_nk_select_label);
    lua_setfield(L, -2, "select_label");
    lua_pushcfunction(L, GenL_nk_select_symbol_label);
    lua_setfield(L, -2, "select_symbol_label");
    lua_pushcfunction(L, GenL_nk_select_symbol_text);
    lua_setfield(L, -2, "select_symbol_text");
    lua_pushcfunction(L, GenL_nk_select_text);
    lua_setfield(L, -2, "select_text");
    lua_pushcfunction(L, GenL_nk_selectable_label);
    lua_setfield(L, -2, "selectable_label");
    lua_pushcfunction(L, GenL_nk_selectable_symbol_label);
    lua_setfield(L, -2, "selectable_symbol_label");
    lua_pushcfunction(L, GenL_nk_selectable_symbol_text);
    lua_setfield(L, -2, "selectable_symbol_text");
    lua_pushcfunction(L, GenL_nk_selectable_text);
    lua_setfield(L, -2, "selectable_text");
    lua_pushcfunction(L, GenL_nk_slide_float);
    lua_setfield(L, -2, "slide_float");
    lua_pushcfunction(L, GenL_nk_slide_int);
    lua_setfield(L, -2, "slide_int");
    lua_pushcfunction(L, GenL_nk_slider_float);
    lua_setfield(L, -2, "slider_float");
    lua_pushcfunction(L, GenL_nk_slider_int);
    lua_setfield(L, -2, "slider_int");
    lua_pushcfunction(L, GenL_nk_spacer);
    lua_setfield(L, -2, "spacer");
    lua_pushcfunction(L, GenL_nk_spacing);
    lua_setfield(L, -2, "spacing");
    lua_pushcfunction(L, GenL_nk_str_append_str_char);
    lua_setfield(L, -2, "str_append_str_char");
    lua_pushcfunction(L, GenL_nk_str_append_str_utf8);
    lua_setfield(L, -2, "str_append_str_utf8");
    lua_pushcfunction(L, GenL_nk_str_append_text_char);
    lua_setfield(L, -2, "str_append_text_char");
    lua_pushcfunction(L, GenL_nk_str_append_text_utf8);
    lua_setfield(L, -2, "str_append_text_utf8");
    lua_pushcfunction(L, GenL_nk_str_at_char_const);
    lua_setfield(L, -2, "str_at_char_const");
    lua_pushcfunction(L, GenL_nk_str_at_const);
    lua_setfield(L, -2, "str_at_const");
    lua_pushcfunction(L, GenL_nk_str_clear);
    lua_setfield(L, -2, "str_clear");
    lua_pushcfunction(L, GenL_nk_str_delete_chars);
    lua_setfield(L, -2, "str_delete_chars");
    lua_pushcfunction(L, GenL_nk_str_delete_runes);
    lua_setfield(L, -2, "str_delete_runes");
    lua_pushcfunction(L, GenL_nk_str_free);
    lua_setfield(L, -2, "str_free");
    lua_pushcfunction(L, GenL_nk_str_get_const);
    lua_setfield(L, -2, "str_get_const");
    lua_pushcfunction(L, GenL_nk_str_init);
    lua_setfield(L, -2, "str_init");
    lua_pushcfunction(L, GenL_nk_str_init_default);
    lua_setfield(L, -2, "str_init_default");
    lua_pushcfunction(L, GenL_nk_str_insert_at_char);
    lua_setfield(L, -2, "str_insert_at_char");
    lua_pushcfunction(L, GenL_nk_str_insert_at_rune);
    lua_setfield(L, -2, "str_insert_at_rune");
    lua_pushcfunction(L, GenL_nk_str_insert_str_char);
    lua_setfield(L, -2, "str_insert_str_char");
    lua_pushcfunction(L, GenL_nk_str_insert_str_utf8);
    lua_setfield(L, -2, "str_insert_str_utf8");
    lua_pushcfunction(L, GenL_nk_str_insert_text_char);
    lua_setfield(L, -2, "str_insert_text_char");
    lua_pushcfunction(L, GenL_nk_str_insert_text_utf8);
    lua_setfield(L, -2, "str_insert_text_utf8");
    lua_pushcfunction(L, GenL_nk_str_len);
    lua_setfield(L, -2, "str_len");
    lua_pushcfunction(L, GenL_nk_str_len_char);
    lua_setfield(L, -2, "str_len_char");
    lua_pushcfunction(L, GenL_nk_str_remove_chars);
    lua_setfield(L, -2, "str_remove_chars");
    lua_pushcfunction(L, GenL_nk_str_remove_runes);
    lua_setfield(L, -2, "str_remove_runes");
    lua_pushcfunction(L, GenL_nk_str_rune_at);
    lua_setfield(L, -2, "str_rune_at");
    lua_pushcfunction(L, GenL_nk_strfilter);
    lua_setfield(L, -2, "strfilter");
    lua_pushcfunction(L, GenL_nk_stricmp);
    lua_setfield(L, -2, "stricmp");
    lua_pushcfunction(L, GenL_nk_stricmpn);
    lua_setfield(L, -2, "stricmpn");
    lua_pushcfunction(L, GenL_nk_strlen);
    lua_setfield(L, -2, "strlen");
    lua_pushcfunction(L, GenL_nk_strmatch_fuzzy_string);
    lua_setfield(L, -2, "strmatch_fuzzy_string");
    lua_pushcfunction(L, GenL_nk_strmatch_fuzzy_text);
    lua_setfield(L, -2, "strmatch_fuzzy_text");
    lua_pushcfunction(L, GenL_nk_stroke_arc);
    lua_setfield(L, -2, "stroke_arc");
    lua_pushcfunction(L, GenL_nk_stroke_circle);
    lua_setfield(L, -2, "stroke_circle");
    lua_pushcfunction(L, GenL_nk_stroke_curve);
    lua_setfield(L, -2, "stroke_curve");
    lua_pushcfunction(L, GenL_nk_stroke_line);
    lua_setfield(L, -2, "stroke_line");
    lua_pushcfunction(L, GenL_nk_stroke_rect);
    lua_setfield(L, -2, "stroke_rect");
    lua_pushcfunction(L, GenL_nk_stroke_triangle);
    lua_setfield(L, -2, "stroke_triangle");
    lua_pushcfunction(L, GenL_nk_style_default);
    lua_setfield(L, -2, "style_default");
    lua_pushcfunction(L, GenL_nk_style_from_table);
    lua_setfield(L, -2, "style_from_table");
    lua_pushcfunction(L, GenL_nk_style_get_color_by_name);
    lua_setfield(L, -2, "style_get_color_by_name");
    lua_pushcfunction(L, GenL_nk_style_hide_cursor);
    lua_setfield(L, -2, "style_hide_cursor");
    lua_pushcfunction(L, GenL_nk_style_load_all_cursors);
    lua_setfield(L, -2, "style_load_all_cursors");
    lua_pushcfunction(L, GenL_nk_style_load_cursor);
    lua_setfield(L, -2, "style_load_cursor");
    lua_pushcfunction(L, GenL_nk_style_pop_color);
    lua_setfield(L, -2, "style_pop_color");
    lua_pushcfunction(L, GenL_nk_style_pop_flags);
    lua_setfield(L, -2, "style_pop_flags");
    lua_pushcfunction(L, GenL_nk_style_pop_float);
    lua_setfield(L, -2, "style_pop_float");
    lua_pushcfunction(L, GenL_nk_style_pop_font);
    lua_setfield(L, -2, "style_pop_font");
    lua_pushcfunction(L, GenL_nk_style_pop_style_item);
    lua_setfield(L, -2, "style_pop_style_item");
    lua_pushcfunction(L, GenL_nk_style_pop_vec2);
    lua_setfield(L, -2, "style_pop_vec2");
    lua_pushcfunction(L, GenL_nk_style_push_color);
    lua_setfield(L, -2, "style_push_color");
    lua_pushcfunction(L, GenL_nk_style_push_flags);
    lua_setfield(L, -2, "style_push_flags");
    lua_pushcfunction(L, GenL_nk_style_push_float);
    lua_setfield(L, -2, "style_push_float");
    lua_pushcfunction(L, GenL_nk_style_push_font);
    lua_setfield(L, -2, "style_push_font");
    lua_pushcfunction(L, GenL_nk_style_push_vec2);
    lua_setfield(L, -2, "style_push_vec2");
    lua_pushcfunction(L, GenL_nk_style_set_cursor);
    lua_setfield(L, -2, "style_set_cursor");
    lua_pushcfunction(L, GenL_nk_style_set_font);
    lua_setfield(L, -2, "style_set_font");
    lua_pushcfunction(L, GenL_nk_style_show_cursor);
    lua_setfield(L, -2, "style_show_cursor");
    lua_pushcfunction(L, GenL_nk_text);
    lua_setfield(L, -2, "text");
    lua_pushcfunction(L, GenL_nk_text_colored);
    lua_setfield(L, -2, "text_colored");
    lua_pushcfunction(L, GenL_nk_text_wrap);
    lua_setfield(L, -2, "text_wrap");
    lua_pushcfunction(L, GenL_nk_text_wrap_colored);
    lua_setfield(L, -2, "text_wrap_colored");
    lua_pushcfunction(L, GenL_nk_textedit_cut);
    lua_setfield(L, -2, "textedit_cut");
    lua_pushcfunction(L, GenL_nk_textedit_delete);
    lua_setfield(L, -2, "textedit_delete");
    lua_pushcfunction(L, GenL_nk_textedit_delete_selection);
    lua_setfield(L, -2, "textedit_delete_selection");
    lua_pushcfunction(L, GenL_nk_textedit_free);
    lua_setfield(L, -2, "textedit_free");
    lua_pushcfunction(L, GenL_nk_textedit_init);
    lua_setfield(L, -2, "textedit_init");
    lua_pushcfunction(L, GenL_nk_textedit_init_default);
    lua_setfield(L, -2, "textedit_init_default");
    lua_pushcfunction(L, GenL_nk_textedit_paste);
    lua_setfield(L, -2, "textedit_paste");
    lua_pushcfunction(L, GenL_nk_textedit_redo);
    lua_setfield(L, -2, "textedit_redo");
    lua_pushcfunction(L, GenL_nk_textedit_select_all);
    lua_setfield(L, -2, "textedit_select_all");
    lua_pushcfunction(L, GenL_nk_textedit_text);
    lua_setfield(L, -2, "textedit_text");
    lua_pushcfunction(L, GenL_nk_textedit_undo);
    lua_setfield(L, -2, "textedit_undo");
    lua_pushcfunction(L, GenL_nk_tooltip);
    lua_setfield(L, -2, "tooltip");
    lua_pushcfunction(L, GenL_nk_tooltip_begin);
    lua_setfield(L, -2, "tooltip_begin");
    lua_pushcfunction(L, GenL_nk_tooltip_begin_offset);
    lua_setfield(L, -2, "tooltip_begin_offset");
    lua_pushcfunction(L, GenL_nk_tooltip_end);
    lua_setfield(L, -2, "tooltip_end");
    lua_pushcfunction(L, GenL_nk_tooltip_offset);
    lua_setfield(L, -2, "tooltip_offset");
    lua_pushcfunction(L, GenL_nk_tree_element_pop);
    lua_setfield(L, -2, "tree_element_pop");
    lua_pushcfunction(L, GenL_nk_tree_element_push_hashed);
    lua_setfield(L, -2, "tree_element_push_hashed");
    lua_pushcfunction(L, GenL_nk_tree_pop);
    lua_setfield(L, -2, "tree_pop");
    lua_pushcfunction(L, GenL_nk_tree_push_hashed);
    lua_setfield(L, -2, "tree_push_hashed");
    lua_pushcfunction(L, GenL_nk_tree_state_pop);
    lua_setfield(L, -2, "tree_state_pop");
    lua_pushcfunction(L, GenL_nk_tree_state_push);
    lua_setfield(L, -2, "tree_state_push");
    lua_pushcfunction(L, GenL_nk_triangle_from_direction);
    lua_setfield(L, -2, "triangle_from_direction");
    lua_pushcfunction(L, GenL_nk_utf_at);
    lua_setfield(L, -2, "utf_at");
    lua_pushcfunction(L, GenL_nk_utf_decode);
    lua_setfield(L, -2, "utf_decode");
    lua_pushcfunction(L, GenL_nk_utf_encode);
    lua_setfield(L, -2, "utf_encode");
    lua_pushcfunction(L, GenL_nk_utf_len);
    lua_setfield(L, -2, "utf_len");
    lua_pushcfunction(L, GenL_nk_value_bool);
    lua_setfield(L, -2, "value_bool");
    lua_pushcfunction(L, GenL_nk_value_color_byte);
    lua_setfield(L, -2, "value_color_byte");
    lua_pushcfunction(L, GenL_nk_value_color_float);
    lua_setfield(L, -2, "value_color_float");
    lua_pushcfunction(L, GenL_nk_value_color_hex);
    lua_setfield(L, -2, "value_color_hex");
    lua_pushcfunction(L, GenL_nk_value_float);
    lua_setfield(L, -2, "value_float");
    lua_pushcfunction(L, GenL_nk_value_int);
    lua_setfield(L, -2, "value_int");
    lua_pushcfunction(L, GenL_nk_value_uint);
    lua_setfield(L, -2, "value_uint");
    lua_pushcfunction(L, GenL_nk_vec2);
    lua_setfield(L, -2, "vec2");
    lua_pushcfunction(L, GenL_nk_vec2i);
    lua_setfield(L, -2, "vec2i");
    lua_pushcfunction(L, GenL_nk_widget);
    lua_setfield(L, -2, "widget");
    lua_pushcfunction(L, GenL_nk_widget_bounds);
    lua_setfield(L, -2, "widget_bounds");
    lua_pushcfunction(L, GenL_nk_widget_disable_begin);
    lua_setfield(L, -2, "widget_disable_begin");
    lua_pushcfunction(L, GenL_nk_widget_disable_end);
    lua_setfield(L, -2, "widget_disable_end");
    lua_pushcfunction(L, GenL_nk_widget_fitting);
    lua_setfield(L, -2, "widget_fitting");
    lua_pushcfunction(L, GenL_nk_widget_has_mouse_click_down);
    lua_setfield(L, -2, "widget_has_mouse_click_down");
    lua_pushcfunction(L, GenL_nk_widget_height);
    lua_setfield(L, -2, "widget_height");
    lua_pushcfunction(L, GenL_nk_widget_is_hovered);
    lua_setfield(L, -2, "widget_is_hovered");
    lua_pushcfunction(L, GenL_nk_widget_is_mouse_clicked);
    lua_setfield(L, -2, "widget_is_mouse_clicked");
    lua_pushcfunction(L, GenL_nk_widget_position);
    lua_setfield(L, -2, "widget_position");
    lua_pushcfunction(L, GenL_nk_widget_size);
    lua_setfield(L, -2, "widget_size");
    lua_pushcfunction(L, GenL_nk_widget_width);
    lua_setfield(L, -2, "widget_width");
    lua_pushcfunction(L, GenL_nk_window_close);
    lua_setfield(L, -2, "window_close");
    lua_pushcfunction(L, GenL_nk_window_collapse);
    lua_setfield(L, -2, "window_collapse");
    lua_pushcfunction(L, GenL_nk_window_collapse_if);
    lua_setfield(L, -2, "window_collapse_if");
    lua_pushcfunction(L, GenL_nk_window_find);
    lua_setfield(L, -2, "window_find");
    lua_pushcfunction(L, GenL_nk_window_get_bounds);
    lua_setfield(L, -2, "window_get_bounds");
    lua_pushcfunction(L, GenL_nk_window_get_canvas);
    lua_setfield(L, -2, "window_get_canvas");
    lua_pushcfunction(L, GenL_nk_window_get_content_region);
    lua_setfield(L, -2, "window_get_content_region");
    lua_pushcfunction(L, GenL_nk_window_get_content_region_max);
    lua_setfield(L, -2, "window_get_content_region_max");
    lua_pushcfunction(L, GenL_nk_window_get_content_region_min);
    lua_setfield(L, -2, "window_get_content_region_min");
    lua_pushcfunction(L, GenL_nk_window_get_content_region_size);
    lua_setfield(L, -2, "window_get_content_region_size");
    lua_pushcfunction(L, GenL_nk_window_get_height);
    lua_setfield(L, -2, "window_get_height");
    lua_pushcfunction(L, GenL_nk_window_get_panel);
    lua_setfield(L, -2, "window_get_panel");
    lua_pushcfunction(L, GenL_nk_window_get_position);
    lua_setfield(L, -2, "window_get_position");
    lua_pushcfunction(L, GenL_nk_window_get_scroll);
    lua_setfield(L, -2, "window_get_scroll");
    lua_pushcfunction(L, GenL_nk_window_get_size);
    lua_setfield(L, -2, "window_get_size");
    lua_pushcfunction(L, GenL_nk_window_get_width);
    lua_setfield(L, -2, "window_get_width");
    lua_pushcfunction(L, GenL_nk_window_has_focus);
    lua_setfield(L, -2, "window_has_focus");
    lua_pushcfunction(L, GenL_nk_window_is_active);
    lua_setfield(L, -2, "window_is_active");
    lua_pushcfunction(L, GenL_nk_window_is_any_hovered);
    lua_setfield(L, -2, "window_is_any_hovered");
    lua_pushcfunction(L, GenL_nk_window_is_closed);
    lua_setfield(L, -2, "window_is_closed");
    lua_pushcfunction(L, GenL_nk_window_is_collapsed);
    lua_setfield(L, -2, "window_is_collapsed");
    lua_pushcfunction(L, GenL_nk_window_is_hidden);
    lua_setfield(L, -2, "window_is_hidden");
    lua_pushcfunction(L, GenL_nk_window_is_hovered);
    lua_setfield(L, -2, "window_is_hovered");
    lua_pushcfunction(L, GenL_nk_window_set_bounds);
    lua_setfield(L, -2, "window_set_bounds");
    lua_pushcfunction(L, GenL_nk_window_set_focus);
    lua_setfield(L, -2, "window_set_focus");
    lua_pushcfunction(L, GenL_nk_window_set_position);
    lua_setfield(L, -2, "window_set_position");
    lua_pushcfunction(L, GenL_nk_window_set_scroll);
    lua_setfield(L, -2, "window_set_scroll");
    lua_pushcfunction(L, GenL_nk_window_set_size);
    lua_setfield(L, -2, "window_set_size");
    lua_pushcfunction(L, GenL_nk_window_show);
    lua_setfield(L, -2, "window_show");
    lua_pushcfunction(L, GenL_nk_window_show_if);
    lua_setfield(L, -2, "window_show_if");
    lua_pushinteger(L, (lua_Integer)NK_BUFFER_FIXED);
    lua_setfield(L, -2, "NK_BUFFER_FIXED");
    lua_pushinteger(L, (lua_Integer)NK_BUFFER_DYNAMIC);
    lua_setfield(L, -2, "NK_BUFFER_DYNAMIC");
    lua_pushinteger(L, (lua_Integer)NK_ANTI_ALIASING_OFF);
    lua_setfield(L, -2, "NK_ANTI_ALIASING_OFF");
    lua_pushinteger(L, (lua_Integer)NK_ANTI_ALIASING_ON);
    lua_setfield(L, -2, "NK_ANTI_ALIASING_ON");
    lua_pushinteger(L, (lua_Integer)NK_BUFFER_FRONT);
    lua_setfield(L, -2, "NK_BUFFER_FRONT");
    lua_pushinteger(L, (lua_Integer)NK_BUFFER_BACK);
    lua_setfield(L, -2, "NK_BUFFER_BACK");
    lua_pushinteger(L, (lua_Integer)NK_BUFFER_MAX);
    lua_setfield(L, -2, "NK_BUFFER_MAX");
    lua_pushinteger(L, (lua_Integer)NK_BUTTON_DEFAULT);
    lua_setfield(L, -2, "NK_BUTTON_DEFAULT");
    lua_pushinteger(L, (lua_Integer)NK_BUTTON_REPEATER);
    lua_setfield(L, -2, "NK_BUTTON_REPEATER");
    lua_pushinteger(L, (lua_Integer)NK_BUTTON_LEFT);
    lua_setfield(L, -2, "NK_BUTTON_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_BUTTON_MIDDLE);
    lua_setfield(L, -2, "NK_BUTTON_MIDDLE");
    lua_pushinteger(L, (lua_Integer)NK_BUTTON_RIGHT);
    lua_setfield(L, -2, "NK_BUTTON_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_BUTTON_DOUBLE);
    lua_setfield(L, -2, "NK_BUTTON_DOUBLE");
    lua_pushinteger(L, (lua_Integer)NK_BUTTON_X1);
    lua_setfield(L, -2, "NK_BUTTON_X1");
    lua_pushinteger(L, (lua_Integer)NK_BUTTON_X2);
    lua_setfield(L, -2, "NK_BUTTON_X2");
    lua_pushinteger(L, (lua_Integer)NK_BUTTON_MAX);
    lua_setfield(L, -2, "NK_BUTTON_MAX");
    lua_pushinteger(L, (lua_Integer)NK_CHART_HOVERING);
    lua_setfield(L, -2, "NK_CHART_HOVERING");
    lua_pushinteger(L, (lua_Integer)NK_CHART_CLICKED);
    lua_setfield(L, -2, "NK_CHART_CLICKED");
    lua_pushinteger(L, (lua_Integer)NK_CHART_LINES);
    lua_setfield(L, -2, "NK_CHART_LINES");
    lua_pushinteger(L, (lua_Integer)NK_CHART_COLUMN);
    lua_setfield(L, -2, "NK_CHART_COLUMN");
    lua_pushinteger(L, (lua_Integer)NK_CHART_MAX);
    lua_setfield(L, -2, "NK_CHART_MAX");
    lua_pushinteger(L, (lua_Integer)NK_MINIMIZED);
    lua_setfield(L, -2, "NK_MINIMIZED");
    lua_pushinteger(L, (lua_Integer)NK_MAXIMIZED);
    lua_setfield(L, -2, "NK_MAXIMIZED");
    lua_pushinteger(L, (lua_Integer)NK_RGB);
    lua_setfield(L, -2, "NK_RGB");
    lua_pushinteger(L, (lua_Integer)NK_RGBA);
    lua_setfield(L, -2, "NK_RGBA");
    lua_pushinteger(L, (lua_Integer)NK_CLIPPING_OFF);
    lua_setfield(L, -2, "NK_CLIPPING_OFF");
    lua_pushinteger(L, (lua_Integer)NK_CLIPPING_ON);
    lua_setfield(L, -2, "NK_CLIPPING_ON");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_NOP);
    lua_setfield(L, -2, "NK_COMMAND_NOP");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_SCISSOR);
    lua_setfield(L, -2, "NK_COMMAND_SCISSOR");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_LINE);
    lua_setfield(L, -2, "NK_COMMAND_LINE");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_CURVE);
    lua_setfield(L, -2, "NK_COMMAND_CURVE");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_RECT);
    lua_setfield(L, -2, "NK_COMMAND_RECT");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_RECT_FILLED);
    lua_setfield(L, -2, "NK_COMMAND_RECT_FILLED");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_RECT_MULTI_COLOR);
    lua_setfield(L, -2, "NK_COMMAND_RECT_MULTI_COLOR");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_CIRCLE);
    lua_setfield(L, -2, "NK_COMMAND_CIRCLE");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_CIRCLE_FILLED);
    lua_setfield(L, -2, "NK_COMMAND_CIRCLE_FILLED");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_ARC);
    lua_setfield(L, -2, "NK_COMMAND_ARC");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_ARC_FILLED);
    lua_setfield(L, -2, "NK_COMMAND_ARC_FILLED");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_TRIANGLE);
    lua_setfield(L, -2, "NK_COMMAND_TRIANGLE");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_TRIANGLE_FILLED);
    lua_setfield(L, -2, "NK_COMMAND_TRIANGLE_FILLED");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_POLYGON);
    lua_setfield(L, -2, "NK_COMMAND_POLYGON");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_POLYGON_FILLED);
    lua_setfield(L, -2, "NK_COMMAND_POLYGON_FILLED");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_POLYLINE);
    lua_setfield(L, -2, "NK_COMMAND_POLYLINE");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_TEXT);
    lua_setfield(L, -2, "NK_COMMAND_TEXT");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_IMAGE);
    lua_setfield(L, -2, "NK_COMMAND_IMAGE");
    lua_pushinteger(L, (lua_Integer)NK_COMMAND_CUSTOM);
    lua_setfield(L, -2, "NK_COMMAND_CUSTOM");
    lua_pushinteger(L, (lua_Integer)NK_CONVERT_SUCCESS);
    lua_setfield(L, -2, "NK_CONVERT_SUCCESS");
    lua_pushinteger(L, (lua_Integer)NK_CONVERT_INVALID_PARAM);
    lua_setfield(L, -2, "NK_CONVERT_INVALID_PARAM");
    lua_pushinteger(L, (lua_Integer)NK_CONVERT_COMMAND_BUFFER_FULL);
    lua_setfield(L, -2, "NK_CONVERT_COMMAND_BUFFER_FULL");
    lua_pushinteger(L, (lua_Integer)NK_CONVERT_VERTEX_BUFFER_FULL);
    lua_setfield(L, -2, "NK_CONVERT_VERTEX_BUFFER_FULL");
    lua_pushinteger(L, (lua_Integer)NK_CONVERT_ELEMENT_BUFFER_FULL);
    lua_setfield(L, -2, "NK_CONVERT_ELEMENT_BUFFER_FULL");
    lua_pushinteger(L, (lua_Integer)NK_STROKE_OPEN);
    lua_setfield(L, -2, "NK_STROKE_OPEN");
    lua_pushinteger(L, (lua_Integer)NK_STROKE_CLOSED);
    lua_setfield(L, -2, "NK_STROKE_CLOSED");
    lua_pushinteger(L, (lua_Integer)NK_VERTEX_POSITION);
    lua_setfield(L, -2, "NK_VERTEX_POSITION");
    lua_pushinteger(L, (lua_Integer)NK_VERTEX_COLOR);
    lua_setfield(L, -2, "NK_VERTEX_COLOR");
    lua_pushinteger(L, (lua_Integer)NK_VERTEX_TEXCOORD);
    lua_setfield(L, -2, "NK_VERTEX_TEXCOORD");
    lua_pushinteger(L, (lua_Integer)NK_VERTEX_ATTRIBUTE_COUNT);
    lua_setfield(L, -2, "NK_VERTEX_ATTRIBUTE_COUNT");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_SCHAR);
    lua_setfield(L, -2, "NK_FORMAT_SCHAR");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_SSHORT);
    lua_setfield(L, -2, "NK_FORMAT_SSHORT");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_SINT);
    lua_setfield(L, -2, "NK_FORMAT_SINT");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_UCHAR);
    lua_setfield(L, -2, "NK_FORMAT_UCHAR");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_USHORT);
    lua_setfield(L, -2, "NK_FORMAT_USHORT");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_UINT);
    lua_setfield(L, -2, "NK_FORMAT_UINT");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_FLOAT);
    lua_setfield(L, -2, "NK_FORMAT_FLOAT");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_DOUBLE);
    lua_setfield(L, -2, "NK_FORMAT_DOUBLE");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_COLOR_BEGIN);
    lua_setfield(L, -2, "NK_FORMAT_COLOR_BEGIN");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_R8G8B8);
    lua_setfield(L, -2, "NK_FORMAT_R8G8B8");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_R16G15B16);
    lua_setfield(L, -2, "NK_FORMAT_R16G15B16");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_R32G32B32);
    lua_setfield(L, -2, "NK_FORMAT_R32G32B32");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_R8G8B8A8);
    lua_setfield(L, -2, "NK_FORMAT_R8G8B8A8");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_B8G8R8A8);
    lua_setfield(L, -2, "NK_FORMAT_B8G8R8A8");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_R16G15B16A16);
    lua_setfield(L, -2, "NK_FORMAT_R16G15B16A16");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_R32G32B32A32);
    lua_setfield(L, -2, "NK_FORMAT_R32G32B32A32");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_R32G32B32A32_FLOAT);
    lua_setfield(L, -2, "NK_FORMAT_R32G32B32A32_FLOAT");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_R32G32B32A32_DOUBLE);
    lua_setfield(L, -2, "NK_FORMAT_R32G32B32A32_DOUBLE");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_RGB32);
    lua_setfield(L, -2, "NK_FORMAT_RGB32");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_RGBA32);
    lua_setfield(L, -2, "NK_FORMAT_RGBA32");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_COLOR_END);
    lua_setfield(L, -2, "NK_FORMAT_COLOR_END");
    lua_pushinteger(L, (lua_Integer)NK_FORMAT_COUNT);
    lua_setfield(L, -2, "NK_FORMAT_COUNT");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_ACTIVE);
    lua_setfield(L, -2, "NK_EDIT_ACTIVE");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_INACTIVE);
    lua_setfield(L, -2, "NK_EDIT_INACTIVE");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_ACTIVATED);
    lua_setfield(L, -2, "NK_EDIT_ACTIVATED");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_DEACTIVATED);
    lua_setfield(L, -2, "NK_EDIT_DEACTIVATED");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_COMMITTED);
    lua_setfield(L, -2, "NK_EDIT_COMMITTED");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_DEFAULT);
    lua_setfield(L, -2, "NK_EDIT_DEFAULT");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_READ_ONLY);
    lua_setfield(L, -2, "NK_EDIT_READ_ONLY");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_AUTO_SELECT);
    lua_setfield(L, -2, "NK_EDIT_AUTO_SELECT");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_SIG_ENTER);
    lua_setfield(L, -2, "NK_EDIT_SIG_ENTER");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_ALLOW_TAB);
    lua_setfield(L, -2, "NK_EDIT_ALLOW_TAB");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_NO_CURSOR);
    lua_setfield(L, -2, "NK_EDIT_NO_CURSOR");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_SELECTABLE);
    lua_setfield(L, -2, "NK_EDIT_SELECTABLE");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_CLIPBOARD);
    lua_setfield(L, -2, "NK_EDIT_CLIPBOARD");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_CTRL_ENTER_NEWLINE);
    lua_setfield(L, -2, "NK_EDIT_CTRL_ENTER_NEWLINE");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_NO_HORIZONTAL_SCROLL);
    lua_setfield(L, -2, "NK_EDIT_NO_HORIZONTAL_SCROLL");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_ALWAYS_INSERT_MODE);
    lua_setfield(L, -2, "NK_EDIT_ALWAYS_INSERT_MODE");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_MULTILINE);
    lua_setfield(L, -2, "NK_EDIT_MULTILINE");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_GOTO_END_ON_ACTIVATE);
    lua_setfield(L, -2, "NK_EDIT_GOTO_END_ON_ACTIVATE");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_SIMPLE);
    lua_setfield(L, -2, "NK_EDIT_SIMPLE");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_FIELD);
    lua_setfield(L, -2, "NK_EDIT_FIELD");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_BOX);
    lua_setfield(L, -2, "NK_EDIT_BOX");
    lua_pushinteger(L, (lua_Integer)NK_EDIT_EDITOR);
    lua_setfield(L, -2, "NK_EDIT_EDITOR");
    lua_pushinteger(L, (lua_Integer)NK_FONT_ATLAS_ALPHA8);
    lua_setfield(L, -2, "NK_FONT_ATLAS_ALPHA8");
    lua_pushinteger(L, (lua_Integer)NK_FONT_ATLAS_RGBA32);
    lua_setfield(L, -2, "NK_FONT_ATLAS_RGBA32");
    lua_pushinteger(L, (lua_Integer)NK_COORD_UV);
    lua_setfield(L, -2, "NK_COORD_UV");
    lua_pushinteger(L, (lua_Integer)NK_COORD_PIXEL);
    lua_setfield(L, -2, "NK_COORD_PIXEL");
    lua_pushinteger(L, (lua_Integer)NK_UP);
    lua_setfield(L, -2, "NK_UP");
    lua_pushinteger(L, (lua_Integer)NK_RIGHT);
    lua_setfield(L, -2, "NK_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_DOWN);
    lua_setfield(L, -2, "NK_DOWN");
    lua_pushinteger(L, (lua_Integer)NK_LEFT);
    lua_setfield(L, -2, "NK_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_KEY_NONE);
    lua_setfield(L, -2, "NK_KEY_NONE");
    lua_pushinteger(L, (lua_Integer)NK_KEY_SHIFT);
    lua_setfield(L, -2, "NK_KEY_SHIFT");
    lua_pushinteger(L, (lua_Integer)NK_KEY_CTRL);
    lua_setfield(L, -2, "NK_KEY_CTRL");
    lua_pushinteger(L, (lua_Integer)NK_KEY_DEL);
    lua_setfield(L, -2, "NK_KEY_DEL");
    lua_pushinteger(L, (lua_Integer)NK_KEY_ENTER);
    lua_setfield(L, -2, "NK_KEY_ENTER");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TAB);
    lua_setfield(L, -2, "NK_KEY_TAB");
    lua_pushinteger(L, (lua_Integer)NK_KEY_BACKSPACE);
    lua_setfield(L, -2, "NK_KEY_BACKSPACE");
    lua_pushinteger(L, (lua_Integer)NK_KEY_COPY);
    lua_setfield(L, -2, "NK_KEY_COPY");
    lua_pushinteger(L, (lua_Integer)NK_KEY_CUT);
    lua_setfield(L, -2, "NK_KEY_CUT");
    lua_pushinteger(L, (lua_Integer)NK_KEY_PASTE);
    lua_setfield(L, -2, "NK_KEY_PASTE");
    lua_pushinteger(L, (lua_Integer)NK_KEY_UP);
    lua_setfield(L, -2, "NK_KEY_UP");
    lua_pushinteger(L, (lua_Integer)NK_KEY_DOWN);
    lua_setfield(L, -2, "NK_KEY_DOWN");
    lua_pushinteger(L, (lua_Integer)NK_KEY_LEFT);
    lua_setfield(L, -2, "NK_KEY_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_KEY_RIGHT);
    lua_setfield(L, -2, "NK_KEY_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_INSERT_MODE);
    lua_setfield(L, -2, "NK_KEY_TEXT_INSERT_MODE");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_REPLACE_MODE);
    lua_setfield(L, -2, "NK_KEY_TEXT_REPLACE_MODE");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_RESET_MODE);
    lua_setfield(L, -2, "NK_KEY_TEXT_RESET_MODE");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_LINE_START);
    lua_setfield(L, -2, "NK_KEY_TEXT_LINE_START");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_LINE_END);
    lua_setfield(L, -2, "NK_KEY_TEXT_LINE_END");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_START);
    lua_setfield(L, -2, "NK_KEY_TEXT_START");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_END);
    lua_setfield(L, -2, "NK_KEY_TEXT_END");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_UNDO);
    lua_setfield(L, -2, "NK_KEY_TEXT_UNDO");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_REDO);
    lua_setfield(L, -2, "NK_KEY_TEXT_REDO");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_SELECT_ALL);
    lua_setfield(L, -2, "NK_KEY_TEXT_SELECT_ALL");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_WORD_LEFT);
    lua_setfield(L, -2, "NK_KEY_TEXT_WORD_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_KEY_TEXT_WORD_RIGHT);
    lua_setfield(L, -2, "NK_KEY_TEXT_WORD_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_KEY_SCROLL_START);
    lua_setfield(L, -2, "NK_KEY_SCROLL_START");
    lua_pushinteger(L, (lua_Integer)NK_KEY_SCROLL_END);
    lua_setfield(L, -2, "NK_KEY_SCROLL_END");
    lua_pushinteger(L, (lua_Integer)NK_KEY_SCROLL_DOWN);
    lua_setfield(L, -2, "NK_KEY_SCROLL_DOWN");
    lua_pushinteger(L, (lua_Integer)NK_KEY_SCROLL_UP);
    lua_setfield(L, -2, "NK_KEY_SCROLL_UP");
    lua_pushinteger(L, (lua_Integer)NK_KEY_MAX);
    lua_setfield(L, -2, "NK_KEY_MAX");
    lua_pushinteger(L, (lua_Integer)NK_DYNAMIC);
    lua_setfield(L, -2, "NK_DYNAMIC");
    lua_pushinteger(L, (lua_Integer)NK_STATIC);
    lua_setfield(L, -2, "NK_STATIC");
    lua_pushinteger(L, (lua_Integer)NK_FIXED);
    lua_setfield(L, -2, "NK_FIXED");
    lua_pushinteger(L, (lua_Integer)NK_MODIFIABLE);
    lua_setfield(L, -2, "NK_MODIFIABLE");
    lua_pushinteger(L, (lua_Integer)NK_VERTICAL);
    lua_setfield(L, -2, "NK_VERTICAL");
    lua_pushinteger(L, (lua_Integer)NK_HORIZONTAL);
    lua_setfield(L, -2, "NK_HORIZONTAL");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_BORDER);
    lua_setfield(L, -2, "NK_WINDOW_BORDER");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_MOVABLE);
    lua_setfield(L, -2, "NK_WINDOW_MOVABLE");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_SCALABLE);
    lua_setfield(L, -2, "NK_WINDOW_SCALABLE");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_CLOSABLE);
    lua_setfield(L, -2, "NK_WINDOW_CLOSABLE");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_MINIMIZABLE);
    lua_setfield(L, -2, "NK_WINDOW_MINIMIZABLE");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_NO_SCROLLBAR);
    lua_setfield(L, -2, "NK_WINDOW_NO_SCROLLBAR");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_TITLE);
    lua_setfield(L, -2, "NK_WINDOW_TITLE");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_SCROLL_AUTO_HIDE);
    lua_setfield(L, -2, "NK_WINDOW_SCROLL_AUTO_HIDE");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_BACKGROUND);
    lua_setfield(L, -2, "NK_WINDOW_BACKGROUND");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_SCALE_LEFT);
    lua_setfield(L, -2, "NK_WINDOW_SCALE_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_NO_INPUT);
    lua_setfield(L, -2, "NK_WINDOW_NO_INPUT");
    lua_pushinteger(L, (lua_Integer)NK_LAYOUT_DYNAMIC_FIXED);
    lua_setfield(L, -2, "NK_LAYOUT_DYNAMIC_FIXED");
    lua_pushinteger(L, (lua_Integer)NK_LAYOUT_DYNAMIC_ROW);
    lua_setfield(L, -2, "NK_LAYOUT_DYNAMIC_ROW");
    lua_pushinteger(L, (lua_Integer)NK_LAYOUT_DYNAMIC_FREE);
    lua_setfield(L, -2, "NK_LAYOUT_DYNAMIC_FREE");
    lua_pushinteger(L, (lua_Integer)NK_LAYOUT_DYNAMIC);
    lua_setfield(L, -2, "NK_LAYOUT_DYNAMIC");
    lua_pushinteger(L, (lua_Integer)NK_LAYOUT_STATIC_FIXED);
    lua_setfield(L, -2, "NK_LAYOUT_STATIC_FIXED");
    lua_pushinteger(L, (lua_Integer)NK_LAYOUT_STATIC_ROW);
    lua_setfield(L, -2, "NK_LAYOUT_STATIC_ROW");
    lua_pushinteger(L, (lua_Integer)NK_LAYOUT_STATIC_FREE);
    lua_setfield(L, -2, "NK_LAYOUT_STATIC_FREE");
    lua_pushinteger(L, (lua_Integer)NK_LAYOUT_STATIC);
    lua_setfield(L, -2, "NK_LAYOUT_STATIC");
    lua_pushinteger(L, (lua_Integer)NK_LAYOUT_TEMPLATE);
    lua_setfield(L, -2, "NK_LAYOUT_TEMPLATE");
    lua_pushinteger(L, (lua_Integer)NK_LAYOUT_COUNT);
    lua_setfield(L, -2, "NK_LAYOUT_COUNT");
    lua_pushinteger(L, (lua_Integer)NK_PANEL_SET_NONBLOCK);
    lua_setfield(L, -2, "NK_PANEL_SET_NONBLOCK");
    lua_pushinteger(L, (lua_Integer)NK_PANEL_SET_POPUP);
    lua_setfield(L, -2, "NK_PANEL_SET_POPUP");
    lua_pushinteger(L, (lua_Integer)NK_PANEL_SET_SUB);
    lua_setfield(L, -2, "NK_PANEL_SET_SUB");
    lua_pushinteger(L, (lua_Integer)NK_PANEL_NONE);
    lua_setfield(L, -2, "NK_PANEL_NONE");
    lua_pushinteger(L, (lua_Integer)NK_PANEL_WINDOW);
    lua_setfield(L, -2, "NK_PANEL_WINDOW");
    lua_pushinteger(L, (lua_Integer)NK_PANEL_GROUP);
    lua_setfield(L, -2, "NK_PANEL_GROUP");
    lua_pushinteger(L, (lua_Integer)NK_PANEL_POPUP);
    lua_setfield(L, -2, "NK_PANEL_POPUP");
    lua_pushinteger(L, (lua_Integer)NK_PANEL_CONTEXTUAL);
    lua_setfield(L, -2, "NK_PANEL_CONTEXTUAL");
    lua_pushinteger(L, (lua_Integer)NK_PANEL_COMBO);
    lua_setfield(L, -2, "NK_PANEL_COMBO");
    lua_pushinteger(L, (lua_Integer)NK_PANEL_MENU);
    lua_setfield(L, -2, "NK_PANEL_MENU");
    lua_pushinteger(L, (lua_Integer)NK_PANEL_TOOLTIP);
    lua_setfield(L, -2, "NK_PANEL_TOOLTIP");
    lua_pushinteger(L, (lua_Integer)NK_POPUP_STATIC);
    lua_setfield(L, -2, "NK_POPUP_STATIC");
    lua_pushinteger(L, (lua_Integer)NK_POPUP_DYNAMIC);
    lua_setfield(L, -2, "NK_POPUP_DYNAMIC");
    lua_pushinteger(L, (lua_Integer)NK_HIDDEN);
    lua_setfield(L, -2, "NK_HIDDEN");
    lua_pushinteger(L, (lua_Integer)NK_SHOWN);
    lua_setfield(L, -2, "NK_SHOWN");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_TEXT);
    lua_setfield(L, -2, "NK_COLOR_TEXT");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_WINDOW);
    lua_setfield(L, -2, "NK_COLOR_WINDOW");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_HEADER);
    lua_setfield(L, -2, "NK_COLOR_HEADER");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_BORDER);
    lua_setfield(L, -2, "NK_COLOR_BORDER");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_BUTTON);
    lua_setfield(L, -2, "NK_COLOR_BUTTON");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_BUTTON_HOVER);
    lua_setfield(L, -2, "NK_COLOR_BUTTON_HOVER");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_BUTTON_ACTIVE);
    lua_setfield(L, -2, "NK_COLOR_BUTTON_ACTIVE");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_TOGGLE);
    lua_setfield(L, -2, "NK_COLOR_TOGGLE");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_TOGGLE_HOVER);
    lua_setfield(L, -2, "NK_COLOR_TOGGLE_HOVER");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_TOGGLE_CURSOR);
    lua_setfield(L, -2, "NK_COLOR_TOGGLE_CURSOR");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_SELECT);
    lua_setfield(L, -2, "NK_COLOR_SELECT");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_SELECT_ACTIVE);
    lua_setfield(L, -2, "NK_COLOR_SELECT_ACTIVE");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_SLIDER);
    lua_setfield(L, -2, "NK_COLOR_SLIDER");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_SLIDER_CURSOR);
    lua_setfield(L, -2, "NK_COLOR_SLIDER_CURSOR");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_SLIDER_CURSOR_HOVER);
    lua_setfield(L, -2, "NK_COLOR_SLIDER_CURSOR_HOVER");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_SLIDER_CURSOR_ACTIVE);
    lua_setfield(L, -2, "NK_COLOR_SLIDER_CURSOR_ACTIVE");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_PROPERTY);
    lua_setfield(L, -2, "NK_COLOR_PROPERTY");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_EDIT);
    lua_setfield(L, -2, "NK_COLOR_EDIT");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_EDIT_CURSOR);
    lua_setfield(L, -2, "NK_COLOR_EDIT_CURSOR");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_COMBO);
    lua_setfield(L, -2, "NK_COLOR_COMBO");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_CHART);
    lua_setfield(L, -2, "NK_COLOR_CHART");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_CHART_COLOR);
    lua_setfield(L, -2, "NK_COLOR_CHART_COLOR");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_CHART_COLOR_HIGHLIGHT);
    lua_setfield(L, -2, "NK_COLOR_CHART_COLOR_HIGHLIGHT");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_SCROLLBAR);
    lua_setfield(L, -2, "NK_COLOR_SCROLLBAR");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_SCROLLBAR_CURSOR);
    lua_setfield(L, -2, "NK_COLOR_SCROLLBAR_CURSOR");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_SCROLLBAR_CURSOR_HOVER);
    lua_setfield(L, -2, "NK_COLOR_SCROLLBAR_CURSOR_HOVER");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_SCROLLBAR_CURSOR_ACTIVE);
    lua_setfield(L, -2, "NK_COLOR_SCROLLBAR_CURSOR_ACTIVE");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_TAB_HEADER);
    lua_setfield(L, -2, "NK_COLOR_TAB_HEADER");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_KNOB);
    lua_setfield(L, -2, "NK_COLOR_KNOB");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_KNOB_CURSOR);
    lua_setfield(L, -2, "NK_COLOR_KNOB_CURSOR");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_KNOB_CURSOR_HOVER);
    lua_setfield(L, -2, "NK_COLOR_KNOB_CURSOR_HOVER");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_KNOB_CURSOR_ACTIVE);
    lua_setfield(L, -2, "NK_COLOR_KNOB_CURSOR_ACTIVE");
    lua_pushinteger(L, (lua_Integer)NK_COLOR_COUNT);
    lua_setfield(L, -2, "NK_COLOR_COUNT");
    lua_pushinteger(L, (lua_Integer)NK_CURSOR_ARROW);
    lua_setfield(L, -2, "NK_CURSOR_ARROW");
    lua_pushinteger(L, (lua_Integer)NK_CURSOR_TEXT);
    lua_setfield(L, -2, "NK_CURSOR_TEXT");
    lua_pushinteger(L, (lua_Integer)NK_CURSOR_MOVE);
    lua_setfield(L, -2, "NK_CURSOR_MOVE");
    lua_pushinteger(L, (lua_Integer)NK_CURSOR_RESIZE_VERTICAL);
    lua_setfield(L, -2, "NK_CURSOR_RESIZE_VERTICAL");
    lua_pushinteger(L, (lua_Integer)NK_CURSOR_RESIZE_HORIZONTAL);
    lua_setfield(L, -2, "NK_CURSOR_RESIZE_HORIZONTAL");
    lua_pushinteger(L, (lua_Integer)NK_CURSOR_RESIZE_TOP_LEFT_DOWN_RIGHT);
    lua_setfield(L, -2, "NK_CURSOR_RESIZE_TOP_LEFT_DOWN_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_CURSOR_RESIZE_TOP_RIGHT_DOWN_LEFT);
    lua_setfield(L, -2, "NK_CURSOR_RESIZE_TOP_RIGHT_DOWN_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_CURSOR_COUNT);
    lua_setfield(L, -2, "NK_CURSOR_COUNT");
    lua_pushinteger(L, (lua_Integer)NK_HEADER_LEFT);
    lua_setfield(L, -2, "NK_HEADER_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_HEADER_RIGHT);
    lua_setfield(L, -2, "NK_HEADER_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_STYLE_ITEM_COLOR);
    lua_setfield(L, -2, "NK_STYLE_ITEM_COLOR");
    lua_pushinteger(L, (lua_Integer)NK_STYLE_ITEM_IMAGE);
    lua_setfield(L, -2, "NK_STYLE_ITEM_IMAGE");
    lua_pushinteger(L, (lua_Integer)NK_STYLE_ITEM_NINE_SLICE);
    lua_setfield(L, -2, "NK_STYLE_ITEM_NINE_SLICE");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_NONE);
    lua_setfield(L, -2, "NK_SYMBOL_NONE");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_X);
    lua_setfield(L, -2, "NK_SYMBOL_X");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_UNDERSCORE);
    lua_setfield(L, -2, "NK_SYMBOL_UNDERSCORE");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_CIRCLE_SOLID);
    lua_setfield(L, -2, "NK_SYMBOL_CIRCLE_SOLID");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_CIRCLE_OUTLINE);
    lua_setfield(L, -2, "NK_SYMBOL_CIRCLE_OUTLINE");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_RECT_SOLID);
    lua_setfield(L, -2, "NK_SYMBOL_RECT_SOLID");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_RECT_OUTLINE);
    lua_setfield(L, -2, "NK_SYMBOL_RECT_OUTLINE");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_TRIANGLE_UP);
    lua_setfield(L, -2, "NK_SYMBOL_TRIANGLE_UP");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_TRIANGLE_DOWN);
    lua_setfield(L, -2, "NK_SYMBOL_TRIANGLE_DOWN");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_TRIANGLE_LEFT);
    lua_setfield(L, -2, "NK_SYMBOL_TRIANGLE_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_TRIANGLE_RIGHT);
    lua_setfield(L, -2, "NK_SYMBOL_TRIANGLE_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_PLUS);
    lua_setfield(L, -2, "NK_SYMBOL_PLUS");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_MINUS);
    lua_setfield(L, -2, "NK_SYMBOL_MINUS");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_TRIANGLE_UP_OUTLINE);
    lua_setfield(L, -2, "NK_SYMBOL_TRIANGLE_UP_OUTLINE");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_TRIANGLE_DOWN_OUTLINE);
    lua_setfield(L, -2, "NK_SYMBOL_TRIANGLE_DOWN_OUTLINE");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_TRIANGLE_LEFT_OUTLINE);
    lua_setfield(L, -2, "NK_SYMBOL_TRIANGLE_LEFT_OUTLINE");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_TRIANGLE_RIGHT_OUTLINE);
    lua_setfield(L, -2, "NK_SYMBOL_TRIANGLE_RIGHT_OUTLINE");
    lua_pushinteger(L, (lua_Integer)NK_SYMBOL_MAX);
    lua_setfield(L, -2, "NK_SYMBOL_MAX");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_ALIGN_LEFT);
    lua_setfield(L, -2, "NK_TEXT_ALIGN_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_ALIGN_CENTERED);
    lua_setfield(L, -2, "NK_TEXT_ALIGN_CENTERED");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_ALIGN_RIGHT);
    lua_setfield(L, -2, "NK_TEXT_ALIGN_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_ALIGN_TOP);
    lua_setfield(L, -2, "NK_TEXT_ALIGN_TOP");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_ALIGN_MIDDLE);
    lua_setfield(L, -2, "NK_TEXT_ALIGN_MIDDLE");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_ALIGN_BOTTOM);
    lua_setfield(L, -2, "NK_TEXT_ALIGN_BOTTOM");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_LEFT);
    lua_setfield(L, -2, "NK_TEXT_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_CENTERED);
    lua_setfield(L, -2, "NK_TEXT_CENTERED");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_RIGHT);
    lua_setfield(L, -2, "NK_TEXT_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_EDIT_MODE_VIEW);
    lua_setfield(L, -2, "NK_TEXT_EDIT_MODE_VIEW");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_EDIT_MODE_INSERT);
    lua_setfield(L, -2, "NK_TEXT_EDIT_MODE_INSERT");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_EDIT_MODE_REPLACE);
    lua_setfield(L, -2, "NK_TEXT_EDIT_MODE_REPLACE");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_EDIT_SINGLE_LINE);
    lua_setfield(L, -2, "NK_TEXT_EDIT_SINGLE_LINE");
    lua_pushinteger(L, (lua_Integer)NK_TEXT_EDIT_MULTI_LINE);
    lua_setfield(L, -2, "NK_TEXT_EDIT_MULTI_LINE");
    lua_pushinteger(L, (lua_Integer)NK_TOP_LEFT);
    lua_setfield(L, -2, "NK_TOP_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_TOP_CENTER);
    lua_setfield(L, -2, "NK_TOP_CENTER");
    lua_pushinteger(L, (lua_Integer)NK_TOP_RIGHT);
    lua_setfield(L, -2, "NK_TOP_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_MIDDLE_LEFT);
    lua_setfield(L, -2, "NK_MIDDLE_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_MIDDLE_CENTER);
    lua_setfield(L, -2, "NK_MIDDLE_CENTER");
    lua_pushinteger(L, (lua_Integer)NK_MIDDLE_RIGHT);
    lua_setfield(L, -2, "NK_MIDDLE_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_BOTTOM_LEFT);
    lua_setfield(L, -2, "NK_BOTTOM_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_BOTTOM_CENTER);
    lua_setfield(L, -2, "NK_BOTTOM_CENTER");
    lua_pushinteger(L, (lua_Integer)NK_BOTTOM_RIGHT);
    lua_setfield(L, -2, "NK_BOTTOM_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_TREE_NODE);
    lua_setfield(L, -2, "NK_TREE_NODE");
    lua_pushinteger(L, (lua_Integer)NK_TREE_TAB);
    lua_setfield(L, -2, "NK_TREE_TAB");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_ALIGN_LEFT);
    lua_setfield(L, -2, "NK_WIDGET_ALIGN_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_ALIGN_CENTERED);
    lua_setfield(L, -2, "NK_WIDGET_ALIGN_CENTERED");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_ALIGN_RIGHT);
    lua_setfield(L, -2, "NK_WIDGET_ALIGN_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_ALIGN_TOP);
    lua_setfield(L, -2, "NK_WIDGET_ALIGN_TOP");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_ALIGN_MIDDLE);
    lua_setfield(L, -2, "NK_WIDGET_ALIGN_MIDDLE");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_ALIGN_BOTTOM);
    lua_setfield(L, -2, "NK_WIDGET_ALIGN_BOTTOM");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_LEFT);
    lua_setfield(L, -2, "NK_WIDGET_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_CENTERED);
    lua_setfield(L, -2, "NK_WIDGET_CENTERED");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_RIGHT);
    lua_setfield(L, -2, "NK_WIDGET_RIGHT");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_INVALID);
    lua_setfield(L, -2, "NK_WIDGET_INVALID");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_VALID);
    lua_setfield(L, -2, "NK_WIDGET_VALID");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_ROM);
    lua_setfield(L, -2, "NK_WIDGET_ROM");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_DISABLED);
    lua_setfield(L, -2, "NK_WIDGET_DISABLED");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_STATE_MODIFIED);
    lua_setfield(L, -2, "NK_WIDGET_STATE_MODIFIED");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_STATE_INACTIVE);
    lua_setfield(L, -2, "NK_WIDGET_STATE_INACTIVE");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_STATE_ENTERED);
    lua_setfield(L, -2, "NK_WIDGET_STATE_ENTERED");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_STATE_HOVER);
    lua_setfield(L, -2, "NK_WIDGET_STATE_HOVER");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_STATE_ACTIVED);
    lua_setfield(L, -2, "NK_WIDGET_STATE_ACTIVED");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_STATE_LEFT);
    lua_setfield(L, -2, "NK_WIDGET_STATE_LEFT");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_STATE_HOVERED);
    lua_setfield(L, -2, "NK_WIDGET_STATE_HOVERED");
    lua_pushinteger(L, (lua_Integer)NK_WIDGET_STATE_ACTIVE);
    lua_setfield(L, -2, "NK_WIDGET_STATE_ACTIVE");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_PRIVATE);
    lua_setfield(L, -2, "NK_WINDOW_PRIVATE");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_DYNAMIC);
    lua_setfield(L, -2, "NK_WINDOW_DYNAMIC");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_ROM);
    lua_setfield(L, -2, "NK_WINDOW_ROM");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_NOT_INTERACTIVE);
    lua_setfield(L, -2, "NK_WINDOW_NOT_INTERACTIVE");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_HIDDEN);
    lua_setfield(L, -2, "NK_WINDOW_HIDDEN");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_CLOSED);
    lua_setfield(L, -2, "NK_WINDOW_CLOSED");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_MINIMIZED);
    lua_setfield(L, -2, "NK_WINDOW_MINIMIZED");
    lua_pushinteger(L, (lua_Integer)NK_WINDOW_REMOVE_ROM);
    lua_setfield(L, -2, "NK_WINDOW_REMOVE_ROM");
    lua_setglobal(L, "NK");
    return 0;
}
