#!/usr/bin/env python3

N = int(input())
A = list(map(int, input().split()))

c = 0
flag = True
while flag:
    flag = False
    for i in range(N - 1, 0, -1):
        if A[i] < A[i - 1]:
            A[i], A[i - 1] = A[i - 1], A[i]
            c += 1
            flag = True
print(' '.join((str(x) for x in A)))
print(c)
