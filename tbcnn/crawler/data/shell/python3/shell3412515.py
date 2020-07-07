def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j -= g
            cnt += 1
        A[j + g] = v


def shellSort(A, n):
    G = [1]
    m = 1
    while True:
        g = 3 * G[-1] + 1
        if g >= n:
            break
        G.append(g)
        m += 1
    G.reverse()
    for i in range(m):
        insertionSort(A, n, G[i])
    print(m)
    print(" ".join(map(str, G)))


n = int(input())
A = []
for i in range(n):
    A.append(int(input()))
cnt = 0
shellSort(A, n)
print(cnt)
for i in range(n):
    print(A[i])
