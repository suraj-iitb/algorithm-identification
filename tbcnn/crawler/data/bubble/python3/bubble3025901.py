n=int(input())
a=list(map(int,input().split()))
c=0
f=True
while f:
    f=False
    for j in range(n-1,0,-1):
        if a[j]<a[j-1]:
            a[j],a[j-1]=a[j-1],a[j]
            c+=1
            f=True
print(*a)
print(c)
