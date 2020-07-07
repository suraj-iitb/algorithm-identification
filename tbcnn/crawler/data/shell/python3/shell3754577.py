def insertionSort(A, n, g, cnt):
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
    return cnt

def shellSort(A, n):
    cnt = 0
    mem = len(A)
    G = []
    while mem != 0:
        G.append(mem)
        if mem == 1: mem = 0
        else :
            mem = int(mem / 2)
    m = len(G)
    print(str(m))
    print(' '.join(map(str, G)))
    for i in range(m):
        cnt = insertionSort(A, n, G[i], cnt)
    print(cnt)
    for j in A:
        print(str(j))
        
if __name__ == '__main__':
    N = int(input())
    M = []
    for i in range(N):
        M.append(int(input()))
    shellSort(M,N)
