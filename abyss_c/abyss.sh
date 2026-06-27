#!/usr/bin/env bash

set -e

cleanup() {
    rm -f main
}

trap cleanup EXIT

gcc *.c -o main
./main