n = int(input())
A = list(map(int, input().split()))
cnt = 0
for i in range(n):
    min_j = i
    for j in range(i, n):
        if A[j] < A[min_j]:
            min_j = j
    if i != min_j:
        A[i], A[min_j] = A[min_j], A[i]
        cnt += 1
print(*A)
print(cnt)

