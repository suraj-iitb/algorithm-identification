#coding: UTF-8

N = int(input())
A = list(map(int, input().split()))


def InsertionSort(A,N):
    c = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                 minj = j
        if i != minj:
            tmp = A[i]
            A[i] = A[minj]
            A[minj] = tmp
            c+=1

    for i in range(N - 1):
        print(A[i],end=' ')
    print(A[N - 1])
    print(c)

InsertionSort(A,N)
