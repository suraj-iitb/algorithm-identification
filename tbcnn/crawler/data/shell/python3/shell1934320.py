def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j = j - g
            cnt += 1
        A[j + g] = v

def shellSort(A, n):
    global m, G
    for i in range(0, m): 
        insertionSort(A, n, G[i])

n = int(input())
A = []
for i in range(0, n):
    A.append(int(input()))

G = []
h = 1
for i in range(1, 999999):
    if h > n:
        break
    G.append(h)
    h = 3 * h + 1

G.reverse()

cnt = 0
m = len(G)
shellSort(A, n)
'''
m = 2
G = (4,1)
shellSort(A, n)
'''

print(m)
print(" ".join(map(str, G)))
print(cnt)
for i in range(0, n):
    print(A[i])
