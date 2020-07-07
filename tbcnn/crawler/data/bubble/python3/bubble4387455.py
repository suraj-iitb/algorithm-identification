N=int(input())
A=list(map(int, input().split()))
flag=True
cnt=0
while flag:
    flag=False
    j=0
    for i in range(N-1, j, -1):
        if A[i-1]>A[i]:
            A[i-1],A[i]=A[i],A[i-1]
            flag=True
            cnt+=1
    j+=1
print(*A)
print(cnt)
