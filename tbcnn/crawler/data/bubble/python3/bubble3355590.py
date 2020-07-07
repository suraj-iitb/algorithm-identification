# -*- coding: utf-8 -*-
"""
Created on Sat Jan 26 22:45:33 2019

@author: Yamazaki Kenichi
"""

N = int(input())
A = list(map(int,input().split()))

counta = 0
flg = 1
while flg == 1:
    flg = 0
    for j in range(N-1):
        if A[j] > A[j+1]:
            temp = A[j]
            A[j] = A[j+1]
            A[j+1] = temp
            flg = 1
            counta += 1
print(' '.join(map(str,A)))
print(counta)
