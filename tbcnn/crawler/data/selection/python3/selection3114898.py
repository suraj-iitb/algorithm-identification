def selection_sort(A, N):
    cnt = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        A[i], A[minj] = A[minj], A[i]
        if i != minj:
            cnt += 1
    return cnt

N = int(input())
A = list(map(int, input().split()))
cnt = selection_sort(A, N)
print(*A)
print(cnt)
