# シェルソート

N = int(input())
A = []
for i in range(N):
    A.append(int(input()))

cnt = 0


def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        for j in range(i-g, -1, -g):
            if A[j+g] < A[j]:
                A[j + g], A[j] = A[j], A[j + g]
                cnt += 1
            else:
                break


def shellSort(A, n):
    # gn+1 = 3gn + 1
    h = 1
    G = []
    while h <= n:
        G.append(h)
        h = 3 * h + 1
    G.reverse()
    print(len(G))
    print(" ".join([str(x) for x in G]))
    for g in G:
        insertionSort(A, n, g)


shellSort(A, N)
print(cnt)
for a in A:
    print(a)

