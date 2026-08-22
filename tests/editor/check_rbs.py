#!/usr/bin/env python3
"""Check the generated RBS is well formed.

The `rbs` gem would do this properly, and requiring it of everyone who
builds the project to validate a file most of them will never use is a poor
trade. So this checks the shape: every signature parses as
`def self.NAME: (args) -> return`, modules open and close, and the file is
not empty — which is the failure that would otherwise ship silently, since
an editor ignores an unreadable definition file without complaining.
"""
import re
import sys
from pathlib import Path

SIGNATURE = re.compile(r"^  def self\.[A-Za-z_][A-Za-z0-9_?!]*: \(.*\) -> \S.*$")


def main() -> int:
    path = Path(sys.argv[1])
    text = path.read_text(encoding="utf-8")
    lines = text.splitlines()

    signatures = [l for l in lines if l.strip().startswith("def ")]
    malformed = [l for l in signatures if not SIGNATURE.match(l)]
    opens = len([l for l in lines if l.startswith("module ")])
    closes = len([l for l in lines if l == "end"])

    if not signatures:
        print(f"{path}: no signatures", file=sys.stderr)
        return 1
    if malformed:
        print(f"{path}: {len(malformed)} malformed signatures", file=sys.stderr)
        for line in malformed[:5]:
            print(f"  {line}", file=sys.stderr)
        return 1
    if opens != closes:
        print(f"{path}: {opens} modules but {closes} ends", file=sys.stderr)
        return 1

    # A keyword where a parameter name belongs is the mistake this file is
    # most likely to make, since C has no such reservations. Compare whole
    # names: a substring test reports `backend` for ending in `end`, which is
    # how the first version of this check failed.
    reserved = {"def", "end", "class", "module", "self", "return", "next",
                "begin", "rescue", "ensure", "yield", "super", "alias"}
    for line in signatures:
        args = line[line.index("(") + 1:line.rindex(")")]
        for arg in args.split(","):
            tokens = arg.split()
            if not tokens:
                continue
            name = tokens[-1]
            if name in reserved:
                print(f"{path}: reserved word `{name}` as a parameter name:\n"
                      f"  {line}", file=sys.stderr)
                return 1

    print(f"{path.name}: {len(signatures)} signatures across {opens} modules")
    return 0


if __name__ == "__main__":
    sys.exit(main())
