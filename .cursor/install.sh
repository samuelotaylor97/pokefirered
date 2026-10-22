#!/usr/bin/env bash
# Cloud Agent bootstrap for pokefirered.
# Follows the Linux section of INSTALL.md: binutils-arm-none-eabi, libpng,
# and a pinned pret/agbcc built into tools/agbcc (gitignored). Does not build a ROM.
set -euo pipefail

AGBCC_COMMIT=da598c1d918402c42c0c0d7128ba14567f3175e9
AGBCC_URL=https://github.com/pret/agbcc
AGBCC_DIR=/opt/agbcc

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

export DEBIAN_FRONTEND=noninteractive
sudo apt-get update
sudo apt-get install -y \
  build-essential \
  binutils-arm-none-eabi \
  git \
  libpng-dev

sudo mkdir -p "$AGBCC_DIR"
sudo chown "$(id -u):$(id -g)" "$AGBCC_DIR"

if [[ ! -d "$AGBCC_DIR/.git" ]]; then
  git -C "$AGBCC_DIR" -c init.defaultBranch=master init
  git -C "$AGBCC_DIR" remote add origin "$AGBCC_URL"
fi

current="$(git -C "$AGBCC_DIR" rev-parse HEAD 2>/dev/null || true)"
if [[ "$current" != "$AGBCC_COMMIT" ]]; then
  git -C "$AGBCC_DIR" fetch --depth 1 origin "$AGBCC_COMMIT"
  git -C "$AGBCC_DIR" checkout --detach --force FETCH_HEAD
fi

need_build=0
if [[ ! -x "$AGBCC_DIR/agbcc" || ! -x "$AGBCC_DIR/old_agbcc" || ! -x "$AGBCC_DIR/agbcc_arm" || ! -f "$AGBCC_DIR/libgcc.a" || ! -f "$AGBCC_DIR/libc.a" ]]; then
  need_build=1
fi

if [[ "$need_build" -eq 1 ]]; then
  git -C "$AGBCC_DIR" clean -fdx
  git -C "$AGBCC_DIR" checkout --detach --force "$AGBCC_COMMIT"
  (cd "$AGBCC_DIR" && ./build.sh)
fi

if [[ "$need_build" -eq 1 \
  || ! -x "$REPO_ROOT/tools/agbcc/bin/agbcc" \
  || ! -x "$REPO_ROOT/tools/agbcc/bin/old_agbcc" \
  || ! -x "$REPO_ROOT/tools/agbcc/bin/agbcc_arm" \
  || ! -f "$REPO_ROOT/tools/agbcc/lib/libgcc.a" \
  || ! -f "$REPO_ROOT/tools/agbcc/lib/libc.a" ]]; then
  (cd "$AGBCC_DIR" && ./install.sh "$REPO_ROOT")
fi

test -x "$REPO_ROOT/tools/agbcc/bin/agbcc"
test -x "$REPO_ROOT/tools/agbcc/bin/old_agbcc"
test -x "$REPO_ROOT/tools/agbcc/bin/agbcc_arm"
test -f "$REPO_ROOT/tools/agbcc/lib/libgcc.a"
test -f "$REPO_ROOT/tools/agbcc/lib/libc.a"
command -v arm-none-eabi-as >/dev/null
command -v arm-none-eabi-ld >/dev/null
echo "pokefirered toolchain ready (agbcc ${AGBCC_COMMIT})"
