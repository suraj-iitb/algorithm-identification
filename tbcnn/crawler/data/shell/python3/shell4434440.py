def insertionSort(A, n, g):
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            global cnt
            cnt += 1
        A[j+g] = v

def shellSort(A, n):
    global cnt
    cnt = 0
    G =[]
    g = 0
    for h in range(100):
        g = 3*g + 1
        if g <= n:
            G.insert(0,g)
        m = len(G)

    for  i in range(m):
        insertionSort(A, n, G[i])
    print(m)
    print(*G)
    print(cnt)
    print(*A,sep="\n")

n = int(input())
A = [int(input()) for i in range(n)]

shellSort(A, n)
