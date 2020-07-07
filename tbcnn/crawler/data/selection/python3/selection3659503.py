n=int(input())
a=list(map(int,input().split()))
switch=0
for i in range(n-1):
    minj=i
    for j in range(i+1,n):
        if a[j]<a[minj]:
            minj=j
    if a[i]!=a[minj]:
        switch+=1
    a[i],a[minj]=a[minj],a[i]

for i in range(n-1):
    print(a[i],end=" ")
print(a[n-1])
print(switch)

