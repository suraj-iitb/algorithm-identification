# -*- coding: utf-8 -*-

import sys
import os



def insertion_sort(A):
    n = len(A)
    for i in range(1, n):
        v = A[i]
        j = i - 1

        # i-1????????§???sort??????
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(*A)

input()
lst = list(map(int, input().split()))
print(*lst)
insertion_sort(lst)
