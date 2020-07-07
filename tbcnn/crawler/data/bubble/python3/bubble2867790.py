# -*- coding: utf-8 -*-

N = int(input())
A = list(map(int, input().split()))


flag = 1
count = 0
while flag == 1:
    flag = 0
    for i in range(N - 1, 0, -1):
        if A[i] < A[i - 1]:
            A[i], A[i - 1] = A[i - 1], A[i]
            flag = 1
            count += 1

for i in range(N):
    if i == N - 1:
        print("{0}".format(A[i]))
    else:
        print("{0} ".format(A[i]), end="")

print(count)
