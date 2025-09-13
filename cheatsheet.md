# 🖥️ GCC / Clang Assembly & Optimization Commands

## Compile and generate assembly
gcc -S test.c -o test.s  
# Generate assembly file (.s) instead of object code.

clang -S test.c -o test.s  
# Same as above but using Clang.

## Optimization levels
gcc -O0 -S test.c -o test_O0.s  
# No optimization, debug-friendly assembly.

gcc -O1 -S test.c -o test_O1.s  
# Basic safe optimizations enabled.

gcc -O2 -S test.c -o test_O2.s  
# Full optimizations, balanced speed and size.

gcc -O3 -S test.c -o test_O3.s  
# Aggressive optimizations and auto-vectorization.

gcc -Ofast -S test.c -o test_Ofast.s  
# Like -O3 but allows unsafe math optimizations.

gcc -Os -S test.c -o test_Os.s  
# Optimize for smaller binary size.

gcc -Og -S test.c -o test_Og.s  
# Optimize while preserving good debugging.

## Inspect intermediate representations
gcc -O2 -fdump-tree-gimple test.c -c  
# Dump GIMPLE IR (high-level 3-address code).

gcc -O2 -fdump-tree-all test.c -c  
# Dump all tree (GIMPLE) stages for inspection.

gcc -O2 -fdump-rtl-all test.c -c  
# Dump RTL (low-level, register transfer language).

## Optimization reports
gcc -O3 -fopt-info-optimized=opt.txt test.c -c  
# Save general optimization report.

gcc -O3 -ftree-vectorize -fopt-info-vec-optimized=vec.txt test.c -c  
# Report vectorization decisions.

gcc -O3 -fopt-info-vec-missed=missed.txt test.c -c  
# Report missed vectorization opportunities.

## Assembly inspection after build
objdump -d -M intel a.out | less  
# Disassemble final binary with Intel syntax.

gdb --args ./a.out  
# Run program in gdb for debugging.
# Inside gdb: `disassemble /m main` shows source+assembly.

## Architecture-specific builds
gcc -O2 -march=native -S test.c -o test_native.s  
# Generate assembly tuned for your CPU.

gcc -O2 -march=corei7 -S test.c -o test_i7.s  
# Target specific CPU architecture.

## Link-Time Optimization (LTO)
gcc -O2 -flto file1.c file2.c -o prog  
# Enable link-time optimization across files.

## Profile-Guided Optimization (PGO)
gcc -fprofile-generate prog.c -o prog  
# Instrument program to collect runtime profile.

./prog  
# Run program to generate profile data.

gcc -fprofile-use prog.c -o prog  
# Recompile using collected profile info.

## Clang-specific commands
clang -S -emit-llvm test.c -o test.ll  
# Generate LLVM IR instead of assembly.

clang -O2 -Rpass=inline test.c -o prog  
# Show inline optimization remarks.

clang -O2 -Rpass=.* test.c -o prog  
# Show all optimization remarks.

opt -O3 test.ll -S -o opt.ll  
# Run LLVM optimizer manually on IR.
