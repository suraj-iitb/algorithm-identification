# -*- coding: UTF-8 -*-
#Bubble Sort

#標準入力から
N = int(input()) #要素数
A = list(map(int,input().split())) #ソート対象（スペース区切り→配列に展開）

#print('input')
#print(N)
#print(A)

flag = 1
i = 0
cnt = 0

#Sort処理（自分メモ：flagが0になったらループを抜ける）
while flag:
    flag = 0
    for j in reversed(range(i+1,N)):
        if A[j] < A[j-1]:
            tmp = A[j-1]
            A[j-1] = A[j]
            A[j] = tmp
            flag = 1
            cnt += 1
    i += 1

#print('output')
#print(A)
print(' '.join(map(str,A)))
print(cnt)

