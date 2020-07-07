c=0
n=int(input())
l=list(map(int, input().split()))
for i in range(n-1):
    m=i
    for j in range(i,n):
        if l[j] < l[m]:
            m=j
    if i != m:
        t=l[i]
        l[i]=l[m]
        l[m]=t
        c+=1
print(*l)
print(c)
