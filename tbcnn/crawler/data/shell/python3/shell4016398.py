# coding: utf-8
# Your code here!


def insertionSort(A, n, g, cnt):
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j = j - g
            cnt += 1
        A[j + g] = v
    return A, cnt
        
def shellSort(A, n):
    cnt = 0
    m = n // 3 + 1
    G = [1]
    for i in range(m-1):
        if G[0] * 3 + 1 < n:
            G.insert(0, G[0] * 3 + 1)
    m = len(G)
    print(m)
    if m > 1:
        for i in range(m-1):
            print(str(G[i]), end = " ")
    print(str(G[m-1]))
        
    for i in range(m):
        A, cnt = insertionSort(A, n, G[i], cnt)


    print(cnt)
    for i in range(n):
        print(A[i])
    
    
#A = [1, 6, 5, 4, 3, 2]
#n = len(A)

n = int(input())
A = []
#cnt = 0
for i in range(n):
    A.append(int(input()))

shellSort(A, n)






