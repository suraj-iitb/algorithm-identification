def countingsort(A,n):
    k=max(A)
    
    B=[0 for i in range(n)]
    C=[0 for i in range(k+1)]
    
    for i in range(n):
        C[A[i]]+=1
        
    for i in range(1,k+1):
        C[i]=C[i]+C[i-1]
    
    for j in range(n-1,-1,-1):
        B[C[A[j]]-1]=A[j]
        C[A[j]]-=1
    
    print(*B)
    
n=int(input())
A=list(map(int,input().split()))

countingsort(A,n)
