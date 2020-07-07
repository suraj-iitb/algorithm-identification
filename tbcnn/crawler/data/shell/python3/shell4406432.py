import sys

def insertionSort(A, n, g):
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            global cnt
            cnt += 1
        A[j+g] = v

def shellSort(A, n):
    G = list()
    h = 1
    while h ==1 or h < n:
        G.append(h)
        h = h * 3 + 1
    G.reverse()
    m = len(G)
    for i in range(m):
        insertionSort(A, n, G[i])
    print(m)
    print(*G)
    global cnt
    print(cnt)
    for item in A:
        print(item)

cnt = 0
n = int(sys.stdin.readline())
A = [int(sys.stdin.readline()) for _ in range(n)]
shellSort(A, n)
