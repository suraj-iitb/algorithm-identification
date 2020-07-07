N=int(input())
A=list(map(int,input().split()))
B=list(map(str,A))
print(' '.join(B))
for i in range(1,N):
    v=A[i]
    j=i-1
    while j!=-1 and A[j]>v:
        A[j+1]=A[j]
        j-=1
    A[j+1]=v
    B=list(map(str,A))
    print(' '.join(B))

