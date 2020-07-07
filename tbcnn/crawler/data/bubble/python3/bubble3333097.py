n=int(input())
a=list(map(int, input().split()))
flag=True
c=0
while flag:
    flag=False
    for i in range(n-1,0,-1):
        if a[i-1]>a[i]:
            a[i],a[i-1]=a[i-1],a[i]
            flag=True
            c+=1
print(*a)
print(c)
