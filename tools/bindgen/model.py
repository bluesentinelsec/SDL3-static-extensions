"""Data model for the binding generator.

The parser produces a Manifest of Functions, Structs, Enums, and opaque
Handles per library. Emitters classify every function into exactly one
bucket per language surface, so coverage is always accounted for:

  C++:  raii-factory | raii-method | status-wrapped | alias | skipped(reason)
  Lua:  bound | skipped(reason)
  Ruby: bound | skipped(reason)
"""

from __future__ import annotations

from dataclasses import dataclass, field


@dataclass
class CType:
    """A parsed C type: base name + pointer depth + qualifiers."""

    base: str  # e.g. "int", "SDL_Window", "char"
    pointers: int = 0
    is_const: bool = False
    is_unsigned: bool = False
    is_struct_kw: bool = False  # declared as "struct X"

    def spelling(self) -> str:
        parts = []
        if self.is_const:
            parts.append("const")
        if self.is_unsigned:
            parts.append("unsigned")
        if self.is_struct_kw:
            parts.append("struct")
        parts.append(self.base)
        return " ".join(parts) + "*" * self.pointers


@dataclass
class Param:
    type: CType
    name: str
    raw: str = ""  # original declaration text, re-emitted verbatim in C++


@dataclass
class Function:
    name: str
    ret: CType
    params: list[Param]
    variadic: bool = False
    header: str = ""
    raw_ret: str = ""  # original return-type text


@dataclass
class StructField:
    type: CType
    name: str
    array_len: str | None = None  # "3" for float v[3]; None otherwise


@dataclass
class Struct:
    name: str
    fields: list[StructField]
    is_union: bool = False
    complete: bool = True  # False when we bailed on parsing the body


@dataclass
class Enum:
    name: str
    values: list[str]
    plain: bool = False  # declared without typedef; C spelling needs "enum"


@dataclass
class Library:
    """One vendored library / module surface."""

    key: str  # short id: "sdl", "mix", "b2", ...
    functions: dict[str, Function] = field(default_factory=dict)
    structs: dict[str, Struct] = field(default_factory=dict)
    enums: dict[str, Enum] = field(default_factory=dict)
    opaque: set[str] = field(default_factory=set)  # forward-declared structs
    typedef_aliases: dict[str, str] = field(default_factory=dict)
    header_names: list[str] = field(default_factory=list)  # parsed files


@dataclass
class Manifest:
    libraries: dict[str, Library] = field(default_factory=dict)

    def all_type_names(self) -> set[str]:
        names: set[str] = set()
        for lib in self.libraries.values():
            names |= set(lib.structs)
            names |= set(lib.enums)
            names |= lib.opaque
            names |= set(lib.typedef_aliases)
        return names


# C scalar type bases the marshalers understand (plus enums, resolved
# per-manifest). Fixed-width ints come from stdint/SDL_stdinc.
SCALAR_INTS = {
    "int",
    "long",
    "short",
    "char",
    "size_t",
    "ptrdiff_t",
    "intptr_t",
    "uintptr_t",
    "int8_t",
    "uint8_t",
    "int16_t",
    "uint16_t",
    "int32_t",
    "uint32_t",
    "int64_t",
    "uint64_t",
    "Sint8",
    "Uint8",
    "Sint16",
    "Uint16",
    "Sint32",
    "Uint32",
    "Sint64",
    "Uint64",
    "PHYSFS_sint64",
    "PHYSFS_uint64",
    "PHYSFS_sint32",
    "PHYSFS_uint32",
    "PHYSFS_sint16",
    "PHYSFS_uint16",
    "nk_size",
    "nk_flags",
    "nk_uint",
    "nk_int",
    "nk_byte",
    "nk_ushort",
    "nk_short",
    "nk_hash",
    "nk_rune",
    "unsigned",
}

SCALAR_FLOATS = {"float", "double"}

SCALAR_BOOLS = {"bool", "SDL_bool", "nk_bool", "cJSON_bool", "mrb_bool"}
