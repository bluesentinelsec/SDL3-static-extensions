#!/usr/bin/env python3
"""Load the shared library the way something that is not C++ would.

    python3 test_shared_library.py <path-to-library> [--cxx]

This is the test the shared libraries exist for. A C++ consumer proves very
little about them: it links through the same toolchain that built them, with
the same headers, and never asks whether the symbols are *exported*. Python
asks nothing of the build system — it opens the file, looks up names, and
calls them — which is exactly what a plugin host, a C# binding or a Zig
project does.

It matters that this **calls** and does not merely load. A library that
exports nothing loads perfectly well and fails at the first lookup; on
Windows a DLL built without exports is a valid DLL. Checking `CDLL(path)`
succeeded would pass in exactly the case worth catching.

The engine is driven through the heap builders rather than a struct, because
a struct means agreeing on layout across a language boundary and the builders
mean agreeing on nothing.
"""
from __future__ import annotations

import argparse
import ctypes
import sys
from pathlib import Path


def load(path: Path) -> ctypes.CDLL:
    try:
        return ctypes.CDLL(str(path))
    except OSError as error:
        # On Linux this is usually a missing dependency of the library, not a
        # missing library — the message from the loader is the useful part.
        raise SystemExit(f"could not load {path}: {error}") from error


def declare(lib: ctypes.CDLL) -> None:
    """Signatures, so ctypes does not guess.

    Pointers default to `int` in ctypes, which truncates a 64-bit address to
    32 bits and produces a crash that looks like the library's fault.
    """
    lib.SDLStatic_ConfigCreate.restype = ctypes.c_void_p
    lib.SDLStatic_ConfigCreate.argtypes = []
    lib.SDLStatic_ConfigDestroy.restype = None
    lib.SDLStatic_ConfigDestroy.argtypes = [ctypes.c_void_p]

    for setter in ("SDLStatic_ConfigSetHeadless", "SDLStatic_ConfigSetManualClock",
                   "SDLStatic_ConfigSetAutoMount"):
        fn = getattr(lib, setter)
        fn.restype = None
        fn.argtypes = [ctypes.c_void_p, ctypes.c_bool]

    lib.SDLStatic_CreateEngine.restype = ctypes.c_void_p
    lib.SDLStatic_CreateEngine.argtypes = [ctypes.c_void_p]
    lib.SDLStatic_DestroyEngine.restype = None
    lib.SDLStatic_DestroyEngine.argtypes = [ctypes.c_void_p]
    lib.SDLStatic_EngineAdvance.restype = None
    lib.SDLStatic_EngineAdvance.argtypes = [ctypes.c_void_p, ctypes.c_uint64]
    lib.SDLStatic_EngineTick.restype = ctypes.c_bool
    lib.SDLStatic_EngineTick.argtypes = [ctypes.c_void_p]
    lib.SDLStatic_EngineFrameCount.restype = ctypes.c_uint64
    lib.SDLStatic_EngineFrameCount.argtypes = [ctypes.c_void_p]

    lib.SDL_GetPlatform.restype = ctypes.c_char_p
    lib.SDL_GetPlatform.argtypes = []
    lib.SDL_GetError.restype = ctypes.c_char_p
    lib.SDL_GetError.argtypes = []


def run_engine(lib: ctypes.CDLL) -> None:
    config = lib.SDLStatic_ConfigCreate()
    if not config:
        raise SystemExit("SDLStatic_ConfigCreate returned NULL")

    # Headless with a manual clock: no window, no GPU, and no waiting on a
    # real clock — this has to run on a CI machine with no display.
    lib.SDLStatic_ConfigSetHeadless(config, True)
    lib.SDLStatic_ConfigSetManualClock(config, True)
    lib.SDLStatic_ConfigSetAutoMount(config, False)

    engine = lib.SDLStatic_CreateEngine(config)
    lib.SDLStatic_ConfigDestroy(config)
    if not engine:
        error = lib.SDL_GetError().decode("utf-8", "replace")
        raise SystemExit(f"SDLStatic_CreateEngine returned NULL: {error}")

    for _ in range(5):
        lib.SDLStatic_EngineAdvance(engine, 16_666_667)
        lib.SDLStatic_EngineTick(engine)

    frames = lib.SDLStatic_EngineFrameCount(engine)
    lib.SDLStatic_DestroyEngine(engine)

    if frames < 5:
        raise SystemExit(f"engine ran {frames} frames, expected at least 5")
    print(f"  engine ran {frames} frames")


def check_hidden(lib: ctypes.CDLL) -> None:
    """Internals must not be reachable.

    Exporting everything is the easy way to make the loads above pass, and it
    turns every vendored library's private helper into part of our ABI —
    something we would then be obliged not to break.
    """
    for name in ("mbedtls_ssl_init", "stbi__zbuild_huffman", "physfs_platform_init"):
        try:
            getattr(lib, name)
        except AttributeError:
            continue
        raise SystemExit(f"{name} is exported; the symbol filter is not working")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("library", type=Path)
    parser.add_argument("--cxx", action="store_true",
                        help="the C++ library, which must also carry the C API")
    args = parser.parse_args()

    if not args.library.exists():
        raise SystemExit(f"no such library: {args.library}")

    print(f"loading {args.library.name}")
    lib = load(args.library)
    declare(lib)

    platform = lib.SDL_GetPlatform().decode("utf-8", "replace")
    print(f"  SDL reports platform: {platform}")

    run_engine(lib)
    check_hidden(lib)

    if args.cxx:
        # The C++ library contains the C API rather than depending on it, so
        # everything above had to work here too — that is what "self-contained"
        # means, and it is why this script runs twice.
        print("  C++ library also carries the full C API")

    print(f"{args.library.name}: ok")
    return 0


if __name__ == "__main__":
    sys.exit(main())
