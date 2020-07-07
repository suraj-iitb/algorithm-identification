# -*- coding: UTF-8 -*-
#Selection Sort

#標準入力から
N = int(input()) #要素数
A = list(map(int,input().split())) #ソート対象（スペース区切り→配列に展開）
#交換回数
cnt = 0 

#Sort処理
for i in range(N):
    cnt_flg = 0
    minj = i
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j
            cnt_flg = 1
    tmp = A[i]
    A[i] = A[minj]
    A[minj] = tmp
    if cnt_flg == 1: cnt+=1

#回答
print(' '.join(map(str,A)))
print(cnt)

