#!/usr/bin/env sh

set -e

BUILD_DIR=build
GENERATOR=Ninja
CC_CMD="ccache clang"

buildrun() {
  echo "[CMAKE] building executable..."
  cmake --build "$BUILD_DIR"
  echo "[EXE] run..."
  exec "$BUILD_DIR"/ubiquitos
  return 0
}

for arg in "$@"; do
  case "$arg" in
  c | clean)
    rm -rf "$BUILD_DIR"
    echo "[SH] build dir has been deleted..."
    exit 0
    ;;
  r | run)
    buildrun
    exit 0
    ;;
  esac
done

if [ ! -d "$BUILD_DIR" ]; then
  echo "[SH] Make build dir..."
  mkdir build
else
  echo "[SH] Build folder exist.."
fi

if [ ! -f "$BUILD_DIR"/CMakeCache.txt ]; then
  echo "[CMAKE] Configuring CMake..."
  CC="ccache clang" cmake -S . -B build -G Ninja
else
  echo "[CMAKE] already configured, skip it"
fi

# ---- build & run ----
buildrun
