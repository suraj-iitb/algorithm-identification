# -*- coding: utf-8 -*-

def swap(A, i, j):
    tmp  = A[i]
    A[i] = A[j]
    A[j] = tmp

def selectionSort(A, N):
    """N個の要素を含む0-オリジンの配列A"""
    nswap = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            swap(A, i, minj)  # A[i] と A[minj] を交換
            nswap += 1
    return nswap

N = int(input())
A = [int(t) for t in input().split()]
if len(A) != N: raise

nswap = selectionSort(A, N)
print(' '.join(map(str, A)))
print(nswap)

