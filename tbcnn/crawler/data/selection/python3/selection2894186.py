#coding:utf-8
n = int(input())
A = list(map(int, input().split()))

times = 0
for i in range(n):
    minj = i
    for j in range(i,n):
        if A[j] < A[minj]:
            minj = j
    if i != minj:
        A[i], A[minj] = A[minj], A[i]
        times += 1

B = " ".join([str(num) for num in A])
print(B)
print(times)

