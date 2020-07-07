N = int(input())
A = list(map(int,input().split()))
cnt=0
flg=1
while flg:
    flg=0
    for i in range(N-1,0,-1):
        if A[i]<A[i-1]:
            A[i],A[i-1]=A[i-1],A[i]
            cnt+=1
            flg=1

[print(A[x],end=' ') for x in range(N-1)];print(A[N-1]);print(cnt)
