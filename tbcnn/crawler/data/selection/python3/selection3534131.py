n=int(input())
a=list(map(int,input().split()))
ans=0
for i in range(n):
    minj=i
    for j in range(i,n):
        if a[j]<a[minj]:
            j,minj=minj,j
    if i!=minj:
        a[i],a[minj]=a[minj],a[i]
        ans+=1
print(' '.join(map(str,a)))
print(ans)
