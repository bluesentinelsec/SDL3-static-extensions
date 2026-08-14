"""Regex-based parser for the vendored C headers.

These headers follow rigid per-library declaration macros
(SDL_DECLSPEC/SDLCALL, PHYSFS_DECL, B2_API, NK_API, CJSON_PUBLIC, plain
extern for SDLStatic modules), which makes a targeted scanner far more
robust here than it would be for arbitrary C — and keeps the generator
dependency-free (no libclang).
"""

from __future__ import annotations

import re
from pathlib import Path

from .model import CType, Enum, Function, Library, Param, Struct, StructField

# ---------------------------------------------------------------------------
# Preprocessing


def strip_comments(text: str) -> str:
    # Preserve newlines so #directive line structure survives.
    text = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), text, flags=re.S)
    text = re.sub(r"//[^\n]*", " ", text)
    return text


def strip_line_continuations(text: str) -> str:
    return text.replace("\\\n", " ")


# ---------------------------------------------------------------------------
# Conditional-region tracking.
#
# We do not run a real preprocessor. Instead we track #if nesting and mark
# regions whose condition either (a) mentions a platform/compiler gate, or
# (b) tests a config macro we know the truth of (Nuklear's NK_INCLUDE_* set
# from SDLStatic/nuklear.h). Declarations inside excluded regions are
# dropped, so the committed generated code never references symbols that
# only exist on some platforms or under a different single-header config.

_PLATFORM_GATE_RE = re.compile(
    r"SDL_PLATFORM_|SDL_WIKI_DOCUMENTATION|_WIN32|_WIN64|WINRT|__WINRT__|GDK"
    r"|__ANDROID__|ANDROID|__APPLE__|__IPHONEOS__|__TVOS__|TARGET_OS"
    r"|__linux__|__unix__|__EMSCRIPTEN__|EMSCRIPTEN|__GNUC__|_MSC_VER"
    r"|__clang__|VULKAN_H_|__OBJC__|SDL_FUNCTION_POINTER_IS_VOID_POINTER"
    # Build-config gates: a declaration that only exists in debug (or only
    # release) builds cannot be referenced by committed generated code.
    r"|NDEBUG|B2_ENABLE_ASSERT|_DEBUG"
)

# Macros defined by our single-header configs / build. Conditions that test
# one of these resolve exactly; see gui/include/SDLStatic/nuklear.h.
# Mirrors gui/include/SDLStatic/nuklear.h exactly — the tool verifies this
# at generation time (see check_nk_config).
_KNOWN_TRUE = {
    "NK_INCLUDE_FIXED_TYPES",
    "NK_INCLUDE_STANDARD_BOOL",
    "NK_INCLUDE_DEFAULT_ALLOCATOR",
    "NK_INCLUDE_STANDARD_VARARGS",
    "NK_INCLUDE_VERTEX_BUFFER_OUTPUT",
    "NK_INCLUDE_FONT_BAKING",
    "NK_INCLUDE_DEFAULT_FONT",
    "NK_BUTTON_TRIGGER_ON_RELEASE",
}
_KNOWN_FALSE = {
    "NK_IMPLEMENTATION",
    "NK_INCLUDE_STANDARD_IO",
    "NK_INCLUDE_COMMAND_USERDATA",
    "NK_INCLUDE_SOFTWARE_FONT",
    "NK_UINT_DRAW_INDEX",
    "NK_KEYSTATE_BASED_INPUT",
}


def check_nk_config(wrapper_header: Path) -> None:
    """Assert _KNOWN_TRUE matches the NK_INCLUDE_* set in the wrapper."""
    defined = set(re.findall(r"^#define\s+(NK_[A-Z_]+)", wrapper_header.read_text(), re.M))
    include_true = {n for n in _KNOWN_TRUE if n.startswith("NK_INCLUDE_")}
    include_defined = {n for n in defined if n.startswith("NK_INCLUDE_")}
    if include_true != include_defined:
        raise SystemExit(
            f"bindgen NK config drift: tool={sorted(include_true)} "
            f"wrapper={sorted(include_defined)} — update parse.py"
        )


def _condition_excluded(expr: str, negated: bool) -> bool | None:
    """Best-effort truth for one #if condition.

    Returns True when the region must be EXCLUDED, False when definitely
    included, None when unknown (treated as included).
    """
    expr = expr.strip()
    m = re.fullmatch(r"(?:defined\s*\(?\s*)?([A-Za-z_][A-Za-z0-9_]*)\s*\)?", expr)
    if m:
        name = m.group(1)
        if name in _KNOWN_TRUE:
            return negated
        if name in _KNOWN_FALSE:
            return not negated
        if _PLATFORM_GATE_RE.search(name):
            # Unknown platform gate: exclude the positive branch, keep the
            # negative one ("#ifndef PLATFORM" regions are the portable path).
            return not negated
        return None
    if _PLATFORM_GATE_RE.search(expr):
        return not negated
    if all(tok in _KNOWN_TRUE for tok in re.findall(r"NK_[A-Z_]+", expr)) and "NK_" in expr:
        return negated
    return None


def excluded_spans(text: str) -> list[tuple[int, int]]:
    """Byte ranges of the text that sit inside excluded #if regions."""
    spans: list[tuple[int, int]] = []
    # Stack entries: [start_of_current_branch or None, this_branch_excluded,
    #                 any_prior_branch_taken, condition_known]
    stack: list[list] = []
    for m in re.finditer(r"^[ \t]*#[ \t]*(\w+)([^\n]*)$", text, flags=re.M):
        directive, rest = m.group(1), m.group(2).strip()
        pos_start, pos_end = m.start(), m.end()
        if directive in ("if", "ifdef", "ifndef"):
            negated = directive == "ifndef"
            expr = rest
            verdict = _condition_excluded(expr, negated)
            excluded = verdict is True
            stack.append([pos_end if excluded else None, excluded,
                          verdict is False, verdict is not None])
        elif directive in ("elif", "else") and stack:
            frame = stack[-1]
            if frame[0] is not None:  # close the excluded branch
                spans.append((frame[0], pos_start))
                frame[0] = None
            if directive == "elif":
                verdict = _condition_excluded(rest, False)
            else:
                # #else of a known-true condition is excluded; of a
                # known-false (i.e. we excluded the if-branch) is included.
                verdict = True if frame[2] else (False if (frame[3] and frame[1]) else None)
            excluded = verdict is True
            frame[1] = excluded
            if excluded:
                frame[0] = pos_end
        elif directive == "endif" and stack:
            frame = stack.pop()
            if frame[0] is not None:
                spans.append((frame[0], pos_start))
            # Propagate exclusion into enclosing frame: nothing to do — nested
            # regions inside an excluded span are already covered by it.
    # Close any still-open excluded frames at EOF (e.g. a guard whose #endif
    # is the file's final line and produced no further directive matches).
    for frame in stack:
        if frame[0] is not None:
            spans.append((frame[0], len(text)))
    return spans


def _in_spans(pos: int, spans: list[tuple[int, int]]) -> bool:
    return any(a <= pos < b for a, b in spans)


# ---------------------------------------------------------------------------
# Type parsing

_TYPE_TOKEN_DROP = {
    "SDL_DECLSPEC",
    "SDLCALL",
    "extern",
    "PHYSFS_DECL",
    "B2_API",
    "B2_INLINE",
    "NK_API",
    "TOML_EXTERN",
    "YAML_DECLARE",
    "SDL_MALLOC",
    "SDL_ALLOC_SIZE",
    "SDL_ALLOC_SIZE2",
    "SDL_DECL_NORETURN",
    "SDL_ANALYZER_NORETURN",
    "SDL_PRINTF_VARARG_FUNC",
    "SDL_PRINTF_VARARG_FUNCV",
    "SDL_SCANF_VARARG_FUNC",
    "SDL_WPRINTF_VARARG_FUNC",
    "restrict",
    "SDL_RESTRICT",
    "inline",
    "static",
}


def parse_ctype(spelling: str) -> CType | None:
    spelling = spelling.strip()
    # "T * const name" pointer-constness is irrelevant at call sites and
    # must not be confused with pointee constness.
    spelling = re.sub(r"\*\s*const\b", "*", spelling)
    pointers = spelling.count("*")
    spelling = spelling.replace("*", " ")
    tokens = [t for t in spelling.split() if t and t not in _TYPE_TOKEN_DROP]
    is_const = "const" in tokens
    tokens = [t for t in tokens if t not in ("const", "volatile")]
    is_struct_kw = False
    if tokens and tokens[0] in ("struct", "enum", "union"):
        is_struct_kw = tokens[0] == "struct"
        tokens = tokens[1:]
    is_unsigned = False
    if tokens and tokens[0] in ("unsigned", "signed"):
        is_unsigned = tokens[0] == "unsigned"
        if len(tokens) == 1:
            tokens = ["int"]
        else:
            tokens = tokens[1:]
    if not tokens:
        return None
    if tokens in (["long", "long"], ["long", "long", "int"], ["long", "int"]):
        tokens = ["long"]
    if tokens == ["short", "int"]:
        tokens = ["short"]
    if len(tokens) != 1:
        return None
    base = tokens[0]
    if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", base):
        return None
    return CType(
        base=base,
        pointers=pointers,
        is_const=is_const,
        is_unsigned=is_unsigned,
        is_struct_kw=is_struct_kw,
    )


def parse_params(paramtext: str) -> tuple[list[Param], bool] | None:
    """Parse a parameter list. Returns (params, variadic) or None on bail."""
    paramtext = paramtext.strip()
    if paramtext in ("", "void"):
        return [], False
    variadic = False
    params: list[Param] = []
    depth = 0
    parts: list[str] = []
    current = ""
    for ch in paramtext:
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
        if ch == "," and depth == 0:
            parts.append(current)
            current = ""
        else:
            current += ch
    parts.append(current)
    for i, raw in enumerate(parts):
        raw = raw.strip()
        if raw == "...":
            variadic = True
            continue
        if "(" in raw:  # function-pointer parameter — keep as marker
            m = re.search(r"\(\s*\*+\s*([A-Za-z_][A-Za-z0-9_]*)?\s*\)", raw)
            name = (m.group(1) if m and m.group(1) else f"cb{i}")
            params.append(Param(CType(base="<funcptr>", pointers=1), name, raw=raw))
            continue
        if "[" in raw:  # array parameter — treat as extra pointer
            raw2 = re.sub(r"\[[^\]]*\]", "", raw)
            ptype_name = _split_decl(raw2)
            if ptype_name is None:
                return None
            ctype, name = ptype_name
            ctype.pointers += 1
            params.append(Param(ctype, name or f"arg{i}", raw=raw))
            continue
        ptype_name = _split_decl(raw)
        if ptype_name is None:
            return None
        ctype, name = ptype_name
        params.append(Param(ctype, name or f"arg{i}", raw=raw))
    return params, variadic


def _split_decl(raw: str) -> tuple[CType, str] | None:
    """Split 'const char *name' into (CType, name). Name may be absent."""
    raw = raw.strip()
    # Whole-declaration-as-type first: unnamed params like "int" or
    # "struct nk_color" must not have their tail eaten as a name
    # ("int" -> type "i", name "nt").
    whole = parse_ctype(raw)
    if whole is not None:
        return whole, ""
    m = re.fullmatch(r"(.+?)\s*([A-Za-z_][A-Za-z0-9_]*)?\s*", raw, flags=re.S)
    if not m:
        return None
    typepart, name = m.group(1), m.group(2) or ""
    probe = parse_ctype(typepart)
    if probe is None:
        return None
    return probe, name


# ---------------------------------------------------------------------------
# Declaration scanning

_FUNC_PATTERNS = {
    "sdl": re.compile(
        r"extern\s+SDL_DECLSPEC\s+(?P<ret>[^;()]*?)\s*SDLCALL\s+"
        r"(?P<name>[A-Za-z_][A-Za-z0-9_]*)\s*\((?P<params>[^;]*?)\)\s*;",
        flags=re.S,
    ),
    "physfs": re.compile(
        r"PHYSFS_DECL\s+(?P<ret>[^;()]*?[\s*])\s*"
        r"(?P<name>PHYSFS_[A-Za-z0-9_]*)\s*\((?P<params>[^;]*?)\)\s*;",
        flags=re.S,
    ),
    "b2": re.compile(
        r"B2_API\s+(?P<ret>[^;()]*?[\s*])\s*"
        r"(?P<name>b2[A-Za-z0-9_]*)\s*\((?P<params>[^;]*?)\)\s*;",
        flags=re.S,
    ),
    "nk": re.compile(
        r"NK_API\s+(?P<ret>[^;()]*?[\s*])\s*"
        r"(?P<name>nk_[A-Za-z0-9_]*)\s*\((?P<params>[^;]*?)\)\s*;",
        flags=re.S,
    ),
    "cjson": re.compile(
        r"CJSON_PUBLIC\(\s*(?P<ret>[^;()]*?)\s*\)\s+"
        r"(?P<name>cJSON_[A-Za-z0-9_]*)\s*\((?P<params>[^;]*?)\)\s*;",
        flags=re.S,
    ),
    "toml": re.compile(
        r"TOML_EXTERN\s+(?P<ret>[^;()]*?[\s*])\s*"
        r"(?P<name>toml_[A-Za-z0-9_]*)\s*\((?P<params>[^;]*?)\)\s*;",
        flags=re.S,
    ),
    "yaml": re.compile(
        r"YAML_DECLARE\(\s*(?P<ret>[^;()]*?)\s*\)\s+"
        r"(?P<name>yaml_[A-Za-z0-9_]*)\s*\((?P<params>[^;]*?)\)\s*;",
        flags=re.S,
    ),
    "sdlstatic": re.compile(
        r"extern\s+(?P<ret>[^;()]*?[\s*])\s*"
        r"(?P<name>SDLStatic_[A-Za-z0-9_]*)\s*\((?P<params>[^;]*?)\)\s*;",
        flags=re.S,
    ),
}

_OPAQUE_RE = re.compile(
    r"typedef\s+struct\s+([A-Za-z_][A-Za-z0-9_]*)\s+([A-Za-z_][A-Za-z0-9_]*)\s*;"
)

_ENUM_RE = re.compile(
    r"typedef\s+enum\s+([A-Za-z_][A-Za-z0-9_]*)?\s*\{(.*?)\}\s*([A-Za-z_][A-Za-z0-9_]*)\s*;",
    flags=re.S,
)

_STRUCT_RE = re.compile(
    r"typedef\s+(struct|union)\s+([A-Za-z_][A-Za-z0-9_]*)?\s*\{(.*?)\}\s*"
    r"([A-Za-z_][A-Za-z0-9_]*)\s*;",
    flags=re.S,
)

_TYPEDEF_ALIAS_RE = re.compile(
    r"typedef\s+((?:unsigned\s+|signed\s+)?[A-Za-z_][A-Za-z0-9_]*)\s+"
    r"([A-Za-z_][A-Za-z0-9_]*)\s*;"
)

_FIELD_RE = re.compile(
    r"^\s*((?:const\s+|unsigned\s+|signed\s+|struct\s+|enum\s+)*[A-Za-z_][A-Za-z0-9_]*"
    r"(?:\s*\*+\s*|\s+))"
    r"([A-Za-z_][A-Za-z0-9_]*(?:\s*,\s*[A-Za-z_][A-Za-z0-9_]*)*)"
    r"\s*(\[\s*[A-Za-z0-9_]+\s*\])?\s*;"
)


def parse_header(lib: Library, path: Path, macro_style: str) -> None:
    text = strip_line_continuations(strip_comments(path.read_text(errors="replace")))
    pattern = _FUNC_PATTERNS[macro_style]
    dead = excluded_spans(text)

    for m in pattern.finditer(text):
        if _in_spans(m.start(), dead):
            continue
        name = m.group("name")
        ret = parse_ctype(m.group("ret"))
        if ret is None:
            continue
        parsed = parse_params(m.group("params"))
        if parsed is None:
            continue
        params, variadic = parsed
        lib.functions[name] = Function(
            name=name, ret=ret, params=params, variadic=variadic, header=path.name,
            raw_ret=re.sub(r"\s+", " ", m.group("ret")).strip(),
        )

    for m in _OPAQUE_RE.finditer(text):
        if _in_spans(m.start(), dead):
            continue
        if m.group(1) == m.group(2):
            lib.opaque.add(m.group(2))

    for m in _ENUM_RE.finditer(text):
        if _in_spans(m.start(), dead):
            continue
        name = m.group(3)
        values = re.findall(r"([A-Za-z_][A-Za-z0-9_]*)\s*(?:=[^,}]*)?(?:,|\s*$)", m.group(2))
        lib.enums[name] = Enum(name=name, values=values)

    for m in _STRUCT_RE.finditer(text):
        if _in_spans(m.start(), dead):
            continue
        kind, body, name = m.group(1), m.group(3), m.group(4)
        lib.structs[name] = _parse_struct_body(name, body, kind == "union")

    # Plain (non-typedef) struct definitions: Nuklear and cJSON declare
    # "struct nk_rect { ... };" without a typedef. Brace-matched by hand.
    for m in re.finditer(r"\bstruct\s+([A-Za-z_][A-Za-z0-9_]*)\s*\{", text):
        if _in_spans(m.start(), dead):
            continue
        name = m.group(1)
        if name in lib.structs:
            continue
        if re.match(r"typedef\s*$", text[max(0, m.start() - 16):m.start()].strip()):
            continue  # typedef struct handled above
        depth = 1
        i = m.end()
        while i < len(text) and depth:
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
            i += 1
        body = text[m.end():i - 1]
        if "{" in body:
            lib.structs[name] = Struct(name=name, fields=[], is_union=False, complete=False)
        else:
            lib.structs[name] = _parse_struct_body(name, body, False)

    # Plain (non-typedef) enums: "enum nk_buttons { ... };"
    for m in re.finditer(
        r"\benum\s+([A-Za-z_][A-Za-z0-9_]*)\s*\{(.*?)\}\s*;", text, flags=re.S
    ):
        if _in_spans(m.start(), dead):
            continue
        name = m.group(1)
        if name in lib.enums or "{" in m.group(2):
            continue
        values = re.findall(r"([A-Za-z_][A-Za-z0-9_]*)\s*(?:=[^,}]*)?(?:,|\s*$)", m.group(2))
        lib.enums[name] = Enum(name=name, values=values, plain=True)

    for m in _TYPEDEF_ALIAS_RE.finditer(text):
        if _in_spans(m.start(), dead):
            continue
        src, dst = m.group(1), m.group(2)
        if src not in ("struct", "enum", "union") and dst not in lib.structs:
            lib.typedef_aliases[dst] = src.split()[-1]


def _parse_struct_body(name: str, body: str, is_union: bool) -> Struct:
    if "{" in body:
        return Struct(name=name, fields=[], is_union=is_union, complete=False)
    fields: list[StructField] = []
    ok = True
    for line in body.split(";"):
        line = line.strip()
        if not line:
            continue
        fm = _FIELD_RE.match(line + ";")
        if not fm:
            ok = False
            continue
        ftype = parse_ctype(fm.group(1))
        if ftype is None:
            ok = False
            continue
        arr = fm.group(3)
        arr_len = arr.strip("[] \t") if arr else None
        for fname in [n.strip() for n in fm.group(2).split(",")]:
            fields.append(StructField(type=ftype, name=fname, array_len=arr_len))
    return Struct(name=name, fields=fields, is_union=is_union, complete=ok)
