import math


def insertionsort(A, n, g):
    cnt = 0
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j = j - g
            cnt += 1
        A[j + g] = v
    return cnt


def shellsort(A, n):
    G = []         
    gap = 1
    while gap <= math.ceil(n / 3):
        G.append(gap)
        gap = gap * 3 + 1
    G = G[::-1]
    m = len(G)
    print(m)
    print(*G)
    cnt = 0
    for i in range(m):
        cnt += insertionsort(A, n, G[i])
    print(cnt)


n = int(input())
A = []
for i in range(n):
    A.append(int(input()))
shellsort(A, n)
for i in range(n):
    print(A[i])
