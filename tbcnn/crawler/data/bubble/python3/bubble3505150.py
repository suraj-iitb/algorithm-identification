N = int(input())
A = list(map(int,input().split()))
flag = True
ans = 0
for i in range(N):
    flag = False
    for j in range(N-1,i,-1):
        if A[j] < A[j-1]:
            A[j],A[j-1] = A[j-1],A[j]
            flag = True
            ans += 1
    if not flag:
        break
print(*A)
print(ans)

