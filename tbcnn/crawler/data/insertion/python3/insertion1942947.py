N = int(input())
A = [int(i) for i in input().split()]

def insertionSort(A, N):
    for i in range(N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(' '.join([str(i) for i in A]))

insertionSort(A, N)
