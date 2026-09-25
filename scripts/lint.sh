#!/opt/homebrew/bin/bash

set -uo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BUILD="$ROOT/.clang-build"
DATABASE="$BUILD/compile_commands.json"
CLANG_TIDY="$(brew --prefix llvm)/bin/clang-tidy"

OUTPUT="$(mktemp)"
trap 'rm -f "$OUTPUT"' EXIT

COMPILER="$(
    python3 - "$DATABASE" <<'PY'
import json
import shlex
import sys

with open(sys.argv[1], encoding="utf-8") as f:
    database = json.load(f)

entry = next(
    e for e in database
    if "/src/" in e["file"]
)

args = entry.get("arguments")

if args is None:
    args = shlex.split(entry["command"])

print(args[0])
PY
)"

TARGET="$("$COMPILER" -dumpmachine)"

mapfile -t SYSTEM_INCLUDES < <(
    "$COMPILER" -E -x c++ - -v </dev/null 2>&1 |
    awk '
        /#include <...> search starts here:/ { capture=1; next }
        /End of search list./ { capture=0 }
        capture {
            sub(/^[[:space:]]+/, "")
            print
        }
    '
)

EXTRA_ARGS=(
    "--extra-arg-before=--target=$TARGET"
)

for INCLUDE in "${SYSTEM_INCLUDES[@]}"; do
    EXTRA_ARGS+=(
        "--extra-arg-before=-isystem"
        "--extra-arg-before=$INCLUDE"
    )
done

"$CLANG_TIDY" \
    "$ROOT"/src/*.cpp \
    -p "$BUILD" \
    "${EXTRA_ARGS[@]}" \
    2>&1 | tee "$OUTPUT"

TIDY_STATUS=${PIPESTATUS[0]}

if [ "$TIDY_STATUS" -ne 0 ]; then
    exit "$TIDY_STATUS"
fi

if grep -Eq "$ROOT/src/.*:[0-9]+:[0-9]+: warning:" "$OUTPUT"; then
    echo
    echo "Lint failed: warnings in project source."
    exit 1
fi

echo
echo "Lint successful."