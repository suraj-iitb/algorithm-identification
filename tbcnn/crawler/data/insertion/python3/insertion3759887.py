def insertionSort(A, N):
    for i in range(1, N):
        print(' '.join(map(lambda x: str(x), A)))
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
    return A

N = int(input())
A = list(map(int, input().split()))
A = insertionSort(A, N)

print(' '.join(map(lambda x: str(x), A)))

