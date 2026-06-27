#!/usr/bin/env sh

set -e

cleanup() {
    rm -f main
}

trap cleanup EXIT

CC="${CC:-cc}"

if ! command -v "$CC" >/dev/null 2>&1; then
    echo "Error: compiler '$CC' not found." >&2
    exit 1
fi

"$CC" *.c -o main
./main