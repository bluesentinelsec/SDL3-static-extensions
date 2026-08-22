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
    ap.add_argument(
        "--check", action="store_true",
        help="regenerate into a temp tree and fail if it differs from the "
             "committed output (codegen freshness)",
    )
    args = ap.parse_args()

    manifest = build_manifest(args.repo, args.deps)
    print_stats(manifest)
    if args.stats_only:
        return 0

    from .emit_cpp import emit_cpp
    from .emit_lua import emit_lua
    from .emit_ruby import emit_ruby
    from .emit_report import emit_report
    from .emit_script_api import emit_script_api

    target = args.repo
    if args.check:
        import shutil
        import tempfile

        tmp = Path(tempfile.mkdtemp(prefix="bindgen-check-"))
        # emit_cpp includes SDLStatic module headers by name only, so a bare
        # skeleton suffices.
        (tmp / "gui" / "include" / "SDLStatic").mkdir(parents=True)
        shutil.copy(args.repo / "gui" / "include" / "SDLStatic" / "nuklear.h",
                    tmp / "gui" / "include" / "SDLStatic" / "nuklear.h")
        target = tmp

    outcomes = {}
    outcomes["cpp"] = emit_cpp(manifest, target)
    outcomes["lua"] = emit_lua(manifest, target)
    outcomes["ruby"] = emit_ruby(manifest, target)
    emit_report(manifest, outcomes, target)

    from .emit_editor import emit_editor
    emit_editor(manifest, outcomes, target, args.deps, args.repo)
    emit_script_api(manifest, outcomes, target)

    if args.check:

        def normalized(path: Path) -> bytes:
            # CI checkouts on Windows may be CRLF-converted.
            return path.read_bytes().replace(b"\r\n", b"\n")

        stale: list[str] = []
        for rel_dir in ("cpp/include/sdlstatic/gen", "bindings/generated"):
            fresh_dir = target / rel_dir
            committed_dir = args.repo / rel_dir
            # Recursive: bindings/generated has subdirectories now (editor/),
            # and iterdir() would hand a directory to read_bytes().
            for fresh in sorted(fresh_dir.rglob("*")):
                if fresh.is_dir():
                    continue
                committed = committed_dir / fresh.relative_to(fresh_dir)
                if not committed.exists() or normalized(fresh) != normalized(committed):
                    stale.append(str(committed))
        if stale:
            import difflib

            print("bindgen: committed output is stale; regenerate with "
                  "`python3 -m tools.bindgen`:", file=sys.stderr)
            for s in stale:
                print(f"  {s}", file=sys.stderr)
            # First few diff lines of the first stale file, for CI logs.
            first = Path(stale[0])
            fresh_first = target / first.relative_to(args.repo)
            diff = difflib.unified_diff(
                normalized(first).decode("utf-8", "replace").splitlines(),
                normalized(fresh_first).decode("utf-8", "replace").splitlines(),
                lineterm="", n=1,
            )
            for i, line in enumerate(diff):
                if i > 20:
                    break
                print(f"  | {line}", file=sys.stderr)
            return 1
        print("bindgen: committed output is up to date")
    return 0


if __name__ == "__main__":
    sys.exit(main())
