Callgrind:

    1. Compile the code with -g option
    2. valgrind --tool=callgrind <./executable> 
    3. callgrind_annotate <callgrind.out.pid> > <file>

Massif:

    1. Compile the code with -g option (g++ -g main.cpp)
    2. valgrind --tool=massif --time-unit=B ./a.out
                        or
       valgrind --tool=massif --time-unit=B --stacks=yes ./a.out  (with stack trace)

       Note: Use --massif-out-file=<output_file>

    3. ms_print <massif.out.pid/output_file> > <file>
