n = int(input())
A = [int(x) for x in input().split()]

cnt = 0
for i in range(n - 1):
    for j in range(n - 2, i - 1, -1):
        if A[j] > A[j + 1]:
            A[j], A[j + 1] = A[j + 1], A[j]
            cnt += 1

print(*A)
print(cnt)

