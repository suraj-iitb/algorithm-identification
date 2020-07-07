n = int(input())
A = list(map(int, input().split()))
count = 0
for i in range(n):
    for j in reversed(range(i, n - 1)):
        if A[j + 1] < A[j]:
            A[j + 1], A[j] = A[j], A[j + 1]
            count += 1
print(*A)
print(count)

