N=int(input())
A=list(map(int,input().split()))
flag=True
count=0
while(flag):
    flag=0
    for i in range(N-1):
        if(A[N-1-i]<A[N-2-i]):
            v=A[N-1-i]
            A[N-1-i]=A[N-2-i]
            A[N-2-i]=v
            count+=1
            flag=True
s=" ".join(map(str,A))
print(s)
print(count)
