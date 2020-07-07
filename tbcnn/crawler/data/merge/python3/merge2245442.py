# -*- coding: utf-8 -*-

import sys
import os
import math


n = int(input())
A = list(map(int, input().split()))
cnt = 0

def merge(A, left, mid, right):
    global cnt

    S = A[left:mid]
    T = A[mid:right]
    S.append(float('inf'))
    T.append(float('inf'))

    s_i = 0
    t_i = 0
    for i in range(right - left):
        cnt += 1
        if S[s_i] < T[t_i]:
            A[left + i] = S[s_i]
            s_i += 1
        else:
            A[left + i] = T[t_i]
            t_i += 1


def merge_sort(A, left, right):
    if left + 1 == right:
        # ???????????????
        return
    else:
        # ??????????????????
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)

merge_sort(A, 0, len(A))
print(*A)
print(cnt)
