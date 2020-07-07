N=int(input())
A=[int(x) for x in input().split()]
i=0
flag=True
count=0
while flag:
    flag=False
    for j in range(N-1,i,-1):
        if A[j]<A[j-1]:#ソート必須
            A[j],A[j-1]=A[j-1],A[j]
            count+=1
            flag=True


    i += 1
for i in range(N):print(A[i],end=' \n'[i+1==N])
print(count)
