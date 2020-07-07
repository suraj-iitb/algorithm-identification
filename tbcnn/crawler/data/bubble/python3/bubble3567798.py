N=int(input())
A=[int(i) for i in input().split()]
ans=0
flag=1
while flag:
    flag=0
    for j in range(1,N)[::-1]:
        if A[j]<A[j-1]:
            A[j],A[j-1]=A[j-1],A[j]
            flag=1
            ans+=1

print(" ".join([str(i) for i in A]))
print(ans)

