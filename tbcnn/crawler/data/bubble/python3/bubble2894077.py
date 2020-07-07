#coding:utf-8
n = int(input())
A = list(map(int, input().split()))

times = 0
flag = 1
while flag:
    flag = 0
    for j in range(n-1,0,-1):
        if A[j] < A[j-1]:
            A[j-1], A[j] = A[j], A[j-1]
            times += 1
            flag = 1

B = " ".join([str(num) for num in A])
print(B)
print(times)


