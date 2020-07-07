n=int(input())
A=list(map(int,input().split()))

for i in range(1,n):
    for k in range(n-1):
        print(A[k],end=" ")
    print(A[n-1])
    v=A[i]
    j=i-1
    while j>=0 and A[j]>v:
        A[j+1]=A[j]
        j=j-1
    A[j+1]=v

for k in range(n-1):
        print(A[k],end=" ")
print(A[n-1])
