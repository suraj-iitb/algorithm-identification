n=int(input())
a=list(map(int,input().split()))
ans=0
flg=True
i=0
while flg:
    flg=False
    for j in range(n-1,i,-1):
        if a[j]<a[j-1]:
            a[j],a[j-1]=a[j-1],a[j]
            flg=True
            ans+=1
    i+=1
print(' '.join(map(str,a)))
print(ans)
