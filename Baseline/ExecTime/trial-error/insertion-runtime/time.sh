#!/bin/bash
for i in 10 100 1000 10000 100000
do
    for j in {1..100}
    do
        (time ./insertion < ../../complexity-analysis/Input/input-$i) &>> insertion_$i
    done
done