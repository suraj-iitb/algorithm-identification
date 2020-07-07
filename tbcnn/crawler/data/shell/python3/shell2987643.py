from sys import stdin

def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
  
def shellSort(A, n):
    global cnt
    cnt = 0
    g = 1
    G = [g]
    while 3 * g + 1 < n:
        g = 3 * g + 1
        G.append(g)
    m = len(G)
    G.reverse()
    print(m)
    print(' '.join(map(str, G)))
    for i in range(m):
        insertionSort(A, n, G[i])

n =  int(stdin.readline())
A = [int(stdin.readline()) for i in range(n)]

shellSort(A, n)
print(cnt)
for a in A:
    print(a)

