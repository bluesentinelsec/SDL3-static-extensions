# SDL3 (consumed via FetchContent — never vendored)

| | |
|--|--|
| Upstream | https://github.com/libsdl-org/SDL |
| Version | 3.4.14 (tag `release-3.4.14`) |
| Commit | `147a8ee32dbf9ac02f3794964490687b6bbda1bc` |
| Fetch | Release tarball, SHA-256 pinned (see `cmake/Dependencies.cmake`) |
| License | zlib |

FetchContent is the only supported way this project (and its consumers)
obtain SDL3. Built static (`SDL_SHARED=OFF`, `SDL_STATIC=ON`). Extensions
never embed a second SDL3.

Update procedure: bump the URL + `URL_HASH` in `cmake/Dependencies.cmake`,
update this file, and let the full CI matrix validate.
