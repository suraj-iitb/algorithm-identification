n,*a=map(int,open(0).read().split())
flag=1
c=0
while flag:
    flag=0
    for j in range(n-1,0,-1):
        if a[j]<a[j-1]:
            a[j],a[j-1]=a[j-1],a[j]
            flag=1
            c+=1
print(*a)
print(c)

