import sys

def insertionSort(A, N):
    for n in range(N-1):
        print (A[n], end=" ")
    print(A[N-1])
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j = j - 1
        A[j + 1] = v
        
        for n in range(N-1):
            print (A[n], end=" ")
        print(A[N-1])
    return A

N = int(input())
A = input()
A = A.split(" ")
for i in range(N):
    A[i] = int(A[i])
val = insertionSort(A, N)
