def partition(a,p,r):
    x=a[r][1]
    i=p-1
    for j in range(p,r):
        if a[j][1]<=x:
            i+=1
            temp=a[i]
            a[i]=a[j]
            a[j]=temp
    temp=a[i+1]
    a[i+1]=a[r]
    a[r]=temp
    return i+1

def quicksort(a,p,r):
    if p<r:
        q=partition(a,p,r)
        quicksort(a,p,q-1)
        quicksort(a,q+1,r)


r=int(input())
a=[list(input().split()) for _ in range(r)]
for i in range(r):
    a[i][1]=int(a[i][1])
import copy
b=copy.deepcopy(a)
b.sort(key=lambda x:x[1])
quicksort(a,0,r-1)


if a==b:
    print("Stable")
else:
    print("Not stable")

for i in range(r):
    print(a[i][0],a[i][1])

