def insertionSort(A, N, g):
    for i in range(g, N):
        global count
        
        v = A[i]
        j = i - g
        while(j >= 0 and A[j] > v):
            A[j+g] = A[j]
            j = j - g
            count += 1
        A[j+g] = v

def shellSort(A, N, m, G):
    for i in range(m):
        insertionSort(A, N, G[i])
    
if __name__ == '__main__':
    N = int(input())
    A = [int(input()) for _ in range(N)]
    
    G = [0]
    for i in range(100):
        G.append(G[-1]+ 3**i)
    G.sort()
    G.remove(0)
    
    m = 0
    for i, g in enumerate(G):
        if g < N:
            m = i + 1
    if m == 0:
        m = 1
    G = G[:m]
    
    G.sort(reverse=True)
    
    count = 0
    
    shellSort(A, N, m, G)
    
    print(m)
    print(*G[:m])
    print(count)
    for a in A:
        print(a)
