n=int(input())
A=list(map(int,input().split()))
c=0
for i in range(0,n):
    minj=i
    for j in range(i,n):
        if A[j]<A[minj]:
            minj=j
    if i != minj:
        c+=1
    A[i],A[minj]=A[minj],A[i]
print(" ".join(map(str,A)))
print(c)
