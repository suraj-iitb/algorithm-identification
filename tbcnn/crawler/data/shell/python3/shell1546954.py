import sys

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
    G = [i for i in [262913, 65921, 16577, 4193, 1073, 281, 77, 23, 8, 1] if i <= n]
    m = len(G)
    for k in range(m):
        insertionSort(A, n, G[k])
    return m, G

A = list(map(int, sys.stdin))
n = A[0]
del A[0]

cnt = 0

m, G = shellSort(A, n)

print(m)
print(*G)
print(cnt)
print("\n".join(map(str, A)))
