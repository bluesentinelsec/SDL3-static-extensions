# Lua (vendored under `lua/`)
| | |
|--|--|
| Upstream | https://www.lua.org (lua-5.4.8.tar.gz) |
| Version | 5.4.8 | License | MIT (lua.org/license) |
| Imported | 2026-08-15, src/*.c+*.h minus lua.c/luac.c (standalone tools) |

Zero deps, C89. Original glue (`<SDLStatic/lua.h>`): SDLStatic_CreateLuaState
installs a package searcher resolving require("a.b") to a/b.lua inside the
PhysFS VFS (mounted zips, encrypted or not) before the normal searchers.
No local modifications.
