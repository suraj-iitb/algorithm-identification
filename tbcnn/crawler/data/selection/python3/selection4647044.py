n = int(input())
A = list(map(int, input().split()))
c = 0

for i in range(n-1):
    minj = i
    for j in range(i, n):
        if A[j] < A[minj]:
            minj = j
    if minj != i:
        A[i], A[minj] = A[minj], A[i]
        c += 1
print(*A, sep=' ')
print(c)
