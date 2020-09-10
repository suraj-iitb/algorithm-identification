if [ "$#" -ne 1 ]; then
    echo "Usage: bash time.sh <exectable-without-g>"
    exit 1
fi

for i in 10000 30000 50000 70000 100000 
do
    echo $1 $i
    valgrind --tool=massif --time-unit=B --stacks=yes --massif-out-file=Results/${1}/${1}-${i} --max-snapshots=10 --detailed-freq=1 ./../Code/${1}_g < ../Input/input-${i}
    # ms_print Results/${1}/${1}-${i} > Results/${1}/${1}-${i}.read
done


for i in 10000 30000 50000 70000 100000 
do
    echo $1 $i
    # valgrind --tool=massif --time-unit=B --stacks=yes --massif-out-file=Results/${1}/${1}-${i} --max-snapshots=10 --detailed-freq=1 ./../Code/${1}_g < ../Input/input-${i}
    ms_print Results/${1}/${1}-${i} > Results/${1}/${1}-${i}.read
done