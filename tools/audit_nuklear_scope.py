#!/usr/bin/env python3
"""Nuklear's bound surface must be its public API and nothing below it.

Nuklear is a single-header library: the widgets a game calls and the
machinery underneath them live in the same file, separated only by how
they are declared. `NK_API` is the public surface; `NK_LIB` and
`NK_INTERN` are the implementation, and binding those would hand a script
the guts of the layout engine — a pool, a page, a command buffer's write
head — where any mistake is a corrupt context rather than an error.

The parser only accepts NK_API, so this holds by construction. That is
exactly the kind of property that breaks quietly when someone widens a
regex, hence a test rather than a comment.

Two things are checked, because "bound" means two different things:

  functions   every bound nk_* function is declared NK_API
  structs     only value types a public signature actually passes get
              field access. Everything else stays an opaque handle: a
              script may hold it and give it back, and cannot read or
              write a field of it.

Run standalone or under ctest; exits non-zero with the offenders named.
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

# The value types Nuklear passes by value through its public API. A script
# sees these as tables; everything else is a handle it cannot look inside.
PUBLIC_VALUE_TYPES = {"nk_color", "nk_colorf", "nk_rect", "nk_scroll", "nk_vec2"}


def main() -> int:
    repo = Path(__file__).resolve().parent.parent
    header = (repo / "gui" / "include" / "nuklear.h").read_text(errors="ignore")
    generated = (repo / "bindings" / "generated" / "gen_lua_nk.c").read_text()

    public = set(re.findall(r"NK_API[^;{]*?\b(nk_\w+)\s*\(", header))
    internal = set(re.findall(r"NK_(?:LIB|INTERN)[^;{]*?\b(nk_\w+)\s*\(", header))
    internal -= public  # a few are declared both ways; the public one wins

    bound = set(re.findall(r"GenL_(nk_\w+)\b", generated))
    converted = set(re.findall(r"Gen(?:Read|Push)_(nk_\w+)\b", generated))

    failures: list[str] = []

    leaked = sorted(bound & internal)
    if leaked:
        failures.append(f"internal functions bound: {', '.join(leaked)}")

    unknown = sorted(bound - public)
    if unknown:
        failures.append(f"bound but not declared NK_API: {', '.join(unknown)}")

    extra = sorted(converted - PUBLIC_VALUE_TYPES)
    if extra:
        failures.append(
            "field access into non-value structs: " + ", ".join(extra) +
            " — these should stay opaque handles"
        )

    if failures:
        print("nuklear scope audit FAILED", file=sys.stderr)
        for failure in failures:
            print(f"  {failure}", file=sys.stderr)
        return 1

    print(f"nuklear scope ok: {len(bound)} public functions bound, "
          f"{len(internal)} internals excluded, "
          f"field access limited to {len(converted)} value types")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
