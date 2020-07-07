# -*- coding: utf-8 -*-


def show(A):
    for k in range(N):
        if k == N - 1:
            print('{0}'.format(A[k]))
        else:
            print('{0}'.format(A[k]), end=' ')


N = int(input())
A = list(map(int, input().split()))
show(A)

for i in range(1, N):
    v = A[i]
    j = i - 1
    while (j >= 0) and (A[j] > v):
        A[j + 1], A[j] = A[j], v
        j -= 1

    show(A)

