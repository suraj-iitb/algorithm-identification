N = int(input())
A = list(map(int, input().split()))

def insertionSort(A, N):
    for i in range(N-1):
        print(' '.join(repr(e) for e in A))
        v = A[i+1]
        j = i
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
            A[j+1] = v
    print(' '.join(repr(e) for e in A))

insertionSort(A, N)
