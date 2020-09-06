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
             Use --max-snapshots=10  (snapshots are taken at each call to malloc/new + some extra and half are
                                      truncated on reaching max no of snapshots)
             Use --detailed-freq=1

       Eg: valgrind --tool=massif --time-unit=B --stacks=yes --massif-out-file=../Memory/Results/bubble/bubble-10 --max-snapshots=10 --detailed-freq=1 ./bubble_g < ../Input/input-10

    3. ms_print <massif.out.pid/output_file> > <file>