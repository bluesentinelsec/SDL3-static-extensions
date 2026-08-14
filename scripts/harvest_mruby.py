#!/usr/bin/env python3
"""Harvest mruby sources + build-generated code into mruby/ (option "b").

mruby's build runs rake with a host Ruby to GENERATE code (parser, presym
tables, mrblib/gem bytecode arrays) before compiling. To keep this repo
self-contained — plain CMake, no host Ruby — we run that build once and
commit both the vendored and the generated sources. All generated output is
portable C (byte-oriented RITE bytecode, symbol tables), so one harvest
serves every target platform.

Regenerate:
  1. tar xzf mruby-4.0.0.tar.gz && cd mruby-4.0.0
  2. cp <repo>/scripts/mruby_build_config.rb build_config/sdlstatic.rb
  3. rake MRUBY_CONFIG=build_config/sdlstatic.rb
  4. python3 <repo>/scripts/harvest_mruby.py <mruby-dir> <repo>/mruby
"""
import shutil, sys
from pathlib import Path

def main():
    src = Path(sys.argv[1]); dst = Path(sys.argv[2])
    build = src / "build" / "host"
    core = dst / "src" / "core"; gems = dst / "src" / "gems"; inc = dst / "include"
    for d in (core, gems, inc): d.mkdir(parents=True, exist_ok=True)

    for f in (src / "src").iterdir():
        if f.suffix in (".c", ".h"): shutil.copy(f, core / f.name)
    shutil.copytree(src / "include", inc, dirs_exist_ok=True)
    shutil.copytree(build / "include" / "mruby" / "presym",
                    inc / "mruby" / "presym", dirs_exist_ok=True)
    shutil.copy(src / "LICENSE", dst / "LICENSE")
    shutil.copy(build / "mrblib" / "mrblib.c", gems / "mrblib.c")
    shutil.copy(build / "mrbgems" / "gem_init.c", gems / "gem_init.c")

    active = set()
    for gem_init in (build / "mrbgems").glob("mruby-*/gem_init.c"):
        gem = gem_init.parent.name
        active.add(gem)
        shutil.copy(gem_init, gems / f"{gem}_init.c")
    # compiler core (y.tab.c ships pre-generated in release tarballs)
    comp = src / "mrbgems" / "mruby-compiler" / "core"
    for f in comp.glob("*.c"): shutil.copy(f, gems / f"compiler_{f.name}")
    for aux in ("node.h", "lex.def", "keywords"): shutil.copy(comp / aux, gems / aux)
    for gem_dir in (src / "mrbgems").glob("mruby-*"):
        if gem_dir.name not in active and gem_dir.name != "mruby-compiler": continue
        gsrc = gem_dir / "src"
        if gsrc.is_dir():
            for f in gsrc.iterdir():
                if f.suffix == ".c": shutil.copy(f, gems / f"{gem_dir.name}_{f.name}")
                elif f.suffix == ".h": shutil.copy(f, gems / f.name)
        ginc = gem_dir / "include"
        if ginc.is_dir(): shutil.copytree(ginc, inc, dirs_exist_ok=True)
    print(f"harvested into {dst}")

if __name__ == "__main__":
    main()
