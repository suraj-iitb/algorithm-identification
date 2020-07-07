def pd(A):
    print(" ".join(map(str,A)))

def insertionSort(A, N):
    pd(A)
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        pd(A)

    return A

n = int(input())
a = list(map(int, input().split()))
insertionSort(a, n)
