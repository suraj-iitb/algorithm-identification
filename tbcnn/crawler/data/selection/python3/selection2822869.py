n=int(input())
a=list(map(int,input().split()))
c=0
for i in range(n-1):
 m=a.index(min(a[i:]),i)
 a[i],a[m]=a[m],a[i];c+=i!=m
print(*a)
print(c)
