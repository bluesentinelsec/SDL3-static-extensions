#!/usr/bin/env python3
"""Link audit: prove binaries carry no non-OS shared-library dependencies.

The core promise of SDL3-static-extensions is that consumers link statically
and ship without bundling shared codec/font libraries. This script inspects a
built binary's dynamic dependencies and fails if anything outside the
OS-built-in allowlist appears — and fails loudly if any known codec/font
library sneaks in regardless of location.

Usage: python3 scripts/link_audit.py <binary> [<binary> ...]
Wired into CTest (see tests/image/CMakeLists.txt); runs on Linux and macOS,
exits 0 with a notice elsewhere.
"""

from __future__ import annotations

import re
import subprocess
import sys

# Never acceptable as link-time dependencies, anywhere on disk.
FORBIDDEN = [
    "libpng", "libjpeg", "libturbojpeg", "libjxl", "libtiff", "libwebp",
    "libavif", "libdav1d", "libaom", "libheif",
    "libfreetype", "libharfbuzz",
    "libvorbis", "libogg", "libflac", "libmpg123", "libmad", "libopus",
]

# OS-built-in locations / names that a static-first binary may depend on.
MACOS_ALLOWED_PREFIXES = ("/usr/lib/", "/System/Library/")
LINUX_ALLOWED = re.compile(
    r"^(linux-vdso|ld-linux|ld-musl|libc|libm|libpthread|libdl|librt|"
    r"libgcc_s|libstdc\+\+|libatomic)"
)


def deps_macos(binary: str) -> list[str]:
    out = subprocess.check_output(["otool", "-L", binary], text=True)
    lines = out.splitlines()[1:]  # first line is the binary itself
    return [line.strip().split(" (")[0] for line in lines if line.strip()]


def deps_linux(binary: str) -> list[str]:
    out = subprocess.check_output(["ldd", binary], text=True)
    deps = []
    for line in out.splitlines():
        line = line.strip()
        if "=>" in line:
            deps.append(line.split("=>")[0].strip())
        elif line and not line.startswith("statically linked"):
            deps.append(line.split(" ")[0].strip())
    return deps


def audit(binary: str) -> list[str]:
    problems = []
    if sys.platform == "darwin":
        deps = deps_macos(binary)
        for dep in deps:
            name = dep.rsplit("/", 1)[-1].lower()
            if any(f in name for f in FORBIDDEN):
                problems.append(f"forbidden codec/font dependency: {dep}")
            elif not dep.startswith(MACOS_ALLOWED_PREFIXES):
                problems.append(f"non-OS dependency: {dep}")
    elif sys.platform.startswith("linux"):
        deps = deps_linux(binary)
        for dep in deps:
            name = dep.rsplit("/", 1)[-1].lower()
            if any(f in name for f in FORBIDDEN):
                problems.append(f"forbidden codec/font dependency: {dep}")
            elif not LINUX_ALLOWED.match(name):
                problems.append(f"non-OS dependency: {dep}")
    else:
        print(f"link_audit: unsupported platform {sys.platform}; skipping")
        return []
    print(f"link_audit: {binary}: {len(deps)} dynamic dependencies inspected")
    return problems


def main() -> int:
    if len(sys.argv) < 2:
        print("usage: link_audit.py <binary> [...]", file=sys.stderr)
        return 2
    failures = []
    for binary in sys.argv[1:]:
        failures.extend(audit(binary))
    for problem in failures:
        print(f"link_audit: FAIL: {problem}", file=sys.stderr)
    if not failures:
        print("link_audit: OK — only OS-built-in shared libraries")
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
