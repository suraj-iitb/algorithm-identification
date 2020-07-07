i=input
t=int
N=t(i())
A=list(map(t,i().split()))
c=0
f = 1
while f:
    f = 0
    for j in range(1,N)[::-1]:
        if A[j]<A[j-1]:
            A[j],A[j-1]=A[j-1],A[j]
            f=1
            c+=1
print(*A)
print(c)
