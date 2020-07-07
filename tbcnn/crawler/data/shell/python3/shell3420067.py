def insertionSort(a, n, g, cnt):
    for i in range(g,n):
        v = a[i]
        j = i-g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j -= g
            cnt += 1
        a[j+g] = v
    return cnt


def shellSort(a, n):
    g = []
    h = 1
    while True:
        if h > n:
            break
        g.append(h)
        h = 3*h + 1
    cnt = 0
    m = len(g)
    for i in range(m-1,-1,-1):
        cnt = insertionSort(a, n, g[i], cnt)
    print(m)
    print(' '.join(list(map(str, g[::-1]))))
    print(cnt)
    for k in a:
        print(k)



n = int(input())
aa = [0]*n
for i in range(n):
    aa[i] = int(input())
shellSort(aa, n)

