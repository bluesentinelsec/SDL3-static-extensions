#!/usr/bin/env python3
"""Check the generated tags file is usable.

A tags file that parses but points nowhere is the failure worth catching:
the editor jumps and finds nothing, which reads as a broken editor rather
than a broken file. So the paths are checked for the shape the SDK installs
— `include/...`, relative to the SDK root where the file sits.
"""
import sys
from pathlib import Path


def main() -> int:
    path = Path(sys.argv[1])
    lines = path.read_text(encoding="utf-8").splitlines()

    headers = [l for l in lines if l.startswith("!_TAG_")]
    entries = [l for l in lines if not l.startswith("!_TAG_")]

    if len(headers) < 2:
        print(f"{path}: missing the !_TAG_ header lines", file=sys.stderr)
        return 1
    if not entries:
        print(f"{path}: no tags", file=sys.stderr)
        return 1

    sorted_flag = any(l.startswith("!_TAG_FILE_SORTED\t1") for l in headers)
    names = [l.split("\t", 1)[0] for l in entries]
    if sorted_flag and names != sorted(names):
        print(f"{path}: claims to be sorted and is not — editors binary-search "
              f"these and will miss entries", file=sys.stderr)
        return 1

    for line in entries:
        parts = line.split("\t")
        if len(parts) < 4:
            print(f"{path}: malformed entry:\n  {line}", file=sys.stderr)
            return 1
        if not parts[1].startswith("include/"):
            print(f"{path}: path is not relative to the SDK root:\n  {line}",
                  file=sys.stderr)
            return 1

    print(f"{path.name}: {len(entries)} tags")
    return 0


if __name__ == "__main__":
    sys.exit(main())
