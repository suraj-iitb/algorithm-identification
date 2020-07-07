def CountingSort(A,k):
    ans=[0 for _ in range(len(A))]
    C=[0 for _ in range(k+1)]
    for i in range(len(A)):
        C[A[i]]+=1
    for i in range(1,k+1):
        C[i]=C[i]+C[i-1]
    for i in reversed(range(len(A))):
        ans[C[A[i]]-1]=A[i]
        C[A[i]]-=1
    return ans
    
n=int(input())
A=list(map(int,input().split()))
k=max(A)
ans=CountingSort(A,k)

print(' '.join(map(str,ans)))
