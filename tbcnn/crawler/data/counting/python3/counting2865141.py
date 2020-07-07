#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Aizu Online Judge Algorithm and Data Structure, counting sort

import sys

def count_sort(A, n, k):
    C = [0 for i in range(k+1)]
    B = [None for i in range(n)]

    for val in A:
        C[val] += 1
    C[0] -= 1
    for i in range(1, k+1):
        C[i] += C[i-1]
    for i in range(n-1, -1, -1):
        val = A[i]
        B[C[val]] = val
        C[val] -= 1

    print(' '.join(map(str,B)))


MAX_NUM = 10000
n = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
count_sort(A, n, MAX_NUM)

