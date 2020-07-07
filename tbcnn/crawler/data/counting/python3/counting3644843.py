n=int(input())
a=list(map(lambda x:int(x),input().split()))
b=[0]*n
c=[0]*10001
for j in range(n):
    c[a[j]]+=1

for i in range(1,10001):
    c[i]=c[i]+c[i-1]

for j in range(n):
    b[c[a[j]]-1]=a[j]
    c[a[j]]-=1

for j in range(n-1):
    print(b[j],end=" ")
print(b[n-1])

