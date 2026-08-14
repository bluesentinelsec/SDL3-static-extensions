"""bindgen CLI: parse headers, emit bindings + coverage report.

Usage:
  python3 -m tools.bindgen --repo . --deps build/_deps [--stats-only]
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

from .model import Library, Manifest
from .parse import parse_header
from .spec import LIBRARIES, resolve_headers


def build_manifest(repo: Path, deps: Path) -> Manifest:
    from .parse import check_nk_config

    check_nk_config(repo / "gui" / "include" / "SDLStatic" / "nuklear.h")
    manifest = Manifest()
    for spec in LIBRARIES:
        lib = Library(key=spec.key)
        headers = resolve_headers(spec, repo, deps)
        if not headers:
            print(f"warning: no headers found for {spec.key}", file=sys.stderr)
        for header in headers:
            parse_header(lib, header, spec.macro_style)
            lib.header_names.append(header.name)
        for name in spec.exclude:
            lib.functions.pop(name, None)
        manifest.libraries[spec.key] = lib
    return manifest


def print_stats(manifest: Manifest) -> None:
    total = 0
    for spec in LIBRARIES:
        lib = manifest.libraries[spec.key]
        n = len(lib.functions)
        total += n
        print(
            f"{spec.key:10s} fns={n:5d} structs={len(lib.structs):4d} "
            f"enums={len(lib.enums):4d} opaque={len(lib.opaque):4d}"
        )
    print(f"{'TOTAL':10s} fns={total:5d}")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--repo", type=Path, default=Path("."))
    ap.add_argument("--deps", type=Path, default=Path("build/_deps"))
    ap.add_argument("--stats-only", action="store_true")
    args = ap.parse_args()

    manifest = build_manifest(args.repo, args.deps)
    print_stats(manifest)
    if args.stats_only:
        return 0

    from .emit_cpp import emit_cpp
    from .emit_lua import emit_lua
    from .emit_ruby import emit_ruby
    from .emit_report import emit_report

    outcomes = {}
    outcomes["cpp"] = emit_cpp(manifest, args.repo)
    outcomes["lua"] = emit_lua(manifest, args.repo)
    outcomes["ruby"] = emit_ruby(manifest, args.repo)
    emit_report(manifest, outcomes, args.repo)
    return 0


if __name__ == "__main__":
    sys.exit(main())
