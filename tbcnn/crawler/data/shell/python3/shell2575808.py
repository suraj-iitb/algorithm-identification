def InsertionSort(A, n, g):
    c = 0
    for i in range(g, n):
        v, j = A[i], i - g
        while j>=0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            c += 1
        A[j+g] = v
    return c
def shellSort(n, A):
    cnt, G, gm = 0, [], 1
    while True:
        G = [gm] + G
        if gm*5+1 > n: break
        gm = 5*gm +1
    m = len(G)
    print(m)
    print(*G)
    for i in range(m):
        cnt += InsertionSort(A,n,G[i])
    return cnt


def ALDS1_2D():
    N = int(input())
    A = [int(input()) for n in range(N)]
    print(shellSort(N, A))
    for i in range(N):print(A[i])

if __name__ == '__main__':
    ALDS1_2D()
