cnt = 0

def insertionSort(A, n, g):
    global cnt

    for i in range(g, n):
        v = A[i]
        j = i - g
        while (j >= 0) and (A[j] > v):
            A[j + g] = A[j]
            j = j - g
            cnt += 1
        
        A[j + g] = v


def shellSort(A, n):
    G = [1]
    for i in range(1, 100):
        G.append(G[i - 1] * 3 + 1)

    G = list(reversed([g for g in G if g <= n]))
    m = len(G)
    print(m)
    if G:
        print(*G)

    for i in range(m):
        insertionSort(A, n, G[i])

    print(cnt)



n = int(input())
A = [int(input()) for _ in range(n)]

shellSort(A, n)

[print(a) for a in A]
