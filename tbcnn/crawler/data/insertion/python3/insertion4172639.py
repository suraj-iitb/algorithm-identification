N=int(input())
A=list(int(x) for x in input().split())
for i in range(N):
    v=A[i]
    j=i-1
    while j>=0 and A[j]>v:
        A[j+1]=A[j]
        j-=1
    A[j+1]=v
    for i in range(N-1):
        print(A[i],end=" ")
    print(A[N-1])
