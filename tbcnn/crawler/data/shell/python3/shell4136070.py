def insetionSort(A,n,g):
    global cnt
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v
    return A

def shellSort(b,p):
    global cnt
    t = 1
    G = [1]
    while t*3+1 < p:
        t = t*3 +1
        G.append(t)
    G.reverse()
    m = len(G)
    for i in range(0,m):
        b = insetionSort(b,p,G[i])
    print(m)
    print(" ".join(map(str,G)))
    print(cnt)
    for t in b:
        print(t)

num = int(input())
lister = [int(input()) for s in range(num)]
cnt = 0
shellSort(lister,num)
