#! /usr/bin/python
# -*- coding: utf-8 -*-

n=int(input()) # 数列の長さ
A=list(map(int, input().split())) # 空白を区切文字として配列に格納
print(*A)

for i in range(1, n):
    key = A[i]
    # insert A[i] into the sorted sequence A[0,...,j-1]
    j = i - 1
    while j >= 0 and A[j] > key:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = key
    print(*A)
