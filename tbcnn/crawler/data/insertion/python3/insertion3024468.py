def insertionSort(A, N):
    for i in range(N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        B = A.copy()
        for t in range(N):
            B[t] = str(B[t])
        print(" ".join(B))


n = int(input())
a = list(map(int, input().split()))
insertionSort(a, n)
