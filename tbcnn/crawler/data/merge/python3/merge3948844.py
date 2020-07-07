cnt=0
def mer(l,r):
    global cnt
    ll=len(l)
    rr=len(r)
    md=[]
    i,j=0,0
    l.append(float('inf'))
    r.append(float('inf'))
    for k in range(ll+rr):
        cnt+=1
        if l[i]<=r[j]:
            md.append(l[i])
            i+=1
        else:
            md.append(r[j])
            j+=1
    return md
def mergesort(a):
    m=len(a)
    if m<=1:
        return a
    m=m//2
    l=mergesort(a[:m])
    r=mergesort(a[m:])
    return mer(l,r)
n=int(input())
a=list(map(int, input().split()))
b=mergesort(a)
for i in range(n-1):
    print(b[i],end=" ")
print(b[n-1])
print(cnt)
