def insertion(A,N):
    for i in range(1,N):
        print(" ".join([str(k) for k in A]))
        v=A[i]
        j=i-1
        while j>=0 and A[j]>v:
            A[j+1]=A[j]
            j-=1
        A[j+1]=v

n=int(input())
A=list(map(int,input().split()))
insertion(A,n)
print(" ".join([str(k) for k in A]))
