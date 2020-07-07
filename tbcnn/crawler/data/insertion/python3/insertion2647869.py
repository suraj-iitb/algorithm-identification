N=int(input())
A=[int(x) for x in input().split()]
for i in range(N):
    v=A[i]
    j=i-1
    while j>=0 and v<A[j]:
        A[j+1]=A[j]
        j-=1
    A[j+1]=v
    print(' '.join(map(str,A)))
