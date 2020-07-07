import math

def insertionSort(A,n,g):
    global cnt
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v

def shellSort(A,n):
    global cnt
    cnt = 0
    m = int(math.log(n))
    if m < 1:
        m = 1
    G = []
    for i in range(0,m):
        if i == 0:
            G.append(1)
        else:
            G.append(G[i-1]*3+1)
    G.sort(reverse=True)
    
    for i in range(0,m):
        insertionSort(A,n,G[i])
    print(m)
    for i in range(m):
        if i == m-1:
            print(G[i])
        else:
            print(G[i],end=" ")
    print(cnt)
    for i in range(n):
        print(A[i])

n = int(input())
A = []
for i in range(n):
    A.append(int(input()))
shellSort(A,n)
