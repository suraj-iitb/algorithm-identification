def insertionSort(A, n, g, cnt):
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
    m = 1
    gs = [1]
    gn = 1
    while (3*gn+1) <= n:
        gn = 3*gn + 1
        gs.append(gn)
        m += 1
    gs = gs[::-1]
    print(m)
    for g in gs:
        if g == 1:
            print(g)
        else:
            print('{} '.format(g), end='')
        cnt = insertionSort(A, n, g, cnt)
    print(cnt)

n = int(input())
A = [int(input()) for _ in range(n)]
shellSort(A, n)
[print(a) for a in A]
