import sys

def insertionSort(A, n, g):
    for i in range(g, n):
        global cnt
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v

def shellSort(A, n):
    global m
    global G
    for i in range(0, m):
        insertionSort(A, n, G[i])


n = int(input())
A = []
for i in range(n):
    A.append(int(input()))

if n == 1:
    print(1)
    print(1)
    print(0)
    print(A[0])
    sys.exit()
t = n - 1
G = []
G.append(t)
while t != 1:
    t = t//2
    G.append(t)
m = len(G)

cnt = 0
shellSort(A, n)
print(m)
print(' '.join(map(str, G)))
print(cnt)
for i in range(n):
    print(A[i])

