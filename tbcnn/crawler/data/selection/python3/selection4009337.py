def selectionSort(A, N):
    count = 0
    for i in range(0, N):
        minj = i
        for j in range(i, N):
            if A[j]<A[minj]:
                minj = j
        if minj != i:
            (A[i], A[minj]) = (A[minj], A[i])
            count += 1
    print(" ".join(map(str, A)))
    print(count)

n = int(input())
a = list(map(int, input().split()))

selectionSort(a, n)
