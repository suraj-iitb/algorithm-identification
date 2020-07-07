def trace(A: list):
    print(*A)

def insertionSort(A: list, N:int) -> list:
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and v < A[j]:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        trace(A)

    return A


N = int(input())
A = list(map(int, input().split()))

trace(A)
insertionSort(A, N)




