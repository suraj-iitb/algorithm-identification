def selectionSort(A):
    nSwap = 0
    for i in range(N):
        minIdx = i
        for j in range(i, N):
            if A[j] < A[minIdx]:
                minIdx = j
        if minIdx != i:
            A[i], A[minIdx] = A[minIdx], A[i]
            nSwap += 1
    return A, nSwap

N = int(input())
A = list(map(int, input().split()))

sortedA, nSwap = selectionSort(A)
print(' '.join(map(str, sortedA)))
print(nSwap)
