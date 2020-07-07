def insertionSort(A,n,g):
    cnt = 0
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt+=1
        A[j+g] = v
    return cnt

def shellSort(A,n):
    cnt = 0
    G = make_G(A)
    m = len(G)
    for i in range(m):
        cnt += insertionSort(A, n, G[i])
    
    return m,G,cnt,A

def make_G(A):
    length_A = len(A)
    i=1
    while 4**i+3*(2**(i-1)) < length_A:
        i+=1
    G = [0 for j in range(i)]
    for k in range(i):
        G[k] = 4**k+3*(2**(k-1))
    G[0] = 1
    G.reverse()
    return G


n = int(input())
A = [0 for i in range(n)]
for i in range(n):
    A[i] = int(input())

m,G,cnt,A = shellSort(A,n)
print(m)
print(*G)
print(cnt)
for i in range(len(A)):
    print(A[i])
