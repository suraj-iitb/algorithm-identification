#! /usr/bin/python
# -*- coding: utf-8 -*-

n=int(input()) # 数列の長さ
A=list(map(int, input().split())) # 空白を区切文字として配列に格納

tmp = 0
cnt = 0
flag = 1

while flag:
    flag = 0
    for i in range(1, n):
        j = n - i
        if A[j] < A[j-1]:
            tmp = A[j]
            A[j] = A[j-1]
            A[j-1] = tmp
            flag = 1
            cnt += 1
print(*A)
print(cnt)
