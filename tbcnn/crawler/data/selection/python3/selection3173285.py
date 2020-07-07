n = int(input())
a = list(map(int, input().split()))

def selectionSort(A, N):
    cnt = 0
    for i in range(0, N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if A[i] != A[minj]:
            A[i], A[minj] = A[minj], A[i]
            cnt += 1
    return A, cnt

result = selectionSort(a, n)
print(' '.join(map(str, result[0])))
print(result[1])
