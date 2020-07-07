n = int(input())
A = list(map(int, input().split()))

ans = 0
for i in range(n):
    for j in range(n-1,i,-1):
        if A[j-1]>A[j]:
            A[j-1],A[j]=A[j],A[j-1]
            ans+=1

print(*A)
print(ans)

