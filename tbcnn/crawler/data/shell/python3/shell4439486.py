def insertionSort(A, n, g):
    cnt = 0
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
    return cnt

def shellSort(A, n):
    cnt = 0
    nn = n
    G = []
    g = 1
    while g <= n:
        G.insert(0, g)
        g = g*3 + 1
    m = len(G)
    for g in G:
        cnt += insertionSort(A, n, g)
    return cnt, m, G

n = int(input())
A = [int(input()) for i in range(n)]
cnt, m, G = shellSort(A, n)
print(m)
print(" ".join(map(str, G)))
print(cnt)
for a in A:
    print(a)

