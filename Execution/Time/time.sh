#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: bash time.sh <exectable> <output-file>"
    exit 1
fi

binary=./../Code/$1
file=Result/$1/$2

(time $binary < ../Input/input-10) &>> $file
echo "input:10" &>> $file

(time $binary < ../Input/input-100) &>> $file
echo "input:100" &>> $file

(time $binary < ../Input/input-1000) &>> $file
echo "input:1000" &>> $file

x=10000
while [ "$x" -le 1000000 ] 
do
    (time $binary < ../Input/input-$x) &>> $file
    echo "input:$x" &>> $file
    x=$(( $x+10000 ))
done