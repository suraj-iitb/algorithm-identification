n=int(input())
a=list(map(lambda x:int(x),list(input().split())))
for i in range(1,n):
    for k in range(n-1):
        print(a[k],end=" ")
    print(a[n-1])
    v=a[i]
    j=i-1
    while j>=0 and a[j]>v:
        a[j+1]=a[j]
        j=j-1
    a[j+1]=v

for k in range(n-1):
        print(a[k],end=" ")
print(a[n-1])


