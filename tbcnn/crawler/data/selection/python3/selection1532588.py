n = int(input())

A = list(map(int, input().split()))

cnt = 0

for i in range(n - 1):
    min_i = i
    for j in range(i + 1, n):
        if A[min_i] > A[j]:
            min_i = j
    if min_i != i:
        A[min_i], A[i] = A[i], A[min_i]
        cnt += 1

print(' '.join(map(str, A)))
print(cnt)
