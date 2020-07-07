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

def shellSort(A, n):
    gi = 2
    m = 1
    G = []
    for i in range(100):
        m += 1
        G.append(gi - 1)
        gi = gi * 2
        if n < gi - 1:
            break
    list.sort(G, reverse=True)
    for i in range(0, m-1):
        insertionSort(A, n, G[i])
    return G
      
n = int(input())
A = []
for i in range(n):
    A.append(int(input()))
G = shellSort(A, n)
G = [str(g) for g in G]
print(len(G))
print(" ".join(G))
print(cnt)
for a in A:
    print(a)
