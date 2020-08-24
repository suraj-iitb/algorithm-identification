Callgrind: call graph
    1. Compile the code with -g option
    2. valgrind --tool=callgrind ./bubble0.1 
    3. callgrind_annotate callgrind.out.10176 > bubble0.1.callgrind.stats

Massif:
    1. g++ -g main.cpp -o main
    2. valgrind --tool=massif --time-unit=B ./main
        or
    2. valgrind --tool=massif --time-unit=B --stacks=yes ./main  (with stack trace)
    3. ms_print massif.out.22472 > massif.out.22472.readable

    Note: valgrind --tool=massif --time-unit=B --stacks=yes --massif-out-file=massif.out.input-10000 ./bubble < /home/suraj/Documents/MTP/Baseline/ExecTime/Input/input-10000
