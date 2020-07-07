def ss(A,n):
    cnt=0
    for k in range(n):
        minj=k
        for i in range(k,n):
            if A[i] < A[minj]:
                minj=i
        if minj !=k:
            tmp=A[k]
            A[k]=A[minj]
            A[minj]=tmp
            cnt=cnt+1
    return A,cnt

n=int(input())
A=list(map(int,input().split()))
A,cnt=ss(A,n)
As=[str(i)for i in A]
As = ' '.join(As)
print(As)
print(cnt)

