N=int(input())
A=list(map(int,input().split()))
count=0

for i in range(N):
    minj=i
    for j in range(i,N):
        if(A[j]<A[minj]):
            minj=j
    v=A[minj]
    A[minj]=A[i]
    A[i]=v
    if(minj!=i):
        count+=1
s=" ".join(map(str,A))
print(s)
print(count)
