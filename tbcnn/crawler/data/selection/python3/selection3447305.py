n=int(input())
ns=list(map(int,input().split()))
ans=0
for i in range(n):
    minj=i
    for j in range(i,n):
        if(ns[j]<ns[minj]):
            minj=j
    if i!=minj:
        ans+=1
        k=ns[i]
        ns[i]=ns[minj]
        ns[minj]=k
 
for i in range(n):
    if(i!=n-1):
        print(ns[i],end=' ')
print(ns[n-1])
print(ans)

