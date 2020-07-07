def selectionSort(A, N):
    swap_count = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            A[i], A[minj] = A[minj], A[i]
            swap_count += 1
    return swap_count

n = int(input())
A = list(map(int, input().split()))
count = selectionSort(A, n)
print(*A)
print(count)
