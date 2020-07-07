def insertionSort(A, n, g, cnt):
    i = g
    while n-1 >= i:
        v = A[i]
        j = i-g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j-g
            cnt += 1
        A[j+g] = v
        i += 1
    return cnt


def shellSort(A, n, cnt):
    G = []
    e = 1
    while len(A) >= e:
        G.append(e)
        e = 3 * e + 1
    G.reverse()
    m = len(G)

    print(m)
    i = 0
    for g in G:
        if i != m-1:
            print("{} ".format(g), end="")
        elif i == m-1:
            print(g)
        i += 1

    for g in G:
        cnt = insertionSort(A, n, g, cnt)

    print(cnt)
    for a in A:
        print(a)

    return cnt


n = int(input())
a = []
cnt = 0
for _ in range(n):
    a.append(int(input()))

cnt = shellSort(a, n, cnt)

