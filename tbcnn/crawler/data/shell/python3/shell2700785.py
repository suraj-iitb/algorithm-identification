def iSort(A, n, g):
    c = 0
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            c += 1
        A[j+g] = v
    return c

def shellSort(A, n):
    cnt = 0
    G = list()
    h = 1
    while True:
        if h > n:
            break
        G.append(h)
        h = 3*h + 1
    G.reverse()
    for num in G:
        cnt += iSort(A, n, num)
    return cnt, A, G

if __name__ == '__main__':
    n = int(input())
    hoge = list()
    for _ in range(n):
        hoge.append(int(input()))
    cnt, hoge, G = shellSort(hoge, n)
    print (len(G))
    print (' '.join([str(x) for x in G]))
    print (cnt)
    for e in hoge:
        print (e)
