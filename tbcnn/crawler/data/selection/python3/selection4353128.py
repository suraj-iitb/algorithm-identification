# 選択ソート


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
    return cnt


N = int(input())
A = list(map(int, input().split()))

cnt = selectionSort(A, N)
print(' '.join(map(str, A)))
print(cnt)

