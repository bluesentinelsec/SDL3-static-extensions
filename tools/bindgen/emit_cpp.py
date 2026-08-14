"""C++ emitter: RAII classes + Status wrappers + aliases per library.

Output: cpp/include/sdlstatic/gen/<key>.h under namespace
sdlstatic::<ns>. Generated classes never collide with the hand-written
ergonomic layer (different namespaces); the C API stays fully reachable.

Everything is emitted from the parsed headers' own raw declaration text,
so parameter/return types are spelled exactly as upstream spelled them.
"""

from __future__ import annotations

import re
from pathlib import Path

from .classify import CppPlan, TypeTable, plan_cpp
from .model import Function, Manifest
from .spec import LIBRARIES, RESOURCES, LibrarySpec

NAMESPACES = {
    "sdl": "sdl",
    "mix": "mix",
    "img": "img",
    "ttf": "ttf",
    "net": "net",
    "physfs": "vfs",
    "b2": "b2",
    "nk": "nk",
    "cjson": "json",
    "sdlstatic": "ext",
}

_CPP_KEYWORDS = {
    "alignas", "alignof", "and", "asm", "auto", "bool", "break", "case",
    "catch", "char", "class", "concept", "const", "constexpr", "continue",
    "default", "delete", "do", "double", "else", "enum", "explicit",
    "export", "extern", "false", "float", "for", "friend", "goto", "if",
    "inline", "int", "long", "mutable", "namespace", "new", "noexcept",
    "not", "nullptr", "operator", "or", "private", "protected", "public",
    "register", "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "template", "this", "throw", "true", "try", "typedef",
    "typeid", "typename", "union", "unsigned", "using", "virtual", "void",
    "volatile", "while", "xor",
}


# Names libc/compilers commonly define as macros: an alias named `isinf`
# would be macro-expanded on platforms (Emscripten) where math.h defines it.
_MACRO_TRAPS = {
    "isinf", "isnan", "isfinite", "isnormal", "signbit", "fpclassify",
    "assert", "errno", "alloca", "stdin", "stdout", "stderr", "environ",
}


def stripped(name: str, prefix: str) -> str:
    out = name[len(prefix):] if name.startswith(prefix) else name
    if out in _CPP_KEYWORDS or out in _MACRO_TRAPS or not re.match(r"[A-Za-z_]", out):
        out += "_"
    return out


def _param_decls(fn: Function) -> tuple[list[str], list[str]]:
    """(declaration strings, forward names) for a function's params."""
    decls: list[str] = []
    names: list[str] = []
    for i, p in enumerate(fn.params):
        raw = re.sub(r"\s+", " ", p.raw).strip()
        name = p.name
        if p.type.base == "<funcptr>":
            m = re.search(r"\(\s*\*+\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)", raw)
            if m:
                decls.append(raw)
                names.append(m.group(1))
                continue
            # typedef'd callback ("SDL_EventFilter filter") parses as a
            # normal decl; unnamed inline fn-ptr types get a name injected.
            if re.search(r"\(\s*\*\s*\)", raw):
                decls.append(raw.replace("(*)", f"(*cbg{i})", 1))
                names.append(f"cbg{i}")
                continue
            decls.append(raw)
            names.append(name)
            continue
        if not name or name == f"arg{i}":
            has_name = bool(name) and raw.rstrip().endswith(name)
            if not has_name:
                name = f"a{i}"
                if "[" in raw:
                    bracket = raw.index("[")
                    raw = raw[:bracket] + " " + name + raw[bracket:]
                else:
                    raw = raw + " " + name
        if name in _CPP_KEYWORDS:
            new = name + "_"
            raw = re.sub(rf"\b{name}\b(?!.*\b{name}\b)", new, raw)
            name = new
        decls.append(raw)
        names.append(name)
    return decls, names


def _is_void(fn: Function) -> bool:
    return fn.ret.base == "void" and fn.ret.pointers == 0


class _ClassBuilder:
    def __init__(self, lib: LibrarySpec, res, tt: TypeTable) -> None:
        self.lib = lib
        self.res = res
        self.tt = tt
        self.factories: list[Function] = []
        self.methods: list[Function] = []

    def emit(self) -> str:
        r = self.res
        store = r.ctype if r.by_value else f"{r.ctype}*"
        null_value = "{}" if r.by_value else "nullptr"
        invalid = r.invalid_expr.replace("{v}", "created_")
        lines: list[str] = []
        w = lines.append
        w(f"// RAII owner for {r.ctype} (destroyed with {r.destroy}).")
        w(f"class {r.cpp_class} {{")
        w(" public:")
        for fn in self.factories:
            decls, names = _param_decls(fn)
            fname = stripped(fn.name, self.lib.prefix)
            arglist = ", ".join(decls)
            w(f"  static Result<{r.cpp_class}> {fname}({arglist}) {{")
            w(f"    {store} created_ = ::{fn.name}({', '.join(names)});")
            w(f"    if ({invalid}) {{")
            if self.lib.error_fn == "SDL_GetError()":
                w("      return Status::FromSdl();")
            elif self.lib.error_fn:
                w(f"      return Status::Error({self.lib.error_fn});")
            else:
                w(f'      return Status::Error("{fn.name} failed");')
            w("    }")
            w(f"    return {r.cpp_class}(created_);")
            w("  }")
        w("")
        w(f"  {r.cpp_class}() = default;")
        w(f"  ~{r.cpp_class}() {{ reset(); }}")
        w(f"  {r.cpp_class}({r.cpp_class}&& other) noexcept")
        w("      : value_(other.value_), engaged_(other.engaged_) {")
        w(f"    other.value_ = {null_value};")
        w("    other.engaged_ = false;")
        w("  }")
        w(f"  {r.cpp_class}& operator=({r.cpp_class}&& other) noexcept {{")
        w("    if (this != &other) {")
        w("      reset();")
        w("      value_ = other.value_;")
        w("      engaged_ = other.engaged_;")
        w(f"      other.value_ = {null_value};")
        w("      other.engaged_ = false;")
        w("    }")
        w("    return *this;")
        w("  }")
        w(f"  {r.cpp_class}(const {r.cpp_class}&) = delete;")
        w(f"  {r.cpp_class}& operator=(const {r.cpp_class}&) = delete;")
        w("")
        w(f"  {store} get() const {{ return value_; }}")
        w(f"  {store} release() {{")
        w(f"    {store} out = value_;")
        w(f"    value_ = {null_value};")
        w("    engaged_ = false;")
        w("    return out;")
        w("  }")
        w("  void reset() {")
        if r.by_value:
            w(f"    if (engaged_) ::{r.destroy}(value_);")
            w(f"    value_ = {null_value};")
        else:
            w(f"    if (value_ != nullptr) ::{r.destroy}(value_);")
            w("    value_ = nullptr;")
        w("    engaged_ = false;")
        w("  }")
        w("")
        for fn in self.methods:
            self._emit_method(w, fn)
        w(" private:")
        w(f"  explicit {r.cpp_class}({store} value) : value_(value), engaged_(true) {{}}")
        w(f"  {store} value_{{}};")
        w("  bool engaged_ = false;")
        w("};")
        w("")
        return "\n".join(lines)

    def _emit_method(self, w, fn: Function) -> None:
        decls, names = _param_decls(fn)
        decls, names = decls[1:], ["value_"] + names[1:]
        fname = stripped(fn.name, self.lib.prefix)
        arglist = ", ".join(decls)
        ret_raw = fn.ret.spelling()
        ri = self.tt.info(fn.ret)
        from .classify import TK

        if (
            ri.kind == TK.BOOL
            and ri.pointers == 0
            and self.lib.error_fn == "SDL_GetError()"
        ):
            w(f"  Status {fname}({arglist}) {{")
            w(f"    return ::{fn.name}({', '.join(names)}) ? Status() : Status::FromSdl();")
            w("  }")
        elif _is_void(fn):
            w(f"  void {fname}({arglist}) {{ ::{fn.name}({', '.join(names)}); }}")
        else:
            w(f"  {ret_raw} {fname}({arglist}) {{")
            w(f"    return ::{fn.name}({', '.join(names)});")
            w("  }")


def emit_cpp(manifest: Manifest, repo: Path) -> dict[str, dict[str, CppPlan]]:
    tt = TypeTable(manifest)
    outdir = repo / "cpp" / "include" / "sdlstatic" / "gen"
    outdir.mkdir(parents=True, exist_ok=True)
    outcomes: dict[str, dict[str, CppPlan]] = {}
    umbrella_includes: list[str] = []

    for lib in LIBRARIES:
        library = manifest.libraries[lib.key]
        plans = plan_cpp(lib.key, library.functions, tt)
        outcomes[lib.key] = plans
        ns = NAMESPACES[lib.key]
        specs = RESOURCES.get(lib.key, [])

        builders = [_ClassBuilder(lib, r, tt) for r in specs]
        by_idx = {i: b for i, b in enumerate(builders)}
        aliases: list[Function] = []
        statuses: list[Function] = []
        for plan in plans.values():
            if plan.bucket == "factory":
                by_idx[plan.resource_idx].factories.append(plan.fn)
            elif plan.bucket == "method":
                by_idx[plan.resource_idx].methods.append(plan.fn)
            elif plan.bucket == "status":
                statuses.append(plan.fn)
            else:
                aliases.append(plan.fn)

        lines: list[str] = []
        w = lines.append
        w("// GENERATED FILE - DO NOT EDIT.")
        w("// Regenerate: python3 -m tools.bindgen (see tools/bindgen/README.md)")
        w(f"// Library: {lib.title}")
        w("// clang-format off")
        guard = f"SDLSTATIC_CPP_GEN_{lib.key.upper()}_H_"
        w(f"#ifndef {guard}")
        w(f"#define {guard}")
        w("")
        for inc in ["<SDL3/SDL.h>"] + lib.includes:
            if inc != "<SDL3/SDL.h>" or lib.key == "sdl":
                w(f"#include {inc}")
        if lib.key == "sdlstatic":
            for header in sorted(_sdlstatic_headers(manifest)):
                w(f"#include <SDLStatic/{header}>")
        w("")
        w('#include "sdlstatic/status.h"')
        w("")
        w("namespace sdlstatic {")
        w(f"namespace {ns} {{")
        w("")
        for b in builders:
            if b.factories or b.methods:
                w(b.emit())
        if statuses:
            w("// bool-returning C functions surfaced as Status.")
            for fn in sorted(statuses, key=lambda f: f.name):
                decls, names = _param_decls(fn)
                fname = stripped(fn.name, lib.prefix)
                w(f"inline Status {fname}({', '.join(decls)}) {{")
                w(f"  return ::{fn.name}({', '.join(names)}) ? Status() : Status::FromSdl();")
                w("}")
            w("")
        if aliases:
            w("// Everything else, aliased into the namespace unchanged.")
            seen: set[str] = set()
            for fn in sorted(aliases, key=lambda f: f.name):
                fname = stripped(fn.name, lib.prefix)
                if fname in seen:
                    fname = stripped(fn.name, "")
                seen.add(fname)
                w(f"inline constexpr auto& {fname} = ::{fn.name};")
            w("")
        w(f"}}  // namespace {ns}")
        w("}  // namespace sdlstatic")
        w("")
        w(f"#endif  // {guard}")
        w("// clang-format on")
        w("")
        (outdir / f"{lib.key}.h").write_text("\n".join(lines, encoding="utf-8"))
        umbrella_includes.append(f'#include "sdlstatic/gen/{lib.key}.h"')

    guarded = []
    for inc in umbrella_includes:
        if "/net.h" in inc:
            # Net does not exist on Emscripten builds (no-stubs policy).
            guarded.append("#if __has_include(<SDL3_net/SDL_net.h>)")
            guarded.append(inc)
            guarded.append("#endif")
        else:
            guarded.append(inc)
    umbrella = [
        "// GENERATED FILE - DO NOT EDIT.",
        "// Umbrella for the generated C++ surface: every parsed C API,",
        "// as RAII owners, Status wrappers, or namespace aliases.",
        "#ifndef SDLSTATIC_CPP_GEN_GEN_H_",
        "#define SDLSTATIC_CPP_GEN_GEN_H_",
        "",
        *guarded,
        "",
        "#endif  // SDLSTATIC_CPP_GEN_GEN_H_",
        "",
    ]
    (outdir / "gen.h").write_text("\n".join(umbrella, encoding="utf-8"))
    return outcomes


def _sdlstatic_headers(manifest: Manifest) -> set[str]:
    return {
        fn.header
        for fn in manifest.libraries["sdlstatic"].functions.values()
        if fn.header
    }
