n=int(input())
A=[0 for i in range(n)]

A=input().split()

for i in range(n):
    A[i]=(int)(A[i])

for i in range(n):
    key=A[i]
    j=i-1
    while j>=0 and A[j]>key:
        A[j+1]=A[j]
        j=j-1
        A[j+1]=key

    for i in range(n):
        if i!=n-1:
            print(A[i],end=" ")
        if i==n-1:
            print(A[i])

