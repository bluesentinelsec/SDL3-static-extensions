"""Type resolution and per-function binding classification.

Every function ends up in exactly one bucket per surface, so the coverage
report can account for 100% of the parsed API:

  C++:   factory | method | status | alias            (never skipped)
  Lua:   bound | skipped(reason)
  Ruby:  same plan as Lua (shared shape rules)
"""

from __future__ import annotations

import re

from dataclasses import dataclass, field
from enum import Enum as PyEnum

from .model import (
    SCALAR_BOOLS,
    SCALAR_FLOATS,
    SCALAR_INTS,
    CType,
    Function,
    Manifest,
    Struct,
)
from .spec import LIBRARIES, POD_SKIP_FIELD_STRUCTS, RESOURCES, LibrarySpec


class TK(PyEnum):
    VOID = "void"
    INT = "int"
    FLOAT = "float"
    BOOL = "bool"
    ENUM = "enum"
    STRING = "string"  # const char*
    OWNED_STRING = "owned_string"  # char* the caller must free
    HANDLE = "handle"  # pointer to opaque type
    POD = "pod"  # marshalable struct
    FUNCPTR = "funcptr"
    VOIDP = "voidp"
    OTHER = "other"


@dataclass
class TypeInfo:
    kind: TK
    base: str = ""
    pointers: int = 0
    is_const: bool = False
    declared: str = ""  # base name as written in the header


class TypeTable:
    """Global name -> category resolution across all libraries."""

    def __init__(self, manifest: Manifest) -> None:
        self.enums: set[str] = set()
        self.plain_enums: set[str] = set()
        self.opaque: set[str] = set()
        self.structs: dict[str, Struct] = {}
        self.aliases: dict[str, str] = {}
        for lib in manifest.libraries.values():
            self.enums |= set(lib.enums)
            self.plain_enums |= {n for n, e in lib.enums.items() if e.plain}
            self.opaque |= lib.opaque
            self.structs.update(lib.structs)
            self.aliases.update(lib.typedef_aliases)
        # Well-known typedefs the headers define via macros we don't expand.
        self.aliases.setdefault("SDL_AudioDeviceID", "Uint32")
        self.aliases.setdefault("SDL_JoystickID", "Uint32")
        self.aliases.setdefault("SDL_CameraID", "Uint32")
        self.aliases.setdefault("SDL_SensorID", "Uint32")
        self.aliases.setdefault("SDL_DisplayID", "Uint32")
        self.aliases.setdefault("SDL_WindowID", "Uint32")
        self.aliases.setdefault("SDL_KeyboardID", "Uint32")
        self.aliases.setdefault("SDL_MouseID", "Uint32")
        self.aliases.setdefault("SDL_PenID", "Uint32")
        self.aliases.setdefault("SDL_TouchID", "Uint64")
        self.aliases.setdefault("SDL_FingerID", "Uint64")
        self.aliases.setdefault("SDL_PropertiesID", "Uint32")
        self.aliases.setdefault("SDL_ThreadID", "Uint64")
        self.aliases.setdefault("SDL_TimerID", "Uint32")
        self.aliases.setdefault("SDL_Keycode", "Uint32")
        self.aliases.setdefault("SDL_Keymod", "Uint16")
        self.aliases.setdefault("SDL_GlyphIndex", "Uint32")
        self.aliases.setdefault("MIX_TrackID", "Uint32")
        self.aliases.setdefault("NK_BOOL", "int")
        self.aliases.setdefault("NK_INT8", "int8_t")
        self.aliases.setdefault("NK_UINT8", "uint8_t")
        self.aliases.setdefault("NK_INT16", "int16_t")
        self.aliases.setdefault("NK_UINT16", "uint16_t")
        self.aliases.setdefault("NK_INT32", "int32_t")
        self.aliases.setdefault("NK_UINT32", "uint32_t")
        self.aliases.setdefault("NK_SIZE_TYPE", "uintptr_t")
        self.aliases.setdefault("NK_POINTER_TYPE", "uintptr_t")
        self._pod_cache: dict[str, bool] = {}

    def resolve_base(self, base: str, depth: int = 0) -> str:
        while base in self.aliases and depth < 8:
            nxt = self.aliases[base]
            if nxt == base:
                break
            base = nxt
            depth += 1
        return base

    def is_pod_struct(self, name: str) -> bool:
        if name in self._pod_cache:
            return self._pod_cache[name]
        self._pod_cache[name] = False  # break cycles
        st = self.structs.get(name)
        ok = False
        if st is not None and st.complete and not st.is_union and st.fields:
            if name in POD_SKIP_FIELD_STRUCTS:
                ok = any(self._field_ok(f.type) for f in st.fields)
            else:
                ok = all(self._field_ok(f.type) for f in st.fields)
        self._pod_cache[name] = ok
        return ok

    def field_marshalable(self, t: CType) -> bool:
        return self._field_ok(t)

    def _field_ok(self, t: CType) -> bool:
        if t.pointers:
            return False
        # Declared name first: config-macro typedefs (nk_byte -> NK_UINT8)
        # make the declared name the reliable signal.
        for probe in (t.base, self.resolve_base(t.base)):
            if probe in SCALAR_INTS or probe in SCALAR_FLOATS or probe in SCALAR_BOOLS:
                return True
        base = self.resolve_base(t.base)
        if base in self.enums:
            return True
        if base in self.structs:
            return self.is_pod_struct(base)
        return False

    def _scalar_kind(self, name: str, is_unsigned: bool) -> TK | None:
        if name in SCALAR_BOOLS:
            return TK.BOOL
        if name in SCALAR_INTS or (is_unsigned and name == "int"):
            return TK.INT
        if name in SCALAR_FLOATS:
            return TK.FLOAT
        return None

    def info(self, t: CType) -> TypeInfo:
        out = self._info(t)
        if t.base != "<funcptr>":
            out.declared = f"unsigned {t.base}" if t.is_unsigned else t.base
        return out

    def _info(self, t: CType) -> TypeInfo:
        if t.base == "<funcptr>":
            return TypeInfo(TK.FUNCPTR)
        base = self.resolve_base(t.base)
        if base == "void":
            if t.pointers == 0:
                return TypeInfo(TK.VOID)
            return TypeInfo(TK.VOIDP, base, t.pointers, t.is_const)
        if base == "char" and t.pointers == 1:
            if t.is_unsigned:
                # unsigned char* is a byte buffer, not a C string; const
                # ones pair with a length param via the blob rule.
                return TypeInfo(TK.VOIDP, base, 1, t.is_const)
            if t.is_const:
                return TypeInfo(TK.STRING, base, 1, True)
            return TypeInfo(TK.OWNED_STRING, base, 1, False)
        # Scalars: check the declared name too — some (nk_bool) resolve
        # through config macros, and the declared name is the truth.
        scalar = self._scalar_kind(t.base, t.is_unsigned) or self._scalar_kind(
            base, t.is_unsigned
        )
        if t.pointers == 0:
            if scalar is not None:
                return TypeInfo(scalar, base)
            if base in self.enums:
                return TypeInfo(TK.ENUM, base)
            if base in self.structs and self.is_pod_struct(base):
                return TypeInfo(TK.POD, base)
            return TypeInfo(TK.OTHER, base)
        # Pointer types
        if base in self.opaque or (base in self.structs and not self.structs[base].complete):
            if t.pointers == 1:
                return TypeInfo(TK.HANDLE, base, 1, t.is_const)
            return TypeInfo(TK.OTHER, base, t.pointers)
        if t.pointers == 1:
            if base in self.structs and self.is_pod_struct(base):
                return TypeInfo(TK.POD, base, 1, t.is_const)
            if base in self.structs:
                # Complete but unmarshalable struct (pointer fields, etc.):
                # treat the pointer as an opaque borrowed handle. Scripts
                # never dereference it; C keeps full access.
                return TypeInfo(TK.HANDLE, base, 1, t.is_const)
            if scalar is not None:
                return TypeInfo(scalar, base, 1, t.is_const)
            if base in self.enums:
                return TypeInfo(TK.ENUM, base, 1, t.is_const)
        return TypeInfo(TK.OTHER, base, t.pointers, t.is_const)


# ---------------------------------------------------------------------------
# Script-surface exclusions: families that make no sense (or are hazardous)
# from Lua/Ruby. Kept data-driven so the coverage report shows them with an
# explicit reason instead of silently dropping them.

SCRIPT_EXCLUDE_PREFIXES: dict[str, str] = {
    # libc-clone layer: scripts have their own strings/memory/math
    "SDL_malloc": "stdlib clone", "SDL_calloc": "stdlib clone",
    "SDL_realloc": "stdlib clone", "SDL_free": "stdlib clone",
    "SDL_mem": "stdlib clone", "SDL_str": "stdlib clone",
    "SDL_wcs": "stdlib clone", "SDL_ulltoa": "stdlib clone",
    "SDL_lltoa": "stdlib clone", "SDL_ltoa": "stdlib clone",
    "SDL_ultoa": "stdlib clone", "SDL_itoa": "stdlib clone",
    "SDL_uitoa": "stdlib clone", "SDL_atoi": "stdlib clone",
    "SDL_atof": "stdlib clone", "SDL_sscanf": "stdlib clone",
    "SDL_snprintf": "stdlib clone", "SDL_swprintf": "stdlib clone",
    "SDL_vsnprintf": "stdlib clone", "SDL_vswprintf": "stdlib clone",
    "SDL_asprintf": "stdlib clone", "SDL_vasprintf": "stdlib clone",
    "SDL_qsort": "stdlib clone", "SDL_bsearch": "stdlib clone",
    "SDL_abs": "stdlib clone", "SDL_isalpha": "stdlib clone",
    "SDL_isalnum": "stdlib clone", "SDL_isblank": "stdlib clone",
    "SDL_iscntrl": "stdlib clone", "SDL_isdigit": "stdlib clone",
    "SDL_isxdigit": "stdlib clone", "SDL_ispunct": "stdlib clone",
    "SDL_isspace": "stdlib clone", "SDL_isupper": "stdlib clone",
    "SDL_islower": "stdlib clone", "SDL_isprint": "stdlib clone",
    "SDL_isgraph": "stdlib clone", "SDL_toupper": "stdlib clone",
    "SDL_tolower": "stdlib clone", "SDL_crc": "stdlib clone",
    "SDL_murmur3": "stdlib clone", "SDL_copysign": "stdlib clone",
    "SDL_acos": "math clone", "SDL_asin": "math clone",
    "SDL_atan": "math clone", "SDL_ceil": "math clone",
    "SDL_cos": "math clone", "SDL_exp": "math clone",
    "SDL_fabs": "math clone", "SDL_floor": "math clone",
    "SDL_fmod": "math clone", "SDL_log": "math clone",
    "SDL_lround": "math clone", "SDL_modf": "math clone",
    "SDL_pow": "math clone", "SDL_round": "math clone",
    "SDL_scalbn": "math clone", "SDL_sin": "math clone",
    "SDL_sqrt": "math clone", "SDL_tan": "math clone",
    "SDL_trunc": "math clone", "SDL_isinf": "math clone",
    "SDL_isnan": "math clone", "SDL_rand": "math clone",
    "SDL_srand": "math clone", "SDL_randf": "math clone",
    # native concurrency has no place in the script sandbox
    "SDL_CreateThread": "threading", "SDL_WaitThread": "threading",
    "SDL_DetachThread": "threading", "SDL_GetThread": "threading",
    "SDL_SetCurrentThread": "threading", "SDL_GetCurrentThread": "threading",
    "SDL_LockMutex": "threading", "SDL_TryLockMutex": "threading",
    "SDL_UnlockMutex": "threading", "SDL_CreateMutex": "threading",
    "SDL_DestroyMutex": "threading", "SDL_LockRWLock": "threading",
    "SDL_TryLockRWLock": "threading", "SDL_UnlockRWLock": "threading",
    "SDL_CreateRWLock": "threading", "SDL_DestroyRWLock": "threading",
    "SDL_SignalSemaphore": "threading", "SDL_WaitSemaphore": "threading",
    "SDL_TryWaitSemaphore": "threading", "SDL_CreateSemaphore": "threading",
    "SDL_DestroySemaphore": "threading", "SDL_GetSemaphoreValue": "threading",
    "SDL_SignalCondition": "threading", "SDL_BroadcastCondition": "threading",
    "SDL_WaitCondition": "threading", "SDL_CreateCondition": "threading",
    "SDL_DestroyCondition": "threading", "SDL_SetTLS": "threading",
    "SDL_GetTLS": "threading", "SDL_CleanupTLS": "threading",
    "SDL_AtomicCompareAndSwap": "threading", "SDL_SetAtomic": "threading",
    "SDL_GetAtomic": "threading", "SDL_AddAtomic": "threading",
    "SDL_MemoryBarrier": "threading", "SDL_CompilerBarrier": "threading",
    "SDL_CPUPauseInstruction": "threading",
}


def script_excluded(name: str) -> str | None:
    for prefix, reason in SCRIPT_EXCLUDE_PREFIXES.items():
        if name == prefix or name.startswith(prefix):
            return reason
    return None


# ---------------------------------------------------------------------------
# Binding plans


@dataclass
class ParamPlan:
    param_index: int
    cname: str
    info: TypeInfo
    mode: str  # "in" | "inout" | "out" | "handle_in" | "pod_in" | "pod_out"


@dataclass
class ScriptPlan:
    fn: Function
    ok: bool
    reason: str = ""
    params: list[ParamPlan] = field(default_factory=list)
    ret: TypeInfo | None = None
    owned_handle: bool = False  # return value passes ownership (register GC)
    owned_resource_idx: int = -1  # index into RESOURCES[lib] when owned


@dataclass
class CppPlan:
    fn: Function
    bucket: str  # "factory" | "method" | "status" | "alias"
    resource_idx: int = -1


def _resource_maps(lib_key: str):
    specs = RESOURCES.get(lib_key, [])
    by_create: dict[str, int] = {}
    by_type: dict[str, int] = {}
    destroys: set[str] = set()
    for i, r in enumerate(specs):
        for c in r.create_fns:
            by_create[c] = i
        by_type[r.ctype] = i
        destroys.add(r.destroy)
    return specs, by_create, by_type, destroys


def plan_cpp(lib_key: str, functions: dict[str, Function], tt: TypeTable) -> dict[str, CppPlan]:
    specs, by_create, by_type, destroys = _resource_maps(lib_key)
    spec = next(s for s in LIBRARIES if s.key == lib_key)
    plans: dict[str, CppPlan] = {}
    for name, fn in functions.items():
        if name in by_create:
            plans[name] = CppPlan(fn, "factory", by_create[name])
            continue
        if name in destroys:
            continue  # consumed by the destructor; not exposed standalone
        first = fn.params[0] if fn.params else None
        if first is not None:
            fi = tt.info(first.type)
            key = first.type.base
            if key in by_type and (
                (fi.kind == TK.HANDLE and fi.pointers == 1)
                or (key in by_type and specs[by_type[key]].by_value and fi.pointers == 0)
            ):
                plans[name] = CppPlan(fn, "method", by_type[key])
                continue
        ri = tt.info(fn.ret)
        if ri.kind == TK.BOOL and ri.pointers == 0 and spec.error_fn and not fn.variadic:
            has_funcptr = any(tt.info(p.type).kind == TK.FUNCPTR for p in fn.params)
            if not has_funcptr:
                plans[name] = CppPlan(fn, "status")
                continue
        plans[name] = CppPlan(fn, "alias")
    return plans


def plan_script(lib_key: str, functions: dict[str, Function], tt: TypeTable) -> dict[str, ScriptPlan]:
    specs, by_create, by_type, destroys = _resource_maps(lib_key)
    plans: dict[str, ScriptPlan] = {}
    for name, fn in functions.items():
        reason = script_excluded(name)
        if reason:
            plans[name] = ScriptPlan(fn, ok=False, reason=reason)
            continue
        if fn.variadic:
            plans[name] = ScriptPlan(fn, ok=False, reason="variadic")
            continue
        ri = tt.info(fn.ret)
        if ri.kind in (TK.FUNCPTR, TK.OTHER, TK.VOIDP) or (
            ri.kind in (TK.INT, TK.FLOAT, TK.BOOL, TK.ENUM) and ri.pointers
        ):
            plans[name] = ScriptPlan(fn, ok=False, reason=f"return type {fn.ret.spelling()}")
            continue
        if ri.kind == TK.POD and ri.pointers:
            plans[name] = ScriptPlan(fn, ok=False, reason="returns struct pointer")
            continue
        lib_spec = next(s for s in LIBRARIES if s.key == lib_key)
        if ri.kind == TK.OWNED_STRING and not lib_spec.free_fn:
            plans[name] = ScriptPlan(fn, ok=False, reason="owned string, no free fn")
            continue
        pplans: list[ParamPlan] = []
        bad = ""
        skip_next = False
        for i, p in enumerate(fn.params):
            if skip_next:
                skip_next = False
                continue
            pi = tt.info(p.type)
            # (const void *data, <int> len) pairs: bind as one script string.
            if (
                pi.kind == TK.VOIDP
                and pi.is_const
                and pi.pointers == 1
                and i + 1 < len(fn.params)
                and tt.info(fn.params[i + 1].type).kind == TK.INT
                and tt.info(fn.params[i + 1].type).pointers == 0
                and re.search(
                    r"len|size|count|bytes|num", fn.params[i + 1].name, re.I
                )
            ):
                pplans.append(ParamPlan(i, p.name, pi, "blob_in"))
                skip_next = True
                continue
            if pi.kind in (TK.INT, TK.FLOAT, TK.BOOL, TK.ENUM) and pi.pointers == 0:
                pplans.append(ParamPlan(i, p.name, pi, "in"))
            elif pi.kind == TK.STRING:
                pplans.append(ParamPlan(i, p.name, pi, "in"))
            elif pi.kind == TK.HANDLE and not pi.is_const:
                pplans.append(ParamPlan(i, p.name, pi, "handle_in"))
            elif pi.kind == TK.HANDLE:
                pplans.append(ParamPlan(i, p.name, pi, "handle_in"))
            elif pi.kind == TK.POD and pi.pointers == 0:
                pplans.append(ParamPlan(i, p.name, pi, "pod_in"))
            elif pi.kind == TK.POD and pi.pointers == 1 and pi.is_const:
                pplans.append(ParamPlan(i, p.name, pi, "pod_in"))
            elif pi.kind == TK.POD and pi.pointers == 1:
                pplans.append(ParamPlan(i, p.name, pi, "pod_out"))
            elif pi.kind in (TK.INT, TK.FLOAT, TK.BOOL, TK.ENUM) and pi.pointers == 1 and not pi.is_const:
                pplans.append(ParamPlan(i, p.name, pi, "inout"))
            else:
                bad = f"param {p.name}: {p.type.spelling()}"
                break
        if bad:
            plans[name] = ScriptPlan(fn, ok=False, reason=bad)
            continue
        owned = name in by_create and ri.kind == TK.HANDLE
        plans[name] = ScriptPlan(
            fn,
            ok=True,
            params=pplans,
            ret=ri,
            owned_handle=owned,
            owned_resource_idx=by_create.get(name, -1) if owned else -1,
        )
    return plans


def used_pod_structs(plans: dict[str, ScriptPlan], tt: TypeTable) -> list[str]:
    """POD structs referenced by bound functions, in dependency order."""
    used: set[str] = set()

    def add(name: str) -> None:
        if name in used:
            return
        used.add(name)
        st = tt.structs.get(name)
        if st:
            for f in st.fields:
                base = tt.resolve_base(f.type.base)
                if base in tt.structs and tt.is_pod_struct(base):
                    add(base)

    for plan in plans.values():
        if not plan.ok:
            continue
        if plan.ret and plan.ret.kind == TK.POD:
            add(plan.ret.base)
        for pp in plan.params:
            if pp.info.kind == TK.POD:
                add(pp.info.base)
    ordered: list[str] = []
    seen: set[str] = set()

    def visit(name: str) -> None:
        if name in seen:
            return
        seen.add(name)
        st = tt.structs.get(name)
        if st:
            for f in st.fields:
                base = tt.resolve_base(f.type.base)
                if base in used and base != name:
                    visit(base)
        ordered.append(name)

    for name in sorted(used):
        visit(name)
    return ordered
