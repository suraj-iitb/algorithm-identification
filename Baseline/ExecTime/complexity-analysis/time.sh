#!/bin/bash
(time ./bubble < Input/input-10) &>> bubble_time_command.txt
(time ./bubble < Input/input-100) &>> bubble_time_command.txt
(time ./bubble < Input/input-500) &>> bubble_time_command.txt

for i in `seq 1000 100 100000`
do
    (time ./bubble < Input/input-$i) &>> bubble_time_command.txt
done