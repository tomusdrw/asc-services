#!/bin/sh

set -exu

cc \
  --target=riscv32 \
  -o release main.c release.c \
  wabt/wasm2c/wasm-rt-impl.c \
  wabt/wasm2c/wasm-rt-mem-impl.c \
  -Iwasm2c -lm

