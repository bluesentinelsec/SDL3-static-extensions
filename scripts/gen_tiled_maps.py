#!/usr/bin/env python3
"""Generate Tiled-1.10-conformant .tmj test maps (JSON map format).

Synthesized rather than downloaded (same ethos as the audio/GM-patch
corpora): deterministic, zero licensing questions, and the layout is known
exactly so tests can assert tile GIDs and objects value-for-value.
"""
import json, sys
from pathlib import Path

def level():
    w, h = 8, 6
    ground = [1 + ((x + y) % 4) for y in range(h) for x in range(w)]
    deco = [0] * (w * h)
    deco[1 * w + 2] = 5
    deco[4 * w + 6] = 6
    return {
        "type": "map", "version": "1.10", "tiledversion": "1.10.2",
        "orientation": "orthogonal", "renderorder": "right-down",
        "width": w, "height": h, "tilewidth": 16, "tileheight": 16,
        "infinite": False, "nextlayerid": 4, "nextobjectid": 3,
        "layers": [
            {"id": 1, "name": "ground", "type": "tilelayer", "visible": True,
             "opacity": 1, "x": 0, "y": 0, "width": w, "height": h, "data": ground},
            {"id": 2, "name": "decorations", "type": "tilelayer", "visible": True,
             "opacity": 1, "x": 0, "y": 0, "width": w, "height": h, "data": deco},
            {"id": 3, "name": "entities", "type": "objectgroup", "visible": True,
             "opacity": 1, "x": 0, "y": 0, "draworder": "topdown",
             "objects": [
                 {"id": 1, "name": "spawn", "type": "player", "x": 24.0, "y": 40.0,
                  "width": 16.0, "height": 16.0, "rotation": 0, "visible": True},
                 {"id": 2, "name": "exit", "type": "door", "x": 112.0, "y": 72.0,
                  "width": 16.0, "height": 32.0, "rotation": 0, "visible": True}]}],
        "tilesets": [{
            "firstgid": 1, "name": "terrain", "tilewidth": 16, "tileheight": 16,
            "tilecount": 8, "columns": 4, "margin": 0, "spacing": 0,
            "image": "terrain.png", "imagewidth": 64, "imageheight": 32}],
    }

out = Path(sys.argv[1]) if len(sys.argv) > 1 else \
    Path(__file__).resolve().parent.parent / "tests" / "tiled" / "assets"
out.mkdir(parents=True, exist_ok=True)
(out / "level.tmj").write_text(# Tiled-faithful export: no space after ":" (cute_tiled requires this
# for quoted numeric fields like "version": it only skips a quote that
# immediately follows the colon).
json.dumps(level(), indent=1, separators=(",", ":")) + "\n")
print(f"wrote {out / 'level.tmj'}")
