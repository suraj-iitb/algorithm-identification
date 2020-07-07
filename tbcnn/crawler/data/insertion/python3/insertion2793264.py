N=int(input())
line=input().split()
A=[0]*N
for i in range(0,N):
    A[i]=int(line[i])
for i in range(N):
    """
    for k in range(N):
        print(A[k],end="")
        if k==N-1:
            print()
        else:
            print(" ",end="")
    """
    v=A[i]
    j=i-1
    while j>=0 and A[j]>v:
        A[j+1]=A[j]
        j-=1
        A[j+1]=v
    for k in range(N):
        print(A[k],end="")
        if k==N-1:
            print()
        else:
            print(" ",end="")

