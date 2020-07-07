# coding: utf-8
# Your code here!

def selectionSort(A, N):
    cnt = 0
    for i in range(0, N-1):
        minj = i
        mink = i
        for j in range(i, N):
            if A[mink] > A[j]:
                mink = j
        if minj != mink:
            A[minj], A[mink] = A[mink], A[minj]
            cnt += 1

                
    showResult(A, cnt)

def showResult(A, cnt):
    for i in range(N-1):
        print(A[i], end=" ")
    print(A[N - 1])
    print(cnt)
        
#A = [6, 5, 4, 3,2,1]
#N = len(A)
N = int(input())
A = list(map(int, input().split())) 
selectionSort(A,N)
