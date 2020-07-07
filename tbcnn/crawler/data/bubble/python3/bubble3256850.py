n=int(input())
*a,=map(int, input().split())
c=0

flag=1
while flag:
    flag=0
    for i in range(n-1,0,-1):
        if a[i]<a[i-1]:
            a[i],a[i-1]=a[i-1],a[i]
            c+=1
            flag=1
print(*a)
print(c)
    

