def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v
def shellSort(A, n):
    global cnt
    cnt = 0
    G = [1]
    while G[0] < n // 3:
        G[0:0] = [G[0] * 3 + 1]
    m = len(G)
    print(m)
    print(' '.join([str(g) for g in G]))
    for g in G:
        insertionSort(A, n, g)
    print(cnt)

n = int(input())
A = []
for i in range(n):
    A.append(int(input()))
shellSort(A, n)
for a in A:
    print(a)

