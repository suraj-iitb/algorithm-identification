from copy import deepcopy

n = int(input())
a = list(map(int, input().split()))

A = deepcopy(a)
j = 0
cnt = 0
for i in range(n-1):
    minj = i
    for j in range(i, n):
        if A[j] < A[minj]: # 未ソート部からargminを持ってくる
            minj = j
    A[i], A[minj] = A[minj], A[i] # 未ソート先頭と最小値を交換する
    if i != minj: # ソートした場合はカウント+1する
        cnt += 1

print(*A)
print(cnt)
