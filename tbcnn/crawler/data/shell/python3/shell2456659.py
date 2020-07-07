def insertionSort(a,n,g):
    for i in range(g,n):
        v=a[i]
        j=i-g
        while j>=0 and a[j]>v:
            a[j+g]=a[j]
            j=j-g
            global cnt
            cnt+=1
        a[j+g]=v

def shellsort(a,n):
    global cnt
    cnt=0
    g=[i for i in [262913, 65921, 16577, 4193, 1073, 281, 77, 23, 8, 1] if i <= n]
    m=len(g)
    #print(g,m)
    for i in range(m):
        insertionSort(a,n,g[i])
    return a,m,g

n=int(input())
a=[int(input()) for i in range(n)]

a,m,g=shellsort(a,n)

print(m)
print(*g)
print(cnt)
for i in a:
    print(i)
