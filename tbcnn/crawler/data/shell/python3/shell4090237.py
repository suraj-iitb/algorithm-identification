n = int(input())
A_n = [int(input()) for i in range(n)]

def insertionSort(A, n, g, _count):
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            _count += 1
        A[j+g] = v
    return _count

def shellSort(A, n):
    count = 0
    h = 1
    G = []
    while h <= n:
        G.append(h)
        h = 3*h + 1
    m = len(G)
    for i in reversed(range(m)):
        count = insertionSort(A, n, G[i], count)
    return m, G, count

m, G, count = shellSort(A_n, n)
print(m)
print_G_str = ''
for i in range(m):
    print_G_str += str(G[m - 1 - i])
    if i < m - 1:
        print_G_str += ' '
print(print_G_str)
print(count)
for A in A_n:
    print(A)

