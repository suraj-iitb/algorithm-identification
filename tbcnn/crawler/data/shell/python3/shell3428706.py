n,*a=map(int,open(0).read().split())
c=0
def IS(a,n,g):
    for i in range(g,n):
        v=a[i]
        j=i-g
        while j>=0 and a[j]>v:
            a[j+g]=a[j]
            j=j-g
            global c
            c+=1
        a[j+g]=v
G=sorted(set([1+(3**i-3)//2 for i in range(1,100)if 1+(3**i-3)//2<n]+[1]))[::-1]
for i in range(len(G)):
    IS(a,n,G[i])
print(len(G))
print(*G)
print(c)
for i in range(n):
    print(a[i])
