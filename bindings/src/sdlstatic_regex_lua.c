/*
 * sdlstatic_regex_lua.c — the `Regex` module for Lua, over SDLStatic::Regex.
 *
 * Original SDLStatic code (zlib).
 *
 * Lua has patterns, not regular expressions: no alternation, no
 * quantifiers on groups, no lookaround. The generated bindings already
 * expose the engine as flat SDLStaticC.Regex* calls; this wraps them in the
 * object shape a Lua programmer expects, so a compiled pattern is a value
 * with methods and the garbage collector owns it.
 *
 *   local re = Regex.new("(%w+)@(%w+)")  -- no: Lua patterns
 *   local re = Regex.new("(\\w+)@(\\w+)") -- yes: a real regex
 *   local m = re:match("mail bob@example")
 *   print(m[1], m[2], m.start, m.stop)
 *
 * Written as a Lua prelude rather than C for the same reason as the Ruby
 * side: it is ordinary object code over primitives that already cross the
 * boundary, and this way the two languages stay visibly the same shape.
 */
#include "bindings_core.h"

#include <SDLStatic/bindings.h>

#include <lauxlib.h>
#include <lua.h>

static const char kPrelude[] =
    "local C = SDLStaticC\n"
    "local Regex = {}\n"
    "Regex.__index = Regex\n"
    "\n"
    "-- Compile a pattern. flags may contain i, m (dot matches newline) or x.\n"
    "-- Returns nil plus the engine's message when the pattern is malformed.\n"
    "function Regex.new(pattern, flags)\n"
    "  local handle = C.CompileRegex(pattern, flags)\n"
    "  if handle == nil then return nil, SDL.GetError() end\n"
    "  return setmetatable({handle = handle}, Regex)\n"
    "end\n"
    "\n"
    "-- Build the match table: [0]=whole match, [1..n]=groups, plus byte\n"
    "-- offsets and any named captures.\n"
    "local function snapshot(self)\n"
    "  local m = {start = C.RegexGroupBegin(self.handle, 0),\n"
    "             stop = C.RegexGroupEnd(self.handle, 0),\n"
    "             groups = {}, named = {}}\n"
    "  local count = C.RegexGroupCount(self.handle)\n"
    "  for i = 0, count - 1 do\n"
    "    m[i] = C.RegexGroup(self.handle, i)\n"
    "    if i > 0 then m.groups[i] = m[i] end\n"
    "  end\n"
    "  for i = 0, C.RegexNamedGroupCount(self.handle) - 1 do\n"
    "    local name = C.RegexNamedGroupName(self.handle, i)\n"
    "    if name then m.named[name] = m[C.RegexNamedGroup(self.handle, name)] end\n"
    "  end\n"
    "  return m\n"
    "end\n"
    "\n"
    "-- Search from a 1-based position, as Lua string functions do; the\n"
    "-- offsets inside the match are the engine's own 0-based byte offsets.\n"
    "function Regex:match(text, init)\n"
    "  local from = (init or 1) - 1\n"
    "  if from < 0 then from = 0 end\n"
    "  if from > #text then return nil end\n"
    "  if not C.RegexSearch(self.handle, text, from) then return nil end\n"
    "  return snapshot(self)\n"
    "end\n"
    "\n"
    "-- True when the pattern matches at exactly this position.\n"
    "function Regex:match_at(text, init)\n"
    "  local at = (init or 1) - 1\n"
    "  if at < 0 or at > #text then return nil end\n"
    "  if not C.RegexMatchAt(self.handle, text, at) then return nil end\n"
    "  return snapshot(self)\n"
    "end\n"
    "\n"
    "-- Iterator over every match, for `for m in re:gmatch(s) do`.\n"
    "function Regex:gmatch(text)\n"
    "  local pos = 0\n"
    "  return function()\n"
    "    if pos > #text then return nil end\n"
    "    if not C.RegexSearch(self.handle, text, pos) then return nil end\n"
    "    local m = snapshot(self)\n"
    "    -- An empty match must still advance or this loops forever.\n"
    "    pos = (m.stop > m.start) and m.stop or (m.stop + 1)\n"
    "    return m\n"
    "  end\n"
    "end\n"
    "\n"
    "-- Replace matches. `replacement` is a string where \\\\1..\\\\9 refer to\n"
    "-- groups, or a function receiving the match table.\n"
    "function Regex:gsub(text, replacement, once)\n"
    "  if type(replacement) ~= 'function' then\n"
    "    return C.RegexReplace(self.handle, text, replacement, not once)\n"
    "  end\n"
    "  local out, start, pos = {}, 0, 0\n"
    "  while pos <= #text do\n"
    "    if not C.RegexSearch(self.handle, text, pos) then break end\n"
    "    local m = snapshot(self)\n"
    "    out[#out + 1] = text:sub(start + 1, m.start)\n"
    "    out[#out + 1] = tostring(replacement(m))\n"
    "    if m.stop == m.start then\n"
    "      out[#out + 1] = text:sub(m.start + 1, m.start + 1)\n"
    "      start = m.start + 1\n"
    "    else\n"
    "      start = m.stop\n"
    "    end\n"
    "    pos = start\n"
    "    if once then break end\n"
    "  end\n"
    "  out[#out + 1] = text:sub(start + 1)\n"
    "  return table.concat(out)\n"
    "end\n"
    "\n"
    "function Regex:split(text)\n"
    "  local out, start, pos = {}, 0, 0\n"
    "  while pos <= #text do\n"
    "    if not C.RegexSearch(self.handle, text, pos) then break end\n"
    "    local m = snapshot(self)\n"
    "    if m.stop == m.start then\n"
    "      if m.start >= #text then break end\n"
    "      out[#out + 1] = text:sub(start + 1, m.start + 1)\n"
    "      start = m.start + 1\n"
    "    else\n"
    "      out[#out + 1] = text:sub(start + 1, m.start)\n"
    "      start = m.stop\n"
    "    end\n"
    "    pos = start\n"
    "  end\n"
    "  out[#out + 1] = text:sub(start + 1)\n"
    "  return out\n"
    "end\n"
    "\n"
    "function Regex:test(text) return self:match(text) ~= nil end\n"
    "function Regex:source() return C.RegexPattern(self.handle) end\n"
    "function Regex:flags() return C.RegexFlags(self.handle) end\n"
    "function Regex.escape(text) return C.RegexEscape(text) end\n"
    "\n"
    "-- Convenience for one-off use. Deliberately not called `match`: that\n"
    "-- name belongs to the instance method, and defining both would\n"
    "-- silently shadow it through Regex.__index.\n"
    "function Regex.find(pattern, text, flags)\n"
    "  local re = Regex.new(pattern, flags)\n"
    "  if re == nil then return nil end\n"
    "  return re:match(text)\n"
    "end\n"
    "\n"
    "_G.Regex = Regex\n";

bool SDLStatic_OpenLuaRegex(lua_State *L)
{
    if (L == NULL)
    {
        return SDL_InvalidParamError("L");
    }
    if (luaL_loadstring(L, kPrelude) != LUA_OK || lua_pcall(L, 0, 0, 0) != LUA_OK)
    {
        /* A broken prelude is a build-time bug; surface it rather than
           leaving a half-built module behind. */
        SDL_SetError("Regex prelude failed: %s", lua_tostring(L, -1));
        lua_pop(L, 1);
        return false;
    }
    return true;
}
