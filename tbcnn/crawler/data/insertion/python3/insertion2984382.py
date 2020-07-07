#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def insertionSort(A, N):
    """N個の要素を含む0-オリジンの配列A"""
    print(' '.join(map(str, A)))
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(' '.join(map(str, A)))

N = int(input())
A = [int(w) for w in input().split()]

insertionSort(A, N)

