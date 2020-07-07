# -*- coding: utf-8 -*-
# Shell sort


def insertionSort(A, n, g):
    """ 間隔Gの挿入ソート """
    global count
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j -= g
            count += 1
        A[j + g] = v


def shellSort(A, n):
    # 数列Gn=3G(n-1)+1 を生成
    G = []
    h = 1
    while h <= n:
        G.append(h)
        h = 3 * h + 1

    G.reverse()
    print(len(G))
    print(*G)

    for i in range(len(G)):
        insertionSort(A, n, G[i])


n = int(input())
A = [int(input()) for i in range(n)]

count = 0
shellSort(A, n)

print(count)
for i in range(n):
    print(A[i])

