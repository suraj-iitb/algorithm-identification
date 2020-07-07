def i_sort(A,n,g):
    global count
    
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j = j - g
            count = count + 1
        A[j + g] = v
        
def shellsort(A,n):
    global m
    global G
    
    h = 1
    while(True):
        if h > n:
            break
        G.append(h)
        h = 3 * h + 1
    
    m = len(G)
    G.reverse()
    
    for i in range(m):
        i_sort(A,n,G[i])
        
if __name__ == '__main__':
    N = int(input())
    R = [int(input()) for i in range(N)]
    
    count = 0
    G = []
    m = 0
    
    shellsort(R,N)
    
    print(m)
    print(" ".join(map(str,G)))
    print(count)
    for i in range(N):
        print(R[i])
