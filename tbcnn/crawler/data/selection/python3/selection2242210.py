# -*- coding: utf-8 -*-

import sys
import os
import math


N = int(input())
A = list(map(int, input().split()))


def selection_sort(A):
    swap_num = 0
    for i in range(N):
        min_i = i
        for j in range(i + 1, N):
            if A[j] < A[min_i]:
                min_i = j
        if i != min_i:
            A[i], A[min_i] = A[min_i], A[i]
            swap_num += 1
    print(*A)
    print(swap_num)

selection_sort(A)
