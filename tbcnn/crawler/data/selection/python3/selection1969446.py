# coding: utf-8

n = int(input())
A = list(map(int, input().split()))
mini = 1
c = 0
for i in range(n):
    mini = i
    for j in range(i, n):
        if A[j] < A[mini]:
            mini = j
    A[i], A[mini] = A[mini], A[i]
    if mini != i:
        c += 1

print(" ".join(map(str, A)))
print(c)
