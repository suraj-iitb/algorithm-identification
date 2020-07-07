# -*- coding: utf-8 -*-

def swap(A, i, j):
    tmp  = A[i]
    A[i] = A[j]
    A[j] = tmp

def bubbleSort(A, N):
    """N 個の要素を含む 0-オリジンの配列 A"""
    nswap = 0
    flag = True # 逆の隣接要素が存在する
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                swap(A, j, j-1) # A[j]とA[j-1]を交換
                nswap += 1
                flag = True
    return nswap

N = int(input())
A = [int(t) for t in input().split()]
if len(A) != N: raise

nswap = bubbleSort(A, N)
print(' '.join(map(str, A)))
print(nswap)

