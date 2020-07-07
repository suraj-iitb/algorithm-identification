# -*- coding: utf-8 -*-
n = int(input())
a = list(map(int, input().split()))

for i in range(1, n):
    print(" ".join(map(str, a)))
    v = a[i]
    j = i - 1
    while (j >= 0) & (a[j] > v):
        a[j+1] = a[j]
        j -= 1
    a[j+1] = v
print(" ".join(map(str, a)))

