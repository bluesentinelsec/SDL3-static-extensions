"""Audit the script surface for handles no script can produce.

    python3 tools/audit_script_surface.py [--deps build/debug/_deps]

A bound function taking a handle is only callable if some *other* bound
function hands that handle back. Anything else is bound but
unconstructible: it appears in SCRIPT_API.md, it autocompletes, and it
cannot be called — a whole feature that looks supported and is not.

That is what SDL_Event was. PollEvent was bound from the day SDL was
parsed, and no script could poll an event, because SDL_PollEvent fills a
struct the caller allocates and a script has no stack to allocate one on.
The coverage report counted it as bound, because it is.

The fix each time is the same and cheap: a create/destroy pair plus
scalar setters, which the generator already classifies as an owned
resource. See engine_config.h.

Not every entry here is a bug. Some handles are legitimately borrowed —
mog_server_request is handed to a request callback and has no meaning
outside one — and some belong to APIs nobody should drive from a script.
The point of the audit is that the decision is *visible* rather than
discovered by somebody writing a game.
"""

import argparse
import sys
from collections import defaultdict
from pathlib import Path
sys.path.insert(0, ".")

from tools.bindgen.__main__ import build_manifest
from tools.bindgen import classify
from tools.bindgen.classify import TK, TypeTable, plan_script
from tools.bindgen.spec import LIBRARIES

_ap = argparse.ArgumentParser(description=__doc__)
_ap.add_argument("--repo", default=".")
_ap.add_argument("--deps", default="build/debug/_deps")
_args = _ap.parse_args()

manifest = build_manifest(Path(_args.repo), Path(_args.deps))
tt = TypeTable(manifest)

produced, consumed = set(), defaultdict(list)

for spec in LIBRARIES:
    lib = manifest.libraries.get(spec.key)
    if lib is None:
        continue
    plans = plan_script(spec.key, lib.functions, tt)
    for name, plan in plans.items():
        if getattr(plan, "skip", None):
            continue
        ret = tt.info(lib.functions[name].ret)
        if ret.kind == TK.HANDLE:
            produced.add(ret.base)
        for pp in plan.params:
            if pp.info.kind == TK.HANDLE:
                consumed[pp.info.base].append((spec.key, name, pp.cname))

# Types whose C entry point still takes a struct no script can build, but
# where a script-shaped path to the same capability exists. The raw call
# stays unreachable on purpose: reporting these as gaps would be wrong, and
# silently dropping them would hide a real one that appeared later.
SUPERSEDED = {
    "SDLStatic_SceneDef":
        "SDLStaticC.SceneDefine/SceneOn + ScriptScenePush — a scene is its "
        "callbacks, so it needs a bridge rather than a builder",
    "SDL_GPUStorageBufferReadWriteBinding":
        "SDLStatic_GPUComputeBindingsAddBuffer + GPUBeginComputePass",
    "SDL_GPUStorageTextureReadWriteBinding":
        "SDLStatic_GPUComputeBindingsAddTexture + GPUBeginComputePass",
}

missing = {b: u for b, u in consumed.items() if b not in produced}
covered = {b: u for b, u in missing.items() if b in SUPERSEDED}
missing = {b: u for b, u in missing.items() if b not in SUPERSEDED}

print(f"handle types a script can obtain : {len(produced)}")
print(f"handle types it cannot           : {len(missing)}")
print(f"reachable another way            : {len(covered)}\n")

for base in sorted(missing, key=lambda b: (-len(missing[b]), b)):
    uses = missing[base]
    print(f"{base}  — {len(uses)} function(s) take it, none return it")
    for lib, fn, param in uses[:3]:
        print(f"      {lib}: {fn}({param})")
    if len(uses) > 3:
        print(f"      ... and {len(uses) - 3} more")

if covered:
    print("\nreachable another way:")
    for base in sorted(covered):
        print(f"  {base}\n      use {SUPERSEDED[base]}")

# A superseded entry that stops appearing means its raw call became
# constructible, and the note is now stale rather than harmless.
stale = sorted(set(SUPERSEDED) - set(covered))
if stale:
    print("\nstale SUPERSEDED entries (now constructible, drop the note): "
          + ", ".join(stale))
