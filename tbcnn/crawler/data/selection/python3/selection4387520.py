N=int(input())
A=list(map(int,input().split()))
cnt=0
for i in range(N-1):
    minj=i
    for j in range(i+1,N):
        if A[j]<A[minj]:
            minj=j
    A[i],A[minj]=A[minj],A[i]
    if i!=minj:
        cnt+=1
print(*A)
print(cnt)
