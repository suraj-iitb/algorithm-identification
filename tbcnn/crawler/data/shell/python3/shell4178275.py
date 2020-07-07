def insertionSortG(a, n, g):
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j -= g
            global cnt
            cnt += 1
        a[j+g] = v

def shellSort(a, n):
    G = []
    i = 0
    while 3 * i + 1 <= n:
        i = 3 * i + 1
        G.append(i)
    G.sort(reverse=True)
    for g in G:
        insertionSortG(a, n, g)
    G = [str(s) for s in G]
    print(len(G))
    print(' '.join(G))

n = int(input())
a = [int(input()) for _ in range(n)]
cnt = 0

shellSort(a, n)
print(cnt)
for s in a:
    print(s)
