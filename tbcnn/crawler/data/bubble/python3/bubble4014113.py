# coding: utf-8
# Your code here!

def bubbleSort(A, N):
    flag = 1
    cnt = 0;
    while flag:
        flag = 0;
        for i in reversed(range(1, N)):
            if A[i-1] > A[i]:
                A[i-1], A[i] = A[i] , A[i-1]
                flag = 1;
                cnt += 1
    showResult(A, cnt)

def showResult(A, cnt):
    N = len(A)
    for i in range(N-1):
        print(A[i], end = " ")
    print(A[N - 1 ])
    print(cnt)

N = int(input())
A = list(map(int, input().split())) 
#A = [1,5,4,3,2]
#N = len(A)

bubbleSort(A, N)

