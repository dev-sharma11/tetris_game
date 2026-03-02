#!/bin/bash
[ "$1" = "clean" ] && rm -rf build
cmake -B build && cmake --build build && ./build/Fractal