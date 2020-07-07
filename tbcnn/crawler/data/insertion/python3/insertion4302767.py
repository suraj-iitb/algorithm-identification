N=int(input())
A=list(map(int,input().split()))
s=" ".join(map(str,A))
print(s)
for i in range(1,N):
    
    v=A[i]
    j=i-1
    while(j>=0 and v<A[j]):#<で安定になる
        A[j+1]=A[j]
        j-=1
    A[j+1]=v
    s=" ".join(map(str,A))
    print(s)
