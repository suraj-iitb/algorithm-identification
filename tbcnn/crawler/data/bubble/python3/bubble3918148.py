n=int(input())
a=[int(i) for i in input().split()]
ans=0
flag=True
while flag:
    flag=False
    for i in range(n-1,0,-1):
        if a[i]<a[i-1]:
            a[i],a[i-1]=a[i-1],a[i]
            flag=True
            ans+=1
print(*a)
print(ans)

