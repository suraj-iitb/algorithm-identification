# coding: utf-8
n = int(input())
A = list(map(int, input().split()))
c = 0
for i in range(n-1):
    for j in range(n-1, i, -1):
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j]
            c += 1
print(" ".join(map(str, A)))
print(c)
