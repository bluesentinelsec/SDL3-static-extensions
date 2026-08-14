"""mruby emitter: mirrors the Lua surface as Ruby modules.

Module functions live on modules named after each library (SDL, MIX, ...,
SDLStaticC), with enum enumerators as module constants. Same call/return
convention as Lua: primary return first (nil for NULL), then out/in-out
params; owned handles are GC-managed Data objects; bound destroy
functions empty the box.

Stubs read arguments via mrb_get_args(mrb, "*") and convert with the
lenient To* helpers, so absent/nil trailing arguments become 0/NULL —
matching the Lua side's optional out-params.
"""

from __future__ import annotations

from pathlib import Path

from .classify import TK, ScriptPlan, TypeTable, plan_script, used_pod_structs
from .model import Manifest
from .spec import LIBRARIES, RESOURCES, LibrarySpec

_RUBY_RESERVED = {
    "alias", "and", "begin", "break", "case", "class", "def", "defined?",
    "do", "else", "elsif", "end", "ensure", "false", "for", "if", "in",
    "module", "next", "nil", "not", "or", "redo", "rescue", "retry",
    "return", "self", "super", "then", "true", "undef", "unless", "until",
    "when", "while", "yield",
}


def ruby_fn_name(cname: str, prefix: str, taken: set[str]) -> str:
    out = cname[len(prefix):] if cname.startswith(prefix) else cname
    if not out or not (out[0].isalpha() or out[0] == "_"):
        out = cname
    if out in _RUBY_RESERVED:
        out += "_"
    if out in taken:
        out = cname
    taken.add(out)
    return out


class _RubyEmitter:
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

    def _struct_ref(self, name: str) -> str:
        if name.startswith("nk_"):
            return f"struct {name}"
        return name

    def _enum_ref(self, name: str) -> str:
        if name in self.tt.plain_enums:
            return f"enum {name}"
        return name

    def _field_kind(self, ftype) -> str:
        from .model import SCALAR_BOOLS, SCALAR_FLOATS, SCALAR_INTS

        for probe in (ftype.base, self.tt.resolve_base(ftype.base)):
            if probe in SCALAR_FLOATS:
                return "num"
            if probe in SCALAR_BOOLS:
                return "bool"
            if probe in SCALAR_INTS:
                return "int"
        rbase = self.tt.resolve_base(ftype.base)
        if rbase in self.tt.enums:
            return "int"
        if rbase in self.tt.structs:
            return "pod"
        return "int"

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
            ref = self._struct_ref(sname)
            if sname in need_read:
                self.w(f"static void GenRead_{sname}(mrb_state *mrb, mrb_value h, {ref} *out)")
                self.w("{")
                self.w("    memset(out, 0, sizeof(*out));")
                self.w("    if (!mrb_hash_p(h)) { return; }")
                for f in st.fields:
                    self._emit_field_read(f)
                self.w("}")
                self.w()
            if sname in need_push:
                self.w(f"static mrb_value GenPush_{sname}(mrb_state *mrb, const {ref} *in)")
                self.w("{")
                self.w("    mrb_value h = mrb_hash_new(mrb);")
                for f in st.fields:
                    self._emit_field_push(f)
                self.w("    return h;")
                self.w("}")
                self.w()

    def _emit_field_read(self, f) -> None:
        kind = self._field_kind(f.type)
        base = self.tt.resolve_base(f.type.base)
        if f.array_len is not None:
            self.w(f"    {{")
            self.w(f"        mrb_value arr = SDLStaticGen_RubyFieldGet(mrb, h, \"{f.name}\");")
            self.w("        if (mrb_array_p(arr)) {")
            self.w(f"            for (mrb_int gi = 0; gi < (mrb_int)({f.array_len}) && gi < RARRAY_LEN(arr); ++gi) {{")
            self.w("                mrb_value el = mrb_ary_ref(mrb, arr, gi);")
            if kind == "pod":
                self.w(f"                GenRead_{base}(mrb, el, &out->{f.name}[gi]);")
            elif kind == "num":
                self.w(f"                out->{f.name}[gi] = ({f.type.base})SDLStaticGen_RubyToNum(mrb, el);")
            else:
                self.w(f"                out->{f.name}[gi] = ({f.type.base})SDLStaticGen_RubyToInt(mrb, el);")
            self.w("            }")
            self.w("        }")
            self.w("    }")
            return
        if kind == "pod":
            self.w(f"    GenRead_{base}(mrb, SDLStaticGen_RubyFieldGet(mrb, h, \"{f.name}\"), &out->{f.name});")
        elif kind == "num":
            self.w(f"    out->{f.name} = ({f.type.base})SDLStaticGen_RubyFieldNum(mrb, h, \"{f.name}\");")
        elif kind == "bool":
            self.w(f"    out->{f.name} = ({f.type.base})SDLStaticGen_RubyFieldBool(mrb, h, \"{f.name}\");")
        else:
            self.w(f"    out->{f.name} = ({f.type.base})SDLStaticGen_RubyFieldInt(mrb, h, \"{f.name}\");")

    def _emit_field_push(self, f) -> None:
        kind = self._field_kind(f.type)
        base = self.tt.resolve_base(f.type.base)
        if f.array_len is not None:
            self.w(f"    {{")
            self.w(f"        mrb_value arr = mrb_ary_new_capa(mrb, (mrb_int)({f.array_len}));")
            self.w(f"        for (mrb_int gi = 0; gi < (mrb_int)({f.array_len}); ++gi) {{")
            if kind == "pod":
                self.w(f"            mrb_ary_push(mrb, arr, GenPush_{base}(mrb, &in->{f.name}[gi]));")
            elif kind == "num":
                self.w(f"            mrb_ary_push(mrb, arr, mrb_float_value(mrb, (mrb_float)in->{f.name}[gi]));")
            else:
                self.w(f"            mrb_ary_push(mrb, arr, mrb_int_value(mrb, (mrb_int)in->{f.name}[gi]));")
            self.w("        }")
            self.w(f"        SDLStaticGen_RubyHashSet(mrb, h, \"{f.name}\", arr);")
            self.w("    }")
            return
        if kind == "pod":
            self.w(f"    SDLStaticGen_RubyHashSet(mrb, h, \"{f.name}\", GenPush_{base}(mrb, &in->{f.name}));")
        elif kind == "num":
            self.w(f"    SDLStaticGen_RubyHashSet(mrb, h, \"{f.name}\", mrb_float_value(mrb, (mrb_float)in->{f.name}));")
        elif kind == "bool":
            self.w(f"    SDLStaticGen_RubyHashSet(mrb, h, \"{f.name}\", mrb_bool_value((mrb_bool)(in->{f.name} != 0)));")
        else:
            self.w(f"    SDLStaticGen_RubyHashSet(mrb, h, \"{f.name}\", mrb_int_value(mrb, (mrb_int)in->{f.name}));")

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

    # -- stubs -------------------------------------------------------------

    def emit_stub(self, plan: ScriptPlan) -> None:
        fn = plan.fn
        self.w(f"static mrb_value GenR_{fn.name}(mrb_state *mrb, mrb_value self)")
        self.w("{")
        self.w("    const mrb_value *argv = NULL;")
        self.w("    mrb_int argc = 0;")
        self.w("    (void)self;")
        self.w("    mrb_get_args(mrb, \"*\", &argv, &argc);")
        self.w("    {")
        arg_n = 0
        call_args: dict[int, str] = {}
        rets: list[str] = []  # expressions pushed to result array
        post: list[str] = []
        i = 0
        params = fn.params
        pp_by_index = {pp.param_index: pp for pp in plan.params}

        def argval(n: int) -> str:
            return f"(argc > {n} ? argv[{n}] : mrb_nil_value())"

        while i < len(params):
            pp = pp_by_index.get(i)
            if pp is None:
                i += 1
                continue
            v = f"a{i}"
            base = pp.info.base
            if pp.mode == "blob_in":
                self.w(f"    size_t len{i} = 0;")
                self.w(f"    const char *{v} = SDLStaticGen_RubyToBlob(mrb, {argval(arg_n)}, &len{i});")
                call_args[i] = f"(const void *){v}"
                nxt = params[i + 1]
                call_args[i + 1] = f"({nxt.type.spelling()})len{i}"
                arg_n += 1
                i += 2
                continue
            if pp.mode == "in" and pp.info.kind in (TK.INT, TK.ENUM):
                spell = self._enum_ref(pp.info.declared or base) if pp.info.kind == TK.ENUM else (pp.info.declared or base)
                self.w(f"    {spell} {v} = ({spell})SDLStaticGen_RubyToInt(mrb, {argval(arg_n)});")
                call_args[i] = v
            elif pp.mode == "in" and pp.info.kind == TK.FLOAT:
                spell = pp.info.declared or base
                self.w(f"    {spell} {v} = ({spell})SDLStaticGen_RubyToNum(mrb, {argval(arg_n)});")
                call_args[i] = v
            elif pp.mode == "in" and pp.info.kind == TK.BOOL:
                spell = pp.info.declared or base
                self.w(f"    {spell} {v} = ({spell})SDLStaticGen_RubyToBool({argval(arg_n)});")
                call_args[i] = v
            elif pp.mode == "in" and pp.info.kind == TK.STRING:
                self.w(f"    const char *{v} = SDLStaticGen_RubyToStr(mrb, {argval(arg_n)});")
                call_args[i] = v
            elif pp.mode == "handle_in":
                take = fn.name in self.destroys and i == 0
                helper = "SDLStaticGen_RubyTakeHandle" if take else "SDLStaticGen_RubyCheckHandle"
                const = "const " if pp.info.is_const else ""
                self.w(f"    {const}{self._handle_ref(base)} *{v} = "
                       f"({const}{self._handle_ref(base)} *){helper}(mrb, {argval(arg_n)}, \"{base}\");")
                call_args[i] = v
            elif pp.mode == "pod_in" and pp.info.pointers == 0:
                self.w(f"    {self._struct_ref(base)} {v};")
                self.w(f"    GenRead_{base}(mrb, {argval(arg_n)}, &{v});")
                call_args[i] = v
            elif pp.mode == "pod_in":
                self.w(f"    {self._struct_ref(base)} tmp{i};")
                self.w(f"    const {self._struct_ref(base)} *{v} = NULL;")
                self.w(f"    if (argc > {arg_n} && mrb_hash_p(argv[{arg_n}])) {{")
                self.w(f"        GenRead_{base}(mrb, argv[{arg_n}], &tmp{i});")
                self.w(f"        {v} = &tmp{i};")
                self.w("    }")
                call_args[i] = v
            elif pp.mode == "pod_out":
                self.w(f"    {self._struct_ref(base)} out{i};")
                self.w(f"    memset(&out{i}, 0, sizeof(out{i}));")
                call_args[i] = f"&out{i}"
                post.append(f"GenPush_{base}(mrb, &out{i})")
                i += 1
                continue  # pure out-param: consumes no Ruby argument
            elif pp.mode == "inout":
                decl = pp.info.declared or base
                if pp.info.kind == TK.ENUM:
                    decl = self._enum_ref(decl)
                if pp.info.kind == TK.FLOAT:
                    self.w(f"    {decl} io{i} = ({decl})SDLStaticGen_RubyToNum(mrb, {argval(arg_n)});")
                    post.append(f"mrb_float_value(mrb, (mrb_float)io{i})")
                elif pp.info.kind == TK.BOOL:
                    self.w(f"    {decl} io{i} = ({decl})SDLStaticGen_RubyToBool({argval(arg_n)});")
                    post.append(f"mrb_bool_value((mrb_bool)(io{i} != 0))")
                else:
                    self.w(f"    {decl} io{i} = ({decl})SDLStaticGen_RubyToInt(mrb, {argval(arg_n)});")
                    post.append(f"mrb_int_value(mrb, (mrb_int)io{i})")
                call_args[i] = f"&io{i}"
            else:
                call_args[i] = "0"
            arg_n += 1
            i += 1

        args = ", ".join(call_args[k] for k in sorted(call_args))
        ret = plan.ret
        assert ret is not None
        if ret.kind == TK.VOID:
            self.w(f"    {fn.name}({args});")
        else:
            self.w(f"    {self._ret_spell(fn, ret)} rv = {fn.name}({args});")
        primary = None
        if ret.kind == TK.BOOL:
            primary = "mrb_bool_value((mrb_bool)(rv != 0))"
        elif ret.kind in (TK.INT, TK.ENUM):
            primary = "mrb_int_value(mrb, (mrb_int)rv)"
        elif ret.kind == TK.FLOAT:
            primary = "mrb_float_value(mrb, (mrb_float)rv)"
        elif ret.kind == TK.STRING:
            primary = "(rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv))"
        elif ret.kind == TK.OWNED_STRING:
            self.w("    mrb_value rstr = rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv);")
            self.w(f"    if (rv != NULL) {{ {self.lib.free_fn}(rv); }}")
            primary = "rstr"
        elif ret.kind == TK.POD:
            primary = f"GenPush_{ret.base}(mrb, &rv)"
        elif ret.kind == TK.HANDLE:
            if plan.owned_handle:
                r = self.resources[plan.owned_resource_idx]
                primary = (f"SDLStaticGen_RubyPushOwned(mrb, (void *)rv, \"{ret.base}\", "
                           f"GenDtor_{r.destroy})")
            else:
                primary = f"SDLStaticGen_RubyPushHandle(mrb, (void *)rv, \"{ret.base}\")"

        outs = ([primary] if primary else []) + post
        if not outs:
            self.w("    return mrb_nil_value();")
        elif len(outs) == 1:
            self.w(f"    return {outs[0]};")
        else:
            self.w(f"    mrb_value rets[{len(outs)}];")
            for k, expr in enumerate(outs):
                self.w(f"    rets[{k}] = {expr};")
            self.w(f"    return mrb_ary_new_from_values(mrb, {len(outs)}, rets);")
        self.w("    }")
        self.w("}")
        self.w()

    def _handle_ref(self, base: str) -> str:
        if base.startswith("nk_"):
            return f"struct {base}"
        return base

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


def emit_ruby(manifest: Manifest, repo: Path) -> dict[str, dict[str, ScriptPlan]]:
    tt = TypeTable(manifest)
    outdir = repo / "bindings" / "generated"
    outdir.mkdir(parents=True, exist_ok=True)
    outcomes: dict[str, dict[str, ScriptPlan]] = {}
    opens: list[str] = []

    for lib in LIBRARIES:
        library = manifest.libraries[lib.key]
        plans = plan_script(lib.key, library.functions, tt)
        outcomes[lib.key] = plans
        em = _RubyEmitter(lib, plans, tt)
        em.w("/* GENERATED FILE - DO NOT EDIT.")
        em.w(" * Regenerate: python3 -m tools.bindgen")
        em.w(f" * mruby bindings for {lib.title}. */")
        em.w("#include \"../src/gen_support_ruby.h\"")
        em.w()
        for inc in lib.includes:
            em.w(f"#include {inc}")
        if lib.key == "sdlstatic":
            for header in sorted(set(library.header_names)):
                em.w(f"#include <SDLStatic/{header}>")
        em.w("#include <string.h>")
        em.w()
        bound = {n: p for n, p in plans.items() if p.ok}
        structs = [s for s in used_pod_structs(bound, tt) if s in tt.structs]
        need_read, need_push = em.converter_needs(bound)
        em.emit_pod_converters(structs, need_read, need_push)
        em.emit_dtor_thunks(bound)
        for name in sorted(bound):
            em.emit_stub(bound[name])

        taken: set[str] = set()
        em.w(f"void SDLStaticGen_OpenRuby_{lib.key}(mrb_state *mrb);")
        em.w(f"void SDLStaticGen_OpenRuby_{lib.key}(mrb_state *mrb)")
        em.w("{")
        em.w("    struct RClass *mod;")
        em.w("    SDLStaticGen_RubyEnsureHandleClass(mrb);")
        em.w(f"    mod = mrb_define_module(mrb, \"{lib.script_module}\");")
        for name in sorted(bound):
            reg = ruby_fn_name(name, lib.prefix, taken)
            em.w(f"    mrb_define_module_function(mrb, mod, \"{reg}\", GenR_{name}, MRB_ARGS_ANY());")
        seen_const: set[str] = set()
        for ename in sorted(library.enums):
            for value in library.enums[ename].values:
                cname = value[len(lib.prefix):] if value.startswith(lib.prefix) else value
                if not cname or cname in seen_const or not cname[0].isalpha():
                    continue
                cname = cname if cname[0].isupper() else cname.upper()
                if cname in seen_const:
                    continue
                seen_const.add(cname)
                em.w(f"    mrb_define_const(mrb, mod, \"{cname}\", mrb_int_value(mrb, (mrb_int){value}));")
        em.w("}")
        (outdir / f"gen_ruby_{lib.key}.c").write_text("\n".join(em.out) + "\n")
        opens.append(f"SDLStaticGen_OpenRuby_{lib.key}")

    reg = [
        "/* GENERATED FILE - DO NOT EDIT. Aggregate mruby registration. */",
        "#include \"../src/gen_support_ruby.h\"",
        "",
    ]
    for o in opens:
        reg.append(f"extern void {o}(mrb_state *mrb);")
    reg.append("")
    reg.append("void SDLStatic_OpenGeneratedRubyBindings(mrb_state *mrb);")
    reg.append("void SDLStatic_OpenGeneratedRubyBindings(mrb_state *mrb)")
    reg.append("{")
    for o in opens:
        reg.append(f"    {o}(mrb);")
    reg.append("}")
    reg.append("")
    (outdir / "gen_ruby_register.c").write_text("\n".join(reg))
    return outcomes
