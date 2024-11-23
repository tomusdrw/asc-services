Exploration progress:
1. Obviously it's trivial to compile AssemblyScript to WASM
   (`cd source && npm run asbuild`)
2. Using `wasm2c` it's possible to generate C-code out of the WASM file.
3. This `C` code can be compiled using `./cbuild/cc.sh` to target your current
   platform and it works.
4. Using the PVM glue code from https://github.com/JamBrains/polkavm-examples/tree/master/lang-c
   we could implement all required host functions.

HOWEVER:
1. The `C` code requires `stdlib` (`libc`).
2. It seems it's not as easy to cross-compile to `riscv32` even when we keep the
   `stdlib` stuff (most likely skill issue, I didn't manage to figure out how to
   provide stdlib for riscv to get it to compile -we probably need something bare
   metal?)
3. The `polkavm-examples` toolchain is compiling to bare-metal `riscv32`, so no
   stdlib stuff.
4. I've tried commeting-out a bunch of standard `wasm-rt.h` and `wasm-rt-*impl` files
   to just check if it would compile but it seems there will be quite a lot things
   that would require re-implementing (math ops, mem stuff obviously, etc).
5. While so far it still seems doable it might be quite an effort just for a PoC
   and I'm afraid that the outcome will be so inefficient that it might not be worth
   that work at all.

## Hope?

Last thing I stumbled upon is https://github.com/gwsystems/aWsm/tree/master
I'm thinking if it would be possible to implement the PCM target platform for `aWsm`
and use it for compilation instead of going through `AS -> WASM -> C -> PVM`.

