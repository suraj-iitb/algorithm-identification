def selectionSort(A, N):
    count = 0
    for i in range(N-1):
        minj = i
        for j in range(i + 1, N):
            if A[j] < A[minj]:
                minj = j
        A[i], A[minj] = A[minj], A[i]
        if A[i] != A[minj]:
            count += 1
    return count


n = int(input())
a = [int(i) for i in input().split()]
count = selectionSort(a, n)
print(" ".join(map(str, a)))
print(count)

