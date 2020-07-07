# ALDS1_1_A: Insertion Sort
N = int(input())
A = list(map(int, input().split())) 

def insertionSort(A, N):
    print(" ".join(map(str, A)))
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j = j - 1
        A[j+1] = v
        print(" ".join(map(str, A)))
    
insertionSort(A, N)
