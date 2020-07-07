def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >=0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v


def shellSort(A, n):
    global cnt
    m = 0
    k = 1
    G = []
    while k <= n:
        G.append(k)
        m +=1
        k = k + 3**m

    G .reverse()

    for i in range(m):
        insertionSort(A, n, G[i])

    print(m)
    print(*G)
    print(cnt)
    for j in A:
        print(j)


m = int(input())
lst = []
for i in range(m):
    lst.append(int(input()))

cnt = 0
shellSort(lst, m)
