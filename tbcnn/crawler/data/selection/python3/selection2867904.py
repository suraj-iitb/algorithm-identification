# -*- coding: utf-8 -*-

N = int(input())
A = list(map(int, input().split()))


count = 0
flag = 0
for i in range(N):

    if N == 1:
        break

    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            minj = j
            flag = 1

    if flag == 1:
        A[i], A[minj] = A[minj], A[i]
        count += 1

    flag = 0


for i in range(N):
    if i == N - 1:
        print("{0}".format(A[i]))
    else:
        print("{0} ".format(A[i]), end="")

print(count)
