#!/usr/bin/env bash
# GitHub Codespaces / Dev Container setup for cppboot projects.
set -euo pipefail

mode="${1:-all}"

install_deps() {
  echo "[devcontainer] installing Ninja, clang-format, Doxygen, Universal Ctags..."
  sudo apt-get update
  sudo DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    ninja-build \
    clang-format \
    doxygen \
    universal-ctags \
    gdb
}

configure_and_build() {
  echo "[devcontainer] configuring Debug preset (FetchContent may take a few minutes)..."
  cmake --preset debug
  echo "[devcontainer] building Debug..."
  cmake --build --preset debug --parallel
  if [ -f build/debug/compile_commands.json ]; then
    ln -sfn build/debug/compile_commands.json compile_commands.json
    echo "[devcontainer] linked compile_commands.json for clangd"
  fi
  echo "[devcontainer] build complete. Try: ./build/debug/bin/* --version  or  make test"
}

case "${mode}" in
  deps) install_deps ;;
  build) configure_and_build ;;
  all)
    install_deps
    configure_and_build
    ;;
  *)
    echo "usage: $0 [deps|build|all]" >&2
    exit 2
    ;;
esac
