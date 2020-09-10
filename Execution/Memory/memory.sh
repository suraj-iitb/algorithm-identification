# if [ "$#" -ne 1 ]; then
#     echo "Usage: bash time.sh <exectable-without-g>"
#     exit 1
# fi

for algo in bubble insertion selection heap quick merge quick-iter
do
    for run in `seq 2 1 10`
    do
        for i in 10000 50000 100000 
        do
            echo $1 $i
            valgrind --tool=massif --time-unit=B --stacks=yes --massif-out-file=Results/${algo}/${algo}-${i}-${run} --max-snapshots=10 --detailed-freq=1 ./../Code/${algo}_g < ../Input/input-${i}
            # ms_print Results/${1}/${1}-${i} > Results/${1}/${1}-${i}.read
        done


        for i in 10000 50000 100000 
        do
            echo $1 $i
            # valgrind --tool=massif --time-unit=B --stacks=yes --massif-out-file=Results/${1}/${1}-${i} --max-snapshots=10 --detailed-freq=1 ./../Code/${1}_g < ../Input/input-${i}
            ms_print Results/${algo}/${algo}-${i}-${run} > Results/${algo}/${algo}-${i}-${run}.read
        done
    done
done