#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
if [[ ! -x ./predador_presa ]]; then
  make -j"$(nproc)"
fi
exec ./predador_presa
