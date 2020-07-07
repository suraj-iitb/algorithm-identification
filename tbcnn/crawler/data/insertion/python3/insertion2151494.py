debug = True

def insertionSort(A, N):
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        if debug: print(*A)

n = int(input())
arr = list(map(int, input().split()))

print(*arr)
insertionSort(arr, n)
