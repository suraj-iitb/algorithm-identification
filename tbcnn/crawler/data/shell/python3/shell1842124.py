def shellSort(A):
    cnt = 0
    def insertionSort(A, g):
        nonlocal cnt
        for i in range(g,len(A)):
            v = A[i]
            j = i - g
            while j >= 0 and A[j] > v:
                A[j+g] = A[j]
                j = j - g
                cnt += 1
            A[j+g] = v
    i = 0 
    G = [1]
    if len(A) > 1:
        while G[i] < len(A):
            G.append(3*G[i]+1)
            i += 1
        G = G[-2::-1]
    print(len(G))
    print(*G)
    for i in range(len(G)):
        insertionSort(A, G[i])
    return cnt

if __name__=='__main__':
    n = int(input()) 
    A = [int(input()) for _ in range(n)]
    print(shellSort(A))
    [print(ai) for ai in A]
