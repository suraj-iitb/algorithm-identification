N=int(input())
A=[]
A=input().split()
A=[int(u) for u in A]
for i in range (0,N):
    v=A[i]
    j=i-1
    while j>=0 and A[j]>v:
        A[j+1]=A[j]
        j=j-1
        A[j+1]=v
    for u in range(0,N-1):
        print(A[u],end=" ")
    print(A[N-1])
