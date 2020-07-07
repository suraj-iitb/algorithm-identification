def insertionSort(A, n, g, cnt):
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
        
    return cnt

def shellSort(A, n):
    cnt_s = 0
    k = 0
    G = []
    while k <= n:
        k = 3*k + 1
        if k <= n:
            G.append(k)
    G.reverse()
    m = len(G)
    for i in range(m):
        cnt_s = insertionSort(A, n, G[i], cnt_s)

    return A, m, G, cnt_s

n = int(input())
A = [0]*n

for i in range(n):
    A[i] = int(input())

A_out, m, G, cnt_out = shellSort(A, n)

G_str = list(map(str,G))
print(str(m))
print(" ".join(G_str))
print(str(cnt_out))
for i in range(n):
    print(str(A_out[i]))
