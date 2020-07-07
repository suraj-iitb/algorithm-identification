N=int(input())
A=[int(i) for i in input().split()]
S=""
for i in range(N-1):
    S=S+str(A[i])+" "
S=S+str(A[N-1])
print(S)
for i in range(1,N):
    v=A[i]
    j=i-1
    while(j>=0 and A[j]>v):
        A[j+1]=A[j]
        j-=1
    A[j+1]=v
    S=""
    for i in range(N-1):
        S=S+str(A[i])+" "
    S=S+str(A[N-1])
    print(S)
