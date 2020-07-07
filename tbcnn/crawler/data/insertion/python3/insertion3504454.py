# -*- Coding: utf-8 -*-
def trace(A, N):
    for i in range(int(N)-1):
        print(A[i], end=' ')
    print(A[int(N)-1])

def insertionSort(A, N):
    for i in range(1, int(N)):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1]  = v
        trace(A, N)

if __name__ == '__main__':
    N = input()
    A = list(map(int, input().split()))
    
    trace(A, N)
    insertionSort(A, N)

