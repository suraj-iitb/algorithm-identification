n = int(input())
*A, = map(int, input().split())
 
ans = 0
for i in range(n):
    for j in range(n-1):
        if A[j+1] < A[j]:
            A[j], A[j+1] = A[j+1], A[j]
            ans += 1
print(*A)
print(ans)
