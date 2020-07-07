def selection_sort(A, N):
    c = 0
    for i in range(N-1):
        minj = A[i+1:].index(min(A[i+1:])) + i+1
        if A[i] > A[minj]:
            A[i], A[minj] = A[minj], A[i]
            c += 1
    return A, c

N = int(input())
A = list(map(int, input().split()))
A, c = selection_sort(A, N)
print(' '.join(map(str, A)))
print(c)
