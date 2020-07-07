N=int(input())

a=list(map(int,input().split()))

#print(a)
for k in range(N-1):
    print(a[k],end=" ")
print(a[N-1])

for i in range(1,N):
    v=a[i]
    j=i-1
    while j>=0 and a[j]>v:
        a[j+1]=a[j]
        j=j-1
    a[j+1]=v

    for k in range(N-1):
        print(a[k],end=" ")
    
    print(a[N-1])

