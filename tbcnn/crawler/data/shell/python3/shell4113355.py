def insertionSort(A, n, g, cnt):
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
    return [cnt, A]

def shellSort(A, n):
    cnt = 0
    a = 1
    G = []
    while a <= n:
        G.append(a)
        a = 3*a + 1
    m = len(G)
    G = G[::-1]
    for i in range(0, m):
        cnt, A = insertionSort(A, n, G[i], cnt)
    return [m, G, cnt, A]
        
if __name__ == "__main__":
    n = int(input())
    A = [int(input()) for _ in range(n)]
    m, G, cnt, A = shellSort(A, n)
    print(m)
    print(*G)
    print(cnt)
    for i in A:
        print(i)
