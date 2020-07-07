# coding: utf-8

import math
import sys

def insertionSort(a, n, g):
    ct = 0
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j = j - g
            ct += 1
            a[j+g] = v
    return ct

n = int(input())
a = list(map(int, sys.stdin.readlines()))
cnt = 0
m = 0
h = 0
g = []

while True:
    h = 3*h + 1
    if h > n:
        break
    g.insert(0, math.ceil(h))

for i in g:
    cnt += insertionSort(a, n, i)

print(len(g))
print(*g, sep=" ")
print(cnt)
print(*a, sep="\n")
