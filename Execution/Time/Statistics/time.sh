#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: bash time.sh <exectable>"
    exit 1
fi

binary=./../../Code/$1
file=Result/$1/$1

for i in 10 100 1000 10000 100000
do
    for j in {1..100}
    do
        (time $binary < ../../Input/input-$i) &>> ${file}_${i}
    done
done