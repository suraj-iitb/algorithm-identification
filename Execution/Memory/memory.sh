if [ "$#" -ne 1 ]; then
    echo "Usage: bash time.sh <exectable-without-g>"
    exit 1
fi

i=20000
while [ "$i" -le 90000 ]
do
    echo $1 $i
    valgrind --tool=massif --time-unit=B --stacks=yes --massif-out-file=Results/${1}/${1}-${i} --max-snapshots=10 --detailed-freq=1 ./../Code/${1}_g < ../Input/input-${i}
    # ms_print Results/${1}/${1}-${i} > Results/${1}/${1}-${i}.read
    i=$(( $i+10000 ))
done

i=20000
while [ "$i" -le 90000 ]
do
    echo $1 $i
    # valgrind --tool=massif --time-unit=B --stacks=yes --massif-out-file=Results/${1}/${1}-${i} --max-snapshots=10 --detailed-freq=1 ./../Code/${1}_g < ../Input/input-${i}
    ms_print Results/${1}/${1}-${i} > Results/${1}/${1}-${i}.read
    i=$(( $i+10000 ))
done