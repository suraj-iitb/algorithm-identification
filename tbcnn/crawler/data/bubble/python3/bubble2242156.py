# -*- coding: utf-8 -*-

import sys
import os
import math


N = int(input())
A = list(map(int, input().split()))


def bubble_sort(A):
    swap_num = 0
    while True:
        swapped = False
        for i in range(N - 1):
            if A[i] > A[i + 1]:
                A[i], A[i + 1] = A[i + 1], A[i]
                swap_num += 1
                swapped = True
        if not swapped:
            return A, swap_num

A, num = bubble_sort(A)
print(*A)
print(num)
