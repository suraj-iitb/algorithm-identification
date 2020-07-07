#!/usr/bin/env python3
N = int(input())
A = list(map(int, input().split()))
c = 0
for i in range(N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            minj = j
    A[i], A[minj] = A[minj], A[i]
    if i != minj:
        c += 1

print(' '.join((str(x) for x in A)))
print(c)
