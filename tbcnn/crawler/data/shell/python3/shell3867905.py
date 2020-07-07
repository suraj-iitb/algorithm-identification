cnt = 0
g = []


def insertionSort(a, n, g):
    global cnt
    for i in range(g, n):
        v = a[i]
        j = i - g
        while (j >= 0 and a[j] > v):
            a[j + g] = a[j]
            j -= g
            cnt += 1
        a[j + g] = v


def shellSort(a, n):
    h = 1
    global g
    while (1):
        if h > n:
            break
        g.append(h)
        h = 3 * h + 1

    for gi in reversed(g):
        insertionSort(a, n, gi)


n = int(input())
a = list(int(input()) for i in range(n))
shellSort(a, n)
print(len(g))
for i in range(len(g)-1, -1, -1):
    print(g[i], end="")
    if (i):
        print(end=" ")
print()
print(cnt)
for i in a:
    print(i)

