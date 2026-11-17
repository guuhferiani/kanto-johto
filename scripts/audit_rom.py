#!/usr/bin/env python3
"""Pre-commit integrity audit for Pokemon Kanto & Johto (GBA)."""
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def check_wild_encounters():
    issues = []
    path = os.path.join(ROOT, "src", "data", "wild_encounters.json")
    with open(path, encoding="utf-8") as f:
        we = json.load(f)
    expected = {"land_mons": 12, "water_mons": 5, "rock_smash_mons": 5, "fishing_mons": 10}
    for g in we.get("wild_encounter_groups", []):
        for enc in g.get("encounters", []):
            m = enc.get("map", enc.get("base_label", "?"))
            for key, exp in expected.items():
                if enc.get(key):
                    mons = enc[key].get("mons", [])
                    if len(mons) != exp:
                        issues.append(f"{m}.{key}: {len(mons)} slots (expected {exp})")
                    for idx, mon in enumerate(mons):
                        lo, hi = mon["min_level"], mon["max_level"]
                        if lo > hi or lo < 1 or hi > 100:
                            issues.append(f"{m}.{key}[{idx}]: invalid levels {lo}-{hi}")
    return issues


def check_evolutions():
    issues = []
    path = os.path.join(ROOT, "src", "data", "pokemon", "evolution.h")
    with open(path, encoding="utf-8", errors="ignore") as f:
        for ln, line in enumerate(f, 1):
            if "EVO_TRADE" in line and not line.strip().startswith("//"):
                issues.append(f"evolution.h:{ln}: trade evolution found: {line.strip()}")
    return issues


def check_dialogues():
    issues = []
    for map_dir in sorted(glob.glob(os.path.join(ROOT, "data", "maps", "*"))):
        si = os.path.join(map_dir, "scripts.inc")
        if not os.path.exists(si):
            continue
        mname = os.path.basename(map_dir)
        with open(si, encoding="utf-8", errors="ignore") as f:
            lines = f.read().splitlines()
        for i, line in enumerate(lines):
            s = line.strip()
            if s.startswith('.string "'):
                nxt = lines[i + 1].strip() if i + 1 < len(lines) else ""
                if not s.endswith('"'):
                    issues.append(f"{mname}/scripts.inc:{i+1}: unclosed quote")
                elif s.count("{") != s.count("}"):
                    issues.append(f"{mname}/scripts.inc:{i+1}: brace mismatch")
                elif not nxt.startswith(".string") and not s.endswith('$"'):
                    issues.append(f"{mname}/scripts.inc:{i+1}: missing $ terminator")
    return issues


def main():
    all_issues = (
        check_wild_encounters()
        + check_evolutions()
        + check_dialogues()
    )
    if all_issues:
        print(f"AUDIT FAILED ({len(all_issues)} issue(s)):")
        for item in all_issues:
            print(f"  - {item}")
        sys.exit(1)
    print("AUDIT PASSED: 0 issues in wild encounters, evolutions, and dialogues.")


if __name__ == "__main__":
    main()
