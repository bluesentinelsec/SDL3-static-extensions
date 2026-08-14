#!/usr/bin/env bash
# Build the static docs site from docs/*.md into an output directory (default: site/).
# Requires pandoc. Used by the docs GitHub Action and for local previews.
set -euo pipefail

cd "$(dirname "$0")/.."
OUT="${1:-site}"

rm -rf "$OUT"
mkdir -p "$OUT"
cp web/style.css "$OUT/style.css"
cp -R docs/assets "$OUT/assets"

for md in docs/*.md; do
  name="$(basename "${md%.md}")"
  pandoc "$md" \
    --from gfm \
    --to html5 \
    --template web/template.html \
    --lua-filter web/bootstrap.lua \
    --css style.css \
    --output "$OUT/$name.html"
  echo "  built $OUT/$name.html"
done

echo "Docs site written to $OUT/"
