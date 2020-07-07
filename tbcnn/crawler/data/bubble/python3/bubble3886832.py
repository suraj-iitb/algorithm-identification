def bb(A,n):
    cnt=0
    for k in range(n):
        for i in range(n-1,k,-1):
            if A[i] < A[i-1]:
                tmp=A[i]
                A[i]=A[i-1]
                A[i-1]=tmp
                cnt=cnt+1
    return A,cnt

n=int(input())
A=list(map(int,input().split()))
A,cnt=bb(A,n)
As=[str(i)for i in A]
As = ' '.join(As)
print(As)
print(cnt)

