#!/usr/bin/env python3
# coding: utf_8

n = int(input())
a = list(map(int, input().split()))
count = 0

for i1 in range(n):
    mini2 = i1
    for i2 in range(len(a[i1:])):
        i2 += i1
        if a[i2] < a[mini2]:
            mini2 = i2
    if i1 != mini2:
        temp = a[i1]
        a[i1] = a[mini2]
        a[mini2] = temp
        count +=1

print(a[0], end="")
for i in a[1:]:
    print(" {}".format(i),end="")

print("\n{}".format(count))

