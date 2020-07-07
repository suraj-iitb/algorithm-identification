def insertionSort(a,n,g):
    global cnt
    for i in range(g,n):
        v = a[i]
        j = i-g
        while j>=0 and a[j]>v:
            a[j+g] = a[j]
            j = j-g
            cnt+=1
        a[j+g] = v

def shellSort(a,n):
    global m
    global g
    h = 1
    while True:
        if h>n:
            break
        g.append(h)
        h = 3*h+1
    m = len(g)
    g.reverse()
    for i in range(m):
        insertionSort(a,n,g[i])

n = int(input())
a = [int(input()) for i in range(n)]
g = []
cnt = 0
m = 0
shellSort(a,n)
print(m)
print(*g)
print(cnt)
for i in range(n):
    print(a[i])

