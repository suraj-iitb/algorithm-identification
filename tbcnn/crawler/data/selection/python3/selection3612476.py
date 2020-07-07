def selectionSort(A):
    cnt = 0

    for i in range(len(A)):
        minj = i

        for j in range(i + 1, len(A)):
            if A[j] < A[minj]:
                minj = j

        if minj != i:
            A[i], A[minj] = A[minj], A[i]

            cnt += 1

    return A, cnt


N = int(input())
A = list(map(int, input().split()))

A_sorted, cnt = selectionSort(A)

print(*A_sorted)
print(cnt)

