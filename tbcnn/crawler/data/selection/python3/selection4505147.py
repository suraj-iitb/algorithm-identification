n = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(n-1) :
    minj = i
    for j in range(i+1, n) :
        if A[j] < A[minj] :
            minj = j
    if A[i] != A[minj] :
        A[i], A[minj] = A[minj], A[i]
        ans += 1
for i in range(n-1) :
    print(A[i], end=" ")
print(A[n-1])
print(ans)
