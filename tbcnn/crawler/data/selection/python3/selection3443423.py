def selectionSort(A, N):
    count = 0
    for i in range(0, N):
        minj = i
        flag = 0
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
                flag = 1
        A[i], A[minj] = A[minj], A[i]
        if flag:
            count += 1
    return A, count

N = int(input())
A = list(map(int, input().split()))
A, count = selectionSort(A, N)
print(*A)
print(count)
