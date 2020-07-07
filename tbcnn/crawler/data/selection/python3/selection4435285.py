N = int(input())
A = list(map(int,input().split()))
cnt=0
for i in range(N-1):
    minj=i
    for j in range(i,N):
        if A[j]<A[minj]:
            minj=j
    if minj != i:
        A[i],A[minj]=A[minj],A[i]
        cnt += 1
[print(A[x],end=' ') for x in range(N-1)];print(A[N-1]);print(cnt)
