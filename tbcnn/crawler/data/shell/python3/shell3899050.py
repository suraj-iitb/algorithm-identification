def insertionSort(A, N, g):
    global count
    for i in range(g, N):
        v = A[i]
        j = i - g
        while j >= 0 and  A[j] > v:
            A[j+g] = A[j]
            j = j - g
            count += 1
            A[j+g] = v
    return 0

def shellSort(A, N):
    global count
    count = 0
    G = []
    h = 1

    while h <= N:
        G.append(h)
        h = 3 * h + 1
    
    G.reverse()

    for _ in range(len(G)):
        insertionSort(A, N, G[_])
    return G

if __name__ == '__main__':
    N = int(input())
    A = [int(input()) for x in range(N)]

    m = shellSort(A, N)
    print(len(m))
    print(' '.join(map(str,m)))
    print(count)
    print(*A, sep='\n')
