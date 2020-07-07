n=int(input())
a=list(map(int, input().split()))
c=0
for i in range(n):
    m=i
    for j in range(i,n):
        if a[j]<a[m]:
            m=j
    a[i],a[m]=a[m],a[i]
    if i!=m:c+=1
print(*a)
print(c)
