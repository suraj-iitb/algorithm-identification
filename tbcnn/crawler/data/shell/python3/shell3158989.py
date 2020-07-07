import math
cnt = 0

def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v
    return A

def shellSort(A, n):
    i = len(A)
    G = [(3**j-1)//2 for j in range(int(math.log(2*i+1, 3)),0,-1)]
    m = len(G)
    for g in G:
        insertionSort(A, n, g)
    return m, G, A


n = int(input())
a = [int(input()) for _ in range(n)]
m, g, sa = shellSort(a[:], n)
print(m)
print(' '.join(map(str,g)))
print(cnt)
print('\n'.join(map(str,sa)))
