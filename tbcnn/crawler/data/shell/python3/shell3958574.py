n = int(input())
A = [0]*n
cnt = 0

for i in range(n):
    A[i] = int(input())



def shellSort(A, n):
    G = []
    h = 1
    while h <= n:
        G.append(h)
        h = 3*h + 1
    G.reverse()

    m = len(G)
    print(m)
    print(' '.join([str(i) for i in G]))
    for i in range(m):
        insertionSort(A, n, G[i])

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
        
shellSort(A, n)
print(cnt)
for i in A:
    print(i)
