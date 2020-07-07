N = int(input())
A = list(map(int, input().split()))
c = 0
for i in range(N-1):
    minj = i
    for j in range(i, N):
        if A[minj] > A[j]:
            minj = j
    if minj != i:
        A[i], A[minj] = A[minj], A[i]
        c += 1
print(*A)
print(c)
