# -*- coding:utf-8 -*-
def bubbleSort(A,N):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for j in range(N-1):
            if A[j] > A[j+1]:
                tmp = A[j]
                A[j] = A[j+1]
                A[j+1] = tmp
                flag = 1
                count += 1
    return A,count
N = int(input())
A = input()
A = A.split()
for i in range(len(A)):
    A[i] = int(A[i])
    
A,count = bubbleSort(A,N)
for i in range(len(A)-1):
    print(A[i],end = ' ')
print(A[len(A)-1])
print(count)
