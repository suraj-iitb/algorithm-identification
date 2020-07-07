N = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(N-1):
    j = N-1
    while j > i:
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j]
            ans += 1
        j -= 1
print(*A)
print(ans)

