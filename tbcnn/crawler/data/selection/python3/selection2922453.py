N = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(N-1):
    min_i = i
    for j in range(i+1, N):
        if A[j] < A[min_i]:
            min_i = j
    if i != min_i:
        ans += 1
        A[i], A[min_i] = A[min_i], A[i]
print(*A)
print(ans)

