def insert_sort(A, n, g, cnt):
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v
    return cnt

def shellSort(A, n):
    cnt = 0
    G = []; h = 0
    while h <= n:
        if 3 * h + 1 <= n:
            h = 3 * h + 1
            G.append(h)
        else: break
    G = sorted(G, reverse=True)
    m = len(G)
    for i in range(m):
        cnt = insert_sort(A, n, G[i], cnt)
    return m, cnt, G

A = []
n = int(input())
for i in range(n):
    A.append(int(input()))

m, cnt, G = shellSort(A, n)
print(m)
for i in range(m):
    if i == m - 1:
        print(G[i])
    else:
        print(G[i], end=" ")
print(cnt)
for i in A:
    print(i)

