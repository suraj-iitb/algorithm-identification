def insertionSort(A, n, g, cnt):
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j = j - g
            cnt += 1
        A[j + g] = v
    return cnt


def shellSort(A, n):
    cnt = 0
    m = 0
    G = [1]
    while G[-1] < n:
        G.append(G[m] * 3 + 1)
        m += 1
    if len(G) != 1:
        del G[-1]
        G.reverse()
    else:
        m = 1
    for i in range(m):
        cnt = insertionSort(A, n, G[i], cnt)
    return m, G, cnt


n = int(input())
a = [int(input()) for _ in range(n)]
m, G, cnt = shellSort(a, n)
print(m)
print(" ".join(map(str, G)))
print(cnt)
for i in range(n):
    print(str(a[i]))

