count = 0
n = int(input())
A = [int(input()) for _ in range(n)]

def insertionSort(A, n, g):
    global count
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j = j - g
            count += 1
        A[j + g] = v

def shelSort(A, n):
    count = 0
    g = []
    h = 1
    while h <= n:
        g.append(h)
        h += h * 3 + 1
    g.reverse()
    m = len(g)
    print(m)
    print(' '.join([str(x) for x in g]))
    for i in range(m):
        insertionSort(A, n, g[i])

shelSort(A, n)
print(count)
for v in A:
    print(v)

