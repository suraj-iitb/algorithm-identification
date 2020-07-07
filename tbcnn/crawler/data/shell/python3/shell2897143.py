#coding:utf-8

n = int(input())
A = [int(input()) for i in range(n)]


def insertionSort(A,n,g):
    cnt = 0
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and v < A[j]:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v
    return cnt



def shellSort(A,n):
    cnt = 0
    p = 1
    G = [p]
    while 3 * p + 1 < n:
        p = 3 * p + 1
        G.append(p)
    
    G.sort(reverse=True)
    m = len(G)
    for i in range(m):
        a = insertionSort(A,n,G[i])
        cnt += a
    print(m)
    G = " ".join([str(num) for num in G])
    print(G)
    print(cnt)

shellSort(A,n)
for num in A:
    print(num)
