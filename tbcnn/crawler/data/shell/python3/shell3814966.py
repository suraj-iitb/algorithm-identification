#シェルソート
N = int(input())
A = [int(input()) for _ in range(N)]
def insertionSort(A, N, g):
    cnt = 0
    for i in range(g, N):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            tmp = A[j]
            A[j] = A[j+g]
            A[j+g] = tmp
            j = j - g
            cnt += 1
    return cnt, A

def shellSort(N, A):
    
    m, g, G, cnt = 0, 1, [], 0
    while g <= N:
        m += 1
        G.append(g)
        g = 4 ** m + 3 * 2 ** (m - 1) + 1

    G.reverse()
    
    for i in range(m):
        c, A = insertionSort(A, N, G[i])
        cnt += c
    print(m)
    print(' '.join([str(g) for g in G]))
    print(cnt)
    for a in A:
        print(a)

shellSort(N, A)

