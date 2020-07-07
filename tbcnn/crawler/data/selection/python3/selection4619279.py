n = int(input())
A = [int(x) for x in input().split()]

cnt = 0
for i in range(n - 1):
    k = i
    for j in range(i + 1, n):
        if A[j] < A[k]:
            k = j

    if i != k:
        A[i], A[k] = A[k], A[i]
        cnt += 1

print(*A)
print(cnt)

