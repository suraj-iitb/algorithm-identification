def insertationSort(A,n,g):
    global cnt
    for i in range(g,n):
        v=A[i]
        j=i-g
        while (j>=0 and A[j]>v):
            A[j+g]=A[j]
            j = j - g
            cnt += 1
        A[j+g] = v

def shellSort(A,n):
    global cnt
    cnt = 0
    g = []
    h = 1
    while h <= n:
        g.append(h)
        h = 3*h + 1
    g.reverse()
    m = len(g)
    print(m)
    print(' '.join(map(str,g)))
    for i in range(m):
        insertationSort(A,n,g[i])

N = int(input())
A = []
for i in range(N):
    A.append(int(input()))
shellSort(A,N)
print(cnt)
for e in A:
    print(e)

