n = int(input())
l = list(map(int,input().split()))
for j in range(n):
    a = l[j]
    v = j-1
    while v>=0 and l[v]>a:
        l[v+1]=l[v]
        l[v]=a
        v -=1
    print(*l)
