N = int(input())
*A, = map(int, input().split())
ans = 0
k = 0
while k < N - 1 :
    i = N - 1
    while i > k :
        if A[i] < A[i-1] :
            A[i], A[i-1] = A[i-1], A[i]
            ans = ans + 1
        i = i - 1    
    k = k + 1
print(*A)
print(ans)
