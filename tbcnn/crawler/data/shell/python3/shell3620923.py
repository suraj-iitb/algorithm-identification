def insertionSort(A,n,g):
    cnt = 0
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
            A[j+g] = v
    return cnt
    
def shellsort(A,n):
    cnt = 0
    h = 1
    G = []
    while h <= n:
        G.append(h)
        h = 3*h + 1
    G.reverse()
    m = len(G)
    print(m)

    print(" ".join(map(str,G)))
    for i in range(m):
        cnt += insertionSort(A,n,G[i])
    print(cnt)
    for i in A:
        print(i)
        
n = int(input())
A = []
for _ in range(n):
    A.append(int(input()))
shellsort(A,n)


