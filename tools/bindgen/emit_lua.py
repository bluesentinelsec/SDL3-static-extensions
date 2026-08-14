"""Lua emitter: one generated C stub file per library.

Every bound function becomes a lua_CFunction registered (prefix-stripped)
in a global table named after the library (SDL, MIX, IMG, TTF, NET,
PHYSFS, B2, NK, JSON, SDLStaticC). Enum enumerators are registered as
integer constants in the same table. Return convention: the C return
value first (nil for NULL pointers), then every out/in-out parameter in
declaration order. Owned handles carry a __gc destructor; bound destroy
functions empty the box so GC never double-frees.
"""

from __future__ import annotations

from pathlib import Path

from .classify import TK, ScriptPlan, TypeTable, plan_script, used_pod_structs
from .model import Manifest
from .spec import LIBRARIES, RESOURCES, LibrarySpec

_LUA_KEYWORDS = {
    "and", "break", "do", "else", "elseif", "end", "false", "for",
    "function", "goto", "if", "in", "local", "nil", "not", "or",
    "repeat", "return", "then", "true", "until", "while",
}


def lua_name(cname: str, prefix: str, taken: set[str]) -> str:
    out = cname[len(prefix):] if cname.startswith(prefix) else cname
    if not out or not out[0].isalpha() and out[0] != "_":
        out = cname
    if out in _LUA_KEYWORDS:
        out += "_"
    if out in taken:
        out = cname
    taken.add(out)
    return out


def _ctype_spelling(pp) -> str:
    """C spelling for a bound parameter's declared type."""
    return pp.info.base


class _LibEmitter:
    def __init__(self, lib: LibrarySpec, plans: dict[str, ScriptPlan], tt: TypeTable):
        self.lib = lib
        self.plans = plans
        self.tt = tt
        self.destroys = {r.destroy: r for r in RESOURCES.get(lib.key, [])
                         if not r.by_value}
        self.resources = RESOURCES.get(lib.key, [])
        self.out: list[str] = []

    def w(self, line: str = "") -> None:
        self.out.append(line)

    # -- POD converters ----------------------------------------------------

    def converter_needs(self, bound: dict[str, ScriptPlan]) -> tuple[set[str], set[str]]:
        need_read: set[str] = set()
        need_push: set[str] = set()

        def close(name: str, into: set[str]) -> None:
            if name in into or name not in self.tt.structs:
                return
            into.add(name)
            for f in self.tt.structs[name].fields:
                base = self.tt.resolve_base(f.type.base)
                if self._field_kind(f.type) == "pod":
                    close(base, into)

        for plan in bound.values():
            if plan.ret and plan.ret.kind == TK.POD:
                close(plan.ret.base, need_push)
            for pp in plan.params:
                if pp.info.kind != TK.POD:
                    continue
                if pp.mode == "pod_in":
                    close(pp.info.base, need_read)
                elif pp.mode == "pod_out":
                    close(pp.info.base, need_push)
        return need_read, need_push

    def emit_pod_converters(self, structs: list[str], need_read: set[str],
                            need_push: set[str]) -> None:
        for sname in structs:
            st = self.tt.structs[sname]
            if sname in need_read:
                self.w(f"static void GenRead_{sname}(lua_State *L, int idx, {self._struct_ref(sname)} *out)")
                self.w("{")
                self.w("    memset(out, 0, sizeof(*out));")
                self.w("    if (!lua_istable(L, idx)) { return; }")
                for f in st.fields:
                    if not self.tt.field_marshalable(f.type):
                        continue
                    self._emit_field_read(sname, f)
                self.w("}")
                self.w()
            if sname in need_push:
                self.w(f"static void GenPush_{sname}(lua_State *L, const {self._struct_ref(sname)} *in)")
                self.w("{")
                self.w(f"    lua_createtable(L, 0, {len(st.fields)});")
                for f in st.fields:
                    if not self.tt.field_marshalable(f.type):
                        continue
                    self._emit_field_push(sname, f)
                self.w("}")
                self.w()

    def _struct_ref(self, name: str) -> str:
        # Plain (non-typedef) structs need the struct keyword. Nuklear's
        # structs are all plain; every other parsed lib typedefs them.
        if name.startswith("nk_"):
            return f"struct {name}"
        return name

    def _enum_ref(self, name: str) -> str:
        if name in self.tt.plain_enums:
            return f"enum {name}"
        return name

    def _field_kind(self, ftype) -> str:
        base = ftype.base
        for probe in (base, self.tt.resolve_base(base)):
            from .model import SCALAR_BOOLS, SCALAR_FLOATS, SCALAR_INTS

            if probe in SCALAR_FLOATS:
                return "num"
            if probe in SCALAR_BOOLS:
                return "bool"
            if probe in SCALAR_INTS:
                return "int"
        rbase = self.tt.resolve_base(base)
        if rbase in self.tt.enums:
            return "int"
        if rbase in self.tt.structs:
            return "pod"
        return "int"

    def _emit_field_read(self, sname: str, f) -> None:
        kind = self._field_kind(f.type)
        base = self.tt.resolve_base(f.type.base)
        if f.array_len is not None:
            self.w(f"    lua_getfield(L, idx, \"{f.name}\");")
            self.w("    if (lua_istable(L, -1)) {")
            self.w(f"        for (int gi = 0; gi < (int)({f.array_len}); ++gi) {{")
            self.w("            lua_rawgeti(L, -1, gi + 1);")
            if kind == "pod":
                self.w(f"            GenRead_{base}(L, lua_gettop(L), &out->{f.name}[gi]);")
            elif kind == "num":
                self.w(f"            out->{f.name}[gi] = ({f.type.base})lua_tonumber(L, -1);")
            else:
                self.w(f"            out->{f.name}[gi] = ({f.type.base})lua_tointeger(L, -1);")
            self.w("            lua_pop(L, 1);")
            self.w("        }")
            self.w("    }")
            self.w("    lua_pop(L, 1);")
            return
        if kind == "pod":
            self.w(f"    lua_getfield(L, idx, \"{f.name}\");")
            self.w(f"    GenRead_{base}(L, lua_gettop(L), &out->{f.name});")
            self.w("    lua_pop(L, 1);")
        elif kind == "num":
            self.w(f"    out->{f.name} = ({f.type.base})SDLStaticGen_LuaFieldNum(L, idx, \"{f.name}\");")
        elif kind == "bool":
            self.w(f"    out->{f.name} = ({f.type.base})SDLStaticGen_LuaFieldBool(L, idx, \"{f.name}\");")
        else:
            self.w(f"    out->{f.name} = ({f.type.base})SDLStaticGen_LuaFieldInt(L, idx, \"{f.name}\");")

    def _emit_field_push(self, sname: str, f) -> None:
        kind = self._field_kind(f.type)
        base = self.tt.resolve_base(f.type.base)
        if f.array_len is not None:
            self.w(f"    lua_createtable(L, (int)({f.array_len}), 0);")
            self.w(f"    for (int gi = 0; gi < (int)({f.array_len}); ++gi) {{")
            if kind == "pod":
                self.w(f"        GenPush_{base}(L, &in->{f.name}[gi]);")
            elif kind == "num":
                self.w(f"        lua_pushnumber(L, (lua_Number)in->{f.name}[gi]);")
            else:
                self.w(f"        lua_pushinteger(L, (lua_Integer)in->{f.name}[gi]);")
            self.w("        lua_rawseti(L, -2, gi + 1);")
            self.w("    }")
        elif kind == "pod":
            self.w(f"    GenPush_{base}(L, &in->{f.name});")
        elif kind == "num":
            self.w(f"    lua_pushnumber(L, (lua_Number)in->{f.name});")
        elif kind == "bool":
            self.w(f"    lua_pushboolean(L, (int)in->{f.name});")
        else:
            self.w(f"    lua_pushinteger(L, (lua_Integer)in->{f.name});")
        self.w(f"    lua_setfield(L, -2, \"{f.name}\");")

    # -- dtor thunks -------------------------------------------------------

    def emit_dtor_thunks(self, bound: dict[str, ScriptPlan]) -> None:
        used = {p.owned_resource_idx for p in bound.values() if p.owned_handle}
        emitted = set()
        for idx, r in enumerate(self.resources):
            if r.by_value or r.destroy in emitted or idx not in used:
                continue
            emitted.add(r.destroy)
            self.w(f"static void GenDtor_{r.destroy}(void *p)")
            self.w("{")
            self.w(f"    {r.ctype} *typed = ({r.ctype} *)p;")
            self.w(f"    {r.destroy}(typed);")
            self.w("}")
            self.w()

    # -- function stubs ----------------------------------------------------

    def emit_stub(self, plan: ScriptPlan) -> None:
        fn = plan.fn
        self.w(f"static int GenL_{fn.name}(lua_State *L)")
        self.w("{")
        self.w("    (void)L;")
        arg_n = 1
        call_args: dict[int, str] = {}
        post: list[str] = []
        nret = 0
        i = 0
        params = fn.params
        pp_by_index = {pp.param_index: pp for pp in plan.params}
        while i < len(params):
            pp = pp_by_index.get(i)
            if pp is None:
                i += 1
                continue
            v = f"a{i}"
            base = pp.info.base
            spell = self._param_spell(pp, params[i])
            if pp.mode == "blob_in":
                self.w(f"    size_t len{i} = 0;")
                self.w(f"    const char *{v} = luaL_checklstring(L, {arg_n}, &len{i});")
                call_args[i] = f"(const void *){v}"
                nxt = params[i + 1]
                nxt_spell = nxt.type.spelling()
                call_args[i + 1] = f"({nxt_spell})len{i}"
                arg_n += 1
                i += 2
                continue
            if pp.mode == "in" and pp.info.kind in (TK.INT, TK.ENUM):
                self.w(f"    {spell} {v} = ({spell})luaL_checkinteger(L, {arg_n});")
                call_args[i] = v
            elif pp.mode == "in" and pp.info.kind == TK.FLOAT:
                self.w(f"    {spell} {v} = ({spell})luaL_checknumber(L, {arg_n});")
                call_args[i] = v
            elif pp.mode == "in" and pp.info.kind == TK.BOOL:
                self.w(f"    {spell} {v} = ({spell})lua_toboolean(L, {arg_n});")
                call_args[i] = v
            elif pp.mode == "in" and pp.info.kind == TK.STRING:
                self.w(f"    const char *{v} = lua_isnoneornil(L, {arg_n}) ? NULL : luaL_checkstring(L, {arg_n});")
                call_args[i] = v
            elif pp.mode == "handle_in":
                take = fn.name in self.destroys and i == 0
                helper = "SDLStaticGen_LuaTakeHandle" if take else "SDLStaticGen_LuaCheckHandle"
                const = "const " if pp.info.is_const else ""
                self.w(f"    {const}{self._handle_ref(base)} *{v} = "
                       f"({const}{self._handle_ref(base)} *){helper}(L, {arg_n}, \"{base}\");")
                call_args[i] = v
            elif pp.mode == "pod_in" and pp.info.pointers == 0:
                self.w(f"    {self._struct_ref(base)} {v};")
                self.w(f"    GenRead_{base}(L, {arg_n}, &{v});")
                call_args[i] = v
            elif pp.mode == "pod_in":
                self.w(f"    {self._struct_ref(base)} tmp{i};")
                self.w(f"    const {self._struct_ref(base)} *{v} = NULL;")
                self.w(f"    if (!lua_isnoneornil(L, {arg_n})) {{")
                self.w(f"        GenRead_{base}(L, {arg_n}, &tmp{i});")
                self.w(f"        {v} = &tmp{i};")
                self.w("    }")
                call_args[i] = v
            elif pp.mode == "pod_out":
                self.w(f"    {self._struct_ref(base)} out{i};")
                self.w(f"    memset(&out{i}, 0, sizeof(out{i}));")
                call_args[i] = f"&out{i}"
                post.append(f"    GenPush_{base}(L, &out{i});")
                nret += 1
                i += 1
                continue  # pure out-param: consumes no Lua argument
            elif pp.mode == "inout":
                decl = pp.info.declared or base
                if pp.info.kind == TK.ENUM:
                    decl = self._enum_ref(decl)
                if pp.info.kind == TK.FLOAT:
                    self.w(f"    {decl} io{i} = ({decl})luaL_optnumber(L, {arg_n}, 0);")
                    post.append(f"    lua_pushnumber(L, (lua_Number)io{i});")
                elif pp.info.kind == TK.BOOL:
                    self.w(f"    {decl} io{i} = ({decl})lua_toboolean(L, {arg_n});")
                    post.append(f"    lua_pushboolean(L, (int)io{i});")
                else:
                    self.w(f"    {decl} io{i} = ({decl})luaL_optinteger(L, {arg_n}, 0);")
                    post.append(f"    lua_pushinteger(L, (lua_Integer)io{i});")
                call_args[i] = f"&io{i}"
                nret += 1
            else:
                self.w(f"    /* unhandled mode {pp.mode} */")
                call_args[i] = "0"
            arg_n += 1
            i += 1

        args = ", ".join(call_args[k] for k in sorted(call_args))
        ret = plan.ret
        assert ret is not None
        if ret.kind == TK.VOID:
            self.w(f"    {fn.name}({args});")
        else:
            rspell = self._ret_spell(fn, ret)
            self.w(f"    {rspell} rv = {fn.name}({args});")
        # primary return
        if ret.kind == TK.VOID:
            pass
        elif ret.kind == TK.BOOL:
            self.w("    lua_pushboolean(L, (int)rv);")
            nret += 1
        elif ret.kind in (TK.INT, TK.ENUM):
            self.w("    lua_pushinteger(L, (lua_Integer)rv);")
            nret += 1
        elif ret.kind == TK.FLOAT:
            self.w("    lua_pushnumber(L, (lua_Number)rv);")
            nret += 1
        elif ret.kind == TK.STRING:
            self.w("    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }")
            nret += 1
        elif ret.kind == TK.OWNED_STRING:
            self.w("    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }")
            self.w(f"    if (rv != NULL) {{ {self.lib.free_fn}(rv); }}")
            nret += 1
        elif ret.kind == TK.POD:
            self.w(f"    GenPush_{ret.base}(L, &rv);")
            nret += 1
        elif ret.kind == TK.HANDLE:
            if plan.owned_handle:
                r = self.resources[plan.owned_resource_idx]
                self.w(f"    SDLStaticGen_LuaPushOwned(L, (void *)rv, \"{ret.base}\", GenDtor_{r.destroy});")
            else:
                self.w(f"    SDLStaticGen_LuaPushHandle(L, (void *)rv, \"{ret.base}\");")
            nret += 1
        for line in post:
            self.w(line)
        self.w(f"    return {nret};")
        self.w("}")
        self.w()

    def _handle_ref(self, base: str) -> str:
        if base in self.tt.structs and (base.startswith("nk_") or base == "cJSON"):
            st = self.tt.structs[base]
            del st
            if base.startswith("nk_"):
                return f"struct {base}"
        return base

    def _param_spell(self, pp, param) -> str:
        if pp.info.kind == TK.ENUM:
            return self._enum_ref(pp.info.declared or pp.info.base)
        if pp.info.kind in (TK.INT, TK.FLOAT, TK.BOOL):
            return pp.info.declared or pp.info.base
        return pp.info.base

    def _ret_spell(self, fn, ret) -> str:
        if ret.kind == TK.HANDLE:
            const = "const " if fn.ret.is_const else ""
            return f"{const}{self._handle_ref(ret.base)} *"
        if ret.kind == TK.STRING:
            return "const char *"
        if ret.kind == TK.OWNED_STRING:
            return "char *"
        if ret.kind == TK.POD:
            return self._struct_ref(ret.base)
        if ret.kind == TK.ENUM:
            return self._enum_ref(ret.declared or ret.base)
        if ret.kind in (TK.INT, TK.FLOAT, TK.BOOL):
            return ret.declared or ret.base
        return fn.ret.spelling()


def emit_lua(manifest: Manifest, repo: Path) -> dict[str, dict[str, ScriptPlan]]:
    tt = TypeTable(manifest)
    outdir = repo / "bindings" / "generated"
    outdir.mkdir(parents=True, exist_ok=True)
    outcomes: dict[str, dict[str, ScriptPlan]] = {}
    opens: list[str] = []

    for lib in LIBRARIES:
        library = manifest.libraries[lib.key]
        plans = plan_script(lib.key, library.functions, tt)
        outcomes[lib.key] = plans
        em = _LibEmitter(lib, plans, tt)
        em.w("/* GENERATED FILE - DO NOT EDIT.")
        em.w(" * Regenerate: python3 -m tools.bindgen")
        em.w(f" * Lua bindings for {lib.title}. */")
        em.w("#include \"../src/gen_support_lua.h\"")
        em.w()
        for inc in lib.includes:
            em.w(f"#include {inc}")
        if lib.key == "sdlstatic":
            for header in sorted(set(library.header_names)):
                em.w(f"#include <SDLStatic/{header}>")
        em.w("#include <string.h>")
        em.w()
        bound = {n: p for n, p in plans.items() if p.ok}
        structs = used_pod_structs(bound, tt)
        structs = [s for s in structs if s in tt.structs]
        need_read, need_push = em.converter_needs(bound)
        em.emit_pod_converters(structs, need_read, need_push)
        em.emit_dtor_thunks(bound)
        for name in sorted(bound):
            em.emit_stub(bound[name])
        # registration
        taken: set[str] = set()
        em.w(f"int SDLStaticGen_OpenLua_{lib.key}(lua_State *L);")
        em.w(f"int SDLStaticGen_OpenLua_{lib.key}(lua_State *L)")
        em.w("{")
        em.w(f"    lua_createtable(L, 0, {len(bound)});")
        for name in sorted(bound):
            reg = lua_name(name, lib.prefix, taken)
            em.w(f"    lua_pushcfunction(L, GenL_{name});")
            em.w(f"    lua_setfield(L, -2, \"{reg}\");")
        # enum constants
        seen_const: set[str] = set()
        for ename in sorted(library.enums):
            for value in library.enums[ename].values:
                cname = value[len(lib.prefix):] if value.startswith(lib.prefix) else value
                if not cname or cname in seen_const or cname[0].isdigit():
                    continue
                seen_const.add(cname)
                em.w(f"    lua_pushinteger(L, (lua_Integer){value});")
                em.w(f"    lua_setfield(L, -2, \"{cname}\");")
        em.w(f"    lua_setglobal(L, \"{lib.script_module}\");")
        em.w("    return 0;")
        em.w("}")
        (outdir / f"gen_lua_{lib.key}.c").write_text("\n".join(em.out) + "\n", encoding="utf-8")
        opens.append(f"SDLStaticGen_OpenLua_{lib.key}")

    reg = [
        "/* GENERATED FILE - DO NOT EDIT. Aggregate Lua registration.",
        " * SDLSTATIC_GEN_DISABLE_<LIB> gates modules whose CMake option is",
        " * off on this platform (e.g. NET on Emscripten). */",
        "#include \"../src/gen_support_lua.h\"",
        "",
    ]
    for lib, o in zip(LIBRARIES, opens):
        guard = f"SDLSTATIC_GEN_DISABLE_{lib.key.upper()}"
        reg.append(f"#ifndef {guard}")
        reg.append(f"extern int {o}(lua_State *L);")
        reg.append(f"#endif")
    reg.append("")
    reg.append("int SDLStatic_OpenGeneratedLuaBindings(lua_State *L);")
    reg.append("int SDLStatic_OpenGeneratedLuaBindings(lua_State *L)")
    reg.append("{")
    for lib, o in zip(LIBRARIES, opens):
        guard = f"SDLSTATIC_GEN_DISABLE_{lib.key.upper()}"
        reg.append(f"#ifndef {guard}")
        reg.append(f"    {o}(L);")
        reg.append(f"#endif")
    reg.append("    return 0;")
    reg.append("}")
    reg.append("")
    (outdir / "gen_lua_register.c").write_text("\n".join(reg), encoding="utf-8")
    return outcomes
