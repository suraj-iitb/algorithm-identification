N=int(input())
A=[0 for i in range(N)]
A=input().split()
for i in range(N):
    A[i]=(int)(A[i])
for i in range(N):
    v=A[i]
    j = i-1
    while j>=0 and A[j]>v:
        A[j+1]=A[j]
        j=j-1
        A[j+1]=v
    for k in range(N):
        if k<N-1:
            print(A[k],end=" ")
        if k==N-1:
            print(A[k])
