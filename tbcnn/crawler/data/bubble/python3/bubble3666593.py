#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#ALDS1_2_A

n = int(input())
A = list(map(int, input().split()))

count = 0
flag = True
while flag:
    flag = False
    for i in range(len(A)-1, 0, -1):
        if A[i] < A[i-1]:
            A[i], A[i-1] = A[i-1], A[i]
            count += 1
            flag = True

print(" ".join(list(map(str, A))))
print(count)
