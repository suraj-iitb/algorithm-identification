def partition(a,p,r):
    x=int(a[r][1:])
    i=p-1
    for j in range(p,r):
        if(int(a[j][1:])<=x):
            i+=1
            a[i],a[j]=a[j],a[i]
    a[i+1],a[r]=a[r],a[i+1]
    return i+1

def quicksort(a,p,r):
    if(p<r):
        q=partition(a,p,r)
        quicksort(a,p,q-1)
        quicksort(a,q+1,r)

a=[]
n=int(input())
for i in range(n):
    s=input()
    a.append("".join(s.split()))

c=list(a)
quicksort(c,0,n-1)

d=dict()
i=0
x="-1"
for i in c:
    if(x!=i[1:]):
        d[i[1:]]=[i[:1]]
        x=i[1:]
    else:
        d[x].append(i[:1])

message="Stable"

for i in reversed(a):
    if(i[1:] in d):
        if(d[i[1:]].pop()!=i[:1]):
            message="Not stable"
            break

print(message)

for i in c:
    print("%s %s"%(i[:1],i[1:]))
