LLVM IR:
    clang++ -S -emit-llvm hello.cpp

AST:
    1. To get raw AST
        python3 examples/using_gcc_E_libc.py ../Data/bubble.c > ../Data/bubble_raw.ast
    2. To get Prolog style AST
        python3 examples/my_parser.py ../Data/bubble.c > ../Data/bubble.ast

    Note: These commands have to be run from pycparser folder
