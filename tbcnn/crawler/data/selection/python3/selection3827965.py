#! /usr/bin/python
# -*- coding: utf-8 -*-

N=int(input()) # 数列の長さ
A=list(map(int, input().split())) # 空白を区切文字として配列に格納

minj = 0
tmp = 0
cnt = 0

for i in range(0, N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:  #一番小さい要素よりも小さいものを記憶する
            minj = j
    if i != minj:
        cnt += 1
    tmp = A[i]  #18行目までで、一番小さい要素とi番目の要素を入れ替え
    A[i] = A[minj]
    A[minj] = tmp
    
print(*A)
print(cnt)
