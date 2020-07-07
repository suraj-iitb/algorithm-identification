n=int(input())
a=list(map(int,input().split()))
cnt=0
judge=0

for i in range(n):
    minj=i
    for j in range(i,n):
        if a[j]<a[minj]:
            minj=j
    if a[i]>a[minj]:
        a[i],a[minj]=a[minj],a[i]
        cnt+=1
   
for i in range(n):
    if i==0:
        print(a[i],end="")
    else:
        print("{: }".format(a[i]),end="")
print()
print(cnt)
